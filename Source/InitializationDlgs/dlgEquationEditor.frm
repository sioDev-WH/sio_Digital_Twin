VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form dlgEquationEditor 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Initialization Equation Editor"
   ClientHeight    =   6780
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   8955
   ControlBox      =   0   'False
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   6780
   ScaleWidth      =   8955
   ShowInTaskbar   =   0   'False
   Begin MSComctlLib.ImageList ImageList1 
      Left            =   8040
      Top             =   1560
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   2
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "dlgEquationEditor.frx":0000
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "dlgEquationEditor.frx":0452
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin VB.CommandButton btnCopyVar 
      Caption         =   "Copy"
      Height          =   375
      Left            =   8040
      TabIndex        =   6
      Top             =   3360
      Width           =   855
   End
   Begin MSComctlLib.TreeView tvwVars 
      Height          =   3135
      Left            =   120
      TabIndex        =   3
      Top             =   3360
      Width           =   7815
      _ExtentX        =   13785
      _ExtentY        =   5530
      _Version        =   393217
      HideSelection   =   0   'False
      Indentation     =   176
      LabelEdit       =   1
      LineStyle       =   1
      Style           =   7
      ImageList       =   "ImageList1"
      Appearance      =   1
   End
   Begin VB.TextBox txtEqnBody 
      Height          =   2655
      Left            =   120
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   2
      Top             =   360
      Width           =   7815
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   8040
      TabIndex        =   1
      Top             =   840
      Width           =   855
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   8040
      TabIndex        =   0
      Top             =   360
      Width           =   855
   End
   Begin VB.Label lblCopy 
      Height          =   375
      Left            =   120
      TabIndex        =   7
      Top             =   6520
      Width           =   7815
   End
   Begin VB.Label Label2 
      Caption         =   "Equation Body:"
      Height          =   255
      Left            =   120
      TabIndex        =   5
      Top             =   120
      Width           =   7815
   End
   Begin VB.Label Label1 
      Caption         =   "Model Variables:"
      Height          =   255
      Left            =   120
      TabIndex        =   4
      Top             =   3120
      Width           =   6855
   End
End
Attribute VB_Name = "dlgEquationEditor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private VarManager As clsVarManager
Private m_bVarsInitialized As Boolean
Private m_SelectedVariable As String
Private m_bApply As Boolean

Private Declare Function ShowWindow Lib "user32" (ByVal hwnd As Long, ByVal nCmdShow As Long) As Long
Private Const SW_HIDE As Long = 0
Private Const SW_MINIMIZE As Long = 6
Private Const SW_MAXIMIZE As Long = 3
Private Const SW_NORMAL As Long = 1
Private Const SW_MAX As Long = 10

Public Property Let EqnBody(newVal As String)
  txtEqnBody.Text = newVal
  initVarNodes
End Property

Public Property Get EqnBody() As String
  EqnBody = txtEqnBody.Text
End Property

Public Property Get Apply() As Boolean
  Apply = m_bApply
End Property

Public Sub init(vm As clsVarManager)
  Set VarManager = vm
  If VarManager.CVars.count > 0 Then
    initVarNodes
  End If
End Sub

Private Sub initVarNodes()
  Dim aCVar As clsCVar
  Dim aVar As clsVar
  Dim aRoot As Node
  Dim aNode As Node
  Dim rootKey As String
  
  If Not m_bVarsInitialized Then
    rootKey = "ROOT"
    tvwVars.Nodes.Clear
    Set aRoot = tvwVars.Nodes.Add(, , rootKey, "Variables")
    For Each aCVar In VarManager.CVars
      If aCVar.Root Then
        Set aNode = tvwVars.Nodes.Add(rootKey, tvwChild, aCVar.longName, aCVar.Name, 1)
        initVarNode aCVar
      End If
    Next
    
    For Each aVar In VarManager.vars
      If aVar.Root Then
        Set aNode = tvwVars.Nodes.Add(rootKey, tvwChild, aVar.longName, aVar.Name, 2)
      End If
    Next
    m_bVarsInitialized = True
  End If
End Sub

Private Sub initVarNode(cv As clsCVar)
  Dim obj As Object
  Dim aCVar As clsCVar
  Dim aVar As clsVar
  Dim i As Long
  Dim aNode As Node
  For i = 1 To cv.count
    Set obj = cv.Item(i)
    If TypeName(obj) = "clsCVar" Then
      Set aCVar = obj
      Set aNode = tvwVars.Nodes.Add(cv.longName, tvwChild, aCVar.longName, aCVar.Name, 1)
      initVarNode aCVar
    ElseIf TypeName(obj) = "clsVar" Then
      Set aVar = obj
      Set aNode = tvwVars.Nodes.Add(cv.longName, tvwChild, aVar.longName, aVar.Name, 2)
    End If
  Next i
End Sub


Private Sub btnCopyVar_Click()
  If Len(m_SelectedVariable) = 0 Then
    MsgBox "Select a variable", vbInformation, "Insert Variable"
    lblCopy.Caption = ""
    Exit Sub
  End If
  
  Call Clipboard.SetText(Fmt(m_SelectedVariable))
  lblCopy.Caption = "'" & m_SelectedVariable & "' copied to clipboard..."
End Sub

Private Sub CancelButton_Click()
  m_bApply = False
  Deactivate Me
End Sub

Private Sub OKButton_Click()
  m_bApply = True
  Deactivate Me
End Sub

Private Sub tvwVars_NodeClick(ByVal Node As MSComctlLib.Node)
  If Node.Image = 2 Then
    m_SelectedVariable = Node.key
  Else
    m_SelectedVariable = ""
  End If
End Sub

Function Fmt(VIn As String) As String
  Dim tok As Variant
  Dim vTokens() As String
  Dim ub As Long
  Dim i As Long
  Dim Ret As String
  
  tok = Split(VIn, ".")
  vTokens = tok
  ub = UBound(vTokens)
  Ret = vTokens(0)
  For i = 1 To ub
    Ret = Ret & "(""" & vTokens(i) & """)"
  Next i
  Fmt = Ret
End Function


