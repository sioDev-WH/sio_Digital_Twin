VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Begin VB.Form frmAttribAndOperProperties 
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Properties"
   ClientHeight    =   1365
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   4470
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1365
   ScaleWidth      =   4470
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin MSComDlg.CommonDialog CommonDialog 
      Left            =   2940
      Top             =   960
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "OK"
      Height          =   375
      Left            =   3480
      TabIndex        =   7
      Top             =   120
      Width           =   915
   End
   Begin VB.CommandButton btnCancel 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   3480
      TabIndex        =   6
      Top             =   600
      Width           =   915
   End
   Begin VB.ComboBox cmbType 
      Height          =   315
      Left            =   960
      TabIndex        =   5
      Top             =   540
      Width           =   2175
   End
   Begin VB.CheckBox chkSim 
      Caption         =   "Check1"
      Height          =   255
      Left            =   960
      TabIndex        =   2
      Top             =   1020
      Width           =   195
   End
   Begin VB.Label Label2 
      Alignment       =   1  'Right Justify
      Caption         =   "Type:"
      Height          =   195
      Left            =   240
      TabIndex        =   4
      Top             =   600
      Width           =   675
   End
   Begin VB.Label lbSim 
      Alignment       =   1  'Right Justify
      Caption         =   "Simulation:"
      Height          =   195
      Left            =   0
      TabIndex        =   3
      Top             =   1020
      Width           =   915
   End
   Begin VB.Label lbAttributeOrOperName 
      Caption         =   "Label1"
      Height          =   195
      Left            =   1020
      TabIndex        =   1
      Top             =   180
      Width           =   2295
   End
   Begin VB.Label lbAttribOrOper 
      Alignment       =   1  'Right Justify
      Caption         =   "Attribute: "
      Height          =   195
      Left            =   300
      TabIndex        =   0
      Top             =   180
      Width           =   675
   End
End
Attribute VB_Name = "frmAttribAndOperProperties"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private aOper As CgOperation
Private aAttr As CgAttribute
Private bAttribute As Boolean

Private sTypeOld As Integer
Private bSimOld As Boolean

Public Property Set Attrib(ByRef aAttrib As CgAttribute)
  Set aAttr = aAttrib
  bAttribute = True
End Property

Public Property Set Oper(ByRef aOperation As CgOperation)
  Set aOper = aOperation
  bAttribute = False
End Property

Public Property Get AttributeChanged() As Boolean
    If bAttribute Then
        If aAttr Is Nothing Then
            AttributeChanged = False
            Exit Property
        End If
        If aAttr.sType = sTypeOld And aAttr.bSim = bSimOld Then
            AttributeChanged = False
        Else
            AttributeChanged = True
        End If
    End If
End Property

Private Sub btnCancel_Click()
    Unload Me
End Sub

Private Sub btnOK_Click()
    'Commit Changes
    On Error GoTo Error_Handler
    If bAttribute And aAttr Is Nothing Then
        gMsgWnd.LogMessage "Failed to save property attribute information."
        Unload Me
        Exit Sub
    ElseIf Not bAttribute And aOper Is Nothing Then
        gMsgWnd.LogMessage "Failed to save property operation information."
        Unload Me
        Exit Sub
    End If
    
    If bAttribute Then      'Save Attribute information
        aAttr.sType = cmbType.ListIndex
        aAttr.bSim = chkSim.Value
    Else                    'Save Operation information
        aOper.sType = cmbType.ListIndex
        aOper.bSim = chkSim.Value
    End If
    
    Unload Me
    Exit Sub
Error_Handler:
    gMsgWnd.LogMessage " Failed to save property information: " & err.Description
    Unload Me
End Sub

Private Sub Form_Load()

    If bAttribute Then
        cmbType.AddItem szAttr_Undefined, idxAttr_Undefined
        cmbType.AddItem szAttr_Variable, idxAttr_Variable
        cmbType.AddItem szAttr_Parameter, idxAttr_Parameter
        cmbType.AddItem szAttr_Connector, idxAttr_Connector
        cmbType.AddItem szAttr_Model, idxAttr_Model
        cmbType.AddItem szAttr_Struct, idxAttr_Struct
        cmbType.AddItem szAttr_Broadcaster, idxAttr_Broadcaster
        cmbType.AddItem szAttr_Listener, idxAttr_Listener
        cmbType.AddItem szAttr_DataCollector, idxAttr_DataCollector
        cmbType.AddItem szAttr_Input, idxAttr_Input
        cmbType.AddItem szAttr_Output, idxAttr_Output
        InitAttributeDialog
    Else
        cmbType.AddItem szOper_Undefined, idxOper_Undefined
        cmbType.AddItem szOper_Continuous, idxOper_Continuous
        cmbType.AddItem szOper_Discontinuous, idxOper_Discontinuous
        cmbType.AddItem szOper_Reset, idxOper_Reset
        cmbType.AddItem szOper_Get, idxOper_Get
        cmbType.AddItem szOper_Set, idxOper_Set
        InitOperationDialog
    End If
End Sub

Private Sub InitAttributeDialog()
    On Error GoTo Error_Handler
    If aAttr Is Nothing Then
        gMsgWnd.LogMessage "Failed to initialize Attribute Properties dialog."
        Unload Me
        Exit Sub
    End If
    lbAttributeOrOperName.Caption = aAttr.Name
    chkSim.Value = IIf(aAttr.bSim = True, 1, 0)
    cmbType.ListIndex = aAttr.sType
                    
    sTypeOld = aAttr.sType
    bSimOld = aAttr.bSim
    Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Error initializing Attribute properties dialog: " & err.Description
    Unload Me
End Sub

Private Sub InitOperationDialog()
    On Error GoTo Error_Handler
    If aOper Is Nothing Then
        gMsgWnd.LogMessage "Failed to initialize Operation Properties dialog."
        Unload Me
        Exit Sub
    End If
    
    lbAttribOrOper.Caption = aOper.Name
    chkSim.Value = aOper.bSim
    cmbType.ListIndex = aOper.sType
            
    sTypeOld = aOper.sType
    bSimOld = aOper.bSim
    Exit Sub
Error_Handler:
    gMsgWnd.LogMessage "Error initializing Attribute properties dialog: " & err.Description
    Unload Me
End Sub
