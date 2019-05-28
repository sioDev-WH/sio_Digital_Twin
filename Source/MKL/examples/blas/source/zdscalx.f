*
*     Z D S C A L  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program ZDSCAL_MAIN
*
      integer          n, incx
      integer          nmax
      parameter       (nmax=10)
      complex*16       x(nmax)
      double precision da
      integer          i
*       External Subroutines 
      external         ZDSCAL, PrintVectorZ
*
*       Executable Statementcs    
*      
      print*
      print*,'   Z D S C A L  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n, incx
      read*, da
      read*, (x(i),i=1,1+(n-1)*abs(incx))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      print 101, da
      call PrintVectorZ(0,n,x,incx,'X ')
*
*      Call ZDSCAL subroutine
      call ZDSCAL(n,da,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorZ(1,n,x,incx,'X ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'DA=',f5.2)
      stop
      end
