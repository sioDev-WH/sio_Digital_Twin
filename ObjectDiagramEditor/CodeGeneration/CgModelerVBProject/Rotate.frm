VERSION 5.00
Begin VB.Form frmRotate 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Rotate Selection"
   ClientHeight    =   2490
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   2775
   Icon            =   "Rotate.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2490
   ScaleWidth      =   2775
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.CheckBox chkCenter 
      Caption         =   "Rotate about center"
      Height          =   195
      Left            =   495
      TabIndex        =   9
      Top             =   645
      Width           =   1725
   End
   Begin VB.CommandButton btnCCW 
      Caption         =   "CCW"
      Height          =   315
      Left            =   1515
      TabIndex        =   4
      ToolTipText     =   "Rotate Counter Clockwise"
      Top             =   1440
      Width           =   990
   End
   Begin VB.CommandButton btnCW 
      Caption         =   "CW"
      Height          =   315
      Left            =   1515
      TabIndex        =   3
      ToolTipText     =   "Rotate Clockwise"
      Top             =   1080
      Width           =   990
   End
   Begin VB.TextBox txtAngle 
      Height          =   285
      Left            =   240
      TabIndex        =   2
      Text            =   "0"
      Top             =   1440
      Width           =   990
   End
   Begin VB.CommandButton btnClose 
      Caption         =   "Close"
      Height          =   315
      Left            =   750
      TabIndex        =   5
      Top             =   2040
      Width           =   1095
   End
   Begin VB.TextBox txtSnap1X 
      Height          =   285
      Left            =   285
      TabIndex        =   0
      Text            =   "50"
      Top             =   300
      Width           =   990
   End
   Begin VB.TextBox txtSnap1Y 
      Height          =   285
      Left            =   1545
      TabIndex        =   1
      Text            =   "50"
      Top             =   300
      Width           =   990
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "Point to rotate about"
      Height          =   195
      Index           =   3
      Left            =   570
      TabIndex        =   10
      Top             =   60
      Width           =   1440
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Angle (degrees)"
      Height          =   210
      Index           =   2
      Left            =   210
      TabIndex        =   8
      Top             =   1185
      Width           =   1140
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "Y"
      Height          =   195
      Index           =   1
      Left            =   1380
      TabIndex        =   7
      Top             =   345
      Width           =   135
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "X"
      Height          =   195
      Index           =   0
      Left            =   120
      TabIndex        =   6
      Top             =   345
      Width           =   135
   End
End
Attribute VB_Name = "frmRotate"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
'
'======================================================================================
Option Explicit

'========================================================
'
' Declarations
'
'
Private m_bDoIt As Boolean
Private m_X As Single
Private m_Y As Single
Private m_Angle As Single
Private m_AppCtrl As Form

Private m_GeCtrl As CG  ' The object
'======================================================================================
' End Declarations
'======================================================================================

'======================================================================================
' Properties
'======================================================================================
Public Property Get GeCtrl() As CG
  Set GeCtrl = m_GeCtrl
End Property
'------------------------------
Public Property Set GeCtrl(GeCtrl As CG)
  ' set the object and manipulate menubar
  On Error Resume Next
  Set m_GeCtrl = GeCtrl
End Property

Public Property Set AppCtrl(frm As Form)
  Set m_AppCtrl = frm
End Property

Public Property Let Angle(dVal As Single)
  m_Angle = dVal
  txtAngle.Text = Format(m_Angle, "0.0")
End Property
Public Property Get Angle() As Single
  On Error Resume Next
  Angle = m_Angle
End Property

Public Property Let sX(dVal As Single)
  m_X = dVal
  txtSnap1X.Text = Format(m_X, "0.000")
End Property
Public Property Get sX() As Single
  On Error Resume Next
  sX = m_X
End Property
Public Property Let sY(dVal As Single)
  m_Y = dVal
  txtSnap1Y.Text = Format(m_Y, "0.000")
End Property
Public Property Get sY() As Single
  On Error Resume Next
  sY = m_Y
End Property
Public Property Get DoIt() As Boolean
  DoIt = m_bDoIt
End Property

'======================================================================================
' CODE
'======================================================================================
'--------------------------
Private Sub Form_Initialize()
  m_X = 0
  m_Y = 0
  m_Angle = 5
  txtAngle.Text = m_Angle
End Sub
'--------------------------
Private Sub btnClose_Click()
  If VerifyConvertSnapValues(txtSnap1X.Text, txtSnap1Y.Text, m_X, m_Y) Then
    If VerifyConvertAngle(txtAngle.Text, m_Angle) Then
      m_bDoIt = True
      Set m_AppCtrl = Nothing
      Unload Me
    End If
  End If
End Sub
'--------------------------
Private Function VerifyConvertAngle(strAngle As String, Angle As Single) As Boolean
  Dim bErr As Boolean
  On Error Resume Next
  bErr = IsNumeric(strAngle)
  bErr = False
  If IsNumeric(strAngle) Then
    Angle = CSng(strAngle)
    If Err = 0 Then
      If Angle > -360 And Angle < 360 Then
        VerifyConvertAngle = True
        Exit Function
      Else
        bErr = True
      End If
    End If
  Else
    bErr = True
  End If
  If bErr Then
    MsgBox "Invalid Angle value. Please enter between -360 and 360", MB_ICONEXCLAMATION
    VerifyConvertAngle = False
  End If
End Function
'--------------------------
Private Function VerifyConvertSnapValues(strX As String, strY As String, X As Single, Y As Single) As Boolean
  Dim bErr As Boolean
  On Error Resume Next
  bErr = IsNumeric(strX)
  bErr = False
  If IsNumeric(strX) And IsNumeric(strY) Then
    X = CSng(strX)
    Y = CSng(strY)
    If Err = 0 Then
      VerifyConvertSnapValues = True
      Exit Function
    End If
  Else
    bErr = True
  End If
  If bErr Then
    MsgBox "Invalid X,Y values", MB_ICONEXCLAMATION
    VerifyConvertSnapValues = False
  End If
End Function


'--------------------------
Private Sub chkCenter_Click()
  Dim dLeft As Single, dBottom As Single
  Dim dRight As Single, dTop As Single
  
  If Not (m_AppCtrl Is Nothing) Then
    If chkCenter.Value Then
      m_GeCtrl.GetSelExtents dLeft, dBottom, dRight, dTop
      m_X = dLeft + ((dRight - dLeft) / 2)
      m_Y = dBottom + ((dTop - dBottom) / 2)
      txtSnap1X.Text = m_X
      txtSnap1Y.Text = m_Y
    End If
  End If
End Sub

'--------------------------
Private Sub btnCCW_Click()
  ' CCW (+ve)
  Dim sVal As Single
  Dim dLeft As Single, dBottom As Single
  Dim dRight As Single, dTop As Single
  
  If Not (m_AppCtrl Is Nothing) Then
  
    If chkCenter.Value Then
      m_GeCtrl.GetSelExtents dLeft, dBottom, dRight, dTop
      m_X = dLeft + ((dRight - dLeft) / 2)
      m_Y = dBottom + ((dTop - dBottom) / 2)
    End If
    
    sVal = m_Angle
    If sVal < 0 Then sVal = 0 - sVal
    m_AppCtrl.DoRotate m_X, m_Y, sVal ' 5
  End If
End Sub

'--------------------------
Private Sub btnCW_Click()
  ' CW (-ve)
  Dim sVal As Single
  Dim dLeft As Single, dBottom As Single
  Dim dRight As Single, dTop As Single
  
  If Not (m_AppCtrl Is Nothing) Then
    
    If chkCenter.Value Then
      m_GeCtrl.GetSelExtents dLeft, dBottom, dRight, dTop
      m_X = dLeft + ((dRight - dLeft) / 2)
      m_Y = dBottom + ((dTop - dBottom) / 2)
    End If
    
    sVal = m_Angle
    If sVal > 0 Then sVal = 0 - sVal
    m_AppCtrl.DoRotate m_X, m_Y, sVal   '-5
  End If
End Sub

'--------------------------
Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
  On Error Resume Next
  Select Case KeyCode
'    Case vbKeyReturn    ' pass it on
'      KeyCode = 0
'      btnClose_Click
    Case vbKeyEscape
      KeyCode = 0
      btnClose_Click
  End Select
End Sub

'--------------------------
Private Sub Form_Unload(Cancel As Integer)
  Set m_GeCtrl = Nothing
End Sub

'--------------------------
Private Sub txtAngle_LostFocus()
  Dim sVal As Single
  If VerifyConvertAngle(txtAngle.Text, sVal) Then
    m_Angle = sVal
  End If
End Sub

'--------------------------
Private Sub txtSnap1X_LostFocus()
  Dim sVal As Single
  If VerifyConvertSnapValues(txtSnap1X.Text, txtSnap1Y.Text, sVal, m_Y) Then
    m_X = sVal
  End If
End Sub
'--------------------------
Private Sub txtSnap1Y_LostFocus()
  Dim sVal As Single
  If VerifyConvertSnapValues(txtSnap1X.Text, txtSnap1Y.Text, m_X, sVal) Then
    m_Y = sVal
  End If
End Sub

'------------------------------
Private Sub txtAngle_GotFocus()
  SelectAllTextControlText txtAngle
End Sub
Private Sub txtSnap1X_GotFocus()
  SelectAllTextControlText txtSnap1X
End Sub
Private Sub txtSnap1Y_GotFocus()
  SelectAllTextControlText txtSnap1Y
End Sub

