VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CgConnectionDef"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public itemName As String       ' name of class item
Public itemType As Long         ' type of class item {attribute, operation, state, or transition}
Public itemID As String         ' ID of Class item
Public attrType As Long         ' attribute type {variable, parameter, connector, model, struct}
Public operType As Long         ' operation type {continuous, discontinuous, reset, other}
Public connName As String       ' name of connector object
Public ItemSizeName As String   ' name of class Size item
Public Face As Long             ' Left, Right, Top Bottom
Public order As Long            ' Order of connectors on that face
Public UserID As Long           ' Used to access the shape def connector for this connection def.

Public Function export() As String
  Dim szRet As String
  
  szRet = szRet & "<CgConnectionDef Name=" & Chr(34) & itemName & Chr(34)
  szRet = szRet & " ItemType=" & Chr(34) & itemType & Chr(34)
  szRet = szRet & " ItemID=" & Chr(34) & itemID & Chr(34)
  szRet = szRet & " AttrType=" & Chr(34) & attrType & Chr(34)
  szRet = szRet & " OperType=" & Chr(34) & operType & Chr(34)
  szRet = szRet & " ConnName=" & Chr(34) & connName & Chr(34)
  szRet = szRet & " ItemSizeName=" & Chr(34) & ItemSizeName & Chr(34)
  szRet = szRet & " UserID=" & Chr(34) & UserID & Chr(34)
  szRet = szRet & " />" & vbCrLf
  export = szRet
  
End Function

Public Sub import(elem As IXMLDOMElement)
  On Error Resume Next
  itemName = elem.getAttribute("Name")
  itemType = elem.getAttribute("ItemType")
  itemID = elem.getAttribute("ItemID")
  attrType = elem.getAttribute("AttrType")
  operType = elem.getAttribute("OperType")
  connName = elem.getAttribute("ConnName")
  UserID = elem.getAttribute("UserID")
  ItemSizeName = elem.getAttribute("ItemSizeName")
End Sub


Public Sub Copy(obj As CgConnectionDef)
  obj.itemName = itemName
  obj.itemType = itemType
  obj.itemID = itemID
  obj.attrType = attrType
  obj.operType = operType
  obj.connName = connName
  obj.ItemSizeName = ItemSizeName
  obj.Face = Face
  obj.order = order
  obj.UserID = UserID
End Sub

Private Sub Class_Initialize()
    Face = 1
    order = 1
    UserID = -1
End Sub

