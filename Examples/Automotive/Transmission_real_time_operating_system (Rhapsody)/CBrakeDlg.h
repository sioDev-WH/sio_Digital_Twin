/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CBrakeDlg
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CBrakeDlg.h
*********************************************************************/


#ifndef CBrakeDlg_H 

#define CBrakeDlg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GUIModels.h"
#include <atlhost.h>
#include <atlwin.h>

//## package GUIModels 

//----------------------------------------------------------------------------
// CBrakeDlg.h                                                                  
//----------------------------------------------------------------------------

//## class CBrakeDlg 
struct _OnBrakes;

class CBrakeDlg  {


////    Constructors and destructors    ////
public :
    
    //## operation CBrakeDlg() 
    CBrakeDlg();
    
    //## operation ~CBrakeDlg() 
    ~CBrakeDlg();


////    Operations    ////
public :
    
    //## operation Move(const int ,const int ,const int ,const int ) 
    void Move(const int x, const int y, const int nWidth, const int nHeight);
    
    //## operation SetCaption(LPCTSTR ) 
    void SetCaption(LPCTSTR szCaption);
    
    //## operation Show() 
    void Show();
    
    //## operation clean() 
    void clean();
    
    //## operation get_Position(double * ) 
    HRESULT get_Position(double * val);
    
    //## operation init() 
    void init();
    
    //## operation put_Position(double) 
    HRESULT put_Position(double  val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    CComPtr<_OnBrakes>  getM_pBrake() const;
    
    //## auto_generated 
    void setM_pBrake(CComPtr<_OnBrakes> p_m_pBrake);
    
    //## auto_generated 
    CAxWindow  getM_wnd() const;
    
    //## auto_generated 
    void setM_wnd(CAxWindow p_m_wnd);


////    Attributes    ////
protected :
    
    CComPtr<_OnBrakes> m_pBrake;		//## attribute m_pBrake 
    
    CAxWindow m_wnd;		//## attribute m_wnd 
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CBrakeDlg.h
*********************************************************************/

