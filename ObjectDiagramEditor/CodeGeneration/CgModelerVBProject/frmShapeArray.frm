VERSION 5.00
Begin VB.Form frmShapeArray 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Shape Array"
   ClientHeight    =   1260
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   3900
   Icon            =   "frmShapeArray.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1260
   ScaleWidth      =   3900
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton btnApply 
      Caption         =   "Apply"
      Height          =   315
      Left            =   2700
      TabIndex        =   4
      Top             =   840
      Width           =   1095
   End
   Begin VB.TextBox txtNumArrayElements 
      Height          =   285
      Left            =   1770
      TabIndex        =   2
      Top             =   330
      Width           =   795
   End
   Begin VB.CommandButton btnOK 
      Caption         =   "OK"
      Height          =   315
      Left            =   2700
      TabIndex        =   1
      Top             =   60
      Width           =   1095
   End
   Begin VB.CommandButton btnCancel 
      Caption         =   "Cancel"
      Height          =   315
      Left            =   2700
      TabIndex        =   0
      Top             =   450
      Width           =   1095
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "Label1"
      Height          =   195
      Left            =   1170
      TabIndex        =   5
      Top             =   780
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.Label Label13 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "Number of Elements"
      Height          =   195
      Left            =   240
      TabIndex        =   3
      Top             =   360
      Width           =   1425
   End
End
Attribute VB_Name = "frmShapeArray"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'======================================================================================
'
'======================================================================================
Option Explicit

'========================================================
'
' Declarations
'
'
Private m_GeCtrl As CG
Private m_nGeID As Long
Private m_bIsDistance As Boolean
Private m_lDistance As Single
Private m_nNumOfElements As Integer

'======================================================================================
' End Declarations
'======================================================================================

'--------------------------
Public Property Set GeCtrl(obj As CG)
  Set m_GeCtrl = obj
End Property

'--------------------------
Private Sub btnApply_Click()
  Dim lVal As Single

  lVal = GetUserNumber
  SetNumArrayElements lVal
  If m_bIsDistance Then
    txtNumArrayElements.Text = m_nNumOfElements * m_lDistance
  Else
    txtNumArrayElements.Text = m_nNumOfElements
  End If
End Sub
'--------------------------
Private Function GetUserNumber() As Single
  If IsNumeric(txtNumArrayElements.Text) Then
    GetUserNumber = CSng(txtNumArrayElements.Text)
  End If
End Function

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Screen.MousePointer = vbArrow
End Sub

'--------------------------
Private Sub txtNumArrayElements_GotFocus()
  SelectAllTextControlText txtNumArrayElements
End Sub


Private Sub txtNumArrayElements_KeyPress(KeyAscii As Integer)
 ' If Not (KeyAscii = Asc(".") Or KeyAscii = vbBackspace (KeyAscii >= Asc("0") And KeyAscii <= Asc(9))) Then
  If Not (KeyAscii = 46 Or KeyAscii = 8 Or (KeyAscii >= 48 And KeyAscii <= 57)) Then
    KeyAscii = 0
  End If
  ' don't allow . when setting quantity
  If m_bIsDistance = False And KeyAscii = 46 Then
    KeyAscii = 0
  End If
End Sub

Private Sub txtNumArrayElements_LostFocus()
  If GetUserNumber < 0 Then
    txtNumArrayElements = Abs(GetUserNumber)
  End If
End Sub

'--------------------------
Private Sub btnCancel_Click()
  Unload Me
End Sub
'--------------------------
Private Sub btnOK_Click()
  If GetUserNumber <> (m_nNumOfElements * m_lDistance) Then btnApply_Click
  Unload Me
End Sub

'-----------------------------
Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
  On Error Resume Next
  Select Case KeyCode
    Case vbKeyReturn    ' pass it on
      KeyCode = 0
      btnOK_Click
    Case vbKeyEscape
      KeyCode = 0
      btnCancel_Click
    End Select
End Sub
'--------------------------
Private Sub Form_Load()
  txtNumArrayElements.Text = 0
End Sub

'--------------------------
Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
  Set m_GeCtrl = Nothing
End Sub

'--------------------------
Private Sub Form_Activate()
  On Error Resume Next
  GetGeID
  If m_nGeID = 0 Then
    btnApply.Enabled = False
    btnOK.Enabled = False
  Else
    txtNumArrayElements.SetFocus
  End If
End Sub

'--------------------------
' Also look to see if it is an array that we want to set
' the distrance rather than the number of elements
Private Sub GetGeID()
  Dim GeID As Long
  Dim nGeType As Integer
  
  On Error Resume Next
  m_nGeID = 0
  GeID = m_GeCtrl.GetFirstSelObject
  ' loop through all objects
  Do While GeID <> 0
    m_GeCtrl.CurrentPropertyID = GeID  ' move into selector
    nGeType = m_GeCtrl.ObjectType
    m_bIsDistance = False
    If nGeType = EGeObjType.UserGroup Then
      If m_GeCtrl.ShapeSetCurrent(GeID) Then
        m_nGeID = GeID
        
        Label1.Visible = False
        Label1.Caption = ""
        Label13.Caption = "Number of Elements"
        
        m_lDistance = GetSizeIncrement(GeID)
        m_nNumOfElements = m_GeCtrl.ShapeNumArrayElements
        
        txtNumArrayElements.Text = m_nNumOfElements
        If m_lDistance > 0# Then
          m_bIsDistance = True
          txtNumArrayElements.Text = m_nNumOfElements * m_lDistance
          Label1.Visible = True
          Label1.Caption = "( Increment is " & m_lDistance & " in.)"
          Label13.Caption = "Set Length (in inches)"
        End If
        Exit Do
      End If
    End If
    GeID = m_GeCtrl.GetNextSelObject(GeID)
  Loop
  m_GeCtrl.CurrentPropertyID = 0  ' reset selector
End Sub


'------------------------------
Private Function SetNumArrayElements(ByVal lVal As Single) As Single
  Dim lDist As Single
  ' set num and them return actual num
  On Error Resume Next
  If Not m_GeCtrl Is Nothing And m_nGeID > 0 Then
    If m_GeCtrl.ShapeSetCurrent(m_nGeID) Then
      m_nNumOfElements = lVal
      If m_bIsDistance = True Then
        m_nNumOfElements = CInt(lVal * (1# / m_lDistance))
        ' Note this sets the undo buffer as well
        m_GeCtrl.ShapeNumArrayElements = m_nNumOfElements
        SetNumArrayElements = lVal
      Else
        ' Note this sets the undo buffer as well
        m_GeCtrl.ShapeNumArrayElements = lVal
        SetNumArrayElements = lVal
      End If
     
    End If
    m_GeCtrl.ShapeSetCurrent 0      ' reset selector
    
    ' want to cuase as selection change to update toolpanel
    m_GeCtrl.SelRemoveAll
    m_GeCtrl.SelAdd m_nGeID
    
  End If
End Function

' if this returs a value other than 0 then it is a distance array. The returned
' value is the size increment
Private Function GetSizeIncrement(GeID As Long) As Single
  Dim i As Integer
  Dim j As Integer
  Dim nCount As Integer

  GetSizeIncrement = 0#
  ' look for field with tag 'description', if found get size
  ' then set up dialog to ask user for distance, not quantity
  nCount = m_GeCtrl.ShapeFieldCount
  Dim strName As String, strVal As String
  Dim nGeIDA As Long

  If nCount > 0 Then
    For j = 0 To nCount - 1
      m_GeCtrl.ShapeSetCurrentField (j)
      If m_GeCtrl.ShapeSetCurrentField(j) Then
        If m_GeCtrl.ShapeGetFieldType = 1 Then
          m_GeCtrl.ShapeGetFieldNameValue strName, strVal
          If InStr(strName, "imension") > 0 Then    ' Real string is "Dimension"
            GetSizeIncrement = CSng(strVal)
          End If
        End If
      End If
    Next j
  End If
  ' reset ID
  m_GeCtrl.ShapeSetCurrent (GeID)

End Function

