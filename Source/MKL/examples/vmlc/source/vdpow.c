#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  double dA1[VEC_LEN],dA2[VEC_LEN],dB1[VEC_LEN],dB2[VEC_LEN];

  int i=0,vec_len=VEC_LEN;
  double CurRMS,MaxRMS=0;

  for(i=0;i<vec_len;i++) {
    dA1[i]=(double)(__VML_DPOW_BEG+((__VML_DPOW_END-__VML_DPOW_BEG)*i)/vec_len);
    dA2[i]=(double)(__VML_DPOW_BEG+((__VML_DPOW_END-__VML_DPOW_BEG)*i)/vec_len);
    dB1[i]=0;
    dB2[i]=pow(dA1[i],dA2[i]);
  }

#if defined(MKL_VML_MIXED)
  vdPow(vec_len,dA1,dA2,dB1);
#elif defined(MKL_VML_LOWER)
  vdpow(&vec_len,dA1,dA2,dB1);
#elif defined(MKL_VML_UPPER)
  VDPOW(&vec_len,dA1,dA2,dB1);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif


  printf("vdPow test/example programm\n\n");
  printf("           Arguments                    vdPow                      Pow\n");
  printf("===============================================================================\n");
  for(i=0;i<vec_len;i++) {
    printf("% 13.6f % 13.6f % 25.14e % 25.14e\n",dA1[i],dA2[i],dB1[i],dB2[i]);
    CurRMS=(dB1[i]-dB2[i])/(0.5*(dB1[i]+dB2[i]));
    if(MaxRMS<CurRMS) MaxRMS=CurRMS;
  }
  printf("\n");
  printf("Maximum relative error: %.2f\n",MaxRMS);
}
