#ifndef __CAR_APP_H
#define __CAR_APP_H

// includes
#include <fstream.h>
#include "RtsOnTransmissionExport.h"
#include "OnModelBase.h"

// forward declarations
class Chart;

class Controller;
class ShiftLever;
class Brakes;
class Throttle;
struct IOnModelExec;
struct IIsDaeEsoCImpl;
class Car;
class Car3;
template <class T, class A> class COnListener;
class COnDataCollector;

#define _use_spring_damper 1

class RTSONTRANSMISSION_API Car_app3 : public COnModelBase
{
public:
Car_app3();
virtual ~Car_app3();

public:
// interface for external clock master ticks, and getting speed of car
HRESULT handle_tick(const double t);
double getSpeed(const double t);
double getdSpeed(const double t);
double getRPM(const double t);
void set_throttle(const double t, double* val);
void set_brake(const double t, double* val);
void printData(const double t);

public:
Controller* AODController;
ShiftLever* GearShift;
Brakes* Brake;
Throttle* Accelerator;
IOnModelExec* m_pModelExec;
IIsDaeEsoCImpl* m_pModel;
#if _use_spring_damper
Car3* m_pUMLModel;
#else
Car* m_pUMLModel;
#endif
double m_startTime;
double m_endTime;
double m_stepSize;
double m_t_last;
double sim_time;
COnListener<Controller, long>* AODController_handle_ShiftLeverData;
COnListener<Controller, double>* AODController_handle_ThrottleData;
#if _use_spring_damper
COnListener<Car3, long>* CarWithDriveTrain_handle_OBShift;
COnListener<Car3, long>* CarWithDriveTrain_handle_DCShift;
COnListener<Car3, long>* CarWithDriveTrain_handle_TCCShift;
COnListener<Car3, long>* CarWithDriveTrain_handle_IOCShift;
COnListener<Car3, long>* CarWithDriveTrain_handle_POCShift;
COnListener<Car3, long>* CarWithDriveTrain_handle_FCShift;
COnListener<Car3, long>* CarWithDriveTrain_handle_LRBShift;
COnListener<Car3, long>* CarWithDriveTrain_handle_RCShift;
COnListener<Car3, double>* CarWithDriveTrain_handle_brakeTorque;
COnListener<Car3, double>* CarWithDriveTrain_handle_throttle;
#else
COnListener<Car, long>* CarWithDriveTrain_handle_OBShift;
COnListener<Car long>* CarWithDriveTrain_handle_DCShift;
COnListener<Car, long>* CarWithDriveTrain_handle_TCCShift;
COnListener<Car, long>* CarWithDriveTrain_handle_IOCShift;
COnListener<Car, long>* CarWithDriveTrain_handle_POCShift;
COnListener<Car, long>* CarWithDriveTrain_handle_FCShift;
COnListener<Car, long>* CarWithDriveTrain_handle_LRBShift;
COnListener<Car, long>* CarWithDriveTrain_handle_RCShift;
COnListener<Car, double>* CarWithDriveTrain_handle_brakeTorque;
COnListener<Car, double>* CarWithDriveTrain_handle_throttle;
#endif
COnDataCollector* AODController_handle_SpeedData;


/*
Chart* PlotChartCar;
Chart* PlotChartEngine;
COnDataCollector<Chart>* PlotChartEngine_handle_plotData;
COnDataCollector<Chart>* PlotChartCar_handle_plotData;
*/



// initSimulation variables
private:
SAFEARRAY* psaVarVals;
double* varVals;
long nVars;
ofstream fs;

public:
	void Save(BSTR filename);
	bool Load(BSTR filename);
void Fire_Tick(const double t);
void runSimulation();
void initSimulation();
void termSimulation();

void ReverseControllerShiftTiming();
double get_LastTime();
double get_Acceleration(const double t);
double get_AccelerationDot(const double t);
void put_ThrottlePosition(const double t, double* val);
void put_BrakePosition(const double t, double* val);
void put_shiftTiming(bool bUpshift, long iIndex, double val);

void init();
void clean();

};

#endif
