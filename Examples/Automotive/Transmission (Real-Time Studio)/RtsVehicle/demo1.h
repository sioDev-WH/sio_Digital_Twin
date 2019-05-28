#ifndef __DEMO1_H
#define __DEMO1_H

// includes
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class Engine;
class Vehicle;
class CFrame;
class Actuator;
class Oneway_Clutch;
class Clutch;
class Ravigneaux;


class demo1 : public COnUMLDaeEsoImpl<demo1>
{
public:
demo1();
virtual ~demo1();

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
