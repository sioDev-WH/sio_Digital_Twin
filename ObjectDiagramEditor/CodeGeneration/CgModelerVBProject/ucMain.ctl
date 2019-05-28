VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Object = "{E6F77CB3-6A30-11D5-89E6-00D0B74A80C3}#1.0#0"; "CGCtrl.ocx"
Object = "{3B7C8863-D78F-101B-B9B5-04021C009402}#1.2#0"; "RICHTX32.OCX"
Begin VB.UserControl ucMain 
   ClientHeight    =   6750
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   11730
   ControlContainer=   -1  'True
   KeyPreview      =   -1  'True
   ScaleHeight     =   6750
   ScaleWidth      =   11730
   Begin RichTextLib.RichTextBox RichTextBox1 
      Height          =   375
      Left            =   3480
      TabIndex        =   9
      Top             =   2520
      Visible         =   0   'False
      Width           =   1455
      _ExtentX        =   2566
      _ExtentY        =   661
      _Version        =   393217
      Enabled         =   -1  'True
      TextRTF         =   $"ucMain.ctx":0000
   End
   Begin CGCtrlLib.CG Ge1 
      Height          =   1095
      Left            =   3510
      TabIndex        =   6
      Top             =   1290
      Width           =   1755
      _Version        =   65536
      _ExtentX        =   3096
      _ExtentY        =   1931
      _StockProps     =   64
   End
   Begin VB.PictureBox picToolpanel 
      Align           =   3  'Align Left
      Height          =   5160
      Left            =   0
      ScaleHeight     =   5100
      ScaleWidth      =   2145
      TabIndex        =   5
      Top             =   750
      Width           =   2205
      Begin CGModeler.ucToolPanel ucToolPanel 
         Height          =   5145
         Left            =   30
         TabIndex        =   7
         Top             =   60
         Width           =   2055
         _ExtentX        =   3625
         _ExtentY        =   9075
      End
   End
   Begin CGModeler.ucToolBar ucToolBar1 
      Align           =   1  'Align Top
      Height          =   750
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   11730
      _ExtentX        =   20690
      _ExtentY        =   1323
   End
   Begin VB.Timer TimerPrint 
      Enabled         =   0   'False
      Left            =   5520
      Top             =   1200
   End
   Begin MSComDlg.CommonDialog CommonDlg 
      Left            =   5520
      Top             =   1680
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      FontSize        =   2.54052e-29
   End
   Begin VB.PictureBox StatusBar 
      Align           =   2  'Align Bottom
      AutoRedraw      =   -1  'True
      BorderStyle     =   0  'None
      Height          =   840
      Left            =   0
      ScaleHeight     =   840
      ScaleWidth      =   11730
      TabIndex        =   1
      Top             =   5910
      Width           =   11730
      Begin VB.CommandButton btnMessagesClear 
         Caption         =   "Clear"
         Height          =   255
         Left            =   10980
         TabIndex        =   13
         Top             =   570
         Width           =   705
      End
      Begin CGModeler.ucMessageWindow ucMessageWindow 
         Height          =   525
         Left            =   0
         TabIndex        =   12
         Top             =   0
         Visible         =   0   'False
         Width           =   11685
         _ExtentX        =   20611
         _ExtentY        =   926
      End
      Begin VB.CommandButton btnStatusMessages 
         Caption         =   "Messages"
         Height          =   255
         Left            =   9900
         TabIndex        =   11
         Top             =   570
         Width           =   1005
      End
      Begin VB.Label pnlObjText 
         BorderStyle     =   1  'Fixed Single
         Caption         =   "Object Text"
         Height          =   270
         Left            =   4230
         TabIndex        =   8
         Top             =   570
         Width           =   1725
      End
      Begin VB.Label pnlCursorPos 
         BorderStyle     =   1  'Fixed Single
         Caption         =   "12345.00,12345.00"
         Height          =   270
         Left            =   8100
         TabIndex        =   4
         Top             =   570
         Width           =   1785
      End
      Begin VB.Label pnlStsText 
         BorderStyle     =   1  'Fixed Single
         Caption         =   "Status Text"
         Height          =   270
         Left            =   6000
         TabIndex        =   3
         Top             =   570
         Width           =   2085
      End
      Begin VB.Label pnlDimensions 
         BorderStyle     =   1  'Fixed Single
         Caption         =   "Width:         Height:"
         Height          =   270
         Left            =   2220
         TabIndex        =   2
         Top             =   570
         Width           =   1965
      End
      Begin VB.Label pnlUMLProject 
         BorderStyle     =   1  'Fixed Single
         Caption         =   "<No UML Project Loaded>"
         Height          =   270
         Left            =   0
         TabIndex        =   10
         Top             =   570
         Width           =   2175
      End
   End
   Begin VB.Menu mnuFile 
      Caption         =   "&File"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuFileItem 
         Caption         =   "&New"
         Index           =   0
         Shortcut        =   ^N
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "&Open..."
         Index           =   1
         Shortcut        =   ^O
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "&Browse..."
         Index           =   2
         Shortcut        =   ^B
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "&Close"
         Index           =   3
         Visible         =   0   'False
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "-"
         Index           =   4
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "&Save"
         Index           =   5
         Shortcut        =   ^S
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "Save &As..."
         Index           =   6
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "-"
         Index           =   7
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "&Drawing Setup"
         Index           =   8
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "-"
         Index           =   9
         Visible         =   0   'False
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "Open &UML Project"
         Index           =   10
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "Save U&ML Project"
         Index           =   11
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "Sa&ve UML Project As..."
         Index           =   12
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "Close UM&L Project"
         Index           =   13
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "-"
         Index           =   14
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "&Print"
         Index           =   15
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "Print (Colou&r)"
         Index           =   16
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "-"
         Index           =   17
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "Insert Picture..."
         Index           =   18
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "&Import..."
         Index           =   19
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "&Export..."
         Index           =   20
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "-"
         Index           =   21
      End
      Begin VB.Menu mnuFileItem 
         Caption         =   "E&xit"
         Index           =   22
      End
      Begin VB.Menu mnuRecentFile 
         Caption         =   "-"
         Index           =   0
      End
      Begin VB.Menu mnuRecentFile 
         Caption         =   ""
         Index           =   1
      End
      Begin VB.Menu mnuRecentFile 
         Caption         =   ""
         Index           =   2
      End
      Begin VB.Menu mnuRecentFile 
         Caption         =   ""
         Index           =   3
      End
      Begin VB.Menu mnuRecentFile 
         Caption         =   ""
         Index           =   4
      End
      Begin VB.Menu mnuRecentFile 
         Caption         =   ""
         Index           =   5
      End
      Begin VB.Menu mnuBMPFile 
         Caption         =   "-"
         Index           =   0
         Visible         =   0   'False
      End
      Begin VB.Menu mnuBMPFile 
         Caption         =   "Save As &Bitmap..."
         Index           =   1
         Visible         =   0   'False
      End
   End
   Begin VB.Menu mnuView 
      Caption         =   "&View"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuViewItem 
         Caption         =   "&Status Bar"
         Index           =   0
      End
      Begin VB.Menu mnuViewItem 
         Caption         =   "&Toolbars"
         Index           =   1
         Begin VB.Menu mnuToolbarItem 
            Caption         =   "&Standard toolbar"
            Index           =   0
         End
         Begin VB.Menu mnuToolbarItem 
            Caption         =   "&Additional tools"
            Index           =   1
         End
      End
      Begin VB.Menu mnuViewItem 
         Caption         =   "ToolPanel"
         Index           =   2
         Begin VB.Menu mnuToolpanelItem 
            Caption         =   "&Visible"
            Index           =   0
         End
         Begin VB.Menu mnuToolpanelItem 
            Caption         =   "On &Left Side"
            Index           =   1
         End
      End
      Begin VB.Menu mnuViewItem 
         Caption         =   "-"
         Index           =   3
      End
      Begin VB.Menu mnuViewItem 
         Caption         =   "&Rulers"
         Index           =   4
      End
      Begin VB.Menu mnuViewItem 
         Caption         =   "Scro&ll Bars"
         Index           =   5
      End
      Begin VB.Menu mnuViewItem 
         Caption         =   "&Margins"
         Index           =   6
      End
      Begin VB.Menu mnuViewItem 
         Caption         =   "-"
         Index           =   7
      End
      Begin VB.Menu mnuViewItem 
         Caption         =   "Re&fresh"
         Index           =   8
         Shortcut        =   {F5}
      End
      Begin VB.Menu mnuSep 
         Caption         =   "-"
         Visible         =   0   'False
      End
      Begin VB.Menu mnuGeometry 
         Caption         =   "Show Length"
         Visible         =   0   'False
      End
   End
   Begin VB.Menu mnuDwgView 
      Caption         =   "&Zoom"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuDwgViewItem 
         Caption         =   "Zoom to &Area"
         Index           =   0
      End
      Begin VB.Menu mnuDwgViewItem 
         Caption         =   "Zoom &In by 2"
         Index           =   1
      End
      Begin VB.Menu mnuDwgViewItem 
         Caption         =   "Zoom &Out by 2"
         Index           =   2
      End
      Begin VB.Menu mnuDwgViewItem 
         Caption         =   "Zoom Pre&vious"
         Index           =   3
      End
      Begin VB.Menu mnuDwgViewItem 
         Caption         =   "-"
         Index           =   4
      End
      Begin VB.Menu mnuDwgViewItem 
         Caption         =   "Zoom Pa&ge"
         Index           =   5
      End
      Begin VB.Menu mnuDwgViewItem 
         Caption         =   "Zoom &Extents"
         Index           =   6
      End
      Begin VB.Menu mnuDwgViewItem 
         Caption         =   "Zoom Page&Width"
         Index           =   7
      End
   End
   Begin VB.Menu mnuEdit 
      Caption         =   "&Edit"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuEditItem 
         Caption         =   "&Undo"
         Index           =   0
         Shortcut        =   ^Z
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "&Delete"
         Index           =   1
         Shortcut        =   {DEL}
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "-"
         Index           =   2
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "C&ut"
         Index           =   3
         Shortcut        =   ^X
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "&Copy"
         Index           =   4
         Shortcut        =   ^C
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "C&opy Special..."
         Index           =   5
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "&Paste"
         Index           =   6
         Shortcut        =   ^V
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "-"
         Index           =   7
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "&Text"
         Index           =   8
         Shortcut        =   ^E
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "-"
         Index           =   9
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "Select &All"
         Index           =   10
         Shortcut        =   ^A
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "Select All &Locked objects"
         Index           =   11
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "-"
         Index           =   12
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "&Move Page Origin"
         Index           =   13
         Visible         =   0   'False
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "-"
         Index           =   14
         Visible         =   0   'False
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "&Browse Selected Objects..."
         Index           =   15
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "&Smart Selection..."
         Index           =   16
      End
   End
   Begin VB.Menu mnuFormat 
      Caption         =   "F&ormat"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuFormatItem 
         Caption         =   "&Align Selection"
         Index           =   0
         Begin VB.Menu mnuAlignSel 
            Caption         =   "&Lefts"
            Index           =   0
         End
         Begin VB.Menu mnuAlignSel 
            Caption         =   "&Middles"
            Index           =   1
         End
         Begin VB.Menu mnuAlignSel 
            Caption         =   "&Rights"
            Index           =   2
         End
         Begin VB.Menu mnuAlignSel 
            Caption         =   "-"
            Index           =   3
         End
         Begin VB.Menu mnuAlignSel 
            Caption         =   "&Tops"
            Index           =   4
         End
         Begin VB.Menu mnuAlignSel 
            Caption         =   "&Centers"
            Index           =   5
         End
         Begin VB.Menu mnuAlignSel 
            Caption         =   "&Bottoms"
            Index           =   6
         End
      End
      Begin VB.Menu mnuFormatItem 
         Caption         =   "Align to &Grid"
         Index           =   1
         Begin VB.Menu mnuAlignGrid 
            Caption         =   "&Left"
            Index           =   0
         End
         Begin VB.Menu mnuAlignGrid 
            Caption         =   "&Right"
            Index           =   1
         End
         Begin VB.Menu mnuAlignGrid 
            Caption         =   "-"
            Index           =   2
         End
         Begin VB.Menu mnuAlignGrid 
            Caption         =   "&Top"
            Index           =   3
         End
         Begin VB.Menu mnuAlignGrid 
            Caption         =   "&Bottom"
            Index           =   4
         End
         Begin VB.Menu mnuAlignGrid 
            Caption         =   "-"
            Index           =   5
         End
         Begin VB.Menu mnuAlignGrid 
            Caption         =   "&Center"
            Index           =   6
         End
      End
      Begin VB.Menu mnuFormatItem 
         Caption         =   "Align to S&nap"
         Index           =   2
         Begin VB.Menu mnuAlignSnap 
            Caption         =   "&Left"
            Index           =   0
         End
         Begin VB.Menu mnuAlignSnap 
            Caption         =   "&Right"
            Index           =   1
         End
         Begin VB.Menu mnuAlignSnap 
            Caption         =   "-"
            Index           =   2
         End
         Begin VB.Menu mnuAlignSnap 
            Caption         =   "&Top"
            Index           =   3
         End
         Begin VB.Menu mnuAlignSnap 
            Caption         =   "&Bottom"
            Index           =   4
         End
      End
      Begin VB.Menu mnuFormatItem 
         Caption         =   "Make same &Size"
         Index           =   3
         Begin VB.Menu mnuAlignSize 
            Caption         =   "&Width"
            Index           =   0
         End
         Begin VB.Menu mnuAlignSize 
            Caption         =   "&Height"
            Index           =   1
         End
         Begin VB.Menu mnuAlignSize 
            Caption         =   "-"
            Index           =   2
         End
         Begin VB.Menu mnuAlignSize 
            Caption         =   "&Both"
            Index           =   3
         End
      End
      Begin VB.Menu mnuFormatItem 
         Caption         =   "&Distribute"
         Index           =   4
         Begin VB.Menu mnuAlignDistribute 
            Caption         =   "&Horizontally"
            Index           =   0
         End
         Begin VB.Menu mnuAlignDistribute 
            Caption         =   "&Vertically"
            Index           =   1
         End
      End
      Begin VB.Menu mnuFormatItem 
         Caption         =   "-"
         Index           =   5
      End
      Begin VB.Menu mnuFormatItem 
         Caption         =   "C&onvert..."
         Index           =   6
         Begin VB.Menu mnuConvertItem 
            Caption         =   "Arc/Ellipse to Polyline"
            Index           =   1
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "Polygon to Polyline"
            Index           =   2
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "Polylines to Polyline"
            Index           =   3
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "-"
            Index           =   4
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "Polyline to Polygon"
            Index           =   5
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "Rectangle to Polygon"
            Index           =   6
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "Split Polyline"
            Index           =   7
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "-"
            Index           =   8
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "Bezier to Polyline"
            Index           =   9
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "-"
            Index           =   10
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "Create Polypolygon"
            Index           =   11
         End
         Begin VB.Menu mnuConvertItem 
            Caption         =   "Explode Polypolygon"
            Index           =   12
         End
      End
   End
   Begin VB.Menu mnuArrange 
      Caption         =   "&Arrange"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "&Group"
         Index           =   0
         Shortcut        =   ^G
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "&Ungroup"
         Index           =   1
         Shortcut        =   ^U
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "-"
         Index           =   2
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "Move to &Front"
         Index           =   3
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "Move to &Back"
         Index           =   4
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "Move Forward &One"
         Index           =   5
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "Move Bac&kward One"
         Index           =   6
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "-"
         Index           =   7
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "Mirror about &Vertical axis"
         Index           =   8
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "Mirror about &Horizontal  axis"
         Index           =   9
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "-"
         Index           =   10
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "Rotate &Left (90 degrees)"
         Index           =   11
      End
      Begin VB.Menu mnuArrangeItem 
         Caption         =   "Rotate &Right (90 degrees)"
         Index           =   12
      End
   End
   Begin VB.Menu mnuTool 
      Caption         =   "&Tool"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Select (Move+Scale)"
         Index           =   0
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Select (Move Only)"
         Index           =   1
         Shortcut        =   ^M
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Pick"
         Index           =   2
         Visible         =   0   'False
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Move/Copy"
         Index           =   3
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "-"
         Index           =   4
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Arc"
         Index           =   5
         Begin VB.Menu mnuArcToolItem 
            Caption         =   "&Bounding"
            Index           =   0
         End
         Begin VB.Menu mnuArcToolItem 
            Caption         =   "&Diameter"
            Index           =   1
         End
         Begin VB.Menu mnuArcToolItem 
            Caption         =   "&Center/Radius"
            Index           =   2
         End
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Pie"
         Index           =   6
         Begin VB.Menu mnuPieToolItem 
            Caption         =   "&Bounding"
            Index           =   0
         End
         Begin VB.Menu mnuPieToolItem 
            Caption         =   "&Diameter"
            Index           =   1
         End
         Begin VB.Menu mnuPieToolItem 
            Caption         =   "&Center/Radius"
            Index           =   2
         End
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Circle"
         Index           =   7
         Begin VB.Menu mnuCircleToolItem 
            Caption         =   "&Diameter"
            Index           =   0
         End
         Begin VB.Menu mnuCircleToolItem 
            Caption         =   "&Center/Radius"
            Index           =   1
         End
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Chord"
         Index           =   8
         Begin VB.Menu mnuChordToolItem 
            Caption         =   "&Bounding"
            Index           =   0
         End
         Begin VB.Menu mnuChordToolItem 
            Caption         =   "&Diameter"
            Index           =   1
         End
         Begin VB.Menu mnuChordToolItem 
            Caption         =   "&Center/Radius"
            Index           =   2
         End
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Ellipse"
         Index           =   9
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "-"
         Index           =   10
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Line"
         Index           =   11
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Polyline"
         Index           =   12
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "S&martline"
         Index           =   13
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "-"
         Index           =   14
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Poly&gon"
         Index           =   15
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Rectangle"
         Index           =   16
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Round Rectangle"
         Index           =   17
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "-"
         Index           =   18
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Bezier Curve"
         Index           =   19
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "-"
         Index           =   20
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Text"
         Index           =   21
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Text box"
         Index           =   22
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Text &Field"
         Index           =   23
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "-"
         Index           =   24
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Con&nection Point"
         Index           =   25
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Reference Po&int"
         Index           =   26
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "-"
         Index           =   27
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Connection Line (single segment)"
         Index           =   28
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Connection Line (multi-segmentl)"
         Index           =   29
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "Connection Line (orthogonal)"
         Index           =   30
      End
      Begin VB.Menu mnuToolItem 
         Caption         =   "&Dimension Line"
         Index           =   31
      End
   End
   Begin VB.Menu mnuShape 
      Caption         =   "Sh&ape"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuShapeItem 
         Caption         =   "&Create Shape..."
         Enabled         =   0   'False
         Index           =   0
      End
      Begin VB.Menu mnuShapeItem 
         Caption         =   "Create &Smart Shape..."
         Index           =   1
      End
      Begin VB.Menu mnuShapeItem 
         Caption         =   "-"
         Index           =   2
      End
      Begin VB.Menu mnuShapeItem 
         Caption         =   "&Insert Shape..."
         Index           =   3
      End
      Begin VB.Menu mnuShapeItem 
         Caption         =   "-"
         Index           =   4
      End
      Begin VB.Menu mnuShapeItem 
         Caption         =   "&Explode Shape"
         Index           =   5
      End
      Begin VB.Menu mnuShapeItem 
         Caption         =   "E&xplode Smart Shape"
         Index           =   6
      End
      Begin VB.Menu mnuShapeItem 
         Caption         =   "-"
         Index           =   7
      End
      Begin VB.Menu mnuShapeItem 
         Caption         =   "Locate Shape..."
         Index           =   8
      End
      Begin VB.Menu mnuShapeItem 
         Caption         =   "-"
         Index           =   9
      End
      Begin VB.Menu mnuShapeItem 
         Caption         =   "Manage Library"
         Index           =   10
      End
   End
   Begin VB.Menu mnuSimulation 
      Caption         =   "Wizards"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuSimulationItem 
         Caption         =   "Class..."
         Index           =   0
      End
      Begin VB.Menu mnuSimulationItem 
         Caption         =   "-"
         Index           =   1
      End
      Begin VB.Menu mnuSimulationItem 
         Caption         =   "&Library Block..."
         Index           =   4
      End
      Begin VB.Menu mnuSimulationItem 
         Caption         =   "-"
         Index           =   5
      End
      Begin VB.Menu mnuSimulationItem 
         Caption         =   "Composition..."
         Index           =   6
      End
      Begin VB.Menu mnuSimulationItem 
         Caption         =   "-"
         Index           =   7
      End
      Begin VB.Menu mnuSimulationItem 
         Caption         =   "Integration..."
         Index           =   8
      End
   End
   Begin VB.Menu mnuSettings 
      Caption         =   "&Settings"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "&Grid"
         Index           =   0
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "&Snap Mode"
         Index           =   1
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "&Vertex Mode"
         Index           =   2
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "-"
         Index           =   3
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "&Object Properties..."
         Index           =   4
         Shortcut        =   {F4}
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "&Drawing Properties..."
         Index           =   5
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "&Palette..."
         Index           =   6
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "-"
         Index           =   7
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "Display field outline &boxes"
         Index           =   8
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "Display field &tags"
         Index           =   9
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "Display &connection points"
         Index           =   10
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "Display shape insertion points"
         Index           =   11
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "Draw filled objects transparently"
         Index           =   12
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "-"
         Index           =   13
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "Sn&ap to Connection Points"
         Index           =   14
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "-"
         Index           =   15
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "Snap shapes to cursor"
         Index           =   16
      End
      Begin VB.Menu mnuSettingsItem 
         Caption         =   "Snap to selected objects"
         Index           =   17
      End
   End
   Begin VB.Menu mnuHelp 
      Caption         =   "&Help"
      NegotiatePosition=   1  'Left
      Begin VB.Menu mnuHelpItem 
         Caption         =   "&About..."
         Index           =   0
      End
      Begin VB.Menu mnuHelpItem 
         Caption         =   "-"
         Index           =   1
         Visible         =   0   'False
      End
      Begin VB.Menu mnuHelpItem 
         Caption         =   "&Help"
         Index           =   2
         Visible         =   0   'False
      End
   End
   Begin VB.Menu mnuPopup 
      Caption         =   "Popup"
      Visible         =   0   'False
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item0"
         Index           =   0
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item1"
         Index           =   1
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item2"
         Index           =   2
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item3"
         Index           =   3
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item4"
         Index           =   4
         Visible         =   0   'False
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item5"
         Index           =   5
         Visible         =   0   'False
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item6"
         Index           =   6
         Visible         =   0   'False
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item7"
         Index           =   7
         Visible         =   0   'False
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item8"
         Index           =   8
         Visible         =   0   'False
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item9"
         Index           =   9
         Visible         =   0   'False
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item10"
         Index           =   10
         Visible         =   0   'False
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item11"
         Index           =   11
         Visible         =   0   'False
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item12"
         Index           =   12
         Visible         =   0   'False
      End
      Begin VB.Menu mnuPopupItem 
         Caption         =   "Item13"
         Index           =   13
         Visible         =   0   'False
      End
   End
End
Attribute VB_Name = "ucMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True

'======================================================================================
'
'======================================================================================
Option Explicit

'========================================================
'
' Declarations
'
Private m_bLoading As Boolean
Private m_LastHitUDI As UserDefinedItem

'
' The App Control object
'
'
' Drag/Drop control variables
'
Private m_bDragging As Boolean
'
' The User Control ToolBox object
'
'
' CG control variables
'
Private m_GeCtrl As CG  ' The object
Private m_dGeX As Double    ' current X/Y from CG
Private m_dGeY As Double


Private m_GeDwgWidth As Double  ' Drawing size
Private m_GeDwgHeight As Double
Private m_strGeFileName As String
Private m_bGeIsModified As Boolean
Private m_bReadOnly As Boolean
Private m_bLoadedAsGEF As Boolean ' file open was actaully from a CGF file
Private m_bHadToLocateLibrary As Boolean
Private m_bUsePictureColor As Boolean

Private m_strDir As String     ' current Directory
Private m_strCaption As String

Private Const c_nNumPopupMenuItems As Integer = 14 ' number of itmes in Popup menu

Private m_bDistanceTool As Boolean  ' Doing a distance measurement
Private m_bDeferShowCount As Boolean  ' defer it
Private m_bCreatingSmartShape As Boolean

' Rotation
Private m_Angle As Single
'
'
' current tool
Private m_nCurTool  As Integer ' GETOOL_SELECT
'
' move page origin
'
Private m_bMovingPage As Boolean
Private m_dWtP As Single, m_dHtP As Single
Private m_llXP As Single, m_llYP As Single
Private m_GeIDP As Long

' hold status of shape panel for this instance of editor
Dim m_strLibrary As String
Dim m_strFolder As String
Dim m_strShape As String

' object dimensions when creating ( & scaling)
Private Const c_strFmt = "#########0.0000"  ' Width/Height format

Private m_ptObjX As Single
Private m_ptObjY As Single

' object dimensions when creating
Private m_bCreatingObj As Boolean

  ' the corners of selExtents when beginning scaling
Private m_sllX As Single, m_sllY As Single, m_surX As Single, m_surY As Single

' object dimensions when scaling
Private m_bScalingObj As Boolean
Private m_iScaleCorner As Integer   ' corner started scale from 0=LL, 1=UL, 2=UR, 3=LR

Private m_bMovingObj As Boolean   ' being moved/moveCopied
Private m_ptMoveX As Double
Private m_ptMoveY As Double

' initial width/height on scale
Private m_wtS As Single, m_htS As Single

' Undo control variables
'
Private m_bUndoWithoutAsking  As Boolean

Private m_bMsgVisible As Boolean  'True if Message window is visible
Private m_Projects As Object

'************************
' controls
'************************
Private m_ucToolPanel As ucToolPanel
Private m_ucToolBar As ucToolBar
' layers
Private m_LayerDefs As LayerDefinitions

Private m_DwgEditor As CustomDrawingEditor  ' helper class
Private m_bDeferObjHit As Boolean ' flag so ignore Objecthit events from Ge

Private bDoMask As Boolean
Private bDoCreateNewMask As Boolean
'======================================================================================
' End Declarations
'======================================================================================

'======================================================================================
' Events
'======================================================================================
'
Public Event CaptionChanged(ByVal strCaption As String)


'======================================================================================
' Layers
'======================================================================================
'------------------------------
'Public Property Get LayerDefinitions() As LayerDefinitions
Public Property Get LayerDefinitions() As Object
  Set LayerDefinitions = m_LayerDefs
End Property

'------------------------------
Public Property Get CustomDrawingEditor() As Object
  Set CustomDrawingEditor = m_DwgEditor
End Property


Private Sub btbMessagesClear_Click()
    
End Sub

Private Sub btnMessagesClear_Click()
    ucMessageWindow.ClearMessageWindow
End Sub

Private Sub btnStatusMessages_Click()
    If ucMessageWindow.Visible = True Then
        HideMessageWindow
    Else
        ShowMessageWindow
    End If
End Sub

'======================================================================================
'======================================================================================
'------------------------------
Private Sub mnuBMPFile_Click(index As Integer)
  ' BitMap ops
  Dim frm As frmBitMap
  On Error Resume Next
  Set frm = New frmBitMap
  Set frm.GeCtrl = Ge1
  frm.Show vbModal
  Set frm = Nothing
End Sub


'------------------------------
Public Function GetFileName() As String
  GetFileName = m_strGeFileName
End Function

'======================================================================================
'======================================================================================

'------------------------------
Private Sub DoSmartSelection()
  ' browse
  Dim frm As frmSmartSel
  
  On Error Resume Next
  Set frm = New frmSmartSel
  Set frm.GeCtrl = Ge1
  frm.Show vbModal
  Set frm = Nothing
  UpdateToolbarButtons
  
End Sub
'------------------------------
Private Sub DoBrowseSelection()
  ' browse
  Dim frm As frmBrowseGE
  
  On Error Resume Next
  Set frm = New frmBrowseGE
  Set frm.GeCtrl = Ge1
  frm.DrawingName = m_strGeFileName
  frm.Show vbModal
  Set frm = Nothing
  UpdateToolbarButtons
  
End Sub
'-----------------------
Private Sub EndMovePage(bmove As Boolean)
  ' move page origin
  Dim urX As Single, urY As Single
  
  On Error Resume Next
  m_bMovingPage = False
  If m_GeIDP <> 0 Then
    If bmove Then
      m_GeCtrl.CurrentPropertyID = m_GeIDP  ' move into selector
      m_GeCtrl.GetExtents m_llXP, m_llYP, urX, urY
      
      m_GeCtrl.DrawingOriginX = m_llXP
      m_GeCtrl.DrawingOriginY = m_llYP
      m_GeCtrl.DrawingWidth = m_dWtP
      m_GeCtrl.DrawingHeight = m_dHtP
      
      m_GeCtrl.CurrentPropertyID = 0  ' reset selector
    End If
    '
    m_GeCtrl.SelAdd m_GeIDP
    m_GeCtrl.Delete

  End If
  '
  m_GeIDP = 0
End Sub

'-----------------------
Private Sub BeginMovePage()
  ' move page origin
  
  On Error Resume Next
  m_dWtP = m_GeCtrl.DrawingWidth 'PageWidth
  m_dHtP = m_GeCtrl.DrawingHeight 'PageHeight
  m_llXP = m_GeCtrl.DrawingOriginX
  m_llYP = m_GeCtrl.DrawingOriginY
  
  m_GeCtrl.Tool = GETOOL_SELECT
  m_GeCtrl.SelRemoveAll
  m_GeCtrl.ZoomPage
  m_GeCtrl.ZoomOut
    ' create rect and add to sel
  m_GeIDP = m_GeCtrl.CreateRectangle(m_llXP, m_llYP, m_llXP + m_dWtP, m_llYP + m_dHtP)
  m_GeCtrl.SelAdd m_GeIDP
  m_bMovingPage = True
  
End Sub




Private Sub mnuGeometry_Click()
  GeWorker.CalcLength m_GeCtrl, Me      ' len of line/polygon outline
End Sub



'======================================================================================
' POPUP MENU HANDLERS
'======================================================================================
Private Sub mnuPopupItem_Click(index As Integer)
  On Error Resume Next
  
  Select Case index
    Case 0  ' Cut
      m_DwgEditor.Cut
'      m_GeCtrl.Cut
    Case 1  ' Copy
      m_DwgEditor.Copy
'      m_GeCtrl.Copy
    Case 2  ' Paste
      m_DwgEditor.Paste
'      m_GeCtrl.Paste
    Case 3  ' Delete
      m_DwgEditor.Delete
'      m_GeCtrl.Delete
    Case 4  ' Edit Text
      m_GeCtrl.DoEditText
    Case 5  ' Object Properties
      m_GeCtrl.DoObjectDialog
'    Case 6  ' Separator
    
    Case 7  ' Rotate
      DoSelRotate
    Case 8  ' Scale
      DoSelScale
    Case 9  ' ShapeArray
      DoShapeArray
    
    Case 10 ' Model Properties
      DoModelProperties
    Case 11 ' Mask
      'DoMask                       '????When launched from this popup menu, the resulting dialog's popup menus DON'T WORK!!!!
      bDoMask = True
    Case 12 ' Create New Mask
      'DoCreateNewMask              '????When launched from this popup menu, the resulting dialog's popup menus DON'T WORK!!!!
      bDoCreateNewMask = True
    Case Else
      Exit Sub
  End Select
End Sub

'------------------------------
Private Sub DoPopupMenu()
  ' first, construct the Popup menu the way its needed
  Dim mnu As Menu
  Dim mnuItem As Menu
  Dim i As Integer
  Dim bSel As Boolean
  
  On Error Resume Next
  Set mnu = mnuPopup
  bSel = m_GeCtrl.CanCopy
  For i = 0 To c_nNumPopupMenuItems - 1
    Set mnuItem = mnuPopupItem(i)
    ' may have been set invisible from AID
    mnuItem.Visible = True
    Select Case i
      Case 0
        mnuItem.Caption = "Cut" & vbTab & "Ctrl+X"
        mnuItem.Enabled = m_GeCtrl.CanCut
      Case 1
        mnuItem.Caption = "Copy" & vbTab & "Ctrl+C"
        mnuItem.Enabled = bSel
      Case 2
        mnuItem.Caption = "Paste" & vbTab & "Ctrl+V"
        mnuItem.Enabled = m_GeCtrl.CanPaste
      Case 3
        mnuItem.Caption = "Delete" & vbTab & "Del"
        mnuItem.Enabled = bSel
      Case 4
        mnuItem.Caption = "Edit Text" & vbTab & "Ctrl+E"
        mnuItem.Enabled = m_GeCtrl.CanEditText
      Case 5
        mnuItem.Caption = "Properties" & vbTab & "F4"
        mnuItem.Enabled = bSel
      Case 6
        mnuItem.Caption = "-"     ' separator
      Case 7
        mnuItem.Caption = "Rotate..."
        mnuItem.Enabled = bSel
      Case 8
        mnuItem.Caption = "Scale..."
        mnuItem.Enabled = bSel
      Case 9
        mnuItem.Caption = "Edit ShapeArray Quantity..."
        If CanDoShapeArray Then
          mnuItem.Enabled = True
          mnuItem.Visible = True
        Else
          mnuItem.Visible = False
        End If
      Case 10
        mnuItem.Caption = "Model Properties..."
        If Not m_LastHitUDI Is Nothing Then
          mnuItem.Enabled = True
          mnuItem.Visible = True
        Else
          mnuItem.Enabled = False
        End If
      Case 11
        mnuItem.Caption = "Library Block..."
        mnuItem.Enabled = True
        mnuItem.Visible = True
      Case 12
        mnuItem.Caption = "Create New Library Block..."
        mnuItem.Enabled = True
        mnuItem.Visible = True
      Case Else
        mnuItem.Visible = False
    End Select
  Next i
  PopupMenu mnu
  
  If bDoMask Then DoMask
  If bDoCreateNewMask Then DoCreateNewMask
  
  bDoMask = False
  bDoCreateNewMask = False
End Sub

Private Sub DoModelProperties()
  Dim frm As frmUDItemDefVars
  Dim lBnd As Long
  Dim UDI As UserDefinedItem
  Dim UDIDef As UserDefinedItemDef
  Dim aVar As Variant
  
  On Error Resume Next
  If Projects Is Nothing Then
     GetProjects Projects, m_Projects, CommonDlg
     If Not g_DrawingDefMgr.LoadModelDef() Then
         gMsgWnd.LogMessage "Error loading xml model definition"
     End If
  Else
    If Projects.count = 0 Then
       GetProjects Projects, m_Projects, CommonDlg
        If Not g_DrawingDefMgr.LoadModelDef() Then
            gMsgWnd.LogMessage "Error loading xml model definition"
        End If
    End If
  End If
  
  If Projects.count = 0 Then
    MsgBox "No UML project selected.  Dialog will not be properly initialized"
  End If
   
   If m_GeCtrl.SelNumberOfObjects <> 1 Then Exit Sub
  m_GeCtrl.SelGetObjectVariants aVar
  If err <> 0 Then Exit Sub
  lBnd = LBound(aVar)
  Set UDI = aVar(lBnd)
  If err <> 0 Then Exit Sub
  Set frm = New frmUDItemDefVars

  Set frm.m_curUDI = UDI  'This was commented out
  Set UDIDef = m_DwgEditor.UDIDefMgr.GetUDIDefbyObjectName(UDI.m_strDefObjectName)
  If UDIDef Is Nothing Then
    LogMessage "Failed to initialize Property dialog. Library block definition not found."
  Else
    Set frm.m_curUDIDef = UDIDef
    frm.m_bDef = False 'True               'Set to use m_curUDIDef rather then m_curUDI
    frm.Show vbModal, Me
    SetDwgIsModified UDI.IsDirty
  End If
End Sub

Private Sub DoMask()
  Dim frm As frmUDItemDefs
  Dim FileName As String
  Dim strUMLProj As String
  Dim lBnd As Long
  Dim UDI As UserDefinedItem
  Dim UDIDef As UserDefinedItemDef
  Dim aVar As Variant
  
  'On Error Resume Next
    
  If m_GeCtrl.SelNumberOfObjects <> 1 Then Exit Sub
  m_GeCtrl.SelGetObjectVariants aVar
  If IsEmpty(aVar) Then
    LogMessage "No valid object selected for Library Block Wizard."
    Exit Sub
  End If
  
  If err <> 0 Then Exit Sub
  lBnd = LBound(aVar)
  Set UDI = aVar(lBnd)
    
  ' *** You can still pull up a Block Wizard for a 'symbol' (Shape with no associate UDIDef) ****
'  Set UDIDef = m_DwgEditor.UDIDefMgr.GetUDIDefbyObjectName(UDI.m_strDefObjectName)
'  If UDIDef Is Nothing Then
'    LogMessage "Failed to initialize Library Block Wizard. Library Block definition not found."
'    Exit Sub
'  End If
   
  Set frm = New frmUDItemDefs
  frm.LibraryName = GetFirstAttachedLibrary

  'If this UDI has no shape and folder fileld in, see if we can get if from UDIDef (if one is assigned).  If
  'no UDIDef assigned, the shape will ahve to be redropped in order to have the Block Wizard accessible.
  If Len(UDI.m_strShape) <= 0 Or Len(UDI.m_strFolder) <= 0 Then
    Set UDIDef = m_DwgEditor.UDIDefMgr.GetUDIDefbyObjectName(UDI.m_strDefObjectName)
    If UDIDef Is Nothing Then
      Set UDIDef = m_DwgEditor.UDIDefMgr.GetUDIDef(UDI.m_strFolder, UDI.m_strShape)
      If UDIDef Is Nothing Then
          LogMessage "Failed to initialize Library Block Wizard. Library Block definition not found."
      End If
    End If
    If Not UDIDef Is Nothing Then
        UDI.m_strShape = UDIDef.GeShape
        UDI.m_strFolder = UDIDef.GeFolder
    End If
  End If
    
  Set frm.UDIDefMgr = m_DwgEditor.UDIDefMgr
  Set frm.ucToolPanel = m_ucToolPanel
  frm.StartupShape = UDI.m_strShape
  frm.StartupFolder = UDI.m_strFolder
  frm.Show vbModal, Me
  Set frm = Nothing
  
  'In case the user chose a UML project, update the status bar
  strUMLProj = GetUMLProjectName()
  If strUMLProj <> "" Then SetUMLProjectText (strUMLProj)
End Sub

Private Sub DoCreateNewMask()
  On Error Resume Next
  Dim frm As frmUDItemDefs
  Dim FileName As String
  Dim strUMLProj As String
  Dim lBnd As Long
  Dim UDI As UserDefinedItem
  Dim UDIDef As UserDefinedItemDef
  Dim UDIDefNew As UserDefinedItemDef
  Dim aVar As Variant
  
  On Error Resume Next
  If m_GeCtrl.SelNumberOfObjects <> 1 Then Exit Sub
  m_GeCtrl.SelGetObjectVariants aVar
  If err <> 0 Then Exit Sub
  lBnd = LBound(aVar)
  Set UDI = aVar(lBnd)
  Set UDIDef = m_DwgEditor.UDIDefMgr.GetUDIDefbyObjectName(UDI.m_strDefObjectName)
  If UDIDef Is Nothing Then
    Set UDIDef = m_DwgEditor.UDIDefMgr.GetUDIDef(UDI.m_strFolder, UDI.m_strShape)
    If UDIDef Is Nothing Then
        LogMessage "Failed to initialize Library Block Wizard. Library Block definition not found."
        Exit Sub
    End If
  End If
  
  'Create new UDIDef
  GetConnectionDetails UDIDef
  Set UDIDefNew = m_DwgEditor.UDIDefMgr.CreateUDIDef()
  If UDIDefNew Is Nothing Then
    gMsgWnd.LogMessage "Failed to create new Library Block."
    Exit Sub
  End If
  If Not UDIDef.Copy(UDIDefNew) Then
    gMsgWnd.LogMessage "Failed to copy Library Block " & UDIDef.GeShape
    Exit Sub
  End If
  UDIDefNew.ObjectName = GetGUID()
  UDIDefNew.GeShape = m_DwgEditor.UDIDefMgr.GetUniqueShapeName(UDIDefNew.GeShape & "_Copy")
         
  Set frm = New frmUDItemDefs
  frm.LibraryName = GetFirstAttachedLibrary
  frm.StartupFolder = UDIDefNew.GeFolder
  frm.StartupShape = UDIDefNew.GeShape
  Set frm.UDIDefMgr = m_DwgEditor.UDIDefMgr
  Set frm.ucToolPanel = m_ucToolPanel
  frm.Show vbModal, Me
  Set frm = Nothing
  
  'In case the user chose a UML project, update the status bar
  strUMLProj = GetUMLProjectName()
  If strUMLProj <> "" Then SetUMLProjectText (strUMLProj)
End Sub

'------------------------------
Private Function CanDoShapeArray() As Boolean
  Dim GeID As Long
  Dim nGeType As Integer
  On Error Resume Next
  If Not m_GeCtrl Is Nothing Then
    If m_GeCtrl.SelNumberOfObjects = 1 Then
      GeID = m_GeCtrl.GetFirstSelObject
      ' loop through all objects
      If GeID > 0 Then
        m_GeCtrl.CurrentPropertyID = GeID  ' move into selector
        nGeType = m_GeCtrl.ObjectType
        If nGeType = EGeObjType.UserGroup Then
          If m_GeCtrl.ShapeSetCurrent(GeID) Then
            If m_GeCtrl.ShapeNumArrayElements > 0 Then CanDoShapeArray = True
          End If
        End If
        m_GeCtrl.CurrentPropertyID = 0  ' reset selector
        '
      End If
    End If
  End If
End Function
'------------------------------
Private Function DoShapeArray()
  ' Shape Array
  Dim frm As Form
  On Error Resume Next
  Set frm = New frmShapeArray
  Set frm.GeCtrl = m_GeCtrl
  frm.Show vbModal
  If frm.IsModified Then SetDwgIsModified True
  Set frm = Nothing
  UpdateToolbarButtons
End Function


'------------------------------
Private Function DoSelRotate()
  ' rotate Selection
  Dim frm As Form
  
  On Error Resume Next
  Set frm = New frmRotate
  Set frm.GeCtrl = Ge1
  Set frm.AppCtrl = Me
  frm.sX = m_dGeX
  frm.sY = m_dGeY
  frm.Angle = m_Angle
  
  frm.Show vbModal
  
  ' memorize
  m_Angle = frm.Angle
  
  Set frm = Nothing
End Function
'------------------------------
Public Function DoRotate(sX As Single, sY As Single, Angle As Single)
  ' do the rotation - callback from rotate form
  On Error Resume Next
  m_GeCtrl.SelRotate sX, sY, Angle
  UpdateToolbarButtons
End Function

'------------------------------
Private Function DoSelScale()
  ' scale Selection about lower left corner of extents
  Dim dLeft As Single, dBottom As Single
  Dim dRight As Single, dTop As Single
  Dim dWidthCur As Single, dHeightCur As Single
  Dim dWidthNew As Single, dHeightNew As Single
  Dim scaleX As Single, scaleY As Single
  Dim frm As Form
  
  On Error Resume Next
  
  Set frm = New frmScale
  m_GeCtrl.GetSelExtents dLeft, dBottom, dRight, dTop
  dWidthCur = dRight - dLeft
  frm.WidthCur = dWidthCur
  dHeightCur = dTop - dBottom
  frm.HeightCur = dHeightCur
  frm.Show vbModal
  If frm.DoIt Then
    dWidthNew = frm.WidthNew
    dHeightNew = frm.HeightNew
      '
    If dWidthCur <> 0 Then
      scaleX = dWidthNew / dWidthCur
    Else
      scaleX = 1
    End If
    '
    If dHeightCur <> 0 Then
      scaleY = dHeightNew / dHeightCur
    Else
      scaleY = 1
    End If
    '
    m_GeCtrl.SelScale dLeft, dBottom, scaleX, scaleY
  End If
  Set frm = Nothing
  
  UpdateToolbarButtons
  
End Function

'======================================================================================
' General
'======================================================================================
'------------------------------
Private Property Set ToolPanel(obj As ucToolPanel)
  On Error Resume Next
  Set m_ucToolPanel = obj
'  If Not m_ucToolPanel Is Nothing Then
'    Set m_ucToolPanel.GeCtrl = m_GeCtrl
'  End If

End Property
'--------------------------
Private Property Get ToolPanel() As ucToolPanel
  Set ToolPanel = m_ucToolPanel
End Property
'--------------------------
Private Property Set ToolBar(obj As ucToolBar)
  On Error Resume Next
  Set m_ucToolBar = obj
End Property
'--------------------------
Private Property Get ToolBar() As ucToolBar
  Set ToolBar = m_ucToolBar
End Property

'------------------------------
Public Property Get GeCtrl() As Object
  Set GeCtrl = m_GeCtrl
End Property

'------------------------------
'
' when set true, the dialog asking if the user really wants to delete
' the lasr object won't appear - it a one-shot
Public Sub SetUndoWithoutAsking()
  m_bUndoWithoutAsking = True
End Sub
'------------------------------


Private Sub SetGeCtrl(GeCtrl As CG)
  ' set the object and manipulate menubar
  On Error Resume Next
  Set m_GeCtrl = GeCtrl
  If Not (m_GeCtrl Is Nothing) Then
    mnuArrange.Visible = True
    mnuShape.Visible = True
    mnuEdit.Visible = True
    mnuDwgView.Visible = True
    mnuSettings.Visible = True
    mnuTool.Visible = True
  Else
    mnuArrange.Visible = False
    mnuShape.Visible = True
    mnuEdit.Visible = False
    mnuDwgView.Visible = False
    mnuSettings.Visible = False
    mnuTool.Visible = False
  End If
End Sub
'------------------------------
Private Sub Init_GeCtrl(GeCtrl As CG)
  ' initialize the GeCtrl
  Dim bRet As Boolean
  Dim strMsg As String
  Dim bSend As Boolean
  
  On Error Resume Next
  bSend = GeCtrl.SendStatusEvents
  GeCtrl.SendStatusEvents = False   ' block as we could be changing props
  
  bRet = GeCtrl.InitNew
  
  Dim nVal As Integer
  
  
' AEM - 3/5/01 - removed this, as setting default papersize to whatever you last printed
' is a 'weird' concept
'  nVal = Printer.PaperSize
'  nVal = AppGetProfileInt(INISECTION_GEEDITOR, INIENTRY_PAPERSIZE, nVal)
'  GeCtrl.PaperSizeRaw = nVal
 
  GeCtrl.DrawingHeight = GeCtrl.PageHeight
  GeCtrl.DrawingWidth = GeCtrl.PageWidth
 
  GeCtrl.Tool = GETOOL_SELECT
  GeCtrl.ScrollBars = True
  GeCtrl.OLEDropMode = 2  ' automatic
  GeCtrl.KeyPreview = True
  ' Jan 14/2000 this is not working yet - see Bruce
'  GeCtrl.MaxUndoBuffers = 1  ' CG has 15 by default
  
'  GeCtrl.SelStepIntoGroups = True
  
  ' inserted shape will scale to match this drawing versus
  ' the drawing they were designed on.
  GeCtrl.AutoSizeShapes = True
  
  ' keep same relative size when inserting shape, pasting, ...
'  GeCtrl.MaintainRelativeSizeOnAction = True
  
  GeCtrl.SendStatusEvents = bSend ' restore
  m_bGeIsModified = False
  
  GeCtrl.FlushUndoBuffer
  GeCtrl.Modified = False
  
  ' connections
  Ge1.ConnectionEvents = True   ' fire the events
  Ge1.ConnectionMode = True     ' enable Connection making
  
  If err <> 0 Then
    strMsg = Error & " Init_GeCtrl"
    gMsgWnd.LogMessage strMsg
  End If
End Sub

'------------------------------
Public Sub GetIniSettings()
  Dim bRet As Integer
  Dim MsgStr As String
  Dim nVal As Integer
  Dim nPanelNumber As Integer
  
  On Error Resume Next
  
  ' Statusbar
  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_STATUSBAR, 1)  ' 1=show by default
  If nVal = 0 Then StatusBar.Visible = False
  
  ''
  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_TOOLPANELSIDE, 0)
  If nVal = 0 Then ToolPanelAlignLeft = True Else ToolPanelAlignLeft = False
  ''
' saving ini will always have toolpanel visible = false (saving during Terminate)
'  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_TOOLPANEL, 1)
'  If nVal = 1 Then ToolPanelVisible = True Else ToolPanelVisible = False
  
  ' ToolBox Panel num
  nPanelNumber = AppGetProfileInt(INISECTION_UAO, INIENTRY_TOOLPANELNUMBER, 0)
  ucToolPanel.ShowPanel nPanelNumber
  ''
  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_TOOLBARROWS, 2) '1 = 1 row, 2 = 2 rows etc
  If nVal > 1 Then Show2Toolbars = True Else Show2Toolbars = False
  ''
  ToolbarVisible = True
  '' Get the INI settings for the toolbar and panel
  ucToolPanel.GetIniSettings
  ucToolBar1.GetIniSettings
End Sub

'------------------------------
Public Sub SaveIniSettings()
  Dim ret As Integer
  Dim nRes As Integer
  Dim nVal As Integer
  Dim bsaved As Boolean
  
  On Error Resume Next
  
    ' Statusbar
  nVal = IIf(StatusBar.Visible = True, 1, 0)
''''
' must force as are too late to determine if still visible
'  nVal = 1
'''''
  AppWriteProfileInt INISECTION_UAO, INIENTRY_STATUSBAR, nVal
   
  ' last sel panel
  nVal = ucToolPanel.GetPanel
  AppWriteProfileInt INISECTION_UAO, INIENTRY_TOOLPANELNUMBER, nVal
   ' Toolpanel on/off
  nVal = IIf(picToolpanel.Visible = True, 1, 0)
  AppWriteProfileInt INISECTION_UAO, INIENTRY_TOOLPANEL, nVal
   ' Toolpanel location
  nVal = IIf(picToolpanel.Align = 4, 1, 0)
  AppWriteProfileInt INISECTION_UAO, INIENTRY_TOOLPANELSIDE, nVal
  ' ToolBar Height
  nVal = ucToolBar1.ToolBarRows
  AppWriteProfileInt INISECTION_UAO, INIENTRY_TOOLBARROWS, nVal

  ' save AuxTools settings
  ucToolPanel.SaveIniSettings
  ucToolBar1.SaveIniSettings
End Sub


'------------------------------
Private Function GetUserDefinedObjectsFileName() As String
  Dim szName As String
  
#If using_ilogix Then
  szName = App.Path & "\" & "UDOs_ilogix.xml"
#End If

  GetUserDefinedObjectsFileName = szName
End Function

Private Sub mnuSimulationItem_Click(index As Integer)

  Select Case index
  
    Case 0 ' Class Wizard
      DoLeafWizard
     
    Case 2 ' create shape
      m_bCreatingSmartShape = True
      m_GeCtrl.TreatShapesAsUserGroups = True
      m_GeCtrl.OnCreateShape
    
    Case 4 ' manage shapes
      DoMangeShapeAndObjects
      
    Case 6 ' composite wizard
      DoCompositeWizard
      
    Case 8 ' application wizard
      DoIntegrationWizard
      
  End Select
End Sub

Private Sub DoLeafWizard()
  Dim frm As frmLeafCg
  Dim strUMLProj As String
  
  Set frm = New frmLeafCg
  frm.Show
  'In case the user chose a UML project, update the status bar
  
  strUMLProj = GetUMLProjectName()
  If strUMLProj <> "" Then SetUMLProjectText (strUMLProj)
End Sub
      
Private Sub DoCompositeWizard()
  Dim frm As frmCompositeCg
  Dim strUMLProj As String
  
  On Error Resume Next
  Set frm = New frmCompositeCg
  Set frm.m_UDIDefMgr = m_DwgEditor.UDIDefMgr
  Set frm.m_GeCtrl = Ge1
  frm.Show
  'In case the user chose a UML project, update the status bar
  strUMLProj = GetUMLProjectName()
  If strUMLProj <> "" Then SetUMLProjectText (strUMLProj)
End Sub
      
Private Sub DoIntegrationWizard()
  Dim frm As frmIntegrationCg
  Dim strUMLProj As String
 
  On Error Resume Next
  Set frm = New frmIntegrationCg
  Set frm.m_UDIDefMgr = m_DwgEditor.UDIDefMgr
  Set frm.m_GeCtrl = Ge1
  frm.Show
  'In case the user chose a UML project, update the status bar
  strUMLProj = GetUMLProjectName()
  If strUMLProj <> "" Then SetUMLProjectText (strUMLProj)
End Sub



'------------------------------
Private Sub UserControl_Initialize()

  ' AEM - 7/7/00 - MUST intialize CG here, as doing it during Form_Initialize can cause error
  ' because the CG object is not instantiated at that point, and setting a property to the
  ' control can cause it to fire a Modified event back to here, but VB does not yet
  ' have an established EventSink until the object is fully instantiated.
  
  On Error Resume Next
  

  Set m_LayerDefs = New LayerDefinitions
'  m_LayerDefs.InitNew

  ' code generation operations require decoding of rich text.  The rich text box on this
  ' control is used by the code generation algorithms, via the crtf global variable
 
  Init_GeCtrl Ge1
  Ge1.SelRemoveAll
  SetGeCtrl Ge1
  SetHelperModuleMainGeCtrl Ge1
  
  Set gMsgWnd = UserControl.ucMessageWindow
  
  Set ToolPanel = ucToolPanel
  Set ToolBar = ucToolBar1
  Set ucToolBar1.ActiveForm = Me  ' UserControl
  Set ucToolBar1.AppCtrl = Me  ' UserControl
  Set ucToolPanel.ActiveForm = Me ' UserControl  ' ME
  Set ucMessageWindow.ActiveForm = Me
  
  Set m_DwgEditor = New CustomDrawingEditor
  Set g_DrawingDefMgr = m_DwgEditor.UDIDefMgr()
  Set m_DwgEditor.AppCtrl = Me
  Set m_DwgEditor.GeCtrl = Ge1
   
  m_bLoading = True
  GetIniSettings
  m_bLoading = False
   
  bDoMask = False
  bDoCreateNewMask = False
  
  GetRecentFiles
  m_Angle = 5
  m_nCurTool = GETOOL_SELECT
  
  UpdateCaption ""
  HideMessageWindow
End Sub

'------------------------------
Private Sub UserControl_Show()

'End Sub
'Private Sub Form_Activate()
  Static bFirst As Boolean
  Dim dHit As Single, dSnap As Single
  Dim strNameCur As String
  
  Dim bConnectionMode As Boolean
  Dim iObjSnap As Integer
  
  On Error Resume Next
  
  'clear any existing status message
  SetStatusText ""
  
  If Not bFirst Then
    bFirst = True
    
    ' want to tag to geOCX as the CmdLine form needs to track which one its using,
    ' and the tag for each editor form will be unique
    
    dHit = m_ucToolPanel.HitSelectionSize
    dSnap = m_ucToolPanel.ObjectSnapSize
    m_GeCtrl.HitSelectionSize = dHit
    m_GeCtrl.ObjectSnapSize = dSnap
    
    m_ucToolPanel.GetObjectSnapSettings iObjSnap, bConnectionMode
    m_GeCtrl.ObjectSnap = iObjSnap
    m_GeCtrl.ConnectionMode = bConnectionMode
    strNameCur = m_GeCtrl.GetDwgName
    
    UpdateCaption strNameCur
    ' this should be done in ToolPanel only
    'GetIniSettings
  End If
  ''
  
  ' if there is no library, don't set anything else
  If Len(m_strLibrary) > 0 Then
    m_ucToolPanel.SetShapeSettings m_strLibrary, m_strFolder, m_strShape
  End If
End Sub


'------------------------------
Private Sub UserControl_Terminate()
  Dim frmIndex As Integer
  Dim frm As Form
  
  On Error Resume Next
  DoDwgFileClose
  DoDwgCloseUMLProject
  
  ' clean up toolbar
  Ge1.Tool = GETOOL_SELECT
  If Not m_ucToolBar Is Nothing Then
    m_ucToolBar.UpdateToolbarButtons
    m_ucToolBar.EnableUndoBtn False
  End If
  
  If Not m_ucToolPanel Is Nothing Then
    m_ucToolPanel.RemoveGeLibraries
    m_ucToolPanel.EmptyCurrentShapeValues
  End If
  
  
  If Not m_DwgEditor Is Nothing Then m_DwgEditor.ResetContent
  Set m_DwgEditor = Nothing
  Set m_ucToolBar = Nothing
  Set m_ucToolPanel = Nothing
  Set m_LayerDefs = Nothing
  Set ucMessageWindow = Nothing
  Set Ge1 = Nothing
  Set m_GeCtrl = Nothing
  Set Projects = Nothing
  
  UserControl.Parent.UnloadForm
End Sub

'------------------------------
Private Sub picToolpanel_Resize()
  AlignToolPanel
End Sub
'------------------------------
Private Sub AlignToolPanel()
  On Error Resume Next
  ucToolPanel.Move 15, 15, picToolpanel.Width - 15, picToolpanel.Height - 15
End Sub
'------------------------------
Private Sub UserControl_Resize()
  On Error Resume Next
  
  Dim L As Single, t As Single, W As Single, H As Single
  
  If m_bLoading Then Exit Sub

  If picToolpanel.Visible Then
    W = UserControl.ScaleWidth - picToolpanel.Width
    If picToolpanel.Align = vbAlignLeft Then L = picToolpanel.Width   ' not on left
  Else
    W = UserControl.ScaleWidth
  End If
  
  If ucToolBar1.Visible Then
    t = ucToolBar1.Height
  End If
  
  H = UserControl.ScaleHeight - t
  If StatusBar.Visible Then
    H = H - StatusBar.Height
  End If
  '
  Ge1.Move L, t, W, H

  AlignToolPanel

End Sub

'-----------------------------
Private Sub UserControl_KeyDown(KeyCode As Integer, Shift As Integer)
  DoKeyDown KeyCode, Shift
End Sub


'-----------------------------
Private Sub DoKeyDown(KeyCode As Integer, Shift As Integer)
  '========== Keyboard handler
  Dim ShiftDown As Boolean
  Dim CtrlDown As Boolean
  Dim bSendGe As Boolean

  On Error Resume Next
  If Not m_GeCtrl.HasFocus Then Exit Sub
  
'  ' check for focus (eg: Del in Layers grid is deleting items on drawing)
'  If Screen.ActiveControl.Name <> "Ge1" Then Exit Sub
  
  ShiftDown = (Shift And vbShiftMask) > 0
  CtrlDown = (Shift And vbCtrlMask) > 0
  
  If ShiftDown And KeyCode = vbKeyF4 Then
    KeyCode = 0
    DoExit
    Exit Sub
  End If
  
  If KeyCode = vbKeyMenu Then Exit Sub
  
  ' block Alt as something like Alt+W (window) will send the W to cmdLine form
  If Shift = vbAltMask Then Exit Sub
  
  ' shift or just a key pressed
  Select Case KeyCode
    Case vbKeyEscape
      KeyCode = 0
      m_GeCtrl.SimulateESC
      If m_bMovingPage Then EndMovePage False
      If m_bDistanceTool Then
        m_GeCtrl.EnableUndo = True ' restore
        m_bDistanceTool = False
        m_GeCtrl.Tool = m_nCurTool
        m_ucToolPanel.UpdateToolButtons
        m_ucToolBar.UpdateToolbarButtons
      End If
      If m_bCreatingObj Or m_bScalingObj Then
        m_bCreatingObj = False
        m_bScalingObj = False
        UpdateSelDimension 0, 0   ' show to status bar
      ElseIf m_bMovingObj Then
        m_bMovingObj = False
        UpdateSelDimension 0, 0   ' show to status bar
      End If
      
    Case vbKeyDelete
      KeyCode = 0
      m_DwgEditor.Delete
'      m_GeCtrl.Delete
      Exit Sub
    Case vbKeyMenu  ' 18  MENU (Alt) key
      Exit Sub
    
    Case vbKeyReturn
      ' pass to CG if drawing object. Otherwise pass to command line
      Select Case m_GeCtrl.Tool
        ' don't send to Ge for these tools.
        Case GETOOL_TEXTINSHAPETOOL
        Case GETOOL_SELECT
        Case GETOOL_PLACESELECTION
        Case Else: bSendGe = True
      End Select
    ' arrow keys
    Case vbKeyPageUp: bSendGe = True
    Case vbKeyPageDown: bSendGe = True
    Case vbKeyEnd: bSendGe = True
    Case vbKeyHome: bSendGe = True
    Case vbKeyLeft: bSendGe = True
    Case vbKeyUp: bSendGe = True
    Case vbKeyRight: bSendGe = True
    Case vbKeyDown: bSendGe = True
  End Select
  '
  If bSendGe Then
    m_GeCtrl.SimulateKeyDown KeyCode
    KeyCode = 0
  End If
'  KeyCode = 0
  
End Sub

'------------------------------
Private Sub UpdateCaption(strDwgName As String)
  Dim strNameCur As String
  Dim strCaption As String
  
  On Error Resume Next
  
  If Len(strDwgName) = 0 Then
    strNameCur = "untitled"
  Else
    strNameCur = strDwgName
    m_strGeFileName = strDwgName
  End If
  
  strCaption = strNameCur
  
  If m_bReadOnly Then strCaption = strCaption & " (Read-only) "
  If m_bGeIsModified Then strCaption = strCaption & " *"
  m_strCaption = strCaption
  RaiseEvent CaptionChanged(m_strCaption)
  
End Sub
'------------------------------
Public Function SetDwgIsModified(ByVal bVal As Boolean)
  ' callback from ucToolPanel
  On Error Resume Next
  If (Not m_bDistanceTool) Then
    m_bGeIsModified = bVal
    m_ucToolBar.EnableSaveBtn m_bGeIsModified
    SetCanUndo Ge1.CanUndo
    UpdateCaption m_strGeFileName
  End If
End Function


'------------------------------
Public Sub DoFindLibrary(ByVal OriginalPathName As String, NewPathName As String)
  ' call dialog and then have user go find it.
  ' fill in NewPathName with result of search
  Dim strMsg As String
  Dim bRet As Boolean
  Dim strName As String
  Dim strLib As String
  
  On Error Resume Next
  ' try and find from INI file
  strName = OriginalPathName
  If GetLibraryFromIni(strName, strLib) Then
    NewPathName = strLib
    Exit Sub
  End If
  
  ' if not found, get user to find it
  strMsg = "Failed to locate Library '" & OriginalPathName & "'. Please locate it now!"
  MsgBox strMsg
  strName = StripPath(OriginalPathName)
  If Len(strName) = 0 Then strName = OriginalPathName
  
  CommonDlg.CancelError = True  ' enable so that can test for Err
  CommonDlg.DefaultExt = "mdb"
  CommonDlg.DialogTitle = "Locate Library with name " & strName
  CommonDlg.MaxFileSize = 2600
  CommonDlg.FLAGS = cdlOFNHideReadOnly Or cdlOFNPathMustExist Or cdlOFNFileMustExist
  CommonDlg.InitDir = m_strDir
  CommonDlg.FileName = strName
  CommonDlg.Filter = "CG Library (*.mdb)|*.mdb||"
  CommonDlg.ShowOpen
  If err = 0 Then
    ' found it. Save to INI file
    strLib = CommonDlg.FileName
    AddLibraryToIni strLib
     m_ucToolPanel.GetAttachedLibraries
    '
    NewPathName = CommonDlg.FileName
    m_bHadToLocateLibrary = True
  End If

End Sub

'======================================================================================
' Misc
'======================================================================================
'------------------------------
Private Function SetCanUndo(bVal As Boolean)
  m_ucToolBar.EnableUndoBtn bVal
End Function

Public Property Get IsDwgDirty() As Boolean
  IsDwgDirty = m_bGeIsModified
End Property

'======================================================================================
' the CGCtrl
'======================================================================================
'------------------------------
Private Sub Ge1_ConnectionChanged(ByVal Action As Integer, _
        ByVal IDLine As Long, _
        ByVal IDA As Long, ByVal VarA As Variant, ByVal NameA As String, _
        ByVal TypeA As Integer, ByVal StsA As Integer, _
        ByVal IDB As Long, ByVal VarB As Variant, ByVal NameB As String, _
        ByVal TypeB As Integer, ByVal StsB As Integer)
  ''''
  ' connection made / broken / etc..
  
  m_ucToolPanel.Proc_ConnectionChanged Action, IDLine, _
      IDA, VarA, NameA, TypeA, StsA, _
      IDB, VarB, NameB, TypeB, StsB
  
  m_DwgEditor.ConnectionChanged Action, IDLine, _
      IDA, VarA, NameA, TypeA, StsA, _
      IDB, VarB, NameB, TypeB, StsB
  
  
End Sub

'------------------------------
Private Sub Ge1_FilenameChanged(ByVal OldName As String, ByVal NewName As String)
  UpdateCaption NewName
End Sub

'------------------------------
Private Sub Ge1_UndoAvailable(ByVal bAvailable As Boolean)
  m_ucToolBar.EnableUndoBtn (bAvailable)
End Sub

'------------------------------
Private Sub Ge1_UndoPreNotify(ByVal nAction As Long)
  ' before undo. Catch un-create and inform user
  Dim Response As Integer
  If m_bUndoWithoutAsking = True Then
    m_bUndoWithoutAsking = False
    Exit Sub
  End If
  If 0 < nAction And nAction < 100 Then
    Response = MsgBox( _
      "Undo will delete object from drawing. It can not be un-deleted." & vbCr & vbLf & "Do you want to continue?", _
      vbYesNoCancel + vbQuestion, PROJECT_TITLE + " - Undo")
    If Response = vbNo Or Response = vbCancel Then
      Ge1.DoAction = False
    End If
  End If

End Sub


'------------------------------
Private Sub Ge1_LibraryChanged(ByVal LibraryName As String, ByVal FolderName As String, ByVal ShapeName As String)
  ' somethng has changed in the library
  ' Oct 16 function below is empty in toolpanel
  m_ucToolPanel.LibraryChanged LibraryName, FolderName, ShapeName
  
  ' Inspect the changed shape for changes.  If connectors have been changed, update the UDIDef.
  VerifyConnectorsForChangedShape FolderName, ShapeName
End Sub

'------------------------------
Private Sub Ge1_LibraryListChanged(ByVal LibraryName As String, ByVal Action As Integer)
  ' user added/remove library using internal CG Dialog
  ' Action: 0 = Added library, 1 = removed library
  m_ucToolPanel.GetAttachedLibraries
End Sub
'------------------------------
Private Sub Ge1_OnIsModified(ByVal Value As Boolean)
  ' something has changed
  SetDwgIsModified True
End Sub

'------------------------------
Private Sub Ge1_OnMouseMove(ByVal X As Double, ByVal Y As Double)
    
  If m_DwgEditor Is Nothing Then Exit Sub
  If Not m_bDeferObjHit Then
    ShowCursorPos X, Y
    m_dGeX = X
    m_dGeY = Y
    m_DwgEditor.OnMouseMove X, Y
    
    If m_bCreatingObj Or m_bScalingObj Then
      UpdateNewObjectSize X, Y
    ElseIf m_bMovingObj Then
      UpdateSelDimension X - m_ptMoveX, Y - m_ptMoveY, False
    End If
  End If
  
End Sub

'------------------------------
Private Sub Ge1_SelMoveCopyDelta(ByVal StartX As Double, ByVal StartY As Double, ByVal deltaX As Double, ByVal deltaY As Double)
  ' this is fired just before BeginSelMove or BeginSelCopy
  m_DwgEditor.SetMoveCopyDelta deltaX, deltaY
End Sub
'------------------------------
Private Sub Ge1_ActionCancelled()
  'A notification that an Action (eg: Move or SelMove) was cancelled.
  ' This is sent after the GeCtrl has had time to remove the outlines of the objects
  ' being moved/copied and to refresh the screen.
  m_DwgEditor.DoActionCancelled
End Sub

'------------------------------
Private Sub Ge1_UndoOccurred(ByVal eAction As Integer)
  '      ACTION_NONE       = 0,       // 0
  '      ACTION_DELETE     = 1,       // CG objects being deleted
  '      ACTION_MOVE       = 2        // CG objects being moved

  ' notification that Undo action has occurred.
  ' this event is fired AFTER the actual Undo operation
  On Error Resume Next
  m_DwgEditor.UndoOccurred eAction
End Sub

'-----------------------
Private Sub Ge1_EndInsertShape()
  On Error Resume Next
  If Projects Is Nothing Then
     GetProjects Projects, m_Projects, CommonDlg
     If Not g_DrawingDefMgr.LoadModelDef() Then
         gMsgWnd.LogMessage "Error loading xml model definition"
     End If
  Else
    If Projects.count = 0 Then
       GetProjects Projects, m_Projects, CommonDlg
        If Not g_DrawingDefMgr.LoadModelDef() Then
            gMsgWnd.LogMessage "Error loading xml model definition"
        End If
    End If
  End If
  
  If Projects.count = 0 Then
    MsgBox "No UML project selected.  Dialog will not be properly initialized"
  End If
  ' this event will be fired at the end of a Paste operation
  m_DwgEditor.EndPaste
'  UpdateSelectionStats
End Sub

'-----------------------
Private Sub Ge1_EndSelectScale()
  ' this event will be fired at the end of a Scale operation
  ' or when a UserGroup has been Extruded
  m_ucToolPanel.GeSelExtents
  m_bScalingObj = False
  m_DwgEditor.EndSelectScale m_GeCtrl.IsExtruding
End Sub
'------------------------------
Private Sub Ge1_BeginSelectCopy()
    'A notification that indicated that the object is about to
    'be Copied to a new location due to a UI mouse operation.
  If m_DwgEditor.BeginSelectCopy Then
    Ge1.DoAction = True
  Else
    Ge1.DoAction = False
  End If
End Sub

'------------------------------
Private Sub Ge1_EndSelectCopy()
  ' operation is totally complete
  m_bMovingObj = False
  m_DwgEditor.EndSelectCopy
End Sub

'-----------------------
Private Sub Ge1_HaveObjectWithUserID(ByVal UserID As Long, ByVal nType As Integer, ByVal ParentUserID As Long)
  m_DwgEditor.NotifyHaveObjectWithUserID UserID, nType, ParentUserID
'  Dim strMsg As String
'  strMsg = "UserID:" & UserID & _
'              " ,type: " & nType & _
'              " ,ParentUserID:" & ParentUserID
'  Debug.Print strMsg
End Sub

'------------------------------
Private Sub Ge1_PostErrMsg(ByVal ErrCode As Long, ByVal AuxMsg As String)
  Dim ErrTemp As Variant
  ErrTemp = err
  Dim strMsg As String
  strMsg = "Ge1:" & ErrCode & ":" & AuxMsg
  gMsgWnd.LogMessage strMsg
  err = ErrTemp
End Sub

'------------------------------
Private Sub Ge1_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
  ' if Right button, do Props
'  Dim bSel As Boolean
  
  If Button = 2 Then  ' Right Button
    If m_GeCtrl.CanCopy Then  ' if something selected, takeover
      Ge1.DoRightClick = False
      DoPopupMenu
    End If
  End If
End Sub

'------------------------------
Private Sub Ge1_EndCreateShapeDef()
  ' Reset here on SmartShape creation
  If m_bCreatingSmartShape Then
    m_GeCtrl.TreatShapesAsUserGroups = False
    m_bCreatingSmartShape = False
  End If
  m_ucToolPanel.UpdateShapeList
End Sub

'------------------------------
Private Sub Ge1_AddVertex()
  ' called each time a vertex is added to a line
    m_ptObjX = m_dGeX
    m_ptObjY = m_dGeY
End Sub

'------------------------------
Private Sub Ge1_PointPicked(ByVal X As Double, ByVal Y As Double)
  ' fired back when the tool is set to GETOOL_PICKPOINT and the user left clicks
  Dim strMsg As String
  Dim ptX As Single, ptY As Single
  On Error Resume Next
    ptX = X:    ptY = Y
    strMsg = "X: " & Format(ptX, "0.0000") & _
            " Y: " & Format(ptY, "0.0000")
      SetStatusText strMsg
      DoGotPoint ptX, ptY
 
End Sub

'-----------------------------
Public Sub DoGotPoint(ByVal X As Single, ByVal Y As Single)
  ' END: got the point on the dwg
  On Error Resume Next
  ' update x,y insertion text fields on toolpanel
  If ucToolPanel.IsPickingPoint Then ucToolPanel.SetToolPanelInsertionPt X, Y
End Sub

'------------------------------
Private Sub Ge1_BeginSelectScale()
  ' called at beginning of obj scale
  On Error Resume Next
  m_bScalingObj = True
  GetSelSizeParams
End Sub
  
'------------------------------
Private Sub GetSelSizeParams()
  ' get extents (width/height)
  On Error Resume Next
  Ge1.GetSelExtents m_sllX, m_sllY, m_surX, m_surY
  m_wtS = m_surX - m_sllX:  m_htS = m_surY - m_sllY
  ' get current mouse pos
  m_ptObjX = m_dGeX
  m_ptObjY = m_dGeY
  
  ' determine starting corner
  If m_ptObjX = m_sllX Then    ' left side
    If m_ptObjY = m_sllY Then  ' bottom
      m_iScaleCorner = 0  ' LL
    Else
      m_iScaleCorner = 1  ' UL
    End If
  Else    ' right side
    If m_ptObjY = m_sllY Then  ' bottom
      m_iScaleCorner = 3  ' LR
    Else
      m_iScaleCorner = 2  ' UR
    End If
  End If
  
End Sub

'------------------------------
Private Sub Ge1_BeginCreateObject()
  ' called at beginning of obj creation
    On Error Resume Next
    m_ptObjX = m_dGeX
    m_ptObjY = m_dGeY
    m_bCreatingObj = True
End Sub

'------------------------------
Private Sub UpdateNewObjectSize(ByVal X As Double, ByVal Y As Double)
  ' update to status bar. x/y are current mouse position
'  Dim strMsg As String
  Dim dX As Single, dy As Single
  
  On Error Resume Next
  
    If m_bCreatingObj Then      ' new
      dX = Abs(X - m_ptObjX)
      dy = Abs(Y - m_ptObjY)
    ElseIf m_bScalingObj Then   ' scaling
      Select Case m_iScaleCorner
        Case 0    ' LL
          dX = m_wtS + (m_sllX - X):  dy = m_htS + (m_sllY - Y)
        Case 1    ' UL
          dX = m_wtS + (m_sllX - X):   dy = m_htS + (Y - m_surY)
        Case 2    ' UR
          dX = m_wtS + (X - m_surX):     dy = m_htS + (Y - m_surY)
        Case 3    ' LR
          dX = m_wtS + (X - m_surX):   dy = m_htS + (m_sllY - Y)
      End Select
      '
      dX = Abs(dX): dy = Abs(dy)
    End If
    UpdateSelDimension dX, dy
  
End Sub

'------------------------------
Private Sub Ge1_EndCreateObject(ByVal nObjID As Long)
    Dim nID As Long
    nID = nObjID
    Ge1.DoAction = True
    EndCreateObject nID
    m_bCreatingObj = False
    m_bMovingObj = False
End Sub


'------------------------------
Private Sub Ge1_FindLibrary(ByVal OriginalPathName As String, NewPathName As String)
  ' request to find a library named OriginalPathName.
  ' call dialog and then have user go find it.
  ' fill in NewPathName with result of search
  On Error Resume Next
  DoFindLibrary OriginalPathName, NewPathName
End Sub

'------------------------------
Private Sub Ge1_KeyDown(KeyCode As Integer, Shift As Integer)
  DoKeyDown KeyCode, Shift
End Sub

'------------------------------
Private Sub Ge1_EndSelectMove()
  If m_bMovingPage Then EndMovePage True
  
  ' reupdate Width/Height at end of move
  On Error Resume Next
  If m_bMovingObj Then
    m_bMovingObj = False
    ' DO NOT CALL this as is leaving droppings in some cases (large qty of objects)
'    Ge1_SelectionChanged
  End If
  
  ' show last tool after move complete and turn-off move/copy button
  m_ucToolPanel.UpdateToolButtons
  m_ucToolBar.UpdateToolbarButtons
End Sub

'------------------------------
Private Sub Ge1_BeginSelectMovePre()
  ' fired at beginning of a move/moveCopy. This is for information lnly.
  ' the BeginSelectMove event is fired after the user has moved the outlines of the object
  ' and before the complete move operation is done.
  m_bMovingObj = True
  m_ptMoveX = m_dGeX
  m_ptMoveY = m_dGeY
End Sub

'------------------------------
Private Sub Ge1_ObjectHit(ByVal GeID As Long, ByVal VarValid As Boolean, varObject As Variant)
  ' object got hit by the user
  If Not m_bDeferObjHit Then
    If VarValid Then
      On Error Resume Next
      Set m_LastHitUDI = Nothing
      Set m_LastHitUDI = varObject
    End If
    If m_DwgEditor Is Nothing Then Exit Sub
    m_DwgEditor.ObjectHit GeID, VarValid, varObject
  Else
    m_bDeferObjHit = False
  End If
  
End Sub
'------------------------------
Private Sub Ge1_SelectionChanged()
  Dim nCnt As Long
  Dim strMsg As String
  
  Dim dLeft As Single
  Dim dBottom As Single
  Dim dRight As Single
  Dim dTop As Single
  
  Dim strType As String
  Dim GeID As Long
  Dim nGeType As Integer
  
  On Error Resume Next
  If m_bMovingPage Then EndMovePage False
  
  m_DwgEditor.SelChanged
  
  m_bMovingObj = False
  m_bScalingObj = False
  
  If Not m_bDeferShowCount Then
    
    nCnt = m_GeCtrl.SelNumberOfObjects
    If nCnt > 0 Then
      strMsg = nCnt & " objects selected"
      ' if only 1 selected, show its type
      If nCnt = 1 Then
        GeID = m_GeCtrl.GetFirstSelObject
        If GeID > 0 Then
          m_GeCtrl.CurrentPropertyID = GeID
          nGeType = m_GeCtrl.ObjectType
          m_GeCtrl.CurrentPropertyID = 0  ' reset selector
          strType = GeWorker.GetGeObjectType_Str(nGeType)
          strType = " (" & strType & ")"
          strMsg = strMsg & strType
        End If
        m_ucToolPanel.UpdateSelGeID GeID
      Else
        m_ucToolPanel.UpdateSelGeID 0
      End If
    Else
      m_ucToolPanel.UpdateSelGeID 0
    End If
    
    '
    SetStatusText strMsg    ' show to status bar
    
    ' get extents (width/height)
    If nCnt = 0 Then
      UpdateSelDimension 0, 0
    Else
      Dim llX As Single, llY As Single, urX As Single, urY As Single
      Ge1.GetSelExtents llX, llY, urX, urY
      UpdateSelDimension urX - llX, urY - llY
    End If
    
    ''
    m_ucToolPanel.UpdateToolButtons
    m_ucToolBar.UpdateToolbarButtons
    
  End If
  m_bDeferShowCount = False
  
End Sub


'======================================================================================
' Menus
'======================================================================================
'========================
' FILE
'========================
'------------------------------
'------------------------------
Private Sub mnuFileItem_Click(index As Integer)
  On Error Resume Next
  m_bDeferObjHit = True ' set this so Menus on dialogs are enabled as call stack gets screwed up if Ge has a hit
  Select Case index
    Case 0:      DoDwgFileNew
    Case 1:      DoDwgFileOpen
    Case 2:      DoDwgFileBrowse
    Case 3:      DoDwgFileClose
'    Case 4 ' -
    Case 5:      DoDwgFileSave
    Case 6:      DoDwgFileSaveAs
'    Case 7 ' -
    Case 8:      m_GeCtrl.PageSetup

    Case 10:      DoDwgOpenUMLProject
    Case 11:     DoDwgSaveUMLProject
    Case 12:     DoDwgSaveAsUMLProject
    Case 13:     DoDwgCloseUMLProject
'    Case 14 -
    Case 15  ' B&W
      m_bUsePictureColor = False
      BeginDoDwgPrint
    Case 16   ' Color
      m_bUsePictureColor = True
      BeginDoDwgPrint
'    Case 17 ' -
    Case 18:      OnInsertPicture ' Insert Picture
    Case 19:      DoDwgImport
    Case 20:      DoDwgExport
'    Case 21 ' -
    Case 22:      DoExit
  End Select
  m_bDeferObjHit = False
End Sub
'------------------------------
Private Sub OnInsertPicture()
  '
  Dim strVal As String, strKey As String
  Dim strCurPath As String
  
  On Error Resume Next
  
  ' memorize current path (cwd)
  strCurPath = CurDir
  
  ' try last picture path
  strVal = strCurPath
  strKey = INIENTRY_LASTPICTUREPATH
  strVal = AppGetProfileString(INISECTION_GEEDITOR, strKey, strVal)
  
  ' change cwd if found and not same as current
  If Len(strVal) > 0 Then
    If strVal <> strCurPath Then
      ChDrive strVal
      ChDir strVal
      If err <> 0 Then err = 0
    End If
  End If
  
  '' get picture from GeCtrl (it will look in cwd first)
  m_GeCtrl.OnInsertPicture
  
  ' memorize picture path
  strVal = CurDir
  AppWriteProfileString INISECTION_GEEDITOR, strKey, strVal
  
  ' restore cwd
  ChDrive strCurPath
  ChDir strCurPath
  
End Sub

'------------------------------
Private Sub mnuRecentFile_Click(index As Integer)
  Dim strName As String
  Dim bsaved As Boolean
  
  On Error Resume Next
  Select Case index
    Case 0  ' -
      Exit Sub
    Case Else
      strName = mnuRecentFile(index).Caption
      If FileExists(strName) Then
        If Not m_GeCtrl.IsEmpty Then CleanupPreviousProjectFiles
        If OpenGeFile(strName) Then
            'Ask the user to open a UML drawing for this project if one not already loaded
            If Not UMLProjectOpen Then
                DoDwgOpenUMLProject
            Else
                'In this case a UML project was open before the CGModeler project, so make sure shapes
                'defined in UML project are loaded
                If m_DwgEditor Then
                    If Not m_DwgEditor.UDIDefMgr.LoadModelDef() Then
                        gMsgWnd.LogMessage "Error loading xml model definition"
                    End If
                End If
            End If
        End If
      Else
        ' user tried to open it, but its not there. remove from INI
        gMsgWnd.LogMessage "Failed to find file " & strName
        RemoveRecentFileEntry strName
        
        ' refresh my recentFile menu
        GetRecentFiles
        
      End If
  
  End Select
End Sub

'------------------------------
Public Function DoDwgFileIsModified(bsaved As Boolean) As Boolean
  ' prompt user for modified drawing
  ' return False if User presses Cancel
  Dim Response As Integer
  Dim msg As String
  Dim bRet As Boolean
  Dim strNameCur As String
  Dim bNameValid As Boolean
  
  On Error Resume Next
  DoDwgFileIsModified = True
  bsaved = False
    If m_bGeIsModified Then
      strNameCur = m_GeCtrl.GetDwgName
      If Len(strNameCur) > 0 Then
        bNameValid = True
      Else
        bNameValid = False
        strNameCur = "untitled" ' & Me.tag
        UpdateCaption strNameCur
      End If
      
      msg = "Drawing '" & strNameCur & "' is Modified. Save Now?"
      Response = MsgBox(msg, vbYesNoCancel, "Save")
      
      If Response = vbNo Then
        DoDwgFileIsModified = True
        Exit Function
      ElseIf Response = vbCancel Then
        DoDwgFileIsModified = False
        Exit Function
      Else
        If bNameValid Then
          ' Save
          bRet = DoDwgFileSave
          If Not bRet Then
            gMsgWnd.LogMessage "Failed to save Drawing"
          Else
            bsaved = True
            DoDwgFileIsModified = True
            UpdateCaption strNameCur
          End If
        Else
        ' SaveAs
          bRet = DoDwgFileSaveAs
        End If
      End If
    End If
End Function

'------------------------------
Private Sub DoExit()
    UserControl_Terminate
    Unload Me
End Sub

'------------------------------
Public Function OpenGeFile(strName As String) As Boolean
  ' check for Exceptions from GeOCX
  Dim bRet As Boolean
  Dim strMsg As String
  On Error Resume Next
  
  OpenGeFile = True
  m_bReadOnly = False
  m_GeCtrl.OpenDwg strName
  'Err = 0
  
  If err = 70 Then  ' if read locked, err = 70 (Permission Denied)
    ' try opening read only
    err = 0
    m_bReadOnly = True
    m_GeCtrl.OpenDwgReadOnly strName
  End If
  '
  If err <> 0 Then
    strMsg = Error & " Opening File " & strName
    gMsgWnd.LogMessage strMsg
    OpenGeFile = False
    UpdateCaption ""
  Else
    OpenGeFile = True
    UpdateCaption strName
    UpdateFileMenu strName
    SetCurrentDirectory strName ' change working dir
    m_strDir = StripFile(strName)
    m_bLoadedAsGEF = True
  
    m_LayerDefs.SerializeToGe Ge1, False  ' false = load
    m_LayerDefs.ReadOnly = m_bReadOnly
    
    m_DwgEditor.FileOpen Ge1, m_bReadOnly, strName
    
  End If
  ''
  If Not m_bHadToLocateLibrary Then
    m_bGeIsModified = False
  Else
    If Not m_bReadOnly Then
      SetDwgIsModified True
      m_bHadToLocateLibrary = False
    End If
  End If
  ''
  m_ucToolBar.EnableSaveBtn m_bGeIsModified
  m_ucToolPanel.UpdateControlsFromGe

End Function


'------------------------------
Private Function DoDwgFileBrowse() As Boolean
  ' browse to open
  Dim strName As String
  Dim frmB As frmFileBrowse
  
  On Error Resume Next

  strName = GetMostRecentFile
  Set frmB = New frmFileBrowse
  frmB.FileName = strName
  frmB.Show vbModal
  If Not frmB.Cancelled Then
    strName = frmB.FileName
    DoDwgFileBrowse = OpenGeFile(strName)
  End If
End Function

'------------------------------
Private Function DoDwgFileOpen() As Boolean
  ' check for Exceptions from GeOCX
  Dim bsaved As Boolean
  On Error Resume Next
  ' prompt for modified dwg. If false, cancel was pressed
  If Not m_GeCtrl.IsEmpty Then CleanupPreviousProjectFiles
 ' If Not DoDwgFileIsModified(bsaved) Then Exit Function
  DoDwgFileOpen = FileOpen()
End Function
'------------------------------
Public Function FileSave() As Boolean
  DoDwgFileSave
End Function

'------------------------------
Public Function FileOpen() As Boolean
  ' check for Exceptions from GeOCX
  Dim strName As String
  
  On Error Resume Next
  FileOpen = False
  If Len(m_strDir) = 0 Then
    strName = GetMostRecentFile
    If Len(strName) > 0 Then
      m_strDir = StripFile(strName)
    End If
  End If
  If GetDwgFilePath(strName, "Open a Graphic Editor File", False) Then
    FileOpen = OpenGeFile(strName)
    If FileOpen Then
        'Ask the user to open a UML drawing for this project if one not already loaded
        If Not UMLProjectOpen Then
            DoDwgOpenUMLProject
        Else
            'In this case a UML project was open before the CGModeler project, so make sure shapes
            'defined in UML project are loaded
            If m_DwgEditor Then
                If Not m_DwgEditor.UDIDefMgr.LoadModelDef() Then
                    gMsgWnd.LogMessage "Error loading xml model definition"
                End If
            End If
        End If
    End If
  End If
End Function
'------------------------------
Private Function GetDwgFilePath(FileName As String, szTitle As String, bCreate As Boolean) As Boolean
  ' Get a .cgf path and name, from the User
  Dim strMsg As String
  Dim bRet As Boolean
  
  On Error Resume Next
  GetDwgFilePath = False
  CommonDlg.CancelError = True  ' enable so that can test for Err
  CommonDlg.DefaultExt = "CGF"
  CommonDlg.DialogTitle = szTitle
  CommonDlg.MaxFileSize = 2600
  CommonDlg.FLAGS = cdlOFNHideReadOnly Or cdlOFNPathMustExist Or cdlOFNFileMustExist
  If bCreate Then
    CommonDlg.FLAGS = CommonDlg.FLAGS Or cdlOFNCreatePrompt
  End If
  CommonDlg.InitDir = m_strDir
  CommonDlg.FileName = ""
  CommonDlg.Filter = "CG Editor (*.cgf)|*.cgf||"
'  CommonDlg.FileName = FileName
'  CommonDlg.Action = 1  ' Open
  CommonDlg.ShowOpen
  If err = 0 Then
    FileName = CommonDlg.FileName
    GetDwgFilePath = True
  End If
End Function

'------------------------------
Private Function DoDwgFileNew() As Boolean
  ' new Drawing
  Dim bsaved As Boolean
  
  On Error Resume Next
  ' prompt for modified dwg. If false, cancel was pressed
  If DoDwgFileIsModified(bsaved) Then
    Ge1.InitNew
    SetDwgIsModified False
    Ge1.Redraw
    m_LayerDefs.ResolveWithGe Ge1
    m_ucToolPanel.UpdateControlsFromGe
    m_DwgEditor.ResetContent
    '
    m_strGeFileName = ""
    UpdateCaption ""
  End If

End Function

'------------------------------
Private Function DoDwgFileClose() As Boolean
  ' close Drawing and Unload
'  TODO - send event
  Dim bsaved As Boolean
  
  On Error Resume Next
  DoDwgFileIsModified bsaved ' prompt for modified dwg
End Function

'------------------------------
Private Function DoDwgFileSave() As Boolean
  Dim strMsg As String
  Dim strNameCur As String
  Dim bAs As Boolean
  
  On Error Resume Next
  bAs = False
  
  If m_bReadOnly Then
    MsgBox ("This file is Read-Only, please use 'Save As' to save it with a different name.")
    Exit Function
  End If
  
  strNameCur = m_GeCtrl.GetDwgName
  If Len(strNameCur) > 0 Then
    If FileExists(strNameCur) And m_bLoadedAsGEF Then


  ' save this Substorage
  If Not m_bReadOnly Then
    m_LayerDefs.SerializeToGe Ge1, True
    m_DwgEditor.FileSave Ge1
  End If


      ''
      m_GeCtrl.SaveDwg
    Else
      bAs = True
      DoDwgFileSave = DoDwgFileSaveAs
      strNameCur = m_GeCtrl.GetDwgName
    End If
  Else
    DoDwgFileSave = DoDwgFileSaveAs
    strNameCur = m_GeCtrl.GetDwgName
  End If
  '
  If err = 32755 Then      ' Cancel was selected, do nothing just leave
    DoDwgFileSave = False
    Exit Function
  ElseIf err <> 0 Then
    If Not bAs Then
      strMsg = Error & " Saving File " & strNameCur
      gMsgWnd.LogMessage strMsg
    End If
    DoDwgFileSave = False
  Else
    m_bGeIsModified = False
    m_ucToolBar.EnableSaveBtn m_bGeIsModified
    DoDwgFileSave = True
    UpdateFileMenu strNameCur
    UpdateCaption strNameCur
  End If
End Function

'------------------------------
Private Function DoDwgFileSaveAs() As Boolean
  ' save As
  Dim NewFileName As String
  Dim bSameAsLoad As Boolean
  Dim strMsg As String
  Dim strNameCur As String

  On Error Resume Next
  
  DoDwgFileSaveAs = True

  strNameCur = m_GeCtrl.GetDwgName
  CommonDlg.CancelError = True  ' enable so that can test for Err
  
  If Len(strNameCur) > 0 Then
    CommonDlg.FileName = strNameCur
  End If
  CommonDlg.DefaultExt = "CGF"

  CommonDlg.DialogTitle = "Save Drawing As"
  CommonDlg.Filter = "CG Editor (*.cgf)|*.cgf||"
  CommonDlg.FLAGS = cdlOFNHideReadOnly Or cdlOFNPathMustExist Or cdlOFNOverwritePrompt
  CommonDlg.ShowSave
  If err = 32755 Then      ' Cancel was selected, do nothing just leave
    DoDwgFileSaveAs = False
    Exit Function
  End If
   
  NewFileName = CommonDlg.FileName
  
  If m_bReadOnly And (NewFileName = m_GeCtrl.GetDwgName) Then
    MsgBox ("This file is Read-Only, please use a different name.")
    DoDwgFileSaveAs = False
    Exit Function
  End If

  
  ' save the drawing
  m_GeCtrl.SaveAsDwg NewFileName
  
  If err <> 0 Then
    strMsg = Error & " SavingAs File " & NewFileName
    gMsgWnd.LogMessage strMsg
    DoDwgFileSaveAs = False
  Else
    
  ' save the Layer stuff after new storage created by CG.
  m_LayerDefs.ReadOnly = m_bReadOnly
  If Not m_bReadOnly Then
    m_LayerDefs.SerializeToGe Ge1, True
    m_DwgEditor.FileSave Ge1
  End If
    
    m_bGeIsModified = False
    m_bLoadedAsGEF = True
    m_ucToolBar.EnableSaveBtn m_bGeIsModified
    m_bReadOnly = False
    SetCurrentDirectory NewFileName ' change working dir
    UpdateCaption NewFileName
    UpdateFileMenu NewFileName
  End If
End Function

Private Sub DoDwgOpenUMLProject()
    Dim strUMLProjectName
    Dim strUMLOldProject
    
    strUMLOldProject = GetUMLProjectName()
    If strUMLOldProject <> "" Then DoDwgCloseUMLProject
    
    If LoadRPYProject(CommonDlg) Then
        strUMLProjectName = GetUMLProjectName()
        If strUMLProjectName = "" Then Exit Sub
        If strUMLOldProject = strUMLProjectName Then Exit Sub
        SetUMLProjectText strUMLProjectName
        If Not m_DwgEditor.UDIDefMgr.LoadModelDef() Then
            gMsgWnd.LogMessage "Error loading xml model definition"
        End If
    Else
        gMsgWnd.LogMessage "A UML project has not been loaded."
    End If
End Sub

Private Sub DoDwgSaveUMLProject()
    If Not m_DwgEditor Is Nothing Then
        If Not m_DwgEditor.UDIDefMgr Is Nothing Then
            m_DwgEditor.UDIDefMgr.SaveModelDef
        End If
    End If
    SaveRPYProject CommonDlg
End Sub

Private Sub DoDwgSaveAsUMLProject()
    If Not m_DwgEditor Is Nothing Then
        If Not m_DwgEditor.UDIDefMgr Is Nothing Then
            m_DwgEditor.UDIDefMgr.SaveModelDef
        End If
    End If
    SaveRPYProjectAs CommonDlg
End Sub

Private Sub DoDwgCloseUMLProject()
    Dim answer As VbMsgBoxResult
    Dim i As Integer
    Dim j As Integer
    
    'Close any outstanding forms
    j = 0
    For i = 0 To (Forms.count - 1)
        If Forms(j).Name <> MAIN_FORM_NAME Then
            Unload Forms(j)
        Else
            j = j + 1
        End If
    Next
    
    If m_DwgEditor.UDIDefMgr.IsDirty() Then
        If Not doc.activeProject Is Nothing Then
            answer = MsgBox("Save UML Project " & doc.activeProject.Name & "?", vbYesNo, "Save")
        Else
            answer = MsgBox("Save UML Project?", vbYesNo, "Save")
        End If
        If answer = vbYes Then
          If Not m_DwgEditor.UDIDefMgr Is Nothing Then
              m_DwgEditor.UDIDefMgr.SaveModelDef
              SaveRPYProject CommonDlg
          Else
              MsgBox "Failed to save model definitions to UML project."
          End If
        End If
    End If
    If CloseRPYProject(CommonDlg) Then
        SetUMLProjectText "<No UML Project>"
        m_DwgEditor.UDIDefMgr.DestroyAll
        doc.quit
    End If
End Sub

Private Function UMLProjectOpen() As Boolean
    UMLProjectOpen = IsUMLProjectOpen()
End Function

'------------------------------
Private Sub DoDwgPrint()
  On Error Resume Next
  If Printer Is Nothing Then Exit Sub
  If DoPrintSetup Then DoDwgPrint1
End Sub
      
'------------------------------
Private Sub BeginDoDwgPrint()
  ' use a timer as print submenu may be causing app to crash
  ' on some Win95 machines
  On Error Resume Next

''''''''''
'  DoDwgPrint
'  Exit Sub
'''''''
  
  DoEvents
  TimerPrint.Interval = 20
  TimerPrint.Enabled = True
End Sub


'------------------------------
Private Sub TimerPrint_Timer()
  On Error Resume Next
  TimerPrint.Enabled = False
  m_GeCtrl.UsePictureColor = m_bUsePictureColor
  DoDwgPrint
  m_GeCtrl.UsePictureColor = False
  m_bUsePictureColor = False
End Sub
'------------------------------
Private Sub DoDwgPrint1()
  ' actually print it
  Dim bMetric As Boolean
  
  On Error Resume Next
  bMetric = False
    
  ' turn off sts events in case layer is hidden while printing so we don't get a modified event
  Dim bSend As Boolean
  bSend = m_GeCtrl.SendStatusEvents
'  m_GeCtrl.SelStepIntoGroups = True
  m_GeCtrl.SendStatusEvents = False
  m_LayerDefs.BeginPrint m_GeCtrl
    
    ' actually print it (call global function)
  PrintGeFile Printer, m_GeCtrl, True, bMetric       ' true = go for BSize

  m_LayerDefs.EndPrint m_GeCtrl
  ' turn back on
'  m_GeCtrl.SelStepIntoGroups = False
  m_GeCtrl.SendStatusEvents = bSend

End Sub

'------------------------------
Private Function DoPrintSetup() As Boolean
  Dim bRet As Boolean
  Dim nVal As Integer
  
  On Error Resume Next
    ' setup printer with user option(s)
  nVal = Printer.PaperSize
  nVal = AppGetProfileInt(INISECTION_GEEDITOR, INIENTRY_PAPERSIZE, nVal)
  'Printer.PaperSize = nVal
  Printer.PaperSize = m_GeCtrl.PaperSizeRaw
    
  Printer.Orientation = m_GeCtrl.PageOrientation      ' 1 = Portrait, 2 = Landscape
  
  ' err = 380 (Invalid property value) if failed to set (size or orient)
  If err <> 0 Then err = 0
    
    ' get settings and OK./cancel from user
  bRet = ShowPrinter(Nothing, , , , UserControl.HWND)
  If bRet Then
    ' save setting to INI file
    If (m_GeCtrl.IsEmpty) Then
      nVal = Printer.PaperSize
      AppWriteProfileInt INISECTION_GEEDITOR, INIENTRY_PAPERSIZE, nVal
    End If
  End If
  '
  DoPrintSetup = bRet
  
End Function

'------------------------------
Private Sub DoDwgImport()
  ' import (internal dialogs in GeCtrl)
  Dim strMsg As String
  
  On Error Resume Next
  BeginWaitCursor
  m_GeCtrl.FileImport
  If err <> 0 Then
    strMsg = Error
    strMsg = strMsg & " Importing File."
    gMsgWnd.LogMessage strMsg
  End If
  EndWaitCursor
End Sub

'------------------------------
Private Sub DoDwgExport()
  ' export (internal dialogs in GeCtrl)
  Dim strMsg As String
  
  On Error Resume Next
  m_GeCtrl.FileExport
  If err <> 0 Then
    strMsg = Error
    strMsg = strMsg & " Exporting File."
    gMsgWnd.LogMessage strMsg
  End If
End Sub

'========================
' View
'========================
'-------------------------------
Private Sub mnuView_Click()
    ' update menu
  mnuViewItem(0).Checked = StatusbarVisible
  
  mnuViewItem(4).Checked = m_GeCtrl.Rulers
  mnuViewItem(5).Checked = m_GeCtrl.ScrollBars
  mnuViewItem(6).Checked = m_GeCtrl.MarginDisplay
  
  mnuToolbarItem(0).Checked = ToolbarVisible
  mnuToolbarItem(1).Checked = Show2Toolbars
  
  mnuToolpanelItem(0).Checked = ToolPanelVisible
  mnuToolpanelItem(1).Checked = ToolPanelAlignLeft
  
  If m_GeCtrl.SelNumberOfObjects = 1 Then
    mnuGeometry.Enabled = True
  Else
    mnuGeometry.Enabled = False
  End If

End Sub

'-------------------------------
Private Sub mnuViewItem_Click(index As Integer)
  Dim bUpdate As Boolean
  
  On Error Resume Next
  bUpdate = True
  Select Case index
    Case 0  ' statusbar
      ShowStatusbar
'    Case 1  ' toolbar
'    Case 2 ' toolpanel
'    Case 3 ' -
    
    Case 4  ' Rulers
      m_GeCtrl.Rulers = Not (mnuViewItem(index).Checked)
    Case 5  ' ScrollBars
      m_GeCtrl.ScrollBars = Not (mnuViewItem(index).Checked)
    Case 6  ' Margins
      m_GeCtrl.MarginDisplay = Not (mnuViewItem(index).Checked)
'    case 7  ' -

    Case 8
      m_GeCtrl.Redraw
      bUpdate = False
  
  End Select
  '
  If bUpdate Then
    m_ucToolBar.UpdateToolbarButtons
    m_ucToolPanel.UpdateToolButtons
  End If
End Sub
'-------------------------------
Private Sub mnuToolbarItem_Click(index As Integer)
  Select Case index
    Case 0  ' std
      ToolbarVisible = Not mnuToolbarItem(0).Checked
    Case 1  ' additional
      Show2Toolbars = Not mnuToolbarItem(1).Checked
      If Show2Toolbars Then ToolbarVisible = True
  End Select
End Sub
'-------------------------------
Private Sub mnuToolpanelItem_Click(index As Integer)
  Select Case index
    Case 0  ' visible
      ToolPanelVisible = Not mnuToolpanelItem(index).Checked
    Case 1  ' on left
      ToolPanelAlignLeft = Not mnuToolpanelItem(index).Checked
  End Select
End Sub

Private Sub CleanupPreviousProjectFiles()
'See if user wants to save UML Project
'If modified, see if user wants to save drawing
    DoDwgFileClose
    DoDwgCloseUMLProject
End Sub

'========================
' EDIT
'========================
'------------------------------
Private Sub mnuEdit_Click()
  Dim bSel As Boolean

  On Error Resume Next
  
  ' check for focus (eg: Del in Layers grid is deleting items on drawing)
  ' disable the edit menu items so that the form does not eat the keyboard input
  ' if the active control is not CG.
  
'  If Screen.ActiveControl.Name <> "Ge1" Then
'    mnuEditItem(0).Enabled = False
'    mnuEditItem(1).Enabled = False
'    mnuEditItem(3).Enabled = False
'    mnuEditItem(4).Enabled = False
'    mnuEditItem(5).Enabled = False
'    mnuEditItem(6).Enabled = False
'    mnuEditItem(8).Enabled = False
'    mnuEditItem(10).Enabled = False   ' Ctrl-A
'    Exit Sub
'  End If
  
  bSel = m_GeCtrl.CanCopy
  mnuEditItem(0).Enabled = m_GeCtrl.CanUndo
'  mnuEditItem(0).Caption = "&UNDO"    '"Undo " & m_GeCtrl.UndoDescription
  mnuEditItem(1).Enabled = m_GeCtrl.CanDelete
  mnuEditItem(3).Enabled = m_GeCtrl.CanCut
  mnuEditItem(4).Enabled = bSel
  mnuEditItem(5).Enabled = bSel
  mnuEditItem(6).Enabled = m_GeCtrl.CanPaste
  mnuEditItem(8).Enabled = m_GeCtrl.CanEditText
  mnuEditItem(10).Enabled = True   ' Ctrl-A

End Sub
'------------------------------
Private Sub mnuEditItem_Click(index As Integer)
  On Error Resume Next
  
  Select Case index
    Case 0  ' Undo
      m_GeCtrl.Undo
    Case 1  ' Delete
      m_DwgEditor.Delete
'      m_GeCtrl.Delete
    Case 3  ' Cut
      m_DwgEditor.Cut
'      m_GeCtrl.Cut
    Case 4  ' Copy
      m_DwgEditor.Copy
'      m_GeCtrl.Copy
    Case 5  ' CopySpecial
      m_GeCtrl.CopySpecial
    Case 6  ' Paste
      m_DwgEditor.Paste
'      m_GeCtrl.Paste
    Case 8  ' Text
      m_GeCtrl.DoEditText
    Case 10 ' SelectAll
      m_GeCtrl.SelectAll
    
    Case 11 ' SelectAllLocked
      m_GeCtrl.SelectAllLocked
  
    Case 13 ' Move Page Origin
      BeginMovePage
    Case 15 ' List Selected Objects
      DoBrowseSelection
    Case 16 ' SmartSelection
      DoSmartSelection
  End Select
End Sub

'========================
' Format
'========================
'------------------------------
Private Sub mnuFormat_Click()
  Dim nSel As Long
  
  On Error Resume Next
  nSel = m_GeCtrl.SelNumberOfObjects
  mnuFormatItem(0).Enabled = IIf(nSel > 1, True, False) ' AlignSelection
  mnuFormatItem(1).Enabled = IIf(nSel > 0, True, False) ' AlignGrid
  mnuFormatItem(2).Enabled = IIf(nSel > 0, True, False) ' AlignSnap
  mnuFormatItem(3).Enabled = IIf(nSel > 1, True, False) ' AlignSize (make same)
  mnuFormatItem(4).Enabled = IIf(nSel > 2, True, False) ' AlignDistribute
  
  mnuFormatItem(6).Enabled = IIf(nSel > 0, True, False) ' Convert
End Sub

'------------------------------
Private Sub mnuAlignDistribute_Click(index As Integer)
  On Error Resume Next
  Select Case index
    Case 0: m_ucToolPanel.DistributeSelHorz
    Case 1: m_ucToolPanel.DistributeSelVert
  End Select
End Sub
'------------------------------
Private Sub mnuAlignGrid_Click(index As Integer)
  Dim nOp As Integer
  On Error Resume Next
  Select Case index
    Case 0: nOp = 0   ' Left
    Case 1: nOp = 1   ' right
    Case 3: nOp = 2   ' top
    Case 4: nOp = 3   ' bottom
    Case 6: nOp = 4   ' center
    Case Else: Exit Sub
  End Select
  GeWorker.AlignToGridOperation m_GeCtrl, nOp
End Sub
'------------------------------
Private Sub mnuAlignSel_Click(index As Integer)
  Dim nOp As Integer
  On Error Resume Next
  Select Case index
    Case 0:  nOp = 0 ' Lefts
    Case 1:  nOp = 5 ' CenterVertical (vertical center of last obj in list, move all others horizontally)
    Case 2:  nOp = 1 ' Rights
'   Case 3 ' -
    Case 4:  nOp = 2 ' Tops
    Case 5:  nOp = 4 ' Centers - CenterHorizontal (horizontal center of last obj in list, move all others vertically)
    Case 6:  nOp = 3 ' Bottoms
    Case Else: Exit Sub
  End Select
  m_GeCtrl.AlignSelection nOp
End Sub
'------------------------------
Private Sub mnuAlignSize_Click(index As Integer)
  ' make same size
  Dim nOp As Integer
  On Error Resume Next
  Select Case index
    Case 0: nOp = 1   ' width
    Case 1: nOp = 0   ' height
    Case 3: nOp = 2   ' both
    Case Else: Exit Sub
  End Select
  m_ucToolBar.MakeSameSizeOperation nOp
End Sub
'------------------------------
Private Sub mnuAlignSnap_Click(index As Integer)
  Dim nOp As Integer
  On Error Resume Next
  Select Case index
    Case 0: nOp = 0   ' Left
    Case 1: nOp = 1   ' right
    Case 3: nOp = 2   ' top
    Case 4: nOp = 3   ' bottom
    Case Else: Exit Sub
  End Select
  m_ucToolPanel.AlignToSnapOperation nOp
End Sub

'------------------------------
Private Sub mnuConvertItem_Click(index As Integer)
  Dim bRet As Boolean
  
  On Error Resume Next
  Select Case index
  Case 1
     bRet = m_GeCtrl.ConvertArcToPline
  Case 2
     bRet = m_GeCtrl.ConvertPgonToPline
  Case 3
     bRet = m_GeCtrl.ConvertPlinesToPline
  Case 5
     bRet = m_GeCtrl.ConvertPlineToPgon
  Case 6
     bRet = m_GeCtrl.ConvertRectToPolygon
  Case 7
     bRet = m_GeCtrl.ConvertSplitPline(1)
  Case 9
     bRet = m_GeCtrl.ConvertBezierToPolyline
  Case 11
    m_GeCtrl.ConvertPolygonsToPolyPolygon
  Case 12
    m_GeCtrl.ExplodePolyPolygon
  End Select
End Sub


'========================
' VIEW
'========================
'------------------------------
Private Sub mnuDwgViewItem_Click(index As Integer)
  Select Case index
    
    Case 0:      m_GeCtrl.ZoomIn    ' area
    Case 1:      GeWorker.ZoomInBy2 m_GeCtrl
    Case 2:      m_GeCtrl.ZoomOut   ' by 2
    Case 3:      m_GeCtrl.ZoomPrevious
'    Case 4  ' -
    Case 5:      m_GeCtrl.ZoomPage
    Case 6:      m_GeCtrl.ZoomExtents
    
    Case 7:      m_GeCtrl.ZoomPageWidth
  End Select
End Sub

'========================
' TOOL
'========================
'------------------------------
Private Sub mnuTool_Click()
  Dim bDoSelect As Boolean
  Dim i As Integer
  ' clear all currently checked
  For i = 0 To mnuToolItem.UBound()
    ' if a Separator, skip it.
    If Not mnuToolItem(i).Caption = "-" Then
      mnuToolItem(i).Enabled = True
      mnuToolItem(i).Checked = False
    End If
  Next i
  
  ' see if anything in selection
  bDoSelect = True
  If Not (m_GeCtrl.CanCopy) Then
    mnuToolItem(3).Enabled = False
  ElseIf m_GeCtrl.IsMoveCopyTool Then
    mnuToolItem(3).Checked = True
    bDoSelect = False
  End If
  
  If bDoSelect Then
    Select Case m_GeCtrl.Tool
'      Case GETOOL_NONE
'        mnuToolItem().Checked = True
      Case GETOOL_SELECT
        If Not m_GeCtrl.SelectMoveOnly Then
          mnuToolItem(0).Checked = True
        Else
          mnuToolItem(1).Checked = True
        End If
'     Case GETOOL_PICK
'       mnuToolItem(2).Checked = True
      Case GETOOL_ELLIPSE
        mnuToolItem(9).Checked = True
      
      Case GETOOL_LINE
        mnuToolItem(11).Checked = True
      Case GETOOL_POLYLINE
        mnuToolItem(12).Checked = True
      Case GETOOL_SMARTLINE
        mnuToolItem(13).Checked = True
      
      Case GETOOL_POLYGON
        mnuToolItem(15).Checked = True
      Case GETOOL_RECTANGLE
        mnuToolItem(16).Checked = True
      Case GETOOL_ROUNDRECT
        mnuToolItem(17).Checked = True
      Case GETOOL_OPENBEZIER
        mnuToolItem(19).Checked = True
      Case GETOOL_TEXT
        mnuToolItem(21).Checked = True
      Case GETOOL_TEXTBOX
        mnuToolItem(22).Checked = True
      Case GETOOL_FIELD
        mnuToolItem(23).Checked = True
      Case GETOOL_CONNECTION
        mnuToolItem(25).Checked = True
      Case GETOOL_REFERENCEPOINT
        mnuToolItem(26).Checked = True
    
      Case GETOOL_CONNECTLINE
        mnuToolItem(28).Checked = True
      Case GETOOL_CONNECTPOLYLINE
        mnuToolItem(29).Checked = True
      Case GETOOL_CONNECTSMARTLINE
        mnuToolItem(30).Checked = True
      
      Case GETOOL_DIMENSIONLINE
        mnuToolItem(31).Checked = True
    
    
    End Select
  End If
End Sub
'------------------------------
Private Sub mnuToolItem_Click(index As Integer)
  On Error Resume Next
  mnuArcToolItem(0).Checked = False
  mnuArcToolItem(1).Checked = False
  mnuArcToolItem(2).Checked = False
  mnuPieToolItem(0).Checked = False
  mnuPieToolItem(1).Checked = False
  mnuPieToolItem(2).Checked = False
  mnuCircleToolItem(0).Checked = False
  mnuCircleToolItem(1).Checked = False
  mnuChordToolItem(0).Checked = False
  mnuChordToolItem(1).Checked = False
  mnuChordToolItem(2).Checked = False
  
  Select Case index
    Case 5  ' arc - submenu - do not want to update toolbar at this point
        Select Case m_GeCtrl.Tool
          Case GETOOL_ARC
              mnuArcToolItem(0).Checked = True
          Case GETOOL_ARCDIAMETER
              mnuArcToolItem(1).Checked = True
          Case GETOOL_ARCCENTERRADIUS
              mnuArcToolItem(2).Checked = True
        End Select
      Exit Sub
    Case 6  ' pie - submenu
        Select Case m_GeCtrl.Tool
          Case GETOOL_PIE
              mnuPieToolItem(0).Checked = True
          Case GETOOL_PIEDIAMETER
              mnuPieToolItem(1).Checked = True
          Case GETOOL_PIECENTERRADIUS
              mnuPieToolItem(2).Checked = True
        End Select
      Exit Sub
    Case 7  ' circle - submenu
        Select Case m_GeCtrl.Tool
          Case GETOOL_CIRCLEDIAMETER
              mnuCircleToolItem(0).Checked = True
          Case GETOOL_CIRCLECENTERRADIUS
              mnuCircleToolItem(1).Checked = True
        End Select
      Exit Sub
    Case 8  ' chord - submenu
        Select Case m_GeCtrl.Tool
          Case GETOOL_CHORD
              mnuChordToolItem(0).Checked = True
          Case GETOOL_CHORDDIAMETER
              mnuChordToolItem(1).Checked = True
          Case GETOOL_CHORDCENTERRADIUS
              mnuChordToolItem(2).Checked = True
        End Select
      Exit Sub
    
    Case 0
      m_GeCtrl.Tool = GETOOL_SELECT
      If m_GeCtrl.SelectMoveOnly Then m_GeCtrl.SelectMoveOnly = False
    Case 1
      m_GeCtrl.SelectMoveOnly = Not m_GeCtrl.SelectMoveOnly
    Case 2
      m_GeCtrl.Tool = GETOOL_PICK
    Case 3
      m_GeCtrl.MoveCopy
    Case 9
      m_GeCtrl.Tool = GETOOL_ELLIPSE
    
    Case 11
      m_GeCtrl.Tool = GETOOL_LINE
    Case 12
      m_GeCtrl.Tool = GETOOL_POLYLINE
    Case 13
      m_GeCtrl.Tool = GETOOL_SMARTLINE
    
    
    Case 15
      m_GeCtrl.Tool = GETOOL_POLYGON
    Case 16
      m_GeCtrl.Tool = GETOOL_RECTANGLE
    Case 17
      m_GeCtrl.Tool = GETOOL_ROUNDRECT

    Case 19
      m_GeCtrl.Tool = GETOOL_OPENBEZIER
    
    Case 21
      m_GeCtrl.Tool = GETOOL_TEXT
    Case 22
      m_GeCtrl.Tool = GETOOL_TEXTBOX
    Case 23
      m_GeCtrl.Tool = GETOOL_FIELD
    Case 25
      ' force show connections to be true
      If Not m_GeCtrl.DrawConnections Then m_GeCtrl.DrawConnections = True
      m_GeCtrl.Tool = GETOOL_CONNECTION
    Case 26
      ' force show connections to be true
      If Not m_GeCtrl.DrawConnections Then m_GeCtrl.DrawConnections = True
      m_GeCtrl.Tool = GETOOL_REFERENCEPOINT
  
    Case 28
      m_GeCtrl.Tool = GETOOL_CONNECTLINE
    Case 29
      m_GeCtrl.Tool = GETOOL_CONNECTPOLYLINE
    Case 30
      m_GeCtrl.Tool = GETOOL_CONNECTSMARTLINE
  
    Case 31
      m_GeCtrl.Tool = GETOOL_DIMENSIONLINE
  
  
  End Select
  m_nCurTool = m_GeCtrl.Tool
  m_ucToolBar.UpdateToolbarButtons
  m_ucToolPanel.UpdateToolButtons
End Sub


'------------------------------
Private Sub mnuArcTool_Click()
  Dim i As Integer
  ' enable All tool items
  For i = 0 To mnuArcToolItem.UBound() Step 1
    ' if a Separator, skip it.
    If Not mnuArcToolItem(i).Caption = "-" Then
      mnuArcToolItem(i).Enabled = True
      mnuArcToolItem(i).Checked = False
    End If
  Next i
'  Select Case m_GeCtrl.Tool
'    Case GETOOL_ARC
'        mnuArcToolItem(0).Checked = True
'    Case GETOOL_ARCDIAMETER
'        mnuArcToolItem(1).Checked = True
'    Case GETOOL_ARCCENTERRADIUS
'        mnuArcToolItem(2).Checked = True
'  End Select
End Sub
'------------------------------
Private Sub mnuArcToolItem_Click(index As Integer)
  Select Case index
    Case 0
      m_GeCtrl.Tool = GETOOL_ARC
    Case 1
      m_GeCtrl.Tool = GETOOL_ARCDIAMETER
    Case 2
      m_GeCtrl.Tool = GETOOL_ARCCENTERRADIUS
  End Select
  m_nCurTool = m_GeCtrl.Tool
  mnuArcTool_Click
  m_ucToolPanel.UpdateToolButtons
  m_ucToolBar.UpdateToolbarButtons
End Sub

'------------------------------
Private Sub mnuPieTool_Click()
  Dim i As Integer
  ' enable All tool items
  For i = 0 To mnuPieToolItem.UBound() Step 1
    ' if a Separator, skip it.
    If Not mnuPieToolItem(i).Caption = "-" Then
      mnuPieToolItem(i).Enabled = True
      mnuPieToolItem(i).Checked = False
    End If
  Next i
'  Select Case m_GeCtrl.Tool
'    Case GETOOL_PIE
'        mnuPieToolItem(0).Checked = True
'    Case GETOOL_PIEDIAMETER
'        mnuPieToolItem(1).Checked = True
'    Case GETOOL_PIECENTERRADIUS
'        mnuPieToolItem(2).Checked = True
'  End Select
End Sub

'------------------------------
Private Sub mnuPieToolItem_Click(index As Integer)
  Select Case index
    Case 0
      m_GeCtrl.Tool = GETOOL_PIE
    Case 1
      m_GeCtrl.Tool = GETOOL_PIEDIAMETER
    Case 2
      m_GeCtrl.Tool = GETOOL_PIECENTERRADIUS
  End Select
  m_nCurTool = m_GeCtrl.Tool
  mnuPieTool_Click
'  m_ucToolPanel.UpdateToolButtons
  m_ucToolBar.UpdateToolbarButtons
End Sub

'------------------------------
Private Sub mnuCircleTool_Click()
  Dim i As Integer
  ' enable All tool items
  For i = 0 To mnuCircleToolItem.UBound() Step 1
    ' if a Separator, skip it.
    If Not mnuCircleToolItem(i).Caption = "-" Then
      mnuCircleToolItem(i).Enabled = True
      mnuCircleToolItem(i).Checked = False
    End If
  Next i
'  Select Case m_GeCtrl.Tool
'    Case GETOOL_CIRCLEDIAMETER
'        mnuCircleToolItem(0).Checked = True
'    Case GETOOL_CIRCLECENTERRADIUS
'        mnuCircleToolItem(1).Checked = True
'  End Select
End Sub
'------------------------------
Private Sub mnuCircleToolItem_Click(index As Integer)
  Select Case index
    Case 0
      m_GeCtrl.Tool = GETOOL_CIRCLEDIAMETER
    Case 1
      m_GeCtrl.Tool = GETOOL_CIRCLECENTERRADIUS
  End Select
  m_nCurTool = m_GeCtrl.Tool
  mnuCircleTool_Click
'  m_ucToolPanel.UpdateToolButtons
  m_ucToolBar.UpdateToolbarButtons
End Sub

'------------------------------
Private Sub mnuChordTool_Click()
  Dim i As Integer
  ' enable All tool items
  For i = 0 To mnuChordToolItem.UBound() Step 1
    ' if a Separator, skip it.
    If Not mnuChordToolItem(i).Caption = "-" Then
      mnuChordToolItem(i).Enabled = True
      mnuChordToolItem(i).Checked = False
    End If
  Next i
'  Select Case m_GeCtrl.Tool
'    Case GETOOL_CHORD
'        mnuChordToolItem(0).Checked = True
'    Case GETOOL_CHORDDIAMETER
'        mnuChordToolItem(1).Checked = True
'    Case GETOOL_CHORDCENTERRADIUS
'        mnuChordToolItem(2).Checked = True
'  End Select
End Sub

'------------------------------
Private Sub mnuChordToolItem_Click(index As Integer)
  Select Case index
    Case 0
      m_GeCtrl.Tool = GETOOL_CHORD
    Case 1
      m_GeCtrl.Tool = GETOOL_CHORDDIAMETER
    Case 2
      m_GeCtrl.Tool = GETOOL_CHORDCENTERRADIUS
  End Select
  m_nCurTool = m_GeCtrl.Tool
  mnuChordTool_Click
'  m_ucToolPanel.UpdateToolButtons
  m_ucToolBar.UpdateToolbarButtons
End Sub


'========================
' ARRANGE
'========================
'------------------------------
Private Sub mnuArrange_Click()
  Dim bSel As Boolean
  On Error Resume Next
  
  mnuArrangeItem(0).Enabled = m_GeCtrl.CanGroup
  ' do not allow ungroup if its a smartShape
  If Not m_GeCtrl.CanExplodeSmartShape Then
    mnuArrangeItem(1).Enabled = m_GeCtrl.CanUngroup
  Else
    mnuArrangeItem(1).Enabled = False
  End If
  
  bSel = m_GeCtrl.CanCopy
  mnuArrangeItem(3).Enabled = bSel
  mnuArrangeItem(4).Enabled = bSel
  mnuArrangeItem(5).Enabled = bSel
  mnuArrangeItem(6).Enabled = bSel
  mnuArrangeItem(8).Enabled = bSel
  mnuArrangeItem(9).Enabled = bSel
  mnuArrangeItem(11).Enabled = bSel
  mnuArrangeItem(12).Enabled = bSel

End Sub
'------------------------------
Private Sub mnuArrangeItem_Click(index As Integer)
  On Error Resume Next
  
  m_bDeferObjHit = True ' set this so Menus on dialogs are enabled as call stack gets screwed up if Ge has a hit
  Select Case index
    Case 0
      m_GeCtrl.Group
    Case 1
      m_GeCtrl.Ungroup
'   case 2  ' sep
    Case 3
      m_GeCtrl.MoveToFront
    Case 4
      m_GeCtrl.MoveToBack
    Case 5
      m_GeCtrl.MoveForward
    Case 6
      m_GeCtrl.MoveBackward
'   case 7  ' sep
    Case 8
      m_GeCtrl.FlipHorizontal
    Case 9
      m_GeCtrl.FlipVertical
'   case 10  ' sep
    Case 11
      m_GeCtrl.RotateLeft
    Case 12
      m_GeCtrl.RotateRight

'   case 18  ' sep
'    Case 19
'      m_GeCtrl.OnInsertUserGroup
  End Select
  m_bDeferObjHit = False
End Sub



'========================
' SHAPE
'========================
'------------------------------
Private Sub mnuShape_Click()
  Dim bSel As Boolean
  On Error Resume Next
  bSel = m_GeCtrl.CanCopy
  mnuShapeItem(0).Enabled = bSel  ' create
  mnuShapeItem(1).Enabled = bSel  ' create Smart
  
  mnuShapeItem(5).Enabled = m_GeCtrl.CanExplodeShape  ' explode
  mnuShapeItem(6).Enabled = m_GeCtrl.CanExplodeSmartShape  ' explode

  mnuShapeItem(8).Enabled = m_GeCtrl.CanLocateShape
End Sub

'------------------------------
Private Sub mnuShapeItem_Click(index As Integer)

  On Error Resume Next
  m_bDeferObjHit = True ' set this so Menus on dialogs are enabled as call stack gets screwed up if Ge has a hit
  
  Select Case index
    Case 0
      m_bCreatingSmartShape = False
      m_GeCtrl.TreatShapesAsUserGroups = False
      m_GeCtrl.OnCreateShape
      
    Case 1  ' Smart Shape
      m_bCreatingSmartShape = True
      m_GeCtrl.TreatShapesAsUserGroups = True
      m_GeCtrl.OnCreateShape
    Case 3
      m_GeCtrl.OnInsertShape
    Case 5
      m_GeCtrl.OnExplodeShape
    Case 6  ' explode smartShape
      m_GeCtrl.Ungroup
    
    Case 8
      m_GeCtrl.LocateShape
  
    Case 10
     'm_GeCtrl.OnLibraryManager            'MEG: changed to use new function for auto shape generation
      ShapeManager       ' Manage Library(s)
  
  End Select
  '
  m_bDeferObjHit = False
  ShowAnyPostModalStatusMsgs
  
End Sub

'--------------------------
Private Sub DoMangeShapeAndObjects()
  ' bring up the dialog
  Dim frm As frmUDItemDefs
  Dim FileName As String
  Dim strUMLProj As String
  
'  On Error Resume Next
  Set frm = New frmUDItemDefs
  frm.LibraryName = GetFirstAttachedLibrary
  Set frm.UDIDefMgr = m_DwgEditor.UDIDefMgr
  Set frm.ucToolPanel = m_ucToolPanel
  frm.Show vbModal
  Set frm = Nothing
  
  'In case the user chose a UML project, update the status bar
  strUMLProj = GetUMLProjectName()
  If strUMLProj <> "" Then SetUMLProjectText (strUMLProj)
  If Not m_GeCtrl Is Nothing Then m_GeCtrl.SelRemoveAll
End Sub
'--------------------------
Public Function GetFirstAttachedLibrary() As String
  ' 1st library attached to CG
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim i As Integer
  Dim strLibPath As String
  Dim aLibraries As Variant

'  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Function
  
  m_GeCtrl.GetAttachedLibraries aLibraries
  If err <> 0 Then
    ' nothing there
    err = 0
    Exit Function
  End If
  
  uBnd = UBound(aLibraries)
  lBnd = LBound(aLibraries)
  If err <> 0 Or uBnd = -1 Then
    err = 0     ' nothing there
    Exit Function
  End If
  ' get first library in list
  strLibPath = aLibraries(lBnd)
  GetFirstAttachedLibrary = strLibPath
  
End Function




' called from toolpanel
'---------------------------
Public Sub SetShapeData(Library As String, Folder As String, Shape As String)
  ' set the data here, don't display it
  m_strLibrary = Library
  m_strFolder = Folder
  m_strShape = Shape
End Sub


'Public Sub AdviseToolPanelOfChange()
'  m_ucToolPanel.GetAttachedLibraries
'End Sub

'========================
' SETTINGS
'========================
'------------------------------
Private Sub mnuSettings_Click()
  On Error Resume Next

  mnuSettingsItem(0).Checked = m_GeCtrl.Grid
  mnuSettingsItem(1).Checked = m_GeCtrl.Snap
  mnuSettingsItem(2).Checked = m_GeCtrl.VertexMode

  mnuSettingsItem(8).Checked = m_GeCtrl.DrawFieldBox
  mnuSettingsItem(9).Checked = m_GeCtrl.DrawFieldTag
  
  ' Show Connections/Reference points
  mnuSettingsItem(10).Checked = m_GeCtrl.DrawConnections
  
  mnuSettingsItem(11).Checked = m_GeCtrl.DrawInsertionPoints
  mnuSettingsItem(12).Checked = m_GeCtrl.DrawFilledTransparent

  mnuSettingsItem(14).Checked = m_GeCtrl.ConnectionMode
  
  mnuSettingsItem(16).Checked = m_GeCtrl.SnapShapesToCursor
  mnuSettingsItem(17).Checked = m_GeCtrl.SnapToSelection


End Sub


'------------------------------
Private Sub mnuSettingsItem_Click(index As Integer)
  Dim nVal As Integer
  
  On Error Resume Next
  m_bDeferObjHit = True ' set this so Menus on dialogs are enabled as call stack gets screwed up if Ge has a hit
  Select Case index
    Case 0  ' Grid
      m_GeCtrl.Grid = Not (mnuSettingsItem(index).Checked)
'      m_ucToolPanel.UpdateToolButtons
      m_ucToolBar.UpdateToolbarButtons
    Case 1  ' Snap
      m_GeCtrl.Snap = Not (mnuSettingsItem(index).Checked)
      m_ucToolPanel.UpdateToolButtons
      m_ucToolBar.UpdateToolbarButtons
    Case 2  ' Vertex
      m_GeCtrl.VertexMode = Not (mnuSettingsItem(index).Checked)
'      m_ucToolPanel.UpdateToolButtons
      m_ucToolBar.UpdateToolbarButtons
      
    Case 4  ' Object Properties
      m_GeCtrl.DoObjectDialog
    Case 5  ' Sheet Properties
      m_GeCtrl.DoViewDialog
    Case 6  ' Palette Properties
      m_GeCtrl.DoPaletteDialog
      ' in case palette was changed
      m_ucToolPanel.GetGeColors
    Case 8  ' FieldBox
      m_GeCtrl.DrawFieldBox = Not (mnuSettingsItem(index).Checked)
    Case 9  ' FieldTag
      m_GeCtrl.DrawFieldTag = Not (mnuSettingsItem(index).Checked)
  
    Case 10  ' Show Connections/Reference points
      m_GeCtrl.DrawConnections = Not (mnuSettingsItem(index).Checked)
        ' save to ini
      If m_GeCtrl.DrawConnections = True Then nVal = 1
      AppWriteProfileInt INISECTION_UAO, INIENTRY_SHOWCONNECTIONS, nVal
      If Not m_ucToolPanel Is Nothing Then m_ucToolPanel.UpdateControlsFromGe
    Case 11  ' Show Shape IPs
      m_GeCtrl.DrawInsertionPoints = Not (mnuSettingsItem(index).Checked)
      If Not m_ucToolPanel Is Nothing Then m_ucToolPanel.UpdateControlsFromGe
    Case 12  ' Draw Filled Transparent
      m_GeCtrl.DrawFilledTransparent = Not (mnuSettingsItem(index).Checked)
      If Not m_ucToolPanel Is Nothing Then m_ucToolPanel.UpdateControlsFromGe
    
    Case 14  ' Snap to Connections
      m_GeCtrl.ConnectionMode = Not (mnuSettingsItem(index).Checked)
      If m_GeCtrl.ConnectionMode = True Then nVal = 1
      AppWriteProfileInt INISECTION_UAO, INIENTRY_SNAPTOCONNECTIONS, nVal
      If Not m_ucToolPanel Is Nothing Then m_ucToolPanel.UpdateControlsFromGe
    
    
    Case 16  ' Snap Shape to Cursor
      m_GeCtrl.SnapShapesToCursor = Not (mnuSettingsItem(index).Checked)
      If Not m_ucToolPanel Is Nothing Then m_ucToolPanel.UpdateControlsFromGe
    Case 17
     m_GeCtrl.SnapToSelection = Not (mnuSettingsItem(index).Checked)
     If Not m_ucToolPanel Is Nothing Then m_ucToolPanel.UpdateControlsFromGe

  
  End Select
  m_bDeferObjHit = False

End Sub
 
'========================
' HELP
'========================
'-------------------------------
Private Sub mnuHelpItem_Click(index As Integer)
  On Error Resume Next
  Select Case index
    Case 0
      Dim frmTmp As New frmAbout
      frmTmp.Move 3200, 1200
      frmTmp.Show vbModal
      Set frmTmp = Nothing
      
  End Select
End Sub


'======================================================================================
' Distance Tool and GetPoint Tool
'======================================================================================
'------------------------------
Public Sub DoGetPoint()
  ' get a point from the ocx (set tool to PICKPOINT)
  m_nCurTool = m_GeCtrl.Tool
  m_GeCtrl.Tool = GETOOL_PICKPOINT
End Sub
'------------------------------
Public Sub DoDistanceTool()
  ' draw a Line so can measure a distance
  On Error Resume Next
  m_nCurTool = m_GeCtrl.Tool
  If Not (m_GeCtrl Is Nothing) Then
    m_bDistanceTool = True
    m_GeCtrl.Tool = GETOOL_LINE
    m_GeCtrl.EnableUndo = False ' set so will not add this line to undo buffer
    SetStatusText ""
  End If
End Sub
'------------------------------
Public Function EndCreateObject(nGeID As Long)
  ' notification that an object has been created by GeCtrl
  ' just using this to test distance tool (above)
  If m_bDistanceTool Then
    m_bDeferShowCount = True
    GetDistance nGeID
    m_GeCtrl.Tool = m_nCurTool
  End If
End Function
'------------------------------
Private Function GetDistance(nGeID As Long)
  ' calc and show distance for line of given ID
  Dim aVar As Variant
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim strMsg As String
  Dim i As Integer
  Dim dX As Double
  Dim dy As Double
  Dim dLen As Double
  
  On Error Resume Next
    
  m_GeCtrl.CurrentPropertyID = nGeID  ' move into selector
  m_GeCtrl.GetVerticies aVar          ' get vertices
  m_GeCtrl.CurrentPropertyID = 0      ' reset selector
  If err = 0 Then
    uBnd = UBound(aVar)
    lBnd = LBound(aVar)
    If (uBnd - lBnd) = 1 Then
      dX = aVar(uBnd, 0) - aVar(lBnd, 0)
      dy = aVar(uBnd, 1) - aVar(lBnd, 1)
      ' calc length
      If Not (dX = 0# And dy = 0#) Then
        dLen = Sqr((dX * dX) + (dy * dy))
      End If
      strMsg = "dx: " & Format(dX, "0.0000") & _
            " dy: " & Format(dy, "0.0000") & _
            " Length: " & Format(dLen, "0.0000")
      SetStatusText strMsg
    End If
  End If
    ' delete it
  m_GeCtrl.EnableUndo = False ' set so will not add this line to undo buffer
  m_bDeferShowCount = True
  m_GeCtrl.SelRemoveAll
  m_bDeferShowCount = True
  m_GeCtrl.SelAdd nGeID
  m_bDeferShowCount = True
  m_GeCtrl.Delete
  m_GeCtrl.EnableUndo = True ' set so will keep on going
  ''
  m_GeCtrl.Tool = m_nCurTool
  m_ucToolPanel.UpdateToolButtons
  m_ucToolBar.UpdateToolbarButtons
  m_bDistanceTool = False
End Function

'-------------------------
Public Sub UpdateToolPanelButtons()
  ' callback from toolbar to here. pass it on to toolpanel
  If Not m_ucToolPanel Is Nothing Then m_ucToolPanel.UpdateToolButtons
End Sub
'-------------------------
Public Sub UpdateToolbarButtons()
  ' callback from toolbar to here. pass it on to toolpanel
  If Not m_ucToolBar Is Nothing Then m_ucToolBar.UpdateToolbarButtons
End Sub

'-------------------------
Public Function ToolBarClick(index As Integer, Value As Integer)
  ' called from toolbox in ucToolPanel
  On Error Resume Next
  Select Case index
    Case 0    'open
      DoDwgFileOpen
    Case 1    'save
      DoDwgFileSave
    End Select
End Function

'==================================================================
' Recent Files
'==================================================================
Private Function GetMostRecentFile() As String
  Dim strName As String
  On Error Resume Next
  strName = ""
  If mnuRecentFile(1).Visible Then
    strName = mnuRecentFile(1).Caption
  End If
  GetMostRecentFile = strName
End Function
'-------------------------------------------
Private Sub UpdateFileMenu(FileName As String)
  On Error Resume Next
  WriteRecentFiles FileName
  GetRecentFiles
End Sub
'-------------------------------------------
Public Sub GetRecentFiles()
  ' update menu with recent files
  Dim strVal As String
  Dim strKey As String
  Dim i As Integer
  Dim nMnu As Integer
  
  On Error Resume Next
  For i = 1 To mnuRecentFile.UBound()
    mnuRecentFile(i).Caption = ""
    mnuRecentFile(i).Visible = False
  Next i
  nMnu = 1
  For i = 1 To mnuRecentFile.UBound()
    strKey = INIENTRY_RECENTFILE & i
    strVal = ""
    strVal = AppGetProfileString(INISECTION_GEEDITOR, strKey, strVal)
    If Len(strVal) > 0 Then
'      If FileExists(strVal) Then
        mnuRecentFile(0).Visible = True     ' separator
        mnuRecentFile(nMnu).Caption = strVal
        mnuRecentFile(nMnu).Visible = True
        nMnu = nMnu + 1
'      Else
'        ' empty it if can't find it
'        strVal = ""
'        AppWriteProfileString INISECTION_GEEDITOR, strKey, strVal
'      End If
    End If
  Next i
End Sub
'-------------------------------------------
Public Sub RemoveRecentFileEntry(strRemove As String)
  ' find and remove from INI
  Dim strVal As String
  Dim strKey As String
  Dim i As Integer
  Dim nMnu As Integer
  
  On Error Resume Next
  For i = 1 To mnuRecentFile.UBound()
    strKey = INIENTRY_RECENTFILE & i
    strVal = ""
    strVal = AppGetProfileString(INISECTION_GEEDITOR, strKey, strVal)
    If Len(strVal) > 0 Then
      If UCase(strRemove) = UCase(strVal) Then
        AppWriteProfileString INISECTION_GEEDITOR, strKey, ""
      End If
    End If
  Next i
End Sub

'-------------------------------------------
Private Sub WriteRecentFiles(OpenFileName As String)
  Dim uBnd As Integer
  On Error Resume Next
  uBnd = mnuRecentFile.UBound()  ' 5 initially
    ' call global function
  DoWriteRecentFiles OpenFileName, INISECTION_GEEDITOR, uBnd
  
End Sub



'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' FRom MDI form
'======================================================================================
'  STATUS BAR
'======================================================================================
'------------------------------
Public Property Get ToolbarVisible() As Boolean
  ToolbarVisible = ucToolBar1.Visible
End Property
'------------------------------
Public Property Let ToolbarVisible(ByVal bShow As Boolean)
  ucToolBar1.Visible = bShow
  UserControl_Resize    ' force resize
End Property

'------------------------------
Public Property Let Show2Toolbars(ByVal bShow As Boolean)
  ' show 1 or 2
  If bShow Then
    ucToolBar1.ToolBarRows = 2
  Else
    ucToolBar1.ToolBarRows = 1
  End If
  UserControl_Resize    ' force resize
  
End Property
'------------------------------
Public Property Get Show2Toolbars() As Boolean
  Show2Toolbars = IIf(ucToolBar1.ToolBarRows = 2, True, False)
End Property
'------------------------------
Public Property Let ToolPanelAlignLeft(ByVal bLeft As Boolean)
  ' align left/right
  If bLeft Then picToolpanel.Align = vbAlignLeft Else picToolpanel.Align = vbAlignRight
  ucToolPanel.SetOnLeftSide IIf(picToolpanel.Align = vbAlignLeft, True, False)
  UserControl_Resize    ' force resize
  
End Property
'------------------------------
Public Property Get ToolPanelAlignLeft() As Boolean
  ToolPanelAlignLeft = IIf(picToolpanel.Align = vbAlignLeft, True, False)
End Property

'------------------------------
Public Property Get ToolPanelVisible() As Boolean
  ToolPanelVisible = picToolpanel.Visible
End Property
'------------------------------
Public Property Let ToolPanelVisible(ByVal bShow As Boolean)
  ' show/hide ToolPanel
  If bShow Then
    picToolpanel.Visible = True
  Else
    picToolpanel.Visible = False
  End If
  UserControl_Resize    ' force resize
  
End Property

'------------------------------
Public Function ShowStatusbar()
  ' Show/Hide main Statusbar
  If StatusBar.Visible = True Then
    StatusBar.Visible = False
  Else
    StatusBar.Visible = True
  End If
  UserControl_Resize
  
End Function
'------------------------------
Public Property Get StatusbarVisible() As Boolean
  StatusbarVisible = StatusBar.Visible
End Property

'------------------------------
Public Sub SetStatusText(ByVal szMsg As String)
  pnlStsText.Caption = " " & szMsg
  DoEvents
End Sub
'------------------------------
Public Sub SetObjectStatusText(ByVal szMsg As String)
  pnlObjText.Caption = " " & szMsg
End Sub

Public Sub SetUMLProjectText(ByVal szMsg As String)
    pnlUMLProject.Caption = " " & szMsg
End Sub

'------------------------------
Public Sub UpdateSelDimension(ByVal posX As Double, ByVal posY As Double, Optional ByVal bShowSize As Boolean = True)
  ' update Width/Height. If both are 0, clear panel's text
  Dim MsgStr As String
  Dim strFmt As String
  
  On Error Resume Next
  '
  If bShowSize And (posX = 0) And (posY = 0) Then
    pnlDimensions.Caption = "Width:          Height:"
    Exit Sub
  End If
  '
  strFmt = "#########0.00000"
  If Abs(posX) > 10000 Or Abs(posY) > 10000 Then strFmt = "########0.0"
  If bShowSize Then
    MsgStr = "Width:" & Format(posX, strFmt) & "  Height:" & Format(posY, strFmt)
  Else
    ' dx/dy
    MsgStr = "DX : " & Format(posX, strFmt) & "     DY : " & Format(posY, strFmt)
  End If
  pnlDimensions.Caption = MsgStr
End Sub

'------------------------------
Public Sub ShowCursorPos(ByVal posX As Double, ByVal posY As Double)
  ' update Cursor position Panel on the status bar
  Dim MsgStr As String
  Dim strFmt As String
  On Error Resume Next
  strFmt = "#########0.0000"
  If Abs(posX) > 10000# Or Abs(posY) > 10000# Then strFmt = "########0.0"
  MsgStr = Format(posX, strFmt) & ", " & Format(posY, strFmt)
  pnlCursorPos.Caption = MsgStr

  ucToolPanel.UpdateCursorPos posX, posY
End Sub


'------------------------------
Private Sub StatusBar_Resize()
  ' must check for -ve value, which happens if
  ' the MDIChild is maximized and the MDIParent is then Minimized
  Dim newWidth As Long
  Dim wBtn As Long
    
  On Error Resume Next
  newWidth = StatusBar.Width - pnlCursorPos.Width - pnlDimensions.Width - pnlObjText.Width - pnlUMLProject.Width - btnStatusMessages.Width - btnMessagesClear.Width
  
  If newWidth > 0 Then
    pnlDimensions.Move pnlUMLProject.Width
    pnlObjText.Move pnlUMLProject.Width + pnlDimensions.Width
    pnlStsText.Move pnlUMLProject.Width + pnlDimensions.Width + pnlObjText.Width
    pnlStsText.Width = newWidth
    pnlCursorPos.Move StatusBar.Width - pnlCursorPos.Width - btnStatusMessages.Width - btnMessagesClear.Width
    btnStatusMessages.Move StatusBar.Width - btnStatusMessages.Width - btnMessagesClear.Width
    btnMessagesClear.Move StatusBar.Width - btnMessagesClear.Width
  End If
    
  ucMessageWindow.Width = StatusBar.Width
End Sub

Public Function SizeStatusBar(X As Single, Y As Single) As Boolean
    Dim newHeight, newPos As Integer
    
    SizeStatusBar = True
    If StatusBar Is Nothing Then Exit Function
    newHeight = ucMessageWindow.Height + Y * (-1)
    If newHeight >= 0 Then
      StatusBar.Height = StatusBar.Height + Y * (-1)
      If (Ge1.Height + Y) < 0 Then
        Ge1.Height = 0
      Else
        Ge1.Height = Ge1.Height + Y
      End If
      ucMessageWindow.Height = newHeight
  '    ucMessageWindow.SizeMsgWindow newHeight
      newPos = ucMessageWindow.Height + 40
      pnlStsText.Top = newPos
      pnlObjText.Top = newPos
      pnlCursorPos.Top = newPos
      btnStatusMessages.Top = newPos
      btnMessagesClear.Top = newPos
      pnlDimensions.Top = newPos
      pnlCursorPos.Top = newPos
      pnlUMLProject.Top = newPos
      StatusBar.Refresh
      UserControl.Refresh
 '     Ge1.Redraw
    Else
        SizeStatusBar = False
    End If
    
End Function

Private Sub HideMessageWindow()
    On Error Resume Next
    Dim newHeight, newPos As Integer

    ucMessageWindow.Visible = False
    StatusBar.Height = StatusBar.Height - ucMessageWindow.Height + 30  'adjust by to for ucMessageWIndow
    If (Ge1.Height + ucMessageWindow.Height - 30) < 0 Then
      Ge1.Height = 0
    Else
      Ge1.Height = Ge1.Height + ucMessageWindow.Height - 30
    End If
    ucMessageWindow.Height = 30           'This is the smallest settable height
    newPos = ucMessageWindow.Height + 40
    pnlStsText.Top = newPos
    pnlObjText.Top = newPos
    pnlCursorPos.Top = newPos
    btnStatusMessages.Top = newPos
    btnMessagesClear.Top = newPos
    pnlDimensions.Top = newPos
    pnlCursorPos.Top = newPos
    pnlUMLProject.Top = newPos
    StatusBar.Refresh
    UserControl.Refresh
     m_bMsgVisible = False
End Sub

Public Sub ShowMessageWindow()
    ucMessageWindow.Visible = True
    SizeStatusBar 0, -2000
    ucMessageWindow.MaximizeMessageWindow ucMessageWindow.Height, ucMessageWindow.Width
    m_bMsgVisible = True
End Sub

'Log a message in the message window
Public Sub LogMessage(strMsg As String)
    UserControl.ucMessageWindow.LogMessage strMsg
End Sub

Public Function IsMsgWindowVisible() As Boolean
    If m_bMsgVisible = True Then
        IsMsgWindowVisible = True
    Else
        IsMsgWindowVisible = False
    End If
End Function

'Added for auto shape generation functionality
Private Sub ShapeManager()
  ' manage libraries
  Dim frmMgr As frmShapeLibMgr
  
  On Error Resume Next
  Set frmMgr = New frmShapeLibMgr
  
  ' get current and pass to form
  Dim aLibraries As Variant
  m_GeCtrl.GetAttachedLibraries aLibraries
  frmMgr.ListAttachedLibraries aLibraries
  '
  frmMgr.Show vbModal
  Set frmMgr = Nothing
  ' refresh attached libs
  m_ucToolPanel.GetAttachedLibraries
  
End Sub

