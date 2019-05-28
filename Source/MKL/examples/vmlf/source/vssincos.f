	programm MKL_VML_TEST

	include "func_interv.fi"

	real*4 sA(VEC_LEN)
	real*4 sB1(VEC_LEN)
	real*4 sB2(VEC_LEN)
	real*4 sB3(VEC_LEN)
	real*4 sB4(VEC_LEN)
	real*4 CurRMS1,MaxRMS1
	real*4 CurRMS2,MaxRMS2
	real*4 MaxRMS
	integer i

	MaxRMS=0.0
	do i=1,VEC_LEN
		sA(i)=VML_SSINCOS_BEG+((VML_SSINCOS_END-VML_SSINCOS_BEG)*i)/VEC_LEN
		sB1(i)=0;
		sB2(i)=0;
		sB3(i)=sin(sA(i))
		sB4(i)=cos(sA(i))
	end do

	call VSSINCOS(VEC_LEN,sA,sB1,sB2)

	print *,"vsSinCos test/example programm"
	print *,""
	print *,""
	print *,"           Argument                     vsSinCos                      SinCos"
	print *,"=============================================================================="
	do i=1,VEC_LEN
		print 10,sA(i),sB1(i),sB2(i),sB3(i),sB4(i)
		CurRMS1=(sB1(i)-sB3(i))/(0.5*(sB1(i)+sB3(i)))
		CurRMS2=(sB2(i)-sB4(i))/(0.5*(sB2(i)+sB4(i)))
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
