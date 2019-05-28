// FDistributedVar.cpp: implementation of the FDistributedVar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <string.h>
#include <math.h>
#include "DistributionDomain.h"
#include "FDistributedVar.h"
#include "DistributedVar.h"
#include "OnAD.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
FDistributedVar::FDistributedVar(char* VarName,
								char* VarUnits,
								long VarnDomains,
								DistributionDomain* VarDomains
								)
{
	long i; 

	 Name = (char*) new char[120];
	 Units = (char*) new char[120];
   Name[0] = '\0';
   Units[0] = '\0';

	 if (VarName) strcpy(Name,VarName);
	 if (VarUnits) strcpy(Units,VarUnits);
	 nDomains = VarnDomains;
	 if(nDomains){
		Domains = (DistributionDomain*) new DistributionDomain[nDomains];
		lowerIndex = new long[nDomains];
		upperIndex = new long[nDomains];
		if(VarDomains)
		 for(i=0;i<nDomains;i++)
			 Domains[i]= VarDomains[i];
	 }
	 pParent = NULL; 
	 mesh(true);
					 
}

FDistributedVar::FDistributedVar()
{
	Name = NULL;
	Units = NULL;
	nDomains = 0;
	Domains = NULL;
	bIsRoot = false; // can be made to be a root variable
	pParent = NULL;  // temporarily set to NULL must have parent
	pVal=NULL;		 // refers to root data
	lowerIndex = NULL;
	upperIndex = NULL;

}

// Used in case of late construction (e.g., arrays of same source var)
void FDistributedVar::init(FDistributedVar& Src)
{
	long i; 

	 Name = (char*) new char[120];
	 Units = (char*) new char[120];
   Name[0] = '\0';
   Units[0] = '\0';

	 if (Src.Name) strcpy(Name,Src.Name);
	 if (Src.Units) strcpy(Units,Src.Units);
	 nDomains = Src.nDomains;
	 if(nDomains){
		Domains = (DistributionDomain*) new DistributionDomain[nDomains];
		lowerIndex = new long[nDomains];
		upperIndex = new long[nDomains];
		if(Src.Domains)
		 for(i=0;i<nDomains;i++)
			 Domains[i]= Src.Domains[i];
	 }
	 mesh();
	 copyData(&Src);
}

void FDistributedVar::setParent(FDistributedVar& src)
{
  pParent = src.pParent;
}

void FDistributedVar::diff(long idx, long n)
{
  long i;
	FDistributedVar* Src = this;

	while(!(Src->bIsRoot)) 
    Src = Src->pParent;

  for (i = 0; i < Src->nVal; i++)
    Src->pVal[i].diff(idx,n);
}

void FDistributedVar::init(DistributedVar& Src)
{
	long i; 

	 Name = (char*) new char[120];
   _ASSERTE(Name != NULL);
	 Units = (char*) new char[120];
   
   Name[0] = '\0';
   Units[0] = '\0';

	 if (Src.Name) strcpy(Name,Src.Name);
	 if (Src.Units) strcpy(Units,Src.Units);
	 nDomains = Src.nDomains;
	 if(nDomains){
		Domains = (DistributionDomain*) new DistributionDomain[nDomains];
		lowerIndex = new long[nDomains];
		upperIndex = new long[nDomains];
		if(Src.Domains)
		 for(i=0;i<nDomains;i++)
			 Domains[i]= Src.Domains[i];
	 }
	 mesh();
	 copyData(&Src);
}


// Copy constructor -- 
FDistributedVar::FDistributedVar(FDistributedVar& Src){
	init(Src);
}


FDistributedVar::~FDistributedVar()
{
	if(pVal) delete[] pVal;
	if(Name) delete Name;
	if(Units) delete Units;
	if(Domains)
		delete[] Domains;
	if(lowerIndex) delete lowerIndex;
	if(upperIndex) delete upperIndex ;
}

void FDistributedVar::mesh(bool bInitVal){

	int i;

	bIsRoot=true;
	nVal = 1;
	for(i=0;i<nDomains;i++){
		lowerIndex[i] = (long) floor(Domains[i].Min/Domains[i].stepSize);
		if(Domains[i].bOpenMin) lowerIndex[i]++; 
		upperIndex[i] = (long) floor(Domains[i].Max/Domains[i].stepSize);
		if(Domains[i].bOpenMax) upperIndex[i]--;
		nVal *=	upperIndex[i] - lowerIndex[i] + 1;// Domains[i].mesh->nPts;
	}
	pVal = new Fdouble[nVal];
	if(bInitVal) for(i=0;i<nVal;i++) pVal[i] = 0.0; // or randomize

}

void FDistributedVar::setData(long index, Fdouble pData)
{
	if(bIsRoot)
		if(0<=index && index <nVal)
			pVal[index] = pData;
	// else error [Derived Variable]
}

void FDistributedVar::copyData(FDistributedVar* pSrc) // make private
{
	long i;
	bIsRoot = true;
	pParent = NULL;
	if(pSrc->nVal == nVal)
		for(i=0;i<nVal;i++)
			pVal[i] = pSrc->pVal[i];
}	

void FDistributedVar::copyData(DistributedVar* pSrc) // make private
{
	long i;
	bIsRoot = true;
	pParent = NULL;
	if(pSrc->nVal == nVal)
		for(i=0;i<nVal;i++)
			pVal[i] = pSrc->pVal[i];
}	


Fdouble FDistributedVar::getVal(Fdouble* domainPoint){
	long index[8], localIndex[3];
	FDistributedVar* Src;
	Fdouble temp; 
  Fdouble lambda[3];

	Src = this;
	while(!(Src->bIsRoot)) Src=Src->pParent;
	switch (nDomains){
	case 1:
		temp = domainPoint[0]/Domains[0].stepSize;
		index[0] = (long) floor(temp.v);
		index[1] = (long) ceil(temp.v);
		lambda[0] = temp - index[0];
		temp = (1-lambda[0]) * pVal[index[0]] + lambda[0] * pVal[index[1]];
		break;
	case 2:
		temp = domainPoint[0]/(Domains[0].stepSize);
		index[0] = (long) floor(temp.v);
		index[1] = (long) ceil(temp.v);
		lambda[0] = temp - index[0];

		temp = domainPoint[1]/Domains[1].stepSize;
		index[2] = (long) floor(temp.v);
		index[3] = (long) ceil(temp.v);
		lambda[1] = temp - index[0];

		localIndex[0] = index[0];
		localIndex[1] = index[2];
		temp = 0.0;
		temp += (1-lambda[0])*(1-lambda[1]) * pVal[getGlobalIndex(index)];
		localIndex[0] = index[0];
		localIndex[1] = index[3];
		temp += (1-lambda[0])*lambda[1] * pVal[getGlobalIndex(index)];
		localIndex[0] = index[1];
		localIndex[1] = index[2];
		temp += lambda[0]*(1-lambda[1]) * pVal[getGlobalIndex(index)];
		localIndex[0] = index[1];
		localIndex[1] = index[3];
		temp += lambda[0]*lambda[1] * pVal[getGlobalIndex(index)];	  
		break;
	}
	return temp;
}

FDistributedVar::operator = (FDistributedVar& Src){

	this->init(Src);

}

FDistributedVar FDistributedVar::operator | (DistributionDomain& AtSlice){
	long i,j;
	long *localIndex, globalIndex;

	localIndex = new long[nDomains];

	FDistributedVar* pVar;
	pVar = new FDistributedVar(this->Name,this->Units,this->nDomains,this->Domains);  // (*this);
	pVar->nVal = 1;
	for(i=0;i<nDomains;i++){
		if(!strcmp(AtSlice.Name,(this->Domains[i]).Name)){
			pVar->Domains[i]=AtSlice;
			pVar->lowerIndex[i] = (long) floor(AtSlice.Min/AtSlice.stepSize);
			if(AtSlice.bOpenMin) pVar->lowerIndex[i]++; 
			pVar->upperIndex[i] = (long) floor(AtSlice.Max/AtSlice.stepSize);
			if(AtSlice.bOpenMax) pVar->upperIndex[i]--;
			pVar->Domains[i].mesh->nPts = (pVar->upperIndex[i] - pVar->lowerIndex[i] + 1);	
		}
		pVar->nVal *= pVar->Domains[i].mesh->nPts;
	}

	for(i=0;i<pVar->nVal;i++){
		pVar->getLocalIndex(i, localIndex);
		for(j=0;j<nDomains;j++) 
			localIndex[j] += pVar->lowerIndex[j];
		globalIndex = this->getGlobalIndex(localIndex);
		pVar->pVal[i] = this->pVal[globalIndex];	
	}
	delete localIndex;
	return (*pVar);
}


FDistributedVar FDistributedVar::operator + (FDistributedVar& opVar)
{
	long i;

	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = (*this);

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<nVal;i++)
		pVar->pVal[i] = pVal[i] + opVar.pVal[i];

	return (*pVar);

}

FDistributedVar operator + (Fdouble opConst, FDistributedVar& opVar)
{
	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = opVar;

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<opVar.nVal;i++)
		pVar->pVal[i] = opConst + opVar.pVal[i];


	return (*pVar);
}

FDistributedVar operator + ( FDistributedVar& opVar, Fdouble opConst)
{
	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = opVar;

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<opVar.nVal;i++)
		pVar->pVal[i] =  opVar.pVal[i] + opConst;


	return (*pVar);
}

FDistributedVar FDistributedVar::operator + ()
{

	return (*this);
}

FDistributedVar FDistributedVar::operator - (FDistributedVar& opVar)
{
	long i;
	FDistributedVar* pVar;

	pVar = new FDistributedVar;
	(*pVar) = (*this);

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<nVal;i++)
		pVar->pVal[i] = pVal[i] - opVar.pVal[i];


	return (*pVar);

}

FDistributedVar operator - (Fdouble opConst, FDistributedVar& opVar)
{
	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = opVar;

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<opVar.nVal;i++)
		pVar->pVal[i] = opConst - opVar.pVal[i];


	return (*pVar);
}

FDistributedVar operator - ( FDistributedVar& opVar, Fdouble opConst)
{
	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = opVar;

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<opVar.nVal;i++)
		pVar->pVal[i] =  opVar.pVal[i] - opConst;


	return (*pVar);
}

FDistributedVar FDistributedVar::operator - ()
{
	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = (*this);

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<nVal;i++)
		pVar->pVal[i] = - pVal[i];


	return (*pVar);
}


FDistributedVar FDistributedVar::operator * (FDistributedVar& opVar)
{

	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = (*this);

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<nVal;i++)
		pVar->pVal[i] = pVal[i] * opVar.pVal[i];

	return (*pVar);
}


FDistributedVar FDistributedVar::operator * (Fdouble opConst)
{
	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = (*this);

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<nVal;i++)
		pVar->pVal[i] = pVal[i] * opConst;



	return (*pVar);
}

FDistributedVar operator * (Fdouble opConst, FDistributedVar& opVar)
{
	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = opVar;

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<opVar.nVal;i++)
		pVar->pVal[i] =opConst * opVar.pVal[i];


	return (*pVar);
}


FDistributedVar FDistributedVar::operator / (FDistributedVar& opVar)
{
	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = (*this);

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<nVal;i++)
		// Use try catch for divid by zero=NAN
		pVar->pVal[i] = pVal[i] / opVar.pVal[i];


	return (*pVar);
}

FDistributedVar FDistributedVar::operator / (Fdouble opConst)
{
	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = (*this);


	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<nVal;i++)
		pVar->pVal[i] = pVal[i] / opConst;

	return (*pVar);
}

FDistributedVar operator / (Fdouble opConst, FDistributedVar& opVar)
{
	long i;
	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = opVar;

	(*pVar).bIsRoot = true;
	(*pVar).mesh();
	for(i=0;i<opVar.nVal;i++)
		pVar->pVal[i] = opConst/opVar.pVal[i] ;


	return (*pVar);
}



// Should be written in terms of a macro called VAL(ptrIndependentVarsIndecises) and/or
// VAL(ptrIndependentVarsValues). The second to support in interpolation for non-grid pts.
FDistributedVar& FDistributedVar::PARTIAL(DistributionDomain& partialDomain) 
{

long dDomain;
long index;
long nPts,nElements, order,i,j;
double h = partialDomain.stepSize;
long* localIndex;
long elementIndex;
long* cpGlobalIndex; // Collocation Point index w.r.t. variable global index
long* gpGlobalIndex;

// Must pad pVal with pParent->.....->root object (from solver) to compute
// the PARTIAL at any broken end elements or end grid points (mostly we need
// BC points of each domain to calculate the PARTIAL of the end points

	FDistributedVar* pVar;
	pVar = new FDistributedVar;
	(*pVar) = (*this);
	pVar->mesh(); // Same size of data

	
	dDomain = -1;
	for(i=0;i<nDomains;i++)
		if(!strcmp(partialDomain.Name,(this->Domains[i]).Name)){
			dDomain=i;
			break;
		}
	localIndex = new long[nDomains];
	// if none matches then ERR: can't take the derivatives with respect to this domain

	// The following assumes that pVal is arranged as follows:
	//	pVal_index				Dom_0		Dom_1		Dom_2
	//		0					0			0			0	
	//		1					1			0			0
	//		2					2			0			0
	//		:
	//		:
	//		N1-1				N1-1		0			0
	//	------------------------------------------------
	//		N1+0				0			1			0	
	//		N1+1				1			1			0
	//		N1+2				2			1			0
	//		:
	//		:
	//		2N1-1				N1-1		1			0
	//	------------------------------------------------
	//		2N1+0				0			2			0	
	//		2N1+1				1			2			0
	//		2N1+2				2			2			0
	//		:
	//		:
	//		2N1-1				N1-1		2			0
	//	------------------------------------------------
	//		:					:			:			:
	//		:					:			:			:
	//	------------------------------------------------
	//		(N2-1)*N1+0			0			N2-1		0	
	//		(N2-1)*N1+1			1			N2-1		0
	//		(N2-1)*N1+2			2			N2-1		0
	//		:
	//		:
	//		N2*N1-1				N1-1		N2-1		0
	//	------------------------------------------------
	//	------------------------------------------------
	//		:					:			:			:
	//		:					:			:			:
	//	------------------------------------------------
	//		(N3-1)*N2*N1+0		0			N2-1		N3-1	
	//		(N3-1)*N2*N1+1		1			N2-1		N3-1
	//		(N3-1)*N2*N1+2		2			N2-1		N3-1
	//		:
	//		:
	//		N3*N2*N1-1			N1-1		N2-1		N3-1
	//	------------------------------------------------

	
	switch(Domains[dDomain].mesh->method){
		case OCFEM:
			nPts = partialDomain.mesh->nPts;
			order = partialDomain.mesh->order;
			nElements = partialDomain.mesh->nElements;
			cpGlobalIndex = new long[order+1]; // Collocation Point index w.r.t. variable global index
			for(i=0;i<nVal;i++){	// we need to compute derivatives at all points ONLY once -- all derived vars will map to here
				getLocalIndex(i,localIndex); // get local indices for all domains
				
				elementIndex = localIndex[dDomain]/order; // within differentiation domain
				index = localIndex[dDomain] - elementIndex*order; // index within an element
				if (index>0) continue; // will do multiple grid points simultaneously
				else{ // begining of an element
					cpGlobalIndex[0] = i; // we know global index for this one
					for(j=1;j<order+1;j++){ // we go to order+1 an end point overlapping with next element starting point
					  localIndex[dDomain] += 1; // where's the next grid point within same element
					  cpGlobalIndex[j] = getGlobalIndex(localIndex); // better use an array global_index[order+1] and a loop
					}
					switch(order){
					case 1:
						; // Error
						break;
					case 2:

							pVar->pVal[cpGlobalIndex[0]] = (-3 * this->pVal[cpGlobalIndex[0]]
															+ 4.0 * this->pVal[cpGlobalIndex[1]]
															- 1 * this->pVal[cpGlobalIndex[2]]
														   ) / h;

							pVar->pVal[cpGlobalIndex[1]] = (-1.0 * this->pVal[cpGlobalIndex[0]]
															+ 0.0 * this->pVal[cpGlobalIndex[1]]
															+ 1.0 * this->pVal[cpGlobalIndex[2]]
													       ) / h;

							pVar->pVal[cpGlobalIndex[2]] = (1.0 * this->pVal[cpGlobalIndex[0]]
															- 4.0 * this->pVal[cpGlobalIndex[1]]
															+ 3.0 * this->pVal[cpGlobalIndex[2]]
													       ) / h;
							 break;
						case 3:

							pVar->pVal[cpGlobalIndex[0]] = (-7 * this->pVal[cpGlobalIndex[0]]
														+ 8.19615 * this->pVal[cpGlobalIndex[1]]
														- 2.19615 * this->pVal[cpGlobalIndex[2]]
														+ this->pVal[cpGlobalIndex[3]]
													   ) / h;

							pVar->pVal[cpGlobalIndex[1]] = (-2.73205 * this->pVal[cpGlobalIndex[0]]
														+ 1.73205 * this->pVal[cpGlobalIndex[1]]
														+ 1.73205 * this->pVal[cpGlobalIndex[2]]
														- 0.73205 * this->pVal[cpGlobalIndex[3]]
													   ) / h;

							pVar->pVal[cpGlobalIndex[2]] = (0.73205 * this->pVal[cpGlobalIndex[0]]
														+ 1.73205 * this->pVal[cpGlobalIndex[1]]
														- 1.73205 * this->pVal[cpGlobalIndex[2]]
														+ 2.73205 * this->pVal[cpGlobalIndex[3]]
													   ) / h;

							 pVar->pVal[cpGlobalIndex[3]] = (-1 * this->pVal[cpGlobalIndex[0]]
														+ 2.19615 * this->pVal[cpGlobalIndex[1]]
														- 8.19615 * this->pVal[cpGlobalIndex[2]]
														+ 7 * this->pVal[cpGlobalIndex[3]]
													   ) / h;
							 break;
						
						case 4:

							pVar->pVal[cpGlobalIndex[0]] = (-13.0 * this->pVal[cpGlobalIndex[0]]
														+ 14.78831 * this->pVal[cpGlobalIndex[1]]
														- 2.66667 * this->pVal[cpGlobalIndex[2]]
														+ 1.87836 * this->pVal[cpGlobalIndex[3]]
														-1.0 * this->pVal[cpGlobalIndex[4]]
													   ) / h;

							pVar->pVal[cpGlobalIndex[1]] = (-5.32379 * this->pVal[cpGlobalIndex[0]]
														+ 3.87298 * this->pVal[cpGlobalIndex[1]]
														+ 2.06559 * this->pVal[cpGlobalIndex[2]]
														- 1.29099 * this->pVal[cpGlobalIndex[3]]
														+ 0.67621 * this->pVal[cpGlobalIndex[4]]
													   ) / h;

							pVar->pVal[cpGlobalIndex[2]] = (1.5000 * this->pVal[cpGlobalIndex[0]]
														-3.22749 * this->pVal[cpGlobalIndex[1]]
														+ 0.0 * this->pVal[cpGlobalIndex[2]]
														+ 3.22749 * this->pVal[cpGlobalIndex[3]]
														- 1.50000 * this->pVal[cpGlobalIndex[4]]
													   ) / h;

							 pVar->pVal[cpGlobalIndex[3]] = (-0.67621 * this->pVal[cpGlobalIndex[0]]
														+ 1.29099 * this->pVal[cpGlobalIndex[1]]
														- 2.06559 * this->pVal[cpGlobalIndex[2]]
														- 3.87298 * this->pVal[cpGlobalIndex[3]]
														+ 5.32379 * this->pVal[cpGlobalIndex[4]]
													   ) / h;
							 pVar->pVal[cpGlobalIndex[4]] = (1.0000 * this->pVal[cpGlobalIndex[0]]
														-1.87836 * this->pVal[cpGlobalIndex[1]]
														+ 2.66667 * this->pVal[cpGlobalIndex[2]]
														- 14.78831 * this->pVal[cpGlobalIndex[3]]
														+ 13.0000 * this->pVal[cpGlobalIndex[4]]
													   ) / h;
							 break;
					}
				}
			}
			break;
		case CFDM:
			nPts = partialDomain.mesh->nPts; // not being used here (can use it to check algorithm count)
			order = partialDomain.mesh->order;
			switch(order){
				case 2:
				   gpGlobalIndex = new long[order+1];
				   for(i=0;i<nVal;i++){
					   getLocalIndex(i,localIndex);
					   if(localIndex[dDomain] == 0){
						   gpGlobalIndex[0] = i;
						   for(j=1;j<order+1;j++){
						    localIndex[dDomain] += 1; 
						    gpGlobalIndex[j] = getGlobalIndex(localIndex);
						   }
						  pVar->pVal[i] = (- 3.0 * this->pVal[gpGlobalIndex[0]] 
										   + 4.0 * this->pVal[gpGlobalIndex[1]] 
										   - 1.0 * this->pVal[gpGlobalIndex[2]] )/h/2;
					   }
					   else if(localIndex[dDomain] == nPts-1) {
						  gpGlobalIndex[0] = i;
						  for(j=1;j<order+1;j++){
						     localIndex[dDomain] -= 1; 
						     gpGlobalIndex[j] = getGlobalIndex(localIndex);
						  }
						  pVar->pVal[i] = (+ 3.0 * this->pVal[gpGlobalIndex[0]] 
										   - 4.0 * this->pVal[gpGlobalIndex[1]] 
										   + 1.0 * this->pVal[gpGlobalIndex[2]] )/h/2;
					   }
					   else{
						  localIndex[dDomain] -= 1; 
						  gpGlobalIndex[0] = getGlobalIndex(localIndex);
						  gpGlobalIndex[1] = i;
						  localIndex[dDomain] += 2; 
						  gpGlobalIndex[2] = getGlobalIndex(localIndex);
						  pVar->pVal[i] = ( - 1.0 * this->pVal[gpGlobalIndex[0]] 
							                + 1.0 * this->pVal[gpGlobalIndex[2]] )/h/2;
					   }
				   }
				   break;
				}
		case BFDM:
				nPts = partialDomain.mesh->nPts; // not being used here (can use it to check algorithm count)
				order = partialDomain.mesh->order;
				switch(order){
				case 1:
				   gpGlobalIndex = new long[order+1];
				   for(i=0;i<nVal;i++){
					   getLocalIndex(i,localIndex);
					   if(localIndex[dDomain] == 0){
						  gpGlobalIndex[0] = i;
						  for(j=1;j<order+1;j++){
						    localIndex[dDomain] += 1; 
						    gpGlobalIndex[j] = getGlobalIndex(localIndex);
						  }
						  pVar->pVal[i] = (this->pVal[gpGlobalIndex[0]] - this->pVal[gpGlobalIndex[1]] )/h;
					   }
					   else{
						  gpGlobalIndex[0] = i;
						  for(j=1;j<order+1;j++){
						     localIndex[dDomain] -= 1; 
						     gpGlobalIndex[j] = getGlobalIndex(localIndex);
						  }
						  pVar->pVal[i] = (this->pVal[gpGlobalIndex[0]] - this->pVal[gpGlobalIndex[1]] )/h;
					   }
				   }
				   break;
				}
		case FFDM:
			break;
		case UFDM:
			break;
	}

	delete localIndex;
	return *pVar;
}


// Should be a macro
// computes the global index for each set of local grid indecies of all domains
long FDistributedVar::getGlobalIndex (long* gridIndex){

	long i,j;
	long index;
	long product;

	index = 0;
	for(i=0;i<nDomains;i++){
		product = 1;
		for(j=0;j<i;j++)
			product *=  Domains[j].mesh->nPts;
	    index += gridIndex[i] * product;
	}

	return index;
}

// Should be a macro
// computes the local grid indecies set of all domains for a given input global index 
void FDistributedVar::getLocalIndex (long index, long* &gridIndex){

	long i,j;
	long product;  // May be very large


	for(i=nDomains-1;i>0;i--){
		product = 1;
		for(j=0;j<i;j++)
			product *=  Domains[j].mesh->nPts;
	    gridIndex[i] =  index/product;
		index -= gridIndex[i] * product;
	}
	gridIndex[0] = index;
}

// May not be needed any more after introducing the lowerIndex & upperIndex
// and looping using them rather than nVal in all operators and PARTIAL
// This way the computations are limited only to equation domains
// Only caveat is the differentiation method or polynomial order need be chnaged
// to support elements broken within subdomains. Better option is to borrow values from
// root variable (across the subdomains) to do the computation. 
bool FDistributedVar::isCompatible(FDistributedVar& otherVar, long* index){

	long i,j, count=0;
	for(i=0;i<nDomains;i++)
		for(j=0;j<otherVar.nDomains;j++)
			if(this->Domains[i].isCompatible(otherVar.Domains[j])){
				if(index) index[i] = j;
				count++;
			}
	if(count==nDomains) return true;
	return false;
}

bool FDistributedVar::inDomain(long* index){

	long i;
	for(i=0;i<nDomains;i++)
		if(index[i] < lowerIndex[i] && index[i] > upperIndex[i])
		 return false;
	return true;
}




