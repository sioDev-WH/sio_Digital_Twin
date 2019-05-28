*
*     S C N R M 2  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SCNRM2_MAIN
*
      integer          n, incx 
      integer          xmax
      parameter       (xmax=10) 
      complex          x(xmax)
      real             res
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         SCNRM2, PrintVectorC
      real             SCNRM2
*
*       Executable Statements    
*    
      print*
      print*,'   S C N R M 2  EXAMPLE PROGRAM'
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
*       Call SCNRM2 subroutine
      res = SCNRM2(n,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, res
*
 100  format(7x,'N=',i2)
 101  format(10x,'SCNRM2 = ',f8.3)
      stop
      end
