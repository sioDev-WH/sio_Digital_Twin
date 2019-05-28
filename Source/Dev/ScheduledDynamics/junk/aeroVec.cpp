#include <limits>
#include "aeroVec.h"
#include "matrix.h"
using namespace std;
using namespace math;
typedef matrix<double> Matrix;
#include "aeroUnits.h"

template<class T,int nVars>
T  aeroVec<T,nVars>::operator () (int i){
	if(i>=0 &&i<3) 
		return x[i]; 
	else{
		cerr<<"Invalid index\n"; 
		return numeric_limits<T>::quiet_NaN();
	}
}

template<class T,int nVars>
T& aeroVec<T,nVars>::operator [ ] (int i)  {
	if(i>=0 && i<3) 
		return x[i]; 
	else {
		cerr<<"Invalid index\n"; 
		return x[0];
	}
}

template<class T,int nVars>
T  Quaternion<T>::operator () (int i){
	if(i>=0 &&i<4) 
		return q[i]; 
	else{
		cerr<<"Invalid index\n";
		return numeric_limits<T>::quiet_NaN();
	}
}

template<class T,int nVars>
T& Quaternion<T>::operator [ ] (int i)  {
	if(i>=0 &&i<4) 
		return q[i]; 
	else {
		cerr<<"Invalid index\n"; 
		return q[0];
	}
}

template<class T,int nVars>
aeroVec<T,nVars> cross(aeroVec<T,nVars>& a, aeroVec<T,nVars>& b){ // Cross product

	aeroVec<T,nVars> c;
   
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];

	return c;
}

template<class T,int nVars>
T dot(aeroVec<T,nVars>& a, aeroVec<T,nVars>& b){ // Dot product

	T c=0;

	c = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

	return c;
}


template<class T,int nVars>
void RotVel2EulerRate(aeroVec<T,nVars>& vel, aeroVec<T,nVars>& euler, aeroVec<T,nVars>& rate){

	rate[0]	= vel[0] + vel[1] * tan(euler[1]) * sin(euler[0]) 
				+ vel[2] * tan(euler[1]) * cos(euler[0]);

	rate[1]	= vel[1] * cos(euler[0]) - vel[2] * sin(euler[0]);

	rate[2]	= vel[1] * sin(euler[0])/tan(euler[1])
				- vel[2] * cos(euler[0])/cos(euler[1]); // + ?? -Z??
}


template<class T,int nVars>
void I2B(aeroVec<T,nVars>& inertial, aeroVec<T,nVars>& euler, aeroVec<T,nVars>& body){

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

template<class T,int nVars>
void B2I(aeroVec<T,nVars>& body, aeroVec<T,nVars>& euler, aeroVec<T,nVars>& inertial){

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


template<class T,int nVars>
void DCM2Euler(Matrix DMC, aeroVec<T,nVars>& euler){
		euler[0]   = atan( DMC(1,2)/DMC(2,2));
		euler[1]   = asin(-DMC(0,2) );
		euler[2]	 = atan( DMC(1,0)/DMC(0,0));
}

template<class T,int nVars>
void Euler2DCM(aeroVec<T,nVars>& euler, Matrix& DMC){

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


template<class T,int nVars>
void Euler2Quaternion(aeroVec<T,nVars>& euler, Quaternion<T>& q){

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

template<class T,int nVars>
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
		for(i=1;i<3;i++) if(DMC(i,i)>max) max=i;

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

template<class T,int nVars>
void Quaternion2Euler(Quaternion<T> qin ,aeroVec<T,nVars>& euler){

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

template<class T,int nVars>
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


template<class T,int nVars>
T alpha(aeroVec<T,nVars>& vel){ 
	return atan2(vel[2],vel[0]);
}

template<class T,int nVars>
T airSpeed(aeroVec<T,nVars>& vel){
	return sqrt(vel[0]*vel[0] + vel[2]*vel[2]);
}

