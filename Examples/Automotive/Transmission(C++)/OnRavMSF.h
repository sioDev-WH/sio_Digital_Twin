// OnRavMSF.h: interface for the COnRavMSF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OnRavMSF_H__A191735A_83A6_4620_9DB6_DD825AB8DCEF__INCLUDED_)
#define AFX_OnRavMSF_H__A191735A_83A6_4620_9DB6_DD825AB8DCEF__INCLUDED_

#include "OnUMLDaeEsoImpl.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSignalActuator;
class CRigidConnector;
class CMass;
class CSpring;
class CDamper;
class CGearRatio;
class CFrame;

class ActuatorClutchConnector;
class Actuator;
class Clutch;
class Oneway_Clutch;
class Ravigneaux;
class Engine;
class Torque_Converter;
class Band_Break;

class COnRavMSF : public COnUMLDaeEsoImpl<COnRavMSF>   
{
public:
	COnRavMSF();
	virtual ~COnRavMSF();

  virtual HRESULT GetAssociations(long** Assoc, long** Size, long* nSize);
  HRESULT InitEsos();

protected:
  CSignalActuator* A1; 
  CMass* J1;
  CFrame* F1;
  Actuator* aBreak;
  Band_Break* cBreak;
  //Clutch* cBreak;
  Ravigneaux* R1;
  CMass* J2;

};

#endif // !defined(AFX_OnRavMSF_H__A191735A_83A6_4620_9DB6_DD825AB8DCEF__INCLUDED_)
