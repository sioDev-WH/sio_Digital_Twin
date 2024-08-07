*     CPBTRF (F07HRE) Example Program Text
*     Mark 15 Release. NAG Copyright 1991.
*     .. Parameters ..
      INTEGER          NIN, NOUT
      PARAMETER        (NIN=5,NOUT=6)
      INTEGER          NMAX, KMAX, LDAB
      PARAMETER        (NMAX=8,KMAX=8,LDAB=KMAX+1)
*     .. Local Scalars ..
      INTEGER          I, IFAIL, INFO, J, KD, N
      CHARACTER        UPLO
*     .. Local Arrays ..
      COMPLEX          AB(LDAB,NMAX)
      CHARACTER        CLABS(1), RLABS(1)
*     .. External Subroutines ..
      EXTERNAL         CPBTRF, X04DFE
*     .. Intrinsic Functions ..
      INTRINSIC        MAX, MIN
*     .. Executable Statements ..
      WRITE (NOUT,*) 'CPBTRF Example Program Results'
*     Skip heading in data file
      READ (NIN,*)
      READ (NIN,*) N, KD
      IF (N.LE.NMAX .AND. KD.LE.KMAX) THEN
*
*        Read A from data file
*
         READ (NIN,*) UPLO
         IF (UPLO.EQ.'U') THEN
            DO 20 I = 1, N
               READ (NIN,*) (AB(KD+1+I-J,J),J=I,MIN(N,I+KD))
   20       CONTINUE
         ELSE IF (UPLO.EQ.'L') THEN
            DO 40 I = 1, N
               READ (NIN,*) (AB(1+I-J,J),J=MAX(1,I-KD),I)
   40       CONTINUE
         END IF
*
*        Factorize A
*
         CALL CPBTRF(UPLO,N,KD,AB,LDAB,INFO)
*
         WRITE (NOUT,*)
         IF (INFO.EQ.0) THEN
*
*           Print factor
*
            IFAIL = 0
            IF (UPLO.EQ.'U') THEN
*
               CALL X04DFE(N,N,0,KD,AB,LDAB,'Bracketed','F7.4','Factor',
     +                     'Integer',RLABS,'Integer',CLABS,80,0,IFAIL)
*
            ELSE IF (UPLO.EQ.'L') THEN
*
               CALL X04DFE(N,N,KD,0,AB,LDAB,'Bracketed','F7.4','Factor',
     +                     'Integer',RLABS,'Integer',CLABS,80,0,IFAIL)
*
            END IF
*
         ELSE
            WRITE (NOUT,*) 'A is not positive-definite'
         END IF
      END IF
      STOP
*
      END
