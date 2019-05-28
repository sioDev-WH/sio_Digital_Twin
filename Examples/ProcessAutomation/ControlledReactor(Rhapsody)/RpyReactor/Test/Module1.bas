Attribute VB_Name = "Module1"
Option Explicit

Global mTest As RpyReactorTestHarness
Global variableData() As Double
Global modelExec As OnModelExec
Global mdlReactor As IsDaeEsoCImpl
Global nVars As Long
Global mOpt As GeoObject
Global varList() As Long
Global nSelectedVars As Long
Global bCancel As Boolean

Global idxControllerOutput As Long

Global Const IPAR_Q = 0
Global Const IPAR_K0 = 3
Global Const IPAR_H = 9


Public Sub RecordSnapshots( _
  parIdxList() As Long, _
  parPercentList() As Double, _
  parSlewList() As Double, _
  SetPoint As Double, _
  SetPointSlew As Double, _
  nPars As Long, _
  varCharts() As TChart)
  
  Dim i As Long
  Dim j As Long
  Dim szFileName As String
  Dim nFile As Long
  Dim T As Double
  Dim t_next As Double
  Dim iRec As Long
  Dim iStep As Long
  Dim oldVal As Double
  
  ' initialize the array of variable data
  mdlReactor.GetNumVars nVars
  ReDim variableData(40 * 10, nVars + 1) As Double
  ReDim varVals(0 To nVars - 1) As Double
  ReDim parVals(3) As Double
  
  ' initialize the setpoint
  mTest.setSetpoint SetPoint
  
  ' set the parameter values on the model
  For i = 0 To nPars - 1
    mdlReactor.GetRealPar parIdxList(i), oldVal
    parVals(i) = (parPercentList(i) / 100#) * oldVal
    mdlReactor.SetRealPar parIdxList(i), parVals(i)
  Next i
  modelExec.ForceReset
  
  ReDim varIdx(3) As Long
  Dim val As Double
  
  varIdx(0) = 2 ' C_Toluene
  varIdx(1) = 0 ' T_Reactor
  varIdx(2) = 5 ' T_Heater
  
  T = 0
  Do While T < 40
    ' slew the setpoint
    mTest.setSetpoint SetPoint * (1 + (SetPointSlew / 100#) * (T / 40))
    
    ' slew the parameter values on the model
    For i = 0 To nPars - 1
      mdlReactor.SetRealPar parIdxList(i), parVals(i) * (1 + (parSlewList(i) / 100#) * (T / 40#))
    Next i
    'modelExec.ForceReset

    If iStep = 0 Or iStep = 10 Then
      szFileName = GetFileName(T)
      modelExec.Save szFileName
      iStep = 0
    End If
    
    mdlReactor.GetAllVariables T, varVals
    For j = 0 To nVars - 1
      variableData(iRec, j) = varVals(j)
    Next j
    mTest.GetControllerOutput T, val
    variableData(iRec, nVars) = val
    
    For j = 0 To 2
      If varCharts(j).SeriesCount = 1 Then
        varCharts(j).Series(0).AddXY T, varVals(varIdx(j)), "", 0
      End If
    Next j
      
    iRec = iRec + 1
    T = T + 0.1
    iStep = iStep + 1
    On Error Resume Next
    mTest.Step T
  Loop
  
  Open "C:\Rhapsody40\Reactor\RpyReactor\Test\variableData.txt" For Output As #3
  Print #3, "iRec" & vbTab & "itsReactor.T_reactor" & vbTab & "itsReactor.C_heptane" & vbTab & "itsReactor.C_toluene" & vbTab & "itsReactor.C_hydrogen" & vbTab & "itsReactor.T_recycle_in" & vbTab & "itsHeater.T_heater" & vbTab & "itsHeater.T_in" & vbTab & "itsHeater.Q_in" & vbTab & "Controller.CO"
  Dim lastRec As Long
  lastRec = iRec - 1
  For iRec = 0 To lastRec
    Print #3, iRec & vbTab & _
              variableData(iRec, 0) & vbTab & variableData(iRec, 1) & vbTab & variableData(iRec, 2) & vbTab & _
              variableData(iRec, 3) & vbTab & variableData(iRec, 4) & vbTab & variableData(iRec, 5) & vbTab & _
              variableData(iRec, 6) & vbTab & variableData(iRec, 7) & vbTab & variableData(iRec, 8)
  Next iRec
  Close #3
End Sub

Public Function GetFileName(T As Double) As String
  GetFileName = "record" & Format(T, "00") & ".bin"
End Function

Public Sub parameterEstimation(paramCharts() As TChart)
  Dim i As Long
  Dim T As Double
  Dim aOptModel As ReactorOpt
  Dim errVal As Double
  
  ReDim InitialGuess(0 To 2) As Double
  InitialGuess(0) = 1 ' 3#          IPAR_Q
  InitialGuess(1) = 1 ' 501000000#  IPAR_K0
  InitialGuess(2) = 1 ' 6.05e5#     IPAR_H

  T = 0
  Set aOptModel = New ReactorOpt
  
  Set mOpt = New GeoObject
  mOpt.SetIModel aOptModel
  mOpt.Span = 0.5
  mOpt.Resolution = 0.000001
  mOpt.MaxIteration = 1000
  mOpt.MaxTime = 20
  
  
  Do While T < 40
    If bCancel Then Exit Sub
    aOptModel.SetStartTime T
    mOpt.SetInitialGuess InitialGuess
    errVal = mOpt.Optimize(InitialGuess)  ' results are returned in this argument
    Debug.Print "T: " & T & " Q: " & InitialGuess(0) & ", K0: " & InitialGuess(1) & ", H: " & InitialGuess(2) & ", err: " & errVal
    For i = 0 To 2
      paramCharts(i).Series(0).AddXY T, InitialGuess(i), "", 0
    Next i
    T = T + 1#
  Loop
  
  MsgBox "Complete"
End Sub
