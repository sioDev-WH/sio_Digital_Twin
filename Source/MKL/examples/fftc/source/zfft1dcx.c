/*
//     Z F F T 1 D C  Example Program Text
//     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>
#include <math.h>

FILE *in_file;
char *in_file_name;

/*  nmax = n, wmax = ((3*n)/2)*2  
*/
enum { nmax = 16, wmax = 48 };

void GetInputData(FILE*, int*, int*, double*, double*);

void main(int argc, char *argv[])
{
      int         n, isign; 
      double      rr[nmax], ri[nmax];
      double      rr0[nmax], ri0[nmax];
      double      wsave[wmax]; 

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
      GetInputData(in_file, &n, &isign, &rr[0], &ri[0]);
      fclose(in_file);
      cblas_dcopy(n, rr, 1, rr0, 1);
      cblas_dcopy(n, ri, 1, ri0, 1);

/*      Call ZFFT1DC subroutine     */
      ZFFT1DC(rr, ri, n, 0, wsave);
      ZFFT1DC(rr, ri, n, isign, wsave);  

      printf("\n          Z F F T 1 D C  EXAMPLE PROGRAM");
      printf("\n\n        N=%d  ISIGN=%d", n, isign);
      printf("\n      INPUT VECTORS                  OUTPUT VECTORS");
      printf("\n         RR          RI                 RR          RI");
      for (i = 0; i < n; i++) 
         printf("\n     %9.6f   %9.6f          %9.6f   %9.6f", 
                 rr0[i],ri0[i],rr[i],ri[i]);
      printf("\n");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *isign, double *rr,
				  double *ri)
{
      int          i;
      double       step0, step;
      const double pi=3.1416;

/*     Read input data from input file  */
      fseek(in_file,40,0);
      fscanf(in_file,"%2d %2d", n, isign);
      fclose(in_file);

      step=-pi;
      step0=(2.0*pi)/(double)(*n);
      for (i=0; i < (*n); i++) {
         rr[i] = (sin(step)*sqrt(3.0))/2.0;
         ri[i] = sin(step)/sqrt(3.0);
         step = step + step0;
      } /* for */
      return;
}