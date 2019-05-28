VERSION 5.00
Object = "{B6C10482-FB89-11D4-93C9-006008A7EED4}#1.0#0"; "TeeChart5.ocx"
Begin VB.Form frmOnChart 
   Caption         =   "Chart"
   ClientHeight    =   5430
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7095
   Icon            =   "frmOnChart.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   5430
   ScaleWidth      =   7095
   StartUpPosition =   3  'Windows Default
   Begin TeeChart.TChart TChart1 
      Height          =   5415
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   7095
      Base64          =   $"frmOnChart.frx":0442
   End
End
Attribute VB_Name = "frmOnChart"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim plotColors(6) As ColorConstants

Private Sub Form_Load()
      
  plotColors(0) = vbBlack
  plotColors(1) = vbBlue
  plotColors(2) = vbGreen
  plotColors(3) = vbRed
  plotColors(4) = vbMagenta
  plotColors(5) = vbWhite
  plotColors(6) = vbCyan
  plotColors(7) = vbYellow

  Dim zoom As IZoom
  Set zoom = TChart1.zoom
  zoom.Enable = True
    
  Dim walls As IWalls
  Set walls = TChart1.walls
  walls.Visible = False
    
  Dim panel As IPanel
  Dim gradient As IGradient
  Set panel = TChart1.panel
  Set gradient = panel.gradient
  gradient.Visible = True
  gradient.StartColor = vbWhite
  gradient.EndColor = vbCyan
  
  Dim legend As ILegend
  Set legend = TChart1.legend
  legend.Visible = True
  Dim la As ELegendAlignment
  la = laTop
  legend.LegendStyle = lsSeries
  legend.Alignment = laTop
    
  Dim aspect As IAspect
  Set aspect = TChart1.aspect
  aspect.View3D = False
    
  Dim titles As ITitles
  Dim sText As IStrings
  Set titles = TChart1.Header
  Set sText = titles.text
  sText.Clear
End Sub

Private Sub Form_Resize()
  TChart1.Move 0, 0, Width, Height
End Sub

Public Sub SetCaption(val As String)
  Caption = val
End Sub

Public Sub AddSeries(Name As String)
  Dim ptr As IPointer
  Dim pen As IPen
  Dim line As ILineSeries
  Dim series As ISeries
  Dim i As Long
  
  TChart1.AddSeries (scLine)
  i = TChart1.SeriesCount - 1
  Set series = TChart1.series(i)
  series.color = plotColors(i)
  If Not IsEmpty(Name) Then
    series.Title = Name
  End If
  series.ShowInLegend = True
  Set line = series.asLine
  Set ptr = line.Pointer
  ptr.Style = psCircle
  ptr.HorizontalSize = 1
  ptr.VerticalSize = 1
  Set pen = ptr.pen
  pen.color = plotColors(i)
End Sub

Public Sub PlotData(time As Double, vars() As Double, count As Long)
  Dim i As Long
  
  For i = 0 To count - 1
    Call TChart1.series(i).AddXY(time, vars(i), "", plotColors(i))
  Next
End Sub

