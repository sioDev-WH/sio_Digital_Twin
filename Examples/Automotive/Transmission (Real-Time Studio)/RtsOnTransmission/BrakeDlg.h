// BrakeDlg.h : Declaration of the CBrake

#ifndef __BrakeDLG_H_
#define __BrakeDLG_H_

#include "resource.h"       // main symbols
#include <atlhost.h>
#include <atlwin.h>

/////////////////////////////////////////////////////////////////////////////
// CBrake
class CBrakeDlg 
{
public:
	CBrakeDlg()
	{
    init();
	}

	~CBrakeDlg()
	{
    clean();
	}

  void init();
  void clean();
  void Show();
  void SetCaption(LPCTSTR szCaption);
  void Move(const int x, const int y, const int nWidth, const int nHeight);
  HRESULT get_Position(double* val);
  HRESULT put_Position(double val);

protected:
	CComPtr<_OnBrakes> m_pBrake;
  CAxWindow m_wnd;

};

#endif //__BrakeDLG_H_
