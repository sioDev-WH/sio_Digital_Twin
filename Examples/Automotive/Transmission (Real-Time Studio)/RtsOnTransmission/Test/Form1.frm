VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Begin VB.Form frmTestClient 
   Caption         =   "Transmission Test Client"
   ClientHeight    =   7065
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   12105
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   7065
   ScaleWidth      =   12105
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame frmMonteCarlo 
      Caption         =   "Monte Carlo Configuration"
      Height          =   6855
      Left            =   6240
      TabIndex        =   21
      Top             =   120
      Width           =   5775
      Begin VB.TextBox txtMCStepSize 
         Height          =   285
         Left            =   1080
         TabIndex        =   38
         Text            =   "0.1"
         Top             =   6000
         Width           =   1095
      End
      Begin VB.TextBox txtMCRuntime 
         Height          =   285
         Left            =   1080
         TabIndex        =   36
         Text            =   "5"
         Top             =   5640
         Width           =   1095
      End
      Begin VB.CommandButton btnMCStop 
         BackColor       =   &H80000009&
         Height          =   375
         Left            =   2280
         Picture         =   "Form1.frx":0442
         Style           =   1  'Graphical
         TabIndex        =   35
         Top             =   6360
         Width           =   375
      End
      Begin VB.CommandButton btnMCPause 
         BackColor       =   &H80000009&
         Height          =   375
         Left            =   2760
         Picture         =   "Form1.frx":0490
         Style           =   1  'Graphical
         TabIndex        =   34
         Top             =   6360
         Width           =   375
      End
      Begin VB.CommandButton btnMCPlay 
         BackColor       =   &H80000009&
         Height          =   375
         Left            =   3240
         Picture         =   "Form1.frx":04DE
         Style           =   1  'Graphical
         TabIndex        =   33
         Top             =   6360
         Width           =   375
      End
      Begin VB.TextBox txtMCIncrements 
         Height          =   285
         Left            =   1080
         TabIndex        =   32
         Text            =   "10"
         Top             =   5280
         Width           =   1095
      End
      Begin VB.CommandButton btnMCSnapshot 
         Caption         =   "..."
         Height          =   255
         Left            =   5280
         TabIndex        =   30
         Top             =   4200
         Width           =   375
      End
      Begin VB.TextBox txtMCHighRange 
         Height          =   285
         Left            =   1080
         TabIndex        =   29
         Text            =   "1.0"
         Top             =   4920
         Width           =   1095
      End
      Begin VB.TextBox txtMCLowRange 
         Height          =   285
         Left            =   1080
         TabIndex        =   26
         Text            =   "0.0"
         Top             =   4560
         Width           =   1095
      End
      Begin VB.TextBox txtMCSnapshot 
         Height          =   285
         Left            =   1080
         TabIndex        =   24
         Top             =   4200
         Width           =   4095
      End
      Begin VB.ListBox lstMCParameters 
         Height          =   3570
         Left            =   120
         TabIndex        =   22
         Top             =   480
         Width           =   5055
      End
      Begin VB.Label Label10 
         Caption         =   "Step Size:"
         Height          =   255
         Left            =   120
         TabIndex        =   39
         Top             =   6000
         Width           =   1095
      End
      Begin VB.Label Label9 
         Caption         =   "Runtime:"
         Height          =   255
         Left            =   120
         TabIndex        =   37
         Top             =   5640
         Width           =   975
      End
      Begin VB.Label Label8 
         Caption         =   "Increments:"
         Height          =   255
         Left            =   120
         TabIndex        =   31
         Top             =   5280
         Width           =   975
      End
      Begin VB.Label Label7 
         Caption         =   "High range:"
         Height          =   255
         Left            =   120
         TabIndex        =   28
         Top             =   4920
         Width           =   975
      End
      Begin VB.Label Label6 
         Caption         =   "Low range:"
         Height          =   255
         Left            =   120
         TabIndex        =   27
         Top             =   4560
         Width           =   1215
      End
      Begin VB.Label Label5 
         Caption         =   "Snapshot:"
         Height          =   255
         Left            =   120
         TabIndex        =   25
         Top             =   4200
         Width           =   1695
      End
      Begin VB.Label Label4 
         Caption         =   "Parameters"
         Height          =   255
         Left            =   120
         TabIndex        =   23
         Top             =   240
         Width           =   2055
      End
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   2280
      Top             =   -120
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.Frame Frame2 
      Caption         =   "Simulation"
      Height          =   2175
      Left            =   120
      TabIndex        =   8
      Top             =   4800
      Width           =   6015
      Begin VB.CheckBox chkSnapshotEvents 
         Caption         =   "Snapshot all events"
         Height          =   495
         Left            =   3600
         TabIndex        =   20
         Top             =   1200
         Width           =   1575
      End
      Begin VB.CommandButton btnLoad 
         Caption         =   "Load snapshot"
         Height          =   375
         Left            =   3600
         TabIndex        =   19
         Top             =   720
         Width           =   1575
      End
      Begin VB.CommandButton btnSave 
         Caption         =   "Save snapshot"
         Height          =   375
         Left            =   3600
         TabIndex        =   18
         Top             =   240
         Width           =   1575
      End
      Begin VB.TextBox txtStepSize 
         Height          =   285
         Left            =   1200
         TabIndex        =   16
         Text            =   "0.1"
         Top             =   1080
         Width           =   1215
      End
      Begin VB.TextBox txtEndTime 
         Height          =   285
         Left            =   1200
         TabIndex        =   14
         Text            =   "300.0"
         Top             =   720
         Width           =   1215
      End
      Begin VB.TextBox txtStartTime 
         Height          =   285
         Left            =   1200
         TabIndex        =   12
         Text            =   "0.0"
         Top             =   360
         Width           =   1215
      End
      Begin VB.CommandButton btnPause 
         BackColor       =   &H80000009&
         Height          =   375
         Left            =   2640
         Picture         =   "Form1.frx":052E
         Style           =   1  'Graphical
         TabIndex        =   11
         Top             =   1680
         Width           =   375
      End
      Begin VB.CommandButton btnPlay 
         BackColor       =   &H80000009&
         Height          =   375
         Left            =   3120
         Picture         =   "Form1.frx":057C
         Style           =   1  'Graphical
         TabIndex        =   10
         Top             =   1680
         Width           =   375
      End
      Begin VB.CommandButton btnStop 
         BackColor       =   &H80000009&
         Height          =   375
         Left            =   2160
         Picture         =   "Form1.frx":05CC
         Style           =   1  'Graphical
         TabIndex        =   9
         Top             =   1680
         Width           =   375
      End
      Begin VB.Label Label3 
         Caption         =   "Step Size:"
         Height          =   255
         Left            =   120
         TabIndex        =   17
         Top             =   1080
         Width           =   1095
      End
      Begin VB.Label Label2 
         Caption         =   "End Time:"
         Height          =   255
         Left            =   120
         TabIndex        =   15
         Top             =   720
         Width           =   1095
      End
      Begin VB.Label Label1 
         Caption         =   "Start Time:"
         Height          =   255
         Left            =   120
         TabIndex        =   13
         Top             =   360
         Width           =   1095
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Chart Configuration"
      Height          =   4575
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   6015
      Begin VB.CommandButton btnSetChartVars 
         Caption         =   "Set Chart Vars"
         Height          =   375
         Left            =   3600
         TabIndex        =   7
         Top             =   4080
         Width           =   1215
      End
      Begin VB.CommandButton btnRemoveChart 
         Caption         =   "Remove"
         Height          =   375
         Left            =   1440
         TabIndex        =   6
         Top             =   4080
         Width           =   975
      End
      Begin VB.CommandButton btnAddChart 
         Caption         =   "Add"
         Height          =   375
         Left            =   120
         TabIndex        =   5
         Top             =   4080
         Width           =   975
      End
      Begin VB.ListBox lstChartVars 
         Height          =   3570
         Left            =   2520
         MultiSelect     =   2  'Extended
         TabIndex        =   2
         Top             =   480
         Width           =   3375
      End
      Begin VB.ListBox lstCharts 
         Height          =   3570
         Left            =   120
         TabIndex        =   1
         Top             =   480
         Width           =   2295
      End
      Begin VB.Label lblChartVars 
         Caption         =   "Chart Variables"
         Height          =   255
         Left            =   2520
         TabIndex        =   4
         Top             =   240
         Width           =   2295
      End
      Begin VB.Label lblCharts 
         Caption         =   "Charts"
         Height          =   255
         Left            =   120
         TabIndex        =   3
         Top             =   240
         Width           =   2295
      End
   End
   Begin VB.Menu mnuMain 
      Caption         =   "File"
      Index           =   0
      Begin VB.Menu mnuFile 
         Caption         =   "Load"
         Index           =   0
      End
      Begin VB.Menu mnuFile 
         Caption         =   "Save"
         Index           =   1
      End
   End
End
Attribute VB_Name = "frmTestClient"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private WithEvents m_ModelExec As OnModelExec
Attribute m_ModelExec.VB_VarHelpID = -1
Private m_afterStates(20) As Long
Private m_beforeStates(20) As Long
Private m_MachineInfo As Collection

Private m_StartTime As Date
Private m_SimStartTime As Double

Private Sub btnAddChart_Click()
  Dim szName As String
  Dim aChart As vbChart
  
  szName = InputBox("Chart Name: ", "Enter name for chart")
  If Len(szName) > 0 Then
    Set aChart = New vbChart
    aChart.Name = szName
    m_Charts.Add aChart, szName
    lstCharts.AddItem szName
  End If
End Sub

Private Sub btnLoad_Click()
  Dim szFileName As String
  
  If Not th Is Nothing Then
    CommonDialog1.DefaultExt = "bin"
    CommonDialog1.filename = "*.bin"
    CommonDialog1.ShowOpen
    szFileName = CommonDialog1.filename
    If Len(szFileName) > 0 Then
      While InStr(1, szFileName, "\") > 0
        szFileName = Mid(szFileName, InStr(1, szFileName, "\") + 1)
      Wend
      th.Load szFileName
    End If
  End If
  
End Sub

Private Sub btnMCStop_Click()
  bMCRun = False
End Sub

Private Sub btnMCPause_Click()
  bMCPause = True
End Sub

Private Sub btnMCPlay_Click()
  bMCPause = False
  If Not bMCRun Then
    bMCRun = True
    If lstMCParameters.ListIndex >= 0 And Len(txtMCSnapshot.Text) > 0 And _
       IsNumeric(txtMCLowRange.Text) And IsNumeric(txtMCHighRange.Text) And _
       IsNumeric(txtMCIncrements.Text) And IsNumeric(txtMCRuntime.Text) Then
       
      MCParameterIndex = lstMCParameters.ItemData(lstMCParameters.ListIndex)
      MCSnapshot = txtMCSnapshot.Text
      Dim pos As Long
      pos = InStr(1, MCSnapshot, ".bin")
      If pos > 0 Then
        MCSnapshot = Left(MCSnapshot, pos - 1)
      End If
      MCRuntime = CDbl(txtMCRuntime.Text)
      
      th.Load MCSnapshot
      m_M.GetTime simTime
      MCstartTime = simTime
      MCendTime = MCstartTime + MCRuntime
      MCstepSize = CDbl(txtMCStepSize.Text)
      MCLowRange = CDbl(txtMCLowRange.Text)
      MCHighRange = CDbl(txtMCHighRange.Text)
      MCIncrements = CLng(txtMCIncrements.Text)
    End If
  End If
  
  If lstMCParameters.ListIndex >= 0 And Len(txtMCSnapshot.Text) > 0 And _
     IsNumeric(txtMCLowRange.Text) And IsNumeric(txtMCHighRange.Text) And _
     IsNumeric(txtMCIncrements.Text) And IsNumeric(txtMCRuntime.Text) Then
    runMCSim
  End If
  
End Sub

Private Sub initParameters()
  ReDim RParNames(0) As String
  Dim i As Long
  
  lstMCParameters.Clear
  ' controller parameters -- added manually and dealt with special
  lstMCParameters.AddItem "Controller.firstToSecondShiftDelay"
  lstMCParameters.ItemData(lstMCParameters.ListCount - 1) = -1
  lstMCParameters.AddItem "Controller.secondToThirdShiftDelay"
  lstMCParameters.ItemData(lstMCParameters.ListCount - 1) = -2
  lstMCParameters.AddItem "Controller.thirdToFourthShiftDelay"
  lstMCParameters.ItemData(lstMCParameters.ListCount - 1) = -3
  lstMCParameters.AddItem "Controller.firstToSecondShiftPeriod"
  lstMCParameters.ItemData(lstMCParameters.ListCount - 1) = -4
  lstMCParameters.AddItem "Controller.secondToThirdShiftPeriod"
  lstMCParameters.ItemData(lstMCParameters.ListCount - 1) = -5
  lstMCParameters.AddItem "Controller.thirdToFourthShiftPeriod"
  lstMCParameters.ItemData(lstMCParameters.ListCount - 1) = -6
  
  m_M.GetRParNames RParNames
  For i = 0 To UBound(RParNames) - 1
    lstMCParameters.AddItem RParNames(i)
    lstMCParameters.ItemData(lstMCParameters.ListCount - 1) = i
  Next i
End Sub

Private Sub btnMCSnapshot_Click()
  Dim szFileName As String
  
  CommonDialog1.DefaultExt = "bin"
  CommonDialog1.filename = "*.bin"
  CommonDialog1.ShowOpen
  szFileName = CommonDialog1.filename
  While InStr(1, szFileName, "\") > 0
    szFileName = Mid(szFileName, InStr(1, szFileName, "\") + 1)
  Wend
  If Len(szFileName) > 0 Then
    txtMCSnapshot.Text = szFileName
  End If
End Sub

Private Sub btnPause_Click()
  bPause = True
  
  Dim nStepperCalls As Long
  Dim nFunctionCalls As Long
  Dim nJacCalls As Long
  Dim nDecompCalls As Long
  Dim nSubstitutions As Long
  Dim nTotalSteps As Long
  Dim nErrorRejectedSteps As Long
  Dim nNewtonRejectedSteps As Long
  Dim nGrowthRejectedSteps As Long
  Dim nFuncRejectedSteps As Long
  Dim nStateEvents As Long
  Dim nParameterEvents As Long
  Dim nStepSizeChanges As Long
  
  Dim elapsedTime As Double
  Dim elapsedSimTime As Double
  
  Dim nEqns As Long
  Dim nVars As Long
  
  m_M.GetNumEqns nEqns
  m_M.GetNumVars nVars
  
  elapsedTime = DateDiff("s", m_StartTime, Now)
  elapsedSimTime = simTime - m_SimStartTime

  m_M.GetReportInfo nStepperCalls, nFunctionCalls, nJacCalls, nDecompCalls, _
                    nSubstitutions, nTotalSteps, nErrorRejectedSteps, nNewtonRejectedSteps, _
                    nGrowthRejectedSteps, nFuncRejectedSteps, nStateEvents, nParameterEvents, _
                    nStepSizeChanges
                    
  Debug.Print "nEqns: " & nEqns
  Debug.Print "nVars: " & nVars
  Debug.Print "elapsedTime: " & elapsedTime
  Debug.Print "elapsedSimTime: " & elapsedSimTime
  Debug.Print "nStepperCalls: " & nStepperCalls
  Debug.Print "nFunctionCalls: " & nFunctionCalls
  Debug.Print "nJacCalls: " & nJacCalls
  Debug.Print "nDecompCalls: " & nDecompCalls
  Debug.Print "nSubstitutions: " & nSubstitutions
  Debug.Print "nTotalSteps: " & nTotalSteps
  Debug.Print "nErrorRejectedSteps: " & nErrorRejectedSteps
  Debug.Print "nNewtonRejectedSteps: " & nNewtonRejectedSteps
  Debug.Print "nGrowthRejectedSteps: " & nGrowthRejectedSteps
  Debug.Print "nFuncRejectedSteps: " & nFuncRejectedSteps
  Debug.Print "nStateEvents: " & nStateEvents
  Debug.Print "nParameterEvents: " & nParameterEvents
  Debug.Print "nStepSizeChanges: " & nStepSizeChanges
  
  Dim fh As Long
  fh = FreeFile()
  Open "statistics.txt" For Output As #fh
  
    Print #fh, "nEqns: " & nEqns
    Print #fh, "nVars: " & nVars
    Print #fh, "elapsedTime: " & elapsedTime
    Print #fh, "elapsedSimTime: " & elapsedSimTime
    Print #fh, "nStepperCalls: " & nStepperCalls
    Print #fh, "nFunctionCalls: " & nFunctionCalls
    Print #fh, "nJacCalls: " & nJacCalls
    Print #fh, "nDecompCalls: " & nDecompCalls
    Print #fh, "nSubstitutions: " & nSubstitutions
    Print #fh, "nTotalSteps: " & nTotalSteps
    Print #fh, "nErrorRejectedSteps: " & nErrorRejectedSteps
    Print #fh, "nNewtonRejectedSteps: " & nNewtonRejectedSteps
    Print #fh, "nGrowthRejectedSteps: " & nGrowthRejectedSteps
    Print #fh, "nFuncRejectedSteps: " & nFuncRejectedSteps
    Print #fh, "nStateEvents: " & nStateEvents
    Print #fh, "nParameterEvents: " & nParameterEvents
    Print #fh, "nStepSizeChanges: " & nStepSizeChanges
    
  Close #fh
  
  Dim szMsg As String
  

  szMsg = "nEqns: " & nEqns & vbCrLf & _
          "nVars: " & nVars & vbCrLf & _
          "elapsedTime: " & elapsedTime & vbCrLf & _
          "elapsedSimTime: " & elapsedSimTime & vbCrLf & _
          "nStepperCalls: " & nStepperCalls & vbCrLf & _
          "nFunctionCalls: " & nFunctionCalls & vbCrLf & _
          "nJacCalls: " & nJacCalls & vbCrLf & _
          "nDecompCalls: " & nDecompCalls & vbCrLf & _
          "nSubstitutions: " & nSubstitutions & vbCrLf & _
          "nTotalSteps: " & nTotalSteps & vbCrLf & _
          "nErrorRejectedSteps: " & nErrorRejectedSteps & vbCrLf & _
          "nNewtonRejectedSteps: " & nNewtonRejectedSteps & vbCrLf & _
          "nGrowthRejectedSteps: " & nGrowthRejectedSteps & vbCrLf & _
          "nFuncRejectedSteps: " & nFuncRejectedSteps & vbCrLf & _
          "nStateEvents: " & nStateEvents & vbCrLf & _
          "nParameterEvents: " & nParameterEvents

  MsgBox szMsg
End Sub

Private Sub btnPlay_Click()
  bPause = False
  
  m_StartTime = Now
  m_SimStartTime = simTime
  
  runSim
End Sub

Private Sub btnRemoveChart_Click()
  Dim szName As String
  
  If lstCharts.ListIndex >= 0 Then
    szName = lstCharts.List(lstCharts.ListIndex)
    m_Charts.Remove lstCharts.ListIndex + 1
    lstCharts.RemoveItem lstCharts.ListIndex
  End If
End Sub

Private Sub btnSave_Click()
  Dim filename As String
  
  If Not th Is Nothing Then
    filename = InputBox("Enter save filename")
    If Len(filename) > 0 Then
      th.Save filename
    End If
  End If
End Sub

Private Sub btnSetChartVars_Click()
  Dim selCount As Long
  Dim szName As String
  Dim aChart As vbChart
  Dim count As Long
  Dim i As Long
  
  selCount = lstChartVars.selCount
  ReDim indices(selCount) As Long
  ReDim Names(selCount) As String
  
  If lstCharts.ListIndex >= 0 Then
    szName = lstCharts.List(lstCharts.ListIndex)
    Set aChart = m_Charts(szName)
    For i = 0 To lstChartVars.ListCount - 1
      If lstChartVars.Selected(i) Then
        indices(count) = i
        Names(count) = lstChartVars.List(i)
        count = count + 1
      End If
    Next i
    aChart.SetVars indices, Names, count
  End If
      
End Sub

Private Sub btnStop_Click()
  Dim aChart As vbChart
  
  bPause = True
  simTime = startTime
  While m_Charts.count > 0
    m_Charts.Remove m_Charts.count
  Wend
  lstCharts.Clear
  th.Load "initial_conditions"
End Sub

Private Sub Form_Load()
  ReDim VarNames(0) As String
  Dim i As Long
  
  InitMachineInfo
  
  startTime = CDbl(txtStartTime.Text)
  endTime = CDbl(txtEndTime.Text)
  stepSize = CDbl(txtStepSize.Text)
  
  initSim
  Set m_ModelExec = th.ModelExec
  ' initialize the variable name list box
  Dim nEqns As Long
  m_M.GetNumEqns nEqns
  m_M.GetVarNames VarNames
  For i = 0 To UBound(VarNames) - 1
    lstChartVars.AddItem VarNames(i)
  Next i
  initParameters
  
End Sub

Private Sub Form_Unload(Cancel As Integer)
  If Not th Is Nothing Then
    Set m_M = Nothing
    th.term
  End If
  
  If Not m_Charts Is Nothing Then
    Set m_Charts = Nothing
  End If
End Sub


Private Sub m_ModelExec_AfterEvent(ByVal Time As Double)
  Dim aChart As vbChart
  Dim aMachine As MachineInfo
  Dim i As Long
  Dim filename As String
  
  If chkSnapshotEvents.Value = Checked Then
    th.GetStates m_afterStates
    filename = ""
    For Each aMachine In m_MachineInfo
      i = aMachine.Index
      If m_beforeStates(i) <> m_afterStates(i) Then
        filename = Left(Format(Time, "000.0000"), 3) & "_" & _
                   Right(Format(Time, "000.0000"), 4) & "_" & _
                   aMachine.Name & "_" & _
                   aMachine.StateName(m_afterStates(i))
        Exit For
      End If
    Next
    
    If Len(filename) > 0 Then
      th.Save filename
    End If
  End If
  
  For Each aChart In m_Charts
    aChart.tick Time
  Next
  
End Sub

Private Sub m_ModelExec_BeforeEvent(ByVal Time As Double)
  Dim aChart As vbChart
  Dim i As Long
  
  If chkSnapshotEvents.Value = Checked Then
    th.GetStates m_beforeStates
  End If
  
  For Each aChart In m_Charts
    aChart.tick Time
  Next
  
End Sub

Private Sub mnuFile_Click(Index As Integer)
  Dim fh As Long
  Dim filename As String
  Dim count As Long
  Dim aChart As vbChart
  Dim i As Long
  
  ' 0 == Load
  If Index = 0 Then
    CommonDialog1.DefaultExt = "txt"
    CommonDialog1.filename = "c:\DistComponents\bin\*.txt"
    CommonDialog1.ShowOpen
    filename = CommonDialog1.filename
    If Len(filename) > 0 Then
      fh = FreeFile
      Open filename For Input As #fh
      
        ' load the timing parameters
        Input #1, startTime
        Input #1, endTime
        Input #1, stepSize
        txtStartTime.Text = startTime
        txtEndTime.Text = endTime
        txtStepSize.Text = stepSize
        
        ' load the chart data
        Input #1, count
        
        For i = 1 To count
          Set aChart = New vbChart
          m_Charts.Add aChart
          aChart.Load fh
        Next i
        
        ' load the list box with the charts
        For Each aChart In m_Charts
          lstCharts.AddItem aChart.Name
        Next
        
      Close #fh
    End If
  End If
  
  ' 1 == Save
  If Index = 1 Then
    CommonDialog1.DefaultExt = "txt"
    CommonDialog1.filename = "c:\DistComponents\bin\*.txt"
    CommonDialog1.ShowSave
    filename = CommonDialog1.filename
    If Len(filename) > 0 Then
      fh = FreeFile
      Open filename For Output As #fh
        
        ' save the timing data
        Write #1, startTime
        Write #1, endTime
        Write #1, stepSize
        
        ' save the chart data
        count = m_Charts.count
        Write #1, count
        
        For i = 1 To count
          Set aChart = m_Charts(i)
          aChart.Save fh
        Next i
      
      Close #fh
    End If
  End If
  
  
End Sub

Private Sub txtStepSize_Change()
  If IsNumeric(txtStepSize.Text) Then
    stepSize = CDbl(txtStepSize.Text)
  End If
End Sub

Private Sub txtEndTime_Change()
  If IsNumeric(txtEndTime.Text) Then
    endTime = CDbl(txtEndTime.Text)
  End If
End Sub

Private Sub txtStartTime_Change()
  If IsNumeric(txtStartTime.Text) Then
    startTime = CDbl(txtStartTime.Text)
  End If
End Sub

Private Sub InitMachineInfo()
  
  Dim nActuatorStates As Long
  ReDim ActuatorStates(3) As String
  Dim nClutchStates As Long
  ReDim ClutchStates(3) As String
  Dim nEngineStates As Long
  ReDim EngineStates(3) As String
  Dim nConverterStates As Long
  ReDim ConverterStates(3) As String
  Dim aMachine As MachineInfo
  
  nActuatorStates = 3
  ActuatorStates(0) = "Disengaged"
  ActuatorStates(1) = "Waiting"
  ActuatorStates(2) = "Engaged"
  
  nClutchStates = 3
  ClutchStates(0) = "cSlip"
  ClutchStates(1) = "Lock"
  ClutchStates(2) = "ccSlip"
  
  nEngineStates = 3
  EngineStates(0) = "Starting"
  EngineStates(1) = "On"
  EngineStates(2) = "Off"
  
  nConverterStates = 3
  ConverterStates(0) = "Fluid_Coupling"
  ConverterStates(1) = "Locked"
  ConverterStates(2) = "Torque_Multiplication"

  Set m_MachineInfo = New Collection
  
  Set aMachine = New MachineInfo
  aMachine.init "EngineWithSpeed", "Engine", 0, nEngineStates, EngineStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "aRC", "Actuator", 1, nActuatorStates, ActuatorStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "RC", "Clutch", 2, nClutchStates, ClutchStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "aLRB", "Actuator", 3, nActuatorStates, ActuatorStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "LRB", "Clutch", 4, nClutchStates, ClutchStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "aTCC", "Actuator", 5, nActuatorStates, ActuatorStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "TCC", "Clutch", 6, nClutchStates, ClutchStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "Converter", "Torque_Converter", 7, nConverterStates, ConverterStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "aOB", "Actuator", 8, nActuatorStates, ActuatorStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "OB", "Clutch", 9, nClutchStates, ClutchStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "aDC", "Actuator", 10, nActuatorStates, ActuatorStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "DC", "Clutch", 11, nClutchStates, ClutchStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "aIOC", "Actuator", 12, nActuatorStates, ActuatorStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "IOC", "Clutch", 13, nClutchStates, ClutchStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "aPOC", "Actuator", 14, nActuatorStates, ActuatorStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "POC", "Clutch", 15, nClutchStates, ClutchStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "aFC", "Actuator", 16, nActuatorStates, ActuatorStates
  m_MachineInfo.Add aMachine, aMachine.Name
  Set aMachine = New MachineInfo
  aMachine.init "FC", "Clutch", 17, nClutchStates, ClutchStates
  m_MachineInfo.Add aMachine, aMachine.Name

End Sub

