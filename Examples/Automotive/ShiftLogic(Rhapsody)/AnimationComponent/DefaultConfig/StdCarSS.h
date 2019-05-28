/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: StdCarSS
//!	Generated Date	: Wed, 18, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\StdCarSS.h
*********************************************************************/


#ifndef StdCarSS_H 

#define StdCarSS_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include "TransmissionControlModels.h"
#include "OnUMLEso.h"
#include "fstream.h"
#include "OnSubsystemBase.h"
#include "StdCar.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// StdCarSS.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedStdCarSS;
#endif // _OMINSTRUMENT


//## class StdCarSS 
class StdCarSS : public COnSubsystemBase<StdCar> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedStdCarSS;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    StdCarSS();
    
    //## auto_generated 
    ~StdCarSS();


////    Operations    ////
public :
    
    //## operation Load(const BSTR) 
    bool Load(const BSTR  filename);
    
    //## operation Save(const BSTR) 
    void Save(const BSTR  filename);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
     init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    void setDC(IIsDaeEsoCImpl*  p_DC);
    
    //## auto_generated 
    void setFC(IIsDaeEsoCImpl*  p_FC);
    
    //## auto_generated 
    void setIOC(IIsDaeEsoCImpl*  p_IOC);
    
    //## auto_generated 
    void setOB(IIsDaeEsoCImpl*  p_OB);
    
    //## auto_generated 
    void setPOC(IIsDaeEsoCImpl*  p_POC);
    
    //## auto_generated 
    void setADC(IIsDaeEsoCImpl*  p_aDC);
    
    //## auto_generated 
    void setAFC(IIsDaeEsoCImpl*  p_aFC);
    
    //## auto_generated 
    void setAIOC(IIsDaeEsoCImpl*  p_aIOC);
    
    //## auto_generated 
    void setAOB(IIsDaeEsoCImpl*  p_aOB);
    
    //## auto_generated 
    void setAPOC(IIsDaeEsoCImpl*  p_aPOC);
    
    //## auto_generated 
    void setGIOC(IIsDaeEsoCImpl*  p_gIOC);
    
    //## auto_generated 
    void setGOB(IIsDaeEsoCImpl*  p_gOB);
    
    //## auto_generated 
    void setGPOC(IIsDaeEsoCImpl*  p_gPOC);
    
    //## auto_generated 
    void setItsEngine(IIsDaeEsoCImpl*  p_itsEngine);
    
    //## auto_generated 
    void setItsGearbox(IIsDaeEsoCImpl*  p_itsGearbox);
    
    //## auto_generated 
    void setItsTorqueConverter(IIsDaeEsoCImpl*  p_itsTorqueConverter);
    
    //## auto_generated 
    void setItsVehicle(IIsDaeEsoCImpl*  p_itsVehicle);


////    Attributes    ////
public :
    
    IIsDaeEsoCImpl* DC;		//## attribute DC 
    
    IIsDaeEsoCImpl* FC;		//## attribute FC 
    
    IIsDaeEsoCImpl* IOC;		//## attribute IOC 
    
    IIsDaeEsoCImpl* OB;		//## attribute OB 
    
    IIsDaeEsoCImpl* POC;		//## attribute POC 
    
    IIsDaeEsoCImpl* aDC;		//## attribute aDC 
    
    IIsDaeEsoCImpl* aFC;		//## attribute aFC 
    
    IIsDaeEsoCImpl* aIOC;		//## attribute aIOC 
    
    IIsDaeEsoCImpl* aOB;		//## attribute aOB 
    
    IIsDaeEsoCImpl* aPOC;		//## attribute aPOC 
    
    IIsDaeEsoCImpl* gIOC;		//## attribute gIOC 
    
    IIsDaeEsoCImpl* gOB;		//## attribute gOB 
    
    IIsDaeEsoCImpl* gPOC;		//## attribute gPOC 
    
    IIsDaeEsoCImpl* itsEngine;		//## attribute itsEngine 
    
    IIsDaeEsoCImpl* itsGearbox;		//## attribute itsGearbox 
    
    IIsDaeEsoCImpl* itsTorqueConverter;		//## attribute itsTorqueConverter 
    
    IIsDaeEsoCImpl* itsVehicle;		//## attribute itsVehicle 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedStdCarSS : virtual public AOMInstance {

    
    DECLARE_META(StdCarSS, OMAnimatedStdCarSS)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\StdCarSS.h
*********************************************************************/

