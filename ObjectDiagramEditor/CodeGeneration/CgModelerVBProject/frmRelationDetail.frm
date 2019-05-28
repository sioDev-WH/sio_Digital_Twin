VERSION 5.00
Begin VB.Form frmRelationDetail 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Relation Detail"
   ClientHeight    =   1845
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   6045
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1845
   ScaleWidth      =   6045
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.Frame frmButtons 
      BorderStyle     =   0  'None
      Height          =   435
      Left            =   3780
      TabIndex        =   7
      Top             =   1380
      Width           =   2235
      Begin VB.CommandButton btnOK 
         Caption         =   "OK"
         Height          =   375
         Left            =   0
         TabIndex        =   3
         Top             =   0
         Width           =   1095
      End
      Begin VB.CommandButton btnCancel 
         Caption         =   "Cancel"
         Height          =   375
         Left            =   1200
         TabIndex        =   8
         Top             =   0
         Width           =   975
      End
   End
   Begin VB.Frame frameDataType 
      Caption         =   "Old"
      Height          =   1155
      Left            =   3000
      TabIndex        =   5
      Top             =   120
      Width           =   2955
      Begin VB.TextBox txtOldAccess 
         Height          =   285
         Left            =   180
         TabIndex        =   2
         Text            =   "Text1"
         Top             =   600
         Width           =   2595
      End
      Begin VB.Label Label2 
         Caption         =   "Access:"
         Height          =   315
         Left            =   180
         TabIndex        =   6
         Top             =   360
         Width           =   855
      End
   End
   Begin VB.Frame frameAccess 
      Caption         =   "New"
      Height          =   1155
      Left            =   60
      TabIndex        =   0
      Top             =   120
      Width           =   2835
      Begin VB.TextBox txtNewAccess 
         Height          =   285
         Left            =   180
         TabIndex        =   1
         Text            =   "Text1"
         Top             =   600
         Width           =   2535
      End
      Begin VB.Label Label1 
         Caption         =   "Access:"
         Height          =   255
         Left            =   180
         TabIndex        =   4
         Top             =   360
         Width           =   1155
      End
   End
End
Attribute VB_Name = "frmRelationDetail"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public m_frmParent As frmClassModificationDetail
Private m_iRow As Integer
Private cgHelper As cgCompareHelper

Public Sub SetBodyText(cgCompareHelper As cgCompareHelper, iRow As Integer)
    On Error Resume Next
    m_iRow = iRow
    Set cgHelper = cgCompareHelper
    
    frameAccess.Caption = "New " & cgHelper.Name
    frameDataType.Caption = "Old " & cgHelper.Name
    
    txtNewAccess.Text = cgHelper.strAccess
    txtOldAccess.Text = cgHelper.strAccessOld
End Sub

Private Sub btnOK_Click()
    On Error GoTo UnloadMe
    If Not m_frmParent Is Nothing Then
        cgHelper.strAccess = txtNewAccess.Text
        cgHelper.strAccessOld = txtOldAccess.Text
        m_frmParent.WriteBackRelation cgHelper, m_iRow
    Else
        gMsgWnd.LogMessage "Could not save new Relation."
    End If
    
UnloadMe:
    Unload Me
End Sub

Private Sub btnCancel_Click()
    Unload Me
End Sub


