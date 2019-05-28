#ifndef ScheduledMatrix_H 

#define ScheduledMatrix_H 

#include "math.h"
#include <fstream>                  
#include "matrix.h"

using namespace std;
using namespace math;
typedef matrix<double> Matrix;

template <class T, int nVars, int nTables> 
class ScheduledMatrix  {

public:
    
    ScheduledMatrix();
	
  
    ~ScheduledMatrix();



public :

    // Schedule variables, e.g., Mac, AOA, .. (nVars; MAX_VARS=3)
	// A, B, C, D are 4 members of a family of state-space scheduled matrices (nTables; MAX_MEMBERS=10) 

	void load(const char* filename);

	void save(const char* filename);

    void init(); 
	

	void setBreakpoints(int varIndex, int  nbp, T*  pbp); // Applies to all member matrices

	void get_nBP(int varIndex, int& cBP);

	void getBreakpoint(int varIndex, int ptIndex, T& bp);
	
	void initTable(int tableIndex, int  nrows, int  ncolumns); // Applies to all member matrices
    
	void setTableEntry(int tableIndex, int bpIndex[], Matrix&  memberData); // populate lookup table by index

	void getTableEntry(int tableIndex, int bpIndex[], Matrix&  memberData);
     
	void setTableEntry(int tableIndex, T* v, Matrix&  memberData);     // populate lookup table by value	

	void getTableEntry(int tableIndex, T* v, Matrix&  memberData);

	void getIndex(int tableIndex, int nvars, T* v, int* Index,T* Fraction, int* Status);
    
	void interpolate(int tableIndex, T* v); // interpolate single matrix using input port variables

	void interpolate(T*  v); // interpolate all members using input port variables

	bool IsOutOfRange();

	int STEP(int status){if(status!=0) return 0; else return 1;}

	void operator = (ScheduledMatrix* sm);


protected :
    
    void idxReSearch(T*  BP_Data, int  nBP, T  v, int*  Index, T*   fraction, int*  bStatus);
    
    void idxSearch(T*  BP_Data, int  nBP, T  v, int*  Index,  T*   fraction, int*  bStatus);

	int getAddress(int bpIndex[]); // Modify to change protected BP data organization

	


////    Attributes    ////
public:
    int nScheduleVars;
	int nMatrixTables;
    int nRows[nTables];
	int nColumns[nTables];
	Matrix* M[nTables];	  // output port variables
	int nBP[nVars];

protected:
    
		
    T* pBP[nVars];
    Matrix* pMatrixData[nTables]; // internal data for all memebrs for all breakpoints

	int bStatus[nVars];
    int bReSearch[nVars];	
	int index[nVars];
	T fraction[nVars];
};





template <class T, int nVars, int nTables>
ScheduledMatrix<T,nVars,nTables>::


ScheduledMatrix() {

	init();
}


template <class T, int nVars, int nTables>  // Copy constructor
void ScheduledMatrix<T,nVars,nTables>::operator = (ScheduledMatrix<T,nVars,nTables>* sm){

	T  bp;
	T   index[nVars];

	nScheduleVars=sm->nScheduleVars;
	nTables=sm->nTables;
	init();
	for(i=0;i<nVars;i++){
		nBP[i]=sm->nBP[i];
		if(bpData) delete bpData;
		bpData = (T*) new T[nBP[i]]; 
		for(j=0;j<nBP[i];j++){
			sm->getBreakpoint(i,j,&bp);
			bpData[j]=bp;
		}
	}
	for(i=0;i<nTables;i++){
		nRows[i]=sm->nRows[i];
		nColumns[i]=sm->nColumns[i];
		initTable(i,nRows[i],nColumns[i]);
		m.SetSize(nRows[i],nColumns[i]);
		switch(nVars){
			case 1:
				for(j=0;j<nBP[0];j++){
					index[0]=j;  
					sm->getTableEntry(i,index,m);
					setTableEntry(i,index,m);
				}
				break;

			case 2:
				for(j=0;j<nBP[0];j++){
					for(k=0;k<nBP[1];k++){
						index[0]=j; 
						index[1]=k;
						sm->getTableEntry(i,index,m);
						setTableEntry(i,index,m);
					}
				}
				break;

			case 3:
				for(j=0;j<nBP[0];j++){
					for(k=0;k<nBP[1];k++){
						for(l=0;l<nBP[2];l++){
							index[0]=j; 
							index[1]=k;
							index[2]=l;
							sm->getTableEntry(i,index,m);
						    setTableEntry(i,index,m);
						}
					}
				}
				break;

			default:
				cerr << "unsupported number of scheduling variables\n";
		}
	}
}


template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::load(const char* filename){

	ifstream fs;
	T* bpData=NULL;
	T v[nVars];
	Matrix m;

	int i,j,k,l;

	fs.open(filename);
	fs >> nScheduleVars;
	fs >> nMatrixTables;
	init(); // nVars,nTables);
	for(i=0;i<nVars;i++){
		fs >> nBP[i];
		if(bpData) delete bpData;
		bpData = (T*) new T[nBP[i]]; 
		for(j=0;j<nBP[i];j++) 
			fs >> bpData[j];
		setBreakpoints(i,nBP[i],bpData);
	}
	for(i=0;i<nTables;i++){
		fs >> nRows[i];
		fs >> nColumns[i];
		initTable(i,nRows[i],nColumns[i]);
		m.SetSize(nRows[i],nColumns[i]);
		switch(nVars){
			case 1:
				for(j=0;j<nBP[0];j++){
					fs >> v[0];  // indexing by breakpoint values (arbitrary order)
					fs >> m;
					setTableEntry(i,v,m);
				}
				break;

			case 2:
				for(j=0;j<nBP[0];j++){
					for(k=0;k<nBP[1];k++){
						fs >> v[0];  // indexing by breakpoint values
						fs >> v[1];
						fs >> m;
						setTableEntry(i,v,m);
					}
				}
				break;

			case 3:
				for(j=0;j<nBP[0];j++){
					for(k=0;k<nBP[1];k++){
						for(l=0;l<nBP[2];l++){
							fs >> v[0];  // indexing by breakpoint values
							fs >> v[1];
							fs >> v[2];
							fs >> m;
							setTableEntry(i,v,m);
						}
					}
				}
				break;

			default:
				cerr << "unsupported number of scheduling variables\n";
		}
	}
}


template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::save(const char* filename){

	 
	T v[2];
	Matrix m;
	ofstream fs;
	int i,j,k,l;

	fs.open(filename);

	fs << nVars << "\t"; 
	fs << nTables << "\n"; 
	
	// Breakpoints
	for(i=0;i<nVars;i++){
	   fs << nBP[i] << "\n";
	   if(pBP[i]){
	     for(j=0;j<nBP[i];j++)
		   fs << pBP[i][j] << "\t";
		 fs << "\n";
	   }
	}
	// Members
	for(i=0;i<nTables;i++){
		fs << nRows[i] << "\t";
		fs << nColumns[i] << "\n";

		switch(nVars){
			case 1:
				for(j=0;j<nBP[0];j++){
					fs << (v[0]=pBP[0][j]) << "\n";  // indexing by breakpoint values (arbitrary order)
					getTableEntry(i,v,m);
					fs << m << "\n";
				}
				break;

			case 2:
				for(j=0;j<nBP[0];j++){
					for(k=0;k<nBP[1];k++){
						fs << (v[0]=pBP[0][j]) << "\t";  // indexing by breakpoint values
						fs << (v[1]=pBP[1][k]) << "\n";
						getTableEntry(i,v,m);
						fs << m << "\n";
					}
				}
				break;

			case 3:
				for(j=0;j<nBP[0];j++){
					for(k=0;k<nBP[1];k++){
						for(l=0;l<nBP[2];l++){
							fs << (v[0]=pBP[0][j])  << "\t";  // indexing by breakpoint values
							fs << (v[1]=pBP[1][k])  << "\t";
							fs << (v[2]=pBP[2][l])  << "\n";
							getTableEntry(i,v,m);
							fs <<  m << "\n";
						}
					}
				}
				break;

			default:
				cerr << "unsupported number of scheduling variables\n";
		}
	}
}

template <class T, int nVars, int nTables>
ScheduledMatrix<T,nVars,nTables>::~ScheduledMatrix() {
	int i;
	
	for(i=0;i<nVars;i++)
       delete[] pBP[i];

	for(i=0;i<nTables;i++){
		delete[] pMatrixData[i];
        delete M[i];
	}
}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::idxReSearch(T*  BP_Data, int  cBP, T  v, int*  Index, T*   Fraction, int*  Status) {
    
    // Same as idxSearch, except that *Index is in/out initial guess (often from previous calls) to speedup the search.
    
    
    	int M_index,U_index,inc;
    	int bAscending;
    	int n = cBP;
    
    	*Status = 0;
    
    	bAscending=(BP_Data[n-1] > BP_Data[0]);
    
    	if(v > BP_Data[n-1] == bAscending){
    		*Index =n-1; 
    		*Fraction=1.0;
    		*Status = 1;
    		return;
    	}
    	if(v < BP_Data[0] == bAscending){
    		*Index =0;
    		*Fraction=0.0;
    		*Status = -1;
    		return;
    	}
    
    	
    	if (*Index < 0 || *Index > n-1) {
    		*Index=-1;
    		U_index=n;
    	} 
    	else {
    		inc=1;
    		if (v >= BP_Data[*Index] == bAscending) {
    			if (*Index == n-1){
    				*Status = 1;
    				*Fraction = 1.0;
    				return;
    			}
    			U_index=(*Index)+1;
    			while (v >= BP_Data[U_index] == bAscending) {
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
    			while (v < BP_Data[*Index] == bAscending) {
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
    		if (v > BP_Data[M_index] == bAscending)
    			*Index=M_index;
    		else
    			U_index=M_index;
    	}
    
    	if((v == BP_Data[0]) == bAscending) *Index=0;
    	if(fabs(BP_Data[*Index+1]-BP_Data[*Index])>1e-12) *Fraction = (v-BP_Data[*Index])/(BP_Data[*Index+1]-BP_Data[*Index]);
    	else *Fraction =  (v-BP_Data[*Index])/(1e-12 + BP_Data[*Index+1]-BP_Data[*Index]);
    
    
    //#]
}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::idxSearch(T*  BP_Data, int  cBP, T  v, int*  Index, T*  Fraction, int*  Status) {

    // void idxSearch(T BP_Data[],  int n, T v,  int *Index, T *Fraction, int *Status)
    // {
    	int U_index,M_index,L_index;
    	bool bAscending;  
    	int n = cBP;
    
    	*Status = 0;
    	L_index=-1;
    	U_index=n;
    	bAscending= (bool)(BP_Data[n-1] > BP_Data[0]);
    
    	if(v > BP_Data[n-1] == bAscending){
    		*Index =n-1; 
    		*Fraction=1.0;
    		*Status = 1;
    		return;
    	}
    	if(v < BP_Data[0] == bAscending){
    		*Index =0;
    		*Fraction = 0.0;
    		*Status = -1;
    		return;
    	}
    
    	while (U_index-L_index > 1) {
    		M_index=(U_index+L_index) >> 1;
    		if (v > BP_Data[M_index] == bAscending)
    			L_index=M_index;
    		else
    			U_index=M_index;
    	}
    	if((v == BP_Data[0]) == bAscending) *Index=0;
    	else *Index=L_index;
    	if(fabs(BP_Data[*Index+1]-BP_Data[*Index])>1e-12) *Fraction = (v-BP_Data[*Index])/(BP_Data[*Index+1]-BP_Data[*Index]);
    	else *Fraction =  (v-BP_Data[*Index])/(1e-12 + BP_Data[*Index+1]-BP_Data[*Index]);
    
    // }
    
    //#]
}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::init(){

	int i;
	nScheduleVars = nVars;
	nMatrixTables = nTables;

	for(i=0;i<nVars;i++){
		nBP[i]=0;
		pBP[i] = NULL;
	}

	for(i=0;i<nTables;i++){
		nRows[i]=0;
		nColumns[i] = 0;
		M[i] = NULL;
		pMatrixData[i] = NULL;
	}

	for(i=0;i<nVars;i++){
		bStatus[i]=0;
		bReSearch[i]=0;
		index[i]=0;
		fraction[i]=0.0;
	}
}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::setBreakpoints(int varIndex, int  nbp, T*  pbp){

	int j;

	nBP[varIndex] = nbp;
	if(pBP[varIndex]) delete pBP[varIndex]; // replace existing BP set with new one
	
	pBP[varIndex]= new T[nbp];
	if(pbp)
	  for(j=0;j<nbp;j++) (pBP[varIndex])[j] = pbp[j];
}


template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::get_nBP(int varIndex, int& cBP){

	if(varIndex>=0 && varIndex<nVars)
		cBP = nBP[varIndex];
	else
		cerr << "illegal var Index\n";
}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::getBreakpoint(int varIndex, int ptIndex, T& bp){

	if(varIndex>=0 && varIndex<nVars)
		if(ptIndex>=0 && ptIndex<nBP[varIndex])
			if(pBP) bp=pBP[varIndex][ptIndex];
			else cerr << "breakpoints are not initialized\n";
		else
			cerr << "Illegal breakpoint index\n";
	else
	cerr << "illegal var Index\n";
}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::initTable(int tableIndex, int  nrows, int  ncolumns){


	nRows[tableIndex] = nrows;
	nColumns[tableIndex] = ncolumns;
	if(!M[tableIndex])
	   M[tableIndex] = new Matrix(nrows,ncolumns);
	else{
		delete M[tableIndex];
		M[tableIndex] = new Matrix(nrows,ncolumns);
	}
}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::setTableEntry(int tableIndex, int bpIndex[], Matrix&  memberData){

	int i, index,dim;
	Matrix zeros(nRows[tableIndex],nColumns[tableIndex]);

	zeros=0.0;

	if(!pMatrixData[tableIndex]){
		dim = 1;
		for(i=0;i<nVars;i++) dim *= nBP[i];
		pMatrixData[tableIndex] = (Matrix*) new Matrix[dim];
		for(i=0;i<dim;i++) (pMatrixData[tableIndex])[i]=zeros; 
	}
	

	index = getAddress(bpIndex);
	(pMatrixData[tableIndex])[index]= memberData;

}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::getTableEntry(int tableIndex, int bpIndex[], Matrix&  memberData){

	int index;

	if(!pMatrixData[tableIndex])
		cerr << " attempt to access unintialized member data\n";

	index = getAddress(bpIndex);
	
	memberData=(pMatrixData[tableIndex])[index];

}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::setTableEntry(int tableIndex, T* v, Matrix&  memberData){

	int i;

	getIndex(tableIndex, nVars, v, index,fraction, bStatus);

	if(IsOutOfRange())
		cerr << "Extrapolation\n";
	else{
		for(i=0;i<nVars;i++)
			if(fraction[i]>0.5) index[i]++; // getIndex returns index(BP) - 1 (fraction=1 indicates pump index by one)
		setTableEntry(tableIndex, index, memberData);
	}
}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::getTableEntry(int tableIndex, T* v, Matrix&  memberData){

	int i;

	getIndex(tableIndex, nVars, v, index,fraction, bStatus);

	if(IsOutOfRange())
		cerr << "Extrapolation\n";
	else{
		for(i=0;i<nVars;i++)
			if(fraction[i]>0.5) index[i]++;
		getTableEntry(tableIndex, index, memberData);
	}
}


template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::interpolate(int tableIndex, T* v){


		int tempIndex[nVars];
        int left,right;            
        int leftTop, leftBottom , rightTop , rightBottom;
		int corner[8];
		int temp;

        getIndex(tableIndex, nVars, v, index,fraction, bStatus);
        
		if(IsOutOfRange())
			cerr << "Extrapolation\n";


		
        switch(nVars){

        	case 1:
			tempIndex[0] = index[0]; 
			left = getAddress(tempIndex);
			tempIndex[0] = index[0]+STEP(bStatus[0]);
			right = getAddress(tempIndex);
			*M[tableIndex] = (1-fraction[0])*(pMatrixData[tableIndex])[left] + fraction[0]*(pMatrixData[tableIndex])[right];
        	break;

        	case 2:
			
			tempIndex[0] = index[0];
			tempIndex[1] = index[1];
        	leftTop		 =getAddress(tempIndex);

			tempIndex[0] = index[0]+ STEP(bStatus[0]);
			tempIndex[1] = index[1];
        	leftBottom		=getAddress(tempIndex);

        	tempIndex[0] = index[0];
			tempIndex[1] = index[1]+ STEP(bStatus[1]);
        	rightTop	 =getAddress(tempIndex);	
			
			tempIndex[0] = index[0]+STEP(bStatus[0]);
			temp = STEP(bStatus[1]);
			tempIndex[1] = index[1]+STEP(bStatus[1]);
        	rightBottom	 =getAddress(tempIndex);

			*M[tableIndex] =  (1-fraction[1])*((1-fraction[0])*(pMatrixData[tableIndex]) [leftTop]+fraction[0]  *(pMatrixData[tableIndex])[leftBottom])
				+ fraction[1]   *((1-fraction[0])*(pMatrixData[tableIndex])[rightTop]+fraction[0] *(pMatrixData[tableIndex])[rightBottom]);
        	break;

        	case 3:
        	
			tempIndex[0] = index[0];
			tempIndex[1] = index[1];
			tempIndex[2] = index[2];
        	corner[0]	 =getAddress(tempIndex);

			tempIndex[0] = index[0]+STEP(bStatus[0]);
			tempIndex[1] = index[1];
			tempIndex[2] = index[2];
        	corner[1]		=getAddress(tempIndex);

        	tempIndex[0] = index[0];
			tempIndex[1] = index[1]+STEP(bStatus[1]);
			tempIndex[2] = index[2];
        	corner[2]	 =getAddress(tempIndex);	
			
			tempIndex[0] = index[0]+STEP(bStatus[0]);
			tempIndex[1] = index[1]+STEP(bStatus[1]);
			tempIndex[2] = index[2];
        	corner[3]	 =getAddress(tempIndex);

			        	
			tempIndex[0] = index[0];
			tempIndex[1] = index[1];
			tempIndex[2] = index[2]+STEP(bStatus[2]);
        	corner[4]	 =getAddress(tempIndex);

			tempIndex[0] = index[0]+STEP(bStatus[0]);
			tempIndex[1] = index[1];
			tempIndex[2] = index[2]+STEP(bStatus[2]);
        	corner[5]		=getAddress(tempIndex);

        	tempIndex[0] = index[0];
			tempIndex[1] = index[1]+STEP(bStatus[1]);
			tempIndex[2] = index[2]+STEP(bStatus[2]);
        	corner[6]	 =getAddress(tempIndex);	
			
			tempIndex[0] = index[0]+STEP(bStatus[0]);
			tempIndex[1] = index[1]+STEP(bStatus[1]);
			tempIndex[2] = index[2]+STEP(bStatus[2]);
        	corner[7]	 =getAddress(tempIndex);

			*M[tableIndex] =  
				(1-fraction[2])*(
				(1-fraction[1])*((1-fraction[0])*(pMatrixData[tableIndex])[corner[0]]+fraction[0]  *(pMatrixData[tableIndex])[corner[1]])
				+ fraction[1]   *((1-fraction[0])*(pMatrixData[tableIndex])[corner[2]]+fraction[0] *(pMatrixData[tableIndex])[corner[3]])
				)
				
				+ fraction[2]*(
				(1-fraction[1])*((1-fraction[0])*(pMatrixData[tableIndex])[corner[4]]+fraction[0]  *(pMatrixData[tableIndex])[corner[5]])
				+ fraction[1]   *((1-fraction[0])*(pMatrixData[tableIndex])[corner[6]]+fraction[0] *(pMatrixData[tableIndex])[corner[7]])
				);


        	break;
        }

}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::interpolate(T*  v){

	int i;

	for(i=0;i<nTables;i++) interpolate(i,v);
	
}

template <class T, int nVars, int nTables>
int ScheduledMatrix<T,nVars,nTables>::getAddress(int bpIndex[]){

	switch(nVars){
		case 1:
			if(bpIndex[0] >= 0 && bpIndex[0]<nBP[0])
			  return bpIndex[0];
			else{
				cerr << "invalid breakpoint index\n";
				return -1;
			}
		case 2:
			if((bpIndex[0] >= 0 && bpIndex[0]<nBP[0]) &&
			   (bpIndex[1] >= 0 && bpIndex[1]<nBP[1]))
			  return bpIndex[0]*nBP[1]+bpIndex[1];
			else{
				cerr << "invalid breakpoint index\n";
				return -1;
			}
		case 3:
			if((bpIndex[0] >= 0 && bpIndex[0]<nBP[0]) &&
			   (bpIndex[1] >= 0 && bpIndex[1]<nBP[1]) &&
			   (bpIndex[2] >= 0 && bpIndex[2]<nBP[2]))
			return bpIndex[0]*nBP[1]*nBP[2]
				   +bpIndex[1]*nBP[2]+bpIndex[2];
			else{
				cerr << "invalid breakpoint index\n";
				return -1;
			}
		default:
			return -1;
	}
}

template <class T, int nVars, int nTables>
void ScheduledMatrix<T,nVars,nTables>::getIndex(int tableIndex, int nvars, T* v, int* Index,T* Fraction, int* Status){
	
	int i;
	if(nvars==nVars){
		for(i=0;i<nvars;i++){
			if(bReSearch[i]==0){
			   idxSearch(pBP[i],nBP[i],v[i],&Index[i],&Fraction[i],&Status[i]);
			   bReSearch[i] = 1;
			}
			else{
			   idxSearch(pBP[i],nBP[i],v[i],&Index[i],&Fraction[i],&Status[i]);
			} 
		}
	}
}

template <class T, int nVars, int nTables>
bool ScheduledMatrix<T,nVars,nTables>::IsOutOfRange(){
		//Extrapolation outside table
		int i, status=0;
		for(i=0;i<nVars;i++)
			status |= bStatus[i];
		if(status)
			return true;
		else
			return false;
}

// Add code to support linear extrapolation and other types of interpolation


#endif  