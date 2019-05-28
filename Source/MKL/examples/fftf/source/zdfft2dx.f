*
*     Z D F F T 2 D  Example Program Text
*     CopyRight 1999 Intel Corporation
*
      program  ZDFFT2D_MAIN

      integer           m, n 
      integer           rrow, rcol, zrow, zcol
      parameter        (rrow = 10, rcol = 6)
      parameter        (zrow = 8,  zcol = 4)
	  double precision  r(rrow,rcol), r0(rrow,rcol)
      complex*16        z(zrow,zcol)

      integer           i, j

*        Intrinsic Functions 
      intrinsic         dble, dimag, conjg
*        External Subroutines 
      external          ZDFFT2D
*                               
*        Executable Statementcs         
*                                
*
*      call MKLStart()
*
      print*,'        Z D F F T 2 D  EXAMPLE PROGRAM'

*        Read input data
      read*
      read*, m, n
      read*, (z(1,j),j=1,n/2+1)
      read*, ((z(i,j),j=1,n),i=2,m/2)
      read*, (z(m/2+1,j),j=1,n/2+1)
      do j=1, n/2+1
        z(1,n/2+1+j) = conjg(z(1,n/2+1-j))
        r(1,2*j-1) = dble(z(1,j))
        r(1,2*j) = dimag(z(1,j))
      end do
      do j=1, n/2+1
        z(m/2+1,n/2+1+j) = conjg(z(m/2+1,n/2+1-j))
        r(m+1,2*j-1) = dble(z(m/2+1,j))
        r(m+1,2*j) = dimag(z(m/2+1,j))
      end do
      do i = 1, m/2-1
        do j = 1, n
          z(m/2+1+i,j) = conjg(z(m/2+1-i,j))
          r(2*i+1,j) = dble(z(i+1,j))
          r(2*i+2,j) = dimag(z(i+1,j))
        end do
      end do     
      call dcopy(rrow*rcol,r,1,r0,1)

*        Call ZDFFT2D subroutine
      call ZDFFT2D(r, m, n)  

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

 100  format(/5x,'M=',i2,'  N=',i2/)
 101  format(7x,4('(',f6.3,',',f6.3,')',3x))
 102  format(7x,6(f6.3,3x))
*
*      call MKLEnd()
*
      stop
      end

