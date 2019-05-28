VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "UDIDefMgr"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'======================================================================================
'
' Module:   UDIDefMgr (manages UDIs)
'--------------------------------------------------------------------------------------
'======================================================================================


Option Explicit

'=================================================================
' Start of Declarations Section
'=================================================================

Private m_frmMsg As frmLoadingMsg
Private m_collDef As Collection

Public m_custDrawEditor As CustomDrawingEditor


'=================================================================
' End of Declarations Section
'=================================================================

'-------------------------------
Private Sub Class_Initialize()
  Set m_collDef = New Collection
End Sub

'-------------------------------
Private Sub Class_Terminate()
  DestroyAll
  Set m_collDef = Nothing
End Sub
'-------------------------------
Public Sub DestroyAll()
  Dim i As Integer
  Dim objDwg As UserDefinedItemDef
  
  On Error Resume Next
  If Not m_collDef Is Nothing Then
    For i = 1 To m_collDef.count
      Set objDwg = m_collDef(1)
      objDwg.DestroyAll
      m_collDef.Remove 1
    Next i
  End If
End Sub

'-------------------------------
Private Sub AddToCollection(objDwg As UserDefinedItemDef)
  m_collDef.Add objDwg
End Sub

'-------------------------------
Public Property Get IsDirty() As Boolean
  Dim i As Long
  Dim objDef As UserDefinedItemDef
  
  On Error Resume Next
  IsDirty = True
  For i = 1 To m_collDef.count
    Set objDef = m_collDef(i)
    If objDef.IsDirty Then Exit Property
  Next i
  IsDirty = False
End Property

Public Property Let IsDirty(bDirty As Boolean)
    Dim objDef As UserDefinedItemDef
    
    'In some cases like deletion of a Def, need to set dirty flag on a different def
    If m_collDef.count > 0 Then
       Set objDef = m_collDef(1)
       objDef.IsDirty = True
    End If
End Property

'-------------------------------
Public Property Get UDIDefs() As Collection
  Set UDIDefs = m_collDef
End Property
'-------------------------------
Public Property Get NumUDIDefs() As Long
  NumUDIDefs = m_collDef.count
End Property
'-------------------------------
Public Property Get UDIDef(ByVal Index As Long) As UserDefinedItemDef
  If Index > 0 And Index <= m_collDef.count Then
    Set UDIDef = m_collDef.Item(Index)
  End If
End Property
'-------------------------------
Public Function GetUDIDefbyObjectName(ByVal strName As String) As UserDefinedItemDef
  Dim i As Long
  Dim bRet As Boolean
  
  ' see if in my list
  For i = 1 To m_collDef.count
    Debug.Print i & ", " & m_collDef.Item(i).ClassName & ", " & m_collDef.Item(i).ObjectName
    If m_collDef.Item(i).ObjectName = strName Then
      Set GetUDIDefbyObjectName = m_collDef.Item(i)
      Exit Function
    End If
  Next i
End Function

Public Function GetUDIDefbyFolderAndShape(ByVal strFolder As String, ByVal strShape As String) As UserDefinedItemDef
  Dim i As Long
  Dim pDef As UserDefinedItemDef
  Dim bRet As Boolean
  
  Set GetUDIDefbyFolderAndShape = Nothing
  If strFolder = "" Or strShape = "" Then Exit Function
  
  For i = 1 To m_collDef.count
    Set pDef = m_collDef.Item(i)
    If pDef.GeFolder = strFolder And pDef.GeShape = strShape Then
      Set GetUDIDefbyFolderAndShape = pDef
      Exit Function
    End If
  Next i
End Function

Public Function GetUDIDef(ByVal strFolder As String, ByVal strShape As String) As UserDefinedItemDef
  Dim i As Long
  Dim pDef As UserDefinedItemDef
  Dim bRet As Boolean
  Dim lShapeID As Long
  
  Set GetUDIDef = Nothing
  If strFolder = "" Or strShape = "" Then Exit Function
  lShapeID = GetShapeID(strFolder, strShape)
  
  'Primary lookup based on ShapeID
  For i = 1 To m_collDef.count
    Set pDef = m_collDef.Item(i)
    If pDef.GeShapeID = lShapeID And lShapeID <> -1 Then
      Set GetUDIDef = pDef
      Exit Function
    End If
  Next i
  
  'If Primary lookup failes, secondary lookup based on Shape Name and Folder
  For i = 1 To m_collDef.count
    Set pDef = m_collDef.Item(i)
    If strFolder <> "" And strShape <> "" Then
        If pDef.GeFolder = strFolder And pDef.GeShape = strShape Then
          Set GetUDIDef = pDef
          Exit Function
        End If
    End If
  Next i
End Function


Public Function CreateUDIDefFromObjectName(ByVal strName As String) As UserDefinedItemDef
  Dim objDef As UserDefinedItemDef
  
  On Error Resume Next
  Set objDef = New UserDefinedItemDef
  objDef.ObjectName = strName
  Set CreateUDIDefFromObjectName = objDef
  AddToCollection objDef

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

Public Function CreateUDIDef() As UserDefinedItemDef
  Dim objDef As UserDefinedItemDef
  Set objDef = New UserDefinedItemDef
  AddToCollection objDef
  Set CreateUDIDef = objDef
End Function

Public Function DeleteUDIDef(ByVal strName As String) As Boolean
  ' permanently delete from my list
  Dim i As Long
  Dim objDef As UserDefinedItemDef
  Dim objDef2 As UserDefinedItemDef
  Dim iFound As Integer
  
  On Error Resume Next
  For i = 1 To m_collDef.count
    Set objDef = m_collDef.Item(i)
    If objDef.ObjectName = strName Then
    
      'If there is another shape def for this class, then it will get saved when they are all saved on exit,
      'otherwise delete it explicitly
      iFound = 0
      For Each objDef2 In m_collDef
        If objDef.ClassName = objDef2.ClassName And objDef.PackageName = objDef2.PackageName Then
            iFound = iFound + 1
        End If
      Next
    
      If iFound = 1 Then
        SetXMLUDIDefs "None", objDef.PackageName, objDef.ClassName
      End If
      objDef.DestroyAll
      m_collDef.Remove i
      DeleteUDIDef = True
      Exit For
    End If
  Next i

End Function

'================================================================
' Storage
'================================================================

Public Function SaveModelDef() As Boolean
  Dim objDef As UserDefinedItemDef
  Dim szXML As String
  Dim colDefs As New Collection
  Dim objHelper As UDIHelper
  Dim strFolderID As String
  Dim cgConn As CgConnectionDef
  Dim i As Integer
  
  On Error Resume Next
  SaveModelDef = True
   
  'First run through the collection and make sure that for each UDIDef, the shape it references is valid.
  'If not, it must be left over from some failed operation, so delete it.
  For Each objDef In m_collDef
    strFolderID = CStr(GetIDForFolder(objDef.GeFolder))
    If Not ShapeExists(strFolderID, objDef.GeShape, Nothing) Then
        If Not ShapeExistsByID(strFolderID, objDef.GeShapeID, Nothing) Then
            DeleteUDIDef objDef.GeShape
        End If
    End If
  Next
   
  'Second, make sure that the UDIDef is referencing valid classes.
  'If not, delete it.
  For Each objDef In m_collDef
    If FindClass(objDef.ClassName, objDef.ID) Is Nothing Then
        DeleteUDIDef objDef.GeShape
    Else
        'Make sure a valid class item is referenced
        For i = 1 To objDef.CgConnectionDefs.count
            Set cgConn = objDef.CgConnectionDefs(i)
            If Not ItemExists(objDef.ClassName, objDef.ID, cgConn.itemName, cgConn.itemID, cgConn.itemType) Then
                objDef.CgConnectionDefs.Remove i
            End If
        Next
    End If
  Next
    
  'Have to assemble xml definitions for the same class together
  For Each objDef In m_collDef
    Dim strTempXML As String
    Dim objUDIHelperTemp As UDIHelper

    Set objUDIHelperTemp = colDefs.Item(objDef.ClassName)
    If Not objUDIHelperTemp Is Nothing Then              'Class already has an assoicated shape
        objUDIHelperTemp.m_strXML = objUDIHelperTemp.m_strXML + objDef.export
        Set objUDIHelperTemp = Nothing
    Else
        Dim objUDIHelper
        Set objUDIHelper = New UDIHelper
        objUDIHelper.m_strClassName = objDef.ClassName
        objUDIHelper.m_strPackageName = objDef.PackageName
        objUDIHelper.m_strXML = objDef.export
        colDefs.Add objUDIHelper, objDef.ClassName
    End If
  Next

  For Each objHelper In colDefs
    If Not SetXMLUDIDefs(objHelper.m_strXML, objHelper.m_strPackageName, objHelper.m_strClassName) Then
       SaveModelDef = False
       gMsgWnd.LogMessage "Failed to save model definitions to UML project."
    End If
  Next
End Function

Public Function LoadModelDef() As Boolean
  Dim objDef As UserDefinedItemDef
  Dim aDoc As DOMDocument
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim i As Long
  Dim aUDIDef As UserDefinedItemDef
  Dim strUDIXml As String
  Dim aCI As rtsClass
  Dim strLastClass As String

  LoadModelDef = True
  strLastClass = ""
  Set aCI = Nothing
  
  If IsUMLProjectOpen() Then
    DisplayStatusMessage "Loading UML Models..."
    strUDIXml = GetXMLUDIDefs
    Set aDoc = New DOMDocument
    On Error Resume Next
    If aDoc.loadXML(strUDIXml) Then
      Set aNodeList = aDoc.getElementsByTagName("UDIDef")
      For i = 0 To aNodeList.length - 1
        Set aItem = aNodeList(i)
        Set aUDIDef = New UserDefinedItemDef
        aUDIDef.import aItem                'Retrieve XML Shape Definition Data
        
        If aCI Is Nothing Or strLastClass <> aUDIDef.ClassName Then
            Set aCI = aUDIDef.GetAttributes               'Retrieve Attribute List
        End If
        strLastClass = aUDIDef.ClassName
        
        '-------------------------------------------------------------------------------
        'TEMPORARY:  Assist addition of GeShapeID field to xml schema, and itemID to
        '            connection xml schema
        If aUDIDef.GeShapeID <= 0 And Len(aUDIDef.GeFolder) > 0 And Len(aUDIDef.GeShape) > 0 Then
            aUDIDef.GeShapeID = GetShapeID(aUDIDef.GeFolder, aUDIDef.GeShape)
            If (aUDIDef.GeShapeID >= 0) Then
              gMsgWnd.LogMessage "Adding ShapeID='" & aUDIDef.GeShapeID & "' to UDIDef xml definition for shape '" & aUDIDef.GeShape & "'."
            End If
        End If
        
        Dim cgConn As CgConnectionDef
        Dim aAttrib As CgAttribute
        Dim aOper As CgOperation
        Dim j As Integer
        Dim aProject As rtsProject
                       
        For j = 1 To Projects.count
           If doc.activeProject.Name = Projects(j).Name Then
             Set aProject = Projects(j)
             Exit For
           End If
        Next j
                                 
        If Not aCI Is Nothing Then
            For Each cgConn In aUDIDef.CgConnectionDefs
                If cgConn.itemID = "" And cgConn.itemName <> "" Then
                    If cgConn.itemType = idxItemType_Attribute Then
                        For Each aAttrib In aCI.Attributes
                            If aAttrib.Name = cgConn.itemName Then
                                cgConn.itemID = aAttrib.obj.GUID
                                Me.IsDirty = True
                                gMsgWnd.LogMessage "Adding itemID='" & aUDIDef.ID & "' for connection xml definition '" & cgConn.connName & "' mapped to attribute '" & cgConn.itemName & "'."
                                Exit For
                            End If
                        Next
                    ElseIf cgConn.itemType = idxItemType_Operation Then
                        For Each aOper In aCI.Operations
                            If aOper.Name = cgConn.itemName Then
                                cgConn.itemID = aOper.obj.GUID
                                Me.IsDirty = True
                                gMsgWnd.LogMessage "Adding itemID='" & aUDIDef.ID & "' for connection xml definition '" & cgConn.connName & "' mapped to operation '" & cgConn.itemName & "'."
                                Exit For
                            End If
                        Next
                    End If
                End If
            Next
        End If
        '-------------------------------------------------------------------------------
        
        m_collDef.Add aUDIDef, aUDIDef.ObjectName
      Next i
      'Perform plausibility checks:
      VerifyDrawingShapesAgainstUDIDefs
    Else
      LoadModelDef = False
      gMsgWnd.LogMessage "Failed to load shape definitions from UML project."
    End If
    DisplayStatusMessageClose
  End If
End Function

Private Sub DisplayStatusMessage(strMsg As String)
    Set m_frmMsg = New frmLoadingMsg
    m_frmMsg.SetCaption strMsg
    m_frmMsg.Show
    m_frmMsg.Refresh
End Sub

Private Sub DisplayStatusMessageClose()
    If Not m_frmMsg Is Nothing Then
        m_frmMsg.Hide
        Set m_frmMsg = Nothing
    End If
End Sub

Private Function VerifyDrawingShapesAgainstUDIDefs() As Boolean
    Dim i As Integer
    Dim custDrawing As CustomDrawing
    Dim UDIItems As UserDefinedItems
    Dim UDIItem As UserDefinedItem
    Dim strShapeName As String
    Dim strClassName As String
    Dim strPackageName As String
    Dim strProjectName As String
    
    VerifyDrawingShapesAgainstUDIDefs = True
    If Not m_custDrawEditor Is Nothing Then
        Set custDrawing = m_custDrawEditor.CustomDrawing()
        If custDrawing Is Nothing Then
            VerifyDrawingShapesAgainstUDIDefs = False
            gMsgWnd.LogMessage "Failed to retrieve CustomDrawing object"
            Exit Function
        End If
        Set UDIItems = custDrawing.UDIItems()
        If UDIItems Is Nothing Then
            VerifyDrawingShapesAgainstUDIDefs = False
            gMsgWnd.LogMessage "Failed to retrieve UDIItems object"
            Exit Function
        End If
        'For each shape on drawing, find matching UDIDef
        For i = 1 To UDIItems.Items.count
            Set UDIItem = UDIItems.Items(i)
            If Not UDIItem Is Nothing Then
                strShapeName = UDIItem.ObjectName
                'Look up Item in UDIDef collection
                If strShapeName <> "" Then
                    Dim UDIDef As UserDefinedItemDef
                    Set UDIDef = m_collDef.Item(strShapeName)
                    If UDIDef Is Nothing Then
                        gMsgWnd.LogMessage "Failed to locate User Object Definition for drawing item: " & strShapeName
                        VerifyDrawingShapesAgainstUDIDefs = False
                    Else
                        If VerifyUDIDefConnections(UDIItem, UDIDef) = False Then
                            VerifyDrawingShapesAgainstUDIDefs = False
                            gMsgWnd.LogMessage "Could not verify validity of connections for shape: " & strShapeName
                        End If
                        If VerifyUDIDefAttributes(UDIItem, UDIDef) = False Then
                            VerifyDrawingShapesAgainstUDIDefs = False
                            gMsgWnd.LogMessage "Could not verify validity of attribute references for shape: " & strShapeName
                        End If
                    End If
                End If
            End If
        Next
    End If
End Function

' Verify that all connection objects reference valid classes
Private Function VerifyUDIDefConnections(ByVal UDIItem As UserDefinedItem, ByVal UDIDef As UserDefinedItemDef) As Boolean
    Dim i, j, iNumFailures As Integer
    Dim m_Projects As Object
    Dim SelectedProject As rtsProject
            
    On Error Resume Next
    If Projects Is Nothing Then
        GetProjects Projects, m_Projects
    Else
        If Projects.count = 0 Then
            GetProjects Projects, m_Projects
        End If
    End If
      
    For j = 1 To Projects.count
        If doc.activeProject.Name = Projects(j).Name Then
          Set SelectedProject = Projects(j)
          Exit For
        End If
    Next j
    If SelectedProject Is Nothing Then
          gMsgWnd.LogMessage "Failed to find UML project " & doc.activeProject.Name
          VerifyUDIDefConnections = False
          Exit Function
    End If
    
    VerifyUDIDefConnections = True
    iNumFailures = 0
    For i = 1 To UDIDef.CgConnectionDefs.count
        Dim cgConDef As CgConnectionDef
        Dim strItemName, strConnName, strClassName As String
        Dim iOperationIndex As Integer
        Dim bClassVerified As Boolean
        Dim SelectedPackage As rtsPackage
        Dim SelectedClass As rtsClass
                                    
        bClassVerified = False
        Set cgConDef = UDIDef.CgConnectionDefs(i)
        strItemName = cgConDef.itemName()
        strConnName = cgConDef.connName()
        
        Set SelectedPackage = SelectedProject.Packages(UDIDef.PackageName)
        If SelectedPackage Is Nothing Then
              gMsgWnd.LogMessage "Connection " & strConnName & " in class " & SelectedClass.Name & ", package " & SelectedPackage.Name & " could not be verified."
              bClassVerified = False
              Exit For
        End If
        
        Set SelectedClass = SelectedPackage.Classes(UDIDef.ClassName())
        If SelectedClass Is Nothing Then
              gMsgWnd.LogMessage "Connection " & strConnName & " in class " & SelectedClass.Name & ", package " & SelectedPackage.Name & " could not be verified."
              bClassVerified = False
              Exit For
        End If
                     
        iOperationIndex = FindAttributeInClass(SelectedClass, strItemName)
        If iOperationIndex > 0 Then
              bClassVerified = True
              Exit For
        Else
            ' See if there a matching operation
            iOperationIndex = FindOperationInClass(SelectedClass, strItemName)
            If iOperationIndex > 0 Then
              bClassVerified = True
              Exit For
            Else
              gMsgWnd.LogMessage "Connection " & strConnName & " is referencing " & strItemName & " which does not exist in class " & SelectedClass.Name & ", package " & SelectedPackage.Name
              Exit For
            End If
        End If
        
        If bClassVerified = False Then
            iNumFailures = iNumFailures + 1
        End If
    Next
    
    If iNumFailures > 0 Then VerifyUDIDefConnections = False
End Function

' Verify that all connections reference valid UML class attributes
Private Function VerifyUDIDefAttributes(ByVal UDIItem As UserDefinedItem, ByVal UDIDef As UserDefinedItemDef) As Boolean
    Dim i, j, iNumFailures As Integer
    Dim SelectedProject As rtsProject
    Dim m_Projects As Object
   
    On Error Resume Next
    VerifyUDIDefAttributes = True
    iNumFailures = 0
    
    If Projects Is Nothing Then
      GetProjects Projects, m_Projects
    Else
      If Projects.count = 0 Then
          GetProjects Projects, m_Projects
      End If
    End If

    For j = 1 To Projects.count
      If doc.activeProject.Name = Projects(j).Name Then
        Set SelectedProject = Projects(j)
        Exit For
      End If
    Next j
    If SelectedProject Is Nothing Then
        gMsgWnd.LogMessage "Failed to find UML project " & doc.activeProject.Name
        VerifyUDIDefAttributes = False
        Exit Function
    End If
    
    If Not IsUMLProjectOpen() Then
    
    End If
        
    For i = 1 To UDIDef.Attributes.count
         Dim cgAttributeDef As CgAttribute
         Dim strItemName, strClassName As String
         Dim iOperationIndex As Integer
         Dim bClassVerified As Boolean
         Dim SelectedPackage As rtsPackage
         Dim SelectedClass As rtsClass
               
         bClassVerified = False
         Set cgAttributeDef = UDIDef.Attributes(i)
         strItemName = cgAttributeDef.Name()
         
         Set SelectedPackage = SelectedProject.Packages(UDIDef.PackageName)
         If SelectedPackage Is Nothing Then
              gMsgWnd.LogMessage "Attribute " & strItemName & " in class " & SelectedClass.Name & ", package " & SelectedPackage.Name & " could not be verified."
              bClassVerified = False
              Exit For
         End If
         
         Set SelectedClass = SelectedPackage.Classes(UDIDef.ClassName())
         If SelectedClass Is Nothing Then
              gMsgWnd.LogMessage "Attribute " & strItemName & " in class " & SelectedClass.Name & ", package " & SelectedPackage.Name & " could not be verified."
              bClassVerified = False
              Exit For
         End If
            
         iOperationIndex = FindAttributeInClass(SelectedClass, strItemName)
         If iOperationIndex > 0 Then
              bClassVerified = True
              Exit For
         Else
            iOperationIndex = FindOperationInClass(SelectedClass, strItemName)
            If iOperationIndex > 0 Then
              bClassVerified = True
              Exit For
            Else
              gMsgWnd.LogMessage "Attribute " & strItemName & " is referencing " & strItemName & " which does not exist in class " & SelectedClass.Name & ", package " & SelectedPackage.Name
              Exit For
            End If
         End If
        
         If bClassVerified = False Then
            iNumFailures = iNumFailures + 1
         End If
    Next
    
    If iNumFailures > 0 Then VerifyUDIDefAttributes = False
End Function

' Verify that a given UML exists in a UML package
Private Function FindClassInPackage(ByVal selPackage As RPPackage, ByVal strClassName As String) As Integer
    Dim i, iClassCount As Integer
    
    FindClassInPackage = -1
    iClassCount = selPackage.Classes.count
    If iClassCount > 0 Then
        For i = 1 To iClassCount
            If selPackage.Classes(i).Name = strClassName Then
                FindClassInPackage = i
                Exit For
            End If
        Next
    End If
End Function

' Retrieve matching class based on class name
Private Function GetClassFromPackage(ByVal selPackage As RPPackage, ByVal strClassName As String) As RPClass
    Dim i, iClassCount As Integer
    
    iClassCount = selPackage.Classes.count
    If iClassCount > 0 Then
        For i = 1 To iClassCount
            If selPackage.Classes(i).Name = strClassName Then
                Set GetClassFromPackage = selPackage.Classes(i)
                Exit For
            End If
        Next
    End If
End Function


' Verify that a given operation exists in a UML class
Private Function FindOperationInClass(ByVal selClass As rtsClass, ByVal strItemName As String) As Integer
    Dim i, iOperCount As Integer
    
    FindOperationInClass = -1
    iOperCount = selClass.Operations.count
    If iOperCount > 0 Then
        For i = 1 To iOperCount
            If selClass.Operations(i).Name = strItemName Then
                FindOperationInClass = i
                Exit For
            End If
        Next
    End If
End Function

' Retrieve matching Operation based on class name
Private Function GetOperationFromClass(ByVal selClass As RPClass, ByVal strItemName As String) As RPOperation
    Dim i, iOperCount As Integer
    
    iOperCount = selClass.Operations.count
    If iOperCount > 0 Then
        For i = 1 To iOperCount
            If selClass.Operations(i).Name = strItemName Then
                Set GetOperationFromClass = selClass.Operations(i)
                Exit For
            End If
        Next
    End If
End Function

Private Function FindAttributeInClass(ByVal selClass As rtsClass, ByVal strItemName As String) As Integer
    Dim i, iAttrCount As Integer
    
    FindAttributeInClass = -1
    iAttrCount = selClass.Attributes.count
    If iAttrCount > 0 Then
        For i = 1 To iAttrCount
            If selClass.Attributes(i).Name = strItemName Then
                FindAttributeInClass = i
                Exit For
            End If
        Next
    End If
End Function

'Retrieve attribut from class
Private Function GetAttributeFromClass(ByVal selClass As RPClass, ByVal strItemName As String) As RPAttribute
    Dim i, iAttrCount As Integer
    
    iAttrCount = selClass.Attributes.count
    If iAttrCount > 0 Then
        For i = 1 To iAttrCount
            If selClass.Attributes(i).Name = strItemName Then
                GetAttributeFromClass = selClass.Attributes(i)
                Exit For
            End If
        Next
    End If
End Function

Public Function GetUniqueShapeName(strShapeName As String) As String
    Dim i As Integer, j As Integer
    Dim strUniqueShape As String, strNameOrig As String
    
    j = 1
    strNameOrig = strShapeName
    strUniqueShape = strShapeName
    GetUniqueShapeName = strUniqueShape
    'See if there is a shape by this name already
    Do
         If IsUniqueShapeName(strUniqueShape) Then
             GetUniqueShapeName = strUniqueShape
             Exit Do
         End If
         strUniqueShape = strNameOrig & "_" & CStr(j)
         j = j + 1
    Loop
End Function

Private Function IsUniqueShapeName(strShapeName As String) As Boolean
    Dim i As Integer
    Dim pDef As UserDefinedItemDef
    
    IsUniqueShapeName = True
    For i = 1 To m_collDef.count
        Set pDef = m_collDef(i)
        If Not pDef Is Nothing Then
            If pDef.GeShape = strShapeName Then
                IsUniqueShapeName = False
                Exit Function
            End If
        End If
    Next i
End Function

'========================================
' Helpers
'========================================
'-------------------------------
Private Function VERIFY_ERR() As Boolean
  ' Verify for the Err object
  ' Return True if OK
  VERIFY_ERR = True
  If Not err = 0 Then
      #If APP_DEBUG Then
        Dim strMsg As String
        strMsg = TypeName(Me) & ":VERIFY_ERR Failed:" & Error
        gMsgWnd.LogMessage strMsg
      #End If
    VERIFY_ERR = False
  End If
End Function


