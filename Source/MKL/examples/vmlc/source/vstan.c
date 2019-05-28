#include <stdio.h>
#include <math.h>
#include "func_interv.h"

#include "mkl_vml.h"

int main()
{
  float fA[VEC_LEN],fB1[VEC_LEN],fB2[VEC_LEN];

  int i=0,vec_len=VEC_LEN;
  double CurRMS,MaxRMS=0;

  for(i=0;i<vec_len;i++) {
    fA[i]=(float)(__VML_STAN_BEG+((__VML_STAN_END-__VML_STAN_BEG)*i)/vec_len);
    fB1[i]=0;
    fB2[i]=(float)tan(fA[i]);
  }

#if defined(MKL_VML_MIXED)
  vsTan(vec_len,fA,fB1);
#elif defined(MKL_VML_LOWER)
  vstan(&vec_len,fA,fB1);
#elif defined(MKL_VML_UPPER)
  VSTAN(&vec_len,fA,fB1);
#else
# error You must define MKL_VML_CDECL for CDECL call convention or MKL_VML_STDCALL for STDCALL call convention.
#endif


  printf("vsTan test/example programm\n\n");
  printf("           Argument                     vsTan                      Tanf\n");
  printf("===============================================================================\n");
  for(i=0;i<vec_len;i++) {
    printf("% 25.14f % 25.14f % 25.14f\n",fA[i],fB1[i],fB2[i]);
    CurRMS=(fB1[i]-fB2[i])/(0.5*(fB1[i]+fB2[i]));
    if(MaxRMS<CurRMS) MaxRMS=CurRMS;
  }
  printf("\n");
  printf("Maximum relative error: %.2f\n",MaxRMS);
}
