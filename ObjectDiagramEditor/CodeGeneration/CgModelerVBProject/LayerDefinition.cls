VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "LayerDefinition"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'======================================================================================
'
' Module:   LayerDefinition
'
'--------------------------------------------------------------------------------------
'======================================================================================


Option Explicit

'=================================================================
' Start of Declarations Section
'=================================================================

' serializable
Private m_nLayer As Integer   ' the CG layer
Private m_strName As String
Private m_bVisible As Boolean
Private m_bPrint As Boolean
Private m_bCanSelect As Boolean
Private m_bCanMove As Boolean

Private m_LineColor As Long    ' index into palette
Private m_FillColor As Long
Private m_LineStyle As Integer
Private m_FillStyle As Integer

Private m_FontHeight As Single

Private m_ToolTipText As String ' so user can make his own

' runtime
Private m_bDirty As Boolean



'=================================================================
' End of Declarations Section
'=================================================================
'-------------------------------
Private Sub Class_Initialize()
  m_bVisible = True
  m_bPrint = True
  m_bCanSelect = True
  m_bCanMove = True
  m_ToolTipText = "Style to use when drawing new objects"
  m_FontHeight = 0.25
  m_FillStyle = GEBS_NULL
  m_LineStyle = GEPS_SOLID
End Sub


'==================================================================
' operations
'==================================================================
'--------------------------
Public Sub SetPropertiesToGe(GeCtrl As CG)
  ' transfer props to CG
  On Error Resume Next
  With GeCtrl
    .Layer = Layer
    
'    .PenColor = LineColor
    
    
'    .PenStyle = LineStyle
'    .BrushColor = FillColor
'
'    .BrushStyle = FillStyle

'    ' set hatch, if style is hatched
'    .BrushHatch = BrushHatch

'    // style
'    static struct {
'      short nStyle;
'      short nHatch;
'    } BASED_CODE tblStyle[] = {
'      { BS_NULL,    0             },
'      { BS_SOLID,   0             },
'      { BS_HATCHED, HS_HORIZONTAL },
'      { BS_HATCHED, HS_VERTICAL   },
'      { BS_HATCHED, HS_FDIAGONAL  },
'      { BS_HATCHED, HS_BDIAGONAL  },
'      { BS_HATCHED, HS_CROSS      },
'      { BS_HATCHED, HS_DIAGCROSS  },
'      { BS_TRANPARENT, 0      }
'    };
    
'     .FontHeight = m_FontHeight
  
  End With
End Sub
'--------------------------
Public Sub GetPropertiesFromGe(GeCtrl As CG)
  ' get props from CG
  On Error Resume Next
  With GeCtrl
    LineColor = .PenColor
    LineStyle = .PenStyle
    FillColor = .BrushColor
    FillStyle = .BrushStyle
    FontHeight = .FontHeight
  End With
End Sub


'==================================================================
' Properties
'==================================================================
'-------------------------------
Public Sub AssumePropsFromObj(objCopy As LayerDefinition)
  ' assume props of it
  With objCopy
    ToolTipText = .ToolTipText
    LineColor = .LineColor
    LineStyle = .LineStyle
    FillColor = .FillColor
    FillStyle = .FillStyle
    Visible = .Visible
    CanPrint = .CanPrint
    CanSelect = .CanSelect
    CanMove = .CanMove
    .FontHeight = FontHeight
  End With
End Sub


'-------------------------------
Public Property Get IsDefault() As Boolean
  ' if layer 0, its the 'default' layer
  IsDefault = IIf(m_nLayer = 0, True, False)
End Property

'-------------------------------
Public Property Get IsDirty() As Boolean
  IsDirty = m_bDirty
End Property
Public Property Let IsDirty(ByVal bVal As Boolean)
  m_bDirty = bVal
End Property

'-------------------------------
Public Property Get FontHeight() As Single
  FontHeight = m_FontHeight
End Property
Public Property Let FontHeight(ByVal vVal As Single)
  If vVal > 0# Then
    If m_FontHeight <> vVal Then m_bDirty = True
    m_FontHeight = vVal
  End If
End Property

'-------------------------------
Public Property Let ToolTipText(ByVal strVal As String)
  ' so user can make his own
  If m_ToolTipText <> strVal Then m_bDirty = True
  m_ToolTipText = strVal
End Property
Public Property Get ToolTipText() As String
  ToolTipText = m_ToolTipText
End Property


'-------------------------------
Public Property Get LineColor() As Long
  LineColor = m_LineColor
End Property
Public Property Let LineColor(ByVal nVal As Long)
  If m_LineColor <> nVal Then m_bDirty = True
  m_LineColor = nVal
End Property
'-------------------------------
Public Property Get LineStyle() As Integer
  LineStyle = m_LineStyle
End Property
Public Property Let LineStyle(ByVal nVal As Integer)
  If m_LineStyle <> nVal Then m_bDirty = True
  m_LineStyle = nVal
End Property
'-------------------------------
Public Property Get FillColor() As Long
  FillColor = m_FillColor
End Property
Public Property Let FillColor(ByVal nVal As Long)
  If m_FillColor <> nVal Then m_bDirty = True
  m_FillColor = nVal
End Property
'-------------------------------
Public Property Get FillStyle() As Integer
  FillStyle = m_FillStyle
End Property
Public Property Let FillStyle(ByVal nVal As Integer)
  If m_FillStyle <> nVal Then m_bDirty = True
  m_FillStyle = nVal
End Property

'-------------------------------
Public Property Get Layer() As Integer
  Layer = m_nLayer
End Property
Public Property Let Layer(ByVal nVal As Integer)
  If m_nLayer <> nVal Then m_bDirty = True
  m_nLayer = nVal
End Property
'-------------------------------
Public Property Get Name() As String
  Name = m_strName
End Property
Public Property Let Name(ByVal strVal As String)
'  ' block using , in name
'  If InStr(strVal, c_sLayerDefStgSep) = 0 Then
    If m_strName <> strVal Then m_bDirty = True
    m_strName = strVal
'  End If
End Property
'-------------------------------
Public Property Get Visible() As Boolean
  Visible = m_bVisible
End Property
Public Property Let Visible(ByVal bVal As Boolean)
  If m_bVisible <> bVal Then m_bDirty = True
  m_bVisible = bVal
End Property
'-------------------------------
Public Property Get CanPrint() As Boolean
  CanPrint = m_bPrint
End Property
Public Property Let CanPrint(ByVal bVal As Boolean)
  If m_bPrint <> bVal Then m_bDirty = True
  m_bPrint = bVal
End Property
'-------------------------------
Public Property Get CanSelect() As Boolean
  CanSelect = m_bCanSelect
End Property
Public Property Let CanSelect(ByVal bVal As Boolean)
  If m_bCanSelect <> bVal Then m_bDirty = True
  m_bCanSelect = bVal
End Property
'-------------------------------
Public Property Get CanMove() As Boolean
  CanMove = m_bCanMove
End Property
Public Property Let CanMove(ByVal bVal As Boolean)
  If m_bCanMove <> bVal Then m_bDirty = True
  m_bCanMove = bVal
End Property

'==================================================================
' Storage
'==================================================================
'-------------------------------
Public Function SerializeToPropertyBag(PropBag As PropertyBag, ByVal strKeyIn As String, ByVal bSave As Boolean) As Boolean
  Dim nSchema As Integer
  
  On Error Resume Next
  ' save to propBag
  
  If bSave Then   '' SAVING
    ' write controlling data
    nSchema = 0
    PropBag.WriteProperty strKeyIn & "S", nSchema, 0
    PropBag.WriteProperty strKeyIn & "LA", m_nLayer, 0
    PropBag.WriteProperty strKeyIn & "N", m_strName, ""
    PropBag.WriteProperty strKeyIn & "V", m_bVisible, 0
    PropBag.WriteProperty strKeyIn & "P", m_bPrint, 0
    PropBag.WriteProperty strKeyIn & "L", m_bCanSelect, 0   ' locked
    PropBag.WriteProperty strKeyIn & "M", m_bCanMove, 0
    PropBag.WriteProperty strKeyIn & "LC", m_LineColor, 0
    PropBag.WriteProperty strKeyIn & "FC", m_FillColor, 0
    PropBag.WriteProperty strKeyIn & "LT", m_LineStyle, 0
    PropBag.WriteProperty strKeyIn & "FT", m_FillStyle, 0
    PropBag.WriteProperty strKeyIn & "TH", m_FontHeight, 0
    SerializeToPropertyBag = True
  
  Else    '' LOADING
    nSchema = PropBag.ReadProperty(strKeyIn & "S", 0)
    m_nLayer = PropBag.ReadProperty(strKeyIn & "LA", 0)
    m_strName = PropBag.ReadProperty(strKeyIn & "N", "")
    m_bVisible = PropBag.ReadProperty(strKeyIn & "V", True)
    m_bPrint = PropBag.ReadProperty(strKeyIn & "P", False)
    m_bCanSelect = PropBag.ReadProperty(strKeyIn & "L", True)
    m_bCanMove = PropBag.ReadProperty(strKeyIn & "M", True)
    m_LineColor = PropBag.ReadProperty(strKeyIn & "LC", 0)
    m_FillColor = PropBag.ReadProperty(strKeyIn & "FC", 0)
    m_LineStyle = PropBag.ReadProperty(strKeyIn & "LT", 0)
    m_FillStyle = PropBag.ReadProperty(strKeyIn & "FT", 0)
    m_FontHeight = PropBag.ReadProperty(strKeyIn & "TH", 0)
    
    SerializeToPropertyBag = True
  End If
  '
  m_bDirty = False
  
End Function

