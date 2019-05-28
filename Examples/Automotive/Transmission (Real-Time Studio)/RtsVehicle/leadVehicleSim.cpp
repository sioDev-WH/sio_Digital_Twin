//{{SCG_IMPLEMENTATION(Clutch_Schedule.cpp) [0]

//{{SCG_INCLUDE 

// Cg_Add
#include "StdAfx.h" 
#include "RtsOnTransmission.h"
#include "leadVehicleSim.h"

#include <fstream.h>                   

                    

leadVehicleSim::leadVehicleSim()
{
  m_pOnEnv = NULL;
  init();
}


leadVehicleSim::~leadVehicleSim()
{
  clean();
}


void leadVehicleSim::init()  
{

  long i;
  long mapSize;
  double *x;
  double *y;

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
    filename.Append(L"leadVehicleData.txt");

    ifstream speedMap(W2CA(filename.m_str),ios::in|ios::nocreate);

    speedMap >> mapSize;

    x = new double[mapSize];
    y = new double[mapSize];

    for(i=0;i<mapSize;i++)
    {
      speedMap >> x[i];
      speedMap >> y[i];
    }

    speedData.init_1D(mapSize, x, y); 

    speedMap.close();
    delete [] x;
    delete [] y;
  }

  _ASSERTE(SUCCEEDED(hr));
}                     

void leadVehicleSim::clean()  
{
  if (m_pOnEnv)
  {
    m_pOnEnv->Release();
    m_pOnEnv = NULL;
  }
}                     

double leadVehicleSim::get_Speed(const double t)
{
  double speed = 0.0;
  speedData.interpolate_1D(t, &speed);
  return speed;
}



