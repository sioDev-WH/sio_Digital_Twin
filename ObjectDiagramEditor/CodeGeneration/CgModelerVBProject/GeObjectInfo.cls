VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "GeObjectInfo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'======================================================================================
'
' Module:   GeObjectInfo
' Updated:                By
'
'--------------------------------------------------------------------------------------
'======================================================================================


Option Explicit


'=================================================================
' Start of Declarations Section
'=================================================================
Public GeID As Long
Public llX As Single
Public llY As Single
Public urX As Single
Public urY As Single
Public iFld As Integer
Public strFldName As String
Public strFldValue As String

Public ObjectType As Integer

'=================================================================
' End of Declarations Section
'=================================================================

