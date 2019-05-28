Attribute VB_Name = "XMLUtilities"
Option Explicit

Public Sub ExportModel(ModelType As Long, Attributes As Collection, Operations As Collection, States As Collection, Transitions As Collection, szXML As String)
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim aState As CgState
  Dim aTrans As CgTransition
  
  If ModelType < 1 Then ModelType = idxClassType_NonSimulation
  szXML = szXML & "<CgModel ClassType=" & Chr(34) & ModelType & Chr(34) & " xmlns=" & Chr(34) & "x-schema:\xmldata\ModelDefinition.xml" & Chr(34) & "> " & vbCrLf
  For Each aAttr In Attributes
    szXML = szXML & aAttr.export
  Next
  
  For Each aOper In Operations
    szXML = szXML & aOper.export
  Next
  
  For Each aState In States
    szXML = szXML & aState.export
  Next
  
  For Each aTrans In Transitions
    szXML = szXML & aTrans.export
  Next
  
  szXML = szXML & "</CgModel>"
End Sub

Public Sub ImportModel(ModelType As Long, Attributes As Collection, Operations As Collection, States As Collection, Transitions As Collection, szXML As String)
  Dim aDoc As DOMDocument
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim aState As CgState
  Dim aTrans As CgTransition
  Dim i As Long
  Dim ItemName As String
  Dim order As Long
  
  Set aDoc = New DOMDocument
  
  'If Not aDoc.loadXML(szXML) Then
  '  MsgBox aDoc.parseError.reason & "," & aDoc.parseError.errorCode & ", " & aDoc.parseError.filepos & ", " & aDoc.parseError.Line & ", " & aDoc.parseError.srcText & ", " & aDoc.parseError.url
  'End If
  
  If aDoc.loadXML(szXML) Then
    If IsNull(aDoc.documentElement.getAttribute("ClassType")) Then
      ModelType = idxClassType_NonSimulation
    Else
      ModelType = aDoc.documentElement.getAttribute("ClassType")
    End If
    Set aNodeList = aDoc.getElementsByTagName("CgAttribute")
    order = 0
    For i = 0 To aNodeList.length - 1
      Set aItem = aNodeList.Item(i)
      On Error Resume Next
      ItemName = aItem.getAttribute("Name")
      Set aAttr = Attributes(ItemName)
      If Err = 0 Then
        aAttr.import aItem
        ' mark models and connectors with the order in which they appear in the document
        ' NOTE: this order is used during code generation of the model, and subsequently to link
        '       this model to other models in a composition
        If (aAttr.sType = idxAttr_Connector Or aAttr.sType = idxAttr_Model) And aAttr.bSim Then
          aAttr.order = order
          order = order + 1
        End If
      End If
    Next i
    
    Set aNodeList = aDoc.getElementsByTagName("CgOperation")
    For i = 0 To aNodeList.length - 1
      Set aItem = aNodeList.Item(i)
      On Error Resume Next
      ItemName = aItem.getAttribute("Name")
      Set aOper = Operations(ItemName)
      If Err = 0 Then
        aOper.import aItem
      End If
    Next i
    
    Set aNodeList = aDoc.getElementsByTagName("CgState")
    For i = 0 To aNodeList.length - 1
      Set aItem = aNodeList.Item(i)
      On Error Resume Next
      ItemName = aItem.getAttribute("Name")
      Set aState = States(ItemName)
      If Err = 0 Then
        aState.import Operations, aItem
      End If
    Next i
    
    Set aNodeList = aDoc.getElementsByTagName("CgTransition")
    For i = 0 To aNodeList.length - 1
      Set aItem = aNodeList.Item(i)
      On Error Resume Next
      ItemName = aItem.getAttribute("Name")
      Set aTrans = Transitions(ItemName)
      If Err = 0 Then
        aTrans.import Operations, aItem
      End If
    Next i
  End If
  
End Sub


