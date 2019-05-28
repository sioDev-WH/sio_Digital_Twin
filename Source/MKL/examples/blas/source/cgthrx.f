*
*     C G T H R  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program CGTHR_MAIN     
*
      integer        nmax, ymax
      parameter      (nmax=10, ymax=10)
      integer        n
      integer        indx(nmax)
      complex        y(ymax), x(nmax)

      integer        i, indmax

*       External Subroutines 
      external       CGTHR, MaxValue, PrintVectorC
*
*       Executable Statements 
*
      print*
      print*,'   C G T H R  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, n
      read*, (indx(i),i=1,n)
      indmax = MaxValue(n,indx)
      read*, (y(i),i=1,indmax)
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, n
      print 101, (indx(i),i=1,n)
      call PrintVectorC(1,indmax,y,1,'Y ')
*
*        Call CGTHR subroutine
      call  CGTHR(n,y,x,indx)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorC(1,n,x,1,'X ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'VECTOR INDX'/10x,10(i2,1x))
      stop
      end
