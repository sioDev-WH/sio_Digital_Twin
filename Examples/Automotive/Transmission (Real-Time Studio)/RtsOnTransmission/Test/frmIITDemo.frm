VERSION 5.00
Begin VB.Form frmIITDemo 
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnStart 
      Caption         =   "Start"
      Height          =   1455
      Left            =   720
      TabIndex        =   0
      Top             =   360
      Width           =   2415
   End
End
Attribute VB_Name = "frmIITDemo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

' model executive
Private WithEvents m_Exec As OnModelExec
Attribute m_Exec.VB_VarHelpID = -1
Private m_Model As IsDaeEsoCImpl
Private m_Composite As vbComposite

' printing
Private m_nEqns As Long
Private m_nVars As Long
Private m_Vals() As Double
Private m_fh As Long

' event tracking
Dim m_bEvent(20) As Boolean

' sub models
Private m_Spring As vbSpring
Private m_Damper As vbDamper
Private m_Engine As vbEngine
Private m_aRC As vbActuator
Private m_RC As vbClutch
Private m_aLRB As vbActuator
Private m_GLRB As vbFrame
Private m_LRB As vbBand_Brake
Private m_GOB As vbFrame
Private m_aOB As vbActuator
Private m_OB As vbBand_Brake
Private m_aDC As vbActuator
Private m_DC As vbClutch
Private m_aIOC As vbActuator
Private m_IOC As vbOneway_Clutch
Private m_GPOC As vbFrame
Private m_aPOC As vbActuator
Private m_POC As vbOneway_Clutch
Private m_aFC As vbActuator
Private m_FC As vbClutch
Private m_GIOC As vbFrame
Private m_Car As vbVehicle5
Private m_GearBox As vbRavigneaux
Private m_TC As vbTorque_Converter

Private Sub btnStart_Click()
  Dim startTime As Double
  Dim endTime As Double
  Dim sampleRate As Double

  ' time interval
  startTime = 0#
  endTime = 10#
  sampleRate = 0.1
  EsoTest startTime, endTime, sampleRate
  MsgBox "Complete"
End Sub

Sub EsoTest(startTime As Double, endTime As Double, sampleRate As Double)

  ' initialization
  InitializeModel startTime, endTime, sampleRate
  
  ' execution
  RunSimulation "c:\temp\demo_output.txt", startTime, endTime, sampleRate
End Sub

Public Sub InitializeModel(startTime As Double, endTime As Double, sampleRate As Double)
  Dim i As Long
  
  ' create executive and composite model
  Set m_Exec = New OnModelExec
  Set m_Composite = New vbComposite
  Set m_Model = m_Composite.Eso
  
  ' create the submodels
  Set m_Spring = New vbSpring
  Set m_Damper = New vbDamper
  Set m_Engine = New vbEngine
  Set m_aRC = New vbActuator
  Set m_RC = New vbClutch
  Set m_aLRB = New vbActuator
  Set m_GLRB = New vbFrame
  Set m_LRB = New vbBand_Brake
  Set m_GOB = New vbFrame
  Set m_aOB = New vbActuator
  Set m_OB = New vbBand_Brake
  Set m_aDC = New vbActuator
  Set m_DC = New vbClutch
  Set m_aIOC = New vbActuator
  Set m_IOC = New vbOneway_Clutch
  Set m_GPOC = New vbFrame
  Set m_aPOC = New vbActuator
  Set m_POC = New vbOneway_Clutch
  Set m_aFC = New vbActuator
  Set m_FC = New vbClutch
  Set m_GIOC = New vbFrame
  Set m_Car = New vbVehicle5
  Set m_GearBox = New vbRavigneaux
  Set m_TC = New vbTorque_Converter
  
  ' insert sub models into composite model
  m_Model.AddModel m_Engine.Eso, "Engine"
  m_Model.AddModel m_TC.Eso, "TC"
  m_Model.AddModel m_aRC.Eso, "aRC"
  m_Model.AddModel m_RC.Eso, "RC"
  m_Model.AddModel m_aLRB.Eso, "aLRB"
  m_Model.AddModel m_GLRB.Eso, "gLRB"
  m_Model.AddModel m_LRB.Eso, "LRB"
  m_Model.AddModel m_GOB.Eso, "gOB"
  m_Model.AddModel m_aOB.Eso, "aOB"
  m_Model.AddModel m_OB.Eso, "OB"
  m_Model.AddModel m_aDC.Eso, "aDC"
  m_Model.AddModel m_DC.Eso, "DC"
  m_Model.AddModel m_GIOC.Eso, "gIOC"
  m_Model.AddModel m_aIOC.Eso, "aIOC"
  m_Model.AddModel m_IOC.Eso, "IOC"
  m_Model.AddModel m_GPOC.Eso, "gPOC"
  m_Model.AddModel m_aPOC.Eso, "aPOC"
  m_Model.AddModel m_POC.Eso, "POC"
  m_Model.AddModel m_aFC.Eso, "aFC"
  m_Model.AddModel m_FC.Eso, "FC"
  m_Model.AddModel m_GearBox.Eso, "Gearbox"
  m_Model.AddModel m_Spring.Eso, "Spring"
  m_Model.AddModel m_Damper.Eso, "Damper"
  m_Model.AddModel m_Car.Eso, "Car"
  
  ' complete sub-model connections
  
  ' engine / torque_converter connections
  m_Model.Connect m_Engine.n, m_TC.impeller
  m_Model.Connect m_TC.turbine, m_FC.p
  m_Model.Connect m_TC.turbine, m_DC.p
  m_Model.Connect m_TC.turbine, m_RC.p
  
  ' clutch actuator and ground connections
  m_Model.Connect m_aRC.clutch, m_RC.actuator
  
  m_Model.Connect m_aLRB.clutch, m_LRB.actuator
  m_Model.Connect m_GLRB.p, m_LRB.p
  
  m_Model.Connect m_aOB.clutch, m_OB.actuator
  m_Model.Connect m_GOB.p, m_OB.p
  
  m_Model.Connect m_aDC.clutch, m_DC.actuator
  
  m_Model.Connect m_aIOC.clutch, m_IOC.actuator
  m_Model.Connect m_GIOC.p, m_IOC.p
  
  m_Model.Connect m_aPOC.clutch, m_POC.actuator
  m_Model.Connect m_GPOC.p, m_POC.p
  
  m_Model.Connect m_aFC.clutch, m_FC.actuator
  
  ' gearbox reverse sun connections
  m_Model.Connect m_OB.n, m_GearBox.reverseSun
  m_Model.Connect m_RC.n, m_GearBox.reverseSun
  m_Model.Connect m_IOC.n, m_GearBox.reverseSun
    
  ' gearbox coupler connections
  m_Model.Connect m_POC.n, m_GearBox.coupler
  m_Model.Connect m_LRB.n, m_GearBox.coupler
  m_Model.Connect m_DC.n, m_GearBox.coupler
  
  ' gearbox forward sun connections
  m_Model.Connect m_FC.n, m_GearBox.forwardSun
    
  ' gearbox to spring / damper (drive shaft) to vehicle
  m_Model.Connect m_GearBox.ring, m_Spring.p
  m_Model.Connect m_Spring.n, m_Car.p
  m_Model.Connect m_GearBox.ring, m_Damper.p
  m_Model.Connect m_Damper.n, m_Car.p
  
  ' Initiate the model initialization
  m_Model.CompositeModelComplete
  
  ' assign model to model executive
  m_Exec.SetModel m_Model
  
  ' initialize tolerance info
  m_Model.GetNumEqns m_nEqns
  ReDim tol(m_nEqns) As Double
  For i = 0 To m_nEqns
    tol(i) = 0.0001
  Next i
  m_Model.SetAbsTolerance tol
  m_Model.SetRelTolerance tol
  
  ' initialize time on model and driver
  m_Model.InitTime startTime, False
  
  ' initialize printing
  m_Model.GetNumVars m_nVars
  ReDim m_Vals(0 To m_nVars - 1) As Double
  
End Sub

Public Sub RunSimulation(FileName As String, startTime As Double, endTime As Double, sampleRate As Double)
  Dim t As Double
  
  ' open output file and print headings
  m_fh = FreeFile
  Open FileName For Output As #m_fh
  printVarNames
  
  ' issue engine start event
  m_Engine.startEvent 0#, 1
  m_Engine.throttleEvent 0#, 20#
  
  ' step through interval recording results
  m_Model.GetTime t
  While t <= endTime
    controlEvents t
    m_Exec.Step t
    printResults t
    t = t + sampleRate
  Wend
  
  ' cleanup
  Close #1
  
End Sub

' the following event list engages first gear at 0.7 seconds, and engages second gear at 2.2 seconds
Private Sub controlEvents(t As Double)
  ' (first gear) FC and POC engage
  If t >= 0.5 And Not m_bEvent(0) Then
    m_aFC.shiftEvent 0.5, 1
    m_aPOC.shiftEvent 0.5, 1
    m_bEvent(0) = True
  End If
  
  ' (second gear) POC disengage, IOC engage
  If t >= 2# And Not m_bEvent(1) Then
    m_aPOC.shiftEvent 2#, 0
    m_aIOC.shiftEvent 2#, 1
    m_bEvent(1) = True
  End If
  
  ' ramp throttle to 90%
  If t >= 5 And Not m_bEvent(2) Then
    m_Engine.throttleEvent 5#, 90#
    m_bEvent(2) = True
  End If
End Sub

Private Sub printVarNames()
  Dim VarNames() As String
  Dim i As Long
  
  m_Model.GetVarNames VarNames
  Print #m_fh, "Time" & vbTab;
  For i = 0 To m_nVars - 2
    Print #m_fh, VarNames(i) & vbTab;
  Next i
  Print #m_fh, VarNames(m_nVars - 1)
End Sub

Private Sub printResults(Time As Double)
  Dim i As Long
  
  m_Model.GetAllVariables Time, m_Vals
  Print #m_fh, Time & vbTab;
  For i = 0 To m_nVars - 2
    Print #m_fh, m_Vals(i) & vbTab;
  Next i
  Print #m_fh, m_Vals(m_nVars - 1)
End Sub

Private Sub Form_Unload(Cancel As Integer)
  Set m_Exec = Nothing
  Set m_Model = Nothing
  Set m_Composite = Nothing
  
  ' printing
  ReDim m_Vals(0) As Double

  ' sub models
  Set m_Spring = Nothing
  Set m_Damper = Nothing
  Set m_Engine = Nothing
  Set m_aRC = Nothing
  Set m_RC = Nothing
  Set m_aLRB = Nothing
  Set m_GLRB = Nothing
  Set m_LRB = Nothing
  Set m_GOB = Nothing
  Set m_aOB = Nothing
  Set m_OB = Nothing
  Set m_aDC = Nothing
  Set m_DC = Nothing
  Set m_aIOC = Nothing
  Set m_IOC = Nothing
  Set m_GPOC = Nothing
  Set m_aPOC = Nothing
  Set m_POC = Nothing
  Set m_aFC = Nothing
  Set m_FC = Nothing
  Set m_GIOC = Nothing
  Set m_Car = Nothing
  Set m_GearBox = Nothing
  Set m_TC = Nothing

End Sub

Private Sub m_Exec_AfterEvent(ByVal Time As Double)
  printResults Time
End Sub

Private Sub m_Exec_BeforeEvent(ByVal Time As Double)
  printResults Time
End Sub
