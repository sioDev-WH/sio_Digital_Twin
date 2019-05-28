#ifndef __BRAKES_H
#define __BRAKES_H

// Cg_Add
#include "ShiftLogic.h"

struct _OnBrakes;

//{{SCG_HEADER(Brakes.h) [0]

//{{SCG_INCLUDE                     

//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)
class CBrakeDlg;


class Brakes 
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        long m_cRef;
        double currentPosition;     
        double lastUpdateTime;
        CBrakeDlg* m_dlg;
        Port_Double* positionPort;     
        bool bInit;     
    public:
        void handle_tick(double *time);
        void setPosition(const double t, double* val);

        void init();             
        void clean();
        Brakes();
        ~Brakes();

        long AddRef();
        long Release();
        void SetName(const _TCHAR* caption);

    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










