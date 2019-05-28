/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: GearInfo
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\GearInfo.h
*********************************************************************/


#ifndef GearInfo_H 

#define GearInfo_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionControlModels.h"

//## package TransmissionControlModels 

//----------------------------------------------------------------------------
// GearInfo.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedGearInfo;
#endif // _OMINSTRUMENT


//## class GearInfo 
class GearInfo  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedGearInfo;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation GearInfo() 
    GearInfo();
    
    //## operation ~GearInfo() 
    ~GearInfo();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init(const long ,const long ,const long ,const long * ) 
    void init(const long GearID, const long nClutches, const long nEngaged, const long * Engaged);


////    Additional operations    ////
public :
    
    //## auto_generated 
    bool *  getClutchState() const;
    
    //## auto_generated 
    void setClutchState(bool * p_ClutchState);
    
    //## auto_generated 
    long getID() const;
    
    //## auto_generated 
    void setID(long  p_ID);


////    Attributes    ////
public :
    
    bool * ClutchState;		//## attribute ClutchState 
    
    long ID;		//## attribute ID 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedGearInfo : virtual public AOMInstance {

    
    DECLARE_META(GearInfo, OMAnimatedGearInfo)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\GearInfo.h
*********************************************************************/

