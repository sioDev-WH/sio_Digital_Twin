VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgAssociation"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
' reading associations from a class
' Set Associations = Class.Items("Association")
' Associations.ResetQueryItems
' Do While Associations.MoreItems
'   Set Association = Associations.NextItem
'   read properties
' Loop


Public ClassName As String          ' parent class name
Public Name As String               ' default property
Public Description As String

' class, role, qualifier, multiplicity for each end
Public StartClass As String         ' "Start Class"
Public StartPackage As String
Public StartRole As String          ' "Start Role"
Public StartQualifier As String     ' "Start Qualifier"
Public StartMultiplicity As String  ' "Start Multiplicity" {ZERO or MORE, only ONE, ONE Or MORE, TBD, eg: 12 to 15}

Public EndClass As String           ' "End Class"
Public EndPackage As String
Public EndRole As String            ' "End Role"
Public EndQualifier As String       ' "End Qualifier"
Public EndMultiplicity As String    ' "End Multiplicity"


Public Aggregate As String          ' Aggregate class end {START, END, NONE} r/w
Public Navigation                   ' implementation: {start-end, end-start, bi-directional, none}

' properties added for iLogix
Public bSim As Boolean
Public sType As Long
Public sSubType As Long
Public dim1 As Integer       ' name of variable for array dimesion or first dim of matrix
Public dim2 As Integer       ' name of variable for second dim of matrix
Public OnCg As Boolean
Public order As Long
Public PackageName As String

Public obj As Object                ' Rts object

Public Sub Copy(tgt As CgAssociation)

  tgt.ClassName = ClassName
  tgt.Name = Name
  tgt.Description = Description
  
  tgt.StartClass = StartClass
  tgt.StartPackage = StartPackage
  tgt.StartRole = StartRole
  tgt.StartQualifier = StartQualifier
  tgt.StartMultiplicity = StartMultiplicity
    
  tgt.EndClass = EndClass
  tgt.EndPackage = EndPackage
  tgt.EndRole = EndRole
  tgt.EndQualifier = EndQualifier
  tgt.EndMultiplicity = EndMultiplicity

  tgt.Aggregate = Aggregate
  tgt.Navigation = Navigation
  
  tgt.bSim = bSim
  tgt.sType = sType
  tgt.sSubType = sSubType
  tgt.dim1 = dim1
  tgt.dim2 = dim2
  tgt.OnCg = OnCg
  tgt.order = order
  tgt.PackageName = PackageName
  
  Set tgt.obj = obj

End Sub

Private Sub Class_Initialize()
  StartMultiplicity = "1"
  EndMultiplicity = "1"
  dim1 = 2
  dim2 = 2
End Sub

Public Sub Save()

#If using_ilogix Then
  Dim aItem As RPModelElement
  Dim aAssoc As RPRelation
  Dim aInst As RPInstance
  If Not obj Is Nothing Then
    Set aItem = obj
    
    If aItem.metaClass = "Association" Or aItem.metaClass = "Relation" Then
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
  Dim aAssoc As RPRelation
  Dim aInst As RPInstance
  Dim v As String
  
  If Not obj Is Nothing Then
    Set aItem = obj
    
    If aItem.metaClass = "Association" Or aItem.metaClass = "Relation" Then
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

