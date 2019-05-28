Attribute VB_Name = "GeWorker"
'======================================================================================
'
' Module:   GeWorker - worker code for various operations against GeCtrl
' Updated:                By
'
'--------------------------------------------------------------------------------------
'======================================================================================

Option Explicit

'=================================================================
' Start of Declarations Section
'=================================================================
'=================================================================
' End of Declarations Section
'=================================================================

'-----------------------
Public Function GetGeObjectType_Str(ByVal iType As Integer) As String
  Dim strType As String
  
  On Error Resume Next
  Select Case iType
  Case 0: strType = "Invalid"
  Case 1: strType = "Pie"
  Case 2: strType = "Chord"
  Case 3: strType = "Arc"
  Case 4: strType = "Ellipse"
  Case 5: strType = "Polygon"
  Case 6: strType = "Smartline"
  Case 7: strType = "Polyline"
  Case 8: strType = "RoundRect"
  Case 9: strType = "Rectangle"
  Case 10: strType = "Shape"
  Case 11: strType = "Group"
  Case 12: strType = "Text"
  Case 13: strType = "TextML"
  Case 14: strType = "TextField"
  Case 15: strType = "StringField"
  Case 16: strType = "Field"
  Case 17: strType = "ConnectLinePnt"
  Case 18: strType = "ReferencePoint"
  Case 19: strType = "OpenBezier"
  Case 20: strType = "3DRect"
  Case 21: strType = "SmartShape" ' UserGroup
  Case 22: strType = "ObjectConnector"
  Case 23: strType = "PolyPolygonA"
  Case 24: strType = "PolyPolygon"
  Case 25: strType = "ConnectPolyline"
  Case 26: strType = "ConnectSmartline"
  Case 27: strType = "PictureHolder"
  Case 28: strType = "DimensionLine"

  Case Else:  strType = iType
  End Select
  
  GetGeObjectType_Str = strType
  
End Function


'======================================================================================
' Zoom
'======================================================================================
'--------------------------
Public Sub ZoomInBy2(GeCtrl As CG)
  ' zoom in by factor of 2
  Dim llX As Single, llY As Single, urX As Single, urY As Single
  Dim dwtpage As Single, dhtpage As Single, dX As Single, dy As Single
  
  Dim llXSel As Single, llYSel As Single, urXSel As Single, urYSel As Single
  Dim diffXSel As Single
  Dim diffYSel As Single
  
  On Error Resume Next
  If Not GeCtrl Is Nothing Then
    GeCtrl.GetZoomRect llX, llY, urX, urY     ' get current window info
    
    If GeCtrl.SelNumberOfObjects = 0 Then
    
      ' determine center of viewport and make it 1/2 the size (done below)
      
'AEM - 7/24/00 - with nothing selected, this code was always putting the center at the
' lower left area of the extents. this code does not need to execute!

'      ' if page is smaller than view, center page when zooming
'      If (((urX - llX) > GeCtrl.PageWidth) And ((urY - llY) > GeCtrl.PageHeight)) Then
'        diffXSel = ((urX - llX) / 2) + llX
'        diffYSel = ((urY - llY) / 2) + llY
'        llX = llX - diffXSel + (GeCtrl.PageWidth / 2)
'        urX = urX - diffXSel + (GeCtrl.PageHeight / 2)
'        llY = llY - diffYSel + (GeCtrl.PageWidth / 2)
'        urY = urY - diffYSel + (GeCtrl.PageHeight / 2)
'      End If
    ''
    Else
      ' center page
      diffXSel = ((urX - llX) / 2) + llX
      diffYSel = ((urY - llY) / 2) + llY
      llX = llX - diffXSel
      urX = urX - diffXSel
      llY = llY - diffYSel
      urY = urY - diffYSel
      
      ' zoom wrt. center of selected object
      GeCtrl.GetSelExtents llXSel, llYSel, urXSel, urYSel   ' get current
      diffXSel = ((urXSel - llXSel) / 2) + llXSel
      diffYSel = ((urYSel - llYSel) / 2) + llYSel
      llX = llX + diffXSel
      urX = urX + diffXSel
      llY = llY + diffYSel
      urY = urY + diffYSel
    End If
    
    ' calc zoom in
    dwtpage = urX - llX
    dhtpage = urY - llY
    dX = (dwtpage / 4)
    dy = (dhtpage / 4)
    llX = llX + dX
    llY = llY + dy
    urX = urX - dX
    urY = urY - dy
    ' do it
    GeCtrl.ZoomRect llX, llY, urX, urY
  End If
End Sub

'======================================================================================
' Align
'======================================================================================
'------------------------------
Public Sub AlignToGridOperation(GeCtrl As CG, ByVal nOp As Integer)
  Dim gHorz As Single
  Dim gVert As Single
  Dim dLeft As Single, dBottom As Single
  Dim dRight As Single, dTop As Single
  Dim adjX As Single
  Dim adjY As Single
  Dim bRet As Boolean

  On Error Resume Next
  GeCtrl.GetSelExtents dLeft, dBottom, dRight, dTop
  gHorz = GeCtrl.GridHorz
  gVert = GeCtrl.GridVert
  adjX = 0#
  adjY = 0#
  
  Select Case nOp
  Case 0  'left
    bRet = FloatModulus(dLeft, gVert, adjX)
    If bRet = False Then
      Exit Sub
    End If
    adjX = -adjX
  Case 1  'right
    bRet = FloatModulus(dRight, gVert, adjX)
    If bRet = False Or adjX = 0# Then
      Exit Sub
    End If
     adjX = gVert - adjX
  Case 2  'top
    bRet = FloatModulus(dTop, gHorz, adjY)
    If bRet = False Or adjY = 0# Then
      Exit Sub
    End If
    adjY = gHorz - adjY
  Case 3  'bottom
    bRet = FloatModulus(dBottom, gHorz, adjY)
    If bRet = False Then
      Exit Sub
    End If
    adjY = -adjY
  Case 4  'center
    Dim H As Single, W As Single
    H = dBottom + ((dTop - dBottom) / 2)
    W = dLeft + ((dRight - dLeft) / 2)
    bRet = FloatModulus(H, gHorz, adjY)
    If adjY < (gHorz / 2) Then
      adjY = -adjY
    Else
      adjY = gHorz - adjY
    End If
    bRet = FloatModulus(W, gVert, adjX)
    If adjX < (gVert / 2) Then
      adjX = -adjX
    Else
      adjX = gVert - adjX
    End If
  End Select
  
  GeCtrl.SelMove adjX, adjY

End Sub


'------------------------------
Public Sub AlignSelectionOperation(GeCtrl As CG, nOp As Integer)
  Select Case nOp
    Case 0 ' Left
      GeCtrl.AlignSelection 0
    Case 5 ' Middles  - CenterVertical (vertical center of last obj in list, move all others horizontally)
      GeCtrl.AlignSelection 5
    Case 1 ' Right
      GeCtrl.AlignSelection 1
      
    Case 2 ' Top
      GeCtrl.AlignSelection 2
    Case 4 ' Centers - CenterHorizontal (horizontal center of last obj in list, move all others vertically)
      GeCtrl.AlignSelection 4
    Case 3 ' Bottom
      GeCtrl.AlignSelection 3
  End Select
End Sub


'======================================================================================
' Size
'======================================================================================
'------------------------------
Public Sub MakeSameSizeOperation(GeCtrl As CG, ByVal nOp As Integer)
  ' make the same size
  On Error Resume Next
  Select Case nOp
    Case 0  ' "HEIGHT"
      GeCtrl.BeginUndoTransaction
      SelMakeSameHeight GeCtrl
      GeCtrl.EndUndoTransaction
    Case 1  ' "WIDTH"
      GeCtrl.BeginUndoTransaction
      SelMakeSameWidth GeCtrl
      GeCtrl.EndUndoTransaction
    Case 2  ' "BOTH"
      GeCtrl.BeginUndoTransaction
      SelMakeSameWidth GeCtrl
      SelMakeSameHeight GeCtrl
      GeCtrl.EndUndoTransaction
  End Select
End Sub

'------------------------------
Private Sub SelMakeSameWidth(GeCtrl As CG)
  ' make em all the same width
  Dim collInfo As Collection
  Dim bRet As Boolean
  Dim bPrev As Boolean

  On Error Resume Next
  If GeCtrl Is Nothing Then Exit Sub
  
    ' setup array and get info
  If GeCtrl.SelNumberOfObjects < 2 Then Exit Sub
  
  bPrev = GeCtrl.SendStatusEvents
  GeCtrl.SendStatusEvents = False
  Set collInfo = New Collection
  bRet = GetSelectedObjects(GeCtrl, collInfo)
  '
  If bRet Then
    GeCtrl.SelRemoveAll
    bRet = DoSelMakeSameWidth(GeCtrl, collInfo)
      ' restore selection
    RestoreSelectionGe GeCtrl, collInfo
  End If
  GeCtrl.SendStatusEvents = bPrev
  If bRet Then GeCtrl.Modified = True ' set flag so updates UI
  
  '
  Set collInfo = Nothing
End Sub

'------------------------------
Private Function DoSelMakeSameWidth(GeCtrl As CG, collInfo As Collection) As Boolean
  ' actually make em all the same width as last item in selection
  Dim i As Long
  Dim Info As GeObjectInfo
  Dim dWidthTarget As Single
  Dim dWidthCur As Single
  Dim ptX As Single, ptY As Single
  Dim scaleX As Single, scaleY As Single
  Dim nID As Long
  
  On Error Resume Next
  If collInfo.Count < 2 Then Exit Function
  
  ' determine target size
  Set Info = collInfo.Item(collInfo.Count)
  dWidthTarget = Info.urX - Info.llX
  ' reform the others.
  ' Scale from LL corner
  scaleY = 1#
  For i = 1 To collInfo.Count ' - 1
    Set Info = collInfo.Item(i)
    '
    ptX = Info.llX
    ptY = Info.llY
    dWidthCur = Info.urX - Info.llX
    If dWidthCur > 0 Then
      scaleX = dWidthTarget / dWidthCur
      nID = Info.GeID
      ' scale the last object( by 1.0) to get it into the undo list
      If i = collInfo.Count Then
        GeCtrl.ScaleObject nID, ptX, ptY, 1#, 1#
      Else
        GeCtrl.ScaleObject nID, ptX, ptY, scaleX, scaleY
      End If
    End If
  Next i
  DoSelMakeSameWidth = True
End Function

'------------------------------
Private Sub SelMakeSameHeight(GeCtrl As CG)
  ' make em all the same Height
  Dim collInfo As Collection
  Dim bRet As Boolean
  Dim bPrev As Boolean
  
  On Error Resume Next
  If GeCtrl Is Nothing Then Exit Sub
    ' setup array and get info
  If GeCtrl.SelNumberOfObjects < 2 Then Exit Sub
  
  bPrev = GeCtrl.SendStatusEvents
  GeCtrl.SendStatusEvents = False
  Set collInfo = New Collection
  bRet = GetSelectedObjects(GeCtrl, collInfo)
  '
  If bRet Then
    GeCtrl.SelRemoveAll
    bRet = DoSelMakeSameHeight(GeCtrl, collInfo)
      ' restore selection
    RestoreSelectionGe GeCtrl, collInfo
  End If
  GeCtrl.SendStatusEvents = bPrev
  If bRet Then GeCtrl.Modified = True   ' set flag so updates UI
  '
  Set collInfo = Nothing
End Sub

'------------------------------
Private Function DoSelMakeSameHeight(GeCtrl As CG, collInfo As Collection) As Boolean
  ' actually make em all the same height as last item in selection
  Dim i As Long
  Dim Info As GeObjectInfo
  Dim dHeightTarget As Single
  Dim dHeightCur As Single
  Dim ptX As Single, ptY As Single
  Dim scaleX As Single, scaleY As Single
  Dim nID As Long
  
  On Error Resume Next
  If collInfo.Count < 2 Then Exit Function
  
  ' determine target size
  Set Info = collInfo.Item(collInfo.Count)
  dHeightTarget = Info.urY - Info.llY
  ' reform the others.
  ' Scale from LL corner
  scaleX = 1#
  
  For i = 1 To collInfo.Count ' - 1
    Set Info = collInfo.Item(i)
    '
    ptX = Info.llX
    ptY = Info.llY
    dHeightCur = Info.urY - Info.llY
    If dHeightCur > 0 Then
      scaleY = dHeightTarget / dHeightCur
      nID = Info.GeID
      ' scale the last object( by 1.0) to get it into the undo list
      If i = collInfo.Count Then
        GeCtrl.ScaleObject nID, ptX, ptY, 1#, 1#
      Else
        GeCtrl.ScaleObject nID, ptX, ptY, scaleX, scaleY
      End If
    End If
  Next i
  
  DoSelMakeSameHeight = True
End Function


'======================================================================================
' Distribute
'======================================================================================
'---------------------------
Public Sub DistributeSelHorz(GeCtrl As CG)
  ' Distribute the selection - Horz
  Dim collInfo As Collection
  Dim bRet As Boolean
  Dim bPrev As Boolean
  
  On Error Resume Next
  GeCtrl.SelStepIntoGroups = False
    ' setup array and get info
  bPrev = GeCtrl.SendStatusEvents
  GeCtrl.SendStatusEvents = False
  Set collInfo = New Collection
  bRet = GetSelectedObjects(GeCtrl, collInfo)
  '
  If bRet Then
    GeCtrl.BeginUndoTransaction
    GeCtrl.SelRemoveAll
    DistributeSelectedObjectsX GeCtrl, collInfo
    RestoreSelectionGe GeCtrl, collInfo
    GeCtrl.EndUndoTransaction
  End If
  GeCtrl.SendStatusEvents = bPrev
  '
  Set collInfo = Nothing
End Sub

'---------------------------
Public Sub DistributeSelVert(GeCtrl As CG)
  ' Distribute the selection - Vert
  Dim collInfo As Collection
  Dim bRet As Boolean
  Dim bPrev As Boolean
  
  On Error Resume Next
  GeCtrl.SelStepIntoGroups = False
    ' setup array and get info
  bPrev = GeCtrl.SendStatusEvents
  GeCtrl.SendStatusEvents = False
  Set collInfo = New Collection
  bRet = GetSelectedObjects(GeCtrl, collInfo)
  '
  If bRet Then
    GeCtrl.BeginUndoTransaction
    GeCtrl.SelRemoveAll
    DistributeSelectedObjectsY GeCtrl, collInfo
    RestoreSelectionGe GeCtrl, collInfo
    GeCtrl.EndUndoTransaction
  End If
  GeCtrl.SendStatusEvents = bPrev
  '
  Set collInfo = Nothing
End Sub

'------------------------------
Private Sub DistributeSelectedObjectsX(GeCtrl As CG, collInfo As Collection)
  ' Distribute the selection equally.
  ' Must be at least 3 objs in sel to do this
  Dim i As Long
  Dim xInc As Single
  Dim yTmp As Single
  Dim nID As Long
  Dim Info1 As GeObjectInfo
  Dim Info As GeObjectInfo
  Dim xNew As Single
  Dim dWidth As Single    ' overall width of sel
  Dim dSpace As Single
  Dim dObjWidth As Single
  Dim dSelLeft As Single
  
  On Error Resume Next
  If collInfo.Count < 3 Then Exit Sub
  SortSelByX collInfo, True    ' true is left to right
  
  '' get overall width - inside to inside
  Set Info = collInfo.Item(1)               ' left
  dSelLeft = Info.urX
  Set Info1 = collInfo.Item(collInfo.Count) ' right
  dWidth = Info1.llX - Info.urX
  
  '' determine distance occupied by all objects
  For i = 2 To collInfo.Count - 1
    Set Info = collInfo.Item(i)
    dObjWidth = dObjWidth + (Info.urX - Info.llX)
  Next i
  
  '' determine interobject spacing
  dSpace = (dWidth - dObjWidth) / (collInfo.Count - 1)
  If dSpace <= 0# Then Exit Sub
  
  ' move the first & last one by 0 just to get it put in the undo list
  nID = Info.GeID:   If nID > 0 Then GeCtrl.MoveObject nID, 0, 0
  nID = Info1.GeID:  If nID > 0 Then GeCtrl.MoveObject nID, 0, 0
  
  '' move em - inc space
  yTmp = 0
  xNew = dSelLeft + dSpace
  For i = 2 To collInfo.Count - 1
    Set Info = collInfo.Item(i)
    '
    xInc = xNew - Info.llX
    nID = Info.GeID:    If nID > 0 Then GeCtrl.MoveObject nID, xInc, yTmp
    xNew = xNew + (Info.urX - Info.llX) + dSpace
    '
  Next i
End Sub
'------------------------------
Private Sub DistributeSelectedObjectsY(GeCtrl As CG, collInfo As Collection)
  ' Distribute the selection equally.
  ' Must be at least 3 objs in sel to do this
  Dim i As Long
  Dim yInc As Single
  Dim xTmp As Single
  Dim nID As Long
  Dim Info1 As GeObjectInfo
  Dim Info As GeObjectInfo
  Dim yNew As Single
  Dim dHeight As Single    ' overall width of sel
  Dim dSpace As Single
  Dim dObjHeight As Single
  Dim dSelBottom As Single
  
  On Error Resume Next
  If collInfo.Count < 3 Then Exit Sub
  SortSelByY collInfo, True   ' true is bottom to top
  
  '' get overall height - inside to inside
  Set Info = collInfo.Item(1)               ' bottom
  dSelBottom = Info.urY
  Set Info1 = collInfo.Item(collInfo.Count) ' top
  dHeight = Info1.llY - Info.urY
  
  '' determine distance occupied by all objects
  For i = 2 To collInfo.Count - 1
    Set Info = collInfo.Item(i)
    dObjHeight = dObjHeight + (Info.urY - Info.llY)
  Next i
  
  '' determine interobject spacing
  dSpace = (dHeight - dObjHeight) / (collInfo.Count - 1)
  If dSpace <= 0# Then Exit Sub
  
  ' move the first & last one by 0 just to get it put in the undo list
  nID = Info.GeID:   If nID > 0 Then GeCtrl.MoveObject nID, 0, 0
  nID = Info1.GeID:  If nID > 0 Then GeCtrl.MoveObject nID, 0, 0
  
  '' move em - inc space
  xTmp = 0
  yNew = dSelBottom + dSpace
  For i = 2 To collInfo.Count - 1
    Set Info = collInfo.Item(i)
    '
    yInc = yNew - Info.llY
    nID = Info.GeID:    If nID > 0 Then GeCtrl.MoveObject nID, xTmp, yInc
    yNew = yNew + (Info.urY - Info.llY) + dSpace
    '
  Next i
End Sub


'======================================================================================
' Spacing
'======================================================================================
'------------------------------
Public Sub SpaceSelHorz(GeCtrl As CG, ByVal bToLeft As Boolean, ByVal dX As Single)
  ' space the selection
  Dim collInfo As Collection
  Dim bRet As Boolean
  Dim bPrev As Boolean
  
  On Error Resume Next
  If GeCtrl.SelNumberOfObjects > 1 Then
    bPrev = GeCtrl.SendStatusEvents
    GeCtrl.SendStatusEvents = False
    GeCtrl.SelStepIntoGroups = False
    GeCtrl.BeginUndoTransaction
      ' setup array and get info
    Set collInfo = New Collection
    bRet = GetSelectedObjects(GeCtrl, collInfo)
    '
    If bRet Then
      GeCtrl.SelRemoveAll
      SpaceSelectedObjectsX GeCtrl, collInfo, dX, bToLeft
      RestoreSelectionGe GeCtrl, collInfo
    End If
    '
    GeCtrl.SendStatusEvents = bPrev
    Set collInfo = Nothing
    GeCtrl.EndUndoTransaction
  End If
End Sub

'------------------------------
Public Sub SpaceSelVert(GeCtrl As CG, ByVal bToTop As Boolean, ByVal dy As Single)
  ' space the selection
  Dim collInfo As Collection
  Dim bRet As Boolean
  Dim bPrev As Boolean
  
  On Error Resume Next
  If GeCtrl.SelNumberOfObjects > 1 Then
    bPrev = GeCtrl.SendStatusEvents
    GeCtrl.SendStatusEvents = False
    GeCtrl.SelStepIntoGroups = False
    GeCtrl.BeginUndoTransaction
      ' setup array and get info
    Set collInfo = New Collection
    bRet = GetSelectedObjects(GeCtrl, collInfo)
    '
    If bRet Then
      GeCtrl.SelRemoveAll
      SpaceSelectedObjectsY GeCtrl, collInfo, dy, bToTop
      RestoreSelectionGe GeCtrl, collInfo
    End If
    '
    GeCtrl.SendStatusEvents = bPrev
    Set collInfo = Nothing
    GeCtrl.EndUndoTransaction
  End If
End Sub

'------------------------------
Private Function SpaceSelectedObjectsX(GeCtrl As CG, collInfo As Collection, _
                        dX As Single, ByVal bToLeft As Boolean)
  ' space the selection by dX
  Dim i As Long
  Dim Info As GeObjectInfo
  Dim Info1 As GeObjectInfo
  Dim xTmp As Single
  Dim yTmp As Single
  Dim nID As Long
  Dim xNew As Single
  
  On Error Resume Next
  If collInfo.Count = 0 Then Exit Function

    
  SortSelByX collInfo, Not bToLeft   ' true is left to right
  ' space is space between objects
  
  Set Info = collInfo.Item(1)
  
  ' move the first & last one by 0 just to get it put in the undo list
  nID = Info.GeID
  If nID > 0 Then GeCtrl.MoveObject nID, 0, 0
  
  yTmp = 0
  For i = 1 To collInfo.Count - 1
    Set Info = collInfo.Item(i)
    Set Info1 = collInfo.Item(i + 1)
    '
    If bToLeft Then
      xNew = Info.llX - dX
      xTmp = xNew - Info1.urX
    Else
      xNew = Info.urX + dX
      xTmp = xNew - Info1.llX
    End If
    nID = Info1.GeID
    If nID > 0 Then GeCtrl.MoveObject nID, xTmp, yTmp
    
    Info1.llX = Info1.llX + xTmp
    Info1.urX = Info1.urX + xTmp
  Next i
  
  ' move the last one by 0 just to get it put in the undo list
  Set Info = collInfo.Item(collInfo.Count)
  nID = Info.GeID
  If nID > 0 Then GeCtrl.MoveObject nID, 0, 0
End Function

'------------------------------
Private Function SpaceSelectedObjectsY(GeCtrl As CG, collInfo As Collection, _
                        dy As Single, ByVal bToTop As Boolean)
  ' space the selection by dY
  Dim i As Integer
  Dim Info As GeObjectInfo
  Dim Info1 As GeObjectInfo
  Dim yTmp As Single
  Dim xTmp As Single
  Dim nCnt As Integer
  Dim nID As Long
  Dim yNew As Single
  
  On Error Resume Next
  If collInfo.Count = 0 Then Exit Function

  SortSelByY collInfo, bToTop    ' true is bottom to top
  ' space is space between objects
  Set Info = collInfo.Item(1)
  ' move the first & last one by 0 just to get it put in the undo list
  nID = Info.GeID
  If nID > 0 Then GeCtrl.MoveObject nID, 0, 0
  
  xTmp = 0
  For i = 1 To collInfo.Count - 1
    Set Info = collInfo.Item(i)
    Set Info1 = collInfo.Item(i + 1)
    '
    If bToTop Then    ' orig
      yNew = Info.urY + dy
      yTmp = yNew - Info1.llY
    Else
      yNew = Info.llY - dy
      yTmp = yNew - Info1.urY
    End If
    
    
    nID = Info1.GeID
    If nID > 0 Then GeCtrl.MoveObject nID, xTmp, yTmp
    Info1.llY = Info1.llY + yTmp
    Info1.urY = Info1.urY + yTmp
  Next i
  ' move the first & last one by 0 just to get it put in the undo list
  Set Info = collInfo.Item(collInfo.Count)
  nID = Info.GeID
  If nID > 0 Then GeCtrl.MoveObject nID, 0, 0
End Function



'======================================================================================
' Align ops
'======================================================================================
'------------------------------
Public Sub AlignToSnapOperation(GeCtrl As CG, ByVal Index As Integer)
  ' align the selection to snap
'  Dim bPrev As Boolean
  
  On Error Resume Next
'  bPrev = GeCtrl.SendStatusEvents
'  GeCtrl.SendStatusEvents = False
  Select Case Index
    Case 0  ' left
      AlignToSnapHorz GeCtrl, True
    Case 1  ' right
      AlignToSnapHorz GeCtrl, False
    Case 2  ' top
      AlignToSnapVert GeCtrl, True
    Case 3  ' bottom
      AlignToSnapVert GeCtrl, False
    Case 4  ' center
      AlignToSnapCenter GeCtrl
   End Select
'  GeCtrl.SendStatusEvents = bPrev
End Sub

'------------------------------
Private Sub AlignToSnapHorz(GeCtrl As CG, ByVal bToLeft As Boolean)
  ' align to snap (Horizontal)
  Dim xTmp As Single, yTmp As Single
  Dim xCenter As Single, yCenter As Single
  Dim Left As Single, Right As Single, Top As Single, Bottom As Single
  Dim dSnapY As Single
  Dim dSnapX As Single
  
  On Error Resume Next
  If GeCtrl.SelNumberOfObjects < 1 Then Exit Sub
  
  dSnapX = GeCtrl.SnapHorz
  dSnapY = GeCtrl.SnapVert
  
  ' get extents of selection.
  GeCtrl.GetSelExtents Left, Bottom, Right, Top
  ' get ref point to move
  If bToLeft Then
    xCenter = Left
  Else
    xCenter = Right
  End If
  ' get distance to move
  xTmp = xCenter - Int((xCenter + (dSnapX / 2)) / dSnapX) * dSnapX
  yTmp = 0#
  GeCtrl.SelMove -xTmp, -yTmp
End Sub


'------------------------------
Private Sub AlignToSnapCenter(GeCtrl As CG)
  ' align the selection to snap value
  Dim xTmp As Single, yTmp As Single
  Dim xCenter As Single, yCenter As Single
  Dim Left As Single, Right As Single, Top As Single, Bottom As Single
  Dim dSnapY As Single
  Dim dSnapX As Single
  
  On Error Resume Next
  If GeCtrl.SelNumberOfObjects < 1 Then Exit Sub
  
  dSnapX = GeCtrl.SnapHorz
  dSnapY = GeCtrl.SnapVert
  
  ' get extents of selection.
  GeCtrl.GetSelExtents Left, Bottom, Right, Top
  xCenter = Left + (Right - Left) / 2
  yCenter = Bottom + (Top - Bottom) / 2
  ' get distance to move
  xTmp = xCenter - Int((xCenter + (dSnapX / 2)) / dSnapX) * dSnapX ' xCenter - Int((xCenter / dSnapX) + (dSnapX / 2)) * dSnapX
  yTmp = yCenter - Int((yCenter + (dSnapY / 2)) / dSnapY) * dSnapY 'yCenter - Int((yCenter / dSnapY) + (dSnapY / 2)) * dSnapY
  
  GeCtrl.SelMove -xTmp, -yTmp
End Sub

'------------------------------
Private Sub AlignToSnapVert(GeCtrl As CG, ByVal bToTop As Boolean)
  ' align to snap (Vertical)
  Dim xTmp As Single, yTmp As Single
  Dim xCenter As Single, yCenter As Single
  Dim Left As Single, Right As Single, Top As Single, Bottom As Single
  Dim dSnapY As Single
  Dim dSnapX As Single
  
  On Error Resume Next
  If GeCtrl.SelNumberOfObjects < 1 Then Exit Sub
  
  dSnapX = GeCtrl.SnapHorz
  dSnapY = GeCtrl.SnapVert
  ' get extents of selection.
  GeCtrl.GetSelExtents Left, Bottom, Right, Top
  
  ' get ref point to move
  If bToTop Then
    yCenter = Top
  Else
    yCenter = Bottom
  End If
  ' get distance to move
  xTmp = 0#
  yTmp = yCenter - Int((yCenter + (dSnapY / 2)) / dSnapY) * dSnapY
  GeCtrl.SelMove -xTmp, -yTmp
End Sub

'======================================================================================
' CG Object Properties
'======================================================================================
'-------------------------
Public Property Let GDIProperty(GeCtrl As CG, iProperty As Integer, strParam As String)
  ' set property for GDI object
  Dim GeID As Long
  Dim aVar As Variant  ' array of GeIDs in selection
  Dim iLow As Long, iHigh As Long, i As Long
  Dim bSel As Boolean
  Dim iVal As Integer, sVal As Single
  Dim nWeight As Integer

  On Error Resume Next
  ' determine if param is valid
  Select Case iProperty
    Case 0:  If Not FormatColor(strParam, iVal) Then Exit Property
    Case 19:  If Not FormatColor(strParam, iVal) Then Exit Property
    Case 20:  If Not FormatColor(strParam, iVal) Then Exit Property
    Case 21:  If Not FormatColor(strParam, iVal) Then Exit Property
    
    Case 1:  If Not FormatLineStyle(strParam, iVal) Then Exit Property
    Case 2:  If Not FormatFillStyle(strParam, iVal) Then Exit Property
    Case 3:  If Not FormatThickness(strParam, sVal) Then Exit Property
    Case 10:  If Not FormatBrushHatch(strParam, iVal) Then Exit Property
    
    Case 12:  If Not FormatScaleMode(strParam, iVal) Then Exit Property
    Case 13:  If Not FormatRotateMode(strParam, iVal) Then Exit Property
    Case 17:  If Not FormatLayer(strParam, iVal) Then Exit Property
    
'    Case Else: Exit Property
  End Select
  
  ' get IDs of selection and move last into selector
  If GetSelectedObjectsFast(GeCtrl, aVar, GeID) Then
    bSel = True
    iLow = LBound(aVar):      iHigh = UBound(aVar)
  End If
  
  ' if multiple, wrap in transaction
  If (iHigh - iLow) > 0 Then
    GeCtrl.BeginUndoTransaction
  End If
  '
  For i = iLow To iHigh
    If bSel Then
      GeID = aVar(i)
      GeCtrl.CurrentPropertyID = GeID ' move into selector
    End If
    ' set it
    Select Case iProperty
      '' Color
      Case 0:    GeCtrl.PenColor = iVal
      Case 19:    GeCtrl.BrushColor = iVal
      Case 20:    GeCtrl.FontColor = iVal
      Case 21:    GeCtrl.BackgroundColor = iVal
      '
      Case 1:  GeCtrl.PenStyle = iVal
      Case 2:  GeCtrl.BrushStyle = iVal
      Case 3:  GeCtrl.PenWidth = sVal
      
      '' font
      Case 4
        sVal = CSng(strParam)
        If sVal > 0# Then GeCtrl.FontHeight = sVal ' height
      Case 5   ' BOLD
        If FormatBool(strParam) Then nWeight = 400 Else nWeight = 700
        GeCtrl.FontWeight = nWeight                 ' 400 = notbold, 700 = bold
      Case 6:  GeCtrl.FontUnderline = FormatBool(strParam) ' underline
      Case 7:  GeCtrl.FontStrikeOut = FormatBool(strParam)     ' strikeout
      Case 8:  GeCtrl.FontItalic = FormatBool(strParam)   ' italic
      Case 9  ' font name
        If Len(strParam) > 0 Then GeCtrl.FontFaceName = strParam
      
      ''
      Case 10:  GeCtrl.BrushHatch = iVal      ' brushhatch
      Case 11
        GeCtrl.BackgroundMode = FormatBool(strParam)     ' BackgroundMode
        GeCtrl.InvalidateObjectAfter GeID
      
      Case 12:  GeCtrl.ScaleMode = iVal      ' scalemode
      Case 13:  GeCtrl.RotateMode = iVal      ' rotatemode
      
      Case 14:  GeCtrl.Lock = FormatBool(strParam) ' selectlock
      Case 15:  GeCtrl.MoveLock = FormatBool(strParam) ' MoveLock
      Case 16
        GeCtrl.InvalidateObjectBefore GeID
        GeCtrl.ObjectVisible = FormatBool(strParam) ' visible
        GeCtrl.InvalidateObjectAfter GeID
        
      Case 17:  GeCtrl.Layer = iVal      ' layer
      
      Case 18   ' text string TXSTR
      ' block if multiline text
        If Len(strParam) > 0 Then
          If GeCtrl.ObjectType = EGeObjType.Text Or GeCtrl.ObjectType = EGeObjType.TextField Then
            GeCtrl.TextString = strParam
          End If
        End If
    
      ''
      Case Else
        Exit For  ' can't deal with it. leave!
    End Select
  Next i
  '
  GeCtrl.CurrentPropertyID = 0      ' reset selector

  ' if multiple, wrap in transaction
  If (iHigh - iLow) > 0 Then
    GeCtrl.EndUndoTransaction
  End If

End Property
'-------------------------
Public Property Get GDIProperty(GeCtrl As CG, iProperty As Integer) As String
  ' get any property from GECtrl
  Dim GeID As Long, aVar As Variant  ' array of GeIDs in selection
  Dim strParam As String
  Dim nWeight As Integer
  
  On Error Resume Next
  ' get IDs of selection and move last into selector
  If GetSelectedObjectsFast(GeCtrl, aVar, GeID) Then
    GeCtrl.CurrentPropertyID = GeID
  End If
  '
  Select Case iProperty
    '' Color
    Case 0:    strParam = GeCtrl.PenColor
    Case 19:    strParam = GeCtrl.BrushColor
    Case 20:    strParam = GeCtrl.FontColor
    Case 21:    strParam = GeCtrl.BackgroundColor
    
    '' style/width
    Case 1:  strParam = GeCtrl.PenStyle
    Case 2:  strParam = GeCtrl.BrushStyle
    Case 3:  strParam = GeCtrl.PenWidth
    
    '' font
    Case 4:  strParam = GeCtrl.FontHeight   ' height
    Case 5
      nWeight = GeCtrl.FontWeight   ' bold 400 = notbold, 700 = bold
      strParam = IIf(nWeight > 400, FormatBoolRev(True), FormatBoolRev(False))
    Case 6:  strParam = FormatBoolRev(GeCtrl.FontUnderline)   ' underline
    Case 7:  strParam = FormatBoolRev(GeCtrl.FontStrikeOut)   ' strikeout
    Case 8:  strParam = FormatBoolRev(GeCtrl.FontItalic)   ' italic
    Case 9:  strParam = GeCtrl.FontFaceName
    
    ''
    Case 10:  strParam = GeCtrl.BrushHatch          ' brushhatch
    Case 11:  strParam = FormatBoolRev(GeCtrl.BackgroundMode)   ' BackgroundMode
    
    Case 12:  strParam = GeCtrl.ScaleMode      ' scalemode
    Case 13:  strParam = GeCtrl.RotateMode     ' rotatemode
    
    Case 14:  strParam = FormatBoolRev(GeCtrl.Lock)     ' selectlock
    Case 15:  strParam = FormatBoolRev(GeCtrl.MoveLock)     ' movelock
    Case 16:  strParam = FormatBoolRev(GeCtrl.ObjectVisible)     ' visible
    Case 17:  strParam = GeCtrl.Layer     ' layer
    
    Case 18     ' text string TXSTR
      ' block if multiline text
      If GeCtrl.ObjectType = EGeObjType.Text Or GeCtrl.ObjectType = EGeObjType.TextField Then
        strParam = GeCtrl.TextString
      End If
    
    End Select
  '
  GeCtrl.CurrentPropertyID = 0  ' reset
  GDIProperty = strParam
End Property

'-------------------------
Private Function FormatBool(strParam As String) As Boolean
  ' format string to boolean
  Dim strTmp As String
  strTmp = Trim(strParam)
  If strTmp = "0" Or strTmp = "f" Or strTmp = "F" Or _
       UCase(strTmp) = "FALSE" Or UCase(strTmp) = "OFF" _
  Then
    FormatBool = False
  Else
    FormatBool = True
  End If
End Function
'-------------------------
Private Function FormatBoolRev(ByVal bVal As Boolean) As String
  ' format string to boolean
  Dim strTmp As String
  If bVal Then
    strTmp = "1"
  Else
    strTmp = "0"
  End If
  FormatBoolRev = strTmp
End Function

'-------------------------
Private Function FormatColor(strParam As String, iVal As Integer) As Boolean
  ' format color
  On Error Resume Next
  iVal = CInt(Trim(strParam))
  If Err = 0 Then FormatColor = True
End Function
'-------------------------
Private Function FormatLayer(strParam As String, iVal As Integer) As Boolean
  ' format layer (0 or +ve integer only)
  On Error Resume Next
  iVal = CInt(Trim(strParam))
  If (Err = 0) And (iVal >= 0) Then FormatLayer = True
End Function

'-------------------------
Private Function FormatBrushHatch(strParam As String, iVal As Integer) As Boolean
  ' format BrushHatch
  On Error Resume Next
  iVal = CInt(Trim(strParam))
  If Err = 0 Then
    If iVal >= GEHS_HORIZONTAL And iVal <= GEHS_DIAGCROSS Then FormatBrushHatch = True
  End If
End Function

'-------------------------
Private Function FormatRotateMode(strParam As String, iVal As Integer) As Boolean
  ' format RotateMode
  On Error Resume Next
  iVal = CInt(Trim(strParam))
  If Err = 0 Then
    If iVal >= EGeRotateMode.MODE_ANY And iVal <= EGeRotateMode.MODE_NONE Then FormatRotateMode = True
  End If
End Function
'-------------------------
Private Function FormatScaleMode(strParam As String, iVal As Integer) As Boolean
  ' format ScaleMode
  On Error Resume Next
  iVal = CInt(Trim(strParam))
  If Err = 0 Then
    If iVal >= EGeScaleMode.MODE_ALL And iVal <= EGeScaleMode.NONE Then FormatScaleMode = True
  End If
End Function

'-------------------------
Private Function FormatLineStyle(strParam As String, iVal As Integer) As Boolean
  ' format LineStyle
  On Error Resume Next
  iVal = CInt(Trim(strParam))
  If Err = 0 Then
    If iVal >= GEPS_SOLID And iVal <= GEPS_NULL Then FormatLineStyle = True
  End If
End Function
'-------------------------
Private Function FormatFillStyle(strParam As String, iVal As Integer) As Boolean
  ' format FillStyle
  On Error Resume Next
  iVal = CInt(Trim(strParam))
  If Err = 0 Then
    If iVal >= GEBS_SOLID And iVal <= GEBS_HATCHED Then
      FormatFillStyle = True
    ElseIf iVal = GEBS_TRANSPARENT Then
      FormatFillStyle = True
    End If
  End If
End Function

'-------------------------
Private Function FormatThickness(strParam As String, sVal As Single) As Boolean
  On Error Resume Next
  sVal = CSng(Trim(strParam))
  If Err = 0 Then
    If sVal >= 0# Then FormatThickness = True
  End If
End Function


'======================================================================================
' Helpers
'======================================================================================
Public Function GetSelectedObjects(GeCtrl As CG, collInfo As Collection) As Boolean
  ' get info on selection
  Dim aVar As Variant
  Dim iLow As Integer
  Dim iHigh As Integer
  Dim i As Integer
  Dim j As Integer
  Dim Info As GeObjectInfo
  Dim urX As Single, urY As Single, llX As Single, llY As Single
  
  On Error Resume Next
  GetSelectionIDs GeCtrl, aVar   ' get from CG
  iLow = LBound(aVar)
  iHigh = UBound(aVar)
    ' if error, then probably nothing in array !
  If Err = 0 Then
    '
    GetSelectedObjects = True
    '
    j = 0
    For i = iLow To iHigh
      '
      Set Info = New GeObjectInfo
      collInfo.Add Info
      Info.GeID = aVar(i)
      GetObjGeExtents GeCtrl, Info.GeID, llX, llY, urX, urY
      Info.llX = llX
      Info.llY = llY
      Info.urX = urX
      Info.urY = urY
      '
      j = j + 1
    Next i
  Else
    Err = 0
    GetSelectedObjects = False
  End If

End Function

'------------------------------
Public Function RestoreSelectionGe(GeCtrl As CG, coll As Collection)
    ' restore selection in CG
  Dim i As Integer
  Dim Info As GeObjectInfo
  Dim bPrev As Boolean
  
  On Error Resume Next
  If Not GeCtrl Is Nothing Then
    bPrev = GeCtrl.SendStatusEvents
    GeCtrl.SendStatusEvents = False
    GeCtrl.SelRemoveAll
    For i = 1 To coll.Count
      Set Info = coll.Item(i)
      GeCtrl.SelAdd Info.GeID
    Next i
    GeCtrl.SendStatusEvents = bPrev
  End If
End Function

'------------------------------
Private Function GetSelectionIDs(GeCtrl As CG, aVar As Variant)
  ' get the IDs only of the selection
  On Error Resume Next
  GeCtrl.SelGetObjects aVar
End Function

'------------------------------
Private Function GetObjGeExtents(GeCtrl As CG, GeID As Long, llX As Single, llY As Single, _
                urX As Single, urY As Single)
  ' get the Extents of the object in CG coordinates
  On Error Resume Next
  GeCtrl.CurrentPropertyID = GeID  ' move into selector
  If Err = 0 Then   ' test for exception from CG
    GeCtrl.GetExtents llX, llY, urX, urY
  End If
  GeCtrl.CurrentPropertyID = 0      ' reset selector
End Function

'------------------------------
Public Function GetSelectedObjectsFast(GeCtrl As CG, aVar As Variant, GeIDLAST As Long) As Boolean
  ' get ids of selection. return false if nothing selected
  ' put GeID of LAST in selction into param
  Dim iLow As Long, iHigh As Long
  
  On Error Resume Next
  GeCtrl.SelGetObjects aVar
  iLow = LBound(aVar)
  iHigh = UBound(aVar)
  ' if error, then probably nothing in array !
  ' high will be less than low if nothing there ( hi = -1, low = 0)
  If Err = 0 And (iLow <= iHigh) Then
    GeIDLAST = aVar(iHigh)
    GetSelectedObjectsFast = True
  Else
    Err = 0
  End If
End Function

'------------------------------
Public Sub RestoreSelectionGeFast(GeCtrl As CG, aVar As Variant)
    ' restore selection to CG
  Dim iLow As Long, iHigh As Long
  Dim i As Long
  Dim GeID As Long
  Dim bPrev As Boolean
  
  If Not GeCtrl Is Nothing Then
    iLow = LBound(aVar)
    iHigh = UBound(aVar)
    ' if error, then probably nothing in array !
    If Err = 0 Then
      bPrev = GeCtrl.SendStatusEvents
      GeCtrl.SendStatusEvents = False
      For i = iLow To iHigh
        GeID = aVar(i)
        GeCtrl.SelAdd GeID
      Next i
      GeCtrl.SendStatusEvents = bPrev
    Else
      Err = 0
    End If
  End If
End Sub



'------------------------------
Public Function SortSelByX(coll As Collection, bAscending As Boolean)
  ' sort selection, X dir
  ' if bAscending, put leftmost 1st, rightmost last
  ' otherwise, the other way
  Dim colltmp As Collection
  Dim i As Integer
  Dim nCount As Integer
  Dim nIndex As Integer
  
  On Error Resume Next
  Set colltmp = New Collection
    ' add to collection in ascending/decending row order, removing as we go
  While (coll.Count > 0)
    If bAscending Then
      nIndex = GetCollIndexWithLowestX(coll)
    Else
      nIndex = GetCollIndexWithHighestX(coll)
    End If
    colltmp.Add coll.Item(nIndex)
    coll.Remove nIndex
  Wend
    ' add Tmp to coll
  nCount = colltmp.Count
  For i = 1 To nCount
    coll.Add colltmp.Item(i)
  Next i
    ' cleanup
  Set colltmp = Nothing
End Function
  
'------------------------------
Public Function SortSelByY(coll As Collection, bAscending As Boolean)
  ' sort selection, Y dir
  ' if bAscending, put bottommost 1st, topmost last
  ' otherwise, the other way
  Dim colltmp As Collection
  Dim i As Integer
  Dim nCount As Integer
  Dim nIndex As Integer
  
  On Error Resume Next
  Set colltmp = New Collection
    ' add to collection in ascending/decending row order, removing as we go
  While (coll.Count > 0)
    If bAscending Then
      nIndex = GetCollIndexWithLowestY(coll)
    Else
      nIndex = GetCollIndexWithHighestY(coll)
    End If
    colltmp.Add coll.Item(nIndex)
    coll.Remove nIndex
  Wend
    ' add Tmp to coll
  nCount = colltmp.Count
  For i = 1 To nCount
    coll.Add colltmp.Item(i)
  Next i
    ' cleanup
  Set colltmp = Nothing
End Function
  
'------------------------------
Public Function GetCollIndexWithLowestX(coll As Collection) As Integer
  ' get index in collection with the lowest llX number
  Dim i As Integer
  Dim nRowRet As Single, nRowCur As Single
  Dim nIndex As Integer
  nRowRet = 3200000
  nIndex = 1
  For i = 1 To coll.Count
    nRowCur = coll.Item(i).llX
    If nRowCur < nRowRet Then
      nRowRet = nRowCur
      nIndex = i
    End If
  Next i
  GetCollIndexWithLowestX = nIndex
End Function
'------------------------------
Public Function GetCollIndexWithHighestX(coll As Collection) As Integer
  ' get index in collection with the highest urX number
  Dim i As Integer
  Dim nRowRet As Single, nRowCur As Single
  Dim nIndex As Integer
  nRowRet = -3200000
  nIndex = 1
  For i = 1 To coll.Count
    nRowCur = coll.Item(i).urX
    If nRowCur > nRowRet Then
      nRowRet = nRowCur
      nIndex = i
    End If
  Next i
  GetCollIndexWithHighestX = nIndex
End Function

'------------------------------
Public Function GetCollIndexWithLowestY(coll As Collection) As Integer
  ' get index in collection with the lowest llY number
  Dim i As Integer
  Dim nRowRet As Single, nRowCur As Single
  Dim nIndex As Integer
  nRowRet = 3200000
  nIndex = 1
  For i = 1 To coll.Count
    nRowCur = coll.Item(i).llY
    If nRowCur < nRowRet Then
      nRowRet = nRowCur
      nIndex = i
    End If
  Next i
  GetCollIndexWithLowestY = nIndex
End Function
'------------------------------
Public Function GetCollIndexWithHighestY(coll As Collection) As Integer
  ' get index in collection with the highest urY number
  Dim i As Integer
  Dim nRowRet As Single, nRowCur As Single
  Dim nIndex As Integer
  nRowRet = -3200000
  nIndex = 1
  For i = 1 To coll.Count
    nRowCur = coll.Item(i).urY
    If nRowCur > nRowRet Then
      nRowRet = nRowCur
      nIndex = i
    End If
  Next i
  GetCollIndexWithHighestY = nIndex
End Function


'------------------------------
Public Function CalcLength(GeCtrl As CG, Optional frm As Form = Nothing, Optional bIsValidForObject As Boolean = False) As Single
  ' calc the length of a single selected object (which has verticies)
  ' frm MUST support SetStatusText if not Nothing ( will Display length in the status bar)
  ' bIsValidForObject will be set to true if object has vertices
  Dim GeID As Long
  Dim ptX As Single
  Dim ptY As Single
  Dim Pt1X As Single
  Dim Pt1Y As Single
  Dim aVar As Variant
  Dim sLength As Single
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim i As Integer
  Dim bIsPolygon As Boolean
  Dim ptStartX As Single
  Dim ptStartY As Single


  CalcLength = 0#
  On Error Resume Next    ' CG is in the mix
  If GeCtrl Is Nothing Then Exit Function
    
  '
  If GeCtrl.SelNumberOfObjects = 1 Then
    GeID = GeCtrl.GetFirstSelObject
    If GeID > 0 Then
      GeCtrl.CurrentPropertyID = GeID  ' move into selector
      GeCtrl.GetVerticies aVar          ' get vertices
      If GeCtrl.ObjectType = EGeObjType.Polygon Then bIsPolygon = True
    End If
  End If
  '
  uBnd = UBound(aVar)
  lBnd = LBound(aVar)
  If uBnd > 0 Then
    bIsValidForObject = True
    If Err = 0 Then
      For i = lBnd To uBnd - 1
        ptX = aVar(i, 0)
        ptY = aVar(i, 1)
        Pt1X = aVar(i + 1, 0)
        Pt1Y = aVar(i + 1, 1)
        If i = lBnd And bIsPolygon = True Then
          ptStartX = ptX
          ptStartY = ptY
        End If
        sLength = sLength + SegmentLen(ptX, ptY, Pt1X, Pt1Y)
      Next i
      ' add last segement in a polygon
      If bIsPolygon = True Then
        sLength = sLength + SegmentLen(ptStartX, ptStartY, Pt1X, Pt1Y)
      End If
      
      CalcLength = sLength
      If Not frm Is Nothing Then frm.SetStatusText " Length: " & sLength
    End If
  Else
    bIsValidForObject = False
  End If
  
  GeCtrl.CurrentPropertyID = 0 ' reset selector
End Function

Public Function SegmentLen(ByVal Xo As Single, ByVal Yo As Single, ByVal Xi As Single, ByVal Yi As Single) As Single
  SegmentLen = Sqr(((Xi - Xo) * (Xi - Xo)) + ((Yi - Yo) * (Yi - Yo)))
End Function


'------------------------------
Public Sub MoveSelectionOperation(GeCtrl As CG, ByVal Index As Integer, X As Single, Y As Single)
  ' Move or MoveBy the selection.
  ' index:
  ' 0 = Lower left, 1 = upper left, 2 = lower right, 3 = upper right,
  ' 4 = center
  ' 5 = move by
  ' 6 = move shape insertion point
  
  Dim Left As Single, Right As Single, Top As Single, Bottom As Single
  Dim xCenter As Single, yCenter As Single
  Dim xIP As Single, yIP As Single
  Dim nGeID As Long
  Dim bUseCenter As Boolean
  
  On Error Resume Next
  If GeCtrl.SelNumberOfObjects < 1 Then Exit Sub
  
  If GeCtrl.SelNumberOfObjects = 1 Then
    nGeID = GeCtrl.GetFirstSelObject
    GeCtrl.ShapeSetCurrent nGeID
    If GeCtrl.ObjectType = Shape Or GeCtrl.ObjectType = UserGroup Then
      GeCtrl.InsertionPoint xIP, yIP  ' get IP
    Else
      bUseCenter = True
    End If
    GeCtrl.ShapeSetCurrent 0
  Else
    If Index = 6 Then bUseCenter = True ' use center if shape IP but more than 1 obj in selection
  End If
  
  GeCtrl.GetSelExtents Left, Bottom, Right, Top
  '
  xCenter = Left + (Right - Left) / 2
  yCenter = Bottom + (Top - Bottom) / 2
  If bUseCenter Then
    ' use center if not shape, as otherwise it will wind up at some unknown place
    xIP = xCenter: yIP = yCenter
  End If
  
  ' move the selection to x,y
  Select Case Index
    Case 0  ' Lower left
      GeCtrl.SelMove X - Left, Y - Bottom
    Case 1  ' upper left
      GeCtrl.SelMove X - Left, Y - Top
    Case 2  ' lower right
      GeCtrl.SelMove X - Right, Y - Bottom
    Case 3  ' upper right
      GeCtrl.SelMove X - Right, Y - Top
    Case 4  ' center
      GeCtrl.SelMove X - xCenter, Y - yCenter
    Case 5  ' move by
      GeCtrl.SelMove X, Y
    Case 6  ' move shape insertion point
      GeCtrl.SelMove X - xIP, Y - yIP
      
   End Select
'
End Sub

'------------------------------
Public Function MakeArray(GeCtrl As CG, ByVal nRows As Long, ByVal nCols As Long, _
        ByVal dX As Single, ByVal dy As Single, Optional ByVal bGroup As Boolean = True, _
        Optional ByVal bCentered As Boolean = False) As Boolean
  ' create 2d rectangular array of selection
  ' Assume selection is cornerstone and will be at lower left of resulting array,
  ' which will grow upwards and to the right.

  ' get extents of selection
  Dim i As Integer, j As Integer
  Dim GeID As Long
  Dim dWidthCur As Single, dHeightCur As Single
  Dim fltLeft0 As Single, fltBottom0 As Single, fltRight0 As Single, fltTop0 As Single
  Dim ptXAnchor As Single, ptYAnchor As Single
  Dim ptX As Single, ptY As Single
  Dim bFirst As Boolean     ' selection remains the 1st element in the array
  Dim aVar As Variant       ' array of GeIDs in selection
  Dim aVarOut() As Variant
  Dim lBnd As Long, uBnd As Long, iBnd As Long, nIDs As Long, nInc As Long
  Dim nCount As Long
  
  
  On Error Resume Next
  
  ' get current situation
  GeCtrl.GetSelExtents fltLeft0, fltBottom0, fltRight0, fltTop0
  dWidthCur = fltRight0 - fltLeft0
  dHeightCur = fltTop0 - fltBottom0
  
  ' wrap in transaction
  GeCtrl.SendStatusEvents = False
  GeCtrl.GrabHandlesEnabled = False
  BeginWaitCursor
  DoEvents
  GeCtrl.BeginUndoTransaction
    
  ' memorize anchor point (lower left of selection)
  ptXAnchor = fltLeft0:   ptYAnchor = fltBottom0
  ptY = ptYAnchor
   
  ' grab IDs of current sel to be restored
  GetSelectedObjectsFast GeCtrl, aVar, GeID
  uBnd = UBound(aVar)
  lBnd = LBound(aVar)
  ReDim Preserve aVarOut(uBnd - lBnd) As Variant
  For iBnd = lBnd To uBnd
    aVarOut(iBnd) = aVar(iBnd)
  Next iBnd
  
  ' row by row, populate column
  For i = 1 To nRows
    ' paste then place - when CG pastes, it uses lower left of extents as insertion point
    For j = 1 To nCols
      If bCentered Then
        ptX = ptXAnchor + (dX * (j - 1))
      Else
        ptX = ptXAnchor + ((dX + dWidthCur) * (j - 1))
      End If
      If Not bFirst Then
        bFirst = True     ' skip the first 1 as we are creating an array
      Else
        GeCtrl.SelCopyToPoint ptX, ptY      ' copy sel to point
        If Err <> 0 Then Exit For
        
        ' grab IDs of copy to be restored
        GetSelectedObjectsFast GeCtrl, aVar, GeID
        uBnd = UBound(aVar)
        lBnd = LBound(aVar)
        nIDs = UBound(aVarOut) + (uBnd - lBnd + 1)
        nInc = nIDs - (uBnd - lBnd)
        ReDim Preserve aVarOut(nIDs) As Variant
        For iBnd = lBnd To uBnd
          aVarOut(nInc + iBnd) = aVar(iBnd)
        Next iBnd
        
        
        ' allow screen to update every 50 or so
        If nCount > 49 Then
          If nCount Mod 50 = 0 Then DoEvents
        End If
        nCount = nCount + 1
      
      End If
    Next j
    ' inc to next row (going upward)
    If bCentered Then
      ptY = ptYAnchor + (dy * i)
    Else
      ptY = ptYAnchor + ((dy + dHeightCur) * i)
    End If
    If Err <> 0 Then Exit For
  Next i
  
  ' add all to selection then group
  GeCtrl.GrabHandlesEnabled = True
  RestoreSelectionGeFast GeCtrl, aVarOut
  GeCtrl.SendStatusEvents = True
  '
  If bGroup Then
    GeCtrl.Group
      ' do a Redraw/ invalidate to get the grab handles of new group to show up
    GeID = GeCtrl.GetLastCreatedObject
    If GeID > 0 Then
      GeCtrl.InvalidateObjectAfter GeID
    Else
      GeCtrl.Redraw
    End If
  End If
  '
  GeCtrl.EndUndoTransaction
  GeCtrl.Modified = True        ' set modified flag to foce event back to GeEditor form
  EndWaitCursor
  

End Function
        

