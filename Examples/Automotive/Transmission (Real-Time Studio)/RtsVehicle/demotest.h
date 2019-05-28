#ifndef __DEMOTEST_H
#define __DEMOTEST_H

// includes
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class CFrame;
class Actuator;
class Oneway_Clutch;
class Engine;
class Vehicle;
class Clutch;
class Ravigneaux;


class demotest : public COnUMLDaeEsoImpl<demotest>
{
public:
demotest();
virtual ~demotest();

public:
CFrame* gIOC;
Actuator* aIOC;
Oneway_Clutch* IOC;
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
