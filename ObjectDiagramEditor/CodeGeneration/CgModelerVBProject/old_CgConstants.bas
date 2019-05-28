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

' Attribute sSubType display value
Global Const szAttr_Scalar = "Scalar"
Global Const szAttr_Array = "Array"
Global Const szAttr_Matrix = "Matrix"


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
