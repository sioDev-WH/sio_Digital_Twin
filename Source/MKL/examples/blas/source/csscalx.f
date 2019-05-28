*
*     C S S C A L  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program CSSCAL_MAIN
*
      integer      n, incx
      integer      nmax
      parameter    (nmax=10)
      complex      cx(nmax)
      real         sa
      integer      i
*       External Subroutines 
      external     CSSCAL, PrintVectorC
*
*   Executable Statementcs    
*      
      print*
      print*,'   C S S C A L  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n, incx
      read*, sa
      read*, (cx(i),i=1,1+(n-1)*abs(incx))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      print 101, sa
      call PrintVectorC(0,n,cx,incx,'X ')
*
*      Call CSSCAL subroutine
      call CSSCAL(n,sa,cx,incx)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorC(1,n,cx,incx,'X ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'SA=',f5.2)
      stop
      end
