/************************************************************************
*  Interval.h (Definition of type INTERVAL)
*
*  Version:                     1.15
*  Date:                        11/14/94
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __INTERVAL__
#define __INTERVAL__

#include "Bias0.h"
#include <iostream.h>
#include "ONInterval.h"

#if defined (__GNUC__)
#define Bias(x)        &((x).ival)
#endif

class ONINTERVAL_API INTERVAL {
#if defined (__GNUC__)
public:
#endif
  BIASINTERVAL ival;
public:
  INTERVAL () { }
  INTERVAL (REAL a)
    { BiasHullR(& ival, & a); }
  INTERVAL (REAL a, REAL b)
    { BiasHullRR(& ival, & a, & b); }
  // Because the appropiate routines are missing in Bias, a temporary
  // variable is needed for +=, -=, *=, /=.
  INTERVAL & operator += (REAL x)
    { INTERVAL t;
      BiasAddIR (Bias(t), Bias(*this), & x);
      *this = t; return *this;
    }
  INTERVAL & operator -= (REAL x)
    { INTERVAL t;
      BiasSubIR (Bias(t), Bias(*this), & x);
      *this = t; return *this;
    }
  INTERVAL & operator *= (REAL x)
    { INTERVAL t;
      BiasMulIR (Bias(t), Bias(*this), & x);
      *this = t; return *this;
    }
  INTERVAL & operator /= (REAL x)
    { INTERVAL t;
      BiasDivIR (Bias(t), Bias(*this), & x);
      *this = t; return *this;
    }
  INTERVAL & operator += (INTERVAL & x)
    { INTERVAL t;
      BiasAddII (Bias(t), Bias(*this), Bias(x));
      *this = t; return *this;
    }
  INTERVAL & operator -= (INTERVAL & x)
    { INTERVAL t;
      BiasSubII (Bias(t), Bias(*this), Bias(x));
      *this = t; return *this;
    }
  INTERVAL & operator *= (INTERVAL & x)
    { INTERVAL t;
      BiasMulII (Bias(t), Bias(*this), Bias(x));
      *this = t; return *this;
    }
  INTERVAL & operator /= (INTERVAL & x)
    { INTERVAL t;
      BiasDivII (Bias(t), Bias(*this), Bias(x));
      *this = t; return *this;
    }
#if !defined (__GNUC__)
  friend BIASINTERVAL * Bias (INTERVAL & x)
    { return &(x.ival); }
#endif
  friend INTERVAL operator + (INTERVAL & x) { return x; }
  friend INTERVAL operator - (INTERVAL & x)
    { INTERVAL result;
      BiasNeg (Bias(result), Bias(x));
      return result;
    }
  friend INTERVAL AddBounds (REAL x, REAL y)
    { INTERVAL result;
      BiasAddRR (Bias(result), & x, & y);
      return result;
    }
  friend INTERVAL operator + (REAL x, INTERVAL & y)
    { INTERVAL result;
      BiasAddRI (Bias(result), & x, Bias(y));
      return result;
    }
  friend INTERVAL operator + (INTERVAL & x, REAL y)
    { INTERVAL result;
      BiasAddIR (Bias(result), Bias(x), & y);
      return result;
    }
  friend INTERVAL operator + (INTERVAL & x, INTERVAL & y)
    { INTERVAL result;
      BiasAddII (Bias(result), Bias(x), Bias(y));
      return result;
    }
  friend INTERVAL SubBounds (REAL x, REAL y)
    { INTERVAL result;
      BiasSubRR (Bias(result), & x, & y);
      return result;
    }
  friend INTERVAL operator - (REAL x, INTERVAL & y)
    { INTERVAL result;
      BiasSubRI (Bias(result), & x, Bias(y));
      return result;
    }
  friend INTERVAL operator - (INTERVAL & x, REAL y)
    { INTERVAL result;
      BiasSubIR (Bias(result), Bias(x), & y);
      return result;
    }
  friend INTERVAL operator - (INTERVAL & x, INTERVAL & y)
    { INTERVAL result;
      BiasSubII (Bias(result), Bias(x), Bias(y));
      return result;
    }
  friend INTERVAL MulBounds (REAL x, REAL y)
    { INTERVAL result;
      BiasMulRR (Bias(result), & x, & y);
      return result;
    }
  friend INTERVAL operator * (REAL x, INTERVAL & y)
    { INTERVAL result;
      BiasMulRI (Bias(result), & x, Bias(y));
      return result;
    }
  friend INTERVAL operator * (INTERVAL & x, REAL y)
    { INTERVAL result;
      BiasMulIR (Bias(result), Bias(x), & y);
      return result;
    }
  friend INTERVAL operator * (INTERVAL & x, INTERVAL & y)
    { INTERVAL result;
      BiasMulII (Bias(result), Bias(x), Bias(y));
      return result;
    }
  friend INTERVAL DivBounds (REAL x, REAL y)
    { INTERVAL result;
      BiasDivRR (Bias(result), & x, & y);
      return result;
    }
  friend INTERVAL operator / (REAL x, INTERVAL & y)
    { INTERVAL result;
      BiasDivRI (Bias(result), & x, Bias(y));
      return result;
    }
  friend INTERVAL operator / (INTERVAL & x, REAL y)
    { INTERVAL result;
      BiasDivIR (Bias(result), Bias(x), & y);
      return result;
    }
  friend INTERVAL operator / (INTERVAL & x, INTERVAL & y)
    { INTERVAL result;
      BiasDivII (Bias(result), Bias(x), Bias(y));
      return result;
    }
  friend REAL Inf (INTERVAL & x)
    { return BiasInf (Bias(x)); }
  friend REAL Sup (INTERVAL & x)
    { return BiasSup (Bias(x)); }
  friend REAL Pred (REAL a) { return BiasPredR (& a); }
  friend REAL Succ (REAL a) { return BiasSuccR (& a); }
  friend INTERVAL Pred (INTERVAL & x)
    { INTERVAL result;
      BiasPredI (Bias(result), Bias(x));
      return result;
    }
  friend INTERVAL Succ (INTERVAL & x)
    { INTERVAL result;
      BiasSuccI (Bias(result), Bias(x));
      return result;
    }
  friend INTERVAL Hull (REAL a)
    { INTERVAL result;
      BiasHullR (Bias(result), & a);
      return result;
    }
  friend INTERVAL Hull (REAL a, REAL b)
    { INTERVAL result;
      BiasHullRR (Bias(result), & a, & b);
      return result;
    }
  friend INTERVAL Hull (REAL a, INTERVAL & b)
    { INTERVAL result;
      BiasHullRI (Bias(result), & a, Bias(b));
      return result;
    }
  friend INTERVAL Hull (INTERVAL & a, REAL b)
    { INTERVAL result;
      BiasHullIR (Bias(result), Bias(a), & b);
      return result;
    }
  friend INTERVAL Hull (INTERVAL & a, INTERVAL & b)
    { INTERVAL result;
      BiasHullII (Bias(result), Bias(a), Bias(b));
      return result;
    }
  friend INTERVAL SymHull (REAL a)
    { INTERVAL result;
      REAL minus_a = -a;
      BiasHullRR (Bias(result), & a, & minus_a);
      return result;
    }
  friend REAL Mid (INTERVAL & a) { return BiasMid (Bias(a)); }
  friend REAL Diam (INTERVAL & a) { return BiasDiam (Bias(a)); }
  friend REAL Abs (INTERVAL & a) { return BiasAbs (Bias(a)); }
  friend REAL Mig (INTERVAL & a) { return Distance (0.0, a); }
  friend REAL Distance (REAL a, INTERVAL & b)
    { return BiasDistRI (& a, Bias(b)); }
  friend REAL Distance (INTERVAL & a, REAL b)
    { return BiasDistIR (Bias(a), & b); }
  friend REAL Distance (INTERVAL & a, INTERVAL & b)
    { return BiasDistII (Bias(a), Bias(b)); }
  friend INT Intersection (INTERVAL & r, INTERVAL & a, INTERVAL & b)
    { return BiasIntersection (Bias(r), Bias(a), Bias(b)); }
  friend INT operator <= (REAL a, INTERVAL & b)
    { return BiasInR (& a, Bias(b)); }
  friend INT operator <= (INTERVAL & a, INTERVAL & b)
    { return BiasInI (Bias(a), Bias(b)); }
  friend INT operator < (REAL a, INTERVAL & b)
    { return BiasInInteriorR (& a, Bias(b)); }
  friend INT operator < (INTERVAL & a, INTERVAL & b)
    { return BiasInInteriorI (Bias(a), Bias(b)); }
  friend INT operator == (INTERVAL & a, INTERVAL & b)
    { return BiasIsEqual (Bias(a), Bias(b)); }
  friend INT operator != (INTERVAL & a, INTERVAL & b)
    { return !BiasIsEqual (Bias(a), Bias(b)); }
  friend ostream & operator << (ostream &, INTERVAL &);
  friend istream & operator >> (istream &, INTERVAL &);
};

inline INTERVAL operator ++ (INTERVAL & x) { return Succ (x); }
inline INTERVAL operator -- (INTERVAL & x) { return Pred (x); }

#endif /* __INTERVAL__ */
