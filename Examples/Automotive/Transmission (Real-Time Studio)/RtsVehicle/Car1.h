#ifndef __CAR_H
#define __CAR_H

// includes
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class Engine;
class Actuator;
class Clutch;
class CFrame;
class Band_Break;
class Torque_Converter;
class Oneway_Clutch;
//class Vehicle;
class Vehicle2;
class Ravigneaux;
class CDamper;
class CSpring;

class Car1 : public COnUMLDaeEsoImpl<Car1>
{
public:
Car1();
virtual ~Car1();

public:
Engine* EngineWithSpeed;
Actuator* aRC;
Clutch* RC;
Actuator* aLRB;
CFrame* GLRB;
Band_Break* LRB;
Actuator* aTCC;
Clutch* TCC;
Torque_Converter* Converter;
CFrame* GOB;
Actuator* aOB;
Band_Break* OB;
Actuator* aDC;
Clutch* DC;
Actuator* aIOC;
Oneway_Clutch* IOC;
CFrame* GPOC;
Actuator* aPOC;
Oneway_Clutch* POC;
Actuator* aFC;
Clutch* FC;
CFrame* GIOC;
//Vehicle* myCar;
Vehicle2* myCar;
Ravigneaux* GearBox;

CSpring* shaft_spring;
CDamper* shaft_damper;

double velocity;     

public:
void init();
void clean();

void Save(FILE* fs);
bool Load(FILE* fs);

HRESULT GetAssociations( long** Assoc,  long** Size,  long* nSize);
HRESULT InitEsos();

// engine start / stop
void handle_Start(const double t, long *val);

// throttle and brake
void handle_throttle(const double t, double* val);             
void handle_brakeTorque(const double t, double* val);

// shift control for 8 clutches
void handle_RCShift(const double t, long* val);             
void handle_LRBShift(const double t, long* val);             
void handle_TCCShift(const double t, long* val);             
void handle_OBShift(const double t, long* val);             
void handle_DCShift(const double t, long* val);             
void handle_IOCShift(const double t, long* val);             
void handle_POCShift(const double t, long* val);             
void handle_FCShift(const double t, long* val);             


};

#endif
