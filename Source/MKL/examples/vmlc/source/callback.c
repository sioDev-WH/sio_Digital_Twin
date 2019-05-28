#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int __stdcall StubCallBack(DefVmlErrorContext* pdefVmlErrorContext)
{
  return 0;
}

int main()
{
  VMLErrorCallBack errcb;

  printf("vmlSetErrorCallBack/vmlGetErrorCallBack/vmlClearErrorCallBack example programm\n\n");

#if defined(MKL_VML_MIXED)
  errcb=vmlGetErrorCallBack();
#elif defined(MKL_VML_LOWER)
  errcb=vmlgeterrorcallback();
#elif defined(MKL_VML_UPPER)
  errcb=VMLGETERRORCALLBACK();
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif
  printf("Initial address of CallBack function: 0x%X%X\n",errcb);

  errcb=StubCallBack;
#if defined(MKL_VML_MIXED)
  vmlSetErrorCallBack(errcb);
#elif defined(MKL_VML_LOWER)
  vmlseterrorcallback(errcb);
#elif defined(MKL_VML_UPPER)
  VMLSETERRORCALLBACK(errcb);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif
  errcb=vmlGetErrorCallBack();
  printf("Address of CallBack function after using vmlSetErrorCallBack: 0x%X%X\n",errcb);

#if defined(MKL_VML_MIXED)
  vmlClearErrorCallBack();
#elif defined(MKL_VML_LOWER)
  vmlclearerrorcallback();
#elif defined(MKL_VML_UPPER)
  VMLCLEARERRORCALLBACK();
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif
  errcb=vmlGetErrorCallBack();
  printf("Address of CallBack function after using vmlClearErrorCallBack: 0x%X%X\n",errcb);
}
