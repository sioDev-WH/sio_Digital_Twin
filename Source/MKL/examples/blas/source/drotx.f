*
*     D R O T  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  DROT_MAIN
*
      integer           n, incx, incy 
      double precision  c, s
      integer           xmax, ymax
      parameter        (xmax=10, ymax=10) 
      double precision  x(xmax), y(ymax) 
      integer           i
*       Intrinsic Functions
      intrinsic         abs
*       External Subroutines 
      external          DROT, PrintVectorD
*
*       Executable Statements    
*    
      print*
      print*,'   D R O T  EXAMPLE PROGRAM'
*
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
      call PrintVectorD(0,n,x,incx,'X ')
      call PrintVectorD(0,n,y,incy,'Y ')
*
*       Call DROT subroutine
      call DROT(n,x,incx,y,incy,c,s)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorD(1,n,x,incx,'X ')
      call PrintVectorD(1,n,y,incy,'Y ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'C=',f5.2,'  S=',f5.2)
      stop
      end
 