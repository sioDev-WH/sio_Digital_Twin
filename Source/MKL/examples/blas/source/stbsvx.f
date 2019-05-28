*
*     S T B S V  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   STBSV_MAIN
*
      character*1      uplo, trans, diag
      integer          n, k, lda, incx
      integer          mmax, nmax, xmax
      parameter        (mmax=5, nmax=6, xmax=5)
      parameter        (lda=mmax)
      real             a(mmax, nmax), x(xmax)
      integer          i, j, k1
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         STBSV, PrintVectorS, PrintBandArrayS
*
*       Executable Statements                           
*
      print*
      print*, '   S T B S V  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n, k
      read*, incx
      read 100, uplo, trans, diag
      read*, (x(i),i=1, 1+(n-1)*abs(incx))
      if (k.ge.n) then
         k1 = n-1
      else 
         k1 = k
      end if
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        read*, ((a(k-k1+i,j),j=k1+2-i,n),i=1,k1+1)
      else
        do i = 1, k1+1
           read*, (a(i,j),j=1,n+1-i)
        end do
      end if
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 101, n, k
      print 102, uplo, trans, diag
      call PrintVectorS(0,n,x,incx,'X ')
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintBandArrayS(1,0,k,n,n,a,lda,'A')
      else
        call PrintBandArrayS(1,k,0,n,n,a,lda,'A')
      end if
*
*      Call STBSV subroutine
      call STBSV( uplo, trans, diag, n, k, a, lda, x, incx )
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorS(1,n,x,incx,'X ')
*
 100  format(3(a1,1x))
 101  format(7x,'N=',i1,'  K=',i1)
 102  format(7x,'UPLO=',a1,'  TRANS=',a1,'  DIAG=',a1)
      stop
      end
