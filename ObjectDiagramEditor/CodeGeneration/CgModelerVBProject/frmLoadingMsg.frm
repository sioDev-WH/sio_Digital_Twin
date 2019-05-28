VERSION 5.00
Begin VB.Form frmLoadingMsg 
   BorderStyle     =   0  'None
   Caption         =   "Form1"
   ClientHeight    =   615
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   2745
   ClipControls    =   0   'False
   ControlBox      =   0   'False
   DrawWidth       =   5
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   Moveable        =   0   'False
   NegotiateMenus  =   0   'False
   ScaleHeight     =   615
   ScaleWidth      =   2745
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.Line Line1 
      BorderColor     =   &H80000003&
      BorderWidth     =   5
      Index           =   3
      X1              =   2700
      X2              =   2700
      Y1              =   0
      Y2              =   660
   End
   Begin VB.Line Line1 
      BorderColor     =   &H80000003&
      BorderWidth     =   5
      Index           =   2
      X1              =   30
      X2              =   30
      Y1              =   30
      Y2              =   630
   End
   Begin VB.Line Line1 
      BorderColor     =   &H80000003&
      BorderWidth     =   5
      Index           =   1
      X1              =   -90
      X2              =   2730
      Y1              =   570
      Y2              =   570
   End
   Begin VB.Line Line1 
      BorderColor     =   &H80000003&
      BorderWidth     =   5
      Index           =   0
      X1              =   -60
      X2              =   2760
      Y1              =   30
      Y2              =   30
   End
   Begin VB.Label lbStatusMsg 
      Alignment       =   2  'Center
      Caption         =   "<No Message>"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   285
      Left            =   90
      TabIndex        =   0
      Top             =   150
      Width           =   2595
   End
End
Attribute VB_Name = "frmLoadingMsg"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Public Sub SetCaption(strMsg As String)
    lbStatusMsg.Caption = strMsg
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Screen.MousePointer = vbArrow
End Sub
