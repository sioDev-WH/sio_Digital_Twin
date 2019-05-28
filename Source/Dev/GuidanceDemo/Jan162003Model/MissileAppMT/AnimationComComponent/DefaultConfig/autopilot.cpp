/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilot
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AutoPilot.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "AutoPilot.h"
#include "AutoPilotCoeff.h"
#include "stdafx.h"
#include "math.h"
#include "fstream.h"

//## package AutopilotPkg 


//#[ ignore 
#define AutopilotPkg_AutoPilot_AutoPilot_SERIALIZE OM_NO_OP


#define AutopilotPkg_AutoPilot_clean_SERIALIZE OM_NO_OP


#define AutopilotPkg_AutoPilot_computeFinControlSignal_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define AutopilotPkg_AutoPilot_get_Fin_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define AutopilotPkg_AutoPilot_handle_tick_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define AutopilotPkg_AutoPilot_init_SERIALIZE OM_NO_OP


#define AutopilotPkg_AutoPilot_set_accelData_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define AutopilotPkg_AutoPilot_set_command_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define AutopilotPkg_AutoPilot_set_gyroData_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));
//#]

//----------------------------------------------------------------------------
// AutoPilot.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AutopilotPkg)
//## class AutoPilot 


ofstream* ap_fs;


AutoPilot::AutoPilot() {
    NOTIFY_CONSTRUCTOR(AutoPilot, AutoPilot(), 0, AutopilotPkg_AutoPilot_AutoPilot_SERIALIZE);
    Coeff = NULL;
    //#[ operation AutoPilot() 
    init();
    //#]
}

AutoPilot::~AutoPilot() {
    NOTIFY_DESTRUCTOR(~AutoPilot, TRUE);
    cleanUpRelations();
}

void AutoPilot::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, AutopilotPkg_AutoPilot_clean_SERIALIZE);
    //#[ operation clean() 
    //#]
}

void AutoPilot::computeFinControlSignal(const double  t) {
    NOTIFY_OPERATION(computeFinControlSignal, computeFinControlSignal(const double), 1, AutopilotPkg_AutoPilot_computeFinControlSignal_SERIALIZE);
    //#[ operation computeFinControlSignal(const double) 
    
      double y;
      double *A,*B,*C,*D;
      int nx = Coeff->nx;
      int nu = Coeff->nu;
      
     
      A = Coeff->A;
      B = Coeff->B;
      C = Coeff->C;
      D = Coeff->D;
      
      int i,j;
      double Ts = Coeff->period/1000.0;
      double pole = Coeff->gyroFilterPole;
      double zero = Coeff->gyroFilterZero; 
      double gain1 = Coeff->gyroGain;
      double gain2 = Coeff->accelGain;
      
    
      // WAH
       if(!ap_fs){ 
          ap_fs = new ofstream; ap_fs->open("AutoPilotData.txt");
          *ap_fs <<  "Time" << "\t" <<  "Fin" << "\t" <<  "pitch rate" << "\t" ;
          *ap_fs <<  "Az Demand" << "\t" <<  "Az" << "\n";
       }
    
      // Sensor processing
      // WAH [use fractions of H(s) since Numerator and Denumerator are of same order
    
      u[0] = (1.0 - Ts * pole) * old_u[0]
    	    + gain1 * (Ts * zero - 1.0) * oldGyroData  
            + gain1 * gyroData;
      
      u[1] = old_u[1] + Ts * gain2 *(accelData - command);
    
    
    
      // H-infinity Compensator
      for(i=0;i<nx;i++){
    	  x[i] = 0.0;
    	  for(j=0;j<nx;j++)
    		  x[i] += A[i*nx+j]*old_x[j];
    	  for(j=0;j<nu;j++)
    		  x[i] += B[i*nu+j]*u[j];
      }
      y = 0.0;
      for(i=0;i<nx;i++) y += C[i]*x[i];
      for(j=0;j<nu;j++) y += D[j]*u[j];
    	  
    
      // Anti-aliasing and 1 sample delay
      //  Fin = (1.0 - Coeff.samplingPeriod*Coeff.antiAliasPole) * old_Fin
    //		   + Coeff.samplingPeriod*Coeff.antiAliasGain * y;
    	double Ad = exp(- Ts * Coeff->antiAliasPole);
    	double Bd = (1 - Ad)*Coeff->antiAliasGain/Coeff->antiAliasPole;
          Fin = Ad * old_Fin + Bd * y;
        
        if(Fin > 30*d2r) Fin = 30*d2r;
        if (Fin < -30*d2r) Fin = -30*d2r; 
        
      // WAH update buffers
      old_u[0] = u[0];
      old_u[1] = u[1];
      oldGyroData = gyroData;
      for(i=0;i<nx;i++) old_x[i] = x[i];
      old_Fin = Fin;
    
      // WAH
       // *ap_fs <<itsGlobalData->get_t()  << "\t"<<  Fin << "\t" <<  gyroData << "\t"; 
       *ap_fs << t  << "\t"<<  Fin << "\t" <<  gyroData << "\t";
       *ap_fs << command/9.81 << "\t"  <<  accelData/9.81 << "\n";
    
    //#]
}

void AutoPilot::get_Fin(const double  t, double *val) {
    NOTIFY_OPERATION(get_Fin, get_Fin(const double,double *), 2, AutopilotPkg_AutoPilot_get_Fin_SERIALIZE);
    //#[ operation get_Fin(const double,double *) 
    
    *val = Fin; 
    //#]
}

void AutoPilot::handle_tick(const double  t) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double), 1, AutopilotPkg_AutoPilot_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double) 
    receive();
    
    computeFinControlSignal(t);
    
    broadcast(t);
    
    //#]
}

void AutoPilot::init() {
    NOTIFY_OPERATION(init, init(), 0, AutopilotPkg_AutoPilot_init_SERIALIZE);
    //#[ operation init() 
    	long i;
    	int nx;
    	int nu;
    	Coeff = new AutoPilotCoeff();
    	nx = Coeff->nx;
    	nu = Coeff->nu;
    	oldGyroData = 0.0;
    	x = new double[nx]; // Destroy
    	u = new double[nu];
    	old_x = new double[nx];
    	old_u = new double[nu];
    	for (i = 0; i < nx; i++) old_x[i] = 0.0;
    	for (i = 0; i < nu; i++) old_u[i] = 0.0;
    	old_Fin = 0.0; 
    	command = 0.0;
    	gyroData = 0.0;
    	accelData = 0.0;
    //#]
}

void AutoPilot::set_accelData(const double  t, double *val) {
    NOTIFY_OPERATION(set_accelData, set_accelData(const double,double *), 2, AutopilotPkg_AutoPilot_set_accelData_SERIALIZE);
    //#[ operation set_accelData(const double,double *) 
    
    accelData  = *val; 
    //#]
}

void AutoPilot::set_command(const double  t, double *val) {
    NOTIFY_OPERATION(set_command, set_command(const double,double *), 2, AutopilotPkg_AutoPilot_set_command_SERIALIZE);
    //#[ operation set_command(const double,double *) 
    
    command  = *val; 
    //#]
}

void AutoPilot::set_gyroData(const double  t, double *val) {
    NOTIFY_OPERATION(set_gyroData, set_gyroData(const double,double *), 2, AutopilotPkg_AutoPilot_set_gyroData_SERIALIZE);
    //#[ operation set_gyroData(const double,double *) 
    
    gyroData  = *val; 
    //#]
}

double AutoPilot::getFin() const {
    return Fin;
}

void AutoPilot::setFin(double  p_Fin) {
    Fin = p_Fin;
}

double AutoPilot::getAccelData() const {
    return accelData;
}

void AutoPilot::setAccelData(double  p_accelData) {
    accelData = p_accelData;
}

double AutoPilot::getCommand() const {
    return command;
}

void AutoPilot::setCommand(double  p_command) {
    command = p_command;
}

double AutoPilot::getGyroData() const {
    return gyroData;
}

void AutoPilot::setGyroData(double  p_gyroData) {
    gyroData = p_gyroData;
}

double AutoPilot::getOldGyroData() const {
    return oldGyroData;
}

void AutoPilot::setOldGyroData(double  p_oldGyroData) {
    oldGyroData = p_oldGyroData;
}

double AutoPilot::getOld_Fin() const {
    return old_Fin;
}

void AutoPilot::setOld_Fin(double  p_old_Fin) {
    old_Fin = p_old_Fin;
}

double* AutoPilot::getOld_u() const {
    return old_u;
}

void AutoPilot::setOld_u(double*  p_old_u) {
    old_u = p_old_u;
}

double* AutoPilot::getOld_x() const {
    return old_x;
}

void AutoPilot::setOld_x(double*  p_old_x) {
    old_x = p_old_x;
}

double* AutoPilot::getU() const {
    return u;
}

void AutoPilot::setU(double*  p_u) {
    u = p_u;
}

double* AutoPilot::getX() const {
    return x;
}

void AutoPilot::setX(double*  p_x) {
    x = p_x;
}

AutoPilotCoeff* AutoPilot::getCoeff() const {
    return Coeff;
}

void AutoPilot::setCoeff(AutoPilotCoeff*  p_AutoPilotCoeff) {
    Coeff = p_AutoPilotCoeff;
}

void AutoPilot::cleanUpRelations() {
    if(Coeff != NULL)
        {
            Coeff = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedAutoPilot::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedAutoPilot::serializeRelations(AOMSRelations*  aomsRelations) const {
}

IMPLEMENT_META(AutoPilot, AutopilotPkg, FALSE, OMAnimatedAutoPilot)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AutoPilot.cpp
*********************************************************************/

