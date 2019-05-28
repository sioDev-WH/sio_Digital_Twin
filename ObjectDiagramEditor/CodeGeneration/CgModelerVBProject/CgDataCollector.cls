VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgDataCollector"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public Name As String
Public Sources As Collection ' of UserDefinedItems
Public Target As UserDefinedItem
Public TargetFcn As String

Private VarNames(1000) As String
Private spVars(100) As Long
Private cNZVars(100) As Long
Public VarCount As Long

Public Sub AddSource(aUDI As UserDefinedItem)
  Dim count As Long
  
  Sources.Add aUDI
  count = Sources.count
  spVars(count - 1) = VarCount
  cNZVars(count - 1) = 0
End Sub

Public Sub AddVar(szVarName As String)
  Dim count As Long
  
  count = Sources.count
  VarNames(VarCount) = szVarName
  VarCount = VarCount + 1
  cNZVars(count - 1) = cNZVars(count - 1) + 1
End Sub

Public Sub GetVars(iSource As Long, Vars() As String, count As Long)
  Dim i As Long
  
  count = cNZVars(iSource)
  ReDim Vars(count) As String
  For i = 0 To count - 1
    Vars(i) = VarNames(spVars(iSource) + i)
  Next i
End Sub

Private Sub Class_Initialize()
  Set Sources = New Collection
End Sub
