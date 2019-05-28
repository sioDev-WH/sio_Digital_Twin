/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: iDriveTrain
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\iDriveTrain.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "iDriveTrain.h"
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


//#[ ignore 
#define Application_iDriveTrain_iDriveTrain_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_GetAssociations_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_InitEsos_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_Load_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_Save_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_clean_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// iDriveTrain.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class iDriveTrain 



iDriveTrain::iDriveTrain() {
    NOTIFY_CONSTRUCTOR(iDriveTrain, iDriveTrain(), 0, Application_iDriveTrain_iDriveTrain_SERIALIZE);
    Car = NULL;
    DC = NULL;
    FC = NULL;
    IOC = NULL;
    OB = NULL;
    POC = NULL;
    aDC = NULL;
    aFC = NULL;
    aIOC = NULL;
    aOB = NULL;
    aPOC = NULL;
    gIOC = NULL;
    gOB = NULL;
    gPOC = NULL;
    itsEngine = NULL;
    itsGearbox = NULL;
    itsTC = NULL;
    //#[ operation iDriveTrain() 
    
    init();
    //#]
}

iDriveTrain::~iDriveTrain() {
    NOTIFY_DESTRUCTOR(~iDriveTrain, TRUE);
    //#[ operation ~iDriveTrain() 
    
    clean();
    //#]
    cleanUpRelations();
}

HRESULT iDriveTrain::GetAssociations(long**  Assoc, long**  Size, long*  nSize) {
    NOTIFY_OPERATION(GetAssociations, GetAssociations(long**,long**,long*), 0, Application_iDriveTrain_GetAssociations_SERIALIZE);
    //#[ operation GetAssociations(long**,long**,long*) 
    
    long nAssoc;
    long i;
    
    const long assoc[] =
    {
      12, 3,      0, 0,
      4, 0,      7, 0,
      5, 0,      16, 0,
      1, 0,      13, 0,
      3, 0,      10, 0,
      2, 0,      11, 0,
      15, 0,      13, 2,
      16, 1,      12, 0,
      6, 0,      7, 2,
      7, 1,      12, 2,
      13, 1,      12, 2,
      8, 0,      11, 2,
      9, 0,      10, 2,
      10, 1,      12, 1,
      11, 1,      12, 1,
      15, 0,      16, 2,
      14, 0,      15, 1,
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

HRESULT iDriveTrain::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, Application_iDriveTrain_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(Car)
      ADD_LOCAL_ESO(aDC)
      ADD_LOCAL_ESO(aOB)
      ADD_LOCAL_ESO(aIOC)
      ADD_LOCAL_ESO(aPOC)
      ADD_LOCAL_ESO(aFC)
      ADD_LOCAL_ESO(gPOC)
      ADD_LOCAL_ESO(POC)
      ADD_LOCAL_ESO(gOB)
      ADD_LOCAL_ESO(gIOC)
      ADD_LOCAL_ESO(IOC)
      ADD_LOCAL_ESO(OB)
      ADD_LOCAL_ESO(itsGearbox)
      ADD_LOCAL_ESO(DC)
      ADD_LOCAL_ESO(itsEngine)
      ADD_LOCAL_ESO(itsTC)
      ADD_LOCAL_ESO(FC)
    
      return S_OK;
    //#]
}

bool iDriveTrain::Load(FILE*  fs) {
    NOTIFY_OPERATION(Load, Load(FILE*), 0, Application_iDriveTrain_Load_SERIALIZE);
    //#[ operation Load(FILE*) 
    
    if (! Car->Load(fs) ) return false;
    if (! aDC->Load(fs) ) return false;
    if (! aOB->Load(fs) ) return false;
    if (! aIOC->Load(fs) ) return false;
    if (! aPOC->Load(fs) ) return false;
    if (! aFC->Load(fs) ) return false;
    if (! gPOC->Load(fs) ) return false;
    if (! POC->Load(fs) ) return false;
    if (! gOB->Load(fs) ) return false;
    if (! gIOC->Load(fs) ) return false;
    if (! IOC->Load(fs) ) return false;
    if (! OB->Load(fs) ) return false;
    if (! itsGearbox->Load(fs) ) return false;
    if (! DC->Load(fs) ) return false;
    if (! itsEngine->Load(fs) ) return false;
    if (! itsTC->Load(fs) ) return false;
    if (! FC->Load(fs) ) return false;
    
    return true;
    //#]
}

void iDriveTrain::Save(FILE*  fs) {
    NOTIFY_OPERATION(Save, Save(FILE*), 0, Application_iDriveTrain_Save_SERIALIZE);
    //#[ operation Save(FILE*) 
    
    Car->Save(fs);
    aDC->Save(fs);
    aOB->Save(fs);
    aIOC->Save(fs);
    aPOC->Save(fs);
    aFC->Save(fs);
    gPOC->Save(fs);
    POC->Save(fs);
    gOB->Save(fs);
    gIOC->Save(fs);
    IOC->Save(fs);
    OB->Save(fs);
    itsGearbox->Save(fs);
    DC->Save(fs);
    itsEngine->Save(fs);
    itsTC->Save(fs);
    FC->Save(fs);
    //#]
}

void iDriveTrain::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_iDriveTrain_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (Car)
    {
      Car->Release();
      Car = NULL;
    }
    if (aDC)
    {
      aDC->Release();
      aDC = NULL;
    }
    if (aOB)
    {
      aOB->Release();
      aOB = NULL;
    }
    if (aIOC)
    {
      aIOC->Release();
      aIOC = NULL;
    }
    if (aPOC)
    {
      aPOC->Release();
      aPOC = NULL;
    }
    if (aFC)
    {
      aFC->Release();
      aFC = NULL;
    }
    if (gPOC)
    {
      gPOC->Release();
      gPOC = NULL;
    }
    if (POC)
    {
      POC->Release();
      POC = NULL;
    }
    if (gOB)
    {
      gOB->Release();
      gOB = NULL;
    }
    if (gIOC)
    {
      gIOC->Release();
      gIOC = NULL;
    }
    if (IOC)
    {
      IOC->Release();
      IOC = NULL;
    }
    if (OB)
    {
      OB->Release();
      OB = NULL;
    }
    if (itsGearbox)
    {
      itsGearbox->Release();
      itsGearbox = NULL;
    }
    if (DC)
    {
      DC->Release();
      DC = NULL;
    }
    if (itsEngine)
    {
      itsEngine->Release();
      itsEngine = NULL;
    }
    if (itsTC)
    {
      itsTC->Release();
      itsTC = NULL;
    }
    if (FC)
    {
      FC->Release();
      FC = NULL;
    }
    //#]
}

void iDriveTrain::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_iDriveTrain_init_SERIALIZE);
    //#[ operation init() 
    
    
    Car = new Vehicle5();
    Car->AddRef();
    Car->wheelSpeed = 0.0;
    Car->speed = 0.0;
    Car->finalDriveRatio = 3.23;
    Car->wheelRadius = 1.0;
    Car->vehicleInertia = 115.49;
    Car->wheelFrictionDrag = 40.0;
    Car->aerodynamicDrag = 0.02;
    
    aDC = new Actuator();
    aDC->AddRef();
    aDC->shiftTime = 0.0;
    aDC->shiftPeriod = 0.5;
    aDC->rate = 30.5;
    aDC->tolerance = 0.001;
    aDC->pressureMax = 1000.0;
    
    aOB = new Actuator();
    aOB->AddRef();
    aOB->shiftTime = 0.0;
    aOB->shiftPeriod = 0.5;
    aOB->rate = 30.5;
    aOB->tolerance = 0.001;
    aOB->pressureMax = 1000.0;
    
    aIOC = new Actuator();
    aIOC->AddRef();
    aIOC->shiftTime = 0.0;
    aIOC->shiftPeriod = 0.5;
    aIOC->rate = 30.5;
    aIOC->tolerance = 0.001;
    aIOC->pressureMax = 1000.0;
    
    aPOC = new Actuator();
    aPOC->AddRef();
    aPOC->shiftTime = 0.0;
    aPOC->shiftPeriod = 0.5;
    aPOC->rate = 30.5;
    aPOC->tolerance = 0.001;
    aPOC->pressureMax = 1000.0;
    
    aFC = new Actuator();
    aFC->AddRef();
    aFC->shiftTime = 0.0;
    aFC->shiftPeriod = 0.5;
    aFC->rate = 30.5;
    aFC->tolerance = 0.001;
    aFC->pressureMax = 1000.0;
    
    gPOC = new CFrame();
    gPOC->AddRef();
    
    POC = new Oneway_Clutch();
    POC->AddRef();
    POC->direction = Direction_CLOCKWISE;
    POC->nSurfaces = 8;
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
    
    gOB = new CFrame();
    gOB->AddRef();
    
    gIOC = new CFrame();
    gIOC->AddRef();
    
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
    
    OB = new Band_Brake();
    OB->AddRef();
    OB->area = 0.075;
    OB->radius = 0.055;
    OB->relativeVelocity = 0.0;
    OB->cBreakfreeDisp = 0.001;
    OB->torqueRatio = 0.3;
    OB->damping = 100000.0;
    OB->displacement = 0.0;
    OB->ccBreakfreeDisp = 0.0;
    OB->pressureMax = 1000.0;
    OB->cBreakfreeDispMax = 0.01;
    OB->ccBreakfreeDispMax = 0.0;
    
    itsGearbox = new Ravigneaux();
    itsGearbox->AddRef();
    itsGearbox->pinionToPinionForce = 0.0;
    itsGearbox->ringToPinionForce = 0.0;
    itsGearbox->pinionToReverseForce = 0.0;
    itsGearbox->forwardToPinionForce = 0.0;
    
    DC = new Clutch();
    DC->AddRef();
    DC->nSurfaces = 10;
    DC->area = 0.0075;
    DC->radius = 0.055;
    DC->relativeVelocity = 0.0;
    DC->cBreakfreeDisp = 0.001;
    DC->torqueRatio = 0.3;
    DC->damping = 100000.0;
    DC->displacement = 0.0;
    DC->ccBreakfreeDisp = 0.001;
    DC->pressureMax = 1000.0;
    DC->cBreakfreeDispMax = 0.01;
    DC->ccBreakfreeDispMax = 0.01;
    
    itsEngine = new Engine();
    itsEngine->AddRef();
    itsEngine->RPM = 0.0;
    itsEngine->throttle = 20.0;
    itsEngine->inertia = 0.28;
    
    itsTC = new Torque_Converter();
    itsTC->AddRef();
    itsTC->turbineTorque = 0.0;
    itsTC->turbineSpeed = 0.0;
    itsTC->turbineInertia = 0.119;
    itsTC->impellerTorque = 0.0;
    itsTC->impellerSpeed = 0.0;
    itsTC->impellerInertia = 0.14;
    
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
    
    //#]
}

void iDriveTrain::cleanUpRelations() {
    if(Car != NULL)
        {
            NOTIFY_RELATION_CLEARED("Car");
            Car = NULL;
        }
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
    if(gIOC != NULL)
        {
            NOTIFY_RELATION_CLEARED("gIOC");
            gIOC = NULL;
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
    if(itsGearbox != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsGearbox");
            itsGearbox = NULL;
        }
    if(itsTC != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsTC");
            itsTC = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatediDriveTrain::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("Car", FALSE, TRUE);
    if(myReal->Car)
        aomsRelations->ADD_ITEM(myReal->Car);
    aomsRelations->addRelation("aDC", FALSE, TRUE);
    if(myReal->aDC)
        aomsRelations->ADD_ITEM(myReal->aDC);
    aomsRelations->addRelation("aOB", FALSE, TRUE);
    if(myReal->aOB)
        aomsRelations->ADD_ITEM(myReal->aOB);
    aomsRelations->addRelation("aIOC", FALSE, TRUE);
    if(myReal->aIOC)
        aomsRelations->ADD_ITEM(myReal->aIOC);
    aomsRelations->addRelation("aPOC", FALSE, TRUE);
    if(myReal->aPOC)
        aomsRelations->ADD_ITEM(myReal->aPOC);
    aomsRelations->addRelation("aFC", FALSE, TRUE);
    if(myReal->aFC)
        aomsRelations->ADD_ITEM(myReal->aFC);
    aomsRelations->addRelation("gPOC", FALSE, TRUE);
    if(myReal->gPOC)
        aomsRelations->ADD_ITEM(myReal->gPOC);
    aomsRelations->addRelation("POC", FALSE, TRUE);
    if(myReal->POC)
        aomsRelations->ADD_ITEM(myReal->POC);
    aomsRelations->addRelation("gOB", FALSE, TRUE);
    if(myReal->gOB)
        aomsRelations->ADD_ITEM(myReal->gOB);
    aomsRelations->addRelation("gIOC", FALSE, TRUE);
    if(myReal->gIOC)
        aomsRelations->ADD_ITEM(myReal->gIOC);
    aomsRelations->addRelation("IOC", FALSE, TRUE);
    if(myReal->IOC)
        aomsRelations->ADD_ITEM(myReal->IOC);
    aomsRelations->addRelation("OB", FALSE, TRUE);
    if(myReal->OB)
        aomsRelations->ADD_ITEM(myReal->OB);
    aomsRelations->addRelation("itsGearbox", FALSE, TRUE);
    if(myReal->itsGearbox)
        aomsRelations->ADD_ITEM(myReal->itsGearbox);
    aomsRelations->addRelation("DC", FALSE, TRUE);
    if(myReal->DC)
        aomsRelations->ADD_ITEM(myReal->DC);
    aomsRelations->addRelation("itsEngine", FALSE, TRUE);
    if(myReal->itsEngine)
        aomsRelations->ADD_ITEM(myReal->itsEngine);
    aomsRelations->addRelation("itsTC", FALSE, TRUE);
    if(myReal->itsTC)
        aomsRelations->ADD_ITEM(myReal->itsTC);
    aomsRelations->addRelation("FC", FALSE, TRUE);
    if(myReal->FC)
        aomsRelations->ADD_ITEM(myReal->FC);
}

IMPLEMENT_META(iDriveTrain, Application, FALSE, OMAnimatediDriveTrain)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\iDriveTrain.cpp
*********************************************************************/

