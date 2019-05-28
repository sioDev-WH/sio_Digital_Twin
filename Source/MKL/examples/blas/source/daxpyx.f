*
*     D A X P Y  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  DAXPY_MAIN
*
      integer          n, incx, incy 
      double precision alpha
      integer          xmax, ymax
      parameter       (xmax=10, ymax=10) 
      double precision x(xmax), y(ymax) 
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         DAXPY, PrintVectorD
*
*       Executable Statements    
*    
      print*
      print*,'   D A X P Y  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n, incx, incy
      read*, alpha
      read*, (x(i),i=1,1+(n-1)*abs(incx))
      read*, (y(i),i=1,1+(n-1)*abs(incy))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      print 101, alpha
      call PrintVectorD(0,n,x,incx,'X ')
      call PrintVectorD(0,n,y,incy,'Y ')
*
*       Call DAXPY subroutine
      call DAXPY(n,alpha,x,incx,y,incy)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorD(1,n,y,incy,'Y ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'ALPHA=',f4.1)
      stop
      end
 