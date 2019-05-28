VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Begin VB.Form frmCodeGenerator 
   Caption         =   "ON Code Generator"
   ClientHeight    =   2715
   ClientLeft      =   7125
   ClientTop       =   8130
   ClientWidth     =   7935
   LinkTopic       =   "Form1"
   ScaleHeight     =   2715
   ScaleWidth      =   7935
   Begin MSComDlg.CommonDialog CommDlg 
      Left            =   6480
      Top             =   1560
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.TextBox txtProjectPath 
      Height          =   375
      Left            =   1560
      TabIndex        =   6
      Top             =   1680
      Width           =   4215
   End
   Begin VB.TextBox txtProjectName 
      Height          =   375
      Left            =   1560
      TabIndex        =   5
      Top             =   1200
      Width           =   4215
   End
   Begin VB.CommandButton btnCodeGeneration 
      Caption         =   "Code Generation"
      Height          =   375
      Left            =   3000
      TabIndex        =   4
      Top             =   2280
      Width           =   1935
   End
   Begin VB.ComboBox lbProject 
      Height          =   315
      Left            =   720
      TabIndex        =   1
      Top             =   240
      Width           =   7095
   End
   Begin VB.ComboBox lbClass 
      Height          =   315
      Left            =   720
      TabIndex        =   0
      Top             =   720
      Width           =   7095
   End
   Begin VB.Label Label3 
      Caption         =   "C++ Project Path:"
      Height          =   255
      Left            =   120
      TabIndex        =   8
      Top             =   1680
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   "C++ Project Name:"
      Height          =   255
      Left            =   120
      TabIndex        =   7
      Top             =   1200
      Width           =   1455
   End
   Begin VB.Label Pr 
      Caption         =   "Project:"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   240
      Width           =   735
   End
   Begin VB.Label Label2 
      Caption         =   "Class:"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   720
      Width           =   735
   End
   Begin VB.Line Line3 
      X1              =   0
      X2              =   8280
      Y1              =   0
      Y2              =   0
   End
End
Attribute VB_Name = "frmCodeGenerator"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim SelectedProject As rtsProject
Dim SelectedClass As rtsClass

Dim m_Projects As Object
Dim classCgAttributes As Collection
Dim classCgOperations As Collection

Private Sub btnCodeGeneration_Click()
  Dim incColl As includes
  Dim szProjectPath As String
  Dim szProjectName As String
  Dim className As String
  szProjectPath = txtProjectPath.Text
  szProjectName = txtProjectName.Text
  
  BuildIncludes incColl
  GetClassInfo SelectedProject, lbClass.List(lbClass.ListIndex), SelectedClass, True
  className = SelectedClass.Name
  GenerateHeaderFile incColl, szProjectPath, szProjectName, className, _
                     SelectedClass.Attributes, SelectedClass.Operations, False
  GenerateCPPFile incColl, szProjectPath, szProjectName, className, _
                  SelectedClass.Attributes, SelectedClass.Operations, False
  
  MsgBox "Code generation complete"
End Sub

Private Sub Form_Load()
  Dim activeProject As Object
  Dim activeProjectName As String
  Dim i As Long
  
  If Projects Is Nothing Then
    GetProjects Projects, m_Projects, CommDlg
  End If
  
  If Projects.count = 0 Then
    GetProjects Projects, m_Projects, CommDlg
  End If
  
  FillProjectCombo
  
#If using_artisan Then
  
  Set activeProject = m_Projects.Item("Active Project")
  If Not activeProject Is Nothing Then
    activeProjectName = activeProject.PropertyGet("Name")
    For i = 0 To lbProject.ListCount - 1
      If lbProject.List(i) = activeProjectName Then
        lbProject.ListIndex = i
        Exit For
      End If
    Next i
  End If

#ElseIf using_ilogix Then

  If Not doc Is Nothing Then
    If Not doc.activeProject Is Nothing Then
      activeProjectName = doc.activeProject.Name
      For i = 0 To lbProject.ListCount - 1
        If lbProject.List(i) = activeProjectName Then
          lbProject.ListIndex = i
          Exit For
        End If
      Next i
    End If
  End If
  
#End If

End Sub

Private Sub Form_Unload(Cancel As Integer)
  Set Projects = Nothing
End Sub

Private Sub lbProject_Click()

  Dim activeClassName As String
  Dim i As Long
  
  Set SelectedProject = Projects.Item(lbProject.ItemData(lbProject.ListIndex))
  FillClassCombo
  
#If using_artisan Then

  Dim activeItem As Object
  Dim activeItemType As String
  Set activeItem = m_Projects.Item("Active Dictionary Item")
  If Not activeItem Is Nothing Then
    activeItemType = activeItem.PropertyGet("Type")
    If activeItemType = "Class" Then
      activeClassName = activeItem.PropertyGet("Name")
      For i = 0 To lbClass.ListCount - 1
        If lbClass.List(i) = activeClassName Then
          lbClass.ListIndex = i
          Exit For
        End If
      Next i
    End If
  End If

#ElseIf using_ilogix Then

  If Not doc Is Nothing Then
    If Not doc.activeProject Is Nothing Then
      If Not doc.activeProject.activeComponent Is Nothing Then
        If doc.activeProject.activeComponent.metaClass = "Class" Then
          activeClassName = doc.activeProject.activeComponent.Name
          For i = 0 To lbClass.ListCount - 1
            If lbClass.List(i) = activeClassName Then
              lbClass.ListIndex = i
              Exit For
            End If
          Next i
        End If
      End If
    End If
  End If

#End If

End Sub

Sub FillProjectCombo()

  Dim i As Long
  lbProject.Clear
  For i = 1 To Projects.count
    lbProject.AddItem Projects(i).Name
    lbProject.ItemData(lbProject.ListCount - 1) = i
  Next i

End Sub

Sub FillClassCombo()
  Dim i As Long
  Dim aName As String
  
  lbClass.Clear
  For i = 1 To SelectedProject.classes.count
    aName = SelectedProject.classes(i).Name
    lbClass.AddItem aName
    lbClass.ItemData(lbClass.ListCount - 1) = i
  Next i
End Sub

