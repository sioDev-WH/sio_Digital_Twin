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
		sA1(i)=VML_SATAN2_BEG+((VML_SATAN2_END-VML_SATAN2_BEG)*i)/VEC_LEN
		sA2(i)=VML_SATAN2_BEG+((VML_SATAN2_END-VML_SATAN2_BEG)*i)/VEC_LEN
		sB1(i)=0;
		sB2(i)=atan2(sA1(i),sA2(i))
	end do

	call VSATAN2(VEC_LEN,sA1,sA2,sB1)

	print *,"vsAtan2 test/example programm"
	print *,""
	print *,""
	print *,"           Argument                     vsAtan2                      Atan2"
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
