// FDistributedVar.h: interface for the FDistributedVar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FDistributedVar_H__7D5C3A9E_F96B_4664_963A_AE52837E41B8__INCLUDED_)
#define AFX_FDistributedVar_H__7D5C3A9E_F96B_4664_963A_AE52837E41B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OnUMLEsoExports.h"

class Fdouble;
class DistributedVar;


class ONUML_API FDistributedVar  
{

public:
	char* Name;
	char* Units;
	long nDomains;
	DistributionDomain* Domains; // Domains can be assigned indecies to order pVals accordingly
	// long Dimension;
	bool bIsRoot;
	FDistributedVar* pParent;
	long nVal;
	Fdouble* pVal;
	long* lowerIndex;
	long* upperIndex;

public:
	FDistributedVar();
	FDistributedVar(FDistributedVar& Src);
	FDistributedVar(	char* VarName,
					char* VarUnits,
					long numberOfDomains,
					DistributionDomain* VarDomains);
	void init(FDistributedVar& Src);
  void init(DistributedVar& Src);

	virtual ~FDistributedVar();

	Fdouble getVal(Fdouble* domainPoint);
	FDistributedVar& PARTIAL(DistributionDomain& partialDomain);
	
	operator = (FDistributedVar& Src);
	FDistributedVar operator | (DistributionDomain& AtSlice);
	FDistributedVar operator + (FDistributedVar& opVar);
	FDistributedVar operator + ();
	FDistributedVar operator - (FDistributedVar& opVar);
	FDistributedVar operator - ();
	FDistributedVar operator * (FDistributedVar& opVar);
	FDistributedVar operator * (Fdouble opConst);
	FDistributedVar operator / (FDistributedVar& opVar);
	FDistributedVar operator / (Fdouble opConst);

	void mesh(bool bInitVal=false);
	void copyData(FDistributedVar* pSrc);
	void copyData(DistributedVar* pSrc);
  void setData(long index, Fdouble pData);

	long getGlobalIndex (long* gridIndex);
	void getLocalIndex (long index, long* &gridIndex);

	bool isCompatible(FDistributedVar& otherVar, long* index=0);
	bool inDomain(long* index);
  void setParent(FDistributedVar& src);
  void diff(long idx, long n);

};

FDistributedVar ONUML_API operator + (Fdouble opConst, FDistributedVar& opVar);
FDistributedVar ONUML_API operator + ( FDistributedVar& opVar, Fdouble opConst);
FDistributedVar ONUML_API operator - (Fdouble opConst, FDistributedVar& opVar);
FDistributedVar ONUML_API operator - ( FDistributedVar& opVar, Fdouble opConst);
FDistributedVar ONUML_API operator * (Fdouble opConst, FDistributedVar& opVar);
FDistributedVar ONUML_API operator / (Fdouble opConst, FDistributedVar& opVar);

#endif // !defined(AFX_FDistributedVar_H__7D5C3A9E_F96B_4664_963A_AE52837E41B8__INCLUDED_)
