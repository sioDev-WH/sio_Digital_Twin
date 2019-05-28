/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilot
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AutoPilot.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "AutoPilot.h"
#include "fstream.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// AutoPilot.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class AutoPilot 


ofstream* ap_fs;

double A[] = 
{
                 0.52725,      0.27836,    -0.082262,     0.044313,      0.17304,
                -0.23582,      0.94585,     0.065422,    -0.014753,    -0.057268,
                 0.052394,    -0.038821,      0.99285,     0.005851,     0.027213,
                 0.013394,    0.0088687,    0.0019418,      0.99258,    -0.076063,
                 0.14993,     0.047107,     -0.01007,     0.027998,      0.83748
};

double B[] =
{
                0.028121,   -0.0052835,
				-0.0040241,   -0.0011257,
				0.0010523,   -0.0016738,
				-4.1362e-005,   0.00078033,
				-0.0012664,  -0.00010584
};

double C[5] =
{

  32.81739226258158,  -1.99751713941653,   1.45614143120027,  -1.05574950614392,  -5.05303086018177
};

double D[2] =
{
  -0.00261138769188,   0.00082860425490
};




AutoPilot::AutoPilot(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    //#[ operation AutoPilot() 
    init();
    //#]
}

AutoPilot::~AutoPilot() {
}

double AutoPilot::getFinControlSignal(double  command, double  gyroData, double  accelData) {
    //#[ operation getFinControlSignal(double,double,double) 
    double Fin=0;
    double x[N],u[M],y;
    
    
    int i,j; 
    
    // WAH
    if(!ap_fs){ ap_fs = new ofstream; ap_fs->open("AutoPilotData.txt");}
    
    // Sensor processing
    // WAH [use fractions of H(s) since Numerator and Denumerator are of same order
    
    u[0] = (1.0 - Coeff.samplingPeriod* Coeff.gyroFilterPole) * old_u[0]
         + Coeff.samplingPeriod*Coeff.gyroFilterZero * Coeff.gyroGain* oldGyroData  
           + Coeff.gyroGain*(gyroData - oldGyroData);
    
    u[1] = old_u[1] + Coeff.samplingPeriod* Coeff.accelGain*(accelData - command);
    
    
    
    // H-infinity Compensator
    
    for(i=0;i<N;i++){
      // x[i] = old_x[i];
      x[i] = 0.0;
      for(j=0;j<N;j++)
    	  // x[i] -= Coeff.samplingPeriod*A[i*N+j]*old_x[j];
    	  x[i] += A[i*N+j]*old_x[j];
      for(j=0;j<M;j++)
    	  // x[i] += Coeff.samplingPeriod*B[i*M+j]*u[j];
    	  x[i] += B[i*M+j]*u[j];
    }
    y = 0.0;
    for(i=0;i<N;i++) y += C[i]*x[i];
    for(j=0;j<M;j++) y += D[j]*u[j];
      
    
    // Anti-aliasing and 1 sample delay
    // WAH Fin = old_Fin + Coeff.samplingPeriod*(Coeff.antiAliasPole * old_Fin
    // WAH	   + Coeff.antiAliasGain * y);
      Fin = old_Fin + Coeff.samplingPeriod*(-Coeff.antiAliasPole * old_Fin
    	   + Coeff.antiAliasGain * y);
    
    // WAH update buffers
    old_u[0] = u[0];
    old_u[1] = u[1];
    oldGyroData = gyroData;
    for(i=0;i<N;i++) old_x[i] = x[i];
    old_Fin = Fin;
    
    // WAH
      *ap_fs << "\t"<< u[0] << "\t" <<  u[1] << "\t"<<  y  << "\t"<<  Fin << "\t";
    *ap_fs << "\t"<< command << "\t" <<  gyroData << "\t" <<  accelData << "\n";
    // Fin = -0.00;
    return Fin;
    //#]
}

void AutoPilot::init() {
    //#[ operation init() 
    long i;
    
      oldGyroData = 0.0;
      for (i = 0; i < N; i++) old_x[i] = 0.0;
      for (i = 0; i < M; i++) old_u[i] = 0.0;
      old_Fin = 0.0;
    //#]
}

void AutoPilot::setOldGyroData(double  p_oldGyroData) {
    oldGyroData = p_oldGyroData;
}

void AutoPilot::setOld_Fin(double  p_old_Fin) {
    old_Fin = p_old_Fin;
}

void AutoPilot::setOld_u(int  i1, double  p_old_u) {
    old_u[i1] = p_old_u;
}

void AutoPilot::setOld_x(int  i1, double  p_old_x) {
    old_x[i1] = p_old_x;
}

AutoPilotCoeff* AutoPilot::getCoeff() const {
    return (AutoPilotCoeff*) &Coeff;
}

OMBoolean AutoPilot::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedAutoPilot::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedAutoPilot::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("Coeff", TRUE, TRUE);
    if((AutoPilotCoeff*) &myReal->Coeff)
        aomsRelations->ADD_ITEM((AutoPilotCoeff*) &myReal->Coeff);
}

IMPLEMENT_REACTIVE_META(AutoPilot, GuidancePkg, FALSE, OMAnimatedAutoPilot)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AutoPilot.cpp
*********************************************************************/

