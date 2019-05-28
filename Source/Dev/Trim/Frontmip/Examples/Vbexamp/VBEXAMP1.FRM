VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Frontline Systems"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   Begin VB.CommandButton Command6 
      Caption         =   "Example 5"
      Height          =   375
      Left            =   1680
      TabIndex        =   13
      Top             =   2760
      Width           =   1215
   End
   Begin VB.CommandButton Command5 
      Caption         =   "Quit"
      Height          =   375
      Left            =   3120
      TabIndex        =   12
      Top             =   2760
      Width           =   1215
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Example 4"
      Height          =   375
      Left            =   240
      TabIndex        =   11
      Top             =   2760
      Width           =   1215
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Example 3"
      Height          =   375
      Left            =   3120
      TabIndex        =   10
      Top             =   2160
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Example 2"
      Height          =   375
      Left            =   1680
      TabIndex        =   9
      Top             =   2160
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Example 1"
      Height          =   375
      Left            =   240
      TabIndex        =   8
      Top             =   2160
      Width           =   1215
   End
   Begin VB.Label Label8 
      Caption         =   "Email info@frontsys.com"
      Height          =   375
      Left            =   2400
      TabIndex        =   7
      Top             =   1440
      Width           =   2295
   End
   Begin VB.Label Label7 
      Caption         =   "Fax (775) 831-0314"
      Height          =   255
      Left            =   2400
      TabIndex        =   6
      Top             =   1200
      Width           =   1935
   End
   Begin VB.Label Label6 
      Caption         =   "Tel (775) 831-0300"
      Height          =   255
      Left            =   2400
      TabIndex        =   5
      Top             =   960
      Width           =   1575
   End
   Begin VB.Label Label5 
      Caption         =   "NV 89450 USA"
      Height          =   255
      Left            =   240
      TabIndex        =   4
      Top             =   1680
      Width           =   1695
   End
   Begin VB.Label Label4 
      Caption         =   "Incline Village"
      Height          =   375
      Left            =   240
      TabIndex        =   3
      Top             =   1440
      Width           =   1455
   End
   Begin VB.Label Label3 
      Caption         =   "P.O. Box 4288"
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   1200
      Width           =   1695
   End
   Begin VB.Label Label2 
      Caption         =   "Frontline Systems Inc."
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   960
      Width           =   1815
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Small-Scale Solver Dynamic Link Library Version 3.5"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   4215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
'   Example 1: Solves the LP model:
'   Maximize   2 x1 +  3 x2
'   Subj to    9 x1 +  6 x2 <= 54
'              6 x1 +  7 x2 <= 42
'              5 x1 + 10 x2 <= 50
'   x1, x2 non-negative
'   LP solution: x1 = 2.8, x2 = 3.6
'   Objective = 16.4

'   This example shows the simple form of passing arguments to loadlp():
'   A dense (full-size N by M) matrix is passed as the matval argument
'   and NULL pointers are passed as the matbeg, matcnt & matind arguments.

'   This example also shows how to obtain LP sensitivity analysis info
'   by calling the objsa() and rhssa() functions.  These calls are valid
'   only for LP problems.  For QP problems, only dual values (the piout
'   and dj arguments of solution()) are available; for MIP problems, no
'   sensitivity analysis info is available (none would be meaningful).
'
'   This example uses a callback function to display the LP iterations.

   ReDim obj(0 To 1) As Double
   obj(0) = 2
   obj(1) = 3
   ReDim rhs(0 To 2) As Double
   rhs(0) = 54
   rhs(1) = 42
   rhs(2) = 50
   ReDim sense(0 To 2) As Byte
   ' L's for <=, E's for =, G's for >=
   sense(0) = Asc("L")
   sense(1) = Asc("L")
   sense(2) = Asc("L")
   ReDim matval(0 To 5) As Double
   matval(0) = 9
   matval(1) = 6
   matval(2) = 5
   matval(3) = 6
   matval(4) = 7
   matval(5) = 10
   ReDim lb(0 To 1) As Double
   lb(0) = 0
   lb(1) = 0
   ReDim ub(0 To 1) As Double
   ub(0) = INFBOUND
   ub(1) = INFBOUND
   ReDim x(0 To 1) As Double
   ReDim piout(0 To 2) As Double
   ReDim slack(0 To 2) As Double
   ReDim dj(0 To 1) As Double
   ReDim varlow(0 To 1) As Double
   ReDim varupp(0 To 1) As Double
   ReDim conlow(0 To 2) As Double
   ReDim conupp(0 To 2) As Double

   Form2.Show
End Sub

Private Sub Command2_Click()

'   Example 2: Solves the MIP model:
'   Maximize   2 x1 +  3 x2
'   Subj to    9 x1 +  6 x2 <= 54
'              6 x1 +  7 x2 <= 42
'              5 x1 + 10 x2 <= 50
'   x1, x2 non-negative, integer
'   MIP solution: x1 = 2, x2 = 4
'   Objective = 16

'   This example illustrates the full set of arguments, used to pass a
'   potentially sparse matrix to loadlp.  For each variable (column) i,
'   matbeg[i] and matcnt[i] are the beginning index and count of non-
'   zero coefficients in the matind and matval arrays.  For each such
'   coefficient, matind[k] is the constraint (row) index and matval[i]
'   is the coefficient value.  See the documentation for more details.

'   In this example, we also use two debugging features of the Solver
'   DLL:  (1) We call setintparam() to enable the display of error
'   MessageBoxes by the DLL routines if they detect an invalid value
'   in one of the arguments we pass (since there are no errors, none
'   will appear).  (2) We call lpwrite() to write out a file which
'   summarizes the LP/MIP problem in algebraic form.  This can help
'   us verify that the arguments we pass have defined the right problem.
'
   ReDim obj(0 To 1) As Double
   obj(0) = 2
   obj(1) = 3
   ReDim rhs(0 To 2) As Double
   rhs(0) = 54
   rhs(1) = 42
   rhs(2) = 50
   ReDim sense(0 To 2) As Byte
   ' L's for <=, E's for =, G's for >=
   sense(0) = Asc("L")
   sense(1) = Asc("L")
   sense(2) = Asc("L")
   ReDim ctype(0 To 1) As Byte
   ' I = integer, B = binary, C = continuous
   ctype(0) = Asc("I")
   ctype(1) = Asc("I")
   ReDim matbeg(0 To 1) As Long
   matbeg(0) = 0
   matbeg(1) = 3
   ReDim matcnt(0 To 1) As Long
   matcnt(0) = 3
   matcnt(1) = 3
   ReDim matind(0 To 5) As Long
   matind(0) = 0
   matind(1) = 1
   matind(2) = 2
   matind(3) = 0
   matind(4) = 1
   matind(5) = 2
   ReDim matval(0 To 5) As Double
   matval(0) = 9
   matval(1) = 6
   matval(2) = 5
   matval(3) = 6
   matval(4) = 7
   matval(5) = 10
   ReDim lb(0 To 1) As Double
   lb(0) = 0
   lb(1) = 0
   ReDim ub(0 To 1) As Double
   ub(0) = INFBOUND
   ub(1) = INFBOUND
   ReDim x(0 To 1) As Double
   
   AdjustFormforExample2
   Form2.Show
End Sub

Private Sub Command3_Click()

 '  Example 3: Attempt to solve the LP model:
 '  Maximize   2 x1 +  3 x2
 '  Subj to    9 x1 +  6 x2 <= 54
 '             6 x1 +  7 x2 <= 42
 '             5 x1 + 10 x2 <= -50
 '  x1, x2 non-negative
 '  Infeasible (due to non-negative variables and negative RHS)

 '  When solution() returns stat = PSTAT_INFEASIBLE, ask Solver DLL
 '  to find an Irreducibly Infeasible Subset (IIS) of the constraints:
 '  Row 2 (with the negative RHS) and lower bounds on both variables

 '  The constraint matrix is passed in simple (dense) form in matval[].


   ReDim obj(0 To 1) As Double
   obj(0) = 2
   obj(1) = 3
   ReDim rhs(0 To 2) As Double
   rhs(0) = 54
   rhs(1) = 42
   rhs(2) = -50
   ReDim sense(0 To 2) As Byte
   ' L's for <=, E's for =, G's for >=
   sense(0) = Asc("L")
   sense(1) = Asc("L")
   sense(2) = Asc("L")
   ReDim matval(0 To 5) As Double
   matval(0) = 9
   matval(1) = 6
   matval(2) = 5
   matval(3) = 6
   matval(4) = 7
   matval(5) = 10
   ReDim lb(0 To 1) As Double
   lb(0) = 0
   lb(1) = 0
   ReDim ub(0 To 1) As Double
   ub(0) = INFBOUND
   ub(1) = INFBOUND
   ReDim x(0 To 1) As Double
    
   AdjustFormforExample3
   Form2.Show
End Sub

Private Sub Command4_Click()

'   Example 4: Use the QP solver to perform
'   Markowitz-style portfolio optimization.
'   Variables are the percentages to be allocated
'   to each investment or asset class:
'      0 <= x1, x2, x3, x4 x5 <= 1
'   Minimize portfolio variance: [xi] Q [xi]
'   Subj to allocations: Sum (xi) = 1
'      and portfolio return: Sum (Ri xi) >= 0.085

'   The efficient portfolio is the QP solution (approx):
'      x1 = 0.462  x2 = 0  x3 = 0.313  x4 = 0  x5 = 0.225
'   The objective = approx. 0.00014 (minimum variance)

'   Both the constraint matrix and the Q matrix are passed
'   using the full set of arguments for sparse matrices.
   Dim i As Long
   ReDim obj(0 To 4) As Double
   For i = 0 To 4
      obj(i) = 0
   Next
   ReDim rhs(0 To 1) As Double
   rhs(0) = 1#
   rhs(1) = 0.085
   ReDim sense(0 To 1) As Byte
   sense(0) = Asc("E")
   sense(1) = Asc("G")
   ReDim matbeg(0 To 4) As Long
   ReDim matcnt(0 To 4) As Long
   ReDim matind(0 To 9) As Long
   ReDim lb(0 To 4) As Double
   ReDim ub(0 To 4) As Double
   For i = 0 To 4
      matbeg(i) = 2 * i
      matcnt(i) = 2
      matind(2 * i) = 0
      matind(2 * i + 1) = 1
      lb(i) = 0
      ub(i) = 1
   Next
   ReDim matval(0 To 9) As Double
   matval(0) = 1
   matval(1) = 0.086
   matval(2) = 1
   matval(3) = 0.071
   matval(4) = 1
   matval(5) = 0.095
   matval(6) = 1
   matval(7) = 0.107
   matval(8) = 1
   matval(9) = 0.069
   
   ReDim qmatbeg(0 To 4) As Long
   ReDim qmatcnt(0 To 4) As Long
   ReDim qmatind(0 To 24) As Long
   For i = 0 To 4
       qmatbeg(i) = 5 * i
       qmatcnt(i) = 5
       qmatind(i) = i
       qmatind(i + 5) = i
       qmatind(i + 10) = i
       qmatind(i + 15) = i
       qmatind(i + 20) = i
   Next
   ReDim qmatval(0 To 24) As Double
   ' The Q matrix specifies the covariance between each pair of assets
   qmatval(0) = 0.000204
   qmatval(1) = 0.000424
   qmatval(2) = 0.00017
   qmatval(3) = 0.000448
   qmatval(4) = -0.000014
   qmatval(5) = 0.000424
   qmatval(6) = 0.012329
   qmatval(7) = 0.001785
   qmatval(8) = 0.001633
   qmatval(9) = -0.000539
   qmatval(10) = 0.00017
   qmatval(11) = 0.001785
   qmatval(12) = 0.000365
   qmatval(13) = 0.000425
   qmatval(14) = -0.000075
   qmatval(15) = 0.000448
   qmatval(16) = 0.001633
   qmatval(17) = 0.000425
   qmatval(18) = 0.005141
   qmatval(19) = 0.000237
   qmatval(20) = -0.000014
   qmatval(21) = -0.000539
   qmatval(22) = -0.000075
   qmatval(23) = 0.000237
   qmatval(24) = 0.000509
   ReDim x(0 To 4) As Double
    
   AdjustFormforExample4
   Form2.Show
End Sub

Private Sub Command5_Click()
   End
End Sub

Private Sub Command6_Click()

   ' Here we use the lpread() function ro read in the model.
   
   'First, we assume that the dimensions of the problem
   'are known.  We call loadlp(), passing array arguments
   'of the proper dimension.  Since the sense[] and ctype[]
   'arrays are checked for validity, we initialize them. */

   ReDim obj(0 To 1) As Double
   ReDim rhs(0 To 2) As Double
   ReDim sense(0 To 2) As Byte
   ReDim ctype(0 To 1) As Byte
   ReDim matbeg(0 To 1) As Long
   ReDim matcnt(0 To 1) As Long
   ReDim matind(0 To 5) As Long
   ReDim matval(0 To 5) As Double
   ReDim lb(0 To 1) As Double
   ReDim ub(0 To 1) As Double
   ReDim x(0 To 1) As Double
      
   AdjustFormforExample5
   Form2.Show
End Sub
