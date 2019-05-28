VERSION 5.00
Begin VB.Form frmOnShiftLever 
   Caption         =   "Shift Lever"
   ClientHeight    =   2820
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   1830
   Icon            =   "frmOnShiftLever.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2820
   ScaleWidth      =   1830
   StartUpPosition =   3  'Windows Default
   Begin OnPlotLib.OnShiftLever OnShiftLever1 
      Height          =   2775
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   1815
      _ExtentX        =   3201
      _ExtentY        =   4895
   End
End
Attribute VB_Name = "frmOnShiftLever"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Property Let Position(val As Long)
  OnShiftLever1.Position = val
End Property

Public Property Get Position() As Long
  Position = OnShiftLever1.Position
End Property

