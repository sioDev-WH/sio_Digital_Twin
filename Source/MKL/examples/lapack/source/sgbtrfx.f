*     SGBTRF (F07BDE) Example Program Text
*     Mark 15 Release. NAG Copyright 1991.
*     .. Parameters ..
      INTEGER          NIN, NOUT
      PARAMETER        (NIN=5,NOUT=6)
      INTEGER          MMAX, NMAX, KLMAX, KUMAX, LDAB
      PARAMETER        (MMAX=8,NMAX=8,KLMAX=8,KUMAX=8,
     +                 LDAB=2*KLMAX+KUMAX+1)
*     .. Local Scalars ..
      INTEGER          I, IFAIL, INFO, J, K, KL, KU, M, N
*     .. Local Arrays ..
      REAL             AB(LDAB,NMAX)
      INTEGER          IPIV(NMAX)
*     .. External Subroutines ..
      EXTERNAL         SGBTRF, X04CEE
*     .. Intrinsic Functions ..
      INTRINSIC        MAX, MIN
*     .. Executable Statements ..
      WRITE (NOUT,*) 'SGBTRF Example Program Results'
*     Skip heading in data file
      READ (NIN,*)
      READ (NIN,*) M, N, KL, KU
      IF (M.LE.MMAX .AND. N.LE.NMAX .AND. KL.LE.KLMAX .AND. KU.LE.KUMAX)
     +    THEN
*
*        Read A from data file
*
         K = KL + KU + 1
         READ (NIN,*) ((AB(K+I-J,J),J=MAX(I-KL,1),MIN(I+KU,N)),I=1,
     +     M)
*
*        Factorize A
*
         CALL SGBTRF(M,N,KL,KU,AB,LDAB,IPIV,INFO)
*
*        Print details of factorization
*
         WRITE (NOUT,*)
         IFAIL = 0
*
         CALL X04CEE(M,N,KL,KL+KU,AB,LDAB,'Details of factorization',
     +               IFAIL)
*
*        Print pivot indices
*
         WRITE (NOUT,*)
         WRITE (NOUT,*) 'IPIV'
         WRITE (NOUT,99999) (IPIV(I),I=1,MIN(M,N))
*
         IF (INFO.NE.0) WRITE (NOUT,*) 'The factor U is singular'
*
      END IF
      STOP
*
99999 FORMAT ((3X,7I11))
      END
