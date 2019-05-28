//{{SCG_IMPLEMENTATION(Brakes.cpp) [0]

//{{SCG_INCLUDE  

// Cg_Add
#include "StdAfx.h" 
#include "OnPlot_i.c"
                   
#include "Brakes.h"
#include "BrakeDlg.h"
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

void Brakes::handle_tick(double *time)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    double val;
    if(!bInit) init();
    if(*time - lastUpdateTime >= 0.1){
      
      if (IsRtsRunning())
        val = 0.0;
      else
        m_dlg->get_Position(&val);

      if(currentPosition != val){
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

void Brakes::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
//HRESULT hr = CoCreateInstance(CLSID_OnBrakes, NULL, CLSCTX_INPROC_SERVER, IID__OnBrakes, (void**) &pGUIObject);
m_cRef = 0;
positionPort = new Port_Double();
positionPort->AddRef();
m_dlg = new CBrakeDlg();
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

void Brakes::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
if (positionPort)
{
  positionPort->Release();
  positionPort = NULL;
}
  
if (m_dlg)
  delete m_dlg;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP

Brakes::Brakes() : bInit(false)
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
init();
//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP

Brakes::~Brakes()
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



long Brakes::AddRef()
{
  return ++m_cRef;
}

long Brakes::Release()
{
  m_cRef--;
  if (m_cRef <= 0)
    delete this;

  return m_cRef;
}


void Brakes::SetName(const _TCHAR* caption)
{
  m_dlg->SetCaption(caption);
}



void Brakes::setPosition(const double t, double* val)
{
  m_dlg->put_Position(*val);
  if (currentPosition != *val)
  {
      currentPosition = *val;
      lastUpdateTime = t;
      positionPort->gen(val);
  }
}
