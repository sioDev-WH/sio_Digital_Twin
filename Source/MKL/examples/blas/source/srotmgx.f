*
*     S R O T M G  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SROTMG_MAIN
*
      real       param(5)
      real       sd1, sd2, sx1, sy1 
*       External Subroutines 
      external   SROTMG
*
*       Executable Statements    
*    
      print*
      print*,'   S R O T M G  EXAMPLE PROGRAM'
*       Read input data from input file 
      read*
      read*, sd1, sd2, sx1, sy1
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, sd1, sd2, sx1, sy1
*
*       Call SROTMG subroutine
      call SROTMG(sd1,sd2,sx1,sy1,param)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, sd1, sd2, sx1 
      print 102, (param(i), i=1,5)
*
 100  format(7x,'SD1=',f4.1,'  SD2=',f4.1,'  SX1=',f4.1,
     $       '  SY1=',f4.1)
 101  format(7x,'SD1=',f5.2,'  SD2=',f5.2,'  SX1=',f5.2)
 102  format(7x,'VECTOR PARAM'/9x,5(f6.2,1x))
      stop
      end
 