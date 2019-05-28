Attribute VB_Name = "VBexamp1"
Option Explicit

Global Nonlinear As Boolean
Global Example As Long

Function funceval1(lp As Long, ByVal numcols As Integer, ByVal numrows As Integer, ByRef objval As Double, _
            ByRef lhs() As Double, ByRef var() As Double, ByVal varone As Integer, ByVal vartwo As Integer) As Long
    Err = 0
    On Error Resume Next
    ' The use of the addressof operator can crash VB. We should never return an error
    ' value to the DLL. Therefor, on error resume next
    objval = var(0) * var(0) + var(1) * var(1) ' objective
    lhs(0) = var(0) + var(1) ' constraint left hand side
    lhs(1) = var(0) * var(1) ' constraint left hand side
    funceval1 = 0
End Function

Function showiter1(ByVal lp As Long, ByVal wherefrom As Long) As Long
   Dim itercount As Long
   Dim objval As Double
   Dim ret As Long
   ret = getcallbackinfo(lp, wherefrom, CBINFO_ITCOUNT, itercount)
   ret = getcallbackinfo(lp, wherefrom, CBINFO_PRIMAL_OBJ, objval)
   MsgBox "Iteration :" & itercount & "  Objective = " & objval
   showiter1 = 0
End Function
Function funceval3(lp As Long, ByVal numcols As Integer, ByVal numrows As Integer, ByRef objval As Double, _
            ByRef lhs() As Double, ByRef var() As Double, ByVal varone As Integer, ByVal vartwo As Integer) As Long
    Err = 0
    On Error Resume Next
    ' The use of the addressof operator can crash VB. We should never return an error
    ' value to the DLL. Therefor, on error resume next
    objval = var(0) * var(0) + var(1) * var(1) ' objective
    lhs(0) = var(0) * var(1) ' constraint left hand side
    lhs(1) = var(0) * var(1) ' constraint left hand side
    funceval3 = 0
End Function
Function funceval4(lp As Long, ByVal numcols As Integer, ByVal numrows As Integer, ByRef objval As Double, _
            ByRef lhs() As Double, ByRef var() As Double, ByVal varone As Integer, ByVal vartwo As Integer) As Long
    Err = 0
    On Error Resume Next
    ' The use of the addressof operator can crash VB. We should never return an error
    ' value to the DLL. Therefor, on error resume next
    If Nonlinear Then
        objval = var(0) * var(0) + var(1) * var(1) ' objective
        lhs(0) = var(0) + var(1) ' constraint left hand side
        lhs(1) = var(0) * var(1) ' constraint left hand side
    Else
        objval = 2 * var(0) + var(1) ' objective
        lhs(0) = var(0) + var(1) ' constraint left hand side
        lhs(1) = 3 * var(0) - var(1) ' constraint left hand side
    End If
    funceval4 = 0
End Function
Function funceval5(lp As Long, ByVal numcols As Integer, ByVal numrows As Integer, ByRef objval As Double, _
            ByRef lhs() As Double, ByRef var() As Double, ByVal varone As Integer, ByVal vartwo As Integer) As Long
    Err = 0
    On Error Resume Next
    Dim term1 As Double, term2 As Double, term3 As Double
    Dim PI As Double
    PI = 3.141593
    ' The use of the addressof operator can crash VB. We should never return an error
    ' value to the DLL. Therefor, on error resume next
    
    term1 = var(0) / PI * (5.1 * var(0) / PI / 4# - 5#)
    term2 = (var(1) - term1 - 6) * (var(1) - term1 - 6)
    term3 = 10# * (1# - 1# / PI / 8#) * Cos(var(0)) + 10#
    objval = term2 + term3
      
    funceval5 = 0
End Function

Function funceval6(lp As Long, ByVal numcols As Integer, ByVal numrows As Integer, ByRef objval As Double, _
            ByRef lhs() As Double, ByRef var() As Double, ByVal varone As Integer, ByVal vartwo As Integer) As Long
    Err = 0
    On Error Resume Next
    
    If var(0) > 10 Then
       objval = var(1) + var(2)
    Else
       objval = var(1) - var(2)
    End If

    funceval6 = 0
End Function


Function jacobian1(lp As Long, ByVal numcols As Integer, ByVal numrows As Integer, ByVal nzspace As Integer, ByRef objval As Double, _
            ByRef obj() As Double, ByRef matbeg() As Long, ByRef matcnt() As Long, ByRef matind() As Long, ByRef matval() As Double, ByRef var() As Double, _
            ByRef objtype() As Byte, ByRef matvaltype() As Byte) As Long

    Err = 0
    On Error Resume Next
    MsgBox "jacobian evaluated at: x1 = " & var(0) & " x2 = " & var(1)
    ' Value of the objective function
    objval = var(0) * var(0) + var(1) * var(1)
    ' Partial derivatives of the objective
    obj(0) = 2 * var(0)
    obj(1) = 2 * var(1)
    ' Partial derivatives of X + Y (constant)
    matval(0) = 1
    matval(2) = 1
    ' Partial derivatives of X * Y (variable)
    matval(1) = var(1)
    matval(3) = var(0)
    jacobian1 = 0
End Function

Function jacobian3(lp As Long, ByVal numcols As Integer, ByVal numrows As Integer, ByVal nzspace As Integer, ByRef objval As Double, _
            ByRef obj() As Double, ByRef matbeg() As Long, ByRef matcnt() As Long, ByRef matind() As Long, ByRef matval() As Double, ByRef var() As Double, _
            ByRef objtype() As Byte, ByRef matvaltype() As Byte) As Long

    Err = 0
    On Error Resume Next
    ' Value of the objective function
    objval = var(0) * var(0) + var(1) * var(1)
    ' Partial derivatives of the objective
    obj(0) = 2 * var(0)
    obj(1) = 2 * var(1)
    ' Partial derivatives of X * Y (variable)
    matval(0) = var(1)
    matval(2) = var(0)
    ' Partial derivatives of X * Y (variable)
    matval(1) = var(1)
    matval(3) = var(0)
    jacobian3 = 0
End Function


Sub Showlimits()
   Dim cols As Long, rows As Long, ints As Long, ret As Long

   ret = getproblimits(0, PROB_LP, cols, rows, ints)
   MsgBox "LP limits: " & Trim(Str(cols)) & " variables, " & Trim(Str(rows)) & " constraints, " & Trim(Str(ints)) & " integers"

   ret = getproblimits(0, PROB_QP, cols, rows, ints)
   MsgBox "QP limits: " & Trim(Str(cols)) & " variables, " & Trim(Str(rows)) & " constraints, " & Trim(Str(ints)) & " integers"

   ret = getproblimits(0, PROB_NLP, cols, rows, ints)
   MsgBox "NLP limits: " & Trim(Str(cols)) & " variables, " & Trim(Str(rows)) & " constraints, " & Trim(Str(ints)) & " integers"

   ret = getproblimits(0, PROB_NSP, cols, rows, ints)
   MsgBox "NSP limits: " & Trim(Str(cols)) & " variables, " & Trim(Str(rows)) & " constraints, " & Trim(Str(ints)) & " integers"

End Sub
Sub AdjustFormforExample2()
   With Form2
   .Label17 = "Here we use the Jacobian function."
   .Label17.Visible = True
   .Text10.Visible = False
   .Text11.Visible = False
   .Text24.Visible = False
   .Text25.Visible = False
   End With
End Sub

Sub AdjustFormforExample3()
   With Form2
   .Label1 = "Example 3: Attempt to solve the model:"
   .Label9 = "x1 * x2 = 1"
   .Label4 = "x1 * x2 = 0"
   .Label7 = ""
   .Label8 = "Infeasible (due to conflicting constraints)"
   .Text10.Visible = False
   .Text11.Visible = False
   .Text24.Visible = False
   .Text25.Visible = False
   End With
End Sub

Sub AdjustFormforExample4()
    With Form2
    .Label1 = "Example 4: Alternate linear problem"
    .Label2 = "Minimize 2 * x1 + x2"
    .Label3 = "Subj to"
    .Label9 = "x1 + x2 = 1"
    .Label4 = "3 * x1 - x2 >= 0"
    .Label7 = "Solution: x1 = 0.25, x2 = 0.75"
    .Label8 = "Objective = 1.25"
    .Text10.Visible = False
    .Text11.Visible = False
    .Text24.Visible = False
    .Text25.Visible = False
   End With
End Sub

Sub Adjustfor4a()
   With Form2
   .Text5.Visible = False
   .Text6.Visible = False
   .Text7.Visible = False
   .Text8.Visible = False
   .Text10.Visible = False
   .Text11.Visible = False
   .Text24.Visible = False
   .Text25.Visible = False
   End With
End Sub

Sub AdjustFormforExample5()
    With Form2
    .Label1 = "Example 5: The Branin Function"
    .Label2 = "Minimize (x2 - term1 - 6) ^2 + term2"
    .Label3 = "With "
    .Label9 = "term1 = x1/PI*(5.1*x1/PI/4 - 5)"
    .Label4 = "term2 = 10*(1 - 1/PI/8)*Cos(x1) + 10"
    .Label7 = "Solution: x1 = 3.14, x2 = 2.27"
    .Label8 = "Objective = 0.39"
   End With
End Sub

Sub AdjustFormforExample6()
   With Form2
    .Label1 = "Example 6: IF function"
    .Label2 = "Maximize (if X > 10 then Y + Z else Y - Z)"
    .Label3 = "With "
    .Label9 = " 0 <= X, Y, Z <= 20"
    .Label4 = ""
    .Label7 = "Solution: x > 10, Y = Z = 20"
    .Label8 = "Objective = 40"
    .Text6.Visible = False
    .Text7.Visible = False
    .Text8.Visible = False
    .Text10.Visible = False
    .Text11.Visible = False
    .Text24.Visible = False
    .Text25.Visible = False
   End With
End Sub

Sub AdjustFormforExample1()
   With Form2
   .Text10.Visible = False
   .Text11.Visible = False
   .Text24.Visible = False
   .Text25.Visible = False
   End With
End Sub
