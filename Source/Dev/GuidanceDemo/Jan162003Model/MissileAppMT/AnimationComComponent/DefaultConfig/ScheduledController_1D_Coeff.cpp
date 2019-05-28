/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: ScheduledController_1D_Coeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\ScheduledController_1D_Coeff.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "ScheduledController_1D_Coeff.h"
#include "ControlDesigner.h"
#include <stdafx.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define LibraryPkg_AvionicsPkg_ScheduledController_1D_Coeff_ScheduledController_1D_Coeff_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_ScheduledController_1D_Coeff_clean_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_ScheduledController_1D_Coeff_init_SERIALIZE \
    aomsmethod->addAttribute("Nv", x2String(Nv)); \
    aomsmethod->addAttribute("V", x2String(V)); \
    aomsmethod->addAttribute("V0", x2String(V0)); \
    aomsmethod->addAttribute("Nx", x2String(Nx)); \
    aomsmethod->addAttribute("Nu", x2String(Nu)); \
    aomsmethod->addAttribute("Ny", x2String(Ny)); \
    aomsmethod->addAttribute("Ac", x2String(Ac)); \
    aomsmethod->addAttribute("Bc", x2String(Bc)); \
    aomsmethod->addAttribute("Cc", x2String(Cc)); \
    aomsmethod->addAttribute("Dc", x2String(Dc)); \
    aomsmethod->addAttribute("X0", x2String(X0));


#define LibraryPkg_AvionicsPkg_ScheduledController_1D_Coeff_locate_SERIALIZE \
    aomsmethod->addAttribute("val", x2String(val)); \
    aomsmethod->addAttribute("index", x2String(index));


#define LibraryPkg_AvionicsPkg_ScheduledController_1D_Coeff_update_SERIALIZE aomsmethod->addAttribute("val", x2String(val));
//#]

//----------------------------------------------------------------------------
// ScheduledController_1D_Coeff.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class ScheduledController_1D_Coeff 



ScheduledController_1D_Coeff::ScheduledController_1D_Coeff() {
    NOTIFY_CONSTRUCTOR(ScheduledController_1D_Coeff, ScheduledController_1D_Coeff(), 0, LibraryPkg_AvionicsPkg_ScheduledController_1D_Coeff_ScheduledController_1D_Coeff_SERIALIZE);
    itsControlDesigner = NULL;
    //#[ operation ScheduledController_1D_Coeff() 
    v = NULL;
    
    Av = NULL;
    Bv = NULL;
    Cv = NULL;
    Dv = NULL;
    x0 = NULL; 
    
    A = NULL;
    B = NULL;
    C = NULL;
    D = NULL;
    //#]
}

ScheduledController_1D_Coeff::~ScheduledController_1D_Coeff() {
    NOTIFY_DESTRUCTOR(~ScheduledController_1D_Coeff, TRUE);
    //#[ operation ~ScheduledController_1D_Coeff() 
    clean();
    //#]
    cleanUpRelations();
}

void ScheduledController_1D_Coeff::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, LibraryPkg_AvionicsPkg_ScheduledController_1D_Coeff_clean_SERIALIZE);
    //#[ operation clean() 
    
    if(v) delete[] v;
    if(Av) 	delete[] Av;
    if(Bv) 	delete[] Bv;
    if(Cv) 	delete[] Cv;
    if(Dv) 	delete[] Dv;
    if(A) 	delete[] A;
    if(B) 	delete[] B;
    if(C) 	delete[] C;
    if(D) 	delete[] D;
    if(x0) 	delete[]x0;
    
    //#]
}

void ScheduledController_1D_Coeff::init(int  Nv, double V[], double  V0, int  Nx, int  Nu, int  Ny, double Ac[], double Bc[], double Cc[], double Dc[], double X0[]) {
    NOTIFY_OPERATION(init, init(int,double [],double,int,int,int,double [],double [],double [],double [],double []), 11, LibraryPkg_AvionicsPkg_ScheduledController_1D_Coeff_init_SERIALIZE);
    //#[ operation init(int,double [],double,int,int,int,double [],double [],double [],double [],double []) 
    int i,k;
    period =    1.0;
    double Ts = period/1000.0;
    
    nv = Nv;
    nx = Nx;
    nu = Nu;
    ny = Ny;
    
    v = new double[nv];
    
    Av = new double[nv*nx*nx];
    Bv = new double[nv*nx*nu];
    Cv = new double[nv*ny*nx];
    Dv = new double[nv*ny*nu];
    x0 = new double[nx]; 
    
    A = new double[nx*nx];
    B = new double[nx*nu];
    C = new double[ny*nx];
    D = new double[ny*nu];
    
    itsControlDesigner = new ControlDesigner;
    
    for(k=0;k<nv;k++){
    	v[k] = V[k];
    	itsControlDesigner->SS_discretize(Ts,nx,nu,&Ac[k*nx*nx],&Bc[k*nx*nu],&Av[k*nx*nx],&Bv[k*nx*nu]);
    	for(i=0;i<ny*nx;i++)Cv[k*ny*nx + i] = Cc[k*ny*nx + i];
    	for(i=0;i<ny*nu;i++)Dv[k*ny*nu + i] = Dc[k*ny*nu + i];  
    }
    
    v0 = V0;
    for(i=0;i<nx;i++) x0[i] = X0[i];
    
    delete itsControlDesigner;
    //#]
}

void ScheduledController_1D_Coeff::locate(double  val, int*  index) {
    NOTIFY_OPERATION(locate, locate(double,int* ), 2, LibraryPkg_AvionicsPkg_ScheduledController_1D_Coeff_locate_SERIALIZE);
    //#[ operation locate(double,int* ) 
    
    
    int ascnd, upper,middle,lower;
    
    lower = -1;
    upper = nv;
    if(v[nv-1]>v[0]) ascnd = 1;
    else ascnd = 0;
    while(upper - lower > 1){
    	middle = (upper+lower) >> 1;
    	if((val > v[middle]) ==  ascnd) 
    		lower = middle;
    	else 
    	 	upper = middle; 
    }
    *index = lower; 
    
     	
    //#]
}

void ScheduledController_1D_Coeff::update(double  val) {
    NOTIFY_OPERATION(update, update(double), 1, LibraryPkg_AvionicsPkg_ScheduledController_1D_Coeff_update_SERIALIZE);
    //#[ operation update(double) 
    // Compute Ad,Bd,Cd,Dd based on value of v 
    int i,k;
    locate(val,&k);
    for(i=0;i<nx*nx;i++)A[i] = Av[k*ny*nx + i];
    for(i=0;i<nu*nx;i++)B[i] = Bv[k*ny*nx + i];
    for(i=0;i<ny*nx;i++)C[i] = Cv[k*ny*nx + i];
    for(i=0;i<ny*nu;i++)D[i] = Dv[k*ny*nu + i];      
    //#]
}

double* ScheduledController_1D_Coeff::getA() const {
    return A;
}

void ScheduledController_1D_Coeff::setA(double*  p_A) {
    A = p_A;
}

double* ScheduledController_1D_Coeff::getAv() const {
    return Av;
}

void ScheduledController_1D_Coeff::setAv(double*  p_Av) {
    Av = p_Av;
}

double* ScheduledController_1D_Coeff::getB() const {
    return B;
}

void ScheduledController_1D_Coeff::setB(double*  p_B) {
    B = p_B;
}

double* ScheduledController_1D_Coeff::getBv() const {
    return Bv;
}

void ScheduledController_1D_Coeff::setBv(double*  p_Bv) {
    Bv = p_Bv;
}

double* ScheduledController_1D_Coeff::getC() const {
    return C;
}

void ScheduledController_1D_Coeff::setC(double*  p_C) {
    C = p_C;
}

double* ScheduledController_1D_Coeff::getCv() const {
    return Cv;
}

void ScheduledController_1D_Coeff::setCv(double*  p_Cv) {
    Cv = p_Cv;
}

double *  ScheduledController_1D_Coeff::getD() const {
    return D;
}

void ScheduledController_1D_Coeff::setD(double * p_D) {
    D = p_D;
}

double *  ScheduledController_1D_Coeff::getDv() const {
    return Dv;
}

void ScheduledController_1D_Coeff::setDv(double * p_Dv) {
    Dv = p_Dv;
}

int ScheduledController_1D_Coeff::getNu() const {
    return nu;
}

void ScheduledController_1D_Coeff::setNu(int  p_nu) {
    nu = p_nu;
}

int ScheduledController_1D_Coeff::getNv() const {
    return nv;
}

void ScheduledController_1D_Coeff::setNv(int  p_nv) {
    nv = p_nv;
}

int ScheduledController_1D_Coeff::getNx() const {
    return nx;
}

void ScheduledController_1D_Coeff::setNx(int  p_nx) {
    nx = p_nx;
}

int ScheduledController_1D_Coeff::getNy() const {
    return ny;
}

void ScheduledController_1D_Coeff::setNy(int  p_ny) {
    ny = p_ny;
}

double ScheduledController_1D_Coeff::getPeriod() const {
    return period;
}

void ScheduledController_1D_Coeff::setPeriod(double  p_period) {
    period = p_period;
}

double* ScheduledController_1D_Coeff::getV() const {
    return v;
}

void ScheduledController_1D_Coeff::setV(double*  p_v) {
    v = p_v;
}

double ScheduledController_1D_Coeff::getV0() const {
    return v0;
}

void ScheduledController_1D_Coeff::setV0(double  p_v0) {
    v0 = p_v0;
}

double* ScheduledController_1D_Coeff::getX0() const {
    return x0;
}

void ScheduledController_1D_Coeff::setX0(double*  p_x0) {
    x0 = p_x0;
}

ControlDesigner* ScheduledController_1D_Coeff::getItsControlDesigner() const {
    return itsControlDesigner;
}

void ScheduledController_1D_Coeff::setItsControlDesigner(ControlDesigner*  p_ControlDesigner) {
    itsControlDesigner = p_ControlDesigner;
}

void ScheduledController_1D_Coeff::cleanUpRelations() {
    if(itsControlDesigner != NULL)
        {
            itsControlDesigner = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedScheduledController_1D_Coeff::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("nv", x2String(myReal->nv));
    aomsAttributes->addAttribute("nx", x2String(myReal->nx));
    aomsAttributes->addAttribute("nu", x2String(myReal->nu));
    aomsAttributes->addAttribute("ny", x2String(myReal->ny));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
    aomsAttributes->addAttribute("A", x2String(myReal->A));
    aomsAttributes->addAttribute("B", x2String(myReal->B));
    aomsAttributes->addAttribute("C", x2String(myReal->C));
    aomsAttributes->addAttribute("D", x2String(myReal->D));
    aomsAttributes->addAttribute("v", x2String(myReal->v));
    aomsAttributes->addAttribute("x0", x2String(myReal->x0));
    aomsAttributes->addAttribute("v0", x2String(myReal->v0));
    aomsAttributes->addAttribute("Av", x2String(myReal->Av));
    aomsAttributes->addAttribute("Bv", x2String(myReal->Bv));
    aomsAttributes->addAttribute("Cv", x2String(myReal->Cv));
    aomsAttributes->addAttribute("Dv", x2String(myReal->Dv));
}

void OMAnimatedScheduledController_1D_Coeff::serializeRelations(AOMSRelations*  aomsRelations) const {
}

IMPLEMENT_META(ScheduledController_1D_Coeff, LibraryPkg_AvionicsPkg, FALSE, OMAnimatedScheduledController_1D_Coeff)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\ScheduledController_1D_Coeff.cpp
*********************************************************************/

