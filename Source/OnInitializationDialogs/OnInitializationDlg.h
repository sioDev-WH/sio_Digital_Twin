// OnInitializationDlg.h : Declaration of the COnInitializationDlg

#ifndef __ONINITIALIZATIONDLG_H_
#define __ONINITIALIZATIONDLG_H_

#include "resource.h"       // main symbols
#include <atlhost.h>

typedef short VARIANT_BOOL;

#import "msvbvm60.dll" raw_interfaces_only, raw_native_types, no_namespace, named_guids 
#import "beegd10.ocx" raw_interfaces_only, raw_native_types, no_namespace, named_guids 
#import "OnInitialization.ocx" raw_interfaces_only, raw_native_types, no_namespace, named_guids 

typedef enum eqnCols
{
  eqnColIndex = 0,
  eqnColAsVar = 1,
  eqnColName = 2,
  eqnColVars = 3,
  eqnColRes = 4,
  eqnColBodyIdx = 5,
} eqnCols;

typedef enum varCols
{
  varColIndex = 0,
  varColAsEqn = 1,
  varColName = 2,
  varColDer = 3,
  varColVal = 4,
  varColSet = 5,
} varCols;

const long SHOW_ALL = 0;
const long SHOW_OPEN = 1;

/////////////////////////////////////////////////////////////////////////////
// COnInitializationDlg
class COnInitializationDlg : 
	public CAxDialogImpl<COnInitializationDlg>
{
public:
	COnInitializationDlg();
	~COnInitializationDlg();

	enum { IDD = IDD_ONINITIALIZATIONDLG };

BEGIN_MSG_MAP(COnInitializationDlg)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_ID_HANDLER(IDOK, OnOK)
	COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

  void init(_OnScriptParser* sp, _clsVarManager* vm);
  void Destroy();
  void initScripts();
  void OnApply();
  void saveScripts();
  void saveTrimVars();
  void m_EqnEditor_OnCancel();
  void m_EqnEditor_OnApply(long GridIndex, long EqnIndex, BSTR sScript);
  void initModelVars();
  void initModelEqns();
  void grdInitEqns_AfterInsert();
  void grdInitEqns_AfterDelete();
  void grdInitEqns_ButtonClick(long RowKey, long ColIndex, VARIANT_BOOL& Cancel);
  void reportEqnVars(BSTR script, double& result, CComBSTR& vars, long& varCount);
  void UserControl_Initialize();
  void UserControl_MouseMove(short& Button, short& Shift, float& X, float& Y);
  VARIANT_BOOL IsMsgWindowVisible();
  void ShowMessageWindow();
  void SizeStatusBar(long& Y);

  bool chkVar(long iSel);
  bool chkEqn(long iSel);


private:
  long m_LastBodyIdx;
  _OnScriptParser* m_sp;
  //COnEqnEditor* m_EqnEditor;
  SAFEARRAY* m_psaEqnBodies;
  BSTR* m_EqnBodies;
  SAFEARRAY* m_psaEqnVarCount;
  long* m_EqnVarCount;
  CComBSTR Delim;

  IsgGrid* grdModelVars;
  IsgGrid* grdModelEqns;
  IsgGrid* grdInitEqns;

};

#endif //__ONINITIALIZATIONDLG_H_
