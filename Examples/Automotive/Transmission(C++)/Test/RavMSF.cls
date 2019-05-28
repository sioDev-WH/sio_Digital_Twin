VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "RavMSF"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Dim VarNames() As String
Dim EqnNames() As String
Dim RParNames() As String
Dim IParNames() As String

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
  endTime = 10
  sampleRate = 0.1
  
  ' create objects
  Set aModelExec = New OnModelExec
  Set aModelFactory = New OnTransModelFactory
  
  aModelFactory.CreateModel "OnRavMSF", aModel
  aModelExec.SetModel aModel
  
  ' initialize tolerances
  aModel.GetNumVars nVars
  ReDim atol(nVars) As Double
  ReDim rtol(nVars) As Double
  ReDim Vals(0 To nVars - 1) As Double
  
  For i = 0 To nVars - 1
    atol(i) = 0.000001
    rtol(i) = 0.000001
  Next i
  
  atol(12) = 0.000000001
  ' displacement of clutch
    
  aModel.SetAbsTolerance atol
  aModel.SetRelTolerance rtol
  
  aModel.GetEqnNames EqnNames
  aModel.GetVarNames VarNames
  aModel.GetRParNames RParNames
  aModel.GetIParNames IParNames
  
  Debug.Print vbCrLf & "EqnNames"
  For i = 0 To UBound(EqnNames)
    Debug.Print i & "  " & EqnNames(i)
  Next i
  
  Debug.Print vbCrLf & "VarNames"
  For i = 0 To UBound(VarNames)
    Debug.Print i & "  " & VarNames(i)
  Next i
 
  Debug.Print vbCrLf & "RParNames"
  For i = 0 To UBound(RParNames)
    Debug.Print i & "  " & RParNames(i)
  Next i
 
  Debug.Print vbCrLf & "IParNames"
  For i = 0 To UBound(IParNames)
    Debug.Print i & "  " & IParNames(i)
  Next i
 
  ' initialize time on model and driver
  aModel.InitTime startTime, False
  aModel.GetTime t
  t_last = t
  
  ' step through interval recording results
  Open "RavMSF.txt" For Output As #1

  ' print headings
  Print #1, "Event" & vbTab & "Time" & vbTab;
  For i = 0 To nVars - 1
    Print #1, VarNames(i) & vbTab;
  Next i
  Print #1, ""

  Dim t1 As Date
  Dim t2 As Date

  t1 = Now
  
  'aModelExec.StepSize = 0.05
  aModel.GetTime t
  t_last = t
  
  aModelExec.PostStateEvent t, "Start", -1, aModel.Eso("Engine1")
  While t < endTime
    aModelExec.Step
    aModel.GetTime t
    
    If t > 0.2 And Not bEvent1Fired Then
      ' aModelExec.PostStateEvent t, "Engage", -1, aModel.Eso("aBreak")
       aModelExec.PostStateEvent t, "Engage", -1, aModel.Eso("Actuator1")
      bEvent1Fired = True
    End If
    PrintData -1, t
  Wend
  
  aModelExec.SetModel Nothing
  ' cleanup
  Close #1
  
  t2 = Now
  Debug.Print "Simtime: " & DateDiff("s", t1, t2)
  
  MsgBox "run time = " & DateDiff("s", t1, t2)
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



