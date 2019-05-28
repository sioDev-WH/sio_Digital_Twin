VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgTriggerCondition"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public bNot As Boolean
Public Operation As String
Public Eqn As CgOperation

Private Sub Class_Initialize()
  bNot = False
  Operation = "And"
End Sub

Public Function export() As String
  Dim szRet As String
  
  szRet = szRet & "<CgTriggerCondition bNot=" & Chr(34) & bNot & Chr(34)
  If Eqn Is Nothing Then
    szRet = szRet & " EqnName=" & Chr(34) & Chr(34)
  Else
    szRet = szRet & " EqnName=" & Chr(34) & Eqn.Name & Chr(34)
  End If
  szRet = szRet & " Operation=" & Chr(34) & Operation & Chr(34)
  szRet = szRet & " />" & vbCrLf
  export = szRet
  
End Function

Public Sub import(Operations As Collection, aItem As IXMLDOMElement)
  Dim EqnName As String
  
  bNot = aItem.getAttribute("bNot")
  EqnName = aItem.getAttribute("EqnName")
  Operation = aItem.getAttribute("Operation")
  On Error Resume Next
  Set Eqn = Operations(EqnName)
  If Err <> 0 Then
    Set Eqn = Nothing
    EqnName = ""
  End If
End Sub

