/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: dotProduct
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\dotProduct.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "dotProduct.h"
#include <stdafx.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define LibraryPkg_AvionicsPkg_dotProduct_dotProduct_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_dotProduct_broadcast_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_dotProduct_clean_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_dotProduct_handle_tick_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_dotProduct_init_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_dotProduct_receive_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_dotProduct_update_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// dotProduct.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class dotProduct 



dotProduct::dotProduct() {
    NOTIFY_CONSTRUCTOR(dotProduct, dotProduct(), 0, LibraryPkg_AvionicsPkg_dotProduct_dotProduct_SERIALIZE);
    //#[ operation dotProduct() 
    init();
    //#]
}

dotProduct::~dotProduct() {
    NOTIFY_DESTRUCTOR(~dotProduct, TRUE);
    //#[ operation ~dotProduct() 
    clean();
    //#]
}

void dotProduct::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, LibraryPkg_AvionicsPkg_dotProduct_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    //#]
}

void dotProduct::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, LibraryPkg_AvionicsPkg_dotProduct_clean_SERIALIZE);
    //#[ operation clean() 
    
    if(a) delete[] a;
    if(b) 	delete[] b;
    
    
    //#]
}

void dotProduct::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, LibraryPkg_AvionicsPkg_dotProduct_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    receive();
    update();
    broadcast();
    
    //#]
}

void dotProduct::init() {
    NOTIFY_OPERATION(init, init(), 0, LibraryPkg_AvionicsPkg_dotProduct_init_SERIALIZE);
    //#[ operation init() 
    int i;
    
    size = 3;
    
    a = new double[size];
    b = new double[size];
    
    
    for(i=0;i<size;i++) a[i] = 0.0;   
    for(i=0;i<size;i++) b[i] = 0.0;
    
    //#]
}

void dotProduct::receive() {
    NOTIFY_OPERATION(receive, receive(), 0, LibraryPkg_AvionicsPkg_dotProduct_receive_SERIALIZE);
    //#[ operation receive() 
    //#]
}

void dotProduct::update() {
    NOTIFY_OPERATION(update, update(), 0, LibraryPkg_AvionicsPkg_dotProduct_update_SERIALIZE);
    //#[ operation update() 
      c = a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
    
    //#]
}

double* dotProduct::getA() const {
    return a;
}

void dotProduct::setA(double*  p_a) {
    a = p_a;
}

double* dotProduct::getB() const {
    return b;
}

void dotProduct::setB(double*  p_b) {
    b = p_b;
}

double dotProduct::getC() const {
    return c;
}

void dotProduct::setC(double  p_c) {
    c = p_c;
}

int dotProduct::getSize() const {
    return size;
}

void dotProduct::setSize(int  p_size) {
    size = p_size;
}



#ifdef _OMINSTRUMENT


void OMAnimateddotProduct::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("a", x2String(myReal->a));
    aomsAttributes->addAttribute("b", x2String(myReal->b));
    aomsAttributes->addAttribute("c", x2String(myReal->c));
    aomsAttributes->addAttribute("size", x2String(myReal->size));
}

IMPLEMENT_META(dotProduct, LibraryPkg_AvionicsPkg, FALSE, OMAnimateddotProduct)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\dotProduct.cpp
*********************************************************************/

