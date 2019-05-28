/*
//     Z D F F T 1 D C  Example Program Text
//     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>
#include <math.h>

FILE *in_file;
char *in_file_name;

/*     rmax = n+2, wmax = (2*n)*2
*/
enum { rmax = 18,  wmax = 64 };

void GetInputData(FILE*, int*, int*, double*);

void main(int argc, char *argv[])
{
      int         n, isign; 
      double      r[rmax], r0[rmax];
      double      wsave[wmax];

      double      temp;
      int         i;
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
      GetInputData(in_file, &n, &isign, &r[0]);
      fclose(in_file);
	  cblas_dcopy(n+2, r, 1, r0, 1);

/*      Call ZDFFT1DC subroutine     */
      ZDFFT1DC(r, n, 0, wsave);
      ZDFFT1DC(r, n, isign, wsave);  

      printf("\n        Z D F F T 1 D C  EXAMPLE PROGRAM");
      printf("\n\n       N=%d  ISIGN=%d", n, isign);
      printf("\n       COMPLEX VECTOR              INPUT VECTOR       OUTPUT VECTOR");
      printf("\n              Z(I)                      R                   R");
      for (i = 0; i < n/2+1; i++) 
         printf("\n       (%6.3f, %6.3f)              %6.3f              %6.3f", r0[i], r0[n/2+1+i],
                 r0[i],r[i]);
	  for (i = 1; i < n/2; i++) {
         temp = -r0[n+1-i];
         printf("\n       (%6.3f, %6.3f)              %6.3f              %6.3f", r0[n/2-i], temp,
                 r0[n/2+i],r[n/2+i]);
      } /* for */
      printf("\n                                     %6.3f", r0[n]);
      printf("\n                                     %6.3f", r0[n+1]);
      printf("\n");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *isign, double *r)
{
      int         i;
      double      z_real, z_imag;

/*     Read input data from input file  */
      fseek(in_file,41,0);
      fscanf(in_file,"%2d %2d", n, isign);
      fseek(in_file,30,1);
	  for (i = 0; i < (*n)/2+1; i++) {
		  fscanf(in_file, "%lf %lf", &z_real, &z_imag);
		  r[i] = z_real;
		  r[(*n)/2+1+i] = z_imag;
      } /* for */
      fclose(in_file);

      return;
}