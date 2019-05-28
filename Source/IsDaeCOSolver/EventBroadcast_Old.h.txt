#if !defined(AFX_EVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_)
#define AFX_EVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_

#include "CommonTools.h"

template <class T, class A>
class COnBroadcaster;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
ONI broadcaster communication maps

// 1 Broadcaster + 1 listener
ONI_BROADCAST_MAP(ARGTYPE, SOURCE_CLASS, SOURCE_OBJECT, SOURCE_FUNCTION, TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)

// 1 DataCollector with 1 variable + 1 listener
ONI_DATACOLLECTOR_MAP(CONTAINER_OBJECT, SOURCE_MODEL_OBJECT, VARIABLE, TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)

// 1 Broacaster + N listeners
ONI_BEGIN_BROADCAST_MAP(ARGTYPE)
  ONI_BROADCASTER_IMPL(SOURCE_CLASS, SOURCE_OBJECT, SOURCE_FUNCTION)
  -- OR -- 
  ONI_BROADCASTER_ENTRY(SOURCE_CLASS, SOURCE_BROADCASTER)
  ONI_LISTENER_IMPL(TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)
  -- OR --
  ONI_LISTENER_ENTRY(TARGET_LISTENER)
  ONI_LISTENER_IMPL(TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)
  ONI_LISTENER_IMPL(TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)
ONI_END_BROADCAST_MAP()

// 1 DataCollector with 1 variable + N listeners
ONI_BEGIN_BROADCAST_MAP(ARGTYPE)
  ONI_DATACOLLECTOR_IMPL(CONTAINER_OBJECT, SOURCE_MODEL_OBJECT, VARIABLE)
  -- or --
  ONI_DATACOLLECTOR_ENTRY(SOURCE_DATACOLLECTOR)
  ONI_LISTENER_IMPL(TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)
  -- or --
  ONI_LISTENER_IMPL_DC(TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)
ONI_END_BROADCAST_MAP()

// 1 DataCollector with N variables + N listeners
ONI_BEGIN_BROADCAST_MAP(ARGTYPE)
  ONI_BEGIN_DATACOLLECTOR_IMPL(CONTAINER_OBJECT, SOURCE_MODEL_OBJECT)
    ONI_VAR(VAR1), ONI_VAR(VAR2), ONI_VAR(VAR3), ...    
  ONI_END_DATACOLLECTOR_IMPL()
  ONI_LISTENER_IMPL(TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)
  -- or --
  ONI_LISTENER_IMPL_DC(TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)
ONI_END_BROADCAST_MAP()



NOTES:
1) The _IMPL suffix indicates that the macro implements or creates the necessary components.  The suffix _ENTRY
   indicates that the necessary component is already existing.

   While it is quite unnecessary to pre-define broadcasters or listeners for communicating data, it is generally desirable
   to pre-define broadcasters for communicating events.  There is no similar advantage to predefining listeners, however,
   it is still supported.
   
2) Use the simplest macro that will suit the purpose.  Most broacaster / datacollection <--> listener combinations
  involve only 1 broadcaster, 1 variable (data collector), and 1 listener.  A single line macro can be used
  for these common and simple cases.

  // 1 Broadcaster + 1 listener --> both must be created dynamically
  ONI_BROADCAST_MAP(ARGTYPE, SOURCE_CLASS, SOURCE_OBJECT, SOURCE_FUNCTION, TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)

  // 1 DataCollector with 1 variable + 1 listener  --> both must be created dynamically
  ONI_DATACOLLECTOR_MAP(CONTAINER_OBJECT, SOURCE_MODEL_OBJECT, VARIABLE, TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)

3) Begin with ONI_BEGIN_BROADCAST_MAP(ARGTYPE)
  - ARGTYPE - argument type of the data element passed from the source object to the target object

4) Data source options:
  ONI_BROADCASTER_ENTRY(SOURCE_CLASS, SOURCE_OBJECT, SOURCE_FUNCTION)      // broadcaster (exists)
  -- or --
  ONI_BROADCASTER_IMPL(SOURCE_CLASS, SOURCE_OBJECT, SOURCE_FUNCTION)      // broadcaster (must be created)
  -- or --
  ONI_DATACOLLECTOR_ENTRY(SOURCE_DATACOLLECTOR)                           // data collector (1 variable) (exists)
  -- or --
  ONI_DATACOLLECTOR_IMPL(CONTAINER_OBJECT, SOURCE_MODEL_OBJECT, VARIABLE) // data collector (1 variable) (must be created)
  -- or --
  ONI_BEGIN_DATACOLLECTOR_IMPL(CONTAINER_OBJECT, SOURCE_MODEL_OBJECT)     // data collector (n variables) (must be created)
    ONI_VAR(VAR1), ONI_VAR(VAR2), ONI_VAR(VAR3), ...    
  ONI_END_DATACOLLECTOR_IMPL()

  - Only one data source can be defined per map, 
  - A data source IMPL is required before listener entries
  - SOURCE_CLASS - class derived from COnModelBase 
  - SOURCE_OBJECT - object pointer of type SOURCE_CLASS* that sources the data
  - SOURCE_FUNCTION - get function name (no argument list, no (), no class scope) with the following prototype:
    void get_function_name(const double time, ARGTYPE* val); -- or --
    void get_function_name(const double time, ARGTYPE** val);
  - CONTAINER_OBJECT - Any object (class derived from COnModelBase) that is appropriate for triggering the data collection
    Typically, the composite ESO or model executive container class

5) Data sink options:
  ONI_LISTENER_IMPL(TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)
  -- or --
  ONI_LISTENER_IMPL_DC(TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION)

  - The ONI_LISTENER_IMPL_DC() macro supports listener function prototypes:
    a) void set_function_name(const double time, ARGTYPE* val); -- or --
    b) void set_function_name(const double time, ARGTYPE* val, long size);
  - The ONI_LISTENER_IMPL() macro supports only option a)
  - TARGET_CLASS - class derived from COnModelBase 
  - TARGET_OBJECT - object pointer of type TARGET_CLASS* that receives the data
  - TARGET_FUNCTION - set function name (no argument list, no (), no class scope) with the above noted prototypes

6) End with ONI_END_BROADCAST_MAP()

*/
// 

#define ONI_BROADCAST_MAP(ARGTYPE, SOURCE_COMPOSITE_OBJECT, SOURCE_CLASS, SOURCE_OBJECT, SOURCE_FUNCTION, TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION) \
{ \
  COnBroadcaster<SOURCE_CLASS, ARGTYPE>* _OniDataSource = \
    new COnBroadcaster<SOURCE_CLASS, ARGTYPE>(SOURCE_OBJECT, &SOURCE_CLASS::SOURCE_FUNCTION); \
  SOURCE_COMPOSITE_OBJECT->AddBroadcaster(_OniDataSource); \
  COnListener<TARGET_CLASS, ARGTYPE>* pL = \
    new COnListener<TARGET_CLASS, ARGTYPE>(TARGET_OBJECT, &TARGET_CLASS::TARGET_FUNCTION); \
  TARGET_COMPOSITE_OBJECT->AddListener(pL); \
  _OniDataSource->Advise(pL); \
}

#define ONI_DATACOLLECTOR_MAP(SOURCE_COMPOSITE_OBJECT, SOURCE_MODEL_OBJECT, VARIABLE, TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION) \
{ \
  COnDataCollector* _OniDataSource = new COnDataCollector(SOURCE_MODEL_OBJECT); \
  SOURCE_COMPOSITE_OBJECT->AddBroadcaster(_OniDataSource); \
  _TCHAR* varList[] = { L#VARIABLE }; \
  _OniDataSource->SetVariables(varList, 1); \
  COnListener<TARGET_CLASS, double>* pL = \
    new COnListener<TARGET_CLASS, double>(TARGET_OBJECT, &TARGET_CLASS::TARGET_FUNCTION); \
  TARGET_COMPOSITE_OBJECT->AddListener(pL); \
  _OniDataSource->Advise(pL); \
}

#define ONI_BEGIN_BROADCAST_MAP(ARGTYPE) \
{ \
  typedef ARGTYPE _ONI_ARGTYPE;

#define ONI_BROADCASTER_IMPL(COMPOSITE_OBJECT, SOURCE_CLASS, SOURCE_OBJECT, SOURCE_FUNCTION) \
  COnBroadcaster<SOURCE_CLASS, _ONI_ARGTYPE>* _OniDataSource = \
    new COnBroadcaster<SOURCE_CLASS, _ONI_ARGTYPE>(SOURCE_OBJECT, &SOURCE_CLASS::SOURCE_FUNCTION); \
  COMPOSITE_OBJECT->AddBroadcaster(_OniDataSource);

#define ONI_BROADCASTER_ENTRY(SOURCE_BROADCASTER) \
  COnEventBroadcaster<_ONI_ARGTYPE>* _OniDataSource = SOURCE_BROADCASTER;

#define ONI_LISTENER_IMPL(COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION) \
{ \
  COnListener<TARGET_CLASS, _ONI_ARGTYPE>* pL = \
    new COnListener<TARGET_CLASS, _ONI_ARGTYPE>(TARGET_OBJECT, &TARGET_CLASS::TARGET_FUNCTION); \
  COMPOSITE_OBJECT->AddListener(pL); \
  _OniDataSource->Advise(pL); \
}

#define ONI_LISTENER_ENTRY(TARGET_LISTENER) _OniDataSource->Advise(TARGET_LISTENER);

#define ONI_DATACOLLECTOR_IMPL(CONTAINER_OBJECT, SOURCE_MODEL_OBJECT, VARIABLE) \
  COnDataCollector* _OniDataSource = new COnDataCollector(SOURCE_MODEL_OBJECT); \
  CONTAINER_OBJECT->AddBroadcaster(_OniDataSource); \
  _TCHAR* varList[] = { L#VARIABLE }; \
  long _OniVectorSize = sizeof(varList) / sizeof(_TCHAR*); \
  _OniDataSource->SetVariables(varList, _OniVectorSize);

#define ONI_DATACOLLECTOR_ENTRY(SOURCE_DATACOLLECTOR) COnDataCollector* _OniDataSource = SOURCE_DATACOLLECTOR;


#define ONI_BEGIN_DATACOLLECTOR_IMPL(CONTAINER_OBJECT, SOURCE_MODEL_OBJECT) \
  COnDataCollector* _OniDataSource = new COnDataCollector(SOURCE_MODEL_OBJECT); \
  CONTAINER_OBJECT->AddBroadcaster(_OniDataSource); \
  _TCHAR* varList[] = { 

#define ONI_VAR(VARIABLE) L#VARIABLE
 
#define ONI_END_DATACOLLECTOR_IMPL() \
  }; \
  long _OniVectorSize = sizeof(varList) / sizeof(_TCHAR*); \
  _OniDataSource->SetVariables(varList, _OniVectorSize);

#define ONI_LISTENER_IMPL_DC(TARGET_CLASS, TARGET_OBJECT, TARGET_FUNCTION) \
{ \
  COnListener<TARGET_CLASS, _ONI_ARGTYPE>* pL = \
    new COnListener<TARGET_CLASS, _ONI_ARGTYPE>(TARGET_OBJECT, &TARGET_CLASS::TARGET_FUNCTION, _OniVectorSize); \
  TARGET_OBJECT->AddListener(pL); \
  _OniDataSource->Advise(pL); \
}

#define ONI_END_BROADCAST_MAP() }


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
  virtual void receive() = 0;
};


template <class A>
class IOnListenerEx : public IOnListener
{
public:
  virtual long GetCookie() = 0;
  virtual void SetCookie(long cookie) = 0; 
  virtual void update(const double t, A* arg) = 0;
  virtual void update(const double t, A* arg, long size) = 0;
  virtual void* GetTarget() = 0;
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
  typedef void (T::*sink_function)(const double t, A* vec);
  typedef void (T::*sink_function_size)(const double t, A* vec, long size);

  COnListener(T* obj, sink_function fcn, long size = 1)
  {
    m_cRef = 0;
    m_cookie = -1;
    m_pObj = obj;
    m_pFcn = fcn;
    m_updateTime = 0.0;
    m_pSizeFcn = NULL;
    m_vec = new A[size];
    m_size = size;
    m_bDataChanged = false;
  }

  COnListener(T* obj, sink_function_size fcn, long size = 0)
  {
    m_cRef = 0;
    m_cookie = -1;
    m_pObj = obj;
    m_pFcn = NULL;
    m_updateTime = 0.0;
    m_pSizeFcn = fcn;
    if (size > 0)
    {
      m_vec = new A[size];
      m_vec[0] = -1;
    }
    else
      m_vec = NULL;
    m_size = size;
    m_bDataChanged = false;
  }

protected:
	virtual ~COnListener() // destructor protected so it can only be called from release();
  {
    if (m_vec) delete[] m_vec;
  }

public:

  // implementation of IOnEventSink
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

  void update(const double t, A* val)
  {
    m_updateTime = t;
    if (m_size == 0)
    {
      m_size = 1;
      m_vec = new A[1];
    }
    for (long i = 0; i < m_size; i++)
    {
      if (m_vec[i] != val[i])
      {
        m_vec[i] = val[i];
        m_bDataChanged = true;
      }
    }
  }

  void update(const double t, A* vec, long size)
  {
    if (!m_vec) m_vec = new A[size];
    m_updateTime = t;
    m_size = size;
    for (long i = 0; i < m_size; i++)
    {
      if (m_vec[i] != vec[i]) 
      {
        m_vec[i] = vec[i];
        m_bDataChanged = true;
      }
    }
  }

  void SetCookie(long cookie) 
  { 
    m_cookie = cookie; 
  }

  long GetCookie()
  { 
    return m_cookie;
  }

  void receive()
  {
    if (m_bDataChanged)
    {
      if (m_pObj)
      {
        if (m_pFcn)    
          (m_pObj->*m_pFcn)(m_updateTime, m_vec);
        else if (m_pSizeFcn)
          (m_pObj->*m_pSizeFcn)(m_updateTime, m_vec, m_size);
      }
      m_bDataChanged = false;
    }
  }

  void* GetTarget()
  {
    return (void*) m_pObj;
  }

protected:
  long m_cRef;
  long m_cookie;
  T* m_pObj;
  A* m_vec;
  long m_size;
  double m_updateTime;
  sink_function m_pFcn;
  sink_function_size m_pSizeFcn;
  bool m_bDataChanged;
};




//=============================================================================================
//
// COnBroadcaster event broadcaster
//
//=============================================================================================
class IOnBroadcaster
{
public:
  virtual long AddRef() = 0;
  virtual long Release() = 0;
  virtual void broadcast(const double t) = 0;
  virtual void* GetTarget(long i) = 0;
  virtual long GetTargetCount() = 0;
};

template <class T, class A>
class COnBroadcaster : public IOnBroadcaster
{
public:
  typedef void (T::*get_function)(const double t, A* arg);

	COnBroadcaster<T, A>(T* pSrc, get_function pSrcFcn)
  {
    m_cRef = 0;
    m_cookies = NULL;
    m_Sinks = NULL;
    m_cSinks = 0;
    m_dSinks = 0;
    m_next_cookie = 1000;
    m_pSrc = pSrc;
    m_pSrcFcn = pSrcFcn;
  }

protected:
	virtual ~COnBroadcaster<T, A>()
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

  virtual void broadcast(const double t)
  {
    long i;
    A arg = 0.0;
    if (m_pSrc && m_pSrcFcn)
    {
      (m_pSrc->*(m_pSrcFcn))(t, &arg);
      for (i = 0; i < m_cSinks; i++)
        m_Sinks[i]->update(t, &arg); 
    }
  }

  void* GetTarget(long i)
  {
    return (void*) m_Sinks[i];
  }


  long GetTargetCount()
  {
    return m_cSinks;
  }


protected:
  long m_cRef;
  IOnListenerEx<A>** m_Sinks;
  long* m_cookies;
  long m_cSinks;
  long m_dSinks;
  long m_next_cookie;
  T* m_pSrc;
  get_function m_pSrcFcn;

};


template <class A>
class COnEventBroadcaster
{
public:

	COnEventBroadcaster<A>()
  {
    m_cRef = 0;
    m_cookies = NULL;
    m_Sinks = NULL;
    m_cSinks = 0;
    m_dSinks = 0;
    m_next_cookie = 1000;
  }

protected:
	virtual ~COnEventBroadcaster<A>()
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

  void broadcast(const double t, A* val)
  {
    long i;
    for (i = 0; i < m_cSinks; i++)
      m_Sinks[i]->update(t, val); 
  }

  void* GetTarget(long i)
  {
    return m_Sink[i]->GetTarget();
  }

  long GetTargetCount()
  {
    return m_cSinks;
  }

protected:
  long m_cRef;
  IOnListenerEx<A>** m_Sinks;
  long* m_cookies;
  long m_cSinks;
  long m_dSinks;
  long m_next_cookie;

};


#endif // !defined(AFX_EVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_)

