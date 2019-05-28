VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   1560
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   1560
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox CheckPhase 
      Caption         =   "Phase"
      Height          =   255
      Left            =   360
      TabIndex        =   3
      Top             =   1200
      Width           =   855
   End
   Begin VB.CommandButton ResumeButton 
      Caption         =   "Resume"
      Height          =   375
      Left            =   2040
      TabIndex        =   2
      Top             =   480
      Width           =   855
   End
   Begin VB.CommandButton PauseButton 
      Caption         =   "Pause"
      Height          =   375
      Left            =   1200
      TabIndex        =   1
      Top             =   480
      Width           =   855
   End
   Begin VB.CommandButton ExitButton 
      Caption         =   "Exit"
      Height          =   375
      Left            =   2880
      TabIndex        =   0
      Top             =   480
      Width           =   855
   End
   Begin VB.Timer Timer1 
      Interval        =   10
      Left            =   0
      Top             =   0
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim OnPlot As OnPlotExe.OnPlotObject
Dim OnShiftLever As OnPlotExe.OnShiftLever
Dim OnThrottle As OnPlotExe.OnThrottle
Dim OnBrakes As OnPlotExe.OnBrakes
 Dim someVars(3) As Double
 Dim Time As Double
 Dim numberOfSeries As Long
Dim SamplingInterval As Double
Dim bPoint As Boolean

Private Sub CheckPhase_Click()
    
    Set OnPlot = Nothing
    Set OnPlot = New OnPlotLib.OnPlotObject
    If numberOfSeries > 1 Then
     numberOfSeries = 1
     bPoint = True
     Else
     numberOfSeries = 2
     bPoint = False
     End If
    OnPlot.initPlot numberOfSeries, bPoint
End Sub

Private Sub Form_Load()

Set OnPlot = New OnPlotExe.OnPlotObject
Set OnShiftLever = New OnPlotExe.OnShiftLever
Set OnThrottle = New OnPlotExe.OnThrottle
Set OnBrakes = New OnPlotExe.OnBrakes

numberOfSeries = 2 ' e.g., 2 vars vs time
bPoint = False ' vs point
OnPlot.initPlot numberOfSeries, bPoint
Time = 0 ' someVars(1) = 0 ' init time to zero
SamplingInterval = 50
OnShiftLever.initLever
OnThrottle.initThrottle
OnBrakes.initBrakes

Timer1.Interval = SamplingInterval
End Sub

Private Sub ExitButton_Click()
    OnPlot.cleanPlot
    SamplingInterval = 0
    Timer1.Interval = SamplingInterval
    Set OnPlot = Nothing
End Sub
Private Sub PauseButton_Click()
    Timer1.Interval = 0
End Sub
Private Sub ResumeButton_Click()
    Timer1.Interval = SamplingInterval
End Sub
Private Sub Timer1_Timer()

Dim PI As Double
Dim throttlePosition As Double
Dim brakesPosition As Double
Dim leverPosition As Long
 
PI = 3.14159265358979
If Timer1.Interval > 0 Then
    Time = Time + SamplingInterval / 1000
    OnThrottle.getPosition throttlePosition
    OnShiftLever.getPosition leverPosition
    OnBrakes.getPosition brakesPosition
    Debug.Print leverPosition, throttlePosition, brakesPosition
    If CheckPhase.Value = 0 Then
        someVars(1) = Time
        someVars(2) = Cos(2 * PI * Time)
        someVars(3) = Sin(2 * PI * Time)
        OnPlot.plotData someVars, 3
    Else 'Phase chart
        someVars(1) = Cos(2 * PI * Time)
        someVars(2) = Sin(2 * PI * Time)
        OnPlot.plotData someVars, 2
    End If
End If
End Sub
