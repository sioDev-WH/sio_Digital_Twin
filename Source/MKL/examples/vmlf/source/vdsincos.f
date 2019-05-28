	programm MKL_VML_TEST

	include "func_interv.fi"

	real*8 dA(VEC_LEN)
	real*8 dB1(VEC_LEN)
	real*8 dB2(VEC_LEN)
	real*8 dB3(VEC_LEN)
	real*8 dB4(VEC_LEN)
	real*8 CurRMS1,MaxRMS1
	real*8 CurRMS2,MaxRMS2
	real*8 MaxRMS
	integer i

	MaxRMS=0.0
	do i=1,VEC_LEN
		dA(i)=VML_DSINCOS_BEG+((VML_DSINCOS_END-VML_DSINCOS_BEG)*i)/VEC_LEN
		dB1(i)=0;
		dB2(i)=0;
		dB3(i)=sin(dA(i))
		dB4(i)=cos(dA(i))
	end do

	call VDSINCOS(VEC_LEN,dA,dB1,dB2)

	print *,"vdSinCos test/example programm"
	print *,""
	print *,""
	print *,"           Argument                     vdSinCos                      SinCos"
	print *,"=============================================================================="
	do i=1,VEC_LEN
		print 10,dA(i),dB1(i),dB2(i),dB3(i),dB4(i)
		CurRMS1=(dB1(i)-dB3(i))/(0.5*(dB1(i)+dB3(i)))
		CurRMS2=(dB2(i)-dB4(i))/(0.5*(dB2(i)+dB4(i)))
		if(MaxRMS1<CurRMS1) MaxRMS1=CurRMS1
		if(MaxRMS2<CurRMS2) MaxRMS2=CurRMS2
	end do

	if(MaxRMS2<MaxRMS1) MaxRMS=MaxRMS1
	if(MaxRMS2>MaxRMS1) MaxRMS=MaxRMS2
	print *,""
	print 11,"Maximum relative error: ",MaxRMS

10	format(F22.14,F20.6,F10.6,F13.6,F10.6)
11	format(A,F25.14)

	end
