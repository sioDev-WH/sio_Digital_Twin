// implementation for class junk150_app
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "junk150_app.h"
// includes
#include "Throttle.h"
#include "SimpleController.h"
#include "junk150.h"
#include "EventBroadcast.h"
#include "Engine.h"
#include "Actuator.h"
void junk150_app::Fire_Tick(const double t)
{

double sim_time = t;

// non-system objects
aThrottle->handle_tick(&sim_time);
aController->handle_tick(&sim_time);

// data consumers
}


void junk150_app::initSimulation()
{

HRESULT hr = S_OK;
SAFEARRAY* psaVarNames = NULL;
BSTR* varNames = NULL;
long i;

psaVarVals = NULL;
varVals = NULL;

USES_CONVERSION;
m_pModel->GetTime(&sim_time);
// record data to file
fs.open("junk150.txt");
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
}


void junk150_app::runSimulation()
{

HRESULT hr = S_OK;

initSimulation();

while (sim_time < m_endTime && SUCCEEDED(hr))
{
  hr = handle_tick(sim_time);
  sim_time += m_stepSize;
}

termSimulation();
}


HRESULT junk150_app::handle_tick(const double t)
{

long i;
static double last_sim_time = 0.0;
sim_time = t;
m_pModel->GetAllVariables(sim_time, &psaVarVals);
fs << sim_time << "\t";
for (i = 0; i < nVars; i++)
  fs << varVals[i] << "\t";

fs << "\n";

HRESULT hr = m_pModelExec->Step(sim_time);
Fire_Tick(sim_time);

return hr;
}


void junk150_app::termSimulation()
{

// cleanup
if (psaVarVals)
{
  SafeArrayUnaccessData(psaVarVals);
  SafeArrayDestroy(psaVarVals);
  psaVarVals = NULL;
  varVals = NULL;
}
fs.close();
}


bool junk150_app::Load(const BSTR filename)
{

if (SUCCEEDED( m_pModelExec->Load(filename) ))
  return true;
else
  return false;
}


void junk150_app::Save(const BSTR filename)
{

m_pModelExec->Save(filename);
}


void junk150_app::init()
{

aThrottle = new Throttle();
aThrottle->AddRef();
aThrottle->SetName(L"aThrottle");
aController = new SimpleController();
aController->AddRef();
aController->SetName(L"aController");
psaVarVals = NULL;
sim_time = 0.0;
varVals = NULL;
nVars = 0;


IIsDaeEsoCImpl* pEso = NULL;
long nVars = 0;
long i;
HRESULT hr = S_OK;

m_startTime = 0;
m_endTime = 5;
m_stepSize = 0.1;

CoInitialize(NULL);
hr = CoCreateInstance(CLSID_OnModelExec, NULL, CLSCTX_INPROC_SERVER, IID_IOnModelExec, (void**) &m_pModelExec);
_ASSERTE(hr == S_OK);
hr = CoCreateInstance(CLSID_IsDaeEsoCImpl, NULL, CLSCTX_INPROC_SERVER, IID_IIsDaeEsoCImpl, (void**) &m_pModel);
_ASSERTE(hr == S_OK);
m_pUMLModel = new junk150();
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
double t;
m_pModel->InitTime(m_startTime, VARIANT_FALSE);
m_pModel->GetTime(&t);
m_t_last = t;
// end time initialization

// sub model initialization
m_pModel->get_Eso(L"myEngine", &m_myEngine);
m_pModel->get_Eso(L"Car", &m_Car);
m_pModel->get_Eso(L"POCGround", &m_POCGround);
m_pModel->get_Eso(L"aPOC", &m_aPOC);
m_pModel->get_Eso(L"aFC", &m_aFC);
m_pModel->get_Eso(L"FC", &m_FC);
m_pModel->get_Eso(L"GearBox", &m_GearBox);
// end sub model initialization

// broadcaster / handler communication initialization
myEngine_handle_Start = new COnListener<Engine, long>(m_pUMLModel->myEngine, &Engine::handle_Start);
myEngine_handle_Start->AddRef();
aController->EnginePort->Advise(myEngine_handle_Start);
myEngine_handle_throttle = new COnListener<Engine, double>(m_pUMLModel->myEngine, &Engine::handle_throttle);
myEngine_handle_throttle->AddRef();
aThrottle->positionPort->Advise(myEngine_handle_throttle);
aPOC_handle_shiftEvent = new COnListener<Actuator, long>(m_pUMLModel->aPOC, &Actuator::handle_shiftEvent);
aPOC_handle_shiftEvent->AddRef();
aController->ClutchPort6->Advise(aPOC_handle_shiftEvent);
aFC_handle_shiftEvent = new COnListener<Actuator, long>(m_pUMLModel->aFC, &Actuator::handle_shiftEvent);
aFC_handle_shiftEvent->AddRef();
aController->ClutchPort5->Advise(aFC_handle_shiftEvent);
// end broadcaster / handler communication initialization

// data consumer communication initialization
// end data consumer communication initialization
}


void junk150_app::clean()
{

if (aThrottle)
{
  aThrottle->Release();
  aThrottle = NULL;
}
if (aController)
{
  aController->Release();
  aController = NULL;
}

if (myEngine_handle_Start)
{
  myEngine_handle_Start->clean();
  myEngine_handle_Start->Release();
  myEngine_handle_Start = NULL;
}
if (myEngine_handle_throttle)
{
  myEngine_handle_throttle->clean();
  myEngine_handle_throttle->Release();
  myEngine_handle_throttle = NULL;
}
if (aPOC_handle_shiftEvent)
{
  aPOC_handle_shiftEvent->clean();
  aPOC_handle_shiftEvent->Release();
  aPOC_handle_shiftEvent = NULL;
}
if (aFC_handle_shiftEvent)
{
  aFC_handle_shiftEvent->clean();
  aFC_handle_shiftEvent->Release();
  aFC_handle_shiftEvent = NULL;
}
if (m_myEngine)
{
  m_myEngine->Release();
  m_myEngine = NULL;
}
if (m_Car)
{
  m_Car->Release();
  m_Car = NULL;
}
if (m_POCGround)
{
  m_POCGround->Release();
  m_POCGround = NULL;
}
if (m_aPOC)
{
  m_aPOC->Release();
  m_aPOC = NULL;
}
if (m_aFC)
{
  m_aFC->Release();
  m_aFC = NULL;
}
if (m_FC)
{
  m_FC->Release();
  m_FC = NULL;
}
if (m_GearBox)
{
  m_GearBox->Release();
  m_GearBox = NULL;
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
}


