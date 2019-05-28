*
*     S R O T G  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SROTG_MAIN
*
      real       c, s
      real       sa, sb
*       External Subroutines 
      external   SROTG
*
*       Executable Statements    
*    
      print*
      print*,'   S R O T G  EXAMPLE PROGRAM'
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
*       Call SROTG subroutine
      call SROTG(sa,sb,c,s)
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
 