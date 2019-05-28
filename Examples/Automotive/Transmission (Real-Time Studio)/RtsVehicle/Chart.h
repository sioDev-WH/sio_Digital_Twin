#ifndef __CHART_H
#define __CHART_H


// Cg_Add
class CChartDlg;


//{{SCG_HEADER(Chart.h) [0]

//{{SCG_INCLUDE                     

//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class Chart 
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    private:
        CChartDlg* m_dlg;     
    public:
        void handle_tick(double *time);             
        void init();             
        void clean();         
        void SetName(const _TCHAR* caption);
        void handle_plotData(const double* time, const double *vals, const long cVals);             
        Chart();             
        ~Chart(); 

        long AddRef();
        long Release();

        // Cg_Add
        bool bInit;
        long m_cRef;
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










