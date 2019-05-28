VERSION 5.00
Begin VB.Form frmScale 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Scale Selection"
   ClientHeight    =   2010
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   4020
   Icon            =   "Scale.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2010
   ScaleWidth      =   4020
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton btnCancel 
      Caption         =   "Cancel"
      Height          =   315
      Left            =   2295
      TabIndex        =   3
      Top             =   1440
      Width           =   1095
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "OK"
      Height          =   315
      Left            =   405
      TabIndex        =   2
      Top             =   1440
      Width           =   1095
   End
   Begin VB.TextBox txtWidthNew 
      Height          =   285
      Left            =   2430
      TabIndex        =   0
      Text            =   "50"
      Top             =   450
      Width           =   1395
   End
   Begin VB.TextBox txtHeightNew 
      Height          =   285
      Left            =   2430
      TabIndex        =   1
      Text            =   "50"
      Top             =   765
      Width           =   1395
   End
   Begin VB.Label lblHeightCur 
      Caption         =   "0.0"
      Height          =   210
      Left            =   1080
      TabIndex        =   9
      Top             =   810
      Width           =   1230
   End
   Begin VB.Label lblWidthCur 
      Caption         =   "0.0"
      Height          =   210
      Left            =   1080
      TabIndex        =   8
      Top             =   495
      Width           =   1230
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      Caption         =   "Height:"
      Height          =   210
      Index           =   3
      Left            =   135
      TabIndex        =   7
      Top             =   810
      Width           =   645
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      Caption         =   "Width:"
      Height          =   210
      Index           =   2
      Left            =   135
      TabIndex        =   6
      Top             =   495
      Width           =   645
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "New"
      Height          =   210
      Index           =   1
      Left            =   2700
      TabIndex        =   5
      Top             =   135
      Width           =   825
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Current"
      Height          =   210
      Index           =   0
      Left            =   1260
      TabIndex        =   4
      Top             =   135
      Width           =   780
   End
End
Attribute VB_Name = "frmScale"
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
Private m_WidthCur As Single
Private m_HeightCur As Single
Private m_WidthNew As Single
Private m_HeightNew As Single

'======================================================================================
' End Declarations
'======================================================================================

'======================================================================================
' Properties
'======================================================================================
'--------------------------
Public Property Let WidthCur(dVal As Single)
  m_WidthCur = dVal
  m_WidthNew = dVal
  lblWidthCur.Caption = Format(m_WidthCur, "0.000000")
  txtWidthNew.Text = Format(m_WidthNew, "0.000000")
End Property
Public Property Let HeightCur(dVal As Single)
  m_HeightCur = dVal
  m_HeightNew = dVal
  lblHeightCur.Caption = Format(m_HeightCur, "0.000000")
  txtHeightNew.Text = Format(m_HeightNew, "0.000000")
End Property
'--------------------------
Public Property Get WidthNew() As Single
  WidthNew = m_WidthNew
End Property
Public Property Let WidthNew(dVal As Single)
  m_WidthNew = dVal
  txtWidthNew.Text = m_WidthNew
End Property
'--------------------------
Public Property Get HeightNew() As Single
  HeightNew = m_HeightNew
End Property
Public Property Let HeightNew(dVal As Single)
  m_HeightNew = dVal
  txtHeightNew.Text = m_HeightNew
End Property

'--------------------------
Public Property Get DoIt() As Boolean
  DoIt = m_bDoIt
End Property

'======================================================================================
' CODE
'======================================================================================
'-----------------------------
Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
  On Error Resume Next
  Select Case KeyCode
    Case vbKeyReturn    ' pass it on
      KeyCode = 0
      btnOK_Click
    Case vbKeyEscape
      KeyCode = 0
      btnCancel_Click
  End Select
End Sub
'--------------------------
Private Sub Form_Initialize()
  m_bDoIt = False
  m_WidthCur = 0
  m_HeightCur = 0
  m_WidthNew = 0
  m_HeightNew = 0
End Sub
'--------------------------
Private Sub btnCancel_Click()
  m_bDoIt = False
  Unload Me
End Sub
'--------------------------
Private Sub btnOK_Click()
  If VerifyConvertScaleValues(txtWidthNew.Text, txtHeightNew.Text, m_WidthNew, m_HeightNew) Then
    m_bDoIt = True
    Unload Me
  End If
End Sub
'--------------------------
Private Function VerifyConvertScaleValues(strWidth As String, _
                  strHeight As String, dWidth As Single, dHeight As Single) As Boolean
  Dim bErr As Boolean
  On Error Resume Next
  bErr = IsNumeric(strWidth)
  bErr = False
  If IsNumeric(strWidth) And IsNumeric(strHeight) Then
    dWidth = CSng(strWidth)
    dHeight = CSng(strHeight)
    If Err = 0 Then
      VerifyConvertScaleValues = True
      Exit Function
    End If
  Else
    bErr = True
  End If
  If bErr Then
    MsgBox "Invalid Width/Height values", MB_ICONEXCLAMATION
    VerifyConvertScaleValues = False
  End If
End Function

'--------------------------
Private Sub txtWidthNew_LostFocus()
  Dim sVal As Single
  If VerifyConvertScaleValues(txtWidthNew.Text, txtHeightNew.Text, sVal, m_HeightNew) Then
    m_WidthNew = sVal
  End If
End Sub
'--------------------------
Private Sub txtHeightNew_LostFocus()
  Dim sVal As Single
  If VerifyConvertScaleValues(txtWidthNew.Text, txtHeightNew.Text, m_WidthNew, sVal) Then
    m_HeightNew = sVal
  End If
End Sub

'------------------------------
Private Sub txtWidthNew_GotFocus()
  SelectAllTextControlText txtWidthNew
End Sub
Private Sub txtHeightNew_GotFocus()
  SelectAllTextControlText txtHeightNew
End Sub

