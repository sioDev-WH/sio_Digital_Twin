#include "frontmip.h"
#include "frontkey.h"
#include <stdio.h>
#include <math.h>

#define sign(x) x>0? 1:-1

void dynamics(double x[], double u[], double xdot[], double y[]){

  long i,j;
  long nx=2,nu=2,ny=2; 

  double A[] = {-0.09, -0.01, 1, 0};
  double B[] = { 0, -7, 0, -2};
  double C[] = { 0, 2, 1, -5};
  double D[] = {-3, 0, 1, 0};


  for(i=0;i<nx;i++){
    xdot[i] = 0.0;
    for(j=0;j<nx;j++)
      xdot[i] += A[i*nx+j]*x[j];
    for(j=0;j<nu;j++)
       xdot[i] += B[i*nu+j]*u[j];
  }
  for(i=0;i<ny;i++){
    y[i] = 0.0;
    for(j=0;j<nx;j++)
      y[i] += C[i*nx+j]*x[j];
    for(j=0;j<nu;j++)
       y[i] += D[i*nu+j]*u[j];
  }
}



INTARG _CC trimObj (HPROBLEM lp, INTARG numcols, INTARG numrows,
   LPREALARG objval, LPREALARG lhs, LPREALARG var, INTARG varone,
   INTARG vartwo)
{
   
   double x[2],u[2],xdot[2],y[2];
   double Tx[2],Tu[2];
   double g[4];
   long i;
   
   x[0] = var[0];
   x[1] = var[1];
   u[0] = var[2];
   u[1] = var[3];


   Tx[0] = 1.0;
   Tx[1] = 1.0;
   Tu[0] = 1.0;
   Tu[1] = 1.0;

   objval[0] = 0.0;

   g[0] = fabs(x[0]-Tx[0]);
   g[1] = fabs(x[1]-Tx[1]);
   g[2] = fabs(u[0]-Tu[0]);
   g[3] = fabs(u[1]-Tu[1]);

	
   for(i=0;i<4;i++){
	   // if(g[i]>objval[0]) objval[0] = g[i];
	   objval[0] += g[i];
   }

   dynamics(x,u,xdot,y);
	printf("Final states: xdot[0] = %g  xdot[1] = %g\n", xdot[0], xdot[1]);	
   lhs[0] = xdot[0]; /* constraint left hand side */
   lhs[1] = xdot[1]; /* constraint left hand side */
   return 0;
}

INTARG _CC jacobian1 (HPROBLEM lp, INTARG numcols, INTARG numrows,
   INTARG nzspace, LPREALARG objval, LPREALARG obj, LPINTARG matbeg,
   LPINTARG matcnt, HPINTARG matind, HPREALARG matval, LPREALARG var,
   LPBYTEARG objtype, LPBYTEARG matvaltype)
{
   
   double x[2],u[2];
   double Tx[2],Tu[2];
   double g[4];
   long i;
   
   x[0] = var[0];
   x[1] = var[1];
   u[0] = var[2];
   u[1] = var[3];


   Tx[0] = 1.0;
   Tx[1] = 1.0;
   Tu[0] = 1.0;
   Tu[1] = 1.0;

 

   g[0] = fabs(x[0]-Tx[0]);
   g[1] = fabs(x[1]-Tx[1]);
   g[2] = fabs(u[0]-Tu[0]);
   g[3] = fabs(u[1]-Tu[1]);

   objval[0]=0.0;	
   for(i=0;i<4;i++)
	   /*
	   if(g[i]>objval[0]){
		   objval[0] = g[i];
		   obj[i] = sign(var[i]);
	   }
	   else obj[i] = 0.0;
	   */
   {
	   objval[0] += g[i];
	   obj[i] = sign(var[i]);
   }
	

   /* Partial derivatives of xdot[0] */
   matval[0] = -0.09;
   matval[2] = -0.01;
   matval[4] = 0;
   matval[6] = -7.0;
   /* Partial derivatives of xdot[1] */
   matval[1] = 1;
   matval[3] = 0;
   matval[5] = 0;
   matval[7] = -2;
   return 0;
}


INTARG _CC showiter1 (HPROBLEM lpinfo, INTARG wherefrom)
{
   long itercount; double objval;
   getcallbackinfo (lpinfo, wherefrom, CBINFO_ITCOUNT, &itercount);
   getcallbackinfo (lpinfo, wherefrom, CBINFO_PRIMAL_OBJ, &objval);
   printf("Iteration %d:  Objective = %g\n", itercount, objval);
   return 0;
}

void linear(void)
{
   double obj[4];
   double rhs[2] = {0.0,0.0};
   char sense[3] = "EE";
   double matval[8];
   double lb[] = { -INFBOUND, -INFBOUND, -INFBOUND, -INFBOUND };
   double ub[] = { +INFBOUND, +INFBOUND, +INFBOUND, +INFBOUND};
   long i, stat; double objval;
   double x[4] = { 0.0, 0.0, 0.0, 0.0 };
   double piout[4], slack[4], dj[4];
   HPROBLEM lp = NULL;

   printf("\nExample NLP problem 1\n");
   setintparam (lp, PARAM_ARGCK, 1);

   lp = loadnlp (PROBNAME, 4, 2, 1, obj, rhs, sense,
      NULL, NULL, NULL, matval, x, lb, ub, NULL, 8,
      trimObj, jacobian1);
   if (!lp) return;
	
   setintparam (lp, PARAM_DERIV, 2);

   setlpcallbackfunc (lp, showiter1);
 
   optimize (lp);

   solution (lp, &stat, &objval, x, piout, slack, dj);
   printf("\nStatus = %d  Objective = %g\n", stat, objval);
   printf("Final states: x1 = %g  x2 = %g\nFinal control:u1 = %g  u2 = %g\n", x[0], x[1], x[2], x[3]);
   for (i = 0; i <= 1; i++)
      printf("slack[%ld] = %7g  piout[%ld] = %7g\n",
      i, slack[i], i, piout[i]);
   printf("\n");

   unloadprob (&lp);
}


/* 
   Example C program calling the nonlinear Solver DLL.
   Solves the problem:

   Minimize X^2 + Y^2
   Subject to:
      X + Y  = 1
      X * Y >= 0

   (Solution is X = Y = 0.5, Objective = 0.5)

   Here we define the function jacobian() as well as funceval(), to help
   speed up the evaluation of first partial derivatives at trial points.
   We re-use the functions funceval1() and showiter1() from Example 1.
*/



void main(){

	linear();
}