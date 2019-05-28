/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: LookupTable
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\LookupTable.h
*********************************************************************/


#ifndef LookupTable_H 

#define LookupTable_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "StandardModels.h"

//## package StandardModels 

//----------------------------------------------------------------------------
// LookupTable.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedLookupTable;
#endif // _OMINSTRUMENT


//## class LookupTable 
class LookupTable  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedLookupTable;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation LookupTable() 
    LookupTable();
    
    //## operation ~LookupTable() 
    ~LookupTable();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation init_1D(const int ,const double * ,const double * ) 
    void init_1D(const int nRows, const double * x, const double * Table);
    
    //## operation init_2D(const int ,const int ,const double * ,const double * ,const double * * ) 
    void init_2D(const int nRows, const int nCols, const double * x, const double * y, const double * * Table);
    
    //## operation interpolate_1D(const double ,double * ) 
    void interpolate_1D(const double x, double * z);
    
    //## operation interpolate_2D(const double ,const double ,double * ) 
    void interpolate_2D(const double x, const double y, double * z);
    
    //## operation locate(const double ,const long ,const double * ,long * ) 
    void locate(const double x, const long nData, const double * Data, long * i);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double * *  getM_Table() const;
    
    //## auto_generated 
    void setM_Table(double * * p_m_Table);
    
    //## auto_generated 
    long getM_nCols() const;
    
    //## auto_generated 
    void setM_nCols(long  p_m_nCols);
    
    //## auto_generated 
    long getM_nRows() const;
    
    //## auto_generated 
    void setM_nRows(long  p_m_nRows);
    
    //## auto_generated 
    double *  getM_x() const;
    
    //## auto_generated 
    void setM_x(double * p_m_x);
    
    //## auto_generated 
    double *  getM_y() const;
    
    //## auto_generated 
    void setM_y(double * p_m_y);


////    Attributes    ////
private :
    
    double * * m_Table;		//## attribute m_Table 
    
    long m_nCols;		//## attribute m_nCols 
    
    long m_nRows;		//## attribute m_nRows 
    
    double * m_x;		//## attribute m_x 
    
    double * m_y;		//## attribute m_y 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedLookupTable : virtual public AOMInstance {

    
    DECLARE_META(LookupTable, OMAnimatedLookupTable)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\LookupTable.h
*********************************************************************/

