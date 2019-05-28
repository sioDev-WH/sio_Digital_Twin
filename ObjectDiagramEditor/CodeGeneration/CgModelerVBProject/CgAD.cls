VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgAD"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Dim asc As ScriptControl
Dim replaceRes As Variant
Dim scanRes As Variant
Dim scanCount As Variant
Dim parseRes As Variant
Dim parseCount As Variant

Public Sub scanResult(R As Variant, count As Variant)
  scanRes = R
  scanCount = count
End Sub

Public Sub replaceResult(R As Variant)
  replaceRes = R
End Sub

Public Sub parseResult(R As Variant, count As Variant)
  parseRes = R
  parseCount = count
End Sub

Public Function ReplacePat(str As String, pat As String, repl As String) As String
  asc.Run "replace", str, pat, repl
  ReplacePat = replaceRes
End Function

Public Function ReplaceStr(str As String, substr As String, pat As String, repl As String) As String
  Dim i As Long
  Dim ic As Long
  Dim ret As String
  Dim offset As Long
  Dim offsetIncr As Long
  Dim intRepl As String
  
  'Debug.Print "str: " & vbCrLf & str
  'Debug.Print "substr: " & vbCrLf & substr
  'Debug.Print "pat: " & vbCrLf & pat
  'Debug.Print "repl: " & vbCrLf & repl
  
  offsetIncr = Len(repl) - Len(substr)
  intRepl = String(Len(repl), "~")
  
  ' NOTE:  There are cases like "AoA*AoA" where a pattern "^AoA^" which requires a before and after
  '        confirmation character overlap, resulting in only the first pattern being recognized.  To
  '        work around this issue, a temporary replace string is inserted for detected matches, and
  '        the scan is run until there are no more patches.  A temporary replace string is used because
  '        the replace string may and often does contain the search string.
  '        A final cleanup is to replace the temporary replace string with the actual replace string
  
  ret = str
  scanCount = 1
  Do While scanCount > 0
    offset = 0
    asc.Run "scan", ret, pat
    
    For i = 0 To scanCount - 1
      ic = scanRes(i) + offset
      'Debug.Print Left(ret, ic + 1) & "^" & Mid(ret, ic + 2)
      ret = Left(ret, ic) & Replace(ret, substr, intRepl, ic + 1, 1, vbTextCompare)
      'Debug.Print ret
      offset = offset + offsetIncr
    Next i
  Loop
  
  ReplaceStr = Replace(ret, intRepl, repl, , , vbTextCompare)
  'Debug.Print ReplaceStr
End Function

Public Sub Parse(str As String, pat As String, argV() As String, argC As Long)
  Dim i As Long
  asc.Run "parse", str, pat
  argC = parseCount
  ReDim argV(argC) As String
  For i = 0 To parseCount - 1
    argV(i) = parseRes(i)
  Next i
End Sub

Private Sub Class_Initialize()
  Dim szCode As String
  Dim var As Variant
  
  Set var = Me
  Set asc = New ScriptControl
  asc.Language = "VBScript"
 
  szCode = ""
  szCode = szCode & "Dim regEx" & vbCrLf
  szCode = szCode & "Dim retObj" & vbCrLf
  szCode = szCode & "" & vbCrLf
  szCode = szCode & "Public Sub Init(obj)" & vbCrLf
  szCode = szCode & "  Set regEx = new RegExp" & vbCrLf
  szCode = szCode & "  Set retObj = obj" & vbCrLf
  szCode = szCode & "End Sub" & vbCrLf
  szCode = szCode & "" & vbCrLf
  szCode = szCode & "Public Sub replace(str, pat, repl)" & vbCrLf
  szCode = szCode & "  regEx.Pattern = pat" & vbCrLf
  szCode = szCode & "  regEx.IgnoreCase = False" & vbCrLf
  szCode = szCode & "  regEx.Global = True" & vbCrLf
  szCode = szCode & "  str = regEx.Replace(str, repl)" & vbCrLf
  szCode = szCode & "  retObj.replaceResult str" & vbCrLf
  szCode = szCode & "End Sub"
  szCode = szCode & "" & vbCrLf
  szCode = szCode & "Public Sub scan(str, pat)" & vbCrLf
  szCode = szCode & "  Dim Matches, Match, ret, i" & vbCrLf
  szCode = szCode & "  regEx.Pattern = pat" & vbCrLf
  szCode = szCode & "  regEx.IgnoreCase = False" & vbCrLf
  szCode = szCode & "  regEx.Global = True" & vbCrLf
  szCode = szCode & "  Set Matches = regEx.Execute(str)" & vbCrLf
  szCode = szCode & "  Redim ret(Matches.count)" & vbCrLf
  szCode = szCode & "  i = 0" & vbCrLf
  szCode = szCode & "  For Each Match in Matches" & vbCrLf
  szCode = szCode & "    ret(i) = Match.FirstIndex" & vbCrLf
  szCode = szCode & "    i = i + 1" & vbCrLf
  szCode = szCode & "  Next" & vbCrLf
  szCode = szCode & "  retObj.scanResult ret, Matches.Count" & vbCrLf
  szCode = szCode & "End Sub"
  szCode = szCode & "" & vbCrLf
  szCode = szCode & "Public Sub parse(str, pat)" & vbCrLf
  szCode = szCode & "  Dim Matches, Match, ret, i" & vbCrLf
  szCode = szCode & "  regEx.Pattern = pat" & vbCrLf
  szCode = szCode & "  regEx.IgnoreCase = False" & vbCrLf
  szCode = szCode & "  regEx.Global = True" & vbCrLf
  szCode = szCode & "  Set Matches = regEx.Execute(str)" & vbCrLf
  szCode = szCode & "  Redim ret(Matches.count)" & vbCrLf
  szCode = szCode & "  i = 0" & vbCrLf
  szCode = szCode & "  For Each Match in Matches" & vbCrLf
  szCode = szCode & "    ret(i) = Match.Value" & vbCrLf
  szCode = szCode & "    i = i + 1" & vbCrLf
  szCode = szCode & "  Next" & vbCrLf
  szCode = szCode & "  retObj.parseResult ret, Matches.Count" & vbCrLf
  szCode = szCode & "End Sub"
  
  asc.AddCode szCode
  asc.Run "Init", var

End Sub

