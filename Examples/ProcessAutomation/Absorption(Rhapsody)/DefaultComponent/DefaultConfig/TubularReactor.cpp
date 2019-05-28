/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TubularReactor
//!	Generated Date	: Sat, 2, Nov 2002  
	File Path	: DefaultComponent\DefaultConfig\TubularReactor.cpp
*********************************************************************/

#include "stdafx.h"
#include "TubularReactor.h"

//## package Models 

//----------------------------------------------------------------------------
// TubularReactor.cpp                                                                  
//----------------------------------------------------------------------------
//## class TubularReactor 

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

TubularReactor::TubularReactor() : 
  Len(1.0) ,K1(0.1) ,K2(3.0) ,phi_in(NULL) ,nu(NULL),
  BC0(NULL) ,BCL(NULL) ,MB(NULL) ,
  phi(NULL) ,phi_BC0(NULL) ,phi_BCL(NULL) ,phi_MB(NULL)
{
    //#[ operation TubularReactor() 
    	long i;
  
      Mesh.init(OCFEM, 3, 15);
      Axial.init("Axial", 0, Len, false, false);
    	Axial.setMesh(Mesh);
      conc.init("C", "kmol/m^3", 1, &Axial);

      phi_in = new double[3];
    	phi_in[0] = 0.0;
    	phi_in[1] = 0.0;
    	phi_in[2] = 0.0;
    	
    	nu = new double[3];
    	nu[0] = -1.0;
    	nu[1] = -1.0;
    	nu[2] = +2.0;
    	
    
      phi = new DistributedVar[3];
    	for(i=0;i<3;i++)
    	  phi[i].init(conc); // set names to A,B and C

      _phi.init(phi, 3);

    	phi_BC0 = new DistributedVar[3];
    	phi_MB = new DistributedVar[3];
    	phi_BCL = new DistributedVar[3];

      _phi_BC0.init(phi_BC0, 3);
      _phi_MB.init(phi_MB, 3);
      _phi_BCL.init(phi_BCL, 3);

      DistributionDomain temp1;
      DistributionDomain temp2;
      //temp = ((Axial - 0) -Len);
      temp1 = Axial - 0;
      temp2 = temp1 - Len;

    	for(i=0;i<3;i++)
    	{
        phi_MB[i] = phi[i] | temp2; // for Mass Balance equation
        phi_MB[i].setParent(phi[i]);
    		phi_BC0[i] = phi[i] | (Axial|0); // for Boundary condition at lambda=0
        phi_BC0[i].setParent(phi[i]);
    		phi_BCL[i] = phi[i] | (Axial|Len); // for Boundary condition at lambda=Len=1.0
        phi_BCL[i].setParent(phi[i]);
    	}

      _phi_BC0.setParent(_phi);
      _phi_MB.setParent(_phi);
      _phi_BCL.setParent(_phi);
      
    	// ***** Equations *******
    	BC0 = new DistributedVar[3];
      _BC0.init(BC0, 3);
    	MB = new DistributedVar[3];
      _MB.init(MB, 3);
    	BCL = new DistributedVar[3];
      _BCL.init(BCL, 3);
    
    //#]
}

TubularReactor::~TubularReactor() 
{
    //#[ operation ~TubularReactor() 
    	DESTROY_VECTOR(phi_in)
    	DESTROY_VECTOR(nu)

      DESTROY_VECTOR(phi)
    	DESTROY_VECTOR(phi_BC0)
    	DESTROY_VECTOR(phi_MB)
    	DESTROY_VECTOR(phi_BCL)

      DESTROY_VECTOR(BC0)
    	DESTROY_VECTOR(MB)
    	DESTROY_VECTOR(BCL)
    
    //#]
}

HRESULT TubularReactor::r_BC0(long i) 
{
    //#[ operation r_BC0() 
    	// Boundary condition at lambda=0
    	BC0[i] = - K1 * phi_BC0[i].PARTIAL(Axial) + phi_BC0[i] -  phi_in[i] ;  
    	
    	return S_OK;
    //#]
}

HRESULT TubularReactor::r_BC0_0() 
{
    	return r_BC0(0);
}

HRESULT TubularReactor::r_BC0_1() 
{
    	return r_BC0(1);
}

HRESULT TubularReactor::r_BC0_2() 
{
    	return r_BC0(2);
}

HRESULT TubularReactor::r_BCL(long i) {
    //#[ operation r_BCL() 
    	
    	// Mass Balance equation (applicable inside the reactor)
    	MB[i] = - DER(phi_MB[i])
    			+ K1 * phi_MB[i].PARTIAL(Axial).PARTIAL(Axial)
    			+ phi_MB[i].PARTIAL(Axial)
    			+ nu[i]*K2*phi_MB[0]*phi_MB[1]; 
    	
    	return S_OK;
    
    //#]
}


HRESULT TubularReactor::r_BCL_0() 
{
      return r_BCL(0);
}

HRESULT TubularReactor::r_BCL_1()
{
      return r_BCL(1);
}

HRESULT TubularReactor::r_BCL_2() 
{
      return r_BCL(2);
}

HRESULT TubularReactor::r_MB(long i) 
{
    //#[ operation r_MB() 
    	
    	// Mass Balance equation (applicable inside the reactor)
    	MB[i] = - DER(phi_MB[i])
    			+ K1 * phi_MB[i].PARTIAL(Axial).PARTIAL(Axial)
    			+ phi_MB[i].PARTIAL(Axial)
    			+ nu[i]*K2*phi_MB[0]*phi_MB[1]; 
    	
    	return S_OK;
    
    //#]
}

HRESULT TubularReactor::r_MB_0() 
{
    	return r_MB(0);
}

HRESULT TubularReactor::r_MB_1()
{
    	return r_MB(1);
}

HRESULT TubularReactor::r_MB_2() 
{
    	return r_MB(2);
}



/*****************************************************************************
// begin AD verions of equations
*****************************************************************************/

HRESULT TubularReactor::ad_r_BC0(long i) 
{
    //#[ operation ad_r_BC0() 
    	// Boundary condition at lambda=0
    	AD(BC0[i]) = - K1 * AD(phi_BC0[i]).PARTIAL(Axial) + AD(phi_BC0[i]) - phi_in[i] ;  
    	
    	return S_OK;
    //#]
}

HRESULT TubularReactor::ad_r_BC0_0() 
{
    	return ad_r_BC0(0);
}

HRESULT TubularReactor::ad_r_BC0_1() 
{
    	return ad_r_BC0(1);
}

HRESULT TubularReactor::ad_r_BC0_2() 
{
    	return ad_r_BC0(2);
}

HRESULT TubularReactor::ad_r_BCL(long i) {
    //#[ operation ad_r_BCL() 
    	
    	// Mass Balance equation (applicable inside the reactor)
    	AD(MB[i]) = - DER_AD(phi_MB[i])
    			+ K1 * AD(phi_MB[i]).PARTIAL(Axial).PARTIAL(Axial)
    			+ AD(phi_MB[i]).PARTIAL(Axial)
    			+ nu[i] * K2 * AD(phi_MB[0])* AD(phi_MB[1]); 
    	
    	return S_OK;
    
    //#]
}


HRESULT TubularReactor::ad_r_BCL_0() 
{
      return ad_r_BCL(0);
}

HRESULT TubularReactor::ad_r_BCL_1()
{
      return ad_r_BCL(1);
}

HRESULT TubularReactor::ad_r_BCL_2() 
{
      return ad_r_BCL(2);
}

HRESULT TubularReactor::ad_r_MB(long i) 
{
    //#[ operation ad_r_MB() 
    	
    	// Mass Balance equation (applicable inside the reactor)
    	AD(MB[i]) = - DER_AD(phi_MB[i])
    			+ K1 * AD(phi_MB[i]).PARTIAL(Axial).PARTIAL(Axial)
    			+ AD(phi_MB[i]).PARTIAL(Axial)
    			+ nu[i] * K2 * AD(phi_MB[0]) * AD(phi_MB[1]); 
    	
    	return S_OK;
    
    //#]
}

HRESULT TubularReactor::ad_r_MB_0() 
{
    	return ad_r_MB(0);
}

HRESULT TubularReactor::ad_r_MB_1()
{
    	return ad_r_MB(1);
}

HRESULT TubularReactor::ad_r_MB_2() 
{
    	return ad_r_MB(2);
}

/*****************************************************************************
// end AD verions of equations
*****************************************************************************/












/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\TubularReactor.cpp
*********************************************************************/

//## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
HRESULT TubularReactor::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form)
{
  const long idx_eqn_r_BC0_0 = 0;
  const long idx_eqn_r_BC0_1 = 1;
  const long idx_eqn_r_BC0_2 = 2;
  const long idx_eqn_r_BCL_0 = 3;
  const long idx_eqn_r_BCL_1 = 4;
  const long idx_eqn_r_BCL_2 = 5;
  const long idx_eqn_r_MB_0 = 6;
  const long idx_eqn_r_MB_1 = 7;
  const long idx_eqn_r_MB_2 = 8;

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_BC0_0] = continuous;
  (*form)[idx_eqn_r_BC0_1] = continuous;
  (*form)[idx_eqn_r_BC0_2] = continuous;
  (*form)[idx_eqn_r_BCL_0] = continuous;
  (*form)[idx_eqn_r_BCL_1] = continuous;
  (*form)[idx_eqn_r_BCL_2] = continuous;
  (*form)[idx_eqn_r_MB_0] = continuous;
  (*form)[idx_eqn_r_MB_1] = continuous;
  (*form)[idx_eqn_r_MB_2] = continuous;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_BC0_0] = automatic;
  (*diff_form)[idx_eqn_r_BC0_1] = automatic;
  (*diff_form)[idx_eqn_r_BC0_2] = automatic;
  (*diff_form)[idx_eqn_r_BCL_0] = automatic;
  (*diff_form)[idx_eqn_r_BCL_1] = automatic;
  (*diff_form)[idx_eqn_r_BCL_2] = automatic;
  (*diff_form)[idx_eqn_r_MB_0] = automatic;
  (*diff_form)[idx_eqn_r_MB_1] = automatic;
  (*diff_form)[idx_eqn_r_MB_2] = automatic;

  return S_OK;
}

//## operation InitLocalEqns() 
HRESULT TubularReactor::InitLocalEqns()
{
  ADD_LOCAL_DIST_EQN(TubularReactor, r_BC0_0, BC0[0])
  ADD_LOCAL_DIST_EQN(TubularReactor, r_BC0_1, BC0[1])
  ADD_LOCAL_DIST_EQN(TubularReactor, r_BC0_2, BC0[2])
  ADD_LOCAL_DIST_EQN(TubularReactor, r_BCL_0, BCL[0])
  ADD_LOCAL_DIST_EQN(TubularReactor, r_BCL_1, BCL[1])
  ADD_LOCAL_DIST_EQN(TubularReactor, r_BCL_2, BCL[2])
  ADD_LOCAL_DIST_EQN(TubularReactor, r_MB_0, MB[0])
  ADD_LOCAL_DIST_EQN(TubularReactor, r_MB_1, MB[1])
  ADD_LOCAL_DIST_EQN(TubularReactor, r_MB_2, MB[2])

  return S_OK;
}

HRESULT TubularReactor::InitLocalADEqns()
{
  ADD_LOCAL_DIST_AD_EQN(TubularReactor, ad_r_BC0_0, AD(BC0[0]))
  ADD_LOCAL_DIST_AD_EQN(TubularReactor, ad_r_BC0_1, AD(BC0[1]))
  ADD_LOCAL_DIST_AD_EQN(TubularReactor, ad_r_BC0_2, AD(BC0[2]))
  ADD_LOCAL_DIST_AD_EQN(TubularReactor, ad_r_BCL_0, AD(BCL[0]))
  ADD_LOCAL_DIST_AD_EQN(TubularReactor, ad_r_BCL_1, AD(BCL[1]))
  ADD_LOCAL_DIST_AD_EQN(TubularReactor, ad_r_BCL_2, AD(BCL[2]))
  ADD_LOCAL_DIST_AD_EQN(TubularReactor, ad_r_MB_0, AD(MB[0]))
  ADD_LOCAL_DIST_AD_EQN(TubularReactor, ad_r_MB_1, AD(MB[1]))
  ADD_LOCAL_DIST_AD_EQN(TubularReactor, ad_r_MB_2, AD(MB[2]))

  return S_OK;
}

//## operation InitLocalVars(const _TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,const bool) 
HRESULT TubularReactor::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  ADD_LOCAL_DIST_SVAR(phi_BC0)
  ADD_LOCAL_DIST_SVAR(phi_BCL)
  ADD_LOCAL_DIST_SVAR(phi_MB)

  for (long i = 0; i < m_nEsos; i++)
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}

//## operation Load(FILE*) 
bool TubularReactor::Load(FILE*  fs)
{
  return true;
}

//## operation Save(FILE*) 
void TubularReactor::Save(FILE*  fs)
{

}