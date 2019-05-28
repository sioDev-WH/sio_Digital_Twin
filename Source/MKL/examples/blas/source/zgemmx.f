*
*      Z G E M M  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   ZGEMM_MAIN
*
      character*1     transa, transb
      integer         m, n, k
      integer         lda, ldb, ldc
      complex*16      alpha, beta
      integer         rmaxa, cmaxa, rmaxb, cmaxb, rmaxc, cmaxc
      parameter       (rmaxa=5, cmaxa=4, rmaxb=5, cmaxb=5,
     $                rmaxc=5, cmaxc=5)
      parameter       (lda=rmaxa, ldb=rmaxb, ldc=rmaxc)
      complex*16      a(rmaxa,cmaxa), b(rmaxb,cmaxb), c(rmaxc,cmaxc)
*       External Subroutines 
      external        ZGEMM, PrintArrayZ
*
*      Executable Statements 
*
      print*
      print*,'    Z G E M M  EXAMPLE PROGRAM'
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
        call PrintArrayZ(0,0,m,k,a,lda,'A')
      else
        call PrintArrayZ(0,0,k,m,a,lda,'A')
	end if
      if ((transb.eq.'N').or.(transb.eq.'n')) then
        call PrintArrayZ(0,0,k,n,b,ldb,'B')
      else
        call PrintArrayZ(0,0,n,k,b,ldb,'B')
	end if
	call PrintArrayZ(0,0,m,n,c,ldc,'C')
*
*      Call ZGEMM subroutine
      call ZGEMM(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc)
*
      print*
      print*, '     OUTPUT DATA'      
      call PrintArrayZ(1,0,m,n,c,ldc,'C')
*
 100  format(2(a1,1x))
 101  format(7x,'M=',i1,'  N=',i1,'  K=',i1)
 102  format(7x,'ALPHA=(',f5.2,',',f5.2,' )',
     $          '  BETA=(',f5.2,',',f5.2,' )')
 103  format(7x,'TRANSA=',a1, '  TRANSB=',a1)
      stop
      end
