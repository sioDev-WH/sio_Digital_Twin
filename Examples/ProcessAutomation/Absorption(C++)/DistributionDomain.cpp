// DistributionDomain.cpp: implementation of the DistributionDomain class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <string.h>
#include "D_Mesh.h"
#include "DistributionDomain.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
DistributionDomain::DistributionDomain(){

	Name = NULL;
	mesh = NULL;

}

DistributionDomain::DistributionDomain(	const char* DomainName,
										double DomainMin,
										double DomainMax,
										bool bOpenDomainMin,
										bool bOpenDomainMax)
{

	Name = (char*) new char[120];
	strcpy(Name,DomainName);
	Min = DomainMin;
	Max = DomainMax;
	bOpenMin = bOpenDomainMin;
	bOpenMax = bOpenDomainMax;
	mesh = NULL;
}

DistributionDomain::~DistributionDomain()
{
	if(Name) delete Name;
}

DistributionDomain::operator =(DistributionDomain& Src){
	Name = (char*) new char[120];
	strcpy(this->Name,Src.Name);
	this->Min = Src.Min;
	this->Max = Src.Max;
	this->bOpenMin = Src.bOpenMin;
	this->bOpenMax = Src.bOpenMax;
	this->mesh = Src.mesh;
	this->stepSize = Src.stepSize;
}

void DistributionDomain::setMesh(D_Mesh& Mesh)
{
	mesh = new D_Mesh(Mesh.method,Mesh.order,Mesh.nElements);
	stepSize = (Max-Min)/(mesh->nPts-1);
}


DistributionDomain DistributionDomain::operator | (double val)
{
	DistributionDomain* pDom;

	pDom = new DistributionDomain;
	(*pDom) = (*this);
	// strcat(this->Name,"@");
	// convert val to string and strcat to boundaryName
	pDom->Min = val;
	pDom->Max = val;
	pDom->bOpenMin=false;
	pDom->bOpenMax=false;

	return (*pDom);
}

// The following is useful is specifying closed domains by adding boundary conditions
// on either side of the domain
DistributionDomain DistributionDomain::operator + (double val)
{
	DistributionDomain* pDom;
	pDom = new DistributionDomain;
	(*pDom) = (*this);
	// strcat(Name," +");
	// convert val to string and strcat to boundaryName

	// Add val to the domain and close it there.
	// Example: create a semi-closed domain from an open domain SrcDom
	// targetDom = SrcDom;  targetDom + SrcDom->Min or targetDom + SrcDom->Max
	if(pDom->Min == val)
	    pDom->bOpenMin = false;
	else if(pDom->Max == val)
	    pDom->bOpenMax = false;
	// ignore if outside domain!
	return (*pDom);
}

// The following is useful is specifying equation domains minus boundary conditions
// on either side of the domain
DistributionDomain DistributionDomain::operator - (double val)
{
	DistributionDomain* pDom;
	pDom = new DistributionDomain;
	(*pDom) = (*this);
	// strcat(Name," -");
	// convert val to string and strcat to boundaryName

	// Remove val from the domain and open it there.
	// Example: create a semi-closed domain from a closed domain SrcDom
	// targetDom = SrcDom;  targetDom - SrcDom->Min or targetDom - SrcDom->Max
	if(pDom->Min == val)
	    pDom->bOpenMin = true;
	else if(pDom->Max == val)
	    pDom->bOpenMax = true;
	// ignore if outside domain!
	return (*pDom);
}

// The following is useful in dynamic boundaries - e.g., heat flow with phase changes
// and to also support adaptive meshing
DistributionDomain DistributionDomain::operator >> (double val)
{
	DistributionDomain* pDom;
	pDom = new DistributionDomain;
	(*pDom) = (*this);

	// strcat(Name," >");
	// convert val to string and strcat to boundaryName
	// strip out any previously injected > and val (not <)
	// Removes min through val
	if(pDom->Min <= val && pDom->Max >= val){ // may need to allow empty domin
		pDom->Min=val;
	    pDom->bOpenMin = true;
	} 
	return (*pDom);
}

// The following is useful in dynamic boundaries - e.g., heat flow with phase changes
// and to also support adaptive meshing
DistributionDomain DistributionDomain::operator<< (double val)
{
	DistributionDomain* pDom;
	pDom = new DistributionDomain;
	(*pDom) = (*this);

	// strcat(Name," <");
	// convert val to string and strcat to boundaryName

	// Removes val through max
	if(pDom->Min <= val && pDom->Max >= val){ // may need to allow empty domin
		pDom->Max=val;
	    pDom->bOpenMax = true;
	}
	// ignored otherwise 
	return (*pDom);
}

bool DistributionDomain::isCompatible(DistributionDomain& otherDomain){


	if( !strcmp(otherDomain.Name, this->Name) 
		&& (otherDomain.Max == this->Max)
		&& !(otherDomain.bOpenMin ^ this->bOpenMin)
		&& !(otherDomain.bOpenMax ^ this->bOpenMax))
		return true;
	else return false;
}

