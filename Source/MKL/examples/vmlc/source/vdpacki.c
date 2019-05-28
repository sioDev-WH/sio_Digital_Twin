#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  double dA[VEC_LEN],dB1[VEC_LEN];

  int i=0,vec_len=VEC_LEN,incra=3;

  for(i=0;i<vec_len;i++) {
    dA[i]=(double)i+1;
    dB1[i]=0.0;
  }

  vec_len=vec_len/incra+1;
#if defined(MKL_VML_MIXED)
  vdPackI(vec_len,dA,incra,dB1);
#elif defined(MKL_VML_LOWER)
  vdpacki(&vec_len,dA,&incra,dB1);
#elif defined(MKL_VML_UPPER)
  VDPACKI(&vec_len,dA,&incra,dB1);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif


  printf("vdPackI test/example programm\n\n");
  printf("           Before packing             After packing\n");
  printf("===============================================================================\n");
  for(i=0;i<VEC_LEN;i++) {
    printf("% 25.14f ",dA[i]);
    printf("% 25.14f",dB1[i]);
    printf("\n");
  }
}
