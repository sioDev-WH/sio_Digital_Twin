*M/*
*
*  INTEL CORPORATION PROPRIETARY INFORMATION
*  This software is supplied under the terms of a license agreement or
*  nondisclosure agreement with Intel Corporation and may not be copied
*  or disclosed except in accordance with the terms of that agreement.
*  Copyright (c) 1999 Intel Corporation. All Rights Reserved.
*
*      $Workfile$
*      $Revision$
*      $Modtime$
*
*  Contents:
*      Fortran-style one-dimensional FFT test 
*
*  Author  : Gvozdev E., Sivolgina O.
*
*M*/


      Program fft1Dtst
* ----------------------------------------------------------------
* --                    1D FFT Testing                          --
* --                  Subroutines all types:                    --
* --                   zfft1d,  cfft1d                          --
* --                   zdfft1d, dzfft1d                         --
* --                   scfft1d, csfft1d                         --
* ----------------------------------------------------------------

* ---- Parameters
      integer           nsubs, ndim, lmax, ich_in
      integer           nm_dft
      real (KIND=8)     dzero, dhalf, done
      real              szero, shalf, sone
      parameter       ( nsubs = 6 )
      parameter       ( ndim = 21, lmax = 1048576 )
      parameter       ( dzero = 0.d0, dhalf = 0.5d0, done = 1.d0 )
      parameter       ( szero = 0.0, shalf = 0.5, sone = 1.0 )
      parameter       ( ich_in = 5 )
      parameter       ( nm_dft = 6 )

*     -- Information
*     parameter       ( Z_gauge_deg = 1.d1)
*     parameter       ( Zr_gauge_deg = 1.d1)

*     -- Variables

*     -- Channels and files for output
      integer           ich_summ, ich_snap
      character(len=32) fn_summ, fn_snap

*     -- Flags, indicate sucessfull return from Initialization,
*        Error-Exit tests and
*        flag for create Snapshot file
      logical           ok_init, ok_err, atrace

      real (KIND=8)     deps
      real              seps

*     -- Flags for testing types and for subroutines
      logical           tstdft, tstcmpt, tsterr, afatal,
     $                  fatal( nsubs ),
     $                  tst_sub( nsubs ), tst_beg( nsubs ),
     $                  dft_check, self_test

*     ---         numbers of 1 dimension values for testing
      integer     nm
*     ---         values on 1 dimension
      integer     m( ndim ), m_dft(nm_dft)

*     --  Data for DFT testing
      logical           ok_exp

      integer        add_even
      integer        align_max
      parameter      (align_max = 128)

*     align_max must be at least twice smaller REDUNT (bytes)
      integer           REDUNT16, REDUNT8, REDUNT4
      parameter         ( REDUNT16 = 128, REDUNT8 = 128, REDUNT4 = 128 )

      logical        ok_align

*     -- Matrices for testing
*     ---          testing vectors
      complex (KIND=8)        za_tst( lmax+2+REDUNT16 )
      complex           ca_tst( lmax*2+4+REDUNT8 )
*     ---          control vectors
      complex (KIND=8)        za_fexp( lmax+2+REDUNT16 )
      complex           ca_fexp( lmax*2+4+REDUNT8 )
      complex (KIND=8)        za_iexp( lmax+REDUNT16 )
      complex           ca_iexp( lmax*2+REDUNT8 )
*     ---          weigth save vectors
      complex (KIND=8)        zws_exp( lmax+REDUNT16 )
      complex           cws_exp( 2*lmax+REDUNT8 )

      complex (KIND=8)        ztmp( lmax+2+REDUNT16 )
      complex           ctmp( 2*(lmax+2)+REDUNT8 )

      real (KIND=8)            za_tst_r( lmax+2+REDUNT8 )
      real              ca_tst_r( lmax+2+REDUNT4 )
      real (KIND=8)            za_fexp_r( lmax+2+REDUNT8 )
      real              ca_fexp_r( lmax+2+REDUNT4 )
      real (KIND=8)            ztmp_r( lmax+2+REDUNT8 )
      real              ctmp_r( 2*(lmax+2)+REDUNT4 )


      real              a_tst(lmax*4+8+REDUNT4)
      real              a_fexp(lmax*2+REDUNT4)
      real              a_iexp(lmax*2+REDUNT4)
      real              ws_exp(lmax+REDUNT4)
*      real              a_tmp (lmax*4+8+REDUNT4)
      real (KIND=8)     ca_tmp (lmax*4+8+REDUNT4)

      equivalence    (za_tst, ca_tst, za_tst_r, ca_tst_r, a_tst)
      equivalence    (za_fexp, ca_fexp, za_fexp_r, ca_fexp_r, a_fexp)
      equivalence    (za_iexp, ca_iexp, a_iexp)
      equivalence    (zws_exp, cws_exp, ws_exp)
      equivalence    (ztmp, ctmp, ztmp_r, ctmp_r, ca_tmp)

*      integer         a_tst_add, a_fexp_add, a_iexp_add,
*     $                wsexp_add, a_tmp_add

      integer         ca_tst_add, ca_fexp_add, ca_iexp_add,
     $                cwsexp_add, ca_tmp_add
      integer         za_tst_add, za_fexp_add, za_iexp_add,
     $                zwsexp_add, za_tmp_add

      integer         aligning, len_addr
      character(len=32) pchar

      logical        ResetRandom
      integer        isub, isub2

*     ---  names of testing subroutines
      character(len=8)       snames( nsubs )

* --- External Functions
      real (KIND=8)            dCeps, dbeg
      real              sCeps
      logical           Fsub

	external          mkl_aligning
      external          CFFT1D, ZFFT1D 
      external          SCFFT1D, ZDFFT1D, DZFFT1D 
      external          dCeps, sCeps, dbeg, Fsub
      external          LOG2
* --- External Subroutines
      external          Init, Headsumm

      data              snames /'ZFFT1D  ','CFFT1D  ',
     $                          'DZFFT1D ','SCFFT1D ',
     $                          'ZDFFT1D ','CSFFT1D '/

      data              m_dft /64, 128, 256, 512, 1024, 2048/
                                           
* ---- CZ2fft start

*      call MKLSTART()

*      integer  n_proc
                                       
*     -- Job creation
      call Init(  ich_in, snames, ok_init, fn_summ, ich_summ,
     $            fn_snap, ich_snap, afatal, atrace, tstdft,
     $            tsterr, tstcmpt, tst_sub, nm, m, 
     $            dft_check, self_test, deps, seps, aligning)

      close (ich_in)

*     -- Open summary file
      open( ich_summ, FILE = fn_summ, STATUS = 'unknown' )

*     -- Test for job creation
      if (ok_init) then
         write(*, fmt = 7701 ) 'Job creation is O.K.',
     $                         'Begin Tests...'
      else
         write(*, fmt = 7701)
     $               'Error: Something is bad in job creation.',
     $               '******* Tests Abandoned *******'
         write(ich_summ, fmt = 7701 )
     $               'Error: Something is bad in job creation.',
     $               '******* Tests Abandoned *******'
         GO TO 300
      end if

*     -- Initialize Random Generator
      ResetRandom = .TRUE.
      za_tst(1) = dbeg(ResetRandom)

*     -- Compute EPS (the machine precision).
*      deps = dCeps( done, dhalf, dzero )
*      seps = sCeps( sone, shalf, szero )

*     -- Write summary file header
      call Headsumm( ich_summ,
     $            deps, seps, afatal, atrace,
     $            tstdft, tsterr, tstcmpt, tst_sub,
     $            snames, nm, m, dft_check, self_test, aligning )

*     -- Open snap file
      if ( atrace ) then
         open( ich_snap, FILE = fn_snap, STATUS = 'unknown' )
         write(ich_snap, fmt = 7703 ) 'Computational test calls'
      end if

*     --   Data aligning

      call mkl_aligning(ca_tst,  aligning, ca_tst_add,  za_tst_add)
      call mkl_aligning(ca_fexp, aligning, ca_fexp_add, za_fexp_add)
      call mkl_aligning(ca_iexp, aligning, ca_iexp_add, za_iexp_add)
      call mkl_aligning(cws_exp, aligning, cwsexp_add,  zwsexp_add)
      call mkl_aligning(ca_tmp,  aligning, ca_tmp_add,  za_tmp_add)

      print*
      print*,' Aligning from boundary beginning is', aligning, 'bytes'

      call mkl_itoa(ca_tst, len_addr, pchar)
      print*,' Complex                array: hexadecimal address=',
     $         pchar(1:len_addr)  

      call mkl_itoa(ca_tst(ca_tst_add), len_addr, pchar)
      print*,' Complex        aligned array: hexadecimal address=',
     $         pchar(1:len_addr)

	  call mkl_itoa(za_tst, len_addr, pchar)
      print*,' Double complex         array: hexadecimal address=',
     $	     pchar(1:len_addr)
      
	  call mkl_itoa(za_tst(za_tst_add), len_addr, pchar)
      print*,' Double complex aligned array: hexadecimal address=',
     $	     pchar(1:len_addr)

      write(ich_summ,fmt='(/a,i3, a)') 
     $ ' Aligning from boundary beginning is', aligning, ' bytes'

      write(ich_snap,fmt='(/a,i3, a/)') 
     $ ' Aligning from boundary beginning is', aligning, ' bytes'

      call mkl_itoa(ca_tst, len_addr, pchar)
      write(ich_snap,fmt='(a, a)') 
     $' Complex                array: hexadecimal address = ', 
     $ pchar(1:len_addr)

      call mkl_itoa(ca_tst(ca_tst_add), len_addr, pchar)
      write(ich_snap,fmt='(a, a/)') 
     $' Complex aligned        array: hexadecimal address = ',
     $  pchar(1:len_addr)
      
	  call mkl_itoa(za_tst, len_addr, pchar)
      write(ich_snap,fmt='(a, a )') 
     $' Double complex         array: hexadecimal address = ',
     $  pchar(1:len_addr)
      
	  call mkl_itoa(za_tst(za_tst_add), len_addr, pchar)
      write(ich_snap,fmt='(a, a/)') 
     $' Double complex aligned array: hexadecimal address = ', 
     $ pchar(1:len_addr)

*     --   Error - Exits test
      ok_err = .TRUE.
      add_even = 1 - (nsubs - 2*(nsubs/2))

      if (tsterr .and. Fsub( tst_sub, nsubs )) then
         write(*, fmt = 7704 ) '------- Error-Exits Test -------'
         write(ich_summ, fmt = 7704 ) '------- Error-Exits Test -------'

         do isub2 = 1, nsubs*2, 2
            isub = isub2
            if (isub2 .gt. nsubs) isub = isub + add_even - nsubs
            if (tst_sub( isub )) then
              call  Chffterr( ich_summ, isub, snames(isub), za_tst,
     $                        ca_tst, za_tst_r, ca_tst_r, zws_exp,
     $                        cws_exp, ok_err )
              if (.not.ok_err) then
                write(*, fmt = * ) snames(isub), 
     $                ' :   ERROR on Error-Exit test'
                write(ich_summ, fmt = * ) snames(isub), 
     $                ' :   ERROR on Error-Exit test'
                tst_sub( isub ) = .FALSE.
                write(ich_summ, fmt = 7705)
     $             '** Test for routine ', snames( isub ),
     $             ' is break **'
              else
                write(*, fmt = * ) snames(isub), 
     $                ' :   PASSED Error-Exit test'
        
                write(ich_summ, fmt = * ) snames(isub), 
     $                ' :   PASSED Error-Exit test'
              end if
            end if
         end do
      end if

*     -- Computational test
      if (tstcmpt. and. Fsub(tst_sub, nsubs) ) then
         write(*, fmt = 7704 ) '------ Computational Test ------'
         write(ich_summ, fmt = 7704 ) '------ Computational Test ------'

*     -- Self Test: Test of DFT routine, Test of sample FFT

       if (self_test) then

*     -- DFT Forward-Inverse test
         ok_exp = .TRUE.
         write(*, fmt = * ) 'ZDFT    routine testing'
         call zChexp(ich_summ,ich_snap, deps, afatal, atrace,
     $               nm_dft, m_dft,
     $               za_tst, za_fexp, za_iexp, zws_exp, ok_exp )
         if (ok_exp) then
            write(*, fmt = * ) 'ZDFT:   PASSED'
         else
            write(*, fmt = * ) 'ZDFT:   ERROR'
            write(ich_summ, fmt = 7709)
     $      'Error: Error in Forward-Inverse complex*16 DFT-routine.',
     $          'Computational Testing Results May Be Wrong.'
         endif

         ok_exp = .TRUE.
         write(*, fmt = * ) 'CDFT    routine testing'
         call cChexp(ich_summ,ich_snap, seps, afatal, atrace,
     $               nm_dft, m_dft,
     $               ca_tst, ca_fexp, ca_iexp, cws_exp, ok_exp )

         if (ok_exp) then
            write(*, fmt = * ) 'CDFT:   PASSED'
         else
            write(*, fmt = * ) 'CDFT:   ERROR'
            write(ich_summ, fmt = 7709)
     $      'Error: Error in Forward-Inverse comlex DFT-routine. ',
     $          'Computational Testing Results May Be Wrong.'
         endif
         if (ok_exp) write(ich_summ, fmt = 7709) 'DFT :  PASSED'

         ok_exp = .TRUE.
         write(*, fmt = * ) 'ZFFT_SAMPLE routine testing'
          call zChfft_s(ich_summ,ich_snap, deps, afatal, atrace,
     $                 nm_dft, m_dft,
     $                 za_tst(za_tst_add), za_fexp(za_fexp_add),
     $                 za_iexp(za_iexp_add), zws_exp(zwsexp_add),
     $                 ok_exp )

*        call zChfft_s(ich_summ,ich_snap, deps, afatal, atrace,
*     $                 nm_dft, m_dft,
*     $                 za_tst, za_fexp, za_iexp, zws_exp, ok_exp )

         if (ok_exp) then
            write(*, fmt = * ) 'ZFFT_SAMPLE:   PASSED'
         else
            write(*, fmt = * ) 'ZFFT_SAMPLE:   ERROR'
            write(ich_summ, fmt = 7709)
     $      'Error: Error in ZFFT_SAMPLE routine.',
     $          'Computational Testing Results May Be Wrong.'
         endif

         ok_exp = .TRUE.
         write(*, fmt = * ) 'CFFT_SAMPLE routine testing'
         call cChfft_s(ich_summ,ich_snap, seps, afatal, atrace,
     $                 nm_dft, m_dft,
     $                 ca_tst(ca_tst_add), ca_fexp(ca_fexp_add),
     $                 ca_iexp(ca_iexp_add), cws_exp(cwsexp_add),
     $                 ok_exp )

*         call cChfft_s(ich_summ,ich_snap, seps, afatal, atrace,
*     $                 nm_dft, m_dft,
*     $                 ca_tst, ca_fexp, ca_iexp, cws_exp, ok_exp )

         if (ok_exp) then
            write(*, fmt = * ) 'CFFT_SAMPLE:   PASSED'
         else
            write(*, fmt = * ) 'CFFT_SAMPLE:   ERROR'
            write(ich_summ, fmt = 7709)
     $          'Error: Error in CFFT_SAMPLE routine.',
     $          'Computational Testing Results May Be Wrong.'
         endif
         if (ok_exp) write(ich_summ, fmt = 7710) 'FFT_SAMPLE: PASSED'

        endif

       do isub2 = 1, nsubs*2, 2
          isub = isub2
          if (isub2 .gt. nsubs) isub = isub + add_even - nsubs
          fatal( isub )   = .FALSE.
          tst_beg( isub ) = tst_sub( isub )
*          if ( tst_sub ( isub ) ) write ( ich_summ , fmt = 7702)
*     $                   snames( isub ), ' : Computational test '
       end do

*     -- Test on random matrices

*     -- Test in Compare with DFT result or sample result and
*     -- Forward-Inverse test
         do isub = 1, nsubs, 2
           if (tst_sub (isub)) then
             write(*, fmt = * ) snames(isub),' routine testing'
             call zChfft( ich_summ, ich_snap, snames,
     $                  deps, afatal, atrace,
     $                  nm, m, ztmp,
     $                  za_tst(za_tst_add), za_fexp(za_fexp_add),
     $                  za_iexp(za_iexp_add), zws_exp(zwsexp_add),
     $                  fatal, isub, tst_sub, dft_check, 
     $                  za_tst(za_tst_add), za_fexp(za_fexp_add))
 
			 if (fatal(isub)) then
               write(*, fmt = * ) snames(isub),': ERROR'
               if (afatal) then
                 write(ich_summ, fmt = 9985)
                 goto 200
               endif
             else
               write(*, fmt = * ) snames(isub),': PASSED'
             endif
           endif
         enddo
         do isub = 2, nsubs, 2
           if (tst_sub (isub)) then
             write(*, fmt = * ) snames(isub),' routine testing'
             call cChfft( ich_summ, ich_snap, snames, seps, afatal,
     $                    atrace, nm, m, ctmp, 
     $                    ca_tst(ca_tst_add), ca_fexp(ca_fexp_add),
     $                    ca_iexp(ca_iexp_add), cws_exp(cwsexp_add),
     $                    fatal, isub, tst_sub, dft_check,
     $                    ca_tst(ca_tst_add), ca_fexp(ca_fexp_add))

             if (fatal(isub)) then
               write(*, fmt = * ) snames(isub),': ERROR'
               if (afatal) then
                 write(ich_summ, fmt = 9985)
                 goto 200
               endif
             else
               write(*, fmt = * ) snames(isub),': PASSED'
             endif
           endif
         enddo
200      continue

         do isub2 = 1, nsubs*2, 2
            isub = isub2
            if (isub2 .gt. nsubs) isub = isub + add_even - nsubs
            if ( tst_beg( isub )) then
               if ( .not.fatal( isub ) ) then
                  write( ich_summ, fmt = 7708) snames( isub ),
     $                  '  : PASSED '
               else
                  write( ich_summ, fmt = 7708) snames( isub ),
     $                  '  : ERROR  '
               end if
            end if
         end do
      end if
 300  write(ich_summ, fmt = 7704) '----- End of Tests -----'
      write(*, fmt = 7704)        '----- End of Tests -----'
 330  continue
      CLOSE ( ich_summ )
      CLOSE ( ich_snap )

*      call MKLEnd()

      STOP

 9985 FORMAT( /' ******* FATAL ERROR - TESTS ABANDONED *******' )
 7701 FORMAT( t2, a / t2, a )
 7702 FORMAT( t6, a, a )
 7703 FORMAT( t6, a )
 7704 FORMAT( / t6, a /)
 7705 FORMAT( t2, a, a, a)
 7708 FORMAT( a, a )
 7709 FORMAT( a )
 7710 FORMAT( a /)

*     End of cfft.
      end


* ----------------------------------------------------------------
* --                   Input Job for testing                    --
* ----------------------------------------------------------------
      subroutine Init ( ich_in, snames, ok, fn_summ, ich_summ,
     $                  fn_snap, ich_snap, afatal, atrace, tstdft,
     $                  tsterr, tstcmpt, tst_sub, nm, m,
     $                  dft_check, self_test, deps, seps, aligning )

* ---     Job creation for 1D Fast Fouire Transform Testing
* ---     for subroutines of C/Z types.

*  -- Do:
*            Read information from standard input,
*            verifying this information,
*            job creation.
*            Variable ok = .TRUE. mean sucessful job creation.
*            Variable ok = .FALSE. mean that job is not created.

* --- Parameters
      integer           nsubs
      parameter       ( nsubs = 6 )
      integer           ndim
      parameter       ( ndim = 21 )
      integer          align_max
      parameter       (align_max = 64)

* --- Input Arguments
      integer           ich_in

*     -- Names of testing subroutines
      character(len=8)       snames( nsubs )

* --- Output Arguments
      logical           ok

*     -- Channels and files for output
      integer           ich_summ, ich_snap
      character(len=32)      fn_summ, fn_snap

      logical           atrace, afatal, tstdft,
     $                  tstcmpt, tsterr,
     $                  tst_sub( nsubs ),
     $                  dft_check, self_test

*     --- numbers of 1 dimension values for testing
      integer           nm
*     --- values on 1 dimension
      integer           m ( ndim )
      integer           aligning

* --- Local Variables
      logical           ok_iff
      integer           isub
      character(len=8)       name_sub
      logical           ltest
      real (KIND=8)            deps
      real              seps

* ---- Init start

      ok = .FALSE.
      tstdft = .FALSE.

*     -- Read name and channel for summary file.
      read( ich_in, fmt = * ) fn_summ
      write( *, fmt = * ) 'fn_summ = ', fn_summ

      read( ich_in, fmt = * ) ich_summ
      write( *,  fmt = * ) 'ich_summ = ', ich_summ

*     -- Read name and channel for snap file.
      read( ich_in, fmt = * ) fn_snap
      write( *, fmt = * ) 'fn_snap = ', fn_snap

      read( ich_in, fmt = * ) ich_snap
      write( *, fmt = * ) 'ich_snap = ', ich_snap

      atrace = ich_snap.ge.0

*     -- Read the flag for Self testing (test sample FFT)
      read( ich_in, fmt = * ) self_test
      write( *, fmt = * ) 'self_test = ', self_test

*     -- Read the flag for checking with DFT routine
      read( ich_in, fmt = * ) dft_check
      write( *, fmt = * ) 'dft_check = ', dft_check

*     -- Read the flag that directs stopping on any failure.
      read( ich_in, fmt = * ) afatal
      write( *, fmt = * ) 'afatal = ', afatal

*     -- What tests...

*     --Read the flag that indicates whether error exits are to be tested.
      read( ich_in, fmt = * ) tsterr
      write( *, fmt = * ) 'tsterr = ', tsterr

*     --Read the flag that indicates whether computational test is to be.
      read( ich_in, fmt = * ) tstcmpt
      write( *, fmt = * ) 'tstcmpt = ', tstcmpt

*     -- Read the epsilon value.
      read( ich_in, fmt = * ) deps
      write( *, fmt = * ) 'eps = ', deps
*     -- Read the epsilon value.
      read( ich_in, fmt = * ) seps
      write( *, fmt = * ) 'eps = ', seps

*     -- Read the align boundary.
      read( ich_in, fmt = * ) aligning
      if ((aligning .gt. align_max) .or. (aligning .lt. 8)) then
         write( *, *) ' Align value must be from 8 to ',
     $                 align_max
         GO TO 230
      endif
      if (((aligning/8)*8) .ne. aligning) then
         write( *, *) ' Align value must be divisible to 8 '
                GO TO 230
      endif
      write( *, fmt = * ) 'Align boundary = ', aligning, 'bytes'

*     -- Read numbers of values of dimensions, values
*     --    and verify it.
      call Iff( ich_in, ok_iff, nm, m )
      if (.not.ok_iff) GO TO 230

*     -- Read names of subroutines and flags which indicate
*     --   whether they are to be tested.
      do  isub = 1, nsubs
         tst_sub( isub ) = .FALSE.
      end do

   50 read( ich_in, fmt = 9900, END = 80 ) name_sub, ltest
      write( *, fmt = * ) name_sub, ltest
      do  isub = 1, nsubs
         if ( name_sub.EQ.snames( isub ) )
     $      GO TO 70
      end do

      write( *, fmt = 7701) ' Error in subroutine name ', name_sub
      GO TO 230

   70 tst_sub( isub ) = ltest
      GO TO 50

   80 continue

      ok = .TRUE.

  230 return

 7701 FORMAT( t2, a, a)
 9900 FORMAT( a8, l2 )
      end

* ------------------------------------------------------------------
* --- Read and verify values on dimensions                       ---
* ------------------------------------------------------------------
      subroutine  Iff(ich_in, ok, nm, m )

* --- Parameters
      integer           ndim, lmax
      parameter       ( ndim = 21, lmax = 1048576)

* --- Input arguments
      integer           ich_in

* --- Output Arguments
      logical           ok
      integer           nm, m(*)

* --- Local variables
      integer           i

* --- External Functions
      integer           log2
      external          log2

* --- Executable Statements

      ok = .FALSE.

*     -- Read number of values on 1 dimension
      read ( ich_in, fmt = * ) nm
      write( *, fmt = * ) 'number of values on 1 dimension = ', nm

*     -- Test number of values on 1 dimension
      if (nm.gt.ndim) then
         write(*, fmt = 7700) nm, ndim
         GO TO 100
      end if

*     -- Read values on 1 dimension
      read(ich_in, fmt = * ) ( m( i ), i = 1, nm )
      write( *, fmt = * )  'Values on 1 dimension = ',
     $                     ( m( i ), i = 1, nm )

*      -- Test value is less than maximum
      do i = 1, nm
         if ( m(i) .gt. 2*log2(lmax) ) then
            write(*, fmt = 7702) m(i), 2*log2(lmax)
            GO TO 100
         end if
         m (i) = 2**m(i)
      end do

      ok = .TRUE.

  100 return

 7700 FORMAT(  ' Number of values on 1 dimension = ',
     $          i4, '  > max = ', i2 )
 7702 FORMAT( ' Value of 1 dimension (Power of 2) = ',
     $          i6, '  > max = ', i4 )

      end


      subroutine  Headsumm(ich_summ, eps, seps, afatal, atrace,
     $            tstdft, tsterr, tstcmpt, tst_sub,
     $            snames, nm,  m, dft_check, self_test, aligning )
* ------------------------------------------------------------------
* --- Write summary file header                                   --
* ------------------------------------------------------------------

* --- Parameters
      integer           nsubs
      parameter       ( nsubs = 6 )

* --- Input Arguments
      real (KIND=8)            eps
      real              seps
      integer           nm, m(*)

*     -- Channels and files for output
      integer           ich_summ

      logical           atrace, afatal,
     $                  tstdft, tstcmpt, tsterr,
     $                  tst_sub(*),
     $                  dft_check, self_test

      integer           aligning

*     ---  Names of testing subroutines
      character(len=8)       snames( nsubs )

* --- Local Variables
      integer           i, isub

* --- Executiable statements...

      if (tstdft) i = 0
*     -- Summary file header
         write( ich_summ, fmt = 7707 )
     $         '-- Testing of 1D Fast Fourier Transform routines --',
     $         '--   by result comparision with results from    --',
     $         '--  1D Discrete Fourier Transform routine (DFT).--',
     $         '--      Routines for double complex data.       --',
     $         '--      Routines for fsingle complex data.       --'

*      write( ich_summ, fmt = 7709 ) aligning
      write( ich_summ, fmt = 7701 ) eps
      write( ich_summ, fmt = 7708 ) seps
      write( ich_summ, fmt = * ) 'Self test: ', self_test
      write( ich_summ, fmt = * ) 'Compare results with DFT routine: '
     $                            ,dft_check
c      write( ich_summ, fmt = * ) 'Tests DFT Routine: ', tstdft
      write( ich_summ, fmt = 7702 ) 'Tests on: ', 'Error exits',
     $       'Computational tests'
      write( ich_summ, fmt = 7703 ) tsterr, tstcmpt
      if (afatal) write( ich_summ, fmt = 7704)
     $        'Routine Testing has been break at any failures'
      if (atrace) write( ich_summ, fmt = 7704)
     $         'Snapshot file has been create'

      write( ich_summ, fmt = 7705) 'Routine number ',
     $           ' Routine name ', 'Test mark'
      do isub = 1, nsubs
         write( ich_summ, fmt = 7706)
     $                             isub, snames(isub), tst_sub(isub)
      end do

      write(ich_summ, fmt = 7704)
     $ 'Values on 1 dimension'
      write(ich_summ, fmt = *) (m( i ), i = 1, nm )

      return

 7701 FORMAT( t6, 'Double presision Eps = ', 1P, E9.1 )
 7702 FORMAT( t6,a, t16,a , t29,a )
 7703 FORMAT(       t16,l1, t29,l1 )
 7704 FORMAT( t2,a )
 7705 FORMAT( t6,a, t26, a, t46,a )
 7706 FORMAT( t10, i2, t29, a8, t50, l1 )
 7707 FORMAT( t6,a / t6,a / t6, a / t6, a / t6, a)
 7708 FORMAT( t6, 'Single presision Eps = ', 1P, E9.1 )
 7709 FORMAT( t6, 'Align arrays on',i4,' byte boundary' )

      end


         subroutine Chffterr( ich_summ, isub, sname, a_z, a_c, a_d, a_s,
     $                     ws_z, ws_c, ok_err )
      integer           ich_summ, isub
      character(len=8)       sname
      complex (KIND=8)        a_z(*), ws_z(*)
      complex*8         a_c(*), ws_c(*)
      real (KIND=8)            a_d(*)
      real*4            a_s(*)
      logical           ok_err

      integer           code_err, ich_out, m, isign
      logical           lerr, ok
      character(len=8)       sub_err
      common            /exiterr/ code_err, ich_out, lerr, ok
      common            /exitname/ sub_err

      ok = .TRUE.
      ok_err = ok
      lerr = .FALSE.
      sub_err = sname
      ich_out = ich_summ

      code_err = 2
      m = -20
      isign = 0
      call call_func( isub, a_z, a_c, a_d, a_s, ws_z, ws_c, m, isign )
      call Cherr ( ich_summ, sname, code_err, lerr, ok)

      code_err = 2
      m = 250
      isign = 0
      call call_func( isub, a_z, a_c, a_d, a_s, ws_z, ws_c, m, isign )
      call Cherr ( ich_summ, sname, code_err, lerr, ok)

      code_err = 3
      m = 64
      isign = -5
      call call_func( isub, a_z, a_c, a_d, a_s, ws_z, ws_c, m, isign )
      call Cherr ( ich_summ, sname, code_err, lerr, ok)

      code_err = 4
      m = 32
      isign = -1
      call call_func( isub, a_z, a_c, a_d, a_s, ws_z, ws_c, m, isign )
      call Cherr ( ich_summ, sname, code_err, lerr, ok)

      code_err = 4
      m = 64
      isign = 0
      call call_func( isub, a_z, a_c, a_d, a_s, ws_z, ws_c, m, isign )

      m = 512
      isign = -1
      call call_func( isub, a_z, a_c, a_d, a_s, ws_z, ws_c, m, isign )
      call Cherr ( ich_summ, sname, code_err, lerr, ok)

      code_err = 4
      m = 1024
      isign = -1
      call call_func( isub, a_z, a_c, a_d, a_s, ws_z, ws_c, m, isign )
      call Cherr ( ich_summ, sname, code_err, lerr, ok)

      if (.NOT.ok) ok_err = .FALSE. 
      return
      end


      subroutine  Cherr (ich_summ, sub_name, code_err, lerr, ok)
* ----------------------------------------------------------------------
* --  Verifying error-exits - work of xerbla                          --
* ----------------------------------------------------------------------
      integer            ich_summ, code_err
      character(len=8)        sub_name
      logical            lerr, ok

      if ( .NOT.lerr ) then
         write( ich_summ, fmt = 7700) code_err, sub_name
         ok = .FALSE.
      end if
      lerr = .FALSE.

      return

 7700 format( t6, '**** error number ', i2, ' not detected by ', a7,
     $       ' ****' )

      end

      subroutine zChexp( ich_summ, ich_snap, eps, afatal, atrace,
     $                   nm, m, a_tst, a_fexp, a_iexp, ws_exp, ok)
* ---------------------------------------------------------------------
* -- Testing DFT on random vectores - Forward-Inverse transform,         --
* ---------------------------------------------------------------------
* --- Parameters
      integer           lmax
      parameter       ( lmax = 2048 )

* --- Input Arguments
      integer           ich_summ, ich_snap
      real (KIND=8)            eps
      logical           afatal, atrace

      integer           nm, m(*)
      complex (KIND=8)        a_tst( * )
      complex (KIND=8)        a_fexp( * )
      complex (KIND=8)        a_iexp( * )
      complex (KIND=8)        ws_exp( lmax*2 )

* --- Output Arguments
      logical           ok

* ---  Local Variables
      integer           im
      logical           fatal

* --- External subroutines
      external          zexpFItest

* --- Executable Statements
      ok = .TRUE.
      do im = 1, nm
         if (m(im) .le. lmax) then
*        -- Forward-Inverse test
            call  zexpFItest ( ich_summ, ich_snap, eps, atrace,
     $                         m(im), a_tst, a_fexp, a_iexp,
     $                         ws_exp, fatal )
            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300
         else
            write(*,fmt = *)' ZDFT: Vector ',m(im),
     $                    'is too large, SKIPPED'
         endif
      end do
 300  return
      end

      subroutine cChexp( ich_summ, ich_snap, eps, afatal, atrace,
     $                   nm, m, a_tst, a_fexp, a_iexp, ws_exp, ok)
* ---------------------------------------------------------------------
* -- Testing DFT on random vectores - Forward-Inverse transform,         --
* ---------------------------------------------------------------------
* --- Parameters
      integer           lmax
      parameter       ( lmax = 2048 )

* --- Input Arguments
      integer           ich_summ, ich_snap
      real              eps
      logical           afatal, atrace

      integer           nm, m(*)
      complex           a_tst( * )
      complex           a_fexp( * )
      complex           a_iexp( * )
      complex           ws_exp( * )

* --- Output Arguments
      logical           ok

* ---  Local Variables
      integer           im
      logical           fatal

* --- External subroutines
      external          cexpFItest

* --- Executable Statements
      ok = .TRUE.
      do im = 1, nm
         if (m(im) .le. lmax) then

*        -- Forward-Inverse test
            call  cexpFItest ( ich_summ, ich_snap, eps, atrace,
     $                  m(im), a_tst, a_fexp, a_iexp, ws_exp, fatal )
            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300
         else
            write(*,fmt = *)' CDFT: Vector ',m(im), 
     $                    'is too large, SKIPPED'
         endif

      end do
 300  return
      end

      subroutine zChfft_s( ich_summ, ich_snap, eps, afatal, atrace,
     $                     nm, ma, a_tst, a_fexp, a_iexp, ws_exp, ok)
*     ---------------------------------------------------------------------
*     -- Testing sample FFT on random vectores                           --
*     ---------------------------------------------------------------------
*     --- Parameters
      integer           lmax
      real (KIND=8)            zero, one
      parameter       ( lmax = 2048 )
      parameter       ( zero = 0.d0, one = 1.d0 )

*     --- Input Arguments
      integer           ich_summ, ich_snap
      real (KIND=8)            eps
      logical           afatal, atrace

      integer           nm, ma(*)
      complex (KIND=8)        a_tst( * )
      complex (KIND=8)        a_fexp( * )
      complex (KIND=8)        a_iexp( * )
      complex (KIND=8)        ws_exp( * )

* --- Output Arguments
      logical           ok

* ---  Local Variables
      integer           im, isign, m
      logical           fatal

* --- Executable Statements

      ok = .TRUE.
      do im = 1, nm
         if (ma(im) .le. lmax) then
           m = ma(im)

           isign = -1
           call zCmpretest_s( ich_summ, ich_snap, eps, afatal, atrace,
     $                        m, isign, a_tst, a_fexp, a_iexp, ws_exp, 
     $                        fatal)
            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300

           isign = 1
           call zCmpretest_s( ich_summ, ich_snap, eps, afatal, atrace,
     $                        m, isign, a_tst, a_fexp, a_iexp, ws_exp, 
     $                        fatal)
            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300

*           -- Forward-Inverse test 
            call  zsampleFItest_1 ( ich_summ, ich_snap, eps, afatal, 
     $                              atrace, m,  
     $                              a_tst, a_fexp, ws_exp, fatal)
            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300

*           -- Forward-Inverse test with out bitrevers
            call  zsampleFItest_2 ( ich_summ, ich_snap, eps, afatal, 
     $                              atrace, m,  
     $                              a_tst, a_fexp, ws_exp, fatal)
            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300
         else
            write(*,fmt = *)' CDFT: Vector ',ma(im), 
     $                    'is too large, SKIPPED'
         endif
      end do
 300  return
      end


      subroutine cChfft_s( ich_summ, ich_snap, eps, afatal, atrace,
     $                     nm, ma, a_tst, a_fexp, a_iexp, ws_exp, ok)
*     ---------------------------------------------------------------------
*     -- Testing sample FFT on random vectores                           --
*     ---------------------------------------------------------------------
*     --- Parameters
      integer           lmax
      real*4            zero, one
      parameter       ( lmax = 2048 )
      parameter       ( zero = 0.d0, one = 1.d0 )

*     --- Input Arguments
      integer           ich_summ, ich_snap
      real*4            eps
      logical           afatal, atrace

      integer           nm, ma(*)
      complex*8         a_tst( * )
      complex*8         a_fexp( * )
      complex*8         a_iexp( * )
      complex*8         ws_exp( * )

* --- Output Arguments
      logical           ok

* ---  Local Variables
      integer           im, isign, m
      logical           fatal

* --- Executable Statements

      ok = .TRUE.
      do im = 1, nm
         if (ma(im) .le. lmax) then
           m = ma(im)

           isign = -1
           call cCmpretest_s( ich_summ, ich_snap, eps, afatal, atrace,
     $                        m, isign, a_tst, a_fexp, a_iexp, ws_exp, 
     $                        fatal)
            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300

           isign = 1
           call cCmpretest_s( ich_summ, ich_snap, eps, afatal, atrace,
     $                        m, isign, a_tst, a_fexp, a_iexp, ws_exp, 
     $                        fatal)
            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300

*           -- Forward-Inverse test 
            call  csampleFItest_1 ( ich_summ, ich_snap, eps, afatal, 
     $                              atrace, m,  
     $                              a_tst, a_fexp, ws_exp, fatal)
            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300

*           -- Forward-Inverse test with out bitrevers
            call  csampleFItest_2 ( ich_summ, ich_snap, eps, afatal, 
     $                              atrace, m,  
     $                              a_tst, a_fexp, ws_exp, fatal)
            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300
         else
            write(*,fmt = *)' CDFT: Vector ',ma(im), 
     $                    'is too large, SKIPPED'
         endif
      end do
 300  return
      end


      subroutine zChfft( ich_summ, ich_snap, snames, eps, afatal,
     $                   atrace, nm, m, a_tmp, a_tst, a_fexp, a_iexp,
     $                   ws_exp, fatal, isub, tst_sub, dft_check,
     $                   a_tst_r, a_fexp_r)
* ---------------------------------------------------------------------
* -- Testing on random vectores - Forward-Inverse transform,         --
* -- Forward, Inverse transform in compare with DFT result           --
* ---------------------------------------------------------------------
* --- Parameters
      integer           nsubs
      parameter       ( nsubs = 6 )
      integer           lmax
      parameter       ( lmax = 1048576 )

* --- Input Arguments
      integer           ich_summ, ich_snap, isub, nm, m(*)
      real (KIND=8)            eps
      logical           afatal, atrace, dft_check
      complex (KIND=8)        a_tmp( lmax ), a_tst( lmax )
      complex (KIND=8)        a_fexp( lmax ), a_iexp( lmax )
      complex (KIND=8)        ws_exp( lmax*2 )
      real (KIND=8)            a_tst_r( lmax+2 ), a_fexp_r( lmax+2 )
      character(len=8)       snames(*)

      logical           tst_sub(*)

* --- Output Arguments
      logical           fatal(*)

* ---  Local Variables
      logical           sub_fatal( nsubs )
      integer           im, isign
      real (KIND=8)            gauge

* --- External subroutines
      external            zCmpretest

* --- Executable Statements

      do im = 1, nm
         if (m(im) .le. lmax) then
            if (isub.EQ.1) then
*          -- Forward test
              isign = -1
              call zCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m(im), 
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

*          -- Inverse test
              isign = 1
              call zCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m(im),  
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)
              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

*          -- Forward-Inverse test
              call  zFItest_1 ( ich_summ, ich_snap, eps, atrace,
     $                          afatal, snames, m(im), ws_exp,  
     $                          a_tst, a_fexp,
     $                          gauge, sub_fatal, isub )

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300
	        
              if (.NOT.dft_check) then
*                 -- Forward test with out Bitreverse
                  isign = -2
                  call zCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                              snames, isign, m(im), 
     $                              a_tst, a_fexp, a_iexp, ws_exp,
     $                              gauge, sub_fatal, afatal, isub,
     $                              dft_check)
                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300

*              -- Inverse test with out Bitreverse
                  isign = 2
                  call zCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                              snames, isign, m(im), 
     $                              a_tst, a_fexp, a_iexp, ws_exp,
     $                              gauge, sub_fatal, afatal, isub,
     $                              dft_check)

                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300

*              -- Forward-Inverse test with out Bitreverse
                  call  zFItest_2 ( ich_summ, ich_snap, eps, atrace,
     $                              afatal, snames, m(im), ws_exp,  
     $                              a_tst, a_fexp,
     $                              gauge, sub_fatal, isub )

                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300
	        endif
            endif

            if (isub.EQ.3 .OR. isub.EQ.5) then
              call zrCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m(im), a_tmp, 
     $                  a_tst_r, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)
              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300
            endif

            if ((isub.EQ.3 .AND. tst_sub(5))) then
*          -- Forward-Inverse test
              call  zrFItest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m(im), a_tmp,
     $                  a_tst_r, a_fexp_r,
     $                  gauge, sub_fatal, isub )

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300
            endif

         else
            write(*,fmt = *)' Vector ',m(im), 
     $                    'is too large, SKIPPED'
         endif
      end do
 300  return
      end


      subroutine cChfft( ich_summ, ich_snap, snames, eps, afatal,
     $                   atrace, nm, m, a_tmp,
     $                   a_tst, a_fexp, a_iexp, ws_exp,
     $                   fatal, isub, tst_sub, dft_check,
     $                   a_tst_r, a_fexp_r)
* ---------------------------------------------------------------------
* -- Testing on random vectores - Forward-Inverse transform,         --
* -- Forward, Inverse transform in compare with DFT result           --
* ---------------------------------------------------------------------
* --- Parameters
      integer           nsubs, lmax
      parameter       ( nsubs = 6, lmax = 1048576 )

* --- Input Arguments
      integer           ich_summ, ich_snap, isub, nm, m(*)
      real              eps
      logical           afatal, atrace, dft_check
      complex           a_tmp( * ), a_tst( * )
      complex           a_fexp( * ), a_iexp( * )
      complex           ws_exp( lmax*2 )
      real              a_tst_r( * ), a_fexp_r( * )
      character(len=8)       snames(*)
      logical           tst_sub(*)

* --- Output Arguments
      logical           fatal(*)

* --- Local Variables
      logical           sub_fatal( nsubs )
      integer           im, isign
      real (KIND=8)            gauge

* --- External subroutines
      external            cCmpretest

* --- Executable Statements

      do im = 1, nm
        if (m(im) .le. lmax) then

           if (isub.EQ.2) then

*          -- Forward test

              isign = -1
              call cCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m(im), 
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

*          -- Inverse test

              isign = 1
              call cCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                          snames, isign, m(im), 
     $                          a_tst, a_fexp, a_iexp, ws_exp,
     $                          gauge, sub_fatal, afatal, isub,
     $                          dft_check)

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300


*          -- Forward-Inverse test

              call  cFItest_1 ( ich_summ, ich_snap, eps, atrace,
     $                          afatal, snames, m(im), ws_exp,  
     $                          a_tst, a_fexp,
     $                          gauge, sub_fatal, isub )

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

	        if (.NOT.dft_check) then
*                 -- Forward test with out Bitreverse
                  isign = -2
                  call cCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                              snames, isign, m(im), 
     $                              a_tst, a_fexp, a_iexp, ws_exp,
     $                              gauge, sub_fatal, afatal, isub,
     $                              dft_check)
                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300

*              -- Inverse test with out Bitreverse
                  isign = 2
                  call cCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                              snames, isign, m(im), 
     $                              a_tst, a_fexp, a_iexp, ws_exp,
     $                              gauge, sub_fatal, afatal, isub,
     $                              dft_check)

                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300

*              -- Forward-Inverse test with out Bitreverse
                  call  cFItest_2 ( ich_summ, ich_snap, eps, atrace,
     $                              afatal, snames, m(im), ws_exp,  
     $                              a_tst, a_fexp,
     $                              gauge, sub_fatal, isub )

                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300
	        endif
           endif

            if (isub.EQ.4 .OR. isub.EQ.6) then
              call crCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m(im),  a_tmp,
     $                  a_tst_r, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check )
              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

            endif

            if ((isub.EQ.4 .AND. tst_sub(6))) then
*             --- Forward-Inverse test
              call  crFItest ( ich_summ, ich_snap, eps, atrace,
     $                         snames, m(im),  a_tmp,
     $                         a_tst_r, a_fexp_r,
     $                         gauge, sub_fatal, isub )
              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300
            endif

         else
            write(*,fmt = *)' Vector ',m(im), 
     $                    'is too large, SKIPPED'
         endif
      end do
 300  return
      end


      subroutine zCmpretest_s( ich_summ, ich_snap, eps, afatal, atrace,
     $                         m, isign, a_tst, a_fexp, a_iexp, ws_exp,
     $                         fatal)
* ---------------------------------------------------------------------
* -- Testing sample FFT on random vectores                           --
* ---------------------------------------------------------------------
* --- Parameters
      real (KIND=8)            zero, one
      parameter       ( zero = 0.d0, one = 1.d0 )

* --- Input Arguments
      integer           ich_summ, ich_snap
      real (KIND=8)            eps
      logical           afatal, atrace

      integer           m, isign
      complex (KIND=8)        a_tst( * )
      complex (KIND=8)        a_fexp( * )
      complex (KIND=8)        a_iexp( * )
      complex (KIND=8)        ws_exp( * )

* --- Output Arguments
      logical           fatal

* ---  Local Variables
      real (KIND=8)            gauge, gauges, gausub
      logical           gauge_fatal

* --- Executable Statements

*          -- Initialize vector for testing
           call zRandm(a_tst, m)
           call zmCopy(a_tst, a_fexp, m)
           call zcomp_gauge (a_tst, m, isign, gauges)
           call zfft1d_s( a_tst, m, 0, ws_exp)
           call zfft1d_s( a_tst, m, isign, ws_exp)
           call zexp1d(a_fexp, m, isign, ws_exp, a_iexp, gauge)

           if (isign.eq.-1) then
             isign = 1
           else
             isign = -1
           endif

           call zcomp_gauge (a_tst, m, isign, gauge)

           if (isign.eq.-1) then
             isign = 1
           else
             isign = -1
           endif

           fatal  = .FALSE.
           gauge_fatal  = .FALSE.
           gausub = (dabs(gauges-gauge) ) / eps
           if ( gauges .ne. zero ) gausub = gausub/gauges
           if (gausub .ge. one) then
             if (isign.eq.-1) then
                write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                  ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                    gauge,gauges
             else
                write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                  ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                    gauge,gauges
             endif
             write(ich_summ, fmt = 7700) 'zfft1d_s', ' : ERROR'
             gauge_fatal = .TRUE.
             if (afatal) goto 90
           endif
           call zEst( ich_summ, ich_snap, eps, atrace, m, 
     $                a_tst, a_iexp, gauges, fatal,
     $                'zfft1d_s', isign )
  90  continue
      fatal = fatal .or. gauge_fatal
	return

 7700 FORMAT( t2, a9, a / )
      end

      subroutine cCmpretest_s( ich_summ, ich_snap, eps, afatal, atrace,
     $                         m, isign, a_tst, a_fexp, a_iexp, ws_exp,
     $                         fatal)
* ---------------------------------------------------------------------
* -- Testing sample FFT on random vectores                           --
* ---------------------------------------------------------------------
* --- Parameters
      real (KIND=8)            zero, one
      parameter       ( zero = 0.e0, one = 1.e0)

* --- Input Arguments
      integer          ich_summ, ich_snap
      integer          isign
      real*4           eps
      logical          afatal, atrace

      integer          m
      complex          a_tst( * )
      complex          a_fexp( * )
      complex          a_iexp( * )
      complex          ws_exp( * )

* --- Output Arguments
      logical          fatal

* ---  Local Variables
      real (KIND=8)           gauge, gauges, gausub
      logical          gauge_fatal

* --- Executable Statements

      isign = -1
*          -- Initialize vector for testing
           call cRandm(a_tst, m)
           call cmCopy(a_tst, a_fexp, m)
           call ccomp_gauge (a_tst, m, isign, gauges)
           call cfft1d_s( a_tst, m, 0, ws_exp)
           call cfft1d_s( a_tst, m, isign, ws_exp)
           call cexp1d(a_fexp, m, isign, ws_exp, a_iexp, gauge)

           if (isign.eq.-1) then
             isign = 1
           else
             isign = -1
           endif

           call ccomp_gauge (a_tst, m, isign, gauge)

           if (isign.eq.-1) then
             isign = 1
           else
             isign = -1
           endif

           fatal  = .FALSE.
           gauge_fatal  = .FALSE.

           gausub = (abs(gauges-gauge) ) / eps
           if ( gauges .ne. zero ) gausub = gausub/gauges
           if (gausub .ge. one) then
             if (isign.eq.-1) then
                write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                  ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                  gauge,gauges
             else
                write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                  ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                  gauge,gauges
             endif
             write(ich_summ, fmt = 7700) 'cfft1d_s', ' : ERROR'
             gauge_fatal = .TRUE.
             if (afatal) goto 90
           endif

           call cEst( ich_summ, ich_snap, eps, atrace, m, a_tst,
     $                a_iexp, gauges, fatal, 'cfft1d_s', isign )
  90  continue
      fatal = fatal .or. gauge_fatal
	return

 7700 FORMAT( t2, a9, a / )
      end

      subroutine  zCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m, 
     $                  a_tst, a_exp_in, a_exp_out, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)
* ----------------------------------------------------------------------
* -- Testing in compare with DFT (complex (KIND=8))                         --
* ----------------------------------------------------------------------
* --- Parameters
      real (KIND=8)    zero, one
      parameter       ( zero = 0.d0, one = 1.d0 )
      real (KIND=8)    Z_gauge_deg
      parameter       ( Z_gauge_deg = 1.d1)
      integer           lmax
      parameter       ( lmax = 1048576 )

* --- Input Arguments
      integer           ich_summ, ich_snap, isign, isub, m 
      integer           isign_gauge
      real (KIND=8)     eps
      logical           atrace, afatal, dft_check
      complex (KIND=8)  a_tst( * ), a_exp_in( * )
      complex (KIND=8)  a_exp_out( * ), ws_exp( * )
      character(len=8)  snames(*)

* --- Output Arguments
      logical           sub_fatal(*)
      real (KIND=8)     gauge

* --- Local Variables
      logical           gauge_fatal
      real (KIND=8)     gausub
      real (KIND=8)     gauges
      integer           post_m, lpost_m, wm 
      parameter         (lpost_m = 512)
      complex (KIND=8)  ws_post( lpost_m )


* --- External subroutines
      external          zexp1d, zfft1d, zmCopy

* --- Executable Statements


*     -- Initialize vector for testing
      post_m = lpost_m
	if (post_m > lmax-m) then
	    post_m = lmax-m
	end if

	wm = 3 * m / 2
		 
      call zRandm(a_tst, m)
      call zmCopy(a_tst, a_exp_in, m)

      if (dft_check) then
        call zexp1d(a_exp_in, m, isign, ws_exp, a_exp_out, gauge)
      else
        call zfft1d_s(a_exp_in, m, 0, ws_exp)
        call zfft1d_s(a_exp_in, m, isign, ws_exp)
        call zmCopy(a_exp_in, a_exp_out, m)
      endif

      sub_fatal( isub ) = .FALSE.
      gauge_fatal = .FALSE.

      if (isign.le.-1) then
         isign_gauge = -1
      else
         isign_gauge = 1
      endif

      call zRandm(a_tst(m+1), post_m)
      call zmCopy(a_tst(m+1), a_exp_in(m+1), post_m)
      call zRandm(ws_exp(wm+1), post_m)
      call zmCopy(ws_exp(wm+1), ws_post, post_m)

      call zfft1d( a_tst, m, 0, ws_exp)
      call zcomp_gauge (a_tst, m, isign_gauge, gauges)
      call zfft1d( a_tst, m, isign, ws_exp)

      if (isign.le.-1) then
         isign_gauge = 1
      else
         isign_gauge = -1
      endif

      call zcomp_gauge (a_tst, m, isign_gauge, gauge)

      gausub = (dabs(gauges-gauge) ) / (eps * Z_gauge_deg)

      if ( gauges .ne. zero ) gausub = gausub/gauges
      if (gausub .ge. one) then
          if (isign.eq.-1) then
              write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                     ' transform gauge is',
     $                     ' not egual input vector gauge',
     $                       gauge,gauges
          else
          if (isign.eq.1) then
              write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                     ' transform gauge is',
     $                     ' not egual input vector gauge',
     $                       gauge,gauges
          else
          if (isign.eq.-2) then
              write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                     ' with out Bitreverse ',
     $                     ' transform gauge is',
     $                     ' not egual input vector gauge',
     $                       gauge,gauges
          else
              write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                     ' with out Bitreverse ',
     $                     ' transform gauge is',
     $                     ' not egual input vector gauge',
     $                       gauge,gauges
          endif
          endif
          endif
          write(ich_summ, fmt = 7700)
     $                  snames( isub ), ' : ERROR'
          sub_fatal( isub ) = .TRUE.
          gauge_fatal = .TRUE.
          if (afatal) goto 90
      endif

      call zEst( ich_summ, ich_snap, eps, atrace, m,
     $                 a_tst, a_exp_out, gauges, sub_fatal( isub ),
     $                 snames(isub), isign )

  90  continue
      if (gauge_fatal) sub_fatal(isub) = .TRUE.

	call zpostm(a_tst, a_exp_in, ws_exp, ws_post, m, post_m,
     $	 sub_fatal( isub ), ich_summ, isign)

      return
 7700 FORMAT( t2, a8, a / )
      end

      subroutine  cCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m, 
     $                  a_tst, a_exp_in, a_exp_out, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)
* ----------------------------------------------------------------------
* -- Testing in compare with DFT (complex (KIND=8))                         --
* ----------------------------------------------------------------------
* --- Parameters
      real             zero, one
      parameter        (zero = 0.e0, one = 1.e0 )
      integer           lmax
      parameter       ( lmax = 1048576 )

* --- Input Arguments
      integer          ich_summ, ich_snap, isign, isub, m
      integer          isign_gauge
      real             eps
      logical          atrace, afatal, dft_check
      complex          a_tst( * ), a_exp_in( * )
      complex          a_exp_out( * ), ws_exp( * )
      character(len=8)      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real (KIND=8)           gauge,gauges
      real             eps_d

* --- Local Variables
      logical          gauge_fatal
      real (KIND=8)           gausub
      integer           post_m, lpost_m, wm, iw 
      parameter         (lpost_m = 512)
      complex (KIND=4)  ws_post( lpost_m )

* --- External subroutines
      external         cexp1d, cfft1d, cmCopy

* --- Executable Statements

*     -- Initialize vector for testing
      post_m = lpost_m
	if (post_m > lmax-m) then
	    post_m = lmax-m
	end if

	wm = 3 * m / 2
		 
      call cRandm(a_tst, m)
      call cmCopy(a_tst, a_exp_in, m)

      if (dft_check) then
        call cexp1d(a_exp_in, m, isign, ws_exp, a_exp_out, gauge)
      else
        call cfft1d_s(a_exp_in, m, 0, ws_exp)
        call cfft1d_s(a_exp_in, m, isign, ws_exp)
        call cmCopy(a_exp_in, a_exp_out, m)
        eps_d = eps
      endif

      sub_fatal( isub ) = .FALSE.
      gauge_fatal = .FALSE.

      if (isign.le.-1) then
          isign_gauge = -1
      else
          isign_gauge = 1
      endif

      call cRandm(a_tst(m+1), post_m)
      call cmCopy(a_tst(m+1), a_exp_in(m+1), post_m)
      call cRandm(ws_exp(wm+1), post_m)
      call cmCopy(ws_exp(wm+1), ws_post, post_m)

      call cfft1d( a_tst, m, 0, ws_exp)
      call ccomp_gauge (a_tst, m, isign_gauge, gauges)
      call cfft1d( a_tst, m, isign, ws_exp)

      if (isign.le.-1) then
          isign_gauge = 1
      else
          isign_gauge = -1
      endif

      call ccomp_gauge (a_tst, m, isign_gauge, gauge)

      gausub = (abs(gauges-gauge) ) / eps
      if ( gauges .ne. zero ) gausub = gausub/gauges
      if (gausub .ge. one) then
         if (isign.eq.-1) then
            write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                     ' transform gauge is',
     $                     ' not egual input vector gauge',
     $                       gauge,gauges
         else
          if (isign.eq.1) then
              write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                     ' transform gauge is',
     $                     ' not egual input vector gauge',
     $                       gauge,gauges
          else
          if (isign.eq.-2) then
              write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                     ' with out Bitreverse ',
     $                     ' transform gauge is',
     $                     ' not egual input vector gauge',
     $                       gauge,gauges
          else
              write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                     ' with out Bitreverse ',
     $                     ' transform gauge is',
     $                     ' not egual input vector gauge',
     $                       gauge,gauges
          endif
          endif
         endif
            write(ich_summ, fmt = 7700)
     $                  snames( isub ), ' : ERROR'
            sub_fatal( isub ) = .TRUE.
            gauge_fatal = .TRUE.
            if (afatal) goto 90
            endif
             call cEst( ich_summ, ich_snap, eps, atrace, m,
     $           a_tst, a_exp_out, gauges, sub_fatal( isub ),
     $           snames(isub), isign )
      if (afatal) GO TO 90
  90  continue
      if (gauge_fatal) sub_fatal(isub) = .TRUE.

	call cpostm(a_tst, a_exp_in, ws_exp, ws_post, m, post_m,
     $	 sub_fatal( isub ), ich_summ, isign)

      return
 7700 FORMAT( t2, a7, a / )
      end


        subroutine  zexpFItest ( ich_summ, ich_snap, eps, atrace, m,
     $                      a_tst, a_fexp, a_iexp, ws_exp, fatal )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex (KIND=8))        --
* -----------------------------------------------------------
* --- Input Arguments
      integer           ich_summ, ich_snap, m
      real (KIND=8)            eps
      logical           atrace
      complex (KIND=8)        a_tst(*)
      complex (KIND=8)        a_fexp(*), a_iexp(*), ws_exp(*)

* --- Output Arguments
      logical           fatal

* --- Local Variables
      integer           isign
      real (KIND=8)            gauge, gauges
* --- External subroutines
      external          zexp1d, zmCopy, zcomp_gauge, zEst

* --- Executable Statements

      fatal = .FALSE.
      call zRandm(a_tst, m)
      call zmCopy(a_tst, a_fexp, m)
      isign = -1
      call zcomp_gauge (a_fexp, m, isign, gauges)
      call zexp1d(a_fexp, m, isign, ws_exp, a_iexp, gauge)
      isign = 1
      call zexp1d(a_iexp, m, isign, ws_exp, a_tst, gauge)
      call zEst( ich_summ, ich_snap, eps, atrace, m, a_tst, a_fexp,
     $           gauges, fatal, 'ZDFT    ', 0 )
  100 continue
      return

 7700 FORMAT( t2, a / )
      end

      subroutine  cexpFItest ( ich_summ, ich_snap, eps, atrace, m,
     $                      a_tst, a_fexp, a_iexp, ws_exp, fatal )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex (KIND=8))        --
* -----------------------------------------------------------
* --- Input Arguments
      integer          ich_summ, ich_snap, m
      real             eps
      logical          atrace
      complex*8        a_tst(*), a_fexp(*), a_iexp(*), ws_exp(*)

* --- Output Arguments
      logical          fatal

* --- Local Variables
      integer          isign
      real (KIND=8)           gauge, gauges
* --- External subroutines
      external         cexp1d, ccomp_gauge, cEst

* --- Executable Statements

      fatal = .FALSE.
      call cRandm(a_tst, m)
      call cmCopy(a_tst, a_fexp, m)
      isign = -1
      call ccomp_gauge (a_fexp, m, isign, gauges)
      call cexp1d(a_fexp, m, isign, ws_exp, a_iexp, gauge)
      isign = 1
      call cexp1d(a_iexp, m, isign, ws_exp, a_tst, gauge)
      call cEst( ich_summ, ich_snap, eps, atrace, m,
     $           a_tst, a_fexp, gauges, fatal,'CDFT    ', 0 )
  100 continue
      return

 7700 FORMAT( t2, a / )
      end

      subroutine zsampleFItest_1( ich_summ, ich_snap, eps, afatal,
     $	                        atrace, m, a_tst, a_fexp, ws_exp, 
     $                            fatal )
* ---------------------------------------------------------------
* -- Testing Forward-Inverse transform (complex (KIND=8)) for sample --
* ---------------------------------------------------------------
* --- Parameters
      real (KIND=8)            zero, one
      parameter       ( zero = 0.e0, one = 1.e0)

* --- Input Arguments
      integer          ich_summ, ich_snap
      real (KIND=8)           eps
      logical          afatal, atrace

      integer          m
      integer          isign
      complex (KIND=8)       a_tst( * )
      complex (KIND=8)       a_fexp( * )
      complex (KIND=8)       ws_exp( * )

* --- Output Arguments
      logical          fatal

* ---  Local Variables
      real (KIND=8)           gauge, gauges, gausub
      logical          gauge_fatal

* --- Executable Statements

*     -- Initialize vector for testing
      call zRandm(a_tst, m)
      call zmCopy(a_tst, a_fexp, m)

      call zfft1d_s( a_tst, m, 0, ws_exp)
      isign = -1
      call zcomp_gauge (a_tst, m, isign, gauges)
      call zfft1d_s( a_tst, m, isign, ws_exp)
      isign = 1
      call zfft1d_s( a_tst, m, isign, ws_exp)

      isign = -1
      call zcomp_gauge (a_tst, m, isign, gauge)

      fatal  = .FALSE.
      gauge_fatal  = .FALSE.

      gausub = (dabs(gauges-gauge) ) / eps
      if ( gauges .ne. zero ) gausub = gausub/gauges
      if (gausub .ge. one) then
          write(ich_summ, fmt = *)' ** FATAL: Forward-Inverse ',
     $                            ' transform gauge is',
     $                            ' not egual input vector gauge',
     $                              gauge,gauges
          write(ich_summ, fmt = 7700) 'zfft1d_s', ' : ERROR'
          gauge_fatal = .TRUE.
          if (afatal) goto 90
      endif
      isign = 0
      call zEst( ich_summ, ich_snap, eps, atrace, m, 
     $           a_tst, a_fexp, gauges, fatal,
     $           'zfft1d_s', isign )
 90	continue
      fatal = fatal .or. gauge_fatal
	return

 7700 FORMAT( t2, a9, a / )
      end

      subroutine csampleFItest_1( ich_summ, ich_snap, eps, afatal,
     $	                        atrace, m, a_tst, a_fexp, ws_exp,  
     $                            fatal)
* ---------------------------------------------------------------
* -- Testing Forward-Inverse transform (complex*8) for sample --
* ---------------------------------------------------------------
* --- Parameters
      real*4            zero, one
      parameter       ( zero = 0.e0, one = 1.e0)

* --- Input Arguments
      integer          ich_summ, ich_snap
      real             eps
      logical          afatal, atrace

      integer          m
      integer          isign
      complex          a_tst( * )
      complex          a_fexp( * )
      complex          ws_exp( * )

* --- Output Arguments
      logical          fatal

* ---  Local Variables
      real (KIND=8)           gauge, gauges, gausub
      logical          gauge_fatal

* --- Executable Statements

*     -- Initialize vector for testing
      call cRandm(a_tst, m)
      call cmCopy(a_tst, a_fexp, m)

      call cfft1d_s( a_tst, m, 0, ws_exp)
      isign = -1
      call ccomp_gauge (a_tst, m, isign, gauges)
      call cfft1d_s( a_tst, m, isign, ws_exp)
      isign = 1
      call cfft1d_s( a_tst, m, isign, ws_exp)

      isign = -1
      call ccomp_gauge (a_tst, m, isign, gauge)

      fatal  = .FALSE.
      gauge_fatal  = .FALSE.

      gausub = (abs(gauges-gauge) ) / eps
      if ( gauges .ne. zero ) gausub = gausub/gauges
      if (gausub .ge. one) then
          write(ich_summ, fmt = *)' ** FATAL: Forward-Inverse ',
     $                            ' transform gauge is',
     $                            ' not egual input vector gauge',
     $                             gauge,gauges
          write(ich_summ, fmt = 7700) 'cfft1d_s', ' : ERROR'
          gauge_fatal = .TRUE.
          if (afatal) goto 90
      endif
      isign = 0
      call cEst( ich_summ, ich_snap, eps, atrace, m, 
     $           a_tst, a_fexp, gauges, fatal,
     $           'cfft1d_s', isign )
 90	continue
      fatal = fatal .or. gauge_fatal
	return

 7700 FORMAT( t2, a9, a / )
      end


      subroutine zsampleFItest_2( ich_summ, ich_snap, eps, afatal,
     $	                        atrace, m, a_tst, a_fexp, ws_exp, 
     $                            fatal)
* ---------------------------------------------------------------
* -- Testing Forward-Inverse transform (complex (KIND=8)) for sample --
*             with out bitreverse
* ---------------------------------------------------------------
* --- Parameters
      real (KIND=8)            zero, one
      parameter       ( zero = 0.e0, one = 1.e0)

* --- Input Arguments
      integer          ich_summ, ich_snap
      real (KIND=8)           eps
      logical          afatal, atrace

      integer          m
      integer          isign
      complex (KIND=8)       a_tst( * )
      complex (KIND=8)       a_fexp( * )
      complex (KIND=8)       ws_exp( * )

* --- Output Arguments
      logical          fatal

* ---  Local Variables
      real (KIND=8)           gauge, gauges, gausub
      logical          gauge_fatal

* --- Executable Statements

*     -- Initialize vector for testing
      call zRandm(a_tst, m)
      call zmCopy(a_tst, a_fexp, m)

      call zfft1d_s( a_tst, m, 0, ws_exp)
      isign = -2
      call zcomp_gauge (a_tst, m, isign, gauges)
      call zfft1d_s( a_tst, m, isign, ws_exp)
      isign = 2
      call zfft1d_s( a_tst, m, isign, ws_exp)

      isign = -2
      call zcomp_gauge (a_tst, m, isign, gauge)

      fatal  = .FALSE.
      gauge_fatal  = .FALSE.

      gausub = (dabs(gauges-gauge) ) / eps
      if ( gauges .ne. zero ) gausub = gausub/gauges
      if (gausub .ge. one) then
          write(ich_summ, fmt = *)' ** FATAL: Forward-Inverse ',
     $                            ' with out bitreverse ',
     $                            ' transform gauge is',
     $                            ' not egual input vector gauge',
     $                              gauge,gauges
          write(ich_summ, fmt = 7700) 'zfft1d_s', ' : ERROR'
          gauge_fatal = .TRUE.
          if (afatal) goto 90
      endif
      isign = 20
      call zEst( ich_summ, ich_snap, eps, atrace, m, 
     $           a_tst, a_fexp, gauges, fatal,
     $           'zfft1d_s', isign )
90    continue
      fatal = fatal .or. gauge_fatal
	return

 7700 FORMAT( t2, a9, a / )
      end

      subroutine csampleFItest_2( ich_summ, ich_snap, eps, afatal,
     $                            atrace, m, a_tst, a_fexp, ws_exp,  
     $                            fatal)
* ---------------------------------------------------------------
* -- Testing Forward-Inverse transform (complex*8) for sample --
*             with out bitreverse
* ---------------------------------------------------------------
* --- Parameters
      real             zero, one
      parameter       ( zero = 0.e0, one = 1.e0)

* --- Input Arguments
      integer          ich_summ, ich_snap
      real             eps
      logical          afatal, atrace

      integer          m
      integer          isign
      complex          a_tst( * )
      complex          a_fexp( * )
      complex          ws_exp( * )

* --- Output Arguments
      logical          fatal

* ---  Local Variables
      real (KIND=8)           gauge, gauges, gausub
      logical          gauge_fatal

* --- Executable Statements

*     -- Initialize vector for testing
      call cRandm(a_tst, m)
      call cmCopy(a_tst, a_fexp, m)

      call cfft1d_s( a_tst, m, 0, ws_exp)
      isign = -2
      call ccomp_gauge (a_tst, m, isign, gauges)
      call cfft1d_s( a_tst, m, isign, ws_exp)
      isign = 2
      call cfft1d_s( a_tst, m, isign, ws_exp)

      isign = -2
      call ccomp_gauge (a_tst, m, isign, gauge)

      fatal  = .FALSE.
      gauge_fatal  = .FALSE.

      gausub = (abs(gauges-gauge) ) / eps
      if ( gauges .ne. zero ) gausub = gausub/gauges
      if (gausub .ge. one) then
          write(ich_summ, fmt = *)' ** FATAL: Forward-Inverse ',
     $                            ' with out bitreverse ',
     $                            ' transform gauge is',
     $                            ' not egual input vector gauge',
     $                            gauge,gauges
          write(ich_summ, fmt = 7700) 'cfft1d_s', ' : ERROR'
          gauge_fatal = .TRUE.
          if (afatal) goto 90
      endif
      isign = 20
      call cEst( ich_summ, ich_snap, eps, atrace, m, 
     $           a_tst, a_fexp, gauges, fatal,
     $           'cfft1d_s', isign )
90    continue
      fatal = fatal .or. gauge_fatal

      return

 7700 FORMAT( t2, a9, a / )
      end


      subroutine  zFItest_1  ( ich_summ, ich_snap, eps, atrace,
     $                         afatal, snames, m, ws_exp,  
     $                         a_tst, a_exp, gauge, sub_fatal, isub )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex (KIND=8))        --
* -----------------------------------------------------------
* --- Parameters
      real (KIND=8)          zero, one
      parameter       ( zero = 0.e0, one = 1.e0)
      integer           lmax
      parameter       ( lmax = 1048576 )

* --- Input Arguments
      integer          ich_summ, ich_snap, m, isub
      real (KIND=8)           eps
      logical          afatal, atrace
      complex (KIND=8)       a_tst(*), a_exp(*), ws_exp(*)
      character(len=8)      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real (KIND=8)           gauge


* --- Local Variables
      integer          isign
      real (KIND=8)           gauges, gausub
      logical          gauge_fatal
      integer           post_m, lpost_m, wm 
      parameter         (lpost_m = 512)
      complex (KIND=8)  ws_post( lpost_m )

* --- External subroutines
      external         zfft1d, zmCopy, zcomp_gauge, zEst

* --- Executable Statements
      post_m = lpost_m
	if (post_m > lmax-m) then
	    post_m = lmax-m
	end if

	wm = 3 * m / 2

      call zRandm(a_tst, m)
      call zmCopy(a_tst, a_exp, m)

      call zRandm(a_tst(m+1), post_m)
      call zmCopy(a_tst(m+1), a_exp(m+1), post_m)
      call zRandm(ws_exp(wm+1), post_m)
      call zmCopy(ws_exp(wm+1), ws_post, post_m)

      sub_fatal( isub ) = .FALSE.
      call zfft1d( a_tst, m, 0, ws_exp)
      isign = -1
      call zcomp_gauge (a_tst, m, isign, gauges)
      call zfft1d( a_tst, m, isign, ws_exp)
      isign = 1
      call zfft1d( a_tst, m, isign, ws_exp)
      
      isign = -1
      call zcomp_gauge (a_tst, m, isign, gauge)

      gauge_fatal  = .FALSE.
*      gausub = (dabs(gauges-gauge) ) / (eps*10.0)
*      if ( gauges .ne. zero ) gausub = gausub/gauges
*      if (gausub .ge. one) then
*          write(ich_summ, fmt = *)' ** FATAL: Forward-Inverse ',
*     $                            ' transform gauge is',
*     $                            ' not egual input vector gauge',
*     $                              gauge,gauges
*          write(ich_summ, fmt = 7700) 'zfft1d', ' : ERROR'
*          gauge_fatal = .TRUE.
*          if (afatal) goto 90
*      endif
      call zEst( ich_summ, ich_snap, eps, atrace, m, a_tst, a_exp,
     $           gauges, sub_fatal( isub ), snames(isub), 0 )
  90  continue

	call zpostm(a_tst, a_exp, ws_exp, ws_post, m, post_m,
     $	 sub_fatal( isub ), ich_summ, isign)

      sub_fatal( isub ) = sub_fatal( isub ) .or. gauge_fatal
      return
 7700 FORMAT( t2, a8, a / )
      end


      subroutine cFItest_1 (ich_summ, ich_snap, eps, atrace,
     $                      afatal, snames, m, ws_exp, a_tst, 
     $                      a_exp, gauge, sub_fatal, isub)
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex (KIND=8))        --
* -----------------------------------------------------------
* --- Parameters
      real             zero, one
      parameter       ( zero = 0.e0, one = 1.e0)
      integer           lmax
      parameter       ( lmax = 1048576 )

* --- Input Arguments
      integer           ich_summ, ich_snap, m, isub
      real              eps
      logical           afatal, atrace
      complex*8         a_tst(*), a_exp(*), ws_exp(*)
      character(len=8)       snames(*)

* --- Output Arguments
      logical           sub_fatal(*)
      real (KIND=8)            gauge

* --- Local Variables
      integer           isign
      real (KIND=8)            gauges, gausub
      logical           gauge_fatal
      integer           post_m, lpost_m, wm 
      parameter         (lpost_m = 512)
      complex (KIND=4)  ws_post( lpost_m )

* --- External subroutines
      external          cfft1d, cmCopy,
     $                  ccomp_gauge, cEst

* --- Executable Statements
      post_m = lpost_m
	if (post_m > lmax-m) then
	    post_m = lmax-m
	end if

	wm = 3 * m / 2

      call cRandm(a_tst, m)
      call cmCopy(a_tst, a_exp, m)
      call cRandm(a_tst(m+1), post_m)
      call cmCopy(a_tst(m+1), a_exp(m+1), post_m)
      call cRandm(ws_exp(wm+1), post_m)
      call cmCopy(ws_exp(wm+1), ws_post, post_m)

      sub_fatal( isub ) = .FALSE.
      call cfft1d( a_tst, m, 0, ws_exp)
      isign = -1
      call ccomp_gauge (a_tst, m, isign, gauges)
      call cfft1d( a_tst, m, isign, ws_exp)
      isign = 1
      call cfft1d( a_tst, m, isign, ws_exp)

      isign = -1
      call ccomp_gauge (a_tst, m, isign, gauge)

      gauge_fatal  = .FALSE.
      gausub = (abs(gauges-gauge) ) / eps
      if ( gauges .ne. zero ) gausub = gausub/gauges
	if (gausub .ge. one) then
          write(ich_summ, fmt = *)' ** FATAL: Forward-Inverse ',
     $                            ' transform gauge is',
     $                            ' not egual input vector gauge',
     $                            gauge,gauges
          write(ich_summ, fmt = 7700) 'cfft1d', ' : ERROR'
          gauge_fatal = .TRUE.
          if (afatal) goto 90
      endif

      call cEst( ich_summ, ich_snap, eps, atrace, m, a_tst, a_exp,
     $           gauges, sub_fatal( isub ), snames(isub), 0 )
  90  continue
	call cpostm(a_tst, a_exp, ws_exp, ws_post, m, post_m,
     $	 sub_fatal( isub ), ich_summ, isign)

      sub_fatal( isub ) = sub_fatal( isub ) .or. gauge_fatal
      return

 7700 FORMAT( t2, a8, a / )
      end

   
      subroutine  zFItest_2  ( ich_summ, ich_snap, eps, atrace,
     $                         afatal, snames, m, ws_exp, a_tst,   
     $                         a_exp, gauge, sub_fatal, isub )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex (KIND=8))        --
* -----------------------------------------------------------
* --- Parameters
      real (KIND=8)          zero, one
      parameter       ( zero = 0.e0, one = 1.e0)
      integer           lmax
      parameter       ( lmax = 1048576 )

* --- Input Arguments
      integer          ich_summ, ich_snap, m, isub
      real (KIND=8)           eps
      logical          afatal, atrace
      complex (KIND=8)       a_tst(*), a_exp(*), ws_exp(*)
      character(len=8)      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real (KIND=8)           gauge

* --- Local Variables
      integer          isign
      real (KIND=8)           gauges, gausub
      logical          gauge_fatal
      integer           post_m, lpost_m, wm 
      parameter         (lpost_m = 256)
      complex (KIND=8)  ws_post( lpost_m )

* --- External subroutines
      external         zfft1d, zmCopy, zcomp_gauge, zEst

* --- Executable Statements
      post_m = lpost_m
	if (post_m > lmax-m) then
	    post_m = lmax-m
	end if

	wm = 3 * m / 2

      call zRandm(a_tst, m)
      call zmCopy(a_tst, a_exp, m)

      call zRandm(a_tst(m+1), post_m)
      call zmCopy(a_tst(m+1), a_exp(m+1), post_m)
      call zRandm(ws_exp(wm+1), post_m)
      call zmCopy(ws_exp(wm+1), ws_post, post_m)

      sub_fatal( isub ) = .FALSE.
      call zfft1d( a_tst, m, 0, ws_exp)
      isign = -2
      call zcomp_gauge (a_tst, m, isign, gauges)
      call zfft1d( a_tst, m, isign, ws_exp)
      isign = 2
      call zfft1d( a_tst, m, isign, ws_exp)
	isign = -2
      call zcomp_gauge (a_tst, m, isign, gauge)

      gauge_fatal  = .FALSE.
*      gausub = (dabs(gauges-gauge) ) / (eps*10.0)
*      if ( gauges .ne. zero ) gausub = gausub/gauges
*      if (gausub .ge. one) then
*          write(ich_summ, fmt = *)' ** FATAL: Forward-Inverse ',
*     $                            ' with out bitreverse ',
*     $                            ' transform gauge is',
*     $                            ' not egual input vector gauge',
*     $                              gauge,gauges
*          write(ich_summ, fmt = 7700) 'zfft1d', ' : ERROR'
*          gauge_fatal = .TRUE.
*          if (afatal) goto 90
*      endif

      call zEst( ich_summ, ich_snap, eps, atrace, m, a_tst, a_exp,
     $           gauges, sub_fatal( isub ), snames(isub), 20 )
  90  continue
	  call zpostm(a_tst, a_exp, ws_exp, ws_post, m, post_m,
     $	 sub_fatal( isub ), ich_summ, isign)

      sub_fatal( isub ) = sub_fatal( isub ) .or. gauge_fatal
      return
 7700 FORMAT( t2, a8, a / )
      end

      subroutine cFItest_2 (ich_summ, ich_snap, eps, atrace,
     $	                  afatal, snames, m, ws_exp, a_tst,
     $                      a_exp, gauge, sub_fatal, isub)
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex (KIND=8))        --
* -----------------------------------------------------------
* --- Parameters
      real             zero, one
      parameter       ( zero = 0.e0, one = 1.e0)
      integer           lmax
      parameter       ( lmax = 1048576 )

* --- Input Arguments
      integer           ich_summ, ich_snap, m, isub
      real              eps
      logical           afatal, atrace
      complex*8         a_tst(*), a_exp(*), ws_exp(*)
      character(len=8)       snames(*)

* --- Output Arguments
      logical           sub_fatal(*)
      real (KIND=8)            gauge

* --- Local Variables
      integer           isign
      real (KIND=8)            gauges, gausub
      logical           gauge_fatal
      integer           post_m, lpost_m, wm 
      parameter         (lpost_m = 512)
      complex (KIND=4)  ws_post( lpost_m )

* --- External subroutines
      external          cfft1d, cmCopy,
     $                  ccomp_gauge, cEst

* --- Executable Statements
      post_m = lpost_m
	if (post_m > lmax-m) then
	    post_m = lmax-m
	end if

	wm = 3 * m / 2

      call cRandm(a_tst, m)
      call cmCopy(a_tst, a_exp, m)
      call cRandm(a_tst(m+1), post_m)
      call cmCopy(a_tst(m+1), a_exp(m+1), post_m)
      call cRandm(ws_exp(wm+1), post_m)
      call cmCopy(ws_exp(wm+1), ws_post, post_m)

      sub_fatal( isub ) = .FALSE.
      call cfft1d( a_tst, m, 0, ws_exp)
      isign = -2
      call ccomp_gauge (a_tst, m, isign, gauges)
      call cfft1d( a_tst, m, isign, ws_exp)
      isign = 2
      call cfft1d( a_tst, m, isign, ws_exp)
  
      isign = -2
      call ccomp_gauge (a_tst, m, isign, gauge)

      gauge_fatal  = .FALSE.
      gausub = (abs(gauges-gauge) ) / eps
      if ( gauges .ne. zero ) gausub = gausub/gauges
      if (gausub .ge. one) then
          write(ich_summ, fmt = *)' ** FATAL: Forward-Inverse ',
     $                            ' with out bitreverse ',
     $                            ' transform gauge is',
     $                            ' not egual input vector gauge',
     $                            gauge,gauges
          write(ich_summ, fmt = 7700) 'cfft1d', ' : ERROR'
          gauge_fatal = .TRUE.
          if (afatal) goto 90
      endif
      call cEst( ich_summ, ich_snap, eps, atrace, m, a_tst, a_exp,
     $           gauges, sub_fatal( isub ), snames(isub), 20 )
  90  continue
	call cpostm(a_tst, a_exp, ws_exp, ws_post, m, post_m,
     $	 sub_fatal( isub ), ich_summ, isign)

      sub_fatal( isub ) = sub_fatal( isub ) .or. gauge_fatal
      return

 7700 FORMAT( t2, a8, a / )
      end

      subroutine  zrCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m, a_tmp,  
     $                  a_tst, a_exp_in, a_exp_out, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)
* ----------------------------------------------------------------------
* -- Testing in compare with DFT (complex (KIND=8))                         --
* ----------------------------------------------------------------------
* --- Parameters
      real (KIND=8)            zero, one
      parameter       ( zero = 0.d0, one = 1.d0 )
      real (KIND=8)    Zr_gauge_deg
      parameter       ( Zr_gauge_deg = 1.d1)
      integer           lmax
      parameter       ( lmax = 1048576 )

* --- Input Arguments
      integer           ich_summ, ich_snap, isub, m
      real (KIND=8)            eps, a_tst( * )
      logical           atrace, afatal, dft_check
      complex (KIND=8)        a_tmp( * ), a_exp_in( * )
      complex (KIND=8)        a_exp_out( * ), ws_exp( * )
      character(len=8)       snames(*)

* --- Output Arguments
      logical           sub_fatal(*)
      real (KIND=8)            gauge,gauges

* --- Local Variables
      logical           gauge_fatal
      integer           isign
      real (KIND=8)            gausub
      integer           post_m, lpost_m, wm 
      parameter         (lpost_m = 512)
      complex (KIND=8)  ws_post( lpost_m )

* --- External subroutines
      external          zexp1d, zdfft1d, zmCopy

* --- Executable Statements

      if (isub .EQ. 3) isign = -1
      if (isub .EQ. 5) isign = 1

      post_m = lpost_m
	if (post_m > lmax-m) then
	    post_m = lmax-m-2
	end if

	wm = 2 * m
*     -- Initialize vector for testing
      call dRandm(a_tst, m+2)
      if (isign .EQ. -1) then
         a_tst(m+1) = 0.0
         a_tst(m+2) = 0.0
         call dzmCopy_exp(a_tst, a_exp_in, m)
         call zcomp_gauge (a_exp_in, m, isign, gauges)
      else
         a_tst(2) = 0.0
         a_tst(m+2) = 0.0
         call dzmCopy(a_tst, a_exp_in, m)
      endif
      
	call zcomp_gauge (a_exp_in, m, isign, gauges)

      if (dft_check) then
        call zexp1d(a_exp_in, m, isign, ws_exp, a_exp_out, gauge)
      else
        call zfft1d_s(a_exp_in, m, 0, ws_exp)
        call zfft1d_s(a_exp_in, m, isign, ws_exp)
        call zmCopy(a_exp_in, a_exp_out, m)
      endif

      sub_fatal( isub ) = .FALSE.
      gauge_fatal = .FALSE.
      
      call dRandm(a_tst(m+3), post_m)
      call dmCopy(a_tst(m+3), a_exp_in(m+3), post_m)
      call zRandm(ws_exp(wm+1), post_m)
      call zmCopy(ws_exp(wm+1), ws_post, post_m)

      call dzfft1d( a_tst, m, 0, ws_exp)
      call zdfft1d( a_tst, m, 0, ws_exp)
      
	  if (isign .EQ. -1) then
         call dzfft1d( a_tst, m, isign, ws_exp)
      else
         call zdfft1d( a_tst, m, isign, ws_exp)
      endif

	  if (isign .EQ. -1) then
         call dzmCopy(a_tst, a_exp_in, m)
      else
         call dzmCopy_exp(a_tst, a_exp_in, m)
      endif

      if (isign.eq.-1) then
         isign = 1
      else
         isign = -1
      endif

	call zcomp_gauge (a_exp_in, m, isign, gauge)
*      call dcomp_gauge (a_tst, m, isign, gauge, a_tmp)

      if (isign.eq.-1) then
         isign = 1
      else
         isign = -1
      endif

      gausub = (dabs(gauges-gauge) ) / (eps * Zr_gauge_deg)

      if ( gauges .ne. zero ) gausub = gausub/gauges
      if (gausub .ge. one) then
         if (isign.eq.-1) then
            write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                     ' transform gauge is',
     $                     ' not egual input vector gauge',
     $                       gauge,gauges
         else
            write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                     ' transform gauge is',
     $                     ' not egual input vector gauge',
     $                       gauge,gauges
         endif
         write(ich_summ, fmt = 7700) snames( isub ), ' : ERROR'
         sub_fatal( isub ) = .TRUE.
         gauge_fatal = .TRUE.
         if (afatal) goto 90
      endif

      call zEst( ich_summ, ich_snap, eps, atrace, m, a_exp_in,
     $           a_exp_out, gauges, sub_fatal( isub ),
     $           snames(isub), isign )
      if (afatal) GO TO 90

  90  continue
      if (gauge_fatal) sub_fatal(isub) = .TRUE.

	call zrpostm(a_tst(m+3), a_exp_in(m+3), ws_exp(wm+1), ws_post, m,
     $	  post_m, sub_fatal( isub ), ich_summ, isign)


      return

 7700 FORMAT( t2, a8, a / )
      end


      subroutine crCmpretest (ich_summ, ich_snap, eps, atrace, snames,
     $                        m, a_tmp, a_tst, a_exp_in, a_exp_out,
     $                        ws_exp, gauge, sub_fatal, afatal,
     $                        isub, dft_check )
* ----------------------------------------------------------------------
* -- Testing in compare with DFT (complex*8)                          --
* ----------------------------------------------------------------------
* --- Parameters
      real*4            zero, one
      parameter       ( zero = 0.e0, one = 1.e0 )
      integer           lmax
      parameter       ( lmax = 1048576 )

* --- Input Arguments
      integer          ich_summ, ich_snap, isub, m
      real*4           eps, a_tst( * )
      logical          atrace, afatal, dft_check
      complex*8        a_tmp( * ), a_exp_in( * )
      complex*8        a_exp_out( * ), ws_exp( * )
      character(len=8)      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real (KIND=8)           gauge,gauges

* --- Local Variables
      logical          gauge_fatal
      integer          isign
      real (KIND=8)           gausub
      real*4           eps_err
      integer           post_m, lpost_m, wm 
      parameter         (lpost_m = 512)
      complex (KIND=4)  ws_post( lpost_m )

* --- External subroutines
      external         zexp1d, zdfft1d, zmCopy

* --- Executable Statements

      if (isub .EQ. 4) isign = -1
      if (isub .EQ. 6) isign = 1

      post_m = lpost_m
	if (post_m > lmax-m) then
	    post_m = lmax-m-2
	end if

	wm = 2 * m
*     -- Initialize vector for testing
      call sRandm(a_tst, m+2)
      if (isign .EQ. -1) then
          a_tst(m+1) = 0.0
          a_tst(m+2) = 0.0
        call scmCopy_exp(a_tst, a_exp_in, m)
      else
          a_tst(2) = 0.0
          a_tst(m+2) = 0.0
          call scmCopy(a_tst, a_exp_in, m)
      endif

      call ccomp_gauge (a_exp_in, m, isign, gauges)
      
	  if (dft_check) then
        call cexp1d(a_exp_in, m, isign, ws_exp, a_exp_out, gauge)
      else
        call cfft1d_s(a_exp_in, m, 0, ws_exp)
        call cfft1d_s(a_exp_in, m, isign, ws_exp)
        call cmCopy(a_exp_in, a_exp_out, m)
      endif
      sub_fatal( isub ) = .FALSE.
      gauge_fatal = .FALSE.

      call sRandm(a_tst(m+3), post_m)
      call smCopy(a_tst(m+3), a_exp_in(m+3), post_m)
      call cRandm(ws_exp(wm+1), post_m)
      call cmCopy(ws_exp(wm+1), ws_post, post_m)

      call scfft1d( a_tst, m, 0, ws_exp)

      if (isign .EQ. -1) then
        call scfft1d( a_tst, m, isign, ws_exp)
      else
        call csfft1d( a_tst, m, isign, ws_exp)
      endif

      if (isign .EQ. -1) then
        call scmCopy(a_tst, a_exp_in, m)
      else
        call scmCopy_exp(a_tst, a_exp_in, m)
      endif

      if (isign.eq.-1) then
         isign = 1
      else
         isign = -1
      endif
*      call scomp_gauge (a_tst, m, isign, gauge, a_tmp)
      call ccomp_gauge (a_exp_in, m, isign, gauge)
      if (isign.eq.-1) then
         isign = 1
      else
         isign = -1
      endif

      gausub = (abs(gauges-gauge)) / eps
      if ( gauges .ne. zero ) gausub = gausub/gauges
      if (gausub .ge. one) then
         if (isign.eq.-1) then
            write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $            ' transform gauge is',
     $            ' not egual input vector gauge',
     $              gauge,gauges
         else
            write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $            ' transform gauge is',
     $            ' not egual input vector gauge',
     $              gauge,gauges
         endif
         write(ich_summ, fmt = 7700) snames( isub ), ' : ERROR'
         sub_fatal( isub ) = .TRUE.
         gauge_fatal = .TRUE.
         if (afatal) goto 90
      endif

      eps_err = eps
      call cEst (ich_summ, ich_snap, eps_err, atrace, m, a_exp_in, 
     $           a_exp_out, gauges, sub_fatal( isub ),
     $           snames(isub), isign )
      if (afatal) GO TO 90

  90  continue
      if (gauge_fatal) sub_fatal(isub) = .TRUE.

	call crpostm(a_tst(m+3), a_exp_in(m+3), ws_exp(wm+1), ws_post, m,
     $	  post_m, sub_fatal( isub ), ich_summ, isign)

      return

 7700 FORMAT( t2, a8, a / )
      end

      subroutine zrFItest (ich_summ, ich_snap, eps, atrace, snames, m,
     $                    a_tmp, a_tst, a_exp, gauge, sub_fatal, isub)
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex (KIND=8))        --
* -----------------------------------------------------------
      integer           lmax
      parameter       ( lmax = 1048576 )
* --- Input Arguments
      integer           ich_summ, ich_snap, m, isub
      real (KIND=8)            eps
      logical           atrace
      complex (KIND=8)        a_tmp(*)
      real (KIND=8)            a_tst(*), a_exp(*)
      character(len=8)       snames(*)

* --- Output Arguments
      logical           sub_fatal(*)
      real (KIND=8)            gauge

* --- Local Variables
      integer           isign
      integer           post_m, lpost_m, wm 
      parameter         (lpost_m = 512)
      complex (KIND=8)  ws_post( lpost_m )

* --- Executable Statements
      post_m = lpost_m
	if (post_m > lmax-m) then
	    post_m = lmax-m-2
	end if

	wm = 2 * m

      call dRandm(a_tst, m)
      call dmCopy(a_tst, a_exp, m)

      call dRandm(a_tst(m+3), post_m)
      call dmCopy(a_tst(m+3), a_exp(m+3), post_m)

      sub_fatal( isub ) = .FALSE.
      isign = -1
      call dcomp_gauge (a_tst, m, isign, gauge, a_tmp)

      call zRandm(a_tmp(wm+1), post_m)
      call zmCopy(a_tmp(wm+1), ws_post, post_m)

      call dzfft1d( a_tst, m, 0, a_tmp)
      call dzfft1d( a_tst, m, isign, a_tmp)
      call zdfft1d( a_tst, m, 0, a_tmp)
      call zdfft1d( a_tst, m, isign, a_tmp)
      call dEst( ich_summ, ich_snap, eps, atrace, m, a_tst, a_exp,
     $           gauge, sub_fatal( isub ), snames(isub), 0 )

  100 continue
	call zrpostm(a_tst(m+3), a_exp(m+3), a_tmp(wm+1), ws_post, m,
     $	  post_m, sub_fatal( isub ), ich_summ, isign)

      return

 7700 FORMAT( t2, a8, a / )
      end

      subroutine crFItest (ich_summ, ich_snap, eps, atrace, snames, m,
     $                    a_tmp, a_tst, a_exp, gauge, sub_fatal, isub)
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex (KIND=8))        --
* -----------------------------------------------------------
      integer           lmax
      parameter       ( lmax = 1048576 )
* --- Input Arguments
      integer           ich_summ, ich_snap, m, isub
      real*4            eps
      logical           atrace
      complex*8         a_tmp(*)
      real*4            a_tst(*), a_exp(*)
      character(len=8)       snames(*)

* --- Output Arguments
      logical           sub_fatal(*)
      real (KIND=8)            gauge

* --- Local Variables
      integer           isign
      integer           post_m, lpost_m, wm 
      parameter         (lpost_m = 512)
      complex (KIND=4)  ws_post( lpost_m )

* --- Executable Statements
      post_m = lpost_m
	if (post_m > lmax-m) then
	    post_m = lmax-m-2
	end if

	wm = 2 * m

      call sRandm(a_tst, m)
      call smCopy(a_tst, a_exp, m)
      call sRandm(a_tst(m+3), post_m)
      call smCopy(a_tst(m+3), a_exp(m+3), post_m)

      sub_fatal( isub ) = .FALSE.
      isign = -1
      call scomp_gauge (a_tst, m, isign, gauge, a_tmp)

      call cRandm(a_tmp(wm+1), post_m)
      call cmCopy(a_tmp(wm+1), ws_post, post_m)

      call scfft1d( a_tst, m, 0, a_tmp)
      call scfft1d( a_tst, m, isign, a_tmp)
      call csfft1d( a_tst, m, isign, a_tmp)

      call sEst( ich_summ, ich_snap, eps, atrace, m, a_tst, a_exp,
     $           gauge, sub_fatal( isub ), snames(isub), 0 )
  100 continue

	call crpostm(a_tst(m+3), a_exp(m+3), a_tmp(wm+1), ws_post, m,
     $	  post_m, sub_fatal( isub ), ich_summ, isign)

      return

 7700 FORMAT( t2, a8, a / )
      end


      real (KIND=8) function dCeps( done, dhalf, dzero )
* ------------------------------------------------------------------
*     Compute machine-dependent double precision epsilon          --
* ------------------------------------------------------------------

      real (KIND=8)            done, dhalf, dzero
      real (KIND=8)            dDiff
      external          dDiff

      dCeps = done
   10 continue
      if ( dDiff( done + dCeps, done).eq.dzero) GO TO 20
      dCeps = dhalf * dCeps
      GO TO 10
   20 dCeps = dCeps + dCeps
      return
      end


      real function sCeps( sone, shalf, szero )
* ------------------------------------------------------------------
*     Compute machine-dependent single precision epsilon          --
* ------------------------------------------------------------------

      real              sone, shalf, szero
      real              sDiff
      external          sDiff

      sCeps = sone
   10 continue
      if ( sDiff( sone + sCeps, sone).eq.szero) GO TO 20
      sCeps = shalf * sCeps
      GO TO 10
   20 sCeps = sCeps + sCeps
      return
      end


      real (KIND=8) function dDiff( x, y )
* -----------------------------------------------------------
* --  Compute two double precision values difference       --
* -----------------------------------------------------------
      real (KIND=8) x, y

      dDiff = x - y
      return
      end


      real function sDiff( x, y )
* -----------------------------------------------------------
* --  Compute two single precision values difference       --
* -----------------------------------------------------------
      real x, y

      sDiff = x - y
      return
      end

      subroutine  zEst ( ich_summ, ich_snap, eps, atrace, m, a_tst,
     $                   a_exp, gauge, sub_fatal, name, isign)
* --------------------------------------------------------------
* --  Compare obtained result with true one (complex (KIND=8))      --
* --  (relative estimation)                                   --
* --------------------------------------------------------------
* --- Parameters
      real (KIND=8)            zero, one
      parameter         ( zero = 0.d0, one = 1.d0 )

* --- Input Arguments
      real (KIND=8)            eps, gauge
      integer           ich_summ, ich_snap, m, isign
      complex (KIND=8)        a_tst(*), a_exp(*)
      logical           atrace
      character(len=8)       name

* --- Output Arguments
      logical           sub_fatal

* --- Local Variables
      real (KIND=8)            err, errij
      integer           i, ierr, ierrfirst
      complex (KIND=8)        C
      logical           nan_fatal

* --- Intrinsic function
      intrinsic         dsqrt, dble

* --- Statement funtions
      real (KIND=8)            abs1
* --- Statement funtions definitions
      abs1( C ) = dsqrt( dble(C)*dble(C) + dimag(C)*dimag(C))

      ich_summ = ich_summ
      ierrfirst = -1
      sub_fatal = .FALSE.
      err = zero

* --- NAN checking      
	nan_fatal = .FALSE.
      do i = 1, m
*          write(ich_snap, fmt = 6602 ) i, 
*     $                                 a_exp( i ),
*     $                                 a_tst( i )

		call ZFXBAD( a_tst(i), nan_fatal ) 
		if( nan_fatal ) then
              sub_fatal = .TRUE.
  	        goto 10
      	endif
	enddo
	
10    if (nan_fatal) then
          if (isign.EQ.0) then
		    write(ich_snap , fmt = 7701 ) name,
     $        '  ISIGN = -1:+1', '  M = ', m, ' NAN FATAL ERROR '
          else
            if (isign.EQ.20) then
			  write(ich_snap , fmt = 7701 ) name,
     $          '  ISIGN = -2:+2', '  M = ', m, ' NAN FATAL ERROR '
            else
                write(ich_snap , fmt = 7700 ) name,
     $         '  ISIGN = ', isign, '  M = ', m, ' NAN FATAL ERROR '
		  endif
		endif
	    goto 120
        endif
      
	do i = 1, m
          errij = abs1( a_tst( i ) - a_exp( i ) ) / eps
          if ( gauge .ne. zero ) then
             if(m .GE. 131072 ) then
                errij = errij/(gauge*10.0)
             else 
                errij = errij/gauge
             end if
          end if
          if (errij. gt. err ) then
             err =  errij
             ierr = i
          end if
          if (errij .ge. one) then
             sub_fatal = .TRUE.
             if (ierrfirst.eq.-1) then
               ierrfirst = ierr
             endif
          endif
      end do

 100  continue

      if ( sub_fatal ) then
        if (atrace) then
          if (isign.EQ.0) then
		    write(ich_snap , fmt = 7701 ) name,
     $               '  ISIGN = -1:+1', '  M = ', m, 'ERROR '
          else
            if (isign.EQ.20) then
			    write(ich_snap , fmt = 7701 ) name,
     $               '  ISIGN = -2:+2', '  M = ', m, ' ERROR'
          	else
                write(ich_snap , fmt = 7700 ) name,
     $            '  ISIGN = ', isign, '  M = ', m, ' ERROR'
		  	endif
		  endif
        endif
        if (atrace) then
          write(ich_snap, fmt = *)
          write(ich_snap, fmt = 6601 )
     $        '**** Fatal Error - computed result is less than hal',
     $         'f accurate ****',
     $         '                       expected re',
     $         'sult                    computed result',
     $         ' first difference:'
          write(ich_snap, fmt = 6602 ) ierrfirst, 
     $                                 a_exp( ierrfirst ),
     $                                 a_tst( ierrfirst )
          write(ich_snap, fmt = 6603 ) 'maximum difference:'
          write(ich_snap, fmt = 6602 ) ierr, 
     $                                 a_exp( ierr ),
     $                                 a_tst( ierr )

          write(ich_snap,fmt = *) '  Matrix gauge: ',gauge
          errij =  abs1( a_tst( ierrfirst ) -
     $                   a_exp( ierrfirst ) )
          write(ich_snap,fmt = *)
     $     '  first |a(i) - a_expect(i)|: ', errij
          errij =  abs1( a_tst( ierr ) - a_exp( ierr ) )
          write(ich_snap,fmt = *)
     $     '  max   |a(i) - a_expect(i)|: ', errij

        endif
      else
        if (atrace) then
          if (isign.EQ.0) then
		    write(ich_snap , fmt = 7701 ) name,
     $               '  ISIGN = -1:+1', '  M = ', m, ' '
          else
            if (isign.EQ.20) then
			    write(ich_snap , fmt = 7701 ) name,
     $               '  ISIGN = -2:+2', '  M = ', m, ' '
          	else
                write(ich_snap , fmt = 7700 ) name,
     $            '  ISIGN = ', isign, '  M = ', m, ' '
		  	endif
		  endif
        endif
      endif
 120  return

 6601 FORMAT( t2, a, a /  a, a, / a )
 6602 FORMAT( 1X, I6, 2( '  (', G15.6, ',', G15.6, ')' ) )
 6603 FORMAT( t2, a )
 7700 FORMAT( t2, a8, a, i5, a, i6, a)
 7701 FORMAT( t2, a8, a, a, i6,  a)

      end

      subroutine cEst (ich_summ, ich_snap, eps, atrace, m, a_tst,
     $                 a_exp, gauge, sub_fatal, name, isign)
* --------------------------------------------------------------
* --  Compare obtained result with true one (complex (KIND=8))      --
* --  (relative estimation)                                   --
* --------------------------------------------------------------
* --- Parameters
      real*4            zero, one
      parameter       ( zero = 0.e0, one = 1.e0 )

* --- Input Arguments
      real (KIND=8)            gauge
      real*4            eps
      integer           ich_summ, ich_snap, m, isign
      complex*8         a_tst(*), a_exp(*)
      logical           atrace
      character(len=8)       name

* --- Output Arguments
      logical           sub_fatal

* --- Local Variables
      complex           C
      real (KIND=8)            err, errij
      integer           i, ierr, ierrfirst
      logical           nan_fatal

* --- Intrinsic function
      intrinsic         sqrt, real

* --- Statement funtions
      real (KIND=8)            abs1
* --- Statement funtions definitions
      abs1( C ) = sqrt( real(C)*real(C) + imag(C)*imag(C))

      ich_summ = ich_summ
      ierrfirst = -1
      sub_fatal = .FALSE.
      err = zero

*      do i = 1, m
*          write(ich_snap, fmt = 6602 ) i, a_exp(i), a_tst(i)
*	  enddo

* --- NAN checking      
      nan_fatal = .FALSE.
      do i = 1, m
	    call CFXBAD( a_tst(i), nan_fatal ) 
		if( nan_fatal ) then
                sub_fatal = .TRUE.
  	        goto 10
      	endif
	  enddo
	
10    if (nan_fatal) then
          if (isign.EQ.0) then
		    write(ich_snap , fmt = 7701 ) name,
     $        '  ISIGN = -1:+1', '  M = ', m, ' NAN FATAL ERROR '
          else
            if (isign.EQ.20) then
			  write(ich_snap , fmt = 7701 ) name,
     $          '  ISIGN = -2:+2', '  M = ', m, ' NAN FATAL ERROR '
            else
                write(ich_snap , fmt = 7700 ) name,
     $         '  ISIGN = ', isign, '  M = ', m, ' NAN FATAL ERROR '
		  endif
		endif
	    goto 120
      endif
      
      do i = 1, m
         
       errij = abs1( a_tst( i ) - a_exp( i ) ) / eps
	 
         if ( gauge .ne. zero ) errij = errij/gauge
         if (errij. gt. err ) then
            err =  errij
            ierr = i
         end if
         if (errij .ge. one) then
            sub_fatal = .TRUE.
            if (ierrfirst.eq.-1) then
              ierrfirst = ierr
            endif
         endif
      end do

 100  continue
      if ( sub_fatal ) then
        if (atrace) then
          if (isign.EQ.0) then
		    write(ich_snap , fmt = 7701 ) name,
     $               '  ISIGN = -1:+1', '  M = ', m, '  ERROR'
          else
            if (isign.EQ.20) then
			    write(ich_snap , fmt = 7701 ) name,
     $               '  ISIGN = -2:+2', '  M = ', m, '  ERROR'
          	else
                 write(ich_snap , fmt = 7700 ) name,
     $            '  ISIGN = ', isign, '  M = ', m, '  ERROR'
		endif
	    endif
          endif
        if (atrace) then
          write(ich_snap, fmt = *)
          write(ich_snap, fmt = 6601 )
     $        '**** Fatal Error - computed result is less than hal',
     $         'f accurate ****',
     $         '                       expected re',
     $         'sult                    computed result',
     $         ' first difference:'
          write(ich_snap, fmt = 6602 ) ierrfirst, 
     $                                 a_exp( ierrfirst ),
     $                                 a_tst( ierrfirst )
          write(ich_snap, fmt = 6603 ) 'maximum difference:'
          write(ich_snap, fmt = 6602 ) ierr, 
     $                                 a_exp( ierr ),
     $                                 a_tst( ierr )
          write(ich_snap,fmt = *) '  Matrix gauge: ',gauge
          errij =  abs1( a_tst( ierrfirst ) -
     $                   a_exp( ierrfirst ) )
          write(ich_snap,fmt = *)
     $     '  first |a(i) - a_expect(i)|: ', errij
          errij =  abs1( a_tst( ierr ) - a_exp( ierr ) )
          write(ich_snap,fmt = *)
     $     '  max   |a(i) - a_expect(i)|: ', errij

        endif
      else
        if (atrace) then
          if (isign.EQ.0) then
		    write(ich_snap , fmt = 7701 ) name,
     $               '  ISIGN = -1:+1', '  M = ', m, ' '
          else
            if (isign.EQ.20) then
			    write(ich_snap , fmt = 7701 ) name,
     $               '  ISIGN = -2:+2', '  M = ', m, ' '
          	else
                write(ich_snap , fmt = 7700 ) name,
     $            '  ISIGN = ', isign, '  M = ', m, ' '
		  	endif
		  endif
        endif
      endif
 120  return

 6601 FORMAT( t2, a, a /  a, a, / a )
 6602 FORMAT( 1X, I6, 2( '  (', G15.6, ',', G15.6, ')' ) )
 6603 FORMAT( t2, a )
 7700 FORMAT( t2, a8, a, i5, a, i6, a)
 7701 FORMAT( t2, a8, a, a, i6, a)
 7702 FORMAT( i6)
 
      end

      subroutine dEst (ich_summ, ich_snap, eps, atrace, m, a_tst,
     $                 a_exp, gauge, sub_fatal, name, isign)
* --------------------------------------------------------------
* --  Compare obtained result with true one (complex (KIND=8))      --
* --  (relative estimation)                                   --
* --------------------------------------------------------------
* --- Parameters
      real (KIND=8)            zero, one
      parameter         ( zero = 0.d0, one = 1.d0 )
 
* --- Input Arguments
      real (KIND=8)            eps, gauge
      integer           ich_summ, ich_snap, m, isign
      real (KIND=8)            a_tst(*), a_exp(*)
      logical           atrace
      character(len=8)       name

* --- Output Arguments
      logical           sub_fatal


* --- Local Variables
      real (KIND=8)            err, errij
      integer           i, ierr, ierrfirst, jerrfirst
      logical           nan_fatal
 
* --- Intrinsic function
      intrinsic dsqrt, iand

      ich_summ = ich_summ
      ierrfirst = -1
      jerrfirst = -1
      sub_fatal = .FALSE.
      err = zero

* --- NAN checking      
	nan_fatal = .FALSE.
      do i = 1, m
		call DFXBAD( a_tst, nan_fatal ) 
		if( nan_fatal ) then
              sub_fatal = .TRUE.
  	        goto 10
      	endif
	enddo
	
10    if (nan_fatal) then
          if (isign.EQ.0) then
		    write(ich_snap , fmt = 7701 ) name,
     $        '  ISIGN = -1:+1', '  M = ', m, ' NAN FATAL ERROR '
          else
              write(ich_snap , fmt = 7700 ) name,
     $         '  ISIGN = ', isign, '  M = ', m, ' NAN FATAL ERROR '
		endif
	    goto 120
      endif
      
      do i = 1, m
          errij = dabs( a_tst( i ) - a_exp( i ) ) / eps
          if ( gauge .ne. zero ) errij = errij/gauge
          if (errij. gt. err ) then
             err =  errij
             ierr = i
          end if
          if (errij .ge. one) then
             sub_fatal = .TRUE.
             if (ierrfirst.eq.-1) then
               ierrfirst = ierr
             endif
          endif
      end do

 100  continue
      if ( sub_fatal ) then
        if (atrace) then
          if (isign.NE.0) then
            write(ich_snap , fmt = 7700 ) name,
     $            '  ISIGN = ', isign, '  M = ', m, ' : ERROR'
          else
            write(ich_snap , fmt = 7701) name,
     $            '  ISIGN = -1:+1', '  M = ', m, ' : ERROR'
          endif
        endif
        if (atrace) then
          write(ich_snap, fmt = *)
          write(ich_snap, fmt = 6601 )
     $        '**** Fatal Error - computed result is less than hal',
     $         'f accurate ****',
     $         '                       expected re',
     $         'sult                    computed result',
     $         ' first difference:'
          write(ich_snap, fmt = 6602 ) ierrfirst,
     $                                 a_exp( ierrfirst ),
     $                                 a_tst( ierrfirst )
          write(ich_snap, fmt = 6603 ) 'maximum difference:'
          write(ich_snap, fmt = 6602 ) ierr, 
     $                                 a_exp( ierr ),
     $                                 a_tst( ierr )
          write(ich_snap,fmt = *) '  Matrix gauge: ',gauge
          errij =  dabs( a_tst( ierrfirst ) -
     $                   a_exp( ierrfirst ) )
          write(ich_snap,fmt = *)
     $     '  first |a(i) - a_expect(i)|: ', errij
          errij =  dabs( a_tst( ierr ) - a_exp( ierr ) )
          write(ich_snap,fmt = *)
     $     '  max   |a(i) - a_expect(i)|: ', errij
        endif
      else
        if (atrace) then
          if (isign.NE.0) then
            write(ich_snap , fmt = 7700 ) name,
     $            '  ISIGN = ', isign, '  M = ', m, ' '
          else
            write(ich_snap , fmt = 7701 ) name,
     $            '  ISIGN = -1:+1', '  M = ', m, ' '
          endif
        endif
      endif
 120  return

 6601 FORMAT( t2, a, a /  a, a, / a )
 6602 FORMAT( 1X, I6, 2( '  (', G15.6, ',', G15.6, ')' ) )
 6603 FORMAT( t2, a )
 7700 FORMAT( t2, a8, a, i5, a, i6, a)
 7701 FORMAT( t2, a8, a, a, i6, a)

      end


      subroutine sEst (ich_summ, ich_snap, eps, atrace, m, a_tst,
     $                 a_exp, gauge, sub_fatal, name, isign)
* --------------------------------------------------------------
* --  Compare obtained result with true one (complex (KIND=8))      --
* --  (relative estimation)                                   --
* --------------------------------------------------------------
* --- Parameters
      real*4            zero, one
      parameter         ( zero = 0.d0, one = 1.d0 )

* --- Input Arguments
      real (KIND=8)            gauge
      real*4            eps, a_tst(*), a_exp(*)
      integer           ich_summ, ich_snap, m, isign
      logical           atrace
      character(len=8)       name

* --- Output Arguments
      logical           sub_fatal


* --- Local Variables
      real*4            err, errij
      integer           i, ierr, ierrfirst
      logical           nan_fatal
 
* --- Intrinsic function
      intrinsic sqrt

      ich_summ = ich_summ
      ierrfirst = -1
      sub_fatal = .FALSE.
      err = zero

* --- NAN checking      
	nan_fatal = .FALSE.
      do i = 1, m
		call DFXBAD( a_tst, nan_fatal ) 
		if( nan_fatal ) then
              sub_fatal = .TRUE.
  	        goto 10
      	endif
	enddo
	
10    if (nan_fatal) then
          if (isign.EQ.0) then
		    write(ich_snap , fmt = 7701 ) name,
     $        '  ISIGN = -1:+1', '  M = ', m, ' NAN FATAL ERROR '
          else
              write(ich_snap , fmt = 7700 ) name,
     $         '  ISIGN = ', isign, '  M = ', m, ' NAN FATAL ERROR '
		endif
	    goto 120
      endif
      
      do i = 1, m
          errij = abs( a_tst( i ) - a_exp( i ) ) / eps
          if ( gauge .ne. zero ) errij = errij/gauge
          if (errij. gt. err ) then
             err =  errij
             ierr = i
          end if
          if (errij .ge. one) then
             sub_fatal = .TRUE.
             if (ierrfirst.eq.-1) then
               ierrfirst = ierr
             endif
          endif
      end do
 100  continue
      if ( sub_fatal ) then
        if (atrace) then
          if (isign.NE.0) then
            write(ich_snap , fmt = 7700 ) name,
     $            '  ISIGN = ', isign, '  M = ', m, ' : ERROR'
          else
            write(ich_snap , fmt = 7701) name,
     $            '  ISIGN = -1:+1', '  M = ', m, ' : ERROR'
          endif
        endif
        if (atrace) then
          write(ich_snap, fmt = *)
          write(ich_snap, fmt = 6601 )
     $        '**** Fatal Error - computed result is less than hal',
     $         'f accurate ****',
     $         '                       expected re',
     $         'sult                    computed result',
     $         ' first difference:'
          write(ich_snap, fmt = 6602 ) ierrfirst,
     $                                 a_exp( ierrfirst ),
     $                                 a_tst( ierrfirst )
          write(ich_snap, fmt = 6603 ) 'maximum difference:'
          write(ich_snap, fmt = 6602 ) ierr, 
     $                                 a_exp( ierr ),
     $                                 a_tst( ierr )
          write(ich_snap,fmt = *) '  Matrix gauge: ',gauge
          errij =  abs( a_tst( ierrfirst ) -
     $                   a_exp( ierrfirst ) )
          write(ich_snap,fmt = *)
     $     '  first |a(i) - a_expect(i)|: ', errij
          errij =  abs( a_tst( ierr ) - a_exp( ierr ) )
          write(ich_snap,fmt = *)
     $     '  max   |a(i) - a_expect(i)|: ', errij
        endif
      else
        if (atrace) then
          if (isign.NE.0) then
            write(ich_snap , fmt = 7700 ) name,
     $            '  ISIGN = ', isign, '  M = ', m, ' '
          else
            write(ich_snap , fmt = 7701 ) name,
     $            '  ISIGN = -1:+1', '  M = ', m, ' '
          endif
        endif
      endif
 120  return

 6601 FORMAT( t2, a, a /  a, a, / a )
 6602 FORMAT( 1X, I6, 2( '  (', G15.6, ',', G15.6, ')' ) )
 6603 FORMAT( t2, a )
 7700 FORMAT( t2, a8, a, i5, a, i6, a)
 7701 FORMAT( t2, a8, a, a, i6, a)

      end


      subroutine zcomp_gauge( a, m, isign, gauge )
* --------------------------------------------------------------
* --  Compute Input matrix gauge  (complex (KIND=8))                --
* --------------------------------------------------------------

* --- Input Arguments
      complex (KIND=8)   a(*)
      integer      m, isign
      real (KIND=8)       gauge

* ---  Local Variables
      integer      i

      gauge = 0.0d0
      do i = 1, m
         gauge = gauge + dble(a( i ))*dble(a( i )) +
     $                   dimag(a( i ))*dimag(a( i ))
      end do
      if (isign.ge.0) gauge = gauge/(dfloat(m))
      return
      end

      subroutine ccomp_gauge( a, m, isign, gauge )
* --------------------------------------------------------------
* --  Compute Input matrix gauge  (complex (KIND=8))                --
* --------------------------------------------------------------

* --- Input Arguments
      complex      a(*)
      integer      m, isign
      real (KIND=8)       gauge

* ---  Local Variables
      integer      i

      gauge = 0.0
      do i = 1, m
         gauge = gauge + real(a( i ))*real(a( i )) +
     $                   aimag(a( i ))*aimag(a( i ))
      end do
      if (isign.ge.0) gauge = gauge/(dfloat(m))
      return
      end

      subroutine dcomp_gauge( a, m, isign, gauge, a_t )
* --------------------------------------------------------------
* --  Compute Input matrix gauge  (real (KIND=8))                    --
* --------------------------------------------------------------

* --- Input Arguments
      real (KIND=8)            a(*), gauge
      integer           m, isign

* --  Local Variables
      complex (KIND=8)        a_t(*)

      if (isign .EQ. 1) then
        call dzmCopy(a, a_t, m)
      else
        call dzmCopy_exp(a, a_t, m)
      endif
      call zcomp_gauge(a_t, m, isign, gauge)

      return
      end


      subroutine scomp_gauge( a, m, isign, gauge, a_t )
* --------------------------------------------------------------
* --  Compute Input matrix gauge  (real*4)                    --
* --------------------------------------------------------------

* --- Input Arguments
      real*4            a(*)
      real (KIND=8)            gauge
      integer           m, isign

* ---  Local Variables
      complex*8         a_t(*)

      if (isign .EQ. 1) then
        call scmCopy(a, a_t, m)
      else
        call scmCopy_exp(a, a_t, m)
      endif
      call ccomp_gauge(a_t, m, isign, gauge)

      return
      end

      logical function Fsub( tst_sub, nsubs)

* --- Is there subroutines for testing?

* --- Input Arguments
      logical           tst_sub(*)
      integer           nsubs

* --- Local Variables
      integer           isub

* --- Executiable Statements

      Fsub = .FALSE.
      do isub = 1, nsubs
         Fsub = Fsub .or. tst_sub( isub )
      end do
      return
      end


      subroutine zRandm (a, m)

      complex (KIND=8)        a(*)
      integer           m, i
      double precision  RealP, ImagP
      double precision  dbeg
      external          dbeg

      do i = 1, m
         RealP = dbeg(.FALSE.)
         ImagP = dbeg(.FALSE.)
         a(i) = dcmplx (RealP, ImagP)
      end do

      return
      end

      subroutine cRandm (a, m)

      complex           a(*)
      integer           m, i
      double precision  RealP, ImagP
      double precision  dbeg
      external          dbeg

      do i = 1, m
         RealP = dbeg(.FALSE.)
         ImagP = dbeg(.FALSE.)
         a(i) = cmplx (RealP, ImagP)
      end do

      return
      end

      subroutine dRandm (a, m)

      real (KIND=8)            a(*)
      integer           m, i
      double precision  dbeg
      external          dbeg

      do i = 1, m
          a(i) = dbeg(.FALSE.)
      end do

      return
      end

      subroutine sRandm (a, m)

      real*4            a(*)
      integer           m, i
      double precision  dbeg
      external          dbeg

      do i = 1, m
         a(i) = dbeg(.FALSE.)
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
      LOGICAL           RESET
*     .. Local Scalars ..
      INTEGER           I, IC, MI
*     .. Save statement ..
      SAVE              I, IC, MI
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

      subroutine zmCopy(a, b, m)

* --- Input Arguments
      complex (KIND=8)   a(*)
      integer      m

* --- Output Arguments
      complex (KIND=8)   b(*)

* --- Local variables
      integer      i


      do i = 1, m
          b(i) = a(i)
      end do

      return
      end

      subroutine cmCopy(a, b, m)

* --- Input Arguments
      complex      a(*)
      integer      m

* --- Output Arguments
      complex      b(*)

* --- Local variables
      integer      i

      do i = 1, m
          b(i) = a(i)
      end do

      return
      end

      subroutine smCopy(a, b, m)

* --- Input Arguments
      real*4       a( *)
      integer      m

* --- Output Arguments
      real*4       b(*)

* --- Local variables
      integer      i

      do i = 1, m
          b(i) = a(i)
      end do

      return
      end

      subroutine dmCopy(a, b, m)

* --- Input Arguments
      real (KIND=8)       a(*)
      integer      m

* --- Output Arguments
      real (KIND=8)       b(*)

* --- Local variables
      integer      i

      do i = 1, m
          b(i) = a(i)
      end do

      return
      end


      subroutine zcmCopy(a, b, m)

* --- Input Arguments
      complex (KIND=8) a(*)
      integer    m

* --- Output Arguments
      complex    b(*)

* --- Local variables
      integer    i

      do i = 1, m
          b(i) = a(i)
      end do

      return
      end


      subroutine scmCopy_exp(ra, ca, m)

* --- Input Arguments
      integer      m
      real*4       ra(*)

* --- Output Arguments
      complex*8    ca(*)

* --- Local variables
      integer      i

      do i = 1, m
         ca(i) = cmplx(ra(i), float(0))
      end do

      return
      end

      subroutine dzmCopy_exp(ra, ca, m)

* --- Input Arguments
      integer      m
      real (KIND=8)       ra(*)

* --- Output Arguments
      complex (KIND=8)   ca(*)

* --- Local variables
      integer      i

      do i = 1, m
         ca(i) = dcmplx(ra(i), 0.d0)
      end do

      return
      end

      subroutine scmCopy(ra, ca, m)

* --- Input Arguments
      integer      m
      real*4       ra(*)

* --- Output Arguments
      complex*8    ca(*)

* --- Local variables
      integer      i, k

      ca(1) = cmplx(ra(1), ra(2))
      if (m .gt. 1) then
        ca(m/2+1) = cmplx(ra(m+1), ra(m+2))
      endif
      k = 3
      do i = 2, m/2
        ca(i) = cmplx(ra(k), ra(k+1))
        ca(m+2-i) = cmplx(ra(k), -ra(k+1))
        k = k+2
      end do

      return
      end

      subroutine csmCopy(ra, ca, m)

* --- Input Arguments
      integer      m
      real*4       ra(*)

* --- Output Arguments
      complex*8    ca(*)

* --- Local variables
      integer      i, k

*      ca(1) = cmplx(ra(1), float(0))
      ca(1) = cmplx(ra(1), ra(2))
      if (m .gt. 1) then
        ca(m/2+1) = cmplx(ra(m+1), ra(m+2))
*        ca(m/2+1) = cmplx(ra(m+1), float(0))
      endif
      k = 3
      do i = 2, m/2
        ca(i) = cmplx(ra(k), ra(k+1))
        ca(m+2-i) = cmplx(ra(k), -ra(k+1))
        k = k+2
      end do

      return
      end

      subroutine dzmCopy(ra, ca, m)

* --- Input Arguments
      integer      m
      real (KIND=8)       ra(*)

* --- Output Arguments
      complex (KIND=8)   ca(*)

* --- Local variables
      integer      i, k

      ca(1) = dcmplx(ra(1), ra(2))
      if (m .gt. 1) then 
        ca(m/2+1) = dcmplx(ra(m+1), ra(m+2))
      endif
      k = 3
      do i = 2, m/2
        ca(i) = dcmplx(ra(k), ra(k+1))
        ca(m+2-i) = dcmplx(ra(k), -ra(k+1))
        k = k+2
      end do

      return
      end

      subroutine zdmCopy(ra, ca, m)

* --- Input Arguments
      integer      m
      real (KIND=8)       ra(*)

* --- Output Arguments
      complex (KIND=8)   ca(*)

* --- Local variables
      integer      i, k

      ca(1) = dcmplx(ra(1), ra(2))
*      ca(1) = dcmplx(ra(1), 0.d0)
      if (m .gt. 1) then 
        ca(m/2+1) = dcmplx(ra(m+1), ra(m+2))
*       ca(m/2+1) = dcmplx(ra(m+1), 0.d0)
       endif
      k = 3
      do i = 2, m/2
        ca(i) = dcmplx(ra(k), ra(k+1))
        ca(m+2-i) = dcmplx(ra(k), -ra(k+1))
        k = k+2
      end do

      return
      end

* -----------------------------------------------------------
* --  complex*8 1D DFT                                     --
* -----------------------------------------------------------
      subroutine cexp1d (a_in, m, isign, wsave, a_out, gauge)
* --- Input Arguments
      complex           a_in(*)
      integer           m, isign

* --- Output Arguments
      complex           a_out(*), wsave(*)
      real (KIND=8)            gauge

* --- Local Variables
      integer           i, k, ia
      real              argm, accm
      complex           C
      real (KIND=8)            temp

* --- Statement funtions
      real              cabs1
* --- Statement funtions definitions
      cabs1( C ) = sqrt( real(C)*real(C) + aimag(C)*aimag(C))

      accm = float(m)
      argm = 8.0*atan(1.0)/ accm
      if (isign.le.0) then

*        --- Twiddle factors for forward transform
         do i = 1, m
            wsave( i ) = cmplx( cos( argm*(i-1) ), -sin( argm*(i-1) ) )
         end do
      else
*        --- Twiddle factors for inverse transform
         do i = 1, m
            wsave( i ) = cmplx( cos( argm*(i-1) ), sin( argm*(i-1) ) )
         end do
      end if
      do k = 1, m
         a_out( k ) = cmplx(0.0, 0.0)
         do i = 1, m
            temp = dble(i-1) * dble(k-1)
            ia = mod ( temp , dble(m)) + 1
            a_out( k ) = a_out( k ) + a_in( i ) * wsave( ia )
         end do
      end do

*     -- Compute gauge
      gauge = 0.d0
      do i = 1, m
          gauge = gauge + cabs1( a_in( i ) )*cabs1( a_in( i ) )
      end do

*     -- Normalization for inverse transform
      if (isign .gt. 0) then
         do k = 1, m
           a_out( k ) = a_out ( k )/accm
         end do
         gauge = gauge/accm
      end if
      return
      end

      subroutine zexp1d (a_in, m, isign, wsave, a_out, gauge)
* -----------------------------------------------------------
* --  complex (KIND=8) 1D DFT                                     --
* -----------------------------------------------------------
* --- Input Arguments
      complex (KIND=8)        a_in(*)
      integer           m, isign

* --- Output Arguments
      complex (KIND=8)        a_out(*), wsave(*)
      real (KIND=8)            gauge

* --- Local Variables
      integer           i, k, ia
      real (KIND=8)            argm, accm
      complex (KIND=8)        C
      real (KIND=8)            temp

* --- Statement funtions
      real (KIND=8)            cabs1
* --- Statement funtions definitions
      cabs1( C ) = dsqrt( dble(C)*dble(C) + dimag(C)*dimag(C))

* --- cexp1d start

      accm = dfloat(m)
      argm = 8.d0*datan(1.d0)/ accm
      if (isign.le.0) then

*        --- Twiddle factors for forward transform
         do i = 1, m
            wsave( i ) = dcmplx(dcos(argm*(i-1)), -dsin(argm*(i-1)))
         end do
      else

*        -- Twiddle factors for inverse transform
         do i = 1, m
            wsave( i ) = dcmplx(dcos(argm*(i-1)), dsin(argm*(i-1)))
         end do
      end if
      do k = 1, m
         a_out( k ) = dcmplx(0.d0, 0.d0)
         do i = 1, m
            temp = dble(i-1) * dble(k-1)
            ia = mod ( temp , dble(m)) + 1
            a_out( k ) = a_out( k ) + a_in( i ) * wsave( ia )
         end do
      end do

*     -- Compute gauge
      gauge = 0.d0
      do i = 1, m
         gauge = gauge + cabs1( a_in( i ) )*cabs1( a_in( i ) )
      end do

*     -- Normalization for inverse transform
      if (isign .gt. 0) then
         do k = 1, m
           a_out( k ) = a_out ( k )/accm
         end do
         gauge = gauge/accm
      end if
      return
      end

* ---------------------------------------------------------
* --                                                     --
* --     E R R O R       H A N D L I N G                 --
* --                                                     --
* ---------------------------------------------------------

      subroutine xerbla(name_func, ind_err)

      character(len=8) name_func
      integer ind_err

      integer            code_err, ich_out
      logical            lerr, ok

      character(len=8)        sub_err
      common             /exiterr/ code_err, ich_out, lerr, ok
      common             /exitname/ sub_err

      lerr = .TRUE.
      if (code_err.eq.0) then
        write( ich_out , fmt = 7703) ind_err, name_func
        write( * , fmt = 7703) ind_err, name_func
        stop
      end if
      if (ind_err.ne.code_err ) then
         if ( code_err.ne.0 ) then
            write( ich_out , fmt = 7700) ind_err, code_err
         else
            write( ich_out , fmt = 7701) ind_err
         end if
         ok = .FALSE.
      end if
      if ( name_func.ne.sub_err ) then
         write( ich_out , fmt = 7702) name_func, sub_err
         ok = .FALSE.
      end if

      return

7700  format( t6, '**** XERBLA was called with ind_code = ', i6,
     $        ' instead  of ', i2, ' ****' )
7701  format( t6,'**** XERBLA was called with ind_code = ', i6)
7702  format( t6, '**** XERBLA was called with name_func = ', a8,
     $        ' instead  of ', a8, ' ****' )
7703  format( '**** FATAL: XERBLA was called while',
     $        ' test executing with ', / 'err_code = ',
     $        i6, ' from function ', a8  )

      end

      subroutine call_func( isub, a_z, a_c, a_d, a_s,
     $                      ws_z, ws_c, m, isign )
      integer         isub
      complex (KIND=8)      a_z(*), ws_z(*)
      complex*8       a_c(*), ws_c(*)
      real (KIND=8)          a_d(*)
      real*4          a_s(*)
      integer         m, isign

      goto (10, 20, 30, 40, 50, 60) isub
 10   call zfft1d(a_z, m, isign, ws_z)
      goto 77

 20   call cfft1d(a_c, m, isign, ws_c)
      goto 77

 30   call dzfft1d(a_d, m, isign, ws_z)
      goto 77

 40   call scfft1d(a_s, m, isign, ws_c)
      goto 77

 50   call zdfft1d(a_d, m, isign, ws_z)
      goto 77

 60   call csfft1d(a_s, m, isign, ws_c)
      goto 77

77    continue
      return
      end


      LOGICAL FUNCTION mkl_aligning1( A, bound, start_val )
*
*  -- Testing auxiliary routine --
      REAL    A(*)
      INTEGER bound
      INTEGER start_val
*     ..
*
*  Purpose
*  =======
*
*  mkl_aligning returns .TRUE. if aligning (function %loc) is available
*  and set start_val to value nessesary for A(start_val) be aligned
*  on bound
*
*  Arguments
*  =========
*
*  A         (input)  REAL(*)  -  input array
*  bound     (input)  INTEGER  - aligning bound
*  start_val (output) INTEGER  - start value for aligned array
*
*  Local variables

	   INTEGER   m_adr, diff, tmp

*  Parameters
	   integer        align_max
   	   parameter      (align_max = 64)

*     .. Executable Statements ..
      mkl_aligning1 = .FALSE.

      start_val = 1

      m_adr = %loc(A)
      tmp = m_adr/align_max
      diff = align_max - (m_adr - tmp*align_max)
      if (diff .NE. 0) then
         start_val = diff/4
      endif
      start_val = start_val + bound/4

      start_val = start_val+1

      mkl_aligning1 = .TRUE.

      return

      END

      SUBROUTINE ZMKBAD( X, FATAL )
*
*  This special module contains two entry points:
*  ZMKBAD to generate positive infinity according to IEEE 754 both in
*     imaginary and in real part of a complex (KIND=8) value
*     and
*  ZFXBAD to check for INF or NaN either imaginary or real part of
*     complex (KIND=8) value
*     and if yes, convert it to a "funny" number
*     that hardly can fit the expected result
*
*  !!!ARCHITECTURE DEPENDENT!!!
*     1.Assumes floating-point numbers conform IEEE 754
*     2.Assumes INTEGER is 4 byte and DOUBLE PRECISION is 8 byte long
*       Change parameter IINDP (Integers IN a Double Precision)
*       to adjust.
*       This may also require to change HGHINF (currently 0x7ff00000)
*     3.Assumes reverse byte ordering
*       Change parameter HGHWRD to adjust
*
*  Auxiliary routine for test program for Level 3 Blas.
*
*  -- Written on 25-December-1996.
*     Dymon Shoose, Intel RSTL
*
*     .. Scalar Argument ..
      complex (KIND=8)         X
	LOGICAL            FATAL
*     .. Parameters ..
      complex (KIND=8)         FUNNY
      PARAMETER( FUNNY = ( 0.123456D-78, -0.123456D78 ) )
      INTEGER            HGHINF, IINDP, HGHWRD
      PARAMETER( HGHINF = 2146435072, IINDP = 2, HGHWRD = 2 )
*     .. Scalars in Equivalence ..
      complex (KIND=8)         W
      INTEGER            IW( IINDP, 2 )
      EQUIVALENCE( W, IW( 1, 1 ) )
*     .. Intrinsic Functions ..
      INTRINSIC          IAND
*     .. Executable Statements ..
      W = ( 0.0, 0.0)
      IW( HGHWRD, 1 ) = HGHINF
      IW( HGHWRD, 2 ) = HGHINF
      X = W
	FATAL = .FALSE.
      RETURN
      ENTRY ZFXBAD( X, FATAL )
      W = X
	FATAL = .FALSE.
      IF( ( IAND( IW( HGHWRD, 1 ), HGHINF ).EQ.HGHINF )
     $   .OR.( IAND( IW( HGHWRD, 2 ), HGHINF ).EQ.HGHINF ) ) 
     $    FATAL = .TRUE.
      RETURN
*
*     End of ZMKBAD/ZFXBAD
*
      END


      SUBROUTINE CMKBAD( X, FATAL )
*
*  This special module contains two entry points:
*  CMKBAD to generate positive infinity according to IEEE 754 both
*     in imaginary and in real part of a COMPLEX value
*     and
*  CFXBAD to check for INF or NaN either imaginary or real part
*     of COMPLEX value
*     and if yes, convert it to a "funny" number
*     that hardly can fit the expected result
*
*  !!!ARCHITECTURE DEPENDENT!!!
*     1.Assumes floating-point numbers conform IEEE 754
*     2.Assumes INTEGER is 4 byte and REAL is 4 byte long
*       (COMPLEX is 8 byte)
*       Change parameter IINR (Integers IN a Real) to adjust
*       This may also require to change HGHINF (currently 0x7f800000)
*     3.Assumes reverse byte ordering
*       Change parameter HGHWRD to adjust
*
*  Auxiliary routine for test program for Level 3 Blas.
*
*  -- Written on 25-December-1996.
*     Dymon Shoose, Intel RSTL
*
*     .. Scalar Argument ..
      COMPLEX            X
	LOGICAL            FATAL
*     .. Parameters ..
      COMPLEX            FUNNY
      PARAMETER( FUNNY = ( 0.987654E-32, -0.987654E32 ) )
      INTEGER            HGHINF, IINR, HGHWRD
      PARAMETER( HGHINF =  2139095040, IINR = 1, HGHWRD = 1 )
*     .. Scalars in Equivalence ..
      COMPLEX            W
      INTEGER            IW( IINR, 2 )
      EQUIVALENCE( W, IW( 1, 1 ) )
*     .. Intrinsic Functions ..
      INTRINSIC          IAND
*     .. Executable Statements ..
      W = ( 0.0, 0.0)
      IW( HGHWRD, 1 ) = HGHINF
      IW( HGHWRD, 2 ) = HGHINF
      X = W
	FATAL = .FALSE.
      RETURN
      ENTRY CFXBAD( X, FATAL )
      W = X
	FATAL = .FALSE.
      IF( ( IAND( IW( HGHWRD, 1 ), HGHINF ).EQ.HGHINF )
     $   .OR.( IAND( IW( HGHWRD, 2 ), HGHINF ).EQ.HGHINF ) ) 
     $    FATAL = .TRUE.
      RETURN
	END


      SUBROUTINE DMKBAD( X, FATAL )
*
*  This special module contains two entry points:
*  DMKBAD to generate DOUBLE PRECISION positive infinity according
*     to IEEE 754
*     and
*  DFXBAD to check for INF or NaN and if yes, convert it
*     to a "funny" number that hardly can fit the expected result
*
*  !!!ARCHITECTURE DEPENDENT!!!
*     1.Assumes floating-point numbers conform IEEE 754
*     2.Assumes INTEGER is 4 byte and DOUBLE PRECISION is 8 byte long
*       Change parameter IINDP (Integers IN a Double Precision)
*       to adjust.
*       This may also require to change HGHINF (currently 0x7ff00000)
*     3.Assumes reverse byte ordering
*       Change parameter HGHWRD to adjust
*
*  Auxiliary routine for test program for Level 3 Blas.
*
*  -- Written on 25-December-1996.
*     Dymon Shoose, Intel RSTL
*
*     .. Scalar Argument ..
      DOUBLE PRECISION   X
	LOGICAL            FATAL
*     .. Parameters ..
      DOUBLE PRECISION   FUNNY
      PARAMETER( FUNNY = 0.123456D-78 )
      INTEGER            HGHINF, IINDP, HGHWRD
      PARAMETER( HGHINF = 2146435072, IINDP = 2, HGHWRD = 2 )
*     .. Scalars in Equivalence ..
      DOUBLE PRECISION   W
      INTEGER            IW( IINDP )
      EQUIVALENCE( W, IW( 1 ) )
*     .. Intrinsic Functions ..
      INTRINSIC          IAND
*     .. Executable Statements ..
      W = 0.0
      IW( HGHWRD ) = HGHINF
      X = W
	FATAL = .FALSE.
      RETURN
      ENTRY DFXBAD( X, FATAL )
      FATAL = .FALSE.
	W = X
      IF( IAND( IW( HGHWRD ), HGHINF ).EQ.HGHINF ) FATAL = .TRUE.
      RETURN
*
*     End of DMKBAD/DFXBAD
*
      END

      SUBROUTINE SMKBAD( X, FATAL )
*
*  This special module contains two entry points:
*  SMKBAD to generate REAL positive infinity according to IEEE 754
*     and
*  SFXBAD to check for INF or NaN and if yes, convert it
*     to a "funny" number
*     that hardly can fit the expected result
*
*  !!!ARCHITECTURE DEPENDENT!!!
*     1.Assumes floating-point numbers conform IEEE 754
*     2.Assumes INTEGER is 4 byte and REAL is 4 byte long
*       Change parameter IINR (Integers IN a Real) to adjust
*       This may also require to change HGHINF (currently 0x7f800000)
*     3.Assumes reverse byte ordering
*       Change parameter HGHWRD to adjust
*
*  Auxiliary routine for test program for Level 3 Blas.
*
*  -- Written on 25-December-1996.
*     Dymon Shoose, Intel RSTL
*
*     .. Scalar Argument ..
      REAL               X
	LOGICAL            FATAL
*     .. Parameters ..
      REAL               FUNNY
      PARAMETER( FUNNY = 0.987654E-32 )
      INTEGER            HGHINF, IINR, HGHWRD
      PARAMETER( HGHINF =  2139095040, IINR = 1, HGHWRD = 1 )
*     .. Scalars in Equivalence ..
      REAL               W
      INTEGER            IW( IINR )
      EQUIVALENCE( W, IW( 1 ) )
*     .. Intrinsic Functions ..
      INTRINSIC          IAND
*     .. Executable Statements ..
      W = 0.0
      IW( HGHWRD ) = HGHINF
      X = W
	FATAL= .FALSE.
      RETURN
      ENTRY SFXBAD( X, FATAL )
	FATAL= .FALSE.
      W = X
      IF( IAND( IW( HGHWRD ), HGHINF ).EQ.HGHINF ) FATAL= .TRUE.
      RETURN
*
*     End of SMKBAD/SFXBAD
*
	END
	
      subroutine  zpostm ( a_tst, a_exp, ws_exp, ws_post, m, post_m, 
     $	                 sub_fatal, ich_summ, isign)
* --------------------------------------------------------------
* --  Compare memory after array  (complex (KIND=8))          --
* --------------------------------------------------------------
* --- Input Arguments
      integer           m, post_m, ich_summ, isign
      complex (KIND=8)  a_tst(*), a_exp(*), ws_exp(*), ws_post(*)

* --- Output Arguments
      logical           sub_fatal

* --- Local Variables
      integer           s, wm

*        a_exp(m+1) = 0

	do s=1, post_m
          if (a_tst(m+s) .ne. a_exp(m+s)) then
*              print *, s, a_tst(m+s), a_exp(m+s)
              print '(/a,i6,a,i2,a)', 'Error (vector lenght =', m,
     $		   ', isign = ', isign, ') : using of memory after array.'
              write(ich_summ,fmt='(/a,i6,a,i2,a)')
     $		      'Error (vector lenght =', m, ', isign = ', isign,
     $		      '): using of memory after array.'
		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do

	wm = 3 * m / 2
	do s=1, post_m
          if (ws_exp(wm+s) .ne. ws_post(s)) then
              print '(/a,i6,a,i2,a)',
     $              'Error (vector lenght =', m, ', isign = ', isign,
     $ 			  ') : using of memory after twiddle array.'
              write(ich_summ,fmt='(/a,i6,a,i2,a)')
     $		      'Error (vector lenght =', m, ', isign = ', isign,
     $		      '): using of memory after twiddle array.'
		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do
10    continue
      end

      subroutine  cpostm ( a_tst, a_exp, ws_exp, ws_post, m, post_m, 
     $	                 sub_fatal, ich_summ, isign)
* --------------------------------------------------------------
* --  Compare memory after array (complex (KIND=4))           --
* --------------------------------------------------------------
* --- Input Arguments
      integer           m, post_m, ich_summ, isign
      complex (KIND=4)  a_tst(*), a_exp(*), ws_exp(*), ws_post(*)

* --- Output Arguments
      logical           sub_fatal

* --- Local Variables
      integer           s, wm
      
	do s=1, post_m
          if (a_tst(m+s) .ne. a_exp(m+s)) then
              print '(/a,i6,a,i2,a)', 'Error (vector lenght =', m,
     $		   ', isign = ', isign, ') : using of memory after array.'
              write(ich_summ,fmt='(/a,i6,a,i2,a)')
     $		      'Error (vector lenght =', m, ', isign = ', isign,
     $		      '): using of memory after array.'
		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do

	wm = 3 * m / 2
*              print *, 'cmp', ws_exp(wm+1), ws_post(1)

	do s=1, post_m
          if (ws_exp(wm+s) .ne. ws_post(s)) then
              print '(/a,i6,a,i2,a)',
     $              'Error (vector lenght =', m, ', isign = ', isign,
     $ 			  ') : using of memory after twiddle array.'
              write(ich_summ,fmt='(/a,i6,a,i2,a)')
     $		      'Error (vector lenght =', m, ', isign = ', isign,
     $		      '): using of memory after twiddle array.'
     		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do
10    continue

      end

      subroutine  zrpostm ( a_tst, a_exp, ws_exp, ws_post, m, post_m, 
     $	                 sub_fatal, ich_summ, isign)
* --------------------------------------------------------------
* --  Compare memory after array  (complex (KIND=8))          --
* --------------------------------------------------------------
* --- Input Arguments
      integer           m, post_m, ich_summ, isign
	real*8            a_tst(*), a_exp(*)
      complex (KIND=8)  ws_exp(*), ws_post(*)

* --- Output Arguments
      logical           sub_fatal

* --- Local Variables
      integer           s, wm

*        a_exp(m+1) = 0

	do s=1, post_m
          if (a_tst(s) .ne. a_exp(s)) then
*              print *, s, a_tst(m+s), a_exp(m+s)
              print '(/a,i6,a,i2,a)', 'Error (vector lenght =', m,
     $		   ', isign = ', isign, ') : using of memory after array.'
              write(ich_summ,fmt='(/a,i6,a,i2,a)')
     $		      'Error (vector lenght =', m, ', isign = ', isign,
     $		      '): using of memory after array.'
		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do

	wm = 2 * m
	do s=1, post_m
          if (ws_exp(s) .ne. ws_post(s)) then
              print '(/a,i6,a,i2,a)',
     $              'Error (vector lenght =', m, ', isign = ', isign,
     $ 			  ') : using of memory after twiddle array.'
              write(ich_summ,fmt='(/a,i6,a,i2,a)')
     $		      'Error (vector lenght =', m, ', isign = ', isign,
     $		      '): using of memory after twiddle array.'
		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do
10    continue
      end

      subroutine  crpostm ( a_tst, a_exp, ws_exp, ws_post, m, post_m, 
     $	                 sub_fatal, ich_summ, isign)
* --------------------------------------------------------------
* --  Compare memory after array (complex (KIND=4))           --
* --------------------------------------------------------------
* --- Input Arguments
      integer           m, post_m, ich_summ, isign
      real*4            a_tst(*), a_exp(*)
	complex (KIND=4)  ws_exp(*), ws_post(*)

* --- Output Arguments
      logical           sub_fatal

* --- Local Variables
      integer           s, wm
      
	do s=1, post_m
          if (a_tst(s) .ne. a_exp(s)) then
*              print *, 'cmp', s, a_tst(s), a_exp(s), post_m

              print '(/a,i6,a,i2,a)', 'Error (vector lenght =', m,
     $		   ', isign = ', isign, ') : using of memory after array.'
              write(ich_summ,fmt='(/a,i6,a,i2,a)')
     $		      'Error (vector lenght =', m, ', isign = ', isign,
     $		      '): using of memory after array.'
		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do

	wm = 2 * m

	do s=1, post_m
          if (ws_exp(s) .ne. ws_post(s)) then
              print '(/a,i6,a,i2,a)',
     $              'Error (vector lenght =', m, ', isign = ', isign,
     $ 			  ') : using of memory after twiddle array.'
              write(ich_summ,fmt='(/a,i6,a,i2,a)')
     $		      'Error (vector lenght =', m, ', isign = ', isign,
     $		      '): using of memory after twiddle array.'
     		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do
10    continue

      end
