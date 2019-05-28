VERSION 5.00
Begin VB.Form GasContainer 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Throttle"
   ClientHeight    =   4215
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   3855
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4215
   ScaleWidth      =   3855
   StartUpPosition =   3  'Windows Default
   Begin VB.VScrollBar VScroll1 
      Height          =   2535
      Left            =   1680
      TabIndex        =   1
      Top             =   120
      Width           =   135
   End
   Begin VB.PictureBox Picture1 
      Height          =   2535
      Left            =   120
      ScaleHeight     =   2475
      ScaleWidth      =   1395
      TabIndex        =   0
      Top             =   120
      Width           =   1455
   End
End
Attribute VB_Name = "GasContainer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim imageGas(15) As IPictureDisp
Public Throttle As Double


Private Sub Form_Load()
Dim i As Long
Dim path As String

path = "C:\DistComponents\GUI\"
For i = 1 To 15
    Set imageGas(i) = LoadPicture(path & "Gas_" & i - 1 & ".bmp")
Next i
Picture1.Picture = imageGas(1)
End Sub

Private Sub VScroll1_Scroll()

Dim Index As Long

   X = (VScroll1.Value - VScroll1.Min) / (VScroll1.Max - VScroll1.Min) ' Size Shape to Scroll Value.
   
   Index = X * 13
   Index = Index + 1
   If Index > 14 Then
   Index = 14
   End If
   
   If Index < 1 Then
   Index = 1
   End If
   
   
   Picture1.Picture = imageGas(Index)
   
   Throttle = CLng(X * 100)
End Sub
