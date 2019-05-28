Attribute VB_Name = "mShapeLibHelper"
Private Const LEFT_POS = 1
Private Const BOTTOM_POS = 1
Private Const RIGHT_POS = 2
Private Const TOP_POS = 2
Private Const SHAPELABEL_HEIGHT = 0.2
Private Const CONNECTOR_DISTANCE = 0.5
Private Const LABEL_DISTANCE = 0.15
Private Const FONT_HEIGHT = 0.13
Private Const PEN_BLACK = 185
Private Const SHAPENAME_USERID = 999999
Private Const SHAPERECTANGLE_USERID = 888888
Private Const VERTICAL_FONT_ORIENTATION = 4.712389

'These can be found in mGEConst
Private Const GE_POLYLINE = 7
Private Const GE_RECTANGLE = 9
Private Const GE_GROUP = 11
Private Const GE_TEXT = 12
Private Const GE_TERXTFIELD = 14
Private Const GE_CONNECTOR = 22

Private GeCtrl As CG
Private m_UserID As Long

Public Sub SetModuleGeCtrl(oGeCtrl As CG)
    Set GeCtrl = oGeCtrl
End Sub

Public Function RenameShape(cgDetails As cgLibraryShapeDetails, m_GeLbrMgr As GeLibraryMgr) As Boolean
    Dim rst As Recordset
    Dim strSQL As String
    Dim GeID As Long, GeIDRemove As Long, GeIDRectangle As Long
    Dim UserID As Long, UserIDMe As Long
    Dim bAltered As Boolean
    Dim strLibAndFolder As String
    Dim fInsertionPointX As Single, fInsertionPointY As Single
    Dim fBottomPos As Single, fTopPos As Single
    Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
    
    On Error GoTo Error_Handler
    RenameShape = False
    GeIDRemove = -1
    GeIDRectangle = -1
    
    If m_GeLbrMgr Is Nothing Then Exit Function
    If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
      
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
    
    If Not RenameShape Then Exit Function
    If GeCtrl Is Nothing Then Exit Function
    bAltered = False
    
    GeCtrl.GrabHandlesEnabled = False
    GeCtrl.RedrawEnabled = False
    GeCtrl.SelRemoveAll
        
    fTopPos = TOP_POS - (Abs(TOP_POS - BOTTOM_POS - SHAPELABEL_HEIGHT) / 2)
    fBottomPos = BOTTOM_POS + (Abs(TOP_POS - BOTTOM_POS - SHAPELABEL_HEIGHT) / 2)
    ShapeGeID = GeCtrl.CreateShape(cgDetails.m_UDIDefOriginal.GeLibrary, cgDetails.m_UDIDefOriginal.GeFolder, cgDetails.strShapeName, fTopPos, fBottomPos)
    If ShapeGeID <= 0 Then GoTo CleanUp_GeCtrl
    
    GeCtrl.SelAdd ShapeGeID
    GeCtrl.ShapeSetCurrent ShapeGeID
    ExplodeOrUngroupCurrentShape
    
    ObjGeID = GeCtrl.GetFirstSelObject
    While ObjGeID > 0
       UserIDMe = GetUserIDForObject(ObjGeID)
       If UserIDMe = SHAPENAME_USERID Then
            GeIDRemove = ObjGeID
       End If
       If UserIDMe = SHAPERECTANGLE_USERID Then
            GeIDRectangle = ObjGeID
       End If
       ObjGeID = GeCtrl.GetNextSelObject(ObjGeID)
    Wend
    
    If GeIDRemove > 0 Then
        'Create New Name Field and add it.
        GeCtrl.CurrentPropertyID = GeIDRectangle
        GeCtrl.GetExtents fLeft, fBottom, fRight, fTop
        GeCtrl.CurrentPropertyID = 0
                
        'Remove old text field
        GeCtrl.SelRemove GeIDRemove
        
        SetFontDetail FONT_HEIGHT, 1, 0
        fTopPos = fTop - (Abs(fTop - fBottom - SHAPELABEL_HEIGHT) / 2)
        fBottomPos = fBottom + (Abs(fTop - fBottom - SHAPELABEL_HEIGHT) / 2)
        GeID = GeCtrl.CreateTextField(fLeft + 0.05, fBottomPos, fRight - 0.05, fTopPos, cgDetails.strShapeNameNew, cgDetails.strShapeNameNew) 'fltLeft, fltBottom, fltRight, fltTop
        If GeID >= 0 Then
            SetUserIDForObject GeID, SHAPENAME_USERID
            GeCtrl.SelAdd GeID
            bAltered = True
        End If
    End If
    
    If bAltered Then    'Recreate the shape
        strLibAndFolder = m_GeLbrMgr.LibrayName & "!" & cgDetails.m_UDIDefOriginal.GeFolder
        fInsertionPointX = fLeft + Abs(fRight - fLeft) / 2
        fInsertionPointY = fBottom + Abs(fTop - fBottom) / 2
        If Not CreateShapeDef(strLibAndFolder, cgDetails.strShapeNameNew, fInsertionPointX, fInsertionPointY) Then
            GoTo CleanUp_GeCtrl
        End If
        
        If GeIDRemove > 0 Then
            GeCtrl.SelRemoveAll
            GeCtrl.SelAdd GeIDRemove
            GeCtrl.Delete
            GeIDRemove = -1
        End If
    End If
    
    If err = 3022 Then
      MsgBox "Mask already exists!", vbExclamation, "Error Renaming Mask"
      err = 0
    End If
        
CleanUp_GeCtrl:
    GeCtrl.SelRemoveAll
    If GeIDRemove > 0 Then
        GeCtrl.SelAdd GeIDRemove
        GeCtrl.Delete
    End If
    GeCtrl.GrabHandlesEnabled = True    ' turn em back on
    GeCtrl.RedrawEnabled = True
    GeCtrl.Redraw
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
    Dim ShapeID As Long
    
    On Error GoTo Error_Handler
    DeleteShape = False
          
    If m_GeLbrMgr Is Nothing Then Exit Function
    If m_GeLbrMgr.LibDB Is Nothing Then Exit Function
    
    strSQL = "SELECT * "
    strSQL = strSQL & "From GeTblShape Where ShapeName = '" & cgDetails.strShapeName & "' and FolderID = " & cgDetails.lFolderID
    Set rst = m_GeLbrMgr.LibDB.OpenRecordset(strSQL, dbOpenDynaset)
    
    With rst
      If .RecordCount = 1 Then
        ShapeID = !ShapeID
        If Not GeCtrl Is Nothing Then
            GeCtrl.SelRemoveAll
            GeCtrl.SelAdd ShapeID
            GeCtrl.Delete
            GeCtrl.SelRemoveAll
        End If
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
   
    If m_GeLbrMgr Is Nothing Then Exit Function
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

'----------------------------------------------------------------------------------------------
' The following functions taken from Andy's auto shape gen. examples
'----------------------------------------------------------------------------------------------

Public Function AutoGenerateShape(strShape As String, strFolder As String, strFolderID As String, m_GeLbrMgr As GeLibraryMgr, cgDetailInfo As cgLibraryShapeDetails) As Boolean
  Dim ptX As Single, ptY As Single
  Dim fltLeft As Single, fltBottom As Single, fltRight As Single, fltTop As Single
  Dim fInsertionPointX As Single, fInsertionPointY As Single
  Dim fBottomPos As Single, fTopPos As Single
  Dim GeID As Long, UserID As Long
  Dim GeIDRectangle As Long
  Dim collID As New Collection  ' We need to keep track of all ids of things that I create (using collID)
  Dim ndxOrig As Long           ' original default color (that user had selected)
  Dim strLibAndFolder As String
  Dim fLabelDistance As Single
  Dim i As Integer
  
  On Error GoTo Error_Handler
  AutoGenerateShape = False
  m_UserID = 1
  
  If m_GeLbrMgr Is Nothing Then Exit Function
  If m_GeLbrMgr.LibDB Is Nothing Then Exit Function

  GeCtrl.RedrawEnabled = False
  GeCtrl.GrabHandlesEnabled = False  ' turn em off so user doesn't get excited

  ndxOrig = GeCtrl.PenColor     ' trap so can restore
  GeCtrl.PenColor = PEN_BLACK
         
  GeID = GeCtrl.CreateRectangle(LEFT_POS, BOTTOM_POS, RIGHT_POS, TOP_POS)
  If GeID >= 0 Then
        GeIDRectangle = GeID
        AddAndSetUserID GeID, SHAPERECTANGLE_USERID, collID
        
        'Add shape name
        SetFontDetail FONT_HEIGHT, 1, 0
        fTopPos = TOP_POS - (Abs(TOP_POS - BOTTOM_POS - SHAPELABEL_HEIGHT) / 2)
        fBottomPos = BOTTOM_POS + (Abs(TOP_POS - BOTTOM_POS - SHAPELABEL_HEIGHT) / 2)
        GeID = GeCtrl.CreateTextField(LEFT_POS + 0.05, fBottomPos, RIGHT_POS - 0.05, fTopPos, strShape, strShape) 'fltLeft, fltBottom, fltRight, fltTop
        If GeID >= 0 Then AddAndSetUserID GeID, SHAPENAME_USERID, collID

        If Not cgDetailInfo Is Nothing Then
            If Not CreateAndAddConnectors(cgDetailInfo, GeIDRectangle, collID) Then
                gMsgWnd.LogMessage "Failed to add connectors during mask '" & strShape & "' auto generation."
                GoTo CleanUp_GeCtrl
            End If
        End If
  Else
      gMsgWnd.LogMessage "Failed to create rectangle for auto generated shape."
      GoTo CleanUp_GeCtrl
  End If
      
  AddMyObjectsToSelection collID    ' add all I created to the Selection List
  fInsertionPointX = LEFT_POS + Abs(RIGHT_POS - LEFT_POS) / 2
  fInsertionPointY = BOTTOM_POS + Abs(TOP_POS - BOTTOM_POS) / 2
  strLibAndFolder = m_GeLbrMgr.LibrayName & "!" & strFolder
  If Not CreateShapeDef(strLibAndFolder, strShape, fInsertionPointX, fInsertionPointY) Then
      GoTo CleanUp_GeCtrl
  End If
  
  AutoGenerateShape = True
  
CleanUp_GeCtrl:
  GeCtrl.Delete
  GeCtrl.SelRemoveAll
  GeCtrl.PenColor = ndxOrig           ' restore Default Pen color
  GeCtrl.GrabHandlesEnabled = True    ' turn em back on
  GeCtrl.RedrawEnabled = True
  GeCtrl.Redraw
  
  Exit Function
Error_Handler:
  gMsgWnd.LogMessage "Failed to auto generate shape " & strShape & ": " & err.Description
 End Function
  
'Walk the connector list, and create the appropriate connections.  Add them to the collection of selected objects.
Private Function CreateAndAddConnectors(ByRef cgDetailInfo As cgLibraryShapeDetails, GeIDRectangle As Long, ByRef collID As Collection)
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
       CreateConnection fPosIncrement, fOffset, collBottom, i, collID, idxAttr_B, GeIDRectangle, pDef
    Next i
    
    'Top Connectors
    If collTop.count > 0 Then
       fPosIncrement = GetConnectorSpacing(collTop.count, szAttr_T, GeIDRectangle)
       SetFontDetail fPosIncrement, 2, VERTICAL_FONT_ORIENTATION 'This constant seems to be for vertical text
       fOffset = fPosIncrement / 2
    End If
    For i = 1 To collTop.count
       CreateConnection fPosIncrement, fOffset, collTop, i, collID, idxAttr_T, GeIDRectangle, pDef
    Next i
    
    'Left Connectors
    If collLeft.count > 0 Then
       fPosIncrement = GetConnectorSpacing(collLeft.count, szAttr_L, GeIDRectangle)
       SetFontDetail fPosIncrement, 2, 0
       fOffset = fPosIncrement / 2
    End If
    For i = 1 To collLeft.count
       CreateConnection fPosIncrement, fOffset, collLeft, i, collID, idxAttr_L, GeIDRectangle, pDef
    Next i
    
    'Right Connectors
    If collRight.count > 0 Then
       fPosIncrement = GetConnectorSpacing(collRight.count, szAttr_R, GeIDRectangle)
       SetFontDetail fPosIncrement, 0, 0
       fOffset = fPosIncrement / 2
    End If
    For i = 1 To collRight.count
       CreateConnection fPosIncrement, fOffset, collRight, i, collID, idxAttr_R, GeIDRectangle, pDef
    Next i
    
    Set collBottom = Nothing
    Set collTop = Nothing
    Set collLeft = Nothing
    Set collRight = Nothing
    
    CreateAndAddConnectors = True
  
  Exit Function
Error_Handler:
  gMsgWnd.LogMessage "Failed to add connectors for auto generated shape " & strShape & ": " & err.Description
End Function
 
Public Function DeleteConnectors(collDel As Collection, cgDetails As cgLibraryShapeDetails, m_GeLbrMgr As GeLibraryMgr) As Boolean
    Dim ShapeGeID As Long, ObjGeID As Long
    Dim i As Integer, j As Integer
    Dim UserID As Long, UserIDMe As Long
    Dim bAltered As Boolean
    Dim strLibAndFolder As String
    Dim fInsertionPointX As Single, fInsertionPointY As Single
    Dim collGeIDs As Collection
    Dim collUserIDs As Collection
    Dim collGeIDsToRemove As Collection
    Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
    Dim GeIDRectangle As Single
    
    On Error GoTo Error_Handler
    deleteConnector = False
    bAltered = False
    GeIDRectangle = -1
    
    Set m_collEnumUserID = Nothing
    Set m_collEnumGeID = Nothing
    GeCtrl.GrabHandlesEnabled = False
    GeCtrl.RedrawEnabled = False
    
    GeCtrl.SelRemoveAll
    
    ShapeGeID = GeCtrl.CreateShape(cgDetails.m_UDIDefOriginal.GeLibrary, cgDetails.m_UDIDefOriginal.GeFolder, cgDetails.m_UDIDefOriginal.GeShape, 1, 1)
    If ShapeGeID <= 0 Then Exit Function
    
    GeCtrl.SelAdd ShapeGeID
    GeCtrl.ShapeSetCurrent ShapeGeID
    ExplodeOrUngroupCurrentShape
    
    Set collGeIDs = New Collection
    Set collUserIDs = New Collection
    Set collGeIDsToRemove = New Collection
    
    'Populate 2 collection, one with all the GeID's in this shape, and one with the matching UserID's
    ObjGeID = GeCtrl.GetFirstSelObject
    While ObjGeID > 0
        collGeIDs.Add ObjGeID
        UserIDMe = GetUserIDForObject(ObjGeID)
        collUserIDs.Add UserIDMe
        If UserIDMe = SHAPERECTANGLE_USERID Then
            GeIDRectangle = ObjGeID
        End If
        ObjGeID = GeCtrl.GetNextSelObject(ObjGeID)
    Wend
            
    For i = 1 To collDel.count
        UserID = collDel(i)
        If UserID > 0 Then
            For j = 1 To collUserIDs.count
                If collUserIDs(j) = UserID Then
                    collGeIDsToRemove.Add collGeIDs(j)
                    GeCtrl.SelRemove collGeIDs(j)
                    bAltered = True
                End If
            Next j
        End If
    Next i
                
    If bAltered Then    'Recreate the shape
        'Create New Name Field and add it.
        GeCtrl.CurrentPropertyID = GeIDRectangle
        GeCtrl.GetExtents fLeft, fBottom, fRight, fTop
        GeCtrl.CurrentPropertyID = 0
    
        strLibAndFolder = m_GeLbrMgr.LibrayName & "!" & cgDetails.m_UDIDefOriginal.GeFolder
        fInsertionPointX = fLeft + Abs(fRight - fLeft) / 2
        fInsertionPointY = fBottom + Abs(fTop - fBottom) / 2
        If Not CreateShapeDef(strLibAndFolder, cgDetails.m_UDIDefOriginal.GeShape, fInsertionPointX, fInsertionPointY) Then
            GoTo CleanUp_GeCtrl
        End If
    End If
    
    If bAltered Then
        GeCtrl.SelRemoveAll
        For i = 1 To collGeIDsToRemove.count
            GeCtrl.SelAdd collGeIDsToRemove(i)
        Next i
        GeCtrl.Delete
        bAltered = False
    End If
    
    deleteConnector = True
    
CleanUp_GeCtrl:
    GeCtrl.Delete
    GeCtrl.SelRemoveAll
    If bAltered Then
        For i = 1 To collGeIDsToRemove.count
            GeCtrl.SelAdd collGeIDsToRemove(i)
        Next i
        GeCtrl.Delete
    End If
    GeCtrl.GrabHandlesEnabled = True    ' turn em back on
    GeCtrl.RedrawEnabled = True
    GeCtrl.Redraw
    
    Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Failed to Delete Connector: " & err.Description
    GoTo CleanUp_GeCtrl
End Function

Public Function AddConnectors(collAdd As Collection, ByRef cgDetails As cgLibraryShapeDetails, m_GeLbrMgr As GeLibraryMgr) As Boolean
   Dim ShapeGeID As Long, ObjGeID As Long
    Dim i As Integer, j As Integer, k As Integer
    Dim UserID As Long, UserIDMe As Long
    Dim strLibAndFolder As String
    Dim fInsertionPointX As Single, fInsertionPointY As Single
    Dim collGeIDsToRemove As Collection
    Dim collGeIDs As Collection, collUserIDs As Collection, collTypes As Collection
    Dim strConnAdd As String
    Dim collBottom As Collection, collTop As Collection, collLeft As Collection, collRight As Collection
    Dim fPosIncrement As Single
    Dim fOffset As Single
    Dim collID As Collection
    Dim strConn As String
    Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
    Dim GeIDRectangle As Long
  
    On Error GoTo Error_Handler
    AddConnectors = False
    
    Set m_collEnumUserID = Nothing
    Set m_collEnumGeID = Nothing
    GeCtrl.GrabHandlesEnabled = False
    GeCtrl.RedrawEnabled = False
    GeCtrl.SelRemoveAll
    
    ShapeGeID = GeCtrl.CreateShape(cgDetails.m_UDIDefOriginal.GeLibrary, cgDetails.m_UDIDefOriginal.GeFolder, cgDetails.m_UDIDefOriginal.GeShape, 2, 2)
    If ShapeGeID <= 0 Then Exit Function
    
    GeCtrl.SelAdd ShapeGeID
    GeCtrl.ShapeSetCurrent ShapeGeID
    ExplodeOrUngroupCurrentShape
    
    Set collGeIDs = New Collection
    Set collUserIDs = New Collection
    Set collTypes = New Collection
    Set collGeIDsToRemove = New Collection
    
    'Populate 2 collection, one with all the GeID's in this shape, and one with the matching UserID's
    ObjGeID = GeCtrl.GetFirstSelObject
    While ObjGeID > 0
        collGeIDs.Add ObjGeID
        UserIDMe = GetUserIDForObject(ObjGeID)
        collUserIDs.Add UserIDMe
        If UserIDMe = SHAPERECTANGLE_USERID Then
            GeIDRectangle = ObjGeID
        End If
        ObjGeID = GeCtrl.GetNextSelObject(ObjGeID)
    Wend
            
    ObjGeID = GeCtrl.GetFirstSelObject
    While ObjGeID > 0
        GeCtrl.CurrentPropertyID = ObjGeID
        If GeIDRectangle <= 0 Then
            If GeCtrl.ObjectType = GE_RECTANGLE Then GeIDRectangle = ObjGeID                          'If Type = Rectangle
            If GeCtrl.ObjectType = GE_GROUP And GeIDRectangle <= 0 Then GeIDRectangle = ObjGeID   'If Type = Group
        End If
        collTypes.Add GeCtrl.ObjectType
        GeCtrl.CurrentPropertyID = 0
        ObjGeID = GeCtrl.GetNextSelObject(ObjGeID)
    Wend
    
    CheckForNonCodeGeneratedConnectors collGeIDs, collUserIDs, collTypes, collGeIDsToRemove
    If collGeIDsToRemove.count > 0 Then bAltered = True
            
    'Populate list of GeIDs (corresponding to all connectors) that will need to be removed
    For i = 1 To cgDetails.m_UDIDefOriginal.CgConnectionDefs.count
        UserID = cgDetails.m_UDIDefOriginal.CgConnectionDefs(i).UserID
        If UserID > 0 Then
            For j = 1 To collUserIDs.count
                If collUserIDs(j) = UserID Then
                    collGeIDsToRemove.Add collGeIDs(j)
                    GeCtrl.SelRemove collGeIDs(j)
                    bAltered = True
                End If
            Next j
        End If
    Next i
            
    Set collID = New Collection
    
    'Recreate all the connectors
    If Not cgDetails Is Nothing Then
        If Not CreateAndAddConnectors(cgDetails, GeIDRectangle, collID) Then
            gMsgWnd.LogMessage "Failed to add connectors during shape '" & strShape & "' auto generation."
            GoTo CleanUp_GeCtrl
        End If
    End If

    If GeIDRectangle > 0 Then
        GeCtrl.CurrentPropertyID = GeIDRectangle
        GeCtrl.GetExtents fLeft, fBottom, fRight, fTop
        GeCtrl.CurrentPropertyID = 0
    Else
        fLeft = LEFT_POS
        fBottom = BOTTOM_POS
        fRight = RIGHT_POS
        fTop = TOP_POS
    End If
    
    AddMyObjectsToCurrentSelection collID
    strLibAndFolder = m_GeLbrMgr.LibrayName & "!" & cgDetails.m_UDIDefOriginal.GeFolder
    fInsertionPointX = fLeft + Abs(fRight - fLeft) / 2
    fInsertionPointY = fBottom + Abs(fTop - fBottom) / 2
    If Not CreateShapeDef(strLibAndFolder, cgDetails.m_UDIDefOriginal.GeShape, fInsertionPointX, fInsertionPointY) Then
        GoTo CleanUp_GeCtrl
    End If
    
    'Remove left over 'old' connectors
    If bAltered Then
        GeCtrl.SelRemoveAll
        For i = 1 To collGeIDsToRemove.count
            GeCtrl.SelAdd collGeIDsToRemove(i)
        Next i
        GeCtrl.Delete
        bAltered = False
    End If
    
CleanUp_GeCtrl:
    GeCtrl.Delete
    GeCtrl.SelRemoveAll
    If bAltered Then
        For i = 1 To collGeIDsToRemove.count
            GeCtrl.SelAdd collGeIDsToRemove(i)
        Next i
        GeCtrl.Delete
    End If
    GeCtrl.GrabHandlesEnabled = True    ' turn em back on
    GeCtrl.RedrawEnabled = True
    GeCtrl.Redraw
    
    AddConnectors = True
    Exit Function
Error_Handler:
    gMsgWnd.LogMessage "Failed to add Connector: " & err.Description
    GoTo CleanUp_GeCtrl
End Function

Public Function GetConnectionFaceAndOrder(strLibrary As String, strFolder As String, strShape As String, cgConn As CgConnectionDef, strObjectName As String) As Boolean
  Dim UserID As Long
  Dim GeID As Long, GeIDTemp As Long
  Dim i As Integer
  Dim iLen As Integer
  Dim strUserID As String
  Dim strName As String
  Dim oArray
  
  On Error Resume Next
  GetConnectionFaceAndOrder = False
  GeCtrl.SelRemoveAll
  UserID = -1

  'When the connector's connection point was created, the shape name was attached to insure a unique identifier.
  'The userID's last 2 numbers specify the order (first number) and the Face (second number)
  GeID = GeCtrl.GetIDFromName(cgConn.connName & "!" & strObjectName, 0)
  If GeID <= 0 Then
     GeCtrl.GrabHandlesEnabled = False
     GeCtrl.RedrawEnabled = False
     GeIDTemp = GeCtrl.CreateShape(strLibrary, strFolder, strShape, 1, 1)
     If GeIDTemp >= 0 Then
        GeCtrl.SelAdd GeIDTemp
        
        ExplodeOrUngroupCurrentShape
        GeIDTemp = GeCtrl.GetFirstSelObject
        While GeIDTemp > 0
          GeCtrl.CurrentPropertyID = GeIDTemp
          If GeCtrl.ObjectUserID > 0 Then
           strName = GeCtrl.TextString
           If strName = cgConn.connName Then
                GeID = GeIDTemp
                UserID = GeCtrl.ObjectUserID
                GeCtrl.CurrentPropertyID = 0
                GeCtrl.Delete
                GeCtrl.SelRemoveAll
                GeCtrl.GrabHandlesEnabled = True
                GeCtrl.RedrawEnabled = True
                GoTo Exit_While
           End If
          End If
          GeCtrl.CurrentPropertyID = 0
          GeIDTemp = GeCtrl.GetNextSelObject(GeIDTemp)
        Wend
        GeCtrl.Delete
        GeCtrl.SelRemoveAll
        GeCtrl.GrabHandlesEnabled = True
        GeCtrl.RedrawEnabled = True
    End If
  End If
  
Exit_While:
  If GeID > 0 Then
    GeCtrl.CurrentPropertyID = GeID
    
    If UserID <= 0 Then UserID = GeCtrl.ObjectUserID
    If UserID > 0 Then
        strUserID = CStr(UserID)
        strUserID = Right(strUserID, 2)
        If Len(strUserID) >= 2 Then
            cgConn.order = CInt(Left(strUserID, 1))
            cgConn.Face = CInt(Right(strUserID, 1))
            cgConn.UserID = UserID
            GetConnectionFaceAndOrder = True
            Debug.Print cgConn.connName & " - " & cgConn.UserID & " Face: " & cgConn.Face & " Order: " & cgConn.order
        End If
    End If
  End If
End Function

Public Sub VerifyConnectorsForChangedShape(strShape As String, strFolder As String)
    'TODO: We need a way to retrieve manual connector changes to the shape, and adjust our connector lists.
End Sub

Private Function GetConnectorSpacing(iConnNum As Integer, szFace As String, GeIDRectangle As Long) As Single
    Dim fAvailableLength As Single
    Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
      
    If GeIDRectangle > 0 Then
      GeCtrl.CurrentPropertyID = GeIDRectangle
      GeCtrl.GetExtents fLeft, fBottom, fRight, fTop
      GeCtrl.CurrentPropertyID = 0
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
    
    If szFace = szAttr_B Or szAttr_B = szAttr_T Then
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
  
 Private Sub AddMyObjectsToSelection(collID As Collection)
 ' add all in coll to selection
  Dim i As Long
  Dim GeID As Long
  
  On Error Resume Next
  GeCtrl.SelRemoveAll
  For i = 1 To collID.count
    GeID = collID.Item(i)
    GeCtrl.SelAdd GeID
  Next i
End Sub

 Private Sub AddMyObjectsToCurrentSelection(collID As Collection)
 ' add all in coll to selection
  Dim i As Long
  Dim GeID As Long
  
  On Error Resume Next
  For i = 1 To collID.count
    GeID = collID.Item(i)
    GeCtrl.SelAdd GeID
  Next i
End Sub

Private Function CreateRectangle(fltLeft As Single, fltBottom As Single, fltRight As Single, fltTop As Single, GeID As Long) As Boolean
  ' create a Shape Instance
  On Error Resume Next
  GeID = GeCtrl.CreateRectangle(fltLeft, fltBottom, fltRight, fltTop)
  CreateRectangle = VERIFY_ERR
End Function

Private Function CreateShape(strLibrary As String, strFolder As String, strShape As String, ptX As Single, ptY As Single, GeID As Long) As Boolean
  ' create a Shape Instance
  On Error Resume Next
  GeID = GeCtrl.CreateShape(m_strLibrary, m_strCoreFolder, strShape, ptX, ptY)
  CreateShape = VERIFY_ERR
End Function

Private Function CreateShapeDef(strLibAndFolder As String, strShape As String, ptX As Single, ptY As Single) As Boolean
  ' create a ShapeDef. ptX and ptY are the insertion point.
  ' we assume that there are objects selected at this point.
  ' returns False if failed, true otherwise
  
  On Error Resume Next
  GeCtrl.TreatShapesAsUserGroups = False
  CreateShapeDef = GeCtrl.CreateShapeDef(strLibAndFolder, strShape, ptX, ptY)

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

Private Function CreateSmartShapeDef(strLibAndFolder As String, strShape As String, ptX As Single, ptY As Single) As Boolean
  ' create a SmartShapeDef. ptX and ptY are the insertion point.
  ' we assume that there are objects selected at this point.
  ' returns False if failed, true otherwise
  
  On Error Resume Next
  GeCtrl.TreatShapesAsUserGroups = True       ' the trick to tell Ctrl that we want to make a SmartShape (aka UserGroup)
  CreateSmartShapeDef = g_DrawingDefMgr.m_custDrawEditor.GeCtrl.CreateShapeDef(strLibAndFolder, strShape, ptX, ptY)
  GeCtrl.TreatShapesAsUserGroups = False      ' remember to reset

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

Private Sub CreateConnection(fPosIncrement As Single, fOffset As Single, collConn As Collection, i As Integer, ByRef collID As Collection, iFace As Integer, GeIDRectangle As Long, ByRef pDefNew As UserDefinedItemDef)
  Dim GeID As Long
  Dim ConType As Integer    ' Type - MUST be a POSITIVE VALUE!
  Dim ptX As Single, ptY As Single
  Dim spacingV As Single
  Dim aVertices() As Single
  Dim fLeft As Single, fBottom As Single, fRight As Single, fTop As Single
  Dim strFldValue As String
  Dim strFldName As String
  Dim UserID As Long
  Dim varPoint(1, 1) As Single
  Dim fPos As Single
  Dim strConn As String
  Dim strObjectName As String
  Dim fTextPos As Single
  
  On Error Resume Next
  ConType = 1
  strConn = collConn(i)
  strObjectName = pDefNew.ObjectName
  
  UserID = GeIDRectangle * 100 + i * 10 + iFace     'This is where we store face and order.  This combination should be unique
  
  If GeIDRectangle > 0 Then
    GeCtrl.CurrentPropertyID = GeIDRectangle
    GeCtrl.GetExtents fLeft, fBottom, fRight, fTop
    GeCtrl.CurrentPropertyID = 0
  Else
    fLeft = LEFT_POS
    fBottom = BOTTOM_POS
    fRight = RIGHT_POS
    fTop = TOP_POS
  End If
  
  Select Case iFace
    Case idxAttr_B
        fPos = fPosIncrement * (i - 1) + fBottom + fOffset
        'For the Connection Point name, we attach the shape name to make sure we will have a unique identifier
        'for this UserID when we try to retrieve it on startup.
        GeID = GeCtrl.CreateConnectionPoint(fPos, fBottom - CONNECTOR_DISTANCE, strConn & "!" & strObjectName, ConType)
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
'Debug.Print "Creating connection point named - " & strConn & "!" & strObjectName & ".  GeID = " & GeID & "  UserID = " & UserID
        
        'GeID = GeCtrl.CreateTextField(fPos, fBottom, fPos + LABEL_DISTANCE, fBottom - CONNECTOR_DISTANCE, strConn, strConn) 'fltLeft, fltBottom, fltRight, fltTop
        GeID = GeCtrl.CreateText(fPos, fBottom - 0.05, strConn) 'fltLeft, fltBottom, fltRight, fltTop
        If GeID >= 0 Then
            AddAndSetUserID GeID, UserID, collID
        End If
        
        varPoint(0, 0) = fPos
        varPoint(0, 1) = fBottom
        varPoint(1, 0) = fPos
        varPoint(1, 1) = fBottom - CONNECTOR_DISTANCE
        GeID = GeCtrl.CreatePolyline(varPoint)
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
        
        pDefNew.FillInDetails strConn, idxAttr_B, i, UserID   'Fill in Face, Order, UserID
        
    Case idxAttr_T
        fPos = fTop - fPosIncrement * (collConn.count - i) - fOffset
        GeID = GeCtrl.CreateConnectionPoint(fPos, fTop + CONNECTOR_DISTANCE, strConn & "!" & strObjectName, ConType)
'Debug.Print "Creating connection point named - " & strConn & "!" & strObjectName & ".  GeID = " & GeID & "  UserID = " & UserID
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
        
        'GeID = GeCtrl.CreateTextField(fPos, fTop, fPos + LABEL_DISTANCE, fTop + CONNECTOR_DISTANCE, strConn, strConn) 'fltLeft, fltBottom, fltRight, fltTop
        GeID = GeCtrl.CreateText(fPos, fTop + 0.05, strConn) 'fltLeft, fltBottom, fltRight, fltTop
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
                
        varPoint(0, 0) = fPos
        varPoint(0, 1) = fTop
        varPoint(1, 0) = fPos
        varPoint(1, 1) = fTop + CONNECTOR_DISTANCE
        GeID = GeCtrl.CreatePolyline(varPoint)
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
        
        pDefNew.FillInDetails strConn, idxAttr_T, i, UserID   'Fill in Face, Order, UserID
                
    Case idxAttr_L
        fPos = fPosIncrement * (collConn.count - i) + fLeft + fOffset
        GeID = GeCtrl.CreateConnectionPoint(fLeft - CONNECTOR_DISTANCE, fPos, strConn & "!" & strObjectName, ConType)
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
'Debug.Print "Creating connection point named - " & strConn & "!" & strObjectName & ".  GeID = " & GeID & "  UserID = " & UserID
        
        fTextPos = IIf(fPosIncrement < FONT_HEIGHT, fPos + fPosIncrement, fPos + FONT_HEIGHT)
        GeID = GeCtrl.CreateText(fLeft - 0.05, fTextPos, strConn)
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
        
        varPoint(0, 0) = fLeft - CONNECTOR_DISTANCE
        varPoint(0, 1) = fPos
        varPoint(1, 0) = fLeft
        varPoint(1, 1) = fPos
        GeID = GeCtrl.CreatePolyline(varPoint)
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
        
        pDefNew.FillInDetails strConn, idxAttr_L, i, UserID   'Fill in Face, Order, UserID
        
    Case idxAttr_R
        fPos = fRight - fPosIncrement * (i - 1) - fOffset
        GeID = GeCtrl.CreateConnectionPoint(fRight + CONNECTOR_DISTANCE, fPos, strConn & "!" & strObjectName, ConType)
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
'Debug.Print "Creating connection point named - " & strConn & "!" & strObjectName & ".  GeID = " & GeID & "  UserID = " & UserID
                
        fTextPos = IIf(fPosIncrement < FONT_HEIGHT, fPos + fPosIncrement, fPos + FONT_HEIGHT)
        GeID = GeCtrl.CreateText(fRight + 0.05, fTextPos, strConn)
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
        
        varPoint(0, 0) = fRight
        varPoint(0, 1) = fPos
        varPoint(1, 0) = fRight + CONNECTOR_DISTANCE
        varPoint(1, 1) = fPos
        GeID = GeCtrl.CreatePolyline(varPoint)
        If GeID >= 0 Then AddAndSetUserID GeID, UserID, collID
        
        pDefNew.FillInDetails strConn, idxAttr_R, i, UserID   'Fill in Face, Order, UserID
  End Select
End Sub

Private Sub CheckForNonCodeGeneratedConnectors(collGeIDs As Collection, collUserIDs As Collection, collType As Collection, ByRef collGeIDsToRemove As Collection)
    Dim UserID As Long, GeID As Long
    Dim i As Integer
    Dim bConnectorExist As Boolean, bPolylinesExist As Boolean, bTextExists As Boolean
    Dim Response As Integer
    Dim strMsg As String
    
    On Error Resume Next
    If GeCtrl Is Nothing Then Exit Sub
    
    bConnectorExist = False
    bPolylinesExist = False
    bTextExists = False
    For i = 1 To collGeIDs.count
        If collUserIDs(i) <= 0 Then
            Select Case collType(i)
                Case GE_POLYLINE
                    bPolylinesExist = True
                Case GE_CONNECTOR
                    bConnectorExist = True
                Case GE_TEXT
                    bTextExists = True
            End Select
        End If
    Next i

    If bConnectorExist And bPolylinesExist And bTextExists Then
        'See if user wants to remove all elements of a connector (which may or may not be an actual connector) that
        'don't have associated UserIDs.
        strMsg = "Non code generated connectors have been detected.  Remove all non code generated elements (polylines, connectors, and text)?"
        Response = MsgBox(strMsg, vbYesNo + vbQuestion, PROJECT_TITLE + " - Remove connectors")
        If Response = vbNo Then
          Exit Sub
        End If
        
        GeCtrl.CurrentPropertyID = 0
        'Remove all polylines, text, and connectors
        For i = 1 To collGeIDs.count
            If collUserIDs(i) <= 0 Then
                If collType(i) = GE_CONNECTOR Or collType(i) = GE_TEXT Or collType(i) = GE_POLYLINE Then
                    GeCtrl.CurrentPropertyID = collGeIDs(i)
                    GeCtrl.SelRemove collGeIDs(i)
                    collGeIDsToRemove.Add collGeIDs(i)
                    GeCtrl.CurrentPropertyID = 0
                End If
            End If
        Next i
    End If
End Sub

Private Sub AddAndSetUserID(GeID As Long, UserID As Long, ByRef collID As Collection)
    collID.Add GeID
    SetUserIDForObject GeID, UserID
End Sub

Private Sub SetUserIDForObject(ByVal GeID As Long, ByVal UserID As Long)
  ' set the userID
  ' move into selector, set userID
  On Error Resume Next
  If GeID > 0 Then
    GeCtrl.CurrentPropertyID = GeID
    GeCtrl.ObjectUserID = UserID
    GeCtrl.CurrentPropertyID = 0   ' remember to reset
  End If
End Sub

Private Function GetUserIDForObject(ByVal GeID As Long) As Long
  ' get the userID
  On Error Resume Next
  If GeID > 0 Then
    GeCtrl.CurrentPropertyID = GeID
    GetUserIDForObject = GeCtrl.ObjectUserID
    GeCtrl.CurrentPropertyID = 0   ' remember to reset
  End If
End Function

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

Private Function OpenLibrary(strLibrary) As Boolean
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
        GeCtrl.FontHeight = FONT_HEIGHT
    Else
        GeCtrl.FontHeight = fPosIncrement - 0.02
    End If
    GeCtrl.ScaleMode = 1                   '1 = Proportional
    GeCtrl.FontAlignment = iAlignment      '0 = Left, 1 = Middle, 2 = Right
    GeCtrl.FontOrientation = iOrientation
    GeCtrl.FontEscapement = iOrientation
End Sub

Private Sub ExplodeOrUngroupCurrentShape()
    If GeCtrl.CanExplodeSmartShape Then
        GeCtrl.Ungroup
    Else
        GeCtrl.OnExplodeShape
    End If
End Sub

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

