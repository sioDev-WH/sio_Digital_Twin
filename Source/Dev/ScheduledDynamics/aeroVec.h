#ifndef _AEROVEC_H
#define _AEROVEC_H

#include <valarray>
#include <limits>


#include "matrix.h"
using namespace std;
using namespace math;
typedef matrix<double> Matrix;

#include "aeroUnits.h"
#include "OnStlVecBase.h"

#define VEC_SIZE  3               // array size
#define QUATERNION_SIZE  4               // array size
#define EPSILON 1.e-16



template <class T>
class aeroVec : public OnStlVecBase<T> 
{
public:
  aeroVec() : OnStlVecBase(VEC_SIZE)
  {
  }
	aeroVec(valarray<T> src):valarray<T>(0.0,VEC_SIZE){if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];}
	void operator = (valarray<T> src){if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];}
};


template <class T>
class Quaternion{
public:
	int n;
	T q[4];
	T operator () (int i);
	T& operator [ ] (int i);
	void operator = (Quaternion src){if(n==src.n) for(int i=0;i<nVars;i++)q[i]=src.q[i];}
	Quaternion(){n=4;q[0]=1.0;q[1]=q[2]=q[3]=0.0;}
};

template <class T>
class aeroPos:public aeroVec<T> {
public:
	Units units; // (LENGTH)
	aeroPos(){Units u(uLENGTH); units=u;};
	aeroPos(aeroVec<T> src):aeroVec<T>(){for(int i=0;i<size();i++)(*this)[i]=src[i];}
	void operator = (aeroVec<T> src){if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];}
  virtual OnPhysicalType GetPhysicalType() { return OnPhysicalType_Across; }
};

template <class T>
class aeroVel:public aeroVec<T>{
public:
	Units units;//(VELOCITY);
	aeroVel(){Units u(uVELOCITY); units=u;};
	aeroVel(aeroVec<T> src):aeroVec<T>(){for(int i=0;i<size();i++)(*this)[i]=src[i];}
	void operator = (aeroVec<T> src){if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];}
  virtual OnPhysicalType GetPhysicalType() { return OnPhysicalType_Across; }
};

template <class T>
class aeroAcc:public aeroVec<T>{
public:
	Units units; // (ACCELERATION);
	aeroAcc(){Units u(uACCELERATION); units=u;};
	aeroAcc(aeroVec<T> src):aeroVec<T>(){for(int i=0;i<size();i++)(*this)[i]=src[i];}
	void operator = (aeroVec<T> src){if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];}
  virtual OnPhysicalType GetPhysicalType() { return OnPhysicalType_Across; }
};

template <class T>
class aeroForce:public aeroVec<T>{
public:
	Units units; // (FORCE);
	aeroForce(){Units u(uFORCE); units=u;};
	aeroForce(aeroVec<T> src):aeroVec<T>(){for(int i=0;i<size();i++)(*this)[i]=src[i];}
	void operator = (aeroVec<T> src){if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];}
  virtual OnPhysicalType GetPhysicalType() { return OnPhysicalType_Through; }
};

template <class T>
class aeroAngle:public aeroVec<T>{
public:
	Units units; //(ANGLE);
	aeroAngle(){Units u(uANGLE); units=u;};
	aeroAngle(aeroVec<T> src):aeroVec<T>(){for(int i=0;i<size();i++)(*this)[i]=src[i];}
	void operator = (aeroVec<T> src){if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];}
  virtual OnPhysicalType GetPhysicalType() { return OnPhysicalType_Across; }
};

template <class T>
class aeroRotVel:public aeroVec<T>{
public:
	Units units; //(ANGULAR_VELOCITY);
	aeroRotVel(){Units u(uANGULAR_VELOCITY); units=u;};
	aeroRotVel(aeroVec<T> src):aeroVec<T>(){for(int i=0;i<size();i++)(*this)[i]=src[i];}
	void operator = (aeroVec<T> src){if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];}
  virtual OnPhysicalType GetPhysicalType() { return OnPhysicalType_Across; }
};

template <class T>
class aeroRotAcc:public aeroVec<T>{
public:
	Units units; //(ANGULAR_ACCELERATION);
	aeroRotAcc(){Units u(uANGULAR_ACCELERATION); units=u;};
	aeroRotAcc(aeroVec<T> src):aeroVec<T>(){for(int i=0;i<size();i++)(*this)[i]=src[i];}
	void operator = (aeroVec<T> src){if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];}
  virtual OnPhysicalType GetPhysicalType() { return OnPhysicalType_Across; }
};

template <class T>
class aeroTorque:public aeroVec<T>{
public:
	Units units; //(TORQUE);
	aeroTorque(){Units u(uTORQUE); units=u;}
	aeroTorque(aeroVec<T> src):aeroVec<T>(){for(int i=0;i<size();i++)(*this)[i]=src[i];}
	void operator = (aeroVec<T> src){if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];}
  virtual OnPhysicalType GetPhysicalType() { return OnPhysicalType_Through; }
};

template <class T>
class aeroInertia:public matrix<T>{
public:
	Units units; //(TORQUE);
	aeroInertia():Matrix(VEC_SIZE,VEC_SIZE){Units u(uINERTIA); units=u;}
};

template<class T>
T  Quaternion<T>::operator () (int i){
	if(i>=0 &&i<4) 
		return q[i]; 
	else{
		cerr<<"Invalid index\n";
		return numeric_limits<T>::quiet_NaN();
	}
}

template<class T>
T& Quaternion<T>::operator [ ] (int i)  {
	if(i>=0 &&i<4) 
		return q[i]; 
	else {
		cerr<<"Invalid index\n"; 
		return q[0];
	}
}

template<class T>
aeroVec<T> cross(aeroVec<T>& a, aeroVec<T>& b){ // Cross product

	aeroVec<T> c;
   
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];

	return c;
}

template<class T>
T dot(aeroVec<T>& a, aeroVec<T>& b){ // Dot product

	T c=0;

	c = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

	return c;
}


template<class T>
aeroVec<T> product(matrix<T> A, aeroVec<T> x){

	aeroVec<T> y;
	if(A.ColNo() == x.size()){
		for(int i=0;i<A.RowNo();i++){
			y[i]= (T) 0.0;
			for(int j=0;j<A.ColNo();j++)
				y[i] += A(i,j)*x[i];
		}
	}
	return y;
}


template<class T>
void RotVel2EulerRate(aeroVec<T>& vel, aeroVec<T>& euler, aeroVec<T>& rate){

	rate[0]	= vel[0] + vel[1] * tan(euler[1]) * sin(euler[0]) 
				+ vel[2] * tan(euler[1]) * cos(euler[0]);

	rate[1]	= vel[1] * cos(euler[0]) - vel[2] * sin(euler[0]);

	rate[2]	= vel[1] * sin(euler[0])/tan(euler[1])
				- vel[2] * cos(euler[0])/cos(euler[1]); // + ?? -Z??
}


template<class T>
void I2B(aeroVec<T>& inertial, aeroVec<T>& euler, aeroVec<T>& body){

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
				
}

template <class T>
void getGravity(T g, aeroVec<T>& euler, aeroVec<T>& gravity){

	T s_phi	= sin(euler[0]);
	T c_phi	= cos(euler[0]);
	T s_theta  = sin(euler[1]);
	T c_theta  = cos(euler[1]);

	gravity[0] = -s_theta     *g;
	gravity[1] = s_phi*c_theta*g;
	gravity[3] = c_phi*c_theta*g;
}

template<class T>
void B2I(aeroVec<T>& body, aeroVec<T>& euler, aeroVec<T>& inertial){

	T c_phi	= cos(euler[0]);
	T s_phi	= sin(euler[0]);
	T c_theta  = cos(euler[1]);
	T s_theta  = sin(euler[1]);
	T c_psi	= cos(euler[2]);
	T s_psi	= sin(euler[2]);

	inertial[0] =   c_theta*c_psi					       * body[0]
				   + (s_phi*s_theta*c_psi - c_phi*s_psi)   * body[1]
				   + (c_phi*s_theta*c_psi + s_phi*s_psi)   * body[2];
	
	inertial[1] =   c_theta*s_psi                        * body[0]
				   + (s_phi*s_theta*s_psi - c_phi*c_psi)   * body[1]
				   + (c_phi*s_theta*s_psi - s_phi*c_psi)   * body[2];

	inertial[2] = - s_theta		                       * body[0]
				   + (s_phi*c_theta)                       * body[1]
				   + (c_phi*c_theta)                       * body[2];		
}

template<class T>
void BodyRate2EulerRate(aeroVec<T>& rate, aeroVec<T>& eulerAngles, aeroVec<T>& eulerRate){

	aeroVec<double> c_euler = cos(eulerAngles);
	aeroVec<double> s_euler = sin(eulerAngles);

	if(c_euler[1]==0) c_euler[1] = EPSILON; // or use quaternions (theta = +/- pi()/2; steep ascent or descent)

	eulerRate[0] = rate[0]+rate[1]*s_euler[0]*s_euler[1]/c_euler[1] + rate[2]*c_euler[0]*s_euler[1]/c_euler[1];
	eulerRate[1] = rate[1]*c_euler[0] - rate[2]*s_euler[0];
	eulerRate[2] = rate[1]*s_euler[0]/c_euler[1] + rate[2]*c_euler[0]*s_euler[1]/c_euler[1];
}


template<class T>
void DCM2Euler(Matrix DMC, aeroVec<T>& euler){
		euler[0]   = atan( DMC(1,2)/DMC(2,2));
		euler[1]   = asin(-DMC(0,2) );
		euler[2]	 = atan( DMC(1,0)/DMC(0,0));
}

template<class T>
void Euler2DCM(aeroVec<T>& euler, Matrix& DMC){

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
}


template<class T>
void Euler2Quaternion(aeroVec<T>& euler, Quaternion<T>& q){

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
}

template<class T>
void DMC2Quaternion(Matrix DMC, Quaternion<T>& q){

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
}

template<class T>
void Quaternion2Euler(Quaternion<T> qin ,aeroVec<T>& euler){

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
}

template<class T>
void Quaternion2DMC(Quaternion<T> qin ,Matrix& DMC){

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
}


#endif
