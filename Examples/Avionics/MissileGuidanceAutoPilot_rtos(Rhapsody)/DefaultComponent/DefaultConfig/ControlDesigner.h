/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ControlDesigner
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\ControlDesigner.h
*********************************************************************/


#ifndef ControlDesigner_H 

#define ControlDesigner_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AvionicsPkg.h"

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// ControlDesigner.h                                                                  
//----------------------------------------------------------------------------

//## class ControlDesigner 
class ControlDesigner  {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    ControlDesigner();
    
    //## auto_generated 
    ~ControlDesigner();


////    Operations    ////
public :
    
    //## operation SS_discretize(double,int,int,double*,double*,double*,double*) 
    void SS_discretize(double  Ts, int  n, int  m, double*  Ac, double*  Bc, double*  Ad, double*  Bd);
    
    //## operation expm(int,double*,double*) 
    void expm(int  n, double*  A, double*  E);
    
    //## operation log2(double) 
    double log2(double  x);
    
    //## operation norm_infinity(int,double*) 
    double norm_infinity(int  n, double*  A);
    
    //## operation prod(int,double*,double*,double* &) 
    void prod(int  n, double*  A, double*  B, double* &C);
    
    //## operation solve(int,double*,double*,double* &) 
    void solve(int  n, double*  A, double*  B, double* &C);
    
    //## operation trace(int,double*) 
    double trace(int  n, double*  A);


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ControlDesigner.h
*********************************************************************/

