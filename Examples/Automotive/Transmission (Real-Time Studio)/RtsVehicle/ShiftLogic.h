#ifndef __SHIFTLOGIC_H
#define __SHIFTLOGIC_H

//{{SCG_HEADER(ShiftLogic.h) [25]

#include "EventBroadcast.h"
class Fdouble;

//{{SCG_INCLUDE                     

//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD

//{{SCG_TYPEDEF(0)
typedef Fdouble** ppfdouble;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(62)
typedef enum {RtsSimpleControllerSimpleController_States_EngineRunning, RtsSimpleControllerSimpleController_States_init, RtsSimpleControllerSimpleController_States_NotIn_SimpleController, RtsSimpleControllerSimpleController_States_SecondGear, RtsSimpleControllerSimpleController_States_FirstGear, RtsSimpleControllerSimpleController_States_FourthGear, RtsSimpleControllerSimpleController_States_ThirdGear} RtsSimpleControllerSimpleController_States;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(63)
typedef enum {RtsEngineEngine_States_Starting, RtsEngineEngine_States_On, RtsEngineEngine_States_Off, RtsEngineEngine_States_NotIn_Engine} RtsEngineEngine_States;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(71)
typedef enum {RtsCOneClutchHarnessCOneClutchHarness_States_Init, RtsCOneClutchHarnessCOneClutchHarness_States_Run, RtsCOneClutchHarnessCOneClutchHarness_States_NotIn_COneClutchHarness} RtsCOneClutchHarnessCOneClutchHarness_States;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(73)
typedef enum {RtsActuatorActuator_States_Disengaged, RtsActuatorActuator_States_Waiting, RtsActuatorActuator_States_Engaged, RtsActuatorActuator_States_NotIn_Actuator} RtsActuatorActuator_States;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(74)
typedef long** pplong;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(78)
typedef COnBroadcaster<long> Port_Int;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(79)
typedef COnBroadcaster<double> Port_Double;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(80)
typedef enum {Direction_CLOCKWISE, Direction_COUNTERCLOCKWISE} Direction;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(81)
typedef enum {RtsDemo1_AppDemo1_App_States_RunSimulation, RtsDemo1_AppDemo1_App_States_Init, RtsDemo1_AppDemo1_App_States_NotIn_Demo1_App} RtsDemo1_AppDemo1_App_States;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(82)
typedef enum {RtsAppHarnessAppHarness_States_Init, RtsAppHarnessAppHarness_States_Clean, RtsAppHarnessAppHarness_States_Run, RtsAppHarnessAppHarness_States_NotIn_AppHarness} RtsAppHarnessAppHarness_States;

//}}SCG_TYPEDEF

typedef enum {RtsControllerIdle_States_Ready, RtsControllerIdle_States_NotIn_Idle} RtsControllerIdle_States;

//}}SCG_TYPEDEF

typedef enum {RtsControllerController_States_First, RtsControllerController_States_Second, RtsControllerController_States_Third, RtsControllerController_States_Fourth, RtsControllerController_States_Reverse, RtsControllerController_States_Idle, RtsControllerController_States_NotIn_Controller, RtsControllerController_States_SecondToFirst, RtsControllerController_States_FourthToThird, RtsControllerController_States_FirstToSecond, RtsControllerController_States_SecondToThird, RtsControllerController_States_ThirdToFourth, RtsControllerController_States_ThirdToSecond} RtsControllerController_States;


//{{SCG_TYPEDEF(85)
typedef enum {RtsClutchBaseClutch_States_cSlip, RtsClutchBaseClutch_States_Lock, RtsClutchBaseClutch_States_ccSlip, RtsClutchBaseClutch_States_NotIn_Clutch} RtsClutchBaseClutch_States;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(86)
typedef enum {RtsTorque_ConverterTorque_Converter_States_Fluid_Coupling, RtsTorque_ConverterTorque_Converter_States_Locked, RtsTorque_ConverterTorque_Converter_States_Torque_Multiplication, RtsTorque_ConverterTorque_Converter_States_NotIn_Torque_Converter} RtsTorque_ConverterTorque_Converter_States;

//}}SCG_TYPEDEF

//{{SCG_TYPEDEF(87)
typedef enum {RtssimpleGearboxsimpleGearbox_States_Neutral, RtssimpleGearboxsimpleGearbox_States_First, RtssimpleGearboxsimpleGearbox_States_Second, RtssimpleGearboxsimpleGearbox_States_Third, RtssimpleGearboxsimpleGearbox_States_Fourth, RtssimpleGearboxsimpleGearbox_States_Reverse, RtssimpleGearboxsimpleGearbox_States_NotIn_simpleGearbox} RtssimpleGearboxsimpleGearbox_States;

//}}SCG_TYPEDEF





// added by hand
typedef enum { RtsVehicle2Vehicle2_States_Reverse, RtsVehicle2Vehicle2_States_Forward, RtsVehicle2Vehicle2_States_NotIn_Vehicle2 } RtsVehicle2Vehicle2_States;

typedef enum { RtsControllerReverse_States_Active, RtsControllerReverse_States_NotIn_Reverse } RtsControllerReverse_States;

typedef double** ppdouble;
typedef _TCHAR** ppchar;
typedef Fdouble** ppfdouble;




//}}SCG_TYPEDEF

//}}SCG_HEADER      
#endif










