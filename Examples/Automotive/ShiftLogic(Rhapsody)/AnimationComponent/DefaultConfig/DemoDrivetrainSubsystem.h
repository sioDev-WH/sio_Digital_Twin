/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DemoDrivetrainSubsystem
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrainSubsystem.h
*********************************************************************/


#ifndef DemoDrivetrainSubsystem_H 

#define DemoDrivetrainSubsystem_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "TransmissionControlModels.h"
#include "OnUMLEso.h"
#include "fstream.h"
#include "OnSubsystemBase.h"
#include "DemoDrivetrain.h"

//## package Application 

//----------------------------------------------------------------------------
// DemoDrivetrainSubsystem.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedDemoDrivetrainSubsystem;
#endif // _OMINSTRUMENT


//## class DemoDrivetrainSubsystem 
class DemoDrivetrainSubsystem : public COnSubsystemBase<DemoDrivetrain> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedDemoDrivetrainSubsystem;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation DemoDrivetrainSubsystem() 
    DemoDrivetrainSubsystem();
    
    //## operation ~DemoDrivetrainSubsystem() 
    ~DemoDrivetrainSubsystem();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    

////    Additional operations    ////
public :
    


////    Attributes    ////
public :
    
    IIsDaeEsoCImpl* Car;		//## attribute Car 
    
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
    
    ofstream fs;		//## attribute fs 
    
    IIsDaeEsoCImpl* gIOC;		//## attribute gIOC 
    
    IIsDaeEsoCImpl* gOB;		//## attribute gOB 
    
    IIsDaeEsoCImpl* gPOC;		//## attribute gPOC 
    
    IIsDaeEsoCImpl* itsEngine;		//## attribute itsEngine 
    
    IIsDaeEsoCImpl* itsGearbox;		//## attribute itsGearbox 
    
    IIsDaeEsoCImpl* itsTC;		//## attribute itsTC 
    
    long m_cRef;		//## attribute m_cRef 
    
    //IIsDaeEsoCImpl* m_pModel;		//## attribute m_pModel 
    
    //IOnModelExec* m_pModelExec;		//## attribute m_pModelExec 
    
    DWORD m_pdw;		//## attribute m_pdw 
    
    long nVars;		//## attribute nVars 
    
    SAFEARRAY* psaVarVals;		//## attribute psaVarVals 
    
    double* varVals;		//## attribute varVals 
    

////    Relations and components    ////
public :
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedDemoDrivetrainSubsystem : virtual public AOMInstance {

    
    DECLARE_META(DemoDrivetrainSubsystem, OMAnimatedDemoDrivetrainSubsystem)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrainSubsystem.h
*********************************************************************/

