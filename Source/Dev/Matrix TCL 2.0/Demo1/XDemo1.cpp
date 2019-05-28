#include "ScheduledMatrix.h"
#include "ScheduledController.h"
#include <fstream>

void testStateSpaceScheduledMatrix();
void test_1VarScheduledMatrix();
void test_2VarScheduledMatrix();
void Generate_2VarScheduledMatrixFile(char* filename);
void Load_2VarScheduledMatrixFromFile(const char *filename_in, const char *filename_out);


#define NVARS	2
#define NTABLES 4
#define nALPHA 9
#define nMach 6
#define NX 5
#define NU 1
#define NY 1

/*
void initStateSpaceTable(int nbp_alpha,double* bp_alpha, 
						   int nbp_mach,  double* bp_mach, 
						   int nx, int nu, int ny, ScheduledMatrix& sm)
*/
template <class T, int nVars, int nTables> 
// or simply typedef double T and use ScheduledMatrix<T, int nVars,int nTables> below
void initStateSpaceTables(int nbp_alpha,double* bp_alpha, int nbp_mach,  double* bp_mach, 
						 int nx, int nu, int ny, ScheduledMatrix<T, nVars,nTables>& sm){

	
	sm.setBreakpoints(0,nbp_alpha,bp_alpha); // Set Breakpoints of first var
	sm.setBreakpoints(1,nbp_mach,bp_mach);   // Set Breakpoints of second var

	sm.initTable(0,nx,nx); // size first lookup table 
	sm.initTable(1,nx,nu); // size second lookup table
	sm.initTable(2,ny,nx); // size third lookup table
	sm.initTable(3,ny,nu); // size fourth lookup table
}

template <class T, int nVars, int nTables>
void populateStateSpaceTable(int index[], Matrix& A, Matrix& B, Matrix& C, Matrix& D, ScheduledMatrix<T,nVars,nTables>& sm){

	sm.setTableData(0,index,A);// populate first lookup table
	sm.setTableData(1,index,B);// populate second lookup table
	sm.setTableData(2,index,C);// populate third lookup table 
	sm.setTableData(3,index,D);// populate fourth lookup table

}

// 4 lookup tables with 2 schedule vars 
// with entries (A(alpha,mach),B(alpha,mach),C(alpha,mach),D(alpha,mach))

void testStateSpaceScheduledMatrix(){

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
		sm.getTableData(0,index,A);
		sm.getTableData(1,index,B);
		sm.getTableData(2,index,C);
		sm.getTableData(3,index,D);
		v[0]=bp_alpha[i]*(1+0.001);
		v[1]=bp_mach[k]*(1+0.001);
		sm.updateAll(v);
		cerr << "A=\n" << A - *(sm.M[0]);
		cerr << "B=\n" << B - *(sm.M[1]);
		cerr << "C=\n" << C - *(sm.M[2]);
		cerr << "D=\n" << D - *(sm.M[3]);
	}
}

void test_1VarScheduledMatrix(){

	int nbp_alpha=nALPHA, nbp_mach=nMach; // Number of breakpoints
	double *bp_alpha; // Breakpoint data
	Matrix A(4,4);
	ScheduledMatrix<double,1,1> sm; 
	int index[1]; // address in tables
	double v[1];

	int i,j,k;

	// sm.init(1,1);  // create 4 lookup tables, entries scheduled by 2-vars (Alpha,Mach) 

	// Breakpoints
	bp_alpha = (double*) new double[nbp_alpha];
	for(i=0;i<nbp_alpha;i++) bp_alpha[i] = i; // populate Breakpoints of first var
	
	sm.setBreakpoints(0,nbp_alpha,bp_alpha);
	sm.initTable(0,4,4);

	// Populate all entries of all lookup tables with randon data
	for(i=0;i<nbp_alpha;i++){	// Alpha axis of lookup table
		index[0] = i;
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				A(j,k) = j*4+k+4*4*index[0];
	    sm.setTableData(0,index,A);
	}
	for(i=0;i<nbp_alpha;i++){
		index[0] = i;
		sm.getTableData(0,index,A);
		v[0]=bp_alpha[i]-0.2;
		sm.updateAll(v);
		cerr << "A(" << index[0] <<")=\n" <<  A - *(sm.M[0]);
	}
}

void test_2VarScheduledMatrix(){

	int nbp_alpha=nALPHA, nbp_mach=nMach; // Number of breakpoints
	double *bp_alpha,*bp_mach; // Breakpoint data
	Matrix A(4,4);
	ScheduledMatrix<double,2,1> sm; 
	int index[2]; // address in tables
	double v[2];
	int i,i1,i2,j,k;


	// sm.init(2,1);  // create 1 lookup tables, entries scheduled by 1-vars (Alpha,Mach) 

	// Breakpoints
	bp_alpha = (double*) new double[nbp_alpha];
	bp_mach = (double*) new double[nbp_mach];
	for(i=0;i<nbp_alpha;i++) bp_alpha[i] = i; // populate Breakpoints of first var
	for(i=0;i<nbp_mach;i++)  bp_mach[i]  = i;
	
	sm.setBreakpoints(0,nbp_alpha,bp_alpha);
	sm.setBreakpoints(1,nbp_mach,bp_mach);
	sm.initTable(0,4,4);

	// Populate all entries of all lookup tables with randon data
	for(i1=0;i1<nbp_alpha;i1++){	// Alpha axis of lookup table
		for(i2=0;i2<nbp_mach;i2++){
			index[0] = i1;
			index[1] = i2;
			for(j=0;j<4;j++)
				for(k=0;k<4;k++)
					A(j,k) = j*4+k+4*4*(index[0]*nbp_mach+index[1]);
			sm.setTableData(0,index,A);
		}
	}
	for(i1=0;i1<nbp_alpha;i1++){	// Alpha axis of lookup table
		for(i2=0;i2<nbp_mach;i2++){
			index[0] = i1;
			index[1] = i2;
			sm.getTableData(0,index,A);
			v[0]=bp_alpha[i1]-0.001;
			v[1]=bp_mach[i2]+0.001;
			sm.updateAll(v);
			cerr << "errA(" << index[0]<<","<<index[1] <<")=\n" << A -  *(sm.M[0]);
		}
	}
}

void Generate_2VarScheduledMatrixFile(char* filename){

	
	int nbp_alpha=nALPHA, nbp_mach=nMach; // Number of breakpoints
	
	
	ScheduledMatrix<double,2,1> sm; 
	int index[2]; // address in tables
	double v[2];
	ofstream fs;
	int i,i1,i2,j,k;

	fs.open(filename);

	int nvars=2,nmembers=1;
	fs << sm.nScheduleVars << "\t"; 
	fs << sm.nMatrixTables << "\n"; 
	
	// Breakpoints
	double *bp_alpha,*bp_mach; // Breakpoint data
	bp_alpha = (double*) new double[nbp_alpha];
	bp_mach = (double*) new double[nbp_mach];
	fs << nbp_alpha << "\n";
	for(i=0;i<nbp_alpha;i++){
		bp_alpha[i] = i;
		fs << bp_alpha[i] << "\t";
	}
	fs << "\n";
	fs << nbp_mach << "\n";
	for(i=0;i<nbp_mach;i++){
		bp_mach[i]  = i;
		fs << bp_mach[i] << "\t";
	}
	fs << "\n";
	
	// Set dimensions of table entries
	int nrows=4,ncolumns=4;
	fs << nrows <<"\t" << ncolumns << "\n";
	
	// 
	Matrix A(nrows,ncolumns);
	for(i1=0;i1<nbp_alpha;i1++){	// Alpha axis of lookup table
		for(i2=0;i2<nbp_mach;i2++){
			index[0] = i1;
			index[1] = i2;
			v[0] = bp_alpha[i1];
			v[1] = bp_mach[i2];
			fs << v[0] << "\t" << v[1];
			fs << "\n";
			for(j=0;j<nrows;j++)
				for(k=0;k<ncolumns;k++)
					A(j,k) = (j*ncolumns+k)+nrows*ncolumns*(index[0]*nbp_mach+index[1]);
			fs << A;
			fs << "\n";
		}
	}	
}

void Load_2VarScheduledMatrixFromFile(const char *filename_in, const char *filename_out){

	ScheduledMatrix<double,2,1> sm;
	sm.init(filename_in);
	sm.save(filename_out);
}

void main(){
	testStateSpaceScheduledMatrix();
	test_1VarScheduledMatrix();
	test_2VarScheduledMatrix();
	Generate_2VarScheduledMatrixFile("twoVars_in.txt");
	Load_2VarScheduledMatrixFromFile("twoVars_in.txt", "twoVars_out.txt");
}
