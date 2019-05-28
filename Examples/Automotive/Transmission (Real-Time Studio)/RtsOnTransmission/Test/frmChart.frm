VERSION 5.00
Object = "{008BBE7B-C096-11D0-B4E3-00A0C901D681}#1.0#0"; "TeeChart.ocx"
Begin VB.Form frmChart 
   Caption         =   "Form2"
   ClientHeight    =   5220
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6660
   LinkTopic       =   "Form2"
   ScaleHeight     =   5220
   ScaleWidth      =   6660
   StartUpPosition =   3  'Windows Default
   Begin TeeChart.TChart TChart1 
      Height          =   5055
      Left            =   120
      OleObjectBlob   =   "frmChart.frx":0000
      TabIndex        =   0
      Top             =   120
      Width           =   6495
   End
End
Attribute VB_Name = "frmChart"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Sub addSeries(SeriesName As String)
  Dim aSeries As ISeries
  TChart1.addSeries (scLine)
  Set aSeries = TChart1.Series(TChart1.SeriesCount - 1)
  aSeries.Title = SeriesName
End Sub

Public Sub SetCaption(dlgcaption As String)
  Me.Caption = dlgcaption
End Sub

Public Sub GetPosition(x As Long, y As Long, nWidth As Long, nHeight As Long)
  x = Me.Left
  y = Me.Top
  nWidth = Me.Width
  nHeight = Me.Height
End Sub

Public Sub plotSeriesData(t As Double, val As Double)
  Dim pSeries As ISeries
  Dim i As Long
  
  If TChart1 Is Nothing Then Exit Sub
  
  i = TChart1.SeriesCount
  
  If i = 0 Then Exit Sub
  Set pSeries = TChart1.Series(i - 1)
  pSeries.AddXY t, val, "", 0
End Sub

Public Sub cleanPlot()

End Sub

Public Sub initPlot(VarCount As Long, points As Boolean, SeriesNames() As String)
  Dim i As Long
  
  For i = 1 To VarCount
    addSeries SeriesNames(i - 1)
  Next i
End Sub

Public Sub plotData(simTime As Double, VarVals() As Double, VarCount As Long)

End Sub

Private Sub Form_Load()
  TChart1.Aspect.View3D = False
  TChart1.Legend.Alignment = laTop
  TChart1.Legend.LegendStyle = lsSeries
  TChart1.Zoom.Enable = True
  TChart1.Walls.Visible = False
  TChart1.Panel.Gradient.Visible = False
End Sub

Private Sub Form_Resize()
  On Error Resume Next
  TChart1.Left = 0
  TChart1.Top = 0
  TChart1.Width = ScaleWidth
  TChart1.Height = ScaleHeight
End Sub
