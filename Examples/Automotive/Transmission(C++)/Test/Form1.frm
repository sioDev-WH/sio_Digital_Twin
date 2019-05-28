VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()
  Dim aTransMSF As TransMSF
  Dim aOneWayMSF As OneWayMSF
  Dim aRavMSF As RavMSF
  Dim broadcastTest As CBroadcastTest
#If 0 Then
  Set aTransMSF = New TransMSF
  aTransMSF.Run
#End If

#If 0 Then
  Set aOneWayMSF = New OneWayMSF
  aOneWayMSF.Run
#End If

#If 1 Then
  Set aRavMSF = New RavMSF
  aRavMSF.Run
#End If

#If 0 Then
  Set broadcastTest = New CBroadcastTest
  broadcastTest.RunTest
#End If

End Sub
