#ifndef __SIMPLECAR_H
#define __SIMPLECAR_H

// includes
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class Engine;
class simpleGearbox;
class Vehicle;


class SimpleCar : public COnUMLDaeEsoImpl<SimpleCar>
{
public:
SimpleCar();
virtual ~SimpleCar();

public:
Engine* Engine_WS;
simpleGearbox* Gearbox;
Vehicle* Car;

public:
void init();
void clean();
void Save( FILE* fs);
bool Load( FILE* fs);
HRESULT GetAssociations( long** Assoc,  long** Size,  long* nSize);
HRESULT InitEsos();

};

#endif
