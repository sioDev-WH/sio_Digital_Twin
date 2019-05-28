Attribute VB_Name = "mCommonDialog"
'======================================================================================
'
' Module:   Common Dialog
'--------------------------------------------------------------------------------------
'
'======================================================================================
Option Explicit

Private Const BUFFER_SIZE = 8192
Private Const DT_LONGBINARY = 11

Private m_bIniFileExists As Boolean ' to speed up INI calls
Private m_IniFileName As String     ' the name
'
'======================================================================================
'

'======================================================================================
' INI File Interface
'======================================================================================

'------------------------------
Public Function AppGetProfileInt(szSection As String, szEntry As String, nDefault As Integer) As Integer
  ' Cover function for GetPrivateProfileInt
  ' nDefault is the default value to place in the Entry
  ' Returns:  Entry value if found. Default if not found.
  Dim IniFileName As String
  Dim bRet As Boolean
  Dim nRet As Long
  Dim nDflt As Long
  Dim strCurPath As String
  
  On Error Resume Next
    
'    ' memorize current path
'  strCurPath = CurDir
'    ' Force to CWD so that can ensure INI file ref is correct
'  ChDrive App.Path
'  ChDir App.Path
  
  ' Test if INI file exists. If not, create it in App Directory
  If Not IniFileExists(INI_FILENAME, IniFileName) Then
    bRet = AppWriteProfileInt(szSection, szEntry, nDefault)
    AppGetProfileInt = nDefault
'    RestorePath strCurPath
    Exit Function
  End If
  nDflt = nDefault
  nRet = GetPrivateProfileInt(szSection, szEntry, nDflt, IniFileName)
  AppGetProfileInt = nRet
'  RestorePath strCurPath
End Function

'------------------------------
Public Function AppWriteProfileInt(szSection As String, szEntry As String, nValue As Integer)
  ' Write an Int to INI file
  ' convert Int to string and write that
  Dim IniFileName As String
  Dim bRet As Boolean
  Dim strCurPath As String
  Dim strVal As String
  
  On Error Resume Next
    
'    ' memorize current path
'  strCurPath = CurDir
'    ' Force to CWD so that can ensure INI file ref is correct
'  ChDrive App.Path
'  ChDir App.Path
    
    ' Test and create if required. Fill in name
  bRet = IniFileExists(INI_FILENAME, IniFileName)
  ' convert to string
  strVal = nValue
  bRet = WritePrivateProfileString(szSection, szEntry, strVal, IniFileName)
'  RestorePath strCurPath
End Function
        
'------------------------------
Public Function AppGetProfileString(szSection As String, szEntry As String, szDefault As String) As String
  ' Cover function for GetPrivateProfileString
  ' szDefault is the default value to place in the Entry
  ' Returns:  Entry value if found. Default if not found.
  '               if szDefault is Empty and Entry not found, return will be empty
        
  Dim IniFileName As String
  Dim bRet As Boolean
  Dim Dflt As String
  Dim Size As Integer
  Dim szReturnBuffer As String
  Dim strCurPath As String
  Dim strRet As String
  
  On Error Resume Next

  Dflt = Space$(256)
  Size = Len(szDefault)
  If Size > 0 Then
    Dflt = szDefault
  End If
  
'    ' memorize current path
'  strCurPath = CurDir
'    ' Force to CWD so that can ensure INI file ref is correct
'  ChDrive App.Path
'  ChDir App.Path
  
  ' Test if INI file exists. If not, create it in Windows Directory
  If Not IniFileExists(INI_FILENAME, IniFileName) Then
    bRet = WritePrivateProfileString(szSection, szEntry, szDefault, IniFileName)
    AppGetProfileString = szDefault
'    RestorePath strCurPath
    Exit Function
  End If
  
  szReturnBuffer = Space$(256)
  Size = Len(szReturnBuffer)
  Size = GetPrivateProfileString(szSection, szEntry, szDefault, szReturnBuffer, Size, IniFileName)
  If Size > 0 Then
    ' strip out terminating garbage
    Dim i As Integer
    Dim strCh As String
    Size = Len(szReturnBuffer)
    For i = Size - 1 To 1 Step -1
      '      If Asc(Mid(szReturnBuffer, i, 1)) > 32 Then Exit For
      strCh = Mid(szReturnBuffer, i, 1)
      If Len(strCh) > 0 And (Not IsNull(strCh)) Then
        If Asc(strCh) > 32 Then Exit For
      Else
        Exit For
      End If
    Next
'    If i > 1 Then
    If i > 0 Then
      strRet = Mid(szReturnBuffer, 1, i)
    End If
    AppGetProfileString = strRet
  Else
    AppGetProfileString = szDefault
  End If
'  RestorePath strCurPath
  
End Function
'------------------------------
Public Function AppWriteProfileString(szSection As String, szEntry As String, szValue As String)
  ' Cover function for WritePrivateProfileString
  Dim IniFileName As String
  Dim bRet As Boolean
  Dim strCurPath As String

  On Error Resume Next
    
'    ' memorize current path
'  strCurPath = CurDir
'    ' Force to CWD so that can ensure INI file ref is correct
'  ChDrive App.Path
'  ChDir App.Path
  
  ' Test and create if required. Fill in name
  bRet = IniFileExists(INI_FILENAME, IniFileName)
  bRet = WritePrivateProfileString(szSection, szEntry, szValue, IniFileName)
'  RestorePath strCurPath
End Function
        
'------------------------------
Private Function IniFileExists(szDefault As String, szReturnBuffer As String) As Boolean
  
  ' Test if INI file exists. If not, create it in Windows Directory using name szDefault
  Dim IniFileName As String
  Dim IniDir As String
  Dim Size As Integer
  Dim wRet As Integer
  Dim i As Integer
  Dim szDir As String
        
  On Error Resume Next
  
  If m_bIniFileExists Then
    IniFileExists = True
    szReturnBuffer = m_IniFileName
    Exit Function
  End If
  
  IniDir = App.Path
  IniFileName = IniDir & "\" & szDefault
  
    ' If Not found. Create empty file
  szDir = Dir(IniFileName)
  If szDir = "" Or Err <> 0 Then
    Open IniFileName For Output As #1
    Close #1
    szReturnBuffer = IniFileName
    IniFileExists = False
    m_bIniFileExists = False
    m_IniFileName = ""
    Exit Function
  End If
  szReturnBuffer = IniFileName
  m_IniFileName = IniFileName
  IniFileExists = True
  m_bIniFileExists = True
End Function




'============================================================
' File Manipulation Functions
'============================================================

'------------------------------
Public Function BuildArrayFileNames(srcPath As String, FileSpec As String, aNames() As String) As Boolean
  ' Build a list of Filenames matching FileSpec.
  ' resulting array will contain the path and all files in path matching spec.
  ' the Path MUST have the trailing '\' on it!
  Dim nFileAttr As Integer
  Dim nFiles As Integer
  Dim bValid As Boolean
  Dim strCur As String
  Dim strCurPath As String
  
  On Error Resume Next
  BuildArrayFileNames = False
    ' memorize current path and Force to new path
  strCurPath = CurDir
  ChDir srcPath
  
  ' build up list
  nFileAttr = vbNormal Or vbHidden Or vbSystem
'  strCur = Dir(FileSpec, nFileAttr)
  strCur = Dir(srcPath & FileSpec, nFileAttr)
  If Err <> 0 Or Len(strCur) = 0 Then
    RestorePath strCurPath
    Exit Function
  End If
  ' add all files requested
  nFiles = 0
  ReDim aNames(nFiles) As String
  aNames(0) = srcPath & strCur
  bValid = True
  Do
    strCur = Dir
    If Len(strCur) > 0 Then
      nFiles = nFiles + 1
      ReDim Preserve aNames(nFiles)
      aNames(nFiles) = srcPath & strCur
    Else
      bValid = False
    End If
  Loop While bValid
  
  RestorePath strCurPath
  BuildArrayFileNames = True
End Function


'-----------------------------------
Public Function GetFileExt(ByVal FileName As String) As String
  ' get the file extension (without the '.' )
  Dim szName As String
  Dim nStart As Integer
  Dim nDelimPos As Integer
  Dim Ext As String
  
  szName = LTrim$(RTrim$(FileName))
  nStart = Len(szName)  ' calc starting pos to deal with DOS paths have a . in them
  If nStart > 4 Then
    nStart = nStart - 4
  Else
    nStart = 1
  End If
  If nStart < 1 Then nStart = 1
  nDelimPos = InStr(nStart, szName, ".")
  If nDelimPos > 0 Then
    Ext = Right(szName, Len(szName) - nDelimPos)
  Else
    Ext = szName
  End If
  GetFileExt = Ext
  
  
  
#If 0 Then
  ' original CODE
  Dim Ext As String
  Dim szName As String
  Dim nStart As Integer
  Dim nDelimPos As Integer

  nStart = Len(FileName)  ' calc starting pos to deal with DOS paths have a . in them
  nStart = nStart - 4
  nDelimPos = InStr(nStart, FileName, ".")
  If nDelimPos > 0 Then
    Ext = Right(FileName, Len(FileName) - nDelimPos)
  End If
  GetFileExt = Ext
#End If
End Function

'------------------------------
Public Function VerifyFilePath(Path As String) As Boolean
  ' Verify that the File System Path is Valid
  Dim testPath As String
  VerifyFilePath = False
  On Error Resume Next
  testPath = Dir(Path, vbDirectory)
  If Err = 0 Then
    If Len(testPath) = 0 Then
      VerifyFilePath = False
    Else
      VerifyFilePath = True
    End If
  End If
End Function


'------------------------------
Public Function RestorePath(Path As String) As Boolean
  ' Restore (set to current) the Path to one passed in
  On Error Resume Next
  ChDir Path
  
End Function

'---------------------------------
Public Function FileExists(ByVal szFileName As String) As Boolean
' Tests for the existence of a file.
' File exists:        True  returned
' File doesn't exist: False returned
  Dim Match As String
  Dim nFileAttr As Integer
  Dim str1 As String
  On Error Resume Next
  
  FileExists = False
  If Len(szFileName) = 0 Then Exit Function
  
  ' check if its only a directory
  str1 = StripPath(szFileName)
  If Len(str1) = 0 Then
    FileExists = False
    Exit Function
  End If
  
  ' now test if its there
  nFileAttr = vbNormal Or vbHidden Or vbSystem
  Match = Dir(szFileName, nFileAttr)
  If Err = 0 And Len(Match) > 0 Then
    FileExists = True
  Else
    FileExists = False
  End If
End Function

'-----------------------------------
Public Function FormatFileName(ByVal szFileName As String, ByVal szFileExt As String) As String
' Formats the file extension of a filename.  If a file extension
' exists, it will be stripped off the filename, and replaced with
' the szFileExt extension.
' NOTE:  szFileExt must contain the '.'
' eg: szFileName = 'c:\ews\myfile.bas'
'     szFileExt =  '.xqs'
'     -> 'c:\ews\myfile.xqs' is returned
' NOTE: Must check for '.' in the directory part of the filename,
' thus should look first for a
' trailing '\' and then work from there

  Dim nDelimPos As Integer
  Dim strpath As String
  Dim strName As String
  Dim i As Integer
  Dim bGotIt As Boolean
  
  bGotIt = False
  strpath = szFileName
  strpath = LTrim$(RTrim$(szFileName))
  If Right(strpath, 1) = "\" Then Exit Function
  For i = Len(strpath) To 1 Step -1
    If Mid(strpath, i, 1) = "\" Then
      bGotIt = True
      strName = Right(strpath, Len(strpath) - i)
      strpath = Left(strpath, i)
      Exit For
    End If
  Next i
  If Not bGotIt Then
    strName = strpath
    strpath = ""
  End If
  
  nDelimPos = InStr(strName, ".")
  If nDelimPos > 0 Then
    strName = Left(strName, nDelimPos - 1) & szFileExt
  Else
    strName = strName & szFileExt
  End If
  FormatFileName = strpath & strName


'  Dim nDelimPos As Integer
'  nDelimPos = InStr(szFileName, ".")
'  If nDelimPos > 0 Then
'    szFileName = Left(szFileName, nDelimPos - 1) & szFileExt
'  Else
'    szFileName = szFileName & szFileExt
'  End If
'  FormatFileName = szFileName

End Function

'----------------------------------
Public Function FormatPath(ByVal szPath As String) As String
' Adds a trailing backslash to a path if one doesn't already exist.
' Use Format path when concatenating a filename to a path to ensure
' the result is valid.
  szPath = Trim(szPath)
  If Len(szPath) > 0 And Right(szPath, 1) <> "\" Then
    szPath = szPath & "\"
  End If
  FormatPath = szPath
End Function

'---------------------------------
Public Function FormatPathNB(ByVal szPath As String) As String
' Removes a trailing backslash from a path if one exists
' Use FormatPathNB before using the CurDir$ function because
' CurDir$ returns an error if the specified path has a trailing
' backslash.
  szPath = Trim(szPath)
  If Right(szPath, 1) = "\" Then
    szPath = Left(szPath, Len(szPath) - 1)
  End If
  FormatPathNB = szPath
End Function

'----------------------------------
Public Function StripFile(ByVal szSource As String) As String
' Strips the Filename (if one exists) off a file
  Dim nI As Integer
  If Len(szSource) = 0 Then Exit Function
  szSource = LTrim$(RTrim$(szSource))
  If Right(szSource, 1) = "\" Then Exit Function
  For nI = Len(szSource) To 1 Step -1
    If Mid(szSource, nI, 1) = "\" Then
      szSource = Left(szSource, nI - 1)
      Exit For
    End If
  Next nI
  StripFile = szSource
End Function

'---------------------------------------
Public Function StripPath(ByVal szSource As String) As String
' Strips the DOS path off a filename (if one exists)
  Dim nI As Integer
  If Len(szSource) = 0 Then Exit Function
  For nI = Len(szSource) To 1 Step -1
    If Mid(szSource, nI, 1) = "\" Then
      szSource = Mid(szSource, nI + 1)
      Exit For
    End If
  Next nI
  StripPath = szSource
End Function

'---------------------------------------
Public Function StripExtension(ByVal szSource As String) As String
' Strips the DOS Extension off a filename (if one exists)
  Dim nI As Integer
  If Len(szSource) = 0 Then Exit Function
  szSource = LTrim$(RTrim$(szSource))
  If Right(szSource, 1) = "." Then Exit Function
  For nI = Len(szSource) To 1 Step -1
    If Mid(szSource, nI, 1) = "." Then
      szSource = Left(szSource, nI - 1)
      Exit For
    End If
  Next nI
  StripExtension = szSource
End Function


'============================================================
' OLE Field Functions
'============================================================

'------------------------------
Public Function GenerateTempFileName(Name As String) As Boolean
  ' generate a Temporary filename
  Dim tempFileName As String
  Dim R As Integer
  
  On Error Resume Next
    tempFileName = Space(512)
    Dim tempPathName As String
    tempPathName = Space(255)
    If GetTempPath(Len(tempPathName), tempPathName) = 0 Then
      GenerateTempFileName = False
      Exit Function
    End If
'    r = GetTempFileName(tempPathName, "", 0, tempFileName)
  ' *** Note: Cannot use above in Win95
    R = GetTempFileName(tempPathName, "", 1234, tempFileName)
    If Err Then
      Name = "1234.tmp"
      Err.Clear
    Else
      Name = tempFileName
    End If
    GenerateTempFileName = True
End Function


'------------------------------
Public Function PutPictureInOleField(pic As Picture, OleField As Field) As Boolean
  ' Save the Picture into the OleField. The Picture is saved as a non-structured BLOB
  ' and totally ignores any standards found for MSAccess OleField datatypes
  Dim R As Integer
  Dim Handle As Integer
  Dim tempFileName As String
  Dim bRet As Boolean
  
  PutPictureInOleField = False
  
  If OleField.Type = DT_LONGBINARY Then
    tempFileName = Space(512)
    Dim tempPathName As String
    tempPathName = Space(255)
    If GetTempPath(Len(tempPathName), tempPathName) = 0 Then
      Exit Function
    End If
    R = GetTempFileName(tempPathName, "", 0, tempFileName)
      'Save the Picture
    If tempFileName <> "" Then
      SavePicture pic, tempFileName
    Else
      Exit Function
    End If
    bRet = CopyMetafileToOleField(OleField, tempFileName)
    Kill tempFileName
  End If
  
  PutPictureInOleField = bRet
End Function

   
'------------------------------
Private Function CopyMetafileToOleField(OleField As Field, FileName As String) As Boolean
  ' copy the Metafile on disk to the OleField
  Dim Handle As Integer
  Dim Buffer As String
  Dim BytesNeeded As Long
  Dim Buffers As Long
  Dim Remainder As Long
  Dim i As Long
  
  On Error GoTo CopyMetafileToOleField_ERR
  Handle = FreeFile
  Open FileName For Binary As Handle
  BytesNeeded = LOF(Handle)
     
  
  'Calculate the number of buffers needed to copy
  'the OLE object based on the bitmap size:
  Buffers = BytesNeeded \ BUFFER_SIZE
  Remainder = 0
  For i = 1 To Buffers
    Buffer = Input(BUFFER_SIZE, Handle)
'    Get Handle, Remainder, Buffer
    OleField.AppendChunk Buffer
  Next
  
  Remainder = BytesNeeded - (BUFFER_SIZE * Buffers)
  'Copy the remaining chunk of the file:
  Buffer = Input(Remainder, Handle)
  OleField.AppendChunk Buffer

  Close Handle
  CopyMetafileToOleField = True
  Exit Function

CopyMetafileToOleField_ERR:
  CopyMetafileToOleField = False
  Close Handle
  Exit Function
End Function

'------------------------------
Public Function GetPictureFromOleField(ctlPict As Object, OleField As Field) As Boolean
  ' Get the Picture from the OleField. The Picture is saved as a non-structured BLOB
  ' and totally ignores any standards found for MSAccess OleField datatypes
  Dim R As Integer
  Dim Handle As Integer
  Dim tempFileName As String
  Dim bRet As Boolean
  
  GetPictureFromOleField = False
  
  If OleField.Type = DT_LONGBINARY Then
    tempFileName = Space(512)
    Dim tempPathName As String
    tempPathName = Space(255)
    If GetTempPath(Len(tempPathName), tempPathName) = 0 Then
      Exit Function
    End If
    R = GetTempFileName(tempPathName, "", 0, tempFileName)
      'Save the Picture
    If tempFileName <> "" Then
      bRet = CopyOleFieldToMetafile(OleField, tempFileName)
      If Not bRet Then Exit Function
    Else
      Exit Function
    End If
   
    ctlPict.Picture = LoadPicture(tempFileName)
    Kill tempFileName
  End If
  
  GetPictureFromOleField = bRet
End Function


'------------------------------
Private Function CopyOleFieldToMetafile(OleField As Field, FileName As String) As Boolean
  ' copy the Metafile on disk to the OleField
  Dim Handle As Integer
  Dim Buffer As String
  Dim BytesNeeded As Long
  Dim Buffers As Long
  Dim Remainder As Long
  Dim i As Long
  
  CopyOleFieldToMetafile = False
  On Error GoTo CopyOleFieldToMetafile_ERR
  
  BytesNeeded = OleField.FieldSize()
  If BytesNeeded = 0 Then Exit Function
    
    'Calculate the number of buffers needed to copy
    'the OLE object based on the field size:
  Buffers = BytesNeeded \ BUFFER_SIZE
  Remainder = BytesNeeded Mod BUFFER_SIZE

  Handle = FreeFile
  Open FileName For Binary As Handle
  
  For i = 0 To Buffers - 1
    Buffer = OleField.GetChunk(i * BUFFER_SIZE, BUFFER_SIZE)
    Put Handle, , Buffer
  Next
  'Copy the remaining chunk of the file:
  Buffer = OleField.GetChunk(Buffers * BUFFER_SIZE, Remainder)
  Put Handle, , Buffer

  Close Handle
  CopyOleFieldToMetafile = True
  Exit Function

CopyOleFieldToMetafile_ERR:
  Close Handle
  CopyOleFieldToMetafile = False
End Function


'------------------------------
Public Function CopyFileToOleField(OleField As Field, FileName As String) As Boolean
  ' copy the file on disk to the OleField
  Dim Handle As Integer
  
  ' ==== Using Byte Array =====
  Dim ByteArray() As Byte
  ReDim ByteArray(BUFFER_SIZE - 1)
  
  Dim BytesNeeded As Long
  Dim Buffers As Long
  Dim Remainder As Long
  Dim i As Long
  
  On Error GoTo CopyFileToOleField_ERR
  Handle = FreeFile
  Open FileName For Binary As Handle
  BytesNeeded = LOF(Handle)
     
  
  
  'Calculate the number of buffers needed to copy
  'the OLE object based on the bitmap size:
  Buffers = BytesNeeded \ BUFFER_SIZE
  Remainder = 0
  For i = 1 To Buffers
    ByteArray = InputB(BUFFER_SIZE, Handle)
'    Get Handle, Remainder, Buffer
    OleField.AppendChunk ByteArray
  Next
  
  'Copy the remaining chunk of the file:
  Remainder = BytesNeeded - (BUFFER_SIZE * Buffers)
  ReDim ByteArray(Remainder - 1)
  ByteArray = InputB(Remainder, Handle)
  OleField.AppendChunk ByteArray

  Close Handle
  CopyFileToOleField = True
  Exit Function

CopyFileToOleField_ERR:
  CopyFileToOleField = False
  Close Handle
  Exit Function
End Function


'------------------------------
Public Function CopyOleFieldToFile(OleField As Field, FileName As String) As Boolean
  ' copy the OleField to file on disk
  Dim Handle As Integer
  Dim BytesNeeded As Long
  Dim Buffers As Long
  Dim Remainder As Long
  Dim i As Long
  
  CopyOleFieldToFile = False
  On Error GoTo CopyOleFieldToFile_ERR
  
  BytesNeeded = OleField.FieldSize()
  If BytesNeeded = 0 Then Exit Function
    
    'Calculate the number of buffers needed to copy
    'the OLE object based on the field size:
  Buffers = BytesNeeded \ BUFFER_SIZE
  Remainder = BytesNeeded Mod BUFFER_SIZE

  Handle = FreeFile
'  Open FileName For Binary As Handle
  Open FileName For Binary Access Write As Handle
  
  ' ==== Using Byte Array =====
  Dim ByteArray() As Byte
  ReDim ByteArray(BUFFER_SIZE - 1)
  For i = 0 To Buffers - 1
    ByteArray = OleField.GetChunk(i * BUFFER_SIZE, BUFFER_SIZE)
    Put Handle, , ByteArray()
  Next i
    'Copy the remaining chunk of the file:
  ReDim ByteArray(Remainder - 1)
  ByteArray = OleField.GetChunk(Buffers * BUFFER_SIZE, Remainder)
  Put Handle, , ByteArray()

  Close Handle
  CopyOleFieldToFile = True
  Exit Function

CopyOleFieldToFile_ERR:
  Close Handle
  CopyOleFieldToFile = False
End Function



'======================================================================================
' CommonDialog Helpers
'======================================================================================
'------------------------------
Public Function dlg_Open(FileName As String, szTitle As String, _
                      strDefaultExt As String, strFilter As String, _
                      bCreate As Boolean, CommonDlg As Object) As Boolean
  ' Get a path and name, from the User
  Dim strDir As String
  Dim strMsg As String
  
  On Error Resume Next
  
  dlg_Open = False
  CommonDlg.CancelError = True          ' enable so that can test for Err
  CommonDlg.DefaultExt = strDefaultExt
  CommonDlg.DialogTitle = szTitle
  CommonDlg.MaxFileSize = 2600
  CommonDlg.FLAGS = cdlOFNHideReadOnly Or cdlOFNPathMustExist Or cdlOFNFileMustExist
  If bCreate Then
    CommonDlg.FLAGS = CommonDlg.FLAGS Or cdlOFNCreatePrompt
  End If
  strDir = StripFile(FileName)
  If Len(strDir) > 0 Then       ' if empty, will default to App.Path
    CommonDlg.InitDir = strDir
  End If
  CommonDlg.Filter = strFilter
  CommonDlg.FileName = FileName
  CommonDlg.ShowOpen
  If Err = 0 Then
    FileName = CommonDlg.FileName
    dlg_Open = True
  End If
  
End Function


