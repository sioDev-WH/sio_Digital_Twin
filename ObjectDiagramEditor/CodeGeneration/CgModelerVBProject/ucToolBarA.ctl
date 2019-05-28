VERSION 5.00
Object = "{8DB9CFCE-3627-11D4-899F-00D0B74A80C3}#2.4#0"; "ABBCAToolbar.ocx"
Begin VB.UserControl ucToolBar 
   Alignable       =   -1  'True
   ClientHeight    =   900
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   12105
   LockControls    =   -1  'True
   ScaleHeight     =   900
   ScaleWidth      =   12105
   Begin ABBCAToolbar.CAToolbar tbFileZoom 
      Height          =   375
      Left            =   0
      Top             =   0
      Width           =   4020
      _ExtentX        =   7091
      _ExtentY        =   661
      BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Appearance      =   1
      ButtonCount     =   14
      PlaySounds      =   0   'False
      CaptionOptions  =   0
      SolidChecked    =   -1  'True
      ShowSeparators  =   -1  'True
      AutoSize        =   -1  'True
      ButtonKey1      =   "FileOpen"
      ButtonPicture1  =   "ucToolBarA.ctx":0000
      ButtonToolTipText1=   "Open existing drawing"
      ButtonKey2      =   "FileSave"
      ButtonPicture2  =   "ucToolBarA.ctx":0352
      ButtonToolTipText2=   "Save current drawing"
      ButtonStyle3    =   2
      ButtonKey4      =   "Cut"
      ButtonPicture4  =   "ucToolBarA.ctx":06A4
      ButtonToolTipText4=   "Cut selection onto clipboard"
      ButtonKey5      =   "Copy"
      ButtonPicture5  =   "ucToolBarA.ctx":09F6
      ButtonToolTipText5=   "Copy selection to clipboard"
      ButtonKey6      =   "Paste"
      ButtonPicture6  =   "ucToolBarA.ctx":0D48
      ButtonToolTipText6=   "Paste from clipboard"
      ButtonKey7      =   "Undo"
      ButtonPicture7  =   "ucToolBarA.ctx":109A
      ButtonToolTipText7=   "Undo last action"
      ButtonStyle8    =   2
      ButtonKey9      =   "ZoomArea"
      ButtonPicture9  =   "ucToolBarA.ctx":13EC
      ButtonToolTipText9=   "Zoom to area"
      ButtonKey10     =   "ZoomIn"
      ButtonPicture10 =   "ucToolBarA.ctx":173E
      ButtonToolTipText10=   "Zoom in by factor of 2"
      ButtonKey11     =   "ZoomOut"
      ButtonPicture11 =   "ucToolBarA.ctx":1A90
      ButtonToolTipText11=   "Zoom out by factor of 2"
      ButtonKey12     =   "ZoomPage"
      ButtonPicture12 =   "ucToolBarA.ctx":1DE2
      ButtonToolTipText12=   "Zoom to full page"
      ButtonKey13     =   "ZoomPrev"
      ButtonPicture13 =   "ucToolBarA.ctx":2134
      ButtonToolTipText13=   "Zoom to previous zoom"
      ButtonKey14     =   "ZoomExtent"
      ButtonPicture14 =   "ucToolBarA.ctx":2486
      ButtonToolTipText14=   "Zoom to extents"
   End
   Begin ABBCAToolbar.CAToolbar tbGeTool 
      Height          =   375
      Left            =   4095
      Top             =   0
      Width           =   4155
      _ExtentX        =   7329
      _ExtentY        =   661
      BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Appearance      =   1
      ButtonCount     =   14
      PlaySounds      =   0   'False
      CaptionOptions  =   0
      SolidChecked    =   -1  'True
      ShowSeparators  =   -1  'True
      AutoSize        =   -1  'True
      ButtonKey1      =   "Select"
      ButtonPicture1  =   "ucToolBarA.ctx":27D8
      ButtonToolTipText1=   "Select tool"
      ButtonGroupID1  =   1
      ButtonKey2      =   "Line"
      ButtonPicture2  =   "ucToolBarA.ctx":2B2A
      ButtonToolTipText2=   "Draw single segment line"
      ButtonGroupID2  =   1
      ButtonKey3      =   "Arc"
      ButtonPicture3  =   "ucToolBarA.ctx":2E7C
      ButtonToolTipText3=   "Draw arc (right click for options)"
      ButtonGroupID3  =   1
      ButtonKey4      =   "Polyline"
      ButtonPicture4  =   "ucToolBarA.ctx":31CE
      ButtonToolTipText4=   "Draw polyline"
      ButtonGroupID4  =   1
      ButtonKey5      =   "SmartLine"
      ButtonPicture5  =   "ucToolBarA.ctx":3520
      ButtonToolTipText5=   "Draw smartline (orthogonal)"
      ButtonGroupID5  =   1
      ButtonKey6      =   "Rectangle"
      ButtonPicture6  =   "ucToolBarA.ctx":3872
      ButtonToolTipText6=   "Draw rectangle"
      ButtonGroupID6  =   1
      ButtonKey7      =   "Polygon"
      ButtonPicture7  =   "ucToolBarA.ctx":3BC4
      ButtonToolTipText7=   "Draw polygon"
      ButtonGroupID7  =   1
      ButtonKey8      =   "Ellipse"
      ButtonPicture8  =   "ucToolBarA.ctx":3F16
      ButtonToolTipText8=   "Draw ellipse"
      ButtonGroupID8  =   1
      ButtonKey9      =   "Chord"
      ButtonPicture9  =   "ucToolBarA.ctx":4268
      ButtonToolTipText9=   "Draw chord (right click for options)"
      ButtonGroupID9  =   1
      ButtonKey10     =   "Pie"
      ButtonPicture10 =   "ucToolBarA.ctx":45BA
      ButtonToolTipText10=   "Draw pie (right click for options)"
      ButtonGroupID10 =   1
      ButtonKey11     =   "Bezier"
      ButtonPicture11 =   "ucToolBarA.ctx":490C
      ButtonToolTipText11=   "Draw open bizier curve"
      ButtonGroupID11 =   1
      ButtonKey12     =   "Text"
      ButtonPicture12 =   "ucToolBarA.ctx":4C5E
      ButtonToolTipText12=   "Draw text (single line)"
      ButtonGroupID12 =   1
      ButtonEnabled13 =   0   'False
      ButtonKey13     =   "MultiVertex"
      ButtonPicture13 =   "ucToolBarA.ctx":4FB0
      ButtonToolTipText13=   "Edit multiple vertices (selected objects only)"
      ButtonGroupID13 =   1
      ButtonKey14     =   "SelectText"
      ButtonPicture14 =   "ucToolBarA.ctx":5302
      ButtonToolTipText14=   "Select text fields in shapes"
      ButtonVisible14 =   0   'False
      ButtonGroupID14 =   1
   End
   Begin ABBCAToolbar.CAToolbar tbSettings 
      Height          =   375
      Left            =   8685
      Top             =   0
      Width           =   2985
      _ExtentX        =   5265
      _ExtentY        =   661
      BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Appearance      =   1
      ButtonCount     =   10
      PlaySounds      =   0   'False
      CaptionOptions  =   0
      SolidChecked    =   -1  'True
      ShowSeparators  =   -1  'True
      AutoSize        =   -1  'True
      ButtonKey1      =   "Vertex"
      ButtonPicture1  =   "ucToolBarA.ctx":5744
      ButtonToolTipText1=   "Vertex Editing mode"
      ButtonKey2      =   "Snap"
      ButtonPicture2  =   "ucToolBarA.ctx":5A96
      ButtonToolTipText2=   "Turn snap on/off"
      ButtonKey3      =   "Ruler"
      ButtonPicture3  =   "ucToolBarA.ctx":5DE8
      ButtonToolTipText3=   "Turn rulers on/off"
      ButtonKey4      =   "Scrollbar"
      ButtonPicture4  =   "ucToolBarA.ctx":610A
      ButtonToolTipText4=   "Turn scrollbars on/off"
      ButtonKey5      =   "Grid"
      ButtonPicture5  =   "ucToolBarA.ctx":642C
      ButtonToolTipText5=   "Turn grid on/off"
      ButtonKey6      =   "Move"
      ButtonPicture6  =   "ucToolBarA.ctx":674E
      ButtonToolTipText6=   "Turn ""move objects only"" on/off"
      ButtonKey7      =   "IsometricMode"
      ButtonPicture7  =   "ucToolBarA.ctx":6AA0
      ButtonToolTipText7=   "Constrain actions to Isometric (30 deg) projection"
      ButtonStyle8    =   2
      ButtonKey9      =   "Distance"
      ButtonPicture9  =   "ucToolBarA.ctx":6DC2
      ButtonToolTipText9=   "Measure distance"
      ButtonKey10     =   "MoveCopy"
      ButtonPicture10 =   "ucToolBarA.ctx":7114
      ButtonToolTipText10=   "Move/copy selected objects"
   End
   Begin ABBCAToolbar.CAToolbar tbArrange 
      Height          =   375
      Left            =   8400
      Top             =   450
      Width           =   3390
      _ExtentX        =   5980
      _ExtentY        =   661
      BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Appearance      =   1
      ButtonCount     =   12
      PlaySounds      =   0   'False
      CaptionOptions  =   0
      SolidChecked    =   -1  'True
      ShowSeparators  =   -1  'True
      AutoSize        =   -1  'True
      ButtonKey1      =   "Group"
      ButtonPicture1  =   "ucToolBarA.ctx":7466
      ButtonToolTipText1=   "Group selected objects"
      ButtonKey2      =   "Ungroup"
      ButtonPicture2  =   "ucToolBarA.ctx":77B8
      ButtonToolTipText2=   "Ungroup selected objects"
      ButtonStyle3    =   2
      ButtonKey4      =   "MoveBack"
      ButtonPicture4  =   "ucToolBarA.ctx":7B0A
      ButtonToolTipText4=   "Make selected objects the rear-most"
      ButtonKey5      =   "MoveFront"
      ButtonPicture5  =   "ucToolBarA.ctx":7E2C
      ButtonToolTipText5=   "Make selected objects the front-most"
      ButtonKey6      =   "MoveBack1"
      ButtonPicture6  =   "ucToolBarA.ctx":814E
      ButtonToolTipText6=   "Move selected objects back 1"
      ButtonKey7      =   "MoveFront1"
      ButtonPicture7  =   "ucToolBarA.ctx":8470
      ButtonToolTipText7=   "Move selected objects forward 1"
      ButtonStyle8    =   2
      ButtonKey9      =   "FlipHorizontal"
      ButtonPicture9  =   "ucToolBarA.ctx":8792
      ButtonToolTipText9=   "Mirror about vertical axis"
      ButtonKey10     =   "FlipVertical"
      ButtonPicture10 =   "ucToolBarA.ctx":8AB4
      ButtonToolTipText10=   "Mirror about horizontal axis"
      ButtonKey11     =   "RotateLeft"
      ButtonPicture11 =   "ucToolBarA.ctx":8DD6
      ButtonToolTipText11=   "Rotate to left 90 degrees"
      ButtonKey12     =   "RotateRight"
      ButtonPicture12 =   "ucToolBarA.ctx":90F8
      ButtonToolTipText12=   "Rotate to right 90 degrees"
   End
   Begin ABBCAToolbar.CAToolbar tbGeTool2 
      Height          =   375
      Left            =   4890
      Top             =   450
      Width           =   3390
      _ExtentX        =   5980
      _ExtentY        =   661
      BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Appearance      =   1
      ButtonCount     =   12
      PlaySounds      =   0   'False
      CaptionOptions  =   0
      SolidChecked    =   -1  'True
      ShowSeparators  =   -1  'True
      AutoSize        =   -1  'True
      ButtonKey1      =   "Circle"
      ButtonPicture1  =   "ucToolBarA.ctx":941A
      ButtonToolTipText1=   "Draw circle (right click for options)"
      ButtonGroupID1  =   1
      ButtonKey2      =   "TextField"
      ButtonPicture2  =   "ucToolBarA.ctx":976C
      ButtonToolTipText2=   "Draw Text Field"
      ButtonGroupID2  =   1
      ButtonKey3      =   "TextMulti"
      ButtonPicture3  =   "ucToolBarA.ctx":9A8E
      ButtonToolTipText3=   "Draw text (multi line)"
      ButtonGroupID3  =   1
      ButtonKey4      =   "RefPoint"
      ButtonPicture4  =   "ucToolBarA.ctx":9DE0
      ButtonToolTipText4=   "Draw reference point"
      ButtonGroupID4  =   1
      ButtonKey5      =   "RoundRect"
      ButtonPicture5  =   "ucToolBarA.ctx":A132
      ButtonToolTipText5=   "Draw round rectangle"
      ButtonGroupID5  =   1
      ButtonStyle6    =   2
      ButtonKey7      =   "ConnectPoint"
      ButtonPicture7  =   "ucToolBarA.ctx":A454
      ButtonToolTipText7=   "Draw connection Point"
      ButtonGroupID7  =   1
      ButtonKey8      =   "ConnectLine"
      ButtonPicture8  =   "ucToolBarA.ctx":A7A6
      ButtonToolTipText8=   "Connection line (single segment)"
      ButtonGroupID8  =   1
      ButtonKey9      =   "ConnectPolyline"
      ButtonPicture9  =   "ucToolBarA.ctx":AAF8
      ButtonToolTipText9=   "Connection line (multi segment)"
      ButtonGroupID9  =   1
      ButtonKey10     =   "ConnectSmartline"
      ButtonPicture10 =   "ucToolBarA.ctx":AE4A
      ButtonToolTipText10=   "Connection line (orthogonal)"
      ButtonGroupID10 =   1
      ButtonStyle11   =   2
      ButtonKey12     =   "DimensionLine"
      ButtonPicture12 =   "ucToolBarA.ctx":B19C
      ButtonToolTipText12=   "Dimension Line"
      ButtonGroupID12 =   1
   End
   Begin ABBCAToolbar.CAToolbar tbAlign 
      Height          =   375
      Left            =   45
      Top             =   450
      Width           =   4740
      _ExtentX        =   8361
      _ExtentY        =   661
      BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Appearance      =   1
      ButtonCount     =   17
      PlaySounds      =   0   'False
      CaptionOptions  =   0
      SolidChecked    =   -1  'True
      ShowSeparators  =   -1  'True
      AutoSize        =   -1  'True
      ButtonKey1      =   "GridLeft"
      ButtonPicture1  =   "ucToolBarA.ctx":B4BE
      ButtonToolTipText1=   "Align left side of selection to grid"
      ButtonKey2      =   "GridTop"
      ButtonPicture2  =   "ucToolBarA.ctx":B7E0
      ButtonToolTipText2=   "Align top of selection to grid"
      ButtonKey3      =   "GridRight"
      ButtonPicture3  =   "ucToolBarA.ctx":BB02
      ButtonToolTipText3=   "Align right side of selection to grid"
      ButtonKey4      =   "GridBottom"
      ButtonPicture4  =   "ucToolBarA.ctx":BE24
      ButtonToolTipText4=   "Align bottom of selection to grid"
      ButtonKey5      =   "GridCenter"
      ButtonPicture5  =   "ucToolBarA.ctx":C146
      ButtonToolTipText5=   "Align center of selection to grid"
      ButtonStyle6    =   2
      ButtonKey7      =   "Left"
      ButtonPicture7  =   "ucToolBarA.ctx":C468
      ButtonToolTipText7=   "Align to left of last item in selection"
      ButtonKey8      =   "Middle"
      ButtonPicture8  =   "ucToolBarA.ctx":C7BA
      ButtonToolTipText8=   "Align to middle of last item in selection"
      ButtonKey9      =   "Right"
      ButtonPicture9  =   "ucToolBarA.ctx":CB0C
      ButtonToolTipText9=   "Align to right of last item in selection"
      ButtonStyle10   =   2
      ButtonKey11     =   "Top"
      ButtonPicture11 =   "ucToolBarA.ctx":CE5E
      ButtonToolTipText11=   "Align to top of last item in selection"
      ButtonKey12     =   "Center"
      ButtonPicture12 =   "ucToolBarA.ctx":D1B0
      ButtonToolTipText12=   "Align to centre of last item in selection"
      ButtonKey13     =   "Bottom"
      ButtonPicture13 =   "ucToolBarA.ctx":D502
      ButtonToolTipText13=   "Align to bottom of last item in selection"
      ButtonStyle14   =   2
      ButtonKey15     =   "Height"
      ButtonPicture15 =   "ucToolBarA.ctx":D854
      ButtonToolTipText15=   "Make all objects the same height as last item in selection"
      ButtonKey16     =   "Width"
      ButtonPicture16 =   "ucToolBarA.ctx":DBA6
      ButtonToolTipText16=   "Make all objects the same width as last item in selection"
      ButtonKey17     =   "Both"
      ButtonPicture17 =   "ucToolBarA.ctx":DEF8
      ButtonToolTipText17=   "Make all objects the same height and width as last item in selection"
   End
   Begin VB.Menu mnuCircleM 
      Caption         =   "Circle"
      Visible         =   0   'False
      Begin VB.Menu mnuCircle 
         Caption         =   "Diameter"
         Index           =   0
      End
      Begin VB.Menu mnuCircle 
         Caption         =   "Center/Radius"
         Index           =   1
      End
   End
   Begin VB.Menu mnuArcM 
      Caption         =   "Arc"
      Visible         =   0   'False
      Begin VB.Menu mnuArc 
         Caption         =   "Bounding"
         Index           =   0
      End
      Begin VB.Menu mnuArc 
         Caption         =   "Diameter"
         Index           =   1
      End
      Begin VB.Menu mnuArc 
         Caption         =   "Center/Radius"
         Index           =   2
      End
   End
   Begin VB.Menu mnuChordM 
      Caption         =   "Chord"
      Visible         =   0   'False
      Begin VB.Menu mnuChord 
         Caption         =   "Bounding"
         Index           =   0
      End
      Begin VB.Menu mnuChord 
         Caption         =   "Diameter"
         Index           =   1
      End
      Begin VB.Menu mnuChord 
         Caption         =   "Center/Radius"
         Index           =   2
      End
   End
   Begin VB.Menu mnuPieM 
      Caption         =   "Pie"
      Visible         =   0   'False
      Begin VB.Menu mnuPie 
         Caption         =   "Bounding"
         Index           =   0
      End
      Begin VB.Menu mnuPie 
         Caption         =   "Diameter"
         Index           =   1
      End
      Begin VB.Menu mnuPie 
         Caption         =   "Center/Radius"
         Index           =   2
      End
   End
End
Attribute VB_Name = "ucToolBar"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

'========================================================
' Declarations
'========================================================
Private m_AppCtrl As ucMain ' Object '  UserControl

Private m_GeCtrl As CG
Private m_frmActive As ucMain ' Object ' UserControl  ' ucMain
Private m_bInitToolBar As Boolean

' the panel height on the MDI form will be made this size, no matter what
' the designer set the height to
Private m_nPanelHeight As Integer

' this will control the number of visible toolbars
Dim m_nToolbarRows As Integer

Dim m_bPopUpRequired As Boolean


'========================================================
' End Declarations
'========================================================

'========================================================
' ABBCAToolbars
'========================================================
'========================================================
' Align
'========================================================
''------------------------------
Private Sub UpdateAlign()
  ' update buttons
  Dim nCnt As Long
  Dim bSel As Boolean
  On Error Resume Next
  If Not m_GeCtrl Is Nothing Then
    nCnt = m_GeCtrl.SelNumberOfObjects
    If nCnt > 0 Then bSel = True
    tbAlign.ButtonEnabled("GRIDLEFT") = bSel
    tbAlign.ButtonEnabled("GRIDTOP") = bSel
    tbAlign.ButtonEnabled("GRIDRIGHT") = bSel
    tbAlign.ButtonEnabled("GRIDBOTTOM") = bSel
    tbAlign.ButtonEnabled("GRIDCENTER") = bSel
    
    If nCnt > 1 Then bSel = True Else bSel = False
    
    tbAlign.ButtonEnabled("LEFT") = bSel
    tbAlign.ButtonEnabled("MIDDLE") = bSel
    tbAlign.ButtonEnabled("RIGHT") = bSel
    tbAlign.ButtonEnabled("TOP") = bSel
    tbAlign.ButtonEnabled("CENTER") = bSel
    tbAlign.ButtonEnabled("BOTTOM") = bSel
  
    tbAlign.ButtonEnabled("HEIGHT") = bSel
    tbAlign.ButtonEnabled("WIDTH") = bSel
    tbAlign.ButtonEnabled("BOTH") = bSel
  
  End If
End Sub

''------------------------------
Private Sub tbAlign_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  ' Settings
  On Error Resume Next
  If m_bInitToolBar Then Exit Sub
  If m_GeCtrl Is Nothing Then Exit Sub
  
  Select Case UCase(ButtonKey)
    Case "GRIDLEFT"
      AlignToGridOperation 0
    Case "GRIDTOP"
      AlignToGridOperation 2
    Case "GRIDRIGHT"
      AlignToGridOperation 1
    Case "GRIDBOTTOM"
      AlignToGridOperation 3
    Case "GRIDCENTER"
      AlignToGridOperation 4
    
    Case "LEFT"
      m_GeCtrl.AlignSelection 0
    Case "MIDDLE"
      m_GeCtrl.AlignSelection 5
    Case "RIGHT"
      m_GeCtrl.AlignSelection 1
    Case "TOP"
      m_GeCtrl.AlignSelection 2
    Case "CENTER"
      m_GeCtrl.AlignSelection 4
    Case "BOTTOM"
      m_GeCtrl.AlignSelection 3
  
    Case "HEIGHT"
      MakeSameSizeOperation 0
    Case "WIDTH"
      MakeSameSizeOperation 1
    Case "BOTH"
      MakeSameSizeOperation 2
  End Select
End Sub

'========================================================
' Arrange
'========================================================
'------------------------------
Private Sub UpdateArrange()
  ' update buttons
  Dim bSel As Boolean
  On Error Resume Next
  If Not m_GeCtrl Is Nothing Then
    bSel = IIf(m_GeCtrl.SelNumberOfObjects > 0, True, False)
    
    tbArrange.ButtonEnabled("GROUP") = m_GeCtrl.CanGroup
    tbArrange.ButtonEnabled("UNGROUP") = m_GeCtrl.CanUngroup
    tbArrange.ButtonEnabled("MOVEBACK") = bSel
    tbArrange.ButtonEnabled("MOVEFRONT") = bSel
    tbArrange.ButtonEnabled("MOVEBACK1") = bSel
    tbArrange.ButtonEnabled("MOVEFRONT1") = bSel
  
    tbArrange.ButtonEnabled("FLIPHORIZONTAL") = bSel
    tbArrange.ButtonEnabled("FLIPVERTICAL") = bSel
    tbArrange.ButtonEnabled("ROTATELEFT") = bSel
    tbArrange.ButtonEnabled("ROTATERIGHT") = bSel
  End If
End Sub

''------------------------------
Private Sub tbArrange_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  ' Settings
  On Error Resume Next
  If m_bInitToolBar = True Then Exit Sub
  If m_GeCtrl Is Nothing Then Exit Sub
  
  Select Case UCase(ButtonKey)
    Case "GROUP":   m_GeCtrl.Group
    Case "UNGROUP":   m_GeCtrl.Ungroup
    Case "MOVEBACK":   m_GeCtrl.MoveToBack
    Case "MOVEFRONT":   m_GeCtrl.MoveToFront
    Case "MOVEBACK1":   m_GeCtrl.MoveBackward
    Case "MOVEFRONT1":   m_GeCtrl.MoveForward
    
    Case "FLIPHORIZONTAL"
      m_GeCtrl.FlipHorizontal
      m_frmActive.UpdateToolPanelButtons
    Case "FLIPVERTICAL"
      m_GeCtrl.FlipVertical
      m_frmActive.UpdateToolPanelButtons
    Case "ROTATELEFT"
      m_GeCtrl.RotateLeft
      m_frmActive.UpdateToolPanelButtons
    Case "ROTATERIGHT"
      m_GeCtrl.RotateRight
      m_frmActive.UpdateToolPanelButtons
  
  End Select
End Sub

'========================================================
' Settings
'========================================================
''------------------------------
Private Sub UpdateSettings()
  ' update buttons
  On Error Resume Next
  If Not m_GeCtrl Is Nothing Then
    tbSettings.ButtonChecked("VERTEX") = m_GeCtrl.VertexMode
    tbSettings.ButtonChecked("SNAP") = m_GeCtrl.Snap
    tbSettings.ButtonChecked("RULER") = m_GeCtrl.Rulers
    tbSettings.ButtonChecked("GRID") = m_GeCtrl.Grid
    tbSettings.ButtonChecked("SCROLLBAR") = m_GeCtrl.ScrollBars
    tbSettings.ButtonChecked("MOVE") = m_GeCtrl.SelectMoveOnly
    tbSettings.ButtonEnabled("MOVECOPY") = IIf(m_GeCtrl.SelNumberOfObjects > 0, True, False)
    tbSettings.ButtonChecked("ISOMETRICMODE") = m_GeCtrl.IsometricMode
      
  End If
End Sub
''------------------------------
Private Sub tbSettings_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  ' Settings
  If m_bInitToolBar = True Then Exit Sub
  If m_GeCtrl Is Nothing Then Exit Sub
  
  Select Case UCase(ButtonKey)
    Case "VERTEX"
      m_GeCtrl.VertexMode = Not tbSettings.ButtonChecked(ButtonKey)
      tbSettings.ButtonChecked(ButtonKey) = Not tbSettings.ButtonChecked(ButtonKey)
    Case "SNAP"
      m_GeCtrl.Snap = Not tbSettings.ButtonChecked(ButtonKey)
      tbSettings.ButtonChecked(ButtonKey) = Not tbSettings.ButtonChecked(ButtonKey)
      If Not m_frmActive Is Nothing Then m_frmActive.UpdateToolPanelButtons
    Case "RULER"
      m_GeCtrl.Rulers = Not tbSettings.ButtonChecked(ButtonKey)
      tbSettings.ButtonChecked(ButtonKey) = Not tbSettings.ButtonChecked(ButtonKey)
    Case "SCROLLBAR"
      m_GeCtrl.ScrollBars = Not tbSettings.ButtonChecked(ButtonKey)
      tbSettings.ButtonChecked(ButtonKey) = Not tbSettings.ButtonChecked(ButtonKey)
    Case "GRID"
      m_GeCtrl.Grid = Not tbSettings.ButtonChecked(ButtonKey)
      tbSettings.ButtonChecked(ButtonKey) = Not tbSettings.ButtonChecked(ButtonKey)
    Case "MOVE"
      m_GeCtrl.SelectMoveOnly = Not tbSettings.ButtonChecked(ButtonKey)
      tbSettings.ButtonChecked(ButtonKey) = Not tbSettings.ButtonChecked(ButtonKey)
    Case "DISTANCE"
      If Not m_frmActive Is Nothing Then m_frmActive.DoDistanceTool
    Case "MOVECOPY"
      m_GeCtrl.MoveCopy
    
    Case "ISOMETRICMODE"
      m_GeCtrl.IsometricMode = Not tbSettings.ButtonChecked(ButtonKey)
      tbSettings.ButtonChecked(ButtonKey) = Not tbSettings.ButtonChecked(ButtonKey)
  
  End Select
End Sub

'========================================================
' File/Zoom
'========================================================
'----------------------
Private Sub tbFileZoom_ButtonMouseOver(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  If Not m_GeCtrl Is Nothing Then
    If UCase(ButtonKey) = "UNDO" Then
      tbFileZoom.ButtonToolTipText(ButtonIndex) = "Undo " & m_GeCtrl.UndoDescription
    End If
  End If
End Sub
'----------------------
Private Sub tbFileZoom_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  ' file/zoom ops
  On Error Resume Next
  
  If m_bInitToolBar = True Then Exit Sub
  ' FILE
  If UCase(ButtonKey) = "FILEOPEN" Then
    ' send FileOpen to mdiForm
    If (Not m_AppCtrl Is Nothing) Then m_AppCtrl.FileOpen
    Exit Sub
  End If
    
  ''
  If m_GeCtrl Is Nothing Or m_frmActive Is Nothing Then Exit Sub
  
  Select Case UCase(ButtonKey)
    Case "FILESAVE":      m_frmActive.FileSave
    Case "COPY":        If m_GeCtrl.CanCopy Then m_GeCtrl.Copy
    Case "CUT":      If m_GeCtrl.CanCut Then m_GeCtrl.Cut
    Case "PASTE":      If m_GeCtrl.CanPaste Then m_GeCtrl.Paste
    Case "UNDO":      If m_GeCtrl.CanUndo Then m_GeCtrl.Undo
    
    ' ZOOM
    Case "ZOOMAREA":    m_GeCtrl.ZoomIn
    Case "ZOOMIN":    ZoomInBy2
    Case "ZOOMOUT":    m_GeCtrl.ZoomOut
    Case "ZOOMPAGE":    m_GeCtrl.ZoomPage
    Case "ZOOMPREV":    m_GeCtrl.ZoomPrevious
    Case "ZOOMEXTENT":    m_GeCtrl.ZoomExtents
  End Select
  
End Sub
''------------------------------
Private Sub UpdateFileZoom()
  ' update buttons
  On Error Resume Next
  If Not m_GeCtrl Is Nothing And Not m_frmActive Is Nothing Then
    EnableSaveBtn m_frmActive.IsDwgDirty     ' save
    EnableCopyBtn m_GeCtrl.CanCopy
    EnableCutBtn m_GeCtrl.CanCut
    EnablePasteBtn m_GeCtrl.CanPaste
    EnableUndoBtn m_GeCtrl.CanUndo
  End If
End Sub
  
Public Function EnableOpenBtn(ByVal bVal As Boolean)
  tbFileZoom.ButtonEnabled("FileOpen") = bVal
End Function
Public Function EnableSaveBtn(ByVal bVal As Boolean)
  tbFileZoom.ButtonEnabled("FileSave") = bVal
End Function
Public Function EnableCopyBtn(ByVal bVal As Boolean)
  tbFileZoom.ButtonEnabled("Copy") = bVal
End Function
Public Function EnableCutBtn(ByVal bVal As Boolean)
  tbFileZoom.ButtonEnabled("Cut") = bVal
End Function
Public Function EnablePasteBtn(ByVal bVal As Boolean)
  tbFileZoom.ButtonEnabled("Paste") = bVal
End Function
Public Sub EnableUndoBtn(ByVal bVal As Boolean)
  tbFileZoom.ButtonEnabled("Undo") = bVal
End Sub


'========================================================
' GeTools (standard)
'========================================================
'----------------------
Private Sub tbGeTool_ButtonRightClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String, CancelBeep As Boolean)
  ' drawing tools
  On Error Resume Next
  Select Case UCase(ButtonKey)
  Case "ARC"
    m_bPopUpRequired = True
    CancelBeep = True
    tbGeTool.ForceClick ButtonIndex
    PopupMenu mnuArcM, , , 400
  Case "CHORD"
    m_bPopUpRequired = True
    CancelBeep = True
    tbGeTool.ForceClick ButtonIndex
    PopupMenu mnuChordM, , , 400
  Case "PIE"
    m_bPopUpRequired = True
    CancelBeep = True
    tbGeTool.ForceClick ButtonIndex
    PopupMenu mnuPieM, , , 400
  End Select
End Sub

'----------------------
Private Sub tbGeTool_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  ' CG tools
  Static bReUpdate As Boolean
  Dim iToolCur As Integer, iTool As Integer
  
    ' TOOLS
  On Error Resume Next
  If bReUpdate Then Exit Sub  ' prevent recursion
  
  If m_bInitToolBar = True Then Exit Sub
  If m_GeCtrl Is Nothing Then Exit Sub
  
  If m_bPopUpRequired Then
    m_bPopUpRequired = False
    Exit Sub
  End If
  
  iToolCur = m_GeCtrl.Tool
  If iToolCur = GETOOL_MULTIVERTEX Then bReUpdate = True
  
  Select Case UCase(ButtonKey)
    
    Case "SELECT":      iTool = GETOOL_SELECT
    Case "LINE":        iTool = GETOOL_LINE
    Case "ARC":         iTool = GETOOL_ARC
    Case "POLYLINE":    iTool = GETOOL_POLYLINE
    Case "SMARTLINE":   iTool = GETOOL_SMARTLINE
    Case "RECTANGLE":   iTool = GETOOL_RECTANGLE
    Case "POLYGON":     iTool = GETOOL_POLYGON
    Case "ELLIPSE":     iTool = GETOOL_ELLIPSE
    Case "CHORD":       iTool = GETOOL_CHORD
    Case "PIE":         iTool = GETOOL_PIE
    Case "BEZIER":      iTool = GETOOL_OPENBEZIER
    Case "TEXT":        iTool = GETOOL_TEXT
    Case "MULTIVERTEX": iTool = GETOOL_MULTIVERTEX
    Case "SELECTTEXT":  iTool = GETOOL_TEXTINSHAPETOOL
  End Select
  
  If iToolCur <> iTool Then
    m_GeCtrl.Tool = iTool
    UpdateGeTools2 ' turn off other toolbar
    UpdateArrange
    UpdateAlign
  End If
  
  ' must call this again as a call to SelectTool will trigger a SelectionChanged
  ' event if editing multi-vertex resulting in tool buttons going out of wack.
  If bReUpdate Then UpdateGeTools
  
  bReUpdate = False ' always set false here to stop blocking
  
End Sub

''------------------------------
Private Sub UpdateGeTools()
  ' update the drawing tools  Buttons (In/Out, On/Off)
  Dim strKey As String
  
  On Error Resume Next
  ' turn current tool on
  If m_GeCtrl Is Nothing Then Exit Sub
  Select Case m_GeCtrl.Tool
    Case GETOOL_NONE
      strKey = "SELECT"
      
    Case GETOOL_SELECT: strKey = "SELECT"
    Case GETOOL_PICK: strKey = "SELECT"
    Case GETOOL_JOIN: strKey = "SELECT"
    
    Case GETOOL_LINE: strKey = "LINE"
    Case GETOOL_ARC: strKey = "ARC"
    Case GETOOL_ARCCENTERRADIUS: strKey = "ARC"
    Case GETOOL_ARCDIAMETER: strKey = "ARC"
    Case GETOOL_POLYLINE: strKey = "POLYLINE"
    Case GETOOL_SMARTLINE: strKey = "SMARTLINE"
    Case GETOOL_RECTANGLE: strKey = "RECTANGLE"
    Case GETOOL_POLYGON: strKey = "POLYGON"
    Case GETOOL_ELLIPSE: strKey = "ELLIPSE"
    Case GETOOL_CHORD: strKey = "CHORD"
    Case GETOOL_CHORDCENTERRADIUS: strKey = "CHORD"
    Case GETOOL_CHORDDIAMETER: strKey = "CHORD"
    Case GETOOL_PIE: strKey = "PIE"
    Case GETOOL_PIECENTERRADIUS: strKey = "PIE"
    Case GETOOL_PIEDIAMETER: strKey = "PIE"
    Case GETOOL_OPENBEZIER: strKey = "BEZIER"
    Case GETOOL_TEXT: strKey = "TEXT"
    Case GETOOL_MULTIVERTEX:  strKey = "MULTIVERTEX"
    Case GETOOL_TEXTINSHAPETOOL:  strKey = "SELECTTEXT"
  End Select
  ''
  Dim i As Integer
  With tbGeTool
    For i = 1 To .ButtonCount
      .ButtonChecked(i) = False
    Next i
    If Len(strKey) > 0 Then .ButtonChecked(strKey) = True
  End With
  
  tbGeTool.ButtonEnabled(13) = False
  If m_GeCtrl.CanMultiVertex = True Then
    tbGeTool.ButtonEnabled(13) = True
  End If
  
  
End Sub
'========================================================
' GeTools (Extended)
'========================================================
'----------------------
Private Sub tbGeTool2_ButtonRightClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String, CancelBeep As Boolean)
  ' drawing tools
  On Error Resume Next
  Select Case UCase(ButtonKey)
  Case "CIRCLE"
    m_bPopUpRequired = True
    CancelBeep = True
    tbGeTool2.ForceClick ButtonIndex
    PopupMenu mnuCircleM, , , 400
  End Select
End Sub

'----------------------
Private Sub tbGeTool2_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  ' CG tools
    ' TOOLS
  On Error Resume Next
  If m_bInitToolBar = True Then Exit Sub
  If m_GeCtrl Is Nothing Then Exit Sub
  
  If m_bPopUpRequired Then
    m_bPopUpRequired = False
    Exit Sub
  End If
  
  Select Case UCase(ButtonKey)
    Case "CIRCLE":      m_GeCtrl.Tool = GETOOL_CIRCLECENTERRADIUS
    Case "REFPOINT":      m_GeCtrl.Tool = GETOOL_REFERENCEPOINT
    Case "TEXTFIELD":      m_GeCtrl.Tool = GETOOL_FIELD
    Case "TEXTMULTI":      m_GeCtrl.Tool = GETOOL_TEXTBOX
    Case "ROUNDRECT":      m_GeCtrl.Tool = GETOOL_ROUNDRECT
    Case "CONNECTPOINT":      m_GeCtrl.Tool = GETOOL_CONNECTION
    Case "CONNECTLINE":      m_GeCtrl.Tool = GETOOL_CONNECTLINE
    Case "CONNECTPOLYLINE":      m_GeCtrl.Tool = GETOOL_CONNECTPOLYLINE
    Case "CONNECTSMARTLINE":      m_GeCtrl.Tool = GETOOL_CONNECTSMARTLINE
    Case "DIMENSIONLINE":      m_GeCtrl.Tool = GETOOL_DIMENSIONLINE
  End Select
  
  UpdateArrange
  UpdateAlign
  
  UpdateGeTools ' turn off other toolbar
  
End Sub

''------------------------------
Private Sub UpdateGeTools2()
  ' update the drawing tools  Buttons (In/Out, On/Off)
  Dim strKey As String
  
  On Error Resume Next
  ' turn current tool on
  If m_GeCtrl Is Nothing Then Exit Sub
  Select Case m_GeCtrl.Tool
    
    Case GETOOL_CIRCLECENTERRADIUS: strKey = "CIRCLE"
    Case GETOOL_CIRCLEDIAMETER: strKey = "CIRCLE"
    Case GETOOL_REFERENCEPOINT: strKey = "REFPOINT"
    Case GETOOL_ROUNDRECT: strKey = "ROUNDRECT"
    Case GETOOL_FIELD: strKey = "TEXTFIELD"
    Case GETOOL_TEXTBOX: strKey = "TEXTMULTI"
    
    Case GETOOL_CONNECTION: strKey = "CONNECTPOINT"
    Case GETOOL_CONNECTLINE: strKey = "CONNECTLINE"
    Case GETOOL_CONNECTPOLYLINE: strKey = "CONNECTPOLYLINE"
    Case GETOOL_CONNECTSMARTLINE: strKey = "CONNECTSMARTLINE"
    Case GETOOL_DIMENSIONLINE: strKey = "DIMENSIONLINE"
  End Select
  ''
  
  Dim i As Integer
  With tbGeTool2
    For i = 1 To .ButtonCount
      .ButtonChecked(i) = False
    Next i
    If Len(strKey) > 0 Then .ButtonChecked(strKey) = True
  End With
End Sub

'========================================================
' General
'========================================================

'-----------------------------------
Public Property Set AppCtrl(obj As ucMain)
  Set m_AppCtrl = obj
End Property

Public Property Let ToolBarRows(num As Integer)
  m_nToolbarRows = num
  m_nPanelHeight = tbFileZoom.Height * m_nToolbarRows
'  m_nPanelHeight = 360 * m_nToolbarRows
  Height = m_nPanelHeight
End Property

Public Property Get ToolBarRows() As Integer
  ToolBarRows = m_nToolbarRows
End Property

'------------------------------
Public Property Set ActiveForm(obj As ucMain)
  On Error Resume Next
  Set m_GeCtrl = Nothing
  Set m_frmActive = obj
  
  If Not m_frmActive Is Nothing Then
    Set m_GeCtrl = m_frmActive.GeCtrl
    If m_GeCtrl Is Nothing Then Exit Property
    UpdateToolbarButtons
  End If
End Property


'--------------------------
Private Sub ZoomInBy2()
  ' zoom in by factor of 2
  If Not m_GeCtrl Is Nothing Then GeWorker.ZoomInBy2 m_GeCtrl
End Sub
'------------------------------
Public Function AlignToGridOperation(ByVal nOp As Integer)
  If Not m_GeCtrl Is Nothing Then GeWorker.AlignToGridOperation m_GeCtrl, nOp
End Function
'------------------------------
Public Sub MakeSameSizeOperation(ByVal nOp As Integer)
  If Not m_GeCtrl Is Nothing Then GeWorker.MakeSameSizeOperation m_GeCtrl, nOp
End Sub

''------------------------------
Public Function UpdateToolbarButtons()
  ' update the Buttons (In/Out, On/Off)

  On Error Resume Next
  If m_frmActive Is Nothing Then Exit Function
  If m_GeCtrl Is Nothing Then Exit Function
  
  ' disable toolbar change
  m_bInitToolBar = True
  
  mnuCircle(0).Checked = False
  mnuCircle(1).Checked = False
  mnuArc(0).Checked = False
  mnuArc(1).Checked = False
  mnuArc(2).Checked = False
  mnuChord(0).Checked = False
  mnuChord(1).Checked = False
  mnuChord(2).Checked = False
  mnuPie(0).Checked = False
  mnuPie(1).Checked = False
  mnuPie(2).Checked = False
  Select Case m_GeCtrl.Tool
    Case GETOOL_CIRCLEDIAMETER
        mnuCircle(0).Checked = True
    Case GETOOL_CIRCLECENTERRADIUS
        mnuCircle(1).Checked = True
        
    Case GETOOL_ARC
        mnuArc(0).Checked = True
    Case GETOOL_ARCDIAMETER
        mnuArc(1).Checked = True
    Case GETOOL_ARCCENTERRADIUS
        mnuArc(2).Checked = True
        
    Case GETOOL_CHORD
        mnuChord(0).Checked = True
    Case GETOOL_CHORDDIAMETER
        mnuChord(1).Checked = True
    Case GETOOL_CHORDCENTERRADIUS
        mnuChord(2).Checked = True
        
    Case GETOOL_PIE
        mnuPie(0).Checked = True
    Case GETOOL_PIEDIAMETER
        mnuPie(1).Checked = True
    Case GETOOL_PIECENTERRADIUS
        mnuPie(2).Checked = True
  End Select
   
  ' toolbars
  UpdateFileZoom
  UpdateGeTools
  UpdateGeTools2
  
  UpdateSettings
  UpdateArrange
  UpdateAlign
  
  ' re-enable toolbar change
  m_bInitToolBar = False

End Function

'=================================================================
' INI file
'=================================================================
'------------------------------
Public Function GetIniSettings()
  ' get the Settings for the controls on this toolbar from INI file
End Function

'------------------------------
Public Function SaveIniSettings()
  ' Save the Settings to INI file
End Function



Private Sub mnuArc_Click(Index As Integer)
    Select Case Index
    Case 0
      m_GeCtrl.Tool = GETOOL_ARC
    Case 1
      m_GeCtrl.Tool = GETOOL_ARCDIAMETER
    Case 2
      m_GeCtrl.Tool = GETOOL_ARCCENTERRADIUS
  End Select
  UpdateToolbarButtons
End Sub

Private Sub mnuChord_Click(Index As Integer)
  Select Case Index
    Case 0
      m_GeCtrl.Tool = GETOOL_CHORD
    Case 1
      m_GeCtrl.Tool = GETOOL_CHORDDIAMETER
    Case 2
      m_GeCtrl.Tool = GETOOL_CHORDCENTERRADIUS
  End Select
  UpdateToolbarButtons
End Sub

Private Sub mnuCircle_Click(Index As Integer)
  Select Case Index
    Case 0
      m_GeCtrl.Tool = GETOOL_CIRCLEDIAMETER
    Case 1
      m_GeCtrl.Tool = GETOOL_CIRCLECENTERRADIUS
  End Select
  UpdateToolbarButtons
End Sub

Private Sub mnuPie_Click(Index As Integer)
  Select Case Index
    Case 0
      m_GeCtrl.Tool = GETOOL_PIE
    Case 1
      m_GeCtrl.Tool = GETOOL_PIEDIAMETER
    Case 2
      m_GeCtrl.Tool = GETOOL_PIECENTERRADIUS
  End Select
  UpdateToolbarButtons
End Sub


'========================================================
' User Control setup/resize functions
'========================================================
'------------------------------
Private Sub UserControl_Initialize()
  ' set the value below to 2 to shown 2nd toolbar
  m_nToolbarRows = 2
  m_nPanelHeight = tbFileZoom.Height * m_nToolbarRows
'  m_nPanelHeight = 360 * m_nToolbarRows
  Height = m_nPanelHeight
  
End Sub

Private Sub UserControl_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
  Screen.MousePointer = vbArrow
End Sub

'------------------------------
Private Sub UserControl_Terminate()
  Set m_AppCtrl = Nothing
  Set m_frmActive = Nothing
  Set m_GeCtrl = Nothing
End Sub

'------------------------------
Private Sub UserControl_Resize()
  Dim wsp As Long
  
  On Error Resume Next
  Height = m_nPanelHeight
  
  wsp = 30  ' inbetween space
  ' 1st row
  tbFileZoom.Move 0, 0
  tbGeTool.Move tbFileZoom.Left + tbFileZoom.Width + wsp, 0
  tbSettings.Move tbGeTool.Left + tbGeTool.Width + wsp, 0
  
  
#If 0 Then
  ' 2nd row ' just place em
  tbAlign.Move 0, tbFileZoom.Top + tbFileZoom.Height
  tbGeTool2.Move tbAlign.Left + tbAlign.Width + wsp, tbAlign.Top
  tbArrange.Move tbGeTool2.Left + tbGeTool2.Width + wsp, tbAlign.Top
  
#Else
  Dim w1 As Long, w2 As Long
  Dim wleft As Long, wdiff As Long
  
  w1 = tbFileZoom.Width + wsp + tbGeTool.Width + wsp + tbSettings.Width
  w2 = tbAlign.Width + wsp + tbGeTool2.Width + wsp + tbArrange.Width
  If w2 < w1 Then
    ' 2nd row - align right most to rightmost of previous line
    wleft = w1 - tbArrange.Width
    tbAlign.Move 0, tbFileZoom.Top + tbFileZoom.Height  ' left most
    tbArrange.Move wleft, tbAlign.Top                   ' right most
    
    wdiff = (tbArrange.Left - tbAlign.Width - tbGeTool2.Width) / 2
    wleft = tbAlign.Left + tbAlign.Width + wdiff          ' center
    tbGeTool2.Move wleft, tbAlign.Top
  Else
    ' 2nd row - just place em
    tbAlign.Move 0, tbFileZoom.Top + tbFileZoom.Height
    tbGeTool2.Move tbAlign.Left + tbAlign.Width + wsp, tbAlign.Top
    tbArrange.Move tbGeTool2.Left + tbGeTool2.Width + wsp, tbAlign.Top
  End If
#End If

End Sub

