// DistributedEqn.h: interface for the DistributedEqn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISTRIBUTEDEQN_H__287CAE90_8E67_4C6A_BF1D_C05FA2B1B0E0__INCLUDED_)
#define AFX_DISTRIBUTEDEQN_H__287CAE90_8E67_4C6A_BF1D_C05FA2B1B0E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DistributedVar.h"
#include "OnUMLEsoExports.h"


class ONUML_API DistributedEqn  
{

public:
	DistributionDomain* Domains;
	double* localRes;
public:
	DistributedEqn(char* EqnName,
					DistributionDomain* explicit_domians,
					double* pRes);
	DistributedEqn();
	virtual ~DistributedEqn();


};

#endif // !defined(AFX_DISTRIBUTEDEQN_H__287CAE90_8E67_4C6A_BF1D_C05FA2B1B0E0__INCLUDED_)
