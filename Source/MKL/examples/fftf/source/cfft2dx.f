*
*     C F F T 2 D   Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  SCFFT1D_MAIN
*
      integer    m, n, isign
      integer    row, col
      parameter (row = 8, col = 4)
      complex    r(row,col), r0(row,col)
      real       step0, step
      real       pi
      parameter (pi=3.1416)
      integer    i, j
*        Intrinsic Functions 
      intrinsic  sin, sqrt, cmplx
*        External Subroutines 
      external   CFFT2D
*                                 
*    Executable Statementcs          
*                                
      print*,'        C F F T 2 D  EXAMPLE PROGRAM'
*
*        Read input parameters
      read*
      read*, m, n, isign
      step = -pi
      step0 = (2.0*pi)/float(m)
      do i = 1, m
         r(i,1)=cmplx((sin(step)*sqrt(3.0))/2.0,sin(step)/sqrt(3.0))
         do j = 2,n
             r(i,j) = r(i,1)
         end do
         step = step + step0
      end do
      call ccopy(row*col, r, 1, r0, 1)

*      Call CFFT2D subroutine 
      call CFFT2D(r, m, n, isign)  
*
*        Print input and output data
      print 100, m, n, isign
      print*, '       INPUT ARRAY'
      do i = 1, m
          print 101, (r0(i,j),j=1,n)
      end do
      print*, '       OUTPUT ARRAY'
      do i = 1, m
          print 101, (r(i,j),j=1,n)
      end do
  100 format(/7x,'M=',i2,'  N=',i2,'  ISIGN=',i2/)
  101 format(4(f9.5,',',f9.5,1x))
      stop
      end
