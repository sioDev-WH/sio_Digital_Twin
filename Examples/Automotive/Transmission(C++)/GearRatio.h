// GearRatio.h : Declaration of the CGearRatio

#ifndef __GearRatio_H_
#define __GearRatio_H_

#include "resource.h"       // main symbols

#include "OnUMLDaeEsoImpl.h"

class CRigidConnector;

/////////////////////////////////////////////////////////////////////////////
// CGearRatio
class CGearRatio : public COnUMLDaeEsoImpl<CGearRatio>  
{
public:
	CGearRatio();
	virtual ~CGearRatio();

public:

  double R;              // <SimRPar>


  CRigidConnector* p;       // <SimConnector>
  CRigidConnector* n;       // <SimConnector>

public:
  HRESULT InitEsos();

  HRESULT InitLocalEqns();
  HRESULT InitLocalADEqns();
  HRESULT InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form);

  HRESULT InitLocalRPars(const _TCHAR* prefix, double*** pars, _TCHAR*** Names, long* nPars, long* dPars);
  HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);

  HRESULT res0(double* res);
  HRESULT res1(double* res);

  HRESULT ad_res0(Fdouble* res);
  HRESULT ad_res1(Fdouble* res);

};

#endif //__GearRatio_H_
