VERSION 5.00
Object = "{97BD7A05-77E0-11D2-8EAE-008048E27A77}#1.0#0"; "beegd10.ocx"
Begin VB.UserControl ctlInitialization 
   ClientHeight    =   11745
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   10575
   ScaleHeight     =   11745
   ScaleWidth      =   10575
   Begin OnInitialization.ctlEquationEditor eqnEditor 
      Height          =   6630
      Left            =   720
      TabIndex        =   13
      Top             =   480
      Visible         =   0   'False
      Width           =   9030
      _ExtentX        =   15928
      _ExtentY        =   11695
   End
   Begin OnInitialization.ctlMessageWindow Status 
      Height          =   1335
      Left            =   120
      TabIndex        =   12
      Top             =   10320
      Width           =   10335
      _ExtentX        =   18230
      _ExtentY        =   2355
   End
   Begin VB.Frame frmInitEqns 
      Caption         =   "Initialization Equations"
      Height          =   3375
      Left            =   120
      TabIndex        =   1
      Top             =   6840
      Width           =   10335
      Begin VB.CommandButton btnInitEqns 
         Caption         =   "Init Eqns"
         Height          =   375
         Left            =   120
         TabIndex        =   7
         Top             =   2880
         Width           =   1335
      End
      Begin VB.CommandButton btnHelp 
         Height          =   550
         Left            =   9750
         Picture         =   "ctlInitialization.ctx":0000
         Style           =   1  'Graphical
         TabIndex        =   8
         Top             =   2790
         Width           =   550
      End
      Begin BeeGrid10.SGGrid grdInitEqns 
         Height          =   2535
         Left            =   120
         TabIndex        =   6
         Top             =   240
         Width           =   10095
         _cx             =   17806
         _cy             =   4471
         DataMode        =   1
         AutoFields      =   -1  'True
         Enabled         =   -1  'True
         GridBorderStyle =   1
         ScrollBars      =   3
         FlatScrollBars  =   0
         ScrollBarTrack  =   0   'False
         DataRowCount    =   0
         BeginProperty HeadingFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         DataColCount    =   5
         HeadingRowCount =   1
         HeadingColCount =   1
         TextAlignment   =   0
         WordWrap        =   -1  'True
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
         MultiSelect     =   2
         AllowAddNew     =   -1  'True
         AllowDelete     =   -1  'True
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
         MaxColumns      =   10
         NewRowPos       =   1
         CustomBkgDraw   =   0
         AutoGroup       =   -1  'True
         GroupByBoxVisible=   -1  'True
         GroupByBoxText  =   "Drag a column header here to group by that column"
         AlphaBlendEnabled=   0   'False
         DragAlphaLevel  =   206
         AutoSearch      =   0
         AutoSearchDelay =   2000
         StylesCollection=   $"ctlInitialization.ctx":0442
         ColumnsCollection=   $"ctlInitialization.ctx":1ED7
         ValueItems      =   $"ctlInitialization.ctx":3A34
      End
   End
   Begin VB.Frame frmModelVars 
      Caption         =   "Model Variables"
      Height          =   3255
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   10335
      Begin VB.OptionButton chkVar 
         Caption         =   "Show Active"
         Height          =   375
         Index           =   1
         Left            =   9000
         TabIndex        =   5
         Top             =   2840
         Value           =   -1  'True
         Width           =   1215
      End
      Begin VB.OptionButton chkVar 
         Caption         =   "Show All"
         Height          =   375
         Index           =   0
         Left            =   7800
         TabIndex        =   4
         Top             =   2840
         Width           =   1095
      End
      Begin BeeGrid10.SGGrid grdModelVars 
         Height          =   2535
         Left            =   120
         TabIndex        =   3
         Top             =   240
         Width           =   10095
         _cx             =   17806
         _cy             =   4471
         DataMode        =   1
         AutoFields      =   -1  'True
         Enabled         =   -1  'True
         GridBorderStyle =   1
         ScrollBars      =   3
         FlatScrollBars  =   0
         ScrollBarTrack  =   0   'False
         DataRowCount    =   0
         BeginProperty HeadingFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         DataColCount    =   6
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
         SelectionMode   =   5
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
         StylesCollection=   $"ctlInitialization.ctx":3E84
         ColumnsCollection=   $"ctlInitialization.ctx":5918
         ValueItems      =   $"ctlInitialization.ctx":790E
      End
   End
   Begin VB.Frame frmModelEqns 
      Caption         =   "Model Equations"
      Height          =   3255
      Left            =   120
      TabIndex        =   2
      Top             =   3480
      Width           =   10335
      Begin VB.OptionButton chkEqn 
         Caption         =   "Show Active"
         Height          =   375
         Index           =   1
         Left            =   9000
         TabIndex        =   11
         Top             =   2840
         Value           =   -1  'True
         Width           =   1215
      End
      Begin VB.OptionButton chkEqn 
         Caption         =   "Show All"
         Height          =   375
         Index           =   0
         Left            =   7800
         TabIndex        =   10
         Top             =   2840
         Width           =   1095
      End
      Begin BeeGrid10.SGGrid grdModelEqns 
         Height          =   2535
         Left            =   120
         TabIndex        =   9
         Top             =   240
         Width           =   10095
         _cx             =   17806
         _cy             =   4471
         DataMode        =   1
         AutoFields      =   -1  'True
         Enabled         =   -1  'True
         GridBorderStyle =   1
         ScrollBars      =   3
         FlatScrollBars  =   0
         ScrollBarTrack  =   0   'False
         DataRowCount    =   0
         BeginProperty HeadingFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         DataColCount    =   5
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
         SelectionMode   =   5
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
         StylesCollection=   $"ctlInitialization.ctx":7CF3
         ColumnsCollection=   $"ctlInitialization.ctx":9787
         ValueItems      =   $"ctlInitialization.ctx":B2E4
      End
   End
End
Attribute VB_Name = "ctlInitialization"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Const SHOW_ALL As Long = 0
Const SHOW_OPEN As Long = 1

Private Enum eqnCols
  eqnColIndex = 0
  eqnColAsVar = 1
  eqnColName = 2
  eqnColVars = 3
  eqnColRes = 4
  eqnColBodyIdx = 5
End Enum

Private Enum varCols
  varColIndex = 0
  varColAsEqn = 1
  varColName = 2
  varColDer = 3
  varColVal = 4
  varColSet = 5
End Enum

Private m_LastBodyIdx As Long
Private WithEvents m_EqnEditor As ctlEquationEditor
Attribute m_EqnEditor.VB_VarHelpID = -1
Private m_Status As ctlMessageWindow
Private m_sp As OnScriptParser

Private Const Delim As String * 1 = "#"
Private m_EqnBodies() As String
Private m_EqnVarCount() As Long

Public Sub init(sp As OnScriptParser, vm As clsVarManager)
  Set m_sp = sp
  m_EqnEditor.init sp, vm, m_Status
  initModelVars
  initModelEqns
  initScripts
End Sub

Public Sub Destroy()
  m_EqnEditor.Destroy
  Set m_EqnEditor = Nothing
  m_Status.Destroy
  Set m_Status = Nothing
  Set m_sp = Nothing
End Sub

Private Sub initScripts()
  Dim i As Long
  Dim nScripts As Long
  
  ReDim AssignedVars(0) As String
  ReDim ScriptNames(0) As String
  ReDim ScriptVars(0) As String
  ReDim ScriptResiduals(0) As Double
  
  m_sp.GetScripts nScripts, AssignedVars(), ScriptNames(), ScriptVars(), ScriptResiduals(), m_EqnBodies(), m_EqnVarCount()
  For i = 0 To nScripts - 1
    Call grdInitEqns.Rows.Add(sgFormatCharSeparatedValue, _
      i + 1 & _
      AssignedVars(i) & _
      ScriptNames(i) & _
      ScriptVars(i) & _
      ScriptResiduals(i) & _
      i, _
      Delim)
  Next i
  
  If nScripts > 0 Then
    m_LastBodyIdx = nScripts - 1
  Else
    m_LastBodyIdx = 0
  End If
End Sub

Public Sub OnApply()
  saveScripts
  saveTrimVars
End Sub

Private Sub saveScripts()
  Dim i As Long
  Dim nScripts As Long
  Dim BodyIdx As Long
  
  nScripts = grdInitEqns.Array.RowCount
  If nScripts = 0 Then Exit Sub
  
  ReDim AssignedVars(nScripts) As String
  ReDim ScriptNames(nScripts) As String
  ReDim ScriptVars(nScripts) As String
  ReDim ScriptResiduals(nScripts) As Double
  ReDim ScriptBodies(nScripts) As String
  ReDim ScriptVarCount(nScripts) As Long
  
  For i = 0 To nScripts - 1
    AssignedVars(i) = grdInitEqns.Array(i, eqnColAsVar)
    ScriptNames(i) = grdInitEqns.Array(i, eqnColName)
    ScriptVars(i) = grdInitEqns.Array(i, eqnColVars)
    ScriptResiduals(i) = grdInitEqns.Array(i, eqnColRes)
    BodyIdx = grdInitEqns.Array(i, eqnColBodyIdx)
    ScriptBodies(i) = m_EqnBodies(BodyIdx)
    ScriptVarCount(i) = m_EqnVarCount(BodyIdx)
  Next i

  m_sp.SetScripts nScripts, AssignedVars(), ScriptNames(), ScriptVars(), ScriptResiduals(), ScriptBodies(), ScriptVarCount()

End Sub

Private Sub saveTrimVars()
  Dim iRow As Long
  Dim nTrimVars As Long
  ReDim TrimVars(100) As Long
  ReDim TrimVarVals(100) As Double
  
  For iRow = 0 To grdModelVars.Array.RowCount - 1
    If grdModelVars.Array(iRow, varColSet) Then
      If nTrimVars = UBound(TrimVars) Then
        ReDim Preserve TrimVars(nTrimVars * 2) As Long
        ReDim Preserve TrimVarVals(nTrimVars * 2) As Double
      End If
      
      If chkVar(SHOW_ALL) Then
        TrimVars(nTrimVars) = iRow
      Else
        TrimVars(nTrimVars) = m_sp.VarOrder(iRow)
      End If
      
      TrimVarVals(nTrimVars) = grdModelVars.Array(iRow, varColVal)
      
      nTrimVars = nTrimVars + 1
    End If
  Next iRow
  
  If nTrimVars > 0 Then
    m_sp.SetTrimVars nTrimVars, TrimVars(), TrimVarVals()
  End If
End Sub

'***************************************************************************************
'
'   Begin: Equation editor event handlers
'
'***************************************************************************************
'
Private Sub m_EqnEditor_OnCancel()
  eqnEditor.Visible = False
End Sub

Private Sub m_EqnEditor_OnApply(GridIndex As Long, EqnIndex As Long, sScript As String)
  Dim result As Double
  Dim vars As String
  Dim varCount As Long
  
  Call reportEqnVars(sScript, result, vars, varCount)
  m_EqnBodies(EqnIndex) = sScript
  m_EqnVarCount(EqnIndex) = varCount
  grdInitEqns.Array(GridIndex, eqnColVars) = vars
  grdInitEqns.Array(GridIndex, eqnColRes) = result
  grdInitEqns.RedrawRow GridIndex + 1
  eqnEditor.Visible = False

End Sub

'
'***************************************************************************************
'
'   End: Equation editor event handlers
'
'***************************************************************************************


Private Sub initModelVars()
  ' iEqn = assignedEqn[iVar]
  ' iVar = assignedVar[iEqn]
  
  Dim iEqn As Long
  Dim iVar As Long
  Dim iRootVar As Long
  
  ' fields
  ' Index, AssignedEqn, Name, DER, Value
  Dim nVars As Long
  Dim aIndex As Long
  Dim aAssignedEqn As String
  Dim aName As String
  Dim aDER As Long
  Dim aValue As Double
  Dim i As Long
  Dim iRow As Long
  
  On Error GoTo error_handler
  
  grdModelVars.Rows.removeAll False
  
  Dim nTrimVars As Long
  ReDim TrimVars(0) As Long
  ReDim TrimVarVals(0) As Double
  
  m_sp.GetTrimVars nTrimVars, TrimVars(), TrimVarVals()
  
  If chkVar(SHOW_ALL).Value Then
    nVars = m_sp.nVars
    For iVar = 0 To nVars - 1
      m_sp.initModelVar iVar, False, aIndex, aAssignedEqn, aName, aDER, aValue
      grdModelVars.Rows.Add sgFormatCharSeparatedValue, _
        aIndex & Delim & aAssignedEqn & Delim & aName & Delim & aDER & Delim & aValue, Delim
    Next iVar
  Else
    nVars = m_sp.nActiveVars
    For iVar = 0 To nVars - 1
      m_sp.initModelVar iVar, True, aIndex, aAssignedEqn, aName, aDER, aValue
      grdModelVars.Rows.Add sgFormatCharSeparatedValue, _
        aIndex & Delim & aAssignedEqn & Delim & aName & Delim & aDER & Delim & aValue, Delim
    Next iVar
  End If
  
  For i = 0 To nTrimVars - 1
    If chkVar(SHOW_ALL).Value Then
      iRow = TrimVars(i)
    Else
      iRow = m_sp.itVarOrder(TrimVars(i))
    End If
    If iRow >= 0 Then
      grdModelVars.Array(iRow, varColSet) = True
      grdModelVars.Array(iRow, varColVal) = TrimVarVals(i)
    End If
  Next i
  
  Exit Sub
error_handler:
  MsgBox "Initialize model variables error: " & Err.Description, vbInformation
  Resume Next
End Sub
  
Private Sub initModelEqns()
  
  Dim iEqn As Long
  
  ' fields
  ' Index, AssignedVar, Name, Vars, Residual
  Dim nEqns As Long
  Dim aIndex As Long
  Dim aAssignedVar As String
  Dim aName As String
  Dim aVars As String
  Dim aResidual As Double
  
  On Error GoTo error_handler
  
  grdModelEqns.Rows.removeAll False
  
  If chkEqn(SHOW_ALL).Value Then
    nEqns = m_sp.nEqns
    For iEqn = 0 To nEqns - 1
      m_sp.initModelEqn iEqn, False, aIndex, aAssignedVar, aName, aVars, aResidual
      grdModelEqns.Rows.Add sgFormatCharSeparatedValue, _
        aIndex & Delim & aAssignedVar & Delim & aName & Delim & aVars & Delim & aResidual, Delim
    Next iEqn
  Else
    nEqns = m_sp.nActiveEqns
    For iEqn = 0 To nEqns - 1
      m_sp.initModelEqn iEqn, True, aIndex, aAssignedVar, aName, aVars, aResidual
      grdModelEqns.Rows.Add sgFormatCharSeparatedValue, _
        aIndex & Delim & aAssignedVar & Delim & aName & Delim & aVars & Delim & aResidual, Delim
    Next iEqn
  End If
  
  Exit Sub
error_handler:
  MsgBox "Initialize model equations error: " & Err.Description, vbInformation
  Resume Next
End Sub

Private Sub btnHelp_Click()
  Dim szMsg As String
  
  szMsg = "Initialization equations are parsed via the VBScript engine.  Equations may reference any variable in the problem per the following syntax:" & vbCrLf & vbCrLf & _
          "  VarName or SubModelName(""VarName"") or SubModelName(""SubSubModelName"")(""VarName"")" & vbCrLf & vbCrLf & _
          "to any depth in the model hierarchy." & vbCrLf & vbCrLf & _
          "Variables can be selected and inserted into equations (automatically formated for VBScript) by pressing the <Insert Variable> button.  " & vbCrLf & vbCrLf & _
          "Equations can be a single expression or a multi-line sub-program.  All equations must be expressed in implicit constraint format, where the result is returned via the reserved variable 'res'.  Refer to the following examples:  " & vbCrLf & vbCrLf & _
          "  (1) res = Force - Mass * Acceleration" & vbCrLf & vbCrLf & _
          "  (2) local_force = Mass * Acceleration" & vbCrLf & _
          "      res = Force - local_force" & vbCrLf & vbCrLf & _
          "  (3) redim local_forces(2) as double" & vbCrLf & _
          "      local_forces(0) = Force" & vbCrLf & _
          "      local_forces(1) = Mass * Acceleration" & vbCrLf & _
          "      res = local_forces(0) - local_forces(1)"
  MsgBox szMsg, vbOKOnly, "Initialation Equations Overview"
End Sub

Private Sub grdInitEqns_AfterDelete()
  Dim iRow As Long
  Dim Count As Long
  
  Count = grdInitEqns.Array.RowCount
  For iRow = 0 To Count - 1
    grdInitEqns.Array(iRow, eqnColIndex) = iRow + 1
  Next iRow

End Sub

Private Sub grdInitEqns_AfterInsert()
  Dim iRow As Long
  Dim Count As Long
  
  Count = grdInitEqns.Array.RowCount
  grdInitEqns.Array(Count - 1, eqnColBodyIdx) = m_LastBodyIdx
  m_LastBodyIdx = m_LastBodyIdx + 1
  For iRow = 0 To Count - 1
    grdInitEqns.Array(iRow, eqnColIndex) = iRow + 1
  Next iRow
  If UBound(m_EqnBodies) < m_LastBodyIdx Then
    ReDim Preserve m_EqnBodies(m_LastBodyIdx + 20) As String
  End If
End Sub

Private Sub grdInitEqns_ButtonClick(ByVal RowKey As Long, ByVal ColIndex As Long, Cancel As Boolean)
  Dim GridIndex As Long
  Dim EqnIndex As Long
  Dim eqnName As String
  Dim szData As String
  Dim varData As Variant
  Dim vecData() As String
  
  On Error GoTo error_handler
  szData = grdInitEqns.Rows.Current.GetData(sgFormatCharSeparatedValue, Delim)
  varData = Split(szData, Delim)
  vecData = varData
  GridIndex = VAL(vecData(eqnColIndex)) - 1
  EqnIndex = grdInitEqns.Array(GridIndex, eqnColBodyIdx)
  eqnName = grdInitEqns.Array(GridIndex, eqnColName)
  m_EqnEditor.GridIndex = GridIndex
  m_EqnEditor.EqnIndex = EqnIndex
  m_EqnEditor.eqnName = eqnName
  m_EqnEditor.EqnBody = m_EqnBodies(EqnIndex)
  
  eqnEditor.Visible = True
  eqnEditor.SetFocus
  
  Exit Sub
error_handler:
  
End Sub

Private Sub reportEqnVars(script As String, result As Double, vars As String, varCount As Long)
  Dim aV As clsVar
  Dim v As Collection
  Dim dv1 As Collection
  Dim dv2 As Collection
  Dim dv3  As Collection
  
  m_sp.GetEqnStruct script, v, dv1, dv2, dv3, result
  
  vars = ""
  varCount = 0
  For Each aV In v
    vars = IIf(varCount > 0, vars & ", ", "") & aV.longName
    varCount = varCount + 1
  Next
  
  For Each aV In dv1
    vars = IIf(varCount > 0, vars & ", ", "") & aV.longName & ".der(1)"
    varCount = varCount + 1
  Next
  
  For Each aV In dv2
    vars = IIf(varCount > 0, vars & ", ", "") & aV.longName & ".der(2)"
    varCount = varCount + 1
  Next
  
  For Each aV In dv3
    vars = IIf(varCount > 0, vars & ", ", "") & aV.longName & ".der(3)"
    varCount = varCount + 1
  Next
  
End Sub

Private Sub UserControl_Initialize()
  Dim i As Long
  ReDim vars(100) As clsVar
  
  ReDim m_EqnBodies(20) As String
  
  ' display a button on the Variables column of the initialization equation grid
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  
  Set aCol = grdInitEqns.Columns.Add("BodyIdx")
  aCol.DataType = sgtLong
  aCol.Hidden = True
  
  Set aCol = grdInitEqns.Columns.Add(" ")
  aCol.Width = 260
  aCol.Style.Borders = sgCellBorderTop + sgCellBorderBottom
  aCol.AllowSizing = False
  Set ctrl = aCol.Control
  ctrl.ShowButton = sgShowButtonAlways
  ctrl.ButtonAlignment = sgButtonLeft
  
  Set m_Status = Status.object
  Set m_Status.ActiveForm = Me
  
  ' initialize the equation editor
  Set m_EqnEditor = eqnEditor.object
 
End Sub

Private Sub UserControl_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
  Screen.MousePointer = vbArrow
End Sub

Public Function IsMsgWindowVisible() As Boolean
  IsMsgWindowVisible = Status.Visible
End Function

Public Sub ShowMessageWindow()
  Status.Visible = True
End Sub

Public Sub SizeStatusBar(Y As Long)
  Status.Move Status.Left, UserControl.Height - Y, UserControl.Width, Y
End Sub
