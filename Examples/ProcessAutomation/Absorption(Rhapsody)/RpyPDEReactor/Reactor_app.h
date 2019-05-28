// Reactor_app.h: interface for the Reactor_app class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REACTOR_APP_H__D45034C0_98B2_457A_AC65_125E281C16AA__INCLUDED_)
#define AFX_REACTOR_APP_H__D45034C0_98B2_457A_AC65_125E281C16AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <fstream.h>
// forward declarations
struct IOnModelExec;
struct IIsDaeEsoCImpl;
class Absorber;



class Reactor_app  
{
public:
	Reactor_app();
	virtual ~Reactor_app();

public:
SAFEARRAY* psaVarVals;
double sim_time;
double* varVals;
long nVars;
ofstream fs;
IOnModelExec* m_pModelExec;
IIsDaeEsoCImpl* m_pModel;
Absorber* m_pUMLModel;
double m_startTime;
double m_endTime;
double m_stepSize;
double m_t_last;
IIsDaeEsoCImpl* m_Reactor;

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

#endif // !defined(AFX_REACTOR_APP_H__D45034C0_98B2_457A_AC65_125E281C16AA__INCLUDED_)
