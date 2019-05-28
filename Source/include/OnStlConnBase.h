// OnStlConnBase.h: interface for the OnStlConnBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONSTLCONNBASE_H__EDA195DD_A48F_4D55_9302_CC83B084A803__INCLUDED_)
#define AFX_ONSTLCONNBASE_H__EDA195DD_A48F_4D55_9302_CC83B084A803__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#undef _VAREX_UML_MACROS
//#define _STL_UML_MACROS
#include "OnUMLConnectorImpl.h"

struct OnConnEqnMap
{
  void init(long inVec, long inVar, long inEso, OnPhysicalType inType)
  {
    iVec = inVec;
    iVar = inVar;
    iEso = inEso;
    type = inType;
  }

  long iVec;
  long iVar;
  long iEso;
  OnPhysicalType type;
};

template <class T>
class OnStlConnBase : public COnUMLConnectorImpl<T>
{
public:

  virtual void enumVars(OnStlVec<double>**& vec, long& size) = 0;

OnStlConnBase()
{
  m_TypedEsos = NULL;
  m_vec = NULL;
  m_size = 0;
  m_map = NULL;
  m_bEsosByRef = true;
}

virtual ~OnStlConnBase()
{
  clean();
}

void init()
{
  long nVars = 0;
  long nEqns = 0;
  long iVec;
  long iEqn;
  long iVar;
  long iEso;
  OnPhysicalType varType;

  // clean memory
  clean();

  // retrive OnStlVec vectors
  enumVars(m_vec, m_size);

  // determine number of variables and equations
  for (iVec = 0; iVec < m_size; iVec++)
  {
    nVars += m_vec[iVec]->size();
    varType = m_vec[iVec]->GetPhysicalType();
    if (varType == OnPhysicalType_Sum)
      nEqns += m_vec[iVec]->size();
    else if (varType == OnPhysicalType_Equal)
      nEqns += m_vec[iVec]->size() * m_nEsos;
  }

  // if this is a master node, construct equation map
  if (m_bMasterNode)
  {
    m_nLocalADEqns = nEqns;
    m_nLocalEqns = nEqns;
    m_map = new OnConnEqnMap[nEqns];
    iEqn = 0;
    for (iVec = 0; iVec < m_size; iVec++)
    {
      varType = m_vec[iVec]->GetPhysicalType();
      if (varType == OnPhysicalType_Sum)
      {
        for (iVar = 0; iVar < m_vec[iVec]->size(); iVar++)
          m_map[iEqn++].init(iVec, iVar, 0, varType);
      }
      else if (varType == OnPhysicalType_Equal)
      {
        for (iVar = 0; iVar < m_vec[iVec]->size(); iVar++)
        {
          for (iEso = 0; iEso < m_nEsos; iEso++)
            m_map[iEqn++].init(iVec, iVar, iEso, varType);
        }
      }
    }
  }

  if (m_TypedEsos == NULL)
  {
    m_TypedEsos = new T*[m_nEsos];
    for (long iVec = 0; iVec < m_nEsos; iVec++)
    {
      m_TypedEsos[iVec] = dynamic_cast<T*> (m_Esos[iVec]);
      _ASSERTE(m_TypedEsos[iVec]);
    }
  }
}

void clean()
{
  DESTROY_VECTOR(m_TypedEsos)
  DESTROY_VECTOR(m_vec)
  DESTROY_VECTOR(m_map)
  m_size = 0;
}

HRESULT GetADResidual(long iEqn, double t, Fdouble* residual) 
{
  long iVec, iVar, iEso;
  OnPhysicalType varType;

  iVec = m_map[iEqn].iVec;
  iVar = m_map[iEqn].iVar;
  iEso = m_map[iEqn].iEso;
  varType = m_map[iEqn].type;

  if (varType == OnPhysicalType_Sum)
  {
    *residual = (*(m_vec[iVec])).ad[iVar];
    for (iEso = 0; iEso < m_nEsos; iEso++)
    {
      *residual += (*(m_TypedEsos[iEso]->m_vec[iVec])).ad[iVar];
    }
  }
  else if (varType == OnPhysicalType_Equal)
  {
    *residual = (*(m_vec[iVec])).ad[iVar];
    *residual -= (*(m_TypedEsos[iEso]->m_vec[iVec])).ad[iVar];
  }
  
  return S_OK;
}

HRESULT GetResiduals(long* iEqns, long nEqn, double t, double* residuals) 
{
  long iRes, iEqn, iVec, iVar, iEso;
  OnPhysicalType varType;

  for (iRes = 0; iRes < nEqn; iRes++)
  {
    iEqn = iEqns[iRes];
    iVec = m_map[iEqn].iVec;
    iVar = m_map[iEqn].iVar;
    iEso = m_map[iEqn].iEso;
    varType = m_map[iEqn].type;

    if (varType == OnPhysicalType_Sum)
    {
      residuals[iRes] = (*(m_vec[iVec]))[iVar];
      for (iEso = 0; iEso < m_nEsos; iEso++)
      {
        residuals[iRes] += (*(m_TypedEsos[iEso]->m_vec[iVec]))[iVar];
      }
    }
    else if (varType == OnPhysicalType_Equal)
    {
      residuals[iRes] = (*(m_vec[iVec]))[iVar];
      residuals[iRes] -= (*(m_TypedEsos[iEso]->m_vec[iVec]))[iVar];
    }
  }
  
  return S_OK;
}

HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) 
{
  long i;
  DESTROY_VECTOR(*form)
  long nEqns = m_nLocalEqns + m_nLocalDistEqns + m_nLocalStlEqns;
  *form = new OnEqnForm[nEqns];
  
  for (i = 0; i < nEqns; i++) (*form)[i] = continuous;
  
  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[nEqns];
  
  for (i = 0; i < nEqns; i++) (*diff_form)[i] = automatic;
  
  return S_OK;
}

HRESULT InitLocalADEqns() 
{
  return S_OK;
}

HRESULT InitLocalEqns() 
{
  init();
  return S_OK;
}

bool Load(FILE * fs) 
{
  return true;
}

void Save(FILE * fs) 
{
}

protected:
  T** m_TypedEsos;
  OnStlVec<double>** m_vec;
  long m_size;
  OnConnEqnMap* m_map;

};


#endif // !defined(AFX_ONSTLCONNBASE_H__EDA195DD_A48F_4D55_9302_CC83B084A803__INCLUDED_)
