// ShiftDlg.h : Declaration of the CShift

#ifndef __ShiftDLG_H_
#define __ShiftDLG_H_

#include "resource.h"       // main symbols
#include <atlhost.h>
#include <atlwin.h>

struct ISeries;

/////////////////////////////////////////////////////////////////////////////
// CShift
class CShiftDlg
{
public:
	CShiftDlg()
	{
    init();
	}

	~CShiftDlg()
	{
    clean();
	}

  void init();
  void clean();
  void Show();
  void SetCaption(LPCTSTR szCaption);
  void Move(const int x, const int y, const int nWidth, const int nHeight);
  HRESULT get_Position(long* val);
  HRESULT put_Position(long val);

protected:
	CComPtr<_OnShiftLever> m_pShift;
  CAxWindow m_wnd;

};

#endif //__ShiftDLG_H_
