*
*     C S C T R  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   CSCTR_MAIN
*
      integer             nmax, ymax
      parameter           (nmax=10, ymax=15)
      integer             n
      integer             indx(nmax)
      complex             x(nmax), y(ymax)

      integer             i, indmax

*       External Function 
      external            CSCTR, MaxValue, PrintVectorC
*
*       Executable Statements ..
*
      print*
      print*,'   C S C T R  EXAMPLE PROGRAM'
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
      call PrintVectorC(1,n,x,1,'X ')
      print 101, (indx(i),i=1,n)
*
*       Call CSCTR function
      call CSCTR(n,x,indx,y)
*
      print*
      print*, '     OUTPUT DATA'
      indmax = MaxValue(n,indx)
      call PrintVectorC(1,indmax,y,1,'Y ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'VECTOR INDX'/10x,10(i2,1x))
      stop
      end
