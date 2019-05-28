#ifndef _IndexSearch_H
#define _IndexSearch_H

typedef struct _ScheduleVar{
		int    nData;
		double* BP_Data;
} ScheduleVar;

typedef struct _SystemMatrix{ // Can use any other matrix class
		int	nRows;		
		int	nCols;
		double* Data; // Column-wise
		// double getAt(int i, int j){if(i>0&&j>0&&i<nRows&&j<nCols) return Data[i*nCols + j];} // Macro or inline
		// void setAt(int i, int j, double val){if(i>0&&j>0&&i<nRows&&j<nCols)Data[i*nCols + j] = val;}
}SystemMatrix;

typedef struct _ScheduledMatrix{
		int nVars;	// 1,2 or 3
		ScheduleVar* pVars; // e.g., AOA or Mach
		SystemMatrix* pSystemMatrix; // e.g., one of {A} or {B} or {C} or {D} of System Dynamics
		int index[3]; // optional -- store old index for speedup search
		double lambda[3];// optional -- store old fractions for speedup search
		int bStatus[3];// optional -- store old status for error detection
		int bReSearch[3];// optional -- store old index for speedup search
		
} ScheduledMatrix;


void idxReSearch(double BP_Data[],  int n, double u,  int *Index, double *fraction, int *bStatus);
void lookupMatrix(ScheduledMatrix* A, double* u, SystemMatrix& B, int &bStatus);
void getBlend(ScheduledMatrix* A, int* Index, double* lambda, SystemMatrix& B);
void interpolateMatrix(int dim, double lambda[], SystemMatrix* A, SystemMatrix &B);
void idxSearch(double BP_Data[],  int n, double u,  int *Index, double *fraction, int *bStatus);


#endif
