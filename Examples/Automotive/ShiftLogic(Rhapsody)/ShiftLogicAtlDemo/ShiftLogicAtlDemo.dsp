# Microsoft Developer Studio Project File - Name="ShiftLogicAtlDemo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ShiftLogicAtlDemo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ShiftLogicAtlDemo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ShiftLogicAtlDemo.mak" CFG="ShiftLogicAtlDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ShiftLogicAtlDemo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "ShiftLogicAtlDemo - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "ShiftLogicAtlDemo - Win32 Release MinSize" (based on "Win32 (x86) Application")
!MESSAGE "ShiftLogicAtlDemo - Win32 Release MinDependency" (based on "Win32 (x86) Application")
!MESSAGE "ShiftLogicAtlDemo - Win32 Unicode Release MinSize" (based on "Win32 (x86) Application")
!MESSAGE "ShiftLogicAtlDemo - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ShiftLogicAtlDemo - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\ShiftLogicAtlDemo.exe
InputPath=.\Debug\ShiftLogicAtlDemo.exe
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ShiftLogicAtlDemo - Win32 Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU"
# PROP BASE Intermediate_Dir "DebugU"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU"
# PROP Intermediate_Dir "DebugU"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "$(ONIROOT)\ShiftLogic\AnimationComponent\DefaultConfig" /I "$(ONIROOT)\ShiftLogic\ShiftLogicAtlDemo" /I "$(ONIROOT)\include" /I "$(ONIROOT)\bin" /I "$(ONIROOT)\mkl\include" /I "C:\Rhapsody40\Share\LangCpp" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_VAREX_UML_MACROS" /D "_OMINSTRUMENT" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD MTL /I "$(ONIROOT)\idl"
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OnUMLEso.lib IsDaeCOSolver.lib MSoxfinst.lib MSaomanim.lib MSomComAppl.lib wsock32.lib mkl_c.lib mkl_def.lib mkl_lapack.lib ShiftLogicDialogs.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"C:\DistComponents\ShiftLogic\AnimationComponent\DefaultConfig\AnimationComComponent.exe" /pdbtype:sept /libpath:"$(ONIROOT)\lib" /libpath:"$(ONIROOT)\mkl\ia32\lib" /libpath:"$(OMROOT)\LangCpp\lib"
# Begin Custom Build - Performing registration
OutDir=.\DebugU
TargetPath=\DistComponents\ShiftLogic\AnimationComponent\DefaultConfig\AnimationComComponent.exe
InputPath=\DistComponents\ShiftLogic\AnimationComponent\DefaultConfig\AnimationComComponent.exe
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode EXE on Windows 95 
	:end 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ShiftLogicAtlDemo - Win32 Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinSize"
# PROP BASE Intermediate_Dir "ReleaseMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinSize"
# PROP Intermediate_Dir "ReleaseMinSize"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\ShiftLogicAtlDemo.exe
InputPath=.\ReleaseMinSize\ShiftLogicAtlDemo.exe
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ShiftLogicAtlDemo - Win32 Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinDependency"
# PROP BASE Intermediate_Dir "ReleaseMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinDependency"
# PROP Intermediate_Dir "ReleaseMinDependency"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\ShiftLogicAtlDemo.exe
InputPath=.\ReleaseMinDependency\ShiftLogicAtlDemo.exe
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ShiftLogicAtlDemo - Win32 Unicode Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUMinSize"
# PROP BASE Intermediate_Dir "ReleaseUMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUMinSize"
# PROP Intermediate_Dir "ReleaseUMinSize"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\ShiftLogicAtlDemo.exe
InputPath=.\ReleaseUMinSize\ShiftLogicAtlDemo.exe
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode EXE on Windows 95 
	:end 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ShiftLogicAtlDemo - Win32 Unicode Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUMinDependency"
# PROP BASE Intermediate_Dir "ReleaseUMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUMinDependency"
# PROP Intermediate_Dir "ReleaseUMinDependency"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\ShiftLogicAtlDemo.exe
InputPath=.\ReleaseUMinDependency\ShiftLogicAtlDemo.exe
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode EXE on Windows 95 
	:end 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "ShiftLogicAtlDemo - Win32 Debug"
# Name "ShiftLogicAtlDemo - Win32 Unicode Debug"
# Name "ShiftLogicAtlDemo - Win32 Release MinSize"
# Name "ShiftLogicAtlDemo - Win32 Release MinDependency"
# Name "ShiftLogicAtlDemo - Win32 Unicode Release MinSize"
# Name "ShiftLogicAtlDemo - Win32 Unicode Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Actuator.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ActuatorClutchConnector.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Application.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Band_Brake.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\BrakeActuator.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Brakes.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CBrakeDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CDamper.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Chart.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Clutch.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Clutch_Schedule.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ClutchBase.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CMass.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Controller.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CRigidConnector.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CShiftDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CSpring.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CThrottleDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\DemoDrivetrain.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\DemoDrivetrain_task_0100ms.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\DemoDrivetrainApp.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\DemoDrivetrainSubsystem.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Driver.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Engine.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ExtApp.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ExtApp_task_0100ms.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ExtCar.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ExtCarSS.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Gear.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\GearInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\GUIModels.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\LookupTable.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\MainAnimationComponent.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Oneway_Clutch.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\PlanetaryCoupler.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Ravigneaux.cpp
# End Source File
# Begin Source File

SOURCE=.\RhapRegistery.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ShiftData.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ShiftLever.cpp
# End Source File
# Begin Source File

SOURCE=.\ShiftLogicAtlDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\ShiftLogicAtlDemo.idl
# ADD MTL /tlb ".\ShiftLogicAtlDemo.tlb" /h "ShiftLogicAtlDemo.h" /iid "ShiftLogicAtlDemo_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\ShiftLogicAtlDemo.rc
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\SimpleApp.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\SimpleApp_task_0100ms.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\SimpleGearbox.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\StandardModels.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\StdApp.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\StdApp_task_0100ms.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\StdCar.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\StdCarSS.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TestDrivetrain01.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TestDrivetrainApp.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TestDrivetrainApp_task_0100ms.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TestDrivetrainSS.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theApp.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theExtApp.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theExtApp2.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theSimpleApp.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theStdApp.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theTestApp.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Throttle.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Torque_Converter.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TransmissionControlModels.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TransmissionModels.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\UI.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Vehicle.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Vehicle5.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\VehicleModels.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Actuator.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ActuatorClutchConnector.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Application.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Band_Brake.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\BrakeActuator.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Brakes.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CBrakeDlg.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CDamper.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CFrame.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Chart.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Clutch.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Clutch_Schedule.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ClutchBase.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CMass.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Controller.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CRigidConnector.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CShiftDlg.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CSpring.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\CThrottleDlg.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\DemoDrivetrain.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\DemoDrivetrain_task_0100ms.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\DemoDrivetrainApp.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\DemoDrivetrainSubsystem.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Driver.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Engine.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ExtApp.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ExtApp_task_0100ms.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ExtCar.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ExtCarSS.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Gear.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\GearInfo.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\GUIModels.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\LookupTable.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\MainAnimationComponent.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Oneway_Clutch.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\PlanetaryCoupler.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Ravigneaux.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RhapRegistery.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ShiftData.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\ShiftLever.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\SimpleApp.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\SimpleApp_task_0100ms.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\SimpleGearbox.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\StandardModels.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\StdApp.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\StdApp_task_0100ms.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\StdCar.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\StdCarSS.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TestDrivetrain01.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TestDrivetrainApp.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TestDrivetrainApp_task_0100ms.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TestDrivetrainSS.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theApp.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theExtApp.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theExtApp2.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theSimpleApp.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theStdApp.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\theTestApp.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Throttle.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Torque_Converter.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TransmissionControlModels.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\TransmissionModels.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\UI.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Vehicle.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Vehicle5.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\VehicleModels.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\ShiftLogicAtlDemo.rgs
# End Source File
# End Group
# End Target
# End Project
