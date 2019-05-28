*
*     S G E M M  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   SGEMM_MAIN
*
      character*1     transa, transb
      integer         m, n, k
      integer         lda, ldb, ldc
      real            alpha, beta
      integer         rmaxa, cmaxa, rmaxb, cmaxb, rmaxc, cmaxc
      parameter       (rmaxa=3, cmaxa=4, rmaxb=4, cmaxb=5,
     $                 rmaxc=3, cmaxc=5)
      parameter       (lda=rmaxa, ldb=rmaxb, ldc=rmaxc)
      real            a(rmaxa,cmaxa), b(rmaxb,cmaxb), c(rmaxc,cmaxc)
*       External Subroutines 
      external        SGEMM, PrintArrayS
*
*      Executable Statements 
*
      print*
      print*,'   S G E M M  EXAMPLE PROGRAM'
*
*      Read input data
      read*
      read*, m, n, k
      read*, alpha, beta
      read 100, transa, transb
      if ((transa.eq.'N').or.(transa.eq.'n')) then
        read*, ((a(i,j),j=1,k),i=1,m)
      else
        read*, ((a(i,j),j=1,m),i=1,k)
	end if
      if ((transb.eq.'N').or.(transb.eq.'n')) then
        read*, ((b(i,j),j=1,n),i=1,k)
      else
        read*, ((b(i,j),j=1,k),i=1,n)
	end if
      read*, ((c(i,j),j=1,n),i=1,m)
*
*       Print input data
      print*      
      print*, '     INPUT DATA'      
      print 101, m, n, k
      print 102, alpha, beta
      print 103, transa, transb
      if ((transa.eq.'N').or.(transa.eq.'n')) then
        call PrintArrayS(0,0,m,k,a,lda,'A')
      else
        call PrintArrayS(0,0,k,m,a,lda,'A')
	end if
      if ((transb.eq.'N').or.(transb.eq.'n')) then
        call PrintArrayS(0,0,k,n,b,ldb,'B')
      else
        call PrintArrayS(0,0,n,k,b,ldb,'B')
	end if
	call PrintArrayS(0,0,m,n,c,ldc,'C')
*
*      Call SGEMM subroutine
      call SGEMM(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)
*
      print*
      print*, '     OUTPUT DATA'      
      call PrintArrayS(1,0,m,n,c,ldc,'C')
*
 100  format(2(a1,1x))
 101  format(7x,'M=',i1,'  N=',i1,'  K=',i1)
 102  format(7x,'ALPHA=',f4.1,'  BETA=',f4.1)
 103  format(7x,'TRANSA=',a1, '  TRANSB=',a1)
      stop
      end
