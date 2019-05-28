#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  float fA1[VEC_LEN],fA2[VEC_LEN],fB1[VEC_LEN],fB2[VEC_LEN];

  int i=0,vec_len=VEC_LEN;
  double CurRMS,MaxRMS=0;

  for(i=0;i<vec_len;i++) {
    fA1[i]=(float)(__VML_SPOW_BEG+((__VML_SPOW_END-__VML_SPOW_BEG)*i)/vec_len);
    fA2[i]=(float)(__VML_SPOW_BEG+((__VML_SPOW_END-__VML_SPOW_BEG)*i)/vec_len);
    fB1[i]=0;
    fB2[i]=(float)pow(fA1[i],fA2[i]);
  }

#if defined(MKL_VML_MIXED)
  vsPow(vec_len,fA1,fA2,fB1);
#elif defined(MKL_VML_LOWER)
  vspow(&vec_len,fA1,fA2,fB1);
#elif defined(MKL_VML_UPPER)
  VSPOW(&vec_len,fA1,fA2,fB1);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif


  printf("vsPow test/example programm\n\n");
  printf("           Argument                     vsPow                      Powf\n");
  printf("===============================================================================\n");
  for(i=0;i<vec_len;i++) {
    printf("% 13.6f % 13.6f % 25.14e % 25.14e\n",fA1[i],fA2[i],fB1[i],fB2[i]);
    CurRMS=(fB1[i]-fB2[i])/(0.5*(fB1[i]+fB2[i]));
    if(MaxRMS<CurRMS) MaxRMS=CurRMS;
  }
  printf("\n");
  printf("Maximum relative error: %.2f\n",MaxRMS);
}
