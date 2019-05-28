/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroComposition
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroComposition.cpp
*********************************************************************/

#include "aeroComposition.h"
#include "aeroDynamics.h"
#include "aeroFrame.h"
#include "atmosphere.h"
#include "bodyDynamics.h"
#include "engineDynamics.h"
#include "finDynamics.h"
#include "stdafx.h"
#include "OnUMLEso.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// aeroComposition.cpp                                                                  
//----------------------------------------------------------------------------
//## class aeroComposition 



aeroComposition::aeroComposition() {
    aeroDynamicsBlock = NULL;
    aeroFrameBlock = NULL;
    atmosphereBlock = NULL;
    bodyDynamicsBlock = NULL;
    engineDynamicsBlock = NULL;
    finDynamicsBlock = NULL;
    //#[ operation aeroComposition() 
    
    init();
    //#]
}

aeroComposition::~aeroComposition() {
    //#[ operation ~aeroComposition() 
    
    clean();
    //#]
    cleanUpRelations();
}

HRESULT aeroComposition::GetAssociations(long**  Assoc, long**  Size, long*  nSize) {
    //#[ operation GetAssociations(long**,long**,long*) 
    
    long nAssoc;
    long i;
    
    const long assoc[] =
    {
      0, 0, 5, 2,		//finDynamicsBlock.pFin <==> aeroDynamicsBlock.pFin
      2, 0, 5, 0,		//bodyDynamicsBlock.p <==> aeroDynamicsBlock.p
      1, 0, 5, 0,		//engineDynamicsBlock.p <==> aeroDynamicsBlock.p
      3, 0, 5, 1,		//atmosphereBlock.pAtmo <==> aeroDynamicsBlock.pAtmosphere
      4, 1, 3, 1,		//aeroFrameBlock.ph <==> atmosphereBlock.ph
      4, 0, 5, 0,		//aeroFrameBlock.p <==> aeroDynamicsBlock.p
    };
    
    const long size[] =
    {
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

HRESULT aeroComposition::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(finDynamicsBlock)
      ADD_LOCAL_ESO(engineDynamicsBlock)
      ADD_LOCAL_ESO(bodyDynamicsBlock)
      ADD_LOCAL_ESO(atmosphereBlock)
      ADD_LOCAL_ESO(aeroFrameBlock)
      ADD_LOCAL_ESO(aeroDynamicsBlock)
    
      return S_OK;
    //#]
}

bool aeroComposition::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
    
    if (! finDynamicsBlock->Load(fs) ) return false;
    if (! engineDynamicsBlock->Load(fs) ) return false;
    if (! bodyDynamicsBlock->Load(fs) ) return false;
    if (! atmosphereBlock->Load(fs) ) return false;
    if (! aeroFrameBlock->Load(fs) ) return false;
    if (! aeroDynamicsBlock->Load(fs) ) return false;
    
    return true;
    //#]
}

void aeroComposition::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
    
    finDynamicsBlock->Save(fs);
    engineDynamicsBlock->Save(fs);
    bodyDynamicsBlock->Save(fs);
    atmosphereBlock->Save(fs);
    aeroFrameBlock->Save(fs);
    aeroDynamicsBlock->Save(fs);
    //#]
}

void aeroComposition::aeroDynamicsBlock_getAlpha(const double  t, double *  val) {
    //#[ operation aeroDynamicsBlock_getAlpha(const double,double *) 
      aeroDynamicsBlock->getAlpha(t, val);
    //#]
}

void aeroComposition::aeroDynamicsBlock_getMach(const double  t, double *  val) {
    //#[ operation aeroDynamicsBlock_getMach(const double,double *) 
      aeroDynamicsBlock->getMach(t, val);
    //#]
}

void aeroComposition::bodyDynamicsBlock_getAccel(const double  t, double *  val) {
    //#[ operation bodyDynamicsBlock_getAccel(const double,double *) 
      bodyDynamicsBlock->getAccel(t, val);
    //#]
}

void aeroComposition::bodyDynamicsBlock_getAttitude(const double  t, double *  val) {
    //#[ operation bodyDynamicsBlock_getAttitude(const double,double *) 
      bodyDynamicsBlock->getAttitude(t, val);
    //#]
}

void aeroComposition::bodyDynamicsBlock_getGyro(const double  t, double *  val) {
    //#[ operation bodyDynamicsBlock_getGyro(const double,double *) 
      bodyDynamicsBlock->getGyro(t, val);
    //#]
}

void aeroComposition::bodyDynamicsBlock_getX(const double  t, double *  val) {
    //#[ operation bodyDynamicsBlock_getX(const double,double *) 
      bodyDynamicsBlock->getX(t, val);
    //#]
}

void aeroComposition::bodyDynamicsBlock_getZ(const double  t, double *  val) {
    //#[ operation bodyDynamicsBlock_getZ(const double,double *) 
      bodyDynamicsBlock->getZ(t, val);
    //#]
}

void aeroComposition::clean() {
    //#[ operation clean() 
    
    if (finDynamicsBlock)
    {
      finDynamicsBlock->Release();
      finDynamicsBlock = NULL;
    }
    if (engineDynamicsBlock)
    {
      engineDynamicsBlock->Release();
      engineDynamicsBlock = NULL;
    }
    if (bodyDynamicsBlock)
    {
      bodyDynamicsBlock->Release();
      bodyDynamicsBlock = NULL;
    }
    if (atmosphereBlock)
    {
      atmosphereBlock->Release();
      atmosphereBlock = NULL;
    }
    if (aeroFrameBlock)
    {
      aeroFrameBlock->Release();
      aeroFrameBlock = NULL;
    }
    if (aeroDynamicsBlock)
    {
      aeroDynamicsBlock->Release();
      aeroDynamicsBlock = NULL;
    }
    //#]
}

void aeroComposition::finDynamics_handle_AngleSetpoint(const double t, double * val) {
    //#[ operation finDynamics_handle_AngleSetpoint(const double ,double * ) 
    finDynamicsBlock->handle_AngleSetpoint(t, val);
    //#]
}

void aeroComposition::init() {
    //#[ operation init() 
    
    
    finDynamicsBlock = new finDynamics();
    finDynamicsBlock->AddRef();
    
    
    engineDynamicsBlock = new engineDynamics();
    engineDynamicsBlock->AddRef();
    
    
    bodyDynamicsBlock = new bodyDynamics();
    bodyDynamicsBlock->AddRef();
    
    atmosphereBlock = new atmosphere();
    atmosphereBlock->AddRef();
    
    
    aeroFrameBlock = new aeroFrame();
    aeroFrameBlock->AddRef();
    
    
    aeroDynamicsBlock = new aeroDynamics();
    aeroDynamicsBlock->AddRef();
    
    //#]
}

void aeroComposition::cleanUpRelations() {
    if(aeroDynamicsBlock != NULL)
        {
            aeroDynamicsBlock = NULL;
        }
    if(aeroFrameBlock != NULL)
        {
            aeroFrameBlock = NULL;
        }
    if(atmosphereBlock != NULL)
        {
            atmosphereBlock = NULL;
        }
    if(bodyDynamicsBlock != NULL)
        {
            bodyDynamicsBlock = NULL;
        }
    if(engineDynamicsBlock != NULL)
        {
            engineDynamicsBlock = NULL;
        }
    if(finDynamicsBlock != NULL)
        {
            finDynamicsBlock = NULL;
        }
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroComposition.cpp
*********************************************************************/

