/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: TestDrivetrainSS
//!	Generated Date	: Fri, 27, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrainSS.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "TestDrivetrainSS.h"

//## package Application 


//#[ ignore 
#define Application_TestDrivetrainSS_TestDrivetrainSS_SERIALIZE OM_NO_OP


#define Application_TestDrivetrainSS_clean_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// TestDrivetrainSS.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class TestDrivetrainSS 



TestDrivetrainSS::TestDrivetrainSS() : DC(NULL) ,aDC(NULL) ,RC(NULL) ,aRC(NULL) ,gOB(NULL) ,OB(NULL) ,aOB(NULL) ,aLRB(NULL) ,gLRB(NULL) ,LRB(NULL) ,itsRavigneaux(NULL) ,gPOC(NULL) ,POC(NULL) ,aPOC(NULL) ,FC(NULL) ,aFC(NULL) ,itsTorqueConverter(NULL) ,itsEngine(NULL) ,itsVehicle(NULL) ,IOC(NULL) ,gIOC(NULL) ,aIOC(NULL) {
    NOTIFY_CONSTRUCTOR(TestDrivetrainSS, TestDrivetrainSS(), 0, Application_TestDrivetrainSS_TestDrivetrainSS_SERIALIZE);
}

TestDrivetrainSS::~TestDrivetrainSS() {
    NOTIFY_DESTRUCTOR(~TestDrivetrainSS, TRUE);
}

bool TestDrivetrainSS::Load(const BSTR  filename) {
    //#[ operation Load(const BSTR) 
    
    if (SUCCEEDED( m_pModelExec->Load(filename) ))
      return true;
    else
      return false;
    //#]
}

void TestDrivetrainSS::Save(const BSTR  filename) {
    //#[ operation Save(const BSTR) 
    
    m_pModelExec->Save(filename);
    //#]
}

void TestDrivetrainSS::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_TestDrivetrainSS_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (DC)
    {
      DC->Release();
      DC = NULL;
    }
    if (aDC)
    {
      aDC->Release();
      aDC = NULL;
    }
    if (RC)
    {
      RC->Release();
      RC = NULL;
    }
    if (aRC)
    {
      aRC->Release();
      aRC = NULL;
    }
    if (gOB)
    {
      gOB->Release();
      gOB = NULL;
    }
    if (OB)
    {
      OB->Release();
      OB = NULL;
    }
    if (aOB)
    {
      aOB->Release();
      aOB = NULL;
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
    if (itsRavigneaux)
    {
      itsRavigneaux->Release();
      itsRavigneaux = NULL;
    }
    if (gPOC)
    {
      gPOC->Release();
      gPOC = NULL;
    }
    if (POC)
    {
      POC->Release();
      POC = NULL;
    }
    if (aPOC)
    {
      aPOC->Release();
      aPOC = NULL;
    }
    if (FC)
    {
      FC->Release();
      FC = NULL;
    }
    if (aFC)
    {
      aFC->Release();
      aFC = NULL;
    }
    if (itsTorqueConverter)
    {
      itsTorqueConverter->Release();
      itsTorqueConverter = NULL;
    }
    if (itsEngine)
    {
      itsEngine->Release();
      itsEngine = NULL;
    }
    if (itsVehicle)
    {
      itsVehicle->Release();
      itsVehicle = NULL;
    }
    if (IOC)
    {
      IOC->Release();
      IOC = NULL;
    }
    if (gIOC)
    {
      gIOC->Release();
      gIOC = NULL;
    }
    if (aIOC)
    {
      aIOC->Release();
      aIOC = NULL;
    }
    //#]
}

void TestDrivetrainSS::init() {
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
    m_pModel->get_Eso(L"DC", &DC);
    m_pModel->get_Eso(L"aDC", &aDC);
    m_pModel->get_Eso(L"RC", &RC);
    m_pModel->get_Eso(L"aRC", &aRC);
    m_pModel->get_Eso(L"gOB", &gOB);
    m_pModel->get_Eso(L"OB", &OB);
    m_pModel->get_Eso(L"aOB", &aOB);
    m_pModel->get_Eso(L"aLRB", &aLRB);
    m_pModel->get_Eso(L"gLRB", &gLRB);
    m_pModel->get_Eso(L"LRB", &LRB);
    m_pModel->get_Eso(L"itsRavigneaux", &itsRavigneaux);
    m_pModel->get_Eso(L"gPOC", &gPOC);
    m_pModel->get_Eso(L"POC", &POC);
    m_pModel->get_Eso(L"aPOC", &aPOC);
    m_pModel->get_Eso(L"FC", &FC);
    m_pModel->get_Eso(L"aFC", &aFC);
    m_pModel->get_Eso(L"itsTorqueConverter", &itsTorqueConverter);
    m_pModel->get_Eso(L"itsEngine", &itsEngine);
    m_pModel->get_Eso(L"itsVehicle", &itsVehicle);
    m_pModel->get_Eso(L"IOC", &IOC);
    m_pModel->get_Eso(L"gIOC", &gIOC);
    m_pModel->get_Eso(L"aIOC", &aIOC);
    // end sub model initialization
    
    //#]
}

void TestDrivetrainSS::setDC(IIsDaeEsoCImpl*  p_DC) {
    DC = p_DC;
}

void TestDrivetrainSS::setFC(IIsDaeEsoCImpl*  p_FC) {
    FC = p_FC;
}

void TestDrivetrainSS::setIOC(IIsDaeEsoCImpl*  p_IOC) {
    IOC = p_IOC;
}

void TestDrivetrainSS::setLRB(IIsDaeEsoCImpl*  p_LRB) {
    LRB = p_LRB;
}

void TestDrivetrainSS::setOB(IIsDaeEsoCImpl*  p_OB) {
    OB = p_OB;
}

void TestDrivetrainSS::setPOC(IIsDaeEsoCImpl*  p_POC) {
    POC = p_POC;
}

void TestDrivetrainSS::setRC(IIsDaeEsoCImpl*  p_RC) {
    RC = p_RC;
}

void TestDrivetrainSS::setADC(IIsDaeEsoCImpl*  p_aDC) {
    aDC = p_aDC;
}

void TestDrivetrainSS::setAFC(IIsDaeEsoCImpl*  p_aFC) {
    aFC = p_aFC;
}

void TestDrivetrainSS::setAIOC(IIsDaeEsoCImpl*  p_aIOC) {
    aIOC = p_aIOC;
}

void TestDrivetrainSS::setALRB(IIsDaeEsoCImpl*  p_aLRB) {
    aLRB = p_aLRB;
}

void TestDrivetrainSS::setAOB(IIsDaeEsoCImpl*  p_aOB) {
    aOB = p_aOB;
}

void TestDrivetrainSS::setAPOC(IIsDaeEsoCImpl*  p_aPOC) {
    aPOC = p_aPOC;
}

void TestDrivetrainSS::setARC(IIsDaeEsoCImpl*  p_aRC) {
    aRC = p_aRC;
}

void TestDrivetrainSS::setGIOC(IIsDaeEsoCImpl*  p_gIOC) {
    gIOC = p_gIOC;
}

void TestDrivetrainSS::setGLRB(IIsDaeEsoCImpl*  p_gLRB) {
    gLRB = p_gLRB;
}

void TestDrivetrainSS::setGOB(IIsDaeEsoCImpl*  p_gOB) {
    gOB = p_gOB;
}

void TestDrivetrainSS::setGPOC(IIsDaeEsoCImpl*  p_gPOC) {
    gPOC = p_gPOC;
}

void TestDrivetrainSS::setItsEngine(IIsDaeEsoCImpl*  p_itsEngine) {
    itsEngine = p_itsEngine;
}

void TestDrivetrainSS::setItsRavigneaux(IIsDaeEsoCImpl*  p_itsRavigneaux) {
    itsRavigneaux = p_itsRavigneaux;
}

void TestDrivetrainSS::setItsTorqueConverter(IIsDaeEsoCImpl*  p_itsTorqueConverter) {
    itsTorqueConverter = p_itsTorqueConverter;
}

void TestDrivetrainSS::setItsVehicle(IIsDaeEsoCImpl*  p_itsVehicle) {
    itsVehicle = p_itsVehicle;
}



#ifdef _OMINSTRUMENT


void OMAnimatedTestDrivetrainSS::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(TestDrivetrainSS, Application, FALSE, OMAnimatedTestDrivetrainSS)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrainSS.cpp
*********************************************************************/

