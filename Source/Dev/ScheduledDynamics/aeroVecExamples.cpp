#include "aeroVec.h"

#define ARRAY_SIZE 3

void testAeroVec(){

	aeroVec<double> position,velocity;
	aeroVec<double> rotVel;
    aeroVec<double> acc;
	double ve;
	Quaternion<double> q;
	position[0] = 1; position[1]=2;  position[2]=3;
	velocity[0] =.5; velocity[1]=.25;velocity[2]=0.1;
	rotVel = cross(position,velocity);
	acc = rotVel;
	ve = dot(position,velocity);
}


void testPhysicalVec(){

	int i,j;

	aeroPos<double> position;
	aeroVel<double> velocity;
	aeroRotVel<double> rotVel;
    aeroAcc<double> acc;
	double ve;

	Quaternion<double> q;

	position[0] = 1; position[1]=2;  position[2]=3;
	velocity[0] =.5; velocity[1]=.25;velocity[2]=0.1;
	rotVel = cross(position,velocity);
	acc = rotVel;
	ve = dot(position,velocity);

	aeroInertia<double> I;
	for(i=0;i<ARRAY_SIZE;i++)
		for(j=0;j<ARRAY_SIZE;j++) I(i,j)=2.3333*(i==j);

	velocity = product(I,rotVel);
}

void testVec(){
	testAeroVec();
	testPhysicalVec();
}