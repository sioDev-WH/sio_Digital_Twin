//{{SCG_IMPLEMENTATION(COneClutch.cpp) [0]

#include "StdAfx.h"

#include "RigidConnector.h"
#include "Frame.h"
#include "Mass.h"
#include "Ravigneaux.h"
#include "Engine.h"
#include "Clutch.h"
#include "Actuator.h"


//{{SCG_INCLUDE                     
#include "COneClutch.h"
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
COneClutch::COneClutch()
{
  init();

}

COneClutch::~COneClutch()
{
  clean();

}
void COneClutch::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


Ground = new CFrame();
Ground->AddRef();

Mass = new CMass();
Mass->AddRef();
Mass->W = 0.0;
Mass->J = 100.0;

Ravigneaux1 = new Ravigneaux();
Ravigneaux1->AddRef();
Ravigneaux1->pinionToPinionForce = 0.0;
Ravigneaux1->ringToPinionForce = 0.0;
Ravigneaux1->pinionToReverseForce = 0.0;
Ravigneaux1->forwardToPinionForce = 0.0;

Engine1 = new Engine();
Engine1->AddRef();
Engine1->RPM = 0.0;
Engine1->throttle = 20.0;
Engine1->inertia = 0.280120961324208;

Clutch1 = new Clutch();
Clutch1->AddRef();
Clutch1->nSurfaces = 10;
Clutch1->area = 0.0075;
Clutch1->radius = 0.055;
Clutch1->relativeVelocity = 0.0;
Clutch1->cBreakfreeDisp = 0.0000001;
Clutch1->torqueRatio = 0.3;
Clutch1->damping = 100000.0;
Clutch1->displacement = 0.0;
Clutch1->ccBreakfreeDisp = 0.0000001;
Clutch1->pressureMax = 1000.0;
Clutch1->cBreakfreeDispMax = 0.00001;
Clutch1->ccBreakfreeDispMax = 0.00001;

Actuator1 = new Actuator();
Actuator1->AddRef();
Actuator1->shiftTime = 0.0;
Actuator1->shiftPeriod = 0.5;
Actuator1->tolerance = 0.001;
// Actuator1->rate = 0.0;
Actuator1->rate=30.0;
Actuator1->pressureMax = 1000.0;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void COneClutch::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


Ground->Release();
Mass->Release();
Ravigneaux1->Release();
Engine1->Release();
Clutch1->Release();
Actuator1->Release();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT COneClutch::GetAssociations(long* *Assoc, long* *Size, long *nSize)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

long nAssoc;
long i;

/*
  0 ADD_LOCAL_ESO(Ground)
  1 ADD_LOCAL_ESO(Mass)
  2 ADD_LOCAL_ESO(Ravigneaux1)
  3 ADD_LOCAL_ESO(Engine1)
  4 ADD_LOCAL_ESO(Clutch1)
  5 ADD_LOCAL_ESO(Actuator1)
*/

const long assoc[] =
{
  4, 1,      2, 0,
  3, 0,      4, 0,
  0, 0,      2, 2,
  2, 3,      1, 0,
  5, 0,      4, 2,
};

const long size[] =
{
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
};

*nSize = sizeof(size) / sizeof(long);
nAssoc = sizeof(assoc) / sizeof(long);

*Size = new long[*nSize];
*Assoc = new long[nAssoc];

for (i = 0; i < *nSize; i++) (*Size)[i] = size[i];
for (i = 0; i < nAssoc; i++) (*Assoc)[i] = assoc[i];

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT COneClutch::InitEsos()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_ESO(Ground)
  ADD_LOCAL_ESO(Mass)
  ADD_LOCAL_ESO(Ravigneaux1)
  ADD_LOCAL_ESO(Engine1)
  ADD_LOCAL_ESO(Clutch1)
  ADD_LOCAL_ESO(Actuator1)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION









