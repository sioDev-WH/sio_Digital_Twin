/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilotCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AutoPilotCoeff.h
*********************************************************************/


#ifndef AutoPilotCoeff_H 

#define AutoPilotCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AutopilotPkg.h"

//## package AutopilotPkg 

//----------------------------------------------------------------------------
// AutoPilotCoeff.h                                                                  
//----------------------------------------------------------------------------

//## class AutoPilotCoeff 
class AutoPilotCoeff  {


////    Constructors and destructors    ////
public :
    
    //## operation AutoPilotCoeff() 
    AutoPilotCoeff();
    
    //## operation ~AutoPilotCoeff() 
    ~AutoPilotCoeff();


////    Operations    ////
public :
    
    //## operation idxReSearch(double*,int,double,int*,double*,int*) 
    void idxReSearch(double*  BP_Data, int  nBP, double  u, int*  Index, double*  fraction, int*  bStatus);
    
    //## operation idxSearch(double*,int,double,int*,double*,int*) 
    void idxSearch(double*  BP_Data, int  nBP, double  u, int*  Index, double*  fraction, int*  bStatus);
    
    //## operation init() 
    void init();
    
    //## operation initData() 
    void initData();
    
    //## operation setPeriod(long) 
    void setPeriod(long  val);
    
    //## operation update(double,double) 
    void update(double  alpha, double  Mach);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double* getBP_Alpha() const;
    
    //## auto_generated 
    void setBP_Alpha(double*  p_BP_Alpha);
    
    //## auto_generated 
    double* getBP_Mach() const;
    
    //## auto_generated 
    void setBP_Mach(double*  p_BP_Mach);
    
    //## auto_generated 
    double getFin_max() const;
    
    //## auto_generated 
    void setFin_max(double  p_Fin_max);
    
    //## auto_generated 
    double getFin_min() const;
    
    //## auto_generated 
    void setFin_min(double  p_Fin_min);
    
    //## auto_generated 
    double getK() const;
    
    //## auto_generated 
    void setK(double  p_K);
    
    //## auto_generated 
    double getKacc() const;
    
    //## auto_generated 
    void setKacc(double  p_Kacc);
    
    //## auto_generated 
    double getKaw() const;
    
    //## auto_generated 
    void setKaw(double  p_Kaw);
    
    //## auto_generated 
    double getKg() const;
    
    //## auto_generated 
    void setKg(double  p_Kg);
    
    //## auto_generated 
    double getKi() const;
    
    //## auto_generated 
    void setKi(double  p_Ki);
    
    //## auto_generated 
    int getBReSearch() const;
    
    //## auto_generated 
    void setBReSearch(int  p_bReSearch);
    
    //## auto_generated 
    int getNAlpha() const;
    
    //## auto_generated 
    void setNAlpha(int  p_nAlpha);
    
    //## auto_generated 
    int getNMach() const;
    
    //## auto_generated 
    void setNMach(int  p_nMach);
    
    //## auto_generated 
    long getPeriod() const;
    
    //## auto_generated 
    double* getSchedule_Gain() const;
    
    //## auto_generated 
    void setSchedule_Gain(double*  p_schedule_Gain);
    
    //## auto_generated 
    double* getSchedule_accelGain() const;
    
    //## auto_generated 
    void setSchedule_accelGain(double*  p_schedule_accelGain);
    
    //## auto_generated 
    double* getSchedule_gyroGain() const;
    
    //## auto_generated 
    void setSchedule_gyroGain(double*  p_schedule_gyroGain);
    
    //## auto_generated 
    double* getSchedule_inputGain() const;
    
    //## auto_generated 
    void setSchedule_inputGain(double*  p_schedule_inputGain);


////    Attributes    ////
public :
    
    double Fin_max;		//## attribute Fin_max 
    
    double Fin_min;		//## attribute Fin_min 
    
    double K;		//## attribute K 
    
    double Kacc;		//## attribute Kacc 
    
    double Kaw;		//## attribute Kaw 
    
    double Kg;		//## attribute Kg 
    
    double Ki;		//## attribute Ki 
    
    long period;		//## attribute period 
    
    double* schedule_accelGain;		//## attribute schedule_accelGain 
    
    double* schedule_gyroGain;		//## attribute schedule_gyroGain 
    
protected :
    
    double* BP_Alpha;		//## attribute BP_Alpha 
    
    double* BP_Mach;		//## attribute BP_Mach 
    
    int bReSearch;		//## attribute bReSearch 
    
    int nAlpha;		//## attribute nAlpha 
    
    int nMach;		//## attribute nMach 
    
    double* schedule_Gain;		//## attribute schedule_Gain 
    
    double* schedule_inputGain;		//## attribute schedule_inputGain 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AutoPilotCoeff.h
*********************************************************************/

