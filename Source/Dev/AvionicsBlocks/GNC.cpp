#include <math.h>
#include "ONI_ublas.h"
#include "AeroLib.h" // careful with order w.r.t. boost namespace since it has similar objects, e.g., Quaternion
using namespace boost::numeric::ublas;


#define PI 3.1415926535897932384626433832795


typedef struct cVec3 Vec3;

typedef struct cVec3{
	int _trans;
	double x;
	double y;
	double z;
	void operator  = (Vec3& b);
	Vec3(){_trans = 0;}	// Column vector
	void trans(){_trans = !_trans;}
} Vec3;

void Vec3::operator  = (Vec3& b){x=b.x;y=b.y;z=b.z;_trans=b._trans;}


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


// This function combines all three interpolateMatrix blocks of Simulink Aerospace blockset
matrix<double> interpolateMatrix(double lambda[], matrix<double> A[]){	
	int n = A[0].size1();
	matrix<double> B(A[0]);
	switch(n){
	case 1:
		B = (1-lambda[0])*A[0] + lambda[0]*A[1];
		break;
	case 2://(0,0),(0,1),(1,0),(1,1)
		B = (1-lambda[1])*((1-lambda[0])*A[0] + lambda[0]*A[2]) 
			 + lambda[1] *((1-lambda[0])*A[1] + lambda[0]*A[3]);
		break;
	case 3://(0,0,0),(0,0,1),(0,1,0),(0,1,1),(1,0,0),(1,0,1),(1,1,0),(1,1,1)
		B = (1-lambda[2])*((1-lambda[1])*((1-lambda[0])*A[0] + lambda[0]*A[4]) 
							+ lambda[1] *((1-lambda[0])*A[2] + lambda[0]*A[6]))
			  +lambda[2] *((1-lambda[1])*((1-lambda[0])*A[1] + lambda[0]*A[5]) 
							+ lambda[1] *((1-lambda[0])*A[3] + lambda[0]*A[7]));
		break;
	}
	return B;
}


matrix<double> sin(matrix<double> A){ // replace with Cayley Hamilton representation of exp(A)
	matrix<double> B(A.size1(),A.size2());
	    for (int i = 0; i < A.size1 (); ++ i) 
        for (int j = 0; j < A.size2 (); ++ j) 
            B(i, j) = sin(A(i,j));
	return B;
}

matrix<double> asin(matrix<double> A){
	matrix<double> B(A.size1(),A.size2());
	    for (int i = 0; i < A.size1 (); ++ i) 
        for (int j = 0; j < A.size2 (); ++ j) 
            B(i, j) = asin(A(i,j));
	return B;
}

