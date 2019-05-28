VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgTrigger"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public Name As String
Public Trigger As String
Public Conditions As Collection
Public Eqns As Collection

Private Sub Class_Initialize()
  Set Conditions = New Collection
  Set Eqns = New Collection
End Sub

Public Function export() As String
  Dim szRet As String
  Dim aCondition As CgTriggerCondition
  
  szRet = szRet & "<CgTrigger Name=" & Chr(34) & Name & Chr(34) & " >" & vbCrLf
  For Each aCondition In Conditions
    szRet = szRet & aCondition.export
  Next
  szRet = szRet & "</CgTrigger>" & vbCrLf
  export = szRet
  
End Function

Public Sub import(Operations As Collection, elem As IXMLDOMElement)
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aCondition As CgTriggerCondition
  Dim i As Long
  
  Name = elem.getAttribute("Name")
  Set aNodeList = elem.getElementsByTagName("CgTriggerCondition")
  For i = 0 To aNodeList.length - 1
    Set aItem = aNodeList.Item(i)
    Set aCondition = New CgTriggerCondition
    aCondition.import Operations, aItem
    Conditions.Add aCondition
  Next i
End Sub


