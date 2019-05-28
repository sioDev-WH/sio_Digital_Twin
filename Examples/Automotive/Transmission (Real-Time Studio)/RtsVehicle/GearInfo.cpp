//{{SCG_IMPLEMENTATION(GearInfo.cpp) [0]

//{{SCG_INCLUDE 

// Cg_Add
#include "StdAfx.h" 
                   

                    
#include "GearInfo.h"

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


GearInfo::GearInfo()
{
  ID = -1000;
  ClutchState = NULL;
}

GearInfo::~GearInfo()
{
  clean();
}

void GearInfo::init(const long GearID, const long nClutches, const long nEngaged, const long* Engaged)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    int i;

    ID=GearID;
    ClutchState = (bool*) new bool[nClutches];
    for(i=0;i<nClutches;i++)  ClutchState[i] = false;
    for(i=0;i<nEngaged;i++)
       ClutchState[Engaged[i]] = true;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void GearInfo::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  if(ClutchState) 
  {
    delete[] ClutchState;
    ClutchState = NULL;
  }

  //}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION









