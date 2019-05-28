// OnUMLAssociation.h

#ifndef _ON_UML_ASSOCIATION_H_
#define _ON_UML_ASSOCIATION_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OnUMLEsoExports.h"


class ONUML_API COnUMLAssociation
{
public:
  COnUMLAssociation();
  virtual ~COnUMLAssociation();

public:
  long* FromIds;
  long nFromIds;
  long* ToIds;
  long nToIds;

};


#endif // _ON_UML_ASSOCIATION_H_