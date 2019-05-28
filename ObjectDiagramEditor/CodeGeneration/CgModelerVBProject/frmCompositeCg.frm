VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form frmCompositeCg 
   Caption         =   "Composite Model Wizard"
   ClientHeight    =   7395
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8085
   Icon            =   "frmCompositeCg.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   7395
   ScaleWidth      =   8085
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton btnRefreshOps 
      Caption         =   "Refresh"
      Height          =   375
      Left            =   6660
      TabIndex        =   9
      Top             =   3360
      Width           =   1335
   End
   Begin MSComctlLib.ImageList ImageList1 
      Left            =   6660
      Top             =   6540
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
            Picture         =   "frmCompositeCg.frx":0442
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "frmCompositeCg.frx":0894
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin VB.Frame frmAddedOperations 
      Caption         =   "Publish Operations"
      Height          =   3975
      Left            =   60
      TabIndex        =   7
      Top             =   3240
      Width           =   6495
      Begin MSComctlLib.TreeView tvwOps 
         Height          =   3615
         Left            =   120
         TabIndex        =   8
         Top             =   240
         Width           =   6255
         _ExtentX        =   11033
         _ExtentY        =   6376
         _Version        =   393217
         HideSelection   =   0   'False
         Indentation     =   176
         LabelEdit       =   1
         LineStyle       =   1
         Style           =   7
         Checkboxes      =   -1  'True
         ImageList       =   "ImageList1"
         Appearance      =   1
      End
   End
   Begin VB.CheckBox chViewDetails 
      Caption         =   "View Class Details"
      Height          =   255
      Left            =   3720
      TabIndex        =   6
      Top             =   2580
      Value           =   1  'Checked
      Width           =   2415
   End
   Begin VB.Frame frmButtons 
      BorderStyle     =   0  'None
      Height          =   1395
      Left            =   6660
      TabIndex        =   2
      Top             =   240
      Width           =   1455
      Begin VB.CommandButton btnCodeGeneration 
         Caption         =   "Generate Code"
         Height          =   375
         Left            =   0
         TabIndex        =   5
         Top             =   0
         Width           =   1335
      End
      Begin VB.CommandButton btnSaveProject 
         Caption         =   "Save Project"
         Height          =   375
         Left            =   0
         TabIndex        =   4
         Top             =   480
         Width           =   1335
      End
      Begin VB.CommandButton btnExit 
         Caption         =   "Exit"
         Height          =   375
         Left            =   0
         TabIndex        =   3
         Top             =   960
         Width           =   1335
      End
   End
   Begin CGModeler.ucUMLTreeView ucUMLTreeView 
      Height          =   2595
      Left            =   180
      TabIndex        =   0
      Top             =   360
      Width           =   6255
      _ExtentX        =   11033
      _ExtentY        =   4577
   End
   Begin MSComDlg.CommonDialog CommDlg 
      Left            =   5220
      Top             =   1500
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.Frame frmProjectSelection 
      Caption         =   "Project Selection"
      Height          =   3015
      Left            =   60
      TabIndex        =   1
      Top             =   120
      Width           =   6495
   End
End
Attribute VB_Name = "frmCompositeCg"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

' the following are passed in when the form is loaded
Public WithEvents m_GeCtrl As CG
Attribute m_GeCtrl.VB_VarHelpID = -1
Public m_UDIDefMgr As UDIDefMgr

Private m_Projects As Object
Private SelectedProject As rtsProject
Private SelectedPackage As rtsPackage
Private SelectedClass As rtsClass

' the following are used locally
Public m_UDIs As Collection
Public m_ConnectionInfo As Collection
Private m_bErr As Boolean
Private bTypeNotVerified As Boolean

' KAB --> need to suppress the yes / no messages
Private m_nPossibleErrors As Long

Private m_bOperationsInitialized As Boolean
Private m_classList As Collection

Private Sub GetCheckedOperations(objList() As String, opList() As String, count As Long)
  Dim aNode As Node
  Dim i As Long
  
  ReDim objList(tvwOps.nodes.count) As String
  ReDim opList(tvwOps.nodes.count) As String
  
  count = 0
  For i = 1 To tvwOps.nodes.count
    Set aNode = tvwOps.nodes(i)
    If aNode.Checked And aNode.Key <> "ROOT" And aNode.Image = 2 Then
      opList(count) = aNode.Text
      objList(count) = aNode.Parent.Text
      count = count + 1
    End If
  Next i
End Sub


Private Sub btnCodeGeneration_Click()
  Dim ClassCgAttributes As Collection
  Dim classCgOperations As Collection
  Dim aProject As rtsProject
  Dim aClass As rtsClass
  
  Dim aDictionary As Object
  Dim szProjectPath As String
  Dim szProjectName As String
  Dim szClassName As String
  Dim aInfo As rtsClass
  Dim aAttr As CgAttribute
  Dim szXML As String
  Dim ic As Long
  Dim Response As Integer
  
  ReDim objList(0) As String
  ReDim opList(0) As String
  Dim count As Long
  Call GetCheckedOperations(objList(), opList(), count)
  
  On Error GoTo Error_Handler
  m_bErr = False
  szClassName = ucUMLTreeView.ClassName
  szClassName = Replace(szClassName, " ", "_")
  If Len(szClassName) > 0 And ucUMLTreeView.ProjectName <> "" And ucUMLTreeView.PackagesName <> "" Then
    If GetCompositeCgObjects( _
      szClassName, _
      SelectedProject, _
      m_UDIs, _
      m_UDIDefMgr, _
      m_ConnectionInfo, _
      ClassCgAttributes, _
      classCgOperations, _
      objList(), _
      opList(), _
      count) Then
      
      Set aClass = New rtsClass
      aClass.Name = szClassName
           
      Dim arpProject As RPProject
      Dim aRpPackage As RPPackage
      Dim aRPClass As RPClass
      Dim bNewPackage As Boolean
      
      Set aRpPackage = SelectedPackage.obj
      Set aRPClass = aRpPackage.FindClass(szClassName)
      If aRPClass Is Nothing Then
         bNewPackage = True
         Set aRPClass = aRpPackage.addClass(szClassName)
      End If
      
      Set aClass.Class = aRPClass
      Set aClass.Project = SelectedProject
      aClass.PackageName = aRpPackage.Name
      aClass.ModelType = idxClassType_Model
      If Not AddCgObjects(aClass.PackageName, aClass.Name, aClass, ClassCgAttributes, classCgOperations, chViewDetails.Value) Then GoTo Error_Handler
      
      ' export the model document so this class can be immediately referred to as a model
      If bNewPackage Then SelectedPackage.Classes.Add aClass, aClass.Name
      GetClassInfo SelectedProject, SelectedPackage.Name, szClassName, aInfo
      
      Dim incColl As includes
      gMsgWnd.LogMessage "Composite class generation complete."
    Else
      gMsgWnd.LogMessage "Composite wizard failed to generate composite class."
    End If
  Else
    MsgBox "Please select a Project, Package, and/or enter a Class name."
  End If
  
Exit Sub
Error_Handler:
  m_bErr = True
  gMsgWnd.LogMessage "Composite wizard failed while performing code generation: " & Hex(err.Number) & ", " & err.Description
End Sub

Private Sub btnExit_Click()
    Unload Me
End Sub

Private Sub btnRefreshOps_Click()
  If Not m_bOperationsInitialized Then
    initOperations
  End If
End Sub

Private Sub btnSaveProject_Click()
  On Error GoTo Error_Handler
  If Not doc Is Nothing Then
    If Not doc.activeProject Is Nothing Then
      doc.activeProject.Save
    End If
  End If
  Exit Sub
    
Error_Handler:
  gMsgWnd.LogMessage "Error saving UML project. " & err.Description
End Sub

Private Sub Form_Load()
  Dim opt As VbMsgBoxResult
  
  On Error Resume Next
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
  
  On Error GoTo 0
  If Projects.count = 0 Then
    gMsgWnd.LogMessage "No UML project loaded.  Dialog will not be properly initialized."
    Unload Me
    Exit Sub
  End If
    
  'Populate the UML project selection control
  If Projects.count > 0 And Not ucUMLTreeView Is Nothing Then
    ucUMLTreeView.PopulateProjectsList Projects
    ucUMLTreeView.CanEditClass = True
  End If
    
  Call tvwOps.nodes.Add(, , "ROOT", "Operations", 2)
    
  GetUDIInfo
  GetConnectionInfo
  
  If m_nPossibleErrors > 0 Then
    opt = MsgBox(m_nPossibleErrors & " possible type errors were detected.  Continue?", vbYesNo, "Signal Connection Validation")
    If opt = vbNo Then
      gMsgWnd.LogMessage "Aborted"
      m_bErr = True
    End If
  End If

  On Error GoTo 0
  If m_bErr Then
    Unload Me
  End If

  
End Sub

Private Sub GetUDIInfo()
  Dim aUDI As UserDefinedItem
  Dim var As Variant
  Dim i As Long
  Dim lBnd As Long
  Dim uBnd As Long
  
  Set m_UDIs = New Collection
  m_GeCtrl.SelAllWithVariants
  m_GeCtrl.SelGetObjectVariants var

  If IsEmpty(var) Then
    Exit Sub
  End If
  
  On Error GoTo Error_Handler
  lBnd = LBound(var)
  uBnd = UBound(var)
  
  For i = lBnd To uBnd
    Set aUDI = Nothing
    Set aUDI = var(i)
    If aUDI Is Nothing Then
      m_bErr = True
      gMsgWnd.LogMessage "Invalid model detected.  Test models through the model properties dialog.  Replace problem model."
    Else
      m_UDIs.Add aUDI, aUDI.ObjectName
    End If
  Next i
  
  Exit Sub
Error_Handler:
  m_bErr = True
  If err.Number = 457 Then
    gMsgWnd.LogMessage "Objects exist with duplicate names '" & aUDI.ObjectName & "'.  Resolve the duplicate name and try again."
  Else
    gMsgWnd.LogMessage "Error detected while retrieving model properties: " & err.Number & ", " & err.Description
  End If
End Sub

Private Sub GetConnectionInfo()
  Dim opt As VbMsgBoxResult
  Dim msg As String
  
  Set m_ConnectionInfo = New Collection
  bTypeNotVerified = False
  m_GeCtrl.EnumConnectionLines
  
  m_GeCtrl.SelRemoveAll
  'm_GeCtrl.SelAdd 8853
  'm_GeCtrl.SelAdd 8854
  
  
  If bTypeNotVerified Then
        msg = "Not all connections could have their types verified.  Continue?"
        opt = MsgBox(msg, vbYesNo, "Signal Connection Validation")
        If opt = vbNo Then
          m_bErr = True
        End If
  End If
  bTypeNotVerified = False
End Sub

' The following three properties are used by the ucUMLTreeView control
' to set the currently selected project\package\class

Public Sub SetSelectedProject(selProject As rtsProject)
    Set SelectedProject = selProject
End Sub

Public Sub SetSelectedPackage(selPackage As rtsPackage)
    Set SelectedPackage = selPackage
End Sub

Public Sub SetSelectedClass(selClass As rtsClass)
    Set SelectedClass = selClass
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, y As Single)
    Screen.MousePointer = vbArrow
End Sub

Private Sub form_Resize()
    On Error Resume Next
    frmProjectSelection.Width = Abs(Me.Width - 1850)
    frmAddedOperations.Width = frmProjectSelection.Width
    ucUMLTreeView.Width = Abs(frmProjectSelection.Width - 180)
    frmProjectSelection.Height = Abs(Me.Height - 650) / 2
    frmAddedOperations.Height = frmProjectSelection.Height
    frmAddedOperations.Top = frmProjectSelection.Height + frmProjectSelection.Top + 100
    ucUMLTreeView.Height = Abs(frmProjectSelection.Height - 350)
    frmButtons.Left = frmProjectSelection.Width + 250
    chViewDetails.Left = Abs(frmButtons.Left - chViewDetails.Width - 500)
    tvwOps.Width = ucUMLTreeView.Width
    tvwOps.Width = ucUMLTreeView.Width
    tvwOps.Height = ucUMLTreeView.Height
    btnRefreshOps.Left = frmButtons.Left
    btnRefreshOps.Top = frmAddedOperations.Top + 85
End Sub


Private Sub m_GeCtrl_ConnectionChanged(ByVal Action As Integer, ByVal IDLine As Long, ByVal IDA As Long, ByVal VarA As Variant, ByVal NameA As String, ByVal TypeA As Integer, ByVal StsA As Integer, ByVal IDB As Long, ByVal VarB As Variant, ByVal NameB As String, ByVal TypeB As Integer, ByVal StsB As Integer)
  Dim aInfo As ConnectionInfo
  
  On Error Resume Next
  Set aInfo = New ConnectionInfo
  aInfo.Action = Action
  aInfo.IDLine = IDLine
  aInfo.IDA = IDA
  If Not IsEmpty(VarA) Then
    If IsObject(VarA) Then
      Set aInfo.VarA = VarA
      Set aInfo.ObjA = VarA
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
      Set aInfo.ObjB = VarB
    Else
      aInfo.VarB = VarB
    End If
  End If
  aInfo.NameB = NameB
  aInfo.TypeB = TypeB
  aInfo.StsB = StsB
  
  If aInfo.ObjA Is Nothing Or aInfo.ObjB Is Nothing Then
    m_bErr = True
    If Not aInfo.ObjA Is Nothing Then
      gMsgWnd.LogMessage "Connection line starting at '" & aInfo.ObjA.ObjectName & "' connector '" & aInfo.NameA & "' is not connected."
    ElseIf Not aInfo.ObjB Is Nothing Then
      gMsgWnd.LogMessage "Connection line ending at '" & aInfo.ObjB.ObjectName & "' connector '" & aInfo.NameB & "' is not connected."
    Else
      gMsgWnd.LogMessage "Connection line is not connected."
    End If
    Exit Sub
  End If
  
    m_ConnectionInfo.Add aInfo
  'Check to make sure connection types match.  Have to look up the type TypeB and TypeA
  'are not correct
  Dim UDIDefA As UserDefinedItemDef
  Dim UDIDefB As UserDefinedItemDef
  Dim ConnA As CgConnectionDef
  Dim ConnB As CgConnectionDef
  Dim AttrA As CgAttribute
  Dim AttrB As CgAttribute
  Dim OperA As CgOperation
  Dim OperB As CgOperation
  Dim strTypeA As String
  Dim strTypeB As String
  Dim par As CgAttribute
  Dim opt As VbMsgBoxResult
  Dim msg As String
  
  
  If m_UDIDefMgr Is Nothing Then Exit Sub
  
  Set UDIDefA = m_UDIDefMgr.UDIDefs(aInfo.ObjA.m_strDefObjectName)
  Set UDIDefB = m_UDIDefMgr.UDIDefs(aInfo.ObjB.m_strDefObjectName)
  If (Not UDIDefA Is Nothing) And (Not UDIDefB Is Nothing) Then
    Set ConnA = UDIDefA.FindConnection(aInfo.NameA)
    Set ConnB = UDIDefB.FindConnection(aInfo.NameB)
    If ConnA Is Nothing Then
        msg = "Could not verify type information for object '" & aInfo.ObjA.ObjectName & "' connection '" & aInfo.NameA & "'"
        gMsgWnd.LogMessage msg
 '       opt = MsgBox(msg & ".  Continue?", vbYesNo, "Signal Connection Validation")
 '       If opt = vbNo Then
 '         m_bErr = True
 '       End If
         bTypeNotVerified = True
    ElseIf ConnB Is Nothing Then
        msg = "Could not verify type information for object '" & aInfo.ObjB.ObjectName & "' connection '" & aInfo.NameB & "'"
        gMsgWnd.LogMessage msg
'        opt = MsgBox(msg & ".  Continue?", vbYesNo, "Signal Connection Validation")
'        If opt = vbNo Then
'          m_bErr = True
'        End If
         bTypeNotVerified = True
    Else
      
      ' TODO: for operations, we need to put a label on the operation indicating the data type.  We cannot rely on reading
      '       the type out of the return type, or out of a fixed parameter (last in this case).
      
      ' determine the type of the A side
      strTypeA = ""
      strTypeB = ""
      If ConnA.itemType = idxItemType_Attribute Then
        Set AttrA = UDIDefA.FindAttribute(ConnA.itemName)
        If Not AttrA Is Nothing Then
          strTypeA = Replace(AttrA.dataType, "*", "")
          strTypeA = Replace(strTypeA, " ", "")
        End If
      ElseIf ConnA.itemType = idxItemType_Operation Then
        Set OperA = UDIDefA.FindOperation(ConnA.itemName)
        If Not OperA Is Nothing Then
          If OperA.ReturnType <> "" And OperA.ReturnType <> "void" And OperA.ReturnType <> "HRESULT" Then
            strTypeA = Replace(OperA.ReturnType, "*", "")
          ElseIf OperA.Parameters.count > 0 Then ' read type out of last (return) parameter
            Set par = OperA.Parameters(OperA.Parameters.count)
            strTypeA = Replace(par.dataType, "*", "")
            strTypeA = Replace(strTypeA, " ", "")
          End If
        End If
      End If
      
      ' determine the type of the B side
      If ConnB.itemType = idxItemType_Attribute Then
        Set AttrB = UDIDefB.FindAttribute(ConnB.itemName)
        If Not AttrB Is Nothing Then
          strTypeB = Replace(AttrB.dataType, "*", "")
          strTypeB = Replace(strTypeB, " ", "")
        End If
      ElseIf ConnB.itemType = idxItemType_Operation Then
        Set OperB = UDIDefB.FindOperation(ConnB.itemName)
        If Not OperB Is Nothing Then
          If OperB.ReturnType <> "" And OperB.ReturnType <> "void" And OperB.ReturnType <> "HRESULT" Then
            strTypeB = Replace(OperB.ReturnType, "*", "")
          ElseIf OperB.Parameters.count > 0 Then ' read type out of last (return) parameter
            Set par = OperB.Parameters(OperB.Parameters.count)
            strTypeB = Replace(par.dataType, "*", "")
            strTypeB = Replace(strTypeB, " ", "")
          End If
        End If
      End If
      
      If strTypeA <> strTypeB Then
        msg = "Connection types '" & strTypeA & "' and '" & strTypeB & "' between '" & aInfo.ObjA.ObjectName & "' connector '" & aInfo.NameA & "' and '" & aInfo.ObjB.ObjectName & "' connector '" & aInfo.NameB & "' do not match."
        gMsgWnd.LogMessage msg
        ' KAB --> need to suppress the yes / no messages

        m_nPossibleErrors = m_nPossibleErrors + 1
      End If
    End If
  End If
  
End Sub

Private Sub initOperations()
  Dim ClassList As Collection
  Dim aClass As rtsClass
  Dim aRoot As Node
  Dim aOper As CgOperation
  Dim aUDI As UserDefinedItem
  
  On Error GoTo Error_Handler
  
  If SelectedProject Is Nothing Then
    MsgBox "Complete the project selection.", vbInformation
    Exit Sub
  End If
  
  If Not m_bOperationsInitialized Then
    MousePointer = vbHourglass
    Call GetCompositeClassOperations(SelectedProject, m_UDIs, m_UDIDefMgr)
    For Each aUDI In m_UDIs
      If Not aUDI.m_Info Is Nothing Then
        If aUDI.m_Info.ModelType = idxClassType_Model Then
          Set aClass = aUDI.m_Info
          tvwOps.nodes.Add "ROOT", tvwChild, aUDI.ObjectName, aUDI.ObjectName, 1
          For Each aOper In aClass.Operations
            tvwOps.nodes.Add aUDI.ObjectName, tvwChild, aUDI.ObjectName & "_" & aOper.Name, aOper.Name, 2
          Next
        End If
      End If
    Next
    MousePointer = vbNormal
    m_bOperationsInitialized = True
  End If
  
  Exit Sub
Error_Handler:
  MsgBox "Error building operations list: " & err.Description, vbExclamation
  MousePointer = vbNormal
End Sub

