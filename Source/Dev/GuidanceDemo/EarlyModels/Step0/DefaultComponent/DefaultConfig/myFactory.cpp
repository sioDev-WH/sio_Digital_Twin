/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: myFactory
//!	Generated Date	: Thu, 19, Dec 2002  
	File Path	: DefaultComponent\DefaultConfig\myFactory.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "myFactory.h"
#include "Guidance.h"

//## package Default 


//#[ ignore 
#define Default_myFactory_myFactory_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// myFactory.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Default)
//## class myFactory 



myFactory::myFactory() {
    NOTIFY_CONSTRUCTOR(myFactory, myFactory(), 0, Default_myFactory_myFactory_SERIALIZE);
    itsGuidance = NULL;
}

myFactory::~myFactory() {
    NOTIFY_DESTRUCTOR(~myFactory, TRUE);
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

IMPLEMENT_META(myFactory, Default, FALSE, OMAnimatedmyFactory)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\myFactory.cpp
*********************************************************************/

