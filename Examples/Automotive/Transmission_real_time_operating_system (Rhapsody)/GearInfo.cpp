/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: GearInfo
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\GearInfo.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "GearInfo.h"

//## package TransmissionControlModels 


//#[ ignore 
#define TransmissionControlModels_GearInfo_GearInfo_SERIALIZE OM_NO_OP


#define TransmissionControlModels_GearInfo_clean_SERIALIZE OM_NO_OP


#define TransmissionControlModels_GearInfo_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// GearInfo.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionControlModels)
//## class GearInfo 



GearInfo::GearInfo() {
    NOTIFY_CONSTRUCTOR(GearInfo, GearInfo(), 0, TransmissionControlModels_GearInfo_GearInfo_SERIALIZE);
    //#[ operation GearInfo() 
    ID = -1000;
    ClutchState = NULL;
    //#]
}

GearInfo::~GearInfo() {
    NOTIFY_DESTRUCTOR(~GearInfo, TRUE);
    //#[ operation ~GearInfo() 
    clean();
    //#]
}

void GearInfo::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionControlModels_GearInfo_clean_SERIALIZE);
    //#[ operation clean() 
      if(ClutchState) 
      {
        delete[] ClutchState;
        ClutchState = NULL;
      }
    
    //#]
}

void GearInfo::init(const long GearID, const long nClutches, const long nEngaged, const long * Engaged) {
    NOTIFY_OPERATION(init, init(const long ,const long ,const long ,const long * ), 0, TransmissionControlModels_GearInfo_init_SERIALIZE);
    //#[ operation init(const long ,const long ,const long ,const long * ) 
        int i;
    
        ID=GearID;
        ClutchState = (bool*) new bool[nClutches];
        for(i=0;i<nClutches;i++)  ClutchState[i] = false;
        for(i=0;i<nEngaged;i++)
           ClutchState[Engaged[i]] = true;
    
    //#]
}

bool *  GearInfo::getClutchState() const {
    return ClutchState;
}

void GearInfo::setClutchState(bool * p_ClutchState) {
    ClutchState = p_ClutchState;
}

long GearInfo::getID() const {
    return ID;
}

void GearInfo::setID(long  p_ID) {
    ID = p_ID;
}



#ifdef _OMINSTRUMENT


void OMAnimatedGearInfo::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(GearInfo, TransmissionControlModels, FALSE, OMAnimatedGearInfo)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\GearInfo.cpp
*********************************************************************/

