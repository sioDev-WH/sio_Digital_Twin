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

   This is a multi-threaded Windows application.  It creates two threads
   and two windows:  One thread repeatedly solves Problem 1 and displays
   the results in the first window, while the other thread repeatedly 
   solves Problem 2 and displays the results in the second window.
   
   If your copy of the Solver DLL does not include the LP or NLP Solver
   "engine", you may change the #defines PROBLEM1 and PROBLEM2 so that
   they both refer to the routine (either RunLPSolver or RunNLPSolver) 
   that calls the Solver engine that you have -- then the same results
   will appear in both windows.
*/

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "frontmip.h"
#include "frontkey.h"

#define PROBLEM1 RunLPSolver
#define PROBLEM2 RunNLPSolver

/* Prototype the procedures to follow... */

int WINAPI WinMain (HINSTANCE, HINSTANCE, LPSTR, int);
LRESULT CALLBACK MainWndProc (HWND, UINT, WPARAM, LPARAM);
BOOL InitApplication(HINSTANCE);
BOOL InitInstance(HINSTANCE, HWND *, char *, long, long, long, long);

/* Threads are not available in Win16... */
#ifdef WIN32
	DWORD WINAPI RunThread(LPVOID);
#endif

PBYTE FPSTR( double value, PBYTE lpstr);
long _CC pivot (HPROBLEM lpinfo, long wherefrom);
typedef long RunSolver(HWND hWnd, long *pstat, double *pobj, double *x);
RunSolver RunLPSolver, RunNLPSolver;

/* Global data... */
HANDLE hInst;  /* current instance */
HWND hWnd1, hWnd2;  /* window handles */
HPROBLEM lp1, lp2;  /* problem handles */
DWORD dwID1, dwID2; /* thread IDs in Win32 */
char szWinTitle1[] = "FRONTMIP Example 1";
char szWinTitle2[] = "FRONTMIP Example 2";
char szClassName[] = "FRONTMIP Class";
long Calls = 0; /* counts calls to RunLPSolver / RunNLPSolver */


int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
     LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg;

    if (!hPrevInstance)
        if (!InitApplication (hInstance))
            return (FALSE);

    if (!InitInstance (hInstance, &hWnd1, szWinTitle1, 10, 10, 300, 300))
        return (FALSE);
    if (!InitInstance (hInstance, &hWnd2, szWinTitle2, 330, 10, 300, 300))
        return (FALSE);

#ifdef WIN32
	srand( GetTickCount());
	CreateThread( NULL, 0, RunThread, (LPVOID)hWnd1, 0, &dwID1);
	CreateThread( NULL, 0, RunThread, (LPVOID)hWnd2, 0, &dwID1);
#endif

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


BOOL InitInstance(HINSTANCE hInstance, HWND *hWnd, char *szWinTitle,
				  long nX, long nY, long nWidth, long nHeight)
{

    hInst = hInstance;

    *hWnd = CreateWindow(
        szClassName,
        szWinTitle,
        WS_OVERLAPPEDWINDOW,
        nX, nY, nWidth, nHeight,
        NULL, NULL, hInstance, NULL);
    if (!*hWnd) return (FALSE);

    ShowWindow(*hWnd, SW_SHOW);
    UpdateWindow(*hWnd);
    return (TRUE);
}


#ifdef WIN32
DWORD WINAPI RunThread( LPVOID lpVoid)
{
	HWND hWnd = (HWND)lpVoid;
	int i;
	/* Cause Solver DLL to be called 9 more times for each window... */
	for (i = 1; i < 10; i++)
	{
		Sleep( rand() * 1000 / RAND_MAX ); /* wait random time (0 - 1 sec) */
		InvalidateRect( hWnd, NULL, TRUE); /* cause WM_PAINT for this window */
		UpdateWindow( hWnd);
	}
	return 0;
}
#endif


LRESULT CALLBACK MainWndProc
    (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hDC;                          /* display-context variable  */
    PAINTSTRUCT ps;                   /* paint structure           */
    TEXTMETRIC textmetric;
    int nDrawX, nDrawY, nSpacing;
    char szText[80], szObj[12], szVar1[12], szVar2[12];

    /* We call the Solver DLL on each WM_PAINT message */
	RunSolver *lpRunSolver;
	char *szWinTitle, *szProblem, *szResults;
	long stat = 0, calls = 0;
    double obj = 0.0;
	double x[2] = { 0.0, 0.0 };

	if (hWnd == hWnd1)
	{
		lpRunSolver = PROBLEM1;
		szWinTitle = szWinTitle1;
	}
	else /* hWnd == hWnd2 */
	{
		lpRunSolver = PROBLEM2;
		szWinTitle = szWinTitle2;
	}
	if (lpRunSolver == RunLPSolver)
	{
		szProblem = "WinExamp:  MIP problem";
		szResults = "MIP Problem Results:";
	}
	else /* lpRunSolver == RunNLPSolver */
	{
		szProblem = "WinExamp:  NLP problem";
		szResults = "NLP Problem Results:";
	}

    switch (message) {

    case WM_PAINT:
        hDC = BeginPaint (hWnd, &ps);
        GetTextMetrics (hDC, &textmetric);
		nSpacing = textmetric.tmExternalLeading + textmetric.tmHeight;

        /* Initialize drawing position to 1/4" from the top left */
        nDrawX = GetDeviceCaps (hDC, LOGPIXELSX) / 4;    /* 1/4" */
        nDrawY = GetDeviceCaps (hDC, LOGPIXELSY) / 4;    /* 1/4" */

        calls = lpRunSolver (hWnd, &stat, &obj, x);
        /* SetWindowText (hWnd, szWinTitle); */

        wsprintf (szText, "Call %ld:  %s", calls, szProblem);
        TextOut (hDC, nDrawX, nDrawY, szText, strlen (szText));
        nDrawY += 2 * nSpacing;

        FPSTR (obj, szObj);
        FPSTR (x[0], szVar1); FPSTR (x[1], szVar2);

        TextOut (hDC, nDrawX, nDrawY, szResults, strlen (szResults));
        nDrawY += nSpacing;

        wsprintf (szText, "Status = %ld  Objective = %s",
          stat, (LPSTR)szObj);
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
   MSG msg; HWND hWnd;

   getcallbackinfo( lpinfo, wherefrom, CBINFO_ITCOUNT, &NumPivot);
   getcallbackinfo( lpinfo, wherefrom, CBINFO_PRIMAL_OBJ, &Objective);
   FPSTR (Objective, ObjStr);
   wsprintf( PivotMsg, "Pivot # %ld:  Obj = %s", NumPivot, (LPSTR)ObjStr);
   hWnd = (lpinfo == lp1 ? hWnd1 : hWnd2);
   SetWindowText (hWnd, PivotMsg);
   if (PeekMessage ((MSG FAR *) &msg, hWnd,
       WM_KEYDOWN, WM_KEYDOWN, PM_NOREMOVE))
      if (msg.wParam == VK_ESCAPE) return PSTAT_USER_ABORT;
   return PSTAT_CONTINUE;
}


/* Define and solve the example MIP problem */

long RunLPSolver (HWND hWnd, long *pstat, double *pobj, double *x)
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
   if (!lp) return 0;
   if (hWnd == hWnd1) lp1 = lp; else lp2 = lp;
   loadctype (lp, ctype);

   lpPivot = (_CCPROC)MakeProcInstance ((FARPROC)pivot, hInst);
   setlpcallbackfunc( lp, lpPivot);
   optimize (lp);

   solution (lp, pstat, pobj, x, NULL, NULL, NULL);
   unloadprob( &lp);
   return ++Calls;
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

long RunNLPSolver (HWND hWnd, long *pstat, double *pobj, double *x)
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
   if (!lp) return 0;
   if (hWnd == hWnd1) lp1 = lp; else lp2 = lp;

   lpPivot = (_CCPROC)MakeProcInstance ((FARPROC)pivot, hInst);
   setlpcallbackfunc( lp, lpPivot);
   optimize (lp);

   solution (lp, pstat, pobj, x, NULL, NULL, NULL);
   unloadprob( &lp);
   return ++Calls;
}
