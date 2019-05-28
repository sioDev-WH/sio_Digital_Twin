/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: MixerTank
//!	Generated Date	: Sat, 2, Nov 2002  
	File Path	: DefaultComponent\DefaultConfig\MixerTank.h
*********************************************************************/


#ifndef MixerTank_H 

#define MixerTank_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Models.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnUMLDaeEsoImpl.h"

//## package Models 

//----------------------------------------------------------------------------
// MixerTank.h                                                                  
//----------------------------------------------------------------------------

//## class MixerTank 
class MixerTank : public OMReactive, public COnUMLDaeEsoImpl<MixerTank>  {


////    Constructors and destructors    ////
public :
    
    //## operation MixerTank() 
    MixerTank();
    
    //## operation ~MixerTank() 
    ~MixerTank();


////    Operations    ////
public :
    
    //## operation r_res0(double*) 
    HRESULT r_res(long i, double*  res);

    //## operation r_res1(double*) 
    HRESULT r_res_0(double*  res);
    
    //## operation r_res1(double*) 
    HRESULT r_res_1(double*  res);
    
    //## operation r_res2(double*) 
    HRESULT r_res_2(double*  res);

    //## operation r_res0(double*) 
    HRESULT ad_r_res(long i, Fdouble*  res);

    //## operation ad_r_res1(double*) 
    HRESULT ad_r_res_0(Fdouble*  res);
    
    //## operation ad_r_res1(double*) 
    HRESULT ad_r_res_1(Fdouble*  res);
    
    //## operation ad_r_res2(double*) 
    HRESULT ad_r_res_2(Fdouble*  res);

protected:

    //## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    HRESULT InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form);
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalVars(const _TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,const bool) 
    HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);

////    Additional operations    ////
public :
    


////    Attributes    ////
public :
    
    double K8;		//## attribute K8 
    
    double K9;		//## attribute K9 
    
    double* feed_in;		//## attribute feed_in 
    
    double* gamma;		//## attribute gamma 
    VarExV _gamma;
    
    double* recycle_in;		//## attribute recycle_in 
    
    // All units are scled to length = 1
    double L;		//## attribute L 

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\MixerTank.h
*********************************************************************/

