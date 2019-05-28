VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Frontline Systems - Nonlinear Examples"
   ClientHeight    =   3825
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4665
   LinkTopic       =   "Form1"
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   3825
   ScaleWidth      =   4665
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton Command8 
      Caption         =   "Example 6"
      Height          =   375
      Left            =   240
      TabIndex        =   15
      Top             =   3360
      Width           =   1215
   End
   Begin VB.CommandButton Command7 
      Caption         =   "Example 5"
      Height          =   375
      Left            =   3360
      TabIndex        =   14
      Top             =   2760
      Width           =   1215
   End
   Begin VB.CommandButton Command6 
      Caption         =   "Example 4B"
      Height          =   375
      Left            =   1800
      TabIndex        =   13
      Top             =   2760
      Width           =   1215
   End
   Begin VB.CommandButton Command5 
      Caption         =   "Quit"
      Height          =   375
      Left            =   3360
      TabIndex        =   12
      Top             =   3360
      Width           =   1215
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Example 4A"
      Height          =   375
      Left            =   240
      TabIndex        =   11
      Top             =   2760
      Width           =   1215
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Example 3"
      Height          =   375
      Left            =   3360
      TabIndex        =   10
      Top             =   2160
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Example 2"
      Height          =   375
      Left            =   1800
      TabIndex        =   9
      Top             =   2160
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Example 1"
      Height          =   375
      Left            =   240
      TabIndex        =   8
      Top             =   2160
      Width           =   1215
   End
   Begin VB.Label Label8 
      Caption         =   "Email info@frontsys.com"
      Height          =   375
      Left            =   2400
      TabIndex        =   7
      Top             =   1440
      Width           =   2295
   End
   Begin VB.Label Label7 
      Caption         =   "Fax (775) 831-0314"
      Height          =   255
      Left            =   2400
      TabIndex        =   6
      Top             =   1200
      Width           =   1935
   End
   Begin VB.Label Label6 
      Caption         =   "Tel (775) 831-0300"
      Height          =   255
      Left            =   2400
      TabIndex        =   5
      Top             =   960
      Width           =   1575
   End
   Begin VB.Label Label5 
      Caption         =   "NV 89450 USA"
      Height          =   255
      Left            =   240
      TabIndex        =   4
      Top             =   1680
      Width           =   1695
   End
   Begin VB.Label Label4 
      Caption         =   "Incline Village"
      Height          =   375
      Left            =   240
      TabIndex        =   3
      Top             =   1440
      Width           =   1455
   End
   Begin VB.Label Label3 
      Caption         =   "P.O. Box 4288"
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   1200
      Width           =   1695
   End
   Begin VB.Label Label2 
      Caption         =   "Frontline Systems Inc."
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   960
      Width           =   1815
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Small-Scale Solver Dynamic Link Library Version 3.5"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   4215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
   AdjustFormforExample1
   Example = 1
   Form2.Show
End Sub

Private Sub Command2_Click()
   AdjustFormforExample2
   Example = 2
   Form2.Show
End Sub

Private Sub Command3_Click()
   AdjustFormforExample3
   Example = 3
   Form2.Show
End Sub

Private Sub Command4_Click()
   Adjustfor4a
   Example = 4
   Nonlinear = True
   Form2.Show
End Sub

Private Sub Command5_Click()
   End
End Sub

Private Sub Command6_Click()
   Example = 4
   Nonlinear = False
   AdjustFormforExample4
   Form2.Show
End Sub

Private Sub Command7_Click()
   Example = 5
   AdjustFormforExample5
   Form2.Show
End Sub

Private Sub Command8_Click()
   Example = 6
   AdjustFormforExample6
   Form2.Show
End Sub

Private Sub Form_Load()
    Showlimits
End Sub
