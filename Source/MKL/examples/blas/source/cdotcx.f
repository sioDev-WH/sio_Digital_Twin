*
*     C D O T C  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  CDOTC_MAIN
*
      integer    n, incx, incy 
      integer    xmax, ymax
      parameter  (xmax=20, ymax=20) 
      complex    x(xmax), y(ymax), res 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   CDOTC, PrintVectorC
      complex    CDOTC
*
*       Executable Statements    
*    
      print*
      print*,'   C D O T C  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n
      read*, incx, incy
      read*, (x(i),i=1,1+(n-1)*abs(incx))
      read*, (y(i),i=1,1+(n-1)*abs(incy))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorC(0,n,x,incx,'X ')
      call PrintVectorC(0,n,y,incy,'Y ')
*
*       Call CDOTC subroutine
      res = CDOTC(n,x,incx,y,incy)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, res
*
 100  format(7x,'N=',i2)
 101  format(7x,'CDOTC = (',f6.3,',',f6.3,')')
      stop
      end
