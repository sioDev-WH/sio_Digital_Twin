#ifndef __DEMO1_APP_H
#define __DEMO1_APP_H

#include <fstream.h>
// forward declarations
class Throttle;
class SimpleController;
struct IOnModelExec;
struct IIsDaeEsoCImpl;
class demo1;
template <class T, class A> class COnListener;
class Engine;


class demo1_app
{
public:
demo1_app();
virtual ~demo1_app();

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
demo1* m_pUMLModel;
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
