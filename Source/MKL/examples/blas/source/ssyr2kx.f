*
*     S S Y R 2 K  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   SSYR2K_MAIN
*
      character*1     uplo, trans
      integer         n, k
      integer         lda, ldb, ldc
      real            alpha, beta
      integer         rmaxa, cmaxa, rmaxb, cmaxb, rmaxc, cmaxc
      parameter       (rmaxa=3, cmaxa=4, rmaxb=5, cmaxb=5,
     $                 rmaxc=3, cmaxc=5)
      parameter       (lda=rmaxa, ldb=rmaxb, ldc=rmaxc)
      real            a(rmaxa,cmaxa), b(rmaxb,cmaxb), c(rmaxc,cmaxc)
*       External Subroutines 
      external        SSYR2K, PrintArrayS
*
*      Executable Statements 
*
      print*
      print*,'   S S Y R 2 K  EXAMPLE PROGRAM'
*
*      Read input data
      read*
      read*, n, k
      read*, alpha, beta
      read 100, uplo, trans
      if ((trans.eq.'N').or.(trans.eq.'n')) then
        read*, ((a(i,j),j=1,k),i=1,n)
        read*, ((b(i,j),j=1,k),i=1,n)
      else
        read*, ((a(i,j),j=1,n),i=1,k)
        read*, ((b(i,j),j=1,n),i=1,k)
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
        call PrintArrayS(0,0,n,k,a,lda,'A')
        call PrintArrayS(0,0,n,k,b,ldb,'B')
      else
        call PrintArrayS(0,0,k,n,a,lda,'A')
        call PrintArrayS(0,0,k,n,b,ldb,'B')
	end if
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintArrayS(0,1,n,n,c,ldc,'C')
      else
        call PrintArrayS(0,-1,n,n,c,ldc,'C')
	end if
*
*      Call SSYR2K subroutine
      call SSYR2K(uplo, trans, n, k, alpha, a, lda, b, ldb,
     $            beta, c, ldc)
*
      print*
      print*, '     OUTPUT DATA'      
      if ((uplo.eq.'U').or.(uplo.eq.'u')) then
        call PrintArrayS(1,1,n,n,c,ldc,'C')
      else
        call PrintArrayS(1,-1,n,n,c,ldc,'C')
	end if
*
 100  format(2(a1,1x))
 101  format(7x,'N=',i1,'  K=',i1)
 102  format(7x,'ALPHA=',f3.1,'  BETA=',f3.1)
 103  format(7x,'UPLO=',a1, '  TRANS=',a1)
      stop
      end
