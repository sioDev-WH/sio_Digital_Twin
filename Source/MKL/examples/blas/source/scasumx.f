*
*     S C A S U M  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SCASUM_MAIN
*
      integer    n, incx 
      integer    xmax
      parameter  (xmax=10) 
      complex    x(xmax)
      real       sum 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   SCASUM, PrintVectorC
      real       SCASUM
*
*       Executable Statements    
*    
      print*
      print*,'   S C A S U M  EXAMPLE PROGRAM'
*       Read input data from input file 
      read*
      read*, n, incx
      read*, (x(i),i=1,1+(n-1)*abs(incx))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorC(0,n,x,incx,'X ')
*
*       Call SCASUM subroutine
      sum = SCASUM(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, sum
*
 100  format(7x,'N=',i2)
 101  format(10x,'SCASUM = ',f6.2)
      stop
      end
