VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "OnThrottle"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Dim container As GasContainer


Private Sub Class_Initialize()
  Set container = New GasContainer
  On Error Resume Next
  container.Show
  If Err <> 0 Then
    MsgBox "Error: " & Err.Number & ", " & Err.Description
  End If
End Sub

Private Sub Class_Terminate()
  On Error Resume Next
  Unload container
  Set container = Nothing
End Sub

Public Sub initThrottle()
  'container.Show
End Sub

Public Sub getPosition(ByRef val As Double)
  val = container.Throttle
End Sub

