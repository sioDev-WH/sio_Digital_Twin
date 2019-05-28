// includes for interval calculations
#include "IsInterval.h"
#include "ival.h"
#include "func.h"
#include "error.h"

#include <float.h>

#if 0
#ifdef _DEBUG
#include "crtdbg.h"
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)   
#endif
#endif

// TODO: the following static variables have to be moved into a class because multiple instances of the solver
// will only get one instance of these variables.
static double m_y0 = 0.0;
static double m_y1 = 0.0;
static double m_ydot0 = 0.0;
static double m_ydot1 = 0.0;
static double m_t0 = 0.0;
static double m_t1 = 0.0;
static long m_cZero = 0;
static double* m_vZero = NULL;
static double m_h = 0.0;

bool CalculateZeros(
  double y0,
  double y1,
  double ydot0,
  double ydot1,
  double t0,
  double t1,
  long& cZero,
  double* vZero)
{
  bool bRet;

  if (y0 == y1 && ydot0 == ydot1)
    return false;

  m_y0 = y0;
  m_y1 = y1;
  m_ydot0 = ydot0;
  m_ydot1 = ydot1;
  m_t0 = t0;
  m_t1 = t1;
  m_cZero = 0;
  m_vZero = vZero;
  m_h = t1-t0;
  bRet = iSimplifiedNewton(m_t0, m_t1);
  cZero = m_cZero;
  return bRet;
}

int Krawczyk(double s_inf, double s_sup)
{ 
  INTERVAL s;
	INTERVAL K;
	INTERVAL z;
  REAL mid,midr;
	INTERVAL Der;
	REAL epsilon = 1.e-10;

  s = Hull(s_inf, s_sup);
	mid = Mid(s);

	// Der = deriv(s);
  // the following 3 lines replace the original derivative over the interval
	Der = Hull(deriv(s_inf), deriv(s_sup));

  midr = Mid(Der);

  if((midr == 0) && (midr + epsilon <= Sup(Der)))
    midr = midr + epsilon;

	K = mid;
	K = K - fVal(mid)/midr;
	K = K + (1.0 - Der/midr)*(s-mid);

	REAL normTest = Abs((1.0 - Der/midr));
	if(Intersection(z,K,s)) // if they intersect there may be a zero
  { 
		if((Inf(K) > s_inf) && (Sup(K) < s_sup))
    {
			return 1;  // There is a unique zero
		}
		else
    {
			return 2;  // Possible multiple zeros; interval will be bisected
		}
	}


	// There is no zero
	return 0;
}

bool iSimplifiedNewton(double y_inf, double y_sup)
{
  INTERVAL y;
  INTERVAL z;
  REAL mid;
  REAL midr;
  REAL theta_old;
  INTERVAL Der;
  INT nZeros;
  bool zeroDer;
  double epsilon = 1.e-12;
  double theta;
  static long recursion_count = 0;
  static bool recursion_limit_exceeded = false;
  y = Hull(y_inf, y_sup);

  // The birta test problem has symmetric zeros around the theta = 0 
  // and causes problem in [0,sup] but not in [.001, sup]!!
  // The test keeps giving nZeros >1 until stack overflow due to bisections
  // of [0,sup].
  // The instability is due to the fact that we are not using inverse of derv
  // Leading K to be outside s (Krawycz > 1 case). This may be avoided if we use
  // the non-inversion version of the test see papers of Moore and Hensen.
  // problem = karlsruhe birta; 
  mid = Mid(y);
  theta = mid + epsilon;

  Der = Hull(deriv(y_inf), deriv(y_sup));
  midr = Mid(Der);
  if ( (0.0 >= Inf(Der)) && (0.0 <= Sup(Der)) ) // Is not being used now and has no significance
    zeroDer = 1;
  else
    zeroDer = 0;

  // Check if the end points are themselves zero of the function 
  // (e.g., in case of Birta [0,3] 0.0 is a zero causing infinite loop in the test)
  // If Inf(s) is the zero then return it; otherwise add the sup(s) to the list and exclude it
  // from the interval and try to find another zero in the interval -- if any return it; 
  // however, if none then return Sup(s) 
  
  // see if the inf is a zero
  if (fVal(y_inf) == 0)
  {
    m_vZero[m_cZero++] = y_inf;
    y = Hull(y_inf+epsilon,y_sup);
  }
  else
  {
    // see if the sup is a zero
    if (fVal(y_sup) == 0)
    {
      m_vZero[m_cZero++] = y_sup;
      y = Hull(y_inf,y_sup-epsilon);
    }
  }

  nZeros = Krawczyk(Inf(y), Sup(y));


  // Added June 16, 2001 by KB / WH to fix missing events
  // test for simple case of zero crossing (one value negative, one positive)
  // if Krawczyk returns 0, and this simple test returns true; set nZeros = 2
  if ( nZeros == 0 && ((fVal(y_inf) <= 0) != (fVal(y_sup) <= 0)) )
    nZeros = 2;

  if ((nZeros==1) && !(midr==0.0)) 
  {
    long counter = 0;
    do 
    {
      counter++;
      theta_old = theta;
      theta = theta_old - fVal(theta_old)/midr;

      // KAB 
      // TODO: determine how to handle NaN
      if ( _isnan(theta) || theta > 1.0e10)
      {
        // do a linear simple interpolation for now
        theta = theta_old = (m_y0 / (m_y0 + m_y1)) * m_t0 + (m_y1 / (m_y0 + m_y1)) * m_t1; 
      }

    } while (fabs(theta-theta_old)>epsilon && counter < 100);

    // add zero to root list
    m_vZero[m_cZero++] = theta;
    return true;
  }
  else if(nZeros>1 || (midr==0.0))
  {
    // bisect y into y1 and y2
    bool bRet = false;
    // execute both branches because both could contain roots.
    // in this case, we are interested in finding all roots, not just the first one.
    if (fabs(Inf(y) - mid) < epsilon)
    {
      m_vZero[m_cZero++] = mid;
      bRet = true;
    }
    else
    {
      if( (nZeros=Krawczyk(Inf(y), mid))  && iSimplifiedNewton(Inf(y), mid))
        bRet = true;
  
      if((nZeros=Krawczyk(mid, Sup(y))) && iSimplifiedNewton(mid, Sup(y)))
        bRet = true;
    }
    
    return bRet;
  }
  else 
    return false;	// No zeros
}

double fVal(double tau)
{
  if (m_t1 == m_t0)
    return m_y1;
  else
  {
	  double theta = (tau - m_t0) / m_h;
	  return (1-theta)*m_y0+theta*m_y1
			   +theta*(theta-1)*((1-2*theta)*(m_y1-m_y0)+(theta-1)*m_h*m_ydot0+theta*m_h*m_ydot1);
  }
}

double deriv(double tau)
{
  
  double theta;

  if (m_t1 == m_t0)
    return m_ydot1;
  else
  {
    if(fabs(m_ydot0)>1e10 || fabs(m_ydot1)>1e10)
      theta=0.0;;
	    theta = (tau - m_t0) / m_h;
	  return 6*theta*(1.0-theta)*(m_y1-m_y0)/m_h 
			  + (3.0*theta-1)*(theta-1)*m_ydot0 
			  + theta*(3.0*theta -2.0)*m_ydot1;
  }
}
