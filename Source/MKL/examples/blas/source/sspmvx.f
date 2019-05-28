*
*     S S P M V  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   SSPMV_MAIN
*
      character*1      uplo
      integer          n, incx, incy
      integer          apmax, xmax, ymax
      parameter        (apmax=15, xmax=5, ymax=5)
      real	       alpha, beta
      real	       ap(apmax), x(xmax), y(ymax)
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         SSPMV, PrintVectorS
*
*       Executable Statements                           
*
      print*
      print*, '   S S P M V  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n
      read*, incx, incy
      read*, alpha, beta
      read 100, uplo
      read*, (x(i),i=1, 1+(n-1)*abs(incx))
      read*, (y(i),i=1, 1+(n-1)*abs(incy))
      read*, (ap(i),i=1,(n*(n+1))/2)
*
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 101, n
      print 102, alpha, beta
      print 103, uplo
      call PrintVectorS(0,n,x,incx,'X ')
      call PrintVectorS(0,n,y,incy,'Y ')
      call PrintVectorS(1,(n*(n+1))/2,ap,1,'AP')
*
*      Call SSPMV subroutine
      call SSPMV(uplo, n, alpha, ap, x, incx, beta, y, incy)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorS(1,n,y,incy,'Y ')
*
 100  format(a1)
 101  format(7x,'N=',i1)
 102  format(7x,'ALPHA=',f4.1,'  BETA=',f4.1)
 103  format(7x,'UPLO=',a1)
      stop
      end
