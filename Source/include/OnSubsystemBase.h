#ifndef _OnSubsystemBase_h_
#define _OnSubsystemBase_h_

//#include <stdafx.h>
#include "OnUMLEso.h"
#ifdef _ORIGINAL_
#include "fstream.h"
#else
#include <fstream>
#endif
#include "OnModelBase.h"


template <class TC>
class COnSubsystemBase : public IOnModelExecEvents, public COnModelBase
{
  
public:

  COnSubsystemBase() : m_cRef(0), m_pModel(NULL), m_pModelExec(NULL), 
    m_pdw(NULL), nVars(0), psaVarVals(NULL), varVals(NULL), m_pSystemModel(NULL)
  { 
    baseInit();
  } 

  ~COnSubsystemBase()
  {
    baseClean();
  }

  ULONG STDMETHODCALLTYPE AddRef()
  {
    return ++m_cRef;
  }

  ULONG STDMETHODCALLTYPE Release()
  {
    m_cRef--;
    if (m_cRef <= 0) delete this;
    return m_cRef;
  }

  virtual HRESULT STDMETHODCALLTYPE QueryInterface(
    REFIID riid, 
    void** ppvObject)
  {
    HRESULT hr = E_FAIL;
    if (riid == IID_IOnModelExecEvents)
    {
      *ppvObject = static_cast<IOnModelExecEvents*> (this);
      AddRef();
      hr = S_OK;
    }
    return hr;
  }

  virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(
    REFIID riid, 
    LPOLESTR* rgszNames, 
    UINT cNames, 
    LCID lcid, 
    DISPID* rgDispId) { return E_NOTIMPL; }

  virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(
    UINT iTInfo, 
    LCID lcid, 
    ITypeInfo** ppTInfo) { return E_NOTIMPL; }

  virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(
    UINT*  pctinfo) { return E_NOTIMPL; }

  virtual HRESULT STDMETHODCALLTYPE Invoke(
    DISPID dispIdMember, 
    REFIID riid, 
    LCID lcid, 
    WORD wFlags, 
    DISPPARAMS* pDispParams, 
    VARIANT* pVarResult, 
    EXCEPINFO* pExcepInfo, 
    UINT* puArgErr) { return E_NOTIMPL; }

  virtual bool Load(const BSTR  filename) 
  {
    if (SUCCEEDED( m_pModelExec->Load(filename) ))
      return true;
    else
      return false;
  }

  virtual void Save(const BSTR  filename) 
  { 
    m_pModelExec->Save(filename);
  }


  // IOnModelExecEvents
  virtual HRESULT STDMETHODCALLTYPE BeforeRParEvent( 
    double Time,
    long iGlobalId,
    double Value) 
  { 
    //fs << "BeforeRParEvent" << "\t" << Time << "\t" << iGlobalId << "\t" << Value << "\n";
    //printData(Time, L"evRPar");  
    return S_OK; 
  }
        
  virtual HRESULT STDMETHODCALLTYPE BeforeIParEvent( 
    double Time,
    long iGlobalId,
    long Value) 
  {
    //fs << "BeforeIParEvent" << "\t" << Time << "\t" << iGlobalId << "\t" << Value << "\n";
    //printData(Time, L"evIPar");  
    return S_OK; 
  }
        
  virtual HRESULT STDMETHODCALLTYPE BeforeStateEvent( 
    double Time,
    BSTR EvId,
    long iEvEqn)
  { 
#if 1 // temporary
    USES_CONVERSION;
    fs << "BeforeStateEvent" << "\t" << Time << "\t" << W2CA(EvId) << "\t" << iEvEqn << "\n";
    printData(Time, L"evState");  
#endif
    return S_OK; 
  }
        
  virtual HRESULT STDMETHODCALLTYPE AfterRParEvent( 
    double Time,
    long iGlobalId,
    double Value)
  { 
    //fs << "AfterRParEvent" << "\t" << Time << "\t" << iGlobalId << "\t" << Value << "\n";
    //printData(Time, L"evRPar");  
    return S_OK; 
  }
        
  virtual HRESULT STDMETHODCALLTYPE AfterIParEvent( 
    double Time,
    long iGlobalId,
    long Value)
  { 
    //fs << "AfterIParEvent" << "\t" << Time << "\t" << iGlobalId << "\t" << Value << "\n";
    //printData(Time, L"evIPar");  
    return S_OK; 
  }

  virtual HRESULT STDMETHODCALLTYPE AfterStateEvent( 
    double Time,
    BSTR EvId,
    long iEvEqn)
  { 
#if 1 // temporary
    USES_CONVERSION;
    fs << "AfterStateEvent" << "\t" << Time << "\t" << W2CA(EvId) << "\t" << iEvEqn << "\n";
    printData(Time, L"evState");  
#endif
    return S_OK; 
  }
        
  virtual HRESULT STDMETHODCALLTYPE InitializationInfo( 
    VARIANT_BOOL fault,
    long stage,
    long nModelEqns,
    long nModelVars,
    long nActiveEqns,
    long nActiveVars,
    long nAugmentedEqns,
    long nAugmentedVars,
    SAFEARRAY** EqnNames,
    SAFEARRAY** VarNames,
    long nColIndices,
    SAFEARRAY** cNZCols,
    SAFEARRAY** spRowPage,
    SAFEARRAY** ColIndices,
    SAFEARRAY** EqnOrder,
    SAFEARRAY** VarOrder,
    SAFEARRAY** VAL,
    SAFEARRAY** EAL,
    SAFEARRAY** AssignedEqn,
    SAFEARRAY** VarVals,
    SAFEARRAY** VarDotVals,
    SAFEARRAY** ResVals) { return S_OK; }
        
  virtual HRESULT STDMETHODCALLTYPE GetTrimEqns( 
    long* nEqns,
    long* nColIndices,
    SAFEARRAY** cNZCols,
    SAFEARRAY** spRowPage,
    SAFEARRAY** ColIndices) { return S_OK; }
        
  virtual HRESULT STDMETHODCALLTYPE GetTrimVars( 
    long* nVars,
    SAFEARRAY** VarIds,
    SAFEARRAY** VarVals) { return S_OK; }

  virtual HRESULT STDMETHODCALLTYPE SetVariables( 
    SAFEARRAY** VarVals) { return S_OK; }

  virtual HRESULT STDMETHODCALLTYPE GetResiduals( 
    long nEqns,
    SAFEARRAY** EqnIds,
    SAFEARRAY** Residuals) { return S_OK; }

  virtual HRESULT STDMETHODCALLTYPE SetResiduals( 
    SAFEARRAY** ResVals) { return S_OK; }

  virtual HRESULT STDMETHODCALLTYPE ShowDialog( 
    BSTR msg) { return S_OK; }

  virtual void handle_tick() 
  {
    receive();
    const double t = getTime();
  
    HRESULT hr = m_pModelExec->Step(t);
    if (FAILED(hr)) 
    {
      m_pModelExec->ForceReset();
      hr = m_pModelExec->Step(t);
      _ASSERTE(hr == S_OK);
    }
  
    printData(t, L"tick");
    broadcast();
  }

  virtual void baseInit() 
  {
    IIsDaeEsoCImpl* pEso = NULL;
    long nVars = 0;
    HRESULT hr = S_OK;
    
    CoInitialize(NULL);
    hr = CoCreateInstance(CLSID_OnModelExec, NULL, CLSCTX_INPROC_SERVER, IID_IOnModelExec, (void**) &m_pModelExec);
    _ASSERTE(hr == S_OK);
    m_pModelExec->HandleInitEvents();
    hr = CoCreateInstance(CLSID_IsDaeEsoCImpl, NULL, CLSCTX_INPROC_SERVER, IID_IIsDaeEsoCImpl, (void**) &m_pModel);
    _ASSERTE(hr == S_OK);
    m_pSystemModel = new TC();
    m_pModel->SetEso( reinterpret_cast<IUnknown*> (m_pSystemModel) );
    hr = m_pModelExec->SetModel(m_pModel);
    _ASSERTE(hr == S_OK);
    
    // event interface initialization
    IOnModelExecEvents* pEventIF = static_cast<IOnModelExecEvents*> (this);
    AtlAdvise(m_pModelExec, pEventIF, IID_IOnModelExecEvents, &m_pdw);
    
    // time initialization
    m_pModel->InitTime(0.0, VARIANT_FALSE);
    // end time initialization

    initSimulation();
  }

  void initSimulation() 
  {
    HRESULT hr = S_OK;
    SAFEARRAY* psaVarNames = NULL;
    BSTR* varNames = NULL;
    
    psaVarVals = NULL;
    varVals = NULL;
    
    USES_CONVERSION;

#if 1 // temporary
    // record data to file
    long i;
    fs.open("Subsystem.txt");
#endif
    m_pModel->GetNumVars(&nVars);
    psaVarVals = SafeArrayCreateVector(VT_R8, 0, nVars);
    SafeArrayAccessData(psaVarVals, (void HUGEP* FAR*)& varVals);
    
    m_pModel->GetVarNames(&psaVarNames);
    SafeArrayAccessData(psaVarNames, (void HUGEP* FAR*)& varNames);

#if 1 // temporary    
    fs << "time" << "\t" << "label" << "\t";
    for (i = 0; i < nVars; i++)
    {
      if (varNames[i])
        fs << W2CA(varNames[i]) << "\t";
      else
        fs << "\t";
    }
    fs << "\n";
#endif

    SafeArrayUnaccessData(psaVarNames);
    SafeArrayDestroy(psaVarNames);
    psaVarNames = NULL;
    varNames = NULL;
  }

  virtual void baseClean() 
  {
    if (m_pModelExec)
    {
      AtlUnadvise(m_pModelExec, IID_IOnModelExecEvents, m_pdw);
      m_pModelExec->SetModel(NULL);
      m_pModelExec->Release();
      m_pModelExec = NULL;
    }
    
    if (m_pModel)
    {
      m_pModel->Release();
      m_pModel = NULL;
    }
    
    CoUninitialize();

    termSimulation();
  }


  virtual void printData(const double t, _TCHAR* label) 
  {
#if 1 // temporary
    long i;
    USES_CONVERSION;

    m_pModel->GetAllVariables( t, &psaVarVals );
    fs << t << "\t" << W2CA(label) << "\t";
    for (i = 0; i < nVars; i++)
      fs << varVals[i] << "\t";
    
    fs << "\n";
#endif
  }

  void termSimulation() 
  {
    if (psaVarVals)
    {
      SafeArrayUnaccessData(psaVarVals);
      SafeArrayDestroy(psaVarVals);
      psaVarVals = NULL;
      varVals = NULL;
    }
#if 1 // temporary
    fs.close();
#endif
  }

public:  
  TC* m_pSystemModel;
  IIsDaeEsoCImpl* m_pModel;
  IOnModelExec* m_pModelExec;

protected:
#if 1 // temporary
  std::ofstream fs;
#endif
  long m_cRef;
  DWORD m_pdw;
  long nVars;
  SAFEARRAY* psaVarVals;
  double* varVals;
};

#endif // _OnSubsystemBase_h_