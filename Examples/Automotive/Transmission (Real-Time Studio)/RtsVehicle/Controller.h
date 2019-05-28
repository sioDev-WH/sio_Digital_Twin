#ifndef __CONTROLLER_H
#define __CONTROLLER_H

//{{SCG_HEADER(Controller.h) [0]

//{{SCG_INCLUDE  
#include "ShiftData.h"
                   
#include "ShiftLogic.h"
#include "RtsSmInt.h"
#include "OnModelBase.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    
class ShiftData;
//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class Controller : public COnModelBase
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    private:
        long m_cRef;

        ShiftData shiftData;     
        double throttleData;     
        double vehicleSpeedData;     
        double upShiftThreshold;     
        double downShiftThreshold;     
        long currentGear;     
    public:
        Port_Int* Port_0;     
        Port_Int* Port_1;     
        Port_Int* Port_2;     
        Port_Int* Port_3;     
        Port_Int* Port_4;     
        Port_Int* Port_5;     
        Port_Int* Port_6;     
        Port_Int* Port_7;     
        Port_Int* Port_8;
        
        Port_Int* Port_Shift;

        bool bReverse;

    public:
        long shiftLeverData;     
        RtsControllerController_States RtsCurrent_Controller;     
        RtsControllerReverse_States RtsCurrent_Reverse;     
        RtsControllerIdle_States RtsCurrent_Idle;     
        RtsMutex RtsBusy;     
    public:
        Port_Int* pActuatorPorts[10];     
        double upshiftDelay[4];     
        double downshiftDelay[4];   
        double local_time;
        double transition_time;
    private:
        RtsTimer RtsAttSecondToFirst_Timer1;     
        RtsTimer RtsAttFourthToThird_Timer1;     
        RtsTimer RtsAttFirstToSecond_Timer1;     
        RtsTimer RtsAttSecondToThird_Timer1;     
        RtsTimer RtsAttThirdToFourth_Timer1;     
        RtsTimer RtsAttThirdToSecond_Timer1;     
    public:
        void SetName(LPCTSTR cszName) {  }

        void updateThresholds();             
        void init();             
        void downShift();             
        void upShift();             
        void runShiftLogic();             
        void Fire_DisengageEvents();             
        void clean();             
        void Fire_EngageEvents();             
        void handle_ThrottleData(const double time, double *val);             
        void handle_SpeedData(double val);             
        void handle_ShiftLeverData(const double time, long *val);             
        void handle_tick(double *time);             
    private:
        void RtsEnter_First();             
        void RtsExit_First();             
        void RtsEnter_Second();             
        void RtsExit_Second();             
        void RtsEnter_Third();             
        void RtsExit_Third();             
        void RtsEnter_Fourth();             
        void RtsExit_Fourth();             
        void RtsEnter_Reverse();             
        void RtsExit_Reverse();             
        void RtsEnter_Idle();             
        void RtsExit_Idle();             
    public:
        ~Controller();             
    private:
        void RtsEnter_Active();             
        void RtsExit_Active();             
        void RtsDefault_Reverse();             
        void RtsDefault_Idle();             
        void RtsEnter_Ready();             
        void RtsExit_Ready();             
    public:
        void Rtsclock_tic();             
        void RtsmanualNeutralShift();             
        void RtsmanualForwardShift();             
        void RtsmanualReverseShift();             
        Controller();             
    private:
        void RtsRunToCompletion();             
    #ifdef RTS_SIMULATION
    static int RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, Controller *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsGetAttributeValue(const char* Name, char* Value, const int buflen, Controller *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsSetAttributeValue(const char* Name, const char* Value, Controller *pInstance);             
#endif

    public:
        void enterSecond();             
        void enterThird();             
        void enterFourth();             
        void enterFirst();             
    private:
        void RtsEnter_SecondToFirst();             
        void RtsExit_SecondToFirst();             
        void RtsEnter_FourthToThird();             
        void RtsExit_FourthToThird();             
        void RtsEnter_FirstToSecond();             
        void RtsExit_FirstToSecond();             
        void RtsEnter_SecondToThird();             
        void RtsExit_SecondToThird();             
        void RtsEnter_ThirdToFourth();             
        void RtsExit_ThirdToFourth();             
        void RtsEnter_ThirdToSecond();             
        void RtsExit_ThirdToSecond();             
        void RtsSecondToFirst_Timer1();             
        static void RtsSecondToFirst_Timer1_CallBack(Controller *pInstance);             
        void RtsFourthToThird_Timer1();             
        static void RtsFourthToThird_Timer1_CallBack(Controller *pInstance);             
        void RtsFirstToSecond_Timer1();             
        static void RtsFirstToSecond_Timer1_CallBack(Controller *pInstance);             
        void RtsSecondToThird_Timer1();             
        static void RtsSecondToThird_Timer1_CallBack(Controller *pInstance);             
        void RtsThirdToFourth_Timer1();             
        static void RtsThirdToFourth_Timer1_CallBack(Controller *pInstance);             
        void RtsThirdToSecond_Timer1();             
        static void RtsThirdToSecond_Timer1_CallBack(Controller *pInstance);             
    public:
        bool Load(FILE *fs);             
        void Save(FILE *fs);             
        long AddRef();             
        long Release();             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










