// implementation for class junk115
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "junk115.h"
// includes
#include "Engine.h"
#include "Actuator.h"
#include "Oneway_Clutch.h"
#include "CFrame.h"
#include "Clutch.h"
#include "Vehicle.h"
#include "Ravigneaux.h"
void junk115::init()
{


EngineWithSpeed = new Engine();
EngineWithSpeed->AddRef();
EngineWithSpeed->RPM = 0.0;
EngineWithSpeed->throttle = 20.0;
EngineWithSpeed->inertia = 0.28;

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
IOC->cSurfaces = 8.0;
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
POC->cSurfaces = 8.0;
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
FC->nSurfaces = 10.0;
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
Car->breakTorque = 0.0;
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


void junk115::clean()
{

if (EngineWithSpeed)
{
  EngineWithSpeed->Release();
  EngineWithSpeed = NULL;
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


void junk115::Save(FILE* fs)
{

EngineWithSpeed->Save(fs);
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


bool junk115::Load(FILE* fs)
{

if (! EngineWithSpeed->Load(fs) ) return false;
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


HRESULT junk115::GetAssociations(long** Assoc, long** Size, long* nSize)
{

long nAssoc;
long i;

const long assoc[] =
{
  0, 0,      7, 2,
  7, 1,      10, 0,
  8, 0,      2, 2,
  1, 0,      2, 0,
  2, 1,      10, 1,
  5, 1,      10, 2,
  3, 0,      5, 2,
  4, 0,      5, 0,
  6, 0,      7, 0,
  10, 3,      9, 0,
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
};

*nSize = sizeof(size) / sizeof(long);
nAssoc = sizeof(assoc) / sizeof(long);

*Size = new long[*nSize];
*Assoc = new long[nAssoc];

for (i = 0; i < *nSize; i++) (*Size)[i] = size[i];
for (i = 0; i < nAssoc; i++) (*Assoc)[i] = assoc[i];

return S_OK;
}


HRESULT junk115::InitEsos()
{

  ADD_LOCAL_ESO(EngineWithSpeed)
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


