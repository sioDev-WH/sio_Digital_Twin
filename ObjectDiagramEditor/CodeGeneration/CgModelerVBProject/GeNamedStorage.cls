VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "GeNamedStorage"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'======================================================================================
'
' Module:   GeNamedStorage
'
'--------------------------------------------------------------------------------------
'======================================================================================


Option Explicit

'=================================================================
' Start of Declarations Section
'=================================================================

Private Const c_nSchema As Integer = 0    ' current schema

' serializable
Private m_strName As String


' runtime
Private m_bDirty As Boolean
Private m_bReadOnly As Boolean

Private Type Entry
  tag As String
  Value As String
  ID As Long        ' id of this entry
End Type
Private m_aEntrys() As Entry

'=================================================================
' End of Declarations Section
'=================================================================
'-------------------------------
Private Sub Class_Initialize()
End Sub

'----------------------
Private Sub Class_Terminate()
  DestroyAll
End Sub

'----------------------
Private Sub DestroyAll()
  ' destroyall entries
  On Error Resume Next
  Erase m_aEntrys
End Sub

'----------------------
Public Sub RemoveContents()
  ' destroyall entries
  On Error Resume Next
  Erase m_aEntrys
End Sub


'==================================================================
' Properties
'==================================================================
'-------------------------------
Public Property Get IsDirty() As Boolean
  IsDirty = m_bDirty
End Property
Public Property Let IsDirty(ByVal bVal As Boolean)
  m_bDirty = bVal
End Property
'-------------------------------
Public Property Get Name() As String
  Name = m_strName
End Property
Public Property Let Name(ByVal strVal As String)
  If m_strName <> strVal Then m_bDirty = True
  m_strName = strVal
End Property
'-------------------------------
Public Property Get ReadOnly() As Boolean
  ReadOnly = m_bReadOnly
End Property
Public Property Let ReadOnly(ByVal bVal As Boolean)
  m_bReadOnly = bVal
End Property

'=================================================================
' Entry access
'=================================================================
'------------------------------
Public Property Get Count() As Long
  Dim uBnd As Long, lBnd As Long
  On Error Resume Next
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then Count = uBnd - lBnd + 1
End Property
'------------------------------
Public Property Get Item(ByVal Index As Long) As String
  ' get value, 1 based interface
  Dim uBnd As Long, lBnd As Long, nDX As Long
  On Error Resume Next
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    nDX = Index - 1
    If nDX >= lBnd And nDX <= uBnd Then Item = m_aEntrys(nDX).Value
  End If
End Property
'------------------------------
Public Sub GetItemData(ByVal Index As Long, ID As Long, strTag As String, strVal As String)
  ' get all data, 1 based interface
  Dim uBnd As Long, lBnd As Long, nDX As Long
  On Error Resume Next
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    nDX = Index - 1
    If nDX >= lBnd And nDX <= uBnd Then
      ID = m_aEntrys(nDX).ID
      strTag = m_aEntrys(nDX).tag
      strVal = m_aEntrys(nDX).Value
    End If
  End If
End Sub

'------------------------------
Public Property Get Entry(ByVal strTag As String) As String
  ' get value
  Dim uBnd As Long, lBnd As Long, i As Long
  On Error Resume Next
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    For i = lBnd To uBnd
      If m_aEntrys(i).tag = strTag Then
        Entry = m_aEntrys(i).Value
        Exit Property
      End If
    Next i
  End If
End Property
'------------------------------
Public Property Let Entry(ByVal strTag As String, ByVal strVal As String)
  ' set value.
  ' if not found, create new one and add
  AddEntryWithTag strTag, strVal
End Property

'------------------------------
Public Sub RemoveEntry(ByVal strTag As String, ByVal strVal As String)
  ' remove entry
  Dim uBnd As Long, lBnd As Long, i As Long
  
  On Error Resume Next
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    For i = lBnd To uBnd
      If m_aEntrys(i).tag = strTag Then
        ' remove from array
        DeleteEntry i
        m_bDirty = True
        Exit Sub
      End If
    Next i
  End If
End Sub

'------------------------------
Private Function UpdateEntryWithTag(ByVal strTag As String, ByVal strVal As String) As Boolean
  ' find and update entry. return false if can't find
  Dim uBnd As Long, lBnd As Long, i As Long
  
  On Error Resume Next
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    For i = lBnd To uBnd
      If m_aEntrys(i).tag = strTag Then
        ' set it to me
        If m_aEntrys(i).Value <> strVal Then m_bDirty = True
        m_aEntrys(i).Value = strVal
        UpdateEntryWithTag = True
        Exit Function
      End If
    Next i
  End If
End Function

'------------------------------
Private Sub AddEntryWithTag(ByVal strTag As String, ByVal strVal As String)
  ' move to it if have it, otherwise create new and then move to it
  Dim uBnd As Long, lBnd As Long
  
  On Error Resume Next
  If UpdateEntryWithTag(strTag, strVal) Then Exit Sub
  
  m_bDirty = True
  Err = 0
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    ' create new one
    Err = 0
    ReDim Preserve m_aEntrys(uBnd - lBnd + 1) As Entry
    m_aEntrys(uBnd - lBnd + 1).tag = strTag
    m_aEntrys(uBnd - lBnd + 1).Value = strVal
  Else
    ' none. create 1st one
    Err = 0 ' clear err
    ReDim m_aEntrys(0) As Entry
    m_aEntrys(0).tag = strTag:    m_aEntrys(0).Value = strVal
  End If
End Sub
'-------------------------
Private Sub DeleteEntry(ByVal nIndex As Long)
  ' delete from tracker
  Dim uBnd As Long, lBnd As Long, i As Long
  Dim nCnt As Long
  
  On Error Resume Next
  
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    nCnt = uBnd - lBnd + 1
    
    If nIndex = nCnt - 1 Then ' handle case of Tail
      If nCnt - 2 < 0 Then    ' nothing left. nuke all
        Erase m_aEntrys
      Else
        ReDim Preserve m_aEntrys(nCnt - 2) As Entry
      End If
    
    ElseIf nIndex = 0 Then              ' handle case of Head
      For i = nIndex To nCnt - 2
        m_aEntrys(i) = m_aEntrys(i + 1)
      Next i
      ReDim Preserve m_aEntrys(nCnt - 2) As Entry
    
    Else                                ' handle case of middle
      ' collapse the array
      For i = nIndex To nCnt - 2
        m_aEntrys(i) = m_aEntrys(i + 1)
      Next i
      ReDim Preserve m_aEntrys(nCnt - 2) As Entry
    End If
  End If
End Sub


'==================================================================
' access by ID
'==================================================================
'------------------------------
Public Function GetAllEntrysWithID(ByVal ID As Long, aTag As Variant, aVal As Variant) As Long
  ' get all tags & values for given ID
  ' return number found
  Dim uBnd As Long, lBnd As Long, i As Long
  Dim nRet As Long
  
  On Error Resume Next
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    For i = lBnd To uBnd
      If m_aEntrys(i).ID = ID Then
        ReDim Preserve aTag(nRet) As Variant
        ReDim Preserve aVal(nRet) As Variant
        aTag(nRet) = m_aEntrys(i).tag
        aVal(nRet) = m_aEntrys(i).Value
        nRet = nRet + 1
      End If
    Next i
  End If
  '
  GetAllEntrysWithID = nRet
  
End Function
'------------------------------
Public Sub GetEntryWithID(ByVal ID As Long, strTag As String, strVal As String)
  ' get tag & value for given ID
  Dim uBnd As Long, lBnd As Long, i As Long
  On Error Resume Next
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    For i = lBnd To uBnd
      If m_aEntrys(i).ID = ID Then
        strVal = m_aEntrys(i).Value
        strTag = m_aEntrys(i).tag
        Exit Sub
      End If
    Next i
  End If
End Sub
'------------------------------
Public Sub SetEntryWithID(ByVal ID As Long, ByVal strTag As String, ByVal strVal As String)
  ' set tag & value for given ID
  ' if not found, create new one and add
  AddEntryWithID ID, strTag, strVal
End Sub
'------------------------------
Private Function UpdateEntryWithID(ByVal ID As Long, ByVal strTag As String, ByVal strVal As String) As Boolean
  ' find and update entry. return false if can't find
  Dim uBnd As Long, lBnd As Long, i As Long
  
  On Error Resume Next
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    For i = lBnd To uBnd
      If m_aEntrys(i).ID = ID And m_aEntrys(i).tag = strTag Then
        ' set it to me
        If m_aEntrys(i).Value <> strVal Then m_bDirty = True
        m_aEntrys(i).Value = strVal
        m_aEntrys(i).tag = strTag
        UpdateEntryWithID = True
        Exit Function
      End If
    Next i
  End If
End Function

'------------------------------
Private Sub AddEntryWithID(ByVal ID As Long, ByVal strTag As String, ByVal strVal As String)
  ' move to it if have it, otherwise create new and then move to it
  Dim uBnd As Long, lBnd As Long
  
  On Error Resume Next
  If UpdateEntryWithID(ID, strTag, strVal) Then Exit Sub
  
  m_bDirty = True
  Err = 0
  uBnd = UBound(m_aEntrys)
  lBnd = LBound(m_aEntrys)
  If Err = 0 Then
    ' create new one
    Err = 0
    ReDim Preserve m_aEntrys(uBnd - lBnd + 1) As Entry
    m_aEntrys(uBnd - lBnd + 1).ID = ID
    m_aEntrys(uBnd - lBnd + 1).tag = strTag
    m_aEntrys(uBnd - lBnd + 1).Value = strVal
  Else
    ' none. create 1st one
    Err = 0 ' clear err
    ReDim m_aEntrys(0) As Entry
    m_aEntrys(0).ID = ID
    m_aEntrys(0).tag = strTag
    m_aEntrys(0).Value = strVal
  End If
End Sub

'==================================================================
' GeFields
'==================================================================
'------------------------------
Public Function SaveGeObjects(GeCtrl As CG, aGeIDs As Variant) As Boolean
  ' save all fields is all Geobjects in array of GeIDs to storage
  ' if no entry exists, create it
  Dim iLow As Long, iHigh As Long, i As Long
  Dim nGeID As Long
  
  On Error Resume Next
  ' if error, then probably nothing in array !
  iLow = LBound(aGeIDs):      iHigh = UBound(aGeIDs)
  If Err <> 0 Or iHigh < 0 Then
    Err = 0
    SaveGeObjects = True
    Exit Function
  End If
  ''
  For i = iLow To iHigh
    nGeID = aGeIDs(i)
    ConstructFieldList GeCtrl, nGeID, 0
  Next i
  '
  SaveGeObjects = True
End Function


'------------------------------
Private Sub ConstructFieldList(GeCtrl As CG, nGeID As Long, iFld As Integer)
  ' build up Entrys from CG Shape

  Dim strFldName As String
  Dim strFldValue As String
  Dim nFlds As Integer
  Dim nGeFldType As Integer
  Dim nGeIDA As Long
  Dim iFldA As Integer

'  Dim strTag As String
  
  On Error Resume Next
  If nGeID > 0 Then
    ' loop through all objects
    If GeCtrl.ShapeSetCurrent(nGeID) Then
      nFlds = GeCtrl.ShapeFieldCount
      For iFld = 0 To nFlds - 1
        If GeCtrl.ShapeSetCurrentField(iFld) Then
          If GeCtrl.ShapeGetFieldNameValue(strFldName, strFldValue) Then
            
            ' update my list of entries
            SetEntryWithID nGeID, strFldName, strFldValue

'            strTag = nGeID & "ID_" & strFldName     ' ie:  12ID_Drawn,   1245ID_ItemID
'            Entry(strTag) = strFldValue
''            Entry(strFldName) = strFldValue
            
            ' 2 = ShapeField, 1 = TextField, 0 = invalid
            nGeFldType = GeCtrl.ShapeGetFieldType
              
            ' ShapeField, step into it as well
            If nGeFldType = 2 Then
              If GeCtrl.ShapeSelectMember(iFld, nGeIDA) Then
                iFldA = iFld
                ConstructFieldList GeCtrl, nGeIDA, iFldA
                ' reset back
                GeCtrl.ShapeSetCurrent nGeID
              End If
            End If
          End If
        End If
      '
      Next iFld
    End If
  End If
End Sub



'==================================================================
' Storage
'==================================================================
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
  Dim pb As PropertyBag
  Dim uBnd As Long, lBnd As Long, i As Long
  Dim nCnt As Long
  Dim aVar As Variant
  Dim nSchema As Integer
  Dim strKey As String
  Dim iCur As Long
  Dim strName As String
  
  On Error Resume Next
    
  ' no name, no file ops!
  If Len(m_strName) = 0 Then Exit Function
  strName = m_strName
  Set pb = New PropertyBag
  
  If bSave Then   '' SAVING
    If m_bReadOnly Then Exit Function
    
    ' write controlling data
    nSchema = c_nSchema
    nCnt = Count
    pb.WriteProperty "Schema", nSchema, 0
    pb.WriteProperty "NumEntrys", nCnt, 0
    ' write entrys - programmatic key,   userKey and userVal
    If nCnt > 0 Then
      uBnd = UBound(m_aEntrys)
      lBnd = LBound(m_aEntrys)
      iCur = 1
      For i = lBnd To uBnd
        strKey = "T" & iCur:   pb.WriteProperty strKey, m_aEntrys(i).tag, ""
        strKey = "V" & iCur:   pb.WriteProperty strKey, m_aEntrys(i).Value, ""
        strKey = "G" & iCur:   pb.WriteProperty strKey, m_aEntrys(i).ID, 0
        iCur = iCur + 1
'        Debug.Print "SAVE: " & strKey & "," & m_aEntrys(i).Tag & "," & m_aEntrys(i).Value
      Next i
    End If
    '
    If bOtherFile Then
      GeCtrl.SaveNamedStorageToFile strFile, strName, pb.Contents
    Else
      GeCtrl.SaveNamedStorage strName, pb.Contents
    End If
    If Err = 0 Then
      DoSerializeToGe = True
      m_bDirty = False
    End If
    
  Else    '' LOADING
    DestroyAll
    If bOtherFile Then
      GeCtrl.LoadNamedStorageFromFile strFile, strName, aVar
    Else
      GeCtrl.LoadNamedStorage strName, aVar
    End If
    If Err = 0 Then
      pb.Contents = aVar    ' assign to propBags contents
      ' read controlling data
      nSchema = pb.ReadProperty("Schema", 0)
      nCnt = pb.ReadProperty("NumEntrys", 0)
      If nCnt > 0 Then
        ReDim Preserve m_aEntrys(nCnt - 1) As Entry
        iCur = 1
        For i = 0 To nCnt - 1
          strKey = "T" & iCur:    m_aEntrys(i).tag = pb.ReadProperty(strKey, "")
          strKey = "V" & iCur:    m_aEntrys(i).Value = pb.ReadProperty(strKey, "")
          strKey = "G" & iCur:    m_aEntrys(i).ID = pb.ReadProperty(strKey, 0)
          iCur = iCur + 1
'          Debug.Print "LOAD: " & strKey & "," & m_aEntrys(i).Tag & "," & m_aEntrys(i).Value
        Next i
      End If
      '
      DoSerializeToGe = True
      m_bDirty = False
    End If
  End If
End Function


