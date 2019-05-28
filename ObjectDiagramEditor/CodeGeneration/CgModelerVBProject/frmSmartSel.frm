VERSION 5.00
Begin VB.Form frmSmartSel 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Enhanced Object Selection"
   ClientHeight    =   4890
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   8475
   Icon            =   "frmSmartSel.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4890
   ScaleWidth      =   8475
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.PictureBox picAttrib 
      BorderStyle     =   0  'None
      Height          =   2355
      Left            =   4230
      ScaleHeight     =   2355
      ScaleWidth      =   2025
      TabIndex        =   15
      Top             =   195
      Width           =   2025
      Begin VB.ListBox lbSelAttribute 
         Height          =   2010
         Left            =   15
         TabIndex        =   16
         Top             =   270
         Width           =   1935
      End
      Begin VB.Label Label7 
         AutoSize        =   -1  'True
         Caption         =   "(2) Where ATTRIBUTE(s)"
         Height          =   195
         Left            =   75
         TabIndex        =   17
         Top             =   0
         Width           =   1830
      End
   End
   Begin VB.PictureBox picSelExpr 
      BorderStyle     =   0  'None
      Height          =   810
      Left            =   4455
      ScaleHeight     =   810
      ScaleWidth      =   4065
      TabIndex        =   8
      Top             =   2640
      Width           =   4065
      Begin VB.TextBox txtSelExpression 
         Height          =   300
         Left            =   180
         TabIndex        =   10
         Text            =   "="
         Top             =   225
         Width           =   1080
      End
      Begin VB.TextBox txtSelCriteria 
         Height          =   300
         Left            =   1500
         TabIndex        =   9
         Text            =   "0"
         Top             =   225
         Width           =   2460
      End
      Begin VB.Label Label10 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "(4) matches criteria"
         Height          =   195
         Left            =   1755
         TabIndex        =   14
         Top             =   0
         Width           =   1350
      End
      Begin VB.Label Label8 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "(3) using expression"
         Height          =   195
         Left            =   0
         TabIndex        =   13
         Top             =   0
         Width           =   1395
      End
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "=, <, >, <>"
         Height          =   195
         Left            =   360
         TabIndex        =   12
         ToolTipText     =   "Enter one of these operators"
         Top             =   570
         Width           =   720
      End
      Begin VB.Label lblCriteriaFormat 
         AutoSize        =   -1  'True
         Caption         =   "criteriaFormat"
         Height          =   195
         Left            =   1500
         TabIndex        =   11
         Top             =   570
         Width           =   945
      End
   End
   Begin VB.CommandButton btnObjProps 
      Caption         =   "Properties..."
      Height          =   300
      Left            =   3045
      TabIndex        =   7
      ToolTipText     =   "Change selected objects properties"
      Top             =   3810
      Width           =   1170
   End
   Begin VB.CheckBox chkStepIntoGroups 
      Alignment       =   1  'Right Justify
      Caption         =   "Select within Groups"
      Height          =   195
      Left            =   90
      TabIndex        =   6
      ToolTipText     =   "Select objects within groups also"
      Top             =   4110
      Visible         =   0   'False
      Width           =   1800
   End
   Begin VB.CheckBox chkSelAutoSelect 
      Alignment       =   1  'Right Justify
      Caption         =   "Auto Select"
      Height          =   195
      Left            =   765
      TabIndex        =   3
      ToolTipText     =   "Automatically select as parameters change"
      Top             =   3855
      Width           =   1125
   End
   Begin VB.ListBox lbSelType 
      Height          =   2010
      Left            =   870
      TabIndex        =   2
      Top             =   600
      Width           =   1860
   End
   Begin VB.CommandButton btnSelGetSelection 
      Caption         =   "Select"
      Height          =   300
      Left            =   1980
      TabIndex        =   1
      ToolTipText     =   "Select the objects"
      Top             =   3810
      Width           =   840
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "Close"
      Height          =   315
      Left            =   1642
      TabIndex        =   0
      ToolTipText     =   "Close this dialog"
      Top             =   4500
      Width           =   1170
   End
   Begin VB.Label lblDebug 
      Caption         =   "lblDebug"
      Height          =   195
      Left            =   60
      TabIndex        =   18
      Top             =   2955
      Width           =   4200
   End
   Begin VB.Label lblSmartSelCaption 
      AutoSize        =   -1  'True
      Caption         =   "Number selected: 0"
      Height          =   195
      Left            =   75
      TabIndex        =   5
      Top             =   30
      Width           =   1380
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "Choose object type(s) to select"
      Height          =   195
      Left            =   825
      TabIndex        =   4
      Top             =   330
      Width           =   2175
   End
End
Attribute VB_Name = "frmSmartSel"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
' frmSmartSel
'======================================================================================
Option Explicit
'
'========================================================
'
' Smart Selection
Private m_bConstructingSel As Boolean
'Private m_collSel As Collection       ' all geObjects in drawing
Private m_collSel As Collection       ' all possible types

Private m_nSelOpMode As Integer   ' expression operator set (logical, region, layer,...)
Private m_bStepIntoGroups As Boolean  ' step into CG groups

Private m_GeCtrl As CG  ' ref to current drawing

#Const timedebug = False  ' True
#If timedebug Then
  Private m_t1 As Long
  Private m_t2 As Long
  '

' 11/8/00
' ****** PC at Work *****
' FILE: TVStandD0.CGF (69 objects)
  
  '' <original> code
  ' 50 ms - Enumeration : CG selection code (using GeObjectInfo and single collection)
  ' 920 ms - Selection (all)
  
  '' <new> code - use multiple collections, 1 for each type, each holding GeIDs
  ' SendStatusEvents Disabled
    ' 20 ms - Enumeration
    ' 71 ms -  grab off, select, grab on, refresh
    ' 100 ms - Selection (all) : don't touch grab handles




' 11/8/00
' ****** PC at Home *****
'' Enumeration Method
  ' 174 ms - <original> CG selection code (using GeObjectInfo and single collection)
    ' TVStandD.gef (69 objects)
    
    ' ?? ms -
  ' 148 ms - <new> use multiple collections, 1 for each type, each holding GeIDs
    ' TVStandD.gef (69 objects)
    ' 30 ms - no events in enum code
  
  '
'' Selection techniques (using new in memory technique)
' SendStatusEvents ON
  ' SmartSelA.Gef (11 objects)
    ' 842 ms - don't touch grab handles
    ' 870 ms - grab off, select, grab on, refresh
  ' TVStandD.gef (69 objects)
    ' 4870 ms - don't touch grab handles
    ' 4660 ms -  grab off, select, grab on, refresh
  '
' SendStatusEvents OFF
  ' SmartSelA.Gef (11 objects)
    ' 23 ms - don't touch grab handles
    ' 28 ms - grab off, select, grab on, refresh
  ' TVStandD.gef (69 objects)
    ' 405 ms - don't touch grab handles
    ' 157 ms -  grab off, select, grab on, refresh
  ' 30 ms - no events in enum code

#End If

'========================================================
'------------------------------
#If timedebug Then
Private Sub ShowDebugMsg(strMsg As String)
  lblDebug.Caption = strMsg
End Sub
#End If ' timedebug

'-------------------------
Public Property Set GeCtrl(obj As CG)
  Set m_GeCtrl = obj
End Property

'------------------------------
Private Sub Form_Activate()
  Static bFirst As Boolean
  On Error Resume Next
  If Not bFirst Then
    bFirst = True
    ShowCriteriaFormat 0
    EnumDrawingObjects
  End If
End Sub

'------------------------------
Private Sub Form_Load()
  On Error Resume Next
  DoInitialize
  ShowFutureControls False
#If timedebug Then
  ShowDebugMsg ""
#Else
  lblDebug.Visible = False
#End If

End Sub
'------------------------------
Private Sub ShowFutureControls(bShow As Boolean)
  picAttrib.Visible = bShow
  picSelExpr.Visible = bShow
End Sub

'------------------------------
Private Sub DoInitialize()
  Dim iType As Long
  Dim collType As Collection
  On Error Resume Next
  
  If m_collSel Is Nothing Then Set m_collSel = New Collection
  
  For iType = EGeObjType.Invalid To EGeObjType.DimensionLine ' 0 to 28
    Set collType = New Collection
    m_collSel.Add collType
  Next iType
End Sub
'------------------------------
Private Sub DoTerminate()
  Dim i As Long, j As Long
  Dim collTmp As Collection
  
  On Error Resume Next
  If Not m_collSel Is Nothing Then
    For i = 1 To m_collSel.count
      Set collTmp = m_collSel.Item(i)
      For j = 1 To collTmp.count
        collTmp.Remove 1
      Next j
      Set collTmp = Nothing
      m_collSel.Remove 1
    Next i
    Set m_collSel = Nothing
  End If
End Sub
'------------------------------
Private Sub FlushCurrent()
  ' flush current in memory refs
  Dim i As Long, j As Long
  Dim collTmp As Collection
  
  On Error Resume Next
  If Not m_collSel Is Nothing Then
    For i = 1 To m_collSel.count
      Set collTmp = m_collSel.Item(i)
      For j = 1 To collTmp.count
        collTmp.Remove 1
      Next j
    Next i
  End If
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Screen.MousePointer = vbArrow
End Sub

'------------------------------
Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
  On Error Resume Next
  DoTerminate
  If Not m_GeCtrl Is Nothing Then
    m_GeCtrl.SelStepIntoGroups = False
    m_GeCtrl.CurrentPropertyID = 0  ' reset selector
    Set m_GeCtrl = Nothing
  End If
End Sub
'-----------------------------
Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
  On Error Resume Next
  Select Case KeyCode
    Case vbKeyReturn    ' select
      btnOK_Click
    Case vbKeyEscape    ' go away
      btnOK_Click
    End Select
End Sub
'-------------------------
Private Sub btnOK_Click()
  Unload Me
End Sub

'=====================================================================================
' Smart Selection
'=====================================================================================
'------------------------------
Private Sub btnObjProps_Click()
  ' change properties
  On Error Resume Next
  m_GeCtrl.DoObjectDialog
End Sub

'------------------------------
Private Sub btnSelGetSelection_Click()
  DoSelForSelParams
End Sub
'------------------------------
Private Sub lbSelType_Click()
  ' type of object changed. update available attributes, etc..
  If m_bConstructingSel Then Exit Sub
  UpdateControlsForSelTypes
End Sub
'------------------------------
Private Property Get CanAutoSelect() As Boolean
  If chkSelAutoSelect.Value <> 0 And m_nSelOpMode = 0 Then
    CanAutoSelect = True
  End If
End Property

'------------------------------
Private Sub lbSelAttribute_Click()
  ' type of attribute
  If m_bConstructingSel Then Exit Sub
  ShowCriteriaFormat lbSelAttribute.ListIndex
  If CanAutoSelect Then DoSelForSelParams
End Sub
'------------------------------
Private Sub chkSelAutoSelect_Click()
  If m_bConstructingSel Then Exit Sub
  If CanAutoSelect Then DoSelForSelParams
End Sub
'------------------------------
Private Sub chkStepIntoGroups_Click()
  m_bStepIntoGroups = IIf(chkStepIntoGroups.Value = 0, False, True)
  If m_bConstructingSel Then Exit Sub
  If CanAutoSelect Then DoSelForSelParams
End Sub

'------------------------------
Private Sub ShowCriteriaFormat(index As Integer)
  ' format of expression
  Dim bEnable As Boolean
  bEnable = True
  Select Case index
    Case 1 ' Region
      lblCriteriaFormat.Caption = "X0, Y0, X1, Y1"
      m_nSelOpMode = index
    Case 2 ' Layer
      lblCriteriaFormat.Caption = "0 to 29999"
      m_nSelOpMode = index
    
    Case Else  ' general
      lblCriteriaFormat.Caption = ""
      m_nSelOpMode = 0
      bEnable = False
  End Select
  ''
  txtSelExpression.Enabled = bEnable
  txtSelCriteria.Enabled = bEnable
  chkSelAutoSelect.Enabled = Not bEnable
  
End Sub

'***************************************************************
'------------------------------
Private Sub EnumDrawingObjects()
  ' enumerate whatever is in the Drawing
  On Error Resume Next
  If Not m_GeCtrl Is Nothing Then
    BeginWaitCursor
    m_bConstructingSel = True
    EnumGeObjects
    InitSelControls
    m_bConstructingSel = False
'    lbSelType.ListIndex = 0
'    lbSelAttribute.ListIndex = 0
    EndWaitCursor
  End If
End Sub

'------------------------------
Private Sub InitSelControls()
  ' initialize the Selection controls
  ' filter out types so only show what is on drawing
  Dim iType As Long
  Dim collType As Collection
  
  On Error Resume Next
  lbSelType.Clear
  lbSelType.AddItem "(All)"
  lbSelType.ItemData(lbSelType.NewIndex) = 0
  '
  ' 11/6/00 - DimensionLine last known objType from geCtrl
  '
  For iType = EGeObjType.Invalid To EGeObjType.DimensionLine
    Set collType = m_collSel.Item(iType + 1)
    ' check if needed
    If collType.count > 0 Then
      lbSelType.AddItem GeWorker.GetGeObjectType_Str(iType)
      lbSelType.ItemData(lbSelType.NewIndex) = iType
    End If
  Next iType
End Sub
'------------------------------
Private Sub UpdateControlsForSelTypes()
  ' update controls and selection in CG
  ' based on what is currently asked to be selected
  Dim i As Long
  Dim nGeType As Integer
  Dim bAdd As Boolean
  Dim nTypeSel As Integer
  Dim nNdxPrev As Integer
  
  Dim bPen As Boolean, bBrush As Boolean, bFont As Boolean
  Dim bLineWidth As Boolean, bBackground As Boolean
  
  On Error Resume Next
  
  nNdxPrev = lbSelAttribute.ListIndex
  
  lbSelAttribute.Clear
  lbSelAttribute.AddItem "(Any)"
  lbSelAttribute.ItemData(lbSelAttribute.NewIndex) = 0
  
  lbSelAttribute.AddItem "(Region)"
  lbSelAttribute.ItemData(lbSelAttribute.NewIndex) = 1
  lbSelAttribute.AddItem "(Layer)"
  lbSelAttribute.ItemData(lbSelAttribute.NewIndex) = 2
  
  If nNdxPrev > -1 And nNdxPrev < lbSelAttribute.ListCount Then
    lbSelAttribute.ListIndex = nNdxPrev
  End If
  
  If lbSelType.ListIndex < 0 Then
    Exit Sub
  End If
  nTypeSel = lbSelType.ItemData(lbSelType.ListIndex)
  
  ''
  If CanAutoSelect Then DoSelForSelParams
  
End Sub


'------------------------------
Private Sub EnumGeObjects()
  ' construct array of info from CG
  Dim i As Long
  Dim GeID As Long
  Dim nGeType As Integer
  Dim collType As Collection
  
  On Error Resume Next
  
#If timedebug Then
  m_t1 = timeGetTime
#End If
  
  ' clear in memory info
  FlushCurrent
  
  ' get info from current drawing
  With m_GeCtrl
    .SelRemoveAll                   ' flush current selection
    .GrabHandlesEnabled = False
    .SendStatusEvents = False       ' set after removeall so can refresh rest of app
    .SelStepIntoGroups = m_bStepIntoGroups
    .SelAddAll
  
    If .SelNumberOfObjects > 0 Then
      GeID = .GetFirstSelObject
      While GeID > 0
        .CurrentPropertyID = GeID  ' move into selector
        nGeType = .ObjectType
        ' add to in memory info. ( add 1 to nGeType as getype 0 (invalid) is at pos 1 in coll)
        Set collType = m_collSel.Item(nGeType + 1)
        collType.Add GeID
        '
        GeID = m_GeCtrl.GetNextSelObject(GeID)
      Wend
      .CurrentPropertyID = 0  ' reset selector
    End If
    .SelRemoveAll
    .GrabHandlesEnabled = True
    .SendStatusEvents = True
'    .Redraw   ' force redraw to show selection status
    .SelStepIntoGroups = False
  End With

#If timedebug Then
  m_t1 = timeGetTime - m_t1
  ShowDebugMsg m_t1 & " ms to enumerate."
#End If
End Sub

'------------------------------
Private Sub DoSelForSelParams()
  ' actually select based on parameters
  Dim i As Long, j As Long
  Dim GeID As Long
  Dim nTypeSel As Integer
  Dim collType As Collection
  
  On Error Resume Next
  
  If lbSelType.ListIndex < 0 Then Exit Sub
  
  BeginWaitCursor
  
#If timedebug Then
  m_t1 = timeGetTime
#End If
  
  m_GeCtrl.SelRemoveAll
  m_GeCtrl.SelStepIntoGroups = m_bStepIntoGroups
  
  ' statusEvents
  m_GeCtrl.SendStatusEvents = False
  
  ' GrabHandle manipulation and a forced redraw.
  ' is slower than not doing grabhandle stuff for few objects, faster for many objects
  m_GeCtrl.GrabHandlesEnabled = False
 
  '' find type to select ( 0 = all )
  nTypeSel = lbSelType.ItemData(lbSelType.ListIndex)
  '
  
  If nTypeSel = 0 Then    ' all
    For i = 2 To m_collSel.count  ' start  at 2 as 1 holds getype 0
      Set collType = m_collSel.Item(i)
      For j = 1 To collType.count
        GeID = collType.Item(j):      m_GeCtrl.SelAdd GeID
      Next j
    Next i
  Else
    Set collType = m_collSel.Item(nTypeSel + 1)
    For j = 1 To collType.count
      GeID = collType.Item(j):      m_GeCtrl.SelAdd GeID
    Next j
  End If
  '
  m_GeCtrl.GrabHandlesEnabled = True
  m_GeCtrl.Redraw                     ' force a refresh so see grab handles
  
  ' statusEvents
  m_GeCtrl.SendStatusEvents = True
  m_GeCtrl.SelStepIntoGroups = False

#If timedebug Then
  m_t1 = timeGetTime - m_t1
  ShowDebugMsg m_t1 & " ms to select."
#End If

  lblSmartSelCaption.Caption = "Number Selected: " & m_GeCtrl.SelNumberOfObjects
  EndWaitCursor
End Sub
  



