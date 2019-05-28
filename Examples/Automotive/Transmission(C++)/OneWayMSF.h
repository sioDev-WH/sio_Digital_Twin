// OneWayMSF.h: interface for the COneWayMSF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OneWayMSF_H__A191735A_83A6_4620_9DB6_DD825AB8DCEF__INCLUDED_)
#define AFX_OneWayMSF_H__A191735A_83A6_4620_9DB6_DD825AB8DCEF__INCLUDED_

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

class ActuatorClutchConnector;
class Actuator;
class Clutch;
class Oneway_Clutch;

class COneWayMSF : public COnUMLDaeEsoImpl<COneWayMSF>   
{
public:
	COneWayMSF();
	virtual ~COneWayMSF();

  virtual HRESULT GetAssociations(long** Assoc, long** Size, long* nSize);
  HRESULT InitEsos();


protected:
  CSignalActuator* A1;     
  CMass* J1;     
  Actuator* AC1;
  Oneway_Clutch* C1;
  //Clutch* C1;
  CMass* J2;

};

#endif // !defined(AFX_OneWayMSF_H__A191735A_83A6_4620_9DB6_DD825AB8DCEF__INCLUDED_)
