#if !defined(AFX_EVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_)
#define AFX_EVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_

#include "CommonTools.h"
#include "OnModelBase.h"

template <class A>
class COnBroadcaster;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*

ONI_BEGIN_BROADCAST_MAP(ARGTYPE)
ONI_BEGIN_EVENT_BROADCAST_MAP()
ONI_SCALAR_BROADCASTER_IMPL(SOURCE_COMPOSITE_OBJECT, SOURCE_OBJECT, SOURCE_ATTR)
ONI_VECTOR_BROADCASTER_IMPL(NAME, SOURCE_COMPOSITE_OBJECT, SOURCE_ATTR, SOURCE_ATTR_SIZE)
ONI_FCN_BROADCASTER_IMPL(SOURCE_COMPOSITE_OBJECT, SOURCE_CLASS, SOURCE_OBJECT, SOURCE_FUNCTION)
ONI_BROADCASTER_ENTRY(SOURCE_BROADCASTER)
ONI_EVENT_BROADCASTER_IMPL(SOURCE_COMPOSITE_OBJECT)
ONI_EVENT_BROADCASTER_ENTRY(SOURCE_BROADCASTER)
ONI_EVENT_LISTENER_IMPL(TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT)
ONI_EVENT_LISTENER_ENTRY(TARGET_LISTENER)
ONI_OPER_LISTENER_IMPL(TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_OP)
ONI_ATTR_LISTENER_IMPL(TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_ATTR)
ONI_LISTENER_ENTRY(TARGET_LISTENER)
ONI_DATACOLLECTOR_IMPL(NAME, SOURCE_CONTAINER_OBJECT, SOURCE_MODEL_OBJECT, VARIABLE)
ONI_DATACOLLECTOR_ENTRY(SOURCE_DATACOLLECTOR)
ONI_BEGIN_DATACOLLECTOR_IMPL(NAME, SOURCE_CONTAINER_OBJECT, SOURCE_MODEL_OBJECT)
ONI_VAR(VARIABLE)
ONI_END_DATACOLLECTOR_IMPL()
ONI_OPER_LISTENER_IMPL_DC(TARGET_CONTAINER_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_OP)
ONI_ATTR_LISTENER_IMPL_DC(TARGET_CONTAINER_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_ATTR)
ONI_END_BROADCAST_MAP()
ONI_END_EVENT_BROADCAST_MAP()

*/
// 

/*
#define ONI_DATACOLLECTOR_MAP(NAME, SOURCE_COMPOSITE_OBJECT, SOURCE_MODEL_OBJECT, VARIABLE, TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_OP_OR_ATTR) \
{ \
  COnDataCollector* _OniDataSource = new COnDataCollector(L#NAME, SOURCE_MODEL_OBJECT); \
  SOURCE_COMPOSITE_OBJECT->AddBroadcaster(_OniDataSource); \
  _OniDataSource->setOwner(SOURCE_COMPOSITE_OBJECT); \
  _TCHAR* varList[] = { L#VARIABLE }; \
  _OniDataSource->SetVariables(varList, 1); \
  COnListener<TARGET_CLASS, double>* pL = \
    new COnListener<TARGET_CLASS, double>(TARGET_OBJECT, &TARGET_CLASS::TARGET_OP_OR_ATTR); \
  TARGET_COMPOSITE_OBJECT->AddListener(pL); \
  pL->setOwner(TARGET_COMPOSITE_OBJECT); \
  _OniDataSource->Advise(pL); \
}
*/

#define ONI_BEGIN_BROADCAST_MAP(ARGTYPE) \
{ \
  typedef ARGTYPE _ONI_ARGTYPE;

#define ONI_BEGIN_EVENT_BROADCAST_MAP() {

#define ONI_SCALAR_BROADCASTER_IMPL(SOURCE_COMPOSITE_OBJECT, SOURCE_OBJECT, SOURCE_ATTR) \
  COnBroadcaster<_ONI_ARGTYPE>* _OniDataSource = \
    new COnBroadcaster<_ONI_ARGTYPE>(&SOURCE_OBJECT->SOURCE_ATTR); \
  SOURCE_COMPOSITE_OBJECT->AddBroadcaster(_OniDataSource); \
  _OniDataSource->setOwner(SOURCE_COMPOSITE_OBJECT); 

#define ONI_VECTOR_BROADCASTER_IMPL(NAME, SOURCE_COMPOSITE_OBJECT, SOURCE_OBJECT, SOURCE_ATTR, SOURCE_ATTR_SIZE) \
  COnBroadcaster<_ONI_ARGTYPE>* _OniDataSource = \
    new COnBroadcaster<_ONI_ARGTYPE>(L#NAME, &SOURCE_OBJECT->SOURCE_ATTR, SOURCE_ATTR_SIZE); \
  SOURCE_COMPOSITE_OBJECT->AddBroadcaster(_OniDataSource); \
  _OniDataSource->setOwner(SOURCE_COMPOSITE_OBJECT); 

#define ONI_FCN_BROADCASTER_IMPL(SOURCE_COMPOSITE_OBJECT, SOURCE_CLASS, SOURCE_OBJECT, SOURCE_FUNCTION) \
  COnBroadcasterFcn<SOURCE_CLASS, _ONI_ARGTYPE>* _OniDataSource = \
    new COnBroadcasterFcn<SOURCE_CLASS, _ONI_ARGTYPE>(SOURCE_OBJECT, &SOURCE_CLASS::SOURCE_FUNCTION); \
  SOURCE_COMPOSITE_OBJECT->AddBroadcaster(_OniDataSource); \
  _OniDataSource->setOwner(SOURCE_COMPOSITE_OBJECT); 

#define ONI_BROADCASTER_ENTRY(SOURCE_BROADCASTER) \
  COnBroadcaster<_ONI_ARGTYPE>* _OniDataSource = SOURCE_BROADCASTER;

#define ONI_EVENT_BROADCASTER_IMPL(SOURCE_COMPOSITE_OBJECT) \
  COnEventBroadcaster* _OniEventSource = \
    new COnEventBroadcaster(); \
  SOURCE_COMPOSITE_OBJECT->AddBroadcaster(_OniEventSource); \
  _OniEventSource->setOwner(SOURCE_COMPOSITE_OBJECT);

#define ONI_EVENT_BROADCASTER_ENTRY(SOURCE_BROADCASTER) \
  COnEventBroadcaster* _OniEventSource = SOURCE_BROADCASTER;


#define ONI_EVENT_LISTENER_IMPL(TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT) \
{ \
  COnEventListener<TARGET_CLASS>* pL = \
    new COnEventListener<TARGET_CLASS>(TARGET_OBJECT); \
  TARGET_COMPOSITE_OBJECT->AddListener(pL); \
  _OniEventSource->Advise(pL); \
  pL->setOwner(TARGET_COMPOSITE_OBJECT); \
}

#define ONI_EVENT_LISTENER_ENTRY(TARGET_LISTENER) _OniEventSource->Advise(TARGET_LISTENER);

#define ONI_OPER_LISTENER_IMPL(TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_OP) \
{ \
  COnListener<TARGET_CLASS, _ONI_ARGTYPE>* pL = \
    new COnListener<TARGET_CLASS, _ONI_ARGTYPE>(TARGET_OBJECT, &TARGET_CLASS::TARGET_OP); \
  TARGET_COMPOSITE_OBJECT->AddListener(pL); \
  pL->setOwner(TARGET_COMPOSITE_OBJECT); \
  _OniDataSource->Advise(pL); \
}

#define ONI_ATTR_LISTENER_IMPL(TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_ATTR) \
{ \
  COnListener<TARGET_CLASS, _ONI_ARGTYPE>* pL = \
    new COnListener<TARGET_CLASS, _ONI_ARGTYPE>(TARGET_OBJECT, &TARGET_OBJECT->TARGET_ATTR); \
  TARGET_COMPOSITE_OBJECT->AddListener(pL); \
  pL->setOwner(TARGET_COMPOSITE_OBJECT); \
  _OniDataSource->Advise(pL); \
}


#define ONI_LISTENER_ENTRY(TARGET_LISTENER) _OniDataSource->Advise(TARGET_LISTENER);

#define ONI_DATACOLLECTOR_IMPL(NAME, SOURCE_CONTAINER_OBJECT, SOURCE_MODEL_OBJECT, VARIABLE) \
  COnDataCollector* _OniDataSource = new COnDataCollector(L#NAME, SOURCE_MODEL_OBJECT); \
  SOURCE_CONTAINER_OBJECT->AddBroadcaster(_OniDataSource); \
  _OniDataSource->setOwner(SOURCE_CONTAINER_OBJECT); \
  _TCHAR* varList[] = { L#VARIABLE }; \
  long _OniVectorSize = sizeof(varList) / sizeof(_TCHAR*); \
  _OniDataSource->SetVariables(varList, _OniVectorSize);

#define ONI_DATACOLLECTOR_ENTRY(SOURCE_DATACOLLECTOR) COnDataCollector* _OniDataSource = SOURCE_DATACOLLECTOR;


#define ONI_BEGIN_DATACOLLECTOR_IMPL(NAME, SOURCE_CONTAINER_OBJECT, SOURCE_MODEL_OBJECT) \
  COnDataCollector* _OniDataSource = new COnDataCollector(L#NAME, SOURCE_MODEL_OBJECT); \
  SOURCE_CONTAINER_OBJECT->AddBroadcaster(_OniDataSource); \
  _OniDataSource->setOwner(SOURCE_CONTAINER_OBJECT); \
  _TCHAR* varList[] = { 

#define ONI_VAR(VARIABLE) L#VARIABLE
 
#define ONI_END_DATACOLLECTOR_IMPL() \
  }; \
  long _OniVectorSize = sizeof(varList) / sizeof(_TCHAR*); \
  _OniDataSource->SetVariables(varList, _OniVectorSize);

#define ONI_OPER_LISTENER_IMPL_DC(TARGET_CONTAINER_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_OP) \
{ \
  COnListener<TARGET_CLASS, _ONI_ARGTYPE>* pL = \
    new COnListener<TARGET_CLASS, _ONI_ARGTYPE>(TARGET_OBJECT, &TARGET_CLASS::TARGET_OP); \
  TARGET_CONTAINER_OBJECT->AddListener(pL); \
  pL->setOwner(TARGET_CONTAINER_OBJECT); \
  _OniDataSource->Advise(pL); \
}

#define ONI_ATTR_LISTENER_IMPL_DC(TARGET_CONTAINER_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_ATTR) \
{ \
  COnListener<TARGET_CLASS, _ONI_ARGTYPE>* pL = \
    new COnListener<TARGET_CLASS, _ONI_ARGTYPE>(TARGET_OBJECT, &TARGET_OBJECT->TARGET_ATTR); \
  TARGET_CONTAINER_OBJECT->AddListener(pL); \
  pL->setOwner(TARGET_CONTAINER_OBJECT); \
  _OniDataSource->Advise(pL); \
}


#define ONI_END_BROADCAST_MAP() }

#define ONI_END_EVENT_BROADCAST_MAP() }

//=============================================================================================
//
// IOnListener interface
//
//=============================================================================================
class IOnListener
{
public:
  virtual long AddRef() = 0;
  virtual long Release() = 0;
  virtual bool receive() = 0;
  virtual void gen() = 0;
  virtual void clean() = 0;
  virtual long GetCookie() = 0;
  virtual void SetCookie(long cookie) = 0; 
  virtual void setOwner(COnModelBase* pOwner) = 0;
  virtual void SetMutex(HANDLE hMutex) = 0;
};


template <class A>
class IOnListenerEx : public IOnListener
{
public:
  virtual void SetSource(A* pSrc, long size) = 0;
};



//=============================================================================================
//
// COnListener event listener
//
//=============================================================================================

template <class T, class A> 
class COnListener : public IOnListenerEx<A> 
{
public:
  typedef void (T::*setScalar)(A vec);
  typedef void (T::*setVector)(A* vec);
  typedef void (T::*setSVector)(A* vec, long size);
  typedef void (T::*setTVector)(const double t, A* vec);
  typedef void (T::*setTSVector)(const double t, A* vec, long size);

#define CONLISTENER_CONSTRUCTOR_BASE \
  m_cRef(0), m_cookie(-1), m_pObj(NULL), m_bDataChanged(false), \
  m_pSFcn(NULL), m_pVFcn(NULL), m_pSVFcn(NULL), m_pTVFcn(NULL), m_pTSVFcn(NULL), m_pSrc(NULL), m_size(0), \
  m_ppTarget(NULL), m_pTarget(NULL), m_hMutex(NULL), m_pOwner(NULL), bNoReceive(false)

  COnListener(T* obj, setScalar fcn) : CONLISTENER_CONSTRUCTOR_BASE
  {
    m_pObj = obj;
    m_pSFcn = fcn;
  }

  COnListener(T* obj, setVector fcn) : CONLISTENER_CONSTRUCTOR_BASE
  {
    m_pObj = obj;
    m_pVFcn = fcn;
  }

  COnListener(T* obj, setSVector fcn) : CONLISTENER_CONSTRUCTOR_BASE
  {
    m_pObj = obj;
    m_pSVFcn = fcn;
  }

  COnListener(T* obj, setTVector fcn) : CONLISTENER_CONSTRUCTOR_BASE
  {
    m_pObj = obj;
    m_pTVFcn = fcn;
  }

  COnListener(T* obj, setTSVector fcn) : CONLISTENER_CONSTRUCTOR_BASE
  {
    m_pObj = obj;
    m_pTSVFcn = fcn;
  }

  COnListener(T* obj, A** ppTarget) : CONLISTENER_CONSTRUCTOR_BASE
  {
    m_pObj = obj;
    m_ppTarget = ppTarget;
  }

  COnListener(T* obj, A* pTarget) : CONLISTENER_CONSTRUCTOR_BASE
  {
    m_pObj = obj;
    m_pTarget = pTarget;
  }

  void clean()
  {
    m_pObj = NULL;
    m_pOwner = NULL;
  }

  void setOwner(COnModelBase* pOwner)
  {
    m_pOwner = pOwner;
  }

  void SetMutex(HANDLE hMutex)
  {
    m_hMutex = hMutex;
  }

  void SetSource(A* pSrc, long size)
  {
    if (pSrc == NULL)
    {
      bNoReceive = true;
    }
    else
    {
      m_pSrc = pSrc;
      m_size = size;
      if (m_ppTarget)
      {
        if (*m_ppTarget = NULL) *m_ppTarget = new A[m_size];
      }
      m_bDataChanged = true;
    }
  }

  long AddRef() 
  { 
    return ++m_cRef; 
  }

  long Release() 
  { 
    m_cRef--; 
    if (m_cRef <= 0) 
      delete this; 
    
    return m_cRef; 
  }

  long GetCookie()
  { 
    return m_cookie;
  }

  void SetCookie(long cookie) 
  { 
    m_cookie = cookie; 
  }

  // enables propagating events via handler functions
  void gen()
  {
    updateTarget();
  }

  bool receive()
  {
    if (!m_pSrc || bNoReceive)
      return true;

    DWORD dwWaitResult;
    bool bRet = true;

    if (m_hMutex)
    {
      dwWaitResult = WaitForSingleObject(m_hMutex, 100);
      switch (dwWaitResult)
      {
        case WAIT_OBJECT_0:
          __try
          {
            updateTarget();
          }
          __finally
          {
            ReleaseMutex(m_hMutex);
          }
          break;

        // Cannot get mutex object ownership due to time-out
        case WAIT_TIMEOUT:
          bRet = false;
          break;

        // Got ownership of an abandoned mutex object
        case WAIT_ABANDONED:
          bRet = false;
          break;
      }
    }
    else
    {
      updateTarget();
    }
    return bRet;
  }

protected:
  inline void updateTarget()
  {
    if (m_ppTarget)
    {
      for (long i = 0; i < m_size; i++) (*m_ppTarget)[i] = m_pSrc[i];
    }
    else if (m_pTarget)
    {
      *m_pTarget = m_pSrc[0];
    }
    else if (m_pSVFcn)
    {
      (m_pObj->*m_pSVFcn)(m_pSrc, m_size);
    }
    else if (m_pVFcn)
    {
      (m_pObj->*m_pVFcn)(m_pSrc);
    }
    else if (m_pTVFcn)
    {
      if (m_pOwner) 
        (m_pObj->*m_pTVFcn)(m_pOwner->getTime(), m_pSrc);  
    }
    else if (m_pTSVFcn)
    {
      if (m_pOwner) 
        (m_pObj->*m_pTSVFcn)(m_pOwner->getTime(), m_pSrc, m_size);  
    }
    else if (m_pSFcn)
    {
      (m_pObj->*m_pSFcn)(m_pSrc[0]);
    }
  }

protected:
  
  long m_cRef;
  long m_cookie;
  T* m_pObj;
  bool m_bDataChanged;

  // function protottypes (list is getting large)
  setScalar m_pSFcn;
  setVector m_pVFcn;
  setTVector m_pTVFcn;
  setSVector m_pSVFcn;
  setTSVector m_pTSVFcn;

  A* m_pSrc;                // source vector / scalar
  long m_size;              // source vector size (1 if scalar)

  A** m_ppTarget;           // target vector
  A* m_pTarget;             // target scalar
  HANDLE m_hMutex;          // hMutex of source broadcaster
  COnModelBase* m_pOwner;   // container base object --> source for time

  bool bNoReceive;          // disable receive, data passed through calls to gen() only
};


//=============================================================================================
//
// COnBroadcasterFcn event broadcaster
// 
// broadcast data handler where source T is a get_ function for a vector or scalar of type A
//
//=============================================================================================
class IOnBroadcaster
{
public:
  virtual long AddRef() = 0;
  virtual long Release() = 0;
  virtual bool broadcast() = 0;
  virtual void clean() = 0;
  virtual void setOwner(COnModelBase* pOwner) = 0;
};

template <class T, class A>
class COnBroadcasterFcn : public IOnBroadcaster
{
public:
  typedef void (T::*getFcn)(A* arg);
  typedef void (T::*getTFcn)(const double t, A* arg);

#define CONBROADCASTERFCN_CONSTRUCTOR_BASE \
  m_cRef(0), m_cookies(NULL), m_Sinks(NULL), m_cSinks(0), m_dSinks(0), m_next_cookie(1000), \
  m_pSrc(NULL), m_pSrcFcn(NULL), m_pSrcTFcn(NULL), m_pOwner(NULL)

  COnBroadcasterFcn<T, A>(T* pSrc, getFcn pSrcFcn) : CONBROADCASTERFCN_CONSTRUCTOR_BASE
  {
    m_pSrc = pSrc;
    m_pSrcFcn = pSrcFcn;
  }

  COnBroadcasterFcn<T, A>(T* pSrc, getTFcn pSrcFcn) : CONBROADCASTERFCN_CONSTRUCTOR_BASE
  {
    m_pSrc = pSrc;
    m_pSrcTFcn = pSrcFcn;
  }

protected:
	virtual ~COnBroadcasterFcn<T, A>()
  {
    long i;

    for (i = 0; i < m_cSinks; i++)
      m_Sinks[i]->Release();

    if (m_Sinks) 
      delete[] m_Sinks;

    if (m_cookies) 
      delete[] m_cookies;
  }

public:

  void clean()
  {
    m_pSrc = NULL;
    m_pOwner = NULL;
    for (long i = 0; i < m_cSinks; i++)
      m_Sinks[i]->clean();
  }

  void setOwner(COnModelBase* pOwner)
  {
    m_pOwner = pOwner;
  }

  bool broadcast()
  {
    long i;

    if (m_pSrc)
    {
      if (m_pSrcFcn)
        (m_pSrc->*(m_pSrcFcn))(&val);
      else if (m_pSrcTFcn)
        if (m_pOwner) (m_pSrc->*(m_pSrcTFcn))( m_pOwner->getTime(), &val );
      for (i = 0; i < m_cSinks; i++)
        m_Sinks[i]->SetSource(&val, 1);
    }

    return true;
  }


  long AddRef()
  { 
    return ++m_cRef; 
  }

  long Release()
  { 
    m_cRef--; 
    if (m_cRef <= 0) 
      delete this; 

    return m_cRef; 
  }

  void Advise(IOnListenerEx<A>* pSink)
  {
    long dim = m_dSinks;
    size_ptr_array(10, m_cSinks, dim, m_Sinks);
    size_array(10, m_cSinks, m_dSinks, m_cookies);
    m_Sinks[m_cSinks] = pSink;
    m_cookies[m_cSinks] = m_next_cookie;
    m_cSinks++;
    pSink->SetCookie(m_next_cookie++);
    pSink->AddRef();
  }

  void Unadvise(long cookie)
  {
    long i;
    long count;

    for (i = 0; i < m_cSinks; i++)
    {
      if (m_cookies[i] == cookie)
      {
        m_Sinks[i]->Release();
        count = m_cSinks;
        compress_ptr_array(i, count, m_Sinks);
        compress_array(i, m_cSinks, m_cookies);
        break;
      }
    }
  }

protected:
  long m_cRef;
  IOnListenerEx<A>** m_Sinks;
  long* m_cookies;
  long m_cSinks;
  long m_dSinks;
  long m_next_cookie;

  A val;
  T* m_pSrc;
  getFcn m_pSrcFcn;
  getTFcn m_pSrcTFcn;
  COnModelBase* m_pOwner;
};



//=============================================================================================
//
// COnBroadcaster event broadcaster
// 
// broadcast data handler where source is a vector or scalar of type A
//
//=============================================================================================
template <class A>
class COnBroadcaster : public IOnBroadcaster
{
public:

#define CONBROADCASTER_CONSTRUCTOR_BASE \
  m_cRef(0), m_cookies(NULL), m_Sinks(NULL), m_cSinks(0), m_dSinks(0), m_next_cookie(1000), \
  m_ppSrc(NULL), m_pSrc(NULL), m_hMutex(NULL), m_bErr(false), m_pInBuff(NULL), m_pOutBuff(NULL), m_pOwner(NULL), \
  m_bAllocInBuff(false), m_bAllocOutBuff(false)
  
  // if ppSrc is NULL, the source class will be responsible for flipping the active buffer when broadcast() is called
  // also, the source class should initialize m_pInBuff, m_pOutBuff, and m_size

  // vector constructor
  COnBroadcaster<A>(_TCHAR* Name, A** ppSrc, long size = 1) : CONBROADCASTER_CONSTRUCTOR_BASE
  {
    m_ppSrc = ppSrc;
    initMutex(Name);
    if (size > 0)
    {
      if (*ppSrc == NULL) 
      {
        *ppSrc = new A[size];
        m_bAllocInBuff = true;
      }
      m_pInBuff = *ppSrc;
      m_pOutBuff = new A[size];
      m_bAllocOutBuff = true;
    }
  }

  // scalar constructor
  COnBroadcaster<A>(A* pSrc) : CONBROADCASTER_CONSTRUCTOR_BASE
  {
    m_pSrc = pSrc;
  }

  COnBroadcaster<A>() : CONBROADCASTER_CONSTRUCTOR_BASE
  {

  }

protected:
	virtual ~COnBroadcaster<A>()
  {
    long i;

    for (i = 0; i < m_cSinks; i++)
      m_Sinks[i]->Release();

    if (m_Sinks) 
      delete[] m_Sinks;

    if (m_cookies) 
      delete[] m_cookies;

    if ( (m_bAllocInBuff || m_bAllocOutBuff) && m_ppSrc )
    {
      // m_pInBuff and m_pOutBuff get flipped, need to test to see which relates to *m_ppSrc
      if (m_pInBuff)
      {
        if (m_pInBuff == *m_ppSrc)
          if (m_bAllocInBuff) delete[] m_pInBuff;
        else
          if (m_bAllocOutBuff) delete[] m_pInBuff;
          
        m_pInBuff = NULL;
      }

      if (m_pOutBuff)
      {
        if (m_pOutBuff == *m_ppSrc)
          if (m_bAllocInBuff) delete[] m_pOutBuff;
        else
          if (m_bAllocOutBuff) delete[] m_pOutBuff;
          
        m_pInBuff = NULL;
      }
    }
  }

public:

  void clean()
  {
    m_pSrc = NULL;
    m_ppSrc = NULL;
    m_pOwner = NULL;
    for (long i = 0; i < m_cSinks; i++)
      m_Sinks[i]->clean();
  }

  void initMutex(_TCHAR* Name)
  {
    m_hMutex = CreateMutex(NULL, FALSE, Name);
    if (m_hMutex == NULL)
      m_bErr = true;
    else if ( ERROR_ALREADY_EXISTS == GetLastError () )
      m_bErr = true;
  }

  void setOwner(COnModelBase* pOwner) 
  { 
    m_pOwner = pOwner;
  }

  void gen(A* val)
  {
    for (long i = 0; i < m_cSinks; i++)
    {
      m_Sinks[i]->SetSource(val, 1);
      m_Sinks[i]->gen();
    }
  }

  bool broadcast()
  {
    bool bRet = true;

    if (m_hMutex)
    {
      DWORD dwWaitResult;
      long i;
      dwWaitResult = WaitForSingleObject(m_hMutex, 100);
      switch (dwWaitResult)
      {
        case WAIT_OBJECT_0:
          __try
          {
            if (m_ppSrc) // only flip the buffers if the vector source is defined 
            {            // (data collector defines its own source, and flips the buffers itself)
              A* temp = m_pInBuff;
              m_pInBuff = m_pOutBuff;
              m_pOutBuff = temp;
              *m_ppSrc = m_pInBuff;
            }
            for (i = 0; i < m_cSinks; i++)
              m_Sinks[i]->SetSource(m_pOutBuff, m_size);
          }
          __finally
          {
            if (! ReleaseMutex(m_hMutex) )
              bRet = false;
          }
          break;

        // Cannot get mutex object ownership due to time-out
        case WAIT_TIMEOUT:
          bRet = false;
          break;

        // Got ownership of an abandoned mutex object
        case WAIT_ABANDONED:
          bRet = false;
          break;
      }
    }

    return bRet;
  }


  long AddRef()
  { 
    return ++m_cRef; 
  }

  long Release()
  { 
    m_cRef--; 
    if (m_cRef <= 0) 
      delete this; 

    return m_cRef; 
  }

  void Advise(IOnListenerEx<A>* pSink)
  {
    long dim = m_dSinks;
    size_ptr_array(10, m_cSinks, dim, m_Sinks);
    size_array(10, m_cSinks, m_dSinks, m_cookies);
    m_Sinks[m_cSinks] = pSink;
    m_Sinks[m_cSinks]->SetMutex(m_hMutex);
    
    if (m_pOutBuff)
      m_Sinks[m_cSinks]->SetSource(m_pOutBuff, m_size);
    else
      m_Sinks[m_cSinks]->SetSource(m_pSrc, 1);

    m_cookies[m_cSinks] = m_next_cookie;
    m_cSinks++;
    pSink->SetCookie(m_next_cookie++);
    pSink->AddRef();
  }

  void Unadvise(long cookie)
  {
    long i;
    long count;

    for (i = 0; i < m_cSinks; i++)
    {
      if (m_cookies[i] == cookie)
      {
        m_Sinks[i]->Release();
        count = m_cSinks;
        compress_ptr_array(i, count, m_Sinks);
        compress_array(i, m_cSinks, m_cookies);
        break;
      }
    }
  }

public: 
  // There are cases where the source class must manage the buffers, like the data collector case where the buffers
  // are implemented from SAFEARRAY.
  // Exposed so source class can optionally take care of buffer management on each broadcast() call.
  A* m_pInBuff;
  bool m_bAllocInBuff;
  A* m_pOutBuff;
  bool m_bAllocOutBuff;
  long m_size;
  bool m_bErr;                  // initialize error

protected:
  // reference counting support
  long m_cRef;

  // listener vector
  IOnListenerEx<A>** m_Sinks;   // vector
  long m_cSinks;                // vector count
  long m_dSinks;                // vector dimension (memory allocated for vector)
  long* m_cookies;              // cookies associated with each Sink
  long m_next_cookie;           // next cookie that will be sent to a new Sink

  // data sources
  A* m_pSrc;                    // data source (scalar case)
  A** m_ppSrc;                  // data source (vector case)

  HANDLE m_hMutex;              // mutex (for managing double buffered memory managment)

  COnModelBase* m_pOwner;       // owner --> used for time by data collector sub-class
};


#endif // !defined(AFX_EVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_)

