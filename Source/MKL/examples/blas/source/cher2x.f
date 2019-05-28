*
*     C H E R 2  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   CHER2_MAIN
*
      character*1      uplo
      integer          n, lda, incx, incy
      integer          mmax, nmax, xmax, ymax
      parameter        (mmax=5, nmax=4, xmax=5, ymax=5)
      parameter        (lda=mmax)
      complex          alpha
      complex          a(mmax, nmax), x(xmax), y(ymax)
      integer          i, j
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         CHER2, PrintVectorC, PrintArrayC
*
*       Executable Statements                           
*
      print*
      print*, '   C H E R 2  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n
      read*, incx, incy
      read*, alpha
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
      print 102, alpha
      print 103, uplo
      call PrintVectorC(0,n,x,incx,'X ')
      call PrintVectorC(0,n,y,incy,'Y ')
	if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintArrayC(0,1,n,n,a,lda,'A')
	else
        call PrintArrayC(0,-1,n,n,a,lda,'A')
	end if
*
*      Call CHER2 subroutine
      call CHER2(uplo, n, alpha, x, incx, y, incy, a, lda)
*
      print*
      print*, '     OUTPUT DATA'
	if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintArrayC(1,1,n,n,a,lda,'A')
	else
        call PrintArrayC(1,-1,n,n,a,lda,'A')
	end if
*
 100  format(a1)
 101  format(7x,'N=',i1)
 102  format(7x,'ALPHA=(',f4.1,',',f4.1,')')
 103  format(7x,'UPLO=',a1)
      stop
      end
