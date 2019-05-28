/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Brakes
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Brakes.cpp
*********************************************************************/

#include "Brakes.h"
#include "CBrakeDlg.h"
#include "EventBroadcast.h"
#include "OnModelBase.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// Brakes.cpp                                                                  
//----------------------------------------------------------------------------
//## class Brakes 



Brakes::Brakes() : m_cRef(0) ,bInit(false) {
    m_dlg = NULL;
    //#[ operation Brakes() 
    init();
    
    //#]
}

Brakes::~Brakes() {
    //#[ operation ~Brakes() 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    clean( );
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
    cleanUpRelations();
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
    m_dlg->SetCaption(caption);
    //#]
}

void Brakes::clean() {
    //#[ operation clean() 
    if (m_dlg)
      delete m_dlg;
    
    //#]
}

void Brakes::getPosition(double*  val) {
    //#[ operation getPosition(double*) 
    m_dlg->get_Position(val);
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
    m_dlg = new CBrakeDlg();
    bInit=true;
    
    //#]
}

void Brakes::setPosition(double * val) {
    //#[ operation setPosition(double * ) 
    m_dlg->put_Position(*val);
    
    //#]
}

bool  Brakes::getBInit() const {
    return bInit;
}

void Brakes::setBInit(bool p_bInit) {
    bInit = p_bInit;
}

long Brakes::getM_cRef() const {
    return m_cRef;
}

void Brakes::setM_cRef(long  p_m_cRef) {
    m_cRef = p_m_cRef;
}

CBrakeDlg* Brakes::getM_dlg() const {
    return m_dlg;
}

void Brakes::setM_dlg(CBrakeDlg*  p_CBrakeDlg) {
    m_dlg = p_CBrakeDlg;
}

void Brakes::cleanUpRelations() {
    if(m_dlg != NULL)
        {
            m_dlg = NULL;
        }
}



/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Brakes.cpp
*********************************************************************/

