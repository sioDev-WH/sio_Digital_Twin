VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsVarManager"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Public vars As Collection
Public CVars As Collection

Public EqnV As Collection
Public EqnDV1 As Collection
Public EqnDV2 As Collection
Public EqnDV3 As Collection

Private Sub Class_Initialize()
  Set vars = New Collection
  Set CVars = New Collection
  Set EqnDV = New Collection
  Set EqnV = New Collection
End Sub

Public Sub Destroy()
  Dim i As Long
  
  For i = 1 To vars.Count
    vars(i).Destroy
  Next i
  
  For i = 1 To CVars.Count
    CVars(i).Destroy
  Next i
  
  Set vars = Nothing
  Set CVars = Nothing
End Sub

Public Sub EnableEvents()
  Dim aV As clsVar
  
  For Each aV In vars
    aV.GenEv = True
  Next
End Sub

Public Sub DisableEvents()
  Dim aV As clsVar
  
  For Each aV In vars
    aV.GenEv = False
  Next
End Sub

Public Sub init(nVars As Long, VarOrder() As Long, VarNames() As String, Vals() As Double, DerVals() As Double)
  Dim i As Long
  Dim j As Long
  Dim parentCV As clsCVar
  Dim aCV As clsCVar
  Dim aV As clsVar
  Dim tok As Variant
  Dim vTokens() As String
  Dim ub As Long
  Dim key As String
  
  Set vars = New Collection
  Set CVars = New Collection
  
  For i = 0 To nVars - 1
    key = ""
    Set parentCV = Nothing
    tok = Split(VarNames(i), ".")
    If IsArray(tok) Then
      vTokens = tok
    End If
    ub = UBound(vTokens)
    For j = 0 To ub
      If j = ub Then
        ' last token
        Set aV = New clsVar
        Call aV.init(vTokens(ub), VarNames(i), j = 0, i, VarOrder(i), Vals(i), DerVals(i), Me)
        vars.Add aV
        If j > 0 Then
          parentCV.Add aV.Name, aV
        End If
      Else
        If j = 0 Then
          key = vTokens(0)
        Else
          key = key & "." & vTokens(j)
        End If
        
        On Error Resume Next
        Err = 0
        Debug.Print key
        Set aCV = CVars(key)
        If Err <> 0 Then
          On Error GoTo 0
          Debug.Print "Adding key: " & key
          Set aCV = New clsCVar
          Call aCV.init(vTokens(j), key, j = 0, Me)
          CVars.Add aCV, key
          If j > 0 Then
            parentCV.Add aCV.Name, aCV
          End If
        End If
        Set parentCV = aCV
        On Error GoTo 0
        
      End If
    Next j
  Next i
  
End Sub

Public Sub InitStruct()
  Set EqnV = New Collection
  Set EqnDV1 = New Collection
  Set EqnDV2 = New Collection
  Set EqnDV3 = New Collection
End Sub

Public Sub ReportStruct(der As Long, var As clsVar)
  On Error Resume Next
  Select Case der
    Case 0
      EqnV.Add var, var.longName
    Case 1
      EqnDV1.Add var, var.longName
    Case 2
      EqnDV2.Add var, var.longName
    Case 3
      EqnDV3.Add var, var.longName
  End Select
  Err = 0
End Sub





















