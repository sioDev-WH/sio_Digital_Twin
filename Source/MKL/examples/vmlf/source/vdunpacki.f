	programm MKL_VML_TEST

	include "func_interv.fi"

	real*8 dA(VEC_LEN)
	real*8 dB1(VEC_LEN)
	real*8 dB2(VEC_LEN)
	integer i,incra,len

	i=0
	incra=3

	do i=1,VEC_LEN
		dA(i)=i/1.0
		dB1(i)=0.0
		dB2(i)=0.0
	end do

	len=VEC_LEN/incra+1
	call VDPACKI(len,dA,incra,dB1)
	call VDUNPACKI(len,dB1,dB2,incra)

	print *,"vdUnpackI test/example programm"
	print *,""
	print *,""

	print *,"           Before packing             After packing          After Unpacking"
	print *,"==============================================================================="
	do i=1,VEC_LEN
		print 10,dA(i),dB1(i),dB2(i)
	end do

10	format (F25.13,F25.13,F25.13)

	end
