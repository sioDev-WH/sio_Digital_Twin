//{{SCG_IMPLEMENTATION(Gear.cpp) [0]

//{{SCG_INCLUDE   

// Cg_Add
#include "StdAfx.h" 
                
                  
#include "Gear.h"

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

Gear::Gear(){
  init();
}

Gear::~Gear(){

}

void Gear::init()  
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

inertia = 0.1;
nTeeth = 20;
radius = 0.1;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            


//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Gear::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SVAR(acceleration)
  ADD_LOCAL_SVAR(torque)
  ADD_LOCAL_SVAR(speed)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Gear::InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SRPAR(radius)
  ADD_LOCAL_SRPAR(inertia)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Gear::InitLocalIPars(const _TCHAR* prefix, pplong *pars, ppchar *Names, long *nPars, long *dPars)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SIPAR(nTeeth)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION









