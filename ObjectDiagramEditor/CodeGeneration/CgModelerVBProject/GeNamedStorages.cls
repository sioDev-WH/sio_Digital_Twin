VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "GeNamedStorages"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'======================================================================================
'
' Module:   GeNamedStorages (collection class for GeNamedStorage's)
'
'--------------------------------------------------------------------------------------
'======================================================================================


Option Explicit

'=================================================================
' Start of Declarations Section
'=================================================================
' serializable
Private m_collItems As Collection

' runtime
Private m_bReadOnly As Boolean  ' file is readonly
Private m_bDirty As Boolean

' storage names in CGF file
Public Enum EGeNamedStorages
  sn_TitleBlock = 1         ' TitleBlockData
End Enum

'=================================================================
' End of Declarations Section
'=================================================================
'----------------------
Private Sub Class_Initialize()
  Set m_collItems = New Collection
End Sub

'----------------------
Private Sub Class_Terminate()
  DestroyAll
  Set m_collItems = Nothing
End Sub

'----------------------
Private Sub DestroyAll()
  ' destroyall entries
  Dim i As Long
  On Error Resume Next
  If Not m_collItems Is Nothing Then
    For i = 1 To m_collItems.Count
      m_collItems.Remove 1
    Next i
  End If
End Sub

'----------------------
Public Sub RemoveContents()
  ' destroyall entries
  Dim i As Long
  On Error Resume Next
  If Not m_collItems Is Nothing Then
    For i = 1 To m_collItems.Count
      m_collItems.Remove 1
    Next i
  End If
End Sub


'=================================================================
' Properties
'=================================================================
'-------------------------------
Public Property Get ReadOnly() As Boolean
  ReadOnly = m_bReadOnly
End Property
'-------------------------------
Public Property Let ReadOnly(ByVal bVal As Boolean)
  Dim obj As GeNamedStorage
  m_bReadOnly = bVal
  For Each obj In m_collItems
    obj.ReadOnly = m_bReadOnly
  Next
End Property

'-------------------------------
Public Property Get IsDirty() As Boolean
  Dim obj As GeNamedStorage
  If Not m_bDirty Then
    For Each obj In m_collItems
      If obj.IsDirty Then
        IsDirty = True
        Exit Property
      End If
    Next
  Else
    IsDirty = True
  End If
End Property

'-------------------------------
Public Property Get Count() As Long
  Count = m_collItems.Count
End Property
'-------------------------------
Public Property Get Item(ByVal Index As Long) As GeNamedStorage
  On Error Resume Next
  Set Item = m_collItems.Item(Index)
End Property

'----------------------
Public Property Get IsValidStorageName(ByVal strName As String) As Boolean
  ' REMEMBER: the Storages are Files within the GeGraphic root storage, and
  ' as such, follow normal file naming conventions.
  ' Thus , some characters are not legal ( : ; / \ , . ? * )
  
'  If IsAlpha(strName) Then
'    IsValidStorageName = True
'  ElseIf IsNumeric(strName) Then
'    IsValidStorageName = True
'  End If
  
  If InStr(strName, "(") Then Exit Property
  If InStr(strName, ")") Then Exit Property
  If InStr(strName, ":") Then Exit Property
  If InStr(strName, ";") Then Exit Property
  If InStr(strName, """") Then Exit Property
  If InStr(strName, "/") Then Exit Property
  If InStr(strName, "\") Then Exit Property
  If InStr(strName, ",") Then Exit Property
  If InStr(strName, "?") Then Exit Property
  If InStr(strName, "*") Then Exit Property
  IsValidStorageName = True
  
End Property

'-------------------------------
Public Property Get Section(ByVal strStgName As String) As GeNamedStorage
  ' get if have it. Create if don't have it
  Dim obj As GeNamedStorage
  On Error Resume Next
  If IsValidStorageName(strStgName) Then
    Set obj = CreateSectionWithName(strStgName)
    Set Section = obj
  End If
End Property
'------------------------------
Public Function GetEntry(ByVal szSection As String, ByVal szEntry As String) As String
  ' get entry
  Dim obj As GeNamedStorage
  On Error Resume Next
  Set obj = SectionWithName(szSection)
  If Not obj Is Nothing Then GetEntry = obj.Entry(szEntry)
End Function
'------------------------------
Public Function SetEntry(ByVal szSection As String, ByVal szEntry As String, ByVal szValue As String) As Boolean
  ' set entry
  Dim obj As GeNamedStorage
  On Error Resume Next
  Set obj = SectionWithName(szSection)
  If Not obj Is Nothing Then
    obj.Entry(szEntry) = szValue
    SetEntry = True
  End If
End Function
'------------------------------
Public Function SaveGeObjects(GeCtrl As CG, aGeIDs As Variant, ByVal szSection As String) As Boolean
  ' save all fields is all Geobjects in array of GeIDs to storage with name szSection
  ' if no section exists, create it
  Dim obj As GeNamedStorage
  On Error Resume Next
  If IsValidStorageName(szSection) Then
    Set obj = CreateSectionWithName(szSection)  ' find or create
    If Not obj Is Nothing Then
      ' clear it then rebuild
      obj.RemoveContents
      SaveGeObjects = obj.SaveGeObjects(GeCtrl, aGeIDs)
    End If
  End If
End Function

'-------------------------------
Private Property Get SectionWithName(ByVal strName As String) As GeNamedStorage
  Dim obj As GeNamedStorage
  For Each obj In m_collItems
    If obj.Name = strName Then
      Set SectionWithName = obj
      Exit Property
    End If
  Next
End Property
'-------------------------------
Public Sub RemoveSection(stg As GeNamedStorage)
  ' remove from my coll
  Dim i As Long
  Dim obj As GeNamedStorage
  For i = 1 To m_collItems.Count
    Set obj = m_collItems.Item(i)
    If obj Is stg Then
      m_collItems.Remove i
      m_bDirty = True
      Exit Sub
    End If
  Next i
End Sub

'-------------------------------
Private Function CreateSectionWithName(ByVal strName As String) As GeNamedStorage
  ' create if don't already have
  Dim obj As GeNamedStorage
  
  Set obj = SectionWithName(strName)
  If obj Is Nothing Then
    Set obj = New GeNamedStorage
    obj.Name = strName
    m_collItems.Add obj
    obj.ReadOnly = m_bReadOnly
    Set CreateSectionWithName = obj
    m_bDirty = True
  Else
    Set CreateSectionWithName = obj
  End If
End Function


'==================================================================
' Serializing
'==================================================================
'-------------------------------
Public Function LoadSectionFromGe(GeCtrl As CG, ByVal strSection As String) As Boolean
  ' load 1 section only from CG. return true if exists and successfully loaded
  Dim obj As GeNamedStorage
  Dim aStgNames As Variant
  Dim strStgName As String
  Dim uBnd As Long, lBnd As Long, i As Long
  Dim bRet As Boolean
  
  On Error Resume Next
  GeCtrl.EnumNamedStorages aStgNames    ' get existing
  uBnd = UBound(aStgNames)
  lBnd = LBound(aStgNames)
  If Err = 0 And uBnd > -1 Then
    '
    For i = lBnd To uBnd
      strStgName = aStgNames(i)
      If UCase(strSection) = UCase(strStgName) Then
        Set obj = CreateSectionWithName(strSection)
        If Not obj Is Nothing Then
          bRet = obj.SerializeToGe(GeCtrl, False)       ' false = load
        End If
        Exit For
      End If
    Next i
    '
  End If
  '
  LoadSectionFromGe = bRet
End Function

'-------------------------------
Public Function SerializeToGeFile(GeCtrl As CG, ByVal bSave As Boolean, ByVal strFile As String) As Boolean
  ' save/load from some other file
  SerializeToGeFile = DoSerializeToGe(GeCtrl, bSave, strFile, True)
End Function

'-------------------------------
Public Function SerializeToGe(GeCtrl As CG, ByVal bSave As Boolean) As Boolean
  ' serialize to graphic
  SerializeToGe = DoSerializeToGe(GeCtrl, bSave, "", False)
End Function
'-------------------------------
Private Function DoSerializeToGe(GeCtrl As CG, ByVal bSave As Boolean, _
                         ByVal strFile As String, ByVal bOtherFile As Boolean) As Boolean
  ' save to graphic
  Dim i As Long, nCnt As Long
  Dim obj As GeNamedStorage
  Dim bRet As Boolean, brtn As Boolean
  Dim strName As String
  Dim bDoIt As Boolean
  
  On Error Resume Next

  If bSave Then   '' SAVING
    bRet = True
    brtn = True
    nCnt = m_collItems.Count
    For i = 1 To nCnt
      Set obj = m_collItems.Item(i)
      If bOtherFile Then
        bRet = obj.SerializeToGeFile(GeCtrl, bSave, strFile)
      Else
        bRet = obj.SerializeToGe(GeCtrl, bSave)
      End If
      If Not bRet Then brtn = False
    Next i
    If brtn Then
      DoSerializeToGe = True
      m_bDirty = False
    End If
  Else    '' LOADING
    DestroyAll
    bRet = True
    brtn = True
    ' enum storages in CG and create objects from them if they are of interest
    Dim aStgNames As Variant
    Dim strStgName As String
    Dim uBnd As Long, lBnd As Long
    '
    If bOtherFile Then
      GeCtrl.EnumNamedStoragesForFile strFile, aStgNames    ' get existing
    Else
      GeCtrl.EnumNamedStorages aStgNames    ' get existing
    End If
    '
    uBnd = UBound(aStgNames)
    lBnd = LBound(aStgNames)
    If Err = 0 And uBnd > -1 Then
      '
      For i = lBnd To uBnd
        bDoIt = True
        strStgName = aStgNames(i)
        strName = strStgName
        '
        If bDoIt Then
          Set obj = New GeNamedStorage
          obj.Name = strName
          m_collItems.Add obj
          If bOtherFile Then
            bRet = obj.SerializeToGeFile(GeCtrl, bSave, strFile)
          Else
            bRet = obj.SerializeToGe(GeCtrl, bSave)
          End If
          If Not bRet Then brtn = False
        End If
        '
      Next i
    End If
    '
    If brtn Then
      DoSerializeToGe = True
      m_bDirty = False
    End If
  End If
End Function


