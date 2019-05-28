// implementation for class Car3
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "Car3.h"
// includes
#include "CSpring.h"
#include "CDamper.h"
#include "Engine.h"
#include "Actuator.h"
#include "Clutch.h"
#include "CFrame.h"
#include "Band_Break.h"
#include "Oneway_Clutch.h"
#include "Vehicle.h"
#include "Ravigneaux.h"

Car3::Car3()
{
  init();
}

Car3::~Car3()
{
 clean();
}

void Car3::init()
{


Spring = new CSpring();
Spring->AddRef();
Spring->Ks = 160.0;
Spring->ddTorque = 0.0;
Spring->dTorque = 0.0;

Damper = new CDamper();
Damper->AddRef();
Damper->Kd = 1.0;
Damper->velocity = 0.0;

EngineWithSpeed = new Engine();
EngineWithSpeed->AddRef();
EngineWithSpeed->RPM = 0.0;
EngineWithSpeed->throttle = 20.0;
EngineWithSpeed->inertia = 0.28;

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
OB->area = 0.075;
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

Car = new Vehicle();
Car->AddRef();
Car->wheelSpeed = 0.0;
Car->speed = 0.0;
Car->brakeTorque = 0.0;
Car->finalDriveRatio = 3.23;
Car->wheelRadius = 1.0;
Car->vehicleInertia = 115.5;
Car->wheelFrictionDrag = 40.0;
Car->aerodynamicDrag = 0.02;

GearBox = new Ravigneaux();
GearBox->AddRef();
GearBox->pinionToPinionForce = 0.0;
GearBox->ringToPinionForce = 0.0;
GearBox->pinionToReverseForce = 0.0;
GearBox->forwardToPinionForce = 0.0;

}


void Car3::clean()
{

if (Spring)
{
  Spring->Release();
  Spring = NULL;
}
if (Damper)
{
  Damper->Release();
  Damper = NULL;
}
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
if (Car)
{
  Car->Release();
  Car = NULL;
}
if (GearBox)
{
  GearBox->Release();
  GearBox = NULL;
}
}


void Car3::Save(FILE* fs)
{

Spring->Save(fs);
Damper->Save(fs);
EngineWithSpeed->Save(fs);
aRC->Save(fs);
RC->Save(fs);
aLRB->Save(fs);
GLRB->Save(fs);
LRB->Save(fs);
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
Car->Save(fs);
GearBox->Save(fs);
}


bool Car3::Load(FILE* fs)
{

if (! Spring->Load(fs) ) return false;
if (! Damper->Load(fs) ) return false;
if (! EngineWithSpeed->Load(fs) ) return false;
if (! aRC->Load(fs) ) return false;
if (! RC->Load(fs) ) return false;
if (! aLRB->Load(fs) ) return false;
if (! GLRB->Load(fs) ) return false;
if (! LRB->Load(fs) ) return false;
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
if (! Car->Load(fs) ) return false;
if (! GearBox->Load(fs) ) return false;

return true;
}


HRESULT Car3::GetAssociations(long** Assoc, long** Size, long* nSize)
{

long nAssoc;
long i;

const long assoc[] =
{
  0, 1,      21, 0,
  22, 3,      0, 0,
  1, 0,      21, 0,
  22, 3,      1, 1,
  2, 0,      4, 2,
  2, 0,      12, 2,
  2, 0,      19, 2,
  11, 0,      12, 0,
  19, 1,      22, 0,
  9, 0,      10, 0,
  4, 1,      22, 1,
  3, 0,      4, 0,
  5, 0,      7, 0,
  7, 1,      22, 2,
  6, 0,      7, 2,
  20, 0,      14, 2,
  10, 1,      22, 1,
  8, 0,      10, 2,
  12, 1,      22, 2,
  13, 0,      14, 0,
  14, 1,      22, 1,
  17, 1,      22, 2,
  15, 0,      17, 2,
  16, 0,      17, 0,
  18, 0,      19, 0,
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
};

*nSize = sizeof(size) / sizeof(long);
nAssoc = sizeof(assoc) / sizeof(long);

*Size = new long[*nSize];
*Assoc = new long[nAssoc];

for (i = 0; i < *nSize; i++) (*Size)[i] = size[i];
for (i = 0; i < nAssoc; i++) (*Assoc)[i] = assoc[i];

return S_OK;
}


HRESULT Car3::InitEsos()
{

  ADD_LOCAL_ESO(Spring)
  ADD_LOCAL_ESO(Damper)
  ADD_LOCAL_ESO(EngineWithSpeed)
  ADD_LOCAL_ESO(aRC)
  ADD_LOCAL_ESO(RC)
  ADD_LOCAL_ESO(aLRB)
  ADD_LOCAL_ESO(GLRB)
  ADD_LOCAL_ESO(LRB)
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
  ADD_LOCAL_ESO(Car)
  ADD_LOCAL_ESO(GearBox)

  return S_OK;
}

// added by hand


void Car3::handle_throttle(const double t, double* val)  
{
  EngineWithSpeed->handle_throttle(t, val);
}                     

void Car3::handle_RCShift(const double t, long* val)  
{
  aRC->handle_shiftEvent(t, val);
}                     

void Car3::handle_LRBShift(const double t, long* val)  
{
  aLRB->handle_shiftEvent(t, val);
}                     

void Car3::handle_TCCShift(const double t, long* val)  
{
//aTCC->handle_shiftEvent(t, val);
}                     

void Car3::handle_OBShift(const double t, long* val)  
{
  aOB->handle_shiftEvent(t, val);
}                     

void Car3::handle_DCShift(const double t, long* val)  
{
  aDC->handle_shiftEvent(t, val);
}                     

void Car3::handle_IOCShift(const double t, long* val)  
{
  aIOC->handle_shiftEvent(t, val);
}                     

void Car3::handle_POCShift(const double t, long* val)  
{
  aPOC->handle_shiftEvent(t, val);
}                     

void Car3::handle_FCShift(const double t, long* val)  
{
  aFC->handle_shiftEvent(t, val);
}                     

void Car3::handle_brakeTorque(const double t, double* val)
{
  Car->handle_brakeTorque(t, val);
}

void Car3::handle_Start(const double t, long *val)
{
  EngineWithSpeed->handle_Start(t, val); 
}



