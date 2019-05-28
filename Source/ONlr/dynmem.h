/************************************************************************
*  $Id:DynMem.h			Speicherallokierung /-freigabe
*
*  Version 1.0	09.06.90	Dirk Husung
*  Version 1.1	05.12.90	Dirk Husung
*	ueberarbeitet
*  Letzte Aenderung:		Sun 28-Feb-1993 09:21:39
*************************************************************************/

#ifndef __DYNMEM__
#define __DYNMEM__

#include "Onlr.h" // WAH

#if defined (__cplusplus)
extern "C" {
#endif

#define __MEMTEST__	     /* Registrierung des allokierten Speichers	*/

/************************************************************************
*  Konstanten- und Typ-Definitionen, Variablen-Deklarationen
*************************************************************************/

#define MEM_MAXSIZE	1024

extern	PVOID MemStore	[(MEM_MAXSIZE >> 2) + 1];

typedef VOID MEM_ERRORHANDLER ARGS((INT));

typedef MEM_ERRORHANDLER FAR * PMEM_ERRORHANDLER;

#if defined (__MEMTEST__)
extern	ULONG	ulMemUsed;
#endif

/************************************************************************
*  Prototypen der Funktionen
*************************************************************************/

extern PMEM_ERRORHANDLER MemErrorHandler;
  /**********************************************************************
  *  (*MemErrorHandler) () wird aufgerufen, wenn der Speicher erschoepft ist.
  */

extern VOID MemInit ARGS ((VOID));
  /**********************************************************************
  *  Funktion : Initialisierung bei Programmstart.
  *  Ergebnis : ---
  */

extern VOID MemReset ARGS ((VOID));
  /**********************************************************************
  *  Funktion : Reinitialisierung.
  *  Ergebnis : ---
  */

extern VOID MemRelease ARGS ((VOID));
  /**********************************************************************
  *  Funktion : Gibt den internen Speicher-Puffer frei.
  *  Ergebnis : ---
  */

extern PVOID ONLR_API _MemNew ARGS ((SIZE Size));
  /**********************************************************************
  *  Funktion : Allokiert Size Bytes Speicher.
  *  Annahmen : Size ist ohne Rest durch 4 teilbar.
  *  Eingaben : Size	: Groesse des Speicherbereichs.
  *  Ergebnis : Zeiger auf Speicherbereich.
  *  Info     : Falls nicht genug Speicher zur Verfuegung steht, wird
  *		(*MemErrorHandler) () aufgerufen.
  */

extern VOID ONLR_API _MemDelete ARGS ((PVOID Memory, SIZE Size));
  /**********************************************************************
  *  Funktion : Gibt einen mit _MemNew() allokierten Speicherbereich frei.
  *  Annahmen : Size ist ohne Rest durch 4 teilbar.
  *  Eingaben : Memory	: Zeiger auf freizugebenden Speicherbereich.
  *		Size	: Groesse des Speicherbereichs.
  *  Ergebnis : ---
  */

extern PVOID _MemResize ARGS ((PVOID Memory, SIZE OldSize, SIZE NewSize));
  /**********************************************************************
  *  Funktion : Aendert die Groesse eines mit _MemNew() allokierten
  *		Speicherbereichs.
  *  Annahmen : OldSize und Size sind ohne Rest durch 4 teilbar.
  *  Eingaben : Memory	: Zeiger auf zu aendernden Speicherbereich.
  *		OldSize : urspr. Groesse des Speicherbereichs.
  *		NewSize : neue Groesse des Speicherbereichs.
  *  Ergebnis : Zeiger auf Speicherbereich.
  *  Info     : Falls nicht genug Speicher zur Verfuegung steht, wird
  *		(*MemErrorHandler) () aufgerufen.
  */

#define MemNew(Size) \
	_MemNew ((Size) == 0 ? 4 : ((Size) + 3) & ~3)
  /**********************************************************************
  *  Funktion : Allokiert Size Bytes Speicher.
  *  Ergebnis : Zeiger auf Speicherbereich.
  *  Eingaben : Size	: Groesse des Speicherbereichs.
  *  Info     : Falls nicht genug Speicher zur Verfuegung steht, wird
  *		(*MemErrorHandler) () aufgerufen.
  */

#define MemDelete(Memory, Size) \
	_MemDelete (Memory, (Size) == 0 ? 4 : ((Size) + 3) & ~3)
  /**********************************************************************
  *  Funktion : Gibt einen mit MemNew() allokierten Speicherbereich frei.
  *  Eingaben : Memory	: Zeiger auf freizugebenden Speicherbereich.
  *		Size	: Groesse des Speicherbereichs.
  *  Ergebnis : ---
  */

#define MemResize(Memory, OldSize, NewSize) \
	_MemResize (Memory, ((OldSize) + 3) & ~3, ((NewSize) + 3) & ~3)
  /**********************************************************************
  *  Funktion : Aendert die Groesse eines mit MemNew() allokierten
  *		Speicherbereichs.
  *  Eingaben : Memory	: Zeiger auf zu aendernden Speicherbereich.
  *		OldSize : urspr. Groesse des Speicherbereichs.
  *		NewSize : neue Groesse des Speicherbereichs.
  *  Ergebnis : Zeiger auf Speicherbereich.
  *  Info     : Falls nicht genug Speicher zur Verfuegung steht, wird
  *		(*MemErrorHandler) () aufgerufen.
  */

extern PVOID MemExtend ARGS ((PVOID Memory, PSIZE Size));
  /**********************************************************************
  *  Funktion : Verdoppelt die Groesse eines mit _MemNew() oder MemNew()
  *		allokierten Speicherbereichs.
  *  Eingaben : Memory	: Zeiger auf zu erweiternden Speicherbereich.
  *		Size	: urspr. Groesse des Speicherbereichs.
  *  Ausgaben : Size	: neue Groesse des Speicherbereichs.
  *  Ergebnis : Zeiger auf Speicherbereich.
  *  Info     : Falls nicht genug Speicher zur Verfuegung steht, wird
  *		(*MemErrorHandler) () aufgerufen.
  */

#define AlignedSize(ElmtSize) \
	(SIZE) ((ElmtSize) >= 2 ? ((ElmtSize) + 1) & ~1 : (ElmtSize))

#define MemNewList(nElmts, ElmtSize) \
	MemNew ((nElmts) * AlignedSize (ElmtSize))
  /**********************************************************************
  *  Funktion : Allokiert eine Liste.
  *  Eingaben : nElmts	 : # Eintraege.
  *		ElmtSize : Eintragsgroesse in Bytes.
  *  Ergebnis : Zeiger auf Liste.
  *  Info     : Falls nicht genug Speicher zur Verfuegung steht, wird
  *		(*MemErrorHandler) () aufgerufen.
  */

#define MemDeleteList(List, nElmts, ElmtSize) \
	MemDelete (List, (nElmts) * AlignedSize (ElmtSize))
  /**********************************************************************
  *  Funktion : Gibt eine Liste frei.
  *  Eingaben : List	 : Zeiger auf freizugebende Liste.
  *		nElmts	 : # Elemente.
  *		ElmtSize : Elementgroesse in Bytes.
  *  Ergebnis : ---
  */

extern PVOID MemExtendList ARGS ((PVOID List, PSIZE nElmts, SIZE ElmtSize));
  /**********************************************************************
  *  Funktion : Erweitert eine Liste auf die doppelte Elemntanzahl.
  *  Eingaben : List	 : Zeiger auf zu erweiternde Liste.
  *		nElmts	 : urspr. # Elemente.
  *		ElmtSize : Elementgroesse in Bytes.
  *  Ausgaben : nElmts	 : neue # Elemente.
  *  Ergebnis : Zeiger auf erweiterte Liste.
  */

extern PPVOID MemNewArray ARGS ((
  USHORT nRows, USHORT nColumns, SIZE ElmtSize));
  /**********************************************************************
  *  Funktion : Allokiert eine Tabelle.
  *  Eingaben : nRows	 : # Zeilen.
  *		nColumns : # Spalten.
  *		ElmtSize : Elementgroesse in Bytes.
  *  Ergebnis : Zeiger auf Tabelle.
  *  Info     : Falls nicht genug Speicher zur Verfuegung steht, wird
  *		(*MemErrorHandler) () aufgerufen.
  */

extern VOID MemDeleteArray ARGS ((
  PPVOID Array, USHORT nRows, USHORT nColumns, SIZE ElmtSize));
  /**********************************************************************
  *  Funktion : Gibt eine Tabelle frei.
  *  Eingaben : Array	 : Zeiger auf freizugebende Tabelle.
  *		nRows	 : # Zeilen.
  *		nColumns : # Spalten.
  *		ElmtSize : Elementgroesse in Bytes.
  *  Ergebnis : ---
  */

/************************************************************************
*  Kompatibilitaet mit REX, LALR
*************************************************************************/

#define InitMemory() \
	MemInit()

#define Alloc(Size) \
	MemNew ((SIZE) (Size))

#define Free(Size, Memory) \
	MemDelete (Memory, (SIZE) (Size))

#ifndef __DYNARR__

#define ArrAlloc(Address, pElmtNum, ElmtSize) \
	*Address = MemNewList (*pElmtNum, ElmtSize)

#define ArrNew(Address, pElmtNum, ElmtSize) \
	*Address = MemNewList ((SIZE) *pElmtNum, (SIZE) ElmtSize)

#define ArrFree(Address, pElmtNum, ElmtSize) \
	MemDeleteList (*Address, (SIZE) *pElmtNum, (SIZE) ElmtSize); \
	*Address = NULL

#define ArrExtend(Address, pElmtNum, ElmtSize) \
	*Address = MemExtendList (*Address, pElmtNum, (SIZE) ElmtSize)

#endif /* !__DYNARR__ */

#if defined (__cplusplus)
}
#endif
#endif /* !__DYNMEM__ */
