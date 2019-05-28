{  Frontline Systems Solver DLL (Dynamic Link Library) Version 3.5
   Copyright 1995-99 Frontline Systems, Inc.  All Rights Reserved.
   Version 3.5 includes API calls for Nonsmooth Solver engines, and
   API changes for multi-problem, recursive and multi-threaded use.
   Include this header file in your Delphi Pascal project.  Be sure
   to mention unit Frontmip in your "Uses" statement(s). }

{  VERSION COMPATIBILITY INFORMATION:
   In Version 3.5, all routines except loadlp() and loadnlp() take 
   an HPROBLEM argument.  Hence, the following routines from Version
   3.0 have argument changes: getproblimits(), infointparam(),
   setintparam(), getintparam(), infodblparam(), setdblparam(),
   getdblparam(), setdefaults(), setlpcallbackfunc(), 
   getlpcallbackfunc(), setmipcallbackfunc(), getmipcallbackfunc().
   Also, getlpcallbackfunc() and getmipcallbackfunc() return a value.

   The following routines have been added in Version 3.5:  varstat(),
   constat(), lpread(), getuse(), reportuse().

   The following compatibility routines (originally from Version 1.0)
   have been deleted: setepgap(), getepgap(), setepopt(), getepopt(). }

unit Frontmip;

interface

const
   INFBOUND              = 1E30;

   PROB_LP               = 0;
   PROB_MIP              = 1;
   PROB_QP               = 4;
   PROB_QPMIP            = 8;
   PROB_NLP              = 12;
   PROB_NLPMIP           = 16;
   PROB_NSP              = 20;
   PROB_NSPMIP           = 24;

{  Define return codes for the callback functions }

   PSTAT_CONTINUE        = 0;  { Used in callback to continue solving     }
   PSTAT_OPTIMAL         = 1;  { An optimal solution has been found       }
   PSTAT_INFEASIBLE      = 2;  { No feasible solution could be found      }
   PSTAT_UNBOUNDED       = 3;  { The objective value is unbounded         }
   PSTAT_IT_LIM_FEAS     = 5;  { Iteration limit exceeded, feasible sol   }
   PSTAT_IT_LIM_INFEAS   = 6;  { Iteration limit exceeded, no feasible sol}
   PSTAT_TIME_LIM_FEAS   = 7;  { Time limit exceeded, feasible solution   }
   PSTAT_TIME_LIM_INFEAS = 8;  { Time limit exceeded, no feasible solution}
   PSTAT_USER_ABORT      = 12; { May be returned by callback routine      }
   PSTAT_ABORT_FEAS      = 12; { User aborted solve, feasible solution    }
   PSTAT_ABORT_INFEAS    = 13; { User aborted solve, no feasible solution }

   PSTAT_FRACT_CHANGE    = 65; { Objective function changing too slowly   }
   PSTAT_NO_REMEDIES     = 66; { All remedies failed to find better point }
   PSTAT_FLOAT_ERROR     = 67; { Error when evaluating problem functions  }
   PSTAT_MEM_LIM         = 68; { Could not allocate enough main memory    }
   PSTAT_ENTRY_ERROR     = 69; { Attempt to use DLL from 2 or more threads}

   PSTAT_MIP_OPTIMAL         = 101; {Optimal integer solution found       }
   PSTAT_MIP_OPTIMAL_TOL     = 102; {Integer solution found within epgap  }
   PSTAT_MIP_INFEASIBLE      = 103; {No feasible integer solution         }
   PSTAT_MIP_SOL_LIM         = 104; {Limit of integer solutions exceeded  }
   PSTAT_MIP_NODE_LIM_FEAS   = 105; {Node limit exceeded, integer solution}
   PSTAT_MIP_NODE_LIM_INFEAS = 106; {Node limit exceeded, no int solution }
   PSTAT_MIP_TIME_LIM_FEAS   = 107; {Time limit exceeded, integer solution}
   PSTAT_MIP_TIME_LIM_INFEAS = 108; {Time limit exceeded, no int solution }

{  Define symbolic names for parameters controlled by set/get/infointparam
   and set/get/infodblparam.  note: when PARAM_ARGCK and PARAM_ARRAY are 
   used with setintparam() and getintparam(), the HPROBLEM argument is
   ignored and the effect is global, on all problem instances and threads }

   PARAM_ARGCK      =  990; { on argument errors: 1-MsgBox, 0-retval only}
   PARAM_ARRAY      =  995; { arrays are: 0-C-style arrays, 1-SAFEARRAYs }
   PARAM_USERP      =  997; { 0-eval/test, 1-auto report, 2-user reports }
   PARAM_IISBND     =  999; { IIS finder: 0-includes bnds, 1-omits bounds}
   PARAM_ITLIM      = 1020; { limit on LP iterations - per (sub)problem  }
   PARAM_NDLIM      = 2017; { limit on Branch & Bound nodes explored     }
   PARAM_MIPLIM     = 2015; { limit on Branch & Bound IP solutions found }
   PARAM_SAMPSZ     = 6001; { Evol Solver population (sample) size       }
   PARAM_NOIMP      = 6002; { Evol Solver max time w/no improvement      }
   PARAM_SCAIND     = 1033; { scaling: -1-none, 0-normal, 1-aggressive   }
   PARAM_CRAIND     = 1007; { crashing: 0-none, 1-crash initial basis    }
   PARAM_RELAX      = 2501; { solve relaxation: 1-on, 0-use int vars     }
   PARAM_PREPRO     = 2502; { B&B Preprocessing and Probing: 1-on, 0-off }
   PARAM_OPTFIX     = 2503; { B&B Optimality Fixing:  1-on, 0-off        }
   PARAM_REORDR     = 2504; { B&B Branch Variable Reordering: 1-on, 0-off}
   PARAM_IMPBND     = 2505; { B&B Bounds Improvement: 1-on, 0-off        }
   PARAM_REQBND     = 6003; { Evol Solver: 1-require bounds, 0-don't     }

   PARAM_TILIM      = 1038; { global solution time limit  }
   PARAM_EPOPT      = 1014; { LP optimality tolerance     }
   PARAM_EPPIV      = 1091; { LP pivot tolerance          }
   PARAM_EPSOL      = 1092; { LSLP solution tolerance     }
   PARAM_EPRHS      = 1016; { LP feasibility tolerance    }
   PARAM_EPGAP      = 2009; { integer tolerance/MIP gap   }
   PARAM_CUTLO      = 2006; { known incumbent for max MIP }
   PARAM_CUTHI      = 2007; { known incumbent for min MIP }

   PARAM_EPNEWT     = 5001; { NLP constraint tolerance    }
   PARAM_EPCONV     = 5002; { NLP slow change stopping tol}
   PARAM_LINVAR     = 5010; { NLP recognize linear vars   }
   PARAM_DERIV      = 5011; { NLP derivative computation  }
   PARAM_ESTIM      = 5012; { NLP estimates for basic vars}
   PARAM_DIREC      = 5013; { NLP search direction option }
   PARAM_MUTATE     = 6010; { Evol mutation probability   }

{  Define "wherefrom" codes for callback functions  }

   CALLBACK_PRIMAL  = 1;      { callback on LP/NLP pivot  }
   CALLBACK_MIP     = 101;    { callback on MIP branch    }

{  Define info request codes for callback functions }

   CBINFO_PRIMAL_OBJ     = 1; { callback: objective       }
   CBINFO_PRIMAL_INFMEAS = 3; { callback: infeasibility   }
   CBINFO_PRIMAL_FEAS    = 5; { callback: whether feasible}
   CBINFO_ITCOUNT        = 7; { callback: iteration count }
   CBINFO_BEST_INTEGER   = 8; { callback: MIP incumbent   }
   CBINFO_NODE_COUNT     = 10;{ callback: nodes explored  }
   CBINFO_MIP_ITERATIONS = 12;{ callback: MIP iterations  }

{ Array types for callback functions }
Type
  DimL = array [0..99] of Longint;
  DimD = array [0..99] of Double;

{ Callback function for setlpcallbackfunc, setmipcallbackfunc }

Type CCPROC = Function(lpinfo:Longint; wherefrom:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ENDIF}

{ Callbacks to compute function values, and the objective value,
  objective gradient and Jacobian matrix of partial derivatives }

Type FUNCEVAL = Function(lp:Longint; numcols:Longint; numrows:Longint; var objval:Double;
   var lhs:DimD; var pvar:DimD; varone:Longint; vartwo:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ENDIF}

Type JACOBIAN = Function(lp:Longint; numcols:Longint; numrows:Longint; var objval:Double;
   var obj:DimD; var matbeg:DimL; var matcnt:DimL; var matind:DimL;
   var matval:DimD; var pvar:DimD; objtype:PChar; matvaltype:PChar): Longint;
{$IFDEF WIN32} stdcall; {$ENDIF}

{  Define the entry points for the Linear & Quadratic Solver }

Function loadlp (probname:Pchar; numcols:Longint; numrows:Longint;
   objsen:Longint; var obj:Double; var rhs:Double; sense:Pchar;
   var matbeg:Longint; var matcnt:Longint; var matind:Longint;
   var matval:Double; var lb:Double; var ub:Double; var rngval:Double;
   colspace:Longint; rowspace:Longint; nzspace:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function loadquad (lp:Longint; var qmatbeg:Longint; var qmatcnt:Longint;
   var qmatind:Longint; var qmatval:Double; qnzspace:Longint; var pvar:Double): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function loadctype (lp:Longint; ctype:Pchar): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

{  Define the entry points for the Nonlinear & NonSmooth Solver }

Function loadnlp (probname:Pchar; numcols:Longint; numrows:Longint;
   objsen:Longint; var obj:Double; var rhs:Double; sense:Pchar;
   var matbeg:Longint; var matcnt:Longint; var matind:Longint;
   var matval:Double; var pvar:Double; var lb:Double; var ub:Double;
   var rngval:Double; nzspace:Longint; funcevalf:FUNCEVAL; jacobianf:JACOBIAN): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function loadnltype (lp:Longint; objtype:Pchar; matvaltype:Pchar): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function testnltype (lp:Longint; numtests:Longint; var testvals:Double;
   var pstat:Longint; objtype:Pchar; matvaltype:Pchar): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

{  Define the optimize and solution routines }

Function optimize (lp:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function mipoptimize (lp:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function solution (lp:Longint; var pstat:Longint; var pobj:Double;
   var x:Double; var piout:Double; var slack:Double; var dj:Double): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function objsa (lp:Longint; begidx: Longint; endidx:Longint;
   var lower:Double; var upper:Double): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function rhssa (lp:Longint; begidx: Longint; endidx:Longint;
   var lower:Double; var upper:Double): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

{  varstat() and constat() are new for NonSmooth Solver engines }

Function varstat (lp:Longint; begidx: Longint; endidx:Longint;
   var mid:Double; var disp:Double; var lower:Double;
   var upper:Double): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function constat (lp:Longint; begidx: Longint; endidx:Longint;
   var mid:Double; var disp:Double; var lower:Double;
   var upper:Double): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

{ Define the IIS (Irreducibly Infeasible Set) finding routines }

Function findiis (lp:Longint; var iisnumrows_p:Longint;
   var iisnumcols_p:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function getiis (lp:Longint; var iisstat_p:Longint;
   var rowind:Longint; var rowbdstat:Longint; var iisnumrows_p:Longint;
   var colind:Longint; var colbdstat:Longint; var iisnumcols_p:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

{  unloadprob MUST be called to free memory }

Function unloadprob (var lp:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

{  routines to set and get parameter values, including size limits.
   Note- getproblimits(), getuse(), reportuse(), infointparam(), and 
   infodblparam() always ignore their HPROBLEM argument; setintparam()
   and getintparam() ignore their HPROBLEM argument when they are
   called with PARAM_ARGCK, PARAM_ARRAY and PARAM_USERP parameters.
   In all other situations, you must first define a problem with 
   loadlp() or loadnlp(), and pass its HPROBLEM pointer to the 
   other routines. }

Function getproblimits (lp:Longint; probtype:Longint; var numcols_p:Longint;
   var numrows_p:Longint; var numints_p:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function getuse (lp:Longint; var loadprob_p:Longint; var optimize_p:Longint;
   var verify_p:Longint; var repload_p:Longint; var repopt_p:Longint;
   var repdate_p:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function reportuse (lp:Longint; probname:Pchar; filename:Pchar;
   profilename:Pchar; password:Pchar): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function infointparam (lp:Longint; whichparam:Longint; var defvalue_p:Longint;
   var minvalue_p:Longint; var maxvalue_p:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function setintparam (lp:Longint; whichparam:Longint;
   newvalue:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function getintparam (lp:Longint; whichparam:Longint;
   var value_p:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function infodblparam (lp:Longint; whichparam:Longint; var defvalue_p:Double;
   var minvalue_p:Double; var maxvalue_p:Double): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function setdblparam (lp:Longint; whichparam:Longint;
   newvalue:Double): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function getdblparam (lp:Longint; whichparam:Longint;
   var value_p:Double): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function setdefaults (lp:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

{ routines to define and use the LP and MIP callback functions }

Function setlpcallbackfunc (lp:Longint; callback:CCPROC): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function getlpcallbackfunc (lp:Longint; var callback_p:CCPROC): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function setmipcallbackfunc (lp:Longint; callback:CCPROC): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function getmipcallbackfunc (lp:Longint; var callback_p:CCPROC): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function getcallbackinfo (lpinfo:Longint; wherefrom:Longint;
   infonumber:Longint; var result_p): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

{  routines to read and write a file summarizing LP/QP/MIP problem in
   algebraic form }

Function lpread (lp:Longint; filename:Pchar; var objsen_p:Longint;
   var numcols_p:Longint; var numrows_p:Longint; var numints_p:Longint;
   var matcnt:Longint; var qmatcnt:Longint): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function lpwrite (lp:Longint; filename:Pchar): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function lprewrite (lp:Longint; filename:Pchar): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

Function iiswrite (lp:Longint; filename:Pchar): Longint;
{$IFDEF WIN32} stdcall; {$ELSE} far; {$ENDIF}

implementation

Function loadlp;              external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function loadquad;            external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function loadctype;           external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function loadnlp;             external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function loadnltype;          external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function testnltype;          external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function optimize;            external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function mipoptimize;         external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function solution;            external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function objsa;               external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function rhssa;               external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function varstat;             external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function constat;             external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function findiis;             external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function getiis;              external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function unloadprob;          external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function getproblimits;       external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function getuse;              external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function reportuse;           external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function infointparam;        external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function infodblparam;        external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function setintparam;         external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function getintparam;         external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function setdblparam;         external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function getdblparam;         external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function setdefaults;         external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function setlpcallbackfunc;   external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function getlpcallbackfunc;  external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function setmipcallbackfunc;  external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function getmipcallbackfunc; external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function getcallbackinfo;     external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function lpread;              external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function lpwrite;             external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function lprewrite;           external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}
Function iiswrite;            external
{$IFDEF WIN32} 'frontmip.dll'; {$ELSE} 'frontmip'; {$ENDIF}

end.
 
