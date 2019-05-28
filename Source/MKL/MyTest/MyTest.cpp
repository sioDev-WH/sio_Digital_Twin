// MyTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include <time.h>
#include "mkl.h"
extern "C" double DDOT(int *n,double *x,int *incx,double *y,int *incy);

int main(int argc, char* argv[])
{

	#define N 4000
	#define Iterations 1000

	int n,inca =1,incb =1,i;
	double a[N], b[N], c;
  double **A,*B;
	clock_t start, finish;
	double  duration;
  int j,M,LDA,LDB,*IPIV,NRHS,INFO;
  char TRANS[1];

	n =N;
	for(i =0;i <n;i++){
		a[i]= (double)i/n;
		b[i] = (double)(n - i)/n;
	}
	start = clock();
	for(i=0;i<Iterations;i++)
		c = DDOT(  &n, a, &inca, b, &incb );
	finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cerr << "The dot product is:" <<  c  << "in " << duration/Iterations << " Sec." << endl;


  A = (double**) new double*[N];
  for(i=0;i<N;i++) A[i] = (double*) new double[N];
  B = (double*) new double[N];
  IPIV = (int*) new int[N];

  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      if(i==j)
        A[i][j] = i;
      else
        A[i][j] = 0.0;
  for(i=0;i<N;i++) B[i]=1.0;

  M=n;
  LDA = n;
  LDB = n;

  //DGETRF(&M, &n, (double *)A, &LDA, IPIV, &INFO);
  *TRANS = 'N';
  NRHS = 1;
  //DGETRS(TRANS, &n, &NRHS, (double *)A, &LDA, IPIV, B, &LDB, &INFO);

	return 0;
}
