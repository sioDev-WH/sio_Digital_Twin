/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: On3DConn
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\On3DConn.h
*********************************************************************/


#ifndef On3DConn_H 

#define On3DConn_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"
#include "OnConnector_On3DConn.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// On3DConn.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedOn3DConn;
#endif // _OMINSTRUMENT


//## class On3DConn 
class On3DConn : public OnConnector_On3DConn {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedOn3DConn;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation On3DConn() 
    On3DConn();
    
    //## operation ~On3DConn() 
    virtual ~On3DConn();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation clean() 
    void clean();
    
    //## operation get_Fx(const double ) 
    double get_Fx(const double time);
    
    //## operation get_Fz(const double ) 
    double get_Fz(const double time);
    
    //## operation get_My(const double ) 
    double get_My(const double time);
    
    //## operation get_der_Fx(const double ) 
    double get_der_Fx(const double time);
    
    //## operation get_der_Fz(const double ) 
    double get_der_Fz(const double time);
    
    //## operation get_der_My(const double ) 
    double get_der_My(const double time);
    
    //## operation get_der_q(const double ) 
    double get_der_q(const double time);
    
    //## operation get_der_u(const double ) 
    double get_der_u(const double time);
    
    //## operation get_der_w(const double ) 
    double get_der_w(const double time);
    
    //## operation get_q(const double ) 
    double get_q(const double time);
    
    //## operation get_u(const double ) 
    double get_u(const double time);
    
    //## operation get_w(const double ) 
    double get_w(const double time);
    
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
    void setF(double * * p_F);
    
    //## auto_generated 
    void setFx(double  p_Fx);
    
    //## auto_generated 
    void setFz(double  p_Fz);
    
    //## auto_generated 
    void setMy(double  p_My);
    
    //## auto_generated 
    void setV(double * * p_V);
    
    //## auto_generated 
    void set_F(VarEx * * p__F);
    
    //## auto_generated 
    void set_Fx(VarEx p__Fx);
    
    //## auto_generated 
    void set_Fz(VarEx p__Fz);
    
    //## auto_generated 
    void set_My(VarEx p__My);
    
    //## auto_generated 
    void set_V(VarEx * * p__V);
    
    //## auto_generated 
    void set_q(VarEx p__q);
    
    //## auto_generated 
    void set_u(VarEx p__u);
    
    //## auto_generated 
    void set_w(VarEx p__w);
    
    //## auto_generated 
    void setIdx_var_Fx(long  p_idx_var_Fx);
    
    //## auto_generated 
    void setIdx_var_Fz(long  p_idx_var_Fz);
    
    //## auto_generated 
    void setIdx_var_My(long  p_idx_var_My);
    
    //## auto_generated 
    void setIdx_var_q(long  p_idx_var_q);
    
    //## auto_generated 
    void setIdx_var_u(long  p_idx_var_u);
    
    //## auto_generated 
    void setIdx_var_w(long  p_idx_var_w);
    
    //## auto_generated 
    void setM_TypedEsos(On3DConn * * p_m_TypedEsos);
    
    //## auto_generated 
    void setQ(double  p_q);
    
    //## auto_generated 
    void setTmpVal(double  p_tmpVal);
    
    //## auto_generated 
    void setU(double  p_u);
    
    //## auto_generated 
    void setW(double  p_w);


////    Attributes    ////
public :
    
    // forces
    double Fx;		//## attribute Fx 
    
    double Fz;		//## attribute Fz 
    
    double My;		//## attribute My 
    
    // extensions for variables
    VarEx _Fx;		//## attribute _Fx 
    
    VarEx _Fz;		//## attribute _Fz 
    
    VarEx _My;		//## attribute _My 
    
    VarEx _q;		//## attribute _q 
    
    VarEx _u;		//## attribute _u 
    
    VarEx _w;		//## attribute _w 
    
    // variable index constants
    long idx_var_Fx;		//## attribute idx_var_Fx 
    
    long idx_var_Fz;		//## attribute idx_var_Fz 
    
    long idx_var_My;		//## attribute idx_var_My 
    
    long idx_var_q;		//## attribute idx_var_q 
    
    long idx_var_u;		//## attribute idx_var_u 
    
    long idx_var_w;		//## attribute idx_var_w 
    
    // rotational velocity      [Body Frame]
    double q;		//## attribute q 
    
    // translational velocity   [Body Frame]
    double u;		//## attribute u 
    
    // translational velocity   [Body Frame]
    double w;		//## attribute w 
    
protected :
    
    double * * F;		//## attribute F 
    
    double * * V;		//## attribute V 
    
    VarEx * * _F;		//## attribute _F 
    
    VarEx * * _V;		//## attribute _V 
    
    // The following vectors are for the efficient implementation of 
    // GetResiduals() and GetADResidual() 
    On3DConn * * m_TypedEsos;		//## attribute m_TypedEsos 
    
private :
    
    double tmpVal;		//## attribute tmpVal 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedOn3DConn : virtual public AOMInstance {

    
    DECLARE_META(On3DConn, OMAnimatedOn3DConn)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\On3DConn.h
*********************************************************************/

