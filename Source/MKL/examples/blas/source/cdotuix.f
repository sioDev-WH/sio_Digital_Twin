*
*     C D O T U I  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   CDOTUI_MAIN
*
      integer             nmax, ymax
      parameter           (nmax=10, ymax = 15)
      integer             n
      integer             indx(nmax)
      complex             x(nmax), y(ymax)

      integer             i, indmax
      complex             res

*       External Function 
      external            CDOTUI, MaxValue, PrintVectorC
      complex             CDOTUI
*
*       Executable Statements 
*
      print*
      print*,'   C D O T U I  EXAMPLE PROGRAM'
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
      call PrintVectorC(1,n,x,1,'X ')
      print 101, (indx(i),i=1,n)
      call PrintVectorC(1,indmax,y,1,'Y ')
*
*       Call CDOTUI function
      res = CDOTUI(n,x,indx,y)
*
      print*
      print*, '     OUTPUT DATA'
      print 102, res
*
 100  format(7x,'N=',i2)
 101  format(7x,'VECTOR INDX'/10x,10(i2,1x))
 102  format(11x,'CDOTUI = (',f6.2,',',f6.2,' )')
      stop
      end
