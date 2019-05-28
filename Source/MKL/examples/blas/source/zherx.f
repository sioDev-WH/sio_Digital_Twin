*
*     Z H E R  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   ZHER_MAIN
*
      character*1      uplo
      integer          n, lda, incx
      integer          mmax, nmax, xmax
      parameter        (mmax=5, nmax=4, xmax=5)
      parameter        (lda=mmax)
      double precision alpha
      complex*16       a(mmax, nmax), x(xmax)
      integer          i, j
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         ZHER, PrintVectorZ, PrintArrayZ
*
*       Executable Statements                           
*
      print*
      print*, '   Z H E R  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n
      read*, incx
      read*, alpha
      read 100, uplo
      read*, (x(i),i=1, 1+(n-1)*abs(incx))
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        read*, ((a(i,j),j=i,n),i=1,n)
      else
        read*, ((a(i,j),j=1,i),i=1,n)
	end if
*
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 101, n
      print 102, alpha
      print 103, uplo
      call PrintVectorZ(0,n,x,incx,'X ')
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintArrayZ(0,1,n,n,a,lda,'A')
      else
        call PrintArrayZ(0,-1,n,n,a,lda,'A')
	end if
*
*      Call ZHER subroutine
      call ZHER( uplo, n, alpha, x, incx, a, lda )
*
      print*
      print*, '     OUTPUT DATA'
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintArrayZ(1,1,n,n,a,lda,'A')
      else
        call PrintArrayZ(1,-1,n,n,a,lda,'A')
	end if
*
 100  format(a1)
 101  format(7x,'N=',i1)
 102  format(7x,'ALPHA=',f4.1)
 103  format(7x,'UPLO=',a1)
      stop
      end
