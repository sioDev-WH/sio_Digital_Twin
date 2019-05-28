/************************************************************************
*  BiasIntIEEE.h (Basic Interval Arithmetic Subroutines Internals)
*
*  Version:                     1.8
*  Date:                        1/31/94
*  Author:                      D. Husung, O. Knueppel
*  Interval Representation:     INFSUP
*  Interval Implementation:     IEEE
*************************************************************************/

#ifndef __BIASINTERN__
#define __BIASINTERN__

#include "ONbias.h"  // WAH

/************************************************************************
*  User definable controls
*************************************************************************/

#define __BIASRAISEDIVIDEBYZERO__       /* if defined, division by zero aborts;
                                           otherwise, bounds containing +/-oo
                                           or NaN are computed. */
#undef  __BIASSETROUNDTONEAREST__       /* if defined, rounding mode is set to
                                           nearest after each operation */

/************************************************************************
*  Rounding mode definitions
*************************************************************************/

#if defined (__MSC__) || defined (__BORLANDC__) || defined (__ON_Machine__) \
  || (defined (__I386__) && defined (__GNUC__)) 
   /* WAH End  Added || defined (__ON_Machine__) */

/**** math coprocessor control word (80x87) ****************************/

#define MCW_EM          0x003f          /* interrupt exception masks   */
#define EM_INVALID      0x0001          /*   invalid                   */
#define EM_DENORMAL     0x0002          /*   denormal                  */
#define EM_ZERODIVIDE   0x0004          /*   zero divide               */
#define EM_OVERFLOW     0x0008          /*   overflow                  */
#define EM_UNDERFLOW    0x0010          /*   underflow                 */
#define EM_INEXACT      0x0020          /*   inexact (precision)       */

#define MCW_IC          0x1000          /* infinity control            */
#define IC_AFFINE       0x1000          /*   affine                    */
#define IC_PROJECTIVE   0x0000          /*   projective                */

#define MCW_RC          0x0c00          /*  rounding control           */
#define RC_CHOP         0x0c00          /*    chop                     */
#define RC_UP           0x0800          /*    up                       */
#define RC_DOWN         0x0400          /*    down                     */
#define RC_NEAR         0x0000          /*    near                     */

#define MCW_PC          0x0300          /*  precision control          */
#define PC_24           0x0000          /*    24 bits                  */
#define PC_53           0x0200          /*    53 bits                  */
#define PC_64           0x0300          /*    64 bits                  */

/**** math coprocessor status word (80x87) *****************************/

#define SW_INVALID      0x0001          /* invalid operation           */
#define SW_DENORMAL     0x0002          /* denormalized operand        */
#define SW_ZERODIVIDE   0x0004          /* zero divide                 */
#define SW_OVERFLOW     0x0008          /* overflow                    */
#define SW_UNDERFLOW    0x0010          /* underflow                   */
#define SW_INEXACT      0x0020          /* precision (inexact result)  */

/**** math coprocessor default control word and rounding modes (80x87) */

#define CW_DEFAULT\
        (IC_AFFINE      | RC_NEAR       | PC_64         |\
         EM_DENORMAL    | EM_OVERFLOW   | EM_UNDERFLOW  | EM_INEXACT)

#define CW_ROUND_CHOP   ((CW_DEFAULT & ~MCW_RC) | RC_CHOP)
#define CW_ROUND_UP     ((CW_DEFAULT & ~MCW_RC) | RC_UP)
#define CW_ROUND_DOWN   ((CW_DEFAULT & ~MCW_RC) | RC_DOWN)
#define CW_ROUND_NEAR   ((CW_DEFAULT & ~MCW_RC) | RC_NEAR)

extern INT _BiasCwRoundUp, _BiasCwRoundDown, _BiasCwRoundNear;

#if defined (__I386__) && defined (__GNUC__)

#define _BiasRoundUp()    asm volatile ("fldcw __BiasCwRoundUp")
#define _BiasRoundDown()  asm volatile ("fldcw __BiasCwRoundDown")
#define _BiasRoundNear()  asm volatile ("fldcw __BiasCwRoundNear")

#elif defined (__BORLANDC__) && defined (__OS2__)

#define _BiasRoundUp()    _asm {fldcw word ptr ds: _BiasCwRoundUp}
#define _BiasRoundDown()  _asm {fldcw word ptr ds: _BiasCwRoundDown}
#define _BiasRoundNear()  _asm {fldcw word ptr ds: _BiasCwRoundNear}

#elif defined (__BORLANDC__)

#define _BiasRoundUp()    _asm {fldcw word ptr ds:OFFSET _BiasCwRoundUp}
#define _BiasRoundDown()  _asm {fldcw word ptr ds:OFFSET _BiasCwRoundDown}
#define _BiasRoundNear()  _asm {fldcw word ptr ds:OFFSET _BiasCwRoundNear}

#else /* defined (__MSC__) */

#define _BiasRoundUp()    _asm {fldcw word ptr ds:OFFSET _BiasCwRoundUp}
#define _BiasRoundDown()  _asm {fldcw word ptr ds:OFFSET _BiasCwRoundDown}
#define _BiasRoundNear()  _asm {fldcw word ptr ds:OFFSET _BiasCwRoundNear}

#endif

#elif defined(_AIX) && defined(__GNUC__)

#define _BiasRoundUp()    asm volatile ("mtfsfi 7,2")
#define _BiasRoundDown()  asm volatile ("mtfsfi 7,3")
#define _BiasRoundNear()  asm volatile ("mtfsfi 7,0")

/*
 * Currently no inline code support for HP-PA. The part below is
 * an idea, how the inline code may look like, but it doesn't work
 * when using optimization. Probably the "g" must be changed into
 * something different!?!

#elif defined(__hppa) && defined(__GNUC__)

extern INT _BiasCwRoundUp, _BiasCwRoundDown, _BiasCwRoundNear;

#define _BiasRoundUp()    asm volatile ("fldws %0,%%fr0L" : : "g" (_BiasCwRoundUp))
#define _BiasRoundDown()  asm volatile ("fldws %0,%%fr0L" : : "g" (_BiasCwRoundDown))
#define _BiasRoundNear()  asm volatile ("fldws %0,%%fr0L" : : "g" (_BiasCwRoundNear))

*/

#elif defined(sparc) && defined(__GNUC__)

extern ULONG _BiasCwRoundUp, _BiasCwRoundDown, _BiasCwRoundNear;

#define _BiasRoundUp()    asm volatile ("ld %0,%%fsr" : : "g" (_BiasCwRoundUp))
#define _BiasRoundDown()  asm volatile ("ld %0,%%fsr" : : "g" (_BiasCwRoundDown))
#define _BiasRoundNear()  asm volatile ("ld %0,%%fsr" : : "g" (_BiasCwRoundNear))

#elif defined(mc68000) && defined(__GNUC__)

extern INT _BiasCwRoundUp, _BiasCwRoundDown, _BiasCwRoundNear;

#define _BiasRoundUp()    asm volatile ("fmovel %0,fpc" : : "g" (_BiasCwRoundUp))
#define _BiasRoundDown()  asm volatile ("fmovel %0,fpc" : : "g" (_BiasCwRoundDown))
#define _BiasRoundNear()  asm volatile ("fmovel %0,fpc" : : "g" (_BiasCwRoundNear))

#else

#define _BiasRoundUp()    BiasRoundUp()
#define _BiasRoundDown()  BiasRoundDown()
#define _BiasRoundNear()  BiasRoundNear()

#endif

ONBIAS_API VOID _BiasError(PCHAR);

/************************************************************************
*  Macros
*************************************************************************/

#if defined (__HIGHBYTEFIRST__)
#define SIGNIDX 0
#else
#define SIGNIDX (sizeof (REAL) / sizeof (ULONG) - 1)
#endif
#define SIGNBIT (1L << (8 * sizeof (ULONG) - 1))

#define Sign(r) \
        (((PULONG) & (r)) [SIGNIDX] & SIGNBIT)

#define Zero(r) \
        ((sizeof (REAL) == sizeof (ULONG) ?             \
        (((PULONG) & (r)) [SIGNIDX] & ~ SIGNBIT) :      \
        (((PULONG) & (r)) [SIGNIDX] & ~ SIGNBIT) |      \
        ((PULONG) & (r)) [1 - SIGNIDX]) == 0)

#if defined (__BIASSETROUNDTONEAREST__)
#define _SetRoundToNearest()    _BiasRoundNear ()
#else
#define _SetRoundToNearest()
#endif

#endif /* __BIASINTERN__ */

