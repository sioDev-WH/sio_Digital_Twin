#ifndef __SHIFTDATA_H
#define __SHIFTDATA_H


// Cg_Add
#include "LookupTable.h"
class Clutch_Schedule;
struct IOnEnv;



//{{SCG_HEADER(ShiftData.h) [0]

//{{SCG_INCLUDE                     

//}}SCG_INCLUDE

//{{SCG_FORWARD                    
//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class ShiftData 
                  
//}}SCG_CLASS_INFO
{
public:

    //{{SCG_CLASS_PROPS(0)
    public:
        LookupTable upShiftTable;     
        LookupTable downShiftTable;     
        Clutch_Schedule* clutchSchedule;    
        IOnEnv* m_pOnEnv;

    public:
      ShiftData();
      ~ShiftData();
        void init();             
        void getUpShiftThreshold(const double throttle, const long gear, double *threshold);             
        void getDownShiftThreshold(const double throttle, const long gear, double *threshold);             
        void clean();             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










