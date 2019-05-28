VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "includes"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Public coll As Collection

Private Sub Class_Initialize()
  Set coll = New Collection
End Sub

Public Sub Add(sType As String, FD As String, INC As String)
  Dim aInclude As include
  
  Set aInclude = New include
  aInclude.sType = sType
  aInclude.FD = FD
  aInclude.INC = INC
  
  coll.Add aInclude, aInclude.sType
End Sub

