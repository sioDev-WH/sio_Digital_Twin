#ifndef __CLUTCH_SCHEDULE_H
#define __CLUTCH_SCHEDULE_H


class GearInfo;
struct IOnEnv;

//{{SCG_HEADER(Clutch_Schedule.h) [0]

//{{SCG_INCLUDE                     

//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class Clutch_Schedule 
                  
//}}SCG_CLASS_INFO
{
public:
  Clutch_Schedule();

    //{{SCG_CLASS_PROPS(0)
    public:
        long nGears;     
        long nClutches;     
        bool* engageList;     
        GearInfo* Gears;     
        bool* disengageList;     
    public:
        void init();             
        void clean();             
        void update(const long CurrentGear, const long NextGear);  
        
    protected:
      IOnEnv* m_pOnEnv;
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










