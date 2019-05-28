// implementation for class Demo_ECM_app
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>
#include "Engine.h"
#include "Actuator.h"

#include "Demo_ECM_app.h"
// includes
#include "Demo_ECM.h"

Demo_ECM_app::Demo_ECM_app()
{
  init();
}

Demo_ECM_app::~Demo_ECM_app()
{
 clean();
}

void Demo_ECM_app::Fire_Tick(const double t)
{

double sim_time = t;

// non-system objects

// data consumers
}


void Demo_ECM_app::initSimulation()
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
fs.open("Demo_ECM.txt");
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


void Demo_ECM_app::runSimulation()
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


HRESULT Demo_ECM_app::handle_tick(const double t)
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


void Demo_ECM_app::termSimulation()
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


bool Demo_ECM_app::Load(const BSTR filename)
{

if (SUCCEEDED( m_pModelExec->Load(filename) ))
  return true;
else
  return false;
}


void Demo_ECM_app::Save(const BSTR filename)
{

m_pModelExec->Save(filename);
}


void Demo_ECM_app::init()
{

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
m_pUMLModel = new Demo_ECM();
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
m_pModel->get_Eso(L"aFC", &m_aFC);
m_pModel->get_Eso(L"FC", &m_FC);
m_pModel->get_Eso(L"aEngine", &m_aEngine);
m_pModel->get_Eso(L"aMass", &m_aMass);
// end sub model initialization

// broadcaster / handler communication initialization
// end broadcaster / handler communication initialization

// data consumer communication initialization
// end data consumer communication initialization
long startVal = 1;
long engageVal = 1;
m_pUMLModel->aEngine->handle_Start(0.0, &startVal);
m_pUMLModel->aFC->handle_shiftEvent(1.0, &engageVal);   
}


void Demo_ECM_app::clean()
{


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
if (m_aEngine)
{
  m_aEngine->Release();
  m_aEngine = NULL;
}
if (m_aMass)
{
  m_aMass->Release();
  m_aMass = NULL;
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


