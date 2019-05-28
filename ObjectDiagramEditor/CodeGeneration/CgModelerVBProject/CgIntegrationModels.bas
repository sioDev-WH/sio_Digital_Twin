Attribute VB_Name = "CgIntegrationModels"
Option Explicit

' KAB June 8, 2003 --> Added function for getting UDI class Info initialized
Public Sub InitializeUDIClasses(Project As rtsProject, DefMgr As UDIDefMgr, UDIs As Collection)
  ' initialize the model info collection
  Dim infos As Collection
  Dim aInfo As rtsClass
  Dim aUDI As UserDefinedItem
  Dim aUDIDef As UserDefinedItemDef
  Dim aClassInfo As rtsClass
  
  Set infos = New Collection
  
  On Error Resume Next
  For Each aUDI In UDIs
    'Debug.Print aUDI.ObjectName
    Set aUDIDef = DefMgr.GetUDIDefbyObjectName(aUDI.m_strDefObjectName)
    If Not aUDIDef Is Nothing Then
      aUDI.PackageName = aUDIDef.PackageName
      aUDI.ClassName = aUDIDef.ClassName
    End If
    Set aInfo = infos(aUDI.ClassName)
    If err <> 0 Then
      If GetClassInfo(Project, aUDI.PackageName, aUDI.ClassName, aClassInfo) Then
        infos.Add aClassInfo, aUDI.ClassName
      End If
    End If
  Next aUDI
      
  For Each aUDI In UDIs
    err = 0
    Set aInfo = infos(aUDI.ClassName)
    If err = 0 Then
      Set aUDI.m_Info = aInfo
    End If
  Next

End Sub

Public Function GetIntegrationModelExecCgObjects( _
  IntegrationProject As rtsProject, _
  IntegrationPackage As rtsPackage, _
  CompositeModelPackage As rtsPackage, _
  CompositeModelClass As rtsClass, _
  szIntAppName As String, _
  szIntPhysicalSubsystemName As String, _
  szIntTaskRootName As String, _
  UDIs As Collection, _
  bMaxStepSize As Boolean, _
  maxStepSize As Double, _
  bViewDetails As Boolean) As Boolean
  
  Dim ClassCgAttributes As Collection
  Dim classCgOperations As Collection
  Dim modelExec As rtsClass
  Dim aFcn As CgOperation
  Dim aInitFcn As CgOperation
  Dim aCleanFcn As CgOperation
  Dim bNewClass As Boolean
  
  On Error Resume Next
  ' build the model exec discrete application class
  Set ClassCgAttributes = New Collection
  Set classCgOperations = New Collection
  
  Set modelExec = New rtsClass
  modelExec.Name = szIntPhysicalSubsystemName
  modelExec.PackageName = IntegrationPackage.Name
  Set modelExec.Project = IntegrationProject
  modelExec.additionalBaseClasses = "public COnSubsystemBase<" & CompositeModelClass.Name & ">"
  modelExec.specIncludes = "OnSubsystemBase.h" & ", " & CompositeModelClass.Name & ".h"
  
  ' generate the header for the init() method
  Set aInitFcn = New CgOperation
  aInitFcn.Name = "init"
  aInitFcn.ReturnType = "void"
  aInitFcn.Access = "public"
  aInitFcn.OnCg = True
  
  ' generate the header for the clean() method
  Set aCleanFcn = New CgOperation
  aCleanFcn.Name = "clean"
  aCleanFcn.ReturnType = "void"
  aCleanFcn.Access = "public"
  aInitFcn.OnCg = True
  
  ' KAB June 8, 2003 --> Had to copy the model info initialization to its own function so it could be called
  '                      from the root calling function, in case generating the model exec class was omitted.
  'initialize the  adg parser
  Set adg = New CgAD
  
  ' initialize the model info collection
  Dim infos As Collection
  Set infos = New Collection
  infos.Add CompositeModelClass
  
  ' build up class information
  Dim aClassInfo As rtsClass
  Dim ModelUDIs As Collection
  Dim aUDI As UserDefinedItem
  Dim aInfo As rtsClass
  
  For Each aUDI In UDIs
    Set aInfo = infos(aUDI.ClassName)
    If err <> 0 Then
      If GetClassInfo(IntegrationProject, aUDI.PackageName, aUDI.ClassName, aClassInfo) Then
        infos.Add aClassInfo, aUDI.ClassName
      End If
    End If
  Next aUDI
      
  Set ModelUDIs = New Collection
  For Each aUDI In UDIs
    err = 0
    Set aInfo = infos(aUDI.ClassName)
    If err = 0 Then
      ModelUDIs.Add aUDI, aUDI.ObjectName
      Set aUDI.m_Info = aInfo
    End If
  Next
  
  On Error GoTo 0
  
  Call CgIntegrationSystemModelInit( _
    CompositeModelPackage.Name, _
    CompositeModelClass.Name, _
    aInitFcn, _
    ModelUDIs, _
    ClassCgAttributes, _
    bMaxStepSize, _
    maxStepSize)
    
  CgIntegrationSystemModelClean aCleanFcn, ModelUDIs, CompositeModelClass.Name
  
  CgIntegrationLoad szIntPhysicalSubsystemName, classCgOperations
  CgIntegrationSave szIntPhysicalSubsystemName, classCgOperations
  
  aInitFcn.CgInit
  classCgOperations.Add aInitFcn
  
  aCleanFcn.CgInit
  classCgOperations.Add aCleanFcn
  
  bNewClass = False
  Set modelExec.Class = IntegrationPackage.obj.FindClass(modelExec.Name)
  If modelExec.Class Is Nothing Then
      bNewClass = True
      Set modelExec.Class = IntegrationPackage.obj.addClass(modelExec.Name)
  End If

  AddCgObjects IntegrationPackage.Name, modelExec.Name, modelExec, ClassCgAttributes, classCgOperations, bViewDetails
  If bNewClass Then
    IntegrationPackage.Classes.Add modelExec, modelExec.Name
  End If
  GetClassInfo IntegrationProject, IntegrationPackage.Name, modelExec.Name, modelExec
  
  GetIntegrationModelExecCgObjects = True
End Function

Function GetIntegrationTaskCgObjects( _
  IntegrationProject As rtsProject, _
  IntegrationPackage As rtsPackage, _
  CompositeModelPackage As rtsPackage, _
  CompositeModelClass As rtsClass, _
  szIntAppName As String, _
  szIntPhysicalSubsystemName As String, _
  szIntTaskRootName As String, _
  UDIs As Collection, _
  aUDIDefMgr As UDIDefMgr, _
  ConnInfo As Collection, _
  bViewDetails As Boolean, _
  bGenApp As Boolean, _
  bGenTasks As Boolean, _
  bGenSubsystem As Boolean) As Boolean

  Dim ClassCgAttributes As Collection
  Dim classCgOperations As Collection
  Dim taskList As Collection
  Dim aClass As rtsClass
  Dim fastestTask As rtsTask
  Dim fastestTS As Long
  Dim aUDI As UserDefinedItem
  Dim aTask As rtsTask
  Dim aConnInfo As ConnectionInfo
  Dim i As Long
  Dim temp As Long
  Dim bNewClass As Boolean
  
  On Error GoTo Error_Handler
  Set taskList = New Collection
  
  Dim bSorted As Boolean
  Dim startTime As Date
  Dim OrderedUDIs As Collection
  Set OrderedUDIs = New Collection
  startTime = Now
  
  ' KAB --> need to initialize the parser (need to replace the parser with a local copy)
  Set adg = New CgAD

  If UDIs.count > 0 Then
    For i = 1 To UDIs.count
      Set aUDI = UDIs(i)
      aUDI.m_Order = i
    Next i
     
    For Each aUDI In UDIs
      OrderedUDIs.Add aUDI, "Order" & Format(aUDI.m_Order, "000")
    Next
    
    fastestTS = 1000000
    For i = 1 To OrderedUDIs.count
      Set aUDI = OrderedUDIs("Order" & Format(i, "000"))
      On Error Resume Next
      Set aTask = taskList("task_" & Format(aUDI.TS, "0000") & "ms")
      If err <> 0 Then
        Set aTask = New rtsTask
        aTask.TS = aUDI.TS
        aTask.ClassName = szIntTaskRootName & "_task_" & Format(aUDI.TS, "0000") & "ms"
        aTask.ObjectName = "task_" & Format(aUDI.TS, "0000") & "ms"
        taskList.Add aTask, aTask.ObjectName
      End If
      aTask.Models.Add aUDI, aUDI.ObjectName
      If aUDI.TS < fastestTS Then
        fastestTS = aUDI.TS
        Set fastestTask = aTask
      End If
    Next
    ' KAB - June 8, 2003 --> conditioning all referenced to physical subsystem
    If bGenSubsystem Then
      Set fastestTask.ModelExecClass = IntegrationPackage.Classes(szIntPhysicalSubsystemName)
    End If
        
    If CgIntegrationGetBlockExecutionOrder(ConnInfo, UDIs, taskList, aUDIDefMgr) = False Then
      GetIntegrationTaskCgObjects = False
      Exit Function
    End If
  End If
  
  Dim aAttr As CgAttribute
  Dim aInitFcn As CgOperation
  Dim aCleanFcn As CgOperation
  Dim aTickFcn As CgOperation
  Dim aTimeFcn As CgOperation
  Dim aBroadcastFcn As CgOperation
  Dim aFcn As CgOperation
  Dim bSuccess As Boolean
  
  For Each aTask In taskList
    Set ClassCgAttributes = New Collection
    Set classCgOperations = New Collection
    
    ' add a constructor
    Set aFcn = New CgOperation
    aFcn.bConstructor = True
    aFcn.Name = aTask.ClassName
    aFcn.Access = "public"
    aFcn.AddLine "init();"
    aFcn.OnCg = True
    aFcn.CgInit
    classCgOperations.Add aFcn
    
    ' add a destructor
    Set aFcn = New CgOperation
    aFcn.bDestructor = True
    aFcn.Name = "~" & aTask.ClassName
    aFcn.Access = "public"
    aFcn.AddLine "clean();"
    aFcn.OnCg = True
    aFcn.CgInit
    classCgOperations.Add aFcn
    
    Set aTickFcn = New CgOperation
    aTickFcn.Name = "handle_tick"
    aTickFcn.Access = "public"
    aTickFcn.ReturnType = "void"
    aTickFcn.OnCg = True
    classCgOperations.Add aTickFcn
    
    Set aTimeFcn = New CgOperation
    aTimeFcn.Name = "setTime"
    aTimeFcn.AddPar "t", "double", "In"
    aTimeFcn.Access = "public"
    aTimeFcn.ReturnType = "void"
    aTimeFcn.OnCg = True
    classCgOperations.Add aTimeFcn
    
    Set aBroadcastFcn = New CgOperation
    aBroadcastFcn.Name = "broadcast"
    aBroadcastFcn.Access = "public"
    aBroadcastFcn.ReturnType = "void"
    aBroadcastFcn.OnCg = True
    classCgOperations.Add aBroadcastFcn
    
    ' generate the header for the init() method
    Set aInitFcn = New CgOperation
    aInitFcn.Name = "init"
    aInitFcn.ReturnType = "void"
    aInitFcn.Access = "public"
    aInitFcn.OnCg = True
    classCgOperations.Add aInitFcn
     
    ' generate the header for the clean() method
    Set aCleanFcn = New CgOperation
    aCleanFcn.Name = "clean"
    aCleanFcn.ReturnType = "void"
    aCleanFcn.Access = "public"
    aCleanFcn.OnCg = True
    classCgOperations.Add aCleanFcn

    Set aAttr = New CgAttribute
    aAttr.Name = "nTicks"
    aAttr.dataType = "long"
    aAttr.DefaultValue = "0"
    aAttr.Access = "protected"
    aAttr.OnCg = True
    ClassCgAttributes.Add aAttr
    
    Set aAttr = New CgAttribute
    aAttr.Name = "interval"
    aAttr.dataType = "long"
    aAttr.DefaultValue = "0"
    aAttr.Access = "protected"
    aAttr.OnCg = True
    ClassCgAttributes.Add aAttr
    
    aInitFcn.AddLine "// calculate the number of ticks (period) before broadcasting tick()"
    aInitFcn.AddLine "long task_TS = " & aTask.TS & ";"
    aInitFcn.AddLine "long fastest_task_TS = " & fastestTS & ";"
    aInitFcn.AddLine "interval = task_TS / fastest_task_TS;"
    aInitFcn.AddLine "nTicks = 0;"

    aTickFcn.AddLine "if (nTicks == 0)"
    aTickFcn.AddLine "{"
    
    'Moved so the handle_tick for the physical subsystem is always first
    If Not aTask.ModelExecClass Is Nothing Then
      aTickFcn.AddLine "  " & "its" & szIntPhysicalSubsystemName & "->handle_tick();"
    End If
    
    For Each aUDI In aTask.Models
      If aUDI.m_Info.ModelType <> idxClassType_Model Then
        Set aAttr = New CgAttribute
        aAttr.bAggregate = True
        aAttr.Access = "public"
        #If using_ilogix Then
          aAttr.dataType = Replace(aUDI.ClassName, " ", "_")
        #End If
        aAttr.PackageName = aUDI.PackageName
        aAttr.bSim = False
        aAttr.Name = Replace(aUDI.ObjectName, " ", "_")
        aAttr.DefaultValue = "NULL"
        aAttr.OnCg = True
        ClassCgAttributes.Add aAttr, aAttr.Name
        
        aInitFcn.AddLine aAttr.Name & " = new " & aUDI.ClassName & "();"
        aInitFcn.AddLine aAttr.Name & "->setPeriod(task_TS);"
        If aUDI.m_Info.States.count > 0 Then
          aInitFcn.AddLine aAttr.Name & "->startBehavior();"
        End If
        aInitFcn.AddLine ""
        
        aTimeFcn.AddLine aAttr.Name & "->setTime(t);"
        
        aTickFcn.AddLine "  " & aAttr.Name & "->handle_tick();"
        
        aBroadcastFcn.AddLine aAttr.Name & "->broadcast();"
        
        aCleanFcn.AddLine "if (" & aAttr.Name & ")"
        aCleanFcn.AddLine "{"
        aCleanFcn.AddLine "  delete " & aAttr.Name & ";"
        aCleanFcn.AddLine "  " & aAttr.Name & " = NULL;"
        aCleanFcn.AddLine "}"
        aCleanFcn.AddLine ""
      End If
    Next
    
    If Not aTask.ModelExecClass Is Nothing Then
      Set aAttr = New CgAttribute
      aAttr.bAggregate = True
      aAttr.Access = "public"
      
      #If using_ilogix Then
        aAttr.dataType = szIntPhysicalSubsystemName
      #End If
      
      aAttr.PackageName = IntegrationPackage.Name
      aAttr.bSim = False
      aAttr.Name = "its" & szIntPhysicalSubsystemName
      aAttr.DefaultValue = "NULL"
      aAttr.OnCg = True
      ClassCgAttributes.Add aAttr, aAttr.Name
      
      aInitFcn.AddLine aAttr.Name & " = new " & szIntPhysicalSubsystemName & "();"
      aInitFcn.AddLine ""
      
      aTimeFcn.AddLine aAttr.Name & "->setTime(t);"
      
      aBroadcastFcn.AddLine aAttr.Name & "->broadcast();"
      
      aCleanFcn.AddLine "if (" & aAttr.Name & ")"
      aCleanFcn.AddLine "{"
      aCleanFcn.AddLine "  delete " & aAttr.Name & ";"
      aCleanFcn.AddLine "  " & aAttr.Name & " = NULL;"
      aCleanFcn.AddLine "}"
      aCleanFcn.AddLine ""
    End If
    
    aTickFcn.AddLine "}"
    aTickFcn.AddLine "if (++nTicks == interval) nTicks = 0;"
    
    aTickFcn.CgInit
    aTimeFcn.CgInit
    aBroadcastFcn.CgInit
    aInitFcn.CgInit
    aCleanFcn.CgInit
    
    bNewClass = False
    'Set aClass = IntegrationPackage.obj.findClass(aTask.ClassName)  //Why doesn't this work???
    For i = 1 To IntegrationPackage.Classes.count
        If IntegrationPackage.Classes(i).Name = aTask.ClassName Then
            Set aClass = IntegrationPackage.Classes(i)
            Exit For
        End If
    Next i
    
    If aClass Is Nothing Then
        bNewClass = True
        Set aClass = New rtsClass
        Set aClass.Project = IntegrationProject
        aClass.PackageName = IntegrationPackage.Name
        aClass.Name = aTask.ClassName
        Set aClass.Class = IntegrationPackage.obj.addClass(aClass.Name)
    End If
    
    aClass.OnCg = True
    AddCgObjects IntegrationPackage.Name, aClass.Name, aClass, ClassCgAttributes, classCgOperations, bViewDetails
    If bNewClass Then
        IntegrationPackage.Classes.Add aClass
    End If
    Call GetClassInfo(IntegrationProject, IntegrationPackage.Name, aClass.Name, aClass)
  Next
  
  Set aClass = Nothing
  Set ClassCgAttributes = Nothing
  Set classCgOperations = Nothing
  Set ClassCgAttributes = New Collection
  Set classCgOperations = New Collection
  ' generate application from tasks
  ' add a constructor
  Set aFcn = New CgOperation
  aFcn.bConstructor = True
  aFcn.Name = szIntAppName
  aFcn.Access = "public"
  aFcn.AddLine "init();"
  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn
  
  ' add a destructor
  Set aFcn = New CgOperation
  aFcn.bDestructor = True
  aFcn.Name = "~" & szIntAppName
  aFcn.Access = "public"
  aFcn.AddLine "clean();"
  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn
  
  Set aTimeFcn = New CgOperation
  aTimeFcn.Name = "setTime"
  aTimeFcn.AddPar "t", "double", "In"
  aTimeFcn.Access = "public"
  aTimeFcn.ReturnType = "void"
  aTimeFcn.OnCg = True
  classCgOperations.Add aTimeFcn
  
  Set aTickFcn = New CgOperation
  aTickFcn.Name = "handle_tick"
  aTickFcn.Access = "public"
  aTickFcn.ReturnType = "void"
  aTickFcn.OnCg = True
  classCgOperations.Add aTickFcn
  
  ' generate the header for the init() method
  Set aInitFcn = New CgOperation
  aInitFcn.Name = "init"
  aInitFcn.ReturnType = "void"
  aInitFcn.Access = "public"
  aInitFcn.OnCg = True
  classCgOperations.Add aInitFcn
   
  ' generate the header for the clean() method
  Set aCleanFcn = New CgOperation
  aCleanFcn.Name = "clean"
  aCleanFcn.ReturnType = "void"
  aCleanFcn.Access = "public"
  aCleanFcn.OnCg = True
  classCgOperations.Add aCleanFcn

  For Each aTask In taskList
    Set aAttr = New CgAttribute
    aAttr.bAggregate = True
    aAttr.Access = "public"
    #If using_ilogix Then
      aAttr.dataType = aTask.ClassName
    #End If
    aAttr.PackageName = IntegrationPackage.Name
    aAttr.bSim = False
    aAttr.Name = aTask.ObjectName
    aAttr.DefaultValue = "NULL"
    aAttr.OnCg = True
    ClassCgAttributes.Add aAttr, aAttr.Name
    
    aInitFcn.AddLine aAttr.Name & " = new " & aTask.ClassName & "();"
    aInitFcn.AddLine ""
    
    aTimeFcn.AddLine aAttr.Name & "->setTime(t);"
    'aTickFcn.AddLine "  " & aAttr.Name & "->handle_tick(t);"
    aTickFcn.AddLine "  " & aAttr.Name & "->handle_tick();"
    
    aCleanFcn.AddLine "if (" & aAttr.Name & ")"
    aCleanFcn.AddLine "{"
    aCleanFcn.AddLine "  delete " & aAttr.Name & ";"
    aCleanFcn.AddLine "  " & aAttr.Name & " = NULL;"
    aCleanFcn.AddLine "}"
    aCleanFcn.AddLine ""
  Next
   
  Dim szCompositeName As String
  If Not CompositeModelClass Is Nothing Then
    szCompositeName = CompositeModelClass.Name
  End If
  
  Call CgIntegrationInitCommunication( _
    szCompositeName, _
    aInitFcn, _
    aCleanFcn, _
    UDIs, _
    aUDIDefMgr, _
    ConnInfo, _
    ClassCgAttributes, _
    taskList, _
    szIntAppName, _
    szIntPhysicalSubsystemName, _
    szIntTaskRootName, _
    bSuccess)
  
  If Not bSuccess Then
    GetIntegrationTaskCgObjects = False
    Exit Function
  End If
  

  For Each aTask In taskList
    aInitFcn.AddLine aTask.ObjectName & "->broadcast();"
  Next
  
  aInitFcn.CgInit
  aCleanFcn.CgInit
  aTickFcn.CgInit
  aTimeFcn.CgInit
  
  bNewClass = False
  'Set aClass = IntegrationPackage.obj.findClass(szIntAppName)       //Why doesn't this work???
  For i = 1 To IntegrationPackage.Classes.count
    If IntegrationPackage.Classes(i).Name = szIntAppName Then
        Set aClass = IntegrationPackage.Classes(i)
        Exit For
    End If
  Next i
  If aClass Is Nothing Then
    bNewClass = True
    Set aClass = New rtsClass
    Set aClass.Project = IntegrationProject
    aClass.PackageName = IntegrationPackage.Name
    aClass.Name = szIntAppName
    Set aClass.Class = IntegrationPackage.obj.addClass(aClass.Name)
  End If
  aClass.OnCg = True
  aClass.impIncludes = "EventBroadcast.h, OnDataCollector.h"

  For Each aUDI In UDIs
    If Not InStr(1, aClass.impIncludes, aUDI.ClassName & ".h") > 0 Then
      aClass.impIncludes = aClass.impIncludes & ", " & aUDI.ClassName & ".h"
    End If
  Next aUDI
  If Not CompositeModelClass Is Nothing Then
    If Not InStr(1, aClass.impIncludes, CompositeModelClass.Name & ".h") > 0 Then
      aClass.impIncludes = aClass.impIncludes & ", " & CompositeModelClass.Name & ".h"
    End If
  End If
  If bGenSubsystem Then
    If Not InStr(1, aClass.impIncludes, szIntPhysicalSubsystemName & ".h") > 0 Then
      aClass.impIncludes = aClass.impIncludes & ", " & szIntPhysicalSubsystemName & ".h"
    End If
  End If
  
  AddCgObjects IntegrationPackage.Name, aClass.Name, aClass, ClassCgAttributes, classCgOperations, bViewDetails
  If bNewClass Then
   IntegrationPackage.Classes.Add aClass, aClass.Name
  End If
  Call GetClassInfo(IntegrationProject, IntegrationPackage.Name, aClass.Name, aClass)
  
  GetIntegrationTaskCgObjects = True
  
  Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Task object code generation error: " & err.Description
End Function

Sub CgIntegrationSystemModelClean(aFcn As CgOperation, UDIs As Collection, szModelClass As String)
  Dim aUDI As UserDefinedItem
  Dim szMemberName As String
  
  On Error GoTo Error_Handler
  For Each aUDI In UDIs
    If aUDI.m_Info.ModelType = idxClassType_Model And Not aUDI.globalName = aUDI.ClassName Then
     ' TODO: exclude the global model
      szMemberName = aUDI.ObjectName
      szMemberName = Replace(szMemberName, " ", "_")
      aFcn.AddLine "if (" & szMemberName & ")"
      aFcn.AddLine "{"
      aFcn.AddLine "  " & szMemberName & "->Release();"
      aFcn.AddLine "  " & szMemberName & " = NULL;"
      aFcn.AddLine "}"
    End If
  Next
  
  Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "System Model code generation error: " & err.Description
End Sub

Private Function GetConnectionAttributes(aUDIDefMgr As UDIDefMgr, UDI1 As UserDefinedItem, UDI2 As UserDefinedItem, connName As String, itemType As Long, itemName As String, attrType As Long, operType As Long) As Boolean
  Dim aConnDef As CgConnectionDef
  Dim aUDIDef As UserDefinedItemDef
  Dim bFound As Boolean
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim msg As String
  
  On Error GoTo Error_Handler
  itemType = idxItemType_Undefined
  itemName = ""
  attrType = idxAttr_Undefined
  operType = idxOper_Undefined
    
  If Len(UDI1.m_strDefObjectName) = 0 Then UDI1.m_strDefObjectName = UDI1.ObjectName
  Set aUDIDef = aUDIDefMgr.GetUDIDefbyObjectName(UDI1.m_strDefObjectName)
  bFound = False
  If Not aUDIDef Is Nothing Then
    Set aConnDef = aUDIDef.FindConnection(connName)
    If Not aConnDef Is Nothing Then
      If aConnDef.itemType = idxItemType_Attribute Then
        Set aAttr = aUDIDef.FindAttribute(aConnDef.itemName)
        If Not aAttr Is Nothing Then
          bFound = True
          itemType = idxItemType_Attribute
          itemName = aAttr.Name
          attrType = aAttr.sType
        Else
          msg = "Attribute '" & aConnDef.itemName & "' not found for object '" & UDI1.ObjectName & "'.  Connection between '" & UDI1.ObjectName & "' and '" & UDI2.ObjectName & "' not implemented."
          gMsgWnd.LogMessage msg
        End If
      ElseIf aConnDef.itemType = idxItemType_Operation Then
        Set aOper = aUDIDef.FindOperation(aConnDef.itemName)
        If Not aOper Is Nothing Then
          bFound = True
          itemType = idxItemType_Operation
          itemName = aOper.Name
          operType = aOper.sType
        Else
          msg = "Operation '" & aConnDef.itemName & "' not found for object '" & UDI1.ObjectName & "'.  Connection between '" & UDI1.ObjectName & "' and '" & UDI2.ObjectName & "' not implemented."
          gMsgWnd.LogMessage msg
        End If
      End If
    Else
      msg = "Connection definition '" & connName & "' not found for object '" & UDI1.ObjectName & "'.  Connection between '" & UDI1.ObjectName & "' and '" & UDI2.ObjectName & "' not implemented."
      gMsgWnd.LogMessage msg
    End If
  Else
    msg = "Object definition not found for object '" & UDI1.ObjectName & "' based on object definition name '" & UDI1.m_strDefObjectName & "'.  Connection between '" & UDI1.ObjectName & "' and '" & UDI2.ObjectName & "' not implemented."
    gMsgWnd.LogMessage msg
  End If
  
  GetConnectionAttributes = bFound
  Exit Function
    
Error_Handler:
    gMsgWnd.LogMessage "Connection attributes retrieval error: " & err.Description
End Function

Private Sub ImplementSignalConnection(szModelExecName As String, broadcastMaps As Collection, UDI1 As UserDefinedItem, UDI2 As UserDefinedItem, ItemType1 As Long, AttrType1 As Long, ItemName1 As String, ItemType2 As Long, AttrType2 As Long, ItemName2 As String)
  Dim aOper As CgOperation
  Dim aAttr As CgAttribute
  Dim szParameterType As String
  Dim aBroadcastMap As CgBroadcastMap
  Dim szTargetCompositeObject As String
  
  On Error Resume Next
  If ItemType1 = idxItemType_Operation Then
    Set aOper = UDI1.m_Info.Operations(ItemName1)
    szParameterType = Replace(aOper.Parameters(aOper.Parameters.count).dataType, "const ", "")
    szParameterType = adg.ReplacePat(szParameterType, "[ *]", "")
  ElseIf AttrType1 = idxAttr_Output Then
    Set aAttr = UDI1.m_Info.Attributes(ItemName1)
    szParameterType = Replace(aAttr.dataType, "const ", "")
    szParameterType = adg.ReplacePat(szParameterType, "[ *]", "")
  ElseIf ItemType2 = idxItemType_Operation Then
    Set aOper = UDI2.m_Info.Operations(ItemName2)
    szParameterType = Replace(aOper.Parameters(aOper.Parameters.count).dataType, "const ", "")
    szParameterType = adg.ReplacePat(szParameterType, "[ *]", "")
  ElseIf AttrType2 = idxAttr_Input Or AttrType2 = idxAttr_Undefined Then
    Set aAttr = UDI2.m_Info.Attributes(ItemName2)
    szParameterType = Replace(aAttr.dataType, "const ", "")
    szParameterType = adg.ReplacePat(szParameterType, "[ *]", "")
  Else
    szParameterType = "double"
  End If
  
  Set aBroadcastMap = broadcastMaps(UDI1.ObjectName & ItemName1)
  If err <> 0 Then
    Set aBroadcastMap = New CgBroadcastMap
    aBroadcastMap.ArgType = szParameterType
    If UDI1.m_Info.ModelType = idxClassType_Model Then
      aBroadcastMap.SourceCompositeObject = szModelExecName
    Else
      aBroadcastMap.SourceCompositeObject = UDI1.globalName
    End If
    
    If ItemType1 = idxItemType_Operation Then
      ' source is an operation
      aBroadcastMap.itsType = Broadcaster_Fcn_Impl
      aBroadcastMap.SourceClass = UDI1.ClassName
      aBroadcastMap.SourceObject = UDI1.globalName
      aBroadcastMap.SourceFunction = ItemName1
    
    ElseIf AttrType1 = idxAttr_Broadcaster Then
      ' source is a broadcaster
      aBroadcastMap.itsType = Broadcaster_Entry
      aBroadcastMap.SourceClass = UDI1.ClassName
      aBroadcastMap.SourceObject = UDI1.globalName
      aBroadcastMap.SourceBroadcaster = UDI1.globalName & "->" & ItemName1
    Else
      ' source is an output attribute
      Set aAttr = UDI1.m_Info.Attributes(ItemName1)
      If aAttr.sSubType = idxAttr_Scalar Then
        aBroadcastMap.itsType = Broadcaster_Scalar_Impl
      ElseIf aAttr.sSubType = idxAttr_Array Then
        aBroadcastMap.itsType = Broadcaster_Vector_Impl
      End If
      aBroadcastMap.SourceClass = UDI1.ClassName
      aBroadcastMap.SourceObject = UDI1.globalName
      aBroadcastMap.SourceAttribute = aAttr.Name
      aBroadcastMap.SourceAttributeSize = aAttr.dim1
    End If
    broadcastMaps.Add aBroadcastMap, UDI1.ObjectName & ItemName1
  End If
  If UDI2.m_Info.ModelType = idxClassType_Model Then
    szTargetCompositeObject = szModelExecName
  Else
    szTargetCompositeObject = UDI2.globalName
  End If
  ' KAB changed communication macros
  Call aBroadcastMap.AddListener(szTargetCompositeObject, UDI2.ClassName, UDI2.globalName, ItemName2, ItemName2, ItemType2 = idxItemType_Operation, True)

End Sub

Private Sub ImplementEventConnection(szModelExecName As String, broadcastMaps As Collection, UDI1 As UserDefinedItem, UDI2 As UserDefinedItem, ItemType1 As Long, AttrType1 As Long, ItemName1 As String, ItemType2 As Long, AttrType2 As Long, ItemName2 As String)
  Dim aOper As CgOperation
  Dim aAttr As CgAttribute
  Dim aBroadcastMap As CgBroadcastMap
  Dim szTargetCompositeObject As String
  
  On Error Resume Next
  Set aBroadcastMap = broadcastMaps(UDI1.ObjectName & ItemName1)
  If err <> 0 Then
    Set aBroadcastMap = New CgBroadcastMap
    If UDI1.m_Info.ModelType = idxClassType_Model Then
      aBroadcastMap.SourceCompositeObject = szModelExecName
    Else
      aBroadcastMap.SourceCompositeObject = UDI1.globalName
    End If
    
    ' source is a broadcaster
    aBroadcastMap.itsType = EventBroadcaster_Entry
    aBroadcastMap.SourceClass = UDI1.ClassName
    aBroadcastMap.SourceObject = UDI1.globalName
    aBroadcastMap.SourceBroadcaster = UDI1.globalName & "->" & ItemName1
    broadcastMaps.Add aBroadcastMap, UDI1.ObjectName & ItemName1
  End If
  If UDI2.m_Info.ModelType = idxClassType_Model Then
    szTargetCompositeObject = szModelExecName
  Else
    szTargetCompositeObject = UDI2.globalName
  End If
  
  Call aBroadcastMap.AddListener(szTargetCompositeObject, UDI2.ClassName, UDI2.globalName, ItemName2, ItemName2, ItemType2 = idxItemType_Operation, ItemType2 = idxItemType_Undefined)

End Sub

Private Sub ImplementDataCollectorConnection(aUDIDefMgr As UDIDefMgr, broadcastMaps As Collection, szParameterType As String, szModelExecName As String, UDI1 As UserDefinedItem, UDI2 As UserDefinedItem, ConnName1 As String, ItemType1 As Long, AttrType1 As Long, ItemName1 As String, ConnName2 As String, ItemType2 As Long, AttrType2 As Long, ItemName2 As String)
  Dim aBroadcastMap As CgBroadcastMap
  Dim aUDIDef As UserDefinedItemDef
  Dim aConnDef As CgConnectionDef
  Dim szTargetCompositeObject As String
  
  ' start is a variable / data collector, end is a handler function / listener
  On Error Resume Next
  err = 0
  Set aBroadcastMap = broadcastMaps(UDI1.ObjectName & "_" & ItemName1)
  
  If err <> 0 Then
    Set aBroadcastMap = New CgBroadcastMap
    aBroadcastMap.ArgType = szParameterType
    If AttrType1 = idxAttr_Variable Then
      aBroadcastMap.itsType = DataCollector_Impl
      aBroadcastMap.SourceCompositeObject = szModelExecName
      aBroadcastMap.SourceModelObject = UDI1.interfaceName
    Else
      aBroadcastMap.itsType = DataCollector_Entry
      aBroadcastMap.SourceCompositeObject = szModelExecName
      aBroadcastMap.SourceModelObject = UDI1.interfaceName
      aBroadcastMap.SourceDataCollector = ItemName1
    End If
    Set aUDIDef = aUDIDefMgr.GetUDIDefbyObjectName(UDI1.m_strDefObjectName)
    For Each aConnDef In aUDIDef.CgConnectionDefs
      If aConnDef.connName = ConnName1 Then
        If aConnDef.itemType = idxItemType_Attribute And aConnDef.attrType = idxAttr_Variable Then
          aBroadcastMap.AddVariable aConnDef.itemName
        End If
      End If
    Next
    
    broadcastMaps.Add aBroadcastMap, UDI1.ObjectName & "_" & ItemName1
  End If
  
  If UDI2.m_Info.ModelType = idxClassType_Model Then
    szTargetCompositeObject = szModelExecName
  Else
    szTargetCompositeObject = UDI2.globalName
  End If
  ' KAB changed communication macros
  Call aBroadcastMap.AddListener(szTargetCompositeObject, UDI2.ClassName, UDI2.globalName, ItemName2, ItemName2, ItemType2 = idxItemType_Operation, True)

End Sub

Public Function CgIntegrationInitCommunication( _
    szModelClass As String, _
    aInitFcn As CgOperation, _
    aCleanFcn As CgOperation, _
    UDIs As Collection, _
    aUDIDefMgr As UDIDefMgr, _
    ConnInfo As Collection, _
    ClassCgAttributes As Collection, _
    taskList As Collection, _
    szIntAppName As String, _
    szIntPhysicalSubsystemName As String, _
    szIntTaskRootName As String, _
    ByRef bSuccess As Boolean)
  
  Dim i As Long
  Dim j As Long
  Dim aUDI As UserDefinedItem
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim aProperty As CgAttribute
  Dim aConn As ConnectionInfo
  Dim aUDIDef As UserDefinedItemDef
  
  Dim startItemType As Long
  Dim startItemName As String
  Dim startAttrType As Long
  Dim startOperType As Long
  
  Dim endItemType As Long
  Dim endItemName As String
  Dim endAttrType As Long
  Dim endOperType As Long
  
  Dim idxUDI As Long
  Dim aConnDef As CgConnectionDef
  
  Dim szParameterType As String
  Dim szModelExecName As String
  Dim msg As String
  
  ' app
  '   t1
  '     discrete_UDI1
  '     discrete_UDI2
  '   t2*
  '     modelExec
  '       m_pGlobalModel
  '         model_UDI3
  '         model_UDI4
  '       IModel_UDI3
  '       IModel_UDI4
  
  ' determine global names for UDIs
  Dim aTask As rtsTask
  
  On Error GoTo Error_Handler
  
  For Each aTask In taskList
    For Each aUDI In aTask.Models
      aUDI.globalName = aTask.ObjectName & "->" & aUDI.ObjectName
    Next
    If Not aTask.ModelExecClass Is Nothing Then
      szModelExecName = aTask.ObjectName & "->its" & szIntPhysicalSubsystemName
      For Each aUDI In UDIs
        If aUDI.m_Info.ModelType = idxClassType_Model Then
          If aUDI.ClassName = szModelClass Then
            aUDI.globalName = szModelExecName & "->m_pSystemModel"
            aUDI.interfaceName = szModelExecName & "->m_pModel"
          Else
            aUDI.interfaceName = szModelExecName & "->" & aUDI.ObjectName
            aUDI.globalName = szModelExecName & "->m_pSystemModel->" & aUDI.ObjectName
          End If
        End If
      Next
    End If
  Next
  
  ' there are 2 cases to be managed:
  ' 1) Multiple models in this diagram are being combined to form a composite.
  ' 2) Composite was already formed elsewhere, and it is the only model on this diagram.
  
  ' determine between case 1 and case 2
  Dim model_count As Long
  Dim szClassName As String
  Dim bCompositeInDiagram As Boolean
  Dim bMultipleModels As Boolean
  Dim bSingleModel As Boolean
  Dim broadcastMaps As Collection
  Dim aBroadcastMap As CgBroadcastMap
  Dim iWarnings As Integer
  
  Set broadcastMaps = New Collection
  
  idxUDI = 0
  iWarnings = 0
  ' iterate over list of connections
  For Each aConn In ConnInfo
    
    Call GetConnectionAttributes(aUDIDefMgr, aConn.ObjA, aConn.ObjB, aConn.NameA, startItemType, startItemName, startAttrType, startOperType)
    Call GetConnectionAttributes(aUDIDefMgr, aConn.ObjB, aConn.ObjA, aConn.NameB, endItemType, endItemName, endAttrType, endOperType)
    
    Dim szObjName As String
    
    If (startItemType = idxItemType_Attribute And startAttrType = idxAttr_Broadcaster Or _
        startItemType = idxItemType_Attribute And startAttrType = idxAttr_Output Or _
        startItemType = idxItemType_Operation And startOperType = idxOper_Get) And _
       (endItemType = idxItemType_Operation Or _
        endItemType = idxItemType_Attribute And endAttrType = idxAttr_Input) Then
        
      Call ImplementSignalConnection( _
        szModelExecName, _
        broadcastMaps, _
        aConn.ObjA, _
        aConn.ObjB, _
        startItemType, _
        startAttrType, _
        startItemName, _
        endItemType, _
        endAttrType, _
        endItemName)
    
    ElseIf (startItemType = idxItemType_Attribute And startAttrType = idxAttr_Broadcaster) And _
           (endItemType = idxItemType_Undefined Or _
            endItemType = idxItemType_Attribute And endAttrType = idxAttr_Listener) Then
        
      Call ImplementEventConnection( _
        szModelExecName, _
        broadcastMaps, _
        aConn.ObjA, _
        aConn.ObjB, _
        startItemType, _
        startAttrType, _
        startItemName, _
        endItemType, _
        endAttrType, _
        endItemName)
    
    ElseIf (endItemType = idxItemType_Attribute And endAttrType = idxAttr_Broadcaster) And _
           (startItemType = idxItemType_Undefined Or _
            startItemType = idxItemType_Attribute And startAttrType = idxAttr_Listener) Then
        
      Call ImplementEventConnection( _
        szModelExecName, _
        broadcastMaps, _
        aConn.ObjB, _
        aConn.ObjA, _
        endItemType, _
        endAttrType, _
        endItemName, _
        startItemType, _
        startAttrType, _
        startItemName)
    
    ElseIf (endItemType = idxItemType_Attribute And endAttrType = idxAttr_Broadcaster Or _
        endItemType = idxItemType_Attribute And endAttrType = idxAttr_Output Or _
        endItemType = idxItemType_Operation And endOperType = idxOper_Get) And _
       (startItemType = idxItemType_Operation Or _
        startItemType = idxItemType_Attribute And startAttrType = idxAttr_Input) Then
        
      Call ImplementSignalConnection( _
        szModelExecName, _
        broadcastMaps, _
        aConn.ObjB, _
        aConn.ObjA, _
        endItemType, _
        endAttrType, _
        endItemName, _
        startItemType, _
        startAttrType, _
        startItemName)
      
    ElseIf (startItemType = idxItemType_Attribute And startAttrType = idxAttr_Variable Or _
            startItemType = idxItemType_Attribute And startAttrType = idxAttr_DataCollector) And _
           (endItemType = idxItemType_Operation Or _
            endItemType = idxItemType_Attribute And endAttrType = idxAttr_Input) Then
      
      Call ImplementDataCollectorConnection( _
        aUDIDefMgr, _
        broadcastMaps, _
        szParameterType, _
        szModelExecName, _
        aConn.ObjA, _
        aConn.ObjB, _
        aConn.NameA, _
        startItemType, _
        startAttrType, _
        aConn.NameB, _
        startItemName, _
        endItemType, _
        endAttrType, _
        endItemName)
        
    ElseIf (endItemType = idxItemType_Attribute And endAttrType = idxAttr_Variable Or _
            endItemType = idxItemType_Attribute And endAttrType = idxAttr_DataCollector) And _
           (startItemType = idxItemType_Operation Or _
            startItemType = idxItemType_Attribute And startAttrType = idxAttr_Input) Then
      
      Call ImplementDataCollectorConnection( _
        aUDIDefMgr, _
        broadcastMaps, _
        szParameterType, _
        szModelExecName, _
        aConn.ObjB, _
        aConn.ObjA, _
        aConn.NameB, _
        endItemType, _
        endAttrType, _
        endItemName, _
        aConn.NameA, _
        startItemType, _
        startAttrType, _
        startItemName)
      
    Else
      If startAttrType <> idxAttr_Connector And endAttrType <> idxAttr_Connector Then
        msg = "Connection from '" & aConn.ObjA.ObjectName & "." & startItemName & "' to '" & aConn.ObjB.ObjectName & "." & endItemName & "' can not be verified.  Verify operation and attribute specifications using the Class Wizard."
        iWarnings = iWarnings + 1
        gMsgWnd.LogMessage msg
      End If
    End If
    
next_item:
  Next

  If iWarnings > 0 Then
      Dim Response As Integer
      msg = "Not all connections could be verified.  Continue with code generation?"
      Response = MsgBox(msg, vbYesNo, "Connection Verification")
      If Response = vbNo Then
        bSuccess = False
        Exit Function
      End If
  End If
  
  aInitFcn.AddLine ""
  aInitFcn.AddLine "// begin broadcaster / handler communication initialization"
  For Each aBroadcastMap In broadcastMaps
    aInitFcn.AddLine aBroadcastMap.CgInit
  Next
  aInitFcn.AddLine "// end broadcaster / handler communication initialization"
  aInitFcn.AddLine ""
  bSuccess = True
  Exit Function
    
Error_Handler:
    gMsgWnd.LogMessage "InitCommunication code generation error: " & err.Description
End Function


Public Sub CgIntegrationLoad(AppModelName As String, classCgOperations As Collection)
  Dim aFcn As CgOperation
  
  On Error GoTo Error_Handler
  Set aFcn = New CgOperation
  aFcn.Access = "public"
  aFcn.Name = "Load"
  aFcn.AddPar "filename", "BSTR", "In"
  aFcn.ReturnType = "bool"
  
  aFcn.AddLine "if (SUCCEEDED( m_pModelExec->Load(filename) ))"
  aFcn.AddLine "  return true;"
  aFcn.AddLine "else"
  aFcn.AddLine "  return false;"

  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn, aFcn.Name
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Load code generation error: " & err.Description
End Sub

Public Sub CgIntegrationSave(AppModelName As String, classCgOperations As Collection)
  Dim aFcn As CgOperation
  
  On Error GoTo Error_Handler
  Set aFcn = New CgOperation
  aFcn.Access = "public"
  aFcn.Name = "Save"
  aFcn.AddPar "filename", "BSTR", "In"
  aFcn.ReturnType = "void"

  aFcn.AddLine "m_pModelExec->Save(filename);"
  
  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn, aFcn.Name
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Save code generation error: " & err.Description
End Sub

' consolidated system model referred to as m_pSystemModel
' consolidated wrapper model referred to as m_pModel
Public Sub CgIntegrationSystemModelInit( _
  szModelPackage As String, _
  szModelClass As String, _
  aFcn As CgOperation, _
  UDIs As Collection, _
  ClassCgAttributes As Collection, _
  bMaxStepSize As Boolean, _
  maxStepSize As Double)

  Dim aAttr As CgAttribute
  Dim aUDI As UserDefinedItem
 
  On Error GoTo Error_Handler
  szModelClass = Replace(LTrim(RTrim(szModelClass)), " ", "_")
  
  aFcn.AddLine "long i;"
  ' KAB no longer required --> handled in base class
  'aFcn.AddLine ""
  'aFcn.AddLine "COnSubsystemBase<" & szModelClass & ">::init();"
  aFcn.AddLine ""
  If bMaxStepSize Then
    aFcn.AddLine "m_pModelExec->put_MaxStepSize(" & maxStepSize & ");"
  End If
  
  aFcn.AddLine ""
  aFcn.AddLine "// tolerance initialization"
  aFcn.AddLine "m_pModel->GetNumVars(&nVars);"

  aFcn.AddLine "SAFEARRAY* psa_atol = SafeArrayCreateVector(VT_R8, 0, nVars);"
  aFcn.AddLine "SAFEARRAY* psa_rtol = SafeArrayCreateVector(VT_R8, 0, nVars);"
  aFcn.AddLine "double* v_atol = NULL;"
  aFcn.AddLine "double* v_rtol = NULL;"
  aFcn.AddLine "SafeArrayAccessData(psa_atol, (void HUGEP* FAR*)& v_atol);"
  aFcn.AddLine "SafeArrayAccessData(psa_rtol, (void HUGEP* FAR*)& v_rtol);"
  
  aFcn.AddLine ""
  aFcn.AddLine "// TODO: modify tolerances as necessary"
  aFcn.AddLine "for (i = 0; i < nVars; i++)"
  aFcn.AddLine "{"
  aFcn.AddLine "  v_atol[i] = 1.0e-4;"
  aFcn.AddLine "  v_rtol[i] = 1.0e-4;"
  aFcn.AddLine "}"
  aFcn.AddLine ""
  aFcn.AddLine "SafeArrayUnaccessData(psa_atol);"
  aFcn.AddLine "SafeArrayUnaccessData(psa_atol);"

  aFcn.AddLine "m_pModel->SetAbsTolerance(&psa_atol);"
  aFcn.AddLine "m_pModel->SetRelTolerance(&psa_rtol);"
  
  aFcn.AddLine "SafeArrayDestroy(psa_atol);"
  aFcn.AddLine "SafeArrayDestroy(psa_rtol);"
  
  aFcn.AddLine "// end tolerance initialization"
  aFcn.AddLine ""

  aFcn.AddLine ""
  aFcn.AddLine "// time initialization"
  aFcn.AddLine "m_pModel->InitTime(0.0, VARIANT_FALSE);"
  
  aFcn.AddLine "// end time initialization"
  aFcn.AddLine ""
  
  aFcn.AddLine "// sub model initialization"
  Dim szObjectName As String
  
  ' there are 2 cases to be managed:
  ' 1) Multiple models in this diagram are being combined to form this composite.
  ' 2) Composite was already formed elsewhere, and it is the only model on this diagram.
  
  ' determine between case 1 and case 2
  Dim model_count As Long
  Dim szClassName As String
  Dim bCompositeInDiagram As Boolean
  
  For Each aUDI In UDIs
    If aUDI.m_Info.ModelType = idxClassType_Model Then
      szClassName = Replace(LTrim(RTrim(aUDI.m_Info.Name)), " ", "_")
      If szClassName = szModelClass Then bCompositeInDiagram = True
      model_count = model_count + 1
    End If
  Next
  
  ' case 1 is true if bCompositeInDiagram = False and model_count > 1
  ' case 2 is true if bCompositeInDiagram = True and model_count = 1
  
  If (Not bCompositeInDiagram) And (model_count > 1) Then ' case 1
    For Each aUDI In UDIs
      If aUDI.m_Info.ModelType = idxClassType_Model Then
        szObjectName = aUDI.ObjectName
        szObjectName = Replace(szObjectName, " ", "_")
        Set aAttr = New CgAttribute
        aAttr.Access = "Public"
        #If using_ilogix Then
          'aAttr.DataType = "IIsDaeEsoCImpl"
          aAttr.dataType = "IIsDaeEsoCImpl*"
        #End If
        'aAttr.packageName = "OniBase"
        'aAttr.bAggregate = True
        aAttr.bAggregate = False
        'aAttr.bRef = True
        aAttr.Name = szObjectName
        aAttr.Access = "public"
        aAttr.DefaultValue = "NULL"
        aAttr.OnCg = True
        ClassCgAttributes.Add aAttr
         
        aFcn.AddLine "m_pModel->get_Eso(L" & Chr(34) & szObjectName & Chr(34) & ", &" & szObjectName & ");"
      End If
    Next
  ElseIf bCompositeInDiagram And (model_count = 1) Then ' case 2
    ' need to think this through, but it doens't appear that anything is required in this case.
  End If
  aFcn.AddLine "// end sub model initialization"
  aFcn.AddLine ""
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "SystemModelInit code generation error: " & err.Description
End Sub
  
Private Function CgIntegrationGetBlockExecutionOrder(ConnInfo As Collection, ByRef UDIs As Collection, taskList As Collection, aUDIDefMgr As UDIDefMgr) As Boolean
  Dim ns As OnNodeSort
  Dim nNodes, nEdges As Long
  Dim i, j As Long
  Dim k As Long
  Dim n As Long
  Dim L As Long
  Dim aConnInfo As ConnectionInfo
  Dim cBlocks As Long
  Dim colBlockToID As Collection
  Dim aUDI As UserDefinedItem
  Dim iLoopCount As Integer
  Dim bFound As Boolean
  Dim iConA As Integer
  Dim iConB As Integer
  Dim uniqueConns As Collection
  Dim strKey As String
  
  iLoopCount = 0
  CgIntegrationGetBlockExecutionOrder = True
  Set colBlockToID = New Collection
  Set ns = New OnNodeSort
  
  On Error GoTo Error_Handler
  Dim aTask As rtsTask
  Dim filteredConnInfo As Collection
  Dim UDIConA As UserDefinedItem
  Dim UDIConB As UserDefinedItem
  
  For L = 1 To taskList.count
      Set filteredConnInfo = New Collection
      Set aTask = taskList(L)
      'Filter connections list such that only connections that have source and end in the nodes of this task
      For Each aConnInfo In ConnInfo
          Set UDIConA = aConnInfo.ObjA
          Set UDIConB = aConnInfo.ObjB
          ' KAB April 2 2003 fix
          On Error Resume Next
          Set aUDI = Nothing
          Set aUDI = aTask.Models(UDIConA.ObjectName)
          If Not aUDI Is Nothing Then
            Set aUDI = Nothing
            Set aUDI = aTask.Models(UDIConB.ObjectName)
            If Not aUDI Is Nothing Then
              filteredConnInfo.Add aConnInfo
            End If
          End If
          On Error GoTo Error_Handler
      Next
        
      nNodes = aTask.Models.count
      ReDim orderMap(nNodes) As Long
      ReDim blockSizes(nNodes) As Long
      ReDim spRow(nNodes) As Long
      ReDim subset(nNodes) As Boolean
       
      For k = 0 To (nNodes - 1)
        Set aUDI = aTask.Models(k + 1)
        colBlockToID.Add k, CStr(aUDI.SIDID)
      Next k
          
      'Remove Duplicates by building up temporary list of unique connections
      Set uniqueConns = New Collection
      Debug.Print "*** CONNECTIONS WITH DUPLICATES ****"
      For Each aConnInfo In filteredConnInfo
          On Error Resume Next
          GetConnectionDirection aConnInfo, UDIs, aUDIDefMgr, iConA, iConB
          If iConA = 1 And iConB = 2 Then
            Debug.Print aConnInfo.ObjA.ObjectName & " ---> " & aConnInfo.ObjB.ObjectName
            strKey = aConnInfo.ObjA.SIDID & "-" & aConnInfo.ObjB.SIDID
          Else
            Debug.Print aConnInfo.ObjB.ObjectName & " ---> " & aConnInfo.ObjA.ObjectName
            strKey = aConnInfo.ObjB.SIDID & "-" & aConnInfo.ObjA.SIDID
          End If
          If uniqueConns(strKey) Is Nothing Then
            uniqueConns.Add aConnInfo, strKey
          End If
      Next
          
      n = 0
      nEdges = uniqueConns.count
      
      ReDim edgeList(nEdges * 2) As Long
      ReDim tearList(nEdges) As Boolean
      
      Debug.Print " "
      Debug.Print "*** CONNECTIONS WITH NO DUPLICATES ****"
      For i = 1 To uniqueConns.count
          Set aConnInfo = uniqueConns(i)
          GetConnectionDirection aConnInfo, UDIs, aUDIDefMgr, iConA, iConB
          If iConA = 1 And iConB = 2 Then
            Debug.Print aConnInfo.ObjA.ObjectName & " ---> " & aConnInfo.ObjB.ObjectName
            edgeList(n * 2) = colBlockToID(CStr(aConnInfo.ObjA.SIDID))
            edgeList(n * 2 + 1) = colBlockToID(CStr(aConnInfo.ObjB.SIDID))
          ElseIf iConB = 1 And iConA = 2 Then
            Debug.Print aConnInfo.ObjB.ObjectName & " ---> " & aConnInfo.ObjA.ObjectName
            edgeList(n * 2) = colBlockToID(CStr(aConnInfo.ObjB.SIDID))
            edgeList(n * 2 + 1) = colBlockToID(CStr(aConnInfo.ObjA.SIDID))
          Else
            Debug.Print aConnInfo.ObjA.ObjectName & " ---> " & aConnInfo.ObjB.ObjectName
            If aConnInfo.ObjA.m_Info.ModelType = idxClassType_NonSimulation And aConnInfo.ObjB.m_Info.ModelType = idxClassType_NonSimulation Then
              gMsgWnd.LogMessage "Integration wizard could not determine direction of the connection between '" & aConnInfo.ObjA.ObjectName & "' and '" & aConnInfo.ObjB.ObjectName & ".  " & aConnInfo.ObjA.ObjectName & " has been chosen as source."
            End If
            edgeList(n * 2) = colBlockToID(CStr(aConnInfo.ObjA.SIDID))
            edgeList(n * 2 + 1) = colBlockToID(CStr(aConnInfo.ObjB.SIDID))
          End If
          n = n + 1
      Next i
                   
repeat_loop:
      ns.SortBlocks nEdges, nNodes, edgeList, tearList, orderMap, cBlocks, blockSizes
      
      bFound = False
      j = 0
      For i = 0 To cBlocks - 1
        spRow(i) = j
        j = j + blockSizes(i)
      Next i
            
      For i = 0 To cBlocks - 1
        Debug.Print "Block " & i & "     ";
        For j = 0 To blockSizes(i) - 1
          Debug.Print orderMap(spRow(i) + j) & ", ";
        Next j
        Debug.Print ""
      Next i
           
      For i = 0 To cBlocks - 1
        If blockSizes(i) > 2 Then
          bFound = True
          For j = 0 To nNodes - 1
            subset(j) = False
          Next j
          
          For j = 0 To blockSizes(i) - 1
            subset(orderMap(j + spRow(i))) = True
          Next j
          
          'This is a list of all the tears that can be made
          For j = 0 To nEdges - 1
            If subset(edgeList(2 * j)) And subset(edgeList(2 * j + 1)) And Not tearList(j) Then
              tearList(j) = True
              Exit For
            End If
          Next j
          
          Exit For
        End If
      Next i
      
      If bFound Then GoTo repeat_loop
      
      k = 0
      Debug.Print " "
      Debug.Print "Task: " & aTask.ObjectName & " TS: " & aTask.TS
      For i = 0 To cBlocks - 1
        For j = 0 To blockSizes(i) - 1
           aTask.Models(orderMap(k) + 1).m_Order = k + 1
           Debug.Print "Order: " & aTask.Models(orderMap(k) + 1).m_Order & "     Node: " & aTask.Models(orderMap(k) + 1).ObjectName
          k = k + 1
        Next j
      Next i
      Debug.Print " "
            
  Next L

  Set ns = Nothing
  Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Error Sorting Blocks.  Code Generation Failed: " & err.Description
    Resume Next
    CgIntegrationGetBlockExecutionOrder = False
End Function

Private Sub GetConnectionDirection(aConnInfo As ConnectionInfo, UDIs As Collection, aUDIDefMgr As UDIDefMgr, ByRef iConA As Integer, ByRef iConB As Integer)
  Dim UDIDefA As UserDefinedItemDef
  Dim UDIDefB As UserDefinedItemDef
  Dim ConnA As CgConnectionDef
  Dim ConnB As CgConnectionDef
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  
  On Error Resume Next
  If aUDIDefMgr Is Nothing Then Exit Sub
  
  Set UDIDefA = aUDIDefMgr.GetUDIDefbyObjectName(aConnInfo.ObjA.m_strDefObjectName)
  Set UDIDefB = aUDIDefMgr.GetUDIDefbyObjectName(aConnInfo.ObjB.m_strDefObjectName)

  If (UDIDefA Is Nothing) Or (UDIDefB Is Nothing) Then Exit Sub
    
  Set ConnA = UDIDefA.FindConnection(aConnInfo.NameA)
  Set ConnB = UDIDefB.FindConnection(aConnInfo.NameB)
   
  iConA = 0
  iConB = 0
  If (Not ConnA Is Nothing) And (Not ConnB Is Nothing) Then
    If ConnA.itemType = idxItemType_Attribute Then
      Set aAttr = UDIDefA.FindAttribute(ConnA.itemName)
      If Not aAttr Is Nothing Then
        If aAttr.sType = idxAttr_Variable Or aAttr.sType = idxAttr_Broadcaster Or aAttr.sType = idxAttr_DataCollector Or aAttr.sType = idxAttr_Output Then
          iConA = 1 ' output
        ElseIf aAttr.sType = idxAttr_Parameter Or aAttr.sType = idxAttr_Listener Or aAttr.sType = idxAttr_Input Then
          iConA = 2 ' input
        End If
      End If
    ElseIf ConnA.itemType = idxItemType_Operation Then
      Set aOper = UDIDefA.FindOperation(ConnA.itemName)
      If Not aOper Is Nothing Then
        If aOper.sType = idxOper_Get Then
          iConA = 1 ' output
        ElseIf aOper.sType = idxOper_Set Then
          iConA = 2 ' input
        End If
      End If
    End If
  
    If ConnB.itemType = idxItemType_Attribute Then
      Set aAttr = UDIDefB.FindAttribute(ConnB.itemName)
      If Not aAttr Is Nothing Then
        If aAttr.sType = idxAttr_Variable Or aAttr.sType = idxAttr_Broadcaster Or aAttr.sType = idxAttr_DataCollector Or aAttr.sType = idxAttr_Output Then
          iConB = 1 ' output
        ElseIf aAttr.sType = idxAttr_Parameter Or aAttr.sType = idxAttr_Listener Or aAttr.sType = idxAttr_Input Then
          iConB = 2 ' input
        End If
      End If
    ElseIf ConnB.itemType = idxItemType_Operation Then
      Set aOper = UDIDefB.FindOperation(ConnB.itemName)
      If Not aOper Is Nothing Then
        If aOper.sType = idxOper_Get Then
          iConB = 1 ' output
        ElseIf aOper.sType = idxOper_Set Then
          iConB = 2 ' input
        End If
      End If
    End If
  End If
  
  err.Clear
End Sub

Private Function BlockSizesSame(blockSizes, blockSizesOld, count) As Boolean
    Dim i As Integer
    
    BlockSizesSame = True
    For i = 1 To count
        If blockSizes(i) <> blockSizesOld(i) Then
            BlockSizesSame = False
            Exit For
        End If
    Next i
End Function

