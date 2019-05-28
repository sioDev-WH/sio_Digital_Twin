	programm MKL_VML_TEST

	include "func_interv.fi"

	real*4 sA(VEC_LEN)
	real*4 sB1(VEC_LEN)
	real*4 sB2(VEC_LEN)
	real*4 CurRMS,MaxRMS
	integer i

	MaxRMS=0.0
	do i=1,VEC_LEN
		sA(i)=VML_SCOS_BEG+((VML_SCOS_END-VML_SCOS_BEG)*i)/VEC_LEN
		sB1(i)=0;
		sB2(i)=cos(sA(i))
	end do

	call VSCOS(VEC_LEN,sA,sB1)

	print *,"vsCos test/example programm"
	print *,""
	print *,""
	print *,"           Argument                     vsCos                      Cos"
	print *,"=============================================================================="
	do i=1,VEC_LEN
		print 10,sA(i),sB1(i),sB2(i)
		CurRMS=(sB1(i)-sB2(i))/(0.5*(sB1(i)+sB2(i)))
		if(MaxRMS<CurRMS) MaxRMS=CurRMS
	end do

	print *,""
	print 11,"Maximum relative error: ",MaxRMS

10	format(F25.14,F25.14,F25.14)
11	format(A,F25.14)

	end
