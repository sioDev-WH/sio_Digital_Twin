// OnDaeCOSolverTypeDefs.h
// type definitions for the IsDaeCOSolver library

#ifndef _ONDAECOSOLVERTYPEDEFS_H_
#define _ONDAECOSOLVERTYPEDEFS_H_

#ifndef _CalcMethod_
#define _CalcMethod_
typedef enum CalcMethod
{
	jcm_nc,
	jcm_ad,
	jcm_num,
	jcm_sym,
	jcm_const,
};
#endif // _CalcMethod_


#ifndef _ON_EQN_FORM_
#define _ON_EQN_FORM_
typedef enum OnEqnForm
{
  continuous,
  discontinuous,
  reset,
};
#endif // _ON_EQN_FORM_


typedef enum OnEqnDiffForm
{
  numeric,
  automatic,
  symbolic,
};

#endif // _ONDAECOSOLVERTYPEDEFS_H_