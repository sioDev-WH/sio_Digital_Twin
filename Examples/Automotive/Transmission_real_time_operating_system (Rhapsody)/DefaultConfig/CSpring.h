/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CSpring
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CSpring.h
*********************************************************************/


#ifndef CSpring_H 

#define CSpring_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "StandardModels.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package StandardModels 

//----------------------------------------------------------------------------
// CSpring.h                                                                  
//----------------------------------------------------------------------------
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedCSpring;
#endif // _OMINSTRUMENT


// <CgModel ClassType="1" xmlns="x-schema:\xmldata\ModelDefinition.xml"> 
// <CgAttribute Name="Ks" sType="2" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="p" sType="3" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="n" sType="3" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="ddTorque" sType="1" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="dTorque" sType="1" sSubType="1" Value="0" bSim="True" />
// <CgOperation Name="res2" sType="1" sDiffType="2" />
// <CgOperation Name="res3" sType="1" sDiffType="2" />
// <CgOperation Name="res0" sType="1" sDiffType="2" />
// <CgOperation Name="res1" sType="1" sDiffType="2" />
// </CgModel>
// 
//## class CSpring 
class CSpring : public COnUMLDaeEsoImpl<CSpring> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedCSpring;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation CSpring() 
    CSpring();
    
    //## operation ~CSpring() 
    ~CSpring();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation ad_res0(Fdouble * ) 
    HRESULT ad_res0(Fdouble * res);
    
    //## operation ad_res1(Fdouble * ) 
    HRESULT ad_res1(Fdouble * res);
    
    //## operation ad_res2(Fdouble * ) 
    HRESULT ad_res2(Fdouble * res);
    
    //## operation ad_res3(Fdouble * ) 
    HRESULT ad_res3(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_Ks(const double ,const double * ) 
    void handle_Ks(const double t, const double * val);
    
    //## operation init() 
    void init();
    
    //## operation res0(double * ) 
    HRESULT res0(double * res);
    
    //## operation res1(double * ) 
    HRESULT res1(double * res);
    
    //## operation res2(double * ) 
    HRESULT res2(double * res);
    
    //## operation res3(double * ) 
    HRESULT res3(double * res);

protected :
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
    //## operation InitEsos() 
    HRESULT InitEsos();
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getKs() const;
    
    //## auto_generated 
    void setKs(double  p_Ks);
    
    //## auto_generated 
    double getDTorque() const;
    
    //## auto_generated 
    void setDTorque(double  p_dTorque);
    
    //## auto_generated 
    double getDdTorque() const;
    
    //## auto_generated 
    void setDdTorque(double  p_ddTorque);
    
    //## auto_generated 
    CRigidConnector* getN() const;
    
    //## auto_generated 
    void setN(CRigidConnector*  p_CRigidConnector);
    
    //## auto_generated 
    CRigidConnector* getP() const;
    
    //## auto_generated 
    void setP(CRigidConnector*  p_CRigidConnector);

protected :
    
    //## auto_generated 
    VarEx get_dTorque() const;
    
    //## auto_generated 
    void set_dTorque(VarEx  p__dTorque);
    
    //## auto_generated 
    VarEx get_ddTorque() const;
    
    //## auto_generated 
    void set_ddTorque(VarEx  p__ddTorque);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double Ks;		//## attribute Ks 
    
    double dTorque;		//## attribute dTorque 
    
    double ddTorque;		//## attribute ddTorque 
    
protected :
    
    VarEx _dTorque;		//## attribute _dTorque 
    
    VarEx _ddTorque;		//## attribute _ddTorque 
    

////    Relations and components    ////
public :
    
    CRigidConnector* n;		//## link n 
    
    
    CRigidConnector* p;		//## link p 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedCSpring : virtual public AOMInstance {

    
    DECLARE_META(CSpring, OMAnimatedCSpring)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CSpring.h
*********************************************************************/

