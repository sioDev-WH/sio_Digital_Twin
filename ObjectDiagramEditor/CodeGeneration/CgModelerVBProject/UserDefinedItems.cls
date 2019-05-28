VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "UserDefinedItems"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'======================================================================================
'
' Module:   UserDefinedItems (manages UDIs)
'
'--------------------------------------------------------------------------------------
'======================================================================================


Option Explicit


'=================================================================
' Start of Declarations Section
'=================================================================

Private m_collItem As Collection

Private m_OwnerSIDID As Long
Private m_nNextID As Long ' next avail UDI SIDID

'=================================================================
' End of Declarations Section
'=================================================================

'-------------------------------
Private Sub Class_Initialize()
  Set m_collItem = New Collection
  m_nNextID = 1
End Sub

'-------------------------------
Private Sub Class_Terminate()
  DestroyAll
  Set m_collItem = Nothing
End Sub

'-------------------------------
Property Get Items() As Collection
  Set Items = m_collItem
End Property

Public Sub GetItemsByProcessTag(ProcessTag As String, coll As Collection)
  Dim aUDI As UserDefinedItem
  
  For Each aUDI In m_collItem
    If aUDI.ProcessTag = ProcessTag Then
      coll.Add aUDI
    End If
  Next
End Sub

'-------------------------------
Public Sub DestroyAll()
  Dim i As Long
  Dim objUDI As UserDefinedItem
  
  On Error Resume Next
  If Not m_collItem Is Nothing Then
    For i = 1 To m_collItem.count
      Set objUDI = m_collItem.Item(1)
      objUDI.DestroyAll
      m_collItem.Remove 1
    Next i
  End If
  ''
  m_nNextID = 1
  
End Sub


'-------------------------------
Public Function AddItem(objUDI As UserDefinedItem) As Boolean
  ' just add and set the SIDID
  On Error Resume Next
  AddItemToCollection objUDI
  AddItem = True
End Function
'-------------------------------
Public Function AddNewItem() As UserDefinedItem
  ' create and add
  Dim objUDI As UserDefinedItem
  On Error Resume Next
  Set objUDI = New UserDefinedItem
  AddItemToCollection objUDI
  Set AddNewItem = objUDI
  
  #If APP_DEBUG Then
  VERIFY_ERR
  #End If
End Function

'-------------------------------
Public Function Find(lSIDID As Long) As UserDefinedItem
  Dim nCount As Integer
  Dim i As Integer
  Dim objUDI As UserDefinedItem
  
  On Error Resume Next
  nCount = m_collItem.count
  For i = 1 To nCount
    Set objUDI = m_collItem(i)
    If objUDI.SIDID = lSIDID Then
      Set Find = objUDI
      Exit For
    End If
  Next i
  
  #If APP_DEBUG Then
  VERIFY_ERR
  #End If
End Function

'-------------------------------
Private Sub CreateUDIItem(objUDI As UserDefinedItem)
  Set objUDI = New UserDefinedItem
  m_collItem.Add objUDI
End Sub

'-------------------------------
Public Sub AddItemToCollection(objUDI As UserDefinedItem)
  m_collItem.Add objUDI
  objUDI.SIDID = m_nNextID
  m_nNextID = m_nNextID + 1
End Sub

'-------------------------------
Public Sub AddToCollection(coll As Collection)
  ' add all items to collection
  Dim objUDI As UserDefinedItem
  For Each objUDI In m_collItem
    coll.Add objUDI
  Next
End Sub

'------------------------------
Public Function Copy(objnew As UserDefinedItems) As Boolean
  ' copy me to new - ASSUME next is an existing object
  Dim objUDI As UserDefinedItem
  Dim objNewItem As UserDefinedItem
  Dim i As Long
  On Error Resume Next
  
  For i = 1 To m_collItem.count
    Set objUDI = m_collItem(i)
    If objUDI.Copy(objNewItem) Then
      objnew.AddItemToCollection objNewItem
    Else
      objnew.DestroyAll
      Copy = False
      Exit Function
    End If
  Next
  '
  Copy = True
  
  #If APP_DEBUG Then
  VERIFY_ERR
  #End If
End Function

'-------------------------------
Public Function DeleteItem(lSIDID As Long) As Boolean
  Dim nCount As Long
  Dim i As Long
  Dim objUDI As UserDefinedItem
  
  On Error Resume Next
  nCount = m_collItem.count
  For i = 1 To nCount
    Set objUDI = m_collItem.Item(i)
    If objUDI.SIDID = lSIDID Then
      objUDI.DestroyAll
      m_collItem.Remove i
      DeleteItem = True
      Exit For
    End If
  Next i
End Function
'-------------------------------
Public Function RemoveItem(lSIDID As Long) As Boolean
  ' just remove. Do not destroy
  Dim nCount As Integer
  Dim i As Long
  Dim objUDI As UserDefinedItem
  
  On Error Resume Next
  nCount = m_collItem.count
  For i = 1 To nCount
    Set objUDI = m_collItem.Item(i)
    If objUDI.SIDID = lSIDID Then
      m_collItem.Remove i
      RemoveItem = True
      Exit For
    End If
  Next i
End Function


'================================================================
' Storage
'================================================================
'-------------------------------
'Public Function SerializeToGeFile(GeCtrl As CGCtrlLib.CG, ByVal bSave As Boolean, ByVal strFile As String) As Boolean
Public Function SerializeToGeFile(GeCtrl As Object, ByVal bSave As Boolean, ByVal strFile As String) As Boolean
  ' save/load from some other file
  SerializeToGeFile = DoSerializeToGe(GeCtrl, bSave, strFile, True)
End Function

'-------------------------------
Public Function SerializeToGe(GeCtrl As Object, ByVal bSave As Boolean) As Boolean
  ' serialize to graphic
  SerializeToGe = DoSerializeToGe(GeCtrl, bSave, "", False)
End Function
'-------------------------------
Private Function DoSerializeToGe(GeCtrl As CG, ByVal bSave As Boolean, _
                         ByVal strFile As String, ByVal bOtherFile As Boolean) As Boolean
  ' save to graphic
  Dim i As Long
  Dim objUDI As UserDefinedItem
  Dim nCount As Long
  Dim pb As PropertyBag
  
  Dim aVar As Variant
  Dim nSchema As Integer
  Dim strKey As String
  
  On Error Resume Next

  Set pb = New PropertyBag

  If bSave Then   '' SAVING
  
    nCount = m_collItem.count
    For i = 1 To nCount
      Set objUDI = m_collItem.Item(i)
      strKey = i
      If Not objUDI.SerializeToPropertyBag(pb, strKey, bSave) Then Exit Function
    Next i
    ' write controlling data
    nSchema = 0
    pb.WriteProperty "Schema", nSchema, 0
    pb.WriteProperty "NumUDI", nCount, 0
    pb.WriteProperty "NextID", m_nNextID, 0

    If bOtherFile Then
      GeCtrl.SaveNamedStorageToFile strFile, c_sUDIDataName, pb.Contents
    Else
      GeCtrl.SaveNamedStorage c_sUDIDataName, pb.Contents
    End If
    
    ' save propbag to CG
    If err = 0 Then
      DoSerializeToGe = True
    End If
  Else    '' LOADING
    DestroyAll

    If bOtherFile Then
      GeCtrl.LoadNamedStorageFromFile strFile, c_sUDIDataName, aVar
    Else
      GeCtrl.LoadNamedStorage c_sUDIDataName, aVar
    End If
    
    If err <> 0 Then
      ' assume not there.
      DoSerializeToGe = True
      Exit Function
    End If
    pb.Contents = aVar    ' assign to propBags contents
    
    ' read controlling data
    nSchema = pb.ReadProperty("Schema", 0)
    nCount = pb.ReadProperty("NumUDI", 0)
    m_nNextID = pb.ReadProperty("NextID", 0)
    For i = 1 To nCount
      Set objUDI = New UserDefinedItem
      m_collItem.Add objUDI
      strKey = i
      objUDI.SerializeToPropertyBag pb, strKey, bSave
      
      'TEMPORARY:  Help addition of Shape and Folder attributes to UDI xml schema.
      If objUDI.m_strShape = "" Or objUDI.m_strFolder = "" Then
        Dim strShape As String, strFolder As String
        
        GetShapeAndFolderForGeID objUDI.GeID, strShape, strFolder
        objUDI.m_strFolder = strShape
        objUDI.m_strShape = strFolder
      End If
    Next i
  End If
  
  DoSerializeToGe = True

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
        ShowStatusMsg strMsg
      #End If
    VERIFY_ERR = False
  End If
End Function


