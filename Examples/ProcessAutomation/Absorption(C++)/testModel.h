// testModel.h: interface for the testModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTMODEL_H__24AE083C_6F53_423B_A475_2FCE7060414C__INCLUDED_)
#define AFX_TESTMODEL_H__24AE083C_6F53_423B_A475_2FCE7060414C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DistributionDomain.h"

class testModel  
{
public:
	testModel();
	virtual ~testModel();

  double L;
  DistributionDomain Axial;

  double* arr;

};

#endif // !defined(AFX_TESTMODEL_H__24AE083C_6F53_423B_A475_2FCE7060414C__INCLUDED_)
