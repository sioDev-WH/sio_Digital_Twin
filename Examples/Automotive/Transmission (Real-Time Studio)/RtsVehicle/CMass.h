#ifndef __CMASS_H
#define __CMASS_H

// Cg_Add
#include "OnUMLDaeEsoImpl.h"
#include "ShiftLogic.h"
#include "RtsOnTransmissionExport.h"

class CRigidConnector;





//{{SCG_HEADER(CMass.h) [0]

//{{SCG_INCLUDE                     
// Include for Template Class should go here.
//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API CMass 
                  :public COnUMLDaeEsoImpl<CMass>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        CRigidConnector* p;     
        CRigidConnector* n;     
        double velocity;     
        double J;     
    public:
        double der_velocity;     
        double old_velocity;     
        double der_old_velocity;     
        Fdouble ad_velocity;     
        Fdouble der_ad_velocity;     
        HRESULT res0(double *res);             
        HRESULT res1(double *res);             
        HRESULT res2(double *res);             
        void init();             
        void clean();             
        void handle_J(const double t, const double* val);             
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
      CMass();
      ~CMass();
        HRESULT ad_res0(Fdouble *res);             
        HRESULT ad_res1(Fdouble *res);             
        HRESULT ad_res2(Fdouble *res);             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










