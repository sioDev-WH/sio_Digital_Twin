/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Quaternion
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\Quaternion.h
*********************************************************************/


#ifndef Quaternion_H 

#define Quaternion_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"

//## package AirframePkg 


//#[ ignore 
#define AirframePkg_Quaternion_Quaternion_SERIALIZE OM_NO_OP


#define AirframePkg_Quaternion_operator_SERIALIZE OM_NO_OP


#define OM_AirframePkg_Quaternion_operator_1_SERIALIZE OM_NO_OP


#define OM_AirframePkg_Quaternion_operator_2_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Quaternion.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedQuaternion;
#endif // _OMINSTRUMENT


//## class Quaternion 
template <class T> class Quaternion  {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedQuaternion<T> OMAnimatedQuaternionType;
        
    #endif // _OMINSTRUMENT
    
//## class Quaternion 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedQuaternion<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Quaternion() 
    Quaternion();
    
    //## auto_generated 
    ~Quaternion();


////    Operations    ////
public :
    
    //## operation operator()(int) 
    T operator()(int  i);
    
    //## operation operator=(Quaternion<T> ) 
    void operator=(Quaternion<T> src);
    
    //## operation operator[](int) 
    T &  operator[](int  i);


////    Additional operations    ////
public :
    
    //## auto_generated 
    int getN() const;
    
    //## auto_generated 
    void setN(int  p_n);
    
    //## auto_generated 
    T getQ(int  i1) const;
    
    //## auto_generated 
    void setQ(int  i1, T  p_q);


////    Attributes    ////
public :
    
    int n;		//## attribute n 
    
    T q[4];		//## attribute q 
    

};

//## class Quaternion 



template <class T> Quaternion<T> ::Quaternion() {
    NOTIFY_CONSTRUCTOR_T(Quaternion, Quaternion(), 0, AirframePkg_Quaternion_Quaternion_SERIALIZE, OMAnimatedQuaternionType);
    //#[ operation Quaternion() 
    n=4;q[0]=1.0;q[1]=q[2]=q[3]=0.0;
    //#]
}

template <class T> Quaternion<T> ::~Quaternion() {
    NOTIFY_DESTRUCTOR(~Quaternion, TRUE);
}

template <class T> T Quaternion<T> ::operator()(int  i) {
    NOTIFY_OPERATION(operator(), operator()(int), 0, AirframePkg_Quaternion_operator_SERIALIZE);
    //#[ operation operator()(int) 
    if(i>=0 &&i<4) 
    	return q[i]; 
    else
    {
    	cerr<<"Invalid index\n";
    	return numeric_limits<T>::quiet_NaN();
    }
    //#]
}

template <class T> void Quaternion<T> ::operator=(Quaternion<T> src) {
    NOTIFY_OPERATION(operator=, operator=(Quaternion<T> ), 0, OM_AirframePkg_Quaternion_operator_1_SERIALIZE);
    //#[ operation operator=(Quaternion<T> ) 
    if(n==src.n) for(int i=0;i<nVars;i++)q[i]=src.q[i];
    //#]
}

template <class T> T &  Quaternion<T> ::operator[](int  i) {
    NOTIFY_OPERATION(operator[], operator[](int), 0, OM_AirframePkg_Quaternion_operator_2_SERIALIZE);
    //#[ operation operator[](int) 
    if(i>=0 &&i<4) 
    	return q[i]; 
    else {
    	cerr<<"Invalid index\n"; 
    	return q[0];
    }
    //#]
}

template <class T> int Quaternion<T> ::getN() const {
    return n;
}

template <class T> void Quaternion<T> ::setN(int  p_n) {
    n = p_n;
}

template <class T> T Quaternion<T> ::getQ(int  i1) const {
    return q[i1];
}

template <class T> void Quaternion<T> ::setQ(int  i1, T  p_q) {
    q[i1] = p_q;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(Quaternion)

//## ignore 
template <class T> class OMAnimatedQuaternion : virtual public AOMInstance {
public :
    
        
        typedef Quaternion<T> OMQuaternionType;
        
    

    
    DECLARE_META_T(Quaternion, OMQuaternionType, OMAnimatedQuaternion)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};



template <class T> void OMAnimatedQuaternion<T> ::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Quaternion.h
*********************************************************************/

