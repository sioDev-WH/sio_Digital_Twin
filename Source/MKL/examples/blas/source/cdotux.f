*
*     C D O T U  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  CDOTU_MAIN
*
      integer    n, incx, incy 
      integer    xmax, ymax
      parameter  (xmax=20, ymax=20) 
      complex    x(xmax), y(ymax), res 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   CDOTU, PrintVectorC
      complex    CDOTU
*
*       Executable Statements    
*    
      print*
      print*,'   C D O T U  EXAMPLE PROGRAM'
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
*       Call CDOTU subroutine
      res = CDOTU(n,x,incx,y,incy)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, res
*
 100  format(7x,'N=',i2)
 101  format(7x,'CDOTU = (',f6.3,',',f6.3,' )')
      stop
      end
