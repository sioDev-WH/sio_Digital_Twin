Attribute VB_Name = "mGeLibMgr"
Option Explicit

Global Const INI_FILENAME = "GeLibMgr.INI"     ' Name of the INI File

'======================================================================================
' Status Message Window Management
'======================================================================================
'------------------------------
Public Sub ShowStatusMsg(szMsg As String)
  Dim frmMsg As frmStatus
  If GetStatusWindow(frmMsg) Then
'    frmMsg.ZOrder ' = 0   ' move to front
    frmMsg.ShowStatusMsg szMsg
  End If
End Sub
'------------------------------
Private Function GetStatusWindow(frmMsg As Form) As Boolean
  Dim Index As Integer
  If Not IsLoaded(Index, "frmStatus") Then
    Set frmMsg = New frmStatus
  Else
    Set frmMsg = Forms(Index)
  End If
  GetStatusWindow = True
End Function
'------------------------------
Public Function IsLoaded(Index As Integer, MyFormName As String) As Boolean
  ' Accepts: a form name
  ' Purpose: determines if a form is loaded
  ' Returns: True if specified the form is loaded;
  '          False if the specified form is not loaded.
  Dim i

  IsLoaded = False
  For i = 0 To Forms.Count - 1
    If Forms(i).Name = MyFormName Then
      IsLoaded = True
      Index = i
      Exit Function       ' Quit function once form has been found.
    End If
  Next
End Function



