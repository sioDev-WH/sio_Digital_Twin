*
*     D R O T M   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*
      program   DROTM_MAIN
*
      integer           n, incx, incy
	  integer           xmax, ymax
	  parameter         (xmax=10, ymax=10)
      double precision  param(5)
      double precision  x(xmax), y(ymax)
      integer           i
*       Intrinsic Function
      intrinsic         abs
*       External Subroutines 
      external          DROTM, PrintVectorD
*
*       Executable Statements    
*    
      print*
      print*,'   D R O T M  EXAMPLE PROGRAM'
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
      call PrintVectorD(0, n, x, incx, 'X ')
      call PrintVectorD(0, n, y, incy, 'Y ')

*      Call DROTM subroutine
      call drotm(n, x, incx, y, incy, param)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorD(1, n, x, incx, 'X ')
      call PrintVectorD(1, n, y, incy, 'Y ')
      
 100  format(7x,'N=',i2)
 101  format(7x,'VECTOR PARAM',/9x,5(f6.3,1x))
      stop
      end
                                                              
