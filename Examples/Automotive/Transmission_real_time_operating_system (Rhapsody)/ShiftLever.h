/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ShiftLever
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\ShiftLever.h
*********************************************************************/


#ifndef ShiftLever_H 

#define ShiftLever_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GUIModels.h"
#include "TransmissionControlModels.h"
#include "OnModelBase.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// ShiftLever.h                                                                  
//----------------------------------------------------------------------------
class CShiftDlg;


// 
//## class ShiftLever 
class ShiftLever : public COnModelBase {


////    Constructors and destructors    ////
public :
    
    //## operation ShiftLever() 
    ShiftLever();
    
    //## operation ~ShiftLever() 
    ~ShiftLever();


////    Operations    ////
public :
    
    //## operation AddRef() 
    long AddRef();
    
    //## operation Release() 
    long Release();
    
    //## operation SetName(LPCTSTR ) 
    void SetName(LPCTSTR cszName);
    
    //## operation clean() 
    void clean();
    
    //## operation get_Position(long * ) 
    void get_Position(long * val);
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation put_Position(long * ) 
    void put_Position(long * val);


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
    CShiftDlg* getM_dlg() const;
    
    //## auto_generated 
    void setM_dlg(CShiftDlg*  p_CShiftDlg);


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
    
    CShiftDlg* m_dlg;		//## link m_dlg 
    


};


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ShiftLever.h
*********************************************************************/

