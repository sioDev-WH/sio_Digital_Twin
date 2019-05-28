/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: ControlDesigner
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\ControlDesigner.cpp
*********************************************************************/

#include "ControlDesigner.h"
#include "math.h"
#include "mkl.h"

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// ControlDesigner.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class ControlDesigner 

#define max(a,b) (a>=b)? a:b
ControlDesigner::ControlDesigner() {
}

ControlDesigner::~ControlDesigner() {
}

void ControlDesigner::SS_discretize(double  Ts, int  n, int  m, double*  Ac, double*  Bc, double*  Ad, double*  Bd) {
    //#[ operation SS_discretize(double,int,int,double*,double*,double*,double*) 
    	int i,j;
    	
    	double *AB;
    	double *g;
    	int nmsqr = (n+m)*(n+m);
    
    	AB = (double*) new double[nmsqr];
    	g =  (double*) new double[nmsqr];
    
    	for(i=0;i<n;i++){
    		for(j=0;j<n;j++)
    			AB[i*(n+m)+j] = Ac[i*n + j] * Ts;
    		for(j=0;j<m;j++)
    			AB[i*(n+m)+(j+n)] = Bc[i*m + j] * Ts;
    	}
    	for(i=n;i<(n+m);i++)
    		for(j=0;j<(n+m);j++)
    			AB[i*(n+m)+j] = 0.0;
    
    	expm(n+m, AB, g);
    	for(i=0;i<n;i++){				// Discrete system matrices Ad and Bd (Cd = Cc and Dd = Dc). 
    		for(j=0;j<n;j++)
    			Ad[i*n + j] = g[i*(n+m)+j];
    		for(j=0;j<m;j++)
    			Bd[i*m + j] = g[i*(n+m)+j+n];
    	}
    	delete AB;
    	delete g;
    //#]
}

void ControlDesigner::expm(int  n, double*  A, double*  E) {
    //#[ operation expm(int,double*,double*) 
      int i,j,k;
      int index;
    
    
      int e = (int)ceil(log2(norm_infinity(n,A)));
      double s = (max(0, e + 1));
      double s2 = pow(2,s);
    
      double *D;
      int nsqr = n*n;
    
      D = (double*) new double[nsqr];
    
      double c = 0.5;
      for(i=0;i<n;i++)
    	  for(j=0;j<n;j++){
    		  index = i*n+j;
    		  A[index] = A[index]/s2;
    		  if(i != j){
    			  E[index] =   c*A[index];
    			  D[index] = - c*A[index];
    		  }
    		  else{
    			  E[index] = 1.0 + c*A[index];
    			  D[index] = 1.0 - c*A[index];
    		  }
    	  }
    
      int q = 6;
      bool p = true;
    
      double *X, *cX, *Y;
    
      X = (double*) new double[nsqr];
      cX = (double*) new double[nsqr];
      Y = (double*) new double[nsqr];
    
      for(i=0;i<nsqr;i++){
    	  X[i] = A[i];
    	  Y[i] = 0.0;
      }
    
      for(k = 2;k<=q;k++){
    
    	c = c * (q - k + 1)/(k*(2*q-k+1));
    
    	prod(n, A , X,  X);
    	
    	for(i=0;i<nsqr;i++){
    		cX[i] = c*X[i];
    		E[i] = E[i] + cX[i];
    	}
    		if(p)
    
    			for(i=0;i<nsqr;i++) D[i] = D[i] + cX[i];
    		else
    			for(i=0;i<nsqr;i++) D[i] = D[i] - cX[i];
    		p = !p;
      }
    
      solve(n, D, E, Y);
    
      for(k=0;k<s;k++){
    	 prod(n, Y, Y, Y);
      }
      for(i=0;i<nsqr;i++) E[i] = Y[i];
    
      delete D;
      delete X;
      delete cX;
      delete Y;
    //#]
}

double ControlDesigner::log2(double  x) {
    //#[ operation log2(double) 
    	if(x == 0.0) return 0;
    	else return log(x)/log(2);
    //#]
}

double ControlDesigner::norm_infinity(int  n, double*  A) {
    //#[ operation norm_infinity(int,double*) 
        int i,j;
    	double row_sum, norm=0.0;
    	for(i=0;i<n;i++){ 
    		row_sum = 0;
    		for(j=0;j<n;j++)
    			row_sum += fabs(A[i*n+j]);
    		if(norm<row_sum) 
    			norm = row_sum;
    	}	
      return norm;
    //#]
}

void ControlDesigner::prod(int  n, double*  A, double*  B, double* &C) {
    //#[ operation prod(int,double*,double*,double* &) 
    	int i,j,k;
    	int index_ij,index_ik,index_kj;
    
    	double *temp;
    	temp = new double[n*n];
    
    	for(i=0;i<n;i++)
    		for(j=0;j<n;j++){
    			index_ij = i*n+j;
    			temp[index_ij] = 0.0;
    			for(k=0;k<n;k++){
    				index_ik = i*n+k;
    				index_kj = k*n+j;
    			    temp[index_ij] += A[index_ik]*B[index_kj];
    			}
    		}
    
    		for(i=0;i<n*n;i++) C[i] = temp[i];
    		delete temp;
    //#]
}

void ControlDesigner::solve(int  n, double*  A, double*  B, double* &C) {
    //#[ operation solve(int,double*,double*,double* &) 
    	double *b;
    	int i,nsqr=n*n;
    	int info;
    
    	b = new double[nsqr];
    	int *pivot;
    	pivot = new int[n];
    	for(i=0;i<nsqr;i++)
    			b[i] = B[i];
       DGESV(&n, &n, A, &n, pivot, b, &n, &info);
    
    	for(i=0;i<nsqr;i++)
    			C[i] = b[i];
    	
    	delete pivot;
    	delete b;
    //#]
}

double ControlDesigner::trace(int  n, double*  A) {
    //#[ operation trace(int,double*) 
    	double tr = 0.0;
    	int i,j;
    
    	for(i=0;n;i++)
    		for(j=0;j<n;j++)
    			tr += A[i*n+j];
    	return tr;
    //#]
}



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\ControlDesigner.cpp
*********************************************************************/

