/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ActuatorClutchConnector
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\ActuatorClutchConnector.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "ActuatorClutchConnector.h"
#include "stdafx.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_ActuatorClutchConnector_ActuatorClutchConnector_SERIALIZE OM_NO_OP


#define TransmissionModels_ActuatorClutchConnector_InitEqnForm_SERIALIZE OM_NO_OP


#define TransmissionModels_ActuatorClutchConnector_InitLocalADEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_ActuatorClutchConnector_InitLocalEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_ActuatorClutchConnector_InitLocalVars_SERIALIZE OM_NO_OP


#define TransmissionModels_ActuatorClutchConnector_Load_SERIALIZE OM_NO_OP


#define TransmissionModels_ActuatorClutchConnector_Save_SERIALIZE OM_NO_OP


#define TransmissionModels_ActuatorClutchConnector_clean_SERIALIZE OM_NO_OP


#define TransmissionModels_ActuatorClutchConnector_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// ActuatorClutchConnector.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class ActuatorClutchConnector 



ActuatorClutchConnector::ActuatorClutchConnector() {
    NOTIFY_CONSTRUCTOR(ActuatorClutchConnector, ActuatorClutchConnector(), 0, TransmissionModels_ActuatorClutchConnector_ActuatorClutchConnector_SERIALIZE);
    //#[ operation ActuatorClutchConnector() 
    init();  
    
    //#]
}

ActuatorClutchConnector::~ActuatorClutchConnector() {
    NOTIFY_DESTRUCTOR(~ActuatorClutchConnector, TRUE);
    //#[ operation ~ActuatorClutchConnector() 
    clean();
    //#]
}

HRESULT ActuatorClutchConnector::GetADResidual(long  iEqn, double  t, Fdouble * residual) {
    //#[ operation GetADResidual(long,double,Fdouble * ) 
    ActuatorClutchConnector* pEso;
    
    if (m_nEsos == 0)
      *residual = AD(pressure);
    else
    {
      pEso = dynamic_cast<ActuatorClutchConnector*> (m_Esos[iEqn]);
      *residual = AD(pressure) - pEso->AD(pressure);
    }
    
    return S_OK;
    //#]
}

HRESULT ActuatorClutchConnector::GetResiduals(long * iEqns, long  nEqn, double  t, double * residuals) {
    //#[ operation GetResiduals(long * ,long,double,double * ) 
    long i;
    ActuatorClutchConnector* pEso;
    
    if (m_nEsos == 0 && nEqn == 1)
    {
      residuals[0] = pressure;
    #if 0
    if (_verbose_print)
    //ATLTRACE("\n ActuatorClutchConnector::GetResiduals:\t%e", pressure);
    #endif
    
    }
    else
    {
      for (i = 0; i < nEqn; i++)
      {
        pEso = dynamic_cast<ActuatorClutchConnector*> (m_Esos[iEqns[i]]);
    
    #if 0
    if (_verbose_print)
    //ATLTRACE("\n ActuatorClutchConnector::GetResiduals[%d]:\t%e\t%e", iEqns[i], pressure, pEso->pressure);
    #endif
    
        residuals[i] = pressure - pEso->pressure;
      }
    }
    
    return S_OK;
    //#]
}

HRESULT ActuatorClutchConnector::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, TransmissionModels_ActuatorClutchConnector_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    long i;
    DESTROY_VECTOR(*form)
    *form = new OnEqnForm[m_nLocalEqns];
    
    for (i = 0; i < m_nLocalEqns; i++) (*form)[i] = continuous;
    
    DESTROY_VECTOR(*diff_form)
    *diff_form = new OnEqnDiffForm[m_nLocalEqns];
    
    for (i = 0; i < m_nLocalEqns; i++) (*diff_form)[i] = automatic;
    
    return S_OK;
    //#]
}

HRESULT ActuatorClutchConnector::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, TransmissionModels_ActuatorClutchConnector_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
    if (m_nEsos == 0 && m_bMasterNode)
      m_nLocalADEqns = 1;
    else
      m_nLocalADEqns = m_nEsos;
    
    return S_OK;
    //#]
}

HRESULT ActuatorClutchConnector::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, TransmissionModels_ActuatorClutchConnector_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
    if (m_nEsos == 0 && m_bMasterNode)
      m_nLocalEqns = 1;
    else
      m_nLocalEqns = m_nEsos;
    
    return S_OK;
    //#]
}

HRESULT ActuatorClutchConnector::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, TransmissionModels_ActuatorClutchConnector_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    ADD_LOCAL_SVAR(pressure)
    for (long i = 0; i < m_nEsos; i++)
     AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
    return S_OK;
    //#]
}

bool ActuatorClutchConnector::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, TransmissionModels_ActuatorClutchConnector_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void ActuatorClutchConnector::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, TransmissionModels_ActuatorClutchConnector_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    //#]
}

void ActuatorClutchConnector::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionModels_ActuatorClutchConnector_clean_SERIALIZE);
    //#[ operation clean() 
    //#]
}

void ActuatorClutchConnector::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionModels_ActuatorClutchConnector_init_SERIALIZE);
    //#[ operation init() 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    pressure = 0.0;
    DER(pressure) = 0.0;
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

VarEx ActuatorClutchConnector::get_pressure() const {
    return _pressure;
}

void ActuatorClutchConnector::set_pressure(VarEx  p__pressure) {
    _pressure = p__pressure;
}

double ActuatorClutchConnector::getPressure() const {
    return pressure;
}

void ActuatorClutchConnector::setPressure(double  p_pressure) {
    pressure = p_pressure;
}



#ifdef _OMINSTRUMENT


void OMAnimatedActuatorClutchConnector::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(ActuatorClutchConnector, TransmissionModels, FALSE, OMAnimatedActuatorClutchConnector)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ActuatorClutchConnector.cpp
*********************************************************************/

