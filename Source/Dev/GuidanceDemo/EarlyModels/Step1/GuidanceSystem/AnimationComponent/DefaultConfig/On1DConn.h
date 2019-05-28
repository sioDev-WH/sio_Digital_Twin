/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: On1DConn
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\On1DConn.h
*********************************************************************/


#ifndef On1DConn_H 

#define On1DConn_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"
#include "OnConnector_On1DConn.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// On1DConn.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedOn1DConn;
#endif // _OMINSTRUMENT


//## class On1DConn 
class On1DConn : public OnConnector_On1DConn {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedOn1DConn;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation On1DConn() 
    On1DConn();
    
    //## operation ~On1DConn() 
    virtual ~On1DConn();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();

protected :
    
    //## operation GetADResidual(long,double,Fdouble * ) 
    HRESULT GetADResidual(long  iEqn, double  t, Fdouble * residual);
    
    //## operation GetResiduals(long * ,long,double,double * ) 
    HRESULT GetResiduals(long * iEqns, long  nEqn, double  t, double * residuals);
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);


////    Additional operations    ////
public :
    
    //## auto_generated 
    void set_pos(VarEx p__pos);
    
    //## auto_generated 
    void setM_TypedEsos(On1DConn * * p_m_TypedEsos);
    
    //## auto_generated 
    void setPos(double  p_pos);


////    Attributes    ////
public :
    
    VarEx _pos;		//## attribute _pos 
    
    // position
    double pos;		//## attribute pos 
    
protected :
    
    On1DConn * * m_TypedEsos;		//## attribute m_TypedEsos 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedOn1DConn : virtual public AOMInstance {

    
    DECLARE_META(On1DConn, OMAnimatedOn1DConn)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\On1DConn.h
*********************************************************************/

