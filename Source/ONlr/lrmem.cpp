/************************************************************************
*  $Id:	LrMem.c			Langzahlarithmetik, Speicherverwaltung
*
*  Version 1.0	10.10.89	Dirk Husung
*  Letzte Aenderung:		Thu 14-May-1992 17:28:55
************************************************************************/

#include "Portab.h"

#if defined (__ANSI__)
#include <string.h>
#else
#include <memory.h>
#include <malloc.h>
#endif

#include "Lr.h"
#include "DynMem.h"

/************************************************************************
* Implementierung globaler Funktionen
************************************************************************/

VOID FAR CALL LrInit (VOID)
 /***********************************************************************
  *  Funktion :	Initialisierung	bei Programmstart.
  *  Ergebnis :	---
  */
{
  static USHORT IsInitialized = FALSE;

  if (IsInitialized++) return;

  MemInit ();
} /* LrInit */

VOID FAR CALL LrReset (VOID)
 /***********************************************************************
  *  Funktion :	Reinitialisierung.
  *  Ergebnis :	---
  */
{
  MemReset ();
} /* LrReset */

LREAL FAR CALL LrNew (SIZE Digits, SIZE Size)
{
  PPVOID Memory;

  if (Size <= MEM_MAXSIZE
      && (Memory = (PPVOID) *((PPVOID) ((PCHAR) MemStore + Size))) != NULL) {
    *((PPVOID) ((PCHAR) MemStore + Size)) = *Memory;
  }
  else if ((Memory = (PPVOID) malloc (Size)) == NULL) {
    INT ErrorClass = 0;

    do {
      (*MemErrorHandler) (ErrorClass++);
    } while ((Memory = (PPVOID) malloc (Size)) == NULL);
  }
  LrSetPosDigits ((LREAL) Memory, Digits);

  return (LREAL) Memory;
} /* LrNew */
