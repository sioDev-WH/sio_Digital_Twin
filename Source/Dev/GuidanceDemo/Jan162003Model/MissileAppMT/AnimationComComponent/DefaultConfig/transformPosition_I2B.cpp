/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: transformPosition_I2B
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\transformPosition_I2B.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "transformPosition_I2B.h"
#include <stdafx.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define LibraryPkg_AvionicsPkg_transformPosition_I2B_transformPosition_I2B_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_I2B_broadcast_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_I2B_clean_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_I2B_handle_tick_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_I2B_init_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_I2B_receive_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_I2B_update_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// transformPosition_I2B.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class transformPosition_I2B 



transformPosition_I2B::transformPosition_I2B() {
    NOTIFY_CONSTRUCTOR(transformPosition_I2B, transformPosition_I2B(), 0, LibraryPkg_AvionicsPkg_transformPosition_I2B_transformPosition_I2B_SERIALIZE);
    //#[ operation transformPosition_I2B() 
    init();
    //#]
}

transformPosition_I2B::~transformPosition_I2B() {
    NOTIFY_DESTRUCTOR(~transformPosition_I2B, TRUE);
    //#[ operation ~transformPosition_I2B() 
    clean();
    //#]
}

void transformPosition_I2B::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, LibraryPkg_AvionicsPkg_transformPosition_I2B_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    //#]
}

void transformPosition_I2B::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, LibraryPkg_AvionicsPkg_transformPosition_I2B_clean_SERIALIZE);
    //#[ operation clean() 
    
    if(eulerAngles) 	delete[] eulerAngles;
    if(body) 	delete[] body;
    if(inertial)delete[] inertial;
    
    //#]
}

void transformPosition_I2B::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, LibraryPkg_AvionicsPkg_transformPosition_I2B_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    receive();
    update();
    broadcast();
    
    //#]
}

void transformPosition_I2B::init() {
    NOTIFY_OPERATION(init, init(), 0, LibraryPkg_AvionicsPkg_transformPosition_I2B_init_SERIALIZE);
    //#[ operation init() 
    int i;
    
    size = 3;
    
    eulerAngles = new double[size];
    body = new double[size];
    inertial = new double[size];
    
    for(i=0;i<size;i++) eulerAngles[i] = 0.0;   
    for(i=0;i<size;i++) body[i] = 0.0;
    for(i=0;i<size;i++) inertial[i] = 0.0;
    //#]
}

void transformPosition_I2B::receive() {
    NOTIFY_OPERATION(receive, receive(), 0, LibraryPkg_AvionicsPkg_transformPosition_I2B_receive_SERIALIZE);
    //#[ operation receive() 
    //#]
}

void transformPosition_I2B::update() {
    NOTIFY_OPERATION(update, update(), 0, LibraryPkg_AvionicsPkg_transformPosition_I2B_update_SERIALIZE);
    //#[ operation update() 
        double c_phi	= cos(eulerAngles[0]); // phi
    	double s_phi	= sin(eulerAngles[0]);
    	double c_theta  = cos(eulerAngles[1]); // theta
    	double s_theta  = sin(eulerAngles[1]);
    	double c_psi	= cos(eulerAngles[2]); // psi
    	double s_psi	= sin(eulerAngles[2]);
    
    	body[0] =   c_theta*c_psi					   * inertial[0]
    			  + c_theta*s_psi					   * inertial[1]
    			  - s_theta							   * inertial[2];
    	
    	body[1] =   (s_phi*s_theta*c_psi - c_phi*s_psi) * inertial[0]
    		      + (s_phi*s_theta*s_psi - c_phi*c_psi) * inertial[1]
    			  + (s_phi*c_theta                    ) * inertial[2];
    
    	body[2] =   (c_phi*s_theta*c_psi + s_phi*s_psi) * inertial[0]
    		      + (c_phi*s_theta*s_psi - s_phi*c_psi) * inertial[1]
    			  + (c_phi*c_theta                    ) * inertial[2]; 
    //#]
}

double* transformPosition_I2B::getBody() const {
    return body;
}

void transformPosition_I2B::setBody(double*  p_body) {
    body = p_body;
}

double* transformPosition_I2B::getEulerAngles() const {
    return eulerAngles;
}

void transformPosition_I2B::setEulerAngles(double*  p_eulerAngles) {
    eulerAngles = p_eulerAngles;
}

double* transformPosition_I2B::getInertial() const {
    return inertial;
}

void transformPosition_I2B::setInertial(double*  p_inertial) {
    inertial = p_inertial;
}

int transformPosition_I2B::getSize() const {
    return size;
}

void transformPosition_I2B::setSize(int  p_size) {
    size = p_size;
}



#ifdef _OMINSTRUMENT


void OMAnimatedtransformPosition_I2B::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("eulerAngles", x2String(myReal->eulerAngles));
    aomsAttributes->addAttribute("inertial", x2String(myReal->inertial));
    aomsAttributes->addAttribute("body", x2String(myReal->body));
    aomsAttributes->addAttribute("size", x2String(myReal->size));
}

IMPLEMENT_META(transformPosition_I2B, LibraryPkg_AvionicsPkg, FALSE, OMAnimatedtransformPosition_I2B)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\transformPosition_I2B.cpp
*********************************************************************/

