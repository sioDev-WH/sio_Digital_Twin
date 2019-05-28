	programm MKL_VML_TEST

	include "func_interv.fi"

	real*8 dA(VEC_LEN)
	real*8 dB1(VEC_LEN)
	integer i

	MaxRMS=0.0
	do i=1,VEC_LEN
		dA(i)=VML_DATANH_BEG+((VML_DATANH_END-VML_DATANH_BEG)*i)/VEC_LEN
		dB1(i)=0;
	end do

	call VDATANH(VEC_LEN,dA,dB1)

	print *,"vdAtanh test/example programm"
	print *,""
	print *,""
	print *,"           Argument                     vdAtanh"
	print *,"=============================================================================="
	do i=1,VEC_LEN
		print 10,dA(i),dB1(i)
	end do

10	format(F25.14,F25.14)

	end