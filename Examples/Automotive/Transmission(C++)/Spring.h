// Spring.h: interface for the CSpring class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Spring_H__E1F0DAF3_17D1_40E7_9AFB_28578C037CE2__INCLUDED_)
#define AFX_Spring_H__E1F0DAF3_17D1_40E7_9AFB_28578C037CE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OnUMLDaeEsoImpl.h"
#include "CommonMacros.h"

class CRigidConnector;


class CSpring : public COnUMLDaeEsoImpl<CSpring>  
{
public:
	CSpring();
	virtual ~CSpring();

public:

  // code generated initialization methods
  HRESULT InitLocalEqns();
  HRESULT InitLocalADEqns();
  HRESULT InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form);

  HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
  HRESULT InitLocalRPars(const _TCHAR* prefix, double*** pars, _TCHAR*** Names, long* nPars, long* dPars);
  HRESULT InitEsos();

  // residuals
  HRESULT res0(double* res); // <SimContinuousResidual>
  HRESULT res1(double* res); // <SimContinuousResidual>
  HRESULT res2(double* res); // <SimContinuousResidual>
  HRESULT res3(double* res);

  HRESULT ad_res0(Fdouble* res); // <SimContinuousResidual>
  HRESULT ad_res1(Fdouble* res); // <SimContinuousResidual>
  HRESULT ad_res2(Fdouble* res); // <SimContinuousResidual>
  HRESULT ad_res3(Fdouble* res);

public:
  // parameter
  double Ks;                            // <SimRPar>
  
  // variable
  double dTs;
  double ddTs;

  define_var(dTs)
  define_var(ddTs)

  // connector
  CRigidConnector* p;  // <SimConnector>
  CRigidConnector* n;  // <SimConnector>
};

#endif // !defined(AFX_Spring_H__E1F0DAF3_17D1_40E7_9AFB_28578C037CE2__INCLUDED_)
