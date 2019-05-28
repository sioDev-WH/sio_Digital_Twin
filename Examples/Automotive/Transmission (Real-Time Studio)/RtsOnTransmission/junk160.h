#ifndef __JUNK160_H
#define __JUNK160_H

// includes
#include "BallV2.h"
#include "RtsSmInt.h"
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class CFrame;
class Oneway_Clutch;
class Actuator;
class Engine;
class Vehicle;
class Clutch;
class Ravigneaux;


class junk160 : public COnUMLDaeEsoImpl<junk160>
{
public:

public:
CFrame* IOCGround;
Oneway_Clutch* IOC;
Actuator* aIOC;
Engine* myEngine;
Vehicle* Car;
CFrame* POCGround;
Actuator* aPOC;
Oneway_Clutch* POC;
Actuator* aFC;
Clutch* FC;
Ravigneaux* GearBox;

public:
void init();
void clean();
void Save( FILE* fs);
bool Load( FILE* fs);
HRESULT GetAssociations( long** Assoc,  long** Size,  long* nSize);
HRESULT InitEsos();

};

#endif
