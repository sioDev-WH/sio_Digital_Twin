#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

void PrintTextVmlMode(int mode);

int main()
{
  int mode;

  printf("vmlSetMode/vmlGetMode example programm\n\n");

#if defined(MKL_VML_MIXED)
  mode=vmlGetMode();
#elif defined(MKL_VML_LOWER)
  mode=vmlgetmode();
#elif defined(MKL_VML_UPPER)
  mode=VMLGETMODE();
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif
  printf("Default value of vmlMode: ");
  PrintTextVmlMode(mode);
  printf(" (0x%x)\n",mode);

  mode=VML_LA|VML_FLOAT_CONSISTENT|VML_ERRMODE_IGNORE;
#if defined(MKL_VML_MIXED)
  vmlSetMode(mode);
#elif defined(MKL_VML_LOWER)
  vmlsetmode(&mode);
#elif defined(MKL_VML_UPPER)
  VMLSETMODE(&mode);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif
  mode=vmlGetMode();
  printf("Value of vmlMode after using vmlSetMode: ");
  PrintTextVmlMode(mode);
  printf(" (0x%x)\n",mode);
}

void PrintTextVmlMode(int mode)
{
  switch(mode&VML_ACCURACY_MASK) {
    case 0x001: {
                printf("VML_LA");
                break;
    }
    case 0x002: {
                printf("VML_HA");
                break;
    }
  }
  switch(mode&VML_FPUMODE_MASK) {
    case 0x000: {
                printf(" | VML_DEFAULT_PRECISION");
                break;
    }
    case 0x010: {
                printf(" | VML_FLOAT_CONSISTENT");
                break;
    }
    case 0x020: {
                printf(" | VML_DOUBLE_CONSISTENT");
                break;
    }
    case 0x030: {
                printf(" | VML_RESTORE");
                break;
    }
  }
  if(mode&VML_ERRMODE_IGNORE) {
    printf(" | VML_ERRMODE_IGNORE");
  }
  else {
    if(mode&VML_ERRMODE_ERRNO) {
      printf(" | VML_ERRMODE_ERRNO");
    }
    if(mode&VML_ERRMODE_STDERR) {
      printf(" | VML_ERRMODE_STDERR");
    }
    if(mode&VML_ERRMODE_EXCEPT) {
      printf(" | VML_ERRMODE_EXCEPT");
    }
    if(mode&VML_ERRMODE_CALLBACK) {
      printf(" | VML_ERRMODE_CALLBACK");
    }
  }
}
