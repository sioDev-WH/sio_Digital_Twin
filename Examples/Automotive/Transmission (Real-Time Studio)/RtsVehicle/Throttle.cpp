//{{SCG_IMPLEMENTATION(Throttle.cpp) [0]

//{{SCG_INCLUDE   

// Cg_Add
#include "StdAfx.h" 
#include "Throttle.h"
#include "ThrottleDlg.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

bool IsRtsRunning();

// Include for Template Class should go here.
//}}SCG_INCLUDE
                      
//{{SCG_CLASS_ID
//}}SCG_CLASS_ID

//{{SCG_ICLASS_INFO(0)


//}}SCG_ICLASS_INFO
//{{SCG_ATTS(0)
//}}SCG_ATTS

//{{SCG_ROLES(0)
//}}SCG_ROLES

//{{SCG_OPS(0)

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Throttle::handle_tick(double *time)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  if(!bInit) init();
  if(*time - lastUpdateTime > 0.001)
  {  
    m_dlg->getThrottle(&val);
    
    if(currentPosition != val)
    {
      currentPosition = val;
      lastUpdateTime = *time;
      positionPort->gen(&val);
    }
  }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Throttle::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
m_cRef = 0;
m_dlg = new CThrottleDlg();
m_dlg->Show();

positionPort = new Port_Double();
positionPort->AddRef();

lastUpdateTime=0.0;
currentPosition=0.0;
bInit=true;
//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Throttle::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
if (m_dlg)
{
  delete m_dlg;
  m_dlg = NULL;
}

if (positionPort)
{
  positionPort->Release();
  positionPort = NULL;
}

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Throttle::Throttle() : bInit(false)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

init();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Throttle::~Throttle()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
clean( );

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION


long Throttle::AddRef()
{
  return ++m_cRef;
}

long Throttle::Release()
{
  m_cRef--;
  if (m_cRef <= 0)
    delete this;

  return m_cRef;
}

void Throttle::SetName(const _TCHAR* caption)
{
  CComBSTR szCaption = caption;
  m_dlg->SetCaption(szCaption);
}


void Throttle::setPosition(const double t, double* val)
{
  m_dlg->setThrottle(*val);
  if (currentPosition != *val)
  {
    currentPosition = *val;
    lastUpdateTime = t;
    positionPort->gen(val);
  }
}
