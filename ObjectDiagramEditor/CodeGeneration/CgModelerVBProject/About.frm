VERSION 5.00
Begin VB.Form frmAbout 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Open Numerics Graphic Modeler"
   ClientHeight    =   2805
   ClientLeft      =   225
   ClientTop       =   870
   ClientWidth     =   5145
   Icon            =   "About.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   2805
   ScaleWidth      =   5145
   ShowInTaskbar   =   0   'False
   Begin VB.CommandButton btnOK 
      Caption         =   "OK"
      Height          =   345
      Left            =   3540
      TabIndex        =   2
      Top             =   90
      Width           =   1245
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "Revision:"
      Height          =   195
      Left            =   2070
      TabIndex        =   1
      Top             =   660
      Width           =   660
   End
   Begin VB.Label lblAppRev 
      Caption         =   "Rev"
      Height          =   195
      Left            =   2790
      TabIndex        =   0
      Top             =   660
      Width           =   690
   End
End
Attribute VB_Name = "frmAbout"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
'
'======================================================================================
Option Explicit

'======================================================================================
' End Declarations
'======================================================================================

'======================================================================================
'======================================================================================
'-----------------------------
Private Sub btnOK_Click()
  Unload Me
End Sub

'-----------------------------
Private Sub Form_Activate()
  On Error Resume Next
  lblAppRev.Caption = App.Major & "." & App.Minor & "." & App.Revision
'  lblComment.Caption = App.Comments
'  lblCompanyName.Caption = App.CompanyName
'  lblExeName.Caption = App.EXEName & ".exe"
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Screen.MousePointer = vbArrow
End Sub
