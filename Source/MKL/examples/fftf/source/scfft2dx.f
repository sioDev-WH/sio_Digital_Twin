*
*     S C F F T 2 D  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SCFFT2D_MAIN
*
      integer     m, n 
      integer     rrow, rcol, zrow, zcol
      parameter   (rrow = 10, rcol = 6)
      parameter   (zrow = 8,  zcol = 4)
      real        r(rrow,rcol), r0(rrow,rcol)
      complex     z(zrow,zcol)

      integer     i, j

*        Intrinsic Functions 
      intrinsic   sin, sqrt, cmplx, conjg
*        External Subroutines 
      external    SCFFT2D
*                               
*        Executable Statementcs         
*                                
*
*      call MKLStart()
*
      print*,'        S C F F T 2 D  EXAMPLE PROGRAM'

*        Read input parameters
      read*
      read*, m, n
      call GetInputArray(r, rrow, m, n)
      call scopy(rrow*rcol, r, 1, r0, 1)

*        Call SCFFT2D subroutine
      call SCFFT2D(r, m, n)  

*        Print input and output data
      print 100, m, n
      print*, '     INPUT VECTOR R(I,J)' 
      do i = 1, m 
          print 101, (r0(i,j),j=1,n)
      end do
      print*
      print*, '     OUTPUT VECTOR R(I,J)' 
      print 101, (r(1,j),j=1,n+2)
      print 101, (r(2,j),j=1,n+2)
      do i = 3, m 
          print 101, (r(i,j),j=1,n)
      end do
      print 101, (r(m+1,j),j=1,n+2)
      print 101, (r(m+2,j),j=1,n)
      print*
      print*, '     MATHEMATICAL RESULT Z(I,J)' 
      do j=1, n/2+1
          z(1,j) = cmplx(r(1,2*j-1), r(1,2*j))
      end do
      do j=1, n/2-1
          z(1,n/2+1+j) = conjg(z(1,n/2+1-j))
      end do
      do j=1, n/2+1
          z(m/2+1,j) = cmplx(r(m+1,2*j-1), r(m+1,2*j))
      end do
      do j=1, n/2-1
          z(m/2+1,n/2+1+j) = conjg(z(m/2+1,n/2+1-j))
      end do
      do i = 1, m/2-1
          do j = 1, n
              z(i+1,j)=cmplx(r(2*i+1,j), r(2*i+2,j))
          end do
      end do
      do i = 1, m/2-1
          do j = 1, n
              z(m/2+1+i,j) = conjg(z(m/2+1-i,j))
          end do
      end do
      do i = 1, m
          print 102, (z(i,j),j=1,n)
      end do

 100  format(/5x,'M=',i2,'  N=',i2/)
 101  format(9x,6(f6.3,2x))
 102  format(7x,4('(',f6.3,',',f6.3,')',3x))
*
*      call MKLEnd()
*
      stop
      end

      subroutine GetInputArray (a, lda, m, n)

      real              a(lda,*)
      integer           m, n

      logical           ResetRandom
      real*8            dtt
      integer           i, j

      double precision  dbeg
      external          dbeg

*     -- Initialize Random Generator
      ResetRandom = .TRUE.
      dtt = dbeg(ResetRandom)

      do i = 1, m
        do j = 1, n
          a(i,j) = dbeg(.FALSE.)
        end do
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
