/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: dotProduct
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\dotProduct.h
*********************************************************************/


#ifndef dotProduct_H 

#define dotProduct_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AvionicsPkg.h"

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// dotProduct.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimateddotProduct;
#endif // _OMINSTRUMENT


//## class dotProduct 
class dotProduct  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimateddotProduct;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation dotProduct() 
    dotProduct();
    
    //## operation ~dotProduct() 
    ~dotProduct();


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
    double getC() const;
    
    //## auto_generated 
    void setC(double  p_c);
    
    //## auto_generated 
    int getSize() const;
    
    //## auto_generated 
    void setSize(int  p_size);


////    Attributes    ////
protected :
    
    double* a;		//## attribute a 
    
    double* b;		//## attribute b 
    
    double c;		//## attribute c 
    
    int size;		//## attribute size 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimateddotProduct : virtual public AOMInstance {

    
    DECLARE_META(dotProduct, OMAnimateddotProduct)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\dotProduct.h
*********************************************************************/

