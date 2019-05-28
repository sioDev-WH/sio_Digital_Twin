//{{SCG_IMPLEMENTATION(ShiftData.cpp) [0]

//{{SCG_INCLUDE    

// Cg_Add
#include "StdAfx.h" 
#include "RtsOnTransmission.h"
#include "ShiftData.h"
#include "Clutch_Schedule.h"
#include "LookupTable.h"

#include <fstream.h>                   

                 

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

// Include for Template Class should go here.
//}}SCG_INCLUDE
                      
//{{SCG_CLASS_ID
//}}SCG_CLASS_ID

//{{SCG_ICLASS_INFO(0)


//}}SCG_ICLASS_INFO
//{{SCG_ATTS(0)
//}}SCG_ATTS

//{{SCG_ROLES(0)
//}}SCG_ROLES

//{{SCG_OPS(0)

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   
ShiftData::ShiftData()
{
  m_pOnEnv = NULL;
}

ShiftData::~ShiftData()
{
  clean();
}

void ShiftData::init()  
//}}SCG_OP_INFO
{
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
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ShiftData::getUpShiftThreshold(const double throttle, const long gear, double *threshold)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
upShiftTable.interpolate_2D(throttle,(double)gear,threshold);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ShiftData::getDownShiftThreshold(const double throttle, const long gear, double *threshold)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
downShiftTable.interpolate_2D(throttle,(double)gear,threshold);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ShiftData::clean()  
//}}SCG_OP_INFO
{
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
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION









