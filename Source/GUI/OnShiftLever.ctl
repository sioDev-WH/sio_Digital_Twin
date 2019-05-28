VERSION 5.00
Begin VB.UserControl OnShiftLever 
   ClientHeight    =   2850
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   1875
   ScaleHeight     =   2850
   ScaleWidth      =   1875
   Begin VB.PictureBox Picture1 
      DragMode        =   1  'Automatic
      Height          =   2775
      Left            =   0
      ScaleHeight     =   2715
      ScaleWidth      =   1155
      TabIndex        =   3
      Top             =   0
      Width           =   1215
   End
   Begin VB.OptionButton OptionReverse 
      Caption         =   "R"
      Height          =   375
      Left            =   1320
      TabIndex        =   2
      Top             =   960
      Width           =   495
   End
   Begin VB.OptionButton OptionNeutral 
      Caption         =   "N"
      Height          =   375
      Left            =   1320
      TabIndex        =   1
      Top             =   1440
      Value           =   -1  'True
      Width           =   495
   End
   Begin VB.OptionButton OptionDrive 
      Caption         =   "D"
      Height          =   375
      Left            =   1320
      TabIndex        =   0
      Top             =   1920
      Width           =   495
   End
End
Attribute VB_Name = "OnShiftLever"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Dim imageReverse As IPictureDisp
Dim imageDrive As IPictureDisp
Dim imageNeutral As IPictureDisp
Private m_Position As Long
 
Public Property Let Position(val As Long)
  m_Position = val

  If m_Position = 1 Then
    OptionDrive.Value = True
    Picture1.Picture = imageDrive
    OptionReverse.Enabled = False
  ElseIf m_Position = 0 Then
    OptionNeutral.Value = True
    Picture1.Picture = imageNeutral
    OptionDrive.Enabled = True
    OptionReverse.Enabled = True
  ElseIf m_Position = -1 Then
    OptionReverse.Value = True
    Picture1.Picture = imageReverse
    OptionDrive.Enabled = False
  End If

End Property

Public Property Get Position() As Long
  Position = m_Position
End Property

Private Sub UserControl_Initialize()
  Dim path As String
  Dim env As OnEnv
  
  On Error GoTo error_handler
  
  Set env = New OnEnv
  path = env.GraphicPath

    Set imageReverse = LoadPicture(path & "Lever_Reverse.bmp")
    Set imageDrive = LoadPicture(path & "Lever_Drive.bmp")
    Set imageNeutral = LoadPicture(path & "Lever_Neutral.bmp")
    Picture1.Picture = imageNeutral
    
Exit Sub
error_handler:
  MsgBox "Error initializing ShiftLever dialog '" & Err.Description & "'"
    
End Sub

Private Sub OptionDrive_Click()
    Picture1.Picture = imageDrive
    m_Position = 1
    OptionReverse.Enabled = False
End Sub

Private Sub OptionNeutral_Click()
    Picture1.Picture = imageNeutral
    m_Position = 0
    OptionDrive.Enabled = True
    OptionReverse.Enabled = True
End Sub

Private Sub OptionReverse_Click()
    Picture1.Picture = imageReverse
    m_Position = -1
    OptionDrive.Enabled = False
End Sub

