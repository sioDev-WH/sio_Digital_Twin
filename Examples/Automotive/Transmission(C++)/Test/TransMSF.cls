VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "TransMSF"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Dim VarNames() As String
Dim EqnNames() As String
Dim RParNames() As String
Dim IParNames() As String
Dim EsoNames() As String

Dim WithEvents aModelExec As OnModelExec
Attribute aModelExec.VB_VarHelpID = -1
Dim aModelFactory As OnTransModelFactory
Dim aModel As IsDaeEsoCImpl
Dim nVars As Long
Dim Vals() As Double
Dim bEvent1Fired As Boolean
Dim bEvent2Fired As Boolean

Public Sub Run()
  'On Error Resume Next
  Dim t As Double
  Dim t_last As Double
  Dim startTime As Double
  Dim endTime As Double
  Dim sampleRate As Double
  Dim i As Long
  
  ' time interval
  startTime = 0#
  endTime = 4
  sampleRate = 0.1
  
  ' create objects
  Set aModelExec = New OnModelExec
  Set aModelFactory = New OnTransModelFactory
  
  aModelFactory.CreateModel "OnTransMSF", aModel
  aModelExec.SetModel aModel
  
  ' initialize tolerances
  aModel.GetNumVars nVars
  ReDim atol(nVars) As Double
  ReDim rtol(nVars) As Double
  ReDim Vals(0 To nVars - 1) As Double
  
  For i = 0 To nVars - 1
    atol(i) = 0.0000001
    rtol(i) = 0.0000001
  Next i
  
#If 0 Then
  atol(17) = 0.000000001
  atol(34) = 0.000000001
  atol(56) = 0.000000001
  atol(73) = 0.000000001
  atol(90) = 0.000000001
  atol(107) = 0.000000001
  atol(124) = 0.000000001
  atol(141) = 0.000000001
  atol(158) = 0.000000001
#End If

  aModel.SetAbsTolerance atol
  aModel.SetRelTolerance rtol
  
  aModel.GetEqnNames EqnNames
  aModel.GetVarNames VarNames
  aModel.GetRParNames RParNames
  aModel.GetIParNames IParNames
  
  aModel.GetEsoNames EsoNames
  For i = 0 To UBound(EqnNames)
    Debug.Print i & "  " & EqnNames(i)
  Next i
  
  Open "struct.txt" For Output As #1
  Print #1, vbCrLf & "EqnNames"
  For i = 0 To UBound(EqnNames)
    Print #1, i & "  " & EqnNames(i)
  Next i
  
  Print #1, vbCrLf & "VarNames"
  For i = 0 To UBound(VarNames)
    Print #1, i & "  " & VarNames(i)
  Next i
 
  Print #1, vbCrLf & "RParNames"
  For i = 0 To UBound(RParNames)
    Print #1, i & "  " & RParNames(i)
  Next i
 
  Print #1, vbCrLf & "IParNames"
  For i = 0 To UBound(IParNames)
    Print #1, i & "  " & IParNames(i)
  Next i
 
  Close #1
  
  ' initialize time on model and driver
  aModel.InitTime startTime, False
  aModel.GetTime t
  t_last = t
  
  ' step through interval recording results
  Open "OnTransMSF.txt" For Output As #1

  ' print headings
  Print #1, "Event" & vbTab & "Time" & vbTab;
  For i = 0 To nVars - 1
    Print #1, VarNames(i) & vbTab;
  Next i
  Print #1, ""

  Dim start_time As Date
  Dim end_time As Date
  
  start_time = Now

  aModelExec.PostStateEvent t, "Start", -1, aModel.Eso("engine")
  aModelExec.StepSize = 0.05
  While t < endTime
    aModelExec.Step
    aModel.GetTime t
    
    If (t >= 0.05 And Not bEvent1Fired) Then
      'aModel.Eso("engine").PostRealParameter 0, 95#
      aModelExec.PostStateEvent t, "Engage", -1, aModel.Eso("aOB")
      aModelExec.PostStateEvent t, "Engage", -1, aModel.Eso("aFC")
      bEvent1Fired = True
    End If
    
    PrintData -1, t
  Wend
  
  end_time = Now
  
  aModelExec.SetModel Nothing
  ' cleanup
  Close #1
  
  MsgBox "time = " & DateDiff("s", start_time, end_time)
  
  printstats
End Sub

Public Sub PrintData(Eqn As String, t As Double)
  Dim i As Double
  
  aModel.GetAllVariables t, Vals
  
  Print #1, Eqn & vbTab & t & vbTab;
  For i = 0 To nVars - 2
    Print #1, Vals(i) & vbTab;
  Next i
  Print #1, Vals(nVars - 1)

End Sub

Private Sub aModelExec_AfterStateEvent(ByVal iEventEqn As Long, ByVal Time As Double)
  If (iEventEqn >= 0) Then
    PrintData EqnNames(iEventEqn), Time
  Else
    PrintData "external", Time
  End If
End Sub

Private Sub aModelExec_BeforeStateEvent(ByVal iEventEqn As Long, ByVal Time As Double)
  If (iEventEqn >= 0) Then
    PrintData EqnNames(iEventEqn), Time
  Else
    PrintData "external", Time
  End If
End Sub

Private Sub printstats()
  Dim StepperCalls As Long, functionCalls As Long, jacobiansCalls As Long, DecompCalls As Long, Substitutions As Long, TotalSteps As Long, errorRejectedSteps As Long, newtonRejectedSteps As Long, growthRejectedSteps As Long, funcRejectedSteps As Long, nEvents  As Long
    
  aModel.GetReportInfo StepperCalls, functionCalls, jacobiansCalls, DecompCalls, Substitutions, TotalSteps, errorRejectedSteps, newtonRejectedSteps, growthRejectedSteps, funcRejectedSteps, nEvents
  Debug.Print "StepperCalls " & StepperCalls
  Debug.Print "functionCalls " & functionCalls
  Debug.Print "jacobiansCalls " & jacobiansCalls
  Debug.Print "DecompCalls " & DecompCalls
  Debug.Print "Substitutions " & Substitutions
  Debug.Print "TotalSteps " & TotalSteps
  Debug.Print "errorRejectedSteps " & errorRejectedSteps
  Debug.Print "newtonRejectedSteps " & newtonRejectedSteps
  Debug.Print "growthRejectedSteps " & growthRejectedSteps
  Debug.Print "funcRejectedSteps " & funcRejectedSteps
  Debug.Print "nEvents " & nEvents
   


End Sub

