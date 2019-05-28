#ifndef __JUNK150_APP_H
#define __JUNK150_APP_H

#include <fstream.h>
// forward declarations
class Throttle;
class SimpleController;
struct IOnModelExec;
struct IIsDaeEsoCImpl;
class junk150;
template <class T, class A> class COnListener;
class Engine;
class Actuator;


class junk150_app
{
public:

public:
Throttle* aThrottle;
SimpleController* aController;
SAFEARRAY* psaVarVals;
double sim_time;
double* varVals;
long nVars;
ofstream fs;
IOnModelExec* m_pModelExec;
IIsDaeEsoCImpl* m_pModel;
junk150* m_pUMLModel;
double m_startTime;
double m_endTime;
double m_stepSize;
double m_t_last;
IIsDaeEsoCImpl* m_myEngine;
IIsDaeEsoCImpl* m_Car;
IIsDaeEsoCImpl* m_POCGround;
IIsDaeEsoCImpl* m_aPOC;
IIsDaeEsoCImpl* m_aFC;
IIsDaeEsoCImpl* m_FC;
IIsDaeEsoCImpl* m_GearBox;
COnListener<Engine, long>* myEngine_handle_Start;
COnListener<Engine, double>* myEngine_handle_throttle;
COnListener<Actuator, long>* aPOC_handle_shiftEvent;
COnListener<Actuator, long>* aFC_handle_shiftEvent;

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
