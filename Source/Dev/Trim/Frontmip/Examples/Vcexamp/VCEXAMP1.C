/* **********************************************************************
   Frontline Systems Small-Scale Solver Dynamic Link Library Version 3.5
   Frontline Systems Inc., P.O. Box 4288, Incline Village, NV 89450 USA
   Tel (775) 831-0300 ** Fax (775) 831-0314 ** Email info@frontsys.com

   Example LP, MIP and QP problems in C/C++: Build as Win32 console app
   or Win16 QuickWin project containing files VCEXAMP1.C and FRONTMIP.LIB
   ********************************************************************** */

#include "frontmip.h"
#include "frontkey.h"
#include <stdio.h>


/*
   Example 1: Solves the LP model:
   Maximize   2 x1 +  3 x2
   Subj to    9 x1 +  6 x2 <= 54
              6 x1 +  7 x2 <= 42
              5 x1 + 10 x2 <= 50
   x1, x2 non-negative
   LP solution: x1 = 2.8, x2 = 3.6
   Objective = 16.4

   This example shows the simple form of passing arguments to loadlp():
   A dense (full-size N by M) matrix is passed as the matval argument
   and NULL pointers are passed as the matbeg, matcnt & matind arguments.

   This example also shows how to obtain LP sensitivity analysis info
   by calling the objsa() and rhssa() functions.  These calls are valid
   only for LP problems.  For QP problems, only dual values (the piout
   and dj arguments of solution()) are available; for MIP problems, no
   sensitivity analysis info is available (none would be meaningful).

   This example uses a callback function to display the LP iterations.
*/

/* The following function is called on each LP iteration in example1 */

long _CC lpcallback (HPROBLEM lpinfo, long wherefrom)
{
   long iters; double obj;
   getcallbackinfo (lpinfo, wherefrom, CBINFO_ITCOUNT, (void*)&iters);
   getcallbackinfo (lpinfo, wherefrom, CBINFO_PRIMAL_OBJ, (void*)&obj);
   printf("Iteration %ld:  Obj = %g\n", iters, obj);
   return PSTAT_CONTINUE;
}

void example1(void)
{
   double obj[] = { 2.0, 3.0 };
   double rhs[] = { 54.0, 42.0, 50.0 };
   char sense[] = "LLL";  /* L's for <=, E's for =, G's for >= */
   double matval[] = { 9.0, 6.0, 5.0, 6.0, 7.0, 10.0 };
   double lb[] = { 0.0, 0.0 };
   double ub[] = { INFBOUND, INFBOUND };
   long stat, i;
   double objval;
   double x[2], piout[3], slack[3], dj[2];
   double varlow[2], varupp[2], conlow[3], conupp[3];
   HPROBLEM lp = NULL;
   printf("\nExample LP problem\n");

   /* set up the LP problem */
   lp = loadlp (PROBNAME, 2, 3, -1, obj, rhs, sense,
      NULL, NULL, NULL, matval, lb, ub, NULL, 2, 3, 6);
   if (!lp) return;

#ifdef WIN32
   setlpcallbackfunc (lp, lpcallback); /* set up the callback */
#endif

   /* solve the problem */
   optimize (lp);

   /* obtain the solution: display objective and variables */
   solution (lp, &stat, &objval, x, piout, slack, dj);
   printf("LPstatus = %ld  Objective = %g\n", stat, objval);

   /* display constraint slacks and dual values */
   printf("x1 = %g  x2 = %g\n\n", x[0], x[1]);
   for (i = 0; i <= 2; i++)
      printf("slack[%ld] = %7g  piout[%ld] = %7g\n",
      i, slack[i], i, piout[i]);
   printf("\n");

   /* obtain and display sensitivity analysis information */
   objsa (lp, 0, 1, varlow, varupp);
   for (i = 0; i <= 1; i++)
      printf("Obj coefficient %3.0f  Lower %7g  Upper %7g\n",
         obj[i], varlow[i], varupp[i]);
   rhssa (lp, 0, 2, conlow, conupp);
   for (i = 0; i <= 2; i++)
      printf("Constraint RHS  %3.0f  Lower %7g  Upper %7g\n",
         rhs[i], conlow[i], conupp[i]);
   printf("\n");

#ifdef WIN32
   setlpcallbackfunc (lp, NULL); /* remove the callback function */
#endif

   /* important - call unloadprob() to release memory */
   unloadprob (&lp);
}


/*
   Example 2: Solves the MIP model:
   Maximize   2 x1 +  3 x2
   Subj to    9 x1 +  6 x2 <= 54
              6 x1 +  7 x2 <= 42
              5 x1 + 10 x2 <= 50
   x1, x2 non-negative, integer
   MIP solution: x1 = 2, x2 = 4
   Objective = 16.0

   This example illustrates the full set of arguments, used to pass a
   potentially sparse matrix to loadlp.  For each variable (column) i,
   matbeg[i] and matcnt[i] are the beginning index and count of non-
   zero coefficients in the matind and matval arrays.  For each such
   coefficient, matind[k] is the constraint (row) index and matval[i]
   is the coefficient value.  See the documentation for more details.

   In this example, we also use two debugging features of the Solver
   DLL:  (1) We call setintparam() to enable the display of error
   MessageBoxes by the DLL routines if they detect an invalid value
   in one of the arguments we pass (since there are no errors, none
   will appear).  (2) We call lpwrite() to write out a file which
   summarizes the LP/MIP problem in algebraic form.  This can help
   us verify that the arguments we pass have defined the right problem.
*/

void example2(void)
{
   double obj[] = { 2.0, 3.0 };
   double rhs[] = { 54.0, 42.0, 50.0 };
   char sense[] = "LLL";
   long matbeg[] = { 0, 3 };
   long matcnt[] = { 3, 3 };
   long matind[] =   {   0,   1,   2,   0,   1,    2 };
   double matval[] = { 9.0, 6.0, 5.0, 6.0, 7.0, 10.0 };
   double lb[] = { 0.0, 0.0 };
   double ub[] = { INFBOUND, INFBOUND };
   char ctype[] = "II";
   long stat;
   double objval;
   double x[2];
   HPROBLEM lp = NULL;

   printf("\nExample MIP problem\n");

   /* enable display of error MessageBoxes on argument
      errors (since the arguments are correct, none will
      appear).  Note - on argument errors, loadlp returns
      a NULL pointer and all other routines return a non-
      zero value; you can and should check for this!  But
      the MessageBoxes can help you identify errors early. */
   setintparam (lp, PARAM_ARGCK, 1);

   /* set up the LP portion of the problem */
   lp = loadlp (PROBNAME, 2, 3, -1, obj, rhs, sense,
      matbeg, matcnt, matind, matval, lb, ub, NULL, 2, 3, 6);
   if (!lp) return;

   /* now define integer variables:  for each variable i,
      ctype[i] is 'C' for continuous, 'I' for general
      integer and 'B' for a binary integer variable */
   loadctype (lp, ctype);

   /* lpwrite() can be called anytime after the problem
      is defined, and before unloadprob() is called.  It
      will write out the following text in file vcexamp1:
      Maximize LP/MIP
      obj: 2.0 x1 + 3.0 x2
      Subject To
        c1:  9.0 x1 + 6.0 x2 <= 54.0
        c2:  6.0 x1 + 7.0 x2 <= 42.0
        c3:  5.0 x1 + 10.0 x2 <= 50.0
      Bounds
        0.0 <= x1 <= +infinity
        0.0 <= x2 <= +infinity
      Integers
        x1
        x2
      End
   */
   lpwrite( lp, "vcexamp1");

   /* solve the problem; obtain and display the solution */
   mipoptimize (lp);
   solution (lp, &stat, &objval, x, NULL, NULL, NULL);
   printf("LPstatus = %ld  Objective = %g\n", stat, objval);
   printf("x1 = %g  x2 = %g\n", x[0], x[1]);

   /* don't forget to free memory */
   unloadprob (&lp);
}


/*
   Example 3: Attempt to solve the LP model:
   Maximize   2 x1 +  3 x2
   Subj to    9 x1 +  6 x2 <= 54
              6 x1 +  7 x2 <= 42
              5 x1 + 10 x2 <= -50
   x1, x2 non-negative
   Infeasible (due to non-negative variables and negative RHS)

   When solution() returns stat = PSTAT_INFEASIBLE, ask Solver DLL
   to find an Irreducibly Infeasible Subset (IIS) of the constraints:
   Row 2 (with the negative RHS) and lower bounds on both variables

   The constraint matrix is passed in simple (dense) form in matval[].
*/

void example3(void)
{
   double obj[] = { 2.0, 3.0 };
   double rhs[] = { 54.0, 42.0, -50.0 };
   char sense[] = "LLL";
   double matval[] = { 9.0, 6.0, 5.0, 6.0, 7.0, 10.0 };
   double lb[] = { 0.0, 0.0 };
   double ub[] = { INFBOUND, INFBOUND };
   long stat, i, iisrows, iiscols;
   long rowind[3], rowbdstat[3], colind[2], colbdstat[2];
   double objval;
   double x[2];
   HPROBLEM lp = NULL;

   printf("\nExample IIS diagnosis of infeasible problem\n");
   setintparam (lp, PARAM_ARGCK, 1);

   /* set up the LP problem */
   lp = loadlp (PROBNAME, 2, 3, -1, obj, rhs, sense,
      NULL, NULL, NULL, matval, lb, ub, NULL, 2, 3, 6);
   if (!lp) return;

   /* attempt solve the problem */
   optimize (lp);

   /* check the status of the solution */
   solution (lp, &stat, &objval, x, NULL, NULL, NULL);
   printf("LPstatus = %ld  Objective = %g\n", stat, objval);

   /* if infeasible, find and display an Irreducibly 
      Infeasible Subset (IIS) of the constraints */
   if (stat == PSTAT_INFEASIBLE)
   {
      findiis (lp, &iisrows, &iiscols);
      printf("\nfindiis: iisrows = %ld  iiscols = %ld\n", iisrows, iiscols);
      getiis (lp, &stat, rowind, rowbdstat, &iisrows, colind, colbdstat, &iiscols);
      for (i = 0; i < iisrows; i++)
         printf("rowind[%ld] = %ld  rowbdstat[%ld] = %ld\n", i, rowind[i], i, rowbdstat[i]);
      for (i = 0; i < iiscols; i++)
         printf("colind[%ld] = %ld  colbdstat[%ld] = %ld\n", i, colind[i], i, colbdstat[i]);
      iiswrite (lp, "iisexamp.txt");
   }
   printf("\n");

   /* don't forget to free memory */
   unloadprob (&lp);
}


/*
   Example 4: Use the QP solver to perform
   Markowitz-style portfolio optimization.
   Variables are the percentages to be allocated
   to each investment or asset class:
      0 <= x1, x2, x3, x4 x5 <= 1
   Minimize portfolio variance: [xi] Q [xi]
   Subj to allocations: Sum (xi) = 1
      and portfolio return: Sum (Ri xi) >= 0.085 

   The efficient portfolio is the QP solution (approx):
      x1 = 0.462  x2 = 0  x3 = 0.313  x4 = 0  x5 = 0.225
   The objective = approx. 0.00014 (minimum variance)

   Both the constraint matrix and the Q matrix are passed
   using the full set of arguments for sparse matrices.
*/

void example4(void)
{
   double obj[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
   double rhs[] = { 1.0, 0.085 };
   char sense[] = "EG";
   long matbeg[] = { 0, 2, 4, 6, 8 };
   long matcnt[] = { 2, 2, 2, 2, 2 };            
   long matind[] =   {   0,     1,   0,     1,   0,     1,   0,     1,   0,     1 };
   double matval[] = { 1.0, 0.086, 1.0, 0.071, 1.0, 0.095, 1.0, 0.107, 1.0, 0.069 };
   double lb[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
   double ub[] = { 1.0, 1.0, 1.0, 1.0, 1.0 };
   long qmatbeg[] = {  0,  5, 10, 15, 20 };
   long qmatcnt[] = {  5,  5,  5,  5,  5 };
   long qmatind[] = { 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4,
                      0, 1, 2, 3, 4, 0, 1, 2, 3, 4 };
   /* The Q matrix specifies the covariance between each pair of assets */
   double qmatval[] = { 0.000204,  0.000424,  0.000170,  0.000448, -0.000014,
                        0.000424,  0.012329,  0.001785,  0.001633, -0.000539,
                        0.000170,  0.001785,  0.000365,  0.000425, -0.000075,
                        0.000448,  0.001633,  0.000425,  0.005141,  0.000237,
                       -0.000014, -0.000539, -0.000075,  0.000237,  0.000509 };
   long stat;
   double objval;
   double x[5];
   HPROBLEM lp = NULL;

   printf("\nExample QP problem (Portfolio Optimization)\n");

   /* set up the LP portion of the problem.  The LP portion
      of the objective is all 0's here; it could be elaborated
      to include transaction costs or other factors. */
   lp = loadlp (PROBNAME, 5, 2, 1, obj, rhs, sense,
      matbeg, matcnt, matind, matval, lb, ub, NULL, 5, 2, 7);
   if (!lp) return;

   /* now set up the Q matrix to define the quadratic objective
      (test whether this DLL supports loadquad(), if not return) */
   if (loadquad (lp, qmatbeg, qmatcnt, qmatind, qmatval, 25, x))
      return;

   /* solve the problem; obtain and display the solution */
   optimize (lp);
   solution (lp, &stat, &objval, x, NULL, NULL, NULL);
   printf("LPstatus = %ld  Objective = %7.5f\n", stat, objval);
   printf("x1 = %5.3f x2 = %5.3f x3 = %5.3f x4 = %5.3f x5 = %5.3f\n\n",
      x[0], x[1], x[2], x[3], x[4]);

   /* once more: don't forget to free memory */
   unloadprob (&lp);
}


/* Example 5: Use the lpread() function to read a
   problem definition from a disk file and solve it.
   We read the file written by example2():

      Maximize LP/MIP
      obj: 2.0 x1 + 3.0 x2
      Subject To
        c1:  9.0 x1 + 6.0 x2 <= 54.0
        c2:  6.0 x1 + 7.0 x2 <= 42.0
        c3:  5.0 x1 + 10.0 x2 <= 50.0
      Bounds
        0.0 <= x1 <= +infinity
        0.0 <= x2 <= +infinity
      Integers
        x1
        x2
      End

   As in Example 2, the MIP solution is:
   x1 = 2, x2 = 4
   Objective = 16.0

*/

void example5(void)
{
   double obj[2];
   double rhs[3];
   char sense[3] = "EEE";
   long matbeg[2];
   long matcnt[2];
   long matind[6];
   double matval[6];
   double lb[2];
   double ub[2];
   char ctype[2] = "CC";
   long stat, nzspace, i;
   double objval;
   double x[2];
   long objsen, numcols, numrows, numints;
   HPROBLEM lp = NULL;

   setintparam (lp, PARAM_ARGCK, 1);

   /* First, we assume that the dimensions of the problem 
      are known.  We call loadlp(), passing array arguments
      of the proper dimension.  Since the sense[] and ctype[]
      arrays are checked for validity, we initialize them. */

   printf("\nExample: Read in MIP problem of known size\n");

   lp = loadlp (PROBNAME, 2, 3, -1, obj, rhs, sense,
      NULL, NULL, NULL, matval, lb, ub, NULL, 2, 3, 6);
   if (!lp) return;
   loadctype( lp, ctype);

   /* call lpread() to read in the actual array values */

   lpread( lp, "vcexamp1", NULL, NULL, NULL, NULL, NULL, NULL);

   /* call mipoptimize() and display the solution */

   mipoptimize (lp);
   solution (lp, &stat, &objval, x, NULL, NULL, NULL);
   printf("LPstatus = %ld  Objective = %g\n", stat, objval);
   printf("x1 = %g  x2 = %g\n", x[0], x[1]);
   unloadprob (&lp);

   /* Next, we assume that the dimensions of the problem are
      not known in advance.  We can call lpread() with a NULL
      first argument to read the file and obtain the actual
      problem dimensions.  Then, we would allocate arrays of
      appropriate size (to keep this example simple, we'll
      re-use the arrays from the first example above).  We call
      loadlp() to define a problem and return a pointer to it.
      Next, we call lpread() again to read in the actual array
      values.  Then we'll be ready to call mipoptimize(). */

   printf("\nExample: Read in MIP problem of unknown size\n");

   /* Call lpread() to obtain the problem dimensions.  If
      the matcnt argument is passed (needed only for sparse 
      problems), it must have at least as many elements as the 
      number of variables in the largest problem to be handled.
      (If necessary, you can call lpread() twice, the first 
      time to get this size via the numcols argument.) */

   lpread( NULL, "vcexamp1", &objsen, &numcols, &numrows, &numints,
      matcnt, NULL);

   /* We would now allocate the x[], obj[], lb[], ub[], and
      (if used) ctype[] and matbeg[] arrays to have numcols 
      elements, and the rhs[] and sense[] arrays to have 
      numrows elements.  For a dense problem, matval[] should 
      be allocated to have numcols * numrows elements.  For a
      sparse problem, the matind[] and matval[] arrays should
      be allocated to have nzspace elements, where nzspace is
      the sum of the counts in matcnt[] as returned by lpread().
      (To keep this example simple, we'll re-use the arrays
      from the first example above). */ 

   for (nzspace = i = 0; i < numcols; i++) nzspace += matcnt[i];
   /* (we could now allocate matind[] and matval[] based on nzspace) */
   for (i = 0; i < nzspace; i++) matval[i] = matind[i] = 0;
   /* matval[] and matind[] will be filled in by our next call to
      lpread(); we need only initialize matbeg[] based on matcnt[] */
   for (i = 0; i < numcols; i++)
      matbeg[i] = (i == 0 ? 0 : matbeg[i-1] + matcnt[i-1]);

   /* Next, call loadlp() and loadctype() to define the problem
      and pass in arrays of appropriate dimension. */

   lp = loadlp (PROBNAME, numcols, numrows, objsen, obj, rhs, sense,
      matbeg, matcnt, matind, matval, lb, ub, NULL,
      numcols, numrows, nzspace);
   if (!lp) return;
   loadctype( lp, ctype);

   /* Now we call lpread() to read in the actual array values. */

   lpread( lp, "vcexamp1", NULL, NULL, NULL, NULL, NULL, NULL);

   /* Finally, we call mipoptimize() and display the solution. */

   mipoptimize (lp);
   solution (lp, &stat, &objval, x, NULL, NULL, NULL);
   printf("LPstatus = %ld  Objective = %g\n", stat, objval);
   printf("x1 = %g  x2 = %g\n", x[0], x[1]);
   unloadprob (&lp);
}


int main(void)
{
   char buf[32];
   printf("TEST CASES FOR FRONTMIP.DLL\n");
   example1();
   example2();
   gets(buf);
   example3();
   example4();
   gets(buf);
   example5();
   return 0;
}

