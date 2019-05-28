/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GasAbsorber
//!	Generated Date	: Sat, 2, Nov 2002  
	File Path	: DefaultComponent\DefaultConfig\GasAbsorber.cpp
*********************************************************************/

#include "stdafx.h"
#include "GasAbsorber.h"

//## package Models 

//----------------------------------------------------------------------------
// GasAbsorber.cpp                                                                  
//----------------------------------------------------------------------------
//## class GasAbsorber 

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

GasAbsorber::GasAbsorber() : Len(1.0), K3(0.1) ,K4(20.0) ,K5(10.0) ,K6(0.003) ,K7(75.0) ,psi_in(NULL) ,
                             theta_in(0.0) ,BCG0(NULL) ,MBG(NULL) ,psi(NULL) ,psi_BC0(NULL) ,psi_MB(NULL)
                             
{
    //#[ operation GasAbsorber() 
      long i;

      ForwardMesh.init(BFDM,1,40);
      ReverseMesh.init(CFDM,2,40);
      Forward.init("Forward",0,Len,false,false);
      Reverse.init("Reverse",0,Len,false,false);
    	Forward.setMesh(ForwardMesh);
    	Reverse.setMesh(ReverseMesh);

      gasConc.init(" ","kmol/m^3",1,&Forward);
      theta.init("Liquid Phase","kmol/m^3",1,&Reverse);
  
    	psi_in = new double[3];
    	psi_in[0] = 0.0;
    	psi_in[1] = 0.0;
    	psi_in[2] = 0.0;
    	
    
    	// ***** Variables ******
    	psi = new DistributedVar[3];

    	for(i=0;i<3;i++)
      {
        psi[i].init(gasConc);
      }
      _psi.init(psi, 3);

    	psi_BC0 = new DistributedVar[3];
    	psi_MB = new DistributedVar[3];
    	for(i=0;i<3;i++)
    	{
    		psi_BC0[i] = psi[i] | (Forward|0);    // for Gas Boundary condition at zeta=0
        psi_BC0[i].setParent(psi[i]);
    		psi_MB[i] = psi[i] | ((Forward - 0)); // for Gas Phase Mass Balance equation
        psi_MB[i].setParent(psi[i]);
    	}
    	_psi_BC0.init(psi_BC0, 3);
      _psi_MB.init(psi_MB, 3);
      _psi_BC0.setParent(_psi);
      _psi_MB.setParent(_psi);

    	psi_MBL = psi[2] | (Forward - Len);       // may require interpolation
    	_psi_MBL.init(psi_MBL);
      _psi_MBL.setParent(_psi[2]);

      _theta.init(theta);
      theta_MBG = theta | (Reverse - 0);      // may require interpolation if grid points are not matching
    	theta_BCL = theta | (Reverse|Len);        // for Boundary condition at zeta=Len=1.0
    	theta_MBL = theta | (Reverse - Len);      // for Liquid Phase Mass Balance equation
    	theta_MBG.setParent(theta);
      theta_BCL.setParent(theta);
      theta_MBL.setParent(theta);
      
      _theta_MBG.init(theta_MBG);
      _theta_BCL.init(theta_BCL);
      _theta_MBL.init(theta_MBL);
    	_theta_MBG.setParent(_theta);
      _theta_BCL.setParent(_theta);
      _theta_MBL.setParent(_theta);

    	// ***** Equations *******
    	BCG0 = new DistributedVar[3];
    	MBG = new DistributedVar[3];
    	_BCG0.init(BCG0, 3);
    	_MBG.init(BCG0, 3);

      _BCLL.init(BCLL);
      _MBL.init(MBL);
    
    //#]
}

GasAbsorber::~GasAbsorber() {
    //#[ operation ~GasAbsorber() 
    	DESTROY_VECTOR(psi_in)

      // ***** Variables ******
    	DESTROY_VECTOR(psi)
    	DESTROY_VECTOR(psi_BC0)
    	DESTROY_VECTOR(psi_MB)
    	  
     	// ***** Equations *******
    	DESTROY_VECTOR(BCG0)
    	DESTROY_VECTOR(MBG)
    
    //#]
}



/******************************************************************************
// begin of equations
******************************************************************************/

HRESULT GasAbsorber::r_BCG0(long i) {
    //#[ operation r_BCG0() 
    	// Boundary condition at zeta=0
  	  BCG0[i] = psi_BC0[i] -  psi_in[i];	  
    	       
      return S_OK;
    
    //#]
}

HRESULT GasAbsorber::r_BCG0_0() 
{
      return r_BCG0(0);
}

HRESULT GasAbsorber::r_BCG0_1()
{
      return r_BCG0(1);
}

HRESULT GasAbsorber::r_BCG0_2()
{
      return r_BCG0(2);
}

HRESULT GasAbsorber::r_BCLL() 
{
    //#[ operation r_BCLL() 
    	// Boundary condition liquid phase at zeta=Len=1.0
    	BCLL = theta_BCL - theta_in; // theta_in = 0 all time
    
      return S_OK;
    //#]
}


HRESULT GasAbsorber::r_MBG(long i)
{
    //#[ operation r_MBG() 
    	// Mass Balance equation (gas phase inside the absorber)
    	MBG[i] = - DER(psi_MB[i]) - K3 * psi_MB[i].PARTIAL(Forward);
    
      return S_OK;
    //#]
}

HRESULT GasAbsorber::r_MBG_0() 
{
      return r_MBG(0);
}

HRESULT GasAbsorber::r_MBG_1()
{
      return r_MBG(1);
}

HRESULT GasAbsorber::r_MBG_2()
{
      return r_MBG(2);
}

HRESULT GasAbsorber::r_MBL() {
    //#[ operation r_MBL() 
    	MBL = - DER(theta_MBL) + K6 * theta_MBL.PARTIAL(Reverse)
    			 + (K4/K7) * (psi_MBL - K5 * theta_MBG);
    
        return S_OK;
    
    //#]
}

/******************************************************************************
// end of equations
******************************************************************************/



/******************************************************************************
// begin of AD equations
******************************************************************************/

HRESULT GasAbsorber::ad_r_BCG0(long i) 
{
    //#[ operation ad_r_BCG0() 
    	// Boundary condition at zeta=0
  	  AD(BCG0[i]) = AD(psi_BC0[i]) -  psi_in[i];	  
    	       
      return S_OK;
    
    //#]
}

HRESULT GasAbsorber::ad_r_BCG0_0() 
{
      return ad_r_BCG0(0);
}

HRESULT GasAbsorber::ad_r_BCG0_1()
{
      return ad_r_BCG0(1);
}

HRESULT GasAbsorber::ad_r_BCG0_2()
{
      return ad_r_BCG0(2);
}

HRESULT GasAbsorber::ad_r_BCLL() 
{
    //#[ operation ad_r_BCLL() 
    	// Boundary condition liquid phase at zeta=Len=1.0
    	AD(BCLL) = AD(theta_BCL) - theta_in; // theta_in = 0 all time
    
      return S_OK;
    //#]
}


HRESULT GasAbsorber::ad_r_MBG(long i)
{
    //#[ operation ad_r_MBG() 
    	// Mass Balance equation (gas phase inside the absorber)
    	AD(MBG[i]) = - DER_AD(psi_MB[i]) - K3 * AD(psi_MB[i]).PARTIAL(Forward);
    
      return S_OK;
    //#]
}

HRESULT GasAbsorber::ad_r_MBG_0() 
{
      return ad_r_MBG(0);
}

HRESULT GasAbsorber::ad_r_MBG_1()
{
      return ad_r_MBG(1);
}

HRESULT GasAbsorber::ad_r_MBG_2()
{
      return ad_r_MBG(2);
}

HRESULT GasAbsorber::ad_r_MBL() {
    //#[ operation ad_r_MBL() 
    	AD(MBL) = - DER_AD(theta_MBL) + K6 * AD(theta_MBL).PARTIAL(Reverse)
    			 + (K4/K7) * (AD(psi_MBL) - K5 * AD(theta_MBG));
    
        return S_OK;
    
    //#]
}

/******************************************************************************
// end of AD equations
******************************************************************************/













/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GasAbsorber.cpp
*********************************************************************/

//## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
HRESULT GasAbsorber::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form)
{
  const long idx_eqn_r_BCG0_0 = 0;
  const long idx_eqn_r_BCG0_1 = 1;
  const long idx_eqn_r_BCG0_2 = 2;
  const long idx_eqn_r_BCLL = 3;
  const long idx_eqn_r_MBG_0 = 4;
  const long idx_eqn_r_MBG_1 = 5;
  const long idx_eqn_r_MBG_2 = 6;
  const long idx_eqn_r_MBL = 7;
  

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_BCG0_0] = continuous;
  (*form)[idx_eqn_r_BCG0_1] = continuous;
  (*form)[idx_eqn_r_BCG0_2] = continuous;
  (*form)[idx_eqn_r_BCLL] = continuous;
  (*form)[idx_eqn_r_MBG_0] = continuous;
  (*form)[idx_eqn_r_MBG_1] = continuous;
  (*form)[idx_eqn_r_MBG_2] = continuous;
  (*form)[idx_eqn_r_MBL] = continuous;


  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_BCG0_0] = automatic;
  (*diff_form)[idx_eqn_r_BCG0_1] = automatic;
  (*diff_form)[idx_eqn_r_BCG0_2] = automatic;
  (*diff_form)[idx_eqn_r_BCLL] = automatic;
  (*diff_form)[idx_eqn_r_MBG_0] = automatic;
  (*diff_form)[idx_eqn_r_MBG_1] = automatic;
  (*diff_form)[idx_eqn_r_MBG_2] = automatic;
  (*diff_form)[idx_eqn_r_MBL] = automatic;

  return S_OK;
}

//## operation InitLocalADEqns() 
HRESULT GasAbsorber::InitLocalADEqns()
{
  ADD_LOCAL_DIST_AD_EQN(GasAbsorber, ad_r_BCG0_0, AD(BCG0[0]))
  ADD_LOCAL_DIST_AD_EQN(GasAbsorber, ad_r_BCG0_1, AD(BCG0[1]))
  ADD_LOCAL_DIST_AD_EQN(GasAbsorber, ad_r_BCG0_2, AD(BCG0[2]))
  ADD_LOCAL_DIST_AD_EQN(GasAbsorber, ad_r_BCLL, AD(BCLL))
  ADD_LOCAL_DIST_AD_EQN(GasAbsorber, ad_r_MBG_0, AD(MBG[0]))
  ADD_LOCAL_DIST_AD_EQN(GasAbsorber, ad_r_MBG_1, AD(MBG[1]))
  ADD_LOCAL_DIST_AD_EQN(GasAbsorber, ad_r_MBG_2, AD(MBG[2]))
  ADD_LOCAL_DIST_AD_EQN(GasAbsorber, ad_r_MBL, AD(MBL))
    
  return S_OK;
}

//## operation InitLocalEqns() 
HRESULT GasAbsorber::InitLocalEqns()
{
  ADD_LOCAL_DIST_EQN(GasAbsorber, r_BCG0_0, BCG0[0])
  ADD_LOCAL_DIST_EQN(GasAbsorber, r_BCG0_1, BCG0[1])
  ADD_LOCAL_DIST_EQN(GasAbsorber, r_BCG0_2, BCG0[2])
  ADD_LOCAL_DIST_EQN(GasAbsorber, r_BCLL, BCLL)
  ADD_LOCAL_DIST_EQN(GasAbsorber, r_MBG_0, MBG[0])
  ADD_LOCAL_DIST_EQN(GasAbsorber, r_MBG_1, MBG[1])
  ADD_LOCAL_DIST_EQN(GasAbsorber, r_MBG_2, MBG[2])
  ADD_LOCAL_DIST_EQN(GasAbsorber, r_MBL, MBL)
    
  return S_OK;
}

//## operation InitLocalVars(const _TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,const bool) 
HRESULT GasAbsorber::InitLocalVars(const _TCHAR*  prefix, VarCont* varC, const bool  bADOnly)
{
  AddLocalVar(&psi, &_psi, L"psi", prefix, varC, bADOnly);
  AddLocalVar(&theta, &_theta, L"theta", prefix, varC, bADOnly);

  for (long i = 0; i < m_nEsos; i++)
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}

//## operation Load(FILE*) 
bool GasAbsorber::Load(FILE*  fs)
{
  return true;
}

//## operation Save(FILE*) 
void GasAbsorber::Save(FILE*  fs)
{

}