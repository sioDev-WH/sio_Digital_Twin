
#ifndef __ND_H__
#define __ND_H__

typedef double (* function) (double x);

int nd_central (const function *f,
		      double x,
		      double *result, double *abserr);

int nd_backward (const function *f,
		       double x,
		       double *result, double *abserr);

int nd_forward (const function *f,
		      double x,
		      double *result, double *abserr);


#endif