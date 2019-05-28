*
*     Z D O T C  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  ZDOTC_MAIN
*
      integer    n, incx, incy 
      integer    xmax, ymax
      parameter  (xmax=20, ymax=20) 
      complex*16 x(xmax), y(ymax), res 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   ZDOTC, PrintVectorZ
      complex*16 ZDOTC
*
*       Executable Statements    
*    
      print*
      print*,'   Z D O T C  EXAMPLE PROGRAM'
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
      call PrintVectorZ(0,n,x,incx,'X ')
      call PrintVectorZ(0,n,y,incy,'Y ')
*
*       Call ZDOTC subroutine
      res = ZDOTC(n,x,incx,y,incy)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, res
*
 100  format(7x,'N=',i2)
 101  format(7x,'ZDOTC = (',f7.3,',',f7.3,')')
      stop
      end
