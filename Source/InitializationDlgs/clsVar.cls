VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsVar"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public longName As String
Public Name As String
Public Force As Boolean
Public DerForce As Boolean
Public ActiveIdx As Long
Public GlobalIdx As Long
Public GenEv As Boolean
Public Root As Boolean
Public m_vm As clsVarManager

Private m_v As Double
Private m_dv(3) As Double

Public Sub init(itsName As String, itsLongName As String, IsRoot As Boolean, ActiveId As Long, GlobalId As Long, v As Double, dv As Double, vm As clsVarManager)
  Name = itsName
  longName = itsLongName
  Root = IsRoot
  ActiveIdx = ActiveId
  GlobalIdx = GlobalId
  m_v = v
  m_dv(1) = dv
  Set m_vm = vm
End Sub

Public Property Get Value() As Double
Attribute Value.VB_UserMemId = 0
  If GenEv And Not m_vm Is Nothing Then Call m_vm.ReportStruct(0, Me)
  Value = m_v
End Property

Public Property Let Value(newVal As Double)
  m_v = newVal
End Property

Public Property Get der(Optional derIdx As Long = 1) As Double
  If GenEv And Not m_vm Is Nothing Then Call m_vm.ReportStruct(derIdx, Me)
  der = m_dv(derIdx)
End Property

Public Property Let der(Optional derIdx As Long = 1, newVal As Double)
  m_dv(derIdx) = newVal
End Property

Private Sub Class_Initialize()
  GenEv = True
End Sub

Public Sub Destroy()
  Set m_vm = Nothing
End Sub
