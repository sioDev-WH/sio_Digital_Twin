*
*     D D O T I  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   DDOTI_MAIN
*
      integer             nmax, ymax
      parameter           (nmax=8, ymax = 15)
      integer             n
      integer             indx(nmax)
      double precision    x(nmax), y(ymax)

      double precision    res
      integer             i, indmax

*       External Function 
      external            DDOTI, MaxValue, PrintVectorD
      double precision    DDOTI
*
*       Executable Statements
*
      print*
      print*,'   D D O T I  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n
      read*, (x(i),i=1,n)
      read*, (indx(i),i=1,n)
      indmax = MaxValue(n,indx)
      read*, (y(i),i=1,indmax)
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorD(1,n,x,1,'X ')
      print 101, (indx(i),i=1,n)
      call PrintVectorD(1,indmax,y,1,'Y ')
*
*       Call DDOTI function
      res = DDOTI(n,x,indx,y)
*
      print*
      print*, '     OUTPUT DATA'
      print 102, res
*
 100  format(7x,'N=',i2)
 101  format(7x,'VECTOR INDX'/10x,10(i2,1x))
 102  format(11x,'DDOTI = ',f8.3)
      stop
      end
