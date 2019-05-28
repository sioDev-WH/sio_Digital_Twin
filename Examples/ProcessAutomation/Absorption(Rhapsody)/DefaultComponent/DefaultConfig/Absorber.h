/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Absorber
//!	Generated Date	: Sat, 2, Nov 2002  
	File Path	: DefaultComponent\DefaultConfig\Absorber.h
*********************************************************************/


#ifndef Absorber_H 

#define Absorber_H 


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
// Absorber.h                                                                  
//----------------------------------------------------------------------------
class GasAbsorber;
class MixerTank;
class TubularReactor;


//## class Absorber 
class Absorber : public OMReactive, public COnUMLDaeEsoImpl<Absorber> {


////    Constructors and destructors    ////
public :
    
    //## operation Absorber() 
    Absorber();
    
    //## operation ~Absorber() 
    ~Absorber();


////    Operations    ////
public :
    
    HRESULT r_absorber_feed(long i, double*  res);

    //## operation r_absorber_feed0(double*) 
    HRESULT r_absorber_feed_0(double*  res);
    
    //## operation r_absorber_feed1(double*) 
    HRESULT r_absorber_feed_1(double*  res);
    
    //## operation r_absorber_feed2(double*) 
    HRESULT r_absorber_feed_2(double*  res);
    
    HRESULT r_mixer_feed(long i, double*  res);

    //## operation r_mixer_feed0(double*) 
    HRESULT r_mixer_feed_0(double*  res);
    
    //## operation r_mixer_feed1(double*) 
    HRESULT r_mixer_feed_1(double*  res);
    
    //## operation r_mixer_feed2(double*) 
    HRESULT r_mixer_feed_2(double*  res);
    
    HRESULT r_mixer_recycle(long i, double*  res);

    //## operation r_mixer_recycle0(double*) 
    HRESULT r_mixer_recycle_0(double*  res);
    
    //## operation r_mixer_recycle1(double*) 
    HRESULT r_mixer_recycle_1(double*  res);
    
    //## operation r_mixer_recycle2(double*) 
    HRESULT r_mixer_recycle_2(double*  res);
    
    HRESULT r_reactor_feed(long i, double*  res);

    //## operation r_reactor_feed0(double*) 
    HRESULT r_reactor_feed_0(double*  res);
    
    //## operation r_reactor_feed1(double*) 
    HRESULT r_reactor_feed_1(double*  res);
    
    //## operation r_reactor_feed2(double*) 
    HRESULT r_reactor_feed_2(double*  res);

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
    
    HRESULT ad_r_absorber_feed(long i, Fdouble*  res);

    //## operation r_absorber_feed0(Fdouble*) 
    HRESULT ad_r_absorber_feed_0(Fdouble*  res);
    
    //## operation r_absorber_feed1(Fdouble*) 
    HRESULT ad_r_absorber_feed_1(Fdouble*  res);
    
    //## operation r_absorber_feed2(Fdouble*) 
    HRESULT ad_r_absorber_feed_2(Fdouble*  res);
    
    HRESULT ad_r_mixer_feed(long i, Fdouble*  res);

    //## operation r_mixer_feed0(Fdouble*) 
    HRESULT ad_r_mixer_feed_0(Fdouble*  res);
    
    //## operation r_mixer_feed1(Fdouble*) 
    HRESULT ad_r_mixer_feed_1(Fdouble*  res);
    
    //## operation r_mixer_feed2(Fdouble*) 
    HRESULT ad_r_mixer_feed_2(Fdouble*  res);
    
    HRESULT ad_r_mixer_recycle(long i, Fdouble*  res);
    
    //## operation r_mixer_recycle0(Fdouble*) 
    HRESULT ad_r_mixer_recycle_0(Fdouble*  res);
    
    //## operation r_mixer_recycle1(Fdouble*) 
    HRESULT ad_r_mixer_recycle_1(Fdouble*  res);
    
    //## operation r_mixer_recycle2(Fdouble*) 
    HRESULT ad_r_mixer_recycle_2(Fdouble*  res);
    
    HRESULT ad_r_reactor_feed(long i, Fdouble*  res);
    
    //## operation r_reactor_feed0(Fdouble*) 
    HRESULT ad_r_reactor_feed_0(Fdouble*  res);
    
    //## operation r_reactor_feed1(Fdouble*) 
    HRESULT ad_r_reactor_feed_1(Fdouble*  res);
    
    //## operation r_reactor_feed2(Fdouble*) 
    HRESULT ad_r_reactor_feed_2(Fdouble*  res);

////    Additional operations    ////
public :
    
    //## auto_generated 
    double* getFeed() const;
    
    //## auto_generated 
    void setFeed(double*  p_feed);
    
    //## auto_generated 
    GasAbsorber* getPAbsorber() const;
    
    //## auto_generated 
    void setPAbsorber(GasAbsorber*  p_GasAbsorber);
    
    //## auto_generated 
    MixerTank* getPMixer() const;
    
    //## auto_generated 
    void setPMixer(MixerTank*  p_MixerTank);
    
    //## auto_generated 
    TubularReactor* getPReactor() const;
    
    //## auto_generated 
    void setPReactor(TubularReactor*  p_TubularReactor);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
protected :
    
    double* feed;		//## attribute feed 
    

////    Relations and components    ////
protected :
    
    GasAbsorber* pAbsorber;		//## link pAbsorber 
    
    
    MixerTank* pMixer;		//## link pMixer 
    
    
    TubularReactor* pReactor;		//## link pReactor 
    
    double L;
    Fdouble ad_L;

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Absorber.h
*********************************************************************/

