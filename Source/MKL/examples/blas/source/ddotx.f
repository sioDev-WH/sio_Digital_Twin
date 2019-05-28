*
*     D D O T  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  DDOT_MAIN
*
      integer          n, incx, incy 
      integer          xmax, ymax
      parameter       (xmax=20, ymax=20) 
      double precision sx(xmax), sy(ymax), res
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         DDOT, PrintVectorD
      double precision DDOT
*
*       Executable Statements    
*    
      print*
      print*,'   D D O T  EXAMPLE PROGRAM'
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
      call PrintVectorD(0,n,sx,incx,'X ')
      call PrintVectorD(0,n,sy,incy,'Y ')
*
*       Call DDOT subroutine
      res = DDOT(n,sx,incx,sy,incy)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, res
*
 100  format(7x,'N=',i2)
 101  format(7x,'DDOT = ',f8.3)
      stop
      end
