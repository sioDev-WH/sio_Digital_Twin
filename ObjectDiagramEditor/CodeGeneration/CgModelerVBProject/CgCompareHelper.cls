VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgCompareHelper"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
' COMPARE_SAME = &H0
' COMPARE_NEW = &H1
' COMPARE_OLD = &H2
' COMPARE_DIFF = &H4
' COMPARE_DIFF_AND_REPLACE = &H8

Public lCompare As Long

Public Name As String
Public strBody As String        'Used for Operation text
Public strOldBody As String     'Used for Operation text
Public strDataType As String
Public strDataTypeOld As String
Public strAccess As String
Public strAccessOld As String

Function AttributesEqual() As Boolean
    AttributesEqual = False
    If TypesEqual(strDataType, strDataTypeOld) And strAccess = strAccessOld Then AttributesEqual = True
End Function

Function RelationsEqual() As Boolean
    RelationsEqual = False
    'If TypesEqual(strDataType, strDataTypeOld) And strAccess = strAccessOld Then RelationsEqual = True
    If strAccess = strAccessOld Then RelationsEqual = True
End Function

Function OperationsEqual() As Boolean
    OperationsEqual = False
    If OperationBodiesEqual(strBody, strOldBody) And TypesEqual(strDataType, strDataTypeOld) And strAccess = strAccessOld Then OperationsEqual = True
End Function

Private Function TypesEqual(strDataType As String, strDataTypeOld As String) As Boolean
    If strDataType = strDataTypeOld Then
        TypesEqual = True
    ElseIf strDataType = "void" And strDataTypeOld = "" Then
        TypesEqual = True
    ElseIf strDataType = "" And strDataTypeOld = "void" Then
        TypesEqual = True
    Else
        TypesEqual = False
    End If
End Function

Private Function OperationBodiesEqual(strBody As String, strOldBody As String) As Boolean
    Dim strTempBody As String
    Dim strTempOldBody As String
    
    OperationBodiesEqual = False
    
    strTempBody = Replace(strBody, " ", "")
    strTempBody = Replace(strTempBody, vbCrLf, "")
    
    strTempOldBody = Replace(strOldBody, " ", "")
    strTempOldBody = Replace(strTempOldBody, vbCrLf, "")
    
    If strTempBody = strTempOldBody Then OperationBodiesEqual = True
End Function
