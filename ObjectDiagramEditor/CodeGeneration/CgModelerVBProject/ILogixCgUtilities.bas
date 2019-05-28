Attribute VB_Name = "ILogixCgUtilities"
Option Explicit

#If using_ilogix Then
Global Projects As Collection
Global crtf As RichTextBox

' iLogix specific arguments
Global doc As RPApplication
'Private Const UML_EXT = ".rpy"
Private Const THE_APPLICATION As String = "rhapsody.Application"
Private m_frmMsg As frmLoadingMsg

Public rpyModelName As String
Public rpyModel As RPProject

'Public Function getUMLExt() As String
'    getUMLExt = UML_EXT
'End Function
Private Function chooseRPYModel(RPYModelDlg As CommonDialog, Optional rpyModelNameFromAddressField As String = "") As String
    On Error GoTo CancelHandler
    
    RPYModelDlg.DialogTitle = "Select Rhapsody project"
    RPYModelDlg.InitDir = ""
    RPYModelDlg.Filter = "rpy (*.rpy)|*.rpy"
    RPYModelDlg.FLAGS = cdlOFNHideReadOnly Or cdlOFNPathMustExist Or cdlOFNFileMustExist
    RPYModelDlg.FileName = rpyModelNameFromAddressField
    RPYModelDlg.ShowOpen
    chooseRPYModel = RPYModelDlg.FileName
    
CancelHandler:
    Exit Function
End Function

Private Function chooseRPYSaveModel(RPYModelDlg As CommonDialog, Optional rpyModelNameFromAddressField As String = "") As String
    On Error GoTo CancelHandler
    
    RPYModelDlg.DialogTitle = "Select Rhapsody project"
    RPYModelDlg.InitDir = ""
    RPYModelDlg.Filter = "rpy (*.rpy)|*.rpy"
    RPYModelDlg.FLAGS = cdlOFNHideReadOnly Or cdlOFNPathMustExist Or cdlOFNFileMustExist
    RPYModelDlg.FileName = rpyModelNameFromAddressField
    RPYModelDlg.ShowSave
    chooseRPYSaveModel = RPYModelDlg.FileName
    
CancelHandler:
    Exit Function
End Function

Private Function loadRPYModel(RPYModelDlg As CommonDialog, Optional rpyModelNameFromAddressField As String = "") As Boolean
    Dim rpyModelNameOLD As String
    
    On Error Resume Next
    rpyModelNameOLD = rpyModelName
'    rpyModelName = g_DrawingDefMgr.m_custDrawEditor.UMLProjectName
'    If rpyModelName = "" Then
        rpyModelName = chooseRPYModel(RPYModelDlg, rpyModelNameFromAddressField)
'    End If
    If rpyModelName = "" Then
        loadRPYModel = True         'Not a failure case.  ie User hit cancel
        rpyModelName = rpyModelNameOLD
        Exit Function
    End If
    
    DisplayStatusMessage "Loading UML Project..."

    ' close previous active project if last one exists
    If Not doc Is Nothing Then
        On Error GoTo RestartHandler
        If Not doc.activeProject Is Nothing Then
            doc.activeProject.Close
            Set doc.activeProject = Nothing
        End If
        
RestartHandler:
        err.Clear
        Set doc = CreateObject(THE_APPLICATION)
        If err.Number Then
            gMsgWnd.LogMessage "Failed to create Rhapsody Application Object.  Error: " & CStr(err.Number) & " - " & err.Description
            loadRPYModel = False
            DisplayStatusMessageClose
            Exit Function
        End If

    Else
        Set doc = CreateObject(THE_APPLICATION)
    End If
    
    err.Clear
    Screen.MousePointer = vbHourglass
    doc.openProject rpyModelName
    Screen.MousePointer = vbNormal
    If err.Number Then
        If Not doc.activeProject Is Nothing Then
            doc.activeProject.Close
            Set doc.activeProject = Nothing
        End If
        loadRPYModel = False
        DisplayStatusMessageClose
        Exit Function
    End If
    
    Set rpyModel = doc.activeProject
    loadRPYModel = True
    If err.Number Then
        gMsgWnd.LogMessage "Error: " & CStr(err.Number) & " Description: " & err.Description
    End If
    
    DisplayStatusMessageClose

    'Set the current UML project
'    If g_DrawingDefMgr.m_custDrawEditor.UMLProjectName <> rpyModelName Then
'        g_DrawingDefMgr.m_custDrawEditor.UMLProjectName = rpyModelName
'    End If
End Function

Private Function saveRPYModel(RPYModelDlg As CommonDialog, Optional rpyModelNameFromAddressField As String = "") As Boolean
    On Error Resume Next
    saveRPYModel = False
    If Not doc Is Nothing Then
        If Not doc.activeProject Is Nothing Then
            doc.activeProject.saveAs (rpyModelName)
            saveRPYModel = True
        Else
            MsgBox "No UML project currently loaded."
            Exit Function
        End If
    Else
        MsgBox "No UML project currently loaded."
        Exit Function
    End If
    If err.Number Then
        gMsgWnd.LogMessage "Failed to save UML project.  Error: " & CStr(err.Number) & " Description: " & err.Description
    End If
End Function

Private Function saveRPYModelAs(RPYModelDlg As CommonDialog, Optional rpyModelNameFromAddressField As String = "") As Boolean
    On Error Resume Next
    Dim saveModelName As String
    
    saveRPYModelAs = False
    If Not doc Is Nothing Then
        If Not doc.activeProject Is Nothing Then
            saveModelName = chooseRPYSaveModel(RPYModelDlg, rpyModelNameFromAddressField)
            If saveModelName <> "" Then
                doc.activeProject.saveAs (saveModelName)
                saveRPYModelAs = True
            End If
        Else
            MsgBox "No UML project currently loaded.", vbOKOnly, PROJECT_TITLE
            Exit Function
        End If
    Else
        MsgBox "No UML project currently loaded."
        Exit Function
    End If
    If err.Number Then
        gMsgWnd.LogMessage "Failed to save UML project.  Error: " & CStr(err.Number) & " Description: " & err.Description
    End If
End Function


Private Function closeRPYModel(RPYModelDlg As CommonDialog, Optional rpyModelNameFromAddressField As String = "") As Boolean
    Dim i As Integer
    
    On Error Resume Next
    closeRPYModel = False
    If Not doc Is Nothing Then
        If Not doc.activeProject Is Nothing Then
            doc.activeProject.Close
            If Not Projects Is Nothing Then
                For i = 1 To Projects.count
                  Projects.Remove (1)
                Next i
                Set Projects = Nothing
            End If
            closeRPYModel = True
         Else
            gMsgWnd.LogMessage "Can not close UML project.  No project currently loaded."
         End If
    End If
    rpyModel.Close
    rpyModelName = ""
    Set rpyModel = Nothing
End Function

Function GetUMLProjectName() As String
    Dim strModelName
    strModelName = StripPath(rpyModelName)
    GetUMLProjectName = strModelName
End Function

Function IsUMLProjectOpen() As Boolean
    On Error Resume Next
    If (doc Is Nothing) Or (doc.activeProject Is Nothing) Then
        IsUMLProjectOpen = False
    Else
        IsUMLProjectOpen = True
    End If
End Function

Function LoadRPYProject(RPYModelDlg As CommonDialog) As Boolean
'    DisplayStatusMessage "Loading UML Project..."
    LoadRPYProject = loadRPYModel(RPYModelDlg)
'    DisplayStatusMessageClose
End Function

Function SaveRPYProject(RPYModelDlg As CommonDialog) As Boolean
    SaveRPYProject = saveRPYModel(RPYModelDlg)
End Function

Function SaveRPYProjectAs(RPYModelDlg As CommonDialog) As Boolean
    SaveRPYProjectAs = saveRPYModelAs(RPYModelDlg)
End Function

Function CloseRPYProject(RPYModelDlg As CommonDialog) As Boolean
    CloseRPYProject = closeRPYModel(RPYModelDlg)
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
    End If
End Sub
Function GetXMLUDIDefs() As String
    Dim strXML As String
    Dim iPackages As Integer
    Dim iClasses As Integer
    Dim i, j As Integer
    
    On Error Resume Next
    strXML = ""
    If IsUMLProjectOpen() Then
        iPackages = doc.activeProject.Packages.count
        If iPackages > 0 Then
            strXML = "<UDIDefs xmlns='\\XMLData\ModelDefinition.xml'>"
            For i = 1 To iPackages
                Dim strProject As String
                Dim strPackage As String
                Dim k As Integer
                
                k = 1
                strProject = doc.activeProject.Name
                strPackage = doc.activeProject.Packages(i).Name
                iClasses = doc.activeProject.Packages(i).Classes.count
                If iClasses > 0 Then
                    For j = 1 To iClasses
                        Dim strClassXML As String
                        Dim strClass As String
                        Dim strID As String
                        Dim strName As String
                        Dim posClassName As Long
                        Dim posID As Long
                        
                        strClassXML = doc.activeProject.Packages(i).Classes(j).getPropertyValue("ShapeDefinitions.Class.UDIDefCollection")
                        If strClassXML <> "None" Then
                            Dim bAdd As Boolean
                            Dim strIDVal As String
                            Dim SearchChar, strTemp As String
                            strClass = doc.activeProject.Packages(i).Classes(j).Name        'Current UML Class Name
                            strID = doc.activeProject.Packages(i).Classes(j).GUID           'Current UML GUID
                            posClassName = InStr(1, strClassXML, "ClassName=")
                            posID = InStr(1, strClassXML, "ID=")
                             
                            strIDVal = GetUDIDefAttribute(strClassXML, "ID")
                            If strIDVal = "" Then
                                strClassXML = Replace(strClassXML, "ID=" & Chr(34) & Chr(34), "", 1, 1)
                                posID = -1
                            End If
                            
                            '---------------------------------------------------------------------------------------------------
                            'TEMPORARY: REMOVE THIS ONCE ALL PROJECTS HAVE BEEN PORTED TO NEW SCHEME OF USING GUIDS FOR UDIDef NAMES
                            strName = GetUDIDefAttribute(strClassXML, "Name")
                            If (Len(strName) > 0) And (Len(strName) <> GUID_LENGTH) Then
                                Dim strGUID As String
                     
                                strGUID = GetGUID()
                                strClassXML = Replace(strClassXML, strName, strGUID, 1, 9999)
                                gMsgWnd.LogMessage "UDIDef's '" & strName & "' Name changed to GUID '" & strGUID & "'."
                                If Not FindAndRenameUDIDefReference(strName, strGUID) Then
                                    gMsgWnd.LogMessage "Failed to rename UDIDef " & strName & " to " & strGUID & "."
                                End If
                                g_DrawingDefMgr.IsDirty = True
                            End If
                            '---------------------------------------------------------------------------------------------------
                            
                            'Get the ClassName and GUID storred in the UDIDef and compare them
                            If (posClassName > 0) And (posID > 0) Then
                                bAdd = CompareClassNameAndID(strClass, strID, strClassXML, k, doc.activeProject.Packages(i).Classes(j))
                                If bAdd Then
                                    strTemp = "<UDIDef ProjectName='" & strProject & "' PackageName='" & strPackage & "'"
                                    strClassXML = Replace(strClassXML, "<UDIDef", strTemp, 1, 9999)
                                    strXML = strXML + strClassXML
                                End If
                            Else       'If ClassName and\or ID didn't exit, use the current ones
                                strTemp = "<UDIDef ProjectName='" & strProject & "' PackageName='" & strPackage & "'"
                                If posClassName <= 0 Then
                                    strTemp = strTemp & " ClassName='" & strClass & "'"
                                End If
                                If posID <= 0 Then
                                    strTemp = strTemp & " ID='" & strID & "'"
                                End If
                                strClassXML = Replace(strClassXML, "<UDIDef", strTemp, 1, 9999)
                                strXML = strXML + strClassXML
                            End If
                        End If
                    Next
                End If
            Next
            strXML = strXML + "</UDIDefs>"
        End If
    End If
    GetXMLUDIDefs = strXML
End Function

'---------------------------------------------------------------------------------------------------
'TEMPORARY: REMOVE THIS ONCE ALL PROJECTS HAVE BEEN PORTED TO NEW SCHEME OF USING GUIDS FOR UDIDef NAMES
Private Function FindAndRenameUDIDefReference(strOldName As String, strGUID As String) As Boolean
    Dim i As Integer
    Dim custDrawing As CustomDrawing
    Dim UDIItems As UserDefinedItems
    Dim UDIItem As UserDefinedItem
    
    FindAndRenameUDIDefReference = True
    If Not g_DrawingDefMgr.m_custDrawEditor Is Nothing Then
        Set custDrawing = g_DrawingDefMgr.m_custDrawEditor.CustomDrawing()
        If custDrawing Is Nothing Then
            FindAndRenameUDIDefReference = False
            Exit Function
        End If
        Set UDIItems = custDrawing.UDIItems()
        If UDIItems Is Nothing Then
            FindAndRenameUDIDefReference = False
            Exit Function
        End If
        
        For i = 1 To UDIItems.Items.count
            Set UDIItem = UDIItems.Items(i)
            If Not UDIItem Is Nothing Then
                If UDIItem.m_strDefObjectName = strOldName Then
                    UDIItem.m_strDefObjectName = strGUID
                End If
            End If
        Next
    End If
End Function
'---------------------------------------------------------------------------------------------------
Function SetXMLUDIDefs(ByVal szXML, strPackageName, strClassName) As Boolean
    Dim aDoc As DOMDocument
    Dim aNodeList As IXMLDOMNodeList
    Dim aItem As IXMLDOMElement
    Dim i, j As Long
    
    On Error Resume Next
    SetXMLUDIDefs = True
   
    If IsUMLProjectOpen() Then
      For i = 1 To doc.activeProject.Packages.count
        If strPackageName = doc.activeProject.Packages(i).Name Then
            For j = 1 To doc.activeProject.Packages(i).Classes.count
              If strClassName = doc.activeProject.Packages(i).Classes(j).Name Then
                doc.activeProject.Packages(i).Classes(j).setPropertyValue "ShapeDefinitions.Class.UDIDefCollection", szXML
                Exit For
              End If
            Next j
            Exit For
        End If
      Next i
    Else
      SetXMLUDIDefs = False
    End If
End Function

Private Function CompareClassNameAndID(strClass As String, strID As String, strXML As String, ByRef k As Integer, ByRef Class As RPClass) As Boolean
'#If 0 Then ' this code does not work.  I created 10 UDIs, and the Id wasn't stored with any of them.  When I
    
    Dim bIDPos As Long
    Dim bClassNamePos As Long
    Dim iUBound As Integer
    Dim i As Integer
    Dim strUDIDef As String
    Dim strNewUDIDef As String
    
    On Error GoTo Error_Handler
    CompareClassNameAndID = False
    bIDPos = InStr(1, strXML, strID)
    bClassNamePos = InStr(1, strXML, strClass & Chr(34))
    
    strUDIDef = GetUDIDefAttribute(strXML, "Name")
    If IsEmpty(strUDIDef) Then Exit Function
    
           ' reopened the project, this code renamed all my UDIs, and refused to load them.
    
    If (bIDPos > 0) And (bClassNamePos) > 0 Then
        CompareClassNameAndID = True
    Else
        Dim aUDIDef
        aUDIDef = Split(strUDIDef, "_")
        iUBound = UBound(aUDIDef)
        If IsNumeric(aUDIDef(iUBound)) Then             'This is most likely an already renamed class...although the user could have created a class with _# at the end
            CompareClassNameAndID = True
            Exit Function
        ElseIf bIDPos <= 0 And bClassNamePos > 0 Then   'ID changed but class name did not.  This shouldn't happen, but handle it just in case
            strNewUDIDef = strUDIDef + "_" + CStr(k)    'Rename the UDIDef
            ChangedUDIDefAttributes strXML, "Name", strNewUDIDef, Class
            k = k + 1
            gMsgWnd.LogMessage "Class '" & strClass & "' detected with wrong properties.  The shape definition '" & strUDIDef & " ' was renamed to '" & strNewUDIDef & "'."
            CompareClassNameAndID = True
        ElseIf bClassNamePos <= 0 And bIDPos <= 0 Then   'New GUID and ClassName.  User copied the class item to a different class.
            strNewUDIDef = strUDIDef + "_" + CStr(k)     'Rename the new instance
            ChangedUDIDefAttributes strXML, "Name", strNewUDIDef, Class
            k = k + 1
            gMsgWnd.LogMessage "Class '" & strClass & "' detected as a copied class.  The shape definition '" & strUDIDef & " ' was renamed to '" & strNewUDIDef & "'."
            CompareClassNameAndID = True
        ElseIf bClassNamePos <= 0 And bIDPos > 0 Then    'User Renamed the class
            ChangedUDIDefAttributes strXML, "ClassName", strClass, Class  'Update the UDIDef storred name
            CompareClassNameAndID = True
        End If
        doc.activeProject.Save
    End If

'#Else
'  CompareClassNameAndID = True
'#End If

    Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Failed to load class '" & strClass & "'.  The may be a discrepancy between the class name or ID and the 'ShapeDefinitions.Class.UDIDefCollection' property."
End Function

Private Function GetUDIDefAttribute(strXML As String, strName As String) As String
    Dim aXML
    Dim iUBound As Integer
    Dim i As Integer
    Dim strAttributeName As String
    
    GetUDIDefAttribute = ""
    aXML = Split(strXML)
    iUBound = UBound(aXML)
    strAttributeName = CStr(strName & "=")
    
    For i = 0 To iUBound
        If InStr(1, aXML(i), strAttributeName) > 0 Then
            aXML(i) = Replace(aXML(i), strAttributeName, "")
            aXML(i) = Replace(aXML(i), Chr(34), "")
            GetUDIDefAttribute = aXML(i)
            Exit For
        End If
    Next
End Function

Private Sub ChangedUDIDefAttributes(ByRef strXML As String, strAttribName As String, strAttribNewValue As String, ByRef Class As RPClass)
    Dim strOldAttribValue As String
    
    strOldAttribValue = GetUDIDefAttribute(strXML, strAttribName)
    If strOldAttribValue <> "" Then
        strXML = Replace(strXML, strOldAttribValue, strAttribNewValue)
        Class.setPropertyValue "ShapeDefinitions.Class.UDIDefCollection", strXML
    End If
End Sub


' Define attributes as Var, RPar, IPar, Connector, or Model
' Define methods as continuous, discontinuous, or reset
' Define equations for states, read the default out of the machine
' Define the triggers and actions for transitions,
' read the source state and event name out of machine
' Implement a parser for the triggers so discontinuity equations
' can be expressed directly
' eg: Height > 25 && x < 20 ==> g1() && g2() where
' g1(): *res = Height - 25;
' g2(): *res = 20 - x;

Sub GetProjects(ProjectList As Collection, Projects As Object, Optional CommDlg As CommonDialog)
    Dim aProject As rtsProject
    Dim aClass As rtsClass
    Dim szProjectName As String
    Dim nLoc As Long
    
    If ProjectList Is Nothing Then Set ProjectList = New Collection
    
    If IsUMLProjectOpen() Then
      Set aProject = New rtsProject
      Set aProject.Project = rpyModel
      On Error Resume Next
      ProjectList.Add aProject, rpyModelName
    Else
      If Not CommDlg Is Nothing Then
        If LoadRPYProject(CommDlg) Then
          Set aProject = New rtsProject
          Set aProject.Project = rpyModel
          On Error Resume Next
          ProjectList.Add aProject, rpyModel.Name
        End If
      End If
    End If
End Sub


Sub GetPackages(Project As Object, PackageList As Collection)
    On Error Resume Next
    
    Dim aPackage As rtsPackage
    Dim aClass As rtsClass
    Dim ClassName As String
    Dim arpProject As RPProject
    Dim arpPackages As RPCollection
    Dim aRpPackage As RPPackage
    Dim arpProjectClasses As RPCollection
    Dim aRPClass As RPClass
    Dim i As Long
    
    If PackageList Is Nothing Then Set PackageList = New Collection
    Set arpProject = Project
    
    Set arpPackages = arpProject.Packages
    For i = 1 To arpPackages.count
      Set aRpPackage = arpPackages.Item(i)
      Set aPackage = New rtsPackage
      Set aPackage.obj = aRpPackage
      aPackage.Name = aRpPackage.Name
      aPackage.Index = i
      Set arpProjectClasses = aRpPackage.Classes
      For Each aRPClass In arpProjectClasses
        Set aClass = New rtsClass
        Set aClass.Class = aRPClass
        ClassName = LTrim(RTrim(aRPClass.Name))
        ClassName = Replace(ClassName, " ", "_")
        aClass.PackageName = aRpPackage.Name
        aClass.Name = ClassName
        err = 0
        aPackage.Classes.Add aClass, aClass.Name
        If err <> 0 Then
          aPackage.Classes.Add aClass
        End If
      Next
      PackageList.Add aPackage, aPackage.Name
    Next
    
End Sub

Public Sub GetTypeDefs(simClass As rtsClass, defs As Collection)
  Dim aRPType As RPType
  Dim aPackage As rtsPackage
  Dim aRpPackage As RPPackage
  Dim loc As Long
  Dim aType As CgType
  Dim aRPClass As RPClass
  
  Set defs = New Collection
  
  On Error Resume Next
  Set aPackage = simClass.Project.Packages(simClass.PackageName)
  If aPackage Is Nothing Or err <> 0 Then
    Exit Sub
  End If
  
  On Error GoTo 0
  Set aRpPackage = aPackage.obj
  
  For Each aRPType In aRpPackage.types
    If aRPType.metaClass = "Type" And InStr(1, aRPType.declaration, "#define") = 0 Then
      Set aType = New CgType
      aType.Name = aRPType.Name
      aType.ClassName = aRPType.declaration
      loc = InStr(1, aType.ClassName, "typedef ")
      If loc > 0 Then
        aType.ClassName = Mid(aType.ClassName, loc + Len("typedef "))
      End If
      loc = InStr(1, aType.ClassName, "<")
      If loc > 0 Then
        aType.ClassName = Left(aType.ClassName, loc - 1)
      End If
      loc = InStr(1, aType.ClassName, "%")
      If loc > 0 Then
        aType.ClassName = Left(aType.ClassName, loc - 1)
      End If
      aType.ClassName = RTrim(LTrim(aType.ClassName))
      Set aType.obj = aRPType
      ' find class / base class
      For Each aRPClass In aRpPackage.Classes
        If aRPClass.Name = aType.ClassName Then
          Set aType.classObj = aRPClass
          aType.IsClass = True
          GetBaseClasses aRPClass, aType.BaseClasses
          Exit For
        End If
      Next
      
      defs.Add aType, aType.Name
    End If
  Next
End Sub

Sub GetClassVariables(classInfo As rtsClass, ByVal prefix As String, varList As Collection, Optional bExpandConnectors As Boolean = True)
  Dim aInfo As rtsClass
  Dim aAttr As CgAttribute
  Dim aCompositeAttr As CgAttribute
  Dim szDataType As String
  Dim nPos As Long
  
  On Error GoTo Error_Handler
  
  If varList Is Nothing Then Set varList = New Collection
    
  For Each aAttr In classInfo.Attributes
    If aAttr.dataType = "double" And aAttr.sType = idxAttr_Variable And aAttr.bSim Then
      Set aCompositeAttr = New CgAttribute
      aAttr.Copy aCompositeAttr
      aCompositeAttr.Name = prefix & aAttr.Name
      On Error Resume Next
      varList.Add aCompositeAttr, aCompositeAttr.Name
      If err <> 0 Then
        Debug.Print "Get Class Variables error: Couldn't add variable '" & aCompositeAttr.Name & "' due to the following error: " & err.Description
      End If
      On Error GoTo Error_Handler
    ElseIf aAttr.sType = idxAttr_Connector Or aAttr.sType = idxAttr_Model Or aAttr.sType = idxAttr_Struct Then
      szDataType = aAttr.dataType
      nPos = InStr(1, szDataType, "*")
      If nPos > 0 Then
        szDataType = LTrim(RTrim(Left(szDataType, nPos - 1)))
      End If
      If GetClassInfo(classInfo.Project, aAttr.PackageName, szDataType, aInfo) Then
        If bExpandConnectors = True Then GetClassVariables aInfo, prefix & aAttr.Name & ".", varList
      Else
        gMsgWnd.LogMessage "Could not retrieve variables for class '" & szDataType & "' in package: '" & aAttr.PackageName & "'"
      End If
    End If
  Next
  
  Exit Sub
Error_Handler:
  gMsgWnd.LogMessage "Get class variables error: " & err.Description
End Sub

#If 0 Then
Sub GetClasses(Project As Object, ClassList As Collection)
    On Error Resume Next
    
    Dim aClass As rtsClass
    Dim ClassName As String
    Dim arpProject As RPProject
    Dim arpPackages As RPCollection
    Dim aRpPackage As RPPackage
    Dim arpProjectClasses As RPCollection
    Dim aRPClass As RPClass
    
    If ClassList Is Nothing Then Set ClassList = New Collection
    Set arpProject = Project
    
    Set arpPackages = arpProject.Packages
    For Each aRpPackage In arpPackages
      Set arpProjectClasses = aRpPackage.Classes
      For Each aRPClass In arpProjectClasses
        Set aClass = New rtsClass
        Set aClass.Class = aRPClass
        ClassName = LTrim(RTrim(aRPClass.Name))
        ClassName = Replace(ClassName, " ", "_")
        aClass.PackageName = aRpPackage.Name
        aClass.Name = ClassName
        err = 0
        ClassList.Add aClass, aClass.Name
        If err <> 0 Then
          ClassList.Add aClass
        End If
      Next
    Next
    
End Sub
#End If

Function GetClassInfo(Project As rtsProject, PackageName As String, ClassName As String, aInfo As rtsClass) As Boolean
  Dim szXML As String
  Dim ModelType As Long
  Dim temp As rtsClass
  Dim Classes As Collection
  Dim Packages As Collection
  Dim aPackage As rtsPackage
  
  If Project Is Nothing Then
    GetClassInfo = False
    Exit Function
  End If
  
  Set aInfo = Nothing
  Set Packages = Project.Packages
  On Error Resume Next
  Set aPackage = Packages(PackageName)
  If Not aPackage Is Nothing Then
    Set Classes = aPackage.Classes
    Set aInfo = Classes(ClassName)
    If Not aInfo Is Nothing Then
      Set aInfo.Project = Project
      aInfo.PackageName = aPackage.Name
    End If
  End If
  
  If aInfo Is Nothing Then Exit Function
    
  If Not aInfo.bInitialized Then
    GetClassAssociations aInfo, aInfo.Associations
    GetAttributesFromAssociations aInfo, aInfo.Associations, aInfo.Attributes
    GetClassAttributes aInfo, aInfo.Attributes
    GetClassOperations aInfo, aInfo.Operations
    GetClassStates aInfo, aInfo.States, aInfo.Transitions
    
    aInfo.Load
    If aInfo.ModelType < 1 Then
      aInfo.ModelType = idxClassType_NonSimulation
    End If
        
    aInfo.bInitialized = True
  End If
  
  GetClassInfo = True
End Function

Sub GetClassAssociations(aClass As rtsClass, ClassAssociations As Collection)
  
  On Error GoTo Error_Handler
  If ClassAssociations Is Nothing Then Set ClassAssociations = New Collection
  
  Dim aAssociation As RPRelation
  Dim AssociationList As RPCollection
  Dim Descriptor As String
  Dim aAssoc As CgAssociation
  Dim ClassName As String
  Dim aRPClass As RPClass
  Dim szCg As String
  
  ClassName = aClass.Name
  Set aRPClass = aClass.Class
  
  Set AssociationList = aRPClass.getRelationsIncludingBases
  For Each aAssociation In AssociationList
    Descriptor = LTrim(RTrim(aAssociation.Description))
    Set aAssoc = New CgAssociation
    aAssoc.ClassName = aAssociation.Owner.Name  ' className
    aAssoc.Name = LTrim(RTrim(aAssociation.Name))
    aAssoc.Name = Replace(aAssoc.Name, " ", "_")

    aAssoc.Description = Descriptor
    Set aAssoc.obj = aAssociation
    aAssoc.Load
    aAssoc.StartClass = aAssociation.ofClass.Name
    aAssoc.StartClass = Replace(aAssoc.StartClass, " ", "_")
    If Not aAssociation.ofClass.Owner Is Nothing Then
      aAssoc.StartPackage = aAssociation.ofClass.Owner.Name
    End If
    aAssoc.StartRole = aAssociation.relationRoleName
    aAssoc.StartQualifier = aAssociation.qualifier
    aAssoc.StartMultiplicity = aAssociation.Multiplicity

    aAssoc.EndClass = aAssociation.otherClass.Name
    aAssoc.EndClass = Replace(aAssoc.EndClass, " ", "_")
    If Not aAssociation.otherClass.Owner Is Nothing Then
      aAssoc.EndPackage = aAssociation.otherClass.Owner.Name
    End If
    aAssoc.EndRole = ""
    aAssoc.EndQualifier = ""
    aAssoc.EndMultiplicity = ""

    'Public Aggregate As String          ' Aggregate class end {START, END, NONE} r/w
    'Public Navigation                   ' implementation: {start-end, end-start, bi-directional, none}
    'If aAssociation.relationType <> "Aggregation" Then
    '  aAssoc.Aggregate = "NONE"
    'Else
      aAssoc.Aggregate = "START"
      aAssoc.Navigation = "start-end"
    'End If
    
    ClassAssociations.Add aAssoc
  Next
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Class Associations retrieval Error: " & err.Description
End Sub

Public Sub GetAttributesFromAssociations(aClass As rtsClass, ClassAssociations As Collection, ClassAttributes As Collection)
'className:         CMass
'Name:              Associates
'Desc:
'StartClass:        CMass
'StartRole:         n
'StartQualifier:
'StartMultiplicity: 1
'EndClass:          CRigidConnector
'EndRole:           CRigidConnector
'EndQualifier:
'EndMultiplicity:   1
'Aggregate:         start
'Navigation:        start-end

  Dim aAssoc As CgAssociation
  Dim aAttr As CgAttribute
  
  On Error Resume Next
  For Each aAssoc In ClassAssociations
    ' convert aggregated members to attributes
    ' only add aggregate associations where the source class is the end class
    If UCase(aAssoc.Aggregate) = "START" And aAssoc.ClassName = aAssoc.StartClass And UCase(aAssoc.Navigation) = "START-END" Then
      Set aAttr = New CgAttribute
      aAttr.bAggregate = True
      aAttr.ClassName = aAssoc.ClassName
      aAttr.Name = aAssoc.StartRole
      aAttr.Description = aAssoc.Description
      If aAssoc.obj.relationType = "Composition" Then
        aAttr.dataType = aAssoc.EndClass
      Else
        aAttr.dataType = aAssoc.EndClass & "*"
      End If
      aAttr.PackageName = aAssoc.EndPackage
      aAttr.Access = "public"
      If IsNumeric(aAssoc.EndMultiplicity) Then
        aAttr.Multiplicity = CLng(aAssoc.EndMultiplicity)
      Else
        aAttr.Multiplicity = 1
      End If
      
      Set aAttr.obj = aAssoc.obj
      aAttr.bSim = aAssoc.bSim
      aAttr.OnCg = aAssoc.OnCg
      aAttr.sType = aAssoc.sType
      aAttr.sSubType = aAssoc.sSubType
      aAttr.dim1 = aAssoc.dim1
      aAttr.dim2 = aAssoc.dim2
      aAttr.DefaultValue = "NULL"
      ClassAttributes.Add aAttr, aAttr.Name
      
    ElseIf UCase(aAssoc.Aggregate) = "END" And aAssoc.ClassName = aAssoc.EndClass And UCase(aAssoc.Navigation) = "END-START" Then
      Set aAttr = New CgAttribute
      aAttr.ClassName = aAssoc.ClassName
      aAttr.Name = aAssoc.EndRole
      aAttr.Description = aAssoc.Description
      If aAssoc.obj.relationType = "Composition" Then
        aAttr.dataType = aAssoc.StartClass
      Else
        aAttr.dataType = aAssoc.StartClass & "*"
      End If
      aAttr.PackageName = aAssoc.StartPackage
      aAttr.Access = "Public"
      If IsNumeric(aAssoc.StartMultiplicity) Then
        aAttr.Multiplicity = CLng(aAssoc.EndMultiplicity)
      Else
        aAttr.Multiplicity = 1
      End If
      
      Set aAttr.obj = aAssoc.obj
      aAttr.bSim = aAssoc.bSim
      aAttr.OnCg = aAssoc.OnCg
      aAttr.sType = aAssoc.sType
      aAttr.sSubType = aAssoc.sSubType
      aAttr.dim1 = aAssoc.dim1
      aAttr.dim2 = aAssoc.dim2
      aAttr.DefaultValue = "NULL"
      ClassAttributes.Add aAttr, aAttr.Name
      
    End If
  Next
End Sub


Sub GetClassAttributes(aClass As rtsClass, ClassAttributes As Collection)
  Dim aRPClass As RPClass
  Dim arpAttribute As RPAttribute
  Dim nStart As Long
  Dim nLastStart As Long
  Dim aName As String
  Dim AttributeList As RPCollection
  Dim aAttr As CgAttribute
  Dim ClassName As String
  
  On Error Resume Next
  ClassName = aClass.Name
  Set aRPClass = aClass.Class
  
  Set AttributeList = aRPClass.getAttributesIncludingBases
  For Each arpAttribute In AttributeList
    Dim tempAttrib As CgAttribute
    Dim iPos As Integer
        
    iPos = -1
    Set tempAttrib = FindAttributeInCollection(ClassAttributes, arpAttribute.Name, iPos)
    'Attribute may already exist when shape xml definitions were loaded.
    If tempAttrib Is Nothing Then
        Set aAttr = New CgAttribute
        Set aAttr.obj = arpAttribute
        aAttr.ClassName = arpAttribute.Owner.Name  ' className
        aAttr.Name = arpAttribute.Name
        aAttr.Description = arpAttribute.Description
        aAttr.Access = arpAttribute.visibility
        If (arpAttribute.typeOf.Name <> "") Then            'Pre-defined type used
            aAttr.dataType = arpAttribute.typeOf.Name
        Else                                                'User Defined data type
            aAttr.dataType = arpAttribute.typeOf.declaration
            aAttr.dataType = Replace(aAttr.dataType, "%s", "")   'Strip off %s
            aAttr.dataType = LTrim(RTrim(aAttr.dataType))
        End If
    
        If arpAttribute.DefaultValue <> "" Then
            Select Case arpAttribute.DefaultValue
            Case "false"  ' False
              aAttr.Value = 0
            Case "true"  ' True
              aAttr.Value = 1
            Case Else
              aAttr.Value = CDbl(arpAttribute.DefaultValue)
          End Select
        End If
        
        aAttr.Load
        On Error Resume Next
        ClassAttributes.Add aAttr, aAttr.Name
        If err.Number <> 0 Then
          Debug.Print "Error adding attributes: " & arpAttribute.Name & ", " & arpAttribute.typeOf.Name
        End If
    End If
  Next
End Sub

Public Function ItemExists(strClass As String, strClassID As String, strItemName As String, strItemID As String, itemType As Long) As Boolean
    On Error Resume Next
    Dim aClass As rtsClass
    Dim ClassName As String
    Dim rtsProject As rtsProject
    Dim rtsPackage As rtsPackage
    Dim rtsClass As rtsClass
    Dim aAttrib As CgAttribute
    Dim aOper As CgOperation
    Dim i As Integer, j As Integer, k As Integer
    
    ItemExists = True
    
    For i = 1 To Projects.count
        If Projects(i).Name = doc.activeProject.Name Then
            Set rtsProject = Projects(i)
            Exit For
        End If
    Next i
    
    If rtsProject Is Nothing Then Exit Function
       
    For Each rtsPackage In rtsProject.Packages
      For Each rtsClass In rtsPackage.Classes
        If rtsClass.Name = strClass Or rtsClass.Class.GUID = strClassID Then
            If itemType = idxItemType_Attribute Then
                For Each aAttrib In rtsClass.Attributes
                    If aAttrib.Name = strItemName Or aAttrib.obj.GUID = strItemID Then Exit Function 'Item found
                Next
            ElseIf itemType = idxItemType_Operation Then
                For Each aOper In rtsClass.Operations
                    If aOper.Name = strItemName Or aOper.obj.GUID = strItemID Then Exit Function     'Item found
                Next
            End If
        End If
      Next
    Next
    
    ItemExists = False
End Function

Public Function FindClass(strClass As String, strClassID As String) As RPClass
    On Error Resume Next
    Dim aClass As rtsClass
    Dim ClassName As String
    Dim arpProject As RPProject
    Dim arpPackages As RPCollection
    Dim aRpPackage As RPPackage
    Dim arpProjectClasses As RPCollection
    Dim aRPClass As RPClass
    Dim i As Integer, j As Integer, k As Integer
    
    For i = 1 To Projects.count
        If Projects(i).Name = doc.activeProject.Name Then
            Set arpProject = Projects(i).Project
            Exit For
        End If
    Next i
    
    If arpProject Is Nothing Then Exit Function
       
    Set arpPackages = arpProject.Packages
    For Each aRpPackage In arpPackages
      Set arpProjectClasses = aRpPackage.Classes
      For Each aRPClass In arpProjectClasses
        If aRPClass.Name = strClass Or aRPClass.GUID = strClassID Then
            Set FindClass = aRPClass
            Exit Function
        End If
      Next
    Next
End Function

Private Function FindAttributeInCollection(ClassAttributes As Collection, strAttribName, ByRef iPos As Integer) As CgAttribute
    Dim aAttrib As CgAttribute
    Dim i, iAttribs As Integer
    
    Set FindAttributeInCollection = Nothing
    iAttribs = ClassAttributes.count
    For i = 1 To iAttribs
        Set aAttrib = ClassAttributes(i)
        If strAttribName = aAttrib.Name Then
            Set FindAttributeInCollection = aAttrib
            iPos = i
            Exit For
        End If
    Next
End Function

Sub GetBaseClasses(aRPClass As RPClass, BaseClasses As Collection)
  Dim Generalizations As RPCollection
  Dim Generalization As RPGeneralization
  Dim BaseClass As RPClass
  
  On Error GoTo Error_Handler
  If BaseClasses Is Nothing Then Set BaseClasses = New Collection
  
  Set Generalizations = aRPClass.Generalizations
  For Each Generalization In Generalizations
    Set BaseClass = Generalization.BaseClass
    BaseClasses.Add BaseClass
    GetBaseClasses BaseClass, BaseClasses
  Next
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Base Class retrieval Error: " & err.Description
End Sub

Sub GetClassOperations(aClass As rtsClass, classOperations As Collection)
  If classOperations Is Nothing Then Set classOperations = New Collection
  
  Dim aRPClass As RPClass
  Dim arpOperation As RPOperation
  Dim Operations As RPCollection
  Dim aOp As CgOperation

  Dim i As Long
  Dim ClassName As String
  Dim Pars As RPCollection
  Dim aPar As RPArgument
  Dim aAttr As CgAttribute
  Dim nLoc As Long
  
  On Error GoTo Error_Handler
  
  ClassName = aClass.Name
  Set aRPClass = aClass.Class
  Set Operations = aRPClass.Operations
  
  i = 0
  For Each arpOperation In Operations
    Set aOp = New CgOperation
    Set aOp.obj = arpOperation
    aOp.Load
    
    aOp.ClassName = arpOperation.Owner.Name
    aOp.Name = arpOperation.Name
    aOp.Description = LTrim(RTrim(arpOperation.Description))
    aOp.Access = arpOperation.visibility
    If Not arpOperation.ReturnType Is Nothing Then
      aOp.ReturnType = arpOperation.ReturnType.Name
      If aOp.ReturnType = "" Then
        aOp.ReturnType = arpOperation.ReturnType.declaration
        nLoc = InStr(1, aOp.ReturnType, "%s")
        If nLoc > 0 Then aOp.ReturnType = LTrim(RTrim(Left(aOp.ReturnType, nLoc - 1)))
      End If
    End If
    
    ' compensate for Void
    If UCase(aOp.ReturnType) = "VOID" Then aOp.ReturnType = "void"
    aOp.Body = arpOperation.Body
    Set Pars = arpOperation.Arguments
    For Each aPar In Pars
      Set aAttr = New CgAttribute
      aAttr.dataType = aPar.typeOf.Name
      If aAttr.dataType = "" Then
        aAttr.dataType = aPar.declaration
        nLoc = InStr(1, aAttr.dataType, "%s")
        If nLoc > 0 Then aAttr.dataType = LTrim(RTrim(Left(aAttr.dataType, nLoc - 1)))
      End If
      aAttr.Name = aPar.Name
      aAttr.Mechanism = aPar.argumentDirection
      aOp.Parameters.Add aAttr
    Next
    
    Set aOp.obj = arpOperation
    aOp.order = i
    i = i + 1
    'Remove old oe if it already exists
     On Error Resume Next
     Set aOp = classOperations(aOp.Name)
     If Not aOp Is Nothing Then
        classOperations.Remove aOp.Name
     End If

    classOperations.Add aOp, aOp.Name
  Next
  
  Dim BaseClasses As Collection
  Dim BaseClass As RPClass
  
  GetBaseClasses aClass.Class, BaseClasses
  For Each BaseClass In BaseClasses
    ClassName = LTrim(RTrim(BaseClass.Name))
    ClassName = Replace(ClassName, " ", "_")
    Set Operations = BaseClass.Operations
    For Each arpOperation In Operations
      Set aOp = New CgOperation
      Set aOp.obj = arpOperation
      aOp.Load
      
      aOp.ClassName = ClassName
      aOp.Name = arpOperation.Name
      aOp.Description = LTrim(RTrim(arpOperation.Description))
      aOp.Access = arpOperation.visibility
      If Not arpOperation.ReturnType Is Nothing Then
        aOp.ReturnType = arpOperation.ReturnType.Name
        If aOp.ReturnType = "" Then
          aOp.ReturnType = arpOperation.ReturnType.declaration
          nLoc = InStr(1, aOp.ReturnType, "%s")
          If nLoc > 0 Then aOp.ReturnType = LTrim(RTrim(Left(aOp.ReturnType, nLoc - 1)))
        End If
      End If
      
      ' compensate for Void
      If UCase(aOp.ReturnType) = "VOID" Then aOp.ReturnType = "void"
      aOp.Body = arpOperation.Body
      Set Pars = arpOperation.Arguments
      For Each aPar In Pars
        Set aAttr = New CgAttribute
        aAttr.dataType = aPar.typeOf.Name
        If aAttr.dataType = "" Then
          aAttr.dataType = aPar.declaration
          nLoc = InStr(1, aAttr.dataType, "%s")
          If nLoc > 0 Then aAttr.dataType = LTrim(RTrim(Left(aAttr.dataType, nLoc - 1)))
        End If
        aAttr.Name = aPar.Name
        aAttr.Mechanism = aPar.argumentDirection
        aOp.Parameters.Add aAttr
      Next
      
      Set aOp.obj = arpOperation
      aOp.order = i
      i = i + 1
      On Error Resume Next
      classOperations.Add aOp, aOp.Name
    Next
  Next
  
  Exit Sub
Error_Handler:
  Debug.Print "GetClassOperations error: " & err.Number & ", " & err.Description
  gMsgWnd.LogMessage "GetClassOperations error: " & err.Number & ", " & err.Description
  Resume Next
End Sub

Sub GetClassStates(SelectedClass As rtsClass, ClassStates As Collection, ClassTransitions As Collection)
  Dim iState As Long
  Dim iTrans As Long
  Dim aRPClass As RPClass
  Dim BaseClasses As Collection
  
  On Error GoTo Error_Handler
  If ClassStates Is Nothing Then Set ClassStates = New Collection
  If ClassTransitions Is Nothing Then Set ClassTransitions = New Collection
  
  iState = 0
  iTrans = 0
  
  Set aRPClass = SelectedClass.Class
  GetClassStates_Sub aRPClass, SelectedClass.Operations, ClassStates, ClassTransitions, iState, iTrans
  
  Set BaseClasses = New Collection
  GetBaseClasses aRPClass, BaseClasses
  For Each aRPClass In BaseClasses
    GetClassStates_Sub aRPClass, SelectedClass.Operations, ClassStates, ClassTransitions, iState, iTrans
  Next
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Class State retrieval Error: " & err.Description
End Sub

Sub GetClassStates_Sub(aRPClass As RPClass, Operations As Collection, States As Collection, Transitions As Collection, iState As Long, iTrans As Long)
  Dim ClassName As String
  Dim i As Long
  Dim arpStateChart As RPStatechart
  Dim aItem As RPModelElement
  Dim arpState As RPState
  Dim arpTransition As RPTransition
  Dim aCgState As CgState
  Dim aCgTrans As CgTransition
  Dim arpTransColl As RPCollection
  Dim Items As RPCollection
  Dim BaseClasses As Collection
  Dim cls As RPClass
  
  On Error GoTo Error_Handler
  ClassName = LTrim(RTrim(aRPClass.Name))
  ClassName = Replace(ClassName, " ", "_")
  
  Set arpStateChart = aRPClass.statechart
  If arpStateChart Is Nothing Then Exit Sub
  
  Set Items = arpStateChart.getNestedElementsRecursive
  For Each aItem In Items
    If aItem.metaClass = "State" And aItem.Name <> "ROOT" Then
      Set arpState = aItem
      Set aCgState = New CgState
      
      aCgState.Name = LTrim(RTrim(aItem.Name))
      aCgState.ClassName = ClassName
      aCgState.order = iState
      Set aCgState.obj = arpState
      aCgState.Load Operations
      aCgState.entryAction = arpState.entryAction
      aCgState.exitAction = arpState.exitAction
      
      Set arpTransColl = arpState.getInTransitions
      For Each arpTransition In arpTransColl
        If arpTransition.isDefaultTransition Then
          aCgState.IsDefault = True
          Exit For
        End If
      Next
      iState = iState + 1
      On Error Resume Next
      States.Add aCgState, aCgState.Name
    End If
    
    If aItem.metaClass = "Transition" Then
      Set arpTransition = aItem
      If Not arpTransition.isDefaultTransition Then
        Set aCgTrans = New CgTransition
        
        aCgTrans.Name = LTrim(RTrim(arpTransition.itsSource.Name & "_" & arpTransition.DisplayName))
        If Not arpTransition.itsSource Is Nothing Then aCgTrans.SourceState = arpTransition.itsSource.Name
        ' aCgTrans.EventType = ???
        If Not arpTransition.getItsTrigger Is Nothing Then aCgTrans.EventName = arpTransition.getItsTrigger.Name
        If Not arpTransition.getItsAction Is Nothing Then aCgTrans.Action = arpTransition.getItsAction.Body
        aCgTrans.order = iTrans
        
        iTrans = iTrans + 1
        Set aCgTrans.obj = arpTransition
        aCgTrans.Load Operations
        Transitions.Add aCgTrans, aCgTrans.Name
      End If
    End If
    
  Next
  
  Set BaseClasses = New Collection
  GetBaseClasses aRPClass, BaseClasses
  For Each cls In BaseClasses
    GetClassStates_Sub cls, Operations, States, Transitions, iState, iTrans
  Next
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Class State retrieval Error: " & err.Description
End Sub

Function AddCgObjects(PackageName As String, ClassName As String, aClass As rtsClass, ClassCgAttributes As Collection, classCgOperations As Collection, chViewDetails As Boolean) As Boolean
  Dim i As Integer
  Dim aOper As RPOperation
  Dim aAttr As RPAttribute
  Dim aAssoc As RPRelation
  Dim aCgOper As CgOperation
  Dim aCgAttr As CgAttribute
  Dim aPar As RPArgument
  Dim aCgPar As CgAttribute
  Dim params As String
  Dim aName As String
  Dim aDescriptor As String
  Dim aCgState As CgState
  Dim aCgTrans As CgTransition
  Dim szDataType As String
  
  Dim aRPClass As RPClass
  Dim arpAttribute As RPAttribute
  Dim arpOperation As RPOperation
  Dim arpRelation As RPRelation
  Dim arpState As RPState
  
  Dim AttributeList As RPCollection
  Dim RelationList As RPCollection
  Dim OperationList As RPCollection
  Dim bAbortAddDelete As Boolean
  
  Dim aPackage As RPPackage
  Dim BaseClass As RPClass
  Dim templateClass As RPClass
  Dim arpProject As RPProject
  Dim arpPar As RPTemplateParameter
  Dim bOnCg As Boolean
  
  On Error GoTo Error_Handler
  If aClass Is Nothing Then
    Debug.Print "AddCgObjects - Empty Class passed in."
    Exit Function
  Else
    Set aRPClass = aClass.Class
  End If
  
  AddCgObjects = True
  If aClass.ModelType = idxClassType_Model Then
    If Not InStr(1, aClass.additionalBaseClasses, "COnUMLDaeEsoImpl") > 0 Then
      aClass.additionalBaseClasses = "public COnUMLDaeEsoImpl<" & LTrim(RTrim(aClass.Name)) & ">" & _
                                     IIf(Len(aClass.additionalBaseClasses) > 0, ", ", "") & _
                                     aClass.additionalBaseClasses
      aClass.specIncludes = "OnUMLDaeEsoImpl.h" & _
                            IIf(Len(aClass.specIncludes) > 0, ", ", "") & _
                            aClass.specIncludes
      aClass.impIncludes = "stdafx.h, OnUMLEso.h" & _
                           IIf(Len(aClass.impIncludes) > 0, ", ", "") & _
                           aClass.impIncludes
      aRPClass.setPropertyValue "CPP_CG.Class.AdditionalBaseClasses", aClass.additionalBaseClasses
      aRPClass.setPropertyValue "CPP_CG.Class.SpecIncludes", aClass.specIncludes
      aRPClass.setPropertyValue "CPP_CG.Class.ImpIncludes", aClass.impIncludes
    End If
  ElseIf aClass.ModelType = idxClassType_Connector Then
    If Not InStr(1, aClass.additionalBaseClasses, "COnUMLConnectorImpl") > 0 Then
      aClass.additionalBaseClasses = "public COnUMLConnectorImpl<" & LTrim(RTrim(aClass.Name)) & ">" & _
                                IIf(Len(aClass.additionalBaseClasses) > 0, ", ", "") & _
                                aClass.additionalBaseClasses
      aClass.specIncludes = "stdafx.h, OnUMLConnectorImpl.h, OnUMLEso.h" & _
                       IIf(Len(aClass.specIncludes) > 0, ", ", "") & _
                       aClass.specIncludes
      aClass.impIncludes = "stdafx.h, OnUMLEso.h" & _
                       IIf(Len(aClass.impIncludes) > 0, ", ", "") & _
                       aClass.impIncludes
      aRPClass.setPropertyValue "CPP_CG.Class.AdditionalBaseClasses", aClass.additionalBaseClasses
      aRPClass.setPropertyValue "CPP_CG.Class.SpecIncludes", aClass.specIncludes
      aRPClass.setPropertyValue "CPP_CG.Class.ImpIncludes", aClass.impIncludes
    End If
  ElseIf aClass.ModelType = idxClassType_Structure Then
    If Not InStr(1, aClass.additionalBaseClasses, "IOnVarInit") > 0 Then
      aClass.additionalBaseClasses = "public IOnVarInit" & _
                                IIf(Len(aClass.additionalBaseClasses) > 0, ", ", "") & _
                                aClass.additionalBaseClasses
      aClass.specIncludes = "IOnVarInit.h" & _
                       IIf(Len(aClass.specIncludes) > 0, ", ", "") & _
                       aClass.specIncludes
      aRPClass.setPropertyValue "CPP_CG.Class.AdditionalBaseClasses", aClass.additionalBaseClasses
      aRPClass.setPropertyValue "CPP_CG.Class.SpecIncludes", aClass.specIncludes
    End If
  Else
      aClass.specIncludes = "OnUMLEso.h, fstream.h" & _
                       IIf(Len(aClass.specIncludes) > 0, ", ", "") & _
                       aClass.specIncludes
      aRPClass.setPropertyValue "CPP_CG.Class.AdditionalBaseClasses", aClass.additionalBaseClasses
      aRPClass.setPropertyValue "CPP_CG.Class.SpecIncludes", aClass.specIncludes
      aRPClass.setPropertyValue "CPP_CG.Class.ImpIncludes", aClass.impIncludes
  End If
    
  #If 0 Then ' using template instantiation , now using base class properties
  If aRPClass.Generalizations.count = 0 Then
    Set aPackage = aRPClass.Owner
    Set arpProject = aRPClass.Project
    Set templateClass = arpProject.FindClass("COnUMLDaeEsoImpl")
    If Not templateClass Is Nothing Then
      Set BaseClass = aPackage.addClass("OnModel_" & aRPClass.Name)
      BaseClass.setPropertyValue "CPP_CG.Class.Animate", False
      BaseClass.becomeTemplateInstantiationOf templateClass
      BaseClass.ti.templateInstantiationParameters(1).argValue = aRPClass.Name
      BaseClass.ti.templateInstantiationParameters(1).Name = aRPClass.Name
      BaseClass.ti.templateInstantiationParameters(1).DisplayName = aRPClass.Name
      aRPClass.addGeneralization BaseClass
      BaseClass.Save True
      aRPClass.Save True
    End If
  End If
  #End If
  
  'Need to build up temporary list of attributes, relations, and operation, so they
  'existing ones can be compared to the new ones
  
  Dim diffAttributes As Collection
  Dim diffRelations As Collection
  Dim diffOperations As Collection
  Dim cgCompareCol As CgCompareCollection
  Dim aInfo As rtsClass
    
  If Not aClass.Class Is Nothing Then
    Set AttributeList = aClass.Class.Attributes
    Set RelationList = aClass.Class.Relations
    Set OperationList = aClass.Class.Operations
  End If
  
  Set cgCompareCol = New CgCompareCollection
  Set cgCompareCol.rpAttributes = AttributeList
  Set cgCompareCol.rpRelations = RelationList
  Set cgCompareCol.rpOperations = OperationList
  Set cgCompareCol.AttributesCol = ClassCgAttributes
  Set cgCompareCol.OperationsCol = classCgOperations

  Set cgCompareCol.Class = aRPClass
  Set diffAttributes = cgCompareCol.CompareCgAttributes()
  Set diffRelations = cgCompareCol.CompareCgRelations()
  Set diffOperations = cgCompareCol.CompareCgOperations()
  
  bAbortAddDelete = cgCompareCol.UserSelectDifferences(chViewDetails)
  If Not bAbortAddDelete Then
    If Not cgCompareCol.DoAttributeAddDelete() Then AddCgObjects = False
    If Not cgCompareCol.DoRelationAddDelete() Then AddCgObjects = False
    If Not cgCompareCol.DoOperationAddDelete() Then AddCgObjects = False
      
    ' add OnTransition to States
    Dim sAction As String
    For Each aCgState In aClass.States
      Set arpState = aCgState.obj
      sAction = arpState.entryAction
      If Len(sAction) > 0 Then
        If InStr(1, sAction, "OnTransition();") = 0 Then
          sAction = sAction & vbCrLf & "OnTransition();"
        End If
      Else
        sAction = "OnTransition();"
      End If
      
      arpState.entryAction = sAction
    Next
    aClass.Save
    If aClass.Attributes.count = 0 Then
      aClass.SaveAttributeOrder ClassCgAttributes
    End If
    If Not g_DrawingDefMgr Is Nothing Then
        g_DrawingDefMgr.IsDirty = True
    End If
  End If
  Set cgCompareCol = Nothing
  Exit Function
    
Error_Handler:
    gMsgWnd.LogMessage "Code Generation Error: " & err.Description
End Function

Private Function GetRTSProject(Projects As RPCollection, ProjectName As String) As RPProject
    Dim i As Integer
    
    On Error Resume Next
    Set GetRTSProject = Nothing
    For i = 1 To Projects.count
        If Projects(i).Name = ProjectName Then
            Set GetRTSProject = Projects(i)
            Exit For
        End If
    Next i
End Function

Private Function GetRTSPackage(Packages As RPCollection, PackageName As String) As RPPackage
    Dim i As Integer
    
    On Error Resume Next
    Set GetRTSPackage = Nothing
    For i = 1 To Packages.count
        If Packages(i).Name = PackageName Then
            Set GetRTSPackage = Packages(i)
            Exit For
        End If
    Next i
End Function

Private Function GetRTSClass(Classes As RPCollection, ClassName As String) As RPClass
    Dim i As Integer
    
    On Error Resume Next
    Set GetRTSClass = Nothing
    For i = 1 To Classes.count
        If Classes(i).Name = ClassName Then
            Set GetRTSClass = Classes(i)
            Exit For
        End If
    Next i
End Function

#End If 'using_artisan


















