#ifndef __THROTTLE_H
#define __THROTTLE_H

#include "shiftLogic.h"

class CThrottleDlg;

//{{SCG_HEADER(Throttle.h) [0]

//{{SCG_INCLUDE                     

//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class Throttle 
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        double currentPosition;     
        double lastUpdateTime;     
        CThrottleDlg* m_dlg;     
        Port_Double* positionPort;     
        bool bInit;     
    public:
        void handle_tick(double *time); 
        void setPosition(const double t, double* val);

        void init();             
        void clean();    
        void SetName(const _TCHAR* caption);
        Throttle();             
        ~Throttle(); 
        
        long AddRef();
        long Release();

        long m_cRef;
        double val;

    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










