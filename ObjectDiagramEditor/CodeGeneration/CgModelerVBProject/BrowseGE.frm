VERSION 5.00
Begin VB.Form frmBrowseGE 
   Caption         =   "Browse Selection"
   ClientHeight    =   7125
   ClientLeft      =   1260
   ClientTop       =   5790
   ClientWidth     =   7230
   Icon            =   "BrowseGE.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MinButton       =   0   'False
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   7125
   ScaleWidth      =   7230
   StartUpPosition =   2  'CenterScreen
   Begin VB.PictureBox picToolbar 
      Align           =   1  'Align Top
      BorderStyle     =   0  'None
      Height          =   405
      Left            =   0
      ScaleHeight     =   405
      ScaleWidth      =   7230
      TabIndex        =   15
      Top             =   0
      Width           =   7230
      Begin VB.CommandButton btnOK 
         Caption         =   "Close"
         Height          =   315
         Left            =   5880
         TabIndex        =   19
         Top             =   30
         Width           =   900
      End
      Begin VB.CommandButton btnListUsedShapes 
         Caption         =   "List Used Shapes"
         Height          =   330
         Left            =   60
         TabIndex        =   16
         ToolTipText     =   "List all Shapes in use in the drawing"
         Top             =   15
         Width           =   1395
      End
   End
   Begin VB.PictureBox picTop 
      Height          =   3360
      Left            =   45
      ScaleHeight     =   3300
      ScaleWidth      =   6885
      TabIndex        =   12
      Top             =   420
      Width           =   6945
      Begin VB.ListBox lbError 
         BeginProperty Font 
            Name            =   "Courier New"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   2370
         Left            =   90
         MultiSelect     =   2  'Extended
         TabIndex        =   18
         Top             =   525
         Width           =   6735
      End
      Begin VB.HScrollBar HScroll1 
         Height          =   240
         LargeChange     =   5
         Left            =   150
         Max             =   100
         TabIndex        =   17
         Top             =   2940
         Width           =   6705
      End
      Begin VB.Label lblNumSel 
         AutoSize        =   -1  'True
         Caption         =   "Num Selected"
         Height          =   195
         Left            =   0
         TabIndex        =   14
         Top             =   0
         Width           =   1005
      End
      Begin VB.Label lblHeader 
         AutoSize        =   -1  'True
         Caption         =   "Header"
         BeginProperty Font 
            Name            =   "Courier New"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   270
         Left            =   120
         TabIndex        =   13
         Top             =   240
         Width           =   630
      End
   End
   Begin VB.PictureBox picFrame 
      Height          =   2745
      Left            =   75
      ScaleHeight     =   2685
      ScaleWidth      =   6795
      TabIndex        =   0
      Top             =   3900
      Width           =   6855
      Begin VB.TextBox txtFLDShape 
         Height          =   285
         Left            =   3675
         TabIndex        =   5
         Top             =   2400
         Width           =   2625
      End
      Begin VB.TextBox txtFLDValue 
         Height          =   285
         Left            =   3675
         TabIndex        =   4
         Top             =   2085
         Width           =   2625
      End
      Begin VB.TextBox txtFLDName 
         BackColor       =   &H80000004&
         Height          =   285
         Left            =   3675
         TabIndex        =   3
         Top             =   1785
         Width           =   2625
      End
      Begin VB.CommandButton btnSSApply 
         Caption         =   "Apply"
         Height          =   285
         Left            =   735
         TabIndex        =   2
         Top             =   1890
         Width           =   1230
      End
      Begin VB.ListBox lbItems 
         Height          =   1425
         Left            =   150
         TabIndex        =   1
         Top             =   255
         Width           =   6570
      End
      Begin VB.Label Label4 
         Caption         =   "Smart Shape Fields"
         Height          =   225
         Left            =   300
         TabIndex        =   11
         Top             =   30
         Width           =   1515
      End
      Begin VB.Label lblFLDType 
         AutoSize        =   -1  'True
         Caption         =   "(none)"
         Height          =   195
         Left            =   1575
         TabIndex        =   10
         Top             =   2445
         Width           =   450
      End
      Begin VB.Label Label3 
         Alignment       =   1  'Right Justify
         Caption         =   "Shape Name"
         Height          =   240
         Left            =   2595
         TabIndex        =   9
         Top             =   2430
         Width           =   960
      End
      Begin VB.Label lblFLDTypeA 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "Field Type:"
         Height          =   195
         Left            =   765
         TabIndex        =   8
         Top             =   2445
         Width           =   780
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         Caption         =   "Field Value"
         Height          =   240
         Left            =   2580
         TabIndex        =   7
         Top             =   2115
         Width           =   960
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Field Name"
         Height          =   240
         Left            =   2235
         TabIndex        =   6
         Top             =   1800
         Width           =   1290
      End
   End
End
Attribute VB_Name = "frmBrowseGE"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
' frmBrowseGE
'======================================================================================
Option Explicit
'
'========================================================
'
Dim m_ncLinesVisible As Integer
'
Private m_GeCtrl As CG
Private m_bConstructingList As Boolean
Private m_bConstructingGroup As Boolean

Private m_collFldData As Collection
Private m_nCurGeID As Long

Private m_strDwgName As String  ' name of drawing that loaded this form
Private m_bSelInvalid As Boolean
Private m_nNumShapes As Long

'========================================================
'------------------------------
Public Property Let DrawingName(strName As String)
  m_strDwgName = strName
End Property
'------------------------------
Private Sub btnListUsedShapes_Click()
  DoListUsedShapes
End Sub
'------------------------------
Private Sub DoListUsedShapes()
  ' list those in use in drawing
  Dim aLibraries As Variant
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim i As Integer
  Dim strLibPath As String
  
  On Error Resume Next
  
  If m_GeCtrl Is Nothing Then Exit Sub
  
  m_bSelInvalid = True
  m_nNumShapes = 0
  BeginWaitCursor
  
  m_GeCtrl.GetUsedShapeDefs aLibraries
  
  uBnd = UBound(aLibraries)
  lBnd = LBound(aLibraries)
  
  ' if err, no shapes there
  If Err = 0 Then
    For i = lBnd To uBnd
      strLibPath = aLibraries(i)
      lbError.AddItem strLibPath
      m_nNumShapes = m_nNumShapes + 1
    Next i
  Else
    Err = 0
  End If
  ''
  lblHeader.Caption = "Library ! Folder ! Shape"
  lblNumSel.Caption = m_nNumShapes & " Shapes in Drawing"
  
  EndWaitCursor
  
End Sub


'-------------------------
Public Property Set GeCtrl(obj As CG)
  Set m_GeCtrl = obj
  If Not m_GeCtrl Is Nothing Then DoListSelection
End Property
'-----------------------
Private Sub DoListSelection()
  ' list selection
  EnumSelection
End Sub
'-----------------------
Private Sub EnumSelection()
  ' get info on selection
  Dim aVar As Variant
  Dim iLow As Long
  Dim iHigh As Long
  Dim i As Long
  Dim GeID As Long
  '
  Dim urX As Single, urY As Single, llX As Single, llY As Single
  Dim iType As Integer
  Dim strType As String
  Dim strMsg As String
  Dim strFmt As String
  
  On Error Resume Next
  lbError.Clear
  m_GeCtrl.SelGetObjects aVar ' get sel IDs from CG
  iLow = LBound(aVar)
  iHigh = UBound(aVar)
  If Err <> 0 Then Exit Sub ' if error, then probably nothing in array !
  m_bConstructingList = True
  ''
  ' headers
  strMsg = (iHigh - iLow + 1) & " objects selected"
  lblNumSel.Caption = strMsg
  ' 22 for type
  strMsg = "(ID) and Name of Type  "
  strMsg = strMsg & "ObjID"
  strMsg = strMsg & "  Extents (LLX, LLY, URX, URY)"
  lblHeader.Caption = strMsg
  '
  strFmt = "#########0.00000"
  
  For i = iLow To iHigh
    GeID = aVar(i)
    m_GeCtrl.CurrentPropertyID = GeID  ' move into selector
    m_GeCtrl.GetExtents llX, llY, urX, urY
    iType = m_GeCtrl.ObjectType
    FormatGeType iType, strType
    '
    strMsg = strType & _
            Format(CStr(GeID), "@@@@@") & " "
    
    strMsg = strMsg & _
           " " & Format(llX, strFmt) & _
           "," & Format(llY, strFmt) & _
           "," & Format(urX, strFmt) & _
           "," & Format(urY, strFmt)
    
    lbError.AddItem strMsg
    lbError.ItemData(lbError.NewIndex) = GeID
    
    ' test for exception from CG
    If Err <> 0 Then
      ShowStatusMsg Error
      Exit For
    End If
  Next i
  '
  m_GeCtrl.CurrentPropertyID = 0      ' reset selector
  m_bConstructingList = False
  
End Sub

'------------------------------
Private Sub Form_Initialize()
  Set m_collFldData = New Collection
End Sub

'------------------------------
Private Sub lbError_Click()
  ' changed to new item in LB.
  Dim index As Integer
  Dim nGeID As Long
  Dim iType As Integer
  Dim nLevel As Integer, iFld As Integer
  
  On Error Resume Next
  If m_bConstructingList Or m_bSelInvalid Then Exit Sub
  ConstructFieldList 0, nLevel, iFld      ' clear group
  
  index = lbError.ListIndex
  If index < 0 Then Exit Sub
  nGeID = lbError.ItemData(index)
  If nGeID > 0 Then
    m_GeCtrl.CurrentPropertyID = nGeID  ' move into selector
    iType = m_GeCtrl.ObjectType
    If iType = 21 Or iType = 10 Then   'SmartShape or Shape
      ConstructFieldList nGeID, nLevel, iFld
    End If
  Else
    m_GeCtrl.CurrentPropertyID = 0  ' reset selector
  End If
End Sub

'-----------------------
Private Sub FormatGeType(iType As Integer, strType As String)
  '
  Dim strTmp As String
  strType = GeWorker.GetGeObjectType_Str(iType)
  
  '
  ' 17 & 4 = 21
'  strType = Format(strType, "!@@@@@@@@@@@@@@@@@") ' left aligned
'  strType = strType & "(" & Format(CStr(iType), "@@") & ")"
  
  strTmp = "(" & Format(CStr(iType), "@@") & ")"
  strType = Format(strType, "!@@@@@@@@@@@@@@@@@") ' left aligned
  strType = strTmp & " " & strType
End Sub


'========================================================
'-------------------------
Private Sub ShowStatusMsg(szStatusMsg As String)
  ' show message.
  On Error Resume Next
  ShowOneStatusMsg szStatusMsg
End Sub
'-------------------------
Private Sub ShowOneStatusMsg(szStatusMsg As String)
  Dim nRes As Integer
  
  On Error Resume Next
  lbError.AddItem szStatusMsg
    ' limit the list to 1000 entries
  If lbError.NewIndex > 1000 Then
    lbError.RemoveItem 0
  End If
    ' scroll the list if required
  If lbError.TopIndex + m_ncLinesVisible < lbError.ListCount Then
    nRes = lbError.ListCount - m_ncLinesVisible
    If nRes > 0 And nRes < lbError.ListCount - 1 Then
      lbError.TopIndex = lbError.ListCount - m_ncLinesVisible
    End If
  End If
  ' update the Listbox
  DoEvents
End Sub

'-------------------------
Public Sub ClearStatusMsg()
  lbError.Clear
End Sub

'-------------------------
Private Sub btnOK_Click()
  Unload Me
End Sub

'-------------------------
Private Sub Form_Load()
  On Error Resume Next
  btnSSApply.Enabled = False
End Sub
'-------------------------
Private Sub Form_Unload(Cancel As Integer)
  Dim i As Long
  On Error Resume Next
  If Not m_collFldData Is Nothing Then
    For i = 1 To m_collFldData.count
      m_collFldData.Remove 1
    Next i
  End If
  Set m_collFldData = Nothing
  
  m_GeCtrl.CurrentPropertyID = 0  ' reset selector
  Set m_GeCtrl = Nothing
End Sub

'-------------------------
Private Sub Form_Resize()
  On Error Resume Next
  If WindowState = vbNormal Or WindowState = vbMaximized Then
    
    '' top pic
    picTop.Move 0, picToolbar.Top + picToolbar.Height, Me.ScaleWidth, picTop.Height
    
    HScroll1.Value = 0
    HScroll1.Move 0, picTop.Height - HScroll1.Height - 50, _
        picTop.Width - 50, HScroll1.Height
    
    lbError.Move 0, lblHeader.Top + lblHeader.Height, picTop.Width - 50, _
            picTop.Height - HScroll1.Height - (lblHeader.Top + lblHeader.Height) - 25
    m_ncLinesVisible = GetCountOfVisibleLines(lbError)
    
    ''
    picFrame.Move 0, picTop.Top + picTop.Height, picTop.Width, btnOK.Top - (picTop.Top + picTop.Height) - 200
  
  End If
End Sub

'-------------------------
Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
  Const KEY_CTRL = 2
  ' copy to clipboard on ^C
  If (Shift And KEY_CTRL) And (KeyCode = asc("c") Or KeyCode = asc("C")) Then
    CopyToClipBoard          ' ^C - copy to clipboard
'  ElseIf (Shift And KEY_CTRL) And (KeyCode = Asc("x") Or KeyCode = Asc("X")) Then
'    CopyToClipBoard          ' ^X - copy to clipboard and delete
'    DeleteSelectedRows
'  ElseIf KeyCode = vbKeyDelete Then
'    DeleteSelectedRows       ' Del - delete selected rows
  End If
End Sub

'=========================================================
'=========================================================
'-------------------------
Private Sub CopyToClipBoard()
  Dim szError As String
  Dim nI As Integer
  Dim bFoundFirst As Boolean
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
  On Error GoTo DeleteSelectedRows_Error
  Dim nI As Integer
  If lbError.ListCount > 0 Then
    Do
      If lbError.Selected(nI) Then
        lbError.RemoveItem nI
      Else
        nI = nI + 1
      End If
    Loop While nI < lbError.ListCount
  End If
DeleteSelectedRows_Exit:
  Exit Sub
DeleteSelectedRows_Error:
  Resume DeleteSelectedRows_Exit
End Sub
'-------------------------
Private Sub lbError_KeyDown(KeyCode As Integer, Shift As Integer)
  Form_KeyDown KeyCode, Shift
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
  
 ' nValMove -> + is to right, - is to left
  
  If nValMove > 0 Then ' move pic left
    lbError.Move lbError.Left - nValMove, lbError.Top, lbError.Width, lbError.Height
    lbError.Width = lbError.Width + nValMove
  Else ' move pic right
    lbError.Move lbError.Left - nValMove, lbError.Top, lbError.Width, lbError.Height
    lbError.Width = lbError.Width + nValMove
  
'    If nVal > 0 Then
'        lbError.Move lbError.Left + nValMove, lbError.Top, lbError.Width, lbError.Height
'        lbError.Width = lbError.Width - nValMove
'        If lbError.Left > 0 Then
'          lbError.Move 0, lbError.Top, Me.ScaleWidth, lbError.Height
'        End If
'    Else
'      lbError.Move 0, lbError.Top, lbError.Width, lbError.Height
'      lbError.Width = Me.ScaleWidth
'    End If
  End If
  nLastVal = nVal
End Sub


'=================================================
' Group Details
'=================================================
'------------------------------
Private Sub ConstructFieldList(nGeID As Long, nLevel As Integer, iFld As Integer)
  ' build up LBShapeitems

  Dim strFldName As String
  Dim strFldValue As String
  Dim nFlds As Integer
'  Dim iFld As Integer
  Dim nGeFldType As Integer
  Dim strMsg As String
  Dim strType As String
  
  Dim nGeIDA As Long
  Dim iFldA As Integer
  Dim nLevelA As Integer
  Dim iCnt As Integer

  Dim Info As GeObjectInfo
  
  On Error Resume Next
  
  m_bConstructingGroup = True
  If nGeID = 0 Then lbItems.Clear
  txtFLDName.Text = ""
  txtFLDValue.Text = ""
  lblFLDType.Caption = "" ' "Field Type: "
  btnSSApply.Enabled = False
  
  If nGeID > 0 Then
    ' loop through all objects
    If m_GeCtrl.ShapeSetCurrent(nGeID) Then
      nFlds = m_GeCtrl.ShapeFieldCount
      For iFld = 0 To nFlds - 1
        If m_GeCtrl.ShapeSetCurrentField(iFld) Then
          If m_GeCtrl.ShapeGetFieldNameValue(strFldName, strFldValue) Then
            nGeFldType = m_GeCtrl.ShapeGetFieldType
            Select Case nGeFldType
              Case 2  ' 2 = ShapeField,
                strType = "ShapeField "
              Case 1  ' 1 = TextField, 0 = invalid
                strType = "TextField  "
              Case Else
                strType = "Undefined  "
            End Select
            
              ' ShapeField, get its GeID
            If nGeFldType = 2 Then
              m_GeCtrl.ShapeSelectMember iFld, nGeIDA
              m_GeCtrl.ShapeSetCurrent nGeID
              strMsg = "[" & Format(CStr(nGeIDA), "@@@@@") & " " & _
                        Format(CStr(iFld), "@@@") & ", " & strType & "] " & _
                        strFldName & " : " & strFldValue
            Else
              strMsg = "[" & Format(CStr(nGeID), "@@@@@") & " " & _
                        Format(CStr(iFld), "@@@") & ", " & strType & "] " & _
                        strFldName & " : " & strFldValue
            End If
            
            
            ' indent
            For iCnt = 1 To nLevel
              strMsg = vbTab & strMsg
            Next iCnt
            
            Set Info = New GeObjectInfo
            m_collFldData.Add Info
            Info.GeID = nGeID
            Info.iFld = iFld
            Info.strFldName = strFldName
            Info.strFldValue = strFldValue
            
            lbItems.AddItem strMsg
            lbItems.ItemData(lbItems.NewIndex) = m_collFldData.count  'iFld
            
            
              ' ShapeField, step into it as well
            If nGeFldType = 2 Then
              If m_GeCtrl.ShapeSelectMember(iFld, nGeIDA) Then
                iFldA = iFld
                nLevelA = nLevel + 1
                ConstructFieldList nGeIDA, nLevelA, iFldA
                ' reset back
                m_GeCtrl.ShapeSetCurrent nGeID
              End If
            End If
            
          End If
        End If
      Next iFld
    End If
  End If
  ''
  If nLevel = 0 Then m_bConstructingGroup = False
End Sub

'------------------------------
Private Sub btnSSApply_Click()
  Dim strFldShape As String
  Dim strMsg As String
  Dim nGeFldType As Integer
  Dim strFldValue As String
  
  
  On Error Resume Next
  If m_nCurGeID > 0 Then
    nGeFldType = GetCurrentFieldType
    
    ' invalidate before change so redraws correctly in this static mode
    m_GeCtrl.InvalidateObjectBefore m_nCurGeID
    
    ' ShapeField -  change shape instance
    If nGeFldType = 2 Then
      strFldShape = txtFLDShape.Text
      If Not m_GeCtrl.ShapeSetFieldShape(strFldShape) Then
        strMsg = "Failed to Change shape because " & Error & " !"
        MsgBox strMsg
      End If
      
      ' refresh with what actually happened
      m_GeCtrl.ShapeGetFieldShape strFldShape
      txtFLDShape.Text = strFldShape
    
    End If
    
    ' text field and Field string value for a Shape
    strFldValue = txtFLDValue.Text
    m_GeCtrl.ShapeSetFieldValue strFldValue
      
      ' invalidate if changed
    m_GeCtrl.InvalidateObjectAfter m_nCurGeID
  
  End If
End Sub

'------------------------------
Private Sub UpdateGroupFieldData(Info As GeObjectInfo)
  On Error Resume Next
  Dim strFldName As String
  Dim strFldValue As String
  Dim strFldShape As String
  Dim nGeFldType As Integer
  Dim strType As String
  Dim iFld As Integer
  
  On Error Resume Next
  
  txtFLDName.Text = ""
  txtFLDValue.Text = ""
  txtFLDShape.Text = ""
  txtFLDShape.Enabled = False
  txtFLDShape.BackColor = &H80000004  ' grey
  lblFLDType.Caption = ""
  btnSSApply.Enabled = False
  
  If Info Is Nothing Then Exit Sub
  m_nCurGeID = Info.GeID
  iFld = Info.iFld
  
  If m_nCurGeID > 0 Then
    ' loop through all objects
    If m_GeCtrl.ShapeSetCurrent(m_nCurGeID) Then
      If m_GeCtrl.ShapeSetCurrentField(iFld) Then
        If m_GeCtrl.ShapeGetFieldNameValue(strFldName, strFldValue) Then
          strFldShape = ""
          nGeFldType = m_GeCtrl.ShapeGetFieldType
          Select Case nGeFldType
            Case 2  ' 2 = ShapeField,
              strType = "ShapeField"
              m_GeCtrl.ShapeGetFieldShape strFldShape
              txtFLDShape.Enabled = True
              txtFLDShape.BackColor = &H80000005  ' white
              btnSSApply.Enabled = True
            Case 1  ' 1 = TextField, 0 = invalid
              strType = "TextField"
              btnSSApply.Enabled = True
            Case Else
              strType = "Undefined"
          End Select
          '
          txtFLDName.Text = strFldName
          txtFLDValue.Text = strFldValue
          txtFLDShape.Text = strFldShape
          lblFLDType.Caption = strType
        End If
      End If
    End If
  End If

End Sub
'------------------------------
Private Function GetCurrentFieldType() As Integer
  Dim nGeFldType As Integer
  On Error Resume Next
  If m_nCurGeID > 0 Then nGeFldType = m_GeCtrl.ShapeGetFieldType
  GetCurrentFieldType = nGeFldType

End Function
'------------------------------
Private Sub lbItems_Click()
  ' changed to new item in LB.
  Dim index As Integer
  Dim nFld As Integer
  Dim Info As GeObjectInfo
  
  On Error Resume Next
  If m_bConstructingGroup Then Exit Sub
  m_nCurGeID = 0
  index = lbItems.ListIndex
  If index < 0 Then Exit Sub
  
  nFld = lbItems.ItemData(index)
  Set Info = m_collFldData.Item(nFld)
  UpdateGroupFieldData Info

End Sub


'*********************************************************
#If 0 Then
'----------------------------
Private Sub GetNamesOfShapes()
  Dim GeID As Long
  Dim nGeType As Integer
  Dim strPathFolder As String
  Dim strShape As String
  Dim strMsg As String
  
  On Error Resume Next
  ' walk all objects looking for shapes
  
  GeID = SourceShapeGe.GetFirstSelObject
  While GeID > 0
    SourceShapeGe.CurrentPropertyID = GeID  ' move into selector
    nGeType = SourceShapeGe.ObjectType
    If nGeType = EGeObjType.Shape Or _
       nGeType = EGeObjType.UserGroup _
    Then
      If SourceShapeGe.ShapeSetCurrent(GeID) Then
        
        strPathFolder = SourceShapeGe.ShapePath   ' Returns File.mdb!Folder
        strShape = SourceShapeGe.ShapeName
        
        strMsg = strPathFolder & "!" & strShape
        lbError.AddItem strMsg
        m_nNumShapes = m_nNumShapes + 1
        '
      End If
    End If
    GeID = SourceShapeGe.GetNextSelObject(GeID)
  Wend
End Sub

'----------------------------
Private Function EnumUsedShapes() As Boolean
  Dim GeID As Long
  Dim nFirstCount As Integer
  Dim nNextCount As Integer
  Dim nGeType As Integer
  Dim bGroup As Boolean
  Dim bDoIt As Boolean
  
  On Error Resume Next
  
  EnumUsedShapes = False
  lbError.Clear
  
  BeginWaitCursor
  SourceShapeGe.GrabHandlesEnabled = False
  SourceShapeGe.SelStepIntoGroups = True
  ''
  SourceShapeGe.SelAddAll
  If SourceShapeGe.SelNumberOfObjects > 0 Then
    nFirstCount = -1
      'keep exploding until there is no more to explode
    While nNextCount <> nFirstCount
      SourceShapeGe.SelAddAll
      bDoIt = False
        ' see if shape or smartshape (usergroup)
      If SourceShapeGe.CanExplodeShape Then
        bDoIt = True
      ElseIf SourceShapeGe.CanExplodeSmartShape Then
        bDoIt = True
        bGroup = True
      End If
      '
      If bDoIt Then
        nFirstCount = SourceShapeGe.SelNumberOfObjects
          ' go find name of current shapes
        GetNamesOfShapes
        
        If bGroup Then
          SourceShapeGe.Ungroup
        Else
          SourceShapeGe.OnExplodeShape
        End If
          ' go find name of current shapes
'        GetNamesOfShapes
        nNextCount = SourceShapeGe.SelNumberOfObjects
      Else
        nNextCount = nFirstCount
      End If
    Wend
  End If
  SourceShapeGe.SelRemoveAll
  SourceShapeGe.GrabHandlesEnabled = True
  EndWaitCursor
  
  '
  If lbError.ListCount > 0 Then
    EnumUsedShapes = True
  Else
    EnumUsedShapes = False
  End If
End Function
#End If
'*********************************************************




