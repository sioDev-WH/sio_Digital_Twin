VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Example"
   ClientHeight    =   4305
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6840
   LinkTopic       =   "Form2"
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   4305
   ScaleWidth      =   6840
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   3480
      TabIndex        =   41
      Top             =   480
      Width           =   855
   End
   Begin VB.TextBox Text25 
      Height          =   285
      Left            =   4920
      TabIndex        =   40
      Top             =   1560
      Width           =   1215
   End
   Begin VB.TextBox Text24 
      Height          =   285
      Left            =   3480
      TabIndex        =   39
      Top             =   1560
      Width           =   1215
   End
   Begin VB.TextBox Text23 
      Height          =   285
      Left            =   5880
      TabIndex        =   38
      Top             =   3960
      Width           =   735
   End
   Begin VB.TextBox Text22 
      Height          =   285
      Left            =   4920
      TabIndex        =   37
      Top             =   3960
      Width           =   735
   End
   Begin VB.TextBox Text21 
      Height          =   285
      Left            =   3480
      TabIndex        =   36
      Top             =   3960
      Width           =   735
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Exit"
      Height          =   495
      Left            =   120
      TabIndex        =   35
      Top             =   3600
      Width           =   1575
   End
   Begin VB.TextBox Text20 
      Height          =   285
      Left            =   5880
      TabIndex        =   34
      Top             =   3600
      Width           =   735
   End
   Begin VB.TextBox Text19 
      Height          =   285
      Left            =   4920
      TabIndex        =   33
      Top             =   3600
      Width           =   735
   End
   Begin VB.TextBox Text18 
      Height          =   285
      Left            =   3480
      TabIndex        =   32
      Top             =   3600
      Width           =   735
   End
   Begin VB.TextBox Text17 
      Height          =   285
      Left            =   5880
      TabIndex        =   31
      Top             =   3240
      Width           =   735
   End
   Begin VB.TextBox Text16 
      Height          =   285
      Left            =   4920
      TabIndex        =   30
      Top             =   3240
      Width           =   735
   End
   Begin VB.TextBox Text15 
      Height          =   285
      Left            =   3480
      TabIndex        =   29
      Top             =   3240
      Width           =   735
   End
   Begin VB.TextBox Text14 
      Height          =   285
      Left            =   5880
      TabIndex        =   25
      Top             =   2640
      Width           =   735
   End
   Begin VB.TextBox Text13 
      Height          =   285
      Left            =   4920
      TabIndex        =   24
      Top             =   2640
      Width           =   735
   End
   Begin VB.TextBox Text12 
      Height          =   285
      Left            =   3480
      TabIndex        =   23
      Top             =   2640
      Width           =   735
   End
   Begin VB.TextBox Text11 
      Height          =   285
      Left            =   5880
      TabIndex        =   22
      Top             =   2280
      Width           =   735
   End
   Begin VB.TextBox Text10 
      Height          =   285
      Left            =   4920
      TabIndex        =   21
      Top             =   2280
      Width           =   735
   End
   Begin VB.TextBox Text9 
      Height          =   285
      Left            =   3480
      TabIndex        =   20
      Top             =   2280
      Width           =   735
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
      TabIndex        =   43
      Top             =   1560
      Visible         =   0   'False
      Width           =   3255
   End
   Begin VB.Label Label16 
      Caption         =   ", integer"
      Height          =   255
      Left            =   1560
      TabIndex        =   42
      Top             =   1320
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.Label Label15 
      Caption         =   "Upper"
      Height          =   255
      Left            =   5880
      TabIndex        =   28
      Top             =   3000
      Width           =   615
   End
   Begin VB.Label Label14 
      Caption         =   "Lower"
      Height          =   255
      Left            =   4920
      TabIndex        =   27
      Top             =   3000
      Width           =   615
   End
   Begin VB.Label Label13 
      Caption         =   "Constraint RHS"
      Height          =   255
      Left            =   3480
      TabIndex        =   26
      Top             =   3000
      Width           =   1335
   End
   Begin VB.Label Label12 
      Caption         =   "Lower"
      Height          =   255
      Left            =   4920
      TabIndex        =   19
      Top             =   2040
      Width           =   615
   End
   Begin VB.Label Label11 
      Caption         =   "Upper"
      Height          =   255
      Left            =   5880
      TabIndex        =   18
      Top             =   2040
      Width           =   615
   End
   Begin VB.Label Label10 
      Caption         =   "Obj Coefficient"
      Height          =   255
      Left            =   3480
      TabIndex        =   17
      Top             =   2040
      Width           =   1215
   End
   Begin VB.Label Label9 
      Caption         =   "9 x1 +  6 x2 <= 54"
      Height          =   255
      Left            =   840
      TabIndex        =   8
      Top             =   600
      Width           =   1695
   End
   Begin VB.Label Label8 
      Caption         =   "Objective = 16.4"
      Height          =   255
      Left            =   120
      TabIndex        =   7
      Top             =   2040
      Width           =   6135
   End
   Begin VB.Label Label7 
      Caption         =   "LP solution: x1 = 2.8, x2 = 3.6"
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
      Width           =   1695
   End
   Begin VB.Label Label5 
      Caption         =   "5 x1 + 10 x2 <= 50"
      Height          =   255
      Left            =   840
      TabIndex        =   4
      Top             =   1080
      Width           =   1575
   End
   Begin VB.Label Label4 
      Caption         =   "6 x1 +  7 x2 <= 42"
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
      Caption         =   "Maximize   2 x1 +  3 x2"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   360
      Width           =   2655
   End
   Begin VB.Label Label1 
      Caption         =   "Example 1: Solves the LP model:"
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

   ' set up the LP problem
   Dim ret As Long
   
   Select Case Left(Form2.Label1, 9)
   Case "Example 1"
       lp = loadlp(PROBNAME, 2, 3, -1, obj(0), rhs(0), sense(0), _
             -1, -1, -1, matval(0), lb(0), ub(0), -1, 2, 3, 6)
             
       If (lp = 0) Then Exit Sub
       
       'set up the callback
       'setlpcallbackfunc AddressOf lpcallback
    
       'solve the problem
       optimize lp
    
       ' obtain the solution: display objective and variables
       solution lp, stat, objval, x(0), piout(0), slack(0), dj(0)
       Form2.Text3 = "LPStatus = " & Trim(Str(stat))
       Form2.Text4 = "Objective = " & Trim(Str(objval))
       
       ' display constraint slacks and dual values
       Form2.Text1 = "x1 = " & x(0)
       Form2.Text2 = "x2 = " & x(1)
       
       Form2.Text5 = "slack1 = " & slack(0)
       Form2.Text6 = "piout1 = " & piout(0)
       Form2.Text7 = "slack2 = " & slack(1)
       Form2.Text8 = "piout2 = " & piout(1)
       Form2.Text24 = "slack3 = " & slack(2)
       Form2.Text25 = "piout3 = " & piout(2)
          
       
       ' obtain and display sensitivity analysis information
       objsa lp, 0, 1, varlow(0), varupp(0)
       Form2.Text9 = obj(0)
       Form2.Text10 = varlow(0)
       Form2.Text11 = varupp(0)
       Form2.Text12 = obj(1)
       Form2.Text13 = varlow(1)
       Form2.Text14 = varupp(1)
       
       rhssa lp, 0, 2, conlow(0), conupp(0)
       
       Form2.Text15 = rhs(0)
       Form2.Text16 = conlow(0)
       Form2.Text17 = conupp(0)
       Form2.Text18 = rhs(1)
       Form2.Text19 = conlow(1)
       Form2.Text20 = conupp(1)
       Form2.Text21 = rhs(2)
       Form2.Text22 = conlow(2)
       Form2.Text23 = conupp(2)
      
       'remove the callback function
       setlpcallbackfunc lp, 0
    
       ' - call unloadprob() to release memory
       unloadprob lp
   Case "Example 2"
       lp = loadlp(PROBNAME, 2, 3, -1, obj(0), rhs(0), sense(0), _
             matbeg(0), matcnt(0), matind(0), matval(0), lb(0), ub(0), -1, 2, 3, 6)
             
       If (lp = 0) Then Exit Sub
       
       loadctype lp, ctype(0)
       
       ' lpwrite() can be called anytime after the problem
       ' is defined, and before unloadprob() is called.  It
       ' will write out the following text in file vcexamp1:
       ' Maximize lp / MIP
       ' obj: 2.0 x1 + 3.0 x2
       ' Subject To
       ' c1:  9.0 x1 + 6.0 x2 <= 54.0
       ' c2:  6.0 x1 + 7.0 x2 <= 42.0
       ' c3:  5.0 x1 + 10.0 x2 <= 50.0
       ' Bounds
       ' 0.0 <= x1 <= +infinity
       ' 0.0 <= x2 <= +infinity
       ' Integers
       ' X1
       ' X2
       ' End
       lpwrite lp, "vbexamp1"
      
       'solve the problem
       mipoptimize lp
    
       ' obtain the solution: display objective and variables
       solution lp, stat, objval, x(0), -1, -1, -1
       Form2.Text3 = "LPStatus = " & Trim(Str(stat))
       Form2.Text4 = "Objective = " & Trim(Str(objval))
       
       Form2.Text1 = "x1 = " & x(0)
       Form2.Text2 = "x2 = " & x(1)
       
       ' - call unloadprob() to release memory
       unloadprob lp
    Case "Example 3"
       Dim iisrows As Long
       Dim iiscols As Long
       lp = loadlp(PROBNAME, 2, 3, -1, obj(0), rhs(0), sense(0), _
             -1, -1, -1, matval(0), lb(0), ub(0), -1, 2, 3, 6)
             
       If (lp = 0) Then Exit Sub
       
       'solve the problem
       optimize lp
    
       ' obtain the solution: display objective and variables
       solution lp, stat, objval, x(0), -1, -1, -1
       Form2.Text3 = "LPStatus = " & Trim(Str(stat))
       Form2.Text4 = "Objective = " & Trim(Str(objval))
                       
       ' if infeasible, find and display an Irreducibly
       ' Infeasible Subset (IIS) of the constraints
       If stat = PSTAT_INFEASIBLE Then
          findiis lp, iisrows, iiscols
          MsgBox "Findiis: iisrows = " & Trim(Str(iisrows)) & " iiscols = " & Trim(Str(iiscols))
          Form2.Text1 = "iisrows = " & Trim(Str(iisrows))
          Form2.Text2 = "iiscols = " & Trim(Str(iiscols))
      
          ReDim rowbdstat(iisrows - 1) As Long
          ReDim colbdstat(iiscols - 1) As Long
          ReDim rowind(iisrows - 1) As Long
          ReDim colind(iiscols - 1) As Long
          getiis lp, stat, rowind(0), rowbdstat(0), iisrows, colind(0), colbdstat(0), iiscols
          Form2.Text5 = "rowind1 = " & rowind(0)
          Form2.Text6 = "rowbdstat1 = " & rowbdstat(0)
          Form2.Text7 = "colind1 = " & colind(0)
          Form2.Text8 = "colbdstat1 = " & colbdstat(0)
          Form2.Text24 = "colind2 = " & colind(1)
          Form2.Text25 = "colbdstat2 = " & colbdstat(1)
          
          iiswrite lp, "iisexamp.txt"
       End If
       ' - call unloadprob() to release memory
       unloadprob lp
    Case "Example Q"
       ' set up the LP portion of the problem.  The LP portion
       ' of the objective is all 0's here; it could be elaborated
       ' to include transaction costs or other factors. */
       lp = loadlp(PROBNAME, 5, 2, 1, obj(0), rhs(0), sense(0), _
             matbeg(0), matcnt(0), matind(0), matval(0), lb(0), ub(0), -1, 5, 2, 10)
       
       If (lp = 0) Then Exit Sub
   
       'now set up the Q matrix to define the quadratic objective */
       loadquad lp, qmatbeg(0), qmatcnt(0), qmatind(0), qmatval(0), 25, x(0)

       ' solve the problem; obtain and display the solution
       optimize lp
       solution lp, stat, objval, x(0), -1, -1, -1
   
       Form2.Text3 = "LPStatus = " & Trim(Str(stat))
       Form2.Text4 = "Obj = " & Trim(Format(objval, "0.0####"))
       
       Form2.Text1 = "x1 = " & x(0)
       Form2.Text2 = "x2 = " & x(1)
       Form2.Text5 = "x3 = " & x(2)
       Form2.Text6 = "x4 = " & x(3)
       Form2.Text7 = "x5 = " & x(4)
       ' - call unloadprob() to release memory
       unloadprob lp
    Case "Example 5"
       ' we merely pass the right sizes on. Since "sense" and "ctype" get
       ' checked for validity, we do initialize them
       
       sense(0) = Asc("L")
       sense(1) = Asc("L")
       sense(2) = Asc("L")
       ctype(0) = Asc("C")
       ctype(1) = Asc("C")
       
       lp = loadlp(PROBNAME, 2, 3, -1, obj(0), rhs(0), sense(0), _
             -1, -1, -1, matval(0), lb(0), ub(0), -1, 2, 3, 6)
             
       If (lp = 0) Then Exit Sub
       loadctype lp, ctype(0)
         
         
       ' Now we read in the textfile "vbexamp1", and all arrays are filled in automatically
                
       ret = lpread(lp, "vbexamp1", -1, -1, -1, -1, -1, -1)
       
       If (ret <> 0) Then
          MsgBox "Please run Example 2 first to create a textfile containing the problem."
          unloadprob lp
          Exit Sub
       End If
       ' we can immediately solve the problem.
       
       mipoptimize lp
    
       ' obtain the solution: display objective and variables
       solution lp, stat, objval, x(0), -1, -1, -1
       Form2.Text3 = "LPStatus = " & Trim(Str(stat))
       Form2.Text4 = "Objective = " & Trim(Str(objval))
       
       Form2.Text1 = "x1 = " & x(0)
       Form2.Text2 = "x2 = " & x(1)
       
       ' - call unloadprob() to release memory
       unloadprob lp
          
       ' Next, we assume that the dimensions of the problem are
       'not known in advance.  We can call lpread() with a NULL
       'first argument to read the file and obtain the actual
       'problem dimensions.  Then, we would allocate arrays of
       'appropriate size (to keep this example simple, we'll
       're-use the arrays from the first example above).  We call
       'loadlp() to define a problem and return a pointer to it.
       'Next, we call lpread() again to read in the actual array
       'Values.Then we  'll be ready to call mipoptimize().

      '  Call lpread() to obtain the problem dimensions.  If
      '  the matcnt argument is passed (needed only for sparse
      ' problems), it must have at least as many elements as the
      ' number of variables in the largest problem to be handled.
      ' (If necessary, you can call lpread() twice, the first
      ' time to get this size via the numcols argument.)
   
      Dim objsen As Long
      Dim numcols As Long
      Dim numrows As Long
      Dim numints As Long
      Dim nzspace As Long
      Dim i As Long
            
      MsgBox "Read problem of unknown size"
      Form2.Text1 = ""
      Form2.Text2 = ""
      Form2.Text3 = ""
      Form2.Text4 = ""
       
      lpread 0, "vbexamp1", objsen, numcols, numrows, numints, matcnt(0), -1
       
      ' We would now allocate the x[], obj[], lb[], ub[], and
      '(if used) ctype[] and matbeg[] arrays to have numcols
      'elements, and the rhs[] and sense[] arrays to have
      'numrows elements.  For a dense problem, matval[] should
      'be allocated to have numcols * numrows elements.  For a
      'sparse problem, the matind[] and matval[] arrays should
      'be allocated to have nzspace elements, where nzspace is
      'the sum of the counts in matcnt[] as returned by lpread().
      '(To keep this example simple, we'll re-use the arrays
      'from the first example above).
 
      nzspace = 0
      For i = 0 To numcols - 1
          nzspace = nzspace + matcnt(i)
      Next
      '(we could now allocate matind[] and matval[] based on nzspace)
      For i = 0 To nzspace - 1
         matval(i) = 0
         matind(i) = 0
      Next
     '  matval[] and matind[] will be filled in by our next call to
     ' lpread(); we need only initialize matbeg[] based on matcnt[]
      matbeg(0) = 0
      For i = 1 To numcols - 1
         matbeg(i) = matbeg(i - 1) + matcnt(i - 1)
      Next
     ' Next, call loadlp() and loadctype() to define the problem
     '   and pass in arrays of appropriate dimension.

      lp = loadlp(PROBNAME, numcols, numrows, objsen, obj(0), rhs(0), sense(0), _
         -1, -1, -1, matval(0), lb(0), ub(0), -1, _
         numcols, numrows, nzspace)
      
      If (lp = 0) Then Exit Sub
      loadctype lp, ctype(0)
         
      ' Now we call lpread() to read in the actual array values.

      lpread lp, "vbexamp1", -1, -1, -1, -1, -1, -1

      'Finally, we call mipoptimize() and display the solution.

      mipoptimize lp
    
      ' obtain the solution: display objective and variables
      solution lp, stat, objval, x(0), -1, -1, -1
      Form2.Text3 = "LPStatus = " & Trim(Str(stat))
      Form2.Text4 = "Objective = " & Trim(Str(objval))
       
      Form2.Text1 = "x1 = " & x(0)
      Form2.Text2 = "x2 = " & x(1)
       
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

