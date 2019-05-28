#include "ScheduledMatrix.h"


extern int Demo1 ();
extern int Demo2 ();
extern int Demo3 ();

extern void initStateSpaceTable(int nbp_alpha,double* bp_alpha, 
						        int nb_mach,  double* bp_mach, 
						        int nx, int nu, int ny, ScheduledMatrix& sm);

extern void populateStateSpaceTable(int index[], 
									Matrix A, 
									Matrix B, 
									Matrix C, 
									Matrix D, 
									ScheduledMatrix& sm);

#define NVARS	2
#define NTABLES 4
#define nALPHA 9
#define nMach 6
#define NX 4
#define NU 1
#define NY 1

void main(){
	testStateSpace()
}

// 4 lookup tables with 2 schedule vars 
// with entries (A(alpha,mach),B(alpha,mach),C(alpha,mach),D(alpha,mach))

void testStateSpace(){

	int nx=NX,nu=NU,ny=NY; // State Space Dimensions
	int nbp_alpha=nALPHA, nbp_mach=nMach; // Number of breakpoints
	double* bp_alpha,bp_mach; // Breakpoint data
	Matrix A(nx,nx), B(nx,nu), C(ny,nx), D(ny,nu); // to Read and Write lookup tables entries
	ScheduledMatrix sm; 
	int index[2]; // address in tables

	int i,k;

	sm.init(NVARS,NTABLES);  // create 4 lookup tables, entries scheduled by 2-vars (Alpha,Mach) 

	// Breakpoints
	bp_alpha = (double*) new double[nbp_alpha];
	bp_mach  = (double*) new double[nb_mach];
	for(i=0;i<nbp_alpha;i++) bp_alpha[i] = (i-nbp_alpha/2)*0.23; // populate Breakpoints of first var
	for(k=0;k<nbp_mach;k++)  bp_mach[k] = k*0.5;       // populate Breakpoints of second var

	initStateSpaceTable(nbp_alpha,bp_alpha, nb_mach, bp_mach,  nx, nu,ny, Matrix& sm);

	// Populate all entries of all lookup tables with randon data
	for(i=0;i<nbp_alpha;i++)	// Alpha axis of lookup table
	for(k=0;k<nbp_mach;k++){	// Mach  axis of lookup table
		index[0] = i;
		index[1] = k;
		A = rand()/RAND_MAX;
		B = rand()/RAND_MAX;
		C = rand()/RAND_MAX;
		D = rand()/RAND_MAX;
		populateStateSpaceTable(index,A,B,C,D,sm);
	}
}



void initStateSpaceTable(int nbp_alpha,double* bp_alpha, 
						   int nb_mach,  double* bp_mach, 
						   int nx, int nu, int ny, Matrix& sm){

	
	int i,j;

	sm.initBreakpoints(0,nbp_alpha,bp_alpha); // Set Breakpoints of first var
	sm.initBreakpoints(0,nbp_mach,bp_mach);   // Set Breakpoints of second var

	sm.initMember(0,nx,nx); // size first lookup table 
	sm.initMember(1,nx,nu); // size second lookup table
	sm.initMember(2,ny,nx); // size third lookup table
	sm.initMember(3,ny,nu); // size fourth lookup table



}

void populateStateSpaceTable(int index[], Matrix A, Matrix B, Matrix C, Matrix D, ScheduledMatrix& sm){

	int i,k;

	sm.setMemberData(0,index,A);// populate first lookup table
	sm.setMemberData(1,index,B);// populate second lookup table
	sm.setMemberData(2,index,C);// populate third lookup table 
	sm.setMemberData(3,index,D);// populate fourth lookup table

}