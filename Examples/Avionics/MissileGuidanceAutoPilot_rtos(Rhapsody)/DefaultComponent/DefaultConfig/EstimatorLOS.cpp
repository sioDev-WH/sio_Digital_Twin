/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorLOS
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\EstimatorLOS.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "EstimatorLOS.h"
#include "EstimatorLOSCoeff.h"
#include <stdafx.h>

//## package GuidancePkg 

//----------------------------------------------------------------------------
// EstimatorLOS.cpp                                                                  
//----------------------------------------------------------------------------
//## class EstimatorLOS 



EstimatorLOS::EstimatorLOS(double  bandwidth, OMThread*  p_thread) {
    Coeff = NULL;
    setThread(p_thread, FALSE);
    initStatechart();
    //#[ operation EstimatorLOS(double) 
    Coeff->design(bandwidth);
    //#]
}

EstimatorLOS::EstimatorLOS(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    Coeff = NULL;
    initStatechart();
    //#[ operation EstimatorLOS() 
    init();
    //#]
}

EstimatorLOS::~EstimatorLOS() {
    cleanUpRelations();
}

void EstimatorLOS::clean() {
    //#[ operation clean() 
      if (Coeff)
      {
      	delete Coeff;
      	Coeff = NULL;
      }
    //#]
}

void EstimatorLOS::handle_tick() {
    //#[ operation handle_tick() 
    receive();
    GEN(evRadarTick); 
    broadcast();
    
    
    	
    
    //#]
}

void EstimatorLOS::init() {
    //#[ operation init() 
    qf=0.0;
    L=0.0;
    LOSRate=0.0;
    guidanceMode=0; 
    Coeff = new EstimatorLOSCoeff();
    //#]
}

void EstimatorLOS::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    Coeff->setPeriod(val);
    Coeff->init();
    //#]
}

double EstimatorLOS::getL() const {
    return L;
}

void EstimatorLOS::setL(double  p_L) {
    L = p_L;
}

double EstimatorLOS::getLOSRate() const {
    return LOSRate;
}

void EstimatorLOS::setLOSRate(double  p_LOSRate) {
    LOSRate = p_LOSRate;
}

double EstimatorLOS::getEpsilon() const {
    return epsilon;
}

void EstimatorLOS::setEpsilon(double  p_epsilon) {
    epsilon = p_epsilon;
}

int EstimatorLOS::getGuidanceMode() const {
    return guidanceMode;
}

void EstimatorLOS::setGuidanceMode(int  p_guidanceMode) {
    guidanceMode = p_guidanceMode;
}

double EstimatorLOS::getQf() const {
    return qf;
}

void EstimatorLOS::setQf(double  p_qf) {
    qf = p_qf;
}

double EstimatorLOS::getQs() const {
    return qs;
}

void EstimatorLOS::setQs(double  p_qs) {
    qs = p_qs;
}

EstimatorLOSCoeff* EstimatorLOS::getCoeff() const {
    return Coeff;
}

void EstimatorLOS::setCoeff(EstimatorLOSCoeff*  p_EstimatorLOSCoeff) {
    Coeff = p_EstimatorLOSCoeff;
}

void EstimatorLOS::rootState_entDef() {
    {
        pushNullConfig();
        rootState_subState = Off;
        rootState_active = Off;
    }
}

int EstimatorLOS::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Off:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 0 
                    if(guidanceMode>1)
                        {
                            popNullConfig();
                            //#[ transition 0 
                            L=epsilon;
                            //#]
                            pushNullConfig();
                            rootState_subState = On;
                            rootState_active = On;
                            //#[ state ROOT.On.(Entry) 
                            
                            LOSRate=Coeff->Bandwidth*(epsilon-L)+qf;
                            L=L+Coeff->Bandwidth*(epsilon-L)*Coeff->period/1000.0; 
                            qf=qf + Coeff->Bandwidth*(-qf+qs)*Coeff->period/1000.0; 
                            
                            //#]
                            res = eventConsumed;
                        }
                }
            
            break;
        };
        case On:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 1 
                    if(guidanceMode==0)
                        {
                            popNullConfig();
                            pushNullConfig();
                            rootState_subState = Off;
                            rootState_active = Off;
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evRadarTick_GuidancePkg_id))
                {
                    popNullConfig();
                    pushNullConfig();
                    rootState_subState = On;
                    rootState_active = On;
                    //#[ state ROOT.On.(Entry) 
                    
                    LOSRate=Coeff->Bandwidth*(epsilon-L)+qf;
                    L=L+Coeff->Bandwidth*(epsilon-L)*Coeff->period/1000.0; 
                    qf=qf + Coeff->Bandwidth*(-qf+qs)*Coeff->period/1000.0; 
                    
                    //#]
                    res = eventConsumed;
                }
            
            break;
        };
        default:
            break;
    };
    return res;
}

void EstimatorLOS::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void EstimatorLOS::cleanUpRelations() {
    if(Coeff != NULL)
        {
            Coeff = NULL;
        }
}

OMBoolean EstimatorLOS::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\EstimatorLOS.cpp
*********************************************************************/

