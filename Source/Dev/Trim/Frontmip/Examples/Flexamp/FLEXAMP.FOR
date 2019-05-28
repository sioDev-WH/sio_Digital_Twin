C     **********************************************************************
C     Frontline Systems Solver DLL (Dynamic Link Library) Version 3.5
C     Frontline Systems Inc., P.O. Box 4288, Incline Village, NV 89450 USA
C     Tel (775) 831-0300 ** Fax (775) 831-0314 ** Email info@frontsys.com
C
C     Example LP/MIP problem in FORTRAN: Build as QuickWin project contain-
C     ing files FLEXAMP.FOR and FRONTMIP.LIB (the import library).  Use
C     FORTRAN Powerstation 4.0 with WIN32 defined, or FORTRAN 5.1 for 16-bit.
C     **********************************************************************

$IF DEFINED( WIN32)

C     Define a "callback" function that displays the iteration number
C     and current objective value 
      INTEGER*4 FUNCTION lpcallback[STDCALL] (lp, wherefrom)
      INTEGER*4 lp[VALUE], wherefrom[VALUE]
      INCLUDE 'frontcbi.for'
      INTEGER*4 ret, iter, mip

      ret = getcallbackinfo (lp, wherefrom, CBINFO_MIP_ITERATIONS, mip)
      ret = getcallbackinfo (lp, wherefrom, CBINFO_ITCOUNT, iter)
      WRITE (*, 10) mip, iter
10    FORMAT (' MIP subproblem 'I3' LP Iteration'I3)
      lpcallback = 0
      END FUNCTION

C     Define a "callback" function that computes the objective and
C     constraint left hand sides, for any supplied values of the variables.

      INTEGER*4 FUNCTION funceval1[STDCALL] (lp, numcols, numrows,
     +  objval, lhs, var, varone, vartwo)
      INTEGER*4 lp[VALUE], numcols[VALUE], numrows[VALUE]
      REAL*8 objval[REFERENCE]
      REAL*8 lhs(0:1), var(0:1)
      INTEGER*4 varone[VALUE], vartwo[VALUE]

      objval = var(0) * var(0) + var(1) * var(1)
      lhs(0) = var(0) + var(1)
      lhs(1) = var(0) * var(1)
      funceval1 = 0
      END FUNCTION

C     Define a "callback" function that computes the objective gradient and
C     Jacobian of the constraints for any supplied values of the variables.

      INTEGER*4 FUNCTION jacobian1[STDCALL] (lp, numcols, numrows,
     +  nzspace, objval, obj, matbeg, matcnt, matind, matval, var,
     +  objtype, matvaltype)
      INTEGER*4 lp[VALUE], numcols[VALUE], numrows[VALUE]
      INTEGER*4 nzspace[VALUE]
      REAL*8 objval[REFERENCE], obj(0:1)
      INTEGER*4 matbeg(0:1), matcnt(0:1), matind(0:1)
      REAL*8 matval(0:1), var(0:1)
      CHARACTER*2 objtype[REFERENCE]
      CHARACTER*2 matvaltype[REFERENCE]

      WRITE (*, 20) var(0), var(1)
20    FORMAT (' Jacobian evaluated at: x1 = 'F7.2'  x2 = 'F7.2)
C     Value of the objective function
      objval = var(0) * var(0) + var(1) * var(1)
C     Partial derivatives of the objective
      obj(0) = 2.0 * var(0);
      obj(1) = 2.0 * var(1);
C     Partial derivatives of X + Y (constant)
      matval(0) = 1.0;
      matval(2) = 1.0;
C     Partial derivatives of X * Y (variable)
      matval(1) = var(1);
      matval(3) = var(0);
      jacobian1 = 0
      END FUNCTION

$ENDIF

      INCLUDE 'frontmip.for'
$IF (.NOT.DEFINED( WIN32))
      INTEGER*4 setintparam, loadlp, loadctype, optimize, solution
      INTEGER*4 lprewrite
$ENDIF
      EXTERNAL lpcallback, funceval1, jacobian1
      INTEGER*4 lpcallback, funceval1, jacobian1

C     You must initialize PROBNAME with your own license key string!
      CHARACTER*16 PROBNAME /'1111111111111111'/
      REAL*8 obj(0:1) / 2.0, 3.0 /
      REAL*8 rhs(0:2) /  54.0, 42.0, 50.0 /
      CHARACTER*3 sense /'LLL'/
      INTEGER*4 matbeg(0:1) / 0, 3 /
      INTEGER*4 matcnt(0:1) / 3, 3 /
      INTEGER*4 matind(0:5) / 0, 1, 2, 0, 1, 2 /
      REAL*8 matval(0:5) / 9.0, 6.0, 5.0, 6.0, 7.0, 10.0 /
      REAL*8 lb(0:1) / 0.0, 0.0 /
      REAL*8 ub(0:1) / 1.0e30, 1.0e30 /
      CHARACTER*2 ctype /'II'/
      INTEGER*4 stat, ret
      REAL*8 objval, x(0:1)
      INTEGER*4 lp
      INTEGER*4 NullL(0:1) / -1, -1 /
      REAL*8 NullD(0:1) / -1.0, -1.0 /

C     Display MessageBoxes on invalid arguments, for both problems
      ret = setintparam (0, PARAM_ARGCK, 1 )

      WRITE (*, 100)
100   FORMAT (' Example LP/MIP problem')
C     Set up the LP portion of the problem
      lp = loadlp (PROBNAME, 2, 3, -1, obj, rhs, sense,
     +	matbeg, matcnt, matind, matval, lb, ub, NullD, 2, 3, 6)
C     Now define the integer variables
      ret = loadctype (lp, ctype)
C     Write out the problem as a text file, in "algebraic" format
      ret = lpwrite (lp, 'flexamp')
$IF DEFINED( WIN32)
C     Set up the callback function to display iteration # and objective
      ret = setlpcallbackfunc( lp, lpcallback )
$ENDIF
C     Solve the mixed-integer problem
      ret = optimize (lp)
C     Obtain and write out the solution
      ret = solution (lp, stat, objval, x, NullD, NullD, NullD)
      WRITE (*, 110) stat, objval
110   FORMAT (' LPstatus = 'I3,'  Objective = 'F7.2)
      WRITE (*, 120) x(0), x(1)
120   FORMAT (' x1 = 'F7.2,'  x2 = 'F7.2)

$IF DEFINED( WIN32)
      WRITE (*, 200)
200   FORMAT (/' Example NLP problem')
C     Re-initialize the values of the rhs, sense, and lb arrays
      rhs(0) = 1.0
      rhs(1) = 0.0
      sense = 'EG'
      lb(0) = -INFBOUND
      lb(1) = -INFBOUND
C     Initialize the values of the variables
      x(0) = 0.25
      x(1) = 0.25
C     Set up the NLP problem
      lp = loadnlp (PROBNAME, 2, 2, 1, obj, rhs, sense,
     +	NullL, NullL, NullL, matval, x, lb, ub, NullD, 4,
     +    funceval1, jacobian1)
C     Set up the callback function to display iteration # and objective
      ret = setlpcallbackfunc( lp, lpcallback )
C     Solve the nonlinear problem
      ret = optimize (lp)
C     Obtain and write out the solution
      ret = solution (lp, stat, objval, x, NullD, NullD, NullD)
      WRITE (*, 110) stat, objval
      WRITE (*, 120) x(0), x(1)
$ENDIF

      END
