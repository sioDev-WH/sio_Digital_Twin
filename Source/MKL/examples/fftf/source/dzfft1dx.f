*
*     D Z F F T 1 D  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  DZFFT1D_MAIN

      integer          n, isign 
      parameter      ( n = 16 )
      integer          rmax, wmax
      parameter      ( rmax = n+2, wmax = 2*n+4 )
      double precision r(rmax), r0(rmax)
      double precision wsave(wmax)

      integer          i

*        External Subroutines 
      external         DZFFT1D
*                               
*        Executable Statementcs         
*                                
      print*,'        D Z F F T 1 D  EXAMPLE PROGRAM'

*        Read input parameters
      read*
      read*, isign
      call GetInputVector(r, n)
      call dcopy(n, r, 1, r0, 1)

*        Call DZFFT1D subroutine
      call DZFFT1D(r, n, 0, wsave)
      call DZFFT1D(r, n, isign, wsave)  

*        Print input and output data
      print 100, n, isign
      print 101 
      do i = 0, n/2 
         print 102, r0(i+1), r(i+1), r(2*i+1), r(2*i+2)
      end do
      do i = 1, n/2-1
         temp = -r(n-2*i+2)
         print 102, r0(n/2+i+1), r(n/2+i+1), r(n-2*i+1), temp
      end do
      print 103, r(n+1)
      print 103, r(n+2)

 100  format(/5x,'N=',i2,'  ISIGN=',i2)
 101  format(5x,'INPUT VECTOR',9x,'OUTPUT VECTOR',6x,
     $       'MATHEMATICAL RESULT'/11x,'R',18x,'R',14x,
     $       'COMPLEX VECTOR Z(I)')
 102  format(8x,f6.3,13x,f6.3,12x,'(',f6.3,',',f6.3,' )')
 103  format(27x,f6.3)
      stop
      end

      subroutine GetInputVector (x, n)

      double precision  x(*)
      integer           n

      logical           ResetRandom
      real*8            dtt
      integer           i

      double precision  dbeg
      external          dbeg

*     -- Initialize Random Generator
      ResetRandom = .TRUE.
      dtt = dbeg(ResetRandom)

      do i = 1, n
          x(i) = dbeg(.FALSE.)
      end do

      return
      end

      DOUBLE PRECISION FUNCTION DBEG( RESET )
*
*  Generates random numbers uniformly distributed between -0.5 and 0.5.
*
*  Auxiliary routine for test program for Level 3 Blas.
*
*  -- Written on 8-February-1989.
*     Jack Dongarra, Argonne National Laboratory.
*     Iain Duff, AERE Harwell.
*     Jeremy Du Croz, Numerical Algorithms Group Ltd.
*     Sven Hammarling, Numerical Algorithms Group Ltd.
*
*     .. Scalar Arguments ..
      LOGICAL            RESET
*     .. Local Scalars ..
      INTEGER            I, IC, MI
*     .. Save statement ..
      SAVE               I, IC, MI
*     .. Executable Statements ..
      IF( RESET )THEN
*        Initialize local variables.
         MI = 891
         I = 7
         IC = 0
         RESET = .FALSE.
      END IF
*
*     The sequence of values of I is bounded between 1 and 999.
*     If initial I = 1,2,3,6,7 or 9, the period will be 50.
*     If initial I = 4 or 8, the period will be 25.
*     If initial I = 5, the period will be 10.
*     IC is used to break up the period by skipping 1 value of I in 6.
*
      IC = IC + 1
   10 I = I*MI
      I = I - 1000*( I/1000 )
      IF( IC.GE.5 )THEN
         IC = 0
         GO TO 10
      END IF
      DBEG = ( I - 500 )/1001.0D0
      RETURN
*
*     End of DBEG.
*
      END
