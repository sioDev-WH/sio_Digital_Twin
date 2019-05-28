VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "vbChart"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Name As String
Private m_VarIndices() As Long
Private m_VarCount As Long
Private m_VarVals() As Double
Private m_Chart As frmChart 'OnChart
Private m_SeriesNames() As String

Public Sub cleanPlot()
  m_Chart.cleanPlot
End Sub

Private Sub Class_Initialize()
  Set m_Chart = New frmChart ' New OnChart
  m_Chart.Show
End Sub

Public Sub addSeries(SeriesName As String)
  m_Chart.addSeries SeriesName
End Sub

Public Sub Load(fh As Long)
  Dim i As Long
  Dim x As Long
  Dim y As Long
  Dim nWidth As Long
  Dim nHeight As Long
  
  ' update the name
  Input #fh, m_Name
  m_Chart.SetCaption m_Name
  
  ' update the position of the dialog
  Input #fh, x
  Input #fh, y
  Input #fh, nWidth
  Input #fh, nHeight
  m_Chart.Move x, y, nWidth, nHeight
  
  ' get the variable count
  Input #fh, m_VarCount
  
  ' import the series names
  ReDim m_SeriesNames(m_VarCount) As String
  For i = 0 To m_VarCount - 1
    Input #fh, m_SeriesNames(i)
  Next i
  
  ' initialize the chart
  m_Chart.initPlot m_VarCount, False, m_SeriesNames
  
  ' dimension the var indices and var vals arrays
  If m_VarCount > 1 Then
    ReDim m_VarIndices(m_VarCount - 1) As Long
    ReDim m_VarVals(m_VarCount - 1) As Double
  Else
    ReDim m_VarIndices(m_VarCount) As Long
    ReDim m_VarVals(m_VarCount) As Double
  End If
  
  ' import the var indices vector
  For i = 0 To m_VarCount - 1
    Input #fh, m_VarIndices(i)
  Next i

End Sub

Public Sub Save(fh As Long)
  Dim i As Long
  Dim x As Long
  Dim y As Long
  Dim nWidth As Long
  Dim nHeight As Long
  
  ' update the name
  Write #fh, m_Name
  
  ' record the position of the dialog
  m_Chart.GetPosition x, y, nWidth, nHeight
  Write #fh, x
  Write #fh, y
  Write #fh, nWidth
  Write #fh, nHeight
  
  Write #fh, m_VarCount
  For i = 0 To m_VarCount - 1
    Write #fh, m_SeriesNames(i)
  Next i
  For i = 0 To m_VarCount - 1
    Write #fh, m_VarIndices(i)
  Next i
End Sub

Public Property Get Name() As String
  Name = m_Name
End Property

Public Property Let Name(newName As String)
  m_Name = newName
  m_Chart.SetCaption newName
End Property

Public Sub tick(simTime As Double)
  If m_Chart Is Nothing Then Exit Sub
  
  If Not m_M Is Nothing Then
    m_M.GetVariables m_VarIndices, simTime, m_VarVals
    If m_VarCount = 1 Then
      m_Chart.plotSeriesData simTime, m_VarVals(0)
    Else
      m_Chart.plotData simTime, m_VarVals, m_VarCount
    End If
  End If
End Sub

Public Sub SetVars(indices() As Long, SeriesNames() As String, count As Long)
  Dim i As Long
  
  ' size the number of variables
  m_VarCount = count
  
  ' clone the series name vector
  ReDim m_SeriesNames(count) As String
  For i = 0 To count
    m_SeriesNames(i) = SeriesNames(i)
  Next i
  
  ' initialize the chart
  m_Chart.initPlot m_VarCount, False, SeriesNames
  If m_VarCount > 1 Then
    ReDim m_VarIndices(m_VarCount - 1) As Long
    ReDim m_VarVals(m_VarCount - 1) As Double
  Else
    ReDim m_VarIndices(m_VarCount) As Long
    ReDim m_VarVals(m_VarCount) As Double
  End If
  
  ' clone the var indices vector
  For i = 0 To m_VarCount - 1
    m_VarIndices(i) = indices(i)
  Next i
End Sub

Private Sub Class_Terminate()
  If Not m_Chart Is Nothing Then
    Unload m_Chart
  End If
End Sub
