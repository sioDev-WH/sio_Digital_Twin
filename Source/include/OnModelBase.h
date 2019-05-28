// OnModelBase.h: interface for the COnModelBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONMODELBASE_H__EE4D1A09_CD8C_4268_810F_8F95A55C95A5__INCLUDED_)
#define AFX_ONMODELBASE_H__EE4D1A09_CD8C_4268_810F_8F95A55C95A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class IOnListener;
class IOnBroadcaster;

#include "OnDaeCOSolverExport.h"

class ONDAECOSOLVER_API COnModelBase  
{
public:
	COnModelBase();
	virtual ~COnModelBase();

  void AddListener(IOnListener* pListener);
  void AddBroadcaster(IOnBroadcaster* pBroadcaster);
  bool receive();
  bool broadcast();
  void setTime(const double t);
  void getTime(double* val);
  const double getTime();
  virtual void setPeriod(long val);
  void getPeriod(long* val);
  const long getPeriod();

protected:  
  long m_cListeners;
  long m_dListeners;
  IOnListener** m_pListeners;
  long m_cBroadcasters;
  long m_dBroadcasters;
  IOnBroadcaster** m_pBroadcasters;
  double m_time;
  long m_period;
};

#endif // !defined(AFX_ONMODELBASE_H__EE4D1A09_CD8C_4268_810F_8F95A55C95A5__INCLUDED_)
