VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Begin VB.Form frmIntegrationCg 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Integration Test Harness Wizard"
   ClientHeight    =   8400
   ClientLeft      =   7650
   ClientTop       =   6300
   ClientWidth     =   8340
   Icon            =   "frmIntegrationCg.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   8400
   ScaleWidth      =   8340
   StartUpPosition =   1  'CenterOwner
   Begin VB.Frame Frame2 
      Caption         =   "Application Model Selection"
      Height          =   5115
      Left            =   60
      TabIndex        =   3
      Top             =   3240
      Width           =   6735
      Begin VB.CheckBox chkGenSubSystem 
         Height          =   255
         Left            =   5400
         TabIndex        =   22
         Top             =   3900
         Value           =   1  'Checked
         Width           =   255
      End
      Begin VB.CheckBox chkGenTasks 
         Enabled         =   0   'False
         Height          =   255
         Left            =   5400
         TabIndex        =   21
         Top             =   3480
         Value           =   1  'Checked
         Width           =   255
      End
      Begin VB.CheckBox chkGenApp 
         Enabled         =   0   'False
         Height          =   255
         Left            =   5400
         TabIndex        =   20
         Top             =   3060
         Value           =   1  'Checked
         Width           =   255
      End
      Begin VB.CheckBox chViewDetails 
         Caption         =   "View Class Details"
         Height          =   255
         Left            =   2220
         TabIndex        =   19
         Top             =   4740
         Value           =   1  'Checked
         Width           =   2415
      End
      Begin VB.CommandButton btnSetSubsystemName 
         Caption         =   "Set"
         Height          =   315
         Left            =   5760
         TabIndex        =   18
         Top             =   3900
         Width           =   795
      End
      Begin VB.CommandButton btnSetRootName 
         Caption         =   "Set"
         Height          =   315
         Left            =   5760
         TabIndex        =   17
         Top             =   3480
         Width           =   795
      End
      Begin VB.CommandButton btnSetAppName 
         Caption         =   "Set"
         Height          =   315
         Left            =   5760
         TabIndex        =   16
         Top             =   3060
         Width           =   795
      End
      Begin CGModeler.ucUMLTreeView ucUMLTreeViewIntegration 
         Height          =   2595
         Left            =   180
         TabIndex        =   15
         Top             =   240
         Width           =   6495
         _extentx        =   11033
         _extenty        =   4577
      End
      Begin VB.CheckBox chkMaxStepSize 
         Caption         =   "Set max step size"
         Height          =   255
         Left            =   3060
         TabIndex        =   11
         Top             =   4380
         Width           =   1695
      End
      Begin VB.TextBox txtMaxStepSize 
         Height          =   285
         Left            =   2220
         TabIndex        =   10
         Text            =   "1.0e-3"
         Top             =   4320
         Width           =   735
      End
      Begin VB.TextBox txtIntPhysicalSubsystemName 
         Height          =   315
         Left            =   2220
         TabIndex        =   6
         Top             =   3900
         Width           =   3135
      End
      Begin VB.TextBox txtIntTaskRootName 
         Height          =   315
         Left            =   2220
         TabIndex        =   5
         Top             =   3480
         Width           =   3135
      End
      Begin VB.TextBox txtIntAppName 
         Height          =   315
         Left            =   2220
         TabIndex        =   4
         Top             =   3060
         Width           =   3135
      End
      Begin VB.Label Label4 
         Alignment       =   1  'Right Justify
         Caption         =   "Step Size:"
         Height          =   315
         Left            =   1200
         TabIndex        =   12
         Top             =   4320
         Width           =   975
      End
      Begin VB.Label Label5 
         Alignment       =   1  'Right Justify
         Caption         =   "Physical subsystem name:"
         Height          =   375
         Left            =   240
         TabIndex        =   9
         Top             =   3900
         Width           =   1935
      End
      Begin VB.Label Label1 
         Alignment       =   1  'Right Justify
         Caption         =   "Root name for tasks:"
         Height          =   375
         Left            =   240
         TabIndex        =   8
         Top             =   3480
         Width           =   1935
      End
      Begin VB.Label Label3 
         Alignment       =   1  'Right Justify
         Caption         =   "Application class name:"
         Height          =   375
         Left            =   240
         TabIndex        =   7
         Top             =   3060
         Width           =   1935
      End
   End
   Begin VB.CommandButton btnExit 
      Caption         =   "Exit"
      Height          =   375
      Left            =   6840
      TabIndex        =   2
      Top             =   1200
      Width           =   1455
   End
   Begin VB.CommandButton btnSaveProject 
      Caption         =   "Save Project"
      Height          =   375
      Left            =   6840
      TabIndex        =   1
      Top             =   720
      Width           =   1455
   End
   Begin MSComDlg.CommonDialog CommDlg 
      Left            =   7200
      Top             =   1860
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton btnCodeGeneration 
      Caption         =   "Generate Classes"
      Height          =   375
      Left            =   6840
      TabIndex        =   0
      Top             =   240
      Width           =   1455
   End
   Begin CGModeler.ucUMLTreeView ucUMLTreeViewComposite 
      Height          =   2595
      Left            =   180
      TabIndex        =   13
      Top             =   360
      Width           =   6495
      _extentx        =   11033
      _extenty        =   4577
   End
   Begin VB.Frame frmProjectSelection 
      Caption         =   "Physical Model Selection"
      Height          =   3015
      Left            =   60
      TabIndex        =   14
      Top             =   120
      Width           =   6735
   End
End
Attribute VB_Name = "frmIntegrationCg"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public WithEvents m_GeCtrl As CG
Attribute m_GeCtrl.VB_VarHelpID = -1
Public m_UDIDefMgr As UDIDefMgr

Private m_Projects As Object
Private IntegrationProject As rtsProject
Private IntegrationPackage As rtsPackage
Private IntegrationClass As rtsClass

Private CompositeMdodelProject As rtsProject
Private CompositeModelPackage As rtsPackage
Private CompositeModelClass As rtsClass

' the following are used locally
Public m_UDIs As Collection
Public m_ConnectionInfo As Collection
Private m_bErr As Boolean
Private currTreeViewName As String


' The following three properties are used by the ucUMLTreeView control
' to set the currently selected project\package\class

Public Sub SetSelectedProject(selProject As rtsProject)
    On Error Resume Next
    If selProject Is Nothing Then Exit Sub
    If currTreeViewName = ucUMLTreeViewComposite.Name Then
        Set CompositeMdodelProject = selProject
    Else
        Set IntegrationProject = selProject
    End If
End Sub

Public Sub SetSelectedPackage(selPackage As rtsPackage)
    On Error Resume Next
    If selPackage Is Nothing Then Exit Sub
    If currTreeViewName = ucUMLTreeViewComposite.Name Then
        Set CompositeModelPackage = selPackage
    Else
        Set IntegrationPackage = selPackage
    End If
End Sub

Public Sub SetSelectedClass(selClass As rtsClass)
    On Error Resume Next
    If selClass Is Nothing Then Exit Sub
    If currTreeViewName = ucUMLTreeViewComposite.Name Then
        Set CompositeModelClass = selClass
    Else
        Set IntegrationClass = selClass
    End If
End Sub


' KAB June 8, 2003 --> Added 3 check boxes for App, Tasks, and Subsystem, making it optional whether they
'                      are generated.  The main reason for this was to make it possible to generate a
'                      application that didn't have a physical subsystem.  The simple transmission case
'                      fit this category.
Private Sub btnCodeGeneration_Click()
  Dim szIntAppName As String
  Dim szIntPhysicalSubsystemName As String
  Dim szIntTaskRootName As String
  Dim bMaxStepSize As Boolean
  Dim maxStepSize As Double
  Dim ModelExecClass As rtsClass
  Dim bSuccess As Boolean
  Dim taskClasses As Collection
  Dim strNames
  
  Dim bGenApp As Boolean
  Dim bGenTasks As Boolean
  Dim bGenSubsystem As Boolean
  
  On Error GoTo Error_Handler
 
  szIntAppName = txtIntAppName.Text
  szIntPhysicalSubsystemName = txtIntPhysicalSubsystemName.Text
  'In case this is an existing root name, strip off the _task part
  szIntTaskRootName = ""
  strNames = Split(txtIntTaskRootName.Text, "_task")
  If UBound(strNames) >= 0 Then szIntTaskRootName = strNames(0)
  
  bMaxStepSize = chkMaxStepSize.Value = Checked
  If IsNumeric(txtMaxStepSize.Text) Then
    maxStepSize = CDbl(txtMaxStepSize.Text)
  End If
  
  bGenApp = (chkGenApp.Value = Checked)
  bGenTasks = (chkGenTasks.Value = Checked)
  bGenSubsystem = (chkGenSubSystem.Value = Checked)
  
  If (Len(szIntAppName) > 0 Or Not bGenApp) And _
     (Len(szIntTaskRootName) > 0 Or Not bGenTasks) And _
     ((Len(szIntPhysicalSubsystemName) > 0 And _
      Not IntegrationPackage Is Nothing And _
      Not CompositeModelPackage Is Nothing And _
      Not CompositeModelClass Is Nothing) Or Not bGenSubsystem) Then
    
    If bGenSubsystem Then
      bSuccess = GetIntegrationModelExecCgObjects( _
        IntegrationProject, _
        IntegrationPackage, _
        CompositeModelPackage, _
        CompositeModelClass, _
        szIntAppName, _
        szIntPhysicalSubsystemName, _
        szIntTaskRootName, _
        m_UDIs, _
        bMaxStepSize, _
        maxStepSize, _
        chViewDetails.Value)
    Else
      ' GetIntegrationModelExecCgObjects() would normally initialize the UDI class references,
      ' so they have to be initialized here.
      Call InitializeUDIClasses(IntegrationProject, m_UDIDefMgr, m_UDIs)
      bSuccess = True
    End If
    
    If bSuccess Then
      bSuccess = GetIntegrationTaskCgObjects( _
        IntegrationProject, _
        IntegrationPackage, _
        CompositeModelPackage, _
        CompositeModelClass, _
        szIntAppName, _
        szIntPhysicalSubsystemName, _
        szIntTaskRootName, _
        m_UDIs, _
        m_UDIDefMgr, _
        m_ConnectionInfo, _
        chViewDetails.Value, _
        bGenApp, _
        bGenTasks, _
        bGenSubsystem)
    End If
    
    If bSuccess Then
      gMsgWnd.LogMessage "Integration class generation complete."
    Else
      gMsgWnd.LogMessage "Integration class generation failed."
    End If
  Else
    MsgBox "Please complete all selections.", vbInformation
  End If

Exit Sub
Error_Handler:
  gMsgWnd.LogMessage "Integration Wizard code generation error: " & err.Description

End Sub

Private Sub btnExit_Click()
    Unload Me
End Sub

Private Sub btnSaveProject_Click()
  On Error GoTo Error_Handler
  If Not doc Is Nothing Then
    If Not doc.activeProject Is Nothing Then
      doc.activeProject.Save
    End If
  End If
  Exit Sub
    
Error_Handler:
  gMsgWnd.LogMessage "Error saving UML project. " & err.Description
End Sub

Private Sub btnSetAppName_Click()
  If Not IntegrationClass Is Nothing Then
    txtIntAppName.Text = IntegrationClass.Name
  End If
End Sub

Private Sub btnSetRootName_Click()
  If Not IntegrationClass Is Nothing Then
    txtIntTaskRootName.Text = IntegrationClass.Name
  End If
End Sub

Private Sub btnSetSubsystemName_Click()
  If Not IntegrationClass Is Nothing Then
    txtIntPhysicalSubsystemName.Text = IntegrationClass.Name
  End If
End Sub

Private Sub Form_Load()
  On Error GoTo Error_Handler
  
  If Projects Is Nothing Then
     GetProjects Projects, m_Projects, CommDlg
     If Not g_DrawingDefMgr.LoadModelDef() Then
         gMsgWnd.LogMessage "Error loading xml model definition"
     End If
  Else
    If Projects.count = 0 Then
       GetProjects Projects, m_Projects, CommDlg
        If Not g_DrawingDefMgr.LoadModelDef() Then
            gMsgWnd.LogMessage "Error loading xml model definition"
        End If
    End If
  End If
  
  If Projects.count = 0 Then
    MsgBox "No UML project selected.  Unable to load any projects"
    Unload Me
  End If
  
  'Populate the UML project selection control
  If Projects.count > 0 Then
    ucUMLTreeViewComposite.PopulateProjectsList Projects
    ucUMLTreeViewIntegration.PopulateProjectsList Projects
    ucUMLTreeViewIntegration.HideClass
  End If
  
  GetUDIInfo
  GetConnectionInfo
  
  If m_bErr Then
    Unload Me
  End If
  
  Exit Sub
Error_Handler:
  gMsgWnd.LogMessage "Error loading integration wizard: " & err.Description
  Unload Me
End Sub


Private Sub GetUDIInfo()
  Dim aUDI As UserDefinedItem
  Dim var As Variant
  Dim i As Long
  Dim lBnd As Long
  Dim uBnd As Long
  
  Set m_UDIs = New Collection
  m_GeCtrl.SelAllWithVariants
  m_GeCtrl.SelGetObjectVariants var
  
  If IsEmpty(var) Then
    Exit Sub
  End If
  
  On Error GoTo Error_Handler
  lBnd = LBound(var)
  uBnd = UBound(var)
  
  For i = lBnd To uBnd
    Set aUDI = Nothing
    Set aUDI = var(i)
    If aUDI Is Nothing Then
      m_bErr = True
      gMsgWnd.LogMessage "Invalid model detected.  Test models through the model properties dialog.  Replace problem model."
    Else
      m_UDIs.Add aUDI, aUDI.ObjectName
    End If
  Next i
  
  Exit Sub
Error_Handler:
  m_bErr = True
  If err.Number = 457 Then
    gMsgWnd.LogMessage "Objects exist with duplicate names '" & aUDI.ObjectName & "'.  Resolve the duplicate name and try again."
  Else
    gMsgWnd.LogMessage "Error detected while retrieving model properties: " & err.Number & ", " & err.Description
  End If
End Sub

Private Sub GetConnectionInfo()
  Set m_ConnectionInfo = New Collection
  m_GeCtrl.EnumConnectionLines
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, y As Single)
    Screen.MousePointer = vbArrow
End Sub

Private Sub Form_Unload(Cancel As Integer)
    If Not m_GeCtrl Is Nothing Then
        m_GeCtrl.SelRemoveAll
        m_GeCtrl.Redraw
    End If
End Sub

Private Sub m_GeCtrl_ConnectionChanged(ByVal Action As Integer, ByVal IDLine As Long, ByVal IDA As Long, ByVal VarA As Variant, ByVal NameA As String, ByVal TypeA As Integer, ByVal StsA As Integer, ByVal IDB As Long, ByVal VarB As Variant, ByVal NameB As String, ByVal TypeB As Integer, ByVal StsB As Integer)
  Dim aInfo As ConnectionInfo
  
  On Error Resume Next
  Set aInfo = New ConnectionInfo
  aInfo.Action = Action
  aInfo.IDLine = IDLine
  aInfo.IDA = IDA
  If Not IsEmpty(VarA) Then
    If IsObject(VarA) Then
      Set aInfo.VarA = VarA
      Set aInfo.ObjA = VarA
    Else
      aInfo.VarA = VarA
    End If
  End If
  aInfo.NameA = NameA
  aInfo.TypeA = TypeA
  aInfo.StsA = StsA
  aInfo.IDB = IDB
  If Not IsEmpty(VarB) Then
    If IsObject(VarB) Then
      Set aInfo.VarB = VarB
      Set aInfo.ObjB = VarB
    Else
      aInfo.VarB = VarB
    End If
  End If
  aInfo.NameB = NameB
  aInfo.TypeB = TypeB
  aInfo.StsB = StsB
  
  If aInfo.ObjA Is Nothing Or aInfo.ObjB Is Nothing Then
    m_bErr = True
    If Not aInfo.ObjA Is Nothing Then
      gMsgWnd.LogMessage "Connection line starting at '" & aInfo.ObjA.ObjectName & "' is not connected"
    ElseIf Not aInfo.ObjB Is Nothing Then
      gMsgWnd.LogMessage "Connection line ending at '" & aInfo.ObjB.ObjectName & "' is not connected"
    Else
      gMsgWnd.LogMessage "Connection line is not connected"
    End If
  Else
    m_ConnectionInfo.Add aInfo
  End If

End Sub

Private Sub ucUMLTreeViewComposite_GotFocus()
    currTreeViewName = ucUMLTreeViewComposite.Name
End Sub

Private Sub ucUMLTreeViewIntegration_GotFocus()
    currTreeViewName = ucUMLTreeViewIntegration.Name
End Sub
