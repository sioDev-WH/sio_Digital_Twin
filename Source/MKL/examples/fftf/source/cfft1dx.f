*
*     C F F T 1 D  Example Program Text
*     CopyRight 1999 Intel Corporation
*

      program  CFFT1D_MAIN
*
      integer      n, isign 
      parameter  ( n = 16 )
	  integer      rmax, wmax
	  parameter  ( rmax = n, wmax = (3*n)/2 )
      complex      r(rmax), r0(rmax), wsave(wmax) 

      integer    i
      real       step0, step, pi
      parameter  (pi=3.1416)

*	 Intrinsic Functions
      intrinsic  sin, cmplx, sqrt
*        External Subroutines 
      external   CFFT1D
*
*   Executable Statementcs    
*    
      print*
      print*,'            C F F T 1 D  EXAMPLE PROGRAM'

*       Read input data from input file 
      read*
      read*, isign
      step0=(2.0*pi)/float(n)
      step=-pi
      do i=1,n
	  r(i)=cmplx((sin(step)*sqrt(3.0))/float(2),sin(step)/sqrt(3.0))
	  r0(i)=r(i)
	  step=step+step0
      end do

*      Call CFFT1D subroutine
*
      call CFFT1D(r, n, 0, wsave)
      call CFFT1D(r, n, isign, wsave)

*       Print input and output data
      print 100, n, isign
      print 101
      do i=1,n
        print 102, r0(i), r(i)
      end do

 100  format(/9x,'N=',i2,'  ISIGN=',i2)
 101  format(9x,'INPUT VECTOR R',20x,'OUTPUT VECTOR R')
 102  format(7x,'(',f9.6,',',f9.6,' )',12x,'(',f9.6,',',f9.6,' )    ')
      stop
      end
