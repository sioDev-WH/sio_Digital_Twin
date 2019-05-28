	programm MKL_VML_TEST

	include "func_interv.fi"

	real*8 dA(VEC_LEN)
	real*8 dB1(VEC_LEN)
	real*8 dB2(VEC_LEN)
	real*8 CurRMS,MaxRMS
	integer i

	MaxRMS=0.0
	do i=1,VEC_LEN
		dA(i)=VML_DTANH_BEG+((VML_DTANH_END-VML_DTANH_BEG)*i)/VEC_LEN
		dB1(i)=0;
		dB2(i)=tanh(dA(i))
	end do

	call VDTANH(VEC_LEN,dA,dB1)

	print *,"vdTanh test/example programm"
	print *,""
	print *,""
	print *,"           Argument                     vdTanh                      Tanh"
	print *,"=============================================================================="
	do i=1,VEC_LEN
		print 10,dA(i),dB1(i),dB2(i)
		CurRMS=(dB1(i)-dB2(i))/(0.5*(dB1(i)+dB2(i)))
		if(MaxRMS<CurRMS) MaxRMS=CurRMS
	end do

	print *,""
	print 11,"Maximum relative error: ",MaxRMS

10	format(F25.14,F25.14,F25.14)
11	format(A,F25.14)

	end