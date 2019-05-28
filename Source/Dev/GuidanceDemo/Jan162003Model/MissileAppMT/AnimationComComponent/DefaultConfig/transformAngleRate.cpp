/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: transformAngleRate
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\transformAngleRate.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "transformAngleRate.h"
#include <stdafx.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define LibraryPkg_AvionicsPkg_transformAngleRate_transformAngleRate_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngleRate_broadcast_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngleRate_clean_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngleRate_handle_tick_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngleRate_init_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngleRate_receive_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngleRate_update_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// transformAngleRate.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class transformAngleRate 



transformAngleRate::transformAngleRate() {
    NOTIFY_CONSTRUCTOR(transformAngleRate, transformAngleRate(), 0, LibraryPkg_AvionicsPkg_transformAngleRate_transformAngleRate_SERIALIZE);
    //#[ operation transformAngleRate() 
    init();
    //#]
}

transformAngleRate::~transformAngleRate() {
    NOTIFY_DESTRUCTOR(~transformAngleRate, TRUE);
    //#[ operation ~transformAngleRate() 
    clean();
    //#]
}

void transformAngleRate::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, LibraryPkg_AvionicsPkg_transformAngleRate_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    //#]
}

void transformAngleRate::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, LibraryPkg_AvionicsPkg_transformAngleRate_clean_SERIALIZE);
    //#[ operation clean() 
    
    if(eulerAngles) 	delete[] eulerAngles;
    if(bodyRates) 	delete[] bodyRates;
    if(eulerRates)delete[] eulerRates;
    
    //#]
}

void transformAngleRate::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, LibraryPkg_AvionicsPkg_transformAngleRate_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    receive();
    update();
    broadcast();
    
    //#]
}

void transformAngleRate::init() {
    NOTIFY_OPERATION(init, init(), 0, LibraryPkg_AvionicsPkg_transformAngleRate_init_SERIALIZE);
    //#[ operation init() 
    int i;
    
    size = 3;
    
    eulerAngles = new double[size];
    bodyRates = new double[size];
    eulerRates = new double[size];
    
    for(i=0;i<size;i++) eulerAngles[i] = 0.0;   
    for(i=0;i<size;i++) bodyRates[i] = 0.0;
    for(i=0;i<size;i++) eulerRates[i] = 0.0;
    //#]
}

void transformAngleRate::receive() {
    NOTIFY_OPERATION(receive, receive(), 0, LibraryPkg_AvionicsPkg_transformAngleRate_receive_SERIALIZE);
    //#[ operation receive() 
    //#]
}

void transformAngleRate::update() {
    NOTIFY_OPERATION(update, update(), 0, LibraryPkg_AvionicsPkg_transformAngleRate_update_SERIALIZE);
    //#[ operation update() 
        double c_phi	= cos(eulerAngles[0]); // phi
    	double s_phi	= sin(eulerAngles[0]);
    	double c_theta  = cos(eulerAngles[1]); // theta
    	double s_theta  = sin(eulerAngles[1]);
    	double t_theta  = s_theta/(c_theta+1e-12);
    
    	eulerRates[0]	=         bodyRates[0] + bodyRates[1] * t_theta * s_phi 
    						    + bodyRates[2] * t_theta * c_phi;
    
    	eulerRates[1]	=		  bodyRates[1] * c_phi - bodyRates[2] * s_phi;
    
    	eulerRates[2]	=		  bodyRates[1] * s_phi/t_theta
    							- bodyRates[2] * c_phi/c_theta; // + ?? -Z?? 
    //#]
}

double* transformAngleRate::getBodyRates() const {
    return bodyRates;
}

void transformAngleRate::setBodyRates(double*  p_bodyRates) {
    bodyRates = p_bodyRates;
}

double* transformAngleRate::getEulerAngles() const {
    return eulerAngles;
}

void transformAngleRate::setEulerAngles(double*  p_eulerAngles) {
    eulerAngles = p_eulerAngles;
}

double* transformAngleRate::getEulerRates() const {
    return eulerRates;
}

void transformAngleRate::setEulerRates(double*  p_eulerRates) {
    eulerRates = p_eulerRates;
}

int transformAngleRate::getSize() const {
    return size;
}

void transformAngleRate::setSize(int  p_size) {
    size = p_size;
}



#ifdef _OMINSTRUMENT


void OMAnimatedtransformAngleRate::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("eulerAngles", x2String(myReal->eulerAngles));
    aomsAttributes->addAttribute("eulerRates", x2String(myReal->eulerRates));
    aomsAttributes->addAttribute("bodyRates", x2String(myReal->bodyRates));
    aomsAttributes->addAttribute("size", x2String(myReal->size));
}

IMPLEMENT_META(transformAngleRate, LibraryPkg_AvionicsPkg, FALSE, OMAnimatedtransformAngleRate)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\transformAngleRate.cpp
*********************************************************************/

