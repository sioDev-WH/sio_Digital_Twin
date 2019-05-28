// implementation for class junk160
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "junk160.h"
// includes
#include "CFrame.h"
#include "Oneway_Clutch.h"
#include "Actuator.h"
#include "Engine.h"
#include "Vehicle.h"
#include "Clutch.h"
#include "Ravigneaux.h"
void junk160::init()
{


IOCGround = new CFrame();
IOCGround->AddRef();

IOC = new Oneway_Clutch();
IOC->AddRef();
IOC->direction = Direction_CLOCKWISE;
IOC->nSurfaces = 8.0;
IOC->area = 0.0075;
IOC->radius = 0.055;
IOC->relativeVelocity = 0.0;
IOC->cBreakfreeDisp = 0.0;
IOC->torqueRatio = 0.3;
IOC->damping = 100000.0;
IOC->displacement = 0.0;
IOC->ccBreakfreeDisp = 0.0;
IOC->pressureMax = 1000.0;
IOC->cBreakfreeDispMax = 0.01;
IOC->ccBreakfreeDispMax = 0.0;

aIOC = new Actuator();
aIOC->AddRef();
aIOC->shiftTime = 0.0;
aIOC->shiftPeriod = 0.5;
aIOC->rate = 30.5;
aIOC->tolerance = 0.001;
aIOC->pressureMax = 1000.0;

myEngine = new Engine();
myEngine->AddRef();
myEngine->RPM = 0.0;
myEngine->throttle = 20.0;
myEngine->inertia = 0.28;

Car = new Vehicle();
Car->AddRef();
Car->wheelSpeed = 0.0;
Car->speed = 0.0;
Car->brakeTorque = 0.0;
Car->finalDriveRatio = 3.23;
Car->wheelRadius = 1.0;
Car->vehicleInertia = 115.5;
Car->wheelFrictionDrag = 0.3;
Car->aerodynamicDrag = 0.02;

POCGround = new CFrame();
POCGround->AddRef();

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
POC->nSurfaces = 8.0;
POC->area = 0.0075;
POC->radius = 0.055;
POC->relativeVelocity = 0.0;
POC->cBreakfreeDisp = 0.0;
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

GearBox = new Ravigneaux();
GearBox->AddRef();
GearBox->pinionToPinionForce = 0.0;
GearBox->ringToPinionForce = 0.0;
GearBox->pinionToReverseForce = 0.0;
GearBox->forwardToPinionForce = 0.0;

}


void junk160::clean()
{

if (IOCGround)
{
  IOCGround->Release();
  IOCGround = NULL;
}
if (IOC)
{
  IOC->Release();
  IOC = NULL;
}
if (aIOC)
{
  aIOC->Release();
  aIOC = NULL;
}
if (myEngine)
{
  myEngine->Release();
  myEngine = NULL;
}
if (Car)
{
  Car->Release();
  Car = NULL;
}
if (POCGround)
{
  POCGround->Release();
  POCGround = NULL;
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
if (GearBox)
{
  GearBox->Release();
  GearBox = NULL;
}
}


void junk160::Save(FILE* fs)
{

IOCGround->Save(fs);
IOC->Save(fs);
aIOC->Save(fs);
myEngine->Save(fs);
Car->Save(fs);
POCGround->Save(fs);
aPOC->Save(fs);
POC->Save(fs);
aFC->Save(fs);
FC->Save(fs);
GearBox->Save(fs);
}


bool junk160::Load(FILE* fs)
{

if (! IOCGround->Load(fs) ) return false;
if (! IOC->Load(fs) ) return false;
if (! aIOC->Load(fs) ) return false;
if (! myEngine->Load(fs) ) return false;
if (! Car->Load(fs) ) return false;
if (! POCGround->Load(fs) ) return false;
if (! aPOC->Load(fs) ) return false;
if (! POC->Load(fs) ) return false;
if (! aFC->Load(fs) ) return false;
if (! FC->Load(fs) ) return false;
if (! GearBox->Load(fs) ) return false;

return true;
}


HRESULT junk160::GetAssociations(long** Assoc, long** Size, long* nSize)
{

long nAssoc;
long i;

const long assoc[] =
{
  0, 0,      1, 2,
  1, 1,      10, 1,
  2, 0,      1, 0,
  3, 0,      9, 2,
  10, 3,      4, 0,
  7, 1,      10, 2,
  5, 0,      7, 2,
  6, 0,      7, 0,
  9, 1,      10, 0,
  8, 0,      9, 0,
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


HRESULT junk160::InitEsos()
{

  ADD_LOCAL_ESO(IOCGround)
  ADD_LOCAL_ESO(IOC)
  ADD_LOCAL_ESO(aIOC)
  ADD_LOCAL_ESO(myEngine)
  ADD_LOCAL_ESO(Car)
  ADD_LOCAL_ESO(POCGround)
  ADD_LOCAL_ESO(aPOC)
  ADD_LOCAL_ESO(POC)
  ADD_LOCAL_ESO(aFC)
  ADD_LOCAL_ESO(FC)
  ADD_LOCAL_ESO(GearBox)

  return S_OK;
}


