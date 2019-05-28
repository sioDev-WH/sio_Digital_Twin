VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgListener"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

' KAB April 7, 2003 --> Changed communication macros.  Need to know if target is attribute or operation.

Public TargetCompositeObject As String
Public TargetClass As String
Public TargetObject As String
Public TargetOper As String
Public TargetAttr As String
Public bCreate As Boolean
Public bOper As Boolean  ' if false, target is an attribute

Public TargetListener As String

