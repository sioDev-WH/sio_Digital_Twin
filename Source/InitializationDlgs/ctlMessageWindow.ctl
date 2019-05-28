VERSION 5.00
Begin VB.UserControl ctlMessageWindow 
   ClientHeight    =   2775
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   6375
   ScaleHeight     =   2775
   ScaleWidth      =   6375
   Begin VB.ListBox lbMessages 
      Height          =   2010
      ItemData        =   "ctlMessageWindow.ctx":0000
      Left            =   0
      List            =   "ctlMessageWindow.ctx":0002
      MultiSelect     =   2  'Extended
      TabIndex        =   0
      Top             =   75
      Width           =   6000
   End
   Begin VB.Image imgSplitter 
      Height          =   75
      Left            =   0
      Top             =   0
      Width           =   6000
   End
   Begin VB.Menu mnuPopup 
      Caption         =   "Popup"
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item0"
         Index           =   0
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item1"
         Index           =   1
      End
   End
End
Attribute VB_Name = "ctlMessageWindow"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_bSizeing As Boolean
Private m_frmActive As Object
Private Const c_nNumPopupMenuItems As Integer = 2 ' number of itmes in Popup menu

Public Sub Destroy()
  Set m_frmActive = Nothing
End Sub

Public Sub LogMessage(strMsg As String)
    If m_frmActive Is Nothing Then Exit Sub
    If Not m_frmActive.IsMsgWindowVisible Then m_frmActive.ShowMessageWindow
    lbMessages.AddItem strMsg
End Sub

Private Sub imgSplitter_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    m_bSizeing = True
End Sub

Private Sub imgSplitter_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Screen.MousePointer = vbSizeNS
End Sub


Private Sub imgSplitter_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Dim newHeight As Long
    Dim picStatusBar As PictureBox
    
    Screen.MousePointer = vbArrow
    If m_frmActive Is Nothing Then Exit Sub
    If m_bSizeing = True Then
        newHeight = lbMessages.Height + Y * (-1)
        If newHeight > 0 Then
            m_frmActive.SizeStatusBar newHeight
        End If
    End If
    m_bSizeing = False
End Sub

Private Sub lbMessages_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button = 2 Then  ' Right Button
        DoPopupMenu
    End If
End Sub

Private Sub lbMessages_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Screen.MousePointer = vbArrow
End Sub

Private Sub UserControl_Initialize()
    On Error Resume Next
    m_bSizeing = False
    imgSplitter.Height = 30
End Sub

Private Sub DoPopupMenu()
  Dim mnu As Menu
  Dim mnuItem As Menu
  Dim i As Integer
  Dim bSel As Boolean
  
  On Error Resume Next
  Set mnu = mnuPopup
  For i = 0 To c_nNumPopupMenuItems - 1
    Set mnuItem = mnuPopupItem(i)
    mnuItem.Visible = True
    Select Case i
      Case 0
        mnuItem.Caption = "Copy" & vbTab & "Ctrl+C"
     Case 1
         mnuItem.Caption = "Clear" & vbTab & "Ctrl+D"
     Case Else
        mnuItem.Visible = False
    End Select
  Next i
  PopupMenu mnu
End Sub

Private Sub CopyToClipBoard()
  Dim strClipData As String
  Dim i As Integer
  
  strClipData = ""
  Clipboard.Clear
  For i = 1 To lbMessages.ListCount
   strClipData = strClipData + lbMessages.List(i) + Chr$(13) + Chr$(10)
  Next
  Clipboard.SetText strClipData
End Sub


Private Sub mnuPopupItem_Click(Index As Integer)
  On Error Resume Next
  
  Select Case Index
    Case 0  ' Copy
      CopyToClipBoard
    Case 1  ' Copy
      lbMessages.Clear
    Case Else
      Exit Sub
  End Select
End Sub

Public Sub ClearMessageWindow()
    lbMessages.Clear
End Sub

Public Sub MaximizeMessageWindow(ucHeight As Integer, ucWidth As Integer)
    lbMessages.Height = ucHeight
    lbMessages.Width = ucWidth
End Sub

Public Property Set ActiveForm(obj As Object)
  Set m_frmActive = obj
End Property

Private Sub UserControl_Resize()
  imgSplitter.Move 0, 0, Width, 75
  lbMessages.Move 0, imgSplitter.Height, Width, Height - imgSplitter.Height
End Sub
