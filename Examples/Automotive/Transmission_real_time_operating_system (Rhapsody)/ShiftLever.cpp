/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ShiftLever
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\ShiftLever.cpp
*********************************************************************/

#include "ShiftLever.h"
#include "CShiftDlg.h"
#include "EventBroadcast.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// ShiftLever.cpp                                                                  
//----------------------------------------------------------------------------
//## class ShiftLever 



ShiftLever::ShiftLever() : m_cRef(0) ,bInit(false)  
//}}SCG_OP_INFO
 {
    m_dlg = NULL;
    //#[ operation ShiftLever() 
    init();
    
    //#]
}

ShiftLever::~ShiftLever() {
    //#[ operation ~ShiftLever() 
    clean();
    
    //#]
    cleanUpRelations();
}

long ShiftLever::AddRef() {
    //#[ operation AddRef() 
    return ++m_cRef;
    //#]
}

long ShiftLever::Release() {
    //#[ operation Release() 
    m_cRef--;
    if (m_cRef <= 0)
      delete this;
    
    return m_cRef;
    //#]
}

void ShiftLever::SetName(LPCTSTR cszName) {
    //#[ operation SetName(LPCTSTR ) 
    m_dlg->SetCaption(cszName);
    //#]
}

void ShiftLever::clean() {
    //#[ operation clean() 
     if (m_dlg)
      {
        delete m_dlg;
        m_dlg = NULL;
      }
    
    //#]
}

void ShiftLever::get_Position(long * val) {
    //#[ operation get_Position(long * ) 
    m_dlg->get_Position(val);
    //#]
}

void ShiftLever::handle_tick() {
    //#[ operation handle_tick() 
        if(!bInit) init();
        broadcast();
    //#]
}

void ShiftLever::init() {
    //#[ operation init() 
    m_dlg = new CShiftDlg();
    m_dlg->Show();
    bInit=true;
    
    //#]
}

void ShiftLever::put_Position(long * val) {
    //#[ operation put_Position(long * ) 
    m_dlg->put_Position(val);
    //#]
}

bool  ShiftLever::getBInit() const {
    return bInit;
}

void ShiftLever::setBInit(bool p_bInit) {
    bInit = p_bInit;
}

long ShiftLever::getM_cRef() const {
    return m_cRef;
}

void ShiftLever::setM_cRef(long  p_m_cRef) {
    m_cRef = p_m_cRef;
}

CShiftDlg* ShiftLever::getM_dlg() const {
    return m_dlg;
}

void ShiftLever::setM_dlg(CShiftDlg*  p_CShiftDlg) {
    m_dlg = p_CShiftDlg;
}

void ShiftLever::cleanUpRelations() {
    if(m_dlg != NULL)
        {
            m_dlg = NULL;
        }
}



/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ShiftLever.cpp
*********************************************************************/

