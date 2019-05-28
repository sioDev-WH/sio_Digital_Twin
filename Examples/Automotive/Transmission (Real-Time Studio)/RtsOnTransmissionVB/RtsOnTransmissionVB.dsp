# Microsoft Developer Studio Project File - Name="RtsOnTransmissionVB" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=RtsOnTransmissionVB - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RtsOnTransmissionVB.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RtsOnTransmissionVB.mak" CFG="RtsOnTransmissionVB - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RtsOnTransmissionVB - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RtsOnTransmissionVB - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RtsOnTransmissionVB - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RtsOnTransmissionVB - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RtsOnTransmissionVB - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RtsOnTransmissionVB - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RtsOnTransmissionVB - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I ".\..\RtsOnTransmission" /I ".\..\RtsTransmission" /I ".\..\OnUMLEso" /I ".\..\IsDaeCOSolver" /I "C:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 OnUMLEso.lib IsDaeCOSolver.lib SMHarnessD.lib RtsOnTransmission.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept /libpath:".\..\bin" /libpath:"c:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen\\"
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\RtsOnTransmissionVB.dll
InputPath=.\Debug\RtsOnTransmissionVB.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RtsOnTransmissionVB - Win32 Unicode Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /ZI /Od /I ".\..\RtsOnTransmission" /I ".\..\RtsTransmission" /I "$(ONIROOT)\include" /I "$(ONIROOT)\bin" /I "C:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# ADD MTL /I "$(ONIROOT)\idl"
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OnUMLEso.lib IsDaeCOSolver.lib SMHarnessD.lib RtsOnTransmission.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:".\..\bin\RtsOnTransmissionVB.dll" /implib:".\..\bin\RtsOnTransmissionVB.lib" /pdbtype:sept /libpath:"$(ONIROOT)\lib" /libpath:"c:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen\\"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\DebugU
TargetPath=\DistComponents\bin\RtsOnTransmissionVB.dll
InputPath=\DistComponents\bin\RtsOnTransmissionVB.dll
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

!ELSEIF  "$(CFG)" == "RtsOnTransmissionVB - Win32 Release MinSize"

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
# ADD CPP /nologo /MT /W3 /O1 /I ".\..\RtsOnTransmission" /I ".\..\RtsTransmission" /I ".\..\OnUMLEso" /I ".\..\IsDaeCOSolver" /I "C:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OnUMLEso.lib IsDaeCOSolver.lib SMHarnessD.lib RtsOnTransmission.lib /nologo /subsystem:windows /dll /machine:I386 /libpath:".\..\bin" /libpath:"c:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen\\"
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\RtsOnTransmissionVB.dll
InputPath=.\ReleaseMinSize\RtsOnTransmissionVB.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RtsOnTransmissionVB - Win32 Release MinDependency"

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
# ADD CPP /nologo /MT /W3 /O1 /I ".\..\RtsOnTransmission" /I ".\..\RtsTransmission" /I ".\..\OnUMLEso" /I ".\..\IsDaeCOSolver" /I "C:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OnUMLEso.lib IsDaeCOSolver.lib SMHarnessD.lib RtsOnTransmission.lib /nologo /subsystem:windows /dll /machine:I386 /libpath:".\..\bin" /libpath:"c:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen\\"
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\RtsOnTransmissionVB.dll
InputPath=.\ReleaseMinDependency\RtsOnTransmissionVB.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "RtsOnTransmissionVB - Win32 Unicode Release MinSize"

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
# ADD CPP /nologo /MT /W3 /O1 /I ".\..\RtsOnTransmission" /I ".\..\RtsTransmission" /I ".\..\OnUMLEso" /I ".\..\IsDaeCOSolver" /I "C:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OnUMLEso.lib IsDaeCOSolver.lib SMHarnessD.lib RtsOnTransmission.lib /nologo /subsystem:windows /dll /machine:I386 /libpath:".\..\bin" /libpath:"c:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen\\"
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\RtsOnTransmissionVB.dll
InputPath=.\ReleaseUMinSize\RtsOnTransmissionVB.dll
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

!ELSEIF  "$(CFG)" == "RtsOnTransmissionVB - Win32 Unicode Release MinDependency"

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
# ADD CPP /nologo /MT /W3 /O1 /I ".\..\RtsOnTransmission" /I ".\..\RtsTransmission" /I ".\..\OnUMLEso" /I ".\..\IsDaeCOSolver" /I "C:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OnUMLEso.lib IsDaeCOSolver.lib SMHarnessD.lib RtsOnTransmission.lib /nologo /subsystem:windows /dll /machine:I386 /libpath:".\..\bin" /libpath:"c:\Program Files\ARTiSAN Software Tools\ARTiSAN Real-time Studio\System\CppGen\\"
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\RtsOnTransmissionVB.dll
InputPath=.\ReleaseUMinDependency\RtsOnTransmissionVB.dll
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

# Name "RtsOnTransmissionVB - Win32 Debug"
# Name "RtsOnTransmissionVB - Win32 Unicode Debug"
# Name "RtsOnTransmissionVB - Win32 Release MinSize"
# Name "RtsOnTransmissionVB - Win32 Release MinDependency"
# Name "RtsOnTransmissionVB - Win32 Unicode Release MinSize"
# Name "RtsOnTransmissionVB - Win32 Unicode Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\OnDefaultCImpl.cpp
# End Source File
# Begin Source File

SOURCE=.\RtsOnTransmissionVB.cpp
# End Source File
# Begin Source File

SOURCE=.\RtsOnTransmissionVB.def
# End Source File
# Begin Source File

SOURCE=.\RtsOnTransmissionVB.idl
# ADD MTL /tlb ".\RtsOnTransmissionVB.tlb" /h "RtsOnTransmissionVB.h" /iid "RtsOnTransmissionVB_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\RtsOnTransmissionVB.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\vbActuator.cpp
# End Source File
# Begin Source File

SOURCE=.\vbBand_Brake.cpp
# End Source File
# Begin Source File

SOURCE=.\vbBrakeActuator.cpp
# End Source File
# Begin Source File

SOURCE=.\vbClutch.cpp
# End Source File
# Begin Source File

SOURCE=.\vbComposite.cpp
# End Source File
# Begin Source File

SOURCE=.\vbDamper.cpp
# End Source File
# Begin Source File

SOURCE=.\vbEngine.cpp
# End Source File
# Begin Source File

SOURCE=.\vbFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\vbMass.cpp
# End Source File
# Begin Source File

SOURCE=.\vbOneway_Clutch.cpp
# End Source File
# Begin Source File

SOURCE=.\vbRavigneaux.cpp
# End Source File
# Begin Source File

SOURCE=.\vbSpring.cpp
# End Source File
# Begin Source File

SOURCE=.\vbTorque_Converter.cpp
# End Source File
# Begin Source File

SOURCE=.\vbVehicle.cpp
# End Source File
# Begin Source File

SOURCE=.\vbVehicle2.cpp
# End Source File
# Begin Source File

SOURCE=.\vbVehicle5.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\OnDefaultCImpl.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\vbActuator.h
# End Source File
# Begin Source File

SOURCE=.\vbBand_Brake.h
# End Source File
# Begin Source File

SOURCE=.\vbBase.h
# End Source File
# Begin Source File

SOURCE=.\vbBrakeActuator.h
# End Source File
# Begin Source File

SOURCE=.\vbClutch.h
# End Source File
# Begin Source File

SOURCE=.\vbComposite.h
# End Source File
# Begin Source File

SOURCE=.\vbDamper.h
# End Source File
# Begin Source File

SOURCE=.\vbEngine.h
# End Source File
# Begin Source File

SOURCE=.\vbFrame.h
# End Source File
# Begin Source File

SOURCE=.\vbMass.h
# End Source File
# Begin Source File

SOURCE=.\vbOneway_Clutch.h
# End Source File
# Begin Source File

SOURCE=.\vbRavigneaux.h
# End Source File
# Begin Source File

SOURCE=.\vbSpring.h
# End Source File
# Begin Source File

SOURCE=.\vbTorque_Converter.h
# End Source File
# Begin Source File

SOURCE=.\vbVehicle.h
# End Source File
# Begin Source File

SOURCE=.\vbVehicle2.h
# End Source File
# Begin Source File

SOURCE=.\vbVehicle5.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\vbActuator.rgs
# End Source File
# Begin Source File

SOURCE=.\vbBand_Brake.rgs
# End Source File
# Begin Source File

SOURCE=.\vbBrakeActuator.rgs
# End Source File
# Begin Source File

SOURCE=.\vbClutch.rgs
# End Source File
# Begin Source File

SOURCE=.\vbComposite.rgs
# End Source File
# Begin Source File

SOURCE=.\vbDamper.rgs
# End Source File
# Begin Source File

SOURCE=.\vbEngine.rgs
# End Source File
# Begin Source File

SOURCE=.\vbFrame.rgs
# End Source File
# Begin Source File

SOURCE=.\vbGear.rgs
# End Source File
# Begin Source File

SOURCE=.\vbMass.rgs
# End Source File
# Begin Source File

SOURCE=.\vbOneway_Clutch.rgs
# End Source File
# Begin Source File

SOURCE=.\vbPlanetaryCoupler.rgs
# End Source File
# Begin Source File

SOURCE=.\vbRavigneaux.rgs
# End Source File
# Begin Source File

SOURCE=.\vbSpring.rgs
# End Source File
# Begin Source File

SOURCE=.\vbTorque_Converter.rgs
# End Source File
# Begin Source File

SOURCE=.\vbVehicle.rgs
# End Source File
# Begin Source File

SOURCE=.\vbVehicle2.rgs
# End Source File
# Begin Source File

SOURCE=.\vbVehicle5.rgs
# End Source File
# End Group
# End Target
# End Project
