// OnMapBSTR.h: interface for the COnMapBSTR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONMAPBSTR_H__53CDAE04_EA3A_4D8F_8654_770348E58454__INCLUDED_)
#define AFX_ONMAPBSTR_H__53CDAE04_EA3A_4D8F_8654_770348E58454__INCLUDED_

#include "OnDaeCOSolverExport.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////

#ifndef __ISPOSITION
#define __ISPOSITION
struct _POSITION { };
typedef _POSITION* ISPOSITION;
#define ISBEFORE_START_POSITION ((ISPOSITION)-1L)
#endif // __ISPOSITION

#ifndef __ISPLEX_H__
#define __ISPLEX_H__

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif

#ifdef AFX_COLL_SEG
#pragma code_seg(AFX_COLL_SEG)
#endif

struct CISPlex     // warning variable length structure
{
	CISPlex* pNext;
#if (_AFX_PACKING >= 8)
	DWORD dwReserved[1];    // align on 8 byte boundary
#endif
	// BYTE data[maxNum*elementSize];

	void* data() { return this+1; }

  // like 'calloc' but no zero fill
	// may throw memory exceptions
  static CISPlex* PASCAL Create(CISPlex*& pHead, UINT nMax, UINT cbElement)
  {
	  _ASSERTE(nMax > 0 && cbElement > 0);
	  CISPlex* p = (CISPlex*) new BYTE[sizeof(CISPlex) + nMax * cbElement];
			  // may throw exception
	  p->pNext = pHead;
	  pHead = p;  // change head (adds in reverse order for simplicity)
	  return p;
  }

  void FreeDataChain()     // free this one and links
  {
	  CISPlex* p = this;
	  while (p != NULL)
	  {
		  BYTE* bytes = (BYTE*) p;
		  CISPlex* pNext = p->pNext;
		  delete[] bytes;
		  p = pNext;
	  }
  }

};

#ifdef AFX_COLL_SEG
#pragma code_seg()
#endif

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif

#endif //__ISPLEX_H__



class ONDAECOSOLVER_API COnMapBSTR
{

protected:
	// Association
	struct CAssoc
	{
		CAssoc* pNext;
		UINT nHashValue;  // needed for efficient iteration
		BSTR key;
    DWORD value;
	};

public:

// Construction
	COnMapBSTR(int nBlockSize = 10);

// Attributes
	// number of elements
	int GetCount() const;
	BOOL IsEmpty() const;

	// Lookup
  BOOL Lookup(BSTR key, DWORD& rValue) const;
	BOOL LookupKey(BSTR key, BSTR& rKey) const;

// Operations
	// Lookup and add if not there
  DWORD& operator[](BSTR key);

	// add a new (key, value) pair
  void SetAt(BSTR key, DWORD newValue)
    { (*this)[key] = newValue; }

	// removing existing (key, ?) pair
	BOOL RemoveKey(BSTR key);
	void RemoveAll();

	// iterating all (key, value) pairs
	ISPOSITION GetStartPosition() const;
  void GetNextAssoc(ISPOSITION& rNextPosition, BSTR& rKey, DWORD& rValue) const;

	// advanced features for derived classes
	UINT GetHashTableSize() const;
	void InitHashTable(UINT hashSize, BOOL bAllocNow = TRUE);

// Overridables: special non-virtual (see map implementation for details)
	// Routine used to user-provided hash keys
	UINT HashKey(BSTR key) const;

// Implementation
protected:
	CAssoc** m_pHashTable;
	UINT m_nHashTableSize;
	int m_nCount;
	CAssoc* m_pFreeList;
	struct CISPlex* m_pBlocks;
	int m_nBlockSize;

	CAssoc* NewAssoc();
	void FreeAssoc(CAssoc*);
	CAssoc* GetAssocAt(BSTR, UINT&) const;

public:
	virtual ~COnMapBSTR();

protected:

  typedef BSTR BASE_KEY;
	typedef BSTR BASE_ARG_KEY;
  typedef DWORD BASE_VALUE;
  typedef DWORD BASE_ARG_VALUE;
};

#endif // !defined(AFX_ONMAPBSTR_H__53CDAE04_EA3A_4D8F_8654_770348E58454__INCLUDED_)
