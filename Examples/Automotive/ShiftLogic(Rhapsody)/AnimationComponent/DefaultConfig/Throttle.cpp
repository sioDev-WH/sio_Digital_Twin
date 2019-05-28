/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Throttle
//!	Generated Date	: Mon, 9, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\Throttle.cpp
*********************************************************************/

#include "Throttle.h"
#include "EventBroadcast.h"
//#include "OnPlot_i.c"
//#include "OnPlot.h"
#include "ThrottleDialog.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// Throttle.cpp                                                                  
//----------------------------------------------------------------------------
//## class Throttle 



Throttle::Throttle() : m_cRef(0) ,m_dialog(NULL) ,bInit(false)  
//}}SCG_OP_INFO
 {
    //#[ operation Throttle() 
    init();
    
    //#]
}

Throttle::~Throttle() {
    //#[ operation ~Throttle() 
    clean( );
    
    //#]
}

long Throttle::AddRef() {
    //#[ operation AddRef() 
    return ++m_cRef;
    //#]
}

long Throttle::Release() {
    //#[ operation Release() 
    m_cRef--;
    if (m_cRef <= 0)
      delete this;
    
    return m_cRef;
    //#]
}

void Throttle::SetName(const _TCHAR * caption) {
    //#[ operation SetName(const _TCHAR * ) 
    m_dialog->SetCaption(caption);
    //#]
}

void Throttle::clean() {
    //#[ operation clean() 
    if (m_dialog)
    {
      delete m_dialog;
      m_dialog = NULL;
    }
    
    //#]
}

void Throttle::getPosition(double*  val) {
    //#[ operation getPosition(double*) 
    m_dialog->get_Position(val);
    //#]
}

void Throttle::handle_tick() {
    //#[ operation handle_tick() 
    if(!bInit) init();
    broadcast();
    //#]
}

void Throttle::init() {
    //#[ operation init() 
    //HRESULT hr = S_OK;  
    //hr = CoCreateInstance(CLSID_OnPlotDlgMgr, NULL, CLSCTX_INPROC_SERVER, IID__OnPlotDlgMgr, (void**) &m_dialog);
    //m_dialog->ShowThrottle();
    //_ASSERTE(hr == S_OK);
    //bInit=true;
    
    m_dialog = new CThrottleDialog();
    m_dialog->Show();
    bInit = true;
    //#]
}

void Throttle::setPosition(double * val) {
    //#[ operation setPosition(double * ) 
    m_dialog->put_Position(val);
    //#]
}



/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Throttle.cpp
*********************************************************************/

