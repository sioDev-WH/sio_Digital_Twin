// implementation for class demo1
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "demo1.h"
// includes
#include "Engine.h"
#include "Vehicle.h"
#include "CFrame.h"
#include "Actuator.h"
#include "Oneway_Clutch.h"
#include "Clutch.h"
#include "Ravigneaux.h"

demo1::demo1()
{
  init();
}

demo1::~demo1()
{
 clean();
}

void demo1::init()
{


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


void demo1::clean()
{

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


void demo1::Save(FILE* fs)
{

myEngine->Save(fs);
Car->Save(fs);
POCGround->Save(fs);
aPOC->Save(fs);
POC->Save(fs);
aFC->Save(fs);
FC->Save(fs);
GearBox->Save(fs);
}


bool demo1::Load(FILE* fs)
{

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


HRESULT demo1::GetAssociations(long** Assoc, long** Size, long* nSize)
{

long nAssoc;
long i;

const long assoc[] =
{
  0, 0,      6, 2,
  7, 3,      1, 0,
  4, 1,      7, 2,
  2, 0,      4, 2,
  3, 0,      4, 0,
  6, 1,      7, 0,
  5, 0,      6, 0,
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


HRESULT demo1::InitEsos()
{

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


