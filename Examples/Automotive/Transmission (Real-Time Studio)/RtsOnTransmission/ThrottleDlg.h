// ThrottleDlg.h : Declaration of the CThrottle

#ifndef __ThrottleDLG_H_
#define __ThrottleDLG_H_

#include "resource.h"       // main symbols
#include <atlhost.h>
#include <atlwin.h>

struct _OnThrottle;

/////////////////////////////////////////////////////////////////////////////
// CThrottle
class CThrottleDlg 
  
{
public:
	CThrottleDlg()
	{
    init();
	}

	~CThrottleDlg()
	{
    clean();
	}

  void init();
  void clean();
  void Show();
  void SetCaption(LPCTSTR szCaption);
  void Move( int x, int y, int nWidth, int nHeight);
  void getThrottle(double* val);
  void setThrottle(double val);

protected:
	CComPtr<_OnThrottle>		m_pThrottle;
  CAxWindow m_wnd;

};

#endif //__ThrottleDLG_H_
