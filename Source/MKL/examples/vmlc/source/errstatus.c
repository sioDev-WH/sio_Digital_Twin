#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

void PrintTextVmlErrStatus(int );

int main()
{
  int errst;

  printf("vmlSetErrStatus/vmlGetErrStatus/vmlClearErrStatus example programm\n\n");

#if defined(MKL_VML_MIXED)
  errst=vmlGetErrStatus();
#elif defined(MKL_VML_LOWER)
  errst=vmlgeterrstatus();
#elif defined(MKL_VML_UPPER)
  errst=VMLGETERRSTATUS();
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif

  printf("Initial value of vmlErrStatus: ");
  PrintTextVmlErrStatus(errst);
  printf(" (0x%x)\n",errst);

  errst=VML_STATUS_BADMEM;
#if defined(MKL_VML_MIXED)
  vmlSetErrStatus(errst);
#elif defined(MKL_VML_LOWER)
  vmlseterrstatus(&errst);
#elif defined(MKL_VML_UPPER)
  VMLSETERRSTATUS(&errst);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif
  errst=vmlGetErrStatus();
  printf("Value of vmlErrStatus after using vmlSetErrStatus: ");
  PrintTextVmlErrStatus(errst);
  printf(" (0x%x)\n",errst);

#if defined(MKL_VML_MIXED)
  vmlClearErrStatus();
#elif defined(MKL_VML_LOWER)
  vmlclearerrstatus();
#elif defined(MKL_VML_UPPER)
  VMLCLEARERRSTATUS();
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif
  errst=vmlGetErrStatus();
  printf("Value of vmlErrStatus after using vmlClearErrStatus: ");
  PrintTextVmlErrStatus(errst);
  printf(" (0x%x)\n",errst);
}

void PrintTextVmlErrStatus(int errst)
{
  switch(errst) {
    case VML_STATUS_OK: {
                printf("VML_STATUS_OK");
                break;
    }
    case VML_STATUS_BADSIZE: {
                printf("VML_STATUS_BADSIZE");
                break;
    }
    case VML_STATUS_BADMEM: {
                printf("VML_STATUS_BADMEM");
                break;
    }
    case VML_STATUS_ERRDOM: {
                printf("VML_STATUS_ERRDOM");
                break;
    }
    case VML_STATUS_SING: {
                printf("VML_STATUS_SING");
                break;
    }
    case VML_STATUS_OVERFLOW: {
                printf("VML_STATUS_OVERFLOW");
                break;
    }
    case VML_STATUS_UNDERFLOW: {
                printf("VML_STATUS_UNDERFLOW");
                break;
    }
  }
}
