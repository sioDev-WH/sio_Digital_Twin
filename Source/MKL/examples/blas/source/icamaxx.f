*
*     I C A M A X  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  ICAMAX_MAIN
*
      integer    n, incx 
      integer    xmax
      parameter  (xmax=10) 
      complex    x(xmax) 
      integer    i, index
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   ICAMAX, PrintVectorC
      integer    ICAMAX
*
*       Executable Statements    
*    
      print*
      print*,'   I C A M A X  EXAMPLE PROGRAM'
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
      call PrintVectorC(0,n,x,incx,'X ')
*
*       Call ICAMAX subroutine
      index = ICAMAX(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, index
*
 100  format(7x,'N=',i2)
 101  format(10x,'ICAMAX = ',i3)
      stop
      end