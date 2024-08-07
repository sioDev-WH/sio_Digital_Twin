*
*     S R O T I  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SROTI_MAIN
*
      integer    nmax, ymax
      parameter  (nmax=10, ymax=10) 
      integer    n 
      real       c, s
      real       x(nmax), y(ymax)
      integer    indx(nmax)
 
      integer    i

*       External Subroutines 
      external   SROTI, MaxValue, PrintVectorS
*
*       Executable Statements    
*    
      print*
      print*,'   S R O T I  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n
      read*, c, s
      read*, (x(i),i=1,n)
      read*, (indx(i),i=1,n)
      indmax = MaxValue(n,indx)
      read*, (y(i),i=1,indmax)
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      print 101, c, s
      print 102, (indx(i),i=1,n)
      call PrintVectorS(1,n,x,1,'X ')
      call PrintVectorS(1,indmax,y,1,'Y ')
*
*       Call SROTI subroutine
      call SROTI(n,x,indx,y,c,s)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorS(1,n,x,1,'X ')
      call PrintVectorS(1,indmax,y,1,'Y ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'C=',f4.1,'  S=',f4.1)
 102  format(7x,'VECTOR INDX'/10x,10(i2,1x))
      stop
      end
 