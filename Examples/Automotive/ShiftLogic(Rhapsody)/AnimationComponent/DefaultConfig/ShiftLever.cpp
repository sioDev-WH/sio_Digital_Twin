/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ShiftLever
//!	Generated Date	: Mon, 9, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\ShiftLever.cpp
*********************************************************************/

#include "ShiftLever.h"
#include "EventBroadcast.h"
//#include "OnPlot_i.c"
//#include "OnPlot.h"
#include "ShiftLeverDialog.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// ShiftLever.cpp                                                                  
//----------------------------------------------------------------------------
//## class ShiftLever 



ShiftLever::ShiftLever() : m_cRef(0) ,m_dialog(NULL) ,bInit(false)  
//}}SCG_OP_INFO
 {
    //#[ operation ShiftLever() 
    init();
    
    //#]
}

ShiftLever::~ShiftLever() {
    //#[ operation ~ShiftLever() 
    clean();
    
    //#]
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
    m_dialog->SetCaption(cszName);
    
    //#]
}

void ShiftLever::clean() {
    //#[ operation clean() 
    if (m_dialog)
    {
    	delete m_dialog;
    	m_dialog = NULL;
    }
    
    //#]
}

void ShiftLever::get_Position(long * val) {
    //#[ operation get_Position(long * ) 
    static long last_val = -10;
  
    m_dialog->get_Position(val);
    if (*val == 1 && *val != last_val)
    {
      ATLTRACE("\nforward");
      last_val = *val;
    }
    else if (*val == 0 && *val != last_val)
    {
      ATLTRACE("\nneutral");
      last_val = *val;
    }
    else if (*val == -1 && *val != last_val)
    {
      ATLTRACE("\nreverse");
      last_val = *val;
    }
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
    //HRESULT hr = S_OK;  
    //hr = CoCreateInstance(CLSID_OnPlotDlgMgr, NULL, CLSCTX_INPROC_SERVER, IID__OnPlotDlgMgr, (void**) &m_dialog);
    //hr = m_dialog->ShowShiftLever();
    //_ASSERTE(hr == S_OK);
    //bInit=true;
    
    m_dialog = new CShiftLeverDialog();
    m_dialog->Show();
    bInit = true;
    //#]
}

void ShiftLever::put_Position(long * val) {
    //#[ operation put_Position(long * ) 
      m_dialog->put_Position(val);
    
    //#]
}



/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ShiftLever.cpp
*********************************************************************/

