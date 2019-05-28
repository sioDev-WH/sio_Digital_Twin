VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CPalette"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

'===================================================================
Private Declare Function MulDiv Lib "Kernel32" (ByVal nNumber As Long, ByVal nNumerator As Long, ByVal nDenominator As Long) As Long

Private m_collEntry As Collection


'===================================================================
Private Sub Class_Initialize()
  Set m_collEntry = New Collection
End Sub

Private Sub Class_Terminate()
  DestroyAll
  Set m_collEntry = Nothing
End Sub

Private Sub DestroyAll()
  Dim i As Long
  If Not m_collEntry Is Nothing Then
    For i = 1 To m_collEntry.Count
      m_collEntry.Remove 1
    Next i
  End If
End Sub

'===================================================================
'-------------------------
Public Sub GrowPalette(GeCtrl As CG, nGrowBy As Integer)
  On Error Resume Next
  GetGePalette GeCtrl
  DoGrowPalette nGrowBy
'  DoSortPaletteHLS
  SetGePalette GeCtrl
End Sub

'-------------------------
Public Sub SortPalette(GeCtrl As CG)
  Dim i As Long
  On Error Resume Next
  GetGePalette GeCtrl
'  DoSortPalette
  DoSortPaletteHLS
  
''  SortPaletteByH m_collEntry, True   ' true = ascending
  
  SetGePalette GeCtrl
End Sub

'-------------------------
Private Sub GetGePalette(GeCtrl As CG)
  Dim nDX As Long
  Dim R As Integer
  Dim G As Integer
  Dim B As Integer
  Dim FLAGS As Integer
  
  On Error Resume Next
  GeCtrl.SelRemoveAll
  DestroyAll
  For nDX = 0 To GeCtrl.PaletteEntryCount - 1 ' 255
    If GeCtrl.GetPaletteEntry(nDX, R, G, B, FLAGS) Then
      AddPaletteEntry nDX, R, G, B, FLAGS
    Else
      Debug.Print "Failed to Get entry " & nDX
    End If
  
'  If nDX = 15 Then
'    Dim entry As CPaletteEntry
'    Set entry = m_collEntry.Item(nDX)
'    Debug.Print "GET:itm: " & nDX & " HLS->" & entry.H & "," & entry.L & "," & entry.S
'    Debug.Print "GET:itm: " & nDX & " RGB->" & entry.r & "," & entry.G & "," & entry.B
'  End If
  
  
  Next nDX
End Sub

'-------------------------
Private Sub DoGrowPalette(nGrowBy As Integer)
  Dim nDX As Long
  Dim R As Integer
  Dim G As Integer
  Dim B As Integer
  Dim FLAGS As Integer
  Dim Entry As CPaletteEntry
  Dim entryNew As CPaletteEntry
  
  On Error Resume Next
  For nDX = 1 To nGrowBy
    Set Entry = m_collEntry.Item(nDX)
    Set entryNew = New CPaletteEntry
    m_collEntry.Add entryNew
'    With entry
      entryNew.R = 99 + nDX ' .r
      entryNew.G = 99 + nDX ' .g
      entryNew.B = 99 + nDX ' .b
      entryNew.FLAGS = 0  ' .FLAGS
'    End With
  Next nDX
  
End Sub
'-------------------------
Private Sub SetGePalette(GeCtrl As CG)
  Dim nDX As Long
  Dim R As Integer
  Dim G As Integer
  Dim B As Integer
  Dim FLAGS As Integer
  Dim bRet As Boolean
  Dim Entry As CPaletteEntry
  
  On Error Resume Next
  For nDX = 1 To m_collEntry.Count
    Set Entry = m_collEntry.Item(nDX)
    With Entry
      R = .R
      G = .G
      B = .B
      FLAGS = .FLAGS
    End With
    
    bRet = GeCtrl.SetPaletteEntry(nDX - 1, R, G, B, FLAGS)
    If Not bRet Then Debug.Print "Failed to add entry " & nDX
    
'    If (nDX - 1) = 15 Then
'      Debug.Print "SET:itm: " & (nDX - 1) & " HLS->" & entry.H & "," & entry.L & "," & entry.S
'      Debug.Print "SET:itm: " & (nDX - 1) & " RGB->" & entry.R & "," & entry.G & "," & entry.B
'    End If
  
  Next nDX
  ''
  If Err <> 0 Then Debug.Print "SetGePalette: " & Error
  
End Sub

'-------------------------
Private Sub AddPaletteEntry(nDX As Long, R As Integer, G As Integer, B As Integer, FLAGS As Integer)
  Dim Entry As CPaletteEntry
  Set Entry = New CPaletteEntry
  m_collEntry.Add Entry
  With Entry
    .nDX = nDX
    .R = R
    .G = G
    .B = B
    .FLAGS = FLAGS
    .CalcHLS      ' compute HLS values
  End With
  
'  Debug.Print "itm: " & m_collEntry.Count & " HLS->" & entry.H & "," & entry.L & "," & entry.S

End Sub


'-------------------------
Private Sub DoSortPaletteHLS()
  Dim collFixed As Collection
  Dim colltmp As Collection
  Dim i As Long
  
  On Error Resume Next
  
  Set collFixed = New Collection    ' fixed colors
  Set colltmp = New Collection
  
    ' copy fixed
  For i = 1 To 10
    collFixed.Add m_collEntry.Item(i)
  Next i
  For i = m_collEntry.Count - 9 To m_collEntry.Count
    collFixed.Add m_collEntry.Item(i)
  Next i
    ' copy variable
  For i = 11 To m_collEntry.Count - 10
    colltmp.Add m_collEntry.Item(i)
  Next i
  
  SortHUE colltmp
  SortSAT colltmp
  
    
    ' flush current
  For i = 1 To m_collEntry.Count
    m_collEntry.Remove 1
  Next i
    ' copy fixed - start
  For i = 1 To 10
    m_collEntry.Add collFixed.Item(i)
  Next i
    ' copy variable
  For i = 1 To colltmp.Count
    m_collEntry.Add colltmp.Item(i)
  Next i
    ' copy fixed - end
  For i = collFixed.Count - 9 To collFixed.Count
    m_collEntry.Add collFixed.Item(i)
  Next i
  
  ''
  Set colltmp = Nothing
  Set collFixed = Nothing
  If Err <> 0 Then MsgBox "Error"

End Sub

'-------------------------------
Private Function SortHUE(collItem As Collection)
  Dim i, j, nCount As Long
  Dim fSwap As Boolean
  Dim fDoSwap As Boolean
  Dim obj1 As CPaletteEntry
  Dim obj2 As CPaletteEntry
  Dim L1 As Long, L2 As Long
  Dim S1 As Long, S2 As Long
  Dim H1 As Long, H2 As Long
  
  nCount = collItem.Count
  ' need more than 1 item to sort
  If nCount < 2 Then Exit Function
    
  For i = 1 To nCount
    fSwap = False
    For j = 1 To nCount - 1
      fDoSwap = False
      Set obj1 = collItem.Item(j)
      Set obj2 = collItem.Item(j + 1)
      L1 = obj1.L: H1 = obj1.H: S1 = obj1.S
      L2 = obj2.L: H2 = obj2.H: S2 = obj2.S
      
'      If L1 > L2 Then fDoSwap = True
      If H1 > H2 Then fDoSwap = True
'      If S1 > S2 Then fDoSwap = True

'      If (H1 < H2 _
'          Or (H1 < H2 And Abs(L1 - 180) < Abs(L2 - 180)) _
'          Or (H1 < H2 And Abs(S1 - 180) < Abs(S2 - 180) And _
'          Abs(L1 - 180) < Abs(L2 - 180))) _
'      Then
'        fDoSwap = True
'      End If
      
'      If _
'        L1 < L2 _
'        Or (L1 < L2 And H1 < H2) _
'        Or (L1 < L2 And H1 < H2 And S1 < S2) _
'      Then
'        fDoSwap = True
'      End If
      
      
      If fDoSwap Then
        collItem.Remove j
        collItem.Remove j
        If (collItem.Count < j) Then 'at end of list
          collItem.Add obj2
          collItem.Add obj1
        Else
          collItem.Add obj2, Before:=j
          collItem.Add obj1, Before:=j + 1
        End If
        fSwap = True
      End If
    Next j
    If fSwap = False Then Exit For
  Next i

End Function

'-------------------------------
Private Function SortSAT(collItem As Collection)
  ' sort, finding by increasing HUE groups
  Dim colltmp As Collection
  Dim collRes As Collection
  Dim pe As CPaletteEntry
  Dim nIndex As Long
  Dim H As Long, i As Long
  
  On Error Resume Next
  
  Set colltmp = New Collection
  Set collRes = New Collection
  nIndex = GetCollIndexWithLowestH(collItem)
  Set pe = collItem.Item(nIndex)
  H = pe.H
  While (nIndex > 0)
    
    GetAllWithHue collItem, colltmp, H
    If colltmp.Count > 0 Then H = colltmp.Item(1).H

    DoSortSAT colltmp
'    DoSortLUM collTmp
    
    For i = 1 To colltmp.Count
      collRes.Add colltmp.Item(i)
    Next i
    For i = 1 To colltmp.Count
      colltmp.Remove 1
    Next i
    
    nIndex = GetCollIndexWithLowestH_Base(collItem, H)
    If nIndex > 0 Then H = collItem.Item(nIndex).H
  Wend
  
  ''
  For i = 1 To collItem.Count
    collItem.Remove 1
  Next i
  For i = 1 To collRes.Count
    collItem.Add collRes.Item(i)
  Next i
  
  Set collRes = Nothing
  Set colltmp = Nothing

End Function
'-------------------------------
Private Function GetAllWithHue(collItem As Collection, colltmp As Collection, _
                    H As Long)
  Dim pe As CPaletteEntry
  Dim i As Long
  For i = 1 To collItem.Count
    Set pe = collItem.Item(i)
    If pe.H = H Then
      colltmp.Add pe
    End If
  Next i
End Function

'-------------------------------
Private Function DoSortSAT(collItem As Collection)
  Dim i, j, nCount As Long
  Dim fSwap As Boolean
  Dim fDoSwap As Boolean
  Dim obj1 As CPaletteEntry
  Dim obj2 As CPaletteEntry
  Dim L1 As Long, L2 As Long
  Dim S1 As Long, S2 As Long
  Dim H1 As Long, H2 As Long
  
  nCount = collItem.Count
  ' need more than 1 item to sort
  If nCount < 2 Then Exit Function
    
  For i = 1 To nCount
    fSwap = False
    For j = 1 To nCount - 1
      fDoSwap = False
      Set obj1 = collItem.Item(j)
      Set obj2 = collItem.Item(j + 1)
      L1 = obj1.L: H1 = obj1.H: S1 = obj1.S
      L2 = obj2.L: H2 = obj2.H: S2 = obj2.S
      
      If S1 > S2 Then fDoSwap = True
      
      If fDoSwap Then
        collItem.Remove j
        collItem.Remove j
        If (collItem.Count < j) Then 'at end of list
          collItem.Add obj2
          collItem.Add obj1
        Else
          collItem.Add obj2, Before:=j
          collItem.Add obj1, Before:=j + 1
        End If
        fSwap = True
      End If
    Next j
    If fSwap = False Then Exit For
  Next i

End Function

'-------------------------------
Private Function DoSortLUM(collItem As Collection)
  Dim i, j, nCount As Long
  Dim fSwap As Boolean
  Dim fDoSwap As Boolean
  Dim obj1 As CPaletteEntry
  Dim obj2 As CPaletteEntry
  Dim L1 As Long, L2 As Long
  Dim S1 As Long, S2 As Long
  Dim H1 As Long, H2 As Long
  
  nCount = collItem.Count
  ' need more than 1 item to sort
  If nCount < 2 Then Exit Function
    
  For i = 1 To nCount
    fSwap = False
    For j = 1 To nCount - 1
      fDoSwap = False
      Set obj1 = collItem.Item(j)
      Set obj2 = collItem.Item(j + 1)
      L1 = obj1.L: H1 = obj1.H: S1 = obj1.S
      L2 = obj2.L: H2 = obj2.H: S2 = obj2.S
      
      If L1 > L2 Then fDoSwap = True
      
      If fDoSwap Then
        collItem.Remove j
        collItem.Remove j
        If (collItem.Count < j) Then 'at end of list
          collItem.Add obj2
          collItem.Add obj1
        Else
          collItem.Add obj2, Before:=j
          collItem.Add obj1, Before:=j + 1
        End If
        fSwap = True
      End If
    Next j
    If fSwap = False Then Exit For
  Next i

End Function



'------------------------------
Private Function GetCollIndexWithLowestH_Base(coll As Collection, base As Long) As Long
  ' get index in collection with the lowest HUE (but higher than base)
  Dim i As Long
  Dim lRet As Long, lCur As Long
  Dim nIndex As Long
  lRet = 32000
  nIndex = 0
  For i = 1 To coll.Count
    lCur = coll.Item(i).H
    If (lCur < lRet) And (lCur > base) Then
      lRet = lCur
      nIndex = i
    End If
  Next i
  GetCollIndexWithLowestH_Base = nIndex
End Function
'------------------------------
Private Function GetCollIndexWithLowestL_Base(coll As Collection, base As Long) As Long
  ' get index in collection with the lowest LUM (but higher than base)
  Dim i As Long
  Dim lRet As Long, lCur As Long
  Dim nIndex As Long
  lRet = 32000
  nIndex = 0
  For i = 1 To coll.Count
    lCur = coll.Item(i).L
    If (lCur < lRet) And (lCur > base) Then
      lRet = lCur
      nIndex = i
    End If
  Next i
  GetCollIndexWithLowestL_Base = nIndex
End Function

'=============================================
#If 0 Then
'-------------------------
Private Sub DoSortPaletteHLS()
  Dim pe As CPaletteEntry
  Dim pe1 As CPaletteEntry    ' lowest
  Dim peBase As CPaletteEntry
  Dim collFixed As Collection
  Dim colltmp As Collection
  Dim collSort As Collection
  
  Dim nBase As Long, i As Long
  Dim j As Long
  
'  MsgBox "fix this fcn"
'  Exit Sub
  
  
  On Error Resume Next
  
  Set collFixed = New Collection    ' fixed colors
  Set colltmp = New Collection
  Set collSort = New Collection
  
  '' copy fixed
  For i = 1 To 10
    collFixed.Add m_collEntry.Item(i)
  Next i
  For i = m_collEntry.Count - 9 To m_collEntry.Count
    collFixed.Add m_collEntry.Item(i)
  Next i
  '' copy variable
  For i = 11 To m_collEntry.Count - 10
    colltmp.Add m_collEntry.Item(i)
  Next i
  
  ' sort by Hue
  For i = 1 To colltmp.Count
    Set pe = colltmp.Item(i)
    nBase = i
    Set peBase = colltmp.Item(nBase)
    
    For j = (i + 1) To colltmp.Count
      Set pe1 = colltmp.Item(j)
      
'      If (h1 < hb _
'        Or (h1 < hb And Abs(l1 - 180) < Abs(lb - 180)) _
'          Or (h1 < hb And Abs(s1 - 180) < Abs(sb - 180) And _
'          Abs(l1 - 180) < Abs(lb - 180)) _
'      ) Then
      
      If (pe1.H < peBase.H _
          Or (pe1.H < peBase.H And Abs(pe1.L - 180) < Abs(peBase.L - 180)) _
          Or (pe1.H < peBase.H And Abs(pe1.S - 180) < Abs(peBase.S - 180) And _
          Abs(pe1.L - 180) < Abs(peBase.L - 180))) _
      Then
        nBase = j
        Set peBase = colltmp.Item(nBase)
      End If
    Next j
  
    Set colltmp.Item(nBase) = pe
    Set colltmp.Item(i) = peBase
'    Debug.Print pe.nDX & "," & peBase.nDX
  Next i

  '' flush current
  For i = 1 To m_collEntry.Count
    m_collEntry.Remove 1
  Next i
  '' copy fixed - start
  For i = 1 To 10
    m_collEntry.Add collFixed.Item(i)
  Next i
  '' copy variable
  For i = 1 To colltmp.Count
    m_collEntry.Add colltmp.Item(i)
  Next i
  '' copy fixed - end
  For i = collFixed.Count - 9 To collFixed.Count
    m_collEntry.Add collFixed.Item(i)
  Next i
  
  
  Set colltmp = Nothing
  Set collSort = Nothing
  Set collFixed = Nothing
End Sub

#End If
'===============================================

'------------------------------
Private Function SortPaletteByH(coll As Collection, bAscending As Boolean)
  ' sort collection by HUE
  ' (ascending if bAscending = True, otherwise descending)
  Dim colltmp As Collection
  Dim i As Long
  Dim nCount As Long
  Dim nIndex As Long
  On Error Resume Next
  Set colltmp = New Collection
    ' add to collection in ascending/decending HUE order, removing as we go
  While (coll.Count > 0)
    If bAscending Then
      nIndex = GetCollIndexWithLowestH(coll)
    Else
      nIndex = GetCollIndexWithHighestH(coll)
    End If
    colltmp.Add coll.Item(nIndex)
    coll.Remove nIndex
  Wend
    ' add Tmp to coll
  nCount = colltmp.Count
  For i = 1 To nCount
    coll.Add colltmp.Item(i)
  Next i
    ' cleanup
  Set colltmp = Nothing
End Function
  
'------------------------------
Private Function GetCollIndexWithLowestH(coll As Collection) As Long
  ' get index in collection with the lowest HUE
  Dim i As Long
  Dim nRowRet As Long, nRowCur As Long
  Dim nIndex As Long
  nRowRet = 32000
  nIndex = 1
  For i = 1 To coll.Count
    nRowCur = coll.Item(i).H
    If nRowCur < nRowRet Then
      nRowRet = nRowCur
      nIndex = i
    End If
  Next i
  GetCollIndexWithLowestH = nIndex
End Function
'------------------------------
Private Function GetCollIndexWithLowestL(coll As Collection) As Long
  ' get index in collection with the lowest LUM
  Dim i As Long
  Dim nRowRet As Long, nRowCur As Long
  Dim nIndex As Long
  nRowRet = 32000
  nIndex = 1
  For i = 1 To coll.Count
    nRowCur = coll.Item(i).L
    If nRowCur < nRowRet Then
      nRowRet = nRowCur
      nIndex = i
    End If
  Next i
  GetCollIndexWithLowestL = nIndex
End Function
'------------------------------
Private Function GetCollIndexWithLowestS(coll As Collection) As Long
  ' get index in collection with the lowest SAT
  Dim i As Long
  Dim nRowRet As Long, nRowCur As Long
  Dim nIndex As Long
  nRowRet = 32000
  nIndex = 1
  For i = 1 To coll.Count
    nRowCur = coll.Item(i).S
    If nRowCur < nRowRet Then
      nRowRet = nRowCur
      nIndex = i
    End If
  Next i
  GetCollIndexWithLowestS = nIndex
End Function

'------------------------------
Private Function GetCollIndexWithHighestH(coll As Collection) As Long
  ' get index in collection with the highest HUE number
  Dim i As Long
  Dim nRowRet As Long, nRowCur As Long
  Dim nIndex As Long
  nRowRet = -32000
  nIndex = 1
  For i = 1 To coll.Count
    nRowCur = coll.Item(i).H  ' L
    If nRowCur > nRowRet Then
      nRowRet = nRowCur
      nIndex = i
    End If
  Next i
  GetCollIndexWithHighestH = nIndex
End Function








'-------------------------
Private Sub DoSortPalette()
  On Error Resume Next
  Dim pe As CPaletteEntry
  Dim pe1 As CPaletteEntry
  Dim peBase As CPaletteEntry

  Dim nBase As Long, i As Long
  Dim j As Long
  Dim H As Long, L As Long, S As Long
  
  For i = 11 To m_collEntry.Count - 10
    Set pe = m_collEntry.Item(i)
'    RGBToHLS1 pe.r, pe.g, pe.b, h, l, s
  
    nBase = i
    Set peBase = m_collEntry.Item(nBase)
    
'    Dim hb As Long, lb As Long, sb As Long
'    RGBToHLS1 peBase.r, peBase.g, peBase.b, hb, lb, sb

    For j = (i + 1) To m_collEntry.Count - 10
      Set pe1 = m_collEntry.Item(j)
      
'      Dim h1 As Long, l1 As Long, s1 As Long
'      RGBToHLS1 pe1.r, pe1.g, pe1.b, h1, l1, s1
'      If (h1 < hb _
'        Or (h1 < hb And Abs(l1 - 180) < Abs(lb - 180)) _
'          Or (h1 < hb And Abs(s1 - 180) < Abs(sb - 180) And _
'          Abs(l1 - 180) < Abs(lb - 180)) _
'      ) Then
      
      If (pe1.R < peBase.R Or _
          (pe1.R < peBase.R And pe1.G < peBase.G) Or _
          (pe1.R < peBase.R And pe1.G < peBase.G And pe1.B < peBase.B)) _
      Then
        ''
        nBase = j
        Set peBase = m_collEntry.Item(nBase)
'        RGBToHLS1 peBase.r, peBase.g, peBase.b, hb, lb, sb
'        Exit For
        ''
      End If
    Next j
  
''''''''''''''
    Dim peA As CPaletteEntry
    Set peA = m_collEntry.Item(nBase)
    If peA.R <> pe.R Or peA.G <> pe.G Or peA.B <> pe.B Then
      Debug.Print "Swapping index " & nBase; " for index " & i
    End If
''''''''''''''
    Set m_collEntry.Item(nBase) = pe
    Set m_collEntry.Item(i) = peBase
  Next i

End Sub


'====================================================================
'====================================================================
Private Function Min1(a As Long, B As Long) As Long
  Min1 = IIf(a <= B, a, B)
End Function
Private Function Max1(a As Long, B As Long) As Long
  Max1 = IIf(a >= B, a, B)
End Function

Private Sub RGBToHLS1(ByVal R As Long, ByVal G As Long, ByVal B As Long, _
                      H As Long, L As Long, S As Long)
'  ASSERT(r >= 0 && r <= 255);
'  ASSERT(g >= 0 && g <= 255);
'  ASSERT(b >= 0 && b <= 255);
  
  Dim nMin As Long, nMax As Long, nSum As Long, nDelta As Long
  nMin = Min1(Min1(R, G), B)
  nMax = Max1(Max1(R, G), B)
  nSum = nMax + nMin
  nDelta = nMax - nMin

  ' lightness
  L = MulDiv(240, nSum, 2 * 255)

  If (nDelta = 0) Then
    ' achromatic
    S = 0
    H = 160
  Else
    ' chromatic
    ' calculate saturation
    If (L <= 120) Then
      S = MulDiv(240, nDelta, nSum) '
    Else
      S = MulDiv(240, nDelta, (2 * 255) - nSum) ' TODO: check if MulDiv rounds
    End If

    ' calculate hue
    If (R = nMax) Then
      H = MulDiv(40, R - B, nDelta) - MulDiv(40, R - G, nDelta)
    ElseIf (G = nMax) Then
      H = 80 + MulDiv(40, G - R, nDelta) - MulDiv(40, G - B, nDelta)
    Else
      H = 160 + MulDiv(40, B - G, nDelta) - MulDiv(40, B - R, nDelta)
    End If
    
    If (H < 0) Then
      H = H + 240
    ElseIf (H > 240) Then
      H = H - 240
    End If
  End If
End Sub









