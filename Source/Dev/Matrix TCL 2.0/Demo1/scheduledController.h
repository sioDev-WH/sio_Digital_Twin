// scheduledController.h: interface for the scheduledController class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCHEDULEDCONTROLLER_H__2BF8EE21_4A2C_475D_AC85_A47511C03B7D__INCLUDED_)
#define AFX_SCHEDULEDCONTROLLER_H__2BF8EE21_4A2C_475D_AC85_A47511C03B7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define NMATRIX 4  // Default number of system matrices (A,B,C,D)

template <class T, int nVars, int nTables> 
class ScheduledMatrix;

template <class T, int Dim,int Nx, int Nu, int Ny, int Nm=NMATRIX> 
class scheduledController   
{
public:
	scheduledController(int nx, int nu,int ny, int nm=Nm);
	virtual ~scheduledController();


public:
	int nx;
	int nu;
	int uy;
	int nm;
	int dim;
	T* x;
	T y;
	ScheduledMatrix* pCoeff;
void	setCoeff(ScheduledMatrix sm);
void	set_initialState(T* X0);
void	handle_tick(T* u);

};



template <class T, int Dim,int Nx, int Nu, int Ny, int Nm> 
scheduledController<T,Dim,Nx,Nu,Ny,Nm>::scheduledController(int Nx, int Nu, int Ny, int Nm)
{

	nx = Nx;
	nu=Nu;
	ny = Ny;
	nm = Nm;
	dim = Dim;
	x = (T*) new T[nx];
	pCoeff = (ScheduledMatrix*) new ScheduledMatrix<T,Dim,Nm>;
	
	
}

template <class T, int Dim,int Nx, int Nu, int Ny,int Nm> 
scheduledController<T,Dim,Nx,Nu,Ny>::~scheduledController()
{
	if(pCoeff) delete pCoeff;

}

template <class T, int Dim,int Nx, int Nu, int Ny,int Nm> 
void scheduledController<T,Dim,Nx,Nu,Ny>::setCoeff(ScheduledMatrix<double,Dim,Nm> sm){

	pCoeff = sm;
}

template <class T, int Dim,int Nx, int Nu, int Ny,int Nm> 
void scheduledController<T,Dim,Nx,Nu,Ny>::set_initialState(T* X0){

	int i;

	for(i=0;i<Nx;i++) x[i] = X0[i];

}

template <class T, int Dim,int Nx, int Nu, int Ny,int Nm> 
void scheduledController<T,Dim,Nx,Nu,Ny>::handle_tick(T* u){

	T x_old[Nx];
	Matrix* A,B,C,D;

	for(i=0;i<Nx;i++) x_old[i] = x[i];
	
	pCoeff->updateAll(u);

	A = pCoeff->M[0];
	B = pCoeff->M[1];
	C = pCoeff->M[2];
	D = pCoeff->M[3];
	// replace with compact matrix-vector notation
	for(i=0;i<Nx;i++){
		for(j=0;j<Nx;j++) x[i] +=A[i][j]*x[j]; 
		for(j=0;j<Nu;j++) x[i] +=B[i][j]*u[j];
	}
	for(i=0;i<Ny;i++){
		for(j=0;j<Nx;j++) y[i] +=C[i][j]*x[j];
		for(j=0;j<Nu;j++) y[i] +=D[i][j]*u[j];
	}
}

#endif // !defined(AFX_SCHEDULEDCONTROLLER_H__2BF8EE21_4A2C_475D_AC85_A47511C03B7D__INCLUDED_)
