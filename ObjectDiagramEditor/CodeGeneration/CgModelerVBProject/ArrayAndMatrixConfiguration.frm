VERSION 5.00
Begin VB.Form frmArrayAndMatrixConfiguration 
   Caption         =   "Array Configuration"
   ClientHeight    =   1725
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4230
   Icon            =   "ArrayAndMatrixConfiguration.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1725
   ScaleWidth      =   4230
   StartUpPosition =   1  'CenterOwner
   Begin VB.Frame frmArray 
      BorderStyle     =   0  'None
      Caption         =   "Array"
      Height          =   1695
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   4215
      Begin VB.TextBox txtArrayAttribute 
         Enabled         =   0   'False
         Height          =   315
         Left            =   1200
         TabIndex        =   12
         Top             =   420
         Width           =   2475
      End
      Begin VB.CommandButton btnOK1 
         Caption         =   "OK"
         Height          =   375
         Left            =   2760
         TabIndex        =   11
         Top             =   960
         Width           =   915
      End
      Begin VB.TextBox txtArrayDim 
         Height          =   315
         Left            =   1200
         TabIndex        =   3
         Top             =   960
         Width           =   615
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         Caption         =   "Array Size:"
         Height          =   255
         Left            =   300
         TabIndex        =   2
         Top             =   960
         Width           =   795
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Attribute: "
         Height          =   255
         Left            =   300
         TabIndex        =   1
         Top             =   420
         Width           =   855
      End
   End
   Begin VB.Frame frmMatrix 
      BorderStyle     =   0  'None
      Caption         =   "Matrix"
      Height          =   1695
      Left            =   -60
      TabIndex        =   4
      Top             =   0
      Width           =   4275
      Begin VB.TextBox txtMatrixAttribute 
         Enabled         =   0   'False
         Height          =   315
         Left            =   1080
         TabIndex        =   13
         Top             =   300
         Width           =   2775
      End
      Begin VB.CommandButton btnOK2 
         Caption         =   "OK"
         Height          =   375
         Left            =   2940
         TabIndex        =   10
         Top             =   1020
         Width           =   915
      End
      Begin VB.TextBox txtDim2 
         Height          =   315
         Left            =   1080
         TabIndex        =   9
         Top             =   1140
         Width           =   615
      End
      Begin VB.TextBox txtDim1 
         Height          =   315
         Left            =   1080
         TabIndex        =   8
         Top             =   720
         Width           =   615
      End
      Begin VB.Label Label5 
         Alignment       =   1  'Right Justify
         Caption         =   "Columns:"
         Height          =   255
         Left            =   60
         TabIndex        =   7
         Top             =   1200
         Width           =   915
      End
      Begin VB.Label Label4 
         Alignment       =   1  'Right Justify
         Caption         =   "Rows:"
         Height          =   255
         Left            =   420
         TabIndex        =   6
         Top             =   780
         Width           =   555
      End
      Begin VB.Label Label3 
         Alignment       =   1  'Right Justify
         Caption         =   "Attribute:"
         Height          =   255
         Left            =   240
         TabIndex        =   5
         Top             =   300
         Width           =   735
      End
   End
End
Attribute VB_Name = "frmArrayAndMatrixConfiguration"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private objGD As SGGrid     'The Grid control Array that created this form

Private dim1 As Integer
Private dim2 As Integer

Private iLastRow As Integer

Private Const NAME_COL = 0
Private Const VALUE_COL = 4
Private Const DIMS_COL = 5

Private Sub btnOK1_Click()
    On Error GoTo UnloadForm
    
    If Not objGD Is Nothing Then
        If IsNumeric(txtArrayDim) Then
            objGD.Array(iLastRow, VALUE_COL) = txtArrayDim & "-0"
            objGD.Update
        Else
            MsgBox "Please enter a valid number."
            Exit Sub
        End If
    Else
        gMsgWnd.LogMessage "Failed to set Array dimensions."
    End If
UnloadForm:
    Unload Me
End Sub

Private Sub btnOK2_Click()
    On Error GoTo UnloadForm
    
    If Not objGD.Array Is Nothing Then
        If IsNumeric(txtDim1) And IsNumeric(txtDim2) Then
            objGD.Array(iLastRow, VALUE_COL) = txtDim1 & "-" & txtDim2
            objGD.Update
         Else
            MsgBox "Please enter valid numbers."
            Exit Sub
        End If
    Else
        gMsgWnd.LogMessage "Failed to set Array dimensions."
    End If
UnloadForm:
    Unload Me
End Sub

Public Sub InitArray(iRow As Integer)
    Dim strAttrib As String
    Dim dimArray
      
    On Error Resume Next
    If objGD.Array.RowCount >= (iRow + 1) Then
        iLastRow = iRow
        strAttrib = objGD.Array(iRow, NAME_COL)
        strDims = objGD.Array(iRow, VALUE_COL)
        
        frmArray.Visible = True
        frmMatrix.Visible = False
        Caption = "Array Size Configuration"
        txtArrayAttribute.Text = strAttrib
        
        dimArray = Split(strDims, DASH_DELIMETER)
        txtArrayDim = dimArray(0)
    Else
        gMsgWnd.LogMessage "Failed to initialize Array size configuration dialog."
    End If
End Sub

Public Sub InitMatrix(iRow As Integer)
    Dim strAttrib As String
    Dim dimArray
    
    On Error Resume Next
    If objGD.Array.RowCount >= (iRow + 1) Then
        iLastRow = iRow
        strAttrib = objGD.Array(iRow, NAME_COL)
        strDims = objGD.Array(iRow, VALUE_COL)
        
        frmArray.Visible = False
        frmMatrix.Visible = True
        Caption = "Matrix Size Configuration"
        txtMatrixAttribute.Text = strAttrib
        
        dimArray = Split(strDims, DASH_DELIMETER)
        txtDim1 = dimArray(0)
        txtDim2 = dimArray(1)
    Else
        gMsgWnd.LogMessage "Failed to initialize Matrix size configuration dialog."
    End If
End Sub

Public Property Set GridArray(ByRef objGrid As Object)
  On Error Resume Next
  Set objGD = objGrid
End Property

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Screen.MousePointer = vbArrow
End Sub
