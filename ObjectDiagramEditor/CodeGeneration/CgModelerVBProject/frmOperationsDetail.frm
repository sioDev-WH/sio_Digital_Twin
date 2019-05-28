VERSION 5.00
Begin VB.Form frmOperationsDetail 
   BorderStyle     =   5  'Sizable ToolWindow
   Caption         =   "Operation Detail"
   ClientHeight    =   6720
   ClientLeft      =   60
   ClientTop       =   300
   ClientWidth     =   10560
   ForeColor       =   &H00000000&
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   6720
   ScaleWidth      =   10560
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.Frame frmLabels 
      BorderStyle     =   0  'None
      Height          =   375
      Left            =   60
      TabIndex        =   17
      Top             =   6360
      Width           =   2955
      Begin VB.Label lbOperatationsStatus 
         Alignment       =   1  'Right Justify
         Caption         =   "Compare  Status: "
         Height          =   255
         Left            =   0
         TabIndex        =   19
         Top             =   0
         Width           =   1275
      End
      Begin VB.Label lbOperStatus 
         Caption         =   "Label1"
         Height          =   255
         Left            =   1380
         TabIndex        =   18
         Top             =   0
         Width           =   1575
      End
   End
   Begin VB.Frame frmButtons 
      BorderStyle     =   0  'None
      Height          =   435
      Left            =   8280
      TabIndex        =   16
      Top             =   6300
      Width           =   2235
      Begin VB.CommandButton btnOK 
         Caption         =   "OK"
         Height          =   375
         Left            =   0
         TabIndex        =   7
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
   Begin VB.Frame frmOld 
      Caption         =   "Old"
      Height          =   6015
      Left            =   5340
      TabIndex        =   11
      Top             =   180
      Width           =   5115
      Begin VB.TextBox txtOldBody 
         Height          =   4545
         Left            =   120
         MultiLine       =   -1  'True
         ScrollBars      =   3  'Both
         TabIndex        =   6
         Top             =   1320
         Width           =   4995
      End
      Begin VB.TextBox txtOldDataType 
         Height          =   285
         Left            =   180
         TabIndex        =   4
         Text            =   "Text1"
         Top             =   660
         Width           =   2235
      End
      Begin VB.TextBox txtOldAccess 
         Height          =   285
         Left            =   2700
         TabIndex        =   5
         Text            =   "Text1"
         Top             =   660
         Width           =   2235
      End
      Begin VB.Label lbBody 
         Caption         =   "Body:"
         Height          =   255
         Left            =   120
         TabIndex        =   15
         Top             =   1080
         Width           =   1395
      End
      Begin VB.Label Label3 
         Caption         =   "Data Type:"
         Height          =   255
         Left            =   180
         TabIndex        =   13
         Top             =   420
         Width           =   1155
      End
      Begin VB.Label Label4 
         Caption         =   "Access:"
         Height          =   315
         Left            =   2700
         TabIndex        =   12
         Top             =   420
         Width           =   855
      End
   End
   Begin VB.Frame frmNew 
      Caption         =   "New"
      Height          =   6015
      Left            =   60
      TabIndex        =   0
      Top             =   180
      Width           =   5175
      Begin VB.TextBox txtNewDataType 
         Height          =   285
         Left            =   180
         TabIndex        =   1
         Text            =   "Text1"
         Top             =   600
         Width           =   2235
      End
      Begin VB.TextBox txtNewBody 
         Height          =   4545
         Left            =   180
         MultiLine       =   -1  'True
         ScrollBars      =   3  'Both
         TabIndex        =   3
         Top             =   1320
         Width           =   4815
      End
      Begin VB.TextBox txtNewAccess 
         Height          =   285
         Left            =   2640
         TabIndex        =   2
         Text            =   "Text1"
         Top             =   600
         Width           =   2235
      End
      Begin VB.Label Label5 
         Caption         =   "Body:"
         Height          =   255
         Left            =   180
         TabIndex        =   14
         Top             =   1080
         Width           =   1635
      End
      Begin VB.Label Label1 
         Caption         =   "Data Type:"
         Height          =   255
         Left            =   180
         TabIndex        =   10
         Top             =   360
         Width           =   1155
      End
      Begin VB.Label Label2 
         Caption         =   "Access:"
         Height          =   315
         Left            =   2700
         TabIndex        =   9
         Top             =   360
         Width           =   855
      End
   End
End
Attribute VB_Name = "frmOperationsDetail"
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
    
    frmNew.Caption = "New " & cgHelper.Name
    frmOld.Caption = "Old " & cgHelper.Name
    
    txtNewAccess.Text = cgHelper.strAccess
    txtOldAccess.Text = cgHelper.strAccessOld
    txtNewBody.Text = cgHelper.strBody
    txtOldBody.Text = cgHelper.strOldBody
        
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

    
    If cgHelper.OperationsEqual() Then
        lbOperStatus.Caption = "SAME"
    Else
        lbOperStatus.Caption = "DIFFERENT"
    End If
End Sub

Private Sub btnOK_Click()
    On Error GoTo UnloadMe
    If Not m_frmParent Is Nothing Then
        cgHelper.strAccess = txtNewAccess.Text
        cgHelper.strAccessOld = txtOldAccess.Text
        
        If txtNewDataType.Text = "void" Then cgHelper.strDataType = ""
        If txtOldDataType.Text = "void" Then cgHelper.strDataTypeOld = ""
        
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
        
        cgHelper.strBody = txtNewBody.Text
        cgHelper.strOldBody = txtOldBody.Text
        m_frmParent.WriteBackOperation cgHelper, m_iRow
    Else
        gMsgWnd.LogMessage "Could not save new Operation."
    End If
    
UnloadMe:
    Unload Me
End Sub

Private Sub btnCancel_Click()
    Unload Me
End Sub

Private Sub Form_Resize()
    On Error Resume Next
    frmLabels.Top = Abs(Me.Height - 700)
    frmButtons.Top = Abs(Me.Height - 800)
    frmButtons.Left = Abs(Me.Width - 2350)
    
    frmNew.Height = Abs(Me.Height - 1100)
    frmNew.Width = Abs((Me.Width - 300) / 2)
    frmOld.Height = frmNew.Height
    frmOld.Width = frmNew.Width
    
    txtNewBody.Height = Abs(frmNew.Height - 1500)
    txtNewBody.Width = Abs(frmNew.Width - 300)
    txtOldBody.Height = txtNewBody.Height
    txtOldBody.Width = txtNewBody.Width
    frmOld.Left = Abs(Me.Width - frmNew.Width - 150)
End Sub

Private Sub txtNewAccess_Change()
    cgHelper.strAccess = txtNewAccess.Text
    
    If cgHelper.OperationsEqual() Then
        lbOperStatus.Caption = "SAME"
    Else
        lbOperStatus.Caption = "DIFFERENT"
    End If
End Sub

Private Sub txtNewDataType_Change()
    cgHelper.strDataType = txtNewDataType.Text

    If cgHelper.OperationsEqual() Then
        lbOperStatus.Caption = "SAME"
    Else
        lbOperStatus.Caption = "DIFFERENT"
    End If
End Sub

Private Sub txtNewBody_Change()
    cgHelper.strBody = txtNewBody.Text
    
    If cgHelper.OperationsEqual() Then
        lbOperStatus.Caption = "SAME"
    Else
        lbOperStatus.Caption = "DIFFERENT"
    End If
End Sub
