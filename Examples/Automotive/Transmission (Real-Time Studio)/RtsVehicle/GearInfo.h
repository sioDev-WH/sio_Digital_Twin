#ifndef __GEARINFO_H
#define __GEARINFO_H

//{{SCG_HEADER(GearInfo.h) [0]

//{{SCG_INCLUDE                     

//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class GearInfo 
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        long ID;     
        bool* ClutchState;     
    public:
        GearInfo();
        ~GearInfo();
        void init(const long GearID, const long nClutches, const long nEngaed, const long* Engaged);             
        void clean();             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










