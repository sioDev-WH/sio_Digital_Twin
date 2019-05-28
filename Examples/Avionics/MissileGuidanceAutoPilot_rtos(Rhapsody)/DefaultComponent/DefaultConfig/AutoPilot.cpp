/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilot
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AutoPilot.cpp
*********************************************************************/

#include "AutoPilot.h"
#include "AutoPilotCoeff.h"
#include "stdafx.h"
#include "math.h"
#include "fstream.h"

//## package AutopilotPkg 

//----------------------------------------------------------------------------
// AutoPilot.cpp                                                                  
//----------------------------------------------------------------------------
//## class AutoPilot 


ofstream* ap_fs;


AutoPilot::AutoPilot() {
    Coeff = NULL;
    //#[ operation AutoPilot() 
    init();
    //#]
}

AutoPilot::~AutoPilot() {
    cleanUpRelations();
}

void AutoPilot::clean() {
    //#[ operation clean() 
    	if(Coeff) delete Coeff; 
    
    //#]
}

void AutoPilot::computeFinControlSignal() {
    //#[ operation computeFinControlSignal() 
          double error, x_old;
         
          x_old = *x;
        
          double Ts;
          double Ki;
          double Kacc ; 
          double Kg;
          double K ;  
          double Kaw;
          double Fin_max; 
          double Fin_min;
    	  double time;
     
    	  
          if(!ap_fs){ 
              ap_fs = new ofstream; ap_fs->open("AutoPilotData.txt");
              *ap_fs <<  "Time" << "\t" <<  "Fin" << "\t" <<  "pitch rate" << "\t" ;
    		  *ap_fs << "Ki" << "\t"  <<  "Kacc" << "\t"<< " Kg" << "\t"  <<  "K" << "\t"; 
              *ap_fs <<  "Az Demand" << "\t" <<  "Az" << "\n";
           }
    
    	  Ts = Coeff->period/1000.0;
    	  Fin_max = Coeff->Fin_max; 
          Fin_min = Coeff->Fin_min;
          Coeff->update(Alpha,Mach);
          Ki = Coeff->Ki;
          Kacc = Coeff->Kacc; 
          Kg = Coeff->Kg;
    	  K = Coeff->K;
    	  Kaw = Coeff->Kaw;
    
    	  
          
          error = (command - Kacc*accelData);
          // *x = x_old + Ts*(Ki*(K*error+ gyroData)-Kaw*(y-Fin));
    
    	  // *x = x_old + Ts*(Ki*(K*error+ gyroData)-Kaw*(Kg*gyroData-Fin));
    	  // *x /= (1+Ts*Kaw*Kg);
    
    	  *x = x_old + Ts*Ki*(K*error+ gyroData);
    	  y=Kg*(*x+gyroData);
    
        if(y<Fin_max)
          	if(y>Fin_min)
          		Fin=y;		
    		else{
          	    Fin=Fin_min;
    			*x = Fin_min/Kg - gyroData;
    		}
    		else{
    			Fin = Fin_max;
    			*x = Fin_max/Kg - gyroData;
    		}
    
    	  
    	  // *x -= Ts*Kaw*(y-Fin); // Anit-Windup to overcome saturation
          
           time = getTime();
           *ap_fs << getTime()  << "\t"<<  Fin << "\t" <<  gyroData << "\t";
           *ap_fs << Ki << "\t"  <<  Kacc << "\t"<< Kg << "\t"  <<  K << "\t";
           *ap_fs << command/9.81 << "\t"  <<  accelData/9.81 << "\n";
    
    //#]
}

void AutoPilot::handle_tick() {
    //#[ operation handle_tick() 
    receive();
    
    computeFinControlSignal();
    
    broadcast();
    
    //#]
}

void AutoPilot::init() {
    //#[ operation init() 
    	Coeff = new AutoPilotCoeff();
      x = new double[1];
      *x=0.0;
      Fin=0.0;
    	command = 0.0;
    	gyroData = 0.0;
    	accelData = 0.0;   
    	y = 0.0;
    	Alpha = 0.0; // WAH20030409  0.20944; // 0.0;  // From Ports
    	Mach = 3.0; // 0.0;  // From Ports
    //#]
}

void AutoPilot::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    if(Coeff)
       Coeff->setPeriod(val);
    //#]
}

double AutoPilot::getAlpha() const {
    return Alpha;
}

void AutoPilot::setAlpha(double  p_Alpha) {
    Alpha = p_Alpha;
}

double AutoPilot::getFin() const {
    return Fin;
}

void AutoPilot::setFin(double  p_Fin) {
    Fin = p_Fin;
}

double AutoPilot::getMach() const {
    return Mach;
}

void AutoPilot::setMach(double  p_Mach) {
    Mach = p_Mach;
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

double* AutoPilot::getX() const {
    return x;
}

void AutoPilot::setX(double*  p_x) {
    x = p_x;
}

double AutoPilot::getY() const {
    return y;
}

void AutoPilot::setY(double  p_y) {
    y = p_y;
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



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AutoPilot.cpp
*********************************************************************/

