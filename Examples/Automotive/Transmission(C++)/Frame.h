// Frame.h: interface for the CFrame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Frame_H__12F339C1_EB4F_461B_8CD5_BE16379E75B5__INCLUDED_)
#define AFX_Frame_H__12F339C1_EB4F_461B_8CD5_BE16379E75B5__INCLUDED_

#include "OnUMLDaeEsoImpl.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRigidConnector;

class CFrame : public COnUMLDaeEsoImpl<CFrame>  
{
public:
	CFrame();
	virtual ~CFrame();

  HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
  HRESULT InitLocalEqns();
  HRESULT InitLocalADEqns();
  HRESULT InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form);

  HRESULT InitEsos();

  // residuals
  HRESULT res0(double* res); // <SimContinuousResidual>

  HRESULT ad_res0(Fdouble* res); // <SimContinuousResidual>

public:

  CRigidConnector* n;  // <SimConnector>
};

#endif // !defined(AFX_Frame_H__12F339C1_EB4F_461B_8CD5_BE16379E75B5__INCLUDED_)
