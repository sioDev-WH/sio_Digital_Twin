/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Chart
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Chart.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "Chart.h"
#include "CChartDlg.h"
#include <stdafx.h>

//## package DisplayPkg 


//#[ ignore 
#define DisplayPkg_Chart_Chart_SERIALIZE OM_NO_OP


#define DisplayPkg_Chart_AddRef_SERIALIZE OM_NO_OP


#define DisplayPkg_Chart_Release_SERIALIZE OM_NO_OP


#define DisplayPkg_Chart_SetName_SERIALIZE aomsmethod->addAttribute("caption", x2String(caption));


#define DisplayPkg_Chart_clean_SERIALIZE OM_NO_OP


#define DisplayPkg_Chart_handle_plotData_SERIALIZE \
    aomsmethod->addAttribute("time", x2String(time)); \
    aomsmethod->addAttribute("vals", x2String(vals)); \
    aomsmethod->addAttribute("cVals", x2String(cVals));


#define DisplayPkg_Chart_handle_tick_SERIALIZE aomsmethod->addAttribute("time", x2String(time));


#define DisplayPkg_Chart_init_SERIALIZE OM_NO_OP


#define DisplayPkg_Chart_initPlot_SERIALIZE \
    aomsmethod->addAttribute("numberOfSeries", x2String(numberOfSeries)); \
    aomsmethod->addAttribute("bPoint", x2String(bPoint)); \
    aomsmethod->addAttribute("pNames", x2String(pNames));


#define DisplayPkg_Chart_setLegends_SERIALIZE \
    aomsmethod->addAttribute("nSeries", x2String(nSeries)); \
    aomsmethod->addAttribute("pLegends", x2String(pLegends));
//#]

//----------------------------------------------------------------------------
// Chart.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(DisplayPkg)
//## class Chart 



Chart::Chart() {
    NOTIFY_CONSTRUCTOR(Chart, Chart(), 0, DisplayPkg_Chart_Chart_SERIALIZE);
    m_dlg = NULL;
    //#[ operation Chart() 
    init();
    //#]
}

Chart::~Chart() {
    NOTIFY_DESTRUCTOR(~Chart, TRUE);
    //#[ operation ~Chart() 
    clean();
    
    //#]
    cleanUpRelations();
}

long Chart::AddRef() {
    NOTIFY_OPERATION(AddRef, AddRef(), 0, DisplayPkg_Chart_AddRef_SERIALIZE);
    //#[ operation AddRef() 
    return ++m_cRef;
    
    //#]
}

long Chart::Release() {
    NOTIFY_OPERATION(Release, Release(), 0, DisplayPkg_Chart_Release_SERIALIZE);
    //#[ operation Release() 
    m_cRef--;
    if (m_cRef <= 0)
      delete this;
    
    return m_cRef;
    
    //#]
}

void Chart::SetName(const _TCHAR * caption) {
    NOTIFY_OPERATION(SetName, SetName(const _TCHAR * ), 1, DisplayPkg_Chart_SetName_SERIALIZE);
    //#[ operation SetName(const _TCHAR * ) 
    CComBSTR szCaption = caption;
    m_dlg->SetCaption(szCaption);
    
    //#]
}

void Chart::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, DisplayPkg_Chart_clean_SERIALIZE);
    //#[ operation clean() 
    if (m_dlg)
    {
      delete m_dlg;
      m_dlg = NULL;
    }  
    
    //#]
}

void Chart::handle_plotData(const double time, double * vals, long  cVals) {
    NOTIFY_OPERATION(handle_plotData, handle_plotData(const double ,double * ,long), 3, DisplayPkg_Chart_handle_plotData_SERIALIZE);
    //#[ operation handle_plotData(const double ,double * ,long) 
    /*
    bool ppoint = false;
    
    if(!bInit)
    {
      m_dlg->initPlot(cVals, ppoint, NULL);
      bInit = true;
    } */
      
    m_dlg->plotData(time, vals, cVals);
    
    //#]
}

void Chart::handle_tick(const double time) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double ), 1, DisplayPkg_Chart_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double ) 
    receive();
    
    //#]
}

void Chart::init() {
    NOTIFY_OPERATION(init, init(), 0, DisplayPkg_Chart_init_SERIALIZE);
    //#[ operation init() 
    m_dlg = new CChartDlg();
    m_dlg->Show();
    bInit=false;
    
    //#]
}

void Chart::initPlot(const long numberOfSeries, const bool bPoint, BSTR * pNames) {
    NOTIFY_OPERATION(initPlot, initPlot(const long ,const bool ,BSTR * ), 3, DisplayPkg_Chart_initPlot_SERIALIZE);
    //#[ operation initPlot(const long ,const bool ,BSTR * ) 
    bool ppoint = false;
    
    if(!bInit)
    {
      m_dlg->initPlot(numberOfSeries, ppoint, pNames);
      bInit = true;
    }
    
    //#]
}

void Chart::setLegends(const long  nSeries, BSTR *  pLegends) {
    NOTIFY_OPERATION(setLegends, setLegends(const long ,BSTR * ), 2, DisplayPkg_Chart_setLegends_SERIALIZE);
    //#[ operation setLegends(const long ,BSTR * ) 
    
    // LegendString(LegendIndex: Integer; LegendTextStyle: ELegendTextStyle): WideString;
    
    m_dlg->SetLegends(nSeries,pLegends);
    
    //#]
}

bool  Chart::getBInit() const {
    return bInit;
}

void Chart::setBInit(bool p_bInit) {
    bInit = p_bInit;
}

long Chart::getM_cRef() const {
    return m_cRef;
}

void Chart::setM_cRef(long  p_m_cRef) {
    m_cRef = p_m_cRef;
}

BSTR * Chart::getPLegands() const {
    return pLegands;
}

void Chart::setPLegands(BSTR *  p_pLegands) {
    pLegands = p_pLegands;
}

CChartDlg* Chart::getM_dlg() const {
    return m_dlg;
}

void Chart::setM_dlg(CChartDlg*  p_CChartDlg) {
    m_dlg = p_CChartDlg;
    if(p_CChartDlg != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("m_dlg", p_CChartDlg, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("m_dlg");
        }
}

void Chart::cleanUpRelations() {
    if(m_dlg != NULL)
        {
            NOTIFY_RELATION_CLEARED("m_dlg");
            m_dlg = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedChart::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("bInit", x2String(myReal->bInit));
    aomsAttributes->addAttribute("m_cRef", x2String(myReal->m_cRef));
    aomsAttributes->addAttribute("pLegands", x2String(myReal->pLegands));
}

void OMAnimatedChart::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("m_dlg", FALSE, TRUE);
    if(myReal->m_dlg)
        aomsRelations->ADD_ITEM(myReal->m_dlg);
}

IMPLEMENT_META(Chart, DisplayPkg, FALSE, OMAnimatedChart)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Chart.cpp
*********************************************************************/

