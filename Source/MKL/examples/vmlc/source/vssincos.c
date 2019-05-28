#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  float fA1[VEC_LEN],fB1[VEC_LEN],fB2[VEC_LEN],fB3[VEC_LEN],fB4[VEC_LEN];

  int i=0,vec_len=VEC_LEN;
  double CurRMS,MaxRMSsin=0,MaxRMScos=0;

  for(i=0;i<vec_len;i++) {
    fA1[i]=(float)(__VML_SSINCOS_BEG+((__VML_SSINCOS_END-__VML_SSINCOS_BEG)*i)/vec_len);
    fB1[i]=0;
    fB2[i]=0;
    fB3[i]=(float)sin(fA1[i]);
    fB4[i]=(float)cos(fA1[i]);
  }

#if defined(MKL_VML_MIXED)
  vsSinCos(vec_len,fA1,fB1,fB2);
#elif defined(MKL_VML_LOWER)
  vssincos(&vec_len,fA1,fB1,fB2);
#elif defined(MKL_VML_UPPER)
  VSSINCOS(&vec_len,fA1,fB1,fB2);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif


  printf("vsSinCos test/example programm\n\n");
  printf("        Argument         vsSinCos:   Sin        Cos           Sin        Cos\n");
  printf("===============================================================================\n");
  for(i=0;i<vec_len;i++) {
    printf("% 22.14f % 20.6f % 10.6f % 13.6f % 10.6f\n",fA1[i],fB1[i],fB2[i],fB3[i],fB4[i]);
    CurRMS=(fB1[i]-fB3[i])/(0.5*(fB1[i]+fB3[i]));
    if(MaxRMSsin<CurRMS) MaxRMSsin=CurRMS;
    CurRMS=(fB2[i]-fB4[i])/(0.5*(fB2[i]+fB4[i]));
    if(MaxRMScos<CurRMS) MaxRMScos=CurRMS;
  }
  printf("\n");
  printf("Maximum relative error (sin): %.2f\n",MaxRMSsin);
  printf("Maximum relative error (cos): %.2f\n",MaxRMScos);
}
