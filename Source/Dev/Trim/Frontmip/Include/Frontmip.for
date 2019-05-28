C     Frontline Systems Solver DLL (Dynamic Link Library) Version 3.5
C     Copyright 1995-99 Frontline Systems, Inc.  All Rights Reserved.
C     Version 3.5 includes API calls for Nonsmooth Solver engines, and
C     API changes for multi-problem, recursive and multi-threaded use.
C     Include this file in your Microsoft FORTRAN program for Windows.
C     For 32-bit Fortran Powerstation, be sure that WIN32 is defined.

C     VERSION COMPATIBILITY INFORMATION:
C     In Version 3.5, all routines except loadlp() and loadnlp() take 
C     an HPROBLEM argument.  Hence, the following routines from Version
C     3.0 have argument changes: getproblimits(), infointparam(),
C     setintparam(), getintparam(), infodblparam(), setdblparam(),
C     getdblparam(), setdefaults(), setlpcallbackfunc(), 
C     getlpcallbackfunc(), setmipcallbackfunc(), getmipcallbackfunc().
C     Also, getlpcallbackfunc() and getmipcallbackfunc() return a value.
C
C     The following routines have been added in Version 3.5:  varstat(),
C     constat(), lpread(), getuse(), reportuse().
C
C     The following compatibility routines (originally from Version 1.0)
C     have been deleted: setepgap(), getepgap(), setepopt(), getepopt().


$IF DEFINED( WIN32)
      INTERFACE
$ENDIF


C     Define the entry points for the Linear & Quadratic Solver

$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION loadlp[STDCALL]
     + (probname, numcols, numrows, objsen, obj, rhs, sense,
     +  matbeg, matcnt, matind, matval, lb, ub, rngval,
     +  cspace, rspace, nzspace)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION loadlp
     + (probname, numcols, numrows, objsen, obj, rhs, sense,
     +  matbeg, matcnt, matind, matval, lb, ub, rngval,
     +  cspace, rspace, nzspace)
$ENDIF
      CHARACTER*2 probname[REFERENCE]
      INTEGER*4 numcols[VALUE], numrows[VALUE], objsen[VALUE]
      REAL*8 obj(0:1), rhs(0:1)
      CHARACTER*2 sense[REFERENCE]
      INTEGER*4 matbeg(0:1), matcnt(0:1), matind(0:1)
      REAL*8 matval(0:1), lb(0:1), ub(0:1), rngval(0:1)
      INTEGER*4 cspace[VALUE], rspace[VALUE], nzspace[VALUE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION loadquad[STDCALL]
     + (lp, qmatbeg, qmatcnt, qmatind, qmatval, qnzspace, var)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION loadquad
     + (lp, qmatbeg, qmatcnt, qmatind, qmatval, qnzspace, var)
$ENDIF
      INTEGER*4 lp[VALUE]
      INTEGER*4 qmatbeg(0:1), qmatcnt(0:1), qmatind(0:1)
      REAL*8 qmatval(0:1)
      INTEGER*4 qnzspace[VALUE]
      REAL*8 var(0:1)
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION loadctype[STDCALL] (lp, ctype)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION loadctype (lp, ctype)
$ENDIF
      INTEGER*4 lp[VALUE]
      CHARACTER*2 ctype[REFERENCE]
      END


C     Define the entry points for the Nonlinear & NonSmooth Solver

$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION loadnlp[STDCALL]
     + (probname, numcols, numrows, objsen, obj, rhs, sense,
     +  matbeg, matcnt, matind, matval, var, lb, ub, rngval,
     +  nzspace, funceval, jacobian)
      CHARACTER*2 probname[REFERENCE]
      INTEGER*4 numcols[VALUE], numrows[VALUE], objsen[VALUE]
      REAL*8 obj(0:1), rhs(0:1)
      CHARACTER*2 sense[REFERENCE]
      INTEGER*4 matbeg(0:1), matcnt(0:1), matind(0:1)
      REAL*8 matval(0:1), var(0:1), lb(0:1), ub(0:1), rngval(0:1)
      INTEGER*4 nzspace[VALUE]
      INTERFACE
        INTEGER*4 FUNCTION funceval[STDCALL] (lp, numcols, numrows,
     +    objval, lhs, var, varone, vartwo)
        INTEGER*4 lp[VALUE], numcols[VALUE], numrows[VALUE]
        REAL*8 objval[REFERENCE]
        REAL*8 lhs(0:1), var(0:1)
        INTEGER*4 varone[VALUE], vartwo[VALUE]
        END
      END INTERFACE
      INTERFACE
        INTEGER*4 FUNCTION jacobian[STDCALL] (lp, numcols, numrows,
     +    nzspace, objval, obj, matbeg, matcnt, matind, matval, var,
     +    objtype, matvaltype)
        INTEGER*4 lp[VALUE], numcols[VALUE], numrows[VALUE]
        INTEGER*4 nzspace[VALUE]
        REAL*8 objval[REFERENCE], obj(0:1)
        INTEGER*4 matbeg(0:1), matcnt(0:1), matind(0:1)
        REAL*8 matval(0:1), var(0:1)
        CHARACTER*2 objtype[REFERENCE]
        CHARACTER*2 matvaltype[REFERENCE]
        END
      END INTERFACE
      END


      INTEGER*4 FUNCTION loadnltype[STDCALL] (lp, objtype, matvaltype)
      INTEGER*4 lp[VALUE]
      CHARACTER*2 objtype[REFERENCE]
      CHARACTER*2 matvaltype[REFERENCE]
      END


      INTEGER*4 FUNCTION testnltype[STDCALL] (lp, numtests, testvals,
     +  pstat, objtype, matvaltype)
      INTEGER*4 lp[VALUE], numtests[VALUE]
      REAL*8 testvals(0:1)
      INTEGER*4 pstat[REFERENCE]
      CHARACTER*2 objtype[REFERENCE]
      CHARACTER*2 matvaltype[REFERENCE]
      END
$ENDIF


C     Define the optimize and solution routines

$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION optimize[STDCALL] (lp)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION optimize (lp)
$ENDIF
      INTEGER*4 lp[VALUE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION mipoptimize[STDCALL] (lp)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION mipoptimize (lp)
$ENDIF
      INTEGER*4 lp[VALUE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION solution[STDCALL]
     + (lp, pstat, pobj, x, piout, slack, dj)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION solution
     + (lp, pstat, pobj, x, piout, slack, dj)
$ENDIF
      INTEGER*4 lp[VALUE]
      INTEGER*4 pstat[REFERENCE]
      REAL*8 pobj[REFERENCE]
      REAL*8 x(0:1), piout(0:1), slack(0:1), dj(0:1)
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION objsa[STDCALL]
     + (lp, begidx, endidx, lower, upper)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION objsa
     + (lp, begidx, endidx, lower, upper)
$ENDIF
      INTEGER*4 lp[VALUE]
      INTEGER*4 begidx[VALUE], endidx[VALUE]
      REAL*8 lower(0:1), upper(0:1)
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION rhssa[STDCALL]
     + (lp, begidx, endidx, lower, upper)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION rhssa
     + (lp, begidx, endidx, lower, upper)
$ENDIF
      INTEGER*4 lp[VALUE]
      INTEGER*4 begidx[VALUE], endidx[VALUE]
      REAL*8 lower(0:1), upper(0:1)
      END


C     varstat() and constat() are new for NonSmooth Solver engines

$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION varstat[STDCALL]
     + (lp, begidx, endidx, mid, disp, lower, upper)
      INTEGER*4 lp[VALUE]
      INTEGER*4 begidx[VALUE], endidx[VALUE]
      REAL*8 mid(0:1), disp(0:1), lower(0:1), upper(0:1)
      END

      INTEGER*4 FUNCTION constat[STDCALL]
     + (lp, begidx, endidx, mid, disp, lower, upper)
      INTEGER*4 lp[VALUE]
      INTEGER*4 begidx[VALUE], endidx[VALUE]
      REAL*8 mid(0:1), disp(0:1), lower(0:1), upper(0:1)
      END
$ENDIF


C     Define the IIS (Irreducibly Infeasible Set) finding routines

$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION findiis[STDCALL] (lp, iisnumrows_p,
     +  iisnumcols_p)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION findiis (lp, iisnumrows_p,
     +  iisnumcols_p)
$ENDIF
      INTEGER*4 lp[VALUE]
      INTEGER*4 iisnumrows_p[REFERENCE], iisnumcols_p[REFERENCE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION getiis[STDCALL] (lp, iisstat_p,
     +  rowind, rowbdstat, iisnumrows_p,
     +  colind, colbdstat, iisnumcols_p)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION getiis (lp, iisstat_p,
     +  rowind, rowbdstat, iisnumrows_p,
     +  colind, colbdstat, iisnumcols_p)
$ENDIF
      INTEGER*4 lp[VALUE]
      INTEGER*4 iisstat_p[REFERENCE]
      INTEGER*4 rowind(0:1), rowbdstat(0:1)
      INTEGER*4 iisnumrows_p[REFERENCE]
      INTEGER*4 colind(0:1), colbdstat(0:1)
      INTEGER*4 iisnumcols_p[REFERENCE]
      END


C     unloadprob MUST be called to free memory

$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION unloadprob[STDCALL] (lp)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION unloadprob (lp)
$ENDIF
      INTEGER*4 lp[REFERENCE]
      END


C     routines to set and get parameter values, including size limits.
C     Note- getproblimits(), getuse(), reportuse(), infointparam(), and 
C     infodblparam() always ignore their HPROBLEM argument; setintparam()
C     and getintparam() ignore their HPROBLEM argument when they are
C     called with PARAM_ARGCK, PARAM_ARRAY and PARAM_USERP parameters.
C     In all other situations, you must first define a problem with 
C     loadlp() or loadnlp(), and pass its HPROBLEM pointer to the 
C     other routines.

$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION getproblimits[STDCALL]
     + (lp, type, numcols_p, numrows_p, numints_p)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION getproblimits
     + (lp, type, numcols_p, numrows_p, numints_p)
$ENDIF
      INTEGER*4 lp[VALUE], type[VALUE]
      INTEGER*4 numcols_p[REFERENCE], numrows_p[REFERENCE],
     + numints_p[REFERENCE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION getuse[STDCALL]
     + (lp, loadprob_p, optimize_p, verify_p,
     +  repload_p, repopt_p, repdate_p)
      INTEGER*4 lp[VALUE]
      INTEGER*4 loadprob_p [REFERENCE], optimize_p [REFERENCE],
     + verify_p [REFERENCE], repload_p [REFERENCE],
     + repopt_p [REFERENCE], repdate_p [REFERENCE]
      END

      INTEGER*4 FUNCTION reportuse[STDCALL]
     + (lp, probname, filename, profilename, password)
      INTEGER*4 lp[VALUE]
      CHARACTER*2 probname[REFERENCE], filename[REFERENCE],
     + profilename [REFERENCE], password [REFERENCE]
      END
$ENDIF


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION infointparam[STDCALL]
     + (lp, whichparam, defvalue_p, minvalue_p, maxvalue_p) 
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION infointparam
     + (lp, whichparam, defvalue_p, minvalue_p, maxvalue_p) 
$ENDIF
      INTEGER*4 lp[VALUE], whichparam[VALUE]
      INTEGER*4 defvalue_p[REFERENCE]
      INTEGER*4 minvalue_p[REFERENCE], maxvalue_p[REFERENCE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION infodblparam[STDCALL]
     + (lp, whichparam, defvalue_p, minvalue_p, maxvalue_p) 
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION infodblparam
     + (lp, whichparam, defvalue_p, minvalue_p, maxvalue_p) 
$ENDIF
      INTEGER*4 lp[VALUE], whichparam[VALUE]
      REAL*8 defvalue_p[REFERENCE]
      REAL*8 minvalue_p[REFERENCE], maxvalue_p[REFERENCE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION setintparam[STDCALL]
     + (lp, whichparam, newvalue) 
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION setintparam
     + (lp, whichparam, newvalue) 
$ENDIF
      INTEGER*4 lp[VALUE], whichparam[VALUE], newvalue[VALUE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION getintparam[STDCALL]
     + (lp, whichparam, value_p) 
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION getintparam
     + (lp, whichparam, value_p) 
$ENDIF
      INTEGER*4 lp[VALUE], whichparam[VALUE], value_p[REFERENCE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION setdblparam[STDCALL]
     + (lp, whichparam, newvalue) 
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION setdblparam
     + (lp, whichparam, newvalue) 
$ENDIF
      INTEGER*4 lp[VALUE], whichparam[VALUE]
      REAL*8 newvalue[VALUE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION getdblparam[STDCALL]
     + (lp, whichparam, value_p) 
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION getdblparam
     + (lp, whichparam, value_p) 
$ENDIF
      INTEGER*4 lp[VALUE], whichparam[VALUE]
      REAL*8 value_p[REFERENCE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION setdefaults[STDCALL] (lp)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION setdefaults (lp)
$ENDIF
      INTEGER*4 lp[VALUE]
      END


C     routines to define and use the LP and MIP callback functions

$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION setlpcallbackfunc[STDCALL] (lp, lpcallback)
      INTEGER*4 lp[VALUE]
      INTERFACE
        INTEGER*4 FUNCTION lpcallback[STDCALL] (lpinfo, wherefrom)
        INTEGER*4 lpinfo[VALUE], wherefrom[VALUE]
        END
      END INTERFACE
      END


      INTEGER*4 FUNCTION setmipcallbackfunc[STDCALL] (lp, mipcallback)
      INTEGER*4 lp[VALUE]
      INTERFACE
        INTEGER*4 FUNCTION mipcallback[STDCALL] (lpinfo, wherefrom)
        INTEGER*4 lpinfo[VALUE], wherefrom[VALUE]
        END
      END INTERFACE
      END
$ENDIF


C     routines to read and write a file summarizing an LP/QP/MIP problem
C     in algebraic form

$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION lpread[STDCALL]
     + (lp, filename, objsen_p, numcols_p, numrows_p, numints_p,
     +  matcnt, qmatcnt) 
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION lpread
     + (lp, filename, objsen_p, numcols_p, numrows_p, numints_p,
     +  matcnt, qmatcnt) 
$ENDIF
      INTEGER*4 lp[VALUE]
      CHARACTER*2 filename[REFERENCE]
      INTEGER*4 objsen_p[REFERENCE], numcols_p[REFERENCE],
     +  numrows_p[REFERENCE], numints_p[REFERENCE]
      INTEGER*4 matcnt(0:1), qmatcnt(0:1)
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION lpwrite[STDCALL] (lp, filename)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION lpwrite (lp, filename)
$ENDIF
      INTEGER*4 lp[VALUE]
      CHARACTER*2 filename[REFERENCE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION lprewrite[STDCALL] (lp, filename)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION lprewrite (lp, filename)
$ENDIF
      INTEGER*4 lp[VALUE]
      CHARACTER*2 filename[REFERENCE]
      END


$IF DEFINED( WIN32)
      INTEGER*4 FUNCTION iiswrite[STDCALL] (lp, filename)
$ELSE
      INTERFACE TO INTEGER*4 FUNCTION iiswrite (lp, filename)
$ENDIF
      INTEGER*4 lp[VALUE]
      CHARACTER*2 filename[REFERENCE]
      END


$IF DEFINED( WIN32)
      END INTERFACE
$ENDIF


C     Define symbolic names for status codes (pstat argument of solution)
C     and parameter type codes for the routines set/get/infointparam and
C     set/get/infodblparam.  Further comments are in C/C++ FRONTMIP.H.

      INTEGER*4 PROB_LP, PROB_MIP, PROB_QP, PROB_QPMIP, PROB_NLP, 
     +  PROB_NLPMIP
      PARAMETER (
     +  PROB_LP     =  0,
     +  PROB_MIP    =  1,
     +  PROB_QP     =  4,
     +  PROB_QPMIP  =  8,
     +  PROB_NLP    =  12,
     +  PROB_NLPMIP =  16,
     +  PROB_NSP    =  20,
     +  PROB_NSPMIP =  24)

      INTEGER*4 PSTAT_CONTINUE, PSTAT_OPTIMAL, PSTAT_INFEASIBLE,
     +  PSTAT_UNBOUNDED, PSTAT_IT_LIM_FEAS, PSTAT_IT_LIM_INFEAS,
     +  PSTAT_TIME_LIM_FEAS, PSTAT_TIME_LIM_INFEAS, PSTAT_USER_ABORT,
     +  PSTAT_ABORT_FEAS, PSTAT_ABORT_INFEAS, PSTAT_FRACT_CHANGE,
     +  PSTAT_NO_REMEDIES, PSTAT_FLOAT_ERROR, PSTAT_MEM_LIM,
     +  PSTAT_ENTRY_ERROR
      PARAMETER (
     +  PSTAT_CONTINUE        = 0,
     +  PSTAT_OPTIMAL         = 1,
     +  PSTAT_INFEASIBLE      = 2,
     +  PSTAT_UNBOUNDED       = 3,
     +  PSTAT_IT_LIM_FEAS     = 5,
     +  PSTAT_IT_LIM_INFEAS   = 6,
     +  PSTAT_TIME_LIM_FEAS   = 7,
     +  PSTAT_TIME_LIM_INFEAS = 8,
     +  PSTAT_USER_ABORT      = 12,
     +  PSTAT_ABORT_FEAS      = 12,
     +  PSTAT_ABORT_INFEAS    = 13,
     +  PSTAT_FRACT_CHANGE    = 65,
     +  PSTAT_NO_REMEDIES     = 66,
     +  PSTAT_FLOAT_ERROR     = 67,
     +  PSTAT_MEM_LIM         = 68,
     +  PSTAT_ENTRY_ERROR     = 69)

      INTEGER*4 PSTAT_MIP_OPTIMAL, PSTAT_MIP_OPTIMAL_TOL,
     +  PSTAT_MIP_INFEASIBLE, PSTAT_MIP_SOL_LIM,
     +  PSTAT_MIP_NODE_LIM_FEAS, PSTAT_MIP_NODE_LIM_INFEAS,
     +  PSTAT_MIP_TIME_LIM_FEAS, PSTAT_MIP_TIME_LIM_INFEAS
      PARAMETER (
     +  PSTAT_MIP_OPTIMAL         = 101,
     +  PSTAT_MIP_OPTIMAL_TOL     = 102,
     +  PSTAT_MIP_INFEASIBLE      = 103,
     +  PSTAT_MIP_SOL_LIM         = 104,
     +  PSTAT_MIP_NODE_LIM_FEAS   = 105,
     +  PSTAT_MIP_NODE_LIM_INFEAS = 106,
     +  PSTAT_MIP_TIME_LIM_FEAS   = 107,
     +  PSTAT_MIP_TIME_LIM_INFEAS = 108)

      INTEGER*4 PARAM_ARGCK, PARAM_ARRAY, PARAM_USERP, PARAM_IISBND,
     +  PARAM_ITLIM, PARAM_NDLIM, PARAM_MIPLIM, PARAM_SAMPSZ,
     +  PARAM_NOIMP, PARAM_SCAIND, PARAM_CRAIND, PARAM_RELAX,
     +  PARAM_PREPRO, PARAM_OPTFIX, PARAM_REORDR, PARAM_IMPBND,
     +  PARAM_REQBND 
      PARAMETER (
     +  PARAM_ARGCK      =  990,
     +  PARAM_ARRAY      =  995,
     +  PARAM_USERP      =  997,
     +  PARAM_IISBND     =  999,
     +  PARAM_ITLIM      = 1020,
     +  PARAM_NDLIM      = 2017,
     +  PARAM_MIPLIM     = 2015,
     +  PARAM_SAMPSZ     = 6001,
     +  PARAM_NOIMP      = 6002,
     +  PARAM_SCAIND     = 1033,
     +  PARAM_CRAIND     = 1007,
     +  PARAM_RELAX      = 2501,
     +  PARAM_PREPRO     = 2502,
     +  PARAM_OPTFIX     = 2503,
     +  PARAM_REORDR     = 2504,
     +  PARAM_IMPBND     = 2505,
     +  PARAM_REQBND     = 6003)

      INTEGER*4 PARAM_TILIM, PARAM_EPOPT, PARAM_EPPIV, PARAM_EPSOL,
     +  PARAM_EPRHS, PARAM_EPGAP, PARAM_CUTLO, PARAM_CUTHI,
     +  PARAM_EPNEWT, PARAM_EPCONV, PARAM_LINVAR, PARAM_DERIV,
     +  PARAM_ESTIM, PARAM_DIREC, PARAM_MUTATE
      PARAMETER (
     +  PARAM_TILIM      = 1038,
     +  PARAM_EPOPT      = 1014,
     +  PARAM_EPPIV      = 1091,
     +  PARAM_EPSOL      = 1092,
     +  PARAM_EPRHS      = 1016,
     +  PARAM_EPGAP      = 2009,
     +  PARAM_CUTLO      = 2006,
     +  PARAM_CUTHI      = 2007,
     +  PARAM_EPNEWT     = 5001,
     +  PARAM_EPCONV     = 5002,
     +  PARAM_LINVAR     = 5010,
     +  PARAM_DERIV      = 5011,
     +  PARAM_ESTIM      = 5012,
     +  PARAM_DIREC      = 5013,
     +  PARAM_MUTATE     = 6010)

      REAL*8 INFBOUND
      PARAMETER (INFBOUND = 1.0E30)
