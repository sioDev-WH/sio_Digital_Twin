VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "UserDefinedItemDef"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

'======================================================================================
'
' Module:   UserDefinedItemDef
'
'--------------------------------------------------------------------------------------
'======================================================================================



'=================================================================
' Start of Declarations Section
'=================================================================

' stored
Private m_strObjectName As String
Private m_strProjectName As String
Private m_strPackageName As String
Private m_strClassName As String
Private m_strID As String
Private m_strLibrary As String
Private m_strFolder As String
Private m_strShape As String
Private m_lShapeID As Long

Private m_strIconLibrary As String
Private m_strIconFolder As String
Private m_strIconShape As String
Private m_lIconShapeID As Long

Private m_TS As Long

Public Attributes As Collection ' CgAttribute
Public CgConnectionDefs As Collection

Private m_bDirty As Boolean


'=================================================================
' End of Declarations Section
'=================================================================

'-------------------------------
Private Sub Class_Initialize()
  Set CgConnectionDefs = New Collection
  Set Attributes = New Collection
  m_TS = 100
  m_bDirty = False
  m_lShapeID = -1
  m_lIconShapeID = -1
End Sub
'-------------------------------
Private Sub Class_Terminate()
  DestroyAll
End Sub

'-------------------------------
Public Sub DestroyAll()
  Set CgConnectionDefs = Nothing
  Set Attributes = Nothing
End Sub

Public Sub EmptyCollections()
    Dim iCons As Integer
    Dim iAttribs As Integer
    Dim i As Integer
    
    iCons = CgConnectionDefs.count
    For i = 1 To iCons
        CgConnectionDefs.Remove 1
    Next

    iAttribs = Attributes.count
    For i = 1 To iAttribs
        Attributes.Remove 1
    Next
End Sub
'-------------------------------
Public Property Get IsDirty() As Boolean
  IsDirty = m_bDirty
End Property

'-------------------------------
Public Property Let IsDirty(NewVal As Boolean)
  m_bDirty = NewVal
End Property

'-------------------------------
Property Get ObjectName() As String
  ObjectName = m_strObjectName
End Property
Property Let ObjectName(ByVal lVal As String)
  If m_strObjectName <> lVal Then
    m_strObjectName = lVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Property Get ProjectName() As String
  ProjectName = m_strProjectName
End Property
Property Let ProjectName(ByVal lVal As String)
  If m_strProjectName <> lVal Then
    m_strProjectName = lVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Property Get ClassName() As String
  ClassName = m_strClassName
End Property
Property Let ClassName(ByVal lVal As String)
  If m_strClassName <> lVal Then
    m_strClassName = lVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Property Get TS() As Long
  TS = m_TS
End Property
Property Let TS(ByVal lVal As Long)
  If m_TS <> lVal Then
    m_TS = lVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Property Get ID() As String
  ID = m_strID
End Property
Property Let ID(ByVal strID As String)
  If m_strID <> strID Then
    m_strID = strID
    m_bDirty = True
  End If
End Property

'-------------------------------
Property Get PackageName() As String
  PackageName = m_strPackageName
End Property
Property Let PackageName(ByVal lVal As String)
  If m_strPackageName <> lVal Then
    m_strPackageName = lVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Public Property Get GeLibrary() As String
  GeLibrary = m_strLibrary
End Property

Public Property Let GeLibrary(ByVal strVal As String)
  If m_strLibrary <> strVal Then
    m_strLibrary = strVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Public Property Get GeIconLibrary() As String
  GeIconLibrary = m_strIconLibrary
End Property

Public Property Let GeIconLibrary(ByVal strVal As String)
  If m_strIconLibrary <> strVal Then
    m_strIconLibrary = strVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Public Property Get GeFolder() As String
  GeFolder = m_strFolder
End Property
Public Property Let GeFolder(ByVal strVal As String)
  If m_strFolder <> strVal Then
    m_strFolder = strVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Public Property Get GeIconFolder() As String
  GeIconFolder = m_strIconFolder
End Property
Public Property Let GeIconFolder(ByVal strVal As String)
  If m_strIconFolder <> strVal Then
    m_strIconFolder = strVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Public Property Get GeShape() As String
  GeShape = m_strShape
End Property
Public Property Let GeShape(ByVal strVal As String)
  If m_strShape <> strVal Then
    m_strShape = strVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Public Property Get GeIconShape() As String
  GeIconShape = m_strIconShape
End Property
Public Property Let GeIconShape(ByVal strVal As String)
  If m_strIconShape <> strVal Then
    m_strIconShape = strVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Public Property Get GeShapeID() As Long
  GeShapeID = m_lShapeID
End Property
Public Property Let GeShapeID(ByVal lVal As Long)
  If m_lShapeID <> lVal Then
    m_lShapeID = lVal
    m_bDirty = True
  End If
End Property

'-------------------------------
Public Property Get GeIconShapeID() As Long
  GeIconShapeID = m_lIconShapeID
End Property
Public Property Let GeIconShapeID(ByVal lVal As Long)
  If m_lIconShapeID <> lVal Then
    m_lIconShapeID = lVal
    m_bDirty = True
  End If
End Property

'------------------------------
Public Function Copy(obj As UserDefinedItemDef) As Boolean
  Dim aAttr As CgAttribute
  Dim newAttr As CgAttribute
  Dim aConn As CgConnectionDef
  Dim newConn As CgConnectionDef
  Dim i As Integer
  
  If obj Is Nothing Then Set obj = New UserDefinedItemDef
  obj.ObjectName = m_strObjectName
  obj.ProjectName = m_strProjectName
  obj.PackageName = m_strPackageName
  obj.ClassName = m_strClassName
  obj.ID = m_strID
  obj.GeLibrary = m_strLibrary
  
  obj.GeFolder = m_strFolder
  obj.GeShape = m_strShape
  obj.GeShapeID = m_lShapeID
  
  obj.GeIconLibrary = m_strIconLibrary
  obj.GeIconFolder = m_strIconFolder
  obj.GeIconShape = m_strIconShape
  obj.GeIconShapeID = m_lIconShapeID
  
  obj.TS = m_TS
  
  If obj.Attributes Is Nothing Then Set obj.Attributes = New Collection
  If Attributes Is Nothing Then
    Set obj.Attributes = Nothing
  Else
    For i = 1 To obj.Attributes.count
        obj.Attributes.Remove 1
    Next i
    For Each aAttr In Attributes
      Set newAttr = New CgAttribute
      aAttr.Copy newAttr
      obj.Attributes.Add newAttr
    Next
  End If
  If obj.CgConnectionDefs Is Nothing Then Set obj.CgConnectionDefs = New Collection
  If CgConnectionDefs Is Nothing Then
    Set obj.CgConnectionDefs = Nothing
  Else
    For i = 1 To obj.CgConnectionDefs.count
        obj.CgConnectionDefs.Remove 1
    Next i
    For Each aConn In CgConnectionDefs
      Set newConn = New CgConnectionDef
      aConn.Copy newConn
      obj.CgConnectionDefs.Add newConn
    Next
  End If
  
  Copy = True
End Function

'================================================================
' Storage
'================================================================
'-------------------------------
Public Function export() As String
  Dim szRet As String
  Dim aAttr As CgAttribute
  Dim aConn As CgConnectionDef
  
  szRet = szRet & "<UDIDef Name=" & Chr(34) & m_strObjectName & Chr(34)
  szRet = szRet & " ClassName=" & Chr(34) & m_strClassName & Chr(34)
  szRet = szRet & " ID=" & Chr(34) & m_strID & Chr(34)
  szRet = szRet & " TS=" & Chr(34) & m_TS & Chr(34)
  szRet = szRet & " Library=" & Chr(34) & RemoveFilePath(m_strLibrary) & Chr(34)
  szRet = szRet & " Folder=" & Chr(34) & m_strFolder & Chr(34)
  szRet = szRet & " Shape=" & Chr(34) & m_strShape & Chr(34)
  szRet = szRet & " ShapeID=" & Chr(34) & m_lShapeID & Chr(34)
  szRet = szRet & " IconLibrary=" & Chr(34) & RemoveFilePath(m_strIconLibrary) & Chr(34)
  szRet = szRet & " IconFolder=" & Chr(34) & m_strIconFolder & Chr(34)
  szRet = szRet & " IconShape=" & Chr(34) & m_strIconShape & Chr(34)
  szRet = szRet & " IconShapeID=" & Chr(34) & m_lIconShapeID & Chr(34)
  szRet = szRet & " >" & vbCrLf
  
  If Not Attributes Is Nothing Then
    For Each aAttr In Attributes
      szRet = szRet & aAttr.export
    Next
  End If
  
  If Not CgConnectionDefs Is Nothing Then
    For Each aConn In CgConnectionDefs
      szRet = szRet & aConn.export
    Next
  End If
  
  szRet = szRet & "</UDIDef>" & vbCrLf
  
  export = szRet
  m_bDirty = False
End Function

Private Function RemoveFilePath(szPath As String) As String
  Dim iPos As Long
  Dim szRet As String
  
  iPos = Len(szPath)
  szRet = szPath
  
  Do While iPos > 0
    If Mid(szPath, iPos, 1) = "\" Then
      szRet = Mid(szPath, iPos + 1)
      Exit Do
    End If
    iPos = iPos - 1
  Loop
  
  RemoveFilePath = szRet
  
End Function

'-------------------------------
Public Sub import(elem As IXMLDOMElement)
  Dim aItem As IXMLDOMElement
  Dim aNodeList As IXMLDOMNodeList
  Dim aAttr As CgAttribute
  Dim aConn As CgConnectionDef
  Dim i As Long
  
  On Error Resume Next
  
  m_strObjectName = elem.getAttribute("Name")
  m_strProjectName = elem.getAttribute("ProjectName")
  m_strPackageName = elem.getAttribute("PackageName")
  m_strClassName = elem.getAttribute("ClassName")
  m_strID = elem.getAttribute("ID")
  m_TS = elem.getAttribute("TS")
  
  m_strLibrary = elem.getAttribute("Library")
  m_strFolder = elem.getAttribute("Folder")
  m_strShape = elem.getAttribute("Shape")
  m_lShapeID = elem.getAttribute("ShapeID")
  
  m_strIconLibrary = elem.getAttribute("IconLibrary")
  m_strIconFolder = elem.getAttribute("IconFolder")
  m_strIconShape = elem.getAttribute("IconShape")
  m_lIconShapeID = elem.getAttribute("IconShapeID")
  
  Set aNodeList = elem.getElementsByTagName("CgAttribute")
  For i = 0 To aNodeList.length - 1
    Set aItem = aNodeList.Item(i)
    Set aAttr = New CgAttribute
    aAttr.import aItem
    aAttr.ClassName = m_strClassName
    aAttr.PackageName = m_strPackageName
    Attributes.Add aAttr, aAttr.Name
  Next i
  
  Set aNodeList = elem.getElementsByTagName("CgConnectionDef")
  For i = 0 To aNodeList.length - 1
    Set aItem = aNodeList.Item(i)
    Set aConn = New CgConnectionDef
    aConn.import aItem
    CgConnectionDefs.Add aConn
  Next i
End Sub

Public Function GetAttributes() As rtsClass
    Dim i As Integer
    Dim m_Projects As Object
    Dim curProject As rtsProject
    Dim curPackage As rtsPackage
    Dim curClass As rtsClass
    Dim iAttribs As Integer
    Dim aInfo As rtsClass
    Dim aDefAttrib As CgAttribute
    Dim aAttrib, aNewAttrib As CgAttribute

    On Error GoTo Error_Handler
    If Projects Is Nothing Then
        GetProjects Projects, m_Projects
    End If
    
    For i = 1 To Projects.count
        If m_strProjectName = Projects(i).Name Then
          Set curProject = Projects(i)
          Exit For
        End If
    Next i
    If curProject Is Nothing Then
          gMsgWnd.LogMessage "Failed to find matching loaded UML project " & m_strProjectName
          Exit Function
    End If
    
    Set curPackage = curProject.Packages(m_strPackageName)
    If curPackage Is Nothing Then
        gMsgWnd.LogMessage "Failed to find matching package " & m_strPackageName & " in project " & m_strProjectName
        Exit Function
    End If
    
    Set curClass = curPackage.Classes(m_strClassName)
    If curClass Is Nothing Then
        gMsgWnd.LogMessage "Failed to find matching class " & m_strClassName & " in package " & m_strPackageName & " in project " & m_strProjectName
        Exit Function
    End If
       
    GetClassInfo curProject, curPackage.Name, curClass.Name, aInfo
    Set GetAttributes = aInfo
    
    'Find in aInfo.Attributes matches from Attributes (loaded from XML shape defs), and make sure
    'the right initial values is set
    For Each aDefAttrib In Attributes
        iAttribs = aInfo.Attributes.count
        For Each aAttrib In aInfo.Attributes
            If aAttrib.Name = aDefAttrib.Name Then
                    aAttrib.Value = aDefAttrib.Value
                Exit For
            End If
        Next
    Next
    
    'Remove all elements from Attributes list and set to newly retrieved attributes list
    For i = 1 To Attributes.count
      Attributes.Remove (1)
    Next i
    
    For Each aAttrib In aInfo.Attributes
        Set aNewAttrib = New CgAttribute
        aAttrib.Copy aNewAttrib
        Attributes.Add aAttrib, aAttrib.Name
    Next
    
    Set curProject = Nothing
    Set curPackage = Nothing
    Set curClass = Nothing
    
    Exit Function
    
Error_Handler:
    gMsgWnd.LogMessage "Failed to load attributes for class " & m_strClassName & " in package " & m_strPackageName & " in project " & m_strProjectName
End Function

Public Sub initUDI(ByRef obj As UserDefinedItem)
  Dim aAttr As CgAttribute
  Dim newAttr As CgAttribute
  
  If obj Is Nothing Then Set obj = New UserDefinedItem
  obj.ObjectName = m_strShape
  obj.ProjectName = m_strProjectName
  obj.PackageName = m_strPackageName
  obj.ClassName = m_strClassName
  obj.TS = m_TS
  obj.m_strDefObjectName = m_strObjectName
  
  For Each aAttr In Attributes
    Set newAttr = New CgAttribute
    aAttr.Copy newAttr
    obj.Attributes.Add newAttr
  Next
End Sub

Public Function FindConnection(strConnName As String) As CgConnectionDef
  Dim aConn As CgConnectionDef
  
  For Each aConn In CgConnectionDefs
    If aConn.connName = strConnName Then
        Set FindConnection = aConn
        Exit For
    End If
  Next
End Function

Public Function GetClass(aInfo As rtsClass) As Boolean
    Dim m_Projects As Collection
    Dim curProject As rtsProject
    Dim curPackage As rtsPackage
    Dim curClass As rtsClass
    Dim i As Long
    
    If Projects Is Nothing Then
        GetProjects Projects, m_Projects
    End If
    
    For i = 1 To Projects.count
        If m_strProjectName = Projects(i).Name Then
          Set curProject = Projects(i)
          Exit For
        End If
    Next i
    If curProject Is Nothing Then
          gMsgWnd.LogMessage "Failed to find matching loaded UML project " & m_strProjectName
          Exit Function
    End If
    
    Set curPackage = curProject.Packages(m_strPackageName)
    If curPackage Is Nothing Then
        gMsgWnd.LogMessage "Failed to find matching package " & m_strPackageName & " in project " & m_strProjectName
        Exit Function
    End If
    
    Set curClass = curPackage.Classes(m_strClassName)
    If curClass Is Nothing Then
        gMsgWnd.LogMessage "Failed to find matching class " & m_strClassName & " in package " & m_strPackageName & " in project " & m_strProjectName
        Exit Function
    End If
       
    GetClass = GetClassInfo(curProject, curPackage.Name, curClass.Name, aInfo)
End Function

Public Function FindAttribute(attrItemName As String) As CgAttribute
  Dim aAttr As CgAttribute
  Dim classInfo As rtsClass
  Dim bFound As Boolean
  
  If GetClass(classInfo) Then
    For Each aAttr In classInfo.Attributes
      If aAttr.Name = attrItemName Then
        bFound = True
        Exit For
      End If
    Next
  End If
  
  If bFound Then
    Set FindAttribute = aAttr
  End If
End Function

Public Function FindOperation(operItemName As String) As CgOperation
  Dim aOper As CgOperation
  Dim connDef As CgConnectionDef
  Dim classInfo As rtsClass
  Dim bFound As Boolean
  
  If GetClass(classInfo) Then
    For Each aOper In classInfo.Operations
      If aOper.Name = operItemName Then
        bFound = True
        Exit For
      End If
    Next
  End If
  
  If bFound Then
    Set FindOperation = aOper
  End If
End Function

Public Sub FillInDetails(strConn As String, iFace As Integer, iOrder As Integer, lUserId As Long)
    Dim pDef As CgConnectionDef
    
    Set pDef = FindConnection(strConn)
    If pDef Is Nothing Then
        'This case is likely to happen when a unmapped ShapeDef gets mapped to a class.  The shape has connectors
        'but they have no associated CgConnectionDefs since the UDIDef has just been created.
        Set pDef = New CgConnectionDef
        pDef.itemName = ""
        pDef.connName = strConn
        CgConnectionDefs.Add pDef
    End If
    
    pDef.Face = iFace
    pDef.order = iOrder
    pDef.UserID = lUserId
End Sub

'========================================
' Helpers
'========================================
'------------------------------
Private Function VERIFY_ERR() As Boolean
  ' Verify for the Err object
  ' Return True if OK
  VERIFY_ERR = True
  If Not err = 0 Then
      #If APP_DEBUG Then
        Dim strMsg As String
        strMsg = TypeName(Me) & ":VERIFY_ERR Failed:" & Error
        ShowStatusMsg strMsg
      #End If
    VERIFY_ERR = False
  End If
End Function

