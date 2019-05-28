*     SPPTRI (F07GJE) Example Program Text
*     Mark 15 Release. NAG Copyright 1991.
*     .. Parameters ..
      INTEGER          NIN, NOUT
      PARAMETER        (NIN=5,NOUT=6)
      INTEGER          NMAX
      PARAMETER        (NMAX=8)
*     .. Local Scalars ..
      INTEGER          I, IFAIL, INFO, J, N
      CHARACTER        UPLO
*     .. Local Arrays ..
      REAL             AP(NMAX*(NMAX+1)/2)
*     .. External Subroutines ..
      EXTERNAL         SPPTRF, SPPTRI, X04CCE
*     .. Executable Statements ..
      WRITE (NOUT,*) 'SPPTRI Example Program Results'
*     Skip heading in data file
      READ (NIN,*)
      READ (NIN,*) N
      IF (N.LE.NMAX) THEN
*
*        Read A from data file
*
         READ (NIN,*) UPLO
         IF (UPLO.EQ.'U') THEN
            READ (NIN,*) ((AP(I+J*(J-1)/2),J=I,N),I=1,N)
         ELSE IF (UPLO.EQ.'L') THEN
            READ (NIN,*) ((AP(I+(2*N-J)*(J-1)/2),J=1,I),I=1,N)
         END IF
*
*        Factorize A
*
         CALL SPPTRF(UPLO,N,AP,INFO)
*
         WRITE (NOUT,*)
         IF (INFO.EQ.0) THEN
*
*           Compute inverse of A
*
            CALL SPPTRI(UPLO,N,AP,INFO)
*
*           Print inverse
*
            IFAIL = 0
*
            CALL X04CCE(UPLO,'Nonunit',N,AP,'Inverse',IFAIL)
*
         ELSE
            WRITE (NOUT,*) 'A is not positive-definite'
         END IF
      END IF
      STOP
*
      END
