*
*     S N R M 2  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SNRM2_MAIN
*
      integer          n, incx 
      integer          xmax
      parameter       (xmax=10) 
      real             x(xmax), res
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         SNRM2, PrintVectorS
      double precision SNRM2
*
*       Executable Statements    
*    
      print*
      print*,'   S N R M 2  EXAMPLE PROGRAM'
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
      call PrintVectorS(0,n,x,incx,'X ')
*
*       Call SNRM2 subroutine
      res = SNRM2(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, res
*
 100  format(7x,'N=',i2)
 101  format(10x,'SNRM2 = ',f8.3)
      stop
      end
