/************************************************************************
*  Error.h (Definition of error handler and misc. checkings)
*
*  Version:                     1.7
*  Date:                        1/10/95
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __ERROR__
#define __ERROR__

#include "Portab.h"
#include "config.h"

#define CheckDimensions(a,b)        _CheckDimensions (Dimension(a), Dimension(b))
#define CheckColumnDimensions(a,b)  _CheckDimensions (ColDimension(a), Dimension(b))
#define CheckRowDimensions(a,b)     _CheckDimensions (RowDimension(a), Dimension(b))
#define CheckMatrixMatrixDimensions(a,b) \
  _CheckDimensions (ColDimension(a), RowDimension(b))
#define CheckMatrixDimensions(a,b)  \
  _CheckMatrixDimensions (RowDimension(a), RowDimension(b), \
			  ColDimension(a), ColDimension(b))
#define CheckQuadratic(a)           _CheckQuadratic(RowDimension(a), ColDimension(a))
#define CheckMemory(p)              _CheckMemory     ((PVOID) (p))

#ifdef __INDEXCHECK__
#define CheckVectorRange(n)         _CheckVectorRange (n)
#define CheckMatrixRange(n,m)       _CheckMatrixRange (n, m)
#define CheckVectorIndex(i,v)       _CheckVectorIndex (i, Dimension(v))
#define CheckMatrixRowIndex(i,m)    _CheckMatrixRowIndex (i, RowDimension(m))
#define CheckMatrixColIndex(i,m)    _CheckMatrixColIndex (i, ColDimension(m))
#else
#define CheckVectorRange(n)
#define CheckMatrixRange(n,m)
#define CheckVectorIndex(i,v)
#define CheckMatrixRowIndex(i,m)
#define CheckMatrixColIndex(i,m)
#endif
#define CheckMatrixIndex(i,j,m)     CheckMatrixRowIndex(i,m); CheckMatrixColIndex(j,m)

VOID _CheckDimensions (INT, INT);
VOID _CheckMatrixDimensions (INT, INT, INT, INT);
VOID _CheckQuadratic (INT, INT);
VOID _CheckMemory (PVOID);

#ifdef __INDEXCHECK__
VOID _CheckVectorRange (INT);
VOID _CheckMatrixRange (INT, INT);
VOID _CheckVectorIndex (INT, INT);
VOID _CheckMatrixRowIndex (INT, INT);
VOID _CheckMatrixColIndex (INT, INT);
#endif

class ErrorHandler {
public:
  static INT LastErrorCode;
  static INT MaxErrorLevel;
  static INT WarningLevel;
  static INT SevereLevel;
  enum ErrorLevel { FatalError = -1, Ignore = 0, Warning = 1000, SevereError = 2000 };
  ErrorHandler () { }
  ~ErrorHandler () { ErrorReport (0); }
  friend VOID Error (PCHAR, INT, ErrorLevel);
  friend VOID FatalError (PCHAR);
  friend VOID ErrorReport (INT DoReportSucess = 1);
};

#endif /* __ERROR__ */
