/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirframePkg
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AirframePkg.h
*********************************************************************/


#ifndef AirframePkg_H 

#define AirframePkg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <oxf/event.h>
#include "stdafx.h"
#include "OnStlVecBase.h"
#include <valarray>
#include <comdef.h>
#include <limits>
#include "matrix.h"

//## package AirframePkg 


//#[ ignore 
#define evSL_AirframePkg_id 10401


#define evSH_AirframePkg_id 10402


#define evNorm_AirframePkg_id 10403
//#]

//----------------------------------------------------------------------------
// AirframePkg.h                                                                  
//----------------------------------------------------------------------------
class aeroComposition;
class aeroDynamics;
class aeroFrame;
class aeroPort;
class AtmoHeightPort;
class AtmoPort;
class atmosphere;
class bodyDynamics;
class engineDynamics;
class finDynamics;
class FinPort;
class GustPort;
class gustWind;
class Units;
class evNorm;
class evSH;
class evSL;

// KAB
template <class  T> class aeroAcc;
template <class  T> class aeroAngle;
template <class  T> class aeroDensity;
template <class  T> class aeroForce;
template <class  T> class aeroInertia;
template <class  T> class aeroLength;
template <class  T> class aeroPos;
template <class  T> class aeroRotAcc;
template <class  T> class aeroRotVel;
template <class  T> class aeroSpeedOfSound;
template <class  T> class aeroTorque;
template <class  T> class aeroVel;
template <class  T> class Quaternion;
// KAB

#undef min
#undef max
#undef free

using namespace std;
using namespace math;//#[ ignore 
#define NAME_SIZE 16

#define PI 3.1415926535897932384626433832795

typedef matrix<double> Matrix;

#define DEGREE_C			"C"

#define DEGREE_K			"K"

#define DEGREE_F			"F"

#define ANGLE_DEG			"deg"

#define ANGLE_RAD			"rad"

#define ANGLE_REV			"rev"

#define DISTANCE_FT			"ft"

#define DISTANCE_METER		"m"

#define DISTANCE_KM			"km"

#define DISTANCE_IN			"in"

#define DISTANCE_MILE		"mi"

#define DISTANCE_NAUT		"naut mi"

#define ANGULAR_VEL_DEG_S	"deg/s"

#define ANGULAR_VEL_RAD_S	"rad/s"

#define ANGULAR_VEL_RPM		"rpm"

#define VEL_FT_S			"ft/s"

#define VEL_METER_S			"m/s"

#define VEL_KM_S			"km/s"

#define VEL_IN_S			"in/s"

#define VEL_KM_HR			"km/h"

#define VEL_MI_HR			"mph"

#define VEL_KNOTS			"kts"

#define ANGULAR_ACC_DEG_S2	"deg/s^2"

#define ANGULAR_ACC_RAD_S2	"rad/s^2"

#define ANGULAR_ACC_RPM_S	"rpm/sec"

#define ACC_FT_S2			"ft/s^2"

#define ACC_METER_S2		"m/s^2"

#define ACC_KM_S2			"km/s^2"

#define ACC_IN_S2			"in/s^2"

#define ACC_KM_HR_S			"km/h-s"

#define ACC_MI_HR_S			"mph/s"

#define MASS_LBM			"lbm"

#define MASS_KG "kg"

#define MASS_SLUG			"slug"

#define MASS_LBF_FT2	"lbf*ft^2"

#define MASS_KG_M2		"kg*m^2"

#define MASS_SLUG_M2	"slug*m^2"

#define FORCE_LBF			"lbf"

#define FORCE_N				"N"

#define TORQUE_LBF_FT "lbf*ft"

#define TORQUE_N_M    "N*m"

#define PRESSURE_PSI		"psi"

#define PRESSURE_PA			"Pa"

#define PRESSURE_PSF		"psf"

#define PRESSURE_ATM		"atm"

#define DENISTY_LB_FT3		"lbm/ft^3"

#define DENISTY_KG_M3		"kg/m^3"

#define DENISTY_LB_IN3		"lbm/in^3"

typedef enum  {uTEMPERATURE,
             uANGLE,
			 uLENGTH,
			 uANGULAR_VELOCITY,
			 uVELOCITY,
			 uANGULAR_ACCELERATION,
			 uACCELERATION,
			 uMASS,
			 uINERTIA,
			 uFORCE,
			 uTORQUE,
			 uPRESSURE,
			 uDENSITY,
			 uOTHERS}  UNITS_T;

#define VEC_SIZE  3               // array size

#define QUATERNION_SIZE  4               // array size

#define EPSILON 1.e-16

typedef double * * ppdouble;

typedef long * * pplong;

typedef _TCHAR * * ppchar;

typedef aeroForce<double> Force;

typedef aeroTorque<double> Moment;

typedef aeroPos<double> Pos;

typedef aeroVel<double> Vel;

typedef aeroRotVel<double> RotVel;

typedef aeroAcc<double> Acc;

typedef aeroRotAcc<double> RotAcc;

typedef aeroAngle<double> Angle;

#define VEC OnStlVec<double> 

#define Kg2slug 0.0685218

#define d2r 0.017453292519943295769236907684886

#define m2ft 3.280840
//#]


//## operation B2I(valarray<T> & ,valarray<T> & ,valarray<T> & ) 
template<class T>void B2I(valarray<T> & body, valarray<T> & euler, valarray<T> & inertial) {
    //#[ operation B2I(valarray<T> & ,valarray<T> & ,valarray<T> & ) 
    
    	T c_phi	= cos(euler[0]);
    	T s_phi	= sin(euler[0]);
    	T c_theta  = cos(euler[1]);
    	T s_theta  = sin(euler[1]);
    	T c_psi	= cos(euler[2]);
    	T s_psi	= sin(euler[2]);
    
      if (inertial.size() != 3) inertial.resize(3);
    
    	inertial[0] =   c_theta*c_psi					       * body[0]
    				   + (s_phi*s_theta*c_psi - c_phi*s_psi)   * body[1]
    				   + (c_phi*s_theta*c_psi + s_phi*s_psi)   * body[2];
    	
    	inertial[1] =   c_theta*s_psi                        * body[0]
    				   + (s_phi*s_theta*s_psi - c_phi*c_psi)   * body[1]
    				   + (c_phi*s_theta*s_psi - s_phi*c_psi)   * body[2];
    
    	inertial[2] = - s_theta		                       * body[0]
    				   + (s_phi*c_theta)                       * body[1]
    				   + (c_phi*c_theta)                       * body[2];		
    //#]
}


//## operation BodyRate2EulerRate(valarray<T> & ,valarray<T> & ,valarray<T> & ) 
template<class T>void BodyRate2EulerRate(valarray<T> & rate, valarray<T> & eulerAngles, valarray<T> & eulerRate) {
    //#[ operation BodyRate2EulerRate(valarray<T> & ,valarray<T> & ,valarray<T> & ) 
    valarray<T> c_euler = cos(eulerAngles);
    valarray<T> s_euler = sin(eulerAngles);
    
    if (eulerRate.size() != VEC_SIZE) eulerRate.resize(VEC_SIZE);
    
    if (c_euler[1] == 0.0) c_euler[1] = EPSILON; // or use quaternions (theta = +/- pi()/2; steep ascent or descent)
    
    eulerRate[0] = rate[0]+rate[1]*s_euler[0]*s_euler[1]/c_euler[1] + rate[2]*c_euler[0]*s_euler[1]/c_euler[1];
    eulerRate[1] = rate[1]*c_euler[0] - rate[2]*s_euler[0];
    eulerRate[2] = rate[1]*s_euler[0]/c_euler[1] + rate[2]*c_euler[0]*s_euler[1]/c_euler[1];
    //#]
}


//## operation DCM2Euler(Matrix,valarray<T> & ) 
template<class T>void DCM2Euler(Matrix  DMC, valarray<T> & euler) {
    //#[ operation DCM2Euler(Matrix,valarray<T> & ) 
    euler[0]   = atan( DMC(1,2)/DMC(2,2));
    euler[1]   = asin(-DMC(0,2) );
    euler[2]	 = atan( DMC(1,0)/DMC(0,0));
    //#]
}


//## operation DMC2Quaternion(Matrix,Quaternion<T> & ) 
template<class T>void DMC2Quaternion(Matrix  DMC, Quaternion<T> & q) {
    //#[ operation DMC2Quaternion(Matrix,Quaternion<T> & ) 
    
    	int max,i;
    	T trace;
    	T q1,q2,q3,q4;
    	T temp;
    
    
    
    	trace = DMC(0,0)+DMC(1,1)+DMC(2,2);
    
    	if(trace>0){
    		temp = sqrt(trace+1.0);
    		q1 = 0.5*temp;
    		q2 = 0.5*(DMC(1,2)-DMC(2,1))/temp;
    		q3 = 0.5*(DMC(2,0)-DMC(0,2))/temp;
    		q4 = 0.5*(DMC(0,1)-DMC(1,0))/temp;
    	}
    	else{
    		max = 0;
    		for(i=1;i<VEC_SIZE;i++) if(DMC(i,i)>max) max=i;
    
    		switch(max){
    
    		case 0:
    			temp = sqrt(DMC(0,0)-(DMC(1,1)+DMC(2,2))+1);
    			q2 = 0.5*temp;
    			if(temp != 0.0) temp = 0.5/temp;
    			q3 = (DMC(1,0)+DMC(0,1))*temp;
    			q4 = (DMC(2,0)+DMC(0,2))*temp;
    			q1 = (DMC(1,2)-DMC(2,1))*temp;
    			break;
    		case 1:
    			temp = sqrt(DMC(1,1)-(DMC(2,2)+DMC(0,0))+1);
    			q3 = 0.5*temp;
    			if(temp != 0.0) temp = 0.5/temp;
    			q2 = (DMC(1,0)+DMC(0,1))*temp;
    			q4 = (DMC(1,2)+DMC(2,1))*temp;
    			q1 = (DMC(2,0)-DMC(0,2))*temp;
    			break;
    		case 2:
    			temp = sqrt(DMC(2,2)-(DMC(1,1)+DMC(0,0))+1);
    			q4 = 0.5*temp;
    			if(temp != 0.0) temp = 0.5/temp;
    			q2 = (DMC(2,0)+DMC(0,2))*temp;
    			q3 = (DMC(1,2)+DMC(2,1))*temp;
    			q1 = (DMC(0,1)-DMC(1,0))*temp;
    			break;
    		};
    	}
    	q[0] = q1;
    	q[1] = q2;
    	q[2] = q3;
    	q[3] = q4; 
    //#]
}


//## operation Euler2DCM(OnStlVec<T> & ,Matrix & ) 
template<class T>void Euler2DCM(OnStlVec<T> & euler, Matrix & DMC) {
    //#[ operation Euler2DCM(OnStlVec<T> & ,Matrix & ) 
    
    	T c_phi	= cos(euler[0]);
    	T s_phi	= sin(euler[0]);
    	T c_theta  = cos(euler[1]);
    	T s_theta  = sin(euler[1]);
    	T c_psi	= cos(euler[2]);
    	T s_psi	= sin(euler[2]);
    
    	DMC(0,0) = c_theta*c_psi;
    	DMC(1,0) = s_phi*s_theta*c_psi-c_phi*s_psi;
    	DMC(2,0) = c_phi*s_theta*c_psi+s_phi*s_psi;
    
    	DMC(0,1) = c_theta*s_psi;
    	DMC(1,1) = s_phi*s_theta*s_psi-c_phi*c_psi;
    	DMC(2,1) = c_phi*s_theta*s_psi-c_phi*c_psi;
    
    	DMC(0,2) = -s_theta;
    	DMC(1,2) = s_phi*c_theta;
    	DMC(2,2) = c_phi*c_theta;
    //#]
}


//## operation Euler2Quaternion(OnStlVec<T> & ,Quaternion<T> & ) 
template<class T>void Euler2Quaternion(OnStlVec<T> & euler, Quaternion<T> & q) {
    //#[ operation Euler2Quaternion(OnStlVec<T> & ,Quaternion<T> & ) 
    
    	T c_phi	= cos(euler[0]/2);
    	T s_phi	= sin(euler[0]/2);
    	T c_theta  = cos(euler[1]/2);
    	T s_theta  = sin(euler[1]/2);
    	T c_psi	= cos(euler[2]/2);
    	T s_psi	= sin(euler[2]/2);
    
    	q[0] = c_phi*c_theta*c_psi + s_phi*s_theta*s_psi;
    	q[1] = s_phi*c_theta*c_psi - c_phi*s_theta*s_psi;
    	q[2] = c_phi*s_theta*c_psi + s_phi*c_theta*s_psi;
    	q[3] = c_phi*c_theta*s_psi - s_phi*s_theta*s_psi;
    //#]
}


//## operation I2B(valarray<T> & ,valarray<T> & ,valarray<T> & ) 
template<class T>void I2B(valarray<T> & inertial, valarray<T> & euler, valarray<T> & body) {
    //#[ operation I2B(valarray<T> & ,valarray<T> & ,valarray<T> & ) 
    
    	T c_phi	= cos(euler[0]);
    	T s_phi	= sin(euler[0]);
    	T c_theta  = cos(euler[1]);
    	T s_theta  = sin(euler[1]);
    	T c_psi	= cos(euler[2]);
    	T s_psi	= sin(euler[2]);
    
    	body[0] =   c_theta*c_psi					   * inertial[0]
    			    + c_theta*s_psi					   * inertial[1]
    			    - s_theta						   * inertial[2];
    	
    	body[1] =(s_phi*s_theta*c_psi - c_phi*s_psi) * inertial[0]
    		     + (s_phi*s_theta*s_psi - c_phi*c_psi) * inertial[1]
    			 + (s_phi*c_theta                    ) * inertial[2];
    
    	body[2] =(c_phi*s_theta*c_psi + s_phi*s_psi) * inertial[0]
    		     + (c_phi*s_theta*s_psi - s_phi*c_psi) * inertial[1]
    			 + (c_phi*c_theta                    ) * inertial[2];
    				
    //#]
}


//## operation Quaternion2DMC(Quaternion<T> ,Matrix & ) 
template<class T>void Quaternion2DMC(Quaternion<T> qin, Matrix & DMC) {
    //#[ operation Quaternion2DMC(Quaternion<T> ,Matrix & ) 
    
    	T q1,q2,q3,q4;
    	Quaternion q;
    	int i;
    	T norm=0.0;
    
    	// Normalization
    	for(i=0;i<4;i++)norm += qin[i];
    	norm = sqrt(norm);
    	if(norm>0)
    		for(i=0;i<4;i++)q[i] += qin[i]/norm;
    	else
    		cerr << "Zero norm Quaternion!\n";
    
    	q1=q[0];q2=q[1];q3=q[2];q4=q[3];
    
    	DMC(0,0)=q1*q1+q2*q2-q3*q3-q4*q4;
    	DMC(0,1)=2*(q2*q3-q1*q4);
    	DMC(0,2)=2*(q1*q3+q2*q4);
    
    	DMC(1,0)=2*(q2*q3+q1*q4);
    	DMC(1,1)=q1*q1-q2*q2+q3*q3-q4*q4;
    	DMC(1,2)=2*(q3*q4-q1*q2);
    
    	DMC(2,0)=2*(q2*q4-q1*q3);
    	DMC(2,1)=2*(q3*q4+q1*q2);
    	DMC(2,2)=q1*q1-q2*q2-q3*q3+q4*q4;
    //#]
}


//## operation Quaternion2Euler(Quaternion<T> ,OnStlVec<T> & ) 
template<class T>void Quaternion2Euler(Quaternion<T> qin, OnStlVec<T> & euler) {
    //#[ operation Quaternion2Euler(Quaternion<T> ,OnStlVec<T> & ) 
    
    	T q1,q2,q3,q4;
    	Quaternion q;
    	int i;
    	T norm=0.0;
    
    	// Normalization
    	for(i=0;i<4;i++)norm += qin[i];
    	norm = sqrt(norm);
    	if(norm>0)
    		for(i=0;i<4;i++)q[i] += qin[i]/norm;
    	else
    		cerr << "Zero norm Quaternion!\n";
    
    	q1=q[0];q2=q[1];q3=q[2];q4=q[3];
    
    	euler[0] = atan2(2.0*(q3*q4+q1*q2) , q1*q1-q2*q2-q3*q3+q4*q4);
    	euler[1] = asin(-2.0*(q2*q4-q1*q3));
    	euler[2] = atan2(2.0*(q2*q3+q1*q4) , q1*q1+q2*q2-q3*q3-q4*q4);
    //#]
}


//## operation RotVel2EulerRate(valarray<T> & ,valarray<T> & ,valarray<T> & ) 
template<class T>void RotVel2EulerRate(valarray<T> & vel, valarray<T> & euler, valarray<T> & rate) {
    //#[ operation RotVel2EulerRate(valarray<T> & ,valarray<T> & ,valarray<T> & ) 
    
    	rate[0]	= vel[0] + vel[1] * tan(euler[1]) * sin(euler[0]) 
    				+ vel[2] * tan(euler[1]) * cos(euler[0]);
    
    	rate[1]	= vel[1] * cos(euler[0]) - vel[2] * sin(euler[0]);
    
    	rate[2]	= vel[1] * sin(euler[0])/tan(euler[1])
    				- vel[2] * cos(euler[0])/cos(euler[1]); // + ?? -Z??
    //#]
}


//## operation cross(valarray<T> & ,valarray<T> & ) 
template<class T>valarray<T> cross(valarray<T> & a, valarray<T> & b) {
    //#[ operation cross(valarray<T> & ,valarray<T> & ) 
    // Cross product
    
    OnStlVec<T> c(VEC_SIZE);
      
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
    
    return c;
    //#]
}


//## operation div(valarray<T> ,double) 
template<class T>valarray<T> div(valarray<T> A, double  x) {
    //#[ operation div(valarray<T> ,double) 
    valarray<T> y(VEC_SIZE);
    for(int i = 0; i < VEC_SIZE; i++) y[i] = A[i] / x;
    
    return y;
    //#]
}


//## operation dot(valarray<T> & ,valarray<T> & ) 
template<class T>T dot(valarray<T> & a, valarray<T> & b) {
    //#[ operation dot(valarray<T> & ,valarray<T> & ) 
    // Dot product
    
    T c=0;
    
    c = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    
    return c;
    //#]
}


//## operation fromMKS(double,Units & ) 
double fromMKS(double  data, Units & unit);

//## operation getGravity(T ,OnStlVec<T> & ,OnStlVec<T> & ) 
template<class T>void getGravity(T g, OnStlVec<T> & euler, OnStlVec<T> & gravity) {
    //#[ operation getGravity(T ,OnStlVec<T> & ,OnStlVec<T> & ) 
    
    	T s_phi	= sin(euler[0]);
    	T c_phi	= cos(euler[0]);
    	T s_theta  = sin(euler[1]);
    	T c_theta  = cos(euler[1]);
    
    	gravity[0] = -s_theta     *g;
    	gravity[1] = s_phi*c_theta*g;
    	gravity[3] = c_phi*c_theta*g;
    //#]
}


//## operation product(matrix<double> ,valarray<T> ) 
template<class T>valarray<T> product(matrix<double> A, valarray<T> x) {
    //#[ operation product(matrix<double> ,valarray<T> ) 
    valarray<T> y(VEC_SIZE);
    if(A.ColNo() == x.size())
    {
    	for(int i=0;i<A.RowNo();i++)
    {
    		y[i]= (T) 0.0;
    		for(int j=0;j<A.ColNo();j++)
    			y[i] += A(i,j)*x[i];
    	}
    }
    return y;
    //#]
}


//## operation toMKS(double,Units & ) 
double toMKS(double  data, Units & unit);

//## event evSL() 
class evSL : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evSL();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};

//## event evSH() 
class evSH : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evSH();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};

//## event evNorm() 
class evNorm : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evNorm();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AirframePkg.h
*********************************************************************/

