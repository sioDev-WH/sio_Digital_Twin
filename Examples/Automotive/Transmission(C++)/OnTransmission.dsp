# Microsoft Developer Studio Project File - Name="OnTransmission" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=OnTransmission - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "OnTransmission.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OnTransmission.mak" CFG="OnTransmission - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OnTransmission - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OnTransmission - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OnTransmission - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OnTransmission - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OnTransmission - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OnTransmission - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "OnTransmission - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
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
TargetPath=.\Debug\OnTransmission.dll
InputPath=.\Debug\OnTransmission.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "OnTransmission - Win32 Unicode Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /ZI /Od /I ".\\" /I ".\..\IsDaeCOSolver" /I ".\..\OnUMLEso" /I ".\..\bin" /I ".\..\CgOnTransmission" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_SIM_ARTISAN" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib IsDaeCOSolver.lib OnUMLEso.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:".\..\bin\OnTransmission.dll" /implib:".\..\bin\OnTransmission.lib" /pdbtype:sept /libpath:".\..\bin"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\DebugU
TargetPath=\DistComponents\bin\OnTransmission.dll
InputPath=\DistComponents\bin\OnTransmission.dll
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

!ELSEIF  "$(CFG)" == "OnTransmission - Win32 Release MinSize"

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
TargetPath=.\ReleaseMinSize\OnTransmission.dll
InputPath=.\ReleaseMinSize\OnTransmission.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "OnTransmission - Win32 Release MinDependency"

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
TargetPath=.\ReleaseMinDependency\OnTransmission.dll
InputPath=.\ReleaseMinDependency\OnTransmission.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "OnTransmission - Win32 Unicode Release MinSize"

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
TargetPath=.\ReleaseUMinSize\OnTransmission.dll
InputPath=.\ReleaseUMinSize\OnTransmission.dll
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

!ELSEIF  "$(CFG)" == "OnTransmission - Win32 Unicode Release MinDependency"

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
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\OnTransmission.dll
InputPath=.\ReleaseUMinDependency\OnTransmission.dll
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

# Name "OnTransmission - Win32 Debug"
# Name "OnTransmission - Win32 Unicode Debug"
# Name "OnTransmission - Win32 Release MinSize"
# Name "OnTransmission - Win32 Release MinDependency"
# Name "OnTransmission - Win32 Unicode Release MinSize"
# Name "OnTransmission - Win32 Unicode Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\CgOnTransmission\Actuator.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\ActuatorClutchConnector.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Band_Break.cpp
# End Source File
# Begin Source File

SOURCE=.\BroadcastSource.cpp
# End Source File
# Begin Source File

SOURCE=.\CBroadcastTest.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Clutch.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Clutch_Schedule.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\ClutchBase.cpp
# End Source File
# Begin Source File

SOURCE=.\COneClutch.cpp
# End Source File
# Begin Source File

SOURCE=.\COnTransModelFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Controller.cpp
# End Source File
# Begin Source File

SOURCE=.\Damper.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Engine.cpp
# End Source File
# Begin Source File

SOURCE=.\Frame.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Gear.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\GearInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\GearRatio.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\LookupTable.cpp
# End Source File
# Begin Source File

SOURCE=.\Mass.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Oneway_Clutch.cpp
# End Source File
# Begin Source File

SOURCE=.\OneWayMSF.cpp
# End Source File
# Begin Source File

SOURCE=.\OnRavMSF.cpp
# End Source File
# Begin Source File

SOURCE=.\OnTransmission.cpp
# End Source File
# Begin Source File

SOURCE=.\OnTransmission.def
# End Source File
# Begin Source File

SOURCE=.\OnTransmission.idl
# ADD MTL /tlb ".\OnTransmission.tlb" /h "OnTransmission.h" /iid "OnTransmission_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\OnTransmission.rc
# End Source File
# Begin Source File

SOURCE=.\OnTransMSF.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\PlanetaryCoupler.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Ravigneaux.cpp
# End Source File
# Begin Source File

SOURCE=.\RigidConnector.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\ShiftData.cpp
# End Source File
# Begin Source File

SOURCE=.\SignalActuator.cpp
# End Source File
# Begin Source File

SOURCE=.\Spring.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Torque_Converter.cpp
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Vehicle.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\CgOnTransmission\Actuator.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\ActuatorClutchConnector.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Band_Break.h
# End Source File
# Begin Source File

SOURCE=.\BroadcastSource.h
# End Source File
# Begin Source File

SOURCE=.\CBroadcastTest.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Clutch.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Clutch_Schedule.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\ClutchBase.h
# End Source File
# Begin Source File

SOURCE=.\CommonMacros.h
# End Source File
# Begin Source File

SOURCE=.\COneClutch.h
# End Source File
# Begin Source File

SOURCE=.\COnTransModelFactory.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Controller.h
# End Source File
# Begin Source File

SOURCE=.\Damper.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Engine.h
# End Source File
# Begin Source File

SOURCE=.\EventBroadcast.h
# End Source File
# Begin Source File

SOURCE=.\Frame.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Gear.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\GearInfo.h
# End Source File
# Begin Source File

SOURCE=.\GearRatio.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\LookupTable.h
# End Source File
# Begin Source File

SOURCE=.\Mass.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Oneway_Clutch.h
# End Source File
# Begin Source File

SOURCE=.\OneWayMSF.h
# End Source File
# Begin Source File

SOURCE=.\OnRavMSF.h
# End Source File
# Begin Source File

SOURCE=.\OnTransMSF.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\PlanetaryCoupler.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Ravigneaux.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RigidConnector.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\ShiftData.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\ShiftLogic.h
# End Source File
# Begin Source File

SOURCE=.\SignalActuator.h
# End Source File
# Begin Source File

SOURCE=.\Spring.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Torque_Converter.h
# End Source File
# Begin Source File

SOURCE=..\CgOnTransmission\Vehicle.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\CBroadcastTest.rgs
# End Source File
# Begin Source File

SOURCE=.\COnTransModelFactory.rgs
# End Source File
# End Group
# End Target
# End Project
