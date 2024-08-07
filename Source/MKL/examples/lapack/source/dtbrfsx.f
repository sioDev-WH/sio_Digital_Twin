*     DTBRFS (F07VHF) Example Program Text
*     Mark 15 Release. NAG Copyright 1991.
*     .. Parameters ..
      INTEGER          NIN, NOUT
      PARAMETER        (NIN=5,NOUT=6)
      INTEGER          NMAX, KDMAX, LDAB, NRHMAX, LDB, LDX
      PARAMETER        (NMAX=8,KDMAX=NMAX,LDAB=KDMAX+1,NRHMAX=NMAX,
     +                 LDB=NMAX,LDX=NMAX)
      CHARACTER        TRANS, DIAG
      PARAMETER        (TRANS='N',DIAG='N')
*     .. Local Scalars ..
      INTEGER          I, IFAIL, INFO, J, KD, N, NRHS
      CHARACTER        UPLO
*     .. Local Arrays ..
      DOUBLE PRECISION AB(LDAB,NMAX), B(LDB,NRHMAX), BERR(NRHMAX),
     +                 FERR(NRHMAX), WORK(3*NMAX), X(LDX,NMAX)
      INTEGER          IWORK(NMAX)
*     .. External Subroutines ..
      EXTERNAL         F06QFF, DTBRFS, DTBTRS, X04CAF
*     .. Intrinsic Functions ..
      INTRINSIC        MAX, MIN
*     .. Executable Statements ..
      WRITE (NOUT,*) 'DTBRFS Example Program Results'
*     Skip heading in data file
      READ (NIN,*)
      READ (NIN,*) N, KD, NRHS
      IF (N.LE.NMAX .AND. KD.LE.KDMAX .AND. NRHS.LE.NRHMAX) THEN
*
*        Read A and B from data file, and copy B to X
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
         READ (NIN,*) ((B(I,J),J=1,NRHS),I=1,N)
*
         CALL F06QFF('General',N,NRHS,B,LDB,X,LDX)
*
*        Compute solution in the array X
*
         CALL DTBTRS(UPLO,TRANS,DIAG,N,KD,NRHS,AB,LDAB,X,LDX,INFO)
*
*        Compute backward errors and estimated bounds on the
*        forward errors
*
         CALL DTBRFS(UPLO,TRANS,DIAG,N,KD,NRHS,AB,LDAB,B,LDB,X,LDX,FERR,
     +               BERR,WORK,IWORK,INFO)
*
*        Print solution
*
         WRITE (NOUT,*)
         IFAIL = 0
         CALL X04CAF('General',' ',N,NRHS,X,LDX,'Solution(s)',IFAIL)
         WRITE (NOUT,*)
         WRITE (NOUT,*) 'Backward errors (machine-dependent)'
         WRITE (NOUT,99999) (BERR(J),J=1,NRHS)
         WRITE (NOUT,*)
     +     'Estimated forward error bounds (machine-dependent)'
         WRITE (NOUT,99999) (FERR(J),J=1,NRHS)
      END IF
      STOP
*
99999 FORMAT ((3X,1P,7D11.1))
      END
