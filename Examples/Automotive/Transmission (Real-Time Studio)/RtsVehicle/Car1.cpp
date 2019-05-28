// implementation for class Car1
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <fstream.h>

#include "Car1.h"
// includes
#include "Engine.h"
#include "Actuator.h"
#include "Clutch.h"
#include "CFrame.h"
#include "Band_Break.h"
#include "Torque_Converter.h"
#include "Oneway_Clutch.h"
//#include "Vehicle.h"
#include "Vehicle2.h"
#include "Ravigneaux.h"
#include "CSpring.h"
#include "CDamper.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

Car1::Car1()
{
  init();
}

Car1::~Car1()
{
 clean();
}

void Car1::init()
{


EngineWithSpeed = new Engine();
EngineWithSpeed->AddRef();
EngineWithSpeed->RPM = 0.0;
EngineWithSpeed->throttle = 20.0;
EngineWithSpeed->inertia = 0.28; // 0.28;

aRC = new Actuator();
aRC->AddRef();
aRC->shiftTime = 0.0;
aRC->shiftPeriod = 0.5;
aRC->rate = 30.5;
aRC->tolerance = 0.001;
aRC->pressureMax = 1000.0;

RC = new Clutch();
RC->AddRef();
RC->nSurfaces = 10;
RC->area = 0.0075;
RC->radius = 0.055;
RC->relativeVelocity = 0.0;
RC->cBreakfreeDisp = 0.001;
RC->torqueRatio = 0.3;
RC->damping = 100000.0;
RC->displacement = 0.0;
RC->ccBreakfreeDisp = 0.001;
RC->pressureMax = 1000.0;
RC->cBreakfreeDispMax = 0.01;
RC->ccBreakfreeDispMax = 0.01;

aLRB = new Actuator();
aLRB->AddRef();
aLRB->shiftTime = 0.0;
aLRB->shiftPeriod = 0.5;
aLRB->rate = 30.5;
aLRB->tolerance = 0.001;
aLRB->pressureMax = 1000.0;

GLRB = new CFrame();
GLRB->AddRef();

LRB = new Band_Break();
LRB->AddRef();
LRB->area = 0.075;
LRB->radius = 0.055;
LRB->relativeVelocity = 0.0;
LRB->cBreakfreeDisp = 0.001;
LRB->torqueRatio = 0.3;
LRB->damping = 100000.0;
LRB->displacement = 0.0;
LRB->ccBreakfreeDisp = 0.0;
LRB->pressureMax = 1000.0;
LRB->cBreakfreeDispMax = 0.01;
LRB->ccBreakfreeDispMax = 0.0;

aTCC = new Actuator();
aTCC->AddRef();
aTCC->shiftTime = 0.0;
aTCC->shiftPeriod = 0.5;
aTCC->rate = 30.5;
aTCC->tolerance = 0.001;
aTCC->pressureMax = 1000.0;

TCC = new Clutch();
TCC->AddRef();
TCC->nSurfaces = 10;
TCC->area = 0.0075;
TCC->radius = 0.055;
TCC->relativeVelocity = 0.0;
TCC->cBreakfreeDisp = 0.001;
TCC->torqueRatio = 0.3;
TCC->damping = 100000.0;
TCC->displacement = 0.0;
TCC->ccBreakfreeDisp = 0.001;
TCC->pressureMax = 1000.0;
TCC->cBreakfreeDispMax = 0.01;
TCC->ccBreakfreeDispMax = 0.01;

Converter = new Torque_Converter();
Converter->AddRef();
Converter->turbineTorque = 0.0;
Converter->turbineSpeed = 0.0;
Converter->turbineInertia = 0.119; // 0.119;
Converter->impellerTorque = 0.0;
Converter->impellerSpeed = 0.0;
Converter->impellerInertia = 0.14; // 0.14;

GOB = new CFrame();
GOB->AddRef();

aOB = new Actuator();
aOB->AddRef();
aOB->shiftTime = 0.0;
aOB->shiftPeriod = 0.5;
aOB->rate = 30.5;
aOB->tolerance = 0.001;
aOB->pressureMax = 1000.0;

OB = new Band_Break();
OB->AddRef();
OB->area = 0.075; // 0.005; // 0.075;
OB->radius = 0.055;
OB->relativeVelocity = 0.0;
OB->cBreakfreeDisp = 0.001;
OB->torqueRatio = 0.3;
OB->damping = 100000.0;
OB->displacement = 0.0;
OB->ccBreakfreeDisp = 0.001;
OB->pressureMax = 1000.0;
OB->cBreakfreeDispMax = 0.01;
OB->ccBreakfreeDispMax = 0.01;

aDC = new Actuator();
aDC->AddRef();
aDC->shiftTime = 0.0;
aDC->shiftPeriod = 0.5;
aDC->rate = 30.5;
aDC->tolerance = 0.001;
aDC->pressureMax = 1000.0;

DC = new Clutch();
DC->AddRef();
DC->nSurfaces = 10;
DC->area = 0.0075;
DC->radius = 0.055;
DC->relativeVelocity = 0.0;
DC->cBreakfreeDisp = 0.001;
DC->torqueRatio = 0.3;
DC->damping = 100000.0;
DC->displacement = 0.0;
DC->ccBreakfreeDisp = 0.001;
DC->pressureMax = 1000.0;
DC->cBreakfreeDispMax = 0.01;
DC->ccBreakfreeDispMax = 0.01;

aIOC = new Actuator();
aIOC->AddRef();
aIOC->shiftTime = 0.0;
aIOC->shiftPeriod = 0.5;
aIOC->rate = 30.5;
aIOC->tolerance = 0.001;
aIOC->pressureMax = 1000.0;

IOC = new Oneway_Clutch();
IOC->AddRef();
IOC->direction = Direction_CLOCKWISE;
IOC->nSurfaces = 8;
IOC->area = 0.0075;
IOC->radius = 0.055;
IOC->relativeVelocity = 0.0;
IOC->cBreakfreeDisp = 0.001;
IOC->torqueRatio = 0.3;
IOC->damping = 100000.0;
IOC->displacement = 0.0;
IOC->ccBreakfreeDisp = 0.0;
IOC->pressureMax = 1000.0;
IOC->cBreakfreeDispMax = 0.01;
IOC->ccBreakfreeDispMax = 0.0;

GPOC = new CFrame();
GPOC->AddRef();

aPOC = new Actuator();
aPOC->AddRef();
aPOC->shiftTime = 0.0;
aPOC->shiftPeriod = 0.5;
aPOC->rate = 30.5;
aPOC->tolerance = 0.001;
aPOC->pressureMax = 1000.0;

POC = new Oneway_Clutch();
POC->AddRef();
POC->direction = Direction_CLOCKWISE;
POC->nSurfaces = 8;
POC->area = 0.0075;
POC->radius = 0.055;
POC->relativeVelocity = 0.0;
POC->cBreakfreeDisp = 0.001;
POC->torqueRatio = 0.3;
POC->damping = 100000.0;
POC->displacement = 0.0;
POC->ccBreakfreeDisp = 0.0;
POC->pressureMax = 1000.0;
POC->cBreakfreeDispMax = 0.01;
POC->ccBreakfreeDispMax = 0.0;

aFC = new Actuator();
aFC->AddRef();
aFC->shiftTime = 0.0;
aFC->shiftPeriod = 0.5;
aFC->rate = 30.5;
aFC->tolerance = 0.001;
aFC->pressureMax = 1000.0;

FC = new Clutch();
FC->AddRef();
FC->nSurfaces = 10;
FC->area = 0.0075;
FC->radius = 0.055;
FC->relativeVelocity = 0.0;
FC->cBreakfreeDisp = 0.001;
FC->torqueRatio = 0.3;
FC->damping = 100000.0;
FC->displacement = 0.0;
FC->ccBreakfreeDisp = 0.001;
FC->pressureMax = 1000.0;
FC->cBreakfreeDispMax = 0.01;
FC->ccBreakfreeDispMax = 0.01;

GIOC = new CFrame();
GIOC->AddRef();

//myCar = new Vehicle();
myCar = new Vehicle2();
myCar->AddRef();
myCar->wheelSpeed = 0.0;
myCar->speed = 0.0;
myCar->brakeTorque = 0.0;
myCar->finalDriveRatio = 3.23;
myCar->wheelRadius = 1.0;
myCar->vehicleInertia = 115.5;
myCar->wheelFrictionDrag = 40.0;
myCar->aerodynamicDrag = 0.02;

GearBox = new Ravigneaux();
GearBox->AddRef();
GearBox->pinionToPinionForce = 0.0;
GearBox->ringToPinionForce = 0.0;
GearBox->pinionToReverseForce = 0.0;
GearBox->forwardToPinionForce = 0.0;

// added inertia settings for gearbox
double factor = 1.0;
GearBox->forwardSun.inertia = 0.03 / factor;
GearBox->shortPinion.inertia = 0.02 / factor;
GearBox->reverseSun.inertia = 0.036 / factor;
GearBox->longPinion.inertia = 0.02 / factor;
GearBox->carrier.inertia = 0.1 / factor;
GearBox->ring.inertia = 0.72 / factor;

shaft_spring = new CSpring();
shaft_spring->Ks = 160.0;
shaft_damper = new CDamper();
shaft_damper->Kd = 100.0;

}


void Car1::clean()
{

if (EngineWithSpeed)
{
  EngineWithSpeed->Release();
  EngineWithSpeed = NULL;
}
if (aRC)
{
  aRC->Release();
  aRC = NULL;
}
if (RC)
{
  RC->Release();
  RC = NULL;
}
if (aLRB)
{
  aLRB->Release();
  aLRB = NULL;
}
if (GLRB)
{
  GLRB->Release();
  GLRB = NULL;
}
if (LRB)
{
  LRB->Release();
  LRB = NULL;
}
if (aTCC)
{
  aTCC->Release();
  aTCC = NULL;
}
if (TCC)
{
  TCC->Release();
  TCC = NULL;
}
if (Converter)
{
  Converter->Release();
  Converter = NULL;
}
if (GOB)
{
  GOB->Release();
  GOB = NULL;
}
if (aOB)
{
  aOB->Release();
  aOB = NULL;
}
if (OB)
{
  OB->Release();
  OB = NULL;
}
if (aDC)
{
  aDC->Release();
  aDC = NULL;
}
if (DC)
{
  DC->Release();
  DC = NULL;
}
if (aIOC)
{
  aIOC->Release();
  aIOC = NULL;
}
if (IOC)
{
  IOC->Release();
  IOC = NULL;
}
if (GPOC)
{
  GPOC->Release();
  GPOC = NULL;
}
if (aPOC)
{
  aPOC->Release();
  aPOC = NULL;
}
if (POC)
{
  POC->Release();
  POC = NULL;
}
if (aFC)
{
  aFC->Release();
  aFC = NULL;
}
if (FC)
{
  FC->Release();
  FC = NULL;
}
if (GIOC)
{
  GIOC->Release();
  GIOC = NULL;
}
if (myCar)
{
  myCar->Release();
  myCar = NULL;
}
if (GearBox)
{
  GearBox->Release();
  GearBox = NULL;
}

if (shaft_spring)
{
  shaft_spring->Release();
  shaft_spring = NULL;
}

if (shaft_damper)
{
  shaft_damper->Release();
  shaft_damper = NULL;
}

}


HRESULT Car1::GetAssociations(long** Assoc, long** Size, long* nSize)
{

long nAssoc;
long i;

/*
const long assoc[] =
{
  12, 0,      13, 0,
  0, 0,      8, 1,
  20, 1,      23, 0,
  10, 0,      11, 0,
  2, 1,      23, 1,
  8, 0,      2, 2,
  1, 0,      2, 0,
  3, 0,      5, 0,
  5, 1,      23, 2,
  4, 0,      5, 2,
  7, 1,      8, 0,
  8, 1,      7, 2,
  6, 0,      7, 0,
  8, 0,      13, 2,
  8, 0,      20, 2,
  21, 0,      15, 2,
  11, 1,      23, 1,
  9, 0,      11, 2,
  13, 1,      23, 2,
  14, 0,      15, 0,
  15, 1,      23, 1,
  18, 1,      23, 2,
  16, 0,      18, 2,
  17, 0,      18, 0,
  19, 0,      20, 0,

  23, 3,      24, 0,
  23, 3,      25, 0,
  24, 1,      22, 0,
  25, 1,      22, 0,
};

const long size[] =
{
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,

  2, 2,
  2, 2,
  2, 2,
  2, 2,
};

*/

const long assoc[] =
{
  12, 0,      13, 0,
  0, 0,      8, 1,
  20, 1,      23, 0,
  10, 0,      11, 0,
  2, 1,      23, 1,
  8, 0,      2, 2,
  1, 0,      2, 0,
  3, 0,      5, 0,
  5, 1,      23, 2,
  4, 0,      5, 2,
  7, 1,      8, 0,
  8, 1,      7, 2,
  6, 0,      7, 0,
  8, 0,      13, 2,
  8, 0,      20, 2,
  21, 0,      15, 2,
  11, 1,      23, 1,
  9, 0,      11, 2,
  13, 1,      23, 2,
  14, 0,      15, 0,
  15, 1,      23, 1,
  18, 1,      23, 2,
  16, 0,      18, 2,
  17, 0,      18, 0,
  19, 0,      20, 0,

  23, 3,      24, 0,
  23, 3,      25, 0,
  24, 1,      22, 0,
  25, 1,      22, 0,
};

const long size[] =
{
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
  2, 2,
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
}


HRESULT Car1::InitEsos()
{

  ADD_LOCAL_ESO(EngineWithSpeed)
  ADD_LOCAL_ESO(aRC)
  ADD_LOCAL_ESO(RC)
  ADD_LOCAL_ESO(aLRB)
  ADD_LOCAL_ESO(GLRB)
  ADD_LOCAL_ESO(LRB)
  ADD_LOCAL_ESO(aTCC)
  ADD_LOCAL_ESO(TCC)
  ADD_LOCAL_ESO(Converter)
  ADD_LOCAL_ESO(GOB)
  ADD_LOCAL_ESO(aOB)
  ADD_LOCAL_ESO(OB)
  ADD_LOCAL_ESO(aDC)
  ADD_LOCAL_ESO(DC)
  ADD_LOCAL_ESO(aIOC)
  ADD_LOCAL_ESO(IOC)
  ADD_LOCAL_ESO(GPOC)
  ADD_LOCAL_ESO(aPOC)
  ADD_LOCAL_ESO(POC)
  ADD_LOCAL_ESO(aFC)
  ADD_LOCAL_ESO(FC)
  ADD_LOCAL_ESO(GIOC)
  ADD_LOCAL_ESO(myCar)
  ADD_LOCAL_ESO(GearBox)
  ADD_LOCAL_ESO(shaft_spring)
  ADD_LOCAL_ESO(shaft_damper)

  return S_OK;
}

void Car1::handle_throttle(const double t, double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
EngineWithSpeed->handle_throttle(t, val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Car1::handle_RCShift(const double t, long* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
aRC->handle_shiftEvent(t, val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Car1::handle_LRBShift(const double t, long* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
aLRB->handle_shiftEvent(t, val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.8)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Car1::handle_TCCShift(const double t, long* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
aTCC->handle_shiftEvent(t, val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.9)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Car1::handle_OBShift(const double t, long* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
aOB->handle_shiftEvent(t, val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Car1::handle_DCShift(const double t, long* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
aDC->handle_shiftEvent(t, val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Car1::handle_IOCShift(const double t, long* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
aIOC->handle_shiftEvent(t, val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Car1::handle_POCShift(const double t, long* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
aPOC->handle_shiftEvent(t, val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.13)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Car1::handle_FCShift(const double t, long* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
aFC->handle_shiftEvent(t, val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION


void Car1::handle_brakeTorque(const double t, double* val)
{
  myCar->handle_brakeTorque(t, val);
}

void Car1::handle_Start(const double t, long *val)
{
  EngineWithSpeed->handle_Start(t, val); 
}


void Car1::Save(FILE* fs)
{
  EngineWithSpeed->Save(fs);
  aRC->Save(fs);
  RC->Save(fs);
  aLRB->Save(fs);
  GLRB->Save(fs);
  LRB->Save(fs);
  aTCC->Save(fs);
  TCC->Save(fs);
  Converter->Save(fs);
  GOB->Save(fs);
  aOB->Save(fs);
  OB->Save(fs);
  aDC->Save(fs);
  DC->Save(fs);
  aIOC->Save(fs);
  IOC->Save(fs);
  GPOC->Save(fs);
  aPOC->Save(fs);
  POC->Save(fs);
  aFC->Save(fs);
  FC->Save(fs);
  GIOC->Save(fs);
  myCar->Save(fs);
  GearBox->Save(fs);
}

bool Car1::Load(FILE* fs)
{
  if (! EngineWithSpeed->Load(fs) ) return false;
  if (! aRC->Load(fs) ) return false;
  if (! RC->Load(fs) ) return false;
  if (! aLRB->Load(fs) ) return false;
  if (! GLRB->Load(fs) ) return false;
  if (! LRB->Load(fs) ) return false;
  if (! aTCC->Load(fs) ) return false;
  if (! TCC->Load(fs) ) return false;
  if (! Converter->Load(fs) ) return false;
  if (! GOB->Load(fs) ) return false;
  if (! aOB->Load(fs) ) return false;
  if (! OB->Load(fs) ) return false;
  if (! aDC->Load(fs) ) return false;
  if (! DC->Load(fs) ) return false;
  if (! aIOC->Load(fs) ) return false;
  if (! IOC->Load(fs) ) return false;
  if (! GPOC->Load(fs) ) return false;
  if (! aPOC->Load(fs) ) return false;
  if (! POC->Load(fs) ) return false;
  if (! aFC->Load(fs) ) return false;
  if (! FC->Load(fs) ) return false;
  if (! GIOC->Load(fs) ) return false;
  if (! myCar->Load(fs) ) return false;
  if (! GearBox->Load(fs) ) return false;

  return true;
}
