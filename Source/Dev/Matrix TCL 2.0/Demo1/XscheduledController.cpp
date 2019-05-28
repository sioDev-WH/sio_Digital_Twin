// scheduledController.cpp: implementation of the scheduledController class.
//
//////////////////////////////////////////////////////////////////////

#include "scheduledController.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#include "ScheduledMatrix.h"

#define NMATRIX 4

template <class T, int dim,int Nx, int Nu, int Ny> scheduledController<T,dim,Nx,Nu,Ny>::scheduledController(int Nx, int Nu, int Ny)
{

	nx = Nx;
	nu=Nu;
	ny = Ny;
	x = (T*) new T[nx];

	
}

template <class T, int dim,int Nx, int Nu, int Ny> scheduledController<T,dim,Nx,Nu,Ny>::~scheduledController()
{


}

template <class T, int dim,int Nx, int Nu, int Ny> 
void scheduledController<T,dim,Nx,Nu,Ny>::setCoeff(ScheduledMatrix<double,dim,NMATRIX>* sm){



}

template <class T, int dim,int Nx, int Nu, int Ny> 
void scheduledController<T,dim,Nx,Nu,Ny>::set_initialState(T* X0){



}

template <class T, int dim,int Nx, int Nu, int Ny> 
void scheduledController<T,dim,Nx,Nu,Ny>::handle_tick(T* u){



}