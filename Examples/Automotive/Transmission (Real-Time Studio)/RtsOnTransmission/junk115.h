#ifndef __JUNK115_H
#define __JUNK115_H

// includes
#include "BallV2.h"
#include "RtsSmInt.h"
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class Engine;
class Actuator;
class Oneway_Clutch;
class CFrame;
class Clutch;
class Vehicle;
class Ravigneaux;


class junk115 : public COnUMLDaeEsoImpl<junk115>
{
public:

public:
Engine* EngineWithSpeed;
Actuator* aIOC;
Oneway_Clutch* IOC;
CFrame* GPOC;
Actuator* aPOC;
Oneway_Clutch* POC;
Actuator* aFC;
Clutch* FC;
CFrame* GIOC;
Vehicle* Car;
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
