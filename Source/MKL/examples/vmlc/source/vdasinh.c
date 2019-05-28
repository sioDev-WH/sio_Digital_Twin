#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  double dA[VEC_LEN],dB1[VEC_LEN];

  int i=0,vec_len=VEC_LEN;

  for(i=0;i<vec_len;i++) {
    dA[i]=(double)(__VML_DASINH_BEG+((__VML_DASINH_END-__VML_DASINH_BEG)*i)/vec_len);
    dB1[i]=0;
  }

#if defined(MKL_VML_MIXED)
  vdAsinh(vec_len,dA,dB1);
#elif defined(MKL_VML_LOWER)
  vdasinh(&vec_len,dA,dB1);
#elif defined(MKL_VML_UPPER)
  VDASINH(&vec_len,dA,dB1);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif


  printf("vdAcosh test/example programm\n\n");
  printf("           Argument                     vdAcosh\n");
  printf("===============================================================================\n");
  for(i=0;i<vec_len;i++) {
    printf("% 25.14f % 25.14f\n",dA[i],dB1[i]);
  }
}
