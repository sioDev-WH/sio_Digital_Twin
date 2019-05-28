/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Brakes
//!	Generated Date	: Mon, 9, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\Brakes.cpp
*********************************************************************/

#include "Brakes.h"
#include "EventBroadcast.h"
#include "OnModelBase.h"
//#include "OnPlot_i.c"
//#include "OnPlot.h"
#include "BrakeDialog.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// Brakes.cpp                                                                  
//----------------------------------------------------------------------------
//## class Brakes 



Brakes::Brakes() : m_cRef(0) ,bInit(false) ,m_dialog(NULL) {
    //#[ operation Brakes() 
    init();
    
    //#]
}

Brakes::~Brakes() {
    //#[ operation ~Brakes() 
    clean( );
    //#]
}

long Brakes::AddRef() {
    //#[ operation AddRef() 
    return ++m_cRef;
    //#]
}

long Brakes::Release() {
    //#[ operation Release() 
    m_cRef--;
    if (m_cRef <= 0)
      delete this;
    
    return m_cRef;
    //#]
}

void Brakes::SetName(const _TCHAR * caption) {
    //#[ operation SetName(const _TCHAR * ) 
    m_dialog->SetCaption(caption);
    
    //#]
}

void Brakes::clean() {
    //#[ operation clean() 
    if (m_dialog)
    {
    	delete m_dialog;
    	m_dialog = NULL;
    }
    
    //#]
}

void Brakes::getPosition(double*  val) {
    //#[ operation getPosition(double*) 
    m_dialog->get_Position(val);
    
    //#]
}

void Brakes::handle_tick() {
    //#[ operation handle_tick() 
    if(!bInit) init();
    broadcast();
    //#]
}

void Brakes::init() {
    //#[ operation init() 
      //HRESULT hr = S_OK;  
      //hr = CoCreateInstance(CLSID_OnPlotDlgMgr, NULL, CLSCTX_INPROC_SERVER, IID__OnPlotDlgMgr, (void**) &m_dlg);
      //m_dlg->ShowBrakes();
      //_ASSERTE(hr == S_OK);
      //bInit=true;
    
      m_dialog = new CBrakeDialog();
      m_dialog->Show();
      bInit = true;
    //#]
}

void Brakes::setPosition(double * val) {
    //#[ operation setPosition(double * ) 
    m_dialog->put_Position(val);
    
    //#]
}




/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Brakes.cpp
*********************************************************************/

