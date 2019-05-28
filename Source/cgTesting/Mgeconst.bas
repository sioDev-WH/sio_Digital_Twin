Attribute VB_Name = "mGEConst"
'======================================================================================
'
' Module:   mGEConst - Constants applicable to GeOCX
'
'--------------------------------------------------------------------------------------
'======================================================================================

Option Explicit



'=====================================================================
' Range Constants
'=====================================================================
Global Const ROTATE_MIN = -360  ' Rotation - Degrees
Global Const ROTATE_MAX = 360
Global Const LAYER_MIN = 0  ' Layer
Global Const LAYER_MAX = 32767


'=====================================================================
' Global Constants for the GE GDI Objects
'=====================================================================
'
' Pen  **************************
'
' Style
'
Global Const GEPS_SOLID = 0
Global Const GEPS_DASH = 1
Global Const GEPS_DOT = 2
Global Const GEPS_DASHDOT = 3
Global Const GEPS_DASHDOTDOT = 4
Global Const GEPS_NULL = 5
Global Const GEPS_INSIDEFRAME = 6

'
' Brush  **************************
'
' Style
'
Global Const GEBS_SOLID = 0
Global Const GEBS_NULL = 1
Global Const GEBS_HATCHED = 2
Global Const GEBS_PATTERN = 3
Global Const GEBS_INDEXED = 4
Global Const GEBS_DIBPATTERN = 5
Global Const GEBS_TRANSPARENT = 15   ' // 0x0F

'
' Hatch
'
Global Const GEHS_HORIZONTAL = 0
Global Const GEHS_VERTICAL = 1
Global Const GEHS_FDIAGONAL = 2
Global Const GEHS_BDIAGONAL = 3
Global Const GEHS_CROSS = 4
Global Const GEHS_DIAGCROSS = 5


#If 0 Then
'
' Font  **************************
'
' weight
'
    // weight
    enum {
      WEIGHT_DONTCARE   = FW_DONTCARE,
      WEIGHT_THIN       = FW_THIN,
      WEIGHT_EXTRALIGHT = FW_EXTRALIGHT,
      WEIGHT_LIGHT      = FW_LIGHT,
      WEIGHT_NORMAL     = FW_NORMAL,
      WEIGHT_MEDIUM     = FW_MEDIUM,
      WEIGHT_SEMIBOLD   = FW_SEMIBOLD,
      WEIGHT_BOLD       = FW_BOLD,
      WEIGHT_EXTRABOLD  = FW_EXTRABOLD,
      WEIGHT_HEAVY = FW_HEAVY
    };
'
' pitch
'
    // pitch
    enum {
      PITCH_DEFAULT  = DEFAULT_PITCH,
      PITCH_FIXED    = FIXED_PITCH,
      PITCH_VARIABLE = VARIABLE_PITCH,
      PITCH_MASK     = 0x0F
    };
'
' family
'
    // family
    enum {
      FAMILY_DONTCARE   = FF_DONTCARE,
      FAMILY_ROMAN      = FF_ROMAN,
      FAMILY_SWISS      = FF_SWISS,
      FAMILY_MODERN     = FF_MODERN,
      FAMILY_SCRIPT     = FF_SCRIPT,
      FAMILY_DECORATIVE = FF_DECORATIVE,
      FAMILY_MASK       = 0xF0
    };
#End If

'=====================================================================
' Global Constants for the Graphics Engine Tools
'=====================================================================
Global Const GETOOL_NONE = 0
Global Const GETOOL_SELECT = 1
Global Const GETOOL_PICK = 2
Global Const GETOOL_ARC = 3
Global Const GETOOL_ARCCENTERRADIUS = 4
Global Const GETOOL_ARCDIAMETER = 5
Global Const GETOOL_CHORD = 6
Global Const GETOOL_CHORDCENTERRADIUS = 7
Global Const GETOOL_CHORDDIAMETER = 8
Global Const GETOOL_CIRCLECENTERRADIUS = 9
Global Const GETOOL_CIRCLEDIAMETER = 10
Global Const GETOOL_ELLIPSE = 11
Global Const GETOOL_LINE = 12
Global Const GETOOL_PIE = 13
Global Const GETOOL_PIECENTERRADIUS = 14
Global Const GETOOL_PIEDIAMETER = 15
Global Const GETOOL_POLYGON = 16
Global Const GETOOL_POLYLINE = 17
Global Const GETOOL_RECTANGLE = 18
Global Const GETOOL_ROUNDRECT = 19
Global Const GETOOL_SMARTLINE = 20
Global Const GETOOL_TEXT = 21
Global Const GETOOL_TEXTBOX = 22
Global Const GETOOL_FIELD = 23
Global Const GETOOL_CONNECTION = 24
Global Const GETOOL_LINECONNECTPOINT = 25
Global Const GETOOL_JOIN = 26         ' Join Tool
Global Const GETOOL_OPENBEZIER = 27
Global Const GETOOL_REFERENCEPOINT = 28
Global Const GETOOL_CONNECTPOLYLINE = 29
Global Const GETOOL_CONNECTSMARTLINE = 30
Global Const GETOOL_CONNECTLINE = 31
Global Const GETOOL_MULTIVERTEX = 32
Global Const GETOOL_TEXTINSHAPETOOL = 33
Global Const GETOOL_PICKPOINT = 34          ' pick a point
Global Const GETOOL_DIMENSIONLINE = 35          ' DimensionLine
Global Const GETOOL_PLACESELECTION = 36          ' place the selection. Acts like tail-end of a paste operation

'=====================================================================
' Enumeration for the Object Snap Property of the GeOCX
'=====================================================================
Public Enum EGeObjectSnap
  GESNAP_NONE = &H0
  GESNAP_CENTER = &H1
  GESNAP_ENDPOINT = &H2
  GESNAP_INSERT = &H4
  GESNAP_INTERSECTION = &H8
  GESNAP_MIDPOINT = &H10
  GESNAP_NEAREST = &H20
  GESNAP_NODE = &H40
  GESNAP_PERPENDICULAR = &H80
  GESNAP_QUADRANT = &H100
  GESNAP_TANGENT = &H200
  GESNAP_CONNECTPOINT = &H400
  GESNAP_ALL = &H137       ' NOTE: all that are currently supported - 4/15/97
End Enum

'=====================================================================
' Enumeration for object ScaleModes of the GeOCX
'=====================================================================
Public Enum EGeScaleMode
  MODE_ALL = 0
  PROPORTIONAL = 1
  HORIZONTAL = 2
  VERTICAL = 3
  MIRROR = 4
  NONE = 5
End Enum

'=====================================================================
' Enumeration for object RotateModes of the GeOCX
'=====================================================================
Public Enum EGeRotateMode
  MODE_ANY = 0
  MODE_90 = 1
  MODE_NONE = 2
End Enum

'=====================================================================
' Enumeration for object Types from the GeOCX
'=====================================================================
Public Enum EGeObjType
  Invalid = 0
  Pie = 1
  Chord = 2
  Arc = 3
  Ellipse = 4
  Polygon = 5
  Smartline = 6
  Polyline = 7
  RoundRect = 8
  Rectangle = 9
  Shape = 10
  Group = 11
  Text = 12
  TextML = 13
  TextField = 14
  StringField = 15
  Field = 16
  ConnectLinePnt = 17
  RefPoint = 18
  OpenBezier = 19   ' CGeOpenBezier
  Ge3DRect = 20      ' CGe3DRect
  UserGroup = 21 ' CGeUserGroup
  ObjConnector = 22    ' CGeObjConnector
  PolyPolygonA = 23    ' obsolete polypolygon (but may be some around)
  PolyPolygon = 24    ' polypolygon
  ConnectPolyline = 25
  ConnectSmartline = 26
  PictureHolder = 27
  DimensionLine = 28
End Enum

'=====================================================================
' Enumeration for Cursor Types from the GeOCX
'=====================================================================
Public Enum EGeCursorType
  IDC_ARROWBLACK = 10007
'  IDC_ARROW = 10007
  IDC_ARROWHEADBLACK = 103
  IDC_ARROWPLUS = 101
  IDC_CROSSRECT = 106
  IDC_CROSSSMALL = 107
  IDC_NESW = 108
  IDC_NWSE = 111
  IDC_VIEWHORZEDGE = 161
  IDC_VIEWVERTEDGE = 162
  IDC_X = 113
End Enum



