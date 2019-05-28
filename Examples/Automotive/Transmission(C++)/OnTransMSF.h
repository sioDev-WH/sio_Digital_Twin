// OnTransMSF.h: interface for the COnTransMSF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OnTransMSF_H__A191735A_83A6_4620_9DB6_DD825AB8DCEF__INCLUDED_)
#define AFX_OnTransMSF_H__A191735A_83A6_4620_9DB6_DD825AB8DCEF__INCLUDED_

#include "OnUMLDaeEsoImpl.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFrame;
class CSignalActuator;
class CRigidConnector;
class CMass;
class CSpring;
class CDamper;
class CGearRatio;

class ActuatorClutchConnector;
class Actuator;
class Clutch;
class Oneway_Clutch;
class Engine;
class Torque_Converter;
class Ravigneaux;
class Vehicle;
class Band_Break;

class COnTransMSF : public COnUMLDaeEsoImpl<COnTransMSF>   
{
public:
	COnTransMSF();
	virtual ~COnTransMSF();

  virtual HRESULT GetAssociations(long** Assoc, long** Size, long* nSize);
  HRESULT InitEsos();


protected:
  CFrame* frame;
  Engine* engine;
  Torque_Converter* TC;
  Actuator* aTCC;
  Clutch* cTCC;

  Actuator* aIC;
  Clutch* cIC;
  CMass* ICMass;
  Actuator* aIOC;
  Oneway_Clutch* cIOC;
  Actuator* aRC;
  Clutch* cRC;
  Actuator* aOB;
  Band_Break* cOB;

  Actuator* aFC;
  Clutch* cFC;

  Actuator* aDC;
  Clutch* cDC;
  Actuator* aPOC;
  Oneway_Clutch* cPOC;
  Actuator* aLRB;
  Band_Break* cLRB;

  Ravigneaux* gearbox;
  Vehicle* vehicle;

};

#endif // !defined(AFX_OnTransMSF_H__A191735A_83A6_4620_9DB6_DD825AB8DCEF__INCLUDED_)
