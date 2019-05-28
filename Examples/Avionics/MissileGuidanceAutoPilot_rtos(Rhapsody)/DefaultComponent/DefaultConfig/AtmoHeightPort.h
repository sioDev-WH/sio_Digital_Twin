/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AtmoHeightPort
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AtmoHeightPort.h
*********************************************************************/


#ifndef AtmoHeightPort_H 

#define AtmoHeightPort_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include "aeroLength.h"
#include "OnStlConnBase.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AtmoHeightPort.h                                                                  
//----------------------------------------------------------------------------

//## class AtmoHeightPort 
class AtmoHeightPort : public OnStlConnBase<AtmoHeightPort> {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    AtmoHeightPort();
    
    //## auto_generated 
    ~AtmoHeightPort();


////    Operations    ////
public :
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation enumVars(OnStlVec<double> * * & ,long & ) 
    void enumVars(OnStlVec<double> * * & vec, long & size);


////    Additional operations    ////
public :
    
    //## auto_generated 
    aeroLength<double>  getHeight() const;
    
    //## auto_generated 
    void setHeight(aeroLength<double> p_height);


////    Attributes    ////
public :
    
    aeroLength<double> height;		//## attribute height 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AtmoHeightPort.h
*********************************************************************/

