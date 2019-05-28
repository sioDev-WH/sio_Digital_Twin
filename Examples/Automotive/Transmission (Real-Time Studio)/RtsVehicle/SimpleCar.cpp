// implementation for class SimpleCar
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "SimpleCar.h"
// includes
#include "Engine.h"
#include "simpleGearbox.h"
#include "Vehicle.h"

SimpleCar::SimpleCar()
{
  init();
}

SimpleCar::~SimpleCar()
{
 clean();
}

void SimpleCar::init()
{


Engine_WS = new Engine();
Engine_WS->AddRef();
Engine_WS->RPM = 0.0;
Engine_WS->throttle = 20.0;
Engine_WS->inertia = 0.28;

Gearbox = new simpleGearbox();
Gearbox->AddRef();
Gearbox->tolerance = 0.001;
Gearbox->shiftPeriod = 0.5;
Gearbox->shiftTime = 0.0;
Gearbox->ratio = 0.0;

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

}


void SimpleCar::clean()
{

if (Engine_WS)
{
  Engine_WS->Release();
  Engine_WS = NULL;
}
if (Gearbox)
{
  Gearbox->Release();
  Gearbox = NULL;
}
if (Car)
{
  Car->Release();
  Car = NULL;
}
}


void SimpleCar::Save(FILE* fs)
{

Engine_WS->Save(fs);
Gearbox->Save(fs);
Car->Save(fs);
}


bool SimpleCar::Load(FILE* fs)
{

if (! Engine_WS->Load(fs) ) return false;
if (! Gearbox->Load(fs) ) return false;
if (! Car->Load(fs) ) return false;

return true;
}


HRESULT SimpleCar::GetAssociations(long** Assoc, long** Size, long* nSize)
{

long nAssoc;
long i;

const long assoc[] =
{
  1, 1,      2, 0,
  0, 0,      1, 0,
};

const long size[] =
{
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


HRESULT SimpleCar::InitEsos()
{

  ADD_LOCAL_ESO(Engine_WS)
  ADD_LOCAL_ESO(Gearbox)
  ADD_LOCAL_ESO(Car)

  return S_OK;
}


