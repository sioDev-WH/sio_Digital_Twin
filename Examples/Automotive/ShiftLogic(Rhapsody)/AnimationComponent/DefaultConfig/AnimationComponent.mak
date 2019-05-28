
############# Target type (Debug/Release) ##################
############################################################
CPPCompileDebug= /Zi /Od /D "_DEBUG" /MDd  /Fd"$(TARGET_NAME)" 
CPPCompileRelease= /Ox /D"NDEBUG" /MD /Fd"$(TARGET_NAME)" 
LinkDebug=
LinkRelease=
BuildSet=Debug
SUBSYSTEM=/SUBSYSTEM:console
COM=False
RPFrameWorkDll=False

ConfigurationCPPCompileSwitches=  /I . /I $(OMROOT)\LangCpp /I $(OMROOT)\LangCpp\oxf /nologo /W3 /GX $(CPPCompileDebug) /D "_AFXDLL" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_WINDOWS" $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) /c 

!IF "$(RPFrameWorkDll)" == "True"
ConfigurationCPPCompileSwitches=$(ConfigurationCPPCompileSwitches) /D "FRAMEWORK_DLL"
!ENDIF

!IF "$(COM)" == "True"
SUBSYSTEM=/SUBSYSTEM:windows
!ENDIF

################### Compilation flags ######################
############################################################
INCLUDE_QUALIFIER=/I
LIB_PREFIX=MS

################### Commands definition #########################
#################################################################
RMDIR = rmdir
LIB_CMD=link.exe -lib
LINK_CMD=link.exe
LIB_FLAGS=$(LinkDebug) /NOLOGO   
LINK_FLAGS=$(LinkDebug) /NOLOGO    $(SUBSYSTEM) /MACHINE:I386 

############### Generated macros #################
##################################################

FLAGSFILE=
RULESFILE=
OMROOT="C:\Rhapsody40\Share"

CPP_EXT=.cpp
H_EXT=.h
OBJ_EXT=.obj
EXE_EXT=.exe
LIB_EXT=.lib

INSTRUMENTATION=Animation

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=AnimationComponent

all : $(TARGET_NAME)$(EXE_EXT) AnimationComponent.mak

TARGET_MAIN=MainAnimationComponent

LIBS=

INCLUDE_PATH=

ADDITIONAL_OBJS=

OBJS= \
  Demo_EngineCar.obj  \
  Demo_EngineCar_app.obj  \
  EngineWithMass.obj  \
  EngineWithMass_app.obj  \
  Demo_CompleteCar.obj  \
  Demo_CompleteCar_app.obj  \
  Demo_CarComplete2.obj  \
  Demo_CarComplete2_app.obj  \
  LookupTable.obj  \
  CDamper.obj  \
  CFrame.obj  \
  CMass.obj  \
  CSpring.obj  \
  ShiftData.obj  \
  Clutch_Schedule.obj  \
  Controller.obj  \
  GearInfo.obj  \
  Oneway_Clutch.obj  \
  PlanetaryCoupler.obj  \
  Ravigneaux.obj  \
  Torque_Converter.obj  \
  Actuator.obj  \
  ActuatorClutchConnector.obj  \
  Band_Brake.obj  \
  BrakeActuator.obj  \
  Clutch.obj  \
  ClutchBase.obj  \
  CRigidConnector.obj  \
  Engine.obj  \
  Gear.obj  \
  Vehicle5.obj  \
  Vehicle.obj  \
  Chart.obj  \
  Brakes.obj  \
  ShiftLever.obj  \
  Throttle.obj  \
  CBrakeDlg.obj  \
  CShiftDlg.obj  \
  CThrottleDlg.obj  \
  theApp.obj  \
  Demo.obj  \
  StandardModels.obj  \
  TransmissionControlModels.obj  \
  TransmissionModels.obj  \
  VehicleModels.obj  \
  GUIModels.obj  \
  Application.obj 




OBJ_DIR=

!IF "$(OBJ_DIR)"!=""
CREATE_OBJ_DIR=if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
CLEAN_OBJ_DIR= if exist $(OBJ_DIR) $(RMDIR) $(OBJ_DIR)
!ELSE
CREATE_OBJ_DIR=
CLEAN_OBJ_DIR=
!ENDIF

######################## Predefined macros ############################
#######################################################################
$(OBJS) : $(INST_LIBS) $(OXF_LIBS)

LIB_POSTFIX=
!IF "$(BuildSet)"=="Release"
LIB_POSTFIX=R
!ENDIF

!IF "$(TARGET_TYPE)" == "Executable"
LinkDebug=$(LinkDebug) /DEBUG
LinkRelease=$(LinkRelease) /OPT:NOREF
!ELSEIF "$(TARGET_TYPE)" == "Library"
LinkDebug=$(LinkDebug) /DEBUGTYPE:CV
!ENDIF


!IF "$(INSTRUMENTATION)" == "Animation"
INST_FLAGS=/D "OMANIMATOR"
INST_INCLUDES=/I $(OMROOT)\LangCpp\aom /I $(OMROOT)\LangCpp\tom
!IF "$(RPFrameWorkDll)" == "True"
INST_LIBS= 
OXF_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxfanimdll$(LIB_POSTFIX)$(LIB_EXT) 
!ELSE
INST_LIBS= $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)aomanim$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxfinst$(LIB_POSTFIX)$(LIB_EXT) $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)omComAppl$(LIB_POSTFIX)$(LIB_EXT)
!ENDIF
SOCK_LIB=wsock32.lib

!ELSEIF "$(INSTRUMENTATION)" == "Tracing"
INST_FLAGS=/D "OMTRACER"
INST_INCLUDES=/I $(OMROOT)\LangCpp\aom /I $(OMROOT)\LangCpp\tom
!IF "$(RPFrameWorkDll)" == "True"
INST_LIBS=
OXF_LIBS= $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxftracedll$(LIB_POSTFIX)$(LIB_EXT) 
!ELSE
INST_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)tomtrace$(LIB_POSTFIX)$(LIB_EXT) $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)aomtrace$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS= $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxfinst$(LIB_POSTFIX)$(LIB_EXT) $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)omComAppl$(LIB_POSTFIX)$(LIB_EXT)
!ENDIF
SOCK_LIB=wsock32.lib

!ELSEIF "$(INSTRUMENTATION)" == "None" 
INST_FLAGS=
INST_INCLUDES=
INST_LIBS=
!IF "$(RPFrameWorkDll)" == "True"
OXF_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxfdll$(LIB_POSTFIX)$(LIB_EXT)
!ELSE
OXF_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxf$(LIB_POSTFIX)$(LIB_EXT)
!ENDIF
SOCK_LIB=

!ELSE
!ERROR An invalid Instrumentation $(INSTRUMENTATION) is specified.
!ENDIF

################## Generated dependencies ########################
##################################################################






Demo_EngineCar.obj : Demo_EngineCar.cpp Demo_EngineCar.h    Demo.h Vehicle5.h Actuator.h Clutch.h Engine.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Demo_EngineCar.obj" "Demo_EngineCar.cpp" 


Demo_EngineCar_app.obj : Demo_EngineCar_app.cpp Demo_EngineCar_app.h    Demo.h Demo_EngineCar.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Demo_EngineCar_app.obj" "Demo_EngineCar_app.cpp" 


EngineWithMass.obj : EngineWithMass.cpp EngineWithMass.h    Demo.h Engine.h CMass.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"EngineWithMass.obj" "EngineWithMass.cpp" 


EngineWithMass_app.obj : EngineWithMass_app.cpp EngineWithMass_app.h    Demo.h EngineWithMass.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"EngineWithMass_app.obj" "EngineWithMass_app.cpp" 


Demo_CompleteCar.obj : Demo_CompleteCar.cpp Demo_CompleteCar.h    Demo.h Vehicle5.h CSpring.h CDamper.h Engine.h Actuator.h Clutch.h CFrame.h Band_Brake.h Oneway_Clutch.h Ravigneaux.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Demo_CompleteCar.obj" "Demo_CompleteCar.cpp" 


Demo_CompleteCar_app.obj : Demo_CompleteCar_app.cpp Demo_CompleteCar_app.h    Demo.h Demo_CompleteCar.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Demo_CompleteCar_app.obj" "Demo_CompleteCar_app.cpp" 


Demo_CarComplete2.obj : Demo_CarComplete2.cpp Demo_CarComplete2.h    Demo.h Torque_Converter.h Vehicle5.h CSpring.h CDamper.h Engine.h Actuator.h Clutch.h CFrame.h Band_Brake.h Oneway_Clutch.h Ravigneaux.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Demo_CarComplete2.obj" "Demo_CarComplete2.cpp" 


Demo_CarComplete2_app.obj : Demo_CarComplete2_app.cpp Demo_CarComplete2_app.h    Demo.h Demo_CarComplete2.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Demo_CarComplete2_app.obj" "Demo_CarComplete2_app.cpp" 


LookupTable.obj : LookupTable.cpp LookupTable.h    StandardModels.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"LookupTable.obj" "LookupTable.cpp" 


CDamper.obj : CDamper.cpp CDamper.h    StandardModels.h CRigidConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CDamper.obj" "CDamper.cpp" 


CFrame.obj : CFrame.cpp CFrame.h    StandardModels.h CRigidConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CFrame.obj" "CFrame.cpp" 


CMass.obj : CMass.cpp CMass.h    StandardModels.h CRigidConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CMass.obj" "CMass.cpp" 


CSpring.obj : CSpring.cpp CSpring.h    StandardModels.h CRigidConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CSpring.obj" "CSpring.cpp" 


ShiftData.obj : ShiftData.cpp ShiftData.h    TransmissionControlModels.h LookupTable.h Clutch_Schedule.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ShiftData.obj" "ShiftData.cpp" 


Clutch_Schedule.obj : Clutch_Schedule.cpp Clutch_Schedule.h    TransmissionControlModels.h GearInfo.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Clutch_Schedule.obj" "Clutch_Schedule.cpp" 


Controller.obj : Controller.cpp Controller.h    TransmissionControlModels.h ShiftData.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Controller.obj" "Controller.cpp" 


GearInfo.obj : GearInfo.cpp GearInfo.h    TransmissionControlModels.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"GearInfo.obj" "GearInfo.cpp" 


Oneway_Clutch.obj : Oneway_Clutch.cpp Oneway_Clutch.h    TransmissionModels.h ClutchBase.h ActuatorClutchConnector.h CRigidConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Oneway_Clutch.obj" "Oneway_Clutch.cpp" 


PlanetaryCoupler.obj : PlanetaryCoupler.cpp PlanetaryCoupler.h    TransmissionModels.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"PlanetaryCoupler.obj" "PlanetaryCoupler.cpp" 


Ravigneaux.obj : Ravigneaux.cpp Ravigneaux.h    TransmissionModels.h CRigidConnector.h Gear.h PlanetaryCoupler.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Ravigneaux.obj" "Ravigneaux.cpp" 


Torque_Converter.obj : Torque_Converter.cpp Torque_Converter.h    TransmissionModels.h CRigidConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Torque_Converter.obj" "Torque_Converter.cpp" 


Actuator.obj : Actuator.cpp Actuator.h    TransmissionModels.h ActuatorClutchConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Actuator.obj" "Actuator.cpp" 


ActuatorClutchConnector.obj : ActuatorClutchConnector.cpp ActuatorClutchConnector.h    TransmissionModels.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ActuatorClutchConnector.obj" "ActuatorClutchConnector.cpp" 


Band_Brake.obj : Band_Brake.cpp Band_Brake.h    TransmissionModels.h ClutchBase.h ActuatorClutchConnector.h CRigidConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Band_Brake.obj" "Band_Brake.cpp" 


BrakeActuator.obj : BrakeActuator.cpp BrakeActuator.h    TransmissionModels.h ActuatorClutchConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"BrakeActuator.obj" "BrakeActuator.cpp" 


Clutch.obj : Clutch.cpp Clutch.h    TransmissionModels.h ClutchBase.h ActuatorClutchConnector.h CRigidConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Clutch.obj" "Clutch.cpp" 


ClutchBase.obj : ClutchBase.cpp ClutchBase.h    TransmissionModels.h ActuatorClutchConnector.h CRigidConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ClutchBase.obj" "ClutchBase.cpp" 


CRigidConnector.obj : CRigidConnector.cpp CRigidConnector.h    TransmissionModels.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CRigidConnector.obj" "CRigidConnector.cpp" 


Engine.obj : Engine.cpp Engine.h    TransmissionModels.h CRigidConnector.h LookupTable.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Engine.obj" "Engine.cpp" 


Gear.obj : Gear.cpp Gear.h    TransmissionModels.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Gear.obj" "Gear.cpp" 


Vehicle5.obj : Vehicle5.cpp Vehicle5.h    VehicleModels.h CFrame.h Clutch.h CRigidConnector.h BrakeActuator.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Vehicle5.obj" "Vehicle5.cpp" 


Vehicle.obj : Vehicle.cpp Vehicle.h    VehicleModels.h CRigidConnector.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Vehicle.obj" "Vehicle.cpp" 


Chart.obj : Chart.cpp Chart.h    GUIModels.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Chart.obj" "Chart.cpp" 


Brakes.obj : Brakes.cpp Brakes.h    GUIModels.h CBrakeDlg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Brakes.obj" "Brakes.cpp" 


ShiftLever.obj : ShiftLever.cpp ShiftLever.h    GUIModels.h CShiftDlg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ShiftLever.obj" "ShiftLever.cpp" 


Throttle.obj : Throttle.cpp Throttle.h    GUIModels.h CThrottleDlg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Throttle.obj" "Throttle.cpp" 


CBrakeDlg.obj : CBrakeDlg.cpp CBrakeDlg.h    GUIModels.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CBrakeDlg.obj" "CBrakeDlg.cpp" 


CShiftDlg.obj : CShiftDlg.cpp CShiftDlg.h    GUIModels.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CShiftDlg.obj" "CShiftDlg.cpp" 


CThrottleDlg.obj : CThrottleDlg.cpp CThrottleDlg.h    GUIModels.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CThrottleDlg.obj" "CThrottleDlg.cpp" 


theApp.obj : theApp.cpp theApp.h    Application.h Demo_EngineCar_app.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"theApp.obj" "theApp.cpp" 


Demo.obj : Demo.cpp Demo.h    Demo_EngineCar.h Demo_EngineCar_app.h EngineWithMass.h EngineWithMass_app.h Demo_CompleteCar.h Demo_CompleteCar_app.h Demo_CarComplete2.h Demo_CarComplete2_app.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Demo.obj" "Demo.cpp" 


StandardModels.obj : StandardModels.cpp StandardModels.h    LookupTable.h CDamper.h CFrame.h CMass.h CSpring.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"StandardModels.obj" "StandardModels.cpp" 


TransmissionControlModels.obj : TransmissionControlModels.cpp TransmissionControlModels.h    ShiftData.h Clutch_Schedule.h Controller.h GearInfo.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TransmissionControlModels.obj" "TransmissionControlModels.cpp" 


TransmissionModels.obj : TransmissionModels.cpp TransmissionModels.h    Oneway_Clutch.h PlanetaryCoupler.h Ravigneaux.h Torque_Converter.h Actuator.h ActuatorClutchConnector.h Band_Brake.h BrakeActuator.h Clutch.h ClutchBase.h CRigidConnector.h Engine.h Gear.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TransmissionModels.obj" "TransmissionModels.cpp" 


VehicleModels.obj : VehicleModels.cpp VehicleModels.h    Vehicle5.h Vehicle.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"VehicleModels.obj" "VehicleModels.cpp" 


GUIModels.obj : GUIModels.cpp GUIModels.h    Chart.h Brakes.h ShiftLever.h Throttle.h CBrakeDlg.h CShiftDlg.h CThrottleDlg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"GUIModels.obj" "GUIModels.cpp" 


Application.obj : Application.cpp Application.h    theApp.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Application.obj" "Application.cpp" 





$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) 
	$(CPP) $(ConfigurationCPPCompileSwitches) /Fo"$(TARGET_MAIN)$(OBJ_EXT)" $(TARGET_MAIN)$(CPP_EXT)

########################## Linking instructions ###############################
###############################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) AnimationComponent.mak
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(SOCK_LIB) \
	$(LINK_FLAGS) /out:$(TARGET_NAME)$(EXE_EXT)

$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) AnimationComponent.mak
	@echo Building library $@
	$(LIB_CMD) $(LIB_FLAGS) /out:$(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS)

clean:
	@echo Cleanup
	if exist Demo_EngineCar.obj erase Demo_EngineCar.obj
	if exist Demo_EngineCar_app.obj erase Demo_EngineCar_app.obj
	if exist EngineWithMass.obj erase EngineWithMass.obj
	if exist EngineWithMass_app.obj erase EngineWithMass_app.obj
	if exist Demo_CompleteCar.obj erase Demo_CompleteCar.obj
	if exist Demo_CompleteCar_app.obj erase Demo_CompleteCar_app.obj
	if exist Demo_CarComplete2.obj erase Demo_CarComplete2.obj
	if exist Demo_CarComplete2_app.obj erase Demo_CarComplete2_app.obj
	if exist LookupTable.obj erase LookupTable.obj
	if exist CDamper.obj erase CDamper.obj
	if exist CFrame.obj erase CFrame.obj
	if exist CMass.obj erase CMass.obj
	if exist CSpring.obj erase CSpring.obj
	if exist ShiftData.obj erase ShiftData.obj
	if exist Clutch_Schedule.obj erase Clutch_Schedule.obj
	if exist Controller.obj erase Controller.obj
	if exist GearInfo.obj erase GearInfo.obj
	if exist Oneway_Clutch.obj erase Oneway_Clutch.obj
	if exist PlanetaryCoupler.obj erase PlanetaryCoupler.obj
	if exist Ravigneaux.obj erase Ravigneaux.obj
	if exist Torque_Converter.obj erase Torque_Converter.obj
	if exist Actuator.obj erase Actuator.obj
	if exist ActuatorClutchConnector.obj erase ActuatorClutchConnector.obj
	if exist Band_Brake.obj erase Band_Brake.obj
	if exist BrakeActuator.obj erase BrakeActuator.obj
	if exist Clutch.obj erase Clutch.obj
	if exist ClutchBase.obj erase ClutchBase.obj
	if exist CRigidConnector.obj erase CRigidConnector.obj
	if exist Engine.obj erase Engine.obj
	if exist Gear.obj erase Gear.obj
	if exist Vehicle5.obj erase Vehicle5.obj
	if exist Vehicle.obj erase Vehicle.obj
	if exist Chart.obj erase Chart.obj
	if exist Brakes.obj erase Brakes.obj
	if exist ShiftLever.obj erase ShiftLever.obj
	if exist Throttle.obj erase Throttle.obj
	if exist CBrakeDlg.obj erase CBrakeDlg.obj
	if exist CShiftDlg.obj erase CShiftDlg.obj
	if exist CThrottleDlg.obj erase CThrottleDlg.obj
	if exist theApp.obj erase theApp.obj
	if exist Demo.obj erase Demo.obj
	if exist StandardModels.obj erase StandardModels.obj
	if exist TransmissionControlModels.obj erase TransmissionControlModels.obj
	if exist TransmissionModels.obj erase TransmissionModels.obj
	if exist VehicleModels.obj erase VehicleModels.obj
	if exist GUIModels.obj erase GUIModels.obj
	if exist Application.obj erase Application.obj
	if exist $(TARGET_MAIN)$(OBJ_EXT) erase $(TARGET_MAIN)$(OBJ_EXT)
	if exist *$(OBJ_EXT) erase *$(OBJ_EXT)
	if exist $(TARGET_NAME).pdb erase $(TARGET_NAME).pdb
	if exist $(TARGET_NAME)$(LIB_EXT) erase $(TARGET_NAME)$(LIB_EXT)
	if exist $(TARGET_NAME).ilk erase $(TARGET_NAME).ilk
	if exist $(TARGET_NAME)$(EXE_EXT) erase $(TARGET_NAME)$(EXE_EXT)
	$(CLEAN_OBJ_DIR)
