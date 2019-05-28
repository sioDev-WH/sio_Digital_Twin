VERSION 5.00
Begin VB.Form frmAttributeDetail 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Attribute Detail"
   ClientHeight    =   2520
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   6045
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2520
   ScaleWidth      =   6045
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.Frame frmButtons 
      BorderStyle     =   0  'None
      Height          =   435
      Left            =   3780
      TabIndex        =   10
      Top             =   2100
      Width           =   2235
      Begin VB.CommandButton btnOK 
         Caption         =   "OK"
         Height          =   375
         Left            =   0
         TabIndex        =   12
         Top             =   0
         Width           =   1095
      End
      Begin VB.CommandButton btnCancel 
         Caption         =   "Cancel"
         Height          =   375
         Left            =   1200
         TabIndex        =   11
         Top             =   0
         Width           =   975
      End
   End
   Begin VB.Frame frameDataType 
      Caption         =   "Old"
      Height          =   1875
      Left            =   3000
      TabIndex        =   9
      Top             =   120
      Width           =   2955
      Begin VB.TextBox txtOldAccess 
         Height          =   285
         Left            =   180
         TabIndex        =   3
         Text            =   "Text1"
         Top             =   600
         Width           =   2595
      End
      Begin VB.TextBox txtOldDataType 
         Height          =   285
         Left            =   180
         TabIndex        =   4
         Text            =   "Text1"
         Top             =   1320
         Width           =   2595
      End
      Begin VB.Label Label2 
         Caption         =   "Access:"
         Height          =   315
         Left            =   180
         TabIndex        =   8
         Top             =   360
         Width           =   855
      End
      Begin VB.Label Label4 
         Caption         =   "Data Type:"
         Height          =   315
         Left            =   180
         TabIndex        =   7
         Top             =   1080
         Width           =   855
      End
   End
   Begin VB.Frame frameAccess 
      Caption         =   "New"
      Height          =   1875
      Left            =   60
      TabIndex        =   0
      Top             =   120
      Width           =   2835
      Begin VB.TextBox txtNewDataType 
         Height          =   285
         Left            =   180
         TabIndex        =   2
         Text            =   "Text1"
         Top             =   1320
         Width           =   2535
      End
      Begin VB.TextBox txtNewAccess 
         Height          =   285
         Left            =   180
         TabIndex        =   1
         Text            =   "Text1"
         Top             =   600
         Width           =   2535
      End
      Begin VB.Label Label3 
         Caption         =   "Data Type:"
         Height          =   255
         Left            =   180
         TabIndex        =   6
         Top             =   1080
         Width           =   1155
      End
      Begin VB.Label Label1 
         Caption         =   "Access:"
         Height          =   255
         Left            =   180
         TabIndex        =   5
         Top             =   360
         Width           =   1155
      End
   End
End
Attribute VB_Name = "frmAttributeDetail"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public m_frmParent As frmClassModificationDetail
Private m_iRow As Integer
Private cgHelper As cgCompareHelper

Public Sub SetBodyText(cgCompareHelper As cgCompareHelper, iRow As Integer)
    On Error GoTo Error_Handler
    m_iRow = iRow
    Set cgHelper = cgCompareHelper
    
    frameAccess.Caption = "New " & cgHelper.Name
    frameDataType.Caption = "Old " & cgHelper.Name
    
    txtNewAccess.Text = cgHelper.strAccess
    txtOldAccess.Text = cgHelper.strAccessOld
    
    If cgHelper.strDataType = "" Then
        txtNewDataType.Text = "void"
    Else
        txtNewDataType.Text = cgHelper.strDataType
    End If
    If cgHelper.strDataTypeOld = "" Then
        txtOldDataType.Text = "void"
    Else
        txtOldDataType.Text = cgHelper.strDataTypeOld
    End If
    Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error setting attribute details. " & Err.Description
End Sub

Private Sub btnOK_Click()
    On Error GoTo UnloadForm
    If Not m_frmParent Is Nothing Then
        cgHelper.strAccess = txtNewAccess.Text
        cgHelper.strAccessOld = txtOldAccess.Text

        If txtNewDataType.Text = "void" Then
            cgHelper.strDataType = ""
        Else
            cgHelper.strDataType = txtNewDataType.Text
        End If
        If txtOldDataType.Text = "void" Then
            cgHelper.strDataTypeOld = ""
        Else
            cgHelper.strDataTypeOld = txtOldDataType.Text
        End If
        
        m_frmParent.WriteBackAttribute cgHelper, m_iRow
    Else
        gMsgWnd.LogMessage "Could not save new Attribute."
    End If
        
UnloadForm:
    Unload Me
End Sub

Private Sub btnCancel_Click()
    Unload Me
End Sub


