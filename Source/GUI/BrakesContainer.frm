VERSION 5.00
Begin VB.Form BrakesContainer 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Breaks"
   ClientHeight    =   3975
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   2760
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3975
   ScaleWidth      =   2760
   StartUpPosition =   3  'Windows Default
   Begin VB.VScrollBar VScroll1 
      Height          =   1575
      Left            =   2520
      TabIndex        =   1
      Top             =   120
      Width           =   135
   End
   Begin VB.PictureBox Picture1 
      Height          =   1575
      Left            =   120
      ScaleHeight     =   1515
      ScaleWidth      =   2235
      TabIndex        =   0
      Top             =   120
      Width           =   2295
   End
End
Attribute VB_Name = "BrakesContainer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim imageBreaks(13) As IPictureDisp
Public Brakes As Double

Private Sub Form_Load()
Dim i As Long
Dim path As String

path = "C:\DistComponents\GUI\"
For i = 1 To 12
    Set imageBreaks(i) = LoadPicture(path & "Brakes_" & i - 1 & ".bmp")
Next i
Picture1.Picture = imageBreaks(1)
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
   
   Brakes = CLng(X * 100)
End Sub

