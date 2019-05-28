/************************************************************************
*  Constants.C (Machine dependent constants)
*
*  Version:                     1.6
*  Date:                        4/23/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)Constants.C 1.6 93/04/23 OK";

//#include "stdafx.h"
#include "const.h"

// extern "C" __declspec(dllimport) double BiasNaN;

REAL Machine::Epsilon            = 0.0;
REAL Machine::MinPositive        = 0.0;
REAL Machine::PosInfinity        = 0.0;
REAL Machine::NegInfinity        = 0.0;
REAL Machine::NaN                = 0.0;

Machine MachineConstants; // constructor is called automatically

Machine::Machine ()
{
  BiasInit ();
  Machine::Epsilon            = BiasEpsilon;
  Machine::MinPositive        = BiasEta;
  Machine::PosInfinity        = BiasPosInf;
  Machine::NegInfinity        = BiasNegInf;
  Machine::NaN                = BiasNaN;
}

// The following routine is only used for reference in Interval.C and Vector.C
// in order to force the loader to bind this file into the executable code.

VOID RegisterConstants () { }
