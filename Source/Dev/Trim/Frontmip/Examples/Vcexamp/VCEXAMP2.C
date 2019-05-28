/* **********************************************************************
   Frontline Systems Small-Scale Solver Dynamic Link Library Version 3.5
   Frontline Systems Inc., P.O. Box 4288, Incline Village, NV 89450 USA
   Tel (775) 831-0300 ** Fax (775) 831-0314 ** Email info@frontsys.com

   Example NLP and NSP problems in C/C++: Build as Win32 console app or
   Win16 QuickWin project containing files VCEXAMP2.C and FRONTMIP.LIB
   ********************************************************************** */

#include "frontmip.h"
#include "frontkey.h"
#include <stdio.h>
#include <math.h>


/* Example routine to check the capabilities and problem size limits of
   the Solver DLL we are using.  A return value of 0 for the number of
   variables or constraints means that the corresponding Solver engine
   is not included. */

void getlimits(void)
{
   long cols, rows, ints;

   getproblimits (NULL, PROB_LP, &cols, &rows, &ints);
   printf("LP limits: %ld variables, %ld constraints, %ld integers\n",
      cols, rows, ints);

   getproblimits (NULL, PROB_QP, &cols, &rows, &ints);
   printf("QP limits: %ld variables, %ld constraints, %ld integers\n",
      cols, rows, ints);

   getproblimits (NULL, PROB_NLP, &cols, &rows, &ints);
   printf("NLP limits: %ld variables, %ld constraints, %ld integers\n",
      cols, rows, ints);

   getproblimits (NULL, PROB_NSP, &cols, &rows, &ints);
   printf("NSP limits: %ld variables, %ld constraints, %ld integers\n",
      cols, rows, ints);
}


/* 
   Example C program calling the nonlinear Solver DLL.
   Solves the problem:

   Minimize X^2 + Y^2
   Subject to:
      X + Y  = 1
      X * Y >= 0

   (Solution is X = Y = 0.5, Objective = 0.5)
*/


/* Define a "callback" function which computes the objective and constraint
   left hand sides, for any supplied values of the decision variables. */

INTARG _CC funceval1 (HPROBLEM lp, INTARG numcols, INTARG numrows,
   LPREALARG objval, LPREALARG lhs, LPREALARG var, INTARG varone,
   INTARG vartwo)
{
   objval[0] = var[0] * var[0]  + var[1] * var[1] ; /* objective */
   lhs[0] = var[0] + var[1]; /* constraint left hand side */
   lhs[1] = var[0] * var[1]; /* constraint left hand side */
   return 0;
}


/* Define a "callback" function which displays progress information 
   when called on major iterations by the nonlinear Solver engine. */

INTARG _CC showiter1 (HPROBLEM lpinfo, INTARG wherefrom)
{
   long itercount; double objval;
   getcallbackinfo (lpinfo, wherefrom, CBINFO_ITCOUNT, &itercount);
   getcallbackinfo (lpinfo, wherefrom, CBINFO_PRIMAL_OBJ, &objval);
   printf("Iteration %d:  Objective = %g\n", itercount, objval);
   return 0;
}


/* Now set up the NLP problem (including the "sense" and right hand sides
   of constraints), call the nonlinear Solver, and display the solution. */

void example1(void)
{
   double obj[2];
   double rhs[2] = {  1.0, 0.0 };
   char sense[2] = "EG"; 
   double matval[4];
   double lb[] = { -INFBOUND, -INFBOUND };
   double ub[] = { +INFBOUND, +INFBOUND };
   long i, stat; double objval;
   double x[2] = { 0.0, 0.0 };
   double piout[2], slack[2], dj[2];
   HPROBLEM lp = NULL;

   printf("\nExample NLP problem 1\n");
   setintparam (lp, PARAM_ARGCK, 1);

   lp = loadnlp (PROBNAME, 2, 2, 1, obj, rhs, sense,
      NULL, NULL, NULL, matval, x, lb, ub, NULL, 4,
      funceval1, NULL);
   if (!lp) return;
   setlpcallbackfunc (lp, showiter1);
 
   optimize (lp);

   solution (lp, &stat, &objval, x, piout, slack, dj);
   printf("\nStatus = %d  Objective = %g\n", stat, objval);
   printf("Final values: x1 = %g  x2 = %g\n", x[0], x[1]);
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


INTARG _CC jacobian1 (HPROBLEM lp, INTARG numcols, INTARG numrows,
   INTARG nzspace, LPREALARG objval, LPREALARG obj, LPINTARG matbeg,
   LPINTARG matcnt, HPINTARG matind, HPREALARG matval, LPREALARG var,
   LPBYTEARG objtype, LPBYTEARG matvaltype)
{
   printf("jacobian evaluated at: x1 = %g   x2 = %g\n", var[0], var[1]);
   /* Value of the objective function */
   objval[0] = var[0] * var[0] + var[1] * var[1];
   /* Partial derivatives of the objective */
   obj[0] = 2.0 * var[0];
   obj[1] = 2.0 * var[1];
   /* Partial derivatives of X + Y (constant) */
   matval[0] = 1.0;
   matval[2] = 1.0;
   /* Partial derivatives of X * Y (variable) */
   matval[1] = var[1];
   matval[3] = var[0];
   return 0;
}


void example2(void)
{
   double obj[2];
   double rhs[2] = {  1.0, 0.0 };
   char sense[2] = "EG";
   double matval[4];
   double lb[] = { -INFBOUND, -INFBOUND };
   double ub[] = { +INFBOUND, +INFBOUND };
   long i, stat; double objval;
   double x[2] = { 0.25, 0.25 };
   double piout[2], slack[2], dj[2];
   HPROBLEM lp = NULL;

   printf("\nExample NLP problem 2\n");
   setintparam (lp, PARAM_ARGCK, 1);

   lp = loadnlp (PROBNAME, 2, 2, 1, obj, rhs, sense,
      NULL, NULL, NULL, matval, x, lb, ub, NULL, 4,
	  funceval1, jacobian1);
   if (!lp) return;

   /* Ask the Solver DLL to call our jacobian() routine, and *check*
      the partial derivatives we supply against its own "rise over run"
      derivative calculations */
   setintparam (lp, PARAM_DERIV, 3);

   optimize (lp);

   solution (lp, &stat, &objval, x, piout, slack, dj);
   printf("\nStatus = %d  Objective = %g\n", stat, objval);
   printf("Final values: x1 = %g  x2 = %g\n", x[0], x[1]);
   for (i = 0; i <= 1; i++)
      printf("slack[%ld] = %7g  piout[%ld] = %7g\n",
      i, slack[i], i, piout[i]);
   printf("\n");

   setlpcallbackfunc (lp, NULL);
   setintparam (lp, PARAM_DERIV, 0);
   unloadprob (&lp);
}


/* 
   Example C program calling the nonlinear Solver DLL.
   Attempts to solve the problem:

   Minimize X^2 + Y^2
   Subject to:
      X * Y  = 1
      X * Y  = 0

   This problem is infeasible, because the two constraints conflict.
   We will call findiis() and getiis() to help isolate the source 
   of the infeasibility.
*/


INTARG _CC funceval3 (HPROBLEM lp, INTARG numcols, INTARG numrows,
   LPREALARG objval, LPREALARG lhs, LPREALARG var, INTARG varone,
   INTARG vartwo)
{
   objval[0] = var[0] * var[0] + var[1] * var[1]; /* objective */
   lhs[0] = var[0] * var[1]; /* constraint left hand side */
   lhs[1] = var[0] * var[1]; /* constraint left hand side */
   return 0;
}


void example3(void)
{
   double obj[2];
   double rhs[2] = {  1.0, 0.0 };
   char sense[2] = "EE";
   double matval[4];
   double lb[] = { -INFBOUND, -INFBOUND };
   double ub[] = { +INFBOUND, +INFBOUND };
   long i, stat, iisrows, iiscols; double objval;
   long rowind[2], rowbdstat[2], colind[2], colbdstat[2];
   double x[2] = { 0.25, 0.25 };
   double piout[2], slack[2], dj[2];
   HPROBLEM lp = NULL;

   printf("\nExample NLP problem 3\n");
   setintparam (lp, PARAM_ARGCK, 1);

   lp = loadnlp (PROBNAME, 2, 2, 1, obj, rhs, sense,
      NULL, NULL, NULL, matval, x, lb, ub, NULL, 4,
      funceval3, NULL);
   if (!lp) return;

   optimize (lp);

   solution (lp, &stat, &objval, x, piout, slack, dj);
   printf("Status = %ld (%s)  Objective = %g\n", stat,
      stat == PSTAT_INFEASIBLE ? "INFEASIBLE" : "FEASIBLE", objval);
   printf("Final values: x1 = %g  x2 = %g\n", x[0], x[1]);

   if (stat == PSTAT_INFEASIBLE)
   {
      findiis (lp, &iisrows, &iiscols);
      printf("\nfindiis: iisrows = %ld  iiscols = %ld\n",
         iisrows, iiscols);
      getiis (lp, &stat, rowind, rowbdstat, &iisrows,
         colind, colbdstat, &iiscols);
      for (i = 0; i < iisrows; i++)
         printf("rowind[%ld] = %ld  rowbdstat[%ld] = %ld\n",
            i, rowind[i], i, rowbdstat[i]);
      for (i = 0; i < iiscols; i++)
         printf("colind[%ld] = %ld  colbdstat[%ld] = %ld\n",
            i, colind[i], i, colbdstat[i]);
   }

   unloadprob (&lp);
}


/* 
   Example C program calling the nonlinear Solver DLL for a series of
   problems which may be linear or nonlinear.  This situation might 
   arise if you are calling some external program, or using your own
   interpreter, to evaluate the problem functions.  We will define and
   solve two example problems:

   Nonlinear problem:

   Minimize X^2 + Y^2
   Subject to:
      X + Y  = 1
      X * Y >= 0

   (Solution is X = Y = 0.5, Objective = 0.5)

   Alternate linear problem:

   Minimize 2 * X + Y
   Subject to:
      X + Y  = 1
      3 * X - Y >= 0

   (Solution is X = 0.25, Y = 0.75, Objective = 1.25)

   In this example, we call testnltype() to determine whether
   the problem is linear or nonlinear.  If it is linear, we
   solve it first with the nonlinear Solver engine, then solve
   it again with the linear (Simplex) Solver engine.
*/

typedef enum { Nonlin, Linear } Problem;
Problem Ex1 = Nonlin;

/* 
   We define one funceval() routine, which can compute the
   objective and constraint values for both of the example
   problems.  The values returned by this funceval() depend
   on the setting of the global variable Ex1.
*/

INTARG _CC funceval4 (HPROBLEM lp, INTARG numcols, INTARG numrows,
   LPREALARG objval, LPREALARG lhs, LPREALARG var, INTARG varone,
   INTARG vartwo)
{
   switch (Ex1)
   {
   case Nonlin:
      objval[0] = var[0] * var[0]  + var[1] * var[1] ; /* objective */
      lhs[0] = var[0] + var[1]; /* constraint left hand side */
      lhs[1] = var[0] * var[1]; /* constraint left hand side */
      break;
   case Linear:
      objval[0] = 2.0 * var[0] + var[1] ; /* objective */
      lhs[0] = var[0] + var[1]; /* constraint left hand side */
      lhs[1] = 3.0 * var[0] - var[1]; /* constraint left hand side */
      break;
   }
   return 0;
}


void example4(void)
{
   double obj[2];
   double rhs[2] = {  1.0, 0.0 };
   char sense[2] = "EG";
   double matval[4];
   double lb[] = { -10.0, -10.0 };
   double ub[] = { +10.0, +10.0 };
   long stat, nlstat; double objval;
   double x[2] = { 0.0, 0.0 };
   double piout[2], slack[2], dj[2];
   HPROBLEM lp = NULL;

   printf("\nExample NLP/LP problem 4\n");
   setintparam (lp, PARAM_ARGCK, 1);

   /* Set up the problem for solution by the NLP Solver */
   lp = loadnlp (PROBNAME, 2, 2, 1, obj, rhs, sense,
      NULL, NULL, NULL, matval, x, lb, ub, NULL, 4,
      funceval4, NULL);
   if (!lp) return;

   /* Test the problem to determine linearity / nonlinearity */
   testnltype(lp, 1, NULL, &nlstat, NULL, NULL);
   printf("\ntestnltype: %s\n", nlstat ? "NONLINEAR" : "LINEAR");
 
   /* Solve the problem (using the NLP Solver) */
   optimize (lp);

   solution (lp, &stat, &objval, x, piout, slack, dj);
   printf("Status = %ld  Objective = %g\n", stat, objval);
   printf("Final values: x1 = %g  x2 = %g\n", x[0], x[1]);

   unloadprob (&lp);
   if (nlstat) return;

   /* The problem was linear.  Set it up to be solved by the
      linear Simplex Solver -- it should find the same solution. */
   printf("\nSolve same problem with loadlp\n");
   lp = loadlp (PROBNAME, 2, 2, 1, obj, rhs, sense,
      NULL, NULL, NULL, matval, lb, ub, NULL, 2, 2, 4);
 
   /* Solve the problem (using the LP Solver) */
   optimize (lp);

   solution (lp, &stat, &objval, x, piout, slack, dj);
   printf("Status = %ld  Objective = %g\n", stat, objval);
   printf("Final values: x1 = %g  x2 = %g\n\n", x[0], x[1]);

   unloadprob (&lp);
}


/* 
   Example C program calling the Evolutionary Solver DLL.
   Solves the problem:

   Minimize the Branin function:
   term1 = X/PI * (5.1 * X/PI/4 - 5)
   term2 = (Y - term1 - 6)^2
   term3 = 10 * (1 - 1/PI/8) * cos X + 10
   objective = term2 + term3
   -5 <= X, Y <= 10

   (3 local optima; 1 global optimum = approx 0.3978)
*/

#define PI 3.141593


INTARG _CC funceval5 (HPROBLEM lp, INTARG numcols, INTARG numrows, LPREALARG objval,
   LPREALARG lhs, LPREALARG var, INTARG varone, INTARG vartwo)
{
   double term1, term2, term3;
   term1 = var[0] / PI * (5.1 * var[0] / PI / 4.0 - 5.0);
   term2 = (var[1] - term1 - 6) * (var[1] - term1 - 6);
   term3 = 10.0 * (1.0 - 1.0 / PI / 8.0) * cos(var[0]) + 10.0;
   objval[0] = term2 + term3;
   return 0;
}


INTARG _CC showiter5 (HPROBLEM lpinfo, INTARG wherefrom)
{
   int itercount; double objval;
   getcallbackinfo (lpinfo, wherefrom, CBINFO_ITCOUNT, &itercount);
   getcallbackinfo (lpinfo, wherefrom, CBINFO_PRIMAL_OBJ, &objval);
   printf("Iteration %ld:  Objective = %g\n", itercount, objval);
   return 0;
}


int example5()
{
   double obj[2];
   double lb[2] = { -5.0, -5.0 };
   double ub[2] = { 10.0, 10.0 };
   int stat; double objval;
   double x[2] = { 1.0, 1.0 };
   double mid[2], disp[2], lower[2], upper[2];
   HPROBLEM lp = NULL;

   printf("\nExample NSP problem 5: Branin function\n");
   setintparam (lp, PARAM_ARGCK, 1);

   lp = loadnlp (PROBNAME, 2, 0, 1, obj, NULL, NULL,
      NULL, NULL, NULL, NULL, x, lb, ub, NULL, 0,
      funceval5, NULL);
   if (!lp) return 1;
   setintparam (lp, PARAM_NOIMP, 1); /* 1 second */
   setlpcallbackfunc (lp, showiter5);

   printf("Calling loadnltype\n");
   loadnltype (lp, NULL, NULL);

   optimize (lp);

   solution (lp, &stat, &objval, x, NULL, NULL, NULL);
   printf("\nStatus = %ld  Objective = %g\n", stat, objval);
   printf("Final values: x1 = %g  x2 = %g\n", x[0], x[1]);

   varstat (lp, 0, 1, mid, disp, lower, upper);
   printf("\nx1: mid = %g  disp = %g  lower = %g  upper = %g\n",
      mid[0], disp[0], lower[0], upper[0]);
   printf("x2: mid = %g  disp = %g  lower = %g  upper = %g\n",
      mid[1], disp[1], lower[1], upper[1]);

   unloadprob (&lp);
   return 0;
}


/* 
   Example C program calling the Evolutionary Solver DLL.
   Solves the problem:

   Maximize (if X > 10 then Y + Z else Y - Z)
   0 <= X, Y, Z <= 20

   (Solution is X > 10, Y = Z = 20, objective = 40)
*/

INTARG _CC funceval6 (HPROBLEM lp, INTARG numcols, INTARG numrows,
   LPREALARG objval, LPREALARG lhs, LPREALARG var, INTARG varone,
   INTARG vartwo)
{
   objval[0] = (var[0] > 10.0 ? var[1] + var[2] : var[1] - var[2]);
      /* objective */
   return 0;
}


int example6()
{
   double obj[3];
   double lb[3] = { 0.0, 0.0, 0.0 };
   double ub[3] = { 20.0, 20.0, 20.0 };
   int stat; double objval;
   double x[3] = { 5.0, 5.0, 5.0 };
   HPROBLEM lp = NULL;

   printf("\nExample NSP problem 6: IF function\n");
   setintparam (lp, PARAM_ARGCK, 1);

   lp = loadnlp (PROBNAME, 3, 0, -1, obj, NULL, NULL,
      NULL, NULL, NULL, NULL, x, lb, ub, NULL, 0,
      funceval6, NULL);
   if (!lp) return 1;
   setintparam (lp, PARAM_NOIMP, 1); /* 1 second */

   printf("Calling loadnltype\n");
   loadnltype (lp, NULL, NULL);

   optimize (lp);

   solution (lp, &stat, &objval, x, NULL, NULL, NULL);
   printf("\nStatus = %ld  Objective = %g\n", stat, objval);
   printf("Final values: x1 = %g  x2 = %g  x3 = %g\n", x[0], x[1], x[2]);

   unloadprob (&lp);
   return 0;
}


int main()
{
   char buf[80];
   printf("NONLINEAR TEST CASES FOR FRONTMIP.DLL\n\n");
   getlimits(); gets(buf);
   example1(); gets(buf);
   example2(); gets(buf);
   example3(); gets(buf);
   Ex1 = Nonlin;
   example4(); gets(buf);
   Ex1 = Linear;
   example4(); gets(buf);
   example5(); gets(buf);
   example6();
   return 0;
}

