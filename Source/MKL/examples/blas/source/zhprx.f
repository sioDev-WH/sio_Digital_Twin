*
*     Z H P R  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   ZHPR_MAIN
*
      character*1      uplo
      integer          n, incx
      integer          apmax, xmax
      parameter        (apmax=15, xmax=5)
      double precision alpha
      complex*16       ap(apmax), x(xmax)
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         ZHPR, PrintVectorZ
*
*       Executable Statements                           
*
      print*
      print*, '   Z H P R  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n
      read*, incx
      read*, alpha
      read 100, uplo
      read*, (x(i),i=1, 1+(n-1)*abs(incx))
      read*, (ap(i),i=1,(n*(n+1))/2)
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 101, n
      print 102, alpha
      print 103, uplo
      call PrintVectorZ(0,n,x,incx,'X ')
      call PrintVectorZ(1,(n*(n+1))/2,ap,1,'AP')
*
*      Call ZHPR subroutine
      call ZHPR(uplo, n, alpha, x, incx, ap)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorZ(1,(n*(n+1))/2,ap,1,'AP')
*
 100  format(a1)
 101  format(7x,'N=',i1)
 102  format(7x,'ALPHA=',f4.1)
 103  format(7x,'UPLO=',a1)
      stop
      end
