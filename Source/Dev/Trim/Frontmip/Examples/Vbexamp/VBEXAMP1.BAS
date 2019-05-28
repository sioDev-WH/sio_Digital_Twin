Attribute VB_Name = "VBexamp1"
Option Explicit

Global obj() As Double
Global rhs() As Double
Global sense() As Byte
Global ctype() As Byte
Global matbeg() As Long
Global matcnt() As Long
Global matind() As Long
Global matval() As Double
Global qmatbeg() As Long
Global qmatcnt() As Long
Global qmatind() As Long
Global qmatval() As Double
Global lb() As Double
Global ub() As Double
Global stat As Long
Global objval As Double
Global x() As Double
Global piout() As Double
Global slack() As Double
Global dj() As Double
Global varlow() As Double
Global varupp() As Double
Global conlow() As Double
Global conupp() As Double
Global lp As Long


Function lpcallback(ByVal lpinfo As Long, ByVal wherefrom As Long) As Long
   Dim iters As Long
   Dim obj As Double
   Dim ret As Long
   ret = getcallbackinfo(lpinfo, wherefrom, CBINFO_ITCOUNT, iters)
   ret = getcallbackinfo(lpinfo, wherefrom, CBINFO_PRIMAL_OBJ, obj)
   MsgBox "Iteration: " & Trim(Str(iters)) & "  Obj = " & Trim(Str(obj))
   lpcallback = PSTAT_CONTINUE
End Function

Sub AdjustFormforExample2()
   With Form2
   .Label16.Visible = True
   .Text5.Visible = False
   .Text6.Visible = False
   .Text7.Visible = False
   .Text8.Visible = False
   .Text9.Visible = False
   .Text10.Visible = False
   .Text11.Visible = False
   .Text12.Visible = False
   .Text13.Visible = False
   .Text14.Visible = False
   .Text15.Visible = False
   .Text16.Visible = False
   .Text17.Visible = False
   .Text18.Visible = False
   .Text19.Visible = False
   .Text20.Visible = False
   .Text21.Visible = False
   .Text22.Visible = False
   .Text23.Visible = False
   .Text24.Visible = False
   .Text25.Visible = False
   .Label10.Visible = False
   .Label11.Visible = False
   .Label12.Visible = False
   .Label13.Visible = False
   .Label14.Visible = False
   .Label15.Visible = False
   .Label1 = "Example 2: Solves the MIP model:"
   .Label7 = "LP solution: x1 = 2, x2 = 4"
   .Label8 = "Objective = 16"
   .Label16.Visible = True
   End With
End Sub

Sub AdjustFormforExample3()
   With Form2
   .Label1 = "Example 3: Attempt to solve the LP model:"
   .Label5 = "5 x1 + 10 x2 <= -50"
   .Label7 = ""
   .Label8 = "Infeasible (due to non-negative variables and negative RHS)"
   .Text9.Visible = False
   .Text10.Visible = False
   .Text11.Visible = False
   .Text12.Visible = False
   .Text13.Visible = False
   .Text14.Visible = False
   .Text15.Visible = False
   .Text16.Visible = False
   .Text17.Visible = False
   .Text18.Visible = False
   .Text19.Visible = False
   .Text20.Visible = False
   .Text21.Visible = False
   .Text22.Visible = False
   .Text23.Visible = False
   .Label10.Visible = False
   .Label11.Visible = False
   .Label12.Visible = False
   .Label13.Visible = False
   .Label14.Visible = False
   .Label15.Visible = False
   End With
End Sub

Sub AdjustFormforExample4()
    With Form2
    .Label1 = "Example QP problem (Portfolio Optimization)"
    .Label2 = "Minimize Portfolio Variance xQx"
    .Label3 = "Subject to allocations: Sum(x) = 1"
    .Label4 = "And portfolio return: Sum (Ri xi) >= 0.085"
    .Label4.Left = 240
    .Label5.Visible = False
    .Label6.Visible = False
    .Label17.Visible = True
    .Label7 = "x1 = 0.462  x2 = 0  x3 = 0.313  x4 = 0  x5 = 0.225"
    .Label8 = "The objective = approx. 0.00014 (minimum variance)"
    .Label9.Visible = False
    .Text8.Visible = False
    .Text9.Visible = False
    .Text10.Visible = False
    .Text11.Visible = False
    .Text12.Visible = False
    .Text13.Visible = False
    .Text14.Visible = False
    .Text15.Visible = False
    .Text16.Visible = False
    .Text17.Visible = False
    .Text18.Visible = False
    .Text19.Visible = False
    .Text20.Visible = False
    .Text21.Visible = False
    .Text22.Visible = False
    .Text23.Visible = False
    .Text24.Visible = False
    .Text25.Visible = False
    .Label10.Visible = False
    .Label11.Visible = False
    .Label12.Visible = False
    .Label13.Visible = False
    .Label14.Visible = False
    .Label15.Visible = False
   End With
End Sub

Sub AdjustFormforExample5()
   With Form2
   .Label16.Visible = True
   .Text5.Visible = False
   .Text6.Visible = False
   .Text7.Visible = False
   .Text8.Visible = False
   .Text9.Visible = False
   .Text10.Visible = False
   .Text11.Visible = False
   .Text12.Visible = False
   .Text13.Visible = False
   .Text14.Visible = False
   .Text15.Visible = False
   .Text16.Visible = False
   .Text17.Visible = False
   .Text18.Visible = False
   .Text19.Visible = False
   .Text20.Visible = False
   .Text21.Visible = False
   .Text22.Visible = False
   .Text23.Visible = False
   .Text24.Visible = False
   .Text25.Visible = False
   .Label10.Visible = False
   .Label11.Visible = False
   .Label12.Visible = False
   .Label13.Visible = False
   .Label14.Visible = False
   .Label15.Visible = False
   .Label1 = "Example 5: Reads and solves the MIP model:"
   .Label7 = "LP solution: x1 = 2, x2 = 4"
   .Label8 = "Objective = 16"
   .Label16.Visible = True
   End With
End Sub

