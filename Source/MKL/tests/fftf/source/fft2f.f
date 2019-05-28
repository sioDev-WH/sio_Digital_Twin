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
*      Fortran-style two-dimensional FFT test 
*
*  Author  : Gvozdev E., Sivolgina O.
*
*M*/


      Program fft2Dtst
* ----------------------------------------------------------------
* --                    2D FFT Testing                          --
* --                  Subroutines all types:                    --
* --                    zfft2d, cfft2d                          --
* --                    zdfft2d, dzfft2d                        --
* --                    scfft2d, csfft2d                        --
* ----------------------------------------------------------------

* ---- Parameters
      integer           nsubs, ndim, lmax, ich_in
      integer           nm_dft, nn_dft
      real*8            dzero, dhalf, done
      real              szero, shalf, sone
      parameter       ( nsubs = 6 )
      parameter       ( ndim = 21, lmax = 1024)
      parameter       ( dzero = 0.d0, dhalf = 0.5d0, done = 1.d0)
      parameter       ( szero = 0.0, shalf = 0.5, sone = 1.0 )
      parameter       ( ich_in = 5 )
      parameter       ( nm_dft = 4, nn_dft = 4 )

*     -- Information
*     parameter       ( C2d_Sample_gauge_deg = 1.d2)

*     -- Variables

*     -- Channels and files for output
      integer           ich_summ, ich_snap
      character*32      fn_summ, fn_snap

*     -- Flags, indicate sucessfull return from Initialization,
*        Error-Exit tests and
*        flag for create Snapshot file
      logical           ok_init, ok_err, atrace

      real*8            deps
      real              seps

      real*8            dtt
*     -- Flags for testing types and for subroutines
      logical           tstdft, tstcmpt, tsterr, afatal,
     $                  fatal( nsubs ),
     $                  tst_sub( nsubs ), tst_beg( nsubs ),
     $                  dft_check, self_test

*     ---         numbers of 1 dimension values for testing
      integer           nm
*     ---         numbers of 2 dimension values for testing
      integer           nn
*     ---         values on 1 dimension
      integer           m ( ndim ), m_dft(nm_dft)
*     ---         values on 2 dimension
      integer           n ( ndim ), n_dft(nn_dft)

*     --  Data for DFT testing
      logical           ok_exp

*     -- Matrices for testing
*     ---          testing matrix
      complex*16        za_tst( lmax+2, lmax+2 )
      complex           ca_tst( lmax*2+4, lmax*2+4 )
*     ---          control matrix
      complex*16        za_fexp( lmax+2, lmax+2 )
      complex           ca_fexp( lmax*2+4, lmax*2+4 )
      complex*16        za_iexp( lmax, lmax )
      complex           ca_iexp( lmax*2, lmax*2 )
*     ---          weigth save vectors
      complex*16        zws_exp( lmax*lmax )
      complex           cws_exp( 2*lmax*lmax )

      complex*16        ztmp( (lmax+2)*(lmax+2) )
      complex           ctmp( 2*(lmax+2)*(lmax+2) )

      real*8            za_tst_r( lmax+2, lmax+2 )
      real              ca_tst_r( lmax+2, lmax+2 )
      real*8            za_fexp_r( lmax+2, lmax+2 )
      real              ca_fexp_r( lmax+2, lmax+2 )
      real*8            ztmp_r( (lmax+2)*(lmax+2) )
      real              ctmp_r( 2*(lmax+2)*(lmax+2) )

      equivalence       (za_tst, ca_tst, za_tst_r, ca_tst_r)
      equivalence       (za_fexp, ca_fexp, za_fexp_r, ca_fexp_r)
      equivalence       (za_iexp, ca_iexp)
      equivalence       (zws_exp, cws_exp)
      equivalence       (ztmp, ctmp, ztmp_r, ctmp_r)

      logical           ResetRandom
      integer           isub

*     ---  names of testing subroutines
      character*8       snames( nsubs )

* --- External Functions
      real*8            dCeps
      real              sCeps
      real*8            dbeg
      logical           Fsub

      external          dCeps, sCeps, dbeg, Fsub

* --- External Subroutines
      external          Init, Headsumm

      data              snames /'ZFFT2D','CFFT2D',
     $                          'DZFFT2D','SCFFT2D',
     $                          'ZDFFT2D','CSFFT2D' /
      data              m_dft /16, 32, 64, 128/
      data              n_dft /16, 32, 64, 128/

* ---- CZ2fft start

      print *, 'fft2d'

*      call MKLStart()

*# ifdef _DLL
*      call MKLSTART()
*# endif

*     -- Job creation
      call Init(  ich_in, snames, ok_init, fn_summ, ich_summ,
     $            fn_snap, ich_snap, afatal, atrace, tstdft,
     $            tsterr, tstcmpt, tst_sub, nm, nn, m, n,
     $            dft_check, self_test, deps, seps)

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
      dtt = dbeg(ResetRandom)

*     -- Compute EPS (the machine precision).
*      deps = dCeps( done, dhalf, dzero )
*      seps = sCeps( sone, shalf, szero )


*     -- Write summary file header
      call Headsumm( ich_summ, deps, seps, afatal, atrace, 
     $               tstdft, tsterr, tstcmpt, tst_sub,
     $               snames, nm, nn, m, n, dft_check, self_test )

*     -- Open snap file
      if ( atrace ) then
         open( ich_snap, FILE = fn_snap, STATUS = 'unknown' )
         write(ich_snap, fmt = 7703 ) 'Computational test calls'
      end if

*     --   Error - Exits test
      ok_err = .TRUE.
      if (tsterr .and. Fsub( tst_sub, nsubs )) then
         write(*, fmt = 7704 ) '------- Error-Exits Test -------'
         write(ich_summ, fmt = 7704 ) '------- Error-Exits Test -------'
         do isub = 1, nsubs
            if (tst_sub( isub )) then
              call  Chffterr( ich_summ, isub, snames( isub), za_tst,
     $                        ca_tst, za_tst_r, ca_tst_r, ok_err )
              if (.not.ok_err) then
                tst_sub( isub ) = .FALSE.
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
         write(ich_summ, fmt = 7704 ) 'Testing of DFT routine.'
         ok_exp = .TRUE.

*     -- DFT Forward-Inverse test
         write(*, fmt = * ) 'ZDFT    routine testing'
         call zChexp(ich_summ,ich_snap, deps, afatal, atrace,
     $               nm_dft, nn_dft, m_dft, n_dft, ztmp,
     $               za_tst, za_fexp, za_iexp, zws_exp, ok_exp )
         if (.not.ok_exp) then
            write(*, fmt = * ) 'ZDFT:   ERROR'
            write(ich_summ, fmt = 7709)
     $      'Error: Error in Forward-Inverse complex*16 DFT-routine.',
     $          'Tests is breaked.'
             GO TO 300
         endif
         write(*, fmt = * ) 'ZDFT:   PASSED'
         write(*, fmt = * ) 'CDFT    routine testing'
         call cChexp(ich_summ,ich_snap, seps, afatal, atrace,
     $               nm_dft, nn_dft, m_dft, n_dft, ctmp,
     $               ca_tst, ca_fexp, ca_iexp, cws_exp, ok_exp )
         if (.not.ok_exp) then
            write(*, fmt = * ) 'CDFT:   ERROR'
            write(ich_summ, fmt = 7709)
     $      'Error: Error in Forward-Inverse comlex DFT-routine. ',
     $         'Tests is breaked.'
            GO TO 300
         endif
         write(*, fmt = * ) 'CDFT:   PASSED'
         write(ich_summ, fmt = 7703) 'DFT-routines passed the test'
         write(ich_summ, fmt = 7704 )'Testing of Sample FFT routine.'
         ok_exp = .TRUE.
         write(*, fmt = * ) 'ZFFT_SAMPLE routine testing'
         call zChfft_s(ich_summ,ich_snap, deps, afatal, atrace,
     $            nm_dft, nn_dft, m_dft, n_dft, ztmp,
     $            za_tst, za_fexp, za_iexp, zws_exp, ok_exp )
         if (.not.ok_exp) then
            write(*, fmt = * ) 'ZFFT_SAMPLE:   ERROR'
            write(ich_summ, fmt = 7709)
     $      'Error: Error in ZFFT_SAMPLE routine.',
     $          'Tests is breaked.'
             GO TO 300
         endif
         write(*, fmt = * ) 'ZFFT_SAMPLE:   PASSED'
         write(*, fmt = * ) 'CFFT_SAMPLE routine testing'
         call cChfft_s(ich_summ,ich_snap, seps, afatal, atrace,
     $            nm_dft, nn_dft, m_dft, n_dft, ctmp,
     $            ca_tst, ca_fexp, ca_iexp, cws_exp, ok_exp )
         if (.not.ok_exp) then
            write(*, fmt = * ) 'CFFT_SAMPLE:   ERROR'
            write(ich_summ, fmt = 7709)
     $            'Error: Error in CFFT_SAMPLE routine.',
     $            'Tests is breaked.'
             GO TO 300
         endif
         write(*, fmt = * ) 'CFFT_SAMPLE:   PASSED'
         write(ich_summ, fmt = 7703) 'FFT_SAMPLE - routines ',
     $                               'passed the test'
       endif

       do isub = 1, nsubs
          fatal( isub )   = .FALSE.
          tst_beg( isub ) = tst_sub( isub )
          if ( tst_sub ( isub ) ) write ( ich_summ , fmt = 7702)
     $                   snames( isub ), ' : Computational test '
       end do

*     -- Test on random matrices

*     -- Test in Compare with DFT result and
*     -- Forward-Inverse test
         do isub = 1, nsubs, 2
           if (tst_sub (isub))       then
             write(*, fmt = * ) snames(isub),' routine testing'
             call zChfft( ich_summ, ich_snap, snames, deps, afatal,
     $                    atrace, nm, nn, m, n, ztmp,
     $                    za_tst, za_fexp, za_iexp, zws_exp,
     $                    fatal, isub, tst_sub, dft_check,
     $                    za_tst_r, za_fexp_r)
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
           if (tst_sub (isub))       then
             write(*, fmt = * ) snames(isub),' routine testing'
             call cChfft( ich_summ, ich_snap, snames, seps,
     $                    afatal, atrace, nm, nn, m, n, ctmp,
     $                    ca_tst, ca_fexp, ca_iexp, cws_exp,
     $                    fatal, isub, tst_sub, dft_check,
     $                    ca_tst_r, ca_fexp_r)
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
         do isub = 1, nsubs
            if ( tst_beg( isub )) then
               if ( .not.fatal( isub ) ) then
                  write( ich_summ, fmt = 7708) snames( isub ),
     $                  ' : PASSED Computational test '
               else
                  write( ich_summ, fmt = 7708) snames( isub ),
     $                  ' : ERROR on Computational test '
               end if
            end if
         end do
      end if

 300  write(ich_summ, fmt = 7704)
     $          '----- End of Tests -----'
      write(*, fmt = 7704)
     $          '----- End of Tests -----'
 330  continue
      CLOSE ( ich_summ )
      CLOSE ( ich_snap )

*      call MKLEnd()

      STOP

 9985 FORMAT( /' ******* FATAL ERROR - TESTS ABANDONED *******' )
 7701 FORMAT( t2, a / t2, a )
 7702 FORMAT( t6, a, a )
 7703 FORMAT(  t6, a /)
 7704 FORMAT( / t6, a /)
 7705 FORMAT(  t2, a, a, a)
 7708 FORMAT( / t6, a, a )
 7709 FORMAT( t2, a )

*     End of cfft.
      end

      subroutine zChfft( ich_summ, ich_snap, snames, eps,
     $                   afatal, atrace, nm, nn, m, n, a_tmp,
     $                   a_tst, a_fexp, a_iexp, ws_exp,
     $                   fatal, isub, tst_sub, dft_check, 
     $                   a_tst_r, a_fexp_r)
* ---------------------------------------------------------------------
* -- Testing on random vectores - Forward-Inverse transform,         --
* -- Forward, Inverse transform in compare with DFT result           --
* ---------------------------------------------------------------------
* --- Parameters
      integer           nsubs
      parameter       ( nsubs = 6 )
      integer           lmax
      parameter       ( lmax = 1024 )

* --- Input Arguments
      integer           ich_summ, ich_snap, isub
      real*8            eps
      logical           afatal, atrace, dft_check

      integer           nm, nn, m(*), n(*)
      complex*16        a_tmp( lmax, lmax )
      complex*16        a_tst( lmax, lmax )
      complex*16        a_fexp( lmax, lmax )
      complex*16        a_iexp( lmax, lmax )
      complex*16        ws_exp( lmax*2 )
      real*8            a_tst_r( lmax+2, * )
      real*8            a_fexp_r( lmax+2, * )

      character*8       snames(*)

      logical           tst_sub(*)

* --- Output Arguments
      logical           fatal(*)

* ---  Local Variables
      logical           sub_fatal( nsubs )
      integer           im, in, isign
      real*8            gauge

* --- External subroutines
      external          zFItest,  zCmpretest

* --- Executable Statements

      do im = 1, nm
       do in = 1, nn

         if (m(im)*n(in) .le. lmax*lmax) then

            if (isub.EQ.3 .OR. isub.EQ.5) then

              call zrCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m(im), n(in), a_tmp,
     $                  a_tst_r, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

            else

*          -- Forward test
              isign = -1
              call zCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m(im), n(in), a_tmp,
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

*          -- Inverse test
              isign = 1
              call zCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m(im), n(in), a_tmp,
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

*          -- Forward-Inverse test
              call  zFItest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m(im), n(in), 
     $                  a_tst, a_fexp,
     $                  gauge, sub_fatal, isub )

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300
              
              if (.NOT.dft_check) then
*                 -- Forward test
                  isign = -2
                  call zCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                              snames, isign, m(im), n(in), a_tmp,
     $                              a_tst, a_fexp, a_iexp, ws_exp,
     $                              gauge, sub_fatal, afatal, isub,
     $                              dft_check)

                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300

*                 -- Inverse test
                  isign = 2
                  call zCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                              snames, isign, m(im), n(in), a_tmp,
     $                              a_tst, a_fexp, a_iexp, ws_exp,
     $                              gauge, sub_fatal, afatal, isub,
     $                              dft_check)

                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300

*                 -- Forward-Inverse test +-2
                  call  zFItest_2 ( ich_summ, ich_snap, eps, atrace,
     $                              snames, m(im), n(in), 
     $                              a_tst, a_fexp,
     $                              gauge, sub_fatal, isub )

                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300

              endif
            endif

            if ((isub.EQ.3 .AND. tst_sub(5))) then
*          -- Forward-Inverse test
              call  zrFItest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m(im), n(in), a_tmp,
     $                  a_tst_r, a_fexp_r,
     $                  gauge, sub_fatal, isub )

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300
            endif
         else
            write(*,fmt = *)' Matrix ',m(im), 'X', n(in),
     $                    'is too large, SKIPPED'
         endif

       enddo
      end do

 300  return

      end

      subroutine cChfft( ich_summ, ich_snap, snames,
     $                   eps, afatal, atrace,
     $                   nm, nn, m, n, a_tmp,
     $                   a_tst, a_fexp, a_iexp, ws_exp,
     $                   fatal, isub, tst_sub, dft_check,
     $                   a_tst_r, a_fexp_r)
* ---------------------------------------------------------------------
* -- Testing on random vectores - Forward-Inverse transform,         --
* -- Forward, Inverse transform in compare with DFT result           --
* ---------------------------------------------------------------------
* --- Parameters
      integer            nsubs, lmax
      parameter          ( nsubs = 6, lmax = 1024 )

* --- Input Arguments
      integer          ich_summ, ich_snap, isub
      real             eps
      logical          afatal, atrace, dft_check

      integer          nm, nn, m(*), n(*)
      complex          a_tmp( lmax, * )
      complex          a_tst( lmax, * )
      complex          a_fexp( lmax, * )
      complex          a_iexp( lmax, * )
      complex          ws_exp( lmax*2 )
      real             a_tst_r( lmax+2, * )
      real             a_fexp_r( lmax+2, * )

      character*8      snames(*)

      logical          tst_sub(*)

* --- Output Arguments
      logical         fatal(*)

* ---  Local Variables
      logical     sub_fatal( nsubs )
      integer     im, in, isign
      real        gauge
c      real        sgauge

* --- External subroutines
      external    cFItest,  cCmpretest

* --- Executable Statements

      do im = 1, nm
       do in = 1, nn

         if (m(im)*n(in) .le. lmax*lmax) then

            if (isub.EQ.4 .OR. isub.EQ.6) then
              call crCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m(im), n(in), a_tmp,
     $                  a_tst_r, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check )

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

            else

*          -- Forward test
              isign = -1
              call cCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m(im), n(in), a_tmp,
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

*          -- Inverse test
              isign = 1
              call cCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m(im), n(in), a_tmp,
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

*          -- Forward-Inverse test
              call  cFItest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m(im), n(in), 
     $                  a_tst, a_fexp,
     $                  gauge, sub_fatal, isub )

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300

              if (.NOT.dft_check) then 
*                 -- Forward test
                  isign = -2
                  call cCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m(im), n(in), a_tmp,
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)

                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300

*                 -- Inverse test
                  isign = 2
                  call cCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m(im), n(in), a_tmp,
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)

                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300

*                 -- Forward-Inverse test +-2
                  call  cFItest_2( ich_summ, ich_snap, eps, atrace,
     $                             snames, m(im), n(in), 
     $                             a_tst, a_fexp,
     $                             gauge, sub_fatal, isub )

                  fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
                  if (fatal(isub).and.afatal) goto 300

              endif
            endif

            if ((isub.EQ.4 .AND. tst_sub(6))) then
*          -- Forward-Inverse test
              call  crFItest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m(im), n(in), a_tmp,
     $                  a_tst_r, a_fexp_r,
     $                  gauge, sub_fatal, isub )

              fatal ( isub ) = sub_fatal( isub ) .or. fatal( isub )
              if (fatal(isub).and.afatal) goto 300
            endif
         else
            write(*,fmt = *)' Matrix ',m(im), 'X', n(in),
     $                    'is too large, SKIPPED'
         endif
       enddo
      end do
 300  return
      end


      subroutine  zCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m, n, a_tmp,
     $                  a_tst, a_exp_in, a_exp_out, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)
* ----------------------------------------------------------------------
* -- Testing in compare with DFT (complex*16)                         --
* ----------------------------------------------------------------------
* --- Parameters
      real*8           zero, one
      parameter        (zero = 0.d0, one = 1.d0 )
      integer          lmax
      parameter        (lmax = 1024 )

* --- Input Arguments
      integer          ich_summ, ich_snap, isign, isub
      real*8           eps
      logical          atrace, afatal, dft_check
      integer          m, n
      complex*16       a_tmp( * )
      complex*16       a_tst( m, * )
      complex*16       a_exp_in( m, * )
      complex*16       a_exp_out( m, * )
      complex*16       ws_exp( * )
      character*8      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real*8           gauge,gauges

* --- Local Variables
      logical          gauge_fatal
      integer          lda, post_m
      integer          isign_gauge
      real*8           gausub


* --- External subroutines
      external         zexp2d, zfft2d, zmCopy

* --- Executable Statements

      post_m = m
	if (post_m > ((lmax+2)*(lmax+2)-m*n)) then
	    post_m = (lmax+2)*(lmax+2)-m*n
	end if
      lda = m

*     -- Initialize vector for testing
      call zRandm(a_tst, m, n)
      call zRandm(a_tst(1,n+1), post_m, 1)

      call zmCopy(a_tst, a_exp_in, m, n)
      call zmCopy(a_tst(1,n+1), a_exp_in(1,n+1), post_m, 1)
      
      if (dft_check) then
        call zexp2d(a_exp_in, lda, m, n, isign, ws_exp, a_exp_out,
     $            lda, gauge, a_tmp)
      else
        call zfft2d_s(a_exp_in, m, n, isign, ws_exp, a_exp_out)
        call zmCopy(a_exp_in, a_exp_out, m, n)
      endif
      
      sub_fatal( isub ) = .FALSE.
      gauge_fatal = .FALSE.
      
      if (isign.le.-1) then
          isign_gauge = -1
      else
          isign_gauge = 1
      endif
      
      call zcomp_gauge (a_tst, lda, m, n, isign_gauge, gauges)
      call zfft2d( a_tst, m, n, isign)
      
      if (isign.le.-1) then
          isign_gauge = 1
      else
          isign_gauge = -1
      endif
      
      call zcomp_gauge (a_tst, lda, m, n, isign_gauge, gauge)
      
      gausub = (dabs(gauges-gauge) ) / (eps*10.0)
      if ( gauge .ne. zero ) gausub = gausub/(gauge)
      if (gausub .ge. one) then
         if (isign.le.-1) then
            write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                     ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                  gauge,gauges
         else
            write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                  ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                    gauge,gauges
         endif
         write(ich_summ, fmt = 7700) snames( isub ), ' : ERROR'
         sub_fatal( isub ) = .TRUE.
         gauge_fatal = .TRUE.
         if (afatal) goto 90
      endif
      
      call zEst( ich_summ, ich_snap, eps, atrace, m, n, a_tst,
     $           a_exp_out, gauge, sub_fatal( isub ),
     $           snames(isub), isign )
      if (afatal) GO TO 90

  90  continue
      if (gauge_fatal) sub_fatal(isub) = .TRUE.

      call  z2postm ( a_tst, a_exp_in, m, n, post_m,  
     $	                 sub_fatal(isub), ich_summ, isign)
      return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, i5, a, i6, a, i6, a)

      end

      subroutine  cCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, isign, m, n, a_tmp,
     $                  a_tst, a_exp_in, a_exp_out, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)
* ----------------------------------------------------------------------
* -- Testing in compare with DFT (complex*16)                         --
* ----------------------------------------------------------------------
* --- Parameters
      real              zero, one
      parameter       ( zero = 0.e0, one = 1.e0 )
      integer          lmax
      parameter        (lmax = 1024 )

* --- Input Arguments
      integer           ich_summ, ich_snap, isign, isub
      real              eps
      logical           atrace, afatal, dft_check
      integer           m, n
      complex           a_tmp( * )
      complex           a_tst( m, * )
      complex           a_exp_in( m, * )
      complex           a_exp_out( m, * )
      complex           ws_exp( * )
      character*8       snames(*)

* --- Output Arguments
      logical           sub_fatal(*)
      real              gauge,gauges

* --- Local Variables
      logical           gauge_fatal
      integer           lda, post_m
      integer           isign_gauge
      real              gausub


* --- External subroutines
      external          cexp2d, cfft2d, cmCopy

* --- Executable Statements

      post_m = m
	if (post_m > ((lmax+2)*(lmax+2)-m*n)) then
	    post_m = (lmax+2)*(lmax+2)-m*n
	end if
      lda = m
*     -- Initialize vector for testing
      call cRandm(a_tst, m, n)
      call cmCopy(a_tst, a_exp_in, m, n)
      call cRandm(a_tst(1,n+1), post_m, 1)
      call cmCopy(a_tst(1,n+1), a_exp_in(1,n+1), post_m, 1)

      if (dft_check) then
        call cexp2d(a_exp_in, lda, m, n, isign, ws_exp, a_exp_out,
     $            lda, gauge, a_tmp)
      else
        call cfft2d_s(a_exp_in, m, n, isign, ws_exp, a_exp_out)
        call cmCopy(a_exp_in, a_exp_out, m, n)
      endif

      sub_fatal( isub ) = .FALSE.
      gauge_fatal = .FALSE.

         if (isign.le.-1) then
            isign_gauge = -1
         else
            isign_gauge = 1
         endif

         call ccomp_gauge (a_tst, lda, m, n, isign_gauge, gauges)

         call cfft2d( a_tst, m, n, isign)

         if (isign.le.-1) then
            isign_gauge = 1
         else
            isign_gauge = -1
         endif

         call ccomp_gauge (a_tst, lda, m, n, isign_gauge, gauge)


         gausub = (abs(gauges-gauge) ) / eps
         if ( gauge .ne. zero ) gausub = gausub/(gauge)
            if (gausub .ge. one) then
               if (isign.le.-1) then
                  write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                     ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                  gauge,gauges
               else
                   write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                     ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                  gauge,gauges
               endif
                write(ich_summ, fmt = 7700)
     $                  snames( isub ), ' : ERROR'
               sub_fatal( isub ) = .TRUE.
               gauge_fatal = .TRUE.
               if (afatal) goto 90
            endif

            call cEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                 a_tst, a_exp_out, gauge, sub_fatal( isub ),
     $                 snames(isub), isign )
c            if ( sub_fatal(isub) ) write(ich_summ, fmt = 7700)
c     $                  snames( isub ), ' : ERROR'
            if (afatal) GO TO 90

  90  continue
      if (gauge_fatal) sub_fatal(isub) = .TRUE.

      call c2postm ( a_tst, a_exp_in, m, n, post_m, 
     $	                 sub_fatal(isub), ich_summ, isign)
      return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, i5, a, i6, a, i6, a)

      end


      subroutine  zFItest ( ich_summ, ich_snap, eps, atrace,
     $                      snames, m, n, 
     $                      a_tst, a_exp, gauge, sub_fatal, isub )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex*16)        --
* -----------------------------------------------------------
      integer          lmax
      parameter        (lmax = 1024 )
* --- Input Arguments
      integer          ich_summ, ich_snap, m, n, isub
      real*8           eps
      logical          atrace
      complex*16       a_tst(m, *), a_exp(m, *)
      character*8      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real*8           gauge

* --- Local Variables
      integer          lda, post_m
      integer          isign

* --- External subroutines
      external         zfft2d, zmCopy,
     $                 zcomp_gauge, zEst

* --- Executable Statements

      post_m = m
	if (post_m > ((lmax+2)*(lmax+2)-m*n)) then
	    post_m = (lmax+2)*(lmax+2)-m*n
	end if
         lda = m

         call zRandm(a_tst, m, n)
         call zmCopy(a_tst, a_exp, m, n)
         call zRandm(a_tst(1,n+1), post_m, 1)
         call zmCopy(a_tst(1,n+1), a_exp(1,n+1), post_m, 1)

         sub_fatal( isub ) = .FALSE.


               isign = -1
               call zcomp_gauge (a_tst, lda, m, n, isign, gauge)

               call zfft2d( a_tst, m, n, isign)

               isign = 1

               call zfft2d( a_tst, m, n, isign)

               call zEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                 a_tst, a_exp, gauge, sub_fatal( isub ),
     $                 snames(isub), 0 )
c               if ( sub_fatal(isub) ) write(ich_summ, fmt = 7700)
c     $                  snames( isub ), ' : ERROR'

  100    continue
         call z2postm ( a_tst, a_exp, m, n, post_m, 
     $	                 sub_fatal(isub), ich_summ, isign)
         return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end

      subroutine  cFItest ( ich_summ, ich_snap, eps, atrace,
     $                      snames, m, n, 
     $                      a_tst, a_exp, gauge, sub_fatal, isub )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex*16)        --
* -----------------------------------------------------------
      integer          lmax
      parameter        (lmax = 1024 )
* --- Input Arguments
      integer          ich_summ, ich_snap, m, n, isub
      real             eps
      logical          atrace
      complex          a_tst(m, *), a_exp(m, *)
      character*8      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real             gauge

* --- Local Variables
      integer          lda, post_m
      integer          isign

* --- External subroutines
      external         cfft2d, cmCopy,
     $                 ccomp_gauge, cEst

* --- Executable Statements

      post_m = m
	if (post_m > ((lmax+2)*(lmax+2)-m*n)) then
	    post_m = (lmax+2)*(lmax+2)-m*n
	end if
         lda = m

         call cRandm(a_tst, m, n)
         call cmCopy(a_tst, a_exp, m, n)
         call cRandm(a_tst(1,n+1), post_m, 1)
         call cmCopy(a_tst(1,n+1), a_exp(1,n+1), post_m, 1)
         sub_fatal( isub ) = .FALSE.

               isign = -1
               call ccomp_gauge (a_tst, lda, m, n, isign, gauge)

               call cfft2d( a_tst, m, n, isign)

               isign = 1

               call cfft2d( a_tst, m, n, isign)

               call cEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                 a_tst, a_exp, gauge, sub_fatal( isub ),
     $                 snames(isub), 0 )
c              if ( sub_fatal(isub) ) write(ich_summ, fmt = 7700)
c    $                  snames( isub ), ' : ERROR'

  100    continue
         call c2postm ( a_tst, a_exp, m, n, post_m, 
     $	                 sub_fatal(isub), ich_summ, isign)
         return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end


      subroutine  zFItest_2 ( ich_summ, ich_snap, eps, atrace,
     $                        snames, m, n, 
     $                        a_tst, a_exp, gauge, sub_fatal, isub )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex*16)        --
* -----------------------------------------------------------
      integer          lmax
      parameter        (lmax = 1024 )
* --- Input Arguments
      integer          ich_summ, ich_snap, m, n, isub
      real*8           eps
      logical          atrace
      complex*16       a_tst(m, *), a_exp(m, *)
      character*8      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real*8           gauge

* --- Local Variables
      integer          lda, post_m
      integer          isign

* --- External subroutines
      external         zfft2d, zmCopy,
     $                 zcomp_gauge, zEst

* --- Executable Statements

      post_m = m
	if (post_m > ((lmax+2)*(lmax+2)-m*n)) then
	    post_m = (lmax+2)*(lmax+2)-m*n
	end if
         lda = m

         call zRandm(a_tst, m, n)
         call zmCopy(a_tst, a_exp, m, n)
         call zRandm(a_tst(1,n+1), post_m, 1)
         call zmCopy(a_tst(1,n+1), a_exp(1,n+1), post_m, 1)

         sub_fatal( isub ) = .FALSE.


               isign = -1
               call zcomp_gauge (a_tst, lda, m, n, isign, gauge)

               isign = -2
               call zfft2d( a_tst, m, n, isign)

               isign = 2

               call zfft2d( a_tst, m, n, isign)

               call zEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                 a_tst, a_exp, gauge, sub_fatal( isub ),
     $                 snames(isub), 22 )
c               if ( sub_fatal(isub) ) write(ich_summ, fmt = 7700)
c     $                  snames( isub ), ' : ERROR'

  100    continue
         call z2postm ( a_tst, a_exp, m, n, post_m, 
     $	                 sub_fatal(isub), ich_summ, isign)
         return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end

      subroutine  cFItest_2 ( ich_summ, ich_snap, eps, atrace,
     $                        snames, m, n, 
     $                        a_tst, a_exp, gauge, sub_fatal, isub )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex*16)        --
* -----------------------------------------------------------
      integer          lmax
      parameter        (lmax = 1024 )
* --- Input Arguments
      integer          ich_summ, ich_snap, m, n, isub
      real             eps
      logical          atrace
      complex          a_tst(m, *), a_exp(m, *)
      character*8      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real             gauge

* --- Local Variables
      integer          lda, post_m
      integer          isign

* --- External subroutines
      external         cfft2d, cmCopy,
     $                 ccomp_gauge, cEst

* --- Executable Statements

      post_m = m
	if (post_m > ((lmax+2)*(lmax+2)-m*n)) then
	    post_m = (lmax+2)*(lmax+2)-m*n
	end if
         lda = m

         call cRandm(a_tst, m, n)
         call cmCopy(a_tst, a_exp, m, n)
         call cRandm(a_tst(1,n+1), post_m, 1)
         call cmCopy(a_tst(1,n+1), a_exp(1,n+1), post_m, 1)
         sub_fatal( isub ) = .FALSE.

               isign = -1
               call ccomp_gauge (a_tst, lda, m, n, isign, gauge)

               isign = -2
               call cfft2d( a_tst, m, n, isign)

               isign = 2

               call cfft2d( a_tst, m, n, isign)

               call cEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                 a_tst, a_exp, gauge, sub_fatal( isub ),
     $                 snames(isub), 22 )
c              if ( sub_fatal(isub) ) write(ich_summ, fmt = 7700)
c    $                  snames( isub ), ' : ERROR'

  100    continue
         call c2postm ( a_tst, a_exp, m, n, post_m, 
     $	                 sub_fatal(isub), ich_summ, isign)
         return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end


      subroutine  zexpFItest ( ich_summ, ich_snap, eps, atrace,
     $                      m, n, a_tmp,
     $                      a_tst, a_fexp, a_iexp, ws_exp, fatal )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex*16)        --
* -----------------------------------------------------------
* --- Input Arguments
      integer          ich_summ, ich_snap, m, n
      real*8           eps
      logical          atrace
      complex*16       a_tmp(m, *)
      complex*16       a_tst(m, *)
      complex*16       a_fexp(m, *), a_iexp(m, *), ws_exp(*)

* --- Output Arguments
      logical          fatal

* --- Local Variables
      integer          lda
      integer          isign
        real*8           gauge
* --- External subroutines
      external         zexp2d, zmCopy,
     $                 zcomp_gauge, zEst

* --- Executable Statements

         lda = m
         fatal = .FALSE.
         call zRandm(a_tst, m, n)
         call zmCopy(a_tst, a_fexp, m, n)

               isign = -1
               call zcomp_gauge (a_fexp, lda, m, n, isign, gauge)

               call zexp2d(a_fexp, lda, m, n, isign, ws_exp,
     $                     a_iexp, lda, gauge, a_tmp)

               isign = 1

               call zexp2d(a_iexp, lda, m, n, isign, ws_exp,
     $                     a_tst, lda, gauge, a_tmp)

               call zEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                a_tst, a_fexp, gauge, fatal,
     $                'ZDFT    ', 0 )

  100    continue
         return

 7700 FORMAT( t2, a / )
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end

      subroutine  cexpFItest ( ich_summ, ich_snap, eps, atrace,
     $                      m, n, a_tmp,
     $                      a_tst, a_fexp, a_iexp, ws_exp, fatal )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex*16)        --
* -----------------------------------------------------------
* --- Input Arguments
      integer          ich_summ, ich_snap, m, n
      real             eps
      logical          atrace
      complex          a_tmp(m, *)
      complex          a_tst(m, *)
      complex          a_fexp(m, *), a_iexp(m, *), ws_exp(*)

* --- Output Arguments
      logical          fatal

* --- Local Variables
      integer          lda
      integer          isign
      real             gauge
* --- External subroutines
      external         cexp2d,
     $                 ccomp_gauge, cEst

* --- Executable Statements

         lda = m
         fatal = .FALSE.
         call cRandm(a_tst, m, n)
         call cmCopy(a_tst, a_fexp, m, n)

               isign = -1
               call ccomp_gauge (a_fexp, m, m, n, isign, gauge)

               call cexp2d(a_fexp, lda, m, n, isign, ws_exp,
     $                     a_iexp, lda, gauge, a_tmp)

               isign = 1

               call cexp2d(a_iexp, lda, m, n, isign, ws_exp,
     $                     a_tst, lda, gauge, a_tmp)

               call cEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                    a_tst, a_fexp, gauge, fatal,'CDFT    ', 0)

  100    continue
         return

 7700 FORMAT( t2, a / )
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end


      subroutine zChexp( ich_summ, ich_snap, eps, afatal, atrace,
     $                   nm, nn, m, n, a_tmp,
     $                   a_tst, a_fexp, a_iexp, ws_exp, ok)
* ---------------------------------------------------------------------
* -- Testing DFT on random vectores - Forward-Inverse transform,         --
* ---------------------------------------------------------------------
* --- Parameters
      integer           lmax
      parameter       ( lmax = 1024 )

* --- Input Arguments
      integer           ich_summ, ich_snap
      real*8            eps
      logical           afatal, atrace

      integer           nm, nn, m(*), n(*)
      complex*16        a_tmp( lmax, * )
      complex*16        a_tst( lmax, * )
      complex*16        a_fexp( lmax, * )
      complex*16        a_iexp( lmax, * )
      complex*16        ws_exp( lmax*2 )

* --- Output Arguments
      logical           ok

* ---  Local Variables
      integer           im, in
      logical           fatal

* --- External subroutines
      external          zexpFItest

* --- Executable Statements

      ok = .TRUE.
      do im = 1, nm
       do in = 1, nn

         if (m(im)*n(in) .le. lmax*lmax) then

*        -- Forward-Inverse test
            call  zexpFItest ( ich_summ, ich_snap, eps, atrace,
     $                  m(im), n(in), a_tmp,
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  fatal )

            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300

         else
            write(*,fmt = *)' ZDFT: Matrix ',m(im), 'X', n(in),
     $                    'is too large, SKIPPED'
         endif

       enddo
      end do

 300  return

      end

      subroutine cChexp( ich_summ, ich_snap,
     $                   eps, afatal, atrace,
     $                   nm, nn, m, n, a_tmp,
     $                   a_tst, a_fexp, a_iexp, ws_exp,
     $                   ok)
* ---------------------------------------------------------------------
* -- Testing DFT on random vectores - Forward-Inverse transform,         --
* ---------------------------------------------------------------------
* --- Parameters
      integer           lmax
      parameter       ( lmax = 1024 )

* --- Input Arguments
      integer           ich_summ, ich_snap
      real              eps
      logical           afatal, atrace

      integer           nm, nn, m(*), n(*)
      complex           a_tmp( lmax, * )
      complex           a_tst( lmax, * )
      complex           a_fexp( lmax, * )
      complex           a_iexp( lmax, * )
      complex           ws_exp( * )

* --- Output Arguments
      logical           ok

* ---  Local Variables
      integer           im, in
      logical           fatal

* --- External subroutines
      external          cexpFItest

* --- Executable Statements

      ok = .TRUE.
      do im = 1, nm
       do in = 1, nn

         if (m(im)*n(in) .le. lmax*lmax) then

*        -- Forward-Inverse test
            call  cexpFItest ( ich_summ, ich_snap, eps, atrace,
     $                  m(im), n(in), a_tmp,
     $                  a_tst, a_fexp, a_iexp, ws_exp,
     $                  fatal )

            if (fatal) ok = .FALSE.
            if (fatal.and.afatal) goto 300

         else
            write(*,fmt = *)' CDFT: Matrix ',m(im), 'X', n(in),
     $                    'is too large, SKIPPED'
         endif

       enddo
      end do

 300  return

      end

      subroutine zChfft_s( ich_summ, ich_snap, eps, afatal, atrace,
     $                   nm, nn, ma, na, a_tmp,
     $                   a_tst, a_fexp, a_iexp, ws_exp, ok)
* ---------------------------------------------------------------------
* -- Testing sample FFT on random vectores                           --
* ---------------------------------------------------------------------
* --- Parameters
      integer           lmax
      parameter       ( lmax = 1024 )
      real*8            zero, one
      parameter       ( zero = 0.d0, one = 1.d0)

* --- Input Arguments
      integer           ich_summ, ich_snap
      real*8            eps, gauge, gauges, gausub
      logical           afatal, atrace

      integer           nm, nn, ma(*), na(*)
      complex*16        a_tmp( lmax, * )
      complex*16        a_tst( lmax, * )
      complex*16        a_fexp( lmax, * )
      complex*16        a_iexp( lmax, * )
      complex*16        ws_exp( * )

* --- Output Arguments
      logical           ok

* ---  Local Variables
      integer           im, in, lda, isign, m, n
      logical           fatal, gauge_fatal, g_fatal

* --- Executable Statements

      ok = .TRUE.
      g_fatal = .FALSE.

      do im = 1, nm
       do in = 1, nn
         if (ma(im)*na(in) .le. lmax*lmax) then
           m = ma(im)
           n = na(in)

           lda = m

           isign = -1
*          -- Initialize vector for testing
           call zRandm(a_tst, m, n)
           call zmCopy(a_tst, a_fexp, m, n)

           call zcomp_gauge (a_tst, lda, m, n, isign, gauges)

           call zfft2d_s( a_tst, m, n, isign, ws_exp, a_iexp)

           call zexp2d(a_fexp, lda, m, n, isign, ws_exp, a_iexp,
     $            lda, gauge, a_tmp)


           if (isign.eq.-1) then
             isign = 1
           else
             isign = -1
           endif

           call zcomp_gauge (a_tst, lda, m, n, isign, gauge)

           if (isign.eq.-1) then
             isign = 1
           else
             isign = -1
           endif

           fatal  = .FALSE.
           gauge_fatal = .FALSE.

           gausub = (dabs(gauges-gauge) ) / eps
           if ( gauge .ne. zero ) gausub = gausub/(gauge)
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
             write(ich_summ, fmt = 7700)
     $             'zfft2d_s', ' : ERROR'
             fatal = .TRUE.
             gauge_fatal = .TRUE.
             g_fatal = .TRUE.
             if (afatal) goto 90
           endif

           call zEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                a_tst, a_iexp, gauge, fatal,
     $                'zfft2d_s', isign )


           g_fatal = g_fatal .OR. fatal
           if (afatal) GO TO 90

         else
            write(*,fmt = *)' ZFFT_S: Matrix ',ma(im), 'X', na(in),
     $                    'is too large, SKIPPED'
         endif

       enddo
      end do

  90  continue
      if (g_fatal) ok = .FALSE.

      return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, i5, a, i6, a, i6, a)

      end


      subroutine cChfft_s( ich_summ, ich_snap, eps, afatal, atrace,
     $                   nm, nn, ma, na, a_tmp,
     $                   a_tst, a_fexp, a_iexp, ws_exp, ok)
* ---------------------------------------------------------------------
* -- Testing sample FFT on random vectores                           --
* ---------------------------------------------------------------------
* --- Parameters
      integer           lmax
      parameter       ( lmax = 1024 )
      real*4            zero, one
      parameter       ( zero = 0.e0, one = 1.e0)

* --- Input Arguments
      integer           ich_summ, ich_snap
      real*4            eps, gauge, gauges, gausub
      logical           afatal, atrace

      integer           nm, nn, ma(*), na(*)
      complex           a_tmp( lmax, * )
      complex           a_tst( lmax, * )
      complex           a_fexp( lmax, * )
      complex           a_iexp( lmax, * )
      complex           ws_exp( * )

* --- Output Arguments
      logical           ok

* ---  Local Variables
      integer           im, in, lda, isign, m, n
      logical           fatal, gauge_fatal, g_fatal

* --- Executable Statements

      ok = .TRUE.
      g_fatal = .FALSE.

      do im = 1, nm
       do in = 1, nn
         if (ma(im)*na(in) .le. lmax*lmax) then
           m = ma(im)
           n = na(in)

           lda = m

           isign = -1
*          -- Initialize vector for testing
           call cRandm(a_tst, m, n)
           call cmCopy(a_tst, a_fexp, m, n)

           call ccomp_gauge (a_tst, lda, m, n, isign, gauges)

           call cfft2d_s( a_tst, m, n, isign, ws_exp, a_iexp)

           call cexp2d(a_fexp, lda, m, n, isign, ws_exp, a_iexp,
     $            lda, gauge, a_tmp)


           if (isign.eq.-1) then
             isign = 1
           else
             isign = -1
           endif

           call ccomp_gauge (a_tst, lda, m, n, isign, gauge)

           if (isign.eq.-1) then
             isign = 1
           else
             isign = -1
           endif

           fatal  = .FALSE.
           gauge_fatal = .FALSE.

           gausub = (abs(gauges-gauge) ) / (eps*100.0)
           if ( gauge .ne. zero ) gausub = gausub/(gauge)
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
             write(ich_summ, fmt = 7700)
     $             'cfft2d_s', ' : ERROR'
             fatal = .TRUE.
             gauge_fatal = .TRUE.
             g_fatal = .TRUE.
             if (afatal) goto 90
           endif

           call cEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                a_tst, a_iexp, gauge, fatal,
     $                'cfft2d_s', isign )
           gauge_fatal = gauge_fatal .OR. fatal
           g_fatal = g_fatal .OR. fatal
           if (afatal) GO TO 90

         else
            write(*,fmt = *)' CFFT_S: Matrix ',ma(im), 'X', na(in),
     $                    'is too large, SKIPPED'
         endif

       enddo
      end do

  90  continue
      if (g_fatal) ok = .FALSE.
      return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, i5, a, i6, a, i6, a)

      end

* ----------------------------------------------------------------
* --                   Input Job for testing                    --
* ----------------------------------------------------------------

      subroutine Init ( ich_in, snames, ok, fn_summ, ich_summ,
     $                  fn_snap, ich_snap, afatal, atrace, tstdft,
     $                  tsterr, tstcmpt, tst_sub, nm, nn, m, n,
     $                  dft_check, self_test, deps, seps )

* ---     Job creation for 2D Fast Fouire Transform Testing
* ---     for subroutines of C/Z types.

*  -- Do:
*            Read information from standard input,
*            verifying this information,
*            job creation.
*            Variable ok = .TRUE. mean sucessful job creation.
*            Variable ok = .FALSE. mean that job is not created.

* --- Parameters
      integer            nsubs
      parameter          ( nsubs = 6 )
      integer            ndim
      parameter          ( ndim = 21 )

* --- Input Arguments
      integer            ich_in

*     -- Names of testing subroutines
      character*8        snames( nsubs )

* --- Output Arguments
      logical            ok

*     -- Channels and files for output
      integer            ich_summ, ich_snap
      character*32       fn_summ, fn_snap

      logical            atrace, afatal, tstdft,
     $                   tstcmpt, tsterr,
     $                   tst_sub( nsubs ),
     $                   dft_check, self_test

*     ---         numbers of 1 dimension values for testing
      integer       nm
*     ---         numbers of 2 dimension values for testing
      integer       nn
*     ---         values on 1 dimension
      integer       m ( ndim )
*     ---         values on 2 dimension
      integer       n ( ndim )

      real*8        deps
      real          seps

* --- Local Variables
      logical          ok_iff
      integer          isub
      character*8      name_sub
      logical          ltest

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

*     -- Read numbers of values of dimensions, values
*     --    and verify it.
      call Iff( ich_in, ok_iff, nm, nn, m, n )
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


      subroutine  Iff(ich_in, ok, nm, nn, m, n )
* ------------------------------------------------------------------
* --- Read and verify values on dimensions                       ---
* ------------------------------------------------------------------

* --- Parameters
      integer            ndim, lmax
      parameter          ( ndim = 21, lmax = 1024)

* --- Input arguments
      integer        ich_in

* --- Output Arguments
      logical        ok
      integer        nm, nn, m(*), n(*)
      
	integer        log2 
      external       log2

* --- Local variables
      integer        i

* --- Executable Statements

      ok = .FALSE.

*     -- Read number of values on 1 dimension
      read ( ich_in, fmt = * ) nm
      write( *, fmt = * ) 'number of values on 1 dimension = ',
     $                     nm

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

*     -- Read number of values on 2 dimension
      read ( ich_in, fmt = * ) nn
      write( *, fmt = * ) 'number of values on 2 dimension = ',
     $                     nn

*     -- Test number of values on 2 dimension
      if (nn.gt.ndim) then
         write(*, fmt = 7701) nn, ndim
         GO TO 100
      end if

*     -- Read values on 2 dimension
      read(ich_in, fmt = * ) ( n( i ), i = 1, nn )
      write( *, fmt = * )  'Values on 2 dimension = ',
     $                     ( n( i ), i = 1, nn )

*      -- Test value is less than maximum
      do i = 1, nn
         if ( n(i) .gt. 2*log2(lmax) ) then
            write(*, fmt = 7703) n(i), 2*log2(lmax)
            GO TO 100
         end if
         n (i) = 2**n(i)
      end do
      ok = .TRUE.

  100 return

 7700 FORMAT(  ' Number of values on 1 dimension = ',
     $          i4, '  > max = ', i2 )
 7701 FORMAT(  ' Number of values on 2 dimension = ',
     $          i4, '  > max = ', i2 )
 7702 FORMAT( ' Value of 1 dimension (Power of 2) = ',
     $          i6, '  > max = ', i4 )
 7703 FORMAT( ' Value of 2 dimension (Power of 2) = ',
     $          i6, '  > max = ', i4 )

      end


      subroutine  Headsumm(ich_summ,
     $            eps, seps, afatal, atrace,
     $            tstdft, tsterr, tstcmpt, tst_sub,
     $            snames, nm, nn, m, n, dft_check, self_test )
* ------------------------------------------------------------------
* --- Write summary file header                                   --
* ------------------------------------------------------------------

* --- Parameters
      integer            nsubs
      parameter          ( nsubs = 6 )

* --- Input Arguments
      real*8             eps
      real               seps
      integer            nm, nn, m(*), n(*)

*     -- Channels and files for output
      integer            ich_summ

      logical            atrace, afatal,
     $                   tstdft, tstcmpt, tsterr,
     $                   tst_sub(*),
     $                   dft_check, self_test

*     ---  Names of testing subroutines
      character*8        snames( nsubs )

* --- Local Variables
      integer         i, isub

* --- Executiable statements...

      if (tstdft) i = 0
*     -- Summary file header
         write( ich_summ, fmt = 7707 )
     $         '-- Testing of 2D Fast Fourier Transform routines --',
     $         '--   by result comparision with results from    --',
     $         '--  2D Discrete Fourier Transform routine (DFT).--',
     $         '--      Routines for double complex data.       --',
     $         '--      Routines for single complex data.       --'

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

      write(ich_summ, fmt = 7704)
     $ 'Values on 2 dimension'
      write(ich_summ, fmt = *) (n( i ), i = 1, nn )

      return

 7701 FORMAT( t6, 'Double presision Eps = ', 1P, E9.1 )
 7702 FORMAT( t6,a, t16,a , t29,a )
 7703 FORMAT(       t16,l1, t29,l1 )
 7704 FORMAT( t2,a )
 7705 FORMAT( t6,a, t26, a, t46,a )
 7706 FORMAT( t10, i2, t29, a8, t50, l1 )
 7707 FORMAT( t6,a / t6,a / t6, a / t6, a / t6, a)
 7708 FORMAT( t6, 'Single presision Eps = ', 1P, E9.1 )

      end


      real*8 function dCeps( done, dhalf, dzero )
* ------------------------------------------------------------------
*     Compute machine-dependent double precision epsilon          --
* ------------------------------------------------------------------

      real*8   done, dhalf, dzero
      real*8   dDiff
      external dDiff

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

      real     sone, shalf, szero
      real     sDiff
      external sDiff

      sCeps = sone
   10 continue
      if ( sDiff( sone + sCeps, sone).eq.szero) GO TO 20
      sCeps = shalf * sCeps
      GO TO 10
   20 sCeps = sCeps + sCeps
      return
      end


      real*8 function dDiff( x, y )
* -----------------------------------------------------------
* --  Compute two double precision values difference       --
* -----------------------------------------------------------
      real*8 x, y

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


      subroutine  zEst ( ich_summ, ich_snap, eps, atrace, m, n,
     $                  a_tst, a_exp, gauge, sub_fatal,
     $                  name, isign)
* --------------------------------------------------------------
* --  Compare obtained result with true one (complex*16)      --
* --  (relative estimation)                                   --
* --------------------------------------------------------------
* --- Parameters
      real*8             zero, one
      parameter          ( zero = 0.d0, one = 1.d0 )

* --- Input Arguments
      real*8       eps, gauge
      integer      ich_summ, ich_snap, m, n, isign
      complex*16   a_tst(m, *), a_exp(m, *)
      logical      atrace
      character*8  name

* --- Output Arguments
      logical   sub_fatal


* --- Local Variables
      real*8        err, errij
      integer       i, ierr, ierrfirst
      integer       j, jerr, jerrfirst
      complex*16    C

* --- Intrinsic function
      intrinsic dsqrt, dble

* ---- Statement funtions
        real*8        abs1
* ---- Statement funtions definitions
        abs1( C ) = dsqrt( dble(C)*dble(C) + dimag(C)*dimag(C))

      ich_summ = ich_summ
      ierrfirst = -1
      jerrfirst = -1
      sub_fatal = .FALSE.
      err = zero
      do i = 1, m
        do j = 1, n
          errij = abs1( a_tst( i,j ) - a_exp( i,j ) ) / eps
          if ( gauge .ne. zero ) errij = errij/ (gauge)
          if (errij. gt. err ) then
             err =  errij
             ierr = i
             jerr = j
          end if
          if (errij .ge. one) then
             sub_fatal = .TRUE.
             if (ierrfirst.eq.-1) then
               ierrfirst = ierr
               jerrfirst = jerr
             endif
          endif
        end do
      end do

 100  continue
      if ( sub_fatal ) then
        if (atrace) then
          if (isign.EQ.0) then
                write(ich_snap , fmt = 7701)
     $                name,
     $                '  ISIGN = -1:+1',
     $                '  M = ', m, '  N = ', n,
     $                ' : ERROR'
          else
	      if (isign.EQ.22) then
                write(ich_snap , fmt = 7701)
     $                name,
     $                '  ISIGN = -2:+2',
     $                '  M = ', m, '  N = ', n,
     $                ' : ERROR'
            else
                write(ich_snap , fmt = 7700 )
     $                name,
     $                '  ISIGN = ', isign,
     $                '  M = ', m, '  N = ', n,
     $                ' : ERROR'
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
          write(ich_snap, fmt = 6602 ) ierrfirst, jerrfirst,
     $                                 a_exp( ierrfirst, jerrfirst ),
     $                                 a_tst( ierrfirst, jerrfirst )
          write(ich_snap, fmt = 6603 ) 'maximum difference:'
          write(ich_snap, fmt = 6602 ) ierr, jerr,
     $                                 a_exp( ierr, jerr ),
     $                                 a_tst( ierr, jerr )

          write(ich_snap,fmt = *) '  Matrix gauge: ',gauge
          errij =  abs1( a_tst( ierrfirst, jerrfirst ) -
     $                   a_exp( ierrfirst, jerrfirst ) )
          write(ich_snap,fmt = *)
     $     '  first |a(i,j) - a_expect(i,j)|: ', errij
          errij =  abs1( a_tst( ierr, jerr ) - a_exp( ierr, jerr ) )
          write(ich_snap,fmt = *)
     $     '  max   |a(i,j) - a_expect(i,j)|: ', errij

        endif
      else
        if (atrace) then
          if (isign.EQ.0) then
            write(ich_snap , fmt = 7701 )
     $          name,
     $          '  ISIGN = -1:+1',
     $          '  M = ', m, '  N = ', n,
     $          ' '
          else
            if (isign.EQ.22) then
                write(ich_snap , fmt = 7701 )
     $                name,
     $                '  ISIGN = -2:+2',
     $                '  M = ', m, '  N = ', n,
     $                ' '
            else
                write(ich_snap , fmt = 7700 )
     $                name,
     $                '  ISIGN = ', isign,
     $                '  M = ', m, '  N = ', n,
     $                ' '
            endif
          endif
        endif
      endif
 120  return

 6601 FORMAT( t2, a, a /  a, a, / a )
 6602 FORMAT( 1X, I6, I6, 2( '  (', G15.6, ',', G15.6, ')' ) )
 6603 FORMAT( t2, a )
 7700 FORMAT( t2, a8, a, i5, a, i6, a, i6, a)
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end


      subroutine  cEst ( ich_summ, ich_snap, eps, atrace, m, n,
     $                   a_tst, a_exp, gauge, sub_fatal,
     $                   name, isign)
* --------------------------------------------------------------
* --  Compare obtained result with true one (complex*16)      --
* --  (relative estimation)                                   --
* --------------------------------------------------------------
* --- Parameters
      real*4             zero, one
      parameter          ( zero = 0.e0, one = 1.e0 )

* --- Input Arguments
      real*4       eps, gauge
      integer      ich_summ, ich_snap, m, n, isign
      complex*8    a_tst(m, *), a_exp(m, *)
      logical      atrace
      character*8  name

* --- Output Arguments
      logical   sub_fatal

* --- Local Variables
      real*4        err, errij
      integer       i, ierr, ierrfirst
      integer       j, jerr, jerrfirst
      complex       C

* --- Intrinsic function
      intrinsic sqrt, real

* ---- Statement funtions
        real*4        abs1
* ---- Statement funtions definitions
        abs1( C ) = sqrt( real(C)*real(C) + aimag(C)*aimag(C))


      ich_summ = ich_summ
      ierrfirst = -1
      jerrfirst = -1
      sub_fatal = .FALSE.
      err = zero
      do i = 1, m
        do j = 1, n
          errij = abs1( a_tst( i,j ) - a_exp( i,j ) ) / eps
          if ( gauge .ne. zero ) errij = errij/ (gauge)
          if (errij. gt. err ) then
             err =  errij
             ierr = i
             jerr = j
          end if
          if (errij .ge. one) then
             sub_fatal = .TRUE.
             if (ierrfirst.eq.-1) then
               ierrfirst = ierr
               jerrfirst = jerr
             endif
          endif
        end do
      end do

 100  continue
      if ( sub_fatal ) then
        if (atrace) then
          if (isign.EQ.0) then
                write(ich_snap , fmt = 7701)
     $                name,
     $                '  ISIGN = -1:+1',
     $                '  M = ', m, '  N = ', n,
     $                ' : ERROR'
          else
	      if (isign.EQ.22) then
                write(ich_snap , fmt = 7701)
     $                name,
     $                '  ISIGN = -2:+2',
     $                '  M = ', m, '  N = ', n,
     $                ' : ERROR'
            else
                write(ich_snap , fmt = 7700 )
     $                name,
     $                '  ISIGN = ', isign,
     $                '  M = ', m, '  N = ', n,
     $                ' : ERROR'
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
          write(ich_snap, fmt = 6602 ) ierrfirst, jerrfirst,
     $                                 a_exp( ierrfirst, jerrfirst ),
     $                                 a_tst( ierrfirst, jerrfirst )
          write(ich_snap, fmt = 6603 ) 'maximum difference:'
          write(ich_snap, fmt = 6602 ) ierr, jerr,
     $                                 a_exp( ierr, jerr ),
     $                                 a_tst( ierr, jerr )

          write(ich_snap,fmt = *) '  Matrix gauge: ',gauge
          errij =  abs1( a_tst( ierrfirst, jerrfirst ) -
     $                   a_exp( ierrfirst, jerrfirst ) )
          write(ich_snap,fmt = *)
     $     '  first |a(i,j) - a_expect(i,j)|: ', errij
          errij =  abs1( a_tst( ierr, jerr ) - a_exp( ierr, jerr ) )
          write(ich_snap,fmt = *)
     $     '  max   |a(i,j) - a_expect(i,j)|: ', errij

        endif
      else
        if (atrace) then
          if (isign.EQ.0) then
            write(ich_snap , fmt = 7701 )
     $          name,
     $          '  ISIGN = -1:+1',
     $          '  M = ', m, '  N = ', n,
     $          ' '
          else
            if (isign.EQ.22) then
                write(ich_snap , fmt = 7701 )
     $                name,
     $                '  ISIGN = -2:+2',
     $                '  M = ', m, '  N = ', n,
     $                ' '
            else
                write(ich_snap , fmt = 7700 )
     $                name,
     $                '  ISIGN = ', isign,
     $                '  M = ', m, '  N = ', n,
     $                ' '
            endif
          endif
        endif
      endif
 120  return

 6601 FORMAT( t2, a, a /  a, a, / a )
 6602 FORMAT( 1X, I6, I6, 2( '  (', G15.6, ',', G15.6, ')' ) )
 6603 FORMAT( t2, a )
 7700 FORMAT( t2, a8, a, i5, a, i6, a, i6, a)
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end

      subroutine  dEst ( ich_summ, ich_snap, eps, atrace, m, n,
     $                  a_tst, ldtst, a_exp, ldexp, gauge,
     $                  sub_fatal, name, isign)
* --------------------------------------------------------------
* --  Compare obtained result with true one (complex*16)      --
* --  (relative estimation)                                   --
* --------------------------------------------------------------
* --- Parameters
      real*8             zero, one
      parameter          ( zero = 0.d0, one = 1.d0 )

* --- Input Arguments
      real*8       eps, gauge
      integer      ich_summ, ich_snap, m, n, isign, ldtst, ldexp
      real*8       a_tst(ldtst, *), a_exp(ldexp, *)
      logical      atrace
      character*8  name

* --- Output Arguments
      logical   sub_fatal


* --- Local Variables
      real*8        err, errij
      integer       i, ierr, ierrfirst
      integer       j, jerr, jerrfirst

* --- Intrinsic function
      intrinsic dsqrt

      ich_summ = ich_summ
      ierrfirst = -1
      jerrfirst = -1
      sub_fatal = .FALSE.
      err = zero
      do i = 1, m
        do j = 1, n
          errij = dabs( a_tst( i,j ) - a_exp( i,j ) ) / eps
          if ( gauge .ne. zero ) errij = errij/ (gauge)
          if (errij. gt. err ) then
             err =  errij
             ierr = i
             jerr = j
          end if
          if (errij .ge. one) then
             sub_fatal = .TRUE.
             if (ierrfirst.eq.-1) then
               ierrfirst = ierr
               jerrfirst = jerr
             endif
          endif
        end do
      end do

 100  continue
      if ( sub_fatal ) then
        if (atrace) then
          if (isign.NE.0) then
            write(ich_snap , fmt = 7700 )
     $            name,
     $            '  ISIGN = ', isign,
     $            '  M = ', m, '  N = ', n,
     $            ' : ERROR'
          else
            write(ich_snap , fmt = 7701)
     $          name,
     $          '  ISIGN = -1:+1',
     $          '  M = ', m, '  N = ', n,
     $          ' : ERROR'
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
          write(ich_snap, fmt = 6602 ) ierrfirst, jerrfirst,
     $                                 a_exp( ierrfirst, jerrfirst ),
     $                                 a_tst( ierrfirst, jerrfirst )
          write(ich_snap, fmt = 6603 ) 'maximum difference:'
          write(ich_snap, fmt = 6602 ) ierr, jerr,
     $                                 a_exp( ierr, jerr ),
     $                                 a_tst( ierr, jerr )

          write(ich_snap,fmt = *) '  Matrix gauge: ',gauge
          errij =  dabs( a_tst( ierrfirst, jerrfirst ) -
     $                   a_exp( ierrfirst, jerrfirst ) )
          write(ich_snap,fmt = *)
     $     '  first |a(i,j) - a_expect(i,j)|: ', errij
          errij =  dabs( a_tst( ierr, jerr ) - a_exp( ierr, jerr ) )
          write(ich_snap,fmt = *)
     $     '  max   |a(i,j) - a_expect(i,j)|: ', errij

        endif
      else
        if (atrace) then
          if (isign.NE.0) then
            write(ich_snap , fmt = 7700 )
     $            name,
     $            '  ISIGN = ', isign,
     $            '  M = ', m, '  N = ', n,
     $            ' '
          else
            write(ich_snap , fmt = 7701 )
     $          name,
     $          '  ISIGN = -1:+1',
     $          '  M = ', m, '  N = ', n,
     $          ' '
          endif
        endif
      endif
 120  return

 6601 FORMAT( t2, a, a /  a, a, / a )
 6602 FORMAT( 1X, I6, I6, 2( '  (', G15.6, ',', G15.6, ')' ) )
 6603 FORMAT( t2, a )
 7700 FORMAT( t2, a8, a, i5, a, i6, a, i6, a)
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end


      subroutine  sEst ( ich_summ, ich_snap, eps, atrace, m, n,
     $                  a_tst, ldtst, a_exp, ldexp, gauge,
     $                  sub_fatal, name, isign)
* --------------------------------------------------------------
* --  Compare obtained result with true one (complex*16)      --
* --  (relative estimation)                                   --
* --------------------------------------------------------------
* --- Parameters
      real*4             zero, one
      parameter          ( zero = 0.d0, one = 1.d0 )

* --- Input Arguments
      real*4       eps, gauge
      integer      ich_summ, ich_snap, m, n, isign, ldtst, ldexp
      real*4       a_tst(ldtst, *), a_exp(ldexp, *)
      logical      atrace
      character*8  name

* --- Output Arguments
      logical   sub_fatal


* --- Local Variables
      real*4        err, errij
      integer       i, ierr, ierrfirst
      integer       j, jerr, jerrfirst

* --- Intrinsic function
      intrinsic sqrt

      ich_summ = ich_summ
      ierrfirst = -1
      jerrfirst = -1
      sub_fatal = .FALSE.
      err = zero
      do i = 1, m
        do j = 1, n
          errij = abs( a_tst( i,j ) - a_exp( i,j ) ) / eps
          if ( gauge .ne. zero ) errij = errij/ (gauge)
          if (errij. gt. err ) then
             err =  errij
             ierr = i
             jerr = j
          end if
          if (errij .ge. one) then
             sub_fatal = .TRUE.
             if (ierrfirst.eq.-1) then
               ierrfirst = ierr
               jerrfirst = jerr
             endif
          endif
        end do
      end do

 100  continue
      if ( sub_fatal ) then
        if (atrace) then
          if (isign.NE.0) then
            write(ich_snap , fmt = 7700 )
     $            name,
     $            '  ISIGN = ', isign,
     $            '  M = ', m, '  N = ', n,
     $            ' : ERROR'
          else
            write(ich_snap , fmt = 7701)
     $          name,
     $          '  ISIGN = -1:+1',
     $          '  M = ', m, '  N = ', n,
     $          ' : ERROR'
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
          write(ich_snap, fmt = 6602 ) ierrfirst, jerrfirst,
     $                                 a_exp( ierrfirst, jerrfirst ),
     $                                 a_tst( ierrfirst, jerrfirst )
          write(ich_snap, fmt = 6603 ) 'maximum difference:'
          write(ich_snap, fmt = 6602 ) ierr, jerr,
     $                                 a_exp( ierr, jerr ),
     $                                 a_tst( ierr, jerr )

          write(ich_snap,fmt = *) '  Matrix gauge: ',gauge
          errij =  abs( a_tst( ierrfirst, jerrfirst ) -
     $                   a_exp( ierrfirst, jerrfirst ) )
          write(ich_snap,fmt = *)
     $     '  first |a(i,j) - a_expect(i,j)|: ', errij
          errij =  abs( a_tst( ierr, jerr ) - a_exp( ierr, jerr ) )
          write(ich_snap,fmt = *)
     $     '  max   |a(i,j) - a_expect(i,j)|: ', errij

        endif
      else
        if (atrace) then
          if (isign.NE.0) then
            write(ich_snap , fmt = 7700 )
     $            name,
     $            '  ISIGN = ', isign,
     $            '  M = ', m, '  N = ', n,
     $            ' '
          else
            write(ich_snap , fmt = 7701 )
     $          name,
     $          '  ISIGN = -1:+1',
     $          '  M = ', m, '  N = ', n,
     $          ' '
          endif
        endif
      endif
 120  return

 6601 FORMAT( t2, a, a /  a, a, / a )
 6602 FORMAT( 1X, I6, I6, 2( '  (', G15.6, ',', G15.6, ')' ) )
 6603 FORMAT( t2, a )
 7700 FORMAT( t2, a8, a, i5, a, i6, a, i6, a)
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end



      subroutine zcomp_gauge( a, lda, m, n, isign, gauge )
* --------------------------------------------------------------
* --  Compute Input matrix gauge  (complex*16)                --
* --------------------------------------------------------------

* --- Input Arguments
      integer        m, n, lda, isign
      complex*16     a(lda, *)
      real*8         gauge

* ---  Local Variables
      integer        i, j

      gauge = 0.0d0
      do i = 1, m
        do j = 1, n
          gauge = gauge + dble(a( i,j ))*dble(a( i,j )) +
     $                    dimag(a( i,j ))*dimag(a( i,j ))
        end do
      end do
*      if (isign.ge.0) gauge = gauge/(dreal(m)*dreal(n))
      if (isign.ge.0) gauge = gauge/(dfloat(m)*dfloat(n))
      return
      end

      subroutine ccomp_gauge( a, lda, m, n, isign, gauge )
* --------------------------------------------------------------
* --  Compute Input matrix gauge  (complex*16)                --
* --------------------------------------------------------------

* --- Input Arguments
      integer        m, n, lda, isign
      complex        a(lda, *)
      real           gauge
      real*8         dgauge

* ---  Local Variables
      integer        i, j

      dgauge = 0.0d0
      do i = 1, m
        do j = 1, n
          dgauge = dgauge + real(a(i,j ))*real(a( i,j )) +
     $                    aimag(a(i,j))*aimag(a( i,j ))
        end do
      end do
	  
	  gauge = dgauge;

      if (isign.ge.0) gauge = gauge/(float(m)*float(n))
      return
      end

      subroutine dcomp_gauge( a, lda, m, n, isign, gauge, a_t )
* --------------------------------------------------------------
* --  Compute Input matrix gauge  (real*8)                    --
* --------------------------------------------------------------

* --- Input Arguments
      integer        m, n, lda, isign
      real*8         a(lda, *)
      real*8         gauge

* ---  Local Variables
      complex*16     a_t(*)

      if (isign .EQ. 1) then
        call dzmCopy(a, lda, a_t, lda, m, n)
      else
        call dzmCopy_exp(a, lda, a_t, lda, m, n)
      endif
      call zcomp_gauge(a_t, lda, m, n, isign, gauge)

      return
      end

      subroutine scomp_gauge( a, lda, m, n, isign, gauge, a_t )
* --------------------------------------------------------------
* --  Compute Input matrix gauge  (real*4)                    --
* --------------------------------------------------------------

* --- Input Arguments
      integer        m, n, lda, isign
      real*4         a(lda, *)
      real*4         gauge

* ---  Local Variables
      complex*8      a_t(*)

      if (isign .EQ. 1) then
        call scmCopy(a, lda, a_t, lda, m, n)
      else
        call scmCopy_exp(a, lda, a_t, lda, m, n)
      endif
      call ccomp_gauge(a_t, lda, m, n, isign, gauge)

      return
      end

      logical function Fsub( tst_sub, nsubs)

* --- Is there subroutines for testing?

* --- Input Arguments
      logical     tst_sub(*)
      integer     nsubs

* --- Local Variables
      integer     isub

* --- Executiable Statements

      Fsub = .FALSE.
      do isub = 1, nsubs
         Fsub = Fsub .or. tst_sub( isub )
      end do
      return
      end


      subroutine zRandm (a, m, n)

      integer           m, n
      complex*16        a(m,*)

      double precision  RealP, ImagP
      integer           i, j

      double precision  dbeg
      external          dbeg

      do i = 1, m
        do j = 1, n
          RealP = dbeg(.FALSE.)
          ImagP = dbeg(.FALSE.)
          a(i,j) = cmplx (RealP, ImagP)
        end do
      end do

      return
      end

      subroutine cRandm (a, m, n)

      integer           m, n
      complex           a(m,*)

      double precision  RealP, ImagP
      integer           i, j

      double precision  dbeg
      external          dbeg

      do i = 1, m
        do j = 1, n
          RealP = dbeg(.FALSE.)
          ImagP = dbeg(.FALSE.)
          a(i,j) = cmplx (RealP, ImagP)
        end do
      end do

      return
      end

      subroutine dRandm (a, lda, m, n)

      integer           m, n, lda
      real*8            a(lda,*)

      integer           i, j

      double precision  dbeg
      external          dbeg

      do i = 1, m
        do j = 1, n
          a(i,j) = dbeg(.FALSE.)
        end do
      end do

      return
      end

      subroutine sRandm (a, lda, m, n)

      integer           m, n, lda
      real*4            a(lda,*)
      
      integer           i, j

      double precision  dbeg
      external          dbeg

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

      subroutine zmCopy(a, b, m, n)

* --- Input Arguments
      integer    m, n
      complex*16 a(m, *)

* --- Output Arguments
      complex*16 b(m, *)

* --- Local variables 
      integer     i, j

      do i = 1, m
        do j = 1, n
          b(i,j) = a(i,j)
        end do
      end do

      return
      end

      subroutine cmCopy(a, b, m, n)

* --- Input Arguments
      integer    m, n
      complex    a(m, *)

* --- Output Arguments
      complex    b(m, *)

* --- Local variables 
      integer     i, j

      do i = 1, m
        do j = 1, n
          b(i,j) = a(i,j)
        end do
      end do

      return
      end

      subroutine smCopy(a, lda, b, ldb, m, n)

* --- Input Arguments
      integer    m, n, lda, ldb
      real*4     a(lda, *)

* --- Output Arguments
      real*4     b(ldb, *)

* --- Local variables 
      integer     i, j

      do i = 1, m
        do j = 1, n
          b(i,j) = a(i,j)
        end do
      end do

      return
      end

      subroutine dmCopy(a, lda, b, ldb, m, n)

* --- Input Arguments
      integer    m, n, lda, ldb
      real*8     a(lda, *)

* --- Output Arguments
      real*8     b(ldb, *)

* --- Local variables 
      integer     i, j

      do i = 1, m
        do j = 1, n
          b(i,j) = a(i,j)
        end do
      end do

      return
      end


      subroutine zcmCopy(a, b, m, n)

* --- Input Arguments
      integer    m, n
      complex*16 a(m, *)

* --- Output Arguments
      complex    b(m, *)

* --- Local variables 
      integer     i, j

      do i = 1, m
        do j = 1, n
          b(i,j) = a(i,j)
        end do
      end do

      return
      end



      subroutine scmCopy_exp(ra, rlda, ca, clda, m, n)

* --- Input Arguments
      integer    m, n, clda, rlda
      real*4     ra(rlda, *)

* --- Output Arguments
      complex*8  ca(clda, *)

* --- Local variables 
      integer     i, j

      do i = 1, m
        do j = 1, n
          ca(i,j) = cmplx(ra(i,j), 0.e0)
        end do
      end do

      return
      end

      subroutine dzmCopy_exp(ra, rlda, ca, clda, m, n)

* --- Input Arguments
      integer    m, n, clda, rlda
      real*8     ra(rlda, *)

* --- Output Arguments
      complex*16  ca(clda, *)

* --- Local variables 
      integer     i, j

      do i = 1, m
        do j = 1, n
          ca(i,j) = dcmplx(ra(i,j), 0.d0)
        end do
      end do

      return
      end

      subroutine scmCopy(ra, rlda, ca, clda, m, n)

* --- Input Arguments
      integer    m, n, clda, rlda
      real*4     ra(rlda, *)

* --- Output Arguments
      complex*8  ca(clda, *)

* --- Local variables
      integer     i, j, k, mm

      ca(1,1) = cmplx(ra(1,1), 0.e0)
      if (n.gt.1) then
        ca(1,n/2+1) = cmplx(ra(1,n+1), 0.e0)
      endif
      k = 3
      do j = 2, n/2
        ca(1,j) = cmplx(ra(1,k), ra(1,k+1))
        ca(1,n+2-j) = cmplx(ra(1,k), -ra(1,k+1))
        k = k+2
      end do

      if (m.gt.1) then
        mm = m/2+1
        ca(mm,1) = cmplx(ra(m+1,1), 0.e0)
        if (n.gt.1) then
          ca(mm,n/2+1) = cmplx(ra(m+1,n+1), 0.e0)
        endif
        k = 3
        do j = 2, n/2
          ca(mm,j) = cmplx(ra(m+1,k), ra(m+1,k+1))
          ca(mm,n+2-j) = cmplx(ra(m+1,k), -ra(m+1,k+1))
          k = k+2
        end do
      endif

      k = 3
      do i = 2, m/2
        ca(i,1) = cmplx(ra(k, 1), ra(k+1, 1))
        ca(m+2-i,1) = cmplx(ra(k, 1), -ra(k+1, 1))
        do j = 2, n
          ca(i,j) = cmplx(ra(k, j), ra(k+1, j))
          ca(m+2-i,n+2-j) = cmplx(ra(k, j), -ra(k+1, j))
        enddo
        k = k+2
      end do

      return
      end


      subroutine dzmCopy(ra, rlda, ca, clda, m, n)

* --- Input Arguments
      integer    m, n, clda, rlda
      real*8     ra(rlda, *)

* --- Output Arguments
      complex*16  ca(clda, *)

* --- Local variables
      integer     i, j, k, mm

      ca(1,1) = dcmplx(ra(1,1), 0.d0)
      if (n.gt.1) then
        ca(1,n/2+1) = dcmplx(ra(1,n+1), 0.d0)
      endif
      k = 3
      do j = 2, n/2
        ca(1,j) = dcmplx(ra(1,k), ra(1,k+1))
        ca(1,n+2-j) = dcmplx(ra(1,k), -ra(1,k+1))
        k = k+2
      end do

      if (m.gt.1) then
        mm = m/2+1
        ca(mm,1) = dcmplx(ra(m+1,1), 0.d0)
        if (n.gt.1) then
          ca(mm,n/2+1) = dcmplx(ra(m+1,n+1), 0.d0)
        endif
        k = 3
        do j = 2, n/2
          ca(mm,j) = dcmplx(ra(m+1,k), ra(m+1,k+1))
          ca(mm,n+2-j) = dcmplx(ra(m+1,k), -ra(m+1,k+1))
          k = k+2
        end do
      endif

      k = 3
      do i = 2, m/2
        ca(i,1) = dcmplx(ra(k, 1), ra(k+1, 1))
        ca(m+2-i,1) = dcmplx(ra(k, 1), -ra(k+1, 1))
        do j = 2, n
          ca(i,j) = dcmplx(ra(k, j), ra(k+1, j))
          ca(m+2-i,n+2-j) = dcmplx(ra(k, j), -ra(k+1, j))
        enddo
        k = k+2
      end do

      return
      end

      subroutine  zrCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m, n, a_tmp,
     $                  a_tst, a_exp_in, a_exp_out, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check)
* ----------------------------------------------------------------------
* -- Testing in compare with DFT (complex*16)                         --
* ----------------------------------------------------------------------
* --- Parameters
      real*8           zero, one
      parameter        (zero = 0.d0, one = 1.d0 )
      integer          lmax
	parameter        (lmax = 1024) 
* --- Input Arguments
      integer          ich_summ, ich_snap, isub
      real*8           eps
      logical          atrace, afatal, dft_check
      integer          m, n
      real*8           a_tst( m+2, * )
      complex*16       a_tmp( m, * )
      complex*16       a_exp_in( m, * )
      complex*16       a_exp_out( m, * )
      complex*16       ws_exp( * )
      character*8      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real*8           gauge,gauges

* --- Local Variables
      logical          gauge_fatal
      integer          lda, ldae, isign
      real             gausub
      integer          i, j, post_m, lpost_m
	parameter        (lpost_m = 256)
      real*8           post_tst(lpost_m,1)


* --- External subroutines
      external         zexp2d, zdfft2d, zmCopy

* --- Executable Statements

      lda = m+2
      ldae = m
      if (isub .EQ. 3) isign = -1
      if (isub .EQ. 5) isign = 1

*     -- Initialize vector for testing
      post_m = lpost_m
	if(post_m > ((lmax+2)*(lmax+2) - (m+2)*(n+2))) then
	    post_m = (lmax+2)*(lmax+2) - (m+2)*(n+2)
	end if
		 
	call dRandm(a_tst, lda, m+2, n+2)
      if (isign .EQ. -1) then
        call dzmCopy_exp(a_tst, lda, a_exp_in, ldae, m, n)
      else
          a_tst(1,2) = 0.0
          a_tst(1,n+2) = 0.0
          a_tst(m+1,2) = 0.0
          a_tst(m+1,n+2) = 0.0
          do j = 1, n
            a_tst(2,j) = 0.0
            a_tst(m+2,j) = 0.0
          enddo
          do i = 3, m
            a_tst(i,n+1) = 0.0
            a_tst(i,n+2) = 0.0
          enddo
          call dzmCopy(a_tst, lda, a_exp_in, ldae, m, n)
      endif

	call dRandm(a_tst(1,n+3), lda, post_m, 1)
      call dmCopy(a_tst(1,n+3), lda, post_tst, lpost_m, post_m, 1)

*      print *, 'copy', a_tst(1,n+3), post_tst(1,1) 

      if (dft_check) then
        call zexp2d(a_exp_in, ldae, m, n, isign, ws_exp, a_exp_out,
     $            ldae, gauge, a_tmp)
      else
        call zfft2d_s(a_exp_in, m, n, isign, ws_exp, a_exp_out)
        call zmCopy(a_exp_in, a_exp_out, m, n)
      endif

      sub_fatal( isub ) = .FALSE.
      gauge_fatal = .FALSE.


         call dcomp_gauge (a_tst, lda, m, n, isign, gauges,
     $                     a_tmp)

         if (isign .EQ. -1) then
           call dzfft2d( a_tst, m, n)
         else
           call zdfft2d( a_tst, m, n)
         endif

        if (isign.eq.-1) then
            isign = 1
         else
            isign = -1
         endif

         call dcomp_gauge (a_tst, lda, m, n, isign, gauge, a_tmp)

         if (isign.eq.-1) then
            isign = 1
         else
            isign = -1
         endif

         if (isign .EQ. -1) then
           call dzmCopy(a_tst, lda, a_exp_in, ldae, m, n)
         else
           call dzmCopy_exp(a_tst, lda, a_exp_in, ldae, m, n)
         endif

         gausub = (dabs(gauges-gauge) ) / eps
         if ( gauge .ne. zero ) gausub = gausub/(gauge)
            if (gausub .ge. one) then
               if (isign.eq.-1) then
                  write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                     ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                  gauge,gauges
               else
                   write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                     ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                  gauge,gauges
               endif
               write(ich_summ, fmt = 7700)
     $                  snames( isub ), ' : ERROR'
               sub_fatal( isub ) = .TRUE.
               gauge_fatal = .TRUE.
               if (afatal) goto 90
            endif

            call zEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                a_exp_in, a_exp_out, gauge, sub_fatal( isub ),
     $                snames(isub), isign )
c            if ( sub_fatal(isub) ) write(ich_summ, fmt = 7700)
c     $                  snames( isub ), ' : ERROR'
            if (afatal) GO TO 90

  90  continue
      if (gauge_fatal) sub_fatal(isub) = .TRUE.

      call zr2postm ( a_tst, post_tst, m, n, lpost_m, post_m, 
     $	                 sub_fatal(isub), ich_summ, isign)
      return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, i5, a, i6, a, i6, a)

      end

      subroutine  crCmpretest ( ich_summ, ich_snap, eps, atrace,
     $                  snames, m, n, a_tmp,
     $                  a_tst, a_exp_in, a_exp_out, ws_exp,
     $                  gauge, sub_fatal, afatal, isub, dft_check )
* ----------------------------------------------------------------------
* -- Testing in compare with DFT (complex*8)                          --
* ----------------------------------------------------------------------
* --- Parameters
      real*4           zero, one
      parameter        (zero = 0.e0, one = 1.e0 )
      integer          lmax
	parameter        (lmax = 1024) 

* --- Input Arguments
      integer          ich_summ, ich_snap, isub
      real*4           eps
      logical          atrace, afatal, dft_check
      integer          m, n
      real*4           a_tst( m+2, * )
      complex*8        a_tmp( m, * )
      complex*8        a_exp_in( m, * )
      complex*8        a_exp_out( m, * )
      complex*8        ws_exp( * )
      character*8      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real*4           gauge,gauges

* --- Local Variables
      logical          gauge_fatal
      integer          lda, ldae, isign
      real             gausub
      integer          i, j, post_m, lpost_m
	parameter        (lpost_m = 256)
      real*8           post_tst(lpost_m,1)


* --- External subroutines
      external         zexp2d, zdfft2d, zmCopy

* --- Executable Statements

      lda = m+2
      ldae = m
      if (isub .EQ. 4) isign = -1
      if (isub .EQ. 6) isign = 1

      post_m = lpost_m
	if(post_m > ((lmax+2)*(lmax+2) - (m+2)*(n+2))) then
	    post_m = (lmax+2)*(lmax+2) - (m+2)*(n+2)
	end if

*     -- Initialize vector for testing
      call sRandm(a_tst, lda, m+2, n+2)
      if (isign .EQ. -1) then
        call scmCopy_exp(a_tst, lda, a_exp_in, ldae, m, n)
      else
          a_tst(1,2) = 0.0
          a_tst(1,n+2) = 0.0
          a_tst(m+1,2) = 0.0
          a_tst(m+1,n+2) = 0.0
          do j = 1, n
            a_tst(2,j) = 0.0
            a_tst(m+2,j) = 0.0
          enddo
          do i = 3, m
            a_tst(i,n+1) = 0.0
            a_tst(i,n+2) = 0.0
          enddo
          call scmCopy(a_tst, lda, a_exp_in, ldae, m, n)
      endif

	call sRandm(a_tst(1,n+3), lda, post_m, 1)
      call smCopy(a_tst(1,n+3), lda, post_tst, lpost_m, post_m, 1)

      if (dft_check) then
        call cexp2d(a_exp_in, ldae, m, n, isign, ws_exp, a_exp_out,
     $            ldae, gauge, a_tmp)
      else
        call cfft2d_s(a_exp_in, m, n, isign, ws_exp, a_exp_out)
        call cmCopy(a_exp_in, a_exp_out, m, n)
      endif


      sub_fatal( isub ) = .FALSE.
      gauge_fatal = .FALSE.


         call scomp_gauge (a_tst, lda, m, n, isign, gauges,  
     $                     a_tmp)

         if (isign .EQ. -1) then
           call scfft2d( a_tst, m, n)
         else
           call csfft2d( a_tst, m, n)
         endif

        if (isign.eq.-1) then
            isign = 1
         else
            isign = -1
         endif

         call scomp_gauge (a_tst, lda, m, n, isign, gauge, a_tmp)

         if (isign.eq.-1) then
            isign = 1
         else
            isign = -1
         endif

         if (isign .EQ. -1) then
           call scmCopy(a_tst, lda, a_exp_in, ldae, m, n)
         else
           call scmCopy_exp(a_tst, lda, a_exp_in, ldae, m, n)
         endif

         gausub = (abs(gauges-gauge) ) / eps
         if ( gauge .ne. zero ) gausub = gausub/(gauge)
            if (gausub .ge. one) then
               if (isign.eq.-1) then
                  write(ich_summ, fmt = *)' ** FATAL: Forward ',
     $                     ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                  gauge,gauges
               else
                   write(ich_summ, fmt = *)' ** FATAL: Inverse ',
     $                     ' transform gauge is',
     $                  ' not egual input vector gauge',
     $                  gauge,gauges
               endif
               write(ich_summ, fmt = 7700)
     $                  snames( isub ), ' : ERROR'
               sub_fatal( isub ) = .TRUE.
               gauge_fatal = .TRUE.
               if (afatal) goto 90
            endif

            call cEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                a_exp_in, a_exp_out, gauge, sub_fatal( isub ),
     $                snames(isub), isign )
c            if ( sub_fatal(isub) ) write(ich_summ, fmt = 7700)
c     $                  snames( isub ), ' : ERROR'
            if (afatal) GO TO 90

  90  continue
      if (gauge_fatal) sub_fatal(isub) = .TRUE.

      call cr2postm ( a_tst, post_tst, m, n, lpost_m, post_m, 
     $	                 sub_fatal(isub), ich_summ, isign)
      return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, i5, a, i6, a, i6, a)

      end

      subroutine  zrFItest ( ich_summ, ich_snap, eps, atrace,
     $                      snames, m, n, a_tmp,
     $                      a_tst, a_exp, gauge, sub_fatal, isub)
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex*16)        --
* -----------------------------------------------------------
      integer          lmax
	parameter        (lmax = 1024) 
* --- Input Arguments
      integer          ich_summ, ich_snap, m, n, isub
      real*8           eps
      logical          atrace
      complex*16       a_tmp(*)
      real*8           a_tst(m+2, *), a_exp(m+2, *)
      character*8      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real*8           gauge

* --- Local Variables
      integer          lda
      integer          isign
      integer          post_m, lpost_m
	parameter        (lpost_m = 256)
      real*8           post_tst(lpost_m,1)

* --- External subroutines
      external         zfft2d, zmCopy,
     $                 zcomp_gauge, zEst

* --- Executable Statements

         lda = m+2
      post_m = lpost_m
	if(post_m > ((lmax+2)*(lmax+2) - (m+2)*(n+2))) then
	    post_m = (lmax+2)*(lmax+2) - (m+2)*(n+2)
	end if

         call dRandm(a_tst, lda, m, n)
         call dmCopy(a_tst, lda, a_exp, lda, m, n)

	call dRandm(a_tst(1,n+3), lda, post_m, 1)
      call dmCopy(a_tst(1,n+3), lda, post_tst, lpost_m, post_m, 1)

         sub_fatal( isub ) = .FALSE.

               isign = -1
               call dcomp_gauge (a_tst, lda, m, n, isign, gauge, 
     $                           a_tmp)

               call dzfft2d( a_tst, m, n)
               call zdfft2d( a_tst, m, n)

               call dEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                 a_tst, lda, a_exp, lda, gauge,
     $                 sub_fatal( isub ), snames(isub), 0 )
c               if ( sub_fatal(isub) ) write(ich_summ, fmt = 7700)
c     $                  snames( isub ), ' : ERROR'

  100    continue
      call zr2postm ( a_tst, post_tst, m, n, lpost_m, post_m, 
     $	                 sub_fatal(isub), ich_summ, isign)
         return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end

      subroutine  crFItest ( ich_summ, ich_snap, eps, atrace,
     $                      snames, m, n, a_tmp, 
     $                      a_tst, a_exp, gauge, sub_fatal, isub )
* -----------------------------------------------------------
* -- Testing Forward-Inverse transform (complex*16)        --
* -----------------------------------------------------------
      integer          lmax
	parameter        (lmax = 1024) 
* --- Input Arguments
      integer          ich_summ, ich_snap, m, n, isub
      real*4           eps
      logical          atrace
      complex*8        a_tmp(*)
      real*4           a_tst(m+2, *), a_exp(m+2, *)
      character*8      snames(*)

* --- Output Arguments
      logical          sub_fatal(*)
      real*4           gauge

* --- Local Variables
      integer          lda
      integer          isign
      integer          post_m, lpost_m
	parameter        (lpost_m = 256)
      real*8           post_tst(lpost_m,1)

* --- External subroutines
      external         zfft2d, zmCopy,
     $                 zcomp_gauge, zEst

* --- Executable Statements

         lda = m+2

      post_m = lpost_m
	if(post_m > ((lmax+2)*(lmax+2) - (m+2)*(n+2))) then
	    post_m = (lmax+2)*(lmax+2) - (m+2)*(n+2)
	end if

         call sRandm(a_tst, lda, m, n)
         call smCopy(a_tst, lda, a_exp, lda, m, n)

	call sRandm(a_tst(1,n+3), lda, post_m, 1)
      call smCopy(a_tst(1,n+3), lda, post_tst, lpost_m, post_m, 1)

         sub_fatal( isub ) = .FALSE.

               isign = -1
               call scomp_gauge (a_tst, lda, m, n, isign, gauge, 
     $                           a_tmp)

               call scfft2d( a_tst, m, n)
               call csfft2d( a_tst, m, n)

               call sEst( ich_summ, ich_snap, eps, atrace, m, n,
     $                 a_tst, lda, a_exp, lda, gauge,
     $                 sub_fatal( isub ), snames(isub), 0 )
c               if ( sub_fatal(isub) ) write(ich_summ, fmt = 7700)
c     $                  snames( isub ), ' : ERROR'

  100    continue
         call cr2postm ( a_tst, post_tst, m, n, lpost_m, post_m, 
     $	                 sub_fatal(isub), ich_summ, isign)
         return

 7700 FORMAT( t2, a8, a / )
 7701 FORMAT( t2, a8, a, a, i6, a, i6, a)

      end

      subroutine cexp2d (a_in, ld_in, m, n, isign, wsave,
     $                   a_out, ld_out, gauge, a_tmp)
* -----------------------------------------------------------
* --  complex*8 2D DFT                                     --
* -----------------------------------------------------------
* --- Input Arguments
        integer        m, n
        integer        ld_in, ld_out
        integer        isign
        complex        a_in(ld_in, *)
        complex        a_tmp(*)

* --- Output Arguments
        complex        a_out(ld_out, *), wsave(*)
        real           gauge

* --- Local Variables
        integer        i, j, l, k, ia
        real           argm, argn, accm
        complex        C


* ---- Statement funtions
        real          cabs1
* ---- Statement funtions definitions
        cabs1( C ) = sqrt( real(C)*real(C) + aimag(C)*aimag(C))

* ---- cexp2d start

      argm = 8.0*atan(1.0)/ float(m)
      argn = 8.0*atan(1.0)/ float(n)
      if (isign.le.0) then

*        -- Twiddle factors for forward transform

         do i = 1, m
            wsave( i ) = cmplx( cos( argm*(i-1) ), -sin( argm*(i-1) ) )
         end do
         do i = m+1, m+n
            wsave( i ) = cmplx( cos( argn*(i-m-1) ),
     $                          -sin( argn*(i-m-1)))
         end do
      else

*        -- Twiddle factors for inverse transform
         do i = 1, m
            wsave( i ) = cmplx( cos( argm*(i-1) ), sin( argm*(i-1) ) )
         end do
         do i = m+1, m+n
            wsave( i ) = cmplx( cos( argn*(i-m-1) ),
     $                          sin( argn*(i-m-1)))
         end do
      end if

      do j = 1, n
         do k = 1, m
            a_tmp( (j-1)*m + k ) = cmplx(0.0, 0.0)
            do i = 1, m
               ia = mod ( (i-1) * (k-1) , m) + 1
               a_tmp( (j-1)*m + k ) = a_tmp( (j-1)*m + k ) +
     $                        a_in( i,j ) * wsave( ia )
            end do
         end do
      end do

      do k = 1, m
         do l = 1, n
            a_out(k,l) = cmplx(0.0, 0.0)
            do j = 1, n
               ia = mod ( (j-1) * (l-1) , n) + 1
               a_out( k,l ) = a_out( k,l ) +
     $              a_tmp( (j-1)*m + k )*wsave( m+ia )
            end do
         end do
      end do

*     -- Compute gauge
      gauge = 0.0
      do i = 1, m
         do j = 1, n
            gauge = gauge + cabs1( a_in( i,j ) )*cabs1( a_in( i,j ) )
         end do
      end do

*     -- Normalization for inverse transform
      if (isign .gt. 0) then
         accm = n*m
         do k = 1, m
            do l = 1, n
               a_out( k,l ) = a_out ( k,l )/accm
            end do
         end do
         gauge = gauge/accm
      end if

      return
      end

      subroutine zexp2d (a_in, ld_in, m, n, isign, wsave,
     $                   a_out, ld_out, gauge, a_tmp)
* -----------------------------------------------------------
* --  complex*16 2D DFT                                     --
* -----------------------------------------------------------
* --- Input Arguments
        integer        m, n
        integer        ld_in, ld_out
        integer        isign
        complex*16     a_in(ld_in, *)
        complex*16     a_tmp(*)

* --- Output Arguments
        complex*16     a_out(ld_out, *), wsave(*)
        real*8         gauge

* --- Local Variables
        integer        i, j, l, k, ia
        real*8         argm, argn, accm
        complex*16     C


* ---- Statement funtions
        real*8         cabs1
* ---- Statement funtions definitions
        cabs1( C ) = dsqrt( dble(C)*dble(C) + dimag(C)*dimag(C))

* ---- cexp2d start


      argm = 8.d0*datan(1.d0)/ float(m)
      argn = 8.d0*datan(1.d0)/ float(n)
      if (isign.le.0) then

*        -- Twiddle factors for forward transform
         do i = 1, m
            wsave( i ) = dcmplx( dcos(argm*(i-1)), -dsin(argm*(i-1)))
         end do
         do i = m+1, m+n
            wsave( i ) = dcmplx( dcos( argn*(i-m-1) ),
     $                           -dsin( argn*(i-m-1)))
         end do
      else

*        -- Twiddle factors for inverse transform
         do i = 1, m
            wsave( i ) = dcmplx( dcos( argm*(i-1) ), dsin(argm*(i-1)))
         end do
         do i = m+1, m+n
            wsave( i ) = dcmplx( dcos( argn*(i-m-1) ),
     $                           dsin( argn*(i-m-1)))
         end do
      end if

      do j = 1, n
         do k = 1, m
            a_tmp( (j-1)*m + k ) = cmplx(0.0, 0.0)
            do i = 1, m
               ia = mod ( (i-1) * (k-1) , m) + 1
               a_tmp( (j-1)*m + k ) = a_tmp( (j-1)*m + k ) +
     $                        a_in( i,j ) * wsave( ia )
            end do
         end do
      end do

      do k = 1, m
         do l = 1, n
            a_out(k,l) = cmplx(0.0, 0.0)
            do j = 1, n
               ia = mod ( (j-1) * (l-1) , n) + 1
               a_out( k,l ) = a_out( k,l ) +
     $              a_tmp( (j-1)*m + k )*wsave( m+ia )
            end do
         end do
      end do

*     -- Compute gauge
      gauge = 0.0
      do i = 1, m
         do j = 1, n
            gauge = gauge + cabs1( a_in( i,j ) )*cabs1( a_in( i,j ) )
         end do
      end do

*     -- Normalization for inverse transform
      if (isign .gt. 0) then
         accm = n*m
         do k = 1, m
            do l = 1, n
               a_out( k,l ) = a_out ( k,l )/accm
            end do
         end do
         gauge = gauge/accm
      end if

      return
      end

      subroutine Chffterr( ich_summ, isub, sname,
     $                      a_z, a_c, a_d, a_s, 
     $                      ok_err )
      integer     ich_summ, isub
      character*8 sname
      complex*16  a_z(1,*)
      complex*8   a_c(1,*)
      real*8      a_d(1,*)
      real*4      a_s(1,*)
      logical     ok_err

* --- Common block for Error-Exits testing
      integer            code_err, ich_out
      logical            lerr, ok
*     ---        name of testing routine
      character*8        sub_err
      common             /exiterr/ code_err, ich_out, lerr, ok
      common             /exitname/ sub_err

      integer    m, n, isign

      ok = .TRUE.
      ok_err = ok
      lerr = .FALSE.
      sub_err = sname
      ich_out = ich_summ

c Test 1 - negative m
c      print*, 'Call 1 time'
c      print*, 'Call 1 time'
      code_err = 2
      m = -1
      n = -1
      isign = -5
      call call_func( isub, 
     $                a_z, a_c, a_d, a_s, 
     $                m, n, isign )
      call Cherr ( ich_summ, sname, code_err, lerr, ok)

c      print*, 'Call 2 time'
c      print*, 'Call 2 time'
      code_err = 2
      m = 0
      n = -1
      isign = -5
      call call_func( isub, 
     $                a_z, a_c, a_d, a_s, 
     $                m, n, isign )
      call Cherr ( ich_summ, sname, code_err, lerr, ok)

c      print*, 'Call 3 time'
c      print*, 'Call 3 time'
      code_err = 3
      m = 2
      n = -1
      isign = -5
      call call_func( isub, 
     $                a_z, a_c, a_d, a_s, 
     $                m, n, isign )
      call Cherr ( ich_summ, sname, code_err, lerr, ok)

c      print*, 'Call 4 time'
c      print*, 'Call 4 time'
      code_err = 3
      m = 2
      n = 0
      isign = -5
      call call_func( isub, 
     $                a_z, a_c, a_d, a_s, 
     $                m, n, isign )
      call Cherr ( ich_summ, sname, code_err, lerr, ok)

c      print*, 'Call 5 time'
c      print*, 'Call 5 time'
      if (isub .EQ. 1 .OR. isub .EQ. 2) then
        code_err = 4
        m = 2
        n = 2
        isign = -3
        call call_func( isub, 
     $                  a_z, a_c, a_d, a_s, 
     $                  m, n, isign )
        call Cherr ( ich_summ, sname, code_err, lerr, ok)

c      print*, 'Call 6 time'
c      print*, 'Call 6 time'
        code_err = 4
        m = 2
        n = 2
        isign = 0
        call call_func( isub, 
     $                  a_z, a_c, a_d, a_s, 
     $                  m, n, isign )
*        call Cherr ( ich_summ, sname, code_err, lerr, ok)

c      print*, 'Call 7 time'
c      print*, 'Call 7 time'
        code_err = 4
        m = 2
        n = 2
        isign = 3
        call call_func( isub, 
     $                  a_z, a_c, a_d, a_s, 
     $                  m, n, isign )
        call Cherr ( ich_summ, sname, code_err, lerr, ok)

      endif

      if (.NOT.ok) ok_err = .FALSE. 

      return

      end

      subroutine  Cherr (ich_summ, sub_name, code_err, lerr, ok)
* ----------------------------------------------------------------------
* --  Verifying error-exits - work of xerbla                          --
* ----------------------------------------------------------------------
      integer            ich_summ, code_err
      character*8        sub_name
      logical            lerr, ok

      if ( .NOT.lerr ) then
         write( ich_summ, fmt = 7700) code_err, sub_name
         ok = .FALSE.
      end if
      lerr = .FALSE.

      return

 7700 format( t6, '**** error number ', i2, ' not detected by ', a8,
     $       ' ****' )

      end

* ---------------------------------------------------------
* --                                                     --
* --     E R R O R       H A N D L I N G                 --
* --                                                     --
* ---------------------------------------------------------

      subroutine xerbla(name_func, ind_err)

      character *8 name_func
      integer ind_err

      integer            code_err, ich_out
      logical            lerr, ok

      character*8        sub_err
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
*        print*, name_func, 'XXX - Actually called'
*        print*, sub_err, 'XXX - Expected'
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


      subroutine call_func( isub, 
     $                      a_z, a_c, a_d, a_s, 
     $                      m, n, isign )

      integer     isub
      complex*16  a_z(1,*)
      complex*8   a_c(1,*)
      real*8      a_d(1,*)
      real*4      a_s(1,*)

      integer    m, n, isign

      goto (10, 20, 30, 40, 50, 60) isub
 10   call zfft2d(a_z, m, n, isign)
      goto 77

 20   call cfft2d(a_c, m, n, isign)
      goto 77

 30   call dzfft2d(a_d, m, n)
      goto 77

 40   call scfft2d(a_s, m, n)
      goto 77

 50   call zdfft2d(a_d, m, n)
      goto 77

 60   call csfft2d(a_s, m, n)
      goto 77

 77   continue
*# ifdef _DLL
*      call MKLEND()
*# endif

      return
      end
      subroutine  z2postm ( a_tst, a_exp, m, n, post_m, 
     $	                 sub_fatal, ich_summ, isign)
* --------------------------------------------------------------
* --  Compare memory after array  (complex (KIND=8))          --
* --------------------------------------------------------------
* --- Input Arguments
      integer           m, n, post_m, ich_summ, isign
	complex (KIND=8)  a_tst(m, *), a_exp(m, *)

* --- Output Arguments
      logical           sub_fatal

* --- Local Variables
      integer           s

	do s=1,  post_m
          if (a_tst(s,n+1) .ne. a_exp(s,n+1)) then
*              print *, s, a_tst(m+s), a_exp(m+s)
              print '(/a,i6,i6,a,i2,a)', 'Error (matrix size =', m, n,
     $		   ', isign = ', isign, ') : using of memory after array.'
              write(ich_summ,fmt='(/a,i6,i6,a,i2,a)')
     $		      'Error (matrix size =', m, n, ', isign = ', isign,
     $		      '): using of memory after array.'
		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do

10    continue
      end

      subroutine  c2postm ( a_tst, a_exp, m, n, post_m, 
     $	                 sub_fatal, ich_summ, isign)
* --------------------------------------------------------------
* --  Compare memory after array (complex (KIND=4))           --
* --------------------------------------------------------------
* --- Input Arguments
      integer           m, n, post_m, ich_summ, isign
      complex (KIND=4)  a_tst(m,*), a_exp(m,*)

* --- Output Arguments
      logical           sub_fatal

* --- Local Variables
      integer           s

	do s=1, post_m
          if (a_tst(s,n+1) .ne. a_exp(s,n+1)) then

              print '(/a,i6,i6,a,i2,a)', 'Error (matrix size =', m, n,
     $		   ', isign = ', isign, ') : using of memory after array.'
              write(ich_summ,fmt='(/a,i6,i6,a,i2,a)')
     $		      'Error (matrix size =', m, n, ', isign = ', isign,
     $		      '): using of memory after array.'
		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do

10    continue

      end
      subroutine  zr2postm ( a_tst, a_exp, m, n, lpost_m, post_m, 
     $	                 sub_fatal, ich_summ, isign)
* --------------------------------------------------------------
* --  Compare memory after array  (complex (KIND=8))          --
* --------------------------------------------------------------
* --- Input Arguments
      integer           m, n, lpost_m, post_m, ich_summ, isign
	real*8            a_tst(m+2, *), a_exp(lpost_m, *)

* --- Output Arguments
      logical           sub_fatal

* --- Local Variables
      integer           s

*      print *, 'cmp', a_tst(1,n+3), a_exp(1,1) 

	do s=1,  post_m
          if (a_tst(s,n+3) .ne. a_exp(s,1)) then
*              print *, s, a_tst(m+s), a_exp(m+s)
              print '(/a,i6,i6,a,i2,a)', 'Error (matrix size =', m, n,
     $		   ', isign = ', isign, ') : using of memory after array.'
              write(ich_summ,fmt='(/a,i6,i6,a,i2,a)')
     $		      'Error (matrix size =', m, n, ', isign = ', isign,
     $		      '): using of memory after array.'
		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do
10    continue
      end

      subroutine  cr2postm ( a_tst, a_exp, m, n, lpost_m, post_m, 
     $	                 sub_fatal, ich_summ, isign)
* --------------------------------------------------------------
* --  Compare memory after array (complex (KIND=4))           --
* --------------------------------------------------------------
* --- Input Arguments
      integer           m, n, lpost_m, post_m, ich_summ, isign
      real*4            a_tst(m+2,*), a_exp(lpost_m, *)

* --- Output Arguments
      logical           sub_fatal

* --- Local Variables
      integer           s

	do s=1, post_m
          if (a_tst(s,n+3) .ne. a_exp(s,1)) then

              print '(/a,i6,i6,a,i2,a)', 'Error (matrix size =', m, n,
     $		   ', isign = ', isign, ') : using of memory after array.'
              write(ich_summ,fmt='(/a,i6,i6,a,i2,a)')
     $		      'Error (matrix size =', m, n, ', isign = ', isign,
     $		      '): using of memory after array.'
		    sub_fatal = .TRUE.
	        goto 10
		end if	 
	end do
10    continue
      end
