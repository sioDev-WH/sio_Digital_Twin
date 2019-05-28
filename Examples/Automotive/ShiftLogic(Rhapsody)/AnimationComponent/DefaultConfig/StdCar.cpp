/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: StdCar
//!	Generated Date	: Wed, 18, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\StdCar.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "StdCar.h"
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

//## package AppSimple 


//#[ ignore 
#define AppSimple_StdCar_aDC_Shift_SERIALIZE OM_NO_OP


#define AppSimple_StdCar_aFC_Shift_SERIALIZE OM_NO_OP


#define AppSimple_StdCar_aIOC_Shift_SERIALIZE OM_NO_OP


#define AppSimple_StdCar_aOB_Shift_SERIALIZE OM_NO_OP


#define AppSimple_StdCar_aPOC_Shift_SERIALIZE OM_NO_OP


#define AppSimple_StdCar_itsEngine_getRPM_SERIALIZE OM_NO_OP


#define AppSimple_StdCar_itsEngine_handle_Start_SERIALIZE OM_NO_OP


#define AppSimple_StdCar_itsEngine_handle_throttle_SERIALIZE OM_NO_OP


#define AppSimple_StdCar_itsVehicle_getSpeed_SERIALIZE OM_NO_OP


#define AppSimple_StdCar_itsVehicle_handle_brakePedal_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// StdCar.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class StdCar 



StdCar::StdCar() {
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
    itsTorqueConverter = NULL;
    itsVehicle = NULL;
    //#[ operation StdCar() 
    
    init();
    //#]
}

StdCar::~StdCar() {
    //#[ operation ~StdCar() 
    
    clean();
    //#]
    cleanUpRelations();
}

HRESULT StdCar::GetAssociations(long**  Assoc, long**  Size, long*  nSize) {
    //#[ operation GetAssociations(long**,long**,long*) 
    
    long nAssoc;
    long i;
    
    const long assoc[] =
    {
      0, 0, 3, 1,		//itsEngine.n <==> itsTorqueConverter.impeller
      12, 1, 5, 2,		//POC.n <==> itsGearbox.Carrier
      3, 0, 16, 2,		//itsTorqueConverter.turbine <==> FC.p
      3, 0, 15, 2,		//itsTorqueConverter.turbine <==> DC.p
      16, 1, 5, 0,		//FC.n <==> itsGearbox.ForwardSun
      15, 1, 5, 2,		//DC.n <==> itsGearbox.Carrier
      1, 0, 14, 2,		//gOB.ground <==> OB.p
      14, 1, 5, 1,		//OB.n <==> itsGearbox.ReverseSun
      13, 1, 5, 1,		//IOC.n <==> itsGearbox.ReverseSun
      5, 3, 4, 0,		//itsGearbox.Ring <==> itsVehicle.DriveWheels
      2, 0, 12, 2,		//gPOC.ground <==> POC.p
      6, 0, 12, 0,		//aPOC.Pressure <==> POC.Actuator
      7, 0, 16, 0,		//aFC.Pressure <==> FC.Actuator
      8, 0, 15, 0,		//aDC.Pressure <==> DC.Actuator
      9, 0, 14, 0,		//aOB.Pressure <==> OB.Actuator
      10, 0, 13, 0,		//aIOC.Pressure <==> IOC.Actuator
      11, 0, 13, 2,		//gIOC.ground <==> IOC.p
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

HRESULT StdCar::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(itsEngine)
      ADD_LOCAL_ESO(gOB)
      ADD_LOCAL_ESO(gPOC)
      ADD_LOCAL_ESO(itsTorqueConverter)
      ADD_LOCAL_ESO(itsVehicle)
      ADD_LOCAL_ESO(itsGearbox)
      ADD_LOCAL_ESO(aPOC)
      ADD_LOCAL_ESO(aFC)
      ADD_LOCAL_ESO(aDC)
      ADD_LOCAL_ESO(aOB)
      ADD_LOCAL_ESO(aIOC)
      ADD_LOCAL_ESO(gIOC)
      ADD_LOCAL_ESO(POC)
      ADD_LOCAL_ESO(IOC)
      ADD_LOCAL_ESO(OB)
      ADD_LOCAL_ESO(DC)
      ADD_LOCAL_ESO(FC)
    
      return S_OK;
    //#]
}

bool StdCar::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
    
    if (! itsEngine->Load(fs) ) return false;
    if (! gOB->Load(fs) ) return false;
    if (! gPOC->Load(fs) ) return false;
    if (! itsTorqueConverter->Load(fs) ) return false;
    if (! itsVehicle->Load(fs) ) return false;
    if (! itsGearbox->Load(fs) ) return false;
    if (! aPOC->Load(fs) ) return false;
    if (! aFC->Load(fs) ) return false;
    if (! aDC->Load(fs) ) return false;
    if (! aOB->Load(fs) ) return false;
    if (! aIOC->Load(fs) ) return false;
    if (! gIOC->Load(fs) ) return false;
    if (! POC->Load(fs) ) return false;
    if (! IOC->Load(fs) ) return false;
    if (! OB->Load(fs) ) return false;
    if (! DC->Load(fs) ) return false;
    if (! FC->Load(fs) ) return false;
    
    return true;
    //#]
}

void StdCar::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
    
    itsEngine->Save(fs);
    gOB->Save(fs);
    gPOC->Save(fs);
    itsTorqueConverter->Save(fs);
    itsVehicle->Save(fs);
    itsGearbox->Save(fs);
    aPOC->Save(fs);
    aFC->Save(fs);
    aDC->Save(fs);
    aOB->Save(fs);
    aIOC->Save(fs);
    gIOC->Save(fs);
    POC->Save(fs);
    IOC->Save(fs);
    OB->Save(fs);
    DC->Save(fs);
    FC->Save(fs);
    //#]
}

void StdCar::aDC_Shift(const double t, long * val) {
    NOTIFY_OPERATION(aDC_Shift, aDC_Shift(const double ,long * ), 0, AppSimple_StdCar_aDC_Shift_SERIALIZE);
    //#[ operation aDC_Shift(const double ,long * ) 
      aDC->handle_shiftEvent(t, val);
    //#]
}

void StdCar::aFC_Shift(const double t, long * val) {
    NOTIFY_OPERATION(aFC_Shift, aFC_Shift(const double ,long * ), 0, AppSimple_StdCar_aFC_Shift_SERIALIZE);
    //#[ operation aFC_Shift(const double ,long * ) 
      aFC->handle_shiftEvent(t, val);
    //#]
}

void StdCar::aIOC_Shift(const double t, long * val) {
    NOTIFY_OPERATION(aIOC_Shift, aIOC_Shift(const double ,long * ), 0, AppSimple_StdCar_aIOC_Shift_SERIALIZE);
    //#[ operation aIOC_Shift(const double ,long * ) 
      aIOC->handle_shiftEvent(t, val);
    //#]
}

void StdCar::aOB_Shift(const double t, long * val) {
    NOTIFY_OPERATION(aOB_Shift, aOB_Shift(const double ,long * ), 0, AppSimple_StdCar_aOB_Shift_SERIALIZE);
    //#[ operation aOB_Shift(const double ,long * ) 
      aOB->handle_shiftEvent(t, val);
    //#]
}

void StdCar::aPOC_Shift(const double t, long * val) {
    NOTIFY_OPERATION(aPOC_Shift, aPOC_Shift(const double ,long * ), 0, AppSimple_StdCar_aPOC_Shift_SERIALIZE);
    //#[ operation aPOC_Shift(const double ,long * ) 
      aPOC->handle_shiftEvent(t, val);
    //#]
}

void StdCar::clean() {
    //#[ operation clean() 
    
    if (itsEngine)
    {
      itsEngine->Release();
      itsEngine = NULL;
    }
    if (gOB)
    {
      gOB->Release();
      gOB = NULL;
    }
    if (gPOC)
    {
      gPOC->Release();
      gPOC = NULL;
    }
    if (itsTorqueConverter)
    {
      itsTorqueConverter->Release();
      itsTorqueConverter = NULL;
    }
    if (itsVehicle)
    {
      itsVehicle->Release();
      itsVehicle = NULL;
    }
    if (itsGearbox)
    {
      itsGearbox->Release();
      itsGearbox = NULL;
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
    if (gIOC)
    {
      gIOC->Release();
      gIOC = NULL;
    }
    if (POC)
    {
      POC->Release();
      POC = NULL;
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
    if (DC)
    {
      DC->Release();
      DC = NULL;
    }
    if (FC)
    {
      FC->Release();
      FC = NULL;
    }
    //#]
}

 StdCar::init() {
    //#[ operation init() 
    
    
    itsEngine = new Engine();
    itsEngine->AddRef();
    
    
    gOB = new CFrame();
    gOB->AddRef();
    
    
    gPOC = new CFrame();
    gPOC->AddRef();
    
    
    itsTorqueConverter = new Torque_Converter();
    itsTorqueConverter->AddRef();
    
    itsTorqueConverter->turbineInertia = 0.119;
    itsTorqueConverter->impellerInertia = 0.14;
    
    itsVehicle = new Vehicle5();
    itsVehicle->AddRef();
    
    itsVehicle->finalDriveRatio = 3.23;
    itsVehicle->wheelRadius = 1.0;
    itsVehicle->vehicleInertia = 115.49014783486148281934742735621;
    itsVehicle->wheelFrictionDrag = 40.0;
    itsVehicle->aerodynamicDrag = 0.02;
    
    itsGearbox = new Ravigneaux();
    itsGearbox->AddRef();
    
    
    aPOC = new Actuator();
    aPOC->AddRef();
    
    aPOC->shiftPeriod = 0.5;
    aPOC->rate = 30.5;
    aPOC->tolerance = 1.0e-3;
    aPOC->pressureMax = 1.0e3;
    
    aFC = new Actuator();
    aFC->AddRef();
    
    aFC->shiftPeriod = 0.5;
    aFC->rate = 30.5;
    aFC->tolerance = 1.0e-3;
    aFC->pressureMax = 1.0e3;
    
    aDC = new Actuator();
    aDC->AddRef();
    
    aDC->shiftTime = 0.0;
    aDC->shiftPeriod = 0.5;
    aDC->rate = 30.5;
    aDC->tolerance = 1.0e-3;
    aDC->pressureMax = 1.0e3;
    
    aOB = new Actuator();
    aOB->AddRef();
    
    aOB->shiftPeriod = 0.5;
    aOB->rate = 30.5;
    aOB->tolerance = 1.0e-3;
    aOB->pressureMax = 1.0e3;
    
    aIOC = new Actuator();
    aIOC->AddRef();
    
    aIOC->shiftPeriod = 0.5;
    aIOC->rate = 30.5;
    aIOC->tolerance = 1.0e-3;
    aIOC->pressureMax = 1.0e3;
    
    gIOC = new CFrame();
    gIOC->AddRef();
    
    
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
    
    //#]
}

void StdCar::itsEngine_getRPM(const double t, double * val) {
    NOTIFY_OPERATION(itsEngine_getRPM, itsEngine_getRPM(const double ,double * ), 0, AppSimple_StdCar_itsEngine_getRPM_SERIALIZE);
    //#[ operation itsEngine_getRPM(const double ,double * ) 
      itsEngine->getRPM(t, val);
    //#]
}

void StdCar::itsEngine_handle_Start(const double t, long * val) {
    NOTIFY_OPERATION(itsEngine_handle_Start, itsEngine_handle_Start(const double ,long * ), 0, AppSimple_StdCar_itsEngine_handle_Start_SERIALIZE);
    //#[ operation itsEngine_handle_Start(const double ,long * ) 
      itsEngine->handle_Start(t, val);
    //#]
}

void StdCar::itsEngine_handle_throttle(const double t, double * val) {
    NOTIFY_OPERATION(itsEngine_handle_throttle, itsEngine_handle_throttle(const double ,double * ), 0, AppSimple_StdCar_itsEngine_handle_throttle_SERIALIZE);
    //#[ operation itsEngine_handle_throttle(const double ,double * ) 
      itsEngine->handle_throttle(t, val);
    //#]
}

void StdCar::itsVehicle_getSpeed(const double t, double * val) {
    NOTIFY_OPERATION(itsVehicle_getSpeed, itsVehicle_getSpeed(const double ,double * ), 0, AppSimple_StdCar_itsVehicle_getSpeed_SERIALIZE);
    //#[ operation itsVehicle_getSpeed(const double ,double * ) 
      itsVehicle->getSpeed(t, val);
    //#]
}

void StdCar::itsVehicle_handle_brakePedal(const double t, double * val) {
    NOTIFY_OPERATION(itsVehicle_handle_brakePedal, itsVehicle_handle_brakePedal(const double ,double * ), 0, AppSimple_StdCar_itsVehicle_handle_brakePedal_SERIALIZE);
    //#[ operation itsVehicle_handle_brakePedal(const double ,double * ) 
      itsVehicle->handle_brakePedal(t, val);
    //#]
}

void StdCar::cleanUpRelations() {
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


void OMAnimatedStdCar::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsEngine", FALSE, TRUE);
    if(myReal->itsEngine)
        aomsRelations->ADD_ITEM(myReal->itsEngine);
    aomsRelations->addRelation("gOB", FALSE, TRUE);
    if(myReal->gOB)
        aomsRelations->ADD_ITEM(myReal->gOB);
    aomsRelations->addRelation("gPOC", FALSE, TRUE);
    if(myReal->gPOC)
        aomsRelations->ADD_ITEM(myReal->gPOC);
    aomsRelations->addRelation("itsTorqueConverter", FALSE, TRUE);
    if(myReal->itsTorqueConverter)
        aomsRelations->ADD_ITEM(myReal->itsTorqueConverter);
    aomsRelations->addRelation("itsVehicle", FALSE, TRUE);
    if(myReal->itsVehicle)
        aomsRelations->ADD_ITEM(myReal->itsVehicle);
    aomsRelations->addRelation("itsGearbox", FALSE, TRUE);
    if(myReal->itsGearbox)
        aomsRelations->ADD_ITEM(myReal->itsGearbox);
    aomsRelations->addRelation("aPOC", FALSE, TRUE);
    if(myReal->aPOC)
        aomsRelations->ADD_ITEM(myReal->aPOC);
    aomsRelations->addRelation("aFC", FALSE, TRUE);
    if(myReal->aFC)
        aomsRelations->ADD_ITEM(myReal->aFC);
    aomsRelations->addRelation("aDC", FALSE, TRUE);
    if(myReal->aDC)
        aomsRelations->ADD_ITEM(myReal->aDC);
    aomsRelations->addRelation("aOB", FALSE, TRUE);
    if(myReal->aOB)
        aomsRelations->ADD_ITEM(myReal->aOB);
    aomsRelations->addRelation("aIOC", FALSE, TRUE);
    if(myReal->aIOC)
        aomsRelations->ADD_ITEM(myReal->aIOC);
    aomsRelations->addRelation("gIOC", FALSE, TRUE);
    if(myReal->gIOC)
        aomsRelations->ADD_ITEM(myReal->gIOC);
    aomsRelations->addRelation("POC", FALSE, TRUE);
    if(myReal->POC)
        aomsRelations->ADD_ITEM(myReal->POC);
    aomsRelations->addRelation("IOC", FALSE, TRUE);
    if(myReal->IOC)
        aomsRelations->ADD_ITEM(myReal->IOC);
    aomsRelations->addRelation("OB", FALSE, TRUE);
    if(myReal->OB)
        aomsRelations->ADD_ITEM(myReal->OB);
    aomsRelations->addRelation("DC", FALSE, TRUE);
    if(myReal->DC)
        aomsRelations->ADD_ITEM(myReal->DC);
    aomsRelations->addRelation("FC", FALSE, TRUE);
    if(myReal->FC)
        aomsRelations->ADD_ITEM(myReal->FC);
}

IMPLEMENT_META(StdCar, AppSimple, FALSE, OMAnimatedStdCar)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\StdCar.cpp
*********************************************************************/
