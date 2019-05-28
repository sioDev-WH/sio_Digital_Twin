VERSION 5.00
Object = "{008BBE7B-C096-11D0-B4E3-00A0C901D681}#1.0#0"; "TeeChart.ocx"
Object = "{BDC217C8-ED16-11CD-956C-0000C04E4C0A}#1.1#0"; "TABCTL32.OCX"
Begin VB.Form Form1 
   Caption         =   "Process diagnostics"
   ClientHeight    =   9645
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   11205
   LinkTopic       =   "Form1"
   ScaleHeight     =   9645
   ScaleWidth      =   11205
   StartUpPosition =   3  'Windows Default
   Begin TabDlg.SSTab tabVariables 
      Height          =   4575
      Left            =   5640
      TabIndex        =   17
      Top             =   5040
      Width           =   5415
      _ExtentX        =   9551
      _ExtentY        =   8070
      _Version        =   393216
      Style           =   1
      Tab             =   2
      TabHeight       =   520
      TabCaption(0)   =   "C_Toluene"
      TabPicture(0)   =   "Form1.frx":0000
      Tab(0).ControlEnabled=   0   'False
      Tab(0).Control(0)=   "chartC_Toluene"
      Tab(0).Control(0).Enabled=   0   'False
      Tab(0).ControlCount=   1
      TabCaption(1)   =   "T_Heater"
      TabPicture(1)   =   "Form1.frx":001C
      Tab(1).ControlEnabled=   0   'False
      Tab(1).Control(0)=   "chartT_Heater"
      Tab(1).Control(0).Enabled=   0   'False
      Tab(1).ControlCount=   1
      TabCaption(2)   =   "T_Reactor"
      TabPicture(2)   =   "Form1.frx":0038
      Tab(2).ControlEnabled=   -1  'True
      Tab(2).Control(0)=   "chartT_Reactor"
      Tab(2).Control(0).Enabled=   0   'False
      Tab(2).ControlCount=   1
      Begin TeeChart.TChart chartT_Reactor 
         Height          =   3975
         Left            =   120
         OleObjectBlob   =   "Form1.frx":0054
         TabIndex        =   23
         Top             =   480
         Width           =   5175
      End
      Begin TeeChart.TChart chartT_Heater 
         Height          =   3975
         Left            =   -74880
         OleObjectBlob   =   "Form1.frx":0163
         TabIndex        =   22
         Top             =   480
         Width           =   5175
      End
      Begin TeeChart.TChart chartC_Toluene 
         Height          =   3975
         Left            =   -74880
         OleObjectBlob   =   "Form1.frx":0275
         TabIndex        =   21
         Top             =   480
         Width           =   5175
      End
   End
   Begin TabDlg.SSTab tabParameters 
      Height          =   4575
      Left            =   120
      TabIndex        =   16
      Top             =   5040
      Width           =   5415
      _ExtentX        =   9551
      _ExtentY        =   8070
      _Version        =   393216
      Style           =   1
      TabHeight       =   520
      TabCaption(0)   =   "Q"
      TabPicture(0)   =   "Form1.frx":0366
      Tab(0).ControlEnabled=   -1  'True
      Tab(0).Control(0)=   "chartQ"
      Tab(0).Control(0).Enabled=   0   'False
      Tab(0).ControlCount=   1
      TabCaption(1)   =   "K0"
      TabPicture(1)   =   "Form1.frx":0382
      Tab(1).ControlEnabled=   0   'False
      Tab(1).Control(0)=   "chartK0"
      Tab(1).Control(0).Enabled=   0   'False
      Tab(1).ControlCount=   1
      TabCaption(2)   =   "h"
      TabPicture(2)   =   "Form1.frx":039E
      Tab(2).ControlEnabled=   0   'False
      Tab(2).Control(0)=   "chartH"
      Tab(2).Control(0).Enabled=   0   'False
      Tab(2).ControlCount=   1
      Begin TeeChart.TChart chartH 
         Height          =   3975
         Left            =   -74880
         OleObjectBlob   =   "Form1.frx":03BA
         TabIndex        =   20
         Top             =   480
         Width           =   5175
      End
      Begin TeeChart.TChart chartK0 
         Height          =   3975
         Left            =   -74880
         OleObjectBlob   =   "Form1.frx":0530
         TabIndex        =   19
         Top             =   480
         Width           =   5175
      End
      Begin TeeChart.TChart chartQ 
         Height          =   3975
         Left            =   120
         OleObjectBlob   =   "Form1.frx":06A6
         TabIndex        =   18
         Top             =   480
         Width           =   5175
      End
   End
   Begin VB.Frame frmParameterEstimation 
      Caption         =   "Parameter Estimation"
      Height          =   2775
      Left            =   120
      TabIndex        =   5
      Top             =   2160
      Width           =   10935
      Begin VB.CommandButton btnCancel 
         Caption         =   "Cancel"
         Height          =   495
         Left            =   8520
         TabIndex        =   25
         Top             =   840
         Width           =   2295
      End
      Begin VB.CommandButton btnParameterEstimation 
         Caption         =   "Parameter Estimation"
         Height          =   495
         Left            =   8520
         TabIndex        =   8
         Top             =   240
         Width           =   2295
      End
      Begin VB.ListBox lbVariables 
         Height          =   2010
         Left            =   120
         MultiSelect     =   2  'Extended
         TabIndex        =   6
         Top             =   600
         Width           =   5895
      End
      Begin VB.Label Label2 
         Caption         =   "Selected Variables for error calculations"
         Height          =   255
         Left            =   120
         TabIndex        =   24
         Top             =   360
         Width           =   5895
      End
   End
   Begin VB.Frame frmRecordFault 
      Caption         =   "Record fault condition(s)"
      Height          =   1815
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   10935
      Begin VB.TextBox txtSetpointSlew 
         Height          =   285
         Left            =   9480
         TabIndex        =   33
         Text            =   "0.0"
         Top             =   1320
         Width           =   1095
      End
      Begin VB.TextBox txtSetpoint 
         Height          =   285
         Left            =   8280
         TabIndex        =   32
         Text            =   "740.0"
         Top             =   1320
         Width           =   1095
      End
      Begin VB.TextBox txtSlew 
         Height          =   285
         Index           =   2
         Left            =   6120
         TabIndex        =   29
         Text            =   "0.0"
         Top             =   1320
         Width           =   1695
      End
      Begin VB.TextBox txtSlew 
         Height          =   285
         Index           =   1
         Left            =   6120
         TabIndex        =   28
         Text            =   "0.0"
         Top             =   960
         Width           =   1695
      End
      Begin VB.TextBox txtSlew 
         Height          =   285
         Index           =   0
         Left            =   6120
         TabIndex        =   27
         Text            =   "0.0"
         Top             =   600
         Width           =   1695
      End
      Begin VB.CheckBox chkParameters 
         Caption         =   "Check1"
         Height          =   255
         Index           =   2
         Left            =   120
         TabIndex        =   15
         Top             =   1320
         Width           =   255
      End
      Begin VB.ComboBox cmbParameters 
         Height          =   315
         Index           =   2
         Left            =   480
         TabIndex        =   14
         Top             =   1320
         Width           =   3735
      End
      Begin VB.TextBox txtPercent 
         Height          =   285
         Index           =   2
         Left            =   4320
         TabIndex        =   13
         Text            =   "100.0"
         Top             =   1320
         Width           =   1695
      End
      Begin VB.CheckBox chkParameters 
         Caption         =   "Check1"
         Height          =   255
         Index           =   1
         Left            =   120
         TabIndex        =   12
         Top             =   960
         Width           =   255
      End
      Begin VB.ComboBox cmbParameters 
         Height          =   315
         Index           =   1
         Left            =   480
         TabIndex        =   11
         Top             =   960
         Width           =   3735
      End
      Begin VB.TextBox txtPercent 
         Height          =   285
         Index           =   1
         Left            =   4320
         TabIndex        =   10
         Text            =   "100.0"
         Top             =   960
         Width           =   1695
      End
      Begin VB.CheckBox chkParameters 
         Caption         =   "Check1"
         Height          =   255
         Index           =   0
         Left            =   120
         TabIndex        =   9
         Top             =   600
         Width           =   255
      End
      Begin VB.CommandButton btnRecordSnapshots 
         Caption         =   "Record Fault Snapshots"
         Height          =   495
         Left            =   8520
         TabIndex        =   7
         Top             =   240
         Width           =   2295
      End
      Begin VB.TextBox txtPercent 
         Height          =   285
         Index           =   0
         Left            =   4320
         TabIndex        =   3
         Text            =   "100.0"
         Top             =   600
         Width           =   1695
      End
      Begin VB.ComboBox cmbParameters 
         Height          =   315
         Index           =   0
         Left            =   480
         TabIndex        =   1
         Top             =   600
         Width           =   3735
      End
      Begin VB.Label Label5 
         Caption         =   "Slew factor"
         Height          =   375
         Left            =   9480
         TabIndex        =   31
         Top             =   1080
         Width           =   1095
      End
      Begin VB.Label Label4 
         Caption         =   "Setpoint"
         Height          =   255
         Left            =   8280
         TabIndex        =   30
         Top             =   1080
         Width           =   855
      End
      Begin VB.Label Label3 
         Caption         =   "Slew factor"
         Height          =   375
         Left            =   6120
         TabIndex        =   26
         Top             =   360
         Width           =   1815
      End
      Begin VB.Label Label1 
         Caption         =   "Percent of normal value"
         Height          =   375
         Left            =   4320
         TabIndex        =   4
         Top             =   360
         Width           =   1815
      End
      Begin VB.Label lblParameters 
         Caption         =   "Selected Parameter"
         Height          =   375
         Left            =   480
         TabIndex        =   2
         Top             =   360
         Width           =   2775
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_bDialogInit As Boolean

Private Sub btnCancel_Click()
  bCancel = True
End Sub

Private Sub btnRecordSnapshots_Click()
  Dim i As Long
  Dim nPars As Long
  ReDim parIdxList(3) As Long
  ReDim parValList(3) As Double
  ReDim parSlewList(3) As Double
  Dim SetPoint As Double
  Dim SetPointSlew As Double
  
  ' init the model
  init

  bCancel = False
  nPars = 0
  For i = 0 To 2
    If chkParameters(i).Value = Checked And cmbParameters(i).ListIndex >= 0 Then
      parIdxList(nPars) = cmbParameters(i).ListIndex
      parValList(nPars) = CDbl(txtPercent(i).Text)
      parSlewList(nPars) = CDbl(txtSlew(i).Text)
      nPars = nPars + 1
    End If
  Next i
  
  SetPoint = CDbl(txtSetpoint.Text)
  SetPointSlew = CDbl(txtSetpointSlew.Text)
  
  ReDim varCharts(3) As TChart
  Set varCharts(0) = chartC_Toluene
  Set varCharts(1) = chartT_Reactor
  Set varCharts(2) = chartT_Heater

  If nPars > 0 Then
    For i = 0 To 2
      varCharts(i).RemoveAllSeries
      varCharts(i).AddSeries scLine
    Next i
    
    RecordSnapshots parIdxList, parValList, parSlewList, SetPoint, SetPointSlew, nPars, varCharts
    MsgBox "Complete"
  Else
    MsgBox "Select a parameter for error injection"
  End If
  
  ' init for next run
End Sub

Private Sub btnParameterEstimation_Click()
  Dim i As Long
  
  bCancel = False
  If lbVariables.SelCount < 1 Then
    MsgBox "Select at least one variable for error calculation"
    Exit Sub
  End If
  
  nSelectedVars = 0
  ReDim varList(lbVariables.SelCount) As Long
  
  ' get the selected vars for error calculation
  For i = 0 To lbVariables.ListCount - 1
    If lbVariables.Selected(i) Then
      varList(nSelectedVars) = i
      nSelectedVars = nSelectedVars + 1
    End If
  Next i
  
  ReDim paramCharts(0 To 2) As TChart
  Set paramCharts(0) = chartQ
  Set paramCharts(1) = chartK0
  Set paramCharts(2) = chartH
  
  ' initialize all charts
  For i = 0 To 2
    paramCharts(i).RemoveAllSeries
    paramCharts(i).AddSeries scLine
    paramCharts(i).Series(0).AddXY -0.1, 0#, "", 0
  Next i
  
  parameterEstimation paramCharts
End Sub

Private Sub Form_Load()
  init
End Sub

Private Sub init()
  Dim i As Long
  Dim j As Long
  Dim lb As Long
  Dim ub As Long
  
  ' create the test object
  Set mTest = New RpyReactorTestHarness
  mTest.GetModel mdlReactor
  mTest.GetModelExec modelExec
  
  ' initialize the paramter names
  ReDim names(0) As String
  mdlReactor.GetRParNames names
  lb = LBound(names)
  ub = UBound(names)
  
  If Not m_bDialogInit Then
    For i = lb To ub
      For j = 0 To 2
        cmbParameters(j).AddItem names(i)
      Next j
    Next i
  End If
  
  ' initialize the variable names
  ReDim names(0) As String
  mdlReactor.GetVarNames names
  lb = LBound(names)
  ub = UBound(names)
  
  If Not m_bDialogInit Then
    For i = lb To ub
      lbVariables.AddItem names(i)
    Next i
    idxControllerOutput = lbVariables.ListCount
    lbVariables.AddItem "Controller.CO"
    m_bDialogInit = True
  End If

End Sub
