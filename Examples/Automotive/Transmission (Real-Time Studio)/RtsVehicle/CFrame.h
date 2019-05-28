#ifndef __CFRAME_H
#define __CFRAME_H

// Cg_Add
#include "OnUMLDaeEsoImpl.h"
class CRigidConnector;
#include "shiftLogic.h"
#include "RtsOnTransmissionExport.h"



//{{SCG_HEADER(CFrame.h) [0]

//{{SCG_INCLUDE                     
//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API CFrame 
                  :public COnUMLDaeEsoImpl<CFrame>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    private:
        CRigidConnector* p;     
    public:
        HRESULT res0(double *res);             
        void clean();             
        void init();             
        void Save(FILE* fs) { }
        bool Load(FILE* fs) { return true; }
    protected:


        HRESULT InitEsos();             
        HRESULT InitLocalEqns();             
        HRESULT InitLocalADEqns();             
        HRESULT InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form);             
        HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
    public:
      CFrame();
      ~CFrame();
        HRESULT ad_res0(Fdouble *res);             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










