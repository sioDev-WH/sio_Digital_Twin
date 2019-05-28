*
*     C C O P Y  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  CCOPY_MAIN
*
      integer    n, incx, incy 
      integer    xmax, ymax
      parameter  (xmax=20, ymax=20) 
      complex    x(xmax), y(ymax) 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   CCOPY, PrintVectorC
*
*       Executable Statements    
*    
      print*
      print*,'   C C O P Y  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n
      read*, incx, incy
      read*, (x(i),i=1,1+(n-1)*abs(incx))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorC(0,n,x,incx,'X ')
*
*       Call CCOPY subroutine
      call CCOPY(n,x,incx,y,incy)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorC(0,n,y,incy,'Y ')
*
 100  format(7x,'N=',i2)
      stop
      end
