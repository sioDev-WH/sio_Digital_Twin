/*M*
//
//  INTEL CORPORATION PROPRIETARY INFORMATION
//  This software is supplied under the terms of a license agreement or
//  nondisclosure agreement with Intel Corporation and may not be copied
//  or disclosed except in accordance with the terms of that agreement.
//  Copyright (c) 1999 Intel Corporation. All Rights Reserved.
//
//      $Workfile$
//      $Revision$
//      $Modtime$
//
//  Contents:
//       C-style two-dimension FFT TEST
//
//  Author  : Gvozdev E., Sivolgina O.
//
*M*/

/*
* --- Version:
* ---    .09.97
* ---     RFNC (VNIIEF), Department 8, Gvozdev E.
* ---    .07.99
* ---     RFNC (VNIIEF), Department 8, Sivolgina O.
* ---     for INTEL

* --- Function:
* ---     Testing program for FFT 2D C-interface routines
*/

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <errno.h>
#include <float.h>
#include <stdlib.h>

#define ZFFT2DC_  0
#define CFFT2DC_  1
#define DZFFT2DC_ 2
#define ZDFFT2DC_ 3
#define SCFFT2DC_ 4
#define CSFFT2DC_ 5
#define ZDFT_     6
#define CDFT_     7
#define ZFFT_S    8
#define CFFT_S    9

#define zfft2dc  ZFFT2DC
#define cfft2dc  CFFT2DC
#define dzfft2dc DZFFT2DC
#define zdfft2dc ZDFFT2DC
#define scfft2dc SCFFT2DC
#define csfft2dc CSFFT2DC

#define NUM1_DFT_CHECK 2
int dim1_dft[NUM1_DFT_CHECK] = {4, 8};

#define NUM2_DFT_CHECK 2
int dim2_dft[NUM2_DFT_CHECK] = {2, 4};

#define FUNC_NUM_S 10
#define FUNC_NUM 6
#define DIM_NUM  20
#define POST_MN  256

#define NAME_LEN    128
#define MESSAGE_LEN 1024
char snp_file_name[NAME_LEN], sum_file_name[NAME_LEN]; 
char *in_file_name;

char message[MESSAGE_LEN];

double deps;
float  feps;

FILE *in_file, *snp_file, *sum_file;
int  self_test, dft_compare, fail_stop, test_error_exit, test_cmpt;
int  what_test[FUNC_NUM];
int  num1, num2;
int  dim1[DIM_NUM], dim2[DIM_NUM];
int  z_type, c_type, r_type;
int  elm_size;
int  code_err_t;
int  ok_g;
int  xerbla_called;
char fnames[FUNC_NUM_S][NAME_LEN] = {
                          "ZFFT2DC",
                          "CFFT2DC",
                          "DZFFT2DC",
                          "ZDFFT2DC",
                          "SCFFT2DC",
                          "CSFFT2DC",
                          "ZDFT2DC",
                          "CDFT2DC",
                          "ZFFT2DC_SAMPLE",
                          "CFFT2DC_SAMPLE"
                          };

char *fname;
int  isign;
int  ifunc;
int  fatal[FUNC_NUM_S];

#define OPEN_FILE(file_pointer, file_name, mode)                 \
  if( (file_pointer = fopen( file_name, mode )) == NULL )  {     \
    sprintf(message, "\nERROR on OPEN '%s' with mode=%s\n",      \
                                 file_name, mode);               \
    out_message(message);                                        \
    Exit_(1);                                                    \
  }

#define CLOSE_FILE(file_pointer)                                 \
  fclose(file_pointer);

#define OPEN_SNAP                                                \
  if( (snp_file = fopen( snp_file_name, "a" )) == NULL )  {      \
    sprintf(message,"\nERROR on REOPEN '%s' with mode=%s\n",     \
                                 snp_file_name, "a");            \
    out_message(message);                                        \
    Exit_(1);                                                    \
  }                                                             

#define CLOSE_SNAP                                               \
  fclose(snp_file);

#define OPEN_SUM                                                 \
  if( (sum_file = fopen( sum_file_name, "a" )) == NULL )  {      \
    sprintf(message, "\nERROR on REOPEN '%s' with mode=%s\n",    \
                                 sum_file_name, "a");            \
    out_message(message);                                        \
    Exit_(1);                                                    \
  }                                                             

#define CLOSE_SUM                                                \
  fclose(sum_file);

double zero = 0.0;
double one = 1.0;


extern void ZFFT2DC_S(double *a_r, double *a_i, int m, int n, int isign);
extern void CFFT2DC_S(float *a_r, float *a_i, int m, int n, int isign);
extern void ZFFT2DC (double *a_r, double *a_i, int m, int n, int isign);
extern void DZFFT2DC(double *a, int m, int n);
extern void ZDFFT2DC(double *a, int m, int n);
extern void CFFT2DC (float *a_r, float *a_i, int m, int n, int isign);
extern void SCFFT2DC(float *a, int m, int n);
extern void CSFFT2DC(float *a, int m, int n);

void   out_message(char* mes);
int    read_line(FILE* fp, char* buf );
int    get_str(char* str, ...);
void   Exit_(int code);
void   read_in_file(void);
void   summary(void);

double d_gauge(double *a_r, double *a_i, int m, int n, int isign);
float  s_gauge(float *a_r, float *a_i, int m, int n, int isign);

void   d_fill_rand(double *a, int m, int n);
void   s_fill_rand(float *a, int m, int n);

void   d_copy(double *a, double *b, int m, int n);
void   s_copy(float *a, float *b, int m, int n);

void   dz_copy_s(double *a, double *a_ro, double *a_io, int m, int n);
void   sc_copy_s(float *a, float *a_ro, float *a_io, int m, int n);

void   dz_copy(double *a, double *a_ro, double *a_io, int m, int n);
void   sc_copy(float *a, float *a_ro, float *a_io, int m, int n);

void   zfft(int m, int n);
void   cfft(int m, int n);

void   dzfft(int m, int n, int fi);
void   scfft(int m, int n, int fi);

void   zdft(int m, int n);
void   cdft(int m, int n);

void   zfft_s(int m, int n);
void   cfft_s(int m, int n);

void   zdft2d (double *a_ri, double *a_ii, int m, int n, int isign, 
               double *a_ro, double *a_io, double *tw, double *tmp_r,
               double *tmp_i );
void   cdft2d (float *a_ri, float *a_ii, int m, int n, int isign, 
               float *a_ro, float *a_io, float *tw, float *tmp_r,
               float *tmp_i );

int    zest(double *tst, double *tst_r, double *tst_i, double *exp_r, double *exp_i,
            int m, int n, double gauge);
int    cest(float *tst, float *tst_r, float *tst_i, float *exp_r, float *exp_i,
            int m, int n, float gauge);
int    zpostm(double*, double*, double*, double*, double*, int, int);
int    cpostm(float*, float*, float*, float*, float*, int, int);
            
void cherr (int num);
void call_func(int num, int m, int n, int isign, void *ar, void *ai);
void XERBLA(char* name_func, int *ind_err);

/* Function start */
void main( int argc, char * argv[] )
{

    int idim1, idim2;
    int i;
    int ok;

/*     MKLStart(); */

    if (argc == 1) {
       out_message("You must specify Input file name as 1-st parameter\n");
       Exit_(1);
	}/* if */

    in_file_name = argv[1];
    srand(1);

    read_in_file();

    summary();

    for (i = 0; i < num1; i++) 
        dim1[i] = 1 << dim1[i];
    for (i = 0; i < num2; i++) 
        dim2[i] = 1 << dim2[i];

    if (self_test) {

        for (ifunc = FUNC_NUM; ifunc < FUNC_NUM_S; ifunc++) {

            fname = fnames[ifunc];
            z_type = c_type = 0;
            if (ifunc == ZDFT_ || ifunc == ZFFT_S ) z_type = 1;
            if (ifunc == CDFT_ || ifunc == CFFT_S ) c_type = 1;
 
            if (z_type)
                elm_size = 8;
            else
                elm_size = 4;

            OPEN_SUM;
            printf(" %s :  Self test", fname);
            fprintf(sum_file, "  %s :  Self test", fname);
            CLOSE_SUM;

            for (idim1 = 0; idim1 < NUM1_DFT_CHECK; idim1++) {
                for (idim2 = 0; idim2 < NUM2_DFT_CHECK; idim2++) {

                    if (ifunc == ZDFT_ )
                        zdft(dim1_dft[idim1], dim2_dft[idim2]);

                    if (ifunc == CDFT_ )
                        cdft(dim1_dft[idim1], dim2_dft[idim2]);

                    if (ifunc == ZFFT_S )
                        zfft_s(dim1_dft[idim1], dim2_dft[idim2]);

                    if (ifunc == CFFT_S )
                        cfft_s(dim1_dft[idim1], dim2_dft[idim2]);

				}/* for idim2 */
			}/* for idim1 */

            OPEN_SUM;
            if (!fatal[ifunc]) {
                printf("\t PASSED\n");
                fprintf(sum_file, "\t PASSED\n");
			} else {
                printf("\t ERROR\n");
                fprintf(sum_file, "\t ERROR\n");
			}/* if */
            CLOSE_SUM;

		}/* for ifunc */
	}/* if self_test */

if (test_error_exit) {

  for (ifunc = 0; ifunc < FUNC_NUM; ifunc++) {

    OPEN_SUM;

    printf("%s :\t Input parameters test", fnames[ifunc]);
    fprintf(sum_file, "%s :\t Input parameters test", fnames[ifunc]);
    CLOSE_SUM;

    fname = fnames[ifunc];
    z_type = c_type = r_type = 0;
    if (ifunc == ZFFT2DC_ || ifunc == ZDFFT2DC_ || ifunc == DZFFT2DC_) z_type = 1;
    if (ifunc == CFFT2DC_ || ifunc == CSFFT2DC_ || ifunc == SCFFT2DC_) c_type = 1;
    if (ifunc == ZDFFT2DC_ || ifunc == DZFFT2DC_ || ifunc == CSFFT2DC_ || ifunc == SCFFT2DC_) r_type = 1;

    if (z_type) 
      elm_size = 8;
    else
      elm_size = 4;


    ok = 0;

    switch(ifunc) {
    case ZFFT2DC_:
      if (what_test[ZFFT2DC_])
        ok = 1;
      break;
    case CFFT2DC_:
      if (what_test[CFFT2DC_])
        ok = 1;
      break;
    case ZDFFT2DC_:
      if (what_test[ZDFFT2DC_])
        ok = 1;
      break;
    case DZFFT2DC_:
      if (what_test[DZFFT2DC_])
        ok = 1;
      break;
    case SCFFT2DC_:
      if (what_test[SCFFT2DC_])
        ok = 1;
      break;
    case CSFFT2DC_:
      if (what_test[CSFFT2DC_])
        ok = 1;
      break;
    }

    if (ok)
      cherr(ifunc);

    OPEN_SUM;
    if (what_test[ifunc]) {
      if (!fatal[ifunc]) {
        printf("\t PASSED \n");
        fprintf(sum_file, "\t PASSED \n");
      }
      else {
        printf("\t ERROR \n");
        fprintf(sum_file, "\t ERROR \n");
      }
    }
    CLOSE_SUM;

  }

}

if (test_cmpt) {
for (ifunc = 0; ifunc < FUNC_NUM; ifunc++) {

  OPEN_SUM;
  if (what_test[ifunc]) {
    printf("%s :\t Computational test", fnames[ifunc]);
    fprintf(sum_file, "%s :\t Computational test", fnames[ifunc]);
  }
  CLOSE_SUM;

  fname = fnames[ifunc];
  z_type = c_type = r_type = 0;
  if (ifunc == ZFFT2DC_ || ifunc == ZDFFT2DC_ || ifunc == DZFFT2DC_) z_type = 1;
  if (ifunc == CFFT2DC_ || ifunc == CSFFT2DC_ || ifunc == SCFFT2DC_) c_type = 1;
  if (ifunc == ZDFFT2DC_ || ifunc == DZFFT2DC_ ||
      ifunc == CSFFT2DC_ || ifunc == SCFFT2DC_) r_type = 1;

  if (z_type) 
    elm_size = 8;
  else
    elm_size = 4;

  for (idim1 = 0; idim1 < num1; idim1++) {
    for (idim2 = 0; idim2 < num2; idim2++) {

//      if((dim1[idim1] + dim2[idim2]) > DIM_NUM) continue;

      if (ifunc == ZFFT2DC_ && what_test[ZFFT2DC_])
        zfft(dim1[idim1], dim2[idim2]);

      if (ifunc == CFFT2DC_ && what_test[CFFT2DC_] )
        cfft(dim1[idim1], dim2[idim2]);

      if (ifunc == DZFFT2DC_ && what_test[DZFFT2DC_]) {
        if (what_test[ZDFFT2DC_])
          dzfft(dim1[idim1], dim2[idim2], 0);
        else
          dzfft(dim1[idim1], dim2[idim2], -1);

      }

      if (ifunc == ZDFFT2DC_ && what_test[ZDFFT2DC_])
        dzfft(dim1[idim1], dim2[idim2], 1);

      if (ifunc == SCFFT2DC_ && what_test[SCFFT2DC_]) {
        if (what_test[CSFFT2DC_])
          scfft(dim1[idim1], dim2[idim2], 0);
        else
          scfft(dim1[idim1], dim2[idim2], -1);

      }
      if (ifunc == CSFFT2DC_ && what_test[CSFFT2DC_])
        scfft(dim1[idim1], dim2[idim2], 1);
    }
  }
  OPEN_SUM;
  if (what_test[ifunc]) {
    if (!fatal[ifunc]) {
      printf(" \t PASSED \n");
      fprintf(sum_file, " \t PASSED \n");
    }
    else {
      printf(" \t ERROR \n");
      fprintf(sum_file, "  \t ERROR \n");
    }
  }
  CLOSE_SUM;
}
}

/*     MKLEnd();       */

}

/* Auxilary routines */
  
/* Function start */
void out_message(char* mes)
{
fprintf(stderr, "%s", mes);
}

/* Function start */
void Exit_(int code)
{
exit(code);
}

/* Function start */
void read_in_file(void)
{
char buf[MESSAGE_LEN];
char flag;
char name[NAME_LEN];

OPEN_FILE(in_file, in_file_name, "rb")

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read Summary file name from input file.\n");
  out_message(message);
  Exit_(1);
}
if (get_str(buf, 1, "%s", sum_file_name)) {
  sprintf(message,"Can't read Summary file name from input file.\n");
  out_message(message);
  Exit_(1);
}

OPEN_FILE(sum_file, sum_file_name, "wb");
CLOSE_FILE(sum_file);

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read Snap file name from input file.\n");
  out_message(message);
  Exit_(1);
}
if (get_str(buf, 1, "%s", snp_file_name)) {
  sprintf(message,"Can't read Snap file name from input file.\n");
  out_message(message);
  Exit_(1);
}

OPEN_FILE(snp_file, snp_file_name, "wb");
CLOSE_FILE(snp_file);

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't string with double epsilon value from input file.\n");
  out_message(message);
  Exit_(1);
}
deps = atof(buf);

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't string with real epsilon value from input file.\n");
  out_message(message);
  Exit_(1);
}
feps = atof(buf);


if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read self_test flag value from input file.\n");
  out_message(message);
  Exit_(1);
}

if (buf[0] == 't' || buf[0] == 'T') self_test = 1;

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read dft_compare flag value from input file.\n");
  out_message(message);
  Exit_(1);
}

if (buf[0] == 't' || buf[0] == 'T') dft_compare = 1;
/*
if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read failure_stop flag value from input file.\n");
  out_message(message);
  Exit_(1);
}

if (buf[0] == 't' || buf[0] == 'T') fail_stop = 1;
*/

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read test_error_exit flag value from input file.\n");
  out_message(message);
  Exit_(1);
}

if (buf[0] == 't' || buf[0] == 'T') test_error_exit = 1;

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read test_compute flag value from input file.\n");
  out_message(message);
  Exit_(1);
}

if (buf[0] == 't' || buf[0] == 'T') test_cmpt = 1;

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read number of values on 1-st dimension from input file.\n");
  out_message(message);
  Exit_(1);
}

if (get_str(buf, 1, "%d", &num1)) {
  sprintf(message,"Can't read number of values on 1-st dimension.\n");
  out_message(message);
  Exit_(1);
}

if (num1 >= 20) {
  sprintf(message,"Wrong number of values on 1-st dimension (must be < 20).\n");
  out_message(message);
  Exit_(1);
}

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read values on 1-st dimension from input file.\n");
  out_message(message);
  Exit_(1);
}

if (get_str(buf, num1, "%d", dim1, "%d", dim1+1, "%d", dim1+2, "%d", dim1+3,
                      "%d", dim1+4, "%d", dim1+5, "%d", dim1+6, "%d", dim1+7,
                      "%d", dim1+8, "%d", dim1+9, "%d", dim1+10, "%d", dim1+11,
                      "%d", dim1+12, "%d", dim1+13, "%d", dim1+14, "%d", dim1+15,
                      "%d", dim1+16, "%d", dim1+17, "%d", dim1+18, "%d", dim1+19 )) {
  sprintf(message,"Can't read values on 1-st dimension.\n");
  out_message(message);
  Exit_(1);
}

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read number of values on 1-st dimension from input file.\n");
  out_message(message);
  Exit_(1);
}

if (get_str(buf, 1, "%d", &num2)) {
  sprintf(message,"Can't read number of values on 2-nd dimension.\n");
  out_message(message);
  Exit_(1);
}

if (num2 >= 20) {
  sprintf(message,"Wrong number of values on 2-nd dimension (must be < 20).\n");
  out_message(message);
  Exit_(1);
}

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read values on 2-nd dimension from input file.\n");
  out_message(message);
  Exit_(1);
}

if (get_str(buf, num2, "%d", dim2, "%d", dim2+1, "%d", dim2+2, "%d", dim2+3,
                      "%d", dim2+4, "%d", dim2+5, "%d", dim2+6, "%d", dim2+7,
                      "%d", dim2+8, "%d", dim2+9, "%d", dim2+10, "%d", dim2+11,
                      "%d", dim2+12, "%d", dim2+13, "%d", dim2+14, "%d", dim2+15,
                      "%d", dim2+16, "%d", dim2+17, "%d", dim2+18, "%d", dim2+19 )) {
  sprintf(message,"Can't read values on 2-st dimension.\n");
  out_message(message);
  Exit_(1);
}


while(read_line(in_file, buf)) {
  if (get_str(buf, 2, "%s", name, "%c", &flag)) {
    sprintf(message,"Can't read function name and test flag from input file.\n");
    out_message(message);
    Exit_(1);
  }

  if      (!strcmp("ZFFT2DC", name) && (flag == 't' || flag == 'T'))  what_test[ZFFT2DC_] = 1;
  else if (!strcmp("CFFT2DC", name) && (flag == 't' || flag == 'T'))  what_test[CFFT2DC_] = 1;
  else if (!strcmp("ZDFFT2DC", name) && (flag == 't' || flag == 'T')) what_test[ZDFFT2DC_] = 1;
  else if (!strcmp("DZFFT2DC", name) && (flag == 't' || flag == 'T')) what_test[DZFFT2DC_] = 1;
  else if (!strcmp("CSFFT2DC", name) && (flag == 't' || flag == 'T')) what_test[CSFFT2DC_] = 1;
  else if (!strcmp("SCFFT2DC", name) && (flag == 't' || flag == 'T')) what_test[SCFFT2DC_] = 1;
  else {
    if (strcmp("ZFFT2DC", name) &&
        strcmp("CFFT2DC", name) &&
        strcmp("DZFFT2DC", name) &&
        strcmp("ZDFFT2DC", name) &&
        strcmp("SCFFT2DC", name) && 
        strcmp("CSFFT2DC", name) ) { 
      sprintf(message,"Can't recognize input function name %s.\n", name);
      out_message(message);
      Exit_(1);
    }
  }
}

CLOSE_FILE(in_file);
}


/* Function start */
int get_str(char* str, ...)
{
   va_list ap;
   int i,j;
   int num;
   char* spec[20];
   void* adr[20];

   va_start(ap, str);

   if ((num = va_arg(ap,int)) <= 0) {
     printf("get_str: Error when read number of parameters!\n");
     return 1;
   }

   for (i = 0; i < num; i++) {
     if ((spec[i] = va_arg(ap,char*)) == NULL) {
       printf("get_str: Error when read specifier!\n");
       return 1;
     }
     if ((adr[i] = va_arg(ap,void*)) == NULL) {
       printf("get_str: Error when read address!\n");
       return 1;
     }
   }


   j = 0;
   for (i = 0; i < num; i++) {
     if (str[j] == '\0' || str[j] == '\n' || j >= 1024) {
       printf("get_str: Too less data in string %s\n", str);
       return 1;
     }
     sscanf(str+j, spec[i], adr[i]);
     j++;
     while (str[j] != '\n' && str[j] != '\0' && str[j] != ' ' && j < 1024) j++;
     while (str[j] != '\n' && str[j] != '\0' && str[j] == ' ' && j < 1024) j++;
   }

   va_end(ap);
   return 0;

}

/* Function start */
int read_line(FILE* fp, char* buf )
{
int  i = 0;
static int ch = ' ';
static int first_time = 1;

if (ch == (int)EOF) return 0;

if (!first_time) buf[i++] = (char)ch;

first_time = 0;
while(ch != 0x0d && ch != 0x0a && ch != 0 && ch != (int)EOF) {
  ch = fgetc( fp );
  buf[i++] = (char)ch;
}
buf[i-1] = '\0';

while((ch == 0x0d || ch == 0x0a || ch == 0) && ch != (int)EOF) {
  ch = fgetc( fp );
}
return 1;
}

/* Function start */
void summary(void)
{
int i;  
char *yes = "Yes", *no = "No";
char *yesno;

  OPEN_SUM;
  fprintf(sum_file, "-- Testing of 2D Fast Fourier Transform C-Interface functions --\n");
  fprintf(sum_file, "--          by result comparision with results from          --\n");
  fprintf(sum_file, "--         2D Discrete Fourier Transform routine (DFT).       --\n");

  fprintf(sum_file, "Double functions epsilon %e\n", deps);
  fprintf(sum_file, "Real functions epsilon %e\n", feps);

  yesno = self_test ? yes : no;
  fprintf(sum_file, "Self test: %s\n", yesno);
  yesno = dft_compare ? yes : no;
  fprintf(sum_file, "DFT Compare: %s\n", yesno);
  yesno = test_error_exit ? yes : no;
    yesno = test_error_exit ? yes : no;
  fprintf(sum_file, "Error-Exit test: %s\n", yesno);
  yesno = test_cmpt ? yes : no;
  fprintf(sum_file, "Computational test: %s\n", yesno);

  fprintf(sum_file, "\n Values on 1-st Dimension (Powers of 2):\n");
  for (i = 0; i < num1; i++ )
    fprintf(sum_file, "%d ", dim1[i]);
  fprintf(sum_file, "\n Values on 2-nd Dimension (Powers of 2):\n");
  for (i = 0; i < num2; i++ )
    fprintf(sum_file, "%d ", dim2[i]);
  fprintf(sum_file, "\n");
  CLOSE_SUM;

  printf("-- Testing of 2D Fast Fourier Transform C-Interface functions --\n");
  printf("--          by result comparision with results from          --\n");
  printf("--         2D Discrete Fourier Transform routine (DFT).       --\n");

  printf("Double functions epsilon %e\n", deps);
  printf("Real functions epsilon %e\n", feps);
  printf("\n Values on 1-st Dimension (Powers of 2):\n");
  for (i = 0; i < num1; i++ )
    printf("%d ", dim1[i]);
  printf("\n\n Values on 2-nd Dimension (Powers of 2):\n");
  for (i = 0; i < num2; i++ )
    printf("%d ", dim2[i]);
  printf("\n\n");
}


/* Function start */
void zfft(int m, int n)
{
    double *a_r = NULL, *a_i = NULL;
    double *a_rs = NULL, *a_is = NULL;
    double *a_rdft = NULL, *a_idft = NULL;
    double *a_rtmp = NULL, *a_itmp = NULL;
    double *tw = NULL;
    double gauge;

    a_r = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size+POST_MN*elm_size);
    a_i = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size+POST_MN*elm_size);
    a_rs = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size+POST_MN*elm_size);
    a_is = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size+POST_MN*elm_size);

    tw = (double *)LocalAlloc(LMEM_FIXED, 2*(m+n)*elm_size);
    a_rtmp = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_itmp = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);

    if(a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
       tw != NULL && a_rtmp != NULL && a_itmp != NULL )  {

        /* Compare with DFT routine, isign = -1 */
        d_fill_rand(a_r, m, n);
        d_fill_rand(a_i, m, n);

        d_fill_rand(&a_r[m*n], 1, POST_MN);
        d_fill_rand(&a_i[m*n], 1, POST_MN);

        isign = -1;
        gauge = d_gauge(a_r, a_i, m, n, isign);

        if (dft_compare) {
            zdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);
		} else {
            d_copy(a_r, a_rs, m, n);
            d_copy(a_i, a_is, m, n);

            d_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
            d_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);

            ZFFT2DC_S(a_rs, a_is, m, n, isign);
		}/* if */
  
		ZFFT2DC(a_r, a_i, m, n, isign);

        zest(a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

        /* Compare with DFT routine, isign = 1 */
        d_fill_rand(a_r, m, n);
        d_fill_rand(a_i, m, n);

        d_fill_rand(&a_r[m*n], 1, POST_MN);
        d_fill_rand(&a_i[m*n], 1, POST_MN);

        isign = 1;
        gauge = d_gauge(a_r, a_i, m, n, isign);

        if (dft_compare) {
            zdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);
		} else {
            d_copy(a_r, a_rs, m, n);
            d_copy(a_i, a_is, m, n);
            d_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
            d_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);

            ZFFT2DC_S(a_rs, a_is, m, n, isign);
		}/* if */

        ZFFT2DC(a_r, a_i, m, n, isign);

        zest(a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

        /* Forward-Inverse transform +-1 */
        d_fill_rand(a_r, m, n);
        d_fill_rand(a_i, m, n);

        d_fill_rand(&a_r[m*n], 1, POST_MN);
        d_fill_rand(&a_i[m*n], 1, POST_MN);

        d_copy (a_r, a_rs, m, n);
        d_copy (a_i, a_is, m, n);
        d_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
        d_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);

        isign = -1;

        gauge = d_gauge(a_r, a_i, m, n, isign);

        ZFFT2DC(a_r, a_i, m, n, isign);
  
        isign = 1;

        ZFFT2DC(a_r, a_i, m, n, isign);
  
        isign = 0;

        zest (a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

        if (!dft_compare) {
            /* Compare with DFT routine, isign = -2 */
            d_fill_rand(a_r, m, n);
            d_fill_rand(a_i, m, n);

            d_fill_rand(&a_r[m*n], 1, POST_MN);
            d_fill_rand(&a_i[m*n], 1, POST_MN);

            isign = -2;
            gauge = d_gauge(a_r, a_i, m, n, isign);

            d_copy(a_r, a_rs, m, n);
            d_copy(a_i, a_is, m, n);
            d_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
            d_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);

            ZFFT2DC_S(a_rs, a_is, m, n, isign);
  
		    ZFFT2DC(a_r, a_i, m, n, isign);

            zest(a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

            /* Compare with DFT routine, isign = 2 */
            d_fill_rand(a_r, m, n);
            d_fill_rand(a_i, m, n);

            d_fill_rand(&a_r[m*n], 1, POST_MN);
            d_fill_rand(&a_i[m*n], 1, POST_MN);

            isign = 2;
            gauge = d_gauge(a_r, a_i, m, n, isign);

            d_copy(a_r, a_rs, m, n);
            d_copy(a_i, a_is, m, n);
            d_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
            d_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);

            ZFFT2DC_S(a_rs, a_is, m, n, isign);

            ZFFT2DC(a_r, a_i, m, n, isign);

            zest(a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

            /* Forward-Inverse transform +-2 */
            d_fill_rand(a_r, m, n);
            d_fill_rand(a_i, m, n);

            d_fill_rand(&a_r[m*n], 1, POST_MN);
            d_fill_rand(&a_i[m*n], 1, POST_MN);

            d_copy (a_r, a_rs, m, n);
            d_copy (a_i, a_is, m, n);
            d_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
            d_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);

            isign = -2;

            gauge = d_gauge(a_r, a_i, m, n, isign);

            ZFFT2DC(a_r, a_i, m, n, isign);
  
            isign = 2;

            ZFFT2DC(a_r, a_i, m, n, isign);
  
            isign = 22;

            zest (a_r, a_r, a_i, a_rs, a_is, m, n, gauge);
		}/* if +-2*/
	} else {
           fatal[ifunc] = 1;
           printf("\n         Array is very big and is not be allocatable\n");
        }/* if allocate */

    LocalFree(a_itmp);
    LocalFree(a_rtmp);
    LocalFree(tw);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);

}/* zfft */

/* Function start */
void cfft(int m, int n)
{
    float *a_r = NULL, *a_i = NULL;
    float *a_rs = NULL, *a_is = NULL;
    float *a_rdft = NULL, *a_idft = NULL;
    float *a_rtmp = NULL, *a_itmp = NULL;
    float *tw = NULL;
    float gauge;

    a_r = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size+POST_MN*elm_size);
    a_i = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size+POST_MN*elm_size);
    a_rs = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size+POST_MN*elm_size);
    a_is = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size+POST_MN*elm_size);

    tw = (float *)LocalAlloc(LMEM_FIXED, 2*(m+n)*elm_size);
    a_rtmp = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_itmp = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);


    if(a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
       tw != NULL && a_rtmp != NULL && a_itmp != NULL )  {

        /* Compare with DFT routine, isign = -1 */
        s_fill_rand(a_r, m, n);
        s_fill_rand(a_i, m, n);

        s_fill_rand(&a_r[m*n], 1, POST_MN);
        s_fill_rand(&a_i[m*n], 1, POST_MN);

        isign = -1;
        gauge = s_gauge(a_r, a_i, m, n, isign);

        if (dft_compare) {
            cdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);
	} else {
            s_copy(a_r, a_rs, m, n);
            s_copy(a_i, a_is, m, n);
            s_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
            s_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);
            CFFT2DC_S(a_rs, a_is, m, n, isign);
	}/* if */

        CFFT2DC(a_r, a_i, m, n, isign);

        cest(a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

        /* Compare with DFT routine, isign = 1 */
        s_fill_rand(a_r, m, n);
        s_fill_rand(a_i, m, n);
        s_fill_rand(&a_r[m*n], 1, POST_MN);
        s_fill_rand(&a_i[m*n], 1, POST_MN);

        isign = 1;
        gauge = s_gauge(a_r, a_i, m, n, isign);

        if (dft_compare) {
            cdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);
	} else {
            s_copy(a_r, a_rs, m, n);
            s_copy(a_i, a_is, m, n);
            s_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
            s_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);
            CFFT2DC_S(a_rs, a_is, m, n, isign);
	}/* if */

        CFFT2DC(a_r, a_i, m, n, isign);

        cest(a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

        /* Forward-Inverse transform +-1 */
        s_fill_rand(a_r, m, n);
        s_fill_rand(a_i, m, n);
        s_fill_rand(&a_r[m*n], 1, POST_MN);
        s_fill_rand(&a_i[m*n], 1, POST_MN);

        s_copy (a_r, a_rs, m, n);
        s_copy (a_i, a_is, m, n);
        s_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
        s_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);

        isign = -1;
        gauge = s_gauge(a_r, a_i, m, n, isign);

        CFFT2DC(a_r, a_i, m, n, isign);
  
        isign = 1;
        CFFT2DC(a_r, a_i, m, n, isign);
  
        isign = 0;
        cest(a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

        if (!dft_compare) {
            /* Compare with DFT routine, isign = -2 */
            s_fill_rand(a_r, m, n);
            s_fill_rand(a_i, m, n);
            s_fill_rand(&a_r[m*n], 1, POST_MN);
            s_fill_rand(&a_i[m*n], 1, POST_MN);

            isign = -2;
            gauge = s_gauge(a_r, a_i, m, n, isign);

            s_copy(a_r, a_rs, m, n);
            s_copy(a_i, a_is, m, n);
            s_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
            s_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);

            CFFT2DC_S(a_rs, a_is, m, n, isign);

            CFFT2DC(a_r, a_i, m, n, isign);

            cest(a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

            /* Compare with DFT routine, isign = 2 */
            s_fill_rand(a_r, m, n);
            s_fill_rand(a_i, m, n);
            s_fill_rand(&a_r[m*n], 1, POST_MN);
            s_fill_rand(&a_i[m*n], 1, POST_MN);

            isign = 2;
            gauge = s_gauge(a_r, a_i, m, n, isign);

            s_copy(a_r, a_rs, m, n);
            s_copy(a_i, a_is, m, n);
            s_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
            s_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);

            CFFT2DC_S(a_rs, a_is, m, n, isign);

            CFFT2DC(a_r, a_i, m, n, isign);
 
            cest(a_r, a_r, a_i, a_rs, a_is, m, n, gauge);
     
			/* Forward-Inverse transform +-2 */
            s_fill_rand(a_r, m, n);
            s_fill_rand(a_i, m, n);
            s_fill_rand(&a_r[m*n], 1, POST_MN);
            s_fill_rand(&a_i[m*n], 1, POST_MN);

            s_copy (a_r, a_rs, m, n);
            s_copy (a_i, a_is, m, n);
            s_copy(&a_r[m*n], &a_rs[m*n], 1, POST_MN);
            s_copy(&a_i[m*n], &a_is[m*n], 1, POST_MN);

            isign = -2;
            gauge = s_gauge(a_r, a_i, m, n, isign);

            CFFT2DC(a_r, a_i, m, n, isign);
  
            isign = 2;
            CFFT2DC(a_r, a_i, m, n, isign);
  
            isign = 22;
            cest(a_r, a_r, a_i, a_rs, a_is, m, n, gauge);
        }/* dft_compare */

	} else {
           fatal[ifunc] = 1;
           printf("\n         Array is very big and is not be allocatable\n");
        }/* if allocate */

	LocalFree(a_itmp);
    LocalFree(a_rtmp);
    LocalFree(tw);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);

}/* cfft */

/* Function start */
void dzfft(int m, int n, int fi)
{
double *a = NULL;
double *a_r = NULL, *a_i = NULL;
double *a_rs = NULL, *a_is = NULL;
double *a_rdft = NULL, *a_idft = NULL;
double *a_rtmp = NULL, *a_itmp = NULL;
double *tw = NULL;
double gauge;

a = (double *)LocalAlloc(LMEM_FIXED, (m+2)*(n+2)*elm_size+POST_MN*elm_size);
a_r = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
a_i = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
a_rs = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size+POST_MN*elm_size);
a_is = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);

tw = (double *)LocalAlloc(LMEM_FIXED, 2*(m+n)*elm_size);
a_rtmp = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
a_itmp = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);


if (a != NULL && a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
    tw != NULL && a_rtmp != NULL && a_itmp != NULL )  {

/* Forward routine DZFFT2D compare with DFT routine */
  if (fi == -1 || fi == 0) {
    isign = -1;
  
    d_fill_rand(a, m, n);

    d_fill_rand(&a[(m+2)*(n+2)], 1, POST_MN);

    dz_copy_s (a, a_r, a_i, m, n);

    d_copy(&a[(m+2)*(n+2)], &a_rs[m*n], 1, POST_MN);

    gauge = d_gauge(a_r, a_i, m, n, isign);

    zdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);

    DZFFT2DC(a, m, n);

    dz_copy (a, a_r, a_i, m, n);

    zest (a, a_r, a_i, a_rs, a_is, m, n, gauge);
  }
/* Inverse routine ZDFFT2D compare with DFT routine */
  if (fi == 1) {
    isign = 1;
  
    d_fill_rand(a, m+2, n+2);
    d_fill_rand(&a[(m+2)*(n+2)], 1, POST_MN);

    dz_copy (a, a_r, a_i, m, n);
    d_copy(&a[(m+2)*(n+2)], &a_rs[m*n], 1, POST_MN);

    gauge = d_gauge(a_r, a_i, m, n, isign);

    zdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);


    ZDFFT2DC(a, m, n);

    dz_copy_s (a, a_r, a_i, m, n);

    zest (a, a_r, a_i, a_rs, a_is, m, n, gauge);
  }

/* Forward-Inverse transform */
  if (fi == 0) {
    d_fill_rand(a, m+2, n+2);
    d_fill_rand(&a[(m+2)*(n+2)], 1, POST_MN);

    isign = -1;

    dz_copy_s (a, a_rs, a_is, m, n);
    d_copy(&a[(m+2)*(n+2)], &a_rs[m*n], 1, POST_MN);

    gauge = d_gauge(a_rs, a_is, m, n, isign);

    DZFFT2DC(a, m, n);
 
    ZDFFT2DC(a, m, n);

    dz_copy_s (a, a_r, a_i, m, n);

    isign = 0;

    zest (a, a_r, a_i, a_rs, a_is, m, n, gauge);
  }

    } else {
           fatal[ifunc] = 1;
           printf("\n         Array is very big and is not be allocatable\n");
    }/* if allocate */

    LocalFree(a_itmp);
    LocalFree(a_rtmp);
    LocalFree(tw);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);
    LocalFree(a);

}/* dzfft */

/* Function start */
void scfft(int m, int n, int fi)
{
float *a = NULL;
float *a_r = NULL, *a_i = NULL;
float *a_rs = NULL, *a_is = NULL;
float *a_rdft = NULL, *a_idft = NULL;
float *a_rtmp = NULL, *a_itmp = NULL;
float *tw = NULL;
float gauge;

int i;

a = (float *)LocalAlloc(LMEM_FIXED, (m+2)*(n+2)*elm_size+POST_MN*elm_size);
a_r = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
a_i = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
a_rs = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size+POST_MN*elm_size);
a_is = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);

tw = (float *)LocalAlloc(LMEM_FIXED, 2*(m+n)*elm_size);
a_rtmp = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
a_itmp = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);


if (a != NULL && a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
    tw != NULL && a_rtmp != NULL && a_itmp != NULL )  {

/* Forward routine SCFFT2D compare with DFT routine */
  if (fi == -1 || fi == 0) {
    isign = -1;
  
    s_fill_rand(a, m, n);
    s_fill_rand(&a[(m+2)*(n+2)], 1, POST_MN);

    sc_copy_s (a, a_r, a_i, m, n);
    s_copy(&a[(m+2)*(n+2)], &a_rs[m*n], 1, POST_MN);

    gauge = s_gauge(a_r, a_i, m, n, isign);

    cdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);

    SCFFT2DC(a, m, n);

//    for (i = 0; i < (m+2)*(n+2); i=i+2) {
//        printf("a[%d] = %f , a[%d] = %f \n", i, a[i], i+1, a[i+1]);
//	}
    
	sc_copy (a, a_r, a_i, m, n);

    cest (a, a_r, a_i, a_rs, a_is, m, n, gauge);
  }

/* Inverse routine ZDFFT2D compare with DFT routine */
  if (fi == 1) {
    isign = 1;
  
    s_fill_rand(a, m+2, n+2);
    s_fill_rand(&a[(m+2)*(n+2)], 1, POST_MN);
    
    sc_copy (a, a_r, a_i, m, n);
    s_copy(&a[(m+2)*(n+2)], &a_rs[m*n], 1, POST_MN);

    gauge = s_gauge(a_r, a_i, m, n, isign);

    cdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);

    CSFFT2DC(a, m, n);

    sc_copy_s (a, a_r, a_i, m, n);

    cest (a, a_r, a_i, a_rs, a_is, m, n, gauge);
  }

/* Forward-Inverse transform */
  if (fi == 0) {
    s_fill_rand(a, m+2, n+2);
    s_fill_rand(&a[(m+2)*(n+2)], 1, POST_MN);
    s_copy(&a[(m+2)*(n+2)], &a_rs[m*n], 1, POST_MN);

    isign = -1;

    sc_copy_s (a, a_rs, a_is, m, n);

    gauge = s_gauge(a_rs, a_is, m, n, isign);

    SCFFT2DC(a, m, n);
 
    CSFFT2DC(a, m, n);

    sc_copy_s (a, a_r, a_i, m, n);

    isign = 0;

    cest (a, a_r, a_i, a_rs, a_is, m, n, gauge);
  }

    } else {
           fatal[ifunc] = 1;
           printf("\n         Array is very big and is not be allocatable\n");
    }/* if allocate */

    LocalFree(a_itmp);
    LocalFree(a_rtmp);
    LocalFree(tw);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);
    LocalFree(a);

}/* scfft */

/* Function start */
void  zdft2d (double *a_ri, double *a_ii, int m, int n, int isign, 
              double *a_ro, double *a_io, double *tw, double *tmp_r,
              double *tmp_i )

{
int    i, j, l, k, ia;
double argm, argn;

argm = 8.0*atan(1.0)/ (double)m;
argn = 8.0*atan(1.0)/ (double)n;

if (isign <= 0) {
  for (i = 0; i < m; i++) {
    tw[2*i]   = cos(argm*(double)(i));
    tw[2*i+1] = -sin(argm*(double)(i));
  }
  for (i = m; i < m+n; i++) {
    tw[2*i]   = cos(argn*(double)(i-m));
    tw[2*i+1] = -sin(argn*(double)(i-m));
  }
}
else {
  for (i = 0; i < m; i++) {
    tw[2*i]   = cos(argm*(double)(i));
    tw[2*i+1] = sin(argm*(double)(i));
  }
  for (i = m; i < m+n; i++) {
    tw[2*i]   = cos(argn*(double)(i-m));
    tw[2*i+1] = sin(argn*(double)(i-m));
  }

}


for (j = 0; j < n; j++) {
  for (k = 0; k < m; k++) {
    tmp_r[ k*n + j] = 0.0;
    tmp_i[ k*n + j] = 0.0;

    for (i = 0; i < m; i++) {
      ia = (int)fmod ( (double)(i*k) , (double)m);
      tmp_r[k*n + j] = tmp_r[k*n + j] +
                       a_ri[i*n+j] * tw[2*ia] - 
                       a_ii[i*n+j] * tw[2*ia+1]; 

      tmp_i[k*n + j] = tmp_i[k*n + j] +
                       a_ri[i*n+j] * tw[2*ia+1] + 
                       a_ii[i*n+j] * tw[2*ia]; 
    }
  }
}

for (k = 0; k < m; k++) {
  for (l = 0; l < n; l++) {
    a_ro[k*n + l] = 0.0;
    a_io[k*n + l] = 0.0;

    for (j = 0; j < n; j++) {
      ia = (int)fmod ( (double)(j*l) , (double)n);
      a_ro[k*n + l] = a_ro[k*n + l] +
                      tmp_r[k*n+j] * tw[2*m+2*ia] - 
                      tmp_i[k*n+j] * tw[2*m+2*ia+1]; 

      a_io[k*n + l] = a_io[k*n + l] +
                      tmp_r[k*n+j] * tw[2*m+2*ia+1] + 
                      tmp_i[k*n+j] * tw[2*m+2*ia]; 
    }
  }
}

if (isign > 0) {
  ia = m*n;
  argm = (double)ia;
  for (i = 0; i < ia; i++) {
      a_ro[i] /= argm;
      a_io[i] /= argm;
    }
}

}

/* Function start */
void  cdft2d (float *a_ri, float *a_ii, int m, int n, int isign, 
              float *a_ro, float *a_io, float *tw, float *tmp_r,
              float *tmp_i )

{
int    i, j, l, k, ia;
float argm, argn;

argm = (float)(8.0*atan(1.0)/ (float)m);
argn = (float)(8.0*atan(1.0)/ (float)n);

if (isign <= 0) {
  for (i = 0; i < m; i++) {
    tw[2*i]   = (float)cos(argm*(float)(i));
    tw[2*i+1] = -(float)sin(argm*(float)(i));
  }
  for (i = m; i < m+n; i++) {
    tw[2*i]   = (float)cos(argn*(float)(i-m));
    tw[2*i+1] = -(float)sin(argn*(float)(i-m));
  }
}
else {
  for (i = 0; i < m; i++) {
    tw[2*i]   = (float)cos(argm*(float)(i));
    tw[2*i+1] = (float)sin(argm*(float)(i));
  }
  for (i = m; i < m+n; i++) {
    tw[2*i]   = (float)cos(argn*(float)(i-m));
    tw[2*i+1] = (float)sin(argn*(float)(i-m));
  }

}


for (j = 0; j < n; j++) {
  for (k = 0; k < m; k++) {
    tmp_r[ k*n + j] = (float)0.0;
    tmp_i[ k*n + j] = (float)0.0;

    for (i = 0; i < m; i++) {
      ia = (int)fmod ( (float)(i*k) , (float)m);
      tmp_r[k*n + j] = tmp_r[k*n + j] +
                       a_ri[i*n+j] * tw[2*ia] - 
                       a_ii[i*n+j] * tw[2*ia+1]; 

      tmp_i[k*n + j] = tmp_i[k*n + j] +
                       a_ri[i*n+j] * tw[2*ia+1] + 
                       a_ii[i*n+j] * tw[2*ia]; 
    }
  }
}

for (k = 0; k < m; k++) {
  for (l = 0; l < n; l++) {
    a_ro[k*n + l] = (float)0.0;
    a_io[k*n + l] = (float)0.0;

    for (j = 0; j < n; j++) {
      ia = (int)fmod ( (float)(j*l) , (float)n);
      a_ro[k*n + l] = a_ro[k*n + l] +
                      tmp_r[k*n+j] * tw[2*m+2*ia] - 
                      tmp_i[k*n+j] * tw[2*m+2*ia+1]; 

      a_io[k*n + l] = a_io[k*n + l] +
                      tmp_r[k*n+j] * tw[2*m+2*ia+1] + 
                      tmp_i[k*n+j] * tw[2*m+2*ia]; 
    }
  }
}

if (isign > 0) {
  ia = m*n;
  argm = (float)ia;
  for (i = 0; i < ia; i++) {
      a_ro[i] /= argm;
      a_io[i] /= argm;
    }
}

}

  
/* Function start */
int zest(double *tst, double *tst_r, double *tst_i, double *exp_r, double *exp_i,
         int m, int n, double gauge)
{
    int ierr, jerr, ierrfirst, jerrfirst;
    double err = 0.0;
    double errij;
    double diff_r, diff_i;
    int error = 0;
    int i,j;

    ierrfirst = -1;
    jerrfirst = -1;
    for(i = 0; i < m; i++ ) {
        for(j = 0; j < n; j++ ) {
            diff_r = tst_r[i*n+j] - exp_r[i*n+j];
            diff_i = tst_i[i*n+j] - exp_i[i*n+j];
            errij = sqrt( diff_r*diff_r + diff_i*diff_i ) / deps;
            
			if( gauge != zero ) errij = errij / (gauge); 
            if(errij > err ) {
                err =  errij;
                ierr = i;
                jerr = j;
			}/* if */
      
			if(errij >= one) {
                error = 1;
                if(ierrfirst == -1) {
                    ierrfirst = ierr;
                    jerrfirst = jerr;
				}/* if */
			}/* if */
		}/* for j */
	}/* for i */

    if (!error && !dft_compare) error = zpostm(tst, tst_r, tst_i, exp_r, exp_i, m, n);

    OPEN_SNAP;
    if( error ) {
        fatal[ifunc] = 1;
        if(isign == 0) {
            fprintf(snp_file, "%s  ISIGN = -1:+1 \tM = %d N = %d :ERROR\n", 
                    fname, m, n);
        } else if(isign == 22){
            fprintf(snp_file, "%s  ISIGN = -2:+2 \tM = %d N = %d :ERROR\n", 
                    fname, m, n);
        } else {
            fprintf(snp_file, "%s  ISIGN = %d    \tM = %d N = %d :ERROR\n", 
                    fname, isign, m, n);
        }/* if */

        if (error != 2) {
		
        fprintf(snp_file, "**** Fatal Error - computed result is less than half accurate ***\n");
        fprintf(snp_file, "     Computed result                      Expected result\n");

        fprintf(snp_file, "\n                           Error first\n");
        fprintf(snp_file, "           tst[%d][%d]                                exp[%d][%d] \n",
                           ierrfirst, jerrfirst, ierrfirst, jerrfirst);
        fprintf(snp_file, "(%.10f, %.10f)               (%.10f, %.10f)\n",
                           tst_r[ierrfirst*n+jerrfirst], tst_i[ierrfirst*n+jerrfirst],
                           exp_r[ierrfirst*n+jerrfirst], exp_i[ierrfirst*n+jerrfirst]);

        fprintf(snp_file, "\n                           Error MAX\n");
        fprintf(snp_file, "           tst[%d][%d]                                exp[%d][%d] \n",
                           ierr, jerr, ierr, jerr);
        fprintf(snp_file, "(%.10f, %.10f)               (%.10f, %.10f)\n",
                           tst_r[ierr*n+jerr], tst_i[ierr*n+jerr],
                           exp_r[ierr*n+jerr], exp_i[ierr*n+jerr]);

        fprintf(snp_file, "\nMatrix gauge %e\n", gauge);
        fprintf(snp_file, "\nFirst error  (%e, %e)\n", fabs(tst_r[ierrfirst*n+jerrfirst]-exp_r[ierrfirst*n+jerrfirst]),
                           fabs(tst_i[ierrfirst*n+jerrfirst]-exp_i[ierrfirst*n+jerrfirst]));
        fprintf(snp_file, "MAX error    (%e, %e)\n\n", fabs(tst_r[ierr*n+jerr]-exp_r[ierr*n+jerr]),
                           fabs(tst_i[ierr*n+jerr]-exp_i[ierr*n+jerr]));
        }
    } else {
        if(isign == 0) {
            fprintf(snp_file, "%s  ISIGN = -1:+1 \tM = %d N = %d \n", 
                   fname, m, n);
		} else if(isign == 22){
            fprintf(snp_file, "%s  ISIGN = -2:+2 \tM = %d N = %d \n", 
                    fname, m, n);
		} else {
            fprintf(snp_file, "%s  ISIGN = %d    \tM = %d N = %d \n", 
                    fname, isign, m, n);
		}/* if */
      
    }/* if error */

    CLOSE_SNAP;
    return 0;
}/* zest */


/* Function start */
int cest(float *tst, float *tst_r, float *tst_i, float *exp_r, float *exp_i,
         int m, int n, float gauge)
{
    int ierr, jerr, ierrfirst, jerrfirst;
    float err = (float)0.0;
    float errij;
    float diff_r, diff_i;
    int error = 0;
    int i,j;

    ierrfirst = -1;
    jerrfirst = -1;
    for(i = 0; i < m; i++ ) {
        for(j = 0; j < n; j++ ) {
//            if (r_type) {
//                printf("tst_r[%d*%d+%d] = %f , exp_r[%d*%d+%d] = %f \n", i,n,j, tst_r[i*n+j], i,n,j, exp_r[i*n+j]);
//                printf("tst_i[%d*%d+%d] = %f , exp_i[%d*%d+%d] = %f \n", i,n,j, tst_i[i*n+j], i,n,j, exp_i[i*n+j]);
//            }
			diff_r = tst_r[i*n+j] - exp_r[i*n+j];
            diff_i = tst_i[i*n+j] - exp_i[i*n+j];
            errij = (float) (sqrt( diff_r*diff_r + diff_i*diff_i ) / feps);
            if( gauge != (float)zero ) errij = errij / (gauge);  
            if(errij > err ) {
                err =  errij;
                ierr = i;
                jerr = j;
			}/* if */
      
			if(errij >= (float)one) {
                error = 1;
                if(ierrfirst == -1) {
                    ierrfirst = ierr;
                    jerrfirst = jerr;
				}/* if */
			}/* if */
		}/* for j */
	}/* for i */

    if (!error && !dft_compare) error = cpostm(tst, tst_r, tst_i, exp_r, exp_i, m, n);

    OPEN_SNAP;
    if( error ) {
        fatal[ifunc] = 1;
        if(isign == 0) {
            fprintf(snp_file, "%s  ISIGN = -1:+1 \tM = %d N = %d :ERROR\n", 
                    fname, m, n);
        } else if(isign == 22){
            fprintf(snp_file, "%s  ISIGN = -2:+2 \tM = %d N = %d :ERROR\n", 
                    fname, m, n);
        } else {
            fprintf(snp_file, "%s  ISIGN = %d    \tM = %d N = %d :ERROR\n", 
                    fname, isign, m, n);
		}/* if */

        if (error != 2) {
        fprintf(snp_file, "**** Fatal Error - computed result is less than half accurate ***\n");
        fprintf(snp_file, "     Computed result                      Expected result\n");

        fprintf(snp_file, "\n                           Error first\n");
        fprintf(snp_file, "           tst[%d][%d]                                exp[%d][%d] \n",
                           ierrfirst, jerrfirst, ierrfirst, jerrfirst);
        fprintf(snp_file, "(%.10f, %.10f)               (%.10f, %.10f)\n",
                           tst_r[ierrfirst*n+jerrfirst], tst_i[ierrfirst*n+jerrfirst],
                           exp_r[ierrfirst*n+jerrfirst], exp_i[ierrfirst*n+jerrfirst]);

        fprintf(snp_file, "\n                           Error MAX\n");
        fprintf(snp_file, "           tst[%d][%d]                                exp[%d][%d] \n",
                           ierr, jerr, ierr, jerr);
        fprintf(snp_file, "(%.10f, %.10f)               (%.10f, %.10f)\n",
                           tst_r[ierr*n+jerr], tst_i[ierr*n+jerr],
                           exp_r[ierr*n+jerr], exp_i[ierr*n+jerr]);



        fprintf(snp_file, "\nMatrix gauge %e\n", gauge);
        fprintf(snp_file, "\nFirst error  (%e, %e)\n", fabs(tst_r[ierrfirst*n+jerrfirst]-exp_r[ierrfirst*n+jerrfirst]),
                           fabs(tst_i[ierrfirst*n+jerrfirst]-exp_i[ierrfirst*n+jerrfirst]));
        fprintf(snp_file, "MAX error    (%e, %e)\n\n", fabs(tst_r[ierr*n+jerr]-exp_r[ierr*n+jerr]),
                           fabs(tst_i[ierr*n+jerr]-exp_i[ierr*n+jerr]));
        }
	} else {
        if(isign == 0) {
            fprintf(snp_file, "%s  ISIGN = -1:+1 \tM = %d N = %d \n", 
                    fname, m, n);
        } else if(isign == 22){
            fprintf(snp_file, "%s  ISIGN = -2:+2 \tM = %d N = %d \n", 
                    fname, m, n);
        } else {
            fprintf(snp_file, "%s  ISIGN = %d    \tM = %d N = %d \n", 
                    fname, isign, m, n);
		}/* if */
      
    }/* if error */

    CLOSE_SNAP;
    return 0;
}/* cest */


/* Function start */
void d_fill_rand(double *a, int m, int n)
{
int i,j;
for (i = 0; i < m; i++) {
  for (j = 0; j < n; j++) {
    a[i*n+j] = ((double)rand())/((double)RAND_MAX) - 0.5;
  }
}

}

/* Function start */
void s_fill_rand(float *a, int m, int n)
{
int i,j;
for (i = 0; i < m; i++) {
  for (j = 0; j < n; j++) {
    a[i*n+j] = (float)((float)rand())/((float)RAND_MAX) - (float)0.5;
  }
}

}

/* Function start */
void d_copy(double *a, double *b, int m, int n)
{
int i,j;
for (i = 0; i < m; i++) {
  for (j = 0; j < n; j++) {
    b[i*n+j] = a[i*n+j] ;
  }
}

}

/* Function start */
void s_copy(float *a, float *b, int m, int n)
{
int i,j;
for (i = 0; i < m; i++) {
  for (j = 0; j < n; j++) {
    b[i*n+j] = a[i*n+j] ;
  }
}

}

/* Function start */
void dz_copy_s(double *a, double *a_ro, double *a_io, int m, int n)
{
int i,j,n2;

n2 = n+2;
for (i = 0; i < m; i++) {
  for (j = 0; j < n; j++) {
    a_ro[i*n+j] = a[i*n2+j] ;
    a_io[i*n+j] = 0.0;
  }
}

}

/* Function start */
void sc_copy_s(float *a, float *a_ro, float *a_io, int m, int n)
{
int i,j,n2;

n2 = n+2;
for (i = 0; i < m; i++) {
  for (j = 0; j < n; j++) {
    a_ro[i*n+j] = a[i*n2+j] ;
    a_io[i*n+j] = (float)0.0;
  }
}

}


/* Function start */
void dz_copy(double *a, double *a_ro, double *a_io, int m, int n)
{
int i,j;
int n2, m2, nn;

n2 = n+2;
m2 = m+2;

      a_ro[0] = a[0];
      a_io[0] = 0.0;

      if (m > 1) {
        a_ro[(m/2)*n] = a[(m/2)*n2];
        a_io[(m/2)*n] = 0.0;
      }

      for ( i = 1; i < m/2; i++) {
        a_ro[i*n] = a[i*n2];
        a_io[i*n] = a[(m/2+i+1)*n2];
        a_ro[(m-i)*n] = a[i*n2];
        a_io[(m-i)*n] = -a[(m/2+i+1)*n2];
      }

      if (n > 1) {
        nn = n/2;
        a_ro[nn] = a[nn];
        a_io[nn] = 0.0;

        if (m > 1) {
          a_ro[(m/2)*n+nn] = a[(m/2)*n2+nn];
          a_io[(m/2)*n+nn] = 0.0;
        }

        for ( i = 1; i < m/2; i++) {
          a_ro[i*n+nn] = a[i*n2+nn];
          a_io[i*n+nn] = a[(m/2+i+1)*n2+nn];
          a_ro[(m-i)*n+nn] = a[i*n2+nn];
          a_io[(m-i)*n+nn] = -a[(m/2+i+1)*n2+nn];
        }
      }


      for ( j = 1; j < n/2; j++) {
        a_ro[j] = a[j];
        a_io[j] = a[n/2+j+1];
        a_ro[n-j] = a[j];
        a_io[n-j] = -a[n/2+j+1];
        for ( i = 1; i < m; i++) {
          a_ro[i*n+j] = a[i*n2+j];
          a_io[i*n+j] = a[i*n2+n/2+j+1];
          a_ro[(m-i)*n+n-j] = a[i*n2+j];
          a_io[(m-i)*n+n-j] = -a[i*n2+n/2+j+1];
        }
      }

}

/* Function start */
void sc_copy(float *a, float *a_ro, float *a_io, int m, int n)
{
int i,j;
int n2, m2, nn;

n2 = n+2;
m2 = m+2;

      a_ro[0] = a[0];
      a_io[0] = (float)0.0;

      if (m > 1) {
        a_ro[(m/2)*n] = a[(m/2)*n2];
        a_io[(m/2)*n] = (float)0.0;
      }

      for ( i = 1; i < m/2; i++) {
        a_ro[i*n] = a[i*n2];
        a_io[i*n] = a[(m/2+i+1)*n2];
        a_ro[(m-i)*n] = a[i*n2];
        a_io[(m-i)*n] = -a[(m/2+i+1)*n2];
      }

      if (n > 1) {
        nn = n/2;
        a_ro[nn] = a[nn];
        a_io[nn] = (float)0.0;

        if (m > 1) {
          a_ro[(m/2)*n+nn] = a[(m/2)*n2+nn];
          a_io[(m/2)*n+nn] = (float)0.0;
        }

        for ( i = 1; i < m/2; i++) {
          a_ro[i*n+nn] = a[i*n2+nn];
          a_io[i*n+nn] = a[(m/2+i+1)*n2+nn];
          a_ro[(m-i)*n+nn] = a[i*n2+nn];
          a_io[(m-i)*n+nn] = -a[(m/2+i+1)*n2+nn];
        }
      }


      for ( j = 1; j < n/2; j++) {
        a_ro[j] = a[j];
        a_io[j] = a[n/2+j+1];
        a_ro[n-j] = a[j];
        a_io[n-j] = -a[n/2+j+1];
        for ( i = 1; i < m; i++) {
          a_ro[i*n+j] = a[i*n2+j];
          a_io[i*n+j] = a[i*n2+n/2+j+1];
          a_ro[(m-i)*n+n-j] = a[i*n2+j];
          a_io[(m-i)*n+n-j] = -a[i*n2+n/2+j+1];
        }
      }


}

/* Function start */
double d_gauge(double *a_r, double *a_i, int m, int n, int isign)
{
double accm;
int i, j;
  accm = 0.0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      accm += a_r[i*n+j]*a_r[i*n+j] + a_i[i*n+j]*a_i[i*n+j];
    }
  }
  if (isign >= 0) accm /= (double)m*n;
  return accm;
}

/* Function start */
float s_gauge(float *a_r, float *a_i, int m, int n, int isign)
{
float accm;
int i, j;
  accm = (float)0.0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      accm += a_r[i*n+j]*a_r[i*n+j] + a_i[i*n+j]*a_i[i*n+j];
    }
  }
  if (isign >= 0) accm /= (float)m*n;
  return accm;
}


/* Function start */
void call_func(int num, int m, int n, int isign, void *ar, void *ai) {

switch (num) {
  case ZFFT2DC_:    
    zfft2dc((double*)ar, (double*)ai, m, n, isign);
    break;

  case CFFT2DC_:    
    cfft2dc((float*)ar, (float*)ai, m, n, isign);
    break;

  case DZFFT2DC_:    
    dzfft2dc((double*)ar, m, n);
    break;

  case ZDFFT2DC_:    
    zdfft2dc((double*)ar, m, n);
    break;

  case SCFFT2DC_:    
    scfft2dc((float*)ar, m, n);
    break;

  case CSFFT2DC_:    
    csfft2dc((float*)ar, m, n);
    break;
}
}

/* ---------------------------------------------------------
*  --                                                     --
*  --     Input parameters check                          --
*  --                                                     --
*  ---------------------------------------------------------
*/

void cherr (int num) {

double a_r[256], a_i[256], w[256];
void   *ar, *ai, *ww;
int    m, n, isign;

  ar = (void*)a_r;
  ai = (void*)a_i;
  ww = (void*)w;

  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT2DC_ || ifunc == CFFT2DC_ ) 
    code_err_t = 3;
  else 
    code_err_t = 2;
  m = -1;
  n = -1;
  isign = -5;
  call_func(num, m, n, isign, ar, ai);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! m = %d, n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! m = %d,  n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT2DC_ || ifunc == CFFT2DC_ ) 
    code_err_t = 3;
  else 
    code_err_t = 2;
  m = 0;
  n = -1;
  isign = -5;
  call_func(num, m, n, isign, ar, ai);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! m = %d, n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! m = %d,  n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT2DC_ || ifunc == CFFT2DC_ ) 
    code_err_t = 4;
  else 
    code_err_t = 3;
  m = 2;
  n = -1;
  isign = -5;
  call_func(num, m, n, isign, ar, ai);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! m = %d, n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! m = %d,  n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT2DC_ || ifunc == CFFT2DC_ ) 
    code_err_t = 4;
  else 
    code_err_t = 3;
  m = 2;
  n = 0;
  isign = -5;
  call_func(num, m, n, isign, ar, ai);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! m = %d, n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! m = %d,  n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  if (ifunc == ZFFT2DC_ || ifunc == CFFT2DC_ ) {
    ok_g = 0;
    xerbla_called = 0;
    code_err_t = 5;
    m = 2;
    n = 2;
    isign = -5;
    call_func(num, m, n, isign, ar, ai);
    if ( !xerbla_called ) {
      printf("  %s: error %d is not catched! m = %d, n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
      OPEN_SNAP;
      fprintf(snp_file, "  %s: error %d is not catched! m = %d,  n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
      CLOSE_SNAP;
    }
    if ( !ok_g ) fatal[ifunc] = 1;

 //   ok_g = 0;
 //   xerbla_called = 0;
 //   code_err_t = 5;
//    m = 2;
//    n = 2;
//    isign = 0;
 //   call_func(num, m, n, isign, ar, ai);
 //   if ( !xerbla_called ) {
 //     printf("  %s: error %d is not catched! m = %d, n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
 //     OPEN_SNAP;
 //     fprintf(snp_file, "  %s: error %d is not catched! m = %d,  n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
 //     CLOSE_SNAP;
 //   }
 //  if ( !ok_g ) fatal[ifunc] = 1;
  
    ok_g = 0;
    xerbla_called = 0;
    code_err_t = 5;
    m = 2;
    n = 2;
    isign = 3;
    call_func(num, m, n, isign, ar, ai);
    if ( !xerbla_called ) {
      printf("  %s: error %d is not catched! m = %d, n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
      OPEN_SNAP;
      fprintf(snp_file, "  %s: error %d is not catched! m = %d,  n = %d, isign = %d\n", fname, code_err_t, m, n, isign);
      CLOSE_SNAP;
    }
    if ( !ok_g ) fatal[ifunc] = 1;
  }

  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT2DC_ || ifunc == CFFT2DC_ ) 
    code_err_t = 1;
  else 
    code_err_t = 1;
  m = 2;
  n = 2;
  isign = 1;
  call_func(num, m, n, isign, NULL, ai);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! First parameter is NULL pointer\n", fname, code_err_t);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! First parameter is NULL pointer\n", fname, code_err_t);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  if (ifunc == ZFFT2DC_ || ifunc == CFFT2DC_ ) {
    ok_g = 0;
    xerbla_called = 0;
    code_err_t = 2;
    m = 2;
    n = 2;
    isign = 1;
    call_func(num, m, n, isign, ar, NULL);
    if ( !xerbla_called ) {
      printf("  %s: error %d is not catched! Second parameter is NULL pointer\n", fname, code_err_t);
      OPEN_SNAP;
      fprintf(snp_file, "  %s: error %d is not catched! Second parameter is NULL pointer\n", fname, code_err_t);
      CLOSE_SNAP;
    }
    if ( !ok_g ) fatal[ifunc] = 1;
  }
}

/* ---------------------------------------------------------
*  --                                                     --
*  --     E R R O R       H A N D L I N G                 --
*  --                                                     --
*  ---------------------------------------------------------
*/
void XERBLA(char* name_func, int *ind_err) {

/*     printf("Xerbla called with %s, %d \n", name_func, *ind_err); */
      ok_g = 1;
      xerbla_called = 1;

      if (code_err_t == 0) {
        printf("**** FATAL: XERBLA was called while test executing with err_code = %d from function %s\n", *ind_err, name_func);
        OPEN_SNAP;
        fprintf(snp_file, "**** FATAL: XERBLA was called while test executing with err_code = %d from function %s\n", *ind_err, name_func);
        CLOSE_SNAP;
        exit(1);
      }

      if ( *ind_err != code_err_t ) {
         if ( code_err_t != 0 ) {
             printf("**** XERBLA was called with ind_code = %d instead  of %d ****\n", *ind_err, code_err_t );
             OPEN_SNAP;
             fprintf(snp_file, "**** XERBLA was called with ind_code = %d instead  of %d ****\n", *ind_err, code_err_t );
             CLOSE_SNAP;
         }
         else {
             printf("**** XERBLA was called with ind_code = %d\n", *ind_err);
             OPEN_SNAP;
             fprintf(snp_file, "**** XERBLA was called with ind_code = %d\n", *ind_err);
             CLOSE_SNAP;
         }
         ok_g = 0;
      }

      if ( strcmp(name_func, fname) ) {
         printf("**** XERBLA was called with name_func = %s instead of %s ****\n", name_func, fname);
         OPEN_SNAP;
         fprintf(snp_file, "**** XERBLA was called with name_func = %s instead of %s ****\n", name_func, fname);
         CLOSE_SNAP;
         ok_g = 0;
      }

      code_err_t = 0;
      return;

}

/* Function start */
void zdft(int m, int n)
{
    double *a_r = NULL, *a_i = NULL;
    double *a_rs = NULL, *a_is = NULL;
    double *a_rdft = NULL, *a_idft = NULL;
    double *a_rtmp = NULL, *a_itmp = NULL;
    double *tw = NULL;
    double gauge;

    a_r = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_i = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_rs = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_is = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_rdft = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_idft = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_rtmp = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_itmp = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);

    tw = (double *)LocalAlloc(LMEM_FIXED, 2*(m+n)*elm_size);

    if(a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
	   a_rdft != NULL && a_idft != NULL &&
       tw != NULL && a_rtmp != NULL && a_itmp != NULL )  {

        /* Compare with DFT routine, isign = -+1 */
        d_fill_rand(a_r, m, n);
        d_fill_rand(a_i, m, n);

        isign = -1;
        gauge = d_gauge(a_r, a_i, m, n, isign);

        zdft2d(a_r, a_i, m, n, -1, a_rdft, a_idft, tw, a_rtmp, a_itmp);
        zdft2d(a_rdft, a_idft, m, n, 1, a_rs, a_is, tw, a_rtmp, a_itmp);

        zest (a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

	}/* if allocate */

    LocalFree(tw);
    LocalFree(a_itmp);
    LocalFree(a_rtmp);
    LocalFree(a_idft);
    LocalFree(a_rdft);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);

}/* zdft */

/* Function start */
void cdft(int m, int n)
{
    float *a_r = NULL, *a_i = NULL;
    float *a_rs = NULL, *a_is = NULL;
    float *a_rdft = NULL, *a_idft = NULL;
    float *a_rtmp = NULL, *a_itmp = NULL;
    float *tw = NULL;
    float gauge;

    a_r = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_i = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_rs = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_is = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_rdft = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_idft = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_rtmp = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_itmp = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);

    tw = (float *)LocalAlloc(LMEM_FIXED, 2*(m+n)*elm_size);


    if(a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
	   a_rdft != NULL && a_idft != NULL &&
       tw != NULL && a_rtmp != NULL && a_itmp != NULL )  {

        /* Compare with DFT routine, isign = -+1 */
        s_fill_rand(a_r, m, n);
        s_fill_rand(a_i, m, n);

        isign = -1;
        gauge = s_gauge(a_r, a_i, m, n, isign);

        cdft2d(a_r, a_i, m, n, -1, a_rdft, a_idft, tw, a_rtmp, a_itmp);
        cdft2d(a_rdft, a_idft, m, n, 1, a_rs, a_is, tw, a_rtmp, a_itmp);

        cest (a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

	}/* if allocate */

	LocalFree(tw);
    LocalFree(a_itmp);
    LocalFree(a_rtmp);
    LocalFree(a_idft);
    LocalFree(a_rdft);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);

}/* cdft */

/* Function start */
void zfft_s(int m, int n)
{
    double *a_r = NULL, *a_i = NULL;
    double *a_rs = NULL, *a_is = NULL;
    double *a_rtmp = NULL, *a_itmp = NULL;
    double *tw = NULL;
    double gauge;

    a_r = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_i = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_rs = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_is = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);

    tw = (double *)LocalAlloc(LMEM_FIXED, 2*(m+n)*elm_size);
    a_rtmp = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_itmp = (double *)LocalAlloc(LMEM_FIXED, m*n*elm_size);


    if(a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
       tw != NULL && a_rtmp != NULL && a_itmp != NULL )  {

        /* Compare with DFT routine, isign = -1 */
        d_fill_rand(a_r, m, n);
        d_fill_rand(a_i, m, n);

        isign = -1;
        gauge = d_gauge(a_r, a_i, m, n, isign);

        zdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);

        ZFFT2DC_S(a_r, a_i, m, n, isign);

        zest (a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

        /* Compare with DFT routine, isign = 1 */
        d_fill_rand(a_r, m, n);
        d_fill_rand(a_i, m, n);

        isign = 1;
        gauge = d_gauge(a_r, a_i, m, n, isign);

        zdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);

        ZFFT2DC_S(a_r, a_i, m, n, isign);

        zest (a_r, a_r, a_i, a_rs, a_is, m, n, gauge);
	}/* if allocate */

    LocalFree(tw);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);

}/* zfft_s */


/* Function start */
void cfft_s(int m, int n)
{
    float *a_r = NULL, *a_i = NULL;
    float *a_rs = NULL, *a_is = NULL;
    float *a_rtmp = NULL, *a_itmp = NULL;
    float *tw = NULL;
    float gauge;

    a_r = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_i = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_rs = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_is = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);

    tw = (float *)LocalAlloc(LMEM_FIXED, 2*(m+n)*elm_size);
    a_rtmp = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);
    a_itmp = (float *)LocalAlloc(LMEM_FIXED, m*n*elm_size);


    if(a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
       tw != NULL && a_rtmp != NULL && a_itmp != NULL )  {

        /* Compare with DFT routine, isign = -1 */
        s_fill_rand(a_r, m, n);
        s_fill_rand(a_i, m, n);

        isign = -1;
        gauge = s_gauge(a_r, a_i, m, n, isign);

        cdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);

        CFFT2DC_S(a_r, a_i, m, n, isign);

        cest (a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

        /* Compare with DFT routine, isign = 1 */
        s_fill_rand(a_r, m, n);
        s_fill_rand(a_i, m, n);

        isign = 1;
        gauge = s_gauge(a_r, a_i, m, n, isign);

        cdft2d(a_r, a_i, m, n, isign, a_rs, a_is, tw, a_rtmp, a_itmp);

        CFFT2DC_S(a_r, a_i, m, n, isign);

        cest (a_r, a_r, a_i, a_rs, a_is, m, n, gauge);

	}/* if allocate */

	LocalFree(tw);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);
 
}/* cfft_s */
int cpostm (float* a, float* a_r, float* a_i, float* a_rs, float* a_is,
			int m, int n)
{
    int s;

	if (!strcmp(fname,"CDFT2DC") || !strcmp(fname,"CFFT2DC_SAMPLE")) return 0;

    if (r_type) { 
		for (s = 0; s < POST_MN; s++) {
		    if (a[(m+2)*(n+2)+s] != a_rs[m*n+s]) {
			    printf("\n Error (matrix size = %d * %d, isign = %d ) : using of memory after array. \n", m, n, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (matrix size = %d * %d, isign = %d ) : using of memory after array. \n", m, n, isign);
				CLOSE_SUM;
			    return 2;
			}
		}
	} else { 
	    for (s = 0; s < POST_MN; s++) {
		    if (a_r[m*n+s] != a_rs[m*n+s]) {
			    printf("\n Error (matrix size = %d * %d, isign = %d ) : using of memory after real array. \n", m, n, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (matrix size = %d * %d, isign = %d ) : using of memory after real array. \n", m, n, isign);
				CLOSE_SUM;
			    return 2;
			}
		}
	    for (s = 0; s < POST_MN; s++) {
		    if (a_i[m*n+s] != a_is[m*n+s]) {
			    printf("\n Error (matrix size = %d * %d, isign = %d ) : using of memory after image array. \n", m, n, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (matrix size = %d * %d, isign = %d ) : using of memory after image array. \n", m, n, isign);
				CLOSE_SUM;
			    return 2;
			}
		}
	}
    return 0;     
}

int zpostm (double* a, double* a_r, double* a_i, double* a_rs, double* a_is,
			int m, int n)
{
    int s;

	if (!strcmp(fname,"ZDFT2DC") || !strcmp(fname,"ZFFT2DC_SAMPLE")) return 0;

    if (r_type) { 
		for (s = 0; s < POST_MN; s++) {
			if (a[(m+2)*(n+2)+s] != a_rs[m*n+s]) {
//    printf("cmp: a = %f a_rs = %f \n", a[(m+2)*(n+2)], a_rs[m*n]); 
			    printf("\n Error (matrix size = %d * %d, isign = %d ) : using of memory after array. \n", m, n, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (matrix size = %d * %d, isign = %d ) : using of memory after array. \n", m, n, isign);
				CLOSE_SUM;
			    return 2;
			}
		}
	} else { 
		for (s = 0; s < POST_MN; s++) {
		    if (a_r[m*n+s] != a_rs[m*n+s]) {
			    printf("\n Error (matrix size = %d * %d, isign = %d ) : using of memory after real array. \n", m, n, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (matrix size = %d * %d, isign = %d) : using of memory after real array. \n", m, n, isign);
				CLOSE_SUM;
			    return 2;
			}
		}
	    for (s = 0; s < POST_MN; s++) {
		    if (a_i[m*n+s] != a_is[m*n+s]) {
			    printf("\n Error (matrix size = %d * %d, isign = %d ) : using of memory after image array. \n", m, n, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (matrix size = %d * %d, isign = %d ) : using of memory after image array. \n", m, n, isign);
				CLOSE_SUM;
			    return 2;
			}
		}
	}
    return 0;     
}
