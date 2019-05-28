/* *********************************************************************
   Frontline Systems Small-Scale Solver Dynamic Link Library Version 3.5
   Frontline Systems Inc., P.O. Box 4288, Incline Village, NV 89450 USA
   Tel (775) 831-0300 ** Fax (775) 831-0314 ** Email info@frontsys.com
   ********************************************************************* */

/*
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

   This is a "native Windows" application.  It includes two examples of
   "callback" routines:  One to compute the objective and constraints
   for the nonlinear Solver, and another which displays the iteration
   and current objective value, & quits if the user presses the ESC key.
   
   If your copy of the Solver DLL does not include the LP or NLP Solver
   "engine", a MessageBox will appear, and the results will show all
   zeroes for the solution status, objective and final variable values.
*/

#include <windows.h>
#include <string.h>
#include "frontmip.h"
#include "frontkey.h"

/* Prototype the procedures to follow... */
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
BOOL InitApplication(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);
PBYTE FPSTR( double value, PBYTE lpstr);
long _CC pivot (HPROBLEM lpinfo, long wherefrom);
void RunLPSolver(long *pstat, double *pobj, double *x);
void RunNLPSolver(long *pstat, double *pobj, double *x);

/* Global data... */
HANDLE hInst;  /* current instance */
HWND hWnd;     /* main window handle */
char szClassName[] = "ExampleClass";
char szAppTitle[] = "FRONTMIP WinExamp";


int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
     LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg;

    if (!hPrevInstance)
        if (!InitApplication(hInstance))
            return (FALSE);

    if (!InitInstance(hInstance, nCmdShow))
        return (FALSE);

    while (GetMessage(&msg, 0, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (msg.wParam);
}


BOOL InitApplication (HINSTANCE hInstance)
{
    WNDCLASS  wc;

    wc.style = 0;
    wc.lpfnWndProc = MainWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = GetStockObject(WHITE_BRUSH); 
    wc.lpszMenuName =  NULL;
    wc.lpszClassName = szClassName;

    return (RegisterClass(&wc));
}


BOOL InitInstance (HINSTANCE hInstance, int nCmdShow)
{

    hInst = hInstance;

    hWnd = CreateWindow(
        szClassName,
        szAppTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);
    if (!hWnd) return (FALSE);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    return (TRUE);
}


LRESULT CALLBACK MainWndProc
    (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hDC;                          /* display-context variable  */
    PAINTSTRUCT ps;                   /* paint structure           */
    TEXTMETRIC textmetric;
    int nDrawX, nDrawY, nSpacing;
    char szText[80], szObj[12], szVar1[12], szVar2[12];

    /* We call the Solver DLL on the 1st WM_PAINT message */
	static long LPstat = 0, NLPstat = 0;
    static double LPobj = 0.0, NLPobj = 0.0;
	static double LPx[2] = { 0.0, 0.0 }, NLPx[2] = { 0.0, 0.0 };
	static char LPtitle[] = "MIP Problem Results:";
	static char NLPtitle[] = "NLP Problem Results:";

    switch (message) {

    case WM_PAINT:
        hDC = BeginPaint (hWnd, &ps);
        GetTextMetrics (hDC, &textmetric);
		nSpacing = textmetric.tmExternalLeading + textmetric.tmHeight;

        /* Initialize drawing position to 1/4" from the top left */
        nDrawX = GetDeviceCaps (hDC, LOGPIXELSX) / 4;    /* 1/4" */
        nDrawY = GetDeviceCaps (hDC, LOGPIXELSY) / 4;    /* 1/4" */

        strcpy (szText, "WinExamp:  MIP and NLP problems with callbacks");
        TextOut (hDC, nDrawX, nDrawY, szText, strlen (szText));
        nDrawY += 2 * nSpacing;

        if (!LPstat)
        {
          RunLPSolver (&LPstat, &LPobj, LPx);
          RunNLPSolver (&NLPstat, &NLPobj, NLPx);
          SetWindowText (hWnd, szAppTitle);
        }

        FPSTR (LPobj, szObj);
        FPSTR (LPx[0], szVar1); FPSTR (LPx[1], szVar2);

        TextOut (hDC, nDrawX, nDrawY, LPtitle, strlen (LPtitle));
        nDrawY += nSpacing;

        wsprintf (szText, "LPstatus = %ld  Objective = %s",
          LPstat, (LPSTR)szObj);
        TextOut (hDC, nDrawX, nDrawY, szText, strlen (szText));
        nDrawY += nSpacing;

        wsprintf(szText, "x1 = %s  x2 = %s", (LPSTR)szVar1, (LPSTR)szVar2);
        TextOut (hDC, nDrawX, nDrawY, szText, strlen (szText));
        nDrawY += 2 * nSpacing;

        FPSTR (NLPobj, szObj);
        FPSTR (NLPx[0], szVar1); FPSTR (NLPx[1], szVar2);

        TextOut (hDC, nDrawX, nDrawY, NLPtitle, strlen (NLPtitle));
        nDrawY += nSpacing;

        wsprintf (szText, "LPstatus = %ld  Objective = %s",
          NLPstat, (LPSTR)szObj);
        TextOut (hDC, nDrawX, nDrawY, szText, strlen (szText));
        nDrawY += nSpacing;

        wsprintf(szText, "x1 = %s  x2 = %s", (LPSTR)szVar1, (LPSTR)szVar2);
        TextOut (hDC, nDrawX, nDrawY, szText, strlen (szText));
        nDrawY += 2 * nSpacing;

        EndPaint (hWnd,  &ps);
        break;

      case WM_DESTROY:
        PostQuitMessage(0);
        break;

      default:
        return (DefWindowProc(hWnd, message, wParam, lParam));
    }
    return 0;
}


PBYTE FPSTR( double value, PBYTE lpstr)
{
   PBYTE   buf = lpstr;
   int     length = 0;
   DWORD   dwFraction;
   if (value < 0.00) { *buf = '-'; length++; value = -value; }
   length += wsprintf( &buf[ length ], "%lu.", (DWORD) value);
   dwFraction = (DWORD) (1.00E+04 * (value - (DWORD) value));
   length += wsprintf( &buf[ length ], "%4.4lu", dwFraction);
   return lpstr;
}


/* Define a "callback" function which displays the iteration and current
   objective value in the window title bar, and checks for the ESC key */

long _CC pivot (HPROBLEM lpinfo, long wherefrom)
{
   long NumPivot; double Objective;
   char PivotMsg[64], ObjStr[12];
   MSG msg;

   getcallbackinfo( lpinfo, wherefrom, CBINFO_ITCOUNT, &NumPivot);
   getcallbackinfo( lpinfo, wherefrom, CBINFO_PRIMAL_OBJ, &Objective);
   FPSTR (Objective, ObjStr);
   wsprintf( PivotMsg, "Pivot # %ld:  Obj = %s", NumPivot, (LPSTR)ObjStr);
   SetWindowText (hWnd, PivotMsg);
   if (PeekMessage ((MSG FAR *) &msg, hWnd,
       WM_KEYDOWN, WM_KEYDOWN, PM_NOREMOVE))
      if (msg.wParam == VK_ESCAPE) return PSTAT_USER_ABORT;
   return PSTAT_CONTINUE;
}


/* Define and solve the example MIP problem */

void RunLPSolver (long *pstat, double *pobj, double *x)
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
   HPROBLEM lp = NULL;
   _CCPROC lpPivot;

   setintparam( lp, PARAM_ARGCK, 1);
   lp = loadlp (PROBNAME, 2, 3, -1, obj, rhs, sense,
      matbeg, matcnt, matind, matval, lb, ub, NULL, 2, 3, 6);
   if (!lp) return;
   loadctype (lp, ctype);

   lpPivot = (_CCPROC)MakeProcInstance ((FARPROC)pivot, hInst);
   setlpcallbackfunc( lp, lpPivot);
   optimize (lp);

   solution (lp, pstat, pobj, x, NULL, NULL, NULL);
   unloadprob( &lp);
   return;
}


/* Define a "callback" function which computes the objective and constraint
   left hand sides, for any supplied values of the decision variables. */

INTARG _CC funceval1 (HPROBLEM lp, INTARG numcols, INTARG numrows, LPREALARG objval,
   LPREALARG lhs, LPREALARG var, INTARG varone, INTARG vartwo)
{
   objval[0] = var[0] * var[0]  + var[1] * var[1] ; /* objective */
   lhs[0] = var[0] + var[1]; /* constraint left hand side */
   lhs[1] = var[0] * var[1]; /* constraint left hand side */
   return 0;
}


/* Define and solve the example NLP problem */

void RunNLPSolver (long *pstat, double *pobj, double *x)
{
   double obj[2];
   double rhs[2] = {  1.0, 0.0 };
   char sense[2] = "EG";
   double matval[4];
   double lb[] = { -INFBOUND, -INFBOUND };
   double ub[] = { +INFBOUND, +INFBOUND };
   HPROBLEM lp = NULL;
   _FUNCEVAL lpFuncEval;
   _CCPROC lpPivot;

   setintparam( lp, PARAM_ARGCK, 1);
   lpFuncEval = (_FUNCEVAL)MakeProcInstance ((FARPROC)funceval1, hInst);
   lp = loadnlp (PROBNAME, 2, 2, 1, obj, rhs, sense,
      NULL, NULL, NULL, matval, x, lb, ub, NULL, 4, lpFuncEval, NULL);
   if (!lp) return;

   lpPivot = (_CCPROC)MakeProcInstance ((FARPROC)pivot, hInst);
   setlpcallbackfunc( lp, lpPivot);
   optimize (lp);

   solution (lp, pstat, pobj, x, NULL, NULL, NULL);
   unloadprob( &lp);
   return;
}
