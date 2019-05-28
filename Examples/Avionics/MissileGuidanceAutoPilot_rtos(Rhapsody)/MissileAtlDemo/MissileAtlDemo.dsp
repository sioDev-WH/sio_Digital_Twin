# Microsoft Developer Studio Project File - Name="MissileAtlDemo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MissileAtlDemo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MissileAtlDemo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MissileAtlDemo.mak" CFG="MissileAtlDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MissileAtlDemo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "MissileAtlDemo - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "MissileAtlDemo - Win32 Release MinSize" (based on "Win32 (x86) Application")
!MESSAGE "MissileAtlDemo - Win32 Release MinDependency" (based on "Win32 (x86) Application")
!MESSAGE "MissileAtlDemo - Win32 Unicode Release MinSize" (based on "Win32 (x86) Application")
!MESSAGE "MissileAtlDemo - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MissileAtlDemo - Win32 Debug"

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
# ADD CPP /nologo /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
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
TargetPath=.\Debug\MissileAtlDemo.exe
InputPath=.\Debug\MissileAtlDemo.exe
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "MissileAtlDemo - Win32 Unicode Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "$(ONIROOT)\VTK\vtk40\include\vtk" /I "$(ONIROOT)\AvionicsDemo\Avionics_6\DefaultComponent\DefaultConfig" /I "$(ONIROOT)\AvionicsDemo\Avionics_6\MissileAtlDemo" /I "$(ONIROOT)\include" /I "$(ONIROOT)\bin" /I "$(ONIROOT)\mkl\include" /I "$(OMROOT)\LangCpp\\" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_STL_UML_MACROS" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD MTL /I "$(ONIROOT)\idl"
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OnUMLEso.lib IsDaeCOSolver.lib MSoxfinst.lib MSaomanim.lib MSomComAppl.lib wsock32.lib mkl_c.lib mkl_def.lib mkl_lapack.lib vtkCommon.lib vtkFiltering.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkParallel.lib vtkpng.lib vtkRendering.lib vtkzlib.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"c:\DistComponents\AvionicsDemo\AnimationComComponent\DefaultConfig\AnimationComComponent.exe" /pdbtype:sept /libpath:"$(ONIROOT)\VTK\vtk40\lib\vtk" /libpath:"$(ONIROOT)\lib" /libpath:"$(ONIROOT)\mkl\ia32\lib" /libpath:"$(OMROOT)\LangCpp\lib"
# Begin Custom Build - Performing registration
OutDir=.\DebugU
TargetPath=\DistComponents\AvionicsDemo\AnimationComComponent\DefaultConfig\AnimationComComponent.exe
InputPath=\DistComponents\AvionicsDemo\AnimationComComponent\DefaultConfig\AnimationComComponent.exe
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

!ELSEIF  "$(CFG)" == "MissileAtlDemo - Win32 Release MinSize"

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
TargetPath=.\ReleaseMinSize\MissileAtlDemo.exe
InputPath=.\ReleaseMinSize\MissileAtlDemo.exe
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "MissileAtlDemo - Win32 Release MinDependency"

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
TargetPath=.\ReleaseMinDependency\MissileAtlDemo.exe
InputPath=.\ReleaseMinDependency\MissileAtlDemo.exe
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "MissileAtlDemo - Win32 Unicode Release MinSize"

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
TargetPath=.\ReleaseUMinSize\MissileAtlDemo.exe
InputPath=.\ReleaseUMinSize\MissileAtlDemo.exe
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

!ELSEIF  "$(CFG)" == "MissileAtlDemo - Win32 Unicode Release MinDependency"

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
# ADD BASE CPP /nologo /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /O1 /I "$(ONIROOT)\VTK\vtk40\include\vtk" /I "$(ONIROOT)\AvionicsDemo\AnimationComComponent\DefaultConfig" /I "$(ONIROOT)\AvionicsDemo\MissileAtlDemo" /I "$(ONIROOT)\include" /I "$(ONIROOT)\bin" /I "$(ONIROOT)\mkl\include" /I "$(OMROOT)\LangCpp" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
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
TargetPath=.\ReleaseUMinDependency\MissileAtlDemo.exe
InputPath=.\ReleaseUMinDependency\MissileAtlDemo.exe
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

# Name "MissileAtlDemo - Win32 Debug"
# Name "MissileAtlDemo - Win32 Unicode Debug"
# Name "MissileAtlDemo - Win32 Release MinSize"
# Name "MissileAtlDemo - Win32 Release MinDependency"
# Name "MissileAtlDemo - Win32 Unicode Release MinSize"
# Name "MissileAtlDemo - Win32 Unicode Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\aeroComposition.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\aeroDynamics.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\aeroFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\aeroPort.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AirframePkg.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\Animation.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\App.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\App_task_0001ms.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\App_task_0010ms.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\App_task_0040ms.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AppAirFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AtmoHeightPort.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AtmoPort.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\atmosphere.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AutoPilot.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AutoPilotCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AutopilotPkg.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AvionicsPkg.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\bodyDynamics.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\CChartDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\Chart.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\ControlDesigner.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\Default.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\DisplayPkg.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\engineDynamics.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\EstimatorLOS.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\EstimatorLOSCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\EstimatorVc.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\EstimatorVcCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\finDynamics.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\FinPort.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\GimbalController.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\GimbalControllerCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\GuidanceLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\GuidancePkg.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\LibraryPkg.cpp
# End Source File
# Begin Source File

SOURCE=.\MissileAtlDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\MissileAtlDemo.idl
# ADD MTL /tlb ".\MissileAtlDemo.tlb" /h "MissileAtlDemo.h" /iid "MissileAtlDemo_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\MissileAtlDemo.rc
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\RateStabilizationFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\RateStabilizationFilterCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\RhapRegistery.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\Target.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\TargetPkg.cpp
# End Source File
# Begin Source File

SOURCE=.\theTest.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\TrackingSubsystem.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\TrackingSubsystemCoeff.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\TrackingSubsystemPkg.cpp
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\Units.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\aeroComposition.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\aeroDynamics.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\aeroFrame.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\aeroPort.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AirframePkg.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\Animation.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\App.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\App_task_0001ms.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\App_task_0010ms.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\App_task_0040ms.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AppAirFrame.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AtmoHeightPort.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AtmoPort.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\atmosphere.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AutoPilot.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AutoPilotCoeff.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AutopilotPkg.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\AvionicsPkg.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\bodyDynamics.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\CChartDlg.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\Chart.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\ControlDesigner.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\Default.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\DisplayPkg.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\engineDynamics.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\EstimatorLOS.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\EstimatorLOSCoeff.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\EstimatorVc.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\EstimatorVcCoeff.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\finDynamics.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\FinPort.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\GimbalController.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\GimbalControllerCoeff.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\GuidanceLogic.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\GuidancePkg.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\LibraryPkg.h
# End Source File
# Begin Source File

SOURCE=.\matrix.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\RateStabilizationFilter.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\RateStabilizationFilterCoeff.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\RhapRegistery.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\Target.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\TargetPkg.h
# End Source File
# Begin Source File

SOURCE=.\theTest.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\TrackingSubsystem.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\TrackingSubsystemCoeff.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\TrackingSubsystemPkg.h
# End Source File
# Begin Source File

SOURCE=..\DefaultComponent\DefaultConfig\Units.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\MissileAtlDemo.rgs
# End Source File
# End Group
# End Target
# End Project
