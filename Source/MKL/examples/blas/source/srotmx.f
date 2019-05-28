*
*     S R O T M  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SROTM_MAIN
*
      integer    n, incx, incy 
      real       param(5)
      integer    xmax, ymax
      parameter  (xmax=10, ymax=10) 
      real       x(xmax), y(ymax) 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   SROTM, PrintVectorS
*
*       Executable Statements    
*    
      print*
      print*,'   S R O T M  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n
      read*, incx, incy
      read*, (param(i),i=1,5)
      read*, (x(i),i=1,1+(n-1)*abs(incx))
      read*, (y(i),i=1,1+(n-1)*abs(incy))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
	print 101, (param(i),i=1,5)
      call PrintVectorS(0,n,x,incx,'X ')
      call PrintVectorS(0,n,y,incy,'Y ')
*
*       Call SROTM subroutine
      call SROTM(n,x,incx,y,incy,param)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorS(1,n,x,incx,'X ')
      call PrintVectorS(1,n,y,incy,'Y ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'VECTOR PARAM'/9x,5(f4.1,1x))
      stop
      end
 