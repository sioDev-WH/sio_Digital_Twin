/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ExtCarSS
//!	Generated Date	: Thu, 19, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\ExtCarSS.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "ExtCarSS.h"

//## package AppSimple 


//#[ ignore 
#define AppSimple_ExtCarSS_ExtCarSS_SERIALIZE OM_NO_OP


#define AppSimple_ExtCarSS_clean_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// ExtCarSS.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class ExtCarSS 



ExtCarSS::ExtCarSS() : aRC(NULL) ,aLRB(NULL) ,gLRB(NULL) ,LRB(NULL) ,RC(NULL) ,itsEngine(NULL) ,gOB(NULL) ,gPOC(NULL) ,itsTorqueConverter(NULL) ,itsVehicle(NULL) ,itsGearbox(NULL) ,aPOC(NULL) ,aFC(NULL) ,aDC(NULL) ,aOB(NULL) ,aIOC(NULL) ,gIOC(NULL) ,POC(NULL) ,IOC(NULL) ,OB(NULL) ,DC(NULL) ,FC(NULL) {
    NOTIFY_CONSTRUCTOR(ExtCarSS, ExtCarSS(), 0, AppSimple_ExtCarSS_ExtCarSS_SERIALIZE);
}

ExtCarSS::~ExtCarSS() {
    NOTIFY_DESTRUCTOR(~ExtCarSS, TRUE);
}

bool ExtCarSS::Load(const BSTR  filename) {
    //#[ operation Load(const BSTR) 
    
    if (SUCCEEDED( m_pModelExec->Load(filename) ))
      return true;
    else
      return false;
    //#]
}

void ExtCarSS::Save(const BSTR  filename) {
    //#[ operation Save(const BSTR) 
    
    m_pModelExec->Save(filename);
    //#]
}

void ExtCarSS::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, AppSimple_ExtCarSS_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (aRC)
    {
      aRC->Release();
      aRC = NULL;
    }
    if (aLRB)
    {
      aLRB->Release();
      aLRB = NULL;
    }
    if (gLRB)
    {
      gLRB->Release();
      gLRB = NULL;
    }
    if (LRB)
    {
      LRB->Release();
      LRB = NULL;
    }
    if (RC)
    {
      RC->Release();
      RC = NULL;
    }
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

void ExtCarSS::init() {
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
    m_pModel->get_Eso(L"aRC", &aRC);
    m_pModel->get_Eso(L"aLRB", &aLRB);
    m_pModel->get_Eso(L"gLRB", &gLRB);
    m_pModel->get_Eso(L"LRB", &LRB);
    m_pModel->get_Eso(L"RC", &RC);
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

void ExtCarSS::setDC(IIsDaeEsoCImpl*  p_DC) {
    DC = p_DC;
}

void ExtCarSS::setFC(IIsDaeEsoCImpl*  p_FC) {
    FC = p_FC;
}

void ExtCarSS::setIOC(IIsDaeEsoCImpl*  p_IOC) {
    IOC = p_IOC;
}

void ExtCarSS::setLRB(IIsDaeEsoCImpl*  p_LRB) {
    LRB = p_LRB;
}

void ExtCarSS::setOB(IIsDaeEsoCImpl*  p_OB) {
    OB = p_OB;
}

void ExtCarSS::setPOC(IIsDaeEsoCImpl*  p_POC) {
    POC = p_POC;
}

void ExtCarSS::setRC(IIsDaeEsoCImpl*  p_RC) {
    RC = p_RC;
}

void ExtCarSS::setADC(IIsDaeEsoCImpl*  p_aDC) {
    aDC = p_aDC;
}

void ExtCarSS::setAFC(IIsDaeEsoCImpl*  p_aFC) {
    aFC = p_aFC;
}

void ExtCarSS::setAIOC(IIsDaeEsoCImpl*  p_aIOC) {
    aIOC = p_aIOC;
}

void ExtCarSS::setALRB(IIsDaeEsoCImpl*  p_aLRB) {
    aLRB = p_aLRB;
}

void ExtCarSS::setAOB(IIsDaeEsoCImpl*  p_aOB) {
    aOB = p_aOB;
}

void ExtCarSS::setAPOC(IIsDaeEsoCImpl*  p_aPOC) {
    aPOC = p_aPOC;
}

void ExtCarSS::setARC(IIsDaeEsoCImpl*  p_aRC) {
    aRC = p_aRC;
}

void ExtCarSS::setGIOC(IIsDaeEsoCImpl*  p_gIOC) {
    gIOC = p_gIOC;
}

void ExtCarSS::setGLRB(IIsDaeEsoCImpl*  p_gLRB) {
    gLRB = p_gLRB;
}

void ExtCarSS::setGOB(IIsDaeEsoCImpl*  p_gOB) {
    gOB = p_gOB;
}

void ExtCarSS::setGPOC(IIsDaeEsoCImpl*  p_gPOC) {
    gPOC = p_gPOC;
}

void ExtCarSS::setItsEngine(IIsDaeEsoCImpl*  p_itsEngine) {
    itsEngine = p_itsEngine;
}

void ExtCarSS::setItsGearbox(IIsDaeEsoCImpl*  p_itsGearbox) {
    itsGearbox = p_itsGearbox;
}

void ExtCarSS::setItsTorqueConverter(IIsDaeEsoCImpl*  p_itsTorqueConverter) {
    itsTorqueConverter = p_itsTorqueConverter;
}

void ExtCarSS::setItsVehicle(IIsDaeEsoCImpl*  p_itsVehicle) {
    itsVehicle = p_itsVehicle;
}



#ifdef _OMINSTRUMENT


void OMAnimatedExtCarSS::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(ExtCarSS, AppSimple, FALSE, OMAnimatedExtCarSS)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ExtCarSS.cpp
*********************************************************************/

