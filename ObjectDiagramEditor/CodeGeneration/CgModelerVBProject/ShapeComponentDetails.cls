VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "cgShapeComponentDetails"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Public urX As Single, urY As Single, llX As Single, llY As Single
Public UserID As Long
Public iFace As Integer
Public iOrder As Integer
Public iType As Long
Public strName As String
Public GeID As Long

Public Sub SetExtents(urXCur As Single, urYCur As Single, llXCur As Single, llYCur As Single)
    urX = urXCur
    urY = urYCur
    llX = llXCur
    llY = llYCur
End Sub

Private Sub Class_Initialize()
    UserID = -1
    strName = ""
End Sub

