VERSION 5.00
Object = "{D8845A22-B5DD-432F-A81D-45A3B9DEEEEC}#1.0#0"; "CGModeler_iLogix.ocx"
Begin VB.Form Form1 
   Caption         =   "ON Extended System Context"
   ClientHeight    =   8310
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   11340
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   8310
   ScaleWidth      =   11340
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin CGModeler.ucMain ucMain1 
      Height          =   7575
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   9975
      _ExtentX        =   17595
      _ExtentY        =   13361
   End
   Begin VB.Menu mnuTmp 
      Caption         =   "Tmp"
      Index           =   0
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Sub UnloadForm()
    Form_Terminate
End Sub
Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
  ucMain1.SaveIniSettings
End Sub

Private Sub Form_Resize()
  'On Error Resume Next
  ucMain1.Move 0, 0, Me.ScaleWidth, Me.ScaleHeight
  ucMain1.GeCtrl.ZoomPage
End Sub

Private Sub Form_Terminate()
    Unload Me
End Sub

Private Sub ucMain1_CaptionChanged(ByVal strCaption As String)
  Me.Caption = "Artist - " & strCaption
End Sub
