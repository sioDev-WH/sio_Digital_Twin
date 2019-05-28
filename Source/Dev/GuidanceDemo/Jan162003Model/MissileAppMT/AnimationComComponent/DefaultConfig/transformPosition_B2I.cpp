/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: transformPosition_B2I
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\transformPosition_B2I.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "transformPosition_B2I.h"
#include <stdafx.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define LibraryPkg_AvionicsPkg_transformPosition_B2I_transformPosition_B2I_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_B2I_broadcast_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_B2I_clean_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_B2I_handle_tick_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_B2I_init_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_B2I_receive_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformPosition_B2I_update_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// transformPosition_B2I.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class transformPosition_B2I 



transformPosition_B2I::transformPosition_B2I() {
    NOTIFY_CONSTRUCTOR(transformPosition_B2I, transformPosition_B2I(), 0, LibraryPkg_AvionicsPkg_transformPosition_B2I_transformPosition_B2I_SERIALIZE);
    //#[ operation transformPosition_B2I() 
    init();
    //#]
}

transformPosition_B2I::~transformPosition_B2I() {
    NOTIFY_DESTRUCTOR(~transformPosition_B2I, TRUE);
    //#[ operation ~transformPosition_B2I() 
    clean();
    //#]
}

void transformPosition_B2I::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, LibraryPkg_AvionicsPkg_transformPosition_B2I_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    //#]
}

void transformPosition_B2I::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, LibraryPkg_AvionicsPkg_transformPosition_B2I_clean_SERIALIZE);
    //#[ operation clean() 
    
    if(eulerAngles) 	delete[] eulerAngles;
    if(body) 	delete[] body;
    if(inertial)delete[] inertial;
    
    //#]
}

void transformPosition_B2I::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, LibraryPkg_AvionicsPkg_transformPosition_B2I_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    receive();
    update();
    broadcast();
    
    //#]
}

void transformPosition_B2I::init() {
    NOTIFY_OPERATION(init, init(), 0, LibraryPkg_AvionicsPkg_transformPosition_B2I_init_SERIALIZE);
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

void transformPosition_B2I::receive() {
    NOTIFY_OPERATION(receive, receive(), 0, LibraryPkg_AvionicsPkg_transformPosition_B2I_receive_SERIALIZE);
    //#[ operation receive() 
    //#]
}

void transformPosition_B2I::update() {
    NOTIFY_OPERATION(update, update(), 0, LibraryPkg_AvionicsPkg_transformPosition_B2I_update_SERIALIZE);
    //#[ operation update() 
        double c_phi	= cos(eulerAngles[0]); // phi
    	double s_phi	= sin(eulerAngles[0]);
    	double c_theta  = cos(eulerAngles[1]); // theta
    	double s_theta  = sin(eulerAngles[1]);
    	double c_psi	= cos(eulerAngles[2]); // psi
    	double s_psi	= sin(eulerAngles[2]);
    
    	inertial[0] =   c_theta*c_psi					    * body[0]
    				 + (s_phi*s_theta*c_psi - c_phi*s_psi)  * body[1]
    				 + (c_phi*s_theta*c_psi + s_phi*s_psi)  * body[2];
    	
    	inertial[1] =   c_theta*s_psi                        * body[0]
    				 + (s_phi*s_theta*s_psi - c_phi*c_psi)  * body[1]
    				 + (c_phi*s_theta*s_psi - s_phi*c_psi)  * body[2];
    
    	inertial[2] = - s_theta		                        * body[0]
    				 + (s_phi*c_theta)                      * body[1]
    				 + (c_phi*c_theta)                      * body[2]; 
    //#]
}

double* transformPosition_B2I::getBody() const {
    return body;
}

void transformPosition_B2I::setBody(double*  p_body) {
    body = p_body;
}

double* transformPosition_B2I::getEulerAngles() const {
    return eulerAngles;
}

void transformPosition_B2I::setEulerAngles(double*  p_eulerAngles) {
    eulerAngles = p_eulerAngles;
}

double* transformPosition_B2I::getInertial() const {
    return inertial;
}

void transformPosition_B2I::setInertial(double*  p_inertial) {
    inertial = p_inertial;
}

int transformPosition_B2I::getSize() const {
    return size;
}

void transformPosition_B2I::setSize(int  p_size) {
    size = p_size;
}



#ifdef _OMINSTRUMENT


void OMAnimatedtransformPosition_B2I::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("eulerAngles", x2String(myReal->eulerAngles));
    aomsAttributes->addAttribute("inertial", x2String(myReal->inertial));
    aomsAttributes->addAttribute("body", x2String(myReal->body));
    aomsAttributes->addAttribute("size", x2String(myReal->size));
}

IMPLEMENT_META(transformPosition_B2I, LibraryPkg_AvionicsPkg, FALSE, OMAnimatedtransformPosition_B2I)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\transformPosition_B2I.cpp
*********************************************************************/

