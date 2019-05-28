#include <stdio.h>
#include <math.h>

#include "mkl_example.h"

int MaxValue(int n, int *x) 
{
      int   i, indmax;

      indmax = x[0];
      for (i = 1; i < n; i++)
          if (indmax < x[i]) 
              indmax = x[i];
      return(indmax);     
} /* MaxValue */

void GetVectorI(FILE *in_file, int n, int *x) 
{
      int   i;

      for (i = 0; i < n; i++)
          fscanf(in_file,"%d", x+i);
      fseek(in_file,30,1);
      return;     
} /* GetVectorI */

void GetVectorS(FILE *in_file, int n, float *x,  int incx) 
{
      int   i;

      for (i = 0; i < (1+(n-1)*abs(incx)); i++)
          fscanf(in_file,"%f", x+i);
      fseek(in_file,24,1);
      return;     
} /* GetVectorS */

void GetVectorD(FILE *in_file, int n, double *x,  int incx) 
{
      int    i;

      for (i = 0; i < (1+(n-1)*abs(incx)); i++)
          fscanf(in_file,"%lf", x+i);
      fseek(in_file,24,1);
      return;     
} /* GetVectorD */

void GetVectorC(FILE *in_file, int n, MKL_Complex8 *x,  int incx) 
{
      int    i;

      for (i = 0; i < (1+(n-1)*abs(incx)); i++)
          fscanf(in_file,"%f %f", &((x+i)->real), &((x+i)->imag));
      fseek(in_file,23,1);
      return;     
} /* GetVectorC */

void GetVectorZ(FILE *in_file, int n, MKL_Complex16 *x,  int incx) 
{
      int    i;

      for (i = 0; i < (1+(n-1)*abs(incx)); i++)
          fscanf(in_file,"%lf %lf", &((x+i)->real), &((x+i)->imag));
      fseek(in_file,23,1);
      return;     
} /* GetVectorZ */

void GetArrayS(FILE *in_file, CBLAS_ORDER *order, int flag, int *m, int *n,
               float *a,  int *lda) 
{
          int         i, j;
          float       *addr;

          if (*order == CblasRowMajor) {
            if (flag == 0) {
              for (i = 0; i < (*m); i++) {
                addr = a + i*(*lda);
                for (j = 0; j < (*n); j++)
                   fscanf(in_file,"%f", addr+j);
              } /* for */
            } else if (flag == 1) {
              for (i = 0; i < (*m); i++) {
                addr = a + i*(*lda);
                for (j = i; j < (*n); j++)
                   fscanf(in_file,"%f", addr+j);
              } /* for */
            } else if (flag == -1) {
              for (i = 0; i < (*m); i++) {
                addr = a + i*(*lda);
                for (j = 0; j <= i; j++)
                   fscanf(in_file,"%f", addr+j);
              } /* for */
            } /* if */
          } else if (*order == CblasColMajor) {
            if (flag == 0) {
              for (j = 0; j < (*n); j++) {
                addr = a + j*(*lda);
                for (i = 0; i < (*m); i++)
                  fscanf(in_file,"%f", addr+i);
              } /* for */
            } else if (flag == 1) {
              for (j = 0; j < (*n); j++) {
                addr = a + j*(*lda);
                for (i = 0; i <= j; i++)
                   fscanf(in_file,"%f", addr+i);
              } /* for */
            } else if (flag == -1) {
              for (j = 0; j < (*n); j++) {
                addr = a + j*(*lda);
                for (i = j; i < (*m); i++)
                   fscanf(in_file,"%f", addr+i);
              } /* for */
            } /* if */
          } /* if */
          fseek(in_file,22,1);
          return;         
} /* GetArrayS */

void GetArrayD(FILE *in_file, CBLAS_ORDER *order, int flag, int *m, int *n,
               double *a,  int *lda) 
{
          int         i, j;
          double      *addr;

          if (*order == CblasRowMajor) {
            if (flag == 0) {
              for (i = 0; i < (*m); i++) {
                addr = a + i*(*lda);
                for (j = 0; j < (*n); j++)
                  fscanf(in_file,"%lf", addr+j);
              } /* for */
            } else if (flag == 1) {
              for (i = 0; i < (*m); i++) {
                  addr = a + i*(*lda);
                  for (j = i; j < (*n); j++)
                      fscanf(in_file,"%lf", addr+j);
              } /* for */
            } else if (flag == -1) {
              for (i = 0; i < (*m); i++) {
                  addr = a + i*(*lda);
                  for (j = 0; j <= i; j++)
                      fscanf(in_file,"%lf", addr+j);
              } /* for */
            } /* if */
          } else if (*order == CblasColMajor) {
            if (flag == 0) {
                for (j = 0; j < (*n); j++) {
                    addr = a + j*(*lda);
                    for (i = 0; i < (*m); i++)
                        fscanf(in_file,"%lf", addr+i);
                } /* for */
            } else if (flag == 1) {
                for (j = 0; j < (*n); j++) {
                    addr = a + j*(*lda);
                    for (i = 0; i <= j; i++)
                        fscanf(in_file,"%lf", addr+i);
                } /* for */
            } else if (flag == -1) {
                for (j = 0; j < (*n); j++) {
                    addr = a + j*(*lda);
                    for (i = j; i < (*m); i++)
                        fscanf(in_file,"%lf", addr+i);
                } /* for */
            } /* if */
          } /* if */
          fseek(in_file,22,1);
          return;         
} /* GetArrayD */

void GetArrayC(FILE *in_file, CBLAS_ORDER *order, int flag, int *m, int *n,
               MKL_Complex8 *a,  int *lda) 
{
      int         i, j;
      MKL_Complex8    *addr;

      if (*order == CblasRowMajor) {
          if (flag == 0) {
              for (i = 0; i < (*m); i++) {
                  addr = a + i*(*lda);
                  for (j = 0; j < (*n); j++)
                      fscanf(in_file,"%f %f", &((addr+j)->real),
                             &((addr+j)->imag));
              } /* for */
          } else if (flag == 1) {
              for (i = 0; i < (*m); i++) {
                  addr = a + i*(*lda);
                  for (j = i; j < (*n); j++)
                      fscanf(in_file,"%f %f", &((addr+j)->real),
                             &((addr+j)->imag));
              } /* for */
          } else if (flag == -1) {
              for (i = 0; i < (*m); i++) {
                  addr = a + i*(*lda);
                  for (j = 0; j <= i; j++)
                      fscanf(in_file,"%f %f", &((addr+j)->real),
                             &((addr+j)->imag));
              } /* for */
          } /* if */
      } else if (*order == CblasColMajor) {
          if (flag == 0) {
              for (j = 0; j < (*n); j++) {
                  addr = a + j*(*lda);
                  for (i = 0; i < (*m); i++)
                      fscanf(in_file,"%f %f", &((addr+i)->real),
                             &((addr+i)->imag));
              } /* for */
          } else if (flag == 1) {
              for (j = 0; j < (*n); j++) {
                  addr = a + j*(*lda);
                  for (i = 0; i <= j; i++)
                      fscanf(in_file,"%f %f", &((addr+i)->real),
                             &((addr+i)->imag));
              } /* for */
          } else if (flag == -1) {
              for (j = 0; j < (*n); j++) {
                  addr = a + j*(*lda);
                  for (i = j; i < (*m); i++)
                      fscanf(in_file,"%f %f", &((addr+i)->real),
                             &((addr+i)->imag));
              } /* for */
          } /* if */
      } /* if */
      fseek(in_file,22,1);
      return;     
} /* GetArrayC */

void GetArrayZ(FILE *in_file, CBLAS_ORDER *order, int flag,
               int *m, int *n, MKL_Complex16 *a,  int *lda) 
{
      int          i, j;
      MKL_Complex16    *addr;

      if (*order == CblasRowMajor) {
          if (flag == 0) {
              for (i = 0; i < (*m); i++) {
                  addr = a + i*(*lda);
                  for (j = 0; j < (*n); j++)
                      fscanf(in_file,"%lf %lf", &((addr+j)->real),
                             &((addr+j)->imag));
              } /* for */
          } else if (flag == 1) {
              for (i = 0; i < (*m); i++) {
                  addr = a + i*(*lda);
                  for (j = i; j < (*n); j++)
                      fscanf(in_file,"%lf %lf", &((addr+j)->real),
                             &((addr+j)->imag));
              } /* for */
          } else if (flag == -1) {
              for (i = 0; i < (*m); i++) {
                  addr = a + i*(*lda);
                  for (j = 0; j <= i; j++)
                      fscanf(in_file,"%lf %lf", &((addr+j)->real),
                             &((addr+j)->imag));
              } /* for */
          } /* if */
      } else if(*order == CblasColMajor) {
          if (flag == 0) {
              for (j = 0; j < (*n); j++) {
                  addr = a + j*(*lda);
                  for (i = 0; i < (*m); i++)
                      fscanf(in_file,"%lf %lf", &((addr+i)->real),
                             &((addr+i)->imag));
              } /* for */
          } else if (flag == 1) {
              for (j = 0; j < (*n); j++) {
                  addr = a + j*(*lda);
                  for (i = 0; i <= j; i++)
                      fscanf(in_file,"%lf %lf", &((addr+i)->real),
                             &((addr+i)->imag));
              } /* for */
          } else if (flag == -1) {
              for (j = 0; j < (*n); j++) {
                  addr = a + j*(*lda);
                  for (i = j; i < (*m); i++)
                      fscanf(in_file,"%lf %lf", &((addr+i)->real),
                             &((addr+i)->imag));
              } /* for */
          } /* if */
      } /* if */
      fseek(in_file,22,1);
      return;     
} /* GetArrayZ */

void GetBandArrayS(FILE *in_file, CBLAS_ORDER *order, int kl, int ku,
                   int m, int n, float *a,  int lda) 
{
      int         i, j, k1, k2, ku1, kl1;
      float      *addr;

      if (*order == CblasRowMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
          for (i=0; i < ku1+1; i++) {
              if ((ku1-i+m) >= n) k1 = n;
              else k1 = ku1-i+m;
                          addr = a+(ku-ku1+i)*lda;
              for (j = ku1-i; j < k1; j++)
                  fscanf(in_file, "%f ", (addr+j));
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              if ((m+ku1-i) >= n) k1 = n;
              else  k1 = m+ku1-i;
                          addr = a+(ku-ku1+i)*lda;
              for (j = 0; j < k1; j++)
                  fscanf(in_file, "%f ", (addr+j));
          } /* for */
      } else if (*order == CblasColMajor) {
           k1 = ku;
           k2 = kl;
           for (i = 0; i < n; i++) {
               addr = a + i*lda;
               for (j = k1; j < ku+1; j++)
                   fscanf(in_file,"%f", (addr+j));
               if (k1 > 0) k1 = k1-1;
               addr = addr+ku+1;
               if ((i+kl) < m) k2 = kl;
               else  k2 = k2-1;
               for (j = 0; j < k2; j++)
                   fscanf(in_file,"%f", (addr+j));
           } /* for */
      } /* if */
      fseek(in_file,22,1);
      return;     
} /* GetBandArrayS */

void GetBandArrayC(FILE *in_file, CBLAS_ORDER *order, int kl, int ku,
                   int m, int n, MKL_Complex8 *a,  int lda) 
{
      int         i, j, k1, k2, ku1, kl1;
      MKL_Complex8    *addr;

      if (*order == CblasRowMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
          for (i=0; i < ku1+1; i++) {
              if ((ku1-i+m) >= n) k1 = n;
              else k1 = ku1-i+m;
                          addr = a+(ku-ku1+i)*lda;
              for (j = ku1-i; j < k1; j++)
                  fscanf(in_file, "%f %f ", &((addr+j)->real), &((addr+j)->imag));
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              if ((m+ku1-i) >= n) k1 = n;
              else  k1 = m+ku1-i;
                          addr = a+(ku-ku1+i)*lda;
              for (j = 0; j < k1; j++)
                  fscanf(in_file, "%f %f ", &((addr+j)->real), &((addr+j)->imag));
          } /* for */
      } else if (*order == CblasColMajor) {
           k1 = ku;
           k2 = kl;
           for (i = 0; i < n; i++) {
               addr = a + i*lda;
               for (j = k1; j < ku+1; j++)
                  fscanf(in_file, "%f %f ", &((addr+j)->real), &((addr+j)->imag));
               if (k1 > 0) k1 = k1-1;
               addr = addr+ku+1;
               if ((i+kl) < m) k2 = kl;
               else  k2 = k2-1;
               for (j = 0; j < k2; j++)
                  fscanf(in_file, "%f %f ", &((addr+j)->real), &((addr+j)->imag));
           } /* for */
      } /* if */
      fseek(in_file,22,1);
      return;     
} /* GetBandArrayC */

void GetBandArrayD(FILE *in_file, CBLAS_ORDER *order, int kl, int ku,
                   int m, int n, double *a,  int lda) 
{
      int         i, j, k1, k2, ku1, kl1;
      double     *addr;

      if (*order == CblasRowMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
          for (i=0; i < ku1+1; i++) {
              if ((ku1-i+m) >= n) k1 = n;
              else k1 = ku1-i+m;
                          addr = a+(ku-ku1+i)*lda;
              for (j = ku1-i; j < k1; j++)
                  fscanf(in_file, "%lf ", (addr+j));
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              if ((m+ku1-i) >= n) k1 = n;
              else  k1 = m+ku1-i;
                          addr = a+(ku-ku1+i)*lda;
              for (j = 0; j < k1; j++)
                  fscanf(in_file, "%lf ", (addr+j));
          } /* for */
      } else if (*order == CblasColMajor) {
           k1 = ku;
           k2 = kl;
           for (i = 0; i < n; i++) {
               addr = a + i*lda;
               for (j = k1; j < ku+1; j++)
                   fscanf(in_file,"%lf ", (addr+j));
               if (k1 > 0) k1 = k1-1;
               addr = addr+ku+1;
               if ((i+kl) < m) k2 = kl;
               else  k2 = k2-1;
               for (j = 0; j < k2; j++)
                   fscanf(in_file,"%lf ", (addr+j));
           } /* for */
      } /* if */
      fseek(in_file,22,1);
      return;     
} /* GetBandArrayD */

void GetBandArrayZ(FILE *in_file, CBLAS_ORDER *order, int kl, int ku,
                   int m, int n, MKL_Complex16 *a,  int lda) 
{
      int         i, j, k1, k2, ku1, kl1;
      MKL_Complex16   *addr;

      if (*order == CblasRowMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
          for (i=0; i < ku1+1; i++) {
              if ((ku1-i+m) >= n) k1 = n;
              else k1 = ku1-i+m;
                          addr = a+(ku-ku1+i)*lda;
              for (j = ku1-i; j < k1; j++)
                  fscanf(in_file, "%lf %lf ", &((addr+j)->real), &((addr+j)->imag));
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              if ((m+ku1-i) >= n) k1 = n;
              else  k1 = m+ku1-i;
                          addr = a+(ku-ku1+i)*lda;
              for (j = 0; j < k1; j++)
                  fscanf(in_file, "%lf %lf ", &((addr+j)->real), &((addr+j)->imag));
          } /* for */
      } else if (*order == CblasColMajor) {
           k1 = ku;
           k2 = kl;
           for (i = 0; i < n; i++) {
               addr = a + i*lda;
               for (j = k1; j < ku+1; j++)
                  fscanf(in_file, "%lf %lf ", &((addr+j)->real), &((addr+j)->imag));
               if (k1 > 0) k1 = k1-1;
               addr = addr+ku+1;
               if ((i+kl) < m) k2 = kl;
               else  k2 = k2-1;
               for (j = 0; j < k2; j++)
                  fscanf(in_file, "%lf %lf ", &((addr+j)->real), &((addr+j)->imag));
           } /* for */
      } /* if */
      fseek(in_file,22,1);
      return;     
} /* GetBandArrayZ */

void PrintSide(CBLAS_SIDE *side, CBLAS_UPLO *uplo, CBLAS_DIAG *diag)
{
       printf("\n       ");
       if (side != NULL)
           if (*side == CblasLeft)
              printf("SIDE = CblasLeft  ");
           else if (*side == CblasRight)
              printf("SIDE = CblasRight  ");
       if (uplo != NULL)
           if (*uplo == CblasUpper)
              printf("UPLO = CblasUpper  ");
           else if (*uplo == CblasLower)
              printf("UPLO = CblasLower  ");
       if (diag != NULL)
           if (*diag == CblasUnit)
              printf("DIAG=CblasUnit");
           else if (*diag == CblasNonUnit)
              printf("DIAG = CblasNonUnit");
      return;     
} /* PrintSide */

void PrintTrans(int count, CBLAS_TRANSPOSE *trans1,
                                CBLAS_TRANSPOSE *trans2)
{
      printf("\n       ");
      switch(count) {
      case 1:
        if (*trans1 == CblasNoTrans)
           printf("TRANS = CblasNoTrans");
        else if (*trans1 == CblasTrans)
           printf("TRANS = CblasTrans");
        else if (*trans1 == CblasConjTrans)
           printf("TRANS = CblasConjTrans");
        break;
      case 2:
        if (*trans1 == CblasNoTrans)
           printf("TRANSA = CblasNoTrans");
        else if (*trans1 == CblasTrans)
           printf("TRANSA = CblasTrans");
        else if (*trans1 == CblasConjTrans)
           printf("TRANSA = CblasConjTrans");
        if (*trans2 == CblasNoTrans)
           printf("  TRANSB = CblasNoTrans");
        else if (*trans2 == CblasTrans)
           printf("  TRANSB = CblasTrans");
        else if (*trans2 == CblasConjTrans)
           printf("  TRANSB = CblasConjTrans");
        break;
      default:
        break;
      } /* switch */
      return;     
} /* PrintTrans */

void PrintOrder(CBLAS_ORDER *order)
{
      if (*order == CblasRowMajor)
           printf("\n       ORDER = CblasRowMajor");
      else if (*order == CblasColMajor)
           printf("\n       ORDER = CblasColMajor");
      return;     
} /* PrintOrder */

void PrintVectorI(int n, int *x, char *name)
{
      int     i;

      printf("\n       VECTOR %s\n         ", name);
      for (i = 0; i < n; i++)
          printf("%3d  ", *(x+i));
      return;     
} /* PrintVectorI */

void PrintVectorS(int flag, int n, float *x,  int incx, char *name)
{
      int     i;

      switch(flag) {
      case 0:
           printf("\n       VECTOR %s   INC%s=%1d\n         ",
                    name, name, incx);
           break;
      case 1:
           printf("\n       VECTOR %s\n         ", name);
           break;
      default:
           break;
      } /* switch */
      for (i = 0; i < (1+(n-1)*abs(incx)); i++)
          printf("%6.2f  ", *(x+i));
      return;     
} /* PrintVectorS */
 
void PrintVectorD(int flag, int n, double *x,  int incx, char *name)
{
      int     i;

      switch(flag) {
      case 0:
           printf("\n       VECTOR %s   INC%s=%1d\n         ",
                    name, name, incx);
           break;
      case 1:
           printf("\n       VECTOR %s\n         ", name);
           break;
      default:
           break;
      } /* switch */
      for (i = 0; i < (1+(n-1)*abs(incx)); i++)
          printf("%8.3f  ", *(x+i));
      return;     
} /* PrintVectorD */

void PrintVectorC(int flag, int n, MKL_Complex8 *x,  int incx, char *name)
{
      int     i;

      switch(flag) {
      case 0:
           printf("\n       VECTOR %s   INC%s=%1d\n         ",
                    name, name, incx);
           break;
      case 1:
           printf("\n       VECTOR %s\n         ", name);
           break;
      default:
           break;
      } /* switch */
      for (i = 0; i < (1+(n-1)*abs(incx)); i++)
          printf("%6.2f,%6.2f   ", (x+i)->real, (x+i)->imag);
      return;     
} /* PrintVectorC */

void PrintVectorZ(int flag, int n, MKL_Complex16 *x,  int incx, char *name)
{
      int     i;

      switch(flag) {
      case 0:
           printf("\n       VECTOR %s   INC%s=%1d\n         ",
                    name, name, incx);
               break;
      case 1:
           printf("\n       VECTOR %s\n         ", name);
               break;
      default:
               break;
      } /* switch */
      for (i = 0; i < (1+(n-1)*abs(incx)); i++)
          printf("%6.2f,%6.2f   ", (x+i)->real, (x+i)->imag);
      return;     
} /* PrintVectorZ */

void PrintArrayS(CBLAS_ORDER *order, int flag1, int flag2, int *m, int *n, float *a, 
                int *lda, char *name)
{
        int     i, j;
        float   *addr;

        switch(flag1) {
        case 0:
            printf("\n       ARRAY %s   LD%s=%1d",
                    name, name, *lda);
            break;
        case 1:
            printf("\n       ARRAY %s", name);
            break;
        default:
            break;
        } /* switch */
        if (*order == CblasRowMajor) {
            if (flag2 == 0) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j = 0; j < (*n); j++)
                        printf("%6.2f  ", *(addr+j));
                } /* for */
            } else if (flag2 == 1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j=0; j < i; j++)
                        printf("        ");
                    for (j = i; j < (*n); j++)
                        printf("%6.2f  ", *(addr+j));
                } /* for */
            } else if (flag2 == -1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j = 0; j <= i; j++)
                        printf("%6.2f  ", *(addr+j));
                } /* for */
            } /* if */
        } else if (*order == CblasColMajor) {
            if (flag2 == 0) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j = 0; j < (*n); j++)
                        printf("%6.2f  ", *(addr+j*(*lda)));
                } /* for */
            } else if (flag2 == 1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j=0; j < i; j++)
                        printf("        ");
                    for (j = i; j < (*n); j++)
                        printf("%6.2f  ", *(addr+j*(*lda)));
                } /* for */
            } else if (flag2 == -1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j = 0; j <= i; j++)
                        printf("%6.2f  ", *(addr+j*(*lda)));
                } /* for */
            } /* if */
        } /* if */
        return;   
} /* PrintArrayS */

void PrintArrayD(CBLAS_ORDER *order, int flag1, int flag2, int *m, int *n, double *a, 
                int *lda, char *name)
{
        int     i, j;
        double  *addr;

        switch(flag1) {
        case 0:
            printf("\n       ARRAY %s   LD%s=%1d",
                    name, name, *lda);
            break;
        case 1:
            printf("\n       ARRAY %s", name);
            break;
        default:
            break;
        } /* switch */
        if (*order == CblasRowMajor) {
            if (flag2 == 0) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j = 0; j < (*n); j++)
                        printf("%8.3f  ", *(addr+j));
                } /* for */
            } else if (flag2 == 1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j=0; j < i; j++)
                        printf("          ");
                    for (j = i; j < (*n); j++)
                        printf("%8.3f  ", *(addr+j));
                } /* for */
            } else if (flag2 == -1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j = 0; j <= i; j++)
                        printf("%8.3f  ", *(addr+j));
                } /* for */
            } /* if */
        } else if (*order == CblasColMajor) {
            if (flag2 == 0) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j = 0; j < (*n); j++)
                        printf("%8.3f  ", *(addr+j*(*lda)));
                } /* for */
            } else if (flag2 == 1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j=0; j < i; j++)
                        printf("          ");
                    for (j = i; j < (*n); j++)
                        printf("%8.3f  ", *(addr+j*(*lda)));
                } /* for */
            } else if (flag2 == -1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j = 0; j <= i; j++)
                        printf("%8.3f  ", *(addr+j*(*lda)));
                } /* for */
            } /* if */
        } /* if */
        return;   
} /* PrintArrayD */

void PrintArrayC(CBLAS_ORDER *order, int flag1, int flag2, int *m, int *n, MKL_Complex8 *a, 
                int *lda, char *name)
{
        int      i, j;
        MKL_Complex8 *addr;

        switch(flag1) {
        case 0:
            printf("\n       ARRAY %s   LD%s=%1d",
                    name, name, *lda);
            break;
        case 1:
            printf("\n       ARRAY %s", name);
            break;
        default:
            break;
        } /* switch */
        if (*order == CblasRowMajor) {
            if (flag2 == 0) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j = 0; j < (*n); j++)
                        printf("%6.2f,%6.2f   ", (addr+j)->real, (addr+j)->imag);
                } /* for */
            } else if (flag2 == 1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j=0; j < i; j++)
                        printf("                ");
                    for (j = i; j < (*n); j++)
                        printf("%6.2f,%6.2f   ", (addr+j)->real, (addr+j)->imag);
                } /* for */
            } else if (flag2 == -1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j = 0; j <= i; j++)
                        printf("%6.2f,%6.2f   ", (addr+j)->real, (addr+j)->imag);
                } /* for */
            } /* if */
        } else if(*order == CblasColMajor) {
            if (flag2 == 0) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j = 0; j < (*n); j++)
                        printf("%6.2f,%6.2f   ", (addr+j*(*lda))->real,
                                (addr+j*(*lda))->imag);
                }  /* for */
            } else if (flag2 == 1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j=0; j < i; j++)
                        printf("                ");
                    for (j = i; j < (*n); j++)
                        printf("%6.2f,%6.2f   ", (addr+j*(*lda))->real,
                                (addr+j*(*lda))->imag);
                } /* for */
            } else if (flag2 == -1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j = 0; j <= i; j++)
                        printf("%6.2f,%6.2f   ", (addr+j*(*lda))->real,
                                (addr+j*(*lda))->imag);
                } /* for */
            } /* if */
        } /* if */
        return;   
} /* PrintArrayC */

void PrintArrayZ(CBLAS_ORDER *order, int flag1, int flag2,
                 int *m, int *n, MKL_Complex16 *a, int *lda, char *name)
{
        int       i, j;
        MKL_Complex16 *addr;

        if (flag1 == 0)
            printf("\n       ARRAY %s   LD%s=%1d", name, name, *lda);
        else
            printf("\n       ARRAY %s", name);

        if (*order == CblasRowMajor) {
            if (flag2 == 0) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j = 0; j < (*n); j++)
                        printf("%6.2f,%6.2f   ", (addr+j)->real,
                               (addr+j)->imag);
                } /* for */
            } else if (flag2 == 1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j=0; j < i; j++)
                        printf("                ");
                    for (j = i; j < (*n); j++)
                        printf("%6.2f,%6.2f   ", (addr+j)->real,
                               (addr+j)->imag);
                } /* for */
            } else if (flag2 == -1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i*(*lda);
                    for (j = 0; j <= i; j++)
                        printf("%6.2f,%6.2f   ", (addr+j)->real,
                                (addr+j)->imag);
                } /* for */
            } /* if */
        } else if (*order == CblasColMajor) {
            if (flag2 == 0) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j = 0; j < (*n); j++)
                        printf("%6.2f,%6.2f   ", (addr+j*(*lda))->real,
                                (addr+j*(*lda))->imag);
                } /* for */
            } else if (flag2 == 1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j=0; j < i; j++)
                        printf("                ");
                    for (j = i; j < (*n); j++)
                        printf("%6.2f,%6.2f   ", (addr+j*(*lda))->real,
                                (addr+j*(*lda))->imag);
                } /* for */
            } else if (flag2 == -1) {
                for (i = 0; i < (*m); i++) {
                    printf("\n         ");
                    addr = a + i;
                    for (j = 0; j <= i; j++)
                        printf("%6.2f,%6.2f   ", (addr+j*(*lda))->real,
                                (addr+j*(*lda))->imag);
                } /* for */
            } /* if */
        } /* if */
        return;   
} /* PrintArrayZ */

void PrintBandArrayS(CBLAS_ORDER *order, int flag, int kl, int ku, int m, int n,
                     float *a, int lda, char *name)
{
      int    i, j, k, ku1, kl1, Nrow = 0;
      float *addr;

      if (flag == 0)
          printf("\n       ARRAY %s   LD%s=%1d  KL=%1d  KU=%1d", name, name, lda,
                  kl, ku);
      else
          printf("\n       ARRAY %s   LD%s=%1d", name, name, lda);

      if (*order == CblasRowMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
                  printf("\n       N row");
                  for (i = 0; i < ku+1-n; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
          } /* for */
          for (i=0; i < ku1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + (ku-ku1+i)*lda;
              if ((ku1-i+m) >= n) k = n;
              else k = ku1-i+m;
              for (j = 0; j < ku1-i; j++)
                  printf("        ");
              for (j = ku1-i; j < k; j++)
                  printf("%6.2f  ", *(addr+j));
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + (ku-ku1+i)*lda;
              if ((m+ku1-i) >= n) k = n;
              else  k = m+ku1-i;
              for (j = 0; j < k; j++)
                  printf("%6.2f  ", *(addr+j));
          } /* for */

          } else if (*order == CblasColMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
                  printf("\n       N row");
                  for (i = 0; i < ku+1-n; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
          } /* for */
          for (i=0; i < ku1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + ku-ku1+i;
              if ((ku1-i+m) >= n) k = n;
              else k = ku1-i+m;
              for (j = 0; j < ku1-i; j++)
                  printf("        ");
              for (j = ku1-i; j < k; j++)
                  printf("%6.2f  ", *(addr+j*lda));
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + ku-ku1+i;
              if ((m+ku1-i) >= n) k = n;
              else  k = m+ku1-i;
              for (j = 0; j < k; j++)
                  printf("%6.2f  ", *(addr+j*lda));
          } /* for */
      } /* if */
      return;
} /* PrintBandArrayS */

void PrintBandArrayD(CBLAS_ORDER *order, int flag, int kl, int ku, int m, int n,
                     double *a, int lda, char *name)
{
      int     i, j, k, ku1, kl1, Nrow = 0;
      double *addr;

      if (flag == 0)
          printf("\n       ARRAY %s   LD%s=%1d  KL=%1d  KU=%1d", name, name, lda,
                  kl, ku);
      else
          printf("\n       ARRAY %s   LD%s=%1d", name, name, lda);

      if (*order == CblasRowMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
                  printf("\n       N row");
                  for (i = 0; i < ku+1-n; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
          } /* for */
          for (i=0; i < ku1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + (ku-ku1+i)*lda;
              if ((ku1-i+m) >= n) k = n;
              else k = ku1-i+m;
              for (j = 0; j < ku1-i; j++)
                  printf("          ");
              for (j = ku1-i; j < k; j++)
                  printf("%8.3f  ", *(addr+j));
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + (ku-ku1+i)*lda;
              if ((m+ku1-i) >= n) k = n;
              else  k = m+ku1-i;
              for (j = 0; j < k; j++)
                  printf("%8.3f  ", *(addr+j));
          } /* for */

          } else if (*order == CblasColMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
                  printf("\n       N row");
                  for (i = 0; i < ku+1-n; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
          } /* for */
          for (i=0; i < ku1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + ku-ku1+i;
              if ((ku1-i+m) >= n) k = n;
              else k = ku1-i+m;
              for (j = 0; j < ku1-i; j++)
                  printf("          ");
              for (j = ku1-i; j < k; j++)
                  printf("%8.3f  ", *(addr+j*lda));
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + ku-ku1+i;
              if ((m+ku1-i) >= n) k = n;
              else  k = m+ku1-i;
              for (j = 0; j < k; j++)
                  printf("%8.3f  ", *(addr+j*lda));
          } /* for */
      } /* if */
      return;
} /* PrintBandArrayD */

void PrintBandArrayC(CBLAS_ORDER *order, int flag, int kl, int ku, int m, int n,
                     MKL_Complex8 *a, int lda, char *name)
{
      int      i, j, k, ku1, kl1, Nrow = 0;
      MKL_Complex8 *addr;

      if (flag == 0)
          printf("\n       ARRAY %s   LD%s=%1d  KL=%1d  KU=%1d", name, name, lda,
                  kl, ku);
      else
          printf("\n       ARRAY %s   LD%s=%1d", name, name, lda);

      if (*order == CblasRowMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
                  printf("\n       N row");
                  for (i = 0; i < ku+1-n; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
          } /* for */
          for (i=0; i < ku1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + (ku-ku1+i)*lda;
              if ((ku1-i+m) >= n) k = n;
              else k = ku1-i+m;
              for (j = 0; j < ku1-i; j++)
                  printf("                ");
              for (j = ku1-i; j < k; j++)
                  printf("%6.2f,%6.2f   ", (addr+j)->real, (addr+j)->imag);
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + (ku-ku1+i)*lda;
              if ((m+ku1-i) >= n) k = n;
              else  k = m+ku1-i;
              for (j = 0; j < k; j++)
                  printf("%6.2f,%6.2f   ", (addr+j)->real, (addr+j)->imag);
          } /* for */
      } else if (*order == CblasColMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
                  printf("\n       N row");
                  for (i = 0; i < ku+1-n; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
          } /* for */
          for (i=0; i < ku1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + ku - ku1 + i;
              if ((ku1-i+m) >= n) k = n;
              else k = ku1-i+m;
              for (j = 0; j < ku1-i; j++)
                  printf("                ");
              for (j = ku1-i; j < k; j++)
                  printf("%6.2f,%6.2f   ", (addr+j*lda)->real,
                          (addr+j*lda)->imag);
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + ku - ku1 + i;
              if ((m+ku1-i) >= n) k = n;
              else  k = m+ku1-i;
              for (j = 0; j < k; j++)
                  printf("%6.2f,%6.2f   ", (addr+j*lda)->real,
                          (addr+j*lda)->imag);
          } /* for */
      } /* if */
      return;
} /* PrintBandArrayC */

void PrintBandArrayZ(CBLAS_ORDER *order, int flag, int kl, int ku, int m, int n,
                     MKL_Complex16 *a, int lda, char *name)
{
      int       i, j, k, ku1, kl1, Nrow = 0;
      MKL_Complex16 *addr;

      if (flag == 0)
          printf("\n       ARRAY %s   LD%s=%1d  KL=%1d  KU=%1d", name, name, lda,
                  kl, ku);
      else
          printf("\n       ARRAY %s   LD%s=%1d", name, name, lda);

      if (*order == CblasRowMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
                  printf("\n       N row");
                  for (i = 0; i < ku+1-n; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
          } /* for */
          for (i=0; i < ku1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + (ku-ku1+i)*lda;
              if ((ku1-i+m) >= n) k = n;
              else k = ku1-i+m;
              for (j = 0; j < ku1-i; j++)
                  printf("                ");
              for (j = ku1-i; j < k; j++)
                  printf("%6.2f,%6.2f   ", (addr+j)->real, (addr+j)->imag);
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + (ku-ku1+i)*lda;
              if ((m+ku1-i) >= n) k = n;
              else  k = m+ku1-i;
              for (j = 0; j < k; j++)
                  printf("%6.2f,%6.2f   ", (addr+j)->real, (addr+j)->imag);
          } /* for */
      } else if (*order == CblasColMajor) {
                  if (ku >= n) ku1 = n-1;
                  else  ku1 = ku;
                  printf("\n       N row");
                  for (i = 0; i < ku+1-n; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
          } /* for */
          for (i=0; i < ku1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + ku - ku1 + i;
              if ((ku1-i+m) >= n) k = n;
              else k = ku1-i+m;
              for (j = 0; j < ku1-i; j++)
                  printf("                ");
              for (j = ku1-i; j < k; j++)
                  printf("%6.2f,%6.2f   ", (addr+j*lda)->real,
                          (addr+j*lda)->imag);
          } /* for */
                  if (kl >= m) kl1 = m-1;
                  else  kl1 = kl;
          for (i = ku1+1; i < ku1+kl1+1; i++) {
              printf("\n       %2d ", Nrow);
                          Nrow = Nrow + 1;
              addr = a + ku - ku1 + i;
              if ((m+ku1-i) >= n) k = n;
              else  k = m+ku1-i;
              for (j = 0; j < k; j++)
                  printf("%6.2f,%6.2f   ", (addr+j*lda)->real,
                          (addr+j*lda)->imag);
          } /* for */
      } /* if */
      return;
} /* PrintBandArrayZ */
