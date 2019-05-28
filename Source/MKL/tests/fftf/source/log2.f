* ---------------------------------------------------------
* --                                                     --
* --     L O G 2 ()                                      --
* --                                                     --
* ---------------------------------------------------------

      integer function LOG2(n)


* -- Version: 27.10.95.

* --- Author:
* ---         Fedorova J.G.

* --- Function:
* ---        Integer log2(n)

* --- Implementation:
* ---        On entry:  integer n, must be power of 2
* ---        On return: +integer, - if n is power of  2
* ---                    -1       - if n is not power of 2

* --- Notice:
* ---        n - must be integer*4

* --- Input Arguments
      integer   n

* --- Local Variables
      integer   in, isizeint, msk

* --- Executable Statements

      in = n - 1
      if (in.lt.0) then
         log2 = -1
         RETURN
      end if
      isizeint = 30
      msk = 1
      do log2 = 0, isizeint
         if (in.eq.0) GO TO 10
         in = iand(in,not(msk))
         msk = ishft(msk,1)
      end do
  10  if (n.eq.ishft(1,log2)) RETURN
      log2 = -1
      RETURN
      end

