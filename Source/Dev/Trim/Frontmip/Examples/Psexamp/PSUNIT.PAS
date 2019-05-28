   {
   Problem 1: Solve the MIP model:
   Maximize   2 x1 +  3 x2
   Subj to    9 x1 +  6 x2 <= 54
              6 x1 +  7 x2 <= 42
              5 x1 + 10 x2 <= 50
   x1, x2 non-negative, integer
   MIP solution: x1 = 2, x2 = 4
   Objective = 16.0

   Problem 2: Solve the NLP model:
   Minimize X^2 + Y^2
   Subject to:
      X + Y  = 1
      X * Y >= 0
   x1, x2 non-negative
   Solution is X = Y = 0.5, Objective = 0.5
   }

unit Psunit;

interface

uses
  SysUtils, WinTypes, WinProcs, Messages, Classes, Graphics, Controls,
  Forms, Dialogs, StdCtrls, Frontmip;
{$I Frontkey}

type
  TForm1 = class(TForm)
    LPLabel: TLabel;
    LPEdit1: TEdit;
    LPEdit2: TEdit;
    LPButton: TButton;
    NLPLabel: TLabel;
    NLPEdit1: TEdit;
    NLPEdit2: TEdit;
    NLPButton: TButton;
    procedure LPButtonClick(Sender: TObject);
    procedure NLPButtonClick(Sender: TObject);
  private
    { Private declarations }
  public
     obj: array[0..1] of double;
     rhs: array[0..2] of double;
     sense: array[0..2] of char;
     matbeg: array[0..1] of Longint;
     matcnt: array[0..1] of Longint;
     matind: array[0..5] of Longint;
     matval: array[0..5] of double;
     lb: array[0..1] of double;
     ub: array[0..1] of double;
     ctype: array[0..1] of char;
     stat: Longint;
     objval: double;
     x: array[0..1] of double;
     NullL: Longint;
     NullD: Double;
     lp: longint;
     ret: Longint;
  end;

var
  Form1: TForm1;

implementation

{$R *.DFM}

{$IFDEF WIN32}

{ Define a "callback" function which displays the iteration and current
  objective value }

function callback(lpinfo: Longint; wherefrom: Longint): Longint;
stdcall;
var
   iters: Longint;
   obj: Double;
   objtext, Msg: String;
begin
   getcallbackinfo (lpinfo, wherefrom, CBINFO_ITCOUNT, iters);
   getcallbackinfo (lpinfo, wherefrom, CBINFO_PRIMAL_OBJ, obj);
   str (obj:4:4,objtext);
   Msg := 'Iteration: ' + inttostr(iters) + '  Objective: ' + objtext;
   Application.MessageBox (PChar(Msg), 'callback', IDOK);
   Result := PSTAT_CONTINUE;
end;

{ Define a "callback" function which computes the objective and constraint
  left hand sides, for any supplied values of the decision variables. }

function funceval1(lp: Longint; numcols: Longint; numrows: Longint;
   var objval: Double; var lhs: DimD; var pvar: DimD;
   varone: Longint; vartwo: Longint): Longint;
stdcall;
begin
   objval := pvar[0] * pvar[0] + pvar[1] * pvar[1] ; { objective }
   lhs[0] := pvar[0] + pvar[1]; { constraint left hand side }
   lhs[1] := pvar[0] * pvar[1]; { constraint left hand side }
   Result := 0;
end;
{$ENDIF}

{ Define and solve the example LP/MIP problem }

procedure TForm1.LPButtonClick(Sender: TObject);
var
   objtext:string;
   x0:string;
   x1:string;
begin
     { objective coefficients }
     obj[0]:=2;
     obj[1]:=3;
     { right hand sides of constraints }
     rhs[0]:=54;
     rhs[1]:=42;
     rhs[2]:=50;
     { sense of constraints: 'L' is <= }
     sense[0]:='L';
     sense[1]:='L';
     sense[2]:='L';
     { define constraint coefficients using the "sparse
       matrix" form -- See Solver User Guide for details }
     matbeg[0]:=0;
     matbeg[1]:=3;
     matcnt[0]:=3;
     matcnt[1]:=3;
     matind[0]:=0;
     matind[1]:=1;
     matind[2]:=2;
     matind[3]:=0;
     matind[4]:=1;
     matind[5]:=2;
     matval[0]:=9;
     matval[1]:=6;
     matval[2]:=5;
     matval[3]:=6;
     matval[4]:=7;
     matval[5]:=10;
     { bounds on variables }
     lb[0]:=0;
     lb[1]:=0;
     ub[0]:=INFBOUND;
     ub[1]:=INFBOUND;
     { integer variables }
     ctype[0]:='I';
     ctype[1]:='I';
     { to pass a NULL or empty array }
     NullL := -1;
     NullD := -1;

     setintparam (NullL, PARAM_ARGCK, 1);
     lp := loadlp (PROBNAME, 2, 3, -1, obj[0], rhs[0], sense, matbeg[0],
          matcnt[0], matind[0], matval[0], lb[0], ub[0], NullD, 2, 3, 6);
     if (lp = 0) then Exit;
     ret := loadctype (lp, ctype);
     ret := lpwrite (lp, 'psexamp');
{$IFDEF WIN32}
     setlpcallbackfunc (lp, callback);
{$ENDIF}
     ret := optimize (lp);
     ret := solution (lp, stat, objval, x[0], NullD, NullD, NullD);
     str (objval:4:4,objtext);
     LPEdit1.text := 'Status = ' + inttostr(stat) + ' Objective = ' + objtext;
     str (x[0]:4:4, x0);
     str (x[1]:4:4, x1);
     LPEdit2.text := 'x1 = ' + x0 + ' x2 = ' + x1;
end;

{ Define and solve the example NLP problem.
  This works only in 32-bit Delphi 2.0 or above. }

procedure TForm1.NLPButtonClick(Sender: TObject);
var
   objtext:string;
   x0:string;
   x1:string;
begin
     { right hand sides of constraints }
     rhs[0]:=1;
     rhs[1]:=0;
     { sense of constraints: 'E' is =, 'G' is >= }
     sense[0]:='E';
     sense[1]:='G';
     { bounds on variables }
     lb[0]:=-INFBOUND;
     lb[1]:=-INFBOUND;
     ub[0]:=INFBOUND;
     ub[1]:=INFBOUND;
     { to pass NULL or empty arrays }
     NullL := -1;
     NullD := -1;
{$IFDEF WIN32}
     setintparam (NullL, PARAM_ARGCK, 1);
     lp := loadnlp (PROBNAME, 2, 2, 1, obj[0], rhs[0], sense, NullL,
           NullL, NullL, matval[0], x[0], lb[0], ub[0], NullD,
           4, funceval1, nil);
     if (lp = 0) then Exit;
     setlpcallbackfunc (lp, callback);
     ret := optimize (lp);
     ret := solution (lp, stat, objval, x[0], NullD, NullD, NullD);
     str (objval:4:4,objtext);
     NLPEdit1.text := 'Status = ' + inttostr(stat) + ' Objective = ' + objtext;
     str (x[0]:4:4, x0);
     str (x[1]:4:4, x1);
     NLPEdit2.text := 'x1 = ' + x0 + ' x2 = ' + x1;
{$ENDIF}
end;

end.
