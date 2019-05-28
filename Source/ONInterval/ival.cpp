/************************************************************************
*  Interval.C (Implementation of type INTERVAL)
*
*  Version:                     1.9
*  Date:                        10/6/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)Interval.C 1.9 93/10/06 OK";

//#include "stdafx.h"
#include "ival.h"

#if !defined (__NICEINOUT__)
ostream & operator << (ostream & os, INTERVAL & x)
{
  return os << '[' << Inf (x) << ',' << Sup(x) << ']';
}

istream & operator >> (istream & is, INTERVAL & x)
{
  REAL a, b;

  is >> a;
  is >> b;
  BiasHullRR (Bias(x), & a, & b);
  return is;
}
#endif

// The following code is only used to force Constants.C to be
// always included in the executable code.

extern VOID RegisterConstants ();

VOID RegisterInterval () { RegisterConstants (); }
