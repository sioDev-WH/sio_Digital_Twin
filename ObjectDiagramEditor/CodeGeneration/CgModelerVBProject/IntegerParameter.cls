VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "IntegerParameter"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Private m_strName As String
Private m_Value As Long

Public Sub Copy(tgt_obj As IntegerParameter)
  tgt_obj.Name = m_strName
  tgt_obj.Value = m_Value
End Sub

Public Property Get Name() As String
  Name = m_strName
End Property

Public Property Let Name(newName As String)
  m_strName = newName
End Property

Public Property Get Value() As Long
  Value = m_Value
End Property

Public Property Let Value(newValue As Long)
  m_Value = newValue
End Property

Public Sub DestroyAll()

End Sub

'-------------------------------
'================================================================
' Storage
'================================================================
'-------------------------------
Public Function SerializeToPropertyBag(PropBag As PropertyBag, ByVal strKeyIn As String, ByVal bSave As Boolean) As Boolean
  ' save to propBag
  Dim nSchema As Integer
  Dim obj As RealParameter
  Dim i As Long
  
  On Error Resume Next
  
  If bSave Then   '' SAVING
    ' write controlling data
    nSchema = 0
    PropBag.WriteProperty strKeyIn & "S", nSchema, 0
    PropBag.WriteProperty strKeyIn & "Name", m_strName, 0
    PropBag.WriteProperty strKeyIn & "Value", m_Value, 0
  
    SerializeToPropertyBag = True
  
  Else    '' LOADING
    nSchema = PropBag.ReadProperty(strKeyIn & "S", 0)
    m_strName = PropBag.ReadProperty(strKeyIn & "Name", "")
    m_Value = PropBag.ReadProperty(strKeyIn & "Value", 0)
    
    SerializeToPropertyBag = True
  End If
  '
  m_bDirty = False
  
End Function



