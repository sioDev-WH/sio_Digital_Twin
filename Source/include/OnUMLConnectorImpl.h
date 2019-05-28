// OnUMLConnectorImpl.h: interface for the COnUMLConnectorBaseImpl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONUMLCONNECTORIMPL_H__722E9230_AD6D_43F4_9F8F_CAC25EEA3CE8__INCLUDED_)
#define AFX_ONUMLCONNECTORIMPL_H__722E9230_AD6D_43F4_9F8F_CAC25EEA3CE8__INCLUDED_

#include "OnUMLDaeEsoBaseImpl.h"
#include "OnUMLConstants_i.c"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



template < class T >
class COnUMLConnectorImpl : public COnUMLDaeEsoBaseImpl<T>
{
public:
	COnUMLConnectorImpl()
  {
    //CopyGUID(TypeID_IOnUMLConnector, m_TypeGUID);
    m_bEsosByRef = true;
  }

  virtual ~COnUMLConnectorImpl() 
  { 
  
  }

  virtual HRESULT Connect(SAFEARRAY** ConnA, SAFEARRAY** ConnB) { return S_OK; }

  virtual HRESULT GetADResidual(long iEqn, double t, Fdouble* residual) { return S_OK; }

  virtual HRESULT GetJacobianValues(
    long* iJac, 
    long nJac, 
    double t, 
    double* jacobians)
  {
    HRESULT hr = S_OK;
	  long i, j;
    long iEqn, iVar, nVar;

	  Fdouble res;

    i = 0;
    while ( (i < nJac) && SUCCEEDED(hr) )
    {
      iEqn = iJac[2*i];
      for (j = i, nVar = 0; j < nJac; j++) 
      {
        if (iEqn != iJac[2*j]) break;
        nVar++;
      }

      for (j = 0; j < m_varC.nADVars; j++) 
      {
        m_varC.FVars[j]->diff(-1, 0);
        m_varC.derFVars[j]->diff(-1,0);
      }

      for (j = 0; j < nVar; j++)
      {
        iVar = iJac[2*(i+j)+1];
        m_varC.FVars[iVar]->diff(j, nVar);
      }
    
      res.diff(-1,0);
		  hr = GetADResidual(iEqn, t, &res);
    
      for (j = 0; j < nVar; j++) jacobians[i+j] = res.d(j);
    
      i += nVar;
    }

    return hr;
  }

  virtual HRESULT GetDiffJacobianValues(
    long* iJac, 
    long nJac, 
    double t, 
    double* jacobians)
  {
    HRESULT hr = S_OK;
	  long i, j;
    long iEqn, iVar, nVar;

	  Fdouble res;
    i = 0;
    while ( (i < nJac) && SUCCEEDED(hr) )
    {
      iEqn = iJac[2*i];
      for (j = i, nVar = 0; j < nJac; j++) 
      {
        if (iEqn != iJac[2*j]) break;
        nVar++;
      }

      for (j = 0; j < m_varC.nADVars; j++) 
      {
        m_varC.FVars[j]->diff(-1, 0);
        m_varC.derFVars[j]->diff(-1, 0);
      }

      for (j = 0; j < nVar; j++)
      {
        iVar = iJac[2*(i+j)+1];
        m_varC.derFVars[iVar]->diff(j, nVar);
      }
    
      res.diff(-1,0);
		  hr = GetADResidual(iEqn, t, &res);
    
      for (j = 0; j < nVar; j++) jacobians[i+j] = res.d(j);
    
      i += nVar;
    }

    return hr;
  }


public:

};

#endif // !defined(AFX_ONUMLCONNECTORIMPL_H__722E9230_AD6D_43F4_9F8F_CAC25EEA3CE8__INCLUDED_)
