#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  double dA1[VEC_LEN],dB1[VEC_LEN],dB2[VEC_LEN],dB3[VEC_LEN],dB4[VEC_LEN];

  int i=0,vec_len=VEC_LEN;
  double CurRMS,MaxRMSsin=0,MaxRMScos=0;

  for(i=0;i<vec_len;i++) {
    dA1[i]=(double)(__VML_DSINCOS_BEG+((__VML_DSINCOS_END-__VML_DSINCOS_BEG)*i)/vec_len);
    dB1[i]=0;
    dB2[i]=0;
    dB3[i]=sin(dA1[i]);
    dB4[i]=cos(dA1[i]);
  }

#if defined(MKL_VML_MIXED)
  vdSinCos(vec_len,dA1,dB1,dB2);
#elif defined(MKL_VML_LOWER)
  vdsincos(&vec_len,dA1,dB1,dB2);
#elif defined(MKL_VML_UPPER)
  VDSINCOS(&vec_len,dA1,dB1,dB2);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif


  printf("vdSinCos test/example programm\n\n");
  printf("        Argument         vdSinCos:   Sin        Cos           Sin        Cos\n");
  printf("===============================================================================\n");
  for(i=0;i<vec_len;i++) {
    printf("% 22.14f % 20.6f % 10.6f % 13.6f % 10.6f\n",dA1[i],dB1[i],dB2[i],dB3[i],dB4[i]);
    CurRMS=(dB1[i]-dB3[i])/(0.5*(dB1[i]+dB3[i]));
    if(MaxRMSsin<CurRMS) MaxRMSsin=CurRMS;
    CurRMS=(dB2[i]-dB4[i])/(0.5*(dB2[i]+dB4[i]));
    if(MaxRMScos<CurRMS) MaxRMScos=CurRMS;
  }
  printf("\n");
  printf("Maximum relative error (sin): %.2f\n",MaxRMSsin);
  printf("Maximum relative error (cos): %.2f\n",MaxRMScos);
}
