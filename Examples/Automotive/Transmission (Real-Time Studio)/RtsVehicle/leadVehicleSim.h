#ifndef _LEAD_VEHICLE_SIM_H_
#define _LEAD_VEHICLE_SIM_H_

#include "LookupTable.h"

struct IOnEnv;

class leadVehicleSim
{
public:
  leadVehicleSim();
  ~leadVehicleSim();

  void init();
  void clean();
  double get_Speed(const double t);

  LookupTable speedData;
  IOnEnv* m_pOnEnv;

};


#endif _LEAD_VEHICLE_SIM_H_