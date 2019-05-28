#ifndef __ACTUATORCLUTCHCONNECTOR_H
#define __ACTUATORCLUTCHCONNECTOR_H

//{{SCG_HEADER(ActuatorClutchConnector.h) [0]

//{{SCG_INCLUDE                     
#include "OnUMLConnectorImpl.h"
#include "RtsOnTransmissionExport.h"

//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API ActuatorClutchConnector  : public COnUMLConnectorImpl<ActuatorClutchConnector>
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        double pressure; 
        double der_pressure;
        double old_pressure;
        double der_old_pressure;
        Fdouble ad_pressure;
        Fdouble der_ad_pressure;
    public:
        void init();             
    //}}SCG_CLASS_PROPS



  ActuatorClutchConnector();
  ~ActuatorClutchConnector();

  void Save(FILE* fs) { }
  bool Load(FILE* fs) { return true; }

  HRESULT InitLocalEqns();
  HRESULT InitLocalADEqns();
  HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
  HRESULT GetResiduals(long* iEqns, long nEqn, double t, double* residuals);
  HRESULT GetADResidual(long iEqn, double t, Fdouble* residual);
  HRESULT GetJacobianValues(long* iJac, long nJac, double t, double* jacobians);
  HRESULT GetDiffJacobianValues(long* iJac, long nJac, double t, double* jacobians);
  HRESULT InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form);


};

//}}SCG_CLASS

//}}SCG_HEADER      
#endif










