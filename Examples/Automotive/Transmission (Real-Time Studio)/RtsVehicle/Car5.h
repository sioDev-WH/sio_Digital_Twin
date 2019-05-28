#ifndef __CAR5_H
#define __CAR5_H

#define include_torque_converter 1

// includes
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class CSpring;
class CDamper;
class Engine;
class Actuator;
class Clutch;
class CFrame;
class Band_Break;
class Oneway_Clutch;
class Vehicle5;
class Ravigneaux;
class Torque_Converter;

class Car5 : public COnUMLDaeEsoImpl<Car5>
{
public:
Car5();
virtual ~Car5();

public:
CSpring* Spring;
CDamper* Damper;
Engine* EngineWithSpeed;
Actuator* aRC;
Clutch* RC;
Actuator* aLRB;
CFrame* GLRB;
Band_Break* LRB;
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
Vehicle5* Car;
Ravigneaux* GearBox;
#if include_torque_converter
Torque_Converter* Converter;
#endif

public:
void init();
void clean();
void Save( FILE* fs);
bool Load( FILE* fs);
HRESULT GetAssociations( long** Assoc,  long** Size,  long* nSize);
HRESULT InitEsos();

void handle_throttle(const double t, double* val);
void handle_RCShift(const double t, long* val);
void handle_LRBShift(const double t, long* val);
void handle_TCCShift(const double t, long* val);
void handle_OBShift(const double t, long* val);
void handle_DCShift(const double t, long* val);
void handle_IOCShift(const double t, long* val);
void handle_POCShift(const double t, long* val);
void handle_FCShift(const double t, long* val);
void handle_brakeTorque(const double t, double* val);
void handle_Start(const double t, long *val);


};

#endif
