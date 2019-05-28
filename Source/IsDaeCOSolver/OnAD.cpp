#include <math.h>
#include "OnDaeCOSolverMacros.h"
#include "OnAD.h"

#define NULL 0

#if 0
#ifdef _DEBUG
#include "crtdbg.h"
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)   
#endif
#endif

// constructor / destructor
Fdouble::Fdouble()
{
  v = 0.0;
  g = NULL; 
  gsize = 0;
  gdim = 0;
}

Fdouble::Fdouble(const double& x)
{ 
  v = x;
  g = NULL; 
  gsize = 0; 
  gdim = 0;
}

Fdouble::~Fdouble()
{
  DESTROY_VECTOR(g)
}

// copy operator
Fdouble& Fdouble::operator= (const Fdouble& a) 
{
  long i;

  v = a.v;
  if (a.gsize > gdim)
  {
    DESTROY_VECTOR(g)
    gdim = a.gdim;
    g = new double[gdim];
  }

  gsize = a.gsize;
  for (i = 0; i < gsize; i++) g[i] = a.g[i];
  
  return *this;
}

void Fdouble::diff(long idx, long n)
{
  long i;

  if (n > gdim)
  {
    DESTROY_VECTOR(g)
    gdim = n;
    g = new double[gdim];
  }

  gsize = n;
  for (i = 0; i < gdim; i++) g[i] = 0.0;

  if (idx >= 0) g[idx] = 1.0;
}

void Fdouble::alloc_g(long n) 
{
  if (n > gdim)
  {
    DESTROY_VECTOR(g)
    gdim = n;
    g = new double[gdim];
  }
  gsize = n;
}

double& Fdouble::x() 
{
  return v;
}

double& Fdouble::d(long i) 
{
  if (g==NULL) 
  {
    // TODO: determine what to do with the following static declaration
    static double d0(0);
    return d0;
  } 
  else 
  {
    return g[i];
  }
}

Fdouble::Fdouble(const Fdouble& x) : v(x.v)
{
  long i;

  g = NULL; 
  gsize = 0;
  gdim = 0;

  if (x.gsize > 0)
  {
    gdim = x.gdim;
    g = new double[gdim];
  }

  gsize = x.gsize;
  for (i = 0; i < gsize; i++) g[i] = x.g[i];
}

#if 0
ostream& operator << (ostream& os, const Fdouble& o)
{
  long i;

  os << "{" << o.v;
  if (o.g!=NULL) 
  {
    os << " [ ";
    for (i = 0; i < o.gsize; i++) os << o.g[i] << " ";
    os << "]";
  }
  os << "}";
  return os;
}
#endif

Fdouble operator+ (const double& a, const Fdouble& b) 
{
  long i;

  Fdouble c(a + b.v);
  c.alloc_g(b.gsize);
  for (i = 0; i < b.gsize; i++) c.g[i] = b.g[i];
  return c;
}

Fdouble operator+ (const Fdouble& a,const double& b) 
{
  Fdouble c(a.v+b);
  c.alloc_g(a.gsize);
  for (long i=0;i<a.gsize;i++) c.g[i]=a.g[i];
  return c;
}

Fdouble operator+ (const Fdouble& a, const Fdouble& b) 
{
  long i;

  if (a.gsize==0) return a.v+b;
  if (b.gsize==0) return a+b.v;
  Fdouble c(a.v + b.v);
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] + b.g[i];
  return c;
}

Fdouble operator- (const double& a, const Fdouble& b) 
{
  long i;

  Fdouble c(a-b.v);
  c.alloc_g(b.gsize);
  for (i = 0; i < b.gsize; i++) c.g[i] = -b.g[i];
  return c;
}

Fdouble operator- (const Fdouble& a,const double& b) 
{
  long i;

  Fdouble c(a.v-b);
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i];
  return c;
}

Fdouble operator- (const Fdouble& a, const Fdouble& b) 
{
  long i;

  if (a.gsize==0) return a.v-b;
  if (b.gsize==0) return a-b.v;
  Fdouble c(a.v-b.v);
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] - b.g[i];

  return c;
}

Fdouble operator* (const double& a, const Fdouble& b) 
{
  long i;

  Fdouble c(a*b.v);
  c.alloc_g(b.gsize);
  for (i = 0; i < b.gsize; i++) c.g[i] = b.g[i] * a;
  return c;
}

Fdouble operator* (const Fdouble& a, const double& b) 
{
  long i;

  Fdouble c(a.v*b);
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] * b;
  return c;
}

Fdouble operator* (const Fdouble& a, const Fdouble& b) 
{
  long i;

  if (a.gsize==0) return a.v * b;
  if (b.gsize==0) return a * b.v;

  Fdouble c(a.v*b.v);
  c.alloc_g(a.gsize);
  
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] * b.v+b.g[i] * a.v;
  return c;
}

Fdouble operator/ (const double& a, const Fdouble& b) 
{
  long i;

  Fdouble c(a / b.v);
  double tmp(-c.v / b.v);
  c.alloc_g(b.gsize);
  for (i = 0; i < b.gsize; i++) c.g[i] = tmp * b.g[i];
  return c;
}

Fdouble operator/ (const Fdouble& a,const double& b) 
{
  long i;

  Fdouble c(a.v/b);
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = (a.g[i]) / b;
  return c;
}

Fdouble operator/ (const Fdouble& a, const Fdouble& b) 
{
  long i;

  if (a.gsize==0) return a.v / b;
  if (b.gsize==0) return a / b.v;

  Fdouble c(a.v/b.v);

  c.alloc_g(a.gsize);

  for (i = 0; i < a.gsize; i++) c.g[i] = (a.g[i] - c.v * b.g[i]) / b.v;
  return c;
}

Fdouble pow (const double& a, const Fdouble& b) 
{
  long i;

  Fdouble c(pow(a,b.v));
  double tmp(c.v * log(a));
  c.alloc_g(b.gsize);
  for (i = 0; i < b.gsize; i++) c.g[i] = tmp * b.g[i];
  return c;
}

Fdouble pow (const Fdouble& a,const double& b) 
{
  long i;

  Fdouble c(pow(a.v,b));
  double tmp(b*pow(a.v,b-1));
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = tmp * a.g[i];
  return c;
}

Fdouble pow (const Fdouble& a, const Fdouble& b) 
{
  long i;

  if (a.gsize==0) return pow(a.v,b);
  if (b.gsize==0) return pow(a,b.v);

  Fdouble c(pow(a.v,b.v));
  double tmp(b.v*pow(a.v,b.v-1)),tmp1(c.v*log(a.v));
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = tmp * a.g[i] + tmp1 * b.g[i];
  return c;
}

//***********************************************************************
// unary operators
//*******************************************

Fdouble operator+ (const Fdouble& a) 
{
  long i;

  Fdouble c(a.v);
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i];
  return c;
}


Fdouble operator- (const Fdouble& a) 
{
  long i;

  Fdouble c(-a.v);
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = -a.g[i];
  return c;
}

//***********************************************************************
// non-linear operators
//*******************************************

Fdouble pow (const Fdouble& a, long b) 
{
  long i;

  Fdouble c(pow(a.v,(double)b));
  c.alloc_g(a.gsize);
  double tmp(double(b) * pow(a.v, (double)b-1));
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] * tmp;
  return c;
}

Fdouble sqr (const Fdouble& a) 
{
  long i;

  Fdouble c(a.v * a.v);
  c.alloc_g(a.gsize);
  double tmp(2.0 * a.v);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] * tmp;
  return c;
}

Fdouble exp (const Fdouble& a) 
{
  long i;

  Fdouble c(exp(a.v));
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] * c.v;
  return c;
}

Fdouble log (const Fdouble& a) 
{
  long i;

  Fdouble c(log(a.v));
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] / a.v;
  return c;
}

Fdouble log10 (const Fdouble& a)
{
  long i;

  Fdouble c(log10(a.v));
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] / a.v;
  return c;
}

Fdouble sqrt (const Fdouble& a) 
{
  long i;

  Fdouble c(sqrt(a.v));
  double tmp(c.v*2.0);
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] / tmp;
  return c;
}


//***********************************************************************
// trigonometry operators
//*******************************************

Fdouble sin (const Fdouble& a) 
{
  long i;

  Fdouble c(sin(a.v));
  double tmp(cos(a.v));
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] * tmp;
  return c;
}

Fdouble cos (const Fdouble& a) 
{
  long i;

  Fdouble c(cos(a.v));
  double tmp(-sin(a.v));
  c.alloc_g(a.gsize);
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] * tmp;
  return c;
}

Fdouble tan (const Fdouble& a) 
{
  long i;

  Fdouble c(tan(a.v));
  c.alloc_g(a.gsize);
  double tmp(1.0 + c.v * c.v);
  for (i = 0; i < a.gsize; i++)  c.g[i] = a.g[i] * tmp;
  return c;
}

Fdouble asin (const Fdouble& a) 
{
  long i;

  Fdouble c(asin(a.v));
  c.alloc_g(a.gsize);
  double tmp(1.0 / sqrt(1.0 - a.v * a.v));
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] * tmp;
  return c;
}

Fdouble acos (const Fdouble& a) 
{
  long i;

  Fdouble c(acos(a.v));
  c.alloc_g(a.gsize); 
  double tmp(-1.0 / sqrt(1.0 - a.v * a.v));   
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] * tmp;
  return c;
}

Fdouble atan (const Fdouble& a) 
{
  long i;

  Fdouble c(atan(a.v));
  c.alloc_g(a.gsize);
  double tmp(1.0 / (1.0 + a.v * a.v));
  for (i = 0; i < a.gsize; i++) c.g[i] = a.g[i] * tmp;
  return c;
}


//***********************************************************************
// compound assignment operators
//*******************************************

Fdouble& Fdouble::operator += (const Fdouble& x) 
{
  *this = (*this)+x;
  return *this;
}

Fdouble& Fdouble::operator -= (const Fdouble& x) 
{
  *this = *this-x;
  return *this;
}

Fdouble& Fdouble::operator *= (const Fdouble& x) 
{
  *this = *this*x;
  return *this;
}

Fdouble& Fdouble::operator /= (const Fdouble& x) 
{
  *this = *this/x;
  return *this;
}

Fdouble& Fdouble::operator += (const double& x) 
{
  *this = (*this)+x;
  return *this;
}

Fdouble& Fdouble::operator -= (const double& x) 
{
  *this = *this-x;
  return *this;
}

Fdouble& Fdouble::operator *= (const double& x) 
{
  *this = *this*x;
  return *this;
}

Fdouble& Fdouble::operator /= (const double& x) 
{
  *this = *this/x;
  return *this;
}

//***********************************************************************
// logical operators
//*******************************************

bool operator == (const Fdouble &a, const Fdouble &b)
{
  return (a.v==b.v);
}

bool operator == (const Fdouble &a, const double &b)
{
  return (a.v==b);
}

bool operator == (const double &a, const Fdouble &b)
{
  return (a==b.v);
}

bool operator != (const Fdouble &a, const Fdouble &b)
{
  return (a.v!=b.v);
}

bool operator != (const Fdouble &a, const double &b)
{
  return (a.v!=b);
}

bool operator != (const double &a, const Fdouble &b)
{
  return (a!=b.v);
}

bool operator > (const Fdouble &a, const Fdouble &b)
{
  return (a.v>b.v);
}

bool operator > (const Fdouble &a, const double &b)
{
  return (a.v>b);
}

bool operator > (const double &a, const Fdouble &b)
{
  return (a>b.v);
}

bool operator >= (const Fdouble &a, const Fdouble &b)
{
  return (a.v>=b.v);
}

bool operator >= (const Fdouble &a, const double &b)
{
  return (a.v>=b);
}

bool operator >= (const double &a, const Fdouble &b)
{
  return (a>=b.v);
}

bool operator < (const Fdouble &a, const Fdouble &b)
{
  return (a.v<b.v);
}

bool operator < (const Fdouble &a, const double &b)
{
  return (a.v<b);
}

bool operator < (const double &a, const Fdouble &b)
{
  return (a<b.v);
}

bool operator <= (const Fdouble &a, const Fdouble &b)
{
  return (a.v<=b.v);
}

bool operator <= (const Fdouble &a, const double &b)
{
  return (a.v<=b);
}

bool operator <= (const double &a, const Fdouble &b)
{
  return (a<=b.v);
}
