// implementation for class Demo_ECM
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "Demo_ECM.h"
// includes
#include "Actuator.h"
#include "Clutch.h"
#include "Engine.h"
#include "CMass.h"

Demo_ECM::Demo_ECM()
{
  init();
}

Demo_ECM::~Demo_ECM()
{
 clean();
}

void Demo_ECM::init()
{


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

aMass = new CMass();
aMass->AddRef();
aMass->velocity = 0.0;
aMass->J = 100.0;

}


void Demo_ECM::clean()
{

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
if (aMass)
{
  aMass->Release();
  aMass = NULL;
}
}


void Demo_ECM::Save(FILE* fs)
{

aFC->Save(fs);
FC->Save(fs);
aEngine->Save(fs);
aMass->Save(fs);
}


bool Demo_ECM::Load(FILE* fs)
{

if (! aFC->Load(fs) ) return false;
if (! FC->Load(fs) ) return false;
if (! aEngine->Load(fs) ) return false;
if (! aMass->Load(fs) ) return false;

return true;
}


HRESULT Demo_ECM::GetAssociations(long** Assoc, long** Size, long* nSize)
{

long nAssoc;
long i;

const long assoc[] =
{
  1, 1,      3, 0,
  0, 0,      1, 0,
  2, 0,      1, 2,
};

const long size[] =
{
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


HRESULT Demo_ECM::InitEsos()
{

  ADD_LOCAL_ESO(aFC)
  ADD_LOCAL_ESO(FC)
  ADD_LOCAL_ESO(aEngine)
  ADD_LOCAL_ESO(aMass)

  return S_OK;
}


