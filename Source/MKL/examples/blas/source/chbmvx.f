*
*     C H B M V  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   CHBMV_MAIN
*
      character*1      uplo
      integer          n, k, lda, incx, incy
      integer          mmax, nmax, xmax, ymax
      parameter        (mmax=6, nmax=6, xmax=5, ymax=5)
      parameter        (lda=mmax)
      complex          alpha, beta
      complex          a(mmax,nmax), x(xmax), y(ymax)
      integer          i, j, k1 
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         CHBMV, PrintVectorC, PrintBandArrayC
*
*       Executable Statements                           
*
      print*
      print*, '   C H B M V  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n, k
      read*, incx, incy
      read*, alpha, beta
      read 100, uplo
      read*, (x(i),i=1, 1+(n-1)*abs(incx))
      read*, (y(i),i=1, 1+(n-1)*abs(incy))
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
      print 102, alpha, beta
      print 103, uplo
      call PrintVectorC(0,n,x,incx,'X ')
      call PrintVectorC(0,n,y,incy,'Y ')
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintBandArrayC(1,0,k,n,n,a,lda,'A')
      else
        call PrintBandArrayC(1,k,0,n,n,a,lda,'A')
      end if
*
*      Call CHBMV subroutine
      call CHBMV( uplo, n, k, alpha, a, lda, x, incx,
     $            beta, y, incy )
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorC(1,n,y,incy,'Y ')
*
 100  format(a1)
 101  format(7x,'N=',i1,'  K=',i1)
 102  format(7x,'ALPHA=(',f4.1,',',f4.1,')  BETA=(',f4.1,',',f4.1,')')
 103  format(7x,'UPLO=',a1)
      stop
      end
