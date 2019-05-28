VERSION 5.00
Object = "{C5DE3F80-3376-11D2-BAA4-04F205C10000}#1.0#0"; "Vsflex6d.ocx"
Object = "{E6F77CB3-6A30-11D5-89E6-00D0B74A80C3}#1.0#0"; "CGCtrl.ocx"
Object = "{8DB9CFCE-3627-11D4-899F-00D0B74A80C3}#2.4#0"; "ABBCAToolbar.ocx"
Begin VB.UserControl ucToolPanel 
   Appearance      =   0  'Flat
   BackColor       =   &H80000004&
   ClientHeight    =   8760
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   15360
   ControlContainer=   -1  'True
   FillColor       =   &H00FFFFFF&
   ForwardFocus    =   -1  'True
   KeyPreview      =   -1  'True
   ScaleHeight     =   8760
   ScaleWidth      =   15360
   Begin VB.PictureBox ucPanelA 
      Height          =   4890
      Index           =   15
      Left            =   10935
      ScaleHeight     =   4830
      ScaleWidth      =   1950
      TabIndex        =   161
      Top             =   3570
      Width           =   2010
      Begin VB.CommandButton btnEnumConnections 
         Caption         =   "Get all Connections"
         Height          =   255
         Left            =   90
         TabIndex        =   203
         ToolTipText     =   "Enumerate all connections"
         Top             =   3990
         Width           =   1785
      End
      Begin VB.TextBox txtConBSts 
         Height          =   285
         Left            =   510
         TabIndex        =   196
         Top             =   3480
         Width           =   900
      End
      Begin VB.TextBox txtConBType 
         Height          =   285
         Left            =   510
         TabIndex        =   195
         Top             =   3165
         Width           =   585
      End
      Begin VB.TextBox txtConBName 
         Height          =   285
         Left            =   510
         TabIndex        =   194
         Top             =   2850
         Width           =   1350
      End
      Begin VB.TextBox txtConBID 
         Height          =   285
         Left            =   510
         TabIndex        =   193
         Top             =   2535
         Width           =   585
      End
      Begin VB.TextBox txtConASts 
         Height          =   285
         Left            =   510
         TabIndex        =   192
         Top             =   1905
         Width           =   900
      End
      Begin VB.TextBox txtConAType 
         Height          =   285
         Left            =   510
         TabIndex        =   191
         Top             =   1545
         Width           =   585
      End
      Begin VB.TextBox txtConAName 
         Height          =   285
         Left            =   510
         TabIndex        =   190
         Top             =   1230
         Width           =   1335
      End
      Begin VB.TextBox txtConAID 
         Height          =   285
         Left            =   510
         TabIndex        =   189
         Top             =   915
         Width           =   585
      End
      Begin VB.TextBox txtLineID 
         Height          =   285
         Left            =   720
         TabIndex        =   177
         Top             =   285
         Width           =   585
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "ConB"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Index           =   14
         Left            =   165
         TabIndex        =   198
         Top             =   2265
         Width           =   465
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "ConA"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Index           =   10
         Left            =   135
         TabIndex        =   197
         Top             =   630
         Width           =   465
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Sts"
         Height          =   210
         Index           =   20
         Left            =   30
         TabIndex        =   188
         Top             =   3480
         Width           =   375
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Type"
         Height          =   210
         Index           =   19
         Left            =   30
         TabIndex        =   187
         Top             =   3120
         Width           =   420
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Name"
         Height          =   210
         Index           =   18
         Left            =   30
         TabIndex        =   186
         Top             =   2850
         Width           =   420
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "ID"
         Height          =   210
         Index           =   9
         Left            =   165
         TabIndex        =   185
         Top             =   2535
         Width           =   285
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Sts"
         Height          =   210
         Index           =   16
         Left            =   45
         TabIndex        =   184
         Top             =   1935
         Width           =   375
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Type"
         Height          =   210
         Index           =   13
         Left            =   45
         TabIndex        =   183
         Top             =   1575
         Width           =   420
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Name"
         Height          =   210
         Index           =   12
         Left            =   45
         TabIndex        =   182
         Top             =   1305
         Width           =   420
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "ID"
         Height          =   210
         Index           =   11
         Left            =   180
         TabIndex        =   181
         Top             =   990
         Width           =   285
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Event:"
         Height          =   165
         Index           =   17
         Left            =   45
         TabIndex        =   180
         Top             =   15
         Width           =   465
      End
      Begin VB.Label lblEvent 
         Caption         =   "?"
         Height          =   210
         Left            =   540
         TabIndex        =   179
         Top             =   30
         Width           =   1350
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "LineID"
         Height          =   210
         Index           =   15
         Left            =   180
         TabIndex        =   178
         Top             =   330
         Width           =   465
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   3105
      Index           =   13
      Left            =   4710
      ScaleHeight     =   3045
      ScaleWidth      =   1935
      TabIndex        =   162
      Top             =   5490
      Width           =   1995
      Begin VB.CommandButton btnMove 
         Height          =   285
         Index           =   6
         Left            =   1440
         Picture         =   "ucToolPanelB.ctx":0000
         Style           =   1  'Graphical
         TabIndex        =   137
         ToolTipText     =   "Move Insertion Point of a shape to point"
         Top             =   1230
         Width           =   285
      End
      Begin VB.CommandButton btnMove 
         Caption         =   "Move By"
         Height          =   255
         Index           =   5
         Left            =   345
         TabIndex        =   136
         ToolTipText     =   "Move selected objects by X,Y"
         Top             =   2760
         Width           =   1125
      End
      Begin VB.CommandButton btnGetIP 
         Height          =   315
         Left            =   1500
         Picture         =   "ucToolPanelB.ctx":0542
         Style           =   1  'Graphical
         TabIndex        =   133
         ToolTipText     =   "Click, position cursor at desired point, click again (Esc to cancel)"
         Top             =   270
         Width           =   315
      End
      Begin VB.CommandButton btnMove 
         Height          =   285
         Index           =   4
         Left            =   690
         Picture         =   "ucToolPanelB.ctx":0644
         Style           =   1  'Graphical
         TabIndex        =   132
         ToolTipText     =   "Move Center of selection to point"
         Top             =   1200
         Width           =   285
      End
      Begin VB.CommandButton btnMove 
         Height          =   285
         Index           =   3
         Left            =   1020
         Picture         =   "ucToolPanelB.ctx":0B86
         Style           =   1  'Graphical
         TabIndex        =   131
         ToolTipText     =   "Move TopRight corner of selection to point"
         Top             =   960
         Width           =   285
      End
      Begin VB.CommandButton btnMove 
         Height          =   285
         Index           =   2
         Left            =   1020
         Picture         =   "ucToolPanelB.ctx":0C88
         Style           =   1  'Graphical
         TabIndex        =   130
         ToolTipText     =   "Move BottomRight corner of selection to point"
         Top             =   1470
         Width           =   285
      End
      Begin VB.CommandButton btnMove 
         Height          =   285
         Index           =   1
         Left            =   360
         Picture         =   "ucToolPanelB.ctx":0D8A
         Style           =   1  'Graphical
         TabIndex        =   129
         ToolTipText     =   "Move TopLeft corner of selection to point"
         Top             =   960
         Width           =   285
      End
      Begin VB.CommandButton btnMove 
         Height          =   285
         Index           =   0
         Left            =   360
         Picture         =   "ucToolPanelB.ctx":0E8C
         Style           =   1  'Graphical
         TabIndex        =   127
         ToolTipText     =   "Move BottomLeft corner of selection to point"
         Top             =   1440
         Width           =   285
      End
      Begin VB.TextBox txtIPY 
         Height          =   255
         Left            =   510
         TabIndex        =   123
         Text            =   "0"
         ToolTipText     =   "Y value of Point to move to / amount to move by "
         Top             =   2460
         Width           =   915
      End
      Begin VB.TextBox txtIPX 
         Height          =   255
         Left            =   510
         TabIndex        =   122
         Text            =   "0"
         ToolTipText     =   "X value of Point to move to / amount to move by "
         Top             =   2175
         Width           =   915
      End
      Begin VB.Label Label24 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Get MoveTo point"
         Height          =   225
         Left            =   150
         TabIndex        =   159
         ToolTipText     =   "Get the point to move the selection to"
         Top             =   330
         Width           =   1305
      End
      Begin VB.Shape Shape1 
         Height          =   915
         Left            =   300
         Top             =   900
         Width           =   1065
      End
      Begin VB.Label Label20 
         AutoSize        =   -1  'True
         Caption         =   "Point to move to"
         Height          =   195
         Left            =   330
         TabIndex        =   134
         Top             =   1950
         Width           =   1155
      End
      Begin VB.Label Label12 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "move selection to point !"
         Height          =   195
         Left            =   120
         TabIndex        =   128
         Top             =   660
         Width           =   1755
      End
      Begin VB.Label Label9 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Move "
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   720
         TabIndex        =   126
         Top             =   30
         Width           =   450
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "Y"
         Height          =   195
         Index           =   6
         Left            =   330
         TabIndex        =   125
         Top             =   2490
         Width           =   105
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "X"
         Height          =   195
         Index           =   5
         Left            =   330
         TabIndex        =   124
         Top             =   2205
         Width           =   105
      End
   End
   Begin VB.PictureBox picPanel 
      BorderStyle     =   0  'None
      Height          =   900
      Left            =   150
      ScaleHeight     =   900
      ScaleWidth      =   2175
      TabIndex        =   75
      Top             =   6570
      Width           =   2175
      Begin ABBCAToolbar.CAToolbar tbToolPanelA 
         Height          =   285
         Left            =   45
         Top             =   30
         Width           =   2100
         _ExtentX        =   3704
         _ExtentY        =   503
         BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ButtonGap       =   1
         BorderStyle     =   1
         BorderLeft      =   0   'False
         BorderTop       =   0   'False
         BorderRight     =   0   'False
         BorderBottom    =   0   'False
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ButtonCount     =   3
         PlaySounds      =   0   'False
         SolidChecked    =   -1  'True
         ShowSeparators  =   -1  'True
         CaptionAlignment=   4
         ButtonCaption1  =   "Snap"
         ButtonKey1      =   "Snap"
         ButtonWidth1    =   45
         ButtonToolTipText1=   "Snap Settings"
         ButtonCaption2  =   "Format"
         ButtonKey2      =   "Format"
         ButtonWidth2    =   45
         ButtonToolTipText2=   "extended align, rotate and scale operations"
         ButtonCaption3  =   "Layers"
         ButtonKey3      =   "Layers"
         ButtonWidth3    =   45
         ButtonToolTipText3=   "Object layer operations"
      End
      Begin ABBCAToolbar.CAToolbar tbToolPanelB 
         Height          =   285
         Left            =   45
         Top             =   300
         Width           =   2100
         _ExtentX        =   3704
         _ExtentY        =   503
         BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ButtonGap       =   1
         BorderStyle     =   1
         BorderLeft      =   0   'False
         BorderTop       =   0   'False
         BorderRight     =   0   'False
         BorderBottom    =   0   'False
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ButtonCount     =   3
         PlaySounds      =   0   'False
         SolidChecked    =   -1  'True
         ShowSeparators  =   -1  'True
         CaptionAlignment=   4
         ButtonCaption1  =   "General"
         ButtonKey1      =   "General"
         ButtonWidth1    =   45
         ButtonToolTipText1=   "Colour and conversion operations"
         ButtonCaption2  =   "Shapes"
         ButtonKey2      =   "Shapes"
         ButtonWidth2    =   45
         ButtonToolTipText2=   "Library Shapes"
         ButtonCaption3  =   "Pref"
         ButtonKey3      =   "Pref"
         ButtonWidth3    =   45
         ButtonToolTipText3=   "Font and general preferences"
      End
      Begin ABBCAToolbar.CAToolbar tbToolPanelC 
         Height          =   285
         Left            =   45
         Top             =   570
         Visible         =   0   'False
         Width           =   2100
         _ExtentX        =   3704
         _ExtentY        =   503
         BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ButtonGap       =   1
         BorderStyle     =   1
         BorderLeft      =   0   'False
         BorderTop       =   0   'False
         BorderRight     =   0   'False
         BorderBottom    =   0   'False
         BackColor       =   12632256
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ButtonCount     =   3
         PlaySounds      =   0   'False
         SolidChecked    =   -1  'True
         ShowSeparators  =   -1  'True
         CaptionAlignment=   4
         ButtonCaption1  =   "Model"
         ButtonKey1      =   "SET1"
         ButtonWidth1    =   45
         ButtonCaption2  =   "Connect"
         ButtonKey2      =   "SET2"
         ButtonWidth2    =   45
         ButtonCaption3  =   "Move"
         ButtonKey3      =   "SET3"
         ButtonWidth3    =   45
         ButtonToolTipText3=   "Extended moving and Array operations"
         ButtonColor3    =   -2147483633
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   1635
      Index           =   1
      Left            =   4275
      ScaleHeight     =   1575
      ScaleWidth      =   1935
      TabIndex        =   163
      Top             =   1770
      Width           =   1995
      Begin VB.CommandButton btnScale 
         Caption         =   "Scale"
         Height          =   255
         Left            =   345
         TabIndex        =   66
         ToolTipText     =   "Scale selected objects"
         Top             =   1335
         Width           =   1305
      End
      Begin VB.TextBox txtWidthNew 
         Height          =   255
         Left            =   1035
         TabIndex        =   65
         Text            =   "0.00"
         Top             =   540
         Width           =   885
      End
      Begin VB.TextBox txtHeightNew 
         Height          =   255
         Left            =   1035
         TabIndex        =   64
         Text            =   "0.00"
         Top             =   810
         Width           =   885
      End
      Begin VB.CheckBox cbAspectRatio 
         Caption         =   "Maintain aspect ratio"
         Height          =   225
         Left            =   45
         TabIndex        =   63
         ToolTipText     =   "If set, the W/H ratio is maintained"
         Top             =   1095
         Width           =   1815
      End
      Begin VB.TextBox txtScale 
         Height          =   255
         Left            =   1035
         TabIndex        =   62
         Text            =   "1.000"
         ToolTipText     =   "Scale W & H by 'X'"
         Top             =   60
         Width           =   885
      End
      Begin VB.Label Label15 
         AutoSize        =   -1  'True
         Caption         =   "Scale"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   225
         TabIndex        =   74
         Top             =   60
         Width           =   405
      End
      Begin VB.Label lblHeightCur 
         Caption         =   "0.00"
         Height          =   180
         Left            =   285
         TabIndex        =   73
         Top             =   855
         Width           =   675
      End
      Begin VB.Label lblWidthCur 
         Caption         =   "0.00"
         Height          =   180
         Left            =   285
         TabIndex        =   72
         Top             =   570
         Width           =   675
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "H"
         Height          =   195
         Index           =   3
         Left            =   75
         TabIndex        =   71
         Top             =   855
         Width           =   120
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "W"
         Height          =   195
         Index           =   1
         Left            =   75
         TabIndex        =   70
         Top             =   570
         Width           =   165
      End
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "New"
         Height          =   195
         Index           =   4
         Left            =   1215
         TabIndex        =   69
         Top             =   330
         Width           =   345
      End
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Current"
         Height          =   195
         Index           =   5
         Left            =   195
         TabIndex        =   68
         Top             =   330
         Width           =   510
      End
      Begin VB.Label Label22 
         AutoSize        =   -1  'True
         Caption         =   "x"
         Height          =   195
         Left            =   915
         TabIndex        =   67
         Top             =   90
         Width           =   75
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   2415
      Index           =   0
      Left            =   60
      ScaleHeight     =   2355
      ScaleWidth      =   1935
      TabIndex        =   164
      Top             =   270
      Width           =   1995
      Begin VB.CommandButton btnSelAllLocked 
         Caption         =   "Select All Locked"
         Height          =   255
         Index           =   2
         Left            =   90
         TabIndex        =   105
         ToolTipText     =   "Select all Locked objects"
         Top             =   2100
         Width           =   1785
      End
      Begin VB.CommandButton btnColor 
         Caption         =   "No Fill"
         Height          =   270
         Index           =   5
         Left            =   1170
         TabIndex        =   81
         ToolTipText     =   "Set fill style to null"
         Top             =   1320
         Width           =   780
      End
      Begin VB.CommandButton btnColor 
         Caption         =   "No Line"
         Height          =   270
         Index           =   4
         Left            =   150
         TabIndex        =   80
         ToolTipText     =   "Set line style to null"
         Top             =   1320
         Width           =   780
      End
      Begin VB.CommandButton btnColor 
         Caption         =   "Get"
         Height          =   270
         Index           =   0
         Left            =   855
         TabIndex        =   59
         ToolTipText     =   "Get the selected objects line (pen) color"
         Top             =   660
         Width           =   480
      End
      Begin VB.CommandButton btnColor 
         Caption         =   "Set"
         Height          =   270
         Index           =   1
         Left            =   1440
         TabIndex        =   58
         ToolTipText     =   "Set the selected objects line (pen) color"
         Top             =   675
         Width           =   480
      End
      Begin VB.CommandButton btnColor 
         Caption         =   "Get"
         Height          =   270
         Index           =   2
         Left            =   855
         TabIndex        =   57
         ToolTipText     =   "Get the selected objects fill (brush) color"
         Top             =   990
         Width           =   480
      End
      Begin VB.CommandButton btnColor 
         Caption         =   "Set"
         Height          =   270
         Index           =   3
         Left            =   1440
         TabIndex        =   56
         ToolTipText     =   "Set the selected objects fill (brush) color"
         Top             =   990
         Width           =   480
      End
      Begin VB.CheckBox chkDrawFilledTransparent 
         Caption         =   "Draw Filled Objects Transparently"
         Height          =   405
         Left            =   135
         TabIndex        =   55
         ToolTipText     =   "All filled objects, such as polygons, will be drawn transparently"
         Top             =   1665
         Width           =   1695
      End
      Begin ABBCAToolbar.CAToolbar tbColorA 
         Height          =   270
         Left            =   120
         Top             =   60
         Width           =   1830
         _ExtentX        =   3228
         _ExtentY        =   476
         BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         TextDisabledColor=   -2147483639
         ButtonGap       =   4
         BorderStyle     =   1
         BorderLeft      =   0   'False
         BorderTop       =   0   'False
         BorderRight     =   0   'False
         BorderBottom    =   0   'False
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ButtonCount     =   6
         PlaySounds      =   0   'False
         SolidChecked    =   -1  'True
         ShowSeparators  =   -1  'True
         CaptionAlignment=   4
         AutoSize        =   -1  'True
         ButtonKey1      =   "C1"
         ButtonGroupID1  =   1
         ButtonKey2      =   "C2"
         ButtonGroupID2  =   1
         ButtonKey3      =   "C3"
         ButtonGroupID3  =   1
         ButtonKey4      =   "C4"
         ButtonGroupID4  =   1
         ButtonKey5      =   "C5"
         ButtonGroupID5  =   1
         ButtonKey6      =   "C6"
         ButtonGroupID6  =   1
      End
      Begin ABBCAToolbar.CAToolbar tbColorB 
         Height          =   270
         Left            =   120
         Top             =   360
         Width           =   1830
         _ExtentX        =   3228
         _ExtentY        =   476
         BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ButtonGap       =   4
         BorderStyle     =   1
         BorderLeft      =   0   'False
         BorderTop       =   0   'False
         BorderRight     =   0   'False
         BorderBottom    =   0   'False
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ButtonCount     =   6
         PlaySounds      =   0   'False
         SolidChecked    =   -1  'True
         ShowSeparators  =   -1  'True
         CaptionAlignment=   4
         AutoSize        =   -1  'True
         ButtonKey1      =   "C1"
         ButtonGroupID1  =   1
         ButtonKey2      =   "C2"
         ButtonGroupID2  =   1
         ButtonKey3      =   "C3"
         ButtonGroupID3  =   1
         ButtonKey4      =   "C4"
         ButtonGroupID4  =   1
         ButtonKey5      =   "C5"
         ButtonGroupID5  =   1
         ButtonKey6      =   "C6"
         ButtonGroupID6  =   1
      End
      Begin VB.Label Label13 
         AutoSize        =   -1  'True
         Caption         =   "Line Color"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   90
         TabIndex        =   61
         Top             =   675
         Width           =   705
      End
      Begin VB.Label Label14 
         AutoSize        =   -1  'True
         Caption         =   "Fill Color"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   180
         TabIndex        =   60
         Top             =   990
         Width           =   585
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   1995
      Index           =   2
      Left            =   2160
      ScaleHeight     =   1935
      ScaleWidth      =   1935
      TabIndex        =   165
      Top             =   315
      Width           =   1995
      Begin VB.CommandButton btnSnap1 
         Caption         =   "4"
         Height          =   225
         Index           =   3
         Left            =   80
         Style           =   1  'Graphical
         TabIndex        =   79
         ToolTipText     =   "Set Snap 4"
         Top             =   1440
         Width           =   330
      End
      Begin VB.CommandButton btnSnap1 
         Caption         =   "3"
         Height          =   225
         Index           =   2
         Left            =   80
         Style           =   1  'Graphical
         TabIndex        =   78
         ToolTipText     =   "Set Snap 3"
         Top             =   1185
         Width           =   330
      End
      Begin VB.CommandButton btnSnap1 
         Caption         =   "2"
         Height          =   225
         Index           =   1
         Left            =   80
         Style           =   1  'Graphical
         TabIndex        =   77
         ToolTipText     =   "Set Snap 2"
         Top             =   930
         Width           =   330
      End
      Begin VB.CommandButton btnSnap1 
         Caption         =   "1"
         Height          =   225
         Index           =   0
         Left            =   80
         Style           =   1  'Graphical
         TabIndex        =   76
         ToolTipText     =   "Set Snap 1"
         Top             =   675
         Width           =   330
      End
      Begin VB.TextBox txtSnapX 
         Height          =   255
         Index           =   0
         Left            =   450
         TabIndex        =   47
         Text            =   "1"
         Top             =   660
         Width           =   705
      End
      Begin VB.TextBox txtSnapX 
         Height          =   255
         Index           =   1
         Left            =   450
         TabIndex        =   46
         Text            =   "1"
         Top             =   915
         Width           =   705
      End
      Begin VB.TextBox txtSnapX 
         Height          =   255
         Index           =   2
         Left            =   450
         TabIndex        =   45
         Text            =   "1"
         Top             =   1170
         Width           =   705
      End
      Begin VB.TextBox txtSnapX 
         Height          =   255
         Index           =   3
         Left            =   450
         TabIndex        =   44
         Text            =   "1"
         Top             =   1425
         Width           =   705
      End
      Begin VB.TextBox txtSnapY 
         Height          =   255
         Index           =   3
         Left            =   1200
         TabIndex        =   43
         Text            =   "1"
         Top             =   1425
         Width           =   705
      End
      Begin VB.TextBox txtSnapY 
         Height          =   255
         Index           =   2
         Left            =   1200
         TabIndex        =   42
         Text            =   "1"
         Top             =   1170
         Width           =   705
      End
      Begin VB.TextBox txtSnapY 
         Height          =   255
         Index           =   1
         Left            =   1200
         TabIndex        =   41
         Text            =   "1"
         Top             =   915
         Width           =   705
      End
      Begin VB.TextBox txtSnapY 
         Height          =   255
         Index           =   0
         Left            =   1200
         TabIndex        =   40
         Text            =   "1"
         Top             =   660
         Width           =   705
      End
      Begin VB.TextBox txtSnapMult 
         Height          =   255
         Left            =   1200
         TabIndex        =   39
         Text            =   "1"
         ToolTipText     =   "'multiplier'  X  'snapValue'  =  'Actual Snap Value'"
         Top             =   1680
         Width           =   705
      End
      Begin ABBCAToolbar.CAToolbar tbbtnSnap 
         Height          =   330
         Left            =   90
         Top             =   60
         Width           =   330
         _ExtentX        =   582
         _ExtentY        =   582
         BeginProperty ToolTipFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         BorderStyle     =   1
         BorderLeft      =   0   'False
         BorderTop       =   0   'False
         BorderRight     =   0   'False
         BorderBottom    =   0   'False
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ButtonCount     =   1
         PlaySounds      =   0   'False
         SolidChecked    =   -1  'True
         ShowSeparators  =   -1  'True
         CaptionAlignment=   4
         ButtonKey1      =   "Snap"
         ButtonPicture1  =   "ucToolPanelB.ctx":0F8E
         ButtonToolTipText1=   "Snap On/Off"
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "Multiplier"
         Height          =   195
         Index           =   4
         Left            =   525
         TabIndex        =   54
         Top             =   1725
         Width           =   615
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "Cursor Snap"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Index           =   0
         Left            =   810
         TabIndex        =   53
         Top             =   30
         Width           =   870
      End
      Begin VB.Label Label2 
         Alignment       =   2  'Center
         Caption         =   "Vert"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   225
         Index           =   1
         Left            =   1425
         TabIndex        =   52
         Top             =   240
         Width           =   375
      End
      Begin VB.Label Label2 
         Alignment       =   2  'Center
         Caption         =   "Horz"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   225
         Index           =   0
         Left            =   705
         TabIndex        =   51
         Top             =   240
         Width           =   375
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "Current"
         Height          =   195
         Index           =   1
         Left            =   45
         TabIndex        =   50
         Top             =   465
         Width           =   510
      End
      Begin VB.Label lblSnapCurX 
         Alignment       =   2  'Center
         Caption         =   "0"
         Height          =   195
         Left            =   555
         TabIndex        =   49
         Top             =   465
         Width           =   690
      End
      Begin VB.Label lblSnapCurY 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "0"
         Height          =   195
         Left            =   1560
         TabIndex        =   48
         Top             =   465
         Width           =   90
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   1425
      Index           =   4
      Left            =   4275
      ScaleHeight     =   1365
      ScaleWidth      =   1935
      TabIndex        =   166
      Top             =   315
      Width           =   1995
      Begin VB.CommandButton btnSeparate 
         Height          =   285
         Index           =   3
         Left            =   420
         Picture         =   "ucToolPanelB.ctx":12E0
         Style           =   1  'Graphical
         TabIndex        =   95
         ToolTipText     =   "Space selection towards the Bottom"
         Top             =   570
         Width           =   330
      End
      Begin VB.CommandButton btnSeparate 
         Height          =   285
         Index           =   2
         Left            =   45
         Picture         =   "ucToolPanelB.ctx":13E2
         Style           =   1  'Graphical
         TabIndex        =   94
         ToolTipText     =   "Space selection towards the Top"
         Top             =   570
         Width           =   330
      End
      Begin VB.CommandButton btnSeparate 
         Height          =   285
         Index           =   1
         Left            =   420
         Picture         =   "ucToolPanelB.ctx":14E4
         Style           =   1  'Graphical
         TabIndex        =   93
         ToolTipText     =   "Space selection towards the Right"
         Top             =   270
         Width           =   330
      End
      Begin VB.CommandButton btnSeparate 
         Height          =   285
         Index           =   0
         Left            =   45
         Picture         =   "ucToolPanelB.ctx":15E6
         Style           =   1  'Graphical
         TabIndex        =   92
         ToolTipText     =   "Space selection towards the Left"
         Top             =   270
         Width           =   330
      End
      Begin VB.CommandButton btnDistributeVert 
         BackColor       =   &H00C8D0D4&
         Caption         =   "Vertical"
         Height          =   255
         Left            =   1050
         TabIndex        =   36
         ToolTipText     =   "Equally space all objects between top and bottom most"
         Top             =   1110
         Width           =   840
      End
      Begin VB.CommandButton btnDistributeHorz 
         BackColor       =   &H00C8D0D4&
         Caption         =   "Horizontal"
         Height          =   255
         Left            =   90
         TabIndex        =   35
         ToolTipText     =   "Equally space all objects between left and right most"
         Top             =   1110
         Width           =   840
      End
      Begin VB.TextBox txtSpaceY 
         Height          =   255
         Left            =   810
         TabIndex        =   34
         Text            =   "0.00000"
         Top             =   585
         Width           =   1125
      End
      Begin VB.TextBox txtSpaceX 
         Height          =   255
         Left            =   810
         TabIndex        =   33
         Text            =   "0.00000"
         Top             =   285
         Width           =   1125
      End
      Begin VB.Label Label11 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Distribute"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   630
         TabIndex        =   38
         ToolTipText     =   "Equally space objects between first and last"
         Top             =   885
         Width           =   660
      End
      Begin VB.Label Label4 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Separation"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   615
         TabIndex        =   37
         ToolTipText     =   "Distance between objects"
         Top             =   30
         Width           =   795
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   2940
      Index           =   5
      Left            =   90
      ScaleHeight     =   2880
      ScaleWidth      =   1935
      TabIndex        =   167
      Top             =   2760
      Width           =   1995
      Begin VB.CommandButton btnConvert 
         Caption         =   "Polylines to Polyline"
         Height          =   255
         Index           =   0
         Left            =   90
         TabIndex        =   31
         Top             =   330
         Width           =   1815
      End
      Begin VB.CommandButton btnConvert 
         Caption         =   "Polyline to Polygon"
         Height          =   255
         Index           =   1
         Left            =   90
         TabIndex        =   30
         Top             =   1755
         Width           =   1815
      End
      Begin VB.CommandButton btnConvert 
         Caption         =   "Arc/Ellipse to Polyline"
         Height          =   255
         Index           =   2
         Left            =   90
         TabIndex        =   29
         Top             =   607
         Width           =   1815
      End
      Begin VB.CommandButton btnConvert 
         Caption         =   "Rectangle to Polygon"
         Height          =   255
         Index           =   3
         Left            =   90
         TabIndex        =   28
         Top             =   2025
         Width           =   1815
      End
      Begin VB.CommandButton btnConvert 
         Caption         =   "Polygon to Polyline"
         Height          =   255
         Index           =   4
         Left            =   90
         TabIndex        =   27
         Top             =   884
         Width           =   1815
      End
      Begin VB.CommandButton btnConvert 
         Caption         =   "Bezier to Polyline"
         Height          =   255
         Index           =   5
         Left            =   90
         TabIndex        =   26
         Top             =   1161
         Width           =   1815
      End
      Begin VB.CommandButton btnConvert 
         Caption         =   "Split Polyline"
         Height          =   255
         Index           =   6
         Left            =   90
         TabIndex        =   25
         Top             =   1440
         Width           =   1815
      End
      Begin VB.CommandButton btnConvert 
         Caption         =   "Explode PolyPolygon"
         Height          =   255
         Index           =   7
         Left            =   90
         TabIndex        =   24
         ToolTipText     =   "Break PoloPolygon into seperate polygons"
         Top             =   2610
         Width           =   1815
      End
      Begin VB.CommandButton btnConvert 
         Caption         =   "Create PolyPolygon"
         Height          =   255
         Index           =   8
         Left            =   90
         TabIndex        =   23
         ToolTipText     =   "convert 2 or more polygons into a complex polygon"
         Top             =   2340
         Width           =   1815
      End
      Begin VB.Label Label17 
         AutoSize        =   -1  'True
         Caption         =   "Convert"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   690
         TabIndex        =   32
         Top             =   45
         Width           =   555
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   4515
      Index           =   6
      Left            =   6330
      ScaleHeight     =   4455
      ScaleWidth      =   1935
      TabIndex        =   168
      Top             =   270
      Width           =   1995
      Begin VB.CheckBox chkLayerPrint 
         Caption         =   "Not Printable"
         Height          =   195
         Left            =   240
         TabIndex        =   146
         ToolTipText     =   "If set, objects on layer will not be printed"
         Top             =   1320
         Width           =   1440
      End
      Begin VB.CheckBox chkLayerVisible 
         Caption         =   "Hidden"
         Height          =   195
         Left            =   240
         TabIndex        =   145
         ToolTipText     =   "If set, objects on layer are not visible"
         Top             =   1095
         Width           =   1110
      End
      Begin VB.CheckBox chkLayerMoveLock 
         Caption         =   "Move Lock"
         Height          =   195
         Left            =   240
         TabIndex        =   144
         ToolTipText     =   "If set, objects on layer can not be moved"
         Top             =   885
         Width           =   1365
      End
      Begin VB.CheckBox chkLayerSelLock 
         Caption         =   "Select Lock"
         Height          =   195
         Left            =   240
         TabIndex        =   143
         ToolTipText     =   "If set, objects on layer can not be selected"
         Top             =   660
         Width           =   1365
      End
      Begin VB.PictureBox picLayers 
         Height          =   2025
         Left            =   60
         ScaleHeight     =   1965
         ScaleWidth      =   1785
         TabIndex        =   141
         Top             =   1785
         Width           =   1845
         Begin VSFlex6DAOCtl.vsFlexGrid FGProps 
            CausesValidation=   0   'False
            Height          =   1080
            Left            =   120
            TabIndex        =   142
            Top             =   120
            Width           =   1500
            _ExtentX        =   2646
            _ExtentY        =   1905
            _ConvInfo       =   1
            Appearance      =   1
            BorderStyle     =   0
            Enabled         =   -1  'True
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            MousePointer    =   0
            BackColor       =   -2147483643
            ForeColor       =   -2147483640
            BackColorFixed  =   -2147483633
            ForeColorFixed  =   -2147483630
            BackColorSel    =   -2147483635
            ForeColorSel    =   -2147483634
            BackColorBkg    =   -2147483636
            BackColorAlternate=   -2147483643
            GridColor       =   -2147483633
            GridColorFixed  =   -2147483632
            TreeColor       =   -2147483632
            FloodColor      =   192
            SheetBorder     =   -2147483642
            FocusRect       =   1
            HighLight       =   2
            AllowSelection  =   -1  'True
            AllowBigSelection=   0   'False
            AllowUserResizing=   1
            SelectionMode   =   0
            GridLines       =   2
            GridLinesFixed  =   2
            GridLineWidth   =   1
            Rows            =   2
            Cols            =   2
            FixedRows       =   0
            FixedCols       =   1
            RowHeightMin    =   0
            RowHeightMax    =   0
            ColWidthMin     =   0
            ColWidthMax     =   0
            ExtendLastCol   =   -1  'True
            FormatString    =   ""
            ScrollTrack     =   0   'False
            ScrollBars      =   2
            ScrollTips      =   0   'False
            MergeCells      =   0
            MergeCompare    =   0
            AutoResize      =   0   'False
            AutoSizeMode    =   0
            AutoSearch      =   0
            MultiTotals     =   -1  'True
            SubtotalPosition=   1
            OutlineBar      =   0
            OutlineCol      =   0
            Ellipsis        =   0
            ExplorerBar     =   0
            PicturesOver    =   0   'False
            FillStyle       =   0
            RightToLeft     =   0   'False
            PictureType     =   0
            TabBehavior     =   0
            OwnerDraw       =   0
            Editable        =   -1  'True
            ShowComboButton =   -1  'True
            WordWrap        =   0   'False
            TextStyle       =   0
            TextStyleFixed  =   0
            OleDragMode     =   0
            OleDropMode     =   0
            DataMode        =   0
            VirtualData     =   -1  'True
         End
      End
      Begin VB.PictureBox picDefaultLayer 
         Height          =   360
         Left            =   90
         ScaleHeight     =   300
         ScaleWidth      =   1785
         TabIndex        =   138
         Top             =   4125
         Width           =   1845
         Begin VB.TextBox txtLayer 
            Height          =   255
            Left            =   1065
            TabIndex        =   139
            Text            =   "0"
            ToolTipText     =   "Sets the default layer, new objects will be assigned this layer."
            Top             =   60
            Width           =   660
         End
         Begin VB.Label Label8 
            AutoSize        =   -1  'True
            Caption         =   "Default Layer"
            Height          =   195
            Left            =   0
            TabIndex        =   140
            ToolTipText     =   "Sets the default layer. New objects will be assigned this layer."
            Top             =   90
            Width           =   945
         End
         Begin VB.Line Line3 
            X1              =   45
            X2              =   1725
            Y1              =   30
            Y2              =   30
         End
      End
      Begin VB.TextBox txtCurLayer 
         Height          =   255
         Left            =   1290
         TabIndex        =   20
         Text            =   "0"
         Top             =   210
         Width           =   585
      End
      Begin VB.CommandButton btnAssignLayer 
         Caption         =   "Assign Layer"
         Height          =   255
         Left            =   150
         TabIndex        =   19
         ToolTipText     =   "Assign layer entered to selection"
         Top             =   90
         Width           =   1065
      End
      Begin VB.CommandButton btnSelByLayer 
         Caption         =   "Select Layer"
         Height          =   255
         Left            =   150
         TabIndex        =   18
         ToolTipText     =   "Select all objects on layer"
         Top             =   360
         Width           =   1065
      End
      Begin VB.CommandButton btnRefreshLayers 
         Caption         =   "Refresh !"
         Height          =   255
         Left            =   480
         TabIndex        =   17
         ToolTipText     =   "Refresh list of existing layers"
         Top             =   3840
         Width           =   975
      End
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   " Layer"
         Height          =   195
         Index           =   0
         Left            =   480
         TabIndex        =   22
         Top             =   120
         Width           =   450
      End
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         Caption         =   "Existing Layers"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   225
         Index           =   2
         Left            =   330
         TabIndex        =   21
         Top             =   1545
         Width           =   1290
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   5910
      Index           =   7
      Left            =   8415
      ScaleHeight     =   5850
      ScaleWidth      =   1935
      TabIndex        =   169
      Top             =   315
      Width           =   1995
      Begin CGCtrlLib.CG ShapeGe 
         Height          =   1515
         Left            =   90
         TabIndex        =   202
         Top             =   450
         Width           =   1815
         _Version        =   65536
         _ExtentX        =   3201
         _ExtentY        =   2672
         _StockProps     =   64
      End
      Begin VB.PictureBox picShpBottom 
         Height          =   600
         Left            =   60
         ScaleHeight     =   540
         ScaleWidth      =   1845
         TabIndex        =   101
         Top             =   5250
         Width           =   1905
         Begin VB.CommandButton btnQty 
            Caption         =   "Set Qty"
            Enabled         =   0   'False
            Height          =   255
            Left            =   90
            TabIndex        =   103
            ToolTipText     =   "Set the number of elements in Shape Array"
            Top             =   240
            Width           =   825
         End
         Begin VB.TextBox txtQty 
            Enabled         =   0   'False
            Height          =   255
            Left            =   1005
            TabIndex        =   102
            Text            =   "0"
            Top             =   240
            Width           =   675
         End
         Begin VB.Label lSmartShape 
            AutoSize        =   -1  'True
            Caption         =   "SmartShape"
            Height          =   195
            Left            =   0
            TabIndex        =   104
            Top             =   0
            Visible         =   0   'False
            Width           =   870
         End
      End
      Begin VB.ComboBox cbShapeFolder 
         Height          =   315
         ItemData        =   "ucToolPanelB.ctx":16E8
         Left            =   60
         List            =   "ucToolPanelB.ctx":16EA
         Sorted          =   -1  'True
         Style           =   2  'Dropdown List
         TabIndex        =   16
         ToolTipText     =   "Select a Folder"
         Top             =   2025
         Width           =   1860
      End
      Begin VB.ListBox lbShapes 
         Height          =   2400
         Left            =   60
         TabIndex        =   15
         Top             =   2715
         Width           =   1860
      End
      Begin VB.CommandButton btnInsertShape 
         BackColor       =   &H8000000A&
         Caption         =   "Insert Shape !"
         Height          =   270
         Left            =   330
         TabIndex        =   14
         ToolTipText     =   "Insert selected shape into drawing"
         Top             =   2400
         Width           =   1305
      End
      Begin VB.ComboBox cbShapeLibName 
         Height          =   315
         ItemData        =   "ucToolPanelB.ctx":16EC
         Left            =   60
         List            =   "ucToolPanelB.ctx":16EE
         Style           =   2  'Dropdown List
         TabIndex        =   13
         ToolTipText     =   "Select one of the attached libraries."
         Top             =   45
         Width           =   1875
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   4770
      Index           =   9
      Left            =   10530
      ScaleHeight     =   4710
      ScaleWidth      =   1935
      TabIndex        =   170
      Top             =   1590
      Width           =   1995
      Begin VB.PictureBox picZoomView 
         CausesValidation=   0   'False
         Height          =   2895
         Left            =   0
         ScaleHeight     =   2835
         ScaleWidth      =   1905
         TabIndex        =   160
         Top             =   1680
         Width           =   1965
      End
      Begin VB.ComboBox comboFont 
         Height          =   315
         Left            =   105
         Sorted          =   -1  'True
         Style           =   2  'Dropdown List
         TabIndex        =   11
         Top             =   270
         Width           =   1830
      End
      Begin VB.CheckBox chkFontStrikeout 
         Caption         =   "Strikeout"
         Height          =   195
         Left            =   105
         TabIndex        =   10
         Top             =   630
         Width           =   930
      End
      Begin VB.CheckBox chkFontUnderline 
         Caption         =   "Underline"
         Height          =   195
         Left            =   105
         TabIndex        =   9
         Top             =   855
         Width           =   1005
      End
      Begin VB.CheckBox chkFontBold 
         Caption         =   "Bold"
         Height          =   195
         Left            =   1260
         TabIndex        =   8
         Top             =   630
         Width           =   645
      End
      Begin VB.CheckBox chkFontItalic 
         Caption         =   "Italic"
         Height          =   195
         Left            =   1260
         TabIndex        =   7
         Top             =   855
         Width           =   645
      End
      Begin VB.CommandButton btnFontHeight 
         BackColor       =   &H00C8D0D4&
         Caption         =   "Height"
         Height          =   285
         Left            =   90
         TabIndex        =   6
         ToolTipText     =   "Set Font Height (in drawing units)"
         Top             =   1125
         Width           =   825
      End
      Begin VB.TextBox txtFontHeight 
         Height          =   285
         Left            =   1035
         TabIndex        =   5
         Text            =   "0.25000"
         Top             =   1125
         Width           =   765
      End
      Begin VB.Label Label19 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Font"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   750
         TabIndex        =   12
         Top             =   30
         Width           =   330
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   915
      Index           =   8
      Left            =   10485
      ScaleHeight     =   855
      ScaleWidth      =   1935
      TabIndex        =   171
      Top             =   315
      Width           =   1995
      Begin VB.TextBox txtObjectHit 
         Height          =   255
         Left            =   1350
         TabIndex        =   1
         Text            =   "1"
         ToolTipText     =   "Distance Cursor is from Object before it is 'Hit'"
         Top             =   300
         Width           =   495
      End
      Begin VB.TextBox txtObjectSnap 
         Height          =   255
         Left            =   3510
         TabIndex        =   0
         Text            =   "4"
         ToolTipText     =   "Distance object is from a SnapTo point before it will Snap"
         Top             =   -225
         Width           =   495
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "Object Selection"
         Height          =   195
         Index           =   2
         Left            =   90
         TabIndex        =   4
         Top             =   330
         Width           =   1170
      End
      Begin VB.Label Label7 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Hit Sensitivity"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   480
         TabIndex        =   3
         ToolTipText     =   "How close cursor is to an object before it is 'Hit' (64'ths inch)"
         Top             =   30
         Width           =   975
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "Object Snap"
         Height          =   195
         Index           =   3
         Left            =   390
         TabIndex        =   2
         Top             =   600
         Width           =   885
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   1440
      Index           =   10
      Left            =   4275
      ScaleHeight     =   1380
      ScaleWidth      =   1935
      TabIndex        =   172
      Top             =   3435
      Width           =   1995
      Begin VB.CheckBox chkCenter 
         Caption         =   "Rotate about center"
         Height          =   195
         Left            =   165
         TabIndex        =   87
         Tag             =   "If set, rotate objects about their center"
         Top             =   885
         Value           =   1  'Checked
         Width           =   1725
      End
      Begin VB.TextBox txtAngle 
         Height          =   255
         Left            =   1125
         TabIndex        =   86
         Text            =   "45"
         Top             =   600
         Width           =   795
      End
      Begin VB.CommandButton btnCW 
         Caption         =   "CW"
         Height          =   255
         Left            =   165
         TabIndex        =   85
         ToolTipText     =   "Rotate clockwise"
         Top             =   1110
         Width           =   810
      End
      Begin VB.CommandButton btnCCW 
         Caption         =   "CCW"
         Height          =   255
         Left            =   1095
         TabIndex        =   84
         ToolTipText     =   "Rotate counter clockwise"
         Top             =   1110
         Width           =   810
      End
      Begin VB.TextBox txtRotateY 
         Height          =   255
         Left            =   1125
         TabIndex        =   83
         Text            =   "0.00"
         Top             =   300
         Width           =   795
      End
      Begin VB.TextBox txtRotateX 
         Height          =   255
         Left            =   135
         TabIndex        =   82
         Text            =   "0.00"
         Top             =   315
         Width           =   795
      End
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Angle (deg)"
         Height          =   195
         Index           =   8
         Left            =   135
         TabIndex        =   91
         Top             =   630
         Width           =   810
      End
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         Caption         =   "X"
         Height          =   210
         Index           =   7
         Left            =   345
         TabIndex        =   90
         Top             =   105
         Width           =   375
      End
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         Caption         =   "Y"
         Height          =   210
         Index           =   6
         Left            =   1305
         TabIndex        =   89
         Top             =   105
         Width           =   375
      End
      Begin VB.Label Label16 
         AutoSize        =   -1  'True
         Caption         =   "Rotate"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   765
         TabIndex        =   88
         Top             =   30
         Width           =   480
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   600
      Index           =   11
      Left            =   4275
      ScaleHeight     =   540
      ScaleWidth      =   1935
      TabIndex        =   173
      Top             =   4905
      Width           =   1995
      Begin VB.CommandButton btnAlignToSnap 
         Height          =   285
         Index           =   4
         Left            =   870
         Picture         =   "ucToolPanelB.ctx":16F0
         Style           =   1  'Graphical
         TabIndex        =   135
         ToolTipText     =   "Align center to snap"
         Top             =   270
         Width           =   315
      End
      Begin VB.CommandButton btnAlignToSnap 
         Height          =   285
         Index           =   2
         Left            =   1275
         Picture         =   "ucToolPanelB.ctx":17EA
         Style           =   1  'Graphical
         TabIndex        =   99
         ToolTipText     =   "Align top to snap"
         Top             =   270
         Width           =   315
      End
      Begin VB.CommandButton btnAlignToSnap 
         Height          =   285
         Index           =   3
         Left            =   1590
         Picture         =   "ucToolPanelB.ctx":18EC
         Style           =   1  'Graphical
         TabIndex        =   98
         ToolTipText     =   "Align bottom to snap"
         Top             =   270
         Width           =   315
      End
      Begin VB.CommandButton btnAlignToSnap 
         Height          =   285
         Index           =   1
         Left            =   420
         Picture         =   "ucToolPanelB.ctx":19EE
         Style           =   1  'Graphical
         TabIndex        =   97
         ToolTipText     =   "Align right to snap"
         Top             =   270
         Width           =   315
      End
      Begin VB.CommandButton btnAlignToSnap 
         Height          =   285
         Index           =   0
         Left            =   90
         Picture         =   "ucToolPanelB.ctx":1AF0
         Style           =   1  'Graphical
         TabIndex        =   96
         ToolTipText     =   "Align left to snap"
         Top             =   270
         Width           =   315
      End
      Begin VB.Label Label5 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Align to Snap"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   510
         TabIndex        =   100
         Top             =   30
         Width           =   975
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   3315
      Index           =   3
      Left            =   2160
      ScaleHeight     =   3255
      ScaleWidth      =   1935
      TabIndex        =   174
      Top             =   2550
      Width           =   1995
      Begin VB.CheckBox chkDrawInsertionPoints 
         Caption         =   "Show Shape Insertion Points "
         Height          =   405
         Left            =   90
         TabIndex        =   118
         ToolTipText     =   "Show the Insertion points of Shapes"
         Top             =   2880
         Width           =   1605
      End
      Begin VB.CheckBox chkShowConnectionPts 
         Caption         =   "Show Connection && Reference Points"
         Height          =   405
         Left            =   90
         TabIndex        =   117
         ToolTipText     =   "Show all connection and reference points"
         Top             =   2490
         Value           =   1  'Checked
         Width           =   1695
      End
      Begin VB.CommandButton btnObjectSnap 
         Caption         =   "None"
         Height          =   255
         Index           =   1
         Left            =   1080
         TabIndex        =   116
         Top             =   285
         Width           =   795
      End
      Begin VB.CommandButton btnObjectSnap 
         Caption         =   "All"
         Height          =   255
         Index           =   0
         Left            =   150
         TabIndex        =   115
         Top             =   285
         Width           =   795
      End
      Begin VB.CheckBox cbObjSnap 
         Caption         =   "Snap to Connection/ Ref. Points"
         Height          =   405
         Index           =   6
         Left            =   90
         TabIndex        =   114
         ToolTipText     =   "Snap objects being moved to Connection or Reference Points"
         Top             =   1245
         Width           =   1785
      End
      Begin VB.CheckBox chkSnapToShape 
         Caption         =   "Snap Shapes to Cursor"
         Height          =   375
         Left            =   90
         TabIndex        =   113
         ToolTipText     =   "Snap insertion points of Shapes being moved to the cursor"
         Top             =   1725
         Value           =   1  'Checked
         Width           =   1485
      End
      Begin VB.CheckBox cbObjSnap 
         Caption         =   "Quadrant"
         Height          =   195
         Index           =   5
         Left            =   930
         TabIndex        =   112
         Top             =   1035
         Width           =   990
      End
      Begin VB.CheckBox cbObjSnap 
         Caption         =   "Nearest"
         Height          =   195
         Index           =   4
         Left            =   930
         TabIndex        =   111
         Top             =   825
         Width           =   885
      End
      Begin VB.CheckBox cbObjSnap 
         Caption         =   "Insert Pt"
         Height          =   195
         Index           =   3
         Left            =   930
         TabIndex        =   110
         Top             =   615
         Width           =   900
      End
      Begin VB.CheckBox cbObjSnap 
         Caption         =   "Center"
         Height          =   195
         Index           =   0
         Left            =   90
         TabIndex        =   109
         Top             =   615
         Width           =   795
      End
      Begin VB.CheckBox cbObjSnap 
         Caption         =   "End Pt"
         Height          =   195
         Index           =   1
         Left            =   90
         TabIndex        =   108
         Top             =   825
         Value           =   1  'Checked
         Width           =   795
      End
      Begin VB.CheckBox cbObjSnap 
         Caption         =   "Mid Pt"
         Height          =   195
         Index           =   2
         Left            =   90
         TabIndex        =   107
         Top             =   1035
         Width           =   780
      End
      Begin VB.CheckBox chkSnapTosel 
         Caption         =   "Snap to Selected Objects"
         Height          =   345
         Left            =   90
         TabIndex        =   106
         ToolTipText     =   "Cursor will snap objects to themselves when being moved"
         Top             =   2130
         Value           =   1  'Checked
         Width           =   1725
      End
      Begin VB.Line Line1 
         X1              =   120
         X2              =   1890
         Y1              =   1695
         Y2              =   1695
      End
      Begin VB.Label Label10 
         AutoSize        =   -1  'True
         Caption         =   "Object Snap"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   540
         TabIndex        =   119
         Top             =   45
         Width           =   885
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   5895
      Index           =   12
      Left            =   13065
      ScaleHeight     =   5835
      ScaleWidth      =   1935
      TabIndex        =   175
      Top             =   270
      Width           =   1995
      Begin VB.TextBox txtAngleRotate 
         Height          =   285
         Left            =   675
         TabIndex        =   212
         Text            =   "0"
         ToolTipText     =   "Degrees to Rotate"
         Top             =   2760
         Width           =   675
      End
      Begin VB.CommandButton btnSet 
         Caption         =   "Rotate"
         Height          =   255
         Index           =   2
         Left            =   60
         TabIndex        =   211
         ToolTipText     =   "Move by amount entered"
         Top             =   2460
         Width           =   1305
      End
      Begin VB.TextBox txtDYScale 
         Height          =   285
         Left            =   660
         TabIndex        =   209
         Text            =   "1"
         Top             =   2055
         Width           =   675
      End
      Begin VB.TextBox txtDXScale 
         Height          =   285
         Left            =   645
         TabIndex        =   207
         Text            =   "1"
         Top             =   1740
         Width           =   675
      End
      Begin VB.CommandButton btnSet 
         Caption         =   "Scale"
         Height          =   255
         Index           =   1
         Left            =   60
         TabIndex        =   206
         ToolTipText     =   "Move by amount entered"
         Top             =   1440
         Width           =   1305
      End
      Begin VB.TextBox txtDYMove 
         Height          =   285
         Left            =   630
         TabIndex        =   204
         Text            =   "0"
         Top             =   1020
         Width           =   675
      End
      Begin VB.TextBox txtDXMove 
         Height          =   285
         Left            =   615
         TabIndex        =   201
         Text            =   "0"
         Top             =   705
         Width           =   675
      End
      Begin VB.TextBox txtIDMove 
         Height          =   285
         Left            =   495
         TabIndex        =   121
         Text            =   "0"
         Top             =   15
         Width           =   675
      End
      Begin VB.CommandButton btnSet 
         Caption         =   "Move"
         Height          =   255
         Index           =   0
         Left            =   90
         TabIndex        =   120
         ToolTipText     =   "Move by amount entered"
         Top             =   420
         Width           =   1185
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Angle"
         Height          =   210
         Index           =   27
         Left            =   90
         TabIndex        =   213
         Top             =   2805
         Width           =   465
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "scaleY"
         Height          =   210
         Index           =   25
         Left            =   60
         TabIndex        =   210
         Top             =   2100
         Width           =   465
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "scaleX"
         Height          =   210
         Index           =   24
         Left            =   60
         TabIndex        =   208
         Top             =   1785
         Width           =   465
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "DY"
         Height          =   210
         Index           =   23
         Left            =   210
         TabIndex        =   205
         Top             =   1065
         Width           =   285
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "DX"
         Height          =   210
         Index           =   22
         Left            =   210
         TabIndex        =   200
         Top             =   750
         Width           =   285
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "ID"
         Height          =   210
         Index           =   21
         Left            =   120
         TabIndex        =   199
         Top             =   30
         Width           =   285
      End
   End
   Begin VB.PictureBox ucPanelA 
      Height          =   2040
      Index           =   14
      Left            =   6300
      ScaleHeight     =   1980
      ScaleWidth      =   1935
      TabIndex        =   176
      Top             =   5250
      Width           =   1995
      Begin VB.CommandButton btnMakeArrayCentered 
         Caption         =   "Make Array (Centers)"
         Height          =   255
         Left            =   180
         TabIndex        =   158
         ToolTipText     =   "Make an array of the selected objects, with centers distance apart"
         Top             =   1740
         Width           =   1665
      End
      Begin VB.TextBox txtVSpace 
         Height          =   255
         Left            =   1110
         TabIndex        =   157
         Text            =   "0.00"
         ToolTipText     =   "Verticall distance between objects (or between centers)"
         Top             =   1155
         Width           =   765
      End
      Begin VB.TextBox txtHSpace 
         Height          =   255
         Left            =   180
         TabIndex        =   155
         Text            =   "0.00"
         ToolTipText     =   "Horizontal distance between objects  (or between centers)"
         Top             =   1155
         Width           =   825
      End
      Begin VB.CommandButton btnMakeArray 
         Caption         =   "Make Array "
         Height          =   255
         Left            =   180
         TabIndex        =   153
         ToolTipText     =   "Make an array with objects x units apart"
         Top             =   1470
         Width           =   1665
      End
      Begin VB.TextBox txtNCols 
         Height          =   255
         Left            =   180
         TabIndex        =   148
         Text            =   "1"
         ToolTipText     =   "Number of objects horizontally"
         Top             =   480
         Width           =   825
      End
      Begin VB.TextBox txtNRows 
         Height          =   255
         Left            =   1110
         TabIndex        =   147
         Text            =   "1"
         ToolTipText     =   "Number of objects vertically"
         Top             =   480
         Width           =   765
      End
      Begin VB.Label Label23 
         AutoSize        =   -1  'True
         Caption         =   "Vertical"
         Height          =   195
         Left            =   1170
         TabIndex        =   156
         Top             =   945
         Width           =   525
      End
      Begin VB.Label Label21 
         AutoSize        =   -1  'True
         Caption         =   "Horizontal"
         Height          =   195
         Left            =   210
         TabIndex        =   154
         Top             =   945
         Width           =   705
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "# of Cols"
         Height          =   195
         Index           =   9
         Left            =   210
         TabIndex        =   152
         Top             =   270
         Width           =   630
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "Space Between"
         Height          =   225
         Index           =   8
         Left            =   480
         TabIndex        =   151
         Top             =   750
         Width           =   1140
      End
      Begin VB.Label Label18 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Make Array"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   555
         TabIndex        =   150
         ToolTipText     =   "How close cursor is to an object before it is 'Hit' (64'ths inch)"
         Top             =   30
         Width           =   825
      End
      Begin VB.Label Label2 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "# of Rows"
         Height          =   195
         Index           =   7
         Left            =   1110
         TabIndex        =   149
         Top             =   270
         Width           =   735
      End
   End
   Begin VB.Menu mnuEditItemx 
      Caption         =   "Edit"
      Index           =   4
      Begin VB.Menu mnuEditItem 
         Caption         =   "&Copy"
         Index           =   0
         Shortcut        =   ^C
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "C&ut"
         Index           =   1
         Shortcut        =   ^X
      End
      Begin VB.Menu mnuEditItem 
         Caption         =   "&Paste"
         Index           =   2
         Shortcut        =   ^V
      End
   End
End
Attribute VB_Name = "ucToolPanel"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

'*************
'' NOTE: AEM - 3/5/01 - this is causing problems on my machine (droppings in other apps, GPs, ...)

#Const USE_BITMAPZOOM = False    ' Show the 'Mouse Area (Zoom)' Window in Pref panel
'
'*************



Private Const LB_ITEMFROMPOINT = &H1A9

' color palette info from CG
Private Type ColorInfo
  R As Integer
  G As Integer
  B As Integer
  FLAGS As Integer
  nDX As Long     ' CG palette index
End Type
Private m_aColors(11) As ColorInfo ' 12 colors

Private m_nSelectColor As Integer
Private m_lSetArrayDistance As Single

'
'***********************************************************
'   Publicly controlled variables
'***********************************************************
Private m_GeCtrl As CG
Private m_frmActive As Object ' ucMain ' UserControl  ' ucMain
Private m_bLeftAligned As Boolean

'***********************************************************
'   shape related
'***********************************************************
Private m_strShapeLibName As String
Private m_strShapeLibPath As String
Private m_strLibrary As String
Private m_strFolder As String
Private m_strShape As String

'***********************************************************
'   Internal only variables
'***********************************************************
Private m_bSpecialSelect As Boolean

Private m_aLibraries As Variant
' used by SET to enable button on panel
Private m_bIsSETDrawing As Boolean

Private Const c_SpaceFromTop As Integer = 15
Private Const c_SpaceLeft As Integer = 75

Private m_nLastPanel As Integer
Private m_bInitToolBar As Boolean

Private m_bDoingUpdate As Boolean
Private m_bUpdatingObjectSnap As Boolean
Private m_bUpdatingDistance As Boolean
Private m_bFirstSensSnap As Boolean    ' first time in for Sensitivity snap.
'
' Array of Snap Values
'
Private Type SnapParams
  X As Double
  Y As Double
End Type

Dim m_aSnap(3) As SnapParams  ' 4 snaps
Private m_SnapX As Single
Private m_SnapY As Single
Private m_SnapMult As Single

' Distance before get a hit
Private m_nHitSelectionSize As Integer
Private m_nObjectSnapSize As Integer
Private Const c_HitUnits As Single = 64#    ' 64ths of an inch

' spacing
Private m_dSpaceX As Single
Private m_dSpaceY As Single

' scaling
Private m_bDoIt As Boolean
Private m_WidthCur As Single
Private m_HeightCur As Single
Private m_WidthNew As Single
Private m_HeightNew As Single

Private m_dleft As Single
Private m_dBottom As Single
Private m_dRight As Single
Private m_dtop As Single
Private m_dCenterX As Single
Private m_dCenterY As Single

' rotating
Private m_X As Single
Private m_Y As Single

' Font
Private m_bChangingFont As Boolean  ' flag to manage font Panel
Private m_dFontHeight As Single     ' default height

Private m_lTwipsX As Long  ' Screen.TwipsPerPixelX
Private m_lTwipsY As Long  ' Screen.TwipsPerPixelY

Private m_bPickingPoint As Boolean  ' pickingPoint from CG

' Layers
Private m_LayerDefs As LayerDefinitions ' ref
Private m_bConstructingGrid As Boolean  ' Layers Grid
Private m_bUpdatingLayer As Boolean     ' Layers controls
Private Const c_nLastUserLayer As Integer = 29999   ' last one we'll let the user enter

' Set the order of the buttons here
' Main Panels
Const cMP_SNAP = 0
Const cMP_FORMAT = 1
Const cMP_LAYERS = 2
Const cMP_SHAPES = 3
Const cMP_GENERAL = 4
Const cMP_PREFER = 5
Const cMP_SET1 = 6
Const cMP_SET2 = 7
Const cMP_MOVE = 8

' Tool sub-panels (indexes)
Const cNOT_USED = -1
Const cCOLORS = 0
Const cSCALE = 1
Const cCURSOR_SNAP = 2
Const cOBJECT_SNAP = 3
Const cSEPARATE = 4
Const cCONVERT = 5
Const cLAYERS = 6

Const cHIT_SENSISTIVITY = 8
Const cSHAPES = 7
Const cFONT = 9
Const cROTATE = 10
Const cALIGNSNAP = 11
Const cSET1 = 12    ' SET - main

Const cMOVE = 13    ' Move
Const cARRAY = 14
Const cSET2 = 15 ' SET - aux


'======================================================================================
' View Tracking
'======================================================================================
'------------------------------
Public Sub UpdateCursorPos(ByVal posX As Double, ByVal posY As Double)
  #If USE_BITMAPZOOM Then
  If Not m_frmActive Is Nothing Then
    If IsShowingFont Then GetImageFromGe
  End If
  #End If
End Sub

'*************************************
#If USE_BITMAPZOOM Then
'--------------------------
Private Sub GetImageFromGe()
  ' BitBlt image from GeCtrl into pictureBox

  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  '
  If m_lTwipsX = 0 Then
    m_lTwipsX = Screen.TwipsPerPixelX
    m_lTwipsY = Screen.TwipsPerPixelY
  End If
  
  
  '' PictureBox Control

  Dim hWndPic As Long, lRight As Long, lBottom As Long
  hWndPic = picZoomView.HWND
  
  
  ' check to see if valid, which may not be the case when terminating
  If hWndPic > 0 Then
    lRight = (picZoomView.Width) / m_lTwipsX
    lBottom = (picZoomView.Height) / m_lTwipsY
    '
      ' true = track mouse
    Dim bTrackMouse As Boolean
    Dim CenterX As Long, CenterY As Long
    Dim ScaleFactor As Single
    
    'Blt to an area the size of the Client area passed in,
    'centered on either
    '  bTrackMouse = True - the current mouse position in wGraphic
    '  bTrackMouse = False - the point passed in (in Windows coordinates)
    ' ScaleFactor is how much to inflate CG Bitmap rect by, where the
    ' default rect size is the size of the client window (hWndPic) when ScaleFactor = 1.0.
    
    '' By default, the bitmap will be an area of the GeWindow that is the same size as the
    '' client window, centered about the current mosue position
    
    bTrackMouse = True
    ScaleFactor = 1#
    m_GeCtrl.DrawToWindow hWndPic, 0, 0, lRight, lBottom, bTrackMouse, CenterX, CenterY, ScaleFactor
  End If

End Sub
#End If
'*************************************


'======================================================================================
' Font
'======================================================================================
'--------------------------
Private Sub InitFontsPanel()
  ' first time in
  On Error Resume Next
  m_bChangingFont = True
  FillComboBoxWithFonts comboFont
  m_bChangingFont = False
End Sub

'--------------------------
Private Sub UpdateFontToGe()
  ' set font props on selection if anything selected,
  ' otherwise set default Font props
  Dim GeID As Long
  Dim nGeType As Integer
  Dim strFontFace As String
  Dim bUnderline As Boolean
  Dim bStrikeout As Boolean
  Dim bItalic As Boolean
  Dim nWeight As Integer
  Dim dHeight As Single
  
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  
  strFontFace = comboFont.List(comboFont.ListIndex)
  bUnderline = IIf(chkFontUnderline.Value = 0, False, True)
  bStrikeout = IIf(chkFontStrikeout.Value = 0, False, True)
  bItalic = IIf(chkFontItalic.Value = 0, False, True)
  nWeight = IIf(chkFontBold.Value = 0, 400, 700)
  dHeight = CSng(txtFontHeight.Text)
  If dHeight <= 0 Then dHeight = m_dFontHeight
  txtFontHeight.Text = dHeight    ' reset after conversion
  
  ''
  If m_GeCtrl.SelNumberOfObjects < 1 Then
    ' change defaults
    If Len(strFontFace) > 0 Then m_GeCtrl.FontFaceName = strFontFace
    m_GeCtrl.FontUnderline = bUnderline
    m_GeCtrl.FontStrikeOut = bStrikeout
    m_GeCtrl.FontWeight = nWeight
    m_GeCtrl.FontItalic = bItalic
    m_GeCtrl.FontHeight = dHeight
  Else
    ' change selection
    m_GeCtrl.BeginUndoTransaction
    GeID = m_GeCtrl.GetFirstSelObject
    Do While GeID > 0
      m_GeCtrl.CurrentPropertyID = GeID
      nGeType = m_GeCtrl.ObjectType
      If nGeType = EGeObjType.Text Or _
         nGeType = EGeObjType.TextML Or _
         nGeType = EGeObjType.DimensionLine Or _
         nGeType = EGeObjType.TextField _
      Then
        '
        If Len(strFontFace) > 0 Then m_GeCtrl.FontFaceName = strFontFace
        m_GeCtrl.FontUnderline = bUnderline
        m_GeCtrl.FontStrikeOut = bStrikeout
        m_GeCtrl.FontWeight = nWeight
        m_GeCtrl.FontItalic = bItalic
        m_GeCtrl.FontHeight = dHeight
      End If
      '
      GeID = m_GeCtrl.GetNextSelObject(GeID) '
    Loop
    m_GeCtrl.EndUndoTransaction
    m_GeCtrl.CurrentPropertyID = 0  ' reset selector
  End If
  '
  m_GeCtrl.SetFocus
  
End Sub
'--------------------------
Private Sub UpdateFontFromGe()
  ' update controls from CG
  Dim GeID As Long
  Dim nGeType As Integer
  Dim strFontFace As String
  Dim bUnderline As Boolean
  Dim bStrikeout As Boolean
  Dim bItalic As Boolean
  Dim nWeight As Integer
  Dim dHeight As Single
  
  Dim i As Long
  
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  If Not IsShowingFont Then Exit Sub
  
  m_bChangingFont = True
  '
  ' get defaults
  strFontFace = m_GeCtrl.FontFaceName
  bUnderline = m_GeCtrl.FontUnderline
  bStrikeout = m_GeCtrl.FontStrikeOut
  nWeight = m_GeCtrl.FontWeight
  bItalic = m_GeCtrl.FontItalic
  dHeight = m_GeCtrl.FontHeight
  m_dFontHeight = dHeight
  
'  lblMaxVisChars.Caption = ""
  
#If 0 Then
''''''''
  Dim dOrient As Single
  dOrient = m_GeCtrl.FontOrientation
  lblFontFamily.Caption = "Family: " & m_GeCtrl.FontFamily ' integer
  lblFontCharExtra.Caption = "CharExtra: " & m_GeCtrl.FontCharExtra ' single
  lblFontEscapement.Caption = "Escapement: " & m_GeCtrl.FontEscapement ' single
  lblFontHeight.Caption = "Height: " & m_GeCtrl.FontHeight ' single
  lblFontItalic.Caption = "Italic: " & m_GeCtrl.FontItalic  ' Boolean
  lblFontPitch.Caption = "Pitch: " & m_GeCtrl.FontPitch ' integer
  lblFontWidth.Caption = "Width: " & m_GeCtrl.FontWidth ' single
  lblFontColor.Caption = "Color: " & m_GeCtrl.FontColor ' integer
'''''''
#End If

  ' get from last in sel that supports font
  If m_GeCtrl.SelNumberOfObjects = 1 Then
    GeID = m_GeCtrl.GetLastSelObject
'    Do While GeID > 0
      m_GeCtrl.CurrentPropertyID = GeID
      nGeType = m_GeCtrl.ObjectType
      If nGeType = EGeObjType.Text Or _
         nGeType = EGeObjType.TextML Or _
         nGeType = EGeObjType.TextField _
      Then
        '
        strFontFace = m_GeCtrl.FontFaceName
        bUnderline = m_GeCtrl.FontUnderline
        bStrikeout = m_GeCtrl.FontStrikeOut
        nWeight = m_GeCtrl.FontWeight
        bItalic = m_GeCtrl.FontItalic
        dHeight = m_GeCtrl.FontHeight
        

'        lblMaxVisChars.Caption = m_GeCtrl.GetNumVisibleCharacters & " max visible chars"


#If 0 Then
      ''''''''
        dOrient = m_GeCtrl.FontOrientation
        lblFontFamily.Caption = "Family: " & m_GeCtrl.FontFamily ' integer
        lblFontCharExtra.Caption = "CharExtra: " & m_GeCtrl.FontCharExtra ' single
        lblFontEscapement.Caption = "Escapement: " & m_GeCtrl.FontEscapement ' single
        lblFontHeight.Caption = "Height: " & m_GeCtrl.FontHeight ' single
        lblFontItalic.Caption = "Italic: " & m_GeCtrl.FontItalic  ' Boolean
        lblFontPitch.Caption = "Pitch: " & m_GeCtrl.FontPitch ' integer
        lblFontWidth.Caption = "Width: " & m_GeCtrl.FontWidth ' single
        lblFontColor.Caption = "Color: " & m_GeCtrl.FontColor ' integer
      '''''''
#End If

'        Exit Do
      End If
      '
'      GeID = m_GeCtrl.GetPrevSelObject(GeID) '
'    Loop
    m_GeCtrl.CurrentPropertyID = 0  ' reset selector
  End If
  
  '' actually update controls
  For i = 0 To comboFont.ListCount - 1
    If comboFont.List(i) = strFontFace Then
       comboFont.ListIndex = i
       Exit For
    End If
  Next i
  chkFontUnderline.Value = IIf(bUnderline, 1, 0)
  chkFontStrikeout.Value = IIf(bStrikeout, 1, 0)
  chkFontBold.Value = IIf(nWeight > 400, 1, 0)
  chkFontItalic.Value = IIf(bItalic, 1, 0)
  txtFontHeight.Text = dHeight
  '
  m_bChangingFont = False
End Sub


'-----------------------------
Public Property Get IsPickingPoint() As Boolean
  IsPickingPoint = m_bPickingPoint
End Property

Public Sub SetToolPanelInsertionPt(X As Single, Y As Single)
  m_bPickingPoint = False
  txtIPX.Text = X
  txtIPY.Text = Y
End Sub

Private Sub btnGetIP_Click()
  ' get 'MoveTo' point
  m_bPickingPoint = True
  m_GeCtrl.Tool = GETOOL_PICKPOINT
  MoveCursorOntoGeCtrl
End Sub


Private Sub btnMakeArray_Click()
Dim bRet As Boolean
  bRet = MakeArray(m_GeCtrl, CLng(txtNRows.Text), CLng(txtNCols.Text), CSng(txtHSpace.Text), CSng(txtVSpace.Text), False, False)
End Sub

Private Sub btnMakeArrayCentered_Click()
Dim bRet As Boolean
  bRet = MakeArray(m_GeCtrl, CLng(txtNRows.Text), CLng(txtNCols.Text), CSng(txtHSpace.Text), CSng(txtVSpace.Text), False, True)
End Sub

Private Sub btnMove_Click(index As Integer)
  Dim nX As Single
  Dim nY As Single
  If Not m_GeCtrl Is Nothing Then
    nX = val(txtIPX.Text)
    nY = val(txtIPY.Text)
    GeWorker.MoveSelectionOperation m_GeCtrl, index, nX, nY
    SetGeFocus
  End If
End Sub

'--------------------------
Private Sub btnSelAllLocked_Click(index As Integer)
  If Not m_GeCtrl Is Nothing Then
    m_GeCtrl.SelectAllLocked
    SetGeFocus
  End If
End Sub




'--------------------------
Private Sub txtAngle_GotFocus()
  SelectAllTextControlText txtAngle
End Sub

Private Sub txtAngle_KeyPress(KeyAscii As Integer)
'  -, ., BS and numbers
  If Not (KeyAscii = 45 Or KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

'--------------------------
Private Sub txtAngle_LostFocus()
  If Len(txtAngle.Text) < 1 Then
    txtAngle.Text = "45.0"
  End If
End Sub

'--------------------------
Private Sub txtFontHeight_GotFocus()
  SelectAllTextControlText txtFontHeight
End Sub

'--------------------------
Private Sub txtFontHeight_KeyPress(KeyAscii As Integer)
  ' set height if enter key
  If KeyAscii = vbKeyReturn Then
    KeyAscii = 0
    btnFontHeight_Click
    txtFontHeight.SetFocus
'  ElseIf (KeyAscii < 48 Or KeyAscii > 57) Then
'    ' allow only numbers
'    KeyAscii = 0
  End If
End Sub

'--------------------------
Private Sub comboFont_Click()
  If m_bChangingFont Or _
      m_GeCtrl Is Nothing Or _
      comboFont.ListCount < 0 _
  Then
    Exit Sub
  End If
  UpdateFontToGe
End Sub

'--------------------------
Private Sub chkFontStrikeout_Click()
  If m_GeCtrl Is Nothing Or m_bChangingFont Then Exit Sub
  UpdateFontToGe
End Sub
'--------------------------
Private Sub chkFontUnderline_Click()
  If m_GeCtrl Is Nothing Or m_bChangingFont Then Exit Sub
  UpdateFontToGe
End Sub
'--------------------------
Private Sub chkFontBold_Click()
  If m_GeCtrl Is Nothing Or m_bChangingFont Then Exit Sub
  UpdateFontToGe
End Sub
'--------------------------
Private Sub chkFontItalic_Click()
  If m_GeCtrl Is Nothing Or m_bChangingFont Then Exit Sub
  UpdateFontToGe
End Sub
'--------------------------
Private Sub btnFontHeight_Click()
  If m_GeCtrl Is Nothing Or m_bChangingFont Then Exit Sub
  UpdateFontToGe
End Sub




'======================================================================================
' Properties
'======================================================================================
'--------------------------
Public Property Set ActiveForm(obj As Object)
'Public Property Set ActiveForm(obj As ucMain)
  On Error Resume Next
  
  ' memorize last selected
  If Not m_LayerDefs Is Nothing Then
    Dim iLayer As Integer
    If GetSelLayer(iLayer) Then m_LayerDefs.LastSelectedLayer = iLayer
    Set m_LayerDefs = Nothing
  End If
  
  '
  Set m_GeCtrl = Nothing
  Set m_frmActive = obj
  '
  If Not m_frmActive Is Nothing Then
    Set m_GeCtrl = m_frmActive.GeCtrl
    
    If m_GeCtrl Is Nothing Then
      If IsShowingLayers Then EnumLayers   ' just to clear
    End If
    '
    Set m_LayerDefs = m_frmActive.LayerDefinitions
    
    UpdateToolButtons
    UpdateControlsFromGe
    ShapeGe.InitNew
    GetAttachedLibraries
  Else
    If IsShowingLayers Then EnumLayers   ' just to clear
  End If
  
End Property

'--------------------------
Public Property Get ActiveForm() As Object
'Public Property Get ActiveForm() As ucMain
  Set ActiveForm = m_frmActive
End Property
'--------------------------

Public Function SetOnLeftSide(bLeftTrue As Boolean)
  Dim i As Integer
  m_bLeftAligned = bLeftTrue
End Function

'--------------------------
Private Sub Initialize()
  Dim i As Integer
  Dim j As Integer
  Dim nVisiblePanels As Integer
  Dim strPanelConfig As String
  Dim bUseDefaults As Boolean

  On Error Resume Next
  ' colors
  m_nSelectColor = 0
  m_aColors(0).nDX = 0
  m_aColors(1).nDX = 255
  m_aColors(2).nDX = 249
  m_aColors(3).nDX = 250
  m_aColors(4).nDX = 252
  m_aColors(5).nDX = 251
  m_aColors(6).nDX = 253
  m_aColors(7).nDX = 254
  m_aColors(8).nDX = 7
  m_aColors(9).nDX = 248
  m_aColors(10).nDX = 112
  m_aColors(11).nDX = 47
  
  ' align panels
  picPanel.Top = 60
  picPanel.Left = c_SpaceLeft - 30  ' made button panel a little bigger than the others
  picPanel.Height = tbToolPanelA.Height + tbToolPanelB.Height + 30
  
  For i = 0 To ucPanelA.count - 1
    ucPanelA(i).Left = c_SpaceLeft
    ucPanelA(i).Visible = False
  Next i

  ShapeGe.InitNew
  ShapeGe.Rulers = False
  ShapeGe.DrawingWidth = 0.01
  ShapeGe.DrawingHeight = 0.01
  ShapeGe.MarginDisplay = False
  ShapeGe.ZoomPage
  ShapeGe.ConnectionMode = False
  ShapeGe.GrabHandlesEnabled = False
  
  ShowPanel 0
  
  ' initialize CG stuff
  m_nHitSelectionSize = 1 '  64th
  m_nObjectSnapSize = 4  ' 64ths
  txtObjectHit.Text = m_nHitSelectionSize
  txtObjectSnap.Text = m_nObjectSnapSize
  m_dSpaceX = 0.25
  m_dSpaceY = 0.25
  m_SnapMult = 1#
  m_bDoingUpdate = False
  
  ' set pen/brush defaults to BLACK
  UpdateColors

  m_bDoIt = False
  m_WidthCur = 0
  m_HeightCur = 0
  m_WidthNew = 0
  m_HeightNew = 0
  
  lblWidthCur.Caption = Format(m_WidthCur, "0.00000")
  txtWidthNew.Text = Format(m_WidthNew, "0.00000")
  lblHeightCur.Caption = Format(m_HeightCur, "0.00000")
  txtHeightNew.Text = Format(m_HeightNew, "0.00000")

  '
  InitFontsPanel

End Sub

'--------------------------
Public Sub GeSelExtents()
  Dim i As Integer
  Dim nCount As Integer
  Dim nSel As Long
  Dim nArray As Integer
  
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  '
  nSel = m_GeCtrl.SelNumberOfObjects
  m_GeCtrl.GetSelExtents m_dleft, m_dBottom, m_dRight, m_dtop
  
  m_dCenterX = (m_dRight - m_dleft) / 2 + m_dleft
  m_dCenterY = (m_dtop - m_dBottom) / 2 + m_dBottom
  lblWidthCur = Format(m_dRight - m_dleft, "0.00000")
  txtWidthNew = Format(lblWidthCur, "0.00000")

  lblHeightCur = Format(m_dtop - m_dBottom, "0.00000")
  txtHeightNew = Format(lblHeightCur, "0.00000")
  txtRotateX.Text = Format(m_dleft, "0.00000")
  txtRotateY.Text = Format(m_dBottom, "0.00000")

  m_X = m_dleft
  m_Y = m_dBottom

  txtQty.Text = ""
  btnQty.Enabled = False:  btnQty.Caption = "Set Qty"
  
  If nSel = 1 Then
    Dim GeID As Long
    Dim nGeType As Integer
    GeID = m_GeCtrl.GetFirstSelObject
    If GeID > 0 Then
      m_GeCtrl.CurrentPropertyID = GeID  ' move into selector
      nGeType = m_GeCtrl.ObjectType
      '' look for smartshape
      If nGeType = EGeObjType.UserGroup Then
        m_GeCtrl.ShapeSetCurrent GeID
        ' determine if extrudable SmartShape (shapearray)
        If m_GeCtrl.CanExtrude Then
          nArray = m_GeCtrl.ShapeNumArrayElements
          ' If nArray > 0 Then
          txtQty.Text = nArray
          txtQty.Enabled = True
          btnQty.Enabled = True
          
          ' look for field with tag 'dimension', if found get size
          ' then set up dialog to ask user for distance, not quantity
          Dim strName As String, strVal As String
          Dim nGeIDA As Long
          btnQty.Caption = "Set Qty"
          btnQty.ToolTipText = "Set the number of elements in Shape Array"
      
          m_lSetArrayDistance = 0#
          nCount = m_GeCtrl.ShapeFieldCount
          For i = 0 To nCount - 1
            If m_GeCtrl.ShapeSetCurrentField(i) Then
              If m_GeCtrl.ShapeGetFieldType = 1 Then      ' text field
                strName = ""
                m_GeCtrl.ShapeGetFieldNameValue strName, strVal
                If InStr(strName, "imension") > 0 Then
                  btnQty.Caption = "Set Len"
                  btnQty.ToolTipText = "Set the length of the Shape Array.(" & strVal & " in increments)."
                  
                  m_lSetArrayDistance = CSng(strVal)
                  
                  txtQty.Text = nArray * m_lSetArrayDistance
                  Exit For
                End If
              End If
            End If
          Next i
        End If  ' shapearray
      End If    ' smartshape
      m_GeCtrl.CurrentPropertyID = 0  ' reset selector
    End If    ' geid > 0
  End If
  
End Sub

'--------------------------
Private Sub btnCCW_Click()
  Dim sVal As Single
  Dim dLeft As Single, dBottom As Single
  Dim dRight As Single, dTop As Single
  
  On Error Resume Next
  
  If m_GeCtrl Is Nothing Then Exit Sub
  
  If chkCenter.Value Then
    m_GeCtrl.GetSelExtents dLeft, dBottom, dRight, dTop
    m_X = dLeft + ((dRight - dLeft) / 2)
    m_Y = dBottom + ((dTop - dBottom) / 2)
  Else
    m_X = txtRotateX.Text
    m_Y = txtRotateY.Text
  End If

  If Not (m_GeCtrl Is Nothing) Then
    sVal = txtAngle.Text
    If sVal < 0 Then sVal = 0 - sVal
    m_GeCtrl.SelRotate m_X, m_Y, sVal ' 5
  End If
  m_GeCtrl.SetFocus
End Sub

'--------------------------
Private Sub btnConvert_Click(index As Integer)
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  m_GeCtrl.BeginUndoTransaction
  Select Case index
  Case 2
     m_GeCtrl.ConvertArcToPline
  Case 4
     m_GeCtrl.ConvertPgonToPline
  Case 0
     m_GeCtrl.ConvertPlinesToPline
  Case 1
     m_GeCtrl.ConvertPlineToPgon
  Case 3
     m_GeCtrl.ConvertRectToPolygon
  Case 5
    m_GeCtrl.ConvertBezierToPolyline
  Case 6
    m_GeCtrl.ConvertSplitPline (1)
  Case 8
    If m_GeCtrl.CanConvertPolygonsToPolyPolygon Then
      m_GeCtrl.ConvertPolygonsToPolyPolygon
    End If
  Case 7
    If m_GeCtrl.CanExplodePolyPolygon Then
      m_GeCtrl.ExplodePolyPolygon
    End If
  End Select
  m_GeCtrl.EndUndoTransaction
  m_GeCtrl.SetFocus
End Sub

'--------------------------
Private Sub btnCW_Click()
  ' CW (-ve)
  Dim sVal As Single
  Dim dLeft As Single, dBottom As Single
  Dim dRight As Single, dTop As Single
  
  On Error Resume Next
  
  If m_GeCtrl Is Nothing Then Exit Sub
  
  If chkCenter.Value Then
    m_GeCtrl.GetSelExtents dLeft, dBottom, dRight, dTop
    m_X = dLeft + ((dRight - dLeft) / 2)
    m_Y = dBottom + ((dTop - dBottom) / 2)
  Else
    m_X = txtRotateX.Text
    m_Y = txtRotateY.Text
  End If
  
  If Not (m_GeCtrl Is Nothing) Then
    sVal = txtAngle.Text
    If sVal > 0 Then sVal = 0 - sVal
    m_GeCtrl.SelRotate m_X, m_Y, sVal    '-5
  End If
  m_GeCtrl.SetFocus
End Sub


'===================================================================================
' COLORS
'===================================================================================
'--------------------------
Public Sub GetGeColors()
  Dim i As Integer
  Dim R As Integer
  Dim G As Integer
  Dim B As Integer
  Dim FLAGS As Integer
  
  On Error Resume Next
  
  With tbColorA
    For i = 0 To 5
      m_GeCtrl.GetPaletteEntry m_aColors(i).nDX, R, G, B, FLAGS
      m_aColors(i).R = R:    m_aColors(i).G = G:    m_aColors(i).B = B: m_aColors(i).FLAGS = FLAGS
      .ButtonToolTipText(i + 1) = "Color index " & m_aColors(i).nDX
    Next i
  End With
  With tbColorB
    For i = 0 To 5
      m_GeCtrl.GetPaletteEntry m_aColors(i + 6).nDX, R, G, B, FLAGS
      m_aColors(i + 6).R = R:  m_aColors(i + 6).G = G:  m_aColors(i + 6).B = B: m_aColors(i + 6).FLAGS = FLAGS
      .ButtonToolTipText(i + 1) = "Color index " & m_aColors(i + 6).nDX
    Next i
  End With
  UpdateColors
  
End Sub
''------------------------------
Private Sub UpdateColors()
  ' update buttons that control the colors
  Dim i As Integer
  
  On Error Resume Next
  ' uncheck all
  With tbColorA
    For i = 0 To 5
     .ButtonColor(i + 1) = RGB(m_aColors(i).R, m_aColors(i).G, m_aColors(i).B)
     .ButtonChecked(i + 1) = False
     .ButtonCaption(i + 1) = ""
    Next i
  End With
  With tbColorB
    For i = 0 To 5
     .ButtonColor(i + 1) = RGB(m_aColors(i + 6).R, m_aColors(i + 6).G, m_aColors(i + 6).B)
     .ButtonChecked(i + 1) = False
     .ButtonCaption(i + 1) = ""
    Next i
  End With
  
  ' check the required one
  Select Case m_nSelectColor
    Case 0:  tbColorA.ButtonChecked("C1") = True
    Case 1:  tbColorA.ButtonChecked("C2") = True
    Case 2:  tbColorA.ButtonChecked("C3") = True
    Case 3:  tbColorA.ButtonChecked("C4") = True
    Case 4:  tbColorA.ButtonChecked("C5") = True
    Case 5:  tbColorA.ButtonChecked("C6") = True
    
    Case 6:  tbColorB.ButtonChecked("C1") = True
    Case 7:  tbColorB.ButtonChecked("C2") = True
    Case 8:  tbColorB.ButtonChecked("C3") = True
    Case 9:  tbColorB.ButtonChecked("C4") = True
    Case 10:  tbColorB.ButtonChecked("C5") = True
    Case 11:  tbColorB.ButtonChecked("C6") = True
  End Select
End Sub

'--------------------------
Private Sub tbColorA_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  ' top colors
  Select Case UCase(ButtonKey)
    Case "C1":  m_nSelectColor = 0
    Case "C2":  m_nSelectColor = 1
    Case "C3":  m_nSelectColor = 2
    Case "C4":  m_nSelectColor = 3
    Case "C5":  m_nSelectColor = 4
    Case "C6":  m_nSelectColor = 5
  End Select
  UpdateColors
End Sub

'--------------------------
Private Sub tbColorB_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  ' bottom colors
  Select Case UCase(ButtonKey)
    Case "C1":  m_nSelectColor = 6
    Case "C2":  m_nSelectColor = 7
    Case "C3":  m_nSelectColor = 8
    Case "C4":  m_nSelectColor = 9
    Case "C5":  m_nSelectColor = 10
    Case "C6":  m_nSelectColor = 11
  End Select
  UpdateColors
End Sub

''--------------------------

'--------------------------
Private Sub btnColor_Click(index As Integer)
  Dim nDX As Long
  Dim R As Integer
  Dim G As Integer
  Dim B As Integer
  Dim FLAGS As Integer
  Dim GeID As Long
  
  On Error Resume Next
  
  If m_GeCtrl Is Nothing Then Exit Sub
  If m_GeCtrl.SelNumberOfObjects < 1 Then Exit Sub
 
  If index = 0 Then  ' get pen
    GeID = m_GeCtrl.GetLastSelObject
    m_GeCtrl.CurrentPropertyID = GeID
    nDX = m_GeCtrl.PenColor
    m_GeCtrl.GetPaletteEntry nDX, R, G, B, FLAGS
    m_aColors(m_nSelectColor).nDX = nDX
    m_aColors(m_nSelectColor).R = R
    m_aColors(m_nSelectColor).G = G
    m_aColors(m_nSelectColor).B = B
    m_aColors(m_nSelectColor).FLAGS = FLAGS
    UpdateColors
  End If
  
  If index = 1 Then  ' set pen
    m_GeCtrl.BeginUndoTransaction
    nDX = m_aColors(m_nSelectColor).nDX
    GeID = m_GeCtrl.GetFirstSelObject
    Do While GeID > 0
      m_GeCtrl.CurrentPropertyID = GeID
      If m_GeCtrl.PenStyle = GEPS_NULL Then   ' if there was no line style, force one
        m_GeCtrl.PenStyle = GEPS_SOLID
      End If
      m_GeCtrl.PenColor = nDX
      GeID = m_GeCtrl.GetNextSelObject(GeID)
    Loop
    m_GeCtrl.EndUndoTransaction
  End If
  
  If index = 2 Then  ' get brush
    GeID = m_GeCtrl.GetLastSelObject
    m_GeCtrl.CurrentPropertyID = GeID
    nDX = m_GeCtrl.BrushColor
    m_GeCtrl.GetPaletteEntry nDX, R, G, B, FLAGS
    m_aColors(m_nSelectColor).nDX = nDX
    m_aColors(m_nSelectColor).R = R
    m_aColors(m_nSelectColor).G = G
    m_aColors(m_nSelectColor).B = B
    m_aColors(m_nSelectColor).FLAGS = FLAGS
    UpdateColors
  End If

  If index = 3 Then  ' set brush
    m_GeCtrl.BeginUndoTransaction
    nDX = m_aColors(m_nSelectColor).nDX
    GeID = m_GeCtrl.GetFirstSelObject
    Do While GeID > 0
      m_GeCtrl.CurrentPropertyID = GeID
      If m_GeCtrl.BrushStyle <> GEBS_SOLID Then
        m_GeCtrl.BrushStyle = GEBS_SOLID
      End If
      m_GeCtrl.BrushColor = nDX
      GeID = m_GeCtrl.GetNextSelObject(GeID)
    Loop
    m_GeCtrl.EndUndoTransaction
  End If
  
  If index = 4 Then  ' set no pen
    m_GeCtrl.BeginUndoTransaction
    GeID = m_GeCtrl.GetFirstSelObject
    Do While GeID > 0
      m_GeCtrl.CurrentPropertyID = GeID
      If m_GeCtrl.PenStyle <> GEPS_NULL Then
        m_GeCtrl.PenStyle = GEPS_NULL
      End If
      GeID = m_GeCtrl.GetNextSelObject(GeID)
    Loop
    m_GeCtrl.EndUndoTransaction
  End If
  
  If index = 5 Then  ' set no brush
    m_GeCtrl.BeginUndoTransaction
    GeID = m_GeCtrl.GetFirstSelObject
    Do While GeID > 0
      m_GeCtrl.CurrentPropertyID = GeID
      If m_GeCtrl.BrushStyle <> GEBS_NULL Then
        m_GeCtrl.BrushStyle = GEBS_NULL
      End If
      GeID = m_GeCtrl.GetNextSelObject(GeID)
    Loop
    m_GeCtrl.EndUndoTransaction
  End If
  '
  m_GeCtrl.CurrentPropertyID = 0  ' reset selector
  m_GeCtrl.SetFocus
  
End Sub


'===================================================================================
'===================================================================================
'--------------------------
Private Sub btnScale_Click()
  If m_GeCtrl Is Nothing Then Exit Sub
  
  ' get current position, as objects may have moved
  m_GeCtrl.GetSelExtents m_dleft, m_dBottom, m_dRight, m_dtop
  
  If VerifyConvertScaleValues(txtWidthNew.Text, txtHeightNew.Text, m_WidthNew, m_HeightNew) Then
    'm_bDoIt = True
    DoSelScale
    GeSelExtents
  End If
  txtScale.Text = "1.000"
  m_GeCtrl.SetFocus
End Sub

'--------------------------
Private Sub tbbtnSnap_BeforeButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String, Cancel As Boolean)
  ' Snap on/Off
  Dim bVal As Boolean
  If m_bDoingUpdate Then Exit Sub
  If UCase(ButtonKey) = "SNAP" Then
    bVal = Not tbbtnSnap.ButtonChecked(ButtonIndex)
    m_GeCtrl.Snap = bVal
    tbbtnSnap.ButtonChecked(ButtonIndex) = bVal
    If Not m_frmActive Is Nothing Then m_frmActive.UpdateToolbarButtons
    UpdateCurrentSnap
    SetGeFocus
    Cancel = True
  End If
End Sub


'--------------------------
Private Sub cbShapeLibName_Click()
  Dim strName As String
  
  If m_bDoingUpdate = True Then Exit Sub
  
  If m_strShapeLibName = cbShapeLibName.List(cbShapeLibName.ListIndex) Then Exit Sub
  
  On Error Resume Next
  ClearShapeGe
  cbShapeFolder.Clear
  lbShapes.Clear
  
  m_strShapeLibPath = GetPath(cbShapeLibName.List(cbShapeLibName.ListIndex))
  If Len(m_strShapeLibPath) > 0 Then
    strName = m_strShapeLibPath & "\"
  End If
  m_strShapeLibName = cbShapeLibName.List(cbShapeLibName.ListIndex)
  strName = strName & m_strShapeLibName
  PopulateShapeFolderListBox strName
  
  m_strLibrary = m_strShapeLibName
  m_frmActive.SetStatusText " Library name: " & strName
End Sub


'--------------------------
Private Sub lbShapes_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
  If m_frmActive Is Nothing Then Exit Sub
  m_frmActive.SetStatusText " Shape name: " & lbShapes.List(lbShapes.ListIndex)
End Sub

'--------------------------
Private Sub lbShapes_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
  Dim lXPoint As Long
  Dim lYPoint As Long
  Dim lIndex As Long

  If m_frmActive Is Nothing Then Exit Sub
  
  lXPoint = CLng(X / Screen.TwipsPerPixelX)
  lYPoint = CLng((Y / Screen.TwipsPerPixelY))

  With lbShapes
    ' get selected item from list
    lIndex = SendMessage(.HWND, LB_ITEMFROMPOINT, 0, ByVal ((lYPoint * 65536) + lXPoint))
    If (lIndex >= 0) And (lIndex <= .ListCount) Then
      m_frmActive.SetStatusText " Shape name: " & .List(lIndex)
      lbShapes.ToolTipText = "  " & .List(lIndex) & "  "
    End If
  End With

End Sub

'======================================================================================
' Handle the invisible menu
'======================================================================================
'--------------------------
Private Sub mnuEditItem_Click(index As Integer)
  Dim strText As String
  
  Select Case index
    Case 0  ' copy Ctrl-C
      If TypeOf UserControl.ActiveControl Is VB.TextBox Then
        strText = UserControl.ActiveControl.Text
        Clipboard.SetText strText
      End If
    Case 1  ' cut Ctrl-X
      If TypeOf UserControl.ActiveControl Is VB.TextBox Then
        strText = UserControl.ActiveControl.Text
        Clipboard.SetText strText
      End If
    Case 2  ' paste Ctrl-V
      If TypeOf UserControl.ActiveControl Is VB.TextBox Then
        strText = Clipboard.GetText
        UserControl.ActiveControl.Text = strText
      End If
  End Select
  
End Sub

'======================================================================================
' Toolbars (panel selection) - buttons that control the panel selection
'======================================================================================
''------------------------------
Private Sub UpdateControlPanel()
  ' update buttons that control the panel selection
  Dim i As Integer
  
  On Error Resume Next
  ' uncheck all
  With tbToolPanelA
    For i = 1 To .ButtonCount
    .ButtonChecked(i) = False
    Next i
  End With
  With tbToolPanelB
    For i = 1 To .ButtonCount
    .ButtonChecked(i) = False
    Next i
  End With
  With tbToolPanelC
    For i = 1 To .ButtonCount
    .ButtonChecked(i) = False
    Next i
  End With
  
  ' check the required one
  Select Case m_nLastPanel
    Case cMP_SNAP:  tbToolPanelA.ButtonChecked("SNAP") = True
    Case cMP_FORMAT:  tbToolPanelA.ButtonChecked("FORMAT") = True
    Case cMP_LAYERS:  tbToolPanelA.ButtonChecked("LAYERS") = True
    
    Case cMP_GENERAL:  tbToolPanelB.ButtonChecked("GENERAL") = True
    Case cMP_SHAPES:  tbToolPanelB.ButtonChecked("SHAPES") = True
    Case cMP_PREFER:  tbToolPanelB.ButtonChecked("PREF") = True
    
    Case cMP_SET1:  tbToolPanelC.ButtonChecked("SET1") = True
    Case cMP_SET2:  tbToolPanelC.ButtonChecked("SET2") = True
    Case cMP_MOVE:  tbToolPanelC.ButtonChecked("SET3") = True
   
  End Select
End Sub


''------------------------------
Private Sub tbToolPanelA_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  '
  Select Case UCase(ButtonKey)
    Case "SNAP":  ShowPanel cMP_SNAP
    Case "FORMAT":  ShowPanel cMP_FORMAT
    Case "LAYERS":  ShowPanel cMP_LAYERS
  End Select
  SetGeFocus
End Sub
''------------------------------
Private Sub tbToolPanelB_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  '
  Select Case UCase(ButtonKey)
    Case "GENERAL":  ShowPanel cMP_GENERAL
    Case "SHAPES":  ShowPanel cMP_SHAPES
    Case "PREF":  ShowPanel cMP_PREFER
  End Select
  SetGeFocus
End Sub

Private Sub tbToolPanelC_ButtonClick(ByVal ButtonIndex As Integer, ByVal ButtonKey As String)
  Select Case UCase(ButtonKey)
    Case "SET1":  ShowPanel cMP_SET1
    Case "SET2":  ShowPanel cMP_SET2
    ' for now it is blank
    Case "SET3":  ShowPanel cMP_MOVE
  End Select
  SetGeFocus
End Sub

'======================================================================================
' Public Functions
'======================================================================================
'--------------------------
Public Function MovePanelWithTools(bMode As Boolean)
  ' true = rolled up
  If bMode = True Then
    HidePanels
  Else
    ShowPanels
  End If
End Function

'--------------------------
Public Sub HidePanels()
  Dim i As Integer
  ' hide everything
  picPanel.Visible = False
  For i = 0 To ucPanelA.count - 1
    ucPanelA(i).Visible = False
  Next i
End Sub

'--------------------------
Public Sub ShowPanels()
  ShowPanel m_nLastPanel
End Sub


'--------------------------
Public Sub ShowPanel(index As Integer)
  Dim i As Integer
  Dim j As Integer
  Dim nPanel As Integer
  Dim StartPos As Long

  ' top buttons
  picPanel.Visible = True
  picPanel.Move 0, 0
  
  ' hide all Panels
  For i = 0 To ucPanelA.count - 1
    ucPanelA(i).Visible = False
  Next i
  
  m_nLastPanel = index
  
' This controls if the third row of buttons is usable
#If True Then
  tbToolPanelC.Visible = True
'  picPanel.Height = 645 + tbToolPanelC.Height
  picPanel.Height = tbToolPanelA.Height + tbToolPanelB.Height + tbToolPanelC.Height
#Else
  tbToolPanelC.Visible = True
  tbToolPanelC.ButtonVisible("SET1") = False
  tbToolPanelC.ButtonVisible("SET2") = False
  picPanel.Height = tbToolPanelA.Height + tbToolPanelB.Height + tbToolPanelC.Height
#End If
  
  ' holder of all buttons (top)
  'picPanel.Height is modified in sub 'initilize'
  StartPos = c_SpaceFromTop + picPanel.Top + picPanel.Height
  
  Select Case index
    Case cMP_SNAP
      DoShowPanel cCURSOR_SNAP, StartPos ' snap
      DoShowPanel cOBJECT_SNAP, StartPos ' object snap
    
    Case cMP_FORMAT
      DoShowPanel cSEPARATE, StartPos ' separate/distrbute
      DoShowPanel cSCALE, StartPos ' scale
      DoShowPanel cROTATE, StartPos ' rotate
      DoShowPanel cALIGNSNAP, StartPos ' AlignToSnap
    
    Case cMP_LAYERS
      DoShowPanel cLAYERS, StartPos   ' layers
      EnumLayers

    Case cMP_SHAPES
      DoShowPanel cSHAPES, StartPos   ' shapes
      DoEvents    ' seems to work today (Nov 1,00)
      ShowShape lbShapes.ListIndex

    Case cMP_GENERAL
      DoShowPanel cCOLORS, StartPos   ' colors
      DoShowPanel cCONVERT, StartPos ' convert
    
    Case cMP_PREFER
      DoShowPanel cFONT, StartPos ' font
      DoShowPanel cHIT_SENSISTIVITY, StartPos ' hit sens
    
    Case cMP_SET1
      DoShowPanel cSET1, StartPos
    Case cMP_SET2
      DoShowPanel cSET2, StartPos
    Case cMP_MOVE
      DoShowPanel cMOVE, StartPos
      DoShowPanel cARRAY, StartPos
      
  End Select
  '
  UpdateControlPanel  ' button status

End Sub

'--------------------------
Private Sub DoShowPanel(nPanel As Integer, StartPos As Long)
  ' show 1 panel
  On Error Resume Next
  
  ' reposition panel to fit
  Select Case nPanel
    ''
'    Case cSHAPES        ' make panel fit my height
'      ucPanelA(nPanel).Top = StartPos
'      ucPanelA(nPanel).Height = UserControl.Height - StartPos
'      StartPos = ucPanelA(nPanel).Top + ucPanelA(nPanel).Height + c_SpaceFromTop
'      ucPanelA(nPanel).Visible = True
    
    Case cFONT
      #If USE_BITMAPZOOM Then
        picZoomView.Visible = True
        picZoomView.Left = 0
        picZoomView.Width = ucPanelA(nPanel).Width
      #Else
        picZoomView.Visible = False
        ucPanelA(nPanel).Height = btnFontHeight.Top + btnFontHeight.Height + 90
      #End If
      '
      ucPanelA(nPanel).Top = StartPos
      StartPos = ucPanelA(nPanel).Top + ucPanelA(nPanel).Height + c_SpaceFromTop
      ucPanelA(nPanel).Visible = True
    
    ''
    Case Else           ' just reposition panel
      ucPanelA(nPanel).Top = StartPos
      StartPos = ucPanelA(nPanel).Top + ucPanelA(nPanel).Height + c_SpaceFromTop
      ucPanelA(nPanel).Visible = True
  End Select
  
  ' stretch controls on panel as required
  Select Case nPanel
    ''
    Case cSHAPES
      picShpBottom.BorderStyle = 0    ' flat
      picShpBottom.Move 30, _
          ucPanelA(nPanel).Height - picShpBottom.Height - 30, _
          ucPanelA(nPanel).Width - 60, _
          picShpBottom.Height
      lbShapes.Move lbShapes.Left, lbShapes.Top, lbShapes.Width, _
            picShpBottom.Top - lbShapes.Top
      '
    ''
    Case cLAYERS
      picLayers.BorderStyle = 0    ' flat
      picDefaultLayer.BorderStyle = 0    ' flat
'      picLayerBottom.Move 30, _
'          ucPanelA(nPanel).Height - picLayerBottom.Height - 30, _
'          ucPanelA(nPanel).Width - 60, _
'          picLayerBottom.Height
      
      picLayers.Move 30, picLayers.Top, ucPanelA(nPanel).Width - 60, picLayers.Height
      FGProps.Move 0, 0, picLayers.Width, picLayers.Height
      
  End Select
  
End Sub

'--------------------------
Public Function GetPanel() As Integer
  GetPanel = m_nLastPanel
End Function


'======================================================================================
' Private Functions
'======================================================================================
'**********************************************************************
'**********************************************************************
' code from frmToolBox
'--------------------------
Public Property Let SnapShapesToCursor(ByVal bVal As Boolean)
  Dim bPrev As Boolean
  If m_GeCtrl Is Nothing Then Exit Property
  bPrev = m_bDoingUpdate
  m_bDoingUpdate = True
  If bVal Then
    If chkSnapToShape.Value = 0 Then chkSnapToShape.Value = 1
  Else
    If chkSnapToShape.Value <> 0 Then chkSnapToShape.Value = 0
  End If
  m_bDoingUpdate = bPrev
End Property

'--------------------------
Public Sub UpdateCurrentSnap()
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  ShowCurrentSnap m_GeCtrl.SnapHorz, m_GeCtrl.SnapVert, m_GeCtrl.Snap
End Sub

'--------------------------
Public Function UpdateControlsFromGe()
  ' update to new GeCtrl state, the data is stored in the CG control
  Dim dVal As Single
  
  On Error Resume Next
  
  If m_GeCtrl Is Nothing Then Exit Function
  m_bDoingUpdate = True
  UpdateObjSnapFromGe
  
  GetGeColors
  UpdateFontFromGe
  
  If Not m_bFirstSensSnap Then
    m_bFirstSensSnap = True
    '
    If m_nHitSelectionSize < 1 Then m_nHitSelectionSize = 2
    HitSelectionSize = m_nHitSelectionSize
    txtObjectHit.Text = m_nHitSelectionSize
    '
    If m_nObjectSnapSize < 1 Then m_nObjectSnapSize = 4
    ObjectSnapSize = m_nObjectSnapSize
    txtObjectSnap.Text = m_nObjectSnapSize
  Else
    dVal = m_GeCtrl.ObjectSnapSize
    m_nObjectSnapSize = dVal * c_HitUnits ' 64
    txtObjectSnap.Text = m_nObjectSnapSize
  End If
  ''
  GeSelExtents  ' update sel extents
  ''
  EnumLayers    ' layers
  ''
  If m_GeCtrl.DrawConnections Then
    chkShowConnectionPts.Value = 1
  Else
    chkShowConnectionPts.Value = 0
  End If
  ''
  If m_GeCtrl.DrawInsertionPoints Then
    chkDrawInsertionPoints.Value = 1
  Else
    chkDrawInsertionPoints.Value = 0
  End If
  ''
  If m_GeCtrl.DrawFilledTransparent Then
    chkDrawFilledTransparent.Value = 1
  Else
    chkDrawFilledTransparent.Value = 0
  End If
  ''
  If m_GeCtrl.SnapShapesToCursor Then
    chkSnapToShape.Value = 1
  Else
    chkSnapToShape.Value = 0
  End If
  ''
  If m_GeCtrl.SnapToSelection Then
    chkSnapTosel.Value = 1
  Else
    chkSnapTosel.Value = 0
  End If
  
  ShowCurrentSnap m_GeCtrl.SnapHorz, m_GeCtrl.SnapVert, m_GeCtrl.Snap
  '
  m_bDoingUpdate = False
End Function

'--------------------------
Public Sub UpdateToolButtons()
  
  On Error Resume Next
  m_bDoingUpdate = True
  
  UpdateObjSnapFromGe
  tbbtnSnap.ButtonChecked("SNAP") = m_GeCtrl.Snap
  
  UpdateCurrentSnap
  GeSelExtents  ' extents
  '
  UpdateFontFromGe
  
  m_bDoingUpdate = False
End Sub

'--------------------------
Private Property Get IsShowingLayers() As Boolean
  If ucPanelA(cLAYERS).Visible = True Then IsShowingLayers = True
End Property
'--------------------------
Private Property Get IsShowingFont() As Boolean
  If ucPanelA(cFONT).Visible = True Then IsShowingFont = True
End Property


'=================================================================
' INI file
'=================================================================
'------------------------------
Public Function GetIniSettings()
  ' get the Settings for the controls on this panel from INI file
  Dim dVal As Double
  Dim strVal As String
  Dim strDflt As String
  Dim nVal As Integer
  Dim nValObjSnap As Integer
  Dim i As Integer
  
  On Error Resume Next
  
  m_bDoingUpdate = True
    
  ' Hit detection
  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_OBJECTHITSENS, 1)
  If nVal > 0 Then m_nHitSelectionSize = nVal
  txtObjectHit.Text = m_nHitSelectionSize
  
  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_OBJECTSNAPSENS, 4)
  If nVal > 0 Then m_nObjectSnapSize = nVal
  txtObjectSnap.Text = m_nObjectSnapSize
    
  ' Object SNAP
  nValObjSnap = AppGetProfileInt(INISECTION_UAO, INIENTRY_OBJECTSNAP, 0)
  UpdateObjSnapControls nValObjSnap, False
    
  ' SNAP
  strDflt = "1"
  ''
  strVal = AppGetProfileString(INISECTION_UAO, INIENTRY_SNAP1X, strDflt)
  dVal = CDbl(strVal)
  m_aSnap(0).X = dVal
  strVal = AppGetProfileString(INISECTION_UAO, INIENTRY_SNAP1Y, strDflt)
  dVal = CDbl(strVal)
  m_aSnap(0).Y = dVal
  ''
  strDflt = "1"
  strVal = AppGetProfileString(INISECTION_UAO, INIENTRY_SNAP2X, strDflt)
  dVal = CDbl(strVal)
  m_aSnap(1).X = dVal
  strVal = AppGetProfileString(INISECTION_UAO, INIENTRY_SNAP2Y, strDflt)
  dVal = CDbl(strVal)
  m_aSnap(1).Y = dVal
  ''
  strDflt = "1"
  strVal = AppGetProfileString(INISECTION_UAO, INIENTRY_SNAP3X, strDflt)
  dVal = CDbl(strVal)
  m_aSnap(2).X = dVal
  strVal = AppGetProfileString(INISECTION_UAO, INIENTRY_SNAP3Y, strDflt)
  dVal = CDbl(strVal)
  m_aSnap(2).Y = dVal
  ''
  strDflt = "1"
  strVal = AppGetProfileString(INISECTION_UAO, INIENTRY_SNAP4X, strDflt)
  dVal = CDbl(strVal)
  m_aSnap(3).X = dVal
  strVal = AppGetProfileString(INISECTION_UAO, INIENTRY_SNAP4Y, strDflt)
  dVal = CDbl(strVal)
  m_aSnap(3).Y = dVal
  ''
  strDflt = "1"
  strVal = AppGetProfileString(INISECTION_UAO, INIENTRY_SNAPMULT, strDflt)
  dVal = CDbl(strVal)
  m_SnapMult = dVal
  ''
  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_DRAWTRANSPARENT, 0)
  chkDrawFilledTransparent.Value = nVal
  If Not m_GeCtrl Is Nothing Then
    m_GeCtrl.DrawFilledTransparent = nVal
  End If

  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_SHOWINSERTION, 0)
  chkDrawInsertionPoints.Value = nVal
  If Not m_GeCtrl Is Nothing Then
    m_GeCtrl.DrawInsertionPoints = nVal
  End If
  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_SHOWCONNECTIONS, 1)
  chkShowConnectionPts.Value = nVal
  If Not m_GeCtrl Is Nothing Then
    m_GeCtrl.DrawConnections = nVal
  End If
  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_SNAPTOSELECTION, 0)
  chkSnapTosel.Value = nVal
  If Not m_GeCtrl Is Nothing Then
    m_GeCtrl.SnapToSelection = nVal
  End If
  nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_SNAPTOSHAPE, 0)
  chkSnapToShape.Value = nVal
  If Not m_GeCtrl Is Nothing Then
    m_GeCtrl.SnapShapesToCursor = nVal
  End If

  UpdateSnapButtonCaptions
  ''
  ' Colors
  For i = 0 To 11
    nVal = AppGetProfileInt(INISECTION_UAO, INIENTRY_COLOR & i, CInt(m_aColors(i).nDX))
    m_aColors(i).nDX = nVal
  Next i
  ''
    
  m_bDoingUpdate = False
End Function

'------------------------------
Public Function SaveIniSettings()
  ' Save the Settings to INI file
  Dim strVal As String
  Dim nVal As Integer
  Dim bVal As Boolean
  Dim i As Integer
  
  On Error Resume Next
  
  nVal = GetPanel
  AppWriteProfileInt INISECTION_UAO, INIENTRY_TOOLPANELNUMBER, nVal
  
  ' Hit detection
  nVal = m_nHitSelectionSize
  AppWriteProfileInt INISECTION_UAO, INIENTRY_OBJECTHITSENS, nVal
  nVal = m_nObjectSnapSize
  AppWriteProfileInt INISECTION_UAO, INIENTRY_OBJECTSNAPSENS, nVal
  ''
  strVal = m_aSnap(0).X
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAP1X, strVal
  strVal = m_aSnap(0).Y
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAP1Y, strVal
  ''
  strVal = m_aSnap(1).X
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAP2X, strVal
  strVal = m_aSnap(1).Y
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAP2Y, strVal
  ''
  strVal = m_aSnap(2).X
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAP3X, strVal
  strVal = m_aSnap(2).Y
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAP3Y, strVal
  ''
  strVal = m_aSnap(3).X
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAP4X, strVal
  strVal = m_aSnap(3).Y
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAP4Y, strVal
  ''
  strVal = m_SnapMult
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAPMULT, strVal
  ''
  nVal = chkDrawFilledTransparent.Value
  AppWriteProfileInt INISECTION_UAO, INIENTRY_DRAWTRANSPARENT, nVal
  
  
  DoGetObjectSnapSettings nVal, bVal
  AppWriteProfileInt INISECTION_UAO, INIENTRY_OBJECTSNAP, nVal
  
  strVal = chkSnapTosel.Value
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAPTOSELECTION, strVal
  strVal = chkSnapToShape.Value
  AppWriteProfileString INISECTION_UAO, INIENTRY_SNAPTOSHAPE, strVal
  nVal = chkDrawInsertionPoints.Value
  AppWriteProfileInt INISECTION_UAO, INIENTRY_SHOWINSERTION, nVal
  nVal = chkShowConnectionPts.Value
  AppWriteProfileInt INISECTION_UAO, INIENTRY_SHOWCONNECTIONS, nVal

  ' Colors
  For i = 0 To 11
    AppWriteProfileInt INISECTION_UAO, INIENTRY_COLOR & i, CInt(m_aColors(i).nDX)
  Next i
  ''
End Function

Private Sub txtHeightNew_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub



Private Sub txtHSpace_GotFocus()
  SelectAllTextControlText txtHSpace
End Sub

Private Sub txtHSpace_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

Private Sub txtHSpace_LostFocus()
  If Len(txtHSpace.Text) < 1 Then
    txtHSpace.Text = 0
  End If
End Sub

Private Sub txtIPX_GotFocus()
  SelectAllTextControlText txtIPX
End Sub

Private Sub txtIPX_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or KeyAscii = 45 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub


Private Sub txtIPX_LostFocus()
  If Len(txtIPX.Text) < 1 Then
    txtIPX.Text = "0"
  End If
End Sub

Private Sub txtIPY_GotFocus()
  SelectAllTextControlText txtIPY
End Sub

Private Sub txtIPY_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or KeyAscii = 45 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

Private Sub txtIPY_LostFocus()
  If Len(txtIPY.Text) < 1 Then
    txtIPY.Text = "0"
  End If
End Sub


Private Sub txtNCols_GotFocus()
  SelectAllTextControlText txtNCols
End Sub

Private Sub txtNCols_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

Private Sub txtNCols_LostFocus()
  If Len(txtNCols.Text) < 1 Then
    txtNCols.Text = 1
  End If
  If val(txtNCols.Text) < 1 Then
    txtNCols.Text = 1
  End If
End Sub



Private Sub txtNRows_GotFocus()
  SelectAllTextControlText txtNRows
End Sub

Private Sub txtNRows_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

Private Sub txtNRows_LostFocus()
  If Len(txtNRows.Text) < 1 Then
    txtNRows.Text = 1
  End If
  If val(txtNRows.Text) < 1 Then
    txtNRows.Text = 1
  End If
End Sub

'======================================================================================
' Misc (hit)
'======================================================================================
'--------------------------
Private Sub txtObjectHit_KeyPress(KeyAscii As Integer)
  ' allow only numbers
  On Error Resume Next
  If IsAlpha(Chr(KeyAscii)) Then KeyAscii = 0
'  If (KeyAscii < 48 Or KeyAscii > 57) Then KeyAscii = 0
End Sub

'--------------------------
Private Sub txtObjectHit_LostFocus()
  ' set hit selection distance (64ths of an inch)
  Dim iVal As Integer
  
  If m_bDoingUpdate Then Exit Sub
  
  iVal = val(txtObjectHit.Text)
  If iVal > 0 Then
    HitSelectionSize = iVal
  End If
  txtObjectHit.Text = m_nHitSelectionSize
End Sub

'--------------------------
Private Sub txtObjectSnap_KeyPress(KeyAscii As Integer)
  ' allow only numbers
  If IsAlpha(Chr(KeyAscii)) Then KeyAscii = 0
'  If (KeyAscii < 48 Or KeyAscii > 57) Then KeyAscii = 0
End Sub

'--------------------------
Private Sub txtObjectSnap_LostFocus()
  ' set hit selection distance (64ths of an inch)
  Dim iVal As Integer
  If m_bDoingUpdate Then Exit Sub
  
  iVal = val(txtObjectSnap.Text)
  If iVal > 0 Then
    ObjectSnapSize = iVal
  End If
  txtObjectSnap.Text = m_nObjectSnapSize

End Sub


Private Sub txtQty_LostFocus()
  If Len(txtQty.Text) < 1 Then
    txtQty.Text = "1"
  End If
End Sub

Private Sub txtRotateX_GotFocus()
  SelectAllTextControlText txtRotateX
End Sub


Private Sub txtRotateX_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

Private Sub txtRotateX_LostFocus()
  If Len(txtRotateX.Text) < 1 Then
    txtRotateX.Text = "0.0000"
  End If
End Sub

Private Sub txtRotateY_GotFocus()
  SelectAllTextControlText txtRotateY
End Sub

Private Sub txtRotateY_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

Private Sub txtRotateY_LostFocus()
  If Len(txtRotateY.Text) < 1 Then
    txtRotateY.Text = "0.0000"
  End If
End Sub

'--------------------------
Private Sub txtScale_Change()
  On Error Resume Next
  If VerifyConvertScaleValues(txtWidthNew.Text, txtHeightNew.Text, m_WidthNew, m_HeightNew) Then
    txtWidthNew.Text = lblWidthCur.Caption * txtScale.Text
    txtHeightNew.Text = lblHeightCur.Caption * txtScale.Text
  End If
End Sub

Private Sub txtScale_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

Private Sub txtScale_GotFocus()
  SelectAllTextControlText txtScale
End Sub


'======================================================================================
' Align ops
'======================================================================================
'------------------------------
Private Sub btnAlignToSnap_Click(index As Integer)
  ' align the selection to snap
  AlignToSnapOperation index
  SetGeFocus
End Sub
'------------------------------
Public Sub AlignToSnapOperation(ByVal index As Integer)
  ' align the selection to snap
  If Not m_GeCtrl Is Nothing Then GeWorker.AlignToSnapOperation m_GeCtrl, index
End Sub


Private Sub txtScale_LostFocus()
  If Len(txtScale.Text) < 1 Then
    txtScale.Text = "1.000"
  End If
End Sub

'======================================================================================
' Extents/Spacing
'======================================================================================
'------------------------------
Private Sub txtSpaceX_GotFocus()
  SelectAllTextControlText txtSpaceX
End Sub

Private Sub txtSpaceX_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

'------------------------------
Private Sub txtSpaceX_LostFocus()
  If Len(txtSpaceX.Text) < 1 Then
    txtSpaceX.Text = "0.00000"
    Exit Sub
  End If
  ' use val to prevent a type mismatch when typing some letter
  m_dSpaceX = val(txtSpaceX.Text)
  ' above may have got rid of some garbage characters
  txtSpaceX.Text = Format(m_dSpaceX, "0.00000")
  ' force vale to be of single type
  m_dSpaceX = CSng(txtSpaceX.Text)
End Sub

'--------------------------
Private Sub txtSpaceY_GotFocus()
  SelectAllTextControlText txtSpaceY
End Sub

Private Sub txtSpaceY_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

'------------------------------
Private Sub txtSpaceY_LostFocus()
  If Len(txtSpaceY.Text) < 1 Then
    txtSpaceY.Text = "0.00000"
    Exit Sub
  End If
  ' use val to prevent a type mismatch when typing some letter
  m_dSpaceY = val(txtSpaceY.Text)
  ' above may have got rid of some garbage characters
  txtSpaceY.Text = Format(m_dSpaceY, "0.00000")
  ' force vale to be of single type
  m_dSpaceY = CSng(txtSpaceY.Text)
  
End Sub

'------------------------------
Private Sub btnSeparate_Click(index As Integer)
  ' space the selection
  Select Case index
    Case 0  ' left
      SpaceSelHorz False
    Case 1  ' right
      SpaceSelHorz True
    Case 2  ' top
      SpaceSelVert False
    Case 3  ' bottom
      SpaceSelVert True
  End Select
End Sub
'------------------------------
Private Sub SpaceSelHorz(ByVal bToLeft As Boolean)
  On Error Resume Next
  If Not m_GeCtrl Is Nothing Then
    Dim dX As Single
    dX = CSng(txtSpaceX.Text)
    GeWorker.SpaceSelHorz m_GeCtrl, bToLeft, dX
    SetGeFocus
  End If
End Sub
'------------------------------
Private Sub SpaceSelVert(ByVal bToTop As Boolean)
  On Error Resume Next
  If Not m_GeCtrl Is Nothing Then
    Dim dy As Single
    dy = CSng(txtSpaceY.Text)
    GeWorker.SpaceSelVert m_GeCtrl, bToTop, dy
    SetGeFocus
  End If
End Sub

'======================================================================================
' Snap
'======================================================================================
'--------------------------
Private Function SetSnapSize(X As Single, Y As Single)
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Function
  m_GeCtrl.SnapHorz = X
  m_SnapX = X
  m_GeCtrl.SnapVert = Y
  m_SnapY = Y
End Function
'--------------------------
Private Sub ShowCurrentSnap(ByVal X As Single, ByVal Y As Single, ByVal bOn As Boolean)
  ' show current setting.
  
  Dim sX As Single, sY As Single
  Dim i As Integer
  On Error Resume Next
  
  ' If can find in my list, make the bg of the button darkgrey
  If (m_SnapMult > 0#) And bOn Then
    For i = 0 To btnSnap1.count - 1
      sX = X / m_SnapMult
      sY = Y / m_SnapMult
      If m_aSnap(i).X = sX And m_aSnap(i).Y = sY Then
        btnSnap1(i).BackColor = &H80000010  ' Button Shadow
      Else
        btnSnap1(i).BackColor = &H8000000F  ' button face (normal)
      End If
    Next i
  Else
    For i = 0 To btnSnap1.count - 1
      btnSnap1(i).BackColor = &H8000000F  ' button face (normal)
    Next i
  End If
  
  If bOn Then
    lblSnapCurX.Caption = X
    lblSnapCurY.Caption = Y
  Else
    lblSnapCurX.Caption = "none"
    lblSnapCurY.Caption = "none"
  End If
End Sub

'------------------------------
Private Function UpdateSnapButtonCaptions()
  ' update all snap buttons captions
  On Error Resume Next
  txtSnapX(0).Text = m_aSnap(0).X
  txtSnapY(0).Text = m_aSnap(0).Y
  txtSnapX(1).Text = m_aSnap(1).X
  txtSnapY(1).Text = m_aSnap(1).Y
  txtSnapX(2).Text = m_aSnap(2).X
  txtSnapY(2).Text = m_aSnap(2).Y
  txtSnapX(3).Text = m_aSnap(3).X
  txtSnapY(3).Text = m_aSnap(3).Y

  txtSnapMult.Text = m_SnapMult
  
End Function
'------------------------------
Private Sub btnSnap1_Click(index As Integer)
  Dim sX As Single
  Dim sY As Single
  On Error Resume Next
  
  If m_GeCtrl Is Nothing Then Exit Sub
  m_GeCtrl.Snap = True
  sX = m_aSnap(index).X * m_SnapMult
  sY = m_aSnap(index).Y * m_SnapMult
  SetSnapSize sX, sY

  ShowCurrentSnap sX, sY, True

  UpdateToolButtons
  UpdateCurrentSnap

  If Not m_frmActive Is Nothing Then m_frmActive.UpdateToolbarButtons

  SetGeFocus
End Sub

'------------------------------
Private Sub txtSnapX_GotFocus(index As Integer)
  SelectAllTextControlText txtSnapX(index)
End Sub

'------------------------------
Private Sub txtSnapY_GotFocus(index As Integer)
  SelectAllTextControlText txtSnapY(index)
End Sub

'------------------------------
Private Sub txtSnapMult_GotFocus()
  SelectAllTextControlText txtSnapMult
End Sub
'--------------------------
Private Sub txtSnapMult_LostFocus()
  Dim strVal As String
  Dim dVal As Single
  On Error Resume Next
  ''
  strVal = txtSnapMult.Text
  If Len(strVal) > 0 Then
    If IsNumeric(strVal) Then
      dVal = strVal
      If Not (dVal > 0) Then
        txtSnapMult.Text = m_SnapMult
        Exit Sub
      End If
    End If
  Else
    txtSnapMult.Text = m_SnapMult
    Exit Sub
  End If
  '
  m_SnapMult = txtSnapMult.Text

End Sub

'------------------------------
Private Sub txtSnapX_LostFocus(index As Integer)
  Dim strVal As String
  Dim dVal As Single
  
  On Error Resume Next
  ''
  strVal = txtSnapX(index).Text
  If Len(strVal) > 0 Then
    If IsNumeric(strVal) Then
      dVal = strVal
      If Not (dVal > 0) Then
        txtSnapX(index).Text = m_aSnap(index).X
        Exit Sub
      End If
    End If
  Else
    txtSnapX(index).Text = m_aSnap(index).X
    Exit Sub
  End If
  ''
  Select Case index
    Case 0
      m_aSnap(0).X = txtSnapX(0).Text
    Case 1
      m_aSnap(1).X = txtSnapX(1).Text
    Case 2
      m_aSnap(2).X = txtSnapX(2).Text
    Case 3
      m_aSnap(3).X = txtSnapX(3).Text
    End Select
End Sub

'------------------------------
Private Sub txtSnapY_LostFocus(index As Integer)
  Dim strVal As String
  Dim dVal As Single
  
  On Error Resume Next
  ''
  strVal = txtSnapY(index).Text
  If Len(strVal) > 0 Then
    If IsNumeric(strVal) Then
      dVal = strVal
      If Not (dVal > 0) Then
        txtSnapY(index).Text = m_aSnap(index).Y
        Exit Sub
      End If
    End If
  Else
    txtSnapY(index).Text = m_aSnap(index).Y
    Exit Sub
  End If
  ''
  Select Case index
    Case 0
      m_aSnap(0).Y = txtSnapY(0).Text
    Case 1
      m_aSnap(1).Y = txtSnapY(1).Text
    Case 2
      m_aSnap(2).Y = txtSnapY(2).Text
    Case 3
      m_aSnap(3).Y = txtSnapY(3).Text
    End Select
End Sub


'=======================================
' Object Snap
'=======================================
'------------------------------
Private Sub btnObjectSnap_Click(index As Integer)
  Dim i As Integer
  Dim iVal As Integer
  
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  If index = 0 Then
    iVal = 1   'All
  Else
    iVal = 0  ' None
  End If
  '
  For i = 0 To cbObjSnap.count - 1
    cbObjSnap(i).Value = iVal
  Next i
  SetGeFocus
End Sub

'------------------------------
Private Sub UpdateObjSnapFromGe()
  ' update checkboxes from CG
  On Error Resume Next
  If Not m_GeCtrl Is Nothing Then
    UpdateObjSnapControls m_GeCtrl.ObjectSnap, m_GeCtrl.ConnectionMode
  End If
End Sub
'------------------------------
Private Sub UpdateObjSnapControls(ByVal val As Integer, ByVal bConnectionMode As Boolean)
  Dim iVal As Integer
  
  On Error Resume Next
  m_bUpdatingObjectSnap = True
  
  iVal = 0
  If val And GESNAP_CENTER Then iVal = 1
  cbObjSnap(0).Value = iVal
  iVal = 0
  If val And GESNAP_ENDPOINT Then iVal = 1
  cbObjSnap(1).Value = iVal
  iVal = 0
  If val And GESNAP_MIDPOINT Then iVal = 1
  cbObjSnap(2).Value = iVal
  iVal = 0
  If val And GESNAP_INSERT Then iVal = 1
  cbObjSnap(3).Value = iVal
  iVal = 0
  If val And GESNAP_NEAREST Then iVal = 1
  cbObjSnap(4).Value = iVal
  iVal = 0
  If val And GESNAP_QUADRANT Then iVal = 1
  cbObjSnap(5).Value = iVal
  
  iVal = 0
  If val And GESNAP_CONNECTPOINT Then iVal = 1
  cbObjSnap(6).Value = iVal
  
  If bConnectionMode Then
    iVal = 1
    cbObjSnap(6).Value = iVal
  End If
  
  
  m_bUpdatingObjectSnap = False
  
End Sub

'------------------------------
Public Sub GetObjectSnapSettings(iObjSnap As Integer, bConnectionMode As Boolean)
  ' get current settings
  DoGetObjectSnapSettings iObjSnap, bConnectionMode
End Sub
'------------------------------
Private Sub DoGetObjectSnapSettings(val As Integer, bConnectionMode As Boolean)
  
  On Error Resume Next
  val = GESNAP_NONE
  If cbObjSnap(0).Value = 1 Then
    val = val + GESNAP_CENTER
  End If
  If cbObjSnap(1).Value = 1 Then
    val = val + GESNAP_ENDPOINT
  End If
  If cbObjSnap(2).Value = 1 Then
    val = val + GESNAP_MIDPOINT
  End If
  
  If cbObjSnap(3).Value = 1 Then
    val = val + GESNAP_INSERT 'mid
  End If
  If cbObjSnap(4).Value = 1 Then
    val = val + GESNAP_NEAREST
  End If
  If cbObjSnap(5).Value = 1 Then
    val = val + GESNAP_QUADRANT
  End If
  ''
  ' snap to connection/reference point
  If cbObjSnap(6).Value = 1 Then
    val = val + GESNAP_CONNECTPOINT
    bConnectionMode = True
  Else
    bConnectionMode = False
  End If

End Sub

'------------------------------
Private Sub cbObjSnap_Click(index As Integer)
  Dim val As Integer
  Dim bConnectionMode As Boolean
  
  On Error Resume Next
  If m_bUpdatingObjectSnap Then Exit Sub
  If m_GeCtrl Is Nothing Then Exit Sub
  ''
  DoGetObjectSnapSettings val, bConnectionMode
  
  AppWriteProfileInt INISECTION_UAO, INIENTRY_OBJECTSNAP, val
  m_GeCtrl.ObjectSnap = val
  
  m_GeCtrl.ConnectionMode = bConnectionMode
  AppWriteProfileInt INISECTION_UAO, INIENTRY_SNAPTOCONNECTIONS, val
  '
  SetGeFocus
End Sub

'========================================
' Hit detection - object selection
'========================================
'------------------------------
Public Property Let HitSelectionSize(iVal As Single)
  ' distance before will hit an object -in 64ths of an inch
  ' (will be mapped to page size by CG)
  Dim dVal As Single
  
  If m_GeCtrl Is Nothing Then Exit Property
  
  If iVal > 0 Then
    m_nHitSelectionSize = iVal
    dVal = iVal
    dVal = dVal / c_HitUnits
    m_GeCtrl.HitSelectionSize = dVal
  End If
End Property
'------------------------------
Public Property Get HitSelectionSize() As Single
  HitSelectionSize = m_nHitSelectionSize / c_HitUnits
End Property

'------------------------------
Private Sub txtObjectHit_Change()
  ' set hit selection distance (64ths of an inch)
  Dim iVal As Integer

  On Error Resume Next
  If m_bDoingUpdate Then Exit Sub

  iVal = val(txtObjectHit.Text)
  If iVal > 0 Then
    HitSelectionSize = iVal
  End If
  txtObjectHit.Text = m_nHitSelectionSize
End Sub
'------------------------------
Private Sub txtObjectHit_GotFocus()
  SelectAllTextControlText txtObjectHit
End Sub

'========================================
' Hit detection - object snap
'========================================
'------------------------------
Public Property Let ObjectSnapSize(iVal As Single)
  ' distance before will hit an object -in 64ths of an inch
  ' (will be mapped to page size by CG)
  Dim dVal As Single
    
  If m_GeCtrl Is Nothing Then Exit Property
  
  If iVal > 0 Then
    m_nObjectSnapSize = iVal
    dVal = iVal
    dVal = dVal / c_HitUnits
    m_GeCtrl.ObjectSnapSize = dVal
  End If
End Property

'------------------------------
Public Property Get ObjectSnapSize() As Single
  ObjectSnapSize = m_nObjectSnapSize / c_HitUnits
End Property

'------------------------------
Private Sub txtObjectSnap_Change()
  ' set hit selection distance (64ths of an inch)
  
  Dim iVal As Integer

  On Error Resume Next
  If m_bDoingUpdate Then Exit Sub

  iVal = val(txtObjectSnap.Text)
  If iVal > 0 Then
    ObjectSnapSize = iVal
  End If
  txtObjectSnap.Text = m_nObjectSnapSize
End Sub

'------------------------------
Private Sub txtObjectSnap_GotFocus()
  SelectAllTextControlText txtObjectSnap
End Sub

'--------------------------
Private Sub chkDrawInsertionPoints_Click()
  On Error Resume Next
  If m_bDoingUpdate Then Exit Sub
  If chkDrawInsertionPoints.Value = 0 Then
    If m_GeCtrl.DrawInsertionPoints Then m_GeCtrl.DrawInsertionPoints = False
  Else
    If Not m_GeCtrl.DrawInsertionPoints Then m_GeCtrl.DrawInsertionPoints = True
  End If
  SetGeFocus
End Sub

'--------------------------
Private Sub chkDrawFilledTransparent_Click()
  On Error Resume Next
  If m_bDoingUpdate Then Exit Sub
  If chkDrawFilledTransparent.Value = 0 Then
    If m_GeCtrl.DrawFilledTransparent Then m_GeCtrl.DrawFilledTransparent = False
  Else
    If Not m_GeCtrl.DrawFilledTransparent Then m_GeCtrl.DrawFilledTransparent = True
  End If
  SetGeFocus
End Sub

'--------------------------
Private Sub chkShowConnectionPts_Click()
  On Error Resume Next
  If m_bDoingUpdate Then Exit Sub
  If chkShowConnectionPts.Value = 0 Then
    If m_GeCtrl.DrawConnections Then m_GeCtrl.DrawConnections = False
  Else
    If Not m_GeCtrl.DrawConnections Then m_GeCtrl.DrawConnections = True
  End If
  SetGeFocus
End Sub

'------------------------------
Private Sub chkSnapToShape_Click()
  On Error Resume Next
  If m_bDoingUpdate Then Exit Sub
  If chkSnapToShape.Value = 0 Then
    If m_GeCtrl.SnapShapesToCursor Then m_GeCtrl.SnapShapesToCursor = False
  Else
    If Not m_GeCtrl.SnapShapesToCursor Then m_GeCtrl.SnapShapesToCursor = True
  End If
  SetGeFocus
End Sub

'--------------------------
Private Sub chkSnapTosel_Click()
  On Error Resume Next
  If m_bDoingUpdate Then Exit Sub
  If chkSnapTosel.Value = 0 Then
    If m_GeCtrl.SnapToSelection Then m_GeCtrl.SnapToSelection = False
  Else
    If Not m_GeCtrl.SnapToSelection Then m_GeCtrl.SnapToSelection = True
  End If
  SetGeFocus
End Sub


'==================================
' misc
'==================================
'------------------------------
Public Sub SetGeFocus()
  On Error Resume Next
  If Not m_GeCtrl Is Nothing Then m_GeCtrl.SetFocus
End Sub

'==================================
' Distribute
'==================================
'---------------------------
Public Sub DistributeSelHorz()
  ' Distribute the selection - Horz
  If Not m_GeCtrl Is Nothing Then GeWorker.DistributeSelHorz m_GeCtrl
End Sub
'---------------------------
Private Sub btnDistributeHorz_Click()
  DistributeSelHorz
  SetGeFocus
End Sub
'---------------------------
Public Sub DistributeSelVert()
  ' Distribute the selection - Vert
  If Not m_GeCtrl Is Nothing Then GeWorker.DistributeSelVert m_GeCtrl
End Sub
'---------------------------
Private Sub btnDistributeVert_Click()
  DistributeSelVert
  SetGeFocus
End Sub



Private Sub txtVSpace_GotFocus()
  SelectAllTextControlText txtVSpace
End Sub

Private Sub txtVSpace_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub

Private Sub txtVSpace_LostFocus()
  If Len(txtVSpace.Text) < 1 Then
    txtVSpace.Text = 0
  End If
End Sub

Private Sub txtWidthNew_KeyPress(KeyAscii As Integer)
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub



'------------------------------
Private Sub UserControl_Initialize()
  
  m_bLeftAligned = True   ' default to left side
  m_nLastPanel = 0    ' last sel panel
  Initialize
End Sub

'------------------------------
Private Sub UserControl_KeyDown(KeyCode As Integer, Shift As Integer)
  ' check for focus - if I've got it, pass onto gectrl
  If KeyCode = vbKeyEscape Then SetGeFocus
End Sub

Private Sub UserControl_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
  Screen.MousePointer = vbArrow
End Sub

'------------------------------
Private Sub UserControl_Resize()
  ' MUST resize selected panel(s) to deal with those that are scalable
  ShowPanel m_nLastPanel
End Sub

'===========================================================================
' Shapes
'===========================================================================
'--------------------------
Private Sub MoveCursorOntoGeCtrl()
  ' move cursor and shape onto GeCtrl
  Dim Top As Long
  Dim Left As Long
  Dim pt As POINTAPI
  
  On Error Resume Next
  ' get current pos ( in screen coordinates ie: 800 X 600)
  GetCursorPos pt
  ' move to new pos
  If m_bLeftAligned = True Then
    Left = pt.X + 250
  Else
    Left = pt.X - 250
  End If
  Top = pt.Y
  SetCursorPos Left, Top
End Sub

'--------------------------
Private Function LibraryExists(strName As String) As Boolean
  Dim i As Integer
  LibraryExists = False
  For i = 0 To cbShapeLibName.ListCount - 1
    If strName = cbShapeLibName.List(i) Then
      cbShapeLibName.ListIndex = i
      LibraryExists = True
      Exit Function
    End If
  Next i
End Function
'--------------------------
Private Function FolderExists(strName As String) As Boolean
Dim i As Integer
  FolderExists = False
  For i = 0 To cbShapeFolder.ListCount - 1
    If strName = cbShapeFolder.List(i) Then
      cbShapeFolder.ListIndex = i
      FolderExists = True
      Exit Function
    End If
  Next i
End Function

'--------------------------
Private Function ShapeExists(strName As String) As Boolean
Dim i As Integer
  ShapeExists = False
  For i = 0 To lbShapes.ListCount - 1
    If strName = lbShapes.List(i) Then
      lbShapes.ListIndex = i
      ShapeExists = True
      Exit Function
    End If
  Next i
  
End Function

'--------------------------
Private Sub txtQty_GotFocus()
  SelectAllTextControlText txtQty
End Sub
'--------------------------
Private Sub txtQty_KeyPress(KeyAscii As Integer)
  ' set qty for enter key
  ' allow only numbers
  On Error Resume Next
  If KeyAscii = vbKeyReturn Then
    KeyAscii = 0
    btnQty_Click
    txtQty.SetFocus
  ElseIf Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
  ' don't allow . when setting quantity
  If m_lSetArrayDistance = 0# And KeyAscii = 46 Then
    KeyAscii = 0
  End If
End Sub

'--------------------------
Private Sub btnQty_Click()
    ' array elements
    Dim GeID As Long
    Dim nGeType As Integer
    
    On Error Resume Next
    If txtQty.Text < 0 Then Exit Sub

    GeID = m_GeCtrl.GetFirstSelObject

    ' Get ID
    m_GeCtrl.CurrentPropertyID = GeID  ' move into selector
    nGeType = m_GeCtrl.ObjectType
    If nGeType = EGeObjType.UserGroup Then
      m_GeCtrl.ShapeSetCurrent (GeID)
    End If
    
    ' PBH
    Dim nFactor As Integer
    nFactor = txtQty.Text
    If m_lSetArrayDistance <> 0# Then
      nFactor = txtQty.Text * (1 / m_lSetArrayDistance)
      If nFactor < 1 Then
        nFactor = 1
      End If
    End If
    ' end PBH

    If Not m_GeCtrl Is Nothing And GeID > 0 Then
      If m_GeCtrl.ShapeSetCurrent(GeID) Then
        ' Note this sets the undo buffer as well
        m_GeCtrl.ShapeNumArrayElements = nFactor ' txtQty.Text
      End If
    End If
    
    m_GeCtrl.CurrentPropertyID = 0  ' reset selector

End Sub

'--------------------------
Private Sub btnInsertShape_Click()
  'advise active form of shape to be inserted
  Dim strShape As String
  Dim strLib As String
  Dim strShapeFullName As String
  Dim GeID As Long
  
  If m_frmActive Is Nothing Then Exit Sub
  If m_GeCtrl Is Nothing Then Exit Sub
  On Error Resume Next
  
  strShape = lbShapes.List(lbShapes.ListIndex)
  strLib = m_strShapeLibPath & "\" & m_strShapeLibName
  strShapeFullName = strLib & "!" & cbShapeFolder.List(cbShapeFolder.ListIndex)

  If Len(strShapeFullName) < 1 Or Len(strShape) < 1 Then Exit Sub
  
  GeID = InsertShape(strShapeFullName, strShape)
  If err = 0 And GeID > 0 Then
    MoveCursorOntoGeCtrl
  End If
End Sub
'--------------------------
Private Sub lbShapes_Click()
  If m_bDoingUpdate = True Then Exit Sub
  If m_frmActive Is Nothing Then Exit Sub
  If m_strShape = lbShapes.List(lbShapes.ListIndex) Then Exit Sub
  
  ShowShape lbShapes.ListIndex
  m_frmActive.SetStatusText " Shape name: " & lbShapes.List(lbShapes.ListIndex)
  m_strShape = lbShapes.List(lbShapes.ListIndex)
  If m_bDoingUpdate = False Then
    m_frmActive.SetShapeData cbShapeLibName.List(cbShapeLibName.ListIndex), _
                          cbShapeFolder.List(cbShapeFolder.ListIndex), _
                          lbShapes.List(lbShapes.ListIndex)
  End If
End Sub

'--------------------------
Private Sub cbShapeFolder_Click()
  Dim lFolderID As Long
  Dim strName As String

  On Error Resume Next
  If m_bDoingUpdate = True Then Exit Sub
  If m_strFolder = cbShapeFolder.List(cbShapeFolder.ListIndex) Then Exit Sub
  
  lFolderID = cbShapeFolder.ItemData(cbShapeFolder.ListIndex)
  strName = m_strShapeLibPath & "\" & m_strShapeLibName
  PopulateShapeListBox lFolderID, strName
  
  m_strFolder = cbShapeFolder.List(cbShapeFolder.ListIndex)
End Sub

'--------------------------
Private Function GetPath(strLibName As String) As String
  Dim aLibraries As Variant
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim i As Integer
  Dim strLibPath As String
  Dim pos As Long
  
  On Error Resume Next
  GetPath = ""
  
  If m_GeCtrl Is Nothing Then Exit Function

  m_GeCtrl.GetAttachedLibraries aLibraries

  uBnd = UBound(aLibraries)
  lBnd = LBound(aLibraries)
  If err <> 0 Then
    err = 0
    Exit Function
  End If

  For i = lBnd To uBnd
    strLibPath = aLibraries(i)
    If InStr(strLibPath, strLibName) > 0 Then
      pos = InStrRev(strLibPath, "\") - 1
      If pos > 0 Then
        GetPath = Left(strLibPath, pos)
      End If
    End If
  Next i
End Function

'--------------------------
Private Sub ClearShapeGe()
  On Error Resume Next
  ShapeGe.InitNew
  ShapeGe.Grid = False
  ShapeGe.MarginDisplay = False
  ShapeGe.DrawInsertionPoints = True
  ShapeGe.DrawingWidth = 0.1
  ShapeGe.DrawingHeight = 0.1
  ShapeGe.ZoomPage
End Sub

'------------------------------
Private Function ShowShape(nDX As Integer)
  Dim GeID As Long
  Dim strShape As String
  Dim strLib As String
  'Dim strShapeFullName As String

  On Error Resume Next
  If m_nLastPanel <> cMP_SHAPES Then
    Exit Function
  End If
  
  ClearShapeGe
  If (nDX < 0) Or (nDX > lbShapes.ListCount) Then Exit Function
  If lbShapes.ListCount < 1 Then
    Exit Function
  End If

  strShape = lbShapes.List(nDX)
  strLib = m_strShapeLibPath & "\" & m_strShapeLibName
  
  ShapeGe.UsePictureColor = True
  GeID = ShapeGe.CreateShape(strLib, cbShapeFolder.List(cbShapeFolder.ListIndex), strShape, 500, 500)
  If GeID < 1 Or err <> 0 Then
    Exit Function
  End If
  ShapeGe.ZoomExtents
  
  ' put shape in selector list otherwise the 'CanExplodeShape' below won't work
  ShapeGe.SelAdd GeID
  lSmartShape.Visible = ShapeGe.CanExplodeSmartShape
  ShapeGe.SelRemoveAll
  
  'lbShapes.SetFocus  'MEG: This call causes problems with the main menu appearing in the shape\object manager dialog
End Function


'--------------------------
Public Function EmptyCurrentShapeValues()
  m_strLibrary = ""
  m_strFolder = ""
  m_strShape = ""
End Function
'--------------------------
Public Function RemoveGeLibraries()
  ' remove any library if one exists
  
  ShapeGe.SelAddAll
  ShapeGe.Delete
  ClearShapeGe
  '
  lbShapes.Clear
  cbShapeLibName.Clear
  cbShapeFolder.Clear
  m_strShapeLibName = ""

End Function

'--------------------------
Public Function UpdateShapeList()
  ' called from frmGeEditor after CG.EndCreateShapeDef
  GetAttachedLibraries
End Function
'--------------------------
Public Sub SetShapeSettings(nLibrary As String, nFolder As String, nShape As String)
  ' called from frmGeEditor when it becomes active (only place this is called)
  Dim lastUpdate As Boolean
  Dim lFolderID As Long
  Dim strName As String
  
  m_strLibrary = nLibrary
  m_strFolder = nFolder
  m_strShape = nShape
  
  lastUpdate = m_bDoingUpdate
  m_bDoingUpdate = True
  If LibraryExists(nLibrary) Then
    ' set library
    If Len(m_strShapeLibPath) > 0 Then
      strName = m_strShapeLibPath & "\"
    End If
    strName = strName & m_strShapeLibName
    PopulateShapeFolderListBox strName
    
    If FolderExists(nFolder) Then
      ' set folder list
      lFolderID = cbShapeFolder.ItemData(cbShapeFolder.ListIndex)
      strName = m_strShapeLibPath & "\" & m_strShapeLibName
      PopulateShapeListBox lFolderID, strName
    
      If ShapeExists(nShape) Then
        'display shape
        m_bDoingUpdate = lastUpdate
        ShowShape lbShapes.ListIndex
      End If
    End If
  End If
  m_bDoingUpdate = lastUpdate
  
End Sub

'------------------------------
Public Sub LibraryChanged(ByVal LibraryName As String, ByVal FolderName As String, ByVal ShapeName As String)
  ' something has changed in the library
'  Debug.Print "Sub LibraryChanged - hi"
  Dim strLib As String
  
  On Error Resume Next
  strLib = m_strShapeLibPath & "\" & m_strShapeLibName
'  If UCase(m_strLibrary) = UCase(LibraryName) Then
  If UCase(strLib) = UCase(LibraryName) Then
    If UCase(m_strFolder) = UCase(FolderName) Then
      If UCase(m_strShape) = UCase(ShapeName) Then
                      
      End If
    End If
  End If
  
End Sub

'--------------------------
Public Function GetAttachedLibraries()
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim i As Integer
  Dim strLibPath As String

  On Error Resume Next
  If m_GeCtrl Is Nothing Then
    Exit Function
  End If
  
  m_GeCtrl.GetAttachedLibraries m_aLibraries
  If err <> 0 Then
    err = 0
    Exit Function
  End If
  
  m_strShapeLibPath = ""
  RemoveGeLibraries
  
  uBnd = UBound(m_aLibraries)
  lBnd = LBound(m_aLibraries)
  If err <> 0 Or uBnd = -1 Then
    err = 0
    Exit Function
  End If
  
  m_bDoingUpdate = True
  m_bIsSETDrawing = False

  For i = lBnd To uBnd
    cbShapeLibName.AddItem StripPath(m_aLibraries(i))
  Next i

 
  ' get first library in list
  strLibPath = m_aLibraries(lBnd)
  m_strShapeLibPath = StripFile(strLibPath)
  m_strShapeLibName = StripPath(strLibPath)

'  If LibraryExists(m_strLibrary) And FolderExists(m_strShape) And ShapeExists(m_strFolder) Then
'
'  End If


  If LibraryExists(m_strLibrary) = False Then
    cbShapeLibName.ListIndex = 0
  End If
  
  m_strLibrary = cbShapeLibName.List(cbShapeLibName.ListIndex)
  If Len(m_strLibrary) > 0 Then
    PopulateShapeFolderListBox strLibPath
  End If
  m_bDoingUpdate = False
  
  ' force draw of first
  If lbShapes.ListCount > 0 Then
    ShowShape lbShapes.ListIndex
  End If

End Function


'------------------------------
Private Function PopulateShapeFolderListBox(strLibPath As String)
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strSQL As String
  Dim strDir As String
  Dim DoingUpdate As Boolean

  On Error Resume Next
  cbShapeFolder.Clear
  
  strDB = strLibPath
  If Not FileExists(strDB) Then Exit Function
  
  strSQL = "SELECT GeTblFolder.FolderName, GeTblFolder.FolderID "
  strSQL = strSQL & "From GeTblFolder "
  strSQL = strSQL & "ORDER BY GeTblFolder.FolderName"
  
  Set dbs = OpenDatabase(strDB, True, True) ' bExclusive, bReadonly
  If err = 0 Then
    Set rst = dbs.OpenRecordset(strSQL, dbOpenSnapshot)
    If err = 0 Then
      With rst
        Do While Not .EOF And Not .BOF
          cbShapeFolder.AddItem !FolderName
          cbShapeFolder.ItemData(cbShapeFolder.NewIndex) = !FolderID
          .MoveNext
        Loop
        .Close
      End With
    End If
    dbs.Close
  End If
  '
  If cbShapeFolder.ListCount > 0 Then
    DoingUpdate = m_bDoingUpdate
    m_bDoingUpdate = True
    
    If FolderExists(m_strFolder) = False Then
      cbShapeFolder.ListIndex = 0
    End If
    PopulateShapeListBox cbShapeFolder.ItemData(cbShapeFolder.ListIndex), strLibPath
    m_bDoingUpdate = DoingUpdate
  End If

End Function

'------------------------------
Private Function PopulateShapeListBox(nFolderID As Long, strShapeLibName As String)
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strSQL As String
  
  On Error Resume Next
  lbShapes.Clear
  
  strSQL = "SELECT GeTblShape.ShapeName, GeTblShape.FolderID "
  strSQL = strSQL & " From GeTblShape Where GeTblShape.FolderID = " & nFolderID
  strSQL = strSQL & " ORDER BY GeTblShape.ShapeName"
  
  strDB = strShapeLibName

  Set dbs = OpenDatabase(strDB, True, True) ' bExclusive, bReadonly
  If err = 0 Then
    Set rst = dbs.OpenRecordset(strSQL, dbOpenSnapshot)
    If err = 0 Then
      With rst
        Do While Not .EOF And Not .BOF
          lbShapes.AddItem !ShapeName
          .MoveNext
        Loop
        .Close
      End With
    End If
    dbs.Close
  End If
  '
  If lbShapes.ListCount > 0 Then
    If ShapeExists(m_strShape) = False Then
      lbShapes.ListIndex = 0
    End If
    EndWaitCursor
    ShapeGe.ZoomExtents
  Else
    ClearShapeGe
  End If
  
End Function

'------------------------------
Private Function InsertShape(strLib As String, strShape As String) As Long
  Dim GeID As Long
  On Error Resume Next
  GeID = m_GeCtrl.InsertShape(strLib, strShape)
  If err = 0 Then InsertShape = GeID
End Function

'===========================================================================
' Scale/Width
'===========================================================================
'--------------------------
Private Function VerifyConvertScaleValues(strWidth As String, _
                  strHeight As String, dWidth As Single, dHeight As Single) As Boolean
  Dim bErr As Boolean
  On Error Resume Next
'  bErr = IsNumeric(strWidth)
  bErr = False
  If IsNumeric(strWidth) And IsNumeric(strHeight) Then
    dWidth = CSng(strWidth)
    dHeight = CSng(strHeight)
    If err = 0 Then
      VerifyConvertScaleValues = True
      Exit Function
    End If
  Else
    bErr = True
  End If
  If bErr Then
    MsgBox "Invalid Width/Height values", MB_ICONEXCLAMATION
    VerifyConvertScaleValues = False
  End If
End Function

'--------------------------
Private Sub txtWidthNew_LostFocus()
  Dim sVal As Single
  Dim aspect As Single
  
  If Len(txtWidthNew.Text) < 1 Then
    txtWidthNew.Text = "0.0000"
    Exit Sub
  End If
  
  If VerifyConvertScaleValues(txtWidthNew.Text, txtHeightNew.Text, sVal, m_HeightNew) Then
    m_WidthNew = sVal
    If cbAspectRatio.Value = 1 Then
      If lblHeightCur > 0.000001 Then
        aspect = lblWidthCur / lblHeightCur
        If aspect > 0.000001 Then
          m_HeightNew = txtWidthNew.Text / aspect
          If m_HeightNew < 0.000001 Then
            m_HeightNew = 0#
          End If
          txtHeightNew.Text = m_HeightNew
        End If
      End If
    End If
  End If
End Sub
'--------------------------
Private Sub txtHeightNew_LostFocus()
  Dim sVal As Single
  Dim aspect As Single
  
  If Len(txtHeightNew.Text) < 1 Then
    txtHeightNew.Text = "0.0000"
    Exit Sub
  End If
  
  If VerifyConvertScaleValues(txtWidthNew.Text, txtHeightNew.Text, m_WidthNew, sVal) Then
    m_HeightNew = sVal
    If cbAspectRatio.Value = 1 Then
      If lblHeightCur > 0.000001 Then
        aspect = lblWidthCur / lblHeightCur
        If aspect > 0.000001 Then
          m_WidthNew = txtHeightNew.Text * aspect
          If m_WidthNew < 0.000001 Then
            m_WidthNew = 0#
          End If
          txtWidthNew.Text = m_WidthNew
        End If
      End If
    End If
    
  End If
End Sub

'------------------------------
Private Sub txtWidthNew_GotFocus()
  SelectAllTextControlText txtWidthNew
End Sub
'--------------------------
Private Sub txtHeightNew_GotFocus()
  SelectAllTextControlText txtHeightNew
End Sub

'--------------------------
Private Function DoSelScale()
  ' scale Selection about lower left corner of extents
  ' June 2000 PBH changed this to scale about center
  Dim dWidthCur As Single, dHeightCur As Single
  Dim dWidthNew As Single, dHeightNew As Single
  Dim scaleX As Single, scaleY As Single

  On Error Resume Next
  
'  dWidthCur = m_dRight - m_dleft
'  dHeightCur = m_dtop - m_dBottom
  ' use data displayed to get an accurate ration as the displayed data is
  ' limited to 5 decimal places
  dWidthCur = lblWidthCur.Caption
  dHeightCur = lblHeightCur.Caption
  
  dWidthNew = txtWidthNew.Text
  dHeightNew = txtHeightNew.Text
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
  '' do it (wrap in transaction)
  m_GeCtrl.BeginUndoTransaction
  
  If scaleX > 0# And scaleY > 0# Then
'    m_GeCtrl.SelScale m_dleft, m_dBottom, scaleX, scaleY
    m_GeCtrl.SelScale m_dCenterX, m_dCenterY, scaleX, scaleY
  End If

  m_GeCtrl.EndUndoTransaction

End Function


'=================================================================
' LAYERS
'=================================================================
'======================================================================================
' FLEXGRID Props for Layers
'======================================================================================
'--------------------------
Private Sub EnumLayers()
  ' get list of layers from CG
  Dim Row As Long
  
  On Error Resume Next
  If Not IsShowingLayers Then Exit Sub
  
  ' resolve if never have so can get up to date on drawing state.
  If Not m_LayerDefs Is Nothing And Not m_GeCtrl Is Nothing Then
    If Not m_LayerDefs.ResolvedWithGe Then m_LayerDefs.ResolveWithGe m_GeCtrl
  End If
  
  ' update grid
  ShowLayerDefsToGrid m_LayerDefs
  
  ' move to layer
  Row = 0
  If Not m_LayerDefs Is Nothing Then
    If Not GetRowWithLayer(Row, m_LayerDefs.LastSelectedLayer) Then
      m_LayerDefs.LastSelectedLayer = 0
    End If
  End If
  '
  FGProps.Row = Row
End Sub

'--------------------------
Private Sub ShowLayerDefsToGrid(LayerDefs As LayerDefinitions)
  ' show all to grid
  Static bFirst As Boolean
  Dim R As Integer, G As Integer, B As Integer, FLAGS As Integer
  Dim i As Long
  Dim LayerDef As LayerDefinition
  
  On Error Resume Next
  m_bConstructingGrid = True
  
  With FGProps
    .Redraw = False
    .Clear
    .Rows = 1
    .Cols = 3
    .FixedCols = 2
    .FixedRows = 1
    
    ' use col 0 for sorting purposes (it is not shown)
    .ColHidden(0) = True
    
    If Not bFirst Then
      .ColWidth(1) = 750  ' 860
      bFirst = True
    End If
    
    .Row = 0
    .Cell(flexcpText, .Row, 1) = "Layer"
    .Cell(flexcpText, .Row, 2) = "Name"
    
    .Editable = True
'    .WordWrap = True
    .ScrollBars = flexScrollBarVertical
    .ExtendLastCol = True
    
    If LayerDefs Is Nothing Or m_GeCtrl Is Nothing Then
      .Redraw = True
      m_bConstructingGrid = False
      Exit Sub
    End If
  
    ' populate grid
    For i = 1 To LayerDefs.count
      Set LayerDef = LayerDefs.Item(i)
      .Rows = .Rows + 1
      UpdateLayerDefToGrid .Rows - 1, LayerDef, False
    Next i
  End With
  ''
  With FGProps
    ' sort grid by layer number (use hidden col 0)
    .Col = 0
    .Sort = flexSortNumericAscending
    .Col = 1

    ' redraw
    .Row = 0
    .Redraw = True
  End With
  '
  m_bConstructingGrid = False
End Sub

'------------------------------
Private Sub UpdateLayerDefToGrid(Row As Long, LayerDef As LayerDefinition, _
                                Optional ByVal bRowSelected As Boolean = True)
  ' update grid with obj
  Dim strStatus As String
  On Error Resume Next
  With FGProps
    strStatus = CStr(LayerDef.Layer) & " "
    If Not LayerDef.CanSelect Then strStatus = strStatus & "L"
    If Not LayerDef.CanMove Then strStatus = strStatus & "M"
    If Not LayerDef.Visible Then strStatus = strStatus & "H"
    If Not LayerDef.CanPrint Then strStatus = strStatus & "P"
    
    .RowData(Row) = LayerDef.Layer
    ' hidden col
    .Cell(flexcpText, Row, 0) = LayerDef.Layer
    
    '' visible cols
    
    ' Selection button
    .Cell(flexcpAlignment, Row, 1) = flexAlignLeftCenter
    .Cell(flexcpText, Row, 1) = strStatus
      ' background
    If bRowSelected Then
      .Cell(flexcpBackColor, Row, 1) = &H80000010     ' dark grey
    Else
      .Cell(flexcpBackColor, Row, 1) = &H8000000F  ' the default (light grey)
    End If
    
    ' description
    .Cell(flexcpAlignment, Row, 2) = flexAlignLeftCenter
    .Cell(flexcpText, Row, 2) = LayerDef.Name
    
  End With
End Sub

'------------------------------
Private Sub FGProps_RowColChange()
  Dim LayerDef As LayerDefinition
  Dim i As Long
  
  On Error Resume Next
  
  If m_bConstructingGrid Then Exit Sub
  With FGProps
    If .Row = 0 Or .Col = 0 Then Exit Sub
    Set LayerDef = SelLayerDef
    If Not LayerDef Is Nothing Then
      UpdateLayerDefToControls LayerDef
      txtCurLayer.Text = LayerDef.Layer
    End If
    ' show row selected, all others not
    For i = 1 To .Rows - 1
      If i = .Row Then
        ' the selected row
        .Cell(flexcpBackColor, i, 1) = &H80000010     ' dark grey
'        .Cell(flexcpForeColor, i, 1) = &HFF0000      ' blue
      Else
        .Cell(flexcpBackColor, i, 1) = &H8000000F  ' the default (light grey)
'        .Cell(flexcpForeColor, i, 1) = &H80000008 ' the default (black)
      End If
    Next i
    If .Col < 2 Then    ' the col with the name
      SetGeFocus
    End If
  End With

End Sub

'------------------------------
Private Sub FGProps_BeforeEdit(ByVal Row As Long, ByVal Col As Long, Cancel As Boolean)
  ' set focus so that current GeCtrl isnot eating keys (eg: Del in grid is deleting items on drawing)
  With FGProps
    If .Row > 0 Then
      If .Col = 2 Then    ' the col with the name
        Cancel = False
        Exit Sub
      End If
    End If
  End With
  '
  Cancel = True
End Sub

'------------------------------
Private Sub FGProps_EnterCell()
  On Error Resume Next
  With FGProps
    If m_bConstructingGrid Or .Row < 1 Then Exit Sub
    If .Col > 1 Then
      .Select .Row, .Col
      .EditCell
    End If
  End With
End Sub

'------------------------------
Private Sub FGProps_AfterEdit(ByVal Row As Long, ByVal Col As Long)
  ' update Props from Grid
  Dim strVal As String
  Dim bModified As Boolean
  Dim LayerDef As LayerDefinition
  Dim iLayer As Integer
  
  On Error Resume Next
  If m_bConstructingGrid Or Row < 1 Then Exit Sub
  With FGProps
    iLayer = .RowData(.Row)
    Set LayerDef = GetLayerDefForRow(.Row)
    If Not LayerDef Is Nothing Then
      strVal = .Cell(flexcpText, Row, Col)
      '
      Select Case Col
        Case 2  ' name
          If LayerDef.Name <> strVal Then
            LayerDef.Name = strVal
            bModified = True
          End If
      End Select
      '
    End If
  End With
  ' update Active form if modified
  If bModified Then
    If Not m_frmActive Is Nothing Then m_frmActive.SetDwgIsModified True
  End If
  ''
  SetGeFocus
  
End Sub
'------------------------------
Private Function GetRowWithLayer(Row As Long, ByVal Layer As Integer) As Boolean
  ' find row with layer
  Dim i As Long
  On Error Resume Next
  With FGProps
    For i = 1 To .Rows
      If .RowData(i) = Layer Then
        Row = i
        GetRowWithLayer = True
        Exit Function
      End If
    Next i
  End With
End Function
'------------------------------
Private Function GetLayerDefForRow(ByVal Row As Long) As LayerDefinition
  ' get LayerDef for row
  Dim iLayer As Integer
  On Error Resume Next
  If Not m_LayerDefs Is Nothing Then
    iLayer = FGProps.RowData(Row)
    Set GetLayerDefForRow = m_LayerDefs.LayerDefForGeLayer(iLayer)
  End If
End Function

'--------------------------
Private Property Get SelLayerDef() As LayerDefinition
  ' selected one
  Set SelLayerDef = GetLayerDefForRow(FGProps.Row)
End Property

'------------------------------
Private Sub UpdateLayerDefToControls(LayerDef As LayerDefinition)
  ' update misc controls with LayerDef info
  On Error Resume Next
  m_bUpdatingLayer = True
  If Not LayerDef Is Nothing Then
    chkLayerSelLock.Value = IIf(LayerDef.CanSelect, 0, 1)
    chkLayerMoveLock.Value = IIf(LayerDef.CanMove, 0, 1)
    chkLayerVisible.Value = IIf(LayerDef.Visible, 0, 1)
    chkLayerPrint.Value = IIf(LayerDef.CanPrint, 0, 1)
  End If
  m_bUpdatingLayer = False
End Sub
'--------------------------
Private Sub chkLayerSelLock_Click()
  ' Select lock it  0 = can select
  Dim iLayer As Integer
  If Not m_bUpdatingLayer Then
    If GetSelLayer(iLayer) Then DoLockLayer IIf(chkLayerSelLock.Value = 0, False, True), iLayer
    SetGeFocus
  End If
End Sub
'--------------------------
Private Sub chkLayerMoveLock_Click()
  ' MoveLock it 0 = can move
  Dim iLayer As Integer
  If Not m_bUpdatingLayer Then
    If GetSelLayer(iLayer) Then DoMoveLockLayer IIf(chkLayerMoveLock.Value = 0, False, True), iLayer
    SetGeFocus
  End If
End Sub
'--------------------------
Private Sub chkLayerVisible_Click()
  ' Show Lock it 0 = is visible
  Dim iLayer As Integer
  If Not m_bUpdatingLayer Then
    If GetSelLayer(iLayer) Then DoShowLayer IIf(chkLayerVisible = 0, True, False), iLayer
    SetGeFocus
  End If
End Sub
'--------------------------
Private Sub chkLayerPrint_Click()
  ' Print Lock it 0 = can print
  Dim iLayer As Integer
  If Not m_bUpdatingLayer Then
    If GetSelLayer(iLayer) Then DoPrintLayer IIf(chkLayerPrint = 0, True, False), iLayer
    SetGeFocus
  End If
End Sub
'--------------------------
Private Sub btnRefreshLayers_Click()
  On Error Resume Next
  If Not m_LayerDefs Is Nothing Then
    If Not m_GeCtrl Is Nothing Then m_LayerDefs.ResolveWithGe m_GeCtrl
  End If
  EnumLayers
  SetGeFocus
End Sub

'--------------------------
Private Sub btnAssignLayer_Click()
  ' assign layer to selection
  Dim iLayer As Integer
  
  On Error Resume Next
  If Len(txtCurLayer.Text) = 0 Then Exit Sub
  If m_GeCtrl Is Nothing Then Exit Sub
  '
  iLayer = CInt(txtCurLayer.Text)
  If iLayer > -1 And iLayer <= c_nLastUserLayer Then
    m_GeCtrl.BeginUndoTransaction
    DoAssignSelToLayer iLayer
    m_GeCtrl.EndUndoTransaction
    MoveToSelLayer iLayer
  End If
  '
  SetGeFocus
End Sub
'--------------------------
Private Sub DoAssignSelToLayer(iLayer As Integer)
  ' Assign selection to layer
  Dim aVar As Variant  ' return array of GeIDs
  Dim i As Integer
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim nID As Long
  
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  If m_GeCtrl.SelNumberOfObjects = 0 Then Exit Sub
  m_GeCtrl.SelGetObjects aVar   ' get IDs of all objects in selection

  If err <> 0 Then Exit Sub
  uBnd = UBound(aVar)
  lBnd = LBound(aVar)
  
  For i = lBnd To uBnd
    nID = aVar(i)
    m_GeCtrl.CurrentPropertyID = nID ' move into selector
    m_GeCtrl.Layer = iLayer          ' set layer
  Next i
  m_GeCtrl.CurrentPropertyID = 0      ' reset selector

'  EnumLayers
  ' update list of layers if a new one
  If Not m_LayerDefs Is Nothing Then
    Dim LayerDef As LayerDefinition
    Set LayerDef = m_LayerDefs.LayerDefForGeLayer(iLayer)
    If LayerDef Is Nothing Then
      m_LayerDefs.ResolveWithGe m_GeCtrl
      EnumLayers
    End If
  End If
End Sub

'--------------------------
Private Sub txtCurLayer_KeyPress(KeyAscii As Integer)
  ' allow only numbers
  If Not (KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub
'--------------------------
Private Sub txtCurLayer_GotFocus()
  SelectAllTextControlText txtCurLayer
End Sub
'--------------------------
Private Sub txtLayer_GotFocus()
  ' default layer
  SelectAllTextControlText txtLayer
End Sub
'--------------------------
Private Sub txtLayer_KeyPress(KeyAscii As Integer)
  ' default layer
  ' allow only numbers
  If Not (KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
End Sub
'--------------------------
Private Sub txtLayer_LostFocus()
  ' default layer
  Dim iLayer As Integer
  
  On Error Resume Next
  If Len(txtLayer.Text) < 1 Then
    txtLayer.Text = m_GeCtrl.Layer
  Else
    iLayer = CInt(txtLayer.Text)
    If iLayer > -1 And iLayer <= c_nLastUserLayer Then
      m_GeCtrl.Layer = txtLayer.Text
    Else
      txtLayer.Text = m_GeCtrl.Layer
    End If
  End If
End Sub

'--------------------------
Private Sub btnSelByLayer_Click()
  ' select all on layer currently in lb
  Dim iLayer As Integer
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  If GetSelLayer(iLayer) Then DoSelByLayer iLayer
  SetGeFocus
End Sub

'--------------------------
Private Sub MoveToSelLayer(iLayer As Integer)
  Dim Row As Long
  On Error Resume Next
  If GetRowWithLayer(Row, iLayer) Then FGProps.Row = Row
  SetGeFocus
End Sub

'--------------------------
Private Function GetSelLayer(iLayer As Integer) As Boolean
  ' set selected
  Dim LayerDef As LayerDefinition
  Set LayerDef = GetLayerDefForRow(FGProps.Row)
  If Not LayerDef Is Nothing Then
    iLayer = LayerDef.Layer
    GetSelLayer = True
  End If
End Function

'--------------------------
Private Sub DoSelByLayer(iLayer As Integer)
  ' select by layer
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  m_GeCtrl.SelRemoveAll
  m_GeCtrl.LayerAddToSelection iLayer
End Sub

'--------------------------
Private Sub DoLockLayer(bLock As Boolean, iLayer As Integer)
  ' Select Lock/unlock by layer
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  If bLock Then m_GeCtrl.LayerLock iLayer Else m_GeCtrl.LayerUnLock iLayer
  
  Dim LayerDef As LayerDefinition
  Set LayerDef = SelLayerDef
  If Not LayerDef Is Nothing Then
    LayerDef.CanSelect = Not bLock
    UpdateLayerDefToGrid FGProps.Row, LayerDef
  End If
'  EnumLayers
End Sub

'--------------------------
Private Sub DoMoveLockLayer(bLock As Boolean, iLayer As Integer)
  ' Move Lock/unlock by layer
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  If bLock Then m_GeCtrl.LayerLockMove iLayer Else m_GeCtrl.LayerUnLockMove iLayer
  
  Dim LayerDef As LayerDefinition
  Set LayerDef = SelLayerDef
  If Not LayerDef Is Nothing Then
    LayerDef.CanMove = Not bLock
    UpdateLayerDefToGrid FGProps.Row, LayerDef
  End If
'  EnumLayers
End Sub
'--------------------------
Private Sub DoShowLayer(bShow As Boolean, iLayer As Integer)
  ' Show/Hide by layer
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  If bShow Then m_GeCtrl.LayerShow iLayer Else m_GeCtrl.LayerHide iLayer
  
  Dim LayerDef As LayerDefinition
  Set LayerDef = SelLayerDef
  If Not LayerDef Is Nothing Then
    LayerDef.Visible = bShow
    UpdateLayerDefToGrid FGProps.Row, LayerDef
  End If
'  EnumLayers
End Sub
'--------------------------
Private Sub DoPrintLayer(bPrint As Boolean, iLayer As Integer)
  ' Print Lock by layer
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  
  Dim LayerDef As LayerDefinition
  Set LayerDef = SelLayerDef
  If Not LayerDef Is Nothing Then
    If LayerDef.CanPrint <> bPrint Then
      If Not m_frmActive Is Nothing Then m_frmActive.SetDwgIsModified True
    End If
    LayerDef.CanPrint = bPrint
    UpdateLayerDefToGrid FGProps.Row, LayerDef
  End If
'  EnumLayers
End Sub


'======================================================================================
' Animation related
'======================================================================================
'--------------------------
Private Sub btnSet_Click(index As Integer)
  Dim sData As String
  Dim nGeID As Long
  Dim dX As Single, dy As Single
  Dim scaleX As Single, scaleY As Single
  Dim ptX As Single, ptY As Single
  Dim Left As Single, Bottom As Single, Right As Single, Top As Single
  Dim sVal As Single
  Dim bConMode As Boolean
  
  On Error Resume Next
  
  m_GeCtrl.SelStepIntoGroups = True ' set true in case object has been placed in a group
  bConMode = m_GeCtrl.ConnectionMode
  m_GeCtrl.ConnectionMode = False     ' disable Connection making
  
  nGeID = txtIDMove.Text
  '
  Select Case index
    Case 0 ' move it
      dX = CSng(txtDXMove.Text)
      dy = CSng(txtDYMove.Text)
      m_GeCtrl.MoveObject nGeID, dX, dy
  
    Case 1 ' scale it
      scaleX = CSng(txtDXScale.Text)
      If scaleX = 0 Then        ' 0 is invalid
        txtDXScale.Text = 1
        m_GeCtrl.ConnectionMode = bConMode     ' restore Connection making mode
        Exit Sub
      End If
      scaleY = CSng(txtDYScale.Text)
      If scaleY = 0 Then        ' 0 is invalid
        txtDYScale.Text = 1
        m_GeCtrl.ConnectionMode = bConMode     ' restore Connection making mode
        Exit Sub
      End If
      '
      m_GeCtrl.CurrentPropertyID = nGeID    ' move into selector so can get extents
      If err = 0 Then
        ' if not err, then is valid GeID
        ' get point to scale about
        m_GeCtrl.GetExtents Left, Bottom, Right, Top
        m_GeCtrl.CurrentPropertyID = 0  ' reset selector
          ' Try the center of object
        ptX = Left + (Right - Left) / 2#
        ptY = Bottom + (Top - Bottom) / 2#
        '
        m_GeCtrl.ScaleObject nGeID, ptX, ptY, scaleX, scaleY
      End If
  
    Case 2 ' Rotate it (in degrees)
      m_GeCtrl.CurrentPropertyID = nGeID    ' move into selector so can get extents
      If err = 0 Then
        ' if not err, then is valid GeID
        ' get point to rotate about
        m_GeCtrl.GetExtents Left, Bottom, Right, Top
        m_GeCtrl.CurrentPropertyID = 0  ' reset selector
        
        ' Try the center of object
        ptX = Left + (Right - Left) / 2#
        ptY = Bottom + (Top - Bottom) / 2#
        
        ' the angle (CCW is positive)
        sVal = txtAngleRotate.Text
        m_GeCtrl.RotateObject nGeID, ptX, ptY, sVal
'        m_GeCtrl.SelRotate ptX, ptY, sval
'        m_GeCtrl.CurrentPropertyID = 0  ' reset selector
      End If
      
  End Select
  '
  m_GeCtrl.SelStepIntoGroups = False
  m_GeCtrl.ConnectionMode = bConMode     ' restore Connection making mode
  
End Sub


'--------------------------
Public Sub UpdateSelGeID(ByVal GeID As Long)
  ' ID of single selected object
  txtIDMove.Text = GeID
End Sub

''===========================================================================
' Ge Connection
''===========================================================================
Private Sub btnEnumConnections_Click()
  ' enum all connections -
  Dim CDEditor As CustomDrawingEditor
  
  On Error Resume Next
  If Not m_frmActive Is Nothing Then
    Set CDEditor = m_frmActive.CustomDrawingEditor
    If Not CDEditor Is Nothing Then CDEditor.EnumConnections
  End If

End Sub


'--------------------------
Public Sub Proc_ConnectionChanged(ByVal Action As Integer, _
        ByVal IDLine As Long, _
        ByVal IDA As Long, ByVal VarA As Variant, _
        ByVal NameA As String, ByVal TypeA As Integer, ByVal StsA As Integer, _
        ByVal IDB As Long, ByVal VarB As Variant, _
        ByVal NameB As String, ByVal TypeB As Integer, ByVal StsB As Integer)
''''
  
#If 1 Then
  '' show info to frame
  
'  ca_NONE     = 0,
'  ca_CONNECTED  = 1,  // line joined to 1 or more connectors
'  ca_BROKEN   = 2,  // broken (vertex moved off Connector, or Connector deleted)
'  ca_LINEDELETED  = 3,  // line was deleted
'  ca_NEW      = 4   // new connection
  
  Select Case Action
    Case 0  ' none
      lblEvent.Caption = "None"
    Case 1  ' connected
      lblEvent.Caption = "Connected"
    Case 2  ' broken
      lblEvent.Caption = "Broken"
    Case 3  ' line deleted
      lblEvent.Caption = "Line Deleted"
    Case 4  ' new connection
      lblEvent.Caption = "New connection"
    Case Else
      lblEvent.Caption = "???????"
  End Select
    
  txtLineID.Text = IDLine
  
  txtConAID.Text = IDA
  txtConAName.Text = NameA
  txtConAType.Text = TypeA
  
'enum EGeObjConnectStatus {
'  cs_NONE     = 0,    // unknown
'  cs_MADE     = 1,    // just made
'  cs_BROKEN   = 2,    // just broken (vertex moved off Connector, or Connector deleted)
'  cs_DELETED    = 3,    // Connector was deleted
'  cs_UNCONNECTED  = 4,    // not connected
'  cs_CONNECTED  = 5     // still connected
'};
  
  Select Case StsA
    Case 0  ' none
      txtConASts.Text = "????"
    Case 1  ' just made
      txtConASts.Text = "Made"
    Case 2  ' just broken (vertex moved off Connector, or Connector deleted)
      txtConASts.Text = "Broken"
    Case 3  ' Connector was deleted
      txtConASts.Text = "Line Deleted"
    Case 4  ' not connected
      txtConASts.Text = "Not Connected"
    Case 5  ' still connected
      txtConASts.Text = "Still Connected"
    Case Else
      txtConASts.Text = "???????"
  End Select

  txtConBID.Text = IDB
  txtConBName.Text = NameB
  txtConBType.Text = TypeB
  Select Case StsB
    Case 0  ' none
      txtConBSts.Text = "????"
    Case 1  ' just made
      txtConBSts.Text = "Made"
    Case 2  ' just broken (vertex moved off Connector, or Connector deleted)
      txtConBSts.Text = "Broken"
    Case 3  ' Connector was deleted
      txtConBSts.Text = "Line Deleted"
    Case 4  ' not connected
      txtConBSts.Text = "Not Connected"
    Case 5  ' still connected
      txtConBSts.Text = "Still Connected"
    Case Else
      txtConBSts.Text = "???????"
  End Select

''''''''''
'  Dim strMsg As String
'  strMsg = "Action: " & lblEvent.Caption & _
'     "      ->ConA: " & IDA & " Name:" & NameA & " Type:" & TypeA & " Sts:" & txtConASts.Text & _
'     "      ->ConB: " & IDB & " Name:" & NameB & " Type:" & TypeB & " Sts:" & txtConBSts.Text
'  ShowStatusMsg strMsg
'''''''''
#End If

End Sub





