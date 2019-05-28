Attribute VB_Name = "Module1"
Option Explicit

Global m_M As IsDaeEsoCImpl
Global m_Charts As Collection
Global simTime As Double
Global th As COnTestHarness
Global bPause As Boolean

Global startTime As Double
Global endTime As Double
Global stepSize As Double

Global bMCPause As Boolean
Global bMCRun As Boolean

Global MCParameterIndex As Long
Global MCstartTime As Double
Global MCendTime As Double
Global MCstepSize As Double
Global MCSnapshot As String
Global MCLowRange As Double
Global MCHighRange As Double
Global MCIncrements As Long
Global MCRuntime As Double


Public Sub initSim()
  simTime = startTime
  Set m_Charts = New Collection
  Set th = New COnTestHarness
  th.init
  Set m_M = th.model
  th.tick simTime
  th.Save "initial_conditions"
End Sub

Public Sub runSim()
  bPause = False
  Dim aChart As vbChart
  
  On Error Resume Next
  While simTime < endTime And Not bPause
    th.tick simTime
    For Each aChart In m_Charts
      aChart.tick simTime
    Next
    simTime = simTime + 0.01 'stepSize
    DoEvents
    
  Wend
End Sub

Public Sub runMCSim()
  Dim inc As Long
  Dim aChart As vbChart
  Dim val As Double
  
  bMCPause = False
  bMCRun = True
  
  On Error Resume Next
  For inc = 0 To MCIncrements
    For Each aChart In m_Charts
      aChart.addSeries CStr(val)
    Next
    th.Load MCSnapshot
    SetMCParameter inc, val
    simTime = MCstartTime
    MCendTime = MCstartTime + MCRuntime
    While simTime < MCendTime And Not bMCPause
      th.tick simTime
      For Each aChart In m_Charts
        aChart.tick simTime
      Next
      simTime = simTime + stepSize
      DoEvents
    Wend
  Next inc
End Sub

Private Sub SetMCParameter(inc As Long, val)
  Dim Index As Long
  Dim ratio As Double
  
  ratio = inc / MCIncrements
  val = MCLowRange * (1# - ratio) + MCHighRange * ratio
  If MCParameterIndex <= -4 Then
    ' -4 = "Controller.firstToSecondShiftPeriod"
    ' -5 = "Controller.secondToThirdShiftPeriod"
    ' -6 = "Controller.thirdToFourthShiftPeriod"
    Index = -1 * MCParameterIndex - 3
    th.SetShiftPeriod Index, val
  ElseIf MCParameterIndex <= 0 Then
    ' -1 = "Controller.firstToSecondShiftDelay"
    ' -2 = "Controller.secondToThirdShiftDelay"
    ' -3 = "Controller.thirdToFourthShiftDelay"
    Index = -1 * MCParameterIndex
    th.SetShiftTiming True, Index, val
  Else
    Index = MCParameterIndex
    th.ModelExec.PostRPar simTime, Index, val
  End If
  
End Sub

Public Sub termSim()
  Set m_M = Nothing
  th.term
End Sub

