VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgCompareCollection"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
  
  Private oldAttributes As RPCollection
  Private oldRelations As RPCollection
  Private oldOperations As RPCollection
  
  Private newAttributes As Collection
  Private newOperations As Collection
  
  Dim arpClass As RPClass
    
  Const COMPARE_SAME = &H0
  Const COMPARE_NEW = &H1
  Const COMPARE_OLD = &H2
  Const COMPARE_DIFF = &H4
  Const COMPARE_DIFF_AND_REPLACE = &H8
  
  'Values in these collections will be a combo of the above flags
  Private diffAttributes As Collection
  Private diffRelations As Collection
  Private diffOperations As Collection
  
  Property Set Class(ByRef curClass As RPClass)
    Set arpClass = curClass
  End Property
  
  Property Set rpAttributes(ByRef Attributes As RPCollection)
    Set oldAttributes = Attributes
  End Property
   
  Property Set rpRelations(ByRef Relations As RPCollection)
    Set oldRelations = Relations
  End Property
  
  Property Set rpOperations(ByRef Operations As RPCollection)
    Set oldOperations = Operations
  End Property
  
  Property Set AttributesCol(ByRef Attributes As Collection)
    Set newAttributes = Attributes
  End Property
  
  Property Set OperationsCol(ByRef Operations As Collection)
    Set newOperations = Operations
  End Property
  
  Public Function CompareCgAttributes() As Collection
    Dim arpAttribute As RPAttribute
    Dim aCgAttr As CgAttribute
    Dim bOnCg As Boolean
    Dim aAttr As RPAttribute
    Dim lItem As Long
    Dim cgHelper As cgCompareHelper
    
    Set diffAttributes = New Collection
        
    'Compare items to be added to the existing ones, and set appropriate flag
    If diffAttributes Is Nothing Then Set diffAttributes = New Collection
    Set arpAttribute = Nothing
    For Each aCgAttr In newAttributes
        If Not aCgAttr.bAggregate And Not aCgAttr.bComposite Then   'If not a relation
            Set arpAttribute = FindAttributeInCollection(aCgAttr.Name)
            Set cgHelper = New cgCompareHelper
            cgHelper.Name = aCgAttr.Name
            If arpAttribute Is Nothing Then     'New attribute.  Didn't exist in old class
                cgHelper.strAccess = aCgAttr.Access
                cgHelper.strDataType = aCgAttr.dataType
                cgHelper.lCompare = COMPARE_NEW
                diffAttributes.Add cgHelper, aCgAttr.Name
            Else                                'This attribute already existed in old class
                cgHelper.strAccess = aCgAttr.Access
                cgHelper.strAccessOld = arpAttribute.visibility
                cgHelper.strDataType = aCgAttr.dataType
                If (arpAttribute.typeOf.Name <> "") Then            'Pre-defined type used
                    cgHelper.strDataTypeOld = arpAttribute.typeOf.Name
                Else                                                'User Defined data type
                    cgHelper.strDataTypeOld = arpAttribute.typeOf.declaration
                    cgHelper.strDataTypeOld = Replace(cgHelper.strDataTypeOld, "%s", "")   'Strip off %s
                    cgHelper.strDataTypeOld = LTrim(RTrim(cgHelper.strDataTypeOld))
                End If
                              
                If cgHelper.AttributesEqual() Then
                    cgHelper.lCompare = COMPARE_SAME
                    diffAttributes.Add cgHelper, aCgAttr.Name
                Else
                    cgHelper.lCompare = COMPARE_DIFF
                    diffAttributes.Add cgHelper, aCgAttr.Name
                End If

            End If
        End If
    Next
    
    'Now run through the old list.  If any item in it does not have an item in the diffAttributes
    'collection, add it and mark it as old (non existant in new attributes)
    Set cgHelper = Nothing
    If Not oldAttributes Is Nothing Then
        For Each arpAttribute In oldAttributes
            bOnCg = CBool(arpAttribute.getPropertyValue("Simulation.Attribute.OnCg"))
            If bOnCg Then
                On Error Resume Next
                Set cgHelper = Nothing
                Set cgHelper = diffAttributes(arpAttribute.Name)
                If cgHelper Is Nothing Then
                    Set cgHelper = New cgCompareHelper
                    cgHelper.lCompare = COMPARE_OLD
                    cgHelper.Name = arpAttribute.Name
                    diffAttributes.Add cgHelper, arpAttribute.Name
                End If
            End If
        Next
    End If

    Set CompareCgAttributes = diffAttributes
  End Function
  
  Public Function CompareCgRelations() As Collection
    Dim arpRelation As RPRelation
    Dim aCgAttr As CgAttribute
    Dim bOnCg As Boolean
    Dim lItem As Long
    Dim cgHelper As cgCompareHelper
    
    Set diffRelations = New Collection
    Set CompareCgRelations = diffRelations
     
    If diffRelations Is Nothing Then Set diffRelations = New Collection
    Set aCgAttr = Nothing
    For Each aCgAttr In newAttributes
        If aCgAttr.bAggregate Or aCgAttr.bComposite Then   'If not a relation
            Set arpRelation = FindRelationInCollection(aCgAttr.Name)
            Set cgHelper = New cgCompareHelper
            cgHelper.Name = aCgAttr.Name
            If arpRelation Is Nothing Then     'New attribute.  Didn't exist in old class
                cgHelper.strAccess = aCgAttr.Access
                cgHelper.strDataType = ""
                cgHelper.lCompare = COMPARE_NEW
                diffRelations.Add cgHelper, aCgAttr.Name
            Else                                'This attribute already existed in old class
                cgHelper.strAccess = aCgAttr.Access
                cgHelper.strAccessOld = arpRelation.visibility
                cgHelper.strDataType = ""
                cgHelper.strDataTypeOld = ""
                If cgHelper.RelationsEqual() Then
                    cgHelper.lCompare = COMPARE_SAME
                    diffRelations.Add cgHelper, aCgAttr.Name
                Else
                    cgHelper.lCompare = COMPARE_DIFF
                    diffRelations.Add cgHelper, aCgAttr.Name
                End If
            End If
        End If
    Next
    
    'Now run through the old list.  If any item in it does not have an item in the diffAttributes
    'collection, add it and mark it as old (non existant in new attributes)
    Set cgHelper = Nothing
    If Not oldRelations Is Nothing Then
        For Each arpRelation In oldRelations
            bOnCg = CBool(arpRelation.getPropertyValue("Simulation.Relation.OnCg"))
            If bOnCg Then
                On Error Resume Next
                Set cgHelper = Nothing
                Set cgHelper = diffRelations(arpRelation.Name)
                If cgHelper Is Nothing Then
                    Set cgHelper = New cgCompareHelper
                    cgHelper.Name = arpRelation.Name
                    cgHelper.lCompare = COMPARE_OLD
                    diffRelations.Add cgHelper, arpRelation.Name
                End If
            End If
        Next
    End If
  End Function
  
  Public Function CompareCgOperations() As Collection
    Dim aCgPar As CgAttribute
    Dim aCgOper As CgOperation
    Dim aOper As RPOperation
    Dim bOnCg As Boolean
    Dim lItem As Long
    Dim cgHelper As cgCompareHelper
    
    Set diffOperations = New Collection
    Set CompareCgOperations = diffOperations
        
    If diffOperations Is Nothing Then Set diffOperations = New Collection
    Set arpOperation = Nothing
    For Each aCgOper In newOperations
        Set arpOperation = FindOperationsInCollection(aCgOper.Name)
        Set cgHelper = New cgCompareHelper
        cgHelper.Name = aCgOper.Name
        If arpOperation Is Nothing Then     'New attribute.  Didn't exist in old class
            cgHelper.lCompare = COMPARE_NEW
            cgHelper.strDataType = aCgOper.ReturnType
            cgHelper.strBody = aCgOper.Body
            cgHelper.strAccess = aCgOper.Access
            diffOperations.Add cgHelper, aCgOper.Name
        Else                                'This attribute already existed in old class
            cgHelper.strBody = aCgOper.Body
            cgHelper.strOldBody = arpOperation.Body
            cgHelper.strAccess = aCgOper.Access
            cgHelper.strAccessOld = arpOperation.visibility
            cgHelper.strDataType = aCgOper.ReturnType
            If arpOperation.ReturnType Is Nothing Then
                cgHelper.strDataTypeOld = ""
            Else
                cgHelper.strDataTypeOld = arpOperation.ReturnType.declaration
            End If
'            If aCgOper.Parameters.count > 0 Then
                'aCgOper.Parameters(1).dataType  'ie. BSTR
                'aCgOper.Parameters(1).Name      'ie. filename
                
'            End If
'            If arpOperation.Arguments.count > 0 Then
                'arpOperation.Arguments(1).declaration  'FILE*
                'arpOperation.Arguments(1).name         'fs
'            End If
            If cgHelper.OperationsEqual() Then
                cgHelper.lCompare = COMPARE_SAME
                diffOperations.Add cgHelper, aCgOper.Name
            Else
                cgHelper.lCompare = COMPARE_DIFF
                diffOperations.Add cgHelper, aCgOper.Name
            End If
        End If
        
    Next
    
    'Now run through the old list.  If any item in it does not have an item in the diffAttributes
    'collection, add it and mark it as old (non existant in new attributes)
    Set cgHelper = Nothing
    If Not oldOperations Is Nothing Then
        For Each arpOperation In oldOperations
            bOnCg = CBool(arpOperation.getPropertyValue("Simulation.Operation.OnCg"))
            If bOnCg Then
                On Error Resume Next
                Set cgHelper = Nothing
                Set cgHelper = diffOperations(arpOperation.Name)
                If cgHelper Is Nothing Then
                    Set cgHelper = New cgCompareHelper
                     cgHelper.lCompare = COMPARE_OLD
                     cgHelper.Name = arpOperation.Name
                    diffOperations.Add cgHelper, arpOperation.Name
                End If
            End If
        Next
    End If
  End Function


  Public Function UserSelectDifferences(chViewDetails As Boolean) As Boolean
    Dim i As Integer
    Dim frmClassDetail As frmClassModificationDetail
    
    UserSelectDifferences = False   'This indicated if add\delete should be aborted
    If chViewDetails Then           'Give the user a chance to modify the new operation
        Set frmClassDetail = New frmClassModificationDetail
        Set frmClassDetail.m_cgParent = Me
        frmClassDetail.InitAttributesGrid diffAttributes
        frmClassDetail.InitRelationsGrid diffRelations
        frmClassDetail.InitOperationsGrid diffOperations
        frmClassDetail.SetClassName arpClass.Name
        frmClassDetail.Show vbModal
        frmClassDetail.Refresh
        
        If frmClassDetail.bAbortAddDelete Then
            UserSelectDifferences = True
        End If
    End If
  End Function

  Public Function DoAttributeAddDelete() As Boolean
    Dim arpAttribute As RPAttribute
    Dim aCgAttr As CgAttribute
    Dim bOnCg As Boolean
    Dim aAttr As RPAttribute
    Dim cbHelper As cgCompareHelper
    
    DoAttributeAddDelete = True
    On Error GoTo ErrorHandler
       
    'Delete Old
    If Not oldAttributes Is Nothing Then
        For Each arpAttribute In oldAttributes
          bOnCg = CBool(arpAttribute.getPropertyValue("Simulation.Attribute.OnCg"))
          If bOnCg Then
            On Error Resume Next
            Set cgHelper = Nothing
            Set cgHelper = diffAttributes(arpAttribute.Name)
            If Not cgHelper Is Nothing Then
                If cgHelper.lCompare = COMPARE_OLD Or cgHelper.lCompare = COMPARE_DIFF_AND_REPLACE Or cgHelper.lCompare = COMPARE_NEW Then
                    arpClass.deleteAttribute arpAttribute
                End If
            End If
          End If
        Next
    End If
    
    'Add New
    For Each aCgAttr In newAttributes
        On Error Resume Next
        If Not aCgAttr.bAggregate And Not aCgAttr.bComposite Then
            On Error Resume Next
            Set cgHelper = diffAttributes(aCgAttr.Name)
            If Not cgHelper Is Nothing Then
              If cgHelper.lCompare = COMPARE_NEW Or cgHelper.lCompare = COMPARE_DIFF_AND_REPLACE Then
                    Set aAttr = arpClass.addAttribute(aCgAttr.Name)
                    Set aCgAttr.obj = aAttr
                    aAttr.setTypeDeclaration cgHelper.strDataType
                    aAttr.visibility = cgHelper.strAccess
                    aAttr.setPropertyValue "CPP_CG.Attribute.Visibility", cgHelper.strAccess
                    aAttr.setPropertyValue "Simulation.Attribute.OnCg", "True"
                    aAttr.setPropertyValue "CPP_CG.Attribute.AccessorGenerate", False
                    aCgAttr.Save
                End If
            End If
        End If
    Next
  Exit Function
  
ErrorHandler:
      gMsgWnd.LogMessage "Class Wizard failed to update attributes. Error: " & err.Description
      DoAttributeAddDelete = False
      Resume Next
  End Function

  Public Function DoRelationAddDelete() As Boolean
    Dim arpRelation As RPRelation
    Dim aCgAttr As CgAttribute
    Dim bOnCg As Boolean
    Dim cbHelper As cgCompareHelper
    
    DoRelationAddDelete = True
    On Error GoTo ErrorHandler
   
    'Delete old
    If Not oldRelations Is Nothing Then
        For Each arpRelation In oldRelations
          bOnCg = CBool(arpRelation.getPropertyValue("Simulation.Relation.OnCg"))
          If bOnCg Then
            On Error Resume Next
            Set cgHelper = Nothing
            Set cgHelper = diffRelations(arpRelation.Name)
            If Not cgHelper Is Nothing Then
                If cgHelper.lCompare = COMPARE_OLD Or cgHelper.lCompare = COMPARE_DIFF_AND_REPLACE Or cgHelper.lCompare = COMPARE_NEW Then
                    arpClass.deleteRelation arpRelation
                End If
            End If
          End If
        Next
    End If
    
    'Add New
   For Each aCgAttr In newAttributes
    On Error Resume Next
    Set cgHelper = diffRelations(aCgAttr.Name)
    If Not cgHelper Is Nothing Then
        If cgHelper.lCompare = COMPARE_NEW Or cgHelper.lCompare = COMPARE_DIFF_AND_REPLACE Then
             If aCgAttr.bAggregate Then
               Set arpRelation = arpClass.addRelation(aCgAttr.dataType, aCgAttr.PackageName, aCgAttr.Name, "Aggregation", "1", "", "Association", "1", "")
               arpRelation.makeUnidirect
               Set aCgAttr.obj = arpRelation
               If cgHelper.strAccess = "public" Then
                 arpRelation.setPropertyValue "CPP_CG.Relation.DataMemberVisibility", "Public"
               End If
               arpRelation.setPropertyValue "Simulation.Attribute.OnCg", aCgAttr.OnCg
               arpRelation.setPropertyValue "CG.Relation.AddGenerate", False
               arpRelation.setPropertyValue "CG.Relation.ClearGenerate", False
               arpRelation.setPropertyValue "CG.Relation.GetGenerate", False
               arpRelation.setPropertyValue "CG.Relation.SetGenerate", False
         
              ElseIf aCgAttr.bComposite Then
                Set arpRelation = arpClass.addRelation(aCgAttr.dataType, aCgAttr.PackageName, aCgAttr.Name, "Composition", "1", "", "Association", "1", "")
                arpRelation.makeUnidirect
                Set aCgAttr.obj = arpRelation
                If cgHelper.strAccess = "public" Then
                  arpRelation.setPropertyValue "CPP_CG.Relation.DataMemberVisibility", "Public"
                End If
                arpRelation.setPropertyValue "Simulation.Attribute.OnCg", aCgAttr.OnCg
                aAttr.setPropertyValue "CG.Relation.AddGenerate", False
                aAttr.setPropertyValue "CG.Relation.ClearGenerate", False
                aAttr.setPropertyValue "CG.Relation.GetGenerate", False
                aAttr.setPropertyValue "CG.Relation.SetGenerate", False '
        
              End If
              aCgAttr.Save
            End If
        End If
    Next
    Exit Function
    
ErrorHandler:
     gMsgWnd.LogMessage "Class Wizard failed to update relations. Error: " & err.Description
     DoRelationAddDelete = False
     Resume Next
 End Function

  Public Function DoOperationAddDelete() As Boolean
    Dim arpOperation As RPOperation
    Dim aCgPar As CgAttribute
    Dim aCgOper As CgOperation
    Dim aOper As RPOperation
    Dim bOnCg As Boolean
    Dim cbHelper As cgCompareHelper
    
    DoOperationAddDelete = True
    On Error GoTo ErrorHandler
    
    'Delete Old
    If Not oldOperations Is Nothing Then
        For Each arpOperation In oldOperations
          bOnCg = CBool(arpOperation.getPropertyValue("Simulation.Operation.OnCg"))
          If bOnCg Then
            On Error Resume Next
            Set cgHelper = Nothing
            Set cgHelper = diffOperations(arpOperation.Name)
            If Not cgHelper Is Nothing Then
                If cgHelper.lCompare = COMPARE_OLD Or cgHelper.lCompare = COMPARE_DIFF_AND_REPLACE Or cgHelper.lCompare = COMPARE_NEW Then
                    arpClass.deleteOperation arpOperation
                End If
            End If
          End If
        Next
    End If
   
    'Add new
    For Each aCgOper In newOperations
        On Error Resume Next
        Set cgHelper = diffOperations(aCgOper.Name)
        If Not cgHelper Is Nothing Then
        If cgHelper.lCompare = COMPARE_NEW Or cgHelper.lCompare = COMPARE_DIFF_AND_REPLACE Then
              If aCgOper.bConstructor Then
                Set aOper = arpClass.addConstructor("")
              ElseIf aCgOper.bDestructor Then
                Set aOper = arpClass.addDestructor()
              Else
                Set aOper = arpClass.addOperation(aCgOper.Name)
              End If
              Set aCgOper.obj = aOper
              aOper.visibility = cgHelper.strAccess
              aOper.Body = cgHelper.strBody
              aOper.setPropertyValue "Simulation.Operation.OnCg", aCgOper.OnCg
              aOper.setReturnTypeDeclaration cgHelper.strDataType
              aOper.ReturnType.declaration = cgHelper.strDataType
              
              ' turn animation off for residual and ad_ operations
              If aCgOper.OnCg Or _
                 (aCgOper.bSim And _
                 (aCgOper.sType = idxOper_Continuous Or aCgOper.sType = idxOper_Reset Or aCgOper.sType = idxOper_Discontinuous)) Then
                aOper.setPropertyValue "CG.Operation.Animate", False
                aOper.setPropertyValue "CG.Operation.AnimateArguments", False
              End If
              
              For Each aCgPar In aCgOper.Parameters
                Set aPar = aOper.addArgument(aCgPar.Name)
                
                szDataType = aCgPar.dataType
                
                If szDataType = "double**" Then
                  szDataType = "ppdouble"
                ElseIf szDataType = "_TCHAR**" Then
                  szDataType = "ppchar"
                ElseIf szDataType = "Fdouble**" Then
                  szDataType = "ppfdouble"
                ElseIf szDataType = "long**" Then
                  szDataType = "pplong"
                End If
                
                'addition because code generate for Artisan adds a pointer (*) automatically for all "Out" and "InOut" parameters
                If UCase(aCgPar.Mechanism) = "OUT" Or UCase(aCgPar.Mechanism) = "INOUT" Then
                  szDataType = szDataType & "*"
                End If
                
                If UCase(aCgPar.Mechanism) = "IN" Then
                  szDataType = "const " & szDataType
                End If
                
                aPar.setTypeDeclaration szDataType
                If Len(aCgPar.Mechanism) > 0 Then
                  aPar.argumentDirection = aCgPar.Mechanism
                End If
              Next
              aCgOper.Save
            End If
        End If
    Next
      
    Exit Function
ErrorHandler:
      gMsgWnd.LogMessage "Class Wizard failed to update operations. Error: " & err.Description
      DoOperationAddDelete = False
      Resume Next
  End Function

Private Function FindAttributeInCollection(strAttr As String) As RPAttribute
    Dim i As Integer
    
    Set FindAttributeInCollection = Nothing
    If oldAttributes Is Nothing Then Exit Function
    For i = 1 To oldAttributes.count
        If oldAttributes(i).Name = strAttr Then
            Set FindAttributeInCollection = oldAttributes(i)
            Exit For
        End If
    Next
End Function

Private Function FindRelationInCollection(strRel As String) As RPRelation
    Dim i As Integer
    
    Set FindRelationInCollection = Nothing
    If oldRelations Is Nothing Then Exit Function
    For i = 1 To oldRelations.count
        If oldRelations(i).Name = strRel Then
            Set FindRelationInCollection = oldRelations(i)
            Exit For
        End If
    Next
End Function

Private Function FindOperationsInCollection(strOper As String) As RPOperation
    Dim i As Integer
    
    Set FindOperationsInCollection = Nothing
    If oldOperations Is Nothing Then Exit Function
    For i = 1 To oldOperations.count
        If oldOperations(i).Name = strOper Then
            Set FindOperationsInCollection = oldOperations(i)
            Exit For
        End If
    Next
End Function

Public Sub WriteBackArrays(diffAttribs As Collection, diffRels As Collection, diffOpers As Collection)
    Set diffAttributes = Nothing
    Set diffRelations = Nothing
    Set diffOperations = Nothing
    
    Set diffAttributes = diffAttribs
    Set diffRelations = diffRels
    Set diffOperations = diffOpers
End Sub

