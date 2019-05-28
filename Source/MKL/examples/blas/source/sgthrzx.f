*
*     S G T H R Z  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program SGTHRZ_MAIN     
*
      integer        nmax, ymax
      parameter      (nmax=10,ymax=10)
      integer        n
      integer        indx(nmax)
      real           x(nmax), y(ymax)
 
      integer        i, indmax

*       External Subroutines 
      external       SGTHRZ, MaxValue, PrintVectorS
*
*       Executable Statements 
*
      print*
      print*,'   S G T H R Z  EXAMPLE PROGRAM'
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
      call PrintVectorS(1,indmax,y,1,'Y ')
*
*        Call SGTHRZ subroutine
      call  SGTHRZ(n,y,x,indx)
*
      print*
      print*, '     OUTPUT DATA'
      call PrintVectorS(1,n,x,1,'X ')
      call PrintVectorS(1,indmax,y,1,'Y ')
*
 100  format(7x,'N=',i2)
 101  format(7x,'VECTOR INDX'/10x,10(i2,1x))
      stop
      end
