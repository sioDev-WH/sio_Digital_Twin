##
##               INTEL CORPORATION PROPRIETARY INFORMATION
##  This software is supplied under the terms of a license agreement or
##  nondisclosure agreement with Intel Corporation and may not be copied
##  or disclosed except in accordance with the terms of that agreement.
##        Copyright (c) 2001 Intel Corporation. All Rights Reserved.
##
## File    : makefile
## Purpose : MKL Fortran-style FFT examples creation and run
##
##------------------------------------------------------------------------------
## examples of using:
## "nmake p3"                     - build and run all examples for
##                                  Pentium(R) III processor
## "nmake p4 function=cfft1+"     - build and run sblat3 example for
##                                  Pentium(R) 4 processor
## "nmake dll_intel64 target=exe" - build all examples with DLL version of MKL for
##                                  Itanium(TM) processor
## "nmake dll_intel64"            - run all examples with DLL version of MKL for
##                                  Itanium(TM) processor
#===============================================================================
!INCLUDE fftf.lst

!  ifndef function
function = $(FFT)
!  endif

!  ifndef target
target = res
!  endif

EXE32 = nmake /nologo -f make_exe E="$(function)" T=$(target) Y=$@ _IA=ia32
EXE64 = nmake /nologo -f make_exe E="$(function)" T=$(target) Y=$@ _IA=ia64
#..............................................................................
def_intel:
	$(EXE32) MKL_LIB="mkl_c+ mkl_def+" F=intel
def_cvf:
	$(EXE32) MKL_LIB="mkl_s+ mkl_def+"
#..............................................................................
p3_intel:
	$(EXE32) MKL_LIB="mkl_c+ mkl_p3+" F=intel
p3_cvf:
	$(EXE32) MKL_LIB="mkl_s+ mkl_p3+"
#..............................................................................
p4_intel:
	$(EXE32) MKL_LIB="mkl_c+ mkl_p4+" F=intel
p4_cvf:
	$(EXE32) MKL_LIB="mkl_s+ mkl_p4+"
#..............................................................................
dll_intel:
	$(EXE32) MKL_LIB=mkl_c_dll+ F=intel
dll_cvf:
	$(EXE32) MKL_LIB=mkl_s_dll+
#..............................................................................
itp_intel:
	$(EXE64) MKL_LIB=mkl_itp+ F=intel64
dll_intel64:
	$(EXE64) MKL_LIB=mkl_dll+ F=intel64

def: def_intel def_cvf
p3:  p3_intel  p3_cvf
p4:  p4_intel  p4_cvf
dll: dll_intel dll_cvf

#-------------------------------------------------------------------------------
clean_all:
	if exist _results rd /q /s _results
clean:
	if exist _results\$X rd /q /s _results\$X
