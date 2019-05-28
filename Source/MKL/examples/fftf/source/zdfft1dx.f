*
*     Z D F F T 1 D  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  ZDFFT1D_MAIN
*
      integer            n, isign 
      parameter        ( n = 16 ) 
      integer            rmax, wmax
      parameter        ( rmax = n+2, wmax = 2*n+4)
      double precision   r(rmax), r0(rmax)
      double precision   wsave(wmax)

      integer          i
      double precision temp, z_real, z_imag

*        External Subroutines 
      external         ZDFFT1D
*                               
*        Executable Statementcs         
*                                
      print*,'            Z D F F T 1 D  EXAMPLE PROGRAM'
*
*        Read input parameters
      read*
      read*, isign
      do i = 0, n/2
         read*, z_real, z_imag
         r(2*i+1) = z_real
         r(2*i+2) = z_imag 
      end do
      call dcopy(n+2, r, 1, r0, 1)
*
*        Call ZDFFT1D subroutine
      call ZDFFT1D(r, n, 0, wsave)
      call ZDFFT1D(r, n, isign, wsave)  
*
*        Print input and output data
      print 100, n, isign
      print 101 
      do i = 0, n/2 
         print 102, r0(2*i+1), r0(2*i+2), r0(i+1), r(i+1) 
      end do
      do i = 1, n/2-1
         temp = -r0(n-2*i+2)
         print 102,  r0(n-2*i+1), temp, r0(n/2+i+1), r(n/2+i+1)
      end do
      print 103, r0(n+1)
      print 103, r0(n+2)
*
 100  format(/9x,'N=',i2,'  ISIGN=',i2)
 101  format(9x,'COMPLEX VECTOR',10x,'INPUT VECTOR',4x,
     $       'OUTPUT VECTOR'/15x,'Z(I)',19x,'R',15x, 'R')
 102  format(9x,'(',f6.3,',',f6.3,' )',10x,f6.3,10x,f6.3)
 103  format(35x,f6.3)
      stop
      end
