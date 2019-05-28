VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "rtsProject"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Public Project As Object
Private m_Classes As Collection
Private m_Packages As Collection
Private m_Name As String

Public Property Get Name() As String
  If Len(m_Name) = 0 Then
  #If using_ilogix Then
    m_Name = Project.Name
  #End If
  End If
  Name = m_Name
End Property

Public Property Get Packages() As Collection
  If m_Packages Is Nothing Then GetPackages Project, m_Packages
  Set Packages = m_Packages
End Property

Private Sub Class_Initialize()
  Set m_Classes = Nothing
  Set m_Packages = Nothing
End Sub

Private Sub Class_Terminate()
  Set m_Classes = Nothing
  Set m_Packages = Nothing
End Sub
