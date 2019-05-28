#ifndef __DEMO_ECMSD_H
#define __DEMO_ECMSD_H

// includes
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class CMass;
class CSpring;
class CDamper;
class Vehicle5;
class Actuator;
class Clutch;
class Engine;


class Demo_ECMSD : public COnUMLDaeEsoImpl<Demo_ECMSD>
{
public:
Demo_ECMSD();
virtual ~Demo_ECMSD();

public:
CMass* aMass;
CSpring* aSpring;
CDamper* Damper;
Vehicle5* Car;
Actuator* aFC;
Clutch* FC;
Engine* aEngine;

public:
void init();
void clean();
void Save( FILE* fs);
bool Load( FILE* fs);
HRESULT GetAssociations( long** Assoc,  long** Size,  long* nSize);
HRESULT InitEsos();

};

#endif
