/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Clutch_Schedule
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Clutch_Schedule.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "Clutch_Schedule.h"
#include "GearInfo.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package TransmissionControlModels 


//#[ ignore 
#define TransmissionControlModels_Clutch_Schedule_Clutch_Schedule_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Clutch_Schedule_clean_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Clutch_Schedule_init_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Clutch_Schedule_update_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Clutch_Schedule_updateDisengage_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Clutch_Schedule_updateEngage_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Clutch_Schedule.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionControlModels)
//## class Clutch_Schedule 



Clutch_Schedule::Clutch_Schedule() : m_pOnEnv(NULL) {
    NOTIFY_CONSTRUCTOR(Clutch_Schedule, Clutch_Schedule(), 0, TransmissionControlModels_Clutch_Schedule_Clutch_Schedule_SERIALIZE);
    Gears = NULL;
    //#[ operation Clutch_Schedule() 
    m_pOnEnv = NULL;
    //#]
}

Clutch_Schedule::~Clutch_Schedule() {
    NOTIFY_DESTRUCTOR(~Clutch_Schedule, TRUE);
    cleanUpRelations();
}

void Clutch_Schedule::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionControlModels_Clutch_Schedule_clean_SERIALIZE);
    //#[ operation clean() 
    long i;
    
    if (m_pOnEnv)
    {
      m_pOnEnv->Release();
      m_pOnEnv = NULL;
    }
    
    if (Gears)
    {
      for(i=0;i<nGears;i++)
        Gears[i].clean();
    
      delete[] Gears;
      Gears = NULL;
    }
    
    if (engageList)
    { 
      delete[] engageList;
      engageList = NULL;
    }
    
    if (disengageList) 
    {
      delete[] disengageList;
      disengageList = NULL;
    }
    
    //#]
}

void Clutch_Schedule::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionControlModels_Clutch_Schedule_init_SERIALIZE);
    //#[ operation init() 
      int i,j;
    
      long GearID;
      long nGearClutches;
      long* GearClutches;
      
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
        filename.Append(L"ClutchScheduleData.txt");
    
        ifstream eMap(W2CA(filename.m_str),ios::in|ios::nocreate);
    
        // Clutch schedule Data header
        eMap >> nGears;
        eMap >> nClutches;
    
        Gears=new GearInfo[nGears];
        engageList = new bool[nClutches];
        disengageList = new bool[nClutches];
    
        for(i=0;i<nGears;i++){
          eMap >> GearID;
          eMap >> nGearClutches;
          GearClutches = (long*) new long[nGearClutches];
          for(j=0;j<nGearClutches;j++)
             eMap >> GearClutches[j];
          Gears[i].init(GearID,nClutches, nGearClutches,GearClutches);
          delete GearClutches;
        }
    
        eMap.close();
      }
      
      _ASSERTE(SUCCEEDED(hr));
    
    //#]
}

void Clutch_Schedule::update(const long CurrentGear, const long NextGear) {
    NOTIFY_OPERATION(update, update(const long ,const long ), 0, TransmissionControlModels_Clutch_Schedule_update_SERIALIZE);
    //#[ operation update(const long ,const long ) 
    bool *CurrentState = NULL;
    bool *NextState = NULL;
    long i;
    
    // CurrentGear and NextGear are Gear IDs, not Gear Indices
    for (i = 0; i < nGears; i++)
      if (CurrentGear == Gears[i].ID)
      {
        CurrentState= Gears[i].ClutchState;    
        break;
      }
    
    for (i = 0; i < nGears; i++)
      if (NextGear == Gears[i].ID)
      {
        NextState= Gears[i].ClutchState;
        break;
      }
    
    _ASSERTE(CurrentState && NextState);
    
    for (i = 0; i < nClutches; i++)
    {
      disengageList[i] = false;
      engageList[i] = false;
    }
    
    for(i=0;i<nClutches;i++){
      if(NextState[i] != CurrentState[i]){
          if(CurrentState[i]){
                  disengageList[i] = true;
                  engageList[i] = false;
          }
          else{
                  disengageList[i] = false; 
                  engageList[i] = true; 
          }
      }
    }
    
    //#]
}

void Clutch_Schedule::updateDisengage(const long  CurrentGear, const long  TargetGear) {
    NOTIFY_OPERATION(updateDisengage, updateDisengage(const long,const long), 0, TransmissionControlModels_Clutch_Schedule_updateDisengage_SERIALIZE);
    //#[ operation updateDisengage(const long,const long) 
    bool *CurrentState = NULL;
    bool *TargetState = NULL;
    long i;
    
    // CurrentGear and NextGear are Gear IDs, not Gear Indices
    for (i = 0; i < nGears; i++)
      if (CurrentGear == Gears[i].ID)
      {
        CurrentState= Gears[i].ClutchState;    
        break;
      }
    
    for (i = 0; i < nGears; i++)
      if (TargetGear == Gears[i].ID)
      {
        TargetState= Gears[i].ClutchState;
        break;
      }
    
    _ASSERTE(CurrentState && TargetState);
    
    for (i = 0; i < nClutches; i++)
    {
      disengageList[i] = false;
    }
    
    for(i=0;i<nClutches;i++)
    {
      if ( CurrentState[i] && (TargetState[i] != CurrentState[i]) )
        disengageList[i] = true;
    }
    
    //#]
}

void Clutch_Schedule::updateEngage(const long  CurrentGear, const long  TargetGear) {
    NOTIFY_OPERATION(updateEngage, updateEngage(const long,const long), 0, TransmissionControlModels_Clutch_Schedule_updateEngage_SERIALIZE);
    //#[ operation updateEngage(const long,const long) 
    bool *CurrentState = NULL;
    bool *TargetState = NULL;
    long i;
    
    // CurrentGear and NextGear are Gear IDs, not Gear Indices
    for (i = 0; i < nGears; i++)
      if (CurrentGear == Gears[i].ID)
      {
        CurrentState= Gears[i].ClutchState;    
        break;
      }
    
    for (i = 0; i < nGears; i++)
      if (TargetGear == Gears[i].ID)
      {
        TargetState= Gears[i].ClutchState;
        break;
      }
    
    _ASSERTE(CurrentState && TargetState);
    
    for (i = 0; i < nClutches; i++)
    {
      engageList[i] = false;
    }
    
    for(i=0; i<nClutches; i++)
    {
      if( TargetState[i] && (TargetState[i] != CurrentState[i]) )
          engageList[i] = true; 
    }
    
    //#]
}

bool *  Clutch_Schedule::getDisengageList() const {
    return disengageList;
}

void Clutch_Schedule::setDisengageList(bool * p_disengageList) {
    disengageList = p_disengageList;
}

bool *  Clutch_Schedule::getEngageList() const {
    return engageList;
}

void Clutch_Schedule::setEngageList(bool * p_engageList) {
    engageList = p_engageList;
}

IOnEnv* Clutch_Schedule::getM_pOnEnv() const {
    return m_pOnEnv;
}

void Clutch_Schedule::setM_pOnEnv(IOnEnv*  p_m_pOnEnv) {
    m_pOnEnv = p_m_pOnEnv;
}

long Clutch_Schedule::getNClutches() const {
    return nClutches;
}

void Clutch_Schedule::setNClutches(long  p_nClutches) {
    nClutches = p_nClutches;
}

long Clutch_Schedule::getNGears() const {
    return nGears;
}

void Clutch_Schedule::setNGears(long  p_nGears) {
    nGears = p_nGears;
}

GearInfo* Clutch_Schedule::getGears() const {
    return Gears;
}

void Clutch_Schedule::setGears(GearInfo*  p_GearInfo) {
    Gears = p_GearInfo;
    if(p_GearInfo != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("Gears", p_GearInfo, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("Gears");
        }
}

void Clutch_Schedule::cleanUpRelations() {
    if(Gears != NULL)
        {
            NOTIFY_RELATION_CLEARED("Gears");
            Gears = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedClutch_Schedule::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedClutch_Schedule::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("Gears", FALSE, TRUE);
    if(myReal->Gears)
        aomsRelations->ADD_ITEM(myReal->Gears);
}

IMPLEMENT_META(Clutch_Schedule, TransmissionControlModels, FALSE, OMAnimatedClutch_Schedule)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Clutch_Schedule.cpp
*********************************************************************/

