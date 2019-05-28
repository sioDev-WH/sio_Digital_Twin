# Microsoft Developer Studio Project File - Name="RtsOnTransmission" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=RtsOnTransmission - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RtsOnTransmission.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RtsOnTransmission.mak" CFG="RtsOnTransmission - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RtsOnTransmission - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RtsOnTransmission - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RtsOnTransmission - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RtsOnTransmission - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RtsOnTransmission - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RtsOnTransmission - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RtsOnTransmission - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I ".\..\..\CgOnTransmission" /I ".\..\..\OnTransmission" /I ".\..\..\CommonHeader" /I ".\..\..\OnUMLEso" /I ".\..\..\IsDaeCOSolver" /I "C:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_SIM_ARTISAN" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\RtsOnTransmission.dll
InputPath=.\Debug\RtsOnTransmission.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RtsOnTransmission - Win32 Unicode Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "$(ONIROOT)\include" /I "$(ONIROOT)\bin" /I "C:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen" /I ".\..\RtsOnTransmission\\" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_SIM_ARTISAN" /D "_RTSONTRANSMISSIONLIB_EXPORTS" /D "RTS_SIMULATION" /Yu"stdafx.h" /FD /GZ /c
# ADD MTL /I "$(ONIROOT)\idl"
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OnUMLEso.lib IsDaeCOSolver.lib SMHarnessD.lib /nologo /subsystem:windows /dll /debug /machine:I386 /include:"_RtsStartTimers@0" /out:".\..\bin\RtsOnTransmission.dll" /implib:".\..\bin\RtsOnTransmission.lib" /pdbtype:sept /libpath:"c:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen\\" /libpath:"$(ONIROOT)\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\DebugU
TargetPath=\DistComponents\bin\RtsOnTransmission.dll
InputPath=\DistComponents\bin\RtsOnTransmission.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RtsOnTransmission - Win32 Release MinSize"

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
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\RtsOnTransmission.dll
InputPath=.\ReleaseMinSize\RtsOnTransmission.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RtsOnTransmission - Win32 Release MinDependency"

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
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\RtsOnTransmission.dll
InputPath=.\ReleaseMinDependency\RtsOnTransmission.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RtsOnTransmission - Win32 Unicode Release MinSize"

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
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\RtsOnTransmission.dll
InputPath=.\ReleaseUMinSize\RtsOnTransmission.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RtsOnTransmission - Win32 Unicode Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUMinDependency"
# PROP BASE Intermediate_Dir "ReleaseUMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUMinDependency"
# PROP Intermediate_Dir "ReleaseUMinDependency"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /O2 /I "$(ONIROOT)\include" /I "$(ONIROOT)\bin" /I "C:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen" /I ".\..\RtsOnTransmission\\" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_SIM_ARTISAN" /D "_RTSONTRANSMISSIONLIB_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OnUMLEso.lib IsDaeCOSolver.lib /nologo /subsystem:windows /dll /pdb:".\..\bin\Release\RtsOnTransmission.pdb" /debug /machine:I386 /out:".\..\bin\Release\RtsOnTransmission.dll" /implib:".\..\bin\Release\RtsOnTransmission.lib" /libpath:"c:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen\\" /libpath:".\..\bin\Release"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinDependency
TargetPath=\DistComponents\bin\Release\RtsOnTransmission.dll
InputPath=\DistComponents\bin\Release\RtsOnTransmission.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "RtsOnTransmission - Win32 Debug"
# Name "RtsOnTransmission - Win32 Unicode Debug"
# Name "RtsOnTransmission - Win32 Release MinSize"
# Name "RtsOnTransmission - Win32 Release MinDependency"
# Name "RtsOnTransmission - Win32 Unicode Release MinSize"
# Name "RtsOnTransmission - Win32 Unicode Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\..\RtsTransmission\Actuator.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\ActuatorClutchConnector.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Band_Break.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\BrakeActuator.cpp
# End Source File
# Begin Source File

SOURCE=.\BrakeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Brakes.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car1.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car2.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car3.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car5.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car_app.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car_app1.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car_app2.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car_app3.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car_app5.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\CDamper.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\CFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Chart.cpp
# End Source File
# Begin Source File

SOURCE=.\ChartDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Clutch.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Clutch_Schedule.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\ClutchBase.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\CMass.cpp
# End Source File
# Begin Source File

SOURCE=.\COnTestHarness.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Controller.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\CSpring.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\demo1.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\demo1_app.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\demo1_app1.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Demo_ECM.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Demo_ECM_app.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Demo_ECMSD.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Demo_ECMSD_app.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\demotest.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\demotest_app.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Engine.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Gear.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\GearInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\leadVehicleSim.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\LookupTable.cpp
# End Source File
# Begin Source File

SOURCE=.\OnChart.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Oneway_Clutch.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\PlanetaryCoupler.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Ravigneaux.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\RigidConnector.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\RtsFactory.cpp

!IF  "$(CFG)" == "RtsOnTransmission - Win32 Debug"

!ELSEIF  "$(CFG)" == "RtsOnTransmission - Win32 Unicode Debug"

# ADD CPP /Yu

!ELSEIF  "$(CFG)" == "RtsOnTransmission - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "RtsOnTransmission - Win32 Release MinDependency"

!ELSEIF  "$(CFG)" == "RtsOnTransmission - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "RtsOnTransmission - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RtsOnTransmission.cpp
# End Source File
# Begin Source File

SOURCE=.\RtsOnTransmission.def
# End Source File
# Begin Source File

SOURCE=.\RtsOnTransmission.idl
# ADD MTL /tlb ".\RtsOnTransmission.tlb" /h "RtsOnTransmission.h" /iid "RtsOnTransmission_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\RtsOnTransmission.rc
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\ShiftData.cpp
# End Source File
# Begin Source File

SOURCE=.\ShiftDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\ShiftLever.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\SimpleCar1.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\SimpleCar1_app.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\SimpleController.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\simpleGearbox.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\TestHarness.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Throttle.cpp
# End Source File
# Begin Source File

SOURCE=.\ThrottleDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Torque_Converter.cpp
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Vehicle.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Vehicle2.cpp
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Vehicle5.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\..\RtsTransmission\Actuator.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\ActuatorClutchConnector.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\AppHarness.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Band_Break.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\BrakeActuator.h
# End Source File
# Begin Source File

SOURCE=.\BrakeDlg.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Brakes.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car1.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car2.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car3.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car5.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car_app.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car_app1.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car_app2.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car_app3.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Car_app5.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\CDamper.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\CFrame.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Chart.h
# End Source File
# Begin Source File

SOURCE=.\ChartDlg.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Clutch.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Clutch_Schedule.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\ClutchBase.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\CMass.h
# End Source File
# Begin Source File

SOURCE=.\COnTestHarness.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Controller.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\CSpring.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\demo1.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\demo1_app.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\demo1_app1.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Demo_ECM.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Demo_ECM_app.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Demo_ECMSD.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Demo_ECMSD_app.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\demotest.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\demotest_app.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Engine.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Gear.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\GearInfo.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\leadVehicleSim.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\LookupTable.h
# End Source File
# Begin Source File

SOURCE=.\OnChart.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Oneway_Clutch.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\PlanetaryCoupler.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Ravigneaux.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\RigidConnector.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\ShiftData.h
# End Source File
# Begin Source File

SOURCE=.\ShiftDlg.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\ShiftLever.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\ShiftLogic.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\SimpleCar1.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\SimpleCar1_app.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\SimpleController.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\simpleGearbox.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\TestHarness.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Throttle.h
# End Source File
# Begin Source File

SOURCE=.\ThrottleDlg.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Torque_Converter.h
# End Source File
# Begin Source File

SOURCE=.\..\RtsTransmission\Vehicle.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Vehicle2.h
# End Source File
# Begin Source File

SOURCE=..\RtsTransmission\Vehicle5.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\COnTestHarness.rgs
# End Source File
# Begin Source File

SOURCE=.\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\OnChart.rgs
# End Source File
# End Group
# End Target
# End Project
