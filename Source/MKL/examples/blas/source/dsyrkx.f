*
*     D S Y R K  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   DSYRK_MAIN
*
      character*1       uplo, trans
      integer           n, k
      integer           lda, ldc
      double precision  alpha, beta
      integer           rmaxa, cmaxa, rmaxc, cmaxc
      parameter         (rmaxa=5, cmaxa=5, rmaxc=5, cmaxc=5)
      parameter         (lda=rmaxa, ldc=rmaxc)
      double precision  a(rmaxa,cmaxa), c(rmaxc,cmaxc)
*       External Subroutines 
      external          DSYRK, PrintArrayD
*
*      Executable Statements 
*
      print*
      print*,'   D S Y R K  EXAMPLE PROGRAM'
*
*      Read input data
      read*
      read*, n, k
      read*, alpha, beta
      read 100, uplo, trans
      if ((trans.eq.'N').or.(trans.eq.'n')) then
        read*, ((a(i,j),j=1,k),i=1,n)
      else
        read*, ((a(i,j),j=1,n),i=1,k)
	end if
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        read*, ((c(i,j),j=i,n),i=1,n)
      else
        read*, ((c(i,j),j=1,i),i=1,n)
	end if
*
*       Print input data
      print*      
      print*, '     INPUT DATA'      
      print 101, n, k
      print 102, alpha, beta
      print 103, uplo, trans
      if ((trans.eq.'N').or.(trans.eq.'n')) then
        call PrintArrayD(0,0,n,k,a,lda,'A')
      else
        call PrintArrayD(0,0,k,n,a,lda,'A')
	end if
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintArrayD(0,1,n,n,c,ldc,'C')
      else
        call PrintArrayD(0,-1,n,n,c,ldc,'C')
	end if
*
*      Call DSYRK subroutine
      call DSYRK(uplo, trans, n, k, alpha, a, lda, beta, c, ldc)
*
      print*
      print*, '     OUTPUT DATA'      
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintArrayD(1,1,n,n,c,ldc,'C')
      else
        call PrintArrayD(1,-1,n,n,c,ldc,'C')
	end if
*
 100  format(2(a1,1x))
 101  format(7x,'N=',i1,'  K=',i1)
 102  format(7x,'ALPHA=',f3.1,'  BETA=',f3.1)
 103  format(7x,'UPLO=',a1, '  TRANS=',a1)
      stop
      end
