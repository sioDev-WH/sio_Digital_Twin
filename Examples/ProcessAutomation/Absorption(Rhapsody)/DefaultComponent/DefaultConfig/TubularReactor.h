/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TubularReactor
//!	Generated Date	: Sat, 2, Nov 2002  
	File Path	: DefaultComponent\DefaultConfig\TubularReactor.h
*********************************************************************/


#ifndef TubularReactor_H 

#define TubularReactor_H 


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
// TubularReactor.h                                                                  
//----------------------------------------------------------------------------

//## class TubularReactor 
class TubularReactor : public OMReactive, public COnUMLDaeEsoImpl<TubularReactor>  {


////    Constructors and destructors    ////
public :
    
    //## operation TubularReactor() 
    TubularReactor();
    
    //## operation ~TubularReactor() 
    ~TubularReactor();


////    Operations    ////
public :
    
    //## operation r_BC0() 
    HRESULT r_BC0(long i);
    HRESULT r_BC0_0();
    HRESULT r_BC0_1();
    HRESULT r_BC0_2();
    
    //## operation r_BCL() 
    HRESULT r_BCL(long i);
    HRESULT r_BCL_0();
    HRESULT r_BCL_1();
    HRESULT r_BCL_2();
    
    //## operation r_MB() 
    HRESULT r_MB(long i);
    HRESULT r_MB_0();
    HRESULT r_MB_1();
    HRESULT r_MB_2();

    HRESULT ad_r_BC0(long i);
    HRESULT ad_r_BC0_0();
    HRESULT ad_r_BC0_1();
    HRESULT ad_r_BC0_2();
    
    //## operation ad_r_BCL() 
    HRESULT ad_r_BCL(long i);
    HRESULT ad_r_BCL_0();
    HRESULT ad_r_BCL_1();
    HRESULT ad_r_BCL_2();
    
    //## operation ad_r_MB() 
    HRESULT ad_r_MB(long i);
    HRESULT ad_r_MB_0();
    HRESULT ad_r_MB_1();
    HRESULT ad_r_MB_2();

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
    


////    Framework operations    ////
protected :
    

////    Attributes    ////
public :
    
    DistributionDomain Axial;		//## attribute Axial 
    
    double K1;		//## attribute K1 
    
    double K2;		//## attribute K2 
    
    // All units are scled to length = 1
    double Len;		//## attribute Len 
    
    D_Mesh Mesh;		//## attribute Mesh 
    
    int attribute_12;		//## attribute attribute_12 
    
    DistributedVar conc;		//## attribute conc 
    
    // Stoichiometric coefficients
    double* nu;		//## attribute nu 
    
    // initial input concentration
    double* phi_in;		//## attribute phi_in 
    

////    Relations and components    ////
public :
    
    // equation var
    DistributedVar* BC0;		//## link BC0 
    DistributedVarExV _BC0;

    // equation var
    DistributedVar* BCL;		//## link BCL 
    DistributedVarExV _BCL;

    // equation var
    DistributedVar* MB;		//## link MB 
    DistributedVarExV _MB;
    
    // independent var
    DistributedVar* phi;		//## link phi 
    DistributedVarExV _phi;
    
    // subset vars
    DistributedVar* phi_BC0;		//## link phi_BC0 
    DistributedVarExV _phi_BC0;
    
    // subset vars
    DistributedVar* phi_BCL;		//## link phi_BCL 
    DistributedVarExV _phi_BCL;
    
    // subset vars
    DistributedVar* phi_MB;		//## link phi_MB 
    DistributedVarExV _phi_MB;
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\TubularReactor.h
*********************************************************************/

