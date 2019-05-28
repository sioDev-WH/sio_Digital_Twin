// OnUMLDaeEsoImpl.h: interface for the COnStlModelImpl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONSTLMODELIMPL_H__C290FA85_9DAA_49A9_9B10_E2D770A8CE19__INCLUDED_)
#define AFX_ONSTLMODELIMPL_H__C290FA85_9DAA_49A9_9B10_E2D770A8CE19__INCLUDED_

#include "OnUMLDaeEsoBaseImpl.h"
#include "OnUMLAssociation.h"
#include "OnUMLEsoMacros.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T>
class COnStlModelImpl : public COnUMLDaeEsoBaseImpl<T>
{
public:
  COnStlModelImpl() { }
  virtual ~COnStlModelImpl() { }

  // connections
  virtual HRESULT Connect(SAFEARRAY** ppsaConnA, SAFEARRAY** ppsaConnB)
  {
    long idx = m_nAssociations;
    long* vec = NULL;
    long i, j;
    long lbound;
    long ubound;
    long size;

    size_ptr_array(20, m_nAssociations, m_dAssociations, m_Associations);
    
    m_Associations[idx] = new COnUMLAssociation();

    SafeArrayAccessData(*ppsaConnA, (void HUGEP* FAR*)& vec);
    SafeArrayGetLBound(*ppsaConnA, (unsigned int) 1, &lbound);
    SafeArrayGetUBound(*ppsaConnA, (unsigned int) 1, &ubound);
    size = ubound - lbound + 1;
    
    m_Associations[idx]->nFromIds = size;
    m_Associations[idx]->FromIds = new long[size];
    for (i = 0, j = lbound; i < size; i++, j++) 
      m_Associations[idx]->FromIds[i] = vec[j];
    
    SafeArrayUnaccessData(*ppsaConnA);


    SafeArrayAccessData(*ppsaConnB, (void HUGEP* FAR*)& vec);
    SafeArrayGetLBound(*ppsaConnB, (unsigned int) 1, &lbound);
    SafeArrayGetUBound(*ppsaConnB, (unsigned int) 1, &ubound);
    size = ubound - lbound + 1;
    
    m_Associations[idx]->nToIds = size;
    m_Associations[idx]->ToIds = new long[size];
    for (i = 0, j = lbound; i < size; i++, j++) 
      m_Associations[idx]->ToIds[i] = vec[j];

    SafeArrayUnaccessData(*ppsaConnB);

    m_nAssociations++;

    return S_OK;
  }

  // method implemented on derived class that loads Eso associations
  virtual HRESULT GetAssociations(long** Assoc, long** Size, long* nSize) { return E_NOTIMPL; }

  virtual HRESULT InitAssociations()
  {
    long* Assoc = NULL;
    long* Size = NULL;
    long nSize = 0;
    long i, j, k;

    for (i = 0; i < m_nEsos; i++) m_Esos[i]->InitAssociations();

    if (m_nAssociations == 0) // if the number of associations is not zero, associations have been added through the connect mechanism.
    {
      if (SUCCEEDED(GetAssociations(&Assoc, &Size, &nSize) ))
      {
      
        m_nAssociations = nSize / 2;
        m_Associations = new COnUMLAssociation*[m_nAssociations];
        m_dAssociations = m_nAssociations;

        k = 0;
        for (i = 0; i < m_nAssociations; i++) 
        {
          m_Associations[i] = new COnUMLAssociation();
          m_Associations[i]->nFromIds = Size[2*i];
          m_Associations[i]->FromIds = new long[m_Associations[i]->nFromIds];
          for (j = 0; j < m_Associations[i]->nFromIds; j++) m_Associations[i]->FromIds[j] = Assoc[k++];
          m_Associations[i]->nToIds = Size[2*i+1];
          m_Associations[i]->ToIds = new long[m_Associations[i]->nToIds];
          for (j = 0; j < m_Associations[i]->nToIds; j++) m_Associations[i]->ToIds[j] = Assoc[k++];
        }
      }
    }
    
    DESTROY_VECTOR(Assoc)
    DESTROY_VECTOR(Size)

    return S_OK;
  }

  virtual HRESULT iInitializeGlobalNode()
  {
    HRESULT hr = S_OK;
    long i, j, k;
    long nBlocks = 0;
    long* spBlocks = NULL;
    long* cNZBlocks = NULL;
    COnUMLDaeEsoBase** pEsos = NULL;

    hr = InitAssociations();
    if (SUCCEEDED(hr))
    {
      hr = GetAssociationBlocks(nBlocks, spBlocks, cNZBlocks, pEsos);
      if (SUCCEEDED(hr))
      {
        for (i = 0; i < nBlocks; i++)
        {
          k = spBlocks[i] + 1;
          for (j = 1; j < cNZBlocks[i]; j++)
          {
            pEsos[spBlocks[i]]->AddMemberEso(pEsos[k++], NULL);
          }
          pEsos[spBlocks[i]]->SetMasterNodeStatus(true);
        }
      }
    }

    DESTROY_VECTOR(spBlocks)
    DESTROY_VECTOR(cNZBlocks)
    DESTROY_VECTOR(pEsos)


    return hr;
  }

};

#endif // !defined(AFX_ONSTLMODELIMPL_H__C290FA85_9DAA_49A9_9B10_E2D770A8CE19__INCLUDED_)
