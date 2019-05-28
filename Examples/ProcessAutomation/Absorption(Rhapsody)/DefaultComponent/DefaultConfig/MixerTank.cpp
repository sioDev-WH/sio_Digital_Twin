/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: MixerTank
//!	Generated Date	: Sat, 2, Nov 2002  
	File Path	: DefaultComponent\DefaultConfig\MixerTank.cpp
*********************************************************************/

#include "stdafx.h"
#include "MixerTank.h"

//## package Models 

//----------------------------------------------------------------------------
// MixerTank.cpp                                                                  
//----------------------------------------------------------------------------
//## class MixerTank 

// TODO: move these defines to a header file
#define DER_AD(ITEM) _##ITEM##.der_ad 

#ifdef DER
#undef DER
#define DER(ITEM) _##ITEM##.der 
#endif

#ifdef AD
#undef AD
#define AD(ITEM) _##ITEM##.ad 
#endif
// end TODO


MixerTank::MixerTank() : L(1.0), K8(30.7) ,K9(0.5) ,feed_in(NULL) ,recycle_in(NULL) ,gamma(NULL) {
    //#[ operation MixerTank() 
    	feed_in = new double[3];
    	feed_in[0] = 0.0;
    	feed_in[1] = 0.0;
    	feed_in[2] = 0.0;
    	
    	recycle_in = new double[3];
    	recycle_in[0] = 0.0;
    	recycle_in[1] = 0.0;
    	recycle_in[2] = 0.0;
    
    	gamma = new double[3];
    	gamma[0] = 0.0;
    	gamma[1] = 0.0;
    	gamma[2] = 0.0;
    
    //#]
}

MixerTank::~MixerTank() 
{
    //#[ operation ~MixerTank() 
    	DESTROY_VECTOR(feed_in)
    	DESTROY_VECTOR(recycle_in)
    	DESTROY_VECTOR(gamma)
    
    //#]
}


/*****************************************************************************
// begin equations
*****************************************************************************/

HRESULT MixerTank::r_res(long i, double*  res) {
    //#[ operation r_res0(double*) 
    
    *res = - DER(gamma[i]) + K8*(feed_in[i] + K9*recycle_in[i] - (1+K9)*gamma[i]);
    
    return S_OK;
    //#]
}

HRESULT MixerTank::r_res_0(double*  res) 
{
    return r_res(0, res);
}

HRESULT MixerTank::r_res_1(double*  res)
{
    return r_res(1, res);
}

HRESULT MixerTank::r_res_2(double*  res) 
{
    return r_res(2, res);
}

/*****************************************************************************
// end equations
*****************************************************************************/


/*****************************************************************************
// begin AD equations
*****************************************************************************/

HRESULT MixerTank::ad_r_res(long i, Fdouble*  res) {
    //#[ operation ad_r_res0(double*) 
    
    *res = -DER_AD(gamma[i]) + K8*(feed_in[i] + K9*recycle_in[i] - (1+K9) * AD(gamma[i]) );
    
    return S_OK;
    //#]
}

HRESULT MixerTank::ad_r_res_0(Fdouble*  res) 
{
    return ad_r_res(0, res);
}

HRESULT MixerTank::ad_r_res_1(Fdouble*  res)
{
    return ad_r_res(1, res);
}

HRESULT MixerTank::ad_r_res_2(Fdouble*  res) 
{
    return ad_r_res(2, res);
}

/*****************************************************************************
// end AD equations
*****************************************************************************/



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\MixerTank.cpp
*********************************************************************/

//## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
HRESULT MixerTank::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form)
{
  const long idx_eqn_r_res0 = 0;
  const long idx_eqn_r_res1 = 1;
  const long idx_eqn_r_res2 = 2;
  

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_res0] = continuous;
  (*form)[idx_eqn_r_res1] = continuous;
  (*form)[idx_eqn_r_res2] = continuous;


  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_res0] = automatic;
  (*diff_form)[idx_eqn_r_res1] = automatic;
  (*diff_form)[idx_eqn_r_res2] = automatic;

  return S_OK;
}

//## operation InitLocalADEqns() 
HRESULT MixerTank::InitLocalADEqns()
{
  ADD_LOCAL_AD_EQN(MixerTank, ad_r_res_0)
  ADD_LOCAL_AD_EQN(MixerTank, ad_r_res_1)
  ADD_LOCAL_AD_EQN(MixerTank, ad_r_res_2)

  return S_OK;
}

//## operation InitLocalEqns() 
HRESULT MixerTank::InitLocalEqns()
{
  ADD_LOCAL_EQN(MixerTank, r_res_0)
  ADD_LOCAL_EQN(MixerTank, r_res_1)
  ADD_LOCAL_EQN(MixerTank, r_res_2)

  return S_OK;
}

//## operation InitLocalVars(const _TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,const bool) 
HRESULT MixerTank::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  AddLocalVar(gamma, &_gamma, L"gamma", prefix, varC, bADOnly);

  for (long i = 0; i < m_nEsos; i++)
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;

}

//## operation Load(FILE*) 
bool MixerTank::Load(FILE*  fs)
{
  return true;
}

//## operation Save(FILE*) 
void MixerTank::Save(FILE*  fs)
{

}