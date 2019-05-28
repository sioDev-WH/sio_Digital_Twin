/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DemoDrivetrainSubsystem
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrainSubsystem.h
*********************************************************************/


#ifndef DemoDrivetrainSubsystem_H 

#define DemoDrivetrainSubsystem_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "TransmissionControlModels.h"
#include "OnUMLEso.h"
#include "fstream.h"
#include "OnModelBase.h"

//## package Application 

//----------------------------------------------------------------------------
// DemoDrivetrainSubsystem.h                                                                  
//----------------------------------------------------------------------------
class DemoDrivetrain;

#ifdef _OMINSTRUMENT
class OMAnimatedDemoDrivetrainSubsystem;
#endif // _OMINSTRUMENT


//## class DemoDrivetrainSubsystem 
class DemoDrivetrainSubsystem : public IOnModelExecEvents, public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedDemoDrivetrainSubsystem;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation DemoDrivetrainSubsystem() 
    DemoDrivetrainSubsystem();
    
    //## operation ~DemoDrivetrainSubsystem() 
    ~DemoDrivetrainSubsystem();


////    Operations    ////
public :
    
    //## operation AddRef() 
    ULONG STDMETHODCALLTYPE AddRef();
    
    //## operation AfterEvent(double) 
    STDMETHODIMP AfterEvent(double  t);
    
    //## operation BeforeEvent(double) 
    STDMETHODIMP BeforeEvent(double  t);
    
    //## operation GetIDsOfNames(REFIID,LPOLESTR*,UINT,LCID,DISPID*) 
    HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID  riid, LPOLESTR*  rgszNames, UINT  cNames, LCID  lcid, DISPID*  rgDispId);
    
    //## operation GetTypeInfo(UINT,LCID,ITypeInfo**) 
    HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT  iTInfo, LCID  lcid, ITypeInfo**  ppTInfo);
    
    //## operation GetTypeInfoCount(UINT*) 
    HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT*  pctinfo);
    
    //## operation Invoke(DISPID,REFIID,LCID,WORD,DISPPARAMS*,VARIANT*,EXCEPINFO*,UINT*) 
    HRESULT STDMETHODCALLTYPE Invoke(DISPID  dispIdMember, REFIID  riid, LCID  lcid, WORD  wFlags, DISPPARAMS*  pDispParams, VARIANT*  pVarResult, EXCEPINFO*  pExcepInfo, UINT*  puArgErr);
    
    //## operation Load(const BSTR) 
    bool Load(const BSTR  filename);
    
    //## operation QueryInterface(REFIID,void**) 
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID  riid, void**  ppvObject);
    
    //## operation Release() 
    ULONG STDMETHODCALLTYPE Release();
    
    //## operation Save(const BSTR) 
    void Save(const BSTR  filename);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation initSimulation() 
    void initSimulation();
    
    //## operation printData(const double) 
    void printData(const double  t);
    
    //## operation termSimulation() 
    void termSimulation();


////    Additional operations    ////
public :
    
    //## auto_generated 
    void setCar(IIsDaeEsoCImpl*  p_Car);
    
    //## auto_generated 
    void setDC(IIsDaeEsoCImpl*  p_DC);
    
    //## auto_generated 
    void setFC(IIsDaeEsoCImpl*  p_FC);
    
    //## auto_generated 
    void setIOC(IIsDaeEsoCImpl*  p_IOC);
    
    //## auto_generated 
    void setOB(IIsDaeEsoCImpl*  p_OB);
    
    //## auto_generated 
    void setPOC(IIsDaeEsoCImpl*  p_POC);
    
    //## auto_generated 
    void setADC(IIsDaeEsoCImpl*  p_aDC);
    
    //## auto_generated 
    void setAFC(IIsDaeEsoCImpl*  p_aFC);
    
    //## auto_generated 
    void setAIOC(IIsDaeEsoCImpl*  p_aIOC);
    
    //## auto_generated 
    void setAOB(IIsDaeEsoCImpl*  p_aOB);
    
    //## auto_generated 
    void setAPOC(IIsDaeEsoCImpl*  p_aPOC);
    
    //## auto_generated 
    void setGIOC(IIsDaeEsoCImpl*  p_gIOC);
    
    //## auto_generated 
    void setGOB(IIsDaeEsoCImpl*  p_gOB);
    
    //## auto_generated 
    void setGPOC(IIsDaeEsoCImpl*  p_gPOC);
    
    //## auto_generated 
    void setItsEngine(IIsDaeEsoCImpl*  p_itsEngine);
    
    //## auto_generated 
    void setItsGearbox(IIsDaeEsoCImpl*  p_itsGearbox);
    
    //## auto_generated 
    void setItsTC(IIsDaeEsoCImpl*  p_itsTC);
    
    //## auto_generated 
    void setM_pModel(IIsDaeEsoCImpl*  p_m_pModel);
    
    //## auto_generated 
    void setM_pModelExec(IOnModelExec*  p_m_pModelExec);

protected :
    
    //## auto_generated 
    void setM_cRef(long  p_m_cRef);
    
    //## auto_generated 
    void setM_pdw(DWORD  p_m_pdw);

private :
    
    //## auto_generated 
    void setFs(ofstream  p_fs);
    
    //## auto_generated 
    void setNVars(long  p_nVars);
    
    //## auto_generated 
    void setPsaVarVals(SAFEARRAY*  p_psaVarVals);
    
    //## auto_generated 
    void setVarVals(double*  p_varVals);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();



////    Attributes    ////
public :
    
    IIsDaeEsoCImpl* Car;		//## attribute Car 
    
    IIsDaeEsoCImpl* DC;		//## attribute DC 
    
    IIsDaeEsoCImpl* FC;		//## attribute FC 
    
    IIsDaeEsoCImpl* IOC;		//## attribute IOC 
    
    IIsDaeEsoCImpl* OB;		//## attribute OB 
    
    IIsDaeEsoCImpl* POC;		//## attribute POC 
    
    IIsDaeEsoCImpl* aDC;		//## attribute aDC 
    
    IIsDaeEsoCImpl* aFC;		//## attribute aFC 
    
    IIsDaeEsoCImpl* aIOC;		//## attribute aIOC 
    
    IIsDaeEsoCImpl* aOB;		//## attribute aOB 
    
    IIsDaeEsoCImpl* aPOC;		//## attribute aPOC 
    
    ofstream fs;		//## attribute fs 
    
    IIsDaeEsoCImpl* gIOC;		//## attribute gIOC 
    
    IIsDaeEsoCImpl* gOB;		//## attribute gOB 
    
    IIsDaeEsoCImpl* gPOC;		//## attribute gPOC 
    
    IIsDaeEsoCImpl* itsEngine;		//## attribute itsEngine 
    
    IIsDaeEsoCImpl* itsGearbox;		//## attribute itsGearbox 
    
    IIsDaeEsoCImpl* itsTC;		//## attribute itsTC 
    
    long m_cRef;		//## attribute m_cRef 
    
    IIsDaeEsoCImpl* m_pModel;		//## attribute m_pModel 
    
    IOnModelExec* m_pModelExec;		//## attribute m_pModelExec 
    
    DWORD m_pdw;		//## attribute m_pdw 
    
    long nVars;		//## attribute nVars 
    
    SAFEARRAY* psaVarVals;		//## attribute psaVarVals 
    
    double* varVals;		//## attribute varVals 
    

////    Relations and components    ////
public :
    
    DemoDrivetrain* m_pSystemModel;		//## link m_pSystemModel 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedDemoDrivetrainSubsystem : virtual public AOMInstance {

    
    DECLARE_META(DemoDrivetrainSubsystem, OMAnimatedDemoDrivetrainSubsystem)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrainSubsystem.h
*********************************************************************/

