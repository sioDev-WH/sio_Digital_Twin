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
//       C-style FFT one-dimension TEST
//
//  Author  : Gvozdev E., Sivolgina O.
//
*M*/

/*
* --- Version:
* ---    .09.97
* ---     RFNC (VNIIEF), Department 8, Gvozdev E.
* ---     for INTEL

* ---    Modified .07.99
* ---     RFNC (VNIIEF), Department 8, Sivolgina O.
* ---     for INTEL

* --- Function:
* ---     Testing program for test FFT 1D C-interface routines
*         Thread safe test for SCFFT1DC
*/

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <float.h>
#include "fft_test.h"

#define cfft1dc CFFT1DC
#define zfft1dc ZFFT1DC
#define csfft1dc CSFFT1DC
#define scfft1dc SCFFT1DC
#define zdfft1dc ZDFFT1DC
#define dzfft1dc DZFFT1DC

#define ZFFT1DC_   0 
#define CFFT1DC_   1
#define DZFFT1DC_  2
#define ZDFFT1DC_  3
#define SCFFT1DC_  4
#define CSFFT1DC_  5
#define ZDFT_      6
#define CDFT_      7
#define ZFFT_S     8
#define CFFT_S     9


#define NUM_DFT_CHECK 12
int dim_dft[NUM_DFT_CHECK] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

/*
#define NUM_DFT_CHECK 2
int dim_dft[NUM_DFT_CHECK] = {1, 2};
*/

#define FUNC_NUM_S 10
#define FUNC_NUM 6
#define DIM_NUM  25

#define NAME_LEN    128
#define MESSAGE_LEN 1024
char snp_file_name[NAME_LEN], sum_file_name[NAME_LEN]; 
char *in_file_name;

char message[MESSAGE_LEN];

double deps;
float feps;

FILE *in_file, *snp_file, *sum_file;
int  self_test, dft_compare, fail_stop, test_error_exit, test_cmpt;
int  what_test[FUNC_NUM];
int  num1, post_m;
int  dim1[DIM_NUM];
int  z_type, c_type, r_type;
int  elm_size;
int  code_err_t;
int  xerbla_called;
int  ok_g;
char fnames[FUNC_NUM_S][NAME_LEN] = {
                          "ZFFT1DC",
                          "CFFT1DC",
                          "DZFFT1DC",
                          "ZDFFT1DC",
                          "SCFFT1DC",
                          "CSFFT1DC",
                          "ZDFT1DC",
                          "CDFT1DC",
                          "ZFFT1DC_SAMPLE",
                          "CFFT1DC_SAMPLE"
                          };

char *fname;
int  isign;
int  ifunc;
int  fatal[FUNC_NUM_S];

#define  REDUNT8   256
#define  REDUNT4   256

int     boundary;
int     s_boundary;
int     d_boundary;

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


extern void ZFFT1DC_S(double *a_r, double *a_i, int m, int isign, double *tw);
extern void CFFT1DC_S(float *a_r, float *a_i, int m, int isign, float *tw);
extern void ZFFT1DC  (double *a_r, double *a_i, int m, int isign, double *tw);
extern void CFFT1DC  (float *a_r, float *a_i, int m, int isign, float *tw);
extern void DZFFT1DC (double *a, int m, int isign, double *tw);
extern void ZDFFT1DC (double *a, int m, int isign, double *tw);
extern void SCFFT1DC (float *a, int m, int isign, float *tw);
extern void CSFFT1DC (float *a, int m, int isign, float *tw);

extern int _isnan (double);

void   out_message(char* mes);
int    read_line(FILE* fp, char* buf );
int    get_str(char* str, ...);
void   Exit_(int code);
void   read_in_file(void);
void   summary(void);

double d_gauge(double *a_r, double *a_i, int m, int isign);
float  s_gauge(float *a_r, float *a_i, int m, int isign);

void   d_fill_rand(double *a, int m);
void   s_fill_rand(float *a, int m);

void   d_copy(double *a, double *b, int m);
void   s_copy(float *a, float *b, int m);

void   dz_copy_s(double *a, double *a_ro, double *a_io, int m);
void   sc_copy_s(float *a, float *a_ro, float *a_io, int m);

void   dz_copy(double *a, double *a_ro, double *a_io, int m);
void   sc_copy(float *a, float *a_ro, float *a_io, int m);

void   zd_copy(double *a, double *a_ro, double *a_io, int m);
void   cs_copy(float *a, float *a_ro, float *a_io, int m);

void   zfft(int m);
void   cfft(int m);

void   dzfft(int m, int fi);
void   scfft(int m, int fi);

void   zdft(int m);
void   cdft(int m);

void   zfft_s(int m);
void   cfft_s(int m);

void   zdft1d (double *a_ri, double *a_ii, int m, int isign, 
               double *a_ro, double *a_io, double *tw );
void   cdft1d (float *a_ri, float *a_ii, int m, int isign, 
               float *a_ro, float *a_io, float *tw );

int    cpostm (float*, float*, float*, float*, float*, float*, float*, int, int);
int    zpostm (double*, double*, double*, double*, double*, double*, double*, int, int);
int    zest(double*, double*, double*, double*, double*, double*, double*,
            int, int, double);
int    cest(float*, float*, float*, float*, float*, float*, float*,
            int, int, float);

void cherr    (int num);
void call_func(int num, int m, int isign, void* ar, void* ai, void* w);
void XERBLA   (char* name_func, int *ind_err);

/* Function start */
void main( int argc, char * argv[] )
{

int idim1;
int i;
int ok;
/*
     MKLStart();
*/
if (argc == 1) {
  out_message("You must specify Input file name as 1-st parameter\n");
  Exit_(1);
}

in_file_name = argv[1];
srand(1);

read_in_file();

summary();


  d_boundary = boundary;
  s_boundary = boundary;

  if(((boundary>>3)<<3) != boundary)
  	  d_boundary += 4;

  for (i = 0; i < num1; i++) 
  dim1[i] = 1 << dim1[i];


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

            for (idim1 = 0; idim1 < NUM_DFT_CHECK; idim1++) {

                if (ifunc == ZDFT_ )
                    zdft(dim_dft[idim1]);

                if (ifunc == CDFT_ )
                    cdft(dim_dft[idim1]);

                if (ifunc == ZFFT_S )
                    zfft_s(dim_dft[idim1]);

                if (ifunc == CFFT_S )
                    cfft_s(dim_dft[idim1]);

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
    printf(" %s :\t Input parameters test", fnames[ifunc]);
    fprintf(sum_file, " %s :\t Input parameters test", fnames[ifunc]);
    CLOSE_SUM;

    fname = fnames[ifunc];
    z_type = c_type = r_type = 0;
    if (ifunc == ZFFT1DC_ || ifunc == ZDFFT1DC_ || ifunc == DZFFT1DC_) z_type = 1;
    if (ifunc == CFFT1DC_ || ifunc == CSFFT1DC_ || ifunc == SCFFT1DC_) c_type = 1;
    if (ifunc == ZDFFT1DC_ || ifunc == DZFFT1DC_ ||
        ifunc == CSFFT1DC_ || ifunc == SCFFT1DC_) r_type = 1;

    if (z_type) 
      elm_size = 8;
    else
      elm_size = 4;

    ok = 0;

    switch(ifunc) {
    case ZFFT1DC_:
      if (what_test[ZFFT1DC_])
        ok = 1;
      break;
    case CFFT1DC_:
      if (what_test[CFFT1DC_])
        ok = 1;
      break;
    case ZDFFT1DC_:
      if (what_test[ZDFFT1DC_])
        ok = 1;
      break;
    case DZFFT1DC_:
      if (what_test[DZFFT1DC_])
        ok = 1;
      break;
    case SCFFT1DC_:
      if (what_test[SCFFT1DC_])
        ok = 1;
      break;
    case CSFFT1DC_:
      if (what_test[CSFFT1DC_])
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
        printf("\t ERROR\n");
        fprintf(sum_file, "\t ERROR\n");
      }
    }
    CLOSE_SUM;

  }

}

if (test_cmpt) {
    for (ifunc = 0; ifunc < FUNC_NUM; ifunc++) {

    OPEN_SUM;
    if (what_test[ifunc]) {
      printf(" %s :\t Computational test", fnames[ifunc]);
      fprintf(sum_file, " %s :\t Computational test", fnames[ifunc]);
    }
    CLOSE_SUM;

    fname = fnames[ifunc];
    z_type = c_type = r_type = 0;
    if (ifunc == ZFFT1DC_ || ifunc == ZDFFT1DC_ || ifunc == DZFFT1DC_) z_type = 1;
    if (ifunc == CFFT1DC_ || ifunc == CSFFT1DC_ || ifunc == SCFFT1DC_) c_type = 1;
    if (ifunc == ZDFFT1DC_ || ifunc == DZFFT1DC_ ||
        ifunc == CSFFT1DC_ || ifunc == SCFFT1DC_) r_type = 1;

    if (z_type) 
      elm_size = 8;
    else
      elm_size = 4;

    for (idim1 = 0; idim1 < num1; idim1++) {

      if (ifunc == ZFFT1DC_ && what_test[ZFFT1DC_])
        zfft(dim1[idim1]);

      if (ifunc == CFFT1DC_ && what_test[CFFT1DC_] ) {
        cfft(dim1[idim1]);
    
      }

      if (ifunc == DZFFT1DC_ && what_test[DZFFT1DC_]) {
        if (what_test[ZDFFT1DC_])
          dzfft(dim1[idim1], 0);
        else
          dzfft(dim1[idim1], -1);

      }

      if (ifunc == ZDFFT1DC_ && what_test[ZDFFT1DC_])
        dzfft(dim1[idim1], 1);

      if (ifunc == SCFFT1DC_ && what_test[SCFFT1DC_]) {
        if (what_test[CSFFT1DC_])
          scfft(dim1[idim1], 0);
        else
          scfft(dim1[idim1], -1);

      }

      if (ifunc == CSFFT1DC_ && what_test[CSFFT1DC_])
       scfft(dim1[idim1], 1);

   }

    OPEN_SUM;
    if (what_test[ifunc]) {
      if (!fatal[ifunc]) {
        printf("\t PASSED \n");
        fprintf(sum_file, "\t PASSED\n");
      }
      else {
        printf("\t ERROR\n");
        fprintf(sum_file, "\t ERROR\n");
      }
    }
    CLOSE_SUM;
  }
}
/*
     MKLEnd();
*/
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

OPEN_FILE(in_file, in_file_name, "rb");

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
feps = (float)atof(buf);


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
        sprintf(message,"Can't read aligning boundary.\n");
        out_message(message);
        Exit_(1);
    }/* if */
    if (get_str(buf, 1, "%d", &boundary)) {
        sprintf(message,"Can't read aligning boundary.\n");
        out_message(message);
        Exit_(1);
    }/* if */

    if ( boundary > 64){
        sprintf(message,"Aligning boundary must be less than 64.\n");
        out_message(message);
        Exit_(1);
    }/* if */

    if ( ((boundary>>2)<<2) != boundary) {
        sprintf(message,"Aligning boundary must be divisible by 4\n");
        out_message(message);
        Exit_(1);
    }/* if */

    if (!read_line(in_file, buf)) {
        sprintf(message,"Can't read number of vector lengths from input file.\n");
        out_message(message);
        Exit_(1);
    }

if (get_str(buf, 1, "%d", &num1)) {
  sprintf(message,"Can't read number of vector lengths\n");
  out_message(message);
  Exit_(1);
}

if (num1 >= DIM_NUM) {
  sprintf(message,"Wrong number of vector length (must be < 20).\n");
  out_message(message);
  Exit_(1);
}

if (!read_line(in_file, buf)) {
  sprintf(message,"Can't read lengths of vectors from input file.\n");
  out_message(message);
  Exit_(1);
}

if (get_str(buf, num1, "%d", dim1, "%d", dim1+1, "%d", dim1+2, "%d", dim1+3,
                      "%d", dim1+4, "%d", dim1+5, "%d", dim1+6, "%d", dim1+7,
                      "%d", dim1+8, "%d", dim1+9, "%d", dim1+10, "%d", dim1+11,
                      "%d", dim1+12, "%d", dim1+13, "%d", dim1+14, "%d", dim1+15,
                      "%d", dim1+16, "%d", dim1+17, "%d", dim1+18, "%d", dim1+19 )) {
  sprintf(message,"Can't read vector length.\n");
  out_message(message);
  Exit_(1);
}

while(read_line(in_file, buf)) {
  if (get_str(buf, 2, "%s", name, "%c", &flag)) {
    sprintf(message,"Can't read function name and test flag from input file.\n");
    out_message(message);
    Exit_(1);
  }

  if      (!strcmp("ZFFT1DC", name)   && (flag == 't' || flag == 'T')) what_test[ZFFT1DC_]   = 1;
  else if (!strcmp("CFFT1DC", name)   && (flag == 't' || flag == 'T')) what_test[CFFT1DC_]   = 1;
  else if (!strcmp("ZDFFT1DC", name)  && (flag == 't' || flag == 'T')) what_test[ZDFFT1DC_]  = 1;
  else if (!strcmp("DZFFT1DC", name)  && (flag == 't' || flag == 'T')) what_test[DZFFT1DC_]  = 1;
  else if (!strcmp("CSFFT1DC", name)  && (flag == 't' || flag == 'T')) what_test[CSFFT1DC_]  = 1;
  else if (!strcmp("SCFFT1DC", name)  && (flag == 't' || flag == 'T')) what_test[SCFFT1DC_]  = 1;
  else {
    if (strcmp("ZFFT1DC",   name) &&
        strcmp("CFFT1DC",   name) &&
        strcmp("DZFFT1DC",  name) &&
        strcmp("ZDFFT1DC",  name) &&
        strcmp("SCFFT1DC",  name) && 
        strcmp("CSFFT1DC",  name) ) { 
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
  fprintf(sum_file, "-- Testing of 1D Fast Fourier Transform C-Interface functions --\n");
  fprintf(sum_file, "--          by result comparision with results from          --\n");
  fprintf(sum_file, "--         1D Discrete Fourier Transform routine (DFT).       --\n");

  fprintf(sum_file, "Double functions epsilon %e\n", deps);
  fprintf(sum_file, "Real functions epsilon %e\n", feps);

  yesno = self_test ? yes : no;
  fprintf(sum_file, "Self test: %s\n", yesno);
  yesno = dft_compare ? yes : no;
  fprintf(sum_file, "DFT Compare: %s\n", yesno);
  yesno = test_error_exit ? yes : no;
  fprintf(sum_file, "Input parameters test: %s\n", yesno);
  yesno = test_cmpt ? yes : no;
  fprintf(sum_file, "Computational test: %s\n", yesno);

  if(((boundary>>3)<<3) != boundary){
  	  fprintf(sum_file, "Align boundary: %d bytes for double precision data.\n", boundary+4);
  	  fprintf(sum_file, "Align boundary: %d bytes for single precision data.\n", boundary);
  } else {
	  fprintf(sum_file, "Align boundary: %d bytes\n", boundary);
  }/* if */
  
  fprintf(sum_file, "\n Lengths of input vectors (Powers of 2):\n");
  for (i = 0; i < num1; i++ )
    fprintf(sum_file, "%d ", dim1[i]);
  fprintf(sum_file, "\n");
  CLOSE_SUM;

  printf("-- Testing of 1D Fast Fourier Transform C-Interface functions --\n");
  printf("--          by result comparision with results from          --\n");
  printf("--         1D Discrete Fourier Transform routine (DFT).       --\n");

  printf("Double functions epsilon %e\n", deps);
  printf("Real functions epsilon %e\n\n", feps);
  
  if(((boundary>>3)<<3) != boundary){
  	  printf("Align boundary: %d bytes for double precision data.\n", boundary+4);
  	  printf("Align boundary: %d bytes for single precision data.\n", boundary);
  } else {
      printf("Align boundary: %d bytes\n\n", boundary);
  }/* if */
  
  printf("\n Lengths of input vectors (Powers of 2):\n");
  for (i = 0; i < num1; i++ )
    printf("%d ", dim1[i]);
  printf("\n\n");
}


/* Function start */
void zfft(int m)
{
    double *na_r = NULL, *na_i = NULL;
    double *na_rs = NULL, *na_is = NULL;
    double *na_tw = NULL;

    double *a_r = NULL, *a_i = NULL;
    double *a_rs = NULL, *a_is = NULL;
    double *tw = NULL;
    double *tw_post = NULL;
    double gauge;

    post_m = (REDUNT8 - d_boundary - (1<<ALIGN_ORDER))/elm_size;

    na_r = (double *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT8);
    na_i = (double *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT8);
    na_rs = (double *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT8);
    na_is = (double *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT8);

    na_tw = (double *)LocalAlloc(LMEM_FIXED, 3*m*elm_size+REDUNT8);
    tw_post = (double *)LocalAlloc(LMEM_FIXED, post_m*elm_size);

    if (na_r != NULL && na_i != NULL && na_rs != NULL && na_is != NULL &&
        na_tw != NULL && tw_post != NULL )  {

        /*
        //  Boundary alignment
        */
        {
		a_r  = (double *)(((((mkl_intp)na_r >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

        a_i  = (double *)(((((mkl_intp)na_i >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

        a_rs = (double *)(((((mkl_intp)na_rs >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

        a_is = (double *)(((((mkl_intp)na_is >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

        tw   = (double *)(((((mkl_intp)na_tw >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

        }/* Boundary alignment */

        /* Compare with DFT routine, isign = -1 */
        d_fill_rand(a_r, m);
        d_fill_rand(a_i, m);

        d_fill_rand(&a_r[m], post_m);
        d_fill_rand(&a_i[m], post_m);
		
        isign = -1;
        gauge = d_gauge(a_r, a_i, m, isign);

        if (dft_compare) {
            zdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);
        } else {
            d_copy(a_r, a_rs, m);
            d_copy(a_i, a_is, m);
            d_copy(&a_r[m], &a_rs[m], post_m);
            d_copy(&a_i[m], &a_is[m], post_m);

            ZFFT1DC_S(a_rs, a_is, m, 0, tw);
            ZFFT1DC_S(a_rs, a_is, m, isign, tw);
        }/* if */

        d_fill_rand(&tw[3*m], post_m);
        d_copy(&tw[3*m], tw_post, post_m);

        ZFFT1DC(a_r, a_i, m, 0, tw);
        ZFFT1DC(a_r, a_i, m, isign, tw);

        zest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

        /* Compare with DFT routine, isign = 1 */
        d_fill_rand(a_r, m);
        d_fill_rand(a_i, m);
        d_fill_rand(&a_r[m], post_m);
        d_fill_rand(&a_i[m], post_m);

        isign = 1;
        gauge = d_gauge(a_r, a_i, m, isign);

        if (dft_compare) {
            zdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);
        } else {
            d_copy(a_r, a_rs, m);
            d_copy(a_i, a_is, m);
            d_copy(&a_r[m], &a_rs[m], post_m);
            d_copy(&a_i[m], &a_is[m], post_m);
            ZFFT1DC_S(a_rs, a_is, m, 0, tw);
            ZFFT1DC_S(a_rs, a_is, m, isign, tw);
        }/* if */

        d_fill_rand(&tw[3*m], post_m);
        d_copy(&tw[3*m], tw_post, post_m);

        ZFFT1DC(a_r, a_i, m, 0, tw);
        ZFFT1DC(a_r, a_i, m, isign, tw);

        zest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

        /* Forward-Inverse transform */
        d_fill_rand(a_r, m);
        d_fill_rand(a_i, m);
        d_fill_rand(&a_r[m], post_m);
        d_fill_rand(&a_i[m], post_m);

        d_copy (a_r, a_rs, m);
        d_copy (a_i, a_is, m);
        d_copy(&a_r[m], &a_rs[m], post_m);
        d_copy(&a_i[m], &a_is[m], post_m);

        d_fill_rand(&tw[3*m], post_m);
        d_copy(&tw[3*m], tw_post, post_m);

        isign = -1;

        gauge = d_gauge(a_r, a_i, m, isign);

        ZFFT1DC(a_r, a_i, m, 0, tw);

        ZFFT1DC(a_r, a_i, m, isign, tw);
  
        isign = 1;

        ZFFT1DC(a_r, a_i, m, isign, tw);
  
        isign = 0;

        zest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

        if (!dft_compare) {
            /* Compare with DFT routine, isign = -2 */
            d_fill_rand(a_r, m);
            d_fill_rand(a_i, m);
            d_fill_rand(&a_r[m], post_m);
            d_fill_rand(&a_i[m], post_m);

            isign = -2;
            gauge = d_gauge(a_r, a_i, m, isign);

            d_copy(a_r, a_rs, m);
            d_copy(a_i, a_is, m);
            d_copy(&a_r[m], &a_rs[m], post_m);
            d_copy(&a_i[m], &a_is[m], post_m);
            d_fill_rand(&tw[3*m], post_m);
            d_copy(&tw[3*m], tw_post, post_m);

		    ZFFT1DC_S(a_rs, a_is, m, 0, tw);
            ZFFT1DC_S(a_rs, a_is, m, isign, tw);

            ZFFT1DC(a_r, a_i, m, 0, tw);
            ZFFT1DC(a_r, a_i, m, isign, tw);

            zest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

            /* Compare with DFT routine, isign = 2 */
            d_fill_rand(a_r, m);
            d_fill_rand(a_i, m);
            d_fill_rand(&a_r[m], post_m);
            d_fill_rand(&a_i[m], post_m);
            d_fill_rand(&tw[3*m], post_m);
            d_copy(&tw[3*m], tw_post, post_m);

            isign = 2;
            gauge = d_gauge(a_r, a_i, m, isign);

            d_copy(a_r, a_rs, m);
            d_copy(a_i, a_is, m);
            d_copy(&a_r[m], &a_rs[m], post_m);
            d_copy(&a_i[m], &a_is[m], post_m);
            ZFFT1DC_S(a_rs, a_is, m, 0, tw);
            ZFFT1DC_S(a_rs, a_is, m, isign, tw);

            ZFFT1DC(a_r, a_i, m, 0, tw);
            ZFFT1DC(a_r, a_i, m, isign, tw);

            zest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

            /* Forward-Inverse transform +-2 */
            d_fill_rand(a_r, m);
            d_fill_rand(a_i, m);
            d_fill_rand(&a_r[m], post_m);
            d_fill_rand(&a_i[m], post_m);

            d_copy (a_r, a_rs, m);
            d_copy (a_i, a_is, m);
            d_copy(&a_r[m], &a_rs[m], post_m);
            d_copy(&a_i[m], &a_is[m], post_m);
            d_fill_rand(&tw[3*m], post_m);
            d_copy(&tw[3*m], tw_post, post_m);

            isign = -2;

            gauge = d_gauge(a_r, a_i, m, isign);

            ZFFT1DC(a_r, a_i, m, 0, tw);
            ZFFT1DC(a_r, a_i, m, isign, tw);
  
            isign = 2;

            ZFFT1DC(a_r, a_i, m, isign, tw);
  
            isign = 22;

            zest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

        }/* if +-2*/
    }/* if allocate */
    
    LocalFree(na_tw);
    LocalFree(na_is);
    LocalFree(na_rs);
    LocalFree(na_i);
    LocalFree(na_r);
    LocalFree(tw_post);

}/* zfft */

/* Function start */
void cfft(int m)
{
    float *na_r = NULL, *na_i = NULL;
    float *na_rs = NULL, *na_is = NULL;
    float *na_tw = NULL;
    float *tw_post = NULL;

    float *a_r = NULL, *a_i = NULL;
    float *a_rs = NULL, *a_is = NULL;
    float *tw = NULL;
    float gauge;
  
    post_m = (REDUNT4 - d_boundary - (1<<ALIGN_ORDER))/elm_size;

    na_r = (float *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT4);
    na_i = (float *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT4);
    na_rs = (float *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT4);
    na_is = (float *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT4);

    na_tw = (float *)LocalAlloc(LMEM_FIXED, 3*m*elm_size+REDUNT4);
    tw_post = (float *)LocalAlloc(LMEM_FIXED, post_m*elm_size);


    if(na_r != NULL && na_i != NULL && na_rs != NULL && na_is != NULL &&
       na_tw != NULL && tw_post != NULL ) {

        /*
        //  Boundary alignment
        */
        {
		a_r  = (float *)(((((mkl_intp)na_r >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

        a_i  = (float *)(((((mkl_intp)na_i >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

        a_rs = (float *)(((((mkl_intp)na_rs >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

        a_is = (float *)(((((mkl_intp)na_is >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

        tw   = (float *)(((((mkl_intp)na_tw >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

        }/* Boundary alignment */

        /* Compare with DFT routine, isign = -1 */
        s_fill_rand(a_r, m);
        s_fill_rand(a_i, m);

        s_fill_rand(&a_r[m], post_m);
        s_fill_rand(&a_i[m], post_m);

        isign = -1;
        gauge = s_gauge(a_r, a_i, m, isign);

        if(dft_compare) {
            cdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);
        } else {

            s_copy(a_r, a_rs, m);
            s_copy(a_i, a_is, m);
            s_copy(&a_r[m], &a_rs[m], post_m);
            s_copy(&a_i[m], &a_is[m], post_m);
  
            CFFT1DC_S(a_rs, a_is, m, 0, tw);
            CFFT1DC_S(a_rs, a_is, m, isign, tw);
        }/* if */

        s_fill_rand(&tw[3*m], post_m);
        s_copy(&tw[3*m], tw_post, post_m);

        CFFT1DC(a_r, a_i, m, 0, tw);
        CFFT1DC(a_r, a_i, m, isign, tw);

        cest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

        /* Compare with DFT routine, isign = 1 */
        s_fill_rand(a_r, m);
        s_fill_rand(a_i, m);
        s_fill_rand(&a_r[m], post_m);
        s_fill_rand(&a_i[m], post_m);


        isign = 1;
        gauge = s_gauge(a_r, a_i, m, isign);

        if (dft_compare) {
            cdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);
        } else {
            s_copy(a_r, a_rs, m);
            s_copy(a_i, a_is, m);
            s_copy(&a_r[m], &a_rs[m], post_m);
            s_copy(&a_i[m], &a_is[m], post_m);
            CFFT1DC_S(a_rs, a_is, m, 0, tw);
            CFFT1DC_S(a_rs, a_is, m, isign, tw);
        }/* if */

        s_fill_rand(&tw[3*m], post_m);
        s_copy(&tw[3*m], tw_post, post_m);

        CFFT1DC(a_r, a_i, m, 0, tw);
        CFFT1DC(a_r, a_i, m, isign, tw);
        
        cest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

        /* Forward-Inverse transform */
        s_fill_rand(a_r, m);
        s_fill_rand(a_i, m);
        s_fill_rand(&a_r[m], post_m);
        s_fill_rand(&a_i[m], post_m);


        s_copy (a_r, a_rs, m);
        s_copy (a_i, a_is, m);
        s_copy(&a_r[m], &a_rs[m], post_m);
        s_copy(&a_i[m], &a_is[m], post_m);

        s_fill_rand(&tw[3*m], post_m);
        s_copy(&tw[3*m], tw_post, post_m);

        isign = -1;

        gauge = s_gauge(a_r, a_i, m, isign);

        CFFT1DC(a_r, a_i, m, 0, tw);

        CFFT1DC(a_r, a_i, m, isign, tw);

        isign = 1;
        CFFT1DC(a_r, a_i, m, isign, tw);

        isign = 0;
        cest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

        if (!dft_compare) {
            /* Compare with DFT routine, isign = -2 */
            s_fill_rand(a_r, m);
            s_fill_rand(a_i, m);
            s_fill_rand(&a_r[m], post_m);
            s_fill_rand(&a_i[m], post_m);


            isign = -2;
            gauge = s_gauge(a_r, a_i, m, isign);

            s_copy(a_r, a_rs, m);
            s_copy(a_i, a_is, m);
            s_copy(&a_r[m], &a_rs[m], post_m);
            s_copy(&a_i[m], &a_is[m], post_m);
  
            s_fill_rand(&tw[3*m], post_m);
            s_copy(&tw[3*m], tw_post, post_m);

		    CFFT1DC_S(a_rs, a_is, m, 0, tw);
            CFFT1DC_S(a_rs, a_is, m, isign, tw);

            CFFT1DC(a_r, a_i, m, 0, tw);

            CFFT1DC(a_r, a_i, m, isign, tw);

            cest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

            /* Compare with DFT routine, isign = 2 */
            s_fill_rand(a_r, m);
            s_fill_rand(a_i, m);
            s_fill_rand(&a_r[m], post_m);
            s_fill_rand(&a_i[m], post_m);
            s_fill_rand(&tw[3*m], post_m);
            s_copy(&tw[3*m], tw_post, post_m);

            isign = 2;
            gauge = s_gauge(a_r, a_i, m, isign);

            s_copy(a_r, a_rs, m);
            s_copy(a_i, a_is, m);
            s_copy(&a_r[m], &a_rs[m], post_m);
            s_copy(&a_i[m], &a_is[m], post_m);

            CFFT1DC_S(a_rs, a_is, m, 0, tw);
            CFFT1DC_S(a_rs, a_is, m, isign, tw);

            CFFT1DC(a_r, a_i, m, 0, tw);
            CFFT1DC(a_r, a_i, m, isign, tw);
        
            cest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

            /* Forward-Inverse transform +-2 */
            s_fill_rand(a_r, m);
            s_fill_rand(a_i, m);
            s_fill_rand(&a_r[m], post_m);
            s_fill_rand(&a_i[m], post_m);


            s_copy (a_r, a_rs, m);
            s_copy (a_i, a_is, m);
            s_copy(&a_r[m], &a_rs[m], post_m);
            s_copy(&a_i[m], &a_is[m], post_m);

            s_fill_rand(&tw[3*m], post_m);
            s_copy(&tw[3*m], tw_post, post_m);
        
			isign = -2;

            gauge = s_gauge(a_r, a_i, m, isign);

            CFFT1DC(a_r, a_i, m, 0, tw);

            CFFT1DC(a_r, a_i, m, isign, tw);

            isign = 2;
            CFFT1DC(a_r, a_i, m, isign, tw);

            isign = 22;

            cest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

        }/* if */
    }/* if */
    
    LocalFree(na_tw);
    LocalFree(na_is);
    LocalFree(na_rs);
    LocalFree(na_i);
    LocalFree(na_r);
    LocalFree(tw_post);

}/* cfft */

/* Function start */
void dzfft(int m, int fi)
{
    double *na = NULL;
    double *na_r = NULL, *na_i = NULL;
    double *na_rs = NULL, *na_is = NULL;
    double *na_tw = NULL;
    double *tw_post = NULL;

    double *a = NULL;
    double *a_r = NULL, *a_i = NULL;
    double *a_rs = NULL, *a_is = NULL;
    double *tw = NULL;
    double gauge;

    post_m = (REDUNT8 - d_boundary - (1<<ALIGN_ORDER))/elm_size - 2;

    na = (double *)LocalAlloc(LMEM_FIXED, (m+2)*elm_size+REDUNT8);
    na_r = (double *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT8);
    na_i = (double *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT8);
    na_rs = (double *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT8);
    na_is = (double *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT8);

    na_tw = (double *)LocalAlloc(LMEM_FIXED, 3*m*elm_size+REDUNT8);
    tw_post = (double *)LocalAlloc(LMEM_FIXED, post_m*elm_size);

    if (na != NULL && na_r != NULL && na_i != NULL && na_rs != NULL && na_is != NULL &&
        na_tw != NULL )  {

        /*
        //  Boundary alignment
        */
        {
		a    = (double *)(((((mkl_intp)na   >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

		a_r  = (double *)(((((mkl_intp)na_r >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

        a_i  = (double *)(((((mkl_intp)na_i >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

        a_rs = (double *)(((((mkl_intp)na_rs >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

        a_is = (double *)(((((mkl_intp)na_is >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

        tw   = (double *)(((((mkl_intp)na_tw >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + d_boundary);

        }/* Boundary alignment */

        /* Forward routine DZFFT1D compare with DFT routine */
        if (fi == -1 || fi == 0) {
            isign = -1;
  
            d_fill_rand(a, m);
            d_fill_rand(&a[m+2], post_m);

            dz_copy_s (a, a_r, a_i, m);
            d_copy(&a[m+2], &a_rs[m], post_m);

            gauge = d_gauge(a_r, a_i, m, isign);

            if (dft_compare) {
                zdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);
            } else {
                d_copy(a_r, a_rs, m);
                d_copy(a_i, a_is, m);
                ZFFT1DC_S(a_rs, a_is, m, 0, tw);
                ZFFT1DC_S(a_rs, a_is, m, isign, tw);
            }/* if */

            d_fill_rand(&tw[2*m], post_m);
            d_copy(&tw[2*m], tw_post, post_m);

            DZFFT1DC(a, m, 0, tw);

            DZFFT1DC(a, m, isign, tw);

            dz_copy (a, a_r, a_i, m);

//            zest (a_r, a_i, a_rs, a_is, m, gauge);
        zest (a, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);
        }/* if */

        /* Inverse routine ZDFFT1D compare with DFT routine */
        if (fi == 1) {
            isign = 1;
  
            d_fill_rand(a, m+2);
            d_fill_rand(&a[m+2], post_m);
    
            zd_copy (a, a_r, a_i, m);
            d_copy(&a[m+2], &a_rs[m], post_m);

            gauge = d_gauge(a_r, a_i, m, isign);

            if (dft_compare) {
                zdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);
            } else {
                d_copy(a_r, a_rs, m);
                d_copy(a_i, a_is, m);
                ZFFT1DC_S(a_rs, a_is, m, 0, tw);
                ZFFT1DC_S(a_rs, a_is, m, isign, tw);
            }/* if */

            d_fill_rand(&tw[2*m], post_m);
            d_copy(&tw[2*m], tw_post, post_m);

            ZDFFT1DC(a, m, 0, tw);

            ZDFFT1DC(a, m, isign, tw);

            dz_copy_s (a, a_r, a_i, m);

//            zest (a_r, a_i, a_rs, a_is, m, gauge);
        zest (a, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);
        }/* if */

        /* Forward-Inverse transform */
        if (fi == 0) {
            d_fill_rand(a, m+2);
            d_fill_rand(&a[m+2], post_m);

            isign = -1;

            dz_copy_s (a, a_rs, a_is, m);
            d_copy(&a[m+2], &a_rs[m], post_m);

            gauge = d_gauge(a_rs, a_is, m, isign);

            d_fill_rand(&tw[2*m], post_m);
            d_copy(&tw[2*m], tw_post, post_m);

            DZFFT1DC(a, m, 0, tw);
            DZFFT1DC(a, m, isign, tw);
 
            ZDFFT1DC(a, m, 0, tw);
            ZDFFT1DC(a, m, isign, tw);

            dz_copy_s (a, a_r, a_i, m);

            isign = 0;

//            zest (a_r, a_i, a_rs, a_is, m, gauge);
        zest (a, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);
        }/* if */

    }/* if allocate */

    LocalFree(na_tw);
    LocalFree(na_is);
    LocalFree(na_rs);
    LocalFree(na_i);
    LocalFree(na_r);
    LocalFree(na);
    LocalFree(tw_post);

}/* dzfft */

/* Function start */
void SC_RUN(float* a, int m, int isign, float* tw)
{
    
    SCFFT1DC(a, m, isign, tw);
    CSFFT1DC(a, m, isign, tw);
    return;
}


/* Function start */
void scfft(int m, int fi)
{
    float *na = NULL;
    float *na_r = NULL, *na_i = NULL;
    float *na_rs = NULL, *na_is = NULL;
    float *na_tw = NULL;
    float *tw_post = NULL;

    float *a = NULL;
    float *a_r = NULL, *a_i = NULL;
    float *a_rs = NULL, *a_is = NULL;
    float *tw = NULL;
    float gauge;

    post_m = (REDUNT4 - d_boundary - (1<<ALIGN_ORDER))/elm_size - 2;

    na = (float *)LocalAlloc(LMEM_FIXED, (m+2)*elm_size+REDUNT4);
    na_r = (float *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT4);
    na_i = (float *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT4);
    na_rs = (float *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT4);
    na_is = (float *)LocalAlloc(LMEM_FIXED, m*elm_size+REDUNT4);

    na_tw = (float *)LocalAlloc(LMEM_FIXED, 3*m*elm_size+REDUNT4);
    tw_post = (float *)LocalAlloc(LMEM_FIXED, post_m*elm_size);

    if (na != NULL && na_r != NULL && na_i != NULL && na_rs != NULL && na_is != NULL &&
        na_tw != NULL )  {

        /*
        //  Boundary alignment
        */
        {
		a    = (float *)(((((mkl_intp)na   >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

		a_r  = (float *)(((((mkl_intp)na_r >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

        a_i  = (float *)(((((mkl_intp)na_i >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

        a_rs = (float *)(((((mkl_intp)na_rs >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

        a_is = (float *)(((((mkl_intp)na_is >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

        tw   = (float *)(((((mkl_intp)na_tw >> ALIGN_ORDER) + 1) << ALIGN_ORDER) + s_boundary);

        }/* Boundary alignment */

        /* Forward routine DZFFT1D compare with DFT routine */
        if (fi == -1 || fi == 0) {
            isign = -1;
  
            s_fill_rand(a, m);
            s_fill_rand(&a[m+2], post_m);

            sc_copy_s (a, a_r, a_i, m);
            s_copy(&a[m+2], &a_rs[m], post_m);

            gauge = s_gauge(a_r, a_i, m, isign);

            if (dft_compare) {
                cdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);
            } else {
                s_copy(a_r, a_rs, m);
                s_copy(a_i, a_is, m);
                CFFT1DC_S(a_rs, a_is, m, 0, tw);
                CFFT1DC_S(a_rs, a_is, m, isign, tw);
            }/* if */

            s_fill_rand(&tw[2*m], post_m);
            s_copy(&tw[2*m], tw_post, post_m);

            SCFFT1DC(a, m, 0, tw);

            SCFFT1DC(a, m, isign, tw);

            sc_copy (a, a_r, a_i, m);

//            cest (a_r, a_i, a_rs, a_is, m, gauge);
        cest (a, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);
        }/* if */

        /* Inverse routine ZDFFT1D compare with DFT routine */
        if (fi == 1) {
            isign = 1;
  
            s_fill_rand(a, m+2);
            s_fill_rand(&a[m+2], post_m);
    
            cs_copy (a, a_r, a_i, m);
            s_copy(&a[m+2], &a_rs[m], post_m);

            gauge = s_gauge(a_r, a_i, m, isign);

            if (dft_compare) {
                cdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);
            } else {
                s_copy(a_r, a_rs, m);
                s_copy(a_i, a_is, m);
                CFFT1DC_S(a_rs, a_is, m, 0, tw);
                CFFT1DC_S(a_rs, a_is, m, isign, tw);
            }/* if */

            s_fill_rand(&tw[2*m], post_m);
            s_copy(&tw[2*m], tw_post, post_m);

            CSFFT1DC(a, m, 0, tw);

            CSFFT1DC(a, m, isign, tw);

            sc_copy_s (a, a_r, a_i, m);

//            cest (a_r, a_i, a_rs, a_is, m, gauge);
        cest (a, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);
        }/* if */

        /* Forward-Inverse transform */
        if (fi == 0) {
            s_fill_rand(a, m+2);
            s_fill_rand(&a[m+2], post_m);

            isign = -1;

            sc_copy_s (a, a_rs, a_is, m);
            s_copy(&a[m+2], &a_rs[m], post_m);

            gauge = s_gauge(a_rs, a_is, m, isign);

            s_fill_rand(&tw[2*m], post_m);
            s_copy(&tw[2*m], tw_post, post_m);

            SCFFT1DC(a, m, 0, tw);
            SCFFT1DC(a, m, isign, tw);
 
            CSFFT1DC(a, m, 0, tw);
            CSFFT1DC(a, m, isign, tw);

            sc_copy_s (a, a_r, a_i, m);

            isign = 0;

//            cest (a_r, a_i, a_rs, a_is, m, gauge);
        cest (a, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);
        }/* if */

    }/* if allocate */

    LocalFree(na_tw);
    LocalFree(na_is);
    LocalFree(na_rs);
    LocalFree(na_i);
    LocalFree(na_r);
    LocalFree(na);
    LocalFree(tw_post);

}/* scfft */


/* Function start */
void  zdft1d (double *a_ri, double *a_ii, int m, int isign, 
              double *a_ro, double *a_io, double *tw )

{
int    i, k, ia;
double argm;

argm = 8.0*atan(1.0)/ (double)m;

if (isign <= 0) {
  for (i = 0; i < m; i++) {
    tw[2*i]   = cos(argm*(double)(i));
    tw[2*i+1] = -sin(argm*(double)(i));
  }
}
else {
  for (i = 0; i < m; i++) {
    tw[2*i]   = cos(argm*(double)(i));
    tw[2*i+1] = sin(argm*(double)(i));
  }

}


  for (k = 0; k < m; k++) {
    a_ro[ k ] = 0.0;
    a_io[ k ] = 0.0;

    for (i = 0; i < m; i++) {
      ia = (int)fmod ( (double)(i*k) , (double)m);
      a_ro[k] += a_ri[i] * tw[2*ia] - 
                 a_ii[i] * tw[2*ia+1]; 

      a_io[k] += a_ri[i] * tw[2*ia+1] + 
                 a_ii[i] * tw[2*ia]; 
    }
  }

if (isign > 0) {
  ia = m;
  argm = (double)ia;
  for (i = 0; i < ia; i++) {
      a_ro[i] /= argm;
      a_io[i] /= argm;
  }
}

}

/* Function start */
void  cdft1d (float *a_ri, float *a_ii, int m, int isign, 
              float *a_ro, float *a_io, float *tw )

{
int    i, k, ia;
float argm;

argm = (float)(8.0*atan(1.0)/ (float)m);
/*
double x;
x= (double)1.0;
printf("x = %f \n", x);
argm = (float)atan(x);
printf("argm = %f \n", argm);

argm = argm*(float)8.0;
printf("argm = %f \n", argm);
argm = argm/ (float)m;
printf("argm = %f \n", argm);
*/
if (isign <= 0) {
  for (i = 0; i < m; i++) {
    tw[2*i]   = (float)cos(argm*(float)(i));
    tw[2*i+1] = -(float)sin(argm*(float)(i));
  }
}
else {
  for (i = 0; i < m; i++) {
    tw[2*i]   = (float)cos(argm*(float)(i));
    tw[2*i+1] = (float)sin(argm*(float)(i));
  }
}

/*   for (i=0; i< m; i++)
      printf("tw[%d]=( %f, %f) \n", i, tw[2*i], tw[2*i+1]);
*/
  for (k = 0; k < m; k++) {
    a_ro[ k ] = (float)0.0;
    a_io[ k ] = (float)0.0;

    for (i = 0; i < m; i++) {
      ia = (int)fmod ( (float)(i*k) , (float)m);
      a_ro[k] += a_ri[i] * tw[2*ia] - 
                 a_ii[i] * tw[2*ia+1]; 

      a_io[k] += a_ri[i] * tw[2*ia+1] + 
                 a_ii[i] * tw[2*ia]; 
    }
  }

if (isign > 0) {
  ia = m;
  argm = (float)ia;
  for (i = 0; i < ia; i++) {
      a_ro[i] /= argm;
      a_io[i] /= argm;
  }
}

/*   for (i=0; i< m; i++)
      printf("a_ro[%d]= %f, a_io[%d]=%f \n", i, a_ro[i], i, a_io[i]);
*/
}


/* Function start */
int zest(double *tst, double *tst_r, double *tst_i, double *exp_r, double *exp_i,
		 double *tw, double *tw_post, int m, int post_m, double gauge)
{
    int ierr, ierrfirst;
    double err = 0.0;
    double errij;
    double diff_r, diff_i;
    int error = 0;
    int i;
    int  nan_flag, nan_res=0, nan_stop=0;

    OPEN_SNAP;
    ierrfirst = -1;
    if(m > 1) {
    for (i = 0; i < m; i++ ){
        
        nan_flag=0;
        nan_flag = _isnan(tst_r[i]);
        
        if(nan_flag){
            //  printf(" tst_r[%d] is NAN\n", i);
            nan_res=1;
        }/* if */
    
        nan_flag=0;
        nan_flag = _isnan(tst_i[i]);
        
        if(nan_flag){
            //printf(" tst_i[%d] is NAN\n", i);
            nan_res=1;
        }/* if */
 
        if(nan_res){
            fprintf(snp_file, " Computed result [%d] :NAN ERROR\n", i);
            nan_stop=1;
        }/* if */
 
        nan_res =0;
    
        nan_flag=0;
        nan_flag = _isnan(exp_r[i]);
        
        if(nan_flag){
            //printf(" exp_r[%d] is NAN\n", i);
            nan_res=1;
        }/* if */
    
        nan_flag=0;
        nan_flag = _isnan(exp_i[i]);
        if(nan_flag){
            //printf(" exp_i[%d] is NAN\n", i);
            nan_res=1;
        }/* if */
    
    
        if(nan_res){
            fprintf(snp_file, " Expected result [%d] :NAN ERROR\n", i);
            nan_stop=1;
        }/* if */

        if(nan_stop){
            fprintf(snp_file, "**  Fatal Error - NAN result **\n");
        
            if(isign == 0) {
                fprintf(snp_file, "%s  ISIGN = -1:+1 \tM = %d :ERROR\n", 
                        fname, m);
            } else if(isign == 22) {
                fprintf(snp_file, "%s  ISIGN = -2:+2 \tM = %d :ERROR\n", 
                        fname, m);
            } else {
                fprintf(snp_file, "%s  ISIGN = %d    \tM = %d :ERROR\n", 
                        fname, isign, m);
            }/* if */
            
            fatal[ifunc] = 1;
            error = 1;
            return 0;
        }/* if nan_stop*/

        diff_r = tst_r[i] - exp_r[i];
        diff_i = tst_i[i] - exp_i[i];
        errij = sqrt( diff_r*diff_r + diff_i*diff_i ) / deps;
/*      if ( gauge != zero ) errij = errij / (gauge*10.0);  */
        if ( gauge != zero ) errij = errij / (gauge); 
        
        if (errij > err ){
            err =  errij;
            ierr = i;
        }/* if */

        if (errij >= one){
            error = 1;
           if (ierrfirst == -1) {
              ierrfirst = ierr;
           }/* if */
        }/* if */
    }/* for */
    }/* if m>1) */
    
    if (!error && !dft_compare) error = zpostm (tst, tst_r, tst_i, exp_r, exp_i,
		                                        tw, tw_post, m, post_m);

    if ( error ){
        fatal[ifunc] = 1;
        if (isign != 0){
            fprintf(snp_file, "%s  ISIGN = %d    \tM = %d :ERROR\n", 
                    fname, isign, m);
        } else {
            fprintf(snp_file, "%s  ISIGN = -1:+1 \tM = %d :ERROR\n", 
                    fname, m);
        }/* if */

        fprintf(snp_file, "**** Fatal Error - computed result is less than half accurate ***\n");
        fprintf(snp_file, "     Computed result                      Expected result\n");

        fprintf(snp_file, "\n                             Error first\n");
        fprintf(snp_file, "           tst[%d]                                     exp[%d] \n",
                           ierrfirst, ierrfirst);
        fprintf(snp_file, "(%.10f, %.10f)               (%.10f, %.10f)\n",
                           tst_r[ierrfirst], tst_i[ierrfirst],
                           exp_r[ierrfirst], exp_i[ierrfirst]);

        fprintf(snp_file, "\n                             Error MAX\n");
        fprintf(snp_file, "           tst[%d]                                     exp[%d] \n",
                           ierr, ierr);
        fprintf(snp_file, "(%.10f, %.10f)               (%.10f, %.10f)\n",
                           tst_r[ierr], tst_i[ierr],
                           exp_r[ierr], exp_i[ierr]);



        fprintf(snp_file, "\nMatrix gauge %e\n", gauge);
        fprintf(snp_file, "\nFirst error  (%e, %e)\n", fabs(tst_r[ierrfirst]-exp_r[ierrfirst]),
                           fabs(tst_i[ierrfirst]-exp_i[ierrfirst]));
        fprintf(snp_file, "MAX error    (%e, %e)\n\n", fabs(tst_r[ierr]-exp_r[ierr]),
                           fabs(tst_i[ierr]-exp_i[ierr]));
    } else {
        if (isign == 0){
            fprintf(snp_file, "%s  ISIGN = -1:+1 \tM = %d \n", 
                    fname, m);
        } else if (isign == 22){
            fprintf(snp_file, "%s  ISIGN = -2:+2 \tM = %d \n", 
                    fname, m);
        } else {
            fprintf(snp_file, "%s  ISIGN = %d    \tM = %d \n", 
                    fname, isign, m);
        }/* if */ 
    }/* if error */

    CLOSE_SNAP;
    return 0;
}/* zest */


/* Function start */
int cest(float *tst, float *tst_r, float *tst_i, float *exp_r, float *exp_i, float *tw, float *tw_post,
         int m, int post_m, float gauge)
{
    int ierr, ierrfirst;
    float err = (float)0.0;
    float errij;
    float diff_r, diff_i;
    int error = 0;
    int i;
    int  nan_flag, nan_res=0, nan_stop=0;

    OPEN_SNAP;

    ierrfirst = -1;
    
    if (m>1) {
        for(i = 0; i < m; i++ ) {
    
            nan_flag=0;
            nan_flag = _isnan(tst_r[i]);
            
            if(nan_flag) {
                 nan_res=1;
            }

            nan_flag=0;
            nan_flag = _isnan(tst_i[i]);
            
            if(nan_flag) {
                nan_res=1;
            }
 
            if(nan_res) {
                fprintf(snp_file, " Computed result [%d] :NAN ERROR\n", i);
                nan_stop=1;
            }/* if */
 
            nan_res =0;
    
            nan_flag=0;
            nan_flag = _isnan(exp_r[i]);
    
            if(nan_flag) {
                nan_res=1;
            }
    
            nan_flag=0;
            nan_flag = _isnan(exp_i[i]);
            if(nan_flag) {
                nan_res=1;
            }
    
    
            if(nan_res) {
                fprintf(snp_file, " Expected result [%d] :NAN ERROR\n", i);
                nan_stop=1;
            }

            if(nan_stop) {
                fprintf(snp_file, "**  Fatal Error - NAN result **\n");
        
                if(isign == 0) {
                     fprintf(snp_file, "%s  ISIGN = -1:+1 \tM = %d :ERROR\n", 
                             fname, m);
                } else if(isign == 22){
                     fprintf(snp_file, "%s  ISIGN = -2:+2 \tM = %d :ERROR\n", 
                             fname, m);
                } else {
                    fprintf(snp_file, "%s  ISIGN = %d    \tM = %d :ERROR\n", 
                           fname, isign, m);
                }/* if */
        
                fatal[ifunc] = 1;
                error = 1;
                return 0;
           }/* if nan_stop */

           diff_r = tst_r[i] - exp_r[i];
           diff_i = tst_i[i] - exp_i[i];

           errij = (float) (sqrt( diff_r*diff_r + diff_i*diff_i ) / feps );

           if( gauge != (float)zero ) errij = errij / (gauge); 
 
           if(errij > err ) {
               err =  errij;
               ierr = i;
           }

           if(errij >= (float)one) {
                error = 1;
                if (ierrfirst == -1) {
                    ierrfirst = ierr;
                }
           }/* if */

        }/* for */
    }/* if m>1 */

    if (!error && !dft_compare) error = cpostm (tst, tst_r, tst_i, exp_r, exp_i,
		                                        tw, tw_post, m, post_m);

    if( error ) {
        fatal[ifunc] = 1;
        if(isign == 0) {
            fprintf(snp_file, "%s  ISIGN = -1:+1 \tM = %d :ERROR\n", 
                    fname, m);
        } else if(isign == 22){
            fprintf(snp_file, "%s  ISIGN = -2:+2 \tM = %d :ERROR\n", 
                    fname, m);
        } else {
            fprintf(snp_file, "%s  ISIGN = %d    \tM = %d :ERROR\n", 
                    fname, isign, m);
        }/* if */

        fprintf(snp_file, "**** Fatal Error - computed result is less than half accurate ***\n");
        fprintf(snp_file, "     Computed result                      Expected result\n");

        fprintf(snp_file, "\n                             Error first\n");
        fprintf(snp_file, "           tst[%d]                                     exp[%d] \n",
                           ierrfirst, ierrfirst);
        fprintf(snp_file, "(%.10f, %.10f)               (%.10f, %.10f)\n",
                           tst_r[ierrfirst], tst_i[ierrfirst],
                           exp_r[ierrfirst], exp_i[ierrfirst]);
        fprintf(snp_file, "\n                             Error MAX  \n");
        fprintf(snp_file, "           tst[%d]                                     exp[%d] \n",
                           ierr, ierr);
        fprintf(snp_file, "(%.10f, %.10f)               (%.10f, %.10f)\n",
                           tst_r[ierr], tst_i[ierr],
                           exp_r[ierr], exp_i[ierr]);



        fprintf(snp_file, "\nMatrix gauge %e\n", gauge);
        fprintf(snp_file, "\nFirst error  (%e, %e)\n", fabs(tst_r[ierrfirst]-exp_r[ierrfirst]),
                           fabs(tst_i[ierrfirst]-exp_i[ierrfirst]));
        fprintf(snp_file, "MAX error    (%e, %e)\n\n", fabs(tst_r[ierr]-exp_r[ierr]),
                           fabs(tst_i[ierr]-exp_i[ierr]));
    } else {
        if(isign == 0) {
            fprintf(snp_file, "%s  ISIGN = -1:+1 \tM = %d \n", 
                    fname, m);
        } else if(isign == 22){
            fprintf(snp_file, "%s  ISIGN = -2:+2 \tM = %d \n", 
                    fname, m);
        } else {
            fprintf(snp_file, "%s  ISIGN = %d    \tM = %d \n", 
                    fname, isign, m);
        }/* if */
      
    }/* if error */

    CLOSE_SNAP;
    return 0;
}/* cest */


/* Function start */
void d_fill_rand(double *a, int m)
{
int i;
for (i = 0; i < m; i++) {
  a[i] = ((double)rand())/((double)RAND_MAX) - 0.5;
}

}

/* Function start */
void s_fill_rand(float *a, int m)
{
int i;
for (i = 0; i < m; i++) {
  a[i] = (float)((float)rand())/((float)RAND_MAX) - (float)0.5;
}

}

/* Function start */
void d_copy(double *a, double *b, int m)
{
int i;
for (i = 0; i < m; i++) {
  b[i] = a[i] ;
}

}

/* Function start */
void s_copy(float *a, float *b, int m)
{
int i;
for (i = 0; i < m; i++) {
  b[i] = a[i] ;
}

}

/* Function start */
void dz_copy_s(double *a, double *a_ro, double *a_io, int m)
{
int i;
for (i = 0; i < m; i++) {
  a_ro[i] = a[i] ;
  a_io[i] = 0.0;
}

}

/* Function start */
void sc_copy_s(float *a, float *a_ro, float *a_io, int m)
{
int i;
for (i = 0; i < m; i++) {
  a_ro[i] = a[i] ;
  a_io[i] = (float)0.0;
}

}


/* Function start */
void dz_copy(double *a, double *a_ro, double *a_io, int m)
{
    int i;

    a_ro[0] = a[0];
    a_io[0] = a[m/2+1];
    
    if (m > 1) {
        a_ro[m/2] = a[m/2];
        a_io[m/2] = a[m+1];
    }/* if */

    for ( i = 1; i < m/2; i++) {
        a_ro[i] = a[i];
        a_io[i] = a[m/2+i+1];
        a_ro[m-i] = a[i];
        a_io[m-i] = -a[m/2+i+1];
    }/* for */
}/* dz_copy */

/* Function start */
void zd_copy(double *a, double *a_ro, double *a_io, int m)
{
    int i;

    a_ro[0] = a[0];
    a_io[0] = 0.0;

    if (m > 1) {
        a_ro[m/2] = a[m/2];
        a_io[m/2] = 0.0;
    }/* if */

    for ( i = 1; i < m/2; i++) {
        a_ro[i] = a[i];
        a_io[i] = a[m/2+i+1];
        a_ro[m-i] = a[i];
        a_io[m-i] = -a[m/2+i+1];
    }/* for */
}/* zd_copy */


/* Function start */
void sc_copy(float *a, float *a_ro, float *a_io, int m)
{
    int i;

    a_ro[0] = a[0];
    a_io[0] = a[m/2+1];

    if (m > 1) {
        a_ro[m/2] = a[m/2];
        a_io[m/2] = a[m+1];
    }/* if */

    for ( i = 1; i < m/2; i++) {
        a_ro[i] = a[i];
        a_io[i] = a[m/2+i+1];
        a_ro[m-i] = a[i];
        a_io[m-i] = -a[m/2+i+1];
    }/* for */
}/* sc_copy */

/* Function start */
void cs_copy(float *a, float *a_ro, float *a_io, int m)
{
    int i;

    a_ro[0] = a[0];
    a_io[0] = (float)0.0;

    if (m > 1) {
        a_ro[m/2] = a[m/2];
        a_io[m/2] = (float)0.0;
    }/* if */

    for ( i = 1; i < m/2; i++) {
        a_ro[i] = a[i];
        a_io[i] = a[m/2+i+1];
        a_ro[m-i] = a[i];
        a_io[m-i] = -a[m/2+i+1];
    }/* for */
}/* cs_copy */


/* Function start */
double d_gauge(double *a_r, double *a_i, int m, int isign)
{
double accm;
int i;
  accm = 0.0;
  for (i = 0; i < m; i++) {
    accm += a_r[i]*a_r[i] + a_i[i]*a_i[i];
  }
  if (isign >= 0) accm /= (double)m;
  return accm;
}

/* Function start */
float s_gauge(float *a_r, float *a_i, int m, int isign)
{
float accm;
int i;
  accm = (float)0.0;
  for (i = 0; i < m; i++) {
    accm += a_r[i]*a_r[i] + a_i[i]*a_i[i];
  }
  if (isign >= 0) accm /= (float)m;
  return accm;
}

/* Function start */
void call_func(int num, int m, int isign, void* ar, void* ai, void* w) {

switch (num) {
  case ZFFT1DC_:    
    zfft1dc((double*)ar, (double*)ai, m, isign, (double*)w);
    break;

  case CFFT1DC_:    
    cfft1dc((float*)ar, (float*)ai, m, isign, (float*)w);
    break;

  case DZFFT1DC_:    
    dzfft1dc((double*)ar, m, isign, (double*)w);
    break;

  case ZDFFT1DC_:    
    zdfft1dc((double*)ar, m, isign, (double*)w);
    break;

  case SCFFT1DC_:    
    scfft1dc((float*)ar, m, isign, (float*)w);
    break;

  case CSFFT1DC_:    
    csfft1dc((float*)ar, m, isign, (float*)w);
    break;

}
}

/* ---------------------------------------------------------
*  --                                                     --
*  --       Input parameters check                        --
*  --                                                     --
*  ---------------------------------------------------------
*/


void cherr (int num) {

double a_r[512], a_i[512], w[512];
void   *ar, *ai, *ww;
int m, isign;

  ar = (void*)a_r;
  ai = (void*)a_i;
  ww = (void*)w;

  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT1DC_ || ifunc == CFFT1DC_ ) 
    code_err_t = 3;
  else 
    code_err_t = 2;
  m = -20;
  isign = 0;
  call_func(num, m, isign, ar, ai, ww);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! m = %d, isign = %d\n", fname, code_err_t, m, isign);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! m = %d, isign = %d\n", fname, code_err_t, m, isign);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;
  
  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT1DC_ || ifunc == CFFT1DC_ ) 
    code_err_t = 4;
  else 
    code_err_t = 3;
  m = 64;
  isign = -5;
  call_func(num, m, isign, ar, ai, ww);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! m = %d, isign = %d\n", fname, code_err_t, m, isign);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! m = %d, isign = %d\n", fname, code_err_t, m, isign);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT1DC_ || ifunc == CFFT1DC_ ) 
    code_err_t = 5;
  else 
    code_err_t = 4;
  m = 128;
  isign = 0;
  call_func(num, m, isign, ar, ai, ww);
  m = 64;
  isign = -1;
  call_func(num, m, isign, ar, ai, ww);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! m = %d, isign = %d\n", fname, code_err_t, m, isign);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! m = %d, isign = %d\n", fname, code_err_t, m, isign);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT1DC_ || ifunc == CFFT1DC_ ) 
    code_err_t = 3;
  else 
    code_err_t = 2;
  m = 102;
  isign = -1;
  call_func(num, m, isign, ar, ai, ww);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! m = %d, isign = %d\n", fname, code_err_t, m, isign);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! m = %d, isign = %d\n", fname, code_err_t, m, isign);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT1DC_ || ifunc == CFFT1DC_ ) 
    code_err_t = 5;
  else 
    code_err_t = 4;
  m = 64;
  isign = 0;
  call_func(num, m, isign, ar, ai, ww);
   
   m = 128;
  isign = -1;
  call_func(num, m, isign, ar, ai, ww);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! m = %d, isign = %d\n", fname, code_err_t, m, isign);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! m = %d, isign = %d\n", fname, code_err_t, m, isign);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  ok_g = 0;
  xerbla_called = 0;
  code_err_t = 1;
  m = 64;
  isign = 0;
  call_func(num, m, isign, ar, ai, ww);
  m = 64;
  isign = -1;
  call_func(num, m, isign, NULL, ai, ww);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! First parameter is NULL pointer\n", fname, code_err_t);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! First parameter is NULL pointer\n", fname, code_err_t);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  if (ifunc == ZFFT1DC_ || ifunc == CFFT1DC_ ) {
    ok_g = 0;
    xerbla_called = 0;
    code_err_t = 2;
    m = 64;
    isign = 0;
    call_func(num, m, isign, ar, ai, ww);
    m = 64;
    isign = -1;
    call_func(num, m, isign, ar, NULL, ww);
    if ( !xerbla_called ) {
      printf("  %s: error %d is not catched! Second parameter is NULL pointer\n", fname, code_err_t);
      OPEN_SNAP;
      fprintf(snp_file, "  %s: error %d is not catched! Second parameter is NULL pointer\n", fname, code_err_t);
      CLOSE_SNAP;
    }
    if ( !ok_g ) fatal[ifunc] = 1;
  }

  ok_g = 0;
  xerbla_called = 0;
  if (ifunc == ZFFT1DC_ || ifunc == CFFT1DC_ ) 
    code_err_t = 5;
  else 
    code_err_t = 4;
  m = 32;
  isign = 0;
  call_func(num, m, isign, ar, ai, NULL);
  if ( !xerbla_called ) {
    printf("  %s: error %d is not catched! Last parameter is NULL pointer\n", fname, code_err_t);
    OPEN_SNAP;
    fprintf(snp_file, "  %s: error %d is not catched! Last parameter is NULL pointer\n", fname, code_err_t);
    CLOSE_SNAP;
  }
  if ( !ok_g ) fatal[ifunc] = 1;

  code_err_t = 0;

}

/* ---------------------------------------------------------
*  --                                                     --
*  --     E R R O R       H A N D L I N G                 --
*  --                                                     --
*  ---------------------------------------------------------
*/
void XERBLA(char* name_func, int *ind_err) {

      ok_g = 1;
      xerbla_called = 1;

//      printf("Xerbla called %s %d \n", name_func, *ind_err); 
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

      return;

}

/* Function start */
void zdft(int m)
{
    double *a_r = NULL, *a_i = NULL;
    double *a_rs = NULL, *a_is = NULL;
    double *a_rdft = NULL, *a_idft = NULL;
    double *tw = NULL;
    double *tw_post = NULL;
    double gauge;

    a_r = (double *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_i = (double *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_rs = (double *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_is = (double *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_rdft = (double *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_idft = (double *)LocalAlloc(LMEM_FIXED, m*elm_size);

    tw = (double *)LocalAlloc(LMEM_FIXED, 3*m*elm_size);


    if (a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
        tw != NULL )  {

        /* Compare with DFT routine, isign = -+1 */
        d_fill_rand(a_r, m);
        d_fill_rand(a_i, m);

        isign = -1;
        gauge = d_gauge(a_r, a_i, m, isign);

        zdft1d(a_r, a_i, m, -1, a_rs, a_is, tw);
        zdft1d(a_rs, a_is, m, 1, a_rdft, a_idft, tw);

//        zest (a_rdft, a_idft, a_r, a_i, m, gauge);
        zest (a_rdft, a_rdft, a_idft, a_r, a_i, tw, tw_post, m, post_m, gauge);

    }/* if allocate */

    LocalFree(tw);
    LocalFree(a_idft);
    LocalFree(a_rdft);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);

}/* zdft */

/* Function start */
void cdft(int m)
{
    float *a_r = NULL, *a_i = NULL;
    float *a_rs = NULL, *a_is = NULL;
    float *a_rdft = NULL, *a_idft = NULL; 
    float *tw = NULL;
    float *tw_post = NULL;
    float gauge;

    a_r = (float *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_i = (float *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_rs = (float *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_is = (float *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_rdft = (float *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_idft = (float *)LocalAlloc(LMEM_FIXED, m*elm_size);

    tw = (float *)LocalAlloc(LMEM_FIXED, 3*m*elm_size);

    if (a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
        tw != NULL )  {

        /* Compare with DFT routine, isign = -+1 */
        s_fill_rand(a_r, m);
        s_fill_rand(a_i, m);

        isign = -1;
        gauge = s_gauge(a_r, a_i, m, isign);

        cdft1d(a_r, a_i, m, -1, a_rs, a_is, tw);
        cdft1d(a_rs, a_is, m, 1, a_rdft, a_idft, tw);

//        cest (a_rdft, a_idft, a_r, a_i, m, gauge);
        cest (a_rdft, a_rdft, a_idft, a_r, a_i, tw, tw_post, m, post_m, gauge);

    }/* if allocate */

    LocalFree(tw);
    LocalFree(a_idft);
    LocalFree(a_rdft);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);

}/* cdft */

/* Function start */
void zfft_s(int m)
{
    double *a_r = NULL, *a_i = NULL;
    double *a_rs = NULL, *a_is = NULL;
    double *a_rdft = NULL, *a_idft = NULL;
    double *tw = NULL;
    double *tw_post = NULL;
    double gauge;

    a_r = (double *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_i = (double *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_rs = (double *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_is = (double *)LocalAlloc(LMEM_FIXED, m*elm_size);

    tw = (double *)LocalAlloc(LMEM_FIXED, 3*m*elm_size);

    if (a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
        tw != NULL )  {

        /* Compare with DFT routine, isign = -1 */
        d_fill_rand(a_r, m);
        d_fill_rand(a_i, m);

        isign = -1;
        gauge = d_gauge(a_r, a_i, m, isign);

        zdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);

        ZFFT1DC_S(a_r, a_i, m, 0, tw);
        ZFFT1DC_S(a_r, a_i, m, isign, tw);

        zest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);
//        zest (a_r, a_i, a_rs, a_is, m, gauge);

        /* Compare with DFT routine, isign = 1 */
        d_fill_rand(a_r, m);
        d_fill_rand(a_i, m);

        isign = 1;
        gauge = d_gauge(a_r, a_i, m, isign);

        zdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);

        ZFFT1DC_S(a_r, a_i, m, 0, tw);
        ZFFT1DC_S(a_r, a_i, m, isign, tw);

//        zest (a_r, a_i, a_rs, a_is, m, gauge);
        zest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

    }/* if allocate */

    LocalFree(tw);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);

}/* zfft_s */


/* Function start */
void cfft_s(int m)
{
    float *a_r = NULL, *a_i = NULL;
    float *a_rs = NULL, *a_is = NULL;
    float *a_rdft = NULL, *a_idft = NULL;
    float *tw = NULL;
    float *tw_post = NULL;
    float gauge;

    a_r = (float *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_i = (float *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_rs = (float *)LocalAlloc(LMEM_FIXED, m*elm_size);
    a_is = (float *)LocalAlloc(LMEM_FIXED, m*elm_size);

    tw = (float *)LocalAlloc(LMEM_FIXED, 3*m*elm_size);

    if (a_r != NULL && a_i != NULL && a_rs != NULL && a_is != NULL &&
        tw != NULL )  {

        /* Compare with DFT routine, isign = -1 */
        s_fill_rand(a_r, m);
        s_fill_rand(a_i, m);

        isign = -1;
        gauge = s_gauge(a_r, a_i, m, isign);

        cdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);

        CFFT1DC_S(a_r, a_i, m, 0, tw);
        CFFT1DC_S(a_r, a_i, m, isign, tw);

        cest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);
//        cest (a_r, a_i, a_rs, a_is, m, gauge);

        /* Compare with DFT routine, isign = 1 */
        s_fill_rand(a_r, m);
        s_fill_rand(a_i, m);

        isign = 1;
        gauge = s_gauge(a_r, a_i, m, isign);

        cdft1d(a_r, a_i, m, isign, a_rs, a_is, tw);

        CFFT1DC_S(a_r, a_i, m, 0, tw);
        CFFT1DC_S(a_r, a_i, m, isign, tw);
//        cest (a_r, a_i, a_rs, a_is, m, gauge);
        cest (a_r, a_r, a_i, a_rs, a_is, tw, tw_post, m, post_m, gauge);

    }/* if allocate */

    LocalFree(tw);
    LocalFree(a_is);
    LocalFree(a_rs);
    LocalFree(a_i);
    LocalFree(a_r);
 
}/* cfft_s */

int cpostm (float* a, float* a_r, float* a_i, float* a_rs, float* a_is,
			float* tw, float* tw_post, int m, int post_m)
{
    int s;

	if (tw_post == NULL) return 0;

    if (r_type) { 
	    for (s = 0; s < post_m; s++) {
		    if (a[m+2+s] != a_rs[m+s]) {
			    printf("\n Error (vector lenght = %d, isign = %d ) : using of memory after array. \n", m, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (vector lenght = %d, isign = %d ) : using of memory after array. \n", m, isign);
				CLOSE_SUM;
			    return 1;
			}
		}
	    for (s = 0; s < post_m; s++) {
		    if (tw[2*m+s] != tw_post[s]) {
			    printf("\n Error (vector lenght = %d, isign = %d ) : using of memory after twiddle array. \n", m, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (vector lenght = %d, isign = %d ) : using of memory after twiddle array. \n", m, isign);
				CLOSE_SUM;
			    return 1;
			}
		}
	} else { 
	    for (s = 0; s < post_m; s++) {
		    if (a_r[m+s] != a_rs[m+s]) {
			    printf("\n Error (vector lenght = %d, isign = %d ) : using of memory after real array. \n", m, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (vector lenght = %d, isign = %d ) : using of memory after real array. \n", m, isign);
				CLOSE_SUM;
			    return 1;
			}
		}
	    for (s = 0; s < post_m; s++) {
		    if (a_i[m+s] != a_is[m+s]) {
			    printf("\n Error (vector lenght = %d, isign = %d ) : using of memory after image array. \n", m, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (vector lenght = %d, isign = %d ) : using of memory after image array. \n", m, isign);
				CLOSE_SUM;
			    return 1;
			}
		}
	    for (s = 0; s < post_m; s++) {
		    if (tw[3*m+s] != tw_post[s]) {
			    printf("\n Error (vector lenght = %d, isign = %d ) : using of memory after twiddle array. \n", m, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (vector lenght = %d, isign = %d ) : using of memory after twiddle array. \n", m, isign);
				CLOSE_SUM;
			    return 1;
			}
		}
	}
    return 0;     
}

int zpostm (double* a, double* a_r, double* a_i, double* a_rs, double* a_is,
			double* tw, double* tw_post, int m, int post_m)
{
    int s;

	if (tw_post == NULL) return 0;

    if (r_type) { 
	    for (s = 0; s < post_m; s++) {
		    if (a[m+2+s] != a_rs[m+s]) {
			    printf("\n Error (vector lenght = %d, isign = %d ) : using of memory after array. \n", m, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (vector lenght = %d, isign = %d ) : using of memory after array. \n", m, isign);
				CLOSE_SUM;
			    return 1;
			}
		}
	    for (s = 0; s < post_m; s++) {
		    if (tw[2*m+s] != tw_post[s]) {
			    printf("\n Error (vector lenght = %d, isign = %d ) : using of memory after twiddle array. \n", m, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (vector lenght = %d, isign = %d ) : using of memory after twiddle array. \n", m, isign);
				CLOSE_SUM;
			    return 1;
			}
		}
	} else { 
                 
		for (s = 0; s < post_m; s++) {
		    if (a_r[m+s] != a_rs[m+s]) {
			    printf("\n Error (vector lenght = %d, isign = %d ) : using of memory after real array. \n", m, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (vector lenght = %d , isign = %d) : using of memory after real array. \n", m, isign);
				CLOSE_SUM;
			    return 1;
			}
		}
	    for (s = 0; s < post_m; s++) {
		    if (a_i[m+s] != a_is[m+s]) {
			    printf("\n Error (vector lenght = %d, isign = %d ) : using of memory after image array. \n", m, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (vector lenght = %d, isign = %d ) : using of memory after image array. \n", m, isign);
				CLOSE_SUM;
			    return 1;
			}
		}
	    for (s = 0; s < post_m; s++) {
		    if (tw[3*m+s] != tw_post[s]) {
//                printf(" tw[3*m+%d] = %f, tw_post[%d] = %f \n", s, tw[3*m+s], s, tw_post[s]);
			    printf("\n Error (vector lenght = %d, isign = %d ) : using of memory after twiddle array. \n", m, isign);
				OPEN_SUM;
			    fprintf(sum_file, "\n Error (vector lenght = %d, isign = %d ) : using of memory after twiddle array. \n", m, isign);
				CLOSE_SUM;
			    return 1;
			}
		}
	}
    return 0;     
}

