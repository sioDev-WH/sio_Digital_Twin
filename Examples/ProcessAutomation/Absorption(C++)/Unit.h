// Unit.h: interface for the Unit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNIT_H__36EA29E6_E5C5_4685_B353_718F8DC35355__INCLUDED_)
#define AFX_UNIT_H__36EA29E6_E5C5_4685_B353_718F8DC35355__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "D_Mesh.h"
#include "DistributionDomain.h"
#include "DistributedVar.h"
#include "DistributedEqn.h"


class Unit  
{
public:

	double* workspace;
	DistributedVar Conc[3];
	DistributedVar Temperature[3];
	DistributedEqn Interior;
	DistributedEqn BC_0;
	DistributedEqn BC_L;

public:
	Unit();
	virtual ~Unit();
	void registerVars(DistributedVar& var); // will add pointers to PARTIAL workspace
	void registerEquations(DistributedEqn& eqn); // will add pointers to workspace

};

#endif // !defined(AFX_UNIT_H__36EA29E6_E5C5_4685_B353_718F8DC35355__INCLUDED_)
