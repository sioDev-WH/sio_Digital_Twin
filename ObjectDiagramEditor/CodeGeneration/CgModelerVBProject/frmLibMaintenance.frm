VERSION 5.00
Object = "{5C607640-780C-11CF-92BA-444553540000}#1.0#0"; "GeCtl.tlb"
Begin VB.Form frmLibMaintenance 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Library Maintenance"
   ClientHeight    =   6630
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   9630
   Icon            =   "frmLibMaintenance.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   6630
   ScaleWidth      =   9630
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton btnOK 
      Caption         =   "Close"
      Height          =   345
      Left            =   8610
      TabIndex        =   15
      Top             =   150
      Width           =   945
   End
   Begin VB.CommandButton btnListShapes 
      Caption         =   "List all Shapes containing Field"
      Height          =   375
      Left            =   3450
      TabIndex        =   14
      ToolTipText     =   "List all Shapes containing Field 'Existing Field Tag'"
      Top             =   2850
      Width           =   2445
   End
   Begin VB.PictureBox picStsMsg 
      Align           =   2  'Align Bottom
      Height          =   2505
      Left            =   0
      ScaleHeight     =   2445
      ScaleWidth      =   9570
      TabIndex        =   11
      Top             =   4125
      Width           =   9630
      Begin VB.ListBox lbError 
         Height          =   2010
         Left            =   0
         MultiSelect     =   2  'Extended
         TabIndex        =   13
         Top             =   0
         Width           =   8340
      End
      Begin VB.HScrollBar HScroll1 
         Height          =   240
         LargeChange     =   5
         Left            =   0
         Max             =   100
         TabIndex        =   12
         Top             =   2070
         Width           =   8340
      End
   End
   Begin GeCtlLib.Ge Ge1 
      Height          =   1785
      Left            =   6090
      TabIndex        =   10
      Top             =   1020
      Visible         =   0   'False
      Width           =   2235
      _Version        =   65536
      _ExtentX        =   3942
      _ExtentY        =   3149
      _StockProps     =   64
   End
   Begin VB.OptionButton Option1 
      Alignment       =   1  'Right Justify
      Caption         =   "Place Field at Origin of Shape "
      Height          =   255
      Index           =   1
      Left            =   2850
      TabIndex        =   9
      Top             =   1890
      Width           =   3045
   End
   Begin VB.OptionButton Option1 
      Alignment       =   1  'Right Justify
      Caption         =   "Place Field at Center of Shape Extents"
      Height          =   255
      Index           =   0
      Left            =   2850
      TabIndex        =   8
      Top             =   1590
      Value           =   -1  'True
      Width           =   3045
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Index           =   2
      Left            =   3540
      TabIndex        =   7
      ToolTipText     =   "0 Length value is recommended"
      Top             =   1170
      Width           =   2325
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Index           =   1
      Left            =   3540
      TabIndex        =   4
      ToolTipText     =   "0 Length value is recommended"
      Top             =   780
      Width           =   2325
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Index           =   0
      Left            =   3540
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   420
      Width           =   2325
   End
   Begin VB.CommandButton btnAddField 
      Caption         =   "Add Field to all Shapes"
      Height          =   375
      Left            =   3450
      TabIndex        =   0
      ToolTipText     =   "The new TextField will be added to ALL Shapes in the library"
      Top             =   2340
      Width           =   2445
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "'Existing Field Tag' to use as search criteria"
      Height          =   195
      Index           =   2
      Left            =   465
      TabIndex        =   6
      ToolTipText     =   "Tag for a field already in the Shapes"
      Top             =   1230
      Width           =   3030
   End
   Begin VB.Label Label2 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "The New TextField will be added to all Shapes Already containing a field with the Tag matching 'Existing Field Tag'"
      Height          =   195
      Left            =   90
      TabIndex        =   5
      Top             =   150
      Width           =   8070
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "NEW TextField Value:"
      Height          =   195
      Index           =   1
      Left            =   1920
      TabIndex        =   3
      ToolTipText     =   "0 Length value is recommended"
      Top             =   810
      Width           =   1575
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "NEW TextField TAG:"
      Height          =   195
      Index           =   0
      Left            =   1980
      TabIndex        =   2
      ToolTipText     =   "A unique Field Tag is required"
      Top             =   480
      Width           =   1500
   End
End
Attribute VB_Name = "frmLibMaintenance"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
' frmLibMaintenance
'======================================================================================
Option Explicit

Private m_LbrMgr As GeLibraryMgr
Private m_bListShapes As Boolean

' Status Window
Private m_ncLinesVisible As Integer ' Status Message Window count
'

'======================================================================================
'======================================================================================

'---------------------------
Public Property Set GeLibraryMgr(obj As GeLibraryMgr)
  Set m_LbrMgr = obj
End Property

Private Sub btnOK_Click()
  Unload Me
End Sub

'---------------------------
Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
  Set m_LbrMgr = Nothing
End Sub

'---------------------------
Private Sub btnListShapes_Click()
  ClearStatusMsg
  m_bListShapes = True
  EnableUI False
  ProcAddField
  EnableUI True
  m_bListShapes = False
End Sub

'---------------------------
Private Sub btnAddField_Click()
  EnableUI False
  ProcAddField
  EnableUI True
End Sub
'---------------------------
Private Sub EnableUI(ByVal bEnable As Boolean)
  Option1(0).Enabled = bEnable
  Option1(1).Enabled = bEnable
  btnAddField.Enabled = bEnable
  btnOK.Enabled = bEnable
  btnListShapes.Enabled = bEnable
End Sub

'---------------------------
Private Sub ProcAddField()
  '
  Dim iFldr As Long, iShp As Long
  Dim strLibName As String
  Dim strFldToMatch As String
  Dim strFldTag As String, strFldValue As String
  Dim collFolder As New Collection
  Dim collShape As New Collection
  Dim strFldr As String, strShp As String
  Dim objInfo As GeShapeDefInfo
  
  
  On Error Resume Next
  If m_LbrMgr Is Nothing Then Exit Sub
  
  ' get info from user
  strFldToMatch = Text1(2).Text
  If Len(strFldToMatch) = 0 Then Exit Sub
  '
  strFldTag = Text1(0).Text
  If Len(strFldTag) = 0 And Not m_bListShapes Then Exit Sub
  strFldValue = Text1(1).Text
  
  '
  BeginWaitCursor
  strLibName = m_LbrMgr.LibrayName
  If m_LbrMgr.GetAllFolders(collFolder) Then
    For iFldr = 1 To collFolder.Count
      strFldr = collFolder.Item(iFldr)
      ' clean existing
      For iShp = 1 To collShape.Count
        collShape.Remove 1
      Next iShp
      ' get shapes in folder
      If m_LbrMgr.GetAllShapesForFolder(collShape, strFldr) Then
        For iShp = 1 To collShape.Count
          Set objInfo = collShape.Item(iShp)
          strShp = objInfo.ShapeName
          ' do it!
          DoAddField strLibName, strFldr, strShp, strFldToMatch, strFldTag, strFldValue
        Next iShp
      End If
    Next iFldr
  End If
  '
  EndWaitCursor

End Sub
'---------------------------
Private Sub DoAddField(strLibName As String, _
          strFldr As String, strShp As String, _
          strFldToMatch As String, strNewFldTag As String, strNewFldValue As String)
  ' insert shape then parse shape. Add field if req'd
  Dim GeID As Long
  Dim nFlds As Integer
  Dim iFld As Integer
  Dim bDoIt As Boolean
  Dim strFldName As String, strFldValue As String
  Dim nGeFldType As Integer
  Dim bFldExists As Boolean
  
  On Error Resume Next
  
  Ge1.SelectAll
  Ge1.Delete
  ' put at 0,0
  GeID = Ge1.CreateShape(strLibName, strFldr, strShp, 0#, 0#)
  If GeID = 0 Or err <> 0 Then
    ShowStatusMsgA Error & vbTab & strLibName & "," & strFldr & "!" & strShp
    Exit Sub
  End If
  
'  Ge1.ZoomExtents
  
  ' see if field matches criteria
  If Ge1.ShapeSetCurrent(GeID) Then
    nFlds = Ge1.ShapeFieldCount
    For iFld = 0 To nFlds - 1
      If Ge1.ShapeSetCurrentField(iFld) Then
        If Ge1.ShapeGetFieldNameValue(strFldName, strFldValue) Then
          nGeFldType = Ge1.ShapeGetFieldType
          ' 2 = ShapeField, 1 = TextField, 0 = invalid
          If nGeFldType = 1 Then
            '
            If UCase(strFldName) = UCase(strFldToMatch) Then
              bDoIt = True
            ElseIf UCase(strFldName) = UCase(strNewFldTag) Then
              bFldExists = True
            End If
            '
          End If
        End If
      End If
    Next iFld
  End If
  '
  Ge1.ShapeSetCurrent 0     ' reset selector
  Ge1.CurrentPropertyID = 0
  
  If Not bDoIt Then Exit Sub
  
  ' just list then leave if req'd
  If m_bListShapes Then
    ShowStatusMsgA strLibName & "," & strFldr & "!" & strShp
    Exit Sub
  End If
  
  ' already got a field of that name. Do NOT add again!
  If bFldExists Then Exit Sub
  
  ' center or origin
  Dim bCenter As Boolean
  If Option1(0).Value = True Then bCenter = True
  
  
End Sub




'===========================================================================
' Status Message Window Interface
'===========================================================================
'-------------------------
Private Sub form_Resize()
  On Error Resume Next
  If WindowState = vbNormal Or WindowState = vbMaximized Then
    HScroll1.Value = 0
    HScroll1.Move 0, picStsMsg.Height - HScroll1.Height - 50, _
        picStsMsg.Width - 50, HScroll1.Height
    lbError.Move 0, 0, picStsMsg.Width - 50, _
            picStsMsg.Height - HScroll1.Height - 50
    m_ncLinesVisible = GetCountOfVisibleLines(lbError)
  End If
End Sub

'-----------------------------
Private Sub DoKeyDown(KeyCode As Integer, Shift As Integer)
  'Keyboard handler
Const KEY_CTRL = 2
Dim i As Long

  On Error Resume Next
  If (Shift And KEY_CTRL) Then
    If UCase(KeyCode) = Asc("C") Then
      ' ^C - copy to clipboard
      CopyToClipBoard
    ElseIf UCase(KeyCode) = Asc("X") Then
      ' ^X - copy to clipboard and delete
      CopyToClipBoard
      DeleteSelectedRows
    ElseIf KeyCode = vbKeyDelete Then
      ' Del - delete selected rows
      DeleteSelectedRows
    ElseIf UCase(KeyCode) = Asc("A") Then
      ' select all
      For i = 0 To lbError.ListCount - 1
        lbError.Selected(i) = True
      Next i
    End If
  End If
  KeyCode = 0

End Sub

'-------------------------
Private Sub ShowStatusMsgA(ByVal szStatusMsg As String)
  ' show message.
  On Error Resume Next
  ShowOneStatusMsg szStatusMsg
End Sub
'-------------------------
Private Sub ShowOneStatusMsg(szStatusMsg As String)
  Dim nRes As Integer
  
  On Error Resume Next
  lbError.AddItem szStatusMsg
  ' limit the list to 500 entries
  If lbError.NewIndex > 500 Then
    lbError.RemoveItem 0
  End If
  ' scroll the list if required
  If lbError.TopIndex + m_ncLinesVisible < lbError.ListCount Then
    nRes = lbError.ListCount - m_ncLinesVisible
    If nRes > 0 And nRes < lbError.ListCount - 1 Then
      lbError.TopIndex = lbError.ListCount - m_ncLinesVisible
    End If
  End If
End Sub

'-------------------------
Public Sub ClearStatusMsg()
  lbError.Clear
End Sub
'-------------------------
Private Sub CopyToClipBoard()
  Dim szError As String
  Dim nI As Integer
  Dim bFoundFirst As Boolean
  
  On Error Resume Next
  BeginWaitCursor
  Clipboard.Clear
  For nI = 0 To lbError.ListCount - 1
    If lbError.Selected(nI) Then
      If bFoundFirst Then
        szError = szError & Chr(13) & Chr(10) & lbError.List(nI)
      Else
        bFoundFirst = True
        szError = lbError.List(nI)
      End If
    End If
  Next nI
  Clipboard.SetText szError, vbCFText
  EndWaitCursor
End Sub

'-------------------------
Private Sub DeleteSelectedRows()
  Dim nI As Integer
  On Error Resume Next
  If lbError.ListCount > 0 Then
    Do
      If lbError.Selected(nI) Then
        lbError.RemoveItem nI
      Else
        nI = nI + 1
      End If
    Loop While nI < lbError.ListCount
  End If
End Sub

'-------------------------
Private Sub lbError_KeyDown(KeyCode As Integer, Shift As Integer)
  DoKeyDown KeyCode, Shift
End Sub
'------------------------------
Private Sub HScroll1_Scroll()
  'Scroll
'  Dim strMsg As String
'  strMsg = "Hscroll:" & HScroll1.Value
'  ShowStatusMsg strMsg
End Sub
'------------------------------
Private Sub HScroll1_Change()
Const nDX = 200
  Static nLastVal As Integer
  Dim nVal As Integer
  Dim dVal As Integer
  Dim nValMove As Integer
  
  On Error Resume Next
  nVal = HScroll1.Value
  dVal = HScroll1.Value - nLastVal
  nValMove = dVal * nDX
  
  If nValMove > 0 Then ' move pic left
    lbError.Move lbError.Left - nValMove, lbError.Top, lbError.Width, lbError.Height
    lbError.Width = lbError.Width + nValMove
  Else
    If nVal > 0 Then
        lbError.Move lbError.Left + nValMove, lbError.Top, lbError.Width, lbError.Height
        lbError.Width = lbError.Width - nValMove
        If lbError.Left > 0 Then
          lbError.Move HScroll1.Left, lbError.Top, HScroll1.Width, lbError.Height
        End If
    Else
      lbError.Move HScroll1.Left, lbError.Top, lbError.Width, lbError.Height
      lbError.Width = HScroll1.Width
    End If
  End If
  nLastVal = nVal
End Sub




