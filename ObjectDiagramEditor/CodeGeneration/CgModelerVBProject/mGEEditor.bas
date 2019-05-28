Attribute VB_Name = "mGEEditor"
'======================================================================================
'
' Module:   mGEEditor
' Updated:                By
'
'--------------------------------------------------------------------------------------
'======================================================================================

Option Explicit

'=================================================================
' Start of Declarations Section
'=================================================================

'========================================================
'
' constants to ID the Input Forms
'
Global Const c_nfrmGEEditor = 1  ' General Purpose Graphical Editor

' Constants for docking
Public Const cNO_DOCK = 0
Public Const cDOCK_TOP = 1
Public Const cDOCK_BOTTOM = 2
Public Const cDOCK_LEFT = 3
Public Const cDOCK_RIGHT = 4
Public Const STATE_DOCKED = 1
Public Const STATE_FLOAT = 2

Public Declare Function SetParent Lib "user32" (ByVal hWndChild As Long, ByVal hWndNewParent As Long) As Long

'========================================================
' **********
' INI File Declarations
' **********
Global Const INI_FILENAME = "CGModeler.ini"  ' Name of the INI File
  
'
' User Options for GeEditor
'
Global Const INISECTION_GEEDITOR = "CGEditor"
'
' recent files
'
Global Const INIENTRY_RECENTFILE = "RecentFile"
'
' Printer Setup Options (per form)
'
Global Const INIENTRY_PAPERSIZE = "PaperSize"

'
' recent files
'
Global Const INISECTION_LIBRARY As String = "Libraries"
Global Const INIENTRY_RECENTLIBFINDS = "FoundLibrary"
Private Const n_MaxLibFinds As Integer = 15 ' max entries

'
' User Options for App and GeEditor
'
Global Const INISECTION_UAO = "UserOptions"      ' Application related options
Global Const INIENTRY_MAINTOOLBAR = "MainToolbar"   ' Show (1) /Hide(0) it
Global Const INIENTRY_AUXTOOLBAR = "AuxToolbar"   ' Show (1) /Hide(0) it
Global Const INIENTRY_STATUSBAR = "StatusBar"       ' Show (1) /Hide(0) it
Global Const INIENTRY_SNAP1X = "Snap1X"       ' snap 1
Global Const INIENTRY_SNAP1Y = "Snap1Y"
Global Const INIENTRY_SNAP2X = "Snap2X"       ' snap 2
Global Const INIENTRY_SNAP2Y = "Snap2Y"
Global Const INIENTRY_SNAP3X = "Snap3X"       ' snap 3
Global Const INIENTRY_SNAP3Y = "Snap3Y"
Global Const INIENTRY_SNAP4X = "Snap4X"       ' snap 4
Global Const INIENTRY_SNAP4Y = "Snap4Y"
Global Const INIENTRY_SNAP5X = "Snap5X"       ' snap 5
Global Const INIENTRY_SNAP5Y = "Snap5Y"
Global Const INIENTRY_SNAPMULT = "SnapMultiplier"
Global Const INIENTRY_SNAPTOSELECTION = "SnapToSelection"

' PBH for new style toolbox Non 8/99
Global Const INIENTRY_TOOLBOX = "Toolbox"         ' Show (1) /Hide(0) it
Global Const INIENTRY_TOOLPANEL = "ToolPanel"         ' Show (1) /Hide(0) it
Global Const INIENTRY_TOOLPANELNUMBER = "ToolPanelNumber"     ' panel number visible
Global Const INIENTRY_TOOLPANELSIDE = "ToolPanelSide"     ' 0=left,1=right
Global Const INIENTRY_SHOWINSERTION = "ShowInsertion"
Global Const INIENTRY_DRAWTRANSPARENT = "DrawTransparent"
Global Const INIENTRY_SHOWCONNECTIONS = "ShowConnections"

Global Const INIENTRY_TOOLBARROWS = "ToolBarRows"       '1 = 1 row, 2 = 2 rows etc
Global Const INIENTRY_USER = "User"
Global Const INIENTRY_TOOLPANELCONFIG = "ToolPanelConfiguration"  'a string like "1,2,4;1,3,4;3"
 
Global Const INIENTRY_OD_SNAP = "SnapDefault"   ' _OD_ = Override default, 0 = Use Default, 1= off, 2 = on
Global Const INIENTRY_OD_MARGINS = "MarginsDefault"   ' _OD_ = Override default, 0 = Use Default, 1= off, 2 = on
 
' colors on panel
Global Const INIENTRY_COLOR1 = "Color1"
Global Const INIENTRY_COLOR2 = "Color2"
Global Const INIENTRY_COLOR3 = "Color3"
Global Const INIENTRY_COLOR4 = "Color4"
Global Const INIENTRY_COLOR5 = "Color5"
Global Const INIENTRY_COLOR6 = "Color6"
Global Const INIENTRY_COLOR7 = "Color7"
Global Const INIENTRY_COLOR8 = "Color8"

Global Const INIENTRY_OBJECTHITSENS = "ObjectHitSensitivity"
Global Const INIENTRY_OBJECTSNAPSENS = "ObjectSnapSensitivity"
Global Const INIENTRY_SNAPTOCONNECTIONS = "SnapToConnections"
Global Const INIENTRY_OBJECTSNAP = "ObjectSnap"

Global Const INIENTRY_SNAPTOSHAPE = "SnapToShape"

Global Const INIENTRY_COLOR = "Color"

' InsertPicture path
Global Const INIENTRY_LASTPICTUREPATH As String = "LastPicturePath"

' INI constants  - FileBrowser
Global Const INIENTRY_RECENTBROWSEFILE As String = "RecentBrowseFile"
Global Const INIENTRY_BROWSECOLOURPRINT As String = "BrowsePrintColour"


' Named Storages
Global Const c_sLayerDataName As String = "LayerData" ' layer data section
Global Const c_sUDIDataName As String = "UDIData" ' user defined items section


'
' System Error handling and reporting
'
Declare Function GetLastError Lib "Kernel32" () As Long

Declare Function FormatMessage Lib "Kernel32" Alias "FormatMessageA" (ByVal dwFlags As Long, _
                      lpSource As Any, ByVal dwMessageId As Long, _
                      ByVal dwLanguageId As Long, ByVal lpBuffer As String, _
                      ByVal nSize As Long, Arguments As Long) As Long




'=================================================================
' End of Declarations Section
'=================================================================

'======================================================================================
' Misc Forms Helpers
'======================================================================================
'------------------------------
Public Function IsLoaded(index As Integer, MyFormName As String) As Boolean
  ' Accepts: a form name
  ' Purpose: determines if a form is loaded
  ' Returns: True if specified the form is loaded;
  '          False if the specified form is not loaded.
  Dim i

  IsLoaded = False
  For i = 0 To Forms.count - 1
    If Forms(i).Name = MyFormName Then
      IsLoaded = True
      index = i
      Exit Function       ' Quit function once form has been found.
    End If
  Next
End Function

'======================================================================================
' Status Message Window Management
'======================================================================================
'------------------------------
Public Sub ShowStatusMsg(szMsg As String)
  Dim frmMsg As frmStatus
  On Error Resume Next
  If GetStatusWindow(frmMsg) Then
'    frmMsg.ZOrder ' = 0   ' move to front
    'frmMsg.ShowStatusMsg szMsg
    gMsgWnd.LogMessage szMsg
  End If
End Sub

Public Sub ShowStatusMsgWindow()
  Dim frmMsg As frmStatus
  On Error Resume Next
  If GetStatusWindow(frmMsg) Then
 '   frmMsg.ShowStatusMsgWindow
  End If
End Sub


'------------------------------
Public Sub CloseStatusMsgDlg()
    ' close the Status Message Dialog if open
  Dim index As Integer
    ' if already loaded, then just bring to front
  On Error Resume Next
  If IsLoaded(index, "frmStatus") Then
    Unload Forms(index)
  End If
End Sub

'------------------------------
Public Sub ShowAnyPostModalStatusMsgs()
  ' show any status messages that may have occured during
  ' a Modal Dialog
  Dim frmMsg As frmStatus
  Dim index As Integer
  On Error Resume Next
  If IsLoaded(index, "frmStatus") Then
    Set frmMsg = Forms(index)
    frmMsg.Show
  End If
End Sub

'------------------------------
Public Sub ClearStatusMsg()
  Dim frmMsg As frmStatus
  On Error Resume Next
  If GetStatusWindow(frmMsg) Then
    frmMsg.ClearStatusMsg
  End If
End Sub
'------------------------------
Private Function GetStatusWindow(frmMsg As Form) As Boolean
  Dim index As Integer
  On Error Resume Next
  If Not IsLoaded(index, "frmStatus") Then
    Set frmMsg = New frmStatus
  Else
    Set frmMsg = Forms(index)
  End If
  GetStatusWindow = True
End Function

'=====================================================================
' Printing routines
'=====================================================================
'------------------------------
Public Function PrintGeFile(Printer As Printer, GeCtrl As CG, _
          bBSize As Boolean, bMetric As Boolean)
  ' actually print it
  Dim nSavedDC As Long
  Dim nOrientGE As Integer
  
  On Error Resume Next
  
'  nOrientGE = GeCtrl.PageOrientation      ' 1 = Portrait, 2 = Landscape
'  Printer.Orientation = nOrientGE
  
'  If GeCtrl.DrawingWidth > GeCtrl.DrawingHeight Then
'    Printer.Orientation = vbPRORLandscape  ' 2
'  Else
'    Printer.Orientation = vbPRORPortrait   ' 1
'  End If
  
    ' actually print it
  Printer.ScaleMode = 3             'pixel mode
  BeginWaitCursor
  Printer.Print ""
  nSavedDC = SaveDC(Printer.hDC)
  GeCtrl.PrinterName = Printer.DeviceName
  GeCtrl.DoPrint Printer.hDC, Printer.hDC, _
                    Printer.ScaleLeft, Printer.ScaleTop, _
                    Printer.ScaleWidth, Printer.ScaleHeight
  nSavedDC = RestoreDC(Printer.hDC, nSavedDC)
  Printer.EndDoc
  EndWaitCursor

End Function



'
'======================================================================================
' Misc Helpers
'======================================================================================
Public Function FloatModulus(fNum As Single, fDiv As Single, fResult As Single) As Boolean
Dim fRemainder As Single
Dim nCount As Integer

  FloatModulus = False
  If fDiv = 0 Then
    Exit Function
  End If
  fRemainder = fNum / fDiv
  
  If fRemainder = 0# Then
    fResult = 0#
    FloatModulus = True
    Exit Function
  End If
  nCount = Int(fRemainder)
  fResult = fNum - (nCount * fDiv)
  FloatModulus = True
End Function

'=====================================================================
' VbControl Helpers
'=====================================================================
'------------------------------
Public Function SelectAllTextControlText(txt As Object)
    ' Select all the text in the Text Control field
  Dim nLen As Integer
  
  On Error Resume Next
  nLen = Len(txt.Text)
  If nLen > 0 Then
    txt.SelStart = 0
    txt.SelLength = nLen
  End If
End Function


'======================================================================================
' FileDialog Helpers
'======================================================================================
'------------------------------
Public Function SetCurrentDirectory(ByVal strName As String)
  ' change working dir to match path in string provided
  Dim strpath As String
  On Error Resume Next
  strpath = StripFile(strName)
  ChDir strpath
  
End Function

'------------------------------
Public Function GetWMFPath(FileName As String, szTitle As String, bCreate As Boolean, _
                    CommonDlg As Object) As Boolean
  ' Get a WMF path and name, from the User
  Dim strDir As String
  Dim strMsg As String
  
  On Error Resume Next
  GetWMFPath = False
  CommonDlg.CancelError = True  ' enable so that can test for Err
  CommonDlg.DefaultExt = "WMF"
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
  CommonDlg.Filter = "Windows metafile (*.wmf)|*.wmf||"
  CommonDlg.FileName = FileName
'  CommonDlg.Action = 1  ' Open
  CommonDlg.ShowOpen
  If Err = 0 Then
    FileName = CommonDlg.FileName
    GetWMFPath = True
  End If
End Function

'------------------------------
Public Function GetBMPPath(FileName As String, szTitle As String, bCreate As Boolean, _
                    CommonDlg As Object) As Boolean
  ' Get a BMP path and name, from the User
  Dim strDir As String
  Dim strMsg As String
  
  On Error Resume Next
  GetBMPPath = False
  CommonDlg.CancelError = True  ' enable so that can test for Err
  CommonDlg.DefaultExt = "BMP"
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
  CommonDlg.Filter = "Bitmap (*.bmp)|*.bmp||"
  CommonDlg.FileName = FileName
'  CommonDlg.Action = 1  ' Open
  CommonDlg.ShowOpen
  If Err = 0 Then
    FileName = CommonDlg.FileName
    GetBMPPath = True
  End If
End Function

'-------------------------------------------
Public Function DoWriteRecentFiles(OpenFileName As String, ByVal IniSection As String, ByVal uBnd As Integer)
    ' Write list in menu to ini.
    ' Copy RecentFile1 to RecentFile2, and so on.
    ' Write the open file to first recent file.
  Dim strVal As String
  Dim strKey As String
  Dim i As Integer
  Dim iCur As Integer
  Dim iShift As Integer
  Dim bShift As Boolean
  
  On Error Resume Next
    ' setup arrays
  ReDim astrIn(uBnd - 1) As String
  ReDim astrOut(uBnd - 1) As String
    
    ' get current from INI
  For i = uBnd To 1 Step -1
    strKey = INIENTRY_RECENTFILE & i
    strVal = ""
    strVal = AppGetProfileString(IniSection, strKey, strVal)
    astrIn(i - 1) = strVal
  Next i
    ' check if should shift or rollover
  iShift = -1
  bShift = False
  For i = uBnd To 1 Step -1
    If (UCase(astrIn(i - 1)) = UCase(OpenFileName)) Then
      bShift = True
      iShift = i
      Exit For
    End If
  Next i
  '
  If bShift Then
    iCur = uBnd
    For i = uBnd To 1 Step -1
      If i <> iShift Then
        astrOut(iCur - 1) = astrIn(i - 1)
        iCur = iCur - 1
      End If
    Next i
  Else
    ' rollover
    iCur = uBnd
    For i = (uBnd - 1) To 1 Step -1
      astrOut(iCur - 1) = astrIn(i - 1)
      iCur = iCur - 1
    Next i
  End If
    ' write out list (except for last)
  For i = uBnd To 2 Step -1
    strKey = INIENTRY_RECENTFILE & i
    strVal = astrOut(i - 1)
    AppWriteProfileString IniSection, strKey, strVal
  Next i
    ' Write the open file to first recent file.
  strKey = INIENTRY_RECENTFILE & 1
  strVal = OpenFileName
  AppWriteProfileString IniSection, strKey, strVal
End Function


'===========================================================================
' Libraries found for mismatches
'===========================================================================
'-------------------------------------------
Public Function GetLibraryFromIni(ByVal strOldLibName As String, strNewName As String) As Boolean
  ' see if in ini. return true if so and fill in new name
'Global Const INIENTRY_RECENTLIBFINDS = "RecentLibraryFinds"
'Private Const n_MaxLibFinds As Integer = 15 ' max entries
  Dim strVal As String
  Dim strKey As String
  Dim i As Integer
  Dim strOldName As String
  Dim strTmp As String
  
  On Error Resume Next
  GetLibraryFromIni = False
  strOldName = StripPath(strOldLibName)
  
  For i = 1 To n_MaxLibFinds
    strKey = INIENTRY_RECENTLIBFINDS & i
    strVal = ""
    strVal = AppGetProfileString(INISECTION_LIBRARY, strKey, strVal)
    If Len(strVal) > 0 Then
      strTmp = StripPath(strVal)
        ' check just the name
      If UCase(strTmp) = UCase(strOldName) Then
        strTmp = strVal
        If FileExists(strTmp) Then
            ' assume this is it
          strNewName = strVal
          GetLibraryFromIni = True
          Exit Function
        End If
      End If
    End If
  Next i
End Function

'-------------------------------------------
Public Function AddLibraryToIni(strNewName As String) As Boolean
  ' add to ini file
    ' Write list in menu to ini.
    ' Copy RecentFile1 to RecentFile2, and so on.
    ' Write the open file to first recent file.
  Dim strVal As String
  Dim strKey As String
  Dim i As Integer
  Dim iCur As Integer
  Dim iShift As Integer
  Dim bShift As Boolean
  Dim uBnd As Integer
  
  On Error Resume Next
    ' setup arrays
  uBnd = n_MaxLibFinds
  ReDim astrIn(uBnd - 1) As String
  ReDim astrOut(uBnd - 1) As String
    ' get current from INI
  For i = uBnd To 1 Step -1
    strKey = INIENTRY_RECENTLIBFINDS & i
    strVal = ""
    strVal = AppGetProfileString(INISECTION_LIBRARY, strKey, strVal)
    astrIn(i - 1) = strVal
  Next i
    ' check if should shift or rollover
  iShift = -1
  bShift = False
  For i = uBnd To 1 Step -1
    If (UCase(astrIn(i - 1)) = UCase(strNewName)) Then
      bShift = True
      iShift = i
      Exit For
    End If
  Next i
  '
  If bShift Then
    iCur = uBnd
    For i = uBnd To 1 Step -1
      If i <> iShift Then
        astrOut(iCur - 1) = astrIn(i - 1)
        iCur = iCur - 1
      End If
    Next i
  Else
    ' rollover
    iCur = uBnd
    For i = (uBnd - 1) To 1 Step -1
      astrOut(iCur - 1) = astrIn(i - 1)
      iCur = iCur - 1
    Next i
  End If
    ' write out list (except for last)
  For i = uBnd To 2 Step -1
    strKey = INIENTRY_RECENTLIBFINDS & i
    strVal = astrOut(i - 1)
    AppWriteProfileString INISECTION_LIBRARY, strKey, strVal
  Next i
    ' Write the open file to first recent file.
  strKey = INIENTRY_RECENTLIBFINDS & 1
  strVal = strNewName
  AppWriteProfileString INISECTION_LIBRARY, strKey, strVal

End Function



'------------------------------
Public Function FormatCSVStr(ByVal strIN As String) As String
  ' format as CSV.
  ' If any comma in string, wrap it in quotes
  ' If any quotes, double em up.
  Dim pos As Long
  Dim strTmp As String
  Dim nLen As Long
  
  On Error Resume Next
  strTmp = strIN
  ' if any " in string, add an extra one
  Dim i As Long
  Dim strRet As String, strT As String
  
  pos = InStr(strTmp, """")
  If pos > 0 Then
    nLen = Len(strTmp)
    For i = 1 To nLen
      strT = Mid(strTmp, i, 1)
      If strT = """" Then
        strT = strT & """"
      End If
      strRet = strRet & strT
    Next i
  Else
    strRet = strTmp
  End If
  If Err <> 0 Then Err = 0
  If InStr(strRet, ",") Then strRet = """" & strRet & """"
  FormatCSVStr = strRet
End Function

