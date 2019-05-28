/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Atmosphere
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Atmosphere.h
*********************************************************************/


#ifndef Atmosphere_H 

#define Atmosphere_H 


//----------------------------------------------------------------------------
// Atmosphere.h                                                                  
//----------------------------------------------------------------------------
class AtmoCoeff;


//## class Atmosphere 
class Atmosphere  {


////    Constructors and destructors    ////
public :
    
    //## operation Atmosphere() 
    Atmosphere();
    
    //## operation ~Atmosphere() 
    virtual ~Atmosphere();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation setCoeff(AtmoCoeff * ) 
    void setCoeff(AtmoCoeff * pC);
    
    //## operation setHeight(double) 
    void setHeight(double  h);
    
    //## operation updateData(double) 
    void updateData(double  height);


////    Attributes    ////
public :
    
    double airDensity;		//## attribute airDensity 
    
    double airPressure;		//## attribute airPressure 
    
    double height;		//## attribute height 
    
    double speedOfSound;		//## attribute speedOfSound 
    
    double temperature;		//## attribute temperature 
    

////    Relations and components    ////
public :
    
    AtmoCoeff* pCoeff;		//## link pCoeff 
    


};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Atmosphere.h
*********************************************************************/

