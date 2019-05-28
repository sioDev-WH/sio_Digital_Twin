VERSION 5.00
Begin VB.UserControl ucPanel 
   CanGetFocus     =   0   'False
   ClientHeight    =   3495
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   2370
   ControlContainer=   -1  'True
   KeyPreview      =   -1  'True
   ScaleHeight     =   3495
   ScaleWidth      =   2370
End
Attribute VB_Name = "ucPanel"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Dim m_CRWhite As OLE_COLOR
Dim m_CRDkGrey As OLE_COLOR
Dim m_OutlineColor As OLE_COLOR
Dim m_BackColor As OLE_COLOR

'----------------------------
Private Sub UserControl_Initialize()
  m_OutlineColor = &H404000   ' dark green
  m_CRWhite = &H8000000E
  m_CRDkGrey = &H80000003
End Sub

'----------------------------
Private Sub UserControl_InitProperties()
  m_OutlineColor = &H404000   ' dark green
  m_BackColor = UserControl.BackColor
End Sub

Private Sub UserControl_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
  Screen.MousePointer = vbArrow
End Sub

'----------------------------
Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
  With PropBag
    m_OutlineColor = .ReadProperty("OutlineColor", &H404000) ' ' dark green by default
    m_BackColor = .ReadProperty("BackColor", vbButtonFace)
    UserControl.BackColor = m_BackColor
  End With
End Sub
'----------------------------
Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
  With PropBag
    .WriteProperty "OutlineColor", m_OutlineColor, &H404000
    .WriteProperty "BackColor", m_BackColor, vbButtonFace
  End With
End Sub

'----------------------------
Public Property Get BackColor() As OLE_COLOR
 'Returns or sets the background color of a Toolbar control.
 BackColor = m_BackColor
End Property
'----------------------------
Public Property Let BackColor(ByVal NewCol As OLE_COLOR)
  m_BackColor = NewCol
  UserControl.BackColor = m_BackColor
  Refresh
  PropertyChanged "BackColor"
End Property
'----------------------------
Public Property Get OutlineColor() As OLE_COLOR
 'Returns or sets the background color of a Toolbar control.
 OutlineColor = m_OutlineColor
End Property
'----------------------------
Public Property Let OutlineColor(ByVal NewCol As OLE_COLOR)
  m_OutlineColor = NewCol
  Refresh
  PropertyChanged "OutlineColor"
End Property


'----------------------------
Private Sub UserControl_Paint()
  Refresh
End Sub

'----------------------------
Private Sub Refresh()
  ' redraw me
  Dim X As Single, Y As Single, W As Single, H As Single, OX As Single, OY As Single
  
  On Error Resume Next
  X = 0#
  Y = 0#
  W = Width - 0#
  H = Height - 0#
  OX = 1 * Screen.TwipsPerPixelX
  OY = 1 * Screen.TwipsPerPixelY
  'erase current
  Line (-1, -1)-(ScaleWidth + 1, ScaleHeight + 1), UserControl.BackColor, BF
  
  ' draw outline
'  UserControl.DrawWidth = 3
'  UserControl.Line (X, Y)-(X + W + 1, Y), m_OutlineColor                   'top
'  UserControl.Line (X + W - OX, Y)-(X + W - OX, Y + H + 1), m_OutlineColor ' right
'  UserControl.Line (X, Y + H - OY)-(X + W + 1, Y + H - OY), m_OutlineColor ' bottom
'  UserControl.Line (X, Y)-(X, Y + H), m_OutlineColor                       ' left
  ' draw outline
'  UserControl.DrawWidth = 3
'  Outline X, Y, X + W - OX, Y + H - OY, m_OutlineColor
  
  ' draw outline
  UserControl.DrawWidth = 1
  ' outer rect
  UserControl.Line (X, Y)-(X, Y + H), m_CRWhite                       ' left
  UserControl.Line (X, Y)-(X + W + 1, Y), m_CRWhite                   'top
  UserControl.Line (X + W - OX, Y)-(X + W - OX, Y + H + 1), m_CRDkGrey ' right
  UserControl.Line (X, Y + H - OY)-(X + W + 1, Y + H - OY), m_CRDkGrey ' bottom
  
  ' inner rect (skip 1 pixel then draw)
  W = W - 2#
  H = H - 2#
  UserControl.Line (X, Y)-(X, Y + H), m_CRDkGrey                       ' left
  UserControl.Line (X, Y)-(X + W + 1, Y), m_CRDkGrey                   'top
  UserControl.Line (X + W - OX, Y)-(X + W - OX, Y + H + 1), m_CRWhite ' right
  UserControl.Line (X, Y + H - OY)-(X + W + 1, Y + H - OY), m_CRWhite ' bottom
  
End Sub

'----------------------------
Private Sub Outline(ByVal X, ByVal Y, ByVal W, ByVal H, C1 As OLE_COLOR)
  UserControl.Line (X, Y)-(X + W + 1, Y), C1                   'top
  UserControl.Line (X + W, Y)-(X + W, Y + H + 1), C1   ' right
  UserControl.Line (X, Y + H)-(X + W + 1, Y + H), C1   ' bottom
  UserControl.Line (X, Y)-(X, Y + H), C1                       ' left
End Sub

