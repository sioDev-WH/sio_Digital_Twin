#include <math.h>
#include "nd.h"

#define SUCCESS 1
#define SQRT_DBL_EPSILON   1.4901161193847656e-08

int
nd_backward (const function * f,
		   double x, double *result, double *abserr)
{

  int i, k;
  double h = SQRT_DBL_EPSILON;
  double a[3], d[3], a2;

  for (i = 0; i < 3; i++)
    {
      a[i] = x + (i - 2.0) * h;
      d[i] = (*f)(a[i]);
    }

  for (k = 1; k < 4; k++)
    {
      for (i = 0; i < 3 - k; i++)
	{
	  d[i] = (d[i + 1] - d[i]) / (a[i + k] - a[i]);
	}
    }


  a2 = fabs (d[0] + d[1] + d[2]);

  if (a2 < 100.0 * SQRT_DBL_EPSILON)
    {
      a2 = 100.0 * SQRT_DBL_EPSILON;
    }

  h = sqrt (SQRT_DBL_EPSILON / (2.0 * a2));

  if (h > 100.0 * SQRT_DBL_EPSILON)
    {
      h = 100.0 * SQRT_DBL_EPSILON;
    }

  *result = ((*f)(x) - (*f)(x - h)) / h;
  *abserr = fabs (10.0 * a2 * h);

  return SUCCESS;
}

int
nd_forward (const function * f,
		  double x, double *result, double *abserr)
{
  int i, k;
  double h = SQRT_DBL_EPSILON;
  double a[3], d[3], a2;

  for (i = 0; i < 3; i++)
    {
      a[i] = x + i * h;
      d[i] = (*f)(a[i]);
    }

  for (k = 1; k < 4; k++)
    {
      for (i = 0; i < 3 - k; i++)
	{
	  d[i] = (d[i + 1] - d[i]) / (a[i + k] - a[i]);
	}
    }

  a2 = fabs (d[0] + d[1] + d[2]);

  if (a2 < 100.0 * SQRT_DBL_EPSILON)
    {
      a2 = 100.0 * SQRT_DBL_EPSILON;
    }

  h = sqrt (SQRT_DBL_EPSILON / (2.0 * a2));

  if (h > 100.0 * SQRT_DBL_EPSILON)
    {
      h = 100.0 * SQRT_DBL_EPSILON;
    }

  *result = ((*f)(x + h) - (*f)(x)) / h;
  *abserr = fabs (10.0 * a2 * h);

  return SUCCESS;
}

int
nd_central (const function * f,
		  double x, double *result, double *abserr)
{
  int i, k;
  double h = SQRT_DBL_EPSILON;
  double a[4], d[4], a3;

  for (i = 0; i < 4; i++)
    {
      a[i] = x + (i - 2.0) * h;
      d[i] = (*f)(a[i]);
    }

  for (k = 1; k < 5; k++)
    {
      for (i = 0; i < 4 - k; i++)
	{
	  d[i] = (d[i + 1] - d[i]) / (a[i + k] - a[i]);
	}
    }

  a3 = fabs (d[0] + d[1] + d[2] + d[3]);

  if (a3 < 100.0 * SQRT_DBL_EPSILON)
    {
      a3 = 100.0 * SQRT_DBL_EPSILON;
    }

  h = pow (SQRT_DBL_EPSILON / (2.0 * a3), 1.0 / 3.0);

  if (h > 100.0 * SQRT_DBL_EPSILON)
    {
      h = 100.0 * SQRT_DBL_EPSILON;
    }

  *result = ((*f)(x + h) - (*f)(x - h)) / (2.0 * h);
  *abserr = fabs (100.0 * a3 * h * h);

  return SUCCESS;
}
