#ifndef _AEROVEC_H
#define _AEROVEC_H

#include "matrix.h"
using namespace std;
using namespace math;
typedef matrix<double> Matrix;


struct Vec3{
	double x[3];
	double operator () (int i){if(i>=0 &&i<3) return x[i]; else cerr<<"Invalid index\n";}
	double& operator [ ] (int i)  {if(i>=0 && i<3) return x[i]; else {cerr<<"Invalid index\n"; return x[0];}}
	Vec3(){x[0]=x[1]=x[2]=0.0;}
};

struct Quaternion{
	double q[4];
	double operator () (int i){if(i>=0 &&i<4) return q[i]; else cerr<<"Invalid index\n";}
	double& operator [ ] (int i)  {if(i>=0 &&i<4) return q[i]; else {cerr<<"Invalid index\n"; return q[0];}}
	Quaternion(){q[0]=1.0;q[1]=q[2]=q[3]=0.0;}
};


Vec3 cross(Vec3& a, Vec3& b){ // Cross product

	Vec3 c;
   
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];

	return c;
}

double dot(Vec3& a, Vec3& b){ // Dot product

	double c=0;

	c = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

	return c;
}

void RotVel2EulerRate(Vec3& vel, Vec3& euler, Vec3& rate){

	rate[0]	= vel[0] + vel[1] * tan(euler[1]) * sin(euler[0]) 
				+ vel[2] * tan(euler[1]) * cos(euler[0]);

	rate[1]	= vel[1] * cos(euler[0]) - vel[2] * sin(euler[0]);

	rate[2]	= vel[1] * sin(euler[0])/tan(euler[1])
				- vel[2] * cos(euler[0])/cos(euler[1]); // + ?? -Z??
}


void I2B(Vec3& inertial, Vec3& euler, Vec3& body){

	double c_phi	= cos(euler[0]);
	double s_phi	= sin(euler[0]);
	double c_theta  = cos(euler[1]);
	double s_theta  = sin(euler[1]);
	double c_psi	= cos(euler[2]);
	double s_psi	= sin(euler[2]);

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

void B2I(Vec3& body, Vec3& euler, Vec3& inertial){

	double c_phi	= cos(euler[0]);
	double s_phi	= sin(euler[0]);
	double c_theta  = cos(euler[1]);
	double s_theta  = sin(euler[1]);
	double c_psi	= cos(euler[2]);
	double s_psi	= sin(euler[2]);

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

void DCM2Euler(Matrix DMC, Vec3& euler){
		euler[0]   = atan( DMC(1,2)/DMC(2,2));
		euler[1]   = asin(-DMC(0,2) );
		euler[2]	 = atan( DMC(1,0)/DMC(0,0));
}

void Euler2DCM(Vec3& euler, Matrix& DMC){

	double c_phi	= cos(euler[0]);
	double s_phi	= sin(euler[0]);
	double c_theta  = cos(euler[1]);
	double s_theta  = sin(euler[1]);
	double c_psi	= cos(euler[2]);
	double s_psi	= sin(euler[2]);

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


void Euler2Quaternion(Vec3& euler, Quaternion& q){

	double c_phi	= cos(euler[0]/2);
	double s_phi	= sin(euler[0]/2);
	double c_theta  = cos(euler[1]/2);
	double s_theta  = sin(euler[1]/2);
	double c_psi	= cos(euler[2]/2);
	double s_psi	= sin(euler[2]/2);

	q[0] = c_phi*c_theta*c_psi + s_phi*s_theta*s_psi;
	q[1] = s_phi*c_theta*c_psi - c_phi*s_theta*s_psi;
	q[2] = c_phi*s_theta*c_psi + s_phi*c_theta*s_psi;
	q[3] = c_phi*c_theta*s_psi - s_phi*s_theta*s_psi;
}

void DMC2Quaternion(Matrix DMC, Quaternion& q){

	int max,i;
	double trace;
	double q1,q2,q3,q4;
	double temp;



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


void Quaternion2Euler(Quaternion qin ,Vec3& euler){

	double q1,q2,q3,q4;
	Quaternion q;
	int i;
	double norm=0.0;

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

void Quaternion2DMC(Quaternion qin ,Matrix& DMC){

	double q1,q2,q3,q4;
	Quaternion q;
	int i;
	double norm=0.0;

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


double alpha(Vec3& vel){ 
	return atan2(vel[2],vel[0]);
}

double airSpeed(Vec3& vel){
	return sqrt(vel[0]*vel[0] + vel[2]*vel[2]);
}

#endif
