/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GasAbsorber
//!	Generated Date	: Sat, 2, Nov 2002  
	File Path	: DefaultComponent\DefaultConfig\GasAbsorber.h
*********************************************************************/


#ifndef GasAbsorber_H 

#define GasAbsorber_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Models.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnUMLDaeEsoImpl.h"
#include "D_Mesh.h"

//## package Models 

//----------------------------------------------------------------------------
// GasAbsorber.h                                                                  
//----------------------------------------------------------------------------

//## class GasAbsorber 
class GasAbsorber : public OMReactive, public COnUMLDaeEsoImpl<GasAbsorber> {


////    Constructors and destructors    ////
public :
    
    //## operation GasAbsorber() 
    GasAbsorber();
    
    //## operation ~GasAbsorber() 
    ~GasAbsorber();


////    Operations    ////
public :
    
    //## operation r_BCG0() 
    HRESULT r_BCG0(long i);
    HRESULT r_BCG0_0();
    HRESULT r_BCG0_1();
    HRESULT r_BCG0_2();
    
    //## operation r_BCLL() 
    HRESULT r_BCLL();
    
    //## operation r_MBG() 
    HRESULT r_MBG(long i);
    HRESULT r_MBG_0();
    HRESULT r_MBG_1();
    HRESULT r_MBG_2();
    
    //## operation r_MBL() 
    HRESULT r_MBL();


    //## operation ad_r_BCG0() 
    HRESULT ad_r_BCG0(long i);
    HRESULT ad_r_BCG0_0();
    HRESULT ad_r_BCG0_1();
    HRESULT ad_r_BCG0_2();
    
    //## operation ad_r_BCLL() 
    HRESULT ad_r_BCLL();
    
    //## operation ad_r_MBG() 
    HRESULT ad_r_MBG(long i);
    HRESULT ad_r_MBG_0();
    HRESULT ad_r_MBG_1();
    HRESULT ad_r_MBG_2();
    
    //## operation ad_r_MBL() 
    HRESULT ad_r_MBL();

////    Additional operations    ////
public :
    

protected:
    //## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    HRESULT InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form);
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalVars(const _TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,const bool) 
    HRESULT InitLocalVars(const _TCHAR*  prefix, VarCont* varC, const bool  bADOnly);
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);


////    Framework operations    ////
protected :
    

////    Attributes    ////
public :
    
    // equations
    DistributedVar BCLL;		//## attribute BCLL 
    DistributedVarEx _BCLL;
    
    // residual for r_MBL
    DistributedVar MBL;		//## attribute MBL 
    DistributedVarEx _MBL;

    DistributionDomain Reverse;		//## attribute Reverse 
    D_Mesh ReverseMesh;		//## attribute ReveseMesh 
    DistributionDomain Forward;		//## attribute Forward 
    
    D_Mesh ForwardMesh;		//## attribute ForwardMesh 
    
    double K3;		//## attribute K3 
    
    double K4;		//## attribute K4 
    
    double K5;		//## attribute K5 
    
    double K6;		//## attribute K6 
    
    double K7;		//## attribute K7 
    

    // gasConc sets the common initialization for all gas concentration (psi) variables
    DistributedVar gasConc;		//## attribute gasConc 

    // subset of psi
    DistributedVar psi_MBL;		//## attribute psi_MBL 
    DistributedVarEx _psi_MBL;
    
    double* psi_in;		//## attribute psi_in 
    
    // variable theta
    DistributedVar theta;		//## attribute theta 
    DistributedVarEx _theta;

    // subset of theta
    DistributedVar theta_BCL;		//## attribute theta_BCL 
    DistributedVarEx _theta_BCL;

    // subset of theta
    DistributedVar theta_MBG;		//## attribute theta_MBG 
    DistributedVarEx _theta_MBG;

    // subset of theta
    DistributedVar theta_MBL;		//## attribute theta_MBL 
    DistributedVarEx _theta_MBL;

    double theta_in;		//## attribute theta_in 
    

////    Relations and components    ////
public :
    
    // equations
    DistributedVar* BCG0;		//## link BCG0 
    DistributedVarExV _BCG0;
    // residual for r_MBG
    DistributedVar* MBG;		//## link MBG 
    DistributedVarExV _MBG;

    // psi variable
    DistributedVar* psi;		//## link psi 
    DistributedVarExV _psi;
    
    // subset of psi for Gas Boundary condition at zeta=0
    DistributedVar* psi_BC0;		//## link psi_BC0 
    DistributedVarExV _psi_BC0;
    
    // subset of psi for Gas Phase Mass Balance equation
    DistributedVar* psi_MB;		//## link psi_MB 
    DistributedVarExV _psi_MB;
    
    double Len;

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GasAbsorber.h
*********************************************************************/

