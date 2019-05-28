Attribute VB_Name = "mPrinter"
'======================================================================================
'
' Module:   mPrinter - code to interface to COMDLG32.DLL Printer Dialog
' Updated:                By
'
'--------------------------------------------------------------------------------------
'======================================================================================

Option Explicit

'=====================================================================
' Start Declarations
'=====================================================================

' Global constants for Win32 API
Public Const CCHDEVICENAME = 32
Public Const CCHFORMNAME = 32
Public Const GMEM_FIXED = &H0
Public Const GMEM_MOVEABLE = &H2
Public Const GMEM_ZEROINIT = &H40

  ' masks for devMode.dmFields -
  'A set of bit flags that specify whether certain members of
  'the DEVMODE structure have been initialized. If a field is initialized,
  'its corresponding bit flag is set, otherwise the bit flag is clear.
  'A printer driver supports only those DEVMODE structure members that
  'are appropriate for the printer technology.
Public Const DM_DUPLEX = &H1000&
Public Const DM_ORIENTATION = &H1&
Public Const DM_PAPERSIZE = &H2&      ' papersize


Public Const PD_ALLPAGES = &H0
Public Const PD_COLLATE = &H10
Public Const PD_DISABLEPRINTTOFILE = &H80000
Public Const PD_ENABLEPRINTHOOK = &H1000
Public Const PD_ENABLEPRINTTEMPLATE = &H4000
Public Const PD_ENABLEPRINTTEMPLATEHANDLE = &H10000
Public Const PD_ENABLESETUPHOOK = &H2000
Public Const PD_ENABLESETUPTEMPLATE = &H8000
Public Const PD_ENABLESETUPTEMPLATEHANDLE = &H20000
Public Const PD_HIDEPRINTTOFILE = &H100000
Public Const PD_NONETWORKBUTTON = &H200000
Public Const PD_NOPAGENUMS = &H8
Public Const PD_NOSELECTION = &H4
Public Const PD_NOWARNING = &H80
Public Const PD_PAGENUMS = &H2
Public Const PD_PRINTSETUP = &H40
Public Const PD_PRINTTOFILE = &H20
Public Const PD_RETURNDC = &H100
Public Const PD_RETURNDEFAULT = &H400
Public Const PD_RETURNIC = &H200
Public Const PD_SELECTION = &H1
Public Const PD_SHOWHELP = &H800
Public Const PD_USEDEVMODECOPIES = &H40000
Public Const PD_USEDEVMODECOPIESANDCOLLATE = &H40000

'Custom Global Constants
Public Const DLG_PRINT = 0
Public Const DLG_PRINTSETUP = 1

'type definitions:
Type PRINTDLG_TYPE
        lStructSize As Long
        hwndOwner As Long
        hDevMode As Long
        hDevNames As Long
        hDC As Long
        FLAGS As Long
        nFromPage As Integer
        nToPage As Integer
        nMinPage As Integer
        nMaxPage As Integer
        nCopies As Integer
        hInstance As Long
        lCustData As Long
        lpfnPrintHook As Long

        lpfnSetupHook As Long
        lpPrintTemplateName As String
        lpSetupTemplateName As String
        hPrintTemplate As Long
        hSetupTemplate As Long
End Type

Type DEVNAMES_TYPE
        wDriverOffset As Integer
        wDeviceOffset As Integer
        wOutputOffset As Integer
        wDefault As Integer
        extra As String * 100
End Type

Type DEVMODE_TYPE
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

'API declarations:
Public Declare Function PrintDialog Lib "comdlg32.dll" _
   Alias "PrintDlgA" (pPrintdlg As PRINTDLG_TYPE) As Long

Public Declare Sub CopyMemory Lib "Kernel32" _
   Alias "RtlMoveMemory" _
   (hpvDest As Any, hpvSource As Any, ByVal cbCopy As Long)

Public Declare Function GlobalLock Lib "Kernel32" _
   (ByVal hMem As Long) As Long

Public Declare Function GlobalUnlock Lib "Kernel32" _
   (ByVal hMem As Long) As Long

Public Declare Function GlobalAlloc Lib "Kernel32" _
   (ByVal wFlags As Long, ByVal dwBytes As Long) As Long

Public Declare Function GlobalFree Lib "Kernel32" _
   (ByVal hMem As Long) As Long
 

'=====================================================================
' End Declarations
'=====================================================================

'Public Function ShowPrinter(frmOwner As Form, _
' object could be form or UserCOntrol

Public Function ShowPrinter(frmOwner As Form, _
                    Optional PrintFlags As Integer, _
                    Optional FromPage As Integer, _
                    Optional ToPage As Integer, _
                    Optional hwndOwner As Long _
          ) As Boolean
  ' show ComCtl32.dll dialog
  Dim PrintDlg As PRINTDLG_TYPE
  Dim devMode As DEVMODE_TYPE
  Dim DevName As DEVNAMES_TYPE
  
  Dim lpDevMode As Long, lpDevName As Long
  Dim bReturn As Integer
  Dim objPrinter As Printer, NewPrinterName As String
  Dim strSetting As String

    ' Use PrintDialog to get the handle to a memory
    ' block with a DevMode and DevName structures
  On Error Resume Next
  ShowPrinter = False
  If Printer Is Nothing Then Exit Function
  
  PrintDlg.lStructSize = Len(PrintDlg)
    ' get handle to owner
  
  If Not frmOwner Is Nothing Then
    PrintDlg.hwndOwner = frmOwner.hWnd
  ElseIf Not (hwndOwner = 0) Then
    PrintDlg.hwndOwner = hwndOwner
  Else
    ' someone does not know how to use this fcn. Leave!
    Exit Function
  End If
  If Err <> 0 Then Exit Function
  
  '
  If PrintFlags And PD_PAGENUMS Then
    If FromPage > 0 Then
      PrintDlg.nFromPage = FromPage
        PrintDlg.nMinPage = FromPage
      If ToPage > 0 And (ToPage > FromPage) Then
        PrintDlg.nToPage = ToPage
        PrintDlg.nMaxPage = ToPage
      End If
    End If
  End If
  '
  PrintDlg.FLAGS = PrintFlags


    'Set the current orientation and duplex setting
  devMode.dmDeviceName = Printer.DeviceName
  devMode.dmSize = Len(devMode)
  ' set masks to enable values
  devMode.dmFields = DM_ORIENTATION Or DM_DUPLEX Or DM_PAPERSIZE
  '
  devMode.dmOrientation = Printer.Orientation
  devMode.dmDuplex = Printer.Duplex
  devMode.dmPaperSize = Printer.PaperSize

    'Allocate memory for the initialization hDevMode structure
    'and copy the settings gathered above into this memory
  PrintDlg.hDevMode = GlobalAlloc(GMEM_MOVEABLE Or _
     GMEM_ZEROINIT, Len(devMode))
  lpDevMode = GlobalLock(PrintDlg.hDevMode)
  If lpDevMode > 0 Then
      CopyMemory ByVal lpDevMode, devMode, Len(devMode)
      bReturn = GlobalUnlock(lpDevMode)
  End If
  
  If Err <> 0 Then Exit Function
  
    'Set the current driver, device, and port name strings
  With DevName
      .wDriverOffset = 8
      .wDeviceOffset = .wDriverOffset + 1 + Len(Printer.DriverName)
      .wOutputOffset = .wDeviceOffset + 1 + Len(Printer.Port)
      .wDefault = 0
  End With
  With Printer
      DevName.extra = .DriverName & Chr(0) & _
      .DeviceName & Chr(0) & .Port & Chr(0)
  End With

    'Allocate memory for the initial hDevName structure
    'and copy the settings gathered above into this memory
  PrintDlg.hDevNames = GlobalAlloc(GMEM_MOVEABLE Or _
                        GMEM_ZEROINIT, Len(DevName))
  lpDevName = GlobalLock(PrintDlg.hDevNames)
  If lpDevName > 0 Then
      CopyMemory ByVal lpDevName, DevName, Len(DevName)
      bReturn = GlobalUnlock(lpDevName)
  End If
  If Err <> 0 Then Exit Function

    'Call the print dialog up and let the user make changes
  If PrintDialog(PrintDlg) Then
        'First get the DevName structure.
      lpDevName = GlobalLock(PrintDlg.hDevNames)
      CopyMemory DevName, ByVal lpDevName, 45
      bReturn = GlobalUnlock(lpDevName)
      GlobalFree PrintDlg.hDevNames
  
        'Next get the DevMode structure and set the printer
        'properties appropriately
      lpDevMode = GlobalLock(PrintDlg.hDevMode)
      CopyMemory devMode, ByVal lpDevMode, Len(devMode)
      bReturn = GlobalUnlock(PrintDlg.hDevMode)
      GlobalFree PrintDlg.hDevMode
        ' get Page nums
      If PrintFlags And PD_PAGENUMS Then
        FromPage = PrintDlg.nFromPage
        ToPage = PrintDlg.nToPage
      End If
      '
      NewPrinterName = UCase$(Left(devMode.dmDeviceName, _
                        InStr(devMode.dmDeviceName, Chr$(0)) - 1))
      If Printer.DeviceName <> NewPrinterName Then
          
          ' must force to not check longer than CCHDEVICENAME
          Dim strTmp As String
          For Each objPrinter In Printers
            strTmp = Left(objPrinter.DeviceName, CCHDEVICENAME - 1)
             If UCase$(strTmp) = NewPrinterName Then
                  Set Printer = objPrinter
             End If
          Next
      
      End If
      If Err <> 0 Then Exit Function
      ShowPrinter = True
  
      'Set printer object properties according to selections made
      'by user
      With Printer
          .PaperSize = devMode.dmPaperSize
          .Copies = devMode.dmCopies
          .Duplex = devMode.dmDuplex
          .Orientation = devMode.dmOrientation
      End With
  End If


#If 0 Then
    'Display the results in the immediate (debug) window
    With Printer
        If .Orientation = 1 Then
            strSetting = "Portrait. "
        Else
            strSetting = "Landscape. "
        End If
        Debug.Print "Copies = " & .Copies, "Orientation = " & _
           strSetting & " PaperSize = " & .PaperSize
    End With
#End If

End Function
 


