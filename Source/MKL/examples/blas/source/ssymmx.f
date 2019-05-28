*
*     S S Y M M  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program SSYMM_MAIN     
*     
      character*1        side, uplo
      integer            m, n, lda, ldb, ldc
      real               alpha, beta
      integer            rmaxa, cmaxa, rmaxb, cmaxb, rmaxc, cmaxc
      parameter          (rmaxa=5, cmaxa=5, rmaxb=5, cmaxb=5,
     $                    rmaxc=5, cmaxc=5)
      parameter          (lda=rmaxa, ldb=rmaxb, ldc=rmaxc)
      real               a(rmaxa, cmaxa), b(rmaxb, cmaxb),
     $                   c(rmaxa, cmaxc)
      integer            i, j
*      External Subroutines 
      external           SSYMM, PrintArrayS
*
*      Executable Statements 
*
      print*
      print*,'   S S Y M M  EXAMPLE PROGRAM'
*       Read input data from input file 
      read*
      read*, m, n
      read*, alpha, beta
      read 100, side, uplo
      if ((side.eq.'L').or.(side.eq.'l')) then
        if ((uplo.eq.'U').or.(uplo.eq.'u')) then
	     read*, ((a(i,j),j=i,m),i=1,m)
	  else
	     read*, ((a(i,j),j=1,i),i=1,m)
	  end if
      else
        if ((uplo.eq.'U').or.(uplo.eq.'u')) then
	     read*, ((a(i,j),j=i,n),i=1,n)
	  else
	     read*, ((a(i,j),j=1,i),i=1,n)
	  end if	  
      end if
      read*, ((b(i,j),j=1,n),i=1,m)
      read*, ((c(i,j),j=1,n),i=1,m)
*
*       Print input data
      print*      
      print*, '     INPUT DATA'      
      print 101, m, n
      print 102, alpha, beta
      print 103, side, uplo
      if ((side.eq.'L').or.(side.eq.'l')) then
        if ((uplo.eq.'U').or.(uplo.eq.'u')) then
          call PrintArrayS(0, 1, m, m, a, lda, 'A')
        else
          call PrintArrayS(0, -1, m, m, a, lda, 'A')
        end if
      else
        if ((uplo.eq.'U').or.(uplo.eq.'u')) then
          call PrintArrayS(0, 1, n, n, a, lda, 'A')
        else
          call PrintArrayS(0, -1, n, n, a, lda, 'A')
        end if
      end if
      call PrintArrayS(0,0,m,n,b,ldb,'B')
	call PrintArrayS(0,0,m,n,c,ldc,'C')
*
*      Call SSYMM subroutine
      call SSYMM(side,uplo,m,n,alpha,a,lda,b,ldb,beta,c,ldc)
*
*       Print output data
      print*
      print*, '     OUTPUT DATA'
      call PrintArrayS(1, 0, m, n, c, ldc, 'C')
*
 100  format(2(a1,1x))
 101  format(7x,'M=',i1,'  N=',i1)
 102  format(7x,'ALPHA=',f3.1,'  BETA=',f3.1)
 103  format(7x,'SIDE=',a1, '  UPLO=',a1)
      stop
      end