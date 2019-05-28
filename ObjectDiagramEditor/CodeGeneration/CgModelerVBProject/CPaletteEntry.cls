VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CPaletteEntry"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Declare Function MulDiv Lib "kernel32" (ByVal nNumber As Long, ByVal nNumerator As Long, ByVal nDenominator As Long) As Long


Public nDX As Long  ' index in palette table

Public R As Long
Public G As Long
Public B As Long
Public FLAGS As Integer

Public H As Long    ' Hue
Public S As Long    ' Satuation
Public L As Long    ' Luminisity

'====================================================================
'====================================================================
Public Sub CalcHLS()
  RGBToHLS1 R, G, B, H, L, S
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



