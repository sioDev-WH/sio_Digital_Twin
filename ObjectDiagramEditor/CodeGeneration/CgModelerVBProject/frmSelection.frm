VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Object = "{97BD7A05-77E0-11D2-8EAE-008048E27A77}#1.0#0"; "beegd10.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Object = "{3B7C8863-D78F-101B-B9B5-04021C009402}#1.2#0"; "RICHTX32.OCX"
Begin VB.Form frmLeafCg 
   Caption         =   "Class Wizard"
   ClientHeight    =   10785
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8145
   Icon            =   "frmSelection.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   10785
   ScaleWidth      =   8145
   StartUpPosition =   1  'CenterOwner
   Begin VB.Frame frmButtons3 
      BorderStyle     =   0  'None
      Height          =   1455
      Left            =   6510
      TabIndex        =   21
      Top             =   3900
      Width           =   1635
      Begin VB.CommandButton btnRemoveTransitionTrigger 
         Caption         =   "Remove Trigger"
         Height          =   375
         Left            =   90
         TabIndex        =   23
         Top             =   990
         Width           =   1455
      End
      Begin VB.CommandButton btnAddTransitionTrigger 
         Caption         =   "Add Trigger"
         Height          =   375
         Left            =   90
         TabIndex        =   22
         Top             =   480
         Width           =   1455
      End
      Begin RichTextLib.RichTextBox RichTextBox1 
         Height          =   375
         Left            =   60
         TabIndex        =   24
         Top             =   0
         Visible         =   0   'False
         Width           =   1455
         _ExtentX        =   2566
         _ExtentY        =   661
         _Version        =   393217
         TextRTF         =   $"frmSelection.frx":0442
      End
   End
   Begin VB.CommandButton btnCollapse 
      Caption         =   "x"
      Height          =   220
      Left            =   60
      TabIndex        =   20
      Top             =   120
      Width           =   220
   End
   Begin VB.Frame frmObjectType 
      Caption         =   "Class Type"
      Height          =   615
      Left            =   60
      TabIndex        =   0
      Top             =   3180
      Width           =   6375
      Begin VB.OptionButton optModel 
         Caption         =   "Connector"
         Height          =   255
         Index           =   3
         Left            =   2520
         TabIndex        =   7
         Top             =   240
         Width           =   1095
      End
      Begin VB.OptionButton optModel 
         Caption         =   "Non-Simulation"
         Height          =   255
         Index           =   5
         Left            =   4740
         TabIndex        =   6
         Top             =   240
         Width           =   1395
      End
      Begin VB.OptionButton optModel 
         Caption         =   "Structure"
         Height          =   255
         Index           =   4
         Left            =   3690
         TabIndex        =   5
         Top             =   240
         Width           =   1095
      End
      Begin VB.OptionButton optModel 
         Caption         =   "Abstract Model"
         Height          =   255
         Index           =   2
         Left            =   990
         TabIndex        =   4
         Top             =   240
         Width           =   1455
      End
      Begin VB.OptionButton optModel 
         Caption         =   "Model"
         Height          =   255
         Index           =   1
         Left            =   90
         TabIndex        =   3
         Top             =   240
         Value           =   -1  'True
         Width           =   855
      End
   End
   Begin MSComctlLib.TreeView tvItems 
      Height          =   2385
      Left            =   60
      TabIndex        =   2
      Top             =   3900
      Width           =   6345
      _ExtentX        =   11192
      _ExtentY        =   4207
      _Version        =   393217
      HideSelection   =   0   'False
      Style           =   7
      Appearance      =   1
   End
   Begin BeeGrid10.SGGrid gdItems 
      Height          =   4395
      Left            =   90
      TabIndex        =   1
      Top             =   6360
      Width           =   6345
      _cx             =   11192
      _cy             =   7752
      DataMode        =   1
      AutoFields      =   -1  'True
      Enabled         =   -1  'True
      GridBorderStyle =   1
      ScrollBars      =   3
      FlatScrollBars  =   0
      ScrollBarTrack  =   0   'False
      DataRowCount    =   2
      BeginProperty HeadingFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      DataColCount    =   2
      HeadingRowCount =   1
      HeadingColCount =   1
      TextAlignment   =   0
      WordWrap        =   0   'False
      Ellipsis        =   1
      HeadingBackColor=   -2147483633
      HeadingForeColor=   -2147483630
      HeadingTextAlignment=   0
      HeadingWordWrap =   0   'False
      HeadingEllipsis =   1
      GridLines       =   1
      HeadingGridLines=   2
      GridLinesColor  =   -2147483633
      HeadingGridLinesColor=   -2147483632
      EvenOddStyle    =   0
      ColorEven       =   -2147483628
      ColorOdd        =   -2147483624
      UserResizeAnimate=   1
      UserResizing    =   3
      RowHeightMin    =   0
      RowHeightMax    =   0
      ColWidthMin     =   0
      ColWidthMax     =   0
      UserDragging    =   2
      UserHiding      =   2
      CellPadding     =   15
      CellBkgStyle    =   1
      CellBackColor   =   -2147483643
      CellForeColor   =   -2147483640
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      FocusRect       =   1
      FocusRectColor  =   0
      FocusRectLineWidth=   1
      TabKeyBehavior  =   0
      EnterKeyBehavior=   0
      NavigationWrapMode=   1
      SkipReadOnly    =   0   'False
      DefaultColWidth =   1200
      DefaultRowHeight=   255
      CellsBorderColor=   0
      CellsBorderVisible=   -1  'True
      RowNumbering    =   0   'False
      EqualRowHeight  =   0   'False
      EqualColWidth   =   0   'False
      HScrollHeight   =   0
      VScrollWidth    =   0
      Format          =   "General"
      Appearance      =   2
      FitLastColumn   =   0   'False
      SelectionMode   =   0
      MultiSelect     =   0
      AllowAddNew     =   0   'False
      AllowDelete     =   0   'False
      AllowEdit       =   -1  'True
      ScrollBarTips   =   0
      CellTips        =   0
      CellTipsDelay   =   1000
      SpecialMode     =   0
      OutlineLines    =   1
      CacheAllRecords =   -1  'True
      ColumnClickSort =   0   'False
      PreviewPaneColumn=   ""
      PreviewPaneType =   0
      PreviewPanePosition=   2
      PreviewPaneSize =   2000
      GroupIndentation=   225
      InactiveSelection=   1
      AutoScroll      =   -1  'True
      AutoResize      =   1
      AutoResizeHeadings=   -1  'True
      OLEDragMode     =   0
      OLEDropMode     =   0
      Caption         =   ""
      ScrollTipColumn =   ""
      MaxRows         =   4194304
      MaxColumns      =   12
      NewRowPos       =   1
      CustomBkgDraw   =   0
      AutoGroup       =   -1  'True
      GroupByBoxVisible=   -1  'True
      GroupByBoxText  =   "Drag a column header here to group by that column"
      AlphaBlendEnabled=   0   'False
      DragAlphaLevel  =   206
      AutoSearch      =   0
      AutoSearchDelay =   2000
      StylesCollection=   $"frmSelection.frx":04CD
      ColumnsCollection=   $"frmSelection.frx":1F61
      ValueItems      =   $"frmSelection.frx":2D38
   End
   Begin VB.Frame frmButtons 
      BackColor       =   &H8000000A&
      BorderStyle     =   0  'None
      Caption         =   "Frame1"
      Height          =   3195
      Left            =   6510
      TabIndex        =   8
      Top             =   60
      Width           =   1635
      Begin VB.CheckBox chkVarAccessors 
         Caption         =   "Generate Variable Accessors"
         Height          =   615
         Left            =   240
         TabIndex        =   28
         Top             =   1980
         Value           =   1  'Checked
         Width           =   1335
      End
      Begin VB.CheckBox chkChildVarAccessors 
         Caption         =   "Generate Child Variable Accessors"
         Height          =   615
         Left            =   240
         TabIndex        =   27
         Top             =   2640
         Width           =   1335
      End
      Begin VB.CheckBox chViewDetails 
         Caption         =   "View Class Details"
         Height          =   495
         Left            =   240
         TabIndex        =   25
         Top             =   1440
         Value           =   1  'Checked
         Width           =   1275
      End
      Begin VB.CommandButton btnExit 
         Caption         =   "Exit"
         Height          =   375
         Left            =   90
         TabIndex        =   17
         Top             =   1020
         Width           =   1455
      End
      Begin VB.CommandButton btnCodeGeneration 
         Caption         =   "Extend Model"
         Height          =   375
         Left            =   90
         TabIndex        =   10
         Top             =   540
         Width           =   1455
      End
      Begin VB.CommandButton btnSave 
         Caption         =   "Save Attributes"
         Height          =   375
         Left            =   90
         TabIndex        =   9
         Top             =   60
         Width           =   1455
      End
      Begin MSComDlg.CommonDialog CommDlg 
         Left            =   1260
         Top             =   240
         _ExtentX        =   847
         _ExtentY        =   847
         _Version        =   393216
      End
      Begin MSComctlLib.ImageList ImageList1 
         Left            =   1140
         Top             =   720
         _ExtentX        =   1005
         _ExtentY        =   1005
         BackColor       =   -2147483643
         ImageWidth      =   16
         ImageHeight     =   16
         MaskColor       =   12632256
         _Version        =   393216
         BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
            NumListImages   =   1
            BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
               Picture         =   "frmSelection.frx":311D
               Key             =   ""
            EndProperty
         EndProperty
      End
   End
   Begin VB.Frame FrmButtons2 
      BorderStyle     =   0  'None
      Caption         =   """ """
      Height          =   4365
      Left            =   6510
      TabIndex        =   11
      Top             =   6360
      Width           =   1605
      Begin VB.CommandButton btnUnselectAll 
         Caption         =   "Unselect All"
         Height          =   375
         Left            =   90
         TabIndex        =   16
         Top             =   570
         Width           =   1455
      End
      Begin VB.CommandButton btnSelectAll 
         Caption         =   "Select All"
         Height          =   375
         Left            =   90
         TabIndex        =   15
         Top             =   60
         Width           =   1455
      End
      Begin VB.CommandButton btnRefreshGrid 
         Caption         =   "Refresh"
         Height          =   375
         Left            =   90
         TabIndex        =   14
         Top             =   2040
         Width           =   1455
      End
      Begin VB.CommandButton btnRemoveTriggerCondition 
         Caption         =   "Remove Condition"
         Height          =   375
         Left            =   90
         TabIndex        =   13
         Top             =   1560
         Width           =   1455
      End
      Begin VB.CommandButton btnAddTriggerCondition 
         Caption         =   "Add Condition"
         Height          =   375
         Left            =   90
         TabIndex        =   12
         Top             =   1080
         Width           =   1455
      End
   End
   Begin CGModeler.ucUMLTreeView ucUMLTreeView 
      Height          =   2655
      Left            =   180
      TabIndex        =   18
      Top             =   420
      Width           =   6195
      _ExtentX        =   11033
      _ExtentY        =   4683
   End
   Begin VB.Frame frmProjectSelection 
      Caption         =   "    Project Selection"
      Height          =   3000
      Left            =   60
      TabIndex        =   19
      Top             =   120
      Width           =   6375
   End
   Begin CGModeler.ctlSplitterEx ctlSplitterEx 
      Height          =   6795
      Left            =   60
      TabIndex        =   26
      Top             =   3900
      Width           =   6315
      _ExtentX        =   11139
      _ExtentY        =   11986
   End
End
Attribute VB_Name = "frmLeafCg"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim AttributesDataXML As String
Dim AttributesLayoutXML As String
Dim OperationsDataXML As String
Dim OperationsLayoutXML As String
Dim StateDataXML() As String
Dim StateLayoutXML() As String
Dim TriggerDataXML() As String
Dim TriggerLayoutXML() As String

Dim TransitionDataXML() As String
Dim TransitionLayoutXML() As String

Dim bDirty As Boolean

Dim SelectedProject As rtsProject
Dim SelectedPackage As rtsPackage
Dim SelectedClass As rtsClass

Dim SelectedItem As String
Dim SelectedAttributeIndex As Long
Dim SelectedOperationIndex As Long
Dim SelectedStateIndex As Long
Dim SelectedTransitionIndex As Long
Dim SelectedTriggerIndex As Long

Const iNodePrefix_Attributes = "0_"
Const iNodePrefix_Operations = "1_"
Const iNodePrefix_States = "2_"
Const iNodePrefix_Transitions = "3_"
Const iNodePrefix_State = "4_"
Const iNodePrefix_Transition = "5_"
Const iNodePrefix_Trigger = "6_"

Dim m_Projects As Object
Dim ClassCgAttributes As Collection
Dim classCgOperations As Collection
Dim m_bSaveLastLayout As Boolean

' The following three properties are used by the ucUMLTreeView control
' to set the currently selected project\package\class

Public Sub SetSelectedProject(selProject As rtsProject)
    Set SelectedProject = selProject
End Sub

Public Sub SetSelectedPackage(selPackage As rtsPackage)
    Set SelectedPackage = selPackage
End Sub

Public Sub SetSelectedClass(selClass As rtsClass)
    On Error GoTo Error_Handler
    Set SelectedClass = selClass

    If (SelectedProject Is Nothing) Or (SelectedPackage Is Nothing) Or (SelectedClass Is Nothing) Then
        gdItems.Columns.RemoveAll False
        gdItems.Rows.RemoveAll False
        tvItems.nodes.Clear
        Exit Sub
    End If
    
    GetClassInfo SelectedProject, SelectedPackage.Name, ucUMLTreeView.ClassName, SelectedClass

    AttributesDataXML = ""
    AttributesLayoutXML = ""
    OperationsDataXML = ""
    OperationsLayoutXML = ""
    ReDim StateLayoutXML(SelectedClass.States.count) As String
    ReDim StateDataXML(SelectedClass.States.count) As String
    ReDim TransitionLayoutXML(SelectedClass.Transitions.count) As String
    ReDim TransitionDataXML(SelectedClass.Transitions.count) As String

    m_bSaveLastLayout = False
    gdItems.Columns.RemoveAll False
    gdItems.Rows.RemoveAll False
    bDirty = False
   
    FillItems
    Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error retrieving class information. " & err.Description
End Sub

Private Sub btnAddTransitionTrigger_Click()
  Dim aTrans As CgTransition
  Dim aTrigger As CgTrigger
  Dim idxTrigger As Long
  
  On Error GoTo Error_Handler
  Set aTrans = SelectedClass.Transitions(SelectedTransitionIndex + 1)
  Set aTrigger = New CgTrigger
  idxTrigger = aTrans.Triggers.count
  aTrigger.Name = "Trigger(" & idxTrigger & ")"
  aTrans.Triggers.Add aTrigger, aTrigger.Name
  tvItems.nodes.Add tvItems.SelectedItem.Key, tvwChild, iNodePrefix_Trigger & SelectedTransitionIndex & "_" & idxTrigger, aTrigger.Name
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error adding trigger. " & err.Description
End Sub

Private Sub btnCollapse_Click()
    On Error Resume Next
    If btnCollapse.Caption = "x" Then
        frmProjectSelection.Height = 250
        ucUMLTreeView.Height = 10
        ucUMLTreeView.Visible = False
        btnCollapse.Caption = ">"
    Else
        frmProjectSelection.Height = 3000
        ucUMLTreeView.Height = 2655
        ucUMLTreeView.Visible = True
        btnCollapse.Caption = "x"
    End If
    btnRefreshGrid.SetFocus 'Take the focus off the btnCollapse, otherwise it looks wierd
    form_Resize
End Sub

Private Sub btnExit_Click()
    Unload Me
End Sub

Private Sub btnRefreshGrid_Click()
  GridRefresh
End Sub

Private Sub btnRemoveTransitionTrigger_Click()
  Dim aTrans As CgTransition
  Dim aTrigger As CgTrigger
  Dim idxTrigger As Long
  
  On Error GoTo Error_Handler
  Set aTrans = SelectedClass.Transitions(SelectedTransitionIndex + 1)
  aTrans.Triggers.Remove SelectedTriggerIndex + 1
  tvItems.nodes.Remove iNodePrefix_Trigger & SelectedTransitionIndex & "_" & SelectedTriggerIndex
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error removing trigger. " & err.Description
End Sub

Private Sub btnAddTriggerCondition_Click()
  Dim aTrans As CgTransition
  Dim aTrigger As CgTrigger
  Dim aCondition As CgTriggerCondition
  
  On Error GoTo Error_Handler
  Set aTrans = SelectedClass.Transitions(SelectedTransitionIndex + 1)
  Set aTrigger = aTrans.Triggers(SelectedTriggerIndex + 1)
  Set aCondition = New CgTriggerCondition
  aTrigger.Conditions.Add aCondition
  On Error Resume Next
  'gdItems.Rows.Current.Redraw
  gdItems.Rows.Add sgFormatCharSeparatedValue, aCondition.bNot & ",," & aCondition.Operation
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error adding trigger condition. " & err.Description
End Sub

Private Sub btnRemoveTriggerCondition_Click()
  Dim aTrans As CgTransition
  Dim aTrigger As CgTrigger
  Dim aCondition As CgTriggerCondition
  
  On Error GoTo Error_Handler
  Set aTrans = SelectedClass.Transitions(SelectedTransitionIndex + 1)
  Set aTrigger = aTrans.Triggers(SelectedTriggerIndex + 1)
  aTrigger.Conditions.Remove gdItems.Rows.Current.Position
  gdItems.Rows.Remove gdItems.Rows.Current.Key
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error removing trigger condition. " & err.Description
End Sub

Private Sub btnCodeGeneration_Click()
  
  Dim strClassID As String
  Dim strClassName As String
  Dim bVarAccessors As Boolean
  Dim bChildVarAccessors As Boolean
  
  On Error GoTo Error_Handler
  
  bVarAccessors = chkVarAccessors.Value
  bChildVarAccessors = chkChildVarAccessors.Value

  If Not SelectedClass Is Nothing Then
    'MousePointer = vbHourglass
    Set ClassCgAttributes = New Collection
    Set classCgOperations = New Collection
    GetLeafCgObjects SelectedClass, ClassCgAttributes, classCgOperations, bVarAccessors, bChildVarAccessors

    If Not ClassCgAttributes Is Nothing And Not classCgOperations Is Nothing Then

      If Not AddCgObjects(SelectedPackage.Name, SelectedClass.Name, SelectedClass, ClassCgAttributes, classCgOperations, chViewDetails.Value) Then
        MousePointer = vbDefault
        gMsgWnd.LogMessage "Leaf wizard code generation failed to complete."
      Else
        On Error Resume Next
        MousePointer = vbDefault
        gMsgWnd.LogMessage "Leaf wizard code generation complete."
      End If
    Else
      gMsgWnd.LogMessage "Leaf wizard code generation failed to complete."
    End If
    'MousePointer = vbDefault
  End If
  Exit Sub
    
Error_Handler:
  gMsgWnd.LogMessage "Leaf wizard code generation failed. " & err.Description
End Sub

Private Sub btnSave_Click()
  On Error Resume Next
  SaveGridFormatAndData ' ensure all changes are saved from the grid
  WriteData
  SelectedClass.Save
End Sub

Private Sub btnSelectAll_Click()
  Dim i As Long
  Dim j As Long
  
  Dim aCol As SGColumn
  Dim aRow As SGRow
  
  On Error Resume Next
  For i = 0 To gdItems.Columns.count - 1
    Set aCol = gdItems.Columns(i + 1)
    If aCol.Control.Type = sgCellCheckBox Then
      For j = 0 To gdItems.Rows.count - 2
        gdItems.Array(j, i) = True
      Next
      Exit For
    End If
  Next i
  gdItems.Redraw sgRedrawAll
End Sub

Private Sub btnUnselectAll_Click()
  Dim i As Long
  Dim j As Long
  
  Dim aCol As SGColumn
  Dim aRow As SGRow
  
  On Error Resume Next
  For i = 0 To gdItems.Columns.count - 1
    Set aCol = gdItems.Columns(i + 1)
    If aCol.Control.Type = sgCellCheckBox Then
      For j = 0 To gdItems.Rows.count - 2
        gdItems.Array(j, i) = False
      Next
      Exit For
    End If
  Next i
  gdItems.Redraw sgRedrawAll
End Sub


Private Sub Form_Load()
  Dim activeProjectName As String
  Dim i As Long
  On Error GoTo Error_Handler
  If crtf Is Nothing Then Set crtf = RichTextBox1
  
  ctlSplitterEx.AttachObjects tvItems, gdItems, True
  ctlSplitterEx.TileMode = TILE_HORIZONTALLY
  
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
    MsgBox "UML Project has not been loaded."
    Exit Sub
  End If
  
  'Populate the UML project selection control
  If Projects.count > 0 And Not ucUMLTreeView Is Nothing Then
    ucUMLTreeView.PopulateProjectsList Projects
  End If
    
#If using_ilogix Then
  
  If Not doc Is Nothing Then
    If Not doc.activeProject Is Nothing Then
      activeProjectName = doc.activeProject.Name
    End If
  End If
  
#End If

  btnAddTransitionTrigger.Enabled = False
  btnRemoveTransitionTrigger.Enabled = False
  btnAddTriggerCondition.Enabled = False
  btnRemoveTriggerCondition.Enabled = False
  gdItems.Columns.RemoveAll False
  gdItems.Rows.RemoveAll False
  
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Failed to initialize Leaf Wizard. " & err.Description
    Unload Me
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, y As Single)
    Screen.MousePointer = vbArrow
End Sub

Private Sub form_Resize()
    On Error Resume Next
    frmObjectType.Top = frmProjectSelection.Height + 200
    tvItems.Top = frmObjectType.Top + frmObjectType.Height + 105
    frmButtons.Left = Abs(Me.Width - 1800)
    FrmButtons2.Left = frmButtons.Left
    frmButtons3.Left = frmButtons.Left
    tvItems.Width = Abs(Me.Width - 2000)
    gdItems.Width = tvItems.Width
    ctlSplitterEx.Width = tvItems.Width
    frmObjectType.Width = tvItems.Width
    frmProjectSelection.Width = tvItems.Width
    ucUMLTreeView.Width = Abs(frmProjectSelection.Width - 180)
    tvItems.Height = Abs(Me.Height - 8500)
    gdItems.Height = Abs(Me.Height - (tvItems.Top + tvItems.Height + 600))
    ctlSplitterEx.Top = tvItems.Top
    ctlSplitterEx.Height = tvItems.Height + gdItems.Height + 15
    gdItems.Top = Abs(tvItems.Top + tvItems.Height + 100)
    FrmButtons2.Top = gdItems.Top
    frmButtons3.Top = Abs(tvItems.Top + (tvItems.Height - frmButtons3.Height))
End Sub

Private Sub Form_Unload(Cancel As Integer)

#If using_ilogix And stand_alone_app Then
  Dim answer As VbMsgBoxResult
  
  If Not doc Is Nothing Then
    If Not doc.activeProject Is Nothing Then
      
      answer = MsgBox("Save project changes?", vbYesNo, "Save")
      If answer = vbYes Then
        doc.activeProject.Save
      End If
      doc.activeProject.Close
      Set doc.activeProject = Nothing
    End If
    doc.quit
  End If
#End If

End Sub

Private Sub gdItems_AfterUpdate()
  bDirty = True
End Sub

Private Sub gdItems_ButtonClick(ByVal RowKey As Long, ByVal ColIndex As Long, Cancel As Boolean)
    Dim m_frmConfig As frmArrayAndMatrixConfiguration
    Dim iType, iRowPos As Integer
        
    On Error Resume Next
    If ColIndex = 5 Then
        iRowPos = gdItems.Rows(RowKey).Position - 1
        iType = gdItems.Array(iRowPos, ColIndex - 2)
        Select Case iType
            Case idxAttr_Array
                Set m_frmConfig = New frmArrayAndMatrixConfiguration
                Set m_frmConfig.GridArray = gdItems
                m_frmConfig.InitArray iRowPos
                m_frmConfig.Show
                m_frmConfig.Refresh
            Case idxAttr_Matrix
                Set m_frmConfig = New frmArrayAndMatrixConfiguration
                Set m_frmConfig.GridArray = gdItems
                m_frmConfig.InitMatrix iRowPos
                m_frmConfig.Show
                m_frmConfig.Refresh
        End Select
    End If
End Sub

Sub FillItems()
  Dim nodX As Node
  Dim nodRoot As Node
  Dim aCgItem As CgItem
  Dim aCgState As CgState
  Dim aCgTrans As CgTransition
  Dim szXML As String
  Dim aCgTrigger As CgTrigger
  Dim szKey As String
  Dim idxTransition As Long
  Dim idxTrigger As Long
  Dim ModelType As Long
  
  On Error GoTo Error_Handler
  tvItems.nodes.Clear
  tvItems.Style = tvwTreelinesPlusMinusText
  Set nodRoot = tvItems.nodes.Add(, , "Root", SelectedClass.Name)
  Set nodX = tvItems.nodes.Add("Root", tvwChild, iNodePrefix_Attributes, "Attributes")
  Set nodX = tvItems.nodes.Add("Root", tvwChild, iNodePrefix_Operations, "Operations")
  
  If SelectedClass.ModelType = 0 Then SelectedClass.ModelType = 1
  optModel(SelectedClass.ModelType) = True
  
  ReDim StateDataXML(SelectedClass.States.count) As String
  ReDim StateLayoutXML(SelectedClass.States.count) As String
  
  ReDim TransitionDataXML(SelectedClass.Transitions.count) As String
  ReDim TransitionLayoutXML(SelectedClass.Transitions.count) As String
  
  ReDim TriggerDataXML(SelectedClass.Transitions.count, 10) As String
  ReDim TriggerLayoutXML(SelectedClass.Transitions.count, 10) As String
  
  Set nodX = tvItems.nodes.Add("Root", tvwChild, iNodePrefix_States, "States")
  For Each aCgState In SelectedClass.States
    Set nodX = tvItems.nodes.Add(iNodePrefix_States, tvwChild, iNodePrefix_State & aCgState.Name, aCgState.Name)
  Next
  
  
  Set nodX = tvItems.nodes.Add("Root", tvwChild, iNodePrefix_Transitions, "Transitions")
  idxTransition = 0
  
  For Each aCgTrans In SelectedClass.Transitions
    szKey = iNodePrefix_Transition & aCgTrans.Name
    Set nodX = tvItems.nodes.Add(iNodePrefix_Transitions, tvwChild, szKey, aCgTrans.Name)
    idxTrigger = 0
    For Each aCgTrigger In aCgTrans.Triggers
      If (aCgTrigger.Name = "") Then aCgTrigger.Name = "Trigger(" & idxTrigger & ")"
      Set nodX = tvItems.nodes.Add(szKey, tvwChild, iNodePrefix_Trigger & idxTransition & "_" & idxTrigger, aCgTrigger.Name)
      idxTrigger = idxTrigger + 1
    Next
    idxTransition = idxTransition + 1
  Next
    
  nodRoot.Expanded = True
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Failed to populate Leaf Wizard information. " & err.Description
End Sub

Private Sub tvItems_AfterLabelEdit(Cancel As Integer, NewString As String)
  Dim aCgTrans As CgTransition
  Dim aCgTrigger As CgTrigger
  Dim OldName As String
  
  On Error Resume Next
  ' only allowing renaming of triggers (not exported in code generation, just for user's sanity)
  If SelectedItem = iNodePrefix_Trigger Then
    Set aCgTrans = SelectedClass.Transitions(SelectedTransitionIndex + 1)
    Set aCgTrigger = aCgTrans.Triggers(SelectedTriggerIndex + 1)
    OldName = aCgTrigger.Name
    aCgTrigger.Name = NewString
    aCgTrans.Triggers.Remove OldName
    If err = 0 Then aCgTrans.Triggers.Add aCgTrigger, NewString
  End If
End Sub

Private Sub tvItems_BeforeLabelEdit(Cancel As Integer)
  Select Case SelectedItem
  
    Case iNodePrefix_Attributes
      Cancel = True
      
    Case iNodePrefix_Operations
      Cancel = True
    
    Case iNodePrefix_State
      Cancel = True
    
    Case iNodePrefix_Transition
      Cancel = True
    
    Case iNodePrefix_Trigger
      Cancel = False ' allow edits
      
  End Select
End Sub

Private Sub SaveGridFormatAndData()
  On Error GoTo Error_Handler
  If bDirty Then
    ' store information for previously selected item
    Select Case SelectedItem
    
      Case iNodePrefix_Attributes
        AttributesDataXML = gdItems.ExportDataString(sgFormatXML, sgExportDefault)
        
      Case iNodePrefix_Operations
        OperationsDataXML = gdItems.ExportDataString(sgFormatXML, sgExportDefault)
      
      Case iNodePrefix_Transition
        TransitionDataXML(SelectedTransitionIndex) = gdItems.ExportDataString(sgFormatXML, sgExportDefault)
        
      Case iNodePrefix_State
        StateDataXML(SelectedStateIndex) = gdItems.ExportDataString(sgFormatXML, sgExportDefault)
      
      Case iNodePrefix_Trigger
        TriggerDataXML(SelectedTransitionIndex, SelectedTriggerIndex) = gdItems.ExportDataString(sgFormatXML, sgExportDefault)
        
    End Select
    bDirty = False
  End If

  If m_bSaveLastLayout Then
    ' store format
    Select Case SelectedItem
    
      Case iNodePrefix_Attributes
        AttributesLayoutXML = gdItems.GetLayoutString(sgLayoutXML)
        
      Case iNodePrefix_Operations
        OperationsLayoutXML = gdItems.GetLayoutString(sgLayoutXML)
      
      Case iNodePrefix_Transition
        TransitionLayoutXML(SelectedTransitionIndex) = gdItems.GetLayoutString(sgLayoutXML)
        
      Case iNodePrefix_State
        StateLayoutXML(SelectedStateIndex) = gdItems.GetLayoutString(sgLayoutXML)
      
      Case iNodePrefix_Trigger
        TriggerLayoutXML(SelectedTransitionIndex, SelectedTriggerIndex) = gdItems.GetLayoutString(sgLayoutXML)
        
    End Select
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error saving Leaf Wizard data. " & err.Description
End Sub

Private Sub tvItems_NodeClick(ByVal Node As MSComctlLib.Node)
  On Error Resume Next
  SaveGridFormatAndData ' save grid data if grid is dirty
  SelectedItem = Left(Node.Key, 2)
  Select Case SelectedItem
  
    Case iNodePrefix_Attributes
      btnAddTransitionTrigger.Enabled = False
      btnRemoveTransitionTrigger.Enabled = False
      btnAddTriggerCondition.Enabled = False
      btnRemoveTriggerCondition.Enabled = False

      InitAttributesGrid True 'Doesn't redraw buttons properly if False
      FillAttributesGrid True
    
    Case iNodePrefix_Operations
      btnAddTransitionTrigger.Enabled = False
      btnRemoveTransitionTrigger.Enabled = False
      btnAddTriggerCondition.Enabled = False
      btnRemoveTriggerCondition.Enabled = False
      InitOperationsGrid False
      FillOperationsGrid False
  
    Case iNodePrefix_States
      btnAddTransitionTrigger.Enabled = False
      btnRemoveTransitionTrigger.Enabled = False
      btnAddTriggerCondition.Enabled = False
      btnRemoveTriggerCondition.Enabled = False
      
    Case iNodePrefix_State
      btnAddTransitionTrigger.Enabled = False
      btnRemoveTransitionTrigger.Enabled = False
      btnAddTriggerCondition.Enabled = False
      btnRemoveTriggerCondition.Enabled = False
      SelectedStateIndex = GetNodeIndex(Node)
      InitStateGrid False
      FillStateGrid False, SelectedStateIndex
      
    Case iNodePrefix_Transitions
      btnAddTransitionTrigger.Enabled = False
      btnRemoveTransitionTrigger.Enabled = False
      btnAddTriggerCondition.Enabled = False
      btnRemoveTriggerCondition.Enabled = False
      
    Case iNodePrefix_Transition
      btnAddTransitionTrigger.Enabled = True
      btnRemoveTransitionTrigger.Enabled = False
      btnAddTriggerCondition.Enabled = False
      btnRemoveTriggerCondition.Enabled = False
      SelectedTransitionIndex = GetNodeIndex(Node)
      InitTransitionGrid False
      FillTransitionGrid False, SelectedTransitionIndex
      
    Case iNodePrefix_Trigger
      btnAddTransitionTrigger.Enabled = False
      btnRemoveTransitionTrigger.Enabled = True
      btnAddTriggerCondition.Enabled = True
      btnRemoveTriggerCondition.Enabled = True
      SelectedTriggerIndex = GetNodeIndex(Node)
      SelectedTransitionIndex = GetNodeIndex(Node.Parent)
      InitTriggerGrid False
      FillTriggerGrid False, SelectedTransitionIndex, SelectedTriggerIndex
      
  End Select
End Sub

Private Sub GridRefresh()
  On Error Resume Next
  Select Case SelectedItem
  
    Case iNodePrefix_Attributes
      InitAttributesGrid True
      FillAttributesGrid True
    
    Case iNodePrefix_Operations
      InitOperationsGrid True
      FillOperationsGrid True
  
    Case iNodePrefix_States
      
    Case iNodePrefix_State
      InitStateGrid True
      FillStateGrid True, SelectedStateIndex
      
    Case iNodePrefix_Transitions
      
    Case iNodePrefix_Transition
      InitTransitionGrid True
      FillTransitionGrid True, SelectedTransitionIndex
      
    Case iNodePrefix_Trigger
      InitTriggerGrid True
      FillTriggerGrid True, SelectedTransitionIndex, SelectedTriggerIndex
      
  End Select
End Sub

Function GetNodeIndex(aNode As Node) As Long
  Dim aParentNode As Node
  Dim aTestNode As Node
  Dim count As Long
  Dim iRet As Long
  
  Set aParentNode = aNode.Parent
  count = aParentNode.Children
  
  Set aTestNode = aParentNode.Child
  For iRet = 0 To count - 1
    If aTestNode.Key = aNode.Key Then Exit For
    Set aTestNode = aTestNode.Next
  Next iRet
  GetNodeIndex = iRet
End Function

Sub InitAttributesGrid(bRefresh As Boolean)
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim aCgItem As CgItem

  On Error GoTo Error_Handler
  If Len(AttributesLayoutXML) > 0 And Not bRefresh Then
    gdItems.LoadLayoutString AttributesLayoutXML, sgLayoutXML
  Else
    gdItems.UserDragging = sgNoRowColDrag
    gdItems.Columns.RemoveAll
    
    Set aCol = gdItems.Columns.Add("Name")
    aCol.Width = 2500
    aCol.ReadOnly = True
    
    Set aCol = gdItems.Columns.Add("Sim")
    aCol.Width = 400
    'aCol.Heading = "Sim"
    Set ctrl = aCol.Control
    ctrl.Type = sgCellCheckBox
    
    
    Set aCol = gdItems.Columns.Add("Type")
    aCol.Width = 1100
    Set ctrl = aCol.Control
    ctrl.Type = sgCellDropList
    Set vis = aCol.ValueItems
    vis.Add idxAttr_Undefined, szAttr_Undefined
    vis.Add idxAttr_Variable, szAttr_Variable
    vis.Add idxAttr_Parameter, szAttr_Parameter
    vis.Add idxAttr_Connector, szAttr_Connector
    vis.Add idxAttr_Model, szAttr_Model
    vis.Add idxAttr_Struct, szAttr_Struct
    vis.Add idxAttr_Broadcaster, szAttr_Broadcaster
    vis.Add idxAttr_Listener, szAttr_Listener
    vis.Add idxAttr_DataCollector, szAttr_DataCollector
    vis.Add idxAttr_Input, szAttr_Input
    vis.Add idxAttr_Output, szAttr_Output
    aCol.DefaultValue = idxAttr_Variable
    ctrl.PopupRows = 11
    ctrl.ShowButton = sgShowButtonFocused
    
    Set vis = Nothing
    Set aCol = gdItems.Columns.Add("Advanced")
    aCol.Style.Borders = sgCellBorderTop + sgCellBorderBottom
    aCol.Width = 1000
    Set ctrl = aCol.Control
    ctrl.Type = sgCellDropDown
    Set vis = aCol.ValueItems
    vis.Add idxAttr_Undefined, szAttr_Undefined
    vis.Add idxAttr_Scalar, szAttr_Scalar
    vis.Add idxAttr_Array, szAttr_Array
    vis.Add idxAttr_Matrix, szAttr_Matrix
    vis.Add idxAttr_valarray, szAttr_valarray
    aCol.DefaultValue = idxAttr_Scalar
    ctrl.PopupRows = 5
    
    'Add column for configuring arrays and enums
    Set aCol = gdItems.Columns.Add(" ")
    aCol.Width = 260
    aCol.Style.Borders = sgCellBorderTop + sgCellBorderBottom
    aCol.AllowSizing = False
    Set ctrl = aCol.Control
    ctrl.ShowButton = sgShowButtonAlways
    ctrl.ButtonAlignment = sgButtonLeft
        
    Set aCol = gdItems.Columns.Add("Cg")
    aCol.Hidden = True
#If APP_DEBUG Then
    aCol.Hidden = False
#End If
    Set ctrl = aCol.Control
    ctrl.Type = sgCellDropDown
    Set vis = aCol.ValueItems
    vis.Add 0, "False"
    vis.Add 1, "True"
    aCol.DefaultValue = 0
    ctrl.PopupRows = 2
    
    gdItems.Rows.RemoveAll False
    AttributesLayoutXML = gdItems.GetLayoutString(sgLayoutXML)
    m_bSaveLastLayout = True
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error initializing Attributes grid. " & err.Description
End Sub


Sub InitOperationsGrid(bRefresh As Boolean)
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim aCgItem As CgItem

  On Error GoTo Error_Handler
  If Len(OperationsLayoutXML) > 0 And Not bRefresh Then
    gdItems.LoadLayoutString OperationsLayoutXML, sgLayoutXML
  Else
    gdItems.Columns.RemoveAll
    
    Set aCol = gdItems.Columns.Add("Name")
    aCol.Width = 3000
    aCol.ReadOnly = True

    Set aCol = gdItems.Columns.Add("Sim")
    aCol.Width = 400
    Set ctrl = aCol.Control
    ctrl.Type = sgCellCheckBox
    
    Set aCol = gdItems.Columns.Add("Type")
    aCol.Width = 1500
    Set ctrl = aCol.Control
    ctrl.Type = sgCellDropList
    Set vis = aCol.ValueItems
    vis.Add idxOper_Continuous, szOper_Continuous
    vis.Add idxOper_Discontinuous, szOper_Discontinuous
    vis.Add idxOper_Reset, szOper_Reset
    vis.Add idxOper_Get, szOper_Get
    vis.Add idxOper_Set, szOper_Set
    aCol.DefaultValue = idxOper_Continuous
    ctrl.PopupRows = 5
    
    Set aCol = gdItems.Columns.Add("SubType")
    aCol.Width = 1500
    Set ctrl = aCol.Control
    ctrl.Type = sgCellDropList
    Set vis = aCol.ValueItems
    vis.Add idxOper_Undefined, szOper_Undefined
    vis.Add idxOper_Scalar, szOper_Scalar
    vis.Add idxOper_Array, szOper_Array
    vis.Add idxOper_valarray, szOper_valarray
    vis.Add idxOper_Distributed, szOper_Distributed
    aCol.DefaultValue = idxOper_Scalar
    ctrl.PopupRows = 4
    
    Set aCol = gdItems.Columns.Add("Diff")
    aCol.Width = 1400
    Set ctrl = aCol.Control
    ctrl.Type = sgCellDropList
    Set vis = aCol.ValueItems
    vis.Add idxOperDiff_Undefined, szOperDiff_Undefined
    vis.Add idxOperDiff_Automatic, szOperDiff_Automatic
    vis.Add idxOperDiff_Numeric, szOperDiff_Numeric
    aCol.DefaultValue = idxOperDiff_Automatic
    ctrl.PopupRows = 3
    
    Set aCol = gdItems.Columns.Add("Cg")
    aCol.Width = 1000
    aCol.Hidden = True
#If APP_DEBUG Then
    aCol.Hidden = False
#End If
    Set ctrl = aCol.Control
    ctrl.Type = sgCellDropList
    Set vis = aCol.ValueItems
    vis.Add 0, "False"
    vis.Add 1, "True"
    aCol.DefaultValue = 0
    ctrl.PopupRows = 2
      
    gdItems.Rows.RemoveAll False
    OperationsLayoutXML = gdItems.GetLayoutString(sgLayoutXML)
    m_bSaveLastLayout = True
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error initializing Operations grid. " & err.Description
End Sub

Sub InitStateGrid(bRefresh As Boolean)
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim aCgItem As CgItem

  On Error GoTo Error_Handler
  If Len(StateLayoutXML(SelectedStateIndex)) > 0 And Not bRefresh Then
    gdItems.LoadLayoutString StateLayoutXML(SelectedStateIndex), sgLayoutXML
  Else
    gdItems.Columns.RemoveAll
    
    Set aCol = gdItems.Columns.Add("Equation name")
    aCol.Width = 3000
    aCol.ReadOnly = True

    Set aCol = gdItems.Columns.Add("Active")
    aCol.Width = 800
    Set ctrl = aCol.Control
    ctrl.Type = sgCellCheckBox
    
    gdItems.Rows.RemoveAll False
    StateLayoutXML(SelectedStateIndex) = gdItems.GetLayoutString(sgLayoutXML)
    m_bSaveLastLayout = True
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error initializing State grid. " & err.Description
End Sub

Sub InitTransitionGrid(bRefresh As Boolean)
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim aCgItem As CgItem

  On Error GoTo Error_Handler
  If Len(TransitionLayoutXML(SelectedTransitionIndex)) > 0 And Not bRefresh Then
    gdItems.LoadLayoutString TransitionLayoutXML(SelectedTransitionIndex), sgLayoutXML
  Else
    gdItems.Columns.RemoveAll
    
    Set aCol = gdItems.Columns.Add("Equation name")
    aCol.Width = 3000
    aCol.ReadOnly = True

    Set aCol = gdItems.Columns.Add("Active")
    aCol.Width = 800
    Set ctrl = aCol.Control
    ctrl.Type = sgCellCheckBox
    
    gdItems.Rows.RemoveAll False
    TransitionLayoutXML(SelectedTransitionIndex) = gdItems.GetLayoutString(sgLayoutXML)
    m_bSaveLastLayout = True
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error initializing Transition grid. " & err.Description
End Sub

Sub InitTriggerGrid(bRefresh As Boolean)
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim Operations() As String
  Dim count As Long
  Dim i As Long
  
  On Error GoTo Error_Handler
  If Len(TriggerLayoutXML(SelectedTransitionIndex, SelectedTriggerIndex)) > 0 And Not bRefresh Then
    gdItems.LoadLayoutString TriggerLayoutXML(SelectedTransitionIndex, SelectedTriggerIndex), sgLayoutXML
  Else
    gdItems.Columns.RemoveAll
    
    Set aCol = gdItems.Columns.Add("Not")
    aCol.Width = 800
    Set ctrl = aCol.Control
    ctrl.Type = sgCellCheckBox
    aCol.DefaultValue = "0"
    
    Set aCol = gdItems.Columns.Add("Equation name")
    aCol.Width = 3000
    Set ctrl = aCol.Control
    ctrl.Type = sgCellDropList
    Set vis = aCol.ValueItems
    GetTypedOperations idxOper_Discontinuous, Operations, count
    For i = 0 To count - 1
      vis.Add Operations(i), Operations(i)
    Next i
    ctrl.PopupRows = count
    
    Set aCol = gdItems.Columns.Add("Operation")
    aCol.Width = 1500
    Set ctrl = aCol.Control
    ctrl.Type = sgCellDropList
    Set vis = aCol.ValueItems
    vis.Add "And", "And"
    vis.Add "Or", "Or"
    aCol.DefaultValue = "And"
    ctrl.PopupRows = 2
    
    gdItems.Rows.RemoveAll False
    TriggerLayoutXML(SelectedTransitionIndex, SelectedTriggerIndex) = gdItems.GetLayoutString(sgLayoutXML)
    m_bSaveLastLayout = True
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error initializing Trigger grid. " & err.Description
End Sub

Sub GetTypedOperations(TypeId As Long, Operations() As String, count As Long)
  Dim aDoc As DOMDocument
  Dim i As Long
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aOperation As CgOperation
  
  On Error GoTo Error_Handler
  If Len(OperationsDataXML) > 0 Then
    Set aDoc = New DOMDocument
    OperationsDataXML = Replace(OperationsDataXML, "encoding=" & Chr(34) & "Windows-1252" & Chr(34), "")
    If aDoc.loadXML(OperationsDataXML) Then
      Set aNodeList = aDoc.getElementsByTagName("row")
      ReDim Operations(aNodeList.length) As String
      For i = 0 To aNodeList.length - 1
        Set aItem = aNodeList.Item(i)
        If (aItem.Attributes(1).Text = "True" Or aItem.Attributes(1).Text = "1" Or aItem.Attributes(1).Text = "-1") And aItem.Attributes(2).Text = TypeId Then
          Operations(count) = aItem.Attributes(0).Text
          count = count + 1
        End If
      Next i
      Exit Sub
    End If
  Else
  
    ReDim Operations(SelectedClass.Operations.count) As String
    For Each aOperation In SelectedClass.Operations
      If aOperation.bSim And aOperation.sType = TypeId Then
        Operations(count) = aOperation.Name
        count = count + 1
      End If
    Next
  
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error retrieving operation. " & err.Description
End Sub

Sub FillAttributesGrid(bRefresh As Boolean)
  Dim aAttr As CgAttribute
  Dim aAssoc As CgAssociation
  Dim i As Integer
  Dim strName As String
  Dim idxNameCol, idxDimCol As Long
  
  On Error GoTo Error_Handler
  idxNameCol = 0
  idxDimCol = 4
  If SelectedClass Is Nothing Then Exit Sub
  
  If Len(AttributesDataXML) > 0 And Not bRefresh Then
    gdItems.ImportDataString AttributesDataXML, sgFormatXML
  Else
    For Each aAttr In SelectedClass.Attributes
      gdItems.Rows.Add sgFormatCharSeparatedValue, _
        aAttr.Name & "," & aAttr.bSim & "," & aAttr.sType & "," & aAttr.sSubType & "," & CStr(aAttr.dim1 & DASH_DELIMETER & aAttr.dim2) & "," & aAttr.OnCg
    Next
    bDirty = True
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error populating Attributes grid. " & err.Description
End Sub

Sub FillOperationsGrid(bRefresh As Boolean)
  Dim aOperation As CgOperation
  
  On Error GoTo Error_Handler
  If SelectedClass Is Nothing Then Exit Sub
  
  If Len(OperationsDataXML) > 0 And Not bRefresh Then
    gdItems.ImportDataString OperationsDataXML, sgFormatXML
  Else
    For Each aOperation In SelectedClass.Operations
      gdItems.Rows.Add sgFormatCharSeparatedValue, _
        aOperation.Name & "," & _
        IIf(aOperation.bSim, "-1", "0") & "," & _
        CStr(aOperation.sType) & "," & _
        CStr(aOperation.sSubType) & "," & _
        CStr(aOperation.sDiffType) & "," & _
        CStr(aOperation.OnCg)
    Next
    bDirty = True
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error populating Operations grid. " & err.Description
End Sub

Sub FillStateGrid(bRefresh As Boolean, idxState As Long)
  Dim aState As CgState
  Dim i As Long
  Dim Operations() As String
  Dim count As Long
  Dim aOperation As CgItem
  
  On Error GoTo Error_Handler
  If SelectedClass Is Nothing Then Exit Sub
  
  Set aState = SelectedClass.States(idxState + 1)
  If Len(StateDataXML(idxState)) > 0 And Not bRefresh Then
    gdItems.ImportDataString StateDataXML(idxState), sgFormatXML
    Exit Sub
  End If
  
  GetTypedOperations idxOper_Continuous, Operations, count
  For i = 0 To count - 1
    On Error Resume Next
    Set aOperation = aState.Eqns(Operations(i))
    If err = 0 Then
      gdItems.Rows.Add sgFormatCharSeparatedValue, Operations(i) & ",1"
    Else
      gdItems.Rows.Add sgFormatCharSeparatedValue, Operations(i) & ",0"
    End If
  Next i
  
  bDirty = True
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error populating State grid. " & err.Description
End Sub

Sub FillTransitionGrid(bRefresh As Boolean, idxTransition As Long)
  Dim aTransition As CgTransition
  Dim i As Long
  Dim Operations() As String
  Dim count As Long
  Dim aOperation As CgItem
  
  On Error GoTo Error_Handler
  If SelectedClass Is Nothing Then Exit Sub
  
  Set aTransition = SelectedClass.Transitions(idxTransition + 1)
  If Len(TransitionDataXML(idxTransition)) > 0 And Not bRefresh Then
    gdItems.ImportDataString TransitionDataXML(idxTransition), sgFormatXML
    Exit Sub
  End If
  
  GetTypedOperations idxOper_Reset, Operations, count
  For i = 0 To count - 1
    On Error Resume Next
    Set aOperation = aTransition.ResetEqns(Operations(i))
    If err = 0 Then
      gdItems.Rows.Add sgFormatCharSeparatedValue, Operations(i) & ",1"
    Else
      gdItems.Rows.Add sgFormatCharSeparatedValue, Operations(i) & ",0"
    End If
  Next i
  bDirty = True
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error populating Transitions grid. " & err.Description
End Sub


Sub FillTriggerGrid(bRefresh As Boolean, idxTransition As Long, idxTrigger As Long)
  Dim aTrans As CgTransition
  Dim aTrigger As CgTrigger
  Dim aDoc As DOMDocument
  Dim i As Long
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aCondition As CgTriggerCondition
  
  On Error GoTo Error_Handler
  If SelectedClass Is Nothing Then Exit Sub
  
  If Len(TriggerDataXML(idxTransition, idxTrigger)) > 0 And Not bRefresh Then
    gdItems.ImportDataString TriggerDataXML(idxTransition, idxTrigger), sgFormatXML
    Exit Sub
  End If
  
  Set aTrans = SelectedClass.Transitions(idxTransition + 1)
  Set aTrigger = aTrans.Triggers(idxTrigger + 1)
  For Each aCondition In aTrigger.Conditions
    If aCondition.Eqn Is Nothing Then
      gdItems.Rows.Add sgFormatCharSeparatedValue, aCondition.bNot & ",," & aCondition.Operation
    Else
      gdItems.Rows.Add sgFormatCharSeparatedValue, aCondition.bNot & "," & aCondition.Eqn.Name & "," & aCondition.Operation
    End If
  Next
  bDirty = True
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error populating Triggers grid. " & err.Description
End Sub

Public Sub WriteData()
  Dim ModelType As Long
  Dim i As Long
  
  ' get the model type from the radio buttons
  For i = optModel.LBound To optModel.UBound
    If optModel(i).Value Then
      ModelType = i
      Exit For
    End If
  Next i
  SelectedClass.ModelType = ModelType

  ' write the attribute, operation, state, and transition data from grid
  WriteAttributeData
  WriteOperationData
  For i = 0 To SelectedClass.States.count - 1
    WriteStateData i
  Next i
  
  For i = 0 To SelectedClass.Transitions.count - 1
    WriteTransitionData i
  Next i
End Sub

Public Sub WriteAttributeData()
  Dim aDoc As DOMDocument
  Dim i As Long
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aCgItem As CgItem
  Dim sName As String
  Dim bSim As Boolean
  Dim sType As String
  Dim sSubType As String
  Dim dims As String
  Dim dim1, dim2 As Integer
  Dim sOnCg As String
  Dim dimArray
  Dim aAttr As CgAttribute
  Dim aAssoc As CgAssociation
  
  On Error GoTo Error_Handler
  If Len(AttributesDataXML) > 0 Then
    Set aDoc = New DOMDocument
    AttributesDataXML = Replace(AttributesDataXML, "encoding=" & Chr(34) & "Windows-1252" & Chr(34), "")
    If aDoc.loadXML(AttributesDataXML) Then
      Set aNodeList = aDoc.getElementsByTagName("row")
      For i = 0 To aNodeList.length - 1
        Set aItem = aNodeList.Item(i)
        ' Name, Sim, Type, SubType
        sName = aItem.Attributes(0).Text
        bSim = aItem.Attributes(1).Text
        sType = aItem.Attributes(2).Text
        sSubType = aItem.Attributes(3).Text
        dims = aItem.Attributes(4).Text
        dimArray = Split(dims, DASH_DELIMETER)
        dim1 = dimArray(0)
        
        If UBound(dimArray) >= 1 Then
          dim2 = dimArray(1)
        End If
        sOnCg = aItem.Attributes(5).Text
        
        For Each aAttr In SelectedClass.Attributes
          If aAttr.Name = sName Then
            aAttr.bSim = bSim
            aAttr.sType = sType
            aAttr.sSubType = sSubType
            aAttr.dim1 = dim1
            aAttr.dim2 = dim2
            aAttr.OnCg = CBool(sOnCg)
            Exit For
          End If
        Next
        
        For Each aAssoc In SelectedClass.Associations
          If aAssoc.Name = sName Then
            aAssoc.bSim = bSim
            aAssoc.sType = sType
            aAssoc.sSubType = sSubType
            aAssoc.dim1 = dim1
            aAssoc.dim2 = dim2
            aAssoc.OnCg = CBool(sOnCg)
            Exit For
          End If
        Next
      Next i
    End If
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error writing Attribute data. " & err.Description
    Resume Next
End Sub

Public Sub WriteOperationData()
  Dim aDoc As DOMDocument
  Dim i As Long
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aCgItem As CgItem
  Dim sName As String
  Dim bSim As Boolean
  Dim sType As String
  Dim sSubType As String
  Dim sDiffType As String
  Dim aOperation As CgOperation
  Dim sOnCg As String
  
  On Error GoTo Error_Handler
  If Len(OperationsDataXML) > 0 Then
    Set aDoc = New DOMDocument
    OperationsDataXML = Replace(OperationsDataXML, "encoding=" & Chr(34) & "Windows-1252" & Chr(34), "")
    If aDoc.loadXML(OperationsDataXML) Then
      Set aNodeList = aDoc.getElementsByTagName("row")
      For i = 0 To aNodeList.length - 1
        Set aItem = aNodeList.Item(i)
        ' Name, Sim, Type, DiffType
        sName = aItem.Attributes(0).Text
        bSim = aItem.Attributes(1).Text
        sType = aItem.Attributes(2).Text
        sSubType = aItem.Attributes(3).Text
        sDiffType = aItem.Attributes(4).Text
        sOnCg = aItem.Attributes(5).Text
        Set aOperation = SelectedClass.Operations(sName)
        aOperation.bSim = bSim
        aOperation.sType = sType
        aOperation.sSubType = sSubType
        aOperation.sDiffType = sDiffType
        aOperation.OnCg = CBool(sOnCg)
      Next i
    End If
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error writing Operations data. " & err.Description
End Sub

Public Sub WriteStateData(idxState As Long)
  Dim aDoc As DOMDocument
  Dim i As Long
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aCgItem As CgItem
  Dim sName As String
  Dim bSim As Boolean
  Dim StateData As String
  Dim aState As CgState
  Dim aOperation As CgOperation
  
  On Error GoTo Error_Handler
  If Len(StateDataXML(idxState)) > 0 Then
    Set aDoc = New DOMDocument
    StateDataXML(idxState) = Replace(StateDataXML(idxState), "encoding=" & Chr(34) & "Windows-1252" & Chr(34), "")
    If aDoc.loadXML(StateDataXML(idxState)) Then
      Set aNodeList = aDoc.getElementsByTagName("row")
      Set aState = SelectedClass.States(idxState + 1)
      While aState.Eqns.count > 0
        aState.Eqns.Remove 1
      Wend
      For i = 0 To aNodeList.length - 1
        Set aItem = aNodeList.Item(i)
        ' Name, Sim
        sName = aItem.Attributes(0).Text
        bSim = aItem.Attributes(1).Text
        If bSim Then
          On Error Resume Next
          Set aOperation = SelectedClass.Operations(sName)
          If err = 0 Then
            Set aCgItem = New CgItem
            aCgItem.bSim = True
            aCgItem.Name = sName
            aState.Eqns.Add aCgItem
          End If
        End If
      Next i
    End If
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error writing State data. " & err.Description
End Sub

Public Sub WriteTransitionData(idxTransition As Long)
  Dim aTrans As CgTransition
  Dim aTrigger As CgTrigger
  Dim aCondition As CgTriggerCondition
  Dim i As Long
  Dim aDoc As DOMDocument
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim bNot As Boolean
  Dim sEqnName As String
  Dim sOperation As String
  Dim idxTrigger As Long
  Dim aTransition As CgTransition
  Dim sName As String
  Dim bSim As Boolean
  Dim aOperation As CgOperation
  Dim aCgItem As CgItem
  
  On Error GoTo Error_Handler
  Set aTrans = SelectedClass.Transitions(idxTransition + 1)
  
  If Len(TransitionDataXML(idxTransition)) > 0 Then
    Set aDoc = New DOMDocument
    TransitionDataXML(idxTransition) = Replace(TransitionDataXML(idxTransition), "encoding=" & Chr(34) & "Windows-1252" & Chr(34), "")
    If aDoc.loadXML(TransitionDataXML(idxTransition)) Then
      Set aNodeList = aDoc.getElementsByTagName("row")
      Set aTransition = SelectedClass.Transitions(idxTransition + 1)
      While aTransition.ResetEqns.count > 0
        aTransition.ResetEqns.Remove 1
      Wend
      For i = 0 To aNodeList.length - 1
        Set aItem = aNodeList.Item(i)
        ' Name, Sim
        sName = aItem.Attributes(0).Text
        bSim = aItem.Attributes(1).Text
        If bSim Then
          On Error Resume Next
          Set aOperation = SelectedClass.Operations(sName)
          If err = 0 Then
            Set aCgItem = New CgItem
            aCgItem.bSim = True
            aCgItem.Name = sName
            aTransition.ResetEqns.Add aCgItem
          End If
        End If
      Next i
    End If
  End If
  
  For idxTrigger = 0 To aTrans.Triggers.count - 1
    Set aTrigger = aTrans.Triggers(idxTrigger + 1)
    If Len(TriggerDataXML(idxTransition, idxTrigger)) > 0 Then
      Set aDoc = New DOMDocument
      TriggerDataXML(idxTransition, idxTrigger) = Replace(TriggerDataXML(idxTransition, idxTrigger), "encoding=" & Chr(34) & "Windows-1252" & Chr(34), "")
      If aDoc.loadXML(TriggerDataXML(idxTransition, idxTrigger)) Then
        Set aNodeList = aDoc.getElementsByTagName("row")
        For i = 0 To aNodeList.length - 1
          Set aItem = aNodeList.Item(i)
          ' bNot, sEqnName, sOperation
          bNot = aItem.Attributes(0).Text
          sEqnName = aItem.Attributes(1).Text
          sOperation = aItem.Attributes(2).Text
          Set aCondition = aTrigger.Conditions(i + 1)
          aCondition.bNot = bNot
          On Error Resume Next
          Set aCondition.Eqn = SelectedClass.Operations(sEqnName)
          aCondition.Operation = sOperation
        Next i
      End If

    End If
    
  Next idxTrigger
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error writing Transition data. " & err.Description
End Sub

