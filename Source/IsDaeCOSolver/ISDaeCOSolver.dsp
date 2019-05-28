# Microsoft Developer Studio Project File - Name="ISDaeCOSolver" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=ISDaeCOSolver - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ISDaeCOSolver.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ISDaeCOSolver.mak" CFG="ISDaeCOSolver - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ISDaeCOSolver - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ISDaeCOSolver - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ISDaeCOSolver - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ISDaeCOSolver - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ISDaeCOSolver - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ISDaeCOSolver - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/DistComponents/IsDaeCoSolver", HAAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ISDaeCOSolver - Win32 Debug"

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
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I ".\..\ONlr" /I ".\..\ONbias" /I ".\..\ONInterval" /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib .\..\bin\ONlr.lib .\..\bin\ONbias.lib .\..\bin\ONInterval.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:".\..\bin\ISDaeCOSolver.dll" /implib:".\..\bin\ISDaeCOSolver.lib" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=\DistComponents\bin\ISDaeCOSolver.dll
InputPath=\DistComponents\bin\ISDaeCOSolver.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "$(ONIROOT)\bin" /I "$(ONIROOT)\include" /I "$(ONIROOT)\ONInterval" /I "$(ONIROOT)\ONBias" /I "$(ONIROOT)\MKL\include" /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ONUMLLIB_EXPORTS" /D "_ONDAECOSOLVERLIB_EXPORTS" /D "notdef" /FD /GZ /c
# ADD MTL /I "$(ONIROOT)\idl"
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ONlr.lib ONbias.lib ONInterval.lib mkl_c.lib mkl_def.lib mkl_lapack.lib /nologo /subsystem:windows /dll /profile /map /debug /machine:I386 /out:"$(ONIROOT)\bin\ISDaeCOSolver.dll" /implib:"$(ONIROOT)\lib\ISDaeCOSolver.lib" /libpath:"$(ONIROOT)\lib" /libpath:"$(ONIROOT)\MKL\ia32\lib"
# Begin Custom Build - Performing registration
OutDir=.\DebugU
TargetPath=.\$(ONIROOT)\bin\ISDaeCOSolver.dll
InputPath=.\$(ONIROOT)\bin\ISDaeCOSolver.dll
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

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinSize"

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
# ADD CPP /nologo /MT /W3 /O1 /D "NDEBUG" /D "_MBCS" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\ISDaeCOSolver.dll
InputPath=.\ReleaseMinSize\ISDaeCOSolver.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinDependency"

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
# ADD CPP /nologo /MD /W3 /O1 /D "NDEBUG" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\ISDaeCOSolver.dll
InputPath=.\ReleaseMinDependency\ISDaeCOSolver.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUMinSize"
# PROP BASE Intermediate_Dir "ReleaseUMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUMinSize"
# PROP Intermediate_Dir "ReleaseUMinSize"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /O1 /I "$(ONIROOT)\include" /I "$(ONIROOT)\ONInterval" /I "$(ONIROOT)\ONBias" /I "$(ONIROOT)\MKL\include" /D "NDEBUG" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ONUMLLIB_EXPORTS" /D "_ONDAECOSOLVERLIB_EXPORTS" /D "notdef" /FD /c
# ADD MTL /I "$(ONIROOT)\idl"
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ONlr.lib ONbias.lib ONInterval.lib mkl_c.lib mkl_def.lib mkl_lapack.lib /nologo /subsystem:windows /dll /pdb:"$(ONIROOT)\bin\release\ISDaeCOSolver.pdb" /machine:I386 /out:"$(ONIROOT)\bin\release\ISDaeCOSolver.dll" /implib:"$(ONIROOT)\lib\ISDaeCOSolver.lib" /libpath:"$(ONIROOT)\lib" /libpath:"$(ONIROOT)\MKL\ia32\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinSize
TargetPath=.\$(ONIROOT)\bin\release\ISDaeCOSolver.dll
InputPath=.\$(ONIROOT)\bin\release\ISDaeCOSolver.dll
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

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinDependency"

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
# ADD CPP /nologo /MD /W3 /O2 /I ".\..\ONInterval" /I ".\..\ONBias" /I ".\..\MKL\include" /D "NDEBUG" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ONUMLLIB_EXPORTS" /D "_ONDAECOSOLVERLIB_EXPORTS" /D "notdef" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ONlr.lib ONbias.lib ONInterval.lib mkl_c.lib mkl_def.lib mkl_lapack.lib /nologo /subsystem:windows /dll /pdb:".\..\bin\Release\ISDaeCOSolver.pdb" /debug /machine:I386 /out:".\..\bin\Release\ISDaeCOSolver.dll" /implib:".\..\bin\Release\ISDaeCOSolver.lib" /libpath:".\..\bin\Release" /libpath:".\..\MKL\ia32\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinDependency
TargetPath=\DistComponents\bin\Release\ISDaeCOSolver.dll
InputPath=\DistComponents\bin\Release\ISDaeCOSolver.dll
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

# Name "ISDaeCOSolver - Win32 Debug"
# Name "ISDaeCOSolver - Win32 Unicode Debug"
# Name "ISDaeCOSolver - Win32 Release MinSize"
# Name "ISDaeCOSolver - Win32 Release MinDependency"
# Name "ISDaeCOSolver - Win32 Unicode Release MinSize"
# Name "ISDaeCOSolver - Win32 Unicode Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BandedInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\ConsistentInitialization.cpp

!IF  "$(CFG)" == "ISDaeCOSolver - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinDependency"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ConvergenceInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\IndexInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\IOnEventSink.cpp
# End Source File
# Begin Source File

SOURCE=.\IsCINlaEso.cpp
# End Source File
# Begin Source File

SOURCE=.\ISDaeCOSolver.cpp
# End Source File
# Begin Source File

SOURCE=.\ISDaeCOSolver.def
# End Source File
# Begin Source File

SOURCE=..\idl\ISDaeCOSolver.idl

!IF  "$(CFG)" == "ISDaeCOSolver - Win32 Debug"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Debug"

# ADD MTL /tlb "$(ONIROOT)\include\ISDaeCOSolver.tlb" /h "$(ONIROOT)\include\IsDaeCOSolver.h" /iid "$(ONIROOT)\bin\IsDaeCOSolver_i.c"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinDependency"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinSize"

# ADD MTL /tlb "$(ONIROOT)\include\ISDaeCOSolver.tlb" /h "$(ONIROOT)\include\IsDaeCOSolver.h" /iid "$(ONIROOT)\bin\IsDaeCOSolver_i.c"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ISDaeCOSolver.rc
# End Source File
# Begin Source File

SOURCE=.\IsDaeEso.cpp
# End Source File
# Begin Source File

SOURCE=.\IsDaeEsoCImpl.cpp
# End Source File
# Begin Source File

SOURCE=.\IsDaeEsoIImpl.cpp
# End Source File
# Begin Source File

SOURCE=.\IsInterval.cpp

!IF  "$(CFG)" == "ISDaeCOSolver - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinDependency"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\IsMatrix.cpp
# End Source File
# Begin Source File

SOURCE=.\IsNlaSolver.cpp
# End Source File
# Begin Source File

SOURCE=.\IsStepper.cpp
# End Source File
# Begin Source File

SOURCE=.\MatInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\ModelNavMaps.cpp
# End Source File
# Begin Source File

SOURCE=.\MSS.cpp

!IF  "$(CFG)" == "ISDaeCOSolver - Win32 Debug"

# ADD CPP /D "_USRDLL /GX"
# SUBTRACT CPP /D "_USRDLL" /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinDependency"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\OnAD.cpp
# End Source File
# Begin Source File

SOURCE=.\OnDataCollector.cpp
# End Source File
# Begin Source File

SOURCE=.\OnEnv.cpp
# End Source File
# Begin Source File

SOURCE=..\idl\OnInitialization.IDL

!IF  "$(CFG)" == "ISDaeCOSolver - Win32 Debug"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Debug"

# ADD MTL /I "$(ONIROOT)\bin" /h "$(ONIROOT)\include\OnInitialization.h" /iid "$(ONIROOT)\bin\OnInitialization_i.c"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinDependency"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\OnMapBSTR.cpp
# End Source File
# Begin Source File

SOURCE=.\OnModelBase.cpp
# End Source File
# Begin Source File

SOURCE=.\OnModelExec.cpp
# End Source File
# Begin Source File

SOURCE=.\OnTest.cpp
# End Source File
# Begin Source File

SOURCE=.\ReportInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\spallocate.c
# End Source File
# Begin Source File

SOURCE=.\sparseInterface.c
# End Source File
# Begin Source File

SOURCE=.\spbuild.c
# End Source File
# Begin Source File

SOURCE=.\spfactor.c
# End Source File
# Begin Source File

SOURCE=.\spoutput.c
# End Source File
# Begin Source File

SOURCE=.\spsolve.c
# End Source File
# Begin Source File

SOURCE=.\sputils.c
# End Source File
# Begin Source File

SOURCE=.\StateInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StepSizeInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\ToleranceInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\TransitionInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\triangularization.cpp

!IF  "$(CFG)" == "ISDaeCOSolver - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Release MinDependency"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "ISDaeCOSolver - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\VarInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\VirtualTimeInfo.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BandedInfo.h
# End Source File
# Begin Source File

SOURCE=.\ConsistentInitialization.h
# End Source File
# Begin Source File

SOURCE=.\ConvergenceInfo.h
# End Source File
# Begin Source File

SOURCE=..\include\EventBroadcast.h
# End Source File
# Begin Source File

SOURCE=.\IIsDaeModelImpl.h
# End Source File
# Begin Source File

SOURCE=.\IndexInfo.h
# End Source File
# Begin Source File

SOURCE=.\IOnEventSink.h
# End Source File
# Begin Source File

SOURCE=.\IOnUMLDaeEsoBase.h
# End Source File
# Begin Source File

SOURCE=.\IsCINlaEso.h
# End Source File
# Begin Source File

SOURCE=.\IsDaeEso.h
# End Source File
# Begin Source File

SOURCE=.\IsDaeEsoCImpl.h
# End Source File
# Begin Source File

SOURCE=.\IsDaeEsoIImpl.h
# End Source File
# Begin Source File

SOURCE=.\IsDaeEsoTImpl.h
# End Source File
# Begin Source File

SOURCE=.\IsInterval.h
# End Source File
# Begin Source File

SOURCE=.\IsMatrix.h
# End Source File
# Begin Source File

SOURCE=.\IsNlaSolver.h
# End Source File
# Begin Source File

SOURCE=.\IsStepper.h
# End Source File
# Begin Source File

SOURCE=.\MatInfo.h
# End Source File
# Begin Source File

SOURCE=.\ModelNavMaps.h
# End Source File
# Begin Source File

SOURCE=.\MSS.h
# End Source File
# Begin Source File

SOURCE=..\include\OmEventBroadcast.h
# End Source File
# Begin Source File

SOURCE=..\include\onad.h
# End Source File
# Begin Source File

SOURCE=..\include\OnDaeCOSolverExport.h
# End Source File
# Begin Source File

SOURCE=..\include\OnDaeCOSolverMacros.h
# End Source File
# Begin Source File

SOURCE=..\include\OnDaeCOSolverTypeDefs.h
# End Source File
# Begin Source File

SOURCE=..\include\OnDataCollector.h
# End Source File
# Begin Source File

SOURCE=..\include\OnEnv.h
# End Source File
# Begin Source File

SOURCE=..\include\OnMapBSTR.h
# End Source File
# Begin Source File

SOURCE=.\..\include\OnModelBase.h
# End Source File
# Begin Source File

SOURCE=.\OnModelExec.h
# End Source File
# Begin Source File

SOURCE=.\OnModelExecCP.h
# End Source File
# Begin Source File

SOURCE=.\OnTest.h
# End Source File
# Begin Source File

SOURCE=.\ReportInfo.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\sparseInterface.h
# End Source File
# Begin Source File

SOURCE=.\spconfig.h
# End Source File
# Begin Source File

SOURCE=.\spdefs.h
# End Source File
# Begin Source File

SOURCE=.\spmatrix.h
# End Source File
# Begin Source File

SOURCE=..\include\StateInfo.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\StepSizeInfo.h
# End Source File
# Begin Source File

SOURCE=.\ToleranceInfo.h
# End Source File
# Begin Source File

SOURCE=..\include\TransitionInfo.h
# End Source File
# Begin Source File

SOURCE=..\include\triangularization.h
# End Source File
# Begin Source File

SOURCE=.\VarInfo.h
# End Source File
# Begin Source File

SOURCE=.\VirtualTimeInfo.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\IsCINlaEso.rgs
# End Source File
# Begin Source File

SOURCE=.\IsDaeEsoCImpl.rgs
# End Source File
# Begin Source File

SOURCE=.\IsDaeEsoIImpl.rgs
# End Source File
# Begin Source File

SOURCE=.\IsDaeSolver.rgs
# End Source File
# Begin Source File

SOURCE=.\IsMatrix.rgs
# End Source File
# Begin Source File

SOURCE=.\IsNlaSolver.rgs
# End Source File
# Begin Source File

SOURCE=.\OnEnv.rgs
# End Source File
# Begin Source File

SOURCE=.\OnModelExec.rgs
# End Source File
# Begin Source File

SOURCE=.\OnTest.rgs
# End Source File
# End Group
# End Target
# End Project
