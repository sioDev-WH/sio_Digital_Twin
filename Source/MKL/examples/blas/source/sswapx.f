*
*     S S W A P  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program SSWAP_MAIN
*
      integer      n, incx, incy
      integer      xmax, ymax
      parameter    (xmax=10,ymax=10)
      real         x(xmax), y(ymax)
      integer      i
*       External Subroutines 
      external     SSWAP, PrintVectorS
*
*   Executable Statementcs    
*      
      print*
      print*,'   S S W A P  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n
      read*, incx, incy
      read*, (x(i),i=1,1+(n-1)*abs(incx))
      read*, (y(i),i=1,1+(n-1)*abs(incy))
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorS(0,n,x,incx,'X ')
      call PrintVectorS(0,n,y,incy,'Y ')
*
*      Call SSWAP subroutine
      call SSWAP(n,x,incx,y,incy)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorS(1,n,x,incx,'X ')
      call PrintVectorS(1,n,y,incy,'Y ')
*
 100  format(7x,'N=',i2)
      stop
      end
