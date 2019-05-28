/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: transformAngle_DMC2Euler
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\transformAngle_DMC2Euler.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "transformAngle_DMC2Euler.h"
#include <stdafx.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_transformAngle_DMC2Euler_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_broadcast_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_clean_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_handle_tick_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_init_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_receive_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_update_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// transformAngle_DMC2Euler.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class transformAngle_DMC2Euler 



transformAngle_DMC2Euler::transformAngle_DMC2Euler() {
    NOTIFY_CONSTRUCTOR(transformAngle_DMC2Euler, transformAngle_DMC2Euler(), 0, LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_transformAngle_DMC2Euler_SERIALIZE);
    //#[ operation transformAngle_DMC2Euler() 
    init();
    //#]
}

transformAngle_DMC2Euler::~transformAngle_DMC2Euler() {
    NOTIFY_DESTRUCTOR(~transformAngle_DMC2Euler, TRUE);
    //#[ operation ~transformAngle_DMC2Euler() 
    clean();
    //#]
}

void transformAngle_DMC2Euler::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    //#]
}

void transformAngle_DMC2Euler::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_clean_SERIALIZE);
    //#[ operation clean() 
    
    if(eulerAngles) 	delete[] eulerAngles;
    if(DMC) 	delete[] DMC;
    
    
    //#]
}

void transformAngle_DMC2Euler::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    receive();
    update();
    broadcast();
    
    //#]
}

void transformAngle_DMC2Euler::init() {
    NOTIFY_OPERATION(init, init(), 0, LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_init_SERIALIZE);
    //#[ operation init() 
    int i;
    
    
    size = 3;
    DMC_size = size*size;
    
    eulerAngles = new double[size];
    DMC = new double[DMC_size]; 
    
    for(i=0;i<size;i++) eulerAngles[i] = 0.0; 
    for(i=0;i<DMC_size;i++) DMC[i] = 0.0;
    
    
    //#]
}

void transformAngle_DMC2Euler::receive() {
    NOTIFY_OPERATION(receive, receive(), 0, LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_receive_SERIALIZE);
    //#[ operation receive() 
    //#]
}

void transformAngle_DMC2Euler::update() {
    NOTIFY_OPERATION(update, update(), 0, LibraryPkg_AvionicsPkg_transformAngle_DMC2Euler_update_SERIALIZE);
    //#[ operation update() 
    
    	eulerAngles[0]   = atan( DMC[5]/DMC[8]);
    	eulerAngles[1]   = asin(-DMC[2]);
    	eulerAngles[2]   = atan( DMC[1]/DMC[0]);
    
     
    //#]
}

double* transformAngle_DMC2Euler::getDMC() const {
    return DMC;
}

void transformAngle_DMC2Euler::setDMC(double*  p_DMC) {
    DMC = p_DMC;
}

int transformAngle_DMC2Euler::getDMC_size() const {
    return DMC_size;
}

void transformAngle_DMC2Euler::setDMC_size(int  p_DMC_size) {
    DMC_size = p_DMC_size;
}

double* transformAngle_DMC2Euler::getEulerAngles() const {
    return eulerAngles;
}

void transformAngle_DMC2Euler::setEulerAngles(double*  p_eulerAngles) {
    eulerAngles = p_eulerAngles;
}

int transformAngle_DMC2Euler::getSize() const {
    return size;
}

void transformAngle_DMC2Euler::setSize(int  p_size) {
    size = p_size;
}



#ifdef _OMINSTRUMENT


void OMAnimatedtransformAngle_DMC2Euler::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("eulerAngles", x2String(myReal->eulerAngles));
    aomsAttributes->addAttribute("DMC", x2String(myReal->DMC));
    aomsAttributes->addAttribute("size", x2String(myReal->size));
    aomsAttributes->addAttribute("DMC_size", x2String(myReal->DMC_size));
}

IMPLEMENT_META(transformAngle_DMC2Euler, LibraryPkg_AvionicsPkg, FALSE, OMAnimatedtransformAngle_DMC2Euler)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\transformAngle_DMC2Euler.cpp
*********************************************************************/

