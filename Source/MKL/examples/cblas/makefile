##
##               INTEL CORPORATION PROPRIETARY INFORMATION
##  This software is supplied under the terms of a license agreement or
##  nondisclosure agreement with Intel Corporation and may not be copied
##  or disclosed except in accordance with the terms of that agreement.
##        Copyright (c) 2001 Intel Corporation. All Rights Reserved.
##
## File    : makefile
## Purpose : MKL CBLAS examples creation and run
##
##------------------------------------------------------------------------------
## examples of using:
## "nmake p3"                       - build and run all examples for
##                                    Pentium(R) III processor
## "nmake p4 function=cblas_sgemm+" - build and run sblat3 example for
##                                    Pentium(R) 4 processor
## "nmake itp_msvc target=exe"      - build examples with Microsoft(R) Visual C/C++
##                                    compiler for Itanium(TM) processor
## "nmake itp_msvc"                 - run examples with Microsoft(R) Visual C/C++
##                                    for Itanium(TM) processor
#===============================================================================
!INCLUDE cblas.lst

!  ifndef function
function = $(CBLAS)
!  endif

!  ifndef target
target = res
!  endif

EXE32 = nmake /nologo -f make_exe E="$(function)" T=$(target) Y=$@ _IA=ia32
EXE64 = nmake /nologo -f make_exe E="$(function)" T=$(target) Y=$@ _IA=ia64
#..............................................................................
def_intel:
	$(EXE32) MKL_LIB="mkl_c+ mkl_def+" F=intel
def_msvc:
	$(EXE32) MKL_LIB="mkl_c+ mkl_def+"
#..............................................................................
p3_intel:
	$(EXE32) MKL_LIB="mkl_c+ mkl_p3+" F=intel
p3_msvc:
	$(EXE32) MKL_LIB="mkl_c+ mkl_p3+"
#..............................................................................
p4_intel:
	$(EXE32) MKL_LIB="mkl_c+ mkl_p4+" F=intel
p4_msvc:
	$(EXE32) MKL_LIB="mkl_c+ mkl_p4+"
#..............................................................................
itp_intel:                                                           
	$(EXE64) MKL_LIB=mkl_itp+ F=intel64
itp_msvc:                                                           
	$(EXE64) MKL_LIB=mkl_itp+
#..............................................................................
dll_intel:
	$(EXE32) MKL_LIB=mkl_c_dll+ F=intel
dll_msvc:
	$(EXE32) MKL_LIB=mkl_c_dll+
dll_intel64:                                                          
	$(EXE64) MKL_LIB=mkl_dll+ F=intel64
dll_msvc64:                                                          
	$(EXE64) MKL_LIB=mkl_dll+

def:   def_intel    def_msvc
p3:    p3_intel     p3_msvc
p4:    p4_intel     p4_msvc
itp:   itp_intel    itp_msvc
dll:   dll_intel    dll_msvc
dll64: dll_intel64  dll_msvc64

#-------------------------------------------------------------------------------
clean_all:
	if exist _results rd /q /s _results
clean:
	if exist _results\$X rd /q /s _results\$X
