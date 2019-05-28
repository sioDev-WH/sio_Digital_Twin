#if !defined(AFX_OMEVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_)
#define AFX_EVENT_OMBROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_


#include "EventBroadcast.h"
#include <oxf/oxf.h>
#include <oxf/event.h>

//=============================================================================================
//
// COnEventListener event listener
//
//=============================================================================================
class IOnEventListener : public IOnListener
{
public:
  virtual void gen(OMEvent* ev) = 0;
  virtual void takeTrigger(OMEvent* ev) = 0;
  virtual void takeEvent(OMEvent* ev) = 0;
};

template <class T> 
class COnEventListener : public IOnEventListener 
{
public:

  COnEventListener(T* obj) : m_cRef(0), m_cookie(-1), m_pObj(NULL)
  {
    m_pObj = obj;
    m_pOwner = NULL;
  }

  void clean()
  {
    m_pObj = NULL;
  }

protected:
	virtual ~COnEventListener() // destructor protected so it can only be called from release();
  {
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

  void gen(OMEvent* ev)
  {
    if (m_pObj)
      m_pObj->gen(ev);
  }

  void takeTrigger(OMEvent* ev)
  {
    if (m_pObj)
      m_pObj->takeTrigger(ev);
  }

  void takeEvent(OMEvent* ev)
  {
    if (m_pObj)
      m_pObj->takeEvent(ev);
  }

  long GetCookie()
  { 
    return m_cookie;
  }

  void setOwner(COnModelBase* pOwner) { m_pOwner = pOwner; }

  void SetMutex(HANDLE hMutex) { }

  void gen() { }

  void SetCookie(long cookie) 
  { 
    m_cookie = cookie; 
  }

  bool receive() { return true; }

protected:
  long m_cRef;
  long m_cookie;
  T* m_pObj;
  COnModelBase* m_pOwner;
};


class COnEventBroadcaster : public IOnBroadcaster
{
public:

	COnEventBroadcaster()
  {
    m_cRef = 0;
    m_cookies = NULL;
    m_Sinks = NULL;
    m_cSinks = 0;
    m_dSinks = 0;
    m_next_cookie = 1000;
    m_pOwner = NULL;
  }

protected:
	virtual ~COnEventBroadcaster()
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

  void clean() { }
  void setOwner(COnModelBase* pOwner) { m_pOwner = pOwner; }

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

  void Advise(IOnEventListener* pSink)
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

  bool broadcast() { return true; }

  void gen(OMEvent* val)
  {
    long i;
    for (i = 0; i < m_cSinks; i++)
      m_Sinks[i]->gen(val); 
  }

  void takeTrigger(OMEvent* val)
  {
    long i;
    for (i = 0; i < m_cSinks; i++)
      m_Sinks[i]->takeTrigger(val); 
  }

  void takeEvent(OMEvent* val)
  {
    long i;
    for (i = 0; i < m_cSinks; i++)
      m_Sinks[i]->takeEvent(val); 
  }

protected:
  long m_cRef;
  IOnEventListener** m_Sinks;
  long* m_cookies;
  long m_cSinks;
  long m_dSinks;
  long m_next_cookie;
  COnModelBase* m_pOwner;
};

#endif //!defined(AFX_OMEVENT_BROADCAST_H__7573FB5D_D874_4C10_A739_71730A0D4B52__INCLUDED_)
