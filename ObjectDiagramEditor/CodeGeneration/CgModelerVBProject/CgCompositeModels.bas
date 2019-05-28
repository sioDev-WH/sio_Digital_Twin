Attribute VB_Name = "CgCompositeModels"
Option Explicit

Public Function GetCompositeClassOperations(theProject As rtsProject, UDIs As Collection, aUDIDefMgr As UDIDefMgr)
  Dim aUDI As UserDefinedItem
  Dim aFcn As CgOperation
  Dim PackageName As String
  Dim ClassName As String
  Dim aUDIDef As UserDefinedItemDef
  Dim aPackage As rtsPackage
  Dim aClass As rtsClass
  Dim classOperations As Collection
  
  On Error Resume Next
  For Each aUDI In UDIs
    Set aUDIDef = Nothing
    Set aUDIDef = aUDIDefMgr.GetUDIDefbyObjectName(aUDI.m_strDefObjectName)
    If Not aUDIDef Is Nothing Then
      PackageName = aUDIDef.PackageName
      ClassName = aUDIDef.ClassName
      Set aPackage = theProject.Packages(PackageName)
      If Not aPackage Is Nothing Then
        Set aClass = aPackage.Classes(ClassName)
        If Not aClass Is Nothing Then
          If aClass.ModelType = idxClassType_Model Then
            Call GetClassInfo(theProject, PackageName, ClassName, aClass)
            Set aUDI.m_Info = aClass
          End If
        End If
      End If
    End If
  Next aUDI

End Function

Public Function GetCompositeCgObjects(CompositeClassName As String, aProject As rtsProject, UDIs As Collection, aUDIDefMgr As UDIDefMgr, ConnInfo As Collection, ClassCgAttributes As Collection, classCgOperations As Collection, objList() As String, opList() As String, OpCount As Long) As Boolean
  Dim aUDI As UserDefinedItem
  Dim aInfo As rtsClass
  Dim shortListUDIs As Collection
  Dim i As Long
  Dim j As Long
  Dim aFcn As CgOperation
  Dim aSrcFcn As CgOperation
  Dim PackageName As String
  Dim ClassName As String
  Dim bSuccess As Boolean
  Dim aUDIDef As UserDefinedItemDef
  Dim infos As Collection
  Dim aPar As CgAttribute
  
  On Error Resume Next
  If ClassCgAttributes Is Nothing Then
    Set ClassCgAttributes = New Collection
  End If
  
  If classCgOperations Is Nothing Then
    Set classCgOperations = New Collection
  End If
  
  Set infos = New Collection
  
  For Each aUDI In UDIs
    Set aUDIDef = Nothing
    Set aUDIDef = aUDIDefMgr.GetUDIDefbyObjectName(aUDI.m_strDefObjectName)
    If aUDIDef Is Nothing Then
      gMsgWnd.LogMessage "Mask for object '" & aUDI.ObjectName & "' not found.  Generation aborted.  Update mask definitions."
      Exit Function
    Else
      PackageName = aUDIDef.PackageName
      ClassName = aUDIDef.ClassName
      ClassName = LTrim(RTrim(ClassName))
      ClassName = Replace(ClassName, " ", "_")
      
      aUDI.PackageName = PackageName
      aUDI.ClassName = ClassName
  
      Set aInfo = infos(ClassName)
      If err <> 0 Then
        If GetClassInfo(aProject, PackageName, ClassName, aInfo) Then
          infos.Add aInfo, aInfo.Name
        Else
          gMsgWnd.LogMessage "Class '" & ClassName & "' not found in package '" & PackageName & "'.  Generation aborted.  Update mask definitions."
          Exit Function
        End If
      End If
    End If
  Next aUDI
  On Error GoTo 0
  
  ' generate the wrapper methods for exposing child methods
  If OpCount > 0 Then
    For Each aUDI In UDIs
      For i = 0 To OpCount - 1
        If aUDI.ObjectName = objList(i) Then
          Set aSrcFcn = aUDI.m_Info.Operations(opList(i))
          Set aFcn = New CgOperation
          Call aSrcFcn.Copy(aFcn)
          aFcn.OnCg = True
          aFcn.Name = aUDI.ObjectName & "_" & aSrcFcn.Name
          aFcn.Body = "  " & aUDI.ObjectName & "->" & aSrcFcn.Name & "("
          j = 1
          For Each aPar In aFcn.Parameters
            aFcn.Body = aFcn.Body & IIf(j > 1, ", ", "") & aPar.Name
            j = j + 1
          Next
          aFcn.Body = aFcn.Body & ");"
          classCgOperations.Add aFcn
        End If
      Next i
    Next
  End If
  
  
  
  i = 0
  Set shortListUDIs = New Collection
  For Each aUDI In UDIs
    err = 0
    ClassName = LTrim(RTrim(aUDI.ClassName))
    ClassName = Replace(ClassName, " ", "_")
   
    Set aInfo = infos(ClassName)
    If err = 0 Then
      If aInfo.ModelType = idxClassType_Model Then
        aUDI.m_index = i
        shortListUDIs.Add aUDI, aUDI.ObjectName
        Set aUDI.m_Info = aInfo
        i = i + 1
      End If
    End If
  Next
  
  On Error GoTo 0
  
  ' constructor
  Set aFcn = New CgOperation
  aFcn.Name = CompositeClassName
  aFcn.Access = "public"
  aFcn.bConstructor = True
  aFcn.AddLine "init();"
  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn
  
  ' destructor
  Set aFcn = New CgOperation
  aFcn.Name = "~" & CompositeClassName
  aFcn.Access = "public"
  aFcn.bDestructor = True
  aFcn.AddLine "clean();"
  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn
  
  CgCompositeInitFcn shortListUDIs, ClassCgAttributes, classCgOperations
  CgCompositeCleanFcn shortListUDIs, classCgOperations
  
  CgCompositeSaveFcn shortListUDIs, classCgOperations
  CgCompositeLoadFcn shortListUDIs, classCgOperations
  
  bSuccess = CgCompositeGetAssociations(shortListUDIs, aUDIDefMgr, ConnInfo, classCgOperations)
  If Not bSuccess Then
    GetCompositeCgObjects = False
    Exit Function
  End If
  ' init Esos
  Set aFcn = New CgOperation
  aFcn.Name = "InitEsos"
  aFcn.Access = "protected"
  aFcn.ReturnType = "HRESULT"
  Dim szMemberName As String
  
  For Each aUDI In shortListUDIs
    szMemberName = aUDI.ObjectName
    szMemberName = Replace(szMemberName, " ", "_")
    aFcn.AddLine "  ADD_LOCAL_ESO(" & szMemberName & ")"
  Next
  aFcn.AddLine ""
  aFcn.AddLine "  return S_OK;"
  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn
  
  ' cleanup
  Set infos = Nothing
  For Each aUDI In UDIs
    Set aUDI.m_Info = Nothing
  Next
  
  GetCompositeCgObjects = True
End Function


Public Function CgCompositeGetAssociations(shortListUDIs As Collection, aUDIDefMgr As UDIDefMgr, ConnInfo As Collection, classCgOperations As Collection) As Boolean
  Dim i As Long
  Dim aUDI As UserDefinedItem
  Dim aAttr As CgAttribute
  Dim aFcn As CgOperation
  Dim aProperty As CgAttribute
  Dim aConn As ConnectionInfo
  Dim aUDIDef As UserDefinedItemDef
  
  Dim startModel As Long
  Dim startConn As Long
  Dim startItemType As Long
  Dim startItemName As String
  Dim startAttrType As Long
  Dim startOperType As Long
  Dim idxStartConn As Long
  
  Dim endModel As Long
  Dim endConn As Long
  Dim endItemType As Long
  Dim endItemName As String
  Dim endAttrType As Long
  Dim endOperType As Long
  Dim idxEndConn As Long
  Dim bNoUDIDef As Boolean
  
  Dim countOfConnections As Long
  Dim iWarnings As Integer
  Dim aConnDef As CgConnectionDef
  Dim connNameA As String
  Dim connNameB As String
  Dim loc As Long
  
  On Error GoTo Error_Handler
  
  Set aFcn = New CgOperation
  aFcn.Access = "protected"
  aFcn.Name = "GetAssociations"
  aFcn.OnCg = True
  aFcn.ReturnType = "HRESULT"
  aFcn.AddPar "Assoc", "long*", "InOut"
  aFcn.AddPar "Size", "long*", "InOut"
  aFcn.AddPar "nSize", "long", "InOut"
  
  aFcn.AddLine "long nAssoc;"
  aFcn.AddLine "long i;"
  aFcn.AddLine ""
  
  aFcn.AddLine "const long assoc[] ="
  aFcn.AddLine "{"
  
  countOfConnections = 0
  iWarnings = 0
  For Each aConn In ConnInfo
    bNoUDIDef = False
    startModel = aConn.ObjA.m_index
    endModel = aConn.ObjB.m_index
      
    Set aUDI = aConn.ObjA
    ' KAB the following patch should be removed
    'If Len(aUDI.m_strDefObjectName) = 0 Then aUDI.m_strDefObjectName = aUDI.ObjectName
    Set aUDIDef = aUDIDefMgr.GetUDIDefbyObjectName(aUDI.m_strDefObjectName)
    
    If aUDIDef Is Nothing Then
        bNoUDIDef = True
        iWarnings = iWarnings + 1
        gMsgWnd.LogMessage "Warning: Shape " & aUDI.m_strDefObjectName & " referenced by connection '" & aConn.NameA & "' does not exist."
    Else
        connNameA = aConn.NameA
        For Each aConnDef In aUDIDef.CgConnectionDefs
          If aConnDef.connName = connNameA Then
            startItemType = aConnDef.itemType
            startItemName = aConnDef.itemName
            startAttrType = aConnDef.attrType
            startOperType = aConnDef.operType
            Exit For
          End If
        Next
    End If
        
    Set aUDI = aConn.ObjB
    ' KAB this patch should be removed
    'If Len(aUDI.m_strDefObjectName) = 0 Then aUDI.m_strDefObjectName = aUDI.ObjectName
    Set aUDIDef = aUDIDefMgr.GetUDIDefbyObjectName(aUDI.m_strDefObjectName)
    
    If aUDIDef Is Nothing Then
        bNoUDIDef = True
        iWarnings = iWarnings + 1
        gMsgWnd.LogMessage "Warning: Shape " & aUDI.m_strDefObjectName & " referenced by connection '" & aConn.NameB & "' does not exist."
    Else
        connNameB = aConn.NameB
        For Each aConnDef In aUDIDef.CgConnectionDefs
          If aConnDef.connName = connNameB Then
            endItemType = aConnDef.itemType
            endItemName = aConnDef.itemName
            endAttrType = aConnDef.attrType
            endOperType = aConnDef.operType
            Exit For
          End If
        Next
    End If
    
    If Not bNoUDIDef Then
        ' see if both ends are connectors (all we are interested in at the moment)
        If startItemType = idxItemType_Attribute And startAttrType = idxAttr_Connector And _
          endItemType = idxItemType_Attribute And endAttrType = idxAttr_Connector Then
        
          ' determine the index of the entry the connector would have in InitEsos()
          Set aUDI = aConn.ObjA
          idxStartConn = -1
          For Each aAttr In aUDI.m_Info.Attributes
            If aAttr.Name = startItemName Then
              idxStartConn = aAttr.Index
              Exit For
            End If
          Next
    
          Set aUDI = aConn.ObjB
          idxEndConn = -1
          For Each aAttr In aUDI.m_Info.Attributes
            If aAttr.Name = endItemName Then
              idxEndConn = aAttr.Index
              Exit For
            End If
          Next
        
          If idxStartConn >= 0 And idxEndConn >= 0 Then
            ' have a complete connection
            aFcn.AddLine "  " & startModel & ", " & idxStartConn & ", " & endModel & ", " & idxEndConn & "," & _
                         vbTab & vbTab & "//" & aConn.ObjA.ObjectName & "." & connNameA & " <==> " & aConn.ObjB.ObjectName & "." & connNameB
            countOfConnections = countOfConnections + 1
          End If
        End If
    End If
  Next
  
  aFcn.AddLine "};"
  aFcn.AddLine ""
  
  If iWarnings > 0 Then
      Dim Response As Integer
      Dim msg As String
      msg = "Potential mismatches have been detected in the connections.  Continue with code generation?"
      Response = MsgBox(msg, vbYesNo, PROJECT_TITLE)
      If Response = vbNo Then
        CgCompositeGetAssociations = False
        Exit Function
      End If
  End If
  
  ' the following assumes that all connections are between objects at the same level in the hierarchy
  aFcn.AddLine "const long size[] ="
  aFcn.AddLine "{"
  For i = 1 To countOfConnections
    aFcn.AddLine "  2, 2,"
  Next
  aFcn.AddLine "};"
 
  aFcn.AddLine ""
  aFcn.AddLine "*nSize = sizeof(size) / sizeof(long);"
  aFcn.AddLine "nAssoc = sizeof(assoc) / sizeof(long);"
  aFcn.AddLine ""
  aFcn.AddLine "*Size = new long[*nSize];"
  aFcn.AddLine "*Assoc = new long[nAssoc];"
  aFcn.AddLine ""
  aFcn.AddLine "for (i = 0; i < *nSize; i++) (*Size)[i] = size[i];"
  aFcn.AddLine "for (i = 0; i < nAssoc; i++) (*Assoc)[i] = assoc[i];"
  aFcn.AddLine ""
  aFcn.AddLine "return S_OK;"

  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn

  CgCompositeGetAssociations = True
  Exit Function
  
Error_Handler:
  CgCompositeGetAssociations = False
  gMsgWnd.LogMessage "Errors detected while determining connection graph: " & err.Number & ", " & err.Description
End Function

Sub CgCompositeInitEsos(SimEsos As Collection, classCgOperations As Collection)
  
  Dim aFcn As CgOperation
  Dim i As Long
  
  If SimEsos.count > 0 Then
    Set aFcn = New CgOperation
    
    aFcn.Name = "InitEsos"
    aFcn.Access = "protected"
    aFcn.ReturnType = "HRESULT"
    
    For i = 1 To SimEsos.count
      aFcn.AddLine "  ADD_LOCAL_ESO(" & SimEsos(i).Name & ")"
    Next i
    
    aFcn.AddLine ""
    aFcn.AddLine "  return S_OK;"
    aFcn.OnCg = True
    aFcn.CgInit
    
    classCgOperations.Add aFcn
    
  End If
  
End Sub

Public Sub CgCompositeInitFcn(shortListUDIs As Collection, ClassCgAttributes As Collection, classCgOperations As Collection)
  Dim aUDI As UserDefinedItem
  Dim aAttr As CgAttribute
  Dim aFcn As CgOperation
  Dim aProperty As CgAttribute
  Dim szValue As String
  Dim ic As Long
  Dim bArray, bMatrix As Boolean
  
  On Error GoTo Error_Handler
  Set aFcn = New CgOperation
  aFcn.Access = "protected"
  aFcn.Name = "init"
  aFcn.ReturnType = "void"
  
  aFcn.AddLine ""
  
  For Each aUDI In shortListUDIs
    Set aAttr = New CgAttribute
    aAttr.bAggregate = True
    aAttr.Access = "public"
    
    #If using_ilogix Then
      aAttr.dataType = Replace(aUDI.ClassName, " ", "_")
    #End If
    
    aAttr.PackageName = aUDI.PackageName
    aAttr.sType = idxAttr_Model
    aAttr.bSim = True
    aAttr.Name = Replace(aUDI.ObjectName, " ", "_")
    aAttr.DefaultValue = "NULL"
    aAttr.OnCg = True
    ClassCgAttributes.Add aAttr, aAttr.Name
    
    aFcn.AddLine aAttr.Name & " = new " & Replace(aUDI.ClassName, " ", "_") & "();"
    aFcn.AddLine aAttr.Name & "->AddRef();"
    
    bMatrix = False
    bArray = False
    'Initialize temporary storage for arrays and matrices
    For Each aProperty In aUDI.Attributes
        Dim strArray As String
        Dim i, iUBoundRows, iUBoundColumns As Integer
        Dim aMatrixRows
        
        szValue = aProperty.Value
        If aProperty.sSubType = idxAttr_Array Then
            bArray = True
            szValue = FillArrayBlanks(szValue)
            aFcn.AddLine ""
            aFcn.AddLine aProperty.dataType & " init_" & aProperty.Name & "[] = {" & strArray & "};"
        ElseIf aProperty.sSubType = idxAttr_Matrix Then
             bMatrix = True
             szValue = FillMatrixBlanks(szValue, iUBoundColumns)
             aFcn.AddLine ""
             aMatrixRows = Split(szValue, DASH_DELIMETER)
             iUBoundRows = UBound(aMatrixRows)
             aFcn.AddLine aProperty.dataType & " init_" & aProperty.Name & "[][" & iUBoundColumns + 1 & "] = {"
             For i = 0 To iUBoundRows
                strArray = Replace(aMatrixRows(i), COLON_DELIMETER, ", ")
                aFcn.AddLine "                                         {" & strArray & "},"
             Next
             aFcn.AddLine "                                                       };"
        End If
    Next
    aFcn.AddLine ""
          
    For Each aProperty In aUDI.Attributes
      ' KAB --> Don't want to restrict this feature so simulation items only
      'If aProperty.bSim And (aProperty.sType = idxAttr_Variable Or aProperty.sType = idxAttr_Parameter) Then
        szValue = aProperty.Value
        If szValue <> "" Then
            If aProperty.sSubType = idxAttr_Scalar Then
                aFcn.AddLine aAttr.Name & "->" & aProperty.Name & " = " & szValue & ";"
            ElseIf aProperty.sSubType = idxAttr_Array Then
                aFcn.AddLine "INIT_ARRAY(" & aProperty.Name & ", init_" & aProperty.Name & ");"
            ElseIf aProperty.sSubType = idxAttr_Matrix Then
                aFcn.AddLine "INIT_MATRIX(" & aProperty.Name & ", init_" & aProperty.Name & ");"
            End If
        End If
      'End If
    Next
    aFcn.AddLine ""
  Next
  
  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "'Init' operation code generation error: " & err.Description
End Sub

Public Sub CgCompositeCleanFcn(shortListUDIs As Collection, classCgOperations As Collection)
  Dim aUDI As UserDefinedItem
  Dim aAttr As CgAttribute
  Dim aFcn As CgOperation
  Dim aProperty As CgAttribute
  Dim szObjectName As String
  
  On Error GoTo Error_Handler
  Set aFcn = New CgOperation
  aFcn.Access = "protected"
  aFcn.Name = "clean"
  aFcn.ReturnType = "void"
  
  For Each aUDI In shortListUDIs
    szObjectName = aUDI.ObjectName
    szObjectName = Replace(szObjectName, " ", "_")
    aFcn.AddLine "if (" & szObjectName & ")"
    aFcn.AddLine "{"
    aFcn.AddLine "  " & szObjectName & "->Release();"
    aFcn.AddLine "  " & szObjectName & " = NULL;"
    aFcn.AddLine "}"
  Next
  
  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "'Clean' operation code generation error: " & err.Description
End Sub

Public Sub CgCompositeSaveFcn(shortListUDIs As Collection, classCgOperations As Collection)
  
  Dim aUDI As UserDefinedItem
  Dim aOp As CgOperation
  Dim aFcn As CgOperation
  Dim szObjectName As String
  
  On Error GoTo Error_Handler
  Set aFcn = New CgOperation
  aFcn.Access = "protected"
  aFcn.Name = "Save"
  aFcn.ReturnType = "void"
  aFcn.AddPar "fs", "FILE", "InOut"
  
  For Each aUDI In shortListUDIs
    szObjectName = aUDI.ObjectName
    szObjectName = Replace(szObjectName, " ", "_")
    aFcn.AddLine szObjectName & "->Save(fs);"
  Next
  
  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "'Save' operation code generation error: " & err.Description
End Sub
  
Public Sub CgCompositeLoadFcn(shortListUDIs As Collection, classCgOperations As Collection)
  
  Dim aUDI As UserDefinedItem
  Dim aOp As CgOperation
  Dim aFcn As CgOperation
  Dim szObjectName As String
  
  On Error GoTo Error_Handler
  Set aFcn = New CgOperation
  aFcn.Access = "protected"
  aFcn.Name = "Load"
  aFcn.ReturnType = "bool"
  aFcn.AddPar "fs", "FILE", "InOut"
  
  For Each aUDI In shortListUDIs
    szObjectName = aUDI.ObjectName
    szObjectName = Replace(szObjectName, " ", "_")
    aFcn.AddLine "if (! " & szObjectName & "->Load(fs) ) return false;"
  Next
  
  aFcn.AddLine ""
  aFcn.AddLine "return true;"
  aFcn.OnCg = True
  aFcn.CgInit
  classCgOperations.Add aFcn
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "'Load' operation code generation error: " & err.Description
End Sub

Private Function FillArrayBlanks(szValue As String) As String
    Dim iRows As Integer
    Dim oRows, oCols
    Dim i, j As Integer
    Dim strValues As String
    
    strValues = ""
    oRows = Split(szValue, "-")
    iRows = UBound(oRows)
    For i = 0 To iRows
        If oRows(i) = "" Then oRows(i) = "NULL"
        strValues = strValues & CStr(oRows(i))
        If i < iRows Then strValues = strValues & ","
    Next
    FillArrayBlanks = strValues
End Function

Private Function FillMatrixBlanks(szValue As String, ByRef iUBoundColumns As Integer) As String
    Dim iRows, iCols As Integer
    Dim oRows, oCols
    Dim i, j As Integer
    Dim strValues As String
    
    strValues = ""
    oRows = Split(szValue, "-")
    iRows = UBound(oRows)
    For i = 0 To iRows
        oCols = Split(oRows(i), ";")
        iCols = UBound(oCols)
        iUBoundColumns = iCols
        For j = 0 To iCols
            If oCols(j) = "" Then oCols(j) = "NULL"
            strValues = strValues & CStr(oCols(j))
            If j < iCols Then strValues = strValues & ","
        Next
        If j >= iCols And i < iRows Then strValues = strValues & "-"
        Next
     FillMatrixBlanks = strValues
End Function
