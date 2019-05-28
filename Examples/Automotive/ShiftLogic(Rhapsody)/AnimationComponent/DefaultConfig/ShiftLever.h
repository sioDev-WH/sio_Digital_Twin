/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ShiftLever
//!	Generated Date	: Mon, 9, Jun 2003  
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

// 
//## class ShiftLever 
//struct _OnPlotDlgMgr;
class CShiftLeverDialog;

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
    


////    Attributes    ////
public :
    
    bool bInit;		//## attribute bInit 
    
    long m_cRef;		//## attribute m_cRef 
    
protected :
    
    //_OnPlotDlgMgr* m_dlg;		//## attribute m_dlg 
    CShiftLeverDialog* m_dialog;
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ShiftLever.h
*********************************************************************/

