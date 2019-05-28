VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Object = "{E6F77CB3-6A30-11D5-89E6-00D0B74A80C3}#1.0#0"; "CGCtrl.ocx"
Object = "{97BD7A05-77E0-11D2-8EAE-008048E27A77}#1.0#0"; "beegd10.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form frmUDItemDefs 
   Caption         =   "Library Block Wizard"
   ClientHeight    =   8775
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8460
   ControlBox      =   0   'False
   ForeColor       =   &H00000000&
   Icon            =   "frmUDItemDefs.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   8775
   ScaleWidth      =   8460
   StartUpPosition =   1  'CenterOwner
   Begin VB.Frame frmMasks 
      BorderStyle     =   0  'None
      Caption         =   "Frame1"
      Height          =   3915
      Left            =   0
      TabIndex        =   14
      Top             =   60
      Width           =   6315
      Begin VB.Frame frmShapeButtons 
         BorderStyle     =   0  'None
         Caption         =   "Frame1"
         Height          =   2835
         Left            =   2640
         TabIndex        =   15
         Top             =   600
         Width           =   1155
         Begin VB.CheckBox chkSynchView 
            Caption         =   "Synchronize"
            Height          =   255
            Left            =   0
            TabIndex        =   19
            Top             =   2520
            Value           =   1  'Checked
            Width           =   1215
         End
         Begin VB.CommandButton btnClearShape 
            Caption         =   "< Clear >"
            Height          =   375
            Index           =   1
            Left            =   120
            TabIndex        =   18
            ToolTipText     =   "Clear Shape Assigned to Item "
            Top             =   1800
            Width           =   885
         End
         Begin VB.CommandButton btnAssignClassToShapeDef 
            Caption         =   "< Assign >"
            Height          =   375
            Left            =   120
            TabIndex        =   17
            ToolTipText     =   "Assign Item to Shape"
            Top             =   1320
            Width           =   885
         End
         Begin VB.CommandButton btnCreateShapeDef 
            Caption         =   "New >"
            Height          =   375
            Left            =   120
            TabIndex        =   16
            ToolTipText     =   "Create new Shape-Class association item"
            Top             =   840
            Width           =   885
         End
         Begin MSComDlg.CommonDialog CommDlg 
            Left            =   240
            Top             =   0
            _ExtentX        =   847
            _ExtentY        =   847
            _Version        =   393216
         End
      End
      Begin CGModeler.ucUMLTreeView ucUMLTreeView 
         Height          =   3555
         Left            =   60
         TabIndex        =   20
         ToolTipText     =   "List of available classes"
         Top             =   300
         Width           =   2535
         _ExtentX        =   4260
         _ExtentY        =   6271
      End
      Begin MSComctlLib.TreeView tvwShapes 
         Height          =   3435
         Left            =   3840
         TabIndex        =   21
         ToolTipText     =   "List of Library Blocks"
         Top             =   300
         Width           =   2385
         _ExtentX        =   4207
         _ExtentY        =   6059
         _Version        =   393217
         HideSelection   =   0   'False
         Indentation     =   88
         LabelEdit       =   1
         Sorted          =   -1  'True
         Style           =   7
         SingleSel       =   -1  'True
         Appearance      =   1
      End
      Begin VB.Label lblProjectClasses 
         Alignment       =   2  'Center
         Caption         =   "Structured Class"
         Height          =   195
         Left            =   60
         TabIndex        =   23
         Top             =   0
         Width           =   2535
      End
      Begin VB.Label lblLibraryShapes 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Library Blocks"
         Height          =   195
         Left            =   4545
         TabIndex        =   22
         Top             =   0
         Width           =   1065
      End
   End
   Begin VB.Frame frmButtons 
      BorderStyle     =   0  'None
      Caption         =   "Frame1"
      Height          =   8775
      Left            =   6360
      TabIndex        =   7
      Top             =   0
      Width           =   2115
      Begin VB.CheckBox chkForceShapeReGen 
         Caption         =   "Force Shape Regenerations"
         Height          =   375
         Left            =   60
         TabIndex        =   38
         ToolTipText     =   "Force the current shape to be regenerated based on current configuration."
         Top             =   3840
         Width           =   1395
      End
      Begin VB.Frame frmShapeGenDetails 
         Caption         =   "Auto Shape"
         Height          =   1815
         Left            =   0
         TabIndex        =   29
         Top             =   4320
         Visible         =   0   'False
         Width           =   2055
         Begin VB.TextBox txtHeight 
            Height          =   285
            Left            =   1080
            TabIndex        =   37
            Text            =   "1"
            Top             =   1380
            Width           =   555
         End
         Begin VB.TextBox txtWidth 
            Height          =   285
            Left            =   1080
            TabIndex        =   36
            Text            =   "1"
            Top             =   1020
            Width           =   555
         End
         Begin VB.OptionButton optShapeGen 
            Caption         =   "Size Shape"
            Height          =   255
            Index           =   1
            Left            =   60
            TabIndex        =   33
            Top             =   600
            Width           =   1215
         End
         Begin VB.OptionButton optShapeGen 
            Caption         =   "Fit Connectors"
            Height          =   255
            Index           =   0
            Left            =   60
            TabIndex        =   32
            Top             =   300
            Value           =   -1  'True
            Width           =   1335
         End
         Begin VB.TextBox txtConnectorSpacing 
            Height          =   285
            Left            =   240
            TabIndex        =   30
            Top             =   1380
            Width           =   855
         End
         Begin VB.Label lbHeight 
            Alignment       =   1  'Right Justify
            Caption         =   "Height:"
            Height          =   195
            Left            =   60
            TabIndex        =   35
            Top             =   1440
            Width           =   615
         End
         Begin VB.Label lbWidth 
            Alignment       =   1  'Right Justify
            Caption         =   "Width:"
            Height          =   195
            Left            =   120
            TabIndex        =   34
            Top             =   1080
            Width           =   555
         End
         Begin VB.Label lbConnectorSpacing 
            Caption         =   "Connector Spacing:"
            Height          =   435
            Left            =   240
            TabIndex        =   31
            Top             =   960
            Width           =   795
         End
      End
      Begin VB.CommandButton btnApply 
         Caption         =   "Apply"
         Height          =   375
         Left            =   360
         TabIndex        =   11
         Top             =   960
         Width           =   1335
      End
      Begin VB.CommandButton btnCancel 
         Caption         =   "Cancel"
         Height          =   375
         Left            =   360
         TabIndex        =   10
         Top             =   540
         Width           =   1335
      End
      Begin VB.CommandButton btnExit 
         Caption         =   "OK"
         Height          =   375
         Left            =   360
         TabIndex        =   9
         Top             =   60
         Width           =   1335
      End
      Begin VB.CheckBox chkViewChangeDetails 
         Caption         =   "View Details"
         Height          =   195
         Left            =   360
         TabIndex        =   8
         Top             =   1560
         Value           =   1  'Checked
         Width           =   1215
      End
      Begin CGCtrlLib.CG ShapeGe 
         Height          =   1335
         Left            =   0
         TabIndex        =   12
         Top             =   2400
         Width           =   1755
         _Version        =   65536
         _ExtentX        =   3096
         _ExtentY        =   2355
         _StockProps     =   64
      End
      Begin MSComctlLib.TreeView tvwIcons 
         Height          =   2235
         Left            =   0
         TabIndex        =   40
         Top             =   6480
         Width           =   2025
         _ExtentX        =   3572
         _ExtentY        =   3942
         _Version        =   393217
         HideSelection   =   0   'False
         Indentation     =   88
         LabelEdit       =   1
         Sorted          =   -1  'True
         Style           =   7
         SingleSel       =   -1  'True
         Appearance      =   1
      End
      Begin VB.Label lblIcon 
         Caption         =   "Icon:"
         Height          =   255
         Left            =   0
         TabIndex        =   39
         Top             =   6240
         Width           =   1335
      End
      Begin VB.Label Label1 
         Caption         =   "Not Mapped"
         Height          =   255
         Left            =   720
         TabIndex        =   28
         Top             =   1800
         Width           =   975
      End
      Begin VB.Shape Shape1 
         BackColor       =   &H00000080&
         BorderColor     =   &H00000080&
         FillColor       =   &H00000080&
         FillStyle       =   0  'Solid
         Height          =   195
         Left            =   360
         Top             =   1800
         Width           =   255
      End
      Begin VB.Label Label5 
         Alignment       =   2  'Center
         Caption         =   "Block Preview"
         Height          =   210
         Left            =   -60
         TabIndex        =   13
         Top             =   2160
         Width           =   1695
      End
   End
   Begin VB.Frame frmDetails 
      BorderStyle     =   0  'None
      Caption         =   "    Details"
      Height          =   4755
      Left            =   0
      TabIndex        =   0
      Top             =   4020
      Width           =   6315
      Begin VB.Frame frmConnectorButtons 
         BorderStyle     =   0  'None
         Caption         =   "Frame1"
         Height          =   1395
         Left            =   2700
         TabIndex        =   24
         Top             =   1320
         Width           =   1035
         Begin VB.CommandButton btnClearConnector 
            Caption         =   "< Clear >"
            Height          =   375
            Left            =   30
            TabIndex        =   27
            ToolTipText     =   "Clear Shape assignments to selected items "
            Top             =   960
            Width           =   960
         End
         Begin VB.CommandButton btnAssignConnector 
            Caption         =   "< Assign >"
            Height          =   375
            Left            =   30
            TabIndex        =   26
            ToolTipText     =   "Assign Shape to Item "
            Top             =   480
            Width           =   960
         End
         Begin VB.CommandButton btnCreateConnector 
            Caption         =   "Create >"
            Height          =   375
            Left            =   30
            TabIndex        =   25
            ToolTipText     =   "Create New Connector"
            Top             =   0
            Width           =   960
         End
      End
      Begin VB.CommandButton btnCollapse 
         Caption         =   ">"
         Height          =   220
         Left            =   0
         TabIndex        =   5
         Top             =   5
         Width           =   220
      End
      Begin BeeGrid10.SGGrid gdConnectors 
         Height          =   4215
         Left            =   3840
         TabIndex        =   1
         ToolTipText     =   "List of connectors for block selected in the 'Library Blocks' tree view."
         Top             =   480
         Width           =   2475
         _cx             =   4366
         _cy             =   7435
         DataMode        =   1
         AutoFields      =   -1  'True
         Enabled         =   -1  'True
         GridBorderStyle =   1
         ScrollBars      =   3
         FlatScrollBars  =   0
         ScrollBarTrack  =   0   'False
         DataRowCount    =   2
         BeginProperty HeadingFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         DataColCount    =   2
         HeadingRowCount =   1
         HeadingColCount =   1
         TextAlignment   =   0
         WordWrap        =   0   'False
         Ellipsis        =   1
         HeadingBackColor=   -2147483633
         HeadingForeColor=   -2147483630
         HeadingTextAlignment=   0
         HeadingWordWrap =   0   'False
         HeadingEllipsis =   1
         GridLines       =   1
         HeadingGridLines=   2
         GridLinesColor  =   -2147483633
         HeadingGridLinesColor=   -2147483632
         EvenOddStyle    =   0
         ColorEven       =   -2147483628
         ColorOdd        =   -2147483624
         UserResizeAnimate=   1
         UserResizing    =   3
         RowHeightMin    =   0
         RowHeightMax    =   0
         ColWidthMin     =   0
         ColWidthMax     =   0
         UserDragging    =   2
         UserHiding      =   2
         CellPadding     =   15
         CellBkgStyle    =   1
         CellBackColor   =   -2147483643
         CellForeColor   =   -2147483640
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         FocusRect       =   1
         FocusRectColor  =   0
         FocusRectLineWidth=   1
         TabKeyBehavior  =   0
         EnterKeyBehavior=   0
         NavigationWrapMode=   1
         SkipReadOnly    =   0   'False
         DefaultColWidth =   1200
         DefaultRowHeight=   255
         CellsBorderColor=   0
         CellsBorderVisible=   -1  'True
         RowNumbering    =   0   'False
         EqualRowHeight  =   0   'False
         EqualColWidth   =   0   'False
         HScrollHeight   =   0
         VScrollWidth    =   0
         Format          =   "General"
         Appearance      =   2
         FitLastColumn   =   0   'False
         SelectionMode   =   0
         MultiSelect     =   0
         AllowAddNew     =   0   'False
         AllowDelete     =   0   'False
         AllowEdit       =   -1  'True
         ScrollBarTips   =   0
         CellTips        =   0
         CellTipsDelay   =   1000
         SpecialMode     =   0
         OutlineLines    =   1
         CacheAllRecords =   -1  'True
         ColumnClickSort =   0   'False
         PreviewPaneColumn=   ""
         PreviewPaneType =   0
         PreviewPanePosition=   2
         PreviewPaneSize =   2000
         GroupIndentation=   225
         InactiveSelection=   1
         AutoScroll      =   -1  'True
         AutoResize      =   1
         AutoResizeHeadings=   -1  'True
         OLEDragMode     =   0
         OLEDropMode     =   0
         Caption         =   ""
         ScrollTipColumn =   ""
         MaxRows         =   4194304
         MaxColumns      =   12
         NewRowPos       =   1
         CustomBkgDraw   =   0
         AutoGroup       =   -1  'True
         GroupByBoxVisible=   -1  'True
         GroupByBoxText  =   "Drag a column header here to group by that column"
         AlphaBlendEnabled=   0   'False
         DragAlphaLevel  =   206
         AutoSearch      =   0
         AutoSearchDelay =   2000
         StylesCollection=   $"frmUDItemDefs.frx":0442
         ColumnsCollection=   $"frmUDItemDefs.frx":1ED6
         ValueItems      =   $"frmUDItemDefs.frx":2CAD
      End
      Begin MSComctlLib.TreeView tvwClassItems 
         Height          =   4215
         Left            =   60
         TabIndex        =   2
         ToolTipText     =   "List of class items for selected structured class."
         Top             =   480
         Width           =   2535
         _ExtentX        =   4471
         _ExtentY        =   7435
         _Version        =   393217
         HideSelection   =   0   'False
         Indentation     =   88
         LabelEdit       =   1
         Style           =   7
         Appearance      =   1
      End
      Begin VB.Label Label2 
         Caption         =   "Details"
         Height          =   195
         Left            =   300
         TabIndex        =   6
         Top             =   0
         Width           =   495
      End
      Begin VB.Label lbClassItems 
         Alignment       =   2  'Center
         Caption         =   "Class Items"
         Height          =   255
         Left            =   60
         TabIndex        =   4
         Top             =   180
         Width           =   2595
      End
      Begin VB.Label lbShapeConnectors 
         Alignment       =   2  'Center
         Caption         =   "Connectors"
         Height          =   255
         Left            =   3840
         TabIndex        =   3
         Top             =   180
         Width           =   2505
      End
   End
   Begin VB.Menu mnuObjectDefsRoot 
      Caption         =   ""
      Visible         =   0   'False
      Begin VB.Menu mnuObjectDefs 
         Caption         =   "Rename..."
         Index           =   0
      End
      Begin VB.Menu mnuObjectDefs 
         Caption         =   "Delete"
         Index           =   1
      End
      Begin VB.Menu mnuObjectDefs 
         Caption         =   "-"
         Index           =   2
      End
      Begin VB.Menu mnuObjectDefs 
         Caption         =   "Default Attributes..."
         Index           =   3
      End
   End
   Begin VB.Menu mnuConnectorsRoot 
      Caption         =   ""
      Visible         =   0   'False
      Begin VB.Menu mnuConnectors 
         Caption         =   "Rename..."
         Index           =   0
      End
      Begin VB.Menu mnuConnectors 
         Caption         =   "Delete"
         Index           =   1
      End
   End
   Begin VB.Menu mnuAttribPropertiesRoot 
      Caption         =   ""
      Visible         =   0   'False
      Begin VB.Menu mnuAttribProperties 
         Caption         =   "Properties..."
         Index           =   0
      End
   End
End
Attribute VB_Name = "frmUDItemDefs"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
'
'======================================================================================
Option Explicit

'========================================================
' Declarations
'========================================================

Private m_Projects As Collection
Private m_GeLbrMgr As GeLibraryMgr
Private m_strLibName As String

Private m_bConstructing As Boolean
Private m_bSettingProps As Boolean
Private m_bModified As Boolean
Private m_UDIDefMgr As UDIDefMgr
Private m_currShapeFolder As String
Private m_currShape As String

Private SelectedProjectName As String
Private SelectedProject As rtsProject
Private SelectedPackage As rtsPackage
Private SelectedClass As rtsClass
Private SelectedClassOld As rtsClass
Private ClassVariables As Collection

Private m_collLibraryShapes As Collection
Private m_curUDIDef As UserDefinedItemDef
Private m_iConnectorRow As Integer
Private m_ConnectionInfo As Collection
Private m_curNode As MSComctlLib.Node
Private m_colAppyResult As Collection
Private m_collConnectionDetails As Collection 'Used for ShapeDefs that have no associated UDIDef

Private m_strStartupFolder As String    'The mask dialog can be launched for a single Mask object
Private m_strStartupShape As String    'The mask dialog can be launched for a single Mask object
Private m_ucToolPanel As ucToolPanel
Private m_bChangesPending As Boolean

Const FOLDER_KEY_PREFIX As String = "F_"
Const SHAPE_KEY_PREFIX As String = "S_"
Const FACE_WIDTH As Integer = 750
Const ORDER_WIDTH As Integer = 650

Const IO_KEY_PREFIX As String = "IO_"
Const OP_KEY_PREFIX As String = "OP_"
Const CN_KEY_PREFIX As String = "CN_"
Const VR_KEY_PREFIX As String = "VR_"
Const BR_KEY_PREFIX As String = "BR_"
Const LI_KEY_PREFIX As String = "LI_"

Const COL_NAME = 1
Const COL_FACE = 2
Const COL_ORDER = 3

Const COLOUR_DARK_RED = 128
Const COLOUR_BLACK = 0

'======================================================================================
' End Declarations
'======================================================================================

Public Property Get IsModified() As Boolean
  IsModified = m_bModified
End Property

' The following three properties are used by the ucUMLTreeView control
' to set the currently selected project\package\class

Public Sub SetSelectedProject(selProject As rtsProject)
  Set SelectedProject = selProject
End Sub

Public Sub SetSelectedPackage(selPackage As rtsPackage)
  Set SelectedPackage = selPackage
End Sub

Public Sub SetSelectedClass(selClass As rtsClass)
  Set SelectedClassOld = SelectedClass
  Set SelectedClass = selClass
  FillClassItems
End Sub

Public Property Let LibraryName(ByVal strName As String)
  m_strLibName = strName
End Property

Public Property Set UDIDefMgr(obj As UDIDefMgr)
  Set m_UDIDefMgr = obj
End Property

Public Property Let StartupShape(ByVal strName As String)
  m_strStartupShape = strName
End Property

Public Property Let StartupFolder(ByVal strName As String)
  m_strStartupFolder = strName
End Property

Public Property Set ucToolPanel(obj As ucToolPanel)
  Set m_ucToolPanel = obj
  If m_ucToolPanel Is Nothing Then
    gMsgWnd.LogMessage "Failed to create reference to the Tool Panel."
    Unload Me
  End If
End Property

Private Sub btnCollapse_Click()
    On Error Resume Next
    If btnCollapse.Caption = "<" Then
        frmDetails.Height = 250
        Me.Height = frmMasks.Height + frmDetails.Height + 510
        frmDetails.Top = frmMasks.Height
        lbShapeConnectors.Visible = False
        lbClassItems.Visible = False
        tvwClassItems.Visible = False
        gdConnectors.Visible = False
        frmConnectorButtons.Visible = False
        btnCollapse.Caption = ">"
    Else
        frmDetails.Height = 4755
        Me.Height = 9180
        lbShapeConnectors.Visible = True
        lbClassItems.Visible = True
        tvwClassItems.Visible = True
        gdConnectors.Visible = True
        frmConnectorButtons.Visible = True
        btnCollapse.Caption = "<"
    End If
    btnApply.SetFocus 'Take the focus off the btnCollapse, otherwise it looks wierd
    form_Resize
End Sub

Private Sub btnCreateConnector_Click()
   'Add a new connector based on the currently selected class attribute, operation, ect..
  Dim szConnector As String
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim szItem As String
  Dim szItemSize As String
  Dim i As Long
  Dim j As Long
  Dim szKeyType As String
  Dim aNode As Node
  Dim aConn As CgConnectionDef
  Dim strNameOrig As String
  Dim iNewOrder As Integer
  
  On Error GoTo Error_Handler
  If tvwClassItems.SelectedItem Is Nothing Or m_curUDIDef Is Nothing Then
    Exit Sub
  End If
  
  szConnector = tvwClassItems.SelectedItem.Text
  strNameOrig = szConnector
  j = 1
  'See if there is a connector by this name already
  If Not IsUniqueConnectorName(szConnector) Then
    MsgBox "Connector already exists for this item."
    Exit Sub
  End If
  
  If szConnector <> "" Then
    For Each aNode In tvwClassItems.nodes
      If Len(aNode.Key) > 2 Then                ' a leaf node key
        szKeyType = Left(aNode.Key, 3)
        On Error Resume Next
        If szKeyType = IO_KEY_PREFIX Or szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Or szKeyType = LI_KEY_PREFIX Then
          szItem = aNode.Text
     
          Set aAttr = Nothing
          Set aAttr = SelectedClass.Attributes(szItem)
          If Not aAttr Is Nothing Then
            If szKeyType = VR_KEY_PREFIX And err <> 0 Then
              Set aAttr = ClassVariables(szItem)
              SelectedClass.Attributes.Add aAttr
            End If
            On Error GoTo Error_Handler
            
            If aNode.Selected Then
              aAttr.ConnId = szConnector
              iNewOrder = GenNextConnectorOrder()
              gdConnectors.Rows.Add sgFormatCharSeparatedValue, szConnector & "," & 1 & "," & iNewOrder
              
              Set aConn = New CgConnectionDef
              aConn.itemName = aAttr.Name
              aConn.itemType = idxItemType_Attribute
              aConn.attrType = aAttr.sType
              aConn.operType = 0
              aConn.connName = aAttr.ConnId
              aConn.ItemSizeName = aAttr.dim1
              m_curUDIDef.CgConnectionDefs.Add aConn
              
              SetModifiedConnectorInfo "", aConn.connName, "1", CStr(iNewOrder)
              Exit For
              
            ElseIf aAttr.ConnId = szConnector Then
              aAttr.ConnId = ""
              SetModifiedConnectorInfo szConnector, "", "", ""
              Exit For
            End If
          End If
          
        ElseIf szKeyType = OP_KEY_PREFIX Then
          szItem = aNode.Text
          Set aOper = Nothing
          Set aOper = SelectedClass.Operations(szItem)
          If Not aOper Is Nothing Then
            If aNode.Selected Then
              aOper.ConnId = szConnector
              iNewOrder = GenNextConnectorOrder()
              gdConnectors.Rows.Add sgFormatCharSeparatedValue, szConnector & "," & 1 & "," & iNewOrder
              
              Set aConn = New CgConnectionDef
              aConn.itemName = aOper.Name
              aConn.itemType = idxItemType_Operation
              aConn.attrType = 0
              aConn.operType = aOper.sType
              aConn.connName = aOper.ConnId
              m_curUDIDef.CgConnectionDefs.Add aConn
              SetModifiedConnectorInfo "", aOper.ConnId, "1", CStr(iNewOrder)
              Exit For
              
            ElseIf aOper.ConnId = szConnector Then
              aOper.ConnId = ""
              SetModifiedConnectorInfo szConnector, "", "", ""
              Exit For
            End If
          End If
        End If
      End If
    Next
  End If
    
  Exit Sub
Error_Handler:
  gMsgWnd.LogMessage "Failed assignment. Error: " & err.Description
End Sub

Private Sub btnCreateShapeDef_Click()
  Dim pDef As UserDefinedItemDef
  Dim aProject As rtsProject
  Dim i As Integer
  
  On Error GoTo Error_Handler
  If Len(ucUMLTreeView.ProjectName) = 0 Or Len(ucUMLTreeView.PackagesName) = 0 Or Len(ucUMLTreeView.ClassName) = 0 Then
    MsgBox "Please select a Class", vbInformation
    Exit Sub
  End If
  
  If Projects Is Nothing Then
    GetProjects Projects, m_Projects, CommDlg
  Else
    If Projects.count = 0 Then
      GetProjects Projects, m_Projects, CommDlg
    End If
  End If

  If Projects.count = 0 Then
    MsgBox "No UML project selected.  Dialog will not be properly initialized"
  End If

  For i = 1 To Projects.count
    If doc.activeProject.Name = Projects(i).Name Then
      Set aProject = Projects(i)
      Exit For
    End If
  Next i
     
  If Not m_GeLbrMgr.IsOpened Then
    gMsgWnd.LogMessage "Failed to Create new library block.  Could not find opened block library."
    Exit Sub
  End If
  
  If Not m_UDIDefMgr Is Nothing Then
    Set pDef = CreateShapeDef(aProject)
    pDef.IsDirty = True
    
    If Not pDef Is Nothing Then
        Dim nNewShape As MSComctlLib.Node
        
        Set nNewShape = AddShapeDefToTree(pDef)
        If nNewShape Is Nothing Then
            gMsgWnd.LogMessage "Failed to add library block '" & pDef.GeShape & "'."
            Exit Sub
        End If
        'Auto generate a shape for the newly created shape def.  This shape will only consist
        'of a rectangle with no connectors since the user has not added any yet.  The user
        'will need to update the shape after adding connectors
        AddNewShapeToCollection pDef
        Set m_curUDIDef = pDef
        tvwShapes.Refresh
        tvwShapes_NodeClick nNewShape
    End If
  Else
    gMsgWnd.LogMessage "Failed to create new library block."
  End If
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Item creation error: " & err.Description
End Sub

Private Sub btnApply_Click()
    Dim i As Integer
    Dim cgShapeInfo As cgLibraryShapeDetails
    Dim frmDetails As frmMaskChangeDetails
    
    If Not m_bChangesPending Then Exit Sub
    Set frmDetails = New frmMaskChangeDetails
    Set frmDetails.m_frmParent = Me
    
    On Error GoTo Error_Handler
    If chkViewChangeDetails.Value = 1 Then                    'Create Detail Dialog and get user confirmation
        For i = 1 To m_collLibraryShapes.count
            If m_collLibraryShapes(i).bAdded Then
                Set cgShapeInfo = m_collLibraryShapes(i)
                frmDetails.AddAddedShape cgShapeInfo.strShapeName
                Set cgShapeInfo = Nothing
            End If
            If m_collLibraryShapes(i).bDeleted Then
                Set cgShapeInfo = m_collLibraryShapes(i)
                frmDetails.AddDeletedShape cgShapeInfo.strShapeName
                Set cgShapeInfo = Nothing
            End If
            If m_collLibraryShapes(i).bModified Or m_collLibraryShapes(i).bForceShapeRegeneration Then
                Set cgShapeInfo = m_collLibraryShapes(i)
                If Not m_collLibraryShapes(i).bAdded And Not m_collLibraryShapes(i).bDeleted Then  'Don't want to added twice
                    frmDetails.AddModifiedShape cgShapeInfo.strShapeName
                End If
                Set cgShapeInfo = Nothing
            End If
        Next i
        
        If frmDetails.bNoChanges Then
            Set frmDetails = Nothing
            Exit Sub
        End If
        frmDetails.Show vbModal, Me
        If frmDetails.bCanceled Then Exit Sub
        m_bChangesPending = False

        CommitDetailChanges True
    Else                                      'Commit changes without confirmation
        CommitDetailChanges False
    End If
    
    Set frmDetails = Nothing
    Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Error setting new configuration: " & err.Description
End Sub

Public Sub CommitDetailChanges(bShowDetails As Boolean)
    Dim i As Integer
    Dim pDef As UserDefinedItemDef
    Dim pDefOriginal As UserDefinedItemDef
    Dim pDefCurrent As UserDefinedItemDef
    Dim cgShapeInfo As cgLibraryShapeDetails
    Dim bDoChange As Boolean
    Dim strFolderID As String
    Dim strName As String
    
    On Error GoTo Error_Handler
    i = 1
    frmShapeGenDetails.Visible = False
    
    While i <= m_collLibraryShapes.count
        strFolderID = CStr(m_collLibraryShapes(i).lFolderID)
        'ADDED
        bDoChange = True
        If m_collLibraryShapes(i).bAdded Then
            If bShowDetails Then bDoChange = m_colAppyResult(m_collLibraryShapes(i).strShapeName)
            Set cgShapeInfo = m_collLibraryShapes(i)
            Set pDef = cgShapeInfo.m_UDIDefNew
            If bDoChange Then
                Set cgShapeInfo = m_collLibraryShapes(i)
                If Not pDef Is Nothing Then
                    Dim strGenName As String
                    If cgShapeInfo.strShapeNameNew = "" Then
                        strGenName = cgShapeInfo.strShapeName
                    Else
                        strGenName = cgShapeInfo.strShapeNameNew
                    End If
                                     
                    If Not AutoGenerateShape(strGenName, cgShapeInfo.strFolderName, strFolderID, m_GeLbrMgr, cgShapeInfo) Then
                        gMsgWnd.LogMessage "Failed to auto generate library block '" & pDef.GeShape & "'."
                    End If
                    pDef.IsDirty = True
                    ShowShape pDef.GeFolder, pDef.GeShape
                End If
                Set cgShapeInfo = Nothing
            Else
                Dim strDelShape As String
                If cgShapeInfo.strShapeNameNew = "" Then
                    strDelShape = cgShapeInfo.strShapeName
                Else
                    strDelShape = cgShapeInfo.strShapeNameNew
                End If
                RemoveShapeFromTree m_collLibraryShapes(i).strFolderName, strDelShape
                Set pDef = m_collLibraryShapes(i).m_UDIDefNew
                If pDef.ObjectName = m_curUDIDef.ObjectName Then Set m_curUDIDef = Nothing
                If Not pDef Is Nothing Then
                  m_UDIDefMgr.DeleteUDIDef pDef.ObjectName
                End If
                gdConnectors.Rows.RemoveAll
                tvwClassItems.nodes.Clear
            End If
            Set pDef = Nothing
            Set m_collLibraryShapes(i).m_UDIDefNew = Nothing
            m_collLibraryShapes(i).bAdded = False
            frmShapeGenDetails.Visible = False
            cgShapeInfo.bForceShapeRegeneration = False
            chkForceShapeReGen.Value = 0
        End If
        'DELETED
        If m_collLibraryShapes(i).bDeleted Then
            If bShowDetails Then bDoChange = m_colAppyResult(m_collLibraryShapes(i).strShapeName)
            Set pDefOriginal = m_collLibraryShapes(i).m_UDIDefOriginal
            If bDoChange Then
                Set cgShapeInfo = m_collLibraryShapes(i)
                DeleteShape cgShapeInfo, m_GeLbrMgr
                'Remove UDIDef for this shape
                If Not pDefOriginal Is Nothing Then
                  m_UDIDefMgr.DeleteUDIDef pDefOriginal.ObjectName
                End If
                'Remove the collection entry without screwing up the order
                m_collLibraryShapes.Remove (i)
                i = i - 1
                m_UDIDefMgr.IsDirty = True
                Set cgShapeInfo = Nothing
            Else
                AddShapeToTree m_collLibraryShapes(i).strFolderName, m_collLibraryShapes(i).strShapeName
            End If
            Set pDefOriginal = Nothing
            m_collLibraryShapes(i).bDeleted = False
        End If
        'MODIFIED
        If m_collLibraryShapes(i).bModified Or m_collLibraryShapes(i).bForceShapeRegeneration Then
            If bShowDetails Then bDoChange = m_colAppyResult(m_collLibraryShapes(i).strShapeName)
            Set cgShapeInfo = m_collLibraryShapes(i)
            If bDoChange Then
                Set pDefOriginal = cgShapeInfo.m_UDIDefOriginal
                'Check to see if the connectors have been changed
                strName = IIf(Len(cgShapeInfo.strShapeNameNew) > 0, cgShapeInfo.strShapeNameNew, cgShapeInfo.strShapeName)
                Set pDef = m_UDIDefMgr.GetUDIDef(cgShapeInfo.strFolderName, strName)
                If cgShapeInfo.bIconUpdated Or cgShapeInfo.bConnectorsUpdated Or cgShapeInfo.bForceShapeRegeneration And Not m_collLibraryShapes(i).bAdded Then
                    'Update original UDIDef connector set state
                    
                    If Not UpdateShape(cgShapeInfo.strShapeName, cgShapeInfo.strFolderName, strFolderID, m_GeLbrMgr, cgShapeInfo) Then
                       gMsgWnd.LogMessage "Failed to auto generate library block '" & pDef.GeShape & "'."
                    Else
                       'In this case there's always a pDef associated with the shape
                       If Not pDef Is Nothing Then
                            GetConnectionDetails pDef
                       End If
                    End If
                    cgShapeInfo.bConnectorsUpdated = False
                    cgShapeInfo.bForceShapeRegeneration = False
                    frmShapeGenDetails.Visible = False
                    chkForceShapeReGen.Value = 0
                End If
                
                'See if name has changed
                If cgShapeInfo.strShapeNameNew <> "" And cgShapeInfo.strShapeNameNew <> cgShapeInfo.strShapeName Then
                    If Not RenameShape(cgShapeInfo, m_GeLbrMgr) Then
                        gMsgWnd.LogMessage "Failed to rename library block '" & cgShapeInfo.strShapeName & "''."
                    End If
                    cgShapeInfo.strShapeName = cgShapeInfo.strShapeNameNew
                    cgShapeInfo.strShapeNameNew = ""
                    RefreshConnectorGrid
                ElseIf pDefOriginal Is Nothing And Not cgShapeInfo.m_UDIDefNew Is Nothing Then
                    Set cgShapeInfo.m_UDIDefOriginal = New UserDefinedItemDef
                    cgShapeInfo.m_UDIDefNew.Copy cgShapeInfo.m_UDIDefOriginal
                ElseIf Not pDefOriginal Is Nothing Then
                    Set pDef = m_UDIDefMgr.GetUDIDef(pDefOriginal.GeFolder, pDefOriginal.GeShape)
                    If Not pDef Is Nothing Then pDef.Copy cgShapeInfo.m_UDIDefOriginal
                End If
                'If we cleared a shape assignment, we have a UDIDef with no shape\folder associate it.  Get rid of it.
                If cgShapeInfo.strShapeName = "" And Not pDef Is Nothing Then m_UDIDefMgr.DeleteUDIDef pDef.ObjectName
                If Not pDef Is Nothing Then ShowShape pDef.GeFolder, pDef.GeShape
                If Not pDef Is Nothing Then pDef.IsDirty = True
                Set pDef = Nothing
            Else
                Dim n As Integer
                Dim strAttrib As String
                Dim strOldCon As String
                Dim strNewCon As String
                Dim aAttr As CgAttribute
                Dim aOper As CgOperation
                Dim selClass As rtsClass
                    
                If Not cgShapeInfo.m_UDIDefOriginal Is Nothing Then
                   'If this shape was renamed, restore old name
                   If cgShapeInfo.strShapeNameNew <> "" Then RestoreOldUDIDefName cgShapeInfo
                    
                    'There was an original UDIDef, so restore it
                   Set pDefOriginal = cgShapeInfo.m_UDIDefOriginal
                   Set pDefCurrent = m_UDIDefMgr.GetUDIDef(pDefOriginal.GeFolder, pDefOriginal.GeShape)
                   If pDefCurrent Is Nothing Then
                        Set pDefCurrent = New UserDefinedItemDef
                        pDefOriginal.Copy pDefCurrent
                        m_UDIDefMgr.UDIDefs.Add pDefCurrent
                   Else
                        pDefOriginal.Copy pDefCurrent
                   End If
                   If m_curNode.Text = cgShapeInfo.strShapeName Then FillClassItems
                ElseIf Not cgShapeInfo.m_UDIDefNew Is Nothing Then
                   'There was no UDIDef origionally, but one was created.  In this case remove the new UDIDef
                    If m_curNode.Text = cgShapeInfo.strShapeName Then
                        gdConnectors.Rows.RemoveAll
                        tvwClassItems.nodes.Clear
                    End If
                    m_UDIDefMgr.DeleteUDIDef cgShapeInfo.m_UDIDefNew.ObjectName
                End If
               
               'Restore Connections
               Dim collConnDefs As Collection
               If pDefCurrent Is Nothing Then Set pDefCurrent = m_UDIDefMgr.GetUDIDef(cgShapeInfo.strFolderName, cgShapeInfo.strShapeName)
               If Not pDefCurrent Is Nothing Then
                    If Not pDefCurrent.CgConnectionDefs Is Nothing Then
                        For n = 1 To pDefCurrent.CgConnectionDefs.count
                            pDefCurrent.CgConnectionDefs.Remove 1
                        Next n
                    End If
                    
                    If Not cgShapeInfo.m_collConnectors Is Nothing Then
                        For n = 1 To cgShapeInfo.m_collConnectors.count
                            cgShapeInfo.m_collConnectors.Remove 1
                            cgShapeInfo.m_collFace.Remove 1
                            cgShapeInfo.m_collOrder.Remove 1
                        Next n
                    End If
                    
                    Set collConnDefs = cgShapeInfo.m_UDIDefOriginal.CgConnectionDefs
                    If Not collConnDefs Is Nothing Then
                        For n = 1 To collConnDefs.count
                            pDefCurrent.CgConnectionDefs.Add collConnDefs(n)
                        Next n
                    End If
                    If m_curNode.Text = cgShapeInfo.strShapeName Then RefreshConnectorGrid  'This will refresh the grid in case this node is selected
                    Set collConnDefs = Nothing
               End If
               
               'Restore connector mappings for each class
               For n = 1 To cgShapeInfo.m_collConnAssignment.count
                   Set selClass = GetClassFromString(cgShapeInfo.m_collConnAssignment(n), strAttrib, strNewCon, strOldCon)
                   If selClass Is Nothing Then Exit Sub
                   
                   On Error Resume Next
                   Set aAttr = selClass.Attributes(strAttrib)
                   If Not aAttr Is Nothing Then
                       aAttr.ConnId = strOldCon
                   Else
                       Set aOper = selClass.Operations(strAttrib)
                       If Not aOper Is Nothing Then aOper.ConnId = strOldCon
                   End If
                   Set aAttr = Nothing
                   Set aOper = Nothing
               Next n
               Set selClass = Nothing
               
            End If
            
            For n = 1 To cgShapeInfo.m_collConnAssignment.count
                cgShapeInfo.m_collConnAssignment.Remove 1
            Next n
            
            cgShapeInfo.strShapeNameNew = ""
            Set cgShapeInfo = Nothing
            Set m_collLibraryShapes(i).m_UDIDefNew = Nothing
            m_collLibraryShapes(i).bConnectorsUpdated = False
            m_collLibraryShapes(i).bModified = False   'Connectors and assignments are already in the 'new' state
        End If
        i = i + 1
    Wend
    
    Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Error setting new configuration: " & err.Description
    Resume Next
End Sub

Public Sub SetApplyResult(colApplyResult As Collection)
    Dim i As Integer
    On Error Resume Next
    If colApplyResult Is Nothing Or m_colAppyResult Is Nothing Then
        gMsgWnd.LogMessage "Failed to write back change status."
        Exit Sub
    End If
    Set m_colAppyResult = colApplyResult
End Sub

Private Sub btnExit_Click()
    Dim nRet As Integer

    On Error Resume Next
    If m_bChangesPending Then
        nRet = MsgBox("Save changes?", vbYesNoCancel)
        If nRet = vbYes Then
            btnApply_Click              'Save new configuration
            Unload Me
            Exit Sub
        ElseIf nRet = vbNo Then
            btnCancel_Click             'Restore old configuration
            Unload Me
            Exit Sub
        Else                            'Cancel exit
            Exit Sub
        End If
    Else
        Unload Me
    End If
End Sub

Private Sub btnCancel_Click()
    Dim i As Integer
    Dim pDefCurrent As UserDefinedItemDef
    Dim pDefOriginal As UserDefinedItemDef
    Dim pDefCol As UserDefinedItemDef
    Dim cgShapeInfo As cgLibraryShapeDetails
    Dim n As Integer
    Dim strAttrib As String
    Dim strOldCon As String
    Dim strNewCon As String
    Dim aAttr As CgAttribute
    Dim aOper As CgOperation
    Dim selClass As rtsClass
    
    On Error GoTo Error_Handler
    'Have to set back renamed UDIDefs' Shape names back to the original names, restore connectors ect...
    'It's enough to restore the original UDIDef for this purpose (if one exists)
    For i = 1 To m_collLibraryShapes.count
        'ADDED
        If m_collLibraryShapes(i).bAdded Then
            Set pDefCurrent = m_collLibraryShapes(i).m_UDIDefNew
            If Not pDefCurrent Is Nothing Then
              m_UDIDefMgr.DeleteUDIDef pDefCurrent.ObjectName
            End If
        End If

        'MODIFIED
        If m_collLibraryShapes(i).bModified Then
           Set cgShapeInfo = m_collLibraryShapes(i)
           If Not cgShapeInfo.m_UDIDefOriginal Is Nothing Then
              'There was an original UDIDef, so restore it
              If cgShapeInfo.strShapeNameNew <> "" Then RestoreOldUDIDefName cgShapeInfo
              Set pDefOriginal = cgShapeInfo.m_UDIDefOriginal
              Set pDefCurrent = m_UDIDefMgr.GetUDIDef(pDefOriginal.GeFolder, pDefOriginal.GeShape)
              If pDefCurrent Is Nothing Then
                 Set pDefCurrent = New UserDefinedItemDef
                 pDefOriginal.Copy pDefCurrent
                 m_UDIDefMgr.UDIDefs.Add pDefCurrent
              Else
                 pDefOriginal.Copy pDefCurrent
              End If
           ElseIf Not cgShapeInfo.m_UDIDefNew Is Nothing Then
             'There was no UDIDef origionally, but one was created.  In this case remove the new UDIDef
              m_UDIDefMgr.DeleteUDIDef cgShapeInfo.m_UDIDefNew.ObjectName
           End If
           
           'Restore connectors
           Dim collConnDefs As Collection
           If pDefCurrent Is Nothing Then Set pDefCurrent = m_UDIDefMgr.GetUDIDef(cgShapeInfo.strFolderName, cgShapeInfo.strShapeName)
           If Not pDefCurrent Is Nothing Then
                If Not pDefCurrent.CgConnectionDefs Is Nothing Then
                    For n = 1 To pDefCurrent.CgConnectionDefs.count
                        pDefCurrent.CgConnectionDefs.Remove 1
                    Next n
                End If
                
                If Not cgShapeInfo.m_collConnectors Is Nothing Then
                    For n = 1 To cgShapeInfo.m_collConnectors.count
                        cgShapeInfo.m_collConnectors.Remove 1
                        cgShapeInfo.m_collFace.Remove 1
                        cgShapeInfo.m_collOrder.Remove 1
                    Next n
                End If
                
                If Not cgShapeInfo.m_UDIDefOriginal Is Nothing Then
                    Set collConnDefs = cgShapeInfo.m_UDIDefOriginal.CgConnectionDefs
                    If Not collConnDefs Is Nothing Then
                        For n = 1 To collConnDefs.count
                            pDefCurrent.CgConnectionDefs.Add collConnDefs(n)
                        Next n
                    End If
                    Set collConnDefs = Nothing
                End If
           End If
               
           'Restore connector mappings for each class
           For n = 1 To cgShapeInfo.m_collConnAssignment.count
               Set selClass = GetClassFromString(cgShapeInfo.m_collConnAssignment(n), strAttrib, strNewCon, strOldCon)
               If selClass Is Nothing Then Exit Sub
               
               On Error Resume Next
               Set aAttr = selClass.Attributes(strAttrib)
               If Not aAttr Is Nothing Then
                   aAttr.ConnId = strOldCon
               Else
                   Set aOper = selClass.Operations(strAttrib)
                   If Not aOper Is Nothing Then aOper.ConnId = strOldCon
               End If
               Set aAttr = Nothing
               Set aOper = Nothing
           Next n
           Set selClass = Nothing
           
           'Restore Connections
           Set pDefCurrent = m_UDIDefMgr.GetUDIDef(cgShapeInfo.strFolderName, cgShapeInfo.strShapeName)
           If Not pDefCurrent Is Nothing Then
                For n = 1 To pDefCurrent.CgConnectionDefs.count
                    pDefCurrent.CgConnectionDefs.Remove 1
                Next n
                Set collConnDefs = cgShapeInfo.m_UDIDefOriginal.CgConnectionDefs
                For n = 1 To collConnDefs.count
                    pDefCurrent.CgConnectionDefs.Add collConnDefs(n)
                Next n
           End If
           Set cgShapeInfo = Nothing
        End If
     Next i
        
    Unload Me
    Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Error restoring original configuration: " & err.Description
    Unload Me
End Sub

Private Function GetClassFromString(strClassInfo As String, ByRef strAttrib As String, ByRef strNewCon As String, ByRef strOldCon As String) As rtsClass
    Dim strProj As String
    Dim strPackage As String
    Dim strClass As String
    Dim selProj As rtsProject
    Dim selPackage As rtsPackage
    Dim aClassDetail
    Dim i As Integer
    Dim j As Integer
    Dim jUBound As Integer
   
    Set GetClassFromString = Nothing
    aClassDetail = Split(strClassInfo, "_")
    jUBound = UBound(aClassDetail)
    If jUBound < 5 Then
        gMsgWnd.LogMessage "Failed to restore old connection information"
        Exit Function
    End If
    
    strProj = aClassDetail(0)
    strPackage = aClassDetail(1)
    strClass = aClassDetail(2)
    strAttrib = aClassDetail(3)
    strOldCon = aClassDetail(4)
    strNewCon = aClassDetail(5)
    
    For i = 1 To Projects.count
        If strProj = Projects(i).Name Then
            Set selProj = Projects(i)
            Exit For
        End If
    Next i
    If selProj Is Nothing Then Exit Function
    
    For i = 1 To selProj.Packages.count
        If strPackage = selProj.Packages(i).Name Then
            Set selPackage = selProj.Packages(i)
            Exit For
        End If
    Next i
    If selPackage Is Nothing Then Exit Function
        
    For i = 1 To selPackage.Classes.count
        If strClass = selPackage.Classes(i).Name Then
            Set GetClassFromString = selPackage.Classes(i)
            Exit For
        End If
    Next i
End Function

Private Sub chkForceShapeReGen_Click()
    Dim strKey As String
    Dim cgShapeInfo As cgLibraryShapeDetails
    
    On Error Resume Next
    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then Exit Sub

    If chkForceShapeReGen.Value = 1 Then
        cgShapeInfo.bForceShapeRegeneration = True
        ShowShapeGenerationFrame cgShapeInfo.m_bSizeShape, cgShapeInfo.m_ConnectorSpacing
        frmShapeGenDetails.Visible = True
        m_bChangesPending = True
        ShowDetailsPane
    Else
        cgShapeInfo.bForceShapeRegeneration = False
        If Not cgShapeInfo.bAdded And Not cgShapeInfo.bConnectorsUpdated Then
            frmShapeGenDetails.Visible = False
        End If
    End If
End Sub

Private Sub optShapeGen_Click(Index As Integer)
    Dim strKey As String
    Dim cgShapeInfo As cgLibraryShapeDetails
    
    On Error Resume Next
    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then Exit Sub
  
    If optShapeGen(0) Then
        cgShapeInfo.m_bSizeShape = False
        ShowShapeGenerationFrame False, cgShapeInfo.m_ConnectorSpacing
    Else
        cgShapeInfo.m_bSizeShape = True
        ShowShapeGenerationFrame True, cgShapeInfo.m_ConnectorSpacing
    End If
End Sub

Private Sub tvwIcons_NodeClick(ByVal Node As MSComctlLib.Node)
  Dim FolderName As String
  Dim ShapeName As String
  Dim shapeDetails As cgLibraryShapeDetails
  
  If GetNodeFolderAndShapeName(Node, FolderName, ShapeName) Then
    If Len(FolderName) > 0 And Len(ShapeName) > 0 Then
      If Not m_curUDIDef Is Nothing Then
        If m_curUDIDef.GeIconFolder <> FolderName Or m_curUDIDef.GeIconShape <> ShapeName Then
          m_curUDIDef.GeIconLibrary = m_strLibName
          m_curUDIDef.GeIconFolder = FolderName
          m_curUDIDef.GeIconShape = ShapeName
          
          For Each shapeDetails In m_collLibraryShapes
            If shapeDetails.strFolderName = m_curUDIDef.GeFolder And shapeDetails.strShapeName = m_curUDIDef.GeShape Then
              If shapeDetails.IconFolder <> FolderName Or shapeDetails.IconShape <> ShapeName Then
                shapeDetails.IconLibrary = m_strLibName
                shapeDetails.IconFolder = FolderName
                shapeDetails.IconShape = ShapeName
                shapeDetails.bModified = True
                shapeDetails.bIconUpdated = True
                Exit For
              End If
            End If
          Next
          m_bChangesPending = True
        End If
      End If
    End If
  End If
End Sub

Private Sub selectIcon(FolderName As String, ShapeName As String)
  Dim aNode As MSComctlLib.Node
  
  If Len(FolderName) > 0 And Len(ShapeName) > 0 Then
    For Each aNode In tvwIcons.nodes
      If aNode.Selected Then aNode.Selected = False
      If aNode.Text = ShapeName And InStr(aNode.Key, "S_") > 0 Then
        If Not aNode.Parent Is Nothing Then
          If aNode.Parent.Text = FolderName Then
            aNode.Selected = True
            aNode.EnsureVisible
            Exit For
          End If
        End If
      End If
    Next
  Else
    For Each aNode In tvwIcons.nodes
      If aNode.Selected Then aNode.Selected = False
    Next
  End If
End Sub

Private Sub txtConnectorSpacing_Change()
    Dim strKey As String
    Dim cgShapeInfo As cgLibraryShapeDetails
    
    On Error Resume Next
    If Len(txtConnectorSpacing.Text) <= 0 Then Exit Sub
    If Not IsNumeric(txtConnectorSpacing.Text And txtConnectorSpacing.Text <> ".") Then
        MsgBox "Please enter a valid number."
        Exit Sub
    End If
    
    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then Exit Sub
    
    cgShapeInfo.m_ConnectorSpacing = txtConnectorSpacing.Text
End Sub

Private Sub txtWidth_Change()
    Dim strKey As String
    Dim cgShapeInfo As cgLibraryShapeDetails
    
    On Error Resume Next
    If Len(txtWidth.Text) <= 0 Then Exit Sub
    If Not IsNumeric(txtWidth.Text) And txtWidth.Text <> "." Then
        MsgBox "Please enter a valid number."
        Exit Sub
    End If
    
    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then Exit Sub
    
    cgShapeInfo.m_DefaultWidth = txtWidth.Text
End Sub

Private Sub txtHeight_Change()
    Dim strKey As String
    Dim cgShapeInfo As cgLibraryShapeDetails
    
    On Error Resume Next
    If Len(txtHeight.Text) <= 0 Then Exit Sub
    If Not IsNumeric(txtHeight.Text) And txtHeight.Text <> "." Then
        MsgBox "Please enter a valid number."
        Exit Sub
    End If
    
    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then Exit Sub
    
    cgShapeInfo.m_DefaultHeight = txtHeight.Text
End Sub

Private Sub ShowShapeGenerationFrame(bSizeShape As Boolean, strConnectorSpacing As String)
    If bSizeShape Then        'Shape will be sized based on connectors & the assigned spacing
        txtConnectorSpacing.Text = strConnectorSpacing
        txtConnectorSpacing.Visible = True
        lbConnectorSpacing.Visible = True
        txtWidth.Visible = False
        txtHeight.Visible = False
        lbWidth.Visible = False
        lbHeight.Visible = False
        frmShapeGenDetails.Height = 1815
    Else                                    'Default rectangle size will be used for shape, and connectors will be spaced evenly
        txtConnectorSpacing.Visible = False
        lbConnectorSpacing.Visible = False
        txtWidth.Visible = True
        txtHeight.Visible = True
        lbWidth.Visible = True
        lbHeight.Visible = True
        frmShapeGenDetails.Height = 1815
    End If
End Sub

Private Sub Form_Activate()
  Static bFirst As Boolean
  On Error Resume Next
  If Not bFirst Then
    bFirst = True
    DoInit                      'populate the various controls
    InitShapeLibraryCollection  'populate library shape\folder collection
  End If
End Sub

Private Sub Form_GotFocus()
    ShapeGe.Redraw
End Sub

Private Sub Form_Initialize()
  On Error Resume Next
  Set m_GeLbrMgr = New GeLibraryMgr
  m_strStartupShape = ""
  SetHelperModuleSecondaryGeCtrl ShapeGe
End Sub

Private Sub Form_Load()
  Dim aInfo As ConnectionInfo
  
  On Error GoTo Error_Handler
  If Projects Is Nothing Then
     GetProjects Projects, m_Projects, CommDlg
     If Not g_DrawingDefMgr.LoadModelDef() Then
         gMsgWnd.LogMessage "Error loading xml model definition"
     End If
  Else
    If Projects.count = 0 Then
       GetProjects Projects, m_Projects, CommDlg
        If Not g_DrawingDefMgr.LoadModelDef() Then
            gMsgWnd.LogMessage "Error loading xml model definition"
        End If
    End If
  End If
    
  m_currShapeFolder = ""
  m_currShape = ""
  Set m_curNode = Nothing
  
  If Projects.count = 0 Then
    MsgBox "No UML project selected.  Dialog will not be properly initialized"
  End If
  
  'Populate the UML project selection control
  If Projects.count > 0 Then ucUMLTreeView.PopulateProjectsList Projects
  ucUMLTreeView.HideClassDetails = True
  
  Me.WindowState = 0
  
  lbShapeConnectors.Visible = False
  lbClassItems.Visible = False
  tvwClassItems.Visible = False
  gdConnectors.Visible = False
  Set m_colAppyResult = New Collection
  Me.Height = 4680
  frmDetails.Height = 250
  form_Resize
  Exit Sub
Error_Handler:
  gMsgWnd.LogMessage "Library Block Wizard load error: " & err.Description
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, y As Single)
  Screen.MousePointer = vbArrow
End Sub

Private Sub InitShapeLibraryCollection()
  Dim i As Long
  Dim j As Long
  Dim shapeKey As String
  Dim collFolders As Collection
  Dim collShapes As Collection
  Dim collFolderIDs As Collection
  Dim pDef As UserDefinedItemDef
  
  On Error GoTo Error_Handler
  Set collFolders = New Collection
  Set collFolderIDs = New Collection
  Set collShapes = New Collection
  
  If Not m_collLibraryShapes Is Nothing Then
    If m_collLibraryShapes.count > 0 Then Exit Sub
    Set m_collLibraryShapes = Nothing
  End If
    
  Set m_collLibraryShapes = New Collection

  'Populate shape library list used to track changes during a dialog session
  If Not GetFoldersAndFolderIDs(collFolders, collFolderIDs, m_GeLbrMgr) Then Exit Sub
  If collFolders.count > 0 Then m_currShapeFolder = collFolders(1)
  For i = 1 To collFolders.count
    If m_GeLbrMgr.GetAllShapesForFolder(collShapes, collFolders(i)) Then
        For j = 1 To collShapes.count
          Dim cgShapeInfo As cgLibraryShapeDetails
          
          Set cgShapeInfo = New cgLibraryShapeDetails
          cgShapeInfo.strFolderName = collFolders(i)
          cgShapeInfo.strShapeName = collShapes(j).ShapeName
          cgShapeInfo.lFolderID = collFolderIDs(i)
          cgShapeInfo.bModified = False
          cgShapeInfo.bAdded = False
          cgShapeInfo.bDeleted = False
          
          'See if there is a UDIDef associated with this shape
          If Not m_UDIDefMgr Is Nothing Then
            Set pDef = m_UDIDefMgr.GetUDIDef(cgShapeInfo.strFolderName, cgShapeInfo.strShapeName)
            If Not pDef Is Nothing Then
                Set cgShapeInfo.m_UDIDefOriginal = New UserDefinedItemDef
                pDef.Copy cgShapeInfo.m_UDIDefOriginal
                ' the Icon info is serialized on the pDef object, and it should be copied to the
                ' shapeInfo, because the shapeInfo is used to specify shape appearance
                cgShapeInfo.IconLibrary = pDef.GeIconLibrary
                cgShapeInfo.IconFolder = pDef.GeIconFolder
                cgShapeInfo.IconShape = pDef.GeIconShape
            End If
          End If
          
          shapeKey = collFolders(i) & "_" & collShapes(j).ShapeName
          m_collLibraryShapes.Add cgShapeInfo, shapeKey
        Next j
    End If
    ' KAB setting collShapes = Nothing causes a crash on the next iteration
    ' the following is much better.
    Set collShapes = New Collection
  Next i
  Exit Sub
Error_Handler:
  gMsgWnd.LogMessage "Error initializing library blocks collection: " & err.Description
End Sub

Public Sub AddNewShapeToCollection(pDef As UserDefinedItemDef)
    Dim cgShapeInfo As cgLibraryShapeDetails
    Dim cgShapeInfoDeleted As cgLibraryShapeDetails
    Dim strKey As String
    Dim i As Integer
    
    If m_collLibraryShapes Is Nothing Or pDef Is Nothing Then
        InitShapeLibraryCollection
    End If
    
    On Error Resume Next
    strKey = pDef.GeFolder & "_" & pDef.GeShape
    Set cgShapeInfoDeleted = m_collLibraryShapes(strKey)
    If cgShapeInfoDeleted Is Nothing Then       'Create new one
        Set cgShapeInfo = New cgLibraryShapeDetails
        cgShapeInfo.strFolderName = pDef.GeFolder
        cgShapeInfo.strShapeName = pDef.GeShape
        cgShapeInfo.lFolderID = GetFolderID()
        cgShapeInfo.bDeleted = False
        cgShapeInfo.bModified = False
        cgShapeInfo.bAdded = True
        cgShapeInfo.bDeleted = False
        Set cgShapeInfo.m_UDIDefOriginal = Nothing
        Set cgShapeInfo.m_UDIDefNew = pDef
        
        m_collLibraryShapes.Add cgShapeInfo, strKey
    Else                    'We already have an existing UDIDef For this shape, so just clear it out
        Dim pDef2 As UserDefinedItemDef
        
        For i = 1 To cgShapeInfoDeleted.m_collConnAssignment.count
            cgShapeInfoDeleted.m_collConnAssignment.Remove 1
            cgShapeInfoDeleted.m_collConnectors.Remove 1
            cgShapeInfoDeleted.m_collFace.Remove 1
        Next i
        If Not cgShapeInfoDeleted.m_UDIDefOriginal Is Nothing Then
            For i = 1 To cgShapeInfoDeleted.m_UDIDefOriginal.CgConnectionDefs.count
                cgShapeInfoDeleted.m_UDIDefOriginal.CgConnectionDefs.Remove 1
            Next i
        End If
        
        'There could be cases were users made several deletes\adds for the same object without
        'applying.  Detect these cases and take appropriate action
        If cgShapeInfoDeleted.bDeleted Then
            cgShapeInfoDeleted.bAdded = False   'They cancel each other out
        Else
            cgShapeInfoDeleted.bAdded = True
        End If
        cgShapeInfoDeleted.bDeleted = False
        cgShapeInfoDeleted.bModified = False
    End If
    m_bChangesPending = True
End Sub

Private Sub AddRenamedShapeToCollection(strShapeNew As String)
    Dim cgShapeInfo As cgLibraryShapeDetails
    Dim cgShapeInfoDeleted As cgLibraryShapeDetails
    Dim strKey As String
        
    If m_collLibraryShapes Is Nothing Then
        gMsgWnd.LogMessage "Failed to add new shape definition to collection."
        Exit Sub
    End If
        
    On Error Resume Next
    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then
        gMsgWnd.LogMessage "Failed to update the status of library block '" & m_currShape & "'."
        Exit Sub
    End If
    'In case this shape is renamed again, make sure the key will match the new name
    m_collLibraryShapes.Remove strKey
    
    cgShapeInfo.strShapeNameNew = strShapeNew
    cgShapeInfo.bModified = True
    strKey = m_currShapeFolder & "_" & strShapeNew
    
    Set cgShapeInfoDeleted = m_collLibraryShapes(strKey)
    If cgShapeInfoDeleted Is Nothing Then
        m_collLibraryShapes.Add cgShapeInfo, strKey
    Else            'Case where a shape by the same name has already been deleted.
        Dim nRet As Integer
        Dim i As Integer
        Dim pDef As UserDefinedItemDef
        
        For i = 1 To cgShapeInfoDeleted.m_collConnAssignment.count
            cgShapeInfoDeleted.m_collConnAssignment.Remove 1
            cgShapeInfoDeleted.m_collConnectors.Remove 1
            cgShapeInfoDeleted.m_collFace.Remove 1
        Next i
        If Not cgShapeInfoDeleted.m_UDIDefOriginal Is Nothing Then
            For i = 1 To cgShapeInfoDeleted.m_UDIDefOriginal.CgConnectionDefs.count
                cgShapeInfoDeleted.m_UDIDefOriginal.CgConnectionDefs.Remove 1
            Next i
        End If
        Set pDef = m_UDIDefMgr.GetUDIDef(m_currShapeFolder, strShapeNew)
        If Not pDef Is Nothing Then
            For i = 1 To pDef.CgConnectionDefs.count
                pDef.CgConnectionDefs.Remove 1
            Next i
        End If
        Set pDef = Nothing
        
        cgShapeInfoDeleted.bDeleted = False
        cgShapeInfoDeleted.bModified = True
    End If
    m_bChangesPending = True
End Sub

Private Sub AddDeletedShapeToCollection()
    Dim cgShapeInfo As cgLibraryShapeDetails
    Dim strKey As String
        
    If m_collLibraryShapes Is Nothing Then
        gMsgWnd.LogMessage "Failed to add deleted library block definition."
        Exit Sub
    End If
    
    On Error Resume Next
    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then
        gMsgWnd.LogMessage "Failed to update the status of library block '" & m_currShape & "'."
        Exit Sub
    End If
    
    If cgShapeInfo.m_UDIDefOriginal Is Nothing Then
        Set cgShapeInfo.m_UDIDefOriginal = New UserDefinedItemDef
        m_curUDIDef.Copy cgShapeInfo.m_UDIDefOriginal
    End If
    
    If cgShapeInfo.bAdded Then
        cgShapeInfo.bDeleted = False
    Else
        cgShapeInfo.bDeleted = True
    End If
    cgShapeInfo.bModified = False
    cgShapeInfo.bAdded = False
    m_bChangesPending = True
End Sub

Private Sub AddModifiedConnectorMapping(strAttrib As String, strConOld As String, strConNew As String)
    Dim cgShapeInfo As cgLibraryShapeDetails
    Dim strKey As String
        
    'When a user selects a node in the shape tree view, assume that there are potential changes to the connections
    'Use this 'copy' of the original connections in case the user changes his mind
    On Error Resume Next
    If m_collLibraryShapes Is Nothing Then
        gMsgWnd.LogMessage "Failed to add library block."
        Exit Sub
    End If
     
    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then
        gMsgWnd.LogMessage "Failed to update the status of connector mapping for library block '" & m_currShape & "'."
        Exit Sub
    End If
    
    If cgShapeInfo.m_UDIDefOriginal Is Nothing Then
        Dim pDef As UserDefinedItemDef
        
        Set pDef = m_UDIDefMgr.GetUDIDef(m_currShapeFolder, m_currShape)
        Set cgShapeInfo.m_UDIDefOriginal = New UserDefinedItemDef
        If Not pDef Is Nothing Then pDef.Copy cgShapeInfo.m_UDIDefOriginal
    End If
    
    cgShapeInfo.bModified = True
    strKey = m_curUDIDef.ProjectName & "_" & m_curUDIDef.PackageName & "_" & m_curUDIDef.ClassName & "_" & strAttrib & "_" & strConOld & "_" & strConNew
    If cgShapeInfo.m_collConnAssignment(strKey) Is Nothing Then
        cgShapeInfo.m_collConnAssignment.Add strKey, strKey
        cgShapeInfo.bModified = True
    End If
    m_bChangesPending = True
End Sub

Private Sub SetModifiedConnectorInfo(strConnOld As String, strConnNew As String, strFace As String, strOrder As String, Optional bExisting As Boolean)
    Dim cgShapeInfo As cgLibraryShapeDetails
    Dim strKey As String
    Dim strValNew As String
    
    On Error GoTo Error_Handler
    'When a user selects a node in the shape tree view, assume that there are potential changes to the connections
    'Use this 'copy' of the original connections in case the user changes his mind
    If m_collLibraryShapes Is Nothing Then
        InitShapeLibraryCollection
    End If
        
    strKey = m_currShapeFolder & "_" & m_currShape
    On Error Resume Next
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then
        gMsgWnd.LogMessage "Failed to update the status of library block '" & m_currShape & "'."
        Exit Sub
    End If
    
    On Error GoTo Error_Handler
    
    If cgShapeInfo.m_UDIDefOriginal Is Nothing And cgShapeInfo.m_UDIDefNew Is Nothing Then
        Dim pDef As UserDefinedItemDef
        
        Set pDef = m_UDIDefMgr.GetUDIDef(m_currShapeFolder, m_currShape)
        Set cgShapeInfo.m_UDIDefOriginal = New UserDefinedItemDef
        If Not pDef Is Nothing Then pDef.Copy cgShapeInfo.m_UDIDefOriginal
    End If
    
    'If connector was added, have to update connections in UDIDef if this is for a new shape
    If Not cgShapeInfo.m_UDIDefNew Is Nothing Then
        If cgShapeInfo.m_UDIDefNew.CgConnectionDefs.count <> m_curUDIDef.CgConnectionDefs.count Then
            Dim pConnDef As CgConnectionDef, pConnDefNew As CgConnectionDef
            Dim i As Integer
            
            If m_curUDIDef.CgConnectionDefs.count > cgShapeInfo.m_UDIDefNew.CgConnectionDefs.count Then
                For i = 1 To cgShapeInfo.m_UDIDefNew.CgConnectionDefs.count
                    cgShapeInfo.m_UDIDefNew.CgConnectionDefs.Remove 1
                Next i
                
                For Each pConnDef In m_curUDIDef.CgConnectionDefs
                    Set pConnDefNew = New CgConnectionDef
                    pConnDef.Copy pConnDefNew
                    cgShapeInfo.m_UDIDefNew.CgConnectionDefs.Add pConnDefNew
                Next
            End If
        End If
    End If
    
    On Error Resume Next
    strValNew = ""
    strValNew = cgShapeInfo.m_collConnectors(strConnNew)

    On Error GoTo Error_Handler
    If strConnNew = "" Then                                      'A connector was removed
        cgShapeInfo.m_collConnectors.Remove strConnOld
        cgShapeInfo.m_collFace.Remove strConnOld
        cgShapeInfo.m_collOrder.Remove strConnOld
        cgShapeInfo.bConnectorsUpdated = True
        cgShapeInfo.bModified = True
        m_bChangesPending = True
    ElseIf strConnOld = "" And strValNew = "" Then               'A connector was added
        cgShapeInfo.m_collConnectors.Add strConnNew, strConnNew
        cgShapeInfo.m_collFace.Add strFace, strConnNew
        cgShapeInfo.m_collOrder.Add strOrder, strConnNew
        If Not bExisting Then                                    'This prevents marking as modified on initialization call
            cgShapeInfo.bConnectorsUpdated = True
            cgShapeInfo.bModified = True
            m_bChangesPending = True
        End If
    ElseIf strConnOld <> "" And strConnNew <> strConnOld Then    'A connector was renamed.  Make sure key gets updated too
        cgShapeInfo.m_collConnectors.Remove strConnOld
        cgShapeInfo.m_collFace.Remove strConnOld
        cgShapeInfo.m_collOrder.Remove strConnOld
        cgShapeInfo.m_collConnectors.Add strConnNew, strConnNew
        cgShapeInfo.m_collFace.Add strFace, strConnNew
        cgShapeInfo.m_collOrder.Add strOrder, strConnNew
        cgShapeInfo.bConnectorsUpdated = True
        cgShapeInfo.bModified = True
        m_bChangesPending = True
    ElseIf strConnOld = strConnNew Then                          'A connector's properties were modified (face, order)
        cgShapeInfo.m_collFace.Remove strConnOld
        cgShapeInfo.m_collOrder.Remove strConnOld
        cgShapeInfo.m_collFace.Add strFace, strConnNew
        cgShapeInfo.m_collOrder.Add strOrder, strConnNew
        If Not bExisting Then
            cgShapeInfo.bConnectorsUpdated = True
            cgShapeInfo.bModified = True
            m_bChangesPending = True
        End If
    End If
    'This prevents making an unnecesary call for a madification
    If cgShapeInfo.bAdded Or cgShapeInfo.bDeleted Then cgShapeInfo.bModified = False
    ShowOrHideShapeDetailsFrame
    Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Failed to update connector for library block " & m_currShape & " :" & err.Description
End Sub

Private Sub SetModifiedInfoToCollection()
    Dim cgShapeInfo As cgLibraryShapeDetails
    Dim strKey As String

    On Error GoTo Error_Handler
    'When a user selects a node in the shape tree view, assume that there are potential changes to the connections
    'Use this 'copy' of the original connections in case the user changes his mind
    If m_collLibraryShapes Is Nothing Then
        gMsgWnd.LogMessage "Failed to add library block."
        Exit Sub
    End If

    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then
        gMsgWnd.LogMessage "Failed to update the status of library block '" & m_currShape & "'."
       Exit Sub
    End If

    If cgShapeInfo.m_UDIDefOriginal Is Nothing And cgShapeInfo.m_UDIDefNew Is Nothing Then
        Dim pDef As UserDefinedItemDef
        Set pDef = m_UDIDefMgr.GetUDIDef(m_currShapeFolder, m_currShape)
        If Not pDef Is Nothing Then
            Set cgShapeInfo.m_UDIDefNew = New UserDefinedItemDef
            pDef.Copy cgShapeInfo.m_UDIDefNew
        End If
    End If

    cgShapeInfo.bModified = True
    m_bChangesPending = True

    Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Failed to update status as 'modified' for library block  " & m_currShape & " :" & err.Description
End Sub

Private Sub form_Resize()
    On Error Resume Next
    If btnCollapse.Caption = ">" Then
        lbShapeConnectors.Visible = False
        lbClassItems.Visible = False
        tvwClassItems.Visible = False
        gdConnectors.Visible = False
        frmConnectorButtons.Visible = False
        
        frmDetails.Height = 250
    
        frmMasks.Width = Abs(Me.Width - frmButtons.Width - 210)
        frmMasks.Height = Abs(Me.Height - frmDetails.Height - 510)
        
        frmDetails.Width = Abs(Me.Width) - frmButtons.Width
        frmDetails.Top = frmMasks.Height + 100
        
        ucUMLTreeView.Width = Abs(Abs(frmMasks.Width - frmShapeButtons.Width) / 2) '  + 250)
        ucUMLTreeView.Height = frmMasks.Height * 0.94
        lblProjectClasses.Width = ucUMLTreeView.Width
        tvwShapes.Left = ucUMLTreeView.Width + frmShapeButtons.Width + 50
        tvwShapes.Width = Abs(Abs(frmMasks.Width - frmShapeButtons.Width) / 2 - 250)
        tvwShapes.Height = frmMasks.Height * 0.9
        lblLibraryShapes.Width = tvwShapes.Width
        frmShapeButtons.Left = ucUMLTreeView.Width - 50
        lblLibraryShapes.Left = tvwShapes.Left
        frmButtons.Left = frmMasks.Width
        
    Else
        lbShapeConnectors.Visible = True
        lbClassItems.Visible = True
        tvwClassItems.Visible = True
        gdConnectors.Visible = True
        frmConnectorButtons.Visible = True
        
        frmMasks.Width = Abs(Me.Width - frmButtons.Width - 210)
        frmMasks.Height = Abs(Me.Height * 0.5 - 255)
        
        ucUMLTreeView.Width = Abs(Abs(frmMasks.Width - frmShapeButtons.Width) / 2) ' + 250)
        ucUMLTreeView.Height = frmMasks.Height * 0.94
        lblProjectClasses.Width = ucUMLTreeView.Width
        tvwShapes.Width = Abs(Abs(frmMasks.Width - frmShapeButtons.Width) / 2 - 250)
        tvwShapes.Height = frmMasks.Height * 0.9
        tvwShapes.Height = frmMasks.Height * 0.9
        lblLibraryShapes.Width = tvwShapes.Width
        frmShapeButtons.Left = ucUMLTreeView.Width - 50
        tvwShapes.Left = ucUMLTreeView.Width + frmShapeButtons.Width + 50
        lblLibraryShapes.Left = tvwShapes.Left
        frmButtons.Left = frmMasks.Width
     
        frmDetails.Width = frmMasks.Width
        frmDetails.Height = Abs(Me.Height * 0.5 - 255)
        frmDetails.Top = frmMasks.Height + 100
        
        tvwClassItems.Width = ucUMLTreeView.Width - 240 'Abs(Abs(frmDetails.Width - frmConnectorButtons.Width) / 2) ' - 100)
        tvwClassItems.Height = frmDetails.Height * 0.87
        lbClassItems.Width = tvwClassItems.Width
        gdConnectors.Width = tvwShapes.Width
        gdConnectors.Height = frmDetails.Height * 0.87
        gdConnectors.Left = tvwShapes.Left
        lbShapeConnectors.Width = gdConnectors.Width
        lbShapeConnectors.Left = gdConnectors.Left
        frmConnectorButtons.Left = tvwClassItems.Width + 260
    End If
    
    btnApply.SetFocus
End Sub

Private Sub Form_Terminate()
  On Error Resume Next
  
  SetHelperModuleSecondaryGeCtrl Nothing
  Set m_GeLbrMgr = Nothing
  Set m_UDIDefMgr = Nothing
End Sub

Private Sub DoInit()
  Dim bRet As Boolean
  
  On Error GoTo Error_Handler
  ShapeGe.Enabled = False  '  accept no user input!
  ShapeGe.InitNew
  ShapeGe.MarginDisplay = False
  ShapeGe.Grid = False
  
  If Len(m_strLibName) > 0 Then
    ShapeGe.AttachLibrary m_strLibName
    bRet = m_GeLbrMgr.OpenLibrary(m_strLibName, False)
    If bRet Then
      InitLibraryLists
      initIconTreeView
    End If
    InitializeConnectorGrid
    If tvwShapes.nodes.count = 3 And m_strStartupShape <> "" Then tvwShapes_NodeClick tvwShapes.nodes.Item(3)
  End If
  
  Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Library Block Wizard initialization error: " & err.Description
End Sub

Private Sub InitializeConnectorGrid()
  Dim aCol As SGColumn
  Dim ctrl As SGControl
  Dim vis As SGValueItems
  Dim i As Integer

  On Error GoTo Error_Handler
  gdConnectors.GroupByBoxVisible = False
  gdConnectors.HeadingTextAlignment = sgAlignCenterCenter
  gdConnectors.ScrollBars = sgSBAll
  gdConnectors.Redraw sgRedrawAll
  gdConnectors.Columns.RemoveAll
  gdConnectors.UserDragging = sgNoRowColDrag
    
  Set aCol = gdConnectors.Columns.Add("Name")
  aCol.Width = Abs(gdConnectors.Width - FACE_WIDTH - ORDER_WIDTH - 35)
  Set ctrl = aCol.Control
  ctrl.Type = sgCellTextBox
  aCol.ReadOnly = True
  aCol.SortOrder = sgSortDescending
  
  Set aCol = gdConnectors.Columns.Add("Face")
  aCol.Width = FACE_WIDTH
  Set ctrl = aCol.Control
  ctrl.Type = sgCellDropList
  Set vis = aCol.ValueItems
  vis.Add idxAttr_L, szAttr_L
  vis.Add idxAttr_R, szAttr_R
  vis.Add idxAttr_T, szAttr_T
  vis.Add idxAttr_B, szAttr_B
  ctrl.PopupRows = 4
  ctrl.ShowButton = sgShowButtonFocused
  aCol.DefaultValue = szAttr_L
  aCol.ReadOnly = False
  
  Set aCol = gdConnectors.Columns.Add("Order")
  aCol.Width = ORDER_WIDTH
  Set ctrl = aCol.Control
  ctrl.Type = sgCellDropList
  Set vis = aCol.ValueItems
  For i = 1 To CONST_ORDER_MAX
    vis.Add i, CStr(i)
  Next i
  ctrl.PopupRows = 4
  ctrl.ShowButton = sgShowButtonFocused
  aCol.DefaultValue = "1"
  aCol.ReadOnly = False
  
  gdConnectors.Rows.RemoveAll False
  Exit Sub
  
Error_Handler:
    gMsgWnd.LogMessage "Connection grid initialization error: " & err.Description
End Sub

Private Sub Form_Unload(Cancel As Integer)
    SetHelperModuleSecondaryGeCtrl Nothing
    If Not m_ucToolPanel Is Nothing Then
      m_ucToolPanel.GetAttachedLibraries  'This call will update the shapes in the tool panel list
    End If
End Sub


Private Sub gdConnectors_AfterEdit(ByVal RowKey As Long, ByVal ColIndex As Long)
    Dim strFace As String
    Dim strOrder As String
    Dim strConn As String
        
    On Error Resume Next
    If Len(m_currShape) <= 0 Then Exit Sub
    GetConnectorCellValues strConn, strFace, strOrder, RowKey
    SetModifiedConnectorInfo strConn, strConn, strFace, strOrder
End Sub

Private Sub GetConnectorCellValues(ByRef strConn As String, ByRef strFace As String, ByRef strOrder As String, ByVal RowKey As Long)
    Dim iFace As Integer
        
    On Error Resume Next
    strConn = gdConnectors.Rows(RowKey).Cells(COL_NAME - 1).Value
    strOrder = gdConnectors.Rows(RowKey).Cells(COL_ORDER - 1).Value
       
    Select Case gdConnectors.Rows(RowKey).Cells(COL_FACE - 1).Value
        Case "Left":
            iFace = 1
        Case "Right":
            iFace = 2
        Case "Top":
            iFace = 3
        Case "Bottom":
            iFace = 4
        Case 1:
            iFace = 1
        Case 2:
            iFace = 2
        Case 3:
            iFace = 3
        Case 4:
            iFace = 4
    End Select
    
    strFace = CStr(iFace)
    Debug.Print strConn & ", " & strFace & ", " & strOrder
End Sub


Private Sub gdConnectors_ButtonClick(ByVal RowKey As Long, ByVal ColIndex As Long, Cancel As Boolean)
    If m_iConnectorRow >= 0 Then UnHighlightRow m_iConnectorRow
    m_iConnectorRow = gdConnectors.Row
    HighlightRow m_iConnectorRow
End Sub

Private Sub gdConnectors_MouseDown(Button As Integer, Shift As Integer, X As Single, y As Single)
  If Button = 2 Then
    PopupMenu mnuConnectorsRoot
  End If
End Sub

Private Sub gdConnectors_MouseUp(Button As Integer, Shift As Integer, X As Single, y As Single)
  Dim aNode As Node
  Dim szConnector As String
  Dim szKeyType As String
  Dim szItem As String
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim cgConnDef As CgConnectionDef
  Dim strConnID As String
  Dim strMappedItem As String
  Dim i As Integer
  
  On Error GoTo Error_Handler
  If Button = vbLeftButton Then
    szConnector = ""
    Select Case gdConnectors.HitTest(X, y)
       Case sgHitCell
          If m_iConnectorRow >= 0 Then UnHighlightRow m_iConnectorRow
          szConnector = gdConnectors.Rows.At(gdConnectors.Row).Cells(0).Text
          m_iConnectorRow = gdConnectors.Row
          HighlightRow m_iConnectorRow
       Case sgHitCellButton
          If m_iConnectorRow >= 0 Then UnHighlightRow m_iConnectorRow
          szConnector = gdConnectors.Rows.At(gdConnectors.Row).Cells(0).Text
          m_iConnectorRow = gdConnectors.Row
          HighlightRow m_iConnectorRow
       End Select
    
    'Find the mapped class if one exists.
    If szConnector = "" Then Exit Sub
    If Not m_curUDIDef Is Nothing Then
        Set cgConnDef = m_curUDIDef.FindConnection(szConnector)
        If Not cgConnDef Is Nothing Then
            strConnID = cgConnDef.itemID
            strMappedItem = cgConnDef.itemName
        End If
        If strMappedItem = "" Then                   'Item not mapped
            For Each aNode In tvwClassItems.nodes    'Clear last selected item
                aNode.Selected = False
            Next
            Exit Sub
        End If
    End If
    
    If chkSynchView.Value = 1 Then
        For Each aNode In tvwClassItems.nodes
          aNode.Selected = False
          If Len(aNode.Key) > 2 Then ' a leaf node key
            szKeyType = Left(aNode.Key, 3)
            If szKeyType = IO_KEY_PREFIX Or szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Or szKeyType = LI_KEY_PREFIX Then
              szItem = aNode.Text
              
              On Error Resume Next
              Set aAttr = Nothing
              Set aAttr = SelectedClass.Attributes(szItem)
              If Not aAttr Is Nothing Then
                If Not aAttr Is Nothing Then
                  If szKeyType = VR_KEY_PREFIX And err <> 0 Then
                    Set aAttr = ClassVariables(szItem)
                  End If
                  On Error GoTo Error_Handler
                  
                  If aAttr.ConnId = szConnector Or aAttr.obj.GUID = strConnID Then
                    aNode.Selected = True
                  End If
                End If
              End If
              
            ElseIf szKeyType = OP_KEY_PREFIX Then
              szItem = aNode.Text
              Set aOper = Nothing
              Set aOper = SelectedClass.Operations(szItem)
              If Not aOper Is Nothing Then
                If aOper.ConnId = szConnector Or aOper.obj.GUID = strConnID Then
                  aNode.Selected = True
                End If
              End If
            End If
          End If
        Next
    End If
  End If
  
  Exit Sub
Error_Handler:
  MsgBox "Connector shape click error: " & err.Description
End Sub

'==================================================================
' Shapes
'==================================================================

Private Sub ShowShape(strFolder As String, strShape As String)
  Dim GeID As Long
  Dim strpath As String
  
  On Error Resume Next
  If Not ShapeExists(GetFolderID(), strShape, m_GeLbrMgr) Then
    ShapeGe.SelectAll
    ShapeGe.Delete
    Exit Sub
  End If
 
  ShapeGe.InitNew
  ShapeGe.Grid = False
  ShapeGe.MarginDisplay = False
  ShapeGe.DrawInsertionPoints = True
  ShapeGe.DrawFieldBox = False
  ShapeGe.DrawingWidth = 2
  ShapeGe.DrawingHeight = 2
  ShapeGe.ZoomPage
  
  ShapeGe.UsePictureColor = True
  GeID = ShapeGe.CreateShape(m_strLibName, strFolder, strShape, 1, 1)
  If GeID < 1 Or err <> 0 Then
    Exit Sub
  End If
  ShapeGe.DrawFieldBox = False
   
' ScaleDwgForViewing
  ShapeGe.ZoomExtents
  ShapeGe.SelAdd GeID
  ShapeGe.SelRemoveAll
  ShapeGe.Redraw
End Sub

Private Sub ScaleDwgForViewing()
  ' set up so don't show page area
  On Error Resume Next
  Dim llX As Single, llY As Single, urX As Single, urY As Single
  Dim dInflate As Single
  Dim strFmt As String
  Dim strWT As String, strHT As String
    
  ShapeGe.DrawingOriginX = -10000#
  ShapeGe.DrawingOriginY = -10000#
  ShapeGe.DrawingWidth = 0.01
  ShapeGe.DrawingHeight = 0.01
  ShapeGe.PageWidth = 0.01
  ShapeGe.PageHeight = 0.01
  
  ShapeGe.SelectAll
  ShapeGe.GetExtents llX, llY, urX, urY
  ShapeGe.SelRemoveAll

  ' extend area by 10%
  dInflate = 0.2
  
  If llX > 0# Then
    llX = llX - (dInflate * llX)
  Else
    llX = llX + (dInflate * llX)
  End If
  If llY > 0# Then
    llY = llY - (dInflate * llY)
  Else
    llY = llY + (dInflate * llY)
  End If
  If urX > 0# Then
    urX = urX + (dInflate * urX)
  Else
    urX = urX - (dInflate * urX)
  End If
  If urY > 0# Then
    urY = urY + (dInflate * urY)
  Else
    urY = urY - (dInflate * urY)
  End If

  ShapeGe.ZoomRect llX, llY, urX, urY
End Sub
Private Sub InitLibraryLists()
  Dim i As Long
  Dim j As Long
  Dim collFolders As Collection
  Dim collShapes As Collection
  Dim collShapeIDs As Collection
  Dim collFolderIDs As Collection
  Dim folderKey As String
  Dim shapeKey As String
  Dim rootNode As Node
  Dim nFolder As Node
  Dim aNode As Node
  Dim bShapeFound As Boolean
  Dim pDef As UserDefinedItemDef
  Dim iFolderID As Integer
  
  On Error GoTo Error_Handler
  bShapeFound = False
  m_bConstructing = True
  Set collFolders = New Collection
  Set collFolderIDs = New Collection
  Set collShapes = New Collection
  Set collShapeIDs = New Collection
  
  iFolderID = -1
  'Populate the library shape tree view
  Set rootNode = tvwShapes.nodes.Add(, , "ROOT", "Library Blocks")
  
  If Not GetFoldersAndFolderIDs(collFolders, collFolderIDs, m_GeLbrMgr) Then Exit Sub
  If m_strStartupShape = "" Then             'Launched form the Simulation Menu.  All shapes will be included
      For i = 1 To collFolders.count
        folderKey = FOLDER_KEY_PREFIX & collFolderIDs(i)
        tvwShapes.nodes.Add "ROOT", tvwChild, folderKey, collFolders(i)
        Set collShapes = New Collection
        If m_GeLbrMgr.GetAllShapesForFolder(collShapes, collFolders(i)) Then
          For j = 1 To collShapes.count
            shapeKey = folderKey & SHAPE_KEY_PREFIX & Format(j, "0000") & collShapes(j).ShapeName
            Set aNode = tvwShapes.nodes.Add(folderKey, tvwChild, shapeKey, collShapes(j).ShapeName)
            
            On Error Resume Next
            Set pDef = m_UDIDefMgr.GetUDIDef(collFolders(i), collShapes(j).ShapeName)
            If pDef Is Nothing Then             'Colour it Red
                aNode.ForeColor = COLOUR_DARK_RED
            End If
          Next j
        End If
        Set collShapes = Nothing
      Next i
      rootNode.Expanded = True
  Else                                      'Launched from a shape instance...only that shape will be included
    On Error Resume Next
    iFolderID = collFolderIDs(m_strStartupFolder)
    If iFolderID < 0 Then Exit Sub         'Startup folder invalid
    
    Set pDef = m_UDIDefMgr.GetUDIDef(m_strStartupFolder, m_strStartupShape)
      
    On Error GoTo Error_Handler
    folderKey = FOLDER_KEY_PREFIX & iFolderID
    Set nFolder = tvwShapes.nodes.Add("ROOT", tvwChild, folderKey, m_strStartupFolder)
    
    shapeKey = folderKey & SHAPE_KEY_PREFIX & Format(j, "0000") & m_strStartupShape
    Set aNode = tvwShapes.nodes.Add(folderKey, tvwChild, shapeKey, m_strStartupShape)
    If pDef Is Nothing Then             'Colour it Red
        aNode.ForeColor = COLOUR_DARK_RED
    End If
    tvwShapes_NodeClick aNode
    rootNode.Expanded = True
    nFolder.Expanded = True
    
    
    On Error GoTo Error_Handler
    If Not pDef Is Nothing Then
        Set m_curUDIDef = pDef
        Set m_curNode = aNode
        If Not ShapeExists(GetFolderID(), pDef.GeShape, m_GeLbrMgr) Then
            AddNewShapeToCollection pDef
        End If
       ' If Not pDef Is Nothing Then GetConnectionDetails pDef
    End If
  End If
  
  tvwShapes.Sorted = True
  m_bConstructing = False
  Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Failed to populate library blocks tree view: " & err.Description
    Unload Me
End Sub

Private Sub initIconTreeView()
  Dim i As Long
  Dim j As Long
  Dim collFolders As Collection
  Dim collShapes As Collection
  Dim collShapeIDs As Collection
  Dim collFolderIDs As Collection
  Dim folderKey As String
  Dim shapeKey As String
  Dim rootNode As Node
  Dim nFolder As Node
  Dim aNode As Node
  Dim bShapeFound As Boolean
  Dim pDef As UserDefinedItemDef
  Dim iFolderID As Integer
  
  On Error GoTo Error_Handler
  bShapeFound = False
  Set collFolders = New Collection
  Set collFolderIDs = New Collection
  Set collShapes = New Collection
  Set collShapeIDs = New Collection
  
  iFolderID = -1
  'Populate the library shape tree view
  Set rootNode = tvwIcons.nodes.Add(, , "ROOT", "Icons")
  
  If Not GetFoldersAndFolderIDs(collFolders, collFolderIDs, m_GeLbrMgr) Then Exit Sub
  For i = 1 To collFolders.count
    folderKey = FOLDER_KEY_PREFIX & collFolderIDs(i)
    tvwIcons.nodes.Add "ROOT", tvwChild, folderKey, collFolders(i)
    Set collShapes = New Collection
    If m_GeLbrMgr.GetAllShapesForFolder(collShapes, collFolders(i)) Then
      For j = 1 To collShapes.count
        shapeKey = folderKey & SHAPE_KEY_PREFIX & Format(j, "0000") & collShapes(j).ShapeName
        Set aNode = tvwIcons.nodes.Add(folderKey, tvwChild, shapeKey, collShapes(j).ShapeName)
      Next j
    End If
    Set collShapes = Nothing
  Next i
  rootNode.Expanded = True
  
  tvwIcons.Sorted = True
  Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Failed to populate library blocks tree view: " & err.Description
    Unload Me
End Sub


Private Sub btnAssignClassToShapeDef_Click()
  AssignShapeToCurItemDef True
End Sub

Private Sub btnClearShape_Click(Index As Integer)
  On Error Resume Next
  AssignShapeToCurItemDef False
End Sub

Private Sub AssignShapeToCurItemDef(bAssign As Boolean)
    ' assign/unassign
    Dim UDIDef As UserDefinedItemDef
    Dim UserObjName As String
    Dim i As Long
    Dim aProject As rtsProject
    Dim aCI As rtsClass
    Dim aAttr As CgAttribute
    Dim newAttr As CgAttribute
    Dim strKey As String
    Dim cgShapeInfo As cgLibraryShapeDetails
    
    On Error Resume Next
    For i = 1 To Projects.count
      If doc.activeProject.Name = Projects(i).Name Then
        Set aProject = Projects(i)
        Exit For
      End If
    Next i
    
    'Retrieve UDIDef for current selected Shape Def
    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then
        gMsgWnd.LogMessage "Failed to update library block mapping for '" & m_currShape & "'."
        Exit Sub
    End If
    
    Set UDIDef = m_UDIDefMgr.GetUDIDef(m_currShapeFolder, m_currShape)
    If Not UDIDef Is Nothing Then
      If bAssign Then
        UDIDef.GeLibrary = m_strLibName
        UDIDef.GeFolder = m_currShapeFolder
        UDIDef.GeShape = m_currShape
        
        UDIDef.ProjectName = ucUMLTreeView.ProjectName
        UDIDef.PackageName = ucUMLTreeView.PackagesName
        UDIDef.ClassName = ucUMLTreeView.ClassName
        UDIDef.EmptyCollections
        
        cgShapeInfo.EmptyCollections
        gdConnectors.Rows.RemoveAll
        
        If GetClassInfo(aProject, UDIDef.PackageName, UDIDef.ClassName, aCI) Then
          UDIDef.PackageName = aCI.PackageName
          m_curNode.ForeColor = COLOUR_BLACK
          If Not aCI Is Nothing Then
            UDIDef.ID = aCI.Class.GUID
            For Each aAttr In aCI.Attributes
              Set newAttr = New CgAttribute
              aAttr.Copy newAttr
              UDIDef.Attributes.Add newAttr
            Next
            SetModifiedInfoToCollection
          End If
        End If
        Set m_curUDIDef = UDIDef
        
      Else
        ' clear it
        UDIDef.GeLibrary = ""
        UDIDef.GeFolder = ""
        UDIDef.GeShape = ""
        UDIDef.DestroyAll
        
        ucUMLTreeView.ClassName = ""
        ucUMLTreeView.ProjectName = ""
        ucUMLTreeView.PackagesName = ""
        
        m_UDIDefMgr.DeleteUDIDef UDIDef.ObjectName
        Set m_curUDIDef = Nothing
        
        m_curNode.ForeColor = COLOUR_DARK_RED
        SetModifiedInfoToCollection
        tvwClassItems.nodes.Clear
        'gdConnectors.Rows.RemoveAll
        RefreshConnectorGrid
      End If
    Else
        'This shape has no associated UDIDef so create a new one and assign it
        Set UDIDef = CreateShapeDef(aProject)
        
        UDIDef.GeLibrary = m_strLibName
        UDIDef.GeFolder = m_currShapeFolder
        UDIDef.GeShape = m_currShape
        UDIDef.GeShapeID = GetShapeID(m_currShapeFolder, m_currShape)
        
        Set m_curUDIDef = UDIDef
        m_curNode.ForeColor = COLOUR_BLACK
        SetModifiedInfoToCollection
        GetConnectionDetails UDIDef
        RefreshConnectorGrid
   End If
   m_UDIDefMgr.IsDirty = True
End Sub


Private Sub tvwClassItems_MouseDown(Button As Integer, Shift As Integer, X As Single, y As Single)
  If Button = 2 Then
    PopupMenu mnuAttribPropertiesRoot
  End If
End Sub

Private Sub tvwShapes_MouseDown(Button As Integer, Shift As Integer, X As Single, y As Single)
  If Button = 2 Then
    PopupMenu mnuObjectDefsRoot
  End If
End Sub

'==============================================================================================
' Menu Handlers
'==============================================================================================
Private Sub mnuObjectDefs_Click(Index As Integer)
  On Error Resume Next
  Select Case Index
      Case 0
        DoObjectDefRename
      Case 1
        DoObjectDelete
      Case 2
        ' --
      Case 3
        DoObjectDefEditAttributes
  End Select
End Sub

Private Sub mnuConnectors_Click(Index As Integer)
  On Error Resume Next
  Select Case Index
      Case 0
        DoConnectorRename
      Case 1
        DoConnectorDelete
  End Select
End Sub

Private Sub mnuAttribProperties_Click(Index As Integer)
  Dim idx As Long
  
  On Error Resume Next
  Select Case Index
      Case 0
        DoAttribProperties
  End Select
End Sub

Private Sub DoObjectDefRename()
  Dim strNewName As String
  Dim strFolderID As String
  Dim pDef As UserDefinedItemDef
  
  On Error GoTo Error_Handler
  If m_curNode Is Nothing Then
    Exit Sub
  End If
  
  strNewName = InputBox("Enter new name for '" & m_currShape & "'", "Rename Library Block", m_currShape)
  If Len(strNewName) < 1 Then Exit Sub
  If Len(strNewName) > 32 Then
    MsgBox "Library block names must be between 1 and 32 characters in length.", vbExclamation
    Exit Sub
  End If
  
  'Make sure new shape name is unique
  If Not IsUniqueShapeName2(strNewName) Then
    MsgBox "Library block name must be unique."
    Exit Sub
  End If
  
  AddRenamedShapeToCollection strNewName
  'Rename shape in tree view
  Set pDef = m_UDIDefMgr.GetUDIDef(m_currShapeFolder, m_currShape)
  'If a UDIDef exists for this shape, renmae it
  If Not pDef Is Nothing Then pDef.GeShape = strNewName
  m_curNode.Text = strNewName
  tvwShapes.Refresh
  tvwShapes_NodeClick m_curNode
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Failed to rename library block '" & m_currShape & "':" & err.Description
End Sub
    
Private Sub DoObjectDelete()
  Dim strFolderID As String
  Dim pDef As UserDefinedItemDef
  
  On Error GoTo Error_Handler
  If m_curNode Is Nothing Then
    Exit Sub
  End If
   
  AddDeletedShapeToCollection
  
  'Remove from tree view
  tvwShapes.nodes.Remove m_curNode.Index
  'Set a different current node
  If tvwShapes.nodes.count > 3 Then
    tvwShapes_NodeClick tvwShapes.nodes(3)
  End If
  tvwShapes.Refresh
  tvwClassItems.nodes.Clear
  gdConnectors.Rows.RemoveAll False
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Failed to delete library block '" & m_currShape & "':" & err.Description
End Sub

Private Sub DoObjectDefEditAttributes()
  Dim frm As frmUDItemDefVars
  Dim objDef As UserDefinedItemDef
  
  On Error Resume Next
  If Not m_UDIDefMgr Is Nothing Then
    Set objDef = m_UDIDefMgr.GetUDIDef(m_currShapeFolder, m_currShape)
    If Not objDef Is Nothing Then
      Set frm = New frmUDItemDefVars
      Set frm.m_curUDIDef = objDef
      frm.m_bDef = True
      frm.Show vbModal, Me
    End If
  End If
End Sub

Private Sub DoConnectorRename()
  Dim strNewName As String
  Dim strOldName As String
  Dim strFace As String, strOrder As String
  Dim iColName As Integer, iColFace As Integer, iColOrder As Integer
  Dim i As Integer
  
  On Error GoTo Error_Handler
  If m_iConnectorRow < 0 Then Exit Sub                  'No row selected
  iColName = gdConnectors.Columns("Name").Position
  iColFace = gdConnectors.Columns("Face").Position
  iColOrder = gdConnectors.Columns("Order").Position
  strOldName = gdConnectors.Rows.Current.Cells(iColName).Value
  
  strNewName = InputBox("Enter new name for '" & strOldName & "'", "Rename Connector", strOldName)
  If Len(strNewName) < 1 Then Exit Sub
  If Len(strNewName) > 32 Then
    MsgBox "Connector names must be between 1 and 32 characters in length.", vbExclamation
    Exit Sub
  End If
  If Not IsUniqueConnectorName(strNewName) Then
    MsgBox "Connector name already exists.", vbExclamation
    Exit Sub
  End If
  
  gdConnectors.Rows.Current.Cells(iColName).Value = strNewName
  
  If m_curUDIDef Is Nothing Then Exit Sub
  For i = 1 To m_curUDIDef.CgConnectionDefs.count
    If m_curUDIDef.CgConnectionDefs(i).connName = strOldName Then
        GetConnectorCellValues strNewName, strFace, strOrder, gdConnectors.Rows.Current.Key
        SetModifiedConnectorInfo strOldName, strNewName, strFace, strOrder
        m_curUDIDef.CgConnectionDefs(i).connName = strNewName
        Exit For
    End If
  Next i
  
  'If this connector is mapped to a class, update the name in that class
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim szItem As String
  Dim szKeyType As String
  Dim aNode As Node

  For Each aNode In tvwClassItems.nodes
    On Error Resume Next
    If aNode.Selected Then
        szItem = aNode.Text
        szKeyType = Left(aNode.Key, 3)
        If szKeyType = IO_KEY_PREFIX Or szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Or szKeyType = LI_KEY_PREFIX Then
            Set aAttr = Nothing
            Set aAttr = SelectedClass.Attributes(szItem)
            If Not aAttr Is Nothing Then
                If szKeyType = VR_KEY_PREFIX And err <> 0 Then
                  Set aAttr = ClassVariables(szItem)
                End If
                On Error GoTo Error_Handler
                aAttr.ConnId = strNewName
                Exit For
            End If
        ElseIf szKeyType = OP_KEY_PREFIX Then
            szItem = aNode.Text
            Set aOper = Nothing
            Set aOper = SelectedClass.Operations(szItem)
            If Not aOper Is Nothing Then
                aOper.ConnId = strNewName
                Exit For
            End If
        End If
    End If
  Next
  
  Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Failed to rename connector '" & strOldName & "':" & err.Description
End Sub

Private Sub DoConnectorDelete()
  On Error GoTo Error_Handler
  
  Dim szConnector As String
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim szItem As String
  Dim szType As String
  Dim i As Long
  Dim aNode As Node
  Dim szKeyType As String
  
  'Remove assignment to UML class if one exists
  If m_iConnectorRow < 0 Then Exit Sub                  'No row selected
  szConnector = gdConnectors.CurrentCell.Row.Cells(0)
  For Each aNode In tvwClassItems.nodes
    If aNode.Selected Then
      If Len(aNode.Key) > 2 Then ' leaf node
        szKeyType = Left(aNode.Key, 3)
        On Error Resume Next
        If szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = IO_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Or szKeyType = LI_KEY_PREFIX Then
          szItem = aNode.Text
          Set aAttr = Nothing
          Set aAttr = SelectedClass.Attributes(szItem)
          If Not aAttr Is Nothing Then
            If szKeyType = VR_KEY_PREFIX And err <> 0 Then
              Set aAttr = ClassVariables(szItem)
            End If
            On Error GoTo Error_Handler
            
            If Not aAttr Is Nothing Then aAttr.ConnId = ""
          End If
        ElseIf szKeyType = OP_KEY_PREFIX Then
          szItem = aNode.Text
          Set aOper = Nothing
          Set aOper = SelectedClass.Operations(szItem)
          If Not aOper Is Nothing Then
            For i = 1 To SelectedClass.Operations.count
              If SelectedClass.Operations(i).Name = szItem Then
                  Set aOper = SelectedClass.Operations(i)
                  Exit For
              End If
            Next i
                
            aOper.ConnId = ""
          End If
        End If
      End If
    End If
  Next
  
  'Remove from grid
  gdConnectors.Rows.Remove gdConnectors.CurrentCell.RowKey
  
  'Remove UDIDef connector
  If Not m_curUDIDef Is Nothing Then
    Set m_ConnectionInfo = m_curUDIDef.CgConnectionDefs
    For i = 1 To m_ConnectionInfo.count
        If m_ConnectionInfo(i).connName = szConnector Then
            m_curUDIDef.CgConnectionDefs.Remove i
            SetModifiedConnectorInfo szConnector, "", "", ""
            Exit For
        End If
    Next i
  End If
  
  Exit Sub
Error_Handler:
  MsgBox "Error deleting connector '" & szConnector & "': " & err.Description
End Sub

Private Sub DoAttribProperties()
  Dim aNode As Node
  Dim szKeyType As String
  Dim szItem As String
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim frmProps As frmAttribAndOperProperties
  Dim i As Integer
  
  On Error GoTo Error_Handler
  
  For Each aNode In tvwClassItems.nodes
    If aNode.Selected Then
      If Len(aNode.Key) > 2 Then ' leaf node
        szKeyType = Left(aNode.Key, 3)
        On Error Resume Next
        If szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = IO_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Or szKeyType = LI_KEY_PREFIX Then
          szItem = aNode.Text
          Set aAttr = Nothing
          Set aAttr = SelectedClass.Attributes(szItem)
          If Not aAttr Is Nothing Then
            aAttr.PackageName = SelectedClass.PackageName
            Set frmProps = New frmAttribAndOperProperties
            Set frmProps.Attrib = aAttr
            frmProps.Show vbModal
            If frmProps.AttributeChanged() Then
                SelectedClass.Save
                tvwClassItems.nodes.Clear
                FillClassItems
            End If
            Exit For
          End If
          On Error GoTo Error_Handler
                  
        ElseIf szKeyType = OP_KEY_PREFIX Then
          szItem = aNode.Text
          Set aOper = Nothing
          Set aOper = SelectedClass.Operations(szItem)
          If Not aOper Is Nothing Then
            Set frmProps = New frmAttribAndOperProperties
            Set frmProps.Oper = aOper
            frmProps.Show vbModal
            If frmProps.AttributeChanged() Then
              SelectedClass.Save
              tvwClassItems.nodes.Clear
              FillClassItems
            End If
            Exit For
          End If
        End If
      End If
    End If
  Next
  
  Exit Sub
Error_Handler:
  MsgBox "Error setting attribute properties: " & err.Description
End Sub

Private Function GetFolderAndShapeName(FolderName As String, ShapeName As String) As Boolean
  If Not tvwShapes.SelectedItem Is Nothing Then
    If InStr(1, tvwShapes.SelectedItem.Key, "S_") > 0 Then
      FolderName = tvwShapes.SelectedItem.Parent.Text
      ShapeName = tvwShapes.SelectedItem.Text
      GetFolderAndShapeName = True
    End If
  End If
End Function

Private Function GetNodeFolderAndShapeName(Node As MSComctlLib.Node, FolderName As String, ShapeName As String) As Boolean
  If InStr(1, Node.Key, "S_") > 0 Then
    ShapeName = Node.Text
    FolderName = Node.Parent.Text
    GetNodeFolderAndShapeName = True
  Else
     If InStr(1, Node.Key, "F_") > 0 Then
      FolderName = Node.Text
      GetNodeFolderAndShapeName = True
     End If
  End If
End Function

Private Sub tvwShapes_NodeClick(ByVal Node As MSComctlLib.Node)
  On Error Resume Next
  Dim FolderName As String, ShapeName As String
  Dim UDIDef As UserDefinedItemDef
  Dim aInfo As ConnectionInfo
  Dim i As Integer
  Dim strKey As String
  Dim cgShapeInfo As cgLibraryShapeDetails

  If m_bConstructing Then Exit Sub
  If GetNodeFolderAndShapeName(Node, FolderName, ShapeName) Then
    If FolderName = m_currShapeFolder And ShapeName = m_currShape Then
        Exit Sub      'Selection has not changed
    End If
    m_currShapeFolder = FolderName
    m_currShape = ShapeName
    If FolderName = "" Or ShapeName = "" Then
        gdConnectors.Rows.RemoveAll
        Exit Sub
    End If
    
    m_iConnectorRow = -1
    gdConnectors.Rows.RemoveAll False
    
    m_curNode.Selected = False
    Set m_curNode = Node
    m_curNode.Selected = True
   
   'See if there's a UDIDef for this ShapeDef
    Set UDIDef = m_UDIDefMgr.GetUDIDef(FolderName, ShapeName)
    If Not UDIDef Is Nothing Then
        'UDIDef.GetConnectionDetails     'Fill In face and Order
        'Select the matching class in the class tree view if synchronization is turned on
        If chkSynchView.Value = 1 Then
            If UDIDef.ClassName <> "" Then
                ucUMLTreeView.ProjectName = UDIDef.ProjectName
                ucUMLTreeView.PackagesName = UDIDef.PackageName
                ucUMLTreeView.ClassID = UDIDef.ID
                ucUMLTreeView.ClassName = UDIDef.ClassName
            End If
        End If
        
        Set m_curUDIDef = UDIDef
        selectIcon m_curUDIDef.GeIconFolder, m_curUDIDef.GeIconShape
        GetConnectionDetails m_curUDIDef
    Else
        Set m_curUDIDef = Nothing
        ucUMLTreeView.ClassName = ""
        ucUMLTreeView.ProjectName = ""
        ucUMLTreeView.PackagesName = ""
        tvwClassItems.nodes.Clear
        GetShapeConnectorsAndDetails m_strLibName, m_currShapeFolder, m_currShape, m_collConnectionDetails
    End If
        
    Set m_ConnectionInfo = Nothing
    Set m_ConnectionInfo = New Collection
    
    InitConnectionData
    RefreshConnectorGrid
    ShowShape FolderName, ShapeName
    
    'If this is a new shape that is to be generated, show the Shape Details frame.  Otherwise, hide it.
    ShowOrHideShapeDetailsFrame
  End If
End Sub

Private Sub ShowOrHideShapeDetailsFrame()
    Dim strKey As String
    Dim cgShapeInfo As cgLibraryShapeDetails
    
    strKey = m_currShapeFolder & "_" & m_currShape
    Set cgShapeInfo = m_collLibraryShapes(strKey)
    If cgShapeInfo Is Nothing Then Exit Sub
    
    chkForceShapeReGen.Value = IIf(cgShapeInfo.bForceShapeRegeneration, 1, 0)
    If cgShapeInfo.bAdded Or cgShapeInfo.bConnectorsUpdated Or chkForceShapeReGen.Value = 1 Then
        frmShapeGenDetails.Visible = True
        ShowShapeGenerationFrame cgShapeInfo.m_bSizeShape, cgShapeInfo.m_ConnectorSpacing
    Else
        frmShapeGenDetails.Visible = False
    End If
End Sub

Private Sub RefreshConnectorGrid()
    Dim i As Integer
    Dim aInfo As ConnectionInfo
    Dim aConn As CgConnectionDef
    Dim strKey As String
    Dim cgConnDetail As cgLibraryShapeDetails
    Dim iFace As Integer, iOrder As Integer
    
    'There are two possible cases here.
    ' 1. We're dealing with a shape that has had connectors modified.  Hance we can't rely on the call to the
    '    shape manager to retrieve the connections.  In this case, rely on the UDIDef's connection info
    ' 2. We have a shape which has not had ay modifications to the connectors and has no current UDIDef assigned.
    '    In this case the info from the shape def manager will be correct.
    On Error Resume Next
    iFace = -1
    iOrder = -1
    strKey = m_currShapeFolder & "_" & m_currShape
    
    If m_collLibraryShapes Is Nothing Then
        InitShapeLibraryCollection
    End If
    
    Set cgConnDetail = m_collLibraryShapes(strKey)
    If cgConnDetail Is Nothing Then
        gMsgWnd.LogMessage "Failed to retrieve connection details for shape '" & m_currShape & "'."
    End If
    
    gdConnectors.Rows.RemoveAll False
    If Not m_curUDIDef Is Nothing Then
        Set m_ConnectionInfo = m_curUDIDef.CgConnectionDefs
        If Not m_ConnectionInfo Is Nothing Then
            For Each aConn In m_ConnectionInfo
                If Not cgConnDetail Is Nothing Then
                    iFace = cgConnDetail.m_collFace(aConn.connName)
                    iOrder = cgConnDetail.m_collOrder(aConn.connName)
                End If
                If iFace > 0 And iOrder > 0 Then    'Face\Order\Name for this connection have not been altered
                    gdConnectors.Rows.Add sgFormatCharSeparatedValue, aConn.connName & "," & iFace & "," & iOrder
                    SetConnectorRowTextColour aConn.connName, gdConnectors.Rows.count - 1
                    SetModifiedConnectorInfo "", aConn.connName, CStr(iFace), CStr(iOrder), True
                Else                                'Face\Order\Name for this connection have been modified
                    gdConnectors.Rows.Add sgFormatCharSeparatedValue, aConn.connName & "," & aConn.Face & "," & aConn.order
                    SetConnectorRowTextColour aConn.connName, gdConnectors.Rows.count - 1
                    SetModifiedConnectorInfo "", aConn.connName, aConn.Face, aConn.order, True
                End If
            Next
        End If
    Else
        Dim cgDetails As cgShapeComponentDetails
        
        If m_collConnectionDetails Is Nothing Then
            GetShapeConnectorsAndDetails m_strLibName, m_currShapeFolder, m_currShape, m_collConnectionDetails
        End If
        For i = 1 To m_collConnectionDetails.count
            Set cgDetails = m_collConnectionDetails(i)
            If cgDetails.iType = EGeObjType.ObjConnector Then
                gdConnectors.Rows.Add sgFormatCharSeparatedValue, cgDetails.strName & "," & cgDetails.iFace & "," & cgDetails.iOrder
                SetConnectorRowTextColour cgDetails.strName, gdConnectors.Rows.count - 1
                SetModifiedConnectorInfo "", cgDetails.strName, cgDetails.iFace, cgDetails.iOrder, True
            End If
        Next i
    End If
End Sub

Private Sub SetConnectorRowTextColour(strConn As String, iRowPos As Integer)
    Dim aNode As Node
    Dim szKeyType As String
    Dim szItem As String
    Dim aAttr As CgAttribute
    Dim aOper As CgOperation
    Dim cgConnDef As CgConnectionDef
    Dim strConnID As String
    Dim i As Integer
    
    strConnID = ""
    gdConnectors.Rows.At(iRowPos).Style.ForeColor = COLOUR_DARK_RED
    
    If Not m_curUDIDef Is Nothing Then
        Set cgConnDef = m_curUDIDef.FindConnection(strConn)
        If Not cgConnDef Is Nothing Then
            strConnID = cgConnDef.itemID
        End If
    End If
    
    For Each aNode In tvwClassItems.nodes
      aNode.Selected = False
      If Len(aNode.Key) > 2 Then ' a leaf node key
        szKeyType = Left(aNode.Key, 3)
        If szKeyType = IO_KEY_PREFIX Or szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Or szKeyType = LI_KEY_PREFIX Then
          szItem = aNode.Text
          
          On Error Resume Next
          Set aAttr = Nothing
          Set aAttr = SelectedClass.Attributes(szItem)
          If Not aAttr Is Nothing Then
            If szKeyType = VR_KEY_PREFIX And err <> 0 Then
              Set aAttr = ClassVariables(szItem)
            End If
            
            If aAttr.ConnId = strConn Or aAttr.obj.GUID = strConnID Then
              gdConnectors.Rows.At(iRowPos).Style.ForeColor = COLOUR_BLACK
            End If
           End If
           
        ElseIf szKeyType = OP_KEY_PREFIX Then
          szItem = aNode.Text
          Set aOper = Nothing
          Set aOper = SelectedClass.Operations(szItem)
          If Not aOper Is Nothing Then
            If aOper.ConnId = strConn Or aOper.obj.GUID = strConnID Then
              gdConnectors.Rows.At(iRowPos).Style.ForeColor = COLOUR_BLACK
            End If
          End If
        End If
      End If
    Next
End Sub

Private Function CreateShapeDef(aProject As rtsProject) As UserDefinedItemDef
  Dim pDef As UserDefinedItemDef
  Dim strName As String
  Dim j As Integer
  Dim aCI As rtsClass
  Dim aAttr As CgAttribute
  Dim newAttr As CgAttribute
      
  Set CreateShapeDef = Nothing
  strName = GetGUID()
  If Not m_UDIDefMgr Is Nothing Then
    j = 1
    Set pDef = m_UDIDefMgr.CreateUDIDefFromObjectName(strName)
    pDef.ProjectName = ucUMLTreeView.ProjectName
    pDef.PackageName = ucUMLTreeView.PackagesName
    pDef.ClassName = ucUMLTreeView.ClassName
    
    If GetClassInfo(aProject, pDef.PackageName, pDef.ClassName, aCI) Then
      pDef.PackageName = aCI.PackageName
      If Not aCI Is Nothing Then
        pDef.ID = aCI.Class.GUID
        For Each aAttr In aCI.Attributes
          Set newAttr = New CgAttribute
          aAttr.Copy newAttr
          pDef.Attributes.Add newAttr
        Next
        pDef.GeLibrary = m_strLibName
        pDef.GeFolder = m_currShapeFolder
        Set CreateShapeDef = pDef
      End If
    End If
  End If
End Function

Private Function AddShapeDefToTree(ByRef UDIDef As UserDefinedItemDef) As MSComctlLib.Node
    Dim i As Integer
    Dim j As Integer
    Dim iNodes As Integer
    Dim oNode As Node
    Dim strShapeDefName As String
    Dim strShapeKey As String
    Dim strNameOrig As String
    Dim pDef As UserDefinedItemDef
    
    Set AddShapeDefToTree = Nothing
    iNodes = tvwShapes.nodes.count
    For i = 1 To iNodes
        Set oNode = tvwShapes.nodes(i)
        If oNode.Text = UDIDef.GeFolder Then
            'Make sure the name is unique
            strShapeDefName = UDIDef.ClassName & "Block"
            strNameOrig = strShapeDefName
            j = 1
            'See if there is a shape by this name already
            Do
                If IsUniqueShapeName(strShapeDefName, oNode) Then
                    Exit Do
                End If
                strShapeDefName = strNameOrig & "_" & CStr(j)
                j = j + 1
            Loop
            UDIDef.GeShape = strShapeDefName
            strShapeKey = oNode.Key & SHAPE_KEY_PREFIX & Format(tvwShapes.nodes.count + 1, "0000") & strShapeDefName
            Set AddShapeDefToTree = tvwShapes.nodes.Add(oNode.Key, tvwChild, strShapeKey, strShapeDefName)
            AddShapeDefToTree.Sorted = True
            AddShapeDefToTree.Parent.Sorted = True
            Exit For
        End If
    Next
    tvwShapes.Sorted = True
    ShowDetailsPane
End Function
 
Private Function AddShapeToTree(strFolder As String, strShape As String) As MSComctlLib.Node
    Dim i As Integer
    Dim j As Integer
    Dim iNodes As Integer
    Dim oNode As Node
    Dim strShapeDefName As String
    Dim strShapeKey As String
    Dim strNameOrig As String
    Dim pDef As UserDefinedItemDef
    
    Set AddShapeToTree = Nothing
    iNodes = tvwShapes.nodes.count
    For i = 1 To iNodes
        Set oNode = tvwShapes.nodes(i)
        If oNode.Text = strFolder Then
            strShapeKey = oNode.Key & SHAPE_KEY_PREFIX & Format(tvwShapes.nodes.count + 1, "0000") & strShape
            Set AddShapeToTree = tvwShapes.nodes.Add(oNode.Key, tvwChild, strShapeKey, strShape)
            AddShapeToTree.Sorted = True
            AddShapeToTree.Parent.Sorted = True
            Exit For
        End If
    Next
    tvwShapes.Sorted = True
End Function

Private Function RemoveShapeDefFromTree(ByRef UDIDef As UserDefinedItemDef) As Boolean
    Dim i As Integer
    Dim iNodes As Integer
    Dim oNode As Node
    Dim strShapeKey As String
    
    On Error Resume Next
    RemoveShapeDefFromTree = False
    
    iNodes = tvwShapes.nodes.count
    For i = 1 To iNodes
        Set oNode = tvwShapes.nodes(i)
        If oNode.Text = UDIDef.GeFolder Then
            strShapeKey = oNode.Key & SHAPE_KEY_PREFIX & Format(tvwShapes.nodes.count + 1, "0000") & UDIDef.GeShape
            tvwShapes.nodes.Remove strShapeKey
            Exit For
        End If
    Next
    tvwShapes.Sorted = True
    RemoveShapeDefFromTree = True
End Function

Private Function RemoveShapeFromTree(strFolder As String, strShape As String) As Boolean
    Dim i As Integer
    Dim j As Integer
    Dim iNodes As Integer
    Dim oNode As Node
    Dim strShapeKey As String
    Dim nChild As Node
    
    On Error Resume Next
    RemoveShapeFromTree = False
    
    iNodes = tvwShapes.nodes.count
    For i = 1 To iNodes
        Set oNode = tvwShapes.nodes(i)
        If oNode.Text = strFolder Then
            Set nChild = oNode.Child
            Do
                If nChild Is Nothing Then Exit Do
                If nChild.Text = strShape Then
                    tvwShapes.nodes.Remove nChild.Index
                    Exit Do
                End If
                Set nChild = nChild.Next
            Loop
        End If
    Next
    tvwShapes.Sorted = True
    RemoveShapeFromTree = True
End Function

Private Sub ShowDetailsPane()
    If btnCollapse.Caption = ">" Then   'Details currently hidden
        btnCollapse.Caption = "<"
        Me.Height = Me.Height * 2
        form_Resize
    End If
End Sub

Private Function IsUniqueShapeName(strShapeName As String, oFolderNode As Node) As Boolean
    Dim k As Integer
    Dim nChild As Node
        
    IsUniqueShapeName = True
    Set nChild = oFolderNode.Child
    Do
        If nChild Is Nothing Then Exit Do
        If nChild.Text = strShapeName Then
            IsUniqueShapeName = False
            Exit Do
        End If
        Set nChild = nChild.Next
    Loop
End Function

Private Function IsUniqueShapeName2(strNewShape As String) As Boolean
    Dim k As Integer
    Dim oNode As Node
    
    IsUniqueShapeName2 = True
    For Each oNode In tvwShapes.nodes
        If oNode.Text = strNewShape Then
            IsUniqueShapeName2 = False
            Exit For
        End If
    Next
End Function

Private Function IsUniqueConnectorName(strConnectorName As String) As Boolean
    Dim i As Integer
    
    IsUniqueConnectorName = True
    If m_curUDIDef Is Nothing Then Exit Function
    For i = 1 To m_curUDIDef.CgConnectionDefs.count
        If m_curUDIDef.CgConnectionDefs(i).connName = strConnectorName Then
            IsUniqueConnectorName = False
            Exit For
        End If
    Next i
End Function

Private Sub btnAssignConnector_Click()
  Dim szConnector As String
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim szItem As String
  Dim szItemSize As String
  Dim i As Long
  Dim szKeyType As String
  Dim aNode As Node
  
  On Error GoTo Error_Handler
  If m_curUDIDef Is Nothing Then
    Exit Sub
  End If
  szConnector = gdConnectors.CurrentCell.Row.Cells(0)
  If szConnector <> "" And Not tvwClassItems.SelectedItem Is Nothing Then
    For Each aNode In tvwClassItems.nodes
      If Len(aNode.Key) > 2 Then                        ' a leaf node key
        szKeyType = Left(aNode.Key, 3)
        On Error Resume Next
        If szKeyType = IO_KEY_PREFIX Or szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Or szKeyType = LI_KEY_PREFIX Then
          szItem = aNode.Text
          
          Set aAttr = Nothing
          Set aAttr = SelectedClass.Attributes(szItem)
          If Not aAttr Is Nothing Then
            If szKeyType = VR_KEY_PREFIX And err <> 0 Then
              Set aAttr = ClassVariables(szItem)
              SelectedClass.Attributes.Add aAttr
            End If
            On Error GoTo Error_Handler
            
            If aNode.Selected Then
              AddModifiedConnectorMapping aAttr.Name, aAttr.ConnId, szConnector
              On Error Resume Next
              UpdateUDIDef szConnector, aAttr.Name, aAttr, Nothing
              aAttr.ConnId = szConnector
              gdConnectors.Rows.Current.Style.ForeColor = COLOUR_BLACK
              gdConnectors.Rows.Current.Redraw
            ElseIf aAttr.ConnId = szConnector Then
              AddModifiedConnectorMapping aAttr.Name, aAttr.ConnId, ""
              aAttr.ConnId = ""
            End If
          End If
          
        ElseIf szKeyType = OP_KEY_PREFIX Then
          szItem = aNode.Text
          Set aOper = Nothing
          Set aOper = SelectedClass.Operations(szItem)
          If Not aOper Is Nothing Then
             If aNode.Selected Then
               AddModifiedConnectorMapping aOper.Name, aOper.ConnId, szConnector
               On Error Resume Next
               
               UpdateUDIDef szConnector, aOper.Name, Nothing, aOper
               aOper.ConnId = szConnector
               gdConnectors.Rows.Current.Style.ForeColor = COLOUR_BLACK
               gdConnectors.Rows.Current.Redraw
             ElseIf aOper.ConnId = szConnector Then
               AddModifiedConnectorMapping aOper.Name, aOper.ConnId, ""
               aOper.ConnId = ""
            End If
          End If
        End If
      End If
    Next
  End If
  
  Exit Sub
Error_Handler:
  If err.Number <> -2147213239 Then
    gMsgWnd.LogMessage "Failed assignment. Error: " & err.Description
  End If
End Sub


Private Sub btnClearConnector_Click()
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim szItem As String
  Dim szType As String
  Dim i As Long
  Dim aNode As Node
  Dim szKeyType As String
  Dim szConnector As String
  
  On Error GoTo Error_Handler
  If m_curUDIDef Is Nothing Then
    Exit Sub
  End If
  
  szConnector = gdConnectors.CurrentCell.Row.Cells(0)   'gdConnectors.Text
  If szConnector <> "" And Not tvwClassItems.SelectedItem Is Nothing Then
  For Each aNode In tvwClassItems.nodes
      If aNode.Selected Then
        If Len(aNode.Key) > 2 Then ' leaf node
          szKeyType = Left(aNode.Key, 3)
          On Error Resume Next
          If szKeyType = CN_KEY_PREFIX Or szKeyType = VR_KEY_PREFIX Or szKeyType = IO_KEY_PREFIX Or szKeyType = BR_KEY_PREFIX Or szKeyType = LI_KEY_PREFIX Then
            szItem = aNode.Text
            Set aAttr = Nothing
            Set aAttr = SelectedClass.Attributes(szItem)
            If Not aAttr Is Nothing Then
                If szKeyType = VR_KEY_PREFIX And err <> 0 Then
                  Set aAttr = ClassVariables(szItem)
                End If
                On Error GoTo Error_Handler
                
                If Not aAttr Is Nothing Then
                  AddModifiedConnectorMapping aAttr.Name, aAttr.ConnId, ""
                  aAttr.ConnId = ""
                  UpdateUDIDef szConnector, "", aAttr, Nothing
                  gdConnectors.Rows.Current.Style.ForeColor = COLOUR_DARK_RED
                  gdConnectors.Rows.Current.Redraw
                End If
            End If
            
          ElseIf szKeyType = OP_KEY_PREFIX Then
            szItem = aNode.Text
            Set aOper = Nothing
            Set aOper = SelectedClass.Operations(szItem)
            If Not aOper Is Nothing Then
                AddModifiedConnectorMapping aOper.Name, aOper.ConnId, ""
                aOper.ConnId = ""
                UpdateUDIDef szConnector, "", Nothing, aOper
                gdConnectors.Rows.Current.Style.ForeColor = COLOUR_DARK_RED
                gdConnectors.Rows.Current.Redraw
            End If
          End If
        End If
      End If
    Next
  End If
  Exit Sub
Error_Handler:
  MsgBox "Clear error: " & err.Description
End Sub

Private Sub FillClassItems()
  Dim aAttr As CgAttribute
  Dim aSubAttr As CgAttribute
  
  Dim aOper As CgOperation
  Dim szEventType As String
  Dim aInfo As rtsClass
  Dim rootNode As Node
  Dim childKey As String
  
  On Error GoTo Error_Handler
  If SelectedClass Is Nothing Then
    tvwClassItems.nodes.Clear
    Exit Sub
  End If
  
  If tvwClassItems.nodes.count > 0 Then tvwClassItems.nodes.Clear
  Set rootNode = tvwClassItems.nodes.Add(, , "RT", "Class items")
  
  tvwClassItems.nodes.Add "RT", tvwChild, "IO", "I/O"
  For Each aAttr In SelectedClass.Attributes
    If aAttr.sType = idxAttr_Input Or aAttr.sType = idxAttr_Output Then
      childKey = IO_KEY_PREFIX & aAttr.Name
      tvwClassItems.nodes.Add "IO", tvwChild, childKey, aAttr.Name
    End If
  Next
      
  tvwClassItems.nodes.Add "RT", tvwChild, "OP", "Operation"
  For Each aOper In SelectedClass.Operations
    If Not aOper.bSim Then
      childKey = OP_KEY_PREFIX & aOper.Name
      tvwClassItems.nodes.Add "OP", tvwChild, childKey, aOper.Name
    End If
  Next
      
  tvwClassItems.nodes.Add "RT", tvwChild, "CN", "Connector"
  For Each aAttr In SelectedClass.Attributes
    If aAttr.sType = idxAttr_Connector Then
      childKey = CN_KEY_PREFIX & aAttr.Name
      tvwClassItems.nodes.Add "CN", tvwChild, childKey, aAttr.Name
    End If
  Next
      
  tvwClassItems.nodes.Add "RT", tvwChild, "VR", "Variable"
  Set ClassVariables = Nothing                      'This collection may have changed, so recreate it!!!!
  'If ClassVariables Is Nothing Then
    GetClassVariables SelectedClass, "", ClassVariables, False
  'End If
  For Each aAttr In ClassVariables
    childKey = VR_KEY_PREFIX & aAttr.Name
    tvwClassItems.nodes.Add "VR", tvwChild, childKey, aAttr.Name
  Next
    
  tvwClassItems.nodes.Add "RT", tvwChild, "BR", "Broadcaster"
  For Each aAttr In SelectedClass.Attributes
    If aAttr.sType = idxAttr_Broadcaster Then
      childKey = BR_KEY_PREFIX & aAttr.Name
      tvwClassItems.nodes.Add "BR", tvwChild, childKey, aAttr.Name
    End If
  Next
    
 tvwClassItems.nodes.Add "RT", tvwChild, "LI", "Listner"
 For Each aAttr In SelectedClass.Attributes
    If aAttr.sType = idxAttr_Listener Then
      childKey = LI_KEY_PREFIX & aAttr.Name
      tvwClassItems.nodes.Add "LI", tvwChild, childKey, aAttr.Name
    End If
  Next
    
  rootNode.Expanded = True
  Exit Sub
    
Error_Handler:
    gMsgWnd.LogMessage "Class Items retrieval error: " & err.Description
End Sub

Sub InitConnectionData()
  Dim aConn As CgConnectionDef
  Dim aAttr As CgAttribute
  Dim aOper As CgOperation
  Dim oNode As Node
  
  On Error Resume Next
  If m_curUDIDef Is Nothing Then
    'This isn't an error case. gMsgWnd.LogMessage "Failed to initialize connections."
    Exit Sub
  End If
  
  'Clear out all the connectors for the selected class if same class was chosen previously
  If SelectedClassOld.Name = SelectedClass.Name Or m_strStartupShape <> "" Then
    If Not SelectedClass Is Nothing Then
      For Each oNode In tvwShapes.nodes
        If InStr(1, oNode.Key, SHAPE_KEY_PREFIX) > 0 Then
            For Each aAttr In SelectedClass.Attributes
              If aAttr.ConnId <> "" Then aAttr.ConnId = ""
            Next
            For Each aOper In SelectedClass.Operations
              If aOper.ConnId <> "" Then aOper.ConnId = ""
            Next
        End If
      Next
    End If
  End If
  
  For Each aConn In m_curUDIDef.CgConnectionDefs
    Select Case aConn.itemType
      Case idxItemType_Attribute
        Set aAttr = SelectedClass.Attributes(aConn.itemName)
        If Not aAttr Is Nothing Then
            aAttr.ConnId = aConn.connName
        End If
        Set aAttr = Nothing
      Case idxItemType_Operation
        Set aOper = SelectedClass.Operations(aConn.itemName)
        If Not aOper Is Nothing Then
            aOper.ConnId = aConn.connName
        End If
        Set aOper = Nothing
    End Select
  Next
End Sub

Private Sub GetConnectionInfo()
  Dim GeID As Long
  Dim ptX As Single, ptY As Single
  
  On Error Resume Next
  ShapeGe.GrabHandlesEnabled = False
  ShapeGe.SelectAll
  ShapeGe.Delete
    ' set X/Y high so get off the drawing area with the dwg border being shown
  ptX = 100
  ptY = 100
  
  On Error Resume Next
  If m_curUDIDef Is Nothing Then Exit Sub
  ShapeGe.UsePictureColor = True
  GeID = ShapeGe.CreateShape(m_curUDIDef.GeLibrary, m_curUDIDef.GeFolder, m_curUDIDef.GeShape, ptX, ptY)
  If GeID > 0 Then
    ShapeGe.CurrentPropertyID = GeID
    ShapeGe.SendCurrentConnectionInfo
  End If

End Sub

Private Sub ShapeGe_ConnectionChanged(ByVal Action As Integer, ByVal IDLine As Long, ByVal IDA As Long, ByVal VarA As Variant, ByVal NameA As String, ByVal TypeA As Integer, ByVal StsA As Integer, ByVal IDB As Long, ByVal VarB As Variant, ByVal NameB As String, ByVal TypeB As Integer, ByVal StsB As Integer)
  Dim aInfo As ConnectionInfo
  
  On Error Resume Next
  Set aInfo = New ConnectionInfo
  aInfo.Action = Action
  aInfo.IDLine = IDLine
  aInfo.IDA = IDA
  If Not IsEmpty(VarA) Then
    If IsObject(VarA) Then
      Set aInfo.VarA = VarA
    Else
      aInfo.VarA = VarA
    End If
  End If
  aInfo.NameA = NameA
  aInfo.TypeA = TypeA
  aInfo.StsA = StsA
  aInfo.IDB = IDB
  If Not IsEmpty(VarB) Then
    If IsObject(VarB) Then
      Set aInfo.VarB = VarB
    Else
      aInfo.VarB = VarB
    End If
  End If
  aInfo.NameB = NameB
  aInfo.TypeB = TypeB
  aInfo.StsB = StsB
  
  m_ConnectionInfo.Add aInfo, aInfo.NameA
End Sub

Private Sub UnHighlightRow(RowKey As Integer)
    On Error Resume Next
    gdConnectors.Rows.At(RowKey).Style.BackColor = &H80000005
    gdConnectors.Rows.At(RowKey).Redraw
End Sub

Private Sub HighlightRow(RowKey As Integer)
    On Error Resume Next
    gdConnectors.Rows.At(RowKey).Style.BackColor = &H80000000
    gdConnectors.Rows.At(RowKey).Redraw
End Sub

Private Function GetFolderID() As String
    Dim strFolderID As String
    
    If m_curNode Is Nothing Then Exit Function
    strFolderID = m_curNode.Parent.Key
    strFolderID = Replace(strFolderID, "F_", "")
    
    GetFolderID = strFolderID
End Function

Private Sub UpdateUDIDef(strConn As String, strConnNew As String, aAttr As CgAttribute, aOper As CgOperation)
  Dim aConn As CgConnectionDef
  
  On Error Resume Next
  If m_curUDIDef Is Nothing Then
    Exit Sub
  End If
  
  For Each aConn In m_curUDIDef.CgConnectionDefs
    If aConn.connName = strConn Then
        If Not aAttr Is Nothing Then
            ' KAB need to write connect item name
            aConn.itemName = aAttr.Name ' strConnNew
            aConn.attrType = aAttr.sType
            aConn.operType = 0
            aConn.itemType = idxItemType_Attribute
            aConn.itemID = aAttr.obj.GUID
        ElseIf Not aOper Is Nothing Then
            ' KAB need to write correct item name
            aConn.itemName = aOper.Name ' strConnNew
            aConn.attrType = 0
            aConn.operType = aOper.sType
            aConn.itemType = idxItemType_Operation
            aConn.itemID = aOper.obj.GUID
        End If
        Exit For
    End If
 Next
End Sub

Private Sub RestoreOldUDIDefName(cgShapeInfo As cgLibraryShapeDetails)
    Dim iNodes As Integer
    Dim oNode As Node
    Dim i As Integer
    Dim strKey As String
    
    'Restore old node name
    iNodes = tvwShapes.nodes.count
    For i = 1 To iNodes
        Set oNode = tvwShapes.nodes(i)
        If oNode.Text = cgShapeInfo.strShapeNameNew Then
            oNode.Text = cgShapeInfo.strShapeName
            Exit For
        End If
    Next
    
    'The key for this item needs to be updated in m_collLibraryShapes
    strKey = cgShapeInfo.strFolderName & "_" & cgShapeInfo.strShapeNameNew
    m_collLibraryShapes.Remove strKey
    
    strKey = cgShapeInfo.strFolderName & "_" & cgShapeInfo.strShapeName
    m_collLibraryShapes.Add cgShapeInfo, strKey
    
    'Update current shape name if it's the renamed one
    If cgShapeInfo.strShapeNameNew = m_currShape Then
        m_currShape = cgShapeInfo.strShapeName
    End If
End Sub

'This function should only be called if the shape being updated has a valid UserID associated with each connector.
Public Function UpdateShape(strShape As String, strFolder As String, strFolderID As String, m_GeLbrMgr As GeLibraryMgr, cgDetailInfo As cgLibraryShapeDetails) As Boolean
    Dim aConn As CgConnectionDef
    Dim GeID As Long
    Dim strConn As String
    Dim iFace As Integer, iOrder As Integer
    Dim collDelete As Collection, collAdd As Collection
    Dim i As Integer
    Dim pDefOrig As UserDefinedItemDef
    On Error GoTo Error_Handler
    
    UpdateShape = True
    If m_GeLbrMgr Is Nothing Then Exit Function
    If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
    If cgDetailInfo Is Nothing Then Exit Function
     
    Set pDefOrig = cgDetailInfo.m_UDIDefOriginal
    If pDefOrig Is Nothing Then Exit Function
    If pDefOrig.CgConnectionDefs Is Nothing Then Exit Function
    
    Set collDelete = New Collection
    Set collAdd = New Collection
           
    'Have to compare new connection list to original to determine which connectors have been added\deleted
    'Note that renamed connectors are treated as if they have been deleted, and then added.
    On Error Resume Next
    For Each aConn In pDefOrig.CgConnectionDefs
        strConn = ""
        strConn = cgDetailInfo.m_collConnectors(aConn.connName)
        If strConn = "" Then collDelete.Add aConn.UserId
    Next
    
    For i = 1 To cgDetailInfo.m_collConnectors.count
        Set aConn = Nothing
        strConn = cgDetailInfo.m_collConnectors(i)
        Set aConn = pDefOrig.FindConnection(strConn)
        If aConn Is Nothing Then collAdd.Add strConn
    Next i

    'If collDelete.count > 0 And collAdd.count <= 0 Then
    '    DeleteConnectors collDelete, cgDetailInfo, m_GeLbrMgr
    'End If
    
    'For now recreate all connectors
    If cgDetailInfo.m_bSizeShape Then
        AddSpacedConnectors collAdd, cgDetailInfo, m_GeLbrMgr
    Else
        AddConnectors collAdd, cgDetailInfo, m_GeLbrMgr
    End If
   Exit Function
Error_Handler:
   gMsgWnd.LogMessage "Failed to update library block " & strShape & ": " & err.Description
   UpdateShape = False
End Function

Private Function GenNextConnectorOrder() As Integer
    Dim iOrderLeft As Integer
    Dim iOrder As Integer
    Dim iRows As Integer
    Dim i As Integer
    
    'Find the largest left face order, and set this one to one greater then that
    On Error Resume Next
    iOrderLeft = 0
    iRows = gdConnectors.RowCount - 1
    For i = 0 To iRows - 1
        If gdConnectors.Array(i, COL_FACE - 1) = "1" Or gdConnectors.Array(i, COL_FACE - 1) = "Left" Then           'Left = 1
            iOrder = CInt(gdConnectors.Array(i, COL_ORDER - 1))
            If iOrder > iOrderLeft Then iOrderLeft = iOrder
        End If
    Next i
    
    GenNextConnectorOrder = iOrderLeft + 1
End Function

