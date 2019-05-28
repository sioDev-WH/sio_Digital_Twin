/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilotCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AutoPilotCoeff.cpp
*********************************************************************/

#include "AutoPilotCoeff.h"
#include "ControlDesigner.h"
#include "stdafx.h"

//## package AutopilotPkg 

//----------------------------------------------------------------------------
// AutoPilotCoeff.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AutopilotPkg)
//## class AutoPilotCoeff 



AutoPilotCoeff::AutoPilotCoeff() {
    itsControlDesigner = NULL;
    //#[ operation AutoPilotCoeff() 
    init();
    //#]
}

AutoPilotCoeff::~AutoPilotCoeff() {
    cleanUpRelations();
}

void AutoPilotCoeff::init() {
    //#[ operation init() 
    int i;
    	  period =    10.0;
    	  double Ts = period/1000.0;
    	  gyroGain		=   0.80004035323733;		//  W1
    	  accelGain		=   0.10730904477327;		//  W2
    	  gyroFilterZero	= 10.0;					// -W3
    	  gyroFilterPole	= 1.0;					// -W4
    	  antiAliasGain	= 100.0;
    	  antiAliasPole	= 100.0;
    
    	double Ac[] = 
    	{
    	  -598.085453166210,   369.209491375411,  -121.106890802199,    57.948075458867,	 269.976945154397,
    	  -315.899688024282,    -4.192867915236,    50.725722570884,    -6.871578072800,	 -28.860638284920,
    		59.221396578794,   -49.353371924105,    -2.783858911310,     3.826896181933,	  22.116757056788,
    		29.164144372849,     6.273786159379,     2.812538151917,    -6.937782988899,	 -86.710552427454,
    	   227.425306382867,    16.335089650934,    -0.649907813404,    25.427564045719,	-201.643504492549
    	};
    
    	double Bc[] =
    	{
    	  38.30440185038075,  -6.88831001916390,
    	   0.85064419027237,  -1.99536323864749,
    	   0.09137240455688,  -1.54182853925637,
    	  -0.59256496296877,   0.87785031881590,
    	  -5.03200542667896,   0.56039391707198
    	};
    
    	double Cc[5] =
    	{
    
    	  32.81739226258158,  -1.99751713941653,   1.45614143120027,  -1.05574950614392,  -5.05303086018177
    	};
    
    	double Dc[2] =
    	{
    	  -0.00261138769188,   0.00082860425490
    	};
    
    	nx = 5;
    	nu = 2;
    	ny = 1;
    	A = new double[nx*nx];
    	B = new double[nx*nu];
    	C = new double[ny*nx];
    	D = new double[ny*nu];
    
    	itsControlDesigner = new ControlDesigner;
    	itsControlDesigner->SS_discretize(Ts, nx,nu,Ac,Bc,A,B);
    	delete itsControlDesigner;
    	for(i=0;i<ny*nx;i++)C[i] = Cc[i];
    	for(i=0;i<ny*nu;i++)D[i] = Dc[i];
    
    //#]
}

double* AutoPilotCoeff::getA() const {
    return A;
}

void AutoPilotCoeff::setA(double*  p_A) {
    A = p_A;
}

double* AutoPilotCoeff::getB() const {
    return B;
}

void AutoPilotCoeff::setB(double*  p_B) {
    B = p_B;
}

double* AutoPilotCoeff::getC() const {
    return C;
}

void AutoPilotCoeff::setC(double*  p_C) {
    C = p_C;
}

double *  AutoPilotCoeff::getD() const {
    return D;
}

void AutoPilotCoeff::setD(double * p_D) {
    D = p_D;
}

double AutoPilotCoeff::getAccelGain() const {
    return accelGain;
}

void AutoPilotCoeff::setAccelGain(double  p_accelGain) {
    accelGain = p_accelGain;
}

double AutoPilotCoeff::getAntiAliasGain() const {
    return antiAliasGain;
}

void AutoPilotCoeff::setAntiAliasGain(double  p_antiAliasGain) {
    antiAliasGain = p_antiAliasGain;
}

double AutoPilotCoeff::getAntiAliasPole() const {
    return antiAliasPole;
}

void AutoPilotCoeff::setAntiAliasPole(double  p_antiAliasPole) {
    antiAliasPole = p_antiAliasPole;
}

double AutoPilotCoeff::getGyroFilterPole() const {
    return gyroFilterPole;
}

void AutoPilotCoeff::setGyroFilterPole(double  p_gyroFilterPole) {
    gyroFilterPole = p_gyroFilterPole;
}

double AutoPilotCoeff::getGyroFilterZero() const {
    return gyroFilterZero;
}

void AutoPilotCoeff::setGyroFilterZero(double  p_gyroFilterZero) {
    gyroFilterZero = p_gyroFilterZero;
}

double AutoPilotCoeff::getGyroGain() const {
    return gyroGain;
}

void AutoPilotCoeff::setGyroGain(double  p_gyroGain) {
    gyroGain = p_gyroGain;
}

int AutoPilotCoeff::getNu() const {
    return nu;
}

void AutoPilotCoeff::setNu(int  p_nu) {
    nu = p_nu;
}

int AutoPilotCoeff::getNx() const {
    return nx;
}

void AutoPilotCoeff::setNx(int  p_nx) {
    nx = p_nx;
}

int AutoPilotCoeff::getNy() const {
    return ny;
}

void AutoPilotCoeff::setNy(int  p_ny) {
    ny = p_ny;
}

double AutoPilotCoeff::getPeriod() const {
    return period;
}

void AutoPilotCoeff::setPeriod(double  p_period) {
    period = p_period;
}

ControlDesigner* AutoPilotCoeff::getItsControlDesigner() const {
    return itsControlDesigner;
}

void AutoPilotCoeff::setItsControlDesigner(ControlDesigner*  p_ControlDesigner) {
    itsControlDesigner = p_ControlDesigner;
}

void AutoPilotCoeff::cleanUpRelations() {
    if(itsControlDesigner != NULL)
        {
            itsControlDesigner = NULL;
        }
}



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AutoPilotCoeff.cpp
*********************************************************************/

