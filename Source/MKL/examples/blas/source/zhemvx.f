*
*     Z H E M V  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   ZHEMV_MAIN
*
      character*1      uplo
      integer          n, lda, incx, incy
      integer          mmax, nmax, xmax, ymax
      parameter        (mmax=5, nmax=4, xmax=5, ymax=5)
      parameter        (lda=mmax)
      complex*16       alpha, beta
      complex*16       a(mmax, nmax), x(xmax), y(ymax)
      integer          i, j
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         ZHEMV, PrintVectorZ, PrintArrayZ
*
*       Executable Statements                           
*
      print*
      print*, '   Z H E M V  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n
      read*, incx, incy
      read*, alpha, beta
      read 100, uplo
      read*, (x(i),i=1, 1+(n-1)*abs(incx))
      read*, (y(i),i=1, 1+(n-1)*abs(incy))
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        read*, ((a(i,j),j=i,n),i=1,n)
      else
        read*, ((a(i,j),j=1,i),i=1,n)
      end if
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 101, n
      print 102, alpha, beta
      print 103, uplo
      call PrintVectorZ(0,n,x,incx,'X ')
      call PrintVectorZ(0,n,y,incy,'Y ')
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintArrayZ(0,1,n,n,a,lda,'A')
      else
        call PrintArrayZ(0,-1,n,n,a,lda,'A')
      end if
*
*      Call ZHEMV subroutine
      call ZHEMV(uplo, n, alpha, a, lda, x, incx,
     $           beta, y, incy)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorZ(1,n,y,incy,'Y ')
*
 100  format(a1)
 101  format(7x,'N=',i1)
 102  format(7x,'ALPHA=(',f4.1,',',f4.1,')  BETA=(',f4.1,',',f4.1,')')
 103  format(7x,'UPLO=',a1)
      stop
      end
