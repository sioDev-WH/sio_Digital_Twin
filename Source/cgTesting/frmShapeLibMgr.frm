VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Object = "{E6F77CB3-6A30-11D5-89E6-00D0B74A80C3}#1.0#0"; "CGCtrl.ocx"
Begin VB.Form frmShapeLibMgr 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Library Manager"
   ClientHeight    =   7890
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   11820
   Icon            =   "frmShapeLibMgr.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7890
   ScaleWidth      =   11820
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin CGCtrlLib.CG ShapeGe 
      Height          =   2355
      Left            =   5670
      TabIndex        =   50
      Top             =   720
      Width           =   2415
      _Version        =   65536
      _ExtentX        =   4260
      _ExtentY        =   4154
      _StockProps     =   64
   End
   Begin VB.CommandButton btnMore 
      Caption         =   "More >>>"
      Height          =   300
      Left            =   7230
      TabIndex        =   36
      ToolTipText     =   "Show more details and statistics about the Shapes"
      Top             =   3210
      Width           =   900
   End
   Begin VB.PictureBox picMore 
      BorderStyle     =   0  'None
      Height          =   7185
      Left            =   8175
      ScaleHeight     =   7185
      ScaleWidth      =   3540
      TabIndex        =   34
      Top             =   795
      Visible         =   0   'False
      Width           =   3540
      Begin VB.TextBox txtUserDataFlt 
         Enabled         =   0   'False
         Height          =   285
         Left            =   720
         TabIndex        =   49
         ToolTipText     =   "User Data (floating point format)"
         Top             =   2685
         Width           =   1650
      End
      Begin VB.TextBox txtUserDataStr 
         Enabled         =   0   'False
         Height          =   285
         Left            =   720
         TabIndex        =   46
         ToolTipText     =   "User Data (string format). 255 characters Max."
         Top             =   2370
         Width           =   2715
      End
      Begin VB.ListBox lbScaleModeDST 
         Height          =   1035
         ItemData        =   "frmShapeLibMgr.frx":0442
         Left            =   165
         List            =   "frmShapeLibMgr.frx":0455
         TabIndex        =   45
         Top             =   1260
         Width           =   1335
      End
      Begin VB.ListBox lbRotateModeDST 
         Height          =   840
         ItemData        =   "frmShapeLibMgr.frx":0488
         Left            =   1680
         List            =   "frmShapeLibMgr.frx":0495
         TabIndex        =   42
         Top             =   1260
         Width           =   1335
      End
      Begin VB.CheckBox chkCanSelect 
         Caption         =   "Can Select (not locked)"
         Height          =   255
         Left            =   180
         TabIndex        =   41
         ToolTipText     =   "Shape can be selected once it has been placed on the drawing"
         Top             =   525
         Width           =   2145
      End
      Begin VB.CheckBox chkAutoScale 
         Caption         =   "Auto Scale when Inserting"
         Height          =   255
         Left            =   180
         TabIndex        =   40
         ToolTipText     =   "Shape will scale automatically to match drawing scale"
         Top             =   780
         Width           =   2205
      End
      Begin VB.CheckBox chkCanMove 
         Caption         =   "Can Move"
         Height          =   255
         Left            =   180
         TabIndex        =   38
         ToolTipText     =   "Shape Can move once its been placed"
         Top             =   270
         Width           =   1275
      End
      Begin VB.TextBox txtSortedShapes 
         Height          =   1695
         Left            =   90
         MultiLine       =   -1  'True
         ScrollBars      =   3  'Both
         TabIndex        =   35
         Top             =   5130
         Width           =   3375
      End
      Begin VB.Label Label12 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "ValFLT"
         Height          =   195
         Left            =   105
         TabIndex        =   48
         Top             =   2730
         Width           =   510
      End
      Begin VB.Label Label11 
         Alignment       =   1  'Right Justify
         AutoSize        =   -1  'True
         Caption         =   "ValSTR"
         Height          =   195
         Left            =   60
         TabIndex        =   47
         Top             =   2445
         Width           =   555
      End
      Begin VB.Label Label10 
         Alignment       =   2  'Center
         Caption         =   "Scale Mode"
         Height          =   195
         Left            =   135
         TabIndex        =   44
         Top             =   1050
         Width           =   1320
      End
      Begin VB.Label Label8 
         Alignment       =   2  'Center
         Caption         =   "Rotate Mode"
         Height          =   195
         Left            =   1680
         TabIndex        =   43
         Top             =   1050
         Width           =   1320
      End
      Begin VB.Line Line4 
         X1              =   210
         X2              =   3210
         Y1              =   45
         Y2              =   45
      End
      Begin VB.Label Label2 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Default Properties"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   900
         TabIndex        =   39
         ToolTipText     =   "Properties that will be applied when the shape is inserted onto a drawing"
         Top             =   75
         Width           =   1560
      End
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         Caption         =   "Member Shape(s)"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Left            =   1020
         TabIndex        =   37
         Top             =   4890
         Width           =   1500
      End
      Begin VB.Line Line3 
         BorderWidth     =   2
         X1              =   0
         X2              =   3570
         Y1              =   3075
         Y2              =   3075
      End
      Begin VB.Line Line2 
         X1              =   60
         X2              =   3480
         Y1              =   4845
         Y2              =   4845
      End
   End
   Begin VB.CheckBox chkConfirmDeleteShape 
      Caption         =   "Confirm Delete"
      Height          =   240
      Left            =   90
      TabIndex        =   33
      ToolTipText     =   "Confirm deleting of Shapes"
      Top             =   2670
      Value           =   1  'Checked
      Visible         =   0   'False
      Width           =   1545
   End
   Begin VB.CommandButton btnDiff 
      Caption         =   "Differences..."
      Enabled         =   0   'False
      Height          =   285
      Left            =   6570
      TabIndex        =   30
      ToolTipText     =   "Manage differences between Destination and Source libraries."
      Top             =   3540
      Width           =   1575
   End
   Begin VB.CommandButton btnExit 
      Caption         =   "Close"
      Height          =   300
      Left            =   8880
      TabIndex        =   28
      ToolTipText     =   "Close this dialog."
      Top             =   0
      Width           =   810
   End
   Begin VB.CommandButton btnAdd 
      Caption         =   "Add Library..."
      Height          =   300
      Left            =   60
      TabIndex        =   27
      ToolTipText     =   "Add a Library to the list of Destination Libraries shown here."
      Top             =   345
      Width           =   1575
   End
   Begin VB.ListBox lbSortedShapes 
      Height          =   450
      Left            =   60
      Sorted          =   -1  'True
      TabIndex        =   26
      Top             =   7230
      Visible         =   0   'False
      Width           =   1335
   End
   Begin VB.TextBox txtSourceLib 
      Enabled         =   0   'False
      Height          =   285
      Left            =   2220
      TabIndex        =   25
      Top             =   4185
      Width           =   5925
   End
   Begin VB.ComboBox cbSrcFolders 
      Height          =   315
      Left            =   2220
      Style           =   2  'Dropdown List
      TabIndex        =   20
      Top             =   4635
      Width           =   3315
   End
   Begin VB.ListBox lstSrcShapes 
      Height          =   2205
      Left            =   2220
      Sorted          =   -1  'True
      TabIndex        =   19
      Top             =   5055
      Width           =   3315
   End
   Begin VB.CommandButton btnCopy 
      Caption         =   "Copy Folder"
      Height          =   300
      Left            =   60
      TabIndex        =   18
      ToolTipText     =   "Copy the folder and its contents to the above library"
      Top             =   4665
      Width           =   1575
   End
   Begin VB.CommandButton btnMove 
      Caption         =   "Move Folder"
      Height          =   300
      Left            =   60
      TabIndex        =   17
      ToolTipText     =   "Move the folder and its contents to the above library"
      Top             =   4980
      Width           =   1575
   End
   Begin VB.CommandButton btnCopyShape 
      Caption         =   "Copy Shape"
      Height          =   300
      Left            =   60
      TabIndex        =   16
      ToolTipText     =   "Copy the shape to the above library & folder"
      Top             =   5610
      Width           =   1575
   End
   Begin VB.CommandButton btnMoveShapeToLib 
      Caption         =   "Move Shape"
      Height          =   300
      Left            =   60
      TabIndex        =   15
      ToolTipText     =   "Move the shape to the above library & folder"
      Top             =   5925
      Width           =   1575
   End
   Begin VB.CommandButton btnOpen 
      Caption         =   "Open Library..."
      Height          =   300
      Left            =   60
      TabIndex        =   14
      ToolTipText     =   "Open a source library to copy/move shapes from."
      Top             =   4185
      Width           =   1575
   End
   Begin VB.CommandButton btnMoveShapeWithinLib 
      Caption         =   "Move Shape"
      Height          =   300
      Left            =   60
      TabIndex        =   13
      ToolTipText     =   "Move the current shape from the selected folder to a new folder."
      Top             =   3450
      Width           =   1335
   End
   Begin VB.ComboBox cbToFolder 
      Height          =   315
      Left            =   2220
      Style           =   2  'Dropdown List
      TabIndex        =   11
      Top             =   3420
      Width           =   3315
   End
   Begin VB.CommandButton btnDeleteShape 
      Caption         =   "Delete Shape"
      Height          =   300
      Left            =   60
      TabIndex        =   10
      ToolTipText     =   "Delete the selected shape"
      Top             =   2340
      Width           =   1575
   End
   Begin VB.CommandButton btnRenameShape 
      Caption         =   "Rename Shape..."
      Height          =   300
      Left            =   60
      TabIndex        =   9
      ToolTipText     =   "Rename the selected shape."
      Top             =   2040
      Width           =   1575
   End
   Begin VB.ComboBox cbLibraries 
      Height          =   315
      Left            =   2220
      Style           =   2  'Dropdown List
      TabIndex        =   8
      Top             =   270
      Width           =   5955
   End
   Begin VB.CommandButton btnDeleteFolder 
      Caption         =   "Delete Folder"
      Height          =   300
      Left            =   60
      TabIndex        =   7
      ToolTipText     =   "Delete the selected folder and any shapes in it from the library."
      Top             =   1410
      Width           =   1575
   End
   Begin VB.CommandButton btnRnameFolder 
      Caption         =   "Rename Folder..."
      Height          =   300
      Left            =   60
      TabIndex        =   6
      ToolTipText     =   "Rename the selected folder."
      Top             =   1110
      Width           =   1575
   End
   Begin VB.CommandButton btnCreateFolder 
      Caption         =   "Create Folder..."
      Height          =   300
      Left            =   60
      TabIndex        =   5
      ToolTipText     =   "Create a new folder in the selected library."
      Top             =   810
      Width           =   1575
   End
   Begin VB.CommandButton btnCreateLibrary 
      Caption         =   "Create Library..."
      Height          =   300
      Left            =   60
      TabIndex        =   4
      ToolTipText     =   "Create a New, Empty library."
      Top             =   0
      Width           =   1575
   End
   Begin VB.ListBox lstShapes 
      Height          =   2205
      Left            =   2220
      Sorted          =   -1  'True
      TabIndex        =   2
      Top             =   1170
      Width           =   3315
   End
   Begin VB.ComboBox cbFolders 
      Height          =   315
      Left            =   2220
      Style           =   2  'Dropdown List
      TabIndex        =   0
      Top             =   750
      Width           =   3315
   End
   Begin MSComDlg.CommonDialog CommonDlg 
      Left            =   1560
      Top             =   6480
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin CGCtrlLib.CG SourceShapeGe 
      Height          =   2355
      Left            =   5640
      TabIndex        =   51
      Top             =   4620
      Width           =   2415
      _Version        =   65536
      _ExtentX        =   4260
      _ExtentY        =   4154
      _StockProps     =   64
   End
   Begin VB.Label lblSRCSmartShape 
      AutoSize        =   -1  'True
      Caption         =   "Smart Shape"
      Height          =   195
      Left            =   5820
      TabIndex        =   32
      Top             =   6990
      Width           =   915
   End
   Begin VB.Label lblDSTSmartShape 
      AutoSize        =   -1  'True
      Caption         =   "Smart Shape"
      Height          =   195
      Left            =   5790
      TabIndex        =   31
      Top             =   3120
      Width           =   915
   End
   Begin VB.Label lblDSTLibrarySts 
      AutoSize        =   -1  'True
      BackColor       =   &H80000000&
      Caption         =   "Destination Library"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Left            =   2070
      TabIndex        =   29
      Top             =   45
      Width           =   1605
   End
   Begin VB.Label Label9 
      AutoSize        =   -1  'True
      Caption         =   "Move or Copy shapes from this library to the selected library above"
      Height          =   195
      Left            =   3480
      TabIndex        =   24
      Top             =   3930
      Width           =   4665
   End
   Begin VB.Label lblSRCLibrarySts 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      BackColor       =   &H80000000&
      Caption         =   "Source Library"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Left            =   2070
      TabIndex        =   23
      Top             =   3930
      Width           =   1245
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "Folder"
      Height          =   195
      Left            =   1740
      TabIndex        =   22
      Top             =   4695
      Width           =   435
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "Shape"
      Height          =   195
      Left            =   1725
      TabIndex        =   21
      Top             =   5835
      Width           =   465
   End
   Begin VB.Line Line1 
      BorderWidth     =   2
      X1              =   0
      X2              =   11655
      Y1              =   3870
      Y2              =   3855
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      Caption         =   "To Folder"
      Height          =   195
      Left            =   1470
      TabIndex        =   12
      Top             =   3480
      Width           =   675
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "Shape"
      Height          =   195
      Left            =   1710
      TabIndex        =   3
      Top             =   2250
      Width           =   465
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "Folder"
      Height          =   195
      Left            =   1710
      TabIndex        =   1
      Top             =   810
      Width           =   435
   End
End
Attribute VB_Name = "frmShapeLibMgr"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
'
'======================================================================================
Option Explicit

'========================================================
'
' Declarations
'
'
Private Declare Function GetSystemDirectory _
      Lib "Kernel32" Alias "GetSystemDirectoryA" _
      (ByVal lpBuffer As String, ByVal nSize As Long) As Long

'
' Ge control variables
'
Dim m_strLibraryPath As String   ' path to library for this drawing
Dim m_bUpdating As Boolean

' use these to set up list boxes when making changes
Dim m_strCurrLibrary As String
Dim m_strCurrFolder As String
Dim m_strCurrShape As String
Private m_bDSTReadOnly As Boolean


Private m_aShapes As Collection ' coll of GeShapeDefInfo

Private m_LbrMgrSRC As GeLibraryMgr
Private m_LbrMgrDST As GeLibraryMgr

Private m_strCurPath As String  ' last fileopen

Private m_strLibrarySRC As String
Private m_bSRCReadOnly As Boolean

Private m_collDSTLibs As Collection

Private m_bDoingUpdate As Boolean

Private m_collDWGLibs As Collection

Private m_bDSTValid As Boolean
Private m_bSRCValid As Boolean

Private m_objInfoDefault As GeShapeDefInfo  ' the one displaying DST default props

'======================================================================================
' End Declarations
'======================================================================================
'======================================================================================
' Display/Populate lists etc.
'======================================================================================

'------------------------------
Private Sub LoadDefaultsDST(strFolder As String, strShape As String)
  ' load it from DB and display
  Dim bEnable As Boolean
  Dim i As Integer
  
  On Error Resume Next
  Set m_objInfoDefault = Nothing
  
  If Not m_LbrMgrDST Is Nothing Then
    Set m_objInfoDefault = m_LbrMgrDST.GetShapeDefInfo_ByFolderAndShape(strFolder, strShape)
    If Not m_objInfoDefault Is Nothing Then
      '
      bEnable = m_bDSTValid And m_objInfoDefault.HasDefaultProps
      ' DDX
      chkCanMove.Value = IIf(m_objInfoDefault.CanMove, 1, 0)
      chkAutoScale.Value = IIf(m_objInfoDefault.AutoScaleOnInsert, 1, 0)
      chkCanSelect.Value = IIf(m_objInfoDefault.CanSelect, 1, 0)
      With lbScaleModeDST
        For i = 0 To .ListCount - 1
          If .ItemData(i) = m_objInfoDefault.ScaleMode Then
            .ListIndex = i
            Exit For
          End If
        Next i
      End With
      With lbRotateModeDST
        For i = 0 To .ListCount - 1
          If .ItemData(i) = m_objInfoDefault.RotateMode Then
            .ListIndex = i
            Exit For
          End If
        Next i
      End With
      
      txtUserDataFlt.Text = m_objInfoDefault.UserDataFlt
      txtUserDataStr.Text = m_objInfoDefault.UserDataStr
      '
    End If
  End If
  '
  chkCanMove.Enabled = bEnable
  chkAutoScale.Enabled = bEnable
  chkCanSelect.Enabled = bEnable
  lbScaleModeDST.Enabled = bEnable
  lbRotateModeDST.Enabled = bEnable
  txtUserDataFlt.Enabled = bEnable
  txtUserDataStr.Enabled = bEnable

End Sub

'------------------------------
Private Sub SaveDefaultDST()
  ' save any changes in default props to DB
  Dim bSave As Boolean, bVal As Boolean
  
  On Error Resume Next
  If Not m_LbrMgrDST Is Nothing Then
    If (Not m_LbrMgrDST.ReadOnly) And m_bDSTValid Then
      If Not m_objInfoDefault Is Nothing Then
        ' see if any changes. Save if so
        '
        bVal = IIf(chkCanMove.Value = 0, False, True)
        If m_objInfoDefault.CanMove <> bVal Then
          m_objInfoDefault.CanMove = bVal: bSave = True
        End If
        '
        bVal = IIf(chkAutoScale.Value = 0, False, True)
        If m_objInfoDefault.AutoScaleOnInsert <> bVal Then
          m_objInfoDefault.AutoScaleOnInsert = bVal: bSave = True
        End If
        '
        bVal = IIf(chkCanSelect.Value = 0, False, True)
        If m_objInfoDefault.CanSelect <> bVal Then
          m_objInfoDefault.CanSelect = bVal: bSave = True
        End If
        '
        If lbScaleModeDST.ItemData(lbScaleModeDST.ListIndex) <> m_objInfoDefault.ScaleMode Then
          m_objInfoDefault.ScaleMode = lbScaleModeDST.ItemData(lbScaleModeDST.ListIndex): bSave = True
        End If
        '
        If lbRotateModeDST.ItemData(lbRotateModeDST.ListIndex) <> m_objInfoDefault.RotateMode Then
          m_objInfoDefault.RotateMode = lbRotateModeDST.ItemData(lbRotateModeDST.ListIndex): bSave = True
        End If
        '
        Dim sVal As Single
        sVal = CSng(txtUserDataFlt.Text)
        txtUserDataFlt.Text = sVal
        If m_objInfoDefault.UserDataFlt <> sVal Then
          m_objInfoDefault.UserDataFlt = sVal:  bSave = True
        End If
        ' 255 chars max
        If Len(txtUserDataStr.Text) > 255 Then txtUserDataStr.Text = Left(txtUserDataStr.Text, 255)
        If m_objInfoDefault.UserDataStr <> txtUserDataStr.Text Then
          m_objInfoDefault.UserDataStr = txtUserDataStr.Text:   bSave = True
        End If
      End If
    End If
    '
    If bSave Then
      If Not m_LbrMgrDST.UpdateDefaultProperties(m_objInfoDefault) Then
        MsgBox "Failed to save Default Property changes. Contact tech support."
      End If
    End If
  End If
End Sub

'------------------------------
Private Sub ResetDefaultDST()
  ' clear refs
  Set m_objInfoDefault = Nothing
End Sub

'---------------------------
Private Sub AttachLibraryDWG(strLibrary As String)
  'attach to the drawing
  Dim i As Long
  On Error Resume Next
  For i = 1 To m_collDWGLibs.Count
    If UCase(m_collDWGLibs.Item(i)) = UCase(strLibrary) Then Exit Sub
  Next i
  m_collDWGLibs.Add strLibrary
End Sub
'---------------------------
Private Sub DetachLibraryDWG(strLibrary As String)
  Dim i As Long
  On Error Resume Next
  For i = 1 To m_collDWGLibs.Count
    If UCase(m_collDWGLibs.Item(i)) = UCase(strLibrary) Then
      m_collDWGLibs.Remove i
      Exit Sub
    End If
  Next i
End Sub

'---------------------------
Private Function IsLibraryAttached(strNewLibrary As String) As Boolean
  'is attached to this dialog
  Dim i As Long
  Dim strTmp As String
  On Error Resume Next
  For i = 1 To m_collDSTLibs.Count
    strTmp = m_collDSTLibs.Item(i)
    If UCase(strTmp) = UCase(strNewLibrary) Then
      IsLibraryAttached = True
      Exit Function
    End If
  Next
End Function

'---------------------------
Private Sub AttachLibrary(strLibrary As String)
  'attach to this dialog
  Dim i As Long
  On Error Resume Next
  For i = 1 To m_collDSTLibs.Count
    If UCase(m_collDSTLibs.Item(i)) = UCase(strLibrary) Then Exit Sub
  Next i
  m_collDSTLibs.Add strLibrary
End Sub
'---------------------------
Private Sub DetachLibrary(strLibrary As String)
  Dim i As Long
  On Error Resume Next
  For i = 1 To m_collDSTLibs.Count
    If UCase(m_collDSTLibs.Item(i)) = UCase(strLibrary) Then
      m_collDSTLibs.Remove i
      Exit Sub
    End If
  Next i
End Sub

'---------------------------
Public Sub ListAttachedLibraries(aLibraries As Variant)
  ' list those attached to current drawing
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim i As Integer
  Dim strLib As String
  
  On Error Resume Next
  
  uBnd = UBound(aLibraries)
  lBnd = LBound(aLibraries)
  If (err <> 0) Or (uBnd < lBnd) Then
    err = 0
    Exit Sub
  End If

  For i = lBnd To uBnd
    strLib = aLibraries(i)
    AttachLibrary strLib
    AttachLibraryDWG strLib
  Next i
End Sub


'---------------------------
Private Sub ListLibrariesFoldersShapes()
  ' show all three lists
  Dim strLib As String
  Dim i As Integer
  Dim nDX As Integer
  Dim bUpdating As Boolean
  
  ResetDefaultDST
  PopulateLibrariesListBox
  
  If Len(m_strCurrLibrary) > 0 Then
    ' see if there was something previously displayed, if yes
    ' attemp to re-display it
    nDX = -1
    For i = 0 To cbLibraries.ListCount
      If m_strCurrLibrary = cbLibraries.List(i) Then
        nDX = i
      End If
    Next i
    If nDX = -1 Then
      m_strCurrLibrary = ""
      m_strCurrFolder = ""
      m_strCurrShape = ""
    Else
      bUpdating = m_bUpdating
      m_bUpdating = True
      cbLibraries.ListIndex = nDX
      m_bUpdating = bUpdating
    End If
   End If
   
  If cbLibraries.ListCount > 0 Then
    strLib = cbLibraries.List(cbLibraries.ListIndex)
    ListFoldersShapes strLib
  End If

End Sub

'---------------------------
Private Sub ListFoldersShapes(strLib As String)
' show lists of folders and shapes
  Dim strFolder As String
  Dim ndxFolder As Long
  Dim nDX As Integer
  Dim i As Integer
  Dim bUpdating As Boolean
  
  PopulateShapeFolderListBox strLib
  
  If Len(m_strCurrFolder) > 0 Then
    ' see if there was something previously displayed, if yes
    ' attemp to re-display it
    nDX = -1
    For i = 0 To cbFolders.ListCount
      If m_strCurrFolder = cbFolders.List(i) Then
        nDX = i
      End If
    Next i
    If nDX = -1 Then
      m_strCurrShape = ""
    Else
      bUpdating = m_bUpdating
      m_bUpdating = True
      cbFolders.ListIndex = nDX
      m_bUpdating = bUpdating
    End If
   End If
  
  If cbFolders.ListCount > 0 Then
    strFolder = cbFolders.List(cbFolders.ListIndex)
    ndxFolder = cbFolders.ItemData(cbFolders.ListIndex)
    ListShapes strFolder, ndxFolder, strLib
  End If
End Sub

'---------------------------
Private Sub ListShapes(strFold As String, ndxFolder As Long, strLib As String)
  ' show shapes list
  Dim nDX As Integer
  Dim i As Integer
  
  ResetDefaultDST
  PopulateShapeListBox ndxFolder, strLib

  If Len(m_strCurrShape) > 0 Then
    ' see if there was something previously displayed, if yes
    ' attemp to re-display it
    nDX = -1
    For i = 0 To lstShapes.ListCount
      If m_strCurrShape = lstShapes.List(i) Then
        nDX = i
      End If
    Next i
  End If
  
  If nDX > -1 Then ShowShape nDX, strFold, strLib
End Sub


'======================================================================================
' Button handling
'======================================================================================
'---------------------------
Private Sub btnExit_Click()
  Unload Me
End Sub

'---------------------------
Private Sub btnAdd_Click()
  ' add to my list
  Dim strLibrary As String
  Dim strTemp As String
  
  On Error Resume Next

  If LocateMaster(strLibrary, strTemp, "Locate desired shape library") Then
    If Len(strTemp) > 0 Then
      strLibrary = strTemp
      If err = 0 Then
        m_strCurrLibrary = strLibrary
        m_strCurrFolder = ""
        m_strCurrShape = ""
        
        If Not IsLibraryAttached(strLibrary) Then
          AttachLibrary strLibrary
        End If
        
        If OpenLibDST(strLibrary) Then
          ListLibrariesFoldersShapes
        End If
      End If
    End If
  End If
End Sub


'---------------------------
Private Sub btnCreateLibrary_Click()
  Dim strEmptyLibrary As String
  Dim strNewLibrary As String
  Dim strTemp As String, strTmp As String
  Dim strNew As String
  Dim bMaster As Boolean
  
  On Error Resume Next

  Dim lRet As Long
  Dim strSysPath As String
  Dim strTest As String
  Dim bPromptEmpty As String
  Dim strpath As String
  
  ' get Win32System path from system
  strSysPath = Space(255)
  lRet = GetSystemDirectory(strSysPath, 255)
  strSysPath = LTrim(RTrim(strSysPath))
  
  ' could get junk at end of path
  strTest = CStr(Mid(strSysPath, Len(strSysPath), 1))
  If Not IsAlpha(strTest) And Not IsNumeric(strTest) Then
    strSysPath = Left(strSysPath, Len(strSysPath) - 1)
  End If
  strEmptyLibrary = strSysPath & "\ge.mdb"
  If FileExists(strEmptyLibrary) Then
    bPromptEmpty = False
  Else
    bPromptEmpty = True
  End If
  
  ' AEM - the default library should be in the System32 dir
  If bPromptEmpty Then
    MsgBox "Cannot find the master GE.MDB Library. Please locate now!", vbExclamation
    strEmptyLibrary = strSysPath & "\ge.mdb"
    If Not FileExists(strEmptyLibrary) Then
      strTemp = "ge.mdb"
      '
      strTmp = m_strCurPath
      bMaster = LocateMaster(strEmptyLibrary, strTemp, "Locate master GE.MDB file")
      m_strCurPath = strTmp
      '
      If bMaster Then
        If Len(strTemp) > 0 Then
          strEmptyLibrary = strTemp
        Else
          Exit Sub
        End If
      Else
        Exit Sub
      End If
    End If
  End If
  
  strpath = CurDir
  strTemp = "NewLibrary.mdb"
  If Not GetNewFilePath(strpath, strTemp, strNewLibrary, "Create New Library") Then Exit Sub
  
  ' get path to destination directory
  m_strLibraryPath = StripFile(strNewLibrary)
  If Len(m_strLibraryPath) < 1 Then
    m_strLibraryPath = CurDir
    strNewLibrary = m_strLibraryPath & "\" & strNewLibrary
  End If
  
  ' check that a library with this name doesn't already exists in drawing
  If IsLibraryAttached(strNewLibrary) Or FileExists(strNewLibrary) Then
    MsgBox "Library already exists!", vbExclamation, "Error Adding Library"
    Exit Sub
  End If
  If strNewLibrary = "ge.mdb" Then
    MsgBox " 'GE' is the same name as the master library, please use another name.", , "Shape Library Manager"
    Exit Sub
  End If
 
 ' Copy source to target.
  FileCopy strEmptyLibrary, strNewLibrary
  If err = 0 Then
    ' update list
    m_bUpdating = True
    m_strCurrLibrary = strNewLibrary
    m_strCurrFolder = ""
    m_strCurrShape = ""
    
    AttachLibrary strNewLibrary
    ListLibrariesFoldersShapes
    m_bUpdating = False
    OpenLibDST strNewLibrary
  End If
End Sub

'---------------------------
Private Function VerifyValidDSTLibrary(ByVal bCheckFolder As Boolean) As Boolean
  ' make sure got valid DST Lib & Folder
  
  If bCheckFolder Then
    If cbFolders.ListIndex > -1 And cbLibraries.ListIndex > -1 Then
      VerifyValidDSTLibrary = True
    Else
      MsgBox "Please select valid Destination Library and Folder"
      VerifyValidDSTLibrary = False
      Exit Function
    End If
  Else
    If cbLibraries.ListIndex > -1 Then
      VerifyValidDSTLibrary = True
    Else
      MsgBox "Please select valid Destination Library"
      VerifyValidDSTLibrary = False
      Exit Function
    End If
  End If
  
  ' src valid ?
  If Len(m_strLibrarySRC) = 0 Then
    MsgBox "Please select valid Source Library, Folder and/or Shape"
    VerifyValidDSTLibrary = False
  Else
    VerifyValidDSTLibrary = True
  End If
  
  ' dst same as src ?
  If UCase(m_strLibrarySRC) = UCase(m_strCurrLibrary) Then
    MsgBox "Source and Destination libraries cannot be the same."
    VerifyValidDSTLibrary = False
  Else
    VerifyValidDSTLibrary = True
  End If

End Function

'---------------------------
Private Sub btnCopyShape_Click()
  ' Copy Shape
  Dim strName As String
  Dim nRet As Integer
  
  On Error Resume Next
  If Not VerifyValidDSTLibrary(True) Then Exit Sub
  
  strName = lstSrcShapes.List(lstSrcShapes.ListIndex)
  If Len(strName) = 0 Then Exit Sub
  
  ' force to insert in case shape in srcGE already exploded
  ShowSourceShape lstSrcShapes.ListIndex, cbSrcFolders.Text, txtSourceLib.Text
  
  If Not DoesShapeRequireOtherShapes(strName) Then
    CopyShape
  Else
    nRet = MsgBox("This shape requires other shapes that must be copied." & vbCr & "Do you want them copied also?", vbYesNo)
    If nRet = vbYes Then
      CopySupportingShapes
      CopyShape
    Else
      Exit Sub
    End If
  End If

  m_strCurrFolder = cbFolders.Text
  m_strCurrShape = lstSrcShapes.List(lstSrcShapes.ListIndex)
  ListShapes cbFolders.Text, _
            cbFolders.ItemData(cbFolders.ListIndex), _
            cbLibraries.Text
  
End Sub

'---------------------------
Private Sub btnMore_Click()
  ' more/less details
  On Error Resume Next
  If picMore.Visible Then
    picMore.Visible = False
    btnMore.Caption = "More >>>"
  Else
    picMore.Visible = True
    btnMore.Caption = "Less <<<"
  End If
  form_Resize
  
End Sub

'---------------------------
Private Sub btnMoveShapeToLib_Click()
  ' Move Shape to dst lib
  Dim strName As String
  Dim nRet As Integer
  Dim strSRCFolder As String
  Dim i As Long
  
  On Error Resume Next
  If Not VerifyValidDSTLibrary(True) Then Exit Sub
  strName = lstSrcShapes.List(lstSrcShapes.ListIndex)
  If Len(strName) = 0 Then Exit Sub
  
  ' force to insert in case shape in srcGE already exploded
  ShowSourceShape lstSrcShapes.ListIndex, cbSrcFolders.Text, txtSourceLib.Text
  
  If Not DoesShapeRequireOtherShapes(strName) Then
    CopyShape
    DeleteSourceShape
  Else
    nRet = MsgBox("This shape requires other shapes that must be moved." & vbCr & "Do you want them moved also?", vbYesNo)
    If nRet = vbYes Then
      CopySupportingShapes
      CopyShape
      DeleteSupportingShapes
      DeleteSourceShape
    Else
      Exit Sub
    End If
  End If

  m_strCurrFolder = cbToFolder.Text
  m_strCurrShape = lstSrcShapes.List(lstSrcShapes.ListIndex)
  ListShapes cbFolders.Text, cbFolders.ItemData(cbFolders.ListIndex), cbLibraries.Text

  ' reopen SRC and moveto current folder
  strSRCFolder = cbSrcFolders.List(cbSrcFolders.ListIndex)
  OpenLibSRC m_strLibrarySRC
  PopulateSourceFolderListBox m_strLibrarySRC
  For i = 0 To cbSrcFolders.ListCount - 1
    If cbSrcFolders.List(i) = strSRCFolder Then
      cbSrcFolders_Click
      Exit For
    End If
  Next i

End Sub


'---------------------------
Private Sub btnMove_Click()
  ' move Folder
  Dim bRet As Boolean
  Dim bMod As Boolean
  Dim i As Long
  Dim strSRCFolder As String
  Dim strTmp As String
  
  On Error Resume Next
  If Not VerifyValidDSTLibrary(False) Then Exit Sub
  
  ResetDefaultDST
  ' memorize next Folder
  strTmp = cbSrcFolders.Text
  For i = 0 To cbSrcFolders.ListCount - 1
    If cbSrcFolders.List(i) = strTmp Then
      If i < cbSrcFolders.ListCount - 1 Then
        ' get next
        strSRCFolder = cbSrcFolders.List(i + 1)
      Else
        ' get prev
        If ((i - 1) > -1) Then strSRCFolder = cbSrcFolders.List(i - 1)
      End If
      Exit For
    End If
  Next i
  '' copy and delete
  bRet = m_LbrMgrDST.CopyFolder(m_LbrMgrDST.LibDB, m_LbrMgrSRC.LibDB, cbSrcFolders.Text, bMod)
  If bRet Then
    DeleteSourceFolder
    m_strCurrFolder = cbFolders.Text
    m_strCurrShape = lstSrcShapes.List(lstSrcShapes.ListIndex)
    ListFoldersShapes m_strCurrLibrary
  
    ' reopen SRC and move to next folder
    OpenLibSRC m_strLibrarySRC
    PopulateSourceFolderListBox m_strLibrarySRC
    For i = 0 To cbSrcFolders.ListCount - 1
      If cbSrcFolders.List(i) = strSRCFolder Then
        cbSrcFolders_Click
        Exit For
      End If
    Next i
  Else
    MsgBox "Failed to remove folder after copy"
  End If
  
End Sub

'---------------------------
Private Sub btnCopy_Click()
  ' Copy Folder
  Dim bMod As Boolean
  Dim bRet As Boolean
  
  On Error Resume Next
  If Not VerifyValidDSTLibrary(False) Then Exit Sub
  ResetDefaultDST
  bRet = m_LbrMgrDST.CopyFolder(m_LbrMgrDST.LibDB, m_LbrMgrSRC.LibDB, cbSrcFolders.Text, bMod)
  
  If Not bRet Then MsgBox "Failed to copy Folder"
  
  m_strCurrFolder = cbSrcFolders.Text
  m_strCurrShape = lstSrcShapes.List(lstSrcShapes.ListIndex)

  ListFoldersShapes m_strCurrLibrary
End Sub


'-----------------------
Private Sub btnCreateFolder_Click()
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strDir As String
  Dim strNew As String
  Dim lRet As Long
  
  On Error Resume Next
  strDB = m_strCurrLibrary
  If Not FileExists(strDB) Then Exit Sub

  strNew = InputBox("Please enter a Folder Name.", "Create a Folder")
  If Len(strNew) < 1 Then Exit Sub

  lRet = CreateFolder(strDB, strNew)
  If lRet = -1 Then
     MsgBox "Folder '" & strNew & "' already exists!", vbExclamation, "Error Renaming Folder"
     Exit Sub
  End If
  
  m_strCurrFolder = strNew
  m_strCurrShape = ""
  ListLibrariesFoldersShapes
End Sub

'-----------------------
Private Sub btnRenameShape_Click()
Dim strDB As String
Dim dbs As Database
Dim rst As Recordset
Dim strSQL As String
Dim strDir As String
Dim strNew As String

  On Error Resume Next
  strDB = m_strCurrLibrary
  If Not FileExists(strDB) Then Exit Sub

  strNew = InputBox("Enter new name for '" & lstShapes.List(lstShapes.ListIndex) & "'", "Rename Shape", lstShapes.List(lstShapes.ListIndex))
  If Len(strNew) < 1 Then Exit Sub
  If Len(strNew) > 32 Then
    MsgBox "Shape names can only be 32 characters long.", vbExclamation
    Exit Sub
  End If
  
  strSQL = "SELECT * "
  strSQL = strSQL & "From GeTblShape Where ShapeName = '" & lstShapes.List(lstShapes.ListIndex) & _
            "' and FolderID =" & cbFolders.ItemData(cbFolders.ListIndex)
  
  Set dbs = OpenDatabase(strDB)
  If err = 0 Then
    Set rst = dbs.OpenRecordset(strSQL, dbOpenDynaset)  ' dbOpenTable)
    If err = 0 Then
      With rst
        If .RecordCount = 1 Then
          .Edit
          !ShapeName = strNew
          .Update
        End If
        .Close
      End With
    End If
    dbs.Close
  End If
  
  If err = 3022 Then
    MsgBox "Shape already exists!", vbExclamation, "Error Renaming Shape"
    err = 0
    Exit Sub
  End If
  
  m_strCurrFolder = cbFolders.List(cbFolders.ListIndex)
  m_strCurrShape = strNew
  ListShapes m_strCurrFolder, cbFolders.ItemData(cbFolders.ListIndex), m_strCurrLibrary
End Sub

'-----------------------
Private Sub btnRnameFolder_Click()
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strSQL As String
  Dim strNew As String
  Dim strOld As String
  
  On Error Resume Next
  strDB = m_strCurrLibrary
  If Not FileExists(strDB) Then Exit Sub
  strOld = cbFolders.List(cbFolders.ListIndex)
  strNew = InputBox("Enter new name for '" & strOld & "'", "New Folder Name.", strOld)
  If Len(strNew) < 1 Then Exit Sub
  If Len(strNew) > 32 Then
    MsgBox "Folder names can only be 32 characters long.", vbExclamation
    Exit Sub
  End If
  
  If strNew = strOld Then
    MsgBox "Folder already exists!", vbExclamation, "Error Renaming Folder"
    Exit Sub
  End If
  
  strSQL = "SELECT * From GeTblFolder Where FolderName = '" & strOld & "'"
  Set dbs = OpenDatabase(strDB)
  If err = 0 Then
    Set rst = dbs.OpenRecordset(strSQL, dbOpenDynaset)
    If err = 0 Then
      With rst
        If .RecordCount = 1 Then
          .Edit
          !FolderName = strNew
          .Update
        Else
          MsgBox "Folder '" & strOld & "' doesn't exist.", , "Shape Library Manager"
        End If
        .Close
      End With
    End If
    dbs.Close
  End If
  '
  m_strCurrFolder = strNew
  m_strCurrShape = lstShapes.List(lstShapes.ListIndex)
  ListFoldersShapes m_strCurrLibrary
End Sub

'-----------------------
Private Sub btnDeleteFolder_Click()
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim rstTmp As Recordset
  Dim strSQL As String
  Dim strDir As String
  Dim nRet As Integer
  Dim i As Integer

  On Error Resume Next
  
  strDB = m_strCurrLibrary
  If Not FileExists(strDB) Then Exit Sub
  
  strSQL = "SELECT * "
  strSQL = strSQL & "From GeTblFolder Where FolderName = '" & cbFolders & "'"
  
  Set dbs = OpenDatabase(strDB)
  Set rst = dbs.OpenRecordset(strSQL, dbOpenDynaset)  ' dbOpenTable)
  
  With rst
    If Not .EOF And Not .BOF Then
      ' see how many shapes exist in this folder
      strSQL = "SELECT * "
      strSQL = strSQL & "From GeTblShape Where FolderID = " & !FolderID
      Set rstTmp = dbs.OpenRecordset(strSQL, dbOpenDynaset)  ' dbOpenTable)
      If Not rstTmp.EOF And Not rstTmp.BOF Then
        rstTmp.MoveLast
        rstTmp.MoveFirst
        If rstTmp.RecordCount > 0 Then
          nRet = MsgBox("There are " & rstTmp.RecordCount & " shapes in this folder. Delete folder?", vbOKCancel)
          If nRet = vbOK Then
            ' delete folder and shapes
            ' delete shapes first
            rstTmp.MoveLast
            For i = rstTmp.RecordCount - 1 To 0 Step -1
              rstTmp.Delete
              rstTmp.MovePrevious
            Next i
            '
            rstTmp.Close
            ' delete folder
            rst.Delete
          End If
        End If
      Else
        rstTmp.Close
        ' delete folder
        rst.Delete
      End If
    End If
    .Close
  End With
  '
  dbs.Close
  
  m_strCurrFolder = ""
  m_strCurrShape = ""
  ListLibrariesFoldersShapes
End Sub

'-----------------------
Private Sub btnDeleteShape_Click()
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strSQL As String
  Dim strDir As String

  On Error Resume Next
  strDB = m_strCurrLibrary
  If Not FileExists(strDB) Then Exit Sub
  
  ' confirm!
  If chkConfirmDeleteShape.Value <> 0 Then
    Dim nRet As Integer
    nRet = MsgBox("Are you sure you want to delete this shape ?", vbYesNo)
    If nRet <> vbYes Then Exit Sub
  End If
  
  ' check for folder name as well, could have shapes with same
  ' name in different folders
  strSQL = "SELECT * "
  strSQL = strSQL & "From GeTblShape Where ShapeName = '" & lstShapes.List(lstShapes.ListIndex) & _
            "' and FolderID =" & cbFolders.ItemData(cbFolders.ListIndex)
  
  Set dbs = OpenDatabase(strDB)
  Set rst = dbs.OpenRecordset(strSQL, dbOpenDynaset)  ' dbOpenTable)
  
  With rst
    If .RecordCount = 1 Then
      .Delete
    End If
    .Close
  End With
  dbs.Close

  m_strCurrFolder = cbFolders.List(cbFolders.ListIndex)
  m_strCurrShape = ""
  ListShapes m_strCurrFolder, cbFolders.ItemData(cbFolders.ListIndex), m_strCurrLibrary
End Sub

'-----------------------
Private Sub btnMoveShapeWithinLib_Click()
  ' move Shape to another folder
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strSQL As String
  Dim strDir As String
  Dim bMoved As Boolean
  Dim strShape As String
  
  On Error Resume Next
  If cbFolders.ItemData(cbFolders.ListIndex) = cbToFolder.ItemData(cbToFolder.ListIndex) Then
    MsgBox "The 'From' and 'To' folders are the same, no action will take place.", vbExclamation, "Shape Library Manager"
    Exit Sub
  End If
  
  strDB = m_strCurrLibrary
  If Not FileExists(strDB) Then Exit Sub
  strShape = lstShapes.List(lstShapes.ListIndex)
  strSQL = "SELECT * "
  strSQL = strSQL & "From GeTblShape Where ShapeName = '" & strShape & _
      "' and FolderID = " & cbFolders.ItemData(cbFolders.ListIndex)
  
  Set dbs = OpenDatabase(strDB)
  If err = 0 Then
    Set rst = dbs.OpenRecordset(strSQL, dbOpenDynaset)
    If err = 0 Then
      With rst
        If Not .BOF And Not .EOF Then
          .MoveFirst
          .Edit
          !FolderID = cbToFolder.ItemData(cbToFolder.ListIndex)
          .Update
          If err = 0 Then bMoved = True
        End If
        .Close
      End With
    End If
    dbs.Close
  End If
  ' update lb
  If bMoved Then
    Dim i As Long
    For i = 0 To lstShapes.ListCount - 1
      If strShape = lstShapes.List(i) Then
        lstShapes.RemoveItem i
        If lstShapes.ListCount > 0 Then
          If (lstShapes.ListCount - 1) >= i Then          ' select next
            lstShapes.Selected(i) = True
          ElseIf (lstShapes.ListCount - 2) >= i Then      ' select prev
            lstShapes.Selected(i - 1) = True
          ElseIf (lstShapes.ListCount) = 1 Then           ' select first
            lstShapes.Selected(0) = True
          End If
        End If
        Exit For
      End If
    Next i
  End If
  
  ' AEM - 2/28/00 - DO NOT Change folders  automatically
'  m_strCurrFolder = cbToFolder.List(cbToFolder.ListIndex)
'  m_strCurrShape = lstShapes.List(lstShapes.ListIndex)
'  ' since 2 folder are affected, don't call 'ListShapes'
'  ListFoldersShapes cbLibraries.Text
End Sub

'-----------------------
Private Sub btnOpen_Click()
  Dim strLibrary As String
  Dim strTemp As String
  
  On Error Resume Next
  ' if one already open, close it
  SourceShapeGe.InitNew
  txtSourceLib.Text = ""
  cbSrcFolders.Clear
  lstSrcShapes.Clear

  If LocateMaster(strLibrary, strTemp, "Select a Library to open") Then
    If Len(strTemp) > 0 Then
      strLibrary = strTemp
      If err = 0 Then
        txtSourceLib.Text = strLibrary
        OpenLibSRC strLibrary
        PopulateSourceFolderListBox strLibrary
      End If
    End If
  Else
    Exit Sub
  End If
End Sub

'-----------------------
Private Sub cbLibraries_Click()
  Dim strName As String
  
  On Error Resume Next
  If m_bUpdating = True Then Exit Sub
  strName = cbLibraries.Text
  OpenLibDST strName
  ListFoldersShapes strName
  
  lstShapes.SetFocus
End Sub
'-----------------------
Private Function OpenLibDST(strName As String) As Boolean
  Dim bRet As Boolean
  On Error Resume Next
  
  ShapeGe.InitNew
  ShapeGe.MarginDisplay = False
  ShapeGe.Grid = False
  ShapeGe.Tool = GETOOL_NONE
  ShapeGe.DrawInsertionPoints = True

  ResetDefaultDST
  m_LbrMgrDST.CloseLibrary
  If Len(strName) = 0 Then
    EnableChangesDST False
    lblDSTLibrarySts.Caption = "Destination Library"
    Exit Function
  End If
  
  m_bDSTReadOnly = False
  bRet = m_LbrMgrDST.OpenLibrary(strName, False)   ' bReadOnly
    ' try again, read only
  If Not bRet Then
    bRet = m_LbrMgrDST.OpenLibrary(strName, True)   ' bReadOnly
    m_bDSTReadOnly = True
  End If
  If Not bRet Then
    EnableChangesDST False
  Else
    EnableChangesDST Not m_LbrMgrDST.ReadOnly
  End If
  '
  m_strCurrLibrary = strName
  OpenLibDST = bRet
End Function

'-----------------------
Private Function OpenLibSRC(strName As String) As Boolean
  Dim bRet As Boolean
  On Error Resume Next
  
  SourceShapeGe.InitNew
  SourceShapeGe.MarginDisplay = False
  SourceShapeGe.Grid = False
  SourceShapeGe.Tool = GETOOL_NONE  '
  SourceShapeGe.DrawInsertionPoints = True

  m_LbrMgrSRC.CloseLibrary
  If Len(strName) = 0 Then
    EnableChangesSRC False
    Exit Function
  End If
  
  m_bSRCReadOnly = False
  bRet = m_LbrMgrSRC.OpenLibrary(strName, False)   ' bReadOnly
    ' try again, read only
  If Not bRet Then
    bRet = m_LbrMgrSRC.OpenLibrary(strName, True)   ' bReadOnly
    m_bSRCReadOnly = True
  End If
  If Not bRet Then
    EnableChangesSRC False
  Else
    EnableChangesSRC Not m_LbrMgrSRC.ReadOnly
  End If
  '
  If bRet Then m_strLibrarySRC = strName
  OpenLibSRC = bRet
End Function

'-----------------------
Private Sub EnableChangesSRC(ByVal bEnable As Boolean)
  ' allow user to do something - SRC
  Dim strCap As String
  
  btnMove.Enabled = bEnable     ' folder
  btnMoveShapeToLib.Enabled = bEnable
  
  strCap = "Source Library"
  If Not bEnable Then strCap = strCap & " (read only)"
  lblSRCLibrarySts.Caption = strCap

  m_bSRCValid = bEnable

  If m_bDSTValid And m_bSRCValid Then
    btnDiff.Enabled = True
  Else
    btnDiff.Enabled = False
  End If

End Sub

'-----------------------
Private Sub EnableChangesDST(ByVal bEnable As Boolean)
  ' allow user to do something - DST
  Dim strCap As String
  
  
'  btnAdd.Enabled = bEnable
  btnCopy.Enabled = bEnable
  btnCopyShape.Enabled = bEnable
  btnDeleteShape.Enabled = bEnable
  btnRenameShape.Enabled = bEnable
  '
  btnCreateFolder.Enabled = bEnable
  btnDeleteFolder.Enabled = bEnable
  btnRnameFolder.Enabled = bEnable
  btnMoveShapeWithinLib.Enabled = bEnable
  '
  If m_bSRCReadOnly Then
    btnMove.Enabled = False
    btnMoveShapeToLib.Enabled = False
  Else
    btnMove.Enabled = bEnable
    btnMoveShapeToLib.Enabled = bEnable
  End If

  strCap = "Destination Library"
  If Not bEnable Then strCap = strCap & " (read only)"
  lblDSTLibrarySts.Caption = strCap
  
  m_bDSTValid = bEnable
  
  If m_bDSTValid And m_bSRCValid Then
    btnDiff.Enabled = True
  Else
    btnDiff.Enabled = False
  End If
  '


End Sub

'-----------------------
Private Sub cbFolders_Click()
  If m_bUpdating = True Then Exit Sub
  PopulateShapeListBox cbFolders.ItemData(cbFolders.ListIndex), cbLibraries.Text
  ShowShape 0, cbFolders.List(cbFolders.ListIndex), cbLibraries.Text
  cbFolders.SetFocus
End Sub
'-----------------------
Private Sub cbToFolder_Click()
  If m_bUpdating = True Then Exit Sub
  lstShapes.SetFocus
End Sub


'-----------------------
Private Sub cbSrcFolders_Click()
  If m_bUpdating = True Then Exit Sub
  PopulateSourceShapeListBox cbSrcFolders.ItemData(cbSrcFolders.ListIndex), txtSourceLib.Text
End Sub

'-----------------------
Private Sub Form_Activate()
  Static bFirst As Boolean
  On Error Resume Next
  If Not bFirst Then
    bFirst = True
    If (m_collDSTLibs.Count > 0) Then cbLibraries_Click
  End If
End Sub

'-----------------------
Private Sub Form_Initialize()
  On Error Resume Next
  Set m_LbrMgrSRC = New GeLibraryMgr
  Set m_LbrMgrDST = New GeLibraryMgr
  Set m_aShapes = New Collection
  Set m_collDSTLibs = New Collection
  Set m_collDWGLibs = New Collection
End Sub

'-----------------------
Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
  '
  On Error Resume Next
'  ' look for Ctrl-F1 to highlight maintenance button
'  If (Shift And vbCtrlMask) > 0 Then
'    If KeyCode = vbKeyF1 Then
'      btnMaintenance.Visible = True
'    End If
'  End If
End Sub

'-----------------------
Private Sub Form_Load()
  
  On Error Resume Next
  
  m_strCurrLibrary = ""
  m_strCurrFolder = ""
  m_strCurrShape = ""
  lblDSTSmartShape.Caption = ""
  
  lblSRCSmartShape.Caption = ""
  
  m_bUpdating = True
  ClearSourceShapeGe
  ListLibrariesFoldersShapes
  m_bUpdating = False
  '
  ShapeGe.GrabHandlesEnabled = False
  SourceShapeGe.GrabHandlesEnabled = False
End Sub

'-----------------------
Private Sub form_Resize()
  Dim y As Long
  On Error Resume Next
  If picMore.Visible Then
    picMore.Top = ShapeGe.Top
    picMore.Left = ShapeGe.Left + ShapeGe.Width + 130
    Me.Width = picMore.Left + picMore.Width + 140
    y = Line1.Y1 - picMore.Top
    Line3.Y1 = y
    Line3.Y2 = y
    Line3.X1 = 0
    Line3.X2 = picMore.Width
  Else
    Me.Width = btnExit.Left + btnExit.Width + 140
  End If
End Sub


'-----------------------
Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
  Dim i As Long
  
  On Error Resume Next
  SaveDefaultDST
  ResetDefaultDST
  Set m_collDWGLibs = Nothing
  Set m_collDSTLibs = Nothing
    
    ' Erase m_aShapes
  For i = 1 To m_aShapes.Count
    m_aShapes.Remove 1
  Next i

  Set m_aShapes = Nothing
  Set m_LbrMgrSRC = Nothing
  Set m_LbrMgrDST = Nothing
End Sub

'----------------------
Private Sub lstSrcShapes_Click()
  '
  On Error Resume Next
  ShowSourceShape lstSrcShapes.ListIndex, cbSrcFolders.Text, txtSourceLib.Text
  ' call just to list member shapes
  DoesShapeRequireOtherShapes lstSrcShapes.List(lstSrcShapes.ListIndex)
  
  lstSrcShapes.SetFocus
End Sub

'======================================================================================
' End Button handling
'======================================================================================

'======================================================================================
' Misc Function
'======================================================================================

'----------------------------
Private Function DoesShapeRequireOtherShapes(strName As String) As Boolean
  Dim aLibraries As Variant
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim i As Integer
  Dim strLibPath As String
  Dim pos As Long, pos1 As Long
  Dim strShp As String, strFolder As String, strLib As String
  
  On Error Resume Next
  DoesShapeRequireOtherShapes = False

  lbSortedShapes.Clear
  txtSortedShapes.Text = ""
  BeginWaitCursor
  ''
  ' Erase m_aShapes
  For i = 1 To m_aShapes.Count
    m_aShapes.Remove 1
  Next i
  
  
  ' list those in use in drawing
  SourceShapeGe.GetUsedShapeDefs aLibraries
  uBnd = UBound(aLibraries)
  lBnd = LBound(aLibraries)
  
  ' if err, no shapes there
  If err = 0 And (uBnd >= lBnd) Then
    For i = lBnd To uBnd
      strLibPath = aLibraries(i)
      pos = InStr(strLibPath, "!")
      If pos Then
        strLib = Trim(Left(strLibPath, pos - 1))
        pos1 = InStr(pos + 1, strLibPath, "!")
        If pos1 Then
          strFolder = Trim(Mid(strLibPath, pos + 1, pos1 - pos - 1))
          strShp = Trim(Right(strLibPath, Len(strLibPath) - pos1))
        End If
      End If
      ' if not one passed in
      If strShp <> strName Then
        '
        Dim objInfo As GeShapeDefInfo
        Set objInfo = New GeShapeDefInfo
        objInfo.FolderName = strFolder
        objInfo.LibraryName = strLib
        objInfo.ShapeName = strShp
        m_aShapes.Add objInfo
        
        lbSortedShapes.AddItem strLibPath
        txtSortedShapes.Text = txtSortedShapes.Text & lbSortedShapes.List(lbSortedShapes.NewIndex) & vbCr & vbLf
        DoesShapeRequireOtherShapes = True
      End If
    Next i
    '
  Else
    err = 0
  End If
  ''
  EndWaitCursor
End Function



'----------------------------
Private Function CreateFolder(strDB As String, strName As String) As Long
' if succesful return folder ID
  Dim dbs As Database
  Dim rst As Recordset
  Dim strDir As String
  Dim strNew As String
  Dim ID As Long
  
  On Error GoTo err
  ID = 0
  CreateFolder = ID
  Set dbs = OpenDatabase(strDB)
  Set rst = dbs.OpenRecordset("GeTblFolder", dbOpenTable)
  
  On Error Resume Next
  
  With rst
    .AddNew
    ID = !FolderID
    !FolderName = strName
    .Update
  End With
  dbs.Close
  
  If err = 3022 Then
    CreateFolder = -1
    err = 0
    Exit Function
  End If

  CreateFolder = ID
  Exit Function
err:
  MsgBox "Couldn't open " & strDB & " ; " & Error, , "Shape Library Manager"

End Function



'*******************************************************************************

'------------------------------
Private Function CopySupportingShapes() As Boolean
  ' copy supporting shapes to DST lib
  Dim i As Long
  Dim strSQL As String
  
  Dim strDB As String
  Dim dbSRC As Database
  Dim rst As Recordset

  Dim dbsDest As Database
  Dim rstDest As Recordset
  Dim strDBDest As String
    
  Dim bRet As Boolean
  Dim nIDShp As Long
  Dim objInfo As GeShapeDefInfo
  Dim bDoIt As Boolean
  Dim nRet As Integer
  Dim strTmp As String
  
  On Error Resume Next
  CopySupportingShapes = True
  If m_aShapes.Count < 1 Then Exit Function
  CopySupportingShapes = False
  
  strDB = m_strLibrarySRC
  If Not FileExists(m_strLibrarySRC) Then Exit Function

  ' open SRC
  If Not OpenDBandVerify(Nothing, dbSRC, strDB, False, True) Then Exit Function
  
  bRet = True
  For i = 1 To m_aShapes.Count
    Set objInfo = m_aShapes.Item(i)
      ' only copy if from SRC library (could be from some other)
    If UCase(objInfo.LibraryName) = UCase(strDB) Then
      If dbsDest Is Nothing Then
        strDBDest = m_strCurrLibrary
        If Not OpenDBandVerify(Nothing, dbsDest, strDBDest, False, False) Then
          bRet = False
          Exit For
        Else
          Set rstDest = dbsDest.OpenRecordset("GeTblShape", dbOpenTable)
          If Not VERIFY_ERR Then
            dbSRC.Close
            dbsDest.Close
            CopySupportingShapes = False
            Exit Function
          End If
        End If
      End If
      '
      ' open source in read mode
'      nIDShp = objInfo.ShapeID
'      strSQL = "SELECT * FROM GeTblShape WHERE ShapeID = " & nIDShp
      strTmp = objInfo.ShapeName
      strSQL = "SELECT * FROM GeTblShape WHERE ShapeName = """ & strTmp & """ ;"
      
      Set rst = dbSRC.OpenRecordset(strSQL, dbOpenSnapshot)
      '' copy
      If err = 0 Then
        With rst
          If Not .BOF And Not .EOF Then
            .MoveFirst
            ' see if alreay got a shape with GUID. If so, prompt user
            rstDest.Index = "ShapeGUID"
            rstDest.Seek "=", !ShapeGUID
            bDoIt = False
            If Not rstDest.NoMatch Then
              nRet = MsgBox("The supporting shape '" & objInfo.ShapeName & "' already exists in the destination library." & vbCr & "Do you want to overwrite it?", vbYesNo)
              If nRet = vbYes Then bDoIt = True
            Else
              bDoIt = True
            End If
            '
            If bDoIt Then
              ' copy each shape over to new folder
              rstDest.AddNew
              rstDest!FolderID = cbFolders.ItemData(cbFolders.ListIndex)
              rstDest!ShapeName = !ShapeName
              rstDest!ShapeCreateDate = !ShapeCreateDate
              rstDest!ShapeModifyDate = !ShapeModifyDate
              rstDest!ShapeRevision = !ShapeRevision
              rstDest!ShapeObject = !ShapeObject
              If Not IsNull(!ShapeDesc) Then rstDest!ShapeDesc = !ShapeDesc
              rstDest!ShapeGUID = !ShapeGUID
              
              rstDest!DrawingWidth = !DrawingWidth
              rstDest!DrawingHeight = !DrawingHeight
              
              rstDest.Update
            End If
          End If
          .Close
        End With
      End If
    End If
    '
  Next i
  
  If Not rstDest Is Nothing Then rstDest.Close
  If Not dbsDest Is Nothing Then dbsDest.Close
  
  If err = 3022 Then
    MsgBox "One or more shapes were not copied as they already exist", , "Shape Library Manager"
  End If
  ''
  dbSRC.Close
  CopySupportingShapes = bRet
End Function

'--------------------------------
Private Function CopyShape() As Boolean
  Dim strDBSRC As String
  Dim strDBDST As String
  
  Dim strSQL As String
  Dim dbs As Database
  Dim rst As Recordset

  Dim dbsDest As Database
  Dim rstDest As Recordset
  
  On Error Resume Next
  CopyShape = False
  strDBSRC = m_strLibrarySRC
  If Not FileExists(strDBSRC) Then Exit Function
  If Len(cbSrcFolders.Text) < 1 Then Exit Function
  
  strDBDST = m_strCurrLibrary
  If Not FileExists(strDBDST) Then Exit Function
  
  ''
  Set dbs = OpenDatabase(strDBSRC, True, True)
  ' open source in read mode
  strSQL = "Select * from GeTblShape where ShapeID = " & lstSrcShapes.ItemData(lstSrcShapes.ListIndex)
  Set rst = dbs.OpenRecordset(strSQL, dbOpenSnapshot)
  If Not VERIFY_ERR Then
    dbs.Close
    Exit Function
  End If
  
  Set dbsDest = OpenDatabase(strDBDST)
  Set rstDest = dbsDest.OpenRecordset("GeTblShape", dbOpenTable)
  If Not VERIFY_ERR Then
    dbsDest.Close
    dbs.Close
    Exit Function
  End If
  
  With rst
    If Not .EOF And Not .BOF Then
      .MoveFirst
      ' copy each shape over to new folder
      rstDest.AddNew
      rstDest!FolderID = cbFolders.ItemData(cbFolders.ListIndex)
      rstDest!ShapeName = !ShapeName
      rstDest!ShapeCreateDate = !ShapeCreateDate
      rstDest!ShapeModifyDate = !ShapeModifyDate
      rstDest!ShapeRevision = !ShapeRevision
      rstDest!ShapeObject = !ShapeObject
      If Not IsNull(!ShapeDesc) Then rstDest!ShapeDesc = !ShapeDesc
      rstDest!ShapeGUID = !ShapeGUID
      
      rstDest!DrawingWidth = !DrawingWidth
      rstDest!DrawingHeight = !DrawingHeight
      
      rstDest!AutoScaleOnInsert = !AutoScaleOnInsert
      rstDest!CanMove = !CanMove
      rstDest!CanSelect = !CanSelect
      rstDest!ScaleMode = !ScaleMode
      rstDest!RotateMode = !RotateMode
      rstDest!UserDataFlt = !UserDataFlt
      If Not IsNull(!UserDataStr) Then rstDest!UserDataStr = !UserDataStr
      
      rstDest.Update
    End If
    .Close
  End With
  
  rstDest.Close
  dbs.Close
  dbsDest.Close
  
  If err = 3022 Then
    MsgBox "One or more shapes weren't copied as they already exist", , "Shape Library Manager"
  End If
  
  CopyShape = True
  
End Function

'--------------------------------
Private Function DeleteSourceShape() As Boolean
  ' delete SRC shape
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strSQL As String
  Dim strDir As String
  
  On Error Resume Next
  
  DeleteSourceShape = False
  strDB = m_strLibrarySRC
  If Not FileExists(m_strLibrarySRC) Then Exit Function
  
  ClearSourceShapeGe
  SourceShapeGe.ZoomPage
  
  ' check for folder name as well, could have shapes with same
  ' name in different folders
  strSQL = "SELECT * "
  strSQL = strSQL & "FROM GeTblShape WHERE ShapeName = '" & _
        lstSrcShapes.List(lstSrcShapes.ListIndex) & "' and FolderID = " & cbSrcFolders.ItemData(cbSrcFolders.ListIndex)
  
  Set dbs = OpenDatabase(strDB)
  Set rst = dbs.OpenRecordset(strSQL, dbOpenDynaset)  ' dbOpenTable)
  If VERIFY_ERR Then
    With rst
      If Not .BOF And Not .EOF Then
        .MoveFirst
        .Delete
      End If
      .Close
    End With
    DeleteSourceShape = True
  End If
  dbs.Close
End Function

'------------------------------
Private Function DeleteSupportingShapes() As Boolean
  ' Delete supporting shapes from DST lib
  Dim i As Long
  Dim strSQL As String
  
  Dim strDB As String
  Dim dbSRC As Database
  Dim rst As Recordset

  Dim bRet As Boolean
  Dim nIDShp As Long
  Dim objInfo As GeShapeDefInfo
  
  On Error Resume Next
  DeleteSupportingShapes = True
  If m_aShapes.Count < 1 Then Exit Function
  DeleteSupportingShapes = False
  
  strDB = m_strLibrarySRC
  If Not FileExists(m_strLibrarySRC) Then Exit Function
  ' open SRC
  If Not OpenDBandVerify(Nothing, dbSRC, strDB, False, False) Then Exit Function
  
  bRet = True
  For i = 1 To m_aShapes.Count
    Set objInfo = m_aShapes.Item(i)
      ' only delete if from SRC library (could be from some other)
    If UCase(objInfo.LibraryName) = UCase(strDB) Then
      ' open source in write mode
      nIDShp = objInfo.ShapeID
      strSQL = "SELECT * FROM GeTblShape WHERE ShapeID = " & nIDShp
      Set rst = dbSRC.OpenRecordset(strSQL, dbOpenDynaset)
      '' delete
      If VERIFY_ERR Then
        With rst
          If Not .BOF And Not .EOF Then
            .MoveFirst
            .Delete
          End If
          .Close
        End With
      Else
        bRet = False
        Exit For
      End If
    End If
  Next i
  ''
  dbSRC.Close
  DeleteSupportingShapes = bRet
End Function

'--------------------------------
Private Function CopyFolder() As Boolean
  Dim strDB As String
  Dim strSQL As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strDir As String

  Dim dbsDest As Database
  Dim rstDest As Recordset
  Dim strDBDST As String
  Dim NewFolderID As Long
  
  On Error Resume Next
  CopyFolder = False
  strDB = m_strLibrarySRC
  If Not FileExists(strDB) Then Exit Function
  If Len(cbSrcFolders.Text) < 1 Then Exit Function
  
  strDBDST = m_strCurrLibrary
  If Not FileExists(strDBDST) Then Exit Function
  
  Set dbs = OpenDatabase(strDB, True, True)
  ' open source in read mode
  strSQL = "Select * from GeTblShape where FolderID = " & cbSrcFolders.ItemData(cbSrcFolders.ListIndex)
  Set rst = dbs.OpenRecordset(strSQL, dbOpenSnapshot)
  
  ' create a new folder
  Set dbsDest = OpenDatabase(strDBDST)
  strSQL = "Select * from GeTblFolder where FolderName = '" & cbSrcFolders.Text & "'"
  Set rstDest = dbsDest.OpenRecordset(strSQL, dbOpenDynaset)
  If Not rstDest.EOF And Not rstDest.BOF Then
    rstDest.MoveLast
    rstDest.MoveFirst
  End If
  ' make sure it doesn't exist
  If rstDest.RecordCount > 0 Then
    NewFolderID = rstDest!FolderID
  Else
    rstDest.Close
    ' make new folder
    Set rstDest = dbsDest.OpenRecordset("GeTblFolder", dbOpenTable)
    
    rstDest.AddNew
    rstDest!FolderName = cbSrcFolders.Text
    NewFolderID = rstDest!FolderID
    rstDest.Update
  End If
  
  rstDest.Close
  Set rstDest = dbsDest.OpenRecordset("GeTblShape", dbOpenTable)
  
  With rst
    If Not .EOF And Not .BOF Then
      rst.MoveLast
      rst.MoveFirst
    End If
    If rst.RecordCount > 0 Then
      Do While Not .EOF And Not .BOF
        ' copy each shape over to new folder
        rstDest.AddNew
        rstDest!FolderID = NewFolderID
        rstDest!ShapeName = !ShapeName
        rstDest!ShapeCreateDate = !ShapeCreateDate
        rstDest!ShapeModifyDate = !ShapeModifyDate
        rstDest!ShapeRevision = !ShapeRevision
        rstDest!ShapeObject = !ShapeObject
        rstDest!ShapeDesc = !ShapeDesc
        rstDest!ShapeGUID = !ShapeGUID
        
        rstDest!DrawingWidth = !DrawingWidth
        rstDest!DrawingHeight = !DrawingHeight
        
        rstDest!AutoScaleOnInsert = !AutoScaleOnInsert
        rstDest!CanMove = !CanMove
        rstDest!CanSelect = !CanSelect
        rstDest!ScaleMode = !ScaleMode
        rstDest!RotateMode = !RotateMode
        rstDest!UserDataFlt = !UserDataFlt
        If Not IsNull(!UserDataStr) Then rstDest!UserDataStr = !UserDataStr
        
        rstDest.Update
      rst.MoveNext
      Loop
    End If
    .Close
  End With
  rstDest.Close

  dbs.Close
  dbsDest.Close
  
  CopyFolder = True
End Function

'------------------------------
Private Function DeleteSourceFolder() As Boolean
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim rstTmp As Recordset
  Dim strSQL As String
  Dim strDir As String
  Dim nRet As Integer
  Dim i As Integer

  On Error Resume Next
  
  strDB = m_strLibrarySRC
  If Not FileExists(strDB) Then Exit Function

  strSQL = "SELECT * "
  strSQL = strSQL & "From GeTblFolder Where FolderName = '" & cbSrcFolders.Text & "'"
  
  Set dbs = OpenDatabase(strDB)
  Set rst = dbs.OpenRecordset(strSQL, dbOpenDynaset)  ' dbOpenTable)
  
  With rst
    If .RecordCount = 1 Then
      
      ' see how many shapes exist in this folder
      strSQL = "SELECT * "
      strSQL = strSQL & "From GeTblShape Where FolderID = " & !FolderID
      Set rstTmp = dbs.OpenRecordset(strSQL, dbOpenDynaset)  ' dbOpenTable)
      If Not .EOF And Not .BOF Then
        rstTmp.MoveLast
        rstTmp.MoveFirst
      End If
      If rstTmp.RecordCount > 0 Then
        nRet = MsgBox("There are " & rstTmp.RecordCount & " shapes in this folder. Delete folder?", vbOKCancel, "Shape Library Manager")
        If nRet = vbOK Then
          ' delete folder and shapes
          ' delete shapes first
          rstTmp.MoveLast
          For i = rstTmp.RecordCount - 1 To 0 Step -1
            rstTmp.Delete
            rstTmp.MovePrevious
          Next i
          ' delete folder
          rst.Delete
        End If
      End If
    End If
    .Close
  End With

  dbs.Close
  DeleteSourceFolder = True
End Function

'------------------------------
Private Function LocateMaster(strDir As String, strLib As String, strPrompt As String) As Boolean
  Dim strCurrPath As String
  On Error Resume Next
  If Len(m_strCurPath) = 0 Then
    strCurrPath = CurDir
  Else
    strCurrPath = m_strCurPath
  End If
  
  LocateMaster = False
  CommonDlg.CancelError = True  ' enable so that can test for Err
  CommonDlg.DefaultExt = "MDB"
  CommonDlg.DialogTitle = strPrompt
  CommonDlg.MaxFileSize = 2600
  CommonDlg.FLAGS = cdlOFNHideReadOnly Or cdlOFNPathMustExist Or cdlOFNFileMustExist
  CommonDlg.InitDir = strCurrPath ' strDir
  CommonDlg.FileName = strLib ' strDir
  CommonDlg.Filter = "GE Library (*.mdb)|*.mdb||"
  CommonDlg.ShowOpen
  If err = 0 Then
    strLib = CommonDlg.FileName
    m_strCurPath = StripFile(strLib)
    LocateMaster = True
  End If

  ChDir strCurrPath
End Function

'------------------------------
Private Function GetNewFilePath(strDir As String, strFile As String, strLib As String, strPrompt As String) As Boolean
  Dim strCurrPath As String
  
  On Error Resume Next
  If Len(m_strCurPath) = 0 Then
    strCurrPath = CurDir
  Else
    strCurrPath = m_strCurPath
  End If
  
  GetNewFilePath = False
  CommonDlg.CancelError = True  ' enable so that can test for Err
  CommonDlg.DefaultExt = "MDB"
  CommonDlg.DialogTitle = strPrompt
  CommonDlg.MaxFileSize = 2600
  CommonDlg.FLAGS = cdlOFNHideReadOnly Or cdlOFNPathMustExist
  CommonDlg.InitDir = strDir
  CommonDlg.FileName = strFile
  CommonDlg.Filter = "GE Library (*.mdb)|*.mdb||"
  CommonDlg.ShowOpen
  If err = 0 Then
    strLib = CommonDlg.FileName
    m_strCurPath = StripFile(strLib)
    GetNewFilePath = True
  End If
End Function

'------------------------------
Private Sub PopulateLibrariesListBox()
  Dim aLibraries As Variant
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim i As Integer
  Dim strLibPath As String
  Dim bUpdating As Boolean
  
  On Error Resume Next
  
  cbLibraries.Clear
  lstShapes.Clear
  cbFolders.Clear
  cbToFolder.Clear
  ClearShapeGe
  
  For i = 1 To m_collDSTLibs.Count
    strLibPath = m_collDSTLibs.Item(i)
    cbLibraries.AddItem strLibPath
  Next i
  
  If cbLibraries.ListCount > 0 Then
    bUpdating = m_bUpdating
    m_bUpdating = True
    cbLibraries.ListIndex = 0
    m_bUpdating = bUpdating
  End If
End Sub


'------------------------------
Private Function PopulateShapeFolderListBox(strLibPath As String)
  Dim dbs As Database
  Dim rst As Recordset
  Dim strSQL As String
  Dim strDir As String
  Dim bUpdating As Boolean

  On Error Resume Next
  cbFolders.Clear
  cbToFolder.Clear
  lstShapes.Clear
  
  If Not FileExists(strLibPath) Then Exit Function

  strSQL = "SELECT GeTblFolder.FolderName, GeTblFolder.FolderID "
  strSQL = strSQL & "From GeTblFolder "
  strSQL = strSQL & "ORDER BY GeTblFolder.FolderName"
  
  If m_bDSTReadOnly Then
    Set dbs = OpenDatabase(strLibPath, True, True)
  Else
    Set dbs = OpenDatabase(strLibPath, False, False)
  End If
  If err = 0 Then
    Set rst = dbs.OpenRecordset(strSQL, dbOpenSnapshot)
    If err = 0 Then
      With rst
        Do While Not .EOF And Not .BOF
          cbFolders.AddItem !FolderName
          cbFolders.ItemData(cbFolders.NewIndex) = !FolderID
          
          cbToFolder.AddItem !FolderName
          cbToFolder.ItemData(cbFolders.NewIndex) = !FolderID
          
          .MoveNext
        Loop
        .Close
      End With
    End If
    dbs.Close
  End If
  
  If cbFolders.ListCount > 0 Then
    bUpdating = m_bUpdating
    m_bUpdating = True
    cbFolders.ListIndex = 0
    cbToFolder.ListIndex = 0
    m_bUpdating = bUpdating
  End If
End Function


'------------------------------
Private Function PopulateShapeListBox(nFolderID As Long, strLibName As String)
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strSQL As String
  Dim strFolderName As String
  Dim bUpdating As Boolean
  Dim nRev As Long
  
  On Error Resume Next
  
  lstShapes.Clear
  strSQL = "SELECT GeTblShape.ShapeName, GeTblShape.FolderID, GeTblShape.ShapeRevision "
  strSQL = strSQL & " From GeTblShape Where GeTblShape.FolderID = " & nFolderID
  strSQL = strSQL & " ORDER BY GeTblShape.ShapeName"
  
  strDB = strLibName
  If m_bDSTReadOnly Then
    Set dbs = OpenDatabase(strDB, True, True)
  Else
    Set dbs = OpenDatabase(strDB, False, False)
  End If
  
  Set rst = dbs.OpenRecordset(strSQL, dbOpenSnapshot)
  With rst
    Do While Not .EOF And Not .BOF
      nRev = !ShapeRevision
      lstShapes.AddItem !ShapeName
      lstShapes.ItemData(lstShapes.NewIndex) = nRev
      .MoveNext
    Loop
    .Close
  End With
  dbs.Close

  If lstShapes.ListCount > 0 Then
    bUpdating = m_bUpdating
    m_bUpdating = True
    lstShapes.ListIndex = 0
    m_bUpdating = bUpdating
  End If
End Function

'------------------------------
Private Sub ClearShapeGe()
  ShapeGe.InitNew
  ShapeGe.DrawingWidth = 0.01
  ShapeGe.DrawingHeight = 0.01
  ShapeGe.MarginDisplay = False
End Sub
'------------------------------
Private Sub ClearSourceShapeGe()
  SourceShapeGe.InitNew
  SourceShapeGe.DrawingWidth = 0.01
  SourceShapeGe.DrawingHeight = 0.01
  SourceShapeGe.MarginDisplay = False
End Sub

'------------------------------
Private Sub ShowShape(nDX As Integer, strShapeFolderName As String, strLibName As String)
  Dim GeID As Long
  Dim strLib As String
  Dim strFolder As String
  Dim strShape As String
  Dim bUpdating As Boolean
  Dim nRev As Long
  Dim nGeType As Integer
  Dim ptX As Single, ptY As Single
  
  On Error Resume Next
  
  ' update to DB if required, then clear refs
  SaveDefaultDST
  ResetDefaultDST
  
  ClearShapeGe
  lblDSTSmartShape.Caption = ""
  
  If (nDX < 0) Or (nDX > lstShapes.ListCount) Then Exit Sub
  If lstShapes.ListCount < 1 Then Exit Sub

  strShape = lstShapes.List(nDX)
  ptX = 0#
  ptY = 0#
  ShapeGe.AttachLibrary strLibName
  GeID = ShapeGe.CreateShape(strLibName, strShapeFolderName, strShape, ptX, ptY)
  ScaleDwgForViewing ShapeGe
  ShapeGe.Tool = GETOOL_NONE
  
  ShapeGe.CurrentPropertyID = GeID  ' move into selector
  nGeType = ShapeGe.ObjectType
  ShapeGe.CurrentPropertyID = 0 ' reset
  
  If nGeType = EGeObjType.UserGroup Then
    lblDSTSmartShape.Caption = "Smart Shape"
  Else
    lblDSTSmartShape.Caption = ""
  End If
  
  ''
  LoadDefaultsDST strShapeFolderName, strShape
  
  ' make sure list index matches displayed shape
  bUpdating = m_bUpdating
  m_bUpdating = True
  lstShapes.ListIndex = nDX
  m_bUpdating = bUpdating

End Sub

'------------------------------
Private Sub ScaleDwgForViewing(Ge As CG)
  ' set up so don't show page area
  On Error Resume Next
  Dim llX As Single, llY As Single, urX As Single, urY As Single
  Dim dInflate As Single
  Dim strFmt As String
  Dim strWT As String, strHT As String
  
  Ge.GrabHandlesEnabled = False
  
  Ge.DrawingOriginX = -10000#
  Ge.DrawingOriginY = -10000#
  Ge.DrawingWidth = 0.01
  Ge.DrawingHeight = 0.01
  Ge.PageWidth = 0.01
  Ge.PageHeight = 0.01
  
  Ge.SelectAll
  Ge.GetExtents llX, llY, urX, urY
  Ge.SelRemoveAll

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

  Ge.ZoomRect llX, llY, urX, urY
  Ge.GrabHandlesEnabled = True

End Sub



'------------------------------
Private Sub lstShapes_Click()
  If m_bUpdating = True Then Exit Sub
  ShowShape lstShapes.ListIndex, cbFolders.Text, cbLibraries.Text
  lstShapes.SetFocus
End Sub

'------------------------------
Private Function PopulateSourceFolderListBox(strLibPath As String)
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strSQL As String
  Dim strDir As String

  On Error Resume Next
  cbSrcFolders.Clear
  lstSrcShapes.Clear
  
  m_bUpdating = True
  
  strDB = strLibPath
  If Not FileExists(strDB) Then
    m_bUpdating = False
    Exit Function
  End If
  
  strSQL = "SELECT GeTblFolder.FolderName, GeTblFolder.FolderID "
  strSQL = strSQL & "From GeTblFolder " 'Where GeTblFolder.FolderID = 1 "
  strSQL = strSQL & "ORDER BY GeTblFolder.FolderName"
  
  Set dbs = OpenDatabase(strDB, True, True)
  If err = 0 Then
    Set rst = dbs.OpenRecordset(strSQL, dbOpenSnapshot)
    If err = 0 Then
      With rst
        .MoveFirst
        ' Populate Recordset.
        Do While Not .EOF And Not .BOF
          cbSrcFolders.AddItem !FolderName
          cbSrcFolders.ItemData(cbSrcFolders.NewIndex) = !FolderID
          .MoveNext
        Loop
        .Close
      End With
    End If
    dbs.Close
  Else
    MsgBox "Couldn't open " & strDB & " ; " & Error, , "Shape Library Manager"
  End If
  
  If cbSrcFolders.ListCount > 0 Then
    cbSrcFolders.ListIndex = 0
    PopulateSourceShapeListBox cbSrcFolders.ItemData(cbSrcFolders.ListIndex), strLibPath
  End If
  
  EndWaitCursor
  m_bUpdating = False
  
End Function

'------------------------------
Private Function PopulateSourceShapeListBox(nFolderID As Long, strDBName As String)
  Dim strDB As String
  Dim dbs As Database
  Dim rst As Recordset
  Dim strSQL As String
  Dim nRev As Long

  On Error Resume Next
  
  lstSrcShapes.Clear
  strSQL = "SELECT GeTblShape.ShapeName, GeTblShape.FolderID, GeTblShape.ShapeID, GeTblShape.ShapeRevision "
  strSQL = strSQL & " From GeTblShape Where GeTblShape.FolderID = " & nFolderID
  strSQL = strSQL & " ORDER BY GeTblShape.ShapeName"
  
  strDB = strDBName
  Set dbs = OpenDatabase(strDB, True, True)
  Set rst = dbs.OpenRecordset(strSQL, dbOpenSnapshot)
  
  With rst
    If Not .EOF And Not .BOF Then
    .MoveFirst
      Do While Not .EOF And Not .BOF
        nRev = !ShapeRevision
        lstSrcShapes.AddItem !ShapeName
        lstSrcShapes.ItemData(lstSrcShapes.NewIndex) = !ShapeID ' !ShapeRevision
      
        .MoveNext
      Loop
    End If
    .Close
  End With

  dbs.Close
  lstSrcShapes.ListIndex = 0
  EndWaitCursor
  
  ShowSourceShape 0, cbSrcFolders.Text, strDBName
End Function

'------------------------------
Private Sub ShowSourceShape(nDX As Integer, strShapeFolderName As String, strLibName As String)
  Dim GeID As Long
  Dim strShape As String
  Dim strLib As String
  Dim strFolder As String
  Dim nRev As Long
  Dim ptX As Single, ptY As Single
  Dim objInfo As GeShapeDefInfo
  Dim nGeType As Integer

  On Error Resume Next
  
  ClearSourceShapeGe
  
  If (nDX < 0) Or (nDX > lstSrcShapes.ListCount) Then Exit Sub
  If lstSrcShapes.ListCount < 1 Then Exit Sub
  
  strShape = lstSrcShapes.List(nDX)

  ptX = 0#
  ptY = 0#
  SourceShapeGe.AttachLibrary strLibName
  GeID = SourceShapeGe.CreateShape(strLibName, strShapeFolderName, strShape, ptX, ptY)
  ScaleDwgForViewing SourceShapeGe
  SourceShapeGe.Tool = GETOOL_NONE

  SourceShapeGe.CurrentPropertyID = GeID  ' move into selector
  nGeType = SourceShapeGe.ObjectType
  SourceShapeGe.CurrentPropertyID = 0 ' reset
  
  If nGeType = EGeObjType.UserGroup Then
    lblSRCSmartShape.Caption = "Smart Shape"
  Else
    lblSRCSmartShape.Caption = ""
  End If
  ''
  lstSrcShapes.SetFocus
End Sub

'=======================================================
' Helpers
'=======================================================
'------------------------------
Private Function VERIFY_ERR() As Boolean
  ' Verify for the Err object
  ' Return True if OK
  VERIFY_ERR = True
  If Not err = 0 Then
    #If APP_DEBUG Then
      Dim strMsg As String
      strMsg = Me.Name & ":VERIFY_ERR Failed:" & Error
      MsgBox strMsg
    #End If
    VERIFY_ERR = False
  End If
End Function




