/*****************************************************************************
*  $Id: LiMem.c 		Intervall-Langzahlarithmetik
*				Speicherverwaltung
*
*  Version 1.0	25.07.90	Olaf Knueppel
*  Letzte Aenderung:		Sun 31-May-1992 17:26:02
*****************************************************************************/

#include "Portab.h"

#if defined (__ANSI__)
#include <string.h>
#else
#include <memory.h>
#include <malloc.h>
#endif

#include "Li.h"
#include "DynMem.h"

LIREAL FAR CALL LiNew (USHORT Prec, register USHORT Size)
 /***********************************************************************
  *  Funktion : Speicherallokierung fuer eine Intervall-Langzahl.
  *  Eingaben : Prec	: Genauigkeit.
  *		Size	: Speicherbedarf in Bytes.
  *  Ergebnis : Zeiger auf Intervall-Langzahl.
  *  Info     : Falls nicht genug Speicher zur Verfuegung steht, wird
  *		(*MemErrorHandler) () aufgerufen.
  */
{
  register PPVOID Memory;

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
  LiInfo ((LIREAL) Memory) = Prec;

  return (LIREAL) Memory;
} /* LiNew */
