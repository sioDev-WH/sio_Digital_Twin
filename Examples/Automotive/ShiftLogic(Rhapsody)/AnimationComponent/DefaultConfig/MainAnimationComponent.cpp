/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AnimationComponent
//!	Generated Date	: Fri, 3, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\MainAnimationComponent.cpp
*********************************************************************/

#include "MainAnimationComponent.h"
#include "theApp.h"

//----------------------------------------------------------------------------
// MainAnimationComponent.cpp                                                                  
//----------------------------------------------------------------------------
//## configuration AnimationComponent::DefaultConfig 
int main(int  argc, char*  argv[]) {
    if(OXF::init(argc, argv, 6423))
        {
            theApp * p_theApp;
            p_theApp = new theApp;
            //#[ configuration AnimationComponent::DefaultConfig 
            //#]
            OXF::start();
            delete p_theApp;
            return 0;
        }
    else
        return 1;
}


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\MainAnimationComponent.cpp
*********************************************************************/

