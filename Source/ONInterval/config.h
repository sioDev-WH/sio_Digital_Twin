/************************************************************************
*  Configuration.h (General Configuration Parameters)
*
*  Version:                     1.5
*  Date:                        1/27/94
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __CONFIG__
#define __CONFIG__

#define __PROFILVERSION__ "1.1b"

/************************************************************************
*  Definition of the REAL type (must be the same as in BIAS)
*************************************************************************/

#ifndef REAL
#define REAL DOUBLE
#define PREAL PDOUBLE
#endif

/************************************************************************
*  If the following macro is defined, a special strategy avoiding
*  copies of temporary structures is used. Due to the fact, that C++
*  only supports a single copy constructor, some restrictions occur when
*  using this strategy:
*    - expressions must not be used as reference parameters
*    - expressions or single variables must not be used as value parameters
*    - initialization without using the assignment operator must not
*      be used.
*  The above restrictions are valid for all structured types as VECTOR,
*  MATRIX, INTERVAL_VECTOR, ...
*  If any of the above cases can't be avoided, a MakePermanent(...)
*  command must be used before any use of the appropriate variable.
*  For testing purposes, the macro should be left undefined.
*************************************************************************/

/* #define __DONTCOPY__ */

/************************************************************************
*  If the following macro is defined, an index check is performed prior
*  any vector or matrix element access. This results in reduced execution
*  speed and therefore should only be used in the developement phase
* of the program.
*************************************************************************/

/* #define __INDEXCHECK__ */

#endif /* __CONFIG__ */
