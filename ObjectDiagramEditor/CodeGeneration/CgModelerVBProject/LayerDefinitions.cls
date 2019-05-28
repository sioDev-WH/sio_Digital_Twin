VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "LayerDefinitions"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'======================================================================================
'
' Module:   LayerDefinitions (collection class for layers)
'
'--------------------------------------------------------------------------------------
'======================================================================================


Option Explicit

'=================================================================
' Start of Declarations Section
'=================================================================
' serializable
Private m_collLayers As Collection

' runtime
Private m_LastSelectedLayer As Integer ' last selected by user.
Private m_bReadOnly As Boolean  ' file is readonly
Private m_bDirty As Boolean
Private m_bResolvedWithGe As Boolean  ' did at least 1 layer resolve operation

'=================================================================
' End of Declarations Section
'=================================================================

'----------------------
Private Sub Class_Initialize()
  Set m_collLayers = New Collection
  m_LastSelectedLayer = -1
End Sub

'----------------------
Private Sub Class_Terminate()
  DestroyAll
  Set m_collLayers = Nothing
End Sub

'----------------------
Private Sub DestroyAll()
  ' destroyall entries
  Dim i As Long
  Dim obj As LayerDefinition
  On Error Resume Next
  If Not m_collLayers Is Nothing Then
    For i = 1 To m_collLayers.Count
      m_collLayers.Remove 1
    Next i
  End If
End Sub

'-------------------------------
Private Sub InitNew()
  ' init with defaults
  Dim LayerDef As LayerDefinition
  
  On Error Resume Next
  DestroyAll
  
  ' layer 0 - default properties from CG
  Set LayerDef = CreateLayerDefForGeLayer(0)
  LayerDef.Name = "(none)"
  
  ' layer 1 for construction lines
  Set LayerDef = CreateLayerDefForGeLayer(1)
  LayerDef.Name = "Construction Lines"
  LayerDef.LineStyle = GEPS_DASH
  LayerDef.LineColor = 252  ' blue    189    ' bluish
  LayerDef.FillStyle = GEBS_NULL
  
'  ' layer 1 for more construction lines
'  Set LayerDef = CreateLayerDefForGeLayer(2)
'  LayerDef.Name = "Construction LinesA"
'  LayerDef.LineStyle = 1

  ''
  m_bDirty = False

End Sub

'-------------------------------
Public Sub BeginPrint(GeCtrl As CG)
  ' hide those that are not to print
  Dim LayerDef As LayerDefinition
  Dim i As Long
  
  On Error Resume Next
  For i = 1 To m_collLayers.Count
    Set LayerDef = m_collLayers.Item(i)
    If Not LayerDef.CanPrint Then GeCtrl.LayerHide LayerDef.Layer
  Next i
End Sub
'-------------------------------
Public Sub EndPrint(GeCtrl As CG)
  ' unhide those that are not to print
  Dim LayerDef As LayerDefinition
  Dim i As Long
  
  On Error Resume Next
  For i = 1 To m_collLayers.Count
    Set LayerDef = m_collLayers.Item(i)
    If Not LayerDef.CanPrint Then
      If LayerDef.Visible Then
        GeCtrl.LayerShow LayerDef.Layer
      End If
    End If
  Next i
End Sub

'-------------------------------
Public Sub GetDefaultsFromGe(GeCtrl As CG)
  ' get default properties from CG and place in layer 0
  ' !! assume that CG has nothing in selection !!
  Dim LayerDef As LayerDefinition
  
  On Error Resume Next
  Set LayerDef = LayerDefForGeLayer(0)
  If Not LayerDef Is Nothing Then LayerDef.GetPropertiesFromGe GeCtrl
End Sub

'-------------------------------
Public Sub ResolveWithGe(GeCtrl As CG)
  ' resolve what I've got versus what is in drawing
  ''
  ' get list of layers and related info from CG
  ' return arrays of layer info (datatype = long)
  Dim aLayerNumber As Variant, aLayerVisible As Variant, aLayerLocked As Variant, aLayerMoveLocked As Variant
  Dim i As Integer, j As Integer
  Dim nLayer As Integer
  Dim uBnd As Integer
  Dim lBnd As Integer
  Dim LayerDef As LayerDefinition
  
  On Error Resume Next
  GeCtrl.LayerGetListExtended aLayerNumber, aLayerVisible, aLayerLocked, aLayerMoveLocked
  If Err <> 0 Then Exit Sub
  '
  uBnd = UBound(aLayerNumber)
  lBnd = LBound(aLayerNumber)
  ' test err. If empty, will be set
  If Err = 0 Then
    For i = lBnd To uBnd
      nLayer = aLayerNumber(i)
      Set LayerDef = LayerDefForGeLayer(nLayer)
      If Not LayerDef Is Nothing Then
        ' update state of layer def
        LayerDef.CanMove = IIf(aLayerMoveLocked(i) = 1, True, False)
        LayerDef.CanSelect = IIf(aLayerLocked(i) = 0, True, False)
        LayerDef.Visible = aLayerVisible(i)
      Else
        ' create new one and get properties of last item in layer from CG.
        Set LayerDef = CreateLayerDefForGeLayer(nLayer)
        If Not LayerDef Is Nothing Then
'          LayerDef.Name = "Style - " & LayerDef.Layer
          LayerDef.Name = LayerDef.Layer
          LayerDef.CanMove = IIf(aLayerMoveLocked(i) = 1, True, False)
          LayerDef.CanSelect = IIf(aLayerLocked(i) = 0, True, False)
          LayerDef.Visible = aLayerVisible(i)
          ' get props  of last item in layer from CG
        End If
      End If
    Next i
    
    ' remove those in my coll that are no in CG
    Dim LayerDefA As LayerDefinition
    Dim colltmp As New Collection
    Dim bRemove As Boolean
    
    For j = 1 To m_collLayers.Count
      bRemove = True
      Set LayerDefA = m_collLayers.Item(j)
      nLayer = LayerDefA.Layer
      For i = lBnd To uBnd
        If aLayerNumber(i) = nLayer Then
          bRemove = False
          Exit For
        End If
      Next i
      '
      If bRemove Then colltmp.Add LayerDefA
    Next j
    
    ' actaully remove em
    For j = 1 To colltmp.Count
      Set LayerDefA = colltmp.Item(j)
      RemoveLayerDef LayerDefA
    Next j
    '
  Else
    Err = 0 ' reset
  End If
  '
  m_bResolvedWithGe = True

End Sub

'-------------------------------
Public Property Get ResolvedWithGe() As Boolean
  ResolvedWithGe = m_bResolvedWithGe
End Property

'=================================================================
' Properties
'=================================================================
'-------------------------------
Public Property Get ReadOnly() As Boolean
  ReadOnly = m_bReadOnly
End Property
'-------------------------------
Public Property Let ReadOnly(ByVal bVal As Boolean)
  m_bReadOnly = bVal
End Property

'-------------------------------
Public Property Get IsDirty() As Boolean
  Dim i As Long
  Dim obj As LayerDefinition
  
  If Not m_bDirty Then
    For i = 1 To m_collLayers.Count
      Set obj = m_collLayers.Item(i)
      If obj.IsDirty Then
        IsDirty = True
        Exit Property
      End If
    Next i
  Else
    IsDirty = True
  End If
End Property
'-------------------------------
Public Property Get NextAvailableGeLayer() As Integer
  ' next layer available.
  ' Look for holes in my list. If found, return the 1st hole,
  ' otherwise, return next available Layer.
  
  Dim i As Long
  Dim obj As LayerDefinition
  Dim nLayer As Integer
  '
  nLayer = 1
  For i = 1 To m_collLayers.Count
    Set obj = m_collLayers.Item(i)
    If obj.Layer >= nLayer Then
      nLayer = obj.Layer + 1
    End If
  Next i
  '
  NextAvailableGeLayer = nLayer
End Property

'-------------------------------
Public Property Get LastSelectedLayer() As Integer
  ' last selected by user. Helper Property for controls using me.
  LastSelectedLayer = m_LastSelectedLayer
End Property
Public Property Let LastSelectedLayer(ByVal nVal As Integer)
  m_LastSelectedLayer = nVal
End Property
'-------------------------------
Public Property Get Count() As Long
  Count = m_collLayers.Count
End Property
'-------------------------------
Public Property Get Item(ByVal Index As Long) As LayerDefinition
  Set Item = m_collLayers.Item(Index)
End Property

'-------------------------------
Public Property Get LayerDefForGeLayer(ByVal nLayer As Integer) As LayerDefinition
  Dim i As Long
  Dim obj As LayerDefinition
  For i = 1 To m_collLayers.Count
    Set obj = m_collLayers.Item(i)
    If obj.Layer = nLayer Then
      Set LayerDefForGeLayer = obj
      Exit Property
    End If
  Next i
End Property

'-------------------------------
Public Property Get LayerDefbyName(ByVal strName As String) As LayerDefinition
  Dim i As Long
  Dim obj As LayerDefinition
  For i = 1 To m_collLayers.Count
    Set obj = m_collLayers.Item(i)
    If obj.Name = strName Then
      Set LayerDefbyName = obj
      Exit Property
    End If
  Next i
End Property
'-------------------------------
Public Function ValidateName(ByVal strName As String, strMsg As String) As Boolean
  ' validate the name as legal

#If 0 Then
'' Layers
'Global Const c_sLayerDefStgSep As String = "/"  ' storage separator - reserved character
  
  Dim obj As LayerDefinition
  On Error Resume Next
  If InStr(strName, c_sLayerDefStgSep) > 0 Then
    strMsg = "the character '" & c_sLayerDefStgSep & "' cannot be used in a name."
    Exit Function
  Else
    Set obj = LayerDefbyName(strName)
    If Not obj Is Nothing Then
      strMsg = "the name '" & obj.Name & "' is already used."
      Exit Function
    End If
  End If
#End If

  ValidateName = True
  
End Function
'-------------------------------
Public Sub RemoveLayerDef(LayerDef As LayerDefinition)
  ' remove from my coll
  Dim i As Long
  Dim obj As LayerDefinition
  For i = 1 To m_collLayers.Count
    Set obj = m_collLayers.Item(i)
    If obj Is LayerDef Then
      m_collLayers.Remove i
      Exit Sub
    End If
  Next i
End Sub

'-------------------------------
Public Function CreateLayerDef(objCopy As LayerDefinition) As LayerDefinition
  ' create next available and assign layer to it
  ' if objCopy is not nothing, then copy it
  
  Dim obj As LayerDefinition
  Dim iLayer As Integer
  
  On Error Resume Next
  
  iLayer = NextAvailableGeLayer
  Set obj = CreateLayerDefForGeLayer(iLayer)
  If Not obj Is Nothing Then
    If Not objCopy Is Nothing Then obj.AssumePropsFromObj objCopy
  End If
  Set CreateLayerDef = obj

End Function

'-------------------------------
Private Function CreateLayerDefForGeLayer(ByVal nLayer As Integer) As LayerDefinition
  ' create if don't already have
  Dim obj As LayerDefinition
  
  Set obj = LayerDefForGeLayer(nLayer)
  If obj Is Nothing Then
    Set obj = New LayerDefinition
    obj.Layer = nLayer
    m_collLayers.Add obj
    Set CreateLayerDefForGeLayer = obj
    m_bDirty = True
  End If
End Function



'==================================================================
'==================================================================
'-------------------------------
Public Function SerializeToGeFile(GeCtrl As CG, ByVal bSave As Boolean, ByVal strFile As String) As Boolean
  ' save/load from some other file
  SerializeToGeFile = DoSerializeToGe(GeCtrl, bSave, strFile, True)
End Function

'-------------------------------
Public Function SerializeToGe(GeCtrl As CG, ByVal bSave As Boolean) As Boolean
  ' serialize to graphic
  SerializeToGe = DoSerializeToGe(GeCtrl, bSave, "", False)
End Function
'-------------------------------
Private Function DoSerializeToGe(GeCtrl As CG, ByVal bSave As Boolean, _
                         ByVal strFile As String, ByVal bOtherFile As Boolean) As Boolean
  ' save to graphic
  Dim pb As PropertyBag
  Dim i As Integer
  Dim obj As LayerDefinition
  Dim nCnt As Integer
  Dim aVar As Variant
  Dim nSchema As Integer
  Dim strKey As String
  
  On Error Resume Next

  Set pb = New PropertyBag
  
  If bSave Then   '' SAVING
    nCnt = m_collLayers.Count
    For i = 1 To nCnt
      Set obj = m_collLayers.Item(i)
      strKey = i
      If Not obj.SerializeToPropertyBag(pb, strKey, bSave) Then Exit Function
    Next i
    ' write controlling data
    nSchema = 0
    pb.WriteProperty "Schema", nSchema, 0
    pb.WriteProperty "NumLayers", nCnt, 0

    If bOtherFile Then
      GeCtrl.SaveNamedStorageToFile strFile, c_sLayerDataName, pb.Contents
    Else
      GeCtrl.SaveNamedStorage c_sLayerDataName, pb.Contents
    End If
    
    ' save propbag to CG
    If Err = 0 Then
      DoSerializeToGe = True
      m_bDirty = False
    End If
  Else    '' LOADING
    DestroyAll

    If bOtherFile Then
      GeCtrl.LoadNamedStorageFromFile strFile, c_sLayerDataName, aVar
    Else
      GeCtrl.LoadNamedStorage c_sLayerDataName, aVar
    End If
    
    If Err <> 0 Then
      ' assume not there. initnew
'      InitNew
      DoSerializeToGe = True
      m_bDirty = False
      Exit Function
    End If
    pb.Contents = aVar    ' assign to propBags contents
    
    ' read controlling data
    nSchema = pb.ReadProperty("Schema", 0)
    nCnt = pb.ReadProperty("NumLayers", 0)
    For i = 1 To nCnt
      Set obj = New LayerDefinition
      m_collLayers.Add obj
      strKey = i
      obj.SerializeToPropertyBag pb, strKey, bSave
    Next i
  End If
  '
  DoSerializeToGe = True

End Function
