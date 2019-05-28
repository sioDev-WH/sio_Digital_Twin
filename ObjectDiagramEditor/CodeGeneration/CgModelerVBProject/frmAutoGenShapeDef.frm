VERSION 5.00
Object = "{E6F77CB3-6A30-11D5-89E6-00D0B74A80C3}#1.0#0"; "CGCtrl.ocx"
Begin VB.Form frmAutoGenShapeDef 
   Caption         =   "Auto Generate Shape"
   ClientHeight    =   6285
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   10425
   Icon            =   "frmAutoGenShapeDef.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   6285
   ScaleWidth      =   10425
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox chkDisplayConnectStates 
      Caption         =   "Display Connection States"
      Height          =   195
      Left            =   60
      TabIndex        =   2
      ToolTipText     =   "Draw Connection States (G=connected,B=half connected,R=Not connected,Y=error)"
      Top             =   3120
      Width           =   2895
   End
   Begin VB.CommandButton btnShape 
      Caption         =   "Insert Shape"
      Height          =   435
      Left            =   240
      TabIndex        =   1
      Top             =   300
      Width           =   1755
   End
   Begin CGCtrlLib.CG CG1 
      Height          =   3855
      Left            =   5040
      TabIndex        =   0
      Top             =   1020
      Width           =   4515
      _Version        =   65536
      _ExtentX        =   7964
      _ExtentY        =   6800
      _StockProps     =   64
   End
End
Attribute VB_Name = "frmAutoGenShapeDef"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
'
'======================================================================================
Option Explicit

'========================================================
' ******** Examples ************
'========================================================
'***********************************************************
' [ 1 ] - LIBRARY MANAGER
#If 0 Then
'' NOTE: put this function (ShapeManager) in ucMain and call this instead of the built in CGCtrl Library Manager
' you will need to include in your VB Project:
'1) frmShapeLibMgr.frm/frx
'2) GeLibraryMgr.cls
''
' change Shape menu handler as follows:
' Private Sub mnuShapeItem_Click(Index As Integer)
'    Case 10:   ShapeManager       ' Manage Library(s)
''
'---------------------------
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
#End If
'***********************************************************

'***********************************************************
' [ 2 ] - AUTOGENERATE SHAPEDEF
#If 0 Then
' example on how to call this form (from ucMain)
'------------------------------
Public Sub AutoGenerateShapeDef()
  ' AEM - 4/17/03
  ' autogenerate a shapeDef
  Dim frm As frmAutoGenShapeDef
  On Error Resume Next
  Set frm = New frmAutoGenShapeDef
  Set frm.GeCtrl = Ge1    ' ref to this control
  frm.Show vbModal
End Sub

#End If
'***********************************************************


'========================================================
' Declarations
'========================================================

Private m_GeCtrlExt As CG  ' The CG object passed in (the External one). It holds the actual drawing info

Private m_GeCtrl As CG            ' The CG object in this form (CG1)
Private m_strLibrary As String    ' Core Library of shapes used for AutoGeneration purpose
Private m_strCoreFolder As String ' the folder in the library with the core shapes

Private m_LbrMgr As GeLibraryMgr  ' So can easily create new folders in Library

'========================================================
' End Declarations
'========================================================

'***********************************************************
' example on how to display Connection States
' 4/21/03 - Note that the CGCtrl does not always redraw the lines fully when the state changes
' when it is in this mode (needs to be cleaned up).
' In the meanwhile, hit the F5 key (calls Redraw on CGCtrl)
'--------------------------
Private Sub chkDisplayConnectStates_Click()
  ' Draw Connection States (Green=connected,Blue=half connected,Red=Not connected,Yellow=error)
  CG1.DisplayConnectionStates = IIf(chkDisplayConnectStates.Value = 1, True, False)
  CG1.Redraw
'  cg1.SetFocus
End Sub
'***********************************************************




'========================================================
' the working code for this form
'========================================================


'------------------------------
Public Property Get GeCtrl() As CG
  Set GeCtrl = m_GeCtrlExt
End Property
'------------------------------
Public Property Set GeCtrl(obj As CG)
  ' ref to CGCtrl on form (or usercontrol) that called this form
  Set m_GeCtrlExt = obj
End Property

'------------------------------
Private Sub Form_Load()
  On Error Resume Next
  Set m_GeCtrl = CG1
  Set m_LbrMgr = New GeLibraryMgr
  
  ' set Library to test with
  SetupProjectLibrary

End Sub

'------------------------------
Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
  On Error Resume Next
  
  CloseLibrary    ' don't forget to close it (although it will be done when the class terminates)
  Set m_LbrMgr = Nothing
  Set m_GeCtrlExt = Nothing
  Set m_GeCtrl = Nothing
End Sub

'------------------------------
Private Sub SetupProjectLibrary()
  ' setup with Library and Folder to use that has built in shapes
  m_strLibrary = "f:\srcCG\samples\CoreShapes.cgl"
  m_strCoreFolder = "BaseShapes"
End Sub


'================================================================================
' Test code
'================================================================================
'------------------------------
Private Sub btnShape_Click()
  ' insert Shapes and a rect or 2. Then create shapeDef
  
  Dim strShape As String
  Dim ptX As Single, ptY As Single
  Dim fltLeft As Single, fltBottom As Single, fltRight As Single, fltTop As Single
  Dim GeID As Long
  Dim collID As New Collection
  
  Dim ndxRed As Long  ' index into CG color palette
  Dim ndxOrig As Long ' original default color (that user had selected)
  
  On Error Resume Next
  
  ' try creating the shapedef directly in the GeCtrl that this form is referencing.
  ' We need to keep track of all ids of things that I create (using collID)
  '
  If Not m_GeCtrlExt Is Nothing Then Set m_GeCtrl = m_GeCtrlExt
  
  
  ''
  ptX = 2:   ptY = 3
  strShape = "LeftConnectionWithLabel"
  ndxRed = 249                            ' can find these numbers from the Settings/Palette dialog
  
  '' insert a shape (or 2), then a rect, then create a shapeDef
  
  m_GeCtrl.GrabHandlesEnabled = False     ' turn em off so user doesn't get excited
  
  If CreateShape(strShape, ptX, ptY, GeID) Then
    collID.Add GeID
    ' create another one
    ptX = 2:   ptY = 2.5
    CreateShape strShape, ptX, ptY, GeID
    collID.Add GeID
    
    ' remove all from selection so their color does not get changed, then change default pen color
    ' which is color used when a new object is created. (The assumption is that if nothing is in selection,
    ' then any properties apply to defaults which are used when new object is created).
    '
    m_GeCtrl.SelRemoveAll
    ndxOrig = m_GeCtrl.PenColor     ' trap so can restore
    m_GeCtrl.PenColor = ndxRed
    '
    If CreateRectangle(1, 1, 4, 4, GeID) Then
      collID.Add GeID
      
      ' create another (testing)
      CreateRectangle 2, 2, 2.5, 2.5, GeID
      collID.Add GeID
      
      ' create yet another one
      ptX = 2:   ptY = 2
      CreateShape strShape, ptX, ptY, GeID
      collID.Add GeID
      ' create yet another one
      ptX = 2:   ptY = 1.5
      CreateShape strShape, ptX, ptY, GeID
      collID.Add GeID
      
      ' add all I created to the Selection List
      AddMyObjectsToSelection collID
      
      ' OR select everything and create a ShapeDef (or SmartShapeDef) from the selection.
      ' m_GeCtrl.SelectAll

      CompleteCreation 1, 1             ' make the insertion point at 1,1
    End If
  End If
  
  '
  m_GeCtrl.SelRemoveAll
  m_GeCtrl.PenColor = ndxOrig   ' restore Default Pen color
  m_GeCtrl.GrabHandlesEnabled = True ' turn em back on
  
  ' reset control ref to the one in this form
  Set m_GeCtrl = CG1

End Sub

'------------------------------
Private Function CompleteCreation(ptX As Single, ptY As Single) As Boolean
  ' everything in created. Now create shapedef
  Dim strLibAndFolder As String
  Dim strFolder As String
  
  On Error Resume Next
  
'  strFolder = "NewTestFolder"
'  strFolder = "NewTestFolder1"
  strFolder = "NewTestFolder2"
  
  ' Open Library, have LbrMgr check if the folder is there. If not, it will create a new folder.
  ' Note that the CGControl does NOT create Folders automatically (it assumes they are already there)
  If OpenLibrary Then
    If Not m_LbrMgr.EnsureFolderExists(strFolder) Then
      Exit Function
    End If
  Else
    Exit Function
  End If
  
  ' MUST use an exclamation point (!) to separate Library name from Folder name!
  ' Note the exclamations are NOT ALLOWED as part of a Shape or Folder Name (along with some other reserved characters)
  
  strLibAndFolder = m_strLibrary & "!" & strFolder
  
' THESE ALL WORK (AEM - 4/17/03)
'  CompleteCreation = CreateShapeDef(strLibAndFolder, "bob", ptX, ptY)
'  CompleteCreation = CreateShapeDef(strLibAndFolder, "bob1", ptX, ptY)
'  CompleteCreation = CreateShapeDef(strLibAndFolder, "bob2", ptX, ptY)
  CompleteCreation = CreateSmartShapeDef(strLibAndFolder, "bob2", ptX, ptY)

End Function


'================================================================================
' Real code
'================================================================================
'------------------------------
Private Sub AddMyObjectsToSelection(collID As Collection)
  ' add all in coll to selection
  Dim i As Long
  Dim GeID As Long
  
  On Error Resume Next
  m_GeCtrl.SelRemoveAll
  For i = 1 To collID.Count
    GeID = collID.Item(i)
    m_GeCtrl.SelAdd GeID
  Next i
  
End Sub

'------------------------------
Private Function CreateRectangle(fltLeft As Single, fltBottom As Single, _
                    fltRight As Single, fltTop As Single, GeID As Long) As Boolean
  ' create a Shape Instance
  On Error Resume Next
  GeID = m_GeCtrl.CreateRectangle(fltLeft, fltBottom, fltRight, fltTop)
  CreateRectangle = VERIFY_ERR
End Function


'------------------------------
Private Function CreateShape(strShape As String, ptX As Single, ptY As Single, GeID As Long) As Boolean
  ' create a Shape Instance
  On Error Resume Next
  GeID = m_GeCtrl.CreateShape(m_strLibrary, m_strCoreFolder, strShape, ptX, ptY)
  CreateShape = VERIFY_ERR
End Function

'------------------------------
Private Function CreateShapeDef(strLibAndFolder As String, strShape As String, ptX As Single, ptY As Single) As Boolean
  ' create a ShapeDef. ptX and ptY are the insertion point.
  ' we assume that there are objects selected at this point.
  ' returns False if failed, true otherwise
  
  On Error Resume Next
  
  m_GeCtrl.TreatShapesAsUserGroups = False
  CreateShapeDef = m_GeCtrl.CreateShapeDef(strLibAndFolder, strShape, ptX, ptY)

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Private Function CreateSmartShapeDef(strLibAndFolder As String, strShape As String, ptX As Single, ptY As Single) As Boolean
  ' create a SmartShapeDef. ptX and ptY are the insertion point.
  ' we assume that there are objects selected at this point.
  ' returns False if failed, true otherwise
  
  On Error Resume Next
  
  m_GeCtrl.TreatShapesAsUserGroups = True       ' the trick to tell Ctrl that we want to make a SmartShape (aka UserGroup)
  CreateSmartShapeDef = m_GeCtrl.CreateShapeDef(strLibAndFolder, strShape, ptX, ptY)
  m_GeCtrl.TreatShapesAsUserGroups = False      ' remember to reset

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Private Sub CloseLibrary()
  On Error Resume Next
  If Not m_LbrMgr Is Nothing Then
    m_LbrMgr.CloseLibrary   ' don't forget to close it (although it will be done when the class terminates)
  End If
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub
'------------------------------
Private Function OpenLibrary() As Boolean
  ' open the library
  Dim bReadonly As Boolean
  On Error Resume Next
  
  If Not m_LbrMgr.IsOpened Then
    bReadonly = False
    OpenLibrary = m_LbrMgr.OpenLibrary(m_strLibrary, bReadonly)
  Else
    OpenLibrary = True
  End If
  
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function


'=======================================================
' Other Helpers
'=======================================================
'------------------------------
Private Function VERIFY_ERR() As Boolean
  ' Verify for the Err object
  ' Return True if OK
  VERIFY_ERR = True
  If Not err = 0 Then
      #If APP_DEBUG Then
        Dim strMsg As String
        strMsg = TypeName(Me) & ":VERIFY_ERR Failed:" & Error
        ShowStatusMsg strMsg
      #End If
    VERIFY_ERR = False
  End If
End Function

