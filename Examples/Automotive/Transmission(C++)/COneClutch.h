#ifndef __CONECLUTCH_H
#define __CONECLUTCH_H


#include "OnUMLDaeEsoImpl.h"

class CRigidConnector;
class CFrame;
class CMass;
class Ravigneaux;
class Engine;
class Clutch;
class Actuator;

//{{SCG_HEADER(COneClutch.h) [0]

//{{SCG_INCLUDE                     
// Include for Template Class should go here.
//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class COneClutch 
                  :public COnUMLDaeEsoImpl<COneClutch>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
public:
  COneClutch();
  ~COneClutch();
    public:
        CFrame* Ground;     
        CMass* Mass;     
        Ravigneaux* Ravigneaux1;     
        Engine* Engine1;     
        Clutch* Clutch1;     
        Actuator* Actuator1;     
    protected:
        void init();             
        void clean();             
        HRESULT GetAssociations(long* *Assoc, long* *Size, long *nSize);             
        HRESULT InitEsos();             
    //}}SCG_CLASS_PROPS
};

//}}SCG_CLASS

//}}SCG_HEADER      
#endif










