*
*     S S C T R  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program   SSCTR_MAIN
*
      integer             imax, xmax, ymax
      parameter           (imax=10, xmax=10, ymax=10)
      integer             n, indx(imax)
      real                x(xmax), y(ymax)
      integer             i, indmax
*       External Function 
      external            SSCTR, MaxValue, PrintVectorS
*
*       Executable Statements ..
*
      print*
      print*,'   S S C T R  EXAMPLE PROGRAM'
*
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
      call PrintVectorS(1,n,x,1,'X ')
      print 101, (indx(i),i=1,n)
*
*       Call SSCTR function
      call SSCTR(n,x,indx,y)
*
      print*
      print*, '     OUTPUT DATA'
      indmax = MaxValue(n,indx)
      call PrintVectorS(1,indmax,y,1,'Y ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'VECTOR INDX'/10x,10(i2,1x))
      stop
      end
