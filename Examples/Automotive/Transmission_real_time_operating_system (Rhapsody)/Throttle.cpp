/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Throttle
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Throttle.cpp
*********************************************************************/

#include "Throttle.h"
#include "CThrottleDlg.h"
#include "EventBroadcast.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// Throttle.cpp                                                                  
//----------------------------------------------------------------------------
//## class Throttle 



Throttle::Throttle() : m_cRef(0) ,bInit(false)  
//}}SCG_OP_INFO
 {
    m_dlg = NULL;
    //#[ operation Throttle() 
    init();
    
    //#]
}

Throttle::~Throttle() {
    //#[ operation ~Throttle() 
    clean( );
    
    //#]
    cleanUpRelations();
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
    CComBSTR szCaption = caption;
    m_dlg->SetCaption(szCaption);
    //#]
}

void Throttle::clean() {
    //#[ operation clean() 
    if (m_dlg)
    {
      delete m_dlg;
      m_dlg = NULL;
    }
    
    //#]
}

void Throttle::getPosition(double*  val) {
    //#[ operation getPosition(double*) 
    m_dlg->getThrottle(val);
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
    m_dlg = new CThrottleDlg();
    m_dlg->Show();
    double val;
    m_dlg->getThrottle(&val);
    bInit=true;
    
    //#]
}

void Throttle::setPosition(double * val) {
    //#[ operation setPosition(double * ) 
    m_dlg->setThrottle(val);
    //#]
}

bool Throttle::getBInit() const {
    return bInit;
}

void Throttle::setBInit(bool  p_bInit) {
    bInit = p_bInit;
}

long Throttle::getM_cRef() const {
    return m_cRef;
}

void Throttle::setM_cRef(long  p_m_cRef) {
    m_cRef = p_m_cRef;
}

CThrottleDlg* Throttle::getM_dlg() const {
    return m_dlg;
}

void Throttle::setM_dlg(CThrottleDlg*  p_CThrottleDlg) {
    m_dlg = p_CThrottleDlg;
}

void Throttle::cleanUpRelations() {
    if(m_dlg != NULL)
        {
            m_dlg = NULL;
        }
}



/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Throttle.cpp
*********************************************************************/

