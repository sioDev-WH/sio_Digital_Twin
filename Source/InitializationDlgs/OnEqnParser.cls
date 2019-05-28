VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "OnScriptParser"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private WithEvents sc As ScriptControl
Attribute sc.VB_VarHelpID = -1
Private WithEvents ModelExec As OnModelExec
Attribute ModelExec.VB_VarHelpID = -1
Private m_vm As clsVarManager
Private res As clsVar
Private m_bFault As Boolean
Private m_stage As Long

Private m_nModelEqns As Long
Private m_nModelVars As Long
Private m_nActiveEqns As Long
Private m_nActiveVars As Long
Private m_nEqns As Long
Private m_nVars As Long
Private m_EqnNames() As String  ' nModelEqns
Private m_VarNames() As String  ' nModelVars
Private m_cNZCols() As Long     ' nActiveEqns
Private m_spRowPage() As Long   ' nActiveEqns
Private m_nColIndices As Long
Private m_ColIndices() As Long  ' nColIndices in terms of ActiveVars
Private m_EqnOrder() As Long    ' nActiveEqns
Private m_itEqnOrder() As Long  ' nEqns
Private m_VarOrder() As Long    ' nActiveVars
Private m_itVarOrder() As Long  ' nVars
Private m_VAL() As Long         ' nVars in terms of ActiveVars
Private m_itVAL() As Long
Private m_EAL() As Long         ' nEqns in terms of ActiveEqns
Private m_itEAL() As Long
Private m_DiffOrder() As Long
Private m_RootVarIdx() As Long
Private m_AssignedEqn() As Long
Private m_AssignedVar() As Long
Private m_VarVals() As Double
Private m_Residuals() As Double

Private ubEqnNames As Long
Private ubVarNames As Long
Private ubcNCols As Long
Private ubspRowPage As Long
Private ubColIndices As Long
Private ubEqnOrder As Long
Private ubVarOrder As Long
Private ubVAL As Long
Private ubEAL As Long
Private ubAssignedEqn As Long
Private ubResVals As Long

Private m_lastTestIdx As Long

' scripted equations
Private m_nScripts As Long
Private m_AssignedVars() As String
Private m_ScriptNames() As String
Private m_ScriptVars() As String
Private m_ScriptResiduals() As Double
Private m_ScriptBodies() As String
Private m_ScriptVarCount() As Long

' constrained variables
Private m_nTrimVars As Long
Private m_TrimVars() As Long
Private m_TrimVarVals() As Double

Public Event OnError(Description As String)

Private Sub Class_Initialize()
  Set sc = New ScriptControl
  sc.Language = "VBScript"
  sc.AllowUI = False
  Set m_vm = New clsVarManager
  Set res = New clsVar
  ReDim m_Residuals(100) As Double
End Sub

Private Sub Class_Terminate()
  Set sc = Nothing
End Sub

Public Sub SetModelExec(pModelExec As OnModelExec)
  Set ModelExec = pModelExec
End Sub

Public Property Get nVars() As Long
  nVars = m_nVars
End Property

Public Property Get nEqns() As Long
  nEqns = m_nEqns
End Property

Public Property Get nModelVars() As Long
  nModelVars = m_nModelVars
End Property

Public Property Get nModelEqns() As Long
  nModelEqns = m_nModelEqns
End Property

Public Property Get nActiveEqns() As Long
  nActiveEqns = m_nActiveEqns
End Property

Public Property Get nActiveVars() As Long
  nActiveVars = m_nActiveVars
End Property

Public Property Get VarOrder(iActiveVar As Long) As Long
  VarOrder = m_VarOrder(iActiveVar)
End Property

Public Property Get EqnOrder(iActiveEqn As Long) As Long
  EqnOrder = m_EqnOrder(iActiveEqn)
End Property

Public Property Get itVarOrder(iVar As Long) As Long
  itVarOrder = m_itVarOrder(iVar)
End Property

Public Property Get itEqnOrder(iEqn As Long) As Long
  itEqnOrder = m_itEqnOrder(iEqn)
End Property

Public Sub ShowDialog()
  Dim frm As frmInitialization
  
  Set frm = New frmInitialization
  frm.init Me, m_vm
  frm.Show vbModal
  frm.Destroy
  Set frm = Nothing
End Sub

Public Sub SetScripts( _
  nScripts As Long, _
  AssignedVars() As String, _
  ScriptNames() As String, _
  ScriptVars() As String, _
  ScriptResiduals() As Double, _
  ScriptBodies() As String, _
  ScriptVarCount() As Long)
  
  Dim i As Long
  
  m_nScripts = nScripts
  
  ReDim AssignedVars(nScripts) As String
  ReDim ScriptNames(nScripts) As String
  ReDim ScriptVars(nScripts) As String
  ReDim ScriptResiduals(nScripts) As Double
  ReDim ScriptBodies(nScripts) As String
  ReDim ScriptVarCount(nScripts) As Long

  For i = 0 To m_nScripts - 1
    m_AssignedVars(i) = AssignedVars(i)
    m_ScriptNames(i) = ScriptNames(i)
    m_ScriptVars(i) = ScriptVars(i)
    m_ScriptResiduals(i) = ScriptResiduals(i)
    m_ScriptBodies(i) = ScriptBodies(i)
    m_ScriptVarCount(i) = ScriptVarCount(i)
  Next i
End Sub

Public Sub SetTrimVars(nTrimVars As Long, TrimVars() As Long, TrimVarVals() As Double)
  Dim i As Long
  
  m_nTrimVars = nTrimVars
  
  ReDim m_TrimVars(m_nTrimVars) As Long
  ReDim m_TrimVarVals(m_nTrimVars) As Double
  
  For i = 0 To m_nTrimVars - 1
    m_TrimVars(i) = TrimVars(i)
    m_TrimVarVals(i) = TrimVarVals(i)
  Next i
End Sub

Public Sub GetScripts( _
  nScripts As Long, _
  AssignedVars() As String, _
  ScriptNames() As String, _
  ScriptVars() As String, _
  ScriptResiduals() As Double, _
  ScriptBodies() As String, _
  ScriptVarCount() As Long)
  
  Dim i As Long
  
  nScripts = m_nScripts
  
  ReDim AssignedVars(nScripts) As String
  ReDim ScriptNames(nScripts) As String
  ReDim ScriptVars(nScripts) As String
  ReDim ScriptResiduals(nScripts) As Double
  ReDim ScriptBodies(nScripts) As String
  ReDim ScriptVarCount(nScripts) As Long

  For i = 0 To m_nScripts - 1
    AssignedVars(i) = m_AssignedVars(i)
    ScriptNames(i) = m_ScriptNames(i)
    ScriptVars(i) = m_ScriptVars(i)
    ScriptResiduals(i) = m_ScriptResiduals(i)
    ScriptBodies(i) = m_ScriptBodies(i)
    ScriptVarCount(i) = m_ScriptVarCount(i)
  Next i
End Sub

Public Sub GetTrimVars(nTrimVars As Long, TrimVars() As Long, TrimVarVals() As Double)
  Dim i As Long
  
  nTrimVars = m_nTrimVars
  
  If nTrimVars > 0 Then
    ReDim TrimVars(m_nTrimVars) As Long
    ReDim TrimVarVals(m_nTrimVars) As Double
    
    For i = 0 To m_nTrimVars - 1
      TrimVars(i) = m_TrimVars(i)
      TrimVarVals(i) = m_TrimVarVals(i)
    Next i
  End If
End Sub


Public Function eqnName(iEqn As Long) As String
  Dim szName As String
  
  On Error GoTo error_handler
  
  If iEqn >= 0 And iEqn < m_nModelEqns Then
    szName = m_EqnNames(iEqn)
    If Len(szName) = 0 Then szName = "Eqn[" & iEqn & "]"
  ElseIf iEqn = -1 Then
    szName = "[Undef]"
  Else
    szName = "Eqn[" & iEqn & "]"
  End If
  
  eqnName = szName
  
  Exit Function
error_handler:
  MsgBox "eqnName calculation error: " & Err.Description
End Function

Public Function VarName(iVar As Long) As String
  Dim szName As String
  Dim iRootVar As Long
  
  On Error GoTo error_handler
  
  If iVar >= 0 And iVar < m_nVars Then
    iRootVar = m_RootVarIdx(iVar)
    If iRootVar >= 0 And iRootVar < m_nModelVars Then
      szName = m_VarNames(iRootVar)
      If Len(szName) = 0 Then szName = "Var[" & iRootVar & "]"
    Else
      szName = "Var[" & iRootVar & "]"
    End If
      
    If m_DiffOrder(iVar) > 0 Then
      szName = szName & ".der(" & m_DiffOrder(iVar) & ")"
    End If
  Else
    szName = "[Undef]"
  End If
  
  VarName = szName
  
  Exit Function
error_handler:
  MsgBox "VarName calculation error: " & Err.Description, vbInformation
End Function

Public Sub initModelVar(iActiveVar As Long, bActive As Boolean, aIndex As Long, aAssignedEqn As String, aName As String, aDER As Long, aValue As Double)
  Dim i As Long
  Dim iVar As Long
  Dim iEqn As Long
  Dim iActiveEqn As Long
  
  On Error GoTo error_handler
  
  If bActive Then
    iVar = m_VarOrder(iActiveVar)
  Else
    iVar = iActiveVar
  End If
  
  If iVar >= 0 Then
    ' index
    aIndex = iVar
    
    ' AssignedEqn
    iActiveEqn = m_AssignedEqn(iActiveVar)
    iEqn = m_EqnOrder(iActiveEqn)
    If iEqn = -1 Then
      aAssignedEqn = "DOF"
    Else
      aAssignedEqn = eqnName(iEqn)
    End If
    
    ' Name
    aName = VarName(iVar)
      
    ' DER
    aDER = m_DiffOrder(iVar)
    
    ' Value
    aValue = m_VarVals(i)
  End If
  
  Exit Sub
error_handler:
  MsgBox "Initialize model variable error: " & Err.Description, vbInformation
End Sub

Public Sub initModelEqn(iActiveEqn As Long, bActive As Boolean, aIndex As Long, aAssignedVar As String, aName As String, aVars As String, aResidual As Double)
  Dim iEqn As Long
  Dim iVar As Long
  Dim spRowPage As Long
  Dim i As Long
  
  On Error GoTo error_handler
  
  If bActive Then
    iEqn = m_EqnOrder(iActiveEqn)
  Else
    iEqn = iActiveEqn
    ' TODO
    'iActiveEqn = m_itActiveEqn(iEqn)
  End If
  
  If iEqn < 0 Then Exit Sub
  
  ' index
  aIndex = iEqn
  
  ' AssignedVar
  iVar = m_AssignedVar(iActiveEqn)
  aAssignedVar = VarName(iVar)
  
  ' Name
  aName = eqnName(iEqn)
  
  spRowPage = m_spRowPage(iActiveEqn)
  For i = 0 To m_cNZCols(iActiveEqn) - 1
    iVar = m_ColIndices(spRowPage + i)
    aVars = IIf(i > 0, aVars & ", ", "") & VarName(iVar)
  Next i
  
  'ReDim m_Residuals(100) As Double
  
  If iEqn <= UBound(m_Residuals) Then
    aResidual = m_Residuals(iEqn)
  End If
  
  Exit Sub
error_handler:
  MsgBox "Initialize model equation error: " & Err.Description, vbInformation
  Resume Next
End Sub

Public Sub Test(sName As String, sScript As String, sFinalScript As String, bErr As Boolean, retVal As Double, errLine As Long, errCol As Long, errDesc As String, errText As String)
  On Error Resume Next
  retVal = Eval(sName, sScript, sFinalScript)
  If Err <> 0 Then
    bErr = True
    errCol = sc.Error.Column
    errLine = sc.Error.Line
    errDesc = Err.Description
    errText = sc.Error.Text
  End If
End Sub

Public Function Eval(eqnName As String, script As String, finalScript As String) As Double
  On Error Resume Next
  Dim sEqnName As String
  
  m_lastTestIdx = m_lastTestIdx + 1  ' make the equation name unique, and different from the production version
  sEqnName = eqnName & m_lastTestIdx
  finalScript = "Sub " & sEqnName & "()" & vbCrLf & script & vbCrLf & "End Sub"
  sc.AddCode finalScript
  If Err = 0 Then
    sc.Run sEqnName
  End If
  If Err = 0 Then
    Eval = res
  End If
End Function

Private Sub ModelExec_GetResiduals(ByVal nEqns As Long, EqnIds() As Long, Residuals() As Double)
  Dim i As Long
  Dim iEqn As Long
  ReDim vars(m_nModelVars) As clsVar
  Dim iVar As Long
  Dim diffOrder As Long
  Dim aV As clsVar
  Dim equationName As String
  
  ' update the local variables
  For Each aV In m_vm.vars
    Set vars(aV.ActiveIdx) = aV
  Next
  
  
  For i = 0 To nEqns - 1
    iEqn = EqnIds(i)
    equationName = m_ScriptNames(iEqn)
    sc.Run equationName
    Residuals(i) = res.Value
  Next i
  
End Sub

Private Sub ModelExec_GetTrimEqns(nEqns As Long, nColIndices As Long, cNZCols() As Long, spRowPage() As Long, ColIndices() As Long)
  ' nEqns As Long
  ' nColIndices As Long
  ' cNZCols() As Long
  ' spRowPage() As Long
  ' ColIndices() As Long

  Dim iRow As Long
  Dim sScript As String
  Dim v As Collection
  Dim dv1 As Collection
  Dim dv2 As Collection
  Dim dv3 As Collection
  Dim result As Double
  Dim aV As clsVar
  Dim id As Long
  
  nEqns = m_nScripts
  
  nColIndices = 0
  For iRow = 0 To nEqns - 1
    nColIndices = nColIndices + m_ScriptVarCount(iRow)
  Next iRow
  
  ReDim cNZCols(nEqns) As Long
  ReDim spRowPage(nEqns) As Long
  ReDim ColIndices(nColIndices + 50) As Long ' padded just in case
  
  nColIndices = 0                            ' reset and build as equations are added
  For iRow = 0 To nEqns - 1
    spRowPage(iRow) = nColIndices
    cNZCols(iRow) = 0
    sScript = m_ScriptBodies(iRow)
    Call GetEqnStruct(sScript, v, dv1, dv2, dv3, result)
    
    ' return the variable references
    For Each aV In v
      id = aV.ActiveIdx
      ColIndices(nColIndices) = id
      nColIndices = nColIndices + 1
      cNZCols(iRow) = cNZCols(iRow) + 1
    Next
    
    For Each aV In dv1
      id = aV.ActiveIdx
      If id >= 0 Then
        id = m_VAL(id)
        If id >= 0 Then
          ColIndices(nColIndices) = id
          nColIndices = nColIndices + 1
          cNZCols(iRow) = cNZCols(iRow) + 1
        End If
      End If
    Next
  
    For Each aV In dv2
      id = aV.ActiveIdx
      If id >= 0 Then
        id = m_VAL(id)
        If id >= 0 Then
          id = m_VAL(id)
          If id >= 0 Then
            ColIndices(nColIndices) = id
            nColIndices = nColIndices + 1
            cNZCols(iRow) = cNZCols(iRow) + 1
          End If
        End If
      End If
    Next
  
    For Each aV In dv3
      id = aV.ActiveIdx
      If id >= 0 Then
        id = m_VAL(id)
        If id >= 0 Then
          id = m_VAL(id)
          If id >= 0 Then
            id = m_VAL(id)
            If id >= 0 Then
              ColIndices(nColIndices) = id
              nColIndices = nColIndices + 1
              cNZCols(iRow) = cNZCols(iRow) + 1
            End If
          End If
        End If
      End If
    Next
  Next iRow
  
  initScripts
End Sub

Private Sub ModelExec_GetTrimVars(nVars As Long, VarIds() As Long, VarVals() As Double)
  ' nVars As Long
  ' VarIds() As Long
  ' VarVals() As Double
  
  Dim iRow As Long
  
  nVars = m_nTrimVars
  ReDim VarIds(m_nTrimVars) As Long
  ReDim VarVals(m_nTrimVars) As Double
  
  For iRow = 0 To m_nTrimVars
    VarIds(iRow) = m_TrimVars(iRow)
    VarVals(iRow) = m_TrimVarVals(iRow)
  Next iRow

End Sub

Private Sub ModelExec_InitializationInfo(ByVal fault As Boolean, ByVal stage As Long, ByVal nModelEqns As Long, ByVal nModelVars As Long, ByVal nActiveEqns As Long, ByVal nActiveVars As Long, ByVal nAugmentedEqns As Long, ByVal nAugmentedVars As Long, EqnNames() As String, VarNames() As String, ByVal nColIndices As Long, cNZCols() As Long, spRowPage() As Long, ColIndices() As Long, EqnOrder() As Long, VarOrder() As Long, VAL() As Long, EAL() As Long, AssignedEqn() As Long, VarVals() As Double, VarDotVals() As Double, ResVals() As Double)
  ' fault As Boolean
  ' stage As ISDAECOSOLVERLib.InitStage
  ' nModelEqns As Long
  ' nModelVars As Long
  ' nActiveEqns As Long
  ' nActiveVars As Long
  ' nAugmentedEqns As Long
  ' nAugmentedVars As Long
  ' EqnNames() As String
  ' VarNames() As String
  ' nColIndices As Long
  ' cNZCols() As Long
  ' spRowPage() As Long
  ' ColIndices() As Long
  ' EqnOrder() As Long
  ' VarOrder() As Long
  ' VAL() As Long
  ' EAL() As Long
  ' AssignedEqn() As Long
  ' VarVals() As Double
  ' VarDotVals() As Double
  ' ResVals() As Double
  
  Dim i As Long
  Dim j As Long
  Dim lj As Long
  Dim k As Long
  Dim ub As Long
  Dim iVar As Long
  
  On Error GoTo error_handler
  
  m_bFault = fault
  m_stage = stage
  m_nModelEqns = nModelEqns
  m_nModelVars = nModelVars
  m_nActiveEqns = nActiveEqns
  m_nActiveVars = nActiveVars
  m_nEqns = nAugmentedEqns
  m_nVars = nAugmentedVars
  
  ubEqnNames = UBound(EqnNames)
  ReDim m_EqnNames(0 To ubEqnNames) As String
  For i = 0 To ubEqnNames
    m_EqnNames(i) = EqnNames(i)
  Next i
  
  ubVarNames = UBound(VarNames)
  ReDim m_VarNames(0 To ubVarNames) As String
  For i = 0 To ubVarNames
    m_VarNames(i) = VarNames(i)
  Next i
  
  m_nColIndices = nColIndices
  
  ubcNCols = UBound(cNZCols)
  ReDim m_cNZCols(0 To ubcNCols) As Long
  For i = 0 To ubcNCols
    m_cNZCols(i) = cNZCols(i)
  Next i
  
  ubspRowPage = UBound(spRowPage)
  ReDim m_spRowPage(0 To ubspRowPage) As Long
  For i = 0 To ubspRowPage
    m_spRowPage(i) = spRowPage(i)
  Next i
  
  ubColIndices = UBound(ColIndices)
  ReDim m_ColIndices(0 To ubColIndices) As Long
  For i = 0 To ubColIndices
    m_ColIndices(i) = ColIndices(i)
  Next i
  
  ubEqnOrder = UBound(EqnOrder)
  ReDim m_EqnOrder(0 To ubEqnOrder) As Long
  For i = 0 To ubEqnOrder
    m_EqnOrder(i) = EqnOrder(i)
  Next i
  
  ReDim m_itEqnOrder(m_nEqns)
  For i = 0 To m_nEqns - 1
    m_itEqnOrder(i) = -1
  Next i
  For i = 0 To m_nActiveEqns - 1
    If m_EqnOrder(i) >= 0 And m_EqnOrder(i) < m_nEqns Then
      m_itEqnOrder(EqnOrder(i)) = i
    End If
  Next i
  
  ubVarOrder = UBound(VarOrder)
  ReDim m_VarOrder(0 To ubVarOrder) As Long
  For i = 0 To ubVarOrder
    m_VarOrder(i) = VarOrder(i)
  Next i
  
  ReDim m_itVarOrder(m_nVars)
  For i = 0 To m_nVars - 1
    m_itVarOrder(i) = -1
  Next i
  For i = 0 To m_nActiveVars - 1
    If m_VarOrder(i) >= 0 And m_VarOrder(i) < m_nVars Then
      m_itVarOrder(VarOrder(i)) = i
    End If
  Next i
  
  ubVAL = UBound(VAL)
  ReDim m_VAL(0 To ubVAL) As Long
  For i = 0 To ubVAL
    m_VAL(i) = VAL(i)
  Next i
  
  ubEAL = UBound(EAL)
  ReDim m_EAL(0 To ubEAL) As Long
  For i = 0 To ubEAL
    m_EAL(i) = EAL(i)
  Next i
  
  ReDim m_itVAL(m_nVars) As Long
  ReDim m_itEAL(m_nEqns) As Long
  ReDim m_DiffOrder(m_nVars) As Long
  ReDim m_RootVarIdx(m_nVars) As Long
  For i = 0 To m_nVars - 1
    m_itVAL(i) = -1
  Next i
  For i = 0 To m_nVars - 1
    If m_VAL(i) >= 0 And m_VAL(i) < m_nVars Then
      m_itVAL(VAL(i)) = i
    End If
  Next i
    
  For i = 0 To m_nEqns - 1
    m_itEAL(i) = -1
  Next i
  For i = 0 To m_nEqns - 1
    If m_EAL(i) >= 0 And m_EAL(i) < m_nEqns Then
      m_itEAL(EAL(i)) = i
    End If
  Next i
    
  For i = 0 To m_nVars - 1
    k = 0
    lj = i
    j = m_itVAL(i)
    If j >= 0 And j < m_nVars Then
      Do
        lj = j
        j = m_itVAL(j)
        k = k + 1
      Loop While j >= 0
    End If
    m_RootVarIdx(i) = lj
    m_DiffOrder(i) = k
  Next i
  
  ubAssignedEqn = UBound(AssignedEqn)
  ReDim m_AssignedEqn(0 To ubAssignedEqn) As Long
  For i = 0 To ubAssignedEqn
    m_AssignedEqn(i) = AssignedEqn(i)
  Next i
    
  ReDim m_AssignedVar(m_nVars) As Long
  For i = 0 To m_nVars - 1
    m_AssignedVar(i) = -1
  Next i
  For i = 0 To m_nVars - 1
    If m_AssignedEqn(i) >= 0 And m_AssignedEqn(i) < m_nVars Then
      m_AssignedVar(m_AssignedEqn(i)) = i
    End If
  Next i
  
  ' extract variable values from model vars and der vars
  Dim iActiveVar As Long
  ReDim m_VarVals(m_nVars) As Double
  ' VarVals [0 to nModelVars]
  ' VarDotVals [0 to nModelVars]
  ' VAL [0 to nAugmentedVars], in terms of active vars
  For i = 0 To m_nVars - 1
    iActiveVar = m_itVarOrder(i)
    If i < m_nModelVars Then
      m_VarVals(i) = VarVals(i)
    ElseIf iActiveVar >= 0 Then
      iActiveVar = m_itVAL(iActiveVar)
      If iActiveVar >= 0 Then
        iVar = m_VarOrder(iActiveVar)
        If iVar < m_nModelVars Then
          m_VarVals(i) = VarDotVals(iVar)
        End If
      End If
    End If
  Next i
  
  If Not IsEmpty(ResVals) Then
    ubResVals = UBound(ResVals)
    ReDim m_ResVals(0 To ubResVals) As Long
    For i = 0 To ubResVals
      m_ResVals(i) = ResVals(i)
    Next i
  End If
  
  m_vm.init m_nModelVars, m_VarOrder(), m_VarNames(), VarVals(), VarDotVals()


  Exit Sub
error_handler:
  MsgBox "Initialization info error: " & Err.Description, vbInformation
  Resume Next
End Sub


Private Sub initScripts()
  On Error GoTo error_handler
  
  Dim i As Long
  Dim eqnName As String
  Dim EqnBody As String
  Dim szCode As String
  Dim BodyIdx As Long
  Dim bAddingCode As Boolean
  
  m_vm.DisableEvents
  initSC
  For i = 0 To m_nScripts - 1
    eqnName = m_ScriptNames(i)
    EqnBody = m_ScriptBodies(i)
    szCode = "Sub " & eqnName & "()" & vbCrLf & EqnBody & vbCrLf & "End Sub"
    bAddingCode = True
    Call sc.AddCode(szCode)
    bAddingCode = False
  Next i

  Exit Sub
error_handler:
  If bAddingCode Then
    RaiseEvent OnError("Error: " & sc.Error.Description & " in '" & eqnName & "' on line '" & sc.Error.Line & "', column & '" & sc.Error.Column & " in '" & sc.Error.Text & "'")
  Else
    RaiseEvent OnError("Error: " & Err.Description & " in '" & eqnName & "'")
  End If
  Resume Next
End Sub

Private Sub initSC()
  Dim CVars As Collection
  Dim vars As Collection
  Dim aV As clsVar
  Dim aCV As clsCVar
  
  sc.Reset
  Set res = New clsVar
  sc.AddObject "res", res
  
  Set CVars = m_vm.CVars
  Set vars = m_vm.vars
  
  For Each aCV In CVars
    If aCV.Root Then
      sc.AddObject aCV.Name, aCV, True
    End If
  Next
  
  For Each aV In vars
    If aV.Root Then
      sc.AddObject aV.Name, aV
    End If
  Next

End Sub

Private Sub ModelExec_SetResiduals(ResVals() As Double)
  ' TODO
End Sub

Private Sub ModelExec_SetVariables(VarVals() As Double)
  Dim iVar As Long
  Dim i As Long
  Dim aV As clsVar
  Dim diffOrder As Long
  Dim vars As Collection
  
  Set vars = m_vm.vars
  For i = 0 To m_nVars - 1
    iVar = m_RootVarIdx(i)
    Set aV = vars(iVar)
    diffOrder = m_DiffOrder(i)
    If diffOrder = 0 Then
      aV.Value = VarVals(i)
    Else
      aV.der(diffOrder) = VarVals(i)
    End If
  Next i
End Sub

Private Sub ModelExec_ShowDialog(ByVal msg As String)
  MsgBox msg, vbInformation, "OnInitialization"
  ShowDialog
End Sub

Private Sub sc_Error()
  MsgBox sc.Error.Source & " script error: " & sc.Error.Description & " in '" & sc.Error.Text & "' on line " & sc.Error.Column & sc.Error.Column, vbInformation, "Script error"
  sc.Error.Clear
End Sub

Private Sub sc_Timeout()
  MsgBox "Timeout", vbInformation, "Script error"
End Sub

Public Sub GetEqnStruct(script As String, v As Collection, dv1 As Collection, dv2 As Collection, dv3 As Collection, result As Double)
  Dim eqnName As String
  Dim finalScript As String
  
  m_vm.InitStruct
  eqnName = "EqnStructTest"
  
  result = Eval(eqnName, script, finalScript)
  Set v = m_vm.EqnV
  Set dv1 = m_vm.EqnDV1
  Set dv2 = m_vm.EqnDV2
  Set dv3 = m_vm.EqnDV3
End Sub

Public Function Fmt(VIn As String) As String
  Dim tok As Variant
  Dim vTokens() As String
  Dim ub As Long
  Dim i As Long
  Dim Ret As String
  
  tok = Split(VIn, ".")
  vTokens = tok
  ub = UBound(vTokens)
  Ret = vTokens(0)
  For i = 1 To ub
    Ret = Ret & "(""" & vTokens(i) & """)"
  Next i
  Fmt = Ret
End Function

