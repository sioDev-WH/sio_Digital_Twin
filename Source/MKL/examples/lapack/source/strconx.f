*     STRCON (F07TGE) Example Program Text
*     Mark 15 Release. NAG Copyright 1991.
*     .. Parameters ..
      INTEGER          NIN, NOUT
      PARAMETER        (NIN=5,NOUT=6)
      INTEGER          NMAX, LDA
      PARAMETER        (NMAX=8,LDA=NMAX)
      CHARACTER        NORM, DIAG
      PARAMETER        (NORM='1',DIAG='N')
*     .. Local Scalars ..
      REAL             RCOND
      INTEGER          I, INFO, J, N
      CHARACTER        UPLO
*     .. Local Arrays ..
      REAL             A(LDA,NMAX), WORK(3*NMAX)
      INTEGER          IWORK(NMAX)
*     .. External Functions ..
      REAL             X02AJE
      EXTERNAL         X02AJE
*     .. External Subroutines ..
      EXTERNAL         STRCON
*     .. Executable Statements ..
      WRITE (NOUT,*) 'STRCON Example Program Results'
*     Skip heading in data file
      READ (NIN,*)
      READ (NIN,*) N
      IF (N.LE.NMAX) THEN
*
*        Read A from data file
*
         READ (NIN,*) UPLO
         IF (UPLO.EQ.'U') THEN
            READ (NIN,*) ((A(I,J),J=I,N),I=1,N)
         ELSE IF (UPLO.EQ.'L') THEN
            READ (NIN,*) ((A(I,J),J=1,I),I=1,N)
         END IF
*
*        Estimate condition number
*
         CALL STRCON(NORM,UPLO,DIAG,N,A,LDA,RCOND,WORK,IWORK,INFO)
*
         WRITE (NOUT,*)
         IF (RCOND.GE.X02AJE()) THEN
            WRITE (NOUT,99999) 'Estimate of condition number =',
     +        1.0/RCOND
         ELSE
            WRITE (NOUT,*) 'A is singular to working precision'
         END IF
      END IF
      STOP
*
99999 FORMAT (1X,A,1P,E10.2)
      END
