/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: crossProduct
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\crossProduct.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "crossProduct.h"
#include <stdafx.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define LibraryPkg_AvionicsPkg_crossProduct_crossProduct_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_crossProduct_broadcast_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_crossProduct_clean_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_crossProduct_handle_tick_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_crossProduct_init_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_crossProduct_receive_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_crossProduct_update_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// crossProduct.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class crossProduct 



crossProduct::crossProduct() {
    NOTIFY_CONSTRUCTOR(crossProduct, crossProduct(), 0, LibraryPkg_AvionicsPkg_crossProduct_crossProduct_SERIALIZE);
    //#[ operation crossProduct() 
    init();
    //#]
}

crossProduct::~crossProduct() {
    NOTIFY_DESTRUCTOR(~crossProduct, TRUE);
    //#[ operation ~crossProduct() 
    clean();
    //#]
}

void crossProduct::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, LibraryPkg_AvionicsPkg_crossProduct_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    //#]
}

void crossProduct::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, LibraryPkg_AvionicsPkg_crossProduct_clean_SERIALIZE);
    //#[ operation clean() 
    
    if(a) delete[] a;
    if(b) 	delete[] b;
    if(c) 	delete[] c;
    
    //#]
}

void crossProduct::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, LibraryPkg_AvionicsPkg_crossProduct_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    receive();
    update();
    broadcast();
    
    //#]
}

void crossProduct::init() {
    NOTIFY_OPERATION(init, init(), 0, LibraryPkg_AvionicsPkg_crossProduct_init_SERIALIZE);
    //#[ operation init() 
    int i;
    
    
    size = 3;
    
    a = new double[size];
    b = new double[size];
    c = new double[size];
    
    for(i=0;i<size;i++) a[i] = 0.0;   
    for(i=0;i<size;i++) b[i] = 0.0;
    for(i=0;i<size;i++) c[i] = 0.0;
    
    //#]
}

void crossProduct::receive() {
    NOTIFY_OPERATION(receive, receive(), 0, LibraryPkg_AvionicsPkg_crossProduct_receive_SERIALIZE);
    //#[ operation receive() 
    //#]
}

void crossProduct::update() {
    NOTIFY_OPERATION(update, update(), 0, LibraryPkg_AvionicsPkg_crossProduct_update_SERIALIZE);
    //#[ operation update() 
      c[0] = a[1]*b[2] - a[2]*b[1];
      c[1] = a[2]*b[0] - a[0]*b[2];
      c[2] = a[0]*b[1] - a[1]*b[0]; 
    //#]
}

double* crossProduct::getA() const {
    return a;
}

void crossProduct::setA(double*  p_a) {
    a = p_a;
}

double* crossProduct::getB() const {
    return b;
}

void crossProduct::setB(double*  p_b) {
    b = p_b;
}

double* crossProduct::getC() const {
    return c;
}

void crossProduct::setC(double*  p_c) {
    c = p_c;
}

int crossProduct::getSize() const {
    return size;
}

void crossProduct::setSize(int  p_size) {
    size = p_size;
}



#ifdef _OMINSTRUMENT


void OMAnimatedcrossProduct::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("a", x2String(myReal->a));
    aomsAttributes->addAttribute("b", x2String(myReal->b));
    aomsAttributes->addAttribute("c", x2String(myReal->c));
    aomsAttributes->addAttribute("size", x2String(myReal->size));
}

IMPLEMENT_META(crossProduct, LibraryPkg_AvionicsPkg, FALSE, OMAnimatedcrossProduct)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\crossProduct.cpp
*********************************************************************/

