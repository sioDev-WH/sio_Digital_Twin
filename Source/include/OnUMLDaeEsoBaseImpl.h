#ifndef _ON_UML_DAE_ESO_BASE_IMPL_
#define _ON_UML_DAE_ESO_BASE_IMPL_

#include "OnUMLDaeEsoBase.h"
#include "OnUMLEsoMacros.h"
#include "OnAD.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


template < class T >
class COnUMLDaeEsoBaseImpl : public COnUMLDaeEsoBase 
{
public:
	COnUMLDaeEsoBaseImpl()
  {
    m_LocalEqns = NULL;
    m_LocalADEqns = NULL;
    m_LocalDistEqns = NULL;
    m_LocalDistADEqns = NULL;
    m_LocalStlEqns = NULL;
    m_LocalStlADEqns = NULL;
  }

	virtual ~COnUMLDaeEsoBaseImpl()
  {
    if (m_LocalEqns)
    {
      delete[] (double*) m_LocalEqns;
      m_LocalEqns = NULL;
    }

    if (m_LocalADEqns)
    {
      delete[] (double*) m_LocalADEqns;
      m_LocalADEqns = NULL;
    }

    if (m_LocalDistEqns)
    {
      delete[] (double*) m_LocalDistEqns;
      m_LocalDistEqns = NULL;
    }


    if (m_LocalDistADEqns)
    {
      delete[] (double*) m_LocalDistADEqns;
      m_LocalDistADEqns = NULL;
    }

    if (m_LocalStlEqns)
    {
      delete[] (double*) m_LocalStlEqns;
      m_LocalStlEqns = NULL;
    }


    if (m_LocalStlADEqns)
    {
      delete[] (double*) m_LocalStlADEqns;
      m_LocalStlADEqns = NULL;
    }

  }

  // *********************************************************************
  // function pointer prototypes
  // *******************************************
#ifdef _ONI_FCN_BYREF   // reference-based function prototypes
  typedef HRESULT (T::*residual_eqn)(double& r);
  typedef HRESULT (T::*ad_residual_eqn)(Fdouble& r);
  typedef HRESULT (T::*dist_residual_eqn)();
  typedef HRESULT (T::*ad_dist_residual_eqn)();
  typedef HRESULT (T::*stl_residual_eqn)(valarray<double>* r);
  typedef HRESULT (T::*ad_stl_residual_eqn)(valarray<Fdouble>* r);
#else               // pointer-based function prototypes
  typedef HRESULT (T::*residual_eqn)(double* r);
  typedef HRESULT (T::*ad_residual_eqn)(Fdouble* r);
  typedef HRESULT (T::*dist_residual_eqn)();
  typedef HRESULT (T::*ad_dist_residual_eqn)();
  typedef HRESULT (T::*stl_residual_eqn)(valarray<double>* r);
  typedef HRESULT (T::*ad_stl_residual_eqn)(valarray<Fdouble>* r);
#endif
  // *********************************************************************


  // *********************************************************************
  // Default implementation of GetResiduals
  // *******************************************
  virtual HRESULT GetResiduals(long* iEqns, long nEqns, double t, double* residuals)
  {
    HRESULT hr = S_OK;
    long i;
    T* pT = static_cast<T*>(this);

    m_time = t;

    if (m_nLocalDistEqns == 0 && m_nLocalStlEqns == 0)
    {
      for (i = 0; i < nEqns && SUCCEEDED(hr); i++)
      {
        #ifdef _ONI_FCN_BYREF   // reference-based function prototypes
          hr = (pT->*(m_LocalEqns[iEqns[i]]))(residuals[i]);
        #else
          hr = (pT->*(m_LocalEqns[iEqns[i]]))(&residuals[i]);
        #endif
      }
    }
    else
    {
      long iDistEqn, iStlEqn, iRes;

      // clear the color array (so equations will be called once again)
      if (m_nLocalDistEqns > 0)
      {
        for (i = 0; i < m_nLocalDistEqns; i++) m_LocalDistEqnColor[i] = false;
      }
      else if (m_nLocalStlEqns > 0)
      {
        for (i = 0; i < m_nLocalStlEqns; i++) m_LocalStlEqnColor[i] = false;
      }

      // call the equations
      for (i = 0; i < nEqns && SUCCEEDED(hr); i++)
      {
        if (iEqns[i] < m_nLocalEqns)
        {
          #ifdef _ONI_FCN_BYREF   // reference-based function prototypes
            hr = (pT->*(m_LocalEqns[iEqns[i]]))(residuals[i]);
          #else
            hr = (pT->*(m_LocalEqns[iEqns[i]]))(&residuals[i]);
          #endif
        }
        else
        {
          // Assumption: distributed equations and stl equations will not be mixed
          if (m_nLocalDistEqns > 0)
          {
            // distributed equations
            iRes = iEqns[i] - m_nLocalEqns;
            for (iDistEqn = 0; iDistEqn < m_nLocalDistEqns; iDistEqn++)
            {
              if (iRes < m_LocalDistEqnResCount[iDistEqn])
              {
                if (!m_LocalDistEqnColor[iDistEqn])
                {
                  hr = (pT->*(m_LocalDistEqns[iDistEqn]))();
                  m_LocalDistEqnColor[iDistEqn] = true;      
                }
                residuals[i] = m_LocalDistEqnVars[iDistEqn]->pVal[iRes];
                break;
              }
              else
              {
                iRes -= m_LocalDistEqnResCount[iDistEqn];
              }
            }
          }
          else if (m_nLocalStlEqns > 0)
          {
            // stl equations
            iRes = iEqns[i] - m_nLocalEqns;
            for (iStlEqn = 0; iStlEqn < m_nLocalStlEqns; iStlEqn++)
            {
              if (iRes < m_LocalStlEqnResCount[iStlEqn])
              {
                if (!m_LocalStlEqnColor[iStlEqn])
                {
                  hr = (pT->*(m_LocalStlEqns[iStlEqn]))( m_LocalStlEqnVars[iStlEqn] );
                  m_LocalStlEqnColor[iStlEqn] = true;      
                }
                residuals[i] = m_LocalStlEqnVars[iStlEqn]->_Ptr[iRes];
                break;
              }
              else
              {
                iRes -= m_LocalStlEqnResCount[iStlEqn];
              }
            }
          }
        }
      }

    }

    return hr;
  }
  // *********************************************************************



protected:

  #define ADD_LOCAL_EQN(CLASS, EQN) AddLocalEqn( CLASS::EQN, _T(#EQN) );

  void AddLocalEqn(residual_eqn eqn, _TCHAR* Name)
  {
    long Dim;

    Dim = m_dLocalEqns;
    size_array(20, m_nLocalEqns, Dim, (double*&) m_LocalEqns);
    size_array(20, m_nLocalEqns, m_dLocalEqns, m_EqnNames);

    m_LocalEqns[m_nLocalEqns] = eqn;
    m_EqnNames[m_nLocalEqns] = ::SysAllocString(Name);
    m_nLocalEqns++;
  }

  #define ADD_LOCAL_DIST_EQN(CLASS, EQN, EQNVAR) AddLocalDistEqn( CLASS::EQN, _T(#EQN), &(EQNVAR));

  void AddLocalDistEqn(dist_residual_eqn eqn, _TCHAR* Name, DistributedVar* eqnVar)
  {
    T* pT = static_cast<T*>(this);
    long Dim;

    Dim = m_dLocalDistEqns;
    size_array(20, m_nLocalDistEqns, Dim, (double*&) m_LocalDistEqns);
    Dim = m_dLocalDistEqns;
    size_array(20, m_nLocalDistEqns, Dim, m_DistEqnNames);
    Dim = m_dLocalDistEqns;
    size_array(20, m_nLocalDistEqns, Dim, m_LocalDistEqnResCount);
    Dim = m_dLocalDistEqns;
    size_array(20, m_nLocalDistEqns, Dim, m_LocalDistEqnColor);
    size_array(20, m_nLocalDistEqns, m_dLocalDistEqns, m_LocalDistEqnVars);

    // call the equation once to ensure the distributed variable is initialized to correct size.
    (pT->*(eqn))();
    
    m_LocalDistEqns[m_nLocalDistEqns] = eqn;
    m_LocalDistEqnVars[m_nLocalDistEqns] = eqnVar;
    m_LocalDistEqnResCount[m_nLocalDistEqns] = eqnVar->nVal;
    m_DistEqnNames[m_nLocalDistEqns] = ::SysAllocString(Name);
    m_nLocalDistEqns++;
  }

  #define ADD_LOCAL_AD_EQN(CLASS, EQN) AddLocalADEqn( CLASS::EQN, _T(#EQN) );

  void AddLocalADEqn(ad_residual_eqn eqn, _TCHAR* Name)
  {
    size_array(20, m_nLocalADEqns, m_dLocalADEqns, (double*&) m_LocalADEqns);
    m_LocalADEqns[m_nLocalADEqns++] = eqn;
  }

  #define ADD_LOCAL_DIST_AD_EQN(CLASS, EQN, EQNVAR) AddLocalDistADEqn( CLASS::EQN, _T(#EQN), &EQNVAR);

  void AddLocalDistADEqn(ad_dist_residual_eqn eqn, _TCHAR* Name, FDistributedVar* eqnVar)
  {
    T* pT = static_cast<T*>(this);
    long Dim;

    Dim = m_dLocalDistADEqns;
    size_array(20, m_nLocalDistADEqns, Dim, (double*&) m_LocalDistADEqns);
    size_array(20, m_nLocalDistEqns, m_dLocalDistEqns, m_LocalDistADEqnVars);

    // call the equation once to ensure the distributed variable is initialized to correct size.
    (pT->*(eqn))();
    
    m_LocalDistADEqns[m_nLocalDistADEqns] = eqn;
    m_LocalDistADEqnVars[m_nLocalDistADEqns] = eqnVar;
    m_nLocalDistADEqns++;
  }

  #define ADD_LOCAL_STL_EQN(CLASS, EQN, SIZE) AddLocalStlEqn( CLASS::EQN, _T(#EQN), SIZE);

  void AddLocalStlEqn(stl_residual_eqn eqn, _TCHAR* Name, long size)
  {
    T* pT = static_cast<T*>(this);
    long Dim;

    Dim = m_dLocalStlEqns;
    size_array(20, m_nLocalStlEqns, Dim, (double*&) m_LocalStlEqns);
    Dim = m_dLocalStlEqns;
    size_array(20, m_nLocalStlEqns, Dim, m_StlEqnNames);
    Dim = m_dLocalStlEqns;
    size_array(20, m_nLocalStlEqns, Dim, m_LocalStlEqnResCount);
    Dim = m_dLocalStlEqns;
    size_array(20, m_nLocalStlEqns, Dim, m_LocalStlEqnColor);
    size_array(20, m_nLocalStlEqns, m_dLocalStlEqns, m_LocalStlEqnVars);

    // call the equation once to ensure the stlributed variable is initialized to correct size.
    m_LocalStlEqns[m_nLocalStlEqns] = eqn;
    m_LocalStlEqnVars[m_nLocalStlEqns] = new OnStlVec<double>(size);
    (pT->*(eqn))(m_LocalStlEqnVars[m_nLocalStlEqns]);
    m_LocalStlEqnResCount[m_nLocalStlEqns] = m_LocalStlEqnVars[m_nLocalStlEqns]->size();
    m_StlEqnNames[m_nLocalStlEqns] = ::SysAllocString(Name);
    m_nLocalStlEqns++;
  }

  #define ADD_LOCAL_STL_AD_EQN(CLASS, EQN, SIZE) AddLocalStlADEqn( CLASS::EQN, _T(#EQN), SIZE);

  void AddLocalStlADEqn(ad_stl_residual_eqn eqn, _TCHAR* Name, long size)
  {
    T* pT = static_cast<T*>(this);
    long Dim;

    Dim = m_dLocalStlADEqns;
    size_array(20, m_nLocalStlADEqns, Dim, (double*&) m_LocalStlADEqns);
    size_array(20, m_nLocalStlADEqns, m_dLocalStlADEqns, m_LocalStlADEqnVars);

    // call the equation once to ensure the distributed variable is initialized to correct size.
    m_LocalStlADEqns[m_nLocalStlADEqns] = eqn;
    m_LocalStlADEqnVars[m_nLocalStlADEqns] = new OnStlVec<Fdouble>(size);
    (pT->*(eqn))(m_LocalStlADEqnVars[m_nLocalStlADEqns]);
    m_nLocalStlADEqns++;
  }


  HRESULT GetJacobianValues(
    long* iJac, 
    long nJac, 
    double t, 
    double* jacobians)
  {
    HRESULT hr = S_OK;
	  long i, j, k;
    long iEqn, iVar, nVar, iVarColor, nItems;
    long iDistEqn, iRes, iStlEqn, iResTest, iResMin, iResMax;
    T* pT = static_cast<T*>(this);

	  Fdouble res;
    m_time = t;
    i = 0;
    while ( (i < nJac) && SUCCEEDED(hr) )
    {
      // read the equation and variable index from the iJac[] vector
      iEqn = iJac[2*i];
      iVar = iJac[2*i+1];

      
      if (iEqn < m_nLocalEqns)
      {
        // count the number of jacobians being sought for the current equation
        nVar = 0;
        nItems = 0;
        //for (j = i; (iEqn == iJac[2*j]) && (j < nJac) && (j == i || iVar != iJac[2*j+1]); j++)
        for (j = i; j < nJac; j++)
        {
          if (iEqn != iJac[2*j]) break;
          nItems++;
          nVar++;
        }
      }
      else
      {
        // Assumption: will not mix distributed and stl equations together in the same model.
        if (m_nLocalDistEqns > 0)
        {
          // begin distributed equations
          
          // Have multiple residuals associated with one function.  
          // Need to initialize all variables to write their outputs to a given unique slot.
          // After the function is called, read the residuals back for each variable from the designated slots.

          // reset the residuals for all distributed equation vars
          for (j = 0; j < m_nLocalDistEqns; j++)
            m_LocalDistADEqnVars[j]->diff(-1, 0);

          // determine which residual equation is involved, and seek all variables referencing this equation
          iRes = iEqn - m_nLocalEqns;
          iResMin = 0;
          nItems = 0;
          iVarColor = 0;
          for (iDistEqn = 0; iDistEqn < m_nLocalDistEqns; iDistEqn++)
          {
            // find the iDistEqn that will calculate iRes
            iResMax = iResMin + m_LocalDistEqnResCount[iDistEqn] - 1;
            if (iRes <= iResMax)
            {
              // reset the AD variable coloring
              for (j = 0; j < m_varC.nADVars; j++) m_ad_x_color[j] = -1;
            
              // while within the same iDistEqn, color the referenced variables
              for (j = i; j < nJac; j++)
              {
                iResTest = iJac[2*j] - m_nLocalEqns;
                if (iResTest >= iResMin && iResTest <= iResMax)
                {
                  nItems++;
                  iVar = iJac[2*j+1];
                  if (m_ad_x_color[iVar] < 0)
                    m_ad_x_color[iVar] = iVarColor++;
                }
                else
                  break;
              }
              // count the colored variables
              for (j = 0, nVar = 0; j < m_varC.nADVars; j++) if (m_ad_x_color[j] >= 0) nVar++;
              break;
            }
            iResMin += m_LocalDistEqnResCount[iDistEqn];
          }

          // end distributed equations
        }
        else if (m_nLocalStlEqns > 0)
        {
          // begin stl equations

          // Have multiple residuals associated with one function.  
          // Need to initialize all variables to write their outputs to a given unique slot.
          // After the function is called, read the residuals back for each variable from the designated slots.

          // reset the residuals for all distributed equation vars
          for (j = 0; j < m_nLocalStlEqns; j++)
          {
            for (k = 0; k < m_LocalStlADEqnVars[j]->size(); k++)
              m_LocalStlADEqnVars[j]->_Ptr[k].diff(-1, 0);
          }

          // determine which residual equation is involved, and seek all variables referencing this equation
          iRes = iEqn - m_nLocalEqns;
          iResMin = 0;
          nItems = 0;
          iVarColor = 0;
          for (iStlEqn = 0; iStlEqn < m_nLocalStlEqns; iStlEqn++)
          {
            // find the iStlEqn that will calculate iRes
            iResMax = iResMin + m_LocalStlEqnResCount[iStlEqn] - 1;
            if (iRes <= iResMax)
            {
              // reset the AD variable coloring
              for (j = 0; j < m_varC.nADVars; j++) m_ad_x_color[j] = -1;
            
              // while within the same iStlEqn, color the referenced variables
              for (j = i; j < nJac; j++)
              {
                iResTest = iJac[2*j] - m_nLocalEqns;
                if (iResTest >= iResMin && iResTest <= iResMax)
                {
                  nItems++;
                  iVar = iJac[2*j+1];
                  if (m_ad_x_color[iVar] < 0)
                    m_ad_x_color[iVar] = iVarColor++;
                }
                else
                  break;
              }
              // count the colored variables
              for (j = 0, nVar = 0; j < m_varC.nADVars; j++) if (m_ad_x_color[j] >= 0) nVar++;
              break;
            }
            iResMin += m_LocalStlEqnResCount[iStlEqn];
          }

          // end stl equations
        }
      }

      // reset the derivative vectors of all AD vars (I suspect there is a simplification)
      for (j = 0; j < m_varC.nADVars; j++) 
      {
        m_varC.FVars[j]->diff(-1, 0);
        m_varC.derFVars[j]->diff(-1, 0);
      }

      if (iEqn < m_nLocalEqns)
      {
        // mark only those variables for which the jacobian should be calculated
        for (j = 0; j < nItems; j++)
        {
          iVar = iJac[2*(i+j)+1];
          if (iVar < m_varC.nADVars) 
            m_varC.FVars[iVar]->diff(j, nVar);
        }
      }
      else
      {
        for (iVar = 0; iVar < m_varC.nADVars; iVar++)
        {
          iVarColor = m_ad_x_color[iVar];
          if (m_ad_x_color[iVar] >= 0)
            m_varC.FVars[iVar]->diff(iVarColor, nVar);
        }
      }

      if (iEqn < m_nLocalEqns)
      {
        // call the equation
        #ifdef _ONI_FCN_BYREF
          hr = (pT->*(m_LocalADEqns[iEqn]))(res);
        #else
          hr = (pT->*(m_LocalADEqns[iEqn]))(&res);
        #endif
      }
      else
      {
        if (m_nLocalDistADEqns > 0)
          hr = (pT->*(m_LocalDistADEqns[iDistEqn]))();
        else if (m_nLocalStlADEqns > 0)
          hr = (pT->*(m_LocalStlADEqns[iStlEqn]))( m_LocalStlADEqnVars[iStlEqn] );
      }

      if (iEqn < m_nLocalEqns)
      {
        // record the jacobian results
        for (j = 0; j < nVar; j++) jacobians[i+j] = res.d(j);

        // reset the residual vector
        res.diff(-1, 0);
      }
      else
      {
        if (m_nLocalDistADEqns > 0)
        {
          // record the jacobian results
          for (j = 0; j < nItems; j++)
          {
            iEqn = iJac[2*(i+j)] - m_nLocalEqns - iResMin;
            iVar = iJac[2*(i+j)+1];
            iVarColor = m_ad_x_color[iVar];
            jacobians[i+j] = m_LocalDistADEqnVars[iDistEqn]->pVal[iEqn].d(iVarColor);
          }
          // residual vector reset above
        }
        else if (m_nLocalStlADEqns > 0)
        {
          // record the jacobian results
          for (j = 0; j < nItems; j++)
          {
            iEqn = iJac[2*(i+j)] - m_nLocalEqns - iResMin;
            iVar = iJac[2*(i+j)+1];
            iVarColor = m_ad_x_color[iVar];
            jacobians[i+j] = m_LocalStlADEqnVars[iStlEqn]->_Ptr[iEqn].d(iVarColor);
          }
          // residual vector reset above
        }
      }

      // increment i past the number of jacobians calculated above
      iEqn = iJac[2*i];
      if (iEqn < m_nLocalEqns)
        i += nVar;
      else
        i += nItems;
    }

    return hr;
  }


  HRESULT GetDiffJacobianValues(
    long* iJac, 
    long nJac, 
    double t, 
    double* jacobians)
  {
    HRESULT hr = S_OK;
	  long i, j, k;
    long iEqn, iVar, nVar, iVarColor, nItems;
    long iDistEqn, iStlEqn, iRes, iResTest, iResMin, iResMax;
    T* pT = static_cast<T*>(this);

	  Fdouble res;
    m_time = t;
    i = 0;
    while ( (i < nJac) && SUCCEEDED(hr) )
    {
      // read the equation and variable index from the iJac[] vector
      iEqn = iJac[2*i];
      iVar = iJac[2*i+1];

      
      if (iEqn < m_nLocalEqns)
      {
        // count the number of jacobians being sought for the current equation
        nVar = 0;
        nItems = 0;
        //for (j = i; (iEqn == iJac[2*j]) && (j < nJac) && (j == i || iVar != iJac[2*j+1]); j++)
        for (j = i; j < nJac; j++)
        {
          if (iEqn != iJac[2*j]) break;
          nItems++;
          nVar++;
        }
      }
      else
      {

        if (m_nLocalDistADEqns > 0)
        {

          // Have multiple residuals associated with one function.  
          // Need to initialize all variables to write their outputs to a given unique slot.
          // After the function is called, read the residuals back for each variable from the designated slots.

          // reset the residuals for all distributed equation vars
          for (j = 0; j < m_nLocalDistEqns; j++)
            m_LocalDistADEqnVars[j]->diff(-1, 0);

          // determine which residual equation is involved, and seek all variables referencing this equation
          iRes = iEqn - m_nLocalEqns;
          iResMin = 0;
          nItems = 0;
          iVarColor = 0;
          for (iDistEqn = 0; iDistEqn < m_nLocalDistEqns; iDistEqn++)
          {
            // find the iDistEqn that will calculate iRes
            iResMax = iResMin + m_LocalDistEqnResCount[iDistEqn] - 1;
            if (iRes <= iResMax)
            {
              // reset the AD variable coloring
              for (j = 0; j < m_varC.nADVars; j++) m_ad_x_color[j] = -1;
            
              // while within the same iDistEqn, color the referenced variables
              for (j = i; j < nJac; j++)
              {
                iResTest = iJac[2*j] - m_nLocalEqns;
                if (iResTest >= iResMin && iResTest <= iResMax)
                {
                  nItems++;
                  iVar = iJac[2*j+1];
                  if (m_ad_x_color[iVar] < 0)
                    m_ad_x_color[iVar] = iVarColor++;
                }
                else
                  break;
              }
              // count the colored variables
              for (j = 0, nVar = 0; j < m_varC.nADVars; j++) if (m_ad_x_color[j] >= 0) nVar++;
              break;
            }
            iResMin += m_LocalDistEqnResCount[iDistEqn];
          }
        }
        else if (m_nLocalStlADEqns > 0)
        {
          // Have multiple residuals associated with one function.  
          // Need to initialize all variables to write their outputs to a given unique slot.
          // After the function is called, read the residuals back for each variable from the designated slots.

          // reset the residuals for all distributed equation vars
          for (j = 0; j < m_nLocalStlEqns; j++)
          {
            for (k = 0; k < m_LocalStlADEqnVars[j]->size(); k++)
              m_LocalStlADEqnVars[j]->_Ptr[k].diff(-1, 0);
          }

          // determine which residual equation is involved, and seek all variables referencing this equation
          iRes = iEqn - m_nLocalEqns;
          iResMin = 0;
          nItems = 0;
          iVarColor = 0;
          for (iStlEqn = 0; iStlEqn < m_nLocalStlEqns; iStlEqn++)
          {
            // find the iStlEqn that will calculate iRes
            iResMax = iResMin + m_LocalStlEqnResCount[iStlEqn] - 1;
            if (iRes <= iResMax)
            {
              // reset the AD variable coloring
              for (j = 0; j < m_varC.nADVars; j++) m_ad_x_color[j] = -1;
            
              // while within the same iStlEqn, color the referenced variables
              for (j = i; j < nJac; j++)
              {
                iResTest = iJac[2*j] - m_nLocalEqns;
                if (iResTest >= iResMin && iResTest <= iResMax)
                {
                  nItems++;
                  iVar = iJac[2*j+1];
                  if (m_ad_x_color[iVar] < 0)
                    m_ad_x_color[iVar] = iVarColor++;
                }
                else
                  break;
              }
              // count the colored variables
              for (j = 0, nVar = 0; j < m_varC.nADVars; j++) if (m_ad_x_color[j] >= 0) nVar++;
              break;
            }
            iResMin += m_LocalStlEqnResCount[iStlEqn];
          }

        }
      }

      // reset the derivative vectors of all AD vars (I suspect there is a simplification)
      for (j = 0; j < m_varC.nADVars; j++) 
      {
        m_varC.FVars[j]->diff(-1, 0);
        m_varC.derFVars[j]->diff(-1, 0);
      }

      if (iEqn < m_nLocalEqns)
      {
        // mark only those variables for which the jacobian should be calculated
        for (j = 0; j < nItems; j++)
        {
          iVar = iJac[2*(i+j)+1];
          if (iVar < m_varC.nADVars) 
            m_varC.derFVars[iVar]->diff(j, nVar);
        }
      }
      else
      {
        for (iVar = 0; iVar < m_varC.nADVars; iVar++)
        {
          iVarColor = m_ad_x_color[iVar];
          if (m_ad_x_color[iVar] >= 0)
            m_varC.derFVars[iVar]->diff(iVarColor, nVar);
        }
      }

      if (iEqn < m_nLocalEqns)
      {
        // call the equation
        #ifdef _ONI_FCN_BYREF
          hr = (pT->*(m_LocalADEqns[iEqn]))(res);
        #else
          hr = (pT->*(m_LocalADEqns[iEqn]))(&res);
        #endif
      }
      else
      {
        if (m_nLocalDistADEqns > 0)
          hr = (pT->*(m_LocalDistADEqns[iDistEqn]))();
        else
          hr = (pT->*(m_LocalStlADEqns[iStlEqn]))( m_LocalStlADEqnVars[iStlEqn] );
      }

      if (iEqn < m_nLocalEqns)
      {
        // record the jacobian results
        for (j = 0; j < nVar; j++) jacobians[i+j] = res.d(j);

        // reset the residual vector
        res.diff(-1, 0);
      }
      else
      {
        if (m_nLocalDistADEqns > 0)
        {
          // record the jacobian results
          for (j = 0; j < nItems; j++)
          {
            iEqn = iJac[2*(i+j)] - m_nLocalEqns - iResMin;
            iVar = iJac[2*(i+j)+1];
            iVarColor = m_ad_x_color[iVar];
            jacobians[i+j] = m_LocalDistADEqnVars[iDistEqn]->pVal[iEqn].d(iVarColor);
          }
          // residual vector reset above
        }
        else if (m_nLocalStlADEqns > 0)
        {
          // record the jacobian results
          for (j = 0; j < nItems; j++)
          {
            iEqn = iJac[2*(i+j)] - m_nLocalEqns - iResMin;
            iVar = iJac[2*(i+j)+1];
            iVarColor = m_ad_x_color[iVar];
            jacobians[i+j] = m_LocalStlADEqnVars[iStlEqn]->_Ptr[iEqn].d(iVarColor);
          }
          // residual vector reset above
        }
      }

      // increment i past the number of jacobians calculated above
      iEqn = iJac[2*i];
      if (iEqn < m_nLocalEqns)
        i += nVar;
      else
        i += nItems;
    }

    return hr;
  }



protected:
  // normal residual equation pointers
  residual_eqn* m_LocalEqns;
  ad_residual_eqn* m_LocalADEqns;
  // distributed residual equation pointers
  dist_residual_eqn* m_LocalDistEqns;
  ad_dist_residual_eqn* m_LocalDistADEqns;
  // stl residual equation pointers
  stl_residual_eqn* m_LocalStlEqns;
  ad_stl_residual_eqn* m_LocalStlADEqns;

};

#endif // _ON_UML_DAE_ESO_BASE_IMPL_