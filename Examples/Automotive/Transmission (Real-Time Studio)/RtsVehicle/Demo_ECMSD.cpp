// implementation for class Demo_ECMSD
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "Demo_ECMSD.h"
// includes
#include "CMass.h"
#include "CSpring.h"
#include "CDamper.h"
#include "Vehicle5.h"
#include "Actuator.h"
#include "Clutch.h"
#include "Engine.h"

Demo_ECMSD::Demo_ECMSD()
{
  init();
}

Demo_ECMSD::~Demo_ECMSD()
{
 clean();
}

void Demo_ECMSD::init()
{


aMass = new CMass();
aMass->AddRef();
aMass->velocity = 0.0;
aMass->J = 5.0;

aSpring = new CSpring();
aSpring->AddRef();
aSpring->Ks = 160.0;
aSpring->ddTorque = 0.0;
aSpring->dTorque = 0.0;

Damper = new CDamper();
Damper->AddRef();
Damper->Kd = 1000.0;
Damper->velocity = 0.0;

Car = new Vehicle5();
Car->AddRef();
Car->wheelSpeed = 0.0;
Car->speed = 0.0;
Car->finalDriveRatio = 3.23;
Car->wheelRadius = 1.0;
Car->vehicleInertia = 115.49;
Car->wheelFrictionDrag = 40.0;
Car->aerodynamicDrag = 0.02;

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

aEngine = new Engine();
aEngine->AddRef();
aEngine->RPM = 0.0;
aEngine->throttle = 20.0;
aEngine->inertia = 0.28;

}


void Demo_ECMSD::clean()
{

if (aMass)
{
  aMass->Release();
  aMass = NULL;
}
if (aSpring)
{
  aSpring->Release();
  aSpring = NULL;
}
if (Damper)
{
  Damper->Release();
  Damper = NULL;
}
if (Car)
{
  Car->Release();
  Car = NULL;
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
if (aEngine)
{
  aEngine->Release();
  aEngine = NULL;
}
}


void Demo_ECMSD::Save(FILE* fs)
{

aMass->Save(fs);
aSpring->Save(fs);
Damper->Save(fs);
Car->Save(fs);
aFC->Save(fs);
FC->Save(fs);
aEngine->Save(fs);
}


bool Demo_ECMSD::Load(FILE* fs)
{

if (! aMass->Load(fs) ) return false;
if (! aSpring->Load(fs) ) return false;
if (! Damper->Load(fs) ) return false;
if (! Car->Load(fs) ) return false;
if (! aFC->Load(fs) ) return false;
if (! FC->Load(fs) ) return false;
if (! aEngine->Load(fs) ) return false;

return true;
}


HRESULT Demo_ECMSD::GetAssociations(long** Assoc, long** Size, long* nSize)
{

long nAssoc;
long i;

/*
0  ADD_LOCAL_ESO(aMass)
1  ADD_LOCAL_ESO(aSpring)
2  ADD_LOCAL_ESO(Damper)
3  ADD_LOCAL_ESO(Car)
4  ADD_LOCAL_ESO(aFC)
5  ADD_LOCAL_ESO(FC)
6  ADD_LOCAL_ESO(aEngine)
*/

const long assoc[] =
{
  0, 1,      2, 1,  // aMass.n - Damper.p
  0, 1,      1, 0,  // aMass.n - aSpring.p
  5, 1,      0, 0,  // FC.n - aMass.p
  2, 0,      3, 0,  // Damper.n - Car.p
  1, 1,      3, 0,  // aSpring.n - Car.p
  4, 0,      5, 0,  // aFC.clutchConnector - FC.actuatorConnector
  6, 0,      5, 2,  // aEngine.n - FC.p
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
};

*nSize = sizeof(size) / sizeof(long);
nAssoc = sizeof(assoc) / sizeof(long);

*Size = new long[*nSize];
*Assoc = new long[nAssoc];

for (i = 0; i < *nSize; i++) (*Size)[i] = size[i];
for (i = 0; i < nAssoc; i++) (*Assoc)[i] = assoc[i];

return S_OK;
}


HRESULT Demo_ECMSD::InitEsos()
{

  ADD_LOCAL_ESO(aMass)
  ADD_LOCAL_ESO(aSpring)
  ADD_LOCAL_ESO(Damper)
  ADD_LOCAL_ESO(Car)
  ADD_LOCAL_ESO(aFC)
  ADD_LOCAL_ESO(FC)
  ADD_LOCAL_ESO(aEngine)

  return S_OK;
}


