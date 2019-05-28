VERSION 5.00
Begin VB.UserControl GERollup 
   Alignable       =   -1  'True
   Appearance      =   0  'Flat
   BackColor       =   &H80000004&
   ClientHeight    =   5010
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   2445
   ControlContainer=   -1  'True
   KeyPreview      =   -1  'True
   ScaleHeight     =   5010
   ScaleWidth      =   2445
   ToolboxBitmap   =   "GERollup.ctx":0000
   Begin VB.PictureBox picDragger 
      AutoRedraw      =   -1  'True
      BackColor       =   &H0000FF00&
      BorderStyle     =   0  'None
      Height          =   3615
      Left            =   180
      MouseIcon       =   "GERollup.ctx":0312
      MousePointer    =   99  'Custom
      ScaleHeight     =   3615
      ScaleWidth      =   75
      TabIndex        =   0
      ToolTipText     =   "Drag to resize"
      Top             =   570
      Width           =   70
   End
   Begin VB.Label cmdMenu 
      Alignment       =   2  'Center
      BackColor       =   &H80000002&
      Caption         =   "Text goes here"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000009&
      Height          =   285
      Left            =   0
      MouseIcon       =   "GERollup.ctx":0464
      MousePointer    =   99  'Custom
      TabIndex        =   1
      ToolTipText     =   "Click to Hide"
      Top             =   30
      Width           =   2775
   End
End
Attribute VB_Name = "GERollup"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'PBH - NOTE This code will only work for left or right alignment.
'
Option Explicit
Option Compare Text

' general local constants
Private Const ERR_INV_PROP_VALUE    As Long = 380&          'standard vb error

' color constants
Private Const COLOR_BTN_FACE        As Long = &H8000000F    'button face color
Private Const COLOR_BACK            As Long = &H80000002    'active title bar color
Private Const COLOR_FORE            As Long = &H80000009    'title bar caption

' default property value constants
Private Const DEF_CAPTION           As String = "ToolBox"   'default title bar caption

' local property variables
Private mvarAlignMode               As VBRUN.AlignConstants
Private mvarIcon                    As Long         'indicates current icon resource id
Private mvarCaption                 As String       'Caption property local var
Private mvarBackColor               As OLE_COLOR    'local copy
Private mvarForeColor               As OLE_COLOR    'local copy
Private m_nTitleHeight              As Integer
Private m_nRolledOutWidth           As Integer
Private m_nRolledUpWidth            As Integer

' state variables
Private mvarRolledUp                As Boolean      'flag to indicate in rolled up state
Private mvarWidthAtRollup           As Single       'width  restored from rollup
Private mvarHeightAtRollup          As Single       'height restored from rollup
Private mvarPropertyInit            As Boolean      'flag indicating property bag was read

' Drawing API Declarations
' used for printing text at unusual angles
Private Declare Function SelectObject Lib "gdi32" ( _
         ByVal hDC As Long, _
         ByVal hObject As Long) _
         As Long

' event declarations
Event UserRollup(Cancel As Boolean)     ' fired at rollup
Event UserUnroll(Cancel As Boolean)     ' fired when unrolling
'Default Property Values:
Const m_def_ExtraWidth = 0
Const m_def_Align = 0
'Property Variables:
Dim m_ExtraWidth As Variant      'size of extra width to always show (tools)
Dim m_Align As Integer

Private m_ucToolPanel As ucToolPanel

'************************************************************************
'************************************************************************
Public Property Set ToolPanel(obj As ucToolPanel)
  On Error Resume Next
  Set m_ucToolPanel = obj

End Property
'--------------------------
Public Property Get ToolPanel() As ucToolPanel
  Set ToolPanel = m_ucToolPanel
End Property
''

Private Property Let CurrentAlign(NewAlign As VBRUN.AlignConstants)
' sets DragBar property to Vertical or Horizontal depending on the align
  mvarAlignMode = NewAlign
End Property

Private Property Get CurrentAlign() As VBRUN.AlignConstants
  mvarAlignMode = UserControl.Extender.Align
  ' did this because Extender object
  ' returns 0 every time while _THIS_ project is in the IDE :(
  If mvarAlignMode = 0 Then
    mvarAlignMode = vbAlignLeft
  End If
  ' return the property read from the Extender object
  ' NEVER cache this property value
  CurrentAlign = mvarAlignMode
End Property

Public Property Let Caption(vData As String)
Attribute Caption.VB_Description = "Sets/returns title bar caption."
  ' this caption appears at the top and remains visible when "Rolled" up
  If mvarCaption = vData Then Exit Property
  
  mvarCaption = vData
  cmdMenu.Caption = mvarCaption
  PropertyChanged "Caption"
End Property

Public Property Get Caption() As String
  Caption = mvarCaption
End Property


Private Sub PrintHorizontal(ByVal TextToPrint As String, LeftSide As Boolean)
' used to keep the horizontal caption on the title bar whenever the align
' is left or right and the control is "rolled up"
Dim fnt     As CLogicalFont     ' object variable
Dim sngY    As Single           ' current Y placeholder
Dim sngX    As Single           ' current X placeholder
Dim hFont   As Long             ' handle to a font object
  
  ' we probably resized, so erase the current text and center it again
  picDragger.Cls
  ' set the picture box font to match the menu font
  Set picDragger.Font = cmdMenu.Font
  ' we use the CLogicalFont class to rotate  text
  Set fnt = New CLogicalFont
  ' this needs to be a property
  picDragger.ForeColor = mvarForeColor
  ' set the CLogicalFont to use our font
  Set fnt.LOGFONT = picDragger.Font
  ' the rotation is:
  '   vbAlignLeft     90  degrees
  '   vbAlignRight    270 degrees
  If LeftSide Then
      fnt.Rotation = 90
  Else
      fnt.Rotation = 270
  End If
  
  If LeftSide Then
      ' set current y to middle -(lenght of text /2)
      sngY = (picDragger.Height / 2) + (picDragger.TextWidth(TextToPrint) / 2)
      ' set currentx to half of width ( half of text height)
      sngX = (picDragger.Width / 2) - (picDragger.TextHeight(TextToPrint) / 2)
  Else
      ' set current y to middle -(lenght of text /2)
      sngY = (picDragger.Height / 2) - (picDragger.TextWidth(TextToPrint) / 2)
      ' set currentx to half of width ( half of text height)
      sngX = (picDragger.Width / 2) + (picDragger.TextHeight(TextToPrint) / 2) + 10
  End If

  With picDragger
      ' select the object with the handle to our logical font
      hFont = SelectObject(.hDC, fnt.Handle)
      ' set our coordinates for printing
      .CurrentX = sngX
      .CurrentY = sngY
      ' print the text
      picDragger.Print TextToPrint
      ' select the object again
      Call SelectObject(.hDC, hFont)
  End With
  
  ' turn on AutoRedraw so we re-paint whenever
  ' the control is covered by another window
  picDragger.AutoRedraw = True
  
  ' release instance of CLogicalFont
  Set fnt = Nothing
End Sub

Private Sub cmdMenu_Click()
  If mvarRolledUp Then
    UserRestore
  Else
    UserRoll
  End If
  Call UserControl_Paint
End Sub


Private Sub picDragger_Click()
  ' causes the control to unroll
  If mvarRolledUp Then UserRestore
  Call UserControl_Paint
End Sub


Private Sub UserControl_InitProperties()
  ' User Control events fire in this order when
  ' the control is first placed on a form:
  '   UserControl_Initialize
  '   UserControl_InitProperties
  '   UserControl_Resize
  '   UserControl_Resize
  '   UserControl_Show
  '   UserControl_Paint
  
  ' subsequently:
  '   UserControl_Initialize
  '   UserControl_Resize
  '   UserControl_ReadProperties
  '   UserControl_Show
  '   UserControl_Paint
  
  ' method calls during the event procedures
  ' can affect the order of events...
  mvarRolledUp = False
  mvarAlignMode = vbAlignLeft
  m_Align = m_def_Align
  m_ExtraWidth = m_def_ExtraWidth
End Sub

Private Sub UserControl_Paint()
  If mvarRolledUp Then
    Select Case CurrentAlign
      Case vbAlignLeft
        picDragger.BackColor = mvarBackColor
        PrintHorizontal cmdMenu.Caption, True
      Case vbAlignRight
        picDragger.BackColor = mvarBackColor
        PrintHorizontal cmdMenu.Caption, False
    End Select
    picDragger.ZOrder 0
  End If
End Sub

Private Sub UserControl_Resize()
  Dim sngWidth            As Single       ' width  of control at procedure entry
  Dim sngHeight           As Single       ' height of control at procedure entry
  Static blnRecursive     As Boolean      ' flag to prevent recursive loops
  
  ' read properties at procedure entry to prevent
  ' repeated calls to property procedures
  On Local Error Resume Next

  Select Case CurrentAlign
    Case vbAlignLeft
      picDragger.Top = 0
      picDragger.Height = UserControl.Extender.Height
'      picDragger.Left = m_nRolledOutWidth - picDragger.Width
      picDragger.Left = 0 ' UserControl.Extender.Width - picDragger.Width
      
      picDragger.ZOrder 0
      Call UserControl_Paint
      
      If mvarRolledUp Then Exit Sub
      
      picDragger.Width = 0
    
    Case vbAlignRight
      picDragger.Top = 0
      picDragger.Height = UserControl.Extender.Height
      picDragger.Left = 0
      picDragger.ZOrder 0
      Call UserControl_Paint
      
      If mvarRolledUp Then Exit Sub
              
      picDragger.Width = 0
      cmdMenu.Left = 0
  End Select

  cmdMenu.Width = UserControl.Extender.Width
  mvarWidthAtRollup = UserControl.Extender.Width + m_ExtraWidth
  mvarHeightAtRollup = UserControl.Extender.Height
End Sub

Private Sub UserControl_Show()
  Call UserControl_Resize
End Sub

Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    'Load property values from storage
    mvarPropertyInit = True
    mvarBackColor = PropBag.ReadProperty("BackColor", COLOR_BACK)
    cmdMenu.BackColor = mvarBackColor
    
    mvarForeColor = PropBag.ReadProperty("ForeColor", vbWhite)
    cmdMenu.ForeColor = mvarForeColor
    mvarCaption = PropBag.ReadProperty("Caption", DEF_CAPTION)
    cmdMenu.Caption = mvarCaption
    
    ' this is a good place to read alignmode property
    ' since the Extender object will always be available when
    ' UserControl_ReadProperties is called
    ' remember that the Extender object will probably return
    ' a bogus value while you step through this
    ' kinda rude Microsoft!
    CurrentAlign = UserControl.Extender.Align
    
    ' use the private propert procedure to ensure
    ' we don't get "Invalid property value" that can be
    ' generated by us in the Public property procedure
    ' calling this procedure will eliminate references to
    ' controls which no longer exist
  m_Align = PropBag.ReadProperty("Align", m_def_Align)
  m_ExtraWidth = PropBag.ReadProperty("ExtraWidth", m_def_ExtraWidth)
End Sub

'Write property values to storage
Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
  Call PropBag.WriteProperty("Caption", mvarCaption, DEF_CAPTION)
  Call PropBag.WriteProperty("lblLeft", picDragger.Left)
  Call PropBag.WriteProperty("BackColor", cmdMenu.BackColor, COLOR_BACK)
  Call PropBag.WriteProperty("Align", m_Align, m_def_Align)
  Call PropBag.WriteProperty("ExtraWidth", m_ExtraWidth, m_def_ExtraWidth)
End Sub

Public Property Get CurrentWidth() As Single
  InitSize
  If mvarRolledUp = False Then
    CurrentWidth = m_nRolledOutWidth
  Else
    CurrentWidth = m_nRolledUpWidth
  End If
End Property

Public Property Get CurrentHeight() As Single
  InitSize
  CurrentHeight = UserControl.Extender.Height
End Property

Public Property Get RolledUp() As Boolean
Attribute RolledUp.VB_Description = "Returns True if the control is currently rolled up."
  RolledUp = mvarRolledUp
End Property

Private Sub InitSize()
  ' this only has to be done once
  If m_nTitleHeight < 1 Then
    m_nTitleHeight = cmdMenu.Height
  End If
  If m_nRolledOutWidth < 1 Then
    m_nRolledOutWidth = UserControl.Width + m_ExtraWidth
  End If
  If m_nRolledUpWidth < 1 Then
    m_nRolledUpWidth = m_nTitleHeight + m_ExtraWidth
  End If
End Sub


Public Sub Rollup()
  InitSize
  ' need to cache our current size(s)  for restore
  ' call CurrentSize to read the appropriate value
  mvarWidthAtRollup = m_nRolledOutWidth   'UserControl.Extender.Width
  mvarHeightAtRollup = UserControl.Extender.Height
  
  mvarAlignMode = CurrentAlign
  
  Select Case mvarAlignMode
    Case vbAlignLeft
      picDragger.MousePointer = vbCustom
      picDragger.BackColor = mvarBackColor
      picDragger.ForeColor = mvarForeColor
      picDragger.ZOrder 0
      mvarRolledUp = True
      UserControl.Width = m_nRolledUpWidth 'cmdMenu.Height + m_ExtraWidth
      
      picDragger.Left = 0
      picDragger.ToolTipText = "Click to restore"
      picDragger.Width = m_nTitleHeight 'cmdMenu.Height
      PrintHorizontal cmdMenu.Caption, True
    Case vbAlignRight
      picDragger.BackColor = mvarBackColor
      picDragger.ZOrder 0
      mvarRolledUp = True
      UserControl.Width = m_nRolledUpWidth  'cmdMenu.Height
      
      picDragger.Width = m_nTitleHeight 'cmdMenu.Height
      picDragger.Height = UserControl.Extender.Height
      picDragger.Left = m_nRolledUpWidth - m_nTitleHeight '0
      picDragger.ToolTipText = "Click to restore"
      PrintHorizontal cmdMenu.Caption, False
  End Select
  
  If Not m_ucToolPanel Is Nothing Then
    m_ucToolPanel.HidePanels
  End If

End Sub

Public Sub Unroll()
Attribute Unroll.VB_Description = "Restores control to size before rollup."
  InitSize
  mvarAlignMode = CurrentAlign
  picDragger.MousePointer = 0
  picDragger.BackColor = COLOR_BTN_FACE
  mvarRolledUp = False
  UserControl.Width = m_nRolledOutWidth 'CurrentWidth
  UserControl_Resize
  
  If Not m_ucToolPanel Is Nothing Then
    m_ucToolPanel.ShowPanels
  End If
End Sub

Private Sub UserRoll()
  ' raises event and checks return before actually calling Rollup
  If Not mvarRolledUp Then
    Dim blnOKWithDeveloper As Boolean       'ref var passed to host
    
    blnOKWithDeveloper = True
    RaiseEvent UserRollup(blnOKWithDeveloper)
    
    If blnOKWithDeveloper Then Rollup
    Call UserControl_Paint
  End If
End Sub

Private Sub UserRestore()
  ' raises event and checks return before actually calling Unroll
  If mvarRolledUp Then
    Dim blnOKWithDeveloper As Boolean       'ref var passed to host
    
    blnOKWithDeveloper = True
    
    Unroll
    RaiseEvent UserUnroll(blnOKWithDeveloper)
    If Not blnOKWithDeveloper Then Rollup
    
    Call UserControl_Paint
    
  End If
End Sub

Public Property Let ForeColor(NewColor As OLE_COLOR)
  cmdMenu.ForeColor = NewColor
  mvarForeColor = NewColor
  PropertyChanged "ForeColor"
End Property

Public Property Get ForeColor() As OLE_COLOR
Attribute ForeColor.VB_Description = "Sets/returns foreground color of title bar."
Attribute ForeColor.VB_ProcData.VB_Invoke_Property = ";Appearance"
Attribute ForeColor.VB_UserMemId = -513
  ForeColor = cmdMenu.ForeColor
End Property

Public Property Let BackColor(NewColor As OLE_COLOR)
  cmdMenu.BackColor = NewColor
  mvarBackColor = NewColor
  PropertyChanged "BackColor"
End Property

Public Property Get BackColor() As OLE_COLOR
Attribute BackColor.VB_Description = "Sets/returns background color used on title bar."
Attribute BackColor.VB_ProcData.VB_Invoke_Property = ";Appearance"
Attribute BackColor.VB_UserMemId = -501
  BackColor = cmdMenu.BackColor
End Property
'
'
'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MemberInfo=7,0,0,0
Public Property Get Align() As Integer
Attribute Align.VB_Description = "Returns/sets a value that determines where an object is displayed on a form."
  Align = m_Align
End Property

Public Property Let Align(ByVal New_Align As Integer)
  m_Align = New_Align
  PropertyChanged "Align"
End Property
''
'
'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MemberInfo=14,0,0,430
Public Property Get ExtraWidth() As Variant
  ExtraWidth = m_ExtraWidth
End Property

Public Property Let ExtraWidth(ByVal New_ExtraWidth As Variant)
  m_ExtraWidth = New_ExtraWidth
  PropertyChanged "ExtraWidth"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MemberInfo=5
Public Sub SwitchSide()
Attribute SwitchSide.VB_Description = "Toggle between lft and right sides"
  If UserControl.Extender.Align = 3 Then
    m_ucToolPanel.SetOnLeftSide False
    UserControl.Extender.Align = 4
  ElseIf UserControl.Extender.Align = 4 Then
    m_ucToolPanel.SetOnLeftSide True
    UserControl.Extender.Align = 3
  End If
End Sub

