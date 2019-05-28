*
*     D A S U M  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  DASUM_MAIN
*
      integer          n, incx 
      integer          xmax
      parameter       (xmax=10) 
      double precision x(xmax), sum 
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         DASUM, PrintVectorD
      double precision DASUM
*
*       Executable Statements    
*    
      print*
      print*,'   D A S U M  EXAMPLE PROGRAM'
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
*       Call DASUM subroutine
      sum = DASUM(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, sum
*
 100  format(7x,'N=',i2)
 101  format(10x,'DASUM = ',f8.3)
      stop
      end
