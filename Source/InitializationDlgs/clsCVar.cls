VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsCVar"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Name As String
Public longName As String
Public Root As Boolean
Public m_vm As clsVarManager

Private m_coll As Collection

Public Sub init(itsName As String, itsLongName As String, IsRoot As Boolean, vm As clsVarManager)
  Name = itsName
  longName = itsLongName
  Root = IsRoot
  Set m_vm = vm
  Set m_coll = New Collection
End Sub

Private Sub Class_Initialize()
  Set m_coll = New Collection
End Sub

Public Sub Add(itemKey As String, newItem As Object)
  m_coll.Add newItem, itemKey
End Sub

Public Sub removeAll()
  Set m_coll = New Collection
End Sub

Public Sub remove(itemKey As Variant)
  m_coll.remove itemKey
End Sub

Public Property Get Item(itemKey As Variant) As Object
Attribute Item.VB_UserMemId = 0
  On Error Resume Next
  Set Item = m_coll(itemKey)
End Property

Public Property Get Count() As Long
  Count = m_coll.Count
End Property

Public Sub Destroy()
  Set m_vm = Nothing
  Set m_coll = Nothing
End Sub
