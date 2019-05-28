VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Example"
   ClientHeight    =   4305
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6840
   LinkTopic       =   "Form2"
   ScaleHeight     =   4305
   ScaleWidth      =   6840
   StartUpPosition =   1  'CenterOwner
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   3480
      TabIndex        =   22
      Top             =   480
      Width           =   855
   End
   Begin VB.TextBox Text25 
      Height          =   285
      Left            =   4920
      TabIndex        =   21
      Top             =   1560
      Width           =   1215
   End
   Begin VB.TextBox Text24 
      Height          =   285
      Left            =   3480
      TabIndex        =   20
      Top             =   1560
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Exit"
      Height          =   495
      Left            =   120
      TabIndex        =   19
      Top             =   3600
      Width           =   1575
   End
   Begin VB.TextBox Text11 
      Height          =   285
      Left            =   4920
      TabIndex        =   18
      Top             =   1920
      Width           =   1215
   End
   Begin VB.TextBox Text10 
      Height          =   285
      Left            =   3480
      TabIndex        =   17
      Top             =   1920
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Solve"
      Height          =   495
      Left            =   120
      TabIndex        =   16
      Top             =   3000
      Width           =   1575
   End
   Begin VB.TextBox Text8 
      Height          =   285
      Left            =   4920
      TabIndex        =   15
      Top             =   1200
      Width           =   1215
   End
   Begin VB.TextBox Text7 
      Height          =   285
      Left            =   3480
      TabIndex        =   14
      Top             =   1200
      Width           =   1215
   End
   Begin VB.TextBox Text6 
      Height          =   285
      Left            =   4920
      TabIndex        =   13
      Top             =   840
      Width           =   1215
   End
   Begin VB.TextBox Text5 
      Height          =   285
      Left            =   3480
      TabIndex        =   12
      Top             =   840
      Width           =   1215
   End
   Begin VB.TextBox Text4 
      Height          =   285
      Left            =   4920
      TabIndex        =   11
      Top             =   120
      Width           =   1455
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   3480
      TabIndex        =   10
      Top             =   120
      Width           =   1215
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   4920
      TabIndex        =   9
      Top             =   480
      Width           =   855
   End
   Begin VB.Label Label17 
      Caption         =   "The efficient portfolio is the QP solution :"
      Height          =   255
      Left            =   120
      TabIndex        =   24
      Top             =   1560
      Visible         =   0   'False
      Width           =   3255
   End
   Begin VB.Label Label16 
      Caption         =   ", integer"
      Height          =   255
      Left            =   1560
      TabIndex        =   23
      Top             =   1320
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.Label Label9 
      Caption         =   "x1 + x2 = 1"
      Height          =   255
      Left            =   840
      TabIndex        =   8
      Top             =   600
      Width           =   2535
   End
   Begin VB.Label Label8 
      Caption         =   "Objective = 0.5"
      Height          =   255
      Left            =   120
      TabIndex        =   7
      Top             =   2040
      Width           =   6135
   End
   Begin VB.Label Label7 
      Caption         =   "Solution: x1 = 0.5, x2 = 0.5"
      Height          =   255
      Left            =   120
      TabIndex        =   6
      Top             =   1800
      Width           =   3735
   End
   Begin VB.Label Label6 
      Caption         =   "x1, x2 non-negative"
      Height          =   255
      Left            =   120
      TabIndex        =   5
      Top             =   1320
      Visible         =   0   'False
      Width           =   3495
   End
   Begin VB.Label Label5 
      Caption         =   "5 x1 + 10 x2 <= 50"
      Height          =   255
      Left            =   840
      TabIndex        =   4
      Top             =   1080
      Visible         =   0   'False
      Width           =   1575
   End
   Begin VB.Label Label4 
      Caption         =   "x1 *  x2 >= 0"
      Height          =   255
      Left            =   840
      TabIndex        =   3
      Top             =   840
      Width           =   3735
   End
   Begin VB.Label Label3 
      Caption         =   "Subj to "
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   600
      Width           =   2895
   End
   Begin VB.Label Label2 
      Caption         =   "Minimize   x1^2 + x2^2"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   360
      Width           =   3255
   End
   Begin VB.Label Label1 
      Caption         =   "Example 1: Solves the nonlinear model:"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   3255
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
   
   Dim obj(0 To 1) As Double    ' Dim obj(0 To number_of_variables - 1)
   Dim rhs(0 To 1) As Double    ' Dim rhs(0 to number_of_constraints - 1)
   Dim sense(0 To 1) As Byte    ' Dim sense(0 to number_of_constraints - 1)
   Dim matbeg(0 To 1) As Long   ' Dim matbeg(0 To number_of_variables - 1)
   Dim matcnt(0 To 1) As Long   ' Dim matcnt(0 To number_of_variables - 1)
   
   Dim matind(0 To 3) As Long
   Dim matval(0 To 3) As Double
   ' The size of the arrays of matind and matval depends on the
   ' number of nonzero elements in the LP matrix for linear problems.
   ' For nonlinear problems, it is easiest to take the number of
   ' constraints times the number of variables. See documentation
   ' for details
   ' In this case 2 constraints x 2 variables = 4
   
   Dim lb(0 To 1) As Double      ' Dim lb(0 To number_of_variables - 1)
   Dim ub(0 To 1) As Double      ' Dim lb(0 To number_of_variables - 1)
   Dim rngval(0 To 1) As Double  ' Dim rngval(0 to number_of_constraints - 1)
   ' Note that rngval can only be used withe the Large Scale DLL
   
   Dim ctype(0 To 1) As Byte     ' Dim ctype(0 To number_of_variables - 1)
   Dim stat As Long, objval As Double
   Dim x(0 To 1) As Double            ' Dim x(0 To number_of_variables - 1)
   Dim piout(0 To 1) As Double        ' Dim piout(0 to number_of_constraints - 1)
   Dim slack(0 To 1) As Double        ' Dim slack(0 to number_of_constraints - 1)
   Dim dj(0 To 1) As Double           ' Dim dj(0 To number_of_variables - 1)
   
   Dim varlow(0 To 1) As Double, varupp(0 To 1) As Double
   ' Dim varlow and varupp(0 to number_of_variables - 1)
   Dim conlow(0 To 1) As Double, conupp(0 To 1) As Double
   ' Dim conlow and conupp(0 to number of constraints - 1)
   Dim objtype(0 To 1) As Byte, matvaltype(0 To 3) As Byte
   ' Dim objtype(0 to number_of_variables -1)
   ' Dim matvaltype(same as matval)
   Dim iisrows As Long, iiscols As Long
   Dim rowbdstat() As Long, colbdstat() As Long
   Dim rowind() As Long, colind() As Long
   Dim lp As Long
   Dim ret As Long
   Dim nlstat As Long
   ' set up the LP problem
   
   ' use Safearrays:
   setintparam 0, PARAM_ARRAY, 1
   
   ' Note that in VB we can not use NULL as in C.
   ' Therefor we define an array of size 1 with element -1
   ' This is recognized by the DLL as NULL
     
   Dim NullL(0) As Long, NullD(0) As Double, NullB(0) As Byte
   NullL(0) = -1
   NullD(0) = -1
   NullB(0) = 0
   
   Select Case Example
   Case 1
   
   '   Example program calling the nonlinear Solver DLL.
   'Solves the problem:

   'Minimize x ^ 2 + Y ^ 2
   'Subject to:
   '   X + Y = 1
   '   X * Y >= 0

   '(Solution is X = Y = 0.5, Objective = 0.5)


       rhs(0) = 1
       rhs(1) = 0
       sense(0) = Asc("E")
       sense(1) = Asc("G")
       lb(0) = -INFBOUND
       lb(1) = -INFBOUND
       ub(0) = INFBOUND
       ub(1) = INFBOUND
       x(0) = 0
       x(1) = 1
       
      setintparam 0, PARAM_ARGCK, 1
      lp = loadnlp(PROBNAME, 2, 2, 1, obj, rhs, sense, _
            NullL, NullL, NullL, matval, x, lb, ub, NullD, 4, _
           AddressOf funceval1, 0)
      If lp = 0 Then Exit Sub
 
      
      setlpcallbackfunc lp, AddressOf showiter1
   
      optimize lp

      solution lp, stat, objval, x, piout, slack, dj
      Form2.Text3 = "Status = " & stat
      Form2.Text4 = "Objective = " & objval
      Form2.Text1 = "x1 = " & x(0)
      Form2.Text2 = "x2 = " & x(1)
      Form2.Text5 = "slack1 = " & slack(0)
      Form2.Text7 = "slack2 = " & slack(1)
      Form2.Text6 = "piout1 = " & piout(0)
      Form2.Text8 = "piout2 = " & piout(1)
   
      setlpcallbackfunc lp, 0
       ' - call unloadprob() to release memory
       unloadprob lp
   Case 2
   
     '   Example program calling the nonlinear Solver DLL.
     'Solves the problem:

     'Minimize x ^ 2 + Y ^ 2
     'Subject to:
     '   X + Y = 1
     '   X * Y >= 0

     '(Solution is X = Y = 0.5, Objective = 0.5)

       rhs(0) = 1
       rhs(1) = 0
       sense(0) = Asc("E")
       sense(1) = Asc("G")
       lb(0) = -INFBOUND
       lb(1) = -INFBOUND
       ub(0) = INFBOUND
       ub(1) = INFBOUND
       x(0) = 0
       x(1) = 1
       setintparam 0, PARAM_ARGCK, 1
       ' Ask the Solver DLL to call our jacobian() routine, and *check*
       ' the partial derivatives we supply against its own "rise over run"
       ' derivative calculations */
       
    
      lp = loadnlp(PROBNAME, 2, 2, 1, obj, rhs, sense, _
            NullL, NullL, NullL, matval, x, lb, ub, NullD, 4, _
           AddressOf funceval1, AddressOf jacobian1)
      If lp = 0 Then Exit Sub
 
      setintparam lp, PARAM_DERIV, 3
      optimize lp

      solution lp, stat, objval, x, piout, slack, dj
      Form2.Text3 = "Status = " & stat
      Form2.Text4 = "Objective = " & objval
      Form2.Text1 = "x1 = " & x(0)
      Form2.Text2 = "x2 = " & x(1)
      Form2.Text5 = "slack1 = " & slack(0)
      Form2.Text7 = "slack2 = " & slack(1)
      Form2.Text6 = "piout1 = " & piout(0)
      Form2.Text8 = "piout2 = " & piout(1)
   
       ' - call unloadprob() to release memory
       unloadprob lp
    Case 3
    '   Example program calling the nonlinear Solver DLL.
     'Attempt to solve the problem:

     'Minimize x ^ 2 + Y ^ 2
     'Subject to:
     '   X * Y = 1
     '   X * Y = 0

     'This problem is infeasible, because the two constraints conflict.
     'We will call findiis() and getiis() to help isolate the source
     'of the infeasibility.

       rhs(0) = 1
       rhs(1) = 0
       sense(0) = Asc("E")
       sense(1) = Asc("E")
       lb(0) = -INFBOUND
       lb(1) = -INFBOUND
       ub(0) = INFBOUND
       ub(1) = INFBOUND
       x(0) = 0.25
       x(1) = 0.25
       setintparam 0, PARAM_ARGCK, 1
       lp = loadnlp(PROBNAME, 2, 2, 1, obj, rhs, sense, _
            NullL, NullL, NullL, matval, x, lb, ub, NullD, 4, _
           AddressOf funceval3, 0)
       If lp = 0 Then Exit Sub
 
       optimize lp

       solution lp, stat, objval, x, piout, slack, dj
       Form2.Text3 = "Status = " & stat
       Form2.Text4 = "Objective = " & objval
      
       If stat = PSTAT_INFEASIBLE Then
          setlpcallbackfunc lp, 0
          findiis lp, iisrows, iiscols
          MsgBox "Findiis: iisrows = " & Trim(Str(iisrows)) & " iiscols = " & Trim(Str(iiscols))
          Form2.Text1 = "iisrows = " & Trim(Str(iisrows))
          Form2.Text2 = "iiscols = " & Trim(Str(iiscols))
      
          ReDim rowbdstat(iisrows - 1) As Long
          ReDim rowind(iisrows - 1) As Long
          getiis lp, stat, rowind, rowbdstat, iisrows, NullL, NullL, iiscols
          Form2.Text5 = "rowind1 = " & rowind(0)
          Form2.Text6 = "rowbdstat1 = " & rowbdstat(0)
          Form2.Text7 = "rowind1 = " & rowind(1)
          Form2.Text8 = "rowbdstat1 = " & rowbdstat(1)
       End If
  
       ' - call unloadprob() to release memory
       unloadprob lp
    Case 4
    '   Example C program calling the nonlinear Solver DLL for a series of
    '   problems which may be linear or nonlinear.  This situation might
    '   arise if you are calling some external program, or using your own
    '   interpreter, to evaluate the problem functions.  We will define and
    '   solve two example problems:

    '   Nonlinear problem:

    '   Minimize x ^ 2 + Y ^ 2
    '   Subject to:
    '   X + Y = 1
    '  X * Y >= 0

    ' (Solution is X = Y = 0.5, Objective = 0.5)

    ' Alternate linear problem:

    ' Minimize 2 * X + Y
    ' Subject to:
    '  X + Y = 1
    '  3 * X - Y >= 0

    ' (Solution is X = 0.25, Y = 0.75, Objective = 1.25)

    ' In this example, we call testnltype() to determine whether
    ' the problem is linear or nonlinear.  If it is linear, we
    ' solve it first with the nonlinear Solver engine, then solve
    ' it again with the linear (Simplex) Solver engine.

       rhs(0) = 1
       rhs(1) = 0
       sense(0) = Asc("E")
       sense(1) = Asc("G")
       lb(0) = -10
       lb(1) = -10
       ub(0) = 10
       ub(1) = 10
       x(0) = 0
       x(1) = 0
       setintparam 0, PARAM_ARGCK, 1
      
       lp = loadnlp(PROBNAME, 2, 2, 1, obj, rhs, sense, _
            NullL, NullL, NullL, matval, x, lb, ub, NullD, 4, _
           AddressOf funceval4, 0)
       If lp = 0 Then Exit Sub
 
       ' Test the problem to determine linearity / nonlinearity */
       
       testnltype lp, 1, NullD, nlstat, NullB, NullB
       If nlstat Then
          MsgBox "Testnltype: NONLINEAR"
       Else
          MsgBox "Testnltype: LINEAR"
       End If
       ' Solve the problem (using the NLP Solver)
       optimize lp
       solution lp, stat, objval, x, piout, slack, dj
       Form2.Text3 = "Status = " & stat
       Form2.Text4 = "Obj = " & objval
       Form2.Text1 = "x1 = " & x(0)
       Form2.Text2 = "x2 = " & x(1)
       If nlstat Then Exit Sub
       
       unloadprob lp
       Form2.Label6 = "First solution via loadnlp, second via loadlp"
       Form2.Label6.Visible = True
       lp = loadlp(PROBNAME, 2, 2, 1, obj, rhs, sense, _
              NullL, NullL, NullL, matval, lb, ub, NullD, 2, 2, 4)
       optimize lp
       solution lp, stat, objval, x, piout, slack, dj
       Form2.Text5 = "Status = " & stat
       Form2.Text6 = "Obj = " & objval
       Form2.Text7 = "x1 = " & x(0)
       Form2.Text8 = "x2 = " & x(1)
       
       ' - call unloadprob() to release memory
       unloadprob lp
    Case 5
       ' Example program calling the nonsmooth Solver DLL.
       ' Solves the Branin Function

       Dim mid(0 To 1) As Double
       Dim disp(0 To 1) As Double
       Dim lower(0 To 1) As Double
       Dim upper(0 To 1) As Double
       
       lb(0) = -5
       lb(1) = -5
       ub(0) = 10
       ub(1) = 10
       x(0) = 1
       x(1) = 1
       
       setintparam 0, PARAM_ARGCK, 1
       lp = loadnlp(PROBNAME, 2, 0, 1, obj, NullD, NullB, _
            NullL, NullL, NullL, NullD, x, lb, ub, NullD, 0, _
            AddressOf funceval5, 0)
       If lp = 0 Then Exit Sub
       
       setintparam lp, PARAM_NOIMP, 1 ' 1 second
       
       setlpcallbackfunc lp, AddressOf showiter1
       loadnltype lp, NullB, NullB
       optimize lp

       solution lp, stat, objval, x, NullD, NullD, NullD
       
       varstat lp, 0, 1, mid, disp, lower, upper
       
       Form2.Text3 = "Status = " & stat
       Form2.Text4 = "Objective = " & objval
       Form2.Text1 = "x1 = " & x(0)
       Form2.Text2 = "x2 = " & x(1)
       Form2.Text5 = "mid1 = " & mid(0)
       Form2.Text7 = "mid2 = " & mid(1)
       Form2.Text6 = "disp1 = " & disp(0)
       Form2.Text8 = "disp2 = " & disp(1)
       Form2.Text10 = "lower1 = " & lower(0)
       Form2.Text11 = "lower2 = " & lower(1)
       Form2.Text24 = "upper1 = " & upper(0)
       Form2.Text25 = "upper2 = " & upper(1)
    
       setlpcallbackfunc lp, 0
       ' - call unloadprob() to release memory
       unloadprob lp
    
    Case 6
       Dim lb2(0 To 2) As Double
       Dim ub2(0 To 2) As Double
       Dim x2(0 To 2) As Double
       Dim obj2(0 To 2) As Double
       lb2(0) = 0
       lb2(1) = 0
       lb2(2) = 0
       ub2(0) = 20
       ub2(1) = 20
       ub2(2) = 20
       x2(0) = 5
       x2(1) = 5
       x2(2) = 5
       
       setintparam 0, PARAM_ARGCK, 1
       lp = loadnlp(PROBNAME, 3, 0, -1, obj2, NullD, NullB, _
            NullL, NullL, NullL, NullD, x2, lb2, ub2, NullD, 0, _
            AddressOf funceval6, 0)
       If lp = 0 Then Exit Sub
       
       setintparam lp, PARAM_NOIMP, 1 ' 1 second
       
       setlpcallbackfunc lp, 0
       loadnltype lp, NullB, NullB
       optimize lp

       solution lp, stat, objval, x2, NullD, NullD, NullD
       
       Form2.Text3 = "Status = " & stat
       Form2.Text4 = "Objective = " & objval
       Form2.Text1 = "X = " & x2(0)
       Form2.Text2 = "Y = " & x2(1)
       Form2.Text5 = "Z = " & x2(1)
    
       setlpcallbackfunc lp, 0
       ' - call unloadprob() to release memory
       unloadprob lp

    End Select
End Sub

Private Sub Command2_Click()
    Unload Form2
End Sub

Private Sub Form_Activate()
   Form2.Command1.SetFocus
End Sub

Private Sub Label14_Click()
End Sub

Private Sub Label9_Click()

End Sub
