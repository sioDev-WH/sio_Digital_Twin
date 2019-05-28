*
*     C H P R 2  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   CHPR2_MAIN
*
      character*1      uplo
      integer          n, incx, incy
      integer          apmax, xmax, ymax
      parameter        (apmax=15, xmax=5, ymax=5)
      complex          alpha
      complex          ap(apmax), x(xmax), y(ymax)
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         CHPR2, PrintVectorC
*
*       Executable Statements                           
*
      print*
      print*, '   C H P R 2  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n
      read*, incx, incy
      read*, alpha
      read 100, uplo
      read*, (x(i),i=1, 1+(n-1)*abs(incx))
      read*, (y(i),i=1, 1+(n-1)*abs(incy))
      read*, (ap(i),i=1,(n*(n+1))/2)
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 101, n
      print 102, alpha
      print 103, uplo
      call PrintVectorC(0,n,x,incx,'X ')
      call PrintVectorC(0,n,y,incy,'Y ')
      call PrintVectorC(1,(n*(n+1))/2,ap,1,'AP')
*
*      Call CHPR2 subroutine
      call CHPR2( uplo, n, alpha, x, incx, y, incy, ap)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorC(1,(n*(n+1))/2,ap,1,'AP')
*
 100  format(a1)
 101  format(7x,'N=',i1)
 102  format(7x,'ALPHA=(',f4.1,',',f4.1,')')
 103  format(7x,'UPLO=',a1)
      stop
      end
