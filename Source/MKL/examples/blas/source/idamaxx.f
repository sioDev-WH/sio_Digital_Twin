*
*     I D A M A X  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  IDAMAX_MAIN
*
      integer          n, incx 
      integer          xmax
      parameter       (xmax=10) 
      double precision x(xmax) 
      integer          i, index
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         IDAMAX, PrintVectorD
      integer          IDAMAX
*
*       Executable Statements    
*    
      print*
      print*,'   I D A M A X  EXAMPLE PROGRAM'
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
*       Call IDAMAX subroutine
      index = IDAMAX(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, index
*
 100  format(7x,'N=',i2)
 101  format(10x,'IDAMAX = ',i3)
      stop
      end
