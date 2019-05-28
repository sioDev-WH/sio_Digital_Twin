*
*     S A S U M  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SASUM_MAIN
*
      integer    n, incx 
      integer    xmax
      parameter  (xmax=10) 
      real       x(xmax), sum 
      integer    i
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   SASUM, PrintVectorS
      real       SASUM
*
*       Executable Statements    
*    
      print*
      print*,'   S A S U M  EXAMPLE PROGRAM'
*       Read input data from input file 
      read*
      read*, n, incx
      read*, (x(i),i=1,1+(n-1)*abs(incx))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorS(0,n,x,incx,'X ')
*
*       Call SASUM subroutine
      sum = SASUM(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, sum
*
 100  format(7x,'N=',i2)
 101  format(10x,'SASUM = ',f7.3)
      stop
      end
