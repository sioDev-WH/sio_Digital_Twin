/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirframeSubsystem
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AirframeSubsystem.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "AirframeSubsystem.h"
#include "AirFrame.h"
#include "BodyDynamics.h"

//## package Application 

//----------------------------------------------------------------------------
// AirframeSubsystem.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class AirframeSubsystem 



AirframeSubsystem::AirframeSubsystem() : m_cRef(1) ,m_pdw(0) ,psaVarVals(NULL) ,varVals(NULL) ,nVars(0) {
    itsAeroDynamics = NULL;
    itsBodyDynamics = NULL;
    itsFinDynamics = NULL;
    m_pModel = NULL;
    m_pModelExec = NULL;
    m_pSystemModel = NULL;
    //#[ operation AirframeSubsystem() 
    
    init();
    initSimulation();
    //#]
}

AirframeSubsystem::~AirframeSubsystem() {
    //#[ operation ~AirframeSubsystem() 
    
    termSimulation();
    clean();
    //#]
    cleanUpRelations();
}

ULONG STDMETHODCALLTYPE AirframeSubsystem::AddRef() {
    //#[ operation AddRef() 
    
    return ++m_cRef;
    //#]
}

STDMETHODIMP AirframeSubsystem::AfterEvent(double  t) {
    //#[ operation AfterEvent(double) 
    
    printData(t);
    return S_OK;
    //#]
}

STDMETHODIMP AirframeSubsystem::BeforeEvent(double  t) {
    //#[ operation BeforeEvent(double) 
    
    printData(t);
    return S_OK;
    //#]
}

HRESULT STDMETHODCALLTYPE AirframeSubsystem::GetIDsOfNames(REFIID  riid, LPOLESTR*  rgszNames, UINT  cNames, LCID  lcid, DISPID*  rgDispId) {
    //#[ operation GetIDsOfNames(REFIID,LPOLESTR*,UINT,LCID,DISPID*) 
    
    return E_NOTIMPL; 
    //#]
}

HRESULT STDMETHODCALLTYPE AirframeSubsystem::GetTypeInfo(UINT  iTInfo, LCID  lcid, ITypeInfo**  ppTInfo) {
    //#[ operation GetTypeInfo(UINT,LCID,ITypeInfo**) 
    
    return E_NOTIMPL; 
    //#]
}

HRESULT STDMETHODCALLTYPE AirframeSubsystem::GetTypeInfoCount(UINT*  pctinfo) {
    //#[ operation GetTypeInfoCount(UINT*) 
    
    return E_NOTIMPL; 
    //#]
}

HRESULT STDMETHODCALLTYPE AirframeSubsystem::Invoke(DISPID  dispIdMember, REFIID  riid, LCID  lcid, WORD  wFlags, DISPPARAMS*  pDispParams, VARIANT*  pVarResult, EXCEPINFO*  pExcepInfo, UINT*  puArgErr) {
    //#[ operation Invoke(DISPID,REFIID,LCID,WORD,DISPPARAMS*,VARIANT*,EXCEPINFO*,UINT*) 
    
    return E_NOTIMPL; 
    //#]
}

bool AirframeSubsystem::Load(const BSTR  filename) {
    //#[ operation Load(const BSTR) 
    
    if (SUCCEEDED( m_pModelExec->Load(filename) ))
      return true;
    else
      return false;
    //#]
}

HRESULT STDMETHODCALLTYPE AirframeSubsystem::QueryInterface(REFIID  riid, void**  ppvObject) {
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

ULONG STDMETHODCALLTYPE AirframeSubsystem::Release() {
    //#[ operation Release() 
    
    m_cRef--;
    if (m_cRef <= 0) delete this;
    return m_cRef;
    //#]
}

void AirframeSubsystem::Save(const BSTR  filename) {
    //#[ operation Save(const BSTR) 
    
    m_pModelExec->Save(filename);
    //#]
}

void AirframeSubsystem::clean() {
    //#[ operation clean() 
    
    
    if (itsFinDynamics)
    {
      itsFinDynamics->Release();
      itsFinDynamics = NULL;
    }
    if (itsBodyDynamics)
    {
      itsBodyDynamics->Release();
      itsBodyDynamics = NULL;
    }
    if (itsAeroDynamics)
    {
      itsAeroDynamics->Release();
      itsAeroDynamics = NULL;
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

HRESULT AirframeSubsystem::handle_tick(const double  t) {
    //#[ operation handle_tick(const double) 
    
    receive();
    
    HRESULT hr = m_pModelExec->Step(t);
    printData(t);
    
    broadcast(t);
    
    return hr;
    //#]
}

void AirframeSubsystem::init() {
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
    m_pSystemModel = new AirFrame();
    m_pModel->SetEso(m_pSystemModel);
    hr = m_pModelExec->SetModel(m_pModel);
    _ASSERTE(hr == S_OK);
    
    // manual addition
    m_pModelExec->put_MaxStepSize(1.0e-3);
    // end manual addition
    
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
    m_pModel->get_Eso(L"itsFinDynamics", &itsFinDynamics);
    m_pModel->get_Eso(L"itsBodyDynamics", &itsBodyDynamics);
    m_pModel->get_Eso(L"itsAeroDynamics", &itsAeroDynamics);
    // end sub model initialization
    
    //#]
}

void AirframeSubsystem::initSimulation() {
    //#[ operation initSimulation() 
    
    HRESULT hr = S_OK;
    SAFEARRAY* psaVarNames = NULL;
    BSTR* varNames = NULL;
    long i;
    
    psaVarVals = NULL;
    varVals = NULL;
    
    USES_CONVERSION;
    // record data to file
    fs.open("App1.txt");
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
    
    
    // initialization event (manual addition)
    
    m_pSystemModel->itsBodyDynamics->handle_Run(0.0);
    //#]
}

void AirframeSubsystem::printData(const double  t) {
    //#[ operation printData(const double) 
    
    long i;  
    
    m_pModel->GetAllVariables(t, &psaVarVals);
    fs << t << "\t";
    for (i = 0; i < nVars; i++)
      fs << varVals[i] << "\t";
    
    fs << "\n";
    
    //#]
}

void AirframeSubsystem::termSimulation() {
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

void AirframeSubsystem::setFs(ofstream  p_fs) {
    fs = p_fs;
}

void AirframeSubsystem::setM_cRef(long  p_m_cRef) {
    m_cRef = p_m_cRef;
}

void AirframeSubsystem::setM_pdw(DWORD  p_m_pdw) {
    m_pdw = p_m_pdw;
}

void AirframeSubsystem::setNVars(long  p_nVars) {
    nVars = p_nVars;
}

void AirframeSubsystem::setPsaVarVals(SAFEARRAY*  p_psaVarVals) {
    psaVarVals = p_psaVarVals;
}

void AirframeSubsystem::setVarVals(double*  p_varVals) {
    varVals = p_varVals;
}

void AirframeSubsystem::cleanUpRelations() {
    if(itsAeroDynamics != NULL)
        {
            itsAeroDynamics = NULL;
        }
    if(itsBodyDynamics != NULL)
        {
            itsBodyDynamics = NULL;
        }
    if(itsFinDynamics != NULL)
        {
            itsFinDynamics = NULL;
        }
    if(m_pModel != NULL)
        {
            m_pModel = NULL;
        }
    if(m_pModelExec != NULL)
        {
            m_pModelExec = NULL;
        }
    if(m_pSystemModel != NULL)
        {
            NOTIFY_RELATION_CLEARED("m_pSystemModel");
            m_pSystemModel = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedAirframeSubsystem::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("m_cRef", x2String(myReal->m_cRef));
    aomsAttributes->addAttribute("m_pdw", x2String(myReal->m_pdw));
    aomsAttributes->addAttribute("psaVarVals", x2String(myReal->psaVarVals));
    aomsAttributes->addAttribute("varVals", x2String(myReal->varVals));
    aomsAttributes->addAttribute("nVars", x2String(myReal->nVars));
    aomsAttributes->addAttribute("fs", x2String(myReal->fs));
}

void OMAnimatedAirframeSubsystem::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("m_pSystemModel", FALSE, TRUE);
    if(myReal->m_pSystemModel)
        aomsRelations->ADD_ITEM(myReal->m_pSystemModel);
}

IMPLEMENT_META(AirframeSubsystem, Application, FALSE, OMAnimatedAirframeSubsystem)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AirframeSubsystem.cpp
*********************************************************************/

