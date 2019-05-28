VERSION 5.00
Object = "{97BD7A05-77E0-11D2-8EAE-008048E27A77}#1.0#0"; "beegd10.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmClassModificationDetail 
   BorderStyle     =   5  'Sizable ToolWindow
   Caption         =   "Class Modification Detail"
   ClientHeight    =   6045
   ClientLeft      =   60
   ClientTop       =   300
   ClientWidth     =   5205
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   6045
   ScaleWidth      =   5205
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton btnClearAll 
      Caption         =   "Clear All"
      Height          =   375
      Left            =   1080
      TabIndex        =   8
      Top             =   5580
      Width           =   915
   End
   Begin VB.CommandButton btnSelectAll 
      Caption         =   "Select All"
      Height          =   375
      Left            =   60
      TabIndex        =   7
      Top             =   5580
      Width           =   915
   End
   Begin VB.CommandButton btnCancel 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4140
      TabIndex        =   5
      Top             =   5580
      Width           =   975
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "OK"
      Height          =   375
      Left            =   3060
      TabIndex        =   4
      Top             =   5580
      Width           =   975
   End
   Begin BeeGrid10.SGGrid gdAttributes 
      Height          =   4635
      Left            =   180
      TabIndex        =   1
      Top             =   720
      Width           =   4815
      _cx             =   8493
      _cy             =   8176
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
      StylesCollection=   $"frmClassModificationDetail.frx":0000
      ColumnsCollection=   $"frmClassModificationDetail.frx":1A94
      ValueItems      =   $"frmClassModificationDetail.frx":286B
   End
   Begin BeeGrid10.SGGrid gdRelations 
      Height          =   4635
      Left            =   180
      TabIndex        =   2
      Top             =   720
      Width           =   4815
      _cx             =   8493
      _cy             =   8176
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
      StylesCollection=   $"frmClassModificationDetail.frx":2C50
      ColumnsCollection=   $"frmClassModificationDetail.frx":46E4
      ValueItems      =   $"frmClassModificationDetail.frx":54BB
   End
   Begin BeeGrid10.SGGrid gdOperations 
      Height          =   4635
      Left            =   180
      TabIndex        =   3
      Top             =   720
      Width           =   4815
      _cx             =   8493
      _cy             =   8176
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
      StylesCollection=   $"frmClassModificationDetail.frx":58A0
      ColumnsCollection=   $"frmClassModificationDetail.frx":7334
      ValueItems      =   $"frmClassModificationDetail.frx":810B
   End
   Begin MSComctlLib.TabStrip tbClassDetail 
      Height          =   5115
      Left            =   60
      TabIndex        =   0
      Top             =   360
      Width           =   5055
      _ExtentX        =   8916
      _ExtentY        =   9022
      _Version        =   393216
      BeginProperty Tabs {1EFB6598-857C-11D1-B16A-00C0F0283628} 
         NumTabs         =   3
         BeginProperty Tab1 {1EFB659A-857C-11D1-B16A-00C0F0283628} 
            Caption         =   "Attributes"
            ImageVarType    =   2
         EndProperty
         BeginProperty Tab2 {1EFB659A-857C-11D1-B16A-00C0F0283628} 
            Caption         =   "Relations"
            ImageVarType    =   2
         EndProperty
         BeginProperty Tab3 {1EFB659A-857C-11D1-B16A-00C0F0283628} 
            Caption         =   "Operations"
            ImageVarType    =   2
         EndProperty
      EndProperty
   End
   Begin VB.Label lbClass 
      Alignment       =   2  'Center
      Caption         =   "Label1"
      Height          =   255
      Left            =   120
      TabIndex        =   6
      Top             =   60
      Width           =   4995
   End
End
Attribute VB_Name = "frmClassModificationDetail"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Const COL_NAME = 0
Private Const COL_ACTION = 1
Private Const COL_APPLY = 2
Private Const COL_DIFF = 3
Private Const COL_DETAIL = 4

Private Const idxAction_None = 1
Private Const idxAction_Add = 2
Private Const idxAction_Delete = 3
Private Const idxAction_Update = 4

Private Const COMPARE_SAME = &H0
Private Const COMPARE_NEW = &H1
Private Const COMPARE_OLD = &H2
Private Const COMPARE_DIFF = &H4
Private Const COMPARE_DIFF_AND_REPLACE = &H8

Private Const DISPLAY_ROW_COUNT = 16            'Number of Rows that fit in the dialog initially
Private Const DETAIL_BUTTON_WIDTH = 230

Private m_diffAttributes As Collection
Private m_diffRelations As Collection
Private m_diffOperations As Collection

Public m_cgParent As CgCompareCollection
Public bAbortAddDelete As Boolean

Private Sub btnCancel_Click()
    bAbortAddDelete = True
    Unload Me
End Sub

Private Sub btnOK_Click()
    Dim i As Integer
    Dim iRow As Long
    Dim attribName As String
    Dim iFlag As Integer
    
    On Error GoTo Unload_Form
    iRows = gdAttributes.RowCount - 1
    For i = 0 To iRows - 1
        iFlag = GetRowFlag(i, gdAttributes)
        m_diffAttributes(i + 1).lCompare = iFlag
    Next i
    
    iRows = gdRelations.RowCount - 1
    For i = 0 To iRows - 1
        iFlag = GetRowFlag(i, gdRelations)
        m_diffRelations(i + 1).lCompare = iFlag
    Next i
    
    iRows = gdOperations.RowCount - 1
    For i = 0 To iRows - 1
        iFlag = GetRowFlag(i, gdOperations)
        m_diffOperations(i + 1).lCompare = iFlag
    Next i
    
    If Not m_cgParent Is Nothing Then
        m_cgParent.WriteBackArrays m_diffAttributes, m_diffRelations, m_diffOperations
    Else
        gMsgWnd.LogMessage "Could not save Attributes, Relations, and Operations"
    End If

Unload_Form:
    Unload Me
End Sub

Private Function GetRowFlag(i As Integer, gdGrid As SGGrid) As Integer
    Dim iAction As Integer
    Dim iApply As Boolean
    
    GetRowFlag = -1
    iAction = gdGrid.Array(i, COL_ACTION)
    iApply = gdGrid.Array(i, COL_APPLY)
    If iApply Then
        Select Case iAction
            Case idxAction_Add:
                GetRowFlag = COMPARE_NEW
            Case idxAction_Delete:
                GetRowFlag = COMPARE_OLD
            Case idxAction_Update:
                GetRowFlag = CompareObjects(i, gdGrid)
            Case Else:
                GetRowFlag = COMPARE_DIFF   'Changes will not be saved
        End Select
    Else
        GetRowFlag = COMPARE_SAME
    End If
End Function

Private Function CompareObjects(i As Integer, gdGrid As SGGrid) As Integer
    Dim cgHelper As cgCompareHelper
    Dim strGridType As String
    Dim strName As String
    
    On Error Resume Next
    strGridType = gdGrid.Name
    strName = gdGrid.Array(i, COL_NAME)
    Select Case strGridType
        Case "gdAttributes":
            Set cgHelper = m_diffAttributes(strName)
            If cgHelper Is Nothing Then Exit Function
            If cgHelper.AttributesEqual() Then
                CompareObjects = COMPARE_SAME
            Else
                CompareObjects = COMPARE_DIFF_AND_REPLACE   'New different version will be saved
            End If
        Case "gdRelations":
            Set cgHelper = m_diffRelations(strName)
            If cgHelper Is Nothing Then Exit Function
            If cgHelper.RelationsEqual() Then
                CompareObjects = COMPARE_SAME
            Else
                CompareObjects = COMPARE_DIFF_AND_REPLACE   'New different version will be saved
            End If
        Case "gdOperations":
            Set cgHelper = m_diffOperations(strName)
            If cgHelper Is Nothing Then Exit Function
            If cgHelper.OperationsEqual() Then
                CompareObjects = COMPARE_SAME
            Else
                CompareObjects = COMPARE_DIFF_AND_REPLACE   'New different version will be saved
            End If
    End Select
End Function

Private Sub btnSelectAll_Click()
    Dim i As Integer
    
    On Error Resume Next
    If tbClassDetail.SelectedItem.Index = 1 Then      'Attributes Tab
        For i = 0 To gdAttributes.Rows.count - 2
            gdAttributes.Array(i, COL_APPLY) = 1
            gdAttributes.RedrawCol COL_APPLY
        Next i
    ElseIf tbClassDetail.SelectedItem.Index = 2 Then  'Relations Tab
        For i = 0 To gdRelations.Rows.count - 2
            gdRelations.Array(i, COL_APPLY) = 1
            gdRelations.RedrawCol COL_APPLY
        Next i
    Else                                              'Operations Tab
        For i = 0 To gdOperations.Rows.count - 2
            gdOperations.Array(i, COL_APPLY) = 1
            gdOperations.RedrawCol COL_APPLY
        Next i
    End If
End Sub

Private Sub btnClearAll_Click()
    Dim i As Integer
    
    On Error Resume Next
    If tbClassDetail.SelectedItem.Index = 1 Then      'Attributes Tab
        For i = 0 To gdAttributes.Rows.count - 2
            gdAttributes.Array(i, COL_APPLY) = 0
            gdAttributes.RedrawCol COL_APPLY
        Next i
    ElseIf tbClassDetail.SelectedItem.Index = 2 Then  'Relations Tab
        For i = 0 To gdRelations.Rows.count - 2
            gdRelations.Array(i, COL_APPLY) = 0
            gdRelations.RedrawCol COL_APPLY
        Next i
    Else                                              'Operations Tab
        For i = 0 To gdOperations.Rows.count - 2
            gdOperations.Array(i, COL_APPLY) = 0
            gdOperations.RedrawCol COL_APPLY
        Next i
    End If
End Sub

Private Sub Form_Load()
    gdAttributes.GroupByBoxVisible = False
    gdRelations.GroupByBoxVisible = False
    gdOperations.GroupByBoxVisible = False
End Sub

Public Sub SetClassName(strClassName As String)
    lbClass.Caption = strClassName
    lbClass.Refresh
End Sub

Public Sub InitAttributesGrid(diffAttributes As Collection)
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim aCgItem As CgItem
  Dim i As Integer
  
  On Error GoTo Error_Handler
  gdAttributes.UserDragging = sgNoRowColDrag
  gdAttributes.Columns.RemoveAll
  Set m_diffAttributes = diffAttributes
  
  Set aCol = gdAttributes.Columns.Add("Attribute")
  aCol.Width = Abs(gdOperations.Width - 1860)
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
  aCol.ReadOnly = True
  
  Set aCol = gdAttributes.Columns.Add("Action")
  aCol.Width = 1000
  Set ctrl = aCol.Control
  ctrl.Type = sgCellDropDown
  Set vis = aCol.ValueItems
  vis.Add idxAction_None, "None"
  vis.Add idxAction_Add, "Add"
  vis.Add idxAction_Delete, "Delete"
  vis.Add idxAction_Update, "Update"
  aCol.DefaultValue = idxAction_None
  ctrl.ShowButton = sgShowButtonAlways
  ctrl.PopupRows = 4
  Set vis = Nothing
  Set ctrl = Nothing
  
  Set aCol = gdAttributes.Columns.Add("Apply")
  aCol.Width = 550
  aCol.Style.TextAlignment = sgAlignCenterCenter
  Set ctrl = aCol.Control
  ctrl.Type = sgCellCheckBox
  
  Set aCol = gdAttributes.Columns.Add(" ")               'Button for matirx\array types
  aCol.Width = 260
  aCol.Style.Borders = sgCellBorderTop + sgCellBorderBottom
  aCol.AllowSizing = False
  Set ctrl = aCol.Control
  ctrl.ShowButton = sgShowButtonAlways
  ctrl.ButtonAlignment = sgButtonLeft
          
  gdAttributes.Rows.RemoveAll False
 
  If m_diffAttributes Is Nothing Then Exit Sub

  For i = 1 To diffAttributes.count
    Select Case diffAttributes(i).lCompare
        Case COMPARE_SAME:
            gdAttributes.Rows.Add sgFormatCharSeparatedValue, diffAttributes(i).Name & "," & idxAction_None & ",0,..."
        Case COMPARE_DIFF:
            gdOperations.Rows.Add sgFormatCharSeparatedValue, diffAttributes(i).Name & "," & idxAction_Update & ",1,..."
        Case COMPARE_NEW:
            gdAttributes.Rows.Add sgFormatCharSeparatedValue, diffAttributes(i).Name & "," & idxAction_Add & ",1,..."
        Case COMPARE_OLD:
            gdAttributes.Rows.Add sgFormatCharSeparatedValue, diffAttributes(i).Name & "," & idxAction_Delete & ",1,..."
    End Select
  Next i
  
  If gdAttributes.Rows.count > DISPLAY_ROW_COUNT Then
      gdAttributes.Columns("Attribute").Width = gdAttributes.Columns("Attribute").Width - DETAIL_BUTTON_WIDTH
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error initializing attribute details. " & err.Description
End Sub

Public Sub InitRelationsGrid(diffRelations As Collection)
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim aCgItem As CgItem

  On Error GoTo Error_Handler
  Set m_diffRelations = diffRelations
  gdRelations.UserDragging = sgNoRowColDrag
  gdRelations.Columns.RemoveAll
  
  Set aCol = gdRelations.Columns.Add("Attribute")
  aCol.Width = Abs(gdOperations.Width - 1860)
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
  aCol.ReadOnly = True
  
  Set aCol = gdRelations.Columns.Add("Action")
  aCol.Width = 1000
  Set ctrl = aCol.Control
  ctrl.Type = sgCellDropDown
  Set vis = aCol.ValueItems
  vis.Add idxAction_None, "None"
  vis.Add idxAction_Add, "Add"
  vis.Add idxAction_Delete, "Delete"
  vis.Add idxAction_Update, "Update"
  aCol.DefaultValue = idxAction_None
  ctrl.ShowButton = sgShowButtonAlways
  ctrl.PopupRows = 4
  Set vis = Nothing
  Set ctrl = Nothing

  Set aCol = gdRelations.Columns.Add("Apply")
  aCol.Width = 550
  aCol.Style.TextAlignment = sgAlignCenterCenter
  Set ctrl = aCol.Control
  ctrl.Type = sgCellCheckBox
  
  Set aCol = gdRelations.Columns.Add(" ")               'Button for matirx\array types
  aCol.Width = 260
  aCol.Style.Borders = sgCellBorderTop + sgCellBorderBottom
  aCol.AllowSizing = False
  Set ctrl = aCol.Control
  ctrl.ShowButton = sgShowButtonAlways
  ctrl.ButtonAlignment = sgButtonLeft
        
  gdRelations.Rows.RemoveAll False
  
  If m_diffRelations Is Nothing Then Exit Sub
  
  For i = 1 To diffRelations.count
    Select Case diffRelations(i).lCompare
        Case COMPARE_SAME:
            gdRelations.Rows.Add sgFormatCharSeparatedValue, diffRelations(i).Name & "," & idxAction_None & ",0,..."
        Case COMPARE_DIFF:
            gdRelations.Rows.Add sgFormatCharSeparatedValue, diffRelations(i).Name & "," & idxAction_Update & ",1,..."
        Case COMPARE_NEW:
            gdRelations.Rows.Add sgFormatCharSeparatedValue, diffRelations(i).Name & "," & idxAction_Add & ",1,..."
        Case COMPARE_OLD:
            gdRelations.Rows.Add sgFormatCharSeparatedValue, diffRelations(i).Name & "," & idxAction_Delete & ",1,..."
    End Select
  Next i
  
  If gdRelations.Rows.count > DISPLAY_ROW_COUNT Then
      gdRelations.Columns("Attribute").Width = gdRelations.Columns("Attribute").Width - DETAIL_BUTTON_WIDTH
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error initializing Relations details. " & err.Description
End Sub

Public Sub InitOperationsGrid(diffOperations As Collection)
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim aCgItem As CgItem

  On Error GoTo Error_Handler
  gdOperations.UserDragging = sgNoRowColDrag
  gdOperations.Columns.RemoveAll
  Set m_diffOperations = diffOperations
  
  Set aCol = gdOperations.Columns.Add("Attribute")
  aCol.Width = Abs(gdOperations.Width - 1860)
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
  aCol.ReadOnly = True
  
  Set aCol = gdOperations.Columns.Add("Action")
  aCol.Width = 1000
  Set ctrl = aCol.Control
  ctrl.Type = sgCellDropDown
  Set vis = aCol.ValueItems
  vis.Add idxAction_None, "None"
  vis.Add idxAction_Add, "Add"
  vis.Add idxAction_Delete, "Delete"
  vis.Add idxAction_Update, "Update"
  aCol.DefaultValue = idxAction_None
  ctrl.ShowButton = sgShowButtonAlways
  ctrl.PopupRows = 4
  Set vis = Nothing
  Set ctrl = Nothing

  Set aCol = gdOperations.Columns.Add("Apply")
  aCol.Width = 550
  aCol.Style.TextAlignment = sgAlignCenterCenter
  Set ctrl = aCol.Control
  ctrl.Type = sgCellCheckBox
  
  Set aCol = gdOperations.Columns.Add(" ")               'Button for matirx\array types
  aCol.Width = 260
  aCol.Style.Borders = sgCellBorderTop + sgCellBorderBottom
  aCol.AllowSizing = False
  Set ctrl = aCol.Control
  ctrl.ShowButton = sgShowButtonAlways
  ctrl.ButtonAlignment = sgButtonLeft
         
  gdOperations.Rows.RemoveAll False
  If m_diffOperations Is Nothing Then Exit Sub
  
  For i = 1 To diffOperations.count
    Select Case diffOperations(i).lCompare
        Case COMPARE_SAME:
            gdOperations.Rows.Add sgFormatCharSeparatedValue, diffOperations(i).Name & "," & idxAction_None & ",0,..."
        Case COMPARE_DIFF:
            gdOperations.Rows.Add sgFormatCharSeparatedValue, diffOperations(i).Name & "," & idxAction_Update & ",1,..."
        Case COMPARE_NEW:
            gdOperations.Rows.Add sgFormatCharSeparatedValue, diffOperations(i).Name & "," & idxAction_Add & ",1,..."
        Case COMPARE_OLD:
            gdOperations.Rows.Add sgFormatCharSeparatedValue, diffOperations(i).Name & "," & idxAction_Delete & ",1,..."
    End Select
  Next i
  
  If gdOperations.Rows.count > DISPLAY_ROW_COUNT Then
      gdOperations.Columns("Attribute").Width = gdOperations.Columns("Attribute").Width - DETAIL_BUTTON_WIDTH
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error initializing operations details. " & err.Description
End Sub

Private Sub Form_Resize()
    On Error Resume Next
    tbClassDetail.Width = Abs(Me.Width - 265)
    tbClassDetail.Height = Abs(Me.Height - 1290)
    gdAttributes.Width = Abs(tbClassDetail.Width - 240)
    gdRelations.Width = gdAttributes.Width
    gdOperations.Width = gdAttributes.Width
    gdAttributes.Height = Abs(tbClassDetail.Height - 500)
    gdRelations.Height = gdAttributes.Height
    gdOperations.Height = gdAttributes.Height
    btnOK.Left = Abs(Me.Width - 2265)
    btnCancel.Left = Abs(Me.Width - 1185)
    btnOK.Top = Abs(Me.Height - 825)
    btnCancel.Top = btnOK.Top
    btnSelectAll.Top = btnOK.Top
    btnClearAll.Top = btnOK.Top
End Sub


Private Sub gdAttributes_ValidateEdit(ByVal RowKey As Long, _
   ByVal ColIndex As Long, ByVal oldValue As Variant, Cancel As Boolean)
    Dim iType, iRowPos As Integer
    
    On Error Resume Next
    iRowPos = gdAttributes.Rows(RowKey).Position - 1
    
    If ColIndex = COL_ACTION + 1 Then
         iType = gdAttributes.Array(iRowPos, COL_ACTION)
         If iType = idxAction_None And oldValue <> iType Then
            gdAttributes.Array(iRowPos, COL_APPLY) = False
         Else
            gdAttributes.Array(iRowPos, COL_APPLY) = True
         End If
         gdAttributes.RedrawCol COL_APPLY
    End If
End Sub

Private Sub gdRelations_ValidateEdit(ByVal RowKey As Long, _
   ByVal ColIndex As Long, ByVal oldValue As Variant, Cancel As Boolean)
    Dim iType, iRowPos As Integer
    
    On Error Resume Next
    iRowPos = gdRelations.Rows(RowKey).Position - 1
    
    If ColIndex = COL_ACTION + 1 Then
         iType = gdRelations.Array(iRowPos, COL_ACTION)
         If iType = idxAction_None And oldValue <> iType Then
            gdRelations.Array(iRowPos, COL_APPLY) = False
         Else
            gdRelations.Array(iRowPos, COL_APPLY) = True
         End If
         gdRelations.RedrawCol COL_APPLY
    End If
End Sub

Private Sub gdOperations_ValidateEdit(ByVal RowKey As Long, _
   ByVal ColIndex As Long, ByVal oldValue As Variant, Cancel As Boolean)
    Dim iType, iRowPos As Integer
    
    On Error Resume Next
    iRowPos = gdOperations.Rows(RowKey).Position - 1
    
    If ColIndex = COL_ACTION + 1 Then
         iType = gdOperations.Array(iRowPos, COL_ACTION)
         If iType = idxAction_None And oldValue <> iType Then
            gdOperations.Array(iRowPos, COL_APPLY) = False
         Else
            gdOperations.Array(iRowPos, COL_APPLY) = True
         End If
         gdOperations.RedrawCol COL_APPLY
    End If
End Sub

Private Sub gdOperations_ButtonClick(ByVal RowKey As Long, ByVal ColIndex As Long, Cancel As Boolean)
    Dim frmOperationsDetail As frmOperationsDetail
    Dim iType, iRowPos As Integer
    Dim cgHelper As cgCompareHelper
    Dim strName As String
        
    On Error Resume Next
    iRowPos = gdOperations.Rows(RowKey).Position - 1
    If ColIndex = COL_DETAIL Then
                
        Set frmOperationsDetail = New frmOperationsDetail
        Set frmOperationsDetail.m_frmParent = Me
        
        strName = gdOperations.Array(iRowPos, COL_NAME)
        Set cgHelper = m_diffOperations(strName)
        If Not cgHelper Is Nothing Then
            frmOperationsDetail.SetBodyText cgHelper, iRowPos
            frmOperationsDetail.Show vbModal
            frmOperationsDetail.Refresh
        End If
    End If
End Sub

Private Sub gdRelations_ButtonClick(ByVal RowKey As Long, ByVal ColIndex As Long, Cancel As Boolean)
    Dim frmRelationDetail As frmRelationDetail
    Dim iType, iRowPos As Integer
    Dim cgHelper As cgCompareHelper
    Dim strName As String
        
    On Error Resume Next
    iRowPos = gdRelations.Rows(RowKey).Position - 1
            
    If ColIndex = COL_DETAIL Then
        Set frmRelationDetail = New frmRelationDetail
        Set frmRelationDetail.m_frmParent = Me
        
        strName = gdRelations.Array(iRowPos, COL_NAME)
        Set cgHelper = m_diffRelations(strName)
        If Not cgHelper Is Nothing Then
            frmRelationDetail.SetBodyText cgHelper, iRowPos
            frmRelationDetail.Show vbModal
            frmRelationDetail.Refresh
        End If
    End If
End Sub

Private Sub gdAttributes_ButtonClick(ByVal RowKey As Long, ByVal ColIndex As Long, Cancel As Boolean)
    Dim frmAttributeDetail As frmAttributeDetail
    Dim iType, iRowPos As Integer
    Dim cgHelper As cgCompareHelper
    Dim strName As String
        
    On Error Resume Next
    iRowPos = gdAttributes.Rows(RowKey).Position - 1
            
    If ColIndex = COL_DETAIL Then
        Set frmAttributeDetail = New frmAttributeDetail
        Set frmAttributeDetail.m_frmParent = Me
        
        strName = gdAttributes.Array(iRowPos, 0)
        Set cgHelper = m_diffAttributes(strName)
        If Not cgHelper Is Nothing Then
            frmAttributeDetail.SetBodyText cgHelper, iRowPos
            frmAttributeDetail.Show vbModal
            frmAttributeDetail.Refresh
        End If
    End If
End Sub

Private Sub tbClassDetail_Click()
    If tbClassDetail.SelectedItem.Index = 1 Then      'Attributes Tab
        gdAttributes.Visible = True
        gdRelations.Visible = False
        gdOperations.Visible = False
    ElseIf tbClassDetail.SelectedItem.Index = 2 Then  'Relations Tab
        gdAttributes.Visible = False
        gdRelations.Visible = True
        gdOperations.Visible = False
    Else                                              'Operations Tab
        gdAttributes.Visible = False
        gdRelations.Visible = False
        gdOperations.Visible = True
    End If
End Sub

Public Sub WriteBackAttribute(cgCompareHelper As cgCompareHelper, iRowPos As Integer)
    Dim cgHelper As cgCompareHelper
    
    On Error Resume Next
    Set cgHelper = m_diffAttributes(gdAttributes.Array(iRowPos, COL_NAME))
    If Not cgCompareHelper Is Nothing And Not cgHelper Is Nothing Then
        Set cgHelper = cgCompareHelper
        'Set to update and apply if operation editing resulted in a different operation
        If Not cgHelper.AttributesEqual() Then
            If gdAttributes.Array(iRowPos, COL_ACTION) = idxAction_None Then
                gdAttributes.Array(iRowPos, COL_ACTION) = idxAction_Update
                gdAttributes.Array(iRowPos, COL_APPLY) = True
            End If
        End If
    End If
End Sub

Public Sub WriteBackRelation(cgCompareHelper As cgCompareHelper, iRowPos As Integer)
    Dim cgHelper As cgCompareHelper
    
    On Error Resume Next
    Set cgHelper = m_diffRelations(gdRelations.Array(iRowPos, COL_NAME))
    If Not cgCompareHelper Is Nothing And Not cgHelper Is Nothing Then
        Set cgHelper = cgCompareHelper
        'Set to update and apply if operation editing resulted in a different operation
        If Not cgHelper.RelationsEqual() Then
            If gdRelations.Array(iRowPos, COL_ACTION) = idxAction_None Then
                gdRelations.Array(iRowPos, COL_ACTION) = idxAction_Update
                gdRelations.Array(iRowPos, COL_APPLY) = True
            End If
        End If
    End If
End Sub

Public Sub WriteBackOperation(cgCompareHelper As cgCompareHelper, iRowPos As Integer)
    Dim cgHelper As cgCompareHelper
    
    On Error Resume Next
    Set cgHelper = m_diffOperations(gdOperations.Array(iRowPos, COL_NAME))
    If Not cgCompareHelper Is Nothing And Not cgHelper Is Nothing Then
        Set cgHelper = cgCompareHelper
        'Set to update and apply if operation editing resulted in a different operation
        If Not cgHelper.OperationsEqual() Then
            If gdOperations.Array(iRowPos, COL_ACTION) = idxAction_None Then
                gdOperations.Array(iRowPos, COL_ACTION) = idxAction_Update
                gdOperations.Array(iRowPos, COL_APPLY) = True
            End If
        End If
    End If
End Sub

