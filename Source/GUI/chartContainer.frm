VERSION 5.00
Object = "{008BBE7B-C096-11D0-B4E3-00A0C901D681}#1.0#0"; "TeeChart.ocx"
Begin VB.Form chartContainer 
   Caption         =   "OnPlot"
   ClientHeight    =   3780
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3960
   LinkTopic       =   "Form1"
   ScaleHeight     =   3780
   ScaleWidth      =   3960
   StartUpPosition =   3  'Windows Default
   Begin TeeChart.TChart TChart 
      Height          =   3495
      Left            =   120
      OleObjectBlob   =   "chartContainer.frx":0000
      TabIndex        =   0
      Top             =   120
      Width           =   3615
   End
End
Attribute VB_Name = "chartContainer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Form_Resize()
  TChart.Left = 0
  TChart.Top = 0
  TChart.Width = Me.ScaleWidth
  TChart.Height = Me.ScaleHeight
End Sub
