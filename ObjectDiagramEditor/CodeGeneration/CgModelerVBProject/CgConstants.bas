Attribute VB_Name = "CgConstants"
Option Explicit

Global Const PROJECT_TITLE = "Artist"

Global Const idxClassType_Model = 1
Global Const idxClassType_AbstractModel = 2
Global Const idxClassType_Connector = 3
Global Const idxClassType_Structure = 4
Global Const idxClassType_NonSimulation = 5

' item type
Global Const idxItemType_Undefined = 0
Global Const idxItemType_Attribute = 1
Global Const idxItemType_Operation = 2
Global Const idxItemType_State = 3
Global Const idxItemType_Transition = 4


' Attribute sType
Global Const idxAttr_Undefined = 0
Global Const idxAttr_Variable = 1
Global Const idxAttr_Parameter = 2
Global Const idxAttr_Connector = 3
Global Const idxAttr_Model = 4
Global Const idxAttr_Struct = 5
Global Const idxAttr_Broadcaster = 6
Global Const idxAttr_Listener = 7
Global Const idxAttr_DataCollector = 8
Global Const idxAttr_Input = 9
Global Const idxAttr_Output = 10

' Attribute sType display value
Global Const szAttr_Undefined = "Undefined"
Global Const szAttr_Variable = "Variable"
Global Const szAttr_Parameter = "Parameter"
Global Const szAttr_Connector = "Connector"
Global Const szAttr_Model = "Model"
Global Const szAttr_Struct = "Struct/Class"
Global Const szAttr_Broadcaster = "Broadcaster"
Global Const szAttr_Listener = "Listener"
Global Const szAttr_DataCollector = "DataCollector"
Global Const szAttr_Input = "Input"
Global Const szAttr_Output = "Output"

' Attribute sSubType
Global Const idxAttr_Scalar = 1
Global Const idxAttr_Array = 2
Global Const idxAttr_Matrix = 3
Global Const idxAttr_valarray = 4

' Attribute sSubType display value
Global Const szAttr_Scalar = "Scalar"
Global Const szAttr_Array = "Array"
Global Const szAttr_Matrix = "Matrix"
Global Const szAttr_valarray = "valarray"


' Operation sType
Global Const idxOper_Undefined = 0
Global Const idxOper_Continuous = 1
Global Const idxOper_Discontinuous = 2
Global Const idxOper_Reset = 3
Global Const idxOper_Get = 4
Global Const idxOper_Set = 5

' Operation sType display value
Global Const szOper_Undefined = "Undefined"
Global Const szOper_Continuous = "Continuous"
Global Const szOper_Discontinuous = "Discontinuous"
Global Const szOper_Reset = "Reset"
Global Const szOper_Get = "Get"
Global Const szOper_Set = "Set"

' Operation sSubType
Global Const idxOper_Scalar = 1
Global Const idxOper_Array = 2
Global Const idxOper_valarray = 3
Global Const idxOper_Distributed = 4

' Operation sSubType display value
Global Const szOper_Scalar = "Scalar"
Global Const szOper_Array = "Array"
Global Const szOper_valarray = "valarray"
Global Const szOper_Distributed = "Distributed"


' Operation sDiffType (differentiation) type
Global Const idxOperDiff_Undefined = 0
Global Const idxOperDiff_Automatic = 1
Global Const idxOperDiff_Numeric = 2

' Operation sDiffType display value
Global Const szOperDiff_Undefined = "Undefined"
Global Const szOperDiff_Automatic = "Automatic"
Global Const szOperDiff_Numeric = "Numeric"

' Masks Connection Grid Constants
Global Const idxAttr_L = 1
Global Const idxAttr_R = 2
Global Const idxAttr_T = 3
Global Const idxAttr_B = 4

Global Const szAttr_L = "Left"
Global Const szAttr_R = "Right"
Global Const szAttr_T = "Top"
Global Const szAttr_B = "Bottom"

' attribute type switch statements
Public Function GetAttrTypeFromId(TypeId As Long) As String
  GetAttrTypeFromId = _
  Switch(TypeId = idxAttr_Undefined, szAttr_Undefined, _
         TypeId = idxAttr_Variable, szAttr_Variable, _
         TypeId = idxAttr_Parameter, szAttr_Parameter, _
         TypeId = idxAttr_Connector, szAttr_Connector, _
         TypeId = idxAttr_Model, szAttr_Model, _
         TypeId = idxAttr_Struct, szAttr_Struct, _
         TypeId = idxAttr_Broadcaster, szAttr_Broadcaster, _
         TypeId = idxAttr_Listener, szAttr_Listener, _
         TypeId = idxAttr_DataCollector, szAttr_DataCollector, _
         TypeId = idxAttr_Input, szAttr_Input, _
         TypeId = idxAttr_Output, szAttr_Output)
End Function

Public Function GetAttrSubTypeFromId(SubTypeId As Long) As String
  GetAttrSubTypeFromId = _
  Switch(SubTypeId = idxAttr_Scalar, szAttr_Scalar, _
         SubTypeId = idxAttr_Array, szAttr_Array, _
         SubTypeId = idxAttr_Matrix, szAttr_Matrix, _
         SubTypeId = idxAttr_valarray, szAttr_valarray)
End Function

Public Function GetAttrTypeId(TypeId As String) As Long
  GetAttrTypeId = _
  Switch(TypeId = szAttr_Undefined, idxAttr_Undefined, _
         TypeId = szAttr_Variable, idxAttr_Variable, _
         TypeId = szAttr_Parameter, idxAttr_Parameter, _
         TypeId = szAttr_Connector, idxAttr_Connector, _
         TypeId = szAttr_Model, idxAttr_Model, _
         TypeId = szAttr_Struct, idxAttr_Struct, _
         TypeId = szAttr_Broadcaster, idxAttr_Broadcaster, _
         TypeId = szAttr_Listener, idxAttr_Listener, _
         TypeId = szAttr_DataCollector, idxAttr_DataCollector, _
         TypeId = szAttr_Input, idxAttr_Input, _
         TypeId = szAttr_Output, idxAttr_Output)
End Function

Public Function GetAttrSubTypeId(SubTypeId As String) As Long
  GetAttrSubTypeId = _
  Switch(SubTypeId = szAttr_Scalar, idxAttr_Scalar, _
         SubTypeId = szAttr_Array, idxAttr_Array, _
         SubTypeId = szAttr_Matrix, idxAttr_Matrix, _
         SubTypeId = szAttr_valarray, idxAttr_valarray)
End Function

' operation type switch statements
Public Function GetOperTypeFromId(TypeId As Long) As String
  GetOperTypeFromId = _
  Switch(TypeId = idxOper_Undefined, szOper_Undefined, _
         TypeId = idxOper_Continuous, szOper_Continuous, _
         TypeId = idxOper_Discontinuous, szOper_Discontinuous, _
         TypeId = idxOper_Reset, szOper_Reset, _
         TypeId = idxOper_Get, szOper_Get, _
         TypeId = idxOper_Set, szOper_Set)
End Function

Public Function GetOperSubTypeFromId(SubTypeId As Long) As String
  GetOperSubTypeFromId = _
  Switch(SubTypeId = idxOper_Scalar, szOper_Scalar, _
         SubTypeId = idxOper_Array, szOper_Array, _
         SubTypeId = idxOper_valarray, szOper_valarray, _
         SubTypeId = idxOper_Distributed, szOper_Distributed)
End Function

Public Function GetOperTypeId(TypeId As String) As Long
  GetOperTypeId = _
  Switch(TypeId = szOper_Undefined, idxOper_Undefined, _
         TypeId = szOper_Continuous, idxOper_Continuous, _
         TypeId = szOper_Discontinuous, idxOper_Discontinuous, _
         TypeId = szOper_Reset, idxOper_Reset, _
         TypeId = szOper_Get, idxOper_Get, _
         TypeId = szOper_Set, idxOper_Set)
End Function

Public Function GetOperSubTypeId(SubTypeId As String) As Long
  GetOperSubTypeId = _
  Switch(SubTypeId = szOper_Scalar, idxOper_Scalar, _
         SubTypeId = szOper_Array, idxOper_Array, _
         SubTypeId = szOper_valarray, idxOper_valarray, _
         SubTypeId = szOper_Distributed, idxOper_Distributed)
End Function

' differention type switch statements
Public Function GetOperDiffTypeFromId(TypeId As Long) As String
  GetOperDiffTypeFromId = _
  Switch(TypeId = idxOperDiff_Undefined, szOperDiff_Undefined, _
         TypeId = idxOperDiff_Automatic, szOperDiff_Automatic, _
         TypeId = idxOperDiff_Numeric, szOperDiff_Numeric)
End Function

Public Function GetOperDiffTypeId(TypeId As String) As Long
  GetOperDiffTypeId = _
  Switch(TypeId = szOperDiff_Undefined, idxOperDiff_Undefined, _
         TypeId = szOperDiff_Automatic, idxOperDiff_Automatic, _
         TypeId = szOperDiff_Numeric, idxOperDiff_Numeric)
End Function



