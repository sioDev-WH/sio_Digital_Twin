VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "OnPlotDlgMgr"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_Brakes As frmOnBrakes
Private m_ShiftLever As frmOnShiftLever
Private m_Throttle As frmOnShiftLever
Private m_Chart As frmOnChart

Private Sub Class_Initialize()
  Set m_Brakes = New frmOnBrakes
  Set m_ShiftLever = New frmOnShiftLever
  Set m_Throttle = New frmOnShiftLever
  Set m_Chart = New frmOnChart
End Sub

Private Sub Class_Terminate()
  Set m_Brakes = Nothing
  Set m_ShiftLever = Nothing
  Set m_Throttle = Nothing
  Set m_Chart = Nothing
End Sub

Public Sub ShowBrakes()
  m_Brakes.Show
End Sub

Public Sub ShowThrottle()
  m_Throttle.Show
End Sub

Public Sub ShowShiftLever()
  m_ShiftLever.Show
End Sub

Public Sub ShowChart()
  m_Chart.Show
End Sub

Public Property Let BrakeCaption(val As String)
  m_Brakes.Caption = val
End Property

Public Property Let ThrottleCaption(val As String)
  m_Throttle.Caption = val
End Property

Public Property Let ShiftLeverCaption(val As String)
  m_ShiftLever.Caption = val
End Property

Public Property Let ChartCaption(val As String)
  m_Chart.Caption = val
End Property

Public Property Let BrakeVal(val As Double)
  m_Brakes.Brake = val
End Property

Public Property Get BrakeVal() As Double
  BrakeVal = m_Brakes.Brake
End Property

Public Property Let ShiftLeverVal(val As Long)
  m_ShiftLever.Position = val
End Property

Public Property Get ShiftLeverVal() As Long
  ShiftLeverVal = m_ShiftLever.Position
End Property

Public Property Let ThrottleVal(val As Double)
  m_Throttle.Position = val
End Property

Public Property Get ThrottleVal() As Double
  ThrottleVal = m_Throttle.Position
End Property

Public Sub ChartAddSeries(Name As String)
  m_Chart.AddSeries Name
End Sub

Public Sub ChartPlotData(time As Double, vars() As Double, count As Long)
  m_Chart.PlotData time, vars(), count
End Sub


