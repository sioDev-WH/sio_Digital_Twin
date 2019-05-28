/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FinPort
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\FinPort.h
*********************************************************************/


#ifndef FinPort_H 

#define FinPort_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include "OnStlConnBase.h"
#include "aeroAngle.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// FinPort.h                                                                  
//----------------------------------------------------------------------------

//## class FinPort 
class FinPort : public OnStlConnBase<FinPort> {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    FinPort();
    
    //## auto_generated 
    ~FinPort();


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
    Angle getAngle() const;
    
    //## auto_generated 
    void setAngle(Angle  p_angle);


////    Attributes    ////
public :
    
    Angle angle;		//## attribute angle 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FinPort.h
*********************************************************************/

