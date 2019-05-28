#if !defined(AFX_EVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_)
#define AFX_EVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_

#include "$(ONIROOT)\CommonHeader\CommonTools.h"

template <class A>
class COnBroadcaster;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//=============================================================================================
//
// IOnListener interface
//
//=============================================================================================
template <class A>
class IOnListener  
{
public:
  virtual long AddRef() = 0;
  virtual long Release() = 0;
  virtual void SetEventSource(COnBroadcaster<A>* pSource) = 0;
  virtual void SetCookie(long cookie) = 0;
  virtual void Disconnect() = 0;
  virtual void Fire_Event(A* arg) = 0; 
};



//=============================================================================================
//
// COnListener event listener
//
//=============================================================================================
template <class T, class A> 
class COnListener : public IOnListener<A> 
{
public:
  typedef void (T::*sink_function)(A* arg);

  COnListener(T* obj, sink_function fcn)
  {
    init(obj, fcn);
  }

protected:
	virtual ~COnListener() // destructor protected so it can only be called from release();
  {
    clean();
  }

public:
  void init(T* obj, sink_function fcn)
  {
    m_cRef = 0;
    m_cookie = -1;
    m_pObj = obj;
    m_pFcn = fcn;
    m_pEventSource = NULL;
  }

  void clean()
  {
    if (m_pEventSource)
    {
      m_pEventSource->Unadvise(m_cookie);
      m_pEventSource->Release();
      m_pEventSource = NULL;
    }
  }

  // implementation of IOnEventSink
  virtual long AddRef() 
  { 
    return ++m_cRef; 
  }

  virtual long Release() 
  { 
    m_cRef--; 
    if (m_cRef <= 0) 
      delete this; 
    
    return m_cRef; 
  }

  virtual void SetEventSource(COnBroadcaster<A>* pSource) 
  { 
    clean();
    m_pEventSource = pSource; 
    pSource->AddRef(); 
  }

  virtual void SetCookie(long cookie) 
  { 
    m_cookie = cookie; 
  }

  virtual void Disconnect()
  {
    clean();
  }

  virtual void Fire_Event(A* arg)
  {
    (m_pObj->*m_pFcn)(arg);
  }



protected:
  COnBroadcaster<A>* m_pEventSource;
  long m_cRef;
  long m_cookie;
  T* m_pObj;
  sink_function m_pFcn;

};




//=============================================================================================
//
// COnBroadcaster event broadcaster
//
//=============================================================================================
template <class A>
class COnBroadcaster
{
public:
	COnBroadcaster<A>()
  {
    init();
  }

protected:
	virtual ~COnBroadcaster<A>()
  {
    clean();
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

  void init()
  {
    m_cRef = 0;
    m_cookies = NULL;
    m_Sinks = NULL;
    m_cSinks = 0;
    m_dSinks = 0;

    m_next_cookie = 1000;
  }

  void clean()
  {
    long i;
    IOnListener<A>* pSink;

    for (i = m_cSinks - 1; i >= 0; i--)  
    {
      pSink = m_Sinks[i];
      pSink->Disconnect(); 
    }

    if (m_Sinks) 
    {
      delete[] m_Sinks;
      m_Sinks = NULL;
    }

    if (m_cookies) 
    {
      delete[] m_cookies;
      m_cookies = NULL;
    }
  }


  void Advise(IOnListener<A>* pSink)
  {
    long dim = m_dSinks;
    size_ptr_array(10, m_cSinks, dim, m_Sinks);
    size_array(10, m_cSinks, m_dSinks, m_cookies);
    m_Sinks[m_cSinks] = pSink;
    m_cookies[m_cSinks] = m_next_cookie;
    m_cSinks++;
    pSink->SetEventSource(this);
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

  void Fire_Event(A* arg)
  {
    long i;

    for (i = 0; i < m_cSinks; i++)
      m_Sinks[i]->Fire_Event(arg); 
  }

protected:
  long m_cRef;
  IOnListener<A>** m_Sinks;
  long* m_cookies;
  long m_cSinks;
  long m_dSinks;
  long m_next_cookie;

};





#endif // !defined(AFX_EVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_)

