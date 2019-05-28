
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

INSTRUMENTATION=None

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=DefaultComponent

all : $(TARGET_NAME)$(EXE_EXT) DefaultComponent.mak

TARGET_MAIN=MainDefaultComponent

LIBS=

INCLUDE_PATH=

ADDITIONAL_OBJS=

OBJS= \
  aeroComposition.obj  \
  aeroDynamics.obj  \
  aeroPort.obj  \
  AtmoHeightPort.obj  \
  AtmoPort.obj  \
  atmosphere.obj  \
  bodyDynamics.obj  \
  engineDynamics.obj  \
  finDynamics.obj  \
  FinPort.obj  \
  GustPort.obj  \
  gustWind.obj  \
  Units.obj  \
  App.obj  \
  aeroFrame.obj  \
  App_task_0040ms.obj  \
  Animation.obj  \
  EstimatorLOS.obj  \
  EstimatorLOSCoeff.obj  \
  App_task_0010ms.obj  \
  TrackingSubsystem.obj  \
  TrackingSubsystemCoeff.obj  \
  GimbalController.obj  \
  GimbalControllerCoeff.obj  \
  RateStabilizationFilter.obj  \
  RateStabilizationFilterCoeff.obj  \
  ControlDesigner.obj  \
  GuidanceLogic.obj  \
  EstimatorVc.obj  \
  EstimatorVcCoeff.obj  \
  Target.obj  \
  App_task_0001ms.obj  \
  AutoPilot.obj  \
  AutoPilotCoeff.obj  \
  AppAirFrame.obj  \
  AirframePkg.obj  \
  GuidancePkg.obj  \
  TrackingSubsystemPkg.obj  \
  AvionicsPkg.obj  \
  TargetPkg.obj  \
  AutopilotPkg.obj 




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






aeroComposition.obj : aeroComposition.cpp aeroComposition.h    AirframePkg.h finDynamics.h engineDynamics.h bodyDynamics.h atmosphere.h aeroFrame.h aeroDynamics.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"aeroComposition.obj" "aeroComposition.cpp" 


aeroDynamics.obj : aeroDynamics.cpp aeroDynamics.h    AirframePkg.h aeroPort.h AtmoPort.h FinPort.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"aeroDynamics.obj" "aeroDynamics.cpp" 


aeroPort.obj : aeroPort.cpp aeroPort.h    AirframePkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"aeroPort.obj" "aeroPort.cpp" 


AtmoHeightPort.obj : AtmoHeightPort.cpp AtmoHeightPort.h    AirframePkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AtmoHeightPort.obj" "AtmoHeightPort.cpp" 


AtmoPort.obj : AtmoPort.cpp AtmoPort.h    AirframePkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AtmoPort.obj" "AtmoPort.cpp" 


atmosphere.obj : atmosphere.cpp atmosphere.h    AirframePkg.h AtmoPort.h AtmoHeightPort.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"atmosphere.obj" "atmosphere.cpp" 


bodyDynamics.obj : bodyDynamics.cpp bodyDynamics.h    AirframePkg.h aeroPort.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"bodyDynamics.obj" "bodyDynamics.cpp" 


engineDynamics.obj : engineDynamics.cpp engineDynamics.h    AirframePkg.h aeroPort.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"engineDynamics.obj" "engineDynamics.cpp" 


finDynamics.obj : finDynamics.cpp finDynamics.h    AirframePkg.h FinPort.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"finDynamics.obj" "finDynamics.cpp" 


FinPort.obj : FinPort.cpp FinPort.h    AirframePkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FinPort.obj" "FinPort.cpp" 


GustPort.obj : GustPort.cpp GustPort.h    AirframePkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"GustPort.obj" "GustPort.cpp" 


gustWind.obj : gustWind.cpp gustWind.h    AirframePkg.h aeroPort.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"gustWind.obj" "gustWind.cpp" 


Units.obj : Units.cpp Units.h    AirframePkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Units.obj" "Units.cpp" 


App.obj : App.cpp App.h    App_task_0040ms.h App_task_0010ms.h App_task_0001ms.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"App.obj" "App.cpp" 


aeroFrame.obj : aeroFrame.cpp aeroFrame.h    AirframePkg.h aeroPort.h AtmoHeightPort.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"aeroFrame.obj" "aeroFrame.cpp" 


App_task_0040ms.obj : App_task_0040ms.cpp App_task_0040ms.h    Animation.h EstimatorLOS.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"App_task_0040ms.obj" "App_task_0040ms.cpp" 


Animation.obj : Animation.cpp Animation.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Animation.obj" "Animation.cpp" 


EstimatorLOS.obj : EstimatorLOS.cpp EstimatorLOS.h    GuidancePkg.h EstimatorLOSCoeff.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"EstimatorLOS.obj" "EstimatorLOS.cpp" 


EstimatorLOSCoeff.obj : EstimatorLOSCoeff.cpp EstimatorLOSCoeff.h    GuidancePkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"EstimatorLOSCoeff.obj" "EstimatorLOSCoeff.cpp" 


App_task_0010ms.obj : App_task_0010ms.cpp App_task_0010ms.h    TrackingSubsystem.h Target.h GuidanceLogic.h EstimatorVc.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"App_task_0010ms.obj" "App_task_0010ms.cpp" 


TrackingSubsystem.obj : TrackingSubsystem.cpp TrackingSubsystem.h    TrackingSubsystemPkg.h TrackingSubsystemCoeff.h GimbalController.h RateStabilizationFilter.h GuidanceLogic.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TrackingSubsystem.obj" "TrackingSubsystem.cpp" 


TrackingSubsystemCoeff.obj : TrackingSubsystemCoeff.cpp TrackingSubsystemCoeff.h    TrackingSubsystemPkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TrackingSubsystemCoeff.obj" "TrackingSubsystemCoeff.cpp" 


GimbalController.obj : GimbalController.cpp GimbalController.h    TrackingSubsystemPkg.h GimbalControllerCoeff.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"GimbalController.obj" "GimbalController.cpp" 


GimbalControllerCoeff.obj : GimbalControllerCoeff.cpp GimbalControllerCoeff.h    TrackingSubsystemPkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"GimbalControllerCoeff.obj" "GimbalControllerCoeff.cpp" 


RateStabilizationFilter.obj : RateStabilizationFilter.cpp RateStabilizationFilter.h    TrackingSubsystemPkg.h RateStabilizationFilterCoeff.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"RateStabilizationFilter.obj" "RateStabilizationFilter.cpp" 


RateStabilizationFilterCoeff.obj : RateStabilizationFilterCoeff.cpp RateStabilizationFilterCoeff.h    TrackingSubsystemPkg.h ControlDesigner.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"RateStabilizationFilterCoeff.obj" "RateStabilizationFilterCoeff.cpp" 


ControlDesigner.obj : ControlDesigner.cpp ControlDesigner.h    AvionicsPkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ControlDesigner.obj" "ControlDesigner.cpp" 


GuidanceLogic.obj : GuidanceLogic.cpp GuidanceLogic.h    GuidancePkg.h EstimatorVc.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"GuidanceLogic.obj" "GuidanceLogic.cpp" 


EstimatorVc.obj : EstimatorVc.cpp EstimatorVc.h    GuidancePkg.h EstimatorVcCoeff.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"EstimatorVc.obj" "EstimatorVc.cpp" 


EstimatorVcCoeff.obj : EstimatorVcCoeff.cpp EstimatorVcCoeff.h    GuidancePkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"EstimatorVcCoeff.obj" "EstimatorVcCoeff.cpp" 


Target.obj : Target.cpp Target.h    TargetPkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Target.obj" "Target.cpp" 


App_task_0001ms.obj : App_task_0001ms.cpp App_task_0001ms.h    AutoPilot.h AppAirFrame.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"App_task_0001ms.obj" "App_task_0001ms.cpp" 


AutoPilot.obj : AutoPilot.cpp AutoPilot.h    AutopilotPkg.h AutoPilotCoeff.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AutoPilot.obj" "AutoPilot.cpp" 


AutoPilotCoeff.obj : AutoPilotCoeff.cpp AutoPilotCoeff.h    AutopilotPkg.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AutoPilotCoeff.obj" "AutoPilotCoeff.cpp" 


AppAirFrame.obj : AppAirFrame.cpp AppAirFrame.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AppAirFrame.obj" "AppAirFrame.cpp" 


AirframePkg.obj : AirframePkg.cpp AirframePkg.h    Units.h aeroPort.h bodyDynamics.h engineDynamics.h gustWind.h GustPort.h AtmoHeightPort.h AtmoPort.h FinPort.h atmosphere.h aeroFrame.h aeroDynamics.h finDynamics.h aeroComposition.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AirframePkg.obj" "AirframePkg.cpp" 


GuidancePkg.obj : GuidancePkg.cpp GuidancePkg.h    GuidanceLogic.h EstimatorLOS.h EstimatorVc.h EstimatorVcCoeff.h EstimatorLOSCoeff.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"GuidancePkg.obj" "GuidancePkg.cpp" 


TrackingSubsystemPkg.obj : TrackingSubsystemPkg.cpp TrackingSubsystemPkg.h    GimbalController.h GimbalControllerCoeff.h RateStabilizationFilter.h RateStabilizationFilterCoeff.h TrackingSubsystem.h TrackingSubsystemCoeff.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TrackingSubsystemPkg.obj" "TrackingSubsystemPkg.cpp" 


AvionicsPkg.obj : AvionicsPkg.cpp AvionicsPkg.h    ControlDesigner.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AvionicsPkg.obj" "AvionicsPkg.cpp" 


TargetPkg.obj : TargetPkg.cpp TargetPkg.h    Target.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TargetPkg.obj" "TargetPkg.cpp" 


AutopilotPkg.obj : AutopilotPkg.cpp AutopilotPkg.h    AutoPilot.h AutoPilotCoeff.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AutopilotPkg.obj" "AutopilotPkg.cpp" 





$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) 
	$(CPP) $(ConfigurationCPPCompileSwitches) /Fo"$(TARGET_MAIN)$(OBJ_EXT)" $(TARGET_MAIN)$(CPP_EXT)

########################## Linking instructions ###############################
###############################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) DefaultComponent.mak
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(SOCK_LIB) \
	$(LINK_FLAGS) /out:$(TARGET_NAME)$(EXE_EXT)

$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) DefaultComponent.mak
	@echo Building library $@
	$(LIB_CMD) $(LIB_FLAGS) /out:$(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS)

clean:
	@echo Cleanup
	if exist aeroComposition.obj erase aeroComposition.obj
	if exist aeroDynamics.obj erase aeroDynamics.obj
	if exist aeroPort.obj erase aeroPort.obj
	if exist AtmoHeightPort.obj erase AtmoHeightPort.obj
	if exist AtmoPort.obj erase AtmoPort.obj
	if exist atmosphere.obj erase atmosphere.obj
	if exist bodyDynamics.obj erase bodyDynamics.obj
	if exist engineDynamics.obj erase engineDynamics.obj
	if exist finDynamics.obj erase finDynamics.obj
	if exist FinPort.obj erase FinPort.obj
	if exist GustPort.obj erase GustPort.obj
	if exist gustWind.obj erase gustWind.obj
	if exist Units.obj erase Units.obj
	if exist App.obj erase App.obj
	if exist aeroFrame.obj erase aeroFrame.obj
	if exist App_task_0040ms.obj erase App_task_0040ms.obj
	if exist Animation.obj erase Animation.obj
	if exist EstimatorLOS.obj erase EstimatorLOS.obj
	if exist EstimatorLOSCoeff.obj erase EstimatorLOSCoeff.obj
	if exist App_task_0010ms.obj erase App_task_0010ms.obj
	if exist TrackingSubsystem.obj erase TrackingSubsystem.obj
	if exist TrackingSubsystemCoeff.obj erase TrackingSubsystemCoeff.obj
	if exist GimbalController.obj erase GimbalController.obj
	if exist GimbalControllerCoeff.obj erase GimbalControllerCoeff.obj
	if exist RateStabilizationFilter.obj erase RateStabilizationFilter.obj
	if exist RateStabilizationFilterCoeff.obj erase RateStabilizationFilterCoeff.obj
	if exist ControlDesigner.obj erase ControlDesigner.obj
	if exist GuidanceLogic.obj erase GuidanceLogic.obj
	if exist EstimatorVc.obj erase EstimatorVc.obj
	if exist EstimatorVcCoeff.obj erase EstimatorVcCoeff.obj
	if exist Target.obj erase Target.obj
	if exist App_task_0001ms.obj erase App_task_0001ms.obj
	if exist AutoPilot.obj erase AutoPilot.obj
	if exist AutoPilotCoeff.obj erase AutoPilotCoeff.obj
	if exist AppAirFrame.obj erase AppAirFrame.obj
	if exist AirframePkg.obj erase AirframePkg.obj
	if exist GuidancePkg.obj erase GuidancePkg.obj
	if exist TrackingSubsystemPkg.obj erase TrackingSubsystemPkg.obj
	if exist AvionicsPkg.obj erase AvionicsPkg.obj
	if exist TargetPkg.obj erase TargetPkg.obj
	if exist AutopilotPkg.obj erase AutopilotPkg.obj
	if exist $(TARGET_MAIN)$(OBJ_EXT) erase $(TARGET_MAIN)$(OBJ_EXT)
	if exist *$(OBJ_EXT) erase *$(OBJ_EXT)
	if exist $(TARGET_NAME).pdb erase $(TARGET_NAME).pdb
	if exist $(TARGET_NAME)$(LIB_EXT) erase $(TARGET_NAME)$(LIB_EXT)
	if exist $(TARGET_NAME).ilk erase $(TARGET_NAME).ilk
	if exist $(TARGET_NAME)$(EXE_EXT) erase $(TARGET_NAME)$(EXE_EXT)
	$(CLEAN_OBJ_DIR)
