VERSION 5.00
Object = "{97BD7A05-77E0-11D2-8EAE-008048E27A77}#1.0#0"; "beegd10.ocx"
Begin VB.Form frmMaskChangeDetails 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Mask Changes"
   ClientHeight    =   4890
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5595
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4890
   ScaleWidth      =   5595
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton btnOK 
      Caption         =   "OK"
      Height          =   375
      Left            =   4500
      TabIndex        =   3
      Top             =   120
      Width           =   975
   End
   Begin VB.CommandButton btnCancel 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4500
      TabIndex        =   2
      Top             =   600
      Width           =   975
   End
   Begin BeeGrid10.SGGrid gdDetails 
      Height          =   4275
      Left            =   180
      TabIndex        =   0
      Top             =   480
      Width           =   4215
      _cx             =   7435
      _cy             =   7541
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
      StylesCollection=   $"frmMaskChangeDetails.frx":0000
      ColumnsCollection=   $"frmMaskChangeDetails.frx":1A94
      ValueItems      =   $"frmMaskChangeDetails.frx":286B
   End
   Begin VB.Label Label1 
      Caption         =   "The following changes will be made:"
      Height          =   315
      Left            =   180
      TabIndex        =   1
      Top             =   120
      Width           =   4155
   End
End
Attribute VB_Name = "frmMaskChangeDetails"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Const idxAction_New = 1
Private Const idxAction_Deleted = 2
Private Const idxAction_Modified = 3

Private Const strAction_New = "New"
Private Const strAction_Deleted = "Deleted"
Private Const strAction_Modified = "Modified"

Private Const COL_CONNAME = 0
Private Const COL_APPLY = 2

Public m_colAppyChange As Collection
Public bCanceled As Boolean
Public bNoChanges As Boolean
Public m_frmParent

Private Sub btnCancel_Click()
    bCanceled = True
    Unload Me
End Sub

Private Sub btnOK_Click()
    Dim iRows As Integer
    Dim i As Integer
    
    On Error GoTo Error_Handler
    iRows = gdDetails.Rows.count
    
    For i = 1 To iRows - 1
        m_colAppyChange.Add gdDetails.Rows.At(i).Cells(COL_APPLY).Value, gdDetails.Rows.At(i).Cells(COL_CONNAME).Value
    Next i
    If m_frmParent Is Nothing Then
        gMsgWnd.LogMessage "Failed to write back selected changes."
    End If
    m_frmParent.SetApplyResult m_colAppyChange
    Unload Me
    Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Failed to write back change selections: " & err.Description
    Unload Me
End Sub

Private Sub Form_Initialize()
    On Error GoTo Error_Handler
    Set m_colAppyChange = Nothing
    Set m_colAppyChange = New Collection
    gdDetails.GroupByBoxVisible = False
    InitGrid
    bCanceled = False
    bNoChanges = True
    Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Failed to initialize Mask Change Details dialog: " & err.Description
    Unload Me
End Sub

Private Sub InitGrid()
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim aCgItem As CgItem
  Dim i As Integer
  
  On Error GoTo Error_Handler
  gdDetails.GroupByBoxVisible = False
  gdDetails.HeadingTextAlignment = sgAlignCenterCenter
  gdDetails.ScrollBars = sgSBAll
  gdDetails.Redraw sgRedrawAll
  gdDetails.Columns.RemoveAll
  
  Set aCol = gdDetails.Columns.Add("Attribute")
  aCol.Width = Abs(gdDetails.Width - 1860)
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
  aCol.ReadOnly = True
  
  Set aCol = gdDetails.Columns.Add("Action")
  aCol.Width = 1000
  Set ctrl = aCol.Control
  ctrl.Type = sgCellDropDown
  Set vis = aCol.ValueItems
  vis.Add idxAction_New, strAction_New
  vis.Add idxAction_Deleted, strAction_Deleted
  vis.Add idxAction_Modified, strAction_Modified
  aCol.DefaultValue = strAction_Modified
  ctrl.PopupRows = 3
  aCol.ReadOnly = True
  Set vis = Nothing
  Set ctrl = Nothing
  
  Set aCol = gdDetails.Columns.Add("Apply")
  aCol.Width = 550
  aCol.Style.TextAlignment = sgAlignCenterCenter
  Set ctrl = aCol.Control
  ctrl.Type = sgCellCheckBox
          
  gdDetails.Rows.RemoveAll False
  Exit Sub
Error_Handler:
  gMsgWnd.LogMessage "Error initializing attribute details. " & err.Description
End Sub

Public Sub AddAddedShape(strShape As String)
    gdDetails.Rows.Add sgFormatCharSeparatedValue, strShape & "," & idxAction_New & ",1", ","
    bNoChanges = False
End Sub

Public Sub AddDeletedShape(strShape As String)
    gdDetails.Rows.Add sgFormatCharSeparatedValue, strShape & "," & idxAction_Deleted & ",1", ","
    bNoChanges = False
End Sub

Public Sub AddModifiedShape(strShape As String)
    gdDetails.Rows.Add sgFormatCharSeparatedValue, strShape & "," & idxAction_Modified & ",1", ","
    bNoChanges = False
End Sub


