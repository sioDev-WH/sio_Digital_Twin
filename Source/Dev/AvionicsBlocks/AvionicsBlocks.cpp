// AvionicsBlocks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IndexSearch.h"
// #include "AeroVec.h"


// void idxSearch(double BP_Data[],  int n, double u,  int *Index, double *lambda, int *bStatus);
// void idxReSearch(double BP_Data[],  int n, double u,  int *Index, double *lambda, int *bStatus);


void test_idxSearch(){
	int i,j, dim;
	double* BP_Data[3];
	double u[3], lambda[3];
	int cBP[3],Index[3], bStatus[3];
	
	dim = 3;

	cBP[0]=64;
	cBP[1]=32;
	cBP[2]=128;

	for(i=0;i<dim;i++){
		BP_Data[i] = new double[cBP[i]];
		for(j=0;j<cBP[i];j++)BP_Data[i][j] = j;
	}
	
	u[0] = 14.47;
	u[1] = 15.48;
	u[2] = 16.49;
	for(i=0;i<dim;i++)
		idxSearch( BP_Data[i],cBP[i],u[i],&Index[i],&lambda[i],&bStatus[i]);

	u[0] = 13.37;
	u[1] = 14.38;
	u[2] = 15.39;
	for(i=0;i<dim;i++)
		idxReSearch( BP_Data[i],cBP[i],u[i],&Index[i],&lambda[i],&bStatus[i]);
}

void test_interpolateMatrix(){
	int i,j, dim;
	SystemMatrix A[8], B;
	int nRows = 2;
	int nCols = 2;
	double Data[8][4], B_Data[4];
	double lambda;

	for(i=0;i<8;i++)
		for(j=0;j<4;j++)
			Data[i][j] = i*4+j;

	for(i=0;i<8;i++){
		A[i].Data = Data[i];
		A[i].nRows = nRows;
		A[i].nCols = nCols;
	}

	dim = 1;
	lambda = 0.5;
	B.Data = B_Data;
	B.nRows = nRows;
	B.nCols = nCols;
	interpolateMatrix(dim,&lambda, A, B);
}


void form_ScheduleVars(int dim, int* nBP, ScheduleVar* u){

	int i,j;
   
	for(i=0;i<dim;i++){
		u[i].nData =nBP[i];
		u[i].BP_Data = new double[nBP[i]];
		for(j=0;j<nBP[i];j++) u[i].BP_Data[j] = j;
	}
}

void form_SystemMatrixSet(int nMatrix, int nRows, int nCols, SystemMatrix* Set){

	int i,j;
	int index;
	double* Data;

	Data = new double[nMatrix*nRows*nCols];

	for(i=0;i<nMatrix;i++)
		for(j=0;j<nRows*nCols;j++){
			index = i*nRows*nCols+j;
			Data[index] = index;
		}
	
	
	for(i=0;i<nMatrix;i++){
		Set[i].Data = &Data[i*nRows*nCols];
		Set[i].nRows = nRows;
		Set[i].nCols = nCols;
	}
}

void formScheduleMatrix(int nVars, ScheduledMatrix* pLookupTable){

	int i;
	int dim = 3;
	int nMatrix,nRows,nCols;
	int* nBP;
	ScheduleVar* u;
	SystemMatrix* Set;
    
	nBP = new int[nVars];
	for(i=0;i<nVars;i++) nBP[i] = 2; // 5*(i+1);
	u = new ScheduleVar[dim];
	form_ScheduleVars(dim,nBP,u);

	nMatrix = 1;
	for(i=0;i<nVars;i++) nMatrix *= nBP[i];

	nRows = 1;
	nCols = 1;

	Set = new SystemMatrix[nMatrix];
	form_SystemMatrixSet(nMatrix,nRows,nCols,Set);

	
	pLookupTable->nVars = nVars;
	pLookupTable->pSystemMatrix = Set;
	pLookupTable->pVars = u;
	for(i=0;i<nVars;i++){
		pLookupTable->bReSearch[i] = 0;
		pLookupTable->bStatus[i]=-1;
		pLookupTable->index[i]=-1;
	}
}


void test_lookupMatrix(){
	
	ScheduledMatrix* pLookupTable;
	SystemMatrix B;
	double v[3];
	int bStatus;

	pLookupTable = new ScheduledMatrix;
	formScheduleMatrix(3,pLookupTable);

	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	
	B.nRows = pLookupTable->pSystemMatrix->nRows;
	B.nCols = pLookupTable->pSystemMatrix->nCols;
	int size = B.nRows * B.nCols;
	B.Data = new double[size];

	lookupMatrix(pLookupTable,v, B,bStatus);
}


void testVec(){

	Euler e,res;
	Vec3 v;
    Vec3 ev;
	double ve;
	e.phi = 1; e.theta=2;e.psi=3;
	v.x = .5; v.y=.25;v.z=0.1;
	ev = cross((Vec3&)e,v);
	res = ev;
	ve = dot((Vec3&)e,v);
}


int main(int argc, char* argv[])
{
	/*
	test_idxSearch();
	test_interpolateMatrix();
	test_lookupMatrix();
	*/
	testVec();
	return 0;
}
