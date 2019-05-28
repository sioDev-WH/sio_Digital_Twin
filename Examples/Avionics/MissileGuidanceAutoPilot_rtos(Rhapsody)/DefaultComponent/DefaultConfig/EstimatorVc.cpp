/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorVc
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\EstimatorVc.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "EstimatorVc.h"
#include "EstimatorVcCoeff.h"
#include <stdafx.h>

//## package GuidancePkg 

//----------------------------------------------------------------------------
// EstimatorVc.cpp                                                                  
//----------------------------------------------------------------------------
//## class EstimatorVc 



EstimatorVc::EstimatorVc(double  bandwidth, OMThread*  p_thread) {
    Coeff = NULL;
    setThread(p_thread, FALSE);
    initStatechart();
    //#[ operation EstimatorVc(double) 
    Coeff->design(bandwidth);
    //#]
}

EstimatorVc::EstimatorVc(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    Coeff = NULL;
    initStatechart();
    //#[ operation EstimatorVc() 
    init();
    //#]
}

EstimatorVc::~EstimatorVc() {
    cleanUpRelations();
}

void EstimatorVc::clean() {
    //#[ operation clean() 
    if (Coeff)
    {
      delete Coeff;
      Coeff = NULL;
    }  
    //#]
}

void EstimatorVc::handle_tick() {
    //#[ operation handle_tick() 
    receive();
    GEN(evRadarTick); 
    broadcast();
    
    
    	
    
    //#]
}

void EstimatorVc::init() {
    //#[ operation init() 
    Vc=0.0;
    R=0.0;
    bTargetAcquired=0;  
    
    Coeff = new EstimatorVcCoeff();
    //#]
}

void EstimatorVc::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    Coeff->setPeriod(val);
    Coeff->init();
    //#]
}

double EstimatorVc::getR() const {
    return R;
}

void EstimatorVc::setR(double  p_R) {
    R = p_R;
}

double EstimatorVc::getRange() const {
    return Range;
}

void EstimatorVc::setRange(double  p_Range) {
    Range = p_Range;
}

double EstimatorVc::getVc() const {
    return Vc;
}

void EstimatorVc::setVc(double  p_Vc) {
    Vc = p_Vc;
}

int EstimatorVc::getBTargetAcquired() const {
    return bTargetAcquired;
}

void EstimatorVc::setBTargetAcquired(int  p_bTargetAcquired) {
    bTargetAcquired = p_bTargetAcquired;
}

EstimatorVcCoeff* EstimatorVc::getCoeff() const {
    return Coeff;
}

void EstimatorVc::setCoeff(EstimatorVcCoeff*  p_EstimatorVcCoeff) {
    Coeff = p_EstimatorVcCoeff;
}

void EstimatorVc::rootState_entDef() {
    {
        pushNullConfig();
        rootState_subState = Off;
        rootState_active = Off;
    }
}

int EstimatorVc::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Off:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 0 
                    if(bTargetAcquired)
                        {
                            popNullConfig();
                            //#[ transition 0 
                            R=Range;
                            //#]
                            pushNullConfig();
                            rootState_subState = On;
                            rootState_active = On;
                            //#[ state ROOT.On.(Entry) 
                            // R=Coeff->A*R+Coeff->B*Range;
                            Vc=-Coeff->Bandwidth*(Range-R);
                            R=R-Vc*Coeff->period/1000.0;
                            
                            
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
                    if(bTargetAcquired==0)
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
                    // R=Coeff->A*R+Coeff->B*Range;
                    Vc=-Coeff->Bandwidth*(Range-R);
                    R=R-Vc*Coeff->period/1000.0;
                    
                    
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

void EstimatorVc::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void EstimatorVc::cleanUpRelations() {
    if(Coeff != NULL)
        {
            Coeff = NULL;
        }
}

OMBoolean EstimatorVc::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\EstimatorVc.cpp
*********************************************************************/

