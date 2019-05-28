VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "GeLibraryMgr"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

'===============================
' GE Library Object
' class data members
'===============================

' properties

' other properties
'
'
' Library File
Private m_bLbrOpened As Boolean ' Library is opened
Private m_LbrDB As Database ' the Library
Private m_strLibName As String  ' name of library database
Private m_bReadOnly As Boolean

Private m_bFirstFieldMsg As Boolean ' Msgbox for invalid schema

Private m_bResetAutoScale As Boolean


Private Const DT_LONGBINARY = 11

'=======================================================
' End Declarations
'=======================================================
'===============================
' Construction
'===============================
Private Sub Class_Initialize()
End Sub

Private Sub Class_Terminate()
  DeleteContents
End Sub

Private Sub DeleteContents()
  CloseLibrary
End Sub
'------------------------------
Public Property Get IsOpened() As Boolean
  IsOpened = m_bLbrOpened
End Property

'------------------------------
Public Property Get LibDB() As Database
  Set LibDB = m_LbrDB
End Property
'------------------------------
Public Property Get LibrayName() As String
  ' complete path & name
  LibrayName = m_strLibName
End Property

Public Property Let ResetAutoScale(ByVal bVal As Boolean)
  m_bResetAutoScale = bVal
End Property
Public Property Get ResetAutoScale() As Boolean
  ResetAutoScale = m_bResetAutoScale
End Property

'------------------------------
Public Function ResetContents()
  DeleteContents
End Function

'------------------------------
Public Property Get ReadOnly() As Boolean
  ReadOnly = m_bReadOnly
End Property
'------------------------------
Public Function OpenLibrary(DBName As String, bReadonly As Boolean) As Boolean
  ' open the file
  On Error Resume Next
  If m_bLbrOpened Then
    OpenLibrary = True
    Exit Function
  End If
  OpenLibrary = False
  
  m_bFirstFieldMsg = False
  If Len(DBName) = 0 Then Exit Function
  If Not FileExists(DBName) Then Exit Function
  
  If bReadonly Then
    If Not OpenDBandVerify(Nothing, m_LbrDB, DBName, True, True) Then Exit Function
  Else
    If Not OpenDBandVerify(Nothing, m_LbrDB, DBName, False, False) Then Exit Function
  End If
  
  If Not VERIFY_ERR Then Exit Function
  m_strLibName = DBName
  m_bReadOnly = bReadonly
  m_bLbrOpened = True
  OpenLibrary = True
End Function

'------------------------------
Public Function CloseLibrary()
  On Error Resume Next
  If m_bLbrOpened Then
    m_LbrDB.Close
    Set m_LbrDB = Nothing
    m_bLbrOpened = False
  End If
End Function

'------------------------------
Public Function VerifyUpdateProjDBRevision(strTemplName As String, AppCtrl As Object) As Boolean
  ' check if Project Template and current DB have same schema and tables match
  Dim DBTempl As Database
  Dim bRet As Boolean
  
  On Error Resume Next
  VerifyUpdateProjDBRevision = False
  If Not m_bLbrOpened Then Exit Function
  If Len(strTemplName) = 0 Then Exit Function
  If Not FileExists(strTemplName) Then Exit Function
                                      
                                      'bExclusive, bReadonly
  If Not OpenDBandVerify(Nothing, DBTempl, strTemplName, False, True) Then Exit Function
  
'  ' check versions
' NO Versions in these Libs
'  bRet = GetDBVersion(m_DB, nVerCur, strRev)
'  If bRet Then
'    bRet = GetDBVersion(DBTempl, nVerTempl, strRev)
'  End If
  
  ' check/update schema
  bRet = DoTableUpdate(m_LbrDB, DBTempl, AppCtrl)
  DBTempl.Close
  VerifyUpdateProjDBRevision = bRet

#If APP_DEBUG Then
  VERIFY_ERR
#End If

End Function

'------------------------------
Public Function VerifyUpdateAllShapeDwgSizes(strTemplName As String, AppCtrl As Object, _
                        bModified As Boolean) As Boolean
  '' make all shapes DrawingSizes only same as master
  VerifyUpdateAllShapeDwgSizes = _
            DoVerifyUpdateAllShapes(strTemplName, AppCtrl, bModified, True)
End Function
'------------------------------
Public Function VerifyUpdateAllShapes(strTemplName As String, AppCtrl As Object, _
                        bModified As Boolean) As Boolean
  '' make all shapes same as master
  VerifyUpdateAllShapes = _
            DoVerifyUpdateAllShapes(strTemplName, AppCtrl, bModified, False)
End Function

'------------------------------
Private Function DoVerifyUpdateAllShapes(strTemplName As String, AppCtrl As Object, _
                        bModified As Boolean, ByVal bDwgSize As Boolean) As Boolean
  ' walk all shapes in all folders and update MyDB with templae info if required
  ' differences are dtermined by revision not being the same or
  ' MyDB does not have a copy of a Shape in templateDB
  Dim DBTempl As Database
  Dim bRet As Boolean
  Dim bModLocal As Boolean
  Dim rsFolderSrc As Recordset
  Dim collFolders As Collection
  Dim strFolder As String
  Dim i As Long
  
  On Error Resume Next
  
  DoVerifyUpdateAllShapes = False
  bModified = False
  If Not m_bLbrOpened Then Exit Function
  If Len(strTemplName) = 0 Then Exit Function
  If Not FileExists(strTemplName) Then Exit Function
                                      
                                      'bExclusive, bReadonly
  If Not OpenDBandVerify(Nothing, DBTempl, strTemplName, False, True) Then Exit Function
  
  'get all Folders from src
  bRet = True
  Set collFolders = New Collection
  Set rsFolderSrc = DBTempl.OpenRecordset("GeTblFolder", dbOpenTable, dbReadOnly)
  If Not VERIFY_ERR Then bRet = False
  If bRet Then
    With rsFolderSrc
      If Not .EOF And Not .BOF Then
        .MoveFirst
        Do
          strFolder = !FolderName
          collFolders.Add strFolder
          .MoveNext
        Loop While (Not .EOF)
        '
      End If
    End With
    rsFolderSrc.Close
  End If
  Set rsFolderSrc = Nothing
  '
  
  '' check/update TemplateDB ShapeFolders against project library
  If bRet Then
    For i = 1 To collFolders.Count
      strFolder = collFolders.Item(i)
      bRet = VerifyUpdateFolder(m_LbrDB, DBTempl, strFolder, bModLocal, bDwgSize)
      If Not bRet Then Exit For
      If bModLocal Then bModified = True
      bModLocal = False
    Next i
  End If
  ''
  Set collFolders = Nothing
  DBTempl.Close
  DoVerifyUpdateAllShapes = bRet

#If APP_DEBUG Then
  VERIFY_ERR
#End If

End Function

'------------------------------
Public Function CopyFolder(DBDest As Database, dbSRC As Database, _
                        ByVal FolderName As String, _
                        bModified As Boolean) As Boolean
  CopyFolder = VerifyUpdateFolder(DBDest, dbSRC, FolderName, bModified, False)
End Function
'------------------------------
Public Function LibraryHasDrawingSizeFields(DB As Database) As Boolean
  Dim bHasDefaultProps As Boolean
  LibraryHasDrawingSizeFields = DoLibraryHasDrawingSizeFields(DB, bHasDefaultProps)
End Function

'------------------------------
Private Function DoLibraryHasDrawingSizeFields(DB As Database, bHasDefaultProps As Boolean) As Boolean
  ' determine if DrawingWidth/Height fields are in DB struct
  Dim tblDef As TableDef
  Dim fld As Field
  Dim i As Long
  Dim bRet As Boolean
  
  On Error Resume Next
  Set tblDef = DB.TableDefs("GeTblShape")
  If Not tblDef Is Nothing Then
    For i = 0 To tblDef.Fields.Count - 1
      Set fld = tblDef.Fields(i)
      If fld.Name = "DrawingWidth" Then
        bRet = True
      ElseIf fld.Name = "AutoScaleOnInsert" Then
        bHasDefaultProps = True
      End If
      If (bRet And bHasDefaultProps) Then Exit For
    Next i
  End If
  '
  DoLibraryHasDrawingSizeFields = bRet

End Function

'------------------------------
Private Function VerifyUpdateFolder(DBProj As Database, DBTempl As Database, _
                        ByVal FolderName As String, bModified As Boolean, _
                        ByVal bDwgSize As Boolean) As Boolean
  ' check that all shapes in Folder match those in Template (by Revision)
  Dim rsFolderSrc As Recordset
  Dim rsFolderDst As Recordset
  Dim rsShapeSrc As Recordset
  Dim rsShapeDst As Recordset
  Dim strSQL As String
  Dim nFolderID As Long
  Dim nFolderIDDst As Long
  Dim strShapeName As String
  Dim bRet As Boolean
  Dim bUpdate As Boolean
  Dim nRevDst As Long
  Dim nRevSrc As Long
  'Dim strFolderDesc As String
  Dim bAdded As Boolean
  Dim bHasDwgSizeDST As Boolean, bHasDwgSizeSRC As Boolean
  Dim bHasDfltPropsSRC As Boolean, bHasDfltPropsDST As Boolean
  Dim bDoIt As Boolean
  
  On Error Resume Next
  VerifyUpdateFolder = False
  
  bHasDwgSizeSRC = DoLibraryHasDrawingSizeFields(DBTempl, bHasDfltPropsSRC)
  bHasDwgSizeDST = DoLibraryHasDrawingSizeFields(DBProj, bHasDfltPropsDST)
  
  
  Set rsFolderSrc = DBTempl.OpenRecordset("GeTblFolder", dbOpenTable, dbReadOnly)
  If Not VERIFY_ERR Then Exit Function
  If rsFolderSrc.EOF And rsFolderSrc.BOF Then
    VerifyUpdateFolder = True
    Exit Function
  End If
  Set rsFolderDst = DBProj.OpenRecordset("GeTblFolder", dbOpenTable, dbDenyWrite)
  If Not VERIFY_ERR Then
    rsFolderSrc.Close
    Exit Function
  End If
  '  get ID
  With rsFolderSrc
    .Index = "FolderName"
    .Seek "=", FolderName
    If Not .NoMatch Then
      nFolderID = !FolderID
'      strFolderDesc = "" & !FolderDesc
    Else
      rsFolderSrc.Close
      rsFolderDst.Close
      Exit Function
    End If
    .Close
  End With
    ' add new folder if needed
  With rsFolderDst
    .Index = "FolderName"
    .Seek "=", FolderName
    If .NoMatch Then
      .AddNew
      !FolderName = FolderName
'      !FolderDesc = strFolderDesc
      .Update
      ' get new folderID from rs
      .Move 0, .LastModified
      nFolderIDDst = !FolderID
      
      bModified = True
      bRet = True
    Else
      nFolderIDDst = !FolderID
    End If
    .Close
  End With
    
    ' Get all shapes in folder
  strSQL = "SELECT * " & _
      "FROM GeTblShape WHERE GeTblShape.FolderID = " & _
      nFolderID & " ORDER BY GeTblShape.ShapeName;"
  
  bRet = True
  Set rsShapeSrc = DBTempl.OpenRecordset(strSQL, dbOpenSnapshot, dbReadOnly)
  If Not (rsShapeSrc.EOF And rsShapeSrc.BOF) Then
    Set rsShapeDst = DBProj.OpenRecordset("GeTblShape", dbOpenTable, dbDenyWrite)
    If err = 0 Then
      
      rsShapeDst.Index = "FolderAndName"
      ' walk and update
      rsShapeSrc.MoveFirst
      Do
        strShapeName = rsShapeSrc!ShapeName
        bUpdate = False
        bAdded = False
        With rsShapeDst
          If Not (.EOF And .BOF) Then
            .Seek "=", nFolderIDDst, strShapeName
            If .NoMatch Then
              ' Add new
              .AddNew
              bUpdate = True
              bAdded = True
            Else
              ' check rev. If different, update Dst
              nRevSrc = rsShapeSrc!ShapeRevision
              nRevDst = !ShapeRevision
              If bDwgSize Or m_bResetAutoScale Then
                .Edit
                bUpdate = True
              Else
                If nRevSrc > nRevDst Then
                  .Edit
                  bUpdate = True
                End If
              End If
            End If
          Else
            ' Empty RS - Add new
            .AddNew
            bUpdate = True
            bAdded = True
          End If
          '
          bDoIt = False
          If bUpdate Then
            If bAdded Then
              !FolderID = nFolderIDDst ' rsShapeSrc!FolderID
              !ShapeName = rsShapeSrc!ShapeName
            End If
            If bAdded Then
              bDoIt = True
            ElseIf Not bDwgSize Then
              bDoIt = True
            End If
            '
            If m_bResetAutoScale Then
              bDoIt = True
            End If
            '
            If bDoIt Then
              !ShapeCreateDate = rsShapeSrc!ShapeCreateDate
              !ShapeModifyDate = rsShapeSrc!ShapeModifyDate
              !ShapeRevision = rsShapeSrc!ShapeRevision
              If Not IsNull(rsShapeSrc!ShapeDesc) Then !ShapeDesc = rsShapeSrc!ShapeDesc
              !ShapeGUID = rsShapeSrc!ShapeGUID
                ' OLE Blob
              !ShapeObject = rsShapeSrc!ShapeObject
            End If
            
            If (bHasDwgSizeSRC And bHasDwgSizeDST) Then
              If m_bResetAutoScale Then
                !DrawingWidth = 0#
                !DrawingHeight = 0#
              Else
                !DrawingWidth = rsShapeSrc!DrawingWidth
                !DrawingHeight = rsShapeSrc!DrawingHeight
              End If
            End If
            
            If (bHasDfltPropsSRC And bHasDfltPropsDST) Then
              !AutoScaleOnInsert = rsShapeSrc!AutoScaleOnInsert
              !CanMove = rsShapeSrc!CanMove
              !CanSelect = rsShapeSrc!CanSelect
              !ScaleMode = rsShapeSrc!ScaleMode
              !RotateMode = rsShapeSrc!RotateMode
              !UserDataFlt = rsShapeSrc!UserDataFlt
              If Not IsNull(rsShapeSrc!UserDataStr) Then !UserDataStr = rsShapeSrc!UserDataStr
            End If
            
            ''
            bRet = RecordsetUpdateWithRetry(rsShapeDst)
            bModified = True
          End If
          '
        End With
        rsShapeSrc.MoveNext
      Loop While ((Not rsShapeSrc.EOF) And bRet)
      ''
      rsShapeDst.Close
    '
    Else
      bRet = False
      VERIFY_ERR
    End If
  End If
  rsShapeSrc.Close
  '
  VerifyUpdateFolder = bRet

'  Err.Clear
#If APP_DEBUG Then
  ' 94 - Invalid use of Null
  If err <> 94 Then VERIFY_ERR
#End If
End Function

'------------------------------
Public Function UpdateShapeDifferences(strTemplName As String, collShapeDefInfo As Collection) As Boolean
  ' update all shapes in collection from Template to me
  ' : assume that DST is me, SRC is TemplateName
  Dim DBTempl As Database
  On Error Resume Next
  
  UpdateShapeDifferences = False
  If m_LbrDB Is Nothing Then Exit Function
  If Len(strTemplName) = 0 Then Exit Function
  If Not FileExists(strTemplName) Then Exit Function
                                      
                                      'bExclusive, bReadonly
  If Not OpenDBandVerify(Nothing, DBTempl, strTemplName, False, True) Then Exit Function
  UpdateShapeDifferences = DoUpdateShapeDifferences(m_LbrDB, DBTempl, collShapeDefInfo)
  ''
  DBTempl.Close
  
End Function

'------------------------------
Private Function DoUpdateShapeDifferences(DBDst As Database, dbSRC As Database, _
                          collInfo As Collection) As Boolean
  '' update all in coll
  Dim i As Long
  Dim objInfo As GeShapeDefInfo
  
  On Error Resume Next
  For i = 1 To collInfo.Count
    Set objInfo = collInfo.Item(i)
    If Not Update1Shape(DBDst, dbSRC, objInfo) Then Exit Function
  Next i
  
  DoUpdateShapeDifferences = True
End Function

'------------------------------
Private Function Update1Shape(DBDst As Database, dbSRC As Database, _
                          objInfo As GeShapeDefInfo) As Boolean
  ' check that all shapes in Folder match those in Template (by Revision)
  Dim rsFolderDst As Recordset
  Dim rsShapeSrc As Recordset
  Dim rsShapeDst As Recordset
  Dim nFolderID As Long, nFolderIDDst As Long
  Dim bRet As Boolean
  Dim bAdded As Boolean
  Dim bGotSRC As Boolean
  Dim bHasDwgSizeDST As Boolean
  Dim bHasDwgSizeSRC As Boolean
  Dim bHasDfltPropsSRC As Boolean, bHasDfltPropsDST As Boolean

  On Error Resume Next
  
  bHasDwgSizeSRC = DoLibraryHasDrawingSizeFields(dbSRC, bHasDfltPropsSRC)
  bHasDwgSizeDST = DoLibraryHasDrawingSizeFields(DBDst, bHasDfltPropsDST)
  
  Set rsFolderDst = DBDst.OpenRecordset("GeTblFolder", dbOpenTable, dbDenyWrite)
  If Not VERIFY_ERR Then
    Exit Function
  End If
    ' add new folder if needed
  With rsFolderDst
    .Index = "FolderName"
    .Seek "=", objInfo.FolderName
    If .NoMatch Then
      .AddNew
      !FolderName = objInfo.FolderName
      .Update
      ' get new folderID from rs
      .Move 0, .LastModified
      nFolderIDDst = !FolderID
    Else
      nFolderIDDst = !FolderID
    End If
    .Close
  End With
  Set rsFolderDst = Nothing
  
  '' get id from Src and position to rs with shape to copy
  bGotSRC = False
  If Not GetFolderIDByName(dbSRC, objInfo.FolderName, nFolderID, False) Then Exit Function  ' bcreate
  Set rsShapeSrc = dbSRC.OpenRecordset("GeTblShape", dbOpenTable, dbReadOnly)
  If err = 0 Then
    rsShapeSrc.Index = "FolderAndName"
    With rsShapeSrc
      If Not (.EOF And .BOF) Then
        .Seek "=", nFolderID, objInfo.ShapeName
        If Not .NoMatch Then
          bGotSRC = True
        End If
      End If
    End With
  End If
  If Not bGotSRC Then
    rsShapeSrc.Close
    Exit Function
  End If
  ''
  Set rsShapeDst = DBDst.OpenRecordset("GeTblShape", dbOpenTable, dbDenyWrite)
  If err = 0 Then
    rsShapeDst.Index = "FolderAndName"
    With rsShapeDst
      If Not (.EOF And .BOF) Then
        .Seek "=", nFolderIDDst, objInfo.ShapeName
        If .NoMatch Then
          .AddNew
          bAdded = True
        Else
          .Edit
        End If
      Else
        ' Empty RS - Add new
        .AddNew
        bAdded = True
      End If
      ''
      If bAdded Then
        !FolderID = nFolderIDDst ' rsShapeSrc!FolderID
        !ShapeName = rsShapeSrc!ShapeName
      End If
      !ShapeCreateDate = rsShapeSrc!ShapeCreateDate
      !ShapeModifyDate = rsShapeSrc!ShapeModifyDate
      !ShapeRevision = rsShapeSrc!ShapeRevision
      If Not IsNull(rsShapeSrc!ShapeDesc) Then !ShapeDesc = rsShapeSrc!ShapeDesc
      !ShapeGUID = rsShapeSrc!ShapeGUID
        ' OLE Blob
      !ShapeObject = rsShapeSrc!ShapeObject
      
      If (bHasDwgSizeSRC And bHasDwgSizeDST) Then
        !DrawingWidth = rsShapeSrc!DrawingWidth
        !DrawingHeight = rsShapeSrc!DrawingHeight
      End If
      
      If (bHasDfltPropsSRC And bHasDfltPropsDST) Then
        !AutoScaleOnInsert = rsShapeSrc!AutoScaleOnInsert
        !CanMove = rsShapeSrc!CanMove
        !CanSelect = rsShapeSrc!CanSelect
        !ScaleMode = rsShapeSrc!ScaleMode
        !RotateMode = rsShapeSrc!RotateMode
        !UserDataFlt = rsShapeSrc!UserDataFlt
        If Not IsNull(rsShapeSrc!UserDataStr) Then !UserDataStr = rsShapeSrc!UserDataStr
      End If
      
      ''
      bRet = RecordsetUpdateWithRetry(rsShapeDst)
      '
    End With
    '
    rsShapeDst.Close
  End If
    ''
  rsShapeSrc.Close
  '
  Update1Shape = bRet

'  Err.Clear
#If APP_DEBUG Then
  ' 94 - Invalid use of Null
  If err <> 94 Then VERIFY_ERR
#End If
End Function

'------------------------------
Public Function GetAllShapeDifferences(strTemplName As String, collShapeDefInfo As Collection) As Boolean
  ' walk all shapes in all folders and get those that are different in MyDB
  ' : assume that DST is me, SRC is TemplateName
  Dim DBTempl As Database
  On Error Resume Next
  
  GetAllShapeDifferences = False
  If m_LbrDB Is Nothing Then Exit Function
  If Len(strTemplName) = 0 Then Exit Function
  If Not FileExists(strTemplName) Then Exit Function
                                      'bExclusive, bReadonly
  If Not OpenDBandVerify(Nothing, DBTempl, strTemplName, False, True) Then Exit Function
  GetAllShapeDifferences = DoGetAllShapeDifferences(m_LbrDB, DBTempl, collShapeDefInfo)
  ''
  DBTempl.Close
  
End Function

'------------------------------
Private Function DoGetAllShapeDifferences(DBDst As Database, dbSRC As Database, _
                          collRet As Collection) As Boolean
  ' walk all shapes in all folders and get those that are different in MyDB
  ' : assume that DST is me, SRC is TemplateName
  Dim collFoldersSRC As Collection, collFoldersDST As Collection
  Dim collInfoSRC As Collection, collInfoDST As Collection
  Dim objSRC As GeShapeDefInfo, objDST As GeShapeDefInfo
  Dim objRet As GeShapeDefInfo
  Dim FolderName As String, ShapeName As String
  Dim i As Long
  Dim iSRC As Long, iDST As Long
  Dim bRet As Boolean
  Dim bGotIt As Boolean
  
    
  On Error Resume Next
  Set collFoldersSRC = New Collection
  Set collFoldersDST = New Collection
  Set collInfoSRC = New Collection
  Set collInfoDST = New Collection
  
  bRet = True
  '' get all from SRC
  If DoGetAllFolders(dbSRC, collFoldersSRC) Then
    For i = 1 To collFoldersSRC.Count
      FolderName = collFoldersSRC.Item(i)
      bRet = DoGetAllShapesForFolder(dbSRC, collInfoSRC, FolderName)
      If Not bRet Then Exit For
    Next i
  End If
  Set collFoldersSRC = Nothing
  '' get all from DST
  If bRet Then
    If DoGetAllFolders(DBDst, collFoldersDST) Then
      For i = 1 To collFoldersDST.Count
        FolderName = collFoldersDST.Item(i)
        bRet = DoGetAllShapesForFolder(DBDst, collInfoDST, FolderName)
        If Not bRet Then Exit For
      Next i
    End If
  End If
  Set collFoldersDST = Nothing
  
  '' resolve and generate results
    ' look for dst matching src by Folder/Shape.
    ' if in src & dst, add to collRet
    ' if Src not in Dst, add to collRet
  If bRet Then
    For iSRC = 1 To collInfoSRC.Count
      bGotIt = False
      Set objSRC = collInfoSRC.Item(iSRC)
      FolderName = UCase(objSRC.FolderName)
      ShapeName = UCase(objSRC.ShapeName)
      '
      For iDST = 1 To collInfoDST.Count
        Set objDST = collInfoDST.Item(iDST)
        If UCase(objDST.FolderName) = FolderName Then
          If UCase(objDST.ShapeName) = ShapeName Then
            bGotIt = True
            If objSRC.Revision <> objDST.Revision Then
            '
              Set objRet = objSRC.Copy
              collRet.Add objRet
              objRet.RevisionDST = objDST.Revision
              Exit For
            '
            End If
          End If
        End If
      Next iDST
      ' add src to return if not in dst
      If Not bGotIt Then
        collRet.Add objSRC
      End If
      '
    Next iSRC
  End If
  ''
  Set collInfoSRC = Nothing
  Set collInfoDST = Nothing
  
  DoGetAllShapeDifferences = bRet
  
#If APP_DEBUG Then
  VERIFY_ERR
#End If

End Function

'=======================================================
' Retrieval
'=======================================================
'------------------------------
Public Function EnsureFolderExists(ByVal FolderName As String) As Boolean
  ' have LbrMgr check if the folder is there. If not, it will create a new folder
  Dim bCreate As Boolean
  Dim nFolderID As Long
  
  On Error Resume Next

  bCreate = True    ' will create if not there
  EnsureFolderExists = GetFolderIDByName(m_LbrDB, FolderName, nFolderID, bCreate)

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Public Function GetAllFolders(coll As Collection) As Boolean
  On Error Resume Next
  If Not m_bLbrOpened Then Exit Function
  GetAllFolders = DoGetAllFolders(m_LbrDB, coll)
End Function
'------------------------------
Private Function DoGetAllFolders(DB As Database, coll As Collection) As Boolean
  ' get all FolderName - Names only as string added to coll
  Dim rsFolder As Recordset
  Dim nFolderID As Long
  Dim FolderName As String
  Dim bRet As Boolean
  
  On Error Resume Next

  Set rsFolder = DB.OpenRecordset("GeTblFolder", dbOpenSnapshot, dbReadOnly)
  If err <> 0 Then
    ShowStatusMsg Error
    Exit Function
  End If
  If rsFolder.EOF Or rsFolder.BOF Then
    rsFolder.Close
    DoGetAllFolders = True
    Exit Function
  End If
  '
  rsFolder.MoveFirst
  bRet = True
  Do While Not rsFolder.EOF
    nFolderID = rsFolder!FolderID
    FolderName = rsFolder!FolderName
    coll.Add FolderName
    rsFolder.MoveNext
  Loop
  '
  rsFolder.Close
  DoGetAllFolders = bRet

'  Err.Clear
#If APP_DEBUG Then
  ' 94 - Invalid use of Null
  If err <> 94 Then VERIFY_ERR
#End If
  
End Function
'------------------------------
Public Function GetAllShapesForFolder(collInfo As Collection, FolderName As String) As Boolean
  ' get all Shapes as ShapeDefInfo for given Folder
  
  On Error Resume Next
  If Not m_bLbrOpened Then Exit Function
  GetAllShapesForFolder = DoGetAllShapesForFolder(m_LbrDB, collInfo, FolderName)

End Function

'------------------------------
Public Function GetShapeDefInfo_ByLibFolderShape(LibName As String, FolderName As String, _
                                         strShape As String) As GeShapeDefInfo
  ' get shapedef info by Library, Folder and Shape
  Dim rsShape As Recordset
  Dim objInfo As GeShapeDefInfo
  Dim DB As Database
  Dim bMine As Boolean
  
  On Error Resume Next
  If UCase(LibName) <> UCase(m_strLibName) Then
    If Len(LibName) = 0 Then Exit Function
    If Not FileExists(LibName) Then Exit Function
    
'    If Not OpenDBandVerify(Nothing, DB, LibName, False, True) Then   'bReadonly = true
    If Not OpenDBandVerify(Nothing, DB, LibName, True, True) Then   ', bExclusive, bReadonly = true
      Exit Function
    End If
    If Not VERIFY_ERR Then Exit Function
    
  Else
    Set DB = m_LbrDB
    bMine = True
  End If
  ''
  Dim bHasDwgSizeSRC As Boolean, bHasDfltPropsSRC As Boolean
  bHasDwgSizeSRC = DoLibraryHasDrawingSizeFields(DB, bHasDfltPropsSRC)
  
  If GetShapeRecord(DB, FolderName, strShape, rsShape, True) Then
    With rsShape
      Set objInfo = New GeShapeDefInfo
      objInfo.FolderName = FolderName
      objInfo.Revision = !ShapeRevision
      objInfo.ShapeName = !ShapeName
      objInfo.ShapeID = !ShapeID
      objInfo.LibraryName = LibName
      objInfo.ShapeGUID = !ShapeGUID
      
      If (bHasDfltPropsSRC) Then
        objInfo.HasDefaultProps = bHasDfltPropsSRC
        objInfo.AutoScaleOnInsert = !AutoScaleOnInsert
        objInfo.CanMove = !CanMove
        objInfo.CanSelect = !CanSelect
        objInfo.ScaleMode = !ScaleMode
        objInfo.RotateMode = !RotateMode
        objInfo.UserDataFlt = !UserDataFlt
        If Not IsNull(!UserDataStr) Then objInfo.UserDataStr = !UserDataStr
      End If
      
      .Close
    End With
    Set GetShapeDefInfo_ByLibFolderShape = objInfo
  End If
  '
  If Not bMine Then DB.Close
  

#If APP_DEBUG Then
  ' 94 - Invalid use of Null
  If err <> 94 Then VERIFY_ERR
#End If

End Function
'------------------------------
Public Function GetShapeDefInfo_ByFolderAndShape(FolderName As String, _
                                         strShape As String) As GeShapeDefInfo
  ' get shapedef info by Folder and Shape
  Dim rsShape As Recordset
  Dim objInfo As GeShapeDefInfo
  
  On Error Resume Next
  If Not m_LbrDB Is Nothing Then
    
    Dim bHasDwgSizeSRC As Boolean, bHasDfltPropsSRC As Boolean
    bHasDwgSizeSRC = DoLibraryHasDrawingSizeFields(m_LbrDB, bHasDfltPropsSRC)
    
    If GetShapeRecord(m_LbrDB, FolderName, strShape, rsShape, True) Then
      With rsShape
        Set objInfo = New GeShapeDefInfo
        objInfo.FolderName = FolderName
        objInfo.Revision = !ShapeRevision
        objInfo.ShapeName = !ShapeName
        objInfo.ShapeID = !ShapeID
        objInfo.LibraryName = m_strLibName
        objInfo.ShapeGUID = !ShapeGUID
      
        If (bHasDfltPropsSRC) Then
          objInfo.HasDefaultProps = bHasDfltPropsSRC
          objInfo.AutoScaleOnInsert = !AutoScaleOnInsert
          objInfo.CanMove = !CanMove
          objInfo.CanSelect = !CanSelect
          objInfo.ScaleMode = !ScaleMode
          objInfo.RotateMode = !RotateMode
          objInfo.UserDataFlt = !UserDataFlt
          If Not IsNull(!UserDataStr) Then objInfo.UserDataStr = !UserDataStr
        End If
        
        
        .Close
      End With
      Set GetShapeDefInfo_ByFolderAndShape = objInfo
    End If
  End If
End Function

'------------------------------
Public Function UpdateDefaultProperties(objInfo As GeShapeDefInfo) As Boolean
  ' only write the default prop info to DB
  Dim rsShape As Recordset
  
  On Error Resume Next
  If objInfo.HasDefaultProps And m_bLbrOpened Then
    If GetShapeRecord(m_LbrDB, objInfo.FolderName, objInfo.ShapeName, rsShape, False) Then
      With rsShape
        .Edit
        
        !AutoScaleOnInsert = objInfo.AutoScaleOnInsert
        !CanMove = objInfo.CanMove
        !CanSelect = objInfo.CanSelect
        !ScaleMode = objInfo.ScaleMode
        !RotateMode = objInfo.RotateMode
        !UserDataFlt = objInfo.UserDataFlt
        !UserDataStr = objInfo.UserDataStr
        
        .Update
        .Close
        UpdateDefaultProperties = True
      End With
    End If
  End If
End Function

'------------------------------
Private Function DoGetAllShapesForFolder(DB As Database, collInfo As Collection, _
                  FolderName As String) As Boolean
  ''
  Dim strSQL As String
  Dim rsShape As Recordset
  Dim strShape As String
  Dim objInfo As GeShapeDefInfo
  Dim nFolderID As Long
  Dim DBName As String
  
  On Error Resume Next
  If Not GetFolderIDByName(DB, FolderName, nFolderID, False) Then Exit Function  ' bcreate
  
  Dim bHasDwgSizeSRC As Boolean, bHasDfltPropsSRC As Boolean
  bHasDwgSizeSRC = DoLibraryHasDrawingSizeFields(DB, bHasDfltPropsSRC)
  
  DBName = DB.Name
'  strSQL = "SELECT GeTblShape.ShapeName, GeTblShape.ShapeRevision " &
  strSQL = "SELECT * " & _
      "FROM GeTblShape WHERE GeTblShape.FolderID = " & _
      nFolderID & " ORDER BY GeTblShape.ShapeName;"
      
  Set rsShape = DB.OpenRecordset(strSQL, dbOpenSnapshot, dbReadOnly)
  If VERIFY_ERR Then
    With rsShape
      If Not .EOF And Not .BOF Then
          ' get em
        .MoveFirst
        Do While Not .EOF
          Set objInfo = New GeShapeDefInfo
          collInfo.Add objInfo
          objInfo.FolderName = FolderName
          objInfo.Revision = !ShapeRevision
          objInfo.ShapeName = !ShapeName
          objInfo.ShapeID = !ShapeID
          objInfo.LibraryName = DBName
          objInfo.ShapeGUID = !ShapeGUID
          If (bHasDfltPropsSRC) Then
            objInfo.HasDefaultProps = bHasDfltPropsSRC
            objInfo.AutoScaleOnInsert = !AutoScaleOnInsert
            objInfo.CanMove = !CanMove
            objInfo.CanSelect = !CanSelect
            objInfo.ScaleMode = !ScaleMode
            objInfo.RotateMode = !RotateMode
            objInfo.UserDataFlt = !UserDataFlt
            If Not IsNull(!UserDataStr) Then objInfo.UserDataStr = !UserDataStr
          End If
          
          '
          .MoveNext
        Loop
      End If
    End With
  Else
    ShowStatusMsg Error
  End If
  '
  If Not rsShape Is Nothing Then rsShape.Close
  
  DoGetAllShapesForFolder = True

#If APP_DEBUG Then
  ' 94 - Invalid use of Null
  If err <> 94 Then VERIFY_ERR
#End If
  
End Function

'++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
'------------------------------
Private Function GetFolderIDByName(DB As Database, strFolder As String, nFolderID As Long, bCreate As Boolean) As Boolean
  ' Get FolderID
  ' if bCreate and not found, create Folder with the name
  Dim rsFolder As Recordset
  Dim bRet As Boolean
  
  On Error Resume Next
  Set rsFolder = DB.OpenRecordset("GeTblFolder", dbOpenTable, dbReadOnly)
  If VERIFY_ERR Then
    With rsFolder
      If Not .EOF And Not .BOF Then
        .Index = "FolderName"
        .Seek "=", strFolder
        If Not .NoMatch Then
          nFolderID = !FolderID
          bRet = True
        End If
      End If
      .Close
    End With
  End If
  Set rsFolder = Nothing
  
  ' create if req'd
  If Not bRet And bCreate And (Len(strFolder) > 0) Then
    Set rsFolder = DB.OpenRecordset("GeTblFolder", dbOpenTable, dbDenyWrite)
    If VERIFY_ERR Then
      With rsFolder
        .AddNew
        !FolderName = strFolder
        .Update
        If err = 0 Then
          .Move 0, .LastModified
          nFolderID = !FolderID
          bRet = True
        End If
        .Close
      End With
    End If
    Set rsFolder = Nothing
  End If
  '
  GetFolderIDByName = bRet
  
End Function
'------------------------------
Private Function GetShapeRecord(DB As Database, strFolder As String, strShape As String, _
                          rsShape As Recordset, bReadonly As Boolean) As Boolean
  ' find and move to the Record
  ' return true and set ref to rsShape if found
  Dim nFolderID As Long
  Dim bGotIt As Boolean
  Dim nMode As Long
  
  GetShapeRecord = False
  On Error Resume Next
  If Not GetFolderIDByName(DB, strFolder, nFolderID, False) Then Exit Function ' bcreate
 
  ''
  If bReadonly Then
    nMode = dbReadOnly
  Else
    nMode = dbDenyWrite
  End If
  '
  bGotIt = False
  Set rsShape = DB.OpenRecordset("GeTblShape", dbOpenTable, nMode)
  If err = 0 Then
    If Not rsShape.EOF And Not rsShape.BOF Then
      rsShape.Index = "FolderAndName"
      rsShape.Seek "=", nFolderID, strShape
      If Not rsShape.NoMatch Then
        bGotIt = True
      Else
        bGotIt = False
      End If
    End If
    '
    If Not bGotIt Then
      rsShape.Close
      Set rsShape = Nothing
    End If
  End If
  GetShapeRecord = bGotIt

  #If APP_DEBUG Then
  VERIFY_ERR
  #End If
End Function

'------------------------------
Public Function PutPictureInShapeField(pic As Picture, strFolder As String, strShape As String) As Boolean
  ' save picture to Field
  Dim fld As Field
  Dim rsShape As Recordset
  Dim bRet As Boolean
  
  If Not m_bLbrOpened Then Exit Function
  On Error Resume Next
  If GetShapeRecord(m_LbrDB, strFolder, strShape, rsShape, False) Then  ' bReadonly
    Set fld = rsShape.Fields("ShapePicture")
    If Not fld Is Nothing Then
      rsShape.Edit
      bRet = PutPictureInOleField(pic, fld)
      If bRet Then
        rsShape.Update
      Else
        MsgBox Error
      End If
    Else
      MsgBox "Invalid GE Library Schema"
    End If
    '
    rsShape.Close
  End If
  PutPictureInShapeField = bRet
  
  #If APP_DEBUG Then
  VERIFY_ERR
  #End If
End Function

'------------------------------
Private Function PutPictureInOleField(pic As Picture, OleField As Field) As Boolean
  Dim tempFileName As String
  Dim bRet As Boolean
  
  On Error Resume Next
  PutPictureInOleField = False
    
  If OleField.Type = DT_LONGBINARY Then
    If GenerateTempFileName(tempFileName) Then
      SavePicture pic, tempFileName
      bRet = CopyFileToOleField(OleField, tempFileName)
      Kill tempFileName
    End If
  End If
  PutPictureInOleField = bRet

  #If APP_DEBUG Then
  VERIFY_ERR
  #End If
End Function

'------------------------------
Public Function GetPictureFromShapeField(picObj As Object, strFolder As String, strShape As String) As Boolean
  ' get picture from Field
  Dim fld As Field
  Dim rsShape As Recordset
  Dim bRet As Boolean
  Dim pic As VB.PictureBox
  
  On Error Resume Next
  
  If Not m_bLbrOpened Then Exit Function
  If Not TypeOf picObj Is VB.PictureBox Then Exit Function
  
  Set pic = picObj
  
  If GetShapeRecord(m_LbrDB, strFolder, strShape, rsShape, True) Then  ' bReadonly
    Set fld = rsShape.Fields("ShapePicture")
    If Not fld Is Nothing Then
      bRet = GetPictureFromOleField(pic, fld)
    Else
      If Not m_bFirstFieldMsg Then
        MsgBox "Invalid GE Library Schema"
        m_bFirstFieldMsg = True
      End If
    End If
    '
    rsShape.Close
  End If
  GetPictureFromShapeField = bRet
  
  #If APP_DEBUG Then
  VERIFY_ERR
  #End If

End Function
'------------------------------
Private Function GetPictureFromOleField(pic As VB.PictureBox, OleField As Field) As Boolean
  Dim tempFileName As String
  Dim bRet As Boolean
  
  On Error Resume Next
  GetPictureFromOleField = False
    
  If OleField.Type = DT_LONGBINARY Then
    If GenerateTempFileName(tempFileName) Then
      bRet = CopyOleFieldToFile(OleField, tempFileName)
      If bRet Then
        pic.Picture = LoadPicture(tempFileName)
      Else
        pic.Picture = LoadPicture()   ' clear it
      End If
      Kill tempFileName
    End If
  End If
  GetPictureFromOleField = bRet

  #If APP_DEBUG Then
  VERIFY_ERR
  #End If
End Function

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
      strMsg = TypeName(Me) & ":VERIFY_ERR Failed:" & Error
      ShowStatusMsg strMsg
    #End If
    VERIFY_ERR = False
  End If
End Function


