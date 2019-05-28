Attribute VB_Name = "mGeFonts"
Option Explicit

'======================================================================================
' Sample code to Enum Fonts
'======================================================================================
'The following example creates a form with a list box containing an alphabetically sorted list of the fonts in your system.
'To run this example, create a form with a list box on it. The code for the form is as follows:

'Private Sub form_Load()
'    Module1.FillListWithFonts List1
'End Sub


'Place the following code in a module.
' The third argument in the definition of the EnumFontFamilies function is a Long that represents a procedure. The argument must contain the address of the procedure, rather than the value that the procedure returns. In the call to EnumFontFamilies, the third argument requires the AddressOf operator to return the address of the EnumFontFamProc procedure, which is the name of the callback procedure you supply when calling the Windows API function, EnumFontFamilies. Windows calls EnumFontFamProc once for each of the font families on the system when you pass AddressOf EnumFontFamProc to EnumFontFamilies. The last argument passed to EnumFontFamilies specifies the list box in which the information is displayed.

'Font enumeration types
Public Const LF_FACESIZE = 32
Public Const LF_FULLFACESIZE = 64

Type LOGFONT
        lfHeight As Long
        lfWidth As Long
        lfEscapement As Long
        lfOrientation As Long
        lfWeight As Long
        lfItalic As Byte
        lfUnderline As Byte
        lfStrikeOut As Byte
        lfCharSet As Byte
        lfOutPrecision As Byte
        lfClipPrecision As Byte
        lfQuality As Byte
        lfPitchAndFamily As Byte

        lfFaceName(LF_FACESIZE) As Byte
End Type

Type NEWTEXTMETRIC
        tmHeight As Long
        tmAscent As Long
        tmDescent As Long
        tmInternalLeading As Long
        tmExternalLeading As Long
        tmAveCharWidth As Long
        tmMaxCharWidth As Long
        tmWeight As Long
        tmOverhang As Long
        tmDigitizedAspectX As Long
        tmDigitizedAspectY As Long
        tmFirstChar As Byte
        tmLastChar As Byte
        tmDefaultChar As Byte

        tmBreakChar As Byte
        tmItalic As Byte
        tmUnderlined As Byte
        tmStruckOut As Byte
        tmPitchAndFamily As Byte
        tmCharSet As Byte
        ntmFlags As Long
        ntmSizeEM As Long
        ntmCellHeight As Long
        ntmAveWidth As Long
End Type

' ntmFlags field flags
Public Const NTM_REGULAR = &H40&
Public Const NTM_BOLD = &H20&
Public Const NTM_ITALIC = &H1&

'  tmPitchAndFamily flags
Public Const TMPF_FIXED_PITCH = &H1

Public Const TMPF_VECTOR = &H2
Public Const TMPF_DEVICE = &H8
Public Const TMPF_TRUETYPE = &H4

Public Const ELF_VERSION = 0
Public Const ELF_CULTURE_LATIN = 0

'  EnumFonts Masks
Public Const RASTER_FONTTYPE = &H1
Public Const DEVICE_FONTTYPE = &H2
Public Const TRUETYPE_FONTTYPE = &H4

Private Declare Function EnumFontFamilies Lib "gdi32" Alias _
   "EnumFontFamiliesA" _
   (ByVal hDC As Long, ByVal lpszFamily As String, _
   ByVal lpEnumFontFamProc As Long, lParam As Any) As Long

Private Declare Function GetDC Lib "user32" (ByVal hWnd As Long) As Long
Private Declare Function ReleaseDC Lib "user32" (ByVal hWnd As Long, _
   ByVal hDC As Long) As Long


'------------------------------
Function EnumFontFamProcLB(lpNLF As LOGFONT, lpNTM As NEWTEXTMETRIC, _
         ByVal FontType As Long, lParam As ListBox) As Long
  ' callback from Windows to fill ListBox with Facenames
  Dim FaceName As String
  
  ' only want TrueType fonts for Ge
  If FontType And TRUETYPE_FONTTYPE Then
    FaceName = StrConv(lpNLF.lfFaceName, vbUnicode)
    lParam.AddItem Left$(FaceName, InStr(FaceName, vbNullChar) - 1)
  End If
  EnumFontFamProcLB = 1
End Function
'------------------------------
Public Sub FillListBoxWithFonts(LB As ListBox)
  Dim hDC As Long
  
  LB.Clear
  hDC = GetDC(LB.hWnd)
  EnumFontFamilies hDC, vbNullString, AddressOf EnumFontFamProcLB, LB
  ReleaseDC LB.hWnd, hDC
End Sub

'------------------------------
Function EnumFontFamProcCB(lpNLF As LOGFONT, lpNTM As NEWTEXTMETRIC, _
         ByVal FontType As Long, lParam As ComboBox) As Long
  ' callback from Windows to fill ComboBox with Facenames
  Dim FaceName As String
'  Dim FullName As String
  
  ' only want TrueType fonts for Ge
  If FontType And TRUETYPE_FONTTYPE Then
    FaceName = StrConv(lpNLF.lfFaceName, vbUnicode)
    lParam.AddItem Left$(FaceName, InStr(FaceName, vbNullChar) - 1)
  End If
  EnumFontFamProcCB = 1
End Function
'------------------------------
Public Sub FillComboBoxWithFonts(CB As ComboBox)
  Dim hDC As Long
  
  CB.Clear
  hDC = GetDC(CB.hWnd)
  EnumFontFamilies hDC, vbNullString, AddressOf EnumFontFamProcCB, CB
  ReleaseDC CB.hWnd, hDC
End Sub


