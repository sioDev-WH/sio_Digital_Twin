// IOnEventSink.h: Definition of the IOnEventSink class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IONEVENTSINK_H__AA8C923E_8404_42D3_8A52_41A8F51B7762__INCLUDED_)
#define AFX_IONEVENTSINK_H__AA8C923E_8404_42D3_8A52_41A8F51B7762__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// IOnEventSink

class IOnEventSink
{
public:
  virtual HRESULT EventNotification(BSTR EventId) = 0;

// IIOnEventSink
public:
};

#endif // !defined(AFX_IONEVENTSINK_H__AA8C923E_8404_42D3_8A52_41A8F51B7762__INCLUDED_)
