#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  float fA[VEC_LEN],fB1[VEC_LEN],fB2[VEC_LEN];
  int ma[VEC_LEN];

  int i=0,vec_len=VEC_LEN;

  for(i=0;i<vec_len;i++) {
    fA[i]=(float)i+1;
    fB1[i]=0.0;
    fB2[i]=0.0;
    ma[i]=i&1;
  }

  vsPackM(vec_len,fA,ma,fB1);
#if defined(MKL_VML_MIXED)
  vsUnpackM(vec_len,fB1,fB2,ma);
#elif defined(MKL_VML_LOWER)
  vsunpackm(&vec_len,fB1,fB2,ma);
#elif defined(MKL_VML_UPPER)
  VSUNPACKM(&vec_len,fB1,fB2,ma);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif

  printf("vsUnpackM test/example programm\n\n");
  printf("           Before packing             After packing          After Unpacking\n");
  printf("===============================================================================\n");
  for(i=0;i<VEC_LEN;i++) {
    printf("% 25.14f ",fA[i]);
    printf("% 25.14f ",fB1[i]);
    printf("% 25.14f",fB2[i]);
    printf("\n");
  }
}
