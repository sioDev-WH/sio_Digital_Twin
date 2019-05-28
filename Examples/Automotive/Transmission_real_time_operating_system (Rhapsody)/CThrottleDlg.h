/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CThrottleDlg
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CThrottleDlg.h
*********************************************************************/


#ifndef CThrottleDlg_H 

#define CThrottleDlg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GUIModels.h"
#include <atlhost.h>
#include <atlwin.h>

//## package GUIModels 

//----------------------------------------------------------------------------
// CThrottleDlg.h                                                                  
//----------------------------------------------------------------------------

//## class CThrottleDlg 
struct _OnThrottle;class CThrottleDlg  {


////    Constructors and destructors    ////
public :
    
    //## operation CThrottleDlg() 
    CThrottleDlg();
    
    //## operation ~CThrottleDlg() 
    ~CThrottleDlg();


////    Operations    ////
public :
    
    //## operation Move(int,int,int,int) 
    void Move(int  x, int  y, int  nWidth, int  nHeight);
    
    //## operation SetCaption(LPCTSTR ) 
    void SetCaption(LPCTSTR szCaption);
    
    //## operation Show() 
    void Show();
    
    //## operation clean() 
    void clean();
    
    //## operation getThrottle(double * ) 
    void getThrottle(double * val);
    
    //## operation init() 
    void init();
    
    //## operation setThrottle(double *) 
    void setThrottle(double *  val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    CComPtr<_OnThrottle>  getM_pThrottle() const;
    
    //## auto_generated 
    void setM_pThrottle(CComPtr<_OnThrottle> p_m_pThrottle);
    
    //## auto_generated 
    CAxWindow  getM_wnd() const;
    
    //## auto_generated 
    void setM_wnd(CAxWindow p_m_wnd);


////    Attributes    ////
protected :
    
    CComPtr<_OnThrottle> m_pThrottle;		//## attribute m_pThrottle 
    
    CAxWindow m_wnd;		//## attribute m_wnd 
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CThrottleDlg.h
*********************************************************************/

