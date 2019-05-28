/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Brakes
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Brakes.h
*********************************************************************/


#ifndef Brakes_H 

#define Brakes_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GUIModels.h"
#include "TransmissionControlModels.h"
#include "OnModelBase.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// Brakes.h                                                                  
//----------------------------------------------------------------------------
class CBrakeDlg;


//## class Brakes 
class Brakes : public COnModelBase {


////    Constructors and destructors    ////
public :
    
    //## operation Brakes() 
    Brakes();
    
    //## operation ~Brakes() 
    ~Brakes();


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
    bool  getBInit() const;
    
    //## auto_generated 
    void setBInit(bool p_bInit);
    
    //## auto_generated 
    long getM_cRef() const;
    
    //## auto_generated 
    void setM_cRef(long  p_m_cRef);
    
    //## auto_generated 
    CBrakeDlg* getM_dlg() const;
    
    //## auto_generated 
    void setM_dlg(CBrakeDlg*  p_CBrakeDlg);


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
    
    CBrakeDlg* m_dlg;		//## link m_dlg 
    


};


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Brakes.h
*********************************************************************/

