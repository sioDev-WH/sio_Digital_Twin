#ifndef __CAR2_H
#define __CAR2_H

// includes
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class Engine;
class Actuator;
class Clutch;
class CFrame;
class Band_Break;
class Oneway_Clutch;
class Vehicle2;
class Ravigneaux;


class Car2 : public COnUMLDaeEsoImpl<Car2>
{
public:
Car2();
virtual ~Car2();

public:
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
Vehicle2* Car;
Ravigneaux* GearBox;

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
