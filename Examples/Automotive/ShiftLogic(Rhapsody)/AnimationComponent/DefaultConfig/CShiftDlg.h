/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CShiftDlg
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CShiftDlg.h
*********************************************************************/


#ifndef CShiftDlg_H 

#define CShiftDlg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GUIModels.h"
#include <atlhost.h>
#include <atlwin.h>

//## package GUIModels 

//----------------------------------------------------------------------------
// CShiftDlg.h                                                                  
//----------------------------------------------------------------------------

//## class CShiftDlg 
struct _OnShiftLever;class CShiftDlg  {


////    Constructors and destructors    ////
public :
    
    //## operation CShiftDlg() 
    CShiftDlg();
    
    //## operation ~CShiftDlg() 
    ~CShiftDlg();


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
    
    //## operation get_Position(long * ) 
    HRESULT get_Position(long * val);
    
    //## operation init() 
    void init();
    
    //## operation put_Position(long*) 
    HRESULT put_Position(long*  val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    CComPtr<_OnShiftLever>  getM_pShift() const;
    
    //## auto_generated 
    void setM_pShift(CComPtr<_OnShiftLever> p_m_pShift);
    
    //## auto_generated 
    CAxWindow  getM_wnd() const;
    
    //## auto_generated 
    void setM_wnd(CAxWindow p_m_wnd);


////    Attributes    ////
protected :
    
    CComPtr<_OnShiftLever> m_pShift;		//## attribute m_pShift 
    
    CAxWindow m_wnd;		//## attribute m_wnd 
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CShiftDlg.h
*********************************************************************/

