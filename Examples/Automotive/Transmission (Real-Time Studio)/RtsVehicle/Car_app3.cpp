// implementation for class Car_app3
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "Car_app3.h"
// includes
#include "Controller.h"
#include "ShiftLever.h"
#include "Brakes.h"
#include "Throttle.h"
#if _use_spring_damper
#include "Car3.h"
#else
#include "Car.h"
#endif
#include "EventBroadcast.h"
#include "OnDataCollector.h"
#include "Vehicle.h"
#include "Engine.h"
#include "Oneway_Clutch.h"

#include "Chart.h"
#include "stdio.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

//ofstream fs;
//_CrtMemState s1, s2, s3;


Car_app3::Car_app3()
{
  //_CrtMemCheckpoint( &s1 );
  init();
}

Car_app3::~Car_app3()
{
  clean();
  //_CrtMemCheckpoint( &s2 );

#if 0
  if ( _CrtMemDifference( &s3, &s1, &s2) ) 
     _CrtMemDumpStatistics( &s3 );

  _CrtDumpMemoryLeaks(); 
#endif
}

void Car_app3::Fire_Tick(const double t)
{

double stime = t;

AODController_handle_SpeedData->broadcast();
AODController->handle_tick(&stime);
GearShift->handle_tick(&stime);
Brake->handle_tick(&stime);
Accelerator->handle_tick(&stime);

}


void Car_app3::initSimulation()
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
fs.open("Car_app3.txt");
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


void Car_app3::termSimulation()
{
// cleanup
SafeArrayUnaccessData(psaVarVals);
SafeArrayDestroy(psaVarVals);
psaVarVals = NULL;
varVals = NULL;
fs.close();
}


HRESULT Car_app3::handle_tick(const double t)
{
  sim_time = t;
  printData(t);
  HRESULT hr = m_pModelExec->Step(sim_time);
  if (FAILED(hr)) m_pModelExec->ForceReset();
  _ASSERTE(hr == S_OK);
  Fire_Tick(sim_time);

  return hr;
}

void Car_app3::printData(const double t)
{
  long i;

  m_pModel->GetAllVariables(t, &psaVarVals);
  fs << t << "\t";
  for (i = 0; i < nVars; i++)
    fs << varVals[i] << "\t";

  fs << "\n";
}

double Car_app3::getSpeed(const double t)
{
  double val;
  // NOTE: could add a couple lines to get this variable by name, but this was much easier.
  m_pModel->GetVariable(144, t, &val);
  return val / 3.6;
}

double Car_app3::getdSpeed(const double t)
{
  double val;
  // NOTE: could add a couple lines to get this variable by name, but this was much easier.
  m_pModel->GetDerivative(144, t, &val);
  return val / 3.6;
}


double Car_app3::getRPM(const double t)
{
  double val;
  // NOTE: could add a couple lines to get this variable by name, but this was much easier.
  m_pModel->GetVariable(0, t, &val);
  return val;
}


void Car_app3::set_throttle(const double t, double* val)
{
  Accelerator->setPosition(t, val);
}


void Car_app3::set_brake(const double t, double* val)
{
  Brake->setPosition(t, val);
}

void Car_app3::runSimulation()
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


void Car_app3::init()
{

AODController = new Controller();
AODController->AddRef();
AODController->SetName(L"AODController");
GearShift = new ShiftLever();
GearShift->AddRef();
GearShift->SetName(L"GearShift");
Brake = new Brakes();
Brake->AddRef();
Brake->SetName(L"Brake");
Accelerator = new Throttle();
Accelerator->AddRef();
Accelerator->SetName(L"Accelerator");

/*
PlotChartCar = new Chart();
PlotChartCar->AddRef();
PlotChartCar->SetName(L"PlotChartCar");
PlotChartEngine = new Chart();
PlotChartEngine->AddRef();
PlotChartEngine->SetName(L"PlotChartEngine");
*/

IIsDaeEsoCImpl* pEso = NULL;
long nVars = 0;
long i;
HRESULT hr = S_OK;

m_startTime = 0.0;
m_endTime = 10000;
m_stepSize = 0.01;
sim_time = m_startTime;

CoInitialize(NULL);
hr = CoCreateInstance(CLSID_OnModelExec, NULL, CLSCTX_INPROC_SERVER, IID_IOnModelExec, (void**) &m_pModelExec);
_ASSERTE(hr == S_OK);
hr = CoCreateInstance(CLSID_IsDaeEsoCImpl, NULL, CLSCTX_INPROC_SERVER, IID_IIsDaeEsoCImpl, (void**) &m_pModel);
_ASSERTE(hr == S_OK);
#if _use_spring_damper
m_pUMLModel = new Car3();
#else
m_pUMLModel = new Car();
#endif
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
AODController_handle_ShiftLeverData = new COnListener<Controller, long>(AODController, &Controller::handle_ShiftLeverData);
AODController_handle_ShiftLeverData->AddRef();
GearShift->positionPort->Advise(AODController_handle_ShiftLeverData);
AODController_handle_ThrottleData = new COnListener<Controller, double>(AODController, &Controller::handle_ThrottleData);
AODController_handle_ThrottleData->AddRef();
Accelerator->positionPort->Advise(AODController_handle_ThrottleData);

#if _use_spring_damper
CarWithDriveTrain_handle_OBShift = new COnListener<Car3, long>(m_pUMLModel, &Car3::handle_OBShift);
CarWithDriveTrain_handle_OBShift->AddRef();
AODController->Port_7->Advise(CarWithDriveTrain_handle_OBShift);
CarWithDriveTrain_handle_DCShift = new COnListener<Car3, long>(m_pUMLModel, &Car3::handle_DCShift);
CarWithDriveTrain_handle_DCShift->AddRef();
AODController->Port_6->Advise(CarWithDriveTrain_handle_DCShift);
CarWithDriveTrain_handle_TCCShift = new COnListener<Car3, long>(m_pUMLModel, &Car3::handle_TCCShift);
CarWithDriveTrain_handle_TCCShift->AddRef();
//AODController->Port_5->Advise(CarWithDriveTrain_handle_TCCShift);
CarWithDriveTrain_handle_IOCShift = new COnListener<Car3, long>(m_pUMLModel, &Car3::handle_IOCShift);
CarWithDriveTrain_handle_IOCShift->AddRef();
AODController->Port_4->Advise(CarWithDriveTrain_handle_IOCShift);
CarWithDriveTrain_handle_POCShift = new COnListener<Car3, long>(m_pUMLModel, &Car3::handle_POCShift);
CarWithDriveTrain_handle_POCShift->AddRef();
AODController->Port_3->Advise(CarWithDriveTrain_handle_POCShift);
CarWithDriveTrain_handle_FCShift = new COnListener<Car3, long>(m_pUMLModel, &Car3::handle_FCShift);
CarWithDriveTrain_handle_FCShift->AddRef();
AODController->Port_2->Advise(CarWithDriveTrain_handle_FCShift);
CarWithDriveTrain_handle_LRBShift = new COnListener<Car3, long>(m_pUMLModel, &Car3::handle_LRBShift);
CarWithDriveTrain_handle_LRBShift->AddRef();
AODController->Port_1->Advise(CarWithDriveTrain_handle_LRBShift);
CarWithDriveTrain_handle_RCShift = new COnListener<Car3, long>(m_pUMLModel, &Car3::handle_RCShift);
CarWithDriveTrain_handle_RCShift->AddRef();
AODController->Port_0->Advise(CarWithDriveTrain_handle_RCShift);
CarWithDriveTrain_handle_brakeTorque = new COnListener<Car3, double>(m_pUMLModel, &Car3::handle_brakeTorque);
CarWithDriveTrain_handle_brakeTorque->AddRef();
Brake->positionPort->Advise(CarWithDriveTrain_handle_brakeTorque);
CarWithDriveTrain_handle_throttle = new COnListener<Car3, double>(m_pUMLModel, &Car3::handle_throttle);
CarWithDriveTrain_handle_throttle->AddRef();
Accelerator->positionPort->Advise(CarWithDriveTrain_handle_throttle);
#else
CarWithDriveTrain_handle_OBShift = new COnListener<Car, long>(m_pUMLModel, &Car::handle_OBShift);
CarWithDriveTrain_handle_OBShift->AddRef();
AODController->Port_7->Advise(CarWithDriveTrain_handle_OBShift);
CarWithDriveTrain_handle_DCShift = new COnListener<Car, long>(m_pUMLModel, &Car::handle_DCShift);
CarWithDriveTrain_handle_DCShift->AddRef();
AODController->Port_6->Advise(CarWithDriveTrain_handle_DCShift);
CarWithDriveTrain_handle_TCCShift = new COnListener<Car, long>(m_pUMLModel, &Car::handle_TCCShift);
CarWithDriveTrain_handle_TCCShift->AddRef();
//AODController->Port_5->Advise(CarWithDriveTrain_handle_TCCShift);
CarWithDriveTrain_handle_IOCShift = new COnListener<Car, long>(m_pUMLModel, &Car::handle_IOCShift);
CarWithDriveTrain_handle_IOCShift->AddRef();
AODController->Port_4->Advise(CarWithDriveTrain_handle_IOCShift);
CarWithDriveTrain_handle_POCShift = new COnListener<Car, long>(m_pUMLModel, &Car::handle_POCShift);
CarWithDriveTrain_handle_POCShift->AddRef();
AODController->Port_3->Advise(CarWithDriveTrain_handle_POCShift);
CarWithDriveTrain_handle_FCShift = new COnListener<Car, long>(m_pUMLModel, &Car::handle_FCShift);
CarWithDriveTrain_handle_FCShift->AddRef();
AODController->Port_2->Advise(CarWithDriveTrain_handle_FCShift);
CarWithDriveTrain_handle_LRBShift = new COnListener<Car, long>(m_pUMLModel, &Car::handle_LRBShift);
CarWithDriveTrain_handle_LRBShift->AddRef();
AODController->Port_1->Advise(CarWithDriveTrain_handle_LRBShift);
CarWithDriveTrain_handle_RCShift = new COnListener<Car, long>(m_pUMLModel, &Car::handle_RCShift);
CarWithDriveTrain_handle_RCShift->AddRef();
AODController->Port_0->Advise(CarWithDriveTrain_handle_RCShift);
CarWithDriveTrain_handle_brakeTorque = new COnListener<Car, double>(m_pUMLModel, &Car::handle_brakeTorque);
CarWithDriveTrain_handle_brakeTorque->AddRef();
Brake->positionPort->Advise(CarWithDriveTrain_handle_brakeTorque);
CarWithDriveTrain_handle_throttle = new COnListener<Car, double>(m_pUMLModel, &Car::handle_throttle);
CarWithDriveTrain_handle_throttle->AddRef();
Accelerator->positionPort->Advise(CarWithDriveTrain_handle_throttle);
#endif

// end broadcaster / handler communication initialization

// data consumer communication initialization
IIsDaeEsoCImpl* pCar = NULL;
m_pModel->get_Eso(L"myCar", &pCar);
ONI_DATACOLLECTOR_MAP(coll1, this, pCar, speed, AODController, Controller, AODController, handle_SpeedData)
pCar->Release();
// end data consumer communication initialization


/*
// data consumer communication initialization
PlotChartEngine_handle_plotData = new COnDataCollector<Chart>();
PlotChartEngine_handle_plotData->AddRef();
PlotChartEngine_handle_plotData->SetTarget(PlotChartEngine, &Chart::handle_plotData);
_TCHAR* varList_PlotChartEngine_handle_plotData[] = 
{
  L"RPM",
};

IIsDaeEsoCImpl* myCar = NULL;
IIsDaeEsoCImpl* myEngine = NULL;
m_pModel->get_Eso(L"myCar", &myCar);
m_pModel->get_Eso(L"EngineWithSpeed", &myEngine);

PlotChartEngine_handle_plotData->AddSource(myEngine, varList_PlotChartEngine_handle_plotData, 1);
PlotChartEngine_handle_plotData->initIndices();
PlotChartCar_handle_plotData = new COnDataCollector<Chart>();
PlotChartCar_handle_plotData->AddRef();
PlotChartCar_handle_plotData->SetTarget(PlotChartCar, &Chart::handle_plotData);
_TCHAR* varList_PlotChartCar_handle_plotData[] = 
{
  L"speed",
};
PlotChartCar_handle_plotData->AddSource(myCar, varList_PlotChartCar_handle_plotData, 1);
PlotChartCar_handle_plotData->initIndices();
// end data consumer communication initialization
myCar->Release();
myEngine->Release();
*/




// custom model initialization
long start_val = 1;
double damping = 1000.0;
m_pUMLModel->handle_Start(sim_time, &start_val);

// put car in gear
//AODController->RtsmanualForwardShift();
GearShift->put_Position(1);
}


void Car_app3::clean()
{

/*
if (PlotChartCar)
{
  PlotChartCar->Release();
  PlotChartCar = NULL;
}
if (PlotChartEngine)
{
  PlotChartEngine->Release();
  PlotChartEngine = NULL;
}
if (PlotChartEngine_handle_plotData)
{
  PlotChartEngine_handle_plotData->Release();
  PlotChartEngine_handle_plotData = NULL;
}
if (PlotChartCar_handle_plotData)
{
  PlotChartCar_handle_plotData->Release();
  PlotChartCar_handle_plotData = NULL;
}
*/




if (AODController)
{
  AODController->Release();
  AODController = NULL;
}
if (GearShift)
{
  GearShift->Release();
  GearShift = NULL;
}
if (Brake)
{
  Brake->Release();
  Brake = NULL;
}
if (Accelerator)
{
  Accelerator->Release();
  Accelerator = NULL;
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
if (CarWithDriveTrain_handle_OBShift)
{
  CarWithDriveTrain_handle_OBShift->clean();
  CarWithDriveTrain_handle_OBShift->Release();
  CarWithDriveTrain_handle_OBShift = NULL;
}
if (CarWithDriveTrain_handle_DCShift)
{
  CarWithDriveTrain_handle_DCShift->clean();
  CarWithDriveTrain_handle_DCShift->Release();
  CarWithDriveTrain_handle_DCShift = NULL;
}
if (CarWithDriveTrain_handle_TCCShift)
{
  CarWithDriveTrain_handle_TCCShift->clean();
  CarWithDriveTrain_handle_TCCShift->Release();
  CarWithDriveTrain_handle_TCCShift = NULL;
}
if (CarWithDriveTrain_handle_IOCShift)
{
  CarWithDriveTrain_handle_IOCShift->clean();
  CarWithDriveTrain_handle_IOCShift->Release();
  CarWithDriveTrain_handle_IOCShift = NULL;
}
if (CarWithDriveTrain_handle_POCShift)
{
  CarWithDriveTrain_handle_POCShift->clean();
  CarWithDriveTrain_handle_POCShift->Release();
  CarWithDriveTrain_handle_POCShift = NULL;
}
if (CarWithDriveTrain_handle_FCShift)
{
  CarWithDriveTrain_handle_FCShift->clean();
  CarWithDriveTrain_handle_FCShift->Release();
  CarWithDriveTrain_handle_FCShift = NULL;
}
if (CarWithDriveTrain_handle_LRBShift)
{
  CarWithDriveTrain_handle_LRBShift->clean();
  CarWithDriveTrain_handle_LRBShift->Release();
  CarWithDriveTrain_handle_LRBShift = NULL;
}
if (CarWithDriveTrain_handle_RCShift)
{
  CarWithDriveTrain_handle_RCShift->clean();
  CarWithDriveTrain_handle_RCShift->Release();
  CarWithDriveTrain_handle_RCShift = NULL;
}
if (CarWithDriveTrain_handle_brakeTorque)
{
  CarWithDriveTrain_handle_brakeTorque->clean();
  CarWithDriveTrain_handle_brakeTorque->Release();
  CarWithDriveTrain_handle_brakeTorque = NULL;
}
if (CarWithDriveTrain_handle_throttle)
{
  CarWithDriveTrain_handle_throttle->clean();
  CarWithDriveTrain_handle_throttle->Release();
  CarWithDriveTrain_handle_throttle = NULL;
}
if (AODController_handle_SpeedData)
{
  AODController_handle_SpeedData->Release();
  AODController_handle_SpeedData = NULL;
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



bool Car_app3::Load(BSTR filename)
{
  CComBSTR bstrName = filename;
  CComBSTR bstrControlName = filename;
  bstrName.Append(L".bin");
  bstrControlName.Append(L"_c.bin");
  USES_CONVERSION;
  const char* control_filename = W2CA(bstrControlName);

  FILE* fs = fopen( control_filename, "rb");
  AODController->Load(fs);
  fclose(fs);

  if (SUCCEEDED( m_pModelExec->Load(bstrName) ))
    return true;
  else
    return false;
}

void Car_app3::Save(BSTR filename)
{
  CComBSTR bstrName = filename;
  CComBSTR bstrControlName = filename;
  bstrName.Append(L".bin");
  bstrControlName.Append(L"_c.bin");
  USES_CONVERSION;
  const char* control_filename = W2CA(bstrControlName);

  m_pModelExec->Save(bstrName);
  FILE* fs = fopen( control_filename, "wb");
  AODController->Save(fs);
  fclose(fs);
}

void Car_app3::ReverseControllerShiftTiming()
{
  AODController->bReverse = true;
}

double Car_app3::get_LastTime()
{
  double val;
  m_pModel->GetLastTime(&val);
  return val;
}

double Car_app3::get_AccelerationDot(const double t)
{
  double val;
  // NOTE: could add a couple lines to get this variable by name, but this was much easier.
  m_pModel->GetDerivative(146, t, &val);
  return val;
}

double Car_app3::get_Acceleration(const double t)
{
  double val;
  // NOTE: could add a couple lines to get this variable by name, but this was much easier.
  m_pModel->GetVariable(146, t, &val);
  return val;
}


void Car_app3::put_ThrottlePosition(const double t, double* val)
{
  Accelerator->setPosition(t, val);
}

void Car_app3::put_BrakePosition(const double t, double* val)
{
  Brake->setPosition(t, val);
}

void Car_app3::put_shiftTiming(bool bUpshift, long iIndex, double val)
{
  if (bUpshift)
    AODController->upshiftDelay[iIndex] = val;
  else
    AODController->downshiftDelay[iIndex] = val;
}