Attribute VB_Name = "CodeGeneration"
Public Sub GenerateCPPFile(incColl As includes, szProjectPath As String, szProjectName As String, className As String, ClassCgAttributes As Collection, classCgOperations As Collection, bApp As Boolean)

Dim Handle As Long
Dim aAttr As CgAttribute
Dim aOper As CgOperation
Dim ic As Long
Dim params As String
Dim aCgPar As CgAttribute
Dim aColl As Collection

Set aColl = New Collection
Handle = FreeFile

szProjectPath = LTrim(RTrim(szProjectPath))
If Right(szProjectPath, 1) <> "\" Then szProjectPath = szProjectPath & "\"

Open szProjectPath & className & ".cpp" For Output As #Handle

Print #Handle, "// implementation for class " & className

Print #Handle, "#include " & Chr(34) & "StdAfx.h" & Chr(34)
Print #Handle, "#include " & Chr(34) & szProjectName & ".h" & Chr(34)
'Print #Handle, "#include <fstream.h>"
Print #Handle, "#include <math.h>"
Print #Handle, ""
Print #Handle, "#include " & Chr(34) & className & ".h" & Chr(34)

If bApp Then
Print #Handle, "#include " & Chr(34) & "ISDaeCOSolver_i.c;" & Chr(34)
Print #Handle, "#include " & Chr(34) & "OnUMLEso_i.c;" & Chr(34)
End If

On Error Resume Next
For Each aAttr In ClassCgAttributes
  aColl.Add aAttr, aAttr.DataType
Next
On Error GoTo 0


Dim argV() As String
Dim argC As Long
Dim aInclude As include
Dim szPat As String
Dim i As Long
Dim newAttr As CgItem
Dim FDColl As Collection
Set FDColl = New Collection

szPat = "[A-Za-z0-9_]+"
On Error Resume Next
Print #Handle, "// includes"
For Each aAttr In aColl
  adg.Parse aAttr.DataType, szPat, argV, argC
  For i = 0 To argC - 1
    Err = 0
    Set aInclude = incColl.coll(argV(i))
    If Err = 0 Then
      If Len(aInclude.INC) > 0 Then
        Set newAttr = New CgItem
        newAttr.Name = "#include " & aInclude.INC
        FDColl.Add newAttr, newAttr.Name
      End If
    Else
      Set newAttr = New CgItem
      newAttr.Name = "#include " & Chr(34) & argV(i) & ".h" & Chr(34)
      FDColl.Add newAttr, newAttr.Name
    End If
  Next i
Next
On Error GoTo 0

For Each newAttr In FDColl
  Print #Handle, newAttr.Name
Next

#If 1 Then
Print #Handle, ""
Print #Handle, className & "::" & className & "()"
Print #Handle, "{"
Print #Handle, "  init();"
Print #Handle, "}"

Print #Handle, ""
Print #Handle, className & "::~" & className & "()"
Print #Handle, "{"
Print #Handle, " clean();"
Print #Handle, "}"
Print #Handle, ""
#End If

For Each aOper In classCgOperations
  params = ""
  For Each aCgPar In aOper.Parameters
    ' TODO: remove this patch
    If LTrim(RTrim(aCgPar.DataType)) = "string" Then aCgPar.DataType = "char*"
    
    params = params & IIf(Len(params) > 0, ", ", "") & IIf(UCase(aCgPar.Mechanism) = "IN", "const ", "") & aCgPar.DataType
    If UCase(aCgPar.Mechanism) = "INOUT" Then
      params = params & "*"
    End If
    
    params = params & " " & aCgPar.Name
  Next
  
  Dim szOperName As String
  szOperName = LTrim(RTrim(aOper.Name))
  If szOperName = className Or szOperName = "~" & className Then
    Print #Handle, className & "::" & aOper.Name & "(" & params & ")"
  Else
  
    If aOper.ReadOnly Then
      Print #Handle, aOper.ReturnType & " " & className & "::" & aOper.Name & "(" & params & ") const"
    Else
      Print #Handle, aOper.ReturnType & " " & className & "::" & aOper.Name & "(" & params & ")"
    End If
  
  End If
  
  Print #Handle, "{"
  Print #Handle, aOper.Body
  Print #Handle, "}"
  Print #Handle, ""
  Print #Handle, ""
  
Next

Close #Handle

End Sub


Public Sub GenerateHeaderFile(incColl As includes, szProjectPath As String, szProjectName As String, className As String, ClassCgAttributes As Collection, classCgOperations As Collection, bApp As Boolean)

Dim Handle As Long
Dim aAttr As CgAttribute
Dim aOper As CgOperation
Dim ic As Long
Dim params As String
Dim aCgPar As CgAttribute
Dim aColl As Collection

Set aColl = New Collection

Handle = FreeFile

szProjectPath = LTrim(RTrim(szProjectPath))
If Right(szProjectPath, 1) <> "\" Then szProjectPath = szProjectPath & "\"

Open szProjectPath & className & ".h" For Output As #Handle

Print #Handle, "#ifndef __" & UCase(className) & "_H"
Print #Handle, "#define __" & UCase(className) & "_H"
Print #Handle, ""

On Error Resume Next
For Each aAttr In ClassCgAttributes
  aColl.Add aAttr, aAttr.DataType
Next
On Error GoTo 0

Dim szPat As String
Dim argV() As String
Dim argC As Long
Dim aInclude As include
Dim i As Long
Dim newAttr As CgItem
Dim FDColl As Collection

Set FDColl = New Collection
szPat = "[A-Za-z0-9_]+"

If bApp Then
  Print #Handle, "#include <fstream.h>"
Else
  Print #Handle, "// includes"
  Print #Handle, "#include " & Chr(34) & "OnUMLDaeEsoImpl.h" & Chr(34)
  Print #Handle, ""
End If

On Error Resume Next
Print #Handle, "// forward declarations"
For Each aAttr In aColl
  adg.Parse aAttr.DataType, szPat, argV, argC
  For i = 0 To argC - 1
    Err = 0
    Set aInclude = incColl.coll(argV(i))
    If Err = 0 Then
      If Len(aInclude.FD) > 0 Then
        Set newAttr = New CgItem
        newAttr.Name = aInclude.FD
        FDColl.Add newAttr, newAttr.Name
      End If
    Else
      Set newAttr = New CgItem
      newAttr.Name = "class " & argV(i) & ";"
      FDColl.Add newAttr, newAttr.Name
    End If
  Next i
Next

For Each newAttr In FDColl
  Print #Handle, newAttr.Name
  Debug.Print newAttr.Name
Next


Print #Handle, ""
Print #Handle, ""
Print #Handle, "class " & className & IIf(bApp, "", " : public COnUMLDaeEsoImpl<" & className & ">")
Print #Handle, "{"
Print #Handle, "public:"
  
#If 1 Then
Print #Handle, className & "();"
Print #Handle, "virtual ~" & className & "();"
#End If

Print #Handle, ""
Print #Handle, "public:"

#If using_ilogix Then
For Each aAttr In ClassCgAttributes
  If aAttr.bRef Or aAttr.bAggregate Then
    Print #Handle, aAttr.DataType & "* " & aAttr.Name & ";"
  Else
    Print #Handle, aAttr.DataType & " " & aAttr.Name & ";"
  End If
Next
#End If

Print #Handle, ""
Print #Handle, "public:"
For Each aOper In classCgOperations
  params = ""
  For Each aCgPar In aOper.Parameters
    ' TODO: remove this patch
    If aCgPar.DataType = "string" Then aCgPar.DataType = "char*"

    params = params & IIf(Len(params) > 0, ", ", "") & IIf(UCase(aCgPar.Mechanism) = "IN", "const ", " ") & aCgPar.DataType
    params = params & IIf(UCase(aCgPar.Mechanism) = "INOUT", "* ", " ") & aCgPar.Name
  Next
  
  ' TODO: remove this patch
  Dim szOperName As String
  szOperName = LTrim(RTrim(aOper.Name))
  If szOperName = className Or szOperName = "~" & className Then
    Print #Handle, aOper.Name & "(" & params & ");"
  ElseIf szOperName = "RtsInjectEvent" Or szOperName = "RtsGetAttributeValue" Or szOperName = "RtsSetAttributeValue" Then
    Print #Handle, "static " & aOper.ReturnType & " " & aOper.Name & "(" & params & ");"
  Else
    If aOper.ReadOnly Then
      Print #Handle, aOper.ReturnType & " " & aOper.Name & "(" & params & ") const;"
    Else
      Print #Handle, aOper.ReturnType & " " & aOper.Name & "(" & params & ");"
    End If
  End If
Next

Print #Handle, ""
Print #Handle, "};"
Print #Handle, ""
Print #Handle, "#endif"

Close #Handle

End Sub


Public Sub BuildIncludes(coll As includes)
  Dim aItem As include
  Set coll = New includes
  
  coll.Add "char", "", ""
  coll.Add "int", "", ""
  coll.Add "long", "", ""
  coll.Add "double", "", ""
  coll.Add "SAFEARRAY", "", ""
  
  coll.Add "ofstream", "", ""
  coll.Add "Fdouble", "class Fdouble;", Chr(34) & "OnAD.h" & Chr(34)
  coll.Add "COnListener", "template <class T, class A> class COnListener;", Chr(34) & "EventBroadcast.h" & Chr(34)
  coll.Add "COnBroadcaster", "template <class A> class COnBroadcaster;", Chr(34) & "EventBroadcast.h" & Chr(34)
  coll.Add "IOnModelExec", "struct IOnModelExec;", "" ' Chr(34) & "ISDaeCOSolver_i.c" & Chr(34)
  coll.Add "IIsDaeEsoCImpl", "struct IIsDaeEsoCImpl;", "" ' Chr(34) & "ISDaeCOSolver_i.c" & Chr(34)
  coll.Add "COnUMLDaeEsoImpl", "class COnUMLDaeEsoImpl;", "" ' Chr(34) & "OnUMLEso_i.c" & Chr(34)
  coll.Add "IOnVarInit", "class IOnVarInit;", Chr(34) & "IOnVarInit.h" & Chr(34)
  coll.Add "COnDataCollector", "template <class T> class COnDataCollector;", Chr(34) & "OnDataCollector.h" & Chr(34)
  
End Sub


