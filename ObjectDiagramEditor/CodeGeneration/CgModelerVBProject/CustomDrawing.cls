VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CustomDrawing"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'======================================================================================
'
' Module:   CustomDrawing
' holds the UDItems and other drawing info
'
'--------------------------------------------------------------------------------------
'======================================================================================
Option Explicit


'=================================================================
' Start of Declarations Section
'=================================================================

Private m_bDirty As Boolean
Private m_bPropsOnly As Boolean
Private m_UDIItems As UserDefinedItems

'=================================================================
' End of Declarations Section
'=================================================================

'----------------------
Private Sub Class_Initialize()
  Set m_UDIItems = New UserDefinedItems
End Sub
'----------------------
Private Sub Class_Terminate()
  DestroyAll
  Set m_UDIItems = Nothing
End Sub

'------------------------------
Public Sub DestroyAll()
  If Not m_UDIItems Is Nothing Then m_UDIItems.DestroyAll
End Sub

'------------------------------
Public Sub FlushMembers()
  DestroyAll
End Sub

'-------------------------------
Public Property Get UDIItems() As UserDefinedItems
  Set UDIItems = m_UDIItems
End Property
'-------------------------------
Public Sub AddToCollection(coll As Collection)
  ' add all items and the Drawing itself to collection
  coll.Add Me
  m_UDIItems.AddToCollection coll
End Sub

'------------------------------
Public Property Let IsDirty(bVal As Boolean)
  m_bDirty = bVal
End Property
Public Property Get IsDirty() As Boolean
  IsDirty = m_bDirty
End Property


'------------------------------
Public Function Copy(DwgNew As CustomDrawing) As Boolean
  ' copy me to new
  Dim bRet As Boolean
  Dim i As Long
  Dim UDIItemsNew As UserDefinedItems
  Dim Items As Collection
  Dim objUDI As UserDefinedItem
  Dim objUDINew As UserDefinedItem
  Dim udiIDOld As Long
  
  On Error Resume Next
  
  Set DwgNew = New CustomDrawing
  DwgNew.AssumePropsFromObj Me
  
  ' Items and Cables
  Set UDIItemsNew = DwgNew.UDIItems
  Set Items = m_UDIItems.Items
  
  bRet = True
  For i = 1 To Items.count
    bRet = False
    Set objUDI = Items.Item(i)
    udiIDOld = objUDI.SIDID
    objUDI.Copy objUDINew
    If objUDINew Is Nothing Then Exit For
    bRet = True
      ' setup for further replace/hookup operations to Ge darwing
    objUDINew.OldSIDID = udiIDOld
      ' add new item to newitems
    UDIItemsNew.AddItem objUDINew
  Next i
  '
  Copy = bRet
  
  #If APP_DEBUG Then
  VERIFY_ERR
  #End If
End Function
'-------------------------------
Public Sub AssumePropsFromObj(objOrig As CustomDrawing)
  ' assume the relevant properties of the original object
  On Error Resume Next
  With objOrig
  End With

#If APP_DEBUG Then
VERIFY_ERR
#End If
End Sub

'------------------------------
Public Function CopyItem(objUDI As UserDefinedItem) As UserDefinedItem
  ' copy item
  Dim objnew As UserDefinedItem
  
  On Error Resume Next
  If objUDI.Copy(objnew) Then
    If m_UDIItems.AddItem(objnew) Then
      Set CopyItem = objnew
      m_bDirty = True
    Else
      Set objnew = Nothing
    End If
  End If
  
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'================================================================
' Object retrieval
'================================================================
'------------------------------
Public Function Find(lSIDID As Long) As UserDefinedItem
  Set Find = m_UDIItems.Find(lSIDID)
End Function
'-------------------------------
Public Function DeleteItem(lSIDID As Long) As Boolean
  Dim objUDI As UserDefinedItem
  
  On Error Resume Next
  Set objUDI = Find(lSIDID)
  DeleteItem = m_UDIItems.DeleteItem(lSIDID)

  #If APP_DEBUG Then
  VERIFY_ERR
  #End If
End Function
'-------------------------------
Public Function RemoveItem(lSIDID As Long) As Boolean
  '
  Dim objUDI As UserDefinedItem
  
  On Error Resume Next
  Set objUDI = Find(lSIDID)
  RemoveItem = m_UDIItems.RemoveItem(lSIDID)
End Function


'================================================================
' Storage
'================================================================
'-------------------------------
'Public Function SerializeToGeFile(GeCtrl As CG, ByVal bSave As Boolean, ByVal strFile As String) As Boolean
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
Private Function DoSerializeToGe(CGCtrl As CG, ByVal bSave As Boolean, _
                         ByVal strFile As String, ByVal bOtherFile As Boolean) As Boolean
  ' save to file stg
  On Error Resume Next
  
  If bSave Then   '' SAVING
    DoSerializeToGe = m_UDIItems.SerializeToGe(CGCtrl, bSave)
    m_bDirty = False
  Else    '' LOADING
    DestroyAll
    DoSerializeToGe = m_UDIItems.SerializeToGe(CGCtrl, bSave)
    m_bDirty = False
  End If
  '
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
  If Not Err = 0 Then
      #If APP_DEBUG Then
        Dim strMsg As String
        strMsg = TypeName(Me) & ":VERIFY_ERR Failed:" & Error
        gMsgWnd.LogMessage strMsg
      #End If
    VERIFY_ERR = False
  End If
End Function


