*
*     D N R M 2  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  DNRM2_MAIN
*
      integer          n, incx 
      integer          xmax
      parameter       (xmax=10) 
      double precision x(xmax), res
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         DNRM2, PrintVectorD
      double precision DNRM2
*
*       Executable Statements    
*    
      print*
      print*,'   D N R M 2  EXAMPLE PROGRAM'
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
      call PrintVectorD(0,n,x,incx,'X ')
*
*       Call DNRM2 subroutine
      res = DNRM2(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, res
*
 100  format(7x,'N=',i2)
 101  format(10x,'DNRM2 = ',f8.3)
      stop
      end
