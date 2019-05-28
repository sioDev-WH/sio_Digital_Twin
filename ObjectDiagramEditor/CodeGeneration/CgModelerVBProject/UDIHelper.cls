VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "UDIHelper"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
'''''''''''''''''''''''''''''''''''''''''''''''''''''''
' UDIHelper Class
' ---------------
' Used for writing Shape definitions back to the UML
' project.  Since there can be several shape definitions
' for the same class, they have to be collected together
' before they can be saved to a Class's property.
'
'''''''''''''''''''''''''''''''''''''''''''''''''''''''

Public m_strXML As String
Public m_strClassName As String
Public m_strPackageName As String

Private Sub Class_Initialize()
    m_strClassName = ""
    m_strPackageName = ""
    m_strXML = ""
End Sub
