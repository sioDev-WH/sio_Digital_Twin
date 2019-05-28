VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Object = "{E6F77CB3-6A30-11D5-89E6-00D0B74A80C3}#1.0#0"; "CGCtrl.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Object = "{BDC217C8-ED16-11CD-956C-0000C04E4C0A}#1.1#0"; "TABCTL32.OCX"
Begin VB.Form frmUDItemDefs 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Shape - Model associations"
   ClientHeight    =   4380
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   8340
   Icon            =   "frmUDItemDefs.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   4380
   ScaleWidth      =   8340
   StartUpPosition =   1  'CenterOwner
   Begin TabDlg.SSTab tabAssociation 
      Height          =   4215
      Left            =   0
      TabIndex        =   0
      Top             =   120
      Width           =   8295
      _ExtentX        =   14631
      _ExtentY        =   7435
      _Version        =   393216
      Style           =   1
      Tabs            =   2
      TabsPerRow      =   2
      TabHeight       =   520
      TabCaption(0)   =   "Class mapping"
      TabPicture(0)   =   "frmUDItemDefs.frx":0442
      Tab(0).ControlEnabled=   -1  'True
      Tab(0).Control(0)=   "lblObjectDefinitions"
      Tab(0).Control(0).Enabled=   0   'False
      Tab(0).Control(1)=   "lblProjectClasses"
      Tab(0).Control(1).Enabled=   0   'False
      Tab(0).Control(2)=   "CommDlg"
      Tab(0).Control(2).Enabled=   0   'False
      Tab(0).Control(3)=   "lstObjectDefinitions1"
      Tab(0).Control(3).Enabled=   0   'False
      Tab(0).Control(4)=   "UMLTreeView"
      Tab(0).Control(4).Enabled=   0   'False
      Tab(0).Control(5)=   "btnCreateItem"
      Tab(0).Control(5).Enabled=   0   'False
      Tab(0).Control(6)=   "btnAssignClassToUDIDef"
      Tab(0).Control(6).Enabled=   0   'False
      Tab(0).ControlCount=   7
      TabCaption(1)   =   "Shape mapping"
      TabPicture(1)   =   "frmUDItemDefs.frx":045E
      Tab(1).ControlEnabled=   0   'False
      Tab(1).Control(0)=   "Label5"
      Tab(1).Control(0).Enabled=   0   'False
      Tab(1).Control(1)=   "lblLibraryShapes"
      Tab(1).Control(1).Enabled=   0   'False
      Tab(1).Control(2)=   "Label11"
      Tab(1).Control(2).Enabled=   0   'False
      Tab(1).Control(3)=   "ShapeGe"
      Tab(1).Control(3).Enabled=   0   'False
      Tab(1).Control(4)=   "tvwShapes"
      Tab(1).Control(4).Enabled=   0   'False
      Tab(1).Control(5)=   "lstObjectDefinitions2"
      Tab(1).Control(5).Enabled=   0   'False
      Tab(1).Control(6)=   "btnClearShape(1)"
      Tab(1).Control(6).Enabled=   0   'False
      Tab(1).Control(7)=   "btnAssignShape"
      Tab(1).Control(7).Enabled=   0   'False
      Tab(1).ControlCount=   8
      Begin VB.CommandButton btnAssignClassToUDIDef 
         Caption         =   "< Assign >"
         Height          =   375
         Left            =   3720
         TabIndex        =   11
         Top             =   3480
         Width           =   885
      End
      Begin VB.CommandButton btnCreateItem 
         Caption         =   "New >"
         Height          =   375
         Left            =   3720
         TabIndex        =   10
         ToolTipText     =   "Create new Shape-Class association item"
         Top             =   3000
         Width           =   885
      End
      Begin CGModeler.ucUMLTreeView UMLTreeView 
         Height          =   3375
         Left            =   120
         TabIndex        =   14
         Top             =   720
         Width           =   5415
         _ExtentX        =   9551
         _ExtentY        =   5953
      End
      Begin VB.ListBox lstObjectDefinitions1 
         Height          =   3180
         ItemData        =   "frmUDItemDefs.frx":047A
         Left            =   5700
         List            =   "frmUDItemDefs.frx":047C
         Sorted          =   -1  'True
         TabIndex        =   9
         Top             =   840
         Width           =   2445
      End
      Begin VB.CommandButton btnAssignShape 
         Caption         =   "< Assign >"
         Height          =   375
         Left            =   -72300
         TabIndex        =   3
         ToolTipText     =   "Assign Item to Shape"
         Top             =   1860
         Width           =   885
      End
      Begin VB.CommandButton btnClearShape 
         Caption         =   "< Clear >"
         Height          =   375
         Index           =   1
         Left            =   -72300
         TabIndex        =   2
         ToolTipText     =   "Clear Shape Assigned to Item "
         Top             =   2340
         Width           =   885
      End
      Begin VB.ListBox lstObjectDefinitions2 
         Height          =   3180
         ItemData        =   "frmUDItemDefs.frx":047E
         Left            =   -74880
         List            =   "frmUDItemDefs.frx":0480
         Sorted          =   -1  'True
         TabIndex        =   1
         Top             =   780
         Width           =   2445
      End
      Begin MSComctlLib.TreeView tvwShapes 
         Height          =   3195
         Left            =   -71280
         TabIndex        =   4
         Top             =   780
         Width           =   2445
         _ExtentX        =   4313
         _ExtentY        =   5636
         _Version        =   393217
         HideSelection   =   0   'False
         Indentation     =   88
         LabelEdit       =   1
         Style           =   7
         SingleSel       =   -1  'True
         Appearance      =   1
      End
      Begin CGCtrlLib.CG ShapeGe 
         Height          =   1755
         Left            =   -68700
         TabIndex        =   5
         Top             =   1560
         Width           =   1695
         _Version        =   65536
         _ExtentX        =   2990
         _ExtentY        =   3096
         _StockProps     =   64
      End
      Begin MSComDlg.CommonDialog CommDlg 
         Left            =   3900
         Top             =   3720
         _ExtentX        =   847
         _ExtentY        =   847
         _Version        =   393216
      End
      Begin VB.Label lblProjectClasses 
         Alignment       =   2  'Center
         Caption         =   "Project Classes"
         Height          =   195
         Left            =   180
         TabIndex        =   12
         Top             =   450
         Width           =   2355
      End
      Begin VB.Label lblObjectDefinitions 
         Alignment       =   2  'Center
         Caption         =   "Object Definitions"
         Height          =   375
         Left            =   5700
         TabIndex        =   13
         Top             =   480
         Width           =   2415
      End
      Begin VB.Label Label11 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Object Definitions"
         Height          =   195
         Left            =   -74880
         TabIndex        =   8
         Top             =   480
         Width           =   2460
      End
      Begin VB.Label lblLibraryShapes 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Library Shapes"
         Height          =   195
         Left            =   -71400
         TabIndex        =   7
         Top             =   480
         Width           =   2385
      End
      Begin VB.Label Label5 
         Alignment       =   2  'Center
         Caption         =   "Shape Preview"
         Height          =   210
         Left            =   -68700
         TabIndex        =   6
         Top             =   1260
         Width           =   1695
      End
   End
   Begin VB.Menu mnuObjectDefsRoot 
      Caption         =   ""
      Visible         =   0   'False
      Begin VB.Menu mnuObjectDefs 
         Caption         =   "Rename..."
         Index           =   0
      End
      Begin VB.Menu mnuObjectDefs 
         Caption         =   "Delete"
         Index           =   1
      End
      Begin VB.Menu mnuObjectDefs 
         Caption         =   "-"
         Index           =   2
      End
      Begin VB.Menu mnuObjectDefs 
         Caption         =   "Edit Attributes..."
         Index           =   3
      End
      Begin VB.Menu mnuObjectDefs 
         Caption         =   "Edit connections..."
         Index           =   4
      End
   End
End
Attribute VB_Name = "frmUDItemDefs"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
'
'======================================================================================
Option Explicit

'========================================================
' Declarations
'========================================================

Private m_Projects As Collection
Private m_GeLbrMgr As GeLibraryMgr
Private m_strLibName As String

Private m_bConstructing As Boolean
Private m_bSettingProps As Boolean
Private m_bModified As Boolean
Private m_UDIDefMgr As UDIDefMgr

Private SelectedProjectName As String
Private SelectedProject As rtsProject
Private SelectedPackage As rtsPackage
Private SelectedClass As rtsClass

Const FOLDER_KEY_PREFIX As String = "F_"
Const SHAPE_KEY_PREFIX As String = "S_"

'======================================================================================
' End Declarations
'======================================================================================

Public Property Get IsModified() As Boolean
  IsModified = m_bModified
End Property

' The following three properties are used by the UMLTreeView control
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

Public Property Let LibraryName(ByVal strName As String)
  m_strLibName = strName
End Property

Public Property Set UDIDefMgr(obj As UDIDefMgr)
  Set m_UDIDefMgr = obj
End Property

Private Sub btnCreateItem_Click()
  Dim strName As String
  Dim pDef As UserDefinedItemDef
  Dim aCI As rtsClass
  Dim aAttr As CgAttribute
  Dim newAttr As CgAttribute
  Dim aProject As rtsProject
  Dim i As Integer
  
  If Len(UMLTreeView.ProjectName) = 0 Or Len(UMLTreeView.PackagesName) = 0 Or Len(UMLTreeView.ClassName) = 0 Then
    MsgBox "Select a project class", vbInformation
  End If
  
  On Error Resume Next
  Err.Clear
  If Projects Is Nothing Then
    GetProjects Projects, m_Projects, CommDlg
  Else
    If Projects.count = 0 Then
      GetProjects Projects, m_Projects, CommDlg
    End If
  End If

  If Projects.count = 0 Then
    MsgBox "No UML project selected.  Dialog will not be properly initialized"
  End If

  For i = 1 To Projects.count
    If doc.activeProject.Name = Projects(i).Name Then
      Set aProject = Projects(i)
      Exit For
    End If
  Next i

  strName = UMLTreeView.ClassName & "Link"
      
  If Not m_UDIDefMgr Is Nothing Then
get_unique_name:
    Set pDef = m_UDIDefMgr.GetUDIDefbyObjectName(strName)
    If Not pDef Is Nothing Then
      generateName strName
      GoTo get_unique_name
    End If
    
    Set pDef = m_UDIDefMgr.CreateUDIDefFromObjectName(strName)
    
    pDef.ProjectName = UMLTreeView.ProjectName
    pDef.packageName = UMLTreeView.PackagesName
    pDef.ClassName = UMLTreeView.ClassName
    
    If GetClassInfo(aProject, pDef.packageName, pDef.ClassName, aCI, True) Then
      pDef.packageName = aCI.packageName
      If Not aCI Is Nothing Then
        For Each aAttr In aCI.Attributes
          Set newAttr = New CgAttribute
          aAttr.Copy newAttr
          pDef.Attributes.Add newAttr
        Next
      End If
    Else
      gMsgWnd.LogMessage "Failed to Create new Association item"
    End If

    lstObjectDefinitions1.AddItem pDef.ObjectName
    lstObjectDefinitions2.AddItem pDef.ObjectName
    For i = 0 To lstObjectDefinitions1.ListCount - 1
      If lstObjectDefinitions1.List(i) = pDef.ObjectName Then
        lstObjectDefinitions1.ListIndex = i
        lstObjectDefinitions2.ListIndex = i
        Exit For
      End If
    Next i
    
    pDef.IsDirty = True
  End If
End Sub

Private Sub generateName(strName As String)
  Dim iLoc As Long
  Dim iVal As Long
  Dim strVal As String
  
  iLoc = InStrRev(strName, "_")
  If iLoc > 0 Then
    strVal = Mid(strName, iLoc + 1)
    If IsNumeric(strVal) Then
      iVal = CLng(strVal)
      strName = Left(strName, iLoc) & CStr(iVal + 1)
    Else
      strName = strName & "_1"
    End If
  Else
    strName = strName & "_1"
  End If
  
End Sub

Private Sub Form_Activate()
  Static bFirst As Boolean
  On Error Resume Next
  If Not bFirst Then
    bFirst = True
    DoInit
  End If
End Sub

Private Sub Form_Initialize()
  Set m_GeLbrMgr = New GeLibraryMgr
End Sub

Private Sub Form_Load()
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
  
  'Populate the UML project selection control
  If Projects.count > 0 Then
    UMLTreeView.PopulateProjectsList Projects
  End If
  
  lstObjectDefinitions1.ListIndex = -1
  lstObjectDefinitions2.ListIndex = -1
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
  Screen.MousePointer = vbArrow
End Sub

Private Sub Form_Terminate()
  On Error Resume Next
  Set m_GeLbrMgr = Nothing
  Set m_UDIDefMgr = Nothing
End Sub

Private Sub DoInit()
  Dim bRet As Boolean
  
  On Error Resume Next
  ShapeGe.Enabled = False  '  accept no user input!
  ShapeGe.InitNew
  ShapeGe.MarginDisplay = False
  ShapeGe.Grid = False
  
  If Len(m_strLibName) > 0 Then
    ShapeGe.AttachLibrary m_strLibName
    bRet = m_GeLbrMgr.OpenLibrary(m_strLibName, True)
    If bRet Then InitLibraryLists
  End If
  InitLists
End Sub

'------------------------------
Private Sub InitLists()
  ' populate category
  Dim i As Long
  Dim objDef As UserDefinedItemDef
  Dim strFolder As String
    
  On Error Resume Next
  If Not m_UDIDefMgr Is Nothing Then
    m_bConstructing = True
    For i = 1 To m_UDIDefMgr.NumUDIDefs
      Set objDef = m_UDIDefMgr.UDIDef(i)
      lstObjectDefinitions1.AddItem objDef.ObjectName
      lstObjectDefinitions2.AddItem objDef.ObjectName
    Next i
    If lstObjectDefinitions1.ListCount > 0 Then lstObjectDefinitions1.ListIndex = 0
    If lstObjectDefinitions2.ListCount > 0 Then lstObjectDefinitions2.ListIndex = 0
    m_bConstructing = False
  End If
End Sub

Private Sub lstObjectDefinitions1_Click()
  On Error Resume Next
  Dim objDef As UserDefinedItemDef
  Dim idx As Long
  
  m_bSettingProps = True
  If m_bConstructing Then Exit Sub
  idx = lstObjectDefinitions1.ListIndex
  If idx >= 0 Then
    lstObjectDefinitions2.ListIndex = idx
    If Not m_UDIDefMgr Is Nothing Then
      Set objDef = m_UDIDefMgr.GetUDIDefbyObjectName(lstObjectDefinitions1.List(idx))
      If Not objDef Is Nothing Then
        
        If UMLTreeView.ProjectName <> objDef.ProjectName Then UMLTreeView.ProjectName = objDef.ProjectName
        If UMLTreeView.PackagesName <> objDef.packageName Then UMLTreeView.PackagesName = objDef.packageName
        If UMLTreeView.ClassName <> objDef.ClassName Then UMLTreeView.ClassName = objDef.ClassName
      Else
        gMsgWnd.LogMessage "Error retrieving object properties."
      End If
    End If
  End If
  m_bSettingProps = False
End Sub

Private Sub lstObjectDefinitions2_Click()
  'On Error Resume Next
  Dim objDef As UserDefinedItemDef
  Dim idx As Long
  Dim aNode As Node
  Dim FolderName As String
  Dim ShapeName As String
  
  m_bSettingProps = True
  If m_bConstructing Then Exit Sub
  idx = lstObjectDefinitions2.ListIndex
  If idx >= 0 Then
    If Not m_UDIDefMgr Is Nothing Then
      Set objDef = m_UDIDefMgr.GetUDIDefbyObjectName(lstObjectDefinitions2.List(idx))
      If Not objDef Is Nothing Then
        For Each aNode In tvwShapes.nodes
          If GetNodeFolderAndShapeName(aNode, FolderName, ShapeName) Then
            If objDef.GeFolder = FolderName And objDef.GeShape = ShapeName Then
              aNode.Selected = True
              tvwShapes_NodeClick aNode
              Exit For
            End If
          End If
        Next
      End If
    End If
  End If
  m_bSettingProps = False
End Sub

'==================================================================
' Shapes
'==================================================================

Private Sub ShowShape(strFolder As String, strShape As String)
  Dim GeID As Long
  Dim strpath As String
  Dim ptX As Single, ptY As Single
  
  On Error Resume Next
  ShapeGe.GrabHandlesEnabled = False
  ShapeGe.SelectAll
  ShapeGe.Delete
    ' set X/Y high so get off the drawing area with the dwg border being shown
  ptX = 100
  ptY = 100
  GeID = ShapeGe.CreateShape(m_strLibName, strFolder, strShape, ptX, ptY)
  If GeID > 0 Then
    ' explode it
    ShapeGe.SelectAll
    ShapeGe.OnExplodeShape
  End If
  ShapeGe.ZoomExtents
End Sub

Private Sub InitLibraryLists()
  Dim i As Long
  Dim j As Long
  Dim collFolders As Collection
  Dim collShapes As Collection
  Dim folderKey As String
  Dim shapeKey As String
  Dim rootNode As Node
  
  On Error Resume Next
  m_bConstructing = True
  Set collFolders = New Collection
  Set collShapes = New Collection
  Set rootNode = tvwShapes.nodes.Add(, , "ROOT", "Library shapes")
  If m_GeLbrMgr.GetAllFolders(collFolders) Then
    For i = 1 To collFolders.count
      folderKey = FOLDER_KEY_PREFIX & Format(i, "0000")
      tvwShapes.nodes.Add "ROOT", tvwChild, folderKey, collFolders(i)
      If m_GeLbrMgr.GetAllShapesForFolder(collShapes, collFolders(i)) Then
        For j = 1 To collShapes.count
          shapeKey = folderKey & SHAPE_KEY_PREFIX & Format(j, "0000")
          tvwShapes.nodes.Add folderKey, tvwChild, shapeKey, collShapes(j).ShapeName
        Next j
      End If
    Next i
  End If
  rootNode.Expanded = True
  m_bConstructing = False
End Sub


'==================================================================
' UDIDefs
'==================================================================

Private Sub btnAssignShape_Click()
  Dim FolderName As String, ShapeName As String
  If GetFolderAndShapeName(FolderName, ShapeName) Then
    AssignShapeToCurItemDef True
  End If
End Sub

Private Sub btnClearShape_Click(Index As Integer)
  On Error Resume Next
  AssignShapeToCurItemDef False
End Sub


Private Sub AssignShapeToCurItemDef(bAssign As Boolean)
  ' assign/unassign
  Dim objDef As UserDefinedItemDef
  Dim FolderName As String, ShapeName As String
  Dim UserObjName As String
  Dim i As Long
  
  On Error Resume Next
  If lstObjectDefinitions2.ListIndex >= 0 Then
    UserObjName = lstObjectDefinitions2.List(lstObjectDefinitions2.ListIndex)
    Set objDef = m_UDIDefMgr.GetUDIDefbyObjectName(UserObjName)
    If Not objDef Is Nothing Then
      If bAssign Then
        If GetFolderAndShapeName(FolderName, ShapeName) Then
          objDef.GeLibrary = m_strLibName
          objDef.GeFolder = FolderName
          objDef.GeShape = ShapeName
        End If
      Else
        ' clear it
        objDef.GeLibrary = ""
        objDef.GeFolder = ""
        objDef.GeShape = ""
      End If
    End If
    m_UDIDefMgr.IsDirty = True
    
  End If

End Sub

Private Sub lstObjectDefinitions1_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
  If Button = 2 Then
    PopupMenu mnuObjectDefsRoot
  End If
End Sub

Private Sub lstObjectDefinitions2_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
  If Button = 2 Then
    PopupMenu mnuObjectDefsRoot
  End If
End Sub

Private Sub mnuObjectDefs_Click(Index As Integer)
  Dim szObjDefName As String
  Dim idx As Long
  
  If tabAssociation.Tab = 0 Then
    idx = lstObjectDefinitions1.ListIndex
  Else
    idx = lstObjectDefinitions2.ListIndex
  End If
  
  If idx >= 0 Then
    szObjDefName = lstObjectDefinitions1.List(idx)
    Select Case Index
      Case 0
        DoObjectDefRename idx, szObjDefName
      Case 1
        DoObjectDelete idx, szObjDefName
      Case 2
        ' --
      Case 3
        DoObjectDefEditAttributes szObjDefName
      Case 4
        DoObjectDefEditConnections szObjDefName
    End Select
  End If
End Sub

Private Sub DoObjectDefRename(idxObjDef As Long, szObjDefName As String)
  Dim pDef As UserDefinedItemDef
  Dim newName As String
  
  If Not m_UDIDefMgr Is Nothing Then
    Set pDef = m_UDIDefMgr.GetUDIDefbyObjectName(szObjDefName)
    If Not pDef Is Nothing Then
      newName = InputBox("Enter new name:", "Object Definition Name <Caution: renaming object definitions will break the link to existing instances>", szObjDefName)
      If Len(newName) > 0 Then
        pDef.ObjectName = newName
        lstObjectDefinitions1.List(idxObjDef) = newName
        lstObjectDefinitions2.List(idxObjDef) = newName
      End If
    End If
  End If
  m_UDIDefMgr.IsDirty = True
End Sub
    
Private Sub DoObjectDelete(idxObjDef As Long, szObjDefName As String)
  If Not m_UDIDefMgr Is Nothing Then
    m_UDIDefMgr.DeleteUDIDef szObjDefName
    lstObjectDefinitions1.RemoveItem idxObjDef
    lstObjectDefinitions2.RemoveItem idxObjDef
  End If
  m_UDIDefMgr.IsDirty = True
End Sub

Private Sub DoObjectDefEditAttributes(szObjDefName As String)
  Dim frm As frmUDItemDefVars
  Dim objDef As UserDefinedItemDef
  
  If Not m_UDIDefMgr Is Nothing Then
    Set objDef = m_UDIDefMgr.GetUDIDefbyObjectName(szObjDefName)
    If Not objDef Is Nothing Then
      Set frm = New frmUDItemDefVars
      Set frm.m_curUDIDef = objDef
      frm.m_bDef = True
      frm.Show vbModal, Me
    End If
  End If
End Sub

Private Sub DoObjectDefEditConnections(szObjDefName As String)
  Dim propPage As frmUDIItemDefProps
  Dim objDef As UserDefinedItemDef
  Dim aProject As rtsProject
  Dim aPackage As rtsPackage
  Dim aClass As rtsClass
  
  On Error Resume Next
  If Not m_UDIDefMgr Is Nothing Then
    Set objDef = m_UDIDefMgr.GetUDIDefbyObjectName(szObjDefName)
    If Not objDef Is Nothing Then
      Set propPage = New frmUDIItemDefProps
      Set propPage.ShapeGe = ShapeGe
      Set propPage.CurUDIDef = objDef
      Set aProject = Projects(1)
      Set propPage.CurrentProject = aProject
      Set aPackage = aProject.Packages(objDef.packageName)
      Set propPage.CurrentPackage = aPackage
      Set aClass = aPackage.Classes(objDef.ClassName)
      Set propPage.CurrentClass = aClass
      propPage.Show vbModal, Me
    End If
  End If
End Sub

Private Function GetFolderAndShapeName(FolderName As String, ShapeName As String) As Boolean
  If Not tvwShapes.SelectedItem Is Nothing Then
    If InStr(1, tvwShapes.SelectedItem.Key, "S_") > 0 Then
      FolderName = tvwShapes.SelectedItem.Parent.Text
      ShapeName = tvwShapes.SelectedItem.Text
      GetFolderAndShapeName = True
    End If
  End If
End Function

Private Function GetNodeFolderAndShapeName(Node As MSComctlLib.Node, FolderName As String, ShapeName As String) As Boolean
  If InStr(1, Node.Key, "S_") > 0 Then
    FolderName = Node.Parent.Text
    ShapeName = Node.Text
    GetNodeFolderAndShapeName = True
  End If
End Function

Private Sub tvwShapes_NodeClick(ByVal Node As MSComctlLib.Node)
  On Error Resume Next
  Dim FolderName As String, ShapeName As String
  
  If m_bConstructing Then Exit Sub
  If GetNodeFolderAndShapeName(Node, FolderName, ShapeName) Then
    ShowShape FolderName, ShapeName
  End If
End Sub




