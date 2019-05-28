*
*     D R O T G  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  DROTG_MAIN
*
      double precision  c, s
      double precision  sa, sb
*       External Subroutines 
      external   DROTG
*
*       Executable Statements    
*    
      print*
      print*,'   D R O T G  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, sa, sb
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, sa, sb
*
*       Call DROTG subroutine
      call DROTG(sa,sb,c,s)
*
      print*
      print*, '     OUTPUT DATA'
      print 100, sa, sb
      print 101, c,  s
*
 100  format(7x,'SA=',f6.3,'  SB=',f6.3)
 101  format(7x,' C=',f6.3,'   S=',f6.3)
      stop
      end
 