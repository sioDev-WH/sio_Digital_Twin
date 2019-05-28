/************************************************************************
*  LSS.C (Solvers for Linear Systems)
*
*  Version:                     1.5
*  Date:                        11/3/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)LSS.C 1.5 93/11/03 OK";

//#include "stdafx.h"
#include "lss.h"
#include "util.h"
#include "const.h"

INTERVAL_VECTOR LSS (MATRIX & A, VECTOR & b, INT & info)
{
  INT dim = Dimension (b);
  MATRIX R (dim, dim);
  VECTOR xs (dim);
  INTERVAL_VECTOR x (dim), y (dim), z (dim);
  INTERVAL_VECTOR Inflat (dim);
  INTERVAL_MATRIX C(dim,dim);
  INT k, done;
  INTERVAL eps (0.9,1.1);

  Initialize(Inflat, SymHull (Machine::MinPositive));
  
  R = Inverse (A);
  xs = R * b;

  z = R * (b - MulBounds (A, xs));
  
  x = z;
  
  C = Id(dim) - MulBounds (R, A);

  k = 0;
  do {
    y = eps * x + Inflat; // expansion
    x = z + C * y;
    done = (x < y);
    k++;
  } while (!done && k < 10); 

  info = done;              // 1, if inclusion was possible
  return (xs + x);
}

INTERVAL_VECTOR ILSS (INTERVAL_MATRIX & A, INTERVAL_VECTOR & b, INT & info)
{
  INT dim = Dimension (b);
  MATRIX R (dim, dim);
  VECTOR xs (dim);
  INTERVAL_VECTOR x (dim), y (dim), z (dim);
  INTERVAL_VECTOR Inflat (dim);
  INTERVAL_MATRIX C(dim,dim);
  INT k, done;
  INTERVAL eps (0.9,1.1);

  Initialize(Inflat, SymHull (Machine::MinPositive));
  
  R = Inverse (Mid (A));
  xs = R * Mid (b);

  z = R * (b - A * xs);

  x = z;
  
  C = Id(dim) - R * A;

  k = 0;
  do {
    y = eps * x + Inflat; // expansion
    x = z + C * y;
    done = (x < y);
    k++;
  } while (!done && k < 10); 

  info = done;              // 1, if inclusion was possible
  return (xs + x);
}
