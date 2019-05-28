#include "StdAfx.h"
#include "OnUMLLink.h"


void COnUMLLink::getFromId(GUID* pId) 
{ 
	CopyGUID(FromId, (*pId)); 
}

void COnUMLLink::getToId(GUID* pId) 
{ 
  CopyGUID(ToId, (*pId)); 
}

void COnUMLLink::setFromId(GUID Id) 
{ 
  CopyGUID(Id, FromId); 
}

void COnUMLLink::setToId(GUID Id) 
{ 
  CopyGUID(Id, ToId); 
}

void COnUMLLink::CopyGUID(const GUID& source, GUID& target)
{ 
  long i;
  target.Data1 = source.Data1;
  target.Data2 = source.Data2;
  target.Data3 = source.Data3;
  for (i = 0; i < 8; i++) target.Data4[i] = source.Data4[i];
}
