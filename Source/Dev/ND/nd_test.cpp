
#include <stdlib.h>
#include <iostream.h>
#include <math.h>
#include "nd.h"


void
test_abs (double result, double expected, double absolute_error,
	      const char *test_description,...)
{
  int status ;

  if (result != result) 
    {
      status = (expected == expected);   /* Check for NaN vs number */
    }
  else 
    {
      status = fabs(result-expected) > absolute_error ;
    }

  if (status == 0)  cerr << "PASS: " << result << "\t" << expected << "\t" << fabs(result-expected) << "\t" << absolute_error << "\n";
  else cerr << "FAIL: ";

}


double
f1 (double x)
{
  return exp (x);
}

double
df1 (double x)
{
  return exp (x);
}

double
f2 (double x)
{
  if (x >= 0.0)
    {
      return x * sqrt (x);
    }
  else
    {
      return 0.0;
    }
}

double
df2 (double x)
{
  if (x >= 0.0)
    {
      return 1.5 * sqrt (x);
    }
  else
    {
      return 0.0;
    }
}

double
f3 (double x)
{
  if (x != 0.0)
    {
      return sin (1 / x);
    }
  else
    {
      return 0.0;
    }
}

double
df3 (double x)
{
  if (x != 0.0)
    {
      return -cos (1 / x) / (x * x);
    }
  else
    {
      return 0.0;
    }
}

double
f4 (double x)
{
  return exp (-x * x);
}

double
df4 (double x)
{
  return -2.0 * x * exp (-x * x);
}

double
f5 (double x)
{
  return x * x;
}

double
df5 (double x)
{
  return 2.0 * x;
}

double
f6 (double x)
{
  return 1.0 / x;
}

double
df6 (double x)
{
  return -1.0 / (x * x);
}

typedef int (nd_fn) (const function * f, double x, double * res, double *abserr);

void
test (nd_fn * diff, function * f, function * df, double x, 
      const char * desc)
{
  double result, abserr;
  double expected = (*df)(x);
  (*diff) (f, x, &result, &abserr);
  test_abs (result, expected, abserr, desc);
  if(fabs(result-expected) >  abserr) cerr << "valid error estimate " << desc;
}

void
test ()
{
  function F1, DF1, F2, DF2, F3, DF3, F4, DF4, F5, DF5, F6, DF6;

  F1 = &f1;
  DF1 = &df1;

  F2 = &f2;
  DF2 = &df2;

  F3 = &f3;
  DF3 = &df3;

  F4 = &f4;
  DF4 = &df4;

  F5 = &f5;
  DF5 = &df5;

  F6 = &f6;
  DF6 = &df6;
  
  test (&nd_central, &F1, &DF1, 1.0, "exp(x), x=1, central diff");
  test (&nd_forward, &F1, &DF1, 1.0, "exp(x), x=1, forward diff");
  test (&nd_backward, &F1, &DF1, 1.0, "exp(x), x=1, backward diff");

  test (&nd_central, &F2, &DF2, 0.1, "x^(3/2), x=0.1, central diff");
  test (&nd_forward, &F2, &DF2, 0.1, "x^(3/2), x=0.1, forward diff");
  test (&nd_backward, &F2, &DF2, 0.1, "x^(3/2), x=0.1, backward diff");

  test (&nd_central, &F3, &DF3, 0.45, "sin(1/x), x=0.45, central diff");
  test (&nd_forward, &F3, &DF3, 0.45, "sin(1/x), x=0.45, forward diff");
  test (&nd_backward, &F3, &DF3, 0.45, "sin(1/x), x=0.45, backward diff");

  test (&nd_central, &F4, &DF4, 0.5, "exp(-x^2), x=0.5, central diff");
  test (&nd_forward, &F4, &DF4, 0.5, "exp(-x^2), x=0.5, forward diff");
  test (&nd_backward, &F4, &DF4, 0.5, "exp(-x^2), x=0.5, backward diff");

  test (&nd_central, &F5, &DF5, 0.0, "x^2, x=0, central diff");
  test (&nd_forward, &F5, &DF5, 0.0, "x^2, x=0, forward diff");
  test (&nd_backward, &F5, &DF5, 0.0, "x^2, x=0, backward diff");

  test (&nd_central, &F6, &DF6, 10.0, "1/x, x=10, central diff");
  test (&nd_forward, &F6, &DF6, 10.0, "1/x, x=10, forward diff");
  test (&nd_backward, &F6, &DF6, 10.0, "1/x, x=10, backward diff");
}



