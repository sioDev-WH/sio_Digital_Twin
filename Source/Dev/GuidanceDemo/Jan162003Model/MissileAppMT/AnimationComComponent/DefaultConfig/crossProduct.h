/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: crossProduct
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\crossProduct.h
*********************************************************************/


#ifndef crossProduct_H 

#define crossProduct_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AvionicsPkg.h"

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// crossProduct.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedcrossProduct;
#endif // _OMINSTRUMENT


//## class crossProduct 
class crossProduct  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedcrossProduct;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation crossProduct() 
    crossProduct();
    
    //## operation ~crossProduct() 
    ~crossProduct();


////    Operations    ////
public :
    
    //## operation broadcast() 
    void broadcast();
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation receive() 
    void receive();
    
    //## operation update() 
    void update();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double* getA() const;
    
    //## auto_generated 
    void setA(double*  p_a);
    
    //## auto_generated 
    double* getB() const;
    
    //## auto_generated 
    void setB(double*  p_b);
    
    //## auto_generated 
    double* getC() const;
    
    //## auto_generated 
    void setC(double*  p_c);
    
    //## auto_generated 
    int getSize() const;
    
    //## auto_generated 
    void setSize(int  p_size);


////    Attributes    ////
protected :
    
    double* a;		//## attribute a 
    
    double* b;		//## attribute b 
    
    double* c;		//## attribute c 
    
    int size;		//## attribute size 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedcrossProduct : virtual public AOMInstance {

    
    DECLARE_META(crossProduct, OMAnimatedcrossProduct)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\crossProduct.h
*********************************************************************/

