VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "rtsClass"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public PackageName As String
Public Name As String
Public Class As Object

Public additionalBaseClasses As String
Public impIncludes As String
Public specIncludes As String

Public ModelType As Long
Public Project As rtsProject

Public Associations As Collection
Public Attributes As Collection
Public Operations As Collection
Public States As Collection
Public Transitions As Collection

Public BaseClasses As Collection

' added for iLogix
Public OnCg As Boolean

Public bInitialized As Boolean
'Public bIncludeCg As Boolean

Public Sub Destroy()
  Class_Terminate
End Sub

Private Sub Class_Initialize()
  Set Associations = New Collection
  Set Attributes = New Collection
  Set Operations = New Collection
  Set States = New Collection
  Set Transitions = New Collection
  Set Project = Nothing
End Sub

Private Sub Class_Terminate()
  Set Associations = Nothing
  Set Attributes = Nothing
  Set Operations = Nothing
  Set States = Nothing
  Set Transitions = Nothing
  Set Project = Nothing
End Sub

Public Sub Save()

#If using_ilogix Then
  Dim aRPClass As RPClass
  Dim aAttr As CgAttribute
  Dim aAssoc As CgAssociation
  Dim aOper As CgOperation
  Dim aState As CgState
  Dim aTrans As CgTransition
  Dim szOrder As String
  
  If Not Class Is Nothing Then
    Set aRPClass = Class
    aRPClass.setPropertyValue "Simulation.Class.OnCg", OnCg
    aRPClass.setPropertyValue "Simulation.Class.SimType", Switch(ModelType = 0, "Undefined", ModelType = 1, "Model", ModelType = 2, "AbstractModel", ModelType = 3, "Connector", ModelType = 4, "Structure", ModelType = 5, "NonSimulation")
    
    aRPClass.setPropertyValue "CPP_CG.Class.AdditionalBaseClasses", additionalBaseClasses
    aRPClass.setPropertyValue "CPP_CG.Class.ImpIncludes", impIncludes
    aRPClass.setPropertyValue "CPP_CG.Class.SpecIncludes", specIncludes
    
    szOrder = ""
    For Each aAttr In Attributes
      aAttr.Save
      szOrder = IIf(Len(szOrder) > 0, szOrder & ",", "") & aAttr.Name
    Next
    aRPClass.setPropertyValue "Simulation.Class.AttributeOrder", szOrder
    
    For Each aAssoc In Associations
        aAssoc.Save
    Next
    
    szOrder = ""
    For Each aOper In Operations
      aOper.Save
      szOrder = IIf(Len(szOrder) > 0, szOrder & ",", "") & aOper.Name
    Next
    aRPClass.setPropertyValue "Simulation.Class.OperationOrder", szOrder
    
    szOrder = ""
    For Each aState In States
      aState.Save
      szOrder = IIf(Len(szOrder) > 0, szOrder & ",", "") & aState.Name
    Next
    aRPClass.setPropertyValue "Simulation.Class.StateOrder", szOrder
    
    For Each aTrans In Transitions
      aTrans.Save
    Next
    
    aRPClass.Save True
  End If
#End If
End Sub

Public Sub SaveAttributeOrder(attrList As Collection)
#If using_ilogix Then
  Dim aRPClass As RPClass
  Dim aAttr As CgAttribute
  Dim szOrder As String
  
  If Not Class Is Nothing Then
    Set aRPClass = Class
    szOrder = ""
    For Each aAttr In attrList
      szOrder = IIf(Len(szOrder) > 0, szOrder & ",", "") & aAttr.Name
    Next
    aRPClass.setPropertyValue "Simulation.Class.AttributeOrder", szOrder
    aRPClass.Save True
  End If
#End If
End Sub

Public Sub Load()
#If using_ilogix Then
  Dim aRPClass As RPClass
  Dim szNames As String
  Dim szOnCg As String
  Dim szSimType As String
  Dim Index As Long
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim i As Long
  Dim count As Long
  
  If Not Class Is Nothing Then
    Set aRPClass = Class
    
    szOnCg = aRPClass.getPropertyValue("Simulation.Class.OnCg")
    szSimType = aRPClass.getPropertyValue("Simulation.Class.SimType")
    
    additionalBaseClasses = aRPClass.getPropertyValue("CPP_CG.Class.AdditionalBaseClasses")
    impIncludes = aRPClass.getPropertyValue("CPP_CG.Class.ImpIncludes")
    specIncludes = aRPClass.getPropertyValue("CPP_CG.Class.SpecIncludes")
    
    OnCg = CBool(szOnCg)
    ModelType = Switch(szSimType = "Undefined", 0, szSimType = "Model", 1, szSimType = "AbstractModel", 2, szSimType = "Connector", 3, szSimType = "Structure", 4, szSimType = "NonSimulation", 5)
    szNames = aRPClass.getPropertyValue("Simulation.Class.AttributeOrder")
    
    i = 1
    count = 0
    ReDim putFirst(Me.Attributes.count) As Long
    For Each aAttr In Me.Attributes
      If aAttr.sSubType = idxAttr_Scalar Then
        putFirst(count) = i
        count = count + 1
      End If
      i = i + 1
    Next
    OrderCollection szNames, Me.Attributes, putFirst, count
    
    ' initialize the InitEsos() index on model and connector attributes
    Index = 0
    For Each aAttr In Me.Attributes
      If aAttr.sType = idxAttr_Connector Or aAttr.sType = idxAttr_Model Then
        aAttr.Index = Index
        Index = Index + 1
      End If
    Next
    
    szNames = aRPClass.getPropertyValue("Simulation.Class.OperationOrder")
    
    ' The equation framework expects all scalar equations to appear first, then all vector equations.
    ' The wizard therefor must sort all scalar equations first, regardless of the purpose for which the
    ' model is being loaded, so all references to the members fall in the correct order.
    i = 1
    count = 0
    ReDim putFirst(Me.Operations.count) As Long
    For Each aOper In Me.Operations
      If aOper.sSubType = idxOper_Scalar Then
        putFirst(count) = i
        count = count + 1
      End If
      i = i + 1
    Next
    OrderCollection szNames, Me.Operations, putFirst, count
    
    szNames = aRPClass.getPropertyValue("Simulation.Class.StateOrder")
    ReDim putFirst(1) As Long
    count = 0
    OrderCollection szNames, Me.States, putFirst, count
    'szNames = arpClass.getPropertyValue("Simulation.Class.TransitionOrder")
    'OrderCollection szNames, Me.Transitions
  End If
#End If
End Sub

Private Sub OrderCollection(names As String, coll As Collection, putFirst() As Long, firstCount As Long)

#If using_ilogix Then
  Dim obj As Object
  Dim nLoc As Long
  Dim i As Long
  Dim j As Long
  Dim idx As Long
  Dim count As Long
  Dim s As String
  Dim tcol As Collection
  Dim cursor As Long
  Dim length As Long
  Dim idxEnd As Long
  
  On Error GoTo Error_Handler
  
  If names = "None" Or Len(Trim(names)) = 0 Then
    ' no order is predefined
    For i = 1 To coll.count
      coll(i).order = -2
    Next i
    For i = 0 To firstCount - 1
      coll(putFirst(i)).order = -1
    Next i
    
    idx = 0
    idxEnd = firstCount
    For i = 1 To coll.count
      If coll(i).order = -1 Then
        coll(i).order = idx
        idx = idx + 1
      ElseIf coll(i).order = -2 Then
        coll(i).order = idxEnd
        idxEnd = idxEnd + 1
      End If
    Next i
  Else
    ' initialize
    For i = 1 To coll.count
      coll(i).order = -2 ' -2 = second
    Next i
    For i = 0 To firstCount - 1
      coll(putFirst(i)).order = -1  ' -1 = first
    Next i
  
    ' iterate over names, assigning an index if the name matches an entry in the collection
    idx = 0
    idxEnd = firstCount
    cursor = 1
    nLoc = InStr(cursor, names, ",")
    On Error Resume Next
    Do While cursor <= Len(names)
      If nLoc = 0 Then
        length = Len(names)
        s = LTrim(RTrim(Mid(names, cursor)))
      Else
        length = nLoc - cursor
        s = LTrim(RTrim(Mid(names, cursor, length)))
      End If
      Set obj = coll(s)
      If err = 0 Then
        If obj.order = -1 Then ' -1 = first
          obj.order = idx
          idx = idx + 1
        ElseIf obj.order = -2 Then ' -2 = second
          obj.order = idxEnd
          idxEnd = idxEnd + 1
        End If
      End If
      
      err = 0
      cursor = cursor + length + 1
      nLoc = InStr(cursor, names, ",")
    Loop
  
    ' get any missed items
    For i = 1 To coll.count
      If coll(i).order = -1 Then
        coll(i).order = idx
        idx = idx + 1
      ElseIf coll(i).order = -2 Then
        coll(i).order = idxEnd
        idxEnd = idxEnd + 1
      End If
    Next i
  End If
  
' set the natural order of the collection to the sorted order
  
  ' copy objects to a temporary collection, indexed by order
  Set tcol = New Collection
  For i = 1 To coll.count
    tcol.Add coll(i), "IDX" & coll(i).order
  Next i
  
  ' remove all entries from the collection
  count = coll.count
  For i = count To 1 Step -1
    coll.Remove i
  Next i
  
  ' insert them back in order
  For i = 0 To tcol.count - 1
    Set obj = tcol("IDX" & i)
    coll.Add obj, obj.Name
  Next i
  
  Exit Sub
Error_Handler:
  MsgBox "OrderCollection error: " & err.Description
  Resume Next
  
#End If

End Sub

Public Property Get IsTypeOf(sType As String) As Boolean
  Dim aRPClass As RPClass
  Dim additionalBaseClasses As String
  
  If Not Class Is Nothing Then
    Set aRPClass = Class
    If BaseClasses Is Nothing Then GetBaseClasses aRPClass, BaseClasses
    additionalBaseClasses = aRPClass.getPropertyValue("CPP_CG.Class.AdditionalBaseClasses")
    If InStr(1, Name, sType) > 0 Or InStr(1, additionalBaseClasses, sType) > 0 Then
      IsTypeOf = True
    Else
      For Each aRPClass In BaseClasses
        additionalBaseClasses = aRPClass.getPropertyValue("CPP_CG.Class.AdditionalBaseClasses")
        If InStr(1, aRPClass.Name, sType) > 0 Or InStr(1, additionalBaseClasses, sType) > 0 Then
          IsTypeOf = True
          Exit For
        End If
      Next
    End If

  End If
End Property
