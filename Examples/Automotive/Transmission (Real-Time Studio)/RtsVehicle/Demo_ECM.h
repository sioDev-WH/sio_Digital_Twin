#ifndef __DEMO_ECM_H
#define __DEMO_ECM_H

// includes
#include "OnUMLDaeEsoImpl.h"

// forward declarations
class Actuator;
class Clutch;
class Engine;
class CMass;


class Demo_ECM : public COnUMLDaeEsoImpl<Demo_ECM>
{
public:
Demo_ECM();
virtual ~Demo_ECM();

public:
Actuator* aFC;
Clutch* FC;
Engine* aEngine;
CMass* aMass;

public:
void init();
void clean();
void Save( FILE* fs);
bool Load( FILE* fs);
HRESULT GetAssociations( long** Assoc,  long** Size,  long* nSize);
HRESULT InitEsos();

};

#endif
