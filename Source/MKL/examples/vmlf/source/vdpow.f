	programm MKL_VML_TEST

	include "func_interv.fi"

	real*8 dA1(VEC_LEN)
	real*8 dA2(VEC_LEN)
	real*8 dB1(VEC_LEN)
	real*8 dB2(VEC_LEN)
	real*8 CurRMS,MaxRMS
	integer i

	MaxRMS=0.0
	do i=1,VEC_LEN
		dA1(i)=VML_DPOW_BEG+((VML_DPOW_END-VML_DPOW_BEG)*i)/VEC_LEN
		dA2(i)=VML_DPOW_BEG+((VML_DPOW_END-VML_DPOW_BEG)*i)/VEC_LEN
		dB1(i)=0;
		dB2(i)=dA1(i)**dA2(i)
	end do

	call VDPOW(VEC_LEN,dA1,dA2,dB1)

	print *,"vdPow test/example programm"
	print *,""
	print *,""
	print *,"           Argument                     vdPow                      Pow"
	print *,"=============================================================================="
	do i=1,VEC_LEN
		print 10,dA1(i),dA2(i),dB1(i),dB2(i)
		CurRMS=(dB1(i)-dB2(i))/(0.5*(dB1(i)+dB2(i)))
		if(MaxRMS<CurRMS) MaxRMS=CurRMS
	end do

	print *,""
	print 11,"Maximum relative error: ",MaxRMS

10	format(F13.6,F13.6,F25.14,F25.14)
11	format(A,F25.14)

	end
