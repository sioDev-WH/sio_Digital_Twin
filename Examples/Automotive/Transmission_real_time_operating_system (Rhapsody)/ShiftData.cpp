/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ShiftData
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\ShiftData.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "ShiftData.h"
#include "Clutch_Schedule.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package TransmissionControlModels 


//#[ ignore 
#define TransmissionControlModels_ShiftData_ShiftData_SERIALIZE OM_NO_OP


#define TransmissionControlModels_ShiftData_clean_SERIALIZE OM_NO_OP


#define TransmissionControlModels_ShiftData_getDownShiftThreshold_SERIALIZE OM_NO_OP


#define TransmissionControlModels_ShiftData_getUpShiftThreshold_SERIALIZE OM_NO_OP


#define TransmissionControlModels_ShiftData_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// ShiftData.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionControlModels)
//## class ShiftData 



ShiftData::ShiftData(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(ShiftData, ShiftData(), 0, TransmissionControlModels_ShiftData_ShiftData_SERIALIZE);
    setThread(p_thread, FALSE);
    clutchSchedule = NULL;
    //#[ operation ShiftData() 
    m_pOnEnv = NULL;
    //#]
}

ShiftData::~ShiftData() {
    NOTIFY_DESTRUCTOR(~ShiftData, TRUE);
    //#[ operation ~ShiftData() 
    clean();
    //#]
    cleanUpRelations();
}

void ShiftData::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionControlModels_ShiftData_clean_SERIALIZE);
    //#[ operation clean() 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    
      if (m_pOnEnv)
      {
        m_pOnEnv->Release();
        m_pOnEnv = NULL;
      }
      
      if(clutchSchedule){
        clutchSchedule->clean();
      
      delete[] clutchSchedule;
    }
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

void ShiftData::getDownShiftThreshold(const double throttle, const long gear, double * threshold) {
    NOTIFY_OPERATION(getDownShiftThreshold, getDownShiftThreshold(const double ,const long ,double * ), 0, TransmissionControlModels_ShiftData_getDownShiftThreshold_SERIALIZE);
    //#[ operation getDownShiftThreshold(const double ,const long ,double * ) 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    downShiftTable.interpolate_2D(throttle,(double)gear,threshold);
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

void ShiftData::getUpShiftThreshold(const double throttle, const long gear, double * threshold) {
    NOTIFY_OPERATION(getUpShiftThreshold, getUpShiftThreshold(const double ,const long ,double * ), 0, TransmissionControlModels_ShiftData_getUpShiftThreshold_SERIALIZE);
    //#[ operation getUpShiftThreshold(const double ,const long ,double * ) 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    upShiftTable.interpolate_2D(throttle,(double)gear,threshold);
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

void ShiftData::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionControlModels_ShiftData_init_SERIALIZE);
    //#[ operation init() 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    
    
      int i,j;
      long nGear, nThrottle;
      double *Throttle,*Gear;
      double **vehicleSpeedThreshold;
    
      clutchSchedule = new Clutch_Schedule();
      clutchSchedule->init();
    
      HRESULT hr = S_OK;
      BSTR path = NULL;
      CComBSTR filename;
      USES_CONVERSION;
    
      if (!m_pOnEnv)
        hr = CoCreateInstance(CLSID_OnEnv, NULL, CLSCTX_INPROC_SERVER, IID_IOnEnv, (void**) &m_pOnEnv);
    
      if (SUCCEEDED(hr))
        hr = m_pOnEnv->get_DataPath(&path);
    
      if (SUCCEEDED(hr))
      {
        filename.Attach(path);
        filename.Append(L"ShiftData.txt");
    
        ifstream eMap(W2CA(filename.m_str),ios::in|ios::nocreate);
        
        // Shift Data header (same number of entries for up shift and down shift data)
        eMap >> nThrottle;
        eMap >> nGear;
        
        Throttle=new double [nThrottle];
        Gear=new double [nGear];
        vehicleSpeedThreshold=new double*[nThrottle];
        
        // Up Shift Data
        for(i=0;i<nThrottle;i++)
          vehicleSpeedThreshold[i] = new double[nGear];
        
        for(i=0;i<nThrottle;i++)
          eMap >> Throttle[i];
        
        for(i=0;i<nGear;i++)
          eMap >> Gear[i];
        
        for (i=0;i<nThrottle;i++) 
          for (j=0;j<nGear;j++)
            eMap >> vehicleSpeedThreshold[i][j];
    
        upShiftTable.init_2D(nThrottle, nGear, Throttle,  Gear,  (const double**)vehicleSpeedThreshold);
        
        // Down Shift Data
        for(i=0;i<nThrottle;i++)
          vehicleSpeedThreshold[i] = new double[nGear];
        for(i=0;i<nThrottle;i++)
          eMap >> Throttle[i];
        for(i=0;i<nGear;i++)
          eMap >> Gear[i];
        for (i=0;i<nThrottle;i++) 
          for (j=0;j<nGear;j++)
            eMap >> vehicleSpeedThreshold[i][j];
          
        downShiftTable.init_2D(nThrottle, nGear, Throttle,  Gear,  (const double**) vehicleSpeedThreshold);
        
        eMap.close();
        delete Throttle;
        delete Gear;
        for(i=0;i<nThrottle;i++)
          delete vehicleSpeedThreshold[i];
    
        delete vehicleSpeedThreshold;
      }
    
      _ASSERTE(SUCCEEDED(hr));
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

IOnEnv* ShiftData::getM_pOnEnv() const {
    return m_pOnEnv;
}

void ShiftData::setM_pOnEnv(IOnEnv*  p_m_pOnEnv) {
    m_pOnEnv = p_m_pOnEnv;
}

Clutch_Schedule* ShiftData::getClutchSchedule() const {
    return clutchSchedule;
}

void ShiftData::setClutchSchedule(Clutch_Schedule*  p_Clutch_Schedule) {
    clutchSchedule = p_Clutch_Schedule;
    if(p_Clutch_Schedule != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("clutchSchedule", p_Clutch_Schedule, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("clutchSchedule");
        }
}

LookupTable* ShiftData::getDownShiftTable() const {
    return (LookupTable*) &downShiftTable;
}

LookupTable* ShiftData::getUpShiftTable() const {
    return (LookupTable*) &upShiftTable;
}

void ShiftData::cleanUpRelations() {
    if(clutchSchedule != NULL)
        {
            NOTIFY_RELATION_CLEARED("clutchSchedule");
            clutchSchedule = NULL;
        }
}

OMBoolean ShiftData::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedShiftData::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedShiftData::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("upShiftTable", TRUE, TRUE);
    if((LookupTable*) &myReal->upShiftTable)
        aomsRelations->ADD_ITEM((LookupTable*) &myReal->upShiftTable);
    aomsRelations->addRelation("downShiftTable", TRUE, TRUE);
    if((LookupTable*) &myReal->downShiftTable)
        aomsRelations->ADD_ITEM((LookupTable*) &myReal->downShiftTable);
    aomsRelations->addRelation("clutchSchedule", FALSE, TRUE);
    if(myReal->clutchSchedule)
        aomsRelations->ADD_ITEM(myReal->clutchSchedule);
}

IMPLEMENT_REACTIVE_META(ShiftData, TransmissionControlModels, FALSE, OMAnimatedShiftData)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ShiftData.cpp
*********************************************************************/

