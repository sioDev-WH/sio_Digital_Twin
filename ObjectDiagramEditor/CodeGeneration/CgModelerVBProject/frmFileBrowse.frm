VERSION 5.00
Object = "{E6F77CB3-6A30-11D5-89E6-00D0B74A80C3}#1.0#0"; "CGCTRL.OCX"
Begin VB.Form frmFileBrowse 
   Caption         =   "File Browser"
   ClientHeight    =   5760
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   9810
   Icon            =   "frmFileBrowse.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MinButton       =   0   'False
   ScaleHeight     =   5760
   ScaleWidth      =   9810
   StartUpPosition =   2  'CenterScreen
   Begin CGCtrlLib.CG Ge1 
      Height          =   4335
      Left            =   4260
      TabIndex        =   16
      Top             =   1320
      Width           =   5355
      _Version        =   65536
      _ExtentX        =   9446
      _ExtentY        =   7646
      _StockProps     =   64
   End
   Begin VB.PictureBox picFiles 
      BorderStyle     =   0  'None
      Height          =   2925
      Left            =   90
      ScaleHeight     =   2925
      ScaleWidth      =   3855
      TabIndex        =   13
      Top             =   2790
      Width           =   3855
      Begin VB.FileListBox File1 
         Height          =   2625
         Left            =   0
         MultiSelect     =   2  'Extended
         Pattern         =   "*.gef"
         TabIndex        =   14
         Top             =   0
         Width           =   3855
      End
      Begin VB.Label lblNumSel 
         Alignment       =   2  'Center
         Caption         =   "0 of 0 Files selected"
         Height          =   195
         Left            =   15
         TabIndex        =   15
         Top             =   2700
         Width           =   3840
      End
   End
   Begin VB.CheckBox chkColourPrint 
      Caption         =   "Colour Printer"
      Height          =   195
      Left            =   6600
      TabIndex        =   8
      ToolTipText     =   "if checked, drawing(s) will be printed in colour"
      Top             =   555
      Width           =   1305
   End
   Begin VB.CommandButton btnPrint 
      Caption         =   "Print..."
      Height          =   325
      Left            =   6585
      TabIndex        =   7
      ToolTipText     =   "Print the selected file(s)"
      Top             =   135
      Width           =   1035
   End
   Begin VB.CommandButton btnCancel 
      Caption         =   "Cancel"
      Height          =   325
      Left            =   8385
      TabIndex        =   3
      Top             =   555
      Width           =   1035
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "Open"
      Height          =   325
      Left            =   8385
      TabIndex        =   2
      ToolTipText     =   "Open the drawing"
      Top             =   135
      Width           =   1035
   End
   Begin VB.DriveListBox Drive1 
      Height          =   315
      Left            =   105
      TabIndex        =   1
      Top             =   60
      Width           =   3840
   End
   Begin VB.DirListBox Dir1 
      Height          =   2340
      Left            =   105
      TabIndex        =   0
      Top             =   420
      Width           =   3840
   End
   Begin VB.Label Label4 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "Orientation:"
      Height          =   195
      Left            =   3990
      TabIndex        =   12
      ToolTipText     =   "preview of the drawing"
      Top             =   5925
      Visible         =   0   'False
      Width           =   810
   End
   Begin VB.Label Label3 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "Paper size:"
      Height          =   195
      Left            =   4020
      TabIndex        =   11
      ToolTipText     =   "preview of the drawing"
      Top             =   5700
      Visible         =   0   'False
      Width           =   780
   End
   Begin VB.Label lblSelDrawingOrient 
      Caption         =   "Portrait"
      Height          =   195
      Left            =   4890
      TabIndex        =   10
      ToolTipText     =   "preview of the drawing"
      Top             =   5925
      Visible         =   0   'False
      Width           =   1905
   End
   Begin VB.Label lblSelDrawingSize 
      Caption         =   "A   (8.5 X 11)"
      Height          =   195
      Left            =   4890
      TabIndex        =   9
      ToolTipText     =   "preview of the drawing"
      Top             =   5700
      Visible         =   0   'False
      Width           =   1920
   End
   Begin VB.Label Label2 
      Caption         =   "Folder"
      Height          =   210
      Left            =   4005
      TabIndex        =   6
      Top             =   465
      Width           =   525
   End
   Begin VB.Label Label1 
      Caption         =   "Drive"
      Height          =   210
      Left            =   4005
      TabIndex        =   5
      Top             =   90
      Width           =   525
   End
   Begin VB.Label lblSelFile 
      Caption         =   "Preview: Filename"
      Height          =   195
      Left            =   4230
      TabIndex        =   4
      ToolTipText     =   "preview of the drawing"
      Top             =   1050
      Width           =   5370
   End
End
Attribute VB_Name = "frmFileBrowse"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
' frmCmdLine
'======================================================================================
Option Explicit
'
'========================================================
'
Private m_strFileName As String
Private m_bCancelled As Boolean

Private m_bAbort As Boolean
Private m_bPrinting As Boolean

' minimum allowed form size
Private Const c_minWidth As Long = 9930
Private Const c_minHeight As Long = 6180

' layers
Private m_LayerDefs As New LayerDefinitions

'========================================================
'------------------------------
Public Property Let FileName(ByVal strVal As String)
  m_strFileName = strVal
End Property
Public Property Get FileName() As String
  FileName = m_strFileName
End Property
'------------------------------
Public Property Get Cancelled() As Boolean
  Cancelled = m_bCancelled
End Property
'------------------------------
Private Sub btnCancel_Click()
  If m_bPrinting Then
    m_bAbort = True
  Else
    m_bCancelled = True
    Unload Me
  End If
End Sub

'------------------------------
Private Sub btnOK_Click()
  On Error Resume Next
  m_bCancelled = False
  If Len(m_strFileName) > 0 Then RecentFile = m_strFileName   ' write to INI
  Unload Me
End Sub
'------------------------------
Private Sub EnableUI(ByVal bEnable As Boolean)
  ' user input
  btnOK.Enabled = bEnable
  btnCancel.Enabled = bEnable ' cancel
  Drive1.Enabled = bEnable
  Dir1.Enabled = bEnable
  File1.Enabled = bEnable
  btnPrint.Enabled = bEnable
  chkColourPrint.Enabled = bEnable
End Sub

'------------------------------
Private Sub btnPrint_Click()
  EnableUI False
  m_bPrinting = True
  m_bAbort = False
  PrintSelFiles
  m_bPrinting = False
  m_bAbort = False
  EnableUI True
End Sub

'------------------------------
Private Sub Form_Activate()
  Static bFirst As Boolean
  Dim strFile As String
  
  On Error Resume Next
  If Not bFirst Then
    bFirst = True
    '
    File1.Pattern = "*.CGF"
    '
    If Len(m_strFileName) > 0 Then
      strFile = m_strFileName
    Else
      strFile = RecentFile  ' get from INI
    End If
    '
    If Len(strFile) > 0 Then
      strFile = StripFile(strFile)
      Drive1.Drive = strFile
      Dir1.Path = strFile
    End If
    File1_Click   ' force a call to update file count status
    
    ' init
    ClearGe
    
    ' print colour
    Dim iVal As Integer
    iVal = ColourPrintInINI
    If iVal <> 0 Then iVal = 1
    chkColourPrint.Value = iVal
  End If
End Sub

'------------------------------
Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
  Dim strName As String
  On Error Resume Next
  If KeyCode = vbKeyReturn Then
    If Not m_bPrinting Then
      strName = Screen.ActiveControl.Name
      If strName = "Drive1" Or strName = "Dir1" Then
        ' do nothing
      ElseIf strName = "File1" Then
        ' do file open
        KeyCode = 0
        btnOK_Click
      Else
        KeyCode = 0
        btnOK_Click
      End If
    End If
  ElseIf KeyCode = vbKeyEscape Then
    KeyCode = 0:    btnCancel_Click
  End If
End Sub

'------------------------------
Private Sub Form_Load()
  m_bCancelled = True
End Sub

'------------------------------
Private Sub Form_Resize()
  On Error Resume Next
  Dim dwt As Long, dht As Long
  Dim bmove As Boolean
  
  ' block making smaller that design size
  ' also, move me back onto screen if need to force a resize,
  ' which could happen if form is shrunk from top resulting in bottom
  ' going off screen
  If Me.Width < c_minWidth Then
    Me.Width = c_minWidth
    bmove = True
  End If
  If Me.Height < c_minHeight Then
    Me.Height = c_minHeight
    bmove = True
  End If
  
  dwt = Me.ScaleWidth - (lblSelFile.Left) - 90
  dht = Me.ScaleHeight - (lblSelFile.Top + lblSelFile.Height + 60) - 90
  If dwt < 1000 Then dwt = 1000
  If dht < 1000 Then dht = 1000
  
  Ge1.Move lblSelFile.Left, lblSelFile.Top + lblSelFile.Height + 60, dwt, dht
  Ge1.ZoomPage
  
  ' files listbox
  dht = Me.ScaleHeight - picFiles.Top - 60
  If dht < 2925 Then dht = 2925
  picFiles.Move picFiles.Left, picFiles.Top, picFiles.Width, dht

  '
  If bmove Then Me.Move 2000, 2000

End Sub

'------------------------------
Private Sub picFiles_Resize()
  On Error Resume Next
  lblNumSel.Move 0, picFiles.Height - lblNumSel.Height - 30
  File1.Move 0, 0, picFiles.Width, picFiles.Height - lblNumSel.Height - 30
End Sub

'------------------------------
Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
  On Error Resume Next
  Ge1.InitNew
  Set m_LayerDefs = Nothing
  ColourPrintInINI = chkColourPrint.Value
  ClearGe
End Sub

'------------------------------
Private Sub Dir1_Click()
  Dim strpath As String
  On Error Resume Next
  With Dir1
    If .ListIndex > -1 Then
      strpath = .List(.ListIndex) ' grab selected
    Else
      ' if listindex < 0, has path when going back up a dir-tree
      strpath = .List(.ListIndex) ' grab selected
    End If
  End With
  '
  If Len(strpath) > 0 Then
    File1.Path = strpath
  End If
End Sub
'------------------------------
Private Sub Dir1_Change()
  Dim strpath As String
  On Error Resume Next
  strpath = Dir1.Path
  ' don't do again if already in has the path, as is case with Dir1_Click
  If strpath <> File1.Path Then
    File1.Path = strpath
  End If
End Sub
'------------------------------
Private Sub Drive1_Change()
  Dim strDrive As String
  On Error Resume Next
  strDrive = Drive1.Drive
  Dir1.Path = strDrive
End Sub

'------------------------------
Private Sub UpdateNumSel(ByVal nSel As Integer, ByVal nTotal As Integer)
  ' update count of selected
  lblNumSel.Caption = nSel & " of " & nTotal & " Files selected"
  btnPrint.Enabled = IIf(nSel > 0, True, False)
End Sub

'------------------------------
Private Sub File1_Click()
  Dim strFile As String, strpath As String
  Dim i As Long, nSel As Long, nTotal As Long
  
  On Error Resume Next
  With File1
    nTotal = .ListCount
    For i = 0 To .ListCount - 1
      If .Selected(i) Then
        If Len(strFile) = 0 Then strFile = .List(i) ' grab 1st in list
        nSel = nSel + 1
      End If
    Next i
    ' get currently selected one
    If .ListIndex > -1 Then
      If .Selected(.ListIndex) Then strFile = .List(.ListIndex)
    End If
  End With
  '
  If nSel > 0 Then
    strpath = File1.Path & "\" & strFile
    m_strFileName = strpath
    ShowGeFile strpath
  Else
    ClearGe
  End If
  '
  UpdateNumSel nSel, nTotal
End Sub
'------------------------------
Private Sub File1_DblClick()
  If Len(m_strFileName) > 0 Then btnOK_Click
End Sub
Private Sub File1_PathChange()
  ClearGe
  File1_Click
End Sub
Private Sub File1_PatternChange()
  ClearGe
  File1_Click
End Sub

'==================================================================
' Printing
'==================================================================
'------------------------------
Private Sub PrintSelFiles()
  ' print all selected
  Dim strFile As String, strpath As String
  Dim i As Long, nSel As Long
  Dim bFailed As Boolean, bRet As Boolean
  
  On Error Resume Next
  If Printer Is Nothing Then Exit Sub
  If Not DoPrintSetup Then Exit Sub
  
  ' TODO - take a look at Printer.Fonts for downloading softfonts, etc...
  '
  BeginWaitCursor
  With File1
    For i = 0 To .ListCount - 1
      If .Selected(i) Then
        strFile = .List(i)
        strpath = File1.Path & "\" & strFile
        ' print it
        bRet = PrintFile(strpath)
        DoEvents                    ' allow for cancel or escape to be hit
        If Not bRet Or m_bAbort Then
          bFailed = True
          Exit For
        Else
          Printer.NewPage
        End If
        '
        nSel = nSel + 1
      End If
    Next i
  End With
  
  ' enddoc or cancel job
  If Not bFailed Then
    Printer.EndDoc
  Else
    Printer.KillDoc
  End If
  '
  Ge1.UsePictureColor = False
  EndWaitCursor
  
End Sub

'------------------------------
Private Function PrintFile(ByVal strFile As String) As Boolean
  ' return false if printer errors
  On Error Resume Next
  If ShowGeFile(strFile) Then
    Ge1.UsePictureColor = IIf(chkColourPrint.Value = 0, False, True)
'    ' if printing multiple, want to flip orientation / papersize automatically ?
'    If bmultiple Then
'      Printer.Orientation = Ge1.PageOrientation
'    End If

    PrintFile = DoPrintFile
  End If
End Function

'------------------------------
Private Function DoPrintFile() As Boolean
  ' actually print it (setup layers and send to printer)
  Dim nSavedDC As Long
  
  On Error Resume Next
'  m_LayerDefs.BeginPrint Ge1
  
'**************** Testing purpose
If 1 Then
'****************
  Printer.ScaleMode = 3             ' pixel mode
  Printer.Print ""                  ' begin page
  nSavedDC = SaveDC(Printer.hDC)
  Ge1.PrinterName = Printer.DeviceName
  Ge1.DoPrint Printer.hDC, Printer.hDC, _
                    Printer.ScaleLeft, Printer.ScaleTop, _
                    Printer.ScaleWidth, Printer.ScaleHeight
  nSavedDC = RestoreDC(Printer.hDC, nSavedDC)
'****************
End If
'****************
  ' what happens here ?
'  m_LayerDefs.EndPrint Ge1
  
  If Err = 0 Then DoPrintFile = True
End Function

'------------------------------
Private Function DoPrintSetup() As Boolean
  Dim bRet As Boolean
  Dim nVal As Integer
  
  On Error Resume Next
  ' setup printer with user option(s)
  nVal = Printer.PaperSize
  nVal = AppGetProfileInt(INISECTION_GEEDITOR, INIENTRY_PAPERSIZE, nVal)
  'Printer.PaperSize = nVal
  Printer.PaperSize = Ge1.PaperSizeRaw
  Printer.Orientation = Ge1.PageOrientation      ' 1 = Portrait, 2 = Landscape
  ' err = 380 (Invalid property value) if failed to set (size or orient)
  If Err <> 0 Then Err = 0
    ' get settings and OK./cancel from user
  bRet = ShowPrinter(Me) '    Optional PrintFlags As Integer)
  If bRet Then
    ' save setting to INI file
'    If (Ge1.IsEmpty) Then
      nVal = Printer.PaperSize
      AppWriteProfileInt INISECTION_GEEDITOR, INIENTRY_PAPERSIZE, nVal
'    End If
  End If
  '
  DoPrintSetup = bRet
End Function


'==================================================================
' GeCtrl
'==================================================================
'------------------------------
Private Sub ClearGe()
  On Error Resume Next
  Ge1.InitNew
  Ge1.Grid = False
  Ge1.MarginDisplay = False
  Ge1.Tool = GETOOL_NONE
  Ge1.SendStatusEvents = False
  Ge1.ZoomPage
  lblSelFile.Caption = "Preview:"
  lblSelDrawingSize.Caption = ""
  lblSelDrawingOrient.Caption = ""
End Sub

'------------------------------
Private Function ShowGeFile(strpath As String) As Boolean
  Dim iOrient As Integer
  On Error Resume Next
  Ge1.OpenDwgReadOnly strpath
  lblSelFile.Caption = "Preview: " & StripPath(strpath)
  If Err <> 0 Then
    MsgBox Error
  Else
    ' papersize
    lblSelDrawingSize.Caption = GetDrawingPaperSize
    ' orientation (1 = Portrait, 2 = Landscape)
    iOrient = Ge1.PageOrientation
    If iOrient = 1 Then
      lblSelDrawingOrient.Caption = "Portrait"
    ElseIf iOrient = 2 Then
      lblSelDrawingOrient.Caption = "Landscape"
    Else
      lblSelDrawingOrient.Caption = "unknown (" & iOrient & ")"
    End If
    '
    Ge1.Grid = False
    Ge1.MarginDisplay = False
    m_LayerDefs.SerializeToGe Ge1, False  ' false = load
  
'**************** Testing purpose
    m_LayerDefs.BeginPrint Ge1    ' hide all layers that will not print ??

    ShowGeFile = True
  End If
End Function

'------------------------------
Private Function GetDrawingPaperSize() As String
  ' determine paper size
  '// size of the piece of paper - indexes 0 to 9
  '/*----------------------------------------------
  'ndx,
  '0,  { DMPAPER_LETTER,               8.5F,          11.0F,         _T("A  8.5 x 11 in")  },
  '1 { DMPAPER_LEDGER,              11.0F,          17.0F,         _T("B 11   x 17 in")  },
  '2 { DMPAPER_CSHEET,              17.0F,          22.0F,         _T("C 17   x 22 in")  },
  '3 { DMPAPER_DSHEET,              22.0F,          34.0F,         _T("D 22   x 34 in")  },
  '4 { DMPAPER_ESHEET,              34.0F,          44.0F,         _T("E 34   x 44 in")  },
  '5 { DMPAPER_A3,                 297.0F / 25.4F, 420.0F / 25.4F, _T("A3 297 x 420 mm") },
  '6 { DMPAPER_A4,                 210.0F / 25.4F, 297.0F / 25.4F, _T("A4 210 x 297 mm") },
  '7 { DMPAPER_A5,                 148.0F / 25.4F, 210.0F / 25.4F, _T("A5 148 x 210 mm") },
  '8 { DMPAPER_B4,                 250.0F / 25.4F, 354.0F / 25.4F, _T("B4 250 x 354 mm") },
  '9 { DMPAPER_B5,                 182.0F / 25.4F, 257.0F / 25.4F, _T("B5 182 x 257 mm") }
  '----------------------------------------------*/
  On Error Resume Next
'  Dim lSize As Long
'  lSize = Ge1.PaperSizeRaw
  Dim iSize As Integer
  iSize = Ge1.PaperSize
  Select Case iSize
    Case 0: GetDrawingPaperSize = "A   (8.5 x 11 in)"
    Case 1: GetDrawingPaperSize = "B   (11  x 17 in)"
    Case 2: GetDrawingPaperSize = "C   (17  x 22 in)"
    Case 3: GetDrawingPaperSize = "D   (22  x 34 in)"
    Case 4: GetDrawingPaperSize = "E   (34  x 44 in)"
    Case 5: GetDrawingPaperSize = "A3  (297 x 420 mm)"
    Case 6: GetDrawingPaperSize = "A4  (210 x 297 mm)"
    Case 7: GetDrawingPaperSize = "A5  (148 x 210 mm)"
    Case 8: GetDrawingPaperSize = "B4  (250 x 354 mm)"
    Case 9: GetDrawingPaperSize = "B5  (182 x 257 mm)"
    Case Else: GetDrawingPaperSize = "unknown (" & iSize & ")"
  End Select

End Function


'------------------------------
Private Sub Ge1_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
  ' Right Button
  If Button = 2 Then Ge1.DoRightClick = False
End Sub

'==================================================================
' INI
'==================================================================
'-------------------------------------------
Private Property Get ColourPrintInINI() As Integer
  ColourPrintInINI = AppGetProfileInt(INISECTION_GEEDITOR, INIENTRY_BROWSECOLOURPRINT, 0)  ' 0=default
End Property
Private Property Let ColourPrintInINI(ByVal iVal As Integer)
  AppWriteProfileInt INISECTION_GEEDITOR, INIENTRY_BROWSECOLOURPRINT, iVal
End Property
'-------------------------------------------
Private Property Get RecentFile() As String
  ' get last opened file from INI
  Dim strVal As String, strKey As String
  
  On Error Resume Next
  ' try last browser section
  strKey = INIENTRY_RECENTBROWSEFILE & 1
  strVal = AppGetProfileString(INISECTION_GEEDITOR, strKey, strVal)
  
  If Len(strVal) = 0 Then
    ' try last opened drawing section
    strKey = INIENTRY_RECENTFILE & 1
    strVal = AppGetProfileString(INISECTION_GEEDITOR, strKey, "")
  End If
  '
  If Len(strVal) > 0 Then
    If FileExists(strVal) Then
      RecentFile = strVal
    End If
  End If
End Property

'-------------------------------------------
Private Property Let RecentFile(ByVal FileName As String)
  ' write to INI
  Dim strVal As String, strKey As String
  
  On Error Resume Next
  strKey = INIENTRY_RECENTBROWSEFILE & 1
  strVal = FileName
  AppWriteProfileString INISECTION_GEEDITOR, strKey, strVal
End Property


