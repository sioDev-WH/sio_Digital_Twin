#include <math.h>

// This file is not part of the Airframe example but illustrate 
// possible ways to structure body dynamics variables and transformations.

// struct cVec3 Vec3;
struct Vec3{
	bool bFrame;
	double x;
	double y;
	double z;
	void operator  = (Vec3& b);
	Vec3(){bFrame = 0;}		// in body axes
};

//struct cPos Pos;
struct Pos{
	bool bFrame;
	double x;
	double y;
	double z;
	void operator  = (Vec3& b){x=b.x;y=b.y;z=b.z;bFrame=b.bFrame;}
	Pos(){bFrame = 0;}			// in body axes
};

//struct cVel Vel; 
struct Vel{
	bool bFrame;
	double u;
	double v;
	double w;
	void operator  = (Vec3& b){u=b.x;v=b.y;w=b.z;bFrame=b.bFrame;}
	Vel(){bFrame = 0;}		// in body axes
};

//struct cRotVel RotVel; 
struct RotVel{
	bool bFrame;
	double p;
	double q;
	double r;
	void operator  = (Vec3& b){p=b.x;q=b.y;r=b.z;bFrame=b.bFrame;}
	RotVel(){bFrame = 0;}		// in body axes
};


//struct cEuler Euler; 
struct Euler{
	bool bFrame;
	double phi;					// roll;
	double theta;				//pitch;
	double psi;					// yaw;
	void operator  = (Vec3& b){phi=b.x;theta=b.y;psi=b.z;bFrame=b.bFrame;}
	Euler(){bFrame = 1;}			// in inertial
};

//struct cEulerRate EulerRate; 
struct EulerRate{
	bool bFrame;
	double phi_dot;				// roll rate;
	double theta_dot;			// pitch rate;
	double psi_dot;				// yaw rate;
	void operator  = (Vec3& b){phi_dot=b.x;theta_dot=b.y;psi_dot=b.z;bFrame=b.bFrame;}
	EulerRate(){bFrame = 0;}		// in inertial
};

//struct cQ Quaternion;
struct Quaternion{
	bool bFrame;
	double q0;
	double q1;
	double q2;
	double q3;
	void operator  = (Quaternion& b);
	Quaternion(){bFrame = 0;}		// in body axes
};


void Vec3::operator  = (Vec3& b){
	x=b.x;
	y=b.y;
	z=b.z;
	bFrame=b.bFrame;
}

Vec3 cross(Vec3& a, Vec3& b){ // Cross product

	Vec3* c = new Vec3;
    
	c->x = a.y * b.z - a.z * b.y;
	c->y = a.z * b.x - a.x * b.z;
	c->z = a.x * b.y - a.y * b.x;

	return *c;
}

double dot(Vec3& a, Vec3& b){ // Dot product

	double c=0;

	c = a.x * b.x + a.y * b.y + a.z * b.z;

	return c;
}

void RotVel2EulerRate(RotVel& vel, Euler& euler, EulerRate& rate){

	rate.phi_dot	= vel.p + vel.q * tan(euler.theta) * sin(euler.phi) 
						    + vel.r * tan(euler.theta) * cos(euler.phi);

	rate.theta_dot	=		  vel.q * cos(euler.phi) - vel.r * sin(euler.phi);

	rate.psi_dot	=		  vel.q * sin(euler.phi)/tan(euler.theta)
							- vel.r * cos(euler.phi)/cos(euler.theta); // + ?? -Z??
}


void I2B(Pos& inertial, Euler& euler, Pos& body){

	double c_phi	= cos(euler.phi);
	double s_phi	= sin(euler.phi);
	double c_theta  = cos(euler.theta);
	double s_theta  = sin(euler.theta);
	double c_psi	= cos(euler.psi);
	double s_psi	= sin(euler.psi);

	body.x =   c_theta*c_psi					   * inertial.x
			 + c_theta*s_psi					   * inertial.y
			 - s_theta							   * inertial.z;
	
	body.y =   (s_phi*s_theta*c_psi - c_phi*s_psi) * inertial.x
		     + (s_phi*s_theta*s_psi - c_phi*c_psi) * inertial.y
			 + (s_phi*c_theta                    ) * inertial.z;

	body.z =   (c_phi*s_theta*c_psi + s_phi*s_psi) * inertial.x
		     + (c_phi*s_theta*s_psi - s_phi*c_psi) * inertial.y
			 + (c_phi*c_theta                    ) * inertial.z;
				
}

void B2I(Pos& body, Euler& euler, Pos& inertial){

	double c_phi	= cos(euler.phi);
	double s_phi	= sin(euler.phi);
	double c_theta  = cos(euler.theta);
	double s_theta  = sin(euler.theta);
	double c_psi	= cos(euler.psi);
	double s_psi	= sin(euler.psi);

	inertial.x =   c_theta*c_psi					    * body.x
				+ (s_phi*s_theta*c_psi - c_phi*s_psi)   * body.y
				+ (c_phi*s_theta*c_psi + s_phi*s_psi)   * body.z;
	
	inertial.y =   c_theta*s_psi                        * body.x
				+ (s_phi*s_theta*s_psi - c_phi*c_psi)   * body.y
				+ (c_phi*s_theta*s_psi - s_phi*c_psi)   * body.z;

	inertial.z = - s_theta		                        * body.x
				+ (s_phi*c_theta)                       * body.y
				+ (c_phi*c_theta)                       * body.z;		
}

void DCM2Euler(Vec3 DMC_rows[], Euler& euler){

	if(DMC_rows){
		euler.phi   = atan( DMC_rows[2].z/DMC_rows[3].z);
		euler.theta = asin(-DMC_rows[1].z );
		euler.psi	= atan( DMC_rows[1].y/DMC_rows[1].x);
	}
	else{		// Error
		euler.phi	= 0.0;
		euler.theta = 0.0;
		euler.psi	= 0.0;
	}
}

void Euler2Quaternion(Euler& euler, Quaternion& q){

	double c_phi	= cos(euler.phi/2);
	double s_phi	= sin(euler.phi/2);
	double c_theta  = cos(euler.theta/2);
	double s_theta  = sin(euler.theta/2);
	double c_psi	= cos(euler.psi/2);
	double s_psi	= sin(euler.psi/2);

	q.q0 = c_phi*c_theta*c_psi + s_phi*s_theta*s_psi;
	q.q1 = s_phi*c_theta*c_psi - c_phi*s_theta*s_psi;
	q.q2 = c_phi*s_theta*c_psi + s_phi*c_theta*s_psi;
	q.q3 = c_phi*c_theta*s_psi - s_phi*s_theta*s_psi; // c_psi???

}

double alpha(Vel& vel){ // incidence angle
	return atan(vel.w/vel.u);
}

double airSpeed(Vel& vel){
	return sqrt(vel.u*vel.u + vel.w*vel.w);
}

