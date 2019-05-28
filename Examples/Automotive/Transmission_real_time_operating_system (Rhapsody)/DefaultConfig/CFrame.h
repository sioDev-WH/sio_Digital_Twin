/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CFrame
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CFrame.h
*********************************************************************/


#ifndef CFrame_H 

#define CFrame_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "StandardModels.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package StandardModels 

//----------------------------------------------------------------------------
// CFrame.h                                                                  
//----------------------------------------------------------------------------
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedCFrame;
#endif // _OMINSTRUMENT


// <CgModel ClassType="1" xmlns="x-schema:\xmldata\ModelDefinition.xml"> 
// <CgAttribute Name="p" sType="3" sSubType="1" Value="0" bSim="True" />
// <CgOperation Name="res0" sType="1" sDiffType="2" />
// </CgModel>
//## class CFrame 
class CFrame : public COnUMLDaeEsoImpl<CFrame> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedCFrame;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation CFrame() 
    CFrame();
    
    //## operation ~CFrame() 
    ~CFrame();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation ad_res0(Fdouble * ) 
    HRESULT ad_res0(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation res0(double * ) 
    HRESULT res0(double * res);

protected :
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
    //## operation InitEsos() 
    HRESULT InitEsos();
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);


////    Additional operations    ////
public :
    
    //## auto_generated 
    CRigidConnector* getP() const;
    
    //## auto_generated 
    void setP(CRigidConnector*  p_CRigidConnector);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Relations and components    ////
private :
    
    CRigidConnector* p;		//## link p 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedCFrame : virtual public AOMInstance {

    
    DECLARE_META(CFrame, OMAnimatedCFrame)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CFrame.h
*********************************************************************/

