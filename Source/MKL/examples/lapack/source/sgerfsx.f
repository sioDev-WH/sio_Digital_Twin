*     SGERFS (F07AHE) Example Program Text
*     Mark 15 Release. NAG Copyright 1991.
*     .. Parameters ..
      INTEGER          NIN, NOUT
      PARAMETER        (NIN=5,NOUT=6)
      INTEGER          NMAX, NRHMAX, LDA, LDAF, LDB, LDX
      PARAMETER        (NMAX=8,NRHMAX=NMAX,LDA=NMAX,LDAF=NMAX,LDB=NMAX,
     +                 LDX=NMAX)
      CHARACTER        TRANS
      PARAMETER        (TRANS='N')
*     .. Local Scalars ..
      INTEGER          I, IFAIL, INFO, J, N, NRHS
*     .. Local Arrays ..
      REAL             A(LDA,NMAX), AF(LDAF,NMAX), B(LDB,NRHMAX),
     +                 BERR(NRHMAX), FERR(NRHMAX), WORK(3*NMAX),
     +                 X(LDX,NMAX)
      INTEGER          IPIV(NMAX), IWORK(NMAX)
*     .. External Subroutines ..
      EXTERNAL         F06QFE, SGERFS, SGETRF, SGETRS, X04CAE
*     .. Executable Statements ..
      WRITE (NOUT,*) 'SGERFS Example Program Results'
*     Skip heading in data file
      READ (NIN,*)
      READ (NIN,*) N, NRHS
      IF (N.LE.NMAX .AND. NRHS.LE.NRHMAX) THEN
*
*        Read A and B from data file, and copy A to AF and B to X
*
         READ (NIN,*) ((A(I,J),J=1,N),I=1,N)
         READ (NIN,*) ((B(I,J),J=1,NRHS),I=1,N)
*
         CALL F06QFE('General',N,N,A,LDA,AF,LDAF)
*
         CALL F06QFE('General',N,NRHS,B,LDB,X,LDX)
*
*        Factorize A in the array AF
*
         CALL SGETRF(N,N,AF,LDAF,IPIV,INFO)
*
         WRITE (NOUT,*)
         IF (INFO.EQ.0) THEN
*
*           Compute solution in the array X
*
            CALL SGETRS(TRANS,N,NRHS,AF,LDAF,IPIV,X,LDX,INFO)
*
*           Improve solution, and compute backward errors and
*           estimated bounds on the forward errors
*
            CALL SGERFS(TRANS,N,NRHS,A,LDA,AF,LDAF,IPIV,B,LDB,X,LDX,
     +                  FERR,BERR,WORK,IWORK,INFO)
*
*           Print solution
*
            IFAIL = 0
*
            CALL X04CAE('General',' ',N,NRHS,X,LDX,'Solution(s)',IFAIL)
*
            WRITE (NOUT,*)
            WRITE (NOUT,*) 'Backward errors (machine-dependent)'
            WRITE (NOUT,99999) (BERR(J),J=1,NRHS)
            WRITE (NOUT,*)
     +        'Estimated forward error bounds (machine-dependent)'
            WRITE (NOUT,99999) (FERR(J),J=1,NRHS)
         ELSE
            WRITE (NOUT,*) 'The factor U is singular'
         END IF
      END IF
      STOP
*
99999 FORMAT ((3X,1P,7E11.1))
      END
