//{{SCG_IMPLEMENTATION(ShiftLever.cpp) [0]

//{{SCG_INCLUDE    

// Cg_Add
#include "StdAfx.h" 
#include "ShiftDlg.h"
                   
#include "OnPlot_i.c"
                 
#include "ShiftLever.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

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

void ShiftLever::handle_tick(double *time)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

    
    if(!bInit) init();

    if(*time - lastUpdateTime > 0.1){  
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

void ShiftLever::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
//HRESULT hr = CoCreateInstance(CLSID_OnShiftLever, NULL, CLSCTX_INPROC_SERVER, IID__OnShiftLever, (void**) &pGUIObject);
m_cRef = 0;
positionPort = new Port_Int();
positionPort->AddRef();
m_dlg = new CShiftDlg();
m_dlg->Show();
bInit=false;

lastUpdateTime=0.0;
currentPosition=0;
bInit=true;
//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ShiftLever::clean()  
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
  {
    delete m_dlg;
    m_dlg = NULL;
  }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 ShiftLever::ShiftLever() : bInit(false)  
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

 ShiftLever::~ShiftLever()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
clean();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION


long ShiftLever::AddRef()
{
  return ++m_cRef;
}

long ShiftLever::Release()
{
  m_cRef--;
  if (m_cRef <= 0)
    delete this;

  return m_cRef;
}

void ShiftLever::SetName(LPCTSTR cszName)
{
  m_dlg->SetCaption(cszName);
}



void ShiftLever::get_Position(long* val)
{
  m_dlg->get_Position(val);
}

void ShiftLever::put_Position(long val)
{
  m_dlg->put_Position(val);
}



