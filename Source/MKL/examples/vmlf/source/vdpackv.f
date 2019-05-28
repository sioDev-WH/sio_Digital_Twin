	programm MKL_VML_TEST

	include "func_interv.fi"

	real*8 dA(VEC_LEN)
	real*8 dB1(VEC_LEN)
	integer ia(VEC_LEN)
	integer i

	i=0

	do i=1,VEC_LEN
		dA(i)=i/1.0
		dB1(i)=0.0
		ia(i)=VEC_LEN-i
	end do

	call VDPACKV(VEC_LEN,dA,ia,dB1)

	print *,"vdPackV test/example programm"
	print *,""
	print *,""

	print *,"           Before packing             After packing"
	print *,"==============================================================================="
	do i=1,VEC_LEN
		print 10,dA(i),dB1(i)
	end do

10	format (F25.13,F25.13)

	end
