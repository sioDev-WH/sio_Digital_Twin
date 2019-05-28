/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AppAirFrame
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AppAirFrame.cpp
*********************************************************************/

#include "AppAirFrame.h"

//## package Default 

//----------------------------------------------------------------------------
// AppAirFrame.cpp                                                                  
//----------------------------------------------------------------------------
//## class AppAirFrame 


AppAirFrame::AppAirFrame() {
}

AppAirFrame::~AppAirFrame() {
}

bool AppAirFrame::Load(const BSTR  filename) {
    //#[ operation Load(const BSTR) 
    
    if (SUCCEEDED( m_pModelExec->Load(filename) ))
      return true;
    else
      return false;
    //#]
}

void AppAirFrame::Save(const BSTR  filename) {
    //#[ operation Save(const BSTR) 
    
    m_pModelExec->Save(filename);
    //#]
}

void AppAirFrame::clean() {
    //#[ operation clean() 

/*  
    if (aeroCompositionBlock)
    {
      aeroCompositionBlock->Release();
      aeroCompositionBlock = NULL;
    }
*/
    //#]
}

void AppAirFrame::init() {
    //#[ operation init() 
    
    long i;
    
    m_pModelExec->put_MaxStepSize(0.001);
    
    // tolerance initialization
    m_pModel->GetNumVars(&nVars);
    SAFEARRAY* psa_atol = SafeArrayCreateVector(VT_R8, 0, nVars);
    SAFEARRAY* psa_rtol = SafeArrayCreateVector(VT_R8, 0, nVars);
    double* v_atol = NULL;
    double* v_rtol = NULL;
    SafeArrayAccessData(psa_atol, (void HUGEP* FAR*)& v_atol);
    SafeArrayAccessData(psa_rtol, (void HUGEP* FAR*)& v_rtol);
    
    // TODO: modify tolerances as necessary
    for (i = 0; i < nVars; i++)
    {
      v_atol[i] = 1.0e-4;
      v_rtol[i] = 1.0e-4;
    }
    
    SafeArrayUnaccessData(psa_atol);
    SafeArrayUnaccessData(psa_atol);
    m_pModel->SetAbsTolerance(&psa_atol);
    m_pModel->SetRelTolerance(&psa_rtol);
    SafeArrayDestroy(psa_atol);
    SafeArrayDestroy(psa_rtol);
    // end tolerance initialization
    
    
    // time initialization
    m_pModel->InitTime(0.0, VARIANT_FALSE);
    // end time initialization
    
    // sub model initialization
    // end sub model initialization
    
    //#]
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AppAirFrame.cpp
*********************************************************************/

