#ifndef __CONTROLLER_H
#define __CONTROLLER_H


#include "ShiftData.h"

//{{SCG_HEADER(Controller.h) [0]

//{{SCG_INCLUDE                     
#include "ShiftLogic.h"
#include "RtsSmInt.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    
class ShiftData;
//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class Controller 
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
public: 
  
        long AddRef();
        long Release();
        void SetName(LPCTSTR cszName) {  }

        long m_cRef;
        double local_time;
        long currentGear;     
        Port_Int* Port_0;     
        Port_Int* Port_1;     
        Port_Int* Port_2;     
        Port_Int* Port_3;     
        Port_Int* Port_4;     
        Port_Int* Port_5;     
        Port_Int* Port_6;     
        Port_Int* Port_7;     
        Port_Int* Port_8;     

private:

        ShiftData shiftData;     
        double throttleData;     
        double vehicleSpeedData;     
        double upShiftThreshold;     
        double downShiftThreshold;     
        long shiftLeverData;     
        RtsControllerController_States RtsCurrent_Controller;     
        //RtsControllerFirst_States RtsCurrent_First;     
        RtsTimer RtsAttTorque_Timer1;     
        //RtsControllerSecond_States RtsCurrent_Second;     
        RtsTimer RtsAttTorque_1_Timer1;     
        //RtsControllerThird_States RtsCurrent_Third;     
        RtsTimer RtsAttTorque_2_Timer1;     
        //RtsControllerFourth_States RtsCurrent_Fourth;     
        RtsTimer RtsAttTorque_3_Timer1;     
        RtsControllerReverse_States RtsCurrent_Reverse;     
        RtsControllerIdle_States RtsCurrent_Idle;     
        RtsMutex RtsBusy;     
        Port_Int* pActuatorPorts[9];     
    public:
        void updateThresholds();             
        void init();             
        void downShift();             
        void upShift();             
        void runShiftLogic();             
        void Fire_DisengageEvents();             
        void clean();             
        void Fire_EngageEvents();             
        void handle_ThrottleData(const double time, double *val);             
        void handle_SpeedData(const double * time, const double *vals, const long cVals);             
        void handle_ShiftLeverData(const double time, long *val);             
        void handle_tick(double *time); 
        
        void Save(FILE* fs);
        bool Load(FILE* fs);

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
        void RtsEnter_Inertia();             
        void RtsExit_Inertia();             
        void RtsDefault_First();             
        void RtsEnter_Torque();             
        void RtsExit_Torque();             
        void RtsEnter_Inertia_1();             
        void RtsExit_Inertia_1();             
        void RtsDefault_Second();             
        void RtsEnter_Torque_1();             
        void RtsExit_Torque_1();             
    public:
        ~Controller();             
    private:
        void RtsEnter_Inertia_2();             
        void RtsExit_Inertia_2();             
        void RtsDefault_Third();             
        void RtsEnter_Torque_2();             
        void RtsExit_Torque_2();             
        void RtsEnter_Inertia_3();             
        void RtsExit_Inertia_3();             
        void RtsDefault_Fourth();             
        void RtsEnter_Torque_3();             
        void RtsExit_Torque_3();             
        void RtsEnter_Active();             
        void RtsExit_Active();             
        void RtsDefault_Reverse();             
        void RtsDefault_Idle();             
        void RtsEnter_Ready();             
        void RtsExit_Ready();             
    public:
        void Rtsclock_tic();             
        void RtsmanualNeutralShift();             
    private:
        void RtsTorque_Timer1();             
        static void RtsTorque_Timer1_CallBack(Controller *pInstance);             
        void RtsTorque_1_Timer1();             
        static void RtsTorque_1_Timer1_CallBack(Controller *pInstance);             
        void RtsTorque_2_Timer1();             
        static void RtsTorque_2_Timer1_CallBack(Controller *pInstance);             
        void RtsTorque_3_Timer1();             
        static void RtsTorque_3_Timer1_CallBack(Controller *pInstance);             
    public:
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

    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










