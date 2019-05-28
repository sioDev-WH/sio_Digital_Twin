VERSION 5.00
Begin VB.Form frmReactorTest 
   Caption         =   "RpyPDEReactorTest"
   ClientHeight    =   2025
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7290
   LinkTopic       =   "Form1"
   ScaleHeight     =   2025
   ScaleWidth      =   7290
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnRun 
      Caption         =   "Run"
      Height          =   855
      Left            =   1440
      TabIndex        =   0
      Top             =   480
      Width           =   4575
   End
End
Attribute VB_Name = "frmReactorTest"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim m_ReactorTest As RpyPDEReactorTest
Dim m_StartTime As Double
Dim m_EndTime As Double
Dim m_StepSize As Double
Dim m_Time As Double

Private Sub btnRun_Click()
  
  Set m_ReactorTest = New RpyPDEReactorTest
  m_StartTime = 0#
  m_EndTime = 10#
  m_StepSize = 0.1
  
  m_Time = m_StartTime
  Do While m_Time < m_EndTime
    m_ReactorTest.Step m_Time
    m_Time = m_Time + m_StepSize
  Loop
    
  MsgBox "Simulation of reactor complete"
  
End Sub

