*
*     I S A M I N  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  ISAMIN_MAIN
*
      integer    n, incx 
      integer    xmax
      parameter  (xmax=10) 
      real       x(xmax) 
      integer    i, index
*       Intrinsic Functions
      intrinsic  abs
*       External Subroutines 
      external   ISAMIN, PrintVectorS
      integer    ISAMIN
*
*       Executable Statements    
*    
      print*
      print*,'   I S A M I N  EXAMPLE PROGRAM'
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
*       Call ISAMIN subroutine
      index = ISAMIN(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, index
*
 100  format(7x,'N=',i2)
 101  format(10x,'ISAMIN = ',i3)
      stop
      end
