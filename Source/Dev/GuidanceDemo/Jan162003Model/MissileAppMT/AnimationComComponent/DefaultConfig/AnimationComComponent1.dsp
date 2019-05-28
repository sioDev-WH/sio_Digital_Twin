# Microsoft Developer Studio Project File - Name="AnimationComComponent1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) External Target" 0x0106

CFG=AnimationComComponent1 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AnimationComComponent1.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AnimationComComponent1.mak" CFG="AnimationComComponent1 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AnimationComComponent1 - Win32 Release" (based on "Win32 (x86) External Target")
!MESSAGE "AnimationComComponent1 - Win32 Debug" (based on "Win32 (x86) External Target")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "AnimationComComponent1 - Win32 Release"

# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Cmd_Line "NMAKE /f AnimationComComponent.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "AnimationComComponent.exe"
# PROP BASE Bsc_Name "AnimationComComponent.bsc"
# PROP BASE Target_Dir ""
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Cmd_Line "NMAKE /f AnimationComComponent.mak"
# PROP Rebuild_Opt "/a"
# PROP Target_File "AnimationComComponent1.exe"
# PROP Bsc_Name "AnimationComComponent1.bsc"
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "AnimationComComponent1 - Win32 Debug"

# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Cmd_Line "NMAKE /f AnimationComComponent.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "AnimationComComponent.exe"
# PROP BASE Bsc_Name "AnimationComComponent.bsc"
# PROP BASE Target_Dir ""
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Cmd_Line "NMAKE /f AnimationComComponent.mak"
# PROP Rebuild_Opt "/a"
# PROP Target_File "AnimationComComponent1.exe"
# PROP Bsc_Name "AnimationComComponent1.bsc"
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "AnimationComComponent1 - Win32 Release"
# Name "AnimationComComponent1 - Win32 Debug"

!IF  "$(CFG)" == "AnimationComComponent1 - Win32 Release"

!ELSEIF  "$(CFG)" == "AnimationComComponent1 - Win32 Debug"

!ENDIF 

# Begin Group "Source"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=.\AeroCoeff.cpp
# End Source File
# Begin Source File

SOURCE=.\AeroDynamics.cpp
# End Source File
# Begin Source File

SOURCE=.\AirFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\AirframePkg.cpp
# End Source File
# Begin Source File

SOURCE=.\AirframeSubsystem.cpp
# End Source File
# Begin Source File

SOURCE=.\Animation.cpp
# End Source File
# Begin Source File

SOURCE=.\App1_app.cpp
# End Source File
# Begin Source File

SOURCE=.\App1_task_0001ms.cpp
# End Source File
# Begin Source File

SOURCE=.\App1_task_0010ms.cpp
# End Source File
# Begin Source File

SOURCE=.\App1_task_0040ms.cpp
# End Source File
# Begin Source File

SOURCE=.\Application.cpp
# End Source File
# Begin Source File

SOURCE=.\AtmoCoeff.cpp
# End Source File
# Begin Source File

SOURCE=.\Atmosphere.cpp
# End Source File
# Begin Source File

SOURCE=.\AutoPilot.cpp
# End Source File
# Begin Source File

SOURCE=.\AutoPilotCoeff.cpp
# End Source File
# Begin Source File

SOURCE=.\AutopilotPkg.cpp
# End Source File
# Begin Source File

SOURCE=.\AvionicsPkg.cpp
# End Source File
# Begin Source File

SOURCE=.\BodyDynamics.cpp
# End Source File
# Begin Source File

SOURCE=.\BodyDynamicsCoeff.cpp
# End Source File
# Begin Source File

SOURCE=.\cchartdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Chart.cpp
# End Source File
# Begin Source File

SOURCE=.\ControlDesigner.cpp
# End Source File
# Begin Source File

SOURCE=.\crossProduct.cpp
# End Source File
# Begin Source File

SOURCE=.\DisplayPkg.cpp
# End Source File
# Begin Source File

SOURCE=.\dotProduct.cpp
# End Source File
# Begin Source File

SOURCE=.\EstimatorLOS.cpp
# End Source File
# Begin Source File

SOURCE=.\EstimatorLOSCoeff.cpp
# End Source File
# Begin Source File

SOURCE=.\FinActuator.cpp
# End Source File
# Begin Source File

SOURCE=.\FinActuatorCoeff.cpp
# End Source File
# Begin Source File

SOURCE=.\GimbalController.cpp
# End Source File
# Begin Source File

SOURCE=.\GimbalControllerCoeff.cpp
# End Source File
# Begin Source File

SOURCE=.\GuidanceLogic.cpp
# End Source File
# Begin Source File

SOURCE=.\GuidancePkg.cpp
# End Source File
# Begin Source File

SOURCE=.\LibraryPkg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainAnimationComComponent.cpp
# End Source File
# Begin Source File

SOURCE=.\On1DConn.cpp
# End Source File
# Begin Source File

SOURCE=.\On3DConn.cpp
# End Source File
# Begin Source File

SOURCE=.\OniBase.cpp
# End Source File
# Begin Source File

SOURCE=.\RateStabilizationFilter.cpp
# End Source File
# Begin Source File

SOURCE=.\RateStabilizationFilterCoeff.cpp
# End Source File
# Begin Source File

SOURCE=.\RhapRegistery.cpp
# End Source File
# Begin Source File

SOURCE=.\ScheduledController_1D.cpp
# End Source File
# Begin Source File

SOURCE=.\ScheduledController_1D_Coeff.cpp
# End Source File
# Begin Source File

SOURCE=.\SeekerSubsystem.cpp
# End Source File
# Begin Source File

SOURCE=.\SeekerSubsystemCoeff.cpp
# End Source File
# Begin Source File

SOURCE=.\SeekerSubsystemPkg.cpp
# End Source File
# Begin Source File

SOURCE=.\Target.cpp
# End Source File
# Begin Source File

SOURCE=.\TargetPkg.cpp
# End Source File
# Begin Source File

SOURCE=.\theApp.cpp
# End Source File
# Begin Source File

SOURCE=.\transformAngle_DMC2Euler.cpp
# End Source File
# Begin Source File

SOURCE=.\transformAngle_Euler2Quaternion.cpp
# End Source File
# Begin Source File

SOURCE=.\transformAngleRate.cpp
# End Source File
# Begin Source File

SOURCE=.\transformPosition_B2I.cpp
# End Source File
# Begin Source File

SOURCE=.\transformPosition_I2B.cpp
# End Source File
# Begin Source File

SOURCE=.\WindGust.cpp
# End Source File
# End Group
# Begin Group "Header"

# PROP Default_Filter "h"
# Begin Source File

SOURCE=.\AeroCoeff.h
# End Source File
# Begin Source File

SOURCE=.\AeroDynamics.h
# End Source File
# Begin Source File

SOURCE=.\AirFrame.h
# End Source File
# Begin Source File

SOURCE=.\AirframePkg.h
# End Source File
# Begin Source File

SOURCE=.\AirframeSubsystem.h
# End Source File
# Begin Source File

SOURCE=.\Animation.h
# End Source File
# Begin Source File

SOURCE=.\App1_app.h
# End Source File
# Begin Source File

SOURCE=.\App1_task_0001ms.h
# End Source File
# Begin Source File

SOURCE=.\App1_task_0010ms.h
# End Source File
# Begin Source File

SOURCE=.\App1_task_0040ms.h
# End Source File
# Begin Source File

SOURCE=.\Application.h
# End Source File
# Begin Source File

SOURCE=.\AtmoCoeff.h
# End Source File
# Begin Source File

SOURCE=.\Atmosphere.h
# End Source File
# Begin Source File

SOURCE=.\AutoPilot.h
# End Source File
# Begin Source File

SOURCE=.\AutoPilotCoeff.h
# End Source File
# Begin Source File

SOURCE=.\AutopilotPkg.h
# End Source File
# Begin Source File

SOURCE=.\AvionicsPkg.h
# End Source File
# Begin Source File

SOURCE=.\BodyDynamics.h
# End Source File
# Begin Source File

SOURCE=.\BodyDynamicsCoeff.h
# End Source File
# Begin Source File

SOURCE=.\CChartDlg.h
# End Source File
# Begin Source File

SOURCE=.\Chart.h
# End Source File
# Begin Source File

SOURCE=.\ControlDesigner.h
# End Source File
# Begin Source File

SOURCE=.\crossProduct.h
# End Source File
# Begin Source File

SOURCE=.\DisplayPkg.h
# End Source File
# Begin Source File

SOURCE=.\dotProduct.h
# End Source File
# Begin Source File

SOURCE=.\EstimatorLOS.h
# End Source File
# Begin Source File

SOURCE=.\EstimatorLOSCoeff.h
# End Source File
# Begin Source File

SOURCE=.\FinActuator.h
# End Source File
# Begin Source File

SOURCE=.\FinActuatorCoeff.h
# End Source File
# Begin Source File

SOURCE=.\GimbalController.h
# End Source File
# Begin Source File

SOURCE=.\GimbalControllerCoeff.h
# End Source File
# Begin Source File

SOURCE=.\GuidanceLogic.h
# End Source File
# Begin Source File

SOURCE=.\GuidancePkg.h
# End Source File
# Begin Source File

SOURCE=.\LibraryPkg.h
# End Source File
# Begin Source File

SOURCE=.\MainAnimationComComponent.h
# End Source File
# Begin Source File

SOURCE=.\On1DConn.h
# End Source File
# Begin Source File

SOURCE=.\On3DConn.h
# End Source File
# Begin Source File

SOURCE=.\OniBase.h
# End Source File
# Begin Source File

SOURCE=.\RateStabilizationFilter.h
# End Source File
# Begin Source File

SOURCE=.\RateStabilizationFilterCoeff.h
# End Source File
# Begin Source File

SOURCE=.\RhapRegistery.h
# End Source File
# Begin Source File

SOURCE=.\ScheduledController_1D.h
# End Source File
# Begin Source File

SOURCE=.\ScheduledController_1D_Coeff.h
# End Source File
# Begin Source File

SOURCE=.\SeekerSubsystem.h
# End Source File
# Begin Source File

SOURCE=.\SeekerSubsystemCoeff.h
# End Source File
# Begin Source File

SOURCE=.\SeekerSubsystemPkg.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# Begin Source File

SOURCE=.\Target.h
# End Source File
# Begin Source File

SOURCE=.\TargetPkg.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\TeeChart5.h
# End Source File
# Begin Source File

SOURCE=.\theApp.h
# End Source File
# Begin Source File

SOURCE=.\transformAngle_DMC2Euler.h
# End Source File
# Begin Source File

SOURCE=.\transformAngle_Euler2Quaternion.h
# End Source File
# Begin Source File

SOURCE=.\transformAngleRate.h
# End Source File
# Begin Source File

SOURCE=.\transformPosition_B2I.h
# End Source File
# Begin Source File

SOURCE=.\transformPosition_I2B.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\units.h
# End Source File
# Begin Source File

SOURCE=.\WindGust.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\AnimationComComponent.mak
# End Source File
# End Target
# End Project
