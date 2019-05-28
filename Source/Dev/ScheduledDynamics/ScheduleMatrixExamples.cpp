#include "ScheduledMatrix.h"
#include "ScheduledController.h"
#include <fstream>

#define nALPHA 9  // Number of breakpoints of AOA
#define nMach 6	  // Number of breakpoints of Mach#

typedef double T;
typedef ScheduledMatrix<T,1,1> SM1;
typedef ScheduledMatrix<T,2,1> SM2;

// generate 1-Var (e.g., angle-of-attack) Lookup Table. 
// Each entry in the table is a 4x4 matrix (e.g., a gain matrix for a 4-State LTI system)
void generate1(SM1 &sm){

	int nbp_alpha=nALPHA;	// Number of breakpoints
	int nRows,nColumns;				
	int i,j,k;

	double *bp_alpha;		// Breakpoint data
	Matrix A;				// Temp

	// Breakpoints
	bp_alpha = (double*) new double[nbp_alpha];
	for(i=0;i<nbp_alpha;i++) bp_alpha[i] = i;
	sm.setBreakpoints(0,nbp_alpha,bp_alpha);

	nRows = 4;
	nColumns=4;
	sm.initTable(0,nRows,nRows);
	A.SetSize(nRows,nColumns);

	// Populate lookup table with test data
	for(i=0;i<nbp_alpha;i++){
		for(j=0;j<nRows;j++)
			for(k=0;k<nColumns;k++)
				A(j,k) = j*nColumns+k+nRows*nColumns*i;// Fill entries with nice test pattern. Could use rand().
	    sm.setTableEntry(0,&i,A);
	}
}

// Interpolate the schedule matrix using small perturbations from its breakpoints.
// Compare interpolated values (stored in sm.M[0]) to nearest neighbour entries in the table (stored in A)
void interpolate1(SM1& sm){
	int i;
	double v,bp;
	Matrix A;

	// Calculate delta A
	for(i=0;i<sm.nBP[0];i++){
		sm.getTableEntry(0,&i,A);
		sm.getBreakpoint(0,i,bp);
		v= bp-0.001;
		sm.interpolate(&v);
		cerr << "delA(" << i <<")=\n" <<  A - *(sm.M[0]);
	}
}


// Same as creat1() but uses 2 scheduling variables (e.g., AOA and Mach#)
void generate2(SM2& sm){

	int nbp_alpha=nALPHA, nbp_mach=nMach;	// Number of breakpoints
	int nRows,nColumns;
	int index[2];
	int i,i1,i2,j,k;

	double *bp_alpha,*bp_mach;				// Breakpoint data
	Matrix A;

	// Breakpoints
	bp_alpha = (double*) new double[nbp_alpha];
	bp_mach = (double*) new double[nbp_mach];
	for(i=0;i<nbp_alpha;i++) bp_alpha[i] = i;
	for(i=0;i<nbp_mach;i++)  bp_mach[i]  = i;
	sm.setBreakpoints(0,nbp_alpha,bp_alpha);
	sm.setBreakpoints(1,nbp_mach,bp_mach);

	// Lookup Table
	nRows = 4;
	nColumns=4;
	sm.initTable(0,nRows,nColumns);
	A.SetSize(nRows,nColumns);

	// Populate lookup table with test data
	for(i1=0;i1<nbp_alpha;i1++){
		for(i2=0;i2<nbp_mach;i2++){
			index[0] = i1;
			index[1] = i2;
			for(j=0;j<nRows;j++)
				for(k=0;k<nColumns;k++)
					A(j,k) = j*nColumns+k+nRows*nColumns*(index[0]*nbp_mach+index[1]);
			sm.setTableEntry(0,index,A);
		}
	}
}

// Same as interpolate1() but uses 2 scheduling variables (e.g., AOA and Mach#)
void interpolate2(SM2& sm){

	int index[2];
	double v[2],bp;
	int i1,i2;
	Matrix A;

	// Calculate delta A
	for(i1=0;i1<sm.nBP[0];i1++){	
		for(i2=0;i2<sm.nBP[1];i2++){
			index[0] = i1;
			index[1] = i2;
			sm.getTableEntry(0,index,A);
			sm.getBreakpoint(0,i1,bp);
			v[0]=bp-0.001;
			sm.getBreakpoint(1,i2,bp);
			v[1]=bp+0.001;
			sm.interpolate(v);
			cerr << "delA(" << index[0]<<","<<index[1] <<")=\n" << A -  *(sm.M[0]);
		}
	}
}


// Handcraft external test file used in testing LoadnSave() below.
// Note: To serialize a schedule matrix to file use sm.save(filename) method. No need to handcraft files.
void generateFile(char* filename){

	
	int nbp_alpha=nALPHA, nbp_mach=nMach; // Number of breakpoints
	
	
	ScheduledMatrix<double,2,1> sm; 
	int index[2];
	double v[2];
	ofstream fs;
	int i,i1,i2,j,k;

	fs.open(filename);

	int nvars=2,nmembers=1;
	fs << sm.nScheduleVars << "\t"; 
	fs << sm.nMatrixTables << "\n"; 
	
	// Breakpoints
	double *bp_alpha,*bp_mach;
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

void LoadnSave(const char *filename_in, const char *filename_out){

	ScheduledMatrix<double,2,1> sm;
	sm.load(filename_in);
	sm.save(filename_out);
}


void testScheduledMatrix(){
	SM1 sm1;
	SM2 sm2;
	generate1(sm1);
	interpolate1(sm1);
	generate2(sm2);
	interpolate2(sm2);
	generateFile("twoVars_in.txt");
	LoadnSave("twoVars_in.txt", "twoVars_out.txt");
}
