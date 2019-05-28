/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirFrame
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AirFrame.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "AirFrame.h"
#include "AeroDynamics.h"
#include "BodyDynamics.h"
#include "FinActuator.h"
#include "stdafx.h"
#include "OnUMLEso.h"

//## package Application 


//#[ ignore 
#define Application_AirFrame_AirFrame_SERIALIZE OM_NO_OP


#define Application_AirFrame_GetAssociations_SERIALIZE \
    aomsmethod->addAttribute("Assoc", x2String(Assoc)); \
    aomsmethod->addAttribute("Size", x2String(Size)); \
    aomsmethod->addAttribute("nSize", x2String(nSize));


#define Application_AirFrame_InitEsos_SERIALIZE OM_NO_OP


#define Application_AirFrame_Load_SERIALIZE aomsmethod->addAttribute("fs", x2String(fs));


#define Application_AirFrame_Save_SERIALIZE aomsmethod->addAttribute("fs", x2String(fs));


#define Application_AirFrame_clean_SERIALIZE OM_NO_OP


#define Application_AirFrame_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// AirFrame.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class AirFrame 



AirFrame::AirFrame() {
    NOTIFY_CONSTRUCTOR(AirFrame, AirFrame(), 0, Application_AirFrame_AirFrame_SERIALIZE);
    itsAeroDynamics = NULL;
    itsBodyDynamics = NULL;
    itsFinDynamics = NULL;
    //#[ operation AirFrame() 
    
    init();
    //#]
}

AirFrame::~AirFrame() {
    NOTIFY_DESTRUCTOR(~AirFrame, TRUE);
    //#[ operation ~AirFrame() 
    
    clean();
    //#]
    cleanUpRelations();
}

HRESULT AirFrame::GetAssociations(long**  Assoc, long**  Size, long*  nSize) {
    NOTIFY_OPERATION(GetAssociations, GetAssociations(long**,long**,long*), 3, Application_AirFrame_GetAssociations_SERIALIZE);
    //#[ operation GetAssociations(long**,long**,long*) 
    
    long nAssoc;
    long i;
    
    // 0, 0 itsFinDynamics.pFinConn
    // 1, 0 itsBodyDynamics.pAero
    // 2, 0 itsAeroDynamics.pBody
    // 2, 1 itsAeroDynamics.pFinConn
    
    /*  TODO: determine project settings that generated these outputs  
    const long assoc[] =
    {
      2, 3,      0, 1,
      1, 1,      2, 2,
    };
    */
    
    const long assoc[] =
    {
      1, 0,      2, 0,
      0, 0,      2, 1,
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
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, Application_AirFrame_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(itsFinDynamics)
      ADD_LOCAL_ESO(itsBodyDynamics)
      ADD_LOCAL_ESO(itsAeroDynamics)
    
      return S_OK;
    //#]
}

bool AirFrame::Load(FILE*  fs) {
    NOTIFY_OPERATION(Load, Load(FILE*), 1, Application_AirFrame_Load_SERIALIZE);
    //#[ operation Load(FILE*) 
    
    if (! itsFinDynamics->Load(fs) ) return false;
    if (! itsBodyDynamics->Load(fs) ) return false;
    if (! itsAeroDynamics->Load(fs) ) return false;
    
    return true;
    //#]
}

void AirFrame::Save(FILE*  fs) {
    NOTIFY_OPERATION(Save, Save(FILE*), 1, Application_AirFrame_Save_SERIALIZE);
    //#[ operation Save(FILE*) 
    
    itsFinDynamics->Save(fs);
    itsBodyDynamics->Save(fs);
    itsAeroDynamics->Save(fs);
    //#]
}

void AirFrame::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_AirFrame_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (itsFinDynamics)
    {
      itsFinDynamics->Release();
      itsFinDynamics = NULL;
    }
    if (itsBodyDynamics)
    {
      itsBodyDynamics->Release();
      itsBodyDynamics = NULL;
    }
    if (itsAeroDynamics)
    {
      itsAeroDynamics->Release();
      itsAeroDynamics = NULL;
    }
    //#]
}

void AirFrame::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_AirFrame_init_SERIALIZE);
    //#[ operation init() 
    
    
    itsFinDynamics = new FinActuator();
    itsFinDynamics->AddRef();
    
    itsBodyDynamics = new BodyDynamics();
    itsBodyDynamics->AddRef();
    
    itsAeroDynamics = new AeroDynamics();
    itsAeroDynamics->AddRef();
    
    //#]
}

void AirFrame::cleanUpRelations() {
    if(itsAeroDynamics != NULL)
        {
            itsAeroDynamics = NULL;
        }
    if(itsBodyDynamics != NULL)
        {
            itsBodyDynamics = NULL;
        }
    if(itsFinDynamics != NULL)
        {
            itsFinDynamics = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedAirFrame::serializeRelations(AOMSRelations*  aomsRelations) const {
}

IMPLEMENT_META(AirFrame, Application, FALSE, OMAnimatedAirFrame)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AirFrame.cpp
*********************************************************************/

