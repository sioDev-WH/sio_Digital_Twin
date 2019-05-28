Attribute VB_Name = "frontmip"
' Frontline Systems Solver DLL (Dynamic Link Library) Version 3.5
' Copyright 1995-99 Frontline Systems, Inc.  All Rights Reserved.
' Version 3.5 includes API calls for Nonsmooth Solver engines, and
' API changes for multi-problem, recursive and multi-threaded use.
' Include this header file in your Visual Basic project.

'  VERSION COMPATIBILITY INFORMATION:
'    In Version 3.5, all routines except loadlp() and loadnlp() take
'    an HPROBLEM argument.  Hence, the following routines from Version
'    3.0 have argument changes: getproblimits(), infointparam(),
'    setintparam(), getintparam(), infodblparam(), setdblparam(),
'    getdblparam(), setdefaults(), setlpcallbackfunc(),
'    getlpcallbackfunc(), setmipcallbackfunc(), getmipcallbackfunc().
'    Also, getlpcallbackfunc() and getmipcallbackfunc() return a value.
'
'    The following routines have been added in Version 3.5:  varstat(),
'    constat(), lpread(), getuse(), reportuse().
'
'    The following compatibility routines (originally from Version 1.0)
'    have been deleted: setepgap(), getepgap(), setepopt(), getepopt().

'Define the entry points for the Linear & Quadratic Solver 

Declare Function loadlp Lib "frontmip.dll" (ByVal probname As String, ByVal numcols As Long, ByVal numrows As Long, ByVal objsen As Long, obj As Double, rhs As Double, sense As Byte, matbeg As Long, matcnt As Long, matind As Long, matval As Double, lb As Double, ub As Double, rngval As Double, ByVal colspace As Long, ByVal rowspace As Long, ByVal nzspace As Long) As Long

Declare Function loadquad Lib "frontmip.dll" (ByVal lp As Long, qmatbeg As Long, qmatcnt As Long, qmatind As Long, qmatval As Double, ByVal qnzspace As Long, var As Double) As Long

Declare Function loadctype Lib "frontmip.dll" (ByVal lp As Long, ctype As Byte) As Long

'Define the entry points for the Nonlinear & NonSmooth Solver 

Declare Function loadnlp Lib "frontmip.dll" (ByVal probname As String, ByVal numcols As Long, ByVal numrows As Long, ByVal objsen As Long, obj As Double, rhs As Double, sense As Byte, matbeg As Long, matcnt As Long, matind As Long, matval As Double, var As Double, lb As Double, ub As Double, rngval As Double, ByVal nzspace As Long, ByVal funceval As Long, ByVal jacobian As Long) As Long

Declare Function loadnltype Lib "frontmip.dll" (ByVal lp As Long, objtype As Byte, matvaltype As Byte) As Long

Declare Function testnltype Lib "frontmip.dll" (ByVal lp As Long, ByVal numtests As Long, testvals As Double, pstat As Long, objtype As Byte, matvaltype As Byte) As Long

'Define the optimize and solution routines 

Declare Function optimize Lib "frontmip.dll" (ByVal lp As Long) As Long

Declare Function mipoptimize Lib "frontmip.dll" (ByVal lp As Long) As Long

Declare Function solution Lib "frontmip.dll" (ByVal lp As Long, pstat As Long, pobj As Double, x As Double, piout As Double, slack As Double, dj As Double) As Long

Declare Function objsa Lib "frontmip.dll" (ByVal lp As Long, ByVal begidx As Long, ByVal endidx As Long, lower As Double, upper As Double) As Long

Declare Function rhssa Lib "frontmip.dll" (ByVal lp As Long, ByVal begidx As Long, ByVal endidx As Long, lower As Double, upper As Double) As Long

'varstat() and constat() are new for NonSmooth Solver engines 

Declare Function varstat Lib "frontmip.dll" (ByVal lp As Long, ByVal begidx As Long, ByVal endidx As Long, mid As Double, disp As Double, lower As Double, upper As Double) As Long

Declare Function constat Lib "frontmip.dll" (ByVal lp As Long, ByVal begidx As Long, ByVal endidx As Long, mid As Double, disp As Double, lower As Double, upper As Double) As Long

'Define the IIS (Irreducibly Infeasible Set) finding routines 

Declare Function findiis Lib "frontmip.dll" (ByVal lp As Long, iisnumrows_p As Long, iisnumcols_p As Long) As Long

Declare Function getiis Lib "frontmip.dll" (ByVal lp As Long, iisstat_p As Long, rowind As Long, rowbdstat As Long, iisnumrows_p As Long, colind As Long, colbdstat As Long, iisnumcols_p As Long) As Long

'unloadprob MUST be called to free memory 

Declare Function unloadprob Lib "frontmip.dll" (lp As Long) As Long

'   routines to set and get parameter values, including size limits.
'   Note- getproblimits(), getuse(), reportuse(), infointparam(), and 
'   infodblparam() always ignore their HPROBLEM argument; setintparam()
'   and getintparam() ignore their HPROBLEM argument when they are
'   called with PARAM_ARGCK, PARAM_ARRAY and PARAM_USERP parameters.
'   In all other situations, you must first define a problem with 
'   loadlp() or loadnlp(), and pass its HPROBLEM pointer to the 
'   other routines. 

Declare Function getproblimits Lib "frontmip.dll" (ByVal lp As Long, ByVal typ As Long, numcols_p As Long, numrows_p As Long, numints_p As Long) As Long

Declare Function getuse Lib "frontmip.dll" (ByVal lp As Long, loadprob_p As Long, optimize_p As Long, verify_p As Long, repload_p As Long, repopt_p As Long, repdate_p As Long) As Long

Declare Function reportuse Lib "frontmip.dll" (ByVal lp As Long, ByVal probname As String, ByVal filename As String, ByVal profilename As String, ByVal password As String) As Long

Declare Function infointparam Lib "frontmip.dll" (ByVal lp As Long, ByVal whichparam As Long, defvalue_p As Long, minvalue_p As Long, maxvalue_p As Long) As Long

Declare Function infodblparam Lib "frontmip.dll" (ByVal lp As Long, ByVal whichparam As Long, defvalue_p As Double, minvalue_p As Double, maxvalue_p As Double) As Long

Declare Function setintparam Lib "frontmip.dll" (ByVal lp As Long, ByVal whichparam As Long, ByVal newvalue As Long) As Long

Declare Function getintparam Lib "frontmip.dll" (ByVal lp As Long, ByVal whichparam As Long, value_p As Long) As Long

Declare Function setdblparam Lib "frontmip.dll" (ByVal lp As Long, ByVal whichparam As Long, ByVal newvalue As Double) As Long

Declare Function getdblparam Lib "frontmip.dll" (ByVal lp As Long, ByVal whichparam As Long, value_p As Double) As Long

Declare Function setdefaults Lib "frontmip.dll" (ByVal lp As Long) As Long

'routines to define and use the LP and MIP callback functions 

Declare Function setlpcallbackfunc Lib "frontmip.dll" (ByVal lp As Long, ByVal callback As Long) As Long

Declare Function setmipcallbackfunc Lib "frontmip.dll" (ByVal lp As Long, ByVal callback As Long) As Long

Declare Function getcallbackinfo Lib "frontmip.dll" (ByVal lp As Long, ByVal wherefrom As Long, ByVal infonumber As Long, ByRef result As Any) As Long

'routines to read and write a file summarizing an LP/QP/MIP 
'problem in algebraic form 

Declare Function lpread Lib "frontmip.dll" (ByVal lp As Long, ByVal filename As String, objsen_p As Long, numcols_p As Long, numrows_p As Long, numints_p As Long, matcnt As Long, qmatcnt As Long) As Long

Declare Function lpwrite Lib "frontmip.dll" (ByVal lp As Long, ByVal filename As String) As Long

Declare Function lprewrite Lib "frontmip.dll" (ByVal lp As Long, ByVal filename As String) As Long

Declare Function iiswrite Lib "frontmip.dll" (ByVal lp As Long, ByVal filename As String) As Long

Public Const PROB_LP               As Long = 0   'linear problem
Public Const PROB_MIP              As Long = 1   'linear integer problem
Public Const PROB_QP               As Long = 4   'quadratic problem
Public Const PROB_QPMIP            As Long = 8   'quadratic integer problem
Public Const PROB_NLP              As Long = 12  'nonlinear problem
Public Const PROB_NLPMIP           As Long = 16  'nonlinear integer problem
Public Const PROB_NSP              As Long = 20  'nonsmooth problem
Public Const PROB_NSPMIP           As Long = 24  'nonsmooth integer problem

Public Const PSTAT_CONTINUE        As Long = 0   'Used in callback to continue solving
Public Const PSTAT_OPTIMAL         As Long = 1   'An optimal solution has been found
Public Const PSTAT_INFEASIBLE      As Long = 2   'No feasible solution could be found
Public Const PSTAT_UNBOUNDED       As Long = 3   'The objective value is unbounded
Public Const PSTAT_IT_LIM_FEAS     As Long = 5   'Iteration limit exceeded, feasible solution
Public Const PSTAT_IT_LIM_INFEAS   As Long = 6   'Iteration limit exceeded, no feasible solution
Public Const PSTAT_TIME_LIM_FEAS   As Long = 7   'Time limit exceeded, feasible solution
Public Const PSTAT_TIME_LIM_INFEAS As Long = 8   'Time limit exceeded, no feasible solution
Public Const PSTAT_ABORT_FEAS      As Long = 12  'User aborted solve, feasible solution
Public Const PSTAT_ABORT_INFEAS    As Long = 13  'User aborted solve, no feasible solution

Public Const PSTAT_MIP_OPTIMAL         As Long = 101  'Optimal integer solution found
Public Const PSTAT_MIP_OPTIMAL_TOL     As Long = 102  'Integer solution found within epgap
Public Const PSTAT_MIP_INFEASIBLE      As Long = 103  'No feasible integer solution
Public Const PSTAT_MIP_SOL_LIM         As Long = 104  'Limit of integer solutions exceeded
Public Const PSTAT_MIP_NODE_LIM_FEAS   As Long = 105  'Node limit exceeded, integer solution
Public Const PSTAT_MIP_NODE_LIM_INFEAS As Long = 106  'Node limit exceeded, no int solution
Public Const PSTAT_MIP_TIME_LIM_FEAS   As Long = 107  'Time limit exceeded, integer solution
Public Const PSTAT_MIP_TIME_LIM_INFEAS As Long = 108  'Time limit exceeded, no int solution

Public Const PSTAT_FRACT_CHANGE        As Long = 65   'Objective function changing too slowly
Public Const PSTAT_NO_REMEDIES         As Long = 66   'All remedies failed to find better point
Public Const PSTAT_FLOAT_ERROR         As Long = 67   'Error when evaluating problem functions
Public Const PSTAT_MEM_LIM             As Long = 68   'Could not allocate enough main memory
Public Const PSTAT_ENTRY_ERROR         As Long = 69   'Attempt to use DLL from 2 or more threads

Public Const PARAM_ARGCK      As Long = 990    'on argument errors: 1-MsgBox, 0-retval only
Public Const PARAM_ARRAY      As Long = 995    'arrays are: 0-C-style arrays, 1-SAFEARRAYs
Public Const PARAM_USERP      As Long = 997    '0-eval/test, 1-auto report, 2-user reports
Public Const PARAM_IISBND     As Long = 999    'IIS finder: 0-includes bnds, 1-omits bounds
Public Const PARAM_ITLIM      As Long = 1020   'limit on LP iterations - per (sub)problem
Public Const PARAM_NDLIM      As Long = 2017   'limit on Branch & Bound nodes explored
Public Const PARAM_MIPLIM     As Long = 2015   'limit on Branch & Bound IP solutions found
Public Const PARAM_SAMPSZ     As Long = 6001   'Evol Solver population (sample) size
Public Const PARAM_NOIMP      As Long = 6002   'Evol Solver max time w/no improvement
Public Const PARAM_SCAIND     As Long = 1033   'scaling: -1-none, 0-normal, 1-aggressive
Public Const PARAM_CRAIND     As Long = 1007   'crashing: 0-none, 1-crash initial basis
Public Const PARAM_RELAX      As Long = 2501   'solve relaxation: 1-on, 0-use int vars
Public Const PARAM_PREPRO     As Long = 2502   'B&B Preprocessing and Probing: 1-on, 0-off
Public Const PARAM_OPTFIX     As Long = 2503   'B&B Optimality Fixing:  1-on, 0-off
Public Const PARAM_REORDR     As Long = 2504   'B&B Branch Variable Reordering: 1-on, 0-off
Public Const PARAM_IMPBND     As Long = 2505   'B&B Bounds Improvement: 1-on, 0-off

Public Const PARAM_TILIM      As Long = 1038   'global solution time limit
Public Const PARAM_EPOPT      As Long = 1014   'LP optimality tolerance
Public Const PARAM_EPPIV      As Long = 1091   'LP pivot tolerance
Public Const PARAM_EPSOL      As Long = 1092   'LSLP solution tolerance
Public Const PARAM_EPRHS      As Long = 1016   'LP feasibility tolerance
Public Const PARAM_EPGAP      As Long = 2009   'integer tolerance/MIP gap
Public Const PARAM_CUTLO      As Long = 2006   'known incumbent for max MIP
Public Const PARAM_CUTHI      As Long = 2007   'known incumbent for min MIP

Public Const PARAM_DERIV      As Long = 5011   'NLP derivative computation
Public Const PARAM_ESTIM      As Long = 5012   'NLP estimates for basic vars
Public Const PARAM_DIREC      As Long = 5013   'NLP search direction option
Public Const PARAM_LINVAR     As Long = 5010   'NLP recognize linear vars

Public Const PARAM_EPNEWT     As Long = 5001   'NLP constraint tolerance
Public Const PARAM_EPCONV     As Long = 5002   'NLP slow change stopping tol
Public Const PARAM_MUTATE     As Long = 6010   'Evol mutation probability

Public Const CALLBACK_PRIMAL  As Long = 1      'callback on LP pivot
Public Const CALLBACK_MIP     As Long = 101    'callback on MIP branch

Public Const INFBOUND         As Double = 1E+30

Public Const CBINFO_PRIMAL_OBJ     As Long = 1  'callback: objective
Public Const CBINFO_PRIMAL_INFMEAS As Long = 3  'callback: infeasibility
Public Const CBINFO_PRIMAL_FEAS    As Long = 5  'callback: whether feasible
Public Const CBINFO_ITCOUNT        As Long = 7  'callback: iteration count
Public Const CBINFO_BEST_INTEGER   As Long = 8  'callback: MIP incumbent
Public Const CBINFO_NODE_COUNT     As Long = 10 'callback: nodes explored
Public Const CBINFO_MIP_ITERATIONS As Long = 12 'callback: MIP iterations

