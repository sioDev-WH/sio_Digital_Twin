VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgAttribute"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public ClassName As String
Public Name As String
Public Description As String
Public dataType As String
Public Access As String
Public Mechanism As String
Public bSim As Boolean
Public sType As Long
Public sSubType As Long
Public obj As Object

Public bAggregate As Boolean ' Attribute represents an aggregated class (through a pointer)
Public bRef As Boolean       ' pointer
Public bComposite As Boolean ' Attribute represents a strongly aggregated class (instance defined in class)
Public Multiplicity As Long  ' In cases where attributes are generated from associations,
'                              this is the indication of multiplicity
Public ConnId As String
Public Value As String
Public DefaultValue As String

Public order As Long         ' Order in which attribute appears in XML document
Public Index As Long         ' index entry for connector / model entries into InitEsos() operations

Public dim1 As Integer       ' name of variable for array dimesion or first dim of matrix
Public dim2 As Integer       ' name of variable for second dim of matrix

' additional properties added for ilogix integration
Public OnCg As Boolean
Public bDerivative As Boolean
Public bOldValue As Boolean
Public bAutoDiff As Boolean
Public PackageName As String       ' if attribute is a class, name of package
'Public CompositeName As String     ' calculated composite name (used for building hierarchical names)

Public Sub Copy(tgt As CgAttribute)

  tgt.ClassName = ClassName
  tgt.Name = Name
  tgt.Description = Description
  tgt.dataType = dataType
  tgt.Access = Access
  tgt.Mechanism = Mechanism
  tgt.bSim = bSim
  tgt.sType = sType
  tgt.sSubType = sSubType
  Set tgt.obj = obj
  
  tgt.bAggregate = bAggregate
  tgt.bRef = bRef
  tgt.bComposite = bComposite
  tgt.Multiplicity = Multiplicity
  
  tgt.ConnId = ConnId
  tgt.Value = Value
  tgt.DefaultValue = DefaultValue
  
  tgt.order = order
  
  tgt.dim1 = dim1
  tgt.dim2 = dim2

  tgt.OnCg = OnCg
  tgt.bDerivative = bDerivative
  tgt.bOldValue = bOldValue
  tgt.bAutoDiff = bAutoDiff
  tgt.PackageName = PackageName
  
End Sub

Private Sub Class_Initialize()
  Mechanism = "InOut"
  dataType = "double"
  Access = "public"
  bSim = False
  sType = idxAttr_Variable
  sSubType = idxAttr_Scalar
  dim1 = 2
  dim2 = 2
  ConnId = ""
  Value = ""
End Sub


Public Function export() As String
  Dim szRet As String
  
  szRet = szRet & "<CgAttribute Name=" & Chr(34) & Name & Chr(34)
  szRet = szRet & " sType=" & Chr(34) & sType & Chr(34)
  szRet = szRet & " sSubType=" & Chr(34) & sSubType & Chr(34)
  szRet = szRet & " dim1=" & Chr(34) & dim1 & Chr(34)
  szRet = szRet & " dim2=" & Chr(34) & dim2 & Chr(34)
  szRet = szRet & " Value=" & Chr(34) & Value & Chr(34)
  szRet = szRet & " bSim=" & Chr(34) & bSim & Chr(34)
  szRet = szRet & " />" & vbCrLf
  export = szRet
  
End Function

Public Sub import(aItem As IXMLDOMElement)

  On Error Resume Next
  Name = aItem.getAttribute("Name")
  sType = aItem.getAttribute("sType")
  sSubType = aItem.getAttribute("sSubType")
  dim1 = aItem.getAttribute("dim1")
  dim2 = aItem.getAttribute("dim2")
  Value = aItem.getAttribute("Value")
  bSim = aItem.getAttribute("bSim")
  
End Sub

Public Sub Save()

#If using_ilogix Then
  Dim aItem As RPModelElement
  Dim aAttr As RPAttribute
  Dim aAssoc As RPRelation
  Dim aInst As RPInstance
  If Not obj Is Nothing Then
    Set aItem = obj
    
    If aItem.metaClass = "Attribute" Then
      Set aAttr = aItem
      aAttr.setPropertyValue "Simulation.Attribute.OnCg", OnCg
      aAttr.setPropertyValue "Simulation.Attribute.bSim", bSim
      aAttr.setPropertyValue "Simulation.Attribute.SimType", GetAttrTypeFromId(sType)
      aAttr.setPropertyValue "Simulation.Attribute.SimSubType", GetAttrSubTypeFromId(sSubType)
      aAttr.setPropertyValue "Simulation.Attribute.Dimension1", dim1
      aAttr.setPropertyValue "Simulation.Attribute.Dimension2", dim2
      aAttr.setPropertyValue "Simulation.Attribute.Derivative", bDerivative
      aAttr.setPropertyValue "Simulation.Attribute.OldValue", bOldValue
      aAttr.setPropertyValue "Simulation.Attribute.AutoDiff", bAutoDiff
      aAttr.setPropertyValue "CPP_CG.Attribute.Visibility", Access
      aAttr.DefaultValue = DefaultValue
    End If
  
    If aItem.metaClass = "Relation" Then
      Set aAssoc = aItem
      aAssoc.setPropertyValue "Simulation.Relation.OnCg", OnCg
      aAssoc.setPropertyValue "Simulation.Relation.bSim", bSim
      aAssoc.setPropertyValue "Simulation.Relation.SimType", GetAttrTypeFromId(sType)
      aAssoc.setPropertyValue "Simulation.Relation.SimSubType", GetAttrSubTypeFromId(sSubType)
      aAssoc.setPropertyValue "Simulation.Relation.Dimension1", dim1
      aAssoc.setPropertyValue "Simulation.Relation.Dimension2", dim2
    End If
  
    If aItem.metaClass = "Instance" Then
      Set aInst = aItem
      aInst.setPropertyValue "Simulation.Relation.OnCg", OnCg
      aInst.setPropertyValue "Simulation.Relation.bSim", bSim
      aInst.setPropertyValue "Simulation.Relation.SimType", GetAttrTypeFromId(sType)
      aInst.setPropertyValue "Simulation.Relation.SimSubType", GetAttrSubTypeFromId(sSubType)
      aInst.setPropertyValue "Simulation.Relation.Dimension1", dim1
      aInst.setPropertyValue "Simulation.Relation.Dimension2", dim2
    End If
  
  End If
#End If

End Sub

Public Sub Load()

#If using_ilogix Then
  Dim aItem As RPModelElement
  Dim aAttr As RPAttribute
  Dim aAssoc As RPRelation
  Dim aInst As RPInstance
  Dim v As String
  
  If Not obj Is Nothing Then
    Set aItem = obj
    
    If aItem.metaClass = "Attribute" Then
      Set aAttr = aItem
      OnCg = CBool(aAttr.getPropertyValue("Simulation.Attribute.OnCg"))
      bSim = CBool(aAttr.getPropertyValue("Simulation.Attribute.bSim"))
      v = aAttr.getPropertyValue("Simulation.Attribute.SimType")
      sType = GetAttrTypeId(v)
      v = aAttr.getPropertyValue("Simulation.Attribute.SimSubType")
      sSubType = GetAttrSubTypeId(v)
      dim1 = aAttr.getPropertyValue("Simulation.Attribute.Dimension1")
      dim2 = aAttr.getPropertyValue("Simulation.Attribute.Dimension2")
      bDerivative = aAttr.getPropertyValue("Simulation.Attribute.Derivative")
      bOldValue = aAttr.getPropertyValue("Simulation.Attribute.OldValue")
      bAutoDiff = aAttr.getPropertyValue("Simulation.Attribute.AutoDiff")
      Access = aAttr.getPropertyValue("CPP_CG.Attribute.Visibility")
      DefaultValue = aAttr.DefaultValue
    End If
  
    If aItem.metaClass = "Relation" Then
      Set aAssoc = aItem
      OnCg = CBool(aAssoc.getPropertyValue("Simulation.Relation.OnCg"))
      bSim = CBool(aAssoc.getPropertyValue("Simulation.Relation.bSim"))
      v = aAssoc.getPropertyValue("Simulation.Relation.SimType")
      sType = GetAttrTypeId(v)
      v = aAssoc.getPropertyValue("Simulation.Relation.SimSubType")
      sSubType = GetAttrSubTypeId(v)
      dim1 = aAssoc.getPropertyValue("Simulation.Relation.Dimension1")
      dim2 = aAssoc.getPropertyValue("Simulation.Relation.Dimension2")
    End If
    
    If aItem.metaClass = "Instance" Then
      Set aInst = aItem
      OnCg = CBool(aInst.getPropertyValue("Simulation.Relation.OnCg"))
      bSim = CBool(aInst.getPropertyValue("Simulation.Relation.bSim"))
      v = aInst.getPropertyValue("Simulation.Relation.SimType")
      sType = GetAttrTypeId(v)
      v = aInst.getPropertyValue("Simulation.Relation.SimSubType")
      sSubType = GetAttrSubTypeId(v)
      dim1 = aInst.getPropertyValue("Simulation.Relation.Dimension1")
      dim2 = aInst.getPropertyValue("Simulation.Relation.Dimension2")
    End If
  
  End If
#End If

End Sub

Public Property Get IsTypeOf(sType As String, classes As Collection, typeDefs As Collection) As Boolean
  
  Dim aClass As rtsClass
  Dim aType As CgType
  Dim pos As Long
  Dim szDataType As String
  
  On Error Resume Next
  szDataType = dataType
  pos = InStr(1, szDataType, "<")
  If pos > 0 Then
    szDataType = Left(szDataType, pos - 1)
  End If
  
  Set aClass = classes(szDataType)
  If err = 0 And Not aClass Is Nothing Then
    IsTypeOf = aClass.IsTypeOf(sType)
    Exit Property
  End If
  
  err = 0
  Set aType = typeDefs(szDataType)
  If err = 0 And Not aType Is Nothing Then
    IsTypeOf = aType.IsTypeOf(sType)
    Exit Property
  End If
End Property
