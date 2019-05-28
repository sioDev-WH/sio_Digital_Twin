*
*     S G E R  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   SGER_MAIN
*
      integer          m, n, lda, incx, incy
      integer          mmax, nmax, xmax, ymax
      parameter        (mmax=4, nmax=5, xmax=5, ymax=5)
      parameter        (lda=mmax)
      real	       alpha
      real	       a(mmax,nmax), x(xmax), y(ymax)
      integer          i, j 
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         SGER, PrintVectorS, PrintArrayS
*
*       Executable Statements                           
*
      print*
      print*, '   S G E R  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, m, n
      read*, incx, incy
      read*, alpha
      read*, (x(i),i=1, 1+(m-1)*abs(incx))
      read*, (y(i),i=1, 1+(n-1)*abs(incy))
      read*, ((a(i,j),j=1,n),i=1,m)
*
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 101, m, n
      print 102, alpha
      call PrintVectorS(0,m,x,incx,'X ')
      call PrintVectorS(0,n,y,incy,'Y ')
      call PrintArrayS(0,0,m,n,a,lda,'A')
*
*      Call SGER subroutine
      call SGER( m, n, alpha, x, incx, y, incy, a, lda )
*
      print*
      print*, '     OUTPUT DATA'
      call PrintArrayS(1,0,m,n,a,lda,'A')
*
 101  format(7x,'M=',i1,'  N=',i1)
 102  format(7x,'ALPHA=',f4.1)
      stop
      end
