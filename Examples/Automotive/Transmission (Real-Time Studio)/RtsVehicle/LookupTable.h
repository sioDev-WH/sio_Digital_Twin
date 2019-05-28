#ifndef __LOOKUPTABLE_H
#define __LOOKUPTABLE_H

//{{SCG_HEADER(LookupTable.h) [0]

//{{SCG_INCLUDE                     
#include "RtsOnTransmissionExport.h"

//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API LookupTable 
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    private:
        double** m_Table;     
        long m_nRows;     
        long m_nCols;     
        double* m_x;     
        double* m_y;     
    public:
      LookupTable();
      ~LookupTable();
        void init();             
        void clean();             
        void init_1D(const int nRows, const double* x, const double* Table);             
        void init_2D(const int nRows, const int nCols, const double* x, const double* y, const double** Table);             
        void interpolate_1D(const double x, double *z);             
        void interpolate_2D(const double x, const double y, double *z);             
        void locate(const double x, const long nData, const double* Data, long *i);             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










