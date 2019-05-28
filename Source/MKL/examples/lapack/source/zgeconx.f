*     ZGECON (F07AUF) Example Program Text
*     Mark 15 Release. NAG Copyright 1991.
*     .. Parameters ..
      INTEGER          NIN, NOUT
      PARAMETER        (NIN=5,NOUT=6)
      INTEGER          NMAX, LDA
      PARAMETER        (NMAX=8,LDA=NMAX)
      CHARACTER        NORM
      PARAMETER        (NORM='1')
*     .. Local Scalars ..
      DOUBLE PRECISION ANORM, RCOND
      INTEGER          I, INFO, J, N
*     .. Local Arrays ..
      COMPLEX*16       A(LDA,NMAX), WORK(2*NMAX)
      DOUBLE PRECISION RWORK(2*NMAX)
      INTEGER          IPIV(NMAX)
*     .. External Functions ..
      DOUBLE PRECISION F06UAF, X02AJF
      EXTERNAL         F06UAF, X02AJF
*     .. External Subroutines ..
      EXTERNAL         ZGECON, ZGETRF
*     .. Executable Statements ..
      WRITE (NOUT,*) 'ZGECON Example Program Results'
*     Skip heading in data file
      READ (NIN,*)
      READ (NIN,*) N
      IF (N.LE.NMAX) THEN
*
*        Read A from data file
*
         READ (NIN,*) ((A(I,J),J=1,N),I=1,N)
*
*        Compute norm of A
*
         ANORM = F06UAF(NORM,N,N,A,LDA,RWORK)
*
*        Factorize A
*
         CALL ZGETRF(N,N,A,LDA,IPIV,INFO)
*
         WRITE (NOUT,*)
         IF (INFO.EQ.0) THEN
*
*           Estimate condition number
*
            CALL ZGECON(NORM,N,A,LDA,ANORM,RCOND,WORK,RWORK,INFO)
*
            IF (RCOND.GE.X02AJF()) THEN
               WRITE (NOUT,99999) 'Estimate of condition number =',
     +           1.0D0/RCOND
            ELSE
               WRITE (NOUT,*) 'A is singular to working precision'
            END IF
         ELSE
            WRITE (NOUT,*) 'The factor U is singular'
         END IF
      END IF
      STOP
*
99999 FORMAT (1X,A,1P,D10.2)
      END
