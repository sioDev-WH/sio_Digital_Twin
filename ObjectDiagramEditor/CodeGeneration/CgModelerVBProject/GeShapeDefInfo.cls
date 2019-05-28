VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "GeShapeDefInfo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
'======================================================================================
'
' Module:   GeShapeDefInfo
' Updated:                By
'
'--------------------------------------------------------------------------------------
'======================================================================================

Option Explicit

'=================================================================
' Start of Declarations Section
'=================================================================
' Source Library
Public FolderName As String
Public ShapeName As String
Public Revision As Long        ' -1 means invalid
Public ShapeID As Long        ' id (counter) in geTblShape
Public ShapeGUID As String    ' GUID for the ShapeDef

'default props
Public HasDefaultProps As Boolean ' indicate if DB even has the fields
Public AutoScaleOnInsert As Boolean
Public CanMove As Boolean
Public CanSelect As Boolean
Public ScaleMode As Integer
Public RotateMode As Integer
Public UserDataStr As String  ' max 255
Public UserDataFlt As Single


Public FolderEmpty As Boolean  ' Source folder is empty
Public LibraryName As String ' name of Library this info belongs to

' Destination Library
Public RevisionDST As Long

' common
Public FolderInfoOnly As Boolean    ' only contain info on Folder

'=================================================================
' End of Declarations Section
'=================================================================
'---------------------------
Private Sub Class_Initialize()
  Revision = -1         ' invalid
  RevisionDST = -1      ' invalid
End Sub

'---------------------------
Public Function Copy() As GeShapeDefInfo
  Dim objnew As GeShapeDefInfo
  On Error Resume Next
  Set objnew = New GeShapeDefInfo
  objnew.AssumePropsFromObj Me
  Set Copy = objnew
End Function

'---------------------------
Public Sub AssumePropsFromObj(obj As GeShapeDefInfo)
  With obj
    FolderName = .FolderName
    ShapeName = .ShapeName
    Revision = .Revision
    FolderEmpty = .FolderEmpty
    FolderName = .FolderName
    RevisionDST = .RevisionDST
    HasDefaultProps = .HasDefaultProps
    AutoScaleOnInsert = .AutoScaleOnInsert
    CanMove = .CanMove
    CanSelect = .CanSelect
    ScaleMode = .ScaleMode
    RotateMode = .RotateMode
    UserDataStr = .UserDataStr
    UserDataFlt = .UserDataFlt
  End With
End Sub


