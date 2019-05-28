VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Begin VB.Form frmBitMap 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Bitmap (device dependant)"
   ClientHeight    =   6600
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5790
   Icon            =   "frmBitMap.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   PaletteMode     =   2  'Custom
   ScaleHeight     =   6600
   ScaleWidth      =   5790
   ShowInTaskbar   =   0   'False
   Begin VB.PictureBox picSave 
      Height          =   555
      Left            =   3300
      ScaleHeight     =   495
      ScaleWidth      =   555
      TabIndex        =   15
      Top             =   3750
      Visible         =   0   'False
      Width           =   615
   End
   Begin VB.OptionButton Option1 
      Caption         =   "Bitmap of Selection"
      Height          =   255
      Index           =   1
      Left            =   60
      TabIndex        =   12
      ToolTipText     =   "View bitmap of selected objects iin drawing"
      Top             =   555
      Width           =   2445
   End
   Begin VB.OptionButton Option1 
      Caption         =   "Bitmap of Complete Drawing"
      Height          =   255
      Index           =   0
      Left            =   60
      TabIndex        =   11
      ToolTipText     =   "View bitmap of complete drawing"
      Top             =   300
      Value           =   -1  'True
      Width           =   2445
   End
   Begin VB.PictureBox btnImage 
      Height          =   2190
      Left            =   120
      ScaleHeight     =   2130
      ScaleWidth      =   5460
      TabIndex        =   9
      Top             =   1380
      Width           =   5520
   End
   Begin VB.CommandButton btnGrowPal 
      Caption         =   "Get HWnd"
      Height          =   255
      Left            =   180
      TabIndex        =   7
      Top             =   0
      Visible         =   0   'False
      Width           =   1455
   End
   Begin VB.CommandButton btnExit 
      Caption         =   "Close"
      Height          =   315
      Left            =   4380
      TabIndex        =   6
      ToolTipText     =   "Close this dialog"
      Top             =   570
      Width           =   1230
   End
   Begin VB.TextBox txtSpaceX 
      Height          =   285
      Left            =   3090
      TabIndex        =   4
      Text            =   "368"
      Top             =   270
      Width           =   825
   End
   Begin VB.TextBox txtSpaceY 
      Height          =   285
      Left            =   3090
      TabIndex        =   3
      Text            =   "256"
      Top             =   570
      Width           =   825
   End
   Begin VB.CommandButton btnSaveBitmap 
      Caption         =   "Save Bitmap..."
      Height          =   315
      Left            =   4380
      TabIndex        =   0
      ToolTipText     =   "Save to Bitmap (BMP) file"
      Top             =   210
      Width           =   1230
   End
   Begin MSComDlg.CommonDialog CommonDlg 
      Left            =   4170
      Top             =   4290
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      FontSize        =   2.54052e-29
   End
   Begin VB.Label lbSize 
      AutoSize        =   -1  'True
      Caption         =   "lbSize"
      Height          =   195
      Left            =   3510
      TabIndex        =   14
      Top             =   960
      Width           =   420
   End
   Begin VB.Label Label3 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "BMP File Size  (bytes) ="
      Height          =   195
      Left            =   1785
      TabIndex        =   13
      ToolTipText     =   "the size of the saved bitmap (BMP) file"
      Top             =   960
      Width           =   1665
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Bitmap Preview"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Left            =   135
      TabIndex        =   10
      Top             =   960
      Width           =   1095
   End
   Begin VB.Label lblNote 
      Caption         =   "Note: to change the background of the bitmap, change the background of the drawing (Settings/Drawing Properties...)"
      Height          =   465
      Left            =   525
      TabIndex        =   8
      Top             =   6000
      Width           =   4410
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "Height"
      Height          =   195
      Index           =   2
      Left            =   2610
      TabIndex        =   5
      Top             =   615
      Width           =   465
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "Width"
      Height          =   195
      Index           =   1
      Left            =   2610
      TabIndex        =   2
      Top             =   315
      Width           =   420
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "Bitmap Size (pixels)"
      Height          =   195
      Index           =   0
      Left            =   2610
      TabIndex        =   1
      Top             =   60
      Width           =   1365
   End
End
Attribute VB_Name = "frmBitMap"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

'======================================================================================
'
'======================================================================================
Option Explicit

Const DRIVERVERSION = 0   ' /* Device driver version                    */
Const TECHNOLOGY = 2      ' /* Device classification                    */
Const HORZSIZE = 4        ' /* Horizontal size in millimeters           */
Const VERTSIZE = 6        ' /* Vertical size in millimeters             */
Const HORZRES = 8          '/* Horizontal width in pixels               */
Const VERTRES = 10         '/* Vertical height in pixels                */
Const BITSPIXEL = 12       '/* Number of bits per pixel                 */
Const PLANES = 14          '/* Number of planes                         */
Const NUMBRUSHES = 16      '/* Number of brushes the device has         */
Const NUMPENS = 18         '/* Number of pens the device has            */
Const NUMMARKERS = 20      '/* Number of markers the device has         */
Const NUMFONTS = 22        '/* Number of fonts the device has           */
Const NUMCOLORS = 24      ' /* Number of colors the device supports     */
Const PDEVICESIZE = 26    ' /* Size required for device descriptor      */
Const CURVECAPS = 28      ' /* Curve capabilities                       */
Const LINECAPS = 30       ' /* Line capabilities                        */
Const POLYGONALCAPS = 32  ' /* Polygonal capabilities                   */
Const TEXTCAPS = 34       ' /* Text capabilities                        */
Const CLIPCAPS = 36       ' /* Clipping capabilities                    */
Const RASTERCAPS = 38     ' /* Bitblt capabilities                      */
Const ASPECTX = 40        ' /* Length of the X leg                      */
Const ASPECTY = 42        ' /* Length of the Y leg                      */
Const ASPECTXY = 44       ' /* Length of the hypotenuse                 */


'========================================================
' Declarations
'

Private Declare Function GetDeviceCaps Lib "gdi32" (ByVal hDC As Long, ByVal nIndex As Long) As Long

Private m_GeCtrl As CG


Private Type RectExtent
    llX As Single
    llY As Single
    urX As Single
    urY As Single
End Type

Private m_dPanZoomScale As Single
Private m_llXP As Single, m_llYP As Single
Private m_RectPage As RectExtent
Private m_RectCur As RectExtent

Private m_bGetSel As Boolean
Private m_strBMPFileName As String

Dim m_lTwipsX As Long  ' Screen.TwipsPerPixelX
Dim m_lTwipsY As Long  ' Screen.TwipsPerPixelY
Dim m_fAspectRatio As Single

Private m_lleft As Long, m_lTop As Long, m_lright As Long, m_lbottom As Long
Private m_llX As Single, m_llY As Single, m_urX As Single, m_urY As Single


Private Declare Function GetWindowRect Lib "user32" (ByVal hWnd As Long, lpRect As RECT) As Long
Private Declare Function GetWindowDC Lib "user32" (ByVal hWnd As Long) As Long
Private Declare Function ReleaseDC Lib "user32" (ByVal hWnd As Long, ByVal hDC As Long) As Long
Private Declare Function BitBlt Lib "gdi32" (ByVal hDestDC As Long, ByVal X As Long, ByVal Y As Long, _
                    ByVal nWidth As Long, ByVal nHeight As Long, _
                    ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, ByVal dwRop As Long) As Long
Private Declare Function StretchBlt Lib "gdi32" (ByVal hDC As Long, _
                    ByVal X As Long, ByVal Y As Long, ByVal nWidth As Long, ByVal nHeight As Long, _
                    ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, _
                    ByVal nSrcWidth As Long, ByVal nSrcHeight As Long, ByVal dwRop As Long) As Long

Private Type RECT
   Left As Long
   Top As Long
   Right As Long
   Bottom As Long
End Type
Private Const SRCCOPY = &HCC0020 ' (DWORD) dest = source

'======================================================================================
' End Declarations
'======================================================================================

'--------------------------
Public Property Set GeCtrl(obj As CG)
  Dim i As Integer
  On Error Resume Next
  Set m_GeCtrl = obj
End Property

'------------------------------
Private Sub btnExit_Click()
  Unload Me
End Sub

'------------------------------
Private Sub btnGrowPal_Click()
'  On Error Resume Next
'  If m_GeCtrl Is Nothing Then Exit Sub
'  Dim pal As CPalette
'  Set pal = New CPalette
'  pal.GrowPalette m_GeCtrl, 100
'  Set pal = Nothing
  
  Dim hDCCur As Long
  Dim hWndCur As Long
  Dim RectWnd As RECT
  Dim dX As Long, dy As Long
  
  On Error Resume Next
  
  Me.Visible = False
  DoEvents
  
  hWndCur = m_GeCtrl.GethWnd
  hDCCur = GetWindowDC(hWndCur)
  
  Call GetWindowRect(hWndCur, RectWnd)  ' rect of geCtrl
  dX = RectWnd.Right - RectWnd.Left + 2 ' inflate
  dy = RectWnd.Bottom - RectWnd.Top + 2
  
  ' blt into picture control
  With btnImage
    .AutoRedraw = True
    .AutoSize = True
    
'      Call BitBlt(.hdc, 0, 0, DX, DY, hDCCur, 200, 200, SRCCOPY)
      Call BitBlt(.hDC, 0, 0, dX, dy, hDCCur, 0, 0, SRCCOPY)

''      .Picture = .Image  ' reverse of below
'      .Image = .Picture ' set whats on the screen is what got bltt'd to it
      
'      Dim RectPic As RECT
'      Dim DXp As Long, DYp As Long
'      '
'      Call GetWindowRect(.hWnd, RectPic)  ' rect of picture box
'      DXp = RectPic.Right - RectPic.Left + 2
'      DYp = RectPic.Bottom - RectPic.Top + 2
'      Call StretchBlt(.hdc, 0, 0, DXp, DYp, hDCCur, 0, 0, DX, DY, SRCCOPY)

  End With
  '
  Call ReleaseDC(hWndCur, hDCCur)
  
  Me.Visible = True
  
End Sub

'--------------------------------
Private Sub Form_Activate()
  Static bFirst As Boolean
  On Error Resume Next
  
  If Not bFirst Then
    bFirst = True
    ' get user's screen data
    m_lTwipsX = Screen.TwipsPerPixelX
    m_lTwipsY = Screen.TwipsPerPixelY
    
    If m_GeCtrl.SelNumberOfObjects < 1 Then
      Option1(1).Enabled = False
      m_bGetSel = False
    Else
      m_bGetSel = IIf(Option1(0).Value = 0, True, False)
    End If
    
    SetAspectRatio
    
    txtSpaceX.Text = 368 ' default for size of dialog box
    txtSpaceY.Text = CInt(txtSpaceX.Text * m_fAspectRatio)
    
    SetPicBoxSize
    GetImageFromGe
  End If
  
End Sub

'------------------------------
Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
  If KeyCode = vbKeyEscape Then
    KeyCode = 0
    Unload Me
  End If
End Sub

'------------------------------
Private Sub Form_Unload(Cancel As Integer)
  Set m_GeCtrl = Nothing
End Sub

'------------------------------
Private Sub Option1_Click(Index As Integer)

  m_bGetSel = IIf(Option1(0).Value = False, True, False)
  If m_GeCtrl.SelNumberOfObjects < 1 Then
    m_bGetSel = False
  End If
  
  SetAspectRatio
  ' assume width is what we want, then adjust height
  txtSpaceY.Text = CInt(txtSpaceX.Text * m_fAspectRatio)
  SetPicBoxSize
  GetImageFromGe
End Sub

'------------------------------
Private Sub SetAspectRatio()
  Dim llX As Single, llY As Single, urX As Single, urY As Single
  
  On Error Resume Next
  ' aspect based on page size
  m_fAspectRatio = m_GeCtrl.PageHeight / m_GeCtrl.PageWidth
  ' get the selection ratio and modify it by the page ratio
  If m_bGetSel = True Then
    m_GeCtrl.GetSelExtents llX, llY, urX, urY
    If m_fAspectRatio < 1# Then
      m_fAspectRatio = ((urY - llY) / (urX - llX)) / m_fAspectRatio
    Else
      m_fAspectRatio = ((urY - llY) / (urX - llX)) * m_fAspectRatio
    End If
  End If
End Sub

'------------------------------
Private Sub SetPicBoxSize()
  Dim a12 As Long
  Dim strVal As String
  Dim lVal As Long
  Dim tmp As Integer
  Dim lWtMax As Long
  Dim lHtMax As Long
  Dim lWt As Long, lHt As Long
  
  On Error Resume Next
  strVal = txtSpaceX.Text
  lVal = CLng(txtSpaceX.Text)
  btnImage.Width = (lVal * m_lTwipsX)
  
  strVal = txtSpaceY.Text
  lVal = CLng(txtSpaceY.Text)
  
  lHt = (lVal * m_lTwipsY)
  If lHt < 1 Then lHt = 1
  lWt = btnImage.Width
  If lWt < 1 Then lWt = 1
  lWtMax = Me.ScaleWidth - btnImage.Left - 90   ' 5520
  lHtMax = lblNote.Top - btnImage.Top - 90       ' 4265
  
  ' fixed numbers are based on max dialog size
  If m_fAspectRatio < 1# Then ' landscape orientation
    If lWt > lWtMax Then
      lWt = lWtMax
      lHt = lWt * m_fAspectRatio
    ElseIf lHt > lHtMax Then
      lWt = lWtMax
      lHt = lWt * m_fAspectRatio
    ElseIf lWt > lHt / m_fAspectRatio Then
      lWt = lHt / m_fAspectRatio
    ElseIf lHt > lWt * m_fAspectRatio Then
      lHt = lWt * m_fAspectRatio
    End If
  Else
    If lWt > lWtMax Then
      lWt = lHtMax
      lWt = lHt / m_fAspectRatio
    ElseIf lHt > lHtMax Then
      lHt = lHtMax
      lWt = lHt / m_fAspectRatio
    ElseIf lWt > lHt / m_fAspectRatio Then
      lHt = lWt * m_fAspectRatio
    ElseIf lHt > lWt * m_fAspectRatio Then
      lWt = lHt / m_fAspectRatio
    End If
  End If
  
  btnImage.Width = lWt
  btnImage.Height = lHt
  
  
'*********
  ' AEM - 3/10/00 - leave control topleft anchored in same position
  
'  ' center control
'  btnImage.Left = (5520 - btnImage.Width) / 2
'  tmp = ((4265 - btnImage.Height) / 2)
'  If tmp < 0 Then tmp = 0
'  btnImage.Top = 1200 + tmp
'*********


  a12 = GetDeviceCaps(Screen.ActiveForm.hDC, BITSPIXEL)
  If a12 = 8 Then
    lbSize.Caption = Format(CLng(txtSpaceX.Text * txtSpaceY.Text), "###,###,###")
  Else
    lbSize.Caption = Format(CLng(txtSpaceX.Text * txtSpaceY.Text * 3), "###,###,###")
  End If

End Sub


'------------------------------
Private Sub txtSpaceX_KeyPress(KeyAscii As Integer)
  If KeyAscii = vbKeyReturn Then
    KeyAscii = 0
    txtSpaceX_LostFocus
  End If
End Sub

'------------------------------
Private Sub txtSpaceX_LostFocus()
  Dim strVal As String
  Dim lVal As Long

  On Error Resume Next
  
  strVal = txtSpaceX.Text
  lVal = CLng(txtSpaceX.Text)

  SetAspectRatio
  
  If lVal > 0 Then
    ' if we are showing complete picture, maintain aspect ratio
    txtSpaceY.Text = CInt(txtSpaceX.Text * m_fAspectRatio)
    SetPicBoxSize
    GetImageFromGe
  Else
    txtSpaceX.Text = CInt(btnImage.Width / m_lTwipsX)
  End If
  
End Sub
'------------------------------
Private Sub txtSpaceY_KeyPress(KeyAscii As Integer)
  If KeyAscii = vbKeyReturn Then
    KeyAscii = 0
    txtSpaceY_LostFocus
  End If
End Sub
'------------------------------
Private Sub txtSpaceY_LostFocus()
  Dim strVal As String
  Dim lVal As Long
  
  On Error Resume Next
  strVal = txtSpaceY.Text
  lVal = CLng(txtSpaceY.Text)
  
  SetAspectRatio
  If lVal > 0 Then
    ' if we are showing complete picture, maintain aspect ratio
'    If m_bGetSel = False Then
      txtSpaceX.Text = CInt(txtSpaceY.Text / m_fAspectRatio)
'    End If
  
    SetPicBoxSize
    GetImageFromGe
  Else
    txtSpaceY.Text = CInt(btnImage.Height / m_lTwipsY)
  End If
  
End Sub


'--------------------------
Private Sub GetImageFromGe()
  Dim nExpand As Single
  
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  
  If m_bGetSel = True Then
    If m_GeCtrl.SelNumberOfObjects < 1 Then
      m_bGetSel = False
      Option1(1).Enabled = False
'      MsgBox "There is nothing selected in the drawing. Cannot get bitmap of selection"
    End If
  End If
  
  ' set button's picture to geBMP
  m_lleft = 0:  m_lTop = 0
  ' this keeps the picture box displaying the correct image
  m_lright = (btnImage.Width) / m_lTwipsX
  m_lbottom = (btnImage.Height) / m_lTwipsY

  If m_bGetSel And m_GeCtrl.SelNumberOfObjects > 0 Then
    m_GeCtrl.GetSelExtents m_llX, m_llY, m_urX, m_urY
    ' make rect 5% bigger
    nExpand = (m_urX - m_llX) * 0.05
    m_urX = m_urX + nExpand
    m_urY = m_urY + nExpand
    m_llX = m_llX - nExpand
    m_llY = m_llY - nExpand
  Else
    ' grab whole page
    m_llX = m_GeCtrl.DrawingOriginX
    m_llY = m_GeCtrl.DrawingOriginY
    m_urX = m_GeCtrl.DrawingWidth ' - llX
    m_urY = m_GeCtrl.DrawingHeight ' - llY
  End If

  ' This one shows the view of what we are going to get
  'dest/source
  Set btnImage.Picture = m_GeCtrl.GetBitmapImage( _
            m_lleft, m_lTop, m_lright, m_lbottom, _
            m_llX, m_llY, m_urX, m_urY)
  
  ' don't use control size as it may be limited in size
  m_lright = CLng(txtSpaceX.Text) '(btnImage.Width) / m_lTwipsX
  m_lbottom = CLng(txtSpaceY.Text) '(btnImage.Height) / m_lTwipsY
  

End Sub

'--------------------------
Private Sub btnSaveBitmap_Click()
  ' save bmp to disk
  On Error Resume Next
  If m_GeCtrl Is Nothing Then Exit Sub
  If Len(m_strBMPFileName) = 0 Then
    If Len(m_GeCtrl.GetDwgName) > 0 Then
      m_strBMPFileName = StripExtension(m_GeCtrl.GetDwgName) & ".bmp"
    End If
  End If
  
  If Len(m_strBMPFileName) > 0 Then
    CommonDlg.FileName = m_strBMPFileName
  End If
  CommonDlg.CancelError = True
  CommonDlg.DefaultExt = "BMP"

  CommonDlg.DialogTitle = "Save Selection to BMP File"
  CommonDlg.Filter = "Bitmap (*.bmp)|*.bmp||"
  CommonDlg.ShowSave
  If Err <> 0 Then Exit Sub
   
  m_strBMPFileName = CommonDlg.FileName
  
  ' This is the actual data that gets saved to the file. It may be
  ' bigger than the entire screen if it was visible
  Set picSave.Picture = m_GeCtrl.GetBitmapImage( _
            m_lleft, m_lTop, m_lright, m_lbottom, _
            m_llX, m_llY, m_urX, m_urY)
  
  SavePicture picSave.Picture, m_strBMPFileName
  
  If Err <> 0 Then MsgBox Error & " (" & Err & ")"

End Sub

