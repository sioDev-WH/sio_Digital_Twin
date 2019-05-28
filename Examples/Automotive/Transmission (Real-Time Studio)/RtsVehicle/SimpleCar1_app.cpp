// implementation for class SimpleCar1_app
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "SimpleCar1_app.h"
// includes
#include "ShiftLever.h"
#include "Throttle.h"
#include "Controller.h"
#include "SimpleCar1.h"
#include "EventBroadcast.h"
#include "Engine.h"
#include "simpleGearbox.h"
#include "OnDataCollector.h"

SimpleCar1_app::SimpleCar1_app()
{
  init();
}

SimpleCar1_app::~SimpleCar1_app()
{
 clean();
}

void SimpleCar1_app::Fire_Tick(const double t)
{

double sim_time = t;

// non-system objects
GearShift->handle_tick(&sim_time);
Accelerator->handle_tick(&sim_time);
AODController->handle_tick(&sim_time);
}


void SimpleCar1_app::initSimulation()
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
fs.open("SimpleCar1");
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


void SimpleCar1_app::runSimulation()
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


HRESULT SimpleCar1_app::handle_tick(const double t)
{

long i;
static double last_sim_time = 0.0;
sim_time = t;
m_pModel->GetAllVariables(sim_time, &psaVarVals);
fs << sim_time << "\t";
for (i = 0; i < nVars; i++)
  fs << varVals[i] << "\t";

fs << "\n";

Fire_Tick(sim_time);
HRESULT hr = m_pModelExec->Step(sim_time);

return hr;
}


void SimpleCar1_app::termSimulation()
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


bool SimpleCar1_app::Load(const BSTR filename)
{

if (SUCCEEDED( m_pModelExec->Load(filename) ))
  return true;
else
  return false;
}


void SimpleCar1_app::Save(const BSTR filename)
{

m_pModelExec->Save(filename);
}


void SimpleCar1_app::init()
{

GearShift = new ShiftLever();
GearShift->AddRef();
GearShift->SetName(L"GearShift");
Accelerator = new Throttle();
Accelerator->AddRef();
Accelerator->SetName(L"Accelerator");
AODController = new Controller();
AODController->AddRef();
AODController->SetName(L"AODController");
psaVarVals = NULL;
sim_time = 0.0;
varVals = NULL;
nVars = 0;


IIsDaeEsoCImpl* pEso = NULL;
long nVars = 0;
long i;
HRESULT hr = S_OK;

m_startTime = 0;
m_endTime = 200;
m_stepSize = 0.1;

CoInitialize(NULL);
hr = CoCreateInstance(CLSID_OnModelExec, NULL, CLSCTX_INPROC_SERVER, IID_IOnModelExec, (void**) &m_pModelExec);
_ASSERTE(hr == S_OK);
hr = CoCreateInstance(CLSID_IsDaeEsoCImpl, NULL, CLSCTX_INPROC_SERVER, IID_IIsDaeEsoCImpl, (void**) &m_pModel);
_ASSERTE(hr == S_OK);
m_pUMLModel = new SimpleCar1();
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
m_pModel->get_Eso(L"Engine_WS", &m_Engine_WS);
m_pModel->get_Eso(L"Gearbox", &m_Gearbox);
m_pModel->get_Eso(L"Car", &m_Car);
// end sub model initialization

// broadcaster / handler communication initialization
AODController_handle_ShiftLeverData = new COnListener<Controller, long>(AODController, &Controller::handle_ShiftLeverData);
AODController_handle_ShiftLeverData->AddRef();
GearShift->positionPort->Advise(AODController_handle_ShiftLeverData);
AODController_handle_ThrottleData = new COnListener<Controller, double>(AODController, &Controller::handle_ThrottleData);
AODController_handle_ThrottleData->AddRef();
Accelerator->positionPort->Advise(AODController_handle_ThrottleData);
Engine_WS_handle_throttle = new COnListener<Engine, double>(m_pUMLModel->Engine_WS, &Engine::handle_throttle);
Engine_WS_handle_throttle->AddRef();
Accelerator->positionPort->Advise(Engine_WS_handle_throttle);
Gearbox_handle_shiftEvent = new COnListener<simpleGearbox, long>(m_pUMLModel->Gearbox, &simpleGearbox::handle_shiftEvent);
Gearbox_handle_shiftEvent->AddRef();
AODController->Port_Shift->Advise(Gearbox_handle_shiftEvent);
// end broadcaster / handler communication initialization

// data consumer communication initialization
IIsDaeEsoCImpl* pCar = NULL;
m_pModel->get_Eso(L"myCar", &pCar);
ONI_DATACOLLECTOR_MAP(coll1, this, pCar, speed, AODController, Controller, AODController, handle_SpeedData)
pCar->Release();
// end data consumer communication initialization

// start the engine, and put the car in gear
long start = 1;
m_pUMLModel->Engine_WS->handle_Start(0.0, &start);  
GearShift->put_Position(1); 
}


void SimpleCar1_app::clean()
{

if (GearShift)
{
  GearShift->Release();
  GearShift = NULL;
}
if (Accelerator)
{
  Accelerator->Release();
  Accelerator = NULL;
}
if (AODController)
{
  AODController->Release();
  AODController = NULL;
}

if (AODController_handle_ShiftLeverData)
{
  AODController_handle_ShiftLeverData->clean();
  AODController_handle_ShiftLeverData->Release();
  AODController_handle_ShiftLeverData = NULL;
}
if (AODController_handle_ThrottleData)
{
  AODController_handle_ThrottleData->clean();
  AODController_handle_ThrottleData->Release();
  AODController_handle_ThrottleData = NULL;
}
if (Engine_WS_handle_throttle)
{
  Engine_WS_handle_throttle->clean();
  Engine_WS_handle_throttle->Release();
  Engine_WS_handle_throttle = NULL;
}
if (Gearbox_handle_shiftEvent)
{
  Gearbox_handle_shiftEvent->clean();
  Gearbox_handle_shiftEvent->Release();
  Gearbox_handle_shiftEvent = NULL;
}
if (AODController_handle_SpeedData)
{
  AODController_handle_SpeedData->Release();
  AODController_handle_SpeedData = NULL;
}
if (m_Engine_WS)
{
  m_Engine_WS->Release();
  m_Engine_WS = NULL;
}
if (m_Gearbox)
{
  m_Gearbox->Release();
  m_Gearbox = NULL;
}
if (m_Car)
{
  m_Car->Release();
  m_Car = NULL;
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


