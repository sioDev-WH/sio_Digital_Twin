Attribute VB_Name = "mShapeLibHelper"
Option Explicit

Private Const LEFT_POS = 1
Private Const BOTTOM_POS = 1
Private Const RIGHT_POS = 2
Private Const TOP_POS = 2
Private Const MIN_FACE_SIZE = 0.3
Private Const SHAPELABEL_HEIGHT = 0.2
Private Const CONNECTOR_DISTANCE = 0.5
Private Const LABEL_DISTANCE = 0.15
Private Const FONT_HEIGHT = 0.13
Private Const PEN_BLACK = 185
Private Const SHAPEICON_USERID = 777777
Private Const SHAPENAME_USERID = 999999
Private Const SHAPERECTANGLE_USERID = 888888
Private Const VERTICAL_FONT_ORIENTATION = 4.712389
Private Const RECTANGLE_TOLERANCE = 0.02

'These can be found in mGEConst
Private Const GE_POLYLINE = 7
Private Const GE_RECTANGLE = 9
Private Const GE_GROUP = 11
Private Const GE_TEXT = 12
Private Const GE_TERXTFIELD = 14
Private Const GE_CONNECTOR = 22

'Keep track of the main and secondary CG control.  If possible, we don't want to manipulate shapes in the main control.
Private GeCtrlMain As CG        'Reference to the main CG control
Private GeCtrl As CG            'Reference to a secondary CG control (ie. in Block Wizard dialog)
Private m_GeCtrl As CG          'Current CG control to be used

Private m_UserID As Long
Private m_GeLbrMgr As GeLibraryMgr

Public Sub SetHelperModuleSecondaryGeCtrl(oGeCtrl As CG)
    Set GeCtrl = oGeCtrl
End Sub

Public Sub SetHelperModuleMainGeCtrl(oGeCtrl As CG)
    Set GeCtrlMain = oGeCtrl
End Sub

Private Function SetGeCtrl() As Boolean
    SetGeCtrl = True
    If Not GeCtrl Is Nothing Then
        Set m_GeCtrl = GeCtrl
    ElseIf Not GeCtrlMain Is Nothing Then
        Set m_GeCtrl = GeCtrlMain
    Else
        Set m_GeCtrl = Nothing
        SetGeCtrl = False
    End If
End Function


Public Function RenameShape(cgDetails As cgLibraryShapeDetails, m_GeLbrMgr As GeLibraryMgr) As Boolean
    Dim rst As Recordset
    Dim strSQL As String
    Dim GeID As Long, GeIDRemove As Long, GeIDRectangle As Long
    Dim UserId As Long
    Dim bAltered As Boolean
    Dim strLibAndFolder As String
    Dim fInsertionPointX As Single, fInsertionPointY As Single
    Dim fBottomPos As Single, fTopPos As Single
    Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
    Dim oDetails As cgShapeComponentDetails
    Dim collConns As Collection
    Dim collId As Collection
    Dim bCanExplode As Boolean
    
    On Error GoTo Error_Handler
    RenameShape = False
    GeIDRemove = -1
    GeIDRectangle = -1
        
    If m_GeLbrMgr Is Nothing Then Exit Function
    If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
    If Not SetGeCtrl() Then Exit Function
    If cgDetails.m_UDIDefOriginal Is Nothing Then
        gMsgWnd.LogMessage "Failed to Rename Shape " & cgDetails.strShapeName & ".  Can not retrieve shape definition."
        Exit Function
    End If
      
    strSQL = "SELECT * "
    strSQL = strSQL & "From GeTblShape Where ShapeName = '" & cgDetails.strShapeName & "' and FolderID =" & cgDetails.lFolderID
    
    Set rst = m_GeLbrMgr.LibDB.OpenRecordset(strSQL, dbOpenDynaset)
    With rst
        If .RecordCount = 1 Then
          .Edit
          !ShapeName = cgDetails.strShapeNameNew
          .Update
          RenameShape = True
        End If
        .Close
    End With
    Set rst = Nothing
    
    bAltered = False
    
    Set collId = New Collection
    Set collConns = New Collection
    m_GeCtrl.GrabHandlesEnabled = False
    m_GeCtrl.RedrawEnabled = False
    m_GeCtrl.SelRemoveAll
        
    m_GeCtrl.UsePictureColor = True
    GeID = m_GeCtrl.CreateShape(m_GeLbrMgr.LibrayName, cgDetails.m_UDIDefOriginal.GeFolder, cgDetails.strShapeName, 1, 1)
    If GeID <= 0 Then Exit Function
    
    m_GeCtrl.CurrentPropertyID = GeID
    bCanExplode = m_GeCtrl.CanExplodeShape
    m_GeCtrl.CurrentPropertyID = 0
    
    m_GeCtrl.SelRemoveAll
    
    'Enumerate all the connectors and determine their face and order based on their position.
    EnumAllShapeObjects GeID, GeIDRectangle, collConns
    
    Dim i As Long
    For i = 1 To collConns.count
        Set oDetails = collConns(i)
        If oDetails.UserId = SHAPENAME_USERID Then
            GeIDRemove = oDetails.GeID
        Else
            collId.Add oDetails.GeID
        End If
    Next i
       
    If GeIDRemove > 0 Then
        'Create New Name Field and add it.
        m_GeCtrl.CurrentPropertyID = GeIDRectangle
        m_GeCtrl.GetExtents fLeft, fBottom, fRight, fTop
        m_GeCtrl.CurrentPropertyID = 0
                        
        SetFontDetail FONT_HEIGHT, 1, 0
        fTopPos = fTop - (Abs(fTop - fBottom - SHAPELABEL_HEIGHT) / 2)
        fBottomPos = fBottom + (Abs(fTop - fBottom - SHAPELABEL_HEIGHT) / 2)
        GeID = m_GeCtrl.CreateTextField(fLeft + 0.05, fBottomPos, fRight - 0.05, fTopPos, cgDetails.strShapeNameNew, cgDetails.strShapeNameNew) 'fltLeft, fltBottom, fltRight, fltTop
        If GeID >= 0 Then
            SetUserIDForObject GeID, SHAPENAME_USERID
            m_GeCtrl.SelAdd GeID
            bAltered = True
        End If
    End If
    
    If bAltered Then    'Recreate the shape
        DeleteShape cgDetails, m_GeLbrMgr
        
        AddMyObjectsToCurrentSelection collId
        m_GeCtrl.SelRemove GeIDRemove
        strLibAndFolder = m_GeLbrMgr.LibrayName & "!" & cgDetails.m_UDIDefOriginal.GeFolder
        fInsertionPointX = fLeft + Abs(fRight - fLeft) / 2
        fInsertionPointY = fBottom + Abs(fTop - fBottom) / 2
        If bCanExplode Then
            If Not CreateShapeDef(strLibAndFolder, cgDetails.strShapeNameNew, fInsertionPointX, fInsertionPointY) Then
                GoTo CleanUp_GeCtrl
            End If
        Else
            If Not CreateSmartShapeDef(strLibAndFolder, cgDetails.strShapeNameNew, fInsertionPointX, fInsertionPointY) Then
                GoTo CleanUp_GeCtrl
            End If
        End If
        If GeIDRemove > 0 Then
            m_GeCtrl.SelRemoveAll
            m_GeCtrl.SelAdd GeIDRemove
            m_GeCtrl.Delete
        End If
    End If
    
    If err = 3022 Then
      MsgBox "Mask already exists!", vbExclamation, "Error Renaming Mask"
      err = 0
    End If
        
    RenameShape = True
        
CleanUp_GeCtrl:
    m_GeCtrl.SelRemoveAll
    m_GeCtrl.GrabHandlesEnabled = True    ' turn em back on
    m_GeCtrl.RedrawEnabled = True
    m_GeCtrl.Redraw
    If Not rst Is Nothing Then rst.Close
    
    Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Failed to rename mask: " & err.Description
    GoTo CleanUp_GeCtrl
End Function

Public Function DeleteShape(cgDetails As cgLibraryShapeDetails, m_GeLbrMgr As GeLibraryMgr) As Boolean
    Dim rst As Recordset
    Dim strSQL As String
    Dim nRet As Integer
    
    On Error GoTo Error_Handler
    DeleteShape = False
    If Not SetGeCtrl() Then Exit Function
          
    If m_GeLbrMgr Is Nothing Then Exit Function
    If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
    
    strSQL = "SELECT * "
    strSQL = strSQL & "From GeTblShape Where ShapeName = '" & cgDetails.strShapeName & "' and FolderID = " & cgDetails.lFolderID
    Set rst = m_GeLbrMgr.LibDB.OpenRecordset(strSQL, dbOpenDynaset)
    
    With rst
      If .RecordCount = 1 Then
        .Delete
        DeleteShape = True
      End If
      .Close
    End With
  Exit Function
Error_Handler:
  If Not rst Is Nothing Then rst.Close
  gMsgWnd.LogMessage "Failed to delete shape: " & err.Description
End Function

Public Function ShapeExists(strFolderID As String, strShape As String, m_GeLbrMgr As GeLibraryMgr) As Boolean
    Dim rst As Recordset
    Dim strSQL As String
    Dim nRet As Integer

    On Error GoTo Error_Handler
    ShapeExists = False
   
    If m_GeLbrMgr Is Nothing Then
        Set m_GeLbrMgr = GetLibraryManager
        If m_GeLbrMgr Is Nothing Then Exit Function
    End If
    If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
    
    strSQL = "SELECT * "
    strSQL = strSQL & "From GeTblShape Where ShapeName = '" & strShape & "' and FolderID = " & strFolderID
    Set rst = m_GeLbrMgr.LibDB.OpenRecordset(strSQL, dbOpenDynaset)
    
    With rst
      If .RecordCount = 1 Then
        ShapeExists = True
      End If
      .Close
    End With
  Exit Function
Error_Handler:
  If Not rst Is Nothing Then rst.Close
  gMsgWnd.LogMessage "Failed to determine existance of shape " & strShape & ": " & err.Description
End Function

Public Function ShapeExistsByID(strFolderID As String, lShapeID As String, m_GeLbrMgr As GeLibraryMgr) As Boolean
    Dim rst As Recordset
    Dim strSQL As String
    Dim nRet As Integer

    On Error GoTo Error_Handler
    ShapeExistsByID = False
   
    If m_GeLbrMgr Is Nothing Then
        Set m_GeLbrMgr = GetLibraryManager
        If m_GeLbrMgr Is Nothing Then Exit Function
    End If
    If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
    
    strSQL = "SELECT * "
    strSQL = strSQL & "From GeTblShape Where ShapeID = " & lShapeID & " and FolderID = " & strFolderID
    Set rst = m_GeLbrMgr.LibDB.OpenRecordset(strSQL, dbOpenDynaset)
    
    With rst
      If .RecordCount = 1 Then
        ShapeExistsByID = True
      End If
      .Close
    End With
  Exit Function
Error_Handler:
  If Not rst Is Nothing Then rst.Close
  gMsgWnd.LogMessage "Failed to determine existance of shape " & lShapeID & ": " & err.Description
End Function


Public Sub GetShapeAndFolderForGeID(GeID As Long, ByRef strShape As String, ByRef strFolder As String)
    Dim strPathFolder As String
    Dim pos As Integer
    
    strShape = ""
    strFolder = ""
    If GeID <= 0 Then Exit Sub
    If Not SetGeCtrl() Then Exit Sub
    
    m_GeCtrl.ShapeSetCurrent GeID
    
    strShape = m_GeCtrl.ShapeName
    strPathFolder = m_GeCtrl.ShapePath     ' Returns File.ext!Folder
    pos = InStr(strPathFolder, "!")
    strFolder = Right(strPathFolder, Len(strPathFolder) - pos)
    
    m_GeCtrl.ShapeSetCurrent 0
End Sub

Public Function GetShapeID(strFolder As String, strShape As String) As Long
    Dim rst As Recordset
    Dim strSQL As String
    Dim nRet As Integer
    Dim strFolderID As String
    
    On Error GoTo Error_Handler
    GetShapeID = -1
    strFolderID = GetIDForFolder(strFolder)
   
    If m_GeLbrMgr Is Nothing Then
        Set m_GeLbrMgr = GetLibraryManager()
        If m_GeLbrMgr Is Nothing Then Exit Function
    End If
    If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
    
    strSQL = "SELECT * "
    strSQL = strSQL & "From GeTblShape Where ShapeName = '" & strShape & "' and FolderID = " & strFolderID
    Set rst = m_GeLbrMgr.LibDB.OpenRecordset(strSQL, dbOpenDynaset)
    
    With rst
      If .RecordCount = 1 Then
        GetShapeID = !ShapeID
      End If
      .Close
    End With
     
    CloseLibraryManager
    Exit Function
Error_Handler:
    If Not rst Is Nothing Then rst.Close
    gMsgWnd.LogMessage "Failed to retrieve ShapeID for shape " & strShape & ": " & err.Description
End Function

Public Function GetFoldersAndFolderIDs(collFolders As Collection, collIDs As Collection, m_GeLbrMgr As GeLibraryMgr) As Boolean
  Dim rsFolder As Recordset
  Dim nFolderID As Long
  Dim FolderName As String
  Dim bRet As Boolean
  
  On Error GoTo Error_Handler
  GetFoldersAndFolderIDs = False
  
  If m_GeLbrMgr Is Nothing Then Exit Function
  If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
  
  Set rsFolder = m_GeLbrMgr.LibDB.OpenRecordset("GeTblFolder", dbOpenSnapshot, dbReadOnly)

  If rsFolder.EOF Or rsFolder.BOF Then
    rsFolder.Close
    GetFoldersAndFolderIDs = True
    Exit Function
  End If
  
  rsFolder.MoveFirst
  Do While Not rsFolder.EOF
    nFolderID = rsFolder!FolderID
    FolderName = rsFolder!FolderName
    collFolders.Add FolderName
    collIDs.Add nFolderID, FolderName
    rsFolder.MoveNext
  Loop
  
  rsFolder.Close
  GetFoldersAndFolderIDs = True
  
  Exit Function
Error_Handler:
  gMsgWnd.LogMessage "Failed to retrieve folders and folder ID's from database: " & err.Description
End Function

Public Function GetIDForFolder(strFolder As String) As Long
  Dim rsFolder As Recordset
  Dim nFolderID As Long
  Dim FolderName As String
  Dim bRet As Boolean
  
  On Error GoTo Error_Handler
  GetIDForFolder = -1
  
  If m_GeLbrMgr Is Nothing Then
    Set m_GeLbrMgr = GetLibraryManager()
    If m_GeLbrMgr Is Nothing Then Exit Function
  End If
  If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
  
  Set rsFolder = m_GeLbrMgr.LibDB.OpenRecordset("GeTblFolder", dbOpenSnapshot, dbReadOnly)

  If rsFolder.EOF Or rsFolder.BOF Then
    rsFolder.Close
    Exit Function
  End If
  
  rsFolder.MoveFirst
  Do While Not rsFolder.EOF
    FolderName = rsFolder!FolderName
    If strFolder = FolderName Then
        GetIDForFolder = rsFolder!FolderID
    End If
    rsFolder.MoveNext
  Loop
  
  rsFolder.Close
  CloseLibraryManager
  
  Exit Function
Error_Handler:
  gMsgWnd.LogMessage "Failed to retrieve folders and folder ID's from database: " & err.Description
End Function

Private Function GetLibraryManager() As GeLibraryMgr
    Dim strLibName As String
    Dim bRet As Boolean
    
    On Error Resume Next
    If Not m_GeLbrMgr Is Nothing Then
        Set GetLibraryManager = m_GeLbrMgr
        Exit Function
    End If
    Set m_GeLbrMgr = New GeLibraryMgr

    strLibName = GetFirstAttachedCGLibrary()
    bRet = m_GeLbrMgr.OpenLibrary(strLibName, False)
    If bRet Then Set GetLibraryManager = m_GeLbrMgr
End Function

Private Function CloseLibraryManager()
    If Not m_GeLbrMgr Is Nothing Then m_GeLbrMgr.CloseLibrary
    Set m_GeLbrMgr = Nothing
End Function
'----------------------------------------------------------------------------------------------
' The following functions taken from Andy's auto shape gen. examples
'----------------------------------------------------------------------------------------------

Public Sub ReplaceIcon(cgDetailInfo As cgLibraryShapeDetails, lLeft As Single, lBottom As Single, lRight As Single, lTop As Single, collId As Collection)
  Dim GeID As Long
  Dim UserId As Long
  Dim l As Single, b As Single, r As Single, t As Single, h As Single, w As Single
  Dim delColl As Collection
  Dim i As Long
  
  If Len(cgDetailInfo.IconLibrary) > 0 And Len(cgDetailInfo.IconFolder) > 0 And Len(cgDetailInfo.IconShape) > 0 Then
    ' remove any existing Icon(s)
    Set delColl = New Collection
    m_GeCtrl.SelectAll
    GeID = m_GeCtrl.GetFirstSelObject
    Do While GeID <> 0
      m_GeCtrl.CurrentPropertyID = GeID  ' move into selector
      UserId = m_GeCtrl.ObjectUserID
      If UserId = SHAPEICON_USERID Then
        delColl.Add GeID
      End If
      GeID = m_GeCtrl.GetNextSelObject(GeID)
    Loop
    m_GeCtrl.CurrentPropertyID = 0  ' reset selector
    If delColl.count > 0 Then
      m_GeCtrl.SelRemoveAll
      For i = 1 To delColl.count
        m_GeCtrl.SelAdd delColl(i)
      Next i
      m_GeCtrl.Delete
    End If
    
    m_GeCtrl.UsePictureColor = True
    GeID = m_GeCtrl.CreateShapeWithUserID(cgDetailInfo.IconLibrary, cgDetailInfo.IconFolder, cgDetailInfo.IconShape, lLeft, lBottom, SHAPEICON_USERID)
    If GeID <> 0 Then
      m_GeCtrl.CurrentPropertyID = GeID
      Call m_GeCtrl.GetExtents(l, b, r, t)
      m_GeCtrl.CurrentPropertyID = 0
      h = t - b
      w = r - l
      If h > 0# And w > 0# Then
        Call m_GeCtrl.ScaleObject(GeID, lLeft, lBottom, (lRight - lLeft) / w, (lTop - lBottom) / h)
      End If
      AddAndSetUserID GeID, SHAPEICON_USERID, collId
    End If
  End If
End Sub

Public Function AutoGenerateShape( _
  strShape As String, _
  strFolder As String, _
  strFolderID As String, _
  m_GeLbrMgr As GeLibraryMgr, _
  cgDetailInfo As cgLibraryShapeDetails) As Boolean
  
  Dim ptX As Single, ptY As Single
  Dim fltLeft As Single, fltBottom As Single, fltRight As Single, fltTop As Single
  Dim lTop As Single, lBottom As Single, lLeft As Single, lRight As Single
  Dim fInsertionPointX As Single, fInsertionPointY As Single
  Dim fBottomPos As Single, fTopPos As Single
  Dim GeID As Long, UserId As Long
  Dim GeIDRectangle As Long
  Dim collId As New Collection  ' We need to keep track of all ids of things that I create (using collID)
  Dim ndxOrig As Long           ' original default color (that user had selected)
  Dim strLibAndFolder As String
  Dim fLabelDistance As Single
  Dim i As Integer
  
  On Error GoTo Error_Handler
  AutoGenerateShape = False
  m_UserID = 1
  
  If m_GeLbrMgr Is Nothing Then Exit Function
  If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
  If Not SetGeCtrl() Then Exit Function

  m_GeCtrl.RedrawEnabled = False
  m_GeCtrl.GrabHandlesEnabled = False  ' turn em off so user doesn't get excited

  ndxOrig = m_GeCtrl.PenColor          ' trap so can restore
  m_GeCtrl.PenColor = PEN_BLACK
         
  If Not cgDetailInfo Is Nothing Then
    If cgDetailInfo.m_bSizeShape Then
      'Determine shape size based on connectors, and the configured spaceing
      GetRectangleSize lLeft, lBottom, lRight, lTop, cgDetailInfo
      
      Call ReplaceIcon(cgDetailInfo, lLeft, lBottom, lRight, lTop, collId)
      
      GeID = m_GeCtrl.CreateRectangle(lLeft, lBottom, lRight, lTop)
      If GeID >= 0 Then
            GeIDRectangle = GeID
            AddAndSetUserID GeID, SHAPERECTANGLE_USERID, collId
            
            'Add shape name
            SetFontDetail FONT_HEIGHT, 1, 0
            fTopPos = lTop - (Abs(lTop - lBottom - SHAPELABEL_HEIGHT) / 2)
            fBottomPos = lBottom + (Abs(lTop - lBottom - SHAPELABEL_HEIGHT) / 2)
            GeID = m_GeCtrl.CreateTextField(lLeft + 0.05, fBottomPos, lRight - 0.05, fTopPos, strShape, strShape) 'fltLeft, fltBottom, fltRight, fltTop
            If GeID >= 0 Then AddAndSetUserID GeID, SHAPENAME_USERID, collId
    
            If Not cgDetailInfo Is Nothing Then
                If Not CreateAndAddSpacedConnectors(cgDetailInfo, GeIDRectangle, collId, lLeft, lBottom, lRight, lTop) Then
                    gMsgWnd.LogMessage "Failed to add connectors during mask '" & strShape & "' auto generation."
                    GoTo CleanUp_GeCtrl
                End If
            End If
      Else
          gMsgWnd.LogMessage "Failed to create rectangle for auto generated shape."
          GoTo CleanUp_GeCtrl
      End If
      
      AddMyObjectsToSelection collId    ' add all I created to the Selection List
      fInsertionPointX = lLeft + Abs(lRight - lLeft) / 2
      fInsertionPointY = lBottom + Abs(lTop - lBottom) / 2
      strLibAndFolder = m_GeLbrMgr.LibrayName & "!" & strFolder
      If Not CreateShapeDef(strLibAndFolder, strShape, fInsertionPointX, fInsertionPointY) Then
          GoTo CleanUp_GeCtrl
      End If
    Else
      'Use default shape size, and distribute the connectors evenly on the faces.
      lRight = IIf(cgDetailInfo.m_DefaultWidth >= MIN_FACE_SIZE, cgDetailInfo.m_DefaultWidth, MIN_FACE_SIZE)
      lTop = IIf(cgDetailInfo.m_DefaultHeight >= MIN_FACE_SIZE, cgDetailInfo.m_DefaultHeight, MIN_FACE_SIZE)
      
      Call ReplaceIcon(cgDetailInfo, LEFT_POS, BOTTOM_POS, lRight + LEFT_POS, lTop + BOTTOM_POS, collId)
      
      GeID = m_GeCtrl.CreateRectangle(LEFT_POS, BOTTOM_POS, lRight + LEFT_POS, lTop + BOTTOM_POS)
      If GeID >= 0 Then
            GeIDRectangle = GeID
            AddAndSetUserID GeID, SHAPERECTANGLE_USERID, collId
            
            'Add shape name
            SetFontDetail FONT_HEIGHT, 1, 0
            fTopPos = lTop - (Abs(lTop - BOTTOM_POS - SHAPELABEL_HEIGHT) / 2)
            fBottomPos = BOTTOM_POS + (Abs(lTop - BOTTOM_POS - SHAPELABEL_HEIGHT) / 2)
            GeID = m_GeCtrl.CreateTextField(LEFT_POS + 0.05, fBottomPos, RIGHT_POS - 0.05, fTopPos, strShape, strShape) 'fltLeft, fltBottom, fltRight, fltTop
            If GeID >= 0 Then AddAndSetUserID GeID, SHAPENAME_USERID, collId
    
            If Not cgDetailInfo Is Nothing Then
                If Not CreateAndAddConnectors(cgDetailInfo, GeIDRectangle, collId) Then
                    gMsgWnd.LogMessage "Failed to add connectors during mask '" & strShape & "' auto generation."
                    GoTo CleanUp_GeCtrl
                End If
            End If
      Else
          gMsgWnd.LogMessage "Failed to create rectangle for auto generated shape."
          GoTo CleanUp_GeCtrl
      End If
      
      AddMyObjectsToSelection collId    ' add all I created to the Selection List
      fInsertionPointX = LEFT_POS + Abs(lRight - LEFT_POS) / 2
      fInsertionPointY = BOTTOM_POS + Abs(lTop - BOTTOM_POS) / 2
      strLibAndFolder = m_GeLbrMgr.LibrayName & "!" & strFolder
      If Not CreateShapeDef(strLibAndFolder, strShape, fInsertionPointX, fInsertionPointY) Then
          GoTo CleanUp_GeCtrl
      End If
    End If
  End If
  
      
  AutoGenerateShape = True
  
CleanUp_GeCtrl:
  m_GeCtrl.Delete
  m_GeCtrl.SelRemoveAll
  m_GeCtrl.PenColor = ndxOrig           ' restore Default Pen color
  m_GeCtrl.GrabHandlesEnabled = True    ' turn em back on
  m_GeCtrl.RedrawEnabled = True
  m_GeCtrl.Redraw
  
  Exit Function
Error_Handler:
  gMsgWnd.LogMessage "Failed to auto generate shape " & strShape & ": " & err.Description
 End Function
 
Private Function CreateAndAddSpacedConnectors(ByRef cgDetailInfo As cgLibraryShapeDetails, GeIDRectangle As Long, ByRef collId As Collection, lLeft As Single, lBottom As Single, lRight As Single, lTop As Single) As Boolean
    Dim collBottom As Collection, collTop As Collection, collLeft As Collection, collRight As Collection
    Dim i As Integer
    Dim pDef As UserDefinedItemDef
    Dim fPosIncrement As Single
    Dim fOffset As Single
    Dim strConn As String
    Dim lConnSpace As Single
    
    On Error GoTo Error_Handler
    CreateAndAddSpacedConnectors = False
    lConnSpace = cgDetailInfo.m_ConnectorSpacing
    
    Set collBottom = New Collection
    Set collTop = New Collection
    Set collLeft = New Collection
    Set collRight = New Collection
    
    Set pDef = cgDetailInfo.m_UDIDefNew                                   'This will handle case of newly generated shape
    If pDef Is Nothing Then Set pDef = cgDetailInfo.m_UDIDefOriginal      'This will handle all other cases
    
    'Sepparate into 4 sets corresponding to each face Sorted on the Order
    For i = 1 To cgDetailInfo.m_collConnectors.count
         strConn = cgDetailInfo.m_collConnectors(i)
         Select Case CInt(cgDetailInfo.m_collFace(strConn))
           Case idxAttr_B
               AddToSortedCollection collBottom, cgDetailInfo, strConn
           Case idxAttr_T
               AddToSortedCollection collTop, cgDetailInfo, strConn
           Case idxAttr_L
               AddToSortedCollection collLeft, cgDetailInfo, strConn
           Case idxAttr_R
               AddToSortedCollection collRight, cgDetailInfo, strConn
         End Select
    Next i
    
    'Bottom Connectors
    If collBottom.count > 0 Then
       SetFontDetail lConnSpace, 0, VERTICAL_FONT_ORIENTATION 'This constant seems to be for vertical text
       fOffset = lConnSpace / 2
    End If
    For i = 1 To collBottom.count
       CreateConnection lConnSpace, fOffset, collBottom, i, collId, idxAttr_B, GeIDRectangle, pDef
    Next i
    
    'Top Connectors
    If collTop.count > 0 Then
       SetFontDetail lConnSpace, 2, VERTICAL_FONT_ORIENTATION 'This constant seems to be for vertical text
       fOffset = lConnSpace / 2
    End If
    For i = 1 To collTop.count
       CreateConnection lConnSpace, fOffset, collTop, i, collId, idxAttr_T, GeIDRectangle, pDef
    Next i
    
    'Left Connectors
    If collLeft.count > 0 Then
       SetFontDetail lConnSpace, 2, 0
       fOffset = lConnSpace / 2
    End If
    For i = 1 To collLeft.count
       CreateConnection lConnSpace, fOffset, collLeft, i, collId, idxAttr_L, GeIDRectangle, pDef
    Next i
    
    'Right Connectors
    If collRight.count > 0 Then
       SetFontDetail lConnSpace, 0, 0
       fOffset = lConnSpace / 2
    End If
    For i = 1 To collRight.count
       CreateConnection lConnSpace, fOffset, collRight, i, collId, idxAttr_R, GeIDRectangle, pDef
    Next i
    
    Set collBottom = Nothing
    Set collTop = Nothing
    Set collLeft = Nothing
    Set collRight = Nothing
    
    CreateAndAddSpacedConnectors = True
  
  Exit Function
Error_Handler:
  gMsgWnd.LogMessage "Failed to add connectors for auto generated shape " & cgDetailInfo.strShapeName & ": " & err.Description
End Function
  
'Walk the connector list, and create the appropriate connections.  Add them to the collection of selected objects.
Private Function CreateAndAddConnectors(ByRef cgDetailInfo As cgLibraryShapeDetails, GeIDRectangle As Long, ByRef collId As Collection) As Boolean
    Dim collBottom As Collection, collTop As Collection, collLeft As Collection, collRight As Collection
    Dim i As Integer
    Dim pDef As UserDefinedItemDef
    Dim fPosIncrement As Single
    Dim fOffset As Single
    Dim strConn As String
  
    On Error GoTo Error_Handler
    CreateAndAddConnectors = False
    
    Set collBottom = New Collection
    Set collTop = New Collection
    Set collLeft = New Collection
    Set collRight = New Collection
    
    Set pDef = cgDetailInfo.m_UDIDefNew                                   'This will handle case of newly generated shape
    If pDef Is Nothing Then Set pDef = cgDetailInfo.m_UDIDefOriginal      'This will handle all other cases
    
    'Sepparate into 4 sets corresponding to each face Sorted on the Order
    For i = 1 To cgDetailInfo.m_collConnectors.count
         strConn = cgDetailInfo.m_collConnectors(i)
         Select Case CInt(cgDetailInfo.m_collFace(strConn))
           Case idxAttr_B
               AddToSortedCollection collBottom, cgDetailInfo, strConn
           Case idxAttr_T
               AddToSortedCollection collTop, cgDetailInfo, strConn
           Case idxAttr_L
               AddToSortedCollection collLeft, cgDetailInfo, strConn
           Case idxAttr_R
               AddToSortedCollection collRight, cgDetailInfo, strConn
         End Select
    Next i
    
    'Bottom Connectors
    If collBottom.count > 0 Then
       fPosIncrement = GetConnectorSpacing(collBottom.count, szAttr_B, GeIDRectangle)
       SetFontDetail fPosIncrement, 0, VERTICAL_FONT_ORIENTATION 'This constant seems to be for vertical text
       fOffset = fPosIncrement / 2
    End If
    For i = 1 To collBottom.count
       CreateConnection fPosIncrement, fOffset, collBottom, i, collId, idxAttr_B, GeIDRectangle, pDef
    Next i
    
    'Top Connectors
    If collTop.count > 0 Then
       fPosIncrement = GetConnectorSpacing(collTop.count, szAttr_T, GeIDRectangle)
       SetFontDetail fPosIncrement, 2, VERTICAL_FONT_ORIENTATION 'This constant seems to be for vertical text
       fOffset = fPosIncrement / 2
    End If
    For i = 1 To collTop.count
       CreateConnection fPosIncrement, fOffset, collTop, i, collId, idxAttr_T, GeIDRectangle, pDef
    Next i
    
    'Left Connectors
    If collLeft.count > 0 Then
       fPosIncrement = GetConnectorSpacing(collLeft.count, szAttr_L, GeIDRectangle)
       SetFontDetail fPosIncrement, 2, 0
       fOffset = fPosIncrement / 2
    End If
    For i = 1 To collLeft.count
       CreateConnection fPosIncrement, fOffset, collLeft, i, collId, idxAttr_L, GeIDRectangle, pDef
    Next i
    
    'Right Connectors
    If collRight.count > 0 Then
       fPosIncrement = GetConnectorSpacing(collRight.count, szAttr_R, GeIDRectangle)
       SetFontDetail fPosIncrement, 0, 0
       fOffset = fPosIncrement / 2
    End If
    For i = 1 To collRight.count
       CreateConnection fPosIncrement, fOffset, collRight, i, collId, idxAttr_R, GeIDRectangle, pDef
    Next i
    
    Set collBottom = Nothing
    Set collTop = Nothing
    Set collLeft = Nothing
    Set collRight = Nothing
    
    CreateAndAddConnectors = True
  
  Exit Function
Error_Handler:
  gMsgWnd.LogMessage "Failed to add connectors for auto generated shape " & cgDetailInfo.strShapeName & ": " & err.Description
End Function
 
Public Function DeleteConnectors(collDel As Collection, cgDetails As cgLibraryShapeDetails, m_GeLbrMgr As GeLibraryMgr) As Boolean
    Dim ShapeGeID As Long, ObjGeID As Long
    Dim UserId As Long
    Dim strLibAndFolder As String
    Dim fInsertionPointX As Single, fInsertionPointY As Single
    Dim collGeIDsToRemove As Collection
    Dim strConn As String
    Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
    Dim RectangleGeID As Long
    Dim oDetails As cgShapeComponentDetails
    Dim collConns As Collection
    Dim bCanExplode As Boolean
    Dim collId As Collection
    
    On Error GoTo Error_Handler
    DeleteConnectors = False
    If Not SetGeCtrl() Then Exit Function
    
    Set collId = New Collection
    Set collConns = New Collection
    'Set m_collEnumUserID = Nothing
    'Set m_collEnumGeID = Nothing
    m_GeCtrl.GrabHandlesEnabled = False
    m_GeCtrl.RedrawEnabled = False
    m_GeCtrl.SelRemoveAll
    
    m_GeCtrl.UsePictureColor = True
    ShapeGeID = m_GeCtrl.CreateShape(m_GeLbrMgr.LibrayName, cgDetails.strFolderName, cgDetails.strShapeName, 1, 1)
    If ShapeGeID <= 0 Then Exit Function
    
    m_GeCtrl.CurrentPropertyID = ShapeGeID
    bCanExplode = m_GeCtrl.CanExplodeShape
    m_GeCtrl.CurrentPropertyID = 0
    
    m_GeCtrl.SelRemoveAll
    
    'Enumerate all the connectors and determine their face and order based on their position.
    EnumAllShapeObjects ShapeGeID, RectangleGeID, collConns
        
    Set collGeIDsToRemove = New Collection
                  
    Dim i As Long
    Dim j As Long
    For i = 1 To collDel.count
        For j = 1 To collConns.count
            Set oDetails = collConns(j)
            If oDetails.UserId = collDel(i) Then
                collGeIDsToRemove.Add oDetails.GeID
                m_GeCtrl.SelRemove oDetails.GeID
            End If
        Next j
    Next i
               
    If RectangleGeID > 0 Then
        m_GeCtrl.CurrentPropertyID = RectangleGeID
        m_GeCtrl.GetExtents fLeft, fBottom, fRight, fTop
        m_GeCtrl.CurrentPropertyID = 0
    Else
        fLeft = LEFT_POS
        fBottom = BOTTOM_POS
        fRight = RIGHT_POS
        fTop = TOP_POS
    End If
        
    strLibAndFolder = m_GeLbrMgr.LibrayName & "!" & cgDetails.strFolderName
    fInsertionPointX = fLeft + Abs(fRight - fLeft) / 2
    fInsertionPointY = fBottom + Abs(fTop - fBottom) / 2
    If bCanExplode Then
        If Not CreateShapeDef(strLibAndFolder, cgDetails.strShapeName, fInsertionPointX, fInsertionPointY) Then
            GoTo CleanUp_GeCtrl
        End If
    Else
        If Not CreateSmartShapeDef(strLibAndFolder, cgDetails.strShapeName, fInsertionPointX, fInsertionPointY) Then
            GoTo CleanUp_GeCtrl
        End If
    End If
    
    'Remove left over 'old' connectors
    ' TODO: determine what to do with this non-existent bAltered flag
    Dim bAltered As Boolean
    If bAltered Then
        m_GeCtrl.SelRemoveAll
        For i = 1 To collGeIDsToRemove.count
            m_GeCtrl.SelAdd collGeIDsToRemove(i)
        Next i
        m_GeCtrl.Delete
    End If
    
CleanUp_GeCtrl:
    m_GeCtrl.Delete
    m_GeCtrl.SelRemoveAll
    m_GeCtrl.GrabHandlesEnabled = True    ' turn em back on
    m_GeCtrl.RedrawEnabled = True
    m_GeCtrl.Redraw
    Set collId = Nothing
    Set collConns = Nothing
    
    DeleteConnectors = True
    
    Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Failed to Delete Connector: " & err.Description
    GoTo CleanUp_GeCtrl
End Function

'Remove all the connectors and re-add them.  This way they are fitted nicely on the existing bounding rectangle
Public Function AddConnectors(collAdd As Collection, ByRef cgDetails As cgLibraryShapeDetails, m_GeLbrMgr As GeLibraryMgr) As Boolean
    Dim ShapeGeID As Long, GeID As Long
    Dim UserId As Long
    Dim strLibAndFolder As String
    Dim fInsertionPointX As Single, fInsertionPointY As Single
    Dim collGeIDsToRemove As Collection, collId As Collection
    Dim strConn As String
    Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
    Dim RectangleGeID As Long
    Dim oDetails As cgShapeComponentDetails
    Dim collConns As Collection
    Dim bCanExplode As Boolean
    Dim lTop As Single, lBottom As Single, lLeft As Single, lRight As Single
    
    On Error GoTo Error_Handler
    AddConnectors = False
    If Not SetGeCtrl() Then Exit Function
    
    Set collId = New Collection
    Set collConns = New Collection
    'Set m_collEnumUserID = Nothing
    'Set m_collEnumGeID = Nothing
    Set collGeIDsToRemove = New Collection
    
    m_GeCtrl.GrabHandlesEnabled = False
    m_GeCtrl.RedrawEnabled = False
    m_GeCtrl.SelRemoveAll
    
    m_GeCtrl.UsePictureColor = True
    ShapeGeID = m_GeCtrl.CreateShape(m_GeLbrMgr.LibrayName, cgDetails.strFolderName, cgDetails.strShapeName, 1, 1)
    If ShapeGeID <= 0 Then Exit Function
    
    m_GeCtrl.CurrentPropertyID = ShapeGeID
    bCanExplode = m_GeCtrl.CanExplodeShape
    m_GeCtrl.CurrentPropertyID = 0
        
    m_GeCtrl.SelRemoveAll
    
    'Enumerate all the connectors and determine their face and order based on their position.
    EnumAllShapeObjects ShapeGeID, RectangleGeID, collConns
                                          
    'Remove and recreate ALL connectors
    Dim i As Long
    For i = 1 To collConns.count
        Set oDetails = collConns(i)
        If oDetails.iType = EGeObjType.ObjConnector Or oDetails.iType = EGeObjType.Polyline Or oDetails.iType = EGeObjType.Text Then
            collGeIDsToRemove.Add oDetails.GeID
            m_GeCtrl.SelRemove oDetails.GeID
        ElseIf oDetails.UserId = SHAPENAME_USERID Or oDetails.GeID = RectangleGeID Then
            collGeIDsToRemove.Add oDetails.GeID
            m_GeCtrl.SelRemove oDetails.GeID
        Else
            collId.Add oDetails.GeID
        End If
    Next i
               
    'Calculate new rectangle extents and create it.
    If Not cgDetails Is Nothing Then
        lRight = IIf(cgDetails.m_DefaultWidth >= MIN_FACE_SIZE, cgDetails.m_DefaultWidth + LEFT_POS, MIN_FACE_SIZE + LEFT_POS)
        lTop = IIf(cgDetails.m_DefaultHeight >= MIN_FACE_SIZE, cgDetails.m_DefaultHeight + BOTTOM_POS, MIN_FACE_SIZE + BOTTOM_POS)
        
        Call ReplaceIcon(cgDetails, LEFT_POS, BOTTOM_POS, lRight, lTop, collId)
        
        GeID = m_GeCtrl.CreateRectangle(LEFT_POS, BOTTOM_POS, lRight, lTop)
        If GeID >= 0 Then
            RectangleGeID = GeID
            'If we created a new rectangle, look for picture holders, so we can adjust them to fit within the new
            'bounding rectangle
            For i = 1 To collConns.count
                Set oDetails = collConns(i)
                If oDetails.iType = EGeObjType.PictureHolder Then
                    Dim x1 As Single, y1 As Single, x2 As Single, y2 As Single
                    
                    m_GeCtrl.CurrentPropertyID = oDetails.GeID
                    m_GeCtrl.GetExtents x1, y1, x2, y2
                    m_GeCtrl.MoveObject oDetails.GeID, LEFT_POS - x1, BOTTOM_POS - y1
                    m_GeCtrl.CurrentPropertyID = 0
                End If
            Next
            
            AddAndSetUserID GeID, SHAPERECTANGLE_USERID, collId
              
            'Add shape name
            Dim fTopPos As Single
            Dim fBottomPos As Single
            
            SetFontDetail FONT_HEIGHT, 1, 0
            fTopPos = lTop - (Abs(lTop - BOTTOM_POS - SHAPELABEL_HEIGHT) / 2)
            fBottomPos = BOTTOM_POS + (Abs(lTop - BOTTOM_POS - SHAPELABEL_HEIGHT) / 2)
            GeID = m_GeCtrl.CreateTextField(LEFT_POS + 0.05, fBottomPos, lRight - 0.05, fTopPos, cgDetails.strShapeName, cgDetails.strShapeName) 'fltLeft, fltBottom, fltRight, fltTop
            If GeID >= 0 Then AddAndSetUserID GeID, SHAPENAME_USERID, collId
        End If
    
        If Not CreateAndAddConnectors(cgDetails, RectangleGeID, collId) Then
            gMsgWnd.LogMessage "Failed to add connectors during library block '" & cgDetails.strShapeName & "' auto generation."
            GoTo CleanUp_GeCtrl
        End If
    End If
               
    If RectangleGeID > 0 Then
        m_GeCtrl.CurrentPropertyID = RectangleGeID
        m_GeCtrl.GetExtents fLeft, fBottom, fRight, fTop
        m_GeCtrl.CurrentPropertyID = 0
    Else
        fLeft = LEFT_POS
        fBottom = BOTTOM_POS
        fRight = RIGHT_POS
        fTop = TOP_POS
    End If
                
    AddMyObjectsToCurrentSelection collId
    strLibAndFolder = m_GeLbrMgr.LibrayName & "!" & cgDetails.strFolderName
    fInsertionPointX = fLeft + Abs(fRight - fLeft) / 2
    fInsertionPointY = fBottom + Abs(fTop - fBottom) / 2
    If bCanExplode Then
        If Not CreateShapeDef(strLibAndFolder, cgDetails.strShapeName, fInsertionPointX, fInsertionPointY) Then
            GoTo CleanUp_GeCtrl
        End If
    Else
        If Not CreateSmartShapeDef(strLibAndFolder, cgDetails.strShapeName, fInsertionPointX, fInsertionPointY) Then
            GoTo CleanUp_GeCtrl
        End If
    End If
    
    'Remove left over 'old' connectors
    ' TODO: determine what to do with this bAltered flag
    Dim bAltered As Boolean
    
    If bAltered Then
        m_GeCtrl.SelRemoveAll
        For i = 1 To collGeIDsToRemove.count
            m_GeCtrl.SelAdd collGeIDsToRemove(i)
        Next i
        m_GeCtrl.Delete
    End If
    
CleanUp_GeCtrl:
    m_GeCtrl.Delete
    m_GeCtrl.SelRemoveAll
    m_GeCtrl.GrabHandlesEnabled = True    ' turn em back on
    m_GeCtrl.RedrawEnabled = True
    m_GeCtrl.Redraw
    Set collId = Nothing
    Set collConns = Nothing
    
    AddConnectors = True
    Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Failed to add Connectors: " & err.Description
    GoTo CleanUp_GeCtrl
End Function

'In this case the bounding rectangle has to be removed as well, and recalculated to fit the connectors
Public Function AddSpacedConnectors(collAdd As Collection, ByRef cgDetails As cgLibraryShapeDetails, m_GeLbrMgr As GeLibraryMgr) As Boolean
    Dim ShapeGeID As Long, GeID As Long
    Dim UserId As Long
    Dim strLibAndFolder As String
    Dim fInsertionPointX As Single, fInsertionPointY As Single
    Dim collGeIDsToRemove As Collection, collId As Collection
    Dim strConn As String
    Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
    Dim fTopPos As Single, fBottomPos As Single
    Dim RectangleGeID As Long
    Dim oDetails As cgShapeComponentDetails
    Dim collConns As Collection
    Dim bCanExplode As Boolean
    Dim lTop As Single, lBottom As Single, lLeft As Single, lRight As Single
        
    On Error GoTo Error_Handler
    AddSpacedConnectors = False
    If Not SetGeCtrl() Then Exit Function
    
    Set collId = New Collection
    Set collConns = New Collection
    'Set m_collEnumUserID = Nothing
    'Set m_collEnumGeID = Nothing
    Set collGeIDsToRemove = New Collection
    
    m_GeCtrl.GrabHandlesEnabled = False
    m_GeCtrl.RedrawEnabled = False
    m_GeCtrl.SelRemoveAll
    
    m_GeCtrl.UsePictureColor = True
    ShapeGeID = m_GeCtrl.CreateShape(m_GeLbrMgr.LibrayName, cgDetails.strFolderName, cgDetails.strShapeName, 1, 1)
    If ShapeGeID <= 0 Then Exit Function
    
    m_GeCtrl.CurrentPropertyID = ShapeGeID
    bCanExplode = m_GeCtrl.CanExplodeShape
    m_GeCtrl.CurrentPropertyID = 0
        
    m_GeCtrl.SelRemoveAll
    
    'Enumerate all the connectors and determine their face and order based on their position.
    EnumAllShapeObjects ShapeGeID, RectangleGeID, collConns
                                          
    'Remove and recreate ALL connectors
    Dim i As Long
    For i = 1 To collConns.count
        Set oDetails = collConns(i)
        If oDetails.iType = EGeObjType.ObjConnector Or oDetails.iType = EGeObjType.Polyline Or oDetails.iType = EGeObjType.Text Then
            collGeIDsToRemove.Add oDetails.GeID
            m_GeCtrl.SelRemove oDetails.GeID
        ElseIf oDetails.UserId = SHAPENAME_USERID Or oDetails.GeID = RectangleGeID Then
            collGeIDsToRemove.Add oDetails.GeID
            m_GeCtrl.SelRemove oDetails.GeID
        Else
            collId.Add oDetails.GeID
        End If
    Next i
               
    'Calculate new rectangle extents and create it.
    If Not cgDetails Is Nothing Then
        GetRectangleSize lLeft, lBottom, lRight, lTop, cgDetails
        
        Call ReplaceIcon(cgDetails, lLeft, lBottom, lRight, lTop, collId)
        
        GeID = m_GeCtrl.CreateRectangle(lLeft, lBottom, lRight, lTop)
        If GeID >= 0 Then
            RectangleGeID = GeID
            'If we created a new rectangle, look for picture holders, so we can adjust them to fit within the new
            'bounding rectangle
            For i = 1 To collConns.count
                Set oDetails = collConns(i)
                If oDetails.iType = EGeObjType.PictureHolder Then
                    Dim x1 As Single, y1 As Single, x2 As Single, y2 As Single
                    
                    m_GeCtrl.CurrentPropertyID = oDetails.GeID
                    m_GeCtrl.GetExtents x1, y1, x2, y2
                    m_GeCtrl.MoveObject oDetails.GeID, LEFT_POS - x1, BOTTOM_POS - y1
                    m_GeCtrl.CurrentPropertyID = 0
                End If
            Next
            
            AddAndSetUserID GeID, SHAPERECTANGLE_USERID, collId
              
            'Add shape name
            SetFontDetail FONT_HEIGHT, 1, 0
            fTopPos = lTop - (Abs(lTop - lBottom - SHAPELABEL_HEIGHT) / 2)
            fBottomPos = lBottom + (Abs(lTop - lBottom - SHAPELABEL_HEIGHT) / 2)
            GeID = m_GeCtrl.CreateTextField(lLeft + 0.05, fBottomPos, lRight - 0.05, fTopPos, cgDetails.strShapeName, cgDetails.strShapeName) 'fltLeft, fltBottom, fltRight, fltTop
            If GeID >= 0 Then AddAndSetUserID GeID, SHAPENAME_USERID, collId
        End If
    
        If Not CreateAndAddSpacedConnectors(cgDetails, RectangleGeID, collId, lLeft, lBottom, lRight, lTop) Then
            gMsgWnd.LogMessage "Failed to add spaced connectors during library block '" & cgDetails.strShapeName & "' auto generation."
            GoTo CleanUp_GeCtrl
        End If
    End If
                               
    AddMyObjectsToCurrentSelection collId
    strLibAndFolder = m_GeLbrMgr.LibrayName & "!" & cgDetails.strFolderName
    fInsertionPointX = lLeft + Abs(lRight - lLeft) / 2
    fInsertionPointY = lBottom + Abs(lTop - lBottom) / 2
    If bCanExplode Then
        If Not CreateShapeDef(strLibAndFolder, cgDetails.strShapeName, fInsertionPointX, fInsertionPointY) Then
            GoTo CleanUp_GeCtrl
        End If
    Else
        If Not CreateSmartShapeDef(strLibAndFolder, cgDetails.strShapeName, fInsertionPointX, fInsertionPointY) Then
            GoTo CleanUp_GeCtrl
        End If
    End If
    
    'Remove left over 'old' connectors
    ' TODO: determine what to do with this bAltered flag
    Dim bAltered As Boolean
    
    If bAltered Then
        m_GeCtrl.SelRemoveAll
        For i = 1 To collGeIDsToRemove.count
            m_GeCtrl.SelAdd collGeIDsToRemove(i)
        Next i
        m_GeCtrl.Delete
    End If
    
CleanUp_GeCtrl:
    m_GeCtrl.Delete
    m_GeCtrl.SelRemoveAll
    m_GeCtrl.GrabHandlesEnabled = True    ' turn em back on
    m_GeCtrl.RedrawEnabled = True
    m_GeCtrl.Redraw
    Set collId = Nothing
    Set collConns = Nothing
    
    AddSpacedConnectors = True
    Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Failed to add spaced Connectors: " & err.Description
    GoTo CleanUp_GeCtrl
End Function

'This method is used to retrieve all connectors, including their face and order, for shapes that do NOT have an
'associated UDIDef.  An array of CgConnectionDef will be populated rather then a UDIDef CgConnectionDefs collection
Public Function GetShapeConnectorsAndDetails(strLibrary As String, strFolder As String, strShape As String, ByRef collConnections As Collection) As Boolean
    Dim GeID As Long, RectangleGeID As Long
    
    On Error GoTo Error_Handler
    
    Set collConnections = New Collection
    GetShapeConnectorsAndDetails = False
    If Not SetGeCtrl() Then Exit Function
    
    m_GeCtrl.GrabHandlesEnabled = False
    m_GeCtrl.RedrawEnabled = False
    
    m_GeCtrl.SelRemoveAll

    m_GeCtrl.UsePictureColor = True
    GeID = m_GeCtrl.CreateShape(strLibrary, strFolder, strShape, 1, 1)
    If GeID <= 0 Then Exit Function
    
    'Enumerate all the connectors and determine their face and order based on their position.
    EnumAllShapeObjects GeID, RectangleGeID, collConnections
    
    If (collConnections.count > 0) And (RectangleGeID > 0) Then
        'Fill in Connection definition details.
        CalculateConnectionFaceAndOrder RectangleGeID, collConnections
    End If
        
    GetShapeConnectorsAndDetails = True
    
    If RectangleGeID < 0 Then
        gMsgWnd.LogMessage "Failed to retrieve a bounding rectangle for the shape."
        GetShapeConnectorsAndDetails = False
    End If
    
    GetShapeConnectorsAndDetails = True
    m_GeCtrl.Delete
    m_GeCtrl.GrabHandlesEnabled = True
    m_GeCtrl.RedrawEnabled = True
    
    Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Failed to retrieve connection details: " & err.Description
    m_GeCtrl.GrabHandlesEnabled = True
    m_GeCtrl.RedrawEnabled = True
End Function

'This method is used for filling in order and face for ShapeDefs that have an associated UDIDef
Public Function GetConnectionDetails(pDef As UserDefinedItemDef) As Boolean
    Dim UserId As Long
    Dim GeID As Long, GeIDTemp As Long, RectangleGeID As Long
    Dim i As Integer
    Dim iLen As Integer
    Dim strUserID As String
    Dim strName As String
    Dim collConns As Collection
    Dim cgConn As CgConnectionDef
    Dim oDetails As cgShapeComponentDetails
    
    On Error GoTo Error_Handler
    
    Set collConns = New Collection
    GetConnectionDetails = False
    If Not SetGeCtrl() Then Exit Function
    If m_GeLbrMgr Is Nothing Then
        GetLibraryManager
        If m_GeLbrMgr Is Nothing Then Exit Function
    End If
        
    m_GeCtrl.GrabHandlesEnabled = False
    m_GeCtrl.RedrawEnabled = False
    
    m_GeCtrl.SelRemoveAll
    
    m_GeCtrl.UsePictureColor = True
    GeID = m_GeCtrl.CreateShape(m_GeLbrMgr.LibrayName, pDef.GeFolder, pDef.GeShape, 1, 1)
    If GeID <= 0 Then Exit Function
    
    'Enumerate all the connectors and determine their face and order based on their position.
    EnumAllShapeObjects GeID, RectangleGeID, collConns
    
    If (collConns.count > 0) And (RectangleGeID > 0) Then
        'Fill in Connection definition details (face and order).
        CalculateConnectionFaceAndOrder RectangleGeID, collConns
        'Fill in CgConnectionCollection's face and order
        For i = 1 To collConns.count
            Set oDetails = collConns(i)
            If Len(oDetails.strName) > 0 Then
                If oDetails.iType = EGeObjType.ObjConnector Then
                    pDef.FillInDetails oDetails.strName, oDetails.iFace, oDetails.iOrder, oDetails.UserId
                End If
            End If
        Next
        Set collConns = Nothing
    End If
    
    If RectangleGeID < 0 Then
        gMsgWnd.LogMessage "Failed to retrieve a bounding rectangle for the shape."
        GetConnectionDetails = False
    End If
        
    GetConnectionDetails = True
    m_GeCtrl.Delete
    m_GeCtrl.GrabHandlesEnabled = True
    m_GeCtrl.RedrawEnabled = True
    
    Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Failed to retrieve connection details: " & err.Description
    m_GeCtrl.GrabHandlesEnabled = True
    m_GeCtrl.RedrawEnabled = True
End Function

Public Sub VerifyConnectorsForChangedShape(strShape As String, strFolder As String)
    'TODO: We need a way to retrieve manual connector changes to the shape, and adjust our connector lists.
End Sub

Private Function GetConnectorSpacing(iConnNum As Integer, szFace As String, GeIDRectangle As Long) As Single
    Dim fAvailableLength As Single
    Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
      
    If GeIDRectangle > 0 Then
      m_GeCtrl.CurrentPropertyID = GeIDRectangle
      m_GeCtrl.GetExtents fLeft, fBottom, fRight, fTop
      m_GeCtrl.CurrentPropertyID = 0
    Else
      fLeft = LEFT_POS
      fBottom = BOTTOM_POS
      fRight = RIGHT_POS
      fTop = TOP_POS
    End If
    
    If iConnNum <= 0 Then
        GetConnectorSpacing = 1
        Exit Function
    End If
    
    If szFace = szAttr_B Or szFace = szAttr_T Then
        fAvailableLength = Abs(fRight - fLeft)
    Else
        fAvailableLength = Abs(fTop - fBottom)
    End If
 
    GetConnectorSpacing = fAvailableLength / iConnNum
 End Function
 
 Private Sub AddToSortedCollection(collItems As Collection, cgDetailInfo As cgLibraryShapeDetails, strKey As String)
    Dim i As Integer
    Dim strConn As String
    Dim iCurrOrder As Integer
    Dim iAddOrder As Integer
    Dim bAdded As Integer
    
    On Error Resume Next
    bAdded = False
    If collItems.count <= 0 Then
        collItems.Add cgDetailInfo.m_collConnectors(strKey)
    Else
        strConn = cgDetailInfo.m_collConnectors(strKey)
        iAddOrder = cgDetailInfo.m_collOrder(strKey)
        For i = 1 To collItems.count
           iCurrOrder = cgDetailInfo.m_collOrder(collItems(i))
           If iAddOrder <= iCurrOrder Then
                collItems.Add cgDetailInfo.m_collConnectors(strKey), cgDetailInfo.m_collConnectors(strKey), Before:=i
                bAdded = True
                Exit For
            End If
        Next i
        If Not bAdded Then
            collItems.Add cgDetailInfo.m_collConnectors(strKey), cgDetailInfo.m_collConnectors(strKey), After:=collItems.count
        End If
    End If
    
 End Sub
  
 Private Sub AddToLeftCollection(ByRef collLeft As Collection, ByRef oObjectDetails As cgShapeComponentDetails)
    Dim i As Integer
    Dim oDetails As cgShapeComponentDetails
    
    For i = 1 To collLeft.count
        Set oDetails = collLeft(i)
        If oObjectDetails.llY >= oDetails.llY Then
            collLeft.Add oObjectDetails, , Before:=i
            Exit Sub
        End If
    Next i
    collLeft.Add oObjectDetails
 End Sub
   
 Private Sub AddToRightCollection(ByRef collRight As Collection, ByRef oObjectDetails As cgShapeComponentDetails)
    Dim i As Integer
    Dim oDetails As cgShapeComponentDetails
    
    For i = 1 To collRight.count
        Set oDetails = collRight(i)
        If oObjectDetails.urY >= oDetails.urY Then
            collRight.Add oObjectDetails, , Before:=i
            Exit Sub
        End If
    Next i
    collRight.Add oObjectDetails
 End Sub
 
 Private Sub AddToBottomCollection(ByRef collBottom As Collection, ByRef oObjectDetails As cgShapeComponentDetails)
    Dim i As Integer
    Dim oDetails As cgShapeComponentDetails
    
    For i = 1 To collBottom.count
        Set oDetails = collBottom(i)
        If oObjectDetails.llX <= oDetails.llX Then
            collBottom.Add oObjectDetails, , Before:=i
            Exit Sub
        End If
    Next i
    collBottom.Add oObjectDetails
 End Sub
  
 Private Sub AddToTopCollection(ByRef collTop As Collection, ByRef oObjectDetails As cgShapeComponentDetails)
    Dim i As Integer
    Dim oDetails As cgShapeComponentDetails
    
    For i = 1 To collTop.count
        Set oDetails = collTop(i)
        If oObjectDetails.urX <= oDetails.urX Then
            collTop.Add oObjectDetails, , Before:=i
            Exit Sub
        End If
    Next i
    collTop.Add oObjectDetails
 End Sub
 
Private Sub FillInConnectionOrderField(ByRef collConns As Collection)
    Dim i As Integer
    Dim oObjectDetails As cgShapeComponentDetails
    
    For i = 1 To collConns.count
        Set oObjectDetails = collConns(i)
        oObjectDetails.iOrder = i
    Next
End Sub
    
 Private Sub AddMyObjectsToSelection(collId As Collection)
 ' add all in coll to selection
  Dim i As Long
  Dim GeID As Long
  
  On Error Resume Next
  m_GeCtrl.SelRemoveAll
  For i = 1 To collId.count
    GeID = collId.Item(i)
    m_GeCtrl.SelAdd GeID
  Next i
End Sub

 Private Sub AddMyObjectsToCurrentSelection(collId As Collection)
 ' add all in coll to selection
  Dim i As Long
  Dim GeID As Long
  
  On Error Resume Next
  For i = 1 To collId.count
    GeID = collId.Item(i)
    m_GeCtrl.SelAdd GeID
  Next i
End Sub

Private Function CreateRectangle(fltLeft As Single, fltBottom As Single, fltRight As Single, fltTop As Single, GeID As Long) As Boolean
  ' create a Shape Instance
  On Error Resume Next
  GeID = m_GeCtrl.CreateRectangle(fltLeft, fltBottom, fltRight, fltTop)
  CreateRectangle = VERIFY_ERR
End Function

Private Function CreateShape(strLibrary As String, strFolder As String, strShape As String, ptX As Single, ptY As Single, GeID As Long) As Boolean
  ' create a Shape Instance
  On Error Resume Next
  m_GeCtrl.UsePictureColor = True
  GeID = m_GeCtrl.CreateShape(strLibrary, strFolder, strShape, ptX, ptY)
  CreateShape = VERIFY_ERR
End Function

Private Function CreateShapeDef(strLibAndFolder As String, strShape As String, ptX As Single, ptY As Single) As Boolean
  ' create a ShapeDef. ptX and ptY are the insertion point.
  ' we assume that there are objects selected at this point.
  ' returns False if failed, true otherwise
  
  On Error Resume Next
  m_GeCtrl.TreatShapesAsUserGroups = False
  CreateShapeDef = m_GeCtrl.CreateShapeDef(strLibAndFolder, strShape, ptX, ptY)

  If CreateShapeDef And Not GeCtrlMain Is Nothing Then GeCtrlMain.NotifyShapeDefRedefined strLibAndFolder, strShape
  
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

Private Function CreateSmartShapeDef(strLibAndFolder As String, strShape As String, ptX As Single, ptY As Single) As Boolean
  ' create a SmartShapeDef. ptX and ptY are the insertion point.
  ' we assume that there are objects selected at this point.
  ' returns False if failed, true otherwise
  
  On Error Resume Next
  m_GeCtrl.TreatShapesAsUserGroups = True       ' the trick to tell Ctrl that we want to make a SmartShape (aka UserGroup)
  CreateSmartShapeDef = m_GeCtrl.CreateShapeDef(strLibAndFolder, strShape, ptX, ptY)
  Debug.Print err.Description
  m_GeCtrl.TreatShapesAsUserGroups = False      ' remember to reset

  If CreateSmartShapeDef And Not GeCtrlMain Is Nothing Then GeCtrlMain.NotifyShapeDefRedefined strLibAndFolder, strShape

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

Private Sub CreateConnection(fPosIncrement As Single, fOffset As Single, collConn As Collection, i As Integer, ByRef collId As Collection, iFace As Integer, GeIDRectangle As Long, ByRef pDefNew As UserDefinedItemDef)
  Dim GeID As Long
  Dim ConType As Integer    ' Type - MUST be a POSITIVE VALUE!
  Dim ptX As Single, ptY As Single
  Dim spacingV As Single
  Dim aVertices() As Single
  Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
  Dim strFldValue As String
  Dim strFldName As String
  Dim UserId As Long
  Dim varPoint(1, 1) As Single
  Dim fPos As Single
  Dim strConn As String
  Dim strObjectName As String
  Dim fTextPos As Single
  
  On Error Resume Next
  If Not SetGeCtrl() Then Exit Sub
  
  ConType = 1
  strConn = collConn(i)
  
  If GeIDRectangle > 0 Then
    m_GeCtrl.CurrentPropertyID = GeIDRectangle
    m_GeCtrl.GetExtents fLeft, fBottom, fRight, fTop
    m_GeCtrl.CurrentPropertyID = 0
  Else
    fLeft = LEFT_POS
    fBottom = BOTTOM_POS
    fRight = RIGHT_POS
    fTop = TOP_POS
  End If
  
  Select Case iFace
    Case idxAttr_B
        UserId = i * 10 + idxAttr_B
        fPos = fPosIncrement * (i - 1) + fLeft + fOffset
        'For the Connection Point name, we attach the shape name to make sure we will have a unique identifier
        'for this UserID when we try to retrieve it on startup.
        GeID = m_GeCtrl.CreateConnectionPoint(fPos, fBottom - CONNECTOR_DISTANCE, strConn, ConType)
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
        
        GeID = m_GeCtrl.CreateText(fPos, fBottom - 0.05, strConn) 'fltLeft, fltBottom, fltRight, fltTop
        If GeID >= 0 Then
            AddAndSetUserID GeID, UserId, collId
        End If
        
        varPoint(0, 0) = fPos
        varPoint(0, 1) = fBottom
        varPoint(1, 0) = fPos
        varPoint(1, 1) = fBottom - CONNECTOR_DISTANCE
        GeID = m_GeCtrl.CreatePolyline(varPoint)
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
        
        pDefNew.FillInDetails strConn, idxAttr_B, i, UserId   'Fill in Face, Order, UserID
        
    Case idxAttr_T
        UserId = i * 10 + idxAttr_T
        fPos = fPosIncrement * (i - 1) + fLeft + fOffset
        GeID = m_GeCtrl.CreateConnectionPoint(fPos, fTop + CONNECTOR_DISTANCE, strConn, ConType)
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
        
        GeID = m_GeCtrl.CreateText(fPos, fTop + 0.05, strConn) 'fltLeft, fltBottom, fltRight, fltTop
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
                
        varPoint(0, 0) = fPos
        varPoint(0, 1) = fTop
        varPoint(1, 0) = fPos
        varPoint(1, 1) = fTop + CONNECTOR_DISTANCE
        GeID = m_GeCtrl.CreatePolyline(varPoint)
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
        
        pDefNew.FillInDetails strConn, idxAttr_T, i, UserId   'Fill in Face, Order, UserID
                
    Case idxAttr_L
        UserId = i * 10 + idxAttr_L
        fPos = fTop - fPosIncrement * i + fOffset
        GeID = m_GeCtrl.CreateConnectionPoint(fLeft - CONNECTOR_DISTANCE, fPos, strConn, ConType)
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
        
        fTextPos = IIf(fPosIncrement < FONT_HEIGHT, fPos + fPosIncrement, fPos + FONT_HEIGHT)
        GeID = m_GeCtrl.CreateText(fLeft - 0.05, fTextPos, strConn)
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
        
        varPoint(0, 0) = fLeft - CONNECTOR_DISTANCE
        varPoint(0, 1) = fPos
        varPoint(1, 0) = fLeft
        varPoint(1, 1) = fPos
        GeID = m_GeCtrl.CreatePolyline(varPoint)
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
        
        pDefNew.FillInDetails strConn, idxAttr_L, i, UserId   'Fill in Face, Order, UserID
        
    Case idxAttr_R
        UserId = i * 10 + idxAttr_R
        fPos = fTop - fPosIncrement * i + fOffset
        GeID = m_GeCtrl.CreateConnectionPoint(fRight + CONNECTOR_DISTANCE, fPos, strConn, ConType)
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
                
        fTextPos = IIf(fPosIncrement < FONT_HEIGHT, fPos + fPosIncrement, fPos + FONT_HEIGHT)
        GeID = m_GeCtrl.CreateText(fRight + 0.05, fTextPos, strConn)
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
        
        varPoint(0, 0) = fRight
        varPoint(0, 1) = fPos
        varPoint(1, 0) = fRight + CONNECTOR_DISTANCE
        varPoint(1, 1) = fPos
        GeID = m_GeCtrl.CreatePolyline(varPoint)
        If GeID >= 0 Then AddAndSetUserID GeID, UserId, collId
        
        pDefNew.FillInDetails strConn, idxAttr_R, i, UserId   'Fill in Face, Order, UserID
  End Select
End Sub

Private Sub CheckForNonCodeGeneratedConnectors(collGeIDs As Collection, collUserIDs As Collection, collType As Collection, ByRef collGeIDsToRemove As Collection)

End Sub

Private Sub AddAndSetUserID(GeID As Long, UserId As Long, ByRef collId As Collection)
    collId.Add GeID
    SetUserIDForObject GeID, UserId
End Sub

'Enumerate fields of shape INSTANCE
Private Sub EnumShapeFields(ByVal GeID As Long)
    Dim strFldName As String
    Dim strFldValue As String
    Dim nFlds As Integer
    Dim iFld As Integer
    Dim nGeFldType As Integer
    Dim strMsg As String
    Dim strType As String
    
    On Error Resume Next
    If GeID > 0 Then
      ' move into selector and loop through all objects
      If m_GeCtrl.ShapeSetCurrent(GeID) Then
        nFlds = m_GeCtrl.ShapeFieldCount
        For iFld = 0 To nFlds - 1
          If m_GeCtrl.ShapeSetCurrentField(iFld) Then
            If m_GeCtrl.ShapeGetFieldNameValue(strFldName, strFldValue) Then
              '
              nGeFldType = m_GeCtrl.ShapeGetFieldType
              Select Case nGeFldType
                Case 2  ' 2 = ShapeField,
                  strType = "ShapeField "
                Case 1  ' 1 = TextField, 0 = invalid
                  strType = "TextField  "
                Case Else
                  strType = "Undefined ( " & nGeFldType & " )"
              End Select
    
              strMsg = "[" & Format(CStr(GeID), "@@@@@") & " " & _
                        Format(CStr(iFld), "@@@") & ", " & strType & "] " & _
                        strFldName & " : " & strFldValue
              Debug.Print strMsg
    
            End If
          End If
        Next iFld
      End If
    End If
End Sub

Private Sub EnumAllShapeObjects(GeIDShape As Long, ByRef RectangleGeID As Long, ByRef collConns As Collection)
    Dim aVar As Variant
    Dim iLow As Long
    Dim iHigh As Long
    Dim i As Long
    Dim iType As Integer
    Dim strType As String
    Dim strMsg As String
    Dim strFmt As String
    Dim oObjDetail As cgShapeComponentDetails
    Dim urX As Single, urY As Single, llX As Single, llY As Single
    Dim GeID As Long
    
    On Error Resume Next
    RectangleGeID = -1
    
    m_GeCtrl.SelRemoveAll
    m_GeCtrl.SelAdd GeIDShape
    ExplodeOrUngroupCurrentShape
'    m_GeCtrl.SelAddAll
    
    'm_GeCtrl.SelectAll
    m_GeCtrl.SelGetObjects aVar ' get sel IDs from CG
    iLow = LBound(aVar)
    iHigh = UBound(aVar)
    If err <> 0 Then Exit Sub ' if error, then probably nothing in array !
    
    strFmt = "#########0.00000"
    For i = iLow To iHigh
      Set oObjDetail = New cgShapeComponentDetails
      GeID = aVar(i)
      m_GeCtrl.CurrentPropertyID = GeID  ' move into selector
      m_GeCtrl.GetExtents llX, llY, urX, urY
      iType = m_GeCtrl.ObjectType
      FormatGeType iType, strType
     
      oObjDetail.iType = iType
      oObjDetail.GeID = GeID
      oObjDetail.SetExtents llX, llY, urX, urY
      oObjDetail.UserId = m_GeCtrl.ObjectUserID
     
      strMsg = strType & Format(CStr(GeID), "@@@@@") & " "
      strMsg = strMsg & " " & Format(llX, strFmt) & "," & Format(llY, strFmt) & "," & Format(urX, strFmt) & "," & Format(urY, strFmt)
'      Debug.Print strMsg
      
      Select Case iType
        Case EGeObjType.ObjConnector      ' ConnectionPoint
          Dim ConName As String           ' Tag (label) on Connector
          Dim ConType As Integer          ' Type - MUST be a POSITIVE VALUE!
          
          ConType = m_GeCtrl.connectorType
          ConName = m_GeCtrl.TagString
          oObjDetail.strName = m_GeCtrl.TagString
'          Debug.Print "ObjConnector -->" & vbTab & "Tag: " & ConName & "  ,  UserID: " & m_GeCtrl.ObjectUserID & "  ,  Type: " & ConType
        
        Case EGeObjType.TextField         ' TextField
          Dim strFldValue As String
          Dim strFldName As String
          
          strFldName = m_GeCtrl.TextString
          strFldValue = m_GeCtrl.TagString
          oObjDetail.strName = m_GeCtrl.TagString
'          Debug.Print "TextField -->" & vbTab & "Tag: " & strFldName & "  ,  Value: " & strFldValue & "  ,  UserID: " & m_GeCtrl.ObjectUserID
          
        Case EGeObjType.Rectangle      'Return GeID of Rectangle
          RectangleGeID = GetLargestRectangle(RectangleGeID, GeID)
          
        Case EGeObjType.Group           'For now treat a group as a possible bounding rectangle
          RectangleGeID = GetLargestRectangle(RectangleGeID, GeID)
          
        End Select
      
      ' HACK!!!!!!!!!
      ' When a shape is exploded, we get an extra 'shape' object ?????
      ' When a smart shape is exploded, get an extr UserGroup object ?????
      If Not oObjDetail.iType = EGeObjType.Shape And Not oObjDetail.iType = EGeObjType.UserGroup Then
        collConns.Add oObjDetail
      End If
      
      ' test for exception from CG
      If err <> 0 Then
        ShowStatusMsg Error
        Exit For
      End If
    Next i
    
    m_GeCtrl.CurrentPropertyID = 0      ' reset selector
'    m_GeCtrl.SelRemoveAll
'    m_GeCtrl.Delete
End Sub

Public Sub CalculateConnectionFaceAndOrder(RectangleGeID As Long, ByRef collConns As Collection)
    Dim i As Integer
    Dim oObjectDetails As cgShapeComponentDetails
    Dim urXRect As Single, urYRect As Single, llXRect As Single, llYRect As Single
    Dim iLeft As Integer, iRight As Integer, iBottom As Integer, iTop As Integer
    Dim collLeft As Collection, collRight As Collection, collBottom As Collection, collTop As Collection
    
    'Calculate the face
    For i = 1 To collConns.count
        Set oObjectDetails = collConns(i)
        
        m_GeCtrl.CurrentPropertyID = RectangleGeID
        m_GeCtrl.GetExtents llXRect, llYRect, urXRect, urYRect
        m_GeCtrl.CurrentPropertyID = 0
        
        If oObjectDetails.strName <> "" Then
            If oObjectDetails.llX < (llXRect + RECTANGLE_TOLERANCE) Then
                oObjectDetails.iFace = idxAttr_L
            ElseIf oObjectDetails.urX > (urXRect - RECTANGLE_TOLERANCE) Then
                oObjectDetails.iFace = idxAttr_R
            ElseIf oObjectDetails.llY < (llYRect + RECTANGLE_TOLERANCE) Then
                oObjectDetails.iFace = idxAttr_B
            ElseIf oObjectDetails.urY > (urYRect - RECTANGLE_TOLERANCE) Then
                oObjectDetails.iFace = idxAttr_T
            Else
                'TODO: This should be the 'Unknown' case
                If oObjectDetails.iType = EGeObjType.ObjConnector Then
                    gMsgWnd.LogMessage "Failed to retrieve face for connector " & oObjectDetails.strName
                End If
            End If
        End If
    Next i
    
    'Calculate the order
    Set collLeft = New Collection
    Set collRight = New Collection
    Set collBottom = New Collection
    Set collTop = New Collection
       
    'Sepparate into ordered collections corresponding to face
    For i = 1 To collConns.count
        Set oObjectDetails = collConns(i)
        If oObjectDetails.iType = EGeObjType.ObjConnector Then
            Select Case oObjectDetails.iFace
                Case idxAttr_L
                    AddToLeftCollection collLeft, oObjectDetails
                Case idxAttr_R
                    AddToRightCollection collRight, oObjectDetails
                Case idxAttr_B
                    AddToBottomCollection collBottom, oObjectDetails
                Case idxAttr_T
                    AddToTopCollection collTop, oObjectDetails
            End Select
        End If
    Next i
    
    'Now fill in the order field
    FillInConnectionOrderField collLeft
    FillInConnectionOrderField collRight
    FillInConnectionOrderField collBottom
    FillInConnectionOrderField collTop
    
    Set collLeft = Nothing
    Set collRight = Nothing
    Set collBottom = Nothing
    Set collTop = Nothing
End Sub

Private Sub SetUserIDForObject(ByVal GeID As Long, ByVal UserId As Long)
  ' set the userID
  ' move into selector, set userID
  On Error Resume Next
  If GeID > 0 Then
    m_GeCtrl.CurrentPropertyID = GeID
    m_GeCtrl.ObjectUserID = UserId
    m_GeCtrl.CurrentPropertyID = 0   ' remember to reset
  End If
End Sub

Private Function GetUserIDForObject(ByVal GeID As Long) As Long
  ' get the userID
  On Error Resume Next
  If GeID > 0 Then
    m_GeCtrl.CurrentPropertyID = GeID
    GetUserIDForObject = m_GeCtrl.ObjectUserID
    m_GeCtrl.CurrentPropertyID = 0   ' remember to reset
  End If
End Function

Private Sub FormatGeType(iType As Integer, strType As String)
  '
  Dim strTmp As String
  strType = GeWorker.GetGeObjectType_Str(iType)
  
  strTmp = "(" & Format(CStr(iType), "@@") & ")"
  strType = Format(strType, "!@@@@@@@@@@@@@@@@@") ' left aligned
  strType = strTmp & " " & strType
End Sub

Private Function GetLargestRectangle(CurrentRectGeID As Long, GeID As Long) As Long
    Dim urX As Single, urY As Single, llX As Single, llY As Single
    Dim urX2 As Single, urY2 As Single, llX2 As Single, llY2 As Single
    Dim lWidthNew As Single, lHeightNew As Single, lWidthCurr As Single, lHeightCurr As Single
    Dim lWidthDiff As Single, lHeightDiff As Single
    
    On Error Resume Next
    
    If CurrentRectGeID < 0 Then
        GetLargestRectangle = GeID
        Exit Function
    End If
      
    m_GeCtrl.CurrentPropertyID = CurrentRectGeID
    m_GeCtrl.GetExtents llX, llY, urX, urY        'Leave this one in the selector
    m_GeCtrl.CurrentPropertyID = 0
    
    m_GeCtrl.CurrentPropertyID = GeID
    m_GeCtrl.GetExtents llX2, llY2, urX2, urY2

    lWidthNew = urX - llX
    lHeightNew = urY - llY
    
    lWidthCurr = urX2 - llX2
    lHeightCurr = urY2 - llY2
    
    If (lWidthNew > lWidthCurr) And (lHeightNew > lHeightCurr) Then
      GetLargestRectangle = GeID
      Exit Function
    ElseIf (lWidthNew < lWidthCurr) And (lHeightNew < lHeightCurr) Then
      GetLargestRectangle = CurrentRectGeID
      Exit Function
    End If
      
    'See if the two differ more by width, or height
    lWidthDiff = Abs(lWidthNew - lWidthCurr)
    lHeightDiff = Abs(lHeightNew - lHeightCurr)
    
    If lWidthDiff > lHeightDiff Then    'The width is the deciding factor
        GetLargestRectangle = IIf(lWidthNew > lWidthCurr, GeID, CurrentRectGeID)
    Else                                'The height is the deciding factor
        GetLargestRectangle = IIf(lHeightNew > lHeightCurr, GeID, CurrentRectGeID)
    End If
End Function

Private Sub GetRectangleSize(ByRef lx As Single, ByRef ly As Single, ByRef ux As Single, ByRef uy As Single, cgDetailInfo As cgLibraryShapeDetails)
    Dim iTop As Integer, iBottom As Integer, iLeft As Integer, iRight As Integer
    Dim i As Integer
    Dim lConnSpacing As Single
    Dim lTop As Single, lBottom, lLeft As Single, lRight As Single
    
    On Error Resume Next
    iTop = 0
    iBottom = 0
    iLeft = 0
    iRight = 0
    
    For i = 1 To cgDetailInfo.m_collFace.count
        Select Case cgDetailInfo.m_collFace(i)
            Case "1":
                iLeft = iLeft + 1
            Case "2":
                iRight = iRight + 1
            Case "3":
                iTop = iTop + 1
            Case "4":
                iBottom = iBottom + 1
        End Select
    Next i

    lConnSpacing = cgDetailInfo.m_ConnectorSpacing
    
    lTop = iTop * lConnSpacing
    lBottom = iBottom * lConnSpacing
    lLeft = iLeft * lConnSpacing
    lRight = iRight * lConnSpacing
    
    lTop = IIf(lTop < MIN_FACE_SIZE, MIN_FACE_SIZE, lTop)
    lBottom = IIf(lBottom < MIN_FACE_SIZE, MIN_FACE_SIZE, lBottom)
    lLeft = IIf(lLeft < MIN_FACE_SIZE, MIN_FACE_SIZE, lLeft)
    lRight = IIf(lRight < MIN_FACE_SIZE, MIN_FACE_SIZE, lRight)
    
    lx = BOTTOM_POS
    ly = LEFT_POS
    ux = IIf(lBottom > lTop, BOTTOM_POS + lBottom, BOTTOM_POS + lTop)
    uy = IIf(lLeft > lRight, LEFT_POS + lLeft, LEFT_POS + lRight)
    
    'In case there were no connectors on both sides
    ux = IIf(ux = 0, MIN_FACE_SIZE, ux)
    uy = IIf(uy = 0, MIN_FACE_SIZE, uy)
End Sub

Private Sub CloseLibrary()
  On Error Resume Next
  If m_GeLbrMgr Is Nothing Then Exit Sub
  
  If Not m_GeLbrMgr Is Nothing Then
    m_GeLbrMgr.CloseLibrary   ' don't forget to close it (although it will be done when the class terminates)
  End If
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Sub

Public Function OpenLibrary(strLibrary As String) As Boolean
  Dim bReadonly As Boolean
  On Error Resume Next
  
  OpenLibrary = False
  If m_GeLbrMgr Is Nothing Then Exit Function
  
  If Not m_GeLbrMgr.IsOpened Then
    bReadonly = False
    OpenLibrary = m_GeLbrMgr.OpenLibrary(strLibrary, bReadonly)
  Else
    OpenLibrary = True
  End If
  
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

Private Sub SetFontDetail(ByRef fPosIncrement As Single, iAlignment As Single, iOrientation As Single)
    If FONT_HEIGHT <= (fPosIncrement - 0.02) Then
        m_GeCtrl.FontHeight = FONT_HEIGHT
    Else
        m_GeCtrl.FontHeight = fPosIncrement - 0.02
    End If
    m_GeCtrl.ScaleMode = 1                   '1 = Proportional
    m_GeCtrl.FontAlignment = iAlignment      '0 = Left, 1 = Middle, 2 = Right
    m_GeCtrl.FontOrientation = iOrientation
    m_GeCtrl.FontEscapement = iOrientation
End Sub

Private Sub ExplodeOrUngroupCurrentShape()
    If m_GeCtrl.CanExplodeSmartShape Then
        m_GeCtrl.Ungroup
    ElseIf m_GeCtrl.CanExplodeShape Then
        m_GeCtrl.OnExplodeShape
    Else
        gMsgWnd.LogMessage "Cannot explode shape"
    End If
End Sub

Public Function GetFirstAttachedCGLibrary() As String
  ' 1st library attached to CG
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim i As Integer
  Dim strLibPath As String
  Dim aLibraries As Variant

  On Error Resume Next
  If Not SetGeCtrl() Then Exit Function
  
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
  GetFirstAttachedCGLibrary = strLibPath
End Function

Private Function VERIFY_ERR() As Boolean
  VERIFY_ERR = True
  If Not err = 0 Then
      #If APP_DEBUG Then
        Dim strMsg As String
        strMsg = "VERIFY_ERR Failed:" & Error
        ShowStatusMsg strMsg
      #End If
    VERIFY_ERR = False
  End If
End Function

'------------------------------------------------------------------------------------------------------

