#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  float fA[VEC_LEN],fB1[VEC_LEN];

  int i=0,vec_len=VEC_LEN;

  for(i=0;i<vec_len;i++) {
    fA[i]=(float)(__VML_SASINH_BEG+((__VML_SASINH_END-__VML_SASINH_BEG)*i)/vec_len);
    fB1[i]=0;
  }

#if defined(MKL_VML_MIXED)
  vsAsinh(vec_len,fA,fB1);
#elif defined(MKL_VML_LOWER)
  vsasinh(&vec_len,fA,fB1);
#elif defined(MKL_VML_UPPER)
  VSASINH(&vec_len,fA,fB1);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif


  printf("vsAsinh test/example programm\n\n");
  printf("           Argument                     vsAsinh\n");
  printf("===============================================================================\n");
  for(i=0;i<vec_len;i++) {
    printf("% 25.14f % 25.14f\n",fA[i],fB1[i]);
  }
}
