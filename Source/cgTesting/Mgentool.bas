Attribute VB_Name = "mGeneralPurposeTools"
'======================================================================================
'
' Module:   General Purpose Tools
' 5/6/96 - AEM
' - added VerifyConvertIsInteger, VerifyConvertIsLong
'
'======================================================================================

Option Explicit



'-----------------------------------
Function FieldType(DataType) As String
  ' Translates the field type code returned by the database engine
  ' into a field type name.  This function is used by any dialog
  ' displaying the structure of a table

  On Error GoTo FIELD_TYPE_ERROR

  Select Case DataType
    Case dbDate
      FieldType = "Date/Time"
    Case dbText
      FieldType = "Text"
    Case dbMemo
      FieldType = "Memo"
    Case dbBoolean
      FieldType = "Yes/No"
    Case dbInteger
      FieldType = "Integer"
    Case dbLong
      FieldType = "Long Integer"
    Case dbCurrency
      FieldType = "Currency"
    Case dbSingle
      FieldType = "Single"
    Case dbDouble
      FieldType = "Double"
    Case dbByte
      FieldType = "Byte"
    Case dbLongBinary
      FieldType = "Long Binary"
    Case Else
      FieldType = "<unknown>"
  End Select

FIELD_TYPE_EXIT:
  Exit Function

FIELD_TYPE_ERROR:
  MsgBox "FieldType() error:  " & Error$
  Resume FIELD_TYPE_EXIT
End Function


'---------------------------------
Public Function GetNumericValue(strConvert As String) As Single
' get numeric value from end of string, note there may be numbers before end discard them
' string must be of the form '??????x'  where x is one or more numbers. The string '#Pow23Y45' will
' return 45.
' NOTE: (AEM - 4/18/97 ) To be used with BCWMF.OCX interface

Dim val As Single
Dim i As Long
Dim char As String
    val = 0
    For i = 1 To Len(strConvert)
        char = Mid(strConvert, i, 1)
        If char >= "0" And char <= "9" Then
            val = val & char
        ElseIf char = " " Then
            '
        Else
            val = 0
        End If
    Next i
    GetNumericValue = val
End Function

'---------------------------------
Public Sub ParseString(nArgC As Integer, szArgV() As String, szSource As String, szDelimiter As String)
  ' Parses a string based on a specified delimiter
  ' Fills szArgV() with strings (including 0 length strings) from szSource
  '

  Dim nSourceLen As Integer
  Dim nI As Integer
  Dim szChar As String * 1
  Dim nUBound As Integer
  
  nUBound = 0
  On Error Resume Next
  nUBound = UBound(szArgV)
  On Error GoTo 0
  If nUBound = 0 Then
    nUBound = 10
    ReDim szArgV(nUBound) As String
  End If
  
  nArgC = 0
  szArgV(0) = ""
  nSourceLen = Len(szSource)
  If nSourceLen > 0 Then
    For nI = 1 To nSourceLen
      szChar = Mid(szSource, nI, 1)
      If szChar = szDelimiter Then
        szArgV(nArgC) = LTrim(RTrim(szArgV(nArgC)))
        nArgC = nArgC + 1
        szArgV(nArgC) = ""
        
        If nArgC = nUBound Then
          nUBound = nArgC + 10
          ReDim Preserve szArgV(nUBound) As String
        End If

      Else
        szArgV(nArgC) = szArgV(nArgC) & szChar
      End If
    Next nI
    szArgV(nArgC) = LTrim(RTrim(szArgV(nArgC)))
    nArgC = nArgC + 1
  End If

End Sub

'---------------------------------------
' Tests all characters in a string to ensure they are alpha
Function IsAlpha(szTest As String) As Boolean
  Dim nLen As Integer
  Dim nI As Integer
  Dim nChar As Integer
  Dim bRet As Boolean
  Const UA = 65
  Const UZ = 90
  Const LA = 97
  Const LZ = 122
  nLen = Len(szTest)
  If nLen = 0 Then Exit Function
  ' allow dollar sign characters
  If InStr(szTest, "$") > 0 Then
    bRet = True
  Else
    bRet = True
    For nI = 1 To nLen
      nChar = Asc(Mid(szTest, nI, 1))
      If Not ((nChar >= UA And nChar <= UZ) Or (nChar >= LA And nChar <= LZ)) Then
        bRet = False
        Exit For
      End If
    Next nI
  End If
  IsAlpha = bRet
End Function

'---------------------------------------------------
Function XIsNumeric(szTest As String) As Boolean
  Dim bRet As Boolean
  bRet = False
  If InStr(szTest, "$") > 0 Then
    bRet = True
  Else
    If IsNumeric(szTest) Then
      bRet = True
    End If
  End If
  XIsNumeric = True
End Function

'---------------------------------------------------
Function StringsAreSame(str1 As String, str2 As String) As Boolean
  ' compare 2 strings.
  ' return True if they are the same, False otherwise
  Dim iRet As Integer
  On Error Resume Next
  StringsAreSame = False
  If (Not IsNull(str1)) And (Not IsNull(str2)) Then
    iRet = StrComp(str1, str2)
    If iRet = 0 Then StringsAreSame = True
  End If
End Function

'---------------------------------------------------
Function StringsAreDifferent(str1 As String, str2 As String) As Boolean
  ' compare 2 strings.
  ' return True if they are different, False otherwise
  Dim iRet As Integer
  On Error Resume Next
  StringsAreDifferent = True
  If (Not IsNull(str1)) And (Not IsNull(str2)) Then
    iRet = StrComp(str1, str2)
    If iRet = 0 Then StringsAreDifferent = False
  End If
End Function


'--------------------------
Function DDXText(strOrig As String, strOut As String, _
                            nMax As Integer, bShowMsg As Boolean) As Boolean
  ' Verify Text Length is OK
  Dim strMsg As String
  On Error Resume Next
  DDXText = False
  If Len(strOrig) <= nMax Then
    strOut = strOrig
    DDXText = True
    Exit Function
  ElseIf bShowMsg Then
    strMsg = "Please Enter a String no Longer than " & Format$(nMax) & " characters."
    MsgBox strMsg, MB_ICONEXCLAMATION
  End If
End Function
'--------------------------
Function DDXInteger(strText As String, nValOrig As Integer, _
                            nMin As Integer, nMax As Integer, ValOut As Integer, _
                            bShowMsg As Boolean) As Boolean
  ' Verify Text is a Integer. Verify it is in Valid Range.
  ' Convert and return if pass all tests
  Dim nVal As Integer
  Dim strMsg As String
  On Error Resume Next
  DDXInteger = False
  ValOut = nValOrig
  If IsNumeric(strText) Then
    nVal = CInt(strText)
    If Err = 0 Then
      If nVal >= nMin And nVal <= nMax Then
        ValOut = nVal
        DDXInteger = True
        Exit Function
      ElseIf bShowMsg Then
        strMsg = "Please Enter a Value between " & Format$(nMin) & " and " & Format$(nMax)
        MsgBox strMsg, MB_ICONEXCLAMATION
      End If
    End If
  ElseIf bShowMsg Then
    MsgBox "Invalid Numeric Character(s)", MB_ICONEXCLAMATION
  End If
End Function
'--------------------------
Function DDXLong(strText As String, nValOrig As Long, _
                          nMin As Long, nMax As Long, ValOut As Long, _
                          bShowMsg As Boolean) As Boolean
  ' Verify Text is a Long. Verify it is in Valid Range.
  ' Convert and return if pass all tests
  Dim nVal As Long
  Dim strMsg As String
  DDXLong = False
  ValOut = nValOrig
  If IsNumeric(strText) Then
    On Error Resume Next
    nVal = CLng(strText)
    If Err = 0 Then
      If nVal >= nMin And nVal <= nMax Then
        ValOut = nVal
        DDXLong = True
        Exit Function
      ElseIf bShowMsg Then
        strMsg = "Please Enter a Value between " & Format$(nMin) & " and " & Format$(nMax)
        MsgBox strMsg, MB_ICONEXCLAMATION
      End If
    End If
  ElseIf bShowMsg Then
    MsgBox "Invalid Numeric Character(s)", MB_ICONEXCLAMATION
  End If
End Function

'--------------------------
Public Function DDXDouble(strText As String, nValOrig As Double, _
                        nMin As Double, nMax As Double, ValOut As Double, _
                        bShowMsg As Boolean) As Boolean
  ' Verify Text is a Float (Double). Verify it is in Valid Range.
  ' Convert and return if pass all tests
  Dim nVal As Double
  Dim strMsg As String
  
  On Error Resume Next
  DDXDouble = False
  ValOut = nValOrig
  If IsNumeric(strText) Then
    nVal = CDbl(strText)
    If Err = 0 Then
      If nVal >= nMin And nVal <= nMax Then
        ValOut = nVal
        DDXDouble = True
        Exit Function
      ElseIf bShowMsg Then
        strMsg = "Please Enter a Value between " & Format$(nMin) & " and " & Format$(nMax)
        MsgBox strMsg, MB_ICONEXCLAMATION
      End If
    End If
  ElseIf bShowMsg Then
    MsgBox "Invalid Numeric Character(s)", MB_ICONEXCLAMATION
  End If
End Function


'--------------------------
Public Function DDXShortDate(strText As String, DateOut As Date, _
                  bShowMsg As Boolean) As Boolean
  ' Verify Text is a Short Date Format
  ' Convert and return if pass all tests
  Dim dDate As Date
  Dim strVal As String
  
  On Error Resume Next
  DDXShortDate = False
  DateOut = Now
  If IsDate(strText) Then
    DateOut = CDate(strText)
  ElseIf bShowMsg Then
    MsgBox "Invalid Date Format. Please enter in the format of mm/dd/yy", MB_ICONEXCLAMATION
    Exit Function
  End If
    ' convert to short format
  strVal = Format(DateOut, "Short Date")
  DateOut = CDate(strVal)
  DDXShortDate = True
End Function

'--------------------------
Public Function ConvertDateToShortFormat(dDateIn As Date) As Date
  ' Convert Date to Short Format and return
  Dim strVal As String
  On Error Resume Next
  strVal = Format(dDateIn, "Short Date") ' convert to short format
  ConvertDateToShortFormat = CDate(strVal)
  If Err <> 0 Then
    ConvertDateToShortFormat = Now
  End If
End Function




'---------------------------------------------------
Function GetCountOfVisibleLines(lbControl As Control) As Integer
' Get the count of visible lines showing in a listbox
  Dim nHeightInPixels As Long
  Dim hDC As Integer
  Dim nPixelsPerInch As Integer
  Dim nHeightInTwips As Integer
  Dim nListBoxBorderHeight As Integer
  Dim lbhWnd As Long
  
  lbhWnd = lbControl.hWnd
  nHeightInPixels = SendMessage(lbhWnd, LB_GETITEMHEIGHT, 0, 0)
  nPixelsPerInch = GetPixelsPerInchY()
  ' hip (pixels) / ppi (pixels/inch) / 1/1440 (inch/twip)
  ' -> hip / pph * 1440
  nHeightInTwips = nHeightInPixels / nPixelsPerInch * 1440
  ' a measurement of 24 twips was read for list box border height
  ' when the line height was 192 twips.
  nListBoxBorderHeight = 24 / 192 * nHeightInTwips
  If nHeightInTwips <> 0 Then
    GetCountOfVisibleLines = (lbControl.Height - nListBoxBorderHeight) / nHeightInTwips
  Else
    GetCountOfVisibleLines = 10
  End If
End Function

'---------------------------------------------------
Function SetTabStops(lbControl As Control, nTabTwips As Integer, nPixelsPerInch As Integer) As Boolean
  ' Adds a tab stop to a list box control
  ' Assumptions:
  '     nPixelsPerIndex was derived using GetPixelsPerInchX().  This function
  '     is not called from SetTabStops() because it only needs to be called
  '     once for many tab stop settings.
  Dim nBaseUnitsPerPixel As Long
  Static nTabStop As Long
  Dim lbhWnd As Long
  nBaseUnitsPerPixel = GetDialogBaseUnits()
  ' baseunit = twips / (twips/inch) * (pixels/inch) / (pixels/baseunit)
  nTabStop = nTabTwips / 1440 * nPixelsPerInch / nBaseUnitsPerPixel
  lbhWnd = lbControl.hWnd
  SetTabStops = SendMessage(lbhWnd, LB_SETTABSTOPS, 1, nTabStop)
End Function

'---------------------------------------------------
Function GetPixelsPerInchY() As Integer
  On Error Resume Next
  Dim hDC As Long
  Dim dvMode As devMode
  hDC = CreateIC("Display", "", "", dvMode)
  If Err <> 0 Then
    GetPixelsPerInchY = 96
    Exit Function
  End If
  GetPixelsPerInchY = GetDeviceCaps(hDC, LOGPIXELSY)
  DeleteDC (hDC)
End Function

'---------------------------------------------------
Function GetPixelsPerInchX() As Integer
  On Error Resume Next
  Dim hDC As Long
  Dim dvMode As devMode
  hDC = CreateIC("Display", "", "", dvMode)
  If Err <> 0 Then
    GetPixelsPerInchX = 144
    Exit Function
  End If
  GetPixelsPerInchX = GetDeviceCaps(hDC, LOGPIXELSX)
  DeleteDC (hDC)
End Function

'-------------------------------------
Public Function SetAsOverLappedWindow(frm As Form, frmAfter As Form)
' NOTE: ARM - 5/7/97 - this DOES NOT WORK !!!!!
' Set frm on Top of FrmAfter
'BOOL SetWindowPos(
'  HWND hWnd,// handle of window
'  HWND hWndInsertAfter,// placement-order handle
'  int X,// horizontal position
'  int Y,// vertical position
'  int cx,// width
'  int cy,// height
'  UINT uFlags// window-positioning flags
');
  Dim nRet As Long
'  nRet = SetWindowPos(frm.hWnd, frmAfter.hWnd, 0, 0, 0, 0, HWND_TOP)
'  nRet = SetWindowPos(frm.hWnd, frmAfter.hWnd, 0, 0, 0, 0, SWP_NOMOVE)
  nRet = SetWindowPos(frm.hWnd, frmAfter.hWnd, 0, 0, 0, 0, TOPWND_FLAGS)
End Function
'-------------------------------------
Public Function ResetAsTopWindow(frm As Form)
  Dim nRet As Long
  nRet = SetWindowPos(frm.hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, TOPWND_FLAGS)
End Function

'-------------------------------------
Public Function SetAsTopWindow(frm As Form)
' Notes
'   To reset the form XXXX to NON-TOPMOST, use the following code:
'  nRet = SetWindowPos(XXXX.hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, FLAGS)
'  nRet <> 0 When Successful
  
  ' this code sets the form as Topmost
  ' nRet <> 0 When Successful
  Dim nRet As Long
  nRet = SetWindowPos(frm.hWnd, HWND_TOPMOST, 0, 0, 0, 0, TOPWND_FLAGS)
'  nRet = BringWindowToTop(frm.hwnd)
End Function



'-----------------------------
Public Function SetRedraw(ByVal hWnd As Long, bRedraw As Boolean)
  ' enable/disable Window redrawing itself
Dim wParam As Long
  If bRedraw Then
    ' set flag to True (do redraws)
    wParam = 1
  Else
    ' set flag to false (stop redraws)
    wParam = 0
  End If
  SendMessage hWnd, WM_SETREDRAW, wParam, 0
End Function


'-----------------------------
Function BeginWaitCursor()
  ' Set Cursor to HourGlass
  Screen.MousePointer = vbHourglass
End Function

'-----------------------------
Function EndWaitCursor()
  ' Set Cursor to Default
  Screen.MousePointer = 0 ' DO NOT USE ->vbArrow
End Function

'-----------------------------
Public Function ObjectExists(obj As Object) As Boolean
  ' determine is a VB 'Object' exists
  ' check for Empty (Null) Object.
  ' theType will be 'Nothing' in this case
  ObjectExists = Not (obj Is Nothing)
  
#If 0 Then
  Dim theType As String
  theType = TypeName(obj)
  If theType = "Nothing" Then
    ObjectExists = False
    Exit Function
  End If
  ObjectExists = True
#End If
End Function

'-----------------------------
Public Function ASSERT_OBJ(obj As Object)
  ' AEM - 4/22/97 - NOTE: DEBUG mode routine only
  ' just ASSERT that the Object is valid
  If (obj Is Nothing) Then
    MsgBox "ASSERT_OBJ: is Nothing"
  End If
End Function


'======================================================================================
' MATH ROUTINES
'======================================================================================
'---------------------------------
Public Function ArcCos(X As Double) As Double
    If X >= 1 Then X = 0.9999999
    ArcCos = Atn(-X / Sqr(-X * X + 1)) + 2 * Atn(1)
End Function


Public Function RoundUp(X As Double, Y As Double) As Integer
Dim partialResult As Integer
  If X = 0 Then
    RoundUp = 0
    Exit Function
  End If
  partialResult = X / Y
  If X - (partialResult * Y) > 0 Then
    partialResult = partialResult + 1
  End If
  RoundUp = partialResult
End Function

'======================================================================================
' Collection Related
'======================================================================================

'------------------------------
Public Function CollSearchVariantLong(lTest As Long, coll As Collection) As Boolean
    ' searches a collection of variants that contain Long's for the first
    ' occurance of lTest

    Dim var As Variant
    Dim lng As Long
    CollSearchVariantLong = False         ' lTest not found
    
    For Each var In coll
      lng = var
      If (lTest = lng) Then
          CollSearchVariantLong = True    ' lTest found
          Exit For
      End If
    Next var
  
End Function

'------------------------------
Public Function CollCopyVariant(collOut As Collection, collIn As Collection)
    Dim var As Variant
      
    For Each var In collIn
        collOut.Add collIn
    Next var

End Function
