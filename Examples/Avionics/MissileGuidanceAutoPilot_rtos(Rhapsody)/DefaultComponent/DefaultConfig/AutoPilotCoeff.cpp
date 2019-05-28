/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilotCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AutoPilotCoeff.cpp
*********************************************************************/

#include "AutoPilotCoeff.h"
#include "stdafx.h"
#include "math.h"

//## package AutopilotPkg 

//----------------------------------------------------------------------------
// AutoPilotCoeff.cpp                                                                  
//----------------------------------------------------------------------------
//## class AutoPilotCoeff 



AutoPilotCoeff::AutoPilotCoeff() {
    //#[ operation AutoPilotCoeff() 
    init();
    //#]
}

AutoPilotCoeff::~AutoPilotCoeff() {
    //#[ operation ~AutoPilotCoeff() 
    delete[] schedule_accelGain;
    delete[] schedule_inputGain;
    delete[] schedule_gyroGain;
    delete[] BP_Alpha;
    delete[] BP_Mach;
    //#]
}

void AutoPilotCoeff::idxReSearch(double*  BP_Data, int  nBP, double  u, int*  Index, double*  fraction, int*  bStatus) {
    //#[ operation idxReSearch(double*,int,double,int*,double*,int*) 
    
    // Same as idxSearch, except that *Index is in/out initial guess (often from previous calls) to speedup the search.
    // void idxReSearch(double BP_Data[],  int n, double u,  int *Index, double *fraction, int *bStatus)
    
    	int M_index,U_index,inc;
    	int bAscending;
    	int n = nBP;
    
    	*bStatus = 0;
    
    	bAscending=(BP_Data[n-1] > BP_Data[0]);
    
    	if(u > BP_Data[n-1] == bAscending){
    		*Index =n-1; 
    		*fraction=1.0;
    		*bStatus = 1;
    		return;
    	}
    	if(u < BP_Data[0] == bAscending){
    		*Index =0;
    		*fraction=0.0;
    		*bStatus = -1;
    		return;
    	}
    
    	
    	if (*Index < 0 || *Index > n-1) {
    		*Index=-1;
    		U_index=n;
    	} 
    	else {
    		inc=1;
    		if (u >= BP_Data[*Index] == bAscending) {
    			if (*Index == n-1){
    				*bStatus = 1;
    				*fraction = 1.0;
    				return;
    			}
    			U_index=(*Index)+1;
    			while (u >= BP_Data[U_index] == bAscending) {
    				*Index=U_index;
    				inc += inc;
    				U_index=(*Index)+inc;
    				if (U_index > n-1) {
    					U_index=n;
    					break;
    				}
    			}
    		} 
    		else {
    			if (*Index == 0) {
    				*Index=-1;
    				return;
    			}
    			U_index=(*Index)--;
    			while (u < BP_Data[*Index] == bAscending) {
    				U_index=(*Index);
    				inc <<= 1;
    				if (inc >= U_index) {
    					*Index=-1;
    					break;
    				}
    				else *Index=U_index-inc;
    			}
    		}
    	}
    	while (U_index-(*Index) != 1) {
    		M_index=(U_index+(*Index)) >> 1;
    		if (u > BP_Data[M_index] == bAscending)
    			*Index=M_index;
    		else
    			U_index=M_index;
    	}
    
    	if((u == BP_Data[0]) == bAscending) *Index=0;
    	if(fabs(BP_Data[*Index+1]-BP_Data[*Index])>1e-12) *fraction = (u-BP_Data[*Index])/(BP_Data[*Index+1]-BP_Data[*Index]);
    	else *fraction =  (u-BP_Data[*Index])/(1e-12 + BP_Data[*Index+1]-BP_Data[*Index]);
    
    
    //#]
}

void AutoPilotCoeff::idxSearch(double*  BP_Data, int  nBP, double  u, int*  Index, double*  fraction, int*  bStatus) {
    //#[ operation idxSearch(double*,int,double,int*,double*,int*) 
    // void idxSearch(double BP_Data[],  int n, double u,  int *Index, double *fraction, int *bStatus)
    // {
    	int U_index,M_index,L_index;
    	bool bAscending;  
    	int n = nBP;
    
    	*bStatus = 0;
    	L_index=-1;
    	U_index=n;
    	bAscending= (bool)(BP_Data[n-1] > BP_Data[0]);
    
    	if(u > BP_Data[n-1] == bAscending){
    		*Index =n-1; 
    		*fraction=1.0;
    		*bStatus = 1;
    		return;
    	}
    	if(u < BP_Data[0] == bAscending){
    		*Index =0;
    		*fraction = 0.0;
    		*bStatus = -1;
    		return;
    	}
    
    	while (U_index-L_index > 1) {
    		M_index=(U_index+L_index) >> 1;
    		if (u > BP_Data[M_index] == bAscending)
    			L_index=M_index;
    		else
    			U_index=M_index;
    	}
    	if((u == BP_Data[0]) == bAscending) *Index=0;
    	else *Index=L_index;
    	if(fabs(BP_Data[*Index+1]-BP_Data[*Index])>1e-12) *fraction = (u-BP_Data[*Index])/(BP_Data[*Index+1]-BP_Data[*Index]);
    	else *fraction =  (u-BP_Data[*Index])/(1e-12 + BP_Data[*Index+1]-BP_Data[*Index]);
    
    // }
    
    //#]
}

void AutoPilotCoeff::init() {
    //#[ operation init() 
    bReSearch=0; 
    
        
    schedule_accelGain=NULL;
    schedule_inputGain=NULL;
    schedule_gyroGain=NULL;
    schedule_Gain=NULL;
    BP_Alpha=NULL;
    BP_Mach=NULL;
    initData();
    
    
    
    //#]
}

void AutoPilotCoeff::initData() {
    //#[ operation initData() 
    	double _accelGain[] = 
    	{
    	  	0.94124,	0.93886,	0.93521,	0.93213,	0.92734,	0.92171,
    		0.93637,	0.93359,	0.93004,	0.92655,	0.92030,	0.91417,
    		0.93156,	0.92895,	0.92496,	0.92041,	0.91367,	0.90709,
    		0.92691,	0.92392,	0.92007,	0.91464,	0.90746,	0.90047,
    		0.92195,	0.91912,	0.91483,	0.90923,	0.90164,	0.89429,
    		0.91726,	0.91404,	0.90988,	0.90418,	0.89620,	0.88852,
    		0.91305,	0.90925,	0.90467,	0.89947,	0.89112,	0.88314,
    		0.90839,	0.90474,	0.89978,	0.89466,	0.88638,	0.87812,
    		0.90398,	0.90049,	0.89519,	0.89028,	0.88197,	0.87347
    	};
    	
    	double _gyroGain[] = 
    	{
    	  	0.85026,	0.8430,		0.83498,	0.82901,	0.82515,	0.82338,
    		0.66882,	0.66155,	0.65353,	0.64755,	0.64369,	0.64191,
    		0.53969,	0.53242,	0.52439,	0.5184,		0.51453,	0.51275,
    		0.44476,	0.43748,	0.42943,	0.42344,	0.41956,	0.41777,
    		0.37312,	0.36583,	0.35777,	0.35176,	0.34788,	0.34608,
    		0.31788,	0.31058,	0.30251,	0.2965,		0.2926,		0.29079,
    		0.27393,	0.26723,	0.25915,	0.25312,	0.24922,	0.2474,
    		0.23943,	0.23272,	0.22462,	0.21858,	0.21467,	0.21285,
    		0.21164,	0.2049,		0.19679,	0.19074,	0.18682,	0.18499
    	}; 
    	
    	double _inputGain[] = 
    	{
    		22.522,	22.709,	22.925,	23.092,	23.209,	23.271,
    		26.109,	26.379,	26.69,	26.932,	27.099,	27.185,
    		30.126,	30.507,	30.948,	31.293,	31.531,	31.651,
    		34.562,	35.091,	35.708,	36.191,	36.52,	36.688,
    		39.4,	40.121,	40.965,	41.629,	42.083,	42.31,
    		44.614,	45.577,	46.71,	47.609,	48.223,	48.529,
    		50.527,	51.431,	52.928,	54.123,	54.941,	55.347,
    		56.413,	57.646,	59.589,	61.149,	62.222,	62.754,
    		62.543,	64.172,	66.65,	68.654,	70.041,	70.727
    	};
    
    
    
    	double _Gain[] = 
    	{
    	  	0.025875,	0.024929,	0.023697,	0.022902,	0.021767,	0.020666,
    		0.02124,	0.020401,	0.019506,	0.018812,	0.01764,	0.016757,
    		0.017772,	0.017161,	0.016368,	0.015623,	0.014657,	0.013932,
    		0.015129,	0.014569,	0.01397,	0.013243,	0.01243,	0.011823,
    		0.012987,	0.012563,	0.012018,	0.011416,	0.01072,	0.010204,
    		0.011307,	0.010911,	0.010484,	0.0099827,	0.0093773,	0.0089312,
    		0.0099923,	0.0095967,	0.0092032,	0.0088348,	0.0083011,	0.0079114,
    		0.008851,	0.0085331,	0.0081704,	0.0078695,	0.0074244,	0.0070803,
    		0.0079166,	0.0076584,	0.0073244,	0.0070834,	0.0067001,	0.0063934
    	};
    	
    	// Columns
    	double _BP_Alpha[] = {0,	0.069813,	0.13963,	0.20944,	0.27925,	0.34907}; 
    	// Rows
        double _BP_Mach[]  = {2,	2.25,		2.5,		2.75,		3,			3.25,		3.5,		3.75,		4};
    
     long i,size;
      
     nMach = sizeof(_BP_Mach)/sizeof(_BP_Mach[0]);
     nAlpha = sizeof(_BP_Alpha)/sizeof(_BP_Alpha[0]); 
     size = nMach*nAlpha;
     
     if(!schedule_accelGain)
        schedule_accelGain = new double[size];
     for (i = 0; i < size; i++) schedule_accelGain[i] = _accelGain[i]; 
     if(!schedule_inputGain)
     schedule_inputGain = new double[size];
     for (i = 0; i < size; i++) schedule_inputGain[i] = _inputGain[i];
     if(!schedule_gyroGain)
     schedule_gyroGain = new double[size];
     for (i = 0; i < size; i++) schedule_gyroGain[i] = _gyroGain[i];
     if(!schedule_Gain)
    schedule_Gain = new double[size];
     for (i = 0; i < size; i++) schedule_Gain[i] = _Gain[i];
     if(!BP_Alpha)
     BP_Alpha = new double[size];
     for (i = 0; i < size; i++) BP_Alpha[i] = _BP_Alpha[i];
     if(!BP_Mach)
     BP_Mach = new double[sizeof(_BP_Mach)];
     for (i = 0; i < size; i++) BP_Mach[i] = _BP_Mach[i];
    
     
     Kaw = 500.0;
     Fin_min = -30.0*d2r;
     Fin_max = 30.0*d2r;
     
     
    
     
    //#]
}

void AutoPilotCoeff::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    
    
    period = val;
    initData(); // Initialize coeff using the new period.
      
    
    
    //#]
}

void AutoPilotCoeff::update(double  alpha, double  Mach) {
    //#[ operation update(double,double) 
    #define INTERPOLATE\
           (1-lambda[1])*(\
              (1-lambda[0])*pData[leftTop]+\
                 lambda[0] *pData[leftBottom])\
           +  lambda[1] *(\
              (1-lambda[0])*pData[rightTop]+\
                 lambda[0] *pData[rightBottom])\
    
    int i,j;
    double lambda[2], *pData;
    int Index[2], bStatus[2];            
    int leftTop, leftBottom , rightTop , rightBottom;
    
    if(bReSearch==0){
       idxSearch(BP_Mach,nMach,Mach,&Index[0],&lambda[0],&bStatus[0]);
       idxSearch(BP_Alpha,nAlpha,alpha,&Index[1],&lambda[1],&bStatus[1]);   
       bReSearch = 1;
    }
    else{
       idxReSearch(BP_Mach,nMach,Mach,&Index[0],&lambda[0],&bStatus[0]);
       idxReSearch(BP_Alpha,nAlpha,alpha,&Index[1],&lambda[1],&bStatus[1]);   
    } 
    i = Index[0];
    j = Index[1];
    
    
    
    leftTop		=i*nAlpha+j; 
    leftBottom	=(i+1)*nAlpha+j;
    rightTop	=i*nAlpha+j+1;
    rightBottom = (i+1)*nAlpha+j+1;
    
    pData 		= schedule_accelGain;
    Kacc = INTERPOLATE;
    
    pData = schedule_inputGain;
    Ki = INTERPOLATE;
     
    pData = schedule_gyroGain;
    Kg = INTERPOLATE; 
    
    pData = schedule_Gain;
    K = INTERPOLATE;
    //#]
}

double* AutoPilotCoeff::getBP_Alpha() const {
    return BP_Alpha;
}

void AutoPilotCoeff::setBP_Alpha(double*  p_BP_Alpha) {
    BP_Alpha = p_BP_Alpha;
}

double* AutoPilotCoeff::getBP_Mach() const {
    return BP_Mach;
}

void AutoPilotCoeff::setBP_Mach(double*  p_BP_Mach) {
    BP_Mach = p_BP_Mach;
}

double AutoPilotCoeff::getFin_max() const {
    return Fin_max;
}

void AutoPilotCoeff::setFin_max(double  p_Fin_max) {
    Fin_max = p_Fin_max;
}

double AutoPilotCoeff::getFin_min() const {
    return Fin_min;
}

void AutoPilotCoeff::setFin_min(double  p_Fin_min) {
    Fin_min = p_Fin_min;
}

double AutoPilotCoeff::getK() const {
    return K;
}

void AutoPilotCoeff::setK(double  p_K) {
    K = p_K;
}

double AutoPilotCoeff::getKacc() const {
    return Kacc;
}

void AutoPilotCoeff::setKacc(double  p_Kacc) {
    Kacc = p_Kacc;
}

double AutoPilotCoeff::getKaw() const {
    return Kaw;
}

void AutoPilotCoeff::setKaw(double  p_Kaw) {
    Kaw = p_Kaw;
}

double AutoPilotCoeff::getKg() const {
    return Kg;
}

void AutoPilotCoeff::setKg(double  p_Kg) {
    Kg = p_Kg;
}

double AutoPilotCoeff::getKi() const {
    return Ki;
}

void AutoPilotCoeff::setKi(double  p_Ki) {
    Ki = p_Ki;
}

int AutoPilotCoeff::getBReSearch() const {
    return bReSearch;
}

void AutoPilotCoeff::setBReSearch(int  p_bReSearch) {
    bReSearch = p_bReSearch;
}

int AutoPilotCoeff::getNAlpha() const {
    return nAlpha;
}

void AutoPilotCoeff::setNAlpha(int  p_nAlpha) {
    nAlpha = p_nAlpha;
}

int AutoPilotCoeff::getNMach() const {
    return nMach;
}

void AutoPilotCoeff::setNMach(int  p_nMach) {
    nMach = p_nMach;
}

long AutoPilotCoeff::getPeriod() const {
    return period;
}

double* AutoPilotCoeff::getSchedule_Gain() const {
    return schedule_Gain;
}

void AutoPilotCoeff::setSchedule_Gain(double*  p_schedule_Gain) {
    schedule_Gain = p_schedule_Gain;
}

double* AutoPilotCoeff::getSchedule_accelGain() const {
    return schedule_accelGain;
}

void AutoPilotCoeff::setSchedule_accelGain(double*  p_schedule_accelGain) {
    schedule_accelGain = p_schedule_accelGain;
}

double* AutoPilotCoeff::getSchedule_gyroGain() const {
    return schedule_gyroGain;
}

void AutoPilotCoeff::setSchedule_gyroGain(double*  p_schedule_gyroGain) {
    schedule_gyroGain = p_schedule_gyroGain;
}

double* AutoPilotCoeff::getSchedule_inputGain() const {
    return schedule_inputGain;
}

void AutoPilotCoeff::setSchedule_inputGain(double*  p_schedule_inputGain) {
    schedule_inputGain = p_schedule_inputGain;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AutoPilotCoeff.cpp
*********************************************************************/

