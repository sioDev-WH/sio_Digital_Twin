//{{SCG_IMPLEMENTATION(CMass.cpp) [0]

//{{SCG_INCLUDE   

// Cg_Add
#include "StdAfx.h" 
#include "RigidConnector.h"                   


                  
#include "CMass.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

// Include for Template Class should go here.
//}}SCG_INCLUDE
                      
//{{SCG_CLASS_ID
//}}SCG_CLASS_ID

//{{SCG_ICLASS_INFO(0)


//}}SCG_ICLASS_INFO
//{{SCG_ATTS(0)
//}}SCG_ATTS

//{{SCG_ROLES(0)
//}}SCG_ROLES

//{{SCG_OPS(0)

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   


CMass::CMass(){
  init();
}

CMass::~CMass(){
  clean();
}

HRESULT CMass::res0(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = p->torque + n->torque - J * p->acceleration;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::res1(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = DER(velocity) - p->acceleration;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::res2(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = p->acceleration - n->acceleration;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void CMass::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  J = 100.0;

 velocity = 0.0;
 DER(velocity) = 0.0;

  p = new CRigidConnector();
  n = new CRigidConnector();

  p->AddRef();
  n->AddRef();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void CMass::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  p->Release();
  n->Release();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void CMass::handle_J(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 0, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::InitEsos()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_ESO(p)
  ADD_LOCAL_ESO(n)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::InitLocalEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_EQN(CMass, res0)
  ADD_LOCAL_EQN(CMass, res1)
  ADD_LOCAL_EQN(CMass, res2)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.8)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::InitLocalADEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_AD_EQN(CMass, ad_res0)
  ADD_LOCAL_AD_EQN(CMass, ad_res1)
  ADD_LOCAL_AD_EQN(CMass, ad_res2)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.9)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


const long idx_eqn_res0 = 0;
const long idx_eqn_res1 = 1;
const long idx_eqn_res2 = 2;

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_res0] = continuous;
  (*form)[idx_eqn_res1] = continuous;
  (*form)[idx_eqn_res2] = continuous;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_res0] = numeric;
  (*diff_form)[idx_eqn_res1] = numeric;
  (*diff_form)[idx_eqn_res2] = numeric;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SVAR(velocity)

for (long i = 0; i < m_nEsos; i++)
  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SRPAR(J)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::ad_res0(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = p->ad_torque + n->ad_torque - J * p->ad_acceleration;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.13)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::ad_res1(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = DER(ad_velocity) - p->ad_acceleration;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.14)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT CMass::ad_res2(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = p->ad_acceleration - n->ad_acceleration;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION









