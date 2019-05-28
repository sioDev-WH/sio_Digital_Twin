# Microsoft Developer Studio Project File - Name="GuidanceApp2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=GuidanceApp2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GuidanceApp2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GuidanceApp2.mak" CFG="GuidanceApp2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GuidanceApp2 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "GuidanceApp2 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GuidanceApp2 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "GuidanceApp2 - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ  /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "C:\Rhapsody40\GuidanceSystem\GuidanceApp2" /I "C:\Rhapsody40\GuidanceSystem\AnimationComponent\DefaultConfig" /I "c:\Distcomponents\IsDaeCOSolver" /I "c:\Distcomponents\bin" /I "c:\Distcomponents\CommonHeader" /I "c:\Distcomponents\OnUMLEso" /I "C:\Rhapsody40\Share\LangCpp" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_UNICODE" /D "_SIM_ARTISAN" /D "_VAREX_UML_MACROS" /D "_OMINSTRUMENT" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib    OnUMLEso.lib IsDaeCOSolver.lib MSoxfinst.lib MSaomanim.lib MSomComAppl.lib wsock32.lib /nologo /subsystem:console /debug /machine:I386 /out:"C:\Rhapsody40\GuidanceSystem\AnimationComponent\DefaultConfig\AnimationComponent.exe" /pdbtype:sept /libpath:"c:\distcomponents\bin" /libpath:"C:\Rhapsody40\Share\LangCpp\lib"

!ENDIF 

# Begin Target

# Name "GuidanceApp2 - Win32 Release"
# Name "GuidanceApp2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AeroCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AeroDynamics.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AirFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AirFrameAutoPilotSystem.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AtmoCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Atmosphere.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AutoPilot.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AutoPilotCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\BodyDynamics.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\BodyDynamicsCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\FinActuator.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\FinActuatorCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Guidance.cpp
# End Source File
# Begin Source File

SOURCE=.\GuidanceApp2.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\GuidancePkg.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\myFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\On1DConn.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\On3DConn.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnConnector_On1DConn.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnConnector_On3DConn.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnModel_AeroDynamics.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnModel_AirFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnModel_BodyDynamics.cpp
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnModel_FinActuator.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AeroCoeff.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AeroDynamics.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AirFrame.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AirFrameAutoPilotSystem.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AtmoCoeff.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Atmosphere.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AutoPilot.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\AutoPilotCoeff.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\BodyDynamics.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\BodyDynamicsCoeff.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Default.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\FinActuator.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\FinActuatorCoeff.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\Guidance.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\GuidancePkg.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\myFactory.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\On1DConn.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\On3DConn.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnConnector_On1DConn.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnConnector_On3DConn.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnModel_AeroDynamics.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnModel_AirFrame.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnModel_BodyDynamics.h
# End Source File
# Begin Source File

SOURCE=..\AnimationComponent\DefaultConfig\OnModel_FinActuator.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
