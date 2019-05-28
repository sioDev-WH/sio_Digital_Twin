VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "IntegerParameters"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
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
Private m_bDirty As Boolean

'=================================================================
' End of Declarations Section
'=================================================================

'-------------------------------
Private Sub Class_Initialize()
  Set m_collItem = New Collection
End Sub

'-------------------------------
Private Sub Class_Terminate()
  DestroyAll
  Set m_collItem = Nothing
End Sub

'-------------------------------
Public Sub Copy(tgt_coll As IntegerParameters)
  Dim i As Long
  Dim new_obj As IntegerParameter
  Dim src_obj As IntegerParameter
  
  For i = 1 To m_collItem.count
    Set new_obj = New IntegerParameter
    Set src_obj = m_collItem(i)
    src_obj.Copy new_obj
    tgt_coll.Add new_obj
  Next i
End Sub

'-------------------------------
Public Sub Add(obj As IntegerParameter)
  m_collItem.Add obj
End Sub

'-------------------------------
Property Get Items() As Collection
  Set Items = m_collItem
End Property

'-------------------------------
Public Sub DestroyAll()
  Dim i As Long
  Dim obj As IntegerParameter
  
  On Error Resume Next
  If Not m_collItem Is Nothing Then
    For i = 1 To m_collItem.count
      Set obj = m_collItem.Item(1)
      obj.DestroyAll
      m_collItem.Remove 1
    Next i
  End If
  
End Sub

'-------------------------------
'================================================================
' Storage
'================================================================
'-------------------------------
Public Function SerializeToPropertyBag(PropBag As PropertyBag, ByVal strKeyIn As String, ByVal bSave As Boolean) As Boolean
  ' save to propBag
  Dim nSchema As Integer
  Dim obj As IntegerParameter
  Dim i As Long
  Dim nCount As Long
  
  On Error Resume Next
  
  If bSave Then   '' SAVING
    ' write controlling data
    nSchema = 0
    nCount = m_collItem.count
    
    PropBag.WriteProperty strKeyIn & "S", nSchema, 0
    PropBag.WriteProperty strKeyIn & "Count", nCount, 0
    
    For i = 1 To nCount
      Set obj = m_collItem.Item(i)
      obj.SerializeToPropertyBag PropBag, strKeyIn & "IPar(" & i & ")", bSave
    Next i
    
    SerializeToPropertyBag = True
  
  Else    '' LOADING
    nSchema = PropBag.ReadProperty(strKeyIn & "S", 0)
    nCount = PropBag.ReadProperty(strKeyIn & "Count", 0)
    
    For i = 1 To nCount
      Set obj = New IntegerParameter
      obj.SerializeToPropertyBag PropBag, strKeyIn & "IPar(" & i & ")", bSave
      m_collItem.Add obj
    Next i
    
    SerializeToPropertyBag = True
  End If
  '
  m_bDirty = False
  
End Function





