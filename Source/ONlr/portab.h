/************************************************************************
*  $Id: Portab.h		Spracherweiterungen, Maschinenabhaengigkeiten
*
*  Version 1.0	17.05.89	Dirk Husung
*  Letzte Aenderung:		Fri 15-Oct-1993 15:01:18
*************************************************************************/

#ifndef __PORTAB__
#define __PORTAB__

#include <stdlib.h>
#include "Onlr.h" // WAH

#if defined (M_I86) && !defined (__ZTC__)
#define __MSC__
#endif

#if defined (__MSC__) || (defined (__BORLANDC__) && !defined (__OS2__))
#define __ANSI__
#ifndef __STDC__
#define __STDC__ 1
#endif

#define __16BIT__

#define __LOWBYTEFIRST__
#endif

#if defined (__ZTC__)
#define __ANSI__
#ifndef __STDC__
#define __STDC__
#endif
#define __16BIT__
#define __LOWBYTEFIRST__
#define __ASSEMBLER__
#endif

#if defined (__BORLANDC__) && defined (__OS2__)
#define __ANSI__
#ifndef __STDC__
#define __STDC__ 1
#endif
#define __32BIT__
#define __LOWBYTEFIRST__
#endif

#if defined (__IBMC__)			/* icc auf PC			*/
/*	__ANSI__	   predefined	*/
/*	__STDC__	   predefined	*/
/*	__32BIT__	   predefined	*/
#define __LOWBYTEFIRST__
#endif

#if defined (__I386__) && defined (__GNUC__)
#define __ANSI__			/* gcc auf PC			*/
/*	__STDC__	   predefined	*/
#ifndef __32BIT__
#define __32BIT__
#endif
#define __LOWBYTEFIRST__
#endif

#if defined (_AIX)			/* gcc, xlc, xlC auf IBM RS6000	*/
#ifndef __ANSI__
#define __ANSI__
#endif
/*	__STDC__	   predefined	*/
#define __32BIT__
#define __HIGHBYTEFIRST__
#endif

#if defined (__hppa)			/* gcc, c89 auf HP-PA           */
#ifndef __ANSI__
#define __ANSI__
#endif
#ifndef __STDC__
#define __STDC__
#endif
#define __32BIT__
#define __HIGHBYTEFIRST__
#endif

#if defined (sparc)			/* gcc, acc, cc, CC auf SUN4    */
#ifdef __GNUC__
#define __ANSI__
/*	__STDC__	   predefined	*/
#endif
#ifdef __ACC__
#define __ANSI__
#endif
#ifdef __cplusplus
#ifndef __ANSI__
#define __ANSI__
#endif
#endif
#define __32BIT__
#define __HIGHBYTEFIRST__
#endif

#if defined (mc68000)			/* gcc, cc auf SUN3             */
#ifdef __GNUC__
#define __ANSI__
/*	__STDC__	   predefined	*/
#endif
#define __32BIT__
#define __HIGHBYTEFIRST__
#endif

/************************************************************************
*  Insert settings for new compilers / machines here!
*  You must define either __HIGHBYTEFIRST__ for big endian machines
*  or __LOWBYTEFIRST__ for little endian machines.
*  Additional defines are:
*  __32BIT__ if your system word length is 32 bit or
*  __16BIT__ if your system word length is 16 bit
*  __ANSI__  if your compiler supports the ANSI keyword volatile
*  __STDC__  if your compiler supports the library function memmove() with
*            overlapping memory fields
*************************************************************************/

// WAH 9/26/00
#define __LOWBYTEFIRST__
#define __ANSI__
#define __32BIT__
// WAH End

#if !defined (__HIGHBYTEFIRST__) && !defined (__LOWBYTEFIRST__)
... Sorry, your compiler is not supported yet!
#endif

#if defined (__STDC__) || defined (__ANSI__) || defined (__cplusplus)
#define ARGS(parameters)	parameters
#define NOARGS			VOID
#else
#define ARGS(parameters)	()
#define NOARGS
#endif

#if defined (__DOS__) || defined (__OS2__)
#define __NOCASE__			/* Gross- und Kleinschreibung
					   gleichbedeutend bei Datei-
					   namen			*/
#endif

/************************************************************************
*  Konstantendefinitionen
*************************************************************************/

#define TRUE		1
#define FALSE		0

#define SUCCESS 	0
#define FAILURE 	(-1)

#if defined (__LOWBYTEFIRST__)

#define LO		0
#define HI		1

#define D0OF2		0
#define D1OF2		1

#define D0OF4		0
#define D1OF4		1
#define D2OF4		2
#define D3OF4		3

#define D0OF8		0
#define D1OF8		1
#define D2OF8		2
#define D3OF8		3
#define D4OF8		4
#define D5OF8		5
#define D6OF8		6
#define D7OF8		7

#elif defined (__HIGHBYTEFIRST__)

#define LO		1
#define HI		0

#define D0OF2		1
#define D1OF2		0

#define D0OF4		3
#define D1OF4		2
#define D2OF4		1
#define D3OF4		0

#define D0OF8		7
#define D1OF8		6
#define D2OF8		5
#define D3OF8		4
#define D4OF8		3
#define D5OF8		2
#define D6OF8		1
#define D7OF8		0

#endif /* !__LOWBYTEFIRST__ && !__HIGHBYTEFIRST__ */

/************************************************************************
*  Typdefinitionen
*************************************************************************/

#if !defined (OS2_INCLUDED)

#if defined (__16BIT__)

#define NEAR		near
#define FAR		far

#elif defined (__32BIT__)

#define NEAR
#define FAR

#endif /* !__16BIT__ && !__32BIT__ */

#define VOID		void

#define INT		int		/* 16 bzw. 32 Bits		*/
#define UNSIGNED	unsigned	/* 16 bzw. 32 Bits		*/

typedef char		CHAR;		/*  8 bits			*/
typedef unsigned char	UCHAR;		/*  8 bits			*/
typedef short		SHORT;		/* 16 bits			*/
typedef unsigned short	USHORT;		/* 16 bits			*/
typedef unsigned short	CARDINAL;	/* 16 bits			*/
typedef long		LONG;		/* 32 bits			*/
typedef unsigned long	ULONG;		/* 32 bits			*/

typedef unsigned char	BOOL;
typedef char *		STRING;

typedef VOID	FAR *	PVOID;
typedef CHAR	FAR *	PCHAR;
typedef UCHAR	FAR *	PUCHAR;
typedef SHORT	FAR *	PSHORT;
typedef USHORT	FAR *	PUSHORT;
typedef INT	FAR *	PINT;
typedef LONG	FAR *	PLONG;
typedef ULONG	FAR *	PULONG;
#endif /* !OS2_INCLUDED */

#if defined (__ANSI__)
#define VOLATILE	volatile
#else
#define VOLATILE
#endif

typedef unsigned	HANDLE;
typedef HANDLE	FAR *	PHANDLE;

#define SIZE		size_t
typedef SIZE	FAR *	PSIZE;

#define FLOAT		float
#define DOUBLE		double
#if defined (__ANSI__) || defined (__cplusplus)
typedef long double	EXTENDED;
#endif

typedef FLOAT	FAR *	PFLOAT;
typedef DOUBLE	FAR *	PDOUBLE;
#if defined (__ANSI__) || defined (__cplusplus)
typedef EXTENDED FAR *	PEXTENDED;
#endif

#if !defined (__GNUC__) || !defined (_OS2EMX_H)
typedef PVOID	FAR *	PPVOID;
#endif
typedef PCHAR	FAR *	PPCHAR;
typedef PUCHAR	FAR *	PPUCHAR;
typedef PSHORT	FAR *	PPSHORT;
typedef PUSHORT FAR *	PPUSHORT;
typedef PLONG	FAR *	PPLONG;
typedef PULONG	FAR *	PPULONG;

/************************************************************************
*  Verschiedenes
*************************************************************************/

#if !defined (NULL)
#if defined (__16BIT__) && \
    defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
#	define	NULL	0
#else
#	define	NULL	0L
#endif
#endif

#if defined (__STDC__)

#define MoveFarLeft(pDest, pSrc, Count, Type) \
	memmove ((pDest), (pSrc), (Count) * sizeof (Type))
#define MoveFarRight(pDest, pSrc, Count, Type) \
	memmove ((pDest), (pSrc), (Count) * sizeof (Type))
#define	MoveLeft(pType,	Count, Type) \
	memmove	((pType), (pType)+1, (Count) * sizeof (Type))
#define	MoveRight(pType, Count,	Type) \
	memmove	((pType)+1, (pType), (Count) * sizeof (Type))
#else

#define	MoveFarLeft(pDest, pSrc, Count, Type) {\
  register INT	  Num  = Count;\
  register Type	* Src  = (Type *) (pSrc);\
  register Type	* Dest = (Type *) (pDest);\
  while	(Num--)	*Dest++	= *Src++;\
}

#define	MoveFarRight(pDest, pSrc, Count, Type) {\
  register INT	  Num  = Count;\
  register Type	* Src  = (Type *) (pSrc)  + Num;\
  register Type	* Dest = (Type *) (pDest) + Num;\
  while	(Num--)	*--Dest	= *--Src;\
}

#define	MoveLeft(pType,	Count, Type) {\
  register INT	  Num  = Count;\
  register Type	* Src  = pType;\
  register Type	* Dest = pType;\
  while	(Num--)	*Dest++	= *++Src;\
}

#define	MoveRight(pType, Count,	Type) {\
  register INT	  Num  = Count;\
  register Type	* Src  = (pType) + Num;\
  register Type	* Dest = (pType) + Num;\
  while	(Num--)	*Dest--	= *--Src;\
}

#endif

#define raise		goto 		/* Sprung zu Ausnahmebehandlung	*/
#define loop		for (;;)	/* Unendlich-Schleife		*/
#define min(a,b)        (((a) < (b)) ? (a) : (b))
#define max(a,b)        (((a) > (b)) ? (a) : (b))
#define dimof(array)	(sizeof(array) / sizeof(*(array)))

#if defined (__BORLANDC__)
#define _asm		asm
#endif

#endif /* !__PORTAB__ */
