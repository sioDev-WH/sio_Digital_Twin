VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgState"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public className As String
Public Eqns As Collection
Public Name As String
Public IsDefault As Boolean
Public Order As Long
Public idx As Long           ' index in the attribute category (used for code generation)

Public obj As Object

' iLogix specific (for now)
Public entryAction As String
Public exitAction As String

' placeholder
Public ConnId As String

Private Sub Class_Initialize()
  Set Eqns = New Collection
  IsDefault = False
End Sub

Public Function export() As String
  Dim szRet As String
  Dim aEqn As CgItem
  
  szRet = szRet & "<CgState Name=" & Chr(34) & Name & Chr(34) & " >" & vbCrLf
  For Each aEqn In Eqns
    szRet = szRet & "  <Eqn Name=" & Chr(34) & aEqn.Name & Chr(34) & " />" & vbCrLf
  Next
  szRet = szRet & "</CgState>" & vbCrLf
  export = szRet
  
End Function

Public Sub import(Operations As Collection, elem As IXMLDOMElement)
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aCgItem As CgItem
  Dim srcOper As CgOperation
  Dim i As Long
  Dim EqnName As String
  
  On Error Resume Next
  Set aNodeList = elem.getElementsByTagName("Eqn")
  For i = 0 To aNodeList.length - 1
    Set aItem = aNodeList.Item(i)
    EqnName = aItem.getAttribute("Name")
    Set srcOper = Operations(EqnName)
    
    If Err = 0 Then
      Set aCgItem = New CgItem
      aCgItem.bSim = True
      aCgItem.Name = EqnName
      Eqns.Add aCgItem, aCgItem.Name
    End If
  Next i
End Sub

Public Sub Save()
  Dim s As String
  Dim aEqn As CgItem
  Dim aState As RPState
  
#If using_ilogix Then
  If Not obj Is Nothing Then
    
    s = "<CgState Name=" & Chr(34) & Name & Chr(34) & " xmlns= " & Chr(34) & "x-schema:\xmldata\ModelDefinition.xml" & Chr(34) & ">" & vbCrLf
    For Each aEqn In Eqns
      s = s & "  <Eqn Name=" & Chr(34) & aEqn.Name & Chr(34) & " />" & vbCrLf
    Next
    s = s & "</CgState>" & vbCrLf
  
    Set aState = obj
    aState.setPropertyValue "Simulation.State.nEqn", Eqns.count
    aState.setPropertyValue "Simulation.State.Eqns", s
  End If
#End If

End Sub

Public Sub Load(Operations As Collection)
  
#If using_ilogix Then
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aCgItem As CgItem
  Dim srcOper As CgOperation
  Dim i As Long
  Dim EqnName As String
  Dim aDoc As DOMDocument
  Dim aState As RPState
  
  If Not obj Is Nothing Then
    Set aState = obj

    On Error Resume Next
    Set aDoc = New DOMDocument
    If aDoc.loadXML(aState.getPropertyValue("Simulation.State.Eqns")) Then
    
      Set aNodeList = aDoc.getElementsByTagName("Eqn")
      For i = 0 To aNodeList.length - 1
        Set aItem = aNodeList.Item(i)
        EqnName = aItem.getAttribute("Name")
        Set srcOper = Operations(EqnName)
        
        If Err = 0 Then
          Set aCgItem = New CgItem
          aCgItem.bSim = True
          aCgItem.Name = EqnName
          Eqns.Add aCgItem, aCgItem.Name
        End If
      Next i
    End If
  End If
#End If

End Sub
