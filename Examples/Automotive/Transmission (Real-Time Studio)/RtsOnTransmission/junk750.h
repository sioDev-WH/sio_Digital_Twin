#ifndef __JUNK750_H
#define __JUNK750_H

// includes
#include "BallV2.h"
#include "RtsSmInt.h"
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class Engine;
class Vehicle;
class CFrame;
class Actuator;
class Oneway_Clutch;
class Clutch;
class Ravigneaux;


class junk750 : public COnUMLDaeEsoImpl<junk750>
{
public:

public:
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
