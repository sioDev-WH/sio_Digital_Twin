#include "BodyDynamics.h"

#define PI 3.1415926535897932384626433832795
#define VEC_SIZE 3

void testResiduals(){
	int i;
	BodyDynamics vehcile;

	for(i=0;i<VEC_SIZE;i++){
		vehcile.p.force[i]		= i;
		vehcile.p.moment[i]		= i;
		vehcile.p.rate[i]		= i;
		vehcile.p.velocity[i]	= i;
		vehcile.position[i]		= i;
		vehcile.eulerAngles[i]	= PI/(i+1);
		vehcile.inertia(i,i)	= i;
	}	
	vehcile.mass=1.0;
	vehcile.AoA = 1.0;
	vehcile.V=1.0;

	valarray<double> res(0.0,5);
	
	vehcile.r_position(res);
	vehcile.r_rate(res);

	vehcile.r_euler(res);
	
	vehcile.r_AoA(res);
	vehcile.r_V(res);
}


void testBodyDynamics(){

	testResiduals();
}