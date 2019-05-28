/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Throttle
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Throttle.h
*********************************************************************/


#ifndef Throttle_H 

#define Throttle_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GUIModels.h"
#include "TransmissionControlModels.h"
#include "OnModelBase.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// Throttle.h                                                                  
//----------------------------------------------------------------------------
class CThrottleDlg;


//## class Throttle 
class Throttle : public COnModelBase {


////    Constructors and destructors    ////
public :
    
    //## operation Throttle() 
    Throttle();
    
    //## operation ~Throttle() 
    ~Throttle();


////    Operations    ////
public :
    
    //## operation AddRef() 
    long AddRef();
    
    //## operation Release() 
    long Release();
    
    //## operation SetName(const _TCHAR * ) 
    void SetName(const _TCHAR * caption);
    
    //## operation clean() 
    void clean();
    
    //## operation getPosition(double*) 
    void getPosition(double*  val);
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation setPosition(double * ) 
    void setPosition(double * val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    bool getBInit() const;
    
    //## auto_generated 
    void setBInit(bool  p_bInit);
    
    //## auto_generated 
    long getM_cRef() const;
    
    //## auto_generated 
    void setM_cRef(long  p_m_cRef);
    
    //## auto_generated 
    CThrottleDlg* getM_dlg() const;
    
    //## auto_generated 
    void setM_dlg(CThrottleDlg*  p_CThrottleDlg);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    bool bInit;		//## attribute bInit 
    
    long m_cRef;		//## attribute m_cRef 
    

////    Relations and components    ////
public :
    
    CThrottleDlg* m_dlg;		//## link m_dlg 
    


};


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Throttle.h
*********************************************************************/

