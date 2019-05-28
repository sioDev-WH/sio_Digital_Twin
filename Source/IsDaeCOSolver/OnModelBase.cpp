// OnModelBase.cpp: implementation of the COnModelBase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OnModelBase.h"
#include "CommonTools.h"
#include "EventBroadcast.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COnModelBase::COnModelBase() : m_cListeners(0), m_dListeners(0), m_pListeners(NULL),
  m_cBroadcasters(0), m_dBroadcasters(0), m_pBroadcasters(NULL), m_period(1), m_time(0.0)
{

}

COnModelBase::~COnModelBase()
{
  long i;

  if (m_pListeners) 
  {
    for (i = 0; i < m_cListeners; i++) 
    {
      if (m_pListeners[i])
      {
        m_pListeners[i]->clean();
        m_pListeners[i]->Release();
      }
    }
    delete[] m_pListeners;
  }
   
  if (m_pBroadcasters) 
  {
    for (i = 0; i < m_cBroadcasters; i++) 
    {
      if (m_pBroadcasters[i])
      {
        m_pBroadcasters[i]->clean();
        m_pBroadcasters[i]->Release();
      }
    }
    delete[] m_pBroadcasters;
  }
}

void COnModelBase::AddListener(IOnListener* pListener)
{
  size_ptr_array(10, m_cListeners, m_dListeners, m_pListeners);
  m_pListeners[m_cListeners++] = pListener;
  pListener->AddRef();
}

void COnModelBase::AddBroadcaster(IOnBroadcaster* pBroadcaster)
{
  size_ptr_array(10, m_cBroadcasters, m_dBroadcasters, m_pBroadcasters);
  m_pBroadcasters[m_cBroadcasters++] = pBroadcaster;
  pBroadcaster->AddRef();
}

bool COnModelBase::receive()
{
  bool bRet = true;

  for (long i = 0; i < m_cListeners; i++)
    bRet = bRet && m_pListeners[i]->receive(); 

  return bRet;
}

bool COnModelBase::broadcast()
{
  bool bRet = true;

  for (long i = 0; i < m_cBroadcasters; i++)
    bRet = bRet && m_pBroadcasters[i]->broadcast();
  
  return bRet;
}

void COnModelBase::setTime(const double t)
{
  m_time = t;
  // Member broadcasters and listeners have a backpointer to this container class, 
  // so they can read this time value
}

void COnModelBase::setPeriod(long val)
{
  m_period = val;
}

void COnModelBase::getPeriod(long* val)
{
  *val = m_period;
}

const long COnModelBase::getPeriod()
{
  return m_period;
}

void COnModelBase::getTime(double* val)
{
  *val = m_time;
}

const double COnModelBase::getTime()
{
  return m_time;
}