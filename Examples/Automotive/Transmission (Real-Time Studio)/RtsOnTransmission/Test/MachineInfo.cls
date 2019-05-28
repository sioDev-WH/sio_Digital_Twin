VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MachineInfo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public Name As String
Public MachineType As String
Public index As Long
Public nStates As Long
Private m_stateNames() As String

Public Sub init(aName As String, aType As String, aIndex As Long, StateCount As Long, stateNames() As String)
  Dim i As Long
  
  Name = aName
  MachineType = aType
  index = aIndex
  nStates = StateCount
  ReDim m_stateNames(nStates) As String
  For i = 0 To nStates - 1
    m_stateNames(i) = stateNames(i)
  Next i
End Sub

Public Property Get StateName(index As Long) As String
  StateName = m_stateNames(index)
End Property

