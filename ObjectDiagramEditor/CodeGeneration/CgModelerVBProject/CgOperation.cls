VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgOperation"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public ClassName As String
Public Name As String
Public Description As String
Public bConstructor As Boolean
Public bDestructor As Boolean
Public sType As Long
Public sSubType As Long
Public sDiffType As Long
Public bSim As Boolean

Public ReturnType As String
Public Access As String
Public Parameters As Collection
Public Body As String
Public BodyLines As Collection
Public ReadOnly As Boolean
Public order As Long
Public idx As Long           ' index in the attribute category (used for code generation)

Public ConnId As String

Public obj As Object

Public OnCg As Boolean
Public bAutoDiff As Boolean

Public Sub AddLine(szLine As String)
  Dim aCgItem As CgItem
  
  Set aCgItem = New CgItem
  aCgItem.Name = szLine
  BodyLines.Add aCgItem
End Sub

Public Function AddPar(Name As String, dataType As String, Mechanism As String) As CgAttribute
  Dim ret As CgAttribute
  
  Set ret = New CgAttribute
  ret.Name = Name
  ret.dataType = dataType
  ret.Mechanism = Mechanism
  Parameters.Add ret
  Set AddPar = ret
End Function

Public Sub Copy(tgtOp As CgOperation)
  Dim aPar As CgAttribute
  Dim tgtPar As CgAttribute
  
  tgtOp.ClassName = ClassName
  tgtOp.Name = Name
  tgtOp.Description = Description
  tgtOp.bConstructor = bConstructor
  tgtOp.bDestructor = bDestructor
  tgtOp.sType = sType
  tgtOp.sSubType = sSubType
  tgtOp.sDiffType = sDiffType
  tgtOp.bSim = bSim
  tgtOp.ReturnType = ReturnType
  tgtOp.Access = Access
  
  For Each aPar In Parameters
    Set tgtPar = New CgAttribute
    aPar.Copy tgtPar
    tgtOp.Parameters.Add aPar
  Next
    
  tgtOp.Body = Body
  
  ' TODO: leave copying BodyLines for now.  I can't see needing this for anything.
  
  tgtOp.ReadOnly = ReadOnly
  tgtOp.order = order
  tgtOp.idx = idx
  tgtOp.ConnId = ConnId
  Set tgtOp.obj = obj
  
  tgtOp.OnCg = OnCg
  tgtOp.bAutoDiff = bAutoDiff
  
End Sub

Private Sub Class_Initialize()
  Set Parameters = New Collection
  Set BodyLines = New Collection
  bSim = False
  sType = idxOper_Continuous
  sSubType = idxOper_Scalar
  sDiffType = idxOperDiff_Automatic
End Sub

Public Sub CgInit()
  Dim aText As CgItem
  
  Body = ""
  For Each aText In BodyLines
    Body = Body & vbCrLf & aText.Name
  Next
  
End Sub

Public Function export() As String
  Dim szRet As String
  
  If bSim Then
    szRet = szRet & "<CgOperation Name=" & Chr(34) & Name & Chr(34)
    szRet = szRet & " sType=" & Chr(34) & sType & Chr(34)
    szRet = szRet & " sSubType=" & Chr(34) & sSubType & Chr(34)
    szRet = szRet & " sDiffType=" & Chr(34) & sDiffType & Chr(34)
    szRet = szRet & " />" & vbCrLf
  End If
  export = szRet
  
End Function

Public Sub import(aItem As IXMLDOMElement)
  bSim = True
  sType = aItem.getAttribute("sType")
  sSubType = aItem.getAttribute("sSubType")
  If IsNumeric(aItem.getAttribute("sDiffType")) Then
    sDiffType = aItem.getAttribute("sDiffType")
  Else
    sDiffType = idxOperDiff_Automatic
  End If
End Sub

Public Sub Save()

#If using_ilogix Then
  Dim aItem As RPModelElement
  Dim aOper As RPOperation
  
  On Error GoTo error_handler
  
  If Not obj Is Nothing Then
    Set aOper = obj
    aOper.setPropertyValue "Simulation.Operation.bSim", bSim
    aOper.setPropertyValue "Simulation.Operation.OnCg", OnCg
    aOper.setPropertyValue "Simulation.Operation.SimType", GetOperTypeFromId(sType)
    aOper.setPropertyValue "Simulation.Operation.SimSubType", GetOperSubTypeFromId(sSubType)
    aOper.setPropertyValue "Simulation.Operation.DiffType", GetOperDiffTypeFromId(sDiffType)
    aOper.setPropertyValue "Simulation.Operation.AutoDiff", bAutoDiff
    
    'aOper.initializer = bConstructor
    'aOper.isFinal = bDestructor
  End If
#End If

Exit Sub
error_handler:
  gMsgWnd.LogMessage "Error saving operation properties for operation '" & Name & "'of class '" & ClassName & "'. Error: " & err.Description
  Resume Next
End Sub

Public Sub Load()

  On Error GoTo error_handler
  
#If using_ilogix Then
  Dim aItem As RPModelElement
  Dim aOper As RPOperation
  Dim v As String
  
  If Not obj Is Nothing Then
    Set aOper = obj
    bSim = CBool(aOper.getPropertyValue("Simulation.Operation.bSim"))
    OnCg = CBool(aOper.getPropertyValue("Simulation.Operation.OnCg"))
    v = aOper.getPropertyValue("Simulation.Operation.SimType")
    sType = GetOperTypeId(v)
    v = aOper.getPropertyValue("Simulation.Operation.SimSubType")
    sSubType = GetOperSubTypeId(v)
    v = aOper.getPropertyValue("Simulation.Operation.DiffType")
    sDiffType = GetOperDiffTypeId(v)
    bAutoDiff = aOper.getPropertyValue("Simulation.Operation.AutoDiff")
  End If
#End If

  Exit Sub
error_handler:
  gMsgWnd.LogMessage "Error loading operation properties for operation '" & Name & "'of class '" & ClassName & "'. Error: " & err.Description
End Sub

