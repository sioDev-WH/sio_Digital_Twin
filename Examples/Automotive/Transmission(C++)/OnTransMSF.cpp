// OnTransMSF.cpp: implementation of the COnTransMSF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OnTransMSF.h"
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
#include "Engine.h"
#include "Torque_Converter.h"
#include "Ravigneaux.h"
#include "Vehicle.h"
#include "Band_Break.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COnTransMSF::COnTransMSF()
{
  frame = new CFrame();
  engine = new Engine();
  TC = new Torque_Converter();
  aTCC = new Actuator();
  cTCC = new Clutch();

  aIC = new Actuator();
  cIC = new Clutch();
  ICMass = new CMass();
  aIOC = new Actuator();
  cIOC = new Oneway_Clutch();
  aRC = new Actuator();
  cRC = new Clutch();
  aOB = new Actuator(); 
  cOB = new Band_Break();

  aFC = new Actuator();
  cFC = new Clutch();

  aDC = new Actuator();
  cDC = new Clutch();
  aPOC = new Actuator();
  cPOC = new Oneway_Clutch();
  aLRB = new Actuator();
  cLRB = new Band_Break();

  gearbox = new Ravigneaux();
  vehicle = new Vehicle();

  frame->AddRef();
  engine->AddRef();
  TC->AddRef();
  aTCC->AddRef();
  cTCC->AddRef();

  aIC->AddRef();
  cIC->AddRef();
  ICMass->AddRef();
  aIOC->AddRef();
  cIOC->AddRef();
  aRC->AddRef();
  cRC->AddRef();
  aOB->AddRef();
  cOB->AddRef();

  aFC->AddRef();
  cFC->AddRef();

  aDC->AddRef();
  cDC->AddRef();
  aPOC->AddRef();
  cPOC->AddRef();
  aLRB->AddRef();
  cLRB->AddRef();

  gearbox->AddRef();
  vehicle->AddRef();

}

COnTransMSF::~COnTransMSF()
{
  frame->Release();
  engine->Release();
  TC->Release();
  aTCC->Release();
  cTCC->Release();

  aIC->Release();
  cIC->Release();
  ICMass->Release();
  aIOC->Release();
  cIOC->Release();
  aRC->Release();
  cRC->Release();
  aOB->Release();
  cOB->Release();

  aFC->Release();
  cFC->Release();

  aDC->Release();
  cDC->Release();
  aPOC->Release();
  cPOC->Release();
  aLRB->Release();
  cLRB->Release();

  gearbox->Release();
  vehicle->Release();
}

HRESULT COnTransMSF::GetAssociations(long** Assoc, long** Size, long* nSize)
{
  long nAssoc;
  long i;

  /*
  0 ADD_LOCAL_ESO(frame) 

  1 ADD_LOCAL_ESO(engine)

  2 ADD_LOCAL_ESO(TC)  
  3 ADD_LOCAL_ESO(aTCC) 
  4 ADD_LOCAL_ESO(cTCC) 

  5 ADD_LOCAL_ESO(aIC)
  6 ADD_LOCAL_ESO(cIC)
  7 ADD_LOCAL_ESO(ICMass)
  8 7 ADD_LOCAL_ESO(aIOC)
  9 8 ADD_LOCAL_ESO(cIOC)
  10 9 ADD_LOCAL_ESO(aRC)
  11 10 ADD_LOCAL_ESO(cRC)
  12 11 ADD_LOCAL_ESO(aOB)
  13 12 ADD_LOCAL_ESO(cOB)

  14 13 ADD_LOCAL_ESO(aFC)
  15 14 ADD_LOCAL_ESO(cFC)

  16 15 ADD_LOCAL_ESO(aDC)
  17 16 ADD_LOCAL_ESO(cDC)
  18 17 ADD_LOCAL_ESO(aPOC)
  19 18 ADD_LOCAL_ESO(cPOC)
  20 19 ADD_LOCAL_ESO(aLRB)
  21 20 ADD_LOCAL_ESO(cLRB)

  22 21 ADD_LOCAL_ESO(gearbox)
  23 22 ADD_LOCAL_ESO(vehicle)
  */





  // code generated association constants
  const long size[] = 
  { 
    2, 2,    // frame
    2, 2,
    2, 2,
    2, 2,

    2, 2,    // engine
    
    2, 2,    // TCC
    2, 2,
    2, 2,

    2, 2,    // TC
    2, 2,
    2, 2,

    2, 2,    // IC
    2, 2,

    2, 2,    // ICMass

    2, 2,    // IOC
    2, 2,

    2, 2,    // RC
    2, 2,

    2, 2,    // OB
    2, 2,

    2, 2,    // FC
    2, 2,

    2, 2,    // DC
    2, 2,

    2, 2,    // POC
    2, 2,

    2, 2,    // LRB
    2, 2,

    2, 2,    // gearbox
  };
  
  const long assoc[] = 
  { 
    0, 0,    6, 0,  // 0 ADD_LOCAL_ESO(frame) 
    0, 0,    13, 0, 
    0, 0,    19, 0,
    0, 0,    21, 0,

    1, 0,    2, 0,  // 1 ADD_LOCAL_ESO(engine)

    3, 0,    4, 2,  // 4 ADD_LOCAL_ESO(cTCC) 
    2, 0,    4, 0,
    2, 1,    4, 1,

    2, 1,    11, 0, // 2 ADD_LOCAL_ESO(TC)  
    2, 1,    15, 0,
    2, 1,    17, 0,

    5, 0,    6, 2,  // 6 ADD_LOCAL_ESO(cIC)
    6, 1,    7, 0, 

    7, 1,    9, 0,  // 7 ADD_LOCAL_ESO(ICMass)

    8, 0,    9, 2,  // 9 ADD_LOCAL_ESO(cIOC)
    9, 1,    22, 1,  

    10, 0,   11, 2, // 11 ADD_LOCAL_ESO(cRC)
    11, 1,   22, 1,

    12, 0,   13, 2, // 13 ADD_LOCAL_ESO(cOB)
    13, 1,   22, 1,

    14, 0,   15, 2, // 15 ADD_LOCAL_ESO(cFC)
    15, 1,   22, 0,

    16, 0,   17, 2, // 17 ADD_LOCAL_ESO(cDC)
    17, 1,   22, 2,

    18, 0,   19, 2, // 19 ADD_LOCAL_ESO(cPOC)
    19, 1,   22, 2,

    20, 0,   21, 2, // 21 ADD_LOCAL_ESO(cLRB)
    21, 1,   22, 2,
    
    22, 3,   23, 0, // 22 ADD_LOCAL_ESO(gearbox)
  };


/* Ravigneaux connectors
  0 ADD_LOCAL_ESO(ifSun)
  1 ADD_LOCAL_ESO(irSun)
  2 ADD_LOCAL_ESO(iCoupler)
  3 ADD_LOCAL_ESO(oRing)
*/  

  *nSize = sizeof(size) / sizeof(long);
  nAssoc = sizeof(assoc) / sizeof(long);

  *Size = new long[*nSize];
  *Assoc = new long[nAssoc];

  for (i = 0; i < *nSize; i++) (*Size)[i] = size[i];
  for (i = 0; i < nAssoc; i++) (*Assoc)[i] = assoc[i];

  return S_OK;
}

HRESULT COnTransMSF::InitEsos()
{

  ADD_LOCAL_ESO(frame)

  ADD_LOCAL_ESO(engine)

  ADD_LOCAL_ESO(TC)
  ADD_LOCAL_ESO(aTCC)
  ADD_LOCAL_ESO(cTCC)

  ADD_LOCAL_ESO(aIC)
  ADD_LOCAL_ESO(cIC)
  ADD_LOCAL_ESO(ICMass)
  ADD_LOCAL_ESO(aIOC)
  ADD_LOCAL_ESO(cIOC)
  ADD_LOCAL_ESO(aRC)
  ADD_LOCAL_ESO(cRC)
  ADD_LOCAL_ESO(aOB)
  ADD_LOCAL_ESO(cOB)

  ADD_LOCAL_ESO(aFC)
  ADD_LOCAL_ESO(cFC)

  ADD_LOCAL_ESO(aDC)
  ADD_LOCAL_ESO(cDC)
  ADD_LOCAL_ESO(aPOC)
  ADD_LOCAL_ESO(cPOC)
  ADD_LOCAL_ESO(aLRB)
  ADD_LOCAL_ESO(cLRB)

  ADD_LOCAL_ESO(gearbox)
  ADD_LOCAL_ESO(vehicle)

  return S_OK;
}