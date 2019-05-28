/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Throttle
//!	Generated Date	: Mon, 9, Jun 2003  
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

//## class Throttle 
//struct _OnPlotDlgMgr;
class CThrottleDialog;

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
    


////    Attributes    ////
public :
    
    bool bInit;		//## attribute bInit 
    
    long m_cRef;		//## attribute m_cRef 
    
protected :
    
    //_OnPlotDlgMgr* m_dlg;		//## attribute m_dlg 
    CThrottleDialog* m_dialog;

};


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Throttle.h
*********************************************************************/

