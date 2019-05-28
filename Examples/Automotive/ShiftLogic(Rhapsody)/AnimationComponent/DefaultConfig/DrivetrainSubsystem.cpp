/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DrivetrainSubsystem
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DrivetrainSubsystem.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "DrivetrainSubsystem.h"
#include "Drivetrain.h"

//## package Application 


//#[ ignore 
#define Application_DrivetrainSubsystem_DrivetrainSubsystem_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_AddRef_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_AfterEvent_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_BeforeEvent_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_GetIDsOfNames_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_GetTypeInfo_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_GetTypeInfoCount_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_Invoke_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_Load_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_QueryInterface_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_Release_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_Save_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_clean_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_handle_tick_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_init_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_initSimulation_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_printData_SERIALIZE OM_NO_OP


#define Application_DrivetrainSubsystem_termSimulation_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// DrivetrainSubsystem.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class DrivetrainSubsystem 



DrivetrainSubsystem::DrivetrainSubsystem() : m_cRef(1) ,m_pdw(0) ,psaVarVals(NULL) ,varVals(NULL) ,nVars(0) ,m_pModelExec(NULL) ,m_pModel(NULL) ,aDC(NULL) ,aOB(NULL) ,aIOC(NULL) ,aPOC(NULL) ,aFC(NULL) ,itsCar(NULL) ,gPOC(NULL) ,POC(NULL) ,gOB(NULL) ,gIOC(NULL) ,IOC(NULL) ,OB(NULL) ,itsGearbox(NULL) ,DC(NULL) ,itsEngine(NULL) ,itsTC(NULL) ,FC(NULL) {
    NOTIFY_CONSTRUCTOR(DrivetrainSubsystem, DrivetrainSubsystem(), 0, Application_DrivetrainSubsystem_DrivetrainSubsystem_SERIALIZE);
    m_pSystemModel = NULL;
    //#[ operation DrivetrainSubsystem() 
    
    init();
    initSimulation();
    //#]
}

DrivetrainSubsystem::~DrivetrainSubsystem() {
    NOTIFY_DESTRUCTOR(~DrivetrainSubsystem, TRUE);
    //#[ operation ~DrivetrainSubsystem() 
    
    termSimulation();
    clean();
    //#]
    cleanUpRelations();
}

ULONG STDMETHODCALLTYPE DrivetrainSubsystem::AddRef() {
    NOTIFY_OPERATION(AddRef, AddRef(), 0, Application_DrivetrainSubsystem_AddRef_SERIALIZE);
    //#[ operation AddRef() 
    
    return ++m_cRef;
    //#]
}

STDMETHODIMP DrivetrainSubsystem::AfterEvent(double  t) {
    NOTIFY_OPERATION(AfterEvent, AfterEvent(double), 0, Application_DrivetrainSubsystem_AfterEvent_SERIALIZE);
    //#[ operation AfterEvent(double) 
    
    printData(t);
    return S_OK;
    //#]
}

STDMETHODIMP DrivetrainSubsystem::BeforeEvent(double  t) {
    NOTIFY_OPERATION(BeforeEvent, BeforeEvent(double), 0, Application_DrivetrainSubsystem_BeforeEvent_SERIALIZE);
    //#[ operation BeforeEvent(double) 
    
    printData(t);
    return S_OK;
    //#]
}

HRESULT STDMETHODCALLTYPE DrivetrainSubsystem::GetIDsOfNames(REFIID  riid, LPOLESTR*  rgszNames, UINT  cNames, LCID  lcid, DISPID*  rgDispId) {
    NOTIFY_OPERATION(GetIDsOfNames, GetIDsOfNames(REFIID,LPOLESTR*,UINT,LCID,DISPID*), 0, Application_DrivetrainSubsystem_GetIDsOfNames_SERIALIZE);
    //#[ operation GetIDsOfNames(REFIID,LPOLESTR*,UINT,LCID,DISPID*) 
    
    return E_NOTIMPL; 
    //#]
}

HRESULT STDMETHODCALLTYPE DrivetrainSubsystem::GetTypeInfo(UINT  iTInfo, LCID  lcid, ITypeInfo**  ppTInfo) {
    NOTIFY_OPERATION(GetTypeInfo, GetTypeInfo(UINT,LCID,ITypeInfo**), 0, Application_DrivetrainSubsystem_GetTypeInfo_SERIALIZE);
    //#[ operation GetTypeInfo(UINT,LCID,ITypeInfo**) 
    
    return E_NOTIMPL; 
    //#]
}

HRESULT STDMETHODCALLTYPE DrivetrainSubsystem::GetTypeInfoCount(UINT*  pctinfo) {
    NOTIFY_OPERATION(GetTypeInfoCount, GetTypeInfoCount(UINT*), 0, Application_DrivetrainSubsystem_GetTypeInfoCount_SERIALIZE);
    //#[ operation GetTypeInfoCount(UINT*) 
    
    return E_NOTIMPL; 
    //#]
}

HRESULT STDMETHODCALLTYPE DrivetrainSubsystem::Invoke(DISPID  dispIdMember, REFIID  riid, LCID  lcid, WORD  wFlags, DISPPARAMS*  pDispParams, VARIANT*  pVarResult, EXCEPINFO*  pExcepInfo, UINT*  puArgErr) {
    NOTIFY_OPERATION(Invoke, Invoke(DISPID,REFIID,LCID,WORD,DISPPARAMS*,VARIANT*,EXCEPINFO*,UINT*), 0, Application_DrivetrainSubsystem_Invoke_SERIALIZE);
    //#[ operation Invoke(DISPID,REFIID,LCID,WORD,DISPPARAMS*,VARIANT*,EXCEPINFO*,UINT*) 
    
    return E_NOTIMPL; 
    //#]
}

bool DrivetrainSubsystem::Load(const BSTR  filename) {
    NOTIFY_OPERATION(Load, Load(const BSTR), 0, Application_DrivetrainSubsystem_Load_SERIALIZE);
    //#[ operation Load(const BSTR) 
    
    if (SUCCEEDED( m_pModelExec->Load(filename) ))
      return true;
    else
      return false;
    //#]
}

HRESULT STDMETHODCALLTYPE DrivetrainSubsystem::QueryInterface(REFIID  riid, void**  ppvObject) {
    NOTIFY_OPERATION(QueryInterface, QueryInterface(REFIID,void**), 0, Application_DrivetrainSubsystem_QueryInterface_SERIALIZE);
    //#[ operation QueryInterface(REFIID,void**) 
    
    HRESULT hr = E_FAIL;
    if (riid == IID_IOnModelExecEvents)
    {
      *ppvObject = static_cast<IOnModelExecEvents*> (this);
      AddRef();
      hr = S_OK;
    }
    return hr;
    //#]
}

ULONG STDMETHODCALLTYPE DrivetrainSubsystem::Release() {
    NOTIFY_OPERATION(Release, Release(), 0, Application_DrivetrainSubsystem_Release_SERIALIZE);
    //#[ operation Release() 
    
    m_cRef--;
    if (m_cRef <= 0) delete this;
    return m_cRef;
    //#]
}

void DrivetrainSubsystem::Save(const BSTR  filename) {
    NOTIFY_OPERATION(Save, Save(const BSTR), 0, Application_DrivetrainSubsystem_Save_SERIALIZE);
    //#[ operation Save(const BSTR) 
    
    m_pModelExec->Save(filename);
    //#]
}

void DrivetrainSubsystem::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_DrivetrainSubsystem_clean_SERIALIZE);
    //#[ operation clean() 
    
    
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
    if (itsCar)
    {
      itsCar->Release();
      itsCar = NULL;
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
    //#]
}

void DrivetrainSubsystem::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, Application_DrivetrainSubsystem_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    receive();
    const double t = getTime();
    
    HRESULT hr = m_pModelExec->Step(t);
    if (FAILED(hr)) 
    {
      m_pModelExec->ForceReset();
      hr = m_pModelExec->Step(t);
      _ASSERTE(hr == S_OK);
    }
    
    printData(t);
    
    broadcast();
    
    //#]
}

void DrivetrainSubsystem::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_DrivetrainSubsystem_init_SERIALIZE);
    //#[ operation init() 
    
    psaVarVals = NULL;
    varVals = NULL;
    nVars = 0;
    
    
    IIsDaeEsoCImpl* pEso = NULL;
    long nVars = 0;
    long i;
    HRESULT hr = S_OK;
    
    CoInitialize(NULL);
    hr = CoCreateInstance(CLSID_OnModelExec, NULL, CLSCTX_INPROC_SERVER, IID_IOnModelExec, (void**) &m_pModelExec);
    _ASSERTE(hr == S_OK);
    hr = CoCreateInstance(CLSID_IsDaeEsoCImpl, NULL, CLSCTX_INPROC_SERVER, IID_IIsDaeEsoCImpl, (void**) &m_pModel);
    _ASSERTE(hr == S_OK);
    m_pSystemModel = new Drivetrain();
    m_pModel->SetEso(m_pSystemModel);
    hr = m_pModelExec->SetModel(m_pModel);
    _ASSERTE(hr == S_OK);
    
    // event interface initialization
    IOnModelExecEvents* pEventIF = static_cast<IOnModelExecEvents*> (this);
    AtlAdvise(m_pModelExec, pEventIF, IID_IOnModelExecEvents, &m_pdw);
    
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
    m_pModel->get_Eso(L"aDC", &aDC);
    m_pModel->get_Eso(L"aOB", &aOB);
    m_pModel->get_Eso(L"aIOC", &aIOC);
    m_pModel->get_Eso(L"aPOC", &aPOC);
    m_pModel->get_Eso(L"aFC", &aFC);
    m_pModel->get_Eso(L"itsCar", &itsCar);
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

void DrivetrainSubsystem::initSimulation() {
    NOTIFY_OPERATION(initSimulation, initSimulation(), 0, Application_DrivetrainSubsystem_initSimulation_SERIALIZE);
    //#[ operation initSimulation() 
    
    HRESULT hr = S_OK;
    SAFEARRAY* psaVarNames = NULL;
    BSTR* varNames = NULL;
    long i;
    
    psaVarVals = NULL;
    varVals = NULL;
    
    USES_CONVERSION;
    // record data to file
    fs.open("DrivetrainSubsystem.txt");
    m_pModel->GetNumVars(&nVars);
    psaVarVals = SafeArrayCreateVector(VT_R8, 0, nVars);
    SafeArrayAccessData(psaVarVals, (void HUGEP* FAR*)& varVals);
    
    m_pModel->GetVarNames(&psaVarNames);
    SafeArrayAccessData(psaVarNames, (void HUGEP* FAR*)& varNames);
    fs << "time" << "\t";
    for (i = 0; i < nVars; i++)
    {
      if (varNames[i])
        fs << W2CA(varNames[i]) << "\t";
      else
        fs << "\t";
    }
    fs << "\n";
    SafeArrayUnaccessData(psaVarNames);
    SafeArrayDestroy(psaVarNames);
    psaVarNames = NULL;
    varNames = NULL;
    //#]
}

void DrivetrainSubsystem::printData(const double  t) {
    NOTIFY_OPERATION(printData, printData(const double), 0, Application_DrivetrainSubsystem_printData_SERIALIZE);
    //#[ operation printData(const double) 
    
    long i;
    
    m_pModel->GetAllVariables( t, &psaVarVals );
    fs << t << "\t";
    for (i = 0; i < nVars; i++)
      fs << varVals[i] << "\t";
    
    fs << "\n";
    
    //#]
}

void DrivetrainSubsystem::termSimulation() {
    NOTIFY_OPERATION(termSimulation, termSimulation(), 0, Application_DrivetrainSubsystem_termSimulation_SERIALIZE);
    //#[ operation termSimulation() 
    
    // cleanup
    if (psaVarVals)
    {
      SafeArrayUnaccessData(psaVarVals);
      SafeArrayDestroy(psaVarVals);
      psaVarVals = NULL;
      varVals = NULL;
    }
    fs.close();
    //#]
}

void DrivetrainSubsystem::setDC(IIsDaeEsoCImpl*  p_DC) {
    DC = p_DC;
}

void DrivetrainSubsystem::setFC(IIsDaeEsoCImpl*  p_FC) {
    FC = p_FC;
}

void DrivetrainSubsystem::setIOC(IIsDaeEsoCImpl*  p_IOC) {
    IOC = p_IOC;
}

void DrivetrainSubsystem::setOB(IIsDaeEsoCImpl*  p_OB) {
    OB = p_OB;
}

void DrivetrainSubsystem::setPOC(IIsDaeEsoCImpl*  p_POC) {
    POC = p_POC;
}

void DrivetrainSubsystem::setADC(IIsDaeEsoCImpl*  p_aDC) {
    aDC = p_aDC;
}

void DrivetrainSubsystem::setAFC(IIsDaeEsoCImpl*  p_aFC) {
    aFC = p_aFC;
}

void DrivetrainSubsystem::setAIOC(IIsDaeEsoCImpl*  p_aIOC) {
    aIOC = p_aIOC;
}

void DrivetrainSubsystem::setAOB(IIsDaeEsoCImpl*  p_aOB) {
    aOB = p_aOB;
}

void DrivetrainSubsystem::setAPOC(IIsDaeEsoCImpl*  p_aPOC) {
    aPOC = p_aPOC;
}

void DrivetrainSubsystem::setFs(ofstream  p_fs) {
    fs = p_fs;
}

void DrivetrainSubsystem::setGIOC(IIsDaeEsoCImpl*  p_gIOC) {
    gIOC = p_gIOC;
}

void DrivetrainSubsystem::setGOB(IIsDaeEsoCImpl*  p_gOB) {
    gOB = p_gOB;
}

void DrivetrainSubsystem::setGPOC(IIsDaeEsoCImpl*  p_gPOC) {
    gPOC = p_gPOC;
}

void DrivetrainSubsystem::setItsCar(IIsDaeEsoCImpl*  p_itsCar) {
    itsCar = p_itsCar;
}

void DrivetrainSubsystem::setItsEngine(IIsDaeEsoCImpl*  p_itsEngine) {
    itsEngine = p_itsEngine;
}

void DrivetrainSubsystem::setItsGearbox(IIsDaeEsoCImpl*  p_itsGearbox) {
    itsGearbox = p_itsGearbox;
}

void DrivetrainSubsystem::setItsTC(IIsDaeEsoCImpl*  p_itsTC) {
    itsTC = p_itsTC;
}

void DrivetrainSubsystem::setM_cRef(long  p_m_cRef) {
    m_cRef = p_m_cRef;
}

void DrivetrainSubsystem::setM_pModel(IIsDaeEsoCImpl*  p_m_pModel) {
    m_pModel = p_m_pModel;
}

void DrivetrainSubsystem::setM_pModelExec(IOnModelExec*  p_m_pModelExec) {
    m_pModelExec = p_m_pModelExec;
}

void DrivetrainSubsystem::setM_pdw(DWORD  p_m_pdw) {
    m_pdw = p_m_pdw;
}

void DrivetrainSubsystem::setNVars(long  p_nVars) {
    nVars = p_nVars;
}

void DrivetrainSubsystem::setPsaVarVals(SAFEARRAY*  p_psaVarVals) {
    psaVarVals = p_psaVarVals;
}

void DrivetrainSubsystem::setVarVals(double*  p_varVals) {
    varVals = p_varVals;
}

void DrivetrainSubsystem::cleanUpRelations() {
    if(m_pSystemModel != NULL)
        {
            NOTIFY_RELATION_CLEARED("m_pSystemModel");
            m_pSystemModel = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedDrivetrainSubsystem::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedDrivetrainSubsystem::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("m_pSystemModel", FALSE, TRUE);
    if(myReal->m_pSystemModel)
        aomsRelations->ADD_ITEM(myReal->m_pSystemModel);
}

IMPLEMENT_META(DrivetrainSubsystem, Application, FALSE, OMAnimatedDrivetrainSubsystem)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DrivetrainSubsystem.cpp
*********************************************************************/

