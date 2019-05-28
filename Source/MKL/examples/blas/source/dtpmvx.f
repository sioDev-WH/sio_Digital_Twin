*
*     D T P M V  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   DTPMV_MAIN
*
      character*1      uplo, trans, diag
      integer          n, incx
      integer          apmax, xmax
      parameter        (apmax=15, xmax=10)
      double precision ap(apmax), x(xmax)
      integer          i
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         DTPMV, PrintVectorD
*
*       Executable Statements                           
*
      print*
      print*, '   D T P M V  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n
      read*, incx
      read 100, uplo, trans, diag
      read*, (x(i),i=1, 1+(n-1)*abs(incx))
      read*, (ap(i),i=1,(n*(n+1))/2)
*
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 101, n
      print 102, uplo, trans, diag
      call PrintVectorD(0,n,x,incx,'X ')
      call PrintVectorD(1,(n*(n+1))/2,ap,1,'AP')
*
*      Call DTPMV subroutine
      call DTPMV(uplo, trans, diag, n, ap, x, incx)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorD(1,n,x,incx,'X ')
*
 100  format(3(a1,1x))
 101  format(7x,'N=',i1)
 102  format(7x,'UPLO=',a1,'  TRANS=',a1,'  DIAG=',a1)
      stop
      end