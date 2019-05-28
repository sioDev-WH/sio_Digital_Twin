VERSION 5.00
Begin VB.Form ShiftLeverContainer 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Shift Lever"
   ClientHeight    =   2880
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   1860
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2880
   ScaleWidth      =   1860
   StartUpPosition =   3  'Windows Default
   Begin VB.OptionButton OptionDrive 
      Caption         =   "D"
      Height          =   375
      Index           =   2
      Left            =   1440
      TabIndex        =   3
      Top             =   1920
      Width           =   495
   End
   Begin VB.OptionButton OptionNeutral 
      Caption         =   "N"
      Height          =   375
      Index           =   1
      Left            =   1440
      TabIndex        =   2
      Top             =   1440
      Value           =   -1  'True
      Width           =   495
   End
   Begin VB.OptionButton OptionReverse 
      Caption         =   "R"
      Height          =   375
      Index           =   0
      Left            =   1440
      TabIndex        =   1
      Top             =   960
      Width           =   495
   End
   Begin VB.PictureBox Picture1 
      DragMode        =   1  'Automatic
      Height          =   2775
      Left            =   120
      ScaleHeight     =   2715
      ScaleWidth      =   1155
      TabIndex        =   0
      Top             =   0
      Width           =   1215
   End
End
Attribute VB_Name = "ShiftLeverContainer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
 Dim imageReverse As IPictureDisp
 Dim imageDrive As IPictureDisp
 Dim imageNeutral As IPictureDisp
 Public Position As Long
 

Private Sub Form_Load()
path = "C:\DistComponents\GUI\"
    Set imageReverse = LoadPicture(path & "Lever_Reverse.bmp")
    Set imageDrive = LoadPicture(path & "Lever_Drive.bmp")
    Set imageNeutral = LoadPicture(path & "Lever_Neutral.bmp")
    Picture1.Picture = imageNeutral
End Sub

Private Sub OptionDrive_Click(Index As Integer)
    Picture1.Picture = imageDrive
    Position = 1
    OptionReverse.Item(0).Enabled = False
End Sub

Private Sub OptionNeutral_Click(Index As Integer)
    Picture1.Picture = imageNeutral
    Position = 0
    OptionDrive.Item(2).Enabled = True
    OptionReverse.Item(0).Enabled = True
End Sub

Private Sub OptionReverse_Click(Index As Integer)
    Picture1.Picture = imageReverse
    Position = -1
    OptionDrive.Item(2).Enabled = False
End Sub
