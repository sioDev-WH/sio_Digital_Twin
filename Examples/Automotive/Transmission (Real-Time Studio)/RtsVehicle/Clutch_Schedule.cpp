//{{SCG_IMPLEMENTATION(Clutch_Schedule.cpp) [0]

//{{SCG_INCLUDE 

// Cg_Add
#include "StdAfx.h" 
#include "RtsOnTransmission.h"
#include "GearInfo.h"

#include <fstream.h>                   

                    
#include "Clutch_Schedule.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

// Include for Template Class should go here.
//}}SCG_INCLUDE
                      
//{{SCG_CLASS_ID
//}}SCG_CLASS_ID

//{{SCG_ICLASS_INFO(0)

Clutch_Schedule::Clutch_Schedule()
{
  m_pOnEnv = NULL;
}

//}}SCG_ICLASS_INFO
//{{SCG_ATTS(0)
//}}SCG_ATTS

//{{SCG_ROLES(0)
//}}SCG_ROLES

//{{SCG_OPS(0)

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Clutch_Schedule::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


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

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Clutch_Schedule::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
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

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Clutch_Schedule::update(const long CurrentGear, const long NextGear)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

#if 1
  ATLTRACE("\nClutch_Schedule::update()");
#endif

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

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION









