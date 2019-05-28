/************************************************************************
*  Complex.C (Implementation of type Complex)
*
*  Version:                     1.2
*  Date:                        5/4/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)Complex.C 1.2 93/05/04 OK";

//#include "stdafx.h"
#include "complex.h"

COMPLEX I (0.0, 1.0);

COMPLEX & COMPLEX::operator /= (COMPLEX & x)
{
  REAL r, den;
  REAL thisRe = re;

  if (fabs (Re(x)) >= fabs (Im(x))) {
    r = Im(x) / Re(x);
    den = Re(x) + r * Im(x);
    re = (thisRe + r * im) / den;
    im = (im - r * thisRe) / den;
  }
  else {
    r = Re(x) / Im(x);
    den = Im(x) + r * Re(x);
    re = (r * thisRe + im) / den;
    im = (r * im - thisRe) / den;
  }
  return *this;
}

COMPLEX operator / (REAL x, COMPLEX & y)
{
  REAL r, den;

  if (fabs (Re(y)) >= fabs (Im(y))) {
    r = Im(y) / Re(y);
    den = Re(y) + r * Im(y);
    return COMPLEX (x / den, -r * x / den);
  }
  else {
    r = Re(y) / Im(y);
    den = Im(y) + r * Re(y);
    return COMPLEX (r * x / den, -x / den);
  }
}

COMPLEX operator / (COMPLEX & x, COMPLEX & y)
{
  REAL r, den;

  if (fabs (Re(y)) >= fabs (Im(y))) {
    r = Im(y) / Re(y);
    den = Re(y) + r * Im(y);
    return COMPLEX ((Re(x) + r * Im(x)) / den,
		    (Im(x) - r * Re(x)) / den);
  }
  else {
    r = Re(y) / Im(y);
    den = Im(y) + r * Re(y);
    return COMPLEX ((r * Re(x) + Im(x)) / den,
		    (r * Im(x) - Re(x)) / den);
  }
}

REAL Abs (COMPLEX & x)
{
  REAL a, b, temp;

  a = fabs (Re(x));
  b = fabs (Im(x));
  if (a == 0.0) return b;
  else if (b == 0.0) return a;
  else if (a > b) {
    temp = b / a;
    return a * sqrt (1.0 + temp * temp);
  }
  else {
    temp = a / b;
    return b * sqrt (1.0 + temp * temp);
  }
}

COMPLEX Sqrt (COMPLEX & x)
{
  REAL a, b, w, r;

  if ((Re(x) == 0.0) && (Im(x) == 0.0)) return COMPLEX (0.0);
  else {
    a = fabs (Re(x));
    b = fabs (Im(x));
    if (a >= b) {
      r = b / a;
      w = sqrt(a) * sqrt (0.5 * (1.0 + sqrt (1.0 + r * r)));
    }
    else {
      r = a / b;
      w = sqrt(b) * sqrt (0.5 * (r + sqrt (1.0 + r * r)));
    }
    if (Re(x) >= 0.0)
      return COMPLEX (w, Im(x) / (2.0 * w));
    else {
      r = (Im(x) >= 0.0) ? w : -w;
      return COMPLEX (Im(x) / (2.0 * r), r);
    }
  }
}

ostream & operator << (ostream & os, COMPLEX & x)
{
  return os << '(' << Re (x) << ',' << Im (x) << ')';
}

istream & operator >> (istream & is, COMPLEX & x)
{
  REAL a, b;

  is >> a;
  is >> b;
  x = COMPLEX (a, b);
  return is;
}

// The following code is only used to force Constants.C to be
// always included in the executable code.

extern VOID RegisterConstants ();

VOID RegisterComplex () { RegisterConstants (); }
