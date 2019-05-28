	programm MKL_VML_TEST

	include "func_interv.fi"

	real*4 sA(VEC_LEN)
	real*4 sB1(VEC_LEN)
	integer i

	MaxRMS=0.0
	do i=1,VEC_LEN
		sA(i)=VML_SATANH_BEG+((VML_SATANH_END-VML_SATANH_BEG)*i)/VEC_LEN
		sB1(i)=0;
	end do

	call VSATANH(VEC_LEN,sA,sB1)

	print *,"vsAtanh test/example programm"
	print *,""
	print *,""
	print *,"           Argument                     vsAtanh"
	print *,"=============================================================================="
	do i=1,VEC_LEN
		print 10,sA(i),sB1(i)
	end do

10	format(F25.14,F25.14)

	end
