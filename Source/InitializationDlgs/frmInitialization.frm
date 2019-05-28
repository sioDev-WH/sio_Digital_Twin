VERSION 5.00
Begin VB.Form frmInitialization 
   Caption         =   "Trimming"
   ClientHeight    =   11700
   ClientLeft      =   2775
   ClientTop       =   3765
   ClientWidth     =   11985
   LinkTopic       =   "Form1"
   ScaleHeight     =   11700
   ScaleWidth      =   11985
   Begin OnInitialization.ctlInitialization InitDlg 
      Height          =   11775
      Left            =   0
      TabIndex        =   2
      Top             =   0
      Width           =   10575
      _ExtentX        =   18653
      _ExtentY        =   20770
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   10680
      TabIndex        =   1
      Top             =   600
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   10680
      TabIndex        =   0
      Top             =   120
      Width           =   1215
   End
End
Attribute VB_Name = "frmInitialization"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_InitDlg As ctlInitialization

Public Sub init(sp As OnScriptParser, vm As clsVarManager)
  If m_InitDlg Is Nothing Then Set m_InitDlg = InitDlg.object
  m_InitDlg.init sp, vm
End Sub

Public Sub Destroy()
  m_InitDlg.Destroy
End Sub

Private Sub CancelButton_Click()
  Unload Me
End Sub

Private Sub Form_Load()
  Set m_InitDlg = InitDlg.object
End Sub

Private Sub OKButton_Click()
  m_InitDlg.OnApply
  Unload Me
End Sub
