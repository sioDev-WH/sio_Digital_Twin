*
*     S S C A L  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program SSCAL_MAIN
*
      integer      n, incx
      integer      nmax
      parameter    (nmax=10)
      real         sa, sx(nmax)
      integer      i
*       External Subroutines 
      external     SSCAL, PrintVectorS
*
*   Executable Statementcs    
*      
      print*
      print*,'   S S C A L  EXAMPLE PROGRAM'
*       Read input data from input file 
      read*
      read*, n, incx
      read*, sa
      read*, (sx(i),i=1,1+(n-1)*abs(incx))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      print 101, sa
      call PrintVectorS(0,n,sx,incx,'X ')
*
*      Call SSCAL subroutine
      call SSCAL(n,sa,sx,incx)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorS(1,n,sx,incx,'X ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'SA=',f5.2)
      stop
      end
