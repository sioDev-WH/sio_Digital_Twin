*
*     Z R O T G  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  ZROTG_MAIN
*
      double precision  c
      complex*16        s, ca, cb
*       External Subroutines 
      external          ZROTG
*
*       Executable Statements    
*    
      print*
      print*,'   Z R O T G  EXAMPLE PROGRAM'
*
*       Read input data from input file 
      read*
      read*, ca, cb
*
*       Print input data
      print*
      print*, '     INPUT DATA'
      print 100, ca, cb
*
*       Call ZROTG subroutine
      call ZROTG(ca,cb,c,s)
*
      print*
      print*, '     OUTPUT DATA'
      print 101, ca
      print 102, c,  s
*
 100  format(7x,'CA=(',f6.3,',',f6.3,')  CB=(',f6.3,',',f6.3,')')
 101  format(7x,'CA=(',f6.3,',',f6.3,')')
 102  format(7x,' C= ',f6.3,11x,'S=(',f6.3,',',f6.3,')')
      stop
      end
 