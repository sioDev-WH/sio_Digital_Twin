*
*     C S R O T  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  CSROT_MAIN
*
      integer    n, incx, incy 
      real       c, s
      integer    xmax, ymax
      parameter  (xmax=10, ymax=10) 
      complex    x(xmax), y(ymax) 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   CSROT, PrintVectorC
*
*       Executable Statements    
*    
      print*
      print*,'   C S R O T  EXAMPLE PROGRAM'
*       Read input data from input file 
      read*
      read*, n
      read*, incx, incy
      read*, c, s
      read*, (x(i),i=1,1+(n-1)*abs(incx))
      read*, (y(i),i=1,1+(n-1)*abs(incy))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      print 101, c, s
      call PrintVectorC(0,n,x,incx,'X ')
      call PrintVectorC(0,n,y,incy,'Y ')
*
*       Call CSROT subroutine
      call CSROT(n,x,incx,y,incy,c,s)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorC(1,n,x,incx,'X ')
      call PrintVectorC(1,n,y,incy,'Y ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'C=',f4.1,'  S=',f4.1)
      stop
      end
 