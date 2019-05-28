*
*     C S F F T 2 D  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  CSFFT2D_MAIN
*
      integer     m, n 
      integer     rrow, rcol, zrow, zcol
      parameter   (rrow = 10, rcol = 6)
      parameter   (zrow = 8,  zcol = 4)
      real        r(rrow,rcol), r0(rrow,rcol)
      complex     z(zrow,zcol)
      integer     i, j
*        Intrinsic Functions 
      intrinsic   real, aimag
*        External Subroutines 
      external    CSFFT2D
*                               
*        Executable Statementcs         
*                                
*
*      call MKLStart()
*
      print*,'        C S F F T 2 D  EXAMPLE PROGRAM'
*
*        Read input parameters
      read*
      read*, m, n
      read*, (z(1,j),j=1,n/2+1)
      read*, ((z(i,j),j=1,n),i=2,m/2)
      read*, (z(m/2+1,j),j=1,n/2+1)
      do j=1, n/2+1
          z(1,n/2+1+j) = conjg(z(1,n/2+1-j))
          r(1,2*j-1) = real(z(1,j))
          r(1,2*j) = aimag(z(1,j))
      end do
      do j=1, n/2+1
          z(m/2+1,n/2+1+j) = conjg(z(m/2+1,n/2+1-j))
          r(m+1,2*j-1) = real(z(m/2+1,j))
          r(m+1,2*j) = aimag(z(m/2+1,j))
      end do
      do i = 1, m/2-1
          do j = 1, n
              z(m/2+1+i,j) = conjg(z(m/2+1-i,j))
              r(2*i+1,j) = real(z(i+1,j))
              r(2*i+2,j) = aimag(z(i+1,j))
          end do
      end do     
      call scopy(rrow*rcol, r, 1, r0, 1)
*
*        Call CSFFT2D subroutine
      call CSFFT2D(r, m, n)  
*
*        Print input and output data
      print 100, m, n
      print*, '     COMPLEX TWO_DIMENSION SEQUENCE Z(I,J)' 
      do i = 1, m
          print 101, (z(i,j),j=1,n)
      end do
      print*
      print*, '     INPUT VECTOR R(I,J)' 
      print 102, (r0(1,j),j=1,n+2)
      print 102, (r0(2,j),j=1,n+2)
      do i = 3, m 
          print 102, (r0(i,j),j=1,n)
      end do
      print 102, (r0(m+1,j),j=1,n+2)
      print 102, (r0(m+2,j),j=1,n)
      print*
      print*, '     OUTPUT VECTOR R(I,J)' 
      do i = 1, m 
          print 102, (r(i,j),j=1,n)
      end do
*
 100  format(/5x,'M=',i2,'  N=',i2/)
 101  format(7x,4('(',f6.3,',',f6.3,')',3x))
 102  format(9x,6(f6.3,3x))
*
*      call MKLEnd()
*
      stop
      end
