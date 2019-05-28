#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  float fA[VEC_LEN],fB1[VEC_LEN],fB2[VEC_LEN];
  int ia[VEC_LEN];

  int i=0,vec_len=VEC_LEN;

  for(i=0;i<vec_len;i++) {
    fA[i]=(float)i+1;
    fB1[i]=0.0;
    fB2[i]=0.0;
    ia[i]=vec_len-i-1;
  }

  vsPackV(vec_len,fA,ia,fB1);
#if defined(MKL_VML_MIXED)
  vsUnpackV(vec_len,fB1,fB2,ia);
#elif defined(MKL_VML_LOWER)
  vsunpackv(&vec_len,fB1,fB2,ia);
#elif defined(MKL_VML_UPPER)
  VSUNPACKV(&vec_len,fB1,fB2,ia);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif

  printf("vsUnpackV test/example programm\n\n");
  printf("           Before packing             After packing          After Unpacking\n");
  printf("===============================================================================\n");
  for(i=0;i<VEC_LEN;i++) {
    printf("% 25.14f % 25.14f % 25.14f\n",fA[i],fB1[i],fB2[i]);
  }
}
