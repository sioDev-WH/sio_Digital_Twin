/************************************************************************
*  NiceIntervalIO.C (Implementation of nice INTERVAL input and output)
*
*  Version:                     1.5
*  Date:                        10/22/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)NiceIntervalIO.C 1.5 93/10/22 OK";

//#include "stdafx.h"
#include "Longival.h"

static LREAL  LongInfimum = NULL;
static LREAL  LongSupremum = NULL;
static LIREAL LongInterval = NULL;

// The prototype for the input/output functions
// are defined in Interval.h

ostream & operator << (ostream & os, INTERVAL & iv)
{
  REAL Infimum, Supremum;

  Infimum = Inf (iv); Supremum = Sup (iv);
  if (LongInfimum == NULL) {
    LongInfimum  = LrNewVar (6);
    LongSupremum = LrNewVar (6);
    LongInterval = LiNewTemp (6, 1);
  }
  else {
    LrSetPosDigits (LongInfimum, 6);
    LrSetPosDigits (LongSupremum, 6);
    LiInfo (LongInterval) = 6;
  }
  dtolr (LongInfimum, & Infimum); dtolr (LongSupremum, & Supremum);
  LiHull (LongInfimum, LongSupremum, LongInterval, 0);
  LiToOutput (os, LongInterval);
  return os;
}

istream & operator >> (istream & is, INTERVAL & x)
{
  CHAR sz[1024];

  is >> sz;
  x = Enclosure (sz);
  return is;
}

// The following code is only used to force LongReal.C to be
// always included in the executable code.

extern VOID RegisterLongReal ();

VOID RegisterNiceIntervalOutput () { RegisterLongReal (); }
