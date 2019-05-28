VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Object = "{97BD7A05-77E0-11D2-8EAE-008048E27A77}#1.0#0"; "beegd10.ocx"
Begin VB.Form frmUDItemDefVars 
   Caption         =   "Mask Attributes"
   ClientHeight    =   7200
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7905
   Icon            =   "frmUDItemDefVars.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   7200
   ScaleWidth      =   7905
   StartUpPosition =   1  'CenterOwner
   Begin VB.Frame frmButtons 
      BorderStyle     =   0  'None
      Height          =   1485
      Left            =   6600
      TabIndex        =   6
      Top             =   60
      Width           =   1335
      Begin VB.CommandButton btnOK 
         Caption         =   "OK"
         Height          =   375
         Left            =   0
         TabIndex        =   9
         Top             =   60
         Width           =   1275
      End
      Begin VB.CommandButton btnCancel 
         Caption         =   "Cancel"
         Height          =   375
         Left            =   0
         TabIndex        =   8
         Top             =   540
         Width           =   1275
      End
      Begin VB.CommandButton btnRefresh 
         Caption         =   "Refresh"
         Height          =   375
         Left            =   0
         TabIndex        =   7
         Top             =   1020
         Width           =   1275
      End
   End
   Begin VB.TextBox txtTS 
      Height          =   300
      Left            =   1200
      TabIndex        =   1
      Top             =   720
      Width           =   1095
   End
   Begin MSComDlg.CommonDialog CommDlg 
      Left            =   7080
      Top             =   2640
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.TextBox txtObjectName 
      Enabled         =   0   'False
      Height          =   300
      Left            =   1200
      TabIndex        =   0
      Top             =   240
      Width           =   4095
   End
   Begin BeeGrid10.SGGrid gdItems 
      Height          =   5535
      Left            =   60
      TabIndex        =   2
      Top             =   1620
      Width           =   7815
      _cx             =   13785
      _cy             =   9763
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
      StylesCollection=   $"frmUDItemDefVars.frx":0442
      ColumnsCollection=   $"frmUDItemDefVars.frx":1ED6
      ValueItems      =   $"frmUDItemDefVars.frx":2CAD
   End
   Begin CGModeler.ucUMLTreeView ucUMLTreeView 
      Height          =   30
      Left            =   120
      TabIndex        =   10
      Top             =   1440
      Visible         =   0   'False
      Width           =   6195
      _ExtentX        =   10927
      _ExtentY        =   53
   End
   Begin VB.Frame frmProjectSelection 
      Caption         =   "    Project Details"
      Height          =   250
      Left            =   60
      TabIndex        =   11
      Top             =   1200
      Width           =   6375
      Begin VB.CommandButton btnCollapse 
         Caption         =   ">"
         Height          =   220
         Left            =   0
         TabIndex        =   12
         Top             =   0
         Width           =   220
      End
   End
   Begin VB.Label Label3 
      Caption         =   "(ms)"
      Height          =   255
      Left            =   2370
      TabIndex        =   5
      Top             =   750
      Width           =   975
   End
   Begin VB.Label Label2 
      Caption         =   "Scan interval:"
      Height          =   255
      Left            =   150
      TabIndex        =   4
      Top             =   720
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "Object name:"
      Height          =   225
      Left            =   180
      TabIndex        =   3
      Top             =   240
      Width           =   945
   End
End
Attribute VB_Name = "frmUDItemDefVars"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public m_curUDIDef As UserDefinedItemDef
Public m_curUDI As UserDefinedItem
Public m_bDef As Boolean

Private m_Projects As Object
Private m_curProject As rtsProject

Private Const VALUE_COL = 4
Private Const DIM_COL = 7

' The following three properties are used by the ucUMLTreeView control
' to set the currently selected project\package\class

Public Sub SetSelectedProject(selProject As rtsProject)
  If m_curUDIDef Is Nothing Or selProject Is Nothing Then Exit Sub
  If m_bDef Then
    m_curUDIDef.ProjectName = selProject.Name
  Else
    m_curUDI.ProjectName = selProject.Name
  End If
End Sub

Public Sub SetSelectedPackage(selPackage As rtsPackage)
  If m_curUDIDef Is Nothing Or selPackage Is Nothing Then Exit Sub
  If m_bDef Then
    m_curUDIDef.PackageName = selPackage.Name
  Else
    m_curUDI.PackageName = selPackage.Name
  End If
End Sub

Public Sub SetSelectedClass(selClass As rtsClass)
 If m_curUDIDef Is Nothing Or selClass Is Nothing Then Exit Sub
 If m_bDef Then
    m_curUDIDef.ClassName = selClass.Name
 Else
    m_curUDI.ClassName = selClass.Name
 End If
End Sub

Sub InitAttributesGrid()
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim aCgItem As CgItem

  On Error GoTo Error_Handler
  gdItems.UserDragging = sgNoRowColDrag
  gdItems.Columns.RemoveAll
  
  Set aCol = gdItems.Columns.Add("Name")
  aCol.Width = 2000
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
  aCol.ReadOnly = True
  
  Set aCol = gdItems.Columns.Add("Sim")
  aCol.Width = 400
  Set ctrl = aCol.Control
  ctrl.Type = sgCellCheckBox
  aCol.ReadOnly = True
  
  Set aCol = gdItems.Columns.Add("DataType")
  aCol.Width = 1500
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
  aCol.ReadOnly = True
  
  Set aCol = gdItems.Columns.Add("Type")
  aCol.Width = 1500
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
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
  aCol.ReadOnly = True
  
  Set aCol = gdItems.Columns.Add("Value")           'This is what the user sees
  aCol.Width = 1500
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
  aCol.DefaultValue = ""
  
  Set aCol = gdItems.Columns.Add("ActualValue")     'This is the actual scalar, array, matrix value. Hidden
  aCol.Hidden = True
  aCol.Width = 500
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
  aCol.DefaultValue = ""
  
  Set aCol = gdItems.Columns.Add(" ")               'Button for matirx\array types
  aCol.Width = 260
  aCol.Style.Borders = sgCellBorderTop + sgCellBorderBottom
  aCol.AllowSizing = False
  Set ctrl = aCol.Control
  ctrl.ShowButton = sgShowButtonAlways
  ctrl.ButtonAlignment = sgButtonLeft
    
  Set aCol = gdItems.Columns.Add("Advanced")        'Hidden
  aCol.Hidden = True
  aCol.Width = 500
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
     
  gdItems.Rows.RemoveAll False
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Attribute grid initialization error: " & err.Description
End Sub

Sub FillGrid()
  Dim aAttr As CgAttribute
  Dim sType As Long
  Dim Attributes As Collection
  Dim dataType As String
  Dim i As Integer
  
  On Error GoTo Error_Handler
  If m_curUDIDef Is Nothing Then Exit Sub
  If m_bDef Then
    Set Attributes = m_curUDIDef.Attributes
  Else
    Set Attributes = m_curUDI.Attributes
  End If
  
  For Each aAttr In Attributes
    If aAttr.sType = idxAttr_Connector Then aAttr.Value = ""        'don't want to override connector pointers
    'If we are populating an object instance, need to retrieve correct type from the default def (not serialized to\from property bag)
    dataType = aAttr.dataType
    If (Not m_bDef) And (Not m_curUDIDef Is Nothing) Then
        For i = 1 To m_curUDIDef.Attributes.count
            If m_curUDIDef.Attributes(i).Name = aAttr.Name Then
                dataType = m_curUDIDef.Attributes(i).dataType
                Exit For
            End If
        Next i
    End If
    gdItems.Rows.Add sgFormatCharSeparatedValue, aAttr.Name & "," & aAttr.bSim & "," & dataType & "," & aAttr.sType & "," & CStr(aAttr.Value) & "," & CStr(aAttr.Value) & "," & CStr(aAttr.dim1 & DASH_DELIMETER & aAttr.dim2) & "," & aAttr.sSubType
    Select Case aAttr.sSubType
        Case idxAttr_Scalar:
            gdItems.Rows.Last.Cells(VALUE_COL).ReadOnly = False
        Case idxAttr_Array:
            gdItems.Rows.Last.Cells(VALUE_COL).Value = "<Array>"
            gdItems.Rows.Last.Cells(VALUE_COL).ReadOnly = True
        Case idxAttr_Matrix:
            gdItems.Rows.Last.Cells(VALUE_COL).Value = "<Matrix>"
            gdItems.Rows.Last.Cells(VALUE_COL).ReadOnly = True
    End Select
  Next
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error . " & err.Description
End Sub

Private Sub btnCancel_Click()
  Unload Me
End Sub

Private Sub btnOK_Click()
  Dim idxNameCol, idxValueCol, idxTypeCol As Long
  Dim i As Long
  Dim szName As String
  Dim nValue As String
  Dim strValue As String
  Dim aAttr As CgAttribute
  Dim attrs, attrsDef As Collection
  Dim iType As Integer
  
  On Error GoTo Unload_Form
  If m_curUDIDef Is Nothing Then Exit Sub
  Set attrsDef = m_curUDIDef.Attributes
  If Not m_curUDI Is Nothing Then
        Set attrs = m_curUDI.Attributes
  End If
   
  idxNameCol = 0
  idxTypeCol = 7
  idxValueCol = 5
  For i = 0 To gdItems.Rows.count - 2
    szName = gdItems.Array(i, idxNameCol)
    strValue = gdItems.Array(i, idxValueCol)
    iType = gdItems.Array(i, idxTypeCol)
    nValue = gdItems.Array(i, idxValueCol)
    
    If m_bDef Then
      For Each aAttr In attrsDef
        If aAttr.Name = szName Then
          aAttr.Value = nValue
          Exit For
        End If
      Next
    Else
      If Not m_curUDI Is Nothing Then
          For Each aAttr In attrs
            If aAttr.Name = szName Then
              aAttr.Value = nValue
              Exit For
            End If
          Next
      End If
    End If
  Next i
  
  m_curUDIDef.IsDirty = True
  If Not m_curUDI Is Nothing Then
    m_curUDI.IsDirty = True
  End If

Unload_Form:
  Unload Me
End Sub

Private Sub btnRefresh_Click()
  Dim aInfo As rtsClass
  Dim aAttr As CgAttribute
  Dim newAttr As CgAttribute
  Dim szPackageName As String
  Dim szClassName As String
  Dim i As Integer
  
  On Error Resume Next
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
      
  If m_curUDIDef Is Nothing Then Exit Sub
  If m_bDef Then
      If Not m_curUDIDef Is Nothing Then
        szPackageName = m_curUDIDef.PackageName
        szClassName = m_curUDIDef.ClassName
        szClassName = Replace(szClassName, " ", "_")
    
        For i = 1 To Projects.count
            If m_curUDIDef.ProjectName = Projects.Item(i).Name Then
                Set m_curProject = Projects.Item(i)
                Exit For
            End If
        Next
    
        If err = 0 Then
          If GetClassInfo(m_curProject, szPackageName, szClassName, aInfo) Then
            Set m_curUDIDef.Attributes = New Collection
            For Each aAttr In aInfo.Attributes
                Set newAttr = New CgAttribute
                aAttr.Copy newAttr
                m_curUDIDef.Attributes.Add newAttr
            Next
            InitAttributesGrid
            FillGrid
          End If
        End If
      End If
  Else
    If Not m_curUDI Is Nothing Then
        szPackageName = m_curUDI.PackageName
        szClassName = m_curUDI.ClassName
        szClassName = Replace(szClassName, " ", "_")
        For i = 1 To Projects.count
            If m_curUDI.ProjectName = Projects.Item(i).Name Then
                Set m_curProject = Projects.Item(i)
                Exit For
            End If
        Next
      
        If err = 0 Then
          If GetClassInfo(m_curProject, szPackageName, szClassName, aInfo) Then
            Set m_curUDI.Attributes = New Collection
            For Each aAttr In aInfo.Attributes
                Set newAttr = New CgAttribute
                aAttr.Copy newAttr
                m_curUDI.Attributes.Add newAttr
            Next
            InitAttributesGrid
            FillGrid
          End If
        End If
      End If
  End If
End Sub

Private Sub btnCollapse_Click()
    On Error Resume Next
    If btnCollapse.Caption = "x" Then
        frmProjectSelection.Height = 250
        ucUMLTreeView.Height = 10
        ucUMLTreeView.Visible = False
        btnCollapse.Caption = ">"
    Else
        frmProjectSelection.Height = 2700
        ucUMLTreeView.Height = 2415
        ucUMLTreeView.Visible = True
        btnCollapse.Caption = "x"
    End If
    btnOK.SetFocus 'Take the focus off the btnCollapse, otherwise it looks wierd
    form_Resize
End Sub

Private Sub Form_Load()
  InitAttributesGrid
  FillGrid
  
  'Populate the UML project selection control
  If Projects.count > 0 And Not ucUMLTreeView Is Nothing Then
    ucUMLTreeView.PopulateProjectsList Projects, , , True   'Set to not recieve tree updates since don't want to change project\class\package of our shape at this point
  End If
  
  If m_curUDIDef Is Nothing Then Exit Sub
  If m_bDef Then
    txtObjectName.Text = m_curUDIDef.GeShape
    txtTS.Text = m_curUDIDef.TS
    ucUMLTreeView.ProjectName = m_curUDIDef.ProjectName
    ucUMLTreeView.PackagesName = m_curUDIDef.PackageName
    ucUMLTreeView.ClassName = m_curUDIDef.ClassName
  Else
    ' KAB need to enable the object name for instances
    txtObjectName.Enabled = True
    txtObjectName.Text = m_curUDI.ObjectName
    txtTS.Text = m_curUDI.TS
    ucUMLTreeView.ProjectName = m_curUDI.ProjectName
    ucUMLTreeView.PackagesName = m_curUDI.PackageName
    ucUMLTreeView.ClassName = m_curUDI.ClassName
  End If
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, y As Single)
    Screen.MousePointer = vbArrow
End Sub

Private Sub form_Resize()
    On Error Resume Next
    frmButtons.Left = Abs(Me.Width - 1450)
    gdItems.Width = Abs(Me.Width - 250)
    gdItems.Height = Abs(Me.Height - frmProjectSelection.Height - 1800)
    frmProjectSelection.Width = Abs(gdItems.Width - frmButtons.Width - 200)
    ucUMLTreeView.Width = Abs(frmProjectSelection.Width - 180)
    gdItems.Top = frmProjectSelection.Height + 1350
End Sub


Private Sub gdItems_ButtonClick(ByVal RowKey As Long, ByVal ColIndex As Long, Cancel As Boolean)
    Dim m_frmValueSet As frmSetArrayAndMatrix
    Dim iType, iRowPos As Integer
        
    On Error Resume Next
    If ColIndex = DIM_COL Then
        'iRowPos = gdItems.Rows(RowKey).Position - 1
        'iType = gdItems.Array(iRowPos, ColIndex)
        iRowPos = gdItems.CurrentCell.Row.Position - 1
        iType = gdItems.CurrentCell.Row.Cells(ColIndex)
        Select Case iType
            Case idxAttr_Scalar
                Set m_frmValueSet = New frmSetArrayAndMatrix
                Set m_frmValueSet.GridArray = gdItems
                m_frmValueSet.InitScalar iRowPos
                m_frmValueSet.Show vbModal
                m_frmValueSet.Refresh
            Case idxAttr_Array
                Set m_frmValueSet = New frmSetArrayAndMatrix
                Set m_frmValueSet.GridArray = gdItems
                m_frmValueSet.InitArray iRowPos
                m_frmValueSet.Show vbModal
                m_frmValueSet.Refresh
            Case idxAttr_Matrix
                Set m_frmValueSet = New frmSetArrayAndMatrix
                Set m_frmValueSet.GridArray = gdItems
                m_frmValueSet.InitMatrix iRowPos
                m_frmValueSet.Show vbModal
                m_frmValueSet.Refresh
        End Select
    End If
End Sub

Private Sub gdItems_AfterEdit(ByVal RowKey As Long, ByVal ColIndex As Long)
    Dim iRowPos As Integer
    Dim strValue As String
    Dim iValueCol, iActualValueCol, iTypeCol As Integer
                
    On Error Resume Next
    iValueCol = VALUE_COL
    iTypeCol = DIM_COL
    iActualValueCol = 5
    If ColIndex = iActualValueCol Then
       iRowPos = gdItems.Rows(RowKey).Position - 1
       If gdItems.Array(iRowPos, iTypeCol) = idxAttr_Scalar Then
            gdItems.Array(iRowPos, iActualValueCol) = gdItems.Array(iRowPos, iValueCol)
       End If
    End If
End Sub

Private Sub txtObjectName_Change()
  On Error Resume Next
  If m_curUDI Is Nothing Then Exit Sub
   m_curUDI.ObjectName = txtObjectName.Text
End Sub

Private Sub txtTS_Change()
  On Error Resume Next
  If m_curUDIDef Is Nothing Then Exit Sub
  If m_bDef Then
    m_curUDIDef.TS = CLng(txtTS.Text)
  Else
    m_curUDI.TS = CLng(txtTS.Text)
  End If
End Sub

