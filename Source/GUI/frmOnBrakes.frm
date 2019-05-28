VERSION 5.00
Begin VB.Form frmOnBrakes 
   Caption         =   "Brake Pedal"
   ClientHeight    =   1860
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   2550
   Icon            =   "frmOnBrakes.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1860
   ScaleWidth      =   2550
   StartUpPosition =   3  'Windows Default
   Begin OnPlotLib.OnBrakes OnBrakes1 
      Height          =   1695
      Left            =   0
      TabIndex        =   0
      Top             =   120
      Width           =   2535
      _ExtentX        =   4471
      _ExtentY        =   2990
   End
End
Attribute VB_Name = "frmOnBrakes"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Property Let Brake(val As Double)
  OnBrakes1.Brake = val
End Property

Public Property Get Brake() As Double
  Brake = OnBrakes1.Brake
End Property

