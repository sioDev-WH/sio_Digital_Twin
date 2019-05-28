@echo off
PATH=..\..\ia32\bin;%PATH%

setlocal
set lang=c
SET MKL32_LIB=..\..\ia32\lib\mkl

if "%2"=="" goto arg2ok
if "%2"=="dll" goto arg2ok
goto error
:arg2ok
if "%1"=="icl" goto c
if "%1"=="ifl" goto f
if "%1"=="cl" goto c
if "%1"=="df" goto s
goto error

:f
set lang=f

:c
if "%2"=="dll" goto cdll

%1 /nologo /w GetVersionString_tst.%lang% %MKL32_LIB%_c.lib %MKL32_LIB%_p4.lib
GetVersionString_tst.exe >mkl_version_%lang%.sum

cl /nologo /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p4.lib
getversion_tst.exe >>mkl_version_%lang%.sum

%1 /nologo /w GetVersionString_tst.%lang% %MKL32_LIB%_c.lib %MKL32_LIB%_p3.lib
GetVersionString_tst.exe >>mkl_version_%lang%.sum

cl /nologo /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p3.lib
getversion_tst.exe >>mkl_version_%lang%.sum

%1 /nologo /w GetVersionString_tst.%lang% %MKL32_LIB%_c.lib %MKL32_LIB%_def.lib
GetVersionString_tst.exe >>mkl_version_%lang%.sum

cl /nologo /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_def.lib
getversion_tst.exe >>mkl_version_%lang%.sum

goto end

:cdll

%1 /nologo /w GetVersionString_tst.%lang% %MKL32_LIB%_c_dll.lib
GetVersionString_tst.exe >mkl_version_%lang%.sum

cl /nologo /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c_dll.lib
getversion_tst.exe >>mkl_version_%lang%.sum

goto end


:s
set lang=f
if "%2"=="dll" goto fdll

df /nologo GetVersionString_tst.f %MKL32_LIB%_s.lib %MKL32_LIB%_p4.lib
GetVersionString_tst.exe >mkl_version_f.sum

rem cl /nologo /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p4.lib
cl /nologo /Gz /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_s.lib %MKL32_LIB%_p4.lib
getversion_tst.exe >>mkl_version_f.sum

df /nologo GetVersionString_tst.f %MKL32_LIB%_s.lib %MKL32_LIB%_p3.lib
GetVersionString_tst.exe >>mkl_version_f.sum

rem cl /nologo /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p3.lib
cl /nologo /Gz /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_s.lib %MKL32_LIB%_p3.lib
getversion_tst.exe >>mkl_version_f.sum

df /nologo GetVersionString_tst.f %MKL32_LIB%_s.lib %MKL32_LIB%_def.lib
GetVersionString_tst.exe >>mkl_version_f.sum

rem cl /nologo /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_def.lib
cl /nologo /Gz /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_s.lib %MKL32_LIB%_def.lib
getversion_tst.exe >>mkl_version_f.sum

goto end

:fdll

df /nologo GetVersionString_tst.f %MKL32_LIB%_s_dll.lib
GetVersionString_tst.exe >mkl_version_f.sum

rem cl /nologo /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c_dll.lib
cl /nologo /Gz /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_s_dll.lib
getversion_tst.exe >>mkl_version_f.sum

goto end

:error

echo "                                         "
echo "   Usage: mklgetversion compiler [dll]   "
echo "       compiler=[cl|icl|ifl|df]          "
echo "                                         "
goto end2

:end
type mkl_version_%lang%.sum
del /q *.exe *.obj work.*
:end2
endlocal
