#include "ScheduledMatrix.h"
#include "ScheduledController.h"
#include <fstream>

// Create and simulate scheduled LTI controllers. 
// The controllers will use Scheduled State-Space Matrices created in ScheduledMatrix Examples 

#define nALPHA 9
#define nMach 6

#define NVARS	2
#define NTABLES 4
#define NX 2
#define NU 1
#define NY 1

typedef double T;
typedef ScheduledMatrix<T,2,NTABLES> SM;


#define getrandom(min, max) \
   ((rand()%(int)(((max) + 1)-(min)))+ (min))


// Example 1: CreateStateSpaceScheduledMatrix()
// Create 4 lookup tables with 2 schedule vars 
// with entries (A(alpha,mach),B(alpha,mach),C(alpha,mach),D(alpha,mach))

void initStateSpaceTables(int nbp_alpha,double* bp_alpha, 
						  int nbp_mach,  double* bp_mach, 
 						  int nx, int nu, int ny, SM& sm){
	
	sm.setBreakpoints(0,nbp_alpha,bp_alpha); // Set Breakpoints of first var
	sm.setBreakpoints(1,nbp_mach,bp_mach);   // Set Breakpoints of second var

	sm.initTable(0,nx,nx); // size first lookup table 
	sm.initTable(1,nx,nu); // size second lookup table
	sm.initTable(2,ny,nx); // size third lookup table
	sm.initTable(3,ny,nu); // size fourth lookup table
}

void populateStateSpaceTable(int index[], 
							 Matrix& A, 
							 Matrix& B, 
							 Matrix& C, 
							 Matrix& D, SM& sm){

	sm.setTableEntry(0,index,A);// populate first lookup table
	sm.setTableEntry(1,index,B);// populate second lookup table
	sm.setTableEntry(2,index,C);// populate third lookup table 
	sm.setTableEntry(3,index,D);// populate fourth lookup table

}

void CreateStateSpaceScheduledMatrix(){

	int nx=NX,nu=NU,ny=NY; // State Space Dimensions
	int nbp_alpha=nALPHA, nbp_mach=nMach; // Number of breakpoints
	double *bp_alpha,*bp_mach; // Breakpoint data
	Matrix A(nx,nx), B(nx,nu), C(ny,nx), D(ny,nu); // to Read and Write lookup tables entries
	ScheduledMatrix<double,2,4> sm; 
	int index[2]; // address in tables
	double v[2];

	int i,k;

	// Breakpoints
	bp_alpha = (double*) new double[nbp_alpha];
	bp_mach  = (double*) new double[nbp_mach];
	for(i=0;i<nbp_alpha;i++) bp_alpha[i] = (i-nbp_alpha/2)*0.23; // populate Breakpoints of first var
	for(k=0;k<nbp_mach;k++)  bp_mach[k] = k*0.5;       // populate Breakpoints of second var

	initStateSpaceTables(nbp_alpha,bp_alpha,nbp_mach,bp_mach,nx, nu,ny,sm);

	// Populate all entries of all lookup tables with randon data
	for(i=0;i<nbp_alpha;i++)	// Alpha axis of lookup table
	for(k=0;k<nbp_mach;k++){	// Mach  axis of lookup table
		index[0] = i;
		index[1] = k;
		A = ((double) rand())/RAND_MAX;
		B = ((double) rand())/RAND_MAX;
		C = ((double) rand())/RAND_MAX;
		D = ((double) rand())/RAND_MAX;
		populateStateSpaceTable(index,A,B,C,D,sm);
	}

	for(i=0;i<nbp_alpha;i++)
	for(k=0;k<nbp_mach;k++){
		index[0] = i;
		index[1] = k;
		sm.getTableEntry(0,index,A);
		sm.getTableEntry(1,index,B);
		sm.getTableEntry(2,index,C);
		sm.getTableEntry(3,index,D);
		v[0]=bp_alpha[i]*(1+0.001);
		v[1]=bp_mach[k]*(1+0.001);
		sm.interpolate(v);
		cerr << "A=\n" << A - *(sm.M[0]);
		cerr << "B=\n" << B - *(sm.M[1]);
		cerr << "C=\n" << C - *(sm.M[2]);
		cerr << "D=\n" << D - *(sm.M[3]);
	}
}




// Example 2
// Linear Parameter-Varying LPV Dynamic Systems Example
// http://www.tup.utwente.nl/catalogue/book/index.jsp?isbn=9036517176 page 87
// X(k+1) = (A0 + v(k)*A1)*X(k) + (B0+v(k)*B1)*u(k)
// y(k)   = C*X(k) + D*u(k)
// A0 = {0.0,0.35; -0.35,0.0}
// A1 = {0.7,0.0;  -0.30,0.3}
// B0 = {1.0;      0.5}
// B1 = {0.0;      0.5}
// C  = {1.0, -1.0}
// D  = {0.05}
// -1<v(k)<+1 (generate 10 breakpoints)

Matrix A0(NX,NX);
Matrix A1(NX,NX);
Matrix B0(NX,NU);
Matrix B1(NX,NU);
Matrix C(NY,NX);
Matrix D(NY,NU);

void getLPVMatrix(double v, Matrix& A,Matrix& B){

	A = A0 + v*A1;
	B = B0 + v*B1;
}

void initLPV(char* filename){


	ifstream fs;
	
	fs.open(filename);

	fs >> A0;
	fs >> A1;
	fs >> B0;
	fs >> B1;
	fs >> C;
	fs >> D;
	
}

typedef ScheduledMatrix<double,1,2> SM1;

void createLPVSchedule(int nbp, SM1& sm){

	double *bp;
	Matrix A(NX,NX), B(NX,NU);
	;  // one var, two matices (A,B) only
	
	double minV=-1.0,maxV=1.0;

	int i;

	// Breakpoints v=[-1,1]
	bp = (double*) new double[nbp];
	for(i=0;i<nbp;i++) bp[i] = minV + i* (maxV-minV)/nbp; 
	sm.setBreakpoints(0,nbp,bp);  // Set Breakpoints 

	sm.initTable(0,NX,NX);  // Lookup Table of A matrices
	sm.initTable(1,NX,NU);  // Lookup Table of B matrices	
	for(i=0;i<nbp;i++){
		getLPVMatrix(bp[i],A,B);
		sm.setTableEntry(0,&i,A);
		sm.setTableEntry(1,&i,B);
	}
}

void LPV_Model(){

	SM1 sm;
	int NBP=11;
	double v;

	initLPV("LPV.txt");
	createLPVSchedule(NBP,sm);
	for(int i =0;i<NBP;i++){
		v = -1 + 2.0*((double) rand())/RAND_MAX; // [-1,1]
		sm.interpolate(&v);
		cerr << "A("<<v<< ")=\n" << *(sm.M[0]);
		cerr << "B("<<v<< ")=\n" << *(sm.M[1]);
	}
}

void testScheduledController(){
	CreateStateSpaceScheduledMatrix();
	LPV_Model();
}
