Attribute VB_Name = "mDBHelper"
'======================================================================================
'
' Module:   mDBHelper
'
'--------------------------------------------------------------------------------------
'======================================================================================

Option Explicit

'=================================================================
' Start of Declarations Section
'=================================================================

'
' structures for table management
'

Public Type FieldList    ' a DB field
  szFieldName As String
  nFieldType As Integer
  nFieldSize As Integer
  nAllowZeroLength As Integer
  DefaultValue As Variant
  nOrdinalPosition As Integer
  nColumnOrder As Long
  szDescription As String
  bAutoNumber As Boolean  ' auto inc.
End Type

Public Type IndexList    ' a DB Index
  szIndexName As String
  nPrimary As Integer
  nUnique As Integer
  nStartField As Integer
  nEndField As Integer
End Type


Public Type RelationList   ' relation
  szRelationName As String
  szTableName As String
  szForeignTable As String
  nAttributes As Long
  nStartField As Integer
  nEndField As Integer
End Type

Public Type RelationField
  szName As String
  szForeignName As String
End Type


'=================================================================
' End of Declarations Section
'=================================================================

'======================================================================================
' Db Functions
'======================================================================================
'------------------------------
Public Function OpenDBandVerify(WSIn As Workspace, DB As Database, DBName As String, bExclusive As Boolean, bReadonly As Boolean) As Boolean
  ' Open database and test if corrupt. Process Error Related to Database Objects
  ' Repair if required!
  Const errDatabaseCorrupt = 1000
  Dim strMsg As String
  Dim errTmp As Error
  Dim WS As Workspace

  
  On Error Resume Next
  OpenDBandVerify = False
  If WSIn Is Nothing Then
    Set WS = DBEngine.Workspaces(0)
  Else
    Set WS = WSIn
  End If
  '
  If WS Is Nothing Then
    If Err <> 0 Then
      gMsgWnd.LogMessage "Database Error: " & Err.Description
      Err = 0
    End If
    OpenDBandVerify = False
    Exit Function
  End If
  '
  Set DB = WS.OpenDatabase(DBName, bExclusive, bReadonly)
  
  If DBEngine.Errors.count > 0 Then
    ' If it’s a corrupt error, then attempt to repair.
    For Each errTmp In DBEngine.Errors
      If errTmp.Number = errDatabaseCorrupt Then
        strMsg = "Database '" & DBName & "' is corrupt. Attempting repair..."
        gMsgWnd.LogMessage strMsg
        DBEngine.RepairDatabase DBName
        strMsg = "You should now exit and Compact '" & DBName & "' using MSAccess"
        gMsgWnd.LogMessage strMsg
        OpenDBandVerify = False
        Exit For
      Else
        OpenDBandVerify = True
      End If
    Next
  Else
    OpenDBandVerify = True
  End If
End Function

'------------------------------
Public Function RecordsetUpdateWithRetry(RS As Recordset) As Boolean
  ' do up to 60 retries ( 1 second each)
  Dim bRet As Boolean
  Dim bLoop As Boolean
  Dim timeCur As Long, timeStart As Long
  Dim nTries As Integer
  Dim bDoIt As Boolean
  Dim strErr As String
  
  On Error Resume Next
  nTries = 0
  bRet = False
  bLoop = True
  
  While bLoop
    RS.Update
    If Err = 0 Then
      RecordsetUpdateWithRetry = True
      Exit Function
    Else
      ' locked by another user or other
      strErr = Err.Description
      bDoIt = True
      Select Case Err
        Case 3186
        Case 3187
        Case 3188
        Case 3189
        Case 3202
        Case 3211
        Case 3212
        Case 3218
        
        Case Else
          bDoIt = False
      End Select
      '
      If bDoIt Then
        Err = 0
        timeStart = timeGetTime
        timeCur = 0
        If nTries < 60 Then
          nTries = nTries + 1
            ' wait 1 second
          Do While (timeCur < 1000)
            timeCur = timeGetTime - timeStart
            DoEvents
          Loop
        Else
          bLoop = False
        End If
      Else
        bLoop = False
      End If
    End If
  Wend
  
  If Not bRet Then
    gMsgWnd.LogMessage strErr
  End If
  RecordsetUpdateWithRetry = bRet
End Function

'------------------------------
Public Function RecordsetDeleteWithRetry(RS As Recordset) As Boolean
  ' do up to 60 retries ( 1 second each)
  Dim bRet As Boolean
  Dim bLoop As Boolean
  Dim timeCur As Long, timeStart As Long
  Dim nTries As Integer
  Dim strErr As String
  
  On Error Resume Next
  nTries = 0
  bRet = False
  bLoop = True
  
  While bLoop
    RS.Delete
    If Err = 0 Then
      RecordsetDeleteWithRetry = True
      Exit Function
    ElseIf Err = 3086 Then  ' locked by another user
      strErr = Err.Description
      Err = 0
      timeStart = timeGetTime
      timeCur = 0
      If nTries < 60 Then
        nTries = nTries + 1
          ' wait 1 second
        Do While (timeCur < 1000)
          timeCur = timeGetTime - timeStart
          DoEvents
        Loop
      Else
        bLoop = False
      End If
    Else
      strErr = Err.Description
      bLoop = False
    End If
  Wend
  
  If Not bRet Then gMsgWnd.LogMessage strErr
  RecordsetDeleteWithRetry = bRet
End Function

'------------------------------
Public Function DoOpenTable(DB As Database, tbl As Recordset, _
                    tblName As String, nMode As Long, _
                    modeFlags As Long) As Boolean
  ' attempt to open a table
  ' do up to 60 retries ( 1 second each)
  Dim bRet As Boolean
  Dim bLoop As Boolean
  Dim timeCur As Long, timeStart As Long
  Dim nTries As Integer
  Dim bDoIt As Boolean
  Dim strErr As String
  
  On Error Resume Next
  nTries = 0
  bRet = False
  bLoop = True
  
  While bLoop
    Set tbl = DB.OpenRecordset(tblName, nMode, modeFlags)
    If Err = 0 Then
      DoOpenTable = True
      Exit Function
    Else
      ' locked by another user or something else
      strErr = Err.Description
      bDoIt = True
      Select Case Err
        Case 3262 ' Couldn't lock table 'Projects'; currently in use by user 'Admin' on machine 'MCEWEN'.
'        Case 3186
'        Case 3187
'        Case 3188
'        Case 3189
'        Case 3202
'        Case 3211
'        Case 3212
'        Case 3218
        
        Case Else
          bDoIt = False
      End Select
      '
      If bDoIt Then
        Err = 0
        timeStart = timeGetTime
        timeCur = 0
        If nTries < 60 Then
          nTries = nTries + 1
            ' wait 1 second
          Do While (timeCur < 1000)
            timeCur = timeGetTime - timeStart
            DoEvents
          Loop
        Else
          bLoop = False
        End If
      Else
        bLoop = False
      End If
    End If
  Wend
  If Not bRet Then gMsgWnd.LogMessage strErr
  DoOpenTable = bRet
End Function




'-----------------------------------------------------------------
' Function TableExists
'
' Purpose:  Test for the existance of a table in a database
'
' Arguments:
'   DB As Database - the Database object
'   strName As String - name of the table
'
' Returns:
'   Boolean: True if table exists, False if not
'-----------------------------------------------------------------

Public Function TableExists(DB As Database, strName As String) As Boolean
  ' see if table of given name exists
  Dim i As Integer
  Dim tblDef As TableDef
  
  On Error Resume Next
  TableExists = True
  For i = 0 To DB.TableDefs.count - 1
    Set tblDef = DB.TableDefs(i)
    If (tblDef.Name = strName) Then Exit Function
  Next i
  TableExists = False
End Function

'-----------------------------------------------------------------
' Function DeleteTableContents
'
' Purpose:  Deletes all records of a table
'
' Arguments:
'   DB As Database - the Database object
'   strName As String - name of the table
'
' Returns:
'   Boolean: True if successful, False if not
'-----------------------------------------------------------------

Public Function DeleteTableContents(DB As Database, strName As String) As Boolean
  ' remove all contents of the table
  Dim tbl As Recordset
  
  On Error Resume Next
  DeleteTableContents = False
  Set tbl = DB.OpenRecordset(strName, dbOpenTable, dbDenyWrite)
  If Err <> 0 Then
    If Err = 3112 Then
        'Record(s) can't be read; no read permission on 'MSysACEs'.
      DeleteTableContents = True
      Exit Function
    Else
      VERIFY_ERR
      Exit Function
    End If
  End If
  While Not (tbl.EOF And tbl.BOF)
    tbl.MoveLast
    tbl.Delete
  Wend
  tbl.Close
  DeleteTableContents = True
End Function

'-----------------------------------------------------------------
' Function Table_Replicate
'
' Purpose: Replicates a table. Copy table structure and indexes.
'
' Arguments:
'   DBFrom As Database - the source Database object
'   DBTo As Database - the destination Database object
'   szOldTableName As String - name of source table
'   szNewTableName As String - name of destination table
'
' Returns:
'   Boolean: True if successful, False if not
'-----------------------------------------------------------------

Public Function Table_Replicate(DBFrom As Database, DBTo As Database, _
        szOldTableName As String, szNewTableName As String) As Boolean
  ' create a copy of the table and its indexes using the new name
  Dim ncField As Integer
  Dim ncIndex As Integer
  Dim bSysTable As Boolean
  Dim bRet As Boolean
  
  ReDim FieldList(0) As FieldList
  ReDim IndexList(0) As IndexList
  ReDim IndexFieldList(0) As String
  
  Table_Replicate = False
  bRet = TableStructure_Read(DBFrom, szOldTableName, FieldList(), ncField, _
              IndexList(), ncIndex, IndexFieldList(), bSysTable)
  
  If bSysTable Then
    Exit Function
  End If
  
  If bRet Then
    Table_Replicate = Table_Add(DBTo, szNewTableName, FieldList(), ncField, _
                  IndexList(), ncIndex, IndexFieldList())
  End If
End Function

'-----------------------------------------------------------------
' Function DoTableUpdate
'
' Purpose: Updates DBProj Database structure with tables from DBTempl.
'          Tables will be added, Field are added or modified, Indexes
'          are added, removed or modified. All the table records within
'          the DBProj Database will be preserved. Fields withing a table
'          are not removed.
'
' Arguments:
'   DBProj As Database - the source Database object
'   DBTempl As Database - the destination Database object
'   AppCtrl As Object - Optional, used for call back of progress
'
' Returns:
'   Boolean: True if successful, False if not
'-----------------------------------------------------------------

Public Function DoTableUpdate(DBProj As Database, DBTempl As Database, _
                Optional AppCtrl As Object = Nothing) As Boolean
  ' walk all tables in DBTempl and do update to Project
  Dim TableDef As TableDef
  Dim strTableName As String
  Dim bRet As Boolean
  Dim i As Integer
  Dim nCnt As Integer
  
  On Error Resume Next
  '
  nCnt = DBTempl.TableDefs.count - 1
  For i = 0 To nCnt
    ' get name then release
    Set TableDef = DBTempl.TableDefs(i)
    strTableName = TableDef.Name
    ' status bar updates
    If Not AppCtrl Is Nothing Then
      AppCtrl.SetProgressValue CInt((CDbl(i + 1) / CDbl(nCnt)) * 100)
    End If
    ' ensure table in ProjDB
    bRet = VerifyAddTable(DBProj, DBTempl, strTableName, TableDef)
    If bRet Then
        ' check and refresh struct and data
      bRet = TableStructure_Update(DBProj, DBTempl, strTableName)
    End If
  '
    If Not bRet Then Exit For
  Next i
  '
  If Not AppCtrl Is Nothing Then
    AppCtrl.SetProgressValue 0
  End If
  
  DoTableUpdate = bRet
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'-----------------------------------------------------------------
' Function SingleTableUpdate
'
' Purpose: Updates strTableName Table structure.
'          Tables will be added, Field are added or modified, Indexes
'          are added, removed or modified. All the table records within
'          the DBProj Database will be preserved. Fields withing a table
'          are not removed.
'
' Arguments:
'   DBProj As Database - the source Database object
'   DBTempl As Database - the destination Database object
'   strTableName as String the name of the Table to update
'
' Returns:
'   Boolean: True if successful, False if not
'-----------------------------------------------------------------

Public Function SingleTableUpdate(DBProj As Database, DBTempl As Database, _
                strTableName As String) As Boolean
  ' walk all tables in DBTempl and do update to Project
  Dim TableDef As TableDef
  Dim bRet As Boolean
  Dim nCnt As Integer
  
  On Error Resume Next
  bRet = False
  
  ' get name then release
  Set TableDef = DBTempl.TableDefs(strTableName)

  If Not (TableDef Is Nothing) Then
    ' ensure table in ProjDB
    bRet = VerifyAddTable(DBProj, DBTempl, strTableName, TableDef)
    If bRet Then
        ' check and refresh struct and data
      bRet = TableStructure_Update(DBProj, DBTempl, strTableName)
    End If
  End If
  
  SingleTableUpdate = bRet
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'=================================================================
' Private Functions
'=================================================================

'------------------------------
Private Function VerifyAddTable(DBProj As Database, DBTempl As Database, _
            strTemplTableName As String, TableDefTempl As TableDef) As Boolean
  ' See if tableDef in Proj. If not, add it
  Dim TableDef As TableDef
  Dim i As Integer
  ReDim NewFieldList(0) As FieldList
  ReDim NewIndexList(0) As IndexList
  ReDim NewIndexFieldList(0) As String
  Dim ncNewField As Integer
  Dim ncNewIndex As Integer
  Dim bRet As Boolean
  Dim bSysTable As Boolean
  On Error Resume Next
  
  VerifyAddTable = True
  For i = 0 To DBProj.TableDefs.count - 1
    Set TableDef = DBProj.TableDefs(i)
    If strTemplTableName = TableDef.Name Then Exit Function
  Next i
  
  ' not there, add it
  VerifyAddTable = False
    ' read the new structure
  bRet = TableStructure_Read(DBTempl, strTemplTableName, _
        NewFieldList(), ncNewField, _
        NewIndexList(), ncNewIndex, _
        NewIndexFieldList(), bSysTable)
  If bSysTable Then
    VerifyAddTable = True
    Exit Function
  End If
  If Not bRet Then Exit Function

  bRet = Table_Add(DBProj, strTemplTableName, _
          NewFieldList(), ncNewField, _
          NewIndexList(), ncNewIndex, _
          NewIndexFieldList())
  VerifyAddTable = bRet

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Private Function TableStructure_Update(DBProj As Database, DBTempl As Database, _
          szTableName As String) As Boolean
  ' check and update 1 table if required.
  Dim MyTableDef As TableDef
  Dim bRet As Boolean
  Dim nI As Integer

  ReDim OldFieldList(0) As FieldList
  ReDim OldIndexList(0) As IndexList
  ReDim OldIndexFieldList(0) As String
  Dim ncOldField As Integer
  Dim ncOldIndex As Integer
  ReDim NewFieldList(0) As FieldList
  ReDim NewIndexList(0) As IndexList
  ReDim NewIndexFieldList(0) As String
  Dim ncNewField As Integer
  Dim ncNewIndex As Integer
  Dim bModified As Boolean
  Dim bSysTable As Boolean

  On Error Resume Next
  TableStructure_Update = False
    ' read the old structure
  bRet = TableStructure_Read(DBProj, szTableName, _
        OldFieldList(), ncOldField, _
        OldIndexList(), ncOldIndex, _
        OldIndexFieldList(), bSysTable)
  If bSysTable Then
    TableStructure_Update = True
    Exit Function
  End If
  
  If Not bRet Then Exit Function
    ' read the new structure
  bRet = TableStructure_Read(DBTempl, szTableName, _
        NewFieldList(), ncNewField, _
        NewIndexList(), ncNewIndex, _
        NewIndexFieldList(), bSysTable)
  If Not bRet Then Exit Function

  Set MyTableDef = DBProj.TableDefs(szTableName)

  ' compare the structures for field differences
  ' (ie: new, modified, deleted ) and update the fields if required
  bRet = TableStructure_UpdateField(DBProj, szTableName, MyTableDef, _
          ncOldField, OldFieldList(), ncNewField, NewFieldList(), _
          bModified)
  If Not bRet Then Exit Function
  
    ' compare indexes. update if required
  If Not TableIndexesSame(OldIndexList(), ncOldIndex, OldIndexFieldList(), _
            NewIndexList(), ncNewIndex, NewIndexFieldList()) _
  Then
    ' delete all existing indexes
    For nI = 0 To ncOldIndex - 1
      MyTableDef.Indexes.Delete OldIndexList(nI).szIndexName
    Next nI
  
    ' add all new indexes
    For nI = 0 To ncNewIndex - 1
      bRet = Index_Add(MyTableDef, NewIndexList(nI), NewIndexFieldList())
      If Not bRet Then Exit For
    Next nI
  End If
  
  TableStructure_Update = bRet

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Private Function TableIndexesSame(OldIndexList() As IndexList, ncOldIndex As Integer, _
                    OldIndexFieldList() As String, _
                    NewIndexList() As IndexList, ncNewIndex As Integer, _
                    NewIndexFieldList() As String) As Boolean
  ' determine if Indexes for old and new are same
  ' return true if so, false otherwise
  
  Dim i As Integer
  Dim j As Integer
  Dim NewItem As IndexList
  Dim OldItem As IndexList
  
  On Error Resume Next
  
  TableIndexesSame = False

'''''''
  Exit Function
'''''''

  If ncOldIndex <> ncNewIndex Then Exit Function
    ' compare db fields that comprise each index
  For i = 0 To ncOldIndex - 1
  Next i
  
  TableIndexesSame = True

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Private Function TableStructure_UpdateField(DB As Database, _
            szTableName As String, MyTableDef As TableDef, _
            ncOldField As Integer, OldFieldList() As FieldList, _
            ncNewField As Integer, NewFieldList() As FieldList, _
            bModified As Boolean) As Boolean
  
  ' Compare and Update field structures for table based on new data passed in
  ' if they are different, and update will be done
  Dim nI As Integer
  Dim nJ As Integer
  Dim bRet As Integer
  Dim bFieldExists As Integer
  Dim MyField As Field
  Dim bOK As Integer
  
  On Error Resume Next
  TableStructure_UpdateField = False
  bRet = True
  bModified = False
  ' find deleted and modified fields
  For nI = 0 To ncOldField - 1
    bFieldExists = False
    For nJ = 0 To ncNewField - 1
      If OldFieldList(nI).szFieldName = NewFieldList(nJ).szFieldName Then
        ' field exists in both table structures
        bFieldExists = True
        If (OldFieldList(nI).nFieldType <> NewFieldList(nJ).nFieldType) Or _
          (OldFieldList(nI).nFieldSize <> NewFieldList(nJ).nFieldSize) Or _
          (OldFieldList(nI).nAllowZeroLength <> NewFieldList(nJ).nAllowZeroLength) Or _
          (OldFieldList(nI).DefaultValue <> NewFieldList(nJ).DefaultValue) _
        Then
          ' structs not same. Modify the field
          If Not Field_Update(DB, szTableName, MyTableDef, _
                        OldFieldList(nI), NewFieldList(nJ)) _
          Then
            bRet = False
          Else
            bModified = True
          End If
        End If
        '
        Exit For
      End If
    Next nJ
  
    ' AEM  - 9/16/98 - will NOT delete old/mismatched Fields to deal with
    ' users who have added their own fields for other purposes.
    
    If Not bRet Then Exit Function
  Next nI
  
  ' find the new fields
  For nI = 0 To ncNewField - 1
    bFieldExists = False
    For nJ = 0 To ncOldField - 1
      If NewFieldList(nI).szFieldName = OldFieldList(nJ).szFieldName Then
        ' field exists in both table structures
        bFieldExists = True
        Exit For
      End If
    Next nJ
    If Not bFieldExists Then
      ' field in NewStructure was not found in OldStructure -> add it
      If Not Field_Add(DB, MyTableDef, NewFieldList(nI)) Then
        bRet = False
      Else
        bModified = True
      End If
    End If
  Next nI

  TableStructure_UpdateField = bRet

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Private Function Field_Update(DB As Database, szTableName As String, _
        MyTableDef As TableDef, OldFieldList As FieldList, _
        NewFieldList As FieldList) As Boolean
  ' NOTE:  If the field type or size has been changed, the field is replaced, and the
  '        data is copied out of the original field.  This may result in update errors
  '        if data type changes are not compatable.
  '
  Dim szSQL As String
  Dim MyQueryDef As QueryDef
  Dim MyField As Field
  Dim bOK As Integer
  Dim bRet As Integer
  Dim szFieldName As String
  Dim szTempFieldName As String

  bRet = True
  On Error Resume Next

  If (OldFieldList.nFieldType <> NewFieldList.nFieldType) Or _
      (OldFieldList.nFieldSize <> NewFieldList.nFieldSize) _
  Then
    ' have to add a new field, update the data, delete the old field, and rename the new field
    szFieldName = NewFieldList.szFieldName
    szTempFieldName = GetUniqueFieldName(MyTableDef, szFieldName)
    
    If Len(szTempFieldName) > 0 Then
      NewFieldList.szFieldName = szTempFieldName
      If Field_Add(DB, MyTableDef, NewFieldList) Then
        ' update the data
        ' if Text type, ensure that it has at least an Empty string in it
        ' NULL strings are bad things
        
        If NewFieldList.nFieldType = dbText And _
            (NewFieldList.nFieldSize < OldFieldList.nFieldSize) _
        Then
'          szSQL = "UPDATE [" & szTableName & "] SET [" & szTempFieldName & "] = Left([" _
'            & szFieldName & "]," & NewFieldList.nFieldSize & ");"
          szSQL = "UPDATE [" & szTableName & "] SET [" & szTempFieldName & "] = Left([" _
            & szFieldName & "]," & NewFieldList.nFieldSize & ")" & _
                    " & " & """" & """" & ";"
        Else
'          szSQL = "UPDATE [" & szTableName & "] SET [" & szTempFieldName & "] = " & szFieldName & ";"
          szSQL = "UPDATE [" & szTableName & "] SET [" & szTempFieldName & "] = " & szFieldName & _
                    " & " & """" & """" & ";"
        End If
        
        Set MyQueryDef = DB.CreateQueryDef("", szSQL)
        
        MyQueryDef.Execute
        #If APP_DEBUG Then
          VERIFY_ERR
        #End If
        MyQueryDef.Close
  
        ' delete the old field
        MyTableDef.Fields.Delete szFieldName
        ' rename the new field
        Set MyField = MyTableDef.Fields(szTempFieldName)
        MyField.Name = szFieldName
      Else
        bRet = False
      End If
      NewFieldList.szFieldName = szFieldName
      
      #If APP_DEBUG Then
        VERIFY_ERR
      #End If
    
    End If
  End If
    
  ' revise read/write properties
  Set MyField = MyTableDef.Fields(NewFieldList.szFieldName)
  
  If OldFieldList.nAllowZeroLength <> NewFieldList.nAllowZeroLength Then
    MyField.AllowZeroLength = NewFieldList.nAllowZeroLength
  End If

  If OldFieldList.DefaultValue <> NewFieldList.DefaultValue Then
    MyField.DefaultValue = NewFieldList.DefaultValue
  End If
  
'  If OldFieldList.szDescription <> NewFieldList.szDescription Then
'    If Len(NewFieldList.szDescription) > 0 Then
'      bOK = FieldProperty_Set(MyField, "Description", dbText, NewFieldList.szDescription)
'    End If
'  End If

  Field_Update = bRet

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Private Function GetUniqueFieldName(MyTableDef As TableDef, _
        szFieldName As String) As String
  ' get unique name
  Dim szRet As String
  Dim szSuffix As String
  Dim ncField As Integer
  Dim nI As Integer
  Dim nJ As Integer
  Dim bOK As Integer

  Const ASCII_A = 65
  Const ASCII_Z = 90

  On Error Resume Next
  ncField = MyTableDef.Fields.count

  bOK = False
  For nI = 0 To 9
    szSuffix = CStr(nI)
    szRet = szFieldName & szSuffix
    bOK = True
    For nJ = 0 To ncField - 1
      If MyTableDef.Fields(nI).Name = szRet Then
        bOK = False
        Exit For
      End If
    Next nJ
    If bOK Then
      Exit For
    End If
  Next nI

  If Not bOK Then
    For nI = ASCII_A To ASCII_Z
      szSuffix = Chr(nI)
      szRet = szFieldName & szSuffix
      bOK = True
      For nJ = 0 To ncField - 1
        If MyTableDef.Fields(nI).Name = szRet Then
          bOK = False
          Exit For
        End If
      Next nJ
      If bOK Then
        Exit For
      End If
    Next nI
  End If

  If bOK Then
    GetUniqueFieldName = szRet
  Else
    GetUniqueFieldName = ""
  End If

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Private Function TableStructure_Read(DB As Database, szTableName As String, _
              FieldList() As FieldList, ncField As Integer, _
              IndexList() As IndexList, ncIndex As Integer, _
              IndexFieldList() As String, bSysTable As Boolean) As Boolean
  ' read a table's structure and indexes and copy to params pased in
  Dim MyTableDef As TableDef
  Dim MyField As Field
  Dim MyIndex As index
  
  Dim nIndexPointer As Integer
  Dim nFieldCount As Integer
  Dim nI As Integer
  Dim nJ As Integer
  
  On Error Resume Next
  ReDim IndexFieldList(50) As String
  
  TableStructure_Read = False
  bSysTable = False
  Set MyTableDef = DB.TableDefs(szTableName)
    
  nIndexPointer = 0
  ncField = MyTableDef.Fields.count
  ncIndex = MyTableDef.Indexes.count
  ReDim FieldList(ncField) As FieldList
  ReDim IndexList(ncIndex) As IndexList
    '
  For nI = 0 To ncField - 1
    Set MyField = MyTableDef.Fields(nI)
    FieldList(nI).szFieldName = MyField.Name
    FieldList(nI).nFieldType = MyField.Type
    FieldList(nI).nFieldSize = MyField.Size
    FieldList(nI).nAllowZeroLength = IIf(MyField.AllowZeroLength, True, False)
    FieldList(nI).DefaultValue = MyField.DefaultValue
    FieldList(nI).nOrdinalPosition = MyField.OrdinalPosition
    '
    If (MyField.Attributes And dbAutoIncrField) = dbAutoIncrField Then    '  if counter
      FieldList(nI).bAutoNumber = True
    End If
    '
    
    For nJ = 0 To MyField.Properties.count - 1
      If MyField.Properties(nJ).Name = "Description" Then
        FieldList(nI).szDescription = MyField.Properties!Description
      End If
      If MyField.Properties(nJ).Name = "ColumnOrder" Then
        FieldList(nI).nColumnOrder = MyField.Properties!ColumnOrder
      End If
    Next nJ
  Next nI

  For nI = 0 To ncIndex - 1
    Set MyIndex = MyTableDef.Indexes(nI)
    IndexList(nI).szIndexName = MyIndex.Name
    IndexList(nI).nPrimary = MyIndex.Primary
    IndexList(nI).nUnique = MyIndex.Unique
    IndexList(nI).nStartField = nIndexPointer
    nFieldCount = MyIndex.Fields.count
    If nFieldCount > 0 Then
      For nJ = 0 To nFieldCount - 1
        IndexFieldList(nIndexPointer + nJ) = MyIndex.Fields(nJ).Name
      Next nJ
      nIndexPointer = nIndexPointer + nFieldCount
      IndexList(nI).nEndField = nIndexPointer - 1
    End If
  Next nI

    ' check for system tables
    '(ie: Couldn't read definitions; no read definitions
    ' permission for table or query 'MSysACEs'.)
  If Err <> 0 Then
    If Err = 3110 Then
      Err = 0
      TableStructure_Read = True
      bSysTable = True
    Else
      TableStructure_Read = False
    End If
  Else
    TableStructure_Read = True
  End If


#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function
'------------------------------
Private Function Table_Add(DB As Database, szTableName As String, _
        FieldList() As FieldList, ncField As Integer, _
        IndexList() As IndexList, ncIndex As Integer, _
        IndexFieldList() As String) As Boolean
  ' add a table to the database with the given name
  Dim MyTableDef As TableDef
  Dim MyField As Field
  Dim nI As Integer
  Dim ret As Boolean
  Dim bOK As Integer

  On Error Resume Next
  Table_Add = False
  Set MyTableDef = DB.CreateTableDef(szTableName)
  If Not VERIFY_ERR Then Exit Function
    ' add fields
  For nI = 0 To ncField - 1
    If Field_Add(DB, MyTableDef, FieldList(nI)) Then
      ret = True
    Else
      ret = False
      Exit For
    End If
  Next nI

  If ret Then
    ' add indexes
    For nI = 0 To ncIndex - 1
      If Not (Index_Add(MyTableDef, IndexList(nI), IndexFieldList())) Then
        ret = False
        Exit For
      End If
    Next nI
  End If

  DB.TableDefs.Append MyTableDef

  ' update column order and description of all fields
  For nI = 0 To ncField - 1
    Set MyField = MyTableDef.Fields(FieldList(nI).szFieldName)
    MyField.OrdinalPosition = FieldList(nI).nOrdinalPosition
'    bOK = FieldProperty_Set(MyField, "ColumnOrder", dbLong, FieldList(nI).nColumnOrder)
'    bOK = FieldProperty_Set(MyField, "Description", dbText, FieldList(nI).szDescription)
  Next nI
  '
  Table_Add = ret
#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function

'------------------------------
Private Function Field_Add(DB As Database, MyTableDef As TableDef, FieldList As FieldList) As Boolean
  ' add a field to the tableDef
  ' fieldlist.nfieldtype :
  ' 4 - dbLong
  '
  Dim MyField As Field
  Dim bRet As Boolean
    
  On Error Resume Next
  Field_Add = False
  Set MyField = MyTableDef.CreateField(FieldList.szFieldName, FieldList.nFieldType, _
                            FieldList.nFieldSize)
  If Not VERIFY_ERR Then Exit Function
  
  '  if counter
  If FieldList.bAutoNumber Then
    MyField.Attributes = MyField.Attributes Or dbAutoIncrField
  End If

  MyField.OrdinalPosition = FieldList.nOrdinalPosition
  If Not IsNull(FieldList.DefaultValue) Then
    MyField.DefaultValue = FieldList.DefaultValue
  End If
  
  If FieldList.nFieldType = dbText Or FieldList.nFieldType = dbMemo Then
    MyField.AllowZeroLength = IIf(FieldList.nAllowZeroLength, 1, 0)
  End If
  
'  bRet = FieldProperty_Set(MyField, "ColumnOrder", dbLong, FieldList.nColumnOrder)
'  bRet = FieldProperty_Set(MyField, "Description", dbText, FieldList.szDescription)
  
  MyTableDef.Fields.Append MyField
      
    ' set value if numeric (so don't have NULL entries)
  If FieldList.nFieldType = dbBigInt Or _
        FieldList.nFieldType = dbDecimal Or _
        FieldList.nFieldType = dbDouble Or _
        FieldList.nFieldType = dbFloat Or _
        FieldList.nFieldType = dbInteger Or _
        FieldList.nFieldType = dbLong Or _
        FieldList.nFieldType = dbSingle Or _
        FieldList.nFieldType = dbBoolean _
  Then
    bRet = SetNumericFieldValue(DB, MyTableDef, FieldList.szFieldName, 0)
  End If
  
  Field_Add = True

#If APP_DEBUG Then
  VERIFY_ERR
#End If
End Function
'------------------------------
Private Function SetNumericFieldValue(DB As Database, MyTableDef As TableDef, _
                    szFieldName As String, nValue As Integer) As Boolean
  ' set a Numeric value for fields in table
  Dim szSQL As String
  Dim MyQueryDef As QueryDef
  Dim szTableName As String
  
  On Error Resume Next
    ' if empty table, do not do this (will get error otherwise)
  If MyTableDef.RecordCount = 0 Then
    SetNumericFieldValue = True
    Exit Function
  End If
  '
  SetNumericFieldValue = False
  szTableName = MyTableDef.Name
  
  szSQL = "UPDATE [" & szTableName & "] SET [" & szFieldName & "] = " & nValue & " ;"
  Set MyQueryDef = DB.CreateQueryDef("", szSQL)
  MyQueryDef.Execute
  
  #If APP_DEBUG Then
    VERIFY_ERR
  #End If
  MyQueryDef.Close
  SetNumericFieldValue = True
End Function


'------------------------------
Private Function Index_Add(MyTableDef As TableDef, IndexList As IndexList, _
                      IndexFieldList() As String) As Boolean
  ' add index to tableDef
  Dim MyIndex As index
  Dim MyField As Field
  Dim nI As Integer

  On Error Resume Next
  Index_Add = False
  Set MyIndex = MyTableDef.CreateIndex(IndexList.szIndexName)
  If Not VERIFY_ERR Then Exit Function
  
  MyIndex.Primary = IndexList.nPrimary
  MyIndex.Unique = IndexList.nUnique
  
  For nI = IndexList.nStartField To IndexList.nEndField
    Set MyField = MyTableDef.CreateField(IndexFieldList(nI))
    MyIndex.Fields.Append MyField
  Next nI

  MyTableDef.Indexes.Append MyIndex

If Err <> 0 Then Err = 0
'#If APP_DEBUG Then
'  VERIFY_ERR
'#End If
  
  Index_Add = True
End Function

'------------------------------
Private Function FieldProperty_Set(MyField As Field, PropertyName As String, _
                  PropertyType As Integer, PropertyValue As Variant) As Integer
  ' set the property on the field
  Const ERR_PROPERTY_NONEXISTENT = 3270
  Dim MyProperty As Property
  
  On Error Resume Next
  
'''''''''
'  Dim prpLoop As Property
'  ' Enumerate Properties collection of passed Field
'  ' object.
'  For Each prpLoop In MyField.Properties
'    ' Some properties are invalid in certain
'    ' contexts (the Value property in the Fields
'    ' collection of a TableDef for example). Any
'    ' attempt to use an invalid property will
'    ' trigger an error.
'    Debug.Print "    " & prpLoop.Name & " = " & prpLoop.Value
'  Next prpLoop
'  Err = 0
'''''''
  
  
  
  FieldProperty_Set = True
  MyField.Properties(PropertyName) = PropertyValue
  If Err <> 0 Then  ' Error occurred when value was set.
    If Err <> ERR_PROPERTY_NONEXISTENT Then
      ' unknown error ocurred, abort property update
      FieldProperty_Set = False
    Else
      Err = 0
      ' Create Property object, setting its Name, Type, and Value properties.
      Set MyProperty = MyField.CreateProperty(PropertyName, PropertyType, PropertyValue)
      If Err = 3385 Then
        ' property value is null, not really a problem to worry about
        Err = 0
      Else
        MyField.Properties.Append MyProperty
      End If
      If Err <> 0 Then
        FieldProperty_Set = False
      End If
    End If
  End If
End Function


'------------------------------
Private Function VERIFY_ERR() As Boolean
  ' Verify for the Err object
  ' Return True if OK
  VERIFY_ERR = True
  If Not Err = 0 Then
      #If APP_DEBUG Then
        Dim strMsg As String
        strMsg = "mDBHelper:VERIFY_ERR Failed:" & Error
        gMsgWnd.LogMessage strMsg
      #End If
    VERIFY_ERR = False
  End If
End Function

