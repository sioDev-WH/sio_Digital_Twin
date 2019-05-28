*
*     D S C A L  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program DSCAL_MAIN
*
      integer          n, incx
      integer          nmax
      parameter        (nmax=10)
      double precision da, x(nmax)
      integer          i
*       External Subroutines 
      external         DSCAL, PrintVectorD
*
*   Executable Statementcs    
*      
      print*
      print*,'   D S C A L  EXAMPLE PROGRAM'
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
      call PrintVectorD(0,n,x,incx,'X ')
*
*      Call DSCAL subroutine
      call DSCAL(n,da,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorD(1,n,x,incx,'X ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'DA=',f6.2)
      stop
      end
