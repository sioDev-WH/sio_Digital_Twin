*
*     C T R M V  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   CTRMV_MAIN
*
      character*1      uplo, trans, diag
      integer          n, lda, incx
      integer          mmax, nmax, xmax
      parameter        (mmax=5, nmax=4, xmax=10)
      parameter        (lda=mmax)
      complex          a(mmax, nmax), x(xmax)
      integer          i, j
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         CTRMV, PrintVectorC, PrintArrayC
*
*       Executable Statements                           
*
      print*
      print*, '   C T R M V  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n
      read*, incx
      read 100, uplo, trans, diag
      read*, (x(i),i=1, 1+(n-1)*abs(incx))
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
      print 102, uplo, trans, diag
      call PrintVectorC(0,n,x,incx,'X ')
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintArrayC(0,1,n,n,a,lda,'A')
      else
        call PrintArrayC(0,-1,n,n,a,lda,'A')
      end if
*
*      Call CTRMV subroutine
      call CTRMV(uplo, trans, diag, n, a, lda, x, incx)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorC(1,n,x,incx,'X ')
*
 100  format(3(a1,1x))
 101  format(7x,'N=',i1)
 102  format(7x,'UPLO=',a1,'  TRANS=',a1,'  DIAG=',a1)
      stop
      end
