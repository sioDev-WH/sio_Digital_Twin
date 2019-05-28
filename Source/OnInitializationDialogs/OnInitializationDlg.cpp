// COnInitializationDlg.cpp : Implementation of COnInitializationDlg
#include "stdafx.h"
#include "OnInitializationDlg.h"

/////////////////////////////////////////////////////////////////////////////
// COnInitializationDlg

COnInitializationDlg::COnInitializationDlg()
{
  Delim = L"#";
  UserControl_Initialize();
}

COnInitializationDlg::~COnInitializationDlg()
{
}

LRESULT COnInitializationDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
  HRESULT hr = S_OK;
  HWND _hwnd;
  IUnknown* pUnk = NULL;
  
  _hwnd = GetDlgItem( IDC_grdModelVars );
  AtlAxGetControl( _hwnd, &pUnk );
  pUnk->QueryInterface( &grdModelVars ); 
  pUnk->Release();

  _hwnd = GetDlgItem( IDC_grdModelEqns );
  AtlAxGetControl( _hwnd, &pUnk );
  pUnk->QueryInterface( &grdModelEqns ); 
  pUnk->Release();

  _hwnd = GetDlgItem( IDC_grdInitEqns );
  AtlAxGetControl( _hwnd, &pUnk );
  pUnk->QueryInterface( &grdInitEqns ); 
  pUnk->Release();

	return 1;  // Let the system set the focus
}

LRESULT COnInitializationDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}

LRESULT COnInitializationDlg::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}

void COnInitializationDlg::init(_OnScriptParser* sp, _clsVarManager* vm)
{
  m_sp = sp;
  //m_EqnEditor->init(sp, vm, m_Status);
  initModelVars();
  initModelEqns();
  initScripts();
}

void COnInitializationDlg::Destroy()
{  
  /*
  if (m_EqnEditor)
  {
    m_EqnEditor.Destroy();
    m_EqnEditor->Release();
    m_EqnEditor = NULL;
  }
  
  if (m_Status)
  {
    m_Status.Destroy();
    m_Status->Release();
    m_Status = NULL;
  }
  */

  if (m_sp)
  {
    m_sp->Release();
    m_sp = NULL;
  }
}

void COnInitializationDlg::initScripts()
{
  long i;
  long nScripts;
  SAFEARRAY* psaAssignedVars = NULL;
  SAFEARRAY* psaScriptNames = NULL;
  SAFEARRAY* psaScriptVars = NULL;
  SAFEARRAY* psaScriptResiduals = NULL;

  BSTR* AssignedVars = NULL;
  BSTR* ScriptNames = NULL;
  BSTR* ScriptVars = NULL;
  BSTR* ScriptResiduals = NULL;
  
  m_sp->GetScripts(&nScripts, &psaAssignedVars, &psaScriptNames, &psaScriptVars, &psaScriptResiduals, &m_psaEqnBodies, &m_psaEqnVarCount);

  SafeArrayAccessData(psaAssignedVars, (void HUGEP* FAR*)& AssignedVars);
  SafeArrayAccessData(psaScriptNames, (void HUGEP* FAR*)& ScriptNames);
  SafeArrayAccessData(psaScriptVars, (void HUGEP* FAR*)& ScriptVars);
  SafeArrayAccessData(psaScriptResiduals, (void HUGEP* FAR*)& ScriptResiduals);
  
  CComBSTR str;
  _TCHAR buff[20];
  IsgRows* pRows = NULL;

  grdInitEqns->get_Rows(&pRows);
  for (i = 0; i < nScripts; i++)
  {
    str = ltoa(i+1, buff, 10);
    str.Append(AssignedVars[i]);
    str.Append(Delim);
    str.Append(ScriptNames[i]);
    str.Append(Delim);
    str.Append(ScriptVars[i]);
    str.Append(Delim);
    str.Append(ScriptResiduals[i]);
    pRows->Add(sgFormatCharSeparatedValue, str, Delim);
  }
  pRows->Release();

  if (nScripts > 0)
    m_LastBodyIdx = nScripts - 1;
  else
    m_LastBodyIdx = 0;

  if (psaAssignedVars)
  {
    SafeArrayDestroy(psaAssignedVars);
    psaAssignedVars = NULL;
  }

  if (psaScriptNames)
  {
    SafeArrayDestroy(psaScriptNames);
    psaScriptNames = NULL;
  }

  if (psaScriptVars)
  {
    SafeArrayDestroy(psaScriptVars);
    psaScriptVars = NULL;
  }

}

void COnInitializationDlg::OnApply()
{
  saveScripts();
  saveTrimVars();
}

void COnInitializationDlg::saveScripts()
{
  long i;
  long nScripts;
  long BodyIdx;
  IsgArray* pArray = NULL;
  SAFEARRAY* psaAssignedVars = NULL;
  SAFEARRAY* psaScriptNames = NULL;
  SAFEARRAY* psaScriptVars = NULL;
  SAFEARRAY* psaScriptResiduals = NULL;
  SAFEARRAY* psaScriptBodies = NULL;
  SAFEARRAY* psaScriptVarCount = NULL;
  
  BSTR* AssignedVars = NULL;
  BSTR* ScriptNames = NULL;
  BSTR* ScriptVars = NULL;
  double* ScriptResiduals = NULL;
  BSTR* ScriptBodies = NULL;
  long* ScriptVarCount = NULL;
  VARIANT val;

  grdInitEqns->get_Array(&pArray);
  pArray->get_RowCount(&nScripts);
  if (nScripts = 0) 
  {
    goto cleanup;
  }

  psaAssignedVars = SafeArrayCreateVector(VT_BSTR, 0, nScripts);
  psaScriptNames = SafeArrayCreateVector(VT_BSTR, 0, nScripts);
  psaScriptVars = SafeArrayCreateVector(VT_BSTR, 0, nScripts);
  psaScriptResiduals = SafeArrayCreateVector(VT_R8, 0, nScripts);
  psaScriptBodies = SafeArrayCreateVector(VT_BSTR, 0, nScripts);
  psaScriptVarCount = SafeArrayCreateVector(VT_I4, 0, nScripts);
  
  SafeArrayAccessData(psaAssignedVars, (void HUGEP* FAR*)& AssignedVars);
  SafeArrayAccessData(psaScriptNames, (void HUGEP* FAR*)& ScriptNames);
  SafeArrayAccessData(psaScriptVars, (void HUGEP* FAR*)& ScriptVars);
  SafeArrayAccessData(psaScriptResiduals, (void HUGEP* FAR*)& ScriptResiduals);
  SafeArrayAccessData(psaScriptBodies, (void HUGEP* FAR*)& ScriptBodies);
  SafeArrayAccessData(psaScriptVarCount, (void HUGEP* FAR*)& ScriptVarCount);
  
  VariantInit(&val);
  for (i = 0; i < nScripts; i++)
  {
    pArray->Get(i, eqnColAsVar, &val);
    AssignedVars[i] = val.bstrVal; 
    pArray->Get(i, eqnColName, &val);
    ScriptNames[i] = val.bstrVal;
    pArray->Get(i, eqnColVars, &val);
    ScriptVars[i] = val.bstrVal;
    pArray->Get(i, eqnColRes, &val);
    ScriptResiduals[i] = val.dblVal;
    pArray->Get(i, eqnColBodyIdx, &val);
    BodyIdx = val.lVal;
    ::SysReAllocString(&(m_EqnBodies[BodyIdx]), ScriptBodies[i]);
    ScriptVarCount[i] = m_EqnVarCount[BodyIdx];
  }

  m_sp->SetScripts(
    &nScripts, 
    &psaAssignedVars, 
    &psaScriptNames, 
    &psaScriptVars, 
    &psaScriptResiduals, 
    &psaScriptBodies, 
    &psaScriptVarCount);

  // cleanup
cleanup:

  SafeArrayUnaccessData(psaAssignedVars);
  SafeArrayUnaccessData(psaScriptNames);
  SafeArrayUnaccessData(psaScriptVars);
  SafeArrayUnaccessData(psaScriptResiduals);
  SafeArrayUnaccessData(psaScriptBodies);
  SafeArrayUnaccessData(psaScriptVarCount);

  SafeArrayDestroy(psaAssignedVars);
  SafeArrayDestroy(psaScriptNames);
  SafeArrayDestroy(psaScriptVars);
  SafeArrayDestroy(psaScriptResiduals);
  SafeArrayDestroy(psaScriptBodies);
  SafeArrayDestroy(psaScriptVarCount);

  if (pArray)
  {
    pArray->Release();
    pArray = NULL;
  }
}

bool COnInitializationDlg::chkVar(long iSel)
{
  // TODO:
  return true;
}

void COnInitializationDlg::saveTrimVars()
{
  long iRow;
  long nTrimVars;
  
  SAFEARRAY* psaTrimVars = SafeArrayCreateVector(VT_I4, 0, 1000);
  SAFEARRAY* psaTrimVarVals = SafeArrayCreateVector(VT_R8, 0, 1000);
  long* TrimVars = NULL;
  double* TrimVarVals = NULL;
  IsgArray* pArray = NULL;
  long rowCount;
  VARIANT val;

  SafeArrayAccessData(psaTrimVars, (void HUGEP* FAR*)& TrimVars);
  SafeArrayAccessData(psaTrimVarVals, (void HUGEP* FAR*)& TrimVarVals);

  grdModelVars->get_Array(&pArray);
  pArray->get_RowCount(&rowCount); 
  VariantInit(&val);

  for (iRow = 0; iRow < rowCount; iRow++)
  {
    pArray->Get(iRow, varColSet, &val);
    if (val.boolVal == VARIANT_TRUE)
    {
      if (chkVar(SHOW_ALL))
        TrimVars[nTrimVars] = iRow;
      else
        m_sp->get_VarOrder( &iRow, &(TrimVars[nTrimVars]) );
      
      pArray->Get(iRow, varColVal, &val);
      TrimVarVals[nTrimVars] = val.dblVal; 
      
      nTrimVars++;
    }
  }
  
  if (nTrimVars > 0)
  {
    m_sp->SetTrimVars(&nTrimVars, &psaTrimVars, &psaTrimVarVals);
  }

  // cleanup
  SafeArrayUnaccessData(psaTrimVars);
  SafeArrayUnaccessData(psaTrimVarVals);

  SafeArrayDestroy(psaTrimVars);
  SafeArrayDestroy(psaTrimVarVals);
  if (pArray)
  {
    pArray->Release();
    pArray = NULL;
  }
}

/***************************************************************************************
'
'   Begin: Equation editor event handlers
'
'***************************************************************************************/

void COnInitializationDlg::m_EqnEditor_OnCancel()
{
  // TODO:
  //eqnEditor.Visible = VARIANT_FALSE;
}

void COnInitializationDlg::m_EqnEditor_OnApply(long GridIndex, long EqnIndex, BSTR sScript)
{
  double result;
  CComBSTR vars;
  long varCount;
  IsgArray* pArray = NULL;
  VARIANT val;

  grdInitEqns->get_Array(&pArray);
  VariantInit(&val);
  
  reportEqnVars(sScript, result, vars, varCount);
  m_EqnBodies[EqnIndex] = sScript;
  m_EqnVarCount[EqnIndex] = varCount;
  val.vt = VT_BSTR;
  val.bstrVal = vars;
  pArray->Set(GridIndex, eqnColVars, &val);
  val.vt = VT_R8;
  val.dblVal = result;
  pArray->Set(GridIndex, eqnColRes, &val);
  grdInitEqns->RedrawRow(GridIndex + 1);
  
  // TODO:
  //eqnEditor->Visible = VARIANT_FALSE;

  // cleanup
  if (pArray)
  {
    pArray->Release();
    pArray = NULL;
  }
}



/***************************************************************************************
'
'   End: Equation editor event handlers
'
'***************************************************************************************/


void COnInitializationDlg::initModelVars()
{
  //' iEqn = assignedEqn[iVar]
  //' iVar = assignedVar[iEqn]
  
  long iEqn;
  long iVar;
  long iRootVar;
  
  //' fields
  //' Index, AssignedEqn, Name, DER, Value
  long nVars;
  long aIndex;
  BSTR aAssignedEqn;
  BSTR aName;
  long aDER;
  double aValue;
  long i;
  long iRow;
  IsgRows* pRows = NULL;
  IsgArray* pArray = NULL;

  //On Error GoTo error_handler
  
  grdModelVars->get_Rows(&pRows);
  grdModelVars->get_Array(&pArray);
  
  pRows->RemoveAll(VARIANT_FALSE);

  long nTrimVars;
  SAFEARRAY* psaTrimVars = NULL;
  SAFEARRAY* psaTrimVarVals = NULL;
  long* TrimVars = NULL;
  double* TrimVarVals = NULL;
  CComBSTR str;
  VARIANT_BOOL boolFalse = VARIANT_FALSE;
  VARIANT_BOOL boolTrue = VARIANT_TRUE;
  VARIANT val;

  m_sp->GetTrimVars(&nTrimVars, &psaTrimVars, &psaTrimVarVals);

  SafeArrayAccessData(psaTrimVars, (void HUGEP* FAR*)& TrimVars);
  SafeArrayAccessData(psaTrimVarVals, (void HUGEP* FAR*)& TrimVarVals);

  if (chkVar(SHOW_ALL))
  {
    m_sp->get_nVars(&nVars);
    for (iVar = 0; iVar < nVars; iVar++)
    {
      m_sp->initModelVar(&iVar, &boolFalse, &aIndex, &aAssignedEqn, &aName, &aDER, &aValue);
      str = aIndex;
      str.Append(Delim);
      str.Append(aAssignedEqn);
      str.Append(Delim);
      str.Append(aName);
      str.Append(Delim);
      str.Append(aDER);
      str.Append(Delim);
      // TODO:
      str.Append(aValue);
      pRows->Add(sgFormatCharSeparatedValue, str, Delim);
    }
  }
  else
  {
    m_sp->get_nActiveVars(&nVars);
    for (iVar = 0; iVar < nVars; iVar++);
    {
      m_sp->initModelVar(&iVar, &boolTrue, &aIndex, &aAssignedEqn, &aName, &aDER, &aValue);
      str = aIndex;
      str.Append(Delim);
      str.Append(aAssignedEqn);
      str.Append(Delim);
      str.Append(aName);
      str.Append(Delim);
      str.Append(aDER);
      str.Append(Delim);
      str.Append(aValue);
      pRows->Add(sgFormatCharSeparatedValue, str, Delim);
    }
  }
  
  VariantInit(&val);
  for (i = 0; i < nTrimVars; i++)
  {
    if (chkVar(SHOW_ALL))
    {
      iRow = TrimVars[i];
    }
    else
    {
      m_sp->get_itVarOrder(&(TrimVars[i]), &iRow);
    }
    
    if (iRow >= 0)
    {
      val.vt = VT_BOOL;
      val.boolVal = VARIANT_TRUE;
      pArray->Set(iRow, varColSet, &val);
      val.vt = VT_R8;
      val.dblVal = TrimVarVals[i];
      pArray->Set(iRow, varColVal, &val);
    }
  }

  // cleanup
  SafeArrayUnaccessData(psaTrimVars);
  SafeArrayUnaccessData(psaTrimVarVals);

  SafeArrayDestroy(psaTrimVars);
  SafeArrayDestroy(psaTrimVarVals);

  if (pRows)
  {
    pRows->Release();
    pRows = NULL;
  }

  if (pArray)
  {
    pArray->Release();
    pArray = NULL;
  }
}

bool COnInitializationDlg::chkEqn(long iSel)
{
  // TODO:
  return true;  
}

void COnInitializationDlg::initModelEqns()
{
  long iEqn;
  
  //' fields
  //' Index, AssignedVar, Name, Vars, Residual
  long nEqns;
  long aIndex;
  BSTR aAssignedVar;
  BSTR aName;
  BSTR aVars;
  double aResidual;
  CComBSTR str;
  IsgRows* pRows = NULL;
  VARIANT_BOOL boolFalse = VARIANT_FALSE;
  VARIANT_BOOL boolTrue = VARIANT_TRUE;

  grdModelEqns->get_Rows(&pRows);
  pRows->RemoveAll(VARIANT_FALSE);
  
  if (chkEqn(SHOW_ALL))
  {
    m_sp->get_nEqns(&nEqns);
    for (iEqn = 0; iEqn < nEqns; iEqn++)
    {
      m_sp->initModelEqn(&iEqn, &boolFalse, &aIndex, &aAssignedVar, &aName, &aVars, &aResidual);
      str = aIndex;
      str.Append(Delim);
      str.Append(aAssignedVar);
      str.Append(Delim);
      str.Append(aName);
      str.Append(Delim);
      str.Append(aVars);
      str.Append(Delim);
      str.Append(aResidual);
      pRows->Add(sgFormatCharSeparatedValue, str, Delim);
    }
  }
  else
  {
    m_sp->get_nActiveEqns(&nEqns);
    for (iEqn = 0; iEqn < nEqns; iEqn++)
    {
      m_sp->initModelEqn(&iEqn, &boolTrue, &aIndex, &aAssignedVar, &aName, &aVars, &aResidual);
      str = aIndex;
      str.Append(Delim);
      str.Append(aAssignedVar);
      str.Append(Delim);
      str.Append(aName);
      str.Append(Delim);
      str.Append(aVars);
      str.Append(Delim);
      str.Append(aResidual);
      pRows->Add(sgFormatCharSeparatedValue, str, Delim);
    }
  }
  
  // cleanup
  if (pRows)
  {
    pRows->Release();
    pRows = NULL;
  }
}

void COnInitializationDlg::grdInitEqns_AfterDelete()
{
  long iRow;
  long Count;
  IsgArray* pArray = NULL;
  VARIANT val;

  grdInitEqns->get_Array(&pArray);
  VariantInit(&val);
  val.vt = VT_I4;

  pArray->get_RowCount(&Count);
  for (iRow = 0; iRow < Count; iRow++)
  {
    val.lVal = iRow + 1;
    pArray->Set(iRow, eqnColIndex, &val);
  }

  // cleanup
  if (pArray)
  {
    pArray->Release();
    pArray = NULL;
  }
}

void COnInitializationDlg::grdInitEqns_AfterInsert()
{
  long iRow;
  long Count;
  IsgArray* pArray = NULL;
  VARIANT val;

  grdInitEqns->get_Array(&pArray);
  VariantInit(&val);

  pArray->get_RowCount(&Count); 
  val.vt = VT_I4;
  val.lVal = m_LastBodyIdx++;
  pArray->Set(Count - 1, eqnColBodyIdx, &val);

  for(iRow = 0; iRow < Count; iRow++)
  {
    val.lVal = iRow + 1;
    pArray->Set(iRow, eqnColIndex, &val);
  }

  //If UBound(m_EqnBodies) < m_LastBodyIdx Then
  // ReDim Preserve m_EqnBodies(m_LastBodyIdx + 20) As String
  //End If
}

void COnInitializationDlg::grdInitEqns_ButtonClick(long RowKey, long ColIndex, VARIANT_BOOL& Cancel)
{
  long GridIndex;
  long EqnIndex;
  BSTR eqnName = NULL;
  BSTR szData = NULL;
  VARIANT varData;
  SAFEARRAY* psaVecData = NULL;
  IsgRows* pRows = NULL;
  IsgRow* pRow = NULL;
  
  grdInitEqns->get_Rows(&pRows);
  pRows->get_Current(&pRow);

  pRow->GetData(sgFormatCharSeparatedValue, Delim, &szData);
  varData = strtok(szData, Delim);
  vecData = varData;
  GridIndex = VAL(vecData(eqnColIndex)) - 1;
  EqnIndex = grdInitEqns->Array(GridIndex, eqnColBodyIdx);
  eqnName = grdInitEqns->Array(GridIndex, eqnColName);
  
  // TODO:
  //m_EqnEditor->GridIndex = GridIndex;
  //m_EqnEditor->EqnIndex = EqnIndex;
  //m_EqnEditor->eqnName = eqnName;
  //m_EqnEditor->EqnBody = m_EqnBodies[EqnIndex];
  
  //eqnEditor->put_Visible(VARIANT_TRUE);
  //eqnEditor.SetFocus();

  // cleanup
  if (pRows)
  {
    pRows->Release();
    pRows = NULL;
  }

  if (pRow)
  {
    pRow->Release();
    pRow = NULL;
  }

}

void COnInitializationDlg::reportEqnVars(BSTR script, double& result, CComBSTR& vars, long& varCount)
{
  _clsVar* aV;
  _Collection v;
  _Collection dv1;
  _Collection dv2;
  _Collection dv3;
  long count;
  IDispatch* pItem;
  HRESULT hr;

  m_sp->GetEqnStruct(script, v, dv1, dv2, dv3, result);
  
  vars = "";
  varCount = 0;
  v->get_Count(&count);
  for (i = 1; i <= count; i++)
  {
    hr = v->get_Item(i, &pItem);
    if SUCCEEDED(hr))
    {
      hr = pItem->QueryInterface(IID_clsVar, reinterpret_cast<void**> (&aV) );
      if (SUCCEEDED(hr))
      {
        vars = varCount > 0 ? vars & ", " : "";
        vars.Append(aV->longName);
        varCount++;
      }
    }
  }

  dv1->get_Count(&count);
  for (i = 1; i <= count; i++)
  {
    hr = dv1->get_Item(i, &pItem);
    if SUCCEEDED(hr))
    {
      hr = pItem->QueryInterface(IID_clsVar, reinterpret_cast<void**> (&aV) );
      if (SUCCEEDED(hr))
      {
        vars = varCount > 0 ? vars & ", " : "";
        vars.Append(aV->longName);
        vars.Append(L".der(1)");
        varCount++;
      }
    }
  }

  dv2->get_Count(&count);
  for (i = 1; i <= count; i++)
  {
    hr = dv2->get_Item(i, &pItem);
    if SUCCEEDED(hr))
    {
      hr = pItem->QueryInterface(IID_clsVar, reinterpret_cast<void**> (&aV) );
      if (SUCCEEDED(hr))
      {
        vars = varCount > 0 ? vars & ", " : "";
        vars.Append(aV->longName);
        vars.Append(L".der(2)");
        varCount++;
      }
    }
  }
 
  dv3->get_Count(&count);
  for (i = 1; i <= count; i++)
  {
    hr = dv3->get_Item(i, &pItem);
    if SUCCEEDED(hr))
    {
      hr = pItem->QueryInterface(IID_clsVar, reinterpret_cast<void**> (&aV) );
      if (SUCCEEDED(hr))
      {
        vars = varCount > 0 ? vars & ", " : "";
        vars.Append(aV->longName);
        vars.Append(L".der(3)");
        varCount++;
      }
    }
  }
  
}  


void COnInitializationDlg::UserControl_Initialize()
{
  long i;
  SAFEARRAY* vars = SafeArrayCreateVector(VT_DISP, 0, 100); // clsVar
  m_psaEqnBodies = SafeArrayCreateVector(VT_BSTR, 0, 100);
  SafeArrayAccessData(m_psaEqnBodies, (void HUGEP* FAR*)& m_EqnBodies);
  
  //' display a button on the Variables column of the initialization equation grid
  SGColumn* aCol;
  SGControl* ctrl;
  
  aCol = grdInitEqns->Columns->Add(L"BodyIdx");
  aCol->DataType = sgtLong;
  aCol->Hidden = VARIANT_TRUE;
  
  aCol = grdInitEqns->Columns.Add(L" ");
  aCol->Width = 260;
  aCol->Style->Borders = sgCellBorderTop + sgCellBorderBottom;
  aCol->AllowSizing = VARIANT_FALSE;
  
  ctrl = aCol->Control;
  ctrl->ShowButton = sgShowButtonAlways;
  ctrl->ButtonAlignment = sgButtonLeft;
  
  m_Status = Status.object;
  m_Status.ActiveForm = this;
  
  //' initialize the equation editor
  m_EqnEditor = eqnEditor.object;
} 


void COnInitializationDlg::UserControl_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
{
  Screen.MousePointer = vbArrow;
}

VARIANT_BOOL COnInitializationDlg::IsMsgWindowVisible()
{
  IsMsgWindowVisible = Status->Visible;
}

void COnInitializationDlg::ShowMessageWindow()
{
  Status.Visible = True
}

void COnInitializationDlg::SizeStatusBar(Y As Long)
{
  Status->Move(Status.Left, UserControl.Height - Y, UserControl.Width, Y);
}
