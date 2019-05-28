/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirFrame
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AirFrame.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "AirFrame.h"
#include "AeroDynamics.h"
#include "BodyDynamics.h"
#include "FinActuator.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// AirFrame.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class AirFrame 



AirFrame::AirFrame() {
    pAero = NULL;
    pBody = NULL;
    pFin = NULL;
    //#[ operation AirFrame() 
    init();
    //#]
}

AirFrame::~AirFrame() {
    //#[ operation ~AirFrame() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT AirFrame::GetAssociations(long * * Assoc, long * * Size, long * nSize) {
    //#[ operation GetAssociations(long * * ,long * * ,long * ) 
    
      long nAssoc;
      long i;
    
      // pAero  0 : 3DConn 0, 1DConn 1
      // pBody  1 : 3DConn 0
      // pFin   2 : 1DConn 0
    
      const long assoc[] =
      {
        0, 0,      1, 0,  // pAero->3DConn <==> pBody->3DConn
        0, 1,      2, 0,  // pAero->1DConn <==> pFin->1DConn
      };
    
      const long size[] =
      {
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

HRESULT AirFrame::InitEsos() {
    //#[ operation InitEsos() 
    ADD_LOCAL_ESO(pAero)
    ADD_LOCAL_ESO(pBody)
    ADD_LOCAL_ESO(pFin)
    
    return S_OK;
    //#]
}

bool AirFrame::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    if (! pAero->Load(fs) ) return false;
    if (! pBody->Load(fs) ) return false;
    if (! pFin->Load(fs) ) return false;
    
    return true;
    //#]
}

void AirFrame::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    pAero->Save(fs);
    pBody->Save(fs);
    pFin->Save(fs);
    //#]
}

void AirFrame::clean() {
    //#[ operation clean() 
    if (pAero)
    {
      pAero->Release();
      pAero = NULL;
    }
    
    if (pBody)
    {
      pBody->Release();
      pBody = NULL;
    }
    if (pFin)
    {
      pFin->Release();
      pFin = NULL;
    }
    //#]
}

double AirFrame::getAccData(double  time) {
    //#[ operation getAccData(double) 
    return pBody->getAccData(time); 
    //#]
}

double AirFrame::getGyroData(double  time) {
    //#[ operation getGyroData(double) 
    return pBody->getGyroData(time); 
    //#]
}

double AirFrame::getSpeed(double  time) {
    //#[ operation getSpeed(double) 
    return pBody->getSpeed(time); 
    //#]
}

void AirFrame::init() {
    //#[ operation init() 
    pAero = new AeroDynamics();
    pAero->AddRef();
    pBody = new BodyDynamics();
    pBody->AddRef();
    pFin = new FinActuator();
    pFin->AddRef();
    //#]
}

void AirFrame::setFinAngleSetpoint(const double t, double * val) {
    //#[ operation setFinAngleSetpoint(const double ,double * ) 
    pFin->setAngleSetpoint(t, val);
    //#]
}

void AirFrame::setThrust(const double t, double * val) {
    //#[ operation setThrust(const double ,double * ) 
    pAero->setThrust(t, val);
    //#]
}

AeroDynamics* AirFrame::getPAero() const {
    return pAero;
}

void AirFrame::setPAero(AeroDynamics*  p_AeroDynamics) {
    pAero = p_AeroDynamics;
}

BodyDynamics* AirFrame::getPBody() const {
    return pBody;
}

void AirFrame::setPBody(BodyDynamics*  p_BodyDynamics) {
    pBody = p_BodyDynamics;
}

FinActuator* AirFrame::getPFin() const {
    return pFin;
}

void AirFrame::setPFin(FinActuator*  p_FinActuator) {
    pFin = p_FinActuator;
}

void AirFrame::cleanUpRelations() {
    if(pAero != NULL)
        {
            pAero = NULL;
        }
    if(pBody != NULL)
        {
            pBody = NULL;
        }
    if(pFin != NULL)
        {
            pFin = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedAirFrame::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedAirFrame::serializeRelations(AOMSRelations*  aomsRelations) const {
}

IMPLEMENT_META(AirFrame, GuidancePkg, FALSE, OMAnimatedAirFrame)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AirFrame.cpp
*********************************************************************/

