	programm MKL_VML_TEST

	include "func_interv.fi"

	real*4 sA(VEC_LEN)
	real*4 sB1(VEC_LEN)
	real*4 sB2(VEC_LEN)
	integer i
	integer ia(VEC_LEN)

	i=0

	do i=1,VEC_LEN
		sA(i)=i/1.0
		sB1(i)=0.0
		sB2(i)=0.0
		ia(i)=vec_len-i
	end do

	call VSPACKV(vec_len,sA,ia,sB1)
	call VSUNPACKV(vec_len,sB1,sB2,ia)

	print *,"vsUnpackV test/example programm"
	print *,""
	print *,""

	print *,"           Before packing             After packing          After Unpacking"
	print *,"==============================================================================="
	do i=1,VEC_LEN
		print 10,sA(i),sB1(i),sB2(i)
	end do

10	format (F25.13,F25.13,F25.13)

	end
