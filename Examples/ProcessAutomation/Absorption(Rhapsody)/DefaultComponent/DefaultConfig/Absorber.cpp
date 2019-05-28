/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Absorber
//!	Generated Date	: Sat, 2, Nov 2002  
	File Path	: DefaultComponent\DefaultConfig\Absorber.cpp
*********************************************************************/

#include "stdafx.h"
#include "Absorber.h"
#include "GasAbsorber.h"
#include "MixerTank.h"
#include "TubularReactor.h"

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


//## package Models 

//----------------------------------------------------------------------------
// Absorber.cpp                                                                  
//----------------------------------------------------------------------------
//## class Absorber 



Absorber::Absorber() : L(1.0), feed(NULL) {
    pAbsorber = NULL;
    pMixer = NULL;
    pReactor = NULL;
    //#[ operation Absorber() 
    pAbsorber = new GasAbsorber();
    pReactor = new TubularReactor();
    pMixer = new MixerTank();
    
    feed = new double[3];
    feed[0] = 0.0;
    feed[1] = 0.0;
    feed[2] = 0.0;
    
    ad_L = L;
    //#]
}

Absorber::~Absorber() {
    //#[ operation ~Absorber() 
    if (pAbsorber)
    {
      delete pAbsorber;
      pAbsorber = NULL;
    }
    
    if (pReactor)
    {
      delete pReactor;
      pReactor = NULL;
    }
    
    if (pMixer)
    {
      delete pMixer;
      pMixer = NULL;
    }
    
    if (feed)
    {
      delete[] feed;
      feed = NULL;
    }    
    
    //#]
    cleanUpRelations();
}

HRESULT Absorber::r_absorber_feed(long i, double*  res) 
{
    *res = pAbsorber->psi_in[i] - pReactor->phi[i].getVal(&L);
    
    return S_OK;
}

HRESULT Absorber::r_absorber_feed_0(double*  res) 
{
  return r_absorber_feed(0, res);
}

HRESULT Absorber::r_absorber_feed_1(double*  res)
{
  return r_absorber_feed(1, res);
}

HRESULT Absorber::r_absorber_feed_2(double*  res)
{
  return r_absorber_feed(2, res);
}

HRESULT Absorber::r_mixer_feed(long i, double*  res)
{
    *res = pMixer->feed_in[i] - feed[i];
    
    return S_OK;
}

HRESULT Absorber::r_mixer_feed_0(double*  res)
{
  return r_mixer_feed(0, res);
}

HRESULT Absorber::r_mixer_feed_1(double*  res) 
{
  return r_mixer_feed(1, res);
}

HRESULT Absorber::r_mixer_feed_2(double*  res) 
{
  return r_mixer_feed(2, res);
}

HRESULT Absorber::r_mixer_recycle(long i, double*  res)
{
    *res = pMixer->recycle_in[i] - pAbsorber->psi[i].getVal(&L);
    
    return S_OK;
}

HRESULT Absorber::r_mixer_recycle_0(double*  res) 
{
  return r_mixer_recycle(0, res);
}

HRESULT Absorber::r_mixer_recycle_1(double*  res) 
{
  return r_mixer_recycle(1, res);
}

HRESULT Absorber::r_mixer_recycle_2(double*  res) 
{
  return r_mixer_recycle(2, res);
}


HRESULT Absorber::r_reactor_feed(long i, double*  res) 
{
    *res = pReactor->phi_in[i] - pMixer->gamma[i];
    
    return S_OK;
}

HRESULT Absorber::r_reactor_feed_0(double*  res) 
{
  return r_reactor_feed(0, res);
}

HRESULT Absorber::r_reactor_feed_1(double*  res) 
{
  return r_reactor_feed(1, res);
}

HRESULT Absorber::r_reactor_feed_2(double*  res)
{
  return r_reactor_feed(2, res);
}



double* Absorber::getFeed() const {
    return feed;
}

void Absorber::setFeed(double*  p_feed) {
    feed = p_feed;
}

GasAbsorber* Absorber::getPAbsorber() const {
    return pAbsorber;
}

void Absorber::setPAbsorber(GasAbsorber*  p_GasAbsorber) {
    pAbsorber = p_GasAbsorber;
}

MixerTank* Absorber::getPMixer() const {
    return pMixer;
}

void Absorber::setPMixer(MixerTank*  p_MixerTank) {
    pMixer = p_MixerTank;
}

TubularReactor* Absorber::getPReactor() const {
    return pReactor;
}

void Absorber::setPReactor(TubularReactor*  p_TubularReactor) {
    pReactor = p_TubularReactor;
}

void Absorber::cleanUpRelations() {
    if(pAbsorber != NULL)
        {
            pAbsorber = NULL;
        }
    if(pMixer != NULL)
        {
            pMixer = NULL;
        }
    if(pReactor != NULL)
        {
            pReactor = NULL;
        }
}






/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Absorber.cpp
*********************************************************************/

//## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
HRESULT Absorber::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form)
{
  const long idx_eqn_r_absorber_feed0 = 0;
  const long idx_eqn_r_absorber_feed1 = 1;
  const long idx_eqn_r_absorber_feed2 = 2;
  const long idx_eqn_r_mixer_feed0 = 3;
  const long idx_eqn_r_mixer_feed1 = 4;
  const long idx_eqn_r_mixer_feed2 = 5;
  const long idx_eqn_r_mixer_recycle0 = 6;
  const long idx_eqn_r_mixer_recycle1 = 7;
  const long idx_eqn_r_mixer_recycle2 = 8;
  const long idx_eqn_r_reactor_feed0 = 9;
  const long idx_eqn_r_reactor_feed1 = 10;
  const long idx_eqn_r_reactor_feed2 = 11;
  

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_absorber_feed0] = continuous;
  (*form)[idx_eqn_r_absorber_feed1] = continuous;
  (*form)[idx_eqn_r_absorber_feed2] = continuous;
  (*form)[idx_eqn_r_mixer_feed0] = continuous;
  (*form)[idx_eqn_r_mixer_feed1] = continuous;
  (*form)[idx_eqn_r_mixer_feed2] = continuous;
  (*form)[idx_eqn_r_mixer_recycle0] = continuous;
  (*form)[idx_eqn_r_mixer_recycle1] = continuous;
  (*form)[idx_eqn_r_mixer_recycle2] = continuous;
  (*form)[idx_eqn_r_reactor_feed0] = continuous;
  (*form)[idx_eqn_r_reactor_feed1] = continuous;
  (*form)[idx_eqn_r_reactor_feed2] = continuous;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_absorber_feed0] = automatic;
  (*diff_form)[idx_eqn_r_absorber_feed1] = automatic;
  (*diff_form)[idx_eqn_r_absorber_feed2] = automatic;
  (*diff_form)[idx_eqn_r_mixer_feed0] = automatic;
  (*diff_form)[idx_eqn_r_mixer_feed1] = automatic;
  (*diff_form)[idx_eqn_r_mixer_feed2] = automatic;
  (*diff_form)[idx_eqn_r_mixer_recycle0] = automatic;
  (*diff_form)[idx_eqn_r_mixer_recycle1] = automatic;
  (*diff_form)[idx_eqn_r_mixer_recycle2] = automatic;
  (*diff_form)[idx_eqn_r_reactor_feed0] = automatic;
  (*diff_form)[idx_eqn_r_reactor_feed1] = automatic;
  (*diff_form)[idx_eqn_r_reactor_feed2] = automatic;

  return S_OK;
}

//## operation InitLocalADEqns() 
HRESULT Absorber::InitLocalADEqns()
{
  ADD_LOCAL_AD_EQN(Absorber, ad_r_absorber_feed_0)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_absorber_feed_1)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_absorber_feed_2)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_mixer_feed_0)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_mixer_feed_1)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_mixer_feed_2)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_mixer_recycle_0)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_mixer_recycle_1)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_mixer_recycle_2)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_reactor_feed_0)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_reactor_feed_1)
  ADD_LOCAL_AD_EQN(Absorber, ad_r_reactor_feed_2)
    
  return S_OK;
}

//## operation InitLocalEqns() 
HRESULT Absorber::InitLocalEqns()
{
  ADD_LOCAL_EQN(Absorber, r_absorber_feed_0)
  ADD_LOCAL_EQN(Absorber, r_absorber_feed_1)
  ADD_LOCAL_EQN(Absorber, r_absorber_feed_2)
  ADD_LOCAL_EQN(Absorber, r_mixer_feed_0)
  ADD_LOCAL_EQN(Absorber, r_mixer_feed_1)
  ADD_LOCAL_EQN(Absorber, r_mixer_feed_2)
  ADD_LOCAL_EQN(Absorber, r_mixer_recycle_0)
  ADD_LOCAL_EQN(Absorber, r_mixer_recycle_1)
  ADD_LOCAL_EQN(Absorber, r_mixer_recycle_2)
  ADD_LOCAL_EQN(Absorber, r_reactor_feed_0)
  ADD_LOCAL_EQN(Absorber, r_reactor_feed_1)
  ADD_LOCAL_EQN(Absorber, r_reactor_feed_2)
    
  return S_OK;
}

//## operation InitLocalVars(const _TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,const bool) 
HRESULT Absorber::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
}

//## operation Load(FILE*) 
bool Absorber::Load(FILE*  fs)
{
  return true;
}

//## operation Save(FILE*) 
void Absorber::Save(FILE*  fs)
{

}

HRESULT Absorber::ad_r_absorber_feed(long i, Fdouble*  res)
{
  *res = pAbsorber->psi_in[i] - pReactor->AD(phi[i]).getVal(&ad_L);
  
  return S_OK;
}

HRESULT Absorber::ad_r_absorber_feed_0(Fdouble*  res)
{
  return ad_r_absorber_feed(0, res);
}

//## operation r_absorber_feed1(Fdouble*) 
HRESULT Absorber::ad_r_absorber_feed_1(Fdouble*  res)
{
  return ad_r_absorber_feed(1, res);
}

//## operation r_absorber_feed2(Fdouble*) 
HRESULT Absorber::ad_r_absorber_feed_2(Fdouble*  res)
{
  return ad_r_absorber_feed(2, res);
}

HRESULT Absorber::ad_r_mixer_feed(long i, Fdouble*  res)
{
    *res = pMixer->feed_in[i] - feed[i];
    
    return S_OK;
}

//## operation r_mixer_feed0(Fdouble*) 
HRESULT Absorber::ad_r_mixer_feed_0(Fdouble*  res)
{
    return ad_r_mixer_feed(0, res);
}

//## operation r_mixer_feed1(Fdouble*) 
HRESULT Absorber::ad_r_mixer_feed_1(Fdouble*  res)
{
    return ad_r_mixer_feed(1, res);
}

//## operation r_mixer_feed2(Fdouble*) 
HRESULT Absorber::ad_r_mixer_feed_2(Fdouble*  res)
{
    return ad_r_mixer_feed(2, res);
}

HRESULT Absorber::ad_r_mixer_recycle(long i, Fdouble*  res)
{
  *res = pMixer->recycle_in[i] - pAbsorber->AD(psi[i]).getVal(&ad_L);
    
  return S_OK;
}

//## operation r_mixer_recycle0(Fdouble*) 
HRESULT Absorber::ad_r_mixer_recycle_0(Fdouble*  res)
{
  return ad_r_mixer_recycle(0, res);
}

//## operation r_mixer_recycle1(Fdouble*) 
HRESULT Absorber::ad_r_mixer_recycle_1(Fdouble*  res)
{
  return ad_r_mixer_recycle(1, res);
}

//## operation r_mixer_recycle2(Fdouble*) 
HRESULT Absorber::ad_r_mixer_recycle_2(Fdouble*  res)
{
  return ad_r_mixer_recycle(2, res);
}

HRESULT Absorber::ad_r_reactor_feed(long i, Fdouble*  res)
{
    *res = pReactor->phi_in[i] - pMixer->AD(gamma[i]);
    
    return S_OK;
}

//## operation r_reactor_feed0(Fdouble*) 
HRESULT Absorber::ad_r_reactor_feed_0(Fdouble*  res)
{
  return ad_r_reactor_feed(0, res);
}

//## operation r_reactor_feed1(Fdouble*) 
HRESULT Absorber::ad_r_reactor_feed_1(Fdouble*  res)
{
  return ad_r_reactor_feed(1, res);
}

//## operation r_reactor_feed2(Fdouble*) 
HRESULT Absorber::ad_r_reactor_feed_2(Fdouble*  res)
{
  return ad_r_reactor_feed(2, res);
}
