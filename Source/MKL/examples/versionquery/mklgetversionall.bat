PATH=..\..\ia32\bin;%PATH%
SET MKL32_LIB=..\..\ia32\lib\mkl

REM ----------------------------- DEFAULT ------------------------------------------------
cl /Gz GetVersionString_tst.c %MKL32_LIB%_s.lib %MKL32_LIB%_def.lib
GetVersionString_tst.exe >mkl32_version_c.sum
df GetVersionString_tst.f %MKL32_LIB%_s.lib %MKL32_LIB%_def.lib
GetVersionString_tst.exe >mkl32_version_f.sum
cl /Gz /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_s.lib %MKL32_LIB%_def.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

cl GetVersionString_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_def.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
df /iface=(cref,nomixed_str_len_arg) GetVersionString_tst.f %MKL32_LIB%_c.lib %MKL32_LIB%_def.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
cl /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_def.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

icl /w GetVersionString_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_def.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
ifl /w GetVersionString_tst.f %MKL32_LIB%_c.lib %MKL32_LIB%_def.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
icl /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_def.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

REM ----------------------------- PENTIUM(R) III -----------------------------------------
cl /Gz GetVersionString_tst.c %MKL32_LIB%_s.lib %MKL32_LIB%_p3.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
df GetVersionString_tst.f %MKL32_LIB%_s.lib %MKL32_LIB%_p3.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
cl /Gz /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_s.lib %MKL32_LIB%_p3.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

cl GetVersionString_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p3.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
df /iface=(cref,nomixed_str_len_arg) GetVersionString_tst.f %MKL32_LIB%_c.lib %MKL32_LIB%_p3.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
cl /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p3.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

icl /w GetVersionString_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p3.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
ifl /w GetVersionString_tst.f %MKL32_LIB%_c.lib %MKL32_LIB%_p3.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
icl /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p3.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

REM ----------------------------- PENTIUM(R) 4 -------------------------------------------
cl /Gz GetVersionString_tst.c %MKL32_LIB%_s.lib %MKL32_LIB%_p4.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
df GetVersionString_tst.f %MKL32_LIB%_s.lib %MKL32_LIB%_p4.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
cl /Gz /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_s.lib %MKL32_LIB%_p4.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

cl GetVersionString_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p4.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
df /iface=(cref,nomixed_str_len_arg) GetVersionString_tst.f %MKL32_LIB%_c.lib %MKL32_LIB%_p4.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
cl /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p4.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

icl /w GetVersionString_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p4.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
ifl /w GetVersionString_tst.f %MKL32_LIB%_c.lib %MKL32_LIB%_p4.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
icl /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c.lib %MKL32_LIB%_p4.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

REM ----------------------------- DYNAMIC ------------------------------------------------
cl /Gz GetVersionString_tst.c %MKL32_LIB%_s_dll.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
df GetVersionString_tst.f %MKL32_LIB%_s_dll.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
cl /Gz /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_s_dll.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

cl GetVersionString_tst.c %MKL32_LIB%_c_dll.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
df /iface=(cref,nomixed_str_len_arg) GetVersionString_tst.f %MKL32_LIB%_c_dll.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
cl /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c_dll.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

icl /w GetVersionString_tst.c %MKL32_LIB%_c_dll.lib
GetVersionString_tst.exe >>mkl32_version_c.sum
ifl /w GetVersionString_tst.f %MKL32_LIB%_c_dll.lib
GetVersionString_tst.exe >>mkl32_version_f.sum
icl /I..\..\INCLUDE getversion_tst.c %MKL32_LIB%_c_dll.lib
getversion_tst.exe >>mkl32_version_c.sum
getversion_tst.exe >>mkl32_version_f.sum

del /q *.exe *.obj work.*
