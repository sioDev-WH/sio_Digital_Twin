#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  double dA[VEC_LEN],dB1[VEC_LEN],dB2[VEC_LEN];

  int i=0,vec_len=VEC_LEN;
  double CurRMS,MaxRMS=0;

  for(i=0;i<vec_len;i++) {
    dA[i]=(double)(__VML_DATAN_BEG+((__VML_DATAN_END-__VML_DATAN_BEG)*i)/vec_len);
    dB1[i]=0;
    dB2[i]=atan(dA[i]);
  }

#if defined(MKL_VML_MIXED)
  vdAtan(vec_len,dA,dB1);
#elif defined(MKL_VML_LOWER)
  vdatan(&vec_len,dA,dB1);
#elif defined(MKL_VML_UPPER)
  VDATAN(&vec_len,dA,dB1);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif


  printf("vdAtan test/example programm\n\n");
  printf("           Argument                     vdAtan                      Atan\n");
  printf("===============================================================================\n");
  for(i=0;i<vec_len;i++) {
    printf("% 25.14f % 25.14f % 25.14f\n",dA[i],dB1[i],dB2[i]);
    CurRMS=(dB1[i]-dB2[i])/(0.5*(dB1[i]+dB2[i]));
    if(MaxRMS<CurRMS) MaxRMS=CurRMS;
  }
  printf("\n");
  printf("Maximum relative error: %.2f\n",MaxRMS);
}
