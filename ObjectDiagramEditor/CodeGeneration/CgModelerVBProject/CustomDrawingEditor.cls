VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CustomDrawingEditor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'======================================================================================
'
' Module:   CustomDrawingEditor
' helper for User Interaction with CG
'
'--------------------------------------------------------------------------------------
'======================================================================================

Option Explicit


'=================================================================
' Start of Declarations Section
'=================================================================

Private m_AppCtrl As ucMain ' frmCustomDrawing ' Form ' Object ' frmCAL     ''Form
Private m_UDIPropViewer As Object ' ucGeTools


Private m_CustDwg As CustomDrawing
Private m_UDIDefMgr As UDIDefMgr

Private m_strProjectPath As String   ' Project Path
Private m_strLibName As String   ' CustomLibrary
'Private m_strUMLProjName As String  ' UML project associated with the drawing
'
' Selection handling
'
Private m_collSel As Collection ' all selected objects
Private m_bDoingSelAdd As Boolean ' so can ignore Events back from Ge when adding to selection

Private m_bInsertingItem As Boolean ' so can ignore Events back from Ge when inserting items
Private m_NewItemID As Long
Private m_strDropText As String

Private m_collDelete As Collection     ' those being worked on
Private m_collCB As Collection     ' those on the ClipBoard
Private m_bUndoing As Boolean     ' in the middle of an undo

Private m_DXMove As Single        ' Ge DX/DY for Move/MoveCopy operations
Private m_DYMove As Single
Private m_bDoSelCopy As Boolean ' doing a Select Copy

Private m_dGeX As Double    ' current X/Y from Ge
Private m_dGeY As Double

Private m_bEnumGeObjects As Boolean
Private m_bDisableHit As Boolean

Private m_bEnumConnections As Boolean

Private m_bPasting As Boolean
Private m_bCutting As Boolean
Private m_bPastingMacro As Boolean

'
' CG Control variables
'
Private m_GeCtrl As CG  ' The object
Private m_bLoadingDwg As Boolean  ' indicates loading/saving a drawing
                                  ' (used so can ignore SelChanged event from GeCtrl)
Private m_bGeFileValid As Boolean ' indicates file is valid

'
Private m_bDirty As Boolean

'=================================================================
' End of Declarations Section
'=================================================================
'----------------------
Private Sub Class_Initialize()

  m_bGeFileValid = False
  m_bDirty = False
  
  Set m_collSel = New Collection
  Set m_collDelete = New Collection
  Set m_collCB = New Collection
  Set m_CustDwg = New CustomDrawing
  Set m_UDIDefMgr = New UDIDefMgr
  Set m_UDIDefMgr.m_custDrawEditor = Me

End Sub
'----------------------
Private Sub Class_Terminate()
  DestroyAll
End Sub

'------------------------------
Private Sub DestroyAll()
  ResetContent
  Set m_collSel = Nothing
  Set m_collDelete = Nothing
  Set m_collCB = Nothing

  Set m_UDIPropViewer = Nothing
  Set m_GeCtrl = Nothing
  Set m_AppCtrl = Nothing
  If Not m_CustDwg Is Nothing Then m_CustDwg.DestroyAll
  Set m_CustDwg = Nothing
  If Not m_UDIDefMgr Is Nothing Then m_UDIDefMgr.DestroyAll
  Set m_UDIDefMgr = Nothing
  
End Sub

'------------------------------
Public Sub ResetContent()
  On Error Resume Next
  DeleteItems
  ResetSelArray m_collSel
  ResetSelArray m_collDelete
  ClearClipBoard
  m_CustDwg.DestroyAll

End Sub
'------------------------------
Public Property Get IsDirty() As Boolean
  If Not m_CustDwg Is Nothing Then IsDirty = m_CustDwg.IsDirty
End Property
'------------------------------
Public Property Let IsDirty(bVal As Boolean)
  m_CustDwg.IsDirty = bVal
  m_AppCtrl.SetDwgIsModified bVal
End Property
'------------------------------
Public Property Get CustomDrawing() As CustomDrawing
  Set CustomDrawing = m_CustDwg
End Property

'------------------------------
Public Property Get UDIDefMgr() As UDIDefMgr
  Set UDIDefMgr = m_UDIDefMgr
End Property

'------------------------------
Public Property Set AppCtrl(obj As ucMain)
  Set m_AppCtrl = obj
End Property
Public Property Get AppCtrl() As ucMain
  Set AppCtrl = m_AppCtrl
End Property
'------------------------------
Public Property Set UDIPropViewer(obj As Object)
  Set m_UDIPropViewer = obj
End Property

'------------------------------
Public Property Set GeCtrl(obj As CG)
  Set m_GeCtrl = obj
  InitGe
End Property

'------------------------------
Public Property Get GeCtrl() As CG
  Set GeCtrl = m_GeCtrl
End Property

'------------------------------
Private Sub InitGe()
  If Not m_GeCtrl Is Nothing Then
    m_GeCtrl.CanEditUserIDs = False
    m_GeCtrl.OLEDropMode = 1  ' manual
'    m_GeCtrl.OLEDropMode = 2  ' automatic
    
    m_GeCtrl.KeyPreview = True  ' let it deal with arrow keys
  
'    m_GeCtrl.DrawingWidth = 230
'    m_GeCtrl.DrawingHeight = 150
'    m_GeCtrl.SnapHorz = 1
'    m_GeCtrl.SnapVert = 1
'    m_GeCtrl.GridHorz = 5
'    m_GeCtrl.GridVert = 5
'    m_GeCtrl.PageHeight = 11
'    m_GeCtrl.PageWidth = 17
'    m_GeCtrl.PageOrientation = 2  ' landscape ' 1 = Portrait
'    m_GeCtrl.FontHeight = 2           ' by default
    
    
    
'    If Len(m_strLibName) > 0 Then m_GeCtrl.AttachLibrary m_strLibName
'

  End If
End Sub


'Public Property Let UMLProjectName(strUMLProj As String)
'   m_strUMLProjName = strUMLProj
'   m_bDirty = True
'End Property

'Public Property Get UMLProjectName() As String
'  UMLProjectName = m_strUMLProjName
'End Property
'------------------------------
Public Function FileOpen(GeCtrl As CG, ByVal bReadonly As Boolean, ByVal strName As String) As Boolean
  ' check for Exceptions from CGOCX
  Dim bRet As Boolean
  Dim strMsg As String
  Dim bSaveRequired As Boolean
  Dim bHadItems As Boolean
  
  On Error Resume Next
  FileOpen = True
  m_bLoadingDwg = True
  
  'Retrieve the UML project name from attached library list
 ' m_strUMLProjName = GetUMLProjName()
    
  m_CustDwg.SerializeToGe GeCtrl, False  ' false = load
  SyncItemsToGE bSaveRequired, bHadItems
  If bSaveRequired And Not bReadonly Then
    m_bDirty = True
  End If
  
  m_bLoadingDwg = False
End Function

'------------------------------
Public Function FileSave(GeCtrl As CG) As Boolean
  ' save CustDwg to CGStg
  Dim strMsg As String
  Dim strNameCur As String
  Dim bAs As Boolean
  
  On Error Resume Next
  m_bLoadingDwg = True
  
  ' save the Substorage
  m_CustDwg.SerializeToGe GeCtrl, True
  m_bDirty = False
  FileSave = True
  
  'store association to UML project
' If IsUMLProjectOpen() And m_strUMLProjName <> "" Then
'    If FileExists(m_strUMLProjName) Then
'        m_GeCtrl.AttachLibrary m_strUMLProjName
'    End If
' End If
  
  m_bLoadingDwg = False
End Function
'------------------------------
Public Function CopyDrawing() As Boolean
  ' copy the CustDwg object only
  ' assign my object to be new one
End Function

'------------------------------
Private Sub SyncItemsToGE(bSaveRequired As Boolean, bHadItems As Boolean)
  ' sync up with Ge
  Dim uItems As UserDefinedItems
  Dim i As Long
  Dim Items As Collection
  Dim objUDI As UserDefinedItem
  Dim GeID As Long
  Dim nSIDID As Long
  Dim nIDOld As Long
  
  ' KAB --> removing unconnected items
  
  Dim nRemoved As Long

  On Error Resume Next
  m_bDisableHit = True
  m_GeCtrl.GrabHandlesEnabled = False
  
  Set uItems = m_CustDwg.UDIItems
  Set Items = uItems.Items
  ReDim Removed(Items.count) As Long

  For i = 1 To Items.count
    bHadItems = True
    Set objUDI = Items.Item(i)
    nSIDID = objUDI.SIDID
      ' if old not 0, assume that have not been synced ever
      ' (ie: a drawing was copied and this is first time its opened)
    nIDOld = objUDI.OldSIDID
    If nIDOld <> 0 Then
      m_GeCtrl.ChangeUserID nIDOld, nSIDID, False
      bSaveRequired = True
    End If
    '
    GeID = m_GeCtrl.AttachVariantByUserID(objUDI, nSIDID, False)  ' BOOL MultipleOnAttach
    If GeID <> 0 Then
      objUDI.GeID = GeID
    Else
      Removed(nRemoved) = i
      nRemoved = nRemoved + 1
    End If
  Next i
  
  If nRemoved > 0 Then
    For i = nRemoved - 1 To 0 Step -1
      Items.Remove Removed(i)
    Next i
  End If
  '
  m_GeCtrl.GrabHandlesEnabled = True
  m_bDisableHit = False
End Sub


'------------------------------
Private Sub CreateUDIOnInsertShape()
  'create UDI based on a Shpe being inserted
  Dim nSIDID As Long
  Dim objUDI As UserDefinedItem
  Dim strFolder As String, strShape As String
  Dim GeID As Long
  Dim nGeType As Integer
  Dim strPathFolder As String
  Dim pos As Long
  Dim pDef As UserDefinedItemDef
  Dim strName As String
  
  On Error Resume Next
  If m_GeCtrl.SelNumberOfObjects = 1 Then
    GeID = m_GeCtrl.GetLastSelObject
    m_GeCtrl.ShapeSetCurrent GeID ' move into Shape selector
    nGeType = m_GeCtrl.ObjectType
    
    ' only if shape or SmartShape (usergroup)
    If nGeType = EGeObjType.Shape Or nGeType = EGeObjType.UserGroup Then
        ' get folder and shape name.
        strShape = m_GeCtrl.ShapeName
        strPathFolder = m_GeCtrl.ShapePath     ' Returns File.ext!Folder
        pos = InStr(strPathFolder, "!")
        strFolder = Right(strPathFolder, Len(strPathFolder) - pos)
      
        ' create obj and move into selection
        Set objUDI = m_CustDwg.UDIItems.AddNewItem
        m_collSel.Add objUDI
        
        ' see if UDIDefMgr has object with assignment
        Set pDef = m_UDIDefMgr.GetUDIDefbyFolderAndShape(strFolder, strShape)
        If Not pDef Is Nothing Then pDef.initUDI objUDI
      
        objUDI.ObjectName = strShape
        objUDI.m_strFolder = strFolder
        objUDI.m_strShape = strShape
        nSIDID = objUDI.SIDID
        objUDI.GeID = GeID
        m_GeCtrl.ObjectUserID = nSIDID    ' assign new userID
        m_GeCtrl.ShapeSetVariant objUDI   ' hook object to shape
        
    End If
    m_GeCtrl.ShapeSetCurrent 0    ' reset selector
  End If


End Sub


'===============================================================
' Feedback
'===============================================================
''===========================================================================
' Ge Connection
''===========================================================================
'--------------------------
Public Sub EnumConnections()
  ' enumerate all
  ' this will cause a series of ConnectionChanged events to fire.
  ' use the Flag m_bEnumConnections to determine that we are doing this operation
  On Error Resume Next
  m_bEnumConnections = True
  m_GeCtrl.EnumConnectionLines
  m_bEnumConnections = False
  
End Sub
'--------------------------
Public Sub ConnectionChanged(ByVal Action As Integer, _
        ByVal IDLine As Long, _
        ByVal IDA As Long, ByVal VarA As Variant, _
        ByVal NameA As String, ByVal TypeA As Integer, ByVal StsA As Integer, _
        ByVal IDB As Long, ByVal VarB As Variant, _
        ByVal NameB As String, ByVal TypeB As Integer, ByVal StsB As Integer)

  ' notification that connection has changed or are in an Enumeration

''''
  Dim ObjA As Object, ObjB As Object
  Dim strAction As String, strStsA As String, strStsB As String
  Dim strMsg As String
  
  On Error Resume Next
  If m_bEnumConnections Then
    Set ObjA = VarA
    Set ObjB = VarB
    
    Select Case Action
      Case 1  ' connected
        strAction = "Connected"
      Case 2  ' broken (not connected)
        strAction = "Broken"
      Case Else
        strAction = Action
    End Select
    ''
    Select Case StsA
      Case 1  ' just made
        strStsA = "Made"
      Case 2  ' just broken (vertex moved off Connector, or Connector deleted)
        strStsA = "Broken"
      Case Else
        strStsA = StsA
    End Select
    ''
    Select Case StsB
      Case 1  ' just made
        strStsB = "Made"
      Case 2  ' just broken (vertex moved off Connector, or Connector deleted)
        strStsB = "Broken"
      Case Else
        strStsB = StsB
    End Select
    
    strMsg = strAction & "," & IDLine & "," & vbCr & vbTab _
      & IDA & "," & TypeName(ObjA) & "," & NameA & "," & TypeA & "," & strStsA & vbCr & vbTab _
      & IDB & "," & TypeName(ObjB) & "," & NameB & "," & TypeB & "," & strStsB
  
    Debug.Print strMsg
  
  End If
''''

End Sub

'------------------------------
Public Sub OnMouseMove(ByVal X As Double, ByVal y As Double)
  
  On Error Resume Next
  
'  m_AppCtrl.KeyPreview = True
'  m_GeCtrl.KeyPreview = True
  m_dGeX = X
  m_dGeY = y
'  If m_bInsertingItem Then
'    EndInsertItem X, Y
'  End If
End Sub
'------------------------------
Public Sub ObjectHit(ByVal GeID As Long, ByVal VarValid As Boolean, varObject As Variant)
  ' object got hit by the user
  Dim varTmp As Object
  
  On Error Resume Next
  If (m_bLoadingDwg Or m_bDisableHit) Then Exit Sub
    
    ' refresh to stsbar
  If VarValid Then
    Set varTmp = varObject      ' grab the actual object from the variant
    UpdateSelObjToStatusBar varTmp
  Else
    m_AppCtrl.SetObjectStatusText ""
  End If
End Sub
'------------------------------
Private Sub UpdateSelObjToStatusBar(obj As Object)
  Dim strMsg As String
  Dim strItem As String
  Dim nItemID As Long
  Dim strName As String
  Dim objTmp As UserDefinedItem
  
  On Error Resume Next
  If Not obj Is Nothing Then
    If TypeOf obj Is UserDefinedItem Then
      Set objTmp = obj
      strMsg = objTmp.ClassName & " | " & objTmp.ObjectName & "[" & objTmp.SIDID & "]"
      m_AppCtrl.SetObjectStatusText strMsg
    End If
  Else
    m_AppCtrl.SetObjectStatusText ""
  End If
End Sub

'-----------------------
Public Sub NotifyHaveObjectWithUserID(ByVal UserID As Long, ByVal nType As Integer, ByVal ParentUserID As Long)
  ' callback on EnumObjects
  ' if deleting, deal with it
  Dim objUDI As UserDefinedItem
  
  On Error Resume Next
  If m_bEnumGeObjects Then
    Set objUDI = m_CustDwg.Find(UserID)
    If Not objUDI Is Nothing Then m_collDelete.Add objUDI
  End If
  
'  Dim strMsg As String
'  strMsg = "UserID:" & UserID & _
'              " ,type: " & nType & _
'              " ,ParentUserID:" & ParentUserID
'  Debug.Print strMsg
End Sub

'===============================================================
' Copy/Delete Handling
'===============================================================
'------------------------------
Public Property Get CanDelete() As Boolean
  If m_GeCtrl.SelNumberOfObjects > 0 Then
    CanDelete = True
  Else
    CanDelete = False
  End If
End Property
'------------------------------
Public Function Delete()
  If HasSelection Then
    m_bDisableHit = True
    AddItemsToDelete
    RemoveFromDrawing m_collDelete
    m_GeCtrl.Delete
'    DeleteItems
    m_bDisableHit = False
    SelChanged
  Else
    m_GeCtrl.Delete
  End If
End Function

'------------------------------
Private Sub AddItemsToDelete()
  ' add all in collsel to delete and step into members
  Dim objUDI As UserDefinedItem
  Dim i As Long
  Dim GeID As Long
  Dim j As Long
  Dim objTmp As UserDefinedItem
  Dim bGotIt As Boolean
  
  On Error Resume Next
  ResetSelArray m_collDelete
  m_bEnumGeObjects = True
  For i = 1 To m_collSel.count
    Set objUDI = m_collSel.Item(i)
    GeID = objUDI.GeID
    If m_GeCtrl.ShapeSetCurrent(GeID) Then
      ' have Ge walk all objects in group and send em
      m_GeCtrl.ShapeEnumObjects
    End If
    ' ensure the root object got into the selection
    bGotIt = False
    For j = 1 To m_collDelete.count
      Set objTmp = m_collDelete.Item(j)
      If objTmp.SIDID = objUDI.SIDID Then
        bGotIt = True
        Exit For
      End If
    Next j
    If Not bGotIt Then m_collDelete.Add objUDI
  
  Next i
  '
  m_GeCtrl.ShapeSetCurrent 0    ' reset
  m_bEnumGeObjects = False

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub
'------------------------------
Private Sub DeleteItems()
  ' delete em and clear collDelete
  Dim objUDI As UserDefinedItem
  Dim i As Long
  
  On Error Resume Next
  If Not m_collDelete Is Nothing Then
    For i = 1 To m_collDelete.count
      Set objUDI = m_collDelete.Item(1)
      objUDI.DestroyAll
      m_collDelete.Remove 1
    Next i
    '
    ResetSelArray m_collDelete
  End If
  
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub

'------------------------------
Private Sub SelCopy()
  ' copy all in selection
  ' first copy em, then attach em to Ge
  Dim objUDI As UserDefinedItem
  Dim objnew As UserDefinedItem
  Dim i As Long
  Dim nID As Long, nIDNew As Long
  Dim bRet As Boolean
  Dim GeID As Long
  Dim collNew As Collection
  
  On Error Resume Next
  Set collNew = New Collection
  
  ' copy em and add to drawing
  For i = 1 To m_collSel.count
    Set objUDI = m_collSel.Item(i)
    Set objnew = m_CustDwg.CopyItem(objUDI)
    If Not objnew Is Nothing Then
      collNew.Add objnew
      nID = objUDI.SIDID
      nIDNew = objnew.SIDID
        ' ChangeUserID will find latest in list and set its ID
      bRet = m_GeCtrl.ChangeUserID(nID, nIDNew, False)
      If bRet Then
        GeID = m_GeCtrl.AttachVariantByUserID(objnew, nIDNew, False) ' False = not Multiple
        If GeID <> 0 Then objnew.GeID = GeID
      End If
    End If
  Next i
  '
  'swap sellist And cleanup
  ResetSelArray m_collSel
  For i = 1 To collNew.count
    m_collSel.Add collNew.Item(i)
  Next i
  
  Set collNew = Nothing
  
  ''
  If m_collSel.count = 1 Then
    If Not m_UDIPropViewer Is Nothing Then
      Set m_UDIPropViewer.UserDefinedItem = m_collSel.Item(1)
    End If
  End If



#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub

'------------------------------
Public Sub Undo()
  On Error Resume Next
  m_bUndoing = True
  m_GeCtrl.Undo
End Sub
'------------------------------
Public Sub UndoOccurred(ByVal eAction As Integer)
'  // Enumerations - Actions
'    enum {
'      ACTION_NONE       = 0,       // 0
'      ACTION_DELETE     = 1,       // CG objects being deleted
'      ACTION_MOVE       = 2        // CG objects being moved
'    };
  
  On Error Resume Next
  If m_bUndoing Then
    
    m_bUndoing = False
    DeleteItems     ' clear current
    SelChanged
    If eAction <> 1 Then Exit Sub
    SelCopy
  End If
  
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub


'===============================================================
' ClipBoard Handling
'===============================================================
'-----------------------
Public Sub PasteMacro()
  m_bPastingMacro = True
  m_GeCtrl.Paste
End Sub
'-----------------------
Public Sub Paste()
  m_bPasting = True
  m_GeCtrl.Paste
End Sub
'-----------------------
Public Sub EndPaste()
  ' paste operation is complete. Copy and Attach
  '' Paste = true, Ge pastes and sends SelChange when operation is complet
  ' Ge sends actionCancelled if aborted
  If m_bPasting Then
    GetSelectionOnPaste
    m_bPasting = False
    SelCopy
    SelChanged
  Else
    ' assume new shape being inserted. Try and create UserObject from it
    CreateUDIOnInsertShape
  End If
End Sub
'-----------------------
Public Sub Cut()
  CopyToClipBoard m_collSel
  RemoveFromDrawing m_collSel
  m_bCutting = True
  m_GeCtrl.Cut
End Sub
'-----------------------
Public Sub Copy()
  CopyToClipBoard m_collSel
  m_GeCtrl.Copy
End Sub

'------------------------------
Public Function GlobalFindOnCB(nID As Long) As UserDefinedItem
  ' callback from global
  ' find the object on the Clipboard with the id
  Dim i As Long
  Dim objUDI As UserDefinedItem
  
  On Error Resume Next
  If Not m_collCB Is Nothing Then
    For i = 1 To m_collCB.count
      Set objUDI = m_collCB.Item(i)
      If objUDI.SIDID = nID Then
        Set GlobalFindOnCB = objUDI
        Exit Function
      End If
    Next i
  End If
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function
'------------------------------
Private Function FindOnCB(nID As Long) As UserDefinedItem
  ' find the object on the Clipboard with the id
  Dim i As Long
  Dim objUDI As UserDefinedItem
  
  On Error Resume Next
  If Not m_collCB Is Nothing Then
    For i = 1 To m_collCB.count
      Set objUDI = m_collCB.Item(i)
      If objUDI.SIDID = nID Then
        Set FindOnCB = objUDI
        Exit Function
      End If
    Next i
'    ' try and get from global
'    Set FindOnCB = gFindOnCB(nID)
  
  End If
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Public Sub ClearClipBoard()
  ' clear and destroy array of CB objects
  Dim i As Long
  Dim objUDI As UserDefinedItem
  
  On Error Resume Next
  If Not m_collCB Is Nothing Then
    For i = 1 To m_collCB.count
      Set objUDI = m_collCB.Item(1)
      objUDI.DestroyAll
      m_collCB.Remove 1
    Next i
  End If

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub
'------------------------------
Private Sub CopyToClipBoard(collSel As Collection)
  ' clearCB and Copy coll
  Dim i As Long
  Dim objUDI As UserDefinedItem
  Dim objnew As UserDefinedItem
  
  On Error Resume Next
  If Not m_collCB Is Nothing Then
'    gClearClipBoard CLng(m_AppCtrl.tag) ' clear all except mine
    ClearClipBoard
    For i = 1 To collSel.count
      Set objUDI = collSel.Item(i)
      If objUDI.Copy(objnew) Then
        m_collCB.Add objnew
        ' set ID to be same so can find later
        objnew.SIDID = objUDI.SIDID
      End If
    Next i
  End If

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub
'------------------------------
Private Sub RemoveFromDrawing(collSel As Collection)
  ' remove coll from Drawing
  Dim i As Long
  Dim objUDI As UserDefinedItem
  Dim nID As Long
  
  On Error Resume Next
  For i = 1 To collSel.count
    Set objUDI = collSel.Item(i)
    nID = objUDI.SIDID
    m_CustDwg.RemoveItem nID
  Next i

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub

'===============================================================
' Selection Handling
'===============================================================
'------------------------------
Public Function GetItemShapeName(objUDI As UserDefinedItem) As String
  ' get the shape name of the item
  Dim GeID As Long
  Dim nGeType As Integer
  On Error Resume Next
  If Not objUDI Is Nothing Then
    ' set UserID
    GeID = objUDI.GeID
    If m_GeCtrl.ShapeSetCurrent(GeID) Then
      nGeType = m_GeCtrl.ObjectType
      If nGeType = EGeObjType.UserGroup Or nGeType = EGeObjType.Shape Then
        GetItemShapeName = m_GeCtrl.ShapeName
      End If
    End If
    m_GeCtrl.ShapeSetCurrent 0      ' reset selector
  End If
End Function

'------------------------------
Public Property Get SelCount() As Long
  SelCount = m_collSel.count
End Property
'------------------------------
Public Property Get FirstSelItem() As UserDefinedItem
  On Error Resume Next
  If m_collSel.count > 0 Then Set FirstSelItem = m_collSel.Item(1)
End Property
'------------------------------
Public Property Get NextSelItem(Index As Long) As UserDefinedItem
  On Error Resume Next
  If m_collSel.count > 0 And Index > 0 And (Index <= m_collSel.count) Then
    Set NextSelItem = m_collSel.Item(Index)
  End If
End Property
'------------------------------
'-----------------------
Public Sub EndSelectScale(ByVal bExtruding As Boolean)
  ' this event will be fired at the end of a Scale operation
  ' or when a UserGroup has been Extruded
'  On Error Resume Next
'  Dim i As Long
'  Dim nNum As Integer
  
'  Dim objUDI As UserDefinedItem
'  If bExtruding Then
'    For i = 1 To m_collSel.Count
'      Set objUDI = m_collSel.Item(i)
'      nNum = GetItemNumArrayElements(objUDI)
'    Next i
'  End If

End Sub

'------------------------------
Public Function SetMoveCopyDelta(ByVal dX As Double, ByVal dy As Double)
  ' delta for Move/moveCopy operations
  m_DXMove = dX
  m_DYMove = dy
End Function

'------------------------------
Public Sub SelChanged()
  ' Selection has changed in GeCtrl (by the user or by the program)
  Dim bRet As Boolean
  Dim obj As Object
  Dim objUDI As UserDefinedItem
  Dim GeID As Long
  
  
  On Error Resume Next
  If (m_bLoadingDwg Or m_bDoingSelAdd Or m_bInsertingItem) Then Exit Sub
    
  '
  If m_bCutting Then
    m_bCutting = False
'    DeleteItems
  End If

'    ' if in Move mode, do it
'  If m_bDoSelMove Or m_bDoSelCopy Then
'    Exit Function
'  End If
  
  ResetSelArray m_collDelete
  ResetSelArray m_collSel
    
  If Not m_UDIPropViewer Is Nothing Then Set m_UDIPropViewer.UserDefinedItem = Nothing
  
  '' if something selected, deal with it.
  If m_GeCtrl.SelNumberOfObjects > 0 Then
    GetSelection m_collSel
  End If
  
  ''
  ' if selected a SmartShape, could have only 1 GeObject selected,
  ' but have many members. In this case, only deal with the
  ' top level selected item
  If m_GeCtrl.SelNumberOfObjects = 1 Then
    If m_collSel.count > 1 Then
      If Not m_UDIPropViewer Is Nothing Then
        GeID = m_GeCtrl.GetFirstSelObject
        Set objUDI = m_collSel.Item(1)
          ' it must also be the UDI and not some arbitraty
          ' SmartShape holding it. The SmartShape could be
          ' different form the UDIs
        If GeID = objUDI.GeID Then
'          GetGeUserFieldsForUDI objUDI
          Set m_UDIPropViewer.UserDefinedItem = objUDI
          UpdateSelObjToStatusBar objUDI
          Exit Sub
        Else
'          m_AppCtrl.SetObjectStatusText ""
        End If
      End If
    End If
  End If
  ''
  If m_collSel.count = 1 Then
    If Not m_UDIPropViewer Is Nothing Then
      Set objUDI = m_collSel.Item(1)
'      GetGeUserFieldsForUDI objUDI
      Set m_UDIPropViewer.UserDefinedItem = objUDI
    End If
  End If
  ''
  If m_collSel.count = 1 Then
    UpdateSelObjToStatusBar m_collSel.Item(1)
'  ElseIf m_collSel.Count > 1 Then
'    m_AppCtrl.SetObjectStatusText m_collSel.Count & " Items selected."
'  Else
'    m_AppCtrl.SetObjectStatusText ""
  End If
  '
End Sub

'------------------------------
Public Property Get CanEditItems(ByVal bMultiple As Boolean) As Boolean
  '
  On Error Resume Next
  If Not bMultiple Then
    If m_collSel.count = 1 Then CanEditItems = True
  Else
    If m_collSel.count > 0 Then CanEditItems = True
  End If
End Property
'------------------------------
Public Sub DoItemProps()
  Dim objUDI As UserDefinedItem
  On Error Resume Next
  If m_collSel.count > 0 Then
    If Not m_UDIPropViewer Is Nothing Then
      Set objUDI = m_collSel.Item(1)
'      GetGeUserFieldsForUDI objUDI
      Set m_UDIPropViewer.UserDefinedItem = objUDI
      m_UDIPropViewer.ShowItemProps
    End If
  End If
End Sub

'------------------------------
Public Function BeginSelectCopy() As Boolean
  ' at this point, the object(s) IMAGES (outlines)
  ' have been moved to new loc'n on screen. Note that we do not have their new
  ' extents yet as the actual objects have not yet been moved there.
  ' Ensure that is OK to do it!
  ' NOTE: SetMoveCopyDelta has already been fired from Ge before we get here
  If Not HasSelection Then
    m_bDoSelCopy = False
  Else
    m_bDoSelCopy = True
  End If
  BeginSelectCopy = True
End Function

'------------------------------
Public Sub EndSelectCopy()
  ' operation is totally complete
  If m_bDoSelCopy Then SelCopy
  m_bDoSelCopy = False
End Sub

'------------------------------
Public Function DoActionCancelled()
  ' A notification that an Action (eg: Move or SelMove) was cancelled.
  ' This is sent after the GeCtrl has had time to remove the outlines of the objects
  ' being moved/copied and to refresh the screen.
  
  m_bDoSelCopy = False
  m_bPasting = False
  m_bPastingMacro = False
  
End Function


'===============================================================
' Selection Management
'===============================================================
'------------------------------
Public Property Get HasSelection() As Boolean
  ' just determine if have any project objects in selection
'  If IsCabling Then
'    HasSelection = m_CableTool.HasSelection
'    Exit Property
'  End If
  If m_collSel.count = 0 Then
    HasSelection = False
  Else
    HasSelection = True
  End If
End Property
'------------------------------
Public Function SelRemoveAll()
  ' clear selection
  m_GeCtrl.SelRemoveAll
  ResetSelArray m_collSel
End Function

'------------------------------
Private Sub ResetSelArray(coll As Collection)
  ' clear array of selected objects
    ' Remove the first object each time through the loop until there
    ' are no objects left in the collection.
  Dim i As Integer
  For i = 1 To coll.count
    coll.Remove 1
  Next i
End Sub

'-----------------------
Private Sub GetSelectionOnPaste()
  ' walk thru GeSelection, enum those with userIDs, add UDIs that match
  ' those pasted
  Dim objUDI As UserDefinedItem
  Dim nID As Long
  Dim GeID As Long
  Dim nGeType As Integer
  
  On Error Resume Next
  ResetSelArray m_collDelete
  ResetSelArray m_collSel
  '
  ' NOTE: DO NOT use SelRemove while stepping into groups
  m_GeCtrl.SelStepIntoGroups = True
  
  GeID = m_GeCtrl.GetFirstSelObject
  ' loop through all objects
  Do While GeID <> 0
    m_GeCtrl.CurrentPropertyID = GeID  ' move into selector
    nGeType = m_GeCtrl.ObjectType
 
'    If nGeType = EGeObjType.UserGroup Then
    If nGeType = EGeObjType.UserGroup Or nGeType = EGeObjType.Shape Then
      '
      If m_GeCtrl.ShapeSetCurrent(GeID) Then
        nID = m_GeCtrl.ShapeUserID
        If nID <> 0 Then
          Set objUDI = FindOnCB(nID)    'm_CustDwg.Find(nID)
          If Not objUDI Is Nothing Then m_collSel.Add objUDI
        End If
      End If
      '
    End If
    '
    GeID = m_GeCtrl.GetNextSelObject(GeID)
  Loop
  '' reset selector when done !!
  m_GeCtrl.SelStepIntoGroups = False
  m_GeCtrl.CurrentPropertyID = 0
  m_GeCtrl.ShapeSetCurrent 0
  m_GeCtrl.ShapeSetCurrentField 0
End Sub

'------------------------------
Private Function GetSelection(coll As Collection) As Boolean
  ' get the selection of ProjObjs based on selection in the GeCtrl
  Dim aVar As Variant
  Dim iLow As Integer
  Dim iHigh As Integer
  Dim i As Integer
  
  On Error Resume Next
  m_GeCtrl.SelGetObjectVariants aVar
  iLow = LBound(aVar)
  iHigh = UBound(aVar)
    ' if error, then probably nothing in array !
  If err = 0 Then
    For i = iLow To iHigh
      If Not IsEmpty(aVar(i)) Then
        coll.Add aVar(i)
      End If
    Next i
  End If
  GetSelection = True
    
End Function

'Private Function GetUMLProjName() As String
'  Dim uBnd As Integer
'  Dim lBnd As Integer
'  Dim i As Integer
'  Dim strLibPath As String
'  Dim aLibraries As Variant
'  Dim strUMLExt As String
'
'  On Error Resume Next
'  If m_GeCtrl Is Nothing Then Exit Function
'
'  GetUMLProjName = ""
'  m_GeCtrl.GetAttachedLibraries aLibraries
'  If Err <> 0 Then
'    ' nothing there
'    Err = 0
'    Exit Function
'  End If
'
'  uBnd = UBound(aLibraries)
'  lBnd = LBound(aLibraries)
'  If Err <> 0 Or uBnd = -1 Then
'    Err = 0     ' nothing there
'    Exit Function
'  End If
  
  ' get first library in with appropriate extension
'  strUMLExt = getUMLExt()
'  For i = 0 To uBnd
'    strLibPath = aLibraries(i)
'    'See if correct extension
'    If InStr(1, strLibPath, strUMLExt) > 0 Then
'        GetUMLProjName = strLibPath
'        Exit For
'    End If
'  Next
'End Function

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
        gMsgWnd.LogMessage strMsg
      #End If
    VERIFY_ERR = False
  End If
End Function



'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' ARCHIVE
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
#If 0 Then
'------------------------------
Private Function CreateUDIFromGe(GeID As Long, GeUserIDOld As Long, _
                  collUpdate As Collection) As Boolean
  ' given GeID, and assuming it is in selector, create a UDI from it and add
  Dim objUDI As UserDefinedItem
  Dim objDef As UserDefinedItemDef
  Dim nSIDID As Long
  Dim ItemID As Long
  Dim strItemID As String
  Dim bGotItemID As Boolean
  Dim strFullNomen As String
  Dim bUpdate As Boolean
  
  Dim nFlds As Long
  Dim iFld As Long
  Dim strFldName As String, strFldValue As String
  
  On Error Resume Next
  
  ' get fields, lookiing for ItemID
  nFlds = m_GeCtrl.ShapeFieldCount
  For iFld = 0 To nFlds - 1
    If m_GeCtrl.ShapeSetCurrentField(iFld) Then
      If m_GeCtrl.ShapeGetFieldNameValue(strFldName, strFldValue) Then
        '' match field to relevant info
        If UCase(strFldName) = "FULLNOMENCLATURE" Then
          strFullNomen = strFldValue
        ''
        ElseIf strFldName = "ItemID" Then
            ' look for 1607B,...
          If Len(strFldValue) > 0 Then
            If Not IsNumeric(strFldValue) Then
              strItemID = strFldValue
            Else
              ' number
              bGotItemID = True
              ItemID = strFldValue
            End If
          End If
          If bGotItemID Then Exit For
        End If
        ''
      End If
    End If
  Next iFld
  
  If Not bGotItemID And Len(strItemID) > 0 Then
    ' get actual ItemID based on FullNomenclature if it exists
    If Len(strFullNomen) > 0 Then
      ItemID = Left(strItemID, Len(strItemID) - 1)  ' strip trailing Alpha
      If ItemID > 0 And err = 0 Then
        If Not GetActualItemIDbyFullNomen(ItemID, strFullNomen) Then
          Exit Function
        Else
          bUpdate = True
        End If
      Else
        If err <> 0 Then err = 0
        Exit Function
      End If
    End If
  ElseIf Not bGotItemID Then
     Exit Function
  End If

  
  Set objDef = m_UDIDefMgr.GetUDIDefbyItemID(ItemID)
  ' not there. Create one on the fly
  If objDef Is Nothing Then
    If CreateUDIDefOnTheFly(ItemID) Then
      Set objDef = m_UDIDefMgr.GetUDIDefbyItemID(ItemID)
    End If
  End If
  '
  If Not objDef Is Nothing Then
    Set objUDI = m_CustDwg.InsertItem(objDef)
    If Not objUDI Is Nothing Then
        ' change user id
      nSIDID = objUDI.SIDID
      m_GeCtrl.ChangeUserID GeUserIDOld, nSIDID, False
        ' attach it
      m_GeCtrl.ShapeSetVariant objUDI
      objUDI.GeID = GeID
        ' fill in UDI props from GeShape
      UpdateUDIFromGeShape objUDI
      CreateUDIFromGe = True
      If bUpdate Then collUpdate.Add objUDI
    End If
  End If

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function


'------------------------------
Private Sub UpdateUDIFromGeShape(objUDI As UserDefinedItem)
  ' get what we can from Ge as fill in data to udi
  Dim nFlds As Long
  Dim iFld As Long
  Dim strFldName As String, strFldValue As String
  Dim strNomen As String
  Dim strItemID As String
  Dim nCableID As Long
  Dim Cable As Cable
  
  On Error Resume Next
    
  nCableID = objUDI.CableSIDID
  If nCableID > 0 Then
    Set Cable = m_CustDwg.GetCableBySIDID(nCableID)
  End If
    
  nFlds = m_GeCtrl.ShapeFieldCount
  For iFld = 0 To nFlds - 1
    If m_GeCtrl.ShapeSetCurrentField(iFld) Then
      If m_GeCtrl.ShapeGetFieldNameValue(strFldName, strFldValue) Then
        '
        Select Case UCase(strFldName)
'          Case "NOMENCLATURE"
'            strFldValue = strNomen
          Case "FULLNOMENCLATURE"
            objUDI.Nomenclature = strFldValue
          Case "QUANTITY"
            If Len(strFldValue) = 0 Then
              objUDI.Quantity = 1
            ElseIf UCase(Left(strFldValue, 1)) = "X" Then
              strFldValue = Right(strFldValue, Len(strFldValue) - 1)
              objUDI.Quantity = CLng(strFldValue)
              If err <> 0 Then err = 0
            End If
          Case "CABLELENGTH"
            If Not Cable Is Nothing Then
              If Len(strFldValue) > 0 Then
                Cable.length = CSng(strFldValue)
                If err <> 0 Then err = 0
              End If
            End If
          Case "CABLEUNITS"
            If Not Cable Is Nothing Then
              If strFldValue = "M" Then
                Cable.IsMetric = True
              Else
                Cable.IsMetric = False
              End If
            End If
            
          Case "ITEMID"
            ' do nothing. It should have been fixed before we got here
            
          Case Else
            objUDI.PropertyValue(strFldName) = strFldValue
            
        End Select
      End If
    End If
  Next iFld

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub



'------------------------------
Private Sub GetGeUserFieldsForUDI(objUDI As UserDefinedItem)
  ' get what we can from Ge that is not standard info
  Dim GeID As Long
  Dim nFlds As Long
  Dim iFld As Long
  Dim strFldName As String, strFldValue As String
  
  On Error Resume Next
  GeID = objUDI.GeID
  If m_GeCtrl.ShapeSetCurrent(GeID) Then
    nFlds = m_GeCtrl.ShapeFieldCount
    For iFld = 0 To nFlds - 1
      If m_GeCtrl.ShapeSetCurrentField(iFld) Then
        If m_GeCtrl.ShapeGetFieldNameValue(strFldName, strFldValue) Then
          '
          Select Case UCase(strFldName)
            Case "ITEMID"
            Case "NOMENCLATURE"
            Case "FULLNOMENCLATURE"
            Case "QUANTITY"
            Case "CABLELENGTH"
            Case "CABLEUNITS"
              
            Case Else
              objUDI.PropertyValue(strFldName) = strFldValue
              
          End Select
        End If
      End If
    Next iFld
    m_GeCtrl.CurrentPropertyID = 0  ' reset selector
  End If
  m_GeCtrl.ShapeSetCurrent 0      ' reset selector

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub




#End If
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' ARCHIVE
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

