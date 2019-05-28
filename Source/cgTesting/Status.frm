VERSION 5.00
Begin VB.Form frmStatus 
   Caption         =   "Messages"
   ClientHeight    =   2805
   ClientLeft      =   1260
   ClientTop       =   5790
   ClientWidth     =   7500
   Icon            =   "Status.frx":0000
   LinkTopic       =   "Form1"
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   2805
   ScaleWidth      =   7500
   Begin VB.HScrollBar HScroll1 
      Height          =   240
      LargeChange     =   5
      Left            =   45
      Max             =   100
      TabIndex        =   1
      Top             =   2475
      Width           =   7215
   End
   Begin VB.ListBox lbError 
      Height          =   2400
      Left            =   0
      MultiSelect     =   2  'Extended
      TabIndex        =   0
      Top             =   0
      Width           =   7215
   End
End
Attribute VB_Name = "frmStatus"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
'
'======================================================================================
Option Explicit



'
'========================================================
'

Dim m_ncLinesVisible As Integer
Private m_bDeferredMsg As Boolean   ' message deferred to next call to Show
Private m_aDeferredMsg() As String  ' deferred messages
Private m_nDeferredMsg As Integer
'
'========================================================
'-------------------------
Private Sub AddDeferredMsg(strMsg As String)
  Dim nArrayBound As Integer
  
  On Error Resume Next
    ' reasonablity check
  If m_nDeferredMsg > 500 Then Exit Sub
  
  nArrayBound = UBound(m_aDeferredMsg)
  If err <> 0 Or m_nDeferredMsg = nArrayBound Then
    ReDim Preserve m_aDeferredMsg(m_nDeferredMsg + 10) As String
  End If
  ' Add to array
  m_aDeferredMsg(m_nDeferredMsg) = strMsg
  m_nDeferredMsg = m_nDeferredMsg + 1
End Sub

'-------------------------
Private Sub ShowDeferredMsg()
  ' dump deferred messages. Reset array.
  Dim i As Integer
  For i = 0 To m_nDeferredMsg - 1
    ShowOneStatusMsg m_aDeferredMsg(i)
  Next i
  ReDim m_aDeferredMsg(10) As String
  m_nDeferredMsg = 0
End Sub
'-------------------------
Public Sub ShowStatusMsg(szStatusMsg As String)
  ' show message.
  On Error Resume Next
  If m_bDeferredMsg Then
    m_bDeferredMsg = False
    Show
      ' If Err = 401 Then ' Can't show non modal form when modal form is active
    If err <> 0 Then
      AddDeferredMsg szStatusMsg
      m_bDeferredMsg = True
      Exit Sub
    End If
    ShowDeferredMsg
  End If
  ShowOneStatusMsg szStatusMsg
  ' New Message Windw
  'gMsgWnd.LogMessage szStatusMsg
End Sub

Public Sub ShowStatusMsgWindow()
  ' show message window
  On Error Resume Next
  If WindowState = vbMinimized Then
    WindowState = vbNormal
  Else
    WindowState = vbMinimized
  End If
End Sub

'-------------------------
Private Sub ShowOneStatusMsg(szStatusMsg As String)
  Dim nRes As Integer
  lbError.AddItem szStatusMsg
    ' limit the list to 1000 entries
  If lbError.NewIndex > 1000 Then
    lbError.RemoveItem 0
  End If
  If WindowState = vbMinimized Then
    WindowState = vbNormal
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
Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
  Const KEY_CTRL = 2
  ' copy to clipboard on ^C
  If (Shift And KEY_CTRL) And (KeyCode = Asc("c") Or KeyCode = Asc("C")) Then
    CopyToClipBoard          ' ^C - copy to clipboard
  ElseIf (Shift And KEY_CTRL) And (KeyCode = Asc("x") Or KeyCode = Asc("X")) Then
    CopyToClipBoard          ' ^X - copy to clipboard and delete
    DeleteSelectedRows
  ElseIf KeyCode = vbKeyDelete Then
    DeleteSelectedRows       ' Del - delete selected rows
  End If
End Sub

'-------------------------
Private Sub Form_Load()
  On Error Resume Next
  Show
  If err <> 0 Then
'    If Err = 401 Then ' Can't show non modal form when modal form is active
      m_bDeferredMsg = True
'    End If
  End If
End Sub

'-------------------------
Private Sub Form_Resize()
  On Error Resume Next
  If WindowState = vbNormal Or WindowState = vbMaximized Then
    HScroll1.Value = 0
    HScroll1.Move 0, ScaleHeight - HScroll1.Height, _
        Me.ScaleWidth, HScroll1.Height
    
    lbError.Move 0, 0, Me.ScaleWidth, _
            Me.ScaleHeight - HScroll1.Height - 25
    
    m_ncLinesVisible = GetCountOfVisibleLines(lbError)
  End If
End Sub

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
          lbError.Move 0, lbError.Top, Me.ScaleWidth, lbError.Height
        End If
    Else
      lbError.Move 0, lbError.Top, lbError.Width, lbError.Height
      lbError.Width = Me.ScaleWidth
    End If
  End If
    
  
  
#If 0 Then
  If nVal > nLastVal Then ' move pic left
    lbError.Move lbError.Left - nDX, lbError.Top, lbError.Width, lbError.Height
    lbError.Width = lbError.Width + nDX
  Else
    If nVal > 0 Then
        lbError.Move lbError.Left + nDX, lbError.Top, lbError.Width, lbError.Height
        lbError.Width = lbError.Width - nDX
        If lbError.Left > 0 Then
          lbError.Move 0, lbError.Top, Me.ScaleWidth, lbError.Height
        End If
    Else
      lbError.Move 0, lbError.Top, lbError.Width, lbError.Height
      lbError.Width = Me.ScaleWidth
    End If
  End If
#End If

  nLastVal = nVal
End Sub



