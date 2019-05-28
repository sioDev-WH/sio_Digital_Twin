#ifndef _OnStlVec_h_
#define _OnStlVec_h_



#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#ifdef free
#undef free
#endif

#include <valarray>
//#include <cmath>

using namespace std;
//using namespace math;
class Fdouble;


typedef enum OnPhysicalType
{
  OnPhysicalType_Unknown,
  OnPhysicalType_Equal,
  OnPhysicalType_Sum,
};

template <class T>
class OnStlVec : public valarray<T>
{
public:

  OnStlVec(long size)
  {
    SetSize(size);
  }

  void SetSize(long size)
  {
    resize(size);
    der.resize(size);
    old.resize(size);
    der_old.resize(size);
    ad.resize(size);
    der_ad.resize(size);
  }

public:
  valarray<T> der;
  valarray<T> old;
  valarray<T> der_old;
  valarray<Fdouble> ad;
  valarray<Fdouble> der_ad;

  virtual OnPhysicalType GetPhysicalType() { return OnPhysicalType_Unknown; }
};

#endif // _OnStlVec_h_