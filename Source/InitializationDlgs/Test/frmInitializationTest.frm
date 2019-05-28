VERSION 5.00
Object = "{822F1C2C-743A-4BDF-96C2-9F1B6BA6134E}#1.0#0"; "OnInitialization.ocx"
Begin VB.Form frmInitializationTest 
   Caption         =   "Form1"
   ClientHeight    =   13050
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   12000
   LinkTopic       =   "Form1"
   ScaleHeight     =   13050
   ScaleWidth      =   12000
   StartUpPosition =   3  'Windows Default
   Begin OnInitialization.ctlInitialization InitDlg 
      Height          =   12855
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   11415
      _ExtentX        =   20135
      _ExtentY        =   22675
   End
End
Attribute VB_Name = "frmInitializationTest"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
  ' testing
  Dim nVars As Long
  ReDim VarNames(10) As String
  ReDim Vals(10) As Double
  ReDim DerVals(10) As Double
  Dim aV As clsVar

  nVars = 10
  VarNames(0) = "name0"
  VarNames(1) = "obj1.name0"                   ' 1
  VarNames(2) = "obj2.name0"                   ' 2
  VarNames(3) = "obj3.obj1.name0"              ' 4
  VarNames(4) = "obj3.obj2.name0"              ' 5
  VarNames(5) = "obj3.obj2.name1"
  VarNames(6) = "obj3.obj3.name0"              ' 6
  VarNames(7) = "obj3.obj3.obj2.obj1.name0"    ' 8
  VarNames(8) = "obj3.obj3.obj2.obj1.name1"
  VarNames(9) = "obj3.obj3.obj2.obj2.name0"    ' 9
  
  Dim i As Long
  For i = 0 To nVars - 1
    Vals(i) = i
    DerVals(i) = i * 10
  Next i
  
  InitDlg.initVars nVars, VarNames, Vals, DerVals
  
  Dim result As Double
  Dim sName As String
  Dim sScript As String
  Dim sFinalScript As String
  
  sName = "Test"
  sScript = "res = " & InitDlg.fmt(VarNames(3)) & " * " & InitDlg.fmt(VarNames(6)) & " + " & InitDlg.fmt(VarNames(9)) & ".der(1)"
  result = InitDlg.eval(sName, sScript, sFinalScript)
  
  Dim v As Collection
  Dim dv1 As Collection
  Dim dv2 As Collection
  Dim dv3 As Collection
  InitDlg.GetEqnStruct sScript, v, dv1, dv2, dv3, result
  
  Debug.Print sFinalScript
  For Each aV In v
    Debug.Print "V: "; aV.Name & ", " & aV.longName & ", " & aV.Idx
  Next
  
  For Each aV In dv1
    Debug.Print "DV1: "; aV.Name & ", " & aV.longName & ", " & aV.Idx
  Next
  
  For Each aV In dv2
    Debug.Print "DV2: "; aV.Name & ", " & aV.longName & ", " & aV.Idx
  Next
  
  For Each aV In dv3
    Debug.Print "DV3: "; aV.Name & ", " & aV.longName & ", " & aV.Idx
  Next

End Sub
