VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgType"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Public Name As String
Public ClassName As String
Public classObj As Object
Public obj As Object
Public IsClass As Boolean
Public BaseClasses As Collection

Public Property Get IsTypeOf(sType As String) As Boolean
  
  Dim aRPClass As RPClass
  Dim additionalBaseClasses As String
  
  If Not classObj Is Nothing Then
    Set aRPClass = classObj
    additionalBaseClasses = aRPClass.getPropertyValue("CPP_CG.Class.AdditionalBaseClasses")
  End If
  
  If InStr(1, ClassName, sType) > 0 Or InStr(1, additionalBaseClasses, sType) > 0 Then
    IsTypeOf = True
  ElseIf IsClass Then
    For Each aRPClass In BaseClasses
      additionalBaseClasses = aRPClass.getPropertyValue("CPP_CG.Class.AdditionalBaseClasses")
      If InStr(1, aRPClass.Name, sType) > 0 Or InStr(1, additionalBaseClasses, sType) > 0 Then
        IsTypeOf = True
        Exit For
      End If
    Next
  End If
  
End Property


Private Sub Class_Initialize()
  Set BaseClasses = New Collection
End Sub

Private Sub Class_Terminate()
  Set BaseClasses = Nothing
  Set obj = Nothing
End Sub
