/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirFrameAutoPilotSystem
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AirFrameAutoPilotSystem.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "AirFrameAutoPilotSystem.h"
#include "AirFrame.h"
#include "AutoPilot.h"
#include "OnUMLEso.h"
#include "BodyDynamics.h"
#include "fstream.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// AirFrameAutoPilotSystem.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class AirFrameAutoPilotSystem 


ofstream fs;


AirFrameAutoPilotSystem::AirFrameAutoPilotSystem() {
    autoPilot = NULL;
    m_pModel = NULL;
    m_pModelExec = NULL;
    m_pUMLModel = NULL;
    //#[ operation AirFrameAutoPilotSystem() 
    init();
    //#]
}

AirFrameAutoPilotSystem::~AirFrameAutoPilotSystem() {
    //#[ operation ~AirFrameAutoPilotSystem() 
    clean();
    //#]
    cleanUpRelations();
}

void AirFrameAutoPilotSystem::Fire_Tick(const double t) {
    //#[ operation Fire_Tick(const double ) 
    // implement inter-device communication
    accelData = m_pUMLModel->getAccData(t);
    gyroData = m_pUMLModel->getGyroData(t);
    
    // WAH changed set point for the controller
    if(t>=5) setCommand(-90);
    else setCommand(-100);
    
    oldFinSetpoint = FinSetpoint;
    FinSetpoint = autoPilot->getFinControlSignal(command, gyroData, accelData);
    
    if (FinSetpoint != oldFinSetpoint)
      m_pUMLModel->setFinAngleSetpoint(t, &FinSetpoint);
    //#]
}

bool AirFrameAutoPilotSystem::Load(BSTR filename) {
    //#[ operation Load(BSTR ) 
    CComBSTR bstrName = filename;
    CComBSTR bstrControlName = filename;
    bstrName.Append(L".bin");
    bstrControlName.Append(L"_c.bin");
    USES_CONVERSION;
    const char* control_filename = W2CA(bstrControlName);
    
    FILE* fs = fopen( control_filename, "rb");
    fclose(fs);
    
    if (SUCCEEDED( m_pModelExec->Load(bstrName) ))
      return true;
    else
      return false;
    //#]
}

void AirFrameAutoPilotSystem::Save(BSTR filename) {
    //#[ operation Save(BSTR ) 
    CComBSTR bstrName = filename;
    CComBSTR bstrControlName = filename;
    bstrName.Append(L".bin");
    bstrControlName.Append(L"_c.bin");
    USES_CONVERSION;
    const char* control_filename = W2CA(bstrControlName);
    
    m_pModelExec->Save(bstrName);
    FILE* fs = fopen( control_filename, "wb");
    fclose(fs);
    //#]
}

void AirFrameAutoPilotSystem::clean() {
    //#[ operation clean() 
    if (autoPilot)
    {
      delete autoPilot;
      autoPilot = NULL;
    }
    
    if (m_pModelExec)
    {
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

HRESULT AirFrameAutoPilotSystem::handle_tick(const double t) {
    //#[ operation handle_tick(const double ) 
    sim_time = t;
    printData(t);
    HRESULT hr = m_pModelExec->Step(sim_time);
    if (FAILED(hr)) m_pModelExec->ForceReset();
    _ASSERTE(hr == S_OK);
    Fire_Tick(sim_time);
    
    return hr;
    //#]
}

void AirFrameAutoPilotSystem::init() {
    //#[ operation init() 
    
      autoPilot = new AutoPilot();
      command = -100; // WAH -1.0;
    
    
      IIsDaeEsoCImpl* pEso = NULL;
      long nVars = 0;
      long i;
      HRESULT hr = S_OK;
    
      m_startTime = 0.0;
      m_endTime = 10000;
      m_stepSize = 0.001; // WAH ???
      sim_time = m_startTime;
    
      CoInitialize(NULL);
      hr = CoCreateInstance(CLSID_OnModelExec, NULL, CLSCTX_INPROC_SERVER, IID_IOnModelExec, (void**) &m_pModelExec);
      _ASSERTE(hr == S_OK);
      hr = CoCreateInstance(CLSID_IsDaeEsoCImpl, NULL, CLSCTX_INPROC_SERVER, IID_IIsDaeEsoCImpl, (void**) &m_pModel);
      _ASSERTE(hr == S_OK);
      m_pUMLModel = new AirFrame();
    
      m_pModel->SetEso(m_pUMLModel);
      m_pModelExec->SetModel(m_pModel);
    
      // tolerance initialization
      m_pModel->GetNumVars(&nVars);
      SAFEARRAY* psa_atol = SafeArrayCreateVector(VT_R8, 0, nVars);
      SAFEARRAY* psa_rtol = SafeArrayCreateVector(VT_R8, 0, nVars);
      double* v_atol = NULL;
      double* v_rtol = NULL;
      SafeArrayAccessData(psa_atol, (void HUGEP* FAR*)& v_atol);
      SafeArrayAccessData(psa_rtol, (void HUGEP* FAR*)& v_rtol);
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
      m_pModel->InitTime(m_startTime, VARIANT_FALSE);
      m_pModel->GetTime(&sim_time);
      m_t_last = sim_time;
      // end time initialization
    
    
      // broadcaster / handler communication initialization
      // end broadcaster / handler communication initialization
    
      // data consumer communication initialization
      // end data consumer communication initialization
    
    //#]
}

void AirFrameAutoPilotSystem::initSimulation() {
    //#[ operation initSimulation() 
    
      HRESULT hr = S_OK;
      SAFEARRAY* psaVarNames = NULL;
      BSTR* varNames = NULL;
      long i;
    
      psaVarVals = NULL;
      varVals = NULL;
    
      USES_CONVERSION;
      m_pModel->GetTime(&sim_time);
      // record data to file
      fs.open("AirFrameAutoPilotSystem.txt");
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
    
      // state machine implementation
      double runTime = 0.0;
      m_pUMLModel->pBody->handle_Run(runTime);
    //#]
}

void AirFrameAutoPilotSystem::printData(const double t) {
    //#[ operation printData(const double ) 
    long i;
    
    m_pModel->GetAllVariables(t, &psaVarVals);
    fs << t << "\t";
    for (i = 0; i < nVars; i++)
      fs << varVals[i] << "\t";
    
    fs << "\n";
    //#]
}

void AirFrameAutoPilotSystem::runSimulation() {
    //#[ operation runSimulation() 
    HRESULT hr = S_OK;
    
    initSimulation();
    
    while (sim_time < m_endTime && SUCCEEDED(hr))
    {
      hr = handle_tick(sim_time);
      sim_time += m_stepSize;
    }
    
    termSimulation();
    //#]
}

void AirFrameAutoPilotSystem::setCommand(double  val) {
    //#[ operation setCommand(double) 
    command = val;
    //#]
}

void AirFrameAutoPilotSystem::setThrust(double  val) {
    //#[ operation setThrust(double) 
    thrust = val;
    //#]
}

void AirFrameAutoPilotSystem::termSimulation() {
    //#[ operation termSimulation() 
    // cleanup
    SafeArrayUnaccessData(psaVarVals);
    SafeArrayDestroy(psaVarVals);
    psaVarVals = NULL;
    varVals = NULL;
    fs.close();
    //#]
}

void AirFrameAutoPilotSystem::setFinSetpoint(double  p_FinSetpoint) {
    FinSetpoint = p_FinSetpoint;
}

void AirFrameAutoPilotSystem::setAccelData(double  p_accelData) {
    accelData = p_accelData;
}

void AirFrameAutoPilotSystem::setGyroData(double  p_gyroData) {
    gyroData = p_gyroData;
}

void AirFrameAutoPilotSystem::setM_endTime(double  p_m_endTime) {
    m_endTime = p_m_endTime;
}

void AirFrameAutoPilotSystem::setM_startTime(double  p_m_startTime) {
    m_startTime = p_m_startTime;
}

void AirFrameAutoPilotSystem::setM_stepSize(double  p_m_stepSize) {
    m_stepSize = p_m_stepSize;
}

void AirFrameAutoPilotSystem::setM_t_last(double  p_m_t_last) {
    m_t_last = p_m_t_last;
}

void AirFrameAutoPilotSystem::setNVars(long  p_nVars) {
    nVars = p_nVars;
}

void AirFrameAutoPilotSystem::setOldFinSetpoint(double  p_oldFinSetpoint) {
    oldFinSetpoint = p_oldFinSetpoint;
}

void AirFrameAutoPilotSystem::setPsaVarVals(SAFEARRAY * p_psaVarVals) {
    psaVarVals = p_psaVarVals;
}

void AirFrameAutoPilotSystem::setSim_time(double  p_sim_time) {
    sim_time = p_sim_time;
}

void AirFrameAutoPilotSystem::setVarVals(double * p_varVals) {
    varVals = p_varVals;
}

AutoPilot* AirFrameAutoPilotSystem::getAutoPilot() const {
    return autoPilot;
}

void AirFrameAutoPilotSystem::setAutoPilot(AutoPilot*  p_AutoPilot) {
    autoPilot = p_AutoPilot;
    if(p_AutoPilot != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("autoPilot", p_AutoPilot, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("autoPilot");
        }
}

IIsDaeEsoCImpl* AirFrameAutoPilotSystem::getM_pModel() const {
    return m_pModel;
}

void AirFrameAutoPilotSystem::setM_pModel(IIsDaeEsoCImpl*  p_IIsDaeEsoCImpl) {
    m_pModel = p_IIsDaeEsoCImpl;
}

IOnModelExec* AirFrameAutoPilotSystem::getM_pModelExec() const {
    return m_pModelExec;
}

void AirFrameAutoPilotSystem::setM_pModelExec(IOnModelExec*  p_IOnModelExec) {
    m_pModelExec = p_IOnModelExec;
}

AirFrame* AirFrameAutoPilotSystem::getM_pUMLModel() const {
    return m_pUMLModel;
}

void AirFrameAutoPilotSystem::setM_pUMLModel(AirFrame*  p_AirFrame) {
    m_pUMLModel = p_AirFrame;
    if(p_AirFrame != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("m_pUMLModel", p_AirFrame, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("m_pUMLModel");
        }
}

void AirFrameAutoPilotSystem::cleanUpRelations() {
    if(autoPilot != NULL)
        {
            NOTIFY_RELATION_CLEARED("autoPilot");
            autoPilot = NULL;
        }
    if(m_pModel != NULL)
        {
            m_pModel = NULL;
        }
    if(m_pModelExec != NULL)
        {
            m_pModelExec = NULL;
        }
    if(m_pUMLModel != NULL)
        {
            NOTIFY_RELATION_CLEARED("m_pUMLModel");
            m_pUMLModel = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedAirFrameAutoPilotSystem::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedAirFrameAutoPilotSystem::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("autoPilot", FALSE, TRUE);
    if(myReal->autoPilot)
        aomsRelations->ADD_ITEM(myReal->autoPilot);
    aomsRelations->addRelation("m_pUMLModel", FALSE, TRUE);
    if(myReal->m_pUMLModel)
        aomsRelations->ADD_ITEM(myReal->m_pUMLModel);
}

IMPLEMENT_META(AirFrameAutoPilotSystem, GuidancePkg, FALSE, OMAnimatedAirFrameAutoPilotSystem)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AirFrameAutoPilotSystem.cpp
*********************************************************************/

