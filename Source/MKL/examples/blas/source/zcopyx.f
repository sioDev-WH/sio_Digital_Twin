*
*     Z C O P Y  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  ZCOPY_MAIN
*
      integer    n, incx, incy 
      integer    xmax, ymax
      parameter  (xmax=20, ymax=20) 
      complex*16 x(xmax), y(ymax) 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   ZCOPY, PrintVectorZ
*
*       Executable Statements    
*    
      print*
      print*,'   Z C O P Y  EXAMPLE PROGRAM'
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
      call PrintVectorZ(0,n,x,incx,'X ')
*
*       Call ZCOPY subroutine
      call ZCOPY(n,x,incx,y,incy)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorZ(0,n,y,incy,'Y ')
*
 100  format(7x,'N=',i2)
      stop
      end
