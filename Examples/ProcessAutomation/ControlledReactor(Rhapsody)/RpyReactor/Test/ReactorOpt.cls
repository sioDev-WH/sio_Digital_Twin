VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ReactorOpt"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Implements DIModel

Private T_Init As Double
Private T_End As Double
Private nPars As Long
Private parList() As Long

Public Sub SetStartTime(T As Double)
  T_Init = T
  T_End = T + 1#
End Sub

Private Sub Class_Initialize()
  ' hardcoded parameter index list
  ReDim parList(0 To 2) As Long
  parList(0) = IPAR_Q
  parList(1) = IPAR_K0
  parList(2) = IPAR_H
  nPars = 3

End Sub

Private Property Let DIModel_Dimension(ByVal RHS As Long)

End Property

Private Property Get DIModel_Dimension() As Long
  DIModel_Dimension = nPars
End Property

Private Function DIModel_EqualityConstraints(pArray() As Double) As Double()

End Function

#If 0 Then
Private Function DIModel_InequalityConstraints(pArray() As Double) As Double()
  Dim Q As Double
  
  ReDim retVal(6) As Double
  Q = pArray(0)
  retVal(0) = pArray(0) - 0.75
  retVal(1) = pArray(1) - 0.75
  retVal(2) = pArray(2) - 0.75
  retVal(3) = 1.25 - pArray(0)
  retVal(4) = 1.25 - pArray(1)
  retVal(5) = 1.25 - pArray(2)

  DIModel_InequalityConstraints = retVal
End Function
#Else
Private Function DIModel_InequalityConstraints(pArray() As Double) As Double()
  ReDim result(0 To 1) As Double
  
  result(0) = pArray(0) - 0.75
  result(1) = 1.25 - pArray(1)
End Function
#End If

Private Property Let DIModel_NEC(ByVal RHS As Long)
  
End Property

Private Property Get DIModel_NEC() As Long
  DIModel_NEC = 0
End Property

Private Property Let DIModel_NIC(ByVal RHS As Long)

End Property

Private Property Get DIModel_NIC() As Long
  DIModel_NIC = 0
End Property

Private Function DIModel_Objective(pArray() As Double) As Double
  Dim szFileName As String
  Dim i As Long
  Dim errVal As Double
  Dim iRec As Long
  Dim Time As Double
  
  If bCancel Then Exit Function
  
  mdlReactor.GetNumVars nVars
  ReDim varVals(0 To nVars - 1) As Double
  
  Time = T_Init
  szFileName = GetFileName(Time)
  modelExec.Load szFileName
  
  ' applying scaling
  ReDim scaledPars(3) As Double
  
  scaledPars(0) = pArray(0) * 3#           ' IPAR_Q
  scaledPars(1) = pArray(1) * 501000000#   ' IPAR_K0
  scaledPars(2) = pArray(2) * 605000#      ' IPAR_H

  'scaledPars(0) = 0.8 * 3#
  'scaledPars(1) = 501000000#
  'scaledPars(2) = 605000#
  
  ' set the parameter values on the model
  For i = 0 To nPars - 1
    mdlReactor.SetRealPar parList(i), scaledPars(i)
  Next i
  'modelExec.ForceReset
  
  Dim testVal As Double
  Dim modelVal As Double
  errVal = 0#
  Do While Time < T_End
    On Error Resume Next
    mTest.Step Time
    If Err = 0 Then
      mdlReactor.GetAllVariables Time, varVals
      
      iRec = 10 * Time
      For i = 0 To nSelectedVars - 1
        testVal = variableData(iRec, varList(i))
        If varList(i) = idxControllerOutput Then
          mTest.GetControllerOutput Time, modelVal
        Else
          modelVal = varVals(varList(i))
        End If
        errVal = errVal + ((testVal - modelVal) * (testVal - modelVal)) / (testVal * testVal)
      Next i
      Time = Time + 0.1
    Else
      errVal = 1E+66
      Exit Do
    End If
    DoEvents
    If bCancel Then Exit Function
  Loop
  
  'Debug.Print "T " & Time & ", Q " & pArray(0) & ", K0 " & pArray(1) & ", H " & pArray(2) & " err " & errVal
  DIModel_Objective = errVal
  DoEvents
  
End Function
