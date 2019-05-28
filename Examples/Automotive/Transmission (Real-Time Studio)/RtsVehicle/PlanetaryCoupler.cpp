//{{SCG_IMPLEMENTATION(PlanetaryCoupler.cpp) [0]

//{{SCG_INCLUDE 

// Cg_Add
#include "StdAfx.h" 
                   

                    
#include "PlanetaryCoupler.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#define DER(ITEM) der_##ITEM

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

PlanetaryCoupler::PlanetaryCoupler(){
  init();
}
PlanetaryCoupler::~PlanetaryCoupler(){

}


void PlanetaryCoupler::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
torque = 0.0;
speed = 0.0;
acceleration = 0.0;

DER(torque) = 0.0;
DER(speed) = 0.0;
DER(acceleration) = 0.0;

inertia = 0.2;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            


//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT PlanetaryCoupler::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SVAR(torque)
  ADD_LOCAL_SVAR(speed)
  ADD_LOCAL_SVAR(acceleration)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT PlanetaryCoupler::InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SRPAR(inertia)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION


HRESULT PlanetaryCoupler::InitLocalIPars(const _TCHAR* prefix, pplong *pars, ppchar *Names, long *nPars, long *dPars)
{
  return S_OK;
}







