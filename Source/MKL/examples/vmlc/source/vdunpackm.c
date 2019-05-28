#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  double dA[VEC_LEN],dB1[VEC_LEN],dB2[VEC_LEN];
  int ma[VEC_LEN];

  int i=0,vec_len=VEC_LEN;

  for(i=0;i<vec_len;i++) {
    dA[i]=(double)i+1;
    dB1[i]=0.0;
    dB2[i]=0.0;
    ma[i]=i&1;
  }

  vdPackM(vec_len,dA,ma,dB1);
#if defined(MKL_VML_MIXED)
  vdUnpackM(vec_len,dB1,dB2,ma);
#elif defined(MKL_VML_LOWER)
  vdunpackm(&vec_len,dB1,dB2,ma);
#elif defined(MKL_VML_UPPER)
  VDUNPACKM(&vec_len,dB1,dB2,ma);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif

  printf("vdUnpackM test/example programm\n\n");
  printf("           Before packing             After packing          After Unpacking\n");
  printf("===============================================================================\n");
  for(i=0;i<VEC_LEN;i++) {
    printf("% 25.14f ",dA[i]);
    printf("% 25.14f ",dB1[i]);
    printf("% 25.14f",dB2[i]);
    printf("\n");
  }
}