
#include "ival.h"
#include "func.h"
#include "error.h"

REAL fVal(REAL& t)
{                              // Function f
  REAL w;
  double pi=3.1415926535897931086244E0;
	w = (Sin(pi*t) - 0.35*t);
  return w;
}

INTERVAL deriv(INTERVAL& t)
{                              // Derivative function f']
  INTERVAL w;
  double pi=3.1415926535897931086244E0;
	w = (pi*Cos(pi*t) - 0.35);
  return w;
}

int Krawczyk(INTERVAL& s){ 

	INTERVAL K;
	INTERVAL z;
  REAL mid,midr;
	INTERVAL Der;
	REAL epsilon = 1.e-10;

	mid = Mid(s);
	Der = deriv(s);
	midr = Mid(Der);

  if((midr == 0) && (midr + epsilon <= Sup(Der)))
    midr = midr + epsilon;

	K = mid;
	K = K - fVal(mid)/midr;
	K = K + (1.0 - Der/midr)*(s-mid);
	REAL normTest = Abs((1.0 - Der/midr));
	if(Intersection(z,K,s)) // if they intersect there may be a zero
  { 
		if((Inf(K) > Inf(s)) && (Sup(K) < Sup(s)))
    {
			// There is a unique zero
			return 1;
		}
		else
    {
			// Possible multiple zeros; interval will be bisected
			return 2;
		}
	}

	// There is no zero
	return 0;
}

bool iSimplifiedNewton(INTERVAL& y, REAL& theta)
{
  INTERVAL z;
  REAL mid;
  REAL midr;
  REAL theta_old;
  INTERVAL Der;
  INT nZeros;
  INTERVAL y1,y2;
  bool zeroDer;
  REAL inf,sup;
  bool bMidIsRoot = false;
  double epsilon = 1.e-12;
  
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
  Der = deriv(y);
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
  inf = Inf(y);
  sup = Sup(y);
  
  if (fVal(mid) == 0)
  {
#if 0
    ATLTRACE("zero_list[%d] = %e\n", cZero, mid);
#endif
    vZero[cZero++] = mid;
    bMidIsRoot = true;
  }
  
  if(fVal(inf) == 0){
#if 0
    ATLTRACE("zero_list[%d] = %e\n", cZero, inf);
#endif
    vZero[cZero++] = inf;
    y = Hull(inf+epsilon,sup);
  }
  else if(fVal(sup) == 0){
#if 0
    ATLTRACE("zero_list[%d] = %e\n", cZero, sup);
#endif
    vZero[cZero++] = sup;
    y = Hull(inf,sup-epsilon);
  }
  nZeros = Krawczyk(y);
  if ((nZeros==1) && !(midr==0.0)) 
  {
    do 
    {
      theta_old = theta;
      theta = theta_old - fVal(theta_old)/midr;
    } while (fabs(theta-theta_old)>epsilon);

    // add zero to root list
#if 0
    ATLTRACE("zero_list[%d] = %e\n", cZero, theta);
#endif
    vZero[cZero++] = theta;
    return true;
  }
  else if(nZeros>1 || (midr==0.0))
  {
    // bisect y into y1 and y2
    if (bMidIsRoot)
    {
      y1 = Hull (Inf (y), mid-epsilon);
      y2 = Hull(mid+epsilon, Sup(y));
    }
    else
    {
      y1 = Hull (Inf (y), mid);
      y2 = Hull(mid, Sup(y));
    }
    bool bRet = false;
    // execute both branches because both could contain roots.
    // in this case, we are interested in finding all roots, not just the first one.
    if( (nZeros=Krawczyk(y1))  && iSimplifiedNewton(y1, theta))
      bRet = true;
    
    if((nZeros=Krawczyk(y2)) && iSimplifiedNewton(y2, theta))
      bRet = true;
    
    return bRet;
  }
  else 
    return false;	// No zeros
}

