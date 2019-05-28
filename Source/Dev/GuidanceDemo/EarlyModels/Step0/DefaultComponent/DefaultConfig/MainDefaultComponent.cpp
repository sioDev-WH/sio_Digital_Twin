/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DefaultComponent
//!	Generated Date	: Thu, 19, Dec 2002  
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

#include "MainDefaultComponent.h"
#include "Guidance.h"

//----------------------------------------------------------------------------
// MainDefaultComponent.cpp                                                                  
//----------------------------------------------------------------------------
//## configuration DefaultComponent::DefaultConfig 
int main(int  argc, char*  argv[]) {
    if(OXF::init(argc, argv, 6423))
        {
            Guidance * p_Guidance;
            p_Guidance = new Guidance;
            p_Guidance->startBehavior();
            //#[ configuration DefaultComponent::DefaultConfig 
            //#]
            OXF::start();
            delete p_Guidance;
            return 0;
        }
    else
        return 1;
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

