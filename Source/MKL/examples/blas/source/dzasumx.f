*
*     D Z A S U M  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  DZASUM_MAIN
*
      integer          n, incx 
      integer          xmax
      parameter       (xmax=10) 
      complex*16       x(xmax)
      double precision sum 
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         DZASUM, PrintVectorZ
      double precision DZASUM
*
*       Executable Statements    
*    
      print*
      print*,'   D Z A S U M  EXAMPLE PROGRAM'
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
*       Call DZASUM subroutine
      sum = DZASUM(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, sum
*
 100  format(7x,'N=',i2)
 101  format(10x,'DZASUM = ',f7.3)
      stop
      end
