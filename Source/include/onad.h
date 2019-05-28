#ifndef _ON_AD_H_
#define _ON_AD_H_

#include "OnDaeCOSolverExport.h"
//#include <iostream.h>

class ONDAECOSOLVER_API Fdouble
{

public:
  // local variables
  double v;                                // value
  double* g;                               // gradient vector
  long gsize;                              // gradient vector size
  long gdim;

  // constructors / destructors
  Fdouble();
  Fdouble(const double& x);
  Fdouble(const Fdouble& x);
  ~Fdouble();

  // copy operator
  Fdouble& operator= (const Fdouble& a);

  // gradient vector allocation
  void diff(long idx, long n);             // allocate the gradient vector on independent variables, where idx == this
  void alloc_g(long n);                    // allocate the gradient vector
  
  // accessor functions
  double& x();          // double value
  double& d(long i);    // partial derivative d[i] for dependent variables

  Fdouble& operator += (const Fdouble& x);
  Fdouble& operator -= (const Fdouble& x);
  Fdouble& operator *= (const Fdouble& x);
  Fdouble& operator /= (const Fdouble& x);
  Fdouble& operator += (const double& x);
  Fdouble& operator -= (const double& x);
  Fdouble& operator *= (const double& x);
  Fdouble& operator /= (const double& x);

  friend bool ONDAECOSOLVER_API  operator == (const Fdouble &a, const Fdouble &b);
  friend bool ONDAECOSOLVER_API  operator == (const Fdouble &a, const double &b);
  friend bool ONDAECOSOLVER_API  operator == (const double &a, const Fdouble &b);

  friend bool ONDAECOSOLVER_API  operator != (const Fdouble &a, const Fdouble &b);
  friend bool ONDAECOSOLVER_API  operator != (const Fdouble &a, const double &b);
  friend bool ONDAECOSOLVER_API  operator != (const double &a, const Fdouble &b);

  friend bool ONDAECOSOLVER_API  operator > (const Fdouble &a, const Fdouble &b);
  friend bool ONDAECOSOLVER_API  operator > (const Fdouble &a, const double &b);
  friend bool ONDAECOSOLVER_API  operator > (const double &a, const Fdouble &b);

  friend bool ONDAECOSOLVER_API  operator >= (const Fdouble &a, const Fdouble &b);
  friend bool ONDAECOSOLVER_API  operator >= (const Fdouble &a, const double &b);
  friend bool ONDAECOSOLVER_API  operator >= (const double &a, const Fdouble &b);

  friend bool ONDAECOSOLVER_API  operator < (const Fdouble &a, const Fdouble &b);
  friend bool ONDAECOSOLVER_API  operator < (const Fdouble &a, const double &b);
  friend bool ONDAECOSOLVER_API  operator < (const double &a, const Fdouble &b);

  friend bool ONDAECOSOLVER_API  operator <= (const Fdouble &a, const Fdouble &b);
  friend bool ONDAECOSOLVER_API  operator <= (const Fdouble &a, const double &b);
  friend bool ONDAECOSOLVER_API  operator <= (const double &a, const Fdouble &b);

};

//ostream& operator << (ostream& os, const Fdouble& o);

Fdouble ONDAECOSOLVER_API operator+ (const double& a, const Fdouble& b);
Fdouble ONDAECOSOLVER_API operator+ (const Fdouble& a,const double& b);
Fdouble ONDAECOSOLVER_API operator+ (const Fdouble& a, const Fdouble& b);
Fdouble ONDAECOSOLVER_API operator- (const double& a, const Fdouble& b);
Fdouble ONDAECOSOLVER_API operator- (const Fdouble& a,const double& b);
Fdouble ONDAECOSOLVER_API operator- (const Fdouble& a, const Fdouble& b);

Fdouble ONDAECOSOLVER_API operator* (const double& a, const Fdouble& b);
Fdouble ONDAECOSOLVER_API operator* (const Fdouble& a,const double& b);
Fdouble ONDAECOSOLVER_API operator* (const Fdouble& a, const Fdouble& b);

Fdouble ONDAECOSOLVER_API operator/ (const double& a, const Fdouble& b);
Fdouble ONDAECOSOLVER_API operator/ (const Fdouble& a,const double& b);
Fdouble ONDAECOSOLVER_API operator/ (const Fdouble& a, const Fdouble& b);

Fdouble ONDAECOSOLVER_API pow (const double& a, const Fdouble& b);
Fdouble ONDAECOSOLVER_API pow (const Fdouble& a,const double& b);
Fdouble ONDAECOSOLVER_API pow (const Fdouble& a, const Fdouble& b);


/* Unary operators */
Fdouble ONDAECOSOLVER_API operator+ (const Fdouble& a);
Fdouble ONDAECOSOLVER_API operator- (const Fdouble& a);
Fdouble ONDAECOSOLVER_API pow (const Fdouble& a,long b);
Fdouble ONDAECOSOLVER_API sqr (const Fdouble& a);
Fdouble ONDAECOSOLVER_API exp (const Fdouble& a);
Fdouble ONDAECOSOLVER_API log (const Fdouble& a);
Fdouble ONDAECOSOLVER_API log10 (const Fdouble& a);
Fdouble ONDAECOSOLVER_API sqrt (const Fdouble& a);
Fdouble ONDAECOSOLVER_API sin (const Fdouble& a);
Fdouble ONDAECOSOLVER_API cos (const Fdouble& a);
Fdouble ONDAECOSOLVER_API tan (const Fdouble& a);
Fdouble ONDAECOSOLVER_API asin (const Fdouble& a);
Fdouble ONDAECOSOLVER_API acos (const Fdouble& a);
Fdouble ONDAECOSOLVER_API atan (const Fdouble& a);

#endif // _ON_AD_H_