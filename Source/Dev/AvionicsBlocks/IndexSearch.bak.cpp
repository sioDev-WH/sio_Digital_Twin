#include <math.h>
#include "IndexSearch.h"



// Structure of pSystemMatrix within the ScheduledMatrix in case of 3 scheduleVars
//     v1 v2 v3  Matrix
//      i  j  k   index
//      -------------
//      0  0  0     0
//      0  0  1     1
//      0  0  2     2
//      :  :  :     :
//      0  0  K-1   K-1    <--- End of one scheduling-variable case (K = v3.nData)
//      -------------
//      0  1  0     K
//      0  1  1     K+1
//      0  1  2     K+2
//      0  :  :     :
//      0  1  K-1   2K-1
//      -------------
//      :  :  :     :
//      :  :  :     :
//      :  :  :     :
//      :  :  :     :
//      :  :  :     :
//      -------------
//      0 J-1 0     :
//      0 J-1 1     :
//      0 J-1 2     :
//      0  :  :     :
//      0 J-1 K-1   J*K-1  <--- End of two scheduling-variable case (J = v2.nData, K = v3.nData)
//      -------------
//      :  :  :     :
//      :  :  :     :
//      :  :  :     :
//      :  :  :     :
//      :  :  :     :
//      -------------
//      I  :  0     :
//      I  :  1     :
//      I  :  2     :
//      I  :  1
//    I-1 J-1 K-1   I*J*K-1 <--- End of three scheduling-variable case (I = v1.nData, J = v2.nData, K = v3.nData)





// Always return index to the left of the data,u.
// bStatus = 0 if within data range; otherwise +/- 1 (L.T. or G.T., respectively)
// The fraction is the distance from (u - Data[index])/(Data[index+1]-Data[index]); use as lambda in linear interpolation
// Note: if fraction (i.e., lambda) = 1.0, then u is actually Data[index+1].
void idxSearch(double BP_Data[],  int n, double u,  int *Index, double *fraction, int *bStatus)
{
	int U_index,M_index,L_index;
	bool bAscending;

	*bStatus = 0;
	L_index=-1;
	U_index=n;
	bAscending= (bool)(BP_Data[n-1] > BP_Data[0]);

	if(u > BP_Data[n-1] == bAscending){
		*Index =n-1;
		*bStatus = 1;
		return;
	}
	if(u < BP_Data[0] == bAscending){
		*Index =0;
		*bStatus = -1;
		return;
	}

	while (U_index-L_index > 1) {
		M_index=(U_index+L_index) >> 1;
		if (u > BP_Data[M_index] == bAscending)
			L_index=M_index;
		else
			U_index=M_index;
	}
	if((u == BP_Data[0]) == bAscending) *Index=0;
	else *Index=L_index;
	if(fabs(BP_Data[*Index+1]-BP_Data[*Index])>1e-12) *fraction = (u-BP_Data[*Index])/(BP_Data[*Index+1]-BP_Data[*Index]);
	else *fraction =  (u-BP_Data[*Index])/(1e-12 + BP_Data[*Index+1]-BP_Data[*Index]);

}


// Same as idxSearch, except that *Index is in/out initial guess (often from previous calls) to speedup the search.
void idxReSearch(double BP_Data[],  int n, double u,  int *Index, double *fraction, int *bStatus)
{
	int M_index,U_index,inc;
	int bAscending;

	*bStatus = 0;

	bAscending=(BP_Data[n-1] > BP_Data[0]);

	if(u > BP_Data[n-1] == bAscending){
		*Index =n-1;
		*bStatus = 1;
		return;
	}
	if(u < BP_Data[0] == bAscending){
		*Index =0;
		*bStatus = -1;
		return;
	}

	
	if (*Index < 0 || *Index > n-1) {
		*Index=-1;
		U_index=n;
	} 
	else {
		inc=1;
		if (u >= BP_Data[*Index] == bAscending) {
			if (*Index == n-1){
				*bStatus = 1;
				*fraction = 1.0;
				return;
			}
			U_index=(*Index)+1;
			while (u >= BP_Data[U_index] == bAscending) {
				*Index=U_index;
				inc += inc;
				U_index=(*Index)+inc;
				if (U_index > n-1) {
					U_index=n;
					break;
				}
			}
		} 
		else {
			if (*Index == 0) {
				*Index=-1;
				return;
			}
			U_index=(*Index)--;
			while (u < BP_Data[*Index] == bAscending) {
				U_index=(*Index);
				inc <<= 1;
				if (inc >= U_index) {
					*Index=-1;
					break;
				}
				else *Index=U_index-inc;
			}
		}
	}
	while (U_index-(*Index) != 1) {
		M_index=(U_index+(*Index)) >> 1;
		if (u > BP_Data[M_index] == bAscending)
			*Index=M_index;
		else
			U_index=M_index;
	}

	if((u == BP_Data[0]) == bAscending) *Index=0;
	if(fabs(BP_Data[*Index+1]-BP_Data[*Index])>1e-12) *fraction = (u-BP_Data[*Index])/(BP_Data[*Index+1]-BP_Data[*Index]);
	else *fraction =  (u-BP_Data[*Index])/(1e-12 + BP_Data[*Index+1]-BP_Data[*Index]);
}



// This function is equivalent to all three interpolateMatrix blocks of Simulink Aerospace blockset
// For higher dimensions (if #scheduling variables = dim > 3), use recursive calls to dim-1 version
// down to interpolateMatrix
void interpolateMatrix(int dim, double lambda[], SystemMatrix A[], SystemMatrix &B){	
	int i,j,index;
	int n = A[0].nRows;
	int m = A[0].nCols;
	
	// check dimensions consistency of other matrices

	switch(dim){
	case 1:// interpolating 2 matrices from  search of 1 scheduleVar A[index_i] and A[index_i+1]
		   // referenced here as A[0] and A[1]
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				index = i*m+j;
				B.Data[index] = (1-lambda[0]) *A[0].Data[index] + lambda[0]*A[1].Data[index];
			}
		break;
	case 2:// interpolating 4 matrices from  search of 2 scheduleVars 
		   // A[index_i, index_j], A[index_i,index_j+1], A[index_i+1,index_j],A[index_i+1,index_j+1] 
		   // referenced here as A[0], A[1], A[2] and A[3]
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				index = i*m+j;
				B.Data[index] = (1-lambda[1])*((1-lambda[0])*A[0].Data[index] + lambda[0]*A[2].Data[index]) 
		      	                 + lambda[1] *((1-lambda[0])*A[1].Data[index] + lambda[0]*A[3].Data[index]);
			}
		  
		break;
	case 3:// interpolating 8 matrices from  search of 3 scheduleVars 
		   // A[index_i, index_j,  index_k], A[index_i,index_j, index_k+1], 
		   // A[index_i,index_j+1, index_k], A[index_i,index_j+1, index_k+1] 
		   // A[index_i+1, index_j,  index_k], A[index_i+1,index_j, index_k+1], 
		   // A[index_i+1,index_j+1, index_k], A[index_i+1,index_j+1, index_k+1]
		   // referenced here as A[0], A[1], A[2], ..., A[7]
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				index = i*m+j;
		        B.Data[index] =   (1-lambda[2])*
					             ((1-lambda[1])*((1-lambda[0])*A[0].Data[index] + lambda[0]*A[4].Data[index]) 
							       + lambda[1] *((1-lambda[0])*A[2].Data[index] + lambda[0]*A[6].Data[index]))
			                        +lambda[2] *
				                 ((1-lambda[1])*((1-lambda[0])*A[1].Data[index] + lambda[0]*A[5].Data[index]) 
							       + lambda[1] *((1-lambda[0])*A[3].Data[index] + lambda[0]*A[7].Data[index]));
			}
		break;
	}
}


void getBlend(ScheduledMatrix* A, int* Index, double* lambda, SystemMatrix& B) // output from idxSearch or idxReSearch
{
	int n1,n2,temp;
	int dim = A->nVars;
	SystemMatrix* pMatrix[8];


	switch(dim){
	case 1:
		pMatrix[0] = &(A->pSystemMatrix[Index[0]]);
		pMatrix[1] = &(A->pSystemMatrix[Index[0]+1]);
		break;
	case 2:
		n1 = A->pVars[1].nData;
		pMatrix[0] = &(A->pSystemMatrix[Index[0]    *n1     + Index[1]]);
		pMatrix[1] = &(A->pSystemMatrix[Index[0]    *n1     + Index[1]+1]);
		pMatrix[2] = &(A->pSystemMatrix[(Index[0]+1)*n1     + Index[1]]);
		pMatrix[3] = &(A->pSystemMatrix[(Index[0]+1)*n1     + Index[1]+1]);
		break;
	case 3:
		n1 = A->pVars[1].nData;
		n2 = A->pVars[2].nData;
		temp = n1*n2;
		pMatrix[0] = &(A->pSystemMatrix[ Index[0]   *temp    +  Index[1]   *n2     + Index[2]]);
		pMatrix[1] = &(A->pSystemMatrix[ Index[0]   *temp    +  Index[1]   *n2     + Index[2]+1]);
		pMatrix[2] = &(A->pSystemMatrix[ Index[0]   *temp    + (Index[1]+1)*n2     + Index[2]]);
		pMatrix[3] = &(A->pSystemMatrix[ Index[0]   *temp    + (Index[1]+1)*n2     + Index[2]+1]);
		pMatrix[4] = &(A->pSystemMatrix[(Index[0]+1)*temp    +  Index[1]   *n2     + Index[2]]);
		pMatrix[5] = &(A->pSystemMatrix[(Index[0]+1)*temp    +  Index[1]   *n2     + Index[2]+1]);
		pMatrix[6] = &(A->pSystemMatrix[(Index[0]+1)*temp    + (Index[1]+1)*n2     + Index[2]]);
		pMatrix[7] = &(A->pSystemMatrix[(Index[0]+1)*temp    + (Index[1]+1)*n2     + Index[2]+1]);
		break;
	default:
		;//Error
		break;
	}
	interpolateMatrix(dim, lambda, *pMatrix, B);	
}

void lookupMatrix(ScheduledMatrix* A, double* u, SystemMatrix& B, int &bStatus){ 

	int k;
	
	int dim = A->nVars;
	ScheduleVar* pVars;
	double* pBP_Data;
	int nData;
	int Index[3]; 
	double lambda[3]; 
	int Status[3];

	bStatus = 0;

	for(k=0;k<dim;k++){
		pVars = &(A->pVars[k]);
		pBP_Data = pVars->BP_Data;
		nData = pVars->nData;
		if(A->bReSearch[k]==0)
		   idxSearch(pBP_Data,nData,u[k],& Index[k], &lambda[k], &Status[k]); // check status
		else
		   idxReSearch(pBP_Data,nData,u[k],&Index[k], &lambda[k], &Status[k]); // check status
		A->bReSearch[k] = 1;
		A->index[k] = Index[k];
		A->lambda[k] = lambda[k];
		A->bStatus[k] = Status[k];
	}
	for(k=0;k<dim;k++)
		if(Status[k] != 0) bStatus=Status[k];
	if(!bStatus) 
		getBlend(A, Index, lambda,B);
}

// Add scheduled system/controller classes
// Add a method functions that locate all blend matrices of a dynamic system/controller (A,B,C,D)
// Add a method that simulate continuous dynamic system/controller (A,B,C,D)
// Add a method that discretize continuous dynamic system/controller (A,B,C,D) using sample and hold and Tutsin
// Add a method that discretize continuous dynamic system/controller (A,B,C,D) using sample and hold and Tutsin
// Add helper functions that locate specific column of the blend matrix (B[j])
// Add helper functions that locate specific element of the blend matrix (B[i][j])
// Add helper functions that create ScheduledMatrix from data files or Matrix editor
// Support for fixed-point arithmatics
