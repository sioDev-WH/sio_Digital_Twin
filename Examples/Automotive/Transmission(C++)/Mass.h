// Mass.h : Declaration of the CMass

#ifndef __Mass_H_
#define __Mass_H_

#include "resource.h"       // main symbols

#include "OnUMLDaeEsoImpl.h"

class CRigidConnector;

/////////////////////////////////////////////////////////////////////////////
// CMass
class CMass : public COnUMLDaeEsoImpl<CMass>  
{
public:
	CMass();
	virtual ~CMass();

public:

  double J;              // <SimRPar>

  double W;                 // <SimVar>
  double der_W;             // <der_SimVar>
  Fdouble ad_W;
  Fdouble der_ad_W;
  double old_W;
  double der_old_W;

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
  HRESULT res2(double* res);

  HRESULT ad_res0(Fdouble* res);
  HRESULT ad_res1(Fdouble* res);
  HRESULT ad_res2(Fdouble* res);

};

#endif //__Mass_H_
