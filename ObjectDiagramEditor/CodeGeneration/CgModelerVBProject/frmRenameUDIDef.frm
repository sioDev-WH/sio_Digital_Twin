VERSION 5.00
Begin VB.Form frmRenameUDIDef 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Rename Shape"
   ClientHeight    =   1095
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   4845
   ControlBox      =   0   'False
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1095
   ScaleWidth      =   4845
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.TextBox txtOldName 
      Enabled         =   0   'False
      Height          =   345
      Left            =   780
      TabIndex        =   4
      Top             =   120
      Width           =   2655
   End
   Begin VB.TextBox txtNewName 
      Height          =   345
      Left            =   780
      TabIndex        =   2
      Top             =   600
      Width           =   2655
   End
   Begin VB.CommandButton btnCancel 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   3720
      TabIndex        =   1
      Top             =   540
      Width           =   1095
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "OK"
      Height          =   375
      Left            =   3720
      TabIndex        =   0
      Top             =   60
      Width           =   1095
   End
   Begin VB.Label Label2 
      Alignment       =   1  'Right Justify
      Caption         =   "Old:"
      Height          =   195
      Left            =   120
      TabIndex        =   5
      Top             =   180
      Width           =   555
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      Caption         =   "New:"
      Height          =   255
      Left            =   180
      TabIndex        =   3
      Top             =   600
      Width           =   495
   End
End
Attribute VB_Name = "frmRenameUDIDef"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private m_strOldName As String
Private m_strNewName As String

Private Sub btnCancel_Click()
  Unload Me
End Sub

Private Sub btnOK_Click()
    If txtNewName.Text = "" Then
        MsgBox "Please enter a valid shape definition name."
    Else
        m_strNewName = txtNewName.Text
        Unload Me
    End If
End Sub

Public Property Let UDIDefName(strName As String)
  txtOldName.Text = strName
  txtNewName.Text = strName
End Property

Public Property Get UDIDefName() As String
  UDIDefName = m_strNewName
End Property


