VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgTransition"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public Name As String
Public ResetEqns As Collection
Public SourceState As String
Public Triggers As Collection
Public obj As Object
Public order As Long
Public idx As Long           ' index in the attribute category (used for code generation)

Public count As Long ' placeholder

' iLogix specific (for now)
#If using_ilogix Then
Private m_Action As String
Private m_EventName As String
Private m_GuardCondition As String
Private m_EventType As String
#End If

' placeholder
Public ConnId As String

Private Sub Class_Initialize()
  Set Triggers = New Collection
  Set ResetEqns = New Collection
End Sub

Public Property Get Action() As String
#If using_ilogix Then
  Action = m_Action
#End If
End Property

Public Property Let Action(sAction As String)
#If using_ilogix Then
  m_Action = sAction
#End If
End Property

Public Property Get guardCondition() As String
#If using_ilogix Then
  guardCondition = m_GuardCondition
#End If
End Property

Public Property Let guardCondition(sGuardCondition As String)
#If using_ilogix Then
  m_GuardCondition = sGuardCondition
#End If
End Property

Public Property Get EventType() As String  ' Signal, Call, Time, Change
#If using_ilogix Then
  EventType = m_EventType
#End If
End Property

Public Property Let EventType(sEventType As String)
#If using_ilogix Then
  m_EventType = sEventType
#End If
End Property
    
Public Property Get EventName() As String
#If using_ilogix Then
  EventName = m_EventName
#End If
End Property

Public Property Let EventName(sEventName As String)
#If using_ilogix Then
  m_EventName = sEventName
#End If
End Property

Public Function export() As String
  Dim szRet As String
  Dim aTrigger As CgTrigger
  Dim aEqn As CgItem
  
  szRet = szRet & "<CgTransition Name=" & Chr(34) & Name & Chr(34) & " >" & vbCrLf
  For Each aEqn In ResetEqns
    szRet = szRet & "  <Eqn Name=" & Chr(34) & aEqn.Name & Chr(34) & " />" & vbCrLf
  Next
  For Each aTrigger In Triggers
    szRet = szRet & aTrigger.export
  Next
  szRet = szRet & "</CgTransition>" & vbCrLf
  export = szRet
  
End Function

Public Sub import(Operations As Collection, elem As IXMLDOMElement)
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aTrigger As CgTrigger
  Dim i As Long
  Dim aCgItem As CgItem
  Dim srcOper As CgOperation
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
      ResetEqns.Add aCgItem, aCgItem.Name
    End If
  Next i
  
  Set aNodeList = elem.getElementsByTagName("CgTrigger")
  For i = 0 To aNodeList.length - 1
    Set aItem = aNodeList.Item(i)
    Set aTrigger = New CgTrigger
    aTrigger.import Operations, aItem
    Triggers.Add aTrigger
  Next i
End Sub

Public Sub Save()

#If using_ilogix Then
  Dim s As String
  Dim aTrigger As CgTrigger
  Dim aEqn As CgItem
  Dim aTransition As RPTransition
  
  If Not obj Is Nothing Then
    Set aTransition = obj
    
    ' reset equations
    s = "<CgTransition Name=" & Chr(34) & Name & Chr(34) & " xmlns= " & Chr(34) & "x-schema:\xmldata\ModelDefinition.xml" & Chr(34) & ">" & vbCrLf
    For Each aEqn In ResetEqns
      s = s & "  <Eqn Name=" & Chr(34) & aEqn.Name & Chr(34) & " />" & vbCrLf
    Next
    s = s & "</CgTransition>" & vbCrLf
    aTransition.setPropertyValue "Simulation.Transition.nResetEqn", ResetEqns.count
    aTransition.setPropertyValue "Simulation.Transition.ResetEqns", s
    
    ' triggers
    s = "<CgTransition Name=" & Chr(34) & Name & Chr(34) & " xmlns= " & Chr(34) & "x-schema:\xmldata\ModelDefinition.xml" & Chr(34) & ">" & vbCrLf
    For Each aTrigger In Triggers
      s = s & aTrigger.export
    Next
    s = s & "</CgTransition>" & vbCrLf
    aTransition.setPropertyValue "Simulation.Transition.nTrigger", Triggers.count
    aTransition.setPropertyValue "Simulation.Transition.Triggers", s

  End If
#End If

End Sub

Public Sub Load(Operations As Collection)

#If using_ilogix Then
  Dim aDoc As DOMDocument
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aTrigger As CgTrigger
  Dim i As Long
  Dim aCgItem As CgItem
  Dim srcOper As CgOperation
  Dim EqnName As String
  Dim aTransition As RPTransition
  
  If Not obj Is Nothing Then
    Set aTransition = obj
  
    'm_Action = aTransition.getItsAction.Body
    If Not aTransition.getItsTrigger Is Nothing Then
        m_EventName = aTransition.getItsTrigger.Body
    End If
    'm_GuardCondition = aTransition.getItsGuard.Body
    'm_EventType = aTransition.

    On Error Resume Next
    Set aDoc = New DOMDocument
    
    If aDoc.loadXML(aTransition.getPropertyValue("Simulation.Transition.ResetEqns")) Then
      Set aNodeList = aDoc.getElementsByTagName("Eqn")
  
      For i = 0 To aNodeList.length - 1
        Set aItem = aNodeList.Item(i)
        EqnName = aItem.getAttribute("Name")
        Set srcOper = Operations(EqnName)
        
        If Err = 0 Then
          Set aCgItem = New CgItem
          aCgItem.bSim = True
          aCgItem.Name = EqnName
          ResetEqns.Add aCgItem, aCgItem.Name
        End If
      Next i
    End If
    
    If aDoc.loadXML(aTransition.getPropertyValue("Simulation.Transition.Triggers")) Then
      Set aNodeList = aDoc.getElementsByTagName("CgTrigger")
      For i = 0 To aNodeList.length - 1
        Set aItem = aNodeList.Item(i)
        Set aTrigger = New CgTrigger
        aTrigger.import Operations, aItem
        Triggers.Add aTrigger
      Next i
    End If
    
  End If
  
#End If

End Sub
