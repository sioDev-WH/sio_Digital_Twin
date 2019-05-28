/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: StdCarSS
//!	Generated Date	: Wed, 18, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\StdCarSS.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "StdCarSS.h"

//## package AppSimple 


//#[ ignore 
#define AppSimple_StdCarSS_StdCarSS_SERIALIZE OM_NO_OP


#define AppSimple_StdCarSS_clean_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// StdCarSS.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class StdCarSS 



StdCarSS::StdCarSS() : itsEngine(NULL) ,gOB(NULL) ,gPOC(NULL) ,itsTorqueConverter(NULL) ,itsVehicle(NULL) ,itsGearbox(NULL) ,aPOC(NULL) ,aFC(NULL) ,aDC(NULL) ,aOB(NULL) ,aIOC(NULL) ,gIOC(NULL) ,POC(NULL) ,IOC(NULL) ,OB(NULL) ,DC(NULL) ,FC(NULL) {
    NOTIFY_CONSTRUCTOR(StdCarSS, StdCarSS(), 0, AppSimple_StdCarSS_StdCarSS_SERIALIZE);
}

StdCarSS::~StdCarSS() {
    NOTIFY_DESTRUCTOR(~StdCarSS, TRUE);
}

bool StdCarSS::Load(const BSTR  filename) {
    //#[ operation Load(const BSTR) 
    
    if (SUCCEEDED( m_pModelExec->Load(filename) ))
      return true;
    else
      return false;
    //#]
}

void StdCarSS::Save(const BSTR  filename) {
    //#[ operation Save(const BSTR) 
    
    m_pModelExec->Save(filename);
    //#]
}

void StdCarSS::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, AppSimple_StdCarSS_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (itsEngine)
    {
      itsEngine->Release();
      itsEngine = NULL;
    }
    if (gOB)
    {
      gOB->Release();
      gOB = NULL;
    }
    if (gPOC)
    {
      gPOC->Release();
      gPOC = NULL;
    }
    if (itsTorqueConverter)
    {
      itsTorqueConverter->Release();
      itsTorqueConverter = NULL;
    }
    if (itsVehicle)
    {
      itsVehicle->Release();
      itsVehicle = NULL;
    }
    if (itsGearbox)
    {
      itsGearbox->Release();
      itsGearbox = NULL;
    }
    if (aPOC)
    {
      aPOC->Release();
      aPOC = NULL;
    }
    if (aFC)
    {
      aFC->Release();
      aFC = NULL;
    }
    if (aDC)
    {
      aDC->Release();
      aDC = NULL;
    }
    if (aOB)
    {
      aOB->Release();
      aOB = NULL;
    }
    if (aIOC)
    {
      aIOC->Release();
      aIOC = NULL;
    }
    if (gIOC)
    {
      gIOC->Release();
      gIOC = NULL;
    }
    if (POC)
    {
      POC->Release();
      POC = NULL;
    }
    if (IOC)
    {
      IOC->Release();
      IOC = NULL;
    }
    if (OB)
    {
      OB->Release();
      OB = NULL;
    }
    if (DC)
    {
      DC->Release();
      DC = NULL;
    }
    if (FC)
    {
      FC->Release();
      FC = NULL;
    }
    
    //#]
}

 StdCarSS::init() {
    //#[ operation init() 
    
    long i;
    
    
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
    m_pModel->get_Eso(L"itsEngine", &itsEngine);
    m_pModel->get_Eso(L"gOB", &gOB);
    m_pModel->get_Eso(L"gPOC", &gPOC);
    m_pModel->get_Eso(L"itsTorqueConverter", &itsTorqueConverter);
    m_pModel->get_Eso(L"itsVehicle", &itsVehicle);
    m_pModel->get_Eso(L"itsGearbox", &itsGearbox);
    m_pModel->get_Eso(L"aPOC", &aPOC);
    m_pModel->get_Eso(L"aFC", &aFC);
    m_pModel->get_Eso(L"aDC", &aDC);
    m_pModel->get_Eso(L"aOB", &aOB);
    m_pModel->get_Eso(L"aIOC", &aIOC);
    m_pModel->get_Eso(L"gIOC", &gIOC);
    m_pModel->get_Eso(L"POC", &POC);
    m_pModel->get_Eso(L"IOC", &IOC);
    m_pModel->get_Eso(L"OB", &OB);
    m_pModel->get_Eso(L"DC", &DC);
    m_pModel->get_Eso(L"FC", &FC);
    // end sub model initialization
    
    //#]
}

void StdCarSS::setDC(IIsDaeEsoCImpl*  p_DC) {
    DC = p_DC;
}

void StdCarSS::setFC(IIsDaeEsoCImpl*  p_FC) {
    FC = p_FC;
}

void StdCarSS::setIOC(IIsDaeEsoCImpl*  p_IOC) {
    IOC = p_IOC;
}

void StdCarSS::setOB(IIsDaeEsoCImpl*  p_OB) {
    OB = p_OB;
}

void StdCarSS::setPOC(IIsDaeEsoCImpl*  p_POC) {
    POC = p_POC;
}

void StdCarSS::setADC(IIsDaeEsoCImpl*  p_aDC) {
    aDC = p_aDC;
}

void StdCarSS::setAFC(IIsDaeEsoCImpl*  p_aFC) {
    aFC = p_aFC;
}

void StdCarSS::setAIOC(IIsDaeEsoCImpl*  p_aIOC) {
    aIOC = p_aIOC;
}

void StdCarSS::setAOB(IIsDaeEsoCImpl*  p_aOB) {
    aOB = p_aOB;
}

void StdCarSS::setAPOC(IIsDaeEsoCImpl*  p_aPOC) {
    aPOC = p_aPOC;
}

void StdCarSS::setGIOC(IIsDaeEsoCImpl*  p_gIOC) {
    gIOC = p_gIOC;
}

void StdCarSS::setGOB(IIsDaeEsoCImpl*  p_gOB) {
    gOB = p_gOB;
}

void StdCarSS::setGPOC(IIsDaeEsoCImpl*  p_gPOC) {
    gPOC = p_gPOC;
}

void StdCarSS::setItsEngine(IIsDaeEsoCImpl*  p_itsEngine) {
    itsEngine = p_itsEngine;
}

void StdCarSS::setItsGearbox(IIsDaeEsoCImpl*  p_itsGearbox) {
    itsGearbox = p_itsGearbox;
}

void StdCarSS::setItsTorqueConverter(IIsDaeEsoCImpl*  p_itsTorqueConverter) {
    itsTorqueConverter = p_itsTorqueConverter;
}

void StdCarSS::setItsVehicle(IIsDaeEsoCImpl*  p_itsVehicle) {
    itsVehicle = p_itsVehicle;
}



#ifdef _OMINSTRUMENT


void OMAnimatedStdCarSS::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(StdCarSS, AppSimple, FALSE, OMAnimatedStdCarSS)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\StdCarSS.cpp
*********************************************************************/

