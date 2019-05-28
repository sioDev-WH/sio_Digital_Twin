/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DefaultComponent
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

#include "MainDefaultComponent.h"
#include "aeroComposition.h"
#include "aeroDynamics.h"
#include "aeroPort.h"
#include "AtmoHeightPort.h"
#include "AtmoPort.h"
#include "atmosphere.h"
#include "bodyDynamics.h"
#include "engineDynamics.h"
#include "finDynamics.h"
#include "FinPort.h"
#include "GustPort.h"
#include "gustWind.h"
#include "Units.h"
#include "App.h"

//----------------------------------------------------------------------------
// MainDefaultComponent.cpp                                                                  
//----------------------------------------------------------------------------
//## configuration DefaultComponent::DefaultConfig 
int main(int  argc, char*  argv[]) {
    if(OXF::init(argc, argv, 6423))
        {
            aeroComposition * p_aeroComposition;
            aeroDynamics * p_aeroDynamics;
            aeroPort * p_aeroPort;
            AtmoHeightPort * p_AtmoHeightPort;
            AtmoPort * p_AtmoPort;
            atmosphere * p_atmosphere;
            bodyDynamics * p_bodyDynamics;
            engineDynamics * p_engineDynamics;
            finDynamics * p_finDynamics;
            FinPort * p_FinPort;
            GustPort * p_GustPort;
            gustWind * p_gustWind;
            Units * p_Units;
            App * p_App;
            p_aeroComposition = new aeroComposition;
            p_aeroDynamics = new aeroDynamics;
            p_aeroDynamics->startBehavior();
            p_aeroPort = new aeroPort;
            p_AtmoHeightPort = new AtmoHeightPort;
            p_AtmoPort = new AtmoPort;
            p_atmosphere = new atmosphere;
            p_atmosphere->startBehavior();
            p_bodyDynamics = new bodyDynamics;
            p_bodyDynamics->startBehavior();
            p_engineDynamics = new engineDynamics;
            p_engineDynamics->startBehavior();
            p_finDynamics = new finDynamics;
            p_finDynamics->startBehavior();
            p_FinPort = new FinPort;
            p_GustPort = new GustPort;
            p_gustWind = new gustWind;
            p_gustWind->startBehavior();
            p_Units = new Units;
            p_App = new App;
            //#[ configuration DefaultComponent::DefaultConfig 
            //#]
            OXF::start();
            delete p_aeroComposition;
            delete p_aeroDynamics;
            delete p_aeroPort;
            delete p_AtmoHeightPort;
            delete p_AtmoPort;
            delete p_atmosphere;
            delete p_bodyDynamics;
            delete p_engineDynamics;
            delete p_finDynamics;
            delete p_FinPort;
            delete p_GustPort;
            delete p_gustWind;
            delete p_Units;
            delete p_App;
            return 0;
        }
    else
        return 1;
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

