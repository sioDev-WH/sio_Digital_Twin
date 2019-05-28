*
*     S D O T  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SDOT_MAIN
*
      integer    n, incx, incy 
      integer    xmax, ymax
      parameter  (xmax=20, ymax=20) 
      real       sx(xmax), sy(ymax), res 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   SDOT, PrintVectorS
      real       SDOT
*
*       Executable Statements    
*    
      print*
      print*,'   S D O T  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n
      read*, incx, incy
      read*, (sx(i),i=1,1+(n-1)*abs(incx))
      read*, (sy(i),i=1,1+(n-1)*abs(incy))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorS(0,n,sx,incx,'X ')
      call PrintVectorS(0,n,sy,incy,'Y ')
*
*       Call SDOT subroutine
      res = SDOT(n,sx,incx,sy,incy)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, res
*
 100  format(7x,'N=',i2)
 101  format(7x,'SDOT = ',f6.3)
      stop
      end
