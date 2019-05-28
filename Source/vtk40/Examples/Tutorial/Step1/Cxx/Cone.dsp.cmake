# Microsoft Developer Studio Project File - Name="pcbuilder" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# CM DSP Header file
# This file is read by the build system of cm, and is used as the top part of
# a microsoft project dsp header file
# IF this is in a dsp file, then it is not the header, but has
# already been used, so do not edit here...

# variables to REPLACE
# 
#  == include path
# E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\ == override in output directory
#   == compiler defines
# Cone  == name of output library
#  /LIBPATH:"E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\$(INTDIR)"  /LIBPATH:"E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\"  vtkRendering.lib vtkGraphics.lib vtkImaging.lib vtkFiltering.lib vtkCommon.lib opengl32.lib /STACK:10000000  == libraries linked in 
# TARGTYPE "Win32 (x86) Application" 0x0103

CFG=Cone - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Cone.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Cone.mak" CFG="Cone - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Cone - Win32 MinSizeRel" (based on "Win32 (x86) Application")
!MESSAGE "Cone - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Cone - Win32 RelWithDebInfo" (based on "Win32 (x86) Application")
!MESSAGE "Cone - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Cone - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo  /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS"  /FD /c
# ADD CPP /nologo  /D "WIN32"  /D "NDEBUG" /D "_CONSOLE" /D "_MBCS"  /FD /c
# ADD CPP    /D "Cone_EXPORTS"
# ADD CPP /nologo /W3 /Zm1000 /GX /GR
# ADD CPP /MD /O2 -DCMAKE_INTDIR=\"Release\"
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC  /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /IGNORE:4089
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /IGNORE:4089

# ADD LINK32 /LIBPATH:"E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\$(INTDIR)"  /LIBPATH:"E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\" 
# ADD LINK32 vtkRendering.lib
# ADD LINK32 vtkGraphics.lib
# ADD LINK32 vtkImaging.lib
# ADD LINK32 vtkFiltering.lib
# ADD LINK32 vtkCommon.lib
# ADD LINK32 opengl32.lib
# ADD LINK32 /STACK:10000000 




!ELSEIF  "$(CFG)" == "Cone - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP   /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS"  /FD /GZ /c
# ADD CPP /nologo  /D "WIN32"  /D "_DEBUG" /D "_CONSOLE" /D "_MBCS"  /FD /GZ /c
# ADD CPP    /D "Cone_EXPORTS"
# ADD CPP /nologo /W3 /Zm1000 /GX /GR
# ADD CPP /MDd /Zi /Od /GZ -DCMAKE_INTDIR=\"Debug\"
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC  /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32   kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /IGNORE:4089
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /IGNORE:4089

# ADD LINK32 /LIBPATH:"E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\$(INTDIR)"  /LIBPATH:"E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\" 
# ADD LINK32 vtkRendering.lib
# ADD LINK32 vtkGraphics.lib
# ADD LINK32 vtkImaging.lib
# ADD LINK32 vtkFiltering.lib
# ADD LINK32 vtkCommon.lib
# ADD LINK32 opengl32.lib
# ADD LINK32 /STACK:10000000 




!ELSEIF  "$(CFG)" == "Cone - Win32 MinSizeRel"
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "MinSizeRel"
# PROP BASE Intermediate_Dir "MinSizeRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\MinSizeRel"
# PROP Intermediate_Dir "MinSizeRel"
# PROP Target_Dir ""
# ADD BASE CPP /nologo  /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS"  /FD /c
# ADD CPP /nologo  /D "WIN32"    /D "NDEBUG" /D "_CONSOLE" /D "_MBCS"  /FD /c
# ADD CPP    /D "Cone_EXPORTS"
# ADD CPP /nologo /W3 /Zm1000 /GX /GR
# ADD CPP /MD /O1 -DCMAKE_INTDIR=\"MinSizeRel\"
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC  /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /IGNORE:4089
# ADD LINK32  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /IGNORE:4089

# ADD LINK32 /LIBPATH:"E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\$(INTDIR)"  /LIBPATH:"E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\" 
# ADD LINK32 vtkRendering.lib
# ADD LINK32 vtkGraphics.lib
# ADD LINK32 vtkImaging.lib
# ADD LINK32 vtkFiltering.lib
# ADD LINK32 vtkCommon.lib
# ADD LINK32 opengl32.lib
# ADD LINK32 /STACK:10000000 




!ELSEIF  "$(CFG)" == "Cone - Win32 RelWithDebInfo"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "RelWithDebInfo"
# PROP BASE Intermediate_Dir "RelWithDebInfo"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\RelWithDebInfo"
# PROP Intermediate_Dir "RelWithDebInfo"
# PROP Target_Dir ""
# ADD BASE CPP /nologo  /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS"  /FD /c
# ADD CPP /nologo  /D "WIN32"  /D "NDEBUG" /D "_CONSOLE" /D "_MBCS"  /FD /c
# ADD CPP    /D "Cone_EXPORTS"
# ADD CPP /nologo /W3 /Zm1000 /GX /GR
# ADD CPP /MD /Zi /O2 -DCMAKE_INTDIR=\"RelWithDebInfo\"
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC  /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /IGNORE:4089
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /IGNORE:4089

# ADD LINK32 /LIBPATH:"E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\$(INTDIR)"  /LIBPATH:"E:\Program Files\vtk40\Examples\Tutorial\Step1\Cxx\Debug\" 
# ADD LINK32 vtkRendering.lib
# ADD LINK32 vtkGraphics.lib
# ADD LINK32 vtkImaging.lib
# ADD LINK32 vtkFiltering.lib
# ADD LINK32 vtkCommon.lib
# ADD LINK32 opengl32.lib
# ADD LINK32 /STACK:10000000 




!ENDIF 

# Begin Target

# Name "Cone - Win32 Release"
# Name "Cone - Win32 Debug"
# Name "Cone - Win32 MinSizeRel"
# Name "Cone - Win32 RelWithDebInfo"

# Begin Source File

SOURCE="E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx\CMakeLists.txt"

!IF  "$(CFG)" == "Cone - Win32 Release"
USERDEP__HACK=\
	"E:\Program Files\CMake\Modules\FindVTK.cmake"\
	"E:\Program Files\CMake\Templates\CMakeWindowsSystemConfig.cmake"\
	"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx\CMakeLists.txt"
# PROP Ignore_Default_Tool 1
# Begin Custom Build

"Cone.dsp.cmake" :  "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	"E:\Program Files\CMake\bin\cmake.exe" "E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx\CMakeLists.txt" -H"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -S"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -O"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -B"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx"

# End Custom Build

!ELSEIF  "$(CFG)" == "Cone - Win32 Debug"
USERDEP__HACK=\
	"E:\Program Files\CMake\Modules\FindVTK.cmake"\
	"E:\Program Files\CMake\Templates\CMakeWindowsSystemConfig.cmake"\
	"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx\CMakeLists.txt"
# PROP Ignore_Default_Tool 1
# Begin Custom Build

"Cone.dsp.cmake" :  "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	"E:\Program Files\CMake\bin\cmake.exe" "E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx\CMakeLists.txt" -H"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -S"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -O"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -B"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx"

# End Custom Build

!ELSEIF  "$(CFG)" == "Cone - Win32 MinSizeRel"
USERDEP__HACK=\
	"E:\Program Files\CMake\Modules\FindVTK.cmake"\
	"E:\Program Files\CMake\Templates\CMakeWindowsSystemConfig.cmake"\
	"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx\CMakeLists.txt"
# PROP Ignore_Default_Tool 1
# Begin Custom Build

"Cone.dsp.cmake" :  "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	"E:\Program Files\CMake\bin\cmake.exe" "E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx\CMakeLists.txt" -H"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -S"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -O"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -B"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx"

# End Custom Build

!ELSEIF  "$(CFG)" == "Cone - Win32 RelWithDebInfo"
USERDEP__HACK=\
	"E:\Program Files\CMake\Modules\FindVTK.cmake"\
	"E:\Program Files\CMake\Templates\CMakeWindowsSystemConfig.cmake"\
	"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx\CMakeLists.txt"
# PROP Ignore_Default_Tool 1
# Begin Custom Build

"Cone.dsp.cmake" :  "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	"E:\Program Files\CMake\bin\cmake.exe" "E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx\CMakeLists.txt" -H"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -S"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -O"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx" -B"E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx"

# End Custom Build

!ENDIF

# End Source File
# Begin Group "Source Files"
# PROP Default_Filter ""
# Begin Source File

SOURCE="E:\Program Files\vtk40\Examples\Tutorial\Step1\cxx\Cone.cxx"

# End Source File
# End Group
# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project

