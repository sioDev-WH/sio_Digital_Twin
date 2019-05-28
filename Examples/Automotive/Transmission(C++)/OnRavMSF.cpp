// OnRavMSF.cpp: implementation of the COnRavMSF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OnRavMSF.h"
#include "SignalActuator.h"
#include "RigidConnector.h"
#include "Mass.h"
#include "Spring.h"
#include "Damper.h"
#include "Clutch.h"
#include "ActuatorClutchConnector.h"
#include "Actuator.h"
#include "GearRatio.h"
#include "Oneway_Clutch.h"
#include "Frame.h"
#include "Ravigneaux.h"
#include "Engine.h"
#include "Torque_Converter.h"
#include "Band_Break.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COnRavMSF::COnRavMSF()
{
  A1 = new CSignalActuator(); 
  J1 = new CMass();
  F1 = new CFrame();
  aBreak = new Actuator();
  cBreak = new Band_Break();
  //cBreak = new Clutch();
  R1 = new Ravigneaux();
  J2 = new CMass();

  A1->AddRef();
  J1->AddRef();
  F1->AddRef();
  aBreak->AddRef();
  cBreak->AddRef();
  R1->AddRef();
  J2->AddRef();

  J1->J = 1.0;
  J2->J = 100.0;
}

COnRavMSF::~COnRavMSF()
{
  A1->Release();
  J1->Release();
  F1->Release();
  aBreak->Release();
  cBreak->Release();
  R1->Release();
  J2->Release();
}

HRESULT COnRavMSF::GetAssociations(long** Assoc, long** Size, long* nSize)
{
  long nAssoc;
  long i;

/* Ravigneaux connectors
  0 ADD_LOCAL_ESO(ifSun)
  1 ADD_LOCAL_ESO(irSun)
  2 ADD_LOCAL_ESO(iCoupler)
  3 ADD_LOCAL_ESO(oRing)
*/  

/*
  0 ADD_LOCAL_ESO(A1)
  1 ADD_LOCAL_ESO(J1)
  2 ADD_LOCAL_ESO(F1)
  3 ADD_LOCAL_ESO(aBreak)
  4 ADD_LOCAL_ESO(cBreak)
  5 ADD_LOCAL_ESO(R1)
  6 ADD_LOCAL_ESO(J2)
*/

// first
  const long size[] = 
  { 
    2, 2,
    2, 2,
    2, 2,
    2, 2,
    2, 2,
    2, 2,
  };
  
  const long assoc[] = 
  { 
    0, 0,    1, 0,
    1, 1,    5, 0,
    2, 0,    4, 1,
    3, 0,    4, 2,
    4, 0,    5, 2,
    5, 3,    6, 0,
  };

  *nSize = sizeof(size) / sizeof(long);
  nAssoc = sizeof(assoc) / sizeof(long);

  *Size = new long[*nSize];
  *Assoc = new long[nAssoc];

  for (i = 0; i < *nSize; i++) (*Size)[i] = size[i];
  for (i = 0; i < nAssoc; i++) (*Assoc)[i] = assoc[i];

  return S_OK;
}

HRESULT COnRavMSF::InitEsos()
{
  ADD_LOCAL_ESO(A1)
  ADD_LOCAL_ESO(J1)
  ADD_LOCAL_ESO(F1)
  ADD_LOCAL_ESO(aBreak)
  ADD_LOCAL_ESO(cBreak)
  ADD_LOCAL_ESO(R1)
  ADD_LOCAL_ESO(J2)

  return S_OK;
}

