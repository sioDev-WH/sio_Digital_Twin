#ifndef __DEMO_ECM_APP_H
#define __DEMO_ECM_APP_H

#include <fstream.h>
// forward declarations
struct IOnModelExec;
struct IIsDaeEsoCImpl;
class Demo_ECM;


class Demo_ECM_app
{
public:
Demo_ECM_app();
virtual ~Demo_ECM_app();

public:
SAFEARRAY* psaVarVals;
double sim_time;
double* varVals;
long nVars;
ofstream fs;
IOnModelExec* m_pModelExec;
IIsDaeEsoCImpl* m_pModel;
Demo_ECM* m_pUMLModel;
double m_startTime;
double m_endTime;
double m_stepSize;
double m_t_last;
IIsDaeEsoCImpl* m_aFC;
IIsDaeEsoCImpl* m_FC;
IIsDaeEsoCImpl* m_aEngine;
IIsDaeEsoCImpl* m_aMass;

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
