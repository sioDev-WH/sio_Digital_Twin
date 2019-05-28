VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form frmUDIItemDefProps 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Object Definition Connector Map"
   ClientHeight    =   5670
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   7635
   Icon            =   "frmUDIDefProps.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   5670
   ScaleWidth      =   7635
   StartUpPosition =   1  'CenterOwner
   Begin MSComctlLib.TreeView tvwClassItems 
      Height          =   3555
      Left            =   4320
      TabIndex        =   15
      Top             =   2040
      Width           =   3255
      _ExtentX        =   5741
      _ExtentY        =   6271
      _Version        =   393217
      HideSelection   =   0   'False
      Indentation     =   88
      LabelEdit       =   1
      Style           =   7
      Appearance      =   1
   End
   Begin VB.TextBox lbClasses 
      Enabled         =   0   'False
      Height          =   315
      Left            =   990
      TabIndex        =   14
      Top             =   1320
      Width           =   3855
   End
   Begin VB.TextBox lbPackages 
      Enabled         =   0   'False
      Height          =   315
      Left            =   990
      TabIndex        =   13
      Top             =   900
      Width           =   3855
   End
   Begin VB.TextBox lbProjects 
      Enabled         =   0   'False
      Height          =   315
      Left            =   990
      TabIndex        =   12
      Top             =   480
      Width           =   3885
   End
   Begin VB.CommandButton btnClearItem 
      Caption         =   "< Clear >"
      Height          =   375
      Left            =   3000
      TabIndex        =   5
      ToolTipText     =   "Clear Shape assignments to selected items "
      Top             =   2760
      Width           =   1140
   End
   Begin VB.CommandButton btnAssign 
      Caption         =   "< Assign >"
      Height          =   375
      Left            =   3000
      TabIndex        =   4
      ToolTipText     =   "Assign Shape to Item "
      Top             =   2280
      Width           =   1140
   End
   Begin VB.ListBox lstShapeConnectors 
      Height          =   3570
      Left            =   30
      Sorted          =   -1  'True
      TabIndex        =   3
      Top             =   2040
      Width           =   2745
   End
   Begin VB.CommandButton btnCancel 
      Caption         =   "Cancel"
      Height          =   405
      Left            =   6000
      TabIndex        =   2
      ToolTipText     =   "Cancel changes"
      Top             =   720
      Width           =   1575
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "OK"
      Height          =   405
      Left            =   6000
      TabIndex        =   1
      ToolTipText     =   "Apply changes"
      Top             =   150
      Width           =   1575
   End
   Begin VB.TextBox txtObjectName 
      Enabled         =   0   'False
      Height          =   315
      Left            =   990
      TabIndex        =   0
      Top             =   60
      Width           =   3885
   End
   Begin MSComDlg.CommonDialog CommDlg 
      Left            =   5160
      Top             =   600
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.Label Label8 
      Alignment       =   2  'Center
      Caption         =   "Shape Connectors"
      Height          =   255
      Left            =   0
      TabIndex        =   11
      Top             =   1800
      Width           =   2805
   End
   Begin VB.Label Label9 
      Alignment       =   2  'Center
      Caption         =   "Class Items"
      Height          =   255
      Left            =   4320
      TabIndex        =   10
      Top             =   1800
      Width           =   3255
   End
   Begin VB.Label Label6 
      Alignment       =   1  'Right Justify
      Caption         =   "Package:"
      Height          =   285
      Left            =   150
      TabIndex        =   9
      Top             =   900
      Width           =   765
   End
   Begin VB.Label Label5 
      Alignment       =   1  'Right Justify
      Caption         =   "Project:"
      Height          =   285
      Left            =   120
      TabIndex        =   8
      Top             =   480
      Width           =   765
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      Caption         =   "Name:"
      Height          =   285
      Left            =   120
      TabIndex        =   7
      Top             =   60
      Width           =   795
   End
   Begin VB.Label Label2 
      Alignment       =   1  'Right Justify
      Caption         =   "Class:"
      Height          =   285
      Left            =   150
      TabIndex        =   6
      Top             =   1320
      Width           =   765
   End
End
Attribute VB_Name = "frmUDIItemDefProps"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim m_curUDIDef As UserDefinedItemDef
Dim WithEvents m_ShapeGe As CG
Attribute m_ShapeGe.VB_VarHelpID = -1
Dim m_ConnectionInfo As Collection

Private m_Projects As Object
Private SelectedProject As rtsProject
Private SelectedPackage As rtsPackage
Private SelectedClass As rtsClass
Private ClassVariables As Collection

Const IO_KEY_PREFIX As String = "IO_"
Const OP_KEY_PREFIX As String = "OP_"
Const CN_KEY_PREFIX As String = "CN_"
Const VR_KEY_PREFIX As String = "VR_"
Const BR_KEY_PREFIX As String = "BR_"

Public Property Set ShapeGe(obj As CG)
  Set m_ShapeGe = obj
End Property

Public Property Set CurUDIDef(obj As UserDefinedItemDef)
  Set m_curUDIDef = obj
End Property

Public Property Set CurrentProject(curProject As rtsProject)
  Set SelectedProject = curProject
End Property

Public Property Set CurrentPackage(curPackage As rtsPackage)
  Set SelectedPackage = curPackage
End Property

Public Property Set CurrentClass(curClass As rtsClass)
  Set SelectedClass = curClass
  FillClassItems
End Property

Private Sub btnAssign_Click()
  Dim szConnector As String
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim szItem As String
  Dim szItemSize As String
  Dim i As Long
  Dim szKeyType As String
  Dim aNode As Node
  
  On Error GoTo Error_Handler
  
  If lstShapeConnectors.ListIndex >= 0 And Not tvwClassItems.SelectedItem Is Nothing Then
    szConnector = lstShapeConnectors.List(lstShapeConnectors.ListIndex)
    For Each aNode In tvwClassItems.nodes
      If Len(aNode.Key) > 2 Then ' a leaf node key
        szKeyType = Left(aNode.Key, 3)
        On Error Resume Next
        If szKeyType = IO_KEY_PREFIX Or szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Then
          szItem = aNode.Text
          
          Set aAttr = SelectedClass.Attributes(szItem)
          If szKeyType = VR_KEY_PREFIX And err <> 0 Then
            Set aAttr = ClassVariables(szItem)
            SelectedClass.Attributes.Add aAttr
          End If
          On Error GoTo Error_Handler
          
          If aNode.Selected Then
            aAttr.ConnId = szConnector
          ElseIf aAttr.ConnId = szConnector Then
            aAttr.ConnId = ""
          End If
          
        ElseIf szKeyType = OP_KEY_PREFIX Then
          szItem = aNode.Text
          Set aOper = SelectedClass.Operations(szItem)
          
          If aNode.Selected Then
            aOper.ConnId = szConnector
          ElseIf aOper.ConnId = szConnector Then
            aOper.ConnId = ""
          End If
        End If
      End If
    Next
  End If
  
  Exit Sub
Error_Handler:
  gMsgWnd.LogMessage "Failed assignment. Error: " & err.Description
End Sub

Private Sub btnCancel_Click()
  Unload Me
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, y As Single)
  Screen.MousePointer = vbArrow
End Sub

Private Sub btnClearItem_Click()
  On Error GoTo Error_Handler
  
  Dim szConnector As String
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim szItem As String
  Dim szType As String
  Dim i As Long
  Dim aNode As Node
  Dim szKeyType As String
  
  For Each aNode In tvwClassItems.nodes
    If aNode.Selected Then
      If Len(aNode.Key) > 2 Then ' leaf node
        szKeyType = Left(aNode.Key, 3)
        On Error Resume Next
        If szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = IO_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Then
          szItem = aNode.Key
          Set aAttr = SelectedClass.Attributes(szItem)
          If szKeyType = VR_KEY_PREFIX And err <> 0 Then
            Set aAttr = ClassVariables(szItem)
          End If
          On Error GoTo Error_Handler
          
          If Not aAttr Is Nothing Then aAttr.ConnId = ""
        
        ElseIf szKeyType = OP_KEY_PREFIX Then
          szItem = aNode.Key
          Set aOper = SelectedClass.Operations(szItem)
          aOper.ConnId = ""
        End If
      End If
    End If
  Next
  
  Exit Sub
Error_Handler:
  MsgBox "Clear error: " & err.Description
End Sub

Private Sub btnOK_Click()
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim aConn As CgConnectionDef
  Dim szEventType As String
  
  On Error GoTo UnloadForm
  If m_curUDIDef Is Nothing Then
    gMsgWnd.LogMessage "Failed to save connections."
    Exit Sub
  End If
  
  While m_curUDIDef.CgConnectionDefs.count > 0
    m_curUDIDef.CgConnectionDefs.Remove 1
  Wend
  
  For Each aAttr In SelectedClass.Attributes
    If Len(aAttr.ConnId) > 0 Then
      Set aConn = New CgConnectionDef
      aConn.itemName = aAttr.Name
      aConn.itemType = idxItemType_Attribute
      aConn.attrType = aAttr.sType
      aConn.operType = 0
      aConn.connName = aAttr.ConnId
      aConn.ItemSizeName = aAttr.dim1
      m_curUDIDef.CgConnectionDefs.Add aConn
    End If
  Next

  For Each aOper In SelectedClass.Operations
    If Len(aOper.ConnId) > 0 Then
      Set aConn = New CgConnectionDef
      aConn.itemName = aOper.Name
      aConn.itemType = idxItemType_Operation
      aConn.attrType = 0
      aConn.operType = aOper.sType
      aConn.connName = aOper.ConnId
      m_curUDIDef.CgConnectionDefs.Add aConn
    End If
  Next
  
UnloadForm:
  Unload Me
End Sub

Private Sub FillClassItems()
  Dim aAttr As CgAttribute
  Dim aSubAttr As CgAttribute
  
  Dim aOper As CgOperation
  Dim szEventType As String
  Dim aInfo As rtsClass
  Dim rootNode As Node
  Dim childKey As String
  
  On Error GoTo Error_Handler
  If SelectedClass Is Nothing Then Exit Sub '
  
  Set rootNode = tvwClassItems.nodes.Add(, , "RT", "Class items")
  
  tvwClassItems.nodes.Add "RT", tvwChild, "IO", "I/O"
  For Each aAttr In SelectedClass.Attributes
    If aAttr.sType = idxAttr_Input Or aAttr.sType = idxAttr_Output Then
      childKey = IO_KEY_PREFIX & aAttr.Name
      tvwClassItems.nodes.Add "IO", tvwChild, childKey, aAttr.Name
    End If
  Next
      
  tvwClassItems.nodes.Add "RT", tvwChild, "OP", "Operation"
  For Each aOper In SelectedClass.Operations
    If Not aOper.bSim Then
      childKey = OP_KEY_PREFIX & aOper.Name
      tvwClassItems.nodes.Add "OP", tvwChild, childKey, aOper.Name
    End If
  Next
      
  tvwClassItems.nodes.Add "RT", tvwChild, "CN", "Connector"
  For Each aAttr In SelectedClass.Attributes
    If aAttr.sType = idxAttr_Connector Then
      childKey = CN_KEY_PREFIX & aAttr.Name
      tvwClassItems.nodes.Add "CN", tvwChild, childKey, aAttr.Name
    End If
  Next
      
  tvwClassItems.nodes.Add "RT", tvwChild, "VR", "Variable"
  If ClassVariables Is Nothing Then
    GetClassVariables SelectedClass, "", ClassVariables
  End If
  For Each aAttr In ClassVariables
    childKey = VR_KEY_PREFIX & aAttr.Name
    tvwClassItems.nodes.Add "VR", tvwChild, childKey, aAttr.Name
  Next
    
  tvwClassItems.nodes.Add "RT", tvwChild, "BR", "Broadcaster"
  For Each aAttr In SelectedClass.Attributes
    If aAttr.sType = idxAttr_Broadcaster Then
      childKey = BR_KEY_PREFIX & aAttr.Name
      tvwClassItems.nodes.Add "BR", tvwChild, childKey, aAttr.Name
    End If
  Next
    
  rootNode.Expanded = True
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Class Items retrieval error: " & err.Description
End Sub


Private Sub Form_Load()
  Dim SelectedProjectName As String
  Dim aInfo As ConnectionInfo
  Dim i As Long
  Dim aProject As rtsProject
   
  On Error GoTo Error_Handler
  If Projects Is Nothing Then
     GetProjects Projects, m_Projects, CommDlg
     If Not g_DrawingDefMgr.LoadModelDef() Then
         gMsgWnd.LogMessage "Error loading xml model definition"
     End If
  Else
    If Projects.count = 0 Then
       GetProjects Projects, m_Projects, CommDlg
        If Not g_DrawingDefMgr.LoadModelDef() Then
            gMsgWnd.LogMessage "Error loading xml model definition"
        End If
    End If
  End If
  
  If Projects.count = 0 Then
    MsgBox "No UML project selected.  Dialog will not be properly initialized"
  End If
   
  If Not SelectedProject Is Nothing Then
    lbProjects.Text = SelectedProject.Name
  End If
  
  If Not SelectedPackage Is Nothing Then
    lbPackages.Text = SelectedPackage.Name
  End If
  
  If Not SelectedClass Is Nothing Then
    lbClasses.Text = SelectedClass.Name
  End If
  
  txtObjectName.Text = m_curUDIDef.GeShape
  
  If m_ConnectionInfo Is Nothing Then Set m_ConnectionInfo = New Collection
  GetConnectionInfo
  For Each aInfo In m_ConnectionInfo
    lstShapeConnectors.AddItem aInfo.NameA
  Next
  InitConnectionData
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error loading Connections dialog. " & err.Description
End Sub

Sub InitConnectionData()
  Dim aConn As CgConnectionDef
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  
  On Error Resume Next
  
  If m_curUDIDef Is Nothing Then
    gMsgWnd.LogMessage "Failed to initialize connections."
    Exit Sub
  End If
  
  For Each aConn In m_curUDIDef.CgConnectionDefs
    Select Case aConn.itemType
      Case idxItemType_Attribute
        Set aAttr = SelectedClass.Attributes(aConn.itemName)
        aAttr.ConnId = aConn.connName
        
      Case idxItemType_Operation
        Set aOper = SelectedClass.Operations(aConn.itemName)
        aOper.ConnId = aConn.connName
        
    End Select
  Next
End Sub

Private Sub GetConnectionInfo()
  Dim GeID As Long
  Dim ptX As Single, ptY As Single
  
  On Error Resume Next
  m_ShapeGe.GrabHandlesEnabled = False
  m_ShapeGe.SelectAll
  m_ShapeGe.Delete
    ' set X/Y high so get off the drawing area with the dwg border being shown
  ptX = 100
  ptY = 100
  
  On Error Resume Next
  m_ShapeGe.UsePictureColor = True
  GeID = m_ShapeGe.CreateShape(m_curUDIDef.GeLibrary, m_curUDIDef.GeFolder, m_curUDIDef.GeShape, ptX, ptY)
  If GeID > 0 Then
    m_ShapeGe.CurrentPropertyID = GeID
    m_ShapeGe.SendCurrentConnectionInfo
  End If

End Sub

Private Sub lstShapeConnectors_Click()
  On Error GoTo Error_Handler
  
  Dim aNode As Node
  Dim szConnector As String
  Dim szKeyType As String
  Dim szItem As String
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  
  If lstShapeConnectors.ListIndex >= 0 Then ' And Not tvwClassItems.SelectedItem Is Nothing Then
    szConnector = lstShapeConnectors.List(lstShapeConnectors.ListIndex)
    For Each aNode In tvwClassItems.nodes
      aNode.Selected = False
      If Len(aNode.Key) > 2 Then ' a leaf node key
        szKeyType = Left(aNode.Key, 3)
        If szKeyType = IO_KEY_PREFIX Or szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Then
          szItem = aNode.Text
          
          On Error Resume Next
          Set aAttr = SelectedClass.Attributes(szItem)
          If szKeyType = VR_KEY_PREFIX And err <> 0 Then
            Set aAttr = ClassVariables(szItem)
            SelectedClass.Attributes.Add aAttr
          End If
          On Error GoTo Error_Handler
          
          If aAttr.ConnId = szConnector Then
            aNode.Selected = True
          End If
          
        ElseIf szKeyType = OP_KEY_PREFIX Then
          szItem = aNode.Text
          Set aOper = SelectedClass.Operations(szItem)
          
          If aOper.ConnId = szConnector Then
            aNode.Selected = True
          End If
        End If
      End If
    Next
  End If

  Exit Sub
Error_Handler:
  MsgBox "Connector shape click error: " & err.Description
End Sub

Private Sub m_ShapeGe_ConnectionChanged(ByVal Action As Integer, ByVal IDLine As Long, ByVal IDA As Long, ByVal VarA As Variant, ByVal NameA As String, ByVal TypeA As Integer, ByVal StsA As Integer, ByVal IDB As Long, ByVal VarB As Variant, ByVal NameB As String, ByVal TypeB As Integer, ByVal StsB As Integer)
  Dim aInfo As ConnectionInfo
  
  On Error Resume Next
  Set aInfo = New ConnectionInfo
  aInfo.Action = Action
  aInfo.IDLine = IDLine
  aInfo.IDA = IDA
  If Not IsEmpty(VarA) Then
    If IsObject(VarA) Then
      Set aInfo.VarA = VarA
    Else
      aInfo.VarA = VarA
    End If
  End If
  aInfo.NameA = NameA
  aInfo.TypeA = TypeA
  aInfo.StsA = StsA
  aInfo.IDB = IDB
  If Not IsEmpty(VarB) Then
    If IsObject(VarB) Then
      Set aInfo.VarB = VarB
    Else
      aInfo.VarB = VarB
    End If
  End If
  aInfo.NameB = NameB
  aInfo.TypeB = TypeB
  aInfo.StsB = StsB
  
  m_ConnectionInfo.Add aInfo, aInfo.NameA
End Sub

Private Sub txtObjectName_Change()
  If Not m_curUDIDef Is Nothing Then
      m_curUDIDef.ObjectName = txtObjectName
  End If
End Sub
