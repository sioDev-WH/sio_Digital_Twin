// DistributedVar.h: interface for the DistributedVar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISTRIBUTEDVAR_H__7D5C3A9E_F96B_4664_963A_AE52837E41B8__INCLUDED_)
#define AFX_DISTRIBUTEDVAR_H__7D5C3A9E_F96B_4664_963A_AE52837E41B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class DistributedVar  
{

public:
	char* Name;
	char* Units;
	long nDomains;
	DistributionDomain* Domains; // Domains can be assigned indecies to order pVals accordingly
	// long Dimension;
	bool bIsRoot;
	DistributedVar* pParent;
	long nVal;
	double* pVal;
	long* lowerIndex;
	long* upperIndex;

public:
	DistributedVar();
	DistributedVar(DistributedVar& Src);
	DistributedVar(	char* VarName,
					char* VarUnits,
					long numberOfDomains,
					DistributionDomain* VarDomains,
					DistributedVar* Parent=0);
	init(DistributedVar& Src);
	virtual ~DistributedVar();

	double getVal(double* domainPoint);
	DistributedVar& PARTIAL(DistributionDomain& partialDomain);
	
	operator = (DistributedVar& Src);
	DistributedVar operator | (DistributionDomain& AtSlice);
	DistributedVar operator + (DistributedVar& opVar);
	DistributedVar operator + ();
	DistributedVar operator - (DistributedVar& opVar);
	DistributedVar operator - ();
	DistributedVar operator * (DistributedVar& opVar);
	DistributedVar operator * (double opConst);
	DistributedVar operator / (DistributedVar& opVar);
	DistributedVar operator / (double opConst);

	void mesh(bool bInitVal=false);
	void copyData(DistributedVar* pSrc);
	void setData(long index, double pData);

	long getGlobalIndex (long* gridIndex);
	void getLocalIndex (long index, long* &gridIndex);

	bool isCompatible(DistributedVar& otherVar, long* index=0);
	bool inDomain(long* index);
};

DistributedVar operator + (double opConst, DistributedVar& opVar);
DistributedVar operator + ( DistributedVar& opVar, double opConst);
DistributedVar operator - (double opConst, DistributedVar& opVar);
DistributedVar operator - ( DistributedVar& opVar, double opConst);
DistributedVar operator * (double opConst, DistributedVar& opVar);
DistributedVar operator / (double opConst, DistributedVar& opVar);

#endif // !defined(AFX_DISTRIBUTEDVAR_H__7D5C3A9E_F96B_4664_963A_AE52837E41B8__INCLUDED_)
