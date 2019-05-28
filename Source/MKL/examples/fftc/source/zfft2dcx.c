/*
//     Z F F T 2 D C  Example Program Text
//     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>
#include <math.h>

FILE *in_file;
char *in_file_name;

void GetInputData(FILE*, int*, int*, int*, double*, double*);

enum {mmax = 8, nmax=4};

void main(int argc, char *argv[])
{
      int         m, n, isign;
      double      rr[mmax][nmax], ri[mmax][nmax];
      double      rr0[mmax][nmax], ri0[mmax][nmax];
      int         i, j;
/*                                
//    Executable Statementcs          
//                                
//    Get input parameters        
*/
      if (argc == 1) {
         printf("\n You must specify in_file data file as 1-st parameter");
         goto end;
      } /* if */
      in_file_name = argv[1];

      if( (in_file = fopen( in_file_name, "r" )) == NULL ) {     
         printf("\nERROR on OPEN '%s' with mode=%s\n", in_file_name, "r");            
         goto end;
      } /* if */
      GetInputData(in_file, &m, &n, &isign, &rr[0][0], &ri[0][0]);
      fclose(in_file);
      cblas_dcopy(m*n, rr, 1, rr0, 1);
      cblas_dcopy(m*n, ri, 1, ri0, 1);

/*      Call ZFFT2DC subroutine     */
      ZFFT2DC(rr, ri, m, n, isign);  

      printf("\n        Z F F T 2 D C  EXAMPLE PROGRAM");
      printf("\n\n      M=%d  N=%d  ISIGN=%d", m, n, isign);
      printf("\n      INPUT VECTORS");
      printf("\n          VECTOR RR");
      for (i = 0; i < m; i++) {
          printf("\n       ");
          for (j = 0; j < n; j++)
              printf("%10.6f  ", rr0[i][j]);
      } /* for */
      printf("\n          VECTOR RI");
      for (i = 0; i < m; i++) {
          printf("\n       ");
          for (j = 0; j < n; j++)
              printf("%10.6f  ", ri0[i][j]);
      } /* for */
      printf("\n\n      OUTPUT VECTORS");
      printf("\n         VECTOR RR");
      for (i = 0; i < m; i++) {
          printf("\n       ");
          for (j = 0; j < n; j++)
              printf("%10.6f  ", rr[i][j]);
      } /* for */
      printf("\n         VECTOR RI");
      for (i = 0; i < m; i++) {
          printf("\n       ");
          for (j = 0; j < n; j++)
              printf("%10.6f  ", ri[i][j]);
      } /* for */
      printf("\n");
end:  return;
}

void GetInputData(FILE *in_file, int *nr, int *nc, int *isign, double *rr,
				  double *ri)
{
      int          i, j, indx;
      double       step0, step;
      const double pi=3.1416;

/*     Read input data from input file  */
      fseek(in_file,40,0);
      fscanf(in_file,"%2d %2d %2d", nr, nc, isign);
      fclose(in_file);

      step = -pi;
      step0 = (2.0*pi)/(double)(*nr);
      for (i = 0; i < *nr; i++) {
          indx = i*(*nc);
          rr[indx] = (sin(step)*sqrt(3.0))/2.0;
          ri[indx] = sin(step)/sqrt(3.0);
          for (j = 1; j < *nc; j++) {
              rr[indx+j] = rr[indx];
              ri[indx+j] = ri[indx];
          } /* for */
          step = step + step0;
      } /* for */
      return;
}