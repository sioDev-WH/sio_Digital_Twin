*
*     S C O P Y  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SCOPY_MAIN
*
      integer    n, incx, incy 
      integer    xmax, ymax
      parameter  (xmax=20, ymax=20) 
      real       sx(xmax), sy(ymax) 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   SCOPY, PrintVectorS
*
*       Executable Statements    
*    
      print*
      print*,'   S C O P Y  EXAMPLE PROGRAM'
*       Read input data from input file 
      read*
      read*, n
      read*, incx, incy
      read*, (sx(i),i=1,1+(n-1)*abs(incx))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorS(0,n,sx,incx,'X ')
*
*       Call SCOPY subroutine
      call SCOPY(n,sx,incx,sy,incy)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorS(0,n,sy,incy,'Y ')
*
 100  format(7x,'N=',i2)
      stop
      end
