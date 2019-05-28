Attribute VB_Name = "CgLeafModels"
Option Explicit

Dim infos As Collection
Global adg As CgAD

Function GetLeafCgObjects(SelectedClass As rtsClass, ClassCgAttributes As Collection, classCgOperations As Collection, bVarAccessors As Boolean, bChildVarAccessors As Boolean) As Boolean

  Dim i As Long
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim aState As CgState
  Dim aTrans As CgTransition
  Dim srcOper As CgOperation
  Dim aFcn As CgOperation
  
  Dim Descriptor As String
  Dim ClassName As String
  
  Dim SimVars As Collection
  Dim SimRPars As Collection
  Dim SimIPars As Collection
  
  Dim SimEsos As Collection
  Dim SimEqns As Collection

  On Error GoTo Error_Handler
  GetLeafCgObjects = True
  ClassName = SelectedClass.Name
  
  ' initialization
  Set infos = New Collection
  Set adg = New CgAD
  If ClassCgAttributes Is Nothing Then Set ClassCgAttributes = New Collection
  If classCgOperations Is Nothing Then Set classCgOperations = New Collection
  
  ' local collections
  Set SimVars = New Collection
  Set SimRPars = New Collection
  Set SimIPars = New Collection
  Set SimEqns = New Collection
  Set SimEsos = New Collection
  
  
  ' build up local collections
  For Each aAttr In SelectedClass.Attributes
    If aAttr.sType = idxAttr_Variable Then
      ' add other versions of the variable (old, der, ad) if in implementation class
      If aAttr.ClassName = SelectedClass.Name Then
        If aAttr.dataType = "double" Then
          #If using_ilogix Then
            ' TODO: softcode package name
            Dim szPackageName As String
            
            szPackageName = "Default"
            CreateSimCompositeAttr "_" & aAttr.Name, szPackageName, "VarEx", "protected", ClassCgAttributes
            
          #End If
        End If
      End If
      
      SimVars.Add aAttr
      
    ElseIf aAttr.sType = idxAttr_Parameter And aAttr.dataType = "double" Then
      SimRPars.Add aAttr
      If SelectedClass.ModelType <> idxClassType_Structure Then
        CreateRParHandler SelectedClass, aAttr, SimRPars.count - 1, classCgOperations
      End If
      
    ElseIf aAttr.sType = idxAttr_Parameter And (aAttr.dataType = "long" Or aAttr.dataType = "int") Then
      SimIPars.Add aAttr
      If SelectedClass.ModelType <> idxClassType_Structure Then
        CreateIParHandler SelectedClass, aAttr, SimIPars.count - 1, classCgOperations
      End If
      
    ElseIf aAttr.sType = idxAttr_Connector Or aAttr.sType = idxAttr_Model Then
      SimEsos.Add aAttr
  
    ElseIf aAttr.sType = idxAttr_Struct Then
      SimVars.Add aAttr
      SimRPars.Add aAttr
      SimIPars.Add aAttr
      
    End If
  Next
  
  Dim varList As Collection
  Dim szPrefix As String
  Dim vName As Variant
  Dim vecName() As String
  Dim varName As String
  Set varList = New Collection
  
  ' generate variable accessors (if selected)
  If bVarAccessors Or bChildVarAccessors Then
    szPrefix = ""
    Call GetClassVariables(SelectedClass, szPrefix, varList)
      
    For Each aAttr In varList
      If (bVarAccessors And InStr(aAttr.Name, ".") = 0) Or (bChildVarAccessors And InStr(aAttr.Name, ".") > 0) Then
        vName = Split(aAttr.Name, ".")
        vecName = vName
        varName = vecName(UBound(vecName))
        
        Set aFcn = New CgOperation
        aFcn.OnCg = True
        aFcn.Access = "public"
        aFcn.ReturnType = "void"
        aFcn.Name = "get_" & varName
        aFcn.AddPar "t", "double", "in"
        aFcn.AddPar "pVal", "double*", "in_out"
        aFcn.AddLine "GET_VARIABLE_VALUE(L""" & aAttr.Name & """, t, pVal)"
        aFcn.CgInit
        classCgOperations.Add aFcn
        
        Set aFcn = New CgOperation
        aFcn.OnCg = True
        aFcn.Access = "public"
        aFcn.ReturnType = "void"
        aFcn.Name = "get_der_" & varName
        aFcn.AddPar "t", "double", "in"
        aFcn.AddPar "pVal", "double*", "in_out"
        aFcn.AddLine "GET_VARIABLE_DER_VALUE(L""" & aAttr.Name & """, t, pVal)"
        aFcn.CgInit
        classCgOperations.Add aFcn
        
      End If
    Next
  End If
  
  ' assign indices to all equations, states, and transitions
  ' NOTE: do not alter the order attribute, this is saved and cannot be used as a temporary placeholder
  '       a temporary placeholder attribute was added called idx.
  i = 0
  For Each aOper In SelectedClass.Operations
    If aOper.bSim Then
      aOper.idx = i
      i = i + 1
      SimEqns.Add aOper, aOper.Name
    End If
  Next
  
  i = 0
  For Each aState In SelectedClass.States
    aState.idx = i
    i = i + 1
  Next
  
  i = 0
  For Each aTrans In SelectedClass.Transitions
    aTrans.idx = i
    i = i + 1
  Next
  
  ' the variety of Init operations added to the class are not added to abstract models
  If SelectedClass.ModelType <> idxClassType_AbstractModel Then
    CgLeafInitEsos SimEsos, classCgOperations
    CgLeafEqnInit SimEqns, classCgOperations
    CgLeafADEqnInit SimEqns, classCgOperations
    CgLeafEqnFormInit SimEqns, classCgOperations
    
    CgLeafVarInit SimVars, classCgOperations, SelectedClass.ModelType
    CgLeafRParInit SimRPars, classCgOperations
    ' KAB change
    CgLeafIParInit SimIPars, classCgOperations, SelectedClass.ModelType
    
    ' state machine implementation
    If SelectedClass.States.count > 0 Then
      CgLeafTransitionInit SimEqns, SelectedClass, classCgOperations
      CgLeafStateInit SimEqns, SelectedClass.States, classCgOperations
      CgLeafOnTransition ClassName, SelectedClass.States, classCgOperations
      CgLeafTriggerEvent SelectedClass.Transitions, SimVars, classCgOperations
      CgLeafEvalStateCondition SelectedClass, classCgOperations
    End If
  End If
  
  ' NOTE: AD functions are only created on the class that implements the actual function
  '       abstract models implement the AD operations for their own operations
  CgLeafCreateADFcns SelectedClass, classCgOperations
  
  If SelectedClass.ModelType <> idxClassType_AbstractModel Then
    ' add shell load / save operations (if not already part of class
    CgLeafSaveFcn SelectedClass.Operations, classCgOperations
    CgLeafLoadFcn SelectedClass.Operations, classCgOperations
  End If
  
  #If 1 Then
    Dim aCgOp As CgOperation
    For Each aCgOp In classCgOperations
      Debug.Print aCgOp.Name
      Debug.Print aCgOp.Body
    Next
  #End If
  
  #If 1 Then
    Dim aCgAttr As CgAttribute
    For Each aCgAttr In ClassCgAttributes
      Debug.Print aCgAttr.Name
    Next
  #End If
  
  ' termination
  Set infos = Nothing
  Set adg = Nothing
  Set SimVars = Nothing
  Set SimRPars = Nothing
  Set SimIPars = Nothing
  Set SimEqns = Nothing
  Set SimEsos = Nothing
  Exit Function
    
Error_Handler:
    gMsgWnd.LogMessage "Class Wizard failed to retrieve objects for code generation. " & err.Description
End Function
      
Sub CreateRParHandler(SelectedClass As rtsClass, aAttr As CgAttribute, Index As Long, classCgOperations As Collection)
  Dim aOper As CgOperation
  
  On Error GoTo Error_Handler
  ' add parameter handler if in Model is not abstract
  If SelectedClass.ModelType <> idxClassType_AbstractModel Then
    Set aOper = New CgOperation
    aOper.OnCg = True
    aOper.Access = "public"
    aOper.Name = "handle_" & aAttr.Name
    aOper.ReturnType = "void"
    aOper.AddPar "t", "double", "In"
    aOper.AddPar "val", "double*", "In"
    aOper.AddLine "PostRealParameter(t, " & Index & ", *val);"
    aOper.CgInit
    classCgOperations.Add aOper
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "RParHandler code generation error: " & err.Description
End Sub
      
Sub CreateIParHandler(SelectedClass As rtsClass, aAttr As CgAttribute, Index As Long, classCgOperations As Collection)
  Dim aOper As CgOperation
  
  On Error GoTo Error_Handler
  ' add parameter handler if in Model is not abstract
  If SelectedClass.ModelType <> idxClassType_AbstractModel Then
    Set aOper = New CgOperation
    aOper.OnCg = True
    aOper.Access = "public"
    aOper.Name = "handle_" & aAttr.Name
    aOper.ReturnType = "void"
    aOper.AddPar "t", "double", "In"
    aOper.AddPar "val", "long*", "In"
    aOper.AddLine "PostIntegerParameter(t, " & Index & ", *val);"
    aOper.CgInit
    classCgOperations.Add aOper
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "IParHandler code generation error: " & err.Description
End Sub

Sub CreateSimAttr(AttrName As String, attrType As String, AttrAccess As String, coll As Collection)
  Dim aAttr As CgAttribute
  
  On Error GoTo Error_Handler
  Set aAttr = New CgAttribute
  aAttr.OnCg = True
  aAttr.Name = AttrName
  aAttr.dataType = attrType
  aAttr.Access = AttrAccess
  coll.Add aAttr
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Attribute '" & AttrName & "' add error: " & err.Description
End Sub

Sub CreateSimCompositeAttr(AttrName As String, PackageName As String, attrType As String, AttrAccess As String, coll As Collection)
  Dim aAttr As CgAttribute
  
  On Error GoTo Error_Handler
  Set aAttr = New CgAttribute
  aAttr.OnCg = True
  aAttr.Name = AttrName
  aAttr.PackageName = PackageName
  aAttr.dataType = attrType
  aAttr.Access = AttrAccess
  'aAttr.bComposite = True
  coll.Add aAttr
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Attribute '" & AttrName & "' add error: " & err.Description
End Sub

Sub CgLeafInitEsos(SimEsos As Collection, classCgOperations As Collection)
  
  Dim aFcn As CgOperation
  Dim i As Long
  Dim aAttr As CgAttribute
  
  On Error GoTo Error_Handler
  If SimEsos.count > 0 Then
    Set aFcn = New CgOperation
    
    aFcn.OnCg = True
    aFcn.Name = "InitEsos"
    aFcn.Access = "protected"
    aFcn.ReturnType = "HRESULT"
    
    For i = 1 To SimEsos.count
      Set aAttr = SimEsos(i)
      If aAttr.bAggregate Then
        aFcn.AddLine "  ADD_LOCAL_ESO(&" & SimEsos(i).Name & ")"
      Else
        aFcn.AddLine "  ADD_LOCAL_ESO(" & SimEsos(i).Name & ")"
      End If
    Next i
    
    aFcn.AddLine ""
    aFcn.AddLine "  return S_OK;"
    aFcn.CgInit
    
    classCgOperations.Add aFcn
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "InitEsos code generation error: " & err.Description
End Sub

Sub CgLeafVarInit(SimVars As Collection, classCgOperations As Collection, ModelType As Long)
  Dim aFcn As CgOperation
  Dim aVar As CgAttribute
  
  On Error GoTo Error_Handler
  Set aFcn = New CgOperation
  
  aFcn.OnCg = True
  aFcn.Access = "protected"
  aFcn.Name = "InitLocalVars"
  aFcn.ReturnType = "HRESULT"
  
  aFcn.AddPar "prefix", "_TCHAR*", "In"
  aFcn.AddPar "varC", "VarCont", "InOut"
  aFcn.AddPar "bADOnly", "bool", "In"
  
  aFcn.AddLine ""
  
  'Patch: Make sure non scalar vars are last, since may vars are referenced by index
  
  For Each aVar In SimVars
    If aVar.bSim Then
      If aVar.sSubType = idxAttr_Scalar Then
        aFcn.AddLine "  ADD_LOCAL_SVAR(" & aVar.Name & ")"
      End If
    End If
  Next
  
  For Each aVar In SimVars
    If aVar.bSim Then
      If aVar.sType = idxAttr_Struct Then
        aFcn.AddLine "  ADD_LOCAL_CVAR(" & aVar.Name & ")"
      End If
    End If
  Next
    
  For Each aVar In SimVars
    If aVar.bSim Then
      If aVar.sSubType = idxAttr_Array Then
        aFcn.AddLine "  ADD_LOCAL_VVAR(" & aVar.Name & ", " & aVar.dim1 & ")"
      ElseIf aVar.sSubType = idxAttr_Matrix Then
        aFcn.AddLine "  ADD_LOCAL_MVAR(" & aVar.Name & ", " & aVar.dim1 & ", " & aVar.dim2 & ")"
      ElseIf aVar.sSubType = idxAttr_valarray Then
        aFcn.AddLine "  ADD_LOCAL_STLVAR(" & aVar.Name & ")"
      End If
    End If
  Next

  If ModelType <> idxClassType_Structure Then
    aFcn.AddLine ""
    aFcn.AddLine "for (long i = 0; i < m_nEsos; i++)"
    aFcn.AddLine "  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);"
    aFcn.AddLine ""
  Else
    aFcn.AddLine ""
  End If
  
  aFcn.AddLine "  return S_OK;"
  
  aFcn.CgInit
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "InitLocalVars code generation error: " & err.Description
End Sub
  
Sub CgLeafRParInit(SimRPars As Collection, classCgOperations As Collection)

  Dim aFcn As CgOperation
  Dim aPar As CgAttribute
  
  On Error GoTo Error_Handler
  If SimRPars.count = 0 Then Exit Sub
  Set aFcn = New CgOperation
  
  aFcn.OnCg = True
  aFcn.Access = "protected"
  aFcn.Name = "InitLocalRPars"
  aFcn.ReturnType = "HRESULT"

  aFcn.AddPar "prefix", "_TCHAR*", "In"
  aFcn.AddPar "pars", "double**", "InOut"
  aFcn.AddPar "Names", "_TCHAR**", "InOut"
  aFcn.AddPar "nPars", "long", "InOut"
  aFcn.AddPar "dPars", "long", "InOut"
  
  aFcn.AddLine ""
  
  'Patch: Make sure non scalar vars are last, since may vars are referenced by index
  For Each aPar In SimRPars
    If aPar.bSim Then
      If aPar.sType = idxAttr_Struct Then
        aFcn.AddLine "  ADD_LOCAL_CRPAR(" & aPar.Name & ")"
      ElseIf aPar.sSubType = idxAttr_Scalar Then
        aFcn.AddLine "  ADD_LOCAL_SRPAR(" & aPar.Name & ")"
      End If
    End If
  Next
  
  For Each aPar In SimRPars
    If aPar.bSim Then
     If aPar.sSubType = idxAttr_Array Then
        aFcn.AddLine "  ADD_LOCAL_VRPAR(" & aPar.Name & ", " & aPar.dim1 & ")"
      ElseIf aPar.sSubType = idxAttr_Matrix Then
        aFcn.AddLine "  ADD_LOCAL_MRPAR(" & aPar.Name & ", " & aPar.dim1 & ", " & aPar.dim2 & ")"
      End If
    End If
  Next
  
  aFcn.AddLine ""
  aFcn.AddLine "  return S_OK;"

  aFcn.CgInit
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "InitLocalRPars code generation error: " & err.Description
End Sub
  
Sub CgLeafIParInit(SimIPars As Collection, classCgOperations As Collection, ModelType As Long)
  
  Dim aFcn As CgOperation
  Dim aPar As CgAttribute
  
  On Error GoTo Error_Handler
  ' KAB change
  If SimIPars.count = 0 And ModelType <> idxClassType_Structure Then Exit Sub
  Set aFcn = New CgOperation
  
  aFcn.OnCg = True
  aFcn.Access = "protected"
  aFcn.Name = "InitLocalIPars"
  aFcn.ReturnType = "HRESULT"

  aFcn.AddPar "prefix", "_TCHAR*", "In"
  aFcn.AddPar "pars", "long**", "InOut"
  aFcn.AddPar "Names", "_TCHAR**", "InOut"
  aFcn.AddPar "nPars", "long", "InOut"
  aFcn.AddPar "dPars", "long", "InOut"
  
  aFcn.AddLine ""
  
  'Patch: Make sure non scalar vars are last, since may vars are referenced by index
  For Each aPar In SimIPars
    If aPar.bSim Then
      If aPar.sType = idxAttr_Struct Then
        aFcn.AddLine "  ADD_LOCAL_CIPAR(" & aPar.Name & ")"
      ElseIf aPar.sSubType = idxAttr_Scalar Then
        aFcn.AddLine "  ADD_LOCAL_SIPAR(" & aPar.Name & ")"
      End If
    End If
  Next
  
  For Each aPar In SimIPars
    If aPar.bSim Then
      If aPar.sSubType = idxAttr_Array Then
        aFcn.AddLine "  ADD_LOCAL_VIPAR(" & aPar.Name & ", " & aPar.dim1 & ")"
      ElseIf aPar.sSubType = idxAttr_Matrix Then
        aFcn.AddLine "  ADD_LOCAL_MIPAR(" & aPar.Name & ", " & aPar.dim1 & ", " & aPar.dim2 & ")"
      End If
    End If
  Next
  
  aFcn.AddLine ""
  aFcn.AddLine "  return S_OK;"
  aFcn.CgInit
  
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "InitLocalIPars code generation error: " & err.Description
End Sub

Sub CgLeafEqnInit(classOperations As Collection, classCgOperations As Collection)
  Dim bIsAD As Boolean
  
  bIsAD = False
  CreateLeafInitFcn "InitLocalEqns", bIsAD, "", classOperations, classCgOperations
End Sub

Sub CgLeafADEqnInit(classOperations As Collection, classCgOperations As Collection)
  Dim bIsAD As Boolean
  
  bIsAD = True
  CreateLeafInitFcn "InitLocalADEqns", bIsAD, "ad_", classOperations, classCgOperations
End Sub


Sub CreateLeafInitFcn(FcnName As String, bIsAD As Boolean, OperationPrefix As String, ItemColl As Collection, classCgOperations As Collection)
  Dim aFcn As CgOperation
  Dim aOperation As CgOperation
  Dim szClassName As String
  Dim i As Long
  
  On Error GoTo Error_Handler
  If ItemColl.count > 0 Then
    Set aFcn = New CgOperation
    
    aFcn.OnCg = True
    aFcn.Name = FcnName
    aFcn.Access = "protected"
    aFcn.ReturnType = "HRESULT"
    
    For Each aOperation In ItemColl
      szClassName = Replace(aOperation.ClassName, " ", "_")
      If bIsAD Then
        ' TODO: support others in the future
        If aOperation.sSubType = idxOper_Scalar Then
          aFcn.AddLine "  " & "ADD_LOCAL_AD_EQN" & "(" & szClassName & ", " & OperationPrefix & aOperation.Name & ")"
        ElseIf aOperation.sSubType = idxOper_valarray Then
          aFcn.AddLine "  " & "ADD_LOCAL_STL_AD_EQN" & "(" & szClassName & ", " & OperationPrefix & aOperation.Name & ", " & "1" & ")"
        End If
      Else
        If aOperation.sSubType = idxOper_Scalar Then
          aFcn.AddLine "  " & "ADD_LOCAL_EQN" & "(" & szClassName & ", " & OperationPrefix & aOperation.Name & ")"
        ElseIf aOperation.sSubType = idxOper_valarray Then
          aFcn.AddLine "  " & "ADD_LOCAL_STL_EQN" & "(" & szClassName & ", " & OperationPrefix & aOperation.Name & ", " & "1" & ")"
        End If
      End If
    Next
    
    aFcn.AddLine ""
    aFcn.AddLine "  return S_OK;"
    aFcn.CgInit
    
    classCgOperations.Add aFcn
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "'" & FcnName & "' code generation error: " & err.Description
End Sub

Sub CgLeafEqnFormInit(Operations As Collection, coll As Collection)
  
  Dim aFcn As CgOperation
  Dim aOperation As CgOperation
  Dim i As Long
  Dim count As Long
  
  On Error GoTo Error_Handler
  count = 0
  For Each aOperation In Operations
    If aOperation.bSim Then
      count = count + 1
    End If
  Next
  
  If count > 0 Then
    Set aFcn = New CgOperation
    
    aFcn.OnCg = True
    aFcn.Name = "InitEqnForm"
    aFcn.Access = "protected"
    aFcn.ReturnType = "HRESULT"
    
    aFcn.AddPar "form", "OnEqnForm*", "InOut"
    aFcn.AddPar "diff_form", "OnEqnDiffForm*", "InOut"
    
    aFcn.AddLine ""
    For Each aOperation In Operations
      aFcn.AddLine "const long idx_eqn_" & aOperation.Name & " = " & aOperation.idx & ";"
    Next
    
    aFcn.AddLine ""
    aFcn.AddLine "  DESTROY_VECTOR(*form)"
    aFcn.AddLine "  *form = new OnEqnForm[m_nLocalEqns];"
    
    count = 0
    For Each aOperation In Operations
      If aOperation.bSim Then
        If aOperation.sType = idxOper_Continuous Then
          aFcn.AddLine "  (*form)[idx_eqn_" & aOperation.Name & "] = continuous;"
        ElseIf aOperation.sType = idxOper_Discontinuous Then
          aFcn.AddLine "  (*form)[idx_eqn_" & aOperation.Name & "] = discontinuous;"
        ElseIf aOperation.sType = idxOper_Reset Then
          aFcn.AddLine "  (*form)[idx_eqn_" & aOperation.Name & "] = reset;"
        End If
        count = count + 1
      End If
    Next
    
    aFcn.AddLine ""
    aFcn.AddLine "  DESTROY_VECTOR(*diff_form)"
    aFcn.AddLine "  *diff_form = new OnEqnDiffForm[m_nLocalEqns];"
    
    count = 0
    For Each aOperation In Operations
      If aOperation.bSim Then
        If aOperation.sDiffType = idxOperDiff_Automatic Then
          aFcn.AddLine "  (*diff_form)[idx_eqn_" & aOperation.Name & "] = automatic;"
        ElseIf aOperation.sDiffType = idxOperDiff_Numeric Then
          aFcn.AddLine "  (*diff_form)[idx_eqn_" & aOperation.Name & "] = numeric;"
        End If
        count = count + 1
      End If
    Next
    
    aFcn.AddLine ""
    aFcn.AddLine "  return S_OK;"
    aFcn.CgInit
    
    coll.Add aFcn
    
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "InitEqnForm code generation error: " & err.Description
End Sub

Public Sub CgLeafTransitionInit(SimEqns As Collection, aClass As rtsClass, classCgOperations As Collection)
  Dim aState As CgState
  Dim aTransition As CgTransition
  Dim aFcn As CgOperation
  Dim aTrigger As CgTrigger
  Dim aCondition As CgTriggerCondition
  Dim tcol As Collection
  Dim aOperation As CgOperation
  Dim aItem As CgItem
  
  On Error GoTo Error_Handler
  Set aFcn = New CgOperation
  
  aFcn.OnCg = True
  aFcn.Name = "InitTransitions"
  aFcn.Access = "protected"
  aFcn.ReturnType = "HRESULT"
  
  aFcn.AddLine "HRESULT hr;"
  aFcn.AddLine "HRESULT hrRet = S_OK;" & vbCrLf
  aFcn.AddLine ""
  
  aFcn.AddLine "// equation constants"
  For Each aOperation In SimEqns
    aFcn.AddLine "const long idx_eqn_" & aOperation.Name & " = " & aOperation.idx & ";"
  Next
  
  aFcn.AddLine ""
  aFcn.AddLine "// state constants"
  For Each aState In aClass.States
    aFcn.AddLine "const long idx_state_" & aState.Name & " = " & aState.idx & ";"
  Next
  
  aFcn.AddLine ""
  On Error Resume Next
  For Each aTransition In aClass.Transitions
    ' determine equations used by this transition
    aTransition.Name = adg.ReplacePat(aTransition.Name, "[\[\]\{\}\- \(\)\+\-\*\/\=]", "")
    
    Set tcol = New Collection
    For Each aItem In aTransition.ResetEqns
      Set aOperation = SimEqns(aItem.Name)
      If err = 0 Then
        tcol.Add aOperation
      End If
    Next
    
    For Each aTrigger In aTransition.Triggers
      For Each aCondition In aTrigger.Conditions
        If Not aCondition.Eqn Is Nothing Then
          tcol.Add aCondition.Eqn, aCondition.Eqn.Name
        End If
      Next
    Next
    aTransition.count = tcol.count
    
    aFcn.AddLine "const long idx_eqns_" & aTransition.Name & "[] = { "
    For Each aOperation In tcol
      aFcn.AddLine "  idx_eqn_" & aOperation.Name & ","
    Next
    aFcn.AddLine " };"
  Next
  On Error GoTo 0
  
  
  aFcn.AddLine ""
  aFcn.AddLine "// Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count"
  For Each aTransition In aClass.Transitions
    aFcn.AddLine "hr = AddTransition(L""" & aTransition.Name & """, idx_state_" & aTransition.SourceState & _
                         ", L""" & aTransition.EventName & """, idx_eqns_" & aTransition.Name & _
                         ", " & aTransition.count & ");"
    aFcn.AddLine "if (FAILED(hr)) hrRet = hr;"
  Next
  
  aFcn.AddLine ""
  
  aFcn.AddLine "return hrRet;"
  aFcn.CgInit
    
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "InitTransitions code generation error: " & err.Description
End Sub

Public Sub CgLeafStateInit(SimEqns As Collection, States As Collection, classCgOperations As Collection)
  Dim aState As CgState
  Dim aFcn As CgOperation
  Dim aOperation As CgOperation
  Dim aItem As CgItem
  
  On Error GoTo Error_Handler
  Set aFcn = New CgOperation
  
  aFcn.OnCg = True
  aFcn.Name = "InitStates"
  aFcn.Access = "protected"
  aFcn.ReturnType = "HRESULT"
  
  aFcn.AddLine "HRESULT hr;"
  aFcn.AddLine "HRESULT hrRet = S_OK;"
  
  aFcn.AddLine ""
  aFcn.AddLine "// equation constants"
  For Each aOperation In SimEqns
    aFcn.AddLine "const long idx_eqn_" & aOperation.Name & " = " & aOperation.idx & ";"
  Next
  
  aFcn.AddLine ""
  aFcn.AddLine "// state constants"
  For Each aState In States
    aFcn.AddLine "const long idx_state_" & aState.Name & " = " & aState.idx & ";"
  Next
  
  aFcn.AddLine ""
  For Each aState In States
    aFcn.AddLine "const long idx_eqns_" & aState.Name & "[] = { "
    For Each aItem In aState.Eqns
      aFcn.AddLine "  idx_eqn_" & aItem.Name & ","
    Next
    aFcn.AddLine " };"
  Next
  On Error GoTo 0
  
  aFcn.AddLine ""
  For Each aState In States
    aFcn.AddLine "hr = AddState(L""" & aState.Name & """, " & _
      IIf(aState.IsDefault, 1, 0) & ", idx_eqns_" & aState.Name & ", " & aState.Eqns.count & ");"
    aFcn.AddLine "if (FAILED(hr)) hrRet = hr;"
  Next
  
  aFcn.AddLine ""
  aFcn.AddLine vbCrLf & "return hrRet;"
  aFcn.CgInit
    
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "InitStates code generation error: " & err.Description
End Sub

Public Sub CgLeafOnTransition(ClassName As String, States As Collection, classCgOperations As Collection)
  Dim aFcn As CgOperation
  Dim aState As CgState
  Dim szClassName As String
  Dim szStateName As String
  
  On Error GoTo Error_Handler
  Set aFcn = New CgOperation
  aFcn.OnCg = True
  aFcn.Access = "protected"
  aFcn.Name = "OnTransition"
  aFcn.ReturnType = "HRESULT"
  
  aFcn.AddLine "HRESULT hr = S_OK;"
  
  aFcn.AddLine ""
  For Each aState In States
    szStateName = Replace(aState.Name, " ", "_")
    aFcn.AddLine "const long idx_state_" & szStateName & " = " & aState.idx & ";"
  Next
    
#If using_ilogix Then
  aFcn.AddLine "switch ( rootState_active )"
  aFcn.AddLine "{"
  For Each aState In States
    szStateName = Replace(aState.Name, " ", "_")
    aFcn.AddLine "  case " & szStateName & ":"
    aFcn.AddLine "    ATLTRACE(" & Chr(34) & "\n" & szStateName & Chr(34) & ");"
    aFcn.AddLine "    PostTransition(idx_state_" & szStateName & ");"
    aFcn.AddLine "    break;"
  Next
  aFcn.AddLine "}"

#End If
  aFcn.AddLine ""
  aFcn.AddLine "return hr;"
  
  aFcn.CgInit
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "OnTransition code generation error: " & err.Description
End Sub

Public Sub CgLeafTriggerEvent(Transitions As Collection, SimVars As Collection, classCgOperations As Collection)

  Dim aFcn As CgOperation
  Dim aTrans As CgTransition
  Dim szElse As String
  Dim aVar As CgAttribute
  Dim szEventType As String
  Dim count As Long
  
  On Error GoTo Error_Handler
  For Each aTrans In Transitions
    count = count + aTrans.Triggers.count
  Next
  If count = 0 Then Exit Sub
  
  Set aFcn = New CgOperation
  
  aFcn.OnCg = True
  aFcn.Name = "TriggerEvent"
  aFcn.Access = "protected"
  aFcn.ReturnType = "HRESULT"
  
  aFcn.AddPar "EventTime", "double", "In"
  aFcn.AddPar "bstrEventId", "BSTR", "In"
  
  aFcn.AddLine "USES_CONVERSION;"
  aFcn.AddLine ""
  aFcn.AddLine "CComBSTR EventId = bstrEventId;"
  aFcn.AddLine "HRESULT hr = S_OK;"
  aFcn.AddLine ""

#If using_ilogix Then
  szElse = ""
  For Each aTrans In Transitions
    aFcn.AddLine szElse & "if (EventId == L""" & aTrans.EventName & """)"
    aFcn.AddLine "{"
    aFcn.AddLine "  " & aTrans.EventName & " ev;"
    aFcn.AddLine "  " & "takeTrigger(&ev);"
    aFcn.AddLine "}"
    szElse = "else "
  Next
#End If

  aFcn.AddLine ""
  aFcn.AddLine "m_time = EventTime;"
  
  aFcn.AddLine vbCrLf & "// update old variables"
  For Each aVar In SimVars
    If aVar.bSim Then
      If aVar.sSubType = idxAttr_Scalar Then
        aFcn.AddLine "S_OLD(" & aVar.Name & ") = " & aVar.Name & ";"
      ElseIf aVar.sSubType = idxAttr_valarray Then
        aFcn.AddLine "OLD(" & aVar.Name & ") = " & aVar.Name & ";"
      End If
    End If
  Next
    
  aFcn.AddLine ""
  aFcn.AddLine "return S_OK;"
    
  aFcn.CgInit
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "TriggerEvent code generation error: " & err.Description
End Sub


Public Sub CgLeafEvalStateCondition(aClass As rtsClass, classCgOperations As Collection)
  Dim aOp As CgOperation
  Dim aState As CgState
  Dim aTransition As CgTransition
  Dim aTrigger As CgTrigger
  Dim i As Long
  Dim szOr As String
  Dim szLine As String
  
  Dim aFcn As CgOperation
  Dim aLine As CgItem
  Dim aParam As CgAttribute
  Dim aVar As CgItem
  Dim aCondition As CgTriggerCondition
  Dim iTransition As Long
  Dim iTrigger As Long
  Dim iCondition As Long
  Dim count As Long
  Dim ClassName As String
  
  On Error GoTo Error_Handler
  ClassName = aClass.Name
  
  For Each aTransition In aClass.Transitions
    count = count + aTransition.Triggers.count
  Next
  If count = 0 Then Exit Sub
  
  Set aFcn = New CgOperation
  
  aFcn.OnCg = True
  aFcn.Name = "EvalStateCondition"
  aFcn.Access = "protected"
  aFcn.ReturnType = "HRESULT"
  
  aFcn.AddPar "EqnState", "bool*", "In"
  aFcn.AddPar "x", "double*", "In"
  aFcn.AddPar "xdot", "double*", "In"
  aFcn.AddPar "EventTime", "double", "In"
  aFcn.AddPar "iDisEqn", "long", "In"
  aFcn.AddPar "iTransition", "long", "In"
  aFcn.AddPar "bEvent", "bool", "InOut"
  
  aFcn.AddLine ""
  For Each aState In aClass.States
    aFcn.AddLine "const long idx_state_" & LTrim(RTrim(aState.Name)) & " = " & aState.idx & ";"
  Next
  aFcn.AddLine ""
  
  i = 0
  For Each aTransition In aClass.Transitions
    aFcn.AddLine "const long idx_transition_" & LTrim(RTrim(aTransition.Name)) & " = " & i & ";"
    i = i + 1
  Next
  
  aFcn.AddLine ""
  For Each aOp In aClass.Operations
    If aOp.sType = idxOper_Discontinuous Or aOp.sType = idxOper_Reset Then
      aFcn.AddLine "const long idx_eqn_" & aOp.Name & " = " & aOp.idx & ";"
    End If
  Next
  
  Dim szClassName As String
  Dim szStateName As String
   
  #If using_ilogix Then
  ' determine current state
  aFcn.AddLine "long currentState = 0;"
  aFcn.AddLine "switch (rootState_active)"
  aFcn.AddLine "{"
  For Each aState In aClass.States
    szStateName = Replace(aState.Name, " ", "_")
    aFcn.AddLine "  case " & szStateName & ":"
    aFcn.AddLine "    currentState = idx_state_" & szStateName & ";"
    aFcn.AddLine "    break;"
  Next
  aFcn.AddLine "}"
  #End If
    
  aFcn.AddLine ""
  aFcn.AddLine "*bEvent = false;"
  aFcn.AddLine "switch (currentState)"
  aFcn.AddLine "{"
         
  For Each aState In aClass.States
    aFcn.AddLine "case idx_state_" & aState.Name & ":"
    iTransition = 1
    For Each aTransition In aClass.Transitions
      If aTransition.SourceState = aState.Name And aTransition.Triggers.count > 0 Then
        aFcn.AddLine "  " & IIf(iTransition > 1, "else ", "") & "if (iTransition == idx_transition_" & LTrim(RTrim(aTransition.Name)) & ")"
        szLine = ""
        szLine = "    *bEvent = "
        iTrigger = 1
        For Each aTrigger In aTransition.Triggers
          iCondition = 1
          szLine = szLine & "("
          For Each aCondition In aTrigger.Conditions
            If Not aCondition.Eqn Is Nothing Then
              szLine = szLine & "EqnState[idx_eqn_" & aCondition.Eqn.Name & "]" & _
                IIf(iCondition < aTrigger.Conditions.count, " && ", "")
              iCondition = iCondition + 1
            End If
          Next
          szLine = szLine & ")"
          
          If iTrigger < aTransition.Triggers.count Then
            szLine = szLine & " || "
          Else
            szLine = szLine & ";"
          End If
          iTrigger = iTrigger + 1
        Next
        aFcn.AddLine szLine
        iTransition = iTransition + 1
      End If
    Next
    aFcn.AddLine "    break;"
  Next
     
  aFcn.AddLine ""
  aFcn.AddLine "}"
      
  aFcn.AddLine "  return S_OK;"
  aFcn.CgInit
  classCgOperations.Add aFcn
  
  #If 0 Then
    Debug.Print aFcn.Body
  #End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "EvalStateCondition code generation error: " & err.Description
End Sub

Public Sub CgLeafCreateADFcns(simClass As rtsClass, classCgOperations As Collection)
  Dim srcEqn As CgOperation
  Dim aEqn As CgOperation
  Dim szBody As String
  Dim typeDefs As Collection
  Dim aType As CgType
  Dim Classes As Collection
  
  Set Classes = simClass.Project.Packages(simClass.PackageName).Classes
  Call GetTypeDefs(simClass, typeDefs)
  
  
  On Error GoTo Error_Handler
  For Each srcEqn In simClass.Operations
    If srcEqn.bSim Then
      If srcEqn.ClassName = simClass.Name Then
        Set aEqn = New CgOperation
        aEqn.OnCg = True
        aEqn.bAutoDiff = True
        aEqn.Name = "ad_" & srcEqn.Name
        aEqn.ReturnType = "HRESULT"
        aEqn.Access = "protected"
        If srcEqn.sSubType = idxOper_Scalar Then
          aEqn.AddPar "res", "Fdouble", "InOut"
        ElseIf srcEqn.sSubType = idxOper_valarray Then
          aEqn.AddPar "res", "valarray<Fdouble>", "InOut"
        End If
        
        szBody = vbCrLf & srcEqn.Body & vbCrLf
        If srcEqn.sDiffType = idxOperDiff_Numeric Then
          szBody = "return S_OK; // placeholder"
        Else
          
          ' replace OnStlVec types with valarray<Fdouble>
          'Debug.Print szBody & vbCrLf & "==========================================" & vbCrLf
          szBody = adg.ReplaceStr(szBody, "OnStlVec<double>", "[^a-zA-Z_0-9.>]{1}" & "OnStlVec<double>" & "[^a-zA-Z_0-9]", "valarray<Fdouble>")
          
          For Each aType In typeDefs
            If aType.IsTypeOf("OnStlVec") Then
              'Debug.Print "============================================="
              'Debug.Print "begin: " & aType.Name & vbCrLf & szBody
              szBody = adg.ReplaceStr(szBody, aType.Name, "[^a-zA-Z_0-9.>]{1}" & aType.Name & "[^a-zA-Z_0-9]", "valarray<Fdouble>")
              'Debug.Print "============================================="
              'Debug.Print "end: " & aType.Name & vbCrLf & szBody
            End If
          Next
          
          ' replace double with Fdouble
          'Debug.Print "Before replacing double with Fdouble" & vbCrLf
          'Debug.Print szBody
          szBody = adg.ReplaceStr(szBody, "double", "[^a-zA-Z_0-9.>]{1}" & "double" & "[^a-zA-Z_0-9]", "Fdouble")
          'Debug.Print "After replacing double with Fdouble" & vbCrLf
          'Debug.Print szBody
          
          
          GetADEqnBody "[^a-zA-Z_0-9.>]{1}", szBody, simClass, Classes, typeDefs    ' "[^a-zA-Z_0-9.>]{0,1}"
          'Debug.Print szBody
          
          ' This requires at least one preceding char that is not alpha-numeric, underscore, dot, or gt
          ' It will fail to match if no preceding chars are present.
        End If
        
        aEqn.Body = szBody
        classCgOperations.Add aEqn
      End If
    End If
  Next
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "CreateADFcns code generation error: " & err.Description
End Sub

Public Sub GetADEqnBody(szPatternPrefix As String, szBody As String, aInfo As rtsClass, Classes As Collection, typeDefs As Collection)
  Dim aVar As CgAttribute
  Dim szName As String
  Dim searchInfo As rtsClass
  Dim szDataType As String
  ' KAB Added package name declaration
  Dim szPackageName As String
  Dim iCur As Long
  
  
  On Error GoTo Error_Handler
  For Each aVar In aInfo.Attributes
    If aVar.bSim And (aVar.sType = idxAttr_Variable Or aVar.sType = idxAttr_Model Or aVar.sType = idxAttr_Connector Or aVar.sType = idxAttr_Struct) Then
      szName = aVar.Name
      If aVar.dataType = "double" Then
        szBody = adg.ReplaceStr(szBody, szName, szPatternPrefix & szName & "[^a-zA-Z_0-9]", "S_AD(" & szName & ")")
        szBody = adg.ReplaceStr(szBody, "DER(" & szName & ")", szPatternPrefix & "DER\([ ]{0,1}" & szName & "[^a-zA-Z_0-9]", "S_DER_AD(" & szName & ")")
        ' remove ad_ from any fabs() functions which are commonly used for determining direction
        szBody = adg.ReplaceStr(szBody, "S_AD(" & szName & ")", "fabs\([ ]{0,1}S_AD\(" & szName, szName)
        ' remove ad_ from any OLD() values which are commonly used for determining direction
        szBody = adg.ReplaceStr(szBody, "S_AD(" & szName & ")", "OLD\([ ]{0,1}S_AD\(" & szName, szName)
        ' replace DER(AD(szName)) with DER_AD(szName)
        szBody = Replace(szBody, "DER(S_AD(" & szName & "))", "DER_AD(" & szName & ")")
        ' replace DER(OLD(szName)) with DER_OLD(szName)
        szBody = Replace(szBody, "DER(OLD(" & szName & "))", "DER_OLD(" & szName & ")")
      ElseIf aVar.IsTypeOf("OnStlVec", Classes, typeDefs) Then
        'Debug.Print szBody
        szBody = adg.ReplaceStr(szBody, szName, szPatternPrefix & szName & "[^a-zA-Z_0-9]", "AD(" & szName & ")")
        szBody = adg.ReplaceStr(szBody, "DER(" & szName & ")", szPatternPrefix & "DER\([ ]{0,1}" & szName & "[^a-zA-Z_0-9]", "DER_AD(" & szName & ")")
        ' remove ad_ from any fabs() functions which are commonly used for determining direction
        szBody = adg.ReplaceStr(szBody, "AD(" & szName & ")", "fabs\([ ]{0,1}AD\(" & szName, szName)
        ' remove ad_ from any OLD() values which are commonly used for determining direction
        szBody = adg.ReplaceStr(szBody, "AD(" & szName & ")", "OLD\([ ]{0,1}AD\(" & szName, szName)
        ' replace DER(AD(szName)) with DER_AD(szName)
        szBody = Replace(szBody, "DER(AD(" & szName & "))", "DER_AD(" & szName & ")")
        ' replace DER(OLD(szName)) with DER_OLD(szName)
        szBody = Replace(szBody, "DER(OLD(" & szName & "))", "DER_OLD(" & szName & ")")
        'Debug.Print szBody
      Else
        On Error Resume Next
        Set searchInfo = Nothing
        Set searchInfo = infos(szName)
        If err <> 0 Then
          szDataType = aVar.dataType
          ' KAB added retrieval of package name from variable
          szPackageName = aVar.PackageName
          iCur = InStr(1, szDataType, "*")
          If iCur > 0 Then
            szDataType = LTrim(RTrim(Left(szDataType, iCur - 1)))
          End If
          On Error GoTo 0
          ' KAB passing variables package name, rather than the source classes package name.
          If GetClassInfo(aInfo.Project, szPackageName, szDataType, searchInfo) Then
            infos.Add searchInfo, szName
          End If
        End If
        On Error GoTo 0
        
        If Not searchInfo Is Nothing Then
          'GetADEqnBody szPatternPrefix & szName & "[.\->]{1,2}", szBody, searchInfo
          GetADEqnBody szPatternPrefix & szName & "(.|\->)", szBody, searchInfo, Classes, typeDefs
        End If
      End If
    End If
  Next
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "ADEqnBody code generation error: " & err.Description
End Sub
Public Sub CgLeafSaveFcn(classOperations As Collection, classCgOperations As Collection)
  
  Dim aFcn As CgOperation
  
  On Error Resume Next
  Set aFcn = classOperations("Save")
  If err <> 0 Then
    ' Load operation doesn't exist
    On Error GoTo 0
  
    Set aFcn = New CgOperation
    aFcn.Access = "public"
    aFcn.Name = "Save"
    aFcn.ReturnType = "void"
    aFcn.AddPar "fs", "FILE", "InOut"
    
    aFcn.CgInit
    classCgOperations.Add aFcn
  End If
End Sub
  
Public Sub CgLeafLoadFcn(classOperations As Collection, classCgOperations As Collection)
  
  Dim aFcn As CgOperation
  
  On Error Resume Next
  Set aFcn = classOperations("Load")
  If err <> 0 Then
    ' Load operation doesn't exist
    On Error GoTo 0
    Set aFcn = New CgOperation
    aFcn.Access = "public"
    aFcn.Name = "Load"
    aFcn.ReturnType = "bool"
    aFcn.AddPar "fs", "FILE", "InOut"
    
    aFcn.AddLine "return true;"
    aFcn.CgInit
    classCgOperations.Add aFcn
  End If
  
End Sub











