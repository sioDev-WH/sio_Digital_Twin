*
*     Z S C T R  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   ZSCTR_MAIN
*
      integer             nmax, ymax
      parameter           (nmax=10, ymax=10)
      integer             n
      integer             indx(nmax)
      complex*16          x(nmax), y(ymax)

      integer             i, indmax

*       External Function 
      external            ZSCTR, MaxValue, PrintVectorZ
*
*       Executable Statements ..
*
      print*
      print*,'   Z S C T R  EXAMPLE PROGRAM'
*       Read input data from input file
      read*
      read*, n
      read*, (x(i),i=1,n)
      read*, (indx(i),i=1,n)
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorZ(1,n,x,1,'X ')
      print 101, (indx(i),i=1,n)
*
*       Call ZSCTR function
      call ZSCTR(n,x,indx,y)
*
      print*
      print*, '     OUTPUT DATA'
      indmax = MaxValue(n,indx)
      call PrintVectorZ(1,indmax,y,1,'Y ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'VECTOR INDX'/10x,10(i2,1x))
      stop
      end
