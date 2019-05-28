VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.UserControl ctlEquationEditor 
   ClientHeight    =   6630
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   9030
   ScaleHeight     =   6630
   ScaleWidth      =   9030
   Begin VB.ListBox lstSuffix 
      Height          =   840
      ItemData        =   "ctlEquationEditor.ctx":0000
      Left            =   8040
      List            =   "ctlEquationEditor.ctx":0010
      TabIndex        =   10
      Top             =   4440
      Width           =   855
   End
   Begin VB.CommandButton btnTest 
      Caption         =   "Test"
      Height          =   375
      Left            =   8040
      TabIndex        =   9
      Top             =   1440
      Width           =   855
   End
   Begin VB.Frame frmInsert 
      Caption         =   "Insert"
      Height          =   1095
      Left            =   7950
      TabIndex        =   4
      Top             =   3030
      Width           =   975
      Begin VB.CommandButton btnInsertVar 
         Caption         =   "Insert"
         Enabled         =   0   'False
         Height          =   300
         Left            =   120
         TabIndex        =   7
         ToolTipText     =   "Manual insert"
         Top             =   720
         Width           =   735
      End
      Begin VB.OptionButton optManual 
         Caption         =   "Manual"
         Height          =   255
         Left            =   50
         TabIndex        =   6
         Top             =   480
         Width           =   900
      End
      Begin VB.OptionButton optAuto 
         Caption         =   "Auto"
         Height          =   255
         Left            =   50
         TabIndex        =   5
         Top             =   240
         Value           =   -1  'True
         Width           =   900
      End
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   8040
      TabIndex        =   2
      Top             =   120
      Width           =   855
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   8040
      TabIndex        =   3
      Top             =   600
      Width           =   855
   End
   Begin VB.TextBox txtEqnBody 
      Height          =   2655
      Left            =   120
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   0
      Top             =   120
      Width           =   7815
   End
   Begin MSComctlLib.ImageList ImageList1 
      Left            =   8040
      Top             =   2160
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   4
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "ctlEquationEditor.ctx":0033
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "ctlEquationEditor.ctx":0485
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "ctlEquationEditor.ctx":08D7
            Key             =   ""
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "ctlEquationEditor.ctx":0D29
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.TreeView tvwVars 
      Height          =   3375
      Left            =   120
      TabIndex        =   1
      Top             =   3120
      Width           =   7815
      _ExtentX        =   13785
      _ExtentY        =   5953
      _Version        =   393217
      HideSelection   =   0   'False
      Indentation     =   176
      LabelEdit       =   1
      LineStyle       =   1
      Style           =   7
      ImageList       =   "ImageList1"
      Appearance      =   1
   End
   Begin VB.Label lblSuffix 
      Caption         =   "Suffix:"
      Height          =   255
      Left            =   8040
      TabIndex        =   11
      Top             =   4200
      Width           =   855
   End
   Begin VB.Line Line4 
      BorderWidth     =   3
      X1              =   20
      X2              =   20
      Y1              =   0
      Y2              =   6600
   End
   Begin VB.Line Line3 
      BorderWidth     =   3
      X1              =   9000
      X2              =   9000
      Y1              =   0
      Y2              =   6600
   End
   Begin VB.Line Line2 
      BorderWidth     =   3
      X1              =   0
      X2              =   9000
      Y1              =   6600
      Y2              =   6600
   End
   Begin VB.Line Line1 
      BorderWidth     =   3
      X1              =   0
      X2              =   9000
      Y1              =   20
      Y2              =   20
   End
   Begin VB.Label Label1 
      Caption         =   "Model Variables:"
      Height          =   255
      Left            =   120
      TabIndex        =   8
      Top             =   2880
      Width           =   6855
   End
End
Attribute VB_Name = "ctlEquationEditor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_sp As OnScriptParser
Private m_vm As clsVarManager
Private m_st As ctlMessageWindow
Private m_bVarsInitialized As Boolean
Private m_SelectedVariable As String

Private Declare Function ShowWindow Lib "user32" (ByVal hwnd As Long, ByVal nCmdShow As Long) As Long
Private Const SW_HIDE As Long = 0
Private Const SW_MINIMIZE As Long = 6
Private Const SW_MAXIMIZE As Long = 3
Private Const SW_NORMAL As Long = 1
Private Const SW_MAX As Long = 10

Public GridIndex As Long
Public EqnIndex As Long
Public eqnName As String
Public Event OnApply(GridIndex As Long, EqnIndex As Long, sScript As String)
Public Event OnCancel()

Public Sub init(sp As OnScriptParser, vm As clsVarManager, st As ctlMessageWindow)
  Set m_sp = sp
  Set m_vm = vm
  Set m_st = st
  If m_vm.CVars.Count > 0 Then
    initVarNodes
  End If
End Sub

Public Sub Destroy()
  Set m_sp = Nothing
  Set m_vm = Nothing
  Set m_st = Nothing
End Sub

Public Property Let EqnBody(newVal As String)
  txtEqnBody.Text = IIf(Len(newVal) = 0, "res = ", newVal)
  initVarNodes
End Property

Public Property Get EqnBody() As String
  EqnBody = txtEqnBody.Text
End Property


Private Sub initVarNodes()
  Dim aCVar As clsCVar
  Dim aVar As clsVar
  Dim aRoot As Node
  Dim aNode As Node
  Dim rootKey As String
  
  On Error GoTo error_handler
  
  If Not m_bVarsInitialized Then
    rootKey = "ROOT"
    tvwVars.Nodes.Clear
    Set aRoot = tvwVars.Nodes.Add(, , rootKey, "Variables", 3)
    For Each aCVar In m_vm.CVars
      If aCVar.Root Then
        Set aNode = tvwVars.Nodes.Add(rootKey, tvwChild, aCVar.longName, aCVar.Name, 1)
        initVarNode aCVar
      End If
    Next
    
    For Each aVar In m_vm.vars
      If aVar.Root Then
        Set aNode = tvwVars.Nodes.Add(rootKey, tvwChild, aVar.longName, aVar.Name, 2)
      End If
    Next
    m_bVarsInitialized = True
    aRoot.Expanded = True
  End If
  
  Exit Sub
error_handler:
  MsgBox "Error initializing variable nodes: " & Err.Description, vbInformation
End Sub

Private Sub initVarNode(cv As clsCVar)
  Dim obj As Object
  Dim aCVar As clsCVar
  Dim aVar As clsVar
  Dim i As Long
  Dim aNode As Node
  For i = 1 To cv.Count
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

Private Sub btnInsertVar_Click()
  If Len(m_SelectedVariable) = 0 Then
    MsgBox "Select a variable", vbInformation, "Insert Variable"
  Else
    InsertVar
  End If
End Sub

Private Sub InsertVar()
  Dim iStart As Long
  Dim sVar As String
  
  sVar = Fmt(m_SelectedVariable)
  Select Case lstSuffix.ListIndex
    Case 0
      sVar = sVar & " "
    Case 1
      sVar = sVar & ".der(1) "
    Case 2
      sVar = sVar & ".der(2) "
    Case 3
      sVar = sVar & ".der(3) "
    Case Else
      sVar = sVar & " "
  End Select
  iStart = txtEqnBody.SelStart
  txtEqnBody.Text = Left(txtEqnBody.Text, iStart) & sVar & Mid(txtEqnBody.Text, iStart + 1)
  txtEqnBody.SetFocus
  txtEqnBody.SelStart = iStart + Len(sVar)
End Sub

Private Sub btnTest_Click()
  Dim sName As String
  Dim sScript As String
  Dim sFinalScript As String
  Dim bErr As Boolean
  Dim retVal As Double
  Dim errLine As Long
  Dim errCol As Long
  Dim errDesc As String
  Dim errText As String
  
  Dim vBody As Variant
  Dim vecBody() As String
  Dim maxLine As Long
  Dim i As Long
  Dim charCount As Long
  Dim sMsg As String
  
  On Error GoTo error_handler
  
  sName = eqnName
  
  If Len(sName) = 0 Then
    sMsg = "Equation name cannot be zero length"
    m_st.LogMessage sMsg
    MsgBox sMsg, vbInformation, "Test Equation"
    Exit Sub
  ElseIf IsNumeric(Left(sName, 1)) Then
    sMsg = "Equation name cannot begin with a number"
    m_st.LogMessage sMsg
    MsgBox sMsg, vbInformation, "Test Equation"
    Exit Sub
  End If
  
  sScript = txtEqnBody.Text
  Call m_sp.Test(sName, sScript, sFinalScript, bErr, retVal, errLine, errCol, errDesc, errText)
  If bErr Then
    vBody = Split(sFinalScript, Chr(10))
    vecBody = vBody
    maxLine = UBound(vecBody)
    charCount = 0
    For i = 1 To errLine - 2
      charCount = charCount + Len(vecBody(i)) + 1
    Next i
    charCount = charCount + errCol
    txtEqnBody.SetFocus
    txtEqnBody.SelStart = charCount
    'txtEqnBody.SelLength = 1
    sMsg = "'" & sName & "' equation errors detected:  " & errDesc & " in '" & errText & "'"
    m_st.LogMessage sMsg
    MsgBox sMsg, vbInformation, "Equation Test"
  Else
    m_st.LogMessage "'" & sName & "' equation result: " & retVal
  End If
  
  Exit Sub
error_handler:
  m_st.LogMessage "Unhandled errors in test of equation '" & sName & "': " & Err.Description
End Sub

Private Sub CancelButton_Click()
  RaiseEvent OnCancel
  ShowWindow hwnd, SW_HIDE
End Sub

Private Sub OKButton_Click()
  RaiseEvent OnApply(GridIndex, EqnIndex, txtEqnBody.Text)
  ShowWindow hwnd, SW_HIDE
End Sub

Private Sub optAuto_Click()
  If optAuto.Value Then
    btnInsertVar.Enabled = False
  End If
End Sub

Private Sub optManual_Click()
  If optManual.Value Then
    btnInsertVar.Enabled = True
  End If
End Sub

Private Sub tvwVars_Collapse(ByVal Node As MSComctlLib.Node)
  If Node.key = "ROOT" Then
    Node.Image = 3
  End If
End Sub

Private Sub tvwVars_Expand(ByVal Node As MSComctlLib.Node)
  If Node.key = "ROOT" Then
    Node.Image = 4
  End If
End Sub

Private Sub tvwVars_NodeClick(ByVal Node As MSComctlLib.Node)
  If Node.Image = 2 Then
    m_SelectedVariable = Node.key
    If optAuto.Value Then
      InsertVar
    End If
  Else
    m_SelectedVariable = ""
  End If
End Sub

Function Fmt(VIn As String) As String
  On Error GoTo error_handler
  
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
  
  Exit Function
error_handler:
  m_st.LogMessage "Unhandled error while formatting variable '" & VIn & "': " & Err.Description
End Function

Private Sub UserControl_Initialize()
  lstSuffix.ListIndex = 0
End Sub

Private Sub UserControl_Show()
  On Error Resume Next
  txtEqnBody.SetFocus
  txtEqnBody.SelStart = Len(txtEqnBody.Text)
End Sub
