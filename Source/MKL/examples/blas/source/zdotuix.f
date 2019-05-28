*
*     Z D O T U I  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   ZDOTUI_MAIN
*
      integer             nmax, ymax
      parameter           (nmax=10, ymax = 10)
      integer             n
      integer             indx(nmax)
      complex*16          x(nmax), y(ymax)

      complex*16          res
      integer             i, indmax

*       External Function 
      external            ZDOTUI, MaxValue, PrintVectorZ
      complex*16          ZDOTUI
*
*       Executable Statements 
*
      print*
      print*,'   Z D O T U I  EXAMPLE PROGRAM'
*
*       Read input data from input file
      read*
      read*, n
      read*, (x(i),i=1,n)
      read*, (indx(i),i=1,n)
      indmax = MaxValue(n, indx)      
      read*, (y(i),i=1,indmax)
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      call PrintVectorZ(1,n,x,1,'X ')
      print 101, (indx(i),i=1,n)
      call PrintVectorZ(1,indmax,y,1,'Y ')
*
*       Call ZDOTUI function
      res = ZDOTUI(n,x,indx,y)
*
      print*
      print*, '     OUTPUT DATA'
      print 102, res
*
 100  format(7x,'N=',i2)
 101  format(7x,'VECTOR INDX'/10x,10(i2,1x))
 102  format(11x,'ZDOTUI = (',f6.2,',',f6.2,' )')
      stop
      end
