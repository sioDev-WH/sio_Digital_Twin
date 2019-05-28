/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: transformAngle_Euler2Quaternion
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\transformAngle_Euler2Quaternion.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "transformAngle_Euler2Quaternion.h"
#include <stdafx.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_transformAngle_Euler2Quaternion_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_broadcast_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_clean_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_handle_tick_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_init_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_receive_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_update_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// transformAngle_Euler2Quaternion.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class transformAngle_Euler2Quaternion 



transformAngle_Euler2Quaternion::transformAngle_Euler2Quaternion() {
    NOTIFY_CONSTRUCTOR(transformAngle_Euler2Quaternion, transformAngle_Euler2Quaternion(), 0, LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_transformAngle_Euler2Quaternion_SERIALIZE);
    //#[ operation transformAngle_Euler2Quaternion() 
    init();
    //#]
}

transformAngle_Euler2Quaternion::~transformAngle_Euler2Quaternion() {
    NOTIFY_DESTRUCTOR(~transformAngle_Euler2Quaternion, TRUE);
    //#[ operation ~transformAngle_Euler2Quaternion() 
    clean();
    //#]
}

void transformAngle_Euler2Quaternion::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    //#]
}

void transformAngle_Euler2Quaternion::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_clean_SERIALIZE);
    //#[ operation clean() 
    
    if(eulerAngles) 	delete[] eulerAngles;
    if(q) 	delete[] q;
    
    
    //#]
}

void transformAngle_Euler2Quaternion::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    receive();
    update();
    broadcast();
    
    //#]
}

void transformAngle_Euler2Quaternion::init() {
    NOTIFY_OPERATION(init, init(), 0, LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_init_SERIALIZE);
    //#[ operation init() 
    int i;
    
    size = 3;
    q_size = 4;
    
    eulerAngles = new double[size];
    q = new double[q_size]; 
    
    for(i=0;i<size;i++) eulerAngles[i] = 0.0; 
    for(i=0;i<q_size;i++) q[i] = 0.0;
    
    
    //#]
}

void transformAngle_Euler2Quaternion::receive() {
    NOTIFY_OPERATION(receive, receive(), 0, LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_receive_SERIALIZE);
    //#[ operation receive() 
    //#]
}

void transformAngle_Euler2Quaternion::update() {
    NOTIFY_OPERATION(update, update(), 0, LibraryPkg_AvionicsPkg_transformAngle_Euler2Quaternion_update_SERIALIZE);
    //#[ operation update() 
    
     	double c_phi	= cos(eulerAngles[0]/2);
    	double s_phi	= sin(eulerAngles[0]/2);
    	double c_theta  = cos(eulerAngles[1]/2);
    	double s_theta  = sin(eulerAngles[1]/2);
    	double c_psi	= cos(eulerAngles[2]/2);
    	double s_psi	= sin(eulerAngles[2]/2);
    
    	q[0] = c_phi*c_theta*c_psi + s_phi*s_theta*s_psi;
    	q[1] = s_phi*c_theta*c_psi - c_phi*s_theta*s_psi;
    	q[2] = c_phi*s_theta*c_psi + s_phi*c_theta*s_psi;
    	q[3] = c_phi*c_theta*s_psi - s_phi*s_theta*s_psi; // c_psi???
    //#]
}

double* transformAngle_Euler2Quaternion::getEulerAngles() const {
    return eulerAngles;
}

void transformAngle_Euler2Quaternion::setEulerAngles(double*  p_eulerAngles) {
    eulerAngles = p_eulerAngles;
}

double* transformAngle_Euler2Quaternion::getQ() const {
    return q;
}

void transformAngle_Euler2Quaternion::setQ(double*  p_q) {
    q = p_q;
}

int transformAngle_Euler2Quaternion::getQ_size() const {
    return q_size;
}

void transformAngle_Euler2Quaternion::setQ_size(int  p_q_size) {
    q_size = p_q_size;
}

int transformAngle_Euler2Quaternion::getSize() const {
    return size;
}

void transformAngle_Euler2Quaternion::setSize(int  p_size) {
    size = p_size;
}



#ifdef _OMINSTRUMENT


void OMAnimatedtransformAngle_Euler2Quaternion::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("eulerAngles", x2String(myReal->eulerAngles));
    aomsAttributes->addAttribute("q", x2String(myReal->q));
    aomsAttributes->addAttribute("size", x2String(myReal->size));
    aomsAttributes->addAttribute("q_size", x2String(myReal->q_size));
}

IMPLEMENT_META(transformAngle_Euler2Quaternion, LibraryPkg_AvionicsPkg, FALSE, OMAnimatedtransformAngle_Euler2Quaternion)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\transformAngle_Euler2Quaternion.cpp
*********************************************************************/

