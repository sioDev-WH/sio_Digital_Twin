//{{SCG_IMPLEMENTATION(Chart.cpp) [0]

//{{SCG_INCLUDE   

// Cg_Add
#include "StdAfx.h" 
#include "RtsOnTransmission.h"
#include "Chart.h"
#include "ChartDlg.h"

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

void Chart::handle_tick(double *time)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Chart::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

m_cRef = 0;
m_dlg = new CChartDlg();
m_dlg->Show();
bInit=false;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Chart::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  delete m_dlg;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Chart::SetName(const _TCHAR* caption)
{
  CComBSTR szCaption = caption;
  m_dlg->SetCaption(szCaption);
}

void Chart::handle_plotData(const double * time, const double *vals, const long cVals)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
bool ppoint = false;

if(!bInit)
{
  m_dlg->initPlot(cVals, ppoint, NULL);
  bInit = true;
}
  
m_dlg->plotData(*time, vals, cVals);


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Chart::Chart()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
bInit= false;
init();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Chart::~Chart()  
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


long Chart::AddRef()
{
  return ++m_cRef;
}

long Chart::Release()
{
  m_cRef--;
  if (m_cRef <= 0)
    delete this;

  return m_cRef;
}





