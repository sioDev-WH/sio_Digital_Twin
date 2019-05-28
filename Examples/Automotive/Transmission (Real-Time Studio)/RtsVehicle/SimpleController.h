#ifndef __SIMPLECONTROLLER_H
#define __SIMPLECONTROLLER_H

//{{SCG_HEADER(SimpleController.h) [0]

//{{SCG_INCLUDE     
#include "ShiftLogic.h"
#include "RtsSmInt.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class SimpleController 
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        long m_cRef;     
        COnBroadcaster<long>* EnginePort;     
        double sim_time;     
    private:
        RtsSimpleControllerSimpleController_States RtsCurrent_SimpleController;     
        RtsMutex RtsBusy;     
    public:
        COnBroadcaster<long>* ClutchPort5;     
        COnBroadcaster<long>* ClutchPort6;     
        COnBroadcaster<long>* ClutchPort7;     
        COnBroadcaster<long>* ClutchPort8;     
        COnBroadcaster<long>* ClutchPort9;     
        COnBroadcaster<long>* ClutchPort10;     
        COnBroadcaster<long>* ClutchPort11;     
        COnBroadcaster<long>* ClutchPort12;     
    private:
        bool bUpshift;     
    public:
        void handle_tick(const double* t);             
        long AddRef();             
        long Release();             
        void ec_Tick();             
        void init();             
        void Fire_StartEngine();             
        void Fire_NeutralToFirst();             
        void clean();             
    private:
        void RtsEnter_EngineRunning();             
        void RtsExit_EngineRunning();             
        void RtsEnter_init();             
        void RtsExit_init();             
    public:
        SimpleController();             
        ~SimpleController();             
    private:
        void RtsRunToCompletion();             
    #ifdef RTS_SIMULATION
    static int RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, SimpleController *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsGetAttributeValue(const char* Name, char* Value, const int buflen, SimpleController *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsSetAttributeValue(const char* Name, const char* Value, SimpleController *pInstance);             
#endif

    public:
        void SetName(const _TCHAR* caption);             
        void Fire_FirstToSecond();             
    private:
        void RtsEnter_SecondGear();             
        void RtsExit_SecondGear();             
        void RtsEnter_FirstGear();             
        void RtsExit_FirstGear();             
    public:
        void Fire_SecondToThird();             
        void Fire_ThirdToFourth();             
    private:
        void RtsEnter_FourthGear();             
        void RtsExit_FourthGear();             
        void RtsEnter_ThirdGear();             
        void RtsExit_ThirdGear();             
    public:
        void Fire_SecondToFirst();             
        void Fire_FirstToNeutral();             
        void Fire_ThirdToSecond();             
        void Fire_FourthToThird();             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










