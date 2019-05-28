#ifndef _ON_UML_LINK_H_
#define _ON_UML_LINK_H_


class COnUMLLink
{
public:
  void getFromId(GUID* pId);
  void getToId(GUID* pId);
  void setFromId(GUID Id);
  void setToId(GUID Id);
  void CopyGUID(const GUID& source, GUID& target);

public:
  GUID FromId;
  GUID ToId;

};


#endif // _ON_UML_LINK_H_

