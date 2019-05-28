// OnMapBSTR.cpp: implementation of the COnMapBSTR class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OnMapBSTR.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COnMapBSTR::COnMapBSTR(int nBlockSize)
{
	_ASSERTE(nBlockSize > 0);

	m_pHashTable = NULL;
	m_nHashTableSize = 17;  // default size
	m_nCount = 0;
	m_pFreeList = NULL;
	m_pBlocks = NULL;
	m_nBlockSize = nBlockSize;
}

inline UINT COnMapBSTR::HashKey(BSTR key) const
{
  USES_CONVERSION;

  LPTSTR psz = OLE2T(key);
	UINT nHash = 0;
	while (*psz)
		nHash = (nHash<<5) + nHash + *psz++;
	return nHash;
}

void COnMapBSTR::InitHashTable(UINT nHashSize, BOOL bAllocNow)
//
// Used to force allocation of a hash table or to override the default
//   hash table size of (which is fairly small)
{
	_ASSERTE(m_nCount == 0);
	_ASSERTE(nHashSize > 0);

	if (m_pHashTable != NULL)
	{
		// free hash table
		delete[] m_pHashTable;
		m_pHashTable = NULL;
	}

	if (bAllocNow)
	{
		m_pHashTable = new CAssoc* [nHashSize];
		memset(m_pHashTable, 0, sizeof(CAssoc*) * nHashSize);
	}
	m_nHashTableSize = nHashSize;
}

void COnMapBSTR::RemoveAll()
{
	if (m_pHashTable != NULL)
	{
		// destroy elements
		for (UINT nHash = 0; nHash < m_nHashTableSize; nHash++)
		{
			CAssoc* pAssoc;
			for (pAssoc = m_pHashTable[nHash]; pAssoc != NULL;
			  pAssoc = pAssoc->pNext)
			{
        ::SysFreeString(pAssoc->key);
			}
		}

		// free hash table
		delete [] m_pHashTable;
		m_pHashTable = NULL;
	}

	m_nCount = 0;
	m_pFreeList = NULL;
	m_pBlocks->FreeDataChain();
	m_pBlocks = NULL;
}

COnMapBSTR::~COnMapBSTR()
{
	RemoveAll();
	_ASSERTE(m_nCount == 0);
}

/////////////////////////////////////////////////////////////////////////////
// Assoc helpers
// same as CList implementation except we store CAssoc's not CNode's
//    and CAssoc's are singly linked all the time

COnMapBSTR::CAssoc*
COnMapBSTR::NewAssoc()
{
	if (m_pFreeList == NULL)
	{
		// add another block
		CISPlex* newBlock = CISPlex::Create(m_pBlocks, m_nBlockSize,
							sizeof(COnMapBSTR::CAssoc));
		// chain them into free list
		COnMapBSTR::CAssoc* pAssoc =
				(COnMapBSTR::CAssoc*) newBlock->data();
		// free in reverse order to make it easier to debug
		pAssoc += m_nBlockSize - 1;
		for (int i = m_nBlockSize-1; i >= 0; i--, pAssoc--)
		{
			pAssoc->pNext = m_pFreeList;
			m_pFreeList = pAssoc;
		}
	}
	_ASSERTE(m_pFreeList != NULL);  // we must have something

	COnMapBSTR::CAssoc* pAssoc = m_pFreeList;
	m_pFreeList = m_pFreeList->pNext;
	m_nCount++;
	_ASSERTE(m_nCount > 0);  // make sure we don't overflow

	pAssoc->value = 0;

	return pAssoc;
}

void COnMapBSTR::FreeAssoc(COnMapBSTR::CAssoc* pAssoc)
{
  ::SysFreeString(pAssoc->key);

	pAssoc->pNext = m_pFreeList;
	m_pFreeList = pAssoc;
	m_nCount--;
	_ASSERTE(m_nCount >= 0);  // make sure we don't underflow

	// if no more elements, cleanup completely
	if (m_nCount == 0)
		RemoveAll();
}

COnMapBSTR::CAssoc*
COnMapBSTR::GetAssocAt(BSTR key, UINT& nHash) const
// find association (or return NULL)
{
	nHash = HashKey(key) % m_nHashTableSize;

	if (m_pHashTable == NULL)
		return NULL;

	// see if it exists
	CAssoc* pAssoc;
	for (pAssoc = m_pHashTable[nHash]; pAssoc != NULL; pAssoc = pAssoc->pNext)
	{
    //if (_tcscmp(pAssoc->key, key) == 0)
    if (wcscmp(pAssoc->key, key) == 0)
			return pAssoc;
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////

BOOL COnMapBSTR::Lookup(BSTR key, DWORD& rValue) const
{

	UINT nHash;
	CAssoc* pAssoc = GetAssocAt(key, nHash);
	if (pAssoc == NULL)
		return FALSE;  // not in map

	rValue = pAssoc->value;
	return TRUE;
}

BOOL COnMapBSTR::LookupKey(BSTR key, BSTR& rKey) const
{

	UINT nHash;
	CAssoc* pAssoc = GetAssocAt(key, nHash);
	if (pAssoc == NULL)
		return FALSE;  // not in map

	rKey = pAssoc->key;
	return TRUE;
}

DWORD& COnMapBSTR::operator[](BSTR key)
{

	UINT nHash;
	CAssoc* pAssoc;
	if ((pAssoc = GetAssocAt(key, nHash)) == NULL)
	{
		if (m_pHashTable == NULL)
			InitHashTable(m_nHashTableSize);

		// it doesn't exist, add a new Association
		pAssoc = NewAssoc();
		pAssoc->nHashValue = nHash;
		pAssoc->key = key;
		// 'pAssoc->value' is a constructed object, nothing more

		// put into hash table
		pAssoc->pNext = m_pHashTable[nHash];
		m_pHashTable[nHash] = pAssoc;
	}
	return pAssoc->value;  // return new reference
}


BOOL COnMapBSTR::RemoveKey(BSTR key)
// remove key - return TRUE if removed
{

	if (m_pHashTable == NULL)
		return FALSE;  // nothing in the table

	CAssoc** ppAssocPrev;
	ppAssocPrev = &m_pHashTable[HashKey(key) % m_nHashTableSize];

	CAssoc* pAssoc;
	for (pAssoc = *ppAssocPrev; pAssoc != NULL; pAssoc = pAssoc->pNext)
	{
    // if (_tcscmp(pAssoc->key, key) == 0)
    if (wcscmp(pAssoc->key, key) == 0)
		{
			// remove it
			*ppAssocPrev = pAssoc->pNext;  // remove from list
			FreeAssoc(pAssoc);
			return TRUE;
		}
		ppAssocPrev = &pAssoc->pNext;
	}
	return FALSE;  // not found
}


/////////////////////////////////////////////////////////////////////////////
// Iterating

void COnMapBSTR::GetNextAssoc(ISPOSITION& rNextPosition, BSTR& rKey, DWORD& rValue) const
{
	_ASSERTE(m_pHashTable != NULL);  // never call on empty map

	CAssoc* pAssocRet = (CAssoc*)rNextPosition;
	_ASSERTE(pAssocRet != NULL);

	if (pAssocRet == (CAssoc*) ISBEFORE_START_POSITION)
	{
		// find the first association
		for (UINT nBucket = 0; nBucket < m_nHashTableSize; nBucket++)
			if ((pAssocRet = m_pHashTable[nBucket]) != NULL)
				break;
		_ASSERTE(pAssocRet != NULL);  // must find something
	}

	// find next association
	CAssoc* pAssocNext;
	if ((pAssocNext = pAssocRet->pNext) == NULL)
	{
		// go to next bucket
		for (UINT nBucket = pAssocRet->nHashValue + 1;
		  nBucket < m_nHashTableSize; nBucket++)
			if ((pAssocNext = m_pHashTable[nBucket]) != NULL)
				break;
	}

	rNextPosition = (ISPOSITION) pAssocNext;

	// fill in return data
	rKey = pAssocRet->key;
	rValue = pAssocRet->value;
}


/////////////////////////////////////////////////////////////////////////////
