/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: TestDrivetrain01
//!	Generated Date	: Fri, 27, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrain01.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "TestDrivetrain01.h"
#include "Actuator.h"
#include "Band_Brake.h"
#include "CFrame.h"
#include "Clutch.h"
#include "Engine.h"
#include "Oneway_Clutch.h"
#include "Ravigneaux.h"
#include "Torque_Converter.h"
#include "Vehicle5.h"
#include "stdafx.h"
#include "OnUMLEso.h"

//## package Application 

//----------------------------------------------------------------------------
// TestDrivetrain01.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class TestDrivetrain01 



TestDrivetrain01::TestDrivetrain01() {
    DC = NULL;
    FC = NULL;
    IOC = NULL;
    LRB = NULL;
    OB = NULL;
    POC = NULL;
    RC = NULL;
    aDC = NULL;
    aFC = NULL;
    aIOC = NULL;
    aLRB = NULL;
    aOB = NULL;
    aPOC = NULL;
    aRC = NULL;
    gIOC = NULL;
    gLRB = NULL;
    gOB = NULL;
    gPOC = NULL;
    itsEngine = NULL;
    itsRavigneaux = NULL;
    itsTorqueConverter = NULL;
    itsVehicle = NULL;
    //#[ operation TestDrivetrain01() 
    
    init();
    //#]
}

TestDrivetrain01::~TestDrivetrain01() {
    //#[ operation ~TestDrivetrain01() 
    
    clean();
    //#]
    cleanUpRelations();
}

HRESULT TestDrivetrain01::GetAssociations(long**  Assoc, long**  Size, long*  nSize) {
    //#[ operation GetAssociations(long**,long**,long*) 
    
    long nAssoc;
    long i;
    
    const long assoc[] =
    {
      16, 0, 14, 2,		//itsTorqueConverter.turbine <==> FC.p
      16, 0, 1, 2,		//itsTorqueConverter.turbine <==> DC.p
      9, 0, 10, 2,		//gLRB.ground <==> LRB.p
      0, 1, 11, 2,		//POC.n <==> itsRavigneaux.Carrier
      1, 1, 11, 2,		//DC.n <==> itsRavigneaux.Carrier
      14, 1, 11, 0,		//FC.n <==> itsRavigneaux.ForwardSun
      11, 3, 18, 0,		//itsRavigneaux.Ring <==> itsVehicle.DriveWheels
      12, 0, 0, 2,		//gPOC.ground <==> POC.p
      5, 0, 6, 2,		//gOB.ground <==> OB.p
      2, 0, 1, 0,		//aDC.Pressure <==> DC.Actuator
      13, 0, 0, 0,		//aPOC.Pressure <==> POC.Actuator
      15, 0, 14, 0,		//aFC.Pressure <==> FC.Actuator
      7, 0, 6, 0,		//aOB.Pressure <==> OB.Actuator
      6, 1, 11, 1,		//OB.n <==> itsRavigneaux.ReverseSun
      3, 1, 11, 1,		//RC.n <==> itsRavigneaux.ReverseSun
      19, 1, 11, 1,		//IOC.n <==> itsRavigneaux.ReverseSun
      4, 0, 3, 0,		//aRC.Pressure <==> RC.Actuator
      16, 0, 3, 2,		//itsTorqueConverter.turbine <==> RC.p
      10, 1, 11, 0,		//LRB.n <==> itsRavigneaux.ForwardSun
      8, 0, 10, 0,		//aLRB.Pressure <==> LRB.Actuator
      17, 0, 16, 1,		//itsEngine.n <==> itsTorqueConverter.impeller
      21, 0, 19, 0,		//aIOC.Pressure <==> IOC.Actuator
      20, 0, 19, 2,		//gIOC.ground <==> IOC.p
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
    //#]
}

HRESULT TestDrivetrain01::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(POC)
      ADD_LOCAL_ESO(DC)
      ADD_LOCAL_ESO(aDC)
      ADD_LOCAL_ESO(RC)
      ADD_LOCAL_ESO(aRC)
      ADD_LOCAL_ESO(gOB)
      ADD_LOCAL_ESO(OB)
      ADD_LOCAL_ESO(aOB)
      ADD_LOCAL_ESO(aLRB)
      ADD_LOCAL_ESO(gLRB)
      ADD_LOCAL_ESO(LRB)
      ADD_LOCAL_ESO(itsRavigneaux)
      ADD_LOCAL_ESO(gPOC)
      ADD_LOCAL_ESO(aPOC)
      ADD_LOCAL_ESO(FC)
      ADD_LOCAL_ESO(aFC)
      ADD_LOCAL_ESO(itsTorqueConverter)
      ADD_LOCAL_ESO(itsEngine)
      ADD_LOCAL_ESO(itsVehicle)
      ADD_LOCAL_ESO(IOC)
      ADD_LOCAL_ESO(gIOC)
      ADD_LOCAL_ESO(aIOC)
    
      return S_OK;
    //#]
}

bool TestDrivetrain01::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
    
    if (! POC->Load(fs) ) return false;
    if (! DC->Load(fs) ) return false;
    if (! aDC->Load(fs) ) return false;
    if (! RC->Load(fs) ) return false;
    if (! aRC->Load(fs) ) return false;
    if (! gOB->Load(fs) ) return false;
    if (! OB->Load(fs) ) return false;
    if (! aOB->Load(fs) ) return false;
    if (! aLRB->Load(fs) ) return false;
    if (! gLRB->Load(fs) ) return false;
    if (! LRB->Load(fs) ) return false;
    if (! itsRavigneaux->Load(fs) ) return false;
    if (! gPOC->Load(fs) ) return false;
    if (! aPOC->Load(fs) ) return false;
    if (! FC->Load(fs) ) return false;
    if (! aFC->Load(fs) ) return false;
    if (! itsTorqueConverter->Load(fs) ) return false;
    if (! itsEngine->Load(fs) ) return false;
    if (! itsVehicle->Load(fs) ) return false;
    if (! IOC->Load(fs) ) return false;
    if (! gIOC->Load(fs) ) return false;
    if (! aIOC->Load(fs) ) return false;
    
    return true;
    //#]
}

void TestDrivetrain01::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
    
    POC->Save(fs);
    DC->Save(fs);
    aDC->Save(fs);
    RC->Save(fs);
    aRC->Save(fs);
    gOB->Save(fs);
    OB->Save(fs);
    aOB->Save(fs);
    aLRB->Save(fs);
    gLRB->Save(fs);
    LRB->Save(fs);
    itsRavigneaux->Save(fs);
    gPOC->Save(fs);
    aPOC->Save(fs);
    FC->Save(fs);
    aFC->Save(fs);
    itsTorqueConverter->Save(fs);
    itsEngine->Save(fs);
    itsVehicle->Save(fs);
    IOC->Save(fs);
    gIOC->Save(fs);
    aIOC->Save(fs);
    //#]
}

void TestDrivetrain01::clean() {
    //#[ operation clean() 
    
    if (POC)
    {
      POC->Release();
      POC = NULL;
    }
    if (DC)
    {
      DC->Release();
      DC = NULL;
    }
    if (aDC)
    {
      aDC->Release();
      aDC = NULL;
    }
    if (RC)
    {
      RC->Release();
      RC = NULL;
    }
    if (aRC)
    {
      aRC->Release();
      aRC = NULL;
    }
    if (gOB)
    {
      gOB->Release();
      gOB = NULL;
    }
    if (OB)
    {
      OB->Release();
      OB = NULL;
    }
    if (aOB)
    {
      aOB->Release();
      aOB = NULL;
    }
    if (aLRB)
    {
      aLRB->Release();
      aLRB = NULL;
    }
    if (gLRB)
    {
      gLRB->Release();
      gLRB = NULL;
    }
    if (LRB)
    {
      LRB->Release();
      LRB = NULL;
    }
    if (itsRavigneaux)
    {
      itsRavigneaux->Release();
      itsRavigneaux = NULL;
    }
    if (gPOC)
    {
      gPOC->Release();
      gPOC = NULL;
    }
    if (aPOC)
    {
      aPOC->Release();
      aPOC = NULL;
    }
    if (FC)
    {
      FC->Release();
      FC = NULL;
    }
    if (aFC)
    {
      aFC->Release();
      aFC = NULL;
    }
    if (itsTorqueConverter)
    {
      itsTorqueConverter->Release();
      itsTorqueConverter = NULL;
    }
    if (itsEngine)
    {
      itsEngine->Release();
      itsEngine = NULL;
    }
    if (itsVehicle)
    {
      itsVehicle->Release();
      itsVehicle = NULL;
    }
    if (IOC)
    {
      IOC->Release();
      IOC = NULL;
    }
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
    //#]
}

void TestDrivetrain01::init() {
    //#[ operation init() 
    
    
    POC = new Oneway_Clutch();
    POC->AddRef();
    
    POC->relativeVelocity = 0.0;
    POC->cBreakfreeDisp = 1.0e-3;
    POC->displacement = 0.0;
    POC->ccBreakfreeDisp = 0.0;
    POC->area = 0.0075;
    POC->radius = 0.055;
    POC->torqueRatio = 0.3;
    POC->damping = 1.0e5;
    POC->pressureMax = 1.0e3;
    POC->cBreakfreeDispMax = 1.0e-2;
    POC->ccBreakfreeDispMax = 0.0;
    POC->direction = Direction_CLOCKWISE;
    POC->nSurfaces = 8;
    POC->ccOilDisp = 0.0;
    POC->cOilDisp = 1.0e-4;
    
    DC = new Clutch();
    DC->AddRef();
    
    DC->relativeVelocity = 0.0;
    DC->cBreakfreeDisp = 1.0e-3;
    DC->displacement = 0.0;
    DC->ccBreakfreeDisp = 1.0e-3;
    DC->area = 0.0075;
    DC->radius = 0.055;
    DC->torqueRatio = 0.3;
    DC->damping = 1.0e5;
    DC->pressureMax = 1.0e3;
    DC->cBreakfreeDispMax = 1.0e-2;
    DC->ccBreakfreeDispMax = 1.0e-2;
    DC->nSurfaces = 10;
    DC->ccOilDisp = 1.0e-4;
    DC->cOilDisp = 1.0e-4;
    
    aDC = new Actuator();
    aDC->AddRef();
    
    aDC->shiftTime = 0.0;
    aDC->shiftPeriod = 0.5;
    aDC->rate = 30.5;
    aDC->tolerance = 1.0e-3;
    aDC->pressureMax = 1.0e3;
    
    RC = new Clutch();
    RC->AddRef();
    
    RC->relativeVelocity = 0.0;
    RC->cBreakfreeDisp = 1.0e-3;
    RC->displacement = 0.0;
    RC->ccBreakfreeDisp = 1.0e-3;
    RC->area = 0.0075;
    RC->radius = 0.055;
    RC->torqueRatio = 0.3;
    RC->damping = 1.0e5;
    RC->pressureMax = 1.0e3;
    RC->cBreakfreeDispMax = 1.0e-2;
    RC->ccBreakfreeDispMax = 1.0e-2;
    RC->nSurfaces = 10;
    RC->ccOilDisp = 1.0e-4;
    RC->cOilDisp = 1.0e-4;
    
    aRC = new Actuator();
    aRC->AddRef();
    
    aRC->shiftTime = 0.0;
    aRC->shiftPeriod = 0.5;
    aRC->rate = 30.5;
    aRC->tolerance = 1.0e-3;
    aRC->pressureMax = 1.0e3;
    
    gOB = new CFrame();
    gOB->AddRef();
    
    
    OB = new Band_Brake();
    OB->AddRef();
    
    OB->relativeVelocity = 0.0;
    OB->cBreakfreeDisp = 1.0e-3;
    OB->displacement = 0.0;
    OB->ccBreakfreeDisp = 1.0e-3;
    OB->wrapAngle = 6.0;
    OB->area = 0.075;
    OB->radius = 0.055;
    OB->torqueRatio = 0.3;
    OB->damping = 1.0e5;
    OB->pressureMax = 1.0e3;
    OB->cBreakfreeDispMax = 1.0e-2;
    OB->ccBreakfreeDispMax = 1.0e-2;
    OB->ccOilDisp = 1.0e-4;
    OB->cOilDisp = 1.0e-4;
    
    aOB = new Actuator();
    aOB->AddRef();
    
    aOB->shiftTime = 0.0;
    aOB->shiftPeriod = 0.5;
    aOB->rate = 30.5;
    aOB->tolerance = 1.0e-3;
    aOB->pressureMax = 1.0e3;
    
    aLRB = new Actuator();
    aLRB->AddRef();
    
    aLRB->shiftTime = 0.0;
    aLRB->shiftPeriod = 0.5;
    aLRB->rate = 30.5;
    aLRB->tolerance = 1.0e-3;
    aLRB->pressureMax = 1.0e3;
    
    gLRB = new CFrame();
    gLRB->AddRef();
    
    
    LRB = new Band_Brake();
    LRB->AddRef();
    
    LRB->relativeVelocity = 0.0;
    LRB->cBreakfreeDisp = 1.0e-3;
    LRB->displacement = 0.0;
    LRB->ccBreakfreeDisp = 1.0e-3;
    LRB->wrapAngle = 6.0;
    LRB->area = 0.075;
    LRB->radius = 0.055;
    LRB->torqueRatio = 0.3;
    LRB->damping = 1.0e5;
    LRB->pressureMax = 1.0e3;
    LRB->cBreakfreeDispMax = 1.0e-2;
    LRB->ccBreakfreeDispMax = 1.0e-2;
    LRB->ccOilDisp = 1.0e-4;
    LRB->cOilDisp = 1.0e-4;
    
    itsRavigneaux = new Ravigneaux();
    itsRavigneaux->AddRef();
    
    
    gPOC = new CFrame();
    gPOC->AddRef();
    
    
    aPOC = new Actuator();
    aPOC->AddRef();
    
    aPOC->shiftTime = 0.0;
    aPOC->shiftPeriod = 0.5;
    aPOC->rate = 30.5;
    aPOC->tolerance = 1.0e-3;
    aPOC->pressureMax = 1.0e3;
    
    FC = new Clutch();
    FC->AddRef();
    
    FC->relativeVelocity = 0.0;
    FC->cBreakfreeDisp = 1.0e-3;
    FC->displacement = 0.0;
    FC->ccBreakfreeDisp = 1.0e-3;
    FC->area = 0.0075;
    FC->radius = 0.055;
    FC->torqueRatio = 0.3;
    FC->damping = 1.0e5;
    FC->pressureMax = 1.0e3;
    FC->cBreakfreeDispMax = 1.0e-2;
    FC->ccBreakfreeDispMax = 1.0e-2;
    FC->nSurfaces = 10;
    FC->ccOilDisp = 1.0e-4;
    FC->cOilDisp = 1.0e-4;
    
    aFC = new Actuator();
    aFC->AddRef();
    
    aFC->shiftTime = 0.0;
    aFC->shiftPeriod = 0.5;
    aFC->rate = 30.5;
    aFC->tolerance = 1.0e-3;
    aFC->pressureMax = 1.0e3;
    
    itsTorqueConverter = new Torque_Converter();
    itsTorqueConverter->AddRef();
    
    itsTorqueConverter->turbineInertia = 0.119;
    itsTorqueConverter->impellerInertia = 0.14;
    
    itsEngine = new Engine();
    itsEngine->AddRef();
    
    
    itsVehicle = new Vehicle5();
    itsVehicle->AddRef();
    
    itsVehicle->finalDriveRatio = 3.23;
    itsVehicle->wheelRadius = 1.0;
    itsVehicle->vehicleInertia = 115.49014783486148281934742735621;
    itsVehicle->wheelFrictionDrag = 40.0;
    itsVehicle->aerodynamicDrag = 0.02;
    
    IOC = new Oneway_Clutch();
    IOC->AddRef();
    
    IOC->relativeVelocity = 0.0;
    IOC->cBreakfreeDisp = 1.0e-3;
    IOC->displacement = 0.0;
    IOC->ccBreakfreeDisp = 0.0;
    IOC->area = 0.0075;
    IOC->radius = 0.055;
    IOC->torqueRatio = 0.3;
    IOC->damping = 1.0e5;
    IOC->pressureMax = 1.0e3;
    IOC->cBreakfreeDispMax = 1.0e-2;
    IOC->ccBreakfreeDispMax = 0.0;
    IOC->direction = Direction_CLOCKWISE;
    IOC->nSurfaces = 8;
    IOC->ccOilDisp = 0.0;
    IOC->cOilDisp = 1.0e-4;
    
    gIOC = new CFrame();
    gIOC->AddRef();
    
    
    aIOC = new Actuator();
    aIOC->AddRef();
    
    aIOC->shiftTime = 0.0;
    aIOC->shiftPeriod = 0.5;
    aIOC->rate = 30.5;
    aIOC->tolerance = 1.0e-3;
    aIOC->pressureMax = 1.0e3;
    
    //#]
}

void TestDrivetrain01::cleanUpRelations() {
    if(DC != NULL)
        {
            NOTIFY_RELATION_CLEARED("DC");
            DC = NULL;
        }
    if(FC != NULL)
        {
            NOTIFY_RELATION_CLEARED("FC");
            FC = NULL;
        }
    if(IOC != NULL)
        {
            NOTIFY_RELATION_CLEARED("IOC");
            IOC = NULL;
        }
    if(LRB != NULL)
        {
            NOTIFY_RELATION_CLEARED("LRB");
            LRB = NULL;
        }
    if(OB != NULL)
        {
            NOTIFY_RELATION_CLEARED("OB");
            OB = NULL;
        }
    if(POC != NULL)
        {
            NOTIFY_RELATION_CLEARED("POC");
            POC = NULL;
        }
    if(RC != NULL)
        {
            NOTIFY_RELATION_CLEARED("RC");
            RC = NULL;
        }
    if(aDC != NULL)
        {
            NOTIFY_RELATION_CLEARED("aDC");
            aDC = NULL;
        }
    if(aFC != NULL)
        {
            NOTIFY_RELATION_CLEARED("aFC");
            aFC = NULL;
        }
    if(aIOC != NULL)
        {
            NOTIFY_RELATION_CLEARED("aIOC");
            aIOC = NULL;
        }
    if(aLRB != NULL)
        {
            NOTIFY_RELATION_CLEARED("aLRB");
            aLRB = NULL;
        }
    if(aOB != NULL)
        {
            NOTIFY_RELATION_CLEARED("aOB");
            aOB = NULL;
        }
    if(aPOC != NULL)
        {
            NOTIFY_RELATION_CLEARED("aPOC");
            aPOC = NULL;
        }
    if(aRC != NULL)
        {
            NOTIFY_RELATION_CLEARED("aRC");
            aRC = NULL;
        }
    if(gIOC != NULL)
        {
            NOTIFY_RELATION_CLEARED("gIOC");
            gIOC = NULL;
        }
    if(gLRB != NULL)
        {
            NOTIFY_RELATION_CLEARED("gLRB");
            gLRB = NULL;
        }
    if(gOB != NULL)
        {
            NOTIFY_RELATION_CLEARED("gOB");
            gOB = NULL;
        }
    if(gPOC != NULL)
        {
            NOTIFY_RELATION_CLEARED("gPOC");
            gPOC = NULL;
        }
    if(itsEngine != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsEngine");
            itsEngine = NULL;
        }
    if(itsRavigneaux != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsRavigneaux");
            itsRavigneaux = NULL;
        }
    if(itsTorqueConverter != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsTorqueConverter");
            itsTorqueConverter = NULL;
        }
    if(itsVehicle != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsVehicle");
            itsVehicle = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedTestDrivetrain01::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("POC", FALSE, TRUE);
    if(myReal->POC)
        aomsRelations->ADD_ITEM(myReal->POC);
    aomsRelations->addRelation("DC", FALSE, TRUE);
    if(myReal->DC)
        aomsRelations->ADD_ITEM(myReal->DC);
    aomsRelations->addRelation("aDC", FALSE, TRUE);
    if(myReal->aDC)
        aomsRelations->ADD_ITEM(myReal->aDC);
    aomsRelations->addRelation("RC", FALSE, TRUE);
    if(myReal->RC)
        aomsRelations->ADD_ITEM(myReal->RC);
    aomsRelations->addRelation("aRC", FALSE, TRUE);
    if(myReal->aRC)
        aomsRelations->ADD_ITEM(myReal->aRC);
    aomsRelations->addRelation("gOB", FALSE, TRUE);
    if(myReal->gOB)
        aomsRelations->ADD_ITEM(myReal->gOB);
    aomsRelations->addRelation("OB", FALSE, TRUE);
    if(myReal->OB)
        aomsRelations->ADD_ITEM(myReal->OB);
    aomsRelations->addRelation("aOB", FALSE, TRUE);
    if(myReal->aOB)
        aomsRelations->ADD_ITEM(myReal->aOB);
    aomsRelations->addRelation("aLRB", FALSE, TRUE);
    if(myReal->aLRB)
        aomsRelations->ADD_ITEM(myReal->aLRB);
    aomsRelations->addRelation("gLRB", FALSE, TRUE);
    if(myReal->gLRB)
        aomsRelations->ADD_ITEM(myReal->gLRB);
    aomsRelations->addRelation("LRB", FALSE, TRUE);
    if(myReal->LRB)
        aomsRelations->ADD_ITEM(myReal->LRB);
    aomsRelations->addRelation("itsRavigneaux", FALSE, TRUE);
    if(myReal->itsRavigneaux)
        aomsRelations->ADD_ITEM(myReal->itsRavigneaux);
    aomsRelations->addRelation("gPOC", FALSE, TRUE);
    if(myReal->gPOC)
        aomsRelations->ADD_ITEM(myReal->gPOC);
    aomsRelations->addRelation("aPOC", FALSE, TRUE);
    if(myReal->aPOC)
        aomsRelations->ADD_ITEM(myReal->aPOC);
    aomsRelations->addRelation("FC", FALSE, TRUE);
    if(myReal->FC)
        aomsRelations->ADD_ITEM(myReal->FC);
    aomsRelations->addRelation("aFC", FALSE, TRUE);
    if(myReal->aFC)
        aomsRelations->ADD_ITEM(myReal->aFC);
    aomsRelations->addRelation("itsTorqueConverter", FALSE, TRUE);
    if(myReal->itsTorqueConverter)
        aomsRelations->ADD_ITEM(myReal->itsTorqueConverter);
    aomsRelations->addRelation("itsEngine", FALSE, TRUE);
    if(myReal->itsEngine)
        aomsRelations->ADD_ITEM(myReal->itsEngine);
    aomsRelations->addRelation("itsVehicle", FALSE, TRUE);
    if(myReal->itsVehicle)
        aomsRelations->ADD_ITEM(myReal->itsVehicle);
    aomsRelations->addRelation("IOC", FALSE, TRUE);
    if(myReal->IOC)
        aomsRelations->ADD_ITEM(myReal->IOC);
    aomsRelations->addRelation("gIOC", FALSE, TRUE);
    if(myReal->gIOC)
        aomsRelations->ADD_ITEM(myReal->gIOC);
    aomsRelations->addRelation("aIOC", FALSE, TRUE);
    if(myReal->aIOC)
        aomsRelations->ADD_ITEM(myReal->aIOC);
}

IMPLEMENT_META(TestDrivetrain01, Application, FALSE, OMAnimatedTestDrivetrain01)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrain01.cpp
*********************************************************************/

