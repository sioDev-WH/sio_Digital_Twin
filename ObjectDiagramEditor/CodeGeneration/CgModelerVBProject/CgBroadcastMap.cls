VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgBroadcastMap"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public Key As String
Public ArgType As String

Enum BroadcasterType
  DataCollector_Impl = 1
  DataCollector_Entry = 2
  Broadcaster_Fcn_Impl = 3
  Broadcaster_Scalar_Impl = 4
  Broadcaster_Vector_Impl = 5
  Broadcaster_Entry = 6
  EventBroadcaster_Entry = 7
End Enum

Public itsType As BroadcasterType
Public SourceCompositeObject As String

' broadcaster info
Public SourceClass As String
Public SourceObject As String

Public SourceAttribute As String
Public SourceAttributeSize As String
' -- or --
Public SourceFunction As String

' -----
Public SourceBroadcaster As String

' data collector info
Public SourceModelObject As String
Private Variables(20) As String
Public cVariables As Long
' -----
Public SourceDataCollector As String



' listeners definition
Public Listeners As Collection

Private Sub Class_Initialize()
  Set Listeners = New Collection
End Sub

Public Sub AddVariable(val As String)
  Variables(cVariables) = val
  cVariables = cVariables + 1
End Sub
  
Public Function GetVariable(idx As Long) As String
  GetVariable = Variables(idx)
End Function

Public Sub AddListener(TargetCompositeObject As String, TargetClass As String, TargetObject As String, TargetOper As String, TargetAttr As String, bOper As Boolean, bCreate As Boolean)
  Dim aListener As CgListener
  Set aListener = New CgListener
  
  aListener.TargetCompositeObject = TargetCompositeObject
  aListener.TargetClass = TargetClass
  aListener.TargetObject = TargetObject
  aListener.TargetOper = TargetOper
  aListener.TargetAttr = TargetAttr
  aListener.bOper = bOper
  aListener.bCreate = bCreate
  
  Listeners.Add aListener
End Sub

Public Function CgInit() As String

' KAB changes to communication macros
' Made the code generation result in human readable code

'ONI_BEGIN_BROADCAST_MAP (ArgType)
'ONI_BEGIN_EVENT_BROADCAST_MAP()
'ONI_SCALAR_BROADCASTER_IMPL(SOURCE_COMPOSITE_OBJECT, SOURCE_ATTR)
'ONI_VECTOR_BROADCASTER_IMPL(NAME, SOURCE_COMPOSITE_OBJECT, SOURCE_ATTR, SOURCE_ATTR_SIZE)
'ONI_FCN_BROADCASTER_IMPL(SOURCE_COMPOSITE_OBJECT, SOURCE_CLASS, SOURCE_OBJECT, SOURCE_FUNCTION)
'ONI_BROADCASTER_ENTRY (SOURCE_BROADCASTER)
'ONI_EVENT_BROADCASTER_IMPL (SOURCE_COMPOSITE_OBJECT)
'ONI_EVENT_BROADCASTER_ENTRY (SOURCE_BROADCASTER)
'ONI_EVENT_LISTENER_IMPL(TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT)
'ONI_EVENT_LISTENER_ENTRY (TARGET_LISTENER)
'ONI_OPER_LISTENER_IMPL(TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_OP)
'ONI_ATTR_LISTENER_IMPL(TARGET_COMPOSITE_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_ATTR)
'ONI_LISTENER_ENTRY (TARGET_LISTENER)
'ONI_DATACOLLECTOR_IMPL(NAME, SOURCE_CONTAINER_OBJECT, SOURCE_MODEL_OBJECT, VARIABLE)
'ONI_DATACOLLECTOR_ENTRY (SOURCE_DATACOLLECTOR)
'ONI_BEGIN_DATACOLLECTOR_IMPL(NAME, SOURCE_CONTAINER_OBJECT, SOURCE_MODEL_OBJECT)
'ONI_VAR (VARIABLE)
'ONI_END_DATACOLLECTOR_IMPL()
'ONI_OPER_LISTENER_IMPL_DC(TARGET_CONTAINER_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_OP)
'ONI_ATTR_LISTENER_IMPL_DC(TARGET_CONTAINER_OBJECT, TARGET_CLASS, TARGET_OBJECT, TARGET_ATTR)
'ONI_END_BROADCAST_MAP()
'ONI_END_EVENT_BROADCAST_MAP()

  Dim szRet As String
  Dim szName As String
  Dim i As Long
  
  Select Case itsType
    Case DataCollector_Impl
      szName = SourceModelObject
      For i = 0 To cVariables - 1
        szName = szName & "_" & Variables(i)
      Next i
      szRet = "ONI_BEGIN_BROADCAST_MAP(double)" & vbCrLf & _
              "  ONI_BEGIN_DATACOLLECTOR_IMPL(" & vbCrLf & _
              "    /* Name: */ " & szName & ", " & vbCrLf & _
              "    /* SourceCompositeObject: */ " & SourceCompositeObject & ", " & vbCrLf & _
              "    /* SourceModelObject: */ " & SourceModelObject & ")" & vbCrLf
      For i = 0 To cVariables - 1
        szRet = szRet & "    /* Variable(" & i & "): */ ONI_VAR(" & Variables(i) & ") " & vbCrLf
      Next i
      szRet = szRet & "  ONI_END_DATACOLLECTOR_IMPL()" & vbCrLf
      addDCListeners szRet
      szRet = szRet & "ONI_END_BROADCAST_MAP()" & vbCrLf
      
    Case DataCollector_Entry
      szRet = "ONI_BEGIN_BROADCAST_MAP(double)" & vbCrLf & _
              "  ONI_BEGIN_DATACOLLECTOR_ENTRY(" & SourceDataCollector & ")" & vbCrLf
      addDCListeners szRet
      szRet = szRet & "ONI_END_BROADCAST_MAP()" & vbCrLf
      
    Case Broadcaster_Fcn_Impl
      szRet = "ONI_BEGIN_BROADCAST_MAP(" & ArgType & ")" & vbCrLf & _
              "  ONI_FCN_BROADCASTER_IMPL(" & vbCrLf & _
              "    /* SourceCompositeObject: */ " & SourceCompositeObject & ", " & vbCrLf & _
              "    /* SourceClass: */ " & SourceClass & ", " & vbCrLf & _
              "    /* SourceObject: */ " & SourceObject & ", " & vbCrLf & _
              "    /* SourceFunction: */ " & SourceFunction & ")" & vbCrLf
      addListeners szRet
      szRet = szRet & "ONI_END_BROADCAST_MAP()" & vbCrLf
    
    Case Broadcaster_Scalar_Impl
      szRet = "ONI_BEGIN_BROADCAST_MAP(" & ArgType & ")" & vbCrLf & _
              "  ONI_SCALAR_BROADCASTER_IMPL(" & vbCrLf & _
              "    /* SourceCompositeObject: */ " & SourceCompositeObject & ", " & vbCrLf & _
              "    /* SourceObject: */ " & SourceObject & ", " & vbCrLf & _
              "    /* SourceAttribute: */ " & SourceAttribute & ")" & vbCrLf
      addListeners szRet
      szRet = szRet & "ONI_END_BROADCAST_MAP()" & vbCrLf
              
    Case Broadcaster_Vector_Impl
      szRet = "ONI_BEGIN_BROADCAST_MAP(" & ArgType & ")" & vbCrLf & _
              "  ONI_VECTOR_BROADCASTER_IMPL(" & vbCrLf & _
              "    /* SourceCompositeObject: */ " & SourceCompositeObject & ", " & vbCrLf & _
              "    /* SourceObject: */ " & SourceObject & ", " & vbCrLf & _
              "    /* SourceAttribute: */ " & SourceAttribute & ", " & vbCrLf & _
              "    /* SourceAttributeSize: */ " & SourceAttributeSize & ")" & vbCrLf
      addListeners szRet
      szRet = szRet & "ONI_END_BROADCAST_MAP()" & vbCrLf
    
    Case Broadcaster_Entry
      szRet = "ONI_BEGIN_BROADCAST_MAP(" & ArgType & ")" & vbCrLf & _
              "  ONI_BROADCASTER_ENTRY(" & SourceBroadcaster & ")" & vbCrLf
      addListeners szRet
      szRet = szRet & "ONI_END_BROADCAST_MAP()" & vbCrLf
      
    Case EventBroadcaster_Entry
      szRet = "ONI_BEGIN_EVENT_BROADCAST_MAP()" & vbCrLf & _
              "  ONI_EVENT_BROADCASTER_ENTRY(" & SourceBroadcaster & ")" & vbCrLf
      addEventListeners szRet
      szRet = szRet & "ONI_END_EVENT_BROADCAST_MAP()" & vbCrLf
      
  End Select

  CgInit = szRet
End Function

' KAB moved this common addListener code to seperate functions
Private Sub addDCListeners(szRet As String)
  Dim aListener As CgListener
  
  For Each aListener In Listeners
    If aListener.bCreate Then
      If aListener.bOper Then
        szRet = szRet & "  ONI_OPER_LISTENER_IMPL_DC(" & vbCrLf & _
                        "  /* TargetCompositeObject: */ " & aListener.TargetCompositeObject & ", " & vbCrLf & _
                        "  /* TargetClass: */ " & aListener.TargetClass & ", " & vbCrLf & _
                        "  /* TargetObject: */ " & aListener.TargetObject & ", " & vbCrLf & _
                        "  /* TargetOperation: */ " & aListener.TargetOper & ")" & vbCrLf
      Else
        szRet = szRet & "  ONI_ATTR_LISTENER_IMPL_DC(" & vbCrLf & _
                        "    /* TargetCompositeObject: */ " & aListener.TargetCompositeObject & ", " & vbCrLf & _
                        "    /* TargetClass: */ " & aListener.TargetClass & ", " & vbCrLf & _
                        "    /* TargetObject: */ " & aListener.TargetObject & ", " & vbCrLf & _
                        "    /* TargetAttribute: */ " & aListener.TargetAttr & ")" & vbCrLf
      End If
    Else
      szRet = szRet & "  ONI_LISTENER_ENTRY(" & aListener.TargetListener & ")" & vbCrLf
    End If
  Next

End Sub

Private Sub addListeners(szRet As String)
  Dim aListener As CgListener
  
  For Each aListener In Listeners
    If aListener.bCreate Then
      If aListener.bOper Then
        szRet = szRet & "  ONI_OPER_LISTENER_IMPL(" & vbCrLf & _
                        "  /* TargetCompositeObject: */ " & aListener.TargetCompositeObject & ", " & vbCrLf & _
                        "  /* TargetClass: */ " & aListener.TargetClass & ", " & vbCrLf & _
                        "  /* TargetObject: */ " & aListener.TargetObject & ", " & vbCrLf & _
                        "  /* TargetOperation: */ " & aListener.TargetOper & ")" & vbCrLf
      Else
        szRet = szRet & "  ONI_ATTR_LISTENER_IMPL(" & vbCrLf & _
                        "    /* TargetCompositeObject: */ " & aListener.TargetCompositeObject & ", " & vbCrLf & _
                        "    /* TargetClass: */ " & aListener.TargetClass & ", " & vbCrLf & _
                        "    /* TargetObject: */ " & aListener.TargetObject & ", " & vbCrLf & _
                        "    /* TargetAttribute: */ " & aListener.TargetAttr & ")" & vbCrLf
      End If
    Else
      szRet = szRet & "  ONI_LISTENER_ENTRY(" & aListener.TargetListener & ")" & vbCrLf
    End If
  Next

End Sub

Private Sub addEventListeners(szRet As String)
  Dim aListener As CgListener
  
  For Each aListener In Listeners
    If aListener.bCreate Then
      szRet = szRet & "  ONI_EVENT_LISTENER_IMPL(" & vbCrLf & _
                      "    /* TargetCompositeObject: */ " & aListener.TargetCompositeObject & ", " & vbCrLf & _
                      "    /* TargetClass: */ " & aListener.TargetClass & ", " & vbCrLf & _
                      "    /* TargetObject: */ " & aListener.TargetObject & ")" & vbCrLf
    Else
      szRet = szRet & "  ONI_EVENT_LISTENER_ENTRY(" & aListener.TargetListener & ")" & vbCrLf
    End If
  Next

End Sub


