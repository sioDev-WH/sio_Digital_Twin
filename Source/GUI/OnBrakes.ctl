VERSION 5.00
Begin VB.UserControl OnBrakes 
   ClientHeight    =   1800
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   2625
   ScaleHeight     =   1800
   ScaleWidth      =   2625
   Begin VB.PictureBox Picture1 
      Height          =   1575
      Left            =   120
      ScaleHeight     =   1515
      ScaleWidth      =   2235
      TabIndex        =   1
      Top             =   120
      Width           =   2295
   End
   Begin VB.VScrollBar VScroll1 
      Height          =   1575
      Left            =   2400
      TabIndex        =   0
      Top             =   120
      Width           =   135
   End
End
Attribute VB_Name = "OnBrakes"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Dim imageBreaks(13) As IPictureDisp
Private m_Brakes As Double

Public Property Let Brake(val As Double)
  m_Brakes = val
  
  Dim Index As Long
  
  Index = CLng(m_Brakes * 11 / 100)
  Index = Index + 1
  If Index > 12 Then Index = 12
  If Index < 1 Then Index = 1
  Picture1.Picture = imageBreaks(Index)
End Property

Public Property Get Brake() As Double
  Brake = m_Brakes
End Property

Private Sub UserControl_Initialize()
  Dim i As Long
  Dim path As String
  Dim env As OnEnv
  
  On Error GoTo error_handler
  
  Set env = New OnEnv
  path = env.GraphicPath
  For i = 1 To 12
      Set imageBreaks(i) = LoadPicture(path & "Brakes_" & i - 1 & ".bmp")
  Next i
  Picture1.Picture = imageBreaks(1)
  
Exit Sub
error_handler:
  MsgBox "Error initializing brake dialog '" & Err.Description & "'"
 
End Sub

Private Sub VScroll1_Scroll()

Dim Index As Long

   X = (VScroll1.Value - VScroll1.Min) / (VScroll1.Max - VScroll1.Min) ' Size Shape to Scroll Value.
   
   Index = X * 11
   Index = Index + 1
   If Index > 12 Then
   Index = 12
   End If
   
   If Index < 1 Then
   Index = 1
   End If
   
   
   Picture1.Picture = imageBreaks(Index)
   
   m_Brakes = CLng(X * 100)
End Sub
