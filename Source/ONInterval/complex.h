/************************************************************************
*  Complex.h (Definition of type COMPLEX)
*
*  Version:                     1.6
*  Date:                        1/16/95
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __COMPLEX__
#define __COMPLEX__

#include "Portab.h"
#include "config.h"
#include <math.h>
#include <iostream.h>

class COMPLEX {
  REAL re;
  REAL im;
public:
  COMPLEX () { }
  COMPLEX (REAL r) { re = r; im = 0.0; }
  COMPLEX (REAL r, REAL i) { re = r; im = i; }
  COMPLEX & operator = (REAL x) { re = x; im = 0.0; return *this; }
  COMPLEX & operator += (REAL x) { re += x; return *this; }
  COMPLEX & operator -= (REAL x) { re -= x; return *this; }
  COMPLEX & operator *= (REAL x) { re *= x; im *= x; return *this; }
  COMPLEX & operator /= (REAL x) { re /= x; im /= x; return *this; }
  COMPLEX & operator = (COMPLEX & x)
    { re = Re(x); im = Im(x); return *this; }
  COMPLEX & operator += (COMPLEX & x)
    { re += Re(x); im += Im(x); return *this; }
  COMPLEX & operator -= (COMPLEX & x)
    { re -= Re(x); im -= Im(x); return *this; }
  COMPLEX & operator *= (COMPLEX & x)
    { REAL t = re;
      re = re * Re(x) - im * Im(x);
      im = im * Re(x) + t  * Im(x);
      return *this;
    }
  COMPLEX & operator /= (COMPLEX & x);
  friend COMPLEX operator + (COMPLEX & x) { return x; }
  friend COMPLEX operator - (COMPLEX & x)
    { return COMPLEX (-Re(x), -Im(x)); }
  friend REAL Re (COMPLEX & x) { return x.re; }
  friend REAL Im (COMPLEX & x) { return x.im; }
  friend COMPLEX operator + (COMPLEX & x, REAL y)
    { return COMPLEX (Re(x) + y, Im(x)); }
  friend COMPLEX operator + (REAL x, COMPLEX & y)
    { return COMPLEX (x + Re(y), Im(y)); }
  friend COMPLEX operator + (COMPLEX & x, COMPLEX & y)
    { return COMPLEX (Re(x) + Re(y), Im(x) + Im(y)); }
  friend COMPLEX operator - (COMPLEX & x, REAL y)
    { return COMPLEX (Re(x) - y, Im(x)); }
  friend COMPLEX operator - (REAL x, COMPLEX & y)
    { return COMPLEX (x - Re(y), -Im(y)); }
  friend COMPLEX operator - (COMPLEX & x, COMPLEX & y)
    { return COMPLEX (Re(x) - Re(y), Im(x) - Im(y)); }
  friend COMPLEX operator * (COMPLEX & x, REAL y)
    { return COMPLEX (Re(x) * y, Im(x) * y); }
  friend COMPLEX operator * (REAL x, COMPLEX & y)
    { return COMPLEX (x * Re(y), x * Im(y)); }
  friend COMPLEX operator * (COMPLEX & x, COMPLEX & y)
    { return COMPLEX (Re(x) * Re(y) - Im(x) * Im(y),
		      Im(x) * Re(y) + Im(y) * Re(x)); }
  friend COMPLEX operator / (COMPLEX & x, REAL y)
    { return COMPLEX (Re(x) / y, Im(x) / y); }
  friend COMPLEX operator / (REAL x, COMPLEX & y);
  friend COMPLEX operator / (COMPLEX & x, COMPLEX & y);
  friend INT operator == (COMPLEX & x, REAL y)
    { return (Re(x) == y) && (Im(x) == 0.0); }
  friend INT operator == (REAL x, COMPLEX & y)
    { return (x == Re(y)) && (Im(y) == 0.0); }
  friend INT operator == (COMPLEX & x, COMPLEX & y)
    { return (Re(x) == Re(y)) && (Im(x) == Im(y)); }
  friend INT operator != (COMPLEX & x, REAL y)
    { return (Re(x) != y) || (Im(x) != 0.0); }
  friend INT operator != (REAL x, COMPLEX & y)
    { return (x != Re(y)) || (Im(y) != 0.0); }
  friend INT operator != (COMPLEX & x, COMPLEX & y)
    { return (Re(x) != Re(y)) || (Im(x) != Im(y)); }
  friend COMPLEX Conjg (COMPLEX & x)
    { return COMPLEX (Re(x), -Im(x)); }
  friend REAL Abs (COMPLEX & x);
  friend COMPLEX Sqrt (COMPLEX & x);
  friend ostream & operator << (ostream & o, COMPLEX & x);
  friend istream & operator >> (istream & i, COMPLEX & x);
};

extern COMPLEX I;

#endif /* __COMPLEX__ */
