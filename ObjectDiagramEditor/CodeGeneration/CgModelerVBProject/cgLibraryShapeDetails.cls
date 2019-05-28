VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "cgLibraryShapeDetails"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'======================================================================
' ShapeInfo Type for managment of library shapes
'======================================================================
Public strFolderName As String
Public strShapeName As String
Public strShapeNameNew As String
Public lFolderID As Long

Public IconLibrary As String
Public IconFolder As String
Public IconShape As String

Public bModified As Boolean
Public bAdded As Boolean
Public bDeleted As Boolean
Public bConnectorsUpdated As Boolean
Public bForceShapeRegeneration As Boolean

'Keeps a copy of the original connector information, wich will be restored if the user decides to
'cancel his changes
Public bIconUpdated As Boolean
Public m_collConnectors As Collection
Public m_collFace As Collection
Public m_collOrder As Collection

'The following members are used when a new shape is being created.
Private Const DEFAULT_CONNECTOR_SPACING = 0.2
Private Const DEFAULT_WIDTH = 1
Private Const DEFAULT_HEIGHT = 1

Public m_bSizeShape As Boolean          '0 - Connectors will be fit to default shape rectangle
                                        '1 - Shape will be adjusted to user defined connector spacing
Public m_ConnectorSpacing As Single     'Connector spacing for shape generation
Public m_DefaultWidth As Single         'Default width when boundng rectangle isn't being scaled
Public m_DefaultHeight As Single        'Default height when bounding rectangle isn't being scaled


'Keeps track of connector assignment changes
'Form  "Project_Package_Class_Attribute_ConnectorOld_ConnectorNew"
Public m_collConnAssignment As Collection

Public m_UDIDefOriginal As UserDefinedItemDef
Public m_UDIDefNew As UserDefinedItemDef


Private Sub Class_Initialize()
    Set m_collConnectors = New Collection
    Set m_collFace = New Collection
    Set m_collOrder = New Collection
    Set m_collConnAssignment = New Collection
    
    Set m_UDIDefOriginal = Nothing

    strShapeNameNew = ""
    lFolderID = -1
    
    bForceShapeRegeneration = False
    m_bSizeShape = False
    m_ConnectorSpacing = DEFAULT_CONNECTOR_SPACING
    m_DefaultWidth = DEFAULT_WIDTH
    m_DefaultHeight = DEFAULT_HEIGHT
End Sub

Public Sub EmptyCollections()
    Dim i As Integer
    
    On Error Resume Next
    For i = 1 To m_collConnectors.count
        m_collConnectors.Remove 1
        m_collFace.Remove 1
        m_collOrder.Remove 1
    Next i
End Sub
