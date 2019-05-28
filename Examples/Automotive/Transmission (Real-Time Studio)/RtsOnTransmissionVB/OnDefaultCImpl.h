// OnDefaultCImpl.h: interface for the COnDefaultCImpl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONDEFAULTCIMPL_H__58E33966_3592_468A_ADAA_CA8086168C55__INCLUDED_)
#define AFX_ONDEFAULTCIMPL_H__58E33966_3592_468A_ADAA_CA8086168C55__INCLUDED_

// includes
#include "OnUMLDaeEsoImpl.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COnDefaultCImpl : public COnUMLDaeEsoImpl<COnDefaultCImpl>
{
public:
  COnDefaultCImpl() { };
  virtual ~COnDefaultCImpl() { };

  // no implementation
  void Save( FILE* fs) { };
  bool Load( FILE* fs) { return true; };

};

#endif // !defined(AFX_ONDEFAULTCIMPL_H__58E33966_3592_468A_ADAA_CA8086168C55__INCLUDED_)
