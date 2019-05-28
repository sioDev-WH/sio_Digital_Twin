VERSION 5.00
Begin VB.UserControl ucMessageWindow 
   AutoRedraw      =   -1  'True
   ClientHeight    =   2115
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   19995
   ScaleHeight     =   2115
   ScaleMode       =   0  'User
   ScaleWidth      =   19995
   Begin VB.ListBox lbMessages 
      Height          =   2010
      Left            =   0
      MultiSelect     =   2  'Extended
      TabIndex        =   0
      Top             =   75
      Width           =   20000
   End
   Begin VB.Image imgSplittler 
      Height          =   75
      Left            =   0
      Top             =   0
      Width           =   19995
   End
   Begin VB.Menu mnuPopup 
      Caption         =   "Popup"
      Visible         =   0   'False
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
Attribute VB_Name = "ucMessageWindow"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Private m_bSizeing As Boolean
Private m_frmActive As ucMain

Private Const c_nNumPopupMenuItems As Integer = 2 ' number of itmes in Popup menu


Public Sub LogMessage(strMsg As String)
    If m_frmActive Is Nothing Then Exit Sub
    If Not m_frmActive.IsMsgWindowVisible Then m_frmActive.ShowMessageWindow
    lbMessages.AddItem strMsg
End Sub

Private Sub imgSplittler_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    m_bSizeing = True
End Sub

Private Sub imgSplittler_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
        Screen.MousePointer = vbSizeNS
End Sub


Private Sub imgSplittler_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Dim newHeight, diffHeight
    Dim picStatusBar As PictureBox
    
    Screen.MousePointer = vbArrow
    If m_frmActive Is Nothing Then Exit Sub
    If m_bSizeing = True Then
        If m_frmActive Is Nothing Then Exit Sub
        newHeight = lbMessages.Height + Y * (-1)
        If newHeight > 0 Then
            lbMessages.Height = newHeight   'This doesn't take the full value being set ????????????????????
            diffHeight = newHeight - lbMessages.Height
            lbMessages.Top = imgSplittler.Height
            lbMessages.Width = UserControl.Width
            imgSplittler.Width = UserControl.Width
            m_frmActive.SizeStatusBar X, Y + diffHeight
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
    Dim newHeight As Integer

    m_bSizeing = False
    imgSplittler.Height = 30
    lbMessages.Width = UserControl.Width
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
      m_DwgEditor.Copy
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


