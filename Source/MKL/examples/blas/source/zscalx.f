*
*     Z S C A L  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program ZSCAL_MAIN
*
      integer      n, incx
      integer      nmax
      parameter    (nmax=10)
      complex*16   za, x(nmax)
      integer      i
*       External Subroutines 
      external     ZSCAL, PrintVectorZ
*
*   Executable Statementcs    
*      
      print*
      print*,'   Z S C A L  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n, incx
      read*, za
      read*, (x(i),i=1,1+(n-1)*abs(incx))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      print 101, za
      call PrintVectorZ(0,n,x,incx,'X ')
*
*      Call ZSCAL subroutine
      call ZSCAL(n,za,x,incx)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorZ(1,n,x,incx,'X ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'ZA=(',f4.1,',',f4.1,')')
      stop
      end
