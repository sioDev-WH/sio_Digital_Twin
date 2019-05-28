VERSION 5.00
Object = "{C5DE3F80-3376-11D2-BAA4-04F205C10000}#1.0#0"; "vsflex6d.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Object = "{5C607640-780C-11CF-92BA-444553540000}#1.0#0"; "GeCtl.ocx"
Begin VB.Form frmGELibraryManager 
   Caption         =   "Library Manager - Differences"
   ClientHeight    =   7605
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   11220
   Icon            =   "frmGELibraryManager.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MinButton       =   0   'False
   ScaleHeight     =   7605
   ScaleWidth      =   11220
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton btnClose 
      Caption         =   "Close"
      Height          =   330
      Left            =   10035
      TabIndex        =   21
      Top             =   30
      Width           =   1140
   End
   Begin VB.CommandButton btnUpdateDiffs 
      Caption         =   "Update Differences !"
      Enabled         =   0   'False
      Height          =   315
      Left            =   5250
      TabIndex        =   9
      ToolTipText     =   "Update destination with selected source shapes."
      Top             =   30
      Width           =   1905
   End
   Begin VB.PictureBox picFGs 
      Height          =   3705
      Left            =   60
      ScaleHeight     =   3645
      ScaleWidth      =   10815
      TabIndex        =   8
      Top             =   390
      Width           =   10875
      Begin VB.PictureBox picFGRT 
         Height          =   600
         Left            =   5820
         ScaleHeight     =   540
         ScaleWidth      =   4710
         TabIndex        =   18
         Top             =   30
         Width           =   4770
         Begin VB.Label lblLibDST 
            AutoSize        =   -1  'True
            Caption         =   "Destination Library"
            Height          =   195
            Left            =   60
            TabIndex        =   23
            Top             =   240
            Width           =   1305
         End
         Begin VB.Label Label4 
            Alignment       =   2  'Center
            AutoSize        =   -1  'True
            Caption         =   "Destination Library"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   700
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   195
            Left            =   1410
            TabIndex        =   20
            Top             =   30
            Width           =   1635
         End
      End
      Begin VB.PictureBox picFGLT 
         Height          =   600
         Left            =   15
         ScaleHeight     =   540
         ScaleWidth      =   4515
         TabIndex        =   17
         Top             =   30
         Width           =   4575
         Begin VB.Label lblLibSRC 
            AutoSize        =   -1  'True
            Caption         =   "Source Library"
            Height          =   195
            Left            =   60
            TabIndex        =   22
            Top             =   240
            Width           =   1035
         End
         Begin VB.Label Label3 
            Alignment       =   2  'Center
            AutoSize        =   -1  'True
            Caption         =   "Source Library"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   700
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   195
            Left            =   1560
            TabIndex        =   19
            Top             =   0
            Width           =   1275
         End
      End
      Begin VB.PictureBox picFGR 
         Height          =   2055
         Left            =   5880
         ScaleHeight     =   1995
         ScaleWidth      =   4485
         TabIndex        =   12
         Top             =   930
         Width           =   4545
         Begin VSFlex6DAOCtl.vsFlexGrid FGDst 
            Height          =   1500
            Left            =   15
            TabIndex        =   13
            Top             =   390
            Width           =   4335
            _ExtentX        =   7646
            _ExtentY        =   2646
            _ConvInfo       =   1
            Appearance      =   1
            BorderStyle     =   1
            Enabled         =   -1  'True
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            MousePointer    =   0
            BackColor       =   -2147483643
            ForeColor       =   -2147483640
            BackColorFixed  =   -2147483633
            ForeColorFixed  =   -2147483630
            BackColorSel    =   -2147483646
            ForeColorSel    =   -2147483639
            BackColorBkg    =   -2147483636
            BackColorAlternate=   -2147483643
            GridColor       =   -2147483633
            GridColorFixed  =   -2147483632
            TreeColor       =   -2147483632
            FloodColor      =   192
            SheetBorder     =   -2147483642
            FocusRect       =   1
            HighLight       =   1
            AllowSelection  =   -1  'True
            AllowBigSelection=   -1  'True
            AllowUserResizing=   1
            SelectionMode   =   0
            GridLines       =   2
            GridLinesFixed  =   2
            GridLineWidth   =   1
            Rows            =   2
            Cols            =   3
            FixedRows       =   1
            FixedCols       =   0
            RowHeightMin    =   0
            RowHeightMax    =   0
            ColWidthMin     =   0
            ColWidthMax     =   0
            ExtendLastCol   =   -1  'True
            FormatString    =   ""
            ScrollTrack     =   0   'False
            ScrollBars      =   3
            ScrollTips      =   0   'False
            MergeCells      =   0
            MergeCompare    =   0
            AutoResize      =   -1  'True
            AutoSizeMode    =   0
            AutoSearch      =   1
            MultiTotals     =   -1  'True
            SubtotalPosition=   1
            OutlineBar      =   0
            OutlineCol      =   0
            Ellipsis        =   0
            ExplorerBar     =   1
            PicturesOver    =   0   'False
            FillStyle       =   0
            RightToLeft     =   0   'False
            PictureType     =   0
            TabBehavior     =   0
            OwnerDraw       =   0
            Editable        =   -1  'True
            ShowComboButton =   -1  'True
            WordWrap        =   0   'False
            TextStyle       =   0
            TextStyleFixed  =   0
            OleDragMode     =   0
            OleDropMode     =   0
            DataMode        =   0
            VirtualData     =   -1  'True
         End
         Begin VB.Label lblDstCount 
            Caption         =   "0 Selected"
            Height          =   210
            Left            =   2250
            TabIndex        =   14
            Top             =   0
            Width           =   1515
         End
      End
      Begin VB.PictureBox picFGL 
         Height          =   1965
         Left            =   240
         ScaleHeight     =   1905
         ScaleWidth      =   4065
         TabIndex        =   11
         Top             =   930
         Width           =   4125
         Begin VSFlex6DAOCtl.vsFlexGrid FGSrc 
            Height          =   1500
            Left            =   0
            TabIndex        =   15
            Top             =   300
            Width           =   4545
            _ExtentX        =   8017
            _ExtentY        =   2646
            _ConvInfo       =   1
            Appearance      =   1
            BorderStyle     =   1
            Enabled         =   -1  'True
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            MousePointer    =   0
            BackColor       =   -2147483643
            ForeColor       =   -2147483640
            BackColorFixed  =   -2147483633
            ForeColorFixed  =   -2147483630
            BackColorSel    =   -2147483646
            ForeColorSel    =   -2147483634
            BackColorBkg    =   -2147483636
            BackColorAlternate=   -2147483643
            GridColor       =   -2147483633
            GridColorFixed  =   -2147483632
            TreeColor       =   -2147483632
            FloodColor      =   192
            SheetBorder     =   -2147483642
            FocusRect       =   1
            HighLight       =   1
            AllowSelection  =   -1  'True
            AllowBigSelection=   -1  'True
            AllowUserResizing=   1
            SelectionMode   =   0
            GridLines       =   2
            GridLinesFixed  =   2
            GridLineWidth   =   1
            Rows            =   2
            Cols            =   3
            FixedRows       =   1
            FixedCols       =   0
            RowHeightMin    =   0
            RowHeightMax    =   0
            ColWidthMin     =   0
            ColWidthMax     =   0
            ExtendLastCol   =   -1  'True
            FormatString    =   ""
            ScrollTrack     =   0   'False
            ScrollBars      =   3
            ScrollTips      =   0   'False
            MergeCells      =   0
            MergeCompare    =   0
            AutoResize      =   -1  'True
            AutoSizeMode    =   0
            AutoSearch      =   0
            MultiTotals     =   -1  'True
            SubtotalPosition=   1
            OutlineBar      =   0
            OutlineCol      =   0
            Ellipsis        =   0
            ExplorerBar     =   1
            PicturesOver    =   0   'False
            FillStyle       =   0
            RightToLeft     =   0   'False
            PictureType     =   0
            TabBehavior     =   0
            OwnerDraw       =   0
            Editable        =   -1  'True
            ShowComboButton =   -1  'True
            WordWrap        =   0   'False
            TextStyle       =   0
            TextStyleFixed  =   0
            OleDragMode     =   0
            OleDropMode     =   0
            DataMode        =   0
            VirtualData     =   -1  'True
         End
         Begin VB.Label lblSrcCount 
            Caption         =   "0 Selected"
            Height          =   210
            Left            =   2250
            TabIndex        =   16
            Top             =   0
            Width           =   1515
         End
      End
      Begin VB.PictureBox picMiddle 
         BackColor       =   &H80000010&
         Height          =   2775
         Left            =   5115
         ScaleHeight     =   2715
         ScaleWidth      =   45
         TabIndex        =   10
         Top             =   120
         Width           =   100
      End
   End
   Begin VB.PictureBox picPreview 
      Height          =   2085
      Left            =   30
      ScaleHeight     =   2025
      ScaleWidth      =   9405
      TabIndex        =   3
      Top             =   5265
      Width           =   9465
      Begin GeCtlLib.Ge GeSRC 
         Height          =   1710
         Left            =   1980
         TabIndex        =   4
         Top             =   270
         Width           =   2955
         _Version        =   65536
         _ExtentX        =   5212
         _ExtentY        =   3016
         _StockProps     =   64
      End
      Begin GeCtlLib.Ge GeDST 
         Height          =   1710
         Left            =   6180
         TabIndex        =   5
         Top             =   270
         Width           =   2955
         _Version        =   65536
         _ExtentX        =   5212
         _ExtentY        =   3016
         _StockProps     =   64
      End
      Begin VB.Label lblPreviewSRC 
         Alignment       =   2  'Center
         Caption         =   "Preview - Source"
         Height          =   195
         Left            =   1980
         TabIndex        =   7
         Top             =   15
         Width           =   3015
      End
      Begin VB.Label lblPreviewDST 
         Alignment       =   2  'Center
         Caption         =   "Preview - Destination"
         Height          =   195
         Left            =   6180
         TabIndex        =   6
         Top             =   15
         Width           =   3015
      End
   End
   Begin VB.CommandButton btnShapeDiff 
      Caption         =   "View Differences"
      Height          =   315
      Left            =   3270
      TabIndex        =   2
      ToolTipText     =   "Show differences only between source and destination."
      Top             =   30
      Width           =   1905
   End
   Begin VB.CommandButton btnAllShapeDST 
      Caption         =   "Update All Shapes -->"
      Height          =   315
      Left            =   1170
      TabIndex        =   1
      ToolTipText     =   "Update ALL Shapes in Destination to match those in Source. New shapes may be added. Versions are checked."
      Top             =   0
      Visible         =   0   'False
      Width           =   1065
   End
   Begin VB.CommandButton btnVerDST 
      Caption         =   "Update Library Structure -->"
      Height          =   330
      Left            =   30
      TabIndex        =   0
      ToolTipText     =   "Update Library structure so that DST matches SRC."
      Top             =   0
      Visible         =   0   'False
      Width           =   1125
   End
   Begin MSComDlg.CommonDialog CommonDlg 
      Left            =   10725
      Top             =   330
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      FontSize        =   2.54052e-29
   End
End
Attribute VB_Name = "frmGELibraryManager"
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
'
Private m_LbrMgrSRC As GeLibraryMgr
Private m_LbrMgrDST As GeLibraryMgr
Private m_bChangingSrc As Boolean
Private m_bChangingDst As Boolean

Private m_bConstructingFGSRC As Boolean
Private m_bFirstSRC As Boolean
Private m_bConstructingFGDST As Boolean
Private m_bFirstDST As Boolean

Private m_bShowingDiffs As Boolean  ' managing differences
Private m_strCurDir As String

Private Const c_CellBGClrDisabled = &H8000000F ' disabled cell background color

' Calling form's code
'------------------------------
'Private Sub btnDiff_Click()
'  ' differences between libraries
'  Dim strName As String
'  Dim frm As frmGELibraryManager
'
'  On Error Resume Next
'  BeginWaitCursor
'  Set frm = New frmGELibraryManager
'
'  BeginWaitCursor
'  strName = m_strLibrarySRC
'  frm.AddLibrarySRC strName
'
'  strName = cbLibraries.Text
'  frm.AddLibraryDST strName
'
'  frm.ShowDifferences
'
'  frm.Show vbModal
'  Set frm = Nothing
'
'End Sub

'
'======================================================================================
' End Declarations
'======================================================================================
'---------------------------
Private Sub EnableCommonOps(bEnable As Boolean)
  btnVerDST.Enabled = bEnable
  btnAllShapeDST.Enabled = bEnable
End Sub
'---------------------------
Private Sub EnableOperations(bEnable As Boolean)
  btnShapeDiff.Enabled = bEnable
  EnableCommonOps bEnable
End Sub

'---------------------------
Private Sub UpdateEnableOperations()
  Dim strLibSrc As String, strLibDst As String
  Dim bEnable As Boolean
  
  bEnable = False
  If GetSelLib(lblLibSRC, strLibSrc) Then
    If GetSelLib(lblLibDST, strLibDst) Then
      ' names not the same
      If UCase(strLibSrc) <> UCase(strLibDst) Then
        bEnable = True
      End If
    End If
  End If
  '
  EnableOperations bEnable

End Sub


'=============================================================
' Source
'=============================================================
'---------------------------
Public Sub AddLibrarySRC(strName As String)
  ' see if already in list
  lblLibSRC.Caption = strName
  ShowLibToView_SRC strName
End Sub

'---------------------------
Private Sub ShowLibToView_SRC(strName As String)
  On Error Resume Next
  
  BeginWaitCursor
  m_bChangingSrc = True
  OpenLibSRC strName
  UpdateEnableOperations
  
  UpdateStatsSRC
  
  m_bChangingSrc = False
  EndWaitCursor
  
End Sub
'---------------------------
Private Function OpenLibSRC(strName As String) As Boolean
  Dim bRet As Boolean
  On Error Resume Next
  FGSrc.Clear
  ClearGe GeSRC
  m_LbrMgrSRC.CloseLibrary
  
  If Len(strName) = 0 Then Exit Function
  
  bRet = m_LbrMgrSRC.OpenLibrary(strName, False)   ' bReadOnly
  If bRet Then PopulateFolders FGSrc, m_LbrMgrSRC, False
  OpenLibSRC = bRet
End Function



'---------------------------
Private Sub btnClose_Click()
  Unload Me
End Sub

'---------------------------
Private Sub FGSrc_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
  UpdateStatsSRC
End Sub
'---------------------------
Private Sub FGSrc_RowColChange()
  Dim strLib As String, strFolder As String, strName As String
  
  If m_bChangingSrc Then Exit Sub
  If FGSrc.Row = 0 Then Exit Sub
  
  m_bChangingSrc = True
  With FGSrc
    If m_bShowingDiffs Then
      ShowShapeDiffsToView
    Else
      If GetFolderAndShape(FGSrc, strFolder, strName) Then
        If GetSelLib(lblLibSRC, strLib) Then ShowShapeToView GeSRC, strLib, strFolder, strName
      End If
    End If
    '
  End With
  m_bChangingSrc = False
End Sub

'=============================================================
' Destination
'=============================================================
'---------------------------
Private Sub btnAllShapeDST_Click()
  ' update All Dst Shapes by version
  ' assume that SRC lib is the master
  Dim strNameSRC As String, strNameDST As String
  Dim bRet As Boolean
  Dim bModified As Boolean
  
  On Error Resume Next
  If GetSelLib(lblLibDST, strNameDST) Then
    If GetSelLib(lblLibSRC, strNameSRC) Then
      If UCase(strNameSRC) = UCase(strNameDST) Then Exit Sub  ' same libs. Can't do
      
      bRet = m_LbrMgrDST.VerifyUpdateAllShapes(strNameSRC, Nothing, bModified)
        ' refresh DST list is req'd
      If bModified Then ShowLibToView_DST strNameDST
    End If
  End If

End Sub

'---------------------------
Private Sub btnVerDST_Click()
  ' update version
  ' assume that SRC lib is the master
  Dim strNameSRC As String, strNameDST As String
  Dim bRet As Boolean
  
  On Error Resume Next
  If GetSelLib(lblLibDST, strNameDST) Then
    If GetSelLib(lblLibSRC, strNameSRC) Then
      If UCase(strNameSRC) = UCase(strNameDST) Then Exit Sub  ' same libs. Can't do
      
      m_LbrMgrSRC.CloseLibrary
      bRet = m_LbrMgrDST.VerifyUpdateProjDBRevision(strNameSRC, Nothing)
        ' reopen SRC
      bRet = m_LbrMgrSRC.OpenLibrary(strNameSRC, False)   ' bReadOnly
        ' refresh DST list is req'd
      ShowLibToView_DST strNameDST
    End If
  End If
End Sub

'---------------------------
Public Sub AddLibraryDST(strName As String)
  lblLibDST.Caption = strName
  ShowLibToView_DST strName
End Sub

'---------------------------
Private Sub ShowLibToView_DST(strName As String)
  On Error Resume Next
  BeginWaitCursor
  m_bChangingDst = True
  If GetSelLib(lblLibDST, strName) Then OpenLibDST strName
  UpdateEnableOperations
  UpdateStatsDST
  m_bChangingDst = False
  EndWaitCursor
End Sub
'---------------------------
Private Function OpenLibDST(strName As String) As Boolean
  Dim bRet As Boolean
  On Error Resume Next
  FGDst.Clear
  ClearGe GeDST
  m_LbrMgrDST.CloseLibrary
  
  If Len(strName) = 0 Then Exit Function
  
  bRet = m_LbrMgrDST.OpenLibrary(strName, False)   ' bReadOnly
  If bRet Then PopulateFolders FGDst, m_LbrMgrDST, False
  OpenLibDST = bRet
End Function

'---------------------------
Private Sub FGDst_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
  UpdateStatsDST
End Sub
'---------------------------
Private Sub FGDst_RowColChange()
  Dim strLib As String, strFolder As String, strName As String
  If m_bChangingDst Then Exit Sub
  m_bChangingDst = True
  With FGDst
    If GetFolderAndShape(FGDst, strFolder, strName) Then
      If GetSelLib(lblLibDST, strLib) Then ShowShapeToView GeDST, strLib, strFolder, strName
    End If
  End With
  m_bChangingDst = False
End Sub

'=============================================================
' Differences
'=============================================================
'---------------------------
Private Sub UpdateStatsSRC()
  On Error Resume Next
  Dim i As Long
  Dim nCnt As Long
  With FGSrc
    nCnt = .SelectedRows
    For i = 0 To .SelectedRows - 1
      If .SelectedRow(i) = 0 Then
        nCnt = nCnt - 1
        Exit For
      End If
    Next i
    lblSrcCount.Caption = nCnt & " of " & (.Rows - 1) & " selected."
    If nCnt = 0 Then ClearGe GeSRC
  End With
End Sub
'---------------------------
Private Sub UpdateStatsDST()
  On Error Resume Next
  Dim i As Long
  Dim nCnt As Long
  With FGDst
    nCnt = .SelectedRows
    For i = 0 To .SelectedRows - 1
      If .SelectedRow(i) = 0 Then
        nCnt = nCnt - 1
        Exit For
      End If
    Next i
    lblDstCount.Caption = nCnt & " of " & (.Rows - 1) & " selected."
    If nCnt = 0 Then ClearGe GeDST
  End With
End Sub

'---------------------------
Public Sub ShowDifferences()
  btnShapeDiff_Click
End Sub
'---------------------------
Private Sub btnShapeDiff_Click()
  ' get all differences
  ' assume that SRC lib is the master
  Dim strNameSRC As String, strNameDST As String
  Dim bDoDiff As Boolean
  
  On Error Resume Next
  
  If m_bShowingDiffs Then
    bDoDiff = False
  Else
    bDoDiff = True
    If GetSelLib(lblLibDST, strNameDST) Then
      If GetSelLib(lblLibSRC, strNameSRC) Then
        If UCase(strNameSRC) = UCase(strNameDST) Then
          bDoDiff = False ' same libs or empty
        End If
      End If
    End If
  End If
  
  If Not bDoDiff Then
    m_bShowingDiffs = False
    btnUpdateDiffs.Enabled = False
    btnShapeDiff.Caption = "View Differences"
    EnableCommonOps True
    AlignLibraryViews
    OpenLibSRC lblLibSRC.Caption
    OpenLibDST lblLibDST.Caption
    ClearGe GeSRC
    ClearGe GeDST
  Else
    m_bShowingDiffs = True
    EnableCommonOps False
    btnShapeDiff.Enabled = True
    btnUpdateDiffs.Enabled = True
    btnShapeDiff.Caption = "View Both"
    BeginWaitCursor
    ClearGe GeSRC
    ClearGe GeDST
    AlignLibraryViews
    
    OpenLibSRC ""       ' 0 len name will close, clear and exit
    OpenLibDST strNameDST
    
    ' NOTE: put diffs (managed by lbrMgrDST) in fgSRC,
    ' making it easier to align screen
    
    PopulateFolders FGSrc, m_LbrMgrDST, True, strNameSRC
  End If
  
  UpdateStatsSRC
  EndWaitCursor
End Sub
'---------------------------
Private Sub ShowShapeDiffsToView()
  ' show differences to view
  Dim strLib As String, strFolder As String, strName As String
  Dim objInfo As GeShapeDefInfo
  
  On Error Resume Next
 
  m_bChangingDst = True
  Set objInfo = FGSrc.RowData(FGSrc.Row)
  '
  If Not objInfo Is Nothing Then
    If Not objInfo.FolderInfoOnly Then
      strFolder = objInfo.FolderName
      strName = objInfo.ShapeName
        ' if rev is -1, then its invalid
      If objInfo.Revision >= 0 Then
        If GetSelLib(lblLibSRC, strLib) Then
          ShowShapeToView GeSRC, strLib, strFolder, strName
        End If
      Else
        ClearGe GeSRC
      End If
        ' if rev is -1, then its invalid
      If objInfo.RevisionDST >= 0 Then
        If GetSelLib(lblLibDST, strLib) Then
          ShowShapeToView GeDST, strLib, strFolder, strName
        End If
      Else
        ClearGe GeDST
      End If
    End If
  Else
    ClearGe GeSRC
    ClearGe GeDST
  End If
  '
  m_bChangingDst = False
End Sub

'---------------------------
Private Sub btnUpdateDiffs_Click()
  On Error Resume Next
  BeginWaitCursor
  
  CopySelSRCtoDST
  m_bShowingDiffs = False
  btnShapeDiff_Click
  
  UpdateStatsSRC
  EndWaitCursor
End Sub

'---------------------------
Private Function CopySelSRCtoDST() As Boolean
  ' copy what is selected in src to dst
  Dim i As Long
  Dim objInfo As GeShapeDefInfo
  Dim coll As Collection
  Dim strNameSRC As String
  Dim bRet As Boolean
  
  On Error Resume Next
  If GetSelLib(lblLibSRC, strNameSRC) Then
    Set coll = New Collection
    For i = 0 To FGSrc.SelectedRows - 1
      If FGSrc.SelectedRow(i) > 0 Then
        Set objInfo = FGSrc.RowData(FGSrc.SelectedRow(i))
        coll.Add objInfo
      End If
    Next i
    '
    If coll.Count > 0 Then
      CopySelSRCtoDST = m_LbrMgrDST.UpdateShapeDifferences(strNameSRC, coll)
    End If
    Set coll = Nothing
  End If
End Function


'=============================================================
' Helpers
'=============================================================
'------------------------
Private Sub PopulateFolders(FG As vsFlexGrid, lbrMgr As GeLibraryMgr, _
                ByVal bShowDifferences As Boolean, Optional ByVal NameSRC As String)
  ' populate FlexGrid
  Dim i As Long
  
  On Error Resume Next
  With FG
    .Redraw = False
    .Clear
    .Rows = 1      ' top row
    If bShowDifferences Then
      .Cols = 4
    Else
      .Cols = 3      ' cols per row
    End If
    .FixedCols = 0   ' 1 fixed column
    .FixedRows = 1   ' 1 fixed row (the top one)
    .WordWrap = True
    .ScrollBars = flexScrollBarBoth
    .SelectionMode = flexSelectionListBox ' flexSelectionFree
    .MergeCells = 0
    .ExplorerBar = flexExSortAndMove ' 3   flexExMove ' 2
    .ExtendLastCol = True
    .Editable = False ' True
    .ColAlignment(0) = flexAlignLeftCenter
    .Row = 0
    For i = 0 To .Cols - 1
      .Col = i
      Select Case i
        Case 0
          .Text = "Folder"
          .ColWidth(i) = 2300
          .MergeCol(i) = True
        Case 1
          .Text = "Shape"
          .ColWidth(i) = 2300
          .MergeCol(i) = True
        Case 2
          .MergeCol(i) = False
          If bShowDifferences Then
            .Text = "Source Version"
            .ColWidth(i) = 1500
          Else
            .Text = "Version"
            .ColWidth(i) = 500
          End If
        Case 3
          .MergeCol(i) = False
'          .ColWidth(i) = 1500
          If bShowDifferences Then
            .Text = "Destination Version"
          Else
            .Text = "Version"
          End If
      End Select
    Next i
  
  End With
  ''
  If bShowDifferences Then
    DoPopulateFoldersDiff FG, lbrMgr, NameSRC
  Else
    DoPopulateFolders FG, lbrMgr
  End If
  ''
  With FG
    .Row = 0
    .Redraw = True
  End With

End Sub

'---------------------------
Private Sub DoPopulateFolders(FG As vsFlexGrid, lbrMgr As GeLibraryMgr)
  ' just populate with all info from 1 library
  Dim coll As Collection
  Dim collShp As Collection
  Dim i As Long, j As Long
  Dim strFolder As String
  Dim objInfo As GeShapeDefInfo
  Dim strAdd As String
  
  
  On Error Resume Next
  Set coll = New Collection
  Set collShp = New Collection
  
  If lbrMgr.GetAllFolders(coll) Then
    With FG
      For i = 1 To coll.Count
        strFolder = coll.Item(i)
        If lbrMgr.GetAllShapesForFolder(collShp, strFolder) Then
          For j = 1 To collShp.Count
            '
            Set objInfo = collShp.Item(j)
            strAdd = objInfo.FolderName & vbTab & _
                    objInfo.ShapeName & vbTab & _
                    objInfo.Revision
            .AddItem strAdd
            .RowData(.Rows - 1) = objInfo
            '
          Next j
          ' clean up
          For j = 1 To collShp.Count
            collShp.Remove 1
          Next j
          '
        End If
      Next i
    End With
  End If
  Set coll = Nothing
  Set collShp = Nothing
End Sub

'---------------------------
Private Sub DoPopulateFoldersDiff(FG As vsFlexGrid, lbrMgr As GeLibraryMgr, ByVal NameSRC As String)
  ' populate DST with all differences from SRC
  Dim i As Long
  Dim collShapeDefInfo As Collection
  Dim objInfo As GeShapeDefInfo
  Dim strAdd As String
  Dim strNameSRC As String
  
  On Error Resume Next
  
  strNameSRC = NameSRC
  Set collShapeDefInfo = New Collection
  If lbrMgr.GetAllShapeDifferences(strNameSRC, collShapeDefInfo) Then
    With FG
      For i = 1 To collShapeDefInfo.Count
        Set objInfo = collShapeDefInfo.Item(i)
        If Not objInfo.FolderInfoOnly Then
          strAdd = objInfo.FolderName & vbTab & _
                   objInfo.ShapeName & vbTab & _
                   objInfo.Revision & vbTab & _
                   objInfo.RevisionDST
            .AddItem strAdd
            .RowData(.Rows - 1) = objInfo
            '
        End If
      Next i
    End With
  End If
  ''
  Set collShapeDefInfo = Nothing
  
End Sub

'---------------------------
Private Function GetFolderAndShape(FG As vsFlexGrid, strFolder As String, strName As String) As Boolean
  Dim objInfo As GeShapeDefInfo
  
  On Error Resume Next
  With FG
    If .Row = 0 Then Exit Function
    Set objInfo = .RowData(.Row)
    strFolder = objInfo.FolderName
    strName = objInfo.ShapeName
    GetFolderAndShape = True
  End With
End Function
'---------------------------
Private Function GetSelLib(lbl As VB.Label, strName As String) As Boolean
  With lbl
    strName = .Caption
    If Len(strName) > 0 Then GetSelLib = True
  End With
End Function

'=============================================================
' Ge Preview Helpers
'=============================================================
'---------------------------
Private Sub ClearGe(Ge As GeCtlLib.Ge)
  On Error Resume Next
  Ge.InitNew
'  Ge.DrawingWidth = 10000 ' 0.01
'  Ge.DrawingHeight = 10000 ' 0.01
  Ge.MarginDisplay = False
  Ge.Grid = False
  Ge.ScrollBars = False
  Ge.Tool = GETOOL_NONE ' SELECT
  Ge.DrawInsertionPoints = True
  If Ge.Name = "GeDST" Then
    lblPreviewDST.Caption = ""
  Else
    lblPreviewSRC.Caption = ""
  End If
  Ge.ZoomRect 50, 50, 70, 70

End Sub
'---------------------------
Private Sub ScaleDwgForViewing(Ge As GeCtlLib.Ge)
  ' set up so don't show page area
  On Error Resume Next
  Dim llX As Single, llY As Single, urX As Single, urY As Single
  Dim dWt As Single, dHt As Single
  Dim dInflate As Single
  Dim strMsg As String
  Dim strFmt As String
  
  Ge.GrabHandlesEnabled = False
  
  Ge.DrawingOriginX = -10000#
  Ge.DrawingOriginY = -10000#
  Ge.DrawingWidth = 0.01
  Ge.DrawingHeight = 0.01
  Ge.PageWidth = 0.01
  Ge.PageHeight = 0.01
  
  Ge.SelectAll
  Ge.GetExtents llX, llY, urX, urY
  Ge.SelRemoveAll

  ' show size of shape
  dWt = urX - llX
  dHt = urY - llY
  strFmt = "#########0.00000"
  strMsg = "Width: " & Format(dWt, strFmt) & ", Height: " & Format(dHt, strFmt)
  
  If Ge.Name = "GeSRC" Then
    lblPreviewSRC.Caption = strMsg
  ElseIf Ge.Name = "GeDST" Then
    lblPreviewDST.Caption = strMsg
  End If
  
  ' extend area by 10%
  dInflate = 0.2
  
  If llX > 0# Then
    llX = llX - (dInflate * llX)
  Else
    llX = llX + (dInflate * llX)
  End If
  If llY > 0# Then
    llY = llY - (dInflate * llY)
  Else
    llY = llY + (dInflate * llY)
  End If
  If urX > 0# Then
    urX = urX + (dInflate * urX)
  Else
    urX = urX - (dInflate * urX)
  End If
  If urY > 0# Then
    urY = urY + (dInflate * urY)
  Else
    urY = urY - (dInflate * urY)
  End If

  Ge.ZoomRect llX, llY, urX, urY
'  Ge.ZoomPage
'  Ge.ZoomExtents
  
  Ge.GrabHandlesEnabled = True

End Sub

'---------------------------
Private Sub ScaleDwgToShape(Ge As GeCtlLib.Ge)
  ' scale drawing so it fits shape
  Dim llX As Single, llY As Single, urX As Single, urY As Single
  Dim dWt As Single, dHt As Single
  
  Ge.GrabHandlesEnabled = False
  Ge.SelectAll
  Ge.GetExtents llX, llY, urX, urY
  
  ' extend area by 10%
'  llX = llX - (0.1 * llX)
'  llY = llY - (0.1 * llY)
'  urX = urX + (0.1 * urX)
'  urY = urY + (0.1 * urY)
  
  ' resize page so can save picture
  Ge.DrawingOriginX = llX
  Ge.DrawingOriginY = llY
  dWt = urX - llX
  dHt = urY - llY
  Ge.DrawingWidth = dWt
  Ge.PageWidth = dWt
  Ge.DrawingHeight = dHt
  Ge.PageHeight = dHt
    
  Ge.SelRemoveAll
  Ge.ZoomPage
  Ge.GrabHandlesEnabled = True

End Sub

'---------------------------
Private Sub ShowShapeToView(Ge As GeCtlLib.Ge, ByVal strLib As String, _
                    ByVal strFolder As String, ByVal strName As String)
  ' show the shape
  Dim GeID As Long
  Dim strpath As String
  Dim llX As Single, llY As Single, urX As Single, urY As Single
  Dim dWt As Single, dHt As Single
  Dim ptX As Single, ptY As Single
  
  On Error Resume Next
  ClearGe Ge
  Ge.ScrollBars = False
  Ge.AttachLibrary strLib
  ptX = 0#
  ptY = 0#
  GeID = Ge.CreateShape(strLib, strFolder, strName, ptX, ptY)

'  strPath = strLib & "!" & strFolder
'  GeID = Ge.InsertShape(strPath, strName)
  If GeID > 0 Then
'    Ge.SimulateLButtonDown 0, 0

'    Ge.ZoomExtents
'    Ge.CurrentPropertyID = GeID  ' move into selector
'    Ge.CurrentPropertyID = 0  ' reset selector
'    Ge.SelRemoveAll
    ScaleDwgForViewing Ge
    
  Else
    MsgBox "Failed to insert shape." & Chr(10) & strFolder & Chr(10) & strName
  End If
End Sub

'=============================================================
' General
'=============================================================
'---------------------------
Private Sub Form_Initialize()
  Set m_LbrMgrSRC = New GeLibraryMgr
  Set m_LbrMgrDST = New GeLibraryMgr
  m_bChangingSrc = True
  m_bChangingDst = True
End Sub
'---------------------------
Private Sub form_Load()
  On Error Resume Next
  EnableOperations False
  FGSrc.Clear
  FGSrc.Rows = 0
  FGDst.Clear
  FGDst.Rows = 0
  GeDST.ScrollBars = False
  GeSRC.ScrollBars = False

  m_bChangingSrc = False
  m_bChangingDst = False
End Sub
'---------------------------
Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
  On Error Resume Next
  m_LbrMgrSRC.CloseLibrary
  m_LbrMgrDST.CloseLibrary
  GeDST.InitNew
  GeSRC.InitNew
  Set m_LbrMgrSRC = Nothing
  Set m_LbrMgrDST = Nothing
End Sub
'---------------------------
Private Sub form_Resize()
  On Error Resume Next
  picPreview.Move 0, Me.ScaleHeight - (picPreview.Height + 45), _
                Me.ScaleWidth, picPreview.Height
  picFGs.Move 0, picFGs.Top, Me.ScaleWidth, picPreview.Top - picFGs.Top
  AlignLibraryViews
End Sub
'---------------------------
Private Sub AlignLibraryViews()
  ' align FGs and buttons
  Dim lTop As Long
  Dim fgtop As Long, fgHT As Long
  Dim middle As Long
  On Error Resume Next
  
  picFGL.BorderStyle = 0
  picFGR.BorderStyle = 0
  
  '' middle - adjust ht
  middle = picFGs.Width / 2
  If m_bShowingDiffs Then
    picMiddle.Move middle, 0, picMiddle.Width, picFGLT.Top + picFGLT.Height
  Else
    picMiddle.Move middle, 0, picMiddle.Width, picFGs.Height
  End If
  
  '' combos,...
  picFGLT.Move 0, 0, middle, picFGLT.Height
  picFGRT.Move middle + picMiddle.Width, 0, _
            picFGs.Width - (picMiddle.Left + picMiddle.Width), _
            picFGRT.Height
  
  fgtop = picFGLT.Top + picFGLT.Height
  fgHT = picFGs.Height - fgtop
  
  
  '' Selection grids
  If m_bShowingDiffs Then
    picFGR.Visible = False
    picFGL.Move 0, fgtop, picFGs.Width - 3000, fgHT
    lTop = lblSrcCount.Top + lblSrcCount.Height + 45
    FGSrc.Move 45, lTop, picFGL.Width - 90, picFGL.Height - lTop - 145
  Else
    picFGR.Visible = True
    '' left
    picFGL.Move 0, fgtop, picMiddle.Left - 45, fgHT
    lTop = lblSrcCount.Top + lblSrcCount.Height + 45
    FGSrc.Move 45, lTop, picFGL.Width - 90, picFGL.Height - lTop - 145
    '' right
    picFGR.Move picMiddle.Left + picMiddle.Width, fgtop, _
                picFGs.Width - (picMiddle.Left + picMiddle.Width), _
                fgHT
    lTop = lblDstCount.Top + lblDstCount.Height + 45
    FGDst.Move 45, lTop, picFGR.Width - 90, picFGR.Height - lTop - 145
  End If
End Sub

