#include "StdAfx.h"
#include "OnUMLAssociation.h"
#include "OnUMLEsoMacros.h"

COnUMLAssociation::COnUMLAssociation()
{
FromIds = NULL;
ToIds = NULL;
}

COnUMLAssociation::~COnUMLAssociation()
{ 
	DESTROY_VECTOR(FromIds)
	DESTROY_VECTOR(ToIds)
}

