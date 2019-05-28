#ifndef __DEMO_ECMSD_APP_H
#define __DEMO_ECMSD_APP_H

#include <fstream.h>
// forward declarations
struct IOnModelExec;
struct IIsDaeEsoCImpl;
class Demo_ECMSD;


class Demo_ECMSD_app
{
public:
Demo_ECMSD_app();
virtual ~Demo_ECMSD_app();

public:
SAFEARRAY* psaVarVals;
double sim_time;
double* varVals;
long nVars;
ofstream fs;
IOnModelExec* m_pModelExec;
IIsDaeEsoCImpl* m_pModel;
Demo_ECMSD* m_pUMLModel;
double m_startTime;
double m_endTime;
double m_stepSize;
double m_t_last;
IIsDaeEsoCImpl* m_aMass;
IIsDaeEsoCImpl* m_aSpring;
IIsDaeEsoCImpl* m_Damper;
IIsDaeEsoCImpl* m_Car;
IIsDaeEsoCImpl* m_aFC;
IIsDaeEsoCImpl* m_FC;
IIsDaeEsoCImpl* m_aEngine;

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
