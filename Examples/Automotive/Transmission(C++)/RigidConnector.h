// RigidConnector.h: interface for the CRigidConnector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RigidConnector_H__D13616CC_CF36_412E_AC14_6D8D84159599__INCLUDED_)
#define AFX_RigidConnector_H__D13616CC_CF36_412E_AC14_6D8D84159599__INCLUDED_

#include "OnUMLConnectorImpl.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRigidConnector : public COnUMLConnectorImpl<CRigidConnector>
{
public:
	CRigidConnector();
	virtual ~CRigidConnector();

  double T; // torque
  double A; // rotational acceleration
  
  // derivatives
  double der_T;
  double der_A;

  // last values (for transitions)
  double old_T;
  double old_A;

  double der_old_T;
  double der_old_A;

  // for automatic differentiation
  Fdouble ad_T;
  Fdouble ad_A;

  Fdouble der_ad_T;
  Fdouble der_ad_A;

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
