/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: myFactory
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\myFactory.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "myFactory.h"
#include "Guidance.h"

//## package GuidancePkg 


//#[ ignore 
#define GuidancePkg_myFactory_myFactory_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// myFactory.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class myFactory 



myFactory::myFactory() {
    NOTIFY_CONSTRUCTOR(myFactory, myFactory(), 0, GuidancePkg_myFactory_myFactory_SERIALIZE);
    itsGuidance = NULL;
}

myFactory::~myFactory() {
    cleanUpRelations();
}

Guidance* myFactory::getItsGuidance() const {
    return itsGuidance;
}

void myFactory::__setItsGuidance(Guidance*  p_Guidance) {
    itsGuidance = p_Guidance;
    if(p_Guidance != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsGuidance", p_Guidance, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsGuidance");
        }
}

void myFactory::_setItsGuidance(Guidance*  p_Guidance) {
    if(itsGuidance != NULL)
        itsGuidance->__setItsMyFactory(NULL);
    __setItsGuidance(p_Guidance);
}

void myFactory::setItsGuidance(Guidance*  p_Guidance) {
    if(p_Guidance != NULL)
        p_Guidance->_setItsMyFactory(this);
    _setItsGuidance(p_Guidance);
}

void myFactory::_clearItsGuidance() {
    NOTIFY_RELATION_CLEARED("itsGuidance");
    itsGuidance = NULL;
}

void myFactory::cleanUpRelations() {
    if(itsGuidance != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsGuidance");
            
            myFactory* p_myFactory = itsGuidance->getItsMyFactory();
            if(p_myFactory != NULL)
                itsGuidance->__setItsMyFactory(NULL);
            itsGuidance = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedmyFactory::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsGuidance", FALSE, TRUE);
    if(myReal->itsGuidance)
        aomsRelations->ADD_ITEM(myReal->itsGuidance);
}

IMPLEMENT_META(myFactory, GuidancePkg, FALSE, OMAnimatedmyFactory)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\myFactory.cpp
*********************************************************************/

