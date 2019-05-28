/************************************************************************
*  Error.C (Implementation of error handler and misc. checkings)
*
*  Version:                     1.9
*  Date:                        6/18/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)Error.C 1.9 93/06/18 OK";

//#include "stdafx.h"
#include "error.h"
#include <stdio.h>

INT ErrorHandler::LastErrorCode = 0;
INT ErrorHandler::MaxErrorLevel = 0;
INT ErrorHandler::WarningLevel = ErrorHandler::Warning;
INT ErrorHandler::SevereLevel  = ErrorHandler::SevereError;

ErrorHandler MyErrorHandler; // destructor should be called automatically at the end

VOID ErrorReport (INT DoReportSuccess)
{
  if (ErrorHandler::MaxErrorLevel > 0) {
    fprintf (stderr, "*** Errors occured:\n");
    fprintf (stderr, "    Max. error level: %d\n", ErrorHandler::MaxErrorLevel);
    fprintf (stderr, "    Last error code:  %d\n", ErrorHandler::LastErrorCode);
    fflush (stderr);
    ErrorHandler::MaxErrorLevel = 0; // to prevent this report to occur twice
  }
  else if (DoReportSuccess) {
    fprintf (stderr, "*** No errors occured.\n");
    fflush (stderr);
  }
}

VOID Error (PCHAR s, INT ErrNo, ErrorHandler::ErrorLevel Priority)
{
  INT ErrorType;
  INT isWarning;

  ErrorHandler::LastErrorCode = ErrNo;
  if (Priority > ErrorHandler::MaxErrorLevel)
    ErrorHandler::MaxErrorLevel = Priority;
  if (Priority == ErrorHandler::FatalError) ErrorType = 0;
  else if (Priority < ErrorHandler::SevereLevel) ErrorType = 1;
  else ErrorType = 2;
  if (ErrorType && (Priority < ErrorHandler::WarningLevel)) return;
  isWarning = (Priority < ErrorHandler::SevereError);
  if (ErrorType)
    fprintf (stderr, "*** %s%s [%d/%d]: %s\n",
	     isWarning ? "Warning" : "Error",
	     ((ErrorType == 1) && !isWarning) ? "(ignored)" : "",
	     ErrNo, Priority, s);
  else
    fprintf (stderr, "*** Fatal Error: %s\n", s);
  fflush (stderr);
  switch (ErrorType) {
  case 0:
    abort ();
  case 1:
    return;
  case 2:
    exit (1);
  }
}

VOID FatalError (PCHAR s)
{
  Error (s, 1, ErrorHandler::FatalError);
}

VOID _CheckDimensions (INT aDim, INT bDim)
{
  if (aDim != bDim) FatalError ("Dimensions differ");
}

VOID _CheckMatrixDimensions (INT aRowDim, INT bRowDim, INT aColDim, INT bColDim)
{
  if (aRowDim != bRowDim) FatalError ("Row dimensions differ");
  if (aColDim != bColDim) FatalError ("Column dimensions differ");
}

VOID _CheckQuadratic (INT rDim, INT cDim)
{
  if (rDim != cDim) FatalError ("Non quadratic matrix");
}

VOID _CheckMemory (PVOID p)
{
  if (p == NULL) FatalError ("Out of Memory");
}

#ifdef __INDEXCHECK__
VOID _CheckVectorRange (INT n)
{
  if (n < 0) FatalError ("Negative vector dimension");
}

VOID _CheckMatrixRange (INT n, INT m)
{
  if (n < 0) FatalError ("Negative matrix row dimension");
  if (m < 0) FatalError ("Negative matrix column dimension");
}

VOID _CheckVectorIndex (INT i, INT n)
{
  if ((i <= 0) || (i > n))
    FatalError ("Vector index out of range");
}

VOID _CheckMatrixRowIndex (INT i, INT n)
{
  if ((i <= 0) || (i > n))
    FatalError ("Matrix row index out of range");
}

VOID _CheckMatrixColIndex (INT i, INT n)
{
  if ((i <= 0) || (i > n))
    FatalError ("Matrix column index out of range");
}
#endif
