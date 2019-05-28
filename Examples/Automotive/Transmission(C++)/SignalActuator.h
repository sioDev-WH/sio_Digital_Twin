// SignalActuator.h: interface for the CSignalActuator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SignalActuator_H__89961687_FCF3_4038_B9E5_BEFC4B96DC74__INCLUDED_)
#define AFX_SignalActuator_H__89961687_FCF3_4038_B9E5_BEFC4B96DC74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OnUMLDaeEsoImpl.h"

class CRigidConnector;

class CSignalActuator : public COnUMLDaeEsoImpl<CSignalActuator>   
{
public:
	CSignalActuator();
	virtual ~CSignalActuator();

public:

  // code generated initialization methods
  HRESULT InitLocalEqns();
  HRESULT InitLocalADEqns();
  HRESULT InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form);

  HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
  HRESULT InitEsos();

  // residuals
  HRESULT res0(double* res); // <SimContinuousResidual>
  HRESULT res1(double* res); // <SimContinuousResidual>

  HRESULT ad_res0(Fdouble* res); // <SimContinuousResidual>
  HRESULT ad_res1(Fdouble* res); // <SimContinuousResidual>
  HRESULT ad_res2(Fdouble* res); // <SimContinuousResidual>

  double direction;
  CRigidConnector* n;        // <SimConnector>

protected:


  double LocalTime;          // <SimVar>
  double der_LocalTime;      // <der_SimVar>
  double old_LocalTime;      // <old_SimVar>
  double der_old_LocalTime;
  Fdouble ad_LocalTime;      // <ad_SimVar>
  Fdouble der_ad_LocalTime;  // <der_ad_SimVar>


};

#endif // !defined(AFX_SignalActuator_H__89961687_FCF3_4038_B9E5_BEFC4B96DC74__INCLUDED_)
