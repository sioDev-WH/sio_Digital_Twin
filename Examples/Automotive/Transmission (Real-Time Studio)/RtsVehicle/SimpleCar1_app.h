#ifndef __SIMPLECAR1_APP_H
#define __SIMPLECAR1_APP_H

#include <fstream.h>
#include "OnModelBase.h"

// forward declarations
class ShiftLever;
class Throttle;
class Controller;
struct IOnModelExec;
struct IIsDaeEsoCImpl;
class SimpleCar1;
template <class T, class A> class COnListener;
class Engine;
class simpleGearbox;
class COnDataCollector;


class SimpleCar1_app : public COnModelBase
{
public:
SimpleCar1_app();
virtual ~SimpleCar1_app();

public:
ShiftLever* GearShift;
Throttle* Accelerator;
Controller* AODController;
SAFEARRAY* psaVarVals;
double sim_time;
double* varVals;
long nVars;
ofstream fs;
IOnModelExec* m_pModelExec;
IIsDaeEsoCImpl* m_pModel;
SimpleCar1* m_pUMLModel;
double m_startTime;
double m_endTime;
double m_stepSize;
double m_t_last;
IIsDaeEsoCImpl* m_Engine_WS;
IIsDaeEsoCImpl* m_Gearbox;
IIsDaeEsoCImpl* m_Car;
COnListener<Controller, long>* AODController_handle_ShiftLeverData;
COnListener<Controller, double>* AODController_handle_ThrottleData;
COnListener<Engine, double>* Engine_WS_handle_throttle;
COnListener<simpleGearbox, long>* Gearbox_handle_shiftEvent;
COnDataCollector* AODController_handle_SpeedData;

public:
void Fire_Tick(const double t);
void initSimulation();
void runSimulation();
HRESULT handle_tick(const double t);
void termSimulation();
bool Load(const BSTR filename);
void Save(const BSTR filename);
void init();
void clean();

};

#endif
