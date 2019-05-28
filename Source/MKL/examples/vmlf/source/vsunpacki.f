	programm MKL_VML_TEST

	include "func_interv.fi"

	real*4 sA(VEC_LEN)
	real*4 sB1(VEC_LEN)
	real*4 sB2(VEC_LEN)
	integer i,incra,len

	i=0
	incra=3

	do i=1,VEC_LEN
		sA(i)=i/1.0
		sB1(i)=0.0
		sB2(i)=0.0
	end do

	len=VEC_LEN/incra+1
	call VSPACKI(len,sA,incra,sB1)
	call VSUNPACKI(len,sB1,sB2,incra)

	print *,"vsUnpackI test/example programm"
	print *,""
	print *,""

	print *,"           Before packing             After packing          After Unpacking"
	print *,"==============================================================================="
	do i=1,VEC_LEN
		print 10,sA(i),sB1(i),sB2(i)
	end do

10	format (F25.13,F25.13,F25.13)

	end
