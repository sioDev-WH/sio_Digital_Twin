// DistributionDomain.h: interface for the DistributionDomain class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISTRIBUTIONDOMAIN_H__BA41A42C_FEEE_4911_AD50_735C085E0D79__INCLUDED_)
#define AFX_DISTRIBUTIONDOMAIN_H__BA41A42C_FEEE_4911_AD50_735C085E0D79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "D_Mesh.h"
class DistributionDomain  
{
public:
	char* Name;
	double Min;
	double Max;
	bool bOpenMin;
	bool bOpenMax;
	D_Mesh* mesh; // Discretization Mesh: generalize to allow multiple non-uniform meshes 
	double stepSize; // Spatial step size

public:
	DistributionDomain();
	DistributionDomain(const char* Name,  
						double Min,  
						double Max,
						bool bOpenDomainMin, 
						bool bOpenDomainMax);
	virtual ~DistributionDomain();
	void setMesh(D_Mesh& mesh);
	operator = (DistributionDomain& Src);
    DistributionDomain operator | (double val);
	DistributionDomain operator + (double val);
	DistributionDomain operator - (double val);
	DistributionDomain operator >> (double val);
	DistributionDomain operator << (double val);
	bool isCompatible(DistributionDomain& otherDomain);
};

#endif // !defined(AFX_DISTRIBUTIONDOMAIN_H__BA41A42C_FEEE_4911_AD50_735C085E0D79__INCLUDED_)
