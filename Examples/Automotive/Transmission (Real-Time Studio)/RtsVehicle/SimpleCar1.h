#ifndef __SIMPLECAR1_H
#define __SIMPLECAR1_H

// includes
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class Engine;
class simpleGearbox;
class Vehicle;


class SimpleCar1 : public COnUMLDaeEsoImpl<SimpleCar1>
{
public:
SimpleCar1();
virtual ~SimpleCar1();

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
