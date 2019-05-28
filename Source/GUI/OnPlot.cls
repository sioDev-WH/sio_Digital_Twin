VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "OnPlotObject"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Dim container As chartContainer

Dim PlotColors(10) As OLE_COLOR
Dim TChart As TChart
Dim bDone As Boolean

Private Sub Class_Initialize()
  Set container = New chartContainer
  On Error Resume Next
  container.Show
  If Err <> 0 Then
    MsgBox "Error: " & Err.Number & ", " & Err.Description
  End If
End Sub

Private Sub Class_Terminate()
  On Error Resume Next
  Unload container
  Set container = Nothing
End Sub

Public Sub initPlot(numberOfSeries As Long, bPoint As Boolean)
Dim i As Long

    PlotColors(1) = vbMagenta
    PlotColors(2) = vbYellow
    PlotColors(3) = vbGreen
    PlotColors(4) = vbBlue
    PlotColors(5) = vbBlack
    PlotColors(6) = vbRed
    
    Set TChart = container.TChart
    TChart.RemoveAllSeries
    With TChart
        For i = 1 To numberOfSeries
            If Not bPoint Then
                .AddSeries scLine
                .Series(i - 1).asLine.Pointer.Style = psCircle
                .Series(i - 1).asLine.Pointer.HorizontalSize = 1
                .Series(i - 1).asLine.Pointer.VerticalSize = 1
                .Series(i - 1).asLine.Pointer.Pen.Color = vbRed
            Else
                .AddSeries scPoint
                .Series(i - 1).asPoint.Pointer.Style = psCircle
                .Series(i - 1).asPoint.Pointer.HorizontalSize = 2
                .Series(i - 1).asPoint.Pointer.VerticalSize = 2
                .Series(i - 1).asPoint.Pointer.Pen.Color = vbRed
            End If
        Next i
    End With

    'container.Show
    
    bDone = False
End Sub

Public Sub plotData(Vars() As Double, numberOfVars As Long)

  On Error GoTo error_exit
  
  Dim i As Long
  If Not bDone Then
    With TChart
      For i = 1 To numberOfVars - 1
        .Series(i - 1).AddXY Vars(1), Vars(i + 1), "", PlotColors(i)
      Next i
    End With
  End If

  Exit Sub
  
error_exit:
  Exit Sub
  
End Sub

Public Sub cleanPlot()
  bDone = True
  On Error Resume Next
  Unload container
End Sub

