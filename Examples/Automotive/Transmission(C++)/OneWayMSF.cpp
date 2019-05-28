// OneWayMSF.cpp: implementation of the COneWayMSF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OneWayMSF.h"
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

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COneWayMSF::COneWayMSF()
{
  A1 = new CSignalActuator();     
  J1 = new CMass();     
  AC1 = new Actuator();
  C1 = new Oneway_Clutch();
  J2 = new CMass();

  A1->AddRef();
  J1->AddRef();
  AC1->AddRef();
  C1->AddRef();
  J2->AddRef();
}

COneWayMSF::~COneWayMSF()
{
  A1->Release();
  J1->Release();
  AC1->Release();
  C1->Release();
  J2->Release();
}

HRESULT COneWayMSF::GetAssociations(long** Assoc, long** Size, long* nSize)
{
  long nAssoc;
  long i;

  /*
  0 ADD_LOCAL_ESO(A1)
  1 ADD_LOCAL_ESO(J1)
  2 ADD_LOCAL_ESO(AC1)
  3 ADD_LOCAL_ESO(C1)
  4 ADD_LOCAL_ESO(J2)
  */

  // code generated association constants
  const long size[] = 
  { 
    2, 2, 
    2, 2,
    2, 2,
    2, 2,
  };
  
  const long assoc[] = 
  { 
    0, 0,    1, 0, // A1 - J1
    1, 1,    3, 0, // J1 - C1
    3, 1,    4, 0, // C1 - J2
    2, 0,    3, 2, // AC1 - C1
 };

  *nSize = sizeof(size) / sizeof(long);
  nAssoc = sizeof(assoc) / sizeof(long);

  *Size = new long[*nSize];
  *Assoc = new long[nAssoc];

  for (i = 0; i < *nSize; i++) (*Size)[i] = size[i];
  for (i = 0; i < nAssoc; i++) (*Assoc)[i] = assoc[i];

  return S_OK;
}

HRESULT COneWayMSF::InitEsos()
{
  ADD_LOCAL_ESO(A1)
  ADD_LOCAL_ESO(J1)
  ADD_LOCAL_ESO(AC1)
  ADD_LOCAL_ESO(C1)
  ADD_LOCAL_ESO(J2)

  return S_OK;
}