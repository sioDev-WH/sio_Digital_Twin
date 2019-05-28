#ifndef __ControlledReactor_APP_H
#define __ControlledReactor_APP_H

#include <fstream.h>
// forward declarations
struct IOnModelExec;
struct IIsDaeEsoCImpl;
class ControlledReactor;


class ControlledReactor_app
{
public:
ControlledReactor_app();
virtual ~ControlledReactor_app();

public:
SAFEARRAY* psaVarVals;
double sim_time;
double* varVals;
long nVars;
ofstream fs;
IOnModelExec* m_pModelExec;
IIsDaeEsoCImpl* m_pModel;
ControlledReactor* m_pUMLModel;
double m_startTime;
double m_endTime;
double m_stepSize;
double m_t_last;

public:
void Fire_Tick(const double t);
void initSimulation();
void runSimulation();
HRESULT handle_tick(const double t);
void termSimulation();
void init();
void clean();
void SetTime(double t);

};

#endif
