Attribute VB_Name = "mGlobalConstants"
Option Explicit

'Global for Message Window
'Global gMsgWnd As ucMessageWindow
'Global custom drawing UDIDefMgr reference
'Global g_DrawingDefMgr As UDIDefMgr

'=====================================================================
' Global Constant Definition for Message Box Windows
'=====================================================================
Global Const MB_OK = 0, MB_OKCANCEL = 1, MB_ABORTRETRYIGNORE = 2
Global Const MB_YESNOCANCEL = 3, MB_YESNO = 4, MB_RETRYCANCEL = 5
Global Const MB_ICONSTOP = 16, MB_ICONQUESTION = 32
Global Const MB_ICONEXCLAMATION = 48, MB_ICONINFORMATION = 64
Global Const IDOK = 1, IDCANCEL = 2, IDABORT = 3, IDRETRY = 4
Global Const MB_DEFBUTTON2 = 256, IDIGNORE = 5, IDYES = 6, IDNO = 7

'=====================================================================
' Intrinsic Windows constants
'=====================================================================
Global Const A_WINDOW = 4
Global Const A_HIDE = 3
Global Const WM_USER = &H400

'=====================================================================
'ListBox Interface
'=====================================================================
Global Const LB_GETITEMHEIGHT = &H1A1
Global Const LB_SETTABSTOPS = &H192
Global Const LOGPIXELSX = 88    '  Logical pixels/inch in X
Global Const LOGPIXELSY = 90    '  Logical pixels/inch in Y

Const CCHDEVICENAME = 32
Const CCHFORMNAME = 32
Type devMode
  dmDeviceName As String * CCHDEVICENAME
  dmSpecVersion As Integer
  dmDriverVersion As Integer
  dmSize As Integer
  dmDriverExtra As Integer
  dmFields As Long
  dmOrientation As Integer
  dmPaperSize As Integer
  dmPaperLength As Integer
  dmPaperWidth As Integer
  dmScale As Integer
  dmCopies As Integer
  dmDefaultSource As Integer
  dmPrintQuality As Integer
  dmColor As Integer
  dmDuplex As Integer
  dmYResolution As Integer
  dmTTOption As Integer
  dmCollate As Integer
  dmFormName As String * CCHFORMNAME
  dmUnusedPadding As Integer
  dmBitsPerPel As Integer
  dmPelsWidth As Long
  dmPelsHeight As Long
  dmDisplayFlags As Long
  dmDisplayFrequency As Long
End Type

Declare Function GetDialogBaseUnits Lib "user32" () As Long
Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, lParam As Long) As Long
Declare Function SendMessageStr Lib "user32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As String) As Long

Declare Function CreateIC Lib "gdi32" Alias "CreateICA" (ByVal lpDriverName As String, ByVal lpDeviceName As String, ByVal lpOutput As String, lpInitData As devMode) As Long
Declare Function GetDeviceCaps Lib "gdi32" (ByVal hDC As Long, ByVal nIndex As Long) As Long
Declare Function DeleteDC Lib "gdi32" (ByVal hDC As Long) As Long

Declare Function SaveDC Lib "gdi32" (ByVal hDC As Long) As Long
Declare Function RestoreDC Lib "gdi32" (ByVal hDC As Long, ByVal nSavedDC As Long) As Long
  
' File Access
' Constants with OpenFile API call.
Global Const OF_WRITE = &H1
Global Const OF_READ = &H0
Global Const OF_CREATE = &H1000

' Structure filled in by OpenFile API call.
Public Type OFSTRUCT
        cBytes As Byte
        fFixedDisk As Byte
        nErrCode As Integer
        Reserved1 As Integer
        Reserved2 As Integer
        szPathName(128) As Byte
End Type

' declarations for the API functions that this class uses.
Declare Function OpenFile Lib "Kernel32" _
    (ByVal lpFileName As String, _
     lpReOpenBuff As OFSTRUCT, _
     ByVal wStyle As Long) As Long

Declare Function hread Lib "Kernel32" Alias "_hread" _
    (ByVal hFile As Long, lpBuffer As Any, ByVal lBytes As Long) As Long

Declare Function hwrite Lib "Kernel32" Alias "_hwrite" _
    (ByVal hFile As Long, ByVal lpBuffer As String, ByVal lBytes As Long) As Long

Declare Function hwriteByteArray Lib "Kernel32" Alias "_hwrite" _
    (ByVal hFile As Long, ByRef lpBuffer As Byte, ByVal lBytes As Long) As Long

Declare Function lclose Lib "Kernel32" Alias "_lclose" _
    (ByVal hFile As Long) As Long

' Declarations for Menu Functions
Declare Function GetMenu Lib "user32" (ByVal hWnd As Long) As Long
Declare Function SetMenu Lib "user32" (ByVal hWnd As Long, ByVal hMenu As Long) As Boolean
Declare Function GetLastError Lib "Kernel32" () As Long
' Millisecond time and time related from Windows
Declare Function timeGetTime Lib "winmm.dll" () As Long
Declare Function Sleep Lib "kernel32.dll" (ByVal dwMillisecond As Long)

' Constants for setting a Form to be TopMost Window Always
Global Const SWP_NOMOVE = 2
Global Const SWP_NOSIZE = 1
Global Const TOPWND_FLAGS = SWP_NOMOVE Or SWP_NOSIZE
Global Const HWND_TOP = 0
Global Const HWND_BOTTOM = 1
Global Const HWND_TOPMOST = -1
Global Const HWND_NOTOPMOST = -2

'/*
' * SetWindowPos Flags
' */
'Global Const SWP_NOSIZE = &H1
'Global Const SWP_NOMOVE = &H2
Global Const SWP_NOZORDER = &H4
Global Const SWP_NOREDRAW = &H8
Global Const SWP_NOACTIVATE = &H10
Global Const SWP_FRAMECHANGED = &H20        '/* The frame changed: send WM_NCCALCSIZE */
Global Const SWP_SHOWWINDOW = &H40
Global Const SWP_HIDEWINDOW = &H80
Global Const SWP_NOCOPYBITS = &H100
Global Const SWP_NOOWNERZORDER = &H200     ' /* Don't do owner Z ordering */
Global Const SWP_NOSENDCHANGING = &H400     '/* Don't send WM_WINDOWPOSCHANGING */

'#define SWP_DRAWFRAME       SWP_FRAMECHANGED
'#define SWP_NOREPOSITION    SWP_NOOWNERZORDER

' File Seaching
Public Const MAX_PATH = 260

Type FILETIME
        dwLowDateTime As Long
        dwHighDateTime As Long
End Type

Type WIN32_FIND_DATA
        dwFileAttributes As Long
        ftCreationTime As FILETIME
        ftLastAccessTime As FILETIME
        ftLastWriteTime As FILETIME
        nFileSizeHigh As Long
        nFileSizeLow As Long
        dwReserved0 As Long
        dwReserved1 As Long
        cFileName As String * MAX_PATH
        cAlternate As String * 14
End Type
Declare Function FindFirstFile Lib "Kernel32" Alias "FindFirstFileA" (ByVal lpFileName As String, lpFindFileData As WIN32_FIND_DATA) As Long
Declare Function FindNextFile Lib "Kernel32" Alias "FindNextFileA" (ByVal hFindFile As Long, lpFindFileData As WIN32_FIND_DATA) As Long


'=====================================================================
'Windows Messages
'=====================================================================
Global Const WM_SETREDRAW As Integer = &HB   '  0x000B

'
'=====================================================================
'INI file interface
'=====================================================================
Declare Function GetWindowsDirectory Lib "Kernel32" Alias "GetWindowsDirectoryA" (ByVal lpBuffer As String, ByVal nSize As Long) As Long
Declare Function GetPrivateProfileString Lib "Kernel32" Alias "GetPrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpDefault As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
Declare Function WritePrivateProfileString Lib "Kernel32" Alias "WritePrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpString As Any, ByVal lpFileName As String) As Long
Declare Function GetPrivateProfileInt Lib "Kernel32" Alias "GetPrivateProfileIntA" (ByVal lpApplicationName As String, ByVal lpKeyName As String, ByVal nDefault As Long, ByVal lpFileName As String) As Long


'=====================================================================
' Common Dialog Interface
'=====================================================================
Global Const OFN_READONLY = &H1
Global Const OFN_OVERWRITEPROMPT = &H2
Global Const OFN_HIDEREADONLY = &H4
Global Const OFN_NOCHANGEDIR = &H8
Global Const OFN_SHOWHELP = &H10
Global Const OFN_ENABLEHOOK = &H20
Global Const OFN_ENABLETEMPLATE = &H40
Global Const OFN_ENABLETEMPLATEHANDLE = &H80
Global Const OFN_NOVALIDATE = &H100
Global Const OFN_ALLOWMULTISELECT = &H200
Global Const OFN_EXTENSIONDIFFERENT = &H400
Global Const OFN_PATHMUSTEXIST = &H800
Global Const OFN_FILEMUSTEXIST = &H1000
Global Const OFN_CREATEPROMPT = &H2000
Global Const OFN_SHAREAWARE = &H4000
Global Const OFN_NOREADONLYRETURN = &H8000
Global Const OFN_NOTESTFILECREATE = &H10000

Type dlg_GETFILENAMEINFO
  hwndOwner As Long
  szFilter As String * 255
  szCustomFilter As String * 255
  nFilterIndex As Long
  szFile As String * 255
  szFileTitle As String * 255
  szInitialDir As String * 255
  szTitle As String * 255
  FLAGS As Long
  nFileOffset As Integer
  nFileExtension As Integer
  szDefExt As String * 255
End Type

  Declare Function GetActiveWindow Lib "user32" () As Long
  Declare Function GetTempPath Lib "Kernel32" Alias "GetTempPathA" (ByVal nBufferLength As Long, ByVal lpBuffer As String) As Long
  Declare Function GetTempFileName Lib "Kernel32" Alias "GetTempFileNameA" (ByVal lpszPath As String, ByVal lpPrefixString As String, ByVal wUnique As Long, ByVal lpTempFileName As String) As Long
  Declare Function SetWindowPos Lib "user32" (ByVal hWnd As Long, ByVal hWndInsertAfter As Long, ByVal X As Long, ByVal Y As Long, ByVal CX As Long, ByVal CY As Long, ByVal wFlags As Long) As Long
  Declare Function BringWindowToTop Lib "user32" (ByVal hWnd As Long) As Long

'=====================================================================
' Range Constants
'=====================================================================
Global Const INT_MIN = -32767  ' Integer
Global Const INT_MAX = 32767
Global Const LONG_MIN = -32767  ' Long
Global Const LONG_MAX = 32767

'=====================================================================
' Misc
'=====================================================================
Global Const DASH_DELIMETER = "-"
Global Const COLON_DELIMETER = ";"
Global Const MAX_SORTORDERLOOPS = 25
Global Const MAIN_FORM_NAME = "Form1"
'=====================================================================
' Palette related TypeDefs and Functions
'=====================================================================
Type PALETTEENTRY
        peRed As Byte
        peGreen As Byte
        peBlue As Byte
        peFlags As Byte
End Type

'
' the PAL file header
'
Type LOGPALETTE
        palVersion As Integer
        palNumEntries As Integer
        palPalEntry(0) As PALETTEENTRY    ' 1 member only
End Type


' NOTE: Returns number of entries set ( 0 = error)
Declare Function SetPaletteEntries Lib "gdi32" (ByVal hPalette As Long, _
        ByVal wStartIndex As Long, ByVal wNumEntries As Long, _
        lpPaletteEntries As PALETTEENTRY) As Long
        
' NOTE: Returns number of entries got ( 0 = error)
Declare Function GetPaletteEntries Lib "gdi32" (ByVal hPalette As Long, _
        ByVal wStartIndex As Long, ByVal wNumEntries As Long, _
        lpPaletteEntries As PALETTEENTRY) As Long
        

'
' System Error handling and reporting
'
Declare Function FormatMessage Lib "Kernel32" Alias "FormatMessageA" (ByVal dwFlags As Long, _
                      lpSource As Any, ByVal dwMessageId As Long, _
                      ByVal dwLanguageId As Long, ByVal lpBuffer As String, _
                      ByVal nSize As Long, Arguments As Long) As Long


'=====================================================================
' User Information from System
'=====================================================================
' Get currently logged on username from system
Declare Function GetUserName Lib "advapi32.dll" Alias "GetUserNameA" ( _
                        ByVal lpBuffer As String, nSize As Long) As Long

' Get current computername from system
Declare Function GetComputerName Lib "Kernel32" Alias "GetComputerNameA" (ByVal sBuffer As String, lSize As Long) As Long

'=====================================================================
' Cursor (mouse) moving
'=====================================================================
Type POINTAPI
    X As Long
    Y As Long
End Type

Declare Function GetCursorPos Lib "user32" (lpPoint As POINTAPI) As Long
Declare Function SetCursorPos Lib "user32" (ByVal X As Long, ByVal Y As Long) As Long


