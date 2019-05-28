#include <math.h>
#include <iostream.h>

// This file is not part of the Airframe example but illustrate 
// possible ways to structure body dynamics variables and transformations.




// struct cVec3 Vec3;
struct Vec3{
	double x[3];
	void operator  = (Vec3& b);
	Vec3(){x[0]=x[1]=x[2]=0.0;};		// in body axes
};


//struct cQ Quaternion;
struct Quaternion{
	double x[4];
	void operator  = (Quaternion& b);
	Quaternion(){x[0]=x[1]=x[2]=x[3]=0.0;}		// in body axes
};


void Vec3::operator  = (Vec3& b){
	x[0]=b.x[0];
	x[1]=b.x[1];
	x[2]=b.x[2];	
}

Vec3 cross(Vec3& a, Vec3& b){ // Cross product

	Vec3* c = new Vec3;
   
	c->x[0] = a.x[1] * b.x[2] - a.x[2] * b.x[1];
	c->x[1] = a.x[2] * b.x[0] - a.x[0] * b.x[2];
	c->x[2] = a.x[0] * b.x[1] - a.x[1] * b.x[0];

	return *c;
}

double dot(Vec3& a, Vec3& b){ // Dot product

	double c=0;

	c = a.x[0] * b.x[0] + a.x[1] * b.x[1] + a.x[2] * b.x[2];

	return c;
}

void RotVel2EulerRate(Vec3& vel, Vec3& euler, Vec3& rate){

	rate.x[0]	= vel.x[0] + vel.x[1] * tan(euler.x[1]) * sin(euler.x[0]) 
				+ vel.x[2] * tan(euler.x[1]) * cos(euler.x[0]);

	rate.x[1]	= vel.x[1] * cos(euler.x[0]) - vel.x[2] * sin(euler.x[0]);

	rate.x[2]	= vel.x[1] * sin(euler.x[0])/tan(euler.x[1])
				- vel.x[2] * cos(euler.x[0])/cos(euler.x[1]); // + ?? -Z??
}


void I2B(Vec3& inertial, Vec3& euler, Vec3& body){

	double c_phi	= cos(euler.x[0]);
	double s_phi	= sin(euler.x[0]);
	double c_theta  = cos(euler.x[1]);
	double s_theta  = sin(euler.x[1]);
	double c_psi	= cos(euler.x[2]);
	double s_psi	= sin(euler.x[2]);

	body.x[0] =   c_theta*c_psi					   * inertial.x[0]
			    + c_theta*s_psi					   * inertial.x[1]
			    - s_theta						   * inertial.x[2];
	
	body.x[1] =(s_phi*s_theta*c_psi - c_phi*s_psi) * inertial.x[0]
		     + (s_phi*s_theta*s_psi - c_phi*c_psi) * inertial.x[1]
			 + (s_phi*c_theta                    ) * inertial.x[2];

	body.x[2] =(c_phi*s_theta*c_psi + s_phi*s_psi) * inertial.x[0]
		     + (c_phi*s_theta*s_psi - s_phi*c_psi) * inertial.x[1]
			 + (c_phi*c_theta                    ) * inertial.x[2];
				
}

void B2I(Vec3& body, Vec3& euler, Vec3& inertial){

	double c_phi	= cos(euler.x[0]);
	double s_phi	= sin(euler.x[0]);
	double c_theta  = cos(euler.x[1]);
	double s_theta  = sin(euler.x[1]);
	double c_psi	= cos(euler.x[2]);
	double s_psi	= sin(euler.x[2]);

	inertial.x[0] =   c_theta*c_psi					       * body.x[0]
				   + (s_phi*s_theta*c_psi - c_phi*s_psi)   * body.x[1]
				   + (c_phi*s_theta*c_psi + s_phi*s_psi)   * body.x[2];
	
	inertial.x[1] =   c_theta*s_psi                        * body.x[0]
				   + (s_phi*s_theta*s_psi - c_phi*c_psi)   * body.x[1]
				   + (c_phi*s_theta*s_psi - s_phi*c_psi)   * body.x[2];

	inertial.x[2] = - s_theta		                       * body.x[0]
				   + (s_phi*c_theta)                       * body.x[1]
				   + (c_phi*c_theta)                       * body.x[2];		
}

void DCM2Euler(Vec3 DMC_cols[], Vec3& euler){

	if(DMC_cols){
		euler.x[0]   = atan( DMC_cols[2].x[1]/DMC_cols[2].x[2]);
		euler.x[1]   = asin(-DMC_cols[2].x[0] );
		euler.x[2]	 = atan( DMC_cols[1].x[0]/DMC_cols[0].x[0]);
	}
	else{		// Error
		euler.x[0]	= 0.0;
		euler.x[1]  = 0.0;
		euler.x[2]	= 0.0;
	}
}

void Euler2DCM(Vec3& euler, Vec3* DMC_cols[]){

	double c_phi	= cos(euler.x[0]);
	double s_phi	= sin(euler.x[0]);
	double c_theta  = cos(euler.x[1]);
	double s_theta  = sin(euler.x[1]);
	double c_psi	= cos(euler.x[2]);
	double s_psi	= sin(euler.x[2]);

	if(!DMC_cols[0] || !DMC_cols[1] || !DMC_cols[2]){
		cerr<< "NULL pointer to a directional cosine matrix\n";
		return;
	}

	DMC_cols[0]->x[0]=c_theta*c_psi;
	DMC_cols[0]->x[1]=s_phi*s_theta*c_psi-c_phi*s_psi;
	DMC_cols[0]->x[2]=c_phi*s_theta*c_psi+s_phi*s_psi;

	DMC_cols[1]->x[0]=c_theta*s_psi;
	DMC_cols[1]->x[1]=s_phi*s_theta*s_psi-c_phi*c_psi;
	DMC_cols[1]->x[2]=c_phi*s_theta*s_psi-c_phi*c_psi;

	DMC_cols[2]->x[0]=-s_theta;
	DMC_cols[2]->x[1]=s_phi*c_theta;
	DMC_cols[2]->x[2]=c_phi*c_theta;
}


void Euler2Quaternion(Vec3& euler, Quaternion& q){

	double c_phi	= cos(euler.x[0]/2);
	double s_phi	= sin(euler.x[0]/2);
	double c_theta  = cos(euler.x[1]/2);
	double s_theta  = sin(euler.x[1]/2);
	double c_psi	= cos(euler.x[2]/2);
	double s_psi	= sin(euler.x[2]/2);

	q.x[0] = c_phi*c_theta*c_psi + s_phi*s_theta*s_psi;
	q.x[1] = s_phi*c_theta*c_psi - c_phi*s_theta*s_psi;
	q.x[2] = c_phi*s_theta*c_psi + s_phi*c_theta*s_psi;
	q.x[3] = c_phi*c_theta*s_psi - s_phi*s_theta*s_psi;
}

void DMC2Quaternion(Vec3 DMC_cols[], Quaternion& q){

	int max,i;
	double trace;
	double q1,q2,q3,q4;
	double temp;

#define DMC(row, col) DMC_cols[col-1].x[row-1]

	trace = DMC_cols[0].x[0]+DMC_cols[1].x[1]+DMC_cols[2].x[2];
	temp = DMC(1,1);
	if(trace>0){
		temp = sqrt(trace+1.0);
		q1 = 0.5*temp;
		q2 = 0.5*(DMC_cols[2].x[1]-DMC_cols[1].x[2])/temp;
		q3 = 0.5*(DMC_cols[0].x[2]-DMC_cols[2].x[0])/temp;
		q4 = 0.5*(DMC_cols[1].x[0]-DMC_cols[0].x[1])/temp;
	}
	else{
		max = 0;
		for(i=1;i<3;i++) if(DMC_cols[i].x[i]>max) max=i;

		switch(max){

		case 0:
			temp = sqrt(DMC_cols[0].x[0]-(DMC_cols[1].x[1]+DMC_cols[2].x[2])+1);
			q2 = 0.5*temp;
			if(temp != 0.0) temp = 0.5/temp;
			q3 = (DMC_cols[0].x[1]+DMC_cols[1].x[0])*temp;
			q4 = (DMC_cols[0].x[2]+DMC_cols[2].x[0])*temp;
			q1 = (DMC_cols[2].x[1]-DMC_cols[1].x[2])*temp;
			break;
		case 1:
			temp = sqrt(DMC_cols[1].x[1]-(DMC_cols[2].x[2]+DMC_cols[0].x[0])+1);
			q3 = 0.5*temp;
			if(temp != 0.0) temp = 0.5/temp;
			q2 = (DMC_cols[0].x[1]+DMC_cols[1].x[0])*temp;
			q4 = (DMC_cols[2].x[1]+DMC_cols[1].x[2])*temp;
			q1 = (DMC_cols[0].x[2]-DMC_cols[2].x[0])*temp;
			break;
		case 2:
			temp = sqrt(DMC_cols[2].x[2]-(DMC_cols[1].x[1]+DMC_cols[0].x[0])+1);
			q4 = 0.5*temp;
			if(temp != 0.0) temp = 0.5/temp;
			q2 = (DMC_cols[0].x[2]+DMC_cols[2].x[0])*temp;
			q3 = (DMC_cols[2].x[1]+DMC_cols[1].x[2])*temp;
			q1 = (DMC_cols[1].x[0]-DMC_cols[0].x[1])*temp;
			break;
		};
	}
	q.x[0] = q1;
	q.x[1] = q2;
	q.x[2] = q3;
	q.x[3] = q4; 
}


void Quaternion2Euler(Quaternion qin ,Vec3& euler){

	double q1,q2,q3,q4;
	Quaternion q;
	int i;
	double norm=0.0;

	// Normalization
	for(i=0;i<4;i++)norm += qin.x[i];
	norm = sqrt(norm);
	if(norm>0)
		for(i=0;i<4;i++)q.x[i] += qin.x[i]/norm;
	else
		cerr << "Zero norm Quaternion!\n";

	q1=q.x[0];q2=q.x[1];q3=q.x[2];q4=q.x[3];

	euler.x[0] = atan2(2.0*(q3*q4+q1*q2) , q1*q1-q2*q2-q3*q3+q4*q4);
	euler.x[1] = asin(-2.0*(q2*q4-q1*q3));
	euler.x[2] = atan2(2.0*(q2*q3+q1*q4) , q1*q1+q2*q2-q3*q3-q4*q4);
}

void Quaternion2DMC(Quaternion qin ,Vec3* DMC_cols[]){

	double q1,q2,q3,q4;
	Quaternion q;
	int i;
	double norm=0.0;

	// Normalization
	for(i=0;i<4;i++)norm += qin.x[i];
	norm = sqrt(norm);
	if(norm>0)
		for(i=0;i<4;i++)q.x[i] += qin.x[i]/norm;
	else
		cerr << "Zero norm Quaternion!\n";

	q1=q.x[0];q2=q.x[1];q3=q.x[2];q4=q.x[3];

	DMC_cols[0]->x[0]=q1*q1+q2*q2-q3*q3-q4*q4;
	DMC_cols[0]->x[1]=2*(q2*q3-q1*q4);
	DMC_cols[0]->x[2]=2*(q1*q3+q2*q4);

	DMC_cols[1]->x[0]=2*(q2*q3+q1*q4);
	DMC_cols[1]->x[1]=q1*q1-q2*q2+q3*q3-q4*q4;
	DMC_cols[1]->x[2]=2*(q3*q4-q1*q2);

	DMC_cols[2]->x[0]=2*(q2*q4-q1*q3);
	DMC_cols[2]->x[1]=2*(q3*q4+q1*q2);
	DMC_cols[2]->x[2]=q1*q1-q2*q2-q3*q3+q4*q4;
}


double alpha(Vec3& vel){ 
	return atan2(vel.x[2],vel.x[0]);
}

double airSpeed(Vec3& vel){
	return sqrt(vel.x[0]*vel.x[0] + vel.x[2]*vel.x[2]);
}

