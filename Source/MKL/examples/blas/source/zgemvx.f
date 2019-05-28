*
*     Z G E M V  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   ZGEMV_MAIN
*
      character*1      trans
      integer          m, n, lda, incx, incy
      integer          mmax, nmax, xmax, ymax
      parameter        (mmax=4, nmax=5, xmax=5, ymax=5)
      parameter        (lda=mmax)
      complex*16       alpha, beta
      complex*16       a(mmax,nmax), x(xmax), y(ymax)
      integer          i, j 
*       Intrinsic Functions
      intrinsic        abs
*       External Subroutines 
      external         ZGEMV, PrintVectorZ, PrintArrayZ
*
*       Executable Statements                           
*
      print*
      print*, '   Z G E M V  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, m, n
      read*, incx, incy
      read*, alpha, beta
      read 100, trans
      if ((trans.eq.'N').or.(trans.eq.'n')) then
        read*,(x(i),i=1, 1+(n-1)*abs(incx))
        read*,(y(i),i=1, 1+(m-1)*abs(incy))
      else
        read*,(x(i),i=1, 1+(m-1)*abs(incx))
        read*,(y(i),i=1, 1+(n-1)*abs(incy))
      end if
      read*, ((a(i,j),j=1,n),i=1,m)
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 101, m, n
      print 102, alpha, beta
      print 103, trans
      if ((trans.eq.'N').or.(trans.eq.'n')) then
        call PrintVectorZ(0,n,x,incx,'X ')
        call PrintVectorZ(0,m,y,incy,'Y ')
      else
        call PrintVectorZ(0,m,x,incx,'X ')
        call PrintVectorZ(0,n,y,incy,'Y ')
      end if
      call PrintArrayZ(0,0,m,n,a,lda,'A')
*
*      Call ZGEMV subroutine
      call ZGEMV(trans,m,n,alpha,a,lda,x,incx,beta,y,incy)
*
      print*
      print*, '     OUTPUT DATA'
      if ((trans.eq.'N').or.(trans.eq.'n')) then
        call PrintVectorZ(0,m,y,incy,'Y ')
      else
        call PrintVectorZ(0,n,y,incy,'Y ')
      end if
*
 100  format(a1)
 101  format(7x,'M=',i1,'  N=',i1)
 102  format(7x,'ALPHA=(',f4.1,',',f4.1,')  BETA=(',f4.1,',',f4.1,')')
 103  format(7x,'TRANS=',a1)
      stop
      end
