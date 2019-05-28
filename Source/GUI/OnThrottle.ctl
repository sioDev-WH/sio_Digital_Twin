VERSION 5.00
Begin VB.UserControl OnThrottle 
   ClientHeight    =   2595
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   1635
   ScaleHeight     =   2595
   ScaleWidth      =   1635
   Begin VB.PictureBox Picture1 
      Height          =   2535
      Left            =   0
      ScaleHeight     =   2475
      ScaleWidth      =   1395
      TabIndex        =   1
      Top             =   0
      Width           =   1455
   End
   Begin VB.VScrollBar VScroll1 
      Height          =   2535
      Left            =   1440
      TabIndex        =   0
      Top             =   0
      Width           =   135
   End
End
Attribute VB_Name = "OnThrottle"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Private imageGas(15) As IPictureDisp
Private m_Throttle As Double

Public Property Get Throttle() As Double
  Throttle = m_Throttle
End Property

Public Property Let Throttle(val As Double)
  Dim Index As Long
  
  m_Throttle = val
  VScroll1.Value = (m_Throttle / 100) * (VScroll1.Max - VScroll1.Min) + VScroll1.Min
  Index = m_Throttle / 8
  Index = Index + 1
  If Index > 14 Then Index = 14
  If Index < 1 Then Index = 1
  Picture1.Picture = imageGas(Index)
End Property

Private Sub UserControl_Initialize()
  Dim i As Long
  Dim path As String
  Dim env As OnEnv
  
  On Error GoTo error_handler
  
  m_Throttle = 0
  
  Set env = New OnEnv
  path = env.GraphicPath
  For i = 1 To 15
      Set imageGas(i) = LoadPicture(path & "Gas_" & i - 1 & ".bmp")
  Next i
  Picture1.Picture = imageGas(1)

Exit Sub
error_handler:
  MsgBox "Error initializing throttle dialog '" & Err.Description & "'"
End Sub

Private Sub VScroll1_Scroll()

Dim Index As Long

   X = (VScroll1.Value - VScroll1.Min) / (VScroll1.Max - VScroll1.Min) ' Size Shape to Scroll Value.
   
   Index = X * 13
   Index = Index + 1
   If Index > 14 Then Index = 14
   If Index < 1 Then Index = 1

   Picture1.Picture = imageGas(Index)
   
   m_Throttle = CLng(X * 100)
End Sub

