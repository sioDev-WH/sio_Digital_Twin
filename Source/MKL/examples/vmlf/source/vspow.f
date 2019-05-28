	programm MKL_VML_TEST

	include "func_interv.fi"

	real*4 sA1(VEC_LEN)
	real*4 sA2(VEC_LEN)
	real*4 sB1(VEC_LEN)
	real*4 sB2(VEC_LEN)
	real*4 CurRMS,MaxRMS
	integer i

	MaxRMS=0.0
	do i=1,VEC_LEN
		sA1(i)=VML_SPOW_BEG+((VML_SPOW_END-VML_SPOW_BEG)*i)/VEC_LEN
		sA2(i)=VML_SPOW_BEG+((VML_SPOW_END-VML_SPOW_BEG)*i)/VEC_LEN
		sB1(i)=0;
		sB2(i)=sA1(i)**sA2(i)
	end do

	call VSPOW(VEC_LEN,sA1,sA2,sB1)

	print *,"vsPow test/example programm"
	print *,""
	print *,""
	print *,"           Argument                     vsPow                      Pow"
	print *,"=============================================================================="
	do i=1,VEC_LEN
		print 10,sA1(i),sA2(i),sB1(i),sB2(i)
		CurRMS=(sB1(i)-sB2(i))/(0.5*(sB1(i)+sB2(i)))
		if(MaxRMS<CurRMS) MaxRMS=CurRMS
	end do

	print *,""
	print 11,"Maximum relative error: ",MaxRMS

10	format(F13.6,F13.6,F25.14,F25.14)
11	format(A,F25.14)

	end
