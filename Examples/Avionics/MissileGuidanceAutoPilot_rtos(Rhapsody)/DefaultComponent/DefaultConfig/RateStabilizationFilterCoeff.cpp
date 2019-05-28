/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: RateStabilizationFilterCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\RateStabilizationFilterCoeff.cpp
*********************************************************************/

#include "RateStabilizationFilterCoeff.h"
#include "ControlDesigner.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// RateStabilizationFilterCoeff.cpp                                                                  
//----------------------------------------------------------------------------
//## class RateStabilizationFilterCoeff 



RateStabilizationFilterCoeff::RateStabilizationFilterCoeff() {
    pDesigner = NULL;
    //#[ operation RateStabilizationFilterCoeff() 
    init();
    //#]
}

RateStabilizationFilterCoeff::~RateStabilizationFilterCoeff() {
    cleanUpRelations();
}

void RateStabilizationFilterCoeff::clean() {
    //#[ operation clean() 
    //#]
}

void RateStabilizationFilterCoeff::init() {
    //#[ operation init() 
    nx = 2;
    nu = 1;
    ny = 1;
    
    A = NULL; 
    B = NULL;
    C = NULL; 
    D = NULL;
    
    //#]
}

void RateStabilizationFilterCoeff::initData() {
    //#[ operation initData() 
    
    int i;
    
    
    double Ts  =    period/1000.0;
    gyroBandwidth		=   100.0*2*PI;		//  Wgyro
    gyroDamping		  =   0.7;		      //  zeta
    double Ac[] = 
    			{
    			  0,              1,
    			  -3.9478E+5,     -879.65
    			};
    
    double Bc[] =
    			{
    			  0, 3.9478E+5
    			};
    
    double Cc[] =
    			{
    
    			  1.0, 0.0
    			};
    
    double Dc[] =
    			{
    			  0
    			};
    if(!A)
    	A = new double[nx*nx]; 
    if(!B)
    	B = new double[nx*nu];
    if(!C)
    	C = new double[ny*nx]; 
    if(!D)
    	D = new double[ny*nu];
    
    ControlDesigner* pDesigner = new ControlDesigner;
    pDesigner->SS_discretize(Ts, nx,nu,Ac,Bc,A,B);
    delete pDesigner;
    for(i=0;i<ny*nx;i++)C[i] = Cc[i];
    for(i=0;i<ny*nu;i++)D[i] = Dc[i];
    //#]
}

void RateStabilizationFilterCoeff::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    period = val;
    //#]
}

double *  RateStabilizationFilterCoeff::getA() const {
    return A;
}

void RateStabilizationFilterCoeff::setA(double * p_A) {
    A = p_A;
}

double *  RateStabilizationFilterCoeff::getB() const {
    return B;
}

void RateStabilizationFilterCoeff::setB(double * p_B) {
    B = p_B;
}

double *  RateStabilizationFilterCoeff::getC() const {
    return C;
}

void RateStabilizationFilterCoeff::setC(double * p_C) {
    C = p_C;
}

double *  RateStabilizationFilterCoeff::getD() const {
    return D;
}

void RateStabilizationFilterCoeff::setD(double * p_D) {
    D = p_D;
}

double RateStabilizationFilterCoeff::getGyroBandwidth() const {
    return gyroBandwidth;
}

void RateStabilizationFilterCoeff::setGyroBandwidth(double  p_gyroBandwidth) {
    gyroBandwidth = p_gyroBandwidth;
}

double RateStabilizationFilterCoeff::getGyroDamping() const {
    return gyroDamping;
}

void RateStabilizationFilterCoeff::setGyroDamping(double  p_gyroDamping) {
    gyroDamping = p_gyroDamping;
}

int RateStabilizationFilterCoeff::getNu() const {
    return nu;
}

void RateStabilizationFilterCoeff::setNu(int  p_nu) {
    nu = p_nu;
}

int RateStabilizationFilterCoeff::getNx() const {
    return nx;
}

void RateStabilizationFilterCoeff::setNx(int  p_nx) {
    nx = p_nx;
}

int RateStabilizationFilterCoeff::getNy() const {
    return ny;
}

void RateStabilizationFilterCoeff::setNy(int  p_ny) {
    ny = p_ny;
}

long RateStabilizationFilterCoeff::getPeriod() const {
    return period;
}

ControlDesigner* RateStabilizationFilterCoeff::getPDesigner() const {
    return pDesigner;
}

void RateStabilizationFilterCoeff::setPDesigner(ControlDesigner*  p_ControlDesigner) {
    pDesigner = p_ControlDesigner;
}

void RateStabilizationFilterCoeff::cleanUpRelations() {
    if(pDesigner != NULL)
        {
            pDesigner = NULL;
        }
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RateStabilizationFilterCoeff.cpp
*********************************************************************/

