/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DemoDrivetrainSubsystem
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrainSubsystem.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "DemoDrivetrainSubsystem.h"
#include "DemoDrivetrain.h"

//## package Application 


//#[ ignore 
#define Application_DemoDrivetrainSubsystem_DemoDrivetrainSubsystem_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_AddRef_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_AfterEvent_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_BeforeEvent_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_GetIDsOfNames_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_GetTypeInfo_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_GetTypeInfoCount_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_Invoke_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_Load_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_QueryInterface_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_Release_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_Save_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_clean_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_handle_tick_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_init_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_initSimulation_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_printData_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainSubsystem_termSimulation_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// DemoDrivetrainSubsystem.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class DemoDrivetrainSubsystem 



DemoDrivetrainSubsystem::DemoDrivetrainSubsystem() : m_cRef(1) ,m_pdw(0) ,psaVarVals(NULL) ,varVals(NULL) ,nVars(0) ,Car(NULL) ,aDC(NULL) ,aOB(NULL) ,aIOC(NULL) ,aPOC(NULL) ,aFC(NULL) ,gPOC(NULL) ,POC(NULL) ,gOB(NULL) ,gIOC(NULL) ,IOC(NULL) ,OB(NULL) ,itsGearbox(NULL) ,DC(NULL) ,itsEngine(NULL) ,itsTC(NULL) ,FC(NULL) {
    NOTIFY_CONSTRUCTOR(DemoDrivetrainSubsystem, DemoDrivetrainSubsystem(), 0, Application_DemoDrivetrainSubsystem_DemoDrivetrainSubsystem_SERIALIZE);
    //#[ operation DemoDrivetrainSubsystem() 
    init();
    //#]
}

DemoDrivetrainSubsystem::~DemoDrivetrainSubsystem() {
    NOTIFY_DESTRUCTOR(~DemoDrivetrainSubsystem, TRUE);
    clean();
    //#[ operation ~DemoDrivetrainSubsystem() 
    
}

void DemoDrivetrainSubsystem::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_DemoDrivetrainSubsystem_clean_SERIALIZE);
    //#[ operation clean() 
    
    
    if (Car)
    {
      Car->Release();
      Car = NULL;
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
    if (gOB)
    {
      gOB->Release();
      gOB = NULL;
    }
    if (gIOC)
    {
      gIOC->Release();
      gIOC = NULL;
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
    if (itsGearbox)
    {
      itsGearbox->Release();
      itsGearbox = NULL;
    }
    if (DC)
    {
      DC->Release();
      DC = NULL;
    }
    if (itsEngine)
    {
      itsEngine->Release();
      itsEngine = NULL;
    }
    if (itsTC)
    {
      itsTC->Release();
      itsTC = NULL;
    }
    if (FC)
    {
      FC->Release();
      FC = NULL;
    }
    
    if (m_pModelExec)
    {
      AtlUnadvise(m_pModelExec, IID_IOnModelExecEvents, m_pdw);
      m_pModelExec->SetModel(NULL);
      m_pModelExec->Release();
      m_pModelExec = NULL;
    }
    
    if (m_pModel)
    {
      m_pModel->Release();
      m_pModel = NULL;
    }
    
    CoUninitialize();

    //baseClean();
    //#]
}

void DemoDrivetrainSubsystem::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_DemoDrivetrainSubsystem_init_SERIALIZE);
    //#[ operation init() 
    
    //baseInit();

    IIsDaeEsoCImpl* pEso = NULL;
    long nVars = 0;
    long i;
    HRESULT hr = S_OK;
    
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
    m_pModel->get_Eso(L"Car", &Car);
    m_pModel->get_Eso(L"aDC", &aDC);
    m_pModel->get_Eso(L"aOB", &aOB);
    m_pModel->get_Eso(L"aIOC", &aIOC);
    m_pModel->get_Eso(L"aPOC", &aPOC);
    m_pModel->get_Eso(L"aFC", &aFC);
    m_pModel->get_Eso(L"gPOC", &gPOC);
    m_pModel->get_Eso(L"POC", &POC);
    m_pModel->get_Eso(L"gOB", &gOB);
    m_pModel->get_Eso(L"gIOC", &gIOC);
    m_pModel->get_Eso(L"IOC", &IOC);
    m_pModel->get_Eso(L"OB", &OB);
    m_pModel->get_Eso(L"itsGearbox", &itsGearbox);
    m_pModel->get_Eso(L"DC", &DC);
    m_pModel->get_Eso(L"itsEngine", &itsEngine);
    m_pModel->get_Eso(L"itsTC", &itsTC);
    m_pModel->get_Eso(L"FC", &FC);
    // end sub model initialization
    
    //#]
}




#ifdef _OMINSTRUMENT


void OMAnimatedDemoDrivetrainSubsystem::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedDemoDrivetrainSubsystem::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("m_pSystemModel", FALSE, TRUE);
    if(myReal->m_pSystemModel)
        aomsRelations->ADD_ITEM(myReal->m_pSystemModel);
}

IMPLEMENT_META(DemoDrivetrainSubsystem, Application, FALSE, OMAnimatedDemoDrivetrainSubsystem)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrainSubsystem.cpp
*********************************************************************/

