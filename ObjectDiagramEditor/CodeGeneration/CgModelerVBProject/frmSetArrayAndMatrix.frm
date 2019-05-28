VERSION 5.00
Object = "{97BD7A05-77E0-11D2-8EAE-008048E27A77}#1.0#0"; "beegd10.ocx"
Begin VB.Form frmSetArrayAndMatrix 
   Caption         =   "Form1"
   ClientHeight    =   4305
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4485
   Icon            =   "frmSetArrayAndMatrix.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4305
   ScaleWidth      =   4485
   StartUpPosition =   1  'CenterOwner
   Begin VB.TextBox txtDim2 
      Enabled         =   0   'False
      Height          =   315
      Left            =   2460
      TabIndex        =   9
      Top             =   1080
      Width           =   675
   End
   Begin VB.TextBox txtDim1 
      Enabled         =   0   'False
      Height          =   315
      Left            =   1020
      TabIndex        =   8
      Top             =   1080
      Width           =   675
   End
   Begin VB.TextBox txtValueType 
      Enabled         =   0   'False
      Height          =   315
      Left            =   1020
      TabIndex        =   5
      Top             =   600
      Width           =   2115
   End
   Begin VB.TextBox txtAttribute 
      Enabled         =   0   'False
      Height          =   315
      Left            =   1020
      TabIndex        =   3
      Top             =   180
      Width           =   2115
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "OK"
      Height          =   375
      Left            =   3420
      TabIndex        =   2
      Top             =   180
      Width           =   975
   End
   Begin BeeGrid10.SGGrid gdValues 
      Height          =   2655
      Left            =   60
      TabIndex        =   0
      Top             =   1560
      Width           =   4335
      _cx             =   7646
      _cy             =   4683
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
      StylesCollection=   $"frmSetArrayAndMatrix.frx":0442
      ColumnsCollection=   $"frmSetArrayAndMatrix.frx":1ED6
      ValueItems      =   $"frmSetArrayAndMatrix.frx":2CAD
   End
   Begin VB.Label lbSizeY 
      Alignment       =   1  'Right Justify
      Caption         =   "Size Y:"
      Height          =   255
      Left            =   1860
      TabIndex        =   7
      Top             =   1140
      Width           =   495
   End
   Begin VB.Label lbSizeX 
      Alignment       =   1  'Right Justify
      Caption         =   "Size X:"
      Height          =   255
      Left            =   180
      TabIndex        =   6
      Top             =   1140
      Width           =   735
   End
   Begin VB.Label lbValue 
      Alignment       =   1  'Right Justify
      Caption         =   "Value Type:"
      Height          =   255
      Left            =   60
      TabIndex        =   4
      Top             =   600
      Width           =   915
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      Caption         =   "Attribute:"
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   180
      Width           =   735
   End
End
Attribute VB_Name = "frmSetArrayAndMatrix"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private objGD As SGGrid     'The Grid control Array that created this form

Private dim1 As Integer
Private dim2 As Integer

Private iLastRow As Integer
Private iType As Long
Private oCurrentRow

Private Const NAME_COL = 0
Private Const VALUE_COL = 5
Private Const DIMS_COL = 6
Private Const CELL_SEPPARATOR = ";"
Private Const ROW_SEPERATOR = "-"
Private Const SCALAR_HEIGHT = 1750


Private Sub btnOK_Click()
    Dim strData As String
    
    On Error GoTo UnloadForm
    If iType = idxAttr_Scalar Then
        If Not IsNumeric(bArray) Then
            MsgBox "Please enter a valid numeric value."
            Exit Sub
        Else
            oCurrentRow.Cells(VALUE_COL) = txtValueType.Text
            oCurrentRow.Cells(VALUE_COL - 1) = txtValueType.Text
            'objGD.Array(iLastRow, VALUE_COL) = txtValueType.Text
            'objGD.Array(iLastRow, VALUE_COL - 1) = txtValueType.Text
        End If
    Else
        If Not objGD.Array Is Nothing Then
            strData = GetGridData
            oCurrentRow.Cells(VALUE_COL) = strData
            'objGD.Array(iLastRow, VALUE_COL) = strData
        Else
            gMsgWnd.LogMessage "Failed to set Array dimensions."
        End If
    End If
    
UnloadForm:
    Unload Me
End Sub

Public Sub InitScalar(iRow As Integer)
    Dim strAttrib As String
   
    On Error Resume Next
    iLastRow = iRow
    Set oCurrentRow = objGD.CurrentCell.Row
    If objGD.RowCount >= (iRow + 1) Then
        iType = idxAttr_Scalar
        'strAttrib = objGD.Array(iRow, NAME_COL)
        'txtValueType.Text = objGD.Array(iRow, VALUE_COL)
        strAttrib = oCurrentRow.Cells(NAME_COL).Text
        txtValueType.Text = oCurrentRow.Cells(VALUE_COL).Text
        
        Caption = "Scalar Configuration"
        txtAttribute.Text = strAttrib
        txtDim1.Visible = False
        lbSizeX.Visible = False
        txtDim2.Visible = False
        lbSizeY.Visible = False
        txtValueType.Enabled = True
        gdValues.Visible = False
        lbValue.Caption = "Value:"
        Me.Height = SCALAR_HEIGHT
        Me.Refresh
    Else
        gMsgWnd.LogMessage "Failed to initialize Array size configuration dialog."
    End If
End Sub

Public Sub InitArray(iRow As Integer)
    Dim strAttrib As String
    Dim dimArray
 
    On Error Resume Next
    If objGD.RowCount >= (iRow + 1) Then
        iLastRow = iRow
        Set oCurrentRow = objGD.CurrentCell.Row
        'strAttrib = objGD.Array(iRow, NAME_COL)
        'strDims = objGD.Array(iRow, DIMS_COL)
        strAttrib = oCurrentRow.Cells(NAME_COL).Text
        strDims = oCurrentRow.Cells(DIMS_COL).Text
        
        Caption = "Array Configuration"
        txtAttribute.Text = strAttrib
        txtValueType = "Array"
        iType = idxAttr_Array
        dimArray = Split(strDims, DASH_DELIMETER)
        txtDim2.Visible = False
        lbSizeY.Visible = False
        txtDim1 = dimArray(0)
        
        If Int(txtDim1) > -1 Then
            AddGridColumns 1
            If txtDim1 > 0 Then AddGridRows txtDim1
            LoadCurrentData
        End If
    Else
        gMsgWnd.LogMessage "Failed to initialize Array size configuration dialog."
    End If
End Sub

Public Sub InitMatrix(iRow As Integer)
    Dim strAttrib As String
    Dim dimArray
    
    On Error Resume Next
    If objGD.RowCount >= (iRow + 1) Then
        iLastRow = iRow
        Set oCurrentRow = objGD.CurrentCell.Row
        'strAttrib = objGD.Array(iRow, NAME_COL)
        'strDims = objGD.Array(iRow, DIMS_COL)
        strAttrib = oCurrentRow.Cells(NAME_COL).Text
        strDims = oCurrentRow.Cells(DIMS_COL).Text
        
        Caption = "Matrix Configuration"
        txtAttribute.Text = strAttrib
        txtValueType = "Martrix"
        iType = idxAttr_Matrix
        dimArray = Split(strDims, DASH_DELIMETER)
        txtDim1 = dimArray(0)
        txtDim2 = dimArray(1)
        txtDim2.Visible = True
        lbSizeY.Visible = True
        
        If Int(txtDim1) > 0 Then
            AddGridColumns txtDim1
        End If
        If Int(txtDim2) > 0 Then
            AddGridRows txtDim2
        End If
        If Int(txtDim1) > 0 And Int(txtDim2) > 0 Then LoadCurrentData
    Else
        gMsgWnd.LogMessage "Failed to initialize matrix size configuration dialog."
    End If
End Sub

Private Sub AddGridColumns(X As Integer)
    Dim aCol As SGColumn
    Dim ctrl As SGControl
    Dim iWidth, iColWidth As Integer
    Dim i As Integer
    
    On Error GoTo Error_Handler
    gdValues.UserDragging = sgNoRowColDrag
    gdValues.GroupByBoxVisible = False
    gdValues.HeadingTextAlignment = sgAlignCenterCenter
    gdValues.ScrollBars = sgSBAll
    gdValues.Redraw sgRedrawAll
    gdValues.Columns.RemoveAll
    iWidth = gdValues.Width
    For i = 1 To X
        Set aCol = gdValues.Columns.Add(CStr(i))
        aCol.Style.TextAlignment = sgAlignCenterCenter
        iColWidth = (iWidth - 400) / X
        If iColWidth < 250 Then
            aCol.Width = 250
        Else
            aCol.Width = iColWidth
        End If
        Set ctrl = aCol.Control
        ctrl.Type = sgCellTextBox
    Next i
    gdValues.Rows.RemoveAll False
    gdValues.Col = 1
    Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error populating data grid. " & err.Description
End Sub

Private Sub AddGridRows(Y As Integer)
    Dim i As Integer
    
    On Error GoTo Error_Handler
    gdValues.HeadingColCount = 1
    gdValues.RowNumbering = True
    For i = 1 To Y
     gdValues.Rows.Add sgFormatCharSeparatedValue, ""
    Next
    gdValues.Row = 1
    Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Error populating data grid. " & err.Description
End Sub

Private Function GetGridData() As String
    Dim strData As String
    
    On Error Resume Next
    strData = ""
    strData = gdValues.ExportDataString(sgFormatCharSeparatedValue, sgExportDefault, CELL_SEPPARATOR, ROW_SEPERATOR)
    If Not IsEmpty(strData) Then
        GetGridData = strData
    End If
End Function

Private Sub LoadCurrentData()
    Dim strValue, strData As String
    
    On Error Resume Next
    strValue = objGD.Array(iLastRow, VALUE_COL)
    gdValues.ImportDataString strValue, sgFormatCharSeparatedValue, CELL_SEPPARATOR, ROW_SEPERATOR
End Sub

Public Property Set GridArray(ByRef objGrid As Object)
  Set objGD = objGrid
End Property

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Screen.MousePointer = vbArrow
End Sub

Private Sub Form_Resize()
    On Error Resume Next
    If iType <> idxAttr_Scalar Then
        gdValues.Width = Abs(Me.Width - 250)
        gdValues.Height = Abs(Me.Height - 2000)
        btnOK.Left = Abs(Me.Width - 1175)
    End If
End Sub
