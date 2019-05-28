#include "BodyDynamics.h"

#define VEC aeroVec<double> 

BodyDynamics::BodyDynamics()
{
	invReady=false;
}

BodyDynamics::~BodyDynamics()
{

}


HRESULT BodyDynamics::r_velocity(valarray<double>& res) {	// [u,v,w]
   
	 
     Acc acc = p.DER(velocity);
     Force& force = p.force;
     RotVel& rate = p.rate;									// Body Coordinates
	 Acc bodyGravity;

	getGravity(g,eulerAngles,bodyGravity);
    res = acc - (-force)/mass + cross(p.velocity,rate);
     return S_OK;
}

HRESULT BodyDynamics::r_position(valarray<double>& res) {	// [x,y,z]
   
     
	 Vel positionDot;
	 Vel& velocity = p.velocity;
    
	 B2I(velocity,eulerAngles,positionDot);
     res = DER(position) - positionDot;						// Inertial Coordinates
     return S_OK;
}


HRESULT BodyDynamics::r_rate(valarray<double>& res) {		// [p,q,r]
   
     RotAcc rateDot = p.DER(rate);
     Moment& moment = p.moment;
     RotVel& rate	= p.rate;
	 
	 if(!invReady){ invInertia = inertia.Inv(); invReady=true;}

															// Body Coordinates
	 res = - rateDot+ product(invInertia, (VEC)((-moment) - cross(p.rate,product(inertia,rate))));
     return S_OK;
}

HRESULT BodyDynamics::r_euler(valarray<double>& res) {		// [phi,theta,psi]
   
	RotVel eulerRate;
	RotVel& rate = p.rate;

	BodyRate2EulerRate(rate,eulerAngles,eulerRate);

    res  = DER(eulerAngles) - eulerRate;					// Inertial Coordinates
     return S_OK;
}


HRESULT BodyDynamics::r_AoA(valarray<double>& res) {		// Incidence Angle (angle of attack)
 
    Vel& vel = p.velocity;
	res = -AoA + atan2(vel[2],vel[0]);						// arctan(w/u)
    return S_OK;
}

HRESULT BodyDynamics::r_SSA(valarray<double>& res) {		// Side Slip Angle
 
    Vel& vel = p.velocity;
	res = -SSA + atan2(vel[1],vel[0]);						// arctan(v/u)
    return S_OK;
}

HRESULT BodyDynamics::r_V(valarray<double>& res) {
    
     Vel& vel = p.velocity;

	 res = -V + sqrt(dot(vel,vel));							// Speed
	 return S_OK;
}

