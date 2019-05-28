#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  float fA[VEC_LEN],fB1[VEC_LEN],fB2[VEC_LEN];

  int i=0,vec_len=VEC_LEN,incra=3;

  for(i=0;i<vec_len;i++) {
    fA[i]=(float)i+1;
    fB1[i]=0.0;
    fB2[i]=0.0;
  }

  vec_len=vec_len/incra+1;
  vsPackI(vec_len,fA,incra,fB1);
#if defined(MKL_VML_MIXED)
  vsUnpackI(vec_len,fB1,fB2,incra);
#elif defined(MKL_VML_LOWER)
  vsunpacki(&vec_len,fB1,fB2,&incra);
#elif defined(MKL_VML_UPPER)
  VSUNPACKI(&vec_len,fB1,fB2,&incra);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif

  printf("vsUnpackI test/example programm\n\n");
  printf("           Before packing             After packing          After Unpacking\n");
  printf("===============================================================================\n");
  for(i=0;i<VEC_LEN;i++) {
    printf("% 25.14f ",fA[i]);
    printf("% 25.14f ",fB1[i]);
    printf("% 25.14f",fB2[i]);
    printf("\n");
  }
}
