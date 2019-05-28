#ifndef __CSPRING_H
#define __CSPRING_H


// Cg_Add
#include "OnUMLDaeEsoImpl.h"
#include "ShiftLogic.h"
#include "RtsOnTransmissionExport.h"

class CRigidConnector;


//{{SCG_HEADER(CSpring.h) [0]

//{{SCG_INCLUDE                     
//}}SCG_INCLUDE

//{{SCG_FORWARD                    
//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API CSpring 
                  :public COnUMLDaeEsoImpl<CSpring>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        double Ks;     
        CRigidConnector* p;     
        CRigidConnector* n;     
        double ddTorque;     
        double dTorque;     
    public:
        double der_ddTorque;     
        double old_ddTorque;     
        double der_old_ddTorque;     
        Fdouble ad_ddTorque;     
        Fdouble der_ad_ddTorque;     
        double der_dTorque;     
        double old_dTorque;     
        double der_old_dTorque;     
        Fdouble ad_dTorque;     
        Fdouble der_ad_dTorque;     
        HRESULT res2(double *res);             
        HRESULT res3(double *res);             
        void init();             
        void clean();             
        HRESULT res0(double *res);             
        HRESULT res1(double *res);             
        void handle_Ks(const double t, const double* val);             

        void Save(FILE* fs) { }
        bool Load(FILE* fs) { return true; }
    
    protected:
        HRESULT InitEsos();             
        HRESULT InitLocalEqns();             
        HRESULT InitLocalADEqns();             
        HRESULT InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form);             
        HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
        HRESULT InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars);             
    public:
      CSpring();
      ~CSpring();
        HRESULT ad_res2(Fdouble *res);             
        HRESULT ad_res3(Fdouble *res);             
        HRESULT ad_res0(Fdouble *res);             
        HRESULT ad_res1(Fdouble *res);             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










