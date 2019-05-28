*
*     D Z N R M 2  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  DZNRM2_MAIN
*
      integer          n, incx 
      integer          xmax
      parameter       (xmax=10) 
      complex*16       x(xmax)
      double precision res
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         DZNRM2, PrintVectorZ
      double precision DZNRM2
*
*       Executable Statements    
*    
      print*
      print*,'   D Z N R M 2  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n, incx
      read*, (x(i),i=1,1+(n-1)*abs(incx))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorZ(0,n,x,incx,'X ')
*
*       Call DZNRM2 subroutine
      res = DZNRM2(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, res
*
 100  format(7x,'N=',i2)
 101  format(10x,'DZNRM2 = ',f8.3)
      stop
      end
