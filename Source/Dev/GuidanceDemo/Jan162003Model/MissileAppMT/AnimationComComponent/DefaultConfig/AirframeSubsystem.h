/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirframeSubsystem
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AirframeSubsystem.h
*********************************************************************/


#ifndef AirframeSubsystem_H 

#define AirframeSubsystem_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "Application.h"
#include "OnUMLEso.h"
#include "fstream.h"
#include "OnModelBase.h"

//## package Application 

//----------------------------------------------------------------------------
// AirframeSubsystem.h                                                                  
//----------------------------------------------------------------------------
class AirFrame;

#ifdef _OMINSTRUMENT
class OMAnimatedAirframeSubsystem;
#endif // _OMINSTRUMENT


//## class AirframeSubsystem 
class AirframeSubsystem : public IOnModelExecEvents, public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedAirframeSubsystem;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation AirframeSubsystem() 
    AirframeSubsystem();
    
    //## operation ~AirframeSubsystem() 
    ~AirframeSubsystem();


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
    
    //## operation handle_tick(const double) 
    HRESULT handle_tick(const double  t);
    
    //## operation init() 
    void init();
    
    //## operation initSimulation() 
    void initSimulation();
    
    //## operation printData(const double) 
    void printData(const double  t);
    
    //## operation termSimulation() 
    void termSimulation();


////    Additional operations    ////
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
protected :
    
    ofstream fs;		//## attribute fs 
    
    long m_cRef;		//## attribute m_cRef 
    
    DWORD m_pdw;		//## attribute m_pdw 
    
    long nVars;		//## attribute nVars 
    
    SAFEARRAY* psaVarVals;		//## attribute psaVarVals 
    
    double* varVals;		//## attribute varVals 
    

////    Relations and components    ////
public :
    
    IIsDaeEsoCImpl* itsAeroDynamics;		//## link itsAeroDynamics 
    
    
    IIsDaeEsoCImpl* itsBodyDynamics;		//## link itsBodyDynamics 
    
    
    IIsDaeEsoCImpl* itsFinDynamics;		//## link itsFinDynamics 
    
    
    IIsDaeEsoCImpl* m_pModel;		//## link m_pModel 
    
    
    IOnModelExec* m_pModelExec;		//## link m_pModelExec 
    
    
    AirFrame* m_pSystemModel;		//## link m_pSystemModel 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedAirframeSubsystem : virtual public AOMInstance {

    
    DECLARE_META(AirframeSubsystem, OMAnimatedAirframeSubsystem)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AirframeSubsystem.h
*********************************************************************/

