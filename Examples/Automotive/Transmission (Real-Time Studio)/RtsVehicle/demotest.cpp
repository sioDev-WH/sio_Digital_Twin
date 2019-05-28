// implementation for class demotest
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "demotest.h"
// includes
#include "CFrame.h"
#include "Actuator.h"
#include "Oneway_Clutch.h"
#include "Engine.h"
#include "Vehicle.h"
#include "Clutch.h"
#include "Ravigneaux.h"

demotest::demotest()
{
  init();
}

demotest::~demotest()
{
 clean();
}

void demotest::init()
{


gIOC = new CFrame();
gIOC->AddRef();

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
IOC->cBreakfreeDisp = 0.0;
IOC->torqueRatio = 0.3;
IOC->damping = 100000.0;
IOC->displacement = 0.0;
IOC->ccBreakfreeDisp = 0.0;
IOC->pressureMax = 1000.0;
IOC->cBreakfreeDispMax = 0.01;
IOC->ccBreakfreeDispMax = 0.0;

myEngine = new Engine();
myEngine->AddRef();

Car = new Vehicle();
Car->AddRef();

POCGround = new CFrame();
POCGround->AddRef();

aPOC = new Actuator();
aPOC->AddRef();

POC = new Oneway_Clutch();
POC->AddRef();

aFC = new Actuator();
aFC->AddRef();

FC = new Clutch();
FC->AddRef();

GearBox = new Ravigneaux();
GearBox->AddRef();

}


void demotest::clean()
{

if (gIOC)
{
  gIOC->Release();
  gIOC = NULL;
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


void demotest::Save(FILE* fs)
{

gIOC->Save(fs);
aIOC->Save(fs);
IOC->Save(fs);
myEngine->Save(fs);
Car->Save(fs);
POCGround->Save(fs);
aPOC->Save(fs);
POC->Save(fs);
aFC->Save(fs);
FC->Save(fs);
GearBox->Save(fs);
}


bool demotest::Load(FILE* fs)
{

if (! gIOC->Load(fs) ) return false;
if (! aIOC->Load(fs) ) return false;
if (! IOC->Load(fs) ) return false;
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


HRESULT demotest::GetAssociations(long** Assoc, long** Size, long* nSize)
{

long nAssoc;
long i;

const long assoc[] =
{
  2, 1,      10, 1,
  0, 0,      2, 2,
  1, 0,      2, 0,
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


HRESULT demotest::InitEsos()
{

  ADD_LOCAL_ESO(gIOC)
  ADD_LOCAL_ESO(aIOC)
  ADD_LOCAL_ESO(IOC)
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


