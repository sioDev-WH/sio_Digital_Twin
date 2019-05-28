VERSION 5.00
Begin VB.Form frmOnThrottle 
   Caption         =   "Throttle"
   ClientHeight    =   2520
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   1560
   Icon            =   "frmOnThrottle.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2520
   ScaleWidth      =   1560
   StartUpPosition =   3  'Windows Default
   Begin OnPlotLib.OnThrottle OnThrottle1 
      Height          =   2535
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   1575
      _ExtentX        =   2778
      _ExtentY        =   4471
   End
End
Attribute VB_Name = "frmOnThrottle"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Property Get Position() As Double
  Position = OnThrottle1.Throttle
End Property

Public Property Let Position(val As Double)
  OnThrottle1.Throttle = val
End Property

