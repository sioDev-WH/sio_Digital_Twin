// RigidConnector.h: interface for the CRigidConnector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RigidConnector_H__D13616CC_CF36_412E_AC14_6D8D84159599__INCLUDED_)
#define AFX_RigidConnector_H__D13616CC_CF36_412E_AC14_6D8D84159599__INCLUDED_

#include "OnUMLConnectorImpl.h"
#include "RtsOnTransmissionExport.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class RTSONTRANSMISSION_API CRigidConnector : public COnUMLConnectorImpl<CRigidConnector>
{
public:
	CRigidConnector();
	virtual ~CRigidConnector();

  double torque; // torque
  double acceleration; // rotational acceleration
  
  // derivatives
  double der_torque;
  double der_acceleration;

  // last values (for transitions)
  double old_torque;
  double old_acceleration;

  double der_old_torque;
  double der_old_acceleration;

  // for automatic differentiation
  Fdouble ad_torque;
  Fdouble ad_acceleration;

  Fdouble der_ad_torque;
  Fdouble der_ad_acceleration;

  void Save(FILE* fs) { }
  bool Load(FILE* fs) { return true; }

  HRESULT InitLocalEqns();
  HRESULT InitLocalADEqns();
  HRESULT InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form);

  HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

  HRESULT GetResiduals(
    long* iEqn, 
    long nEqn, 
    double t, 
    double* residuals);

  HRESULT GetADResidual(
    long iEqn, 
    double t, 
    Fdouble* residual);

  HRESULT GetJacobianValues(
    long* iJac, 
    long nJac, 
    double t, 
    double* jacobians);

  HRESULT GetDiffJacobianValues(
    long* iJac, 
    long nJac, 
    double t, 
    double* jacobians);


};

#endif // !defined(AFX_RigidConnector_H__D13616CC_CF36_412E_AC14_6D8D84159599__INCLUDED_)
