// BodyDynamics.h: interface for the BodyDynamics class.
//
//////////////////////////////////////////////////////////////////////
#ifndef BODYDYNAMICS_H
#define BODYDYNAMICS_H

#include <valarray>
#include <comdef.h>
#include <limits>
#include "matrix.h"
#include "OnStlConnBase.h"

#include "aeroVec.h"
#include "aeroUnits.h"
using namespace std;
using namespace math;

typedef matrix<double> Matrix;


#define DER(x) x		// To be replaced with actual derivative macro


typedef aeroForce<double> Force;
typedef aeroTorque<double> Moment;
typedef aeroPos<double> Pos;
typedef aeroVel<double> Vel;
typedef aeroRotVel<double> RotVel;
typedef aeroAcc<double> Acc;
typedef aeroRotAcc<double> RotAcc;

struct Port : public OnStlConnBase<Port>
{
  void enumVars(OnStlVecBase<double>**& vec, long& size)
  {
    size = 4;
    vec = new OnStlVecBase<double>*[size];
    vec[0] = &force;
    vec[1] = &moment;
    vec[2] = &velocity;
    vec[3] = &rate;
  }

  HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) 
  {
    ADD_LOCAL_STLVAR(force)
    ADD_LOCAL_STLVAR(moment)
    ADD_LOCAL_STLVAR(velocity)
    ADD_LOCAL_STLVAR(rate)
  
    for (long i = 0; i < m_nEsos; i++) 
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
    return S_OK;
  }
  
	Force force;
	Moment moment;
	Vel velocity;
	RotVel rate;

};

class BodyDynamics  
{
public:
	BodyDynamics();
	virtual ~BodyDynamics();

	void init();

	HRESULT BodyDynamics::r_velocity(valarray<double>& res); // Body Coordinates
	HRESULT BodyDynamics::r_position(valarray<double>& res); // Local Coordinates
	HRESULT BodyDynamics::r_rate(valarray<double>& res);		// Body Coordinates
	HRESULT BodyDynamics::r_euler(valarray<double>& res);		// Local Coordinates

	HRESULT BodyDynamics::r_AoA(valarray<double>& res);	// Algebraic relation
	HRESULT BodyDynamics::r_SSA(valarray<double>& res);	// Algebraic relation
	HRESULT BodyDynamics::r_V(valarray<double>& res);		// Algebraic relation

public:
	Port p;
	Port n;
	double mass;
	double g;
	aeroInertia<double> inertia;

	aeroPos<double> position;
	aeroAngle<double> eulerAngles;	// Angle relatiev to local inertial coordinate system
	double AoA;		// Angle of Attack (incidence angle)
	double SSA;		// Side Slip Angle
	double V;		// Mach# = V/AirVelocity

protected:
	Matrix invInertia;
	bool invReady;
};


#endif
