VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.UserControl ucUMLTreeView 
   ClientHeight    =   2550
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   6210
   ScaleHeight     =   2550
   ScaleWidth      =   6210
   Begin VB.Frame frmDetails 
      BorderStyle     =   0  'None
      Height          =   2415
      Left            =   3360
      TabIndex        =   2
      Top             =   120
      Width           =   2775
      Begin VB.TextBox txtProject 
         Enabled         =   0   'False
         ForeColor       =   &H80000007&
         Height          =   315
         Left            =   60
         TabIndex        =   5
         Top             =   240
         Width           =   2655
      End
      Begin VB.TextBox txtPackage 
         Enabled         =   0   'False
         Height          =   315
         Left            =   60
         TabIndex        =   4
         Top             =   900
         Width           =   2655
      End
      Begin VB.TextBox txtClass 
         Enabled         =   0   'False
         Height          =   315
         Left            =   60
         TabIndex        =   3
         Top             =   1560
         Width           =   2655
      End
      Begin VB.Label lblProject 
         Caption         =   "Project:"
         Height          =   195
         Left            =   60
         TabIndex        =   8
         Top             =   0
         Width           =   855
      End
      Begin VB.Label lblPackage 
         Caption         =   "Package:"
         Height          =   195
         Left            =   60
         TabIndex        =   7
         Top             =   660
         Width           =   915
      End
      Begin VB.Label lblClass 
         Caption         =   "Class:"
         Height          =   195
         Left            =   60
         TabIndex        =   6
         Top             =   1320
         Width           =   735
      End
   End
   Begin MSComctlLib.TreeView tvUMLProjSel 
      Height          =   2535
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   3315
      _ExtentX        =   5847
      _ExtentY        =   4471
      _Version        =   393217
      HideSelection   =   0   'False
      Indentation     =   353
      LabelEdit       =   1
      Style           =   7
      SingleSel       =   -1  'True
      Appearance      =   1
   End
   Begin VB.Label Label4 
      Caption         =   "ProjectTree"
      Height          =   195
      Left            =   120
      TabIndex        =   1
      Top             =   60
      Width           =   1455
   End
End
Attribute VB_Name = "ucUMLTreeView"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
'-----------------------------------------------------------------------
' This control is used to navigate through a UML project\package\class
' tree, and select any tree branch
'
' NOTE:
' ----
' The parent of this control must implement the following properties:
'       SetSelectedProject
'       SetSelectedPackage
'       SetSelectedClass
'-----------------------------------------------------------------------

Const iNodePrefix_Projects = "0_"
Const iNodePrefix_Packages = "1_"
Const iNodePrefix_Classes = "2_"

Private selProject As rtsProject
Private selPackage As rtsPackage
Private selClass As rtsClass
Private m_strClassID As String
Private bHideUpdates As Boolean
Private bHideClassDetails As Boolean

Public Sub HideClass()
  txtClass.Visible = False
  lblClass.Visible = False
End Sub

Public Property Get ClassName() As String
  ClassName = txtClass.Text
End Property

Public Property Get PackagesName() As String
  PackagesName = txtPackage.Text
End Property

Public Property Get ProjectName() As String
  ProjectName = txtProject.Text
End Property

Public Property Get HideClassDetails() As Boolean
    HideClassDetails = bHideClassDetails
End Property

Public Property Let HideClassDetails(bHide As Boolean)
    bHideClassDetails = bHide
End Property

Public Property Let ClassName(strClass As String)
  On Error Resume Next
  If strClass = "" Then
    tvUMLProjSel.nodes(iNodePrefix_Classes & txtClass.Text).Selected = False
    txtClass.Text = strClass
    Exit Property
  End If
  txtClass.Text = strClass
  tvUMLProjSel.nodes(iNodePrefix_Classes & strClass).Selected = True
  If selPackage Is Nothing Then Exit Property
  
  Set selClass = Nothing
  'Primary lookup by class iD
  Set selClass = FindClassByID(m_strClassID, selPackage.Classes)
  If selClass Is Nothing Then
    'Secondary lookup by class name
    Set selClass = selPackage.Classes(strClass)
  End If
  
  UserControl.Parent.SetSelectedClass selClass
End Property

Public Property Let ClassID(strClassID As String)
  On Error Resume Next
  m_strClassID = strClassID
End Property

Public Property Let PackagesName(strPackage As String)
  On Error Resume Next
  txtPackage.Text = strPackage
  txtClass.Text = ""
  If strPackage = "" Then Exit Property
  tvUMLProjSel.nodes(iNodePrefix_Packages & strPackage).Selected = True
  If selProject Is Nothing Then Exit Property
  Set selPackage = selProject.Packages(strPackage)
  UserControl.Parent.SetSelectedPackage selPackage
End Property

Public Property Let ProjectName(strProject As String)
  Dim i As Integer
  
  On Error Resume Next
  txtProject.Text = strProject
  txtPackage.Text = ""
  txtClass.Text = ""
  If strProject = "" Then Exit Property
  tvUMLProjSel.nodes(iNodePrefix_Projects & strProject).Selected = True
  For i = 1 To Projects.count
    If Projects(i).Name = strProject Then
        Set selProject = Projects(i)
    End If
  Next i
  UserControl.Parent.SetSelectedProject selProject
End Property

Public Property Let CanEditClass(bCanEdit As Boolean)
  txtClass.Enabled = bCanEdit
End Property

Public Property Let CanEditPackage(bCanEdit As Boolean)
  txtPackage.Enabled = bCanEdit
End Property

Public Property Let CanEditProject(bCanEdit As Boolean)
  txtProject.Enabled = bCanEdit
End Property

Public Sub PopulateProjectsList(ByVal Projects As Collection, Optional bHidePackages As Boolean, Optional bHideClasses As Boolean, Optional bHide As Boolean)
   Dim i As Long
   Dim j As Long
   Dim k As Long
   Dim nodX As Node
   Dim nodY As Node
   Dim nodZ As Node
   Dim nodRoot As Node
   Dim rtsPackage As rtsPackage
   Dim rtsClass As rtsClass
   
   On Error GoTo Error_Handler
   tvUMLProjSel.nodes.Clear
   tvUMLProjSel.Style = tvwTreelinesPlusMinusText
   bHideUpdates = bHide
   Set nodRoot = tvUMLProjSel.nodes.Add(, , "Root", "UML Projects")
   For i = 1 To Projects.count
        Set nodX = tvUMLProjSel.nodes.Add("Root", tvwChild, iNodePrefix_Projects & Projects(i).Name, Projects(i).Name)
        If Not bHidePackages Then
            For j = 1 To Projects(i).Packages.count
               Set rtsPackage = Projects(i).Packages(j)
               Set nodY = tvUMLProjSel.nodes.Add(iNodePrefix_Projects & Projects(i).Name, tvwChild, iNodePrefix_Packages & rtsPackage.Name, rtsPackage.Name)
               If Not bHideClasses Then
                    For k = 1 To rtsPackage.Classes.count
                       Set rtsClass = rtsPackage.Classes(k)
                       Set nodZ = tvUMLProjSel.nodes.Add(iNodePrefix_Packages & rtsPackage.Name, tvwChild, iNodePrefix_Classes & rtsClass.Name, rtsClass.Name)
                    Next k
                End If
            Next j
        End If
   Next i
   nodRoot.Expanded = True
  
   Exit Sub
Error_Handler:
   gMsgWnd.LogMessage "Error Populating Tree View Control. " & err.Description
   Resume Next
End Sub

Private Sub tvUMLProjSel_NodeClick(ByVal Node As MSComctlLib.Node)
  Dim strSelItem As String
  
  On Error Resume Next
  If Node Is Nothing Then Exit Sub
  
  strSelItem = Left(Node.Key, 2)
  Select Case strSelItem
    Case iNodePrefix_Projects
        Set selProject = FindProject(Node.Text)
        Set selPackage = Nothing
        Set selClass = Nothing
        txtProject.Text = selProject.Name
        txtPackage.Text = ""
        txtClass.Text = ""
        
    Case iNodePrefix_Packages
        Set selProject = FindProject(Node.Parent.Text)
        If selProject Is Nothing Then Exit Sub
        Set selPackage = FindPackage(Node.Text, selProject.Packages)
        Set selClass = Nothing
        
        txtProject.Text = selProject.Name
        txtPackage.Text = selPackage.Name
        txtClass.Text = ""
    
    Case iNodePrefix_Classes
        Set selProject = FindProject(Node.Parent.Parent.Text)
        If selProject Is Nothing Then Exit Sub
        Set selPackage = FindPackage(Node.Parent.Text, selProject.Packages)
        If selPackage Is Nothing Then Exit Sub
        Set selClass = FindClass(Node.Text, selPackage.Classes)
        
        txtProject.Text = selProject.Name
        txtPackage.Text = selPackage.Name
        txtClass.Text = selClass.Name
  
  End Select
  
  If Not bHideUpdates Then
    If Not selProject Is Nothing Then
      UserControl.Parent.SetSelectedProject selProject
    Else
      UserControl.Parent.SetSelectedProject Nothing
    End If
    
    If Not selProject Is Nothing And Not selPackage Is Nothing Then
      UserControl.Parent.SetSelectedPackage selPackage
    Else
      UserControl.Parent.SetSelectedPackage Nothing
    End If
    
    If Not selProject Is Nothing And Not selPackage Is Nothing And Not selClass Is Nothing Then
      UserControl.Parent.SetSelectedClass selClass
    Else
      UserControl.Parent.SetSelectedClass Nothing
    End If
  End If
End Sub

Private Function FindProject(strProject As String) As rtsProject
    Dim i As Integer
    
    For i = 1 To Projects.count
        If Projects(i).Name = strProject Then
            Set FindProject = Projects(i)
            Exit For
        End If
    Next i
End Function

Private Function FindPackage(strPackage As String, Packages As Collection) As rtsPackage
    Dim i As Integer
    
    For i = 1 To Packages.count
        If Packages(i).Name = strPackage Then
            Set FindPackage = Packages(i)
            Exit For
        End If
    Next i
End Function

Private Function FindClass(strClass As String, Classes As Collection) As rtsClass
    Dim i As Integer
    
    For i = 1 To Classes.count
        If Classes(i).Name = strClass Then
            Set FindClass = Classes(i)
            Exit For
        End If
    Next i
End Function

Private Function FindClassByID(strClassID As String, Classes As Collection) As rtsClass
    Dim i As Integer
    
    For i = 1 To Classes.count
        If Classes(i).Class.GUID = strClassID Then
            Set FindClassByID = Classes(i)
            Exit For
        End If
    Next i
End Function

Function GetNodeIndex(aNode As Node) As Long
  Dim aParentNode As Node
  Dim aTestNode As Node
  Dim count As Long
  Dim iRet As Long
  
  On Error Resume Next
  Set aParentNode = aNode.Parent
  If aParentNode Is Nothing Then
    GetNodeIndex = -1
    Exit Function
  End If
  
  count = aParentNode.Children
  
  Set aTestNode = aParentNode.Child
  For iRet = 0 To count - 1
    If aTestNode.Key = aNode.Key Then Exit For
    Set aTestNode = aTestNode.Next
  Next iRet
  GetNodeIndex = iRet
End Function


Private Sub UserControl_Resize()
    Dim lWidth As Long
    
    On Error Resume Next
    If bHideClassDetails Then
        frmDetails.Width = 1
        frmDetails.Visible = False
    Else
        frmDetails.Width = 2775
        frmDetails.Visible = True
    End If
    
    lWidth = UserControl.Width - frmDetails.Width - 200
    If lWidth > 0 Then tvUMLProjSel.Width = lWidth
    
    lWidth = UserControl.Height - 150
    If lWidth > 0 Then tvUMLProjSel.Height = lWidth
    frmDetails.Left = tvUMLProjSel.Width + 180
End Sub
