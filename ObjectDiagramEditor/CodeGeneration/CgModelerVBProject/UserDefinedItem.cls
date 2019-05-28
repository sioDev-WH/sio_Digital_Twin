VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "UserDefinedItem"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

'======================================================================================
'
' Module:   UserDefinedItem
'
'--------------------------------------------------------------------------------------
'======================================================================================



'=================================================================
' Start of Declarations Section
'=================================================================

' stored
Private m_nSIDID As Long
Private m_nOldSIDID As Long   ' what I used to be if copied
Private m_strObjectName As String
Private m_strProjectName As String
Private m_strPackageName As String
Private m_strClassName As String
Private m_strProcessTag As String
Private m_TS As Long

Public m_strDefObjectName As String

Public m_strFolder As String
Public m_strShape As String

Public Attributes As Collection

' runtime properties
Private m_nGeID As Long
Private m_bDirty As Boolean

Public m_Info As rtsClass        ' info holder for code generation
Public m_index As Long           ' info holder for code generation
Public m_Order As Long           ' info holder for code generation
Public globalName As String      ' info holder for code generation
Public interfaceName As String   ' info holder for code generation

Private Const NULL_STRING = "NULL"  'Replaces XML zero length strings

'=================================================================
' End of Declarations Section
'=================================================================

'-------------------------------
Private Sub Class_Initialize()
  m_bDirty = False
  m_TS = 100
  Set Attributes = New Collection
'  m_nSIDID = GetNextProjObjID
End Sub
'-------------------------------
Private Sub Class_Terminate()
  DestroyAll
End Sub

'-------------------------------
Public Sub DestroyAll()
  '
End Sub
'-------------------------------
Public Property Get IsDirty() As Boolean
  IsDirty = m_bDirty
End Property

'-------------------------------
Public Property Let IsDirty(newVal As Boolean)
  m_bDirty = newVal
End Property

'-------------------------------
Public Property Get GeID() As Long
  GeID = m_nGeID
End Property
Public Property Let GeID(ByVal lVal As Long)
  m_nGeID = lVal
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
Property Get ProcessTag() As String
  ProcessTag = m_strProcessTag
End Property
Property Let ProcessTag(ByVal lVal As String)
  If m_strProcessTag <> lVal Then
    m_strProcessTag = lVal
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
Public Property Get SIDID() As Long
  SIDID = m_nSIDID
End Property
Public Property Let SIDID(ByVal lVal As Long)
  If m_nSIDID <> lVal Then
    m_nSIDID = lVal
    m_bDirty = True
  End If
End Property
'-------------------------------
Public Property Get OldSIDID() As Long
  OldSIDID = m_nOldSIDID
End Property
Public Property Let OldSIDID(ByVal lVal As Long)
  If m_nOldSIDID <> lVal Then
    m_nOldSIDID = lVal
    m_bDirty = True
  End If
End Property

'------------------------------
Public Function Copy(tgt_obj As UserDefinedItem) As Boolean
  Dim aAttr As CgAttribute
  Dim newAttr As CgAttribute

  If tgt_obj Is Nothing Then Set tgt_obj = New UserDefinedItem
  tgt_obj.ObjectName = m_strObjectName
  tgt_obj.ProjectName = m_strProjectName
  tgt_obj.PackageName = m_strPackageName
  tgt_obj.ClassName = m_strClassName
  tgt_obj.TS = m_TS
  tgt_obj.SIDID = m_nSIDID
  tgt_obj.OldSIDID = m_nOldSIDID
  tgt_obj.m_strFolder = m_strFolder
  tgt_obj.m_strShape = m_strShape
  
  For Each aAttr In Attributes
    Set newAttr = New CgAttribute
    newAttr.Copy aAttr
    tgt_obj.Attributes.Add aAttr
  Next
  
End Function

'------------------------------
Public Sub AddToCollection(coll As Collection)
  coll.Add Me
End Sub

'================================================================
' Storage
'================================================================
'-------------------------------
Public Function SerializeToPropertyBag(PropBag As PropertyBag, ByVal strKeyIn As String, ByVal bSave As Boolean) As Boolean
  ' save to propBag
  Dim szXML As String
  Dim aDoc As DOMDocument
  Dim aNodeList As IXMLDOMNodeList
  Dim aItem As IXMLDOMElement
  Dim aAttr As CgAttribute
  Dim i As Long
  
  Dim ObjectName As String
  Dim DefObjectName As String
  Dim ProjectName As String
  Dim PackageName As String
  Dim ClassName As String
  Dim Folder As String
  Dim Shape As String
  
  On Error Resume Next
  
  If bSave Then   '' SAVING
    'NOTE:  Can't have attributes of zero length in XML, so replace with 'NULL' string
    ObjectName = IIf(m_strObjectName = "", NULL_STRING, m_strObjectName)
    DefObjectName = IIf(m_strDefObjectName = "", NULL_STRING, m_strDefObjectName)
    ProjectName = IIf(m_strProjectName = "", NULL_STRING, m_strProjectName)
    PackageName = IIf(m_strPackageName = "", NULL_STRING, m_strPackageName)
    ClassName = IIf(m_strClassName = "", NULL_STRING, m_strClassName)
    Folder = IIf(m_strFolder = "", NULL_STRING, m_strFolder)
    Shape = IIf(m_strShape = "", NULL_STRING, m_strShape)
    
    ' write controlling data
    szXML = szXML & "<UDI Name = " & Chr(34) & ObjectName & Chr(34)
    szXML = szXML & " DefName = " & Chr(34) & DefObjectName & Chr(34)
    szXML = szXML & " ProjectName = " & Chr(34) & ProjectName & Chr(34)
    szXML = szXML & " PackageName = " & Chr(34) & PackageName & Chr(34)
    szXML = szXML & " ClassName = " & Chr(34) & ClassName & Chr(34)
    szXML = szXML & " TS = " & Chr(34) & m_TS & Chr(34)
    szXML = szXML & " SID = " & Chr(34) & m_nSIDID & Chr(34)
    szXML = szXML & " OldSID = " & Chr(34) & m_nOldSIDID & Chr(34)
    szXML = szXML & " Folder = " & Chr(34) & Folder & Chr(34)
    szXML = szXML & " Shape = " & Chr(34) & Shape & Chr(34)
    szXML = szXML & " xmlns=" & Chr(34) & "x-schema:\xmldata\ModelDefinition.xml" & Chr(34) & "> " & vbCrLf
    For Each aAttr In Attributes
      szXML = szXML & aAttr.export
    Next
    szXML = szXML & "</UDI>"

    PropBag.WriteProperty strKeyIn & "XMLData", szXML, ""
        
    SerializeToPropertyBag = True
  
  Else    '' LOADING
  
    szXML = PropBag.ReadProperty(strKeyIn & "XMLData", "")
    
    Debug.Print ""
    Debug.Print szXML
    Debug.Print ""
    
    If Len(szXML) > 0 Then
      Set aDoc = New DOMDocument
      If aDoc.loadXML(szXML) Then
        Set aItem = aDoc.documentElement
        m_strObjectName = aItem.getAttribute("Name")
        m_strDefObjectName = aItem.getAttribute("DefName")
        m_strProjectName = aItem.getAttribute("ProjectName")
        m_strPackageName = aItem.getAttribute("PackageName")
        m_strClassName = aItem.getAttribute("ClassName")
        m_TS = aItem.getAttribute("TS")
        m_nSIDID = aItem.getAttribute("SID")
        m_nOldSIDID = aItem.getAttribute("OldSID")
        m_strFolder = aItem.getAttribute("Folder")
        m_strShape = aItem.getAttribute("Shape")
        
        m_strObjectName = IIf(m_strObjectName = NULL_STRING, "", m_strObjectName)
        m_strDefObjectName = IIf(m_strDefObjectName = NULL_STRING, "", m_strDefObjectName)
        m_strProjectName = IIf(m_strProjectName = NULL_STRING, "", m_strProjectName)
        m_strPackageName = IIf(m_strPackageName = NULL_STRING, "", m_strPackageName)
        m_strClassName = IIf(m_strClassName = NULL_STRING, "", m_strClassName)
        m_strFolder = IIf(m_strFolder = NULL_STRING, "", m_strFolder)
        m_strShape = IIf(m_strShape = NULL_STRING, "", m_strShape)
        
        Set aNodeList = aDoc.getElementsByTagName("CgAttribute")
        For i = 0 To aNodeList.length - 1
          Set aItem = aNodeList.Item(i)
          On Error Resume Next
          Set aAttr = New CgAttribute
          aAttr.import aItem
          Attributes.Add aAttr
        Next i
      End If
    End If
    
    SerializeToPropertyBag = True
  End If
  '
  m_bDirty = False
  
End Function


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
        gMsgWnd.LogMessage strMsg
      #End If
    VERIFY_ERR = False
  End If
End Function

